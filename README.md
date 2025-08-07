<img width="732" height="1020" alt="image" src="https://github.com/user-attachments/assets/b316a146-6cbd-4c6d-92b2-8032e114e1af" /><img width="457" height="593" alt="image" src="https://github.com/user-attachments/assets/32bd995e-5c4d-46f9-be47-b0a289a77bc5" /># QQ_replica_project_based_on_Qt5_in_CLion

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

#### 截图展示

1. 登录功能截图：<img width="457" height="593" alt="image" src="https://github.com/user-attachments/assets/27c71930-26f0-49a5-93b2-c6f3a9e8b0e4" />
2. 注册功能截图：<img width="457" height="593" alt="image" src="https://github.com/user-attachments/assets/93403ed9-14e1-4f3b-88ce-9088b20104f5" />
3. 注销功能截图：<img width="457" height="593" alt="image" src="https://github.com/user-attachments/assets/09a594d7-ab94-48d4-bfe6-1180ffd7e041" />
4. 主浏览界面截图：<img width="482" height="759" alt="image" src="https://github.com/user-attachments/assets/a093e128-3064-4fb6-9591-25ee3017025d" />
5. 新建群聊界面截图（未完成，仅界面）：<img width="412" height="615" alt="image" src="https://github.com/user-attachments/assets/664e1225-61ba-4ef8-acd5-dfbf535ff04b" />
6. 添加好友截图：<img width="802" height="746" alt="image" src="https://github.com/user-attachments/assets/d07633d7-ab67-4c2e-b3fb-b866e036fc87" />
7. 删除好友截图：<img width="802" height="746" alt="image" src="https://github.com/user-attachments/assets/f45762b8-25d1-4a4d-8a1b-f674d885f5a7" />
8. 聊天界面截图（10号视角）：<img width="732" height="1020" alt="image" src="https://github.com/user-attachments/assets/d14114d7-542e-4078-a47c-8b36f52ac0d9" />
9. 聊天界面截图（9号视角）：<img width="732" height="1020" alt="image" src="https://github.com/user-attachments/assets/3727dbe4-ccb7-43cf-8c4c-d769fc25e8ba" />
10. 开发者功能（根据用户持有好友数目生成柱图）：<img width="802" height="639" alt="image" src="https://github.com/user-attachments/assets/feb9c859-6512-4bc5-9e84-ed258b276f9b" />
11. 开发者功能（根据用户持有好友数目生成饼图图）：<img width="802" height="639" alt="image" src="https://github.com/user-attachments/assets/812d70ed-e9e8-4222-badc-84d5d59952ec" />











