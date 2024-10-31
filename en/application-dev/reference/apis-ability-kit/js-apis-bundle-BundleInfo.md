# BundleInfo

The **BundleInfo** module defines the bundle information, which can be obtained through [bundle.getBundleInfo](js-apis-Bundle.md#bundlegetbundleinfodeprecated).

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## BundleInfo<sup>(deprecated)<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager-BundleInfo](js-apis-bundleManager-bundleInfo.md) instead.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                            | Type                                                        | Read-Only| Optional| Description                                                        |
| -------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                             | string                                                       | Yes  | No  | Bundle name.                                              |
| type                             | string                                                       | Yes  | No  | Bundle type.                                                |
| appId                            | string                                                       | Yes  | No  | ID of the application to which the bundle belongs.                                      |
| uid                              | number                                                       | Yes  | No  | UID of the application to which the bundle belongs.                                     |
| installTime                      | number                                                       | Yes  | No  | Time when the HAP file was installed.                                               |
| updateTime                       | number                                                       | Yes  | No  | Time when the HAP file was updated.                                               |
| appInfo                          | [ApplicationInfo](js-apis-bundle-ApplicationInfo.md)         | Yes  | No  | Application configuration information.                                        |
| abilityInfos                     | Array\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)>         | Yes  | No  | Ability configuration information.<br>The value is obtained by passing in GET_BUNDLE_WITH_ABILITIES to [bundle.getBundleInfo](js-apis-Bundle.md#bundlegetbundleinfodeprecated).|
| reqPermissions                   | Array\<string>                                               | Yes  | No  | Permissions to request from the system for running the application.<br>The value is obtained by passing in GET_BUNDLE_WITH_REQUESTED_PERMISSION to [bundle.getBundleInfo](js-apis-Bundle.md#bundlegetbundleinfodeprecated).|
| reqPermissionDetails             | Array\<[ReqPermissionDetail](#reqpermissiondetaildeprecated)> | Yes  | No  | Detailed information of the permissions to request from the system.<br>The value is obtained by passing in GET_BUNDLE_WITH_REQUESTED_PERMISSION to [bundle.getBundleInfo](js-apis-Bundle.md#bundlegetbundleinfodeprecated).|
| vendor                           | string                                                       | Yes  | No  | Vendor of the bundle.                                            |
| versionCode                      | number                                                       | Yes  | No  | Version number of the bundle.                                            |
| versionName                      | string                                                       | Yes  | No  | Version description of the bundle.                                  |
| compatibleVersion                | number                                                       | Yes  | No  | Earliest SDK version required for running the bundle.                           |
| targetVersion                    | number                                                       | Yes  | No  | Latest SDK version required for running the bundle.                             |
| isCompressNativeLibs             | boolean                                                      | Yes  | No  | Whether to compress the native library of the bundle. The default value is **true**.                        |
| hapModuleInfos                   | Array\<[HapModuleInfo](js-apis-bundle-HapModuleInfo.md)>     | Yes  | No  | Module configuration information.                                            |
| entryModuleName                  | string                                                       | Yes  | No  | Name of the entry module.                                           |
| cpuAbi                           | string                                                       | Yes  | No  | CPU and ABI information of the bundle.                                        |
| isSilentInstallation             | string                                                       | Yes  | No  | Whether the application can be installed in silent mode.                                          |
| minCompatibleVersionCode         | number                                                       | Yes  | No  | Earliest version compatible with the bundle in the distributed scenario.                        |
| entryInstallationFree            | boolean                                                      | Yes  | No  | Whether installation-free is supported for the entry module.                                       |
| reqPermissionStates<sup>8+</sup> | Array\<number>                                               | Yes  | No  | Permission grant state. The value **0** means that the request is successful, and **-1** means the opposite.         |



## ReqPermissionDetail<sup>(deprecated)<sup>

> This API is deprecated since API version 9. You are advised to use [ReqPermissionDetail](js-apis-bundleManager-bundleInfo.md) instead.

Provides the detailed information of the permissions to request from the system.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                 | Type                   | Read-Only| Optional| Description                  |
| --------------------- | ----------------------- | ---- | ---- | ---------------------- |
| name                  | string                  | No  | No  | Name of the permission to request.  |
| reason                | string                  | No  | No  | Reason for requesting the permission.  |
| usedScene             | [UsedScene](#usedscenedeprecated) | No  | No  | Application scenario and timing for using the permission.|



## UsedScene<sup>(deprecated)<sup>

> This API is deprecated since API version 9. You are advised to use [UsedScene](js-apis-bundleManager-bundleInfo.md) instead.

Describes the application scenario and timing for using the permission.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name     | Type          | Read-Only| Optional| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| abilities | Array\<string> | No  | No  | Abilities that use the permission.|
| when      | string         | No  | No  | Time when the permission is used.         |
