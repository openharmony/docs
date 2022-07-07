# ApplicationInfo

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> API version 9 is a canary version for trial use. The APIs of this version may be unstable.

Provides the application information. 

## ApplicationInfo

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name                      | Type                                                        | Readable| Writable| Description                                      |
| -------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------ |
| name                       | string                                                       | Yes  | No  | Application name.                            |
| description                | string                                                       | Yes  | No  | Application description.                            |
| descriptionId              | number                                                       | Yes  | No  | Application description ID.                          |
| systemApp                  | boolean                                                      | Yes  | No  | Whether the application is a system application. The default value is **false**.       |
| enabled                    | boolean                                                      | Yes  | No  | Whether the application is enabled. The default value is **true**.      |
| label                      | string                                                       | Yes  | No  | Application label.                            |
| labelId                    | string                                                       | Yes  | No  | Application label ID.                          |
| icon                       | string                                                       | Yes  | No  | Application icon.                            |
| iconId                     | string                                                       | Yes  | No  | Application icon ID.                          |
| process                    | string                                                       | Yes  | No  | Process in which the application runs. If this parameter is not set, the bundle name is used.|
| supportedModes             | number                                                       | Yes  | No  | Running modes supported by the application.                    |
| moduleSourceDirs           | Array\<string>                                               | Yes  | No  | Relative paths for storing application resources.              |
| permissions                | Array\<string>                                               | Yes  | No  | Permissions required for accessing the application.                    |
| moduleInfos                | Array\<[ModuleInfo](js-apis-bundle-ModuleInfo.md)>           | Yes  | No  | Application module information.                        |
| entryDir                   | string                                                       | Yes  | No  | Path for storing application files.                    |
| codePath<sup>8+</sup>      | string                                                       | Yes  | No  | Installation directory of the application.                        |
| metaData<sup>8+</sup>      | Map\<string, Array\<[CustomizeData](js-apis-bundle-CustomizeData.md)>> | Yes  | No  | Custom metadata of the application.                    |
| metadata<sup>9+</sup>      | Map\<string, Array\<[Metadata](js-apis-bundle-Metadata.md)>> | Yes  | No  | Metadata of the application.                          |
| removable<sup>8+</sup>     | boolean                                                      | Yes  | No  | Whether the application is removable.                    |
| accessTokenId<sup>8+</sup> | number                                                       | Yes  | No  | Access token ID of the application.                   |
| uid<sup>8+</sup>           | number                                                       | Yes  | No  | UID of the application.                             |
| entityType<sup>8+</sup>    | string                                                       | Yes  | No  | Entity type of the application.                        |
