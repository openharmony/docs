# PluginBundleInfo (System API)

The PluginBundleInfo module defines plugin information, which is obtained through the [bundleManager.getAllPluginInfo](js-apis-bundleManager-sys.md#bundlemanagergetallplugininfo19) API.

> **NOTE**
>
> The initial APIs of this module are supported since API version 19. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## PluginBundleInfo

Defines the plugin information.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core
 
**System API**: This is a system API.

| Name          | Type  | Read-Only| Optional| Description          |
| -------------- | ------ | ---- | ---- | -------------- |
| label   | string | Yes  | Yes  | Plugin name.  |
| labelId   | number | Yes  | Yes  | Resource ID of the plugin name.  |
| icon   | string | Yes  | Yes  | Plugin icon.  |
| iconId   | number | Yes  | Yes  | Resource ID of the plugin icon.  |
| pluginBundleName   | string | Yes  | Yes  | Bundle name of the application for which the plugin is installed.  |
| versionCode   | string | Yes  | Yes  | Version number of the plugin.  |
| versionName   | string | Yes  | Yes  | Version name of the plugin.  |
| pluginModuleInfos   | Array<[PluginModuleInfo](js-apis-bundleManager-pluginBundleInfo-sys.md#pluginmoduleinfo)> | Yes  | Yes  | Module information of the plugin.  |

## PluginModuleInfo

Defines the module information of a plugin.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name          | Type  | Read-Only| Optional| Description          |
| -------------- | ------ | ---- | ---- | -------------- |
| moduleName   | string | Yes  | Yes  |  Module name of the plugin. |
| descriptionId   | number | Yes  | Yes  |  Resource ID of the module description. |
| description   | string | Yes  | Yes  |  Description of the module. |
