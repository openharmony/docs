# OverlayModuleInfo

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The **OverlayModuleInfo** module provides information about a module with the overlay feature. A system application can obtain such information of the specified application through [overlay.getOverlayModuleInfoByBundleName](js-apis-overlay.md#overlaygetoverlaymoduleinfobybundlename), and a third-party application can obtain such information of the current application through [overlay.getOverlayModuleInfo](js-apis-overlay.md#overlaygetoverlaymoduleinfo).

## OverlayModuleInfo

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                 | Type                                               | Readable| Writable| Description                                           |
| --------------------- | ---------------------------------------------------| ---- | ---- | ---------------------------------------------- |
| bundleName            | string                                             | Yes  | No  | Bundle name of the application to which the module with the overlay feature belongs.          |
| moduleName            | string                                             | Yes  | No  | HAP name of the module with the overlay feature.                      |
| targetModuleName      | string                                             | Yes  | No  | HAP name of the target module specified by the module with the overlay feature.       |
| priority              | number                                             | Yes  | No  | Priority of the module with the overlay feature.                  |
| state                 | number                                             | Yes  | No  | Whether the module with the overlay feature is disabled. The value **0** means that the module is disabled, and **1** means the opposite.                      |
