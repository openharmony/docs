# water_flow.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @rongShao-Z; @guozejun-->
<!--Designer: @guozejun-->
<!--Tester: @leiyuqian-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

定义WaterFlow组件相关的枚举和接口。

**引用文件：** <arkui/node_attributes/water_flow.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**相关示例：** <!--RP1-->[NDKWaterFlowSample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NDKWaterFlowSample)<!--RP1End-->

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_Margin](capi-arkui-nativemodule-arkui-margin.md) | ArkUI_Margin | 外边距属性，定义组件边界与父容器或相邻组件之间的空白区域，影响组件在布局中的实际占用空间和位置。 |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md) | ArkUI_WaterFlowSectionOption | 定义[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)分组配置信息。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_WaterFlowLayoutMode](#arkui_waterflowlayoutmode) | ArkUI_WaterFlowLayoutMode | 定义[WaterFlow](../apis-arkui/arkui-ts/ts-container-waterflow.md)组件布局模式枚举值。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_WaterFlowSectionOption* OH_ArkUI_WaterFlowSectionOption_Create()](#oh_arkui_waterflowsectionoption_create) | - | 创建FlowItem分组配置信息，初始数组长度为1。使用结束后需调用OH_ArkUI_WaterFlowSectionOption_Dispose释放资源。 |
| [void OH_ArkUI_WaterFlowSectionOption_Dispose(ArkUI_WaterFlowSectionOption* option)](#oh_arkui_waterflowsectionoption_dispose) | - | 销毁由OH_ArkUI_WaterFlowSectionOption_Create创建的FlowItem分组配置信息。销毁后不得继续访问该指针。 |
| [void OH_ArkUI_WaterFlowSectionOption_SetSize(ArkUI_WaterFlowSectionOption* option, int32_t size)](#oh_arkui_waterflowsectionoption_setsize) | - | 设置FlowItem分组配置信息数组长度。扩容时保留原有配置，并在数组末尾新增分组配置；缩容时保留新长度范围内的配置，删除其余配置。 |
| [int32_t OH_ArkUI_WaterFlowSectionOption_GetSize(ArkUI_WaterFlowSectionOption* option)](#oh_arkui_waterflowsectionoption_getsize) | - | 获取FlowItem分组配置信息数组长度。 |
| [void OH_ArkUI_WaterFlowSectionOption_SetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index, int32_t itemCount)](#oh_arkui_waterflowsectionoption_setitemcount) | - | 设置分组中FlowItem数量。 |
| [int32_t OH_ArkUI_WaterFlowSectionOption_GetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getitemcount) | - | 通过FlowItem分组配置信息获取对应索引下的FlowItem数量。 |
| [void OH_ArkUI_WaterFlowSectionOption_SetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index, int32_t crossCount)](#oh_arkui_waterflowsectionoption_setcrosscount) | - | 设置布局栅格，纵向布局时为列数，横向布局时为行数。 |
| [int32_t OH_ArkUI_WaterFlowSectionOption_GetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getcrosscount) | - | 通过FlowItem分组配置信息获取对应索引下的布局栅格数。 |
| [void OH_ArkUI_WaterFlowSectionOption_SetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index, float columnGap)](#oh_arkui_waterflowsectionoption_setcolumngap) | - | 设置分组的列间距。 |
| [float OH_ArkUI_WaterFlowSectionOption_GetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getcolumngap) | - | 通过FlowItem分组配置信息获取对应索引下的分组的列间距。 |
| [void OH_ArkUI_WaterFlowSectionOption_SetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index, float rowGap)](#oh_arkui_waterflowsectionoption_setrowgap) | - | 设置指定分组的行间距。 |
| [float OH_ArkUI_WaterFlowSectionOption_GetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getrowgap) | - | 通过FlowItem分组配置信息获取对应索引下的分组的行间距。 |
| [void OH_ArkUI_WaterFlowSectionOption_SetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index, float marginTop, float marginRight, float marginBottom, float marginLeft)](#oh_arkui_waterflowsectionoption_setmargin) | - | 设置分组的外边距。 |
| [ArkUI_Margin OH_ArkUI_WaterFlowSectionOption_GetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getmargin) | - | 通过FlowItem分组配置信息获取对应索引下的分组的外边距。 |
| [void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex (ArkUI_WaterFlowSectionOption* option, int32_t index, float(\*callback)(int32_t itemIndex))](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindex) | - | 为分组配置信息数组中索引为index的分组注册用于提供FlowItem主轴尺寸的回调。WaterFlow布局该分组内的FlowItem时，将当前FlowItem在WaterFlow中的索引作为itemIndex传入回调，并将回调返回值作为该FlowItem的主轴尺寸。主轴尺寸在纵向布局时为高度，在横向布局时为宽度。如需在回调中使用自定义数据，可使用OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData。 |
| [void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData (ArkUI_WaterFlowSectionOption* option, int32_t index, void* userData, float (\*callback)(int32_t itemIndex, void* userData))](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindexwithuserdata) | - | 为分组配置信息数组中索引为index的分组注册用于提供FlowItem主轴尺寸的回调，同时保存传入的userData。WaterFlow布局该分组内的FlowItem时，将当前FlowItem在WaterFlow中的索引和userData分别作为回调的第一个、第二个参数传入。userData仅用于向回调传递附加数据，FlowItem的主轴尺寸由回调返回值提供。主轴尺寸在纵向布局时为高度，在横向布局时为宽度。 |

## 枚举类型说明

### ArkUI_WaterFlowLayoutMode

```c
enum ArkUI_WaterFlowLayoutMode
```

**描述：**


定义[WaterFlow](../apis-arkui/arkui-ts/ts-container-waterflow.md)组件布局模式枚举值。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_WATER_FLOW_LAYOUT_MODE_ALWAYS_TOP_DOWN = 0 | 从上到下布局。列数切换场景需要从第一个[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)开始布局到当前显示的[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)。 |
| ARKUI_WATER_FLOW_LAYOUT_MODE_SLIDING_WINDOW = 1 | 移动窗口布局。列数切换场景只重新布局当前显示范围到[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)，手指向下滑动再布局从上方进入显示范围的[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)。 |

## 函数说明

### OH_ArkUI_WaterFlowSectionOption_Create()

```c
ArkUI_WaterFlowSectionOption* OH_ArkUI_WaterFlowSectionOption_Create()
```

**描述：**


创建[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)分组配置信息，初始数组长度为1。使用结束后需调用[OH_ArkUI_WaterFlowSectionOption_Dispose](#oh_arkui_waterflowsectionoption_dispose)释放资源。

**起始版本：** 12

**返回：**

| 类型                                | 说明 |
|-----------------------------------| -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* | [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)分组配置信息。 |

### OH_ArkUI_WaterFlowSectionOption_Dispose()

```c
void OH_ArkUI_WaterFlowSectionOption_Dispose(ArkUI_WaterFlowSectionOption* option)
```

**描述：**


销毁由[OH_ArkUI_WaterFlowSectionOption_Create](#oh_arkui_waterflowsectionoption_create)创建的[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)分组配置信息。销毁后不得继续访问该指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | 要销毁的[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)分组配置信息。 |

### OH_ArkUI_WaterFlowSectionOption_SetSize()

```c
void OH_ArkUI_WaterFlowSectionOption_SetSize(ArkUI_WaterFlowSectionOption* option, int32_t size)
```

**描述：**


设置FlowItem分组配置信息数组长度。扩容时保留原有配置，并在数组末尾新增分组配置；缩容时保留新长度范围内的配置，删除其余配置。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t size | 数组长度，取值范围为大于等于0。传入负数时不执行操作。 |

### OH_ArkUI_WaterFlowSectionOption_GetSize()

```c
int32_t OH_ArkUI_WaterFlowSectionOption_GetSize(ArkUI_WaterFlowSectionOption* option)
```

**描述：**


获取[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)分组配置信息数组长度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 数组长度。option为空指针时返回-1。 |

### OH_ArkUI_WaterFlowSectionOption_SetItemCount()

```c
void OH_ArkUI_WaterFlowSectionOption_SetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index, int32_t itemCount)
```

**描述：**


设置分组中[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)数量。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)分组配置信息。 |
| int32_t index | 分组配置信息数组索引值，取值范围为大于等于0。超出当前数组长度时，数组自动扩展至index + 1。 |
| int32_t itemCount | 分组中[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)数量，取值范围为大于等于0。传入负数时不执行操作。 |

### OH_ArkUI_WaterFlowSectionOption_GetItemCount()

```c
int32_t OH_ArkUI_WaterFlowSectionOption_GetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**描述：**


通过[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)分组配置信息获取对应索引下的[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)数量。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)分组配置信息。 |
| int32_t index | 分组配置信息数组索引值，取值范围为0至数组长度减1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 分组中FlowItem数量。index大于等于数组长度时返回0，option为空指针时返回-1。 |

### OH_ArkUI_WaterFlowSectionOption_SetCrossCount()

```c
void OH_ArkUI_WaterFlowSectionOption_SetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index, int32_t crossCount)
```

**描述：**


设置布局栅格，纵向布局时为列数，横向布局时为行数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t index | 分组配置信息数组索引值，取值范围为大于等于0。超出当前数组长度时，数组自动扩展至index + 1。 |
| int32_t crossCount | 布局栅格数量，纵向布局时为列数，横向布局时为行数。传入小于等于0的值时按1处理。 |

### OH_ArkUI_WaterFlowSectionOption_GetCrossCount()

```c
int32_t OH_ArkUI_WaterFlowSectionOption_GetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**描述：**


通过[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)分组配置信息获取对应索引下的布局栅格数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t index | 分组配置信息数组索引值，取值范围为0至数组长度减1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 布局栅格数量。index大于等于数组长度时返回0，option为空指针时返回-1。 |

### OH_ArkUI_WaterFlowSectionOption_SetColumnGap()

```c
void OH_ArkUI_WaterFlowSectionOption_SetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index, float columnGap)
```

**描述：**


设置分组的列间距。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t index | 分组配置信息数组索引值，取值范围为大于等于0。超出当前数组长度时，数组自动扩展至index + 1。 |
| float columnGap | 列间距。单位：vp。传入负数时按0处理。 |

### OH_ArkUI_WaterFlowSectionOption_GetColumnGap()

```c
float OH_ArkUI_WaterFlowSectionOption_GetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**描述：**


通过FlowItem分组配置信息获取对应索引下的分组的列间距。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t index | 分组配置信息数组索引值，取值范围为0至数组长度减1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 列间距。单位：vp。 |

### OH_ArkUI_WaterFlowSectionOption_SetRowGap()

```c
void OH_ArkUI_WaterFlowSectionOption_SetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index, float rowGap)
```

**描述：**


设置指定分组的行间距。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t index | 分组配置信息数组索引值，取值范围为大于等于0。超出当前数组长度时，数组自动扩展至index + 1。 |
| float rowGap | 行间距。单位：vp。传入负数时按0处理。 |

### OH_ArkUI_WaterFlowSectionOption_GetRowGap()

```c
float OH_ArkUI_WaterFlowSectionOption_GetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**描述：**


通过[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)分组配置信息获取对应索引下的分组的行间距。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)分组配置信息。 |
| int32_t index | 分组配置信息数组索引值，取值范围为0至数组长度减1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 行间距。单位：vp。 |

### OH_ArkUI_WaterFlowSectionOption_SetMargin()

```c
void OH_ArkUI_WaterFlowSectionOption_SetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index, float marginTop, float marginRight, float marginBottom, float marginLeft)
```

**描述：**


设置分组的外边距。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)分组配置信息。 |
| int32_t index | 分组配置信息数组索引值，取值范围为大于等于0。超出当前数组长度时，数组自动扩展至index + 1。 |
| float marginTop | [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)上外边距。单位：vp。 |
| float marginRight | [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)右外边距。单位：vp。 |
| float marginBottom | [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)下外边距。单位：vp。 |
| float marginLeft | [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)左外边距。单位：vp。 |

### OH_ArkUI_WaterFlowSectionOption_GetMargin()

```c
ArkUI_Margin OH_ArkUI_WaterFlowSectionOption_GetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**描述：**


通过[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)分组配置信息获取对应索引下的分组的外边距。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)分组配置信息。 |
| int32_t index | 分组配置信息数组索引值，取值范围为0至数组长度减1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_Margin](capi-arkui-nativemodule-arkui-margin.md) | 外边距。单位：vp。 |

### OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex()

```c
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex(ArkUI_WaterFlowSectionOption* option, int32_t index, float(*callback)(int32_t itemIndex))
```

**描述：**


为分组配置信息数组中索引为index的分组注册用于提供[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)主轴尺寸的回调。WaterFlow布局该分组内的FlowItem时，将当前FlowItem在WaterFlow中的索引作为itemIndex传入回调，并将回调返回值作为该FlowItem的主轴尺寸。主轴尺寸在纵向布局时为高度，在横向布局时为宽度。如需在回调中使用自定义数据，可使用[OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindexwithuserdata)。

**起始版本：** 12


**参数：**

| 参数项                                            | 描述 |
|------------------------------------------------| -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)分组配置信息。 |
| int32_t index                                  | 要注册回调的分组配置信息数组索引值，取值范围为0至数组长度减1。 |
| float (*callback)(int32_t itemIndex)            | 主轴尺寸回调。itemIndex为当前[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)在WaterFlow中的索引；开发者通过返回值提供该FlowItem的主轴尺寸，单位：vp，返回负数时按0处理。 |

### OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData()

```c
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData(ArkUI_WaterFlowSectionOption* option, int32_t index, void* userData, float (*callback)(int32_t itemIndex, void* userData))
```

**描述：**


为分组配置信息数组中索引为index的分组注册用于提供[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)主轴尺寸的回调，同时保存传入的userData。WaterFlow布局该分组内的FlowItem时，将当前FlowItem在WaterFlow中的索引和userData分别作为回调的第一个、第二个参数传入。userData仅用于向回调传递附加数据，FlowItem的主轴尺寸由回调返回值提供。主轴尺寸在纵向布局时为高度，在横向布局时为宽度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)分组配置信息。 |
| int32_t index | 要注册回调的分组配置信息数组索引值，取值范围为0至数组长度减1。 |
| void* userData | 传递给回调的附加数据指针，不直接表示FlowItem的主轴尺寸。WaterFlow布局时，将该参数作为回调的第二个参数传入。该指针由调用方管理，需在回调可能触发期间保持有效。 |
| float (\*callback)(int32_t itemIndex, void\* userData) | 主轴尺寸回调。itemIndex为当前[FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md)在WaterFlow中的索引；userData为传入接口的用户自定义数据；开发者通过返回值提供该FlowItem的主轴尺寸，单位：vp，返回负数时按0处理。 |
