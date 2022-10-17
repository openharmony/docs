# Device Information

The **deviceInfo** module provides product information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import deviceInfo from '@ohos.deviceInfo'
```

## Attributes

**System capability**: SystemCapability.Startup.SystemInfo

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| deviceType | string | Yes| No| Device type.|
| manufacture | string | Yes| No| Device manufacturer.|
| brand | string | Yes| No| Device brand.|
| marketName | string | Yes| No| Marketing name.|
| productSeries | string | Yes| No| Product series.|
| productModel | string | Yes| No| Product model.|
| softwareModel | string | Yes| No| Software model.|
| hardwareModel | string | Yes| No| Hardware model.|
| hardwareProfile | string | Yes| No| Hardware profile.|
| serial | string | Yes| No| Device serial number.<br>**Required permissions**: ohos.permission.sec.ACCESS_UDID (a system permission)|
| bootloaderVersion | string | Yes| No| Bootloader version.|
| abiList | string | Yes| No| Application binary interface (Abi) list.|
| securityPatchTag | string | Yes| No| Security patch tag.|
| displayVersion | string | Yes| No| Product version.|
| incrementalVersion | string | Yes| No| Incremental version.|
| osReleaseType | string | Yes| No| OS release type. The options are as follows:<br>- **Canary**: Preliminary release open only to specific developers. This release does not promise API stability and may require tolerance of instability.<br>- **Beta**: Release open to all developers. This release does not promise API stability and may require tolerance of instability.<br>- **Release**: Official release open to all developers. This release promises that all APIs are stable.|
| osFullName | string | Yes| No| OS version.|
| majorVersion | number | Yes| No| Major version, incrementing along with OS version updates.|
| seniorVersion | number | Yes| No| Senior version, incrementing along with architecture and feature updates.|
| featureVersion | number | Yes| No| Feature version.|
| buildVersion | number | Yes| No| Build version.|
| sdkApiVersion | number | Yes| No| SDK API version.|
| firstApiVersion | number | Yes| No| First API version.|
| versionId | string | Yes| No| Version ID.|
| buildType | string | Yes| No| Build type.|
| buildUser | string | Yes| No| Build user.|
| buildHost | string | Yes| No| Build host.|
| buildTime | string | Yes| No| Build time.|
| buildRootHash | string | Yes| No| Build root hash.|
| udid<sup>7+</sup> | string | Yes| No| Device UDID.<br>**Required permissions**: ohos.permission.sec.ACCESS_UDID (a system permission)|
