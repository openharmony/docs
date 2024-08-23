# ShortcutInfo (System API)

The **ShortcutInfo** module defines shortcut information configured in the configuration file. The information can be obtained through [getShortcutInfo](js-apis-launcherBundleManager-sys.md#launcherbundlemanagergetshortcutinfo9).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> For the FA model, the shortcut information is configured in the [config.json](../../quick-start/module-structure.md) file. For details about the shortcut information in the stage model, see [shortcuts](../../quick-start/module-configuration-file.md#shortcuts).
>
> The APIs provided by this module are system APIs.

## ShortcutWant

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**System API**: This is a system API.

| Name                     | Type  | Readable| Writable| Description                |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| targetBundle              | string | Yes  | Yes  | Target bundle name of the shortcut.|
| targetModule              | string | Yes  | Yes | Target module name of the shortcut. |
| targetAbility             | string | Yes  | Yes | Target ability name of the shortcut.|
| parameters<sup>12+</sup>  | Array\<[ParameterItem](#parameteritem12)> | Yes  | Yes | Custom data in the shortcut configuration.|

## ShortcutInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

 **System API**: This is a system API.

| Name                   | Type                                      | Readable| Writable| Description                        |
| ----------------------- | ------------------------------------------ | ---- | ---- | ---------------------------- |
| id                      | string                                     | Yes  | Yes| ID of the application to which the shortcut belongs. |
| bundleName              | string                                     | Yes  | Yes | Name of the bundle that contains the shortcut.|
| moduleName | string                                     | Yes  | Yes | Module name of the shortcut.           |
| hostAbility             | string                                     | Yes  | Yes | Local ability name of the shortcut.  |
| icon                    | string                                     | Yes  | Yes | Icon of the shortcut.            |
| iconId     | number                                     | Yes  | Yes | ID of the shortcut icon.          |
| label                   | string                                     | Yes  | Yes | Label of the shortcut.             |
| labelId    | number                                     | Yes  | Yes | ID of the shortcut label.          |
| wants                   | Array\<[ShortcutWant](#shortcutwant)> | Yes  | Yes | Want information required for the shortcut.       |
| appIndex<sup>12+</sup> | number | Yes| Yes| Index of an application clone.|
| sourceType<sup>12+</sup> | number | Yes| Yes| Shortcut source type. The value **0** means a custom shortcut, and **1** means a static shortcut.|

## ParameterItem<sup>12+</sup>

Describes the custom data in the shortcut configuration.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

| Name         | Type   | Readable| Writable| Description                  |
| ------------- | ------ | ---- | ---------------------- | ---------------------- |
| key           | string | Yes  | Yes  | Key of the custom data.      |
| value         | string | Yes  | Yes  | Value of the custom data.|

<!--no_check-->
