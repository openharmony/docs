# AppProvisionInfo (System API)

The **AppProvisionInfo** module provides information in the [HarmonyAppProvision configuration file](../../security/app-provision-structure.md). The information can be obtained through [getAppProvisionInfo](./js-apis-bundleManager-sys.md#bundlemanagergetappprovisioninfo10).

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## AppProvisionInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name                     | Type  | Read-Only| Optional| Description                |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| versionCode              | number | Yes  | No  | Version number of the configuration file.|
| versionName              | string | Yes  | No  | Version name of the configuration file. |
| uuid                     | string | Yes  | No  | UUID in the configuration file.|
| type                     | string | Yes  | No  | Type of the configuration file, which can be **debug** or **release**.|
| appDistributionType      | string | Yes  | No  | [Distribution type](../../security/app-provision-structure.md) in the configuration file.|
| validity                 | [Validity](#validity) | Yes  | No  | Validity period in the configuration file.|
| developerId              | string | Yes  | No  | Developer ID in the configuration file.|
| certificate              | string | Yes  | No  | Certificate public key in the configuration file.|
| apl                      | string | Yes  | No  | APL in the configuration file, which can be **normal**, **system_basic**, or **system_core**.|
| issuer                      | string | Yes  | No  | Issuer name in the configuration file.|
|appIdentifier<sup>11+</sup>| string         | Yes  | No  | Unique ID of the application. It is the [app ID](https://developer.huawei.com/consumer/en/doc/app/agc-help-createharmonyapp-0000001945392297), which is a random string, allocated by AppGallery Connect during the creation of the application. This ID does not change along the application lifecycle, including version updates, certificate changes, public and private key changes, and application transfers. If you use multiple debugging devices, perform debugging offline, or need to interact with other applications, you are advised to use [manual signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section297715173233).           |
| organization<sup>12+</sup> | string | Yes  | No  | Organization of the application.|

## Validity

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name                     | Type  | Read-Only| Optional| Description                |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| notBefore                 | number | Yes  | No  | Timestamp of the earliest valid date for the configuration file.|
| notAfter                  | number | Yes  | No  | Timestamp of the latest valid date for the configuration file.|
