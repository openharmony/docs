# Native Accessibility

## 概述

描述第三方平台通过XComponent接入ArkUI无障碍框架的接口说明。更多详细介绍请参考[通过XComponent接入无障碍](../../ui/ndk-accessibility-xcomponent.md)。

描述了第三方平台需要实现的接口以及相关的结构、枚举定义说明。

> **说明：**
>
> 该模块从API Version13 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 汇总


### 文件

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [native_interface_accessibility.h](native__interface__accessibility_8h.md) | 声明用于访问Native&nbsp;Accessibility的API。 |

### 类型定义

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [ArkUI_AccessibilityElementInfo](#arkui_accessibilityelementinfo) | 无障碍节点信息，用于向无障碍服务、辅助应用传递节点信息。     |
| [ArkUI_AccessibilityElementInfoList](#arkui_accessibilityelementinfolist) | 无障碍节点列表，包含需要的无障碍节点列表信息。              |
| [ArkUI_AccessibilityEventInfo](#arkui_accessibilityeventinfo) | 无障碍事件信息，无障碍服务或辅助应用要求组件执行操作后，需要发送执行成功事件。组件自身交互诉求需要同步状态给无障碍服务或辅助应用时，也需要主动发送事件。 |
| [ArkUI_AccessibilityProvider](#arkui_accessibilityprovider)  | 第三方操作provider，承载回调函数实现。                         |
| [ArkUI_AccessibilityProviderCallbacks](#arkui_accessibilityprovidercallbacks) | 第三方操作provider回调函数结构定义，需要第三方平台实现的相关函数，通过OH_ArkUI_AccessibilityProviderRegisterCallback注册到系统侧。 |
| [ArkUI_AccessibilityActionArguments](#arkui_accessibilityactionarguments) | Action附加字段，对需要执行的Action进行处理的说明。           |
| [ArkUI_AccessibleRect](#arkui_accessiblerect)                | 节点所在坐标位置。                                           |
| [ArkUI_AccessibleRangeInfo](#arkui_accessiblerangeinfo)      | 用于特定组件设置组件的当前值、最大值、最小值，如Slider、Rating、Progress组件。 |
| [ArkUI_AccessibleGridInfo](#arkui_accessiblegridinfo)        | 用于特定组件设置组件的行数、列数以及选择模式，如list、flex、select、swiper组件。 |
| [ArkUI_AccessibleGridItemInfo](#arkui_accessiblegriditeminfo) | 用于特定组件设置组件的属性值，如list、flex、select、swiper组件。 |
| [ArkUI_AccessibleAction](#arkui_accessibleaction)            | 无障碍操作内容结构。                                         |

### 枚举

| 名称                                                         | 描述           |
| ------------------------------------------------------------ | -------------- |
| [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)    | 错误码。       |
| [ArkUI_AccessibilitySearchMode](#arkui_accessibilitysearchmode) | 查询模式。     |
| [ArkUI_AccessibilityFocusType](#arkui_accessibilityfocustype) | 焦点类型。     |
| [ArkUI_Accessibility_ActionType](#arkui_accessibility_actiontype) | 操作类型。     |
| [ArkUI_AccessibilityEventType](#arkui_accessibilityeventtype) | 事件类型。     |
| [ArkUI_AccessibilityFocusMoveDirection](#arkui_accessibilityfocusmovedirection) | 焦点移动方向。 |

## 类型定义说明

### ArkUI_AccessibilityElementInfo

```
typedef struct ArkUI_AccessibilityElementInfo ArkUI_AccessibilityElementInfo
```

**描述：**

无障碍节点信息，用于向无障碍服务、辅助应用传递节点信息。

**起始版本：**

13

### ArkUI_AccessibilityElementInfoList

```
typedef struct ArkUI_AccessibilityElementInfoList ArkUI_AccessibilityElementInfoList
```

**描述：**

无障碍节点列表，包含需要的无障碍节点列表信息。

**起始版本：**

13

### ArkUI_AccessibilityEventInfo 

```
typedef struct ArkUI_AccessibilityEventInfo ArkUI_AccessibilityEventInfo
```

**描述：**

无障碍事件信息，无障碍服务或辅助应用要求组件执行操作后，需要发送执行成功事件。组件自身交互需求要同步状态给无障碍服务或辅助应用时，也需要主动发送事件。

**起始版本：**

13

### ArkUI_AccessibilityProvider

```
typedef struct ArkUI_AccessibilityProvider ArkUI_AccessibilityProvider
```

**描述：**

第三方操作provider，承载回调函数实现。

**起始版本：**

13

### ArkUI_AccessibilityProviderCallbacks

```C
typedef struct ArkUI_AccessibilityProviderCallbacks {
    int32_t (*findAccessibilityNodeInfosById)(int64_t elementId, ArkUI_AccessibilitySearchMode mode, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList);
    int32_t (*findAccessibilityNodeInfosByText)(int64_t elementId, const char* text, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList);
    int32_t (*findFocusedAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusType focusType, int32_t requestId, ArkUI_AccessibilityElementInfo* elementinfo);
    int32_t (*findNextFocusAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusMoveDirection direction, int32_t requestId, ArkUI_AccessibilityElementInfo* elementList);
    int32_t (*executeAccessibilityAction)(int64_t elementId, ArkUI_Accessibility_ActionType action, ArkUI_AccessibilityActionArguments *actionArguments, int32_t requestId);
    int32_t (*clearFocusedFocusAccessibilityNode)();
    int32_t (*getAccessibilityNodeCursorPosition)(int64_t elementId, int32_t requestId, int32_t* index);
} ArkUI_AccessibilityProviderCallbacks;
```

**描述：**

第三方操作provider回调函数结构定义，需要第三方平台实现的相关函数，通过OH_ArkUI_AccessibilityProviderRegisterCallback注册到系统侧。

| 回调函数                                                     | 函数功能                             |
| ------------------------------------------------------------ | ------------------------------------ |
| [findAccessibilityNodeInfosById](#findaccessibilitynodeinfosbyid) | 查询指定节点的节点信息。 |
| [findAccessibilityNodeInfosByText](#findaccessibilitynodeinfosbytext) | 查询满足指定text内容的节点信息。     |
| [findFocusedAccessibilityNode](#findfocusedaccessibilitynode) | 从指定节点查找已聚焦的节点。       |
| [findNextFocusAccessibilityNode](#findnextfocusaccessibilitynode) | 从指定节点查询指定方向的节点。       |
| [executeAccessibilityAction](#executeaccessibilityaction)    | 对指定节点执行指定的操作（Action）。 |
| [clearFocusedFocusAccessibilityNode](#clearfocusedfocusaccessibilitynode) | 清除当前获焦的节点。                 |
| [getAccessibilityNodeCursorPosition](#getaccessibilitynodecursorposition) | 获取当前组件中（文本组件）光标位置。 |

**起始版本：**

13

### ArkUI_AccessibilityProviderCallbacksWithInstance

```C
typedef struct ArkUI_AccessibilityProviderCallbacksWithInstance {
    int32_t (*findAccessibilityNodeInfosById)(const char* instanceId, int64_t elementId, ArkUI_AccessibilitySearchMode mode, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList);
    int32_t (*findAccessibilityNodeInfosByText)(const char* instanceId, int64_t elementId, const char* text, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList);
    int32_t (*findFocusedAccessibilityNode)(const char* instanceId, int64_t elementId, ArkUI_AccessibilityFocusType focusType, int32_t requestId, ArkUI_AccessibilityElementInfo* elementinfo);
    int32_t (*findNextFocusAccessibilityNode)(const char* instanceId, int64_t elementId, ArkUI_AccessibilityFocusMoveDirection direction, int32_t requestId, ArkUI_AccessibilityElementInfo* elementList);
    int32_t (*executeAccessibilityAction)(const char* instanceId, int64_t elementId, ArkUI_Accessibility_ActionType action, ArkUI_AccessibilityActionArguments *actionArguments, int32_t requestId);
    int32_t (*clearFocusedFocusAccessibilityNode)(const char* instanceId);
    int32_t (*getAccessibilityNodeCursorPosition)(const char* instanceId, int64_t elementId, int32_t requestId, int32_t* index);
} ArkUI_AccessibilityProviderCallbacksWithInstance;
```

**描述：**

适配多实例场景第三方操作provider回调函数结构定义，需要第三方平台实现的相关函数，通过OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance注册到系统侧。

| 回调函数                                                     | 函数功能                             |
| ------------------------------------------------------------ | ------------------------------------ |
| [findAccessibilityNodeInfosById](#findaccessibilitynodeinfosbyid-1) | 由接入方平台实现的回调函数，注册给系统侧调用。查询指定节点的节点信息。支持多实例场景。 |
| [findAccessibilityNodeInfosByText](#findaccessibilitynodeinfosbytext-1) | 由接入方平台实现的回调函数，注册给系统侧调用。基于指定的节点，查询满足指定组件文本内容的节点信息。支持多实例场景。 |
| [findFocusedAccessibilityNode](#findfocusedaccessibilitynode-1) | 由接入方平台实现的回调函数，注册给系统侧调用。从指定节点查找已聚焦的节点。支持多实例场景。  |
| [findNextFocusAccessibilityNode](#findnextfocusaccessibilitynode-1) | 由接入方平台实现的回调函数，注册给系统侧调用。从指定节点查询指定方向的节点。支持多实例场景。  |
| [executeAccessibilityAction](#executeaccessibilityaction-1)    | 由接入方平台实现的回调函数，注册给系统侧调用。对指定节点执行指定的操作。支持多实例场景。  |
| [clearFocusedFocusAccessibilityNode](#clearfocusedfocusaccessibilitynode-1) | 由接入方平台实现的回调函数，注册给系统侧调用。 清除当前获焦的节点。支持多实例场景。  |
| [getAccessibilityNodeCursorPosition](#getaccessibilitynodecursorposition-1) | 由接入方平台实现的回调函数，注册给系统侧调用。获取当前组件中（文本组件）光标位置。支持多实例场景。 |

**起始版本：**

15

### ArkUI_AccessibilityActionArguments

**描述：**

Action附加字段，对需要执行的Action进行处理说明。

**起始版本：**

13



### ArkUI_AccessibleRect

**描述：**

节点所在坐标位置。

**参数：**

| 名称         | 类型  | 描述                |
| ------------ | ----- | ------------------- |
| leftTopX     | int32 | 左上角X轴坐标位置。 |
| leftTopY     | int32 | 左上角Y轴坐标位置。 |
| rightBottomX | int32 | 右下角X轴坐标位置。 |
| rightBottomY | int32 | 右下角Y轴坐标位置。 |

**起始版本：**

13



### ArkUI_AccessibleRangeInfo

**描述：**

用于特定组件设置组件的当前值、最大值、最小值，如Slider、Rating、Progress组件。

**参数：**

| 名称    | 类型   | 描述     |
| ------- | ------ | -------- |
| min     | double | 最小值。 |
| max     | double | 最大值。 |
| current | double | 当前值。 |

**起始版本：**

13



### ArkUI_AccessibleGridInfo

**描述：**

用于特定组件设置组件的行数、列数以及选择模式，如list、flex、select、swiper组件。

**参数：**

| 名称          | 类型  | 描述       |
| ------------- | ----- | ---------- |
| rowCount      | int32 | 行数。     |
| columnCount   | int32 | 列数。     |
| selectionMode | int32 | 选择模式。 |

**起始版本：**

13



### ArkUI_AccessibleGridItemInfo

**描述：**

用于特定组件设置组件的属性值，如list、flex、select、swiper组件。

**参数：**

| 名称        | 类型  | 描述         |
| ----------- | ----- | ------------ |
| heading     | bool  | 是否是标题。 |
| selected    | bool  | 是否被选中。 |
| columnIndex | int32 | 列下标。     |
| rowIndex    | int32 | 行下标。     |
| columnSpan  | int32 | 列跨度。     |
| rowSpan     | int32 | 行跨度。     |

**起始版本：**

13

### ArkUI_AccessibleAction

**描述：**

无障碍操作内容结构。

**参数：**

| 名称        | 类型                                                         | 描述             |
| ----------- | ------------------------------------------------------------ | ---------------- |
| actionType  | [ArkUI_Accessibility_ActionType](#arkui_accessibility_actiontype) | 无障碍操作类型。 |
| description | char*                                                        | 描述信息。       |

**起始版本：**

13

## 函数说明

### findAccessibilityNodeInfosById

```C
int32_t (*findAccessibilityNodeInfosById)(int64_t elementId, ArkUI_AccessibilitySearchMode mode, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList);
```

**描述：**

由接入方平台实现的回调函数，注册给系统侧调用。查询指定节点的节点信息。

**起始版本：** 13

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| elementId   | 指定节点的id，从该节点出发进行搜索查询。当指定为-1时，代表从组件树的根节点进行查询。 |
| mode        | 查询模式，支持如下查询类型：[ArkUI_AccessibilitySearchMode](#arkui_accessibilitysearchmode)。 |
| requestId   | 请求id，用于关联请求过程，方便问题定位。第三方输出日志关键日志时，建议一起输出。 |
| elementList | 查询结果，接入方根据查询结果进行调整并返回。                     |

**返回：**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)

### findAccessibilityNodeInfosByText

```C
int32_t (*findAccessibilityNodeInfosByText)(int64_t elementId, const char* text, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList);
```

**描述：**

由接入方平台实现的回调函数，注册给系统侧调用。基于指定的节点，查询满足指定text内容的节点信息。

**起始版本：** 13

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| elementId   | 指定节点的id，从该节点出发进行搜索查询。当指定为-1时，代表从组件树的根节点进行查询。 |
| text        | 指定文本，匹配节点中无障碍属性的文本内容。                   |
| requestId   | 请求id，用于关联请求过程，方便问题定位。第三方输出日志关键日志时，建议一起输出。 |
| elementList | 查询结果，接入方根据查询结果进行调整并返回。                     |

**返回：**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)

### findFocusedAccessibilityNode

```C
int32_t (*findFocusedAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusType focusType, int32_t requestId, ArkUI_AccessibilityElementInfo* elementinfo);
```

**描述：**

由接入方平台实现的回调函数，注册给系统侧调用。从指定节点查找已聚焦的节点。

**起始版本：** 13

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| elementId   | 指定节点的id，从该节点出发进行搜索查询。当指定为-1时，代表从组件树的根节点进行查询。 |
| focusType   | 无障碍焦点类型[ArkUI_AccessibilityFocusType](#arkui_accessibilityfocustype)。 |
| requestId   | 请求id，用于关联请求过程，方便问题定位。第三方输出日志关键日志时，建议一起输出。 |
| elementList | 查询结果，接入方根据查询结果进行调整并返回。                     |

**返回：**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### findNextFocusAccessibilityNode

```C
int32_t (*findNextFocusAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusMoveDirection direction, int32_t requestId, ArkUI_AccessibilityElementInfo* elementList);
```

**描述：**

由接入方平台实现的回调函数，注册给系统侧调用。从指定节点查询指定方向的节点。

**起始版本：** 13

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| elementId   | 指定节点的id，从该节点出发进行搜索查询。当指定为-1时，代表从组件树的根节点进行查询。 |
| focusType   | 无障碍焦点类型[ArkUI_AccessibilityFocusType](#arkui_accessibilityfocustype)。 |
| requestId   | 请求id，用于关联请求过程，方便问题定位。第三方输出日志关键日志时，建议一起输出。 |
| elementList | 查询结果，接入方根据查询结果进行调整并返回。                     |

**返回：**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)

### executeAccessibilityAction

```C
int32_t (*executeAccessibilityAction)(int64_t elementId, ArkUI_Accessibility_ActionType action, ArkUI_AccessibilityActionArguments *actionArguments, int32_t requestId);
```

**描述：**

由接入方平台实现的回调函数，注册给系统侧调用。对指定节点执行指定的操作（[ArkUI_Accessibility_ActionType](#arkui_accessibility_actiontype)）。

**起始版本：** 13

**参数：**

| 名称            | 描述                                                         |
| --------------- | ------------------------------------------------------------ |
| elementId       | 指定节点的id。                                               |
| action          | 执行操作类型[ArkUI_Accessibility_ActionType](#arkui_accessibility_actiontype)。 |
| requestId       | 请求id，用于关联请求过程，方便问题定位。第三方输出日志关键日志时，建议一起输出。 |
| actionArguments | Action辅助配置信息。                                         |

**返回：**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)

### clearFocusedFocusAccessibilityNode

```C
int32_t (*clearFocusedFocusAccessibilityNode)();
```

**描述：**

由接入方平台实现的回调函数，注册给系统侧调用。 清除当前获焦的节点。

**起始版本：** 13

**参数：**  无

**返回：**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)

### getAccessibilityNodeCursorPosition

```C
int32_t (*getAccessibilityNodeCursorPosition)(int64_t elementId, int32_t requestId, int32_t* index);
```

**描述：**

由接入方平台实现的回调函数，注册给系统侧调用。获取当前组件中（文本组件）光标位置。

**起始版本：** 13

**参数：**

| 名称      | 描述                                                         |
| --------- | ------------------------------------------------------------ |
| elementId | 指定节点的id。                                               |
| requestId | 请求id，用于关联请求过程，方便问题定位。第三方输出日志关键日志时，建议一起输出。 |
| index     | 返回光标位置结果。                                           |

**返回：**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)
 
### findAccessibilityNodeInfosById

```C
int32_t (*findAccessibilityNodeInfosById)(const char* instanceId, int64_t elementId, ArkUI_AccessibilitySearchMode mode, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList);
```

**描述：**

由接入方平台实现的回调函数，注册给系统侧调用。查询指定节点的节点信息。支持多实例场景。

**起始版本：** 15

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| instanceId  | 指定当前接入的第三方实例的id，id与接入方调用方法[OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance](#oh_arkui_accessibilityproviderregistercallbackwithinstance)传入的instanceId一致。 |
| elementId   | 指定节点的id，从该节点出发进行搜索查询。当指定为-1时，代表从组件树的根节点进行查询。 |
| mode        | 查询模式，支持如下查询类型：[ArkUI_AccessibilitySearchMode](#arkui_accessibilitysearchmode)。 |
| requestId   | 请求id，用于关联请求过程，方便问题定位。建议日志打印时附带输出该信息，方便定位。 |
| elementList | 查询结果，接入方根据查询结果进行调整并返回。                     |

**返回：**

[ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)

### findAccessibilityNodeInfosByText

```C
int32_t (*findAccessibilityNodeInfosByText)(const char* instanceId, int64_t elementId, const char* text, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList);
```

**描述：**

由接入方平台实现的回调函数，注册给系统侧调用。基于指定的节点，查询满足指定组件文本内容的节点信息。支持多实例场景。

**起始版本：** 15

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| instanceId  | 指定当前接入的第三方实例的id，id与接入方调用方法[OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance](#oh_arkui_accessibilityproviderregistercallbackwithinstance)传入的instanceId一致。 |
| elementId   | 指定节点的id，从该节点出发进行搜索查询。当指定为-1时，代表从组件树的根节点进行查询。 |
| text        | 指定文本，匹配节点中无障碍属性的文本内容。                   |
| requestId   | 请求id，用于关联请求过程，方便问题定位。建议日志打印时附带输出该信息，方便定位。 |
| elementList | 查询结果，接入方根据查询结果进行调整并返回。                     |

**返回：**

[ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)

### findFocusedAccessibilityNode

```C
int32_t (*findFocusedAccessibilityNode)(const char* instanceId, int64_t elementId, ArkUI_AccessibilityFocusType focusType, int32_t requestId, ArkUI_AccessibilityElementInfo* elementinfo);
```

**描述：**

由接入方平台实现的回调函数，注册给系统侧调用。从指定节点查找已聚焦的节点。支持多实例场景。

**起始版本：** 15

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| instanceId  | 指定当前接入的第三方实例的id，id与接入方调用方法[OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance](#oh_arkui_accessibilityproviderregistercallbackwithinstance)传入的instanceId一致。 |
| elementId   | 指定节点的id，从该节点出发进行搜索查询。当指定为-1时，代表从组件树的根节点进行查询。 |
| focusType   | 无障碍焦点类型[ArkUI_AccessibilityFocusType](#arkui_accessibilityfocustype)。 |
| requestId   | 请求id，用于关联请求过程，方便问题定位。建议日志打印时附带输出该信息，方便定位。 |
| elementList | 查询结果，接入方根据查询结果进行调整并返回。                     |

**返回：**

[ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### findNextFocusAccessibilityNode

```C
int32_t (*findNextFocusAccessibilityNode)(const char* instanceId, int64_t elementId, ArkUI_AccessibilityFocusMoveDirection direction, int32_t requestId, ArkUI_AccessibilityElementInfo* elementList);
```

**描述：**

由接入方平台实现的回调函数，注册给系统侧调用。从指定节点查询指定方向的节点。支持多实例场景。

**起始版本：** 15

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| instanceId  | 指定当前接入的第三方实例的id，id与接入方调用方法[OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance](#oh_arkui_accessibilityproviderregistercallbackwithinstance)传入的instanceId一致。 |
| elementId   | 指定节点的id，从该节点出发进行搜索查询。当指定为-1时，代表从组件树的根节点进行查询。 |
| focusType   | 无障碍焦点类型[ArkUI_AccessibilityFocusType](#arkui_accessibilityfocustype)。 |
| requestId   | 请求id，用于关联请求过程，方便问题定位。建议日志打印时附带输出该信息，方便定位。 |
| elementList | 查询结果，接入方根据查询结果进行调整并返回。                     |

**返回：**

[ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)

### executeAccessibilityAction

```C
int32_t (*executeAccessibilityAction)(const char* instanceId, int64_t elementId, ArkUI_Accessibility_ActionType action, ArkUI_AccessibilityActionArguments *actionArguments, int32_t requestId);
```

**描述：**

由接入方平台实现的回调函数，注册给系统侧调用。对指定节点执行指定的操作（[ArkUI_Accessibility_ActionType](#arkui_accessibility_actiontype)）。支持多实例场景。

**起始版本：** 15

**参数：**

| 名称            | 描述                                                         |
| --------------- | ------------------------------------------------------------ |
| instanceId      | 指定当前接入的第三方实例的id，id与接入方调用方法[OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance](#oh_arkui_accessibilityproviderregistercallbackwithinstance)传入的instanceId一致。 |
| elementId       | 指定节点的id。                                               |
| action          | 执行操作类型[ArkUI_Accessibility_ActionType](#arkui_accessibility_actiontype)。 |
| requestId       | 请求id，用于关联请求过程，方便问题定位。建议日志打印时附带输出该信息，方便定位。 |
| actionArguments | Action辅助配置信息。                                         |

**返回：**

[ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)

### clearFocusedFocusAccessibilityNode

```C
int32_t (*clearFocusedFocusAccessibilityNode)(const char* instanceId);
```

**描述：**

由接入方平台实现的回调函数，注册给系统侧调用。 清除当前获焦的节点。支持多实例场景。

**起始版本：** 15

**参数：**  

| 名称            | 描述                                                         |
| --------------- | ------------------------------------------------------------ |
| instanceId | 指定当前接入的第三方实例的id，id与接入方调用方法[OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance](#oh_arkui_accessibilityproviderregistercallbackwithinstance)传入的instanceId一致。 |

**返回：**

[ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)

### getAccessibilityNodeCursorPosition

```C
int32_t (*getAccessibilityNodeCursorPosition)(const char* instanceId, int64_t elementId, int32_t requestId, int32_t* index);
```

**描述：**

由接入方平台实现的回调函数，注册给系统侧调用。获取当前组件中（文本组件）光标位置。支持多实例场景。

**起始版本：** 15

**参数：**

| 名称      | 描述                                                         |
| --------- | ------------------------------------------------------------ |
| instanceId| 指定当前接入的第三方实例的id，id与接入方调用方法[OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance](#oh_arkui_accessibilityproviderregistercallbackwithinstance)传入的instanceId一致。 |
| elementId | 指定节点的id。                                               |
| requestId | 请求id，用于关联请求过程，方便问题定位。建议日志打印时附带输出该信息，方便定位。 |
| index     | 返回光标位置结果。                                           |

**返回：**

[ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityProviderRegisterCallback

```C
int32_t OH_ArkUI_AccessibilityProviderRegisterCallback(
    ArkUI_AccessibilityProvider* provider, ArkUI_AccessibilityProviderCallbacks* callbacks);
```

**描述：**

注册回调函数。

**起始版本：** 13

**参数：**

| 名称      | 描述                       |
| --------- | -------------------------- |
| provider  | 第三方平台接入provider句柄。 |
| callbacks | 回调函数实现。             |

**返回：**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)
 
 
### OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance

```C
int32_t OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance(const char* instanceId,
    ArkUI_AccessibilityProvider* provider, ArkUI_AccessibilityProviderCallbacksWithInstance* callbacks);
```

**描述：**

多实例场景第三方平台注册回调函数。

**起始版本：** 15

**参数：**

| 名称      | 描述                       |
| --------- | -------------------------- |
| instanceId| 第三方平台接入的实例ID，用于区分多实例场景中不同的第三方实例，ID由第三方平台指定与维护。 |
| provider  | 第三方平台接入provider句柄。 |
| callbacks | 回调函数实现。             |

**返回：**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_SendAccessibilityAsyncEvent

```C
void OH_ArkUI_SendAccessibilityAsyncEvent(
    ArkUI_AccessibilityProvider* provider, ArkUI_AccessibilityEventInfo* eventInfo, void (*callback)(int32_t errorCode));
```

**描述：**

主动上报事件接口，通知无障碍服务。

**起始版本：** 13

**参数：** 

| 名称      | 描述                       |
| --------- | -------------------------- |
| provider  | 第三方平台接入provider句柄。 |
| eventInfo | 上报事件。                 |
| callback  | 结果返回回调。             |

**返回：** 无



### OH_ArkUI_CreateAccessibilityElementInfo

```C
ArkUI_AccessibilityElementInfo* OH_ArkUI_CreateAccessibilityElementInfo(void);
```

**描述：**

创建elementInfo结构，创建后需要调用[OH_ArkUI_DestoryAccessibilityElementInfo](#oh_arkui_destoryaccessibilityelementinfo)释放。

**起始版本：** 13

**返回：**

返回创建完成的ArkUI_AccessibilityElementInfo结构指针，如果创建失败返回NULL。

### OH_ArkUI_DestoryAccessibilityElementInfo

```C
void OH_ArkUI_DestoryAccessibilityElementInfo(ArkUI_AccessibilityElementInfo* elementInfo);
```

**描述：**

销毁elementInfo。

**起始版本：** 13

**参数：** 

| 名称        | 描述                            |
| ----------- | ------------------------------- |
| elementInfo | 需要删除释放的Element结构指针。 |

**返回：** 无



### OH_ArkUI_AddAndGetAccessibilityElementInfo

```C
ArkUI_AccessibilityElementInfo* OH_ArkUI_AddAndGetAccessibilityElementInfo(ArkUI_AccessibilityElementInfoList* list);
```

**描述：**

在指定的list中增加Element成员，并返回Element结构。

**起始版本：** 13

**参数：** 

| 名称 | 描述                                                         |
| ---- | ------------------------------------------------------------ |
| list | 指定的ArkUI_AccessibilityElementInfoList结构，新创建的ElementInfo成员加入该list后返回给函数调用方。 |

**返回：** 

返回创建完成的ArkUI_AccessibilityElementInfo结构指针，如果创建失败返回NULL。



### OH_ArkUI_AccessibilityElementInfoSetElementId

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetElementId(ArkUI_AccessibilityElementInfo* elementInfo, int32_t elementId);
```

**描述：**

设置Element的ElementId。

**起始版本：** 13

**参数：** 

| 名称        | 描述          |
| ----------- | ------------- |
| elementInfo | Element结构。 |
| elementId   | 元素组件id。  |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetParentId

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetParentId(ArkUI_AccessibilityElementInfo* elementInfo, int32_t parentId);
```

**描述：**

设置Element的parentId。

**起始版本：** 13

**参数：** 

| 名称        | 描述           |
| ----------- | -------------- |
| elementInfo | Element结构。  |
| parentId    | 元素父组件id。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetComponentType

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetComponentType(ArkUI_AccessibilityElementInfo* elementInfo, const char* componentType);
```

**描述：**

设置Element的componentType。

**起始版本：** 13

**参数：** 

| 名称          | 描述           |
| ------------- | -------------- |
| elementInfo   | Element结构。  |
| componentType | 元素组件类型。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetContents

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetContents(ArkUI_AccessibilityElementInfo* elementInfo, const char* contents);
```

**描述：**

设置Element的contents。

**起始版本：** 13

**参数：** 

| 名称        | 描述           |
| ----------- | -------------- |
| elementInfo | Element结构。  |
| contents    | 元素组件内容。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetHintText

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetHintText(ArkUI_AccessibilityElementInfo* elementInfo, const char* hintText);
```

**描述：**

设置Element的hintText。

**起始版本：** 13

**参数：** 

| 名称        | 描述          |
| ----------- | ------------- |
| elementInfo | Element结构。 |
| hintText    | 提示文本。    |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetAccessibilityText

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityText(ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityText);
```

**描述：**

设置Element的accessibilityText。

**起始版本：** 13

**参数：** 

| 名称              | 描述                   |
| ----------------- | ---------------------- |
| elementInfo       | Element结构。          |
| accessibilityText | 元素的无障碍文本信息。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetAccessibilityDescription

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityDescription(ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityDescription);
```

**描述：**

设置Element的accessibilityDescription。

**起始版本：** 13

**参数：** 

| 名称                     | 描述             |
| ------------------------ | ---------------- |
| elementInfo              | Element结构。    |
| accessibilityDescription | 元素的描述信息。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetChildNodeIds

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetChildNodeIds(ArkUI_AccessibilityElementInfo* elementInfo, int32_t childCount, int64_t* childNodeIds);
```

**描述：**

设置Element的childCount和childNodeIds。

**起始版本：** 13

**参数：** 

| 名称         | 描述           |
| ------------ | -------------- |
| elementInfo  | Element结构。  |
| childCount   | 子节点个数。   |
| childNodeIds | 子节点id列表。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetOperationActions

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetOperationActions(ArkUI_AccessibilityElementInfo* elementInfo, int32_t operationCount, ArkUI_AccessibleAction* operationActions);
```

**描述：**

设置Element的operationCount和operationActions。

**起始版本：** 13

**参数：** 

| 名称             | 描述                   |
| ---------------- | ---------------------- |
| elementInfo      | Element结构。          |
| operationCount   | 组件支持的action数量。 |
| operationActions | 组件支持的action。     |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetScreenRect

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetScreenRect(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleRect* screenRect);
```

**描述：**

设置Element的screenRect。

**起始版本：** 13

**参数：** 

| 名称             | 描述               |
| ---------------- | ------------------ |
| elementInfo      | Element结构。      |
| screenRect       | 元素显示区域。     |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetCheckable

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetCheckable(ArkUI_AccessibilityElementInfo* elementInfo, bool checkable);
```

**描述：**

设置Element的checkable。

**起始版本：** 13

**参数：** 

| 名称        | 描述           |
| ----------- | -------------- |
| elementInfo | Element结构。  |
| checkable   | 元素是否可查。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetChecked

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetChecked(ArkUI_AccessibilityElementInfo* elementInfo, bool checked);
```

**描述：**

设置Element的checked。

**起始版本：** 13

**参数：** 

| 名称        | 描述             |
| ----------- | ---------------- |
| elementInfo | Element结构。    |
| checked     | 元素是否被检查。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetFocusable

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetFocusable(ArkUI_AccessibilityElementInfo* elementInfo, bool focusable);
```

**描述：**

设置Element的focusable。

**起始版本：** 13

**参数：** 

| 名称        | 描述             |
| ----------- | ---------------- |
| elementInfo | Element结构。    |
| focusable   | 元素是否可聚焦。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetFocused

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetFocused(ArkUI_AccessibilityElementInfo* elementInfo, bool isFocused);
```

**描述：**

设置Element的isFocused。

**起始版本：** 13

**参数：** 

| 名称        | 描述           |
| ----------- | -------------- |
| elementInfo | Element结构。  |
| isFocused   | 元素是否聚焦。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetVisible

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetVisible(ArkUI_AccessibilityElementInfo* elementInfo, bool isVisible);
```

**描述：**

设置Element的isVisible。

**起始版本：** 13

**参数：** 

| 名称        | 描述           |
| ----------- | -------------- |
| elementInfo | Element结构。  |
| isVisible   | 元素是否可见。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetAccessibilityFocused

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityFocused(ArkUI_AccessibilityElementInfo* elementInfo, bool accessibilityFocused);
```

**描述：**

设置Element的accessibilityFocused。

**起始版本：** 13

**参数：** 

| 名称                 | 描述             |
| -------------------- | ---------------- |
| elementInfo          | Element结构。    |
| accessibilityFocused | 无障碍获焦状态。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetSelected

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetSelected(ArkUI_AccessibilityElementInfo* elementInfo, bool selected);
```

**描述：**

设置Element的selected。

**起始版本：** 13

**参数：** 

| 名称        | 描述             |
| ----------- | ---------------- |
| elementInfo | Element结构。    |
| selected    | 元素是否被选中。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetClickable

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetClickable(ArkUI_AccessibilityElementInfo* elementInfo, bool clickable);
```

**描述：**

设置Element的clickable。

**起始版本：** 13

**参数：** 

| 名称        | 描述             |
| ----------- | ---------------- |
| elementInfo | Element结构。    |
| clickable   | 元素是否可点击。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetLongClickable

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetLongClickable(ArkUI_AccessibilityElementInfo* elementInfo, bool longClickable);
```

**描述：**

设置Element的longClickable。

**起始版本：** 13

**参数：** 

| 名称          | 描述               |
| ------------- | ------------------ |
| elementInfo   | Element结构。      |
| longClickable | 元素是否可长点击。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetEnabled

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetEnabled(ArkUI_AccessibilityElementInfo* elementInfo, bool isEnabled);
```

**描述：**

设置Element的isEnabled。

**起始版本：** 13

**参数：** 

| 名称        | 描述           |
| ----------- | -------------- |
| elementInfo | Element结构。  |
| isEnabled   | 元素是否启用。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetIsPassword

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetIsPassword(ArkUI_AccessibilityElementInfo* elementInfo, bool isPassword);
```

**描述：**

设置Element的isPassword。

**起始版本：** 13

**参数：** 

| 名称        | 描述             |
| ----------- | ---------------- |
| elementInfo | Element结构。    |
| isPassword  | 元素是否为密码。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetScrollable

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetScrollable(ArkUI_AccessibilityElementInfo* elementInfo, bool scrollable);
```

**描述：**

设置Element的scrollable。

**起始版本：** 13

**参数：** 

| 名称        | 描述             |
| ----------- | ---------------- |
| elementInfo | Element结构。    |
| scrollable  | 元素是否可滚动。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetEditable

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetEditable(ArkUI_AccessibilityElementInfo* elementInfo, bool editable);
```

**描述：**

设置Element的editable。

**起始版本：** 13

**参数：** 

| 名称        | 描述             |
| ----------- | ---------------- |
| elementInfo | Element结构。    |
| editable    | 元素是否可编辑。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetIsHint

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetIsHint(ArkUI_AccessibilityElementInfo* elementInfo, bool isHint);
```

**描述：**

设置Element的isHint。

**起始版本：** 13

**参数：** 

| 名称        | 描述                 |
| ----------- | -------------------- |
| elementInfo | Element结构。        |
| isHint      | 元素是否为提示状态。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetRangeInfo

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetRangeInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleRangeInfo* rangeInfo);
```

**描述：**

设置Element的rangeInfo。

**起始版本：** 13

**参数：** 

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| elementInfo | Element结构。                                                |
| rangeInfo   | 用于特定组件设置组件的当前值、最大值、最小值。如Slider、Rating、Progress组件。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetGridInfo

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetGridInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleGridInfo* gridInfo);
```

**描述：**

设置Element的gridInfo。

**起始版本：** 13

**参数：** 

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| elementInfo | Element结构。                                                |
| gridInfo    | 特定组件需要使用，如list、flex、select、swiper组件。设置组件的行数、列数以及选择模式。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetGridItemInfo

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetGridItemInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleGridItemInfo* gridItem);
```

**描述：**

设置Element的gridItem。

**起始版本：** 13

**参数：** 

| 名称        | 描述                                                 |
| ----------- | ---------------------------------------------------- |
| elementInfo | Element结构。                                        |
| gridItem    | 特定组件需要使用，如list、flex、select、swiper组件。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetSelectedTextStart

```
int32_t OH_ArkUI_AccessibilityElementInfoSetSelectedTextStart(ArkUI_AccessibilityElementInfo* elementInfo, int32_t selectedTextStart);
```

**描述：**

设置Element的selectedTextStart。

**起始版本：** 13

**参数：** 

| 名称              | 描述                               |
| ----------------- | ---------------------------------- |
| elementInfo       | Element结构。                      |
| selectedTextStart | 文本组件使用，设置选择的起点位置。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetSelectedTextEnd

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetSelectedTextEnd(ArkUI_AccessibilityElementInfo* elementInfo, int32_t selectedTextEnd);
```

**描述：**

设置Element的selectedTextEnd。

**起始版本：** 13

**参数：** 

| 名称            | 描述                               |
| --------------- | ---------------------------------- |
| elementInfo     | Element结构。                      |
| selectedTextEnd | 文本组件使用，设置选择的结束位置。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetCurrentItemIndex

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetCurrentItemIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t currentItemIndex);
```

**描述：**

设置Element的currentItemIndex。

**起始版本：** 13

**参数：** 

| 名称             | 描述                                                         |
| ---------------- | ------------------------------------------------------------ |
| elementInfo      | Element结构。                                                |
| currentItemIndex | 当前项的索引，当前获焦组件的index信息。如，list、select、swiper、tab_bar等组件 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetStartItemIndex

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetStartItemIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t startItemIndex);
```

**描述：**

设置Element的startItemIndex。

**起始版本：** 13

**参数：** 

| 名称           | 描述                                                         |
| -------------- | ------------------------------------------------------------ |
| elementInfo    | Element结构。                                                |
| startItemIndex | 当前屏幕中显示的第一个item的index，当前获焦组件的index信息。如，list、select、swiper、tab_bar等组件。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetEndItemIndex

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetEndItemIndex(
    ArkUI_AccessibilityElementInfo* elementInfo, int32_t endItemIndex);
```

**描述：**

设置Element的endItemIndex。

**起始版本：** 13

**参数：** 

| 名称         | 描述                                                         |
| ------------ | ------------------------------------------------------------ |
| elementInfo  | Element结构。                                                |
| endItemIndex | 当前屏幕中显示的最后一个item的index，当前获焦组件的index信息。如，list、select、swiper、tab_bar等组件。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetItemCount

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetItemCount(
    ArkUI_AccessibilityElementInfo* elementInfo, int32_t itemCount);
```

**描述：**

设置Element的itemCount。

**起始版本：** 13

**参数：** 

| 名称        | 描述                                                      |
| ----------- | --------------------------------------------------------- |
| elementInfo | Element结构。                                             |
| itemCount   | 组件的item总数。如，list、select、swiper、tab_bar等组件。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetAccessibilityOffset

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityOffset(
    ArkUI_AccessibilityElementInfo* elementInfo, int32_t offset);
```

**描述：**

设置Element的offset。

**起始版本：** 13

**参数：** 

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| elementInfo | Element结构。                                                |
| offset      | 对于可滚动类组件，如list，grid，内容区相对组件的顶部坐标滚动的像素偏移量。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetAccessibilityGroup

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityGroup(
    ArkUI_AccessibilityElementInfo* elementInfo, bool accessibilityGroup);
```

**描述：**

设置Element的accessibilityGroup。

**起始版本：** 13

**参数：** 

| 名称               | 描述                                                         |
| ------------------ | ------------------------------------------------------------ |
| elementInfo        | Element结构。                                                |
| accessibilityGroup | 无障碍组，设置为true时，表示该组件及其所有子组件为一整个可以选中的组件，无障碍服务将不再关注其子组件内容。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetAccessibilityLevel

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityLevel(
    ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityLevel);
```

**描述：**

设置Element的accessibilityLevel。

**起始版本：** 13

**参数：** 

| 名称               | 描述                                                         |
| ------------------ | ------------------------------------------------------------ |
| elementInfo        | Element结构。                                                |
| accessibilityLevel | 无障碍重要性，用于控制某个组件是否可被无障碍辅助服务所识别。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetZIndex

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetZIndex(
    ArkUI_AccessibilityElementInfo* elementInfo, int32_t zIndex);
```

**描述：**

设置Element的zIndex。

**起始版本：** 13

**参数：** 

| 名称        | 描述                                             |
| ----------- | ------------------------------------------------ |
| elementInfo | Element结构。                                    |
| zIndex      | 组件z序，用于控制元素在垂直于屏幕的z轴上的位置。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetAccessibilityOpacity

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityOpacity(
    ArkUI_AccessibilityElementInfo* elementInfo, float opacity);
```

**描述：**

设置Element的opacity。

**起始版本：** 13

**参数：** 

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| elementInfo | Element结构。                                                |
| opacity     | 组件透明度信息，其取值范围是0到1，其中1表示完全不透明，而0则表示完全透明。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetBackgroundColor

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetBackgroundColor(
    ArkUI_AccessibilityElementInfo* elementInfo, const char* backgroundColor);
```

**描述：**

设置Element的backgroundColor。

**起始版本：** 13

**参数：** 

| 名称            | 描述             |
| --------------- | ---------------- |
| elementInfo     | Element结构。    |
| backgroundColor | 组件背景色信息。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetBackgroundImage

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetBackgroundImage(
    ArkUI_AccessibilityElementInfo* elementInfo, const char* backgroundImage);
```

**描述：**

设置Element的backgroundImage。

**起始版本：** 13

**参数：** 

| 名称            | 描述               |
| --------------- | ------------------ |
| elementInfo     | Element结构。      |
| backgroundImage | 组件背景图片信息。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetBlur

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetBlur(
    ArkUI_AccessibilityElementInfo* elementInfo, const char* blur);
```

**描述：**

设置Element的blur。

**起始版本：** 13

**参数：** 

| 名称        | 描述             |
| ----------- | ---------------- |
| elementInfo | Element结构。    |
| blur        | 组件模糊度信息。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetHitTestBehavior

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetHitTestBehavior(
    ArkUI_AccessibilityElementInfo* elementInfo, const char* hitTestBehavior);
```

**描述：**

设置Element的hitTestBehavior。

**起始版本：** 13

**参数：** 

| 名称            | 描述                                                         |
| --------------- | ------------------------------------------------------------ |
| elementInfo     | Element结构。                                                |
| hitTestBehavior | hitTest模式。取值：<br/>HitTestMode.Default: 默认模式<br/>HitTestMode.Block:阻塞模式<br/>HitTestMode.Transparent:透传模式<br/>HitTestMode.None: 关闭模式 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_CreateAccessibilityEventInfo

```C
ArkUI_AccessibilityEventInfo* OH_ArkUI_CreateAccessibilityEventInfo(void);
```

**描述：**

创建eventInfo结构，创建后需要调用OH_ArkUI_DestoryAccessibilityEventInfo释放。

**起始版本：** 13

**返回：** 

返回创建完成的ArkUI_AccessibilityEventInfo结构指针，如果创建失败返回NULL。

### OH_ArkUI_DestoryAccessibilityEventInfo

```C
void OH_ArkUI_DestoryAccessibilityEventInfo(ArkUI_AccessibilityEventInfo* eventInfo);
```

**描述：**

销毁eventInfo结构。

**起始版本：** 13

**参数：** 

| 名称      | 描述                              |
| --------- | --------------------------------- |
| eventInfo | 需要删除释放的eventInfo结构指针。 |

**返回：** 无



### OH_ArkUI_AccessibilityEventSetEventType

```C
int32_t OH_ArkUI_AccessibilityEventSetEventType(
    ArkUI_AccessibilityEventInfo* eventInfo,  ArkUI_AccessibilityEventType eventType);
```

**描述：**

设置eventInfo结构的eventType。

**起始版本：** 13

**参数：** 

| 名称      | 描述                                                         |
| --------- | ------------------------------------------------------------ |
| eventInfo | eventInfo结构指针。                                          |
| eventType | 事件类型[ArkUI_AccessibilityEventType](#arkui_accessibilityeventtype)。 |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityEventSetTextAnnouncedForAccessibility

```C
int32_t OH_ArkUI_AccessibilityEventSetTextAnnouncedForAccessibility(
    ArkUI_AccessibilityEventInfo* eventInfo, const char* textAnnouncedForAccessibility);
```

**描述：**

设置eventInfo结构的textAnnouncedForAccessibility。

**起始版本：** 13

**参数：** 

| 名称                          | 描述                                                         |
| ----------------------------- | ------------------------------------------------------------ |
| eventInfo                     | eventInfo结构指针。                                          |
| textAnnouncedForAccessibility | 当发送主动播报事件时，需要播报的内容。事件类型：ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_VIEW_ANNOUNCE_FOR_ACCESSIBILITY |

**返回：** 

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityEventSetRequestFocusId

```c
int32_t OH_ArkUI_AccessibilityEventSetRequestFocusId(
    ArkUI_AccessibilityEventInfo* eventInfo, int32_t requestFocusId);
```

**描述：**

设置eventInfo结构的requestFocusId。

**起始版本：** 13

**参数：** 

| 名称           | 描述                                                         |
| -------------- | ------------------------------------------------------------ |
| eventInfo      | eventInfo结构指针。                                          |
| requestFocusId | 当发送主动聚焦事件时，聚焦的节点id。聚焦需要保障不能变化。事件类型：ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_VIEW_REQUEST_FOCUS_FOR_ACCESSIBILITY |

**返回：**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityEventSetElementInfo

```C
int32_t OH_ArkUI_AccessibilityEventSetElementInfo(
    ArkUI_AccessibilityEventInfo* eventInfo,  ArkUI_AccessibilityElementInfo* elementInfo);
```

**描述：**

设置eventInfo结构的elementInfo。

**起始版本：** 13

**参数：** 

| 名称        | 描述                     |
| ----------- | ------------------------ |
| eventInfo   | eventInfo结构指针。      |
| elementInfo | 设置发送事件的组件信息。 |

**返回：**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_FindAccessibilityActionArgumentByKey

```
int32_t OH_ArkUI_FindAccessibilityActionArgumentByKey(
    ArkUI_AccessibilityActionArguments* arguments, const char* key, char** value);
```

**描述：**

获取ArkUI_AccessibilityActionArguments中指定key的value值。

**起始版本：** 13

**参数：** 

| 名称      | 描述                   |
| --------- | ---------------------- |
| arguments | action辅助参数内容。   |
| key       | 指定key。              |
| value     | 指定key对应的value值。 |

**返回：**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



## 枚举类型说明

### ArkUI_AcessbilityErrorCode

**描述：**

定义了各种错误码及其含义。

| 枚举值                                          | 描述       |
| ----------------------------------------------- | ---------- |
| ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESS       | 成功。     |
| ARKUI_ACCESSIBILITY_NATIVE_RESULT_FAILED        | 失败。     |
| ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER | 参数错误。 |
| ARKUI_ACCESSIBILITY_NATIVE_RESULT_OUT_OF_MEMORY | 内存不足。 |

**起始版本：**

13

### ArkUI_AccessibilitySearchMode

**描述：**

查询模式。

| 枚举值                                                       | 描述                                                     |
| ------------------------------------------------------------ | -------------------------------------------------------- |
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_CURRENT      | 只查询指定节点信息。                                     |
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_PREDECESSORS | 查询父组件。查询结果包含指定节点信息。                   |
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_SIBLINGS     | 查询兄弟节点组件。查询结果包含指定节点信息。             |
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_CHILDREN     | 查询当前节点的下一层孩子节点。查询结果包含指定节点信息。 |
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_RECURSIVE_CHILDREN | 查询当前节点的所有孩子节点。查询结果包含指定节点信息。   |

**起始版本：**

13

### ArkUI_AccessibilityFocusType

**描述：**

焦点类型。

| 枚举值                                              | 描述             |
| --------------------------------------------------- | ---------------- |
| ARKUI_ACCESSIBILITY_NATIVE_FOCUS_TYPE_INVALID       | 无效值。         |
| ARKUI_ACCESSIBILITY_NATIVE_FOCUS_TYPE_INPUT         | 组件获焦类型。   |
| ARKUI_ACCESSIBILITY_NATIVE_FOCUS_TYPE_ACCESSIBILITY | 无障碍获焦类型。 |

**起始版本：**

13

### ArkUI_Accessibility_ActionType

**描述：**

执行操作类型。

| 枚举值                                                      | 描述                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_INVALID                   | 无效值。                                                     |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CLICK                     | 点击事件。                                                   |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_LONG_CLICK                | 长按事件。                                                   |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_GAIN_ACCESSIBILITY_FOCUS  | 执行无障碍节点获焦。                                         |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CLEAR_ACCESSIBILITY_FOCUS | 清除无障碍节点获焦状态。                                     |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SCROLL_FORWARD            | 支持滚动的组件向前滚动。                                     |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SCROLL_BACKWARD           | 支持滚动的组件向后滚动。                                     |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_COPY                      | 针对文本组件支持选中内容的拷贝。                             |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_PASTE                     | 针对文本组件在光标所在位置粘贴。                             |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CUT                       | 针对文本组件支持选中内容的剪切。                             |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SELECT_TEXT               | 针对文本组件进行选择操作。结合[ArkUI_AccessibilityActionArguments](#arkui_accessibilityactionarguments)使用，配置selectTextStart，selectTextEnd，selectTextInForWard。进入编辑区选择一段文本内容。 |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SET_TEXT                  | 针对文本组件设置文本内容。                                   |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SET_CURSOR_POSITION       | 针对文本组件设置光标位置。结合[ArkUI_AccessibilityActionArguments](#arkui_accessibilityactionarguments)使用，配置offset设置位置。 |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_NEXT_HTML_ITEM            | 起始版本:API 15。配置后表示支持通过[findNextFocusAccessibilityNode](#findnextfocusaccessibilitynode-1)查找下一个焦点，方向为[ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_FORWARD](#arkui_accessibilityfocusmovedirection)。  |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_PREVIOUS_HTML_ITEM        | 起始版本:API 15。配置后表示支持通过[findNextFocusAccessibilityNode](#findnextfocusaccessibilitynode-1)查找上一个焦点，方向为[ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_BACKWARD](#arkui_accessibilityfocusmovedirection)。 |

**起始版本：**

13

### ArkUI_AccessibilityEventType

**描述：**

事件类型。

| 枚举值                                                       | 描述                                             |
| ------------------------------------------------------------ | ------------------------------------------------ |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_INVALID                | 无效值。                                         |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_CLICKED                | 被点击事件。                                     |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_LONG_CLICKED           | 被长按事件。                                     |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_SELECTED               | 被选中事件。                                     |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_TEXT_UPDATE            | 文本更新时需发送事件。                           |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_STATE_UPDATE      | 页面跳转、切换、大小变化、移动等需要发送该事件。 |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_CONTENT_UPDATE    | 页面内容发生变化时需要发送该事件。               |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_SCROLLED               | 可以滚动的组件发生滚动事件时需要发送该事件。     |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_ACCESSIBILITY_FOCUSED  | 触发无障碍聚焦事件。                               |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_ACCESSIBILITY_FOCUS_CLEARED | 清除无障碍节点聚焦事件。                             |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_REQUEST_ACCESSIBILITY_FOCUS | 请求指定节点聚焦。                           |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_OPEN              | 页面打开时需要发送该事件。                       |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_CLOSE             | 页面关闭时需要发送该事件。                       |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_ANNOUNCE_FOR_ACCESSIBILITY | 请求播报指定内容。                     |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_FOCUS_NODE_UPDATE      | 获焦组件发生位置或大小变化时需要发送事件。       |

**起始版本：**

13

### ArkUI_AccessibilityFocusMoveDirection

**描述：**

焦点移动方向。

| 枚举值                                        | 描述                                 |
| --------------------------------------------- | ------------------------------------ |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_INVALID  | 无效值。                             |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_UP       | 焦点向上移动。                       |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_DOWN     | 焦点向下移动。                       |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_LEFT     | 焦点向左移动。                       |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_RIGHT    | 焦点向右移动。                       |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_FORWARD  | 焦点向下一个可聚焦节点移动，基于查询请求中指定的基准节点。 |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_BACKWARD | 焦点向上一个可聚焦节点移动，基于查询请求中指定的基准节点。 |

**起始版本：**

13