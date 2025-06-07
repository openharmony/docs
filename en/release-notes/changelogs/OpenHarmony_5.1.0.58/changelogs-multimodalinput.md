# Multimodal Subsystem Changelog

## cl.multimodalinput.1 Change in OH_Input_AddInputEventInterceptor and OH_Input_AddKeyEventInterceptor Specifications

**Access Level**

Public API

**Reason for the Change**

Restrictions on intercepted events are added for **OH_Input_AddInputEventInterceptor** and **OH_Input_AddKeyEventInterceptor** in the **oh_input_manager.h** file.

**Change Impact**

This change does not require application adaptation.

Before change: Interception of key events and input events takes effect immediately after being enabled.
  
After change: Interception of key events takes effect only when the application gains the focus. Interception of input events takes effect only when the input event hits the application window.

**Start API Level**

API 12

**Change Since**

OpenHarmony SDK 5.1.0.58

**Key API/Component Changes**

The following APIs in the **oh_input_manager.h** file are modified:

- [OH_Input_AddInputEventInterceptor](../../../application-dev/reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_addinputeventinterceptor)
- [OH_Input_AddKeyEventInterceptor](../../../application-dev/reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_addkeyeventinterceptor)

**Adaptation Guide**

No adaptation is required.
