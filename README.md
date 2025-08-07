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

1. 安装 Qt 5.15.2（建议使用官方 Qt Online Installer）
2. 配置 CLion + MinGW 8.1.0 环境，确保支持 Qt CMake 构建
3. 克隆本仓库：
   git clone https://gitee.com/lilin0218/qq_replica_project_based_on_-qt5_in_-clion.git
4. 使用 CLion 打开项目根目录，自动加载 CMakeLists.txt
5. 构建并运行项目（初次运行建议清空缓存并重新 CMake reload）

#### 使用说明

1.  启动程序后进入登录页，可创建新用户或用已有 ID 登录
2.  登录成功后进入主界面，可选择联系人发起聊天
3.  聊天窗口支持发送文本、图片、窗口抖动与文件
4.  点击“添加好友”输入 ID 即可添加新联系人
5.  每位用户本地独立启动服务器（支持多用户同时在线）
6.  所有聊天数据与好友关系持久化存储于 SQLite 数据库中
7. 开发者页面支持数据可视化： 输出当前用户的好友数量柱状图 & 输出当前用户的好友数量饼状图

#### 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request


#### 特技

1.  使用 Readme\_XXX.md 来支持不同的语言，例如 Readme\_en.md, Readme\_zh.md
2.  Gitee 官方博客 [blog.gitee.com](https://blog.gitee.com)
3.  你可以 [https://gitee.com/explore](https://gitee.com/explore) 这个地址来了解 Gitee 上的优秀开源项目
4.  [GVP](https://gitee.com/gvp) 全称是 Gitee 最有价值开源项目，是综合评定出的优秀开源项目
5.  Gitee 官方提供的使用手册 [https://gitee.com/help](https://gitee.com/help)
6.  Gitee 封面人物是一档用来展示 Gitee 会员风采的栏目 [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/)
