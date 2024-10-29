# Window Subsystem Changelog
## cl.window.1 WindowType.TYPE_INPUT_METHOD Deprecated

**Access Level**

System API

**Reason for Change**

The input method window is controlled by the interface provided by the input method framework. Other direct control of the input method behavior is uncontrollable and therefore is deprecated.

**Change Impact**

This change is a compatible change.

**Start API Level**

13

**Change Since**

OpenHarmony SDK 5.0.0.39

**Key API/Component Changes**

window.WindowType.TYPE_INPUT_METHOD

**Adaptation Guide**

You are not advised to use **window.WindowType.TYPE_INPUT_METHOD**. To control the input method, call [Input method framework interface](../../../application-dev/inputmethod/inputmethod_application_guide.md).
