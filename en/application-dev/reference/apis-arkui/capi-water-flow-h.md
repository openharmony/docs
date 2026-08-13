# water_flow.h

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @rongShao-Z; @guozejun-->
<!--Designer: @guozejun-->
<!--Tester: @leiyuqian-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=e4da1f59f2bfae1b45300542e10b9243ddb9c5c2 translatedAt=2026-08-11T09:12:27.718Z pushedAt=2026-08-13T03:15:27.555Z -->

## Overview

Defines enumerations and APIs related to **WaterFlow**.

**File to include:** <arkui/node_attributes/water_flow.h>

**Library:** libace_ndk.z.so

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Since:** 12

**Related module:** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Sample:** <!--RP1-->[NDKWaterFlowSample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NDKWaterFlowSample)<!--RP1End-->

## Summary

### Structs

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_Margin](capi-arkui-nativemodule-arkui-margin.md) | ArkUI_Margin | Describes the margins of a component. This struct defines the blank area between the component boundary and the parent container or an adjacent component, affecting the actual occupied space and position of the component in the layout. |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md) | ArkUI_WaterFlowSectionOption | Defines the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration. |

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_WaterFlowLayoutMode](#arkui_waterflowlayoutmode) | ArkUI_WaterFlowLayoutMode | Enumerates the layout modes of the [WaterFlow](../apis-arkui/arkui-ts/ts-container-waterflow.md) component. |

### Functions

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_WaterFlowSectionOption* OH_ArkUI_WaterFlowSectionOption_Create()](#oh_arkui_waterflowsectionoption_create) | - | Creates a water flow section configuration, with an initial array length of 1. Call **OH_ArkUI_WaterFlowSectionOption_Dispose** to release resources after the use. |
| [void OH_ArkUI_WaterFlowSectionOption_Dispose(ArkUI_WaterFlowSectionOption* option)](#oh_arkui_waterflowsectionoption_dispose) | - | Disposes of the pointer to the water flow section configuration created by **OH_ArkUI_WaterFlowSectionOption_Create**. The pointer must not be accessed after being disposed of. |
| [void OH_ArkUI_WaterFlowSectionOption_SetSize(ArkUI_WaterFlowSectionOption* option, int32_t size)](#oh_arkui_waterflowsectionoption_setsize) | - | Sets the array length for a water flow section configuration. For scaling-out, the original configuration is retained and a new water flow section configuration is added at the end of the array; for scaling-in, the configuration within the new length range is retained and the rest are deleted. |
| [int32_t OH_ArkUI_WaterFlowSectionOption_GetSize(ArkUI_WaterFlowSectionOption* option)](#oh_arkui_waterflowsectionoption_getsize) | - | Obtains the array length of a water flow section configuration. |
| [void OH_ArkUI_WaterFlowSectionOption_SetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index, int32_t itemCount)](#oh_arkui_waterflowsectionoption_setitemcount) | - | Sets the number of items in a water flow section. |
| [int32_t OH_ArkUI_WaterFlowSectionOption_GetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getitemcount) | - | Obtains the number of items in the water flow section that matches the specified index. |
| [void OH_ArkUI_WaterFlowSectionOption_SetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index, int32_t crossCount)](#oh_arkui_waterflowsectionoption_setcrosscount) | - | Sets the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow section. |
| [int32_t OH_ArkUI_WaterFlowSectionOption_GetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getcrosscount) | - | Obtains the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow section. |
| [void OH_ArkUI_WaterFlowSectionOption_SetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index, float columnGap)](#oh_arkui_waterflowsectionoption_setcolumngap) | - | Sets the gap between columns in the specified water flow section. |
| [float OH_ArkUI_WaterFlowSectionOption_GetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getcolumngap) | - | Obtains the gap between columns in the water flow section that matches the specified index. |
| [void OH_ArkUI_WaterFlowSectionOption_SetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index, float rowGap)](#oh_arkui_waterflowsectionoption_setrowgap) | - | Sets the gap between rows in the specified water flow section. |
| [float OH_ArkUI_WaterFlowSectionOption_GetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getrowgap) | - | Obtains the gap between rows in the water flow section that matches the specified index. |
| [void OH_ArkUI_WaterFlowSectionOption_SetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index, float marginTop, float marginRight, float marginBottom, float marginLeft)](#oh_arkui_waterflowsectionoption_setmargin) | - | Sets the margins for the specified water flow section. |
| [ArkUI_Margin OH_ArkUI_WaterFlowSectionOption_GetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getmargin) | - | Obtains the margins of the water flow section that matches the specified index. |
| [void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex (ArkUI_WaterFlowSectionOption* option, int32_t index, float(\*callback)(int32_t itemIndex))](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindex) | - | Registers a callback for the section at the specified index in the section configuration array to provide the main axis size of **FlowItem**. When **WaterFlow** lays out **FlowItem** in this section, the index of the current **FlowItem** in **WaterFlow** is passed to the callback as **itemIndex**, and the callback return value is used as the main axis size of the **FlowItem**. The main axis size is the height in vertical layout and the width in horizontal layout. To use custom data in the callback, use **OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData**. |
| [void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData (ArkUI_WaterFlowSectionOption* option, int32_t index, void* userData, float (\*callback)(int32_t itemIndex, void* userData))](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindexwithuserdata) | - | Registers a callback for the section at the specified index in the section configuration array to provide the main axis size of **FlowItem** and saves the passed **userData**. When **WaterFlow** lays out **FlowItem** in this section, the index of the current **FlowItem** in **WaterFlow** and **userData** are passed to the callback as the first and second parameters, respectively. **userData** is only used to pass additional data to the callback, and the main axis size of the **FlowItem** is provided by the callback return value. The main axis size is the height in vertical layout and the width in horizontal layout. |

## Enum Description

### ArkUI_WaterFlowLayoutMode

```c
enum ArkUI_WaterFlowLayoutMode
```

**Description**

Enumerates the layout modes of the [WaterFlow](../apis-arkui/arkui-ts/ts-container-waterflow.md) component.

**Since:** 18

| Value | Description |
| -- | -- |
| ARKUI_WATER_FLOW_LAYOUT_MODE_ALWAYS_TOP_DOWN = 0 | Layout from top to bottom. In scenarios where column switching occurs, the layout starts from the first [water flow item](../apis-arkui/arkui-ts/ts-container-flowitem.md) to the currently displayed [water flow item](../apis-arkui/arkui-ts/ts-container-flowitem.md). |
| ARKUI_WATER_FLOW_LAYOUT_MODE_SLIDING_WINDOW = 1 | Sliding window layout. In scenarios where column switching occurs, only the range of [water flow items](../apis-arkui/arkui-ts/ts-container-flowitem.md) currently on display is re-laid out. As the user scrolls down with their finger, [water flow items](../apis-arkui/arkui-ts/ts-container-flowitem.md) that enter the display range from above are subsequently laid out. |

## Function Description

### OH_ArkUI_WaterFlowSectionOption_Create()

```c
ArkUI_WaterFlowSectionOption* OH_ArkUI_WaterFlowSectionOption_Create()
```

**Description**

Creates a [water flow](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration, with an initial array length of 1. Call [OH_ArkUI_WaterFlowSectionOption_Dispose](#oh_arkui_waterflowsectionoption_dispose) to release resources after the use.

**Since:** 12

**Returns**

| Type | Description |
|------|-------------|
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* | Pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration. |

### OH_ArkUI_WaterFlowSectionOption_Dispose()

```c
void OH_ArkUI_WaterFlowSectionOption_Dispose(ArkUI_WaterFlowSectionOption* option)
```

**Description**

Disposes of the pointer to a [water flow](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration created by [OH_ArkUI_WaterFlowSectionOption_Create](#oh_arkui_waterflowsectionoption_create). The pointer must not be accessed after being disposed of.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to the [water flow](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration to dispose of. |

### OH_ArkUI_WaterFlowSectionOption_SetSize()

```c
void OH_ArkUI_WaterFlowSectionOption_SetSize(ArkUI_WaterFlowSectionOption* option, int32_t size)
```

**Description**

Sets the array length of a water flow section configuration. For scaling-out, the original configuration is retained and a new group configuration is added at the end of the array. When scaling-in, the configuration within the new length range is retained and the rest are deleted.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration. |
| int32_t size | Array length. The value range is greater than or equal to 0. No operation is performed when a negative number is passed in. |

### OH_ArkUI_WaterFlowSectionOption_GetSize()

```c
int32_t OH_ArkUI_WaterFlowSectionOption_GetSize(ArkUI_WaterFlowSectionOption* option)
```

**Description**

Obtains the length of the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration array.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration. |

**Returns**

| Type | Description |
| -- | -- |
| int32_t | Array length. **-1** is returned if **option** is a null pointer. |

### OH_ArkUI_WaterFlowSectionOption_SetItemCount()

```c
void OH_ArkUI_WaterFlowSectionOption_SetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index, int32_t itemCount)
```

**Description**

Sets the number of [water flow items](../apis-arkui/arkui-ts/ts-container-flowitem.md) in the section.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration. |
| int32_t index | Index of the section configuration array. The value range is greater than or equal to 0. When the value exceeds the current array length, the array is automatically expanded to **index** + 1. |
| int32_t itemCount | Number of [flow items](../apis-arkui/arkui-ts/ts-container-flowitem.md) in the section. The value range is greater than or equal to 0. No operation is performed when a negative number is passed in. |

### OH_ArkUI_WaterFlowSectionOption_GetItemCount()

```c
int32_t OH_ArkUI_WaterFlowSectionOption_GetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**Description**

Obtains the number of [water flow items](../apis-arkui/arkui-ts/ts-container-flowitem.md) at the corresponding index based on the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration. |
| int32_t index | Index of the section configuration array. The value ranges from 0 to the array length minus 1. |

**Returns**

| Type | Description |
| -- | -- |
| int32_t | Number of flow items in the section. **0** is returned if the value of **index** is greater than or equal to the array length, and **-1** if **option** is a null pointer. |

### OH_ArkUI_WaterFlowSectionOption_SetCrossCount()

```c
void OH_ArkUI_WaterFlowSectionOption_SetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index, int32_t crossCount)
```

**Description**

Sets the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow section.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration. |
| int32_t index | Index of the section configuration array. The value range is greater than or equal to 0. When the value exceeds the current array length, the array is automatically expanded to **index** + 1. |
| int32_t crossCount | Number of layout grids. In vertical layout, it indicates the number of columns; in horizontal layout, it indicates the number of rows. A value less than or equal to 0 is treated as **1**. |

### OH_ArkUI_WaterFlowSectionOption_GetCrossCount()

```c
int32_t OH_ArkUI_WaterFlowSectionOption_GetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**Description**

Obtains the number of layout grids at the corresponding index based on the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration. |
| int32_t index | Index of the section configuration array. The value ranges from 0 to the array length minus 1. |

**Returns**

| Type | Description |
| -- | -- |
| int32_t | Number of layout grid columns. **0** is returned if the value of **index** is greater than or equal to the array length, and **-1** if **option** is a null pointer. |

### OH_ArkUI_WaterFlowSectionOption_SetColumnGap()

```c
void OH_ArkUI_WaterFlowSectionOption_SetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index, float columnGap)
```

**Description**

Sets the gap between columns in the specified water flow section.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration. |
| int32_t index | Index of the section configuration array. The value range is greater than or equal to 0. When the value exceeds the current array length, the array is automatically expanded to **index** + 1. |
| float columnGap | Gap between columns. Unit: vp. If a negative number is passed in, it is treated as 0. |

### OH_ArkUI_WaterFlowSectionOption_GetColumnGap()

```c
float OH_ArkUI_WaterFlowSectionOption_GetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**Description**

Obtains the gap between columns in the water flow section that matches the specified index.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration. |
| int32_t index | Index of the section configuration array. The value ranges from 0 to the array length minus 1. |

**Returns**

| Type | Description |
| -- | -- |
| float | Gap between columns. The unit is vp. |

### OH_ArkUI_WaterFlowSectionOption_SetRowGap()

```c
void OH_ArkUI_WaterFlowSectionOption_SetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index, float rowGap)
```

**Description**

Sets the row spacing for the specified group.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration. |
| int32_t index | Index of the section configuration array. The value range is greater than or equal to 0. When the value exceeds the current array length, the array is automatically expanded to **index** + 1. |
| float rowGap | Gap between rows. Unit: vp. If a negative number is passed in, it is treated as **0**. |

### OH_ArkUI_WaterFlowSectionOption_GetRowGap()

```c
float OH_ArkUI_WaterFlowSectionOption_GetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**Description**

Obtains the gap between rows in the section at the corresponding index based on the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration. |
| int32_t index | Index of the section configuration array. The value ranges from 0 to the array length minus 1. |

**Returns**

| Type | Description |
| -- | -- |
| float | Gap between rows. The unit is vp. |

### OH_ArkUI_WaterFlowSectionOption_SetMargin()

```c
void OH_ArkUI_WaterFlowSectionOption_SetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index, float marginTop, float marginRight, float marginBottom, float marginLeft)
```

**Description**

Sets the margins for the specified water flow section.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration. |
| int32_t index | Index of the section configuration array. The value range is greater than or equal to 0. When the value exceeds the current array length, the array is automatically expanded to **index** + 1. |
| float marginTop | Top margin of [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md). Unit: vp. |
| float marginRight | Right margin of [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md). Unit: vp. |
| float marginBottom | Bottom margin of [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md). Unit: vp. |
| float marginLeft | Left margin of [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md). Unit: vp. |

### OH_ArkUI_WaterFlowSectionOption_GetMargin()

```c
ArkUI_Margin OH_ArkUI_WaterFlowSectionOption_GetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**Description**

Obtains the margins of the section at the corresponding index based on the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration. |
| int32_t index | Index of the section configuration array. The value ranges from 0 to the array length minus 1. |

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_Margin](capi-arkui-nativemodule-arkui-margin.md) | Margin. The unit is vp. |

### OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex()

```c
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex(ArkUI_WaterFlowSectionOption* option, int32_t index, float(*callback)(int32_t itemIndex))
```

**Description**

Registers a callback for the section at the specified index in the section configuration array to provide the main axis size of [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md). When **WaterFlow** lays out **FlowItem** in this section, the index of the current **FlowItem** in **WaterFlow** is passed to the callback as **itemIndex**, and the callback return value is used as the main axis size of the **FlowItem**. The main axis size is the height in vertical layout and the width in horizontal layout. To use custom data in the callback, use [OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindexwithuserdata).

**Since:** 12

**Parameters**

| Name | Description |
|------------------------------------------------| -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration. |
| int32_t index | Index of the section configuration array for which the callback is to be registered. The value range is 0 to the array length minus 1. |
| float (*callback)(int32_t itemIndex) | Callback used to return the main axis size. **itemIndex** indicates the index of the current [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) in **WaterFlow**. You can provide the main axis size of the **FlowItem** through the return value, in vp. A negative return value is treated as **0**. |

### OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData()

```c
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData(ArkUI_WaterFlowSectionOption* option, int32_t index, void* userData, float (*callback)(int32_t itemIndex, void* userData))
```

**Description**

Registers a callback for the section at the specified index in the section configuration array to provide the main axis size of [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) and saves the passed **userData**. When **WaterFlow** lays out **FlowItem** in this section, the index of the current **FlowItem** in **WaterFlow** and **userData** are passed to the callback as the first and second parameters, respectively. **userData** is only used to pass additional data to the callback, and the main axis size of the **FlowItem** is provided by the callback return value. The main axis size is the height in vertical layout and the width in horizontal layout.

**Since:** 12

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration. |
| int32_t index | Index of the section configuration array for which the callback is to be registered. The value range is 0 to the array length minus 1. |
| void* userData | Pointer to the additional data passed to the callback. It does not directly represent the main axis size of the **FlowItem**. During **WaterFlow** layout, this parameter is passed as the second parameter of the callback. This pointer is managed by the caller and must remain valid while the callback may be triggered. |
| float (*callback)(int32_t itemIndex, void* userData) | Callback used to return the main axis size. **itemIndex** indicates the index of the current [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) in the **WaterFlow**. **userData** indicates the user-defined data passed to the API. You can provide the main axis size of the **FlowItem** through the return value, in vp. A negative return value is treated as **0**. |