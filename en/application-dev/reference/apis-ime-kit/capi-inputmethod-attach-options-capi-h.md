# inputmethod_attach_options_capi.h

<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=4c244f2ed12456a4c6059eccff764e442d7872b9 translatedAt=2026-08-10T06:46:08.709Z pushedAt=2026-08-12T04:00:23.437Z -->

## Overview

Provides methods for creating, destroying, reading, and writing input method attach option objects, used to manage configuration parameters when an app attaches to an input method.

Functionality: Creates and manages **InputMethod_AttachOptions** instances. You can configure whether to show the keyboard upon attachment (**showKeyboard**) and the reason for requesting the keyboard (**requestKeyboardReason**). **AttachOptions**, controls the initial behavior when attaching to the input method service, is a mandatory parameter for **OH_InputMethodController_Attach**.

Usage scenarios: Before an app attaches to the input method service, create **AttachOptions** to configure the attachment behavior.

- When **showKeyboard** is **true**, the keyboard is automatically brought up upon attachment. This applies to scenarios where immediate input is required after an input box gains focus.

- When **showKeyboard** is **false**, the keyboard is not brought up upon attachment. This applies to scenarios where an interaction channel needs to be established first without immediate input (for example, a search box attaches to the input method first and brings up the keyboard only after a user click).

- **requestKeyboardReason** identifies what triggers the keyboard request (such as mouse clicks or touch events). It helps the system recognize input scenarios to deliver improved user experience.

Use effect: After you create **AttachOptions**, pass it to the attach function. The attach function reads its configurations to determine attachment‑time behaviors. Once the attach operation completes, **AttachOptions** can be destroyed, as its configuration information has already been read.

**File to include**: <inputmethod/inputmethod_attach_options_capi.h>

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](capi-inputmethod.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) | InputMethod_AttachOptions | Input method attach options, used to carry relevant configurations when attaching to an input method. This is an opaque type. Callers cannot directly access its member variables and can operate it only through the functions provided in this header file. |

### Functions

| Name| Description                                            |
| -- |------------------------------------------------|
| [InputMethod_AttachOptions *OH_AttachOptions_Create(bool showKeyboard)](#oh_attachoptions_create) | Creates an **InputMethod_AttachOptions** instance, suitable for simple attachment scenarios where only the keyboard visibility needs to be controlled. |
| [InputMethod_AttachOptions *OH_AttachOptions_CreateWithRequestKeyboardReason(bool showKeyboard, InputMethod_RequestKeyboardReason requestKeyboardReason)](#oh_attachoptions_createwithrequestkeyboardreason) | Creates an **InputMethod_AttachOptions** instance, specifying both the keyboard visibility and the reason for requesting the keyboard. This function is suitable for attachment scenarios that require identifying what triggers the keyboard request. |
| [void OH_AttachOptions_Destroy(InputMethod_AttachOptions *options)](#oh_attachoptions_destroy) | Destroys an **InputMethod_AttachOptions** instance and releases memory resources allocated by the **OH_AttachOptions_Create** function. |
| [InputMethod_ErrorCode OH_AttachOptions_IsShowKeyboard(InputMethod_AttachOptions *options, bool *showKeyboard)](#oh_attachoptions_isshowkeyboard) | Obtains the value indicating whether to show the keyboard from **InputMethod_AttachOptions**. |
| [InputMethod_ErrorCode OH_AttachOptions_GetRequestKeyboardReason(InputMethod_AttachOptions *options, int *requestKeyboardReason)](#oh_attachoptions_getrequestkeyboardreason) | Obtains the reason for requesting the keyboard from **InputMethod_AttachOptions**. |

## Function Description

### OH_AttachOptions_Create()

```c
InputMethod_AttachOptions *OH_AttachOptions_Create(bool showKeyboard)
```

**Description**

Creates an [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) instance for simple scenarios where only keyboard visibility needs to be controlled. If you also need to specify the reason for requesting the keyboard, it is recommended that you use [OH_AttachOptions_CreateWithRequestKeyboardReason](#oh_attachoptions_createwithrequestkeyboardreason).

Paired calls: This function must be called in pair with [OH_AttachOptions_Destroy](#oh_attachoptions_destroy). Objects created by **OH_AttachOptions_Create** must be destroyed via **OH_AttachOptions_Destroy**; otherwise, memory leaks will occur.

Lifecycle management:

- After creation, it can be read multiple times (**IsShowKeyboard**).

- After options are passed to the attach function, the attach function reads configuration information. Once the attach operation completes, options can be destroyed immediately, as the configuration has already been read.

- Destroyed options must not be used again.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| bool showKeyboard | Input parameter that indicates whether to show the keyboard upon attachment.<br>Use scenarios: Set to **true** for scenarios requiring immediate input after an input box gains focus (for example, a text‑editing box). Set to **false** for scenarios where an interaction channel is established first with no keyboard brought up (for example, a search box that brings up the keyboard only after user clicks).<br>Use effect: When **showKeyboard** is **true**, the keyboard pops up automatically upon successful attachment. When **showKeyboard** is **false**, the keyboard does not pop up after successful attachment; you need to call **OH_InputMethodProxy_ShowKeyboard** to bring up the keyboard.<br>Value range: **true** or **false**.<br>Default value: No default value. Callers must specify it explicitly.<br>Value‑setting guideline: Parameter values are determined based on service scenarios. A value of **true** applies to scenarios requiring immediate input, while a value of **false** applies to scenarios requiring delayed keyboard display. For the latter, you can call **ShowKeyboard** to bring up the keyboard at a later time. |

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) * | Pointer type.<br>Creation successful: Returns a pointer to the newly created **InputMethod_AttachOptions** instance. The pointer is valid and can be used for subsequent operations.<br>Creation failed: Returns **NULL**. Possible causes include full app address space (insufficient memory).<br>Null check: The caller must check whether the return value is **NULL** before using it. If **NULL** is returned, the pointer cannot be used and the caller should troubleshoot memory conditions or retry later.<br>Memory management: Memory for the returned pointer is allocated internally by the create function. Callers need to release it using **OH_AttachOptions_Destroy**. Do not use **free()** or other methods to release the memory. |

### OH_AttachOptions_CreateWithRequestKeyboardReason()

```c
InputMethod_AttachOptions *OH_AttachOptions_CreateWithRequestKeyboardReason(bool showKeyboard, InputMethod_RequestKeyboardReason requestKeyboardReason)
```

**Description**

Creates an [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) instance, specifying both keyboard visibility and the reason for requesting the keyboard. The **requestKeyboardReason** parameter identifies the scenario that triggers the keyboard request, enabling the system to recognize input scenarios and deliver improved user experience.

Paired calls: This function must be called in pair with [OH_AttachOptions_Destroy](#oh_attachoptions_destroy). The object created by the create function must be destroyed via **OH_AttachOptions_Destroy**.

Lifecycle management: Consistent with **OH_AttachOptions_Create**. Multiple read operations can be performed after creation. The instance can be destroyed immediately once the attach operation completes.

**Since**: 15

**Parameters**

| Name| Description|
| -- | -- |
| bool showKeyboard | Input parameter indicating whether to show the keyboard upon attachment. Its meaning, functionality, usage scenarios, use effect, value range and value‑setting guideline are consistent with the **showKeyboard** parameter in **OH_AttachOptions_Create**. |
| [InputMethod_RequestKeyboardReason](capi-inputmethod-types-capi-h.md#inputmethod_requestkeyboardreason) requestKeyboardReason | Input parameter indicating the reason for requesting keyboard input.<br>Meaning/Function: Identifies the scenario triggering the keyboard request to help the system recognize input scenarios and optimize user experience.<br>Usage scenarios: Used when an app needs to inform the system why the keyboard is brought up. Examples include distinguishing triggers such as mouse clicks, touch events, or active API calls from the app.<br>Use effect: The system can adjust input method behaviors according to this reason (for example, selecting an appropriate keyboard layout or input mode).<br>Value range: Enumerated values of **InputMethod_RequestKeyboardReason**, including:<br>- **IME_REQUEST_REASON_NONE** (**0**): No specific reason.<br>- **IME_REQUEST_REASON_MOUSE** (**1**): Triggered by a mouse click.<br>- **IME_REQUEST_REASON_TOUCH** (**2**): Triggered by a touch event.<br>- **IME_REQUEST_REASON_OTHER** (**20**): Other reasons (such as active API calls initiated by the app).<br>Value‑setting guideline: The corresponding enumerated value is selected based on the actual trigger scenario. **IME_REQUEST_REASON_TOUCH** applies to triggers where the user taps an input box, **IME_REQUEST_REASON_MOUSE** applies to mouse click triggers, and **IME_REQUEST_REASON_OTHER** applies to triggers initiated actively by the app's internal logic.<br>Specification constraints: Only the above enumerated values are supported. Passing other values may lead to undefined behavior. |

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) * | Pointer type.<br>Creation successful: Returns a pointer to the newly created **InputMethod_AttachOptions** instance.<br>Creation failed: Returns **NULL**. Possible causes include full app address space (insufficient memory).<br>Null check: The caller must check whether the return value is **NULL** before using it. If **NULL** is returned, the pointer cannot be used.<br>Memory management: Memory for the returned pointer is allocated internally by the create function. Callers need to release it using **OH_AttachOptions_Destroy**. Do not use **free()** or other methods to release the memory.|

### OH_AttachOptions_Destroy()

```c
void OH_AttachOptions_Destroy(InputMethod_AttachOptions *options)
```

**Description**

Destroys an [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) instance, releasing the memory resource allocated by the **OH_AttachOptions_Create** function. This method is used in pair with **OH_AttachOptions_Create** and **OH_AttachOptions_CreateWithRequestKeyboardReason**.

Paired calls: This function must be called in pair with **OH_AttachOptions_Create** or **OH_AttachOptions_CreateWithRequestKeyboardReason**. Each instance created by **OH_AttachOptions_Create** shall be destroyed by exactly one invocation of **OH_AttachOptions_Destroy**.

Lifecycle management:

- After **OH_AttachOptions_Destroy** is called, the options pointer becomes invalid and shall not be used further.

- **OH_AttachOptions_Destroy** cannot be called twice on the same options pointer; otherwise, a double-free error will occur.

- It is recommended that you call **OH_AttachOptions_Destroy** immediately after a successful attach operation, since configuration information has already been read upon attachment.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) *options | Input pointer representing the **InputMethod_AttachOptions** instance to be destroyed.<br>Meaning/Functionality: Specifies the **AttachOptions** instance to destroy. **OH_AttachOptions_Destroy** releases memory occupied by this instance.<br>Usage scenarios: Called when the **AttachOptions** is no longer required, typically after the attach operation completes.<br>Use effect: Memory pointed to by **options** is released, and the pointer becomes invalid.<br>Null pointer handling: If **options** is **NULL**, **OH_AttachOptions_Destroy** performs no operation (safe handling) and will not trigger a crash. However, you are advised to avoid passing **NULL**, as this indicates unsuccessful handling of failures from **OH_AttachOptions_Create**.<br>Memory release responsibility: You are responsible for calling **OH_AttachOptions_Destroy** at the appropriate time to release memory. |

### OH_AttachOptions_IsShowKeyboard()

```c
InputMethod_ErrorCode OH_AttachOptions_IsShowKeyboard(InputMethod_AttachOptions *options, bool *showKeyboard)
```

**Description**

Obtains the value that indicates whether to show the keyboard from [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md).

Precondition: **options** must be a valid instance created via the **OH_AttachOptions_Create** function, and **showKeyboard** must point to a valid **bool** variable.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) *options | Input pointer for the **InputMethod_AttachOptions** instance to be read.<br>Meaning/Functionality: Specifies the **AttachOptions** instance from which to read **showKeyboard**.<br>Null pointer handling: The pointer cannot be **NULL**. Passing **NULL** returns **IME_ERR_NULL_POINTER**.<br>Precondition: It must be a valid instance created via the **OH_AttachOptions_Create** function. |
| bool *showKeyboard | Output pointer that obtains the value from **InputMethod_AttachOptions** indicating whether to display the keyboard.<br>Meaning/Functionality: Obtains the value of the **showKeyboard** property. **true** indicates that the keyboard needs to be shown after attachment completes; **false** indicates that the keyboard does not need to be shown after attachment completes.<br>Use scenarios: Used for querying the keyboard display configuration of **AttachOptions**, such as verifying configurations before attachment or validating settings during debugging.<br>Null pointer handling: This parameter cannot be **NULL**. Passing **NULL** returns **IME_ERR_NULL_POINTER**. You need to ensure **showKeyboard** points to a valid **bool** variable.<br>Memory allocation responsibility: Memory for the **bool** variable is allocated by you. **IsShowKeyboard** only writes the value and does not allocate memory. |

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | Returns a specific error code.<br>- [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Success. *showKeyboard has been assigned the correct Boolean value.<br>- [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Unexpected null pointer. **options** or **showKeyboard** is a null pointer. Ensure that both parameters are properly initialized and not **NULL** before you call them.<br>Error handling suggestion: If **IME_ERR_NULL_POINTER** is returned, verify whether **options** and **showKeyboard** are valid pointers. If **IME_ERR_OK** is returned, *showKeyboard holds the correct configuration value. Refer to [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) for detailed error code definitions. |

### OH_AttachOptions_GetRequestKeyboardReason()

```c
InputMethod_ErrorCode OH_AttachOptions_GetRequestKeyboardReason(InputMethod_AttachOptions *options, int *requestKeyboardReason)
```

**Description**

Obtains the reason for requesting the keyboard from [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md).

Precondition: **options** must be a valid instance created via **OH_AttachOptions_CreateWithRequestKeyboardReason** (For instances created via **OH_AttachOptions_Create**, the default value of **requestKeyboardReason** is **IME_REQUEST_REASON_NONE**). **requestKeyboardReason** must point to a valid variable of **InputMethod_RequestKeyboardReason**.

**Since**: 15

**Parameters**

| Name| Description|
| -- | -- |
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) *options | Input pointer pointing to the **InputMethod_AttachOptions** instance from which values are read.<br>Meaning/Functionality: Specifies the **AttachOptions** instance from which to read **requestKeyboardReason**.<br>Null pointer handling: The pointer cannot be **NULL**. Passing **NULL** returns **IME_ERR_NULL_POINTER**.<br>Precondition: It must be a valid instance created via the **OH_AttachOptions_Create** function. If the instance is created via **OH_AttachOptions_Create** (instead of **OH_AttachOptions_CreateWithRequestKeyboardReason**), the default value read for **requestKeyboardReason** is **IME_REQUEST_REASON_NONE**. |
| [InputMethod_RequestKeyboardReason](capi-inputmethod-types-capi-h.md#inputmethod_requestkeyboardreason) *requestKeyboardReason | Output pointer indicating the reason for requesting the keyboard.<br>Meaning/Functionality: Output parameter used to retrieve the enumerated value indicating the scenario that triggers input method activation.<br>Usage scenarios: Queries the keyboard request reason configured in **AttachOptions**.<br>Value range: The output value belongs to the **InputMethod_RequestKeyboardReason** enumeration: **IME_REQUEST_REASON_NONE(0)**, **IME_REQUEST_REASON_MOUSE(1)**, **IME_REQUEST_REASON_TOUCH(2)**, **IME_REQUEST_REASON_OTHER(20)**.<br>Null pointer handling: This parameter cannot be **NULL**. Passing **NULL** returns **IME_ERR_NULL_POINTER**. You need to ensure **requestKeyboardReason** points to a valid variable.<br>Memory allocation responsibility: Memory for the variable is allocated by you. **GetRequestKeyboardReason** only writes the value and does not allocate memory. |

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | Returns a specific error code.<br>- [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Success. *requestKeyboardReason has been assigned the correct enumerated value.<br>- [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode): Unexpected null pointer. **options** or **requestKeyboardReason** is a null pointer. Ensure that both parameters are properly initialized and not **NULL** before you call them.<br>Error handling suggestion: If **IME_ERR_NULL_POINTER** is returned, verify whether **options** and **requestKeyboardReason** are valid pointers. If **IME_ERR_OK** is returned, *requestKeyboardReason holds the correct configuration value. Refer to [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) for detailed error code definitions. |