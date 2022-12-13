# @ohos.deviceInfo (设备信息)

本模块提供产品信息。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import deviceInfo from '@ohos.deviceInfo'
```

## 属性

**系统能力**：SystemCapability.Startup.SystemInfo。

**权限**：以下各项所需要的权限有所不同，详见下表。

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceType | string | 是 | 否 | 设备类型。 |
| manufacture | string | 是 | 否 | 设备厂家名称。 |
| brand | string | 是 | 否 | 设备品牌名称。 |
| marketName | string | 是 | 否 | 外部产品系列。 |
| productSeries | string | 是 | 否 | 产品系列。 |
| productModel | string | 是 | 否 | 认证型号。 |
| softwareModel | string | 是 | 否 | 内部软件子型号。 |
| hardwareModel | string | 是 | 否 | 硬件版本号。 |
| hardwareProfile | string | 是 | 否 | 硬件Profile。 |
| serial | string | 是 | 否 | 设备序列号。<br/>**需要权限**：ohos.permission.sec.ACCESS_UDID，该权限为系统权限 |
| bootloaderVersion | string | 是 | 否 | Bootloader版本号。 |
| abiList | string | 是 | 否 | 应用二进制接口（Abi）列表。 |
| securityPatchTag | string | 是 | 否 | 安全补丁级别。 |
| displayVersion | string | 是 | 否 | 产品版本。 |
| incrementalVersion | string | 是 | 否 | 差异版本号。 |
| osReleaseType | string | 是 | 否 | 系统的发布类型，取值为：<br/>-&nbsp;Canary：面向特定开发者发布的早期预览版本，不承诺API稳定性。<br/>-&nbsp;Beta：面向开发者公开发布的Beta版本，不承诺API稳定性。<br/>-&nbsp;Release：面向开发者公开发布的正式版本，承诺API稳定性。 |
| osFullName | string | 是 | 否 | 系统版本。 |
| majorVersion | number | 是 | 否 | Major版本号，随主版本更新增加。 |
| seniorVersion | number | 是 | 否 | Senior版本号，随局部架构、重大特性增加。 |
| featureVersion | number | 是 | 否 | Feature版本号，标识规划的新特性版本。 |
| buildVersion | number | 是 | 否 | Build版本号，标识编译构建的版本号。 |
| sdkApiVersion | number | 是 | 否 | 系统软件API版本。 |
| firstApiVersion | number | 是 | 否 | 首个版本系统软件API版本。 |
| versionId | string | 是 | 否 | 版本ID。 |
| buildType | string | 是 | 否 | 构建类型。 |
| buildUser | string | 是 | 否 | 构建用户。 |
| buildHost | string | 是 | 否 | 构建主机。 |
| buildTime | string | 是 | 否 | 构建时间。 |
| buildRootHash | string | 是 | 否 | 构建版本Hash。 |
| udid<sup>7+</sup> | string | 是 | 否 | 设备Udid。<br/>**需要权限**：ohos.permission.sec.ACCESS_UDID，该权限为系统权限|
