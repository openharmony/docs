# progress.h

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @Zhang-Dong-hui-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=f591a4e488f57c0e85bc666bbc867ec6b4d2ed64 translatedAt=2026-08-11T09:10:14.866Z pushedAt=2026-08-12T04:19:51.518Z -->

## Overview

Defines enumerations and APIs related to **Progress**, supporting multiple progress indicator types such as linear, ring, eclipse, and capsule, and providing customization capabilities for linear progress indicator style options (smooth animation, scan effect, width, and corner radius). It is suitable for scenarios such as displaying task progress and loading states, helping you quickly implement diverse progress displays and interactive feedback.

**File to include:** <arkui/node_attributes/progress.h>

**Library:** libace_ndk.z.so

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Since:** 12

**Related module:** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Sample:** <!--RP1-->[native_type_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/native_type_sample)<!--RP1End-->

## Summary

### Structs

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md) | ArkUI_ProgressLinearStyleOption | Defines linear progress indicator style options, suitable for scenarios where the display style of a linear progress indicator needs to be customized. |

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [ArkUI_ProgressType](#arkui_progresstype) | ArkUI_ProgressType | Enumerates progress indicator types. |

### Functions

| Name | Description |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption* OH_ArkUI_ProgressLinearStyleOption_Create(void)](#oh_arkui_progresslinearstyleoption_create) | Creates a **ProgressLinearStyleOption** instance. After use, you must call [OH_ArkUI_ProgressLinearStyleOption_Destroy](#oh_arkui_progresslinearstyleoption_destroy) to release resources and avoid memory leaks. |
| [void OH_ArkUI_ProgressLinearStyleOption_Destroy(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_destroy) | Destroys a **ProgressLinearStyleOption** instance. This API must be used in pair with [OH_ArkUI_ProgressLinearStyleOption_Create](#oh_arkui_progresslinearstyleoption_create). The **option** parameter should be obtained through **OH_ArkUI_ProgressLinearStyleOption_Create()**, and the object should not be used after **OH_ArkUI_ProgressLinearStyleOption_Destroy()** is called. |
| [void OH_ArkUI_ProgressLinearStyleOption_SetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)](#oh_arkui_progresslinearstyleoption_setsmootheffectenabled) | Sets whether to enable the smooth effect. |
| [void OH_ArkUI_ProgressLinearStyleOption_SetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)](#oh_arkui_progresslinearstyleoption_setscaneffectenabled) | Sets whether to enable the scan effect. This API is applicable to loading scenarios that require enhanced visual feedback of the progress indicator, such as data loading and file upload. The scan effect refers to the dynamic visual effect of a light beam scanning across the progress indicator. |
| [void OH_ArkUI_ProgressLinearStyleOption_SetStrokeWidth(ArkUI_ProgressLinearStyleOption* option, float strokeWidth)](#oh_arkui_progresslinearstyleoption_setstrokewidth) | Sets the stroke width for a progress indicator. |
| [void OH_ArkUI_ProgressLinearStyleOption_SetStrokeRadius(ArkUI_ProgressLinearStyleOption* option, float strokeRadius)](#oh_arkui_progresslinearstyleoption_setstrokeradius) | Sets the corner radius for a progress indicator. |
| [bool OH_ArkUI_ProgressLinearStyleOption_GetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getsmootheffectenabled) | Obtains the enabled status of the smooth effect. |
| [bool OH_ArkUI_ProgressLinearStyleOption_GetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getscaneffectenabled) | Obtains the enabled status of the scan effect. |
| [float OH_ArkUI_ProgressLinearStyleOption_GetStrokeWidth(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getstrokewidth) | Obtains the stroke width of the progress indicator. |
| [float OH_ArkUI_ProgressLinearStyleOption_GetStrokeRadius(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getstrokeradius) | Obtains the corner radius of the progress indicator. |

## Enum Description

### ArkUI_ProgressType

```c
enum ArkUI_ProgressType
```

**Description**

Enumerates progress indicator types.

**Since:** 12

| Value | Description |
| -- | -- |
| ARKUI_PROGRESS_TYPE_LINEAR = 0 | Linear style. |
| ARKUI_PROGRESS_TYPE_RING = 1 | Ring type without scale marks. The ring gradually displays until fully filled. |
| ARKUI_PROGRESS_TYPE_ECLIPSE = 2 | Eclipse type that displays a moon phase-like progress effect, gradually changing from a crescent to a full moon. |
| ARKUI_PROGRESS_TYPE_SCALE_RING = 3 | Ring type with scale marks, which displays a clock-like progress effect. |
| ARKUI_PROGRESS_TYPE_CAPSULE = 4 | Capsule type. The progress effect at both rounded ends is the same as **ARKUI_PROGRESS_TYPE_ECLIPSE**, and the progress effect in the middle section is the same as **ARKUI_PROGRESS_TYPE_LINEAR**. |

## Function Description

### OH_ArkUI_ProgressLinearStyleOption_Create()

```c
ArkUI_ProgressLinearStyleOption* OH_ArkUI_ProgressLinearStyleOption_Create(void)
```

**Description**

Creates a **ProgressLinearStyleOption** instance. After use, you must call [OH_ArkUI_ProgressLinearStyleOption_Destroy](#oh_arkui_progresslinearstyleoption_destroy) to release resources to avoid memory leaks.

**Since:** 15

**Returns**

| Type | Description |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption*](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md) | Pointer to the **ArkUI_ProgressLinearStyleOption** instance, which can be used to configure display styles such as smooth animation, scan effect, width, and corner radius of a linear progress indicator.<br>If a null pointer is returned, the memory may be insufficient. |

### OH_ArkUI_ProgressLinearStyleOption_Destroy()

```c
void OH_ArkUI_ProgressLinearStyleOption_Destroy(ArkUI_ProgressLinearStyleOption* option)
```

**Description**

Destroys a **ProgressLinearStyleOption** instance. This API must be used in pair with [OH_ArkUI_ProgressLinearStyleOption_Create](#oh_arkui_progresslinearstyleoption_create). The **option** parameter should be obtained through **OH_ArkUI_ProgressLinearStyleOption_Create()**, and the object should not be used after **OH_ArkUI_ProgressLinearStyleOption_Destroy()** is called.

**Since:** 15

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to the **ProgressLinearStyleOption** instance, which is obtained through **OH_ArkUI_ProgressLinearStyleOption_Create()**. |

### OH_ArkUI_ProgressLinearStyleOption_SetSmoothEffectEnabled()

```c
void OH_ArkUI_ProgressLinearStyleOption_SetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)
```

**Description**

Sets whether to enable the smooth effect.

**Since:** 15

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to the **ProgressLinearStyleOption** instance. It should be created using **OH_ArkUI_ProgressLinearStyleOption_Create()**. |
| bool enabled | Whether to enable the smooth effect. When this effect is enabled, the progress changes smoothly from the current value to the target value. When this effect is disabled, the progress changes abruptly to the target value.<br>**true**: Enable the smooth effect.<br>**false**: Disable the smooth effect.<br>Default value: **true**. |

### OH_ArkUI_ProgressLinearStyleOption_SetScanEffectEnabled()

```c
void OH_ArkUI_ProgressLinearStyleOption_SetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)
```

**Description**

Sets whether to enable the scan effect. It is suitable for loading scenarios that require enhanced visual feedback of the progress indicator, such as data loading and file upload. The scan effect refers to the dynamic visual effect of a light beam scanning across the progress indicator.

**Since:** 15

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to the **ProgressLinearStyleOption** instance. It should be created using **OH_ArkUI_ProgressLinearStyleOption_Create()**. |
| bool enabled | Whether to enable the scan effect.<br>**true**: Enable the scan effect.<br>**false**: Disable the scan effect.<br>Default value: **false**. |

### OH_ArkUI_ProgressLinearStyleOption_SetStrokeWidth()

```c
void OH_ArkUI_ProgressLinearStyleOption_SetStrokeWidth(ArkUI_ProgressLinearStyleOption* option, float strokeWidth)
```

**Description**

Sets the stroke width for a progress indicator.

**Since:** 15

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to the **ProgressLinearStyleOption** instance. It should be created using **OH_ArkUI_ProgressLinearStyleOption_Create()**. |
| float strokeWidth | Stroke width of the progress indicator, in vp. Percentage values are not supported. The value must be greater than 0. If an invalid value is passed, the default value is used. Default value: **4.0vp**. Setting **strokeWidth** affects the value range of **strokeRadius**, which is [0, strokeWidth/2]. |

### OH_ArkUI_ProgressLinearStyleOption_SetStrokeRadius()

```c
void OH_ArkUI_ProgressLinearStyleOption_SetStrokeRadius(ArkUI_ProgressLinearStyleOption* option, float strokeRadius)
```

**Description**

Sets the corner radius for a progress indicator.

**Since:** 15

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to the **ProgressLinearStyleOption** instance. It should be created using **OH_ArkUI_ProgressLinearStyleOption_Create()**. |
| float strokeRadius | Corner radius of the progress indicator, in vp. The value range is [0, strokeWidth/2]. The value **0** indicates a right-angle corner. A larger value indicates a more obvious corner radius effect. The maximum value indicates a fully rounded corner. If the value is out of range, it is automatically corrected to the boundary value. Default value: **strokeWidth/2**. |

### OH_ArkUI_ProgressLinearStyleOption_GetSmoothEffectEnabled()

```c
bool OH_ArkUI_ProgressLinearStyleOption_GetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option)
```

**Description**

Obtains the enabled status of the smooth effect.

**Since:** 15

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to the **ProgressLinearStyleOption** instance. It should be created using **OH_ArkUI_ProgressLinearStyleOption_Create()**. |

**Returns**

| Type | Description |
| -- | -- |
| bool | Whether the smooth effect is enabled. **true**: The smooth effect is enabled. **false**: The smooth effect is disabled. The default value is **true**. |

### OH_ArkUI_ProgressLinearStyleOption_GetScanEffectEnabled()

```c
bool OH_ArkUI_ProgressLinearStyleOption_GetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option)
```

**Description**

Obtains the enabled status of the scan effect.

**Since:** 15

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to the **ProgressLinearStyleOption** instance. It should be created using **OH_ArkUI_ProgressLinearStyleOption_Create()**. |

**Returns**

| Type | Description |
| -- | -- |
| bool | Whether the scan effect is enabled. **true**: The scan effect is enabled. **false**: The scan effect is disabled. The default value is **false**. |

### OH_ArkUI_ProgressLinearStyleOption_GetStrokeWidth()

```c
float OH_ArkUI_ProgressLinearStyleOption_GetStrokeWidth(ArkUI_ProgressLinearStyleOption* option)
```

**Description**

Obtains the stroke width of the progress indicator.

**Since:** 15

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to the **ProgressLinearStyleOption** instance. It should be created using **OH_ArkUI_ProgressLinearStyleOption_Create()**. |

**Returns**

| Type | Description |
| -- | -- |
| float | Stroke width of the progress indicator, in vp. |

### OH_ArkUI_ProgressLinearStyleOption_GetStrokeRadius()

```c
float OH_ArkUI_ProgressLinearStyleOption_GetStrokeRadius(ArkUI_ProgressLinearStyleOption* option)
```

**Description**

Obtains the corner radius of the progress indicator.

**Since:** 15

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to the **ProgressLinearStyleOption** instance. It should be created using **OH_ArkUI_ProgressLinearStyleOption_Create()**. |

**Returns**

| Type | Description |
| -- | -- |
| float | Corner radius of the progress indicator, in vp. |