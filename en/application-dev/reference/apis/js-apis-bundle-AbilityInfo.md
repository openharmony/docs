# AbilityInfo



> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.



Provides the ability information.

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
| targetAbility         | string                                                   | Yes  | No  | Target ability that the ability alias points to.             |
| backgroundModes       | number                                                   | Yes  | No  | Background service mode of the ability.                       |
| isVisible             | boolean                                                  | Yes  | No  | Whether the ability can be called by other applications.        |
| formEnabled           | boolean                                                  | Yes  | No  | Whether the ability provides the service widget capability.              |
| type                  | AbilityType                                              | Yes  | No  | Ability type.                              |
| orientation           | DisplayOrientation                                       | Yes  | No  | Ability display orientation.                        |
| launchMode            | LaunchMode                                               | Yes  | No  | Ability launch mode.                        |
| permissions           | Array\<string>                                           | Yes  | No  | Permissions required for other applications to call the ability.|
| deviceTypes           | Array\<string>                                           | Yes  | No  | Device types supported by the ability.                    |
| deviceCapabilities    | Array\<string>                                           | Yes  | No  | Device capabilities required for the ability.                    |
| readPermission        | string                                                   | Yes  | No  | Permission required for reading the ability data.                |
| writePermission       | string                                                   | Yes  | No  | Permission required for writing data to the ability.                |
| applicationInfo       | [ApplicationInfo](js-apis-bundle-ApplicationInfo.md)     | Yes  | No  | Application configuration information.                       |
| uri                   | string                                                   | Yes  | No  | URI of the ability.       |
| labelId               | number                                                   | Yes  | No  | Ability label ID.                          |
| subType               | AbilitySubType                                           | Yes  | No  | Subtype of the template that can be used by the ability.          |
| metaData<sup>8+</sup> | Array\<[CustomizeData](js-apis-bundle-CustomizeData.md)> | Yes  | No  | Custom metadata of the ability.                      |
| metaData<sup>9+</sup> | Array\<[Metadata](js-apis-bundle-Metadata.md)>           | Yes  | No  | Metadata of the ability.                          |
| enabled<sup>8+</sup>  | boolean                                                  | Yes  | No  | Whether the ability is enabled.                          |
