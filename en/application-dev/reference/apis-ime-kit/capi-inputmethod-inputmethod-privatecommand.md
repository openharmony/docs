# InputMethod_PrivateCommand

<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=4c244f2ed12456a4c6059eccff764e442d7872b9 translatedAt=2026-08-12T08:24:39.810Z pushedAt=2026-08-13T12:19:01.343Z -->

```c
typedef struct InputMethod_PrivateCommand InputMethod_PrivateCommand
```

## Overview

Represents a private command struct adopting the key-value mechanism. It serves as a carrier for transmitting private data between the text input box and the input method app. It can be used to deliver custom commands, extended capability parameters, and scenario-specific data, improving the extensibility and compatibility of input method features. Each **PrivateCommand** instance contains a key (identifier string) and a value (boolean, integer or string; only one type can be selected). The data type of the value is indicated by **InputMethod_CommandValueType**.

Purpose: Transmits private data between the input method app and the edit box client to enable custom communication between the two sides. The input method app sends private commands to the edit box client via **OH_InputMethodProxy_SendPrivateCommand**. The edit box client receives private commands from the input method app through the **OH_TextEditorProxy_ReceivePrivateCommandFunc** callback. Each **PrivateCommand** instance carries one piece of key-value private data. Up to five instances can be sent in a single transmission. The total size of all private data and key values in one transmission is limited to 32 KB.

Usage scenarios:

- The input method app sends private commands to the edit box: The input method app creates a **PrivateCommand** instance and sends it to the edit box client via [OH_InputMethodProxy_SendPrivateCommand](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_sendprivatecommand) with the key and value set.

- The edit box client receives private commands: The edit box client receives an array of **PrivateCommand** instances from the input method app through the [OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc) callback, and traverses the array to parse the key and value of each instance.

**Since**: 12

**Related module**: [InputMethod](capi-inputmethod.md)

**Header file**: [inputmethod_private_command_capi.h](capi-inputmethod-private-command-capi-h.md)

Related functions

| Function | Description |
| --- | --- |
| [OH_PrivateCommand_Create](capi-inputmethod-private-command-capi-h.md#oh_privatecommand_create) | Creates an **InputMethod_PrivateCommand** instance. |
| [OH_PrivateCommand_Destroy](capi-inputmethod-private-command-capi-h.md#oh_privatecommand_destroy) | Destroys an **InputMethod_PrivateCommand** instance. |
| [OH_PrivateCommand_SetKey](capi-inputmethod-private-command-capi-h.md#oh_privatecommand_setkey) | Sets the key value. |
| [OH_PrivateCommand_SetBoolValue](capi-inputmethod-private-command-capi-h.md#oh_privatecommand_setboolvalue) | Sets the boolean-type value. |
| [OH_PrivateCommand_SetIntValue](capi-inputmethod-private-command-capi-h.md#oh_privatecommand_setintvalue) | Sets the integer-type value. |
| [OH_PrivateCommand_SetStrValue](capi-inputmethod-private-command-capi-h.md#oh_privatecommand_setstrvalue) | Sets the string-type value. |
| [OH_PrivateCommand_GetKey](capi-inputmethod-private-command-capi-h.md#oh_privatecommand_getkey) | Obtains the key value. |
| [OH_PrivateCommand_GetValueType](capi-inputmethod-private-command-capi-h.md#oh_privatecommand_getvaluetype) | Obtains the data type of the value. |
| [OH_PrivateCommand_GetBoolValue](capi-inputmethod-private-command-capi-h.md#oh_privatecommand_getboolvalue) | Obtains the boolean-type value. |
| [OH_PrivateCommand_GetIntValue](capi-inputmethod-private-command-capi-h.md#oh_privatecommand_getintvalue) | Obtains the integer-type value. |
| [OH_PrivateCommand_GetStrValue](capi-inputmethod-private-command-capi-h.md#oh_privatecommand_getstrvalue) | Obtains the string-type value. |

Related APIs:

| API | Description |
| --- | --- |
| [OH_InputMethodProxy_SendPrivateCommand](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_sendprivatecommand) | Sends private commands from the input method app to the edit box client. An array of **PrivateCommand** instances is passed as a parameter. Up to five instances are allowed, and the total size of data is limited to 32 KB. |
| [OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc) | Callback API for the edit box client to receive private commands. An array of **PrivateCommand** instances is passed as a parameter. Memory for the instances is released after the callback returns. |

Related Enums

| Enum | Description |
| --- | --- |
| [InputMethod_CommandValueType](capi-inputmethod-types-capi-h.md#inputmethod_commandvaluetype) | Enumerates the data types of the value in **PrivateCommand** (**NONE**/**STRING**/**BOOL**/**INT32**). |