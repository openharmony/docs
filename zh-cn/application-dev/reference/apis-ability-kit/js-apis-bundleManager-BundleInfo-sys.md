# BundleInfo (系统接口)

应用包信息，三方应用可以通过[bundleManager.getBundleInfoForSelf](js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)获取自身的应用包信息，其中入参[bundleFlags](js-apis-bundleManager.md#bundleflag)指定所返回的[BundleInfo](js-apis-bundleManager-bundleInfo.md)中所包含的信息。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见（[BundleInfo](js-apis-bundleManager-bundleInfo.md)）。

## AppCloneIdentity<sup>14+<sup>

描述应用包的身份信息。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core。

| 名称      | 类型           | 只读 | 可选 | 说明                        |
| --------- | -------------- | ---- | ---- | --------------------------- |
| bundleName | string         | 是   | 否   | 应用的bundleName。          |
| appIndex | number | 是   | 否   | 应用包的分身索引信息。 |