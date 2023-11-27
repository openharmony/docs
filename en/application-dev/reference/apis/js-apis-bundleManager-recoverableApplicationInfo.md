# RecoverableApplicationInfo

The **RecoverableApplicationInfo** module defines the information about a preinstalled application that can be restored after being uninstalled. The information can be obtained through [bundleManager.getRecoverableApplicationInfo](js-apis-bundleManager.md).

> **NOTE**
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## RecoverableApplicationInfo

Defines the information about a preinstalled application that can be restored after being uninstalled.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name            | Type                          | Readable| Writable| Description                  |
| ---------------- | ------------------------------ | ---- | ---- | ---------------------- |
| bundleName       | string                         | Yes  | No  | Bundle name.      |
| moduleName       | string                         | Yes  | No  | Module name.|
| labelId          | number                         | Yes  | No  | ID of the module label.    |
| iconId           | number                         | Yes  | No  | ID of the module icon.   |
