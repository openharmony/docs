# ApplicationInfo (System API)

The ApplicationInfo module defines the application information. A third-party application can obtain its own application information through **bundleManager.getBundleInfoForSelf**, with at least **GETBUNDLEINFOWITHAPPLICATION** passed in to **bundleFlags**.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).

## ApplicationInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name     | Type          | Read-Only| Optional| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| flags<sup>12+</sup>    | number    | Yes  | Yes  | Status set between the current application and the current user. Each bit indicates a specific Boolean status.<br>**System API**: This property can be used in system APIs since API version 12.|


## PreinstalledApplicationInfo<sup>12+<sup>

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name     | Type          | Read-Only| Optional| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| bundleName | string         | Yes  | No  | Bundle name of the application.                |
| moduleName | string         | Yes  | No  | Module name of the application. The value is **moduleName** configured for the entry module. If the entry module does not exist, the value is **moduleName** configured for the feature module.           |
| iconId | number         | Yes  | No  | Icon ID of the application.           |
| labelId | number         | Yes  | No  | Label ID of the application.           |
