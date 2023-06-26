# 设备管理ChangeLog
## cl.distributedDeviceManager.1 接口变更

从Opeharmonny 4.0.9.2版本开始，新增了设备管理接口，部分接口仅系统应用可调用。

**变更影响**

原有的接口暂时可继续使用，但是停止维护，建议使用新接口进行开发。

**关键的接口/组件变更**

##新增接口如下:

| 模块名                    | 类名                | 新增接口声明                                                   | 是否支持三方应用调用             |                                        
| ------------------------- | ------------------- | ------------------------------------------------------------ | ------------------------------- |
| @ohos.distributedDeviceManager       | deviceManager        | **function** createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void            | 是    |
| @ohos.distributedDeviceManager       | deviceManager        | **function** releaseDeviceManager(): void | 是 |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getAvailableDeviceListSync(): Array&lt;DeviceBasicInfo&gt; | 是 |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getAvailableDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceBasicInfo&gt;&gt;): void | 是    |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getAvailableDeviceList(): Promise&lt;Array&lt;DeviceBasicInfo&gt;&gt; | 是              |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getLocalDeviceNetworkIdSync(): string | 是            |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getLocalDeviceNameSync(): string | 是         |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getLocalDeviceTypeSync(): number | 是           |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getLocalDeviceIdSync(): string | 是    |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getDeviceNameSync(networkId: string): string; | 是     |
| @ohos.distributedDeviceManager       | deviceManager        | **function** getDeviceTypeSync(networkId: string): number; | 是     |
| @ohos.distributedDeviceManager       | deviceManager        | **function** startDeviceDiscovery(subscribeId: number, filterOptions?: string): void; | 是 |
| @ohos.distributedDeviceManager       | deviceManager        | **function** stopDeviceDiscovery(subscribeId: number): void | 是       |
| @ohos.distributedDeviceManager       | deviceManager        | **function** bindDevice(deviceId: string, bindParam: BindParam, callback: AsyncCallback&lt;{deviceId: string}&gt;): void; | 是      |
| @ohos.distributedDeviceManager       | deviceManager        | **function** unbindDevice(deviceId: string): void; | 是     |
| @ohos.distributedDeviceManager       | deviceManager        | **function** publishDeviceDiscovery(publishInfo: PublishInfo): void | 否    |
| @ohos.distributedDeviceManager       | deviceManager        | **function** unPublishDeviceDiscovery(publishId: number): void | 否    |
| @ohos.distributedDeviceManager       | deviceManager        | **function** verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback&lt;{deviceId: string, level: number}&gt;): void | 否    |
| @ohos.distributedDeviceManager       | deviceManager        | **function** setUserOperation(operateAction: number, params: string): void; | 否    |
| @ohos.distributedDeviceManager       | deviceManager        | **function** requestCredentialRegisterInfo(requestInfo: string, callback: AsyncCallback&lt;{registerInfo: string}&gt;): void; | 否     |
| @ohos.distributedDeviceManager       | deviceManager        | **function** importCredential(credentialInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void; | 否    |
| @ohos.distributedDeviceManager       | deviceManager        | **function** deleteCredential(queryInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void; | 否     |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'deviceStatusChange', callback: Callback&lt;{ action: DeviceStatusChange, device: DeviceBasicInfo }&gt;): void; | 是       |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'deviceStatusChange', callback?: Callback&lt;{ action: DeviceStatusChange, device: DeviceBasicInfo }&gt;): void; | 是       |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'discoverSuccess', callback: Callback&lt;{ subscribeId: number, device: DeviceBasicInfo }&gt;): void; | 是   |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'discoverSuccess', callback?: Callback&lt;{ subscribeId: number, device: DeviceBasicInfo }&gt;): void; | 是   |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'deviceNameChange', callback: Callback&lt;{ deviceName: string }&gt;): void; | 是               |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'deviceNameChange', callback?: Callback&lt;{ deviceName: string }&gt;): void; | 是               |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void | 是   |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void | 是 |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'serviceDie', callback: () =&gt; void): void | 是         |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'serviceDie', callback?: () =&gt; void): void | 是        |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'uiStateChange', callback: Callback&lt;{ param: string}&gt;): void; | 否    |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'uiStateChange', callback?: Callback&lt;{ param: string}&gt;): void; | 否    |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'publishSuccess', callback: Callback&lt;{ publishId: number }&gt;): void | 否       |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'publishSuccess', callback?: Callback&lt;{ publishId: number }&gt;): void | 否       |
| @ohos.distributedDeviceManager       | deviceManager        | **function** on(type: 'publishFail', callback: Callback&lt;{ publishId: number, reason: number }&gt;): void | 否      |
| @ohos.distributedDeviceManager       | deviceManager        | **function** off(type: 'publishFail', callback?: Callback&lt;{ publishId: number, reason: number }&gt;): void | 否     |

**适配指导**

请参考各接口的[API参考](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md)
