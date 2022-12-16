# ApplicationInfo

The **ApplicationInfo** module provides information about an application. Unless otherwise specified, the information is obtained through [GET_APPLICATION_INFO_DEFAULT](js-apis-bundleManager.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ApplicationInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Core
| Name                      | Type                                                        | Readable| Writable| Description                                                        |
| -------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                       | string                                                       | Yes  | No  | Application name.                                                |
| description                | string                                                       | Yes  | No  | Application description.                                                |
| descriptionId              | number                                                       | Yes  | No  | ID of the application description.                                  |
| enabled                    | boolean                                                      | Yes  | No  | Whether the application is enabled. The default value is **true**.                          |
| label                      | string                                                       | Yes  | No  | Application label.                                                |
| labelId                    | number                                                 | Yes  | No  | ID of the application label.                                  |
| icon                       | string                                                       | Yes  | No  | Application icon.                                                |
| iconId                     | number                                                 | Yes  | No  | ID of the application icon.                                              |
| process                    | string                                                       | Yes  | No  | Process in which the application runs. If this parameter is not set, the bundle name is used.                  |
| permissions                | Array\<string>                                               | Yes  | No  | Permissions required for accessing the application. The information is obtained by using **GET_APPLICATION_INFO_WITH_PERMISSION**.|
| entryDir                   | string                                                       | Yes  | No  | Path for storing application files.                                        |
| codePath                   | string                                                       | Yes  | No  | Installation directory of the application.                                            |
| metadata                   | Map\<string, Array\<[Metadata](js-apis-bundleManager-metadata.md)>> | Yes  | No  | Metadata of the application. The information is obtained by using **GET_APPLICATION_INFO_WITH_METADATA**.|
| removable                  | boolean                                                      | Yes  | No  | Whether the application is removable.                                        |
| accessTokenId             | number                                                       | Yes  | No  | Access token ID of the application.                                     |
| uid                       | number                                                       | Yes  | No  | UID of the application.                                               |
| iconResource              | [Resource](js-apis-resource-manager.md#resource9) | Yes| No| Icon resource of the application.                        |
| labelResource             | [Resource](js-apis-resource-manager.md#resource9) | Yes| No| Label resource of the application.                        |
| descriptionResource       | [Resource](js-apis-resource-manager.md#resource9) | Yes| No| Description resource of the application.                        |
| appDistributionType       | string                                                       | Yes  | No  | Distribution type of the application signing certificate. The options are **app_gallery**, **enterprise**, **os_integration**, and **crowdtesting**.   |
| appProvisionType          | string                                                       | Yes  | No  | Type of the application signing certificate file. The options are **debug** and **release**.          |
