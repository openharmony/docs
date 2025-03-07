# RecoverableApplicationInfo (System API)

The RecoverableApplicationInfo module defines the information about a preinstalled application that can be restored after being uninstalled. The information can be obtained through [bundleManager.getRecoverableApplicationInfo](./js-apis-bundleManager-sys.md#bundlemanagergetrecoverableapplicationinfo11).

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## RecoverableApplicationInfo

Defines the information about a preinstalled application that can be restored after being uninstalled.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name            | Type                          | Read-Only| Optional| Description                  |
| ---------------- | ------------------------------ | ---- | ---- | ---------------------- |
| bundleName       | string                         | Yes  | No  | Bundle name.      |
| moduleName       | string                         | Yes  | No  | Module name.|
| labelId          | number                         | Yes  | No  | ID of the module label.    |
| iconId           | number                         | Yes  | No  | ID of the module icon.   |
| systemApp        | boolean                        | Yes  | No  | Whether the application is a system application. The value **true** means that the application is a system application, and **false** means the opposite. |
| bundleType       |[BundleType](js-apis-bundleManager.md#bundletype)             | Yes  | No  | Bundle type, which can be **APP** (application) or **ATOMIC_SERVICE** (atomic service).                               |
| codePaths        | Array\<string>                 | Yes  | No  | Installation directory of the application.         |
