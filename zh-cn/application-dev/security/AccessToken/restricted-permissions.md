# 受限开放权限

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--Designer: @linshuqing; @hehehe-li-->
<!--Tester: @leiyuqian-->
<!--Adviser: @zengyawen-->

## 申请方式

<!--RP1-->

以下权限的开放范围为普通应用，但需要通过[访问控制列表（ACL）](app-permission-mgmt-overview.md#权限机制中的基本概念)的方式跨级别申请。

normal等级的应用需要将自身的APL等级声明为system_basic及以上，在开发应用安装包时，需要修改应用的HarmonyAppProvision配置文件即SDK目录下的“`Toolchains / _{Version} _/ lib / UnsignedReleasedProfileTemplate.json`”文件，并重新进行应用签名。

**修改方式：**

HarmonyAppProvision配置文件示例如下所示，修改"bundle-info" &gt; "apl" 字段。

```json5
"bundle-info" : {
    // ...
    "apl": "system_basic",
    // ...
},
```

> **说明：**
> 直接修改HarmonyAppProvision配置文件的方式，仅用于应用调试阶段使用，不可用于发布上架应用市场。如果需要开发商用版本的应用，请在对应的应用市场进行发布证书和Profile文件的申请。

<!--RP1End-->

## ohos.permission.SYSTEM_FLOAT_WINDOW

允许应用使用悬浮窗的能力。

<!--RP25--><!--RP25End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：7

## ohos.permission.READ_CONTACTS

允许应用读取联系人数据。

<!--RP33--><!--RP33End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：8

## ohos.permission.WRITE_CONTACTS

允许应用添加、移除或更改联系人数据。

<!--RP34--><!--RP34End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：8

## ohos.permission.READ_AUDIO

允许读取用户公共目录的音频文件。

<!--RP26--><!--RP26End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：9

## ohos.permission.WRITE_AUDIO

允许修改用户公共目录的音频文件。

<!--RP28--><!--RP28End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：9

## ohos.permission.READ_IMAGEVIDEO

允许读取用户本地公共目录的图片或视频文件。

<!--RP27--><!--RP27End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：9

**变更信息**：在API版本9-24，申请该权限可访问云上和本地图片或视频文件；从API版本26.0.0开始，申请该权限仅能读取用户本地公共目录的图片或视频文件。

## ohos.permission.WRITE_IMAGEVIDEO

允许修改用户公共目录的图片或视频文件。

<!--RP29--><!--RP29End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：9

<!--Del-->
## ohos.permission.WRITE_DOCUMENT

允许修改用户公共目录的文档。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：9

**废弃版本**：12

**替代方案**：

请参考[文件权限组废弃替代方案](app-permission-group-list.md#文件deprecated)。

## ohos.permission.READ_DOCUMENT

允许读取用户公共目录的文档。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：9

**废弃版本**：12

**替代方案**：

请参考[文件权限组废弃替代方案](app-permission-group-list.md#文件deprecated)。
<!--DelEnd-->

## ohos.permission.READ_WRITE_DESKTOP_DIRECTORY

允许应用访问公共目录下Desktop目录及子目录。

当前仅2in1设备和平板上的应用可申请此权限。

<!--RP15--><!--RP15End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：11

## ohos.permission.ACCESS_DDK_USB

允许扩展外设驱动访问USB DDK接口开发USB总线扩展外设驱动。

<!--RP31--><!--RP31End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：11

## ohos.permission.ACCESS_DDK_HID

允许扩展外设驱动访问HID DDK接口开发HID类扩展外设驱动。

<!--RP30--><!--RP30End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：11

## ohos.permission.READ_PASTEBOARD

允许应用读取剪贴板。

<!--RP32--><!--RP32End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**支持设备**：Phone | TV | Wearable | PC/2in1 | Tablet | Car

**起始版本**：11

## ohos.permission.FILE_ACCESS_PERSIST

允许应用支持持久化访问文件Uri。

> **说明：**
>
> 在API 12及以上版本，该权限等级变更为normal，应用可直接[声明使用](declare-permissions.md)；若需兼容API12之前版本，仍需按[受限权限申请方式](declare-permissions-in-acl.md)使用该权限。

<!--RP18--><!--RP18End-->

**权限级别**：normal

**授权方式**：系统授权（system_grant）

**起始版本**：11

**变更信息：** 在API 11，权限等级为system_basic；从API 12开始，权限等级变更为normal，向普通应用开放。

## ohos.permission.INTERCEPT_INPUT_EVENT

允许应用拦截输入事件。

<!--RP24--><!--RP24End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：General

**起始版本**：11

**变更信息**：API 11，权限等级为system_core；从API 12开始，权限等级变更为system_basic，向普通应用开放。从API 26.0.0开始，该权限支持在全设备上申请。

## ohos.permission.INPUT_MONITORING

允许应用监听输入事件。

<!--RP23--><!--RP23End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：7

**变更信息**：API 7-11，权限等级为system_core；从API 12开始，权限等级变更为system_basic，向普通应用开放。

## ohos.permission.SHORT_TERM_WRITE_IMAGEVIDEO

允许应用保存图片、视频到用户公共目录。

应用获取此权限后，最长可获得30分钟的短时授权，来保存图片/视频。如果超过30分钟，将再次弹窗，需要用户再次确认。

<!--RP21--><!--RP21End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：12

## ohos.permission.READ_WRITE_USER_FILE

允许应用访问并修改用户目录下的文件。

<!--RP19-->
当前仅2in1设备应用可申请此权限。
<!--RP19End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：13

## ohos.permission.READ_WRITE_USB_DEV

允许应用连接设备，并通过USB调试读写该设备。

<!--RP20-->
当前仅2in1设备应用可申请此权限。
<!--RP20End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：13

## ohos.permission.GET_WIFI_PEERS_MAC

允许应用获取对端Wi-Fi设备的MAC地址。

在获取Wi-Fi扫描结果时，如果需要获取对端设备的MAC地址，则需要申请该权限。

<!--RP14--><!--RP14End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：8

**变更信息**：API 8-13，权限等级为system_core；从API 14开始，权限等级变更为system_basic，向普通应用开放。

## ohos.permission.SET_TELEPHONY_ESIM_STATE_OPEN

允许运营商应用添加eSIM配置文件。

<!--RP86--><!--RP86End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：13

**变更信息**：在API 13，权限等级为normal；从API 14开始，权限等级变更为system_basic。

## ohos.permission.kernel.DISABLE_CODE_MEMORY_PROTECTION

允许应用禁用本应用的代码运行时完整性保护。

<!--RP11-->
针对使用跨平台框架开发的应用，用于应用豁免代码运行时的完整性保护。当前仅平板、2in1设备应用可申请此权限。
<!--RP11End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：14

## ohos.permission.kernel.ALLOW_WRITABLE_CODE_MEMORY

允许应用申请可写可执行匿名内存。

<!--RP10-->
针对使用跨平台框架开发的应用，用于应用申请可写可执行的匿名内存。当前仅平板、2in1设备应用可申请此权限。
<!--RP10End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：14

## ohos.permission.kernel.ALLOW_EXECUTABLE_FORT_MEMORY

允许系统JS引擎申请带MAP_FORT标识的匿名可执行内存。

应用申请此权限后，系统引擎可申请带MAP_FORT的匿名可执行内存，做即时编译，提高运行时执行效率。

<!--RP13--><!--RP13End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：14

## ohos.permission.MANAGE_PASTEBOARD_APP_SHARE_OPTION

允许应用设置或移除剪贴板数据的可粘贴范围。

<!--RP16--><!--RP16End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | TV | Wearable | PC/2in1 | Tablet | Car

**起始版本**：14

## ohos.permission.MANAGE_UDMF_APP_SHARE_OPTION

允许应用设置或移除其使用UDMF支持的数据分享范围。

<!--RP17--><!--RP17End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：14

## ohos.permission.ACCESS_DISK_PHY_INFO

允许应用获取硬盘的硬件信息。

<!--RP3--><!--RP3End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：15

## ohos.permission.PRELOAD_FILE

允许应用预加载文件以提升文件打开速度。

<!--RP9--><!--RP9End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：PC/2in1 | Tablet

**起始版本**：15

**变更信息**：从API版本26.0.0开始，增加支持在平板上申请。

## ohos.permission.SET_PAC_URL

允许应用设置代理自动配置脚本地址。

应用完成脚本地址配置后，其他应用可读取此脚本并进行解析，根据解析结果决定是否使用代理。

<!--RP4--><!--RP4End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：15

## ohos.permission.PERSONAL_MANAGE_RESTRICTIONS

允许设备管理应用管理个人设备限制策略。

<!--RP7--><!--RP7End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：15

## ohos.permission.START_PROVISIONING_MESSAGE

允许应用启动设备管理业务部署流程，将该应用激活为个人设备管理应用。

<!--RP8--><!--RP8End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：15

## ohos.permission.USE_FRAUD_CALL_LOG_PICKER

允许应用使用诈骗通话记录选择器，获取通话记录内容。

<!--RP5--><!--RP5End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：15

## ohos.permission.USE_FRAUD_MESSAGES_PICKER

允许应用使用诈骗短信选择器，获取短信内容。

<!--RP6--><!--RP6End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：15

## ohos.permission.PERSISTENT_BLUETOOTH_PEERS_MAC

允许应用固化对端蓝牙设备MAC对应的虚拟地址。

通过BLE扫描、BR扫描或连接监听获取到对端蓝牙设备MAC对应的虚拟地址，申请该权限且调用[access.addPersistentDeviceId](../../reference/apis-connectivity-kit/js-apis-bluetooth-access.md#accessaddpersistentdeviceid16)方法后，可保持该虚拟地址长时间存储，即使是开/关/重启蓝牙也不发生变化。

<!--RP36--><!--RP36End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：16

## ohos.permission.ACCESS_VIRTUAL_SCREEN

允许应用管控虚拟屏。

获得该权限的应用可以调用虚拟屏相关接口管理虚拟屏，包括创建虚拟屏，使虚拟屏，销毁虚拟屏等。

<!--RP37--><!--RP37End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：16

## ohos.permission.MANAGE_APN_SETTING

允许应用读取或设置APN信息。

<!--RP38--><!--RP38End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：16

## ohos.permission.GET_WIFI_LOCAL_MAC

允许应用获取本机的Wi-Fi设备的MAC地址。

<!--RP43--><!--RP43End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：8

**变更信息**：API 8-15该权限仅向系统应用开放；从API 16开始，在PC/2in1设备上面向普通应用开放，在其余设备上仍仅面向系统应用开放。

## ohos.permission.kernel.ALLOW_USE_JITFORT_INTERFACE

允许应用调用JITFort接口更新MAP_FORT内存的内容。

<!--RP12--><!--RP12End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：16

## ohos.permission.GET_ETHERNET_LOCAL_MAC

允许应用查询以太网当前MAC地址。

<!--RP51--><!--RP51End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：13

**变更信息**：API 13，该权限仅面向MDM应用开放；从API 14开始，开放范围从MDM应用变为更为企业普通应用；从API 16开始，在PC/2in1设备上面向普通应用开放，在其余设备上仍仅面向系统应用开放。

## ohos.permission.kernel.DISABLE_GOTPLT_RO_PROTECTION

允许应用关闭进程内.got.plt段的只读保护。

<!--RP22--><!--RP22End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：17

## ohos.permission.USE_FRAUD_APP_PICKER

允许应用使用诈骗应用选择器，获取应用信息。

<!--RP2--><!--RP2End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：18

## ohos.permission.ACCESS_DDK_DRIVERS

允许扩展外设驱动客户端绑定到扩展外设驱动服务端。

该权限针对扩展外设客户端绑定到扩展外设服务端权限校验，具体规则：

1. 外设扩展驱动客户端权限声明中的value字段中描述的目标扩展驱动服务端已上架或一并上架。
2. 被申请目标扩展驱动服务端对外提供能力与扩展外设驱动客户端业务诉求一致。

<!--RP82--><!--RP82End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**携带额外数据**：是，配置方法请见[Driver Development Kit开发指导](../../device/driver/externaldevice-guidelines.md#应用签名)。

**起始版本**：18

## ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

允许扩展外设驱动访问SCSI DDK接口开发SCSI Peripheral扩展外设驱动。

支持以下类型的外设扩展驱动开发：

外设以USB总线接入主机，且满足：

1. 外设InterfaceClass为Mass Storage(0x08)、InterfaceSubClass为SCSI透明命令集(0x06)。
2. 外设能够以对操作系统透明的方式来模拟SCSI设备。

<!--RP83--><!--RP83End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：18

## ohos.permission.ACCESS_DDK_USB_SERIAL

允许扩展外设驱动访问USBSerial DDK接口开发USB Serial扩展外设驱动。

USB串口DDK API可用于开发以下类型的外设扩展驱动：

外设以USB总线接入主机，且满足：

1. 外设InterfaceClass为通信设备控制类 (0x02)、InterfaceSubClass遵循ACMSubClass模型(0x02)。
2. 外设支持通过USB接口模拟传统的串行通信。

<!--RP101--><!--RP101End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备：** PC/2in1 | Tablet

**起始版本**：18

## ohos.permission.kernel.SUPPORT_PLUGIN

允许主体应用安装插件。

<!--RP35--><!--RP35End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：19

## ohos.permission.CUSTOM_SANDBOX

允许应用将沙箱类型改为动态沙箱。

<!--RP39--><!--RP39End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：18

## ohos.permission.atomicService.MANAGE_STORAGE

允许原子化服务小游戏进行存储空间大小的管理。

<!--RP96--><!--RP96End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：20

## ohos.permission.MANAGE_SCREEN_TIME_GUARD

允许应用调用屏幕时间守护相关接口，进行屏幕使用限制、应用访问控制、管控使用时间等操作。

<!--RP40--><!--RP40End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone |  Tablet

**起始版本**：20

## ohos.permission.CUSTOMIZE_SAVE_BUTTON

允许应用自定义保存控件的图标和文本。

<!--RP41--><!--RP41End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：General

**起始版本**：20

## ohos.permission.GET_ABILITY_INFO

允许应用根据URI或者FileType查询Ability信息。

<!--RP42--><!--RP42End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**: PC/2in1

**起始版本**：20

## ohos.permission.ACCESS_FIDO2_ONLINEAUTH

允许应用使用通行密钥服务的NDK。

<!--RP45--><!--RP45End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：20

## ohos.permission.USE_FLOAT_BALL

允许应用使用闪控球的能力。

<!--RP46--><!--RP46End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：20

**变更信息**：从API版本26.0.0开始，增加支持在PC/2in1上申请。

## ohos.permission.AUTO_RESTORE_MAIN_WINDOW

允许应用使用闪控球的自动恢复到应用主窗口的能力。

**申请条件**：需要与闪控球权限[ohos.permission.USE_FLOAT_BALL](#ohospermissionuse_float_ball)一起，才可申请此权限。

<!--RP69--><!--RP69End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | Tablet

**起始版本**：24

## ohos.permission.DLP_GET_HIDE_STATUS

允许应用使用信息隐藏接口，获取信息隐藏状态的能力。

获取此权限后，应用可以获取当前屏幕窥视状态，即当前是机主一人注视屏幕，还是有他人偷窥机主屏幕。

<!--RP44--><!--RP44End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**: Phone

**起始版本**：18

**变更信息**：在API18-19，该权限面向系统应用开放；从API20开始，面向普通应用开放。

## ohos.permission.READ_LOCAL_DEVICE_NAME

允许应用获取本机的设备显示名。

获取此权限后，应用可获取设置中“关于本机”页面的设备名称，否则只能获取设备出厂时的默认名称。

<!--RP47--><!--RP47End-->

**权限级别**：system_basic

**授权方式**: 系统授权（system_grant）

**支持设备**:  Phone | PC/2in1 | Tablet

**起始版本**: 20

<!--Del-->
## ohos.permission.atomicService.MANAGE_STORAGE

允许原子化服务申请差异化的存储空间大小。

**权限级别**：system_basic

**授权方式**: 系统授权（system_grant）

**支持设备**: Phone | PC/2in1 | Tablet

**起始版本**: 20
<!--DelEnd-->

## ohos.permission.KEEP_BACKGROUND_RUNNING_SYSTEM

允许应用申请特殊类型长时任务，如在手机上申请计算任务类型的长时任务。

<!--RP48--><!--RP48End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：General

**起始版本**：20

## ohos.permission.LINKTURBO

允许应用使用多网并发等网络加速能力。

获取该权限后，应用可发起多网激活、监听、释放等相关操作，以实现多路径的传输。

<!--RP49--><!--RP49End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：20

## ohos.permission.ACCESS_NET_TRACE_INFO

允许应用使用网络探测和获取TraceRoute信息的维测能力，用于检测网络时延较大的可能故障原因。

<!--RP50--><!--RP50End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：General

**起始版本**：20

## ohos.permission.READ_WHOLE_CALENDAR

允许应用读取所有的日历信息。

<!--RP84--><!--RP84End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：9

**变更信息**：在API 9-19，该权限面向系统应用开放；从API 20开始，面向普通应用开放。

## ohos.permission.WRITE_WHOLE_CALENDAR

允许应用添加、移除或更改所有的日历活动。

<!--RP85--><!--RP85End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：9

**变更信息**：在API 9-19，该权限面向系统应用开放；从API 20开始，面向普通应用开放。

## ohos.permission.SET_SYSTEMSHARE_APPLAUNCHTRUSTLIST

允许应用配置系统分享的目标应用名单。

获取该权限后，应用可控制系统分享的目标应用范围。

<!--RP53--><!--RP53End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | PC/2in1 | Tablet | TV

**起始版本**：21

## ohos.permission.HOOK_KEY_EVENT

允许应用拦截键盘输入事件。

获取该权限后，应用可以在按键事件分发到应用窗口前，将自定义的按键处理过程添加到系统的按键处理过程中。

<!--RP52--><!--RP52End-->

**权限级别**：system_basic

**授权方式**：手动设置授权（manual_settings）

**支持设备**：PC/2in1 | Tablet

**起始版本**：21

## ohos.permission.WEB_NATIVE_MESSAGING

允许应用使用Web本地通信能力。

应用获取此权限后，可以使用web本地通信能力，使浏览器扩展与本地应用进行通信。

<!--RP54--><!--RP54End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：21

**变更信息**：从API版本24开始，增加支持在手机和平板上申请。

## ohos.permission.SUBSCRIBE_NOTIFICATION

允许应用读取系统或者已安装应用发布的通知。

<!--RP55--><!--RP55End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | Tablet

**起始版本**：22

## ohos.permission.CUSTOM_SCREEN_RECORDING

允许应用无需弹窗录制屏幕。

获取该权限后，应用在录制屏幕时不再每次弹出隐私告警弹窗。

<!--RP56--><!--RP56End-->

**权限级别**：system_basic

**授权方式**：手动设置授权（manual_settings）

**支持设备**：PC/2in1 | TV

**起始版本**：22

**变更信息**：从API版本26.0.0开始，增加支持在TV上申请。

## ohos.permission.ALLOW_EXTERNAL_NATIVE_CODE

允许应用使用外部native程序。

包括加载外部动态链接库(so)、二进制文件(bin)等。

<!--RP57--><!--RP57End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：PC/2in1

**起始版本**：23

## ohos.permission.GET_IP_MAC_INFO

允许应用获取网络设备的IP和MAC地址。

<!--RP58-->
用于网络连接或者识别，不支持用于设备定位。
<!--RP58End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：General

**起始版本**：22

## ohos.permission.atomicService.MANAGE_AGING

允许原子化服务申请差异化的老化策略。

<!--RP59--><!--RP59End-->

**权限级别**：system_basic

**授权方式**: 系统授权（system_grant）

**支持设备**: Phone | PC/2in1 | Tablet

**起始版本**: 23

## ohos.permission.ACCESS_USER_FULL_DISK

允许应用无需弹窗访问用户公共路径。

获取该权限后，应用在用户授权后访问用户公共路径，每次访问不再额外弹窗提示。

<!--RP60--><!--RP60End-->

**权限级别**：system_basic

**授权方式**：手动设置授权（manual_settings）

**支持设备**：PC/2in1

**起始版本**：22

## ohos.permission.kernel.LOAD_INDEPENDENT_LIBRARY

允许应用加载二进制证书签名的共享库。

<!--RP61--><!--RP61End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：PC/2in1

**起始版本**：20

**变更信息**：在API 20-21，该权限面向系统应用开放；从API 22开始，面向普通应用开放。

## ohos.permission.CRYPTO_EXTENSION_REGISTER

允许应用注册和注销crypto扩展。

<!--RP62--><!--RP62End-->

**权限级别**：system_basic

**授权方式**: 系统授权（system_grant）

**支持设备**: PC/2in1 | Tablet | Phone

**起始版本**: 22

**变更信息：** 从API版本24开始，增加支持在平板上申请；从API版本26.0.0开始，增加支持在手机上申请。

## ohos.permission.MANAGE_MEDIA_RESOURCES_FOR_PUBLIC

允许应用获取和管理当前设备正在播放的媒体资源。

<!--RP63--><!--RP63End-->

**权限级别**：system_basic

**授权方式**: 系统授权（system_grant）

**支持设备**: Phone | PC/2in1 | Tablet | TV | Car

**起始版本**: 23

## ohos.permission.MANAGE_RECENT_SNAPSHOT

允许应用设置在多任务中和Dock栏悬停显示的预览图。

多任务和鼠标悬停在Dock栏应用图标，将展示应用实时预览图，获取该权限后，应用可自定义此预览图。

<!--RP72--><!--RP72End-->

**权限级别**: system_basic

**授权方式**: 系统授权（system_grant）

**支持设备**: PC/2in1

**起始版本**: 26.0.0

## ohos.permission.SET_WINDOW_ALPHA

允许应用设置主窗容器透明。

获取该权限后，应用可以设置主窗口容器背景色。

<!--RP73--><!--RP73End-->

**权限级别**: system_basic

**授权方式**: 系统授权（system_grant）

**支持设备**: PC/2in1

**起始版本**: 26.0.0

## ohos.permission.MANAGE_CALL_FOR_DEVICES

允许应用管理通话状态。如获取来电号码、接听、拒接、挂断等.

<!--RP64--><!--RP64End-->

**权限级别**: system_basic

**授权方式**: 系统授权（system_grant）

**支持设备**: Phone | PC/2in1 | Tablet

**起始版本**: 23

## ohos.permission.SET_WINDOW_TOUCH_AREAS

允许应用设置窗口事件热区，非热区事件将被透传。

<!--RP75--><!--RP75End-->

**权限级别**: system_basic

**授权方式**: 系统授权（system_grant）

**支持设备**：PC/2in1

**起始版本**: 26.0.0

## ohos.permission.MANAGE_BLUETOOTH_ADVERTISER_NAME

允许应用自定义BLE广播名称。

<!--RP65--><!--RP65End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：General

**起始版本**：23

## ohos.permission.INPUT_DEVICE_CONFIGURATOR

允许应用绑定输入设备与显示屏幕。

获取该权限后，驱动应用可将通过USB或蓝牙连接的外部输入设备与指定屏幕绑定。

<!--RP66--><!--RP66End-->

**权限级别**: system_basic

**授权方式**: 系统授权（system_grant）

**支持设备**: PC/2in1

**起始版本**: 24

## ohos.permission.REGISTER_OBJECTEDITOR_EXTENSION

允许应用注册ObjectEditorExtensionAbility组件。

获取该权限后，应用可以提供嵌入内容编辑服务给其他应用使用。

<!--RP67--><!--RP67End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：24

## ohos.permission.ALLOW_ACCESSORY_ACCESS

允许应用使用配件接入服务完成配件关联和自动唤醒等功能。

<!--RP70--><!--RP70End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | PC/2in1 | Tablet | Car

**起始版本**：26.0.0

## ohos.permission.CHECK_CALL_LOG

允许应用根据特定条件(手机号码、通话时长)，查询指定时间内系统是否存在匹配的通话记录。

<!--RP71--><!--RP71End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：General

**起始版本**：24

## ohos.permission.GET_NETWORK_STATS

允许应用查询其他应用的流量数据。

<!--RP81--><!--RP81End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：General

**起始版本**：10

**变更信息**：API 10-11，ACL使能为false；从API 12开始，变更为true。对于API版本10-24，权限的开放范围为系统应用；从API版本26.0.0开始，开放范围变更为普通应用。

## ohos.permission.ACCESS_DLP_SERVICE

允许应用或服务使用DLP提供的注册、解注册连云插件功能。

<!--RP74--><!--RP74End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | PC/2in1 | Tablet | TV

**起始版本**：26.0.0

## ohos.permission.CONTROL_DEVICE

允许应用注入输入事件以控制本设备。

<!--RP79--><!--RP79End-->

**权限级别**：system_basic

**授权方式**：手动设置授权（manual_settings）

**支持设备**：PC/2in1

**起始版本**：26.0.0

## ohos.permission.KEEP_BACKGROUND_RUNNING_SPECIAL_SCENARIO

允许应用申请特殊类型长时任务。

<!--RP76--><!--RP76End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：24

## ohos.permission.FLOAT_VIEW

允许应用使用闪控窗。

<!--RP78--><!--RP78End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：26.0.0

## ohos.permission.GET_CALL_TRANSFER_INFO

允许应用查询呼叫转移状态。

<!--RP80--><!--RP80End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：26.0.0

## ohos.permission.MANAGE_SKILL
    
允许应用使用skill的能力。

获取该权限后，应用可以：

- 查询skill包的信息
- 监听skill包的安装、更新、卸载事件
- 访问skill包安装的沙箱目录

<!--RP87--><!--RP87End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：PC/2in1

**起始版本**：26.0.0

## ohos.permission.kernel.AS_LDK_DRIVER

允许应用安装PCIe驱动。

<!--RP77--><!--RP77End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：PC/2in1

**起始版本**：26.0.0

## ohos.permission.KNOCK_COLLABORATION

允许应用通过碰一碰的形式连接指定设备并实现信息交互和应用互动。

<!--RP88--><!--RP88End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone

**起始版本**：26.0.0

## ohos.permission.PRINTER_DRIVER

允许应用管理打印系统。

<!--RP89--><!--RP89End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：PC/2in1 | Phone | Tablet

**起始版本**：24

## ohos.permission.kernel.SUPPORT_LOCAL_PLUGIN

允许应用安装与加载自分发插件。

<!--RP90--><!--RP90End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：PC/2in1

**起始版本**：26.0.0

## ohos.permission.ALLOW_USE_BM

允许应用在开发者模式下调用BM工具。

<!--RP94--><!--RP94End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：PC/2in1

**起始版本**：26.0.0

## ohos.permission.ACCESS_DIGITAL_IDENTITY

允许应用使用数字身份服务导入数字凭证。

获取该权限后，应用可以将用户的数字身份凭证导入设备，进行安全存储以及后续便捷出示。

<!--RP91--><!--RP91End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | Tablet

**起始版本**：26.0.0

## ohos.permission.CAPTURE_PLAYBACK_DOWNLINK

允许应用录制蜂窝通话下行数据。

<!--RP95--><!--RP95End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | Tablet

**起始版本**：26.0.0

## ohos.permission.MANAGE_SANDBOX_BUNDLE

允许应用管理沙箱应用。

<!--RP97--><!--RP97End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：PC/2in1

**起始版本**：26.0.0

## ohos.permission.DETECT_DEVICE

允许应用调用智能检测服务获取数据。

<!--RP98--><!--RP98End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：26.0.0

## ohos.permission.ACCESS_SE_KEY

允许应用生成、使用、删除安全芯片密钥。

<!--RP100--><!--RP100End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | Wearable | TV | PC/2in1 | Tablet | Car

**起始版本**：26.0.0
