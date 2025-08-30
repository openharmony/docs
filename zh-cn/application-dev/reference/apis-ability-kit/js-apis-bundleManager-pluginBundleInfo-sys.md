# PluginBundleInfo (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

插件信息，通过接口[bundleManager.getAllPluginInfo](js-apis-bundleManager-sys.md#bundlemanagergetallplugininfo19)获取。

> **说明：**
>
> 本模块首批接口从API version 19 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## 导入模块

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## PluginBundleInfo
插件信息。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core
 
**系统接口：** 此接口为系统接口。

| 名称           | 类型   | 只读 | 可选 | 说明           |
| -------------- | ------ | ---- | ---- | -------------- |
| label   | string | 是   | 否   | 插件的名称。   |
| labelId   | number | 是   | 否   | 插件名称的资源id值。   |
| icon   | string | 是   | 否   | 插件的图标。   |
| iconId   | number | 是   | 否   | 插件图标的资源id值。   |
| pluginBundleName   | string | 是   | 否   | 安装插件的应用包名。   |
| versionCode   | number | 是   | 否   | 插件的版本号。   |
| versionName   | string | 是   | 否   | 插件的版本名称。   |
| pluginModuleInfos   | Array<[PluginModuleInfo](js-apis-bundleManager-pluginBundleInfo-sys.md#pluginmoduleinfo)> | 是   | 否   | 插件的模块信息。   |

## PluginModuleInfo
插件的模块信息。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**系统接口：** 此接口为系统接口。

| 名称           | 类型   | 只读 | 可选 | 说明           |
| -------------- | ------ | ---- | ---- | -------------- |
| moduleName   | string | 是   | 否   |  插件模块的名称。  |
| descriptionId   | number | 是   | 否   |  插件模块描述的资源id值。  |
| description   | string | 是   | 否   |  插件模块的描述信息。  |
