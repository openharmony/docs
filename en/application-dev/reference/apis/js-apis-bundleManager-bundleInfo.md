# BundleInfo

The **BundleInfo** module defines the bundle information. A system application can obtain its own or others' bundle information through [bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo). A third-party application can obtain its own bundle information through [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself). The input parameter [bundleFlags](js-apis-bundleManager.md#bundleflag) specifies the information to be contained in the returned [BundleInfo](js-apis-bundleManager-bundleInfo.md) object.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## BundleInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                             | Type                                                        | Readable| Writable| Description                                                        |
| --------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                              | string                                                       | Yes  | No  | Bundle name.                                              |
| vendor                            | string                                                       | Yes  | No  | Vendor of the bundle.                                              |
| versionCode                       | number                                                       | Yes  | No  | Version number of the bundle.                                             |
| versionName                       | string                                                       | Yes  | No  | Version description of the bundle.                                    |
| minCompatibleVersionCode          | number                                                       | Yes  | No  | Earliest version compatible with the bundle in the distributed scenario.                          |
| targetVersion                     | number                                                       | Yes  | No  | Target API version required for running the bundle.                               |
| appInfo                           | [ApplicationInfo](js-apis-bundleManager-applicationInfo.md)         | Yes  | No  | Application information. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_APPLICATION** to the **bundleFlags** parameter of [bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo).                                          |
| hapModulesInfo                    | Array\<[HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md)>     | Yes  | No  | Module configuration information. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_HAP_MODULE** to the **bundleFlags** parameter of [bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo).                                                |
| reqPermissionDetails     | Array\<[ReqPermissionDetail](#reqpermissiondetail)>   | Yes  | No  | Detailed information of the permissions to request from the system. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION** to the **bundleFlags** parameter of [bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo).|
| permissionGrantStates        | Array\<[PermissionGrantState](js-apis-bundleManager.md#permissiongrantstate)> | Yes  | No  | Permission grant state. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION** to the **bundleFlags** parameter of [bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo).                    |
| signatureInfo          | [SignatureInfo](#signatureinfo)                                          | Yes  | No  | Signature information of the bundle. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_SIGNATURE_INFO** to the **bundleFlags** parameter of [bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo).                                          |
| installTime                       | number                                                       | Yes  | No  | Time when the bundle was installed.                                         |
| updateTime                        | number                                                       | Yes  | No  | Time when the bundle was updated.                                           |


## ReqPermissionDetail

Provides the detailed information of the permissions to request from the system.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                 | Type                   | Readable| Writable| Description                |
| --------------------- | ----------------------- | ---- | ---- | ---------------------|
| name                  | string                  | Yes  | Yes  | Name of the permission to request.  |
| reason                | string                  | Yes  | Yes  | Reason for requesting the permission. |
| reasonId              | number                  | Yes  | Yes  | ID of the reason for requesting the permission.|
| usedScene             | [UsedScene](#usedscene) | Yes  | Yes  | Application scenario and timing for using the permission.|



## UsedScene

Describes the application scenario and timing for using the permission.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name     | Type          | Readable| Writable| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| abilities | Array\<string> | Yes  | Yes  | Abilities that use the permission.  |
| when      | string         | Yes  | Yes  | Time when the permission is used.         |

## SignatureInfo

Describes the signature information of the bundle.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name     | Type          | Readable| Writable| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| appId     | string         | Yes  | No  | Application ID.                |
|fingerprint| string         | Yes  | No  | Fingerprint information of the bundle.           |
