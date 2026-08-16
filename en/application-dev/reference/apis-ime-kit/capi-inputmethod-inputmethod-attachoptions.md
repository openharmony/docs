# InputMethod_AttachOptions

<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=4c244f2ed12456a4c6059eccff764e442d7872b9 translatedAt=2026-08-12T08:24:34.683Z pushedAt=2026-08-13T12:06:29.258Z -->

```c
typedef struct InputMethod_AttachOptions InputMethod_AttachOptions
```

## Overview

**InputMethod_AttachOptions** is an opaque type for input method attachment options. It carries configuration parameters when an app attaches to the input method service and controls the initial behavior during attachment.

Purpose: It serves as a mandatory parameter for **OH_InputMethodController_Attach** and **OH_InputMethodController_AttachWithUIContext**, used to configure behavior options for input method attachment, including:

- Whether to automatically show the keyboard upon attachment (**showKeyboard**): Controls whether the keyboard pops up immediately after attachment completes.

- Reason for requesting the keyboard (**requestKeyboardReason**): Identifies the scenario that triggers the input method activation (such as a tap, mouse click, or active app invocation), helping the system optimize the input experience.

Usage scenarios:

- **showKeyboard=true**: Applies to scenarios requiring immediate input after an input box gains focus (e.g., text input box). The keyboard pops up automatically after attachment.

- **showKeyboard=false**: Applies to scenarios where an interaction channel is established first but the keyboard is not needed immediately (e.g., search box). No keyboard appears after attachment; the keyboard can be activated later via **ShowKeyboard**.

- **requestKeyboardReason**: Applies to scenarios where the app needs to inform the system of the trigger reason for input method activation, enabling the system to adopt an appropriate input strategy.

Related functions

| Function | Description |
| -- | -- |
| [OH_AttachOptions_Create](capi-inputmethod-attach-options-capi-h.md#oh_attachoptions_create) | Creates an **AttachOptions** instance. |
| [OH_AttachOptions_CreateWithRequestKeyboardReason](capi-inputmethod-attach-options-capi-h.md#oh_attachoptions_createwithrequestkeyboardreason) | Creates an **AttachOptions** instance and specifies the **requestKeyboardReason**. |
| [OH_AttachOptions_Destroy](capi-inputmethod-attach-options-capi-h.md#oh_attachoptions_destroy) | Destroys an **AttachOptions** instance. |
| [OH_AttachOptions_IsShowKeyboard](capi-inputmethod-attach-options-capi-h.md#oh_attachoptions_isshowkeyboard) | Obtains the **showKeyboard** value. |
| [OH_AttachOptions_GetRequestKeyboardReason](capi-inputmethod-attach-options-capi-h.md#oh_attachoptions_getrequestkeyboardreason) | Obtains the **requestKeyboardReason** value. |

Relationship with other structs:

- **InputMethod_AttachOptions** is one of the mandatory parameters of **OH_InputMethodController_Attach** and **OH_InputMethodController_AttachWithUIContext**. This attach function requires both **InputMethod_TextEditorProxy** and **InputMethod_AttachOptions**.

- The **requestKeyboardReason** member in **InputMethod_AttachOptions** adopts the **InputMethod_RequestKeyboardReason** enumeration type which is defined in [inputmethod_types_capi.h](capi-inputmethod-types-capi-h.md).

- **OH_InputMethodProxy_ShowTextInput** also accepts **InputMethod_AttachOptions** as a parameter, for requesting to show the keyboard again under an attached state and specifying the request reason.

**Since**: 12

**Related module**: [InputMethod](capi-inputmethod.md)

**Header file**: [inputmethod_attach_options_capi.h](capi-inputmethod-attach-options-capi-h.md)