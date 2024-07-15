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
| targetBundle              | string | Yes  | No  | Target bundle name of the shortcut.|
| targetModule              | string | Yes  | No  | Target module name of the shortcut. |
| targetAbility             | string | Yes  | No  | Target ability name of the shortcut.|
| parameters<sup>12+</sup>  | Array\<[ParameterItem](#parameteritem12)> | Yes  | No  | Custom data in the shortcut configuration.|

## ShortcutInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**System API**: This is a system API.

| Name                   | Type                                      | Readable| Writable| Description                        |
| ----------------------- | ------------------------------------------ | ---- | ---- | ---------------------------- |
| id                      | string                                     | Yes  | No  | ID of the application to which the shortcut belongs. |
| bundleName              | string                                     | Yes  | No  | Name of the bundle that contains the shortcut.|
| moduleName | string                                     | Yes  | No  | Module name of the shortcut.           |
| hostAbility             | string                                     | Yes  | No  | Local ability name of the shortcut.  |
| icon                    | string                                     | Yes  | No  | Icon of the shortcut.            |
| iconId     | number                                     | Yes  | No  | ID of the shortcut icon.          |
| label                   | string                                     | Yes  | No  | Label of the shortcut.             |
| labelId    | number                                     | Yes  | No  | ID of the shortcut label.          |
| wants                   | Array\<[ShortcutWant](#shortcutwant)> | Yes  | No  | Want information required for the shortcut.       |

## ParameterItem<sup>12+</sup>

Describes the custom data in the shortcut configuration.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

| Name         | Type   | Read Only| Mandatory| Description                  |
| ------------- | ------ | ---- | ---- | ---------------------- |
| key           | string | Yes  | Yes  | Key of the custom data.      |
| value         | string | Yes  | Yes  | Value of the custom data.|

<!--no_check-->
