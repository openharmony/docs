# BusinessAbilityInfo (系统接口)

> **说明：**
>
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

包含基本业务路由信息。

## BusinessAbilityInfo

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

| 名称                              | 类型                                                         | 可读 | 可写 | 说明                 |
| --------------------------------- | ------------------------------------------------------------ | ---- | ---- | -------------------- |
| bundleName                        | string                                                       | 是   | 否   | 表示应用程序的bundleName。 |
| moduleName                        | string                                                       | 是   | 否   | 表示应用程序的moduleName。 |
| name                              | string                                                       | 是   | 否   | 业务路由ability名。 |
| labelId                           | number                                                       | 是   | 否   | 模块标签的资源id。       |
| descriptionId                     | number                                                       | 是   | 否   | 描述信息的资源id。       |
| iconId                            | number                                                       | 是   | 否   | 描述ability信息的图标id。 |
| businessType | [businessAbilityRouter.BusinessType](js-apis-businessAbilityRouter-sys.md#businesstype) | 是 | 否 | 标识枚举业务类型。 |
| applicationInfo | Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | 是   | 否   | 应用程序的信息。  |
