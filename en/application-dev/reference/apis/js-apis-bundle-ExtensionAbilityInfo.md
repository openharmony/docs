# ExtensionAbilityInfo

The **ExtensionAbilityInfo** module provides Extension ability information. Unless otherwise specified, all attributes are obtained through [getBundleInfo](js-apis-Bundle.md#bundlegetbundleinfo), and flags are obtained through [GET_BUNDLE_DEFAULT](js-apis-Bundle.md#bundleflag).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ExtensionAbilityInfo

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name                | Type                                                | Readable| Writable| Description                                              |
| -------------------- | ---------------------------------------------------- | ---- | ---- | -------------------------------------------------- |
| bundleName           | string                                               | Yes  | No  | Bundle name of the application.                                          |
| moduleName           | string                                               | Yes  | No  | Name of the HAP file to which the Extension ability belongs.                 |
| name                 | string                                               | Yes  | No  | Name of the Extension ability.                              |
| labelId              | number                                               | Yes  | No  | Label ID of the Extension ability.                          |
| descriptionId        | number                                               | Yes  | No  | Description ID of the Extension ability.                          |
| iconId               | number                                               | Yes  | No  | Icon ID of the Extension ability.                          |
| isVisible            | boolean                                              | Yes  | No  | Whether the Extension ability can be called by other applications.        |
| extensionAbilityType | bundle.ExtensionAbilityType                          | Yes  | No  | Type of the Extension ability.                              |
| permissions          | Array\<string>                                       | Yes  | No  | Permissions required for other applications to call the Extension ability.|
| applicationInfo      | [ApplicationInfo](js-apis-bundle-ApplicationInfo.md) | Yes  | No  | Application information of the Extension ability.                                |
| metadata             | Array\<[Metadata](js-apis-bundle-Metadata.md)>       | Yes  | No  | Metadata of the Extension ability.                          |
| enabled              | boolean                                              | Yes  | No  | Whether the Extension ability is enabled.                          |
| readPermission       | string                                               | Yes  | No  | Permission required for reading data from the Extension ability.                |
| writePermission      | string                                               | Yes  | No  | Permission required for writing data to the Extension ability.                |
