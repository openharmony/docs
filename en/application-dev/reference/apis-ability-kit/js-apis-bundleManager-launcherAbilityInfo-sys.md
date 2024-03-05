# LauncherAbilityInfo (System API)

The **LauncherAbilityInfo** module defines the ability information of the home screen application. The information can be obtained through [bundleManager.getLauncherAbilityInfo](js-apis-launcherBundleManager-sys.md#launcherbundlemanagergetlauncherabilityinfo9).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The APIs provided by this module are system APIs.

## LauncherAbilityInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**System API**: This is a system API.

| Name           | Type                                                       | Readable| Writable| Description                                |
| --------------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------ |
| applicationInfo | [ApplicationInfo](js-apis-bundleManager-applicationInfo.md) | Yes  | No  | Application information of the launcher ability.|
| elementName     | [ElementName](js-apis-bundleManager-elementName.md)         | Yes  | No  | Element name of the launcher ability.   |
| labelId         | number                                                      | Yes  | No  | ID of the launcher ability label.            |
| iconId          | number                                                      | Yes  | No  | ID of the launcher ability icon.            |
| userId          | number                                                      | Yes  | No  | ID of the launcher ability user.            |
| installTime     | number                                                      | Yes  | No  | Time when the launcher ability was installed.          |
