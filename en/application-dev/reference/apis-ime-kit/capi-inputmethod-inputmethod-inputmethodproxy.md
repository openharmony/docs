# InputMethod_InputMethodProxy

<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=4c244f2ed12456a4c6059eccff764e442d7872b9 translatedAt=2026-08-12T08:24:38.559Z pushedAt=2026-08-13T12:06:33.943Z -->

```c
typedef struct InputMethod_InputMethodProxy InputMethod_InputMethodProxy
```

## Overview

Provides an interaction proxy object between the app and the input method service. The app can call relevant APIs of the input method service and receive event callbacks from the input method service through this object. This struct is an opaque type. Its internal members shall not be accessed directly. Operations can only be performed through the function interfaces provided by this module.

**Since**: 12

**Related modules:** [InputMethod](capi-inputmethod.md)

**Header file**: [inputmethod_inputmethod_proxy_capi.h](capi-inputmethod-inputmethod-proxy-capi-h.md)

## Struct Purpose

**InputMethod_InputMethodProxy** is the core proxy object for interaction between the app and the input method service. It is used to send requests and notifications to the input method service. With this proxy object, the app can show or hide the keyboard, notify the input method of changes to text selection ranges and configurations in the edit field, update the cursor position, and transmit private command data.

## Lifecycle Management

- Creation: Created by the [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach) function and returned as an output parameter. This object cannot be manually created.

- Destruction: Manual destruction is prohibited. After [OH_InputMethodController_Detach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_detach) is called to terminate attachment, the **InputMethod_InputMethodProxy** object will be automatically released by the system and become invalid.

- Validity: **InputMethod_InputMethodProxy** is only valid between an attach call and the corresponding detach call. After detachment, all functions called via this object return the error code **IME_ERR_DETACHED**, and the object must no longer be used.

- Repeated creation and destruction: Repeated destruction is not supported. Each attach call generates a new **InputMethod_InputMethodProxy** instance, and the corresponding detach call invalidates that instance.

## Usage Notes

- Before calling any **InputMethod_InputMethodProxy**-related functions, ensure that the object has been successfully obtained via [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach) and the detach function has not been called.

- The **inputMethodProxy** pointer must not be **NULL**. Passing a null pointer results in the error code **IME_ERR_NULL_POINTER**. Example: This error occurs if a function is called when the null pointer is not checked beforehand. Check whether the pointer is null before invocation. If it is null, obtain a valid object via the attach function first or abort the call.

- The acquired **inputMethodProxy** pointer shall not be used after the detach function is called. All operations return **IME_ERR_DETACHED**. Example: This error code is returned when any API is called after the detach function is called. Check the lifecycle state. Use the object only between an attach call and the corresponding detach call. Call the attach function again if needed. This object is an opaque type. Its internal members shall not be accessed directly, and memory operations (such as **malloc** and **free**) shall not be performed on it.

- Not thread-safe. Concurrent operations on the same **inputMethodProxy** object in a multi-threaded environment are not recommended. Implement locking protection if multi-threaded access is required.

Related functions:

The following functions can be called via an **InputMethod_InputMethodProxy** object:

| Function | Description |
| -- | -- |
| [OH_InputMethodProxy_ShowKeyboard](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_showkeyboard) | Shows the keyboard. |
| [OH_InputMethodProxy_ShowTextInput](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_showtextinput) | Shows the text input box. |
| [OH_InputMethodProxy_HideKeyboard](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_hidekeyboard) | Hides the keyboard. |
| [OH_InputMethodProxy_NotifySelectionChange](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_notifyselectionchange) | Notifies the input method of changes to the text selection in the text input field. |
| [OH_InputMethodProxy_NotifyConfigurationChange](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_notifyconfigurationchange) | Notifies the input method of configuration changes for the text input field. |
| [OH_InputMethodProxy_NotifyCursorUpdate](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_notifycursorupdate) | Notifies the input method of cursor position updates. |
| [OH_InputMethodProxy_SendPrivateCommand](capi-inputmethod-inputmethod-proxy-capi-h.md#oh_inputmethodproxy_sendprivatecommand) | Sends private command data to the input method. |

Relationships:

- Relationship with **TextEditorProxy**: [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) receives requests and notifications from the input method app, while **InputMethod_InputMethodProxy** sends requests and notifications to the input method service. The two objects are linked when the attach function is called and form a bidirectional communication channel.

- Relationship with **AttachOptions**: [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) is passed in when the attach function is called to configure attachment options (such as whether to show the keyboard and the reason for requesting the keyboard). An **InputMethod_InputMethodProxy** instance is created upon a successful attach call.