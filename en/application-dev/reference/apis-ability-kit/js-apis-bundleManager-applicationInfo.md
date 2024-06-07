# ApplicationInfo

The **ApplicationInfo** module defines the application information. A third-party application can obtain its own application information through [bundleManager.getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself), with **GET_BUNDLE_INFO_WITH_APPLICATION** passed in to [bundleFlags](js-apis-bundleManager.md#bundleflag).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ApplicationInfo

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                      | Type                                                        | Readable| Writable| Description                                                        |
| -------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                       | string                                                       | Yes  | No  | Application name.                                                |
| description                | string                                                       | Yes  | No  | Description of the application, for example, "description": $string: mainability_description". For details, see the description of the **descriptionResource** field below.                                                |
| descriptionId              | number                                                       | Yes  | No  | ID of the application description.                                              |
| enabled                    | boolean                                                      | Yes  | No  | Whether the application is enabled. The default value is **true**.                          |
| label                      | string                                                       | Yes  | No  | Application name, for example, "label": "$string: mainability_description". For details, see the description of the **labelResource** field below.|
| labelId                    | number                                                       | Yes  | No  | ID of the application label.                                              |
| icon                       | string                                                       | Yes  | No  | Application icon, for example, "icon": "$media:icon". For details, see the description of the **iconResource** field below.                                                |
| iconId                     | number                                                       | Yes  | No  | ID of the application icon.                                              |
| process                    | string                                                       | Yes  | No  | Process in which the application runs. If this parameter is not set, the bundle name is used.                  |
| permissions                | Array\<string>                                               | Yes  | No  | Permissions required for accessing the application. The permissions can be obtained by passing in **GET_BUNDLE_INFO_WITH_APPLICATION** and **GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).|
| codePath                   | string                                                       | Yes  | No  | Installation directory of the application.                                            |
| metadata<sup>(deprecated)<sup>  | Map\<string, Array\<[Metadata](js-apis-bundleManager-metadata.md)>> | Yes  | No  | Metadata of the application. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_APPLICATION** and **GET_BUNDLE_INFO_WITH_METADATA** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself). **NOTE**<br>This field is deprecated since API version 10. You are advised to use **metadataArray** instead.|
| metadataArray<sup>10+</sup>              | Array\<[ModuleMetadata](#modulemetadata10)> | Yes  | No  | Metadata of the application. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_APPLICATION** and **GET_BUNDLE_INFO_WITH_METADATA** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).|
| removable                  | boolean                                                      | Yes  | No  | Whether the application is removable.                                        |
| accessTokenId             | number                                                       | Yes  | No  | Access token ID of the application.                                     |
| uid                       | number                                                       | Yes  | No  | UID of the application.                                               |
| iconResource              | [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) | Yes| No| Resource information of the application icon. The resource information obtained contains the bundle name, module name, and ID of the resource. You can call [getMediaContent](../apis-localization-kit/js-apis-resource-manager.md#getmediacontent9) to obtain the resource details.                    |
| labelResource             | [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) | Yes| No| Resource information of the application label. The resource information obtained contains the bundle name, module name, and ID of the resource. You can call [getMediaContent](../apis-localization-kit/js-apis-resource-manager.md#getmediacontent9) to obtain the resource details.                        |
| descriptionResource       | [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) | Yes| No| Resource information of the application description. The resource information obtained contains the bundle name, module name, and ID of the resource. You can call [getMediaContent](../apis-localization-kit/js-apis-resource-manager.md#getmediacontent9) to obtain the resource details.|
| appDistributionType       | string                                                       | Yes  | No  | Distribution type of the application signing certificate. The options are **app_gallery**, **enterprise**, **os_integration**, and **crowdtesting**.   |
| appProvisionType          | string                                                       | Yes  | No  | Type of the application signing certificate file. The options are **debug** and **release**.          |
| systemApp          | boolean                                                       | Yes  | No  | Whether the application is a system application.          |
| bundleType                |[BundleType](js-apis-bundleManager.md#bundletype)             | Yes  | No  | Bundle type, which can be **APP** (application) or **ATOMIC_SERVICE** (atomic service).                               |
| debug<sup>10+</sup>       | boolean                                | Yes  | No  | Whether the application is in debugging mode. The default value is **false**.       |
| dataUnclearable<sup>11+</sup>       | boolean                      | Yes  | No  | Whether the application data is unclearable. The value **true** means that the application data is unclearable, and **false** means the opposite. The default value is **false**.       |
| nativeLibraryPath<sup>12+</sup> | string                                                                     | Yes  | No  | Local library file path of the application.                                                                                                  |

## PreinstalledApplicationInfo<sup>12+<sup>

Describes the information about a preinstalled application.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name     | Type          | Readable| Writable| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| bundleName     | string         | Yes  | No  | Bundle name of the application.                |
| moduleName | string         | Yes  | No  | Module name of the application. By default, the name of the entry module is returned. If the entry module does not exist, the name of the feature module is returned.           |
| iconId | number         | Yes  | No  | Icon ID of the application.           |
| labelId | number         | Yes  | No  | Label ID of the application.           |

## ModuleMetadata<sup>10+</sup>

Describes the metadata of a module.

**Atomic service API**: This API can be used in atomic services since API version 11.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name     | Type          | Readable| Writable| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| moduleName<sup>10+</sup>| string         | Yes  | No  | Module name.  |
| metadata<sup>10+</sup>  | Array\<[Metadata](js-apis-bundleManager-metadata.md)>      | Yes  | No  | Metadata list of the module.|
