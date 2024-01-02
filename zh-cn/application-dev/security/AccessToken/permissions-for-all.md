# 对所有应用开放


在申请目标权限前，建议开发者先阅读[申请应用权限](determine-application-mode.md)，对权限的工作流程有基本了解后，再结合以下权限字段的具体说明，判断应用能否申请目标权限，提高开发效率。


## system_grant（系统授权）权限列表

以下权限的授权方式均为[system_grant](app-permission-mgmt-overview.md#system_grant系统授权)，申请方式请参考[声明权限](declare-permissions.md)。


### ohos.permission.USE_BLUETOOTH

允许应用查看蓝牙的配置。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：8

### ohos.permission.GET_BUNDLE_INFO

允许查询应用的基本信息。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：7


### ohos.permission.PREPARE_APP_TERMINATE

允许应用关闭前执行自定义的预关闭动作。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：10


### ohos.permission.PRINT

允许应用获取打印框架的能力。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：10


### ohos.permission.DISCOVER_BLUETOOTH

允许应用配置本地蓝牙，查找远端设备且与之配对连接。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：8


### ohos.permission.ACCELEROMETER

允许应用读取加速度传感器的数据。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：7


### ohos.permission.ACCESS_BIOMETRIC

允许应用使用生物特征识别能力进行身份认证。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：6


### ohos.permission.ACCESS_NOTIFICATION_POLICY

在本设备上允许应用访问通知策略。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：false

**起始版本**：7


### ohos.permission.GET_NETWORK_INFO

允许应用获取数据网络信息。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：8


### ohos.permission.GET_WIFI_INFO

允许应用获取Wi-Fi信息。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：8


### ohos.permission.GYROSCOPE

允许应用读取陀螺仪传感器的数据。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：7


### ohos.permission.INTERNET

允许使用Internet网络。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：9


### ohos.permission.KEEP_BACKGROUND_RUNNING

允许Service Ability在后台持续运行。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：8


### ohos.permission.NFC_CARD_EMULATION

允许应用实现卡模拟功能。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：false

**起始版本**：8


### ohos.permission.NFC_TAG

允许应用读写Tag卡片。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：false

**起始版本**：7


### ohos.permission.PRIVACY_WINDOW

允许应用将窗口设置为隐私窗口，禁止截屏录屏

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：9


### ohos.permission.PUBLISH_AGENT_REMINDER

允许该应用使用后台代理提醒。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：7


### ohos.permission.SET_NETWORK_INFO

允许应用配置数据网络。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：8


### ohos.permission.SET_WIFI_INFO

允许应用配置Wi-Fi设备。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：8


### ohos.permission.VIBRATE

允许应用控制马达振动。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：7


### ohos.permission.CLEAN_BACKGROUND_PROCESSES

允许应用根据包名清理相关后台进程。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：7


### ohos.permission.COMMONEVENT_STICKY

允许应用发布粘性公共事件。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：7


### ohos.permission.MODIFY_AUDIO_SETTINGS

允许应用修改音频设置。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：8


### ohos.permission.RUNNING_LOCK

允许应用获取运行锁，保证应用在后台的持续运行。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：7


### ohos.permission.SET_WALLPAPER

允许应用设置壁纸。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：7


### ohos.permission.ACCESS_CERT_MANAGER

允许应用进行查询证书及私有凭据等操作。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：false

**起始版本**：9


### ohos.permission.hsdr.HSDR_ACCESS

允许应用访问安全检测与响应框架。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：false

**起始版本**：10

### ohos.permission.RUN_DYN_CODE

允许应用运行动态代码。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：false

**起始版本**：11

### ohos.permission.READ_CLOUD_SYNC_CONFIG

允许接入云空间的应用查询应用云同步相关配置信息。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：true

**起始版本**：11


## user_grant（用户授权）权限列表

以下权限的授权方式均为[user_grant（用户授权）](app-permission-mgmt-overview.md#user_grant用户授权)，申请方式请参考[声明权限](declare-permissions.md) &gt; [向用户申请授权](request-user-authorization.md) 。


### ohos.permission.ACCESS_BLUETOOTH

允许应用接入蓝牙并使用蓝牙能力，例如配对、连接外围设备等。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：false

**起始版本**：10


### ohos.permission.MEDIA_LOCATION

允许应用访问用户媒体文件中的地理位置信息。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：true

**起始版本**：7


### ohos.permission.APP_TRACKING_CONSENT

允许应用读取开放匿名设备标识符。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：true

**起始版本**：9


### ohos.permission.ACTIVITY_MOTION

允许应用读取用户的运动状态。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：true

**起始版本**：7


### ohos.permission.CAMERA

允许应用使用相机。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：true

**起始版本**：9


### ohos.permission.DISTRIBUTED_DATASYNC

允许不同设备间的数据交换。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：true

**起始版本**：7


### ohos.permission.LOCATION_IN_BACKGROUND

允许应用在后台运行时获取设备位置信息。

**申请条件**：需要先申请前台位置权限[ohos.permission.LOCATION](#ohospermissionlocation)和[ohos.permission.APPROXIMATELY_LOCATION](#ohospermissionapproximately_location)后，才可申请此权限。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：false

**起始版本**：7


### ohos.permission.LOCATION

允许应用获取设备位置信息。

**申请条件**：需要先申请模糊位置权限[ohos.permission.APPROXIMATELY_LOCATION](#ohospermissionapproximately_location)，才可申请此权限。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：true

**起始版本**：7


### ohos.permission.APPROXIMATELY_LOCATION

允许应用获取设备模糊位置信息。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：false

**起始版本**：9


### ohos.permission.MICROPHONE

允许应用使用麦克风。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：true

**起始版本**：8


### ohos.permission.READ_CALENDAR

允许应用读取日历信息。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：true

**起始版本**：8


### ohos.permission.READ_HEALTH_DATA

允许应用读取用户的健康数据。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：true

**起始版本**：7


### ohos.permission.READ_MEDIA

允许应用读取用户外部存储中的媒体文件信息。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：true

**起始版本**：7


### ohos.permission.WRITE_CALENDAR

允许应用添加、移除或更改日历活动。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：true

**起始版本**：8


### ohos.permission.WRITE_MEDIA

允许应用读写用户外部存储中的媒体文件信息。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：true

**起始版本**：7
