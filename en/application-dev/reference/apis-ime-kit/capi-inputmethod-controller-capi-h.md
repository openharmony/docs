# inputmethod_controller_capi.h

<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=4c244f2ed12456a4c6059eccff764e442d7872b9 translatedAt=2026-08-10T06:45:22.474Z pushedAt=2026-08-12T08:19:37.278Z -->

## Overview

Provides methods for attaching to and detaching from the input method. It serves as the core entry point for interactions between apps and the input method service.

Functionality: **OH_InputMethodController_Attach** is used to attach the app to the input method service and establish a bidirectional communication channel. **OH_InputMethodController_Detach** is used to detach the app from the input method service, close the communication channel, and release associated resources.

Usage scenarios: Applicable to NDK-based apps that implement self-drawn input boxes. Apps shall attach to the input method service upon startup or when the input box gains focus, and detach from the service upon app exit or when the input box loses focus.

Use effect: After a successful call to **OH_InputMethodController_Attach**, the app can interact with the input method via the returned **InputMethodProxy** (such as showing or hiding the keyboard and notifying cursor updates). Meanwhile, the input method can send notifications such as text insertion and deletion to the app through callbacks from **TextEditorProxy**. After **OH_InputMethodController_Detach** is called, the communication channel is closed and **inputMethodProxy** becomes invalid.

**File to include**: <inputmethod/inputmethod_controller_capi.h>

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](capi-inputmethod.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [InputMethod_ErrorCode OH_InputMethodController_Attach(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_AttachOptions *options, InputMethod_InputMethodProxy **inputMethodProxy)](#oh_inputmethodcontroller_attach) | Attaches the app to the input method service. This function shall be called after **TextEditorProxy** and **AttachOptions** are created. Upon successful attachment, **InputMethodProxy** is returned for subsequent interactions. This function must be used in pair with **OH_InputMethodController_Detach**. |
| [InputMethod_ErrorCode OH_InputMethodController_AttachWithUIContext(ArkUI_ContextHandle context, InputMethod_TextEditorProxy *textEditorProxy, InputMethod_AttachOptions *options, InputMethod_InputMethodProxy **inputMethodProxy)](#oh_inputmethodcontroller_attachwithuicontext) | Attaches the app to the input method service with UI context information. Suitable for scenarios where the input method needs to be associated with a specific UI page (for example, specifying the target page in multi-window scenarios). It shall be called after **TextEditorProxy** and **AttachOptions** are created. It must be paired with **OH_InputMethodController_Detach**. |
| [InputMethod_ErrorCode OH_InputMethodController_Detach(InputMethod_InputMethodProxy *inputMethodProxy)](#oh_inputmethodcontroller_detach) | Detaches the app from the input method service. This function must be called after **OH_InputMethodController_Attach** or **AttachWithUIContext** is called. After detachment, **inputMethodProxy** becomes invalid and cannot be used further. |

## Function Description

### OH_InputMethodController_Attach()

```c
InputMethod_ErrorCode OH_InputMethodController_Attach(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_AttachOptions *options, InputMethod_InputMethodProxy **inputMethodProxy)
```

**Description**

Attaches the app to the input method service and establishes a bidirectional communication channel between the app and the input method. After successful attachment, the app can actively send requests and notifications to the input method via the returned **InputMethodProxy**. Meanwhile, the input method can send notifications such as text insertion and deletion to the app through callback functions registered in **TextEditorProxy**.

Preconditions:

1. An **InputMethod_TextEditorProxy** instance shall first be created via **OH_TextEditorProxy_Create**, and required callbacks (including **InsertTextFunc**, **DeleteForwardFunc**, **GetTextConfigFunc**, etc.) shall be registered via the *OH_TextEditorProxy_SetXXXFunc* series of functions.

2. An **InputMethod_AttachOptions** instance shall first be created via **OH_AttachOptions_Create** or **OH_AttachOptions_CreateWithRequestKeyboardReason**.

3. Callback functions registered in **TextEditorProxy** shall be properly implemented; otherwise, interactions with the input method will be incomplete.

Paired calls:

- After calling **OH_InputMethodController_Attach**, **OH_InputMethodController_Detach** shall be called to detach the app once related work completes.

- Failing to call **OH_InputMethodController_Detach** will cause input method resource leaks.

- It is recommended that you call **OH_InputMethodController_Detach** promptly when the app exits or the input box no longer requires the input method.

Calling sequence:

1. **OH_TextEditorProxy_Create** → Create **TextEditorProxy**.

2. *OH_TextEditorProxy_SetXXXFunc* → Register callback functions.

3. **OH_AttachOptions_Create** → Create **AttachOptions**.

4. **OH_InputMethodController_Attach** → Attach to the input method (**InputMethodProxy** is returned).

5. **OH_InputMethodProxy_ShowKeyboard**, **NotifyCursorUpdate**, etc. → Use input method features.

6. **OH_InputMethodController_Detach** → Detach from the input method.

7. **OH_TextEditorProxy_Destroy**/**OH_AttachOptions_Destroy** → Destroy created objects.

Lifecycle management:

- **textEditorProxy**: You manage its lifecycle. If **OH_InputMethodController_Attach** succeeds, **textEditorProxy** shall not be released until the subsequent **OH_InputMethodController_Attach** or **OH_InputMethodController_Detach** completes. Otherwise, invalid memory access will occur when the input method triggers callbacks.

- **options**: You manage its lifecycle. **options** can be destroyed immediately via **OH_AttachOptions_Destroy** after **OH_InputMethodController_Attach** is called, as configuration information within **options** has been fully read during the attachment process.

- **inputMethodProxy**: Memory is allocated by **OH_InputMethodController_Attach** through the double-pointer output parameter. You shall keep **inputMethodProxy** valid before calling **OH_InputMethodController_Detach**. This pointer shall not be used any longer after **OH_InputMethodController_Detach** is called.

Thread safety: Not thread-safe. It is recommended that you call the function on the main thread.

**Since**: 12

**Parameters**

| Name | Description |
| -- | -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Input pointer pointing to an **InputMethod_TextEditorProxy** instance. Meaning/functionality: Acts as the carrier through which the app receives callback notifications from the input method. After attachment, the input method interacts with the app via the callback functions registered within this object. Usage scenarios: Before attaching to the input method, the app shall create **TextEditorProxy** and register required callback functions. Use effect: If **OH_InputMethodController_Attach** succeeds, the input method sends notifications to the app through callbacks inside this object. If the call fails, this object remains unaffected and can be reused.<br>Precondition: Shall be created via **OH_TextEditorProxy_Create**, with callbacks registered through the *SetXXXFunc* series of functions.<br>**NULL** pointer handling: Must not be **NULL**. Passing **NULL** returns **IME_ERR_NULL_POINTER**.<br>Lifecycle management: Managed by you. If attachment succeeds, **textEditorProxy** shall not be released until the subsequent **OH_InputMethodController_Attach** or **OH_InputMethodController_Detach** completes. Otherwise, undefined behavior will occur when the input method triggers callbacks and accesses freed memory.<br>Memory allocation responsibility: Allocated by you via **OH_TextEditorProxy_Create** and released via **OH_TextEditorProxy_Destroy**. |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) *options | Input pointer pointing to an **InputMethod_AttachOptions** instance. Meaning/functionality: Specifies behavior configuration for attaching to the input method, including whether to show the keyboard upon attachment and the reason for requesting the keyboard. Usage scenarios: Create and configure **AttachOptions** before attachment to control keyboard display behavior during attachment. Use effect: **OH_InputMethodController_Attach** reads configuration parameters from **options** to determine attachment behavior.<br>Precondition: Shall be created via **OH_AttachOptions_Create** or **OH_AttachOptions_CreateWithRequestKeyboardReason**.<br>Null pointer handling: Must not be **NULL**. Passing **NULL** returns **IME_ERR_NULL_POINTER**.<br>Lifecycle management: **options** can be destroyed immediately after **OH_InputMethodController_Attach** completes, as all configuration information is fully read during the attachment process. It is recommended that you call **OH_AttachOptions_Destroy** to free memory after **OH_InputMethodController_Attach** succeeds.<br>Memory allocation responsibility: Allocated by you via the corresponding create function and released via **OH_AttachOptions_Destroy**. |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) **inputMethodProxy | Output double pointer pointing to **InputMethod_InputMethodProxy**. Meaning/functionality: Receives the **InputMethodProxy** instance returned upon successful calling of **OH_InputMethodController_Attach**. This instance serves as the communication channel for the app to actively send requests and notifications to the input method. Usage scenarios: After **OH_InputMethodController_Attach** succeeds, you can obtain **InputMethodProxy** via this pointer which shall be passed to subsequent functions such as **ShowKeyboard**, **HideKeyboard**, and **NotifyCursorUpdate**. Use effect: If **OH_InputMethodController_Attach** succeeds, *inputMethodProxy is assigned a valid **InputMethodProxy** pointer. If the call fails, the value of *inputMethodProxy is indeterminate and shall not be used.<br>Double-pointer explanation: This is a pointer-to-pointer parameter. Memory for **InputMethodProxy** is allocated inside **OH_InputMethodController_Attach**, and the address of the created object is delivered to you via this double pointer. You need to supply the address of a valid pointer variable and cannot pass **NULL**.<br>Null pointer handling: **inputMethodProxy** must not be **NULL**. Passing **NULL** will return **IME_ERR_NULL_POINTER**.<br>Memory management: Memory for **InputMethodProxy** is allocated internally by **OH_InputMethodController_Attach**. Its lifecycle is managed by the framework until **OH_InputMethodController_Detach** completes. You shall not release this memory manually. Memory referenced by **inputMethodProxy** will be freed after **OH_InputMethodController_Detach** is called, and this pointer shall no longer be used.<br>Parameter constraints: This pointer is only valid when **OH_InputMethodController_Attach** returns **IME_ERR_OK**. It becomes invalid immediately after **OH_InputMethodController_Detach** is called. Continued use will result in undefined behavior or crashes. |

**Returns**

| Type | Description |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | Returns a specific error code.<br>-[IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Success. *inputMethodProxy is valid and can be used for subsequent interactions.<br>-[IME_ERR_PARAMCHECK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Parameter error. Check whether **textEditorProxy**, **options**, and **inputMethodProxy** are valid pointers.<br>- [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method client error. The input method service may not be ready or the connection is abnormal.<br>- [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method service error. The system input method management service may be abnormal.<br>-[IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Unexpected null pointer. Returned when **textEditorProxy**, **options**, or **inputMethodProxy** is **NULL**.<br>Error handling suggestions: If a code other than **IME_ERR_OK** is returned, verify parameter validity before retrying. If **IME_ERR_IMCLIENT** or **IME_ERR_IMMS** is returned, the service is abnormal; retry later. For more details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode). |

### OH_InputMethodController_AttachWithUIContext()

```c
InputMethod_ErrorCode OH_InputMethodController_AttachWithUIContext(ArkUI_ContextHandle context, InputMethod_TextEditorProxy *textEditorProxy, InputMethod_AttachOptions *options, InputMethod_InputMethodProxy **inputMethodProxy)
```

**Description**

Attaches the app to the input method service with UI context information. Different from **OH_InputMethodController_Attach**, this function receives an additional **ArkUI_ContextHandle** parameter. In multi-window or multi-page scenarios, this parameter specifies the target UI context for attachment, enabling the input method service to accurately associate with the currently active page.

Preconditions:

1. A valid **ArkUI_ContextHandle** shall be obtained (acquired when you create a UI context via the ArkUI module).

2. An **InputMethod_TextEditorProxy** instance shall first be created via **OH_TextEditorProxy_Create**, and required callbacks shall be registered through the *OH_TextEditorProxy_SetXXXFunc* series of functions.

3. An **InputMethod_AttachOptions** instance shall be created first via **OH_AttachOptions_Create** or **OH_AttachOptions_CreateWithRequestKeyboardReason**.

Paired calls:

- After **OH_InputMethodController_AttachWithUIContext** is called, **OH_InputMethodController_Detach** shall be called to perform detachment once related work completes.

- Failing to call **OH_InputMethodController_Detach** will cause input method resource leaks.

Calling sequence:

1. Obtain **ArkUI_ContextHandle**.

2. **OH_TextEditorProxy_Create** → Create **TextEditorProxy**.

3. *OH_TextEditorProxy_SetXXXFunc* → Register callback functions.

4. **OH_AttachOptions_Create** → Create **AttachOptions**.

5. **OH_InputMethodController_AttachWithUIContext** → Attach to the input method (with UI context).

6. **OH_InputMethodProxy_ShowKeyboard**, **NotifyCursorUpdate**, etc. → Use input method features.

7. **OH_InputMethodController_Detach** → Detach from the input method.

8. Destroy created objects.

Lifecycle management:

- **context**: Managed by the ArkUI module. It must remain valid during attachment.

- **textEditorProxy**: Managed by you. If **OH_InputMethodController_AttachWithUIContext** succeeds, it shall not be released until the subsequent **OH_InputMethodController_AttachWithUIContext** or **OH_InputMethodController_Detach** completes.

- **options**: Can be destroyed immediately after **OH_InputMethodController_AttachWithUIContext** completes.

- **inputMethodProxy**: Allocated internally by the **AttachWithUIContext** function and released after **OH_InputMethodController_Detach** is called.

Usage scenarios: Applicable to multi-window or multi-page apps where the input method needs to be attached to a specific UI page. If an app holds multiple UI contexts (such as multiple windows), use this function to ensure the input method is associated with the correct page and prevent input method events from being dispatched to the wrong window.

Thread safety: Not thread-safe. It is recommended that you call the function on the main thread.

**Since**: 23

**Parameters**

| Name | Description |
| -- | -- |
| [ArkUI_ContextHandle](../apis-arkui/capi-arkui-nativemodule-arkui-context8h.md) context | Input pointer pointing to an **ArkUI_Context** instance. Meaning/functionality: Specifies which UI context (page/window) the input method attaches to, enabling the input method service to accurately associate with the currently active page. Usage scenarios: Used in multi-window or multi-page apps when the input method needs to be attached to a specific UI context. Use effect: Input method events are sent to the page associated with this context.<br>Precondition: A valid **ArkUI_ContextHandle** shall be obtained via the ArkUI module.<br>Null pointer handling: Must not be **NULL**. Passing **NULL** returns **IME_ERR_NULL_POINTER**.<br>Lifecycle management: The corresponding **ArkUI_Context** shall remain valid during attachment. The associated UI context shall not be destroyed before **OH_InputMethodController_Detach** is called. |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Input pointer pointing to an **InputMethod_TextEditorProxy** instance. Meaning/functionality: Identical to the **textEditorProxy** parameter of **OH_InputMethodController_Attach**. It acts as the carrier through which the app receives callback notifications from the input method. Its usage scenarios, preconditions, null pointer handling rules, and lifecycle management are consistent with those of the **textEditorProxy** parameter in **OH_InputMethodController_Attach**. |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) *options | Input pointer pointing to an **InputMethod_AttachOptions** instance. Meaning/functionality: Identical to the **options** parameter of **OH_InputMethodController_Attach**, used to specify behavior configuration for attachment. Its usage scenarios, preconditions, null pointer handling rules, and lifecycle management are consistent with those of the **options** parameter in **OH_InputMethodController_Attach**. |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) **inputMethodProxy | Output double pointer pointing to a pointer of **InputMethod_InputMethodProxy**. Its meaning/functionality, usage scenarios, double-pointer explanation, null pointer handling, memory management, and parameter constraints are consistent with those of the **inputMethodProxy** parameter in **OH_InputMethodController_Attach**. |

**Returns**

| Type | Description |
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | Returns a specific error code.<br>- [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Success. *inputMethodProxy is valid and can be used for subsequent interaction.<br>- [IME_ERR_PARAMCHECK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Invalid parameter. Check whether **context**, **textEditorProxy**, **options**, and **inputMethodProxy** are valid pointers.<br>- [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method client error.<br>- [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method service error.<br>- [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Unexpected null pointer. Returned when **context**, **textEditorProxy**, **options**, or **inputMethodProxy** is **NULL**.<br>Error handling suggestions: If a code other than **IME_ERR_OK** is returned, verify parameter validity before retrying. If **IME_ERR_IMCLIENT** or **IME_ERR_IMMS** is returned, the service is abnormal; retry later. For more details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode). |

### OH_InputMethodController_Detach()

```c
InputMethod_ErrorCode OH_InputMethodController_Detach(InputMethod_InputMethodProxy *inputMethodProxy)
```

**Description**

Detaches the app from the input method service and closes the communication channel. After **OH_InputMethodController_Detach** is called, **inputMethodProxy** becomes invalid. No functions called via **inputMethodProxy** (such as **ShowKeyboard**, **HideKeyboard**, and **NotifyCursorUpdate**) shall be used thereafter; otherwise, undefined behavior or crashes may occur.

Preconditions:

- **OH_InputMethodController_Attach** or **OH_InputMethodController_AttachWithUIContext** shall be called first to successfully attach to the input method and obtain a valid **inputMethodProxy**.

Calling sequence:

- **OH_InputMethodController_Attach** or **OH_InputMethodController_AttachWithUIContext** shall be called first to attach to the input method.

- **inputMethodProxy** shall not be used after **OH_InputMethodController_Detach** is called upon completion of input method operations.

- After **OH_InputMethodController_Detach** completes, **TextEditorProxy** can be safely destroyed (via **OH_TextEditorProxy_Destroy**).

Error handling:

- If **inputMethodProxy** is invalid or not attached, calling **OH_InputMethodController_Detach** returns **IME_ERR_NULL_POINTER** or **IME_ERR_IMCLIENT**.

- Repeatedly calling **OH_InputMethodController_Detach** with the same **inputMethodProxy** may trigger undefined behavior and shall be avoided.

- **inputMethodProxy** shall not be used further if **OH_InputMethodController_Detach** fails.

Lifecycle management:

- After **OH_InputMethodController_Detach** is called, memory referenced by **inputMethodProxy** is released by the framework. This pointer shall no longer be used.

- After **OH_InputMethodController_Detach** is called, the app may safely destroy **TextEditorProxy**, since the input method will no longer access **TextEditorProxy** through callbacks.

- It is recommended that you call **OH_TextEditorProxy_Destroy** and **OH_AttachOptions_Destroy** immediately after a successful **OH_InputMethodController_Detach** to release all created objects.

Thread safety: Not thread‑safe. It is recommended that you call it on the main thread.

**Since**: 12

**Parameters**

| Name                                               | Description|
|----------------------------------------------------| -- |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) *inputMethodProxy | Input pointer pointing to an **InputMethod_InputMethodProxy** instance. Meaning/functionality: Specifies the input method proxy instance to be detached. **OH_InputMethodController_Detach** closes the communication channel corresponding to this proxy and releases associated resources. Usage scenarios: Called when the app no longer requires input method interaction, such as upon app exit or when an input box loses focus. Use effect: Upon successful execution of **OH_InputMethodController_Detach**, **inputMethodProxy** becomes invalid immediately and shall not be used further. The input method will no longer send callback notifications to the app.<br>Precondition: This pointer must be successfully returned by **OH_InputMethodController_Attach** or **OH_InputMethodController_AttachWithUIContext**.<br>Null pointer handling: Must not be **NULL**. Passing **NULL** returns **IME_ERR_NULL_POINTER**.<br>Lifecycle management: This pointer is allocated by **OH_InputMethodController_Attach** or **OH_InputMethodController_AttachWithUIContext**. Memory is released by the framework after a successful call to **OH_InputMethodController_Detach**. This pointer shall not be freed manually by you, nor shall it be used after **OH_InputMethodController_Detach** is called.<br>Usage notes: This pointer becomes invalid immediately after detachment. Passing this pointer to any **InputMethodProxy**‑related function will result in undefined behavior. **OH_InputMethodController_Detach** shall not be called repeatedly with the same **inputMethodProxy**. |

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | Returns a specific error code.<br>- [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Success. Detachment completes and **inputMethodProxy** is no longer valid.<br>- [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method client error. The client connection may be abnormal or disconnected.<br>- [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Input method service error. An exception may occur on the service side.<br>- [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Unexpected null pointer. Returned when **inputMethodProxy** is **NULL**.<br>Error handling suggestions: If **IME_ERR_OK** is returned, detachment succeeds, and all created objects can be safely destroyed afterward. If **IME_ERR_IMCLIENT** is returned, the client is in an abnormal state; logging is recommended followed by destruction of related objects. If **IME_ERR_NULL_POINTER** is returned, the passed pointer is invalid. Check whether **OH_InputMethodController_Detach** has already been called or whether the pointer has become invalid. For more details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode). |