# inputmethod_inputmethod_proxy_capi.h

<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=4c244f2ed12456a4c6059eccff764e442d7872b9 translatedAt=2026-08-13T12:26:43.905Z pushedAt=2026-08-15T06:11:51.322Z -->

## Overview

Provides methods for using the input method, allowing you to send requests and notifications to the input method app. It applies to app development scenarios requiring capabilities such as showing or hiding the input method and sending notifications for configuration changes.

**File to include**: <inputmethod/inputmethod_inputmethod_proxy_capi.h>

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](capi-inputmethod.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) | InputMethod_InputMethodProxy | Input method proxy object, used to call input method methods. |

### Functions

| Name| Description|
| -- | -- |
| [InputMethod_ErrorCode OH_InputMethodProxy_ShowKeyboard(InputMethod_InputMethodProxy *inputMethodProxy)](#oh_inputmethodproxy_showkeyboard) | Shows the keyboard.|
| [InputMethod_ErrorCode OH_InputMethodProxy_ShowTextInput(InputMethod_InputMethodProxy *inputMethodProxy, InputMethod_AttachOptions *options)](#oh_inputmethodproxy_showtextinput) | Shows the text input box.|
| [InputMethod_ErrorCode OH_InputMethodProxy_HideKeyboard(InputMethod_InputMethodProxy *inputMethodProxy)](#oh_inputmethodproxy_hidekeyboard) | Hides the keyboard.|
| [InputMethod_ErrorCode OH_InputMethodProxy_NotifySelectionChange(InputMethod_InputMethodProxy *inputMethodProxy, char16_t text[], size_t length, int start, int end)](#oh_inputmethodproxy_notifyselectionchange) | Notifies the input method of selection changes in the text input box. |
| [InputMethod_ErrorCode OH_InputMethodProxy_NotifyConfigurationChange(InputMethod_InputMethodProxy *inputMethodProxy,InputMethod_EnterKeyType enterKey, InputMethod_TextInputType textType)](#oh_inputmethodproxy_notifyconfigurationchange) | Notifies the input method of configuration changes for the text input box.|
| [InputMethod_ErrorCode OH_InputMethodProxy_NotifyCursorUpdate(InputMethod_InputMethodProxy *inputMethodProxy, InputMethod_CursorInfo *cursorInfo)](#oh_inputmethodproxy_notifycursorupdate) | Notifies the input method of cursor position updates.|
| [InputMethod_ErrorCode OH_InputMethodProxy_SendPrivateCommand(InputMethod_InputMethodProxy *inputMethodProxy, InputMethod_PrivateCommand *privateCommand[], size_t size)](#oh_inputmethodproxy_sendprivatecommand) | Sends private command data.|

## Function Description

### OH_InputMethodProxy_ShowKeyboard()

```c
InputMethod_ErrorCode OH_InputMethodProxy_ShowKeyboard(InputMethod_InputMethodProxy *inputMethodProxy)
```

**Description**

Shows the keyboard. After this function is called, the system requests the input method app to pop up the soft keyboard UI for text input.

Usage scenarios: This function is called when an app needs to actively bring up the keyboard for users to enter text, for example, when the edit box gains focus and requires the keyboard to be shown.

Use effect: If the call succeeds, the input method app displays the soft keyboard UI. If the call fails, a corresponding error code is returned, and you need to handle the error based on the returned code.

Precondition: You must first call [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach) to obtain the **inputMethodProxy** instance, and the instance must be in the attached state.

Lifecycle management: The **inputMethodProxy** instance is created via [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach) and cannot be destroyed manually. After [OH_InputMethodController_Detach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_detach) is called to terminate the attachment, **inputMethodProxy** becomes invalid. Any subsequent calls to this function return the error code **IME_ERR_DETACHED**.

Call sequence: **OH_InputMethodController_Attach** → **OH_InputMethodProxy_ShowKeyboard** → **OH_InputMethodProxy_HideKeyboard** → **OH_InputMethodController_Detach**

Thread safety: Not thread-safe. Concurrent operations on the same **inputMethodProxy** object in a multi-threaded environment are not recommended. Implement locking protection if multi-threaded access is required.

**Since**: 12

**Parameters**

| Name                                               | Description|
|----------------------------------------------------| -- |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) *inputMethodProxy | Input pointer pointing to an [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) instance. The instance is obtained via a call to [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach). This pointer cannot be **NULL**. Passing a null pointer returns the error code **IME_ERR_NULL_POINTER**. The pointer becomes invalid after detachment and shall not be used to call any **InputMethodProxy**-related functions. |

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | Returns a specific error code.<br>- [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Success. The keyboard has been requested to show.<br>- [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method client error, possibly caused by an internal client exception.<br>- [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method service error, possibly indicating the input method management service is unavailable.<br>- [IME_ERR_DETACHED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Not attached to the input method. The detach function has been called; you need to perform attachment again before further use.<br>- [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Unexpected null pointer. The passed **inputMethodProxy** is **NULL**.<br>For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode). |

### OH_InputMethodProxy_ShowTextInput()

```c
InputMethod_ErrorCode OH_InputMethodProxy_ShowTextInput(InputMethod_InputMethodProxy *inputMethodProxy, InputMethod_AttachOptions *options)
```

**Description**

Shows the text input box. Unlike **ShowKeyboard**, this API uses **AttachOptions** to specify the reason for requesting keyboard input. The system determines whether to pop up the keyboard based on this reason.

Usage scenarios: This function is called when an app needs to request the text input interface under specific scenarios, such as switching input boxes or resuming input. It is especially suitable for scenarios where **InputMethod_RequestKeyboardReason** needs to be carried.

Use effect: If the call succeeds, the system determines whether to pop up the keyboard and activate text input according to **RequestKeyboardReason** contained in **options**. If the call fails, a corresponding error code is returned.

Precondition: You must first call [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach) to obtain the **inputMethodProxy instance**, and the instance must be in the attached state. The **options** parameter must be created through [OH_AttachOptions_Create](capi-inputmethod-attach-options-capi-h.md#oh_attachoptions_create).

Lifecycle management: The **inputMethodProxy** instance is created via [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach) and cannot be destroyed manually. The instance becomes invalid after detachment. The lifecycle of **options** is managed by you. Call [OH_AttachOptions_Destroy](capi-inputmethod-attach-options-capi-h.md#oh_attachoptions_destroy) to destroy it after use.

Thread safety: Not thread-safe. Concurrent operations on the same **inputMethodProxy** object in a multi-threaded environment are not recommended.

**Since**: 15

**Parameters**

| Parameter | Description |
| -- | -- |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) *inputMethodProxy | Input pointer pointing to an [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) instance. The instance is obtained via a call to [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach). This pointer cannot be **NULL**. Passing a null pointer returns the error code **IME_ERR_NULL_POINTER**. The pointer becomes invalid after detachment. |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) *options | Input pointer pointing to an  [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) instance, used to obtain configuration options. This pointer cannot be **NULL**. Passing a null pointer returns the error code **IME_ERR_NULL_POINTER**. For this API, only the [InputMethod_RequestKeyboardReason](capi-inputmethod-types-capi-h.md#inputmethod_requestkeyboardreason) property needs to be considered, which indicates the reason for requesting keyboard input. The **ShowKeyboard** property in **AttachOptions** is always treated as **true** for this API and does not need additional attention. |

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | Returns a specific error code.<br>- [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Success.<br>- [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method client error.<br>- [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method service error.<br>- [IME_ERR_DETACHED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Not attached to the input method. The detach function has been called; you need to perform attachment again before further use.<br>- [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Unexpected null pointer. **inputMethodProxy** or **options** is **NULL**.<br>For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode). |

### OH_InputMethodProxy_HideKeyboard()

```c
InputMethod_ErrorCode OH_InputMethodProxy_HideKeyboard(InputMethod_InputMethodProxy *inputMethodProxy)
```

**Description**

Hides the keyboard. After this function is called, the system requests the input method app to close the soft keyboard.

Usage scenarios: This function is called when an app needs to actively hide the keyboard, for example, when the edit box loses focus or the user completes input and the keyboard needs to be hidden.

Use effect: If the call succeeds, the input method app hides the soft keyboard UI. If the call fails, a corresponding error code is returned.

Precondition: You must first call [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach) to obtain the **inputMethodProxy** instance, and the instance must be in the attached state.

Lifecycle management: The **inputMethodProxy** instance is created via [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach) and cannot be destroyed manually. The instance becomes invalid after detachment, and subsequent calls to this function return **IME_ERR_DETACHED**.

Thread safety: Not thread-safe. Concurrent operations on the same **inputMethodProxy** object in a multi-threaded environment are not recommended.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) *inputMethodProxy | Input pointer pointing to an [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) instance. The instance is obtained via a call to [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach). This pointer cannot be **NULL**. Passing a null pointer returns the error code **IME_ERR_NULL_POINTER**. The pointer becomes invalid after the detach function is called. |

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | Returns a specific error code.<br>- [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Success. The keyboard has been requested to hide.<br>- [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method client error.<br>- [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method service error.<br>- [IME_ERR_DETACHED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Not attached to the input method. The detach function has been called; you need to perform attachment again before further use.<br>- [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Unexpected null pointer.<br>For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).  |

### OH_InputMethodProxy_NotifySelectionChange()

```c
InputMethod_ErrorCode OH_InputMethodProxy_NotifySelectionChange(InputMethod_InputMethodProxy *inputMethodProxy, char16_t text[], size_t length, int start, int end)
```

**Description**

Notifies the input method of selection changes in the text input box. When the text content, cursor position, or text selection inside the input field changes, this API is called to send change information to the input method app, enabling the input method to perceive the text state of the edit box.

Usage scenarios: This function is called when the text content in the edit box is modified, the cursor moves, or the user’s text selection changes. This ensures the text state remains synchronized between the input method app and the edit box.

Use effect: If the call succeeds, the input method app receives the selection change information and updates its internal state accordingly, including candidate words and text suggestions. If the call fails, a corresponding error code is returned.

Precondition: You must first call [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach) to obtain the **inputMethodProxy** instance, and the instance must be in the attached state.

Lifecycle management: The **inputMethodProxy** instance is created via [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach) and cannot be destroyed manually. The instance becomes invalid after detachment.

Memory management: The **text** parameter is an input pointer with memory allocated by you. The function only reads the data and does not modify or release it. You are responsible for managing the lifecycle of the memory for the **text** array.

Thread safety: Not thread-safe. Concurrent operations on the same **inputMethodProxy** object in a multi-threaded environment are not recommended.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) *inputMethodProxy | Input pointer pointing to an [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) instance. The instance is obtained via a call to [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach). This pointer cannot be **NULL**. Passing a null pointer returns the error code **IME_ERR_NULL_POINTER**. The pointer becomes invalid after detachment. |
| char16_t text[] | Input pointer carrying all input text, encoded in UTF-16. Memory is allocated by you, and the function only reads the data. This pointer cannot be **NULL**. The upper limit is 8,192 char16_t characters, equivalent to 16,384 bytes. Exceeding this limit returns **IME_ERR_PARAMCHECK**. |
| size_t length | Input parameter indicating the number of char16_t characters in **text**. Value range: greater than **0** and no more than **8192**. A value exceeding 8,192 returns the error code **IME_ERR_PARAMCHECK**. |
| int start | Input parameter representing the start position of the selected text (char16_t offset, starting from **0**). Value range: greater than or equal to **0** and less than or equal to **end**. Constraint: **start** shall be less than or equal to **end** and shall not exceed the actual length of **text**. |
| int end | Input parameter representing the end position of the selected text (char16_t offset, starting from **0**). Value range: greater than or equal to **start** and less than or equal to the actual length of **text**. Constraint: If no text is selected, **start** equals **end**, which indicates the cursor position. |

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | Returns a specific error code.<br>- [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Success.<br> - [IME_ERR_PARAMCHECK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Invalid parameters. Possible causes include the length exceeding the 8K limit or invalid range of **start** or **end**. Verify whether all parameters are within valid ranges.<br>- [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method client error.<br>- [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method service error.<br>- [IME_ERR_DETACHED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Not attached to the input method. Perform attachment again after detachment.<br>- [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Unexpected null pointer. **inputMethodProxy** is **NULL**.<br>For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode). |

### OH_InputMethodProxy_NotifyConfigurationChange()

```c
InputMethod_ErrorCode OH_InputMethodProxy_NotifyConfigurationChange(InputMethod_InputMethodProxy *inputMethodProxy,InputMethod_EnterKeyType enterKey, InputMethod_TextInputType textType)
```

**Description**

Notifies the input method of configuration changes for the text input box. When the enter key type or text input type of the edit box changes, this API is called to send updated configuration information to the input method app, enabling the input method to adjust the keyboard layout and input behavior.

Usage scenarios: This function is called when the edit box's input type (for example, switching from text mode to numeric mode) or enter key type changes (for example, switching from **Done** to **Search**).

Use effect: If the call succeeds, the input method app adjusts the keyboard layout and enter key display based on the new configuration. If the call fails, a corresponding error code is returned.

Precondition: You must first call [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach) to obtain the **inputMethodProxy** instance, and the instance must be in the attached state.

Lifecycle management: The **inputMethodProxy** instance is created via [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach) and cannot be destroyed manually. The instance becomes invalid after detachment.

Thread safety: Not thread-safe. Concurrent operations on the same **inputMethodProxy** object in a multi-threaded environment are not recommended.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) *inputMethodProxy | Input pointer pointing to an [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) instance. The instance is obtained via a call to [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach). This pointer cannot be **NULL**. Passing a null pointer returns the error code **IME_ERR_NULL_POINTER**. The pointer becomes invalid after detachment. |
| [InputMethod_EnterKeyType](capi-inputmethod-types-capi-h.md#inputmethod_enterkeytype) enterKey | 	Input parameter indicating the enter key type. Valid values belong to the [InputMethod_EnterKeyType](capi-inputmethod-types-capi-h.md#inputmethod_enterkeytype) enumeration, such as **IME_ENTER_KEY_UNSPECIFIED**, **IME_ENTER_KEY_GO**, and **IME_ENTER_KEY_SEARCH**. The input method adjusts the label and behavior of the enter key accordingly. |
| [InputMethod_TextInputType](capi-inputmethod-types-capi-h.md#inputmethod_textinputtype) textType | Input parameter indicating the input type of the edit box. Valid values belong to the [InputMethod_TextInputType](capi-inputmethod-types-capi-h.md#inputmethod_textinputtype) enumeration, such as **IME_TEXT_INPUT_TYPE_UNSPECIFIED**, **IME_TEXT_INPUT_TYPE_TEXT**, and **IME_TEXT_INPUT_TYPE_NUMBER**. The input method switches the keyboard layout accordingly (for example, numeric keyboard and text keyboard). |

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | Returns a specific error code.<br>- [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Success.<br> - [IME_ERR_PARAMCHECK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Invalid parameters. Possible causes include an illegal value of **enterKey** or **textType**. Verify whether all enumerated values are within valid ranges.<br>- [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method client error.<br>- [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method service error.<br>- [IME_ERR_DETACHED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Not attached to the input method. Perform attachment again after detachment.<br>- [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Unexpected null pointer.<br>For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode). |

### OH_InputMethodProxy_NotifyCursorUpdate()

```c
InputMethod_ErrorCode OH_InputMethodProxy_NotifyCursorUpdate(InputMethod_InputMethodProxy *inputMethodProxy, InputMethod_CursorInfo *cursorInfo)
```

**Description**

Notifies the input method of cursor position changes. When the cursor position in the edit box changes, this API is called to send updated cursor information to the input method app, enabling the input method to adjust the display position of the candidate word window based on the cursor location.

Usage scenarios: This function is called when the cursor moves within the edit box, for example, when the user taps different positions inside the edit box or when the cursor is moved programmatically.

Use effect: If the call succeeds, the input method app receives the updated cursor information and adjusts the positioning of the candidate word window accordingly. If the call fails, a corresponding error code is returned.

Precondition: You must first call [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach) to obtain the **inputMethodProxy** instance. **cursorInfo** must be created and configured with relevant properties via [OH_CursorInfo_Create](capi-inputmethod-cursor-info-capi-h.md#oh_cursorinfo_create).

Lifecycle management: The **inputMethodProxy** instance is created via the attach function and cannot be destroyed manually. The instance becomes invalid after detachment. The lifecycle of **cursorInfo** is managed by you. After use, you need to call [OH_CursorInfo_Destroy](capi-inputmethod-cursor-info-capi-h.md#oh_cursorinfo_destroy) to destroy it.

Thread safety: Not thread-safe. Concurrent operations on the same **inputMethodProxy** object in a multi-threaded environment are not recommended.

**Since**: 12

**Parameters**

| Parameter | Description |
| -- | -- |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) *inputMethodProxy | Input pointer pointing to an [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) instance. The instance is obtained via a call to [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach). This pointer cannot be **NULL**. Passing a null pointer returns the error code **IME_ERR_NULL_POINTER**. The pointer becomes invalid after detachment. |
| [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) *cursorInfo | Input pointer pointing to an [InputMethod_CursorInfo](capi-inputmethod-inputmethod-cursorinfo.md) instance that holds cursor information. This pointer cannot be **NULL**. Passing a null pointer returns the error code **IME_ERR_NULL_POINTER**. cursorInfo is created by you via [OH_CursorInfo_Create](capi-inputmethod-cursor-info-capi-h.md#oh_cursorinfo_create). The function only reads internal data and does not modify or release it. After use, you need to call [OH_CursorInfo_Destroy](capi-inputmethod-cursor-info-capi-h.md#oh_cursorinfo_destroy) to release **cursorInfo**. |

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | Returns a specific error code.<br>- [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Success.<br> - [IME_ERR_PARAMCHECK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Invalid parameters. The data inside **cursorInfo** may be invalid. Verify the cursor information parameters.<br>- [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method client error.<br>- [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method service error.<br>- [IME_ERR_DETACHED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Not attached to the input method. Perform attachment again after detachment.<br>- [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Unexpected null pointer. Either **inputMethodProxy** or **cursorInfo** is **NULL**.<br>For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode). |

### OH_InputMethodProxy_SendPrivateCommand()

```c
InputMethod_ErrorCode OH_InputMethodProxy_SendPrivateCommand(InputMethod_InputMethodProxy *inputMethodProxy, InputMethod_PrivateCommand *privateCommand[], size_t size)
```

**Description**

Sends private command data. This API is used to send custom private command data to the input method app, implementing a private communication protocol between the app and the input method.

Usage scenarios: This function is called when the app needs to transmit custom private data to the input method app, such as service-specific commands and configuration parameters. It applies to scenarios where a private communication protocol is defined between the app and the input method.

Use effect: If the call succeeds, the input method app receives the private command data through the [OH_TextEditorProxy_ReceivePrivateCommandFunc](capi-inputmethod-text-editor-proxy-capi-h.md#oh_texteditorproxy_receiveprivatecommandfunc) callback. If the call fails, the corresponding error code is returned.

Precondition: You must first call [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach) to obtain the **inputMethodProxy** instance, and the instance must be in the attached state.

Lifecycle management: The **inputMethodProxy** instance is created via the attach function and cannot be destroyed manually. The instance becomes invalid after detachment. The lifecycle of each element in the **privateCommand** array is managed by you. After use, you need to call [OH_PrivateCommand_Destroy](capi-inputmethod-private-command-capi-h.md#oh_privatecommand_destroy) to destroy each element one by one.

Constraints: The **privateCommand** array can contain a maximum of five command objects (the maximum value of **size** is **5**). Exceeding this limit returns **IME_ERR_PARAMCHECK**. The maximum size of a single command object is 32 KB; exceeding this limit may cause data transmission failure.

Thread safety: Not thread-safe. Concurrent operations on the same **inputMethodProxy** object in a multi-threaded environment are not recommended.

**Since**: 12

**Parameters**

| Parameter | Description |
| -- | -- |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) *inputMethodProxy | Input pointer pointing to an [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) instance. The instance is obtained via a call to [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach). This pointer cannot be **NULL**. Passing a null pointer returns the error code **IME_ERR_NULL_POINTER**. The pointer becomes invalid after detachment. |
| [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) *privateCommand[] | Input pointer for the private command array. Each element is a pointer to an [InputMethod_PrivateCommand](capi-inputmethod-inputmethod-privatecommand.md) instance. Instances are created and memory is allocated by you, and the function only reads the data. This pointer cannot be **NULL**. The maximum size of a single command object is 32 KB (total size, including **key** and **value**). Exceeding this limit may lead to transmission failure. The array supports a maximum length of 5 (the maximum value of the **size** parameter is **5**). |
| size_t size | Input parameter indicating the number of elements in the private command array. Value range: greater than 0 and no more than 5. A value exceeding **5** returns the error code **IME_ERR_PARAMCHECK**. |

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | Returns a specific error code.<br>- [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Success. The private command has been sent.<br> - [IME_ERR_PARAMCHECK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Invalid parameters. Possible causes include **size** exceeding 5, a null **privateCommand**, or a single command exceeding the 32 KB limit. Verify the parameter values.<br>- [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method client error.<br>- [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method service error.<br>- [IME_ERR_DETACHED](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Not attached to the input method. Perform attachment again after detachment.<br>- [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Unexpected null pointer. Either **inputMethodProxy** or **privateCommand** is **NULL**.<br>For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) |