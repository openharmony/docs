# inputmethod_text_avoid_info_capi.h
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

## 概述

提供输入框避让信息对象的创建、销毁与读写方法，用于在软键盘弹起时动态调整输入框的位置，避免遮挡输入内容。

InputMethod_TextAvoidInfo描述了编辑框在屏幕上的位置和高度信息，输入法框架根据这些信息计算避让区域，使编辑框在键盘弹起时能够自动上移或调整布局，确保用户可见并可操作输入区域。该结构体作为InputMethod_TextConfig的子属性，通过OH_TextConfig_GetTextAvoidInfo从TextConfig中获取，用于向输入法框架传递编辑框的避让参数。

**引用文件：** <inputmethod/inputmethod_text_avoid_info_capi.h>

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：** [InputMethod](capi-inputmethod.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) | InputMethod_TextAvoidInfo | 输入框避让信息。输入框用于避让键盘显示区域的信息，包含编辑框的Y坐标和高度。 |

### 函数

| 名称 | 描述                                            |
| -- |-----------------------------------------------|
| [InputMethod_TextAvoidInfo *OH_TextAvoidInfo_Create(double positionY, double height)](#oh_textavoidinfo_create) | 创建一个新的[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)实例。 |
| [void OH_TextAvoidInfo_Destroy(InputMethod_TextAvoidInfo *info)](#oh_textavoidinfo_destroy) | 销毁一个[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)实例。      |
| [InputMethod_ErrorCode OH_TextAvoidInfo_SetPositionY(InputMethod_TextAvoidInfo *info, double positionY)](#oh_textavoidinfo_setpositiony) | 设置[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)中的Y坐标值。    |
| [InputMethod_ErrorCode OH_TextAvoidInfo_SetHeight(InputMethod_TextAvoidInfo *info, double height)](#oh_textavoidinfo_setheight) | 设置[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)中的高度值。     |
| [InputMethod_ErrorCode OH_TextAvoidInfo_GetPositionY(InputMethod_TextAvoidInfo *info, double *positionY)](#oh_textavoidinfo_getpositiony) | 从[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)获取Y坐标值。     |
| [InputMethod_ErrorCode OH_TextAvoidInfo_GetHeight(InputMethod_TextAvoidInfo *info, double *height)](#oh_textavoidinfo_getheight) | 从[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)获取高度值。      |

## 函数说明

### OH_TextAvoidInfo_Create()

```c
InputMethod_TextAvoidInfo *OH_TextAvoidInfo_Create(double positionY, double height)
```

**描述**

创建一个新的[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)实例。该函数根据指定的Y坐标和高度创建一个避让信息对象，用于描述编辑框在物理屏幕上的位置和尺寸。

使用场景：当编辑框需要向输入法框架传递避让参数时，首先调用此函数创建TextAvoidInfo实例，设置编辑框的Y坐标和高度，然后通过InputMethod_TextConfig将该信息传递给输入法框架。输入法框架根据避让信息计算键盘弹起后的编辑框调整区域。

使用后效果：成功调用后返回一个新创建的InputMethod_TextAvoidInfo实例指针，该实例包含指定的positionY和height值。调用方需负责该实例的生命周期管理，在使用完毕后必须调用OH_TextAvoidInfo_Destroy销毁实例以释放内存。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| double positionY | 表示输入框位置的Y坐标值，单位px。Y坐标值即输入框顶点与物理屏幕上侧距离的绝对值。取值范围≥0，建议使用物理屏幕的实际坐标值。若传入负值，创建仍会成功，但该值在实际避让计算中无意义。 |
| double height | 表示输入框高度，单位px。取值范围≥0，建议使用编辑框的实际像素高度。若传入负值，创建仍会成功，但该值在实际避让计算中无意义。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) * | 如果创建成功，返回一个指向新创建的[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)实例的指针。调用方必须负责该实例的生命周期管理，使用完毕后调用[OH_TextAvoidInfo_Destroy](#oh_textavoidinfo_destroy)销毁实例以释放内存。<br> 如果创建失败，返回NULL。可能的失败原因：内存分配不足（应用地址空间满）。对NULL指针的后续操作（如Set/Get函数）将返回IME_ERR_NULL_POINTER。 |

### OH_TextAvoidInfo_Destroy()

```c
void OH_TextAvoidInfo_Destroy(InputMethod_TextAvoidInfo *info)
```

**描述**

销毁一个[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)实例，释放其占用的内存资源。

使用场景：当TextAvoidInfo实例不再使用时，调用此函数销毁实例。必须在Create函数成功返回后、且实例不再被任何其他对象引用时调用。

生命周期管理：OH_TextAvoidInfo_Create和OH_TextAvoidInfo_Destroy必须配对使用，每个Create创建的实例必须有对应的Destroy调用，否则会导致内存泄漏。调用Destroy后，原指针变为无效指针，不应再被使用。

前置条件：info参数应为OH_TextAvoidInfo_Create成功返回的非NULL指针。

使用后效果：info指向的内存被释放，info指针变为无效指针。对已销毁指针的任何后续访问均为未定义行为。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) *info | 表示指向即将被销毁的[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)实例的指针。若传入NULL，函数不执行任何操作，安全返回。建议销毁后将指针置为NULL以避免误用悬空指针。 |

### OH_TextAvoidInfo_SetPositionY()

```c
InputMethod_ErrorCode OH_TextAvoidInfo_SetPositionY(InputMethod_TextAvoidInfo *info, double positionY)
```

**描述**

设置[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)中的Y坐标值。Y坐标值表示输入框顶点与物理屏幕上侧距离的绝对值。

使用场景：当编辑框位置发生变化时（如窗口移动、布局调整），需要更新避让信息中的Y坐标值，使输入法框架能够根据最新位置重新计算避让区域。

前置条件：info参数必须为OH_TextAvoidInfo_Create成功返回的非NULL指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) *info | 指向即将被设置值的[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)实例的指针。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |
| double positionY | Y坐标值，即输入框顶点与物理屏幕上侧距离的绝对值，单位px。取值范围≥0，建议使用物理屏幕的实际坐标值。传入负值不会报错，但在实际避让计算中无意义。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，info参数为NULL。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextAvoidInfo_SetHeight()

```c
InputMethod_ErrorCode OH_TextAvoidInfo_SetHeight(InputMethod_TextAvoidInfo *info, double height)
```

**描述**

设置[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)中的高度值。高度值表示编辑框在屏幕上占据的垂直像素尺寸。

使用场景：当编辑框高度发生变化时（如布局调整、窗口缩放），需要更新避让信息中的高度值，使输入法框架能够根据最新高度重新计算避让区域。避让区域计算依赖于positionY和height的组合，确保编辑框在键盘弹起时不被遮挡。

前置条件：info参数必须为OH_TextAvoidInfo_Create成功返回的非NULL指针。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) *info | 指向即将被设置值的[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)实例的指针。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |
| double height | 高度值，单位px。取值范围≥0，建议使用编辑框的实际像素高度。传入负值不会报错，但在实际避让计算中无意义。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，info参数为NULL。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextAvoidInfo_GetPositionY()

```c
InputMethod_ErrorCode OH_TextAvoidInfo_GetPositionY(InputMethod_TextAvoidInfo *info, double *positionY)
```

**描述**

从[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)获取Y坐标值。Y坐标值即输入框顶点与物理屏幕上侧距离的绝对值。

使用场景：输入法应用在处理避让逻辑时，需要获取编辑框的Y坐标值，以确定编辑框在屏幕上的垂直位置，从而判断是否需要调整编辑框位置或布局。

前置条件：info参数必须为OH_TextAvoidInfo_Create成功返回的非NULL指针；positionY输出参数必须为非NULL的double类型指针，且由调用方分配内存。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) *info | 指向即将被获取值的[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)实例的指针。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |
| double *positionY | 输出参数，用于接收Y坐标值，即输入框顶点与物理屏幕上侧距离的绝对值，单位px。此参数为输出指针，调用方需分配double类型变量的内存并将其地址传入。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功，positionY指针指向的内存已被写入Y坐标值。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，info或positionY参数为NULL。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextAvoidInfo_GetHeight()

```c
InputMethod_ErrorCode OH_TextAvoidInfo_GetHeight(InputMethod_TextAvoidInfo *info, double *height)
```

**描述**

从[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)获取高度值。高度值表示编辑框在屏幕上占据的垂直像素尺寸。

使用场景：输入法应用在处理避让逻辑时，需要获取编辑框的高度值，结合Y坐标值确定编辑框在屏幕上的完整垂直范围（positionY到positionY+height），从而判断编辑框是否会被键盘遮挡。

前置条件：info参数必须为OH_TextAvoidInfo_Create成功返回的非NULL指针；height输出参数必须为非NULL的double类型指针，且由调用方分配内存。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) *info | 指向即将被获取值的[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)实例的指针。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |
| double *height | 输出参数，用于接收输入框高度，单位px。此参数为输出指针，调用方需分配double类型变量的内存并将其地址传入。不允许传入NULL指针，否则返回IME_ERR_NULL_POINTER。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功，height指针指向的内存已被写入高度值。<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，info或height参数为NULL。<br> 具体错误码可以参考 [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |
