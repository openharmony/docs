# AbilityInfo

The **AbilityInfo** module provides information about an ability. Unless otherwise specified, the information is obtained through [GET_ABILITY_INFO_DEFAULT](js-apis-bundleManager.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## AbilityInfo

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                 | Type                                                    | Readable| Writable| Description                                     |
| --------------------- | -------------------------------------------------------- | ---- | ---- | ----------------------------------------- |
| bundleName            | string                                                   | Yes  | No  | Bundle name.                                 |
| moduleName            | string                                                   | Yes  | No  | Name of the HAP file to which the ability belongs.                 |
| name                  | string                                                   | Yes  | No  | Ability name.                              |
| label                 | string                                                   | Yes  | No  | Ability name visible to users.                  |
| labelId               | number                                                   | Yes  | No  | ID of the ability label.                     |
| description           | string                                                   | Yes  | No  | Ability description.                            |
| descriptionId         | number                                                   | Yes  | No  | ID of the ability description.                      |
| icon                  | string                                                   | Yes  | No  | Index of the ability icon resource file.                |
| iconId                | number                                                   | Yes  | No  | ID of the ability icon.                      |
| process               | string                                                   | Yes  | No  | Process in which the ability runs. If this parameter is not set, the bundle name is used.|
| isVisible             | boolean                                                  | Yes  | No  | Whether the ability can be called by other bundles.        |
| type                  | [AbilityType](js-apis-bundleManager.md#abilitytype)      | Yes  | No  | Ability type.<br>This attribute can be used only in the FA model.           |
| orientation           | [DisplayOrientation](js-apis-bundleManager.md#displayorientation)  | Yes  | No  | Ability display orientation.                        |
| launchType            | [LaunchType](js-apis-bundleManager.md#launchtype)        | Yes  | No  | Ability launch mode.                        |
| permissions           | Array\<string>                                           | Yes  | No  | Permissions required for other bundles to call the ability. The information is obtained by using **GET_ABILITY_INFO_WITH_PERMISSION**.|
| readPermission        | string                                                   | Yes  | No  | Permission required for reading the ability data.<br>This attribute can be used only in the FA model.|
| writePermission       | string                                                   | Yes  | No  | Permission required for writing data to the ability.<br>This attribute can be used only in the FA model.|
| uri                   | string                                                   | Yes  | No  | URI of the ability.<br>This attribute can be used only in the FA model.|
| deviceTypes           | Array\<string>                                           | Yes  | No  | Device types supported by the ability.                    |
| applicationInfo       | [ApplicationInfo](js-apis-bundleManager-applicationInfo.md)     | Yes  | No  | Application information. The information is obtained by using **GET_ABILITY_INFO_WITH_APPLICATION**.|
| metadata              | Array\<[Metadata](js-apis-bundleManager-metadata.md)>           | Yes  | No  | Metadata of the ability. The information is obtained by using **GET_ABILITY_INFO_WITH_METADATA**.|
| enabled               | boolean                                                  | Yes  | No  | Whether the ability is enabled.                          |
| supportWindowModes    | Array\<[SupportWindowMode](js-apis-bundleManager.md#supportwindowmode)> | Yes  | No  | Window modes supported by the ability.                     |
| windowSize|[WindowSize](#windowsize)                                            |    Yes  | No  | Window size.|

## WindowSize

Describes the window size.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name              | Type   | Readable| Writable| Description                              |
| -------------------| ------- | ---- | ---- | ---------------------------------- |
| maxWindowRatio     | number  | Yes  | No  | Maximum aspect ratio of the window in free window mode. The value ranges from 0 to 1.|
| minWindowRatio     | number  | Yes  | No  | Minimum aspect ratio of the window in free window mode. The value ranges from 0 to 1.|
| maxWindowWidth     | number  | Yes  | No  | Maximum width of the window in free window mode. The unit is vp.|
| minWindowWidth     | number  | Yes  | No  | Minimum width of the window in free window mode. The unit is vp.|
| maxWindowHeight    | number  | Yes  | No  | Maximum height of the window in free window mode. The unit is vp.|
| minWindowHeight    | number  | Yes  | No  | Maximum height of the window in free window mode. The unit is vp.|
