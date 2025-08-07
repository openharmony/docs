# ShortcutInfo

The module defines shortcut information configured in the configuration file. For the FA model, the shortcut information is configured in the [config.json](../../quick-start/application-configuration-file-overview-fa.md) file. For the stage model, the information is configured in the configuration file under **resources/base/profile** in the development view.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This module is deprecated since API version 9. You are advised to use [bundleManager-ShortcutInfo](js-apis-bundleManager-shortcutInfo.md) instead.

## ShortcutInfo<sup>(deprecated)<sup>
This API is deprecated since API version 9. You are advised to use [bundleManager-ShortcutInfo](js-apis-bundleManager-shortcutInfo.md#shortcutinfo) instead.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name                   | Type                                      | Read-Only| Optional| Description                        |
| ----------------------- | ------------------------------------------ | ---- | ---- | ---------------------------- |
| id                      | string                                     | Yes  | No  | ID of the application to which the shortcut belongs.    |
| bundleName              | string                                     | Yes  | No  | Name of the bundle that contains the shortcut.|
| hostAbility             | string                                     | Yes  | No  | Local ability information of the shortcut.   |
| icon                    | string                                     | Yes  | No  | Icon of the shortcut.              |
| iconId<sup>8+</sup>     | number                                     | Yes  | No  | Icon ID of the shortcut.            |
| label                   | string                                     | Yes  | No  | Name of the shortcut.              |
| labelId<sup>8+</sup>    | number                                     | Yes  | No  | Name ID of the shortcut.            |
| disableMessage          | string                                     | Yes  | No  | Message displayed when the shortcut is disabled.          |
| wants                   | Array&lt;<!--Del-->[<!--DelEnd-->ShortcutWant<!--Del-->](js-apis-bundle-ShortcutInfo-sys.md#shortcutwantdeprecated)<!--DelEnd-->&gt; | Yes  | No  | Want list for the shortcut.        |
| isStatic                | boolean                                    | Yes  | No  | Whether the shortcut is static. The value **true** means that the shortcut is static, and **false** means the opposite.         |
| isHomeShortcut          | boolean                                    | Yes  | No  | Whether the shortcut is a home shortcut. The value **true** means that the shortcut is a home shortcut, and **false** means the opposite.|
| isEnabled               | boolean                                    | Yes  | No  | Whether the shortcut is enabled. The value **true** means that the shortcut is enabled, and **false** means the opposite.            |
