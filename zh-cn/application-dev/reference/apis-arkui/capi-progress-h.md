# progress.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @Zhang-Dong-hui-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

定义Progress相关的枚举和接口，支持线性、环形、圆形、胶囊等多种进度条类型，并提供线性进度条样式选项的自定义能力（平滑动效、扫光效果、宽度、圆角），适用于需要展示任务进度、加载状态等场景，帮助开发者快速实现多样化的进度展示和交互反馈。

**引用文件：** <arkui/node_attributes/progress.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**相关示例：** <!--RP1-->[native_type_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/native_type_sample)<!--RP1End-->

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md) | ArkUI_ProgressLinearStyleOption | 定义线性进度条的样式选项，适用于需要自定义线性进度条显示样式的场景。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_ProgressType](#arkui_progresstype) | ArkUI_ProgressType | 定义进度条类型枚举值。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption* OH_ArkUI_ProgressLinearStyleOption_Create(void)](#oh_arkui_progresslinearstyleoption_create) | 创建线性进度条样式信息。使用完毕后必须调用[OH_ArkUI_ProgressLinearStyleOption_Destroy](#oh_arkui_progresslinearstyleoption_destroy)释放资源，避免内存泄漏。 |
| [void OH_ArkUI_ProgressLinearStyleOption_Destroy(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_destroy) | 销毁线性进度条样式信息。必须与[OH_ArkUI_ProgressLinearStyleOption_Create](#oh_arkui_progresslinearstyleoption_create)配对使用，参数option应通过Create()获取，调用Destroy()后不应再使用该对象。 |
| [void OH_ArkUI_ProgressLinearStyleOption_SetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)](#oh_arkui_progresslinearstyleoption_setsmootheffectenabled) | 设置进度平滑动效的开关。 |
| [void OH_ArkUI_ProgressLinearStyleOption_SetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)](#oh_arkui_progresslinearstyleoption_setscaneffectenabled) | 设置扫光效果的开关。适用于需要增强进度条视觉反馈效果的加载场景，如数据加载、文件上传等。扫光效果指进度条上有光线扫描移动的动态视觉效果。 |
| [void OH_ArkUI_ProgressLinearStyleOption_SetStrokeWidth(ArkUI_ProgressLinearStyleOption* option, float strokeWidth)](#oh_arkui_progresslinearstyleoption_setstrokewidth) | 设置进度条宽度。 |
| [void OH_ArkUI_ProgressLinearStyleOption_SetStrokeRadius(ArkUI_ProgressLinearStyleOption* option, float strokeRadius)](#oh_arkui_progresslinearstyleoption_setstrokeradius) | 设置进度条圆角半径。 |
| [bool OH_ArkUI_ProgressLinearStyleOption_GetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getsmootheffectenabled) | 获取进度平滑动效的开关信息。 |
| [bool OH_ArkUI_ProgressLinearStyleOption_GetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getscaneffectenabled) | 获取扫光效果的开关信息。 |
| [float OH_ArkUI_ProgressLinearStyleOption_GetStrokeWidth(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getstrokewidth) | 获取进度条宽度。 |
| [float OH_ArkUI_ProgressLinearStyleOption_GetStrokeRadius(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getstrokeradius) | 获取进度条圆角半径值。 |

## 枚举类型说明

### ArkUI_ProgressType

```c
enum ArkUI_ProgressType
```

**描述**

定义进度条类型枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_PROGRESS_TYPE_LINEAR = 0 | 线性样式。 |
| ARKUI_PROGRESS_TYPE_RING = 1 | 环形无刻度样式，环形圆环逐渐显示直至完全填充。 |
| ARKUI_PROGRESS_TYPE_ECLIPSE = 2 | 圆形样式，显示类似月圆月缺的进度展示效果，从月牙逐渐变化至满月。 |
| ARKUI_PROGRESS_TYPE_SCALE_RING = 3 | 环形有刻度样式，显示类似时钟刻度形式的进度展示效果。 |
| ARKUI_PROGRESS_TYPE_CAPSULE = 4 | 胶囊样式，头尾两端圆弧处的进度展示效果与ARKUI_PROGRESS_TYPE_ECLIPSE相同，中段的进度展示效果与ARKUI_PROGRESS_TYPE_LINEAR相同。 |


## 函数说明

### OH_ArkUI_ProgressLinearStyleOption_Create()

```c
ArkUI_ProgressLinearStyleOption* OH_ArkUI_ProgressLinearStyleOption_Create(void)
```

**描述**

创建线性进度条样式信息。使用完毕后必须调用[OH_ArkUI_ProgressLinearStyleOption_Destroy](#oh_arkui_progresslinearstyleoption_destroy)释放资源，避免内存泄漏。

**起始版本：** 15

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption*](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md) | ArkUI_ProgressLinearStyleOption实例，可用于配置线性进度条的平滑动效、扫光效果、宽度和圆角等显示样式。<br>如果返回空指针，可能是因为内存不足。 |

### OH_ArkUI_ProgressLinearStyleOption_Destroy()

```c
void OH_ArkUI_ProgressLinearStyleOption_Destroy(ArkUI_ProgressLinearStyleOption* option)
```

**描述**

销毁线性进度条样式信息。必须与[OH_ArkUI_ProgressLinearStyleOption_Create](#oh_arkui_progresslinearstyleoption_create)配对使用，参数option应通过Create()获取，调用Destroy()后不应再使用该对象。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。应通过OH_ArkUI_ProgressLinearStyleOption_Create()获取。 |

### OH_ArkUI_ProgressLinearStyleOption_SetSmoothEffectEnabled()

```c
void OH_ArkUI_ProgressLinearStyleOption_SetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)
```

**描述**

设置进度平滑动效的开关。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。应通过OH_ArkUI_ProgressLinearStyleOption_Create()创建。 |
| bool enabled | 进度平滑动效的开关。开启平滑动效后设置进度，进度会从当前值渐变至设定值，否则进度从当前值突变至设定值。<br>true：表示开启进度平滑动效。<br>false：表示关闭进度平滑动效。<br>默认值：true。 |

### OH_ArkUI_ProgressLinearStyleOption_SetScanEffectEnabled()

```c
void OH_ArkUI_ProgressLinearStyleOption_SetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)
```

**描述**

设置扫光效果的开关。适用于需要增强进度条视觉反馈效果的加载场景，如数据加载、文件上传等。扫光效果指进度条上有光线扫描移动的动态视觉效果。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。应通过OH_ArkUI_ProgressLinearStyleOption_Create()创建。 |
| bool enabled | 扫光效果的开关。<br>true：表示开启扫光效果。<br>false：表示关闭扫光效果。<br>默认值：false。 |

### OH_ArkUI_ProgressLinearStyleOption_SetStrokeWidth()

```c
void OH_ArkUI_ProgressLinearStyleOption_SetStrokeWidth(ArkUI_ProgressLinearStyleOption* option, float strokeWidth)
```

**描述**

设置进度条宽度。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。应通过OH_ArkUI_ProgressLinearStyleOption_Create()创建。 |
| float strokeWidth | 进度条宽度值（不支持百分比设置），单位为vp，取值需大于0，传入不合法值时使用默认值。默认值：4.0vp。设置strokeWidth会影响strokeRadius的取值范围，strokeRadius取值范围为[0, strokeWidth/2]。 |

### OH_ArkUI_ProgressLinearStyleOption_SetStrokeRadius()

```c
void OH_ArkUI_ProgressLinearStyleOption_SetStrokeRadius(ArkUI_ProgressLinearStyleOption* option, float strokeRadius)
```

**描述**

设置进度条圆角半径。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。应通过OH_ArkUI_ProgressLinearStyleOption_Create()创建。 |
| float strokeRadius | 进度条圆角半径值，单位为vp，取值范围[0, strokeWidth/2]。值为0时进度条显示直角，值越大圆角越明显，最大值时显示为完全圆角。超出范围时自动修正为边界值。默认值：strokeWidth/2。 |

### OH_ArkUI_ProgressLinearStyleOption_GetSmoothEffectEnabled()

```c
bool OH_ArkUI_ProgressLinearStyleOption_GetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option)
```

**描述**

获取进度平滑动效的开关信息。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。应通过OH_ArkUI_ProgressLinearStyleOption_Create()创建。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 是否开启平滑动效。true：表示开启进度平滑动效。false：表示关闭进度平滑动效。默认值：true。 |

### OH_ArkUI_ProgressLinearStyleOption_GetScanEffectEnabled()

```c
bool OH_ArkUI_ProgressLinearStyleOption_GetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option)
```

**描述**

获取扫光效果的开关信息。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。应通过OH_ArkUI_ProgressLinearStyleOption_Create()创建。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 是否开启扫光效果。true：表示开启扫光效果。false：表示关闭扫光效果。默认值：false。 |

### OH_ArkUI_ProgressLinearStyleOption_GetStrokeWidth()

```c
float OH_ArkUI_ProgressLinearStyleOption_GetStrokeWidth(ArkUI_ProgressLinearStyleOption* option)
```

**描述**

获取进度条宽度。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。应通过OH_ArkUI_ProgressLinearStyleOption_Create()创建。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 进度条宽度值，单位为vp。 |

### OH_ArkUI_ProgressLinearStyleOption_GetStrokeRadius()

```c
float OH_ArkUI_ProgressLinearStyleOption_GetStrokeRadius(ArkUI_ProgressLinearStyleOption* option)
```

**描述**

获取进度条圆角半径值。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。应通过OH_ArkUI_ProgressLinearStyleOption_Create()创建。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 进度条圆角半径值，单位为vp。 |


