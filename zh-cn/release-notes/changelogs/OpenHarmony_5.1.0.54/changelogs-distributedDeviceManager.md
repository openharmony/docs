# 分布式设备管理Changelog

## cl.distributedDeviceManager.1 分布式设备管理API接口错误码变更

**访问级别**

公开接口。

**变更原因**

- 错误码401可能原因包括：1. 必选参数未指定；2. 参数类型不正确；3. 参数校验失败。

  接口getAvailableDeviceListSync与stopDiscovering没有可传参数，所以需要删除错误码401。

- 错误码11600104可能原因为：上一次发现业务未结束。

  接口stopDiscovering流程不会触发该错误，所以需要删除错误码11600104。

- 错误码201可能原因为：权限校验失败。

  接口releaseDeviceManager和createDeviceManager配对使用，两者权限校验逻辑保持一致，createDeviceManager不存在权限校验，所以需要删除错误码201。

**变更影响**

该变更不涉及应用适配。

- 变更前：@ohos.distributedDeviceManager模块存在releaseDeviceManager函数声明201错误码。

  变更后：@ohos.distributedDeviceManager模块删除releaseDeviceManager函数声明201错误码。

- 变更前：@ohos.distributedDeviceManager模块存在getAvailableDeviceListSync函数声明401错误码。

  变更后：@ohos.distributedDeviceManager模块删除getAvailableDeviceListSync函数声明401错误码。

- 变更前：@ohos.distributedDeviceManager模块存在stopDiscovering函数声明401、11600104错误码。

  变更后：@ohos.distributedDeviceManager模块删除stopDiscovering函数声明401、11600104错误码。

**起始 API Level**

10。

**变更发生版本**

从OpenHarmony SDK 5.1.0.54开始。

**变更的接口/组件**

本次变更主要涉及如下模块的注释更新：

| 模块名                                | 类名                | 接口声明                                                   |主要变更点说明    |
| ------------------------------------ | ------------------- | ------------------------------------------------------------ | -------------- |
| @ohos.distributedDeviceManager       | function             | **function** releaseDeviceManager(deviceManager: DeviceManager): void; | 删除201错误码。 |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** getAvailableDeviceListSync(): Array&lt;DeviceBasicInfo&gt;; | 删除401错误码。 |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** stopDiscovering(): void; | 删除401、11600104错误码。   |

**适配指导**

默认行为变更，无需适配。
