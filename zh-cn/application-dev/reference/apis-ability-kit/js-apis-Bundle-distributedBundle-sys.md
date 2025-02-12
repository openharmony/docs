# @ohos.distributedBundle (分布式包管理)(系统接口)

本模块提供分布式包的管理。

> **说明：**
>
> 本模块首批接口从API version 8 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## 导入模块

```
import distributedBundle from '@ohos.distributedBundle';
```

## 系统能力

SystemCapability.BundleManager.DistributedBundleFramework

## 权限列表

| 权限                                       | 权限等级     | 描述               |
| ------------------------------------------ | ------------ | ------------------ |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED | system_basic | 可查询所有应用信息 |

权限等级参考[权限APL等级说明](../../security/AccessToken/app-permission-mgmt-overview.md#权限机制中的基本概念)。

## distributedBundle.getRemoteAbilityInfo<sup>deprecated<sup>

> 从API version 9开始不再维护，建议使用[getRemoteAbilityInfo(@ohos.bundle.distributedBundleManager)](js-apis-distributedBundleManager-sys.md)替代。

getRemoteAbilityInfo(elementName: ElementName, callback: AsyncCallback&lt;RemoteAbilityInfo&gt;): void

根据给定的ElementName获取有关远程设备AbilityInfo信息，使用callback异步回调。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.DistributedBundleFramework

**系统接口：**

此接口为系统接口。

**参数：**

| 参数名      | 类型                                                         | 必填 | 说明                                               |
| ----------- | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| elementName | [ElementName](js-apis-bundle-ElementName.md)                 | 是   | 获得的ElementName信息。                            |
| callback    | AsyncCallback<[RemoteAbilityInfo](js-apis-bundle-remoteAbilityInfo-sys.md)> | 是   | 程序启动作为入参的回调函数，返回远程基本能力信息。 |



## distributedBundle.getRemoteAbilityInfo<sup>deprecated<sup>

> 从API version 9开始不再维护，建议使用[getRemoteAbilityInfo(@ohos.bundle.distributedBundleManager)](js-apis-distributedBundleManager-sys.md)替代。

getRemoteAbilityInfo(elementName: ElementName): Promise&lt;RemoteAbilityInfo&gt;

根据给定的ElementName获取有关远程设备AbilityInfo信息，使用Promise异步回调。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.DistributedBundleFramework

**系统接口：**

此接口为系统接口。

**参数：**

| 参数名      | 类型                                         | 必填 | 说明                    |
| ----------- | -------------------------------------------- | ---- | ----------------------- |
| elementName | [ElementName](js-apis-bundle-ElementName.md) | 是   | 获得的ElementName信息。 |

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<[RemoteAbilityInfo](js-apis-bundle-remoteAbilityInfo-sys.md)> | Promise形式返回远程基本能力信息。 |

## distributedBundle.getRemoteAbilityInfos<sup>deprecated<sup>

> 从API version 9开始不再维护，建议使用[getRemoteAbilityInfo(@ohos.bundle.distributedBundleManager)](js-apis-distributedBundleManager-sys.md)替代。

getRemoteAbilityInfos(elementNames: Array&lt;ElementName&gt;, callback: AsyncCallback&lt;Array&lt;RemoteAbilityInfo&gt;&gt;): void

根据给定的ElementName获取有关远程设备AbilityInfos信息，使用callback异步回调。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.DistributedBundleFramework

**系统接口：**

此接口为系统接口。

**参数：**

| 参数名       | 类型                                                         | 必填 | 说明                                               |
| ------------ | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| elementNames | Array<[ElementName](js-apis-bundle-ElementName.md)>          | 是   | ElementName信息，最大数组长度为10。                   |
| callback     | AsyncCallback< Array<[RemoteAbilityInfo](js-apis-bundle-remoteAbilityInfo-sys.md)>> | 是   | 程序启动作为入参的回调函数，返回远程基本能力信息。 |



## distributedBundle.getRemoteAbilityInfos<sup>deprecated<sup>

> 从API version 9开始不再维护，建议使用[getRemoteAbilityInfo(@ohos.bundle.distributedBundleManager)](js-apis-distributedBundleManager-sys.md)替代。

getRemoteAbilityInfos(elementNames: Array&lt;ElementName&gt;): Promise&lt;Array&lt;RemoteAbilityInfo&gt;&gt;

根据给定的ElementName获取有关远程设备AbilityInfos信息，使用Promise异步回调。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.DistributedBundleFramework

**系统接口：**

此接口为系统接口。

**参数：**

| 参数名      | 类型                                                | 必填 | 说明                  |
| ------------ | --------------------------------------------------- | ---- | ----------------------- |
| elementNames | Array<[ElementName](js-apis-bundle-ElementName.md)> | 是   | ElementName信息，最大数组长度为10。 |

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<Array<[RemoteAbilityInfo](js-apis-bundle-remoteAbilityInfo-sys.md)>> | Promise形式返回远程基本能力信息。 |
