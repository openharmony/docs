# inputmethod_attach_options_capi.h
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

## 概述

提供输入法绑定选项对象的创建、销毁与读写方法，用于管理应用绑定输入法时的配置参数。

功能：创建和管理InputMethod_AttachOptions实例，支持配置绑定时是否显示键盘（showKeyboard）以及触发输入法拉起的场景原因（requestKeyboardReason）。AttachOptions是调用OH_InputMethodController_Attach时的必要参数，用于控制绑定输入法服务时的初始行为。

使用场景：在应用绑定输入法服务前，创建AttachOptions配置绑定行为：
- showKeyboard=true时，绑定时自动拉起键盘，适用于输入框获得焦点后需要立即输入的场景。
- showKeyboard=false时，绑定时不拉起键盘，适用于需要先建立交互通道但暂不输入的场景（如搜索框先绑定输入法，等用户点击后再拉起键盘）。
- requestKeyboardReason用于标识触发输入法拉起的原因（如鼠标点击、触摸事件等），帮助系统识别输入场景以提供更好的用户体验。

使用后效果：创建AttachOptions后，将其传入Attach函数，Attach函数将读取其中的配置来决定绑定行为。Attach完成后，AttachOptions可销毁，因为配置信息已被读取。

**引用文件：** <inputmethod/inputmethod_attach_options_capi.h>

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：** [InputMethod](capi-inputmethod.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) | InputMethod_AttachOptions | 输入法绑定选项，用于在绑定输入法时携带相关配置。这是一个不透明类型（opaque type），调用者不可直接访问其成员变量，只能通过本头文件提供的函数操作。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [InputMethod_AttachOptions *OH_AttachOptions_Create(bool showKeyboard)](#oh_attachoptions_create) | 创建一个InputMethod_AttachOptions实例，适用于仅需控制键盘显示状态的简单绑定场景。 |
| [InputMethod_AttachOptions *OH_AttachOptions_CreateWithRequestKeyboardReason(bool showKeyboard, InputMethod_RequestKeyboardReason requestKeyboardReason)](#oh_attachoptions_createwithrequestkeyboardreason) | 创建一个InputMethod_AttachOptions实例，同时指定键盘显示状态和请求键盘的原因，适用于需要标识触发输入法拉起场景的绑定场景。 |
| [void OH_AttachOptions_Destroy(InputMethod_AttachOptions *options)](#oh_attachoptions_destroy) | 销毁一个InputMethod_AttachOptions实例，释放由OH_AttachOptions_Create函数分配的内存资源。 |
| [InputMethod_ErrorCode OH_AttachOptions_IsShowKeyboard(InputMethod_AttachOptions *options, bool *showKeyboard)](#oh_attachoptions_isshowkeyboard) | 从InputMethod_AttachOptions中获取是否显示键盘的值。 |
| [InputMethod_ErrorCode OH_AttachOptions_GetRequestKeyboardReason(InputMethod_AttachOptions *options, int *requestKeyboardReason)](#oh_attachoptions_getrequestkeyboardreason) | 从InputMethod_AttachOptions中获取请求键盘的原因。 |

## 函数说明

### OH_AttachOptions_Create()

```c
InputMethod_AttachOptions *OH_AttachOptions_Create(bool showKeyboard)
```

**描述**

创建一个[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)实例，适用于仅需控制键盘显示状态的简单场景。如需同时指定触发输入法拉起的场景原因，建议使用[OH_AttachOptions_CreateWithRequestKeyboardReason](#oh_attachoptions_createwithrequestkeyboardreason)。

配对调用：必须与[OH_AttachOptions_Destroy](#oh_attachoptions_destroy)配对调用，OH_AttachOptions_Create创建的对象必须通过OH_AttachOptions_Destroy销毁，否则会导致内存泄漏。

生命周期管理：
- 创建后可多次读取（IsShowKeyboard）。
- 将options传入Attach函数后，Attach函数将读取配置信息。Attach完成后options可立即销毁，因为配置已被读取。
- 不可将已销毁的options再次使用。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| bool showKeyboard | 输入参数，表示绑定时是否显示键盘。<br>使用场景：true适用于输入框获得焦点后需要立即输入的场景（如文本编辑框）；false适用于先建立交互通道但暂不需要键盘的场景（如搜索框，等用户主动点击后再拉起键盘）。<br>使用后效果：showKeyboard=true时，绑定成功后键盘将自动弹出；showKeyboard=false时，绑定成功后键盘不弹出，需后续通过OH_InputMethodProxy_ShowKeyboard主动拉起。<br>取值范围：true或false。<br>默认值：无默认值，调用者必须显式指定。<br>取值原则：根据业务场景决定。需要立即输入的场景设为true；需要延迟拉起键盘的场景设为false，后续通过ShowKeyboard主动拉起。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) * | 返回指针类型。<br>创建成功：返回一个指向新创建的InputMethod_AttachOptions实例的指针，该指针有效且可用于后续操作。<br>创建失败：返回NULL，可能的失败原因包括应用地址空间满（内存不足）。<br>NULL判断：调用者必须在使用返回值前检查是否为NULL，若为NULL则不可使用该指针，应排查内存状况或稍后重试。<br>内存管理：返回的指针由Create函数内部分配内存，调用者需通过OH_AttachOptions_Destroy释放，不可使用free()或其他方式释放。 |

### OH_AttachOptions_CreateWithRequestKeyboardReason()

```c
InputMethod_AttachOptions *OH_AttachOptions_CreateWithRequestKeyboardReason(bool showKeyboard, InputMethod_RequestKeyboardReason requestKeyboardReason)
```

**描述**

创建一个[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)实例，同时指定键盘显示状态和请求键盘的原因。requestKeyboardReason参数用于标识触发输入法拉起的场景原因，帮助系统识别输入场景以提供更好的用户体验。

配对调用：必须与[OH_AttachOptions_Destroy](#oh_attachoptions_destroy)配对调用，Create创建的对象必须通过OH_AttachOptions_Destroy销毁。

生命周期管理：与OH_AttachOptions_Create一致。创建后可多次读取，Attach完成后可立即销毁。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| bool showKeyboard | 输入参数，表示绑定时是否显示键盘。含义/功能、使用场景、使用后效果、取值范围、取值原则与OH_AttachOptions_Create中的showKeyboard参数一致。 |
| [InputMethod_RequestKeyboardReason](capi-inputmethod-types-capi-h.md#inputmethod_requestkeyboardreason) requestKeyboardReason | 输入参数，表示请求键盘输入的原因。<br>含义/功能：标识触发输入法拉起的场景原因，用于帮助系统识别输入场景并优化用户体验。<br>使用场景：当应用需要告知系统为何拉起键盘时使用，例如区分用户通过鼠标点击、触摸事件还是应用主动调用API触发输入法。<br>使用后效果：系统可根据此原因调整输入法行为（如选择合适的键盘布局或输入模式）。<br>取值范围：InputMethod_RequestKeyboardReason枚举值，包括：<br>- IME_REQUEST_REASON_NONE (0)：无特定原因。<br>- IME_REQUEST_REASON_MOUSE (1)：通过鼠标点击触发。<br>- IME_REQUEST_REASON_TOUCH (2)：通过触摸事件触发。<br>- IME_REQUEST_REASON_OTHER (20)：其他原因（应用主动调用API等）。<br>取值原则：根据实际触发场景选择对应的枚举值。用户通过触摸输入框触发时使用IME_REQUEST_REASON_TOUCH；通过鼠标点击触发时使用IME_REQUEST_REASON_MOUSE；应用内部逻辑主动触发时使用IME_REQUEST_REASON_OTHER。<br>规格限制：仅支持上述枚举值，传入其他值可能导致未定义行为。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) * | 返回指针类型。<br>创建成功：返回一个指向新创建的InputMethod_AttachOptions实例的指针。<br>创建失败：返回NULL，可能的失败原因有应用地址空间满（内存不足）。<br>NULL判断：调用者必须在使用返回值前检查是否为NULL，若为NULL则不可使用该指针。<br>内存管理：返回的指针由Create函数内部分配内存，调用者需通过OH_AttachOptions_Destroy释放，不可使用free()或其他方式释放。 |

### OH_AttachOptions_Destroy()

```c
void OH_AttachOptions_Destroy(InputMethod_AttachOptions *options)
```

**描述**

销毁一个[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)实例，释放由OH_AttachOptions_Create函数分配的内存资源。该方法与OH_AttachOptions_Create和OH_AttachOptions_CreateWithRequestKeyboardReason配对使用。

配对调用：必须与OH_AttachOptions_Create或OH_AttachOptions_CreateWithRequestKeyboardReason配对调用。每个OH_AttachOptions_Create创建的实例必须且只能调用一次OH_AttachOptions_Destroy。

生命周期管理：
- OH_AttachOptions_Destroy后，options指针不再有效，不可继续使用。
- 不可对同一个options指针调用两次OH_AttachOptions_Destroy，否则会导致重复释放（double-free）。
- 建议在Attach成功后立即调用OH_AttachOptions_Destroy，因为Attach已读取完配置信息。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) *options | 输入指针，表示即将被销毁的InputMethod_AttachOptions实例。<br>含义/功能：指定要销毁的AttachOptions实例，OH_AttachOptions_Destroy将释放该实例占用的内存资源。<br>使用场景：在AttachOptions不再需要时调用，典型时机为Attach绑定完成后。<br>使用后效果：options指向的内存被释放，该指针不再有效。<br>NULL指针处理：若options为NULL，OH_AttachOptions_Destroy函数不做任何操作（安全处理），不会导致崩溃。但建议调用者避免传入NULL，因为这意味着OH_AttachOptions_Create失败未被正确处理。<br>内存释放责任：由调用者负责在适当时机调用OH_AttachOptions_Destroy释放内存。 |

### OH_AttachOptions_IsShowKeyboard()

```c
InputMethod_ErrorCode OH_AttachOptions_IsShowKeyboard(InputMethod_AttachOptions *options, bool *showKeyboard)
```

**描述**

从[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)中获取是否显示键盘的值。

前置条件：options必须是通过OH_AttachOptions_Create函数创建的有效实例，showKeyboard必须指向有效的bool变量。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) *options | 输入指针，表示被读取值的InputMethod_AttachOptions实例。<br>含义/功能：指定要从哪个AttachOptions实例中读取showKeyboard属性。<br>NULL指针处理：不可为NULL，传入NULL将返回IME_ERR_NULL_POINTER。<br>前提条件：必须通过OH_AttachOptions_Create函数创建的有效实例。 |
| bool *showKeyboard | 输出指针，表示从InputMethod_AttachOptions中获取的是否显示键盘的值。<br>含义/功能：用于接收showKeyboard属性的值。true表示绑定完成时需要显示键盘；false表示绑定完成时不需要显示键盘。<br>使用场景：需要查询AttachOptions的键盘显示配置时使用，如Attach前确认配置、调试时验证配置等。<br>NULL指针处理：不可为NULL，传入NULL将返回IME_ERR_NULL_POINTER。调用者需确保showKeyboard指向有效的bool变量。<br>内存分配责任：由调用者分配bool变量的内存，IsShowKeyboard仅写入值，不分配内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。*showKeyboard已被赋值为正确的布尔值。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。表示options或showKeyboard为空指针，调用前需确保这两个参数已正确初始化且不为NULL。<br>错误处理建议：若返回IME_ERR_NULL_POINTER，检查options和showKeyboard是否为有效指针；若返回IME_ERR_OK，*showKeyboard即为正确的配置值。具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_AttachOptions_GetRequestKeyboardReason()

```c
InputMethod_ErrorCode OH_AttachOptions_GetRequestKeyboardReason(InputMethod_AttachOptions *options, int *requestKeyboardReason)
```

**描述**

从[InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md)中获取请求键盘输入的原因。

前置条件：options必须是通过OH_AttachOptions_CreateWithRequestKeyboardReason创建的实例（通过OH_AttachOptions_Create创建的实例的requestKeyboardReason默认值为IME_REQUEST_REASON_NONE）。requestKeyboardReason必须指向有效的InputMethod_RequestKeyboardReason变量。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) *options | 输入指针，表示被读取值的InputMethod_AttachOptions实例。<br>含义/功能：指定要从哪个AttachOptions实例中读取requestKeyboardReason属性。<br>NULL指针处理：不可为NULL，传入NULL将返回IME_ERR_NULL_POINTER。<br>前提条件：必须通过OH_AttachOptions_Create函数创建的有效实例。若实例通过OH_AttachOptions_Create（而非CreateWithRequestKeyboardReason）创建，读取的requestKeyboardReason默认值为IME_REQUEST_REASON_NONE。 |
| [InputMethod_RequestKeyboardReason](capi-inputmethod-types-capi-h.md#inputmethod_requestkeyboardreason) *requestKeyboardReason | 输出指针，表示请求键盘输入的原因。<br>含义/功能：输出参数，用于获取触发输入法拉起的场景原因枚举值。<br>使用场景：需要查询AttachOptions的请求键盘原因配置时使用。<br>取值范围：输出值为InputMethod_RequestKeyboardReason枚举：IME_REQUEST_REASON_NONE(0)、IME_REQUEST_REASON_MOUSE(1)、IME_REQUEST_REASON_TOUCH(2)、IME_REQUEST_REASON_OTHER(20)。<br>NULL指针处理：不可为NULL，传入NULL将返回IME_ERR_NULL_POINTER。调用者需确保requestKeyboardReason指向有效的变量。<br>内存分配责任：由调用者分配变量的内存，GetRequestKeyboardReason仅写入值，不分配内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。*requestKeyboardReason已被赋值为正确的枚举值。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针。表示options或requestKeyboardReason为空指针，调用前需确保这两个参数已正确初始化且不为NULL。<br>错误处理建议：若返回IME_ERR_NULL_POINTER，检查options和requestKeyboardReason是否为有效指针；若返回IME_ERR_OK，*requestKeyboardReason即为正确的配置值。具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |
