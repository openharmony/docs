# BundleResourceInfo

The **BundleResourceInfo** module provides resource information of an application, such as the icon and label. The information can be obtained by calling [getBundleResourceInfo](js-apis-bundleResourceManager.md#bundleresourcemanagergetbundleresourceinfo).

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## BundleResourceInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**System API**: This is a system API.

| Name                     | Type  | Readable| Writable| Description                |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| bundleName              | string | Yes  | No  | Bundle name of the application.|
| icon              | string | Yes  | No  | Application icon, which is encoded using Base64. |
| label                     | string | Yes  | No  | Application label.|
