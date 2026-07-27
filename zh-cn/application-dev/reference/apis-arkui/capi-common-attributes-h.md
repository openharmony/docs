# common_attributes.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @zhou-chaobo-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

提供NativeModule通用属性和事件的类型定义。

**引用文件：** <arkui/node_attributes/common_attributes.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**相关示例：** <!--RP1-->[native_type_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/native_type_sample)<!--RP1End-->

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_SnapshotOptions](capi-arkui-nativemodule-arkui-snapshotoptions.md) | ArkUI_SnapshotOptions | 定义截图的可选项。 |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md) | ArkUI_VisibleAreaEventOptions | 可见区域变化监听的参数。 |

### 枚举

| 名称                                                                  | typedef关键字                      | 描述                                |
|---------------------------------------------------------------------|---------------------------------|-----------------------------------|
| [ArkUI_HitTestMode](#arkui_hittestmode)                             | ArkUI_HitTestMode               | 触摸测试控制枚举值。                        |
| [ArkUI_Visibility](#arkui_visibility)                               | ArkUI_Visibility                | 控制组件的显隐枚举值。                       |
| [ArkUI_HoverEffect](#arkui_hovereffect) | ArkUI_HoverEffect | 组件被悬停时的效果。 |
| [ArkUI_FocusPriority](#arkui_focuspriority) | ArkUI_FocusPriority | 应用程序内焦点管理的优先级级别。确定UI组件在交互期间接收焦点的顺序。 |
| [ArkUI_UIState](#arkui_uistate)                                     | ArkUI_UIState                   | 组件的UI状态枚举，用于处理状态样式。               |
| [ArkUI_FocusMove](#arkui_focusmove)                                 | ArkUI_FocusMove                 | 定义焦点移动方向的枚举值。                     |
| [ArkUI_ResponseRegionSupportedTool](#arkui_responseregionsupportedtool)                         | ArkUI_ResponseRegionSupportedTool             | 定义支持响应区域设置的事件工具类型。                         |
| [ArkUI_RawInputEventType](#arkui_rawinputeventtype) | ArkUI_RawInputEventType | 原始输入事件类型枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [ArkUI_SnapshotOptions* OH_ArkUI_CreateSnapshotOptions()](#oh_arkui_createsnapshotoptions) | 创建一个截图选项，当返回值不再使用时必须通过[OH_ArkUI_DestroySnapshotOptions](#oh_arkui_destroysnapshotoptions)释放。 |
| [void OH_ArkUI_DestroySnapshotOptions(ArkUI_SnapshotOptions* snapshotOptions)](#oh_arkui_destroysnapshotoptions) | 销毁截图选项指针。 |
| [int32_t OH_ArkUI_SnapshotOptions_SetScale(ArkUI_SnapshotOptions* snapshotOptions, float scale)](#oh_arkui_snapshotoptions_setscale) | 配置截图选项中的缩放属性。 |
| [int32_t OH_ArkUI_SnapshotOptions_SetColorMode(ArkUI_SnapshotOptions* snapshotOptions, int32_t colorSpace, bool isAuto)](#oh_arkui_snapshotoptions_setcolormode) | 设置截图选项中的色彩空间。 |
| [int32_t OH_ArkUI_SnapshotOptions_SetDynamicRangeMode(ArkUI_SnapshotOptions* snapshotOptions, int32_t dynamicRangeMode, bool isAuto)](#oh_arkui_snapshotoptions_setdynamicrangemode) | 设置截图选项中的动态范围模式。 |
| [ArkUI_VisibleAreaEventOptions* OH_ArkUI_VisibleAreaEventOptions_Create()](#oh_arkui_visibleareaeventoptions_create) | 创建可见区域变化监听的参数。 |
| [void OH_ArkUI_VisibleAreaEventOptions_Dispose(ArkUI_VisibleAreaEventOptions* option)](#oh_arkui_visibleareaeventoptions_dispose) | 销毁可见区域变化监听的参数。 |
| [int32_t OH_ArkUI_VisibleAreaEventOptions_SetRatios(ArkUI_VisibleAreaEventOptions* option, float* value, int32_t size)](#oh_arkui_visibleareaeventoptions_setratios) | 设置阈值数组。 |
| [int32_t OH_ArkUI_VisibleAreaEventOptions_SetExpectedUpdateInterval(ArkUI_VisibleAreaEventOptions *option, int32_t value)](#oh_arkui_visibleareaeventoptions_setexpectedupdateinterval) | 设置开发者期望的计算间隔，用于控制可见区域比例的计算频率。 |
| [int32_t OH_ArkUI_VisibleAreaEventOptions_SetMeasureFromViewport(ArkUI_VisibleAreaEventOptions *option, bool measureFromViewport)](#oh_arkui_visibleareaeventoptions_setmeasurefromviewport) | 设置可见区域计算模式。 |
| [int32_t OH_ArkUI_VisibleAreaEventOptions_GetRatios(ArkUI_VisibleAreaEventOptions* option, float* value, int32_t* size)](#oh_arkui_visibleareaeventoptions_getratios) | 获取阈值数组。 |
| [int32_t OH_ArkUI_VisibleAreaEventOptions_GetExpectedUpdateInterval(ArkUI_VisibleAreaEventOptions* option)](#oh_arkui_visibleareaeventoptions_getexpectedupdateinterval) | 获取预期更新间隔。 |
| [bool OH_ArkUI_VisibleAreaEventOptions_GetMeasureFromViewport(ArkUI_VisibleAreaEventOptions* option)](#oh_arkui_visibleareaeventoptions_getmeasurefromviewport) | 获取可见区域计算模式。 |

## 枚举类型说明

### ArkUI_HitTestMode

```c
enum ArkUI_HitTestMode
```

**描述：**


触摸测试控制枚举值。

**起始版本：** 12

| 枚举项 | 描述                                                     |
| -- |--------------------------------------------------------|
| ARKUI_HIT_TEST_MODE_DEFAULT = 0 | 默认触摸测试效果。自身及子节点响应触摸测试，但阻塞兄弟节点的触摸测试，不影响祖先节点的触摸测试。                                              |
| ARKUI_HIT_TEST_MODE_BLOCK = 1 | 自身响应触摸测试，阻塞子节点、兄弟节点和祖先节点的触摸测试。                                              |
| ARKUI_HIT_TEST_MODE_TRANSPARENT = 2 | 自身和子节点都响应触摸测试，不会阻塞兄弟节点和祖先节点的触摸测试。                                         |
| ARKUI_HIT_TEST_MODE_NONE = 3 | 自身不响应触摸测试，不会阻塞子节点、兄弟节点和祖先节点的触摸测试。                                             |
| ARKUI_HIT_TEST_MODE_BLOCK_HIERARCHY = 4 | 自身和子节点响应触摸测试，阻止所有优先级较低的兄弟节点和父节点参与触摸测试。<br>**起始版本：** 20 |
| ARKUI_HIT_TEST_MODE_BLOCK_DESCENDANTS = 5 | 自身不响应触摸测试，并且所有的后代（孩子，孙子等）也不响应触摸测试，不会影响祖先节点的触摸测试。<br>**起始版本：** 20                     |

### ArkUI_Visibility

```c
enum ArkUI_Visibility
```

**描述：**


控制组件的显隐枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_VISIBILITY_VISIBLE = 0 | 显示。 |
| ARKUI_VISIBILITY_HIDDEN = 1 | 隐藏，但参与布局进行占位。 |
| ARKUI_VISIBILITY_NONE = 2 | 隐藏，但不参与布局，不进行占位。 |

### ArkUI_HoverEffect

```c
enum ArkUI_HoverEffect
```

**描述：**


组件被悬停时的效果。

**起始版本：** 23

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_HOVER_EFFECT_AUTO = 0 | 默认效果。 |
| ARKUI_HOVER_EFFECT_SCALE  | 缩放效果。 |
| ARKUI_HOVER_EFFECT_HIGHLIGHT  | 高亮效果。 |
| ARKUI_HOVER_EFFECT_NONE  | 无效果。 |

### ArkUI_FocusPriority

```c
enum ArkUI_FocusPriority
```

**描述：**


应用程序内焦点管理的优先级级别。确定UI组件在交互期间接收焦点的顺序。

**起始版本：** 23

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_FOCUS_PRIORITY_AUTO  = 0 | 默认优先级。 |
| ARKUI_FOCUS_PRIORITY_PRIOR = 2000   | 容器内优先获焦的优先级。 |
| ARKUI_FOCUS_PRIORITY_PREVIOUS = 3000   | 上一次容器整体失焦时获焦节点的优先级。 |

### ArkUI_UIState

```c
enum ArkUI_UIState
```

**描述：**


组件的UI状态枚举，用于处理状态样式。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| UI_STATE_NORMAL = 0 | 正常状态。 |
| UI_STATE_PRESSED = 1 << 0 | 按压状态。 |
| UI_STATE_FOCUSED = 1 << 1 | 获焦状态。 |
| UI_STATE_DISABLED = 1 << 2 | 禁用状态。 |
| UI_STATE_SELECTED = 1 << 3 | 选中状态，此状态仅由某些特定类型的组件支持，分别是Checkbox、Radio、Toggle、List、Grid和MenuItem。 |
| UI_STATE_HOVERED = 1 << 4 | 悬浮状态。<br/>**起始版本：** 26.0.0 |

### ArkUI_FocusMove

```c
enum ArkUI_FocusMove
```

**描述：**

定义焦点移动方向的枚举值。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_FOCUS_MOVE_FORWARD = 0 | 向前移动焦点。 |
| ARKUI_FOCUS_MOVE_BACKWARD = 1 | 向后移动焦点。 |
| ARKUI_FOCUS_MOVE_UP = 2 | 向上移动焦点。 |
| ARKUI_FOCUS_MOVE_DOWN = 3 | 向下移动焦点。 |
| ARKUI_FOCUS_MOVE_LEFT = 4 | 向左移动焦点。 |
| ARKUI_FOCUS_MOVE_RIGHT = 5 | 向右移动焦点。 |

### ArkUI_ResponseRegionSupportedTool

```c
enum ArkUI_ResponseRegionSupportedTool
```

**描述：**


定义支持响应区域设置的事件工具类型。

**起始版本：** 23

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_RESPONSE_REGIN_SUPPORTED_TOOL_ALL  = 0 | 所有输入工具类型。 |
| ARKUI_RESPONSE_REGIN_SUPPORTED_TOOL_FINGER  = 1  | 手指类型。 |
| ARKUI_RESPONSE_REGIN_SUPPORTED_TOOL_PEN  = 2  | 手写笔类型。 |
| ARKUI_RESPONSE_REGIN_SUPPORTED_TOOL_MOUSE  = 3  | 鼠标类型。 |

### ArkUI_RawInputEventType

```c
enum ArkUI_RawInputEventType
```

**描述**

原始输入事件类型枚举。

**起始版本：** 26.0.0

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_RAW_INPUT_EVENT_TYPE_TOUCH = 0 | 触摸事件类型。 |
| ARKUI_RAW_INPUT_EVENT_TYPE_MOUSE = 1 | 鼠标事件类型。 |

## 函数说明

### OH_ArkUI_CreateSnapshotOptions()

```c
ArkUI_SnapshotOptions* OH_ArkUI_CreateSnapshotOptions()
```

**描述：**


创建一个截图选项，当返回值不再使用时必须通过[OH_ArkUI_DestroySnapshotOptions](#oh_arkui_destroysnapshotoptions)释放。

**起始版本：** 15

**返回：**

| 类型                         | 说明 |
|----------------------------| -- |
| [ArkUI_SnapshotOptions](capi-arkui-nativemodule-arkui-snapshotoptions.md)* | 返回指向创建的截图选项对象的指针。如果对象返回空指针，则表示创建失败，失败的原因可能是地址空间已满。 |

### OH_ArkUI_DestroySnapshotOptions()

```c
void OH_ArkUI_DestroySnapshotOptions(ArkUI_SnapshotOptions* snapshotOptions)
```

**描述：**

销毁截图选项指针。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SnapshotOptions](capi-arkui-nativemodule-arkui-snapshotoptions.md)* snapshotOptions | 截图选项。 |

### OH_ArkUI_SnapshotOptions_SetScale()

```c
int32_t OH_ArkUI_SnapshotOptions_SetScale(ArkUI_SnapshotOptions* snapshotOptions, float scale)
```

**描述：**

配置截图选项中的缩放属性。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SnapshotOptions](capi-arkui-nativemodule-arkui-snapshotoptions.md)* snapshotOptions | 截图选项。 |
| float scale | 缩放值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>         异常原因：传入参数验证失败，参数不能为空。 |
### OH_ArkUI_SnapshotOptions_SetColorMode()

``` C++
int32_t OH_ArkUI_SnapshotOptions_SetColorMode(ArkUI_SnapshotOptions* snapshotOptions, int32_t colorSpace, bool isAuto)
```

**描述：**

设置截图选项中的色彩空间。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SnapshotOptions](capi-arkui-nativemodule-arkui-snapshotoptions.md)* snapshotOptions | 截图选项指针。 |
| int32_t colorSpace | 指定截图使用的色彩空间。<br>如果知道需要截图的组件使用的色彩空间，可以通过colorSpace参数指定，并将isAuto设置为false，以达到预期的截图效果。<br>支持的取值为：3（RGB色域为Display P3类型）、4（RGB色域为SRGB类型）、27（RGB色域为DISPLAY BT2020类型）。<br>默认值：4<br>仅当isAuto设置为false，该参数设置生效。 |
| bool isAuto | 是否由系统自动决定所使用的色彩空间。<br>true表示系统自动决定所使用的色彩空间。在不确定组件使用的色彩空间时，建议将isAuto设置为true，让系统根据实际情况自动决定使用的色彩空间。<br>false表示使用通过colorSpace字段设置的色彩空间类型进行截图。<br>默认值：false |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_SnapshotOptions_SetDynamicRangeMode()

``` C++
int32_t OH_ArkUI_SnapshotOptions_SetDynamicRangeMode(ArkUI_SnapshotOptions* snapshotOptions, int32_t dynamicRangeMode, bool isAuto)
```

**描述：**

设置截图选项中的动态范围模式。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SnapshotOptions](capi-arkui-nativemodule-arkui-snapshotoptions.md)* snapshotOptions | 截图选项指针。 |
| int32_t dynamicRangeMode | 指定截图使用的动态范围模式。<br>如果知道截图对象使用的动态范围模式，可通过dynamicRangeMode参数指定动态范围模式，并将isAuto设置为false，以达到预期的截图效果。<br>支持的取值为：[ArkUI_DynamicRangeMode](capi-image-h.md#arkui_dynamicrangemode)枚举值。<br>默认值：ARKUI_DYNAMIC_RANGE_MODE_STANDARD<br>仅当isAuto设置为false，该参数设置生效。 |
| bool isAuto | 是否由系统自动决定所使用的动态范围模式。<br>true表示系统自动决定所使用的动态范围模式。在不确定组件使用的动态范围模式时，建议将isAuto设置为true，让系统根据实际情况自动决定使用的动态范围模式。<br>false表示使用通过dynamicRangeMode字段设置的动态范围模式进行截图。<br>默认值：false |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_VisibleAreaEventOptions_Create()

```c
ArkUI_VisibleAreaEventOptions* OH_ArkUI_VisibleAreaEventOptions_Create()
```

**描述：**

创建可见区域变化监听的参数。

**起始版本：** 17

**返回：**

| 类型                                 | 说明 |
|------------------------------------| -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md)* | 可见区域变化监听的参数。 |

### OH_ArkUI_VisibleAreaEventOptions_Dispose()

```c
void OH_ArkUI_VisibleAreaEventOptions_Dispose(ArkUI_VisibleAreaEventOptions* option)
```

**描述：**

销毁可见区域变化监听的参数。

**起始版本：** 17

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md)* option | 需要销毁的实例。 |

### OH_ArkUI_VisibleAreaEventOptions_SetRatios()

```c
int32_t OH_ArkUI_VisibleAreaEventOptions_SetRatios(ArkUI_VisibleAreaEventOptions* option, float* value, int32_t size)
```

**描述：**

设置阈值数组。

**起始版本：** 17

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md)* option | 可见区域变化监听的参数实例。 |
| float* value | 阈值数组。其中每个元素代表组件可见面积（即组件在屏幕显示区的面积，只计算父组件内的面积，超出父组件部分不会计算）与组件自身面积的比值。每个阈值的取值范围为[0.0, 1.0]，如果开发者设置的阈值超出该范围，则会实际取值0.0或1.0。 |
| int32_t size | 阈值数组大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>         异常原因：传入参数验证失败，参数不能为空。 |

### OH_ArkUI_VisibleAreaEventOptions_SetExpectedUpdateInterval()

```c
int32_t OH_ArkUI_VisibleAreaEventOptions_SetExpectedUpdateInterval(ArkUI_VisibleAreaEventOptions *option, int32_t value)
```

**描述：**

设置开发者期望的计算间隔，用于控制可见区域比例的计算频率。

**起始版本：** 17

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md) *option | 可见区域变化监听的参数实例。 |
| int32_t value | 开发者期望的计算间隔，单位为ms。默认值：1000ms。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>         异常原因：传入参数验证失败，参数不能为空。 |

### OH_ArkUI_VisibleAreaEventOptions_SetMeasureFromViewport()

```c
int32_t OH_ArkUI_VisibleAreaEventOptions_SetMeasureFromViewport(ArkUI_VisibleAreaEventOptions* option, bool measureFromViewport)
```

**描述：**

设置可见区域计算模式。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md)* option | 可见区域变化监听的参数实例。 |
| bool measureFromViewport | 设置可见区域计算模式。<br/>当measureFromViewport设置为true时，系统在计算该组件的可见区域时，会考虑父组件的NODE_CLIP属性设置。如果父组件的NODE_CLIP为false，则认为其内的子组件可以超出其区域进行显示，因此超出父组件的区域也将被视为可见区域纳入计算；如果父组件的NODE_CLIP设置为true，则组件超出父组件的区域会被裁剪，无法显示，因此会被视为不可见区域进行计算。而当measureFromViewport设置为false时，则不考虑NODE_CLIP的影响，直接将组件超出父组件的部分视为不可见区域。<br/>默认值：false |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>         异常原因：传入参数验证失败，参数不能为空。 |

### OH_ArkUI_VisibleAreaEventOptions_GetRatios()

```c
int32_t OH_ArkUI_VisibleAreaEventOptions_GetRatios(ArkUI_VisibleAreaEventOptions* option, float* value, int32_t* size)
```

**描述：**

获取阈值数组。

**起始版本：** 17

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md)* option | 可见区域变化监听的参数实例。 |
| float* value | 阈值数组。 |
| int32_t* size | 阈值数组大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。<br>         [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 数组大小不够。<br>         异常原因：传入参数验证失败，参数不能为空。 |

### OH_ArkUI_VisibleAreaEventOptions_GetExpectedUpdateInterval()

```c
int32_t OH_ArkUI_VisibleAreaEventOptions_GetExpectedUpdateInterval(ArkUI_VisibleAreaEventOptions* option)
```

**描述：**

获取预期更新间隔。

**起始版本：** 17

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md)* option | 可见区域变化监听的参数实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 预期更新间隔，单位为ms。定义了开发者期望的更新间隔。默认值：1000。 |


### OH_ArkUI_VisibleAreaEventOptions_GetMeasureFromViewport()

```c
bool OH_ArkUI_VisibleAreaEventOptions_GetMeasureFromViewport(ArkUI_VisibleAreaEventOptions* option)
```

**描述：**

获取可见区域计算模式。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md)* option | 可见区域变化监听的参数实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 获取可见区域计算模式。<br/>当measureFromViewport设置为true时，系统在计算该组件的可见区域时，会考虑父组件的NODE_CLIP属性设置。如果父组件的NODE_CLIP为false，则认为其内的子组件可以超出其区域进行显示，因此超出父组件的区域也将被视为可见区域纳入计算；如果父组件的NODE_CLIP设置为true，则组件超出父组件的区域会被裁剪，无法显示，因此会被视为不可见区域进行计算。而当measureFromViewport设置为false时，则不考虑NODE_CLIP的影响，直接将组件超出父组件的部分视为不可见区域。<br/>默认值：false |