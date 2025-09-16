# PluginBundleInfo (System API)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module defines plugin information, which is obtained through the [bundleManager.getAllPluginInfo](js-apis-bundleManager-sys.md#bundlemanagergetallplugininfo19) API.

> **NOTE**
>
> The initial APIs of this module are supported since API version 19. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## PluginBundleInfo
Defines the plugin information.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core
 
**System API**: This is a system API.

| Name          | Type  | Read-Only| Optional| Description          |
| -------------- | ------ | ---- | ---- | -------------- |
| label   | string | Yes  | No  | Plugin name.  |
| labelId   | number | Yes  | No  | Resource ID of the plugin name.  |
| icon   | string | Yes  | No  | Plugin icon.  |
| iconId   | number | Yes  | No  | Resource ID of the plugin icon.  |
| pluginBundleName   | string | Yes  | No  | Bundle name of the application for which the plugin is installed.  |
| versionCode   | string | Yes  | No  | Version number of the plugin.  |
| versionName   | string | Yes  | No  | Version name of the plugin.  |
| pluginModuleInfos   | Array<[PluginModuleInfo](js-apis-bundleManager-pluginBundleInfo-sys.md#pluginmoduleinfo)> | Yes  | No  | Module information of the plugin.  |

## PluginModuleInfo
Defines the module information of a plugin.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name          | Type  | Read-Only| Optional| Description          |
| -------------- | ------ | ---- | ---- | -------------- |
| moduleName   | string | Yes  | No  |  Module name of the plugin. |
| descriptionId   | number | Yes  | No  |  Resource ID of the module description. |
| description   | string | Yes  | No  |  Description of the module. |
