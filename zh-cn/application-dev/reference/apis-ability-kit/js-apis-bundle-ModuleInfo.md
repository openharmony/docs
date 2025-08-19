# ModuleInfo
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

应用程序的模块信息。

> **说明：**
> 
> 本模块首批接口从API version 7 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 从API Version 9开始，该模块不再维护，建议使用[bundleManager-HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md)替代。

## ModuleInfo<sup>(deprecated)<sup>
> 从API version 9开始不再维护，建议使用[bundleManager-HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md#hapmoduleinfo-1)替代。

**系统能力：** SystemCapability.BundleManager.BundleFramework
| 名称            | 类型   | 只读 | 可选 | 说明     |
| --------------- | ------ | ---- | ---- | -------- |
| moduleName      | string | 是   | 否   | 模块名称。 |
| moduleSourceDir | string | 是   | 否   | 安装目录。不能拼接路径访问资源文件，请使用[资源管理接口](../apis-localization-kit/js-apis-resource-manager.md)访问资源。 |