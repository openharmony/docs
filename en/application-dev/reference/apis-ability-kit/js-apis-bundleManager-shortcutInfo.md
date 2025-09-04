# ShortcutInfo
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module describes the shortcut information defined in the [module.json5](../../quick-start/module-configuration-file.md#shortcuts) file of an application. The information can be obtained by running [getAllShortcutInfoForSelf](js-apis-shortcutManager.md#shortcutmanagergetallshortcutinfoforself)<!--Del--> or [getShortcutInfo](js-apis-launcherBundleManager-sys.md#launcherbundlemanagergetshortcutinfo9)<!--DelEnd-->.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { shortcutManager } from '@kit.AbilityKit';
```

## ShortcutWant

Describes a collection of target [Wants](../../quick-start/module-configuration-file.md#wants) information defined within a shortcut.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

| Name              | Type                                   | Read-Only| Optional| Description                |
| ------------------| --------------------------------------- | --- | --- | -------------------- |
| targetBundle      | string                                  | No  | No | Target bundle name of the shortcut.|
| targetModule      | string                                  | No  | Yes | Target module name of the shortcut.|
| targetAbility     | string                                  | No  | No | Target ability name of the shortcut.|
| parameters        | Array\<[ParameterItem](#parameteritem)> | No  | Yes | Custom data for launching the shortcut. The data must be strings. Both keys and values can be strings up to 1024 characters long.|

## ShortcutInfo

Describes the configuration information for a shortcut.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

| Name               | Type                                      | Read-Only| Optional| Description                        |
| ------------------- | ----------------------------------------- | --- | --- | ---------------------------- |
| id                  | string                                    | No | No | ID of the shortcut.|
| bundleName          | string                                    | No | No | Bundle name of the application to which the shortcut belongs.|
| moduleName          | string                                    | No | Yes | Module name of the shortcut.|
| hostAbility         | string                                    | No | Yes | Name of the ability that hosts the shortcut.|
| icon                | string                                    | No | Yes | Icon of the shortcut. The value is the index of a resource file.|
| iconId              | number                                    | No | Yes | Resource ID of the shortcut icon.|
| label               | string                                    | No | Yes | Label of the shortcut. The value can be descriptive text or a resource index.|
| labelId             | number                                    | No | Yes | Resource ID of the shortcut label.|
| wants               | Array\<[ShortcutWant](#shortcutwant)>     | No | Yes | A collection of target Wants information defined within the shortcut.|
| appIndex            | number                                    | No | No | Index of the application clone to which the shortcut belongs.|
| sourceType          | number                                    | No | No | Source type of the shortcut. The value **0** means a custom shortcut, and **1** means a static shortcut.|
| visible             | boolean                                   | No | Yes | Whether the shortcut is visible. **true** if visible, **false** otherwise. The default value is **true**.|

## ParameterItem

Describes the custom data in the shortcut configuration. You can define your own key-value pairs, and obtain the values using the keys.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

| Name         | Type   | Read-Only| Optional| Description                           |
| ------------- | ------ | ---- | ---- | ----------------------------- |
| key           | string | No  | No  | Key of the custom data.|
| value         | string | No  | No  | Value of the custom data.|
