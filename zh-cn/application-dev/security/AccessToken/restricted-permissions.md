# 受限开放权限

## 申请方式

<!--RP1-->

以下权限的开放范围为普通应用，但需要通过[访问控制列表（ACL）](app-permission-mgmt-overview.md#权限机制中的基本概念)的方式跨级别申请。

normal等级的应用需要将自身的APL等级声明为system_basic及以上，在开发应用安装包时，需要修改应用的HarmonyAppProvision配置文件即SDK目录下的“`Toolchains / _{Version} _/ lib / UnsgnedReleasedProfileTemplate.json`”文件，并重新进行应用签名。

**修改方式：**

HarmonyAppProvision配置文件示例如下所示，修改"bundle-info" &gt; "apl" 字段。

```json
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

允许读取用户公共目录的图片或视频文件。

<!--RP27--><!--RP27End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：9

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

<!--RP15-->
当前仅2in1设备和平板上的应用可申请此权限。
<!--RP15End-->

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

**起始版本**：11

## ohos.permission.FILE_ACCESS_PERSIST

允许应用支持持久化访问文件Uri。

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

**起始版本**：11

**变更信息**：API 11，权限等级为system_core；从API 12开始，权限等级变更为system_basic，向普通应用开放。

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

**授权方式**：用户授权（user_grant）

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

应用申请此权限后，系统引擎可申请带MAP_FORT的匿名可执行内存，做即时编译，提高与形式执行效率。

<!--RP13--><!--RP13End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：14

## ohos.permission.MANAGE_PASTEBOARD_APP_SHARE_OPTION

允许应用设置或移除剪贴板数据的可粘贴范围。

<!--RP16--><!--RP16End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

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

**起始版本**：15

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

**起始版本**：15

## ohos.permission.START_PROVISIONING_MESSAGE

允许应用启动设备管理业务部署流程，将该应用激活为个人设备管理应用。

<!--RP8--><!--RP8End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

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

允许应用固化对端蓝牙设备MAC对应的虚拟随机地址。

通过BLE扫描、BR扫描或连接监听获取到对端蓝牙设备MAC对应的虚拟随机地址，申请该权限后，可保持该虚拟随机地址长时间保持，即使是开/关/重启蓝牙也不发生变化。

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

**起始版本**：18

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

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**ACL使能**：true

**携带额外数据**：是，配置方法请见[Driver Development Kit开发指导](../../device/driver/externaldevice-guidelines.md#应用签名)。

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

## ohos.permission.MANAGE_SCREEN_TIME_GUARD

允许应用调用屏幕时间守护相关接口，进行屏幕使用限制、应用访问控制、管控使用时间等操作。

<!--RP40--><!--RP40End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：20

## ohos.permission.CUSTOMIZE_SAVE_BUTTON

允许应用自定义保存控件的图标和文本。

<!--RP41--><!--RP41End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：General

**起始版本**：20

## ohos.permission.GET_ABILITY_INFO

允许应用根据URI查询Ability信息。

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

允许应用使用全局闪控球的能力。

<!--RP46--><!--RP46End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | Tablet

**起始版本**：20

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

**权限级别**: system_basic

**授权方式**: 系统授权（system_grant）

**支持设备**:  Phone | PC/2in1 | Tablet

**起始版本**: 20

<!--Del-->
## ohos.permission.atomicService.MANAGE_STORAGE

允许原子化服务申请差异化的存储空间大小。

**权限级别**: system_basic

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