# QQ_replica_project_based_on_Qt5_in_CLion

#### 介绍
这是一个使用 **Qt 5.15.2** 开发的 QQ 聊天软件复刻项目，支持文本、图片、
窗口抖动、文件四类消息，具备多用户系统、聊天记录存储、好友管理等功能。项目在
**CLion** 中使用 **CMake** 构建，采用 **MinGW 8.1.0 64-bit** 编译器
，使用 **SQLite 数据库** 进行用户信息与消息数据的本地持久化。代码管理通过 
**Git 仓库**完成同步与版本控制。

#### 软件架构
本项目采用模块化设计，主要模块如下：

- `LoginPage`：用户登录界面，支持 ID 登录
- `CreatePage`：新用户注册界面，自动分配 ID
- `MainPage`：主界面，展示好友列表、聊天入口
- `ChatPage`：聊天窗口，支持文字、图片、抖动、文件四类消息
- `AddPage`：添加好友界面，输入 ID 添加好友
- `DeveloperPage`：开发者界面，支持数据可视化展示
- `MyClient` / `MyServer`：TCP 客户端与服务端，负责点对点通信
- `Protocol`：自定义协议，基于 JSON 实现消息封装与解析
- `ChatManager` / `DatabaseManager`：聊天记录与数据库管理类
- `AppConfig`：统一配置类，定义路径、端口等常量
- `dynamicgradientbg`：自定义渐变背景控件



#### 安装教程

1. 在Qt的在线安装工具中选择安装 Qt 5.15.2，QCharts模块（可选）
2. 在CLion中选择Qt微件，选择Qt5打开该项目
3. 修改cmake当中内容：# Qt 安装路径  set(CMAKE_PREFIX_PATH "D:/APP/QT5/5.15.2/mingw81_64")
4. 如果不需要图标模块要删除对QCharts的引用（添加和删除模块在cmake当中这样操作）：
   find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Network Sql Charts)
   foreach(QT_LIB Core Gui Widgets Charts Network Sql)
5. Qt如果使用数据库报错（使用SQLite应该不会，MySQL需要额外下载dll），需要额外下载自己Qt版本对应的数据库dll
6. CLion中无法运行数据库（缺少dll库）：在终端中执行：& "D:\APP\QT5\5.15.2\mingw81_64\bin\windeployqt.exe" "cmake-build-debug\Heart.exe"
7. 当clion检测不到ui文件，但是却能运行时：在cmake中添加：include_directories(${CMAKE_CURRENT_BINARY_DIR})

#### 使用说明

1.  启动程序后进入登录页，可创建新用户或用已有 ID 登录
2.  登录成功后进入主界面，可选择联系人发起聊天
3.  聊天窗口支持发送文本、图片、窗口抖动与文件
4.  点击“添加好友”输入 ID 即可添加新联系人
5.  每位用户本地独立启动服务器（支持多用户同时在线）
6.  所有聊天数据与好友关系持久化存储于 SQLite 数据库中
7. 开发者页面支持数据可视化： 输出当前用户的好友数量柱状图 & 输出当前用户的好友数量饼状图

#### 参与贡献

略


#### 特技

略

