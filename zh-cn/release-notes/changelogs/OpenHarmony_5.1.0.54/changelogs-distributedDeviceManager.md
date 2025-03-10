# 设备管理ChangeLog

从OpenHarmony 5.1.0.54版本开始，设备管理的API删除了无效错误码信息。

## cl.distributedDeviceManager.1 API删除无效错误码及描述

相较之前版本，删除API接口中无效错误码及描述。

**变更影响**

影响API10版本的JS接口对外声明，对实际功能无影响，开发者可选择是否适配。

**关键的接口/组件变更**

本次变更主要涉及如下模块的注释更新，详细请参考对应的对外接口声明及API开发指导文档：

| 模块名                                | 类名                | 接口声明                                                   |主要变更点说明    |
| ------------------------------------ | ------------------- | ------------------------------------------------------------ | 
| @ohos.distributedDeviceManager       | function             | **function** releaseDeviceManager(deviceManager: DeviceManager): void; | 删除201错误码返回说明。 |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** getAvailableDeviceListSync(): Array&lt;DeviceBasicInfo&gt;; | 删除401错误码返回说明。 |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** stopDiscovering(): void; | 删除401、11600104错误码返回说明。   |

**适配指导**

请参考各接口的[API参考](../../../application-dev/reference/apis-distributedservice-kit/js-apis-distributedDeviceManager.md)。
