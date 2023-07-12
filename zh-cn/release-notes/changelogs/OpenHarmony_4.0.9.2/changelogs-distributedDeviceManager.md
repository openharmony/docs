# 设备管理ChangeLog
## cl.distributedDeviceManager.1 接口变更

从Openharmony 4.0.9.2版本开始，新增设备管理接口。

**变更影响**

原有的接口[API参考](../../../application-dev/reference/apis/js-apis-device-manager.md)暂时可继续使用，但是停止维护，建议使用新接口进行开发。

**关键的接口/组件变更**

##新增接口如下:

| 模块名                                | 类名                | 新增接口声明                                                   |
| ------------------------------------ | ------------------- | ------------------------------------------------------------ |
| @ohos.distributedDeviceManager       | function             | **function** createDeviceManager(bundleName: string): DeviceManager;           |
| @ohos.distributedDeviceManager       | function             | **function** releaseDeviceManager(deviceManager: DeviceManager): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** getAvailableDeviceListSync(): Array&lt;DeviceBasicInfo&gt;; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** getAvailableDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceBasicInfo&gt;&gt;): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** getAvailableDeviceList(): Promise&lt;Array&lt;DeviceBasicInfo&gt;&gt;; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** getLocalDeviceNetworkId(): string; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** getLocalDeviceName(): string; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** getLocalDeviceType(): number; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** getLocalDeviceId(): string; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** getDeviceName(networkId: string): string; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** getDeviceType(networkId: string): number; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** startDiscovering(discoverParam: {[key:&nbsp;string]:&nbsp;Object} , filterOptions?: {[key:&nbsp;string]:&nbsp;Object} ): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** stopDiscovering(): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** bindTarget(deviceId: string, bindParam: {[key:&nbsp;string]:&nbsp;Object} , callback: AsyncCallback&lt;{deviceId: string}&gt;): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** unbindTarget(deviceId: string): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** replyUiAction(action: number, actionResult: string): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** on(type: 'replyResult', callback: Callback&lt;{ param: string}&gt;): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** off(type: 'replyResult', callback?: Callback&lt;{ param: string}&gt;): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** on(type: 'deviceStateChange', callback: Callback&lt;{ action: DeviceStateChange, device: DeviceBasicInfo }&gt;): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChange, device: DeviceBasicInfo }&gt;): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** on(type: 'discoverSuccess', callback: Callback&lt;{ device: DeviceBasicInfo }&gt;): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** off(type: 'discoverSuccess', callback?: Callback&lt;{ device: DeviceBasicInfo }&gt;): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** on(type: 'deviceNameChange', callback: Callback&lt;{ deviceName: string }&gt;): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** off(type: 'deviceNameChange', callback?: Callback&lt;{ deviceName: string }&gt;): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** on(type: 'discoverFailure', callback: Callback&lt;{ reason: number }&gt;): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** off(type: 'discoverFailure', callback?: Callback&lt;{ reason: number }&gt;): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** on(type: 'serviceDie', callback?: Callback&lt;{}&gt;): void; |
| @ohos.distributedDeviceManager       | DeviceManager        | **function** off(type: 'serviceDie', callback?: Callback&lt;{}&gt;): void; |

**适配指导**

请参考各接口的[API参考](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md)
