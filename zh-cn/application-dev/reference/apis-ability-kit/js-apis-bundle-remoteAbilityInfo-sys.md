# RemoteAbilityInfo (系统接口)

remoteAbility信息。

> **说明：**
>
> 本模块首批接口从API version 8 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## RemoteAbilityInfo<sup>(deprecated)<sup>

> 从API version 9开始不再维护，建议使用[bundleManager-RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md)替代。

 **系统能力:** SystemCapability.BundleManager.DistributedBundleFramework

 **系统接口：**  此接口为系统接口。

| 名称        | 类型                                         | 只读 | 可选 | 说明                    |
| ----------- | -------------------------------------------- | ---- | ---- | ----------------------- |
| elementName | [ElementName](js-apis-bundle-ElementName.md) | 是   | 否   | ability元素资源信息。       |
| label       | string                                       | 是   | 否   | 指明ability的名称。   |
| icon        | string                                       | 是   | 否   | 指明的ability的图标信息。 |
