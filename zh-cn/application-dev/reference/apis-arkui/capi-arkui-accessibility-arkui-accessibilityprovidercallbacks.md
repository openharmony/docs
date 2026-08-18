# ArkUI_AccessibilityProviderCallbacks
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyinhua-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct ArkUI_AccessibilityProviderCallbacks {...} ArkUI_AccessibilityProviderCallbacks
```

## 概述

第三方[provider](capi-arkui-accessibility-arkui-accessibilityprovider.md)回调函数结构定义，需要第三方平台实现的相关函数，通过[OH_ArkUI_AccessibilityProviderRegisterCallback](capi-native-interface-accessibility-h.md#oh_arkui_accessibilityproviderregistercallback)注册到系统侧。适用于读屏软件、语音控制、开关控制等无障碍辅助场景，第三方平台通过实现这些回调响应系统的无障碍查询和操作请求。

**起始版本：** 13

**相关模块：** [ArkUI_Accessibility](capi-arkui-accessibility.md)

**所在头文件：** [native_interface_accessibility.h](capi-native-interface-accessibility-h.md)

## 汇总

### 成员函数

| 名称 | 描述 |
| -- | -- |
| [int32_t (\*findAccessibilityNodeInfosById)(int64_t elementId, ArkUI_AccessibilitySearchMode mode, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)](#findaccessibilitynodeinfosbyid) | 查询指定节点的节点信息。由接入方平台实现的回调函数，注册给系统侧调用。 |
| [int32_t (\*findAccessibilityNodeInfosByText)(int64_t elementId, const char* text, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)](#findaccessibilitynodeinfosbytext) | 基于指定的节点，查询满足指定文本内容的节点信息。由接入方平台实现的回调函数，注册给系统侧调用。 |
| [int32_t (\*findFocusedAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusType focusType, int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)](#findfocusedaccessibilitynode) | 从指定节点出发，根据焦点类型查找当前已获得焦点的节点，并将该节点元素信息返回。由接入方平台实现的回调函数，注册给系统侧调用。 |
| [int32_t (\*findNextFocusAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusMoveDirection direction, int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)](#findnextfocusaccessibilitynode) | 根据参考节点和查找方向，查询下一个可以聚焦的节点。由接入方平台实现的回调函数，注册给系统侧调用。 |
| [int32_t (\*executeAccessibilityAction)(int64_t elementId, ArkUI_Accessibility_ActionType action, ArkUI_AccessibilityActionArguments *actionArguments, int32_t requestId)](#executeaccessibilityaction) | 在指定的无障碍节点上执行无障碍Action操作。由接入方平台实现的回调函数，注册给系统侧调用。 |
| [int32_t (\*clearFocusedFocusAccessibilityNode)()](#clearfocusedfocusaccessibilitynode) | 清除当前焦点节点的焦点状态。例如，当无障碍服务需要重置焦点高亮或用户切换到其他交互区域时触发。由接入方平台实现的回调函数，注册给系统侧调用。 |
| [int32_t (\*getAccessibilityNodeCursorPosition)(int64_t elementId, int32_t requestId, int32_t* index)](#getaccessibilitynodecursorposition) | 查询指定节点的当前光标位置。例如，当读屏软件需要播报光标位置或语音输入法定位文本插入点时触发。由接入方平台实现的回调函数，注册给系统侧调用。 |

## 成员函数说明

### findAccessibilityNodeInfosById()

```c
int32_t (*findAccessibilityNodeInfosById)(int64_t elementId, ArkUI_AccessibilitySearchMode mode, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)
```

**描述：**


查询指定节点的节点信息。由接入方平台实现的回调函数，注册给系统侧调用。

**起始版本：** 13

**参数：**

| 参数项                                                                            | 描述 |
|--------------------------------------------------------------------------------| -- |
| int64_t elementId                                                              | 无障碍元素的唯一编号，取值应为系统已分配的有效元素ID。 |
| [ArkUI_AccessibilitySearchMode](capi-native-interface-accessibility-h.md#arkui_accessibilitysearchmode) mode | 表示无障碍搜索模式。具体取值及含义参见[ArkUI_AccessibilitySearchMode](capi-native-interface-accessibility-h.md#arkui_accessibilitysearchmode)。 |
| int32_t requestId                                                              | 表示请求ID，由系统侧生成，用于标识一次无障碍请求。 |
| [ArkUI_AccessibilityElementInfoList](capi-arkui-accessibility-arkui-accessibilityelementinfolist.md)* elementList                            | 表示无障碍元素信息列表。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)，表示操作成功。<br>[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)，表示参数错误。可能原因：传入的elementId无效或elementList为空指针。处理步骤：请检查参数elementId、mode、elementList的有效性。 |

### findAccessibilityNodeInfosByText()

```c
int32_t (*findAccessibilityNodeInfosByText)(int64_t elementId, const char* text, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)
```

**描述：**

基于指定的节点，查询满足指定文本内容的节点信息。由接入方平台实现的回调函数，注册给系统侧调用。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int64_t elementId | 无障碍元素的唯一编号。 |
|  const char* text | 表示用于查找节点的文本内容。 |
|  int32_t requestId | 表示请求ID。 |
| [ArkUI_AccessibilityElementInfoList](capi-arkui-accessibility-arkui-accessibilityelementinfolist.md)* elementList | 表示无障碍元素信息列表。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)，表示操作成功。<br>[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)，表示参数错误。 |

### findFocusedAccessibilityNode()

```c
int32_t (*findFocusedAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusType focusType, int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)
```

**描述：**

从指定节点出发，根据焦点类型查找当前已获得焦点的节点，并将该节点元素信息返回。由接入方平台实现的回调函数，注册给系统侧调用。

**起始版本：** 13

**参数：**

| 参数项                                                                                                             | 描述 |
|-----------------------------------------------------------------------------------------------------------------| -- |
| int64_t elementId                                                                                               | 无障碍元素的唯一编号。 |
| [ArkUI_AccessibilityFocusType](capi-native-interface-accessibility-h.md#arkui_accessibilityfocustype) focusType | 表示焦点的类型。具体取值及含义参见[ArkUI_AccessibilityFocusType](capi-native-interface-accessibility-h.md#arkui_accessibilityfocustype)。 |
| int32_t requestId                                                                                               | 表示请求ID。 |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo                                                                 | 表示查询到的无障碍元素信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)，表示操作成功。<br>[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)，表示参数错误。 |

### findNextFocusAccessibilityNode()

```c
int32_t (*findNextFocusAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusMoveDirection direction, int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)
```

**描述：**

根据参考节点和查找方向，查询下一个可以聚焦的节点。由接入方平台实现的回调函数，注册给系统侧调用。

**起始版本：** 13

**参数：**

| 参数项                                                                                                                               | 描述 |
|-----------------------------------------------------------------------------------------------------------------------------------| -- |
| int64_t elementId                                                                                                                 | 无障碍元素的唯一编号。 |
| [ArkUI_AccessibilityFocusMoveDirection](capi-native-interface-accessibility-h.md#arkui_accessibilityfocusmovedirection) direction | 表示查找方向。具体取值及含义参见[ArkUI_AccessibilityFocusMoveDirection](capi-native-interface-accessibility-h.md#arkui_accessibilityfocusmovedirection)。 |
| int32_t requestId                                                                                                                 | 表示请求ID。 |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo                                                                                       | 表示无障碍元素信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)，表示操作成功。<br>[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)，表示参数错误。 |

### executeAccessibilityAction()

```c
int32_t (*executeAccessibilityAction)(int64_t elementId, ArkUI_Accessibility_ActionType action, ArkUI_AccessibilityActionArguments *actionArguments, int32_t requestId)
```

**描述：**

在指定的无障碍节点上执行无障碍Action操作。例如，当读屏软件用户通过语音指令或开关控制触发点击、滚动、选择等操作时，系统通过此回调通知第三方平台执行相应动作。由接入方平台实现的回调函数，注册给系统侧调用。

**起始版本：** 13

**参数：**

| 参数项                                                                                                              | 描述 |
|------------------------------------------------------------------------------------------------------------------| -- |
| int64_t elementId                                                                                                | 无障碍元素的唯一编号。 |
| [ArkUI_Accessibility_ActionType](capi-native-interface-accessibility-h.md#arkui_accessibility_actiontype) action | 表示要执行的动作。具体取值及含义参见[ArkUI_Accessibility_ActionType](capi-native-interface-accessibility-h.md#arkui_accessibility_actiontype)。 |
| [ArkUI_AccessibilityActionArguments](capi-arkui-accessibility-arkui-accessibilityactionarguments.md) *actionArguments                                                          | 表示动作的参数。 |
| int32_t requestId                                                                                                | 表示请求ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)，表示操作成功。<br>[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)，表示参数错误。 |

### clearFocusedFocusAccessibilityNode()

```c
int32_t (*clearFocusedFocusAccessibilityNode)()
```

**描述：**

清除当前焦点节点的焦点状态。由接入方平台实现的回调函数，注册给系统侧调用。

**起始版本：** 13

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)，表示操作成功。<br>[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)，表示参数错误。 |

### getAccessibilityNodeCursorPosition()

```c
int32_t (*getAccessibilityNodeCursorPosition)(int64_t elementId, int32_t requestId, int32_t* index)
```

**描述：**

查询指定节点的当前光标位置。由接入方平台实现的回调函数，注册给系统侧调用。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int64_t elementId | 无障碍元素的唯一编号。 |
|  int32_t requestId | 表示请求ID。 |
|  int32_t* index | 表示光标位置的索引，取值为非负整数，表示光标在文本中的字符位置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)，表示操作成功。<br>[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)，表示参数错误。 |


