# OpenHarmony 5.0.3 Release


## 版本概述

OpenHarmony 5.0.3 Release版本对标准系统的能力进行持续完善，以快速迭代的方式推出API 15，相比5.0.2 Release版本，重点做出了如下特性新增或增强：

进一步增强ArkUI，提供更多组件的高级属性设置，支持更多精致动效；针对2in1设备和可能的外接多屏幕增强了窗口管理的能力，以支持更多类型设备屏幕或窗口状态下应用的体验；分布式数据管理的UDMF能力进一步增强，同时新增智慧数据平台，提供端侧的数据智慧化能力；新增支持更多外接设备，如游戏手柄等。

[OpenHarmony 5.0.1(API 13)](./OpenHarmony-v5.0.1-release.md)和[OpenHarmony 5.0.2(API 14)](./OpenHarmony-v5.0.2-release.md)均为快速迭代版本，可查阅对应的版本说明进一步了解。

更详细的特性新增与增强的说明如下：


### 应用框架

- 在C API新增组件启动参数Want的定义与接口。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-ability-kit/_ability_base.md)）

- 新增支持根据指定的物理屏幕ID创建应用上下文的能力，以便于获取和使用其他带有屏幕信息。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-inner-application-context.md#contextcreatedisplaycontext15)）

- 新增支持通过C API拉起UIAbility的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-ability-kit/_ability_runtime.md#oh_abilityruntime_startselfuiability)）

- 新增支持应用预关闭的回调方法，可用于询问用户选择立即执行操作还是取消操作。（[API参考-UIAbility](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#uiabilityonpreparetoterminateasync15)、[API参考-AbilityStage](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#abilitystageonprepareterminationasync15)）


### ArkUI

- 路由导航能力增强。包括：
  - Navigation新增支持自定义开启或关闭单双栏显示切换时的动效。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#enablemodechangeanimation15)）
  - NavDestination新增页面返回时的回调，用于处理pop携带的返回参数（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#onresult15)）、新增支持设置是否隐藏标题栏中的返回键（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#hidebackbutton15)）。
  - NavDestination新增单页面自定义转场动画设置能力（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#customtransition15)）、新增系统转场动画类型枚举（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#navigationsystemtransitiontype14%E6%9E%9A%E4%B8%BE%E8%AF%B4%E6%98%8E)）。

- 文本与输入组件能力增强。包括：
  - TextInput/TextArea/Search组件新增支持配置不拦截返回键操作（onBackPressed）的回调。（[API参考-TextInput](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md#stopbackpress15)、[API参考-TextArea](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md#stopbackpress15)、[API参考-Search](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-search.md#stopbackpress15)）
  - TextInput/TextArea/Search组件新增支持在文本内容将要发生变化时触发回调。（[API参考-TextInput](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md#onwillchange15)、[API参考-TextArea](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md#onwillchange15)、[API参考-Search](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-search.md#onwillchange15)）
  - 属性字符串新增支持ResourceStr类型图片的设置（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-styled-string.md#resourceimageattachmentoptions15)）、属性字符串的图片对象新增支持获取属性字符串的图片颜色滤镜效果（colorFilter）（[API参考-RichEditor](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-styled-string.md#imageattachment)）。
  - 文本编辑类组件（TextInput/TextArea/Search/RichEditor）新增支持设置键盘外观。（[API参考-TextInput](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md#keyboardappearance15)、[API参考-TextArea](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md#keyboardappearance15)、[API参考-Search](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-search.md#keyboardappearance15)、[API参考-RichEditor](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-richeditor.md#keyboardappearance15)）
  - 组件新增支持在已编辑文本的指定位置插入文本和删除指定区域内容的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-types.md#addtext15)）

- 图片与视频组件能力增强。包括：
  - Image新增支持传入[ColorContent](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-image.md#colorcontent15)类型重置填充颜色，仅针对SVG格式的图源生效（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-image.md#fillcolor15)）。
  - Image新增支持按图片矩阵做自动变换，在类似图库的场景呈现宫格型缩略图时提供自动的变换优化。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-image.md#imagematrix15)）
  - Video组件新增支持设置对快捷键的响应。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-media-components-video.md#enableshortcutkey15)）

- 弹窗能力增强。包括：
  - 弹窗新增支持设置弹窗页面内显示及相关效果的属性（levelMode、levelUniqueId、immersiveMode）。（[API参考-PromptAction](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#promptaction)、[API参考-自定义弹窗](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md#customdialogcontrolleroptions%E5%AF%B9%E8%B1%A1%E8%AF%B4%E6%98%8E)、[API参考-showAlertDialog](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#showalertdialog)、[API参考-showActionSheet](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#showactionsheet)）
  - bindSheet新增支持圆角（radius）属性，用于设置半模态页面圆角半径；新增支持非手势切换挡位（detentSelection）属性。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetoptions)）
  - Popup组件新增keyboardAvoidMode属性用于设置Popup气泡是否避让软键盘。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-popup.md#popupoptions%E7%B1%BB%E5%9E%8B%E8%AF%B4%E6%98%8E)）
  - 弹窗新增支持设置避让键盘的距离。其中ArkTS API均以属性方式提供，可在链接指向的表格中搜索关键词keyboardAvoidDistance。（[API参考-C API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_dialog_a_p_i__2.md#setkeyboardavoiddistance)、[API参考-自定义弹窗ArkTS API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md#customdialogcontrolleroptions%E5%AF%B9%E8%B1%A1%E8%AF%B4%E6%98%8E)、[API参考-弹窗模块ArkTS API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-promptAction.md#basedialogoptions11)）

- 视图切换组件能力增强。包括：
  - Swiper和Tabs组件新增支持带动画跳转的模式、（[API参考-Swiper组件C API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_swiperanimationmode)、[API参考-Swiper组件ArkTS API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-container-swiper.md#swiperanimationmode15%E6%9E%9A%E4%B8%BE%E8%AF%B4%E6%98%8E)、[API参考-Tabs组件ArkTS API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-container-tabs.md#animationmode12%E6%9E%9A%E4%B8%BE%E8%AF%B4%E6%98%8E)）、
     新增支持设置鼠标滚轮翻页模式。（[API参考-Tabs组件](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-container-tabs.md#pageflipmode15)、[API参考-Swiper组件](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-container-swiper.md#pageflipmode15)）。
  - Swiper组件新增支持滑动行为拦截事件，可判断是否允许滑动行为。其中，C API通过属性控制，属性名NODE_SWIPER_EVENT_ON_CONTENT_WILL_SCROLL。（[API参考-C API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype)、[API参考-ArkTS API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-container-swiper.md#oncontentwillscroll15)）
  - Tabs组件新增组件参数，支持设置TabBar的通用属性。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-container-tabs.md#tabsoptions15)）

- UIContext新增如下能力。包括：
  - 新增支持设置OverlayManager的参数，可设置是否需要渲染overlay根节点等属性。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#setoverlaymanageroptions15)）
  - 新增支持通过uniqueId获取已加载的组件的截图（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#getwithuniqueid15)）。
  - 支持获取元服务menuBar相对窗口的布局信息的能力（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#getbarrect15)）。
  - 拖拽能力新增支持获取拖拽进度条拖拽数据的能力。（[API参考-C API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_dragevent_startdataloading)、[API参考-ArkTS API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#canceldataloading15)）

- C API通用能力增强。包括：
  - 新增C API支持组件布局完成和组件绘制完成的回调方法。（[API参考-组件布局完成回调](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_registerlayoutcallbackonnodehandle)、[API参考-组件绘制完成回调](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_registerdrawcallbackonnodehandle)）
  - 新增C API属性样式NODE_IMMUTABLE_FONT_WEIGHT，支持设置文字粗细属性不跟随系统字体粗细而变化。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeattributetype)）
  - C API的Node属性样式新增背景模糊效果属性NODE_BACKDROP_BLUR。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeattributetype)）
  - 新增C API支持控制焦点以及处理焦点事件的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/native__interface__focus_8h.md)）
  - 新增C API支持克隆事件的转发。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___event_module.md#oh_arkui_pointerevent_postclonedevent)）
  - 通用事件新增C API支持获取当前触摸事件触发的ID。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___event_module.md#oh_arkui_pointerevent_getchangedpointerid)）
  - 支持C API组件截图能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_getnodesnapshot)）
  - 新增支持NODE_CHECKBOX_GROUP相关能力。可在API参考中搜索该关键字。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md)）

- 新增支持获取触摸相关的事件来自左手还是右手，涉及多个数据对象：
  - 绑定手势方法FingerInfo对象新增hand属性。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-gesture-settings.md#fingerinfo%E5%AF%B9%E8%B1%A1%E8%AF%B4%E6%98%8E8)）
  - 触摸事件TouchObject对象新增hand属性。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-events-touch.md#touchobject%E5%AF%B9%E8%B1%A1%E8%AF%B4%E6%98%8E)）
  - 点击事件ClickEvent对象新增hand属性。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-events-click.md#clickevent%E5%AF%B9%E8%B1%A1%E8%AF%B4%E6%98%8E)）

- 手势响应新增支持限制手指数量：
  - NDK新增相关C API。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_setgesturerecognizerlimitfingercount)）
  - 手势接口新增设置是否检查触摸屏幕的手指数量的属性isFingerCountLimited。可在各接口参考页面中查看该属性。（[API参考-长按手势事件](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-longpressgesture.md)、[API参考-滑动手势事件](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-pangesture.md)、[API参考-捏合手势事件](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-pinchgesture.md)、[API参考-旋转手势事件](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-rotationgesture.md)、[API参考-滑动事件](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-swipegesture.md)、[API参考-单击双击和多次点击事件](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-tapgesture.md)）

- 新增支持设置按键事件处理的优先级和重新派发的能力。涉及：
  - NDK新增设置按键事件处理优先级的C API。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_focussetkeyprocessingmode)）
  - NDK中ArkUI_NodeEventType枚举新增NODE_DISPATCH_KEY_EVENT，表示组件按键事件重新派发事件（C API）。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype)）
  - UIContext新增设置按键事件处理优先级的ArkTS API。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#setkeyprocessingmode15)）
  - UIContext新增分发按键事件给指定组件的ArkTS API。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#dispatchkeyevent15)）

- TextPicker组件新增支持滑动过程中不使能文本样式动效和默认文本样式配置。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textpicker.md#disabletextstyleanimation15)）

- Progress组件新增C API，支持线性进度条样式的设置。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_progresslinearstyleoption_create)）

- FrameNode新增支持跨语言能力（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-frameNode.md#setcrosslanguageoptions15)）、新增支持选择遍历节点时子节点的展开模式（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-frameNode.md#expandmode15)）。

- 新增导航点组件，提供圆点导航点以及数字导航点两种导航点样式。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-swiper-components-indicator.md)）

- 三方平台接入ArkUI无障碍框架新增支持查找上一个或下一个焦点（ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_NEXT_HTML_ITEM、ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_PREVIOUS_HTML_ITEM）（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui_native_interface_accessibility.md#arkui_accessibility_actiontype)）、新增支持多实例场景（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui_native_interface_accessibility.md#arkui_accessibilityprovidercallbackswithinstance)）。

- ohos.arkui.observer模块NavDestination组件信息新增NavDestination类型和uniqueId。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-observer.md#navdestinationinfo)）

- 图案密码锁组件新增支持设置未选中的宫格圆点在密码路径经过时是否自动选中。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-patternlock.md#skipunselectedpoint15)）

- 通用事件新增焦点轴事件，支持对游戏手柄轴事件的响应（[API参考-C API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___event_module.md#oh_arkui_axisevent_getaxisaction)、[API参考-ArkTS API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-events-focus_axis.md)）；

- C API支持获取当前轴事件的操作类型值（[API参考-C API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___event_module.md#oh_arkui_focusaxisevent_getaxisvalue)）。

- 尺寸设置新增支持设置宽度、高度适应父组件布局。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#width15)）

- 组件截图能力新增支持定义组件截图区域。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-componentSnapshot.md#snapshotregion15)）

- 安全组件支持设置图标文本的对齐方式（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-securitycomponent-attributes.md#align15)）、支持分别设置边框四个圆角的半径（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-securitycomponent-attributes.md#borderradius15)）。


### 窗口管理

- 新增支持获取画中画窗口的信息，如ID和尺寸。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-pipWindow.md#getpipwindowinfo15)）

- 新增支持获取指定屏幕上可见的窗口布局的信息。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#windowgetallwindowlayoutinfo15)）

- 新增支持获取当前窗口所在屏幕的显示大小缩放系数的信息（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#getwindowdensityinfo15)），支持设置本窗口所处屏幕的系统显示大小缩放系数变化事件的监听（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#onsystemdensitychange15)），支持应用主窗口自定义其显示大小缩放系数（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#setcustomdensity15)）。

- 新增窗口移动选项的定义，当前可定义屏幕ID，支持在移动窗口时移动到其他屏幕。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#movewindowtoasync15)）

- 新增定义窗口管理的C API，主要用于设置和获取指定窗口的属性，以及设置指定窗口的状态栏样式、导航栏样式。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/oh__window_8h.md)）

- 屏幕属性模块折叠屏状态枚举新增多个针对折轴二的状态定义。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-display.md#foldstatus10)）

- 新增一个针对2in1设备用于设置应用窗口尺寸限制的同名接口。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#setwindowlimits15)）

- 新增一个用于指定鼠标在窗口内的位置并移动窗口的同名接口。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#startmoving15)）

- 新增针对2in1设备的窗口关闭事件监听的异步回调。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#onwindowwillclose15)）

- 新增支持开启画中画窗口尺寸变化事件的监听。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-pipWindow.md#onpipwindowsizechange15)）

- 新增支持动态设置窗口标题栏的标题。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#setwindowtitle15)）

- 新增设置主窗的窗口支持模式（全屏、悬浮窗、分屏等模式）。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#setsupportedwindowmodes15)）


### 应用包管理

包管理应用信息（ApplicationInfo）中，应用程序安装来源（installSource）定义增强，新增ota、recovery、安装包名三类安装来源。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-bundleManager-applicationInfo.md#applicationinfo-1)）


### 分布式数据管理

- UDMF新增支持添加指定数据类型和内容的数据，同时新增对应的查询接口。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkdata/js-apis-data-unifiedDataChannel.md#addentry15)）

- 新增智慧数据平台，提供端侧的数据智慧化能力，完成数据和AI智能在端侧闭环。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/database/aip-data-intelligence-overview.md)、[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkdata/js-apis-data-intelligence.md)）

- UDMF新增支持获取进度信息和数据的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkdata/js-apis-data-unifiedDataChannel.md#dataprogresslistener15)）


### 文件管理

- 新增原子文件的定义和操作能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-core-file-kit/js-apis-file-fs.md#atomicfile15)）

- 新增支持获取设备内置存储总大小和可用大小。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-core-file-kit/js-apis-file-storage-statistics.md#storagestatisticsgettotalsize15)）

- 文件信息属性Stat新增上次访问时间（atimeNs）、上次修改时间（mtimeNs）、最近文件状态变更的时间（ctimeNs）三个属性。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-core-file-kit/js-apis-file-fs.md#stat)）

- 文件选择器新增支持批量授权文件的能力。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/file-management/select-user-file.md#%E9%80%89%E6%8B%A9%E6%96%87%E6%A1%A3%E7%B1%BB%E6%96%87%E4%BB%B6)、[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-core-file-kit/js-apis-file-picker.md#documentselectoptions)）


### 媒体

**视频编码**


新增C API支持视频可变帧率的能力。（[指南](https://gitee.com/openharmony/docs/blob/f739c4f14db24d32f2e3bd90aaee89bead285430/zh-cn/application-dev/media/avcodec/video-variable-refreshrate.md)）


**图片处理**


- 新增从Surface id创建PixelMap对象的方法，相比原有方法，无需指定区域。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-image-kit/js-apis-image.md#imagecreatepixelmapfromsurface15)）

- 新增C API支持获取Pixelmap像素数据的内存地址。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_accesspixels)）


**屏幕录制**


- 屏幕录制的C API新增支持设置录屏内容是否显示光标。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-media-kit/_a_v_screen_capture.md#oh_avscreencapture_showcursor)）

- 屏幕录制新增支持获取录屏的屏幕ID的回调。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-media-kit/_a_v_screen_capture.md#oh_avscreencapture_setdisplaycallback)）


**相机**


- 新增支持获取分布式相机设备的类型。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-camera-kit/js-apis-camera.md#hostdevicetype15)）

- 新增支持镜像录像的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-camera-kit/js-apis-camera.md#enablemirror13)）


**媒体库**


新增支持通过photoPicker预览并替换相册中图片的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-media-library-kit/ohos-file-PhotoPickerComponent.md#replacephotopickerpreview15)）


### 图形图像

- 新增工具类Tool，用于处理ResourceColor类型的值向common2D.Color对象的转换。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkgraphics2d/js-apis-graphics-drawing.md#tool15)）

- 新增支持设置绘制字型的字体是否跟随主题字体的变化。（[API参考-C API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkgraphics2d/_drawing.md#oh_drawing_fontsetthemefontfollowed)、[API参考-ArkTS API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkgraphics2d/js-apis-graphics-drawing.md#setthemefontfollowed15)）

- 新增C API支持获取一类变换矩阵的能力，该变换矩阵根据生产端设置的旋转角度和buffer实际有效内容区域计算得出。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkgraphics2d/_o_h___native_image.md#oh_nativeimage_getbuffermatrix)）

- NativeBuffer支持的格式新增BLOB格式（NATIVEBUFFER_PIXEL_FMT_BLOB）和RGBA16 float格式（NATIVEBUFFER_PIXEL_FMT_RGBA16_FLOAT）。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_format-1)）


### 语言编译器运行时

一个进程最多创建的运行时环境数量从16个增加到64个，并且需要满足同时运行的Worker子线程数量和进程创建的运行时的总数不超过80个。


### 基础通信

- Wi-Fi新增支持Wi-Fi 7和Wi-Fi 7+类型的网络。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-connectivity-kit/js-apis-wifiManager.md#wificategory12)）

- Wi-Fi新增支持查询热点是否处于活跃状态。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-connectivity-kit/js-apis-wifiManager.md#wifimanagerishotspotactive15)）

- 面向企业应用开放wifiManager模块的Wi-Fi管理能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-connectivity-kit/js-apis-wifiManager.md#wifimanagerenablewifi15)）


### 网络管理

新增支持设置系统级代理自动配置（PAC）脚本地址。（[API参考-C API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-network-kit/_net_connection.md#oh_netconn_setpacurl)、[API参考-ArkTS API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-network-kit/js-apis-net-connection.md#connectionsetpacurl15)）


### DFX

- HiLog支持设置应用打印的最低日志级别。（[API参考-C API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-performance-analysis-kit/_hi_log.md#oh_log_setminloglevel)、[API参考-ArkTS API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-performance-analysis-kit/js-apis-hilog.md#hilogsetminloglevel15)）

- 新增支持通过hdc访问debug应用的沙箱，以读取调测状态下应用沙箱中的日志及资源。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/dfx/hdc.md#%E6%89%A7%E8%A1%8C%E4%BA%A4%E4%BA%92%E5%91%BD%E4%BB%A4)）

- HiAppEvent对主线程超时事件的维测能力增强。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/dfx/hiappevent-watcher-mainthreadjank-events.md)、[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventseteventconfig15)）


### NDK

新增支持基于OpenMP库的开发能力。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/napi/openmp-overview.md)）


### 设备管理

- 新增支持游戏手柄设备的按键事件的识别和分发。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-input-kit/js-apis-keycode.md#keycode)）

- 新增支持动作感知能力，可对用户行为、动作进行感知。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/device/stationary/motion-guidelines.md)、[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-multimodalawareness-kit/js-apis-awareness-motion.md)）


### 企业定制

- 新增支持为指定的浏览器设置浏览器策略。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-mdm-kit/js-apis-enterprise-browser.md#browsersetmanagedbrowserpolicy15)）

- 新增支持设置指定用户下的网络代理（仅限2in1设备）。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-mdm-kit/js-apis-enterprise-networkManager.md#networkmanagersetglobalproxyforaccount15)）


### 输入法

- 新增支持查询输入法的启用状态。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#getinputmethodstate15)）

- 新增一系列API，用于支持输入法应用与输入框/编辑框的自定义通信。（[API参考-输入法框架](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#messagehandleronmessage15)、[API参考-输入法服务](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-ime-kit/js-apis-inputmethodengine.md#messagehandleronmessage15)）

- 新增支持移动输入法窗口的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-ime-kit/js-apis-inputmethodengine.md#startmoving15)）


### 剪贴板

剪贴板新增支持设置进度指示条。（[API参考-C API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-basic-services-kit/_pasteboard.md#oh_pasteboard_getdataparams_setprogressindicator)、[API参考-ArkTS API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-pasteboard.md#progressindicator15)）


### Web

新增支持对Cookie进行持久化的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-arkweb/js-apis-webview.md#savecookiesync15)）


### 上传下载

- 上传下载新增支持下载任务分组，并按分组显示通知。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-request.md#requestagentcreategroup15)）

- 上传下载支持的URL地址长度从2048个字符扩展到8192个字符。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-request.md#uploadconfig6)）

- 上传下载新增支持使用单个上传请求上传多文件，该能力通过Config的multipart参数配置。（[API参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-request.md#config10)）

- 上传下载新增支持自定义通知栏的信息。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-request.md#notification15)）


### 全球化

- 国际化支持的标准ICU C库（ICU4C）支持的语言新增Unicode字符串处理(ustring.h)、ICU文本抽象表示(utext.h)。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/native-lib/icu4c.md)）

- 新增支持获取语言的简化表示的能力，例如将"en-Latn-US"的简化表示为"en"。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-localization-kit/js-apis-i18n.md#getsimplifiedlanguage15)）


### 资源调度

新增支持长时任务取消的监听回调。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/zh-cn/application-dev/reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanageroncontinuoustaskcancel15)）


## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 | 
| -------- | -------- | -------- |
| OpenHarmony | 5.0.3 Release | NA | 
| Public SDK | Ohos_sdk_public 5.0.3.135 (API Version 15 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 | 
| HUAWEI DevEco Studio（可选） | 5.0.3 Release | OpenHarmony应用开发推荐使用。 | 
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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-5.0.3-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v5.0.3-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-5.0.3-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v5.0.3-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取


**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）<br />2025.7.3更新        | 5.0.3 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/code-v5.0.3-Release-20250702.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/code-v5.0.3-Release-20250702.tar.gz) | 43.3 GB |
| Hi3861解决方案（二进制）        | 5.0.3 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/hispark_pegasus.tar.gz.sha256) | 27.2 MB |
| Hi3516解决方案-LiteOS（二进制） | 5.0.3 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 328.7 MB |
| Hi3516解决方案-Linux（二进制）  | 5.0.3 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/hispark_taurus_Linux.tar.gz.sha256) | 221.4 MB |
| RK3568标准系统解决方案（二进制）        | 5.0.3 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/dayu200_standard_arm32.tar.gz.sha256) | 13.2 GB |
| 标准系统Public SDK包（Mac）             | 5.0.3.135 | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/ohos-sdk-mac-public.tar.gz.sha256) | 1.3 GB |
| 标准系统Public SDK包（Mac-M1）             | 5.0.3.135  | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 1.2 GB |
| 标准系统Public SDK包（Windows/Linux）   | 5.0.3.135   | [站点](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 4.3 GB |


## 修复缺陷列表

**表3** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 | 
| ------- | ------- |
| IANQF3 | 在执行WuKong压测过程有较高概率出现重启现象。 |
| IBJ6LH | 因新引入安全校验机制导致删除多张图片的处理时长可能过长，影响体验。 |
| IBDPFF | 进程intell_voice_service下的SaOndemand线程小概率出现cppcrash，崩溃栈：libintell_voice_server.z.so |

## 遗留缺陷列表

**表4** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 | 
| -------- | -------- | -------- | -------- |
| IBTXFK | 从图库删除多张图片的完整用时可能稍长（1000+ ms）。 | 轻微影响使用体验。 | 2025年4月30日 |
| IBTCKR | SystemUI状态栏下拉到内容渲染耗完成时的完整用时可能稍长（160+ ms）。 | 轻微影响使用体验。 | 2025年4月30日 |
| IBTCJQ | FWX图片放大缩小的移动帧率不足60帧。 | 轻微影响使用体验。 | 2025年4月30日 |
| IBBZPS | 进程com.ohos.systemui下的OS_IPC_0_1067线程小概率出现cppcrash，崩溃栈：ld-musl-arm.so.1(__libc_free+172) | 系统异常，用户无感知。 | 2025年4月30日 | 
| IBE36X</br>IBO3MF | 进程render_service小概率出现因SERVICE_BLOCK导致的的sysfreeze问题。 | 桌面无响应后黑屏，自动恢复后回到桌面。 | 2025年4月30日 |
| IBINUK | 进程com.ohos.camera有一定概率出现因LIFECYCLE_TIMEOUT卡在libcamera_framework.z.so导致的sysfreeze。 | 相机调用异常，重启可恢复。 | 2025年4月30日 |
