# HapModuleInfo

The module defines the HAP module information. An application can obtain its own HAP module information through [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself), with **GET_BUNDLE_INFO_WITH_HAP_MODULE** passed in for [bundleFlags](js-apis-bundleManager.md#bundleflag).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## HapModuleInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                             | Type                                                        | Read-Only| Optional| Description                |
| --------------------------------- | ------------------------------------------------------------ | ---- | ---- | -------------------- |
| name                              | string                                                       | Yes  | No  | Module name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| icon                              | string                                                       | Yes  | No  | Module icon.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| iconId                            | number                                                       | Yes  | No  | ID of the module icon.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| label                             | string                                                       | Yes  | No  | Module label.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| labelId                           | number                                                       | Yes  | No  | ID of the module label.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| description                       | string                                                       | Yes  | No  | Module description.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| descriptionId                     | number                                                       | Yes  | No  | ID of the module description.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| mainElementName                   | string                                                       | Yes  | No  | Name of the UIAbility or ExtensionAbility that serves as the entry of the current module.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| abilitiesInfo                     | Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>         | Yes  | No  | Ability information. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_HAP_MODULE** and **GET_BUNDLE_INFO_WITH_ABILITY** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| extensionAbilitiesInfo            | Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)> | Yes  | No  | ExtensionAbility information. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_HAP_MODULE** and **GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| metadata                          | Array\<[Metadata](js-apis-bundleManager-metadata.md)>               | Yes  | No  | Metadata of the ability. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_HAP_MODULE** and **GET_BUNDLE_INFO_WITH_METADATA** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| deviceTypes                       | Array\<string>                                               | Yes  | No  | Types of devices that can run the module.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| installationFree                  | boolean                                                      | Yes  | No  | Whether the module supports the installation-free feature. Installation-free means that the module does not need to be explicitly installed through an app market. The value **true** means that the module supports installation-free, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| hashValue                         | string                                                       | Yes  | No  | Hash value of the module.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| type                              | [bundleManager.ModuleType](js-apis-bundleManager.md#moduletype)            | Yes  | No  | Type of the module.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| preloads                          | Array\<[PreloadItem](#preloaditem)>                          | Yes  | No  | Preloaded modules in the atomic service.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| dependencies                      | Array\<[Dependency](#dependency)>                            | Yes  | No  | Dynamic shared libraries on which the module depends.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| fileContextMenuConfig<sup>11+</sup>     | string                                                       | Yes  | No  | File menu configuration of the module. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_HAP_MODULE** and **GET_BUNDLE_INFO_WITH_MENU** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| routerMap<sup>12+</sup>           | Array\<[RouterItem](#routeritem12)>                            | Yes  | No  | [Router table configuration of the module](../../quick-start/module-configuration-file.md#routermap). The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_HAP_MODULE** and **GET_BUNDLE_INFO_WITH_ROUTER_MAP** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| codePath<sup>12+</sup>            | string                                                       | Yes  | No  | Installation path of the module.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| nativeLibraryPath<sup>12+</sup>     | string                                                       | Yes  | No  | Local library file path of the module in the application.                   |

## PreloadItem

Describes the preloaded module information in the atomic service.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name     | Type          | Read-Only| Optional| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
|moduleName | string         | Yes  | No  | Module name.|

## Dependency

Describes the information about the dynamic shared library on which the module depends.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name       | Type  | Read-Only| Optional| Description                  |
| ----------- | ------ | ---- | ---- | ---------------------- |
| bundleName<sup>10+</sup>  | string | Yes  | No  | Name of the shared bundle on which the current module depends.      |
| moduleName  | string | Yes  | No  | Module name of the shared bundle on which the current module depends.|
| versionCode<sup>10+</sup> | number | Yes  | No  | Version number of the shared bundle.  |

## RouterItem<sup>12+</sup>

Describes the router table configuration of the module.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name          | Type  | Read-Only| Optional| Description                  |
| ------------- | ------ | ---- | ---- | ---------------------- |
| name          | string | Yes  | No  | Name of the page to be redirected to.      |
| pageSourceFile| string | Yes  | No  | Path of the page in the module.  |
| buildFunction | string | Yes  | No  | Function decorated by @Builder. The function describes the UI of the page.  |
| data          | Array\<[DataItem](#dataitem12)> | Yes  | No  | User-defined string in the [routing table configuration file](../../quick-start/module-configuration-file.md#routermap), that is, value of the **data** field. This field is parsed by the system. You do not need to parse it.  |
| customData    | string | Yes  | No  | Any type of custom data in the [routing table configuration file](../../quick-start/module-configuration-file.md#routermap), that is, JSON string of the **customData** field. You need to call **JSON.parse** to parse the field.  |

## DataItem<sup>12+</sup>

Describes the user-defined data in the routing table configuration of the module.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name         | Type   | Read-Only| Optional| Description                  |
| ------------- | ------ | ---- | ---- | ---------------------- |
| key           | string | Yes  | No  | Key of the user-defined data.      |
| value         | string | Yes  | No  | Value of the user-defined data.|
