# LauncherAbilityInfo (System API)

The LauncherAbilityInfo module provides information about the launcher ability, which is obtained through [innerBundleManager.getLauncherAbilityInfos](js-apis-Bundle-InnerBundleManager-sys.md#innerbundlemanagergetlauncherabilityinfosdeprecated).

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The APIs of this module are deprecated since API version 9. You are advised to use [bundleManager-LauncherAbilityInfo](js-apis-launcherBundleManager.md) instead.
>
> The APIs provided by this module are system APIs.

## LauncherAbilityInfo<sup>(deprecated)<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager-LauncherAbilityInfo](js-apis-launcherBundleManager.md) instead.

**System capability**: SystemCapability.BundleManager.BundleFramework

**System API**: This is a system API.

| Name           | Type                                                | Read-Only| Optional| Description                                  |
| --------------- | ---------------------------------------------------- | ---- | ---- | -------------------------------------- |
| applicationInfo | [ApplicationInfo](js-apis-bundle-ApplicationInfo.md) | Yes  | No  | Application information of the launcher ability.|
| elementName     | [ElementName](js-apis-bundle-ElementName.md)         | Yes  | No  | Element name of the launcher ability.   |
| labelId         | number                                               | Yes  | No  | ID of the launcher ability label.            |
| iconId          | number                                               | Yes  | No  | ID of the launcher ability icon.            |
| userId          | number                                               | Yes  | No  | ID of the launcher ability user.            |
| installTime     | number                                               | Yes  | No  | Time when the launcher ability is installed.          |
