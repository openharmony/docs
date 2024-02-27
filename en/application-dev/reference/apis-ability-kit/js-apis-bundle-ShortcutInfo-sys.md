# shortcutInfo (System API)

The **shortcutInfo** module defines shortcut information configured in the configuration file. For the FA model, the shortcut information is configured in the [config.json](../../quick-start/application-configuration-file-overview-fa.md) file. For the stage model, the information is configured in the configuration file under **resources/base/profile** in the development view.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## ShortcutWant<sup>(deprecated)<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager-ShortcutWant](js-apis-bundleManager-shortcutInfo-sys.md) instead.

**System capability**: SystemCapability.BundleManager.BundleFramework

**System API**: This is a system API and cannot be called by third-party applications.

| Name                     | Type  | Readable| Writable| Description                |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| targetBundle              | string | Yes  | No  | Target bundle of the shortcut.|
| targetClass               | string | Yes  | No  | Target class required by the shortcut.|

## ShortcutInfo<sup>(deprecated)<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager-ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md) instead.


**System capability**: SystemCapability.BundleManager.BundleFramework

| Name                   | Type                                      | Readable| Writable| Description                        |
| ----------------------- | ------------------------------------------ | ---- | ---- | ---------------------------- |
| id                      | string                                     | Yes  | No  | ID of the application to which the shortcut belongs.    |
| bundleName              | string                                     | Yes  | No  | Name of the bundle that contains the shortcut.|
| hostAbility             | string                                     | Yes  | No  | Local ability information of the shortcut.   |
| icon                    | string                                     | Yes  | No  | Icon of the shortcut.              |
| iconId<sup>8+</sup>     | number                                     | Yes  | No  | Icon ID of the shortcut.            |
| label                   | string                                     | Yes  | No  | Name of the shortcut.              |
| labelId<sup>8+</sup>    | number                                     | Yes  | No  | Name ID of the shortcut.            |
| disableMessage          | string                                     | Yes  | No  | Message displayed when the shortcut is disabled.          |
| wants                   | Array&lt;[ShortcutWant](#shortcutwantdeprecated)&gt; | Yes  | No  | Want list for the shortcut.        |
| isStatic                | boolean                                    | Yes  | No  | Whether the shortcut is static.          |
| isHomeShortcut          | boolean                                    | Yes  | No  | Whether the shortcut is a home shortcut.|
| isEnabled               | boolean                                    | Yes  | No  | Whether the shortcut is enabled.            |
