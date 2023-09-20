# ArkUI Subsystem Changelog

## cl.arkui.1 uiAppearance API Behavior Change

Changed the return mode and return value of the **setDarkMode** and **getDarkMode** APIs.

**Change Impact**

The application developed based on earlier versions needs to adapt to new return mode and return value. Otherwise, the original service logic will be affected.

**Key API/Component Changes**


- In the error thrown when the **setDarkMode** API is called in callback mode, what's contained changes from error code ID only to error code ID and message.
- In the error thrown when the **setDarkMode** API is called in promise mode, what's contained changes from error code ID only to error code ID and message.
- In the value returned in normal cases when the **setDarkMode** API is called in callback mode, the first parameter changes from **0** to **null**.
- In the earlier version, the **getDarkMode** API directly returns **2** when an exception occurs. In this version, the API throws an error. You need to determine the error type based on the error code ID and message.

> **NOTE**
>
> Exceptions refer to unexpected behavior such as incorrect parameters, unconfigured permissions, and internal execution errors. Normal cases refer to expected behavior that do not generate errors.

**Adaptation Guide**

For details, see [@ohos.uiAppearance (UI Appearance)](../../../application-dev/reference/apis/js-apis-uiappearance.md).
