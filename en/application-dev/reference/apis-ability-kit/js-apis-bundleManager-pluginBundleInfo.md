# PluginBundleInfo

<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @menghaiyang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=f6aebb5feee7366b8f8186d7dd8d5c650b89a049 translatedAt=2026-08-13T13:20:07.714Z pushedAt=2026-08-17T03:36:02.366Z -->

Provides the plugin information, which is obtained by calling [pluginBundleManager.getAllLocalPluginInfoForSelf](js-apis-pluginBundleManager.md#pluginbundlemanagergetalllocalplugininfoforself) to obtain all plugin information installed by the current app through self-distribution. The information includes the plugin name, icon, version number, and module information, and is used to manage installed plugins and perform compatibility checks and updates based on the version number and module information.
**Since:** 26.0.0

## Modules to Import

```ts
import { pluginBundleManager } from '@kit.AbilityKit';
```

## PluginBundleInfo

Plugin information. It is used to manage installed plugins and perform compatibility checks and updates based on their version numbers and module information.

**Since**: 26.0.0

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name           | Type   | Read-Only | Optional | Description           |
| -------------- | ------ | ---- | ---- | -------------- |
| label   | string | Yes   | No   | Name of the plugin. It corresponds to the **label** field configured in [app.json5](../../quick-start/app-configuration-file.md#tags-in-the-configuration-file).   |
| labelId   | number | Yes   | No   | Resource ID of the plugin name. It is the resource ID automatically generated during compile and build based on the **label** configured in the plugin configuration.   |
| icon   | string | Yes   | No   | Icon of the plugin. It corresponds to the **icon** field configured in [app.json5](../../quick-start/app-configuration-file.md#tags-in-the-configuration-file).   |
| iconId   | number | Yes   | No   | Resource ID of the plugin icon. It is the resource ID automatically generated during compile and build based on the **icon** configured in the plugin configuration.   |
| pluginBundleName   | string | Yes   | No   | Bundle name of the app that installs the plugin. It corresponds to the **bundleName** field configured in [app.json5](../../quick-start/app-configuration-file.md#tags-in-the-configuration-file).   |
| versionCode   | number | Yes   | No   | Version code of the plugin. It corresponds to the **versionCode** field configured in [app.json5](../../quick-start/app-configuration-file.md#tags-in-the-configuration-file).   |
| versionName   | string | Yes   | No   | Version name of the plugin. It corresponds to the **versionName** field configured in [app.json5](../../quick-start/app-configuration-file.md#tags-in-the-configuration-file).   |
| pluginModuleInfos   | Array<[PluginModuleInfo](#pluginmoduleinfo)> | Yes   | No   | Module information of the plugin.   |

## PluginModuleInfo

Provides the module information of a plugin, which describes the name and function description of the plugin module.

**Since**: 26.0.0

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name           | Type   | Read-Only | Optional | Description           |
| -------------- | ------ | ---- | ---- | -------------- |
| moduleName   | string | Yes   | No   |  Name of the plugin module. It corresponds to the **name** field configured in the [module.json5 Configuration File](../../quick-start/module-configuration-file.md#tags-in-the-configuration-file).  |
| descriptionId   | number | Yes   | No   |  Resource ID of the plugin module description. It is the resource ID automatically generated based on the **description** configured for the plugin during compile and build.  |
| description   | string | Yes   | No   |  Description of the plugin module. It corresponds to the **description** field configured in the [module.json5 Configuration File](../../quick-start/module-configuration-file.md#tags-in-the-configuration-file).  |