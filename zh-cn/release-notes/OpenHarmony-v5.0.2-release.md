# OpenHarmony 5.0.2 Release


## 版本概述

OpenHarmony 5.0.2 Release版本对标准系统的能力进行持续完善，以快速迭代的方式推出API 14，相比5.0.1 Release版本，重点做出了如下特性新增或增强：

进一步增强ArkUI、图形图像的能力，提供更多组件的高级属性设置，支持更多精致动效；进一步增强Web能力，满足更多应用诉求；针对2in1设备特点，新增一系列窗口管理和控制的能力及窗口生命周期行为管理；新增一批企业定制应用的能力，支持灵活管理企业定制应用，等等。

更详细的特性新增与增强的说明如下：


### 应用框架

- 针对2in1与平板设备，新增支持自定义应用启动时的启动页。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-app-ability-startOptions.md#%E5%B1%9E%E6%80%A7)）

- 通过Want传递对象间信息时支持在parameters参数中携带应用分身的索引（ohos.param.callerAppCloneIndex）。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-app-ability-want.md#%E5%B1%9E%E6%80%A7)）

- 新增支持获取应用级上下文的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-app-ability-application.md#applicationgetapplicationcontext14)）

- 开放包管理能力供三方应用调用。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-bundleManager.md)）

- 新增支持UIAbility备份恢复的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetrestoreenabled14)，[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/application-models/ability-recover-guideline.md)）

- 新增支持获取当前应用多实例的唯一实例标识。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextgetcurrentinstancekey14)）

- 环境变化信息的定义中新增当前系统字体的唯一ID的定义fontId。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-app-ability-configuration.md#%E5%B1%9E%E6%80%A7)）

- 新增C API，支持获取本应用适用的设备类型，用于判断应用是否可直接运行在2in1设备。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-ability-kit/_bundle.md#oh_nativebundle_getcompatibledevicetype)）


### ArkUI

- 路由导航能力增强。包括：
  - Navigation页面栈新增支持配置可在异常退出时恢复。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#recoverable14)）
  - NavDestination支持跟可滚动容器组件联动，当滑动可滚动容器组件时，会触发所有与其绑定的NavDestination组件的标题栏和工具栏的显示和隐藏动效。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#bindtoscrollable14)）
  - Navigation支持设置单个页面的系统转场动画枚举，支持分别设置系统标题栏动画和内容动画以及无动画。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#systemtransition14)）
  - 页面路由新增支持设置页面是否可恢复。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-router.md#routeroptions)）

- 文本与输入组件能力增强。包括：
  - 属性字符串新增支持设置文字背景色、支持设置为超链接、支持将有属性的字符串转换成HTML格式字符串的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-styled-string.md)）
  - ImageSpan组件新增支持为图像设置颜色滤镜效果。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-imagespan.md#colorfilter14)）
  - 支持获取文本组件中指定字符的绘制区域信息（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-text-common.md#getrectsforrange14)）、文本输入时的键盘避让模式支持光标避让（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#keyboardavoidmode11)）。
  - 文本选择器组件（TextPicker）新增支持滑动停止时的事件回调。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textpicker.md#onscrollstop14)）

- 滚动与滑动组件能力增强。包括：
  - 滚动组件新增支持设置滚动容器的内容层裁剪区域、支持设置边缘渐隐效果。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-container-scrollable-common.md)）
  - List组件新增支持配置是否显示预加载的ListItem/ListItemGroup。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-container-list.md#cachedcount14)）
  - Grid、WaterFlow组件新增新增支持配置是否显示预加载的GridItem、FlowItem。（[API参考-Grid](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-container-grid.md#cachedcount14)、[API参考-WaterFlow](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-container-waterflow.md#cachedcount14)）

- C API通用能力增强 。包括：
  - 支持为OH_NativeXComponent实例注册带有返回值的按键事件回调。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/_o_h___native_x_component.md#oh_nativexcomponent_registerkeyeventcallbackwithresult)）
  - 支持获取节点的各种自定义属性。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_nodeutils_getnodetype)）
  - NodeAttributeType新增获取滚动类组件及所有子组件全展开尺寸的C API属性定义。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeattributetype)）

- 按键事件新增unicode对象，支持返回当前keyEvent对应按键的unicode码值。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-events-key.md#keyevent%E5%AF%B9%E8%B1%A1%E8%AF%B4%E6%98%8E)）

- 半模态转场的SheetOptions新增enableHoverMode和hoverModeArea属性用于支持悬停。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetoptions)）

- 日期滑动选择器弹窗（DatePickerDialog）新增支持设置切换农历开关的样式。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-methods-datepicker-dialog.md#lunarswitchstyle14%E7%B1%BB%E5%9E%8B%E8%AF%B4%E6%98%8E)）

- 手势处理能力涉及到的六类手势事件新增支持设置允许的事件输入源（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-gesturehandler.md#allowedtypes14)）、FreamNode新增支持手势事件（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-frameNode.md#gestureevent14)）。

- 组件的位置设置新增支持对形成链的组件进行重新布局（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-location.md#chainweight14)）、组件的背景设置新增支持设置窗口失焦后窗口内控件模糊效果会被移除（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundeffectoptions11)）。

- 新增支持对容器设置组件级的安全区域。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#safeareapadding14)）

- Image组件新增支持设置图片的显示方向。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-image.md#orientation14)）


### 窗口管理

- 针对2in1设备的应用，新增通过应用窗口关闭按钮关闭应用的监听，使用该API可忽略已设置的预关闭开关的回调。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#onwindowstageclose14)）

- 针对2in1设备的应用，新增自定义应用主窗口大小和位置的能力，通过配置文件module.json5进行配置。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/quick-start/module-configuration-file.md#metadata%E6%A0%87%E7%AD%BE)）

- 针对2in1设备的应用，新增支持将应用从最小化恢复到前台显示的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#restore14)）

- 针对2in1设备的应用，新增支持查询本应用内指定坐标下的可见窗口的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#windowgetwindowsbycoordinate14)）

- 针对2in1设备的应用，新增支持使能/禁用通过拖拽方式缩放主窗口或子窗口。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#setresizebydragenabled14)）

- 针对2in1设备的应用，新增支持设置主窗口为模态窗口。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#setwindowmodal14)）

- 针对2in1设备的应用，新增支持应用控制启动页消失时机。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#removestartingwindow14)）

- 针对2in1设备的应用，新增支持设置主窗的尺寸记忆是否启用。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#setwindowrectautosave14)）

- 针对2in1设备的应用，新增支持设置主窗口进入全屏沉浸式时鼠标Hover到热区上隐藏窗口标题栏和dock栏。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#settitleanddockhovershown14)）

- 针对2in1设备的应用，新增支持设置主窗标题栏上的最大化、最小化、关闭按钮是否可见。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#setwindowtitlebuttonvisible14)）

- 针对2in1设备的应用，新增支持设置主窗口置于其他应用窗口之上而不被遮挡。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#setwindowtopmost14)）

- 针对2in1设备的应用，新增支持应用窗口无系统标题栏场景下拖拽移动窗口的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#startmoving14)）

- 新增支持设置窗口使用效果模板，比如使用有透视的背景模糊效果。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-use-effect.md#useeffect14)）

- 新增支持对窗口所在屏幕进行事件监听，例如当前窗口移动到其他屏幕时，可以调用此接口监听到这个行为。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#ondisplayidchange14)）

- 新增支持设置子窗的模态类型。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#setsubwindowmodal14)）


### 应用包管理

- HSP支持在配置文件中声明除入口Ability以外的UIAbility组件。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/quick-start/in-app-hsp.md#%E7%BA%A6%E6%9D%9F%E9%99%90%E5%88%B6)）

- 配置文件[module.json5中abilities标签](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/quick-start/module-configuration-file.md#abilities%E6%A0%87%E7%AD%BE)的orientation属性新增支持通过资源索引方式（$string）进行配置。

- 配置文件[module.json5中extensionAbilities标签](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/quick-start/module-configuration-file.md#extensionabilities%E6%A0%87%E7%AD%BE)的extensionProcessMode属性新增支持配置runWithMainProcess类型，表示该ExtensionAbility和应用主进程共进程。

- 配置文件[module.json5中extensionAbilities标签](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/quick-start/module-configuration-file.md#extensionabilities%E6%A0%87%E7%AD%BE)新增process属性，type为embeddedUI的ExtensionAbility可通过该属性的配置使ExtensionAbility和Ability运行在同一进程。


### 分布式数据管理

- 新增flushSync接口支持将缓存的Preferences实例中的数据存储到共享用户首选项的持久化文件中。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkdata/js-apis-data-sendablePreferences.md#flushsync14)）

- 关系型数据库（RDB）的配置属性StoreConfig新增参数cryptoParam，用于自定义加密参数。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkdata/js-apis-data-relationalStore.md#storeconfig)）

- 关系型数据库（RDB）新增支持创建可并发的事务对象。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkdata/js-apis-data-relationalStore.md)）

- 标准化数据结构（UDMF）新增内容卡片类型的数据结构（ContentForm）。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkdata/js-apis-data-uniformDataStruct.md#contentform14)）

- 标准化数据结构（UDMF）新增支持设置应用内拖拽通道数据可使用的范围。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddatachannelsetappshareoptions14)）


### 文件管理

- 新增支持获取保存成功后的文件后缀类型。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-core-file-kit/js-apis-file-picker.md#getselectedindex14)）


### 媒体


- 流媒体播放新增一批错误码以细化流媒体播放可能出现的异常场景。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-media-kit/js-apis-media.md#averrorcode9)）


- 播放控制新增支持投播半模态对象的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-avsession-kit/js-apis-avsession.md#avcastpickerhelper14)）


- 录屏新增C API支持设置录屏的最大帧率。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-media-kit/_a_v_screen_capture.md#oh_avscreencapture_setmaxvideoframerate)）


- 媒体库新增支持定义配置相册图片后的完成按钮，可显示“完成”、“发送”或“添加”。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-media-library-kit/js-apis-photoAccessHelper.md#completebuttontext14)）


- 媒体库Photo Picker组件新增支持视频播放状态的回调videoPlayStateChangedCallback。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-media-library-kit/ohos-file-PhotoPickerComponent.md#videoplayerstate14)）

- 媒体库Photo Picker组件新增支持大图页视频播放状态改变时的回调onVideoPlayStateChanged。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-media-library-kit/ohos-file-PhotoPickerComponent.md#photopickercomponent)）


- 相机新增C API和ArkTS API用于设置录像质量的优先级，提供高质量和功耗平衡两档选择。（[C API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-camera-kit/_o_h___camera.md#oh_capturesession_setqualityprioritization)、[ArkTS API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-camera-kit/js-apis-camera.md#setqualityprioritization14)）


### 图形

- 新增C API，支持获取系统全局字体集。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkgraphics2d/_drawing.md#oh_drawing_getfontcollectionglobalinstance)）

- 新增Decoupled VSync（DVSync）的C API能力以提高自绘制动画场景的流畅性。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkgraphics2d/_native_vsync.md#oh_nativevsync_dvsyncswitch)）

- 新增一个模糊效果的处理能力，增加着色器效果平铺模式，影响图像边缘的模糊效果。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkgraphics2d/js-apis-effectKit.md#blur14)）

- 新增C API，使浏览器支持动态帧率。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkgraphics2d/_native_vsync.md#oh_nativevsync_create_forassociatedwindow)）


### 安全

[非对称密钥生成和转换](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/security/CryptoArchitectureKit/crypto-asym-key-generation-conversion-spec.md#%E4%BD%BF%E7%94%A8%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%8F%82%E6%95%B0%E7%94%9F%E6%88%90-1)、[密钥协商](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/security/CryptoArchitectureKit/crypto-key-agreement-overview.md#ecdh)、[签名验签](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/security/CryptoArchitectureKit/crypto-sign-sig-verify-overview.md#ecdsa)所使用的ECC算法支持secp256k1曲线。


### 企业定制

- 企业应用禁用设备功能的能力新增支持禁用设备相机能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-mdm-kit/js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)）

- 企业应用安装事件新增一类回调，该回调返回的信息包括安装包名和账号ID。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-avcodec-kit/_codec_base.md#oh_aacprofile-1)）

- 企业应用新增支持委托其他应用来设置设备的管控策略。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-mdm-kit/js-apis-enterprise-adminManager.md#adminmanagersetdelegatedpolicies14)）

- 企业应用新增支持设置禁用/启用设备指纹功能，该能力目前仅限2in1设备使用。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-mdm-kit/js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccount14)）

- 企业应用新增支持设置禁用屏幕快照（即截屏）功能，该能力目前仅限2in1设备使用。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-mdm-kit/js-apis-enterprise-restrictions.md#restrictionsadddisallowedlistforaccount14)）

- 企业应用新增支持对应用设置水印的能力，该能力目前仅限2in1设备使用。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-mdm-kit/js-apis-enterprise-securityManager.md#securitymanagersetwatermarkimage14)）

- 企业应用新增支持“设备管理”应用添加保活的应用，该能力目前仅限2in1设备使用。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-mdm-kit/js-apis-enterprise-applicationManager.md#applicationmanageraddkeepaliveapps14)）

- 企业应用新增支持“设备管理”应用添加禁止使用的USB设备类型，该能力目前仅限2in1设备使用。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-mdm-kit/js-apis-enterprise-usbManager.md#usbmanageradddisallowedusbdevices14)）


### USB

USB管理新增支持检查应用程序是否有权访问USB配件。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-usbManager.md#usbmanagerhasaccessoryright14)）


### 输入法

输入法框架提供的编辑框属性新增编辑框所属应用的包名。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-ime-kit/js-apis-inputmethodengine.md#editorattribute)）


### 剪贴板

- 剪贴板新增支持通过MIME定义和使用多种格式的内容对象。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-pasteboard.md#pasteboardcreatedata14)）

- 剪贴板新增C API和ArkTS API支持获取剪贴板内容的MIME类型。（[C API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-basic-services-kit/_pasteboard.md#oh_pasteboard_getmimetypes)、[ArkTS API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-pasteboard.md#getmimetypes14)）


### Web

- 用户主动收起软键盘时，新增支持设置焦点从输入框转移到Web的body上，使文本框失焦。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#bluronkeyboardhidemode14)）

- 新增C API，用于获取调用JavaScriptProxy最后一帧的url。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkweb/_ark_web___controller_a_p_i.md#getlastjavascriptproxycallingframeurl)）

- 新增支持获取默认的用户代理。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkweb/js-apis-webview.md#getdefaultuseragent14)）

- 新增支持为指定url设置cookie的值。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkweb/js-apis-webview.md#configcookiesync14)）

- 新增支持上下左右四种嵌套滚动模式。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#nestedscroll11)）

- 新增支持根据指定的内存压力等级主动清理Web组件占用的缓存。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkweb/js-apis-webview.md#trimmemorybypressurelevel14)）

- 新增支持网页另存为PDF的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkweb/js-apis-webview.md#createpdf14)）

- 新增支持设置滚动动画的持续时间。（[API参考-scrollTo](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkweb/js-apis-webview.md#scrollto)、[API参考-scrollBy](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkweb/js-apis-webview.md#scrollby)）

- 新增支持设置滚动条常驻。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#forcedisplayscrollbar14)）


## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 | 
| -------- | -------- | -------- |
| OpenHarmony | 5.0.2 Release | NA | 
| Public SDK | Ohos_sdk_public 5.0.2.123 (API Version 14 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 | 
| HUAWEI DevEco Studio（可选） | 5.0.2 Release | OpenHarmony应用开发推荐使用。 | 
| HUAWEI DevEco Device Tool（可选） | 4.0 Release | OpenHarmony智能设备集成开发环境推荐使用。 | 


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-5.0.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v5.0.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-5.0.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v5.0.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取


**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 5.0.2 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/code-v5.0.2-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/code-v5.0.2-Release.tar.gz.sha256) | 42.5 GB |
| Hi3861解决方案（二进制）        | 5.0.2 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/hispark_pegasus.tar.gz.sha256) | 27.2 MB |
| Hi3516解决方案-LiteOS（二进制） | 5.0.2 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 328.4 MB |
| Hi3516解决方案-Linux（二进制）  | 5.0.2 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/hispark_taurus_Linux.tar.gz.sha256) | 221.2 MB |
| RK3568标准系统解决方案（二进制）        | 5.0.2 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/dayu200_standard_arm32.tar.gz.sha256) | 13.1 GB |
| 标准系统Public SDK包（Mac）             | 5.0.2.123 | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/ohos-sdk-mac-public.tar.gz.sha256) | 1.3 GB |
| 标准系统Public SDK包（Mac-M1）             | 5.0.2.123  | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 1.2 GB |
| 标准系统Public SDK包（Windows/Linux）   | 5.0.2.123   | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 4.0 GB |


## 修复缺陷列表

**表3** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 | 
| ------- | ------- |
| [33](https://gitcode.com/openharmony/applications_contacts/issues/33) | 进程com.ohos.contacts小概率出现因THREAD_BLOCK_6S卡在libark_jsruntime.so导致的appfreez。 |
| [174](https://gitcode.com/openharmony/communication_bluetooth/issues/174) | 进程com.ohos.settings有较高概率出现因THREAD_BLOCK_6S卡在libbtframework.z.so导致的appfreeze。 |
| [222](https://gitcode.com/openharmony/web_webview/issues/222) | 通过浏览器访问微博首页的滑动帧率低于规格基线。 |
| [9](https://gitcode.com/openharmony/applications_screenlock/issues/9) | RK3568开发板在执行WuKong整机随机压力测试过程有较高概率出现卡死现象。 |
| [4740](https://gitcode.com/openharmony/drivers_peripheral/issues/4740) | 进程com.ohos.camera有较高概率出现因LIFECYCLE_TIMEOUT卡在libcamera_framework.z.so导致的appfreeze。 |
| [11](https://gitcode.com/openharmony/resourceschedule_memmgr/issues/11) | 启动进程优先级过低有小概率会被优先kill掉导致出现sysfreeze。 |
| [33](https://gitcode.com/openharmony/applications_contacts/issues/33) | 进程com.ohos.contacts小概率因THREAD_BLOCK_6S卡在libark_jsruntime.so出现appfreeze。 |
| [231](https://gitcode.com/openharmony/applications_mms/issues/231) | 进程com.ohos.mms小概率出现jscrash，问题栈为close。 |


## 遗留缺陷列表

**表4** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 | 
| -------- | -------- | -------- | -------- |
| [481](https://gitcode.com/openharmony/kernel_linux_5.10/issues/481) | 在执行WuKong压测过程有较高概率出现重启现象。 | 问题出现会导致设备重启。<br/>该问题暂时无法规避。 | 2025年2月15日 | 
| [1619](https://gitcode.com/openharmony/distributeddatamgr_relational_store/issues/1619) | 因新引入安全校验机制导致删除多张图片的处理时长可能过长，影响体验。 | 不影响使用，无需规避。 | 2025年2月15日 | 
| [9238](https://gitcode.com/openharmony/multimedia_audio_framework/issues/9238) | 进程com.ohos.systemui下的OS_IPC_0_1067线程小概率出现cppcrash，崩溃栈：ld-musl-arm.so.1(__libc_free+172) | 系统异常，用户无感知。 | 2025年2月15日 | 
| [211](https://gitcode.com/openharmony/device_soc_rockchip/issues/211) | render_service小概率出现因SERVICE_BLOCK导致的的sysfreeze问题。 | 桌面无响应后黑屏，自动恢复后回到桌面。 | 2025年2月15日 | 
| [65](https://gitcode.com/openharmony/ai_intelligent_voice_framework/issues/65) | 进程intell_voice_service下的SaOndemand线程小概率出现cppcrash，崩溃栈：libintell_voice_server.z.so | 系统异常，用户无感知。 | 2025年2月15日 | 

