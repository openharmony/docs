# Input Method Framework Changelog

## cl.imf.1 Permission for switchInputMethod() in @ohos.InputMethodSubtype


**Reason for Change**

**switchInputMethod()** is a public API, but the caller must have the ohos.permission.CONNECT_IME_ABILITY permission. As a result, third-party app developers cannot use this API.

**Change Impact**

This change is a non-compatible change.
The system applications that previously use this API need to use [switchInputMethod](../../../application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchinputmethod9).

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.3

**Key API/Component Changes**

The ohos.permission.SET_UNREMOVABLE_NOTIFICATION permission is no longer required for calling **switchInputMethod()**. This API is available only for the current input method application.

**Adaptation Guide**
The system applications that previously use this API need to use [switchInputMethod](../../../application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchinputmethod9).

## cl.imf.2 Permission for switchCurrentInputMethodSubtype in @ohos.InputMethodSubtype


**Reason for Change**

**switchCurrentInputMethodSubtype()** is a public API, but the caller must have the ohos.permission.CONNECT_IME_ABILITY permission. As a result, third-party app developers cannot use this API.

**Change Impact**

This change is a non-compatible change.
The system applications that previously use this API need to use [switchInputMethod](../../../application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchinputmethod9).

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.3

**Key API/Component Changes**

The ohos.permission.SET_UNREMOVABLE_NOTIFICATION permission is no longer required for calling **switchInputMethod()**. This API is available only for the current input method application.

**Adaptation Guide**
The system applications that previously use this API need to use [switchInputMethod](../../../application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchinputmethod9).

## cl.imf.3 Permission for switchCurrentInputMethodAndSubtype9 in @ohos.InputMethodSubtype


**Reason for Change**

**switchCurrentInputMethodSubtype()** is a public API, but the caller must have the ohos.permission.CONNECT_IME_ABILITY permission. As a result, third-party app developers cannot use this API.

**Change Impact**

This change is a non-compatible change.
The system applications that previously use this API need to use [switchInputMethod](../../../application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchinputmethod9).

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.3

**Key API/Component Changes**

The ohos.permission.SET_UNREMOVABLE_NOTIFICATION permission is no longer required for calling **switchInputMethod()**. This API is available only for the current input method application.

**Adaptation Guide**
The system applications that previously use this API need to use [switchInputMethod](../../../application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodswitchinputmethod9).
