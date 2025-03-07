# Multimodal Subsystem Changelog

## Permission Change in @ohos.multimodalInput.inputEventClient.d.ts

**Access Level**

System API

**Reason for Change**

The **ohos.permission.INJECT_INPUT_EVENT** permission is added to all APIs in the @ohos.multimodalInput.inputEventClient.d.ts file to meet security requirements.

**Change Impact**

This change is a non-compatible change. After the permission change, the compilation is successful, but the original functions of the APIs cannot be used properly. When an API is called, error code 201 is reported.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.33

**Key API/Component Changes**

| API| Before Change| After Change|
| ------------------------------------------------------------ | --------- | ------ |
| function injectKeyEvent(keyEvent: KeyEventData): void;       | No permission is required.| The **ohos.permission.INJECT_INPUT_EVENT** permission is required.|
| function injectEvent({ KeyEvent: KeyEvent }): void;          | No permission is required.| The **ohos.permission.INJECT_INPUT_EVENT** permission is required.|
| function injectMouseEvent(mouseEvent: MouseEventData): void; | No permission is required.| The **ohos.permission.INJECT_INPUT_EVENT** permission is required.|
| function injectTouchEvent(touchEvent: TouchEventData): void; | No permission is required.| The **ohos.permission.INJECT_INPUT_EVENT** permission is required.|
| function permitInjection(result: boolean): void;             | No permission is required.| The **ohos.permission.INJECT_INPUT_EVENT** permission is required.|

**Adaptation Guide**

Declare the **ohos.permission.INJECT_INPUT_EVENT** permission during application development.
