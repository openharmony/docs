# RemoteAbilityInfo (系统接口)

包含远程的ability信息，通过接口[distributedBundle.getRemoteAbilityInfo](js-apis-distributedBundleManager-sys.md#distributedbundlegetremoteabilityinfo)获取。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## RemoteAbilityInfo

 **系统能力:** SystemCapability.BundleManager.DistributedBundleFramework

 **系统接口：** 此接口为系统接口。

| 名称        | 类型                                         | 只读 | 可选 | 说明                    |
| ----------- | -------------------------------------------- | ---- | ---- | ----------------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md) | 是   | 否   | 指明远程ability的ElementName信息。       |
| label       | string                                       | 是   | 否   | 指明远程ability的标签信息。   |
| icon        | string                                       | 是   | 否   | 指明的远程ability的图标信息。 |
