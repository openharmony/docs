# 开放权限（系统授权）

此列表内所有权限均为系统授权（system_grant）的开放权限，面向所有应用开放。

应用申请了system_grant权限后，系统将在用户安装应用时，自动把相应权限授予给应用。

<!--Del-->
> **说明：**
> 权限级别为normal的权限，不涉及ACL使能字段。
<!--DelEnd-->

## 申请方式

以下权限的授权方式均为[system_grant](app-permission-mgmt-overview.md#system_grant系统授权)，申请方式请参考[声明权限](declare-permissions.md)。

## ohos.permission.USE_BLUETOOTH

允许应用查看蓝牙的配置。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：8

## ohos.permission.GET_BUNDLE_INFO

允许查询应用的基本信息。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：7

## ohos.permission.PREPARE_APP_TERMINATE

允许应用关闭前执行自定义的预关闭动作。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：10

## ohos.permission.PRINT

允许应用获取打印框架的能力。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：10

## ohos.permission.DISCOVER_BLUETOOTH

允许应用配置本地蓝牙，查找远端设备且与之配对连接。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：8

## ohos.permission.ACCELEROMETER

允许应用读取加速度传感器的数据。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：7

## ohos.permission.ACCESS_BIOMETRIC

允许应用使用生物特征识别能力进行身份认证。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：6

## ohos.permission.ACCESS_NOTIFICATION_POLICY

在本设备上允许应用访问通知策略。

仅当控制铃声从静音到非静音时，需要申请该权限。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：7

## ohos.permission.GET_NETWORK_INFO

允许应用获取数据网络信息。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：8

## ohos.permission.GET_WIFI_INFO

允许应用获取Wi-Fi信息。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：8

## ohos.permission.GYROSCOPE

允许应用读取陀螺仪传感器的数据。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：7

## ohos.permission.INTERNET

允许使用Internet网络。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：9

## ohos.permission.KEEP_BACKGROUND_RUNNING

允许Service Ability在后台持续运行。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：8

## ohos.permission.NFC_CARD_EMULATION

允许应用实现卡模拟功能。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：8

## ohos.permission.NFC_TAG

允许应用读写Tag卡片。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：7

## ohos.permission.PRIVACY_WINDOW

允许应用将窗口设置为隐私窗口，禁止截屏录屏。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：9

**变更信息：** API 9-10，权限级别为system_basic；从API 11开始，变更为normal。

## ohos.permission.PUBLISH_AGENT_REMINDER

允许该应用使用后台代理提醒。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：7

## ohos.permission.SET_WIFI_INFO

允许应用配置Wi-Fi设备。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：8

## ohos.permission.VIBRATE

允许应用控制马达振动。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：7

## ohos.permission.CLEAN_BACKGROUND_PROCESSES

允许应用根据包名清理相关后台进程。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：7

## ohos.permission.COMMONEVENT_STICKY

允许应用发布粘性公共事件。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：7

## ohos.permission.MODIFY_AUDIO_SETTINGS

允许应用修改音频设置。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：8

## ohos.permission.RUNNING_LOCK

允许应用获取运行锁，保证应用在后台的持续运行。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：7

## ohos.permission.SET_WALLPAPER

允许应用设置壁纸。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：7

## ohos.permission.ACCESS_CERT_MANAGER

允许应用进行查询证书及私有凭据等操作。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：9

## ohos.permission.hsdr.HSDR_ACCESS

允许应用访问安全检测与响应框架。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：10

## ohos.permission.RUN_DYN_CODE

允许系统方舟运行时引擎在受限模式下执行动态下发的方舟字节码。

该权限相关的API均为系统API，仅部分特定系统应用可申请该权限。 

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：11

## ohos.permission.READ_CLOUD_SYNC_CONFIG

允许接入云空间的应用查询应用云同步相关配置信息。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：11

## ohos.permission.STORE_PERSISTENT_DATA

允许应用存储持久化的数据，该数据直到设备恢复出厂设置或重装系统才会被清除。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：11

## ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

允许应用使用外接设备增强功能。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：11

## ohos.permission.READ_ACCOUNT_LOGIN_STATE

允许应用读取用户账号的登录状态。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：12

## ohos.permission.ACCESS_SERVICE_NAVIGATION_INFO

允许应用访问导航信息服务。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：12

## ohos.permission.PROTECT_SCREEN_LOCK_DATA

允许应用在锁屏后保护本应用敏感数据不被访问。

应用获取此权限后，系统将给用户新建一个高安全级别el5的目录。应用可以在此目录下存放数据，这部分数据在锁屏后无法被访问。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：12

## ohos.permission.FILE_ACCESS_PERSIST

允许应用支持持久化访问文件Uri。

<!--RP2--><!--RP2End-->

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：11

**变更信息：** API 11，权限级别为system_basic；从API 12开始，变更为normal。

## ohos.permission.ACCESS_CAR_DISTRIBUTED_ENGINE

允许应用访问出行分布式业务引擎。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：12

## ohos.permission.WINDOW_TOPMOST

允许应用将窗口设置为应用置顶窗口。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：13

## ohos.permission.USE_FRAUD_MESSAGES_PICKER

允许应用使用诈骗短信选择器，获取短信内容。

**权限级别**：system_basic

**授权方式**：system_grant

**起始版本**：16

## ohos.permission.USE_FRAUD_CALL_LOG_PICKER

允许应用使用诈骗通话记录选择器，获取通话记录内容。

**权限级别**：system_basic

**授权方式**：system_grant

**起始版本**：16

## ohos.permission.kernel.ALLOW_EXECUTABLE_FORT_MEMORY

允许系统JS引擎申请带MAP_FORT标识的匿名可执行内存。

应用申请此权限后，系统引擎可申请带MAP_FORT的匿名可执行内存，做即时编译，提高与形式执行效率。

**权限级别**：system_basic

**授权方式**：system_grant

**起始版本**：14

<!--Del-->
## ohos.permission.PRELOAD_FILE

允许应用预加载文件以提升文件打开速度。

仅当应用为文档编辑类应用可申请此权限。

**权限级别**：system_basic

**授权方式**：system_grant

**起始版本**：15
<!--DelEnd-->

## ohos.permission.MANAGE_INPUT_INFRARED_EMITTER

允许应用使用红外接口。

查询红外支持最大频率，发送特定频率红外信号。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：12

**变更信息**：在API 12-15，该权限仅向系统应用开放；从API16开始，开放范围变更为普通应用。

## ohos.permission.INPUT_KEYBOARD_CONTROLLER

允许应用设置键盘功能键状态。

如CapsLock(大小写) 的亮灭状态等。当前仅输入法应用可以申请该权限。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：15

## ohos.permission.SET_ABILITY_INSTANCE_INFO

允许应用单独配置每个Ability的图标和标签信息。

设置后的图标与标签信息可在任务中心和快捷栏的界面中显示。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：15

## ohos.permission.NDK_START_SELF_UI_ABILITY

允许应用通过C API启动同应用的UIAbility。

当前仅2in1设备应用可申请此权限。

**权限级别**：normal

**授权方式**：system_grant

**起始版本**：15

### ohos.permission.PERSONAL_MANAGE_RESTRICTIONS

允许设备管理应用管理个人设备限制策略。

**权限级别**：system_basic

**授权方式**：system_grant

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：15

### ohos.permission.START_PROVISIONING_MESSAGE

允许应用启动设备管理业务部署流程，将该应用激活为个人设备管理应用。

**权限级别**：system_basic

**授权方式**：system_grant

<!--Del-->
**ACL使能**：true<!--DelEnd-->

**起始版本**：15
