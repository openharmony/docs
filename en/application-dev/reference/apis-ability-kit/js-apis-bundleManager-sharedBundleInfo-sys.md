# SharedBundleInfo (System API)

The **SharedBundleInfo** module provides information about the shared bundle. The information can be obtained by calling [bundleManager.getSharedBundleInfo](js-apis-bundleManager-sys.md#bundlemanagergetsharedbundleinfo10).

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## SharedBundleInfo

Defines the shared bundle information.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name            | Type                          | Read-Only| Optional| Description                  |
| ---------------- | ------------------------------ | ---- | ---- | ---------------------- |
| name             | string                         | Yes  | No  | Name of the shared bundle.      |
| compatiblePolicy | bundleManager.CompatiblePolicy | Yes  | No  | Compatibility type of the shared bundle.|
| sharedModuleInfo | Array\<SharedModuleInfo>       | Yes  | No  | Information about the shared module.    |

## SharedModuleInfo

Defines the shared module information.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name         | Type  | Read-Only| Optional| Description                      |
| ------------- | ------ | ---- | ---- | -------------------------- |
| name          | string | Yes  | No  | Module name of the shared bundle.          |
| versionCode   | number | Yes  | No  | Version number of the shared bundle.          |
| versionName   | string | Yes  | No  | Version description of the shared bundle.|
| description   | string | Yes  | No  | Description of the shared bundle.    |
| descriptionId | number | Yes  | No  | Description ID of the shared bundle.    |
