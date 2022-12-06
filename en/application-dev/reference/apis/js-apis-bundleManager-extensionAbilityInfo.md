# ExtensionAbilityInfo

The **ExtensionAbilityInfo** module provides information about an Extension ability. Unless otherwise specified, all attributes are obtained through [getBundleInfo](js-apis-bundleManager.md), and flags are obtained through [GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY](js-apis-bundleManager.md#bundleflag).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ExtensionAbilityInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                | Type                                                       | Readable| Writable| Description                                              |
| -------------------- | ----------------------------------------------------------- | ---- | ---- | -------------------------------------------------- |
| bundleName           | string                                                      | Yes  | No  | Bundle name.                                          |
| moduleName           | string                                                      | Yes  | No  | Name of the HAP file to which the Extension ability belongs.                 |
| name                 | string                                                      | Yes  | No  | Name of the Extension ability.                              |
| labelId              | number                                                      | Yes  | No  | Label ID of the Extension ability.                      |
| descriptionId        | number                                                      | Yes  | No  | Description ID of the Extension ability.                      |
| iconId               | number                                                      | Yes  | No  | Icon ID of the Extension ability.                      |
| isVisible            | boolean                                                     | Yes  | No  | Whether the Extension ability can be called by other bundles.        |
| extensionAbilityType | [ExtensionAbilityType](js-apis-bundleManager.md#extensionabilitytype)  | Yes  | No  | Type of the Extension ability.                              |
| permissions          | Array\<string>                                              | Yes  | No  | Permissions required for other bundles to call the Extension ability.|
| applicationInfo      | [ApplicationInfo](js-apis-bundleManager-applicationInfo.md) | Yes  | No  | Application information of the Extension ability.                                |
| metadata             | Array\<[Metadata](js-apis-bundleManager-metadata.md)>       | Yes  | No  | Metadata of the Extension ability.                          |
| enabled              | boolean                                                     | Yes  | No  | Whether the Extension ability is enabled.                          |
| readPermission       | string                                                      | Yes  | No  | Permission required for reading data from the Extension ability.                |
| writePermission      | string                                                      | Yes  | No  | Permission required for writing data to the Extension ability.                |
