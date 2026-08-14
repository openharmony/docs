# grid.h

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @rongShao-Z; @guozejun-->
<!--Designer: @guozejun-->
<!--Tester: @leiyuqian-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=e4da1f59f2bfae1b45300542e10b9243ddb9c5c2 translatedAt=2026-08-11T09:09:02.359Z pushedAt=2026-08-12T07:41:43.691Z -->

## Overview

Defines enumerations and APIs related to **Grid**.

**File to include:** <arkui/node_attributes/grid.h>

**Library:** libace_ndk.z.so

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Since:** 22

**Related module:** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Sample:** <!--RP1-->[NDKGridSample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NDKGridSample)<!--RP1End-->

## Summary

### Structs

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_GridItemSize](capi-arkui-nativemodule-arkui-griditemsize.md) | ArkUI_GridItemSize | Defines the return value for the **onGetIrregularSizeByIndex** callback in **Grid** layout options. |
| [ArkUI_GridItemRect](capi-arkui-nativemodule-arkui-griditemrect.md) | ArkUI_GridItemRect | Defines the return value for the **onGetRectByIndex** callback in **Grid** layout options. |
| [ArkUI_GridLayoutOptions](capi-arkui-nativemodule-arkui-gridlayoutoptions.md) | ArkUI_GridLayoutOptions | Defines the **Grid** layout options, which are used to set the layout parameters of irregular grid items in the **Grid** component, including the irregular item index and layout callback. An irregular grid item refers to a grid item that spans across rows and columns or has a different size in the grid layout. |

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_GridItemAlignment](#arkui_griditemalignment) | ArkUI_GridItemAlignment | Enumerates the alignment modes of the [GridItem](../apis-arkui/arkui-ts/ts-container-griditem.md) component. |
| [ArkUI_GridItemStyle](#arkui_griditemstyle) | ArkUI_GridItemStyle | Enumerates styles of grid items. |

### Functions

| Name | Description |
| -- | -- |
| [ArkUI_GridLayoutOptions* OH_ArkUI_GridLayoutOptions_Create()](#oh_arkui_gridlayoutoptions_create) | Creates **Grid** layout options. Call **OH_ArkUI_GridLayoutOptions_Dispose** to destroy it after use. |
| [void OH_ArkUI_GridLayoutOptions_Dispose(ArkUI_GridLayoutOptions* option)](#oh_arkui_gridlayoutoptions_dispose) | Disposes of the **Grid** layout options to release resources. |
| [int32_t OH_ArkUI_GridLayoutOptions_SetIrregularIndexes(ArkUI_GridLayoutOptions* option, uint32_t* irregularIndexes, int32_t size)](#oh_arkui_gridlayoutoptions_setirregularindexes) | Sets the irregular grid item index array for the grid layout. |
| [int32_t OH_ArkUI_GridLayoutOptions_GetIrregularIndexes(ArkUI_GridLayoutOptions* option, uint32_t* irregularIndexes, int32_t* size)](#oh_arkui_gridlayoutoptions_getirregularindexes) | Obtains the irregular grid item index array for the grid layout. When **OH_ArkUI_GridLayoutOptions_RegisterGetIrregularSizeByIndexCallback** is not set, the grid item specified in this parameter occupies an entire row of the grid that scrolls vertically or an entire column of the grid that scrolls horizontally. |
| [void OH_ArkUI_GridLayoutOptions_RegisterGetIrregularSizeByIndexCallback(ArkUI_GridLayoutOptions* option, void* userData, ArkUI_GridItemSize(\*callback)(int32_t itemIndex, void* userData))](#oh_arkui_gridlayoutoptions_registergetirregularsizebyindexcallback) | Registers a callback to obtain the row and column span for the grid item at the specified index. |
| [void OH_ArkUI_GridLayoutOptions_RegisterGetRectByIndexCallback(ArkUI_GridLayoutOptions* option, void* userData, ArkUI_GridItemRect (\*callback)(int32_t itemIndex, void* userData))](#oh_arkui_gridlayoutoptions_registergetrectbyindexcallback) | Registers a callback to obtain the starting row, starting column, row span, and column span for the grid item at the specified index. |

## Enum Description

### ArkUI_GridItemAlignment

```c
enum ArkUI_GridItemAlignment
```

**Description**

Enumerates the alignment modes of the [GridItem](../apis-arkui/arkui-ts/ts-container-griditem.md) component.

**Since:** 22

| Value | Description |
| -- | -- |
| GRID_ITEM_ALIGNMENT_DEFAULT = 0 | Use the default alignment mode of the grid. |
| GRID_ITEM_ALIGNMENT_STRETCH  = 1  | Use the height of the tallest grid item in a row as the height for all other grid items in that row. |

### ArkUI_GridItemStyle

```c
enum ArkUI_GridItemStyle
```

**Description**

Enumerates styles of grid items.

**Since:** 22

| Value | Description |
| -- | -- |
| GRID_ITEM_STYLE_NONE  = 0 | No style. |
| GRID_ITEM_STYLE_PLAIN  = 1  | Hover or press style. |

## Function Description

### OH_ArkUI_GridLayoutOptions_Create()

```c
ArkUI_GridLayoutOptions* OH_ArkUI_GridLayoutOptions_Create()
```

**Description**

Creates **Grid** layout options. Call **OH_ArkUI_GridLayoutOptions_Dispose** to dispose of it after use.

**Since:** 22

**Returns**

| Type | Description |
|-----------------------------------| -- |
| [ArkUI_GridLayoutOptions](capi-arkui-nativemodule-arkui-gridlayoutoptions.md)* | Pointer to the created **Grid** layout option array. |

### OH_ArkUI_GridLayoutOptions_Dispose()

```c
void OH_ArkUI_GridLayoutOptions_Dispose(ArkUI_GridLayoutOptions* option)
```

**Description**

Disposes of the **Grid** layout options to release resources.

**Since:** 22

**Parameters**

| Parameter Item | Description |
| -- | -- |
| [ArkUI_GridLayoutOptions](capi-arkui-nativemodule-arkui-gridlayoutoptions.md)* option | Pointer to the **Grid** layout option array to dispose of. |

### OH_ArkUI_GridLayoutOptions_SetIrregularIndexes()

```c
int32_t OH_ArkUI_GridLayoutOptions_SetIrregularIndexes(ArkUI_GridLayoutOptions* option, uint32_t* irregularIndexes, int32_t size)
```

**Description**

Sets the irregular grid item index array for the grid layout.

**Since:** 22

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_GridLayoutOptions](capi-arkui-nativemodule-arkui-gridlayoutoptions.md)* option | Pointer to the **Grid** layout option array to set. |
| uint32_t* irregularIndexes | Pointer to the array of irregular grid item indexes used to set the **Grid** layout options. |
| int32_t size | Number of elements in the **irregularIndexes** array. |

**Returns**

| Type | Description |
| -- | -- |
| int32_t | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.<br> A possible cause is that mandatory parameters are left unspecified. |

### OH_ArkUI_GridLayoutOptions_GetIrregularIndexes()

```c
int32_t OH_ArkUI_GridLayoutOptions_GetIrregularIndexes(ArkUI_GridLayoutOptions* option, uint32_t* irregularIndexes, int32_t* size)
```

**Description**

Obtains the irregular grid item index array for the grid layout. When **OH_ArkUI_GridLayoutOptions_RegisterGetIrregularSizeByIndexCallback** is not set, the grid item specified in this parameter occupies an entire row of the grid that scrolls vertically or an entire column of the grid that scrolls horizontally.

**Since:** 22

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_GridLayoutOptions](capi-arkui-nativemodule-arkui-gridlayoutoptions.md)* option | Pointer to the **Grid** layout option array to be obtained. |
| uint32_t* irregularIndexes | Pointer to the buffer for receiving the irregular grid item index array. |
| int32_t* size | Pointer to the number of elements that the **irregularIndexes** buffer can hold. Pass the buffer capacity before calling, and it will be updated to the actual number of indexes actually written after a successful call. |

**Returns**

| Type | Description |
| -- | -- |
| int32_t | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.<br> Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the array size is insufficient.<br> A possible cause is that mandatory parameters are left unspecified. |

### OH_ArkUI_GridLayoutOptions_RegisterGetIrregularSizeByIndexCallback()

```c
void OH_ArkUI_GridLayoutOptions_RegisterGetIrregularSizeByIndexCallback(ArkUI_GridLayoutOptions* option, void* userData, ArkUI_GridItemSize (*callback)(int32_t itemIndex, void* userData))
```

**Description**

Registers a callback to obtain the row and column span for the grid item at the specified index.

**Since:** 22

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_GridLayoutOptions](capi-arkui-nativemodule-arkui-gridlayoutoptions.md)* option | Pointer to the **Grid** layout option array. |
| void* userData | Pointer to the user-defined data. |
| [ArkUI_GridItemSize](capi-arkui-nativemodule-arkui-griditemsize.md) (\*callback)(int32_t itemIndex, void* userData) | Pointer to the callback used to obtain the row and column count occupied by a specified item based on the index.<br> **itemIndex**: grid item index, with the value range from [OH_ArkUI_GridLayoutOptions_SetIrregularIndexes](#oh_arkui_gridlayoutoptions_setirregularindexes). |

### OH_ArkUI_GridLayoutOptions_RegisterGetRectByIndexCallback()

```c
void OH_ArkUI_GridLayoutOptions_RegisterGetRectByIndexCallback(ArkUI_GridLayoutOptions* option, void* userData, ArkUI_GridItemRect (*callback)(int32_t itemIndex, void* userData))
```

**Description**

Registers a callback to obtain the starting row, starting column, row span, and column span for the grid item at the specified index.

**Since:** 22

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_GridLayoutOptions](capi-arkui-nativemodule-arkui-gridlayoutoptions.md)* option | Pointer to the **Grid** layout option array. |
| void* userData | Pointer to the user-defined data. |
| [ArkUI_GridItemRect](capi-arkui-nativemodule-arkui-griditemrect.md) (\*callback)(int32_t itemIndex, void* userData) | Pointer to the callback used to obtain the start row and column and the occupied row and column count of the specified item based on the index.<br> **itemIndex**: grid item index. |