# BundleStatusCallback

The **BundleStatusCallback** module provides bundle callback information, which is obtained through [innerBundleManager.on](js-apis-Bundle-InnerBundleManager.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## BundleStatusCallback

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name  | Type                                         | Description                                  |
| ------ | --------------------------------------------- | -------------------------------------- |
| add    | (bundleName : string, userId: number) => void | Callback invoked when a **launcherStatusCallback** is added.|
| update | (bundleName : string, userId: number) => void | Callback invoked when a **launcherStatusCallback** is updated.|
| remove | (bundleName : string, userId: number) => void | Callback invoked when a **launcherStatusCallback** is removed.|
