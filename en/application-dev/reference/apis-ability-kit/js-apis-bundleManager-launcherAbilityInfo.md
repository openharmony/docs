# LauncherAbilityInfo
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module describes the ability information of the launcher application. The information can be obtained by calling [getLauncherAbilityInfoSync](js-apis-launcherBundleManager.md#launcherbundlemanagergetlauncherabilityinfosync)<!--Del--> or [getLauncherAbilityInfo](js-apis-launcherBundleManager-sys.md#launcherbundlemanagergetlauncherabilityinfo9)<!--DelEnd-->.

> **NOTE**
>
> The initial APIs of this module are supported since API version 18. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { launcherBundleManager } from '@kit.AbilityKit';
```

## LauncherAbilityInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

| Name           | Type                                                       | Read Only| Optional| Description                                |
| --------------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------ |
| applicationInfo | [ApplicationInfo](js-apis-bundleManager-applicationInfo.md) | Yes  | No  | Application information of the launcher ability.|
| elementName     | [ElementName](js-apis-bundleManager-elementName.md)         | Yes  | No  | Element name of the launcher ability.   |
| labelId         | number                                                      | Yes  | No  | ID of the launcher ability label.     |
| iconId          | number                                                      | Yes  | No  | ID of the launcher ability icon.     |
| userId          | number                                                      | Yes  | No  | User ID of the launcher ability.            |
| installTime     | number                                                      | Yes  | No  | Timestamp when the launcher ability was installed, in milliseconds.|
