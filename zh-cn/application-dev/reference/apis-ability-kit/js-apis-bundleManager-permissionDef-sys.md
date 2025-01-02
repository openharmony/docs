# PermissionDef (系统接口)

配置文件中定义的权限详细信息，通过接口[bundleManager.getPermissionDef](js-apis-bundleManager-sys.md#bundlemanagergetpermissiondef)获取。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## **PermissionDef**

 **系统能力:** SystemCapability.BundleManager.BundleFramework.Core

 **系统接口：**  系统接口，三方应用不支持调用

| 名称           | 类型   | 只读 | 可选 | 说明           |
| -------------- | ------ | ---- | ---- | -------------- |
| permissionName | string | 是   | 否   | 用户权限名称。   |
| grantMode      | number | 是   | 否   | 权限的授予模式。 |
| labelId        | number | 是   | 否   | 权限的标签ID。   |
| descriptionId  | number | 是   | 否   | 描述权限的ID。   |