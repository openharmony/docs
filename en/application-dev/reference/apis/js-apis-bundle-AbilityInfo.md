# AbilityInfo

Unless otherwise specified, ability information is obtained through **GET_BUNDLE_DEFAULT**.

> **NOTE**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## AbilityInfo

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name                 | Type                                                    | Readable| Writable| Description                                     |
| --------------------- | -------------------------------------------------------- | ---- | ---- | ----------------------------------------- |
| bundleName            | string                                                   | Yes  | No  | Bundle name of the application.                                 |
| name                  | string                                                   | Yes  | No  | Ability name.                              |
| label                 | string                                                   | Yes  | No  | Ability name visible to users.                  |
| description           | string                                                   | Yes  | No  | Ability description.                            |
| icon                  | string                                                   | Yes  | No  | Index of the ability icon resource file.                |
| descriptionId         | number                                                   | Yes  | No  | Ability description ID.                          |
| iconId                | number                                                   | Yes  | No  | Ability icon ID.                          |
| moduleName            | string                                                   | Yes  | No  | Name of the HAP file to which the ability belongs.                 |
| process               | string                                                   | Yes  | No  | Process in which the ability runs. If this parameter is not set, the bundle name is used.|
| targetAbility         | string                                                   | Yes  | No  | Target ability that the ability alias points to.<br>This attribute can be used only in the FA model.|
| backgroundModes       | number                                                   | Yes  | No  | Background service mode of the ability.<br>This attribute can be used only in the FA model.    |
| isVisible             | boolean                                                  | Yes  | No  | Whether the ability can be called by other applications.        |
| formEnabled           | boolean                                                  | Yes  | No  | Whether the ability provides the service widget capability.<br>This attribute can be used only in the FA model.|
| type                  | AbilityType                                              | Yes  | No  | Ability type.<br>This attribute can be used only in the FA model.           |
| orientation           | DisplayOrientation                                       | Yes  | No  | Ability display orientation.                        |
| launchMode            | LaunchMode                                               | Yes  | No  | Ability launch mode.                        |
| permissions           | Array\<string>                                           | Yes  | No  | Permissions required for other applications to call the ability.<br>The value is obtained by passing **GET_ABILITY_INFO_WITH_PERMISSION**.|
| deviceTypes           | Array\<string>                                           | Yes  | No  | Device types supported by the ability.                    |
| deviceCapabilities    | Array\<string>                                           | Yes  | No  | Device capabilities required for the ability.                    |
| readPermission        | string                                                   | Yes  | No  | Permission required for reading the ability data.<br>This attribute can be used only in the FA model.|
| writePermission       | string                                                   | Yes  | No  | Permission required for writing data to the ability.<br>This attribute can be used only in the FA model.|
| applicationInfo       | [ApplicationInfo](js-apis-bundle-ApplicationInfo.md)     | Yes  | No  | Application configuration information.<br>The value is obtained by passing **GET_ABILITY_INFO_WITH_APPLICATION**.|
| uri                   | string                                                   | Yes  | No  | URI of the ability.<br>This attribute can be used only in the FA model.|
| labelId               | number                                                   | Yes  | No  | Ability label ID.                          |
| subType               | AbilitySubType                                           | Yes  | No  | Subtype of the template that can be used by the ability.<br>This attribute can be used only in the FA model.|
| metaData<sup>8+</sup> | Array\<[CustomizeData](js-apis-bundle-CustomizeData.md)> | Yes  | No  | Custom metadata of the ability.<br>The value is obtained by passing **GET_ABILITY_INFO_WITH_METADATA**.|
| metadata<sup>9+</sup> | Array\<[Metadata](js-apis-bundle-Metadata.md)>           | Yes  | No  | Metadata of the ability.<br>The value is obtained by passing **GET_ABILITY_INFO_WITH_METADATA**.|
| enabled<sup>8+</sup>  | boolean                                                  | Yes  | No  | Whether the ability is enabled.                          |
| supportWindowMode<sup>9+</sup>  | Array\<[SupportWindowMode](js-apis-Bundle.md)> | Yes  | No  | Window modes supported by the ability.                     |
| maxWindowRatio<sup>9+</sup>  | number                                            | Yes  | No  | Maximum window ratio supported by the ability.                     |
| minWindowRatio<sup>9+</sup>  | number                                            | Yes  | No  | Minimum window ratio supported by ability.                     |
| maxWindowWidth<sup>9+</sup>  | number                                            | Yes  | No  | Maximum window width supported by the ability.                     |
| minWindowWidth<sup>9+</sup>  | number                                            | Yes  | No  | Minimum window width supported by the ability.                     |
| maxWindowHeight<sup>9+</sup>  | number                                           | Yes  | No  | Maximum window height supported by the ability.                     |
| minWindowHeight<sup>9+</sup>  | number                                           | Yes  | No  | Minimum window height supported by the ability.                     |
