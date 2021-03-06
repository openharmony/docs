# 权限定义列表

在符合[应用申请和使用权限的基本原则](accesstoken-overview.md#基本原则)的基础上，可以根据下图判断应用是否可以申请某权限。

![](figures/permission-application-process.png)

1. 应用APL等级与权限等级的匹配关系请参考[访问控制开发概述-权限等级说明](accesstoken-overview.md#权限等级说明)。
2. 权限的授权方式分为user_grant（用户授权）和system_grant（系统授权），具体请参考[访问控制开发概述-权限类型说明](accesstoken-overview.md#权限类型说明)。
3. 应用可以通过ACL（访问控制列表）方式申请高级别的权限，具体请参考[访问控制开发概述-访问控制列表说明](accesstoken-overview.md#访问控制列表acl说明)。

以下给出当前系统定义的权限信息列表。权限的使用示例请参考[访问控制开发指导](accesstoken-guidelines.md)。

| 权限名                                                   | 权限级别     | 授权方式     | ACL使能 | 权限说明                                                     |
| -------------------------------------------------------- | ------------ | ------------ | ------- | ------------------------------------------------------------ |
| ohos.permission.USE_BLUETOOTH                            | normal       | system_grant | TRUE    | 允许应用查看蓝牙的配置。                                     |
| ohos.permission.DISCOVER_BLUETOOTH                       | normal       | system_grant | TRUE    | 允许应用配置本地蓝牙，查找远端设备且与之配对连接。           |
| ohos.permission.MANAGE_BLUETOOTH                         | system_basic | system_grant | TRUE    | 允许应用配对蓝牙设备，并对设备的电话簿或消息进行访问。       |
| ohos.permission.INTERNET                                 | normal       | system_grant | TRUE    | 允许使用Internet网络。                                       |
| ohos.permission.MODIFY_AUDIO_SETTINGS                    | normal       | system_grant | TRUE    | 允许应用修改音频设置。                                       |
| ohos.permission.ACCESS_NOTIFICATION_POLICY               | normal       | system_grant | FALSE   | 在本设备上允许应用访问通知策略。                             |
| ohos.permission.GET_TELEPHONY_STATE                      | system_basic | system_grant | TRUE    | 允许应用读取电话信息。                                       |
| ohos.permission.REQUIRE_FORM                             | system_basic | system_grant | TRUE    | 允许应用获取Ability Form。                                   |
| ohos.permission.GET_NETWORK_INFO                         | normal       | system_grant | TRUE    | 允许应用获取数据网络信息。                                   |
| ohos.permission.PLACE_CALL                               | system_basic | system_grant | TRUE    | 允许应用直接拨打电话。                                       |
| ohos.permission.SET_NETWORK_INFO                         | normal       | system_grant | TRUE    | 允许应用配置数据网络。                                       |
| ohos.permission.REMOVE_CACHE_FILES                       | system_basic | system_grant | TRUE    | 允许清理指定应用的缓存。                                     |
| ohos.permission.REBOOT                                   | system_basic | system_grant | TRUE    | 允许应用重启设备。                                           |
| ohos.permission.RUNNING_LOCK                             | normal       | system_grant | TRUE    | 允许应用获取运行锁，保证应用在后台的持续运行。               |
| ohos.permission.ENROLL_BIOMETRIC                         | system_core  | system_grant | FALSE   | 允许应用录入或删除生物特征数据。                             |
| ohos.permission.ACCESS_BIOMETRIC                         | normal       | system_grant | FALSE   | 允许应用使用生物特征识别能力进行身份认证。                   |
| ohos.permission.ACCESS_BIOMETRIC_INTERNAL                | system_core  | system_grant | FALSE   | 允许应用申请或释放生物特征识别的资源。                       |
| ohos.permission.RESET_BIOMETRIC_LOCKOUT                  | system_core  | system_grant | FALSE   | 允许应用重置生物特征识别的认证失败计数。                     |
| ohos.permission.SET_TIME                                 | system_basic | system_grant | TRUE    | 允许应用修改系统时间。                                       |
| ohos.permission.SET_TIME_ZONE                            | system_basic | system_grant | TRUE    | 允许应用修改系统时区。                                       |
| ohos.permission.DOWNLOAD_SESSION_MANAGER                 | system_core  | system_grant | TRUE    | 允许应用管理下载任务会话。                                   |
| ohos.permission.COMMONEVENT_STICKY                       | normal       | system_grant | TRUE    | 允许应用发布粘性公共事件。                                   |
| ohos.permission.SYSTEM_FLOAT_WINDOW                      | normal       | system_grant | TRUE    | 允许应用使用悬浮窗的能力。                                   |
| ohos.permission.POWER_MANAGER                            | system_core  | system_grant | TRUE    | 允许应用调用电源管理子系统的接口，休眠或者唤醒设备。         |
| ohos.permission.REFRESH_USER_ACTION                      | system_basic | system_grant | TRUE    | 允许应用在收到用户事件时，重新计算超时时间。                 |
| ohos.permission.POWER_OPTIMIZATION                       | system_basic | system_grant | TRUE    | 允许系统应用设置省电模式、获取省电模式的配置信息并接收配置变化的通知。 |
| ohos.permission.REBOOT_RECOVERY                          | system_basic | system_grant | TRUE    | 允许系统应用重启设备并进入恢复模式。                         |
| ohos.permission.MANAGE_LOCAL_ACCOUNTS                    | system_basic | system_grant | TRUE    | 允许应用管理本地用户账号。                                   |
| ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS           | system_basic | system_grant | TRUE    | 允许多个系统账号之间相互访问。                               |
| ohos.permission.VIBRATE                                  | normal       | system_grant | TRUE    | 允许应用控制马达振动。                                       |
| ohos.permission.CONNECT_IME_ABILITY                      | system_core  | system_grant | TRUE    | 允许绑定输入法Ability(InputMethodAbility)。                  |
| ohos.permission.CONNECT_SCREEN_SAVER_ABILITY             | system_core  | system_grant | TRUE    | 允许绑定屏保Ability(ScreenSaverAbility)。                    |
| ohos.permission.READ_SCREEN_SAVER                        | system_basic | system_grant | TRUE    | 允许应用查询屏保状态信息。                                   |
| ohos.permission.WRITE_SCREEN_SAVER                       | system_basic | system_grant | TRUE    | 允许应用修改屏保状态信息。                                   |
| ohos.permission.SET_WALLPAPER                            | normal       | system_grant | TRUE    | 允许应用设置静态壁纸。                                       |
| ohos.permission.GET_WALLPAPER                            | system_basic | system_grant | TRUE    | 允许应用读取壁纸文件。                                       |
| ohos.permission.CHANGE_ABILITY_ENABLED_STATE             | system_basic | system_grant | TRUE    | 允许改变应用或者组件的使能状态。                             |
| ohos.permission.ACCESS_MISSIONS                          | system_basic | system_grant | TRUE    | 允许应用访问任务栈信息。                                     |
| ohos.permission.CLEAN_BACKGROUND_PROCESSES               | normal       | system_grant | TRUE    | 允许应用根据包名清理相关后台进程。                           |
| ohos.permission.KEEP_BACKGROUND_RUNNING                  | normal       | system_grant | TRUE    | 允许Service Ability在后台持续运行。                          |
| ohos.permission.UPDATE_CONFIGURATION                     | system_basic | system_grant | TRUE    | 允许更新系统配置。                                           |
| ohos.permission.UPDATE_SYSTEM                            | system_basic | system_grant | TRUE    | 允许调用升级接口。                                           |
| ohos.permission.FACTORY_RESET                            | system_basic | system_grant | TRUE    | 允许调用回复出厂接口。                                       |
| ohos.permission.GRANT_SENSITIVE_PERMISSIONS              | system_core  | system_grant | TRUE    | 允许应用为其他应用授予敏感权限。                             |
| ohos.permission.REVOKE_SENSITIVE_PERMISSIONS             | system_core  | system_grant | TRUE    | 允许应用撤销给其他应用授予的敏感信息。                       |
| ohos.permission.GET_SENSITIVE_PERMISSIONS                | system_core  | system_grant | TRUE    | 允许应用读取其他应用的敏感权限的状态。                       |
| ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION | system_core  | system_grant | TRUE    | 允许应用跨用户对其他应用的属性进行设置。                     |
| ohos.permission.LISTEN_BUNDLE_CHANGE                     | system_basic | system_grant | TRUE    | 允许应用监听其他应用安装、更新、卸载状态的变化。             |
| ohos.permission.GET_BUNDLE_INFO                          | normal       | system_grant | TRUE    | 允许应用查询其他应用的信息。                                 |
| ohos.permission.ACCELEROMETER                            | normal       | system_grant | TRUE    | 允许应用读取加速度传感器的数据。                             |
| ohos.permission.GYROSCOPE                                | normal       | system_grant | TRUE    | 允许应用读取陀螺仪传感器的数据。                             |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED               | system_basic | system_grant | TRUE    | 允许应用查询其他应用的信息。                                 |
| ohos.permission.INSTALL_BUNDLE                           | system_core  | system_grant | TRUE    | 允许应用安装、卸载其他应用。                                 |
| ohos.permission.MANAGE_SHORTCUTS                         | system_core  | system_grant | TRUE    | 允许应用查询其他应用的快捷方式信息、启动其他应用的快捷方式。 |
| ohos.permission.radio.ACCESS_FM_AM                       | system_core  | system_grant | TRUE    | 允许应用获取收音机相关服务。                                 |
| ohos.permission.SET_TELEPHONY_STATE                      | system_basic | system_grant | TRUE    | 允许应用修改telephone的状态。                                |
| ohos.permission.START_ABILIIES_FROM_BACKGROUND           | system_basic | system_grant | TRUE    | 允许应用在后台启动FA。                                       |
| ohos.permission.BUNDLE_ACTIVE_INFO                       | system_basic | system_grant | TRUE    | 允许系统应用查询其他应用在前台或后台的运行时间。             |
| ohos.permission.START_INVISIBLE_ABILITY                  | system_core  | system_grant | TRUE    | 无论Ability是否可见，都允许应用进行调用。                    |
| ohos.permission.sec.ACCESS_UDID                          | system_basic | system_grant | TRUE    | 允许系统应用获取UDID。                                       |
| ohos.permission.LAUNCH_DATA_PRIVACY_CENTER               | system_basic | system_grant | TRUE    | 允许应用从其隐私声明页面跳转至"数据与隐私"页面。             |
| ohos.permission.MANAGE_MEDIA_RESOURCES                   | system_basic | system_grant | TRUE    | 允许应用程序获取当前设备正在播放的媒体资源，并对其进行管理。 |
| ohos.permission.PUBLISH_AGENT_REMINDER                   | normal       | system_grant | TRUE    | 允许该应用使用后台代理提醒。                                 |
| ohos.permission.CONTROL_TASK_SYNC_ANIMATOR               | system_core  | system_grant | TRUE    | 允许应用使用同步任务动画。                                   |
| ohos.permission.INPUT_MONITORING                         | system_core  | system_grant | TRUE    | 允许应用监听输入事件，仅系统签名应用可申请此权限。           |
| ohos.permission.MANAGE_MISSIONS                          | system_core  | system_grant | TRUE    | 允许用户管理元能力任务栈。                                   |
| ohos.permission.NOTIFICATION_CONTROLLER                  | system_core  | system_grant | TRUE    | 允许应用管理通知和订阅通知。                                 |
| ohos.permission.CONNECTIVITY_INTERNAL                    | system_basic | system_grant | TRUE    | 允许应用程序获取网络相关的信息或修改网络相关设置。           |
| ohos.permission.SET_ABILITY_CONTROLLER                   | system_basic | system_grant | TRUE    | 允许设置ability组件启动和停止控制权。                        |
| ohos.permission.USE_USER_IDM                             | system_basic | system_grant | FALSE   | 允许应用访问系统身份凭据信息。                               |
| ohos.permission.MANAGE_USER_IDM                          | system_basic | system_grant | FALSE   | 允许应用使用系统身份凭据管理能力进行口令、人脸、指纹等录入、修改、删除等操作。 |
| ohos.permission.ACCESS_BIOMETRIC                         | normal       | system_grant | TRUE    | 允许应用使用生物特征识别能力进行身份认证。                   |
| ohos.permission.ACCESS_USER_AUTH_INTERNAL                | system_basic | system_grant | FALSE   | 允许应用使用系统身份认证能力进行用户身份认证或身份识别。     |
| ohos.permission.ACCESS_PIN_AUTH                          | system_basic | system_grant | FALSE   | 允许应用使用口令输入接口，用于系统应用完成口令输入框绘制场景。 |
| ohos.permission.GET_RUNNING_INFO                         | system_basic | system_grant | TRUE    | 允许应用获取运行态信息。                                     |
| ohos.permission.CLEAN_APPLICATION_DATA                   | system_basic | system_grant | TRUE    | 允许应用清理应用数据。                                       |
| ohos.permission.RUNNING_STATE_OBSERVER                   | system_basic | system_grant | TRUE    | 允许应用观察应用状态。                                       |
| ohos.permission.CAPTURE_SCREEN                           | system_core  | system_grant | TRUE    | 允许应用截取屏幕图像。                                       |
| ohos.permission.GET_WIFI_INFO                            | normal       | system_grant | TRUE    | 允许应用获取WLAN信息。                                       |
| ohos.permission.GET_WIFI_INFO_INTERNAL                   | system_core  | system_grant | TRUE    | 允许应用获取WLAN信息。                                       |
| ohos.permission.SET_WIFI_INFO                            | normal       | system_grant | TRUE    | 允许应用配置WLAN设备。                                       |
| ohos.permission.GET_WIFI_PEERS_MAC                       | system_core  | system_grant | TRUE    | 允许应用获取对端WLAN或者蓝牙设备的MAC地址。                  |
| ohos.permission.GET_WIFI_LOCAL_MAC                       | system_basic | system_grant | TRUE    | 允许应用获取本机WLAN或者蓝牙设备的MAC地址。                  |
| ohos.permission.GET_WIFI_CONFIG                          | system_basic | system_grant | TRUE    | 允许应用获取WLAN配置信息。                                   |
| ohos.permission.SET_WIFI_CONFIG                          | system_basic | system_grant | TRUE    | 允许应用配置WLAN信息。                                       |
| ohos.permission.MANAGE_WIFI_CONNECTION                   | system_core  | system_grant | TRUE    | 允许应用管理WLAN连接。                                       |
| ohos.permission.MANAGE_WIFI_HOTSPOT                      | system_core  | system_grant | TRUE    | 允许应用开启或者关闭WLAN热点。                               |
| ohos.permission.GET_ALL_APP_ACCOUNTS                     | system_core  | system_grant | FALSE   | 允许应用获取所有应用账户信息。                               |
| ohos.permission.MANAGE_SECURE_SETTINGS                   | system_basic | system_grant | TRUE    | 允许应用修改安全类系统设置。                                 |
| ohos.permission.READ_DFX_SYSEVENT                        | system_basic | system_grant | FALSE   | 允许获取所有应用账号信息。                                   |
| ohos.permission.MANAGE_ADMIN                             | system_core  | system_grant | TRUE    | 允许应用激活设备管理员应用。                                 |
| ohos.permission.EDM_MANAGE_DATETIME                      | normal       | system_grant | FALSE   | 允许设备管理员应用设置系统时间。                             |
| ohos.permission.NFC_TAG                                  | normal       | system_grant | FALSE   | 允许应用读取Tag卡片。                                        |
| ohos.permission.NFC_CARD_EMULATION                       | normal       | system_grant | FALSE   | 允许应用实现卡模拟功能。                                     |
| ohos.permission.PERMISSION_USED_STATS                    | system_core  | system_grant | TRUE    | 允许系统应用访问权限使用记录。                               |
| ohos.permission.NOTIFICATION_AGENT_CONTROLLER            | system_core  | system_grant | TRUE    | 允许应用发送代理通知。                                       |
| ohos.permission.ANSWER_CALL                              | system_basic | user_grant   | TRUE    | 允许应用接听来电。                                           |
| ohos.permission.READ_CALENDAR                            | normal       | user_grant   | TRUE    | 允许应用读取日历信息。                                       |
| ohos.permission.READ_CALL_LOG                            | system_basic | user_grant   | TRUE    | 允许应用读取通话记录。                                       |
| ohos.permission.READ_CELL_MESSAGES                       | system_basic | user_grant   | TRUE    | 允许应用读取设备收到的小区广播信息。                         |
| ohos.permission.READ_CONTACTS                            | system_basic | user_grant   | TRUE    | 允许应用读取联系人数据。                                     |
| ohos.permission.READ_MESSAGES                            | system_basic | user_grant   | TRUE    | 允许应用读取短信息。                                         |
| ohos.permission.RECEIVE_MMS                              | system_basic | user_grant   | TRUE    | 允许应用接收和处理彩信。                                     |
| ohos.permission.RECEIVE_SMS                              | system_basic | user_grant   | TRUE    | 允许应用接收和处理短信。                                     |
| ohos.permission.RECEIVE_WAP_MESSAGES                     | system_basic | user_grant   | TRUE    | 允许应用接收和处理WAP消息。                                  |
| ohos.permission.MICROPHONE                               | normal       | user_grant   | TRUE    | 允许应用使用麦克风。                                         |
| ohos.permission.SEND_MESSAGES                            | system_basic | user_grant   | TRUE    | 允许应用发送短信。                                           |
| ohos.permission.WRITE_CALENDAR                           | normal       | user_grant   | TRUE    | 允许应用添加、移除或更改日历活动。                           |
| ohos.permission.WRITE_CALL_LOG                           | system_basic | user_grant   | TRUE    | 允许应用添加、移除或更改通话记录。                           |
| ohos.permission.WRITE_CONTACTS                           | system_basic | user_grant   | TRUE    | 允许应用添加、移除或更改联系人数据。                         |
| ohos.permission.DISTRIBUTED_DATASYNC                     | normal       | user_grant   | TRUE    | 允许不同设备间的数据交换。                                   |
| ohos.permission.MANAGE_VOICEMAIL                         | system_basic | user_grant   | TRUE    | 允许应用在语音信箱中留言                                     |
| ohos.permission.LOCATION_IN_BACKGROUND                   | normal       | user_grant   | FALSE   | 允许应用在后台运行时获取设备位置信息。                       |
| ohos.permission.LOCATION                                 | normal       | user_grant   | TRUE    | 允许应用获取设备位置信息。                                   |
| ohos.permission.MEDIA_LOCATION                           | normal       | user_grant   | TRUE    | 允许应用访问用户媒体文件中的地理位置信息。                   |
| ohos.permission.CAMERA                                   | normal       | user_grant   | TRUE    | 允许应用使用相机拍摄照片和录制视频。                         |
| ohos.permission.READ_MEDIA                               | normal       | user_grant   | TRUE    | 允许应用读取用户外部存储中的媒体文件信息。                   |
| ohos.permission.WRITE_MEDIA                              | normal       | user_grant   | TRUE    | 允许应用读写用户外部存储中的媒体文件信息。                   |
| ohos.permission.ACTIVITY_MOTION                          | normal       | user_grant   | TRUE    | 允许应用读取用户当前的运动状态。                             |
| ohos.permission.READ_HEALTH_DATA                         | normal       | user_grant   | TRUE    | 允许应用读取用户的健康数据。                                 |
| ohos.permission.GET_DEFAULT_APPLICATION                  | system_core  | system_grant | TRUE    | 允许应用查询默认应用。                                       |
| ohos.permission.SET_DEFAULT_APPLICATION                  | system_core  | system_grant | TRUE    | 允许应用设置、重置默认应用。                                 |
| ohos.permission.MANAGE_DISPOSED_APP_STATUS               | system_core  | system_grant | TRUE    | 允许设置和查询应用的处置状态。                               |
| ohos.permission.ACCESS_IDS                               | system_core  | system_grant | TRUE    | 允许应用查询设备的唯一标识符信息。                               |