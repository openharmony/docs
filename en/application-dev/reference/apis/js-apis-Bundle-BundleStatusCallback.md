# BundleStatusCallback

The **BundleStatusCallback** module provides callbacks for bundle status changes. The changes can be obtained through [innerBundleManager.on](js-apis-Bundle-InnerBundleManager.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## BundleStatusCallback<sup>(deprecated)<sup>
> This API is deprecated since API version 9. You are advised to use [bundleMonitor](js-apis-bundleMonitor.md) instead.

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Type  | Callback                                         | Description                                  |
| ------ | --------------------------------------------- | -------------------------------------- |
| add    | (bundleName : string, userId: number) => void | Used to obtain information when a bundle is installed.|
| update | (bundleName : string, userId: number) => void | Used to obtain information when a bundle is updated.|
| remove | (bundleName : string, userId: number) => void | Used to obtain information when a bundle is uninstalled.|
