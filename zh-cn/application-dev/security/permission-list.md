# 应用权限列表

在申请目标权限前，建议开发者先阅读[访问控制开发概述-权限的工作流程](accesstoken-overview.md#权限的工作流程)。对权限的工作流程有基本的了解后，再结合以下权限的具体说明，判断应用能否申请目标权限，提高开发效率。

权限的使用示例请参考[访问控制开发指导](accesstoken-guidelines.md)。

## ohos.permission.USE_BLUETOOTH

允许应用查看蓝牙的配置。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.DISCOVER_BLUETOOTH

允许应用配置本地蓝牙，查找远端设备且与之配对连接。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.MANAGE_BLUETOOTH

允许应用配对蓝牙设备，并对设备的电话簿或消息进行访问。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.INTERNET

允许使用Internet网络。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.MODIFY_AUDIO_SETTINGS

允许应用修改音频设置。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.ACCESS_NOTIFICATION_POLICY

在本设备上允许应用访问通知策略。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.GET_TELEPHONY_STATE

允许应用读取电话信息。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.REQUIRE_FORM

允许应用获取Ability Form。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.GET_NETWORK_INFO

允许应用获取数据网络信息。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.PLACE_CALL

允许应用直接拨打电话。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.SET_NETWORK_INFO

允许应用配置数据网络。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.REMOVE_CACHE_FILES

允许清理指定应用的缓存。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.REBOOT

允许应用重启设备。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.RUNNING_LOCK

允许应用获取运行锁，保证应用在后台的持续运行。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.SET_TIME

允许应用修改系统时间。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.SET_TIME_ZONE

允许应用修改系统时区。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.DOWNLOAD_SESSION_MANAGER

允许应用管理下载任务会话。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.COMMONEVENT_STICKY

允许应用发布粘性公共事件。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.SYSTEM_FLOAT_WINDOW

允许应用使用悬浮窗的能力。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.PRIVACY_WINDOW

允许应用将窗口设置为隐私窗口，禁止截屏录屏。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.POWER_MANAGER

允许应用调用电源管理子系统的接口休眠或者唤醒设备。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.REFRESH_USER_ACTION

允许应用在收到用户事件时，重新计算超时时间。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.POWER_OPTIMIZATION

允许系统应用设置省电模式、获取省电模式的配置信息并接收配置变化的通知。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.REBOOT_RECOVERY

允许系统应用重启设备并进入恢复模式。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.MANAGE_LOCAL_ACCOUNTS

允许应用管理本地用户账号。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

允许多个系统账号之间相互访问。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.VIBRATE

允许应用控制马达振动。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.CONNECT_IME_ABILITY

允许绑定输入法Ability（InputMethodAbility）。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.CONNECT_SCREEN_SAVER_ABILITY

允许绑定屏保Ability（ScreenSaverAbility）。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.READ_SCREEN_SAVER

允许应用查询屏保状态信息。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.WRITE_SCREEN_SAVER

允许应用修改屏保状态信息。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.SET_WALLPAPER

允许应用设置静态壁纸。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.GET_WALLPAPER

允许应用读取壁纸文件。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.CHANGE_ABILITY_ENABLED_STATE

允许改变应用或者组件的使能状态。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.ACCESS_MISSIONS

允许应用访问任务栈信息。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.CLEAN_BACKGROUND_PROCESSES

允许应用根据包名清理相关后台进程。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.KEEP_BACKGROUND_RUNNING

允许Service Ability在后台持续运行。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.UPDATE_CONFIGURATION

允许更新系统配置。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.UPDATE_SYSTEM

允许调用升级接口。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.FACTORY_RESET

允许调用恢复出厂接口。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.GRANT_SENSITIVE_PERMISSIONS

允许应用为其他应用授予敏感权限。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.REVOKE_SENSITIVE_PERMISSIONS

允许应用撤销给其他应用授予的敏感信息。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.GET_SENSITIVE_PERMISSIONS

允许应用读取其他应用的敏感权限的状态。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

允许应用跨用户对其他应用的属性进行设置。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.LISTEN_BUNDLE_CHANGE

允许应用监听其他应用安装、更新、卸载状态的变化。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.GET_BUNDLE_INFO

允许应用查询其他单个应用的信息。该权限仅适用于三方应用。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

允许应用查询其他多个应用的信息。该权限仅适用于特权应用、同签名应用。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.ACCELEROMETER

允许应用读取加速度传感器的数据。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.GYROSCOPE

允许应用读取陀螺仪传感器的数据。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.INSTALL_BUNDLE

允许应用安装、卸载其他应用。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.MANAGE_SHORTCUTS

允许应用查询其他应用的快捷方式信息、启动其他应用的快捷方式。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.radio.ACCESS_FM_AM

允许应用获取收音机相关服务。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.SET_TELEPHONY_STATE

允许应用修改telephone的状态。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.START_ABILIIES_FROM_BACKGROUND

允许应用在后台启动FA。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.BUNDLE_ACTIVE_INFO

允许系统应用查询其他应用在前台或后台的运行时间。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.START_INVISIBLE_ABILITY

无论Ability是否可见，都允许应用进行调用。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.sec.ACCESS_UDID

允许系统应用获取UDID。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.LAUNCH_DATA_PRIVACY_CENTER

允许应用从其隐私声明页面跳转至"数据与隐私"页面。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.MANAGE_MEDIA_RESOURCES

允许应用程序获取当前设备正在播放的媒体资源，并对其进行管理。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.PUBLISH_AGENT_REMINDER

允许该应用使用后台代理提醒。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.CONTROL_TASK_SYNC_ANIMATOR

允许应用使用同步任务动画。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.INPUT_MONITORING

允许应用监听输入事件，仅系统签名应用可申请此权限。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.MANAGE_MISSIONS

允许用户管理元能力任务栈。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.NOTIFICATION_CONTROLLER

允许应用管理通知和订阅通知。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.CONNECTIVITY_INTERNAL

允许应用程序获取网络相关的信息或修改网络相关设置。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.SET_ABILITY_CONTROLLER

允许设置ability组件启动和停止控制权。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.USE_USER_IDM

允许应用访问系统身份凭据信息。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.MANAGE_USER_IDM

允许应用使用系统身份凭据管理能力进行口令、人脸、指纹等录入、修改、删除等操作。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.ACCESS_BIOMETRIC

允许应用使用生物特征识别能力进行身份认证。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.ACCESS_USER_AUTH_INTERNAL

允许应用使用系统身份认证能力进行用户身份认证或身份识别。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.ACCESS_PIN_AUTH

允许应用使用口令输入接口，用于系统应用完成口令输入框绘制场景。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.GET_RUNNING_INFO

允许应用获取运行态信息。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.CLEAN_APPLICATION_DATA

允许应用清理应用数据。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.RUNNING_STATE_OBSERVER

允许应用观察应用状态。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.CAPTURE_SCREEN

允许应用截取屏幕图像。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.GET_WIFI_INFO

允许应用获取WLAN信息。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.GET_WIFI_INFO_INTERNAL

允许应用获取WLAN信息。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.SET_WIFI_INFO

允许应用配置WLAN设备。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.GET_WIFI_PEERS_MAC

允许应用获取对端WLAN或者蓝牙设备的MAC地址。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.GET_WIFI_LOCAL_MAC

允许应用获取本机WLAN或者蓝牙设备的MAC地址。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.GET_WIFI_CONFIG

允许应用获取WLAN配置信息。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.SET_WIFI_CONFIG

允许应用配置WLAN信息。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.MANAGE_WIFI_CONNECTION

允许应用管理WLAN连接。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.MANAGE_WIFI_HOTSPOT

允许应用开启或者关闭WLAN热点。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.GET_ALL_APP_ACCOUNTS

允许应用获取所有应用账户信息。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.MANAGE_SECURE_SETTINGS

允许应用修改安全类系统设置。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.READ_DFX_SYSEVENT

允许应用访问系统事件打点数据。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

允许应用激活设备管理员应用。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.SET_ENTERPRISE_INFO

允许设备管理员应用设置企业信息。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

允许设备管理员应用订阅管理事件。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.ENTERPRISE_SET_DATETIME

允许设备管理员应用设置系统时间。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.ENTERPRISE_GET_DEVICE_INFO

允许设备管理员读取设备信息。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.NFC_TAG

允许应用读取Tag卡片。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.NFC_CARD_EMULATION

允许应用实现卡模拟功能。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.PERMISSION_USED_STATS

允许系统应用访问权限使用记录。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.NOTIFICATION_AGENT_CONTROLLER

允许应用发送代理通知。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.ANSWER_CALL

允许应用接听来电。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.READ_CALENDAR

允许应用读取日历信息。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.READ_CALL_LOG

允许应用读取通话记录。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.READ_CELL_MESSAGES

允许应用读取设备收到的小区广播信息。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.READ_CONTACTS

允许应用读取联系人数据。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.READ_MESSAGES

允许应用读取短信息。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.RECEIVE_MMS

允许应用接收和处理彩信。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.RECEIVE_SMS

允许应用接收和处理短信。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.RECEIVE_WAP_MESSAGES

允许应用接收和处理WAP消息。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.MICROPHONE

允许应用使用麦克风。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.SEND_MESSAGES

允许应用发送短信。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.WRITE_CALENDAR

允许应用添加、移除或更改日历活动。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.WRITE_CALL_LOG

允许应用添加、移除或更改通话记录。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.WRITE_CONTACTS

允许应用添加、移除或更改联系人数据。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.DISTRIBUTED_DATASYNC

允许不同设备间的数据交换。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.MANAGE_VOICEMAIL

允许应用在语音信箱中留言。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.LOCATION_IN_BACKGROUND

允许应用在后台运行时获取设备位置信息。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：FALSE

## ohos.permission.LOCATION

允许应用获取设备位置信息。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.APPROXIMATELY_LOCATION

允许应用获取设备模糊位置信息。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：FALSE

## ohos.permission.MEDIA_LOCATION

允许应用访问用户媒体文件中的地理位置信息。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.CAMERA

允许应用使用相机拍摄照片和录制视频。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.READ_MEDIA

允许应用读取用户外部存储中的媒体文件信息。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.WRITE_MEDIA

允许应用读写用户外部存储中的媒体文件信息。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.ACTIVITY_MOTION

允许应用读取用户当前的运动状态。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.READ_HEALTH_DATA

允许应用读取用户的健康数据。

**权限级别**：normal

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.GET_DEFAULT_APPLICATION

允许应用查询默认应用。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.SET_DEFAULT_APPLICATION

允许应用设置、重置默认应用。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.MANAGE_DISPOSED_APP_STATUS

允许设置和查询应用的处置状态。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.ACCESS_IDS

允许应用查询设备的唯一标识符信息。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.DUMP

允许导出系统基础信息和SA服务信息。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.DISTRIBUTED_SOFTBUS_CENTER

允许不同设备之间进行组网处理。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.ACCESS_DLP_FILE

允许对DLP文件进行权限配置和管理。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.PROVISIONING_MESSAGE

允许激活超级设备管理器应用。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.ACCESS_SYSTEM_SETTINGS

允许应用接入或拉起系统设置界面。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.READ_IMAGEVIDEO

允许读取用户公共目录的图片或视频文件。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.READ_AUDIO

允许读取用户公共目录的音频文件。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.READ_DOCUMENT

允许读取用户公共目录的文档。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.WRITE_IMAGEVIDEO

允许修改用户公共目录的图片或视频文件。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.WRITE_AUDIO

允许修改用户公共目录的音频文件。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.WRITE_DOCUMENT

允许修改用户公共目录的文档。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.ABILITY_BACKGROUND_COMMUNICATION

允许应用将Ability组件在后台启动并与该Ability建立通信连接。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.securityguard.REPORT_SECURITY_INFO

允许应用上报风险数据至设备风险管理平台。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.securityguard.REQUEST_SECURITY_MODEL_RESULT

允许应用获取设备风险状态。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.securityguard.REQUEST_SECURITY_EVENT_INFO

允许应用获取风险详细数据。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.READ_ACCESSIBILITY_CONFIG

允许应用读取无障碍配置信息。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.WRITE_ACCESSIBILITY_CONFIG

允许应用设置无障碍配置信息。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

允许应用进行证书及凭据的安装、卸载、启用、禁用等操作。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.ACCESS_CERT_MANAGER

允许应用进行私有凭据的相关操作、查询证书状态等操作。

**权限级别**：normal

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.ACCESS_PUSH_SERVICE

允许应用访问推送服务的Ability。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.RECEIVER_STARTUP_COMPLETED

允许应用订阅开机广播。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.MANAGE_CAMERA_CONFIG

允许应用进行全局相机开关等操作。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.READ_WHOLE_CALENDAR

允许应用读取所有的日历信息。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.WRITE_WHOLE_CALENDAR

允许应用添加、移除或更改所有的日历活动。

**权限级别**：system_basic

**授权方式**：user_grant

**ACL使能**：TRUE

## ohos.permission.ENFORCE_USER_IAM

允许SA无token删除IAM子系统用户信息。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.ACCESS_AUTH_RESPOOL

允许SA注册执行器。

**权限级别**：system_core

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.MOUNT_UNMOUNT_MANAGER

允许应用对外卡进行挂载卸载操作。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.MOUNT_FORMAT_MANAGER

允许应用对外卡进行格式化操作。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：FALSE

## ohos.permission.STORAGE_MANAGER

允许应用调用storage manager服务中对空间统计以及卷信息的查询接口。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.BACKUP

允许应用拥有备份恢复能力。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.FILE_ACCESS_MANAGER

允许文件管理类应用通过FAF框架访问公共数据文件。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.MANAGE_AUDIO_CONFIG

允许应用进行全局麦克风静音等操作。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE

## ohos.permission.ACCESS_SERVICE_DM

允许系统应用获取分布式设备的认证组网能力。

**权限级别**：system_basic

**授权方式**：system_grant

**ACL使能**：TRUE
