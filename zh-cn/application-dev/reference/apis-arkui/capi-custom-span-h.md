# custom_span.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @Zhang-Dong-hui-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

定义CustomSpan相关的结构体和接口，用于实现自定义绘制Span的精确尺寸测量、布局排版和绘制效果。支持开发者在富文本编辑器、聊天应用、文档应用等场景中实现图文混排、表情内嵌、自定义标记等功能，提供灵活的自定义绘制Span能力，帮助开发者提升开发效率，实现更丰富的文本排版效果。

**引用文件：** <arkui/node_attributes/custom_span.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**相关示例：** <!--RP1-->[native_type_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/native_type_sample)<!--RP1End-->

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_CustomSpanMeasureInfo](capi-arkui-nativemodule-arkui-customspanmeasureinfo.md) | ArkUI_CustomSpanMeasureInfo | 自定义绘制Span的测量信息。该结构体用于在自定义绘制Span的测量回调中提供组件的测量数据，帮助开发者实现自定义文本组件的精确尺寸测量与布局排版。 |
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md) | ArkUI_CustomSpanMetrics | 自定义绘制Span的度量指标，用于设置组件的宽高等布局信息。适用于富文本编辑器、聊天应用等场景的图文混排。 |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md) | ArkUI_CustomSpanDrawInfo | 自定义绘制Span的绘制信息，用于在该组件的绘制回调中向开发者传递绘制信息，开发者可在自定义绘制流程中获取并使用该信息，实现定制化的段落组件绘制效果。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanMeasureInfo* OH_ArkUI_CustomSpanMeasureInfo_Create(void)](#oh_arkui_customspanmeasureinfo_create) | 创建自定义绘制Span测量信息。 |
| [void OH_ArkUI_CustomSpanMeasureInfo_Dispose(ArkUI_CustomSpanMeasureInfo* info)](#oh_arkui_customspanmeasureinfo_dispose) | 销毁自定义绘制Span测量信息。 |
| [float OH_ArkUI_CustomSpanMeasureInfo_GetFontSize(ArkUI_CustomSpanMeasureInfo* info)](#oh_arkui_customspanmeasureinfo_getfontsize) | 获取自定义绘制Span的父节点Text的字体大小。 |
| [ArkUI_CustomSpanMetrics* OH_ArkUI_CustomSpanMetrics_Create(void)](#oh_arkui_customspanmetrics_create) | 创建自定义绘制Span度量信息。 |
| [void OH_ArkUI_CustomSpanMetrics_Dispose(ArkUI_CustomSpanMetrics* metrics)](#oh_arkui_customspanmetrics_dispose) | 销毁自定义绘制Span度量信息。 |
| [int32_t OH_ArkUI_CustomSpanMetrics_SetWidth(ArkUI_CustomSpanMetrics* metrics, float width)](#oh_arkui_customspanmetrics_setwidth) | 设置自定义绘制Span的宽度。在图文混排场景中，需要为嵌入的图片或表情设置合适的宽度以匹配文本行高；在文档应用中，可能需要为自定义标记元素设置固定宽度。 |
| [int32_t OH_ArkUI_CustomSpanMetrics_SetHeight(ArkUI_CustomSpanMetrics* metrics, float height)](#oh_arkui_customspanmetrics_setheight) | 设置自定义绘制Span的高度。在表情内嵌场景中，需要根据表情大小设置合适的高度以保持与文本对齐；在图文混排场景中，需要为嵌入元素设置与文本行高匹配的高度。 |
| [ArkUI_CustomSpanDrawInfo* OH_ArkUI_CustomSpanDrawInfo_Create(void)](#oh_arkui_customspandrawinfo_create) | 创建自定义绘制Span绘制信息。 |
| [void OH_ArkUI_CustomSpanDrawInfo_Dispose(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_dispose) | 销毁自定义绘制Span绘制信息。 |
| [float OH_ArkUI_CustomSpanDrawInfo_GetXOffset(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_getxoffset) | 获取自定义绘制Span相对于挂载组件的x轴偏移值。在自定义绘制回调中，需要根据偏移值确定绘制起始位置，用于实现表情内嵌、图文混排等场景的精确绘制。 |
| [float OH_ArkUI_CustomSpanDrawInfo_GetLineTop(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_getlinetop) | 获取自定义绘制Span相对于挂载组件的上边距。在自定义绘制时，需要根据上边距确定绘制区域的垂直起始位置，用于富文本编辑器、文档应用等场景的精确排版。 |
| [float OH_ArkUI_CustomSpanDrawInfo_GetLineBottom(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_getlinebottom) | 获取自定义绘制Span相对于挂载组件的下边距。在自定义绘制时，需要结合上边距和下边距计算绘制区域的高度范围，用于图文混排、表情内嵌等场景的精确布局。 |
| [float OH_ArkUI_CustomSpanDrawInfo_GetBaseline(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_getbaseline) | 获取自定义绘制Span相对于挂载组件的基线偏移量。 |

## 函数说明

### OH_ArkUI_CustomSpanMeasureInfo_Create()

```c
ArkUI_CustomSpanMeasureInfo* OH_ArkUI_CustomSpanMeasureInfo_Create(void)
```

**描述**

创建自定义绘制Span测量信息。

> **说明：**
>
> - 必须与OH_ArkUI_CustomSpanMeasureInfo_Dispose()配对使用。
>
> - 调用流程：OH_ArkUI_CustomSpanMeasureInfo_Create()→使用info对象→OH_ArkUI_CustomSpanMeasureInfo_Dispose()释放资源。
>
> - 使用完毕后必须调用OH_ArkUI_CustomSpanMeasureInfo_Dispose()释放内存，否则会导致资源泄漏。

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_CustomSpanMeasureInfo*](capi-arkui-nativemodule-arkui-customspanmeasureinfo.md) | ArkUI_CustomSpanMeasureInfo实例，用于在自定义绘制Span的测量回调中提供组件的测量数据。<br> 如果返回空指针，可能是因为内存不足。 |

### OH_ArkUI_CustomSpanMeasureInfo_Dispose()

```c
void OH_ArkUI_CustomSpanMeasureInfo_Dispose(ArkUI_CustomSpanMeasureInfo* info)
```

**描述**

销毁自定义绘制Span测量信息。

> **说明：**
>
> - 必须与OH_ArkUI_CustomSpanMeasureInfo_Create()配对使用。
>
> - 仅用于销毁由OH_ArkUI_CustomSpanMeasureInfo_Create()方法创建的测量信息对象。
>
> - 调用前确保已不再需要该对象，调用后该对象不可再使用。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanMeasureInfo](capi-arkui-nativemodule-arkui-customspanmeasureinfo.md)* info | 自定义绘制Span测量信息指针，用于传入需要销毁的测量信息对象。参数不能为空，否则会导致参数验证失败。必须是由OH_ArkUI_CustomSpanMeasureInfo_Create()创建的对象。 |

### OH_ArkUI_CustomSpanMeasureInfo_GetFontSize()

```c
float OH_ArkUI_CustomSpanMeasureInfo_GetFontSize(ArkUI_CustomSpanMeasureInfo* info)
```

**描述**

获取自定义绘制Span的父节点Text的字体大小。在自定义绘制Span的测量回调中，可根据父节点Text的字体大小计算自定义组件的布局尺寸，用于实现图文混排、表情内嵌等场景的精确排版。

> **说明：**
>
> - 必须先调用OH_ArkUI_CustomSpanMeasureInfo_Create()创建测量信息对象。
>
> - 参数info必须是通过OH_ArkUI_CustomSpanMeasureInfo_Create()方法返回的有效对象指针。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanMeasureInfo](capi-arkui-nativemodule-arkui-customspanmeasureinfo.md)* info | 自定义绘制Span测量信息指针。参数不能为空，否则会导致参数验证失败。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 父节点Text的字体大小，单位为fp。若参数验证失败，返回0.0f。<br> 异常返回原因：参数验证失败，参数不能为空。 |

### OH_ArkUI_CustomSpanMetrics_Create()

```c
ArkUI_CustomSpanMetrics* OH_ArkUI_CustomSpanMetrics_Create(void)
```

**描述**

创建自定义绘制Span度量信息。

> **说明：**
>
> - 必须与OH_ArkUI_CustomSpanMetrics_Dispose()配对使用。
>
> - 调用流程：OH_ArkUI_CustomSpanMetrics_Create()→设置宽高(可选)→使用metrics对象→OH_ArkUI_CustomSpanMetrics_Dispose()释放资源。
>
> - 使用完毕后必须调用OH_ArkUI_CustomSpanMetrics_Dispose()释放内存，否则会导致资源泄漏。

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_CustomSpanMetrics*](capi-arkui-nativemodule-arkui-customspanmetrics.md) | ArkUI_CustomSpanMetrics实例，用于描述自定义绘制Span的宽高等布局信息。<br> 如果返回空指针，可能是因为内存不足。 |

### OH_ArkUI_CustomSpanMetrics_Dispose()

```c
void OH_ArkUI_CustomSpanMetrics_Dispose(ArkUI_CustomSpanMetrics* metrics)
```

**描述**

销毁自定义绘制Span度量信息。

> **说明：**
>
> - 必须与OH_ArkUI_CustomSpanMetrics_Create()配对使用。
>
> - 仅用于销毁由OH_ArkUI_CustomSpanMetrics_Create()方法创建的度量信息对象。
>
> - 调用前确保已不再需要该对象，调用后该对象不可再使用。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md)* metrics | 自定义绘制Span度量信息实例指针，用于传入需要销毁的度量信息对象。参数不能为空，否则会导致参数验证失败。必须是由OH_ArkUI_CustomSpanMetrics_Create()创建的对象。 |

### OH_ArkUI_CustomSpanMetrics_SetWidth()

```c
int32_t OH_ArkUI_CustomSpanMetrics_SetWidth(ArkUI_CustomSpanMetrics* metrics, float width)
```

**描述**

设置自定义绘制Span的宽度。在图文混排场景中，需要为嵌入的图片或表情设置合适的宽度以匹配文本行高；在文档应用中，可能需要为自定义标记元素设置固定宽度。

> **说明：**
>
> - 必须先调用OH_ArkUI_CustomSpanMetrics_Create()创建度量信息对象。
>
> - 参数metrics必须是通过OH_ArkUI_CustomSpanMetrics_Create()方法返回的有效对象指针。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md)* metrics | 自定义绘制Span度量信息实例指针，用于传入需要设置宽度的度量信息对象。参数不能为空，否则会导致参数验证失败。 |
| float width | 宽度大小，单位为vp。取值范围[0, +∞)，默认值为0.0f，负值与默认值效果一致。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 参数验证失败。<br>         可能原因：参数验证失败，参数不能为空。<br>         处理步骤：请确保传入的metrics参数不为空指针。 |

### OH_ArkUI_CustomSpanMetrics_SetHeight()

```c
int32_t OH_ArkUI_CustomSpanMetrics_SetHeight(ArkUI_CustomSpanMetrics* metrics, float height)
```

**描述**

设置自定义绘制Span的高度。在表情内嵌场景中，需要根据表情大小设置合适的高度以保持与文本对齐；在图文混排场景中，需要为嵌入元素设置与文本行高匹配的高度。

> **说明：**
>
> - 必须先调用OH_ArkUI_CustomSpanMetrics_Create()创建度量信息对象。
>
> - 参数metrics必须是通过OH_ArkUI_CustomSpanMetrics_Create()方法返回的有效对象指针。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md)* metrics | 自定义绘制Span度量信息实例指针，用于传入需要设置高度的度量信息对象。参数不能为空，否则会导致参数验证失败。必须是通过OH_ArkUI_CustomSpanMetrics_Create()创建的有效对象。 |
| float height | 高度大小，单位为vp。取值范围[0, +∞)，默认值为0.0f，负值与默认值效果一致。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 参数验证失败。<br>         可能原因：参数验证失败，参数不能为空。<br>         处理步骤：请确保传入的metrics参数不为空指针。 |

### OH_ArkUI_CustomSpanDrawInfo_Create()

```c
ArkUI_CustomSpanDrawInfo* OH_ArkUI_CustomSpanDrawInfo_Create(void)
```

**描述**

创建自定义绘制Span绘制信息。

> **说明：**
>
> - 必须与OH_ArkUI_CustomSpanDrawInfo_Dispose()配对使用。
>
> - 调用流程：OH_ArkUI_CustomSpanDrawInfo_Create()→使用info对象→OH_ArkUI_CustomSpanDrawInfo_Dispose()释放资源。
>
> - 使用完毕后必须调用OH_ArkUI_CustomSpanDrawInfo_Dispose()释放内存，否则会导致资源泄漏。

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_CustomSpanDrawInfo*](capi-arkui-nativemodule-arkui-customspandrawinfo.md) | ArkUI_CustomSpanDrawInfo实例，表示自定义绘制Span的绘制信息。<br> 如果返回空指针，可能是因为内存不足。 |

### OH_ArkUI_CustomSpanDrawInfo_Dispose()

```c
void OH_ArkUI_CustomSpanDrawInfo_Dispose(ArkUI_CustomSpanDrawInfo* info)
```

**描述**

销毁自定义绘制Span绘制信息。

> **说明：**
>
> - 必须与OH_ArkUI_CustomSpanDrawInfo_Create()配对使用。
>
> - 仅用于销毁由OH_ArkUI_CustomSpanDrawInfo_Create()方法创建的绘制信息对象。
>
> - 调用前确保已不再需要该对象，调用后该对象不可再使用。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* info | 自定义绘制Span绘制信息指针，用于传入需要销毁的绘制信息对象。参数不能为空，否则会导致参数验证失败。必须是由OH_ArkUI_CustomSpanDrawInfo_Create()创建的对象。 |

### OH_ArkUI_CustomSpanDrawInfo_GetXOffset()

```c
float OH_ArkUI_CustomSpanDrawInfo_GetXOffset(ArkUI_CustomSpanDrawInfo* info)
```

**描述**

获取自定义绘制Span相对于挂载组件的x轴偏移值。在自定义绘制回调中，需要根据偏移值确定绘制起始位置，用于实现表情内嵌、图文混排等场景的精确绘制。

> **说明：**
>
> - 必须先调用OH_ArkUI_CustomSpanDrawInfo_Create()创建绘制信息对象。
>
> - 参数info必须是通过OH_ArkUI_CustomSpanDrawInfo_Create()方法返回的有效对象指针。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* info | 自定义绘制Span绘制信息指针，用于传入需要获取x轴偏移值的绘制信息对象。参数不能为空，否则会导致参数验证失败。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | x轴偏移值，单位为px。若参数验证失败，返回0.0f。<br> 异常返回原因：参数验证失败，参数不能为空。 |

### OH_ArkUI_CustomSpanDrawInfo_GetLineTop()

```c
float OH_ArkUI_CustomSpanDrawInfo_GetLineTop(ArkUI_CustomSpanDrawInfo* info)
```

**描述**

获取自定义绘制Span相对于挂载组件的上边距。在自定义绘制时，需要根据上边距确定绘制区域的垂直起始位置，用于富文本编辑器、文档应用等场景的精确排版。

> **说明：**
>
> - 必须先调用OH_ArkUI_CustomSpanDrawInfo_Create()创建绘制信息对象。
>
> - 参数info必须是通过OH_ArkUI_CustomSpanDrawInfo_Create()方法返回的有效对象指针。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* info | 自定义绘制Span绘制信息指针，用于传入需要获取上边距的绘制信息对象。参数不能为空，否则会导致参数验证失败。必须是通过OH_ArkUI_CustomSpanDrawInfo_Create()创建的有效对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 上边距值，单位为px。若参数验证失败，返回0.0f。<br> 异常返回原因：参数验证失败，参数不能为空。 |

### OH_ArkUI_CustomSpanDrawInfo_GetLineBottom()

```c
float OH_ArkUI_CustomSpanDrawInfo_GetLineBottom(ArkUI_CustomSpanDrawInfo* info)
```

**描述**

获取自定义绘制Span相对于挂载组件的下边距。在自定义绘制时，需要结合上边距和下边距计算绘制区域的高度范围，用于图文混排、表情内嵌等场景的精确布局。

> **说明：**
>
> - 必须先调用OH_ArkUI_CustomSpanDrawInfo_Create()创建绘制信息对象。
>
> - 参数info必须是通过OH_ArkUI_CustomSpanDrawInfo_Create()方法返回的有效对象指针。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* info | 自定义绘制Span绘制信息指针，用于传入需要获取下边距的绘制信息对象。参数不能为空，否则会导致参数验证失败。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 下边距值，单位为px。若参数验证失败，返回0.0f。<br> 异常返回原因：参数验证失败，参数不能为空。 |

### OH_ArkUI_CustomSpanDrawInfo_GetBaseline()

```c
float OH_ArkUI_CustomSpanDrawInfo_GetBaseline(ArkUI_CustomSpanDrawInfo* info)
```

**描述**

获取自定义绘制Span相对于挂载组件的基线偏移量。在自定义绘制Span的绘制回调中，通过本接口获取基线偏移量用于文本对齐排版，实现富文本编辑器、图文混排等场景的精准绘制效果。

> **说明：**
>
> - 必须先调用OH_ArkUI_CustomSpanDrawInfo_Create()创建绘制信息对象。
>
> - 参数info必须是通过OH_ArkUI_CustomSpanDrawInfo_Create()方法返回的有效对象指针。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* info | 自定义绘制Span绘制信息指针，用于传入需要获取基线偏移量的绘制信息对象。参数不能为空，否则会导致参数验证失败。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 基线偏移量值，单位为px。若参数验证失败，返回0.0f。<br> 异常返回原因：参数验证失败，参数不能为空。 |


