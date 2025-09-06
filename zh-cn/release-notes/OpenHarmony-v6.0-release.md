# OpenHarmony 6.0 Release


## 版本概述

OpenHarmony 6.0 Release版本进一步增强ArkUI组件能力，提供更安全、更灵活的组件布局；进一步增强窗口能力，新增支持窗口处理文本显示的能力；进一步增强分布式数据管理能力，支持管理资产和资产组，支持应用对标准化数据进行展示；进一步增强位置服务、输入法框架的相关能力等等。

更详细的特性新增与增强的说明如下：


### 应用框架

- 新增AppServiceExtensionAbility模块，提供后台服务相关扩展能力，包括后台服务的创建、销毁、连接、断开等生命周期回调。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md)）

- 新增支持应用查询自身权限授权状态信息。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#getselfpermissionstatus20)）

- 支持通过装饰器开发意图，支持将现有功能通过装饰器快速集成至系统入口。（[指南](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/application-models/insight-intent-decorator-development.md)）

- 新增支持互动卡片。（[指南](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/form/arkts-ui-liveform-overview.md)）

- 新增支持Kiosk模式。Kiosk模式是一种特殊的设备锁定模式，可以确保设备界面只服务于特定的交互场景。（[指南](https://gitcode.com/RayShih/docs/blob/master/zh-cn/application-dev/reference/apis-ability-kit/js-apis-app-ability-kioskManager.md)）

- 应用启动框架支持在feature类型的HAP中配置，以及支持添加任务匹配规则。（[指南](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/application-models/app-startup.md#%E6%94%AF%E6%8C%81%E7%9A%84%E8%8C%83%E5%9B%B4)）

### ArkUI

- 组件布局能力增强：

  - 组件背景安全区默认延伸：当组件与非安全区邻接时（包括SafeAreaPadding，AI导航栏，状态栏），组件背景默认延伸到非安全区，提升沉浸式开发体验。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#background20)）

  - 忽略组件布局安全区边缘：当组件与非安全区邻接时（包括SafeAreaPadding，AI导航栏，状态栏），组件设置忽略布局安全区边缘后可布局到非安全区。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-expand-safe-area.md#ignorelayoutsafearea20)）

  - 基础布局能力：宽高支持LayoutPolicy布局能力，包括自适应父组件matchParent，自适应内容wrapContent，自适应内容（忽略父组件的约束）fitAtIdealSize。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-types.md#layoutpolicy15)）

- 新增支持对Navigation双栏模式设置默认占位页。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#lockcanvas20)）

- UX视觉效果优化：菜单与拖拽过渡，菜单跟随效果优化：拖拽发起时，实时更新菜单位置；菜单整体跟随拖拽跟手图；跟手图存在缩放场景时，菜单与跟手图之间的间隔整体相对合理；控件支持P3色域显示。

- 通过XComponent组件新开的lockCanvas接口，开发者可获取到Drawing Canvas对应的ArkTS对象，使用该对象执行绘制指令会直接绘制到XComponent上，相较于基于NDK接口绘制，更易用。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-frameNode.md#cancelanimations20)）

- 新增支持取消隐式动画的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-frameNode.md#cancelanimations20)）

- 保存控件新增支持图标和文字的自定义能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-security-components-savebutton.md#savebuttonattribute)）

- 无感监听支持全量手势事件上报，包括基础手势识别，长按、捏合、旋转和快滑。（[API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkts-apis-uicontext-uiobserver.md#onwillclick12)）

- NDK侧新增渲染节点的能力，包括创建、挂载、渲染属性设置、自定义绘制、重绘、绘制优先级、脏区裁剪等能力，以及配套的属性动画和FrameNode上事件拦截转发。（[API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/capi-native-render-h.md)）


### ArkWeb

- ArkWeb使用的Chromium内核从114版本升级到132版本。详细说明请查看[ArkWeb版本的差异总结](https://gitcode.com/openharmony-tpc/chromium_src/blob/132_trunk/web/ReleaseNote/ArkWeb_114_132.md)。

- 交互能力增强：支持组合键缩放禁用、强制手势缩放、手势获焦、自定义文本菜单等。

- 新增支持手写笔PointerEvent事件。

- 新增支持在网络加载错误时返回自定义的错误页。（[API参考](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/arkts-basic-components-web-events.md#onoverrideerrorpage20)）


### 窗口管理

- 新增支持窗口显示时默认不获取焦点，点击后可获取焦点。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#showwindow20)）

- 新增支持输入法动画开始前和结束后的回调，方便应用进行输入法弹出与收回动画的响应。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#onkeyboardwillshow20)）

- 新增支持通过C API卸载自定义字体以释放内存空间。（[API参考](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/zh-cn/application-dev/reference/apis-arkgraphics2d/capi-drawing-register-font-h.md#oh_drawing_unregisterfont)）

- 新增支持设置文本垂直对齐方式。（[API参考](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkgraphics2d/js-apis-graphics-text.md#textverticalalign20)）

- 新增支持拷贝段落样式、文本样式、文本阴影对象。（[API参考](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkgraphics2d/capi-drawing-text-typography-h.md#oh_drawing_copytypographystyle)）

- 新增支持以独立文字为单位进行塑形。（[API参考](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkgraphics2d/capi-drawing-text-run-h.md#oh_drawing_getrunfont)）

### 图形

- 新增支持中西文自动间距，支持排版时去除行位空格；新增支持修改文本颜色无需重新排版；新增支持不跟随系统高对比度文字开关设置。（[API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkgraphics2d/js-apis-graphics-text.md#paragraphstyle)

- 图片编码的ASTC编码支持HDR质量的编码。（[API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-image-kit/arkts-apis-image-i.md#packingoption)）

- 新增支持为组件内容添加HDR提亮效果，该能力为系统能力。（[API参考](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkgraphics2d/js-apis-uiEffect-sys.md#hdrbrightnessratio20)）

- 新增NativeFence接口，实现对fenceFd阻塞指定时间、永久阻塞、关闭和检查fenceFd是否有效等操作。（[指南](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/graphics/native-fence-guidelines.md)）

### 包管理

- 新增setShortcutVisibleForSelf接口，支持设置当前应用的快捷方式是否显示。（[API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-ability-kit/js-apis-shortcutManager.md)）

- 新增getAbilityInfo接口，支持根据指定的uri获取应用的ability信息。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetabilityinfo20)）


### 分布式数据管理

- 新增支持设置资产和资产组的相关接口。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/database/data-sync-of-distributed-data-object.md#%E8%B5%84%E4%BA%A7%E5%90%8C%E6%AD%A5%E6%9C%BA%E5%88%B6)）

- 新增提供基于标准化数据结构的标准卡片控件接口，支持应用对标准化数据结构进行可视化展示。

- UDMF新增DataHub、系统分享、picker、右键菜单这三类数据通道的生命周期管理能力，提供ArkTS和C API。（[API参考-ArkTS](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-arkdata/js-apis-data-unifiedDataChannel.md#intention)、[API参考-C API](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-arkdata/capi-udmf-h.md#%E6%9E%9A%E4%B8%BE%E7%B1%BB%E5%9E%8B%E8%AF%B4%E6%98%8E)）
  其中DataHub仅C API为本次新增，ArkTS已支持。

- 新增支持监听附件传输的进度，支持接续传输。（[API参考](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkdata/js-apis-data-distributedobject.md#onprogresschanged20)）


### 分布式软总线

新开放底层连接能力接口，实现连接能力提升。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/distributedservice/linnkEnhance_development-guide.md)）


### 分布式服务

新增C API支持获取本地设备名称。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-distributedservice-kit/capi-devicemanager.md)）

### 分布式设备管理

新增机械设备管理服务，主要面向云台、机械臂等智能机械体配件设备提供交互控制的能力。（[指南](https://gitcode.com/openharmony/docs/tree/master/zh-cn/application-dev/reference/apis-mechanic-kit)）


### 事件通知

新增支持三方应用获取通知响铃震动等设置信息。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagergetnotificationsetting20)）


### 语言编译器运行时

- 新增针对系统JSVM引擎API调用内存泄漏问题的定位能力。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/napi/jsvm-frequently-questions.md)）

- 新增FastBuffer对象定义。FastBuffer对象是更高效的Buffer容器，用于表示固定长度的字节序列，是专门存放二进制数据的缓存区。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-arkts/js-apis-fastbuffer.md)）

- 新增支持以动态序列化方式生成XML文件。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-arkts/js-apis-xml.md)）


### 基础通信

Wi-Fi新增支持连接候选网络时提示确认是否信任该网络，并提供确认的回调。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-connectivity-kit/js-apis-wifiManager.md#wifimanagerconnecttocandidateconfigwithuseraction20)）


### 位置服务

新增支持获取两个位置之间直线距离的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetdistancebetweenlocations20)）


### 多模输入

- 新增C API支持获取当前屏幕上鼠标的坐标点。（[API参考](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_getpointerlocation)）

- 新增C API支持查询设备支持的最大触屏报点数。（[API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_querymaxtouchpoints)）

- 新增C API支持设置和查询鼠标事件、触屏事件在指定屏幕上的相对坐标系。详情可在[API参考](https://gitcode.com/openharmony/docs/blob/ad4d1941c726b56c89948c689ad5cd8b2391ca15/zh-cn/application-dev/reference/apis-input-kit/capi-oh-input-manager-h.md)中搜索关键字“相对坐标系”。

### DFX

- 新增使用HiDebug对应用主线程进行栈回溯的能力。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/dfx/hidebug-guidelines-ndk.md#%E4%BD%BF%E7%94%A8hidebug%E5%AF%B9%E5%BA%94%E7%94%A8%E4%B8%BB%E7%BA%BF%E7%A8%8B%E8%BF%9B%E8%A1%8C%E6%A0%88%E5%9B%9E%E6%BA%AF)）

- 支持sanitizer事件对接到HiAppEvent。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/dfx/hiappevent-watcher-address-sanitizer-events.md)）

- CPP_CRASH事件支持通过SetEventConfig接口设置参数控制日志内容。（[指南](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/dfx/hiappevent-watcher-crash-events.md#%E5%B4%A9%E6%BA%83%E6%97%A5%E5%BF%97%E8%A7%84%E6%A0%BC%E8%87%AA%E5%AE%9A%E4%B9%89%E5%8F%82%E6%95%B0%E8%AE%BE%E7%BD%AE)）

- 针对包含页面切换的应用，故障日志文件将包含页面切换历史轨迹。（[指南](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/dfx/cppcrash-guidelines.md#%E6%9C%89%E9%A1%B5%E9%9D%A2%E5%88%87%E6%8D%A2%E8%BD%A8%E8%BF%B9%E7%9A%84%E6%95%85%E9%9A%9C%E5%9C%BA%E6%99%AF%E6%97%A5%E5%BF%97%E8%A7%84%E6%A0%BC)）

- 新增addProcessorFromConfig接口，支持异步添加数据处理者和及其配置信息。（[API参考](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventaddprocessorfromconfig20)）

- HiAppEvent的C API新增EVENT_APP_KILLED接口，订阅应用查杀事件。（[API参考](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-performance-analysis-kit/capi-hiappevent-event-h.md#event_app_killed)）

### 升级

支持流式物理AB升级，支持边下载边升级安装，减少用户设备存储空间的占用。（[说明文档](https://gitee.com/openharmony/update_updater/blob/master/README_zh.md)）


### 媒体

- 针对直播场景新增支持高画质ROI编码。（[指南](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/media/avcodec/video-encoding-ROI.md)）

- 图片编创支持纹理数据作为输入输出，纹理可以自定义。（[指南](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/media/image/image-effect-guidelines.md)）

- 支持查询获取网络流的媒体元信息和缩略图。

- 支持相机白平衡功能查询和设置。

- 新增相机压力管控接口，用于上报系统压力状态。

### 音频

- 升级音频引擎2.0，提升整体运行效率并降低播放时延。

- 新增音频工作组管理的能力，应用可以提升自身音频线程的系统供给，从而获取更好的音频处理性能。（[指南](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/media/audio/audio-workgroup.md)）

- 新增支持音频低时延耳返的能力，可将音频以更低时延的方式实时传输到有线耳机中。（[指南](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/media/audio/audio-ear-monitor-loopback.md)）

- 新增星闪音频设备播放和录制能力，支持应用获取当前音频的输出类型为星闪设备类型。（[API参考]()）

- 新增为直播场景打造的高清AEC录音能力，支持应用使用新增的直播录音流类型。（[API参考]()）


### 安全

- 证书管理新增openAuthorizeDialog接口，支持拉起用户证书凭据授权界面，用户授权后应用可使用授权的证书凭据进行双向TLS认证或文档签名。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog20)）

- 加解密算法库框架提供了非对称加解密、签名、密钥协商、密钥派生、消息认证码、随机数的C接口；提供了ASN1格式和R|S格式的sm2签名数据互转能力；新增支持DES算法。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/security/CryptoArchitectureKit/Readme-CN.md)）

- 证书算法库支持获取utf-8编码的证书或证书吊销列表的颁发者名称。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-device-certificate-kit/js-apis-cert.md#tostring20)）

- 证书链校验新增支持信任系统预置的根证书。（[API参考](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-device-certificate-kit/js-apis-cert.md#certchainvalidationparameters11)）

### 网络管理

新增C API，支持网络探测（[API参考](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-network-kit/capi-net-connection-h.md#oh_netconn_queryproberesult)）和网络跟踪路由（[API参考](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-network-kit/capi-net-connection-h.md#oh_netconn_querytraceroute)）。

### 测试框架

- 新增白盒性能测试框架，支持针对应用指定代码段CPU/内存占用、应用冷启动响应时间、滑动场景帧率的度量能力。（[API参考](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/zh-cn/application-dev/reference/apis-test-kit/js-apis-perftest.md)）

- UI测试框架新增支持多屏场景指定屏幕查找控件和模拟操作能力。（[API参考](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/zh-cn/application-dev/reference/apis-test-kit/js-apis-uitest.md#belongingdisplay20)）

- UI测试框架新增支持文本输入场景可选追加输入能力。（[API参考](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/zh-cn/application-dev/reference/apis-test-kit/js-apis-uitest.md#inputtextmode20)）

### 输入法框架

- 悬浮软键盘和候选词窗口新增支持startMoving。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-ime-kit/js-apis-inputmethodengine.md#startmoving15)）

- 新增支持通过hdc命令管理输入法。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/inputmethod/inputmethod-hdc-commands-guide.md)）

- 新增支持编辑框放弃正在输入的文字。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#discardtypingtext20)）

- 新增支持感知到编辑框中的占位文本和所属Ability的名字。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-ime-kit/js-apis-inputmethodengine.md#editorattribute)）

- 新增支持短信验证码编辑框。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#textinputtype10)）

- 新增支持自动大小写模式。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-6.0-Beta1/zh-cn/application-dev/reference/apis-ime-kit/js-apis-inputmethodengine.md#capitalizemode20)）

### 上传下载

支持设置任务超时、限速，支持下载数据到公共文件。（[API参考](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-request.md#minspeed20)）

### 电源管理

- 新增系统接口，支持刷新设备活动状态（如：重设屏幕超时息屏时间等）。（[API参考](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-power-sys.md#powerrefreshactivity20)）

- 电源模式的枚举新增自定义省电模式。（[API参考](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-power.md#devicepowermode9)）


## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 | 
| -------- | -------- | -------- |
| OpenHarmony | 6.0 Release | NA | 
| Public SDK | Ohos_sdk_public 6.0.0.47 (API Version 20 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 | 
| HUAWEI DevEco Studio（可选） | 6.0.0 Release | OpenHarmony应用开发推荐使用。<br />*待发布后提供*。 | 
| HUAWEI DevEco Device Tool（可选） | 4.0 Release | OpenHarmony智能设备集成开发环境推荐使用。<br />[请点击这里获取](https://device.harmonyos.com/cn/develop/ide#download)。 | 


## 源码获取


### 前提条件

1. 注册码云gitee帐号。

2. 注册码云SSH公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)。

3. 安装[git客户端](https://gitee.com/link?target=https%3A%2F%2Fgit-scm.com%2Fbook%2Fzh%2Fv2%2F%25E8%25B5%25B7%25E6%25AD%25A5-%25E5%25AE%2589%25E8%25A3%2585-Git)和[git-lfs](https://gitee.com/vcs-all-in-one/git-lfs?_from=gitee_search#downloading)并配置用户信息。
   ```
   git config --global user.name "yourname"
   git config --global user.email "your-email-address"
   git config --global credential.helper store
   ```

4. 安装码云repo工具，可以执行如下命令。
   ```
   curl -s https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > /usr/local/bin/repo  #如果没有权限，可下载至其他目录，并将其配置到环境变量中chmod a+x /usr/local/bin/repo
   pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
   ```


### 通过repo获取

**方式一（推荐）**

通过repo + ssh 下载（需注册公钥，请参考[码云帮助中心](https://gitee.com/help/articles/4191)）。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-6.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v6.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-6.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v6.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取


**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 6.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/6.0-Release/code-v6.0-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/6.0-Release/code-v6.0-Release.tar.gz.sha256) | -- GB |
| Hi3861解决方案（二进制）        | 6.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/6.0-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/6.0-Release/hispark_pegasus.tar.gz.sha256) | -- MB |
| Hi3516解决方案-LiteOS（二进制） | 6.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/6.0-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/6.0-Release/hispark_taurus_LiteOS.tar.gz.sha256) | -- MB |
| Hi3516解决方案-Linux（二进制）  | 6.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/6.0-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/6.0-Release/hispark_taurus_Linux.tar.gz.sha256) | -- MB |
| RK3568标准系统解决方案（二进制）        | 6.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/6.0-Release/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/6.0-Release/dayu200_standard_arm32.tar.gz.sha256) | 	-- GB |
| 标准系统Public SDK包（Mac）             | 6.0.0.47 | [站点](https://repo.huaweicloud.com/openharmony/os/6.0-Release/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/6.0-Release/ohos-sdk-mac-public.tar.gz.sha256) | -- GB |
| 标准系统Public SDK包（Mac-M1）             | 6.0.0.47  | [站点](https://repo.huaweicloud.com/openharmony/os/6.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/6.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | -- GB |
| 标准系统Public SDK包（Windows/Linux）   | 6.0.0.47   | [站点](https://repo.huaweicloud.com/openharmony/os/6.0-Release/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/6.0-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | -- GB |


## 修复缺陷列表

**表3** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 | 
| ------- | ------- |
| ICAWPJ | 执行XTS测试时，在之前的case注册了on的callback（其中callback是一个case的局部函数），之后没有通过off解除注册，在后面的case也触发了此callback，但是因其引用的js函数已经析构，导致执行结果出现失败项。 |
| ICD55I | 执行XTS测试时，ActsTelephonyContactTest测试套因RK3568开发板因联系人服务获取datashare超时限制过长导致执行结果出现失败项。 |
| ICENKX | 执行XTS测试时，创建资产接口业务码未做区分导致执行结果出现失败项。 |
| ICE0E0 | 进程com.ohos.systemui有较大概率出现因INPUT_EVENT_SOCKET_TIMEOUT导致的sysfreeze问题。 |
| ICCUL7 | 进程/system/bin/bootanimation下的OS_IPC_1_743线程有一定概率出现因libaccessibilityconfig.z.so崩溃导致的cppcrash。 |
| ICCXYS | 进程foundation下的OS_IPC_6_979线程小概率出现因libhilog.so崩溃导致的cppcrash。 | 系统异常，重启可恢复。 | 2025年7月30日 | 


## 遗留缺陷列表

**表4** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 | 
| -------- | -------- | -------- | -------- |
| ICW13P | 仿抖音滑动评论区帧率43 FPS，不满足基线要求。 | 轻微影响使用体验。 | 2025年9月30日 |
| ICW0P4 | 开机完成时延较前一版本稍有劣化。 | 轻微影响使用体验。 | 2025年9月30日 |
| ICW129 | 联系人列表滑动帧率42 FPS，不满足基线要求。| 轻微影响使用体验。 | 2025年12月30日 |
| ICV8O8 | 进程com.ohos.systemui在wukong压测下出现内存泄露。 | 系统异常，重启可恢复。 | 2025年9月30日 |
| ICWA4N<br />ICWA56 | 进程com.ohos.mms小概率出现因anonymous或deleteAction导致的jscrash。 | 短信应用异常闪退，重启应用可恢复。 | 2025年9月30日 |
| ICUCVF | 进程/system/bin/hilogd下的hilogd.server线程小概率出现cppcrash。 | 使用HiLog记录日志可能出现异常，重启可恢复。 | 2025年9月30日 |
| ICW9XX | 进程com.ohos.contacts下的m.ohos.contacts线程小概率出现因libace_compatible.z.so导致的cppcrash。 | 联系人应用异常闪退，重启应用可恢复。 | 2025年9月30日 |

<!--no_check-->