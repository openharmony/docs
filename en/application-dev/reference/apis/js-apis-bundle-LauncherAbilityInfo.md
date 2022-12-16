# LauncherAbilityInfo

The **LauncherAbilityInfo** module provides information about the launcher ability, which is obtained through [innerBundleManager.getLauncherAbilityInfos](js-apis-Bundle-InnerBundleManager.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## LauncherAbilityInfo<sup>(deprecated)<sup>

> This API is deprecated since API version 9. You are advised to use [LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md) instead.

**System capability**: SystemCapability.BundleManager.BundleFramework

**System API**: This is a system API and cannot be called by third-party applications.

| Name           | Type                                                | Readable| Writable| Description                                  |
| --------------- | ---------------------------------------------------- | ---- | ---- | -------------------------------------- |
| applicationInfo | [ApplicationInfo](js-apis-bundle-ApplicationInfo.md) | Yes  | No  | Application information of the launcher ability.|
| elementName     | [ElementName](js-apis-bundle-ElementName.md)         | Yes  | No  | Element name of the launcher ability.   |
| labelId         | number                                               | Yes  | No  | Label ID of the launcher ability.            |
| iconId          | number                                               | Yes  | No  | Icon ID of the launcher ability.            |
| userId          | number                                               | Yes  | No  | User ID of the launcher ability.            |
| installTime     | number                                               | Yes  | No  | Time when the launcher ability is installed.          |
