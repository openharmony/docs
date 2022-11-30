# PermissionDef



> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。



配置文件中定义的权限详细信息。

## **PermissionDef**<sup>(deprecated)<sup>

> 从API version 9开始不再维护，建议使用[PermissionDef](js-apis-bundleManager-permissionDef.md)替代。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

 **系统API：**  此接口为系统接口，三方应用不支持调用

| 名称           | 类型   | 可读 | 可写 | 说明           |
| -------------- | ------ | ---- | ---- | -------------- |
| permissionName | string | 是   | 否   | 权限名称。   |
| grantMode      | number | 是   | 否   | 权限的授予模式，0表示安装后系统自动授予该权限，1表示使用时动态申请，用户授权后方可使用。 |
| labelId        | number | 是   | 否   | 权限的标签ID。   |
| descriptionId  | number | 是   | 否   | 描述权限的ID。   |