# native_interface_accessibility.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyinhua-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

声明用于访问Native Accessibility的API，提供无障碍相关能力。支持第三方框架将自身UI组件接入ArkUI无障碍服务体系，包括注册无障碍回调、设置和查询无障碍节点信息、主动上报无障碍事件以及适配多实例场景等，使系统无障碍服务能够识别并操作三方框架的UI组件，适用于第三方UI框架需要与系统无障碍能力进行交互的场景。

**引用文件：** <arkui/native_interface_accessibility.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 13

**相关模块：** [ArkUI_Accessibility](capi-arkui-accessibility.md)

**相关示例：** <!--RP1-->[AccessibilityCapi](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/AccessibilityCapi)<!--RP1End-->

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_AccessibleAction](capi-arkui-accessibility-arkui-accessibleaction.md) | ArkUI_AccessibleAction | 无障碍操作内容结构。该结构体用于描述无障碍节点支持的操作类型及其描述信息。支持无障碍服务向用户呈现节点可执行的操作（如点击、长按、滚动等），并提供操作的文字说明，以帮助用户理解操作含义。 |
| [ArkUI_AccessibleRect](capi-arkui-accessibility-arkui-accessiblerect.md) | ArkUI_AccessibleRect | 节点在屏幕中的矩形区域坐标位置。该结构体用于描述无障碍节点的边界矩形，通过左上角和右下角的坐标定义节点在屏幕上的可视区域，支持无障碍服务获取节点的位置和大小信息。 |
| [ArkUI_AccessibleRangeInfo](capi-arkui-accessibility-arkui-accessiblerangeinfo.md) | ArkUI_AccessibleRangeInfo | 用于表示特定组件（如[Slider](arkui-ts/ts-basic-components-slider.md)、[Rating](arkui-ts/ts-basic-components-rating.md)、[Progress](arkui-ts/ts-basic-components-progress.md)）的范围值信息，包含当前值、最大值和最小值，供无障碍服务读取并向障碍用户播报。 |
| [ArkUI_AccessibleGridInfo](capi-arkui-accessibility-arkui-accessiblegridinfo.md) | ArkUI_AccessibleGridInfo | 用于描述网格组件的整体布局属性。该结构体用于向无障碍服务提供网格组件的行数、列数和选择模式等信息，支持无障碍服务获取网格的整体布局信息。 |
| [ArkUI_AccessibleGridItemInfo](capi-arkui-accessibility-arkui-accessiblegriditeminfo.md) | ArkUI_AccessibleGridItemInfo | 用于描述网格组件内某个网格项的无障碍属性。该结构体用于向无障碍服务提供网格项的位置、跨度、选中状态等信息，支持无障碍服务获取网格项的布局信息。 |
| [ArkUI_AccessibilityProviderCallbacks](capi-arkui-accessibility-arkui-accessibilityprovidercallbacks.md) | ArkUI_AccessibilityProviderCallbacks | 第三方[provider](capi-arkui-accessibility-arkui-accessibilityprovider.md)回调函数结构定义，需要第三方平台实现的相关函数，通过[OH_ArkUI_AccessibilityProviderRegisterCallback](capi-native-interface-accessibility-h.md#oh_arkui_accessibilityproviderregistercallback)注册到系统侧。适用于读屏软件、语音控制、开关控制等无障碍辅助场景，第三方平台通过实现这些回调响应系统的无障碍查询和操作请求。 |
| [ArkUI_AccessibilityProviderCallbacksWithInstance](capi-arkui-accessibility-arkui-accessibilityprovidercallbackswithinstance.md) | ArkUI_AccessibilityProviderCallbacksWithInstance | 适配多实例场景第三方操作[provider](capi-arkui-accessibility-arkui-accessibilityprovider.md)回调函数结构定义，包含节点信息查询、焦点查找与清除、操作执行、光标位置获取等无障碍相关回调函数。该结构需由第三方平台实现，并通过[OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance](capi-native-interface-accessibility-h.md#oh_arkui_accessibilityproviderregistercallbackwithinstance)注册到系统侧，以支持第三方平台接入系统无障碍服务。 |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md) | [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md) | 无障碍元素信息，用于向无障碍服务、辅助应用（屏幕朗读等）传递元素的属性、操作、位置、文本等信息，适用于无障碍服务获取和操作界面元素的辅助场景。 |
| [ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md) | [ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md) | 无障碍事件信息。当无障碍服务或辅助应用要求控件执行操作后，应用需发送执行成功事件以通知操作结果，适用于需要向无障碍服务反馈操作执行情况的场景。 |
| [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md) | [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md) | 该结构体为无障碍第三方操作提供者，用于承载回调函数的实现。开发者可通过该结构体注册和管理无障碍操作相关的回调，实现自定义的无障碍交互逻辑，适用于需要扩展或定制ArkUI无障碍能力的场景。 |
| [ArkUI_AccessibilityActionArguments](capi-arkui-accessibility-arkui-accessibilityactionarguments.md) | [ArkUI_AccessibilityActionArguments](capi-arkui-accessibility-arkui-accessibilityactionarguments.md) | 用于设置无障碍操作的具体参数。在进行无障碍操作时，通过该结构体向无障碍服务传递操作所需的附加上下文信息。适用于开发者需要向无障碍服务精确描述无障碍操作细节的场景，例如自定义控件的无障碍读屏播报、辅助功能服务中的操作参数传递、语音助手触发的无障碍交互等应用功能。 |
| [ArkUI_AccessibilityElementInfoList](capi-arkui-accessibility-arkui-accessibilityelementinfolist.md) | [ArkUI_AccessibilityElementInfoList](capi-arkui-accessibility-arkui-accessibilityelementinfolist.md) | 提供封装[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的List实例，用于批量存储和管理无障碍元素信息，适用于需要一次获取多个无障碍元素信息的场景。 |
| [ArkUI_Node*](capi-arkui-nativemodule-arkui-node8h.md) | ArkUI_NodeHandle | 定义 ArkUI Native 组件实例对象指针，用于在 ArkUI Native 接口中标识和传递组件实例，例如创建、挂载、移除或销毁组件节点。<br>**起始版本：** 23  |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_Accessibility_ActionType](#arkui_accessibility_actiontype) | ArkUI_Accessibility_ActionType | Accessibility操作类型的枚举。 |
| [ArkUI_AccessibilityEventType](#arkui_accessibilityeventtype) | ArkUI_AccessibilityEventType | Accessibility事件类型的枚举。 |
| [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode) | ArkUI_AcessbilityErrorCode | Accessibility错误代码状态的枚举。 |
| [ArkUI_AccessibilitySearchMode](#arkui_accessibilitysearchmode) | ArkUI_AccessibilitySearchMode | Accessibility搜索类型的枚举。 |
| [ArkUI_AccessibilityFocusType](#arkui_accessibilityfocustype) | ArkUI_AccessibilityFocusType | Accessibility焦点类型的枚举。 |
| [ArkUI_AccessibilityFocusMoveDirection](#arkui_accessibilityfocusmovedirection) | ArkUI_AccessibilityFocusMoveDirection | Accessibility焦点移动方向的枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [int32_t OH_ArkUI_AccessibilityProviderRegisterCallback(ArkUI_AccessibilityProvider* provider, ArkUI_AccessibilityProviderCallbacks* callbacks)](#oh_arkui_accessibilityproviderregistercallback) | 注册第三方操作provider回调函数到系统侧，由第三方平台实现相关函数并通过本接口完成注册。 |
| [int32_t OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance(const char* instanceId,ArkUI_AccessibilityProvider* provider, ArkUI_AccessibilityProviderCallbacksWithInstance* callbacks)](#oh_arkui_accessibilityproviderregistercallbackwithinstance) | 无障碍多实例场景第三方平台将回调函数注册到系统侧。 |
| [void OH_ArkUI_SendAccessibilityAsyncEvent(ArkUI_AccessibilityProvider* provider, ArkUI_AccessibilityEventInfo* eventInfo,void (\*callback)(int32_t errorCode))](#oh_arkui_sendaccessibilityasyncevent) | 主动上报事件接口，通知无障碍服务。当组件状态发生变化（如点击、选中、文本更新、页面切换、焦点变化等）时，开发者可通过此接口主动向无障碍服务上报事件，以便辅助应用（如屏幕朗读）及时获取最新的组件状态信息。 |
| [ArkUI_AccessibilityElementInfo* OH_ArkUI_AddAndGetAccessibilityElementInfo(ArkUI_AccessibilityElementInfoList* list)](#oh_arkui_addandgetaccessibilityelementinfo) | 在指定的list中增加element成员，并返回element结构。<br>**说明：** 该接口返回的ArkUI_AccessibilityElementInfo对象由传入的ArkUI_AccessibilityElementInfoList统一管理，生命周期与list绑定，不需要单独调用OH_ArkUI_DestoryAccessibilityElementInfo释放。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetElementId(ArkUI_AccessibilityElementInfo* elementInfo, int32_t elementId)](#oh_arkui_accessibilityelementinfosetelementid) | 为ArkUI_AccessibilityElementInfo设置无障碍元素的唯一标识（elementId）。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetParentId(ArkUI_AccessibilityElementInfo* elementInfo, int32_t parentId)](#oh_arkui_accessibilityelementinfosetparentid) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置父节点的无障碍编号（parentId）。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetComponentType(ArkUI_AccessibilityElementInfo* elementInfo, const char* componentType)](#oh_arkui_accessibilityelementinfosetcomponenttype) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置组件类型。为组件类型字符串（如“Button”、“Text”、“Image”等），用于标识当前无障碍节点的组件类型。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetContents(ArkUI_AccessibilityElementInfo* elementInfo, const char* contents)](#oh_arkui_accessibilityelementinfosetcontents) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置组件文本内容。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetHintText(ArkUI_AccessibilityElementInfo* elementInfo, const char* hintText)](#oh_arkui_accessibilityelementinfosethinttext) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置提示文本。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityText(ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityText)](#oh_arkui_accessibilityelementinfosetaccessibilitytext) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置无障碍专用的替代文本。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityDescription(ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityDescription)](#oh_arkui_accessibilityelementinfosetaccessibilitydescription) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置无障碍描述信息。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetChildNodeIds(ArkUI_AccessibilityElementInfo* elementInfo, int32_t childCount, int64_t* childNodeIds)](#oh_arkui_accessibilityelementinfosetchildnodeids) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置孩子节点数量和孩子节点ID集合。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetOperationActions(ArkUI_AccessibilityElementInfo* elementInfo,int32_t operationCount, ArkUI_AccessibleAction* operationActions)](#oh_arkui_accessibilityelementinfosetoperationactions) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置组件支持的无障碍操作列表。<br>**说明：** operationActions用于设置组件支持的无障碍操作集合，每次调用本接口将替换之前设置的所有操作动作（覆盖式更新，非追加）；operationCount必须大于0，且operationActions数组中至少包含operationCount个有效元素。建议根据组件的交互属性注册对应的action类型：可点击组件应包含ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CLICK，可长按组件应包含ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_LONG_CLICK。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetScreenRect(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleRect* screenRect)](#oh_arkui_accessibilityelementinfosetscreenrect) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置组件在屏幕上的矩形区域。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetCheckable(ArkUI_AccessibilityElementInfo* elementInfo, bool checkable)](#oh_arkui_accessibilityelementinfosetcheckable) | 为ArkUI_AccessibilityElementInfo设置是否可勾选。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetChecked(ArkUI_AccessibilityElementInfo* elementInfo, bool checked)](#oh_arkui_accessibilityelementinfosetchecked) | 为ArkUI_AccessibilityElementInfo设置当前的勾选状态。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetFocusable(ArkUI_AccessibilityElementInfo* elementInfo, bool focusable)](#oh_arkui_accessibilityelementinfosetfocusable) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置是否可聚焦。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetFocused(ArkUI_AccessibilityElementInfo* elementInfo, bool isFocused)](#oh_arkui_accessibilityelementinfosetfocused) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置是否已聚焦。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetVisible(ArkUI_AccessibilityElementInfo* elementInfo, bool isVisible)](#oh_arkui_accessibilityelementinfosetvisible) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置组件是否在屏幕上可见。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityFocused(ArkUI_AccessibilityElementInfo* elementInfo, bool accessibilityFocused)](#oh_arkui_accessibilityelementinfosetaccessibilityfocused) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置当前的无障碍辅助焦点状态。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetSelected(ArkUI_AccessibilityElementInfo* elementInfo, bool selected)](#oh_arkui_accessibilityelementinfosetselected) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置是否处于选中状态。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetClickable(ArkUI_AccessibilityElementInfo* elementInfo, bool clickable)](#oh_arkui_accessibilityelementinfosetclickable) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置是否支持点击操作。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetLongClickable(ArkUI_AccessibilityElementInfo* elementInfo, bool longClickable)](#oh_arkui_accessibilityelementinfosetlongclickable) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置是否支持长按操作。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetEnabled(ArkUI_AccessibilityElementInfo* elementInfo, bool isEnabled)](#oh_arkui_accessibilityelementinfosetenabled) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置组件是否处于启用状态。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetIsPassword(ArkUI_AccessibilityElementInfo* elementInfo, bool isPassword)](#oh_arkui_accessibilityelementinfosetispassword) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置是否为密码输入框。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetScrollable(ArkUI_AccessibilityElementInfo* elementInfo, bool scrollable)](#oh_arkui_accessibilityelementinfosetscrollable) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置是否支持滚动操作。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetEditable(ArkUI_AccessibilityElementInfo* elementInfo, bool editable)](#oh_arkui_accessibilityelementinfoseteditable) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置文本内容是否可编辑。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetIsHint(ArkUI_AccessibilityElementInfo* elementInfo, bool isHint)](#oh_arkui_accessibilityelementinfosetishint) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置是否处于提示文本状态。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetRangeInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleRangeInfo* rangeInfo)](#oh_arkui_accessibilityelementinfosetrangeinfo) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置范围值信息。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetGridInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleGridInfo* gridInfo)](#oh_arkui_accessibilityelementinfosetgridinfo) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置网格信息。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetGridItemInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleGridItemInfo* gridItem)](#oh_arkui_accessibilityelementinfosetgriditeminfo) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置网格容器中子项的属性信息。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetSelectedTextStart(ArkUI_AccessibilityElementInfo* elementInfo, int32_t selectedTextStart)](#oh_arkui_accessibilityelementinfosetselectedtextstart) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置选中文本的起始位置。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetSelectedTextEnd(ArkUI_AccessibilityElementInfo* elementInfo, int32_t selectedTextEnd)](#oh_arkui_accessibilityelementinfosetselectedtextend) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置选中文本的结束位置。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetCurrentItemIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t currentItemIndex)](#oh_arkui_accessibilityelementinfosetcurrentitemindex) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置当前获焦或高亮子项的位置索引。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetStartItemIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t startItemIndex)](#oh_arkui_accessibilityelementinfosetstartitemindex) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置当前屏幕可见区域中第一个元素的位置索引。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetEndItemIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t endItemIndex)](#oh_arkui_accessibilityelementinfosetenditemindex) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置当前屏幕可见区域中最后一个元素的位置索引。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetItemCount(ArkUI_AccessibilityElementInfo* elementInfo, int32_t itemCount)](#oh_arkui_accessibilityelementinfosetitemcount) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置容器中子项的总数。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityOffset(ArkUI_AccessibilityElementInfo* elementInfo, int32_t offset)](#oh_arkui_accessibilityelementinfosetaccessibilityoffset) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置滚动偏移量。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityGroup(ArkUI_AccessibilityElementInfo* elementInfo, bool accessibilityGroup)](#oh_arkui_accessibilityelementinfosetaccessibilitygroup) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置无障碍分组。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityLevel(ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityLevel)](#oh_arkui_accessibilityelementinfosetaccessibilitylevel) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置无障碍重要性级别。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetZIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t zIndex)](#oh_arkui_accessibilityelementinfosetzindex) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置组件的Z序。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityOpacity(ArkUI_AccessibilityElementInfo* elementInfo, float opacity)](#oh_arkui_accessibilityelementinfosetaccessibilityopacity) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置透明度。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetBackgroundColor(ArkUI_AccessibilityElementInfo* elementInfo, const char* backgroundColor)](#oh_arkui_accessibilityelementinfosetbackgroundcolor) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置背景色。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetBackgroundImage(ArkUI_AccessibilityElementInfo* elementInfo, const char* backgroundImage)](#oh_arkui_accessibilityelementinfosetbackgroundimage) | 为ArkUI_AccessibilityElementInfo设置背景图片。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetBlur(ArkUI_AccessibilityElementInfo* elementInfo, const char* blur)](#oh_arkui_accessibilityelementinfosetblur) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置模糊效果。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetHitTestBehavior(ArkUI_AccessibilityElementInfo* elementInfo, const char* hitTestBehavior)](#oh_arkui_accessibilityelementinfosethittestbehavior) | 为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置触摸测试的响应逻辑及节点阻塞规则。取值为“Default”（默认不阻断）、“Block”（阻断自身及子组件）、“Transparent”（自身不响应但子组件可响应）、“None”（自身和子组件都不响应），不能为空指针。 |
| [int32_t OH_ArkUI_AccessibilityElementInfoSetComponentIdentifier(ArkUI_AccessibilityElementInfo* elementInfo, const char* identifier)](#oh_arkui_accessibilityelementinfosetcomponentidentifier) | 为无障碍节点信息[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置组件标识，可用于自动化测试识别特定组件。|
| [ArkUI_AccessibilityElementInfo* OH_ArkUI_CreateAccessibilityElementInfo(void)](#oh_arkui_createaccessibilityelementinfo) | 创建一个[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)对象，创建后需要调用[OH_ArkUI_DestoryAccessibilityElementInfo](#oh_arkui_destoryaccessibilityelementinfo)释放。 |
| [void OH_ArkUI_DestoryAccessibilityElementInfo(ArkUI_AccessibilityElementInfo* elementInfo)](#oh_arkui_destoryaccessibilityelementinfo) | 销毁一个[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)对象。 |
| [ArkUI_AccessibilityEventInfo* OH_ArkUI_CreateAccessibilityEventInfo(void)](#oh_arkui_createaccessibilityeventinfo) | 创建一个[ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)对象，创建后需要调用[OH_ArkUI_DestoryAccessibilityEventInfo](#oh_arkui_destoryaccessibilityeventinfo)释放。 |
| [void OH_ArkUI_DestoryAccessibilityEventInfo(ArkUI_AccessibilityEventInfo* eventInfo)](#oh_arkui_destoryaccessibilityeventinfo) | 销毁[ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)对象。 |
| [int32_t OH_ArkUI_AccessibilityEventSetEventType(ArkUI_AccessibilityEventInfo* eventInfo,  ArkUI_AccessibilityEventType eventType)](#oh_arkui_accessibilityeventseteventtype) | 为[ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)设置事件类型。 |
| [int32_t OH_ArkUI_AccessibilityEventSetTextAnnouncedForAccessibility(ArkUI_AccessibilityEventInfo* eventInfo,  const char* textAnnouncedForAccessibility)](#oh_arkui_accessibilityeventsettextannouncedforaccessibility) | 为[ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)设置主动播报的内容。 |
| [int32_t OH_ArkUI_AccessibilityEventSetRequestFocusId(ArkUI_AccessibilityEventInfo* eventInfo,  int32_t requestFocusId)](#oh_arkui_accessibilityeventsetrequestfocusid) | 为[ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)设置请求聚焦的无障碍节点elementId。在发送无障碍事件（如[ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_REQUEST_ACCESSIBILITY_FOCUS](#arkui_accessibilityeventtype)）时，可通过此接口指定需要获焦的节点ID，使无障碍服务在处理事件时将辅助焦点移动到指定节点。适用于需要主动引导用户关注特定元素的场景，如页面跳转后引导焦点到新页面的首个可交互元素。 |
| [int32_t OH_ArkUI_AccessibilityEventSetElementInfo(ArkUI_AccessibilityEventInfo* eventInfo,  ArkUI_AccessibilityElementInfo* elementInfo)](#oh_arkui_accessibilityeventsetelementinfo) | 为[ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)设置关联的无障碍节点信息（elementInfo），用于指定事件对应的无障碍节点。 |
| [int32_t OH_ArkUI_FindAccessibilityActionArgumentByKey(ArkUI_AccessibilityActionArguments* arguments, const char* key, char** value)](#oh_arkui_findaccessibilityactionargumentbykey) | 获取[ArkUI_AccessibilityActionArguments](capi-arkui-accessibility-arkui-accessibilityactionarguments.md)中指定key的value值。 |
| [int32_t OH_ArkUI_NativeModule_GetNativeAccessibilityProvider(ArkUI_NodeHandle* node, ArkUI_AccessibilityProvider** provider)](#oh_arkui_nativemodule_getnativeaccessibilityprovider) |获取指向[ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)对象指针的二级指针变量。<br>其中[ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)对象与传入的[ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md)的实例一一对应。<br>三方框架将自身UI组件映射为[ARKUI_NODE_CUSTOM](capi-native-node-h.md#arkui_nodetype)类型的[RenderNode](js-apis-arkui-renderNode.md)并得到[ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md)。<br>再调用OH_ArkUI_NativeModule_GetNativeAccessibilityProvider接口获取[ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)指针，并通过[OH_ArkUI_AccessibilityProviderRegisterCallback](#oh_arkui_accessibilityproviderregistercallback)或[OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance](#oh_arkui_accessibilityproviderregistercallbackwithinstance)注册无障碍回调。<br>最终实现ArkUI无障碍服务对三方框架UI的识别与事件触发。<br>仅当三方框架将自身UI组件映射为[ARKUI_NODE_CUSTOM](capi-native-node-h.md#arkui_nodetype)的[RenderNode](js-apis-arkui-renderNode.md)，该接口才会生效，否则会报错误码。<br>本接口通过[RenderNode](js-apis-arkui-renderNode.md)实现三方框架的接入，仅支持[ARKUI_NODE_CUSTOM](capi-native-node-h.md#arkui_nodetype)接入无障碍服务，可以实现无障碍控件树获取能力。<br>不支持多线程并发，由三方框架保证调用时的线程安全。|

## 枚举类型说明

### ArkUI_Accessibility_ActionType

```c
enum ArkUI_Accessibility_ActionType
```

**描述：**


Accessibility操作类型的枚举。

**起始版本：** 13

| 枚举项 | 描述                                                                                                                                |
| -- |-----------------------------------------------------------------------------------------------------------------------------------|
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_INVALID = 0 | 无效值。                                                                                                                               |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CLICK = 0x00000010 | 收到事件后，组件需要对点击做出响应。                                                                                                                |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_LONG_CLICK = 0x00000020 | 收到事件后，组件需要对长按做出响应。                                                                                                               |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_GAIN_ACCESSIBILITY_FOCUS = 0x00000040 | 表示获取辅助功能焦点的操作，执行后对应组件将获得无障碍焦点。                                                                                                            |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CLEAR_ACCESSIBILITY_FOCUS = 0x00000080 | 表示清除辅助功能焦点的操作。                                                                                                                    |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SCROLL_FORWARD = 0x00000100 | 滚动组件响应向前滚动动作。                                                                                                                     |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SCROLL_BACKWARD = 0x00000200 | 滚动组件响应反向滚动操作。                                                                                                                     |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_COPY = 0x00000400 | 复制文本组件的选定内容。                                                                                                                      |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_PASTE = 0x00000800 | 粘贴文本组件的选定内容。                                                                                                                      |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CUT = 0x00001000 | 剪切文本组件的选定内容。                                                                                                                      |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SELECT_TEXT = 0x00002000 | 针对文本组件进行选择操作。需结合ArkUI_AccessibilityActionArguments使用，配置selectTextBegin（选择起始位置）、selectTextEnd（选择结束位置）、selectTextInForward（true表示前光标，false表示后光标），配置后在编辑区选择一段文本内容。                                                                    |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SET_TEXT = 0x00004000 | 设置文本组件的文本内容。                                                                                                                      |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SET_CURSOR_POSITION = 0x00100000 | 针对文本组件设置光标位置，结合[ArkUI_AccessibilityActionArguments](capi-arkui-accessibility-arkui-accessibilityactionarguments.md)使用，配置可输入文本组件的光标位置。 |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_NEXT_HTML_ITEM = 0x02000000 | 焦点移动操作中支持查找下一个焦点。此处的HTML并不代表网页元素，仅用于表示具有可自行查找下一个可见聚焦组件的能力，与Web支持的能力相似。实现[findNextFocusAccessibilityNode](capi-arkui-accessibility-arkui-accessibilityprovidercallbacks.md#findnextfocusaccessibilitynode)的能力才可配置该属性。<br>**起始版本：** 15 |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_PREVIOUS_HTML_ITEM = 0x04000000 | 焦点移动操作中支持查找上一个焦点。此处的HTML并不代表网页元素，仅用于表示具有可自行查找上一个可见聚焦组件的能力，与Web支持的能力相似。实现[findNextFocusAccessibilityNode](./capi-arkui-accessibility-arkui-accessibilityprovidercallbacks.md#findnextfocusaccessibilitynode)的能力才可配置该属性。<br>**起始版本：** 15     |

### ArkUI_AccessibilityEventType

```c
enum ArkUI_AccessibilityEventType
```

**描述：**


Accessibility事件类型的枚举。

**起始版本：** 13

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_INVALID = 0 | 无效值。 |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_CLICKED = 0x00000001 | 点击事件，在UI组件响应后发送。 |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_LONG_CLICKED = 0x00000002 | 长按事件，在UI组件响应后发送。 |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_SELECTED = 0x00000004 | 被选中事件，控件响应完成后发送。 |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_TEXT_UPDATE = 0x00000010 | 文本更新事件，需要在文本更新时发送。 |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_STATE_UPDATE = 0x00000020 | 页面更新事件，当页面跳转、切换、大小更改或移动时发送。 |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_CONTENT_UPDATE = 0x00000800 | 页面内容发生变化时需要发送事件。 |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_SCROLLED = 0x000001000 | scrolled事件，当可滚动的组件上发生滚动事件时，会发送此事件。 |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_ACCESSIBILITY_FOCUSED = 0x00008000 | Accessibility焦点事件，在UI组件响应后发送。 |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_ACCESSIBILITY_FOCUS_CLEARED = 0x00010000 | Accessibility焦点清除事件，在UI组件响应后发送。 |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_REQUEST_ACCESSIBILITY_FOCUS = 0x02000000 | 主动请求指定节点聚焦。 |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_OPEN = 0x20000000 | UI组件上报页面打开事件。 |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_CLOSE = 0x08000000 | UI组件上报页面关闭事件。 |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_ANNOUNCE_FOR_ACCESSIBILITY = 0x10000000 | 广播Accessibility事件，请求主动播报指定的内容。 |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_FOCUS_NODE_UPDATE = 0x10000001 | 焦点更新事件，用于焦点更新场景。 |

### ArkUI_AcessbilityErrorCode

```c
enum ArkUI_AcessbilityErrorCode
```

**描述：**


Accessibility错误代码状态的枚举。

**起始版本：** 13

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL = 0 | 成功。 |
| ARKUI_ACCESSIBILITY_NATIVE_RESULT_FAILED = -1 | 操作失败，请检查接口调用流程。可能原因：接口执行过程中出现内部错误。解决措施：请检查调用流程是否正确，若问题持续存在请排查系统状态。 |
| ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER = -2 | 无效参数，请检查传入的参数是否正确。可能原因:传入的参数为空指针或不符合接口要求。解决措施:请检查传入参数是否合法,确保指针不为空且参数值在有效范围内。 |
| ARKUI_ACCESSIBILITY_NATIVE_RESULT_OUT_OF_MEMORY = -3 | 内存不足，请检查系统内存使用情况。可能原因:系统内存资源不足,无法完成操作。解决措施:请释放不必要的资源后重试。 |

### ArkUI_AccessibilitySearchMode

```c
enum ArkUI_AccessibilitySearchMode
```

**描述：**


Accessibility搜索类型的枚举。

**起始版本：** 13

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_CURRENT = 0 | 查询当前节点。 |
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_PREDECESSORS = 1 << 0 | 查询父节点。 |
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_SIBLINGS = 1 << 1 | 查询兄弟节点。 |
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_CHILDREN = 1 << 2 | 查询下一层孩子节点。 |
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_RECURSIVE_CHILDREN = 1 << 3 | 查询所有孩子节点。 |

### ArkUI_AccessibilityFocusType

```c
enum ArkUI_AccessibilityFocusType
```

**描述：**


Accessibility焦点类型的枚举。

**起始版本：** 13

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ACCESSIBILITY_NATIVE_FOCUS_TYPE_INVALID = -1 | 无效值。 |
| ARKUI_ACCESSIBILITY_NATIVE_FOCUS_TYPE_INPUT = 1 << 0 | 输入焦点类型。 |
| ARKUI_ACCESSIBILITY_NATIVE_FOCUS_TYPE_ACCESSIBILITY = 1 << 1 | Accessibility焦点类型。 |

### ArkUI_AccessibilityFocusMoveDirection

```c
enum ArkUI_AccessibilityFocusMoveDirection
```

**描述：**


Accessibility焦点移动方向的枚举。

**起始版本：** 13

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_INVALID = 0 | 无效值。 |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_UP = 0x00000001 | 焦点向上移动。 |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_DOWN = 0x00000002 | 焦点向下移动。 |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_LEFT = 0x00000004 | 焦点向左移动。 |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_RIGHT = 0x00000008 | 焦点向右移动。 |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_FORWARD = 0x00000010 | 焦点向下一个可聚焦节点移动，基于查询请求中指定的基准节点。 |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_BACKWARD = 0x00000020 | 焦点向上一个可聚焦节点移动，基于查询请求中指定的基准节点。 |


## 函数说明

### OH_ArkUI_AccessibilityProviderRegisterCallback()

```c
int32_t OH_ArkUI_AccessibilityProviderRegisterCallback(ArkUI_AccessibilityProvider* provider, ArkUI_AccessibilityProviderCallbacks* callbacks)
```

**描述：**


注册第三方操作provider回调函数到系统侧，由第三方平台实现相关函数并通过本接口完成注册。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)* provider | 表示指向[ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)实例的指针。 |
| [ArkUI_AccessibilityProviderCallbacks](capi-arkui-accessibility-arkui-accessibilityprovidercallbacks.md)* callbacks | 表示指向[ArkUI_AccessibilityProviderCallbacks](capi-arkui-accessibility-arkui-accessibilityprovidercallbacks.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功，则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>如果参数错误，则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance()

```c
int32_t OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance(const char* instanceId, ArkUI_AccessibilityProvider* provider, ArkUI_AccessibilityProviderCallbacksWithInstance* callbacks)
```

**描述：**


无障碍多实例场景第三方平台将回调函数注册到系统侧。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* instanceId | 第三方平台接入的实例ID，用于区分多实例场景中不同的第三方实例，ID由第三方平台指定与维护。 |
| [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)* provider | 第三方平台接入provider句柄。 |
| [ArkUI_AccessibilityProviderCallbacksWithInstance](capi-arkui-accessibility-arkui-accessibilityprovidercallbackswithinstance.md)* callbacks | 表示指向[ArkUI_AccessibilityProviderCallbacksWithInstance](capi-arkui-accessibility-arkui-accessibilityprovidercallbackswithinstance.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_SendAccessibilityAsyncEvent()

```c
void OH_ArkUI_SendAccessibilityAsyncEvent(ArkUI_AccessibilityProvider* provider, ArkUI_AccessibilityEventInfo* eventInfo, void (*callback)(int32_t errorCode))
```

**描述：**


主动上报事件接口，通知无障碍服务。

使用流程：
1. 先通过[OH_ArkUI_CreateAccessibilityEventInfo](#oh_arkui_createaccessibilityeventinfo)创建事件信息对象。
2. 通过[OH_ArkUI_AccessibilityEventSetEventType](#oh_arkui_accessibilityeventseteventtype)、[OH_ArkUI_AccessibilityEventSetTextAnnouncedForAccessibility](#oh_arkui_accessibilityeventsettextannouncedforaccessibility)等方法配置事件类型及相关信息。
3. 调用本接口发送事件。
4. 发送完成后通过[OH_ArkUI_DestoryAccessibilityEventInfo](#oh_arkui_destoryaccessibilityeventinfo)释放事件信息对象。

**起始版本：** 13


**参数：**

| 参数项                                                                                              | 描述 |
|--------------------------------------------------------------------------------------------------| -- |
| [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)* provider | 第三方平台接入provider句柄。 |
| [ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)* eventInfo                                                      | 表示指向Accessibility事件信息的指针。 |
| void (*callback)(int32_t errorCode)                                                                                         | 表示事件发送完成后的回调函数。errorCode为0表示发送成功，非0表示发送失败的错误码。 |

### OH_ArkUI_AddAndGetAccessibilityElementInfo()

```c
ArkUI_AccessibilityElementInfo* OH_ArkUI_AddAndGetAccessibilityElementInfo(ArkUI_AccessibilityElementInfoList* list)
```

**描述：**


在指定的list中增加element成员，并返回element结构。

> **说明：**
>
> 该接口返回的ArkUI_AccessibilityElementInfo对象由传入的ArkUI_AccessibilityElementInfoList统一管理，生命周期与list绑定，不需要单独调用OH_ArkUI_DestoryAccessibilityElementInfo释放。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfoList](capi-arkui-accessibility-arkui-accessibilityelementinfolist.md)* list | 指定的[ArkUI_AccessibilityElementInfoList](capi-arkui-accessibility-arkui-accessibilityelementinfolist.md)结构，新创建的ElementInfo成员加入该list后返回给函数调用方。 |

**返回：**

| 类型                                  | 说明 |
|-------------------------------------| -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* | 返回创建完成的[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)结构指针；如果创建失败，则返回NULL。 |

### OH_ArkUI_AccessibilityElementInfoSetElementId()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetElementId(ArkUI_AccessibilityElementInfo* elementInfo, int32_t elementId)
```

**描述：**

为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置无障碍元素的唯一标识（elementId）。

> **说明**
> 
> - elementId是无障碍组件树中节点的唯一标识，用于无障碍服务定位和引用特定节点。无障碍服务查找节点信息、执行操作和移动焦点时均依赖此标识。
> - 三方框架需保证同一组件树中各节点的elementId全局唯一，否则可能导致无障碍服务无法正确查找节点。
> - elementId的值由三方框架自行分配和维护，建议使用递增整数或稳定的组件标识。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)指针。 |
| int32_t elementId | 无障碍元素的唯一编号，在当前组件树中必须唯一。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetParentId()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetParentId(ArkUI_AccessibilityElementInfo* elementInfo, int32_t parentId)
```

**描述：**

为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置父节点的无障碍编号（parentId）。

> **说明**
> 
> - parentId用于构建无障碍组件树的层级关系，标识当前节点的父节点。无障碍服务在遍历节点树、查找兄弟节点时依赖父子关系。
> - 若当前节点为根节点，建议将parentId设置为-1或0（与根节点自身的elementId不同即可）。
> - parentId指向的父节点elementId必须在组件树中真实存在，否则无障碍服务向上遍历时可能出现异常。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| int32_t parentId | 表示元素的父组件无障碍编号，应指向已存在的父节点elementId。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetComponentType()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetComponentType(ArkUI_AccessibilityElementInfo* elementInfo, const char* componentType)
```

**描述：**

为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置组件类型。

> **说明**
> 
> - componentType用于标识无障碍节点的组件类型，如Button、Text、Image、List。
> - 无障碍服务（如无障碍辅助应用）根据组件类型决定如何向用户描述和交互该节点。例如，Button类型会被朗读为按钮，Text类型会被朗读为文本。三方框架可使用自身组件类型名称，建议使用与ArkUI组件名称一致的字符串以便获得最佳朗读效果。
> - 建议使用的组件类型名称包括：[Button](arkui-ts/ts-basic-components-button.md)、[Text](arkui-ts/ts-basic-components-text.md)、[Image](arkui-ts/ts-basic-components-image.md)、[List](arkui-ts/ts-container-list.md)、[TextInput](arkui-ts/ts-basic-components-textinput.md)、[Slider](arkui-ts/ts-basic-components-slider.md)、[Rating](arkui-ts/ts-basic-components-rating.md)、[Progress](arkui-ts/ts-basic-components-progress.md)、[CheckBox](arkui-ts/ts-basic-components-checkbox.md)、[Toggle](arkui-ts/ts-basic-components-toggle.md)、[Grid](arkui-ts/ts-container-grid.md)、[Swiper](arkui-ts/ts-container-swiper.md)、[Select](arkui-ts/ts-basic-components-select.md)、[Tab](arkui-ts/ts-container-tabs.md)。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| const char* componentType | 表示元素所属的组件类型字符串，不能为空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetContents()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetContents(ArkUI_AccessibilityElementInfo* elementInfo, const char* contents)
```

**描述：**

为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置组件文本内容。

> **说明**
> 
> - contents是组件的主要文本内容，无障碍辅助应用会将其作为主要播报内容朗读给用户。
> - 对于文本类组件（如[Text](arkui-ts/ts-basic-components-text.md)、[TextInput](arkui-ts/ts-basic-components-textinput.md)），contents通常设置为组件显示的文本。
> - 对于非文本类组件（如[Button](arkui-ts/ts-basic-components-button.md)、[Image](arkui-ts/ts-basic-components-image.md)），若设置了accessibilityText，则无障碍辅助应用优先使用accessibilityText。
> - 通过[OH_ArkUI_AccessibilityElementInfoSetAccessibilityText](#oh_arkui_accessibilityelementinfosetaccessibilitytext)设置accessibilityText，否则使用contents作为朗读内容。
> - 当组件同时设置了contents和accessibilityText时，无障碍辅助应用优先使用accessibilityText。
> - contents不支持传入空指针，传入空指针将返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| const char* contents | 表示元素被无障碍服务所识别的文本内容，不能为空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetHintText()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetHintText(ArkUI_AccessibilityElementInfo* elementInfo, const char* hintText)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置提示文本。

> **说明**
> 
> - hintText用于为组件提供辅助说明，通常用于可编辑组件的占位提示文本（例如输入框）。无障碍辅助应用在组件处于提示状态（isHint为true）时，会朗读hintText代替contents。例如，当输入框为空时显示的占位文本“请输入用户名”，应通过hintText传递。
> - hintText与isHint配合使用：当isHint为true时，无障碍辅助应用播报hintText；当isHint为false时，播报contents。isHint通过[OH_ArkUI_AccessibilityElementInfoSetIsHint](#oh_arkui_accessibilityelementinfosetishint)设置，contents通过[OH_ArkUI_AccessibilityElementInfoSetContents](#oh_arkui_accessibilityelementinfosetcontents)设置。
> - hintText不支持传入空指针，传入空指针将返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| const char* hintText | 表示提示文本，不能为空指针。默认为""。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetAccessibilityText()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityText(ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityText)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置无障碍专用的替代文本。

> **说明**
> 
> - accessibilityText是无障碍专用的替代文本，用于覆盖contents提供给无障碍辅助应用的内容。
> - 当组件设置了accessibilityText且不为空时，无障碍辅助应用会优先播报accessibilityText而非contents。适用于视觉内容需要额外描述的场景，例如：图片组件可设置accessibilityText为“一张大海照片”，即使图片本身无文本内容，无障碍辅助应用也能向用户描述图片含义。
> - 若accessibilityText为空字符串，无障碍辅助应用会回退使用contents。
> - accessibilityText不支持传入空指针，传入空指针将返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| const char* accessibilityText | 表示Accessibility文本，不能为空指针。默认为""。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetAccessibilityDescription()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityDescription(ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityDescription)
```

**描述：**

为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置无障碍描述信息。

> **说明**
> 
> - accessibilityDescription用于为组件提供额外的无障碍描述信息。
> - 无障碍辅助应用在播报完组件的主要内容（accessibilityText或contents）后，会继续播报accessibilityDescription。例如，一个按钮的contents为“提交”，accessibilityDescription可设置为“点击提交表单数据”，无障碍辅助应用将播报“提交，点击提交表单数据”。此属性适用于需要为用户提供额外操作提示或状态说明的场景。
> - accessibilityDescription不支持传入空指针，传入空指针将返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| const char* accessibilityDescription | 表示Accessibility描述信息，不能为空指针。默认为""。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetChildNodeIds()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetChildNodeIds(ArkUI_AccessibilityElementInfo* elementInfo, int32_t childCount, int64_t* childNodeIds)
```

**描述：**

设置[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的子节点数量和子节点ID集合。

> **说明**
> 
> - childNodeIds用于构建无障碍组件树的父子关系，标识当前节点的所有直接子节点。无障碍服务通过childNodeIds遍历子节点来获取完整的无障碍树结构。
> - 每次调用本接口将清空之前设置的所有子节点信息，替换为本次传入的子节点集合（覆盖式更新，非追加）。childNodeIds中的每个值对应已存在的子节点的elementId。
> - childCount必须大于0，且childNodeIds数组中至少包含childCount个有效元素。
> - childNodeIds和elementInfo不支持传入空指针，childCount不支持小于等于0，否则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| int32_t childCount | 表示孩子节点数量，必须大于0。 |
| int64_t* childNodeIds | 表示孩子节点id集合，每个ID应指向已存在的子节点elementId，不能为空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetOperationActions()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetOperationActions(ArkUI_AccessibilityElementInfo* elementInfo,int32_t operationCount, ArkUI_AccessibleAction* operationActions)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置组件支持的无障碍操作列表。

> **说明：**
>
> operationActions用于设置组件支持的无障碍操作集合，每次调用本接口将替换之前设置的所有操作动作（覆盖式更新，非追加）；operationCount必须大于0，且operationActions数组中至少包含operationCount个有效元素。建议根据组件的交互属性注册对应的action类型：可点击组件应包含ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CLICK，可长按组件应包含ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_LONG_CLICK。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| int32_t operationCount | 组件支持的action数量，必须大于0。传入0或负数时返回ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER。 |
| [ArkUI_AccessibleAction](capi-arkui-accessibility-arkui-accessibleaction.md)* operationActions | 组件支持的action数组，数组中应至少包含operationCount个有效元素，不能为空指针。具体支持的action类型可以参考[ArkUI_Accessibility_ActionType](#arkui_accessibility_actiontype)。 |


**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetScreenRect()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetScreenRect(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleRect* screenRect)
```

**描述：**

为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置组件在屏幕上的矩形区域。

> **说明**
> 
> - screenRect定义了组件在屏幕上的位置和大小，以像素为单位。无障碍服务使用screenRect进行焦点高亮绘制、触摸目标定位和元素可见性判断。
> - 无障碍辅助应用等辅助应用依赖screenRect来确定焦点框的显示位置，帮助用户了解当前聚焦元素在屏幕上的位置。
> - 如果screenRect的区域面积为0或不在屏幕可见范围内，该节点可能不会被辅助应用聚焦。
> - screenRect和elementInfo不支持传入空指针，否则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| [ArkUI_AccessibleRect](capi-arkui-accessibility-arkui-accessiblerect.md)* screenRect | 表示屏幕区域，包含左上角和右下角坐标，不能为空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetCheckable()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetCheckable(ArkUI_AccessibilityElementInfo* elementInfo, bool checkable)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置是否可勾选。

> **说明**
> 
> - 适用于具备可勾选语义的组件（例如ArkUI的[CheckBox](arkui-ts/ts-basic-components-checkbox.md)、[Toggle](arkui-ts/ts-basic-components-toggle.md)、[Radio](arkui-ts/ts-basic-components-radio.md)）。
> - 无障碍辅助应用会根据checkable状态向用户播报“可勾选”提示，并告知用户可以通过操作来切换勾选状态。
> - 设置checkable为true时，应同时通过[OH_ArkUI_AccessibilityElementInfoSetChecked](#oh_arkui_accessibilityelementinfosetchecked)来设置checked来表示当前勾选状态。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| bool checkable | 表示是否可勾选。true表示可勾选，false表示不可勾选。默认值false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetChecked()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetChecked(ArkUI_AccessibilityElementInfo* elementInfo, bool checked)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置当前的勾选状态。

> **说明**
> 
> - 无障碍辅助应用会根据checked状态播报“已勾选”或“未勾选”。本接口仅设置勾选状态，不会自动设置checkable属性。
> - 若需要组件被识别为可勾选，需同时调用[OH_ArkUI_AccessibilityElementInfoSetCheckable](#oh_arkui_accessibilityelementinfosetcheckable)设置checkable属性为true。
> - 仅设置checked而不设置checkable为true时，checked状态不会在辅助应用中体现。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| bool checked | 表示是否被勾选。true表示已勾选，false表示未勾选。默认值false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetFocusable()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetFocusable(ArkUI_AccessibilityElementInfo* elementInfo, bool focusable)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置是否可聚焦。

> **说明**
> 
> - 适用于可聚焦的交互组件（例如ArkUI的[TextInput](arkui-ts/ts-basic-components-textinput.md)、[Button](arkui-ts/ts-basic-components-button.md)）。
> - 无障碍辅助应用等辅助应用在遍历可聚焦节点时，会跳过focusable为false的节点。
> - 设置focusable为true的组件通常也需要通过[OH_ArkUI_AccessibilityElementInfoSetClickable](#oh_arkui_accessibilityelementinfosetclickable)设置clickable为true，并注册相应的操作动作，否则用户可能无法通过辅助应用对该组件执行聚焦后的交互操作。
> - focusable与accessibilityFocused是不同的概念：focusable表示输入焦点能力，accessibilityFocused表示无障碍辅助焦点的当前状态。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| bool focusable | 表示是否可聚焦。true表示可聚焦，false表示不可聚焦。默认值false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetFocused()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetFocused(ArkUI_AccessibilityElementInfo* elementInfo, bool isFocused)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置是否已聚焦。

> **说明**
> 
> - 无障碍辅助应用在获焦时会播报当前焦点元素的信息。
> - 设置isFocused为true时，通常应同时通过[OH_ArkUI_AccessibilityElementInfoSetFocusable](#oh_arkui_accessibilityelementinfosetfocusable)设置focusable为true，否则焦点状态的含义不完整。
> - isFocused与accessibilityFocused是不同的概念：isFocused表示输入焦点状态，accessibilityFocused（由[OH_ArkUI_AccessibilityElementInfoSetAccessibilityFocused](#oh_arkui_accessibilityelementinfosetaccessibilityfocused)设置）表示无障碍辅助焦点状态。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| bool isFocused | 表示是否聚焦。true表示已聚焦，false表示未聚焦。默认值false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetVisible()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetVisible(ArkUI_AccessibilityElementInfo* elementInfo, bool isVisible)
```

**描述：**

为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置组件是否在屏幕上可见。

> **说明**
> 
> - 无障碍辅助应用等辅助应用在遍历节点时，默认会跳过isVisible为false的节点，不会对这些节点聚焦或播报。对于因滚动而暂时不在可视区域的组件，建议设置isVisible为false。
> - 若一个可交互组件被错误地设置为不可见，用户将无法通过辅助应用访问该组件。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| bool isVisible | 表示是否可见。true表示可见，false表示不可见。默认值false。所有需要被辅助应用识别的组件必须显式设置为true。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetAccessibilityFocused()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityFocused(ArkUI_AccessibilityElementInfo* elementInfo, bool accessibilityFocused)
```

**描述：**

为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置当前的无障碍辅助焦点状态。

> **说明**
> 
> - 当用户通过辅助应用的焦点移动操作浏览界面时，被聚焦的节点accessibilityFocused应为true。
> - 无障碍辅助应用会对accessibilityFocused为true的节点播报其内容，并在屏幕上绘制焦点高亮框。
> - 无障碍服务在执行[ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_GAIN_ACCESSIBILITY_FOCUS](#arkui_accessibility_actiontype)和[ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CLEAR_ACCESSIBILITY_FOCUS](#arkui_accessibility_actiontype)操作时，三方框架应相应更新此状态，并通过发送[ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_ACCESSIBILITY_FOCUSED](#arkui_accessibilityeventtype)或[ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_ACCESSIBILITY_FOCUS_CLEARED](#arkui_accessibilityeventtype)事件通知系统。
> - accessibilityFocused与isFocused不同：前者是无障碍辅助焦点，后者是输入焦点（键盘焦点）。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| bool accessibilityFocused | 表示是否被无障碍聚焦。true表示被无障碍聚焦，false表示未被无障碍聚焦。默认值false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetSelected()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetSelected(ArkUI_AccessibilityElementInfo* elementInfo, bool selected)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置是否处于选中状态。

> **说明**
> 
> - 适用于具备选中语义的组件（例如ArkUI的[Tab](arkui-ts/ts-container-tabs.md)、[ListItem](arkui-ts/ts-container-listitem.md)）。
> - 无障碍辅助应用会根据selected状态播报“已选中”或“未选中”。在[Tab](arkui-ts/ts-container-tabs.md)页签场景中，selected为true的Tab页签会被朗读为当前活动页签。
> - 在列表场景中，selected可与accessibilityGroup（通过[OH_ArkUI_AccessibilityElementInfoSetAccessibilityGroup](#oh_arkui_accessibilityelementinfosetaccessibilitygroup)设置）配合使用，标记当前激活的列表项。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| bool selected | 表示是否被选中。true表示被选中，false表示未选中。默认值false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetClickable()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetClickable(ArkUI_AccessibilityElementInfo* elementInfo, bool clickable)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置是否支持点击操作。

> **说明**
> 
> - 无障碍辅助应用会向用户提示该组件可点击，用户可通过辅助应用执行点击操作时，系统会通过[ArkUI_AccessibilityProviderCallbacks](capi-arkui-accessibility-arkui-accessibilityprovidercallbacks.md)中的executeAccessibilityAction回调通知三方框架。
> - 设置clickable为true时，通常需要通过[OH_ArkUI_AccessibilityElementInfoSetOperationActions](#oh_arkui_accessibilityelementinfosetoperationactions)在operationActions中添加[ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CLICK](#arkui_accessibility_actiontype)，否则用户无法通过辅助应用对该组件执行点击操作。
> - clickable与enabled（通过[OH_ArkUI_AccessibilityElementInfoSetEnabled](#oh_arkui_accessibilityelementinfosetenabled)设置）应配合使用：当clickable为true但enabled为false时，无障碍辅助应用会播报“已禁用”，提示用户该组件虽可点击但当前不可用。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| bool clickable | 表示是否支持点击。true表示支持，false表示不支持。默认值false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetLongClickable()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetLongClickable(ArkUI_AccessibilityElementInfo* elementInfo, bool longClickable)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置是否支持长按操作。

> **说明**
> 
> - 无障碍辅助应用会向用户提示该组件支持长按，用户可通过辅助应用执行长按操作时，系统会通过[ArkUI_AccessibilityProviderCallbacks](capi-arkui-accessibility-arkui-accessibilityprovidercallbacks.md)中的executeAccessibilityAction回调通知三方框架。
> - 设置longClickable为true时，通常需要通过[OH_ArkUI_AccessibilityElementInfoSetOperationActions](#oh_arkui_accessibilityelementinfosetoperationactions)在operationActions中添加[ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_LONG_CLICK](#arkui_accessibility_actiontype)。
> - 否则用户无法通过辅助应用对该组件执行长按操作。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| bool longClickable | 表示是否支持长按。true表示支持，false表示不支持。默认值false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetEnabled()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetEnabled(ArkUI_AccessibilityElementInfo* elementInfo, bool isEnabled)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置组件是否处于启用状态。

> **说明**
> 
> - 当isEnabled为false时，无障碍辅助应用会播报“已禁用”或“不可用”，提示用户该组件当前不可交互。
> - 对于被禁用的组件（如灰色按钮），应设置isEnabled为false，并通过[OH_ArkUI_AccessibilityElementInfoSetClickable](#oh_arkui_accessibilityelementinfosetclickable)设置clickable为true，这样无障碍辅助应用会提示用户该组件存在但当前不可用。
> - 如果isEnabled为false且clickable也为false，无障碍辅助应用可能完全跳过该组件。
> - 所有需要与用户交互的组件必须显式设置为true。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| bool isEnabled | 表示是否启用。true表示启用，false表示未启用。默认值false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetIsPassword()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetIsPassword(ArkUI_AccessibilityElementInfo* elementInfo, bool isPassword)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置是否为密码输入框。

> **说明**
> 
> - 当isPassword为true时，无障碍辅助应用不会朗读具体的密码字符内容，而是播报“密码框”或“已输入密码”等替代提示，以防止密码被朗读泄露。
> - 对于[TextInput](arkui-ts/ts-basic-components-textinput.md)等文本输入组件，若用于密码输入场景，必须设置isPassword为true。
> - 若未设置或设置为false，无障碍辅助应用可能直接朗读密码内容，造成安全隐患。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| bool isPassword | 表示是否为密码。true表示是密码，false表示不是密码。默认值false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetScrollable()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetScrollable(ArkUI_AccessibilityElementInfo* elementInfo, bool scrollable)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置是否支持滚动操作。

> **说明**
> 
> - 适用于支持内容滚动的容器组件（例如ArkUI的[List](arkui-ts/ts-container-list.md)、[Grid](arkui-ts/ts-container-grid.md)、[Scroll](arkui-ts/ts-container-scroll.md)、[Swiper](arkui-ts/ts-container-swiper.md)）。
> - 无障碍辅助应用等辅助应用会根据scrollable状态向用户提供滚动操作提示，用户可通过辅助应用执行向前滚动（[ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SCROLL_FORWARD](#arkui_accessibility_actiontype)）或向后滚动（[ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SCROLL_BACKWARD](#arkui_accessibility_actiontype)）操作。
> - 设置scrollable为true时，需要通过[OH_ArkUI_AccessibilityElementInfoSetOperationActions](#oh_arkui_accessibilityelementinfosetoperationactions)在operationActions中添加滚动操作，包括[ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SCROLL_FORWARD](#arkui_accessibility_actiontype)和[ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SCROLL_BACKWARD](#arkui_accessibility_actiontype)，否则用户无法通过辅助应用对该组件执行滚动操作。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| bool scrollable | 表示是否支持滚动。true表示支持，false表示不支持。默认值false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetEditable()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetEditable(ArkUI_AccessibilityElementInfo* elementInfo, bool editable)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置文本内容是否可编辑。

> **说明**
> 
> - editable表示该组件的文本内容是否可以被用户编辑，适用于[TextInput](arkui-ts/ts-basic-components-textinput.md)、[TextArea](arkui-ts/ts-basic-components-textarea.md)等可编辑文本组件。
> - 无障碍辅助应用会根据editable状态向用户提示该组件可编辑，并允许用户通过辅助应用输入或修改文本。
> - 设置editable为true的组件，通常还应通过[OH_ArkUI_AccessibilityElementInfoSetOperationActions](#oh_arkui_accessibilityelementinfosetoperationactions)注册相应的无障碍操作动作，如[ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SET_TEXT](#arkui_accessibility_actiontype)、[ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_COPY](#arkui_accessibility_actiontype)、[ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_PASTE](#arkui_accessibility_actiontype)、[ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CUT](#arkui_accessibility_actiontype)等，以便用户通过辅助应用执行编辑操作。
> - editable为true且isPassword（通过[OH_ArkUI_AccessibilityElementInfoSetIsPassword](#oh_arkui_accessibilityelementinfosetispassword)设置）为true时，无障碍辅助应用会播报“密码编辑框”。默认值为false。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| bool editable | 表示是否支持编辑。true表示支持，false表示不支持。默认值false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetIsHint()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetIsHint(ArkUI_AccessibilityElementInfo* elementInfo, bool isHint)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置是否处于提示文本状态。

> **说明**
> 
> - 当isHint为true时，无障碍辅助应用会朗读hintText（提示文本，通过[OH_ArkUI_AccessibilityElementInfoSetHintText](#oh_arkui_accessibilityelementinfosethinttext)设置）而非contents（主文本内容，通过[OH_ArkUI_AccessibilityElementInfoSetContents](#oh_arkui_accessibilityelementinfosetcontents)设置）。
> - 此属性主要用于可编辑文本组件（如[TextInput](arkui-ts/ts-basic-components-textinput.md)）在用户尚未输入内容时显示占位提示文本的场景。
> - 例如：输入框显示“请输入用户名”时，isHint应设为true，hintText应设为“请输入用户名”；用户输入内容后，isHint应设为false，contents应设为用户输入的文本。
> - 若isHint设置为true但未设置hintText，无障碍辅助应用可能播报空内容。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| bool isHint | 表示是否为提示状态。true表示是提示状态，false表示不是提示状态。在提示状态下无障碍辅助应用播报hintText，否则播报contents。默认值false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetRangeInfo()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetRangeInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleRangeInfo* rangeInfo)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置范围值信息。

> **说明**
> 
> - rangeInfo用于设置具有连续范围值的组件的当前值、最小值和最大值，适用于在连续数值范围内取值的组件（例如[Slider](arkui-ts/ts-basic-components-slider.md)、[Rating](arkui-ts/ts-basic-components-rating.md)、[Progress](arkui-ts/ts-basic-components-progress.md)）。
> - 无障碍辅助应用会根据rangeInfo播报当前值和范围，例如“进度50%，范围0到100”。
> - rangeInfo中的current表示当前值，min表示最小值，max表示最大值。
> - 设置rangeInfo时，应确保min不大于max，current应在min和max之间。
> - rangeInfo和elementInfo不支持传入空指针，否则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| [ArkUI_AccessibleRangeInfo](capi-arkui-accessibility-arkui-accessiblerangeinfo.md)* rangeInfo | 表示特定组件的当前值、最大值、最小值，不能为空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetGridInfo()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetGridInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleGridInfo* gridInfo)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置网格信息。

> **说明**
> 
> - gridInfo用于设置网格类容器的行数、列数和选择模式，适用于[Grid](arkui-ts/ts-container-grid.md)、[List](arkui-ts/ts-container-list.md)、[Flex](arkui-ts/ts-container-flex.md)、[Select](arkui-ts/ts-basic-components-select.md)、[Swiper](arkui-ts/ts-container-swiper.md)等容器组件。
> - 无障碍辅助应用会根据gridInfo播报网格的结构信息，如“第2行，共5行3列”。
> - rowCount表示行数，columnCount表示列数，selectionMode表示选择模式（值为0表示单行选择，非0表示多行选择）。
> - gridInfo和elementInfo不支持传入空指针，否则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| [ArkUI_AccessibleGridInfo](capi-arkui-accessibility-arkui-accessiblegridinfo.md)* gridInfo | 表示特定组件的行数、列数以及选择模式，不能为空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetGridItemInfo()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetGridItemInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleGridItemInfo* gridItem)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置网格容器中子项的属性信息。

> **说明**
> 
> - gridItem用于设置[Grid](arkui-ts/ts-container-grid.md)组件中每个子项的属性，包括是否为标题、是否被选中、所在行列下标及跨度信息。适用于网格/列表类容器的子项（例如ArkUI的[Grid](arkui-ts/ts-container-grid.md)、[List](arkui-ts/ts-container-list.md)、[Flex](arkui-ts/ts-container-flex.md)、[Select](arkui-ts/ts-basic-components-select.md)、[Swiper](arkui-ts/ts-container-swiper.md)的子项）。
> - 无障碍辅助应用会根据gridItem的rowIndex和columnIndex播报子项的位置信息，如“第2行第3列”。
> - [ArkUI_AccessibleGridItemInfo](capi-arkui-accessibility-arkui-accessiblegriditeminfo.md)中的heading为true时，无障碍辅助应用会播报“标题”。
> - gridItem和elementInfo不支持传入空指针，否则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| [ArkUI_AccessibleGridItemInfo](capi-arkui-accessibility-arkui-accessiblegriditeminfo.md)* gridItem | 表示网格子项的属性值，不能为空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetSelectedTextStart()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetSelectedTextStart(ArkUI_AccessibilityElementInfo* elementInfo, int32_t selectedTextStart)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置选中文本的起始位置。

> **说明**
>
> - selectedTextStart用于文本类可编辑组件，标记当前选中文本的起始字符索引位置（从0开始计数）。
> - 无障碍辅助应用等辅助应用会根据selectedTextStart和selectedTextEnd播报当前选中的文本范围。
> - 当用户通过辅助应用执行[ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SELECT_TEXT](#arkui_accessibility_actiontype)操作时，三方框架应获取起始位置。
> - 通过[ArkUI_AccessibilityActionArguments](capi-arkui-accessibility-arkui-accessibilityactionarguments.md)中的selectTextBegin参数获取起始位置。
> - selectedTextStart应与selectedTextEnd（通过[OH_ArkUI_AccessibilityElementInfoSetSelectedTextEnd](#oh_arkui_accessibilityelementinfosetselectedtextend)设置）配合使用，且selectedTextStart不应大于selectedTextEnd。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| int32_t selectedTextStart | 文本类控件使用，设置选中文本的起始位置索引（从0开始）。应与selectedTextEnd配合使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetSelectedTextEnd()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetSelectedTextEnd(ArkUI_AccessibilityElementInfo* elementInfo, int32_t selectedTextEnd)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置选中文本的结束位置。

> **说明**
>
> - selectedTextEnd用于文本类可编辑组件，标记当前选中文本的结束字符索引位置（从0开始计数）。
> - 无障碍辅助应用等辅助应用会根据selectedTextStart和selectedTextEnd计算并播报选中的文本内容。
> - selectedTextEnd应与selectedTextStart配合使用，且selectedTextEnd不应小于selectedTextStart。其中selectedTextStart通过[OH_ArkUI_AccessibilityElementInfoSetSelectedTextStart](#oh_arkui_accessibilityelementinfosetselectedtextstart)设置。
> - 当没有文本被选中时，selectedTextStart和selectedTextEnd可以设置为相同的值（即光标位置）。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| int32_t selectedTextEnd | 文本类控件使用，设置选中文本的结束位置索引（从0开始）。应与selectedTextStart配合使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetCurrentItemIndex()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetCurrentItemIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t currentItemIndex)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置当前获焦或高亮子项的位置索引。

> **说明**
> 
> - currentItemIndex用于[List](arkui-ts/ts-container-list.md)、[Select](arkui-ts/ts-basic-components-select.md)、[Swiper](arkui-ts/ts-container-swiper.md)、[Tab](arkui-ts/ts-container-tabs.md)等容器类组件，表示当前获得焦点或处于激活状态的子项在容器中的位置索引（从0开始计数）。
> - 无障碍辅助应用会播报当前项的位置信息，如“第3项，共10项”。
> - currentItemIndex应与itemCount（通过[OH_ArkUI_AccessibilityElementInfoSetItemCount](#oh_arkui_accessibilityelementinfosetitemcount)设置）配合使用，以便辅助应用播报“第X项，共Y项”的完整信息。
> - currentItemIndex的值应在0到itemCount-1的范围内。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| int32_t currentItemIndex | 当前获焦控件的位置索引（从0开始），取值范围为[0, itemCount-1]。应与itemCount配合使用。适用于[List](arkui-ts/ts-container-list.md)、[Select](arkui-ts/ts-basic-components-select.md)、[Swiper](arkui-ts/ts-container-swiper.md)、[Tab](arkui-ts/ts-container-tabs.md)等容器组件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetStartItemIndex()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetStartItemIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t startItemIndex)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置当前屏幕可见区域中第一个元素的位置索引。

> **说明**
> 
> - startItemIndex用于[List](arkui-ts/ts-container-list.md)、[Select](arkui-ts/ts-basic-components-select.md)、[Swiper](arkui-ts/ts-container-swiper.md)、[Tab](arkui-ts/ts-container-tabs.md)等可滚动容器组件，表示当前屏幕可见区域中第一个子项的位置索引（从0开始计数）。
> - 无障碍辅助应用等辅助应用根据startItemIndex和endItemIndex（通过[OH_ArkUI_AccessibilityElementInfoSetEndItemIndex](#oh_arkui_accessibilityelementinfosetenditemindex)设置）判断可见区域范围，用于优化焦点移动和播报。
> - startItemIndex应小于等于endItemIndex，且两者均应在0到itemCount-1的范围内。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| int32_t startItemIndex | 当前屏幕可见区域中第一个元素的位置索引（从0开始）。List、Select、Swiper、[Tab](arkui-ts/ts-container-tabs.md)等容器组件使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetEndItemIndex()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetEndItemIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t endItemIndex)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置当前屏幕可见区域中最后一个元素的位置索引。

> **说明**
> 
> - endItemIndex用于[List](arkui-ts/ts-container-list.md)、[Select](arkui-ts/ts-basic-components-select.md)、[Swiper](arkui-ts/ts-container-swiper.md)、[Tab](arkui-ts/ts-container-tabs.md)等可滚动容器组件，表示当前屏幕可见区域中最后一个子项的位置索引（从0开始计数）。
> - 无障碍辅助应用等辅助应用根据startItemIndex（通过[OH_ArkUI_AccessibilityElementInfoSetStartItemIndex](#oh_arkui_accessibilityelementinfosetstartitemindex)设置）和endItemIndex判断可见区域范围，当用户执行滚动操作时，辅助应用可据此播报滚动进度。
> - endItemIndex应大于等于startItemIndex，且两者均应在0到itemCount-1的范围内。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| int32_t endItemIndex | 当前屏幕可见区域中最后一个元素的位置索引（从0开始），取值范围为[0, itemCount-1]，且应大于等于startItemIndex。List、Select、Swiper、[Tab](arkui-ts/ts-container-tabs.md)等容器组件使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetItemCount()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetItemCount(ArkUI_AccessibilityElementInfo* elementInfo, int32_t itemCount)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置容器中子项的总数。

> **说明**
> 
> - itemCount用于[List](arkui-ts/ts-container-list.md)、[Select](arkui-ts/ts-basic-components-select.md)、[Swiper](arkui-ts/ts-container-swiper.md)、[Tab](arkui-ts/ts-container-tabs.md)等容器类组件，表示容器中子项的总数量。
> - 无障碍辅助应用等辅助应用结合currentItemIndex（通过[OH_ArkUI_AccessibilityElementInfoSetCurrentItemIndex](#oh_arkui_accessibilityelementinfosetcurrentitemindex)设置）和itemCount播报位置信息，如“第3项，共10项”。
> - itemCount的值应为容器中所有子项的总数（包括可见和不可见的），而不仅是当前屏幕可见区域的子项数。
> - itemCount应为非负整数，设置为0表示容器为空。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| int32_t itemCount | 表示容器中子项的总数（包括可见和不可见的），应为非负整数，0表示容器为空。用于辅助应用播报“第X项，共Y项”。如[List](arkui-ts/ts-container-list.md)、[Select](arkui-ts/ts-basic-components-select.md)、[Swiper](arkui-ts/ts-container-swiper.md)、[Tab](arkui-ts/ts-container-tabs.md)等容器组件使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetAccessibilityOffset()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityOffset(ArkUI_AccessibilityElementInfo* elementInfo, int32_t offset)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置滚动偏移量。

> **说明**
> 
> - offset用于可滚动类容器组件（如[List](arkui-ts/ts-container-list.md)、[Grid](arkui-ts/ts-container-grid.md)、[Scroll](arkui-ts/ts-container-scroll.md)），表示内容区相对于元素顶部坐标的滚动像素偏移量。
> - 无障碍服务使用offset来判断滚动位置，辅助应用可据此播报滚动进度。
> - 当用户执行[ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SCROLL_FORWARD](#arkui_accessibility_actiontype)或[ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SCROLL_BACKWARD](#arkui_accessibility_actiontype)操作后，三方框架应在更新后的节点信息中同步更新offset值。
> - offset为0表示内容区未滚动（处于初始位置），正值表示向下/向右滚动的像素距离。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| int32_t offset | 对于可滚动类容器组件，如[List](arkui-ts/ts-container-list.md)、[Grid](arkui-ts/ts-container-grid.md)，内容区相对于元素顶部坐标的滚动像素偏移量（单位：像素）。offset为0表示未滚动，正值表示已滚动的距离。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetAccessibilityGroup()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityGroup(ArkUI_AccessibilityElementInfo* elementInfo, bool accessibilityGroup)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置无障碍分组。

> **说明**
> 
> - accessibilityGroup表示是否将该组件及其所有子组件作为一个整体对待。
> - 当accessibilityGroup为true时，无障碍辅助应用会将该节点视为一个整体，不会单独聚焦或播报其子节点的信息，而是将子节点的文本内容合并后一起播报。
> - 此属性适用于将一组相关内容（如一个列表项包含图标和文本）作为一个无障碍单元的场景。例如：一个列表项包含商品图片和商品名称，设置accessibilityGroup为true后，无障碍辅助应用会将整个列表项作为一个节点播报，而不是分别播报图片和文本。
> - accessibilityGroup为false时，无障碍辅助应用会逐个遍历子节点。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| bool accessibilityGroup | 表示是否启用无障碍分组。true表示将组件及其子组件作为一个整体播报，false表示逐个遍历子节点。默认值false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetAccessibilityLevel()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityLevel(ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityLevel)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置无障碍重要性级别。

> **说明**
> 
> - accessibilityLevel用于控制组件是否被无障碍辅助服务识别，影响无障碍节点树中该节点的可见性。
> - 无障碍辅助应用等辅助应用根据accessibilityLevel决定是否向用户展示该节点。
> - 取值范围及含义如下：
> - “auto”：由系统根据当前组件的属性自动判断该组件是否重要，决定是否让辅助服务识别该组件。通常具有可交互属性（如clickable）或文本内容的组件会被自动识别为重要。
> - “yes”：表示该组件重要，允许辅助服务识别该组件。无论组件属性如何，辅助服务都会识别。
> - “no”：表示该组件不重要，不允许辅助服务识别该组件。辅助服务会跳过该节点，但其子节点仍可被识别。
> - “no-hide-descendants”：表示该组件及其所有子孙节点都不重要，辅助服务不会识别该组件及其子孙节点。适用于纯装饰性容器，避免辅助服务播报无意义的内容。
> - accessibilityLevel不支持传入空指针，传入空指针将返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| const char* accessibilityLevel | 表示组件的无障碍重要性级别，取值为“auto”/“yes”/“no”/“no-hide-descendants”，不能为空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetZIndex()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetZIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t zIndex)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置组件的Z序。

> **说明**
> 
> - zIndex用于控制元素在垂直于屏幕的Z轴上的层级位置。当多个组件在屏幕上重叠时，zIndex值较大的组件会覆盖zIndex值较小的组件。
> - 此属性主要供UiTest自动化测试框架使用，用于识别组件的层叠顺序。
> - 无障碍服务在确定焦点移动方向时也可能参考zIndex进行判断。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| int32_t zIndex | 组件z序，用于控制元素在垂直于屏幕的z轴上的位置。[UiTest](../apis-test-kit/js-apis-uitest.md)需要使用。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetAccessibilityOpacity()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityOpacity(ArkUI_AccessibilityElementInfo* elementInfo, float opacity)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置透明度。

> **说明**
> 
> - opacity表示组件的透明度。此属性主要供UiTest自动化测试框架使用，用于识别组件的视觉透明状态。取值范围为0到1，其中1表示完全不透明，0表示完全透明。
> - 注意：传入NaN值将返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)，但超出0到1范围的值（如负数或大于1的值）不会被自动修正，建议始终传入0到1之间的有效值。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| float opacity | 表示透明度。取值范围[0, 1]，包含0和1，其中1表示完全不透明，0表示完全透明。超出范围时按边界值截断处理。[UiTest](../apis-test-kit/js-apis-uitest.md)需要使用。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetBackgroundColor()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetBackgroundColor(ArkUI_AccessibilityElementInfo* elementInfo, const char* backgroundColor)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置背景色。

> **说明**
> 
> - backgroundColor表示组件的背景颜色。此属性主要供UiTest自动化测试框架使用，用于识别组件的视觉背景色。
> - 数据格式为“#ARGB”字符串，例如非透明白色为“#FFFFFFFF”，半透明红色为“#80FF0000”。
> - backgroundColor不支持传入空指针，传入空指针将返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| const char* backgroundColor | 表示背景色。数据为“#ARGB”格式，例如非透明白色即“#FFFFFFFF”。不能为空指针。[UiTest](../apis-test-kit/js-apis-uitest.md)需要使用。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetBackgroundImage()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetBackgroundImage(ArkUI_AccessibilityElementInfo* elementInfo, const char* backgroundImage)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置背景图片。

> **说明**
> 
> - backgroundImage表示组件的背景图片资源。此属性主要供UiTest自动化测试框架使用，用于识别组件的视觉背景图。
> - backgroundImage不支持传入空指针，传入空指针将返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| const char* backgroundImage | 表示背景图片的资源路径字符串。不能为空指针。[UiTest](../apis-test-kit/js-apis-uitest.md)需要使用。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetBlur()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetBlur(ArkUI_AccessibilityElementInfo* elementInfo, const char* blur)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置模糊效果。

> **说明**
> 
> - blur表示组件的模糊效果参数。此属性主要供UiTest自动化测试框架使用，用于识别组件的视觉模糊状态。
> - blur不支持传入空指针，传入空指针将返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| const char* blur | 表示模糊度参数字符串。具体取值格式参考ArkUI组件对应模糊度属性的取值规范。不能为空指针。[UiTest](../apis-test-kit/js-apis-uitest.md)需要使用。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetHitTestBehavior()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetHitTestBehavior(ArkUI_AccessibilityElementInfo* elementInfo, const char* hitTestBehavior)
```

**描述：**


为[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置触摸测试的响应逻辑及节点阻塞规则。

> **说明**
> 
> - hitTestBehavior用于控制组件在触摸测试过程中的响应行为，决定触摸事件是否可以穿透该组件。
> - 此属性主要供UiTest自动化测试框架使用。取值范围参考HitTestMode，包括：
> - “Default”：默认行为，不阻断触摸事件。
> - “Block”：阻断自身及子组件的触摸事件。
> - “Transparent”：自身不响应触摸事件，但子组件可以响应。
> - “None”：自身和子组件都不响应触摸事件。
> - hitTestBehavior不支持传入空指针，传入空指针将返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |
| const char* hitTestBehavior | 表示触摸测试响应模式，取值为“Default”（默认行为，不阻断触摸事件）、“Block”（阻断自身及子组件的触摸事件）、“Transparent”（自身不响应但子组件可响应）、“None”（自身和子组件都不响应），不能为空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityElementInfoSetComponentIdentifier()

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetComponentIdentifier(ArkUI_AccessibilityElementInfo* elementInfo, const char* identifier)
```

**描述：**


为无障碍节点信息[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)设置组件标识，可用于自动化测试识别特定组件。

**起始版本：** 24


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向ArkUI_AccessibilityElementInfo的指针。 |
| const char* identifier | 表示组件的唯一标识字符串，不能为空指针。<br>需保证上报的组件树中的组件标识唯一，且字符串长度不大于1024，超过1024会截断使用。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_CreateAccessibilityElementInfo()

```c
ArkUI_AccessibilityElementInfo* OH_ArkUI_CreateAccessibilityElementInfo(void)
```

**描述：**


创建一个[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)对象，创建后需要调用[OH_ArkUI_DestoryAccessibilityElementInfo](#oh_arkui_destoryaccessibilityelementinfo)释放。

**起始版本：** 13

**返回：**

| 类型                                  | 说明 |
|-------------------------------------| -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* | 返回新创建的[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)对象指针，用于承载无障碍节点信息；如果创建失败，则返回NULL。 |

### OH_ArkUI_DestoryAccessibilityElementInfo()

```c
void OH_ArkUI_DestoryAccessibilityElementInfo(ArkUI_AccessibilityElementInfo* elementInfo)
```

**描述：**


销毁一个[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)对象。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示指向[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)的指针。 |

### OH_ArkUI_CreateAccessibilityEventInfo()

```c
ArkUI_AccessibilityEventInfo* OH_ArkUI_CreateAccessibilityEventInfo(void)
```

**描述：**


创建一个[ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)对象，创建后需要调用[OH_ArkUI_DestoryAccessibilityEventInfo](#oh_arkui_destoryaccessibilityeventinfo)释放。

**起始版本：** 13

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)* | 返回新创建的[ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)对象指针，用于承载无障碍事件信息；如果创建失败，则返回NULL。 |

### OH_ArkUI_DestoryAccessibilityEventInfo()

```c
void OH_ArkUI_DestoryAccessibilityEventInfo(ArkUI_AccessibilityEventInfo* eventInfo)
```

**描述：**


销毁[ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)对象。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)* eventInfo | 需要被销毁的[ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)对象。 |

### OH_ArkUI_AccessibilityEventSetEventType()

```c
int32_t OH_ArkUI_AccessibilityEventSetEventType(ArkUI_AccessibilityEventInfo* eventInfo,  ArkUI_AccessibilityEventType eventType)
```

**描述：**


为[ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)设置事件类型。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)* eventInfo | 表示指向[ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)的指针。 |
| [ArkUI_AccessibilityEventType](#arkui_accessibilityeventtype) eventType | 表示事件类型，可选值参考[ArkUI_AccessibilityEventType](#arkui_accessibilityeventtype)枚举定义，如点击事件、长按事件、文本更新事件、焦点事件、页面更新事件等。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityEventSetTextAnnouncedForAccessibility()

```c
int32_t OH_ArkUI_AccessibilityEventSetTextAnnouncedForAccessibility(ArkUI_AccessibilityEventInfo* eventInfo,  const char* textAnnouncedForAccessibility)
```

**描述：**


为[ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)设置主动播报的内容。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)* eventInfo | 表示事件信息。 |
| const char* textAnnouncedForAccessibility | 表示主动播报的内容，不能为空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityEventSetRequestFocusId()

```c
int32_t OH_ArkUI_AccessibilityEventSetRequestFocusId(ArkUI_AccessibilityEventInfo* eventInfo,  int32_t requestFocusId)
```

**描述：**


为[ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)设置请求焦点id。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)* eventInfo | 表示事件信息。 |
| int32_t requestFocusId | 表示请求聚焦的无障碍元素编号，需与ArkUI_AccessibilityElementInfo中设置的elementId一致，用于通知无障碍服务聚焦到指定节点。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_AccessibilityEventSetElementInfo()

```c
int32_t OH_ArkUI_AccessibilityEventSetElementInfo(ArkUI_AccessibilityEventInfo* eventInfo,  ArkUI_AccessibilityElementInfo* elementInfo)
```

**描述：**


为[ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)设置elementInfo。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)* eventInfo | 表示事件信息。 |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | 表示[ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)元素信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_FindAccessibilityActionArgumentByKey()

```c
int32_t OH_ArkUI_FindAccessibilityActionArgumentByKey(ArkUI_AccessibilityActionArguments* arguments, const char* key, char** value)
```

**描述：**


获取[ArkUI_AccessibilityActionArguments](capi-arkui-accessibility-arkui-accessibilityactionarguments.md)中指定key的value值。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityActionArguments](capi-arkui-accessibility-arkui-accessibilityactionarguments.md)* arguments | 表示指向[ArkUI_AccessibilityActionArguments](capi-arkui-accessibility-arkui-accessibilityactionarguments.md)的指针。 |
| const char* key | 表示要查找的参数键名。key的取值需与ArkUI_AccessibilityActionArguments中设置的key一致。 |
| char** value | 表示用于接收查找到的value值的二级指针（输出参数）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### OH_ArkUI_NativeModule_GetNativeAccessibilityProvider()

```c
int32_t OH_ArkUI_NativeModule_GetNativeAccessibilityProvider(ArkUI_NodeHandle* node, ArkUI_AccessibilityProvider** provider)
```

**描述：**

获取指向[ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)对象指针的二级指针变量。

其中[ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)对象与传入的[ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md)的实例一一对应。

三方框架将自身UI组件映射为[ARKUI_NODE_CUSTOM](capi-native-node-h.md#arkui_nodetype)类型的[RenderNode](js-apis-arkui-renderNode.md)并得到[ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md)。

再调用OH_ArkUI_NativeModule_GetNativeAccessibilityProvider接口获取[ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)指针并注册无障碍回调。

最终实现ArkUI无障碍服务对三方框架UI的识别与事件触发。

仅当三方框架将自身UI组件映射为[ARKUI_NODE_CUSTOM](capi-native-node-h.md#arkui_nodetype)的[RenderNode](js-apis-arkui-renderNode.md)，该接口才会生效，否则会报错误码。

本接口通过[RenderNode](js-apis-arkui-renderNode.md)实现三方框架的接入，仅支持[ARKUI_NODE_CUSTOM](capi-native-node-h.md#arkui_nodetype)接入无障碍服务，可以实现无障碍控件树获取能力。

不支持多线程并发，由三方框架保证调用时的线程安全。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md)* node | 指向一个[ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md)对象的指针。|
| [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)** provider | 表示指向[ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)指针的二级指针（输出参数），用于接收ArkUI_AccessibilityProvider对象指针，该对象用于注册无障碍回调函数。不能为空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回状态码。<br>成功返回[ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>参数错误返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。<br>参数错误：1. 传入的参数node或者provider为空指针。<br>2. node对应的ArkUI_NodeHandle类型不为ARKUI_NODE_CUSTOM。 |
