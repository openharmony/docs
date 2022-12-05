# BundleStatusCallback

The **BundleStatusCallback** module provides bundle callback information, which is obtained through [innerBundleManager.on](js-apis-Bundle-InnerBundleManager.md).

> **NOTE**
>
> This module is deprecated since API version 9. You are advised to use [bundleMonitor](js-apis-bundleMonitor.md) instead.


## BundleStatusCallback<sup>(deprecated)<sup>
> This API is deprecated since API version 9. You are advised to use [bundleMonitor](js-apis-bundleMonitor.md) instead.

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Type  | Callback                                         | Description                                  |
| ------ | --------------------------------------------- | -------------------------------------- |
| add    | (bundleName : string, userId: number) => void | Used to obtain information when a bundle is installed.|
| update | (bundleName : string, userId: number) => void | Used to obtain information when a bundle is updated.|
| remove | (bundleName : string, userId: number) => void | Used to obtain information when a bundle is uninstalled.|
