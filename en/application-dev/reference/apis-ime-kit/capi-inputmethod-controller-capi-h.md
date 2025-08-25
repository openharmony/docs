# inputmethod_controller_capi.h
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy1984-->
<!--Adviser: @zhang_yixin13-->

## Overview

Provides methods for binding and unbinding input methods.

**File to include**: <inputmethod/inputmethod_controller_capi.h>

**Library**: libohinputmethod.so

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Since**: 12

**Related module**: [InputMethod](capi-inputmethod.md)

## Summary

### Function

| Name| Description|
| -- | -- |
| [InputMethod_ErrorCode OH_InputMethodController_Attach(InputMethod_TextEditorProxy *textEditorProxy,InputMethod_AttachOptions *options, InputMethod_InputMethodProxy **inputMethodProxy)](#oh_inputmethodcontroller_attach) | Binds an application to the input method service.|
| [InputMethod_ErrorCode OH_InputMethodController_Detach(InputMethod_InputMethodProxy *inputMethodProxy)](#oh_inputmethodcontroller_detach) | Unbinds an application from the input method service.|

## Function Description

### OH_InputMethodController_Attach()

```
InputMethod_ErrorCode OH_InputMethodController_Attach(InputMethod_TextEditorProxy *textEditorProxy,InputMethod_AttachOptions *options, InputMethod_InputMethodProxy **inputMethodProxy)
```

**Description**

Binds an application to the input method service.

**Since**: 12


**Parameters**

| Name                                                                                            | Description|
|-------------------------------------------------------------------------------------------------| -- |
| [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) *textEditorProxy | Pointer to the [InputMethod_TextEditorProxy](capi-inputmethod-inputmethod-texteditorproxy.md) instance. The caller needs to manage the **textEditorProxy** lifecycle. If the calling is successful, the caller cannot release **textEditorProxy** before the next binding or unbinding call.|
| [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) *options             | Pointer to the [InputMethod_AttachOptions](capi-inputmethod-inputmethod-attachoptions.md) instance. This parameter is used to specify the options of attaching an input method.|
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) **inputMethodProxy                                             | Pointer to the [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) instance. The lifecycle lasts until the next binding or unbinding call.|

**Returns**

| Type                                                                             | Description                                                                                                                                                                                                                                                                           |
|---------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_PARAMCHECK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Parameter error.<br>     [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Client error in input method.<br>     [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Input method service error.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|

### OH_InputMethodController_Detach()

```
InputMethod_ErrorCode OH_InputMethodController_Detach(InputMethod_InputMethodProxy *inputMethodProxy)
```

**Description**

Unbinds an application from the input method service.

**Since**: 12


**Parameters**

| Name                                               | Description|
|----------------------------------------------------| -- |
| [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) *inputMethodProxy | Pointer to the [InputMethod_InputMethodProxy](capi-inputmethod-inputmethod-inputmethodproxy.md) instance obtained by calling [OH_InputMethodController_Attach](capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach).|

**Returns**

| Type| Description|
| -- | -- |
| [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) | An error code.<br>     [IME_ERR_OK](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Success.<br>     [IME_ERR_IMCLIENT](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Client error in input method.<br>     [IME_ERR_IMMS](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - Input method service error.<br>     [IME_ERR_NULL_POINTER](capi-inputmethod-types-capi-h.md#inputmethod_errorcode) - An unexpected null pointer.<br> For details about the error codes, see [InputMethod_ErrorCode](capi-inputmethod-types-capi-h.md#inputmethod_errorcode).|
