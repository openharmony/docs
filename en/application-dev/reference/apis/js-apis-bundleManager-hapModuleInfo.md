# HapModuleInfo

The **HapModuleInfo** module defines the HAP module information. A system application can obtain its own or others' HAP module information through [bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo). A third-party application can obtain its own HAP module information through [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself). **GET_BUNDLE_INFO_WITH_HAP_MODULE** must be passed in to the input parameter [bundleFlags](js-apis-bundleManager.md#bundleflag) to obtain the information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## HapModuleInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                             | Type                                                        | Readable| Writable| Description                |
| --------------------------------- | ------------------------------------------------------------ | ---- | ---- | -------------------- |
| name                              | string                                                       | Yes  | No  | Module name.            |
| icon                              | string                                                       | Yes  | No  | Module icon.            |
| iconId                            | number                                                       | Yes  | No  | ID of the module icon.      |
| label                             | string                                                       | Yes  | No  | Module label.            |
| labelId                           | number                                                       | Yes  | No  | ID of the module label.      |
| description                       | string                                                       | Yes  | No  | Module description.        |
| descriptionId                     | number                                                       | Yes  | No  | ID of the module description.      |
| mainElementName                   | string                                                       | Yes  | No  | Name of the main ability.     |
| abilitiesInfo                     | Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>         | Yes  | No  | Ability information.         |
| extensionAbilitiesInfo            | Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)> | Yes  | No  | ExtensionAbility information.|
| metadata                          | Array\<[Metadata](js-apis-bundleManager-metadata.md)>               | Yes  | No  | Metadata of the ability.     |
| deviceTypes                       | Array\<string>                                               | Yes  | No  | Types of devices where the module can run.  |
| installationFree                  | boolean                                                      | Yes  | No  | Whether installation-free is supported.      |
| hashValue                         | string                                                       | Yes  | No  | Hash value of the module.             |
