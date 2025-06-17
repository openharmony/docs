# OpenHarmony 5.1.0 Release


## 版本概述

OpenHarmony 5.1.0 Release版本正式推出API 18。相比前一个Release版本（OpenHarmony 5.0.3，即API 15），重点做出了如下特性新增或增强：

进一步增强ArkUI，提供更丰富的组件属性设置，支持更多精致动效，持续补充组件通过C API调用的能力；进一步增强媒体能力，提供更丰富的编解码能力、播控能力、媒体会话管理能力；进一步丰富了应用启动的细节设置能力；进一步增强分布式数据管理的UDMF、RDB的数据处理能力；进一步完善了标准Web能力；等等。

更详细的特性新增与增强的说明如下，将按照API版本顺序分别进行列举：

### 应用框架

- 新增支持根据指定的数据加密级别创建应用上下文，以获取相应的路径。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-inner-application-context.md#contextcreateareamodecontext18)）

- 新增支持同步获取当前进程的进程名（processName）。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-inner-application-context.md#%E5%B1%9E%E6%80%A7)）

- 新增支持获取应用被拉起原因（LAUNCH_REASON_MESSAGE）。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-app-ability-wantConstant.md#params)）

- 启动框架新增支持HAR/HSP和so文件。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/application-models/app-startup.md#支持的范围)、[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-app-appstartup-startupManager.md#ohosappappstartupstartupmanager)）

- 新增支持启动Ability时指定主窗口显示的最大宽高（maxWindowWidth/maxWindowHeight）和最小宽高（minWindowWidth/minWindowHeight）。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-app-ability-startOptions.md#%E5%B1%9E%E6%80%A7)）

- 新增支持获取应用上一次退出的详细原因。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/application-models/ability-exit-info-record.md)、[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-app-ability-abilityConstant.md#lastexitdetailinfo18)）

- 新增支持设置UIAbility的颜色模式。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetcolormode18)）

- 新增支持通过startAbility的属性startOptions来指定创建新窗口的大小（minWindowWidth、minWindowHeight、maxWindowWidth、maxWindowHeight）。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-ability-kit/js-apis-app-ability-startOptions.md#%E5%B1%9E%E6%80%A7)）

- C API新增支持启动Ability时传递startOptions。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-ability-kit/start__options_8h.md)）

- C API新增支持设置启动Ability时窗口和dock栏图标的显示模式。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-ability-kit/_ability_runtime.md#oh_abilityruntime_setstartoptionsstartvisibility)）

- 新增一批C API函数，用于获取应用级别沙箱内文件目录。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-ability-kit/_ability_runtime.md)）

### 应用包管理

配置文件module.json5新增重定向配置：通过abilitySrcEntryDelegator标识当前Module需要重定向到的UIAbility的名称，通过abilityStageSrcEntryDelegator标识当前Module需要重定向到的UIAbility对应的Module名称（不可为当前Module名称），两者组合使用，共同指定重定向的目标对象。 （[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/quick-start/module-configuration-file.md#%E9%85%8D%E7%BD%AE%E6%96%87%E4%BB%B6%E6%A0%87%E7%AD%BE)）

### ArkUI

- 文本与输入组件能力增强。包括：
  - 文本组件支持通过NODE_IMMUTABLE_FONT_WEIGHT属性，设置文字粗细不会跟随系统字体粗细而变化。（[API参考-C API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeattributetype)）
  - 文本组件支持对选中的文本提供分享服务（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-text-common.md#%E5%B1%9E%E6%80%A7)）、支持按音节连字符换行（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-appendix-enums.md#wordbreak11)）。
  - 文本组件新增支持设置文本选择菜单显示在独立窗口。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#textmenucontroller16)）
  - 富文本（RichEditor）组件支持设置最大行数。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-richeditor.md#maxlength18)）
  - TextInput组件支持设置文本省略位置。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md#ellipsismode18)）
  - TextInput/TextArea/Search/RichEditor组件支持将文本行间距平分至行的顶部与底部。（[API参考-TextInput](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md#halfleading18)、[API参考-TextArea](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md#halfleading18)、[API参考-Search](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-search.md#halfleading18)、[API参考-RichEditor](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-richeditor.md#richeditortextstyleresult)）
  - TextInput/TextArea组件扩展自动填充类型，包含：车牌号、护照号等。（[API参考-ArkTS](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md#contenttype12%E6%9E%9A%E4%B8%BE%E8%AF%B4%E6%98%8E)、[API参考-C](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_textinputcontenttype)）
  - 富文本（RichEditor）组件在长按预览菜单时支持振动效果。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-richeditor.md#previewmenuoptions18)）
  - 基础类型定义新增支持清除当前的预上屏文本内容。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-types.md#clearpreviewtext17)）

- 通用拖拽能力增强。包括：
  - 支持封装自定义落位动效。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#notifydragstartrequest18)，[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#executedropanimation18)）

  - 支持自定义控制在拖拽至可滚动组件边缘时是否触发自动滚屏。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-drag-drop.md#draginteractionoptions12)）

- 弹窗能力增强。包括：
  - 支持通过设置levelOrder来管理弹出框的显示顺序，确保层级较高的弹出框覆盖在层级较低的弹出框之上。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-promptAction.md#showdialogoptions)、[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/ui/arkts-dialog-levelorder.md)）
  - 支持在自定义内容中，创建和关闭对应的自定义弹窗。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#opencustomdialogwithcontroller18)）
  - Popup组件支持通过maxWidth设置最大宽度。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ohos-arkui-advanced-Popup.md#popupoptions)）
  - 半模态Popup样式弹窗，支持通过placement设置相对于目标的显示位置，通过placementOnTarget设置弹窗能否覆盖在目标节点上。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetoptions)）
  - Menu和Dialog支持通过backgroundBlurStyleOptions和backgroundEffect设置自定义背景模糊。（[API参考-Menu](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#contextmenuoptions10)、[API参考-Dialog](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-promptAction.md#showdialogoptions)）
  - 模态转场和MenuItem支持!!双向绑定变量。（[API参考-半模态转场](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet)、[API参考-全屏模态转场](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-modal-transition.md#bindcontentcover)、[API参考-MenuItem](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-menuitem.md#selected)）
  - 自定义弹窗支持避让键盘后，通过keyboardAvoidDistance设置弹窗和键盘之间的最小距离。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md#customdialogcontrolleroptions%E5%AF%B9%E8%B1%A1%E8%AF%B4%E6%98%8E)、[API参考-C](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_dialog_a_p_i__2.md)）
  - 支持通过showInSubWindow设置半模态是否在子窗中显示、支持通过effectEdge设置半模态面板边缘滚动的效果。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetoptions)）
  - 菜单（Menu）在弹出时支持振动效果。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#hapticfeedbackmode18)）

- 表单选择类组件能力增强。包括：
  - 新增SegmentButtonV2组件，可创建页签型、单选或多选的胶囊型分段按钮。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ohos-arkui-advanced-SegmentButtonV2.md)）
  - TextPicker/TimePicker支持选项进入选中区域时触发事件回调。（[API参考-TextPicker](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textpicker.md#onenterselectedarea18)、[API参考-TimePicker](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-timepicker.md#onenterselectedarea18)）
  - TimePicker/CalendarPicker支持通过start和end配置开始时间和结束时间（[API参考-TimePicker](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-timepicker.md#timepickeroptions%E5%AF%B9%E8%B1%A1%E8%AF%B4%E6%98%8E)、[API参考-CalendarPicker](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-calendarpicker.md#calendaroptions%E5%AF%B9%E8%B1%A1%E8%AF%B4%E6%98%8E)）。
  - TimePicker支持通过enableCascade设置12小时制时上午下午跟随时间联动。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-timepicker.md#enablecascade18)）

- 滚动与滑动组件能力增强。包括：
  - Swiper/Tabs组件增加页面选中元素改变时触发的回调，返回当前选中或将要隐藏的元素的索引值。（[API参考-Swiper](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-container-swiper.md)、[API参考-Tabs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-container-tabs.md)）
  - Swiper组件增加控制手指或者鼠标等按下屏幕时子组件是否停止自动播放的能力。（[API参考-Swiper](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-container-swiper.md#onunselected18)）
  - Swiper组件CAPI能力增强，可设置缓存节点是否显示、数字导航点和导航箭头的样式。（[API参考-CAPI](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md)）
  - List组件支持设置布局样式和滚动效果（NODE_LIST_SCROLL_TO_INDEX_IN_GROUP、 NODE_LIST_LANES、NODE_LIST_SCROLL_SNAP_ALIGN、NODE_LIST_MAINTAIN_VISIBLE_CONTENT_POSITION）（[API参考-CAPI](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeattributetype)）。

- 新增C API，支持可配置用户自定义数据的手势中断事件回调函数。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_gesture_a_p_i__2.md)）

- 新增C API，支持获取事件命中组件的宽高和坐标信息。（[API参考-CAPI](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___event_module.md#%E5%87%BD%E6%95%B0)）

- 支持设置组件的自定义焦点走焦逻辑。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-focus.md#nextfocus18)、[API参考-CAPI](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_focusmove)）

- 支持动态获取手势配置参数，可返回连续点击次数阈值。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-gesture-blocking-enhancement.md#taprecognizer18)）

- 支持手势取消时触发的onActionCancel回调中返回手势事件信息。（[API参考-LongPressGesture](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-longpressgesture.md#%E4%BA%8B%E4%BB%B6)、[API参考-PanGesture](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-pangesture.md#%E4%BA%8B%E4%BB%B6)、[API参考-PinchGesture](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-pinchgesture.md#%E4%BA%8B%E4%BB%B6)、[API参考-RotationGesture](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-rotationgesture.md#%E4%BA%8B%E4%BB%B6)）

- 无障碍支持自定义焦点顺序（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-accessibility.md#accessibilitynextfocusid18)）、支持控制组件的屏幕朗读方式（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-accessibility.md#accessibilityrole18)）、支持设置屏幕朗读滚动操作（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-accessibility.md#accessibilityscrolltriggerable18)）。

- 支持设置EmbeddedComponent或UIExtensionComponent组件的占用事件，指定手势事件的响应方式。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-uiExtension.md#occupyevents18)）

- 支持将当前FrameNode移动到目标FrameNode的指定位置，实现跨实例节点迁移。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-frameNode.md#moveto18)、[API参考-CAPI](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_nodeutils_moveto)）

- NodeController新增节点上下树和绑定解绑前后的生命周期回调接口（onAttach、onDetach、onWillBind、onWillUnbind、onBind、onUnbind）。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-nodeController.md)）

- 支持对ComponentContent构建的UI组件进行截图。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#createfromcomponent18)）

- 新增鼠标轴事件相关接口。（[API参考-ArkTS](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-events-axis.md)、[API参考-C API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___event_module.md#oh_arkui_axisevent_setpropagation)）

- NavDestination新增OnActive和OnInActive生命周期。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#onactive17)）

- C API的事件能力增强，新增支持获取事件命中的组件的宽度、高度、X坐标、Y坐标等能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___event_module.md#oh_arkui_uiinputevent_geteventtargetwidth)）

- UIContext新增支持创建不依赖窗口的UI实例。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#createuicontextwithoutwindow17)）

- 组件可见区域变化事件新增支持设置事件的回调参数，限制它的执行间隔。（[API参考-ArkTS](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-universal-component-visible-area-change-event.md#onvisibleareaapproximatechange17)、[API参考-C API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_visibleareaeventoptions_create)）

- ImageAnimator组件支持设置是否通过系统onVisibleAreaChange的可见性来判断组件的暂停和播放。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-imageanimator.md#monitorinvisiblearea17)）

### 窗口管理

- 新增软键盘弹出动画完成的监听回调。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-window.md#onkeyboarddidshow18)）

- 画中画窗口支持通过创建参数LocalStorage实现页面级别的UI状态存储单元，多实例下可用来跟踪主窗实例。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-pipWindow.md#pipconfiguration)）

- 窗口管理新增支持创建虚拟屏幕。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkui/js-apis-display.md#displaycreatevirtualscreen16)）


### 图形图像

新增一批C API函数和枚举，用于支持直接绘制到屏幕buffer的gpu渲染能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkgraphics2d/drawing__path__effect_8h.md)）


### 分布式数据管理

- RelationalStore新增rootDir配置，支持打开非database目录下的数据库。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkdata/js-apis-data-relationalStore.md#storeconfig)）

- 关系型数据库新增支持根据指定的列索引或列名称获取列数据类型。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkdata/js-apis-data-relationalStore.md#getcolumntype18)）

- UDMF新增支持将传入的data转换成多样式数据结构的能力。若原data使用多个record去承载同一份数据的不同样式，则可以使用此接口将原data转换为多样式数据结构。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddatachannelconvertrecordstoentries17)）


### 媒体


**音频**

- 新增支持Float32格式音频输出。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-audio-kit/_o_h_audio.md#oh_audiostream_sampleformat)）

- 新增支持空间音频管理的能力。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/media/audio/public-audio-spatialization-management.md)、[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-audio-kit/js-apis-audio.md#getspatializationmanager18)）

**音视频编解码**

- 视频解码新增支持MPEG2、MPEG4、H.263。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/media/avcodec/avcodec-support-formats.md)）

**播放控制**

- 播放器支持向应用透传SEI字段数据，适用于HTTP-FLV直播。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-media-kit/js-apis-media.md#onseimessagereceived18)）

- 调用媒体播放器AVPlayer设置播放策略时，新增支持Prepare之后显示视频起播首帧（showFirstFrameOnPrepare）、起播缓冲水线（preferredBufferDurationForPlaying）等播放策略。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-media-kit/js-apis-media.md#setplaybackstrategy12)）

- 播放器新增支持播放预下载的视频数据。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-media-kit/js-apis-media.md#setmediaresourceloaderdelegate18)）

- 调用媒体播放器AVPlayer设置播放策略时，新增支持智能追帧水线（thresholdForAutoQuickPlay）。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-media-kit/js-apis-media.md#playbackstrategy12)）

- 能力增强：支持应用创建多个SoundPool实例。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-media-kit/js-apis-media.md#mediacreatesoundpool10)）

- 调用媒体播放器AVPlayer设置播放策略时，新增支持Prepare之后显示视频起播首帧（showFirstFrameOnPrepare）。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-media-kit/js-apis-media.md#playbackstrategy12)）

- 新增支持通过AV会话命令传递设置目标循环模式（setTargetLoopMode）的能力（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-avsession-kit/js-apis-avsession.md#avcontrolcommandtype10)），并提供对设置动作的事件监听回调（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-avsession-kit/js-apis-avsession.md#onsettargetloopmode18)）。

- 音频会话新增支持单句/单条歌词展示的属性singleLyricText。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-avsession-kit/js-apis-avsession.md#avmetadata10)）

**图片**

- 新增C API支持获取图片的可编辑标志。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_geteditable)）

**录制**

- 新增屏幕录制时视频填充模式的枚举。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-media-kit/js-apis-media.md#avscreencapturefillmode18)）

- 音视频录制配置文件新增支持配置稳定录制模式enableStableQualityMode18。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-media-kit/js-apis-media.md#avrecorderprofile9)）


### 语言编译器运行时

- TaskPool支持指定任务执行并发度和指定任务的排队策略。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkts/js-apis-taskpool.md#asyncrunner18)）

- TaskPool支持通过任务ID取消任务池中的任务。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkts/js-apis-taskpool.md#taskpoolcancel18)）

- collections（ArkTS容器集）在API 18新增支持以下方法（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkts/js-apis-arkts-collections.md#arktscollections-arkts%E5%AE%B9%E5%99%A8%E9%9B%86)）：
  Array：from、isArray、of、copyWithin、lastIndexOf、some、reduceRight、reverse、toString、every、toLocaleString

  TypedArray：toString、toLocaleString、lastIndexOf、reduceRight

- Sendable支持在缓存空间不够的时候，将近期最少使用的数据替换为新数据。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkts/js-apis-arkts-utils.md#sendablelrucachek-v18)）

- Worker支持创建任务时指定任务的优先级。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkts/js-apis-worker.md#threadworkerpriority18)）


### 安全

新增基于群组的关键资产访问控制。通过设置群组属性，同一开发者开发的多个应用可以共享数据。（[指南](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/security/AssetStoreKit/asset-js-group-access-control.md)）


### DFX

新增支持为当前线程转储虚拟机的原始堆快照。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-performance-analysis-kit/js-apis-hidebug.md#hidebugdumpjsrawheapdata18)）


### 企业定制

- 可禁用/启用的特性限制新增MTP（mtpClient/mtpServer）和恢复出厂设置（resetFactory）。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-mdm-kit/js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)）

- 新增支持按系统账户安装用户证书。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-mdm-kit/js-apis-enterprise-securityManager.md#securitymanagerinstallusercertificate18)）

- 新增支持订阅账号的新增、删除、切换系统事件。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-mdm-kit/js-apis-enterprise-adminManager.md#managedevent)）

### 基础通信

- 新增在蓝牙socket server端可以获取对端蓝牙设备虚拟MAC地址的功能（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-connectivity-kit/js-apis-bluetooth-socket.md#socketgetdeviceid17)）

- 新增获取对端蓝牙设备原始名字的功能。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-connectivity-kit/js-apis-bluetooth-connection.md#connectiongetremotedevicename16)）

- 新增连接对端蓝牙设备可用profile的功能，如A2DP、HFP、HID等协议profile。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-connectivity-kit/js-apis-bluetooth-connection.md#connectionconnectallowedprofiles16)）

- 新增持久化存储对端蓝牙设备虚拟MAC地址的功能。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-connectivity-kit/js-apis-bluetooth-access.md#accessaddpersistentdeviceid16)）

- 新增蓝牙BLE扫描围栏模式，可实现首次扫描到BLE广播报文时上报进入围栏，扫描不到BLE广播报文时上报离开围栏，并携带BLE广播报文信息。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#scanreportmode15)）

- 完善蓝牙搜索到的设备信息，新增获取设备RSSI（信号强度）、名称和类别信息。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-connectivity-kit/js-apis-bluetooth-connection.md#discoveryresult18)）

- 新增异步读取和发送蓝牙socket数据的功能，如果链路断开，会上报IO异常。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-connectivity-kit/js-apis-bluetooth-socket.md#socketsppwriteasync18)）

### 位置服务

新增支持订阅蓝牙扫描信息上报事件用于辅助定位。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanageronbluetoothscanresultchange16)）

### 网络管理

新增支持获取TLSSocket的文件描述符。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-network-kit/js-apis-socket.md#getsocketfd16)）

### 剪贴板

剪贴板支持获取剪贴板的内容变化的次数。（[API参考-ArkTS API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-pasteboard.md#getchangecount18)、[API参考-C API](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-basic-services-kit/_pasteboard.md#oh_pasteboard_getchangecount)）


### 输入法

输入法框架新增支持设置显示预览文本时的回调（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#setpreviewtextcallback17)），支持订阅输入法应用操作文本预览内容的事件（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#onsetpreviewtext17)）。

### Web

- 支持获取上一次被点击区域的元素信息。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkweb/js-apis-webview.md#getlasthittest18)）

- 支持设置Web组件是否开启字重跟随系统设置变化。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#enablefollowsystemfontweight18)）

- 支持Web内音视频可对接到播控中心。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#enablewebavsession18)）

- 对接W3C规范，支持通过accept指定上传的文件类型。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#onshowfileselector9)）

- 提供静态方法，清除应用中的资源缓存文件。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkweb/js-apis-webview.md#removeallcache18)）

- 新增支持以固定宽高设置同层渲染的元素。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#nativeembedoptions16)）

### 多模输入

新增支持设置处于前台的应用操作指定按键的回调。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-input-kit/js-apis-inputconsumer.md#inputconsumeronkeypressed16)）

### 上传下载

- 上传下载支持应用缓存下载能力，支持应用提前缓存文件到沙箱目录或内存中。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-request-cacheDownload.md)）

- 上传下载agent接口支持设置任务最高限速（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-request.md#setmaxspeed18)），支持设置待上传文件在表单中的content-type字段（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-basic-services-kit/js-apis-request.md#filespec10)）。


### 资源调度

- 新增后台子进程管理模块，提供应用对子进程进行压制、解压制的能力，避免子进程过多占用系统资源，导致系统使用卡顿。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-backgroundtasks-kit/js-apis-backgroundProcessManager.md)）

- 后台代理提醒中提醒标题、提醒内容等字段支持设置资源ID，用于全球化适配。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-backgroundtasks-kit/js-apis-reminderAgentManager.md#reminderrequest)）


### 全球化

- 新增支持获取用户偏好温度单位和周起始日的能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-localization-kit/js-apis-i18n.md#gettemperaturetype18)）

- 新增支持时间日期/数字精细化格式化的能力，便于更灵活的使用格式化能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-localization-kit/js-apis-i18n.md#i18ngetsimpledatetimeformatbypattern18)）

- 新增支持返回富文本的数字格式化能力。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-localization-kit/js-apis-i18n.md#stylednumberformat18)）

- 新增支持路径本地化显示的能力，可以根据输入语言判断路径是否需要镜像显示。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-localization-kit/js-apis-i18n.md#getunicodewrappedfilepath18)）


### 测试框架

- 新增支持按照模糊匹配/正则匹配方式查找符合条件的控件id、type的能力。（API参考：[id](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-test-kit/js-apis-uitest.md#id18)、[type](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-test-kit/js-apis-uitest.md#type18)）

- 新增支持获取控件提示文本（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-test-kit/js-apis-uitest.md#gethint18)），并根据控件提示文本查找控件（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-test-kit/js-apis-uitest.md#hint18)）。

- 新增支持横向纵向查找控件，仅适用于支持滑动的控件。（[API参考](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/zh-cn/application-dev/reference/apis-test-kit/js-apis-uitest.md#scrollsearch18)）


## 配套关系

**表1** 版本软件和工具配套关系

| 软件 | 版本 | 备注 | 
| -------- | -------- | -------- |
| OpenHarmony | 5.1.0 Release | NA | 
| Public SDK | Ohos_sdk_public 5.1.0.107 (API Version 18 Release) | 面向应用开发者提供，不包含需要使用系统权限的系统接口。通过DevEco Studio默认获取的SDK为Public SDK。 | 
| HUAWEI DevEco Studio（可选） | 5.1.0 Release | OpenHarmony应用开发推荐使用。<br/>*待发布* | 
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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-5.1.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v5.1.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**方式二**

通过repo + https 下载。

- 从版本分支获取源码。可获取该版本分支的最新源码，包括版本发布后在该分支的合入。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-5.1.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- 从版本发布Tag节点获取源码。可获取与版本发布时完全一致的源码。
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v5.1.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### 从镜像站点获取


**表2** 获取源码路径

| 版本源码                                | **版本信息** | **下载站点**                                                 | **SHA256校验码**                                             | **软件包容量** |
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| 全量代码（标准、轻量和小型系统）        | 5.1.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/code-v5.1.0-Release.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/code-v5.1.0-Release.tar.gz.sha256) | 49.1 GB |
| Hi3861解决方案（二进制）        | 5.1.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/hispark_pegasus.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/hispark_pegasus.tar.gz.sha256) | 28.4 MB |
| Hi3516解决方案-LiteOS（二进制） | 5.1.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/hispark_taurus_LiteOS.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 350.0 MB |
| Hi3516解决方案-Linux（二进制）  | 5.1.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/hispark_taurus_Linux.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/hispark_taurus_Linux.tar.gz.sha256) | 223.6 MB |
| RK3568标准系统解决方案（二进制）        | 5.1.0 Release    | [站点](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/dayu200_standard_arm32.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/dayu200_standard_arm32.tar.gz.sha256) | 	9.7 GB |
| 标准系统Public SDK包（Mac）             | 5.1.0.107 | [站点](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/ohos-sdk-mac-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/ohos-sdk-mac-public.tar.gz.sha256) | 1.3 GB |
| 标准系统Public SDK包（Mac-M1）             | 5.1.0.107  | [站点](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 1.2 GB |
| 标准系统Public SDK包（Windows/Linux）   | 5.1.0.107   | [站点](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/ohos-sdk-windows_linux-public.tar.gz) | [SHA256校验码](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 3.2 GB |


## 修复缺陷列表

**表3** 修复缺陷ISSUE列表

| ISSUE单 | 问题描述 | 
| ------- | ------- |
| IBTXFK | 从图库删除多张图片的完整用时可能稍长（1000+ ms）。 |
| IBTCJQ | FWX图片放大缩小的移动帧率不足60帧。 |
| IBINUK | 进程com.ohos.camera有一定概率出现因LIFECYCLE_TIMEOUT卡在libcamera_framework.z.so导致的sysfreeze。 |

## 遗留缺陷列表

**表4** 遗留缺陷列表

| ISSUE | 问题描述 | 影响 | 计划解决日期 | 
| -------- | -------- | -------- | -------- |
| IBTCKR | SystemUI状态栏下拉到内容渲染耗完成时的完整用时可能稍长（160+ ms）。 | 轻微影响使用体验。 | 2025年5月30日 |
| IBBZPS | 进程com.ohos.systemui下的OS_IPC_0_1067线程小概率出现cppcrash，崩溃栈：ld-musl-arm.so.1(__libc_free+172) | 系统异常，用户无感知。 | 2025年5月30日 | 
| IBE36X</br>IBO3MF | 进程render_service小概率出现因SERVICE_BLOCK导致的的sysfreeze问题。 | 桌面无响应后黑屏，自动恢复后回到桌面。 | 2025年5月30日 |
| IC313T | 图库缩略图列表滑动的动画帧率未达到基线要求。 | 轻微影响使用体验。预计5月10日解决后评估回合5.1.0版本。 | 2025年5月10日 | 
| IC32I0 | 浏览器微博首页滑动、浏览器天猫界面缩放的动画帧率未达到基线要求。 | 轻微影响使用体验。 | 2025年5月30日 | 
| IC32SL | 首次启动浏览器到启动完成的耗时稍长，未达到基线要求。 | 轻微影响使用体验。 | 2025年6月23日 | 
| IBUCOT | com.ohos.settingsdata进程的常驻内存实测值为16MB，远超基线要求。  | 内存占用不符合预期，对实际使用无影响。 | 2025年5月30日 | 
| IC4UFM | 通话拨号盘按键的按键响应时延稍长，未达到基线要求。  | 轻微影响使用体验。 | 2025年5月16日 | 
| IC04TG | 进程com.ohos.note下的com.ohos.note线程有一定概率出现因libarkweb_engine.so导致的cppcrash。  | 备忘录应用异常，重启可恢复。 | 2025年5月8日 | 
| IBZYWM | 进程com.ohos.note下的CompositorGpuTh线程有一定概率出现因libmali-bifrost-g52-g7p0-ohos.so导致的cppcrash。  | 备忘录应用异常，重启可恢复。 | 2025年5月8日 | 
| IC22OQ | 进程com.ohos.note下的RSRenderThread线程小概率出现因libskia_canvaskit.z.so导致的cppcrash。  | 备忘录应用异常，重启可恢复。 | 2025年5月15日 | 
| IC4ZPS | 执行XTS测试时，ActslocationErrorCodeApiTest测试套因RK3568开发板位置服务不支持Geofence能力导致执行结果出现失败项。  | 该问题已在master解决，可通过增加配置项处理。<br/>配置方式可参考https://gitee.com/openharmony/vendor_hihope/pulls/1505 | 2025年4月30日 | 
| IC57IO | 桌面->右上角下划进入控制中心->点击控制中心飞行模式，该操作按钮功能失效。  | 该问题已在master解决，可手动修改代码规避。<br/>处理方式可参考https://gitee.com/openharmony/distributeddatamgr_datamgr_service/pulls/2967 | 2025年4月30日 | 


<!--no_check-->