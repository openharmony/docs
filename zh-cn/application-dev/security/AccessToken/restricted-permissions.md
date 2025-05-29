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

## 权限列表

### ohos.permission.SYSTEM_FLOAT_WINDOW

允许应用使用悬浮窗的能力。

如果应用需要使用悬浮窗显示（即保持窗口悬浮在最顶层，不被遮挡），则需要申请该权限。

<!--RP25--><!--RP25End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：7

### ohos.permission.READ_CONTACTS

允许应用读取联系人数据。

<!--RP33--><!--RP33End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：8

### ohos.permission.WRITE_CONTACTS

允许应用添加、移除或更改联系人数据。

<!--RP34--><!--RP34End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：8

### ohos.permission.READ_AUDIO

允许读取用户公共目录的音频文件。

<!--RP26--><!--RP26End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：9

### ohos.permission.WRITE_AUDIO

允许修改用户公共目录的音频文件。

<!--RP28--><!--RP28End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：9

### ohos.permission.READ_IMAGEVIDEO

允许读取用户公共目录的图片或视频文件。

<!--RP27--><!--RP27End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：9

### ohos.permission.WRITE_IMAGEVIDEO

允许修改用户公共目录的图片或视频文件。

<!--RP29--><!--RP29End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：9

<!--Del-->
### ohos.permission.WRITE_DOCUMENT

允许修改用户公共目录的文档。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：9

**废弃版本**：12

**替代方案**：

请参考[文件权限组废弃替代方案](app-permission-group-list.md#文件deprecated)。

### ohos.permission.READ_DOCUMENT

允许读取用户公共目录的文档。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：9

**废弃版本**：12

**替代方案**：

请参考[文件权限组废弃替代方案](app-permission-group-list.md#文件deprecated)。
<!--DelEnd-->

### ohos.permission.READ_WRITE_DESKTOP_DIRECTORY

允许应用访问公共目录下Desktop目录及子目录。

当前仅2in1设备和平板上的应用可申请此权限。

<!--RP15-->
当前仅2in1设备应用可申请此权限。
<!--RP15End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**变更信息**:从PKI网站同步过来，按照PKI网站权限内容进行修正

**起始版本**：11

### ohos.permission.ACCESS_DDK_USB

允许扩展外设驱动访问USB DDK接口开发USB总线扩展外设驱动。

允许扩展外设驱动访问USB DDK接口访问扩展外设，使能USB总线类扩展外设增强能力。

<!--RP31--><!--RP31End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：11

### ohos.permission.ACCESS_DDK_HID

允许扩展外设驱动访问HID DDK接口开发HID类扩展外设驱动。

允许扩展外设驱动访问HID DDK接口访问扩展外设，使能HID类扩展外设增强能力。

<!--RP30--><!--RP30End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：11

### ohos.permission.READ_PASTEBOARD

允许应用读取剪贴板。

1. 银行卡号复制：银行类应用需要读取剪贴板中的银行卡号自动生成卡片。
2. 口令复制：应用需要读取剪贴板中特定格式口令，自动打开应用内对应页面。
3. 文档编辑类应用。
4. 输入法：系统级输入法需要读取剪贴板信息实现自动填充。应用内置输入法不能申请此权限。
5. 由于使用开源框架，需要使用剪切板权限而不能使用控件。

<!--RP32--><!--RP32End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：11

### ohos.permission.FILE_ACCESS_PERSIST

允许应用支持持久化访问文件Uri。

PC场景下,对于获取到Uri临时授权的应用,支持对其持久化授权。

<!--RP18--><!--RP18End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：11

**变更信息：** 从PKI网站同步过来，按照PKI网站权限内容进行修正

### ohos.permission.INTERCEPT_INPUT_EVENT

允许应用拦截输入事件。

可申请此权限的特殊场景与功能：应用为云桌面或是远程登录客户端，需要在本地设备显示远端服务端的云电脑，或是显示远程电脑的画面。 除上述场景外，应用不能申请此权限。

<!--RP24--><!--RP24End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：11

**变更信息**：权限级别在API 11为system_core；从API version 12开始为system_basic。

### ohos.permission.INPUT_MONITORING

允许应用监听输入事件。

可申请此权限的特殊场景与功能：应用需要录屏，且录屏过程中有显示键盘按键事件，或是显示鼠标指针效果/触摸效果的功能；应用需要共享桌面。除上述场景外，应用不能申请此权限。

<!--RP23--><!--RP23End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：7

**变更信息**：权限级别在API 11为system_core；从API version 12开始为system_basic。

### ohos.permission.SHORT_TERM_WRITE_IMAGEVIDEO

允许应用保存图片、视频到用户公共目录。应用获取此权限后，最长可获得30分钟的短时授权，来保存图片/视频。

可申请此权限的特殊场景与功能： 
1. 应用无法使用安全保存控件，例如H5网页应用等。
2. 存在连续多次保存图片/视频的场景，无法使用保存确认弹框，一次保存多个图片/视频。

<!--RP21--><!--RP21End-->

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：12

### ohos.permission.READ_WRITE_USER_FILE

允许应用访问并修改用户目录下的文件。

<!--RP19-->
当前仅2in1设备应用可申请此权限。
<!--RP19End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：13

### ohos.permission.READ_WRITE_USB_DEV

允许应用连接设备，并通过USB调试读写该设备。

<!--RP20-->
当前仅2in1设备应用可申请此权限。
<!--RP20End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：13

### ohos.permission.GET_WIFI_PEERS_MAC

允许应用获取对端Wi-Fi设备的MAC地址。

在获取Wi-Fi扫描结果时，如果需要获取对端设备的MAC地址，则需要申请该权限。

<!--RP14--><!--RP14End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：8

**变更信息**：API 8-13，权限等级为system_core；从API 14开始，权限等级变更为system_basic。

### ohos.permission.kernel.DISABLE_CODE_MEMORY_PROTECTION

允许应用禁用本应用的代码运行时完整性保护。

<!--RP11-->
针对使用跨平台框架开发的应用，用于应用豁免代码运行时完整性保护。
<!--RP11End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：14

### ohos.permission.kernel.ALLOW_WRITABLE_CODE_MEMORY

允许应用申请可写可执行匿名内存。

<!--RP10-->
针对使用跨平台框架开发的应用，用于应用申请可写可执行的匿名内存。
<!--RP10End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：14

### ohos.permission.kernel.ALLOW_EXECUTABLE_FORT_MEMORY

允许系统JS引擎申请带MAP_FORT标识的匿名可执行内存。

应用申请此权限后，系统引擎可申请带MAP_FORT的匿名可执行内存，做即时编译，提高运行时执行效率。

<!--RP13--><!--RP13End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：14

### ohos.permission.MANAGE_PASTEBOARD_APP_SHARE_OPTION

允许应用管理本应用剪贴板数据的可粘贴范围。

即本应用剪贴板数据可否粘贴到其他应用或其他设备。

<!--RP16--><!--RP16End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：14

### ohos.permission.MANAGE_UDMF_APP_SHARE_OPTION

允许应用设置或移除其使用UDMF支持的数据分享范围。

<!--RP17--><!--RP17End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：14

### ohos.permission.ACCESS_DISK_PHY_INFO

允许应用获取硬盘的硬件信息。

仅面向金融证券类应用开放，用于证券、股票交易。

<!--RP3--><!--RP3End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：15

### ohos.permission.PRELOAD_FILE

允许应用预加载文件以提升文件打开速度。

仅当应用为文档编辑类应用可申请此权限。

<!--RP9--><!--RP9End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：15

### ohos.permission.SET_PAC_URL

允许应用设置代理自动配置脚本地址。

应用完成脚本地址配置后，其他应用可读取此脚本并进行解析，根据解析结果决定是否使用代理。

<!--RP4--><!--RP4End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：15

### ohos.permission.PERSONAL_MANAGE_RESTRICTIONS

允许设备管理应用管理个人设备限制策略。

<!--RP7--><!--RP7End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：15

### ohos.permission.START_PROVISIONING_MESSAGE

允许应用启动设备管理业务部署流程，将该应用激活为个人设备管理应用。

<!--RP8--><!--RP8End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：15

### ohos.permission.USE_FRAUD_CALL_LOG_PICKER

允许应用使用诈骗通话记录选择器，获取通话记录内容。

当前仅白名单内应用可申请此权限。

<!--RP5--><!--RP5End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：15

### ohos.permission.USE_FRAUD_MESSAGES_PICKER

允许应用使用诈骗短信选择器，获取短信内容。

当前仅白名单内应用可申请此权限。

<!--RP6--><!--RP6End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：15

### ohos.permission.PERSISTENT_BLUETOOTH_PEERS_MAC

允许应用固化对端蓝牙设备MAC对应的虚拟随机地址。

通过BLE扫描、BR扫描或连接监听获取到对端蓝牙设备MAC对应的虚拟随机地址，申请该权限后，可保持该虚拟随机地址长时间保持，即使是开/关/重启蓝牙也不发生变化。

<!--RP36--><!--RP36End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：16

### ohos.permission.ACCESS_VIRTUAL_SCREEN

允许应用管控虚拟屏。

获得该权限的应用可以调用虚拟屏相关接口管理虚拟屏，包括创建虚拟屏，使虚拟屏，销毁虚拟屏等。

<!--RP37--><!--RP37End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：18

### ohos.permission.MANAGE_APN_SETTING

允许应用读取或设置APN信息。

当应用需要使用专网APN信息时可申请此权限。

<!--RP38--><!--RP38End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：16

### ohos.permission.GET_WIFI_LOCAL_MAC

允许应用获取本机的Wi-Fi设备的MAC地址。

可申请此权限的特殊场景和功能：
- 证券交易：应用内需进行股票、期货、债券交易等。
- 网银交易及身份认证：应用内提供网上银行服务，或是需要为网银用户完成身份认证、签名验签等。
- 应用需在PC/2in1设备上运行。

<!--RP43--><!--RP43End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：8

**变更信息**：API 8-15该权限仅向系统应用开放；从API 16开始，在PC/2in1设备上面向普通应用开放，在其余设备上仍仅面向系统应用开放。

### ohos.permission.kernel.ALLOW_USE_JITFORT_INTERFACE

允许应用调用JITFort接口更新MAP_FORT内存的内容。

可申请此权限的特殊场景与功能：应用使用自己的脚本引擎，且需要开启即时编译优化性能。

<!--RP12--><!--RP12End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：16

### ohos.permission.kernel.DISABLE_GOTPLT_RO_PROTECTION

允许应用关闭进程内.got.plt段的只读保护。

可申请此权限的特殊场景与功能：应用功能所依赖的基础能力系统尚不支持，必须通过修改.got.plt表方式实现。在申请权限时需要明确说明系统不满足原因。

<!--RP22--><!--RP22End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：17

### ohos.permission.USE_FRAUD_APP_PICKER

允许应用使用诈骗应用选择器，获取应用信息。

当前仅白名单内应用可申请此权限。

<!--RP2--><!--RP2End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：18

### ohos.permission.kernel.SUPPORT_PLUGIN

允许主体应用安装插件。

申请权限的应用应当有对应的插件机制，确保可以使用对应的插件，并符合插件市场的管理规定。

<!--RP35--><!--RP35End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：19

### ohos.permission.CUSTOM_SANDBOX

允许应用将沙箱类型改为动态沙箱。

该权限面向华为内部开发工具应用开放，仅在允许名单内的固定应用可申请该权限，如需进入允许名单，请联系企业技术支持。

<!--RP39--><!--RP39End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：18

### ohos.permission.MANAGE_SCREEN_TIME_GUARD

允许应用调用屏幕时间守护相关接口，进行屏幕使用限制、应用访问控制、管控使用时间等操作。

可申请此权限的特殊场景与功能：仅面向企业类应用开放，应用类型属于时间、效率、习惯、教育、亲子相关类目，使用场景需围绕管理个人、亲友的用机时间管理。

<!--RP40--><!--RP40End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**起始版本**：20

### ohos.permission.CUSTOMIZE_SAVE_BUTTON

允许应用自定义保存控件的图标和文本。

可申请此权限的特殊场景与功能：使用保存控件提供的默认样式无法满足业务场景，应用需要自定义保存控件的图标和文本。

<!--RP41--><!--RP41End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**：Phone | PC/2in1 | Tablet

**起始版本**：20

### ohos.permission.GET_ABILITY_INFO

允许应用根据URI查询Ability信息。

当前仅PC/2in1上的浏览器类应用可申请此权限。

<!--RP42--><!--RP42End-->

**权限级别**：system_basic

**授权方式**：系统授权（system_grant）

**支持设备**: PC/2in1

**起始版本**：20