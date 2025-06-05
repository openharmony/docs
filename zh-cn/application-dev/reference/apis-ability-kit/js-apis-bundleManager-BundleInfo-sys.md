# BundleInfo (系统接口)

应用包信息，应用可以通过[bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo14)获取自身的应用包信息，其中入参[bundleFlags](js-apis-bundleManager.md#bundleflag)指定所返回的[BundleInfo](js-apis-bundleManager-bundleInfo.md)中所包含的信息。

> **说明：**
>
> 本模块首批接口从API version 20 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见（[BundleInfo](js-apis-bundleManager-bundleInfo.md)）。

## DynamicIconInfo

应用的动态图标信息。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**系统接口：** 此接口为系统接口。

| 名称      | 类型           | 只读 | 可选 | 说明                        |
| --------- | -------------- | ---- | ---- | --------------------------- |
| bundleName    | string    | 是   | 否   | 标识当前动态图标所属的应用包名信息。 |
| moduleName    | string    | 是   | 否   | 标识当前动态图标所属的应用模块名称信息。 |
| userId    | number    | 是   | 否   | 标识当前动态图标所属的用户信息。 |
| appIndex    | number    | 是   | 否   | 标识当前动态图标所属的应用分身索引信息。 |


## BundleOptions

应用包选项，用于设置或查询应用相关信息。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**系统接口：** 此接口为系统接口。

| 名称      | 类型           | 只读 | 可选 | 说明                |
| --------- | -------------- | ---- | ---- | ------------------- |
| userId | number         | 否   | 是   | 用户ID。默认为当前调用方所在的用户。             |
| appIndex | number         | 否   | 是   | 应用分身ID。默认为0，表示主应用。    |
