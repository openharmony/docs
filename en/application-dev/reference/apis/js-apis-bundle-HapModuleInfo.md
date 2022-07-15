# HapModuleInfo



> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.



Provides the HAP module information.

## HapModuleInfo

**System capability**: SystemCapability.BundleManager.BundleFramework



| Name                             | Type                                                        | Readable| Writable| Description                |
| --------------------------------- | ------------------------------------------------------------ | ---- | ---- | -------------------- |
| name                              | string                                                       | Yes  | No  | Module name.            |
| description                       | string                                                       | Yes  | No  | Module description.        |
| descriptionId                     | number                                                       | Yes  | No  | Module description ID.          |
| icon                              | string                                                       | Yes  | No  | Module icon.            |
| label                             | string                                                       | Yes  | No  | Module label.            |
| labelId                           | number                                                       | Yes  | No  | Module label ID.          |
| iconId                            | number                                                       | Yes  | No  | Module icon ID.          |
| backgroundImg                     | string                                                       | Yes  | No  | Module background image.        |
| supportedModes                    | number                                                       | Yes  | No  | Running modes supported by the module.      |
| reqCapabilities                   | Array\<string>                                               | Yes  | No  | Capabilities required for module running.  |
| deviceTypes                       | Array\<string>                                               | Yes  | No  | Device types supported by the module.  |
| abilityInfo                       | Array\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)>         | Yes  | No  | Ability information.         |
| moduleName                        | string                                                       | Yes  | No  | Module name.              |
| mainAbilityName                   | string                                                       | Yes  | No  | Name of the main ability.     |
| installationFree                  | boolean                                                      | Yes  | No  | Whether installation-free is supported.      |
| mainElementName<sup>9+</sup>      | string                                                       | Yes  | No  | Information about the main ability.     |
| extensionAbilityInfo<sup>9+</sup> | Array\<[ExtensionAbilityInfo](js-apis-bundle-ExtensionAbilityInfo.md)> | Yes  | No  | Information about the Extension ability.|
| metadata<sup>9+</sup>             | Array\<[Metadata](js-apis-bundle-Metadata.md)>               | Yes  | No  | Metadata of the ability.     |
| hashValue<sup>9+</sup>            | string                                                       | Yes  | No  | Hash value of the module.     |
