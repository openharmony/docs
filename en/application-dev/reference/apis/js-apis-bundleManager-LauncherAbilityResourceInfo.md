# LauncherAbilityResourceInfo

The **LauncherAbilityResourceInfo** module provides resource information of the entry ability of an application, such as the icon and label. The information can be obtained by calling [getLauncherAbilityResourceInfo](js-apis-bundleResourceManager.md#bundleresourcemanagergetlauncherabilityresourceinfo).

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## LauncherAbilityResourceInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**System API**: This is a system API.

| Name                     | Type  | Readable| Writable| Description                |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| bundleName              | string | Yes  | No  | Bundle name of the application.|
| moduleName              | string | Yes  | No  | Module name of the application.|
| abilityName              | string | Yes  | No  | Name of the entry ability.|
| icon              | string | Yes  | No  | Application icon, which is encoded using Base64. |
| label                     | string | Yes  | No  | Application label.|
