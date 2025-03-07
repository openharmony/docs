# ExtensionAbilityInfo

The ExtensionAbilityInfo module defines the ExtensionAbility information. A third-party application can obtain its own ExtensionAbility information through [bundleManager.getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself), with **GET_BUNDLE_INFO_WITH_HAP_MODULE** and **GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY** passed in to [bundleFlags](js-apis-bundleManager.md#bundleflag).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ExtensionAbilityInfo

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                | Type                                                        | Read-Only| Optional| Description                                                |
| -------------------- | ------------------------------------------------------------ | ---- | ---- | ---------------------------------------------------- |
| bundleName           | string                                                       | Yes  | No  | Bundle name.                                    |
| moduleName           | string                                                       | Yes  | No  | Name of the HAP file to which the ExtensionAbility belongs.                   |
| name                 | string                                                       | Yes  | No  | Name of the ExtensionAbility.                              |
| labelId              | number                                                       | Yes  | No  | ID of the ExtensionAbility label.                      |
| descriptionId        | number                                                       | Yes  | No  | ID of the ExtensionAbility description.                      |
| iconId               | number                                                       | Yes  | No  | ID of the ExtensionAbility icon.                      |
| exported            | boolean                                                      | Yes  | No  | Whether the ExtensionAbility can be called by other applications. The value **true** means that the ExtensionAbility can be called by other applications, and **false** means the opposite.        |
| extensionAbilityType | [ExtensionAbilityType](js-apis-bundleManager.md#extensionabilitytype) | Yes  | No  | Type of the ExtensionAbility.                              |
| permissions          | Array\<string>                                               | Yes  | No  | Permissions required for other bundles to call the ExtensionAbility.|
| applicationInfo      | [ApplicationInfo](js-apis-bundleManager-applicationInfo.md)  | Yes  | No  | Application information. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_HAP_MODULE**, **GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY**, and **GET_BUNDLE_INFO_WITH_APPLICATION** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).|
| metadata             | Array\<[Metadata](js-apis-bundleManager-metadata.md)>        | Yes  | No  | Metadata of the ExtensionAbility. The information can be obtained by passing in **GET_BUNDLE_INFO_WITH_HAP_MODULE**, **GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY**, and **GET_BUNDLE_INFO_WITH_METADATA** to the **bundleFlags** parameter of [getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself).|
| enabled              | boolean                                                      | Yes  | No  | Whether the ExtensionAbility is enabled. The value **true** means that the ExtensionAbility is enabled, and **false** means the opposite.                          |
| readPermission       | string                                                       | Yes  | No  | Permission required for reading data from the ExtensionAbility.                |
| writePermission      | string                                                       | Yes  | No  | Permission required for writing data to the ExtensionAbility.                |
| extensionAbilityTypeName<sup>11+</sup>      | string                                 | Yes  | No  | Type of the ExtensionAbility.                |
| skills<sup>12+</sup>             | Array\<[Skill](js-apis-bundleManager-skill.md)>                                                 | Yes  | No  | Skills of the ExtensionAbility.       |
| appIndex<sup>12+</sup>    | number    | Yes  | No  | Index of an application clone. It takes effect only for cloned applications.|
