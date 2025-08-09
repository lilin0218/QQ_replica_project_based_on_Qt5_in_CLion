#ifndef POOLMANAGER_H
#define POOLMANAGER_H

#include <QRunnable>       // 提供QRunnable基类，用于线程任务
#include <QThreadPool>     // 提供线程池管理功能
#include <QVariant>        // 提供通用数据类型容器
#include <QCoreApplication>// 提供qApp全局指针，用于主线程调用
#include <functional>      // 提供std::function函数对象支持
#include <exception>       // 提供标准异常处理支持
#include <stdexcept>       // 提供标准运行时异常支持

class PoolManager
{
public:
    // 删除默认构造函数，禁止类实例化
    PoolManager() = delete;
    // 定义任务函数类型：无参数，返回QVariant
    using TaskFunction = std::function<QVariant()>;
    // 定义回调函数类型：接受QVariant参数，无返回值
    using CallbackFunction = std::function<void(QVariant)>;
    // 定义错误处理函数类型：接受标准异常引用
    using ErrorHandler = std::function<void(const std::exception&)>;

    static void submit(
        TaskFunction work,
        CallbackFunction callback = nullptr,
        QThreadPool* pool = QThreadPool::globalInstance(),
        ErrorHandler errorHandler = nullptr
    ) {
        // 定义任务运行器内部类（继承自QRunnable）
        class TaskRunner : public QRunnable {
        public:

            TaskRunner(TaskFunction task, CallbackFunction cb, ErrorHandler eh)
                : m_task(std::move(task)),      // 移动任务函数到成员变量
                  m_callback(std::move(cb)),    // 移动回调函数到成员变量
                  m_errorHandler(std::move(eh)) // 移动错误处理到成员变量
            {
                // 设置任务完成后自动删除对象
                setAutoDelete(true);
            }

            /**
             * @brief 重写run方法，实际执行任务
             */
            void run() override {
                try {
                    // 执行任务函数并获取结果
                    QVariant result = m_task();
                    // 如果提供了回调函数
                    if (m_callback) {
                        // 在主线程安排回调执行
                        QMetaObject::invokeMethod(
                            qApp, // 使用全局QCoreApplication实例
                            [res = std::move(result), cb = m_callback]() {
                                // 在主线程执行回调，传递任务结果
                                cb(res);
                            },
                            Qt::QueuedConnection // 使用队列连接确保在主线程执行
                        );
                    }
                }
                // 捕获标准异常
                catch (const std::exception& e) {
                    // 如果提供了错误处理函数
                    if (m_errorHandler) {
                        // 在主线程安排错误处理
                        QMetaObject::invokeMethod(
                            qApp,
                            [eh = m_errorHandler, e]() {
                                // 调用错误处理函数，传递异常
                                eh(e);
                            },
                            Qt::QueuedConnection
                        );
                    }
                }
                // 捕获所有其他异常
                catch (...) {
                    // 如果提供了错误处理函数
                    if (m_errorHandler) {
                        // 在主线程安排错误处理
                        QMetaObject::invokeMethod(
                            qApp,
                            [eh = m_errorHandler]() {
                                // 创建并传递运行时异常
                                eh(std::runtime_error("Unknown exception"));
                            },
                            Qt::QueuedConnection
                        );
                    }
                }
            }
        private:
            TaskFunction m_task;         // 存储任务函数
            CallbackFunction m_callback; // 存储回调函数
            ErrorHandler m_errorHandler; // 存储错误处理函数
        };
        // 创建任务运行器实例
        auto* runner = new TaskRunner(
            std::move(work),       // 移动任务函数
            std::move(callback),    // 移动回调函数
            std::move(errorHandler) // 移动错误处理
        );
        // 将任务提交到指定线程池
        pool->start(runner);
    }
};

#endif // POOLMANAGER_H