# Samples

为了方便开发者快速学习与了解、针对重点特性或功能进行开发，本页面对当前OpenHarmony所有的[Samples](https://gitee.com/openharmony/applications_app_samples)资源汇总，如下所示：



## UI

### 声明式开发范式

#### ArkUI组件集合

本示例为ArkUI中组件、通用、动画、全局方法的集合。示例使用 [Tabs容器组件](reference/arkui-ts/ts-container-tabs.md) 搭建整体应用框架，每个 [TabContent内容视图](reference/arkui-ts/ts-container-tabcontent.md) 使用 [List容器组件](reference/arkui-ts/ts-container-list.md) 布局，在每个 [ListItem](reference/arkui-ts/ts-container-listitem.md) 中使用 [循环渲染](quick-start/arkts-rendering-control-foreach.md) 加载此分类下分类导航数据，底部导航菜单使用 [TabContent中tabBar属性](reference/arkui-ts/ts-container-tabcontent.md#属性) 设置自定义样式 。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.1

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/UI/ArkTsComponentCollection/ComponentCollection)

#### 横竖屏切换

本示例展示如何使用媒体查询，通过[@ohos.mediaquery](reference/apis/js-apis-mediaquery.md) 接口完成在不同设备上显示不同的界面效果。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/UI/ArkTsComponentCollection/MediaQuery)

#### 状态管理

本示例通过使用[页面级的状态变量](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Fquick-start%2Farkts-localstorage.md%2F) 和[应用级的状态变量](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Fquick-start%2Farkts-appstorage.md%2F) 来实现应用的状态管理。展示内容包括修饰的对象类型、父子组件之间的状态同步、爷孙组件之间的状态同步以及兄弟组件之间的状态同步。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：4.0.5.2

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/UI/ArkTsComponentCollection/StateManagement)

#### 页面布局和连接

本示例构建食物分类列表页面和食物详情页，包含：

1.[List](reference/arkui-ts/ts-container-list.md)布局：创建食物数据模型，ForEach循环渲染ListItem。

2.[Grid](reference/arkui-ts/ts-container-grid.md)布局：展示食物分类信息，创建Tabs页签展示不同分类的食物。

3.路由机制：[@ohos.router](reference/apis/js-apis-router.md)接口、[Navigator](reference/arkui-ts/ts-container-navigator.md)和页面间数据传递。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/UI/ArkTsComponentCollection/DefiningPageLayoutAndConnection)

### 类Web开发范式

#### JS组件集合

本示例为ArkUI中组件、通用、动画、全局方法的集合。示例使用 [Tabs容器组件](reference/arkui-js/js-components-container-tabs.md)搭建整体应用框架，每个 [TabContent内容视图](reference/arkui-js/js-components-container-tab-content.md) 使用 [div容器组件](reference/arkui-js/js-components-container-div.md) 嵌套布局，在每个 [div](reference/arkui-js/js-components-container-div.md) 中使用 [循环渲染](reference/arkui-js/js-components-common-attributes.md) 加载此分类下分类导航数据，底部导航菜单使用 [TabContent中tabBar属性](reference/arkui-js/js-components-container-tab-content.md) 设置自定义样式 。通过组件、通用、动画、全局方法四个大类展现了ArkUI的能力，并把四大类中的功能进行了分类，方便开发者查看，每个示例又结合了不同的展现方式，以契合实际应用场景为主生动的体现了ArkUI能力的用法。

开发语言：JS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/UI/JsComponentCollection/JsComponentCollection)



## 基础特性

### 应用模型

#### Ability的启动模式

本示例展示了在一个Stage模型中，实现multiton、singleton、specified多种模式场景。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/ApplicationModels/AbilityStartMode)

#### 自定义分享

自定义分享主要是发送方将文本，链接，图片三种类型分享给三方应用,同时能够在三方应用中展示。本示例使用[数据请求](reference/apis/js-apis-http.md) 实现网络资源的获取，使用[屏幕截屏](reference/apis/js-apis-screenshot.md) 实现屏幕的截取，使用[文件管理](reference/apis/js-apis-fileio.md) 实现对文件，文件目录的管理，使用[媒体库管理](reference/apis/js-apis-medialibrary.md) 获取截取的图片，使用[弹窗](reference/apis/js-apis-promptAction.md) 进行信息的提示。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.1

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/ApplicationModels/CustomShare)

#### Stage模型

[Stage模型](reference/apis/js-apis-app-ability-abilityStage.md) 的设计，主要是为了解决FA模型无法解决的开发场景问题，基于应用的能力与系统总体功能和功耗的平衡、原生支持组件级的迁移和协同、支持多设备和多窗口形态的特点这三个出发点，从而让开发者更加方便地开发出分布式环境下的复杂应用。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/ApplicationModels/StageModel)

### 网络与连接

#### 蓝牙

本示例通过使用蓝牙低功耗心率服务，结合[bluetooth](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Fapis%2Fjs-apis-bluetooth.md%2F) 来接收BLE心率设备发送的心率数据，并使用画布[Canvas](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Farkui-ts%2Fts-components-canvas-canvas.md%2F) 来绘制实时心率图来展示蓝牙相关API用法。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.1

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Bluetooth)

#### Http

本示例通过[@ohos.net.http](reference/apis/js-apis-http.md) 等接口，实现了根据URL地址和相关配置项发起http请求的功能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Http)

#### RPC连接

本示例使用[@ohos.rpc](reference/apis/js-apis-rpc.md) 相关接口，实现了一个前台选择商品和数目，后台计算总价的功能，使用rpc进行前台和后台的通信。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/RPC)

#### 网络管理-Socket连接（UDP）

本示例主要使用面向非连接的协议UDP Socket，展示Socket在两端设备的连接验证、聊天通信方面的应用。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Socket)

#### 网络管理-Socket连接

本示例主要设计三种协议方式：UDP Socket、TCP Socket以及TLS Socket，展示在使用不同协议时，Socket在两端设备的连接验证、聊天通信方面的应用。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.10

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/StageSocket)

#### 上传和下载

本示例使用[@ohos.request](reference/apis/js-apis-request.md)接口创建上传和下载任务，实现上传、下载功能，hfs作为服务器，实现了文件的上传和下载和任务的查询功能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.8.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/UploadAndDownLoad)

#### WebSocket

本示例展示了[WebSocket]([@ohos.net.webSocket](reference/apis/js-apis-webSocket.md))的使用，包括客户端与服务端的连接和断开以及客户端数据的接收和发送。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.1

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/WebSocket)

### DFX

#### 应用故障恢复

本示例展示了在应用中如何适配故障恢复相关接口。示例包括一下场景：单Ability自动恢复、多Ability自动恢复、多Ability主动恢复、Ability后台强制终止恢复。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.8.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DFX/AppRecovery)

#### Debug

本示例通过使用[@ohos.hidebug](reference/apis/js-apis-hidebug.md) 接口来获取应用进程实际使用的物理内存大小、进程的共享脏内存大小、进程的私有脏内存大小等内存使用情况。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DFX/Debug)

#### 测试打点

本示例展示了在eTS中如何获取应用故障相关信息，测试打点包括应用打点与性能打点两部分，应用打点通过调用[@ohos.hiAppEvent](reference/apis/js-apis-hiappevent.md)接口来记录应用运行过程中发生的各种信息。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DFX/DotTest)

#### 故障日志获取

本示例使用了[@ohos.faultLogger](reference/apis/js-apis-faultLogger.md)接口，展示在eTS中如何获取js_crash故障、cpp_crash故障、freeze_crash故障等不同场景下应用故障相关信息。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DFX/FaultLogger)

#### 日志打印

本示例使用[hilog日志系统](reference/apis/js-apis-hilog.md) ，提供日志打印类，使应用/服务可以按照指定级别、标识和格式字符串输出日志内容，帮助开发者了解应用/服务的运行状态，更好地调试程序。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DFX/Logger)

### 数据管理

#### 首选项

本示例使用[@ohos.data.preferences](reference/apis/js-apis-data-preferences.md) 接口，展示了使用首选项持久化存储数据的功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DataManagement/Preferences)

### 设备管理

#### 设备管理合集（非系统特性）

本示例集合设备管理相关（非系统特性）不需要复杂功能展示的模块，展示了各个模块的基础功能，包含：

- [@ohos.batteryInfo (电量信息)](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Fapis%2Fjs-apis-battery-info.md%2F)
- [@ohos.charger (充电类型)](reference/apis/js-apis-charger.md)
- [@ohos.deviceInfo (设备信息)](reference/apis/js-apis-device-info.md)
- [@ohos.power (系统电源管理)](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Fapis%2Fjs-apis-power.md%2F)
- [@ohos.runningLock (Runninglock锁)](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Fapis%2Fjs-apis-runninglock.md%2F)
- [@ohos.settings (设置数据项名称)](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Fapis%2Fjs-apis-settings.md%2F)
- [@ohos.stationary (设备状态感知框架)](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Fapis%2Fjs-apis-stationary.md%2F)
- [@ohos.thermal (热管理)](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Fapis%2Fjs-apis-thermal.md%2F)
- [@ohos.usbManager (USB管理)](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Fapis%2Fjs-apis-usbManager.md%2F)
- [@ohos.multimodalInput.inputConsumer (组合按键)](reference/apis/js-apis-inputconsumer.md)
- [@ohos.multimodalInput.inputDevice (输入设备)](reference/apis/js-apis-inputdevice.md)
- [@ohos.multimodalInput.inputEvent (输入事件)](reference/apis/js-apis-inputevent.md)
- [@ohos.multimodalInput.inputEventClient (按键注入)](reference/apis/js-apis-inputeventclient.md)
- [@ohos.multimodalInput.inputMonitor (输入监听)](reference/apis/js-apis-inputmonitor.md)
- [@ohos.multimodalInput.keyCode (键值)](reference/apis/js-apis-keycode.md)
- [@ohos.multimodalInput.keyEvent (按键输入事件)](reference/apis/js-apis-keyevent.md)
- [@ohos.multimodalInput.mouseEvent (鼠标输入事件)](reference/apis/js-apis-mouseevent.md)
- [@ohos.multimodalInput.pointer (鼠标指针)](reference/apis/js-apis-pointer.md)
- [@ohos.multimodalInput.touchEvent (触摸输入事件)](reference/apis/js-apis-touchevent.md)

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/DeviceManagementCollection)

#### 位置信息

本示例使用 [geolocation](reference/apis/js-apis-geolocation.md) 实现获取当前位置的经纬度，然后通过 [http](reference/apis/js-apis-http.md) 将经纬度作为请求参数，获取到该经纬度所在的城市。通过 [AlphabetIndexer](reference/arkui-ts/ts-container-alphabet-indexer.md) 容器组件实现按逻辑结构快速定位容器显示区域。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/Location)

#### 屏幕探测

本示例实时监测连接的屏幕数量状态，支持创建至多5个虚拟屏幕，点击对应的屏幕矩形能显示该屏幕的相关属性。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/ScreenDetector)

#### 振动

本示例模拟倒计时场景，通过[@ohos.vibrator](reference/apis/js-apis-vibrator.md) 等接口来实现振动。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/Vibrator/BasicVibration)

#### 自定义振动

本示例使用[Vibrator模块](reference/apis/js-apis-vibrator.md)展示了振感定制化的基本功能，包括振感与音效、视频协同振动等。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.7

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/Vibrator/CustomHaptic)

### 设备信息统计

#### 设备使用信息统计

本示例使用[bundleState](reference/apis/js-apis-deviceUsageStatistics.md)相关接口完成设备中应用时长的统计功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceUsageStatistics/DeviceUsageStatistics)

### 文件管理

#### 应用接入数据备份恢复

本示例主要给备份流程提供应用，用于生成数据和显示数据。应用接入数据备份恢复需要通过配置BackupExtensionAbility实现。BackupExtensionAbility，是[Stage模型](application-models/stage-model-development-overview.md)中扩展组件[ExtensionAbility](application-models/extensionability-overview.md)的派生类。开发者可以通过修改配置文件定制备份恢复框架的行为，包括是否允许备份恢复，备份哪些文件等。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.8.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/FileManagement/FileBackupExtension)

#### 文件管理

本示例主要展示了文件管理相关的功能，使用[@ohos.multimedia.medialibrary](reference/apis/js-apis-medialibrary.md) 、[@ohos.filemanagement.userFileManager](reference/apis/js-apis-userFileManager.md) 、[@ohos.fileio](reference/apis/js-apis-fileio.md) 、[@ohos.file.fs](reference/apis/js-apis-file-fs.md)

等接口，实现了增添文件、删除文件、查找指定类型文件文件、复制并移动文件和预览图片、监听文件的功能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/FileManagement/FileManager)

#### 选择并查看文档与媒体文件

应用使用[@ohos.file.picker](reference/apis/js-apis-file-picker.md)、[@ohos.multimedia.mediaLibrary](reference/apis/js-apis-medialibrary.md)、[@ohos.file.fs](reference/apis/js-apis-file-fs.md) 等接口，实现了picker拉起文档编辑保存、拉起系统相册图片查看、拉起视频并播放的功能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.7

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/FileManagement/FileShare/Picker)

#### 为应用之间分享和文件访问提供统一的入口能力

本示例主要展示了沙箱文件分享相关的功能，使用 [@ohos.file.fileuri](reference/apis/js-apis-file-fileuri.md) 、[@ohos.file.fs](reference/apis/js-apis-file-fs.md)、[@ohos.ability.wantConstant](reference/apis/js-apis-ability-wantConstant.md)、[@ohos.application.Want](reference/apis/js-apis-app-ability-want.md) 等接口，实现了获取文件uri、创建沙箱文件、提供want中操作want常数和解释Flags说、应用组件间的信息传递的功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.2

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/FileManagement/FileShare/SandboxShare)

#### 媒体管理合集

本示例主要展示网络流播放能力、音视频播控能力、音量调节能力。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/FileManagement/MediaCollections)

#### 相册

本示例主要展示了相册相关的功能，使用[@ohos.file.photoAccessHelper](reference/apis/js-apis-photoAccessHelper.md) 接口，实现了查看系统相册、创建用户相册、查看相册照片、用户相册文件添加和删除、以及预览图片、最近删除、收藏夹操作等功能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.1

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/FileManagement/Photos)

### IDL

#### Ability与ServiceExtensionAbility通信

本示例展示通过[IDL的方式](IDL/idl-guidelines.md#ts开发步骤) 和 [@ohos.rpc](reference/apis/js-apis-rpc.md) 等接口实现了Ability与ServiceExtensionAbility之间的通信。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/IDL/AbilityConnectServiceExtension)

### 国际化

#### 国际化

本示例主要展示了国际化模块的相关功能，使用[@ohos.i18n](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Finternationalization%2Fi18n-guidelines.md%2F) 接口，实现简单日历展示、字符类型判断、文本断点处理功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.10

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/International/International)

### 媒体

#### 音视频录制

本示例主要使用@ohos.multimedia.media中的AVRecorder接口实现了录制功能；另外辅助使用@ohos.multimedia.medialibrary接口，实现了创建录制文件功能，接口使用以及权限获取详见[媒体库管理](reference/apis/js-apis-medialibrary.md)。使用@ohos.multimedia.camera接口，实现了相机预览及出流功能，接口使用以及权限获取详见[相机管理](reference/apis/js-apis-camera.md)。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.10.8

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVRecorder)

#### 媒体会话——控制方（仅对系统应用开放）

本示例主要展示了媒体会话（媒体控制方）的相关功能，使用[@ohos.multimedia.avsession](reference/apis/js-apis-avsession.md)等接口实现媒体提供方与媒体控制方自定义信息的交互功能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVSession/MediaController)

#### 媒体会话——提供方

本示例主要展示了媒体会话（媒体提供方）的相关功能，使用[@ohos.multimedia.avsession](reference/apis/js-apis-avsession.md)等接口实现媒体提供方与媒体控制方自定义信息的交互功能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVSession/MediaProvider)

#### 音频管理

本示例主要展示了音频的相关功能，使用[@ohos.multimedia.audio](reference/apis/js-apis-audio.md)等接口实现音频的发声设备的切换与查询、音频焦点、音效的查询与设置以及音频录制等功能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/Audio)

#### 拼图

该示例通过[@ohos.multimedia.image](reference/apis/js-apis-image.md)和[@ohos.multimedia.mediaLibrary](reference/apis/js-apis-medialibrary.md)接口实现获取图片，以及图片裁剪分割的功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/GamePuzzle)

#### 图片编辑

本示例使用 [TextArea](reference/arkui-ts/ts-basic-components-textarea.md) 实现多文本输入，使用 [@ohos.app.ability.common](reference/apis/js-apis-app-ability-common.md) 依赖系统的图库引用，实现在相册中获取图片，使用 [@ohos.multimedia.image](reference/apis/js-apis-image.md) 生成pixelMap，使用pixelMap的scale()，crop()，rotate()接口实现对图片的缩放，裁剪，旋转功能。 使用[@ohos.effectKit](reference/apis/js-apis-effectKit.md) 生成effectKit,使用effectKit.getHighestSaturationColor() 接口实现对图片的高亮调节。添加文字/贴纸，利用组件的组合编辑素材大小和位置，再使用OffscreenCanvasRenderingContext2D进行离屏绘制保存。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/Image)

#### 图片显示

本示例使用 [TextArea](reference/arkui-ts/ts-basic-components-textarea.md) 组件实现多文本输入，使用 [mediaLibrary](reference/apis/js-apis-mediaquery.md) 实现从相册选择图片展示在商品评价页面。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/ImageShow)

#### 二维码扫描

本示例使用[媒体库管理](reference/apis/js-apis-medialibrary.md)、[相机管理](reference/apis/js-apis-camera.md)、[图片处理](reference/apis/js-apis-image.md)、[文件管理](reference/apis/js-apis-fileio.md)展示二维码扫描功能，包括相机扫描解析二维码和从相册中选择二维码图片解析。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/QRCodeScan)

#### 录音机

本示例使用[audio](reference/apis/js-apis-audio.md)相关接口实现音频录制和播放的功能，使用[mediaLibrary](reference/apis/js-apis-medialibrary.md)实现音频文件的管理。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/Recorder)

#### 视频播放

视频播放的主要工作是将视频数据转码并输出到设备进行播放，同时管理播放任务。本文将对视频播放全流程、视频切换、视频循环播放等场景开发进行介绍说明。 本示例主要展示了播放本地视频和网络视频相关功能,使用 [@ohos.multimedia.media](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-media.md#bufferinginfotype8),[@ohos.resourceManager](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-resource-manager.md),[@ohos.wifiManager](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-wifiManager.md)等接口,实现了视频播放、暂停、调节倍速、切换视频的功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.10

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/VideoPlay)

#### 媒体库视频

本示例使用[Video组件](reference/arkui-ts/ts-media-components-video.md)展示了视频组件的基本功能，包括视频组件化，全屏化，窗口化，上下轮播视频等。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/VideoShow)

#### 音频通话示例

本示例主要展示了音频通话相关的功能，使用[@ohos.multimedia.audio](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Fapis%2Fjs-apis-audio.md%2F) 、[@ohos.net.socket](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Fapis%2Fjs-apis-socket.md%2F) 等接口，实现音频录制和渲染，音频数据网络传输等功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.10

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/VoiceCallDemo)

### Native

#### 获取Rawfile资源

本示例中主要介绍开发者如何使用Native Rawfile接口操作Rawfile目录和文件。功能包括文件列表遍历、文件打开、搜索、读取和关闭Rawfile。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkRawfile)

#### Native XComponent

本示例中主要介绍开发者如何使用Native XComponent接口来获取NativeWindow实例、获取布局/事件信息、注册事件回调并通过OpenGL/EGL实现在页面上绘制形状。功能主要包括点击按钮绘制一个五角星，并可以通过点击XComponent区域改变五角星的颜色。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.8.2

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkXComponent)

#### OpenGL三棱椎

本示例展示了XComponent相关控件的使用，及采用OpenGL (OpenGL ES)相关标准API绘制3D图形（三棱锥，3D渲染的光源用的是简单的线性光源）。此外，可在屏幕触摸滑动，以使三棱锥进行旋转，其中主要采用了napi接口来更新3D图形的旋转角度。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkOpenGL)

### 通知

#### 公共事件的订阅和发布

本示例主要展示了公共事件相关的功能，实现了一个检测用户部分行为的应用。具体而言实现了如下几点功能：

1.通过订阅系统公共事件，实现对用户操作行为（亮灭屏、锁屏和解锁屏幕、断联网）的监测；

2.通过在用户主动停止监测行为时发布自定义有序公共事件，实现对用户主动触发监听行为的持久化记录；

3.通过在用户设置对某一事件的监听状态时发布粘性事件，记录下本次应用运行期间允许监听的事件列表，同时在应用退出时将临时允许的修改为不允许。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Notification/CustomCommonEvent)

#### 自定义Emitter

本示例使用[Emitter](reference/apis/js-apis-emitter.md)实现事件的订阅和发布，使用[自定义弹窗](reference/arkui-ts/ts-methods-custom-dialog-box.md)设置广告信息。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Notification/CustomEmitter)

#### 自定义通知

本示例使用[@ohos.notificationManager](reference/apis/js-apis-notificationManager.md) 等接口，展示了如何初始化不同类型通知的通知内容以及通知的发布、取消及桌面角标的设置，通知类型包括基本类型、长文本类型、多行文本类型、图片类型、带按钮的通知、点击可跳转到应用的通知。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.7.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Notification/CustomNotification)

#### 自定义通知角标

本示例主要展示了设定应用的桌面图标角标的功能，使用[@ohos.notificationManager](reference/apis/js-apis-notificationManager.md) 接口，进行桌面角标的设置，通知的发送，获取等。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.7.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Notification/CustomNotificationBadge)

#### 自定义通知推送

本示例主要展示了通知过滤回调管理的功能，使用[@ohos.notificationManager](reference/apis/js-apis-notificationManager.md) 接口，进行通知监听回调，决定应用通知是否发送。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.7.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Notification/CustomNotificationPush)

### 资源

#### 资源管理器

本工程使用[@ohos.app.ability.common](reference/apis/js-apis-app-ability-common.md) 接口中的AbilityContext类，获取资源管理器resourceManager，使用[@ohos.resourceManager.d.ts](reference/apis/js-apis-resource-manager.md) 中的接口，展示了格式化字符串查询、基于指定屏幕分辨率查询媒体资源、获取系统资源管理对象等基础功能，以及展示了资源静态overlay以及运行时overlay的特性功能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Resource/ResourceManager)

### 安全

#### 应用帐号管理

本示例选择应用进行注册/登录，并设置帐号相关信息，简要说明应用帐号管理相关功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Security/AppAccountManager)

#### 证书算法库框架

本示例使用了[@ohos.security.cert](reference/apis/js-apis-cert.md)相关接口实现了对签名数据进行校验的功能。

实现场景如下：

1）使用**正确**的原始数据和签名数据进行签名校验场景：模拟服务端通过客户端证书获取公钥，利用公钥对签名数据进行校验，验证客户端身份和原始数据完整性。

2）使用**错误**的原始数据或签名数据进行签名校验场景：模拟攻击者修改原始数据或签名数据，服务端在利用公钥进行签名校验时，攻击者身份不可信或原始数据不完整，验证失败。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.2

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Security/CertificateFramework)

#### 加解密

本示例使用[cipher](reference/apis/js-apis-system-cipher.md)相关接口实现了字符串加解密算法，包括RSA加密算法与AES加密算法。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Security/Cipher)

#### 通用密钥库系统（cryptoFramework）

本示例使用[@ohos.security.cryptoFramework](reference/apis/js-apis-cryptoFramework.md) 相关接口实现了对文本文件的加解密、签名验签操作。

实现场景如下：

1）软件需要加密存储本地文本文件，需要调用加解密算法库框架选择密钥文本文件，对本地文本文件进行加密，其中密钥文本文件可由加解密算法库生成。

2）软件需要解密存储本地文本文件，需要调用加解密算法库框架选择密钥文本文件，对本地文本文件进行解密，其中密钥文本文件可由加解密算法库生成。

3）软件需要对存储本地文本文件签名，调用加解密算法库框架选择密钥文本文件，对本地文本文件进行完整性签名，其中密钥文本文件可由加解密算法库生成。

4）软件需要验证存储本地文本文件的签名完整性，需要调用加解密算法库框架选择密钥文本文件与签名文件，对文件进行验签，其中密钥文本文件可由加解密算法库生成。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.2

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Security/CryptoFramework)

#### 通用密钥库系统（huks）

本示例使用[@ohos.security.huks](reference/apis/js-apis-huks.md)相关接口实现了对任意输入内容进行加密和解密的功能。

实现场景如下：

1）使用新密钥进行消息加解密传输：使用HUKS的生成密钥接口在本地生成一个新密钥，模拟设备对发送的消息进行加密和对接收的消息进行解密场景。

2）使用旧密钥进行消息加解密传输：使用HUKS的导入密钥接口导入一个旧密钥，模拟在旧设备上对发送的消息进行加密，在新设备上对接收的消息进行解密的场景。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.1

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Security/Huks)

#### 支付

本示例主要展示了加解密算法库框架的相关功能，使用[@ohos.security.cryptoFramework](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Fapis%2Fjs-apis-cryptoFramework.md%2F) 接口，利用RSA非对称加密、ECC数字签名模拟选购支付功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.10

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Security/PaySecurely)

### 任务管理

#### 长时任务

本示例展示后台任务的长时任务。通过使用[@ohos.resourceschedule.backgroundTaskManager](reference/apis/js-apis-resourceschedule-backgroundTaskManager.md)实现后台播放音乐时避免进入挂起（Suspend）状态。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/TaskManagement/ContinuousTask)

#### 小鸟避障游戏

本示例使用[@ohos.app.ability.ServiceExtensionAbility](reference/apis/js-apis-app-ability-serviceExtensionAbility.md)的ServiceExtension接口验证提供的Stage模型， [Canvas组件](reference/arkui-ts/ts-components-canvas-canvas.md)绘制小游戏，[@ohos.resourceschedule.usageStatistics](reference/apis/js-apis-resourceschedule-deviceUsageStatistics.md)的queryBundleStatsInfos接口通过指定起始和结束时间查询应用使用时长统计信息来统计展示游戏在线时长，[@ohos.backgroundTaskManager](reference/apis/js-apis-backgroundTaskManager.md)的requestSuspendDelay接口申请后台应用延迟挂起来验证短时任务API能否正常执行，[@ohos.rpc](reference/apis/js-apis-rpc.md)提供进程间通信能力，[@ohos.wantAgent](reference/apis/js-apis-wantAgent.md)验证系统能力。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/TaskManagement/Flybird)

#### 后台代理提醒

本示例使用 [Tabs组件](reference/arkui-ts/ts-container-tabs.md) 进行应用布局，使用 [Canvas组件](reference/arkui-ts/ts-components-canvas-canvas.md) 绘制时钟、倒计时，使用 [后台代理提醒](reference/apis/js-apis-reminderAgentManager.md) 发布后台代理提醒，使用 [振动](reference/apis/js-apis-vibrator.md) 设置振动效果。保证应用被冻结或退出时，计时和弹出提醒的功能可以被后台系统服务代理。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/TaskManagement/ReminderAgentManager)

#### 短时任务

本示例主要展示后台任务中的短时任务。

通过[@ohos.resourceschedule.backgroundTaskManager](reference/apis/js-apis-resourceschedule-backgroundTaskManager.md) ，[@ohos.app.ability.quickFixManager](reference/apis/js-apis-app-ability-quickFixManager.md) 等接口实现应用热更新的方式去展现短时任务机制。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/TaskManagement/TransientTask)

#### 任务延时调度

本示例使用[@ohos.WorkSchedulerExtensionAbility](reference/apis/js-apis-WorkSchedulerExtensionAbility.md) 、[@ohos.net.http](reference/apis/js-apis-http.md) 、[@ohos.notification](reference/apis/js-apis-notification.md) 、[@ohos.bundle](reference/apis/js-apis-Bundle.md) 、[@ohos.fileio](reference/apis/js-apis-fileio.md) 等接口，实现了设置后台任务、下载更新包 、保存更新包、发送通知 、安装更新包实现升级的功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/TaskManagement/WorkScheduler)

### 电话服务

#### 拨打电话

本示例使用[call](reference/apis/js-apis-call.md)相关接口实现了拨打电话并显示电话相关信息的功能。主要展示拨打电话功能，dial方法拨打电话，可设置通话参数，hasCall方法判断是否存在通话，getCallState方法获取当前通话状态，isEmergencyPhoneNumber方法判断是否是紧急电话号码，formatPhoneNumber方法格式化电话号码，formatPhoneNumberToE164方法将电话号码格式化为E.164表示形式。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Telephony/Call)

#### 联系人

本示例使用[@ohos.contact](reference/apis/js-apis-contact.md) 接口，实现了对联系人的增删查改功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Telephony/Contact)

#### 短信服务

本示例使用[@ohos.telephony.sms](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Beta5/zh-cn/application-dev/reference/apis/js-apis-sms.md) 接口展示了电话服务中发送短信的功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Telephony/Message)

#### 蜂窝数据

本示例使用 [SystemCapability.Telephony.CellularData系统能力](reference/apis/js-apis-telephony-data.md) 获取SIM卡信息及网络信息。使用 [@Builder](quick-start/arkts-builder.md) 在一个自定义组件内快速生成多个布局内容。通过获取SIM卡相关信息，展示打开本应用时网络信息。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Telephony/MobileNetwork)

#### 事件订阅

本示例通过[@ohos.telephony.radio](reference/apis/js-apis-radio.md)，[@ohos.telephony.call](reference/apis/js-apis-call.md)，[@ohos.telephony.data](reference/apis/js-apis-telephony-data.md)，[@ohos.telephony.observer](reference/apis/js-apis-observer.md)订阅网络状态、信号状态、通话状态、蜂窝数据、sim状态等事件，并获取状态变化返回的结果。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Telephony/Observer)

#### 网络搜索

本示例通过[@ohos.telephony.sim](reference/apis/js-apis-sim.md) 、[@ohos.telephony.radio](reference/apis/js-apis-radio.md) 等接口来展示电话服务中网络搜索功能，包含无线接入技术、网络状态、选网模式、ISO国家码、信号强度信息列表及Radio是否打开。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Telephony/RadioTech)

#### SIM卡管理

本示例使用[sim](reference/apis/js-apis-sim.md)相关接口，展示了电话服务中SIM卡相关功能，包含SIM卡的服务提供商、ISO国家码、归属PLMN号信息，以及默认语音卡功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Telephony/SimManager)

### Web

#### 浏览器

本示例使用[@ohos.systemparameter](reference/apis/js-apis-system-parameter.md)接口和[Web组件](reference/arkui-ts/ts-basic-components-web.md)展示了一个浏览器的基本功能,展示网页，根据页面历史栈前进回退等。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Web/Browser)

#### JS注入与执行

本示例基于H5游戏，通过arkui的[Button](reference/arkui-ts/ts-basic-components-button.md)实现对游戏实现基本控制，展示[@ohos.web.webview](reference/apis/js-apis-webview.md)的JS注入与执行能力，及native应用与H5的通信能力。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Web/RunJsInWeb)

### 窗口管理

#### 窗口

本实例使用[窗口管理](reference/apis/js-apis-window.md)，展示了在应用主窗口中创建和拉起子窗口，并对子窗口设置窗口相关属性，以及设置窗口规避区域、窗口沉浸式和小窗口等功能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/WindowManagement/WindowManage)

#### 悬浮窗

本示例使用[@ohos.window](reference/apis/js-apis-window.md)，主要展示了在子窗口中以悬浮窗模式拉起悬浮应用，并对新的应用设置窗口缩放比例，窗口以设置的比例进行缩放，并在界面显示窗口当前的宽度和高度。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.8.2

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/WindowManagement/WindowRatio)



## 语言基础类库

#### 多线程任务

本示例通过[@ohos.taskpool](reference/apis/js-apis-taskpool.md) 和[@ohos.worker](reference/apis/js-apis-worker.md) 接口，展示了如何启动worker线程和taskpool线程。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.2

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/LaunguageBaseClassLibrary/ConcurrentModule)

#### 语言基础类库

本示例集合语言基础类库的各个子模块，展示了各个模块的基础功能，包含：

- [@ohos.buffer (Buffer)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-buffer.md)
- [@ohos.convertxml (xml转换JavaScript)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-convertxml.md)
- [@ohos.process (获取进程相关的信息)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-process.md)
- [@ohos.taskpool (启动任务池)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-taskpool.md)
- [@ohos.uri (URI字符串解析)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-uri.md)
- [@ohos.url (URL字符串解析)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-url.md)
- [@ohos.util (util工具函数)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-util.md)
- [@ohos.util.ArrayList (线性容器ArrayList)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-arraylist.md)
- [@ohos.util.Deque (线性容器Deque)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-deque.md)
- [@ohos.util.HashMap (非线性容器HashMap)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-hashmap.md)
- [@ohos.util.HashSet (非线性容器HashSet)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-hashset.md)
- [@ohos.util.LightWeightMap (非线性容器LightWeightMap)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-lightweightmap.md)
- [@ohos.util.LightWeightSet (非线性容器LightWeightSet)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-lightweightset.md)
- [@ohos.util.LinkedList (线性容器LinkedList)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-linkedlist.md)
- [@ohos.util.List (线性容器List)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-list.md)
- [@ohos.util.PlainArray (非线性容器PlainArray)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-plainarray.md)
- [@ohos.util.Queue (线性容器Queue)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-queue.md)
- [@ohos.util.Stack (线性容器Stack)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-stack.md)
- [@ohos.util.TreeMap (非线性容器TreeMap)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-treemap.md)
- [@ohos.util.TreeSet (非线性容器TreeSet)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-treeset.md)
- [@ohos.util.Vector (线性容器Vector)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-vector.md)
- [@ohos.xml (xml解析与生成)](https://gitee.com/openharmony/docs/blob/OpenHarmony-3.2-Release/zh-cn/application-dev/reference/apis/js-apis-xml.md)

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.8.3

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/LaunguageBaseClassLibrary/LanguageBaseClassLibrary)

#### 压缩与解压

本示例通过[@ohos.zlib](reference/apis/js-apis-zlib.md) 和[@ohos.fileio](reference/apis/js-apis-fileio.md) 接口，实现添加文件、解压和压缩文件场景。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/LaunguageBaseClassLibrary/ZipLib)



## Performance

### ArkRuntime

#### N-Body模拟程序

本示例使用[@ohos.taskpool](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-taskpool.md)和[@ohos.worker](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-worker.md) 接口，使用ArkTS编程语言开发了业界编程语言基准测试项目[Benchmarks Game](https://gitee.com/link?target=https%3A%2F%2Fsalsa.debian.org%2Fbenchmarksgame-team%2Fbenchmarksgame%2F)中的[N体问题模拟程序](https://gitee.com/link?target=https%3A%2F%2Fbenchmarksgame-team.pages.debian.net%2Fbenchmarksgame%2Fdescription%2Fnbody.html%23nbody)，实现类木星体轨道计算。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Performance/ArkRuntime/NBody)



## 工程

### 应用程序包

#### 多HAP

本示例使用应用上下文Context接口 [@ohos.app.ability.common](reference/apis/js-apis-app-ability-common.md)和媒体服务接口[@ohos.multimedia.media](reference/apis/js-apis-media.md)，展示多HAP开发，简单介绍了多HAP的使用场景，应用包含了一个entry HAP和两个feature HAP，两个feature HAP分别提供了音频和视频播放组件，entry中使用了音频和视频播放组件。 三个模块需要安装三个hap包，最终会在设备上安装一个主entry的hap包。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Project/ApplicationHap/MultiHap)

### 资源配置

#### 应用主题切换

本示例使用[@ohos.application.abilityManager](reference/apis/js-apis-application-abilityManager.md) 能力，对Ability状态进行修改：其中AbilityManager.updateConfiguration()通过修改colorMode属性来更新配置系统主题颜色，展示多种应用主题切换。通过创建 base 同级资源文件夹 dark 和 light 完成深色浅色主题相关资源配置，实现深色浅色主题切换，在 ThemeConst 文件中配置自定义主题文件，通过控制变量实现多主题切换。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Project/ResourceAllocation/ApplicationThemeSwitch)

### 测试框架

本示例展示[测试框架](https://gitee.com/openharmony/testfwk_arkxtest)的使用示例，主要介绍了 jsunit单元测试框架和uitestUI测试框架的使用示例。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Project/Test)



## 行业解决方案

### 游戏

#### 分布式五子棋

本示例使用使用分布式设备管理能力[@ohos.distributedHardware.deviceManager](reference/apis/js-apis-device-manager.md)、分布式数据管理[@ohos.data.distributedData](reference/apis/js-apis-distributed-data.md)等接口，结合[Canvas组件](reference/arkui-ts/ts-components-canvas-canvas.md) 实现棋盘、棋子的绘制，使用[分布式数据管理](reference/apis/js-apis-distributed-data.md) 实现两台设备间数据的同步。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/Game/DistributedDataGobang)

#### 游戏2048

本示例使用用户首选项[ohos.data.preferences](reference/apis/js-apis-data-preferences.md) 以及屏幕属性[@ohos.display](reference/apis/js-apis-display.md#displaygetdefaultdisplaydeprecated) 等接口，结合[Grid](reference/arkui-ts/ts-container-grid.md)组件，实现了2048小游戏功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/Game/Game2048)

#### Lottie动画

本示例展示了lottie对动画的操作功能。引入[Lottie模块](https://gitee.com/openharmony-tpc/lottieETS)，实现控制动画的播放、暂停、倍速播放、播放顺序、播放到指定帧停止或从指定帧开始播放、侦听事件等功能，动画资源路径必须是json格式。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/Game/Lottie)

### 即时通信

#### 聊天实例应用

本示例使用图片处理能力接口[@ohos.multimedia.image](reference/apis/js-apis-image.md)以及文件存储管理能力接口[@ohos.fileio](reference/apis/js-apis-fileio.md) 。展示一个仿聊天类应用，使用静态布局搭建了不同的页面。为了优化内存与性能体验，在部分list场景使用了懒加载。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/IM/Chat)

### 输入法

#### 自绘编辑框

本示例通过输入法框架实现自会编辑框，可以绑定输入法应用，从输入法应用输入内容，显示和隐藏输入法。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.7.2

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/InputMethod/CustomInputText)

#### 轻量级输入法

本示例使用[@ohos.application.InputMethodExtensionAbility](application-models/inputmethodextentionability.md)系统权限的系统接口，展示一个轻量级的输入法应用，支持在运行OpenHarmony OS的智能终端上。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/InputMethod/KikaInput)

#### Kika输入法应用

本示例使用[inputMethodEngine](reference/apis/js-apis-inputmethodengine.md)实现一个轻量级输入法应用kikaInput，支持在运行OpenHarmony OS的智能终端上。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.7.2

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/InputMethod/KikaInputMethod)

### 媒体

#### 相机和媒体库

本示例使用权限管理能力[@ohos.abilityAccessCtrl](reference/apis/js-apis-abilityAccessCtrl.md)、相机模块能力接口[@ohos.multimedia.camera](reference/apis/js-apis-camera.md)、图片处理接口[@ohos.multimedia.image](reference/apis/js-apis-image.md)、音视频相关媒体业务能力接口[@ohos.multimedia.media](reference/apis/js-apis-media.md)、媒体库管理接口[@ohos.multimedia.medialibrary](reference/apis/js-apis-medialibrary.md)、设备信息能力接口[@ohos.deviceInfo](reference/apis/js-apis-device-info.md)、文件存储管理能力接口[@ohos.fileio](reference/apis/js-apis-fileio.md)、弹窗能力接口[@ohos.prompt](reference/apis/js-apis-prompt.md)，展示如何在eTS中调用相机拍照和录像，以及如何使用媒体库接口进行媒体文件的增、删、改、查操作。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/Media/MultiMedia)

### 电商

#### 购物示例应用

本示例使用延迟任务回调能力接口[@ohos.WorkSchedulerExtensionAbility](reference/apis/js-apis-WorkSchedulerExtensionAbility.md) 、通知管理的能力接口[@ohos.notification](reference/apis/js-apis-notification.md) 、HTTP数据请求能力接口[@ohos.net.http](reference/apis/js-apis-http.md) 、媒体查询接口[@system.mediaquery](reference/apis/js-apis-system-mediaquery.md) 、管理窗口能力接口[@ohos.window](reference/apis/js-apis-window.md) 。实现在进场时加载进场动画，使用[Tabs容器](reference/arkui-ts/ts-container-tabs.md) 实现通过页签进行内容视图切换。使用[自定义弹窗](reference/arkui-ts/ts-methods-custom-dialog-box.md) 设置位置信息。使用[Swiper](reference/arkui-ts/ts-container-swiper.md) 组件实现页面展示图轮播。使用[Grid](reference/arkui-ts/ts-container-list.md) 容器组件设置展示的商品信息。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/Shopping/OrangeShopping)

### 工具

#### ArkTS时钟

本示例通过添加setInterval定时器启动时钟，使用[Canvas组件](reference/arkui-ts/ts-components-canvas-canvas.md)绘制时钟，通过[CanvasRenderingContext2D](reference/arkui-ts/ts-canvasrenderingcontext2d.md) 来画表盘背景、时针、分针、秒针、圆心以及表盘下方文本，结合[@ohos.display](reference/apis/js-apis-display.md) 接口来实现一个简单的时钟应用。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/Tools/ArkTSClock)

#### 翻页时钟

本示例集中展示了时钟、闹钟、倒计时、设置屏幕亮度相关的场景，
1、使用[@ohos.reminderAgentManager](reference/apis/js-apis-reminderAgentManager.md)完成闹钟的相关功能，
2、使用animateTo完成翻页时钟动画，使用[@ohos.runningLock](reference/apis/js-apis-runninglock.md)完成屏幕常亮功能，
3、设置屏幕亮度，使用[@ohos.brightness](reference/apis/js-apis-brightness.md)系统能力调节屏幕亮度，
4、后台消息提醒，使用[@ohos.notificationManager](reference/apis/js-apis-notificationManager.md)系统能力做后台代理提醒。
5、需要系统存储信息，使用用户首选项接口[@ohos.data.preferences](reference/apis/js-apis-data-preferences.md)。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/Tools/FlipClock)

#### JS时钟

本示例使用JS语言编写示例，设置一个定时器（timer），捕捉用户动作，当用户离开首页时（onHide事件）定时器注销（clearInverval）定时器，当用户回到小程序首页时（onShow事件），重新设置一个定时器（timer）setInterval，使用[transform](reference/arkui-js/js-components-svg-animatetransform.md)设置平移/旋转/缩放的属性，实现一个简单时钟应用。

开发语言：JS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/Tools/JsClock)

#### 图案密码锁组件

本示例使用用户首选项接口[@ohos.data.preferences](reference/apis/js-apis-data-preferences.md) 异步获取用户设定过的密码，以宫格图案的方式输入密码，用于密码验证。手指触碰图案密码锁时开始进入输入状态，手指离开屏幕时结束输入状态并向应用返回输入的密码。展示图案密码锁组件的使用，实现了密码设置、验证和重置功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/Tools/PatternLock)



## 关键特性

### 分布式

#### ArkTS分布式计算器

本示例使用分布式数据管理接口[@ohos.data.distributedData](reference/apis/js-apis-distributed-data.md)、媒体查询接口[@ohos.mediaquery](reference/apis/js-apis-mediaquery.md)、分布式设备管理能力接口(设备管理)[@ohos.distributedHardware.deviceManager](reference/apis/js-apis-device-manager.md)，实现设备之间的kvStore对象的数据传输交互。通过StartAbility实现远端应用的拉起以及DistributedDataKit分布式数据框架实现异端应用的数据同步，实现一个简单的计算器应用，可以进行简单的数值计算，支持远程拉起另一个设备的计算器应用，两个计算器应用进行协同计算。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.7

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/ArkTSDistributedCalc)

#### ArkTS分布式音乐播放

本示例使用与用户进行交互的Ability的能力接口[@ohos.ability.featureAbility](reference/apis/js-apis-ability-featureAbility.md)、文件存储管理能力接口[@ohos.fileio](reference/apis/js-apis-fileio.md)、屏幕属性接口[@ohos.display](reference/apis/js-apis-display.md)、媒体查询接口[@ohos.mediaquery](reference/apis/js-apis-mediaquery.md)、分布式数据管理接口[@ohos.data.distributedData](reference/apis/js-apis-distributed-data.md)、音视频相关媒体业务能力接口[@ohos.multimedia.media](reference/apis/js-apis-media.md)、分布式设备管理能力接口(设备管理)[@ohos.distributedHardware.deviceManager](reference/apis/js-apis-device-manager.md)，实现设备之间的kvStore对象的数据传输交互。通过AudioPlayer实现音频播放能力，调用分布式数据各个接口，应用程序可将数据保存到分布式数据库中，并可对分布式数据库中的数据进行增/删/改/查等各项操作。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/ArkTSDistributedMusicPlayer)

#### JS分布式计算器

本示例使用分布式数据管理接口[@ohos.data.distributedData](reference/apis/js-apis-distributed-data.md)、媒体查询接口[@ohos.mediaquery](reference/apis/js-apis-mediaquery.md)、分布式设备管理能力接口(设备管理)[@ohos.distributedHardware.deviceManager](reference/apis/js-apis-device-manager.md)，实现设备之间的kvStore对象的数据传输交互。通过StartAbility实现远端应用的拉起以及DistributedDataKit分布式数据框架实现异端应用的数据同步，实现一个简单的计算器应用，可以进行简单的数值计算，支持远程拉起另一个设备的计算器应用，两个计算器应用进行协同计算。

开发语言：JS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/DistributeCalc)

#### 分布式帐号

本示例主要展示了分布式帐号相关的功能，使用[@ohos.account.distributedAccount](reference/apis/js-apis-distributed-account.md)、[@ohos.account.osAccount](reference/apis/js-apis-osAccount.md)等接口，实现了绑定分布式帐号、解绑分布式帐号、更新分布式帐号信息和管理分布式帐号的功能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.7.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/DistributedAccount)

#### 设备管理

本示例主要展示了设备管理相关的功能，使用[@ohos.distributedHardware.deviceManager](reference/apis/js-apis-device-manager.md) 等接口，实现了包括获取本机设备信息，获取授信设备列表，根据过滤条件扫描设备，设备认证，设备状态订阅，导入凭据，控制设备是否允许被发现等功能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/DistributedAuthentication)

#### 分布式备忘录

本示例使用分布式数据管理接口[@ohos.data.distributedData](reference/apis/js-apis-distributed-data.md)、权限管理能力[@ohos.abilityAccessCtrl](reference/apis/js-apis-abilityAccessCtrl.md)、分布式数据对象接口[@ohos.data.distributedDataObject](reference/apis/js-apis-data-distributedobject.md)以及分布式设备管理能力接口(设备管理)[@ohos.distributedHardware.deviceManager](reference/apis/js-apis-device-manager.md)，实现设备之间的distributedDataObject对象的数据传输交互，展示在eTS中如何使用分布式数据对象实现一个简单的分布式备忘录。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.1

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/DistributedNote)

#### 分布式关系型数据库

本示例使用[@ohos.data.relationalStore](reference/apis/js-apis-data-relationalStore.md) 接口和[@ohos.distributedHardware.deviceManager](reference/apis/js-apis-device-manager.md) 接口展示了在eTS中分布式关系型数据库的使用，在增、删、改、查的基本操作外，还包括分布式数据库的数据同步同能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/DistributedRdb)

#### JS分布式音乐播放

本示例使用与用户进行交互的Ability的能力接口[@ohos.ability.featureAbility](reference/apis/js-apis-ability-featureAbility.md)、文件存储管理能力接口[@ohos.fileio](reference/apis/js-apis-fileio.md)、屏幕属性接口[@ohos.display](reference/apis/js-apis-display.md)、媒体查询接口[@ohos.mediaquery](reference/apis/js-apis-mediaquery.md)、分布式数据管理接口[@ohos.data.distributedData](reference/apis/js-apis-distributed-data.md)、音视频相关媒体业务能力接口[@ohos.multimedia.media](reference/apis/js-apis-media.md)、分布式设备管理能力接口(设备管理)[@ohos.distributedHardware.deviceManager](reference/apis/js-apis-device-manager.md)，实现设备之间的kvStore对象的数据传输交互。通过AudioPlayer实现音频播放能力，调用分布式数据各个接口，应用程序可将数据保存到分布式数据库中，并可对分布式数据库中的数据进行增/删/改/查等各项操作。

开发语言：JS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/JsDistributedMusicPlayer)

#### 分布式数据管理

本示例展示了在eTS中分布式数据管理的使用，包括KVManager对象实例的创建和KVStore数据流转的使用。

通过设备管理接口[@ohos.distributedHardware.deviceManager](reference/apis/js-apis-device-manager.md) ，实现设备之间的kvStore对象的数据传输交互，该对象拥有以下能力[详见](reference/apis/js-apis-device-manager.md) ;
1、注册和解除注册设备上下线变化监听
2、发现周边不可信设备
3、认证和取消认证设备
4、查询可信设备列表
5、查询本地设备信息，包括设备名称，设备类型和设备标识
6、发布设备发现

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/Kvstore)

### 一次开发多端部署

#### ArkTS多设备自适应能力

本示例是[《一次开发，多端部署》](https://gitee.com/openharmony/docs/tree/master/zh-cn/application-dev/key-features/multi-device-app-dev)的配套示例代码，展示了[页面开发的一多能力](key-features/multi-device-app-dev/layout-intro.md)，包括自适应布局、响应式布局、典型布局场景以及资源文件使用。

| 名称         | 简介                                                         |
| ------------ | ------------------------------------------------------------ |
| 自适应布局   | 当外部容器大小发生变化时，元素可以**根据相对关系自动变化**以适应外部容器变化的布局能力。 |
| 响应式布局   | 当外部容器大小发生变化时，元素可以**根据断点或特定的媒体特征（如屏幕方向、窗口宽高等）自动变化**以适应外部容器变化的布局能力。 |
| 典型布局场景 | 应用开发中的典型场景，包括运行横幅、网格、侧边栏等。         |
| 资源文件使用 | 根据当前的设备特征（如设备类型、屏幕密度等）或应用场景（如语言、国家、地区等），从resources目录下不同的资源限定词目录中获取相应的资源值。 |

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/AdaptiveCapabilities)

#### 一多应用市场首页

本示例使用媒体查询接口[@ohos.mediaquery](reference/apis/js-apis-mediaquery.md)，结合[一次开发多端部署](https://gitee.com/openharmony/docs/tree/master/zh-cn/application-dev/key-features/multi-device-app-dev)中介绍的自适应布局能力和响应式布局能力进行多设备（或多窗口尺寸）适配，保证应用在不同设备或不同窗口尺寸下可以正常显示，展示应用市场首页，页面中包括Tab栏、运营横幅、精品应用、精品游戏等。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/AppMarket)

#### 健康饮食

本示例使用了路由跳转[@ohos.router](reference/apis/js-apis-system-router.md)，比如点击食物，可以跳转至相应的食物详情页面，通过[一次开发多端部署](https://gitee.com/openharmony/docs/tree/master/zh-cn/application-dev/key-features/multi-device-app-dev)，使用其中介绍的自适应布局能力和响应式布局能力进行多设备（或多窗口尺寸）适配，保证应用在不同设备或不同窗口尺寸下可以正常显示，使用[@ohos.mediaquery](reference/apis/js-apis-mediaquery.md)的MediaQueryListener方法查询媒体，matchMediaSync方法设置媒体查询的查询条件，[@ohos.curves](reference/apis/js-apis-curve.md)的cubicBezierCurve方法构造三阶贝塞尔曲线对象。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/HealthyDiet)

#### JS多设备自适应能力

1.本示例中的资源限定词和响应式布局针对常见设备类型做了适配，可以在预览器中开启"Multi-profile preview"进行多设备预览。

2.本示例中的原子布局提供了滑动条（slider），通过拖动滑动条更改父容器尺寸可以更直观的查看原子布局的效果。为了突出重点以及易于理解，此部分的代码做了一定精简，建议通过IDE预置的MatePadPro预览器查看此部分效果。

3.启动应用，首页展示了**资源限定词**、**原子布局**和**响应式布局**三个按钮。

4.点击**资源限定词**进入新界面，展示字符串和图片资源的使用。

5.点击**原子布局**进入新界面，分别展示原子布局的拉伸能力、缩放能力、隐藏能力、折行能力、均分能力、占比能力、延伸能力。

6.点击**响应式布局**进入新界面，展示媒体查询、栅格布局、典型场景三类响应式布局能力。

开发语言：JS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/JsAdaptiveCapabilities)

#### 一多分栏控件

本示例分别展示了多场景下，一多分栏控件的响应式变化效果。分别用到了[SideBarContainer](reference/arkui-ts/ts-container-sidebarcontainer.md)组件与[Navigation](reference/arkui-ts/ts-basic-components-navigation.md)组件，对应使用场景如下：

- A+B+C：即SideBarContainer组件组合Navigation组件
  1. 预览器窗口宽度>840vp时，显示A、B、C三列，放大缩小时，优先变化C列
  2. 预览器窗口宽度<=840vp并且>600vp时，显示B、C两列，放大缩小时，优先变化C列
  3. 预览器窗口宽度<=600vp并且>360vp时，仅显示C列
- A+C：SideBarContainer组件
  1. 预览器窗口宽度>600vp时，显示A、C三列，放大缩小时，优先变化C列
  2. 预览器窗口宽度<=600vp并且>360vp时，仅显示C三列
- B+C：Navigation组件
  1. 预览器窗口宽度>600vp时，显示B、C三列，放大缩小时，优先变化C列
  2. 预览器窗口宽度<=600并且>360vp时，仅显示C三列

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.2

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/MultiColumns)

#### 一多导航栏

本示例展示了导航组件在不同设备形态下的样式。

- 在sm设备上，以tabs形式展示，内容、导航为上下样式布局，通过点击底部tabs切换内容；
- 在md/lg设备上，以[SideBarContainer](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/arkui-ts/ts-container-sidebarcontainer.md)形式展示，内容、导航为左右布局，通过点击侧边一二级菜单进行内容切换。

本示例使用[一次开发多端部署](https://gitee.com/openharmony/docs/tree/master/zh-cn/application-dev/key-features/multi-device-app-dev) 中介绍的自适应布局能力和响应式布局能力进行多设备（或多窗口尺寸）适配，主要通过组件提供窗口断点事件，保证应用在不同设备或不同窗口尺寸下可以正常显示。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.8.2

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/MultiNavBar)

#### 一多音乐专辑主页

本示例使用媒体查询接口[@ohos.mediaquery](reference/apis/js-apis-mediaquery.md)，[一次开发多端部署](https://gitee.com/openharmony/docs/tree/master/zh-cn/application-dev/key-features/multi-device-app-dev)中介绍的自适应布局能力和响应式布局能力进行多设备（或多窗口尺寸）适配，保证应用在不同设备或不同窗口尺寸下可以正常显示，展示音乐专辑主页。

- 头部返回栏: 因元素单一、位置固定在顶部，因此适合采用自适应拉伸，充分利用顶部区域。
- 专辑封面: 使用栅格组件控制占比，在小尺寸屏幕下封面图与歌单描述在同一行。
- 歌曲列表: 使用栅格组件控制宽度，在小尺寸屏幕下宽度为屏幕的100%，中尺寸屏幕下宽度为屏幕的50%，大尺寸屏幕下宽度为屏幕的75%。
- 播放器: 采用自适应拉伸，充分使用底部区域。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/MusicAlbum)

#### 一多设置典型页面

本示例使用[Navigation组件](reference/arkui-ts/ts-basic-components-navigation.md)，实现小窗口单栏显示、大窗口双栏显示的效果，结合[一次开发多端部署](https://gitee.com/openharmony/docs/tree/master/zh-cn/application-dev/key-features/multi-device-app-dev)中介绍的自适应布局能力和响应式布局能力进行多设备（或多窗口尺寸）适配，保证应用在不同设备或不同窗口尺寸下可以正常显示。 实现单/双栏的显示效果、 实现点击跳转或刷新、 实现多级跳转。展示设置应用的典型页面，其在小窗口和大窗口有不同的显示效果，体现一次开发、多端部署的能力。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/Settings)

#### 一多天气

本示例使用[SideBarContainer](reference/arkui-ts/ts-container-sidebarcontainer.md)实现侧边栏功能，[栅格容器组件](reference/arkui-ts/ts-container-gridrow.md)实现界面内容的分割和展示，[Canvas组件](reference/arkui-ts/ts-components-canvas-canvas.md)和[CanvasRenderingContext2D](reference/arkui-ts/ts-canvasrenderingcontext2d.md) 完成空气质量和日出月落图的曲线绘制，再结合[一次开发，多端部署](https://gitee.com/openharmony/docs/tree/master/zh-cn/application-dev/key-features/multi-device-app-dev)的指导中响应式布局的栅格断点系统实现在不同尺寸窗口界面上不同的显示效果。展示一个天气应用界面，包括首页、城市管理、添加城市、更新时间弹窗，体现一次开发，多端部署的能力。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/Weather)

### 卡片

#### JS多设备自适应服务卡片

本示例使用卡片扩展模块接口[@ohos.app.form.FormExtensionAbility](reference/apis/js-apis-app-form-formExtensionAbility.md) 、卡片信息和状态等相关类型和枚举接口[@ohos.app.form.formInfo](reference/apis/js-apis-app-form-formInfo.md) 、卡片数据绑定的能力接口[@ohos.app.form.formBindingData](reference/apis/js-apis-app-form-formBindingData.md) 。展示Js工程中服务卡片的布局和使用，其中卡片内容显示使用了一次开发，多端部署的能力实现多设备自适应。

开发语言：JS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/Widget/AdaptiveServiceWidget)

#### ArkTS卡片

##### ArkTS卡片计算器

本示例展示了使用ArkTS卡片开发的计算器模型。部分设备的桌面不支持卡片，可以通过自己的开发卡片使用方，进行卡片的创建、更新和删除等操作。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/Widget/ArkTSCard/Calculator)

##### ArkTS卡片Canvas小游戏

本示例展示了如何通过ArkTS卡片的Canvas自定义绘制能力实现一个简单的五子棋游戏卡片。

- 使用Canvas绘制棋盘和黑白棋子的落子。
- 通过卡片支持的[点击事件](reference/arkui-ts/ts-universal-events-click.md)进行交互，让用户在棋盘上进行黑白棋子的对局。
- 通过TS的逻辑代码实现五子棋输赢判定、回退等逻辑计算，整个游戏过程无需拉起FormExtensionAbility。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/Widget/ArkTSCard/CanvasGame)

##### ArkTS音乐卡片

本示例展示了如何通过ArkTS卡片实现一个简单的音乐卡片。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/Widget/ArkTSCard/MusicControl)

#### Stage模型卡片

本示例使用卡片扩展模块接口[@ohos.app.form.FormExtensionAbility](reference/apis/js-apis-app-form-formExtensionAbility.md) 、卡片信息和状态等相关类型和枚举接口[@ohos.app.form.formInfo](reference/apis/js-apis-app-form-formInfo.md) 、卡片提供方相关接口的能力接口[@ohos.app.form.formProvider](reference/apis/js-apis-app-form-formProvider.md) 、应用组件间的信息传递接口[@ohos.app.ability.Want](reference/apis/js-apis-app-ability-want.md) 。展示了Stage模型卡片提供方的创建与使用。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.7

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/Widget/FormExtAbility)

#### Stage模型卡片小游戏

本示例展示了如何通过Stage模型实现一个简单的游戏卡片。

- 通过卡片支持的[点击事件](reference/js-service-widget-ui/js-service-widget-common-events.md)进行交互，让用户通过点击的先后顺序把一个乱序的成语排列成正确的成语。
- 使用了C++和TS的混合编程方式，将获取随机数的能力下沉到C++实现，并通过[NAPI](napi/napi-guidelines.md)的能力将C++实现的能力暴露到TS中。
- 用到了卡片扩展模块接口，[@ohos.app.form.FormExtensionAbility](reference/apis/js-apis-app-form-formExtensionAbility.md) 。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/Widget/FormGame)

#### 应用主动添加数据代理卡片到桌面

本示例主要展示了使用[@ohos.app.form.formBindingData](reference/apis/js-apis-app-form-formBindingData.md)、[@ohos.app.form.formProvider](reference/apis/js-apis-app-form-formProvider.md)等接口，实现了在com.ohos.hag.famanager应用上，主动添加数据代理卡片到桌面的功能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.8.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/Widget/RequestAddForm)



## 系统特性

### 应用模型

#### AccessibilityExtensionAbility示例

本示例展示了[AccessibilityExtensionAbility](application-models/accessibilityextensionability.md)的简单应用，使用多个辅助功能接口，启动或关闭无障碍扩展服务，实现了一些快捷的交互方式。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/AccessibilityExtAbility)

#### EnterpriseAdminExtensionAbility的创建与使用

本示例通过[@ohos.enterprise.EnterpriseAdminExtensionAbility](reference/apis/js-apis-EnterpriseAdminExtensionAbility.md)接口实现了系统管理状态变化通知功能，[@ohos.enterprise.adminManager](reference/apis/js-apis-enterprise-adminManager.md)接口中enableAdmin方法去激活当前用户下的指定设备管理员应用，disableSuperAdmin方法去根据bundleName将管理员用户下的超级管理员应用去激活，subscribeManagedEvent方法去指定设备管理员应用订阅系统管理事件，unsubscribeManagedEvent方法去指定设备管理员应用取消订阅系统管理事件来实现应用激活、去激活、应用安装、卸载事件。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/EnterpriseAdminExtensionAbility)

#### 仿桌面应用

本示例使用[@ohos.bundle.launcherBundleManager](reference/apis/js-apis-launcherBundleManager.md)模块接口，获取所有应用信息和给定包名获取应用信息，实现桌面展示所有安装的应用。使用[@ohos.bundle](reference/apis/js-apis-Bundle.md)的getBundleInstaller接口获取到，调用uninstall接口实现应用卸载功能。使用[@ohos.app.form.formHost](reference/apis/js-apis-app-form-formHost.md)接口，获取应用卡片信息，使用FormComponent组件展示卡片内容，从而实现添加卡片到桌面的功能。使用关系型数据库[@ohos.data.relationalStore](reference/apis/js-apis-data-relationalStore.md)接口，实现桌面数据持久化存储，存储应用的位置信息，卡片信息。使用[@ohos.application.missionManager](reference/apis/js-apis-application-missionManager.md)接口，获取最近任务信息，并实现加锁、解锁、清理后台任务的功能。使用[@ohos.app.ability.ServiceExtensionAbility](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.app.ability.ServiceExtensionAbility.d.ts)的startRecentAbility接口，拉起最近任务至前台显示，若应用Ability未启动时，则拉起新创建的应用Ability显示到前台。实现了一个简单桌面应用，概括为以下几点：

1.展示了系统安装的应用，实现点击启动、应用上滑弹出卡片、卡片添加到桌面、卡片移除功能。

2.实现桌面数据持久化存储，应用支持卸载、监听应用卸载和安装并显示。

3.实现最近任务管理功能，包括任务卡片加锁、解锁、清理和清理所有任务功能。

4.通过点击应用图标或点击由长按图标弹出的菜单栏中的打开按钮的方式打开应用，是以打开最近任务方式拉起应用Ability。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/Launcher)

#### 系统任务管理

本示例通过调用系统任务管理的能力，使用[@ohos.application.missionManager](reference/apis/js-apis-application-missionManager.md) 、[@ohos.multimedia.image](reference/apis/js-apis-image.md) 等接口完成对系统任务执行锁定、解锁、清理、切换到前台等操作。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/MissionManager)

#### 静态订阅

本示例主要展示了静态订阅的创建与使用，以及静态订阅的使能和去使能。通过[CommonEventManager](reference/apis/js-apis-commonEventManager.md)发布自定义事件，使能和去使能静态订阅。通过[StaticSubscriberExtensionAbility](reference/apis/js-apis-application-staticSubscriberExtensionAbility.md)、[NotificationManager](reference/apis/js-apis-notificationManager.md)静态订阅已发布的自定义事件，订阅后即可自动收到该事件，收到该事件后，发送通知将自定义事件数据显示在通知栏。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/StaticSubscriber)

#### 测试依赖

##### 跨任务链返回

本示例为一个仿桌面应用测试demo，使用[@ohos.app.ability.ServiceExtensionAbility](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.app.ability.ServiceExtensionAbility.d.ts)接口中ServiceExtensionContext类的startRecentAbility能力（系统能力：SystemCapability.Ability.AbilityRuntime.Core），实现了跨任务链返回的功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/TestRely/LauncherTest/CrossChainBack)

##### 启动上一次的组件实例

本示例为一个仿桌面应用测试demo，测试的功能为：点击仿桌面应用上的应用图标，若应用未启动则启动应用，若应用已经被启动并创建多个实例则启动上一次拉起的实例。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/TestRely/LauncherTest/StartRecentAbility)

### 网络与连接

#### 蓝牙

本示例通过[@ohos.bluetooth](reference/apis/js-apis-bluetooth.md) 接口实现蓝牙设备发现、配对、取消配对功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Connectivity/Bluetooth)

#### WLAN

本示例通过[@ohos.wifiManager](reference/apis/js-apis-wifiManager.md) 相关API实现wlan激活和关闭、扫描和连接WIFI等功能。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Connectivity/Wlan)

### 数据管理

#### 跨应用数据共享

本示例使用数据共享扩展能力[@ohos.data.DataShareResultSet](reference/apis/js-apis-application-dataShareExtensionAbility.md)，关系型数据库[@ohos.data.relationalStore](reference/apis/js-apis-data-dataShare.md)，[@ohos.data.rdb](reference/apis/js-apis-data-rdb.md)实现了一个跨应用数据共享实例，分为联系人（数据提供方）和联系人助手（数据使用方）两部分：联系人支持联系人数据的增、删、改、查等功能；联系人助手支持同步联系人数据，当联系人与联系人助手数据不一致时，支持合并重复数据。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DataManagement/CrossAppDataShare)

### 设备管理

#### 设备管理合集(系统特性)

本示例集合设备管理相关(系统特性)不需要复杂功能展示的模块，展示了各个模块的基础功能，包含：

- [@ohos.batteryStatistics (耗电统计)](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Fapis%2Fjs-apis-batteryStatistics.md%2F)
- [@ohos.brightness (屏幕亮度)](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Fapis%2Fjs-apis-brightness.md%2F)
- [@ohos.power (系统电源管理)](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Fapis%2Fjs-apis-power.md%2F)
- [@ohos.settings (设置数据项名称)](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Fapis%2Fjs-apis-settings.md%2F)
- [@ohos.systemCapability (系统能力)](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Fapis%2Fjs-apis-system-capability.md%2F)
- [@ohos.systemParameterEnhance (系统参数)](https://gitee.com/link?target=https%3A%2F%2Fdocs.openharmony.cn%2Fpages%2Fv3.2%2Fzh-cn%2Fapplication-dev%2Freference%2Fapis%2Fjs-apis-system-parameterEnhance.md%2F)
- [@ohos.batteryInfo (电量信息)](reference/apis/js-apis-battery-info.md)
- [@ohos.deviceInfo (设备信息)](reference/apis/js-apis-device-info.md)
- [@ohos.multimodalInput.inputConsumer (组合按键)](reference/apis/js-apis-inputconsumer.md)
- [@ohos.multimodalInput.inputDevice (输入设备)](reference/apis/js-apis-inputdevice.md)
- [@ohos.multimodalInput.inputEvent (输入事件)](reference/apis/js-apis-inputevent.md)
- [@ohos.multimodalInput.inputEventClient (按键注入)](reference/apis/js-apis-inputeventclient.md)
- [@ohos.multimodalInput.inputMonitor (输入监听)](reference/apis/js-apis-inputmonitor.md)
- [@ohos.multimodalInput.keyCode (键值)](reference/apis/js-apis-keycode.md)
- [@ohos.multimodalInput.keyEvent (按键输入事件)](reference/apis/js-apis-keyevent.md)
- [@ohos.multimodalInput.mouseEvent (鼠标输入事件)](reference/apis/js-apis-mouseevent.md)
- [@ohos.multimodalInput.pointer (鼠标指针)](reference/apis/js-apis-pointer.md)
- [@ohos.multimodalInput.touchEvent (触摸输入事件)](reference/apis/js-apis-touchevent.md)

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DeviceManagement/DeviceManagementCollection)

#### 屏幕属性

本示例主要展示了屏幕管理相关的功能，使用[@ohos.display](reference/apis/js-apis-display.md)、[@ohos.screen](reference/apis/js-apis-screen.md)接口，[@ohos.display](reference/apis/js-apis-display.md)接口提供获取默认display对象、获取所有display对象，开启监听、关闭监听功能；[@ohos.screen](reference/apis/js-apis-screen.md)接口提供创建虚拟屏幕、销毁虚拟屏幕、扩展屏幕、镜像屏幕等功能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DeviceManagement/Screen)

#### 存储空间统计

本示例使用[DataPanel组件](reference/arkui-ts/ts-basic-components-datapanel.md)展示不同种类的应用存储信息，通过[@ohos.bundle.bundleManager](reference/apis/js-apis-Bundle.md)模块来获取不同应用的包名与应用名等信息，使用应用空间统计[@ohos.file.storageStatistics](reference/apis/js-apis-file-storage-statistics.md)来查询当前设备的存储使用情况，使用卷管理[@ohos.file.volumeManager](reference/apis/js-apis-file-volumemanager.md)来查询可用卷存储使用情况。实现了查看当前设备存储空间信息、所有安装的应用的存储信息、所有可用卷的存储信息的功能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DeviceManagement/StorageStatistic)

#### 多模输入

本示例使用[鼠标指针](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-pointer.md)，展示了多模输入鼠标外设的五种场景：鼠标样式资源切换、设置鼠标大小及颜色、设置鼠标动画光标样式、通过switch开关切换鼠标滚轮在非激活悬停窗口的滚动操作使能状态、通过switch开关切换鼠标主次键等功能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.11.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DeviceManagement/Mouse)

### 国际化

#### 国际化

本示例展示如何使用媒体查询，[@ohos.intl](reference/apis/js-apis-intl.md)模块包含国际化能力基础接口，[@ohos.i18n](reference/apis/js-apis-i18n.md)模块包含国际化能力增强接口，资源管理模块，根据当前configuration（语言，区域，横竖屏，mccmnc）和device capability（设备类型，分辨率）提供获取应用资源信息读取接口。三个结合一起实现语言地区设置、时区设置和国际化资源管理相关功能。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.7.5

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Internationalnation/International)

### 媒体

#### 相机和媒体库

本示例使用[@ohos.multimedia.camera](reference/apis/js-apis-camera.md)接口实现相机示例的主要功能：拍照、录像、参数配置等。使用[@ohos.multimedia.mediaLibrary](reference/apis/js-apis-medialibrary.md) 接口实现对媒体文件的存储。同时支持拍照角度旋转以及录制分辨率选择。

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.1

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Media/Camera)

#### 录屏示例

本示例使用[@ohos.screen](reference/apis/js-apis-screen.md)管理屏幕的一些基础能力，包括获取屏幕对象，监听屏幕变化，创建和销毁虚拟屏幕等。[@ohos.multimedia.media](reference/apis/js-apis-media.md)和[@ohos.multimedia.mediaLibrary](reference/apis/js-apis-medialibrary.md)完成视频编码并保存到文件中。[@ohos.display](reference/apis/js-apis-display.md)捕捉屏幕显示图像帧，展示设备屏幕（含音频）录制功能。屏幕录制的主要工作是通过创建一个虚拟屏，捕获屏幕显示图形帧，完成视频编码并保存到文件中，帮助OEM设备厂家系统应用实现屏幕录制功能，也可以通过此应用抓取屏幕帧用于问题复现录制。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Media/ScreenRecorder)

#### 截屏

本示例使用[screenshot](reference/apis/js-apis-screenshot.md)模块实现屏幕截图 ，使用[window](reference/apis/js-apis-window.md#setwindowprivacymode9)模块实现隐私窗口切换，使用[display](reference/apis/js-apis-display.md#displayhasprivatewindow9)模块查询当前隐私窗口。展示全屏截图和屏幕局部截图。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Media/Screenshot)

### 安全

#### 访问权限控制

本示例使用[@ohos.abilityAccessCtrl](reference/apis/js-apis-abilityAccessCtrl.md)接口中abilityAccessCtrl方法获取访问控制模块对象，GrantStatus.PERMISSION_GRANTED方法表示已授权状态，[@ohos.bundle.bundleManager](reference/apis/js-apis-bundleManager.md)接口中getApplicationInfo方法根据包名获取ApplicationInfo等展示应用申请权限场景

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Security/AbilityAccessCtrl)

### 窗口管理

#### 窗口扩展应用

本示例通过 [窗口扩展能力](reference/apis/js-apis-application-windowExtensionAbility.md) 设置不同Ability，使用 [AbilityComponent](reference/arkui-ts/ts-container-ability-component.md) 组件加载各个Ability。仿设置应用，实现点击设置菜单栏，跳转或加载详情页面。

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/WindowManagement/WindowExtAbility)

