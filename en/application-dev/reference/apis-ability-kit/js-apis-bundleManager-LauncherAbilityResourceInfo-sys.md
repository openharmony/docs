# LauncherAbilityResourceInfo (System API)

The **LauncherAbilityResourceInfo** module provides resource information of the entry ability of an application, such as the icon and label. The information can be obtained by calling [getLauncherAbilityResourceInfo](js-apis-bundleResourceManager-sys.md#bundleresourcemanagergetlauncherabilityresourceinfo).

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

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
| drawableDescriptor<sup>12+</sup>                     | [DrawableDescriptor](../apis-arkui/js-apis-arkui-drawableDescriptor-sys.md) | Yes  | No  | **drawableDescriptor** object of the application icon.|
| appIndex<sup>12+</sup>           | number | Yes  | No  | Index of an application clone.|
