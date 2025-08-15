# PermissionDef (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

配置文件中定义的权限详细信息。

> **说明：**
>
> 本模块首批接口从API version 8 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 从API Version 9开始，该模块不再维护，建议使用[bundleManager-PermissionDef](js-apis-bundleManager-permissionDef-sys.md)替代。
>
> 本模块为系统接口。

## **PermissionDef**<sup>(deprecated)<sup>

> 从API version 9开始不再维护，建议使用[bundleManager-PermissionDef](js-apis-bundleManager-permissionDef-sys.md#permissiondef)替代。

 **系统能力：** SystemCapability.BundleManager.BundleFramework

 **系统接口：**  此接口为系统接口。

| 名称           | 类型   | 只读 | 可选 | 说明           |
| -------------- | ------ | ---- | ---- | -------------- |
| permissionName | string | 否   | 否   | 权限名称。   |
| grantMode      | number | 否   | 否   | 权限的授予模式。0表示安装后系统自动授予该权限，1表示使用时动态申请，用户授权后方可使用。 |
| labelId        | number | 否   | 否   | 权限的标签ID。   |
| descriptionId  | number | 否   | 否   | 描述权限的ID。   |