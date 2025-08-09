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

#### 截图展示

<h4>1. 登录 / 注册 / 注销：</h4>
<table>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/27c71930-26f0-49a5-93b2-c6f3a9e8b0e4" width="300"/></td>
    <td><img src="https://github.com/user-attachments/assets/93403ed9-14e1-4f3b-88ce-9088b20104f5" width="300"/></td>
    <td><img src="https://github.com/user-attachments/assets/09a594d7-ab94-48d4-bfe6-1180ffd7e041" width="300"/></td>
  </tr>
</table>

<h4>2. 主浏览界面：</h4>
<img src="https://github.com/user-attachments/assets/a093e128-3064-4fb6-9591-25ee3017025d" width="300"/>

<h4>3. 添加 / 删除好友：</h4>
<table>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/d07633d7-ab67-4c2e-b3fb-b866e036fc87" width="350"/></td>
    <td><img src="https://github.com/user-attachments/assets/f45762b8-25d1-4a4d-8a1b-f674d885f5a7" width="350"/></td>
  </tr>
</table>

<h4>4. 新建群聊（UI未完成）：</h4>
<img src="https://github.com/user-attachments/assets/664e1225-61ba-4ef8-acd5-dfbf535ff04b" width="300"/>

<h4>5. 聊天界面（10号 / 9号视角）：</h4>
<table>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/d14114d7-542e-4078-a47c-8b36f52ac0d9" width="350"/></td>
    <td><img src="https://github.com/user-attachments/assets/3727dbe4-ccb7-43cf-8c4c-d769fc25e8ba" width="350"/></td>
  </tr>
</table>

<h4>6. 开发者功能图表（柱图 / 饼图）：</h4>
<table>
  <tr>
    <td><img src="https://github.com/user-attachments/assets/feb9c859-6512-4bc5-9e84-ed258b276f9b" width="350"/></td>
    <td><img src="https://github.com/user-attachments/assets/812d70ed-e9e8-4222-badc-84d5d59952ec" width="350"/></td>
  </tr>
</table>
