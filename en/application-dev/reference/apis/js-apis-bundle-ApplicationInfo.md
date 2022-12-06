# ApplicationInfo

The **ApplicationInfo** module provides application information. Unless otherwise specified, all attributes are obtained through **GET_BUNDLE_DEFAULT**.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ApplicationInfo<sup>(deprecated)<sup>

> This API is deprecated since API version 9. You are advised to use [ApplicationInfo](js-apis-bundleManager-applicationInfo.md) instead.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name                      | Type                                                        | Readable| Writable| Description                                                        |
| -------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                       | string                                                       | Yes  | No  | Application name.                                              |
| description                | string                                                       | Yes  | No  | Application description.                                              |
| descriptionId              | number                                                       | Yes  | No  | Application description ID.                                            |
| systemApp                  | boolean                                                      | Yes  | No  | Whether the application is a system application. The default value is **false**.                         |
| enabled                    | boolean                                                      | Yes  | No  | Whether the application is enabled. The default value is **true**.                        |
| label                      | string                                                       | Yes  | No  | Application label.                                              |
| labelId<sup>(deprecated)</sup> | string                                                       | Yes  | No  | Application label ID.<br>\- **NOTE**: This attribute is deprecated from API version 9. Use **labelIndex** instead.|
| icon                       | string                                                       | Yes  | No  | Application icon.                                              |
| iconId<sup>(deprecated)</sup> | string                                                       | Yes  | No  | Application icon ID.<br>\- **NOTE**: This attribute is deprecated from API version 9. Use **iconIndex** instead.|
| process                    | string                                                       | Yes  | No  | Process in which the application runs. If this parameter is not set, the bundle name is used.                  |
| supportedModes             | number                                                       | Yes  | No  | Running modes supported by the application.                                      |
| moduleSourceDirs           | Array\<string>                                               | Yes  | No  | Relative paths for storing application resources.                                |
| permissions                | Array\<string>                                               | Yes  | No  | Permissions required for accessing the application.<br>The value is obtained by passing **GET_APPLICATION_INFO_WITH_PERMISSION**.|
| moduleInfos                | Array\<[ModuleInfo](js-apis-bundle-ModuleInfo.md)>           | Yes  | No  | Application module information.                                          |
| entryDir                   | string                                                       | Yes  | No  | Path for storing application files.                                      |
| codePath<sup>8+</sup>      | string                                                       | Yes  | No  | Installation directory of the application.                                          |
| metaData<sup>8+</sup>      | Map\<string, Array\<[CustomizeData](js-apis-bundle-CustomizeData.md)>> | Yes  | No  | Custom metadata of the application.<br>The value is obtained by passing **GET_APPLICATION_INFO_WITH_METADATA**.|
| removable<sup>8+</sup>     | boolean                                                      | Yes  | No  | Whether the application is removable.                                      |
| accessTokenId<sup>8+</sup> | number                                                       | Yes  | No  | Access token ID of the application.                                     |
| uid<sup>8+</sup>           | number                                                       | Yes  | No  | UID of the application.                                               |
| entityType<sup>8+</sup>    | string                                                       | Yes  | No  | Entity type of the application.                                          |
