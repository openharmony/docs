# 设备管理ChangeLog
## cl.distributedDeviceManager.1 接口变更

从Opeharmonny 4.0.9.2版本开始，新增了设备管理接口。

**变更影响**

原有的接口[API参考](../../../application-dev/reference/apis/js-apis-device-manager.md)暂时可继续使用，但是停止维护，建议使用新接口进行开发。

**关键的接口/组件变更**

##新增接口如下:

| 模块名                    | 类名                | 新增接口声明                                                   | 是否支持三方应用调用             |                                        
| ------------------------- | ------------------- | ------------------------------------------------------------ | ------------------------------- |
| @ohos.distributedDeviceManager       | deviceManager        | **function** createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void;            | 是    |
| @ohos.distributedDeviceManager       | deviceManager        | **function** releaseDeviceManager(): void; | 是 |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getAvailableDeviceListSync(): Array&lt;DeviceBasicInfo&gt;; | 是 |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getAvailableDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceBasicInfo&gt;&gt;): void; | 是    |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getAvailableDeviceList(): Promise&lt;Array&lt;DeviceBasicInfo&gt;&gt;; | 是              |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getLocalDeviceNetworkIdSync(): string; | 是            |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getLocalDeviceNameSync(): string; | 是         |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getLocalDeviceTypeSync(): number; | 是           |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getLocalDeviceIdSync(): string; | 是    |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getDeviceNameSync(networkId: string): string; | 是     |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getDeviceTypeSync(networkId: string): number; | 是     |
| @ohos.distributedDeviceManager       | deviceManager        | **function** startDiscovering(subscribeId: number, filterOptions?: string): void; | 是 |
| @ohos.distributedDeviceManager       | deviceManager        | **function** stopDiscovering(subscribeId: number): void; | 是       |
| @ohos.distributedDeviceManager       | deviceManager        | **function** bindTarget(deviceId: string, bindParam: BindParam, callback: AsyncCallback&lt;{deviceId: string}&gt;): void; | 是      |
| @ohos.distributedDeviceManager       | deviceManager        | **function** unbindTarget(deviceId: string): void; | 是     |
| @ohos.distributedDeviceManager       | deviceManager        | **function** replyUiAction(action: number, params: string): void; | 否    |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'replyResult', callback: Callback&lt;{ param: string}&gt;): void; | 否       |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'replyResult', callback?: Callback&lt;{ param: string}&gt;): void; |否       |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'deviceStatusChange', callback: Callback&lt;{ action: DeviceStatusChange, device: DeviceBasicInfo }&gt;): void; | 是   |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'deviceStatusChange', callback?: Callback&lt;{ action: DeviceStatusChange, device: DeviceBasicInfo }&gt;): void; | 是   |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'discoverSuccess', callback: Callback&lt;{ subscribeId: number, device: DeviceBasicInfo }&gt;): void; | 是               |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'discoverSuccess', callback?: Callback&lt;{ subscribeId: number, device: DeviceBasicInfo }&gt;): void; | 是               |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'deviceNameChange', callback: Callback&lt;{ deviceName: string }&gt;): void; | 是   |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'deviceNameChange', callback?: Callback&lt;{ deviceName: string }&gt;): void; | 是 |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void; | 是         |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void; | 是        |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'serviceDie', callback: () =&gt; void): void; | 是    |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'serviceDie', callback?: () =&gt; void): void; | 是    |

**适配指导**

请参考各接口的[API参考](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md)
