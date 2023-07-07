# 设备管理ChangeLog
## cl.distributedDeviceManager.1 接口变更

从Openharmony 4.0.9.2版本开始，新增设备管理接口。

**变更影响**

原有的接口[API参考](../../../application-dev/reference/apis/js-apis-device-manager.md)暂时可继续使用，但是停止维护，建议使用新接口进行开发。

**关键的接口/组件变更**

##新增接口如下:

| 模块名                                | 类名                | 新增接口声明                                                   |
| ------------------------------------ | ------------------- | ------------------------------------------------------------ |
| @ohos.distributedDeviceManager       | function        | **function** createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void;            |
| @ohos.distributedDeviceManager       | deviceManager        | **function** releaseDeviceManager(): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getAvailableDeviceListSync(): Array&lt;DeviceBasicInfo&gt;; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getAvailableDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceBasicInfo&gt;&gt;): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getAvailableDeviceList(): Promise&lt;Array&lt;DeviceBasicInfo&gt;&gt;; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getLocalDeviceNetworkIdSync(): string; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getLocalDeviceNameSync(): string; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getLocalDeviceTypeSync(): number; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getLocalDeviceIdSync(): string; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getDeviceNameSync(networkId: string): string; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getDeviceTypeSync(networkId: string): number; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** startDiscovering(discoverParameter:string, filterOptions?: string): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** stopDiscovering(): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** bindTarget(deviceId: string, bindParam: BindParam, callback: AsyncCallback&lt;{deviceId: string}&gt;): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** unbindTarget(deviceId: string): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** replyUiAction(action: number, params: string): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'replyResult', callback: Callback&lt;{ param: string}&gt;): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'replyResult', callback?: Callback&lt;{ param: string}&gt;): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'deviceStatusChange', callback: Callback&lt;{ action: DeviceStatusChange, device: DeviceBasicInfo }&gt;): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'deviceStatusChange', callback?: Callback&lt;{ action: DeviceStatusChange, device: DeviceBasicInfo }&gt;): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'discoverSuccess', callback: Callback&lt;{ device: DeviceBasicInfo }&gt;): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'discoverSuccess', callback?: Callback&lt;{ device: DeviceBasicInfo }&gt;): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'deviceNameChange', callback: Callback&lt;{ deviceName: string }&gt;): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'deviceNameChange', callback?: Callback&lt;{ deviceName: string }&gt;): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'discoverFail', callback: Callback&lt;{ reason: number }&gt;): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'discoverFail', callback?: Callback&lt;{ reason: number }&gt;): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'serviceDie', callback: () =&gt; void): void; |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'serviceDie', callback?: () =&gt; void): void; |

**适配指导**

请参考各接口的[API参考](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md)
