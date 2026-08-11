# ArkUI_AccessibilityProviderCallbacksWithInstance
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyinhua-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct ArkUI_AccessibilityProviderCallbacksWithInstance {...} ArkUI_AccessibilityProviderCallbacksWithInstance
```

## 概述

适配多实例场景第三方操作[provider](capi-arkui-accessibility-arkui-accessibilityprovider.md)回调函数结构定义，包含节点信息查询、焦点查找与清除、操作执行、光标位置获取等无障碍相关回调函数。该结构需由第三方平台实现，并通过[OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance](capi-native-interface-accessibility-h.md#oh_arkui_accessibilityproviderregistercallbackwithinstance)注册到系统侧，以支持第三方平台接入系统无障碍服务。

**起始版本：** 15

**相关模块：** [ArkUI_Accessibility](capi-arkui-accessibility.md)

**所在头文件：** [native_interface_accessibility.h](capi-native-interface-accessibility-h.md)

## 汇总

### 成员函数

| 名称 | 描述 |
| -- | -- |
| [int32_t (\*findAccessibilityNodeInfosById)(const char* instanceId, int64_t elementId,ArkUI_AccessibilitySearchMode mode, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)](#findaccessibilitynodeinfosbyid) | 基于指定的节点，根据搜索模式查询对应的节点信息。支持多实例场景。由接入方平台实现的回调函数，注册给系统侧调用。 |
| [int32_t (\*findAccessibilityNodeInfosByText)(const char* instanceId, int64_t elementId, const char* text,int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)](#findaccessibilitynodeinfosbytext) | 基于指定的节点，查询文本内容匹配指定文本的节点信息。支持多实例场景。由接入方平台实现的回调函数，注册给系统侧调用。 |
| [int32_t (\*findFocusedAccessibilityNode)(const char* instanceId, int64_t elementId,ArkUI_AccessibilityFocusType focusType, int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)](#findfocusedaccessibilitynode) | 从指定节点查找已经聚焦的节点。由接入方平台实现的回调函数，注册给系统侧调用。支持多实例场景。**使用场景**：当无障碍服务需要确定当前焦点所在元素（如屏幕阅读器朗读当前焦点元素内容）时，通过此回调向接入方平台查询。 |
| [int32_t (\*findNextFocusAccessibilityNode)(const char* instanceId, int64_t elementId, ArkUI_AccessibilityFocusMoveDirection direction,int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)](#findnextfocusaccessibilitynode) | 从指定节点查询指定方向的下一个可聚焦节点。由接入方平台实现的回调函数，注册给系统侧调用。支持多实例场景。 |
| [int32_t (\*executeAccessibilityAction)(const char* instanceId, int64_t elementId,ArkUI_Accessibility_ActionType action, ArkUI_AccessibilityActionArguments *actionArguments, int32_t requestId)](#executeaccessibilityaction) | 对指定节点执行指定的操作。由接入方平台实现的回调函数，注册给系统侧调用。支持多实例场景。**使用场景**：当无障碍服务代替用户对界面元素执行操作（如自动点击、聚焦、滚动等）时，通过此回调通知接入方平台执行对应的操作。 |
| [int32_t (\*clearFocusedFocusAccessibilityNode)(const char* instanceId)](#clearfocusedfocusaccessibilitynode) | 清除当前获焦的节点。由接入方平台实现的回调函数，注册给系统侧调用。支持多实例场景。 |
| [int32_t (\*getAccessibilityNodeCursorPosition)(const char* instanceId, int64_t elementId,int32_t requestId, int32_t* index)](#getaccessibilitynodecursorposition) | 获取当前文本组件中的光标位置。由接入方平台实现的回调函数，注册给系统侧调用。支持多实例场景。 |

## 成员函数说明

### findAccessibilityNodeInfosById()

```c
int32_t (*findAccessibilityNodeInfosById)(const char* instanceId, int64_t elementId, ArkUI_AccessibilitySearchMode mode, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)
```

**描述：**

基于指定的节点，根据搜索模式查询对应的节点信息。由接入方平台实现的回调函数，注册给系统侧调用。支持多实例场景。

**起始版本：** 15

**参数：**

| 参数项                                                                            | 描述 |
|--------------------------------------------------------------------------------| -- |
| const char* instanceId                                                         | 第三方框架的实例编码。 |
| int64_t elementId                                                              | 无障碍元素的唯一编号。 |
| [ArkUI_AccessibilitySearchMode](capi-native-interface-accessibility-h.md#arkui_accessibilitysearchmode) mode | 无障碍服务的搜索模式，决定基于指定节点查询节点信息的方式，例如按子树搜索、按前序遍历搜索、按后序遍历搜索等。具体取值及含义详见ArkUI_AccessibilitySearchMode枚举说明。 |
| int32_t requestId                                                              | 请求id，用于关联请求过程，建议日志打印时附带输出该信息，方便问题定位。 |
| [ArkUI_AccessibilityElementInfoList](capi-arkui-accessibility-arkui-accessibilityelementinfolist.md)* elementList                            | 本次查询到的所有无障碍元素列表。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### findAccessibilityNodeInfosByText()

```c
int32_t (*findAccessibilityNodeInfosByText)(const char* instanceId, int64_t elementId, const char* text, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)
```

**描述：**

基于指定的节点，查询文本内容匹配指定文本的节点信息。由接入方平台实现的回调函数，注册给系统侧调用。支持多实例场景。**使用场景**：当无障碍服务执行文本搜索（如用户通过屏幕阅读器查找包含特定文本的元素）时，通过此回调向接入方平台查询匹配的节点。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* instanceId | 第三方框架的实例编码。 |
| int64_t elementId | 无障碍元素的唯一编号，需指向文本组件。 |
| const char* text | 组件需要匹配的文本内容。匹配规则说明：需说明匹配方式（精确匹配/模糊匹配）、是否区分大小写等。 |
| int32_t requestId | 请求id，用于关联请求过程，建议日志打印时附带输出该信息，方便问题定位。 |
|  [ArkUI_AccessibilityElementInfoList](capi-arkui-accessibility-arkui-accessibilityelementinfolist.md)* elementList | 本次查询到的所有无障碍元素列表。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### findFocusedAccessibilityNode()

```c
int32_t (*findFocusedAccessibilityNode)(const char* instanceId, int64_t elementId, ArkUI_AccessibilityFocusType focusType, int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)
```

**描述：**

从指定节点查找已经聚焦的节点。由接入方平台实现的回调函数，注册给系统侧调用。支持多实例场景。

**起始版本：** 15

**参数：**

| 参数项                                                                                | 描述 |
|------------------------------------------------------------------------------------| -- |
| const char* instanceId                                                             | 第三方框架的实例编码。 |
| int64_t elementId                                                                  | 无障碍元素的唯一编号。 |
| [ArkUI_AccessibilityFocusType](capi-native-interface-accessibility-h.md#arkui_accessibilityfocustype) focusType | 焦点类型，用于区分输入焦点和无障碍焦点。 |
| int32_t requestId                                                                  | 请求id，用于关联请求过程，建议日志打印时附带输出该信息，方便问题定位。 |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo                                    | 本次查询到的无障碍元素。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### findNextFocusAccessibilityNode()

```c
int32_t (*findNextFocusAccessibilityNode)(const char* instanceId, int64_t elementId, ArkUI_AccessibilityFocusMoveDirection direction, int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)
```

**描述：**

从指定节点查询指定方向的下一个可聚焦节点。由接入方平台实现的回调函数，注册给系统侧调用。支持多实例场景。

**起始版本：** 15

**参数：**

| 参数项                                                                                                                               | 描述 |
|-----------------------------------------------------------------------------------------------------------------------------------| -- |
| const char* instanceId                                                                                                            | 第三方框架的实例编码。 |
| int64_t elementId                                                                                                                 | 无障碍元素的唯一编号。 |
| [ArkUI_AccessibilityFocusMoveDirection](capi-native-interface-accessibility-h.md#arkui_accessibilityfocusmovedirection) direction | 焦点移动方向，指定查找下一个焦点节点的方向。 |
| int32_t requestId                                                                                                                 | 请求id，用于关联请求过程，建议日志打印时附带输出该信息，方便问题定位。 |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo                         | 本次查询到的无障碍元素。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### executeAccessibilityAction()

```c
int32_t (*executeAccessibilityAction)(const char* instanceId, int64_t elementId, ArkUI_Accessibility_ActionType action, ArkUI_AccessibilityActionArguments* actionArguments, int32_t requestId)
```

**描述：**

对指定节点执行指定的操作。由接入方平台实现的回调函数，注册给系统侧调用。支持多实例场景。

**起始版本：** 15

**参数：**

| 参数项                                                                                                              | 描述 |
|------------------------------------------------------------------------------------------------------------------| -- |
| const char* instanceId                                                                                           | 第三方框架的实例编码。 |
| int64_t elementId                                                                                                | 无障碍元素的唯一编号。 |
| [ArkUI_Accessibility_ActionType](capi-native-interface-accessibility-h.md#arkui_accessibility_actiontype) action | 需要执行的操作，比如聚焦、点击和长按等。 |
| [ArkUI_AccessibilityActionArguments](capi-arkui-accessibility-arkui-accessibilityactionarguments.md) *actionArguments | 执行操作所需的参数集合，具体参数内容取决于action指定的操作类型。 |
| int32_t requestId                                                                                                | 请求id，用于关联请求过程，建议日志打印时附带输出该信息，方便问题定位。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### clearFocusedFocusAccessibilityNode()

```c
int32_t (*clearFocusedFocusAccessibilityNode)(const char* instanceId)
```

**描述：**

清除当前获焦的节点。由接入方平台实现的回调函数，注册给系统侧调用。支持多实例场景。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* instanceId | 第三方框架的实例编码。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |

### getAccessibilityNodeCursorPosition()

```c
int32_t (*getAccessibilityNodeCursorPosition)(const char* instanceId, int64_t elementId, int32_t requestId, int32_t* index)
```

**描述：**

获取当前文本组件中的光标位置。由接入方平台实现的回调函数，注册给系统侧调用。支持多实例场景。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* instanceId | 第三方框架的实例编码。 |
| int64_t elementId | 无障碍元素的唯一编号。 |
| int32_t requestId | 请求id，用于关联请求过程，建议日志打印时附带输出该信息，方便问题定位。 |
|  int32_t* index | 光标的位置结果，表示光标在文本中从起始位置开始的字符索引，索引从0开始。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 成功返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。<br>参数错误返回[ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode)。 |


