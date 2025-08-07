#include "dynamicgradientbg.h"
#include <QPainter>
#include <QPaintEvent>
#include <QLinearGradient>
#include <QEvent>

// 用于监听目标 widget 的 resize 事件，确保覆盖层同步大小
class ResizeEventFilter : public QObject
{
public:
    ResizeEventFilter(QWidget* target, DynamicGradientBG* overlay)
        : m_target(target), m_overlay(overlay) {}

protected:
    bool eventFilter(QObject *obj, QEvent *event) override {
        if (obj == m_target && event->type() == QEvent::Resize) {
            m_overlay->resize(m_target->size());  // 同步大小
        }
        return QObject::eventFilter(obj, event);
    }

private:
    QWidget* m_target;
    DynamicGradientBG* m_overlay;
};

DynamicGradientBG::DynamicGradientBG(QWidget *parent)
    : QWidget(parent), m_currentIndex(0), m_progress(0.0f)
{
    // 设置为不阻塞鼠标事件，不绘制背景，不自动填充背景
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_NoSystemBackground);
    setAutoFillBackground(false);
    raise();  // 显示在最上层但不遮挡内容

    // 每16ms刷新一次，实现动画流畅（约60帧）
    m_updateTimer.setInterval(16);
    connect(&m_updateTimer, &QTimer::timeout, this, [=]() {
        m_progress += 0.02f;               // 渐变进度步进
        if (m_progress > 1.0f) m_progress = 1.0f;
        update();                          // 触发重绘
    });

    // 每隔设定时间切换下一组颜色
    connect(&m_switchTimer, &QTimer::timeout, this, [=]() {
        m_currentIndex = (m_currentIndex + 1) % m_gradientPairs.size();
        m_progress = 0.0f;                 // 重新开始渐变
    });
}

void DynamicGradientBG::addGradientPair(const QColor &start, const QColor &end)
{
    // 添加一个颜色渐变对（开始色和结束色）
    m_gradientPairs.append(qMakePair(start, end));
}

void DynamicGradientBG::startAnimation(int interval)
{
    if (m_gradientPairs.size() < 2) return;  // 至少需要两组才能循环

    resize(parentWidget()->size());  // 设置为与父窗口等大
    show();                          // 显示自己

    m_switchTimer.start(interval);   // 设置颜色切换间隔（单位：毫秒）
    m_updateTimer.start();           // 启动刷新动画
}

void DynamicGradientBG::installDynamicGradientBG(QWidget *target) {
    if (!target) return;

    auto *overlay = new DynamicGradientBG(target);

    // 添加七种彩虹色渐变对（前后连接构成循环）
    QList<QColor> rainbowColors = {
        QColor(255, 0, 0, 50),     // 红（浅）
        QColor(255, 165, 0, 50),   // 橙（浅）
        QColor(255, 255, 0, 50),   // 黄（浅）
        QColor(0, 255, 0, 50),     // 绿（浅）
        QColor(0, 255, 255, 50),   // 青（浅）
        QColor(0, 0, 255, 50),     // 蓝（浅）
        QColor(128, 0, 255, 50)    // 紫（浅）
    };


    for (int i = 0; i < rainbowColors.size(); ++i) {
        QColor start = rainbowColors[i];
        QColor end   = rainbowColors[(i + 1) % rainbowColors.size()];
        overlay->addGradientPair(start, end);  // 添加连续过渡对
    }

    overlay->startAnimation(5000);  // 切换间隔时间（5秒）

    // 安装监听器以同步大小
    target->installEventFilter(new ResizeEventFilter(target, overlay));
}

// 插值函数：根据 t(0~1) 计算 a 和 b 之间的中间色
QColor DynamicGradientBG::interpolate(const QColor &a, const QColor &b, float t)
{
    return QColor(
        a.red()   + (b.red()   - a.red())   * t,
        a.green() + (b.green() - a.green()) * t,
        a.blue()  + (b.blue()  - a.blue())  * t,
        a.alpha() + (b.alpha() - a.alpha()) * t
        );
}

void DynamicGradientBG::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    if (m_gradientPairs.size() < 2) return;

    int nextIndex = (m_currentIndex + 1) % m_gradientPairs.size();

    // 计算当前渐变的中间色
    QColor startColor = interpolate(m_gradientPairs[m_currentIndex].first,
                                    m_gradientPairs[nextIndex].first,
                                    m_progress);
    QColor endColor = interpolate(m_gradientPairs[m_currentIndex].second,
                                  m_gradientPairs[nextIndex].second,
                                  m_progress);

    // 绘制线性渐变背景
    QPainter painter(this);
    QLinearGradient gradient(rect().topLeft(), rect().bottomRight());
    gradient.setColorAt(0, startColor);
    gradient.setColorAt(1, endColor);
    painter.fillRect(rect(), gradient);  // 填充整个区域
}
