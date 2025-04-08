# BundleInfo

The **BundleInfo** module defines the bundle information. A third-party application can obtain its own bundle information through [bundleManager.getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself), with [bundleFlags](js-apis-bundleManager.md#bundleflag) set to the information to be contained in the returned [BundleInfo](js-apis-bundleManager-bundleInfo.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## BundleInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                             | Type                                                        | Read-Only| Optional| Description                                                        |
| --------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                              | string                                                       | Yes  | No  | Bundle name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| vendor                            | string                                                       | Yes  | No  | Vendor of the bundle.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| versionCode                       | number                                                       | Yes  | No  | Version number of the bundle.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| versionName                       | string                                                       | Yes  | No  | Version description of the bundle.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| minCompatibleVersionCode          | number                                                       | Yes  | No  | Earliest version compatible with the bundle in the distributed scenario.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| targetVersion                     | number                                                       | Yes  | No  | Target API version required for running the bundle.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| appInfo                           | [ApplicationInfo](js-apis-bundleManager-applicationInfo.md)         | Yes  | No  | Application information. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_APPLICATION** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| hapModulesInfo                    | Array\<[HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md)>     | Yes  | No  | Module configuration information. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_HAP_MODULE** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| reqPermissionDetails     | Array\<[ReqPermissionDetail](#reqpermissiondetail)>   | Yes  | No  | Detailed information of the permissions to request from the system. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| permissionGrantStates        | Array\<[bundleManager.PermissionGrantState](js-apis-bundleManager.md#permissiongrantstate)> | Yes  | No  | Permission grant state. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| signatureInfo          | [SignatureInfo](#signatureinfo)                                          | Yes  | No  | Signature information of the bundle. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_SIGNATURE_INFO** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| installTime                       | number                                                       | Yes  | No  | Time when the bundle was installed.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| updateTime                        | number                                                       | Yes  | No  | Time when the bundle was updated.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| routerMap<sup>12+</sup>           | Array\<[RouterItem](js-apis-bundleManager-hapModuleInfo.md#routeritem12)>           | Yes  | No  | Router table of the application. The table is obtained by deduplicating and combining the **routerMap** information under **hapModulesInfo** based on the **name** field in **RouterItem**. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_HAP_MODULE** and **GET_BUNDLE_INFO_WITH_ROUTER_MAP** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| appIndex<sup>12+</sup>    | number    | Yes  | No  | Index of an application clone. It takes effect only for cloned applications.|
| firstInstallTime<sup>18+</sup>                        | number                                                       | Yes  | Yes  | Time when the application is installed on the current device for the first time.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|


## ReqPermissionDetail

Provides the detailed information of the permissions to request from the system.
> **NOTE**
>
> If multiple packages of an application have requested the same permission but with different reasons, the system returns only one reason based on a descending priority order: entry HAP > feature HAP > in-app HSP.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                 | Type                   | Read-Only| Optional| Description                |
| --------------------- | ----------------------- | ---- | ---- | ---------------------|
| name                  | string                  | No  | No  | Name of the permission to request.  |
| moduleName<sup>10+</sup>            | string                  | No  | No  | Name of the module that requests the permission.  |
| reason                | string                  | No  | No  | Reason for requesting the permission. |
| reasonId              | number                  | No  | No | ID of the reason for requesting the permission.|
| usedScene             | [UsedScene](#usedscene) | No  | No  | Use scenario and timing for using the permission.|



## UsedScene

Describes the use scenario and timing for using the permission.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name     | Type          | Read-Only| Optional| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| abilities | Array\<string> | No  | No  | Abilities that use the permission.  |
| when      | string         | No  | No  | Time when the permission is used. The value can be **inuse** or **always**.         |

## SignatureInfo

Describes the signature information of the bundle.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name     | Type          | Read-Only| Optional| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| appId     | string         | Yes  | No  | Application ID.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                |
|fingerprint| string         | Yes  | No  | Fingerprint information of the bundle. This field changes when the used signing certificate changes.<br>**Atomic service API**: This API can be used in atomic services since API version 11.           |
|appIdentifier<sup>11+</sup>| string         | Yes  | No  | Unique ID of the application. It is a random string allocated by AppGallery Connect during the creation of the application. This ID does not change along the application lifecycle, including version updates, certificate changes, public and private key changes, and application transfers.<br>**Atomic service API**: This API can be used in atomic services since API version 11.           |
|certificate<sup>14+</sup>| string         | Yes  | Yes  | Public key of the application certificate.<br>**Atomic service API**: This API can be used in atomic services since API version 14.           |

## AppCloneIdentity<sup>14+<sup>

Describes the identity information of an application clone.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name     | Type          | Read-Only| Optional| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| bundleName | string         | Yes  | No  | Bundle name of the application.         |
| appIndex | number | Yes  | No  | Index of the application clone.|
