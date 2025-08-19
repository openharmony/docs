# ArkUI_AccessibilityProviderCallbacks
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhanghangkai10241-->
<!--Designer: @lmleon-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @HelloCrease-->

## 概述

第三方操作provider回调函数结构定义，需要第三方平台实现的相关函数，通过OH_ArkUI_AccessibilityProviderRegisterCallback注册到系统侧。

**起始版本：** 13

**相关模块：** [ArkUI_Accessibility](capi-arkui-accessibility.md)

**所在头文件：** [native_interface_accessibility.h](capi-native-interface-accessibility-h.md)

## 汇总

### 成员函数

| 名称 | 描述 |
| -- | -- |
| [int32_t (\*findAccessibilityNodeInfosById)(int64_t elementId, ArkUI_AccessibilitySearchMode mode,int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)](#findaccessibilitynodeinfosbyid) | 由接入方平台实现的回调函数，注册给系统侧调用。查询指定节点的节点信息。支持多实例场景。 |
| [int32_t (\*findAccessibilityNodeInfosByText)(int64_t elementId, const char* text, int32_t requestId,ArkUI_AccessibilityElementInfoList* elementList)](#findaccessibilitynodeinfosbytext) | 由接入方平台实现的回调函数，注册给系统侧调用。基于指定的节点，查询满足指定text内容的节点信息。 |
| [int32_t (\*findFocusedAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusType focusType,int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)](#findfocusedaccessibilitynode) | 当需要基于指定节点获取焦点元素信息时调用。 |
| [int32_t (\*findNextFocusAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusMoveDirection direction,int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)](#findnextfocusaccessibilitynode) | 根据参考节点查询可以聚焦的节点，根据模式和方向查询下一个可以聚焦的节点。 |
| [int32_t (\*executeAccessibilityAction)(int64_t elementId, ArkUI_Accessibility_ActionType action,ArkUI_AccessibilityActionArguments *actionArguments, int32_t requestId)](#executeaccessibilityaction) | 在指定节点上执行Action操作。 |
| [int32_t (\*clearFocusedFocusAccessibilityNode)()](#clearfocusedfocusaccessibilitynode) | 清除当前焦点节点的焦点状态。 |
| [int32_t (\*getAccessibilityNodeCursorPosition)(int64_t elementId, int32_t requestId, int32_t* index)](#getaccessibilitynodecursorposition) | 查询指定节点的当前光标位置。 |

## 成员函数说明

### findAccessibilityNodeInfosById()

```
int32_t (*findAccessibilityNodeInfosById)(int64_t elementId, ArkUI_AccessibilitySearchMode mode,int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)
```

**描述：**


由接入方平台实现的回调函数，注册给系统侧调用。查询指定节点的节点信息。支持多实例场景。

**起始版本：** 13

**参数：**

| 参数项                                                                            | 描述 |
|--------------------------------------------------------------------------------| -- |
| int64_t elementId                                                              | 表示元素ID。 |
| [ArkUI_AccessibilitySearchMode](capi-native-interface-accessibility-h.md) mode | 表示无障碍搜索模式。 |
| int32_t requestId                                                              | 表示请求ID。 |
| [ArkUI_AccessibilityElementInfoList](capi-arkui-accessibility-arkui-accessibilityelementinfolist.md)* elementList                            | 表示无障碍元素信息列表。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功，则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>如果参数错误，则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### findAccessibilityNodeInfosByText()

```
int32_t (*findAccessibilityNodeInfosByText)(int64_t elementId, const char* text, int32_t requestId,ArkUI_AccessibilityElementInfoList* elementList)
```

**描述：**

由接入方平台实现的回调函数，注册给系统侧调用。基于指定的节点，查询满足指定text内容的节点信息。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int64_t elementId | 表示元素ID。 |
|  const char* text | 表示无障碍文本。 |
|  int32_t requestId | 表示请求ID。 |
| [ArkUI_AccessibilityElementInfoList](capi-arkui-accessibility-arkui-accessibilityelementinfolist.md)* elementList | 表示无障碍元素信息列表。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功，则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>如果参数错误，则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### findFocusedAccessibilityNode()

```
int32_t (*findFocusedAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusType focusType,int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)
```

**描述：**

当需要基于指定节点获取焦点元素信息时调用。

**起始版本：** 13

**参数：**

| 参数项                                                                                                             | 描述 |
|-----------------------------------------------------------------------------------------------------------------| -- |
| int64_t elementId                                                                                               | 表示元素ID。 |
| [ArkUI_AccessibilityFocusType](capi-native-interface-accessibility-h.md#arkui_accessibilityfocustype) focusType | 表示焦点的类型。 |
| int32_t requestId                                                                                               | 表示请求ID。 |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo                                                                 | 表示无障碍元素信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功，则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>如果参数错误，则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### findNextFocusAccessibilityNode()

```
int32_t (*findNextFocusAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusMoveDirection direction,int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)
```

**描述：**

根据参考节点查询可以聚焦的节点，根据模式和方向查询下一个可以聚焦的节点。

**起始版本：** 13

**参数：**

| 参数项                                                                                                                               | 描述 |
|-----------------------------------------------------------------------------------------------------------------------------------| -- |
| int64_t elementId                                                                                                                 | 表示元素ID。 |
| [ArkUI_AccessibilityFocusMoveDirection](capi-native-interface-accessibility-h.md#arkui_accessibilityfocusmovedirection) direction | 表示查找方向。 |
| int32_t requestId                                                                                                                 | 表示请求ID。 |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo                                                                                       | 表示无障碍元素信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功，则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>如果参数错误，则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### executeAccessibilityAction()

```
int32_t (*executeAccessibilityAction)(int64_t elementId, ArkUI_Accessibility_ActionType action,ArkUI_AccessibilityActionArguments *actionArguments, int32_t requestId)
```

**描述：**

在指定节点上执行Action操作。

**起始版本：** 13

**参数：**

| 参数项                                                                                                              | 描述 |
|------------------------------------------------------------------------------------------------------------------| -- |
| int64_t elementId                                                                                                | 表示元素ID。 |
| [ArkUI_Accessibility_ActionType](capi-native-interface-accessibility-h.md#arkui_accessibility_actiontype) action | 表示要执行的动作。 |
| [ArkUI_AccessibilityActionArguments](capi-arkui-accessibility-arkui-accessibilityactionarguments.md) *actionArguments                                                          | 表示动作的参数。 |
| int32_t requestId                                                                                                | 表示请求的ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功，则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>如果参数错误，则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### clearFocusedFocusAccessibilityNode()

```
int32_t (*clearFocusedFocusAccessibilityNode)()
```

**描述：**

清除当前焦点节点的焦点状态。

**起始版本：** 13

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功，则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>如果参数错误，则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### getAccessibilityNodeCursorPosition()

```
int32_t (*getAccessibilityNodeCursorPosition)(int64_t elementId, int32_t requestId, int32_t* index)
```

**描述：**

查询指定节点的当前光标位置。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int64_t elementId | 表示元素ID。 |
|  int32_t requestId | 表示请求的ID。 |
|  int32_t* index | 表示光标位置的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功，则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>如果参数错误，则返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |


