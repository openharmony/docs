# HapModuleInfo

The **HapModuleInfo** module defines the HAP module information. A system application can obtain its own or others' HAP module information through [bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo). A third-party application can obtain its own HAP module information through [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself). The input parameter [bundleFlags](js-apis-bundleManager.md#bundleflag) must be set to **GET_BUNDLE_INFO_WITH_HAP_MODULE**.

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
| moduleType                        | [ModuleType](js-apis-bundleManager.md#moduletype)            | Yes  | No  | Type of the module.     |
| preloads                          | Array\<[PreloadItem](#preloaditem)>                          | Yes  | No  | Preloaded modules in the atomic service.|
| dependencies                      | Array\<[Dependency](#dependency)>                            | Yes  | No  | Dynamic shared libraries on which the module depends. |

## PreloadItem

Describes the preloaded module information in the atomic service.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name     | Type          | Readable| Writable| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
|moduleName | string         | Yes  | No  | Name of the module automatically preloaded by the system.|

## Dependency

Describes the information about the dynamic shared library on which the module depends.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name       | Type  | Readable| Writable| Description                  |
| ----------- | ------ | ---- | ---- | ---------------------- |
| moduleName  | string | Yes  | No  | Module name of the shared bundle on which the current module depends.|
