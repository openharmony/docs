# ApplicationInfo
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module defines the application information. An application can obtain its own application information through [bundleManager.getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself), with **GET_BUNDLE_INFO_WITH_APPLICATION** passed in to [bundleFlags](js-apis-bundleManager.md#bundleflag).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## ApplicationInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                      | Type                                                        | Read-Only| Optional| Description                                                        |
| -------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                       | string                                                       | Yes  | No  | Application name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                |
| description                | string                                                       | Yes  | No  | Description of the application. It corresponds to the **description** field in the [app.json5](../../quick-start/app-configuration-file.md). For details about **description**, see the **descriptionResource** field in this table.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| descriptionId              | number                                                       | Yes  | No  | Resource ID of the application description. It is automatically generated during compilation and build based on the description configured for the application.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| enabled                    | boolean                                                      | Yes  | No  | Whether the application is enabled. **true** if enabled, **false** otherwise.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| label                      | string                                                       | Yes  | No  | Application label. It corresponds to the **label** field in the [app.json5](../../quick-start/app-configuration-file.md) file. For details about **label**, see the **labelResource** field in this table. Starting from API version 20, if [bundleManager.getAbilityInfo](js-apis-bundleManager.md#bundlemanagergetabilityinfo20) is used to obtain application information, this field is the application name visible to users, instead of the resource descriptor.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| labelId                    | number                                                       | Yes  | No  | Resource ID of the application label. It is automatically generated during compilation and build based on the label configured for the application.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| icon                       | string                                                       | Yes  | No  | Application icon. It corresponds to the **icon** field in the [app.json5](../../quick-start/app-configuration-file.md) file. For details about **icon**, see the **iconResource** field in this table.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| iconId                     | number                                                       | Yes  | No  | Resource ID of the application icon. It is automatically generated during compilation and build based on the icon configured for the application.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| process                    | string                                                       | Yes  | No  | Process name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| permissions                | Array\<string>                                               | Yes  | No  | Permissions required for accessing the application. The permissions can be obtained by passing in **GET_BUNDLE_INFO_WITH_APPLICATION** and **GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| codePath                   | string                                                       | Yes  | No  | Installation directory of the application.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| metadata<sup>(deprecated)<sup>  | Map\<string, Array\<[Metadata](js-apis-bundleManager-metadata.md)>> | Yes  | No  | Metadata of the application. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_APPLICATION** and **GET_BUNDLE_INFO_WITH_METADATA** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).<br>Note: The **metadata** field is deprecated since API version 10. You are advised to use **metadataArray** instead.|
| metadataArray<sup>10+</sup>              | Array\<[ModuleMetadata](#modulemetadata10)> | Yes  | No  | Metadata of the application. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_APPLICATION** and **GET_BUNDLE_INFO_WITH_METADATA** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| removable                  | boolean                                                      | Yes  | No  | Whether the application is removable. **true** if removable, **false** otherwise.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| accessTokenId             | number                                                       | Yes  | No  | Access token ID of the application, which is used in the [application access control verification API](js-apis-abilityAccessCtrl.md#checkaccesstoken9).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| uid                       | number                                                       | Yes  | No  | UID of the application.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| iconResource              | [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) | Yes| No| Resource information of the application icon. The resource information obtained contains the bundle name, module name, and ID of the resource. You can call [getMediaContent](../apis-localization-kit/js-apis-resource-manager.md#getmediacontent9) to obtain the resource details.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| labelResource             | [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) | Yes| No| Resource information of the application label. The resource information obtained contains the bundle name, module name, and ID of the resource. You can call [getMediaContent](../apis-localization-kit/js-apis-resource-manager.md#getmediacontent9) to obtain the resource details.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| descriptionResource       | [Resource](../apis-localization-kit/js-apis-resource-manager.md#resource9) | Yes| No| Resource information of the application description. The resource information obtained contains the bundle name, module name, and ID of the resource. You can call [getMediaContent](../apis-localization-kit/js-apis-resource-manager.md#getmediacontent9) to obtain the resource details.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| appDistributionType       | string                                                       | Yes  | No  | Distribution type of the application signing certificate. The options are as follows:<li>**app_gallery**: application installed from AppGallery. <li>**enterprise**: enterprise application that can be installed on personal devices. <li>**enterprise_mdm**: enterprise Mobile Device Management (MDM) application, which can be installed only on enterprise devices. <!--Del-->To install a common enterprise application, you must have [administrator privileges](../apis-mdm-kit/js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin). <!--DelEnd--> <li>**enterprise_normal**: common enterprise application, which can be installed on enterprise devices only through an enterprise MDM application. <li>**os_integration**: preset application in the system. <li>crowdtesting: application under crowdtesting, which is distributed by AppGallery to a limited number of users and come with a set expiration date. When the system detects that the validity period of the application expires, it prompts the user to update to the release version available on AppGallery. <li>**internaltesting**: application under internal testing of AppGallery. <li>**none**: other applications.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| appProvisionType          | string                                                       | Yes  | No  | Type of the application signing certificate file. The options are **debug** and **release**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| systemApp          | boolean                                                       | Yes  | No  | Whether the application is a system application. **true** if it is a system application, **false** otherwise.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| bundleType                |[bundleManager.BundleType](js-apis-bundleManager.md#bundletype)             | Yes  | No  | Bundle type, which can be **APP** (application) or **ATOMIC_SERVICE** (atomic service).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| debug<sup>10+</sup>       | boolean                                | Yes  | No  | Whether the application is running in debug mode. **true** if in debug mode, **false** otherwise.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| dataUnclearable<sup>11+</sup>       | boolean                      | Yes  | No  | Whether the application data is unclearable. **true** if unclearable, **false** otherwise.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| nativeLibraryPath<sup>12+</sup> | string                                                                     | Yes  | No  | Local library file path of the application.                                                 |
| multiAppMode<sup>12+</sup> | [MultiAppMode](#multiappmode12) | Yes  | No  | Multi-app mode.|
| appIndex<sup>12+</sup>    | number    | Yes  | No  | Index of an application clone. It takes effect only for cloned applications.|
| installSource<sup>12+</sup>    | string    | Yes  | No  | Installation source of the application. The options are as follows:<br> - **pre-installed**: The application is a preset application installed at initial device startup.<br> - **ota**: The application is a preset application added during system upgrade.<br> - **recovery**: The preset application is uninstalled and then restored.<br> - **bundleName**: The application corresponding to the bundle name is installed.<br> - **unknown**: The installation source is unknown.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| releaseType<sup>12+</sup>    | string    | Yes  | No  | Release type of the SDK used for application packing. Currently, the SDK release types include Canary, Beta, and Release. Each of the Canary and Beta releases can be distinguished by a sequential number, such as Canary1, Canary2, Beta1, and Beta2. You can compare the SDK release type on which application packaging depends and the OS release type (specified by [deviceInfo.distributionOSReleaseType](../apis-basic-services-kit/js-apis-device-info.md)) to determine the compatibility.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| cloudFileSyncEnabled<sup>12+</sup>    | boolean    | Yes  | No  | Whether device-cloud file synchronization is enabled for the application. **true** if enabled, **false** otherwise.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| cloudStructuredDataSyncEnabled<sup>20+</sup>    | boolean    | Yes  | Yes  | Whether device-cloud structured data synchronization is enabled for the application. **true** if enabled, **false** otherwise.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

## MultiAppMode<sup>12+</sup>
Defines the [multi-app mode](../../quick-start/multiInstance.md).

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type          | Read-Only| Optional| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| multiAppModeType | [bundleManager.MultiAppModeType](js-apis-bundleManager.md#multiappmodetype12) | Yes| No|  Type of the multi-app mode. |
| maxCount | number  | Yes| No|  Maximum number of accounts that can log in to the application at the same time. |

## ModuleMetadata<sup>10+</sup>

Describes the metadata of a module.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name     | Type          | Read-Only| Optional| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| moduleName| string         | Yes  | No  | Module name.  |
| metadata  | Array\<[Metadata](js-apis-bundleManager-metadata.md)>      | Yes  | No  | Metadata list of the module.|
