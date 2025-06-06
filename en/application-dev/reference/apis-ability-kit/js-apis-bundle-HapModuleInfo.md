# HapModuleInfo

The HapModuleInfo module provides information about an HAP module. Unless otherwise specified, the information is obtained through [bundle.getBundleInfo](js-apis-Bundle.md#bundlegetbundleinfodeprecated).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The APIs of this module are deprecated since API version 9. You are advised to use [bundleManager-HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md) instead.

## HapModuleInfo<sup>(deprecated)<sup>

This API is deprecated since API version 9. You are advised to use [bundleManager-HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md#hapmoduleinfo-1) instead.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name                             | Type                                                        | Read-Only| Optional| Description                |
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
| installationFree                  | boolean                                                      | Yes  | No  | Whether installation-free is supported. The value **true** means that installation-free is supported, and **false** means the opposite.      |
