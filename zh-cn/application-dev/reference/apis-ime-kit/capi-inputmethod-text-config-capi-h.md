# inputmethod_text_config_capi.h
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

## 概述

提供输入框配置信息对象的创建、销毁与读写方法。InputMethod_TextConfig承载编辑框的配置信息，在GetTextConfigFunc回调中使用，开发者需在回调内对config参数设置各配置项。

**引用文件：** <inputmethod/inputmethod_text_config_capi.h>

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：** [InputMethod](capi-inputmethod.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) | InputMethod_TextConfig | 输入框的配置信息。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [InputMethod_TextConfig *OH_TextConfig_Create(void)](#oh_textconfig_create) | 创建一个新的InputMethod_TextConfig实例。 |
| [void OH_TextConfig_Destroy(InputMethod_TextConfig *config)](#oh_textconfig_destroy) | 销毁一个InputMethod_TextConfig实例。 |
| [InputMethod_ErrorCode OH_TextConfig_SetInputType(InputMethod_TextConfig *config, InputMethod_TextInputType inputType)](#oh_textconfig_setinputtype) | 设置文本配置信息中的输入框类型。 |
| [InputMethod_ErrorCode OH_TextConfig_SetEnterKeyType(InputMethod_TextConfig *config, InputMethod_EnterKeyType enterKeyType)](#oh_textconfig_setenterkeytype) | 设置文本配置信息中的回车键功能类型。 |
| [InputMethod_ErrorCode OH_TextConfig_SetPreviewTextSupport(InputMethod_TextConfig *config, bool supported)](#oh_textconfig_setpreviewtextsupport) | 将预上屏支持情况设置到文本配置信息中。 |
| [InputMethod_ErrorCode OH_TextConfig_SetSelection(InputMethod_TextConfig *config, int32_t start, int32_t end)](#oh_textconfig_setselection) | 设置文本配置信息中的选中文本范围。 |
| [InputMethod_ErrorCode OH_TextConfig_SetWindowId(InputMethod_TextConfig *config, int32_t windowId)](#oh_textconfig_setwindowid) | 设置文本配置信息中所属窗口的窗口id。 |
| [InputMethod_ErrorCode OH_TextConfig_SetPlaceholder(InputMethod_TextConfig *config, const char16_t *placeholder,size_t length)](#oh_textconfig_setplaceholder) | 设置文本配置信息中的占位符文本信息。 |
| [InputMethod_ErrorCode OH_TextConfig_SetAbilityName(InputMethod_TextConfig *config, const char16_t *abilityName,size_t length)](#oh_textconfig_setabilityname) | 设置文本配置信息中的abilityName信息。 |
| [InputMethod_ErrorCode OH_TextConfig_SetConsumeKeyEvents(InputMethod_TextConfig *config, bool consumeKeyEvents)](#oh_textconfig_setconsumekeyevents) | 将编辑框是否具有完整处理字母、字符、功能等按键的能力设置到文本配置信息中。 |
| [InputMethod_ErrorCode OH_TextConfig_GetInputType(InputMethod_TextConfig *config, InputMethod_TextInputType *inputType)](#oh_textconfig_getinputtype) | 获取文本配置信息中的输入框类型。 |
| [InputMethod_ErrorCode OH_TextConfig_GetEnterKeyType(InputMethod_TextConfig *config, InputMethod_EnterKeyType *enterKeyType)](#oh_textconfig_getenterkeytype) | 获取文本配置信息中的回车键功能类型。 |
| [InputMethod_ErrorCode OH_TextConfig_IsPreviewTextSupported(InputMethod_TextConfig *config, bool *supported)](#oh_textconfig_ispreviewtextsupported) | 获取文本配置中是否支持预上屏。 |
| [InputMethod_ErrorCode OH_TextConfig_GetCursorInfo(InputMethod_TextConfig *config, InputMethod_CursorInfo **cursorInfo)](#oh_textconfig_getcursorinfo) | 获取文本配置信息中的光标信息。 |
| [InputMethod_ErrorCode OH_TextConfig_GetTextAvoidInfo(InputMethod_TextConfig *config, InputMethod_TextAvoidInfo **avoidInfo)](#oh_textconfig_gettextavoidinfo) | 获取文本配置信息中的避让信息。 |
| [InputMethod_ErrorCode OH_TextConfig_GetSelection(InputMethod_TextConfig *config, int32_t *start, int32_t *end)](#oh_textconfig_getselection) | 获取文本配置信息中的选区范围信息。 |
| [InputMethod_ErrorCode OH_TextConfig_GetWindowId(InputMethod_TextConfig *config, int32_t *windowId)](#oh_textconfig_getwindowid) | 获取文本配置信息中所属窗口的窗口id。 |
| [InputMethod_ErrorCode OH_TextConfig_GetPlaceholder(InputMethod_TextConfig *config, char16_t *placeholder,size_t *length)](#oh_textconfig_getplaceholder) | 获取文本配置信息中的占位符文本信息。 |
| [InputMethod_ErrorCode OH_TextConfig_GetAbilityName(InputMethod_TextConfig *config, char16_t *abilityName,size_t *length)](#oh_textconfig_getabilityname) | 获取文本配置信息中的abilityName信息。 |
| [InputMethod_ErrorCode OH_TextConfig_GetConsumeKeyEvents(InputMethod_TextConfig *config, bool *consumeKeyEvents)](#oh_textconfig_getconsumekeyevents) | 获取文本配置中是否具有完整处理字母、字符、功能等按键的能力。 |

## 函数说明

### OH_TextConfig_Create()

```c
InputMethod_TextConfig *OH_TextConfig_Create(void)
```

**描述**

创建一个新的[InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md)实例。主要用于在[OH_TextEditorProxy_GetTextConfigFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_gettextconfigfunc)回调中对config参数进行设置操作。

使用场景：当开发者需要在GetTextConfigFunc回调外部预先创建TextConfig对象以准备配置信息时调用此函数。通常config参数由回调框架提供，开发者直接在回调内设置即可，无需自行创建。

使用后效果：创建成功后返回一个新的TextConfig实例指针，后续可通过Set*接口设置配置属性。

生命周期管理：返回的对象必须通过[OH_TextConfig_Destroy](#oh_textconfig_destroy)销毁，Create与Destroy必须配对使用。未销毁会导致内存泄漏。同一个实例只能被销毁一次。

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) * | 如果创建成功，返回一个指向新创建的[InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md)实例的指针。如果创建失败，返回NULL，可能的失败原因有内存不足。返回的指针在使用完毕后必须通过[OH_TextConfig_Destroy](#oh_textconfig_destroy)销毁，销毁后指针应设置为NULL避免误用。 |

### OH_TextConfig_Destroy()

```c
void OH_TextConfig_Destroy(InputMethod_TextConfig *config)
```

**描述**

销毁一个[InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md)实例。销毁后config指针不可再使用，建议将指针设置为NULL避免误用。

使用场景：当应用不再需要TextConfig对象时调用此函数释放资源。

使用后效果：config对象将被释放，其内部资源被回收，此后不可再通过config指针调用任何函数。

生命周期管理：与[OH_TextConfig_Create](#oh_textconfig_create)配对使用。同一个实例只能被销毁一次，不可重复销毁。若config为NULL，函数不做任何处理。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，表示指向即将被销毁的[InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md)实例的指针。若传入NULL，函数不做任何处理，不会导致崩溃。销毁后该指针失效，建议设置为NULL。注意：由GetTextConfigFunc回调框架提供的config参数的内存由框架管理，回调返回后自动释放，不可在回调外部调用Destroy销毁。 |

### OH_TextConfig_SetInputType()

```c
InputMethod_ErrorCode OH_TextConfig_SetInputType(InputMethod_TextConfig *config, InputMethod_TextInputType inputType)
```

**描述**

设置文本配置信息中的输入框类型。输入法框架将根据此类型调整键盘布局。

使用场景：在GetTextConfigFunc回调内设置编辑框的输入类型，或在创建TextConfig后预先设置输入类型。

使用后效果：设置成功后，输入法框架将据此切换对应的键盘布局（如文本键盘、数字键盘等）。

前置条件：config须为有效的InputMethod_TextConfig实例指针。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，指向即将被设置值的[InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md)实例的指针。不可为NULL，若传入NULL将返回IME_ERR_NULL_POINTER。 |
| [InputMethod_TextInputType](capi-inputmethod-types-capi-h.md#inputmethod_textinputtype) inputType | 输入参数，输入框的输入类型。取值范围：[InputMethod_TextInputType](capi-inputmethod-types-capi-h.md#inputmethod_textinputtype)枚举值，如IME_TEXT_INPUT_TYPE_TEXT、IME_TEXT_INPUT_TYPE_NUMBER、IME_TEXT_INPUT_TYPE_PHONE等。使用后效果：不同类型将触发输入法切换到不同的键盘布局。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>IME_ERR_OK = 0：表示成功。<br>IME_ERR_NULL_POINTER = 12802000：非预期的空指针，config为NULL。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextConfig_SetEnterKeyType()

```c
InputMethod_ErrorCode OH_TextConfig_SetEnterKeyType(InputMethod_TextConfig *config, InputMethod_EnterKeyType enterKeyType)
```

**描述**

设置文本配置信息中的回车键功能类型。输入法框架将据此调整回车键的显示标签和功能。

使用场景：在GetTextConfigFunc回调内设置编辑框的回车键类型。

使用后效果：设置成功后，输入法键盘上的回车键将显示对应的标签（如"搜索"、"完成"等）并执行对应功能。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，指向即将被设置值的TextConfig实例的指针。不可为NULL。 |
| [InputMethod_EnterKeyType](capi-inputmethod-types-capi-h.md#inputmethod_enterkeytype) enterKeyType | 输入参数，回车键功能类型。取值范围：[InputMethod_EnterKeyType](capi-inputmethod-types-capi-h.md#inputmethod_enterkeytype)枚举值。使用后效果：不同类型对应不同的回车键行为和显示标签。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，config为NULL。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextConfig_SetPreviewTextSupport()

```c
InputMethod_ErrorCode OH_TextConfig_SetPreviewTextSupport(InputMethod_TextConfig *config, bool supported)
```

**描述**

将预上屏支持情况设置到文本配置信息中。预上屏是输入法的候选文本展示功能，设置supported为true后输入法将启用预上屏功能。

使用场景：在GetTextConfigFunc回调内设置编辑框是否支持预上屏功能。

使用后效果：设置为true后，输入法将启用预上屏功能，通过SetPreviewTextFunc回调向编辑框发送预上屏文本；设置为false后，输入法不使用预上屏功能。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，指向即将被设置值的TextConfig实例的指针。不可为NULL。 |
| bool supported | 输入参数，表示输入框是否支持预上屏。取值范围：true或false。true表示支持预上屏，输入法将使用SetPreviewTextFunc回调；false表示不支持预上屏。此参数为必需参数，必须设置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，config为NULL。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextConfig_SetSelection()

```c
InputMethod_ErrorCode OH_TextConfig_SetSelection(InputMethod_TextConfig *config, int32_t start, int32_t end)
```

**描述**

设置文本配置信息中的选中文本范围。用于告知输入法当前编辑框的文本选区状态。

使用场景：在GetTextConfigFunc回调内设置当前编辑框的选区范围。

使用后效果：设置成功后，输入法将据此感知编辑框的选中状态。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，指向即将被设置值的TextConfig实例的指针。不可为NULL。 |
| int32_t start | 输入参数，所选文本的起始位置（单位：字符偏移量，从0开始计数）。取值原则：start应大于等于0且小于等于end。 |
| int32_t end | 输入参数，所选文本的结束位置（单位：字符偏移量，从0开始计数）。取值原则：end应大于等于start且小于等于文本总长度。无选中文本时start与end相等表示光标位置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，config为NULL。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextConfig_SetWindowId()

```c
InputMethod_ErrorCode OH_TextConfig_SetWindowId(InputMethod_TextConfig *config, int32_t windowId)
```

**描述**

设置文本配置信息中所属窗口的窗口id。用于标识编辑框所属的应用窗口，输入法据此确定避让区域和候选词窗口定位。

使用场景：在GetTextConfigFunc回调内设置编辑框所属窗口的窗口ID。

使用后效果：设置成功后，输入法将据此确定候选词窗口的定位和避让策略。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，指向即将被设置值的TextConfig实例的指针。不可为NULL。 |
| int32_t windowId | 输入参数，绑定输入法的应用所属窗口的窗口id。此参数为必需参数，必须设置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，config为NULL。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextConfig_SetPlaceholder()

```c
InputMethod_ErrorCode OH_TextConfig_SetPlaceholder(InputMethod_TextConfig *config, const char16_t *placeholder, size_t length)
```

**描述**

设置文本配置信息中的占位符文本信息。占位符文本是编辑框中当无用户输入时显示的提示文本，输入法据此感知编辑框的提示内容。

使用场景：在GetTextConfigFunc回调内设置编辑框的占位符提示文本。

使用后效果：设置成功后，输入法将据此感知编辑框的占位提示内容，可用于上下文分析。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，指向即将被设置值的TextConfig实例的指针。不可为NULL，若传入NULL将返回IME_ERR_NULL_POINTER。 |
| const char16_t *placeholder | 输入指针，指向UTF-16编码的双字节字符串。若传NULL指针，则会将占位文本信息设置为空字符串。函数仅读取该数据，不会修改或释放。 |
| size_t length | 输入参数，placeholder指针指向的UTF-16字符个数（不包含结尾符）。取值范围：0到255。1. 如果长度为0，占位文本信息会被设置为空字符串。2. UTF-16编码的最大长度为255个字符（不包含结尾符），超过255个字符会被截断。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)：IME_ERR_OK = 0：表示成功。IME_ERR_NULL_POINTER = 12802000：非预期的空指针，config为NULL。 |

### OH_TextConfig_SetAbilityName()

```c
InputMethod_ErrorCode OH_TextConfig_SetAbilityName(InputMethod_TextConfig *config, const char16_t *abilityName, size_t length)
```

**描述**

设置文本配置信息中的abilityName信息。abilityName用于标识编辑框所属的Ability，输入法据此感知编辑框的业务场景。

使用场景：在GetTextConfigFunc回调内设置编辑框所属Ability的名称。

使用后效果：设置成功后，输入法将据此感知编辑框的业务场景。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，指向即将被设置值的TextConfig实例的指针。不可为NULL。 |
| const char16_t *abilityName | 输入指针，指向UTF-16编码的双字节字符串。若传NULL指针，则会将abilityName设置为空字符串。函数仅读取该数据。 |
| size_t length | 输入参数，abilityName指针指向的UTF-16字符个数（不包含结尾符）。取值范围：0到127。1. 如果长度为0，abilityName会被设置为空字符串。2. UTF-16编码的最大长度为127个字符（不包含结尾符），超过127个字符会被截断。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)：IME_ERR_OK = 0：表示成功。IME_ERR_NULL_POINTER = 12802000：非预期的空指针，config为NULL。 |

### OH_TextConfig_SetConsumeKeyEvents()

```c
InputMethod_ErrorCode OH_TextConfig_SetConsumeKeyEvents(InputMethod_TextConfig *config, bool consumeKeyEvents)
```

**描述**

将编辑框是否具有完整处理字母、字符、功能等按键的能力设置到文本配置信息中。当设置为true时，表示编辑框具备完整处理按键事件的能力，输入法框架将跳过对这些按键的处理；当设置为false时，表示编辑框不具备此能力，按键事件将由输入法框架自行处理。

使用场景：在GetTextConfigFunc回调内设置编辑框是否具有按键事件处理能力。当编辑框已实现完整的按键处理逻辑（如自行处理字母键、字符键、功能键等）时，应设置为true；否则应设置为false。

使用后效果：设置为true后，输入法框架将跳过对字母、字符、功能等按键的处理，由编辑框自行消费这些按键事件；设置为false后，输入法框架将自行处理这些按键事件，编辑框不再消费。

前置条件：config须为有效的InputMethod_TextConfig实例指针。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，指向即将被设置值的[InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md)实例的指针。不可为NULL，若传入NULL将返回IME_ERR_NULL_POINTER。 |
| bool consumeKeyEvents | 输入参数，表示编辑框是否具有完整处理字母、字符、功能等按键的能力。取值范围：true或false。true表示编辑框具备完整处理按键事件的能力，输入法框架将跳过对字母、字符、功能等按键的处理，由编辑框自行消费；false表示编辑框不具备此能力，按键事件将由输入法框架处理。此参数为必需参数，必须设置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，config为NULL。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextConfig_GetInputType()

```c
InputMethod_ErrorCode OH_TextConfig_GetInputType(InputMethod_TextConfig *config, InputMethod_TextInputType *inputType)
```

**描述**

获取文本配置信息中的输入框类型。

使用场景：当需要读取已设置的输入框类型时调用此函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，指向即将被获取值的TextConfig实例的指针。不可为NULL。 |
| [InputMethod_TextInputType](capi-inputmethod-types-capi-h.md#inputmethod_textinputtype) *inputType | 输出指针，表示指向[InputMethod_TextInputType](capi-inputmethod-types-capi-h.md#inputmethod_textinputtype)变量的指针。由调用者分配内存，函数将把输入类型值写入此地址。不可为NULL。取值范围：[InputMethod_TextInputType](capi-inputmethod-types-capi-h.md#inputmethod_textinputtype)枚举值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，config或inputType为NULL。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextConfig_GetEnterKeyType()

```c
InputMethod_ErrorCode OH_TextConfig_GetEnterKeyType(InputMethod_TextConfig *config, InputMethod_EnterKeyType *enterKeyType)
```

**描述**

获取文本配置信息中的回车键功能类型。

使用场景：当需要读取已设置的回车键类型时调用此函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，指向即将被获取值的TextConfig实例的指针。不可为NULL。 |
| [InputMethod_EnterKeyType](capi-inputmethod-types-capi-h.md#inputmethod_enterkeytype) *enterKeyType | 输出指针，表示指向[InputMethod_EnterKeyType](capi-inputmethod-types-capi-h.md#inputmethod_enterkeytype)变量的指针。由调用者分配内存。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，config或enterKeyType为NULL。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextConfig_IsPreviewTextSupported()

```c
InputMethod_ErrorCode OH_TextConfig_IsPreviewTextSupported(InputMethod_TextConfig *config, bool *supported)
```

**描述**

获取文本配置中是否支持预上屏。

使用场景：当需要读取已设置的预上屏支持状态时调用此函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，指向即将被获取值的TextConfig实例的指针。不可为NULL。 |
| bool *supported | 输出指针，用于返回是否支持预上屏。由调用者分配内存。不可为NULL。取值范围：true表示支持预上屏，false表示不支持预上屏。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，config或supported为NULL。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextConfig_GetCursorInfo()

```c
InputMethod_ErrorCode OH_TextConfig_GetCursorInfo(InputMethod_TextConfig *config, InputMethod_CursorInfo **cursorInfo)
```

**描述**

获取文本配置信息中的光标信息。此接口使用双指针参数，函数内部分配内存返回CursorInfo对象。

使用场景：当需要读取已设置的光标信息时调用此函数。

使用后效果：调用成功后，cursorInfo指向由函数内部分配的CursorInfo对象，包含光标位置和高度等信息。

内存管理：cursorInfo为双指针（输出指针），函数内部分配内存创建[InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md)对象并通过此参数返回。返回的CursorInfo对象必须在使用完毕后调用[OH_CursorInfo_Destroy](capi-inputmethod-cursor-info-capi-h.md#oh_cursorinfo_destroy)释放，否则会造成内存泄漏。不可使用free直接释放。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，指向即将被获取值的TextConfig实例的指针。不可为NULL。 |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) **cursorInfo | 输出双指针，用于返回光标信息对象。函数内部分配内存创建[InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md)实例，并通过此双指针返回。不可为NULL。返回的对象必须在使用完毕后调用[OH_CursorInfo_Destroy](capi-inputmethod-cursor-info-capi-h.md#oh_cursorinfo_destroy)释放，不可使用free直接释放，否则会造成内存泄漏。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，config或cursorInfo为NULL。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextConfig_GetTextAvoidInfo()

```c
InputMethod_ErrorCode OH_TextConfig_GetTextAvoidInfo(InputMethod_TextConfig *config, InputMethod_TextAvoidInfo **avoidInfo)
```

**描述**

获取文本配置信息中的避让信息。此接口使用双指针参数，函数内部分配内存返回TextAvoidInfo对象。

使用场景：当需要读取已设置的避让信息时调用此函数。

使用后效果：调用成功后，avoidInfo指向由函数内部分配的TextAvoidInfo对象，包含避让区域的位置和尺寸等信息。

内存管理：avoidInfo为双指针（输出指针），函数内部分配内存创建[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)对象并通过此参数返回。返回的TextAvoidInfo对象必须在使用完毕后调用[OH_TextAvoidInfo_Destroy](capi-inputmethod-text-avoid-info-capi-h.md#oh_textavoidinfo_destroy)释放，否则会造成内存泄漏。不可使用free直接释放。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，表示文本配置信息。不可为NULL。 |
| [InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md) **avoidInfo | 输出双指针，用于返回输入框避让信息对象。函数内部分配内存创建[InputMethod_TextAvoidInfo](capi-inputmethod-inputmethod-textavoidinfo.md)实例，并通过此双指针返回。不可为NULL。返回的对象必须在使用完毕后调用[OH_TextAvoidInfo_Destroy](capi-inputmethod-text-avoid-info-capi-h.md#oh_textavoidinfo_destroy)释放，不可使用free直接释放，否则会造成内存泄漏。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，config或avoidInfo为NULL。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextConfig_GetSelection()

```c
InputMethod_ErrorCode OH_TextConfig_GetSelection(InputMethod_TextConfig *config, int32_t *start, int32_t *end)
```

**描述**

获取文本配置信息中的选区范围信息。

使用场景：当需要读取已设置的选区范围时调用此函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，指向即将被获取值的TextConfig实例的指针。不可为NULL。 |
| int32_t *start | 输出指针，所选文本的起始位置（单位：字符偏移量）。由调用者分配内存。不可为NULL。 |
| int32_t *end | 输出指针，所选文本的结束位置（单位：字符偏移量）。由调用者分配内存。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，config、start或end为NULL。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextConfig_GetWindowId()

```c
InputMethod_ErrorCode OH_TextConfig_GetWindowId(InputMethod_TextConfig *config, int32_t *windowId)
```

**描述**

获取文本配置信息中所属窗口的窗口id。

使用场景：当需要读取已设置的窗口ID时调用此函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，指向即将被获取值的TextConfig实例的指针。不可为NULL。 |
| int32_t *windowId | 输出指针，绑定输入法的应用所属窗口的窗口id。由调用者分配内存。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，config或windowId为NULL。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |

### OH_TextConfig_GetPlaceholder()

```c
InputMethod_ErrorCode OH_TextConfig_GetPlaceholder(InputMethod_TextConfig *config, char16_t *placeholder, size_t *length)
```

**描述**

获取文本配置信息中的占位符文本信息。此接口采用两步调用策略：第一次调用时以NULL作为placeholder参数，length将返回实际占位文本长度；根据返回的长度分配足够内存后第二次调用获取完整内容。

使用场景：当需要读取已设置的占位符文本时调用此函数。

使用后效果：调用成功后，placeholder中将包含完整的占位文本内容，length返回实际长度。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，指向即将被获取值的TextConfig实例的指针。不可为NULL。 |
| char16_t *placeholder | 输出指针，用于存放占位文本信息，该指针内存由调用者分配和维护。采用两步调用策略：第一次可传NULL获取实际长度；第二次传已分配的足够内存获取完整内容。最大支持255个UTF-16字符（不含结尾符），分配时建议预留length+1个元素空间以包含结尾符。 |
| size_t *length | 输入/输出指针，占位文本信息长度（单位：UTF-16字符个数，不包含结尾符）。作为入参时，表示placeholder指向的内存可用长度（最大支持255个字符）；作为出参时，表示实际的占位文本长度。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)：IME_ERR_OK = 0：表示成功。IME_ERR_PARAMCHECK = 401：参数检查失败，可能是placeholder为NULL或length不足，此时length会被设置为实际长度。IME_ERR_NULL_POINTER = 12802000：非预期的空指针，config或length为NULL。 |

### OH_TextConfig_GetAbilityName()

```c
InputMethod_ErrorCode OH_TextConfig_GetAbilityName(InputMethod_TextConfig *config, char16_t *abilityName, size_t *length)
```

**描述**

获取文本配置信息中的abilityName信息。此接口采用两步调用策略：第一次调用时以NULL作为abilityName参数，length将返回实际abilityName长度；根据返回的长度分配足够内存后第二次调用获取完整内容。

使用场景：当需要读取已设置的abilityName时调用此函数。

使用后效果：调用成功后，abilityName中将包含完整的abilityName内容，length返回实际长度。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，指向即将被获取值的TextConfig实例的指针。不可为NULL。 |
| char16_t *abilityName | 输出指针，用于存放abilityName，该指针内存由调用者分配和维护。采用两步调用策略：第一次可传NULL获取实际长度；第二次传已分配的足够内存获取完整内容。最大支持127个UTF-16字符（不含结尾符），分配时建议预留length+1个元素空间。 |
| size_t *length | 输入/输出指针，abilityName长度（单位：UTF-16字符个数，不包含结尾符）。作为入参时，表示abilityName指向的内存可用长度（最大支持127个字符）；作为出参时，表示实际的abilityName长度。不可为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)：<br>     IME_ERR_OK = 0：表示成功。<br>     IME_ERR_PARAMCHECK = 401：参数检查失败。<br>     IME_ERR_NULL_POINTER = 12802000：非预期的空指针。 |

### OH_TextConfig_GetConsumeKeyEvents()

```c
InputMethod_ErrorCode OH_TextConfig_GetConsumeKeyEvents(InputMethod_TextConfig *config, bool *consumeKeyEvents)
```

**描述**

获取文本配置中编辑框是否具有完整处理字母、字符、功能等按键的能力。即读取通过[OH_TextConfig_SetConsumeKeyEvents](#oh_textconfig_setconsumekeyevents)设置的按键事件消费能力配置。

使用场景：当需要读取已设置的按键事件处理能力配置时调用此函数，用于判断编辑框是否具备完整消费按键事件的能力。

使用后效果：调用成功后，consumeKeyEvents将返回编辑框的按键事件处理能力状态。true表示编辑框具备完整处理按键事件的能力，输入法框架将跳过对字母、字符、功能等按键的处理；false表示编辑框不具备此能力，按键事件将由输入法框架处理。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md) *config | 输入指针，指向即将被获取值的[InputMethod_TextConfig](capi-inputmethod-inputmethod-textconfig.md)实例的指针。不可为NULL，若传入NULL将返回IME_ERR_NULL_POINTER。 |
| bool *consumeKeyEvents | 输出指针，用于返回编辑框是否具有完整处理字母、字符、功能等按键的能力。由调用者分配内存。不可为NULL。取值范围：true表示编辑框具备完整处理按键事件的能力，输入法框架将跳过对字母、字符、功能等按键的处理；false表示编辑框不具备此能力，按键事件将由输入法框架处理。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | 返回一个特定的错误码。<br>[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 表示成功。<br>[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - 非预期的空指针，config或consumeKeyEvents为NULL。<br>具体错误码可以参考[InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode)。 |


