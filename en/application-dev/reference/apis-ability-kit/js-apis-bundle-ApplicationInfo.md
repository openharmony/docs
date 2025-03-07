# ApplicationInfo

The **ApplicationInfo** module provides application information. Unless otherwise specified, the information is obtained through [bundle.getApplicationInfo](js-apis-Bundle.md#bundlegetapplicationinfodeprecated).

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ApplicationInfo<sup>(deprecated)<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager-ApplicationInfo](js-apis-bundleManager-applicationInfo.md) instead.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name                      | Type                                                        | Read-Only| Optional| Description                                                        |
| -------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                       | string                                                       | Yes  | No  | Application name.                                            |
| description                | string                                                       | Yes  | No  | Application description.                                        |
| descriptionId              | number                                                       | Yes  | No  | ID of the application description.                                |
| systemApp                  | boolean                                                      | Yes  | No  | Whether the application is a system application. The value **true** means that the application is a system application, and **false** means the opposite.                       |
| enabled                    | boolean                                                      | Yes  | No  | Whether the application is enabled. The value **true** means that the application is enabled, and **false** means the opposite.                      |
| label                      | string                                                       | Yes  | No  | Application label.                                        |
| labelId                    | string                                                       | Yes  | No  | ID of the application label.                                  |
| icon                       | string                                                       | Yes  | No  | Application icon.                                            |
| iconId                     | string                                                       | Yes  | No  | ID of the application icon.                                    |
| process                    | string                                                       | Yes  | No  | Process name.                |
| supportedModes             | number                                                       | Yes  | No  | Modes supported by the application. Currently, only the **drive** mode is defined. This attribute applies only to telematics devices.|
| moduleSourceDirs           | Array\<string>                                               | Yes  | No  | Relative paths for storing application resources. Do not access resource files using concatenated paths. Use [@ohos.resourceManager](../apis-localization-kit/js-apis-resource-manager.md) instead.                              |
| permissions                | Array\<string>                                               | Yes  | No  | Permissions required for accessing the application.<br>The value is obtained by passing in GET_APPLICATION_INFO_WITH_PERMISSION to [bundle.getApplicationInfo](js-apis-Bundle.md#bundlegetapplicationinfodeprecated).|
| moduleInfos                | Array\<[ModuleInfo](js-apis-bundle-ModuleInfo.md)>           | Yes  | No  | Application module information.                                        |
| entryDir                   | string                                                       | Yes  | No  | Path for storing application files. Do not access resource files using concatenated paths. Use [@ohos.resourceManager](../apis-localization-kit/js-apis-resource-manager.md) instead.                                    |
| codePath<sup>8+</sup>      | string                                                       | Yes  | No  | Installation directory of the application. Do not access resource files using concatenated paths. Use [@ohos.resourceManager](../apis-localization-kit/js-apis-resource-manager.md) instead.                                        |
| metaData<sup>8+</sup>      | Map\<string, Array\<[CustomizeData](js-apis-bundle-CustomizeData.md)>> | Yes  | No  | Custom metadata of the application.<br>The value is obtained by passing in GET_APPLICATION_INFO_WITH_METADATA to [bundle.getApplicationInfo](js-apis-Bundle.md#bundlegetapplicationinfodeprecated).|
| removable<sup>8+</sup>     | boolean                                                      | Yes  | No  | Whether the application is removable. The value **true** means that the application is removable, and **false** means the opposite.                                    |
| accessTokenId<sup>8+</sup> | number                                                       | Yes  | No  | Access token ID of the application.                                   |
| uid<sup>8+</sup>           | number                                                       | Yes  | No  | UID of the application.                                             |
| entityType                 | string                                                       | Yes  | No  | Type of the application, for example, gaming, social networking, movies, and news.|
