# 设备管理ChangeLog
## cl.device_manager.1 接口权限变更

从Opeharmonny 4.0.8.2版本开始，全部接口新增权限校验。

**变更影响**

在Opeharmonny 4.0.8.2之后版本开发的应用，需要持有相应权限，否则无法正常调用接口。

**关键的接口/组件变更**

| 模块名                    | 类名                | 方法/属性/枚举/常量                                          | 新增权限 |
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.distributedHardware.deviceManager        | deviceManager        | **function** createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** release(): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** getTrustedDeviceListSync(): Array&lt;DeviceInfo&gt; | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** getTrustedDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceInfo&gt;&gt;): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** getTrustedDeviceList(): Promise&lt;Array&lt;DeviceInfo&gt;&gt; | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** getLocalDeviceInfoSync(): DeviceInfo | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** getLocalDeviceInfo(callback:AsyncCallback&lt;DeviceInfo&gt;): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** getLocalDeviceInfo(): Promise&lt;DeviceInfo&gt; | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** getDeviceInfo(networkId: string, callback:AsyncCallback&lt;DeviceInfo&gt;): void | ohos.permission.ACCESS_SERVICE_DM    |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** getDeviceInfo(networkId: string): Promise&lt;DeviceInfo&gt; | ohos.permission.ACCESS_SERVICE_DM    |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** startDeviceDiscovery(subscribeInfo: SubscribeInfo): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** startDeviceDiscovery(subscribeInfo: SubscribeInfo, filterOptions?: string): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** stopDeviceDiscovery(subscribeId: number): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** publishDeviceDiscovery(publishInfo: PublishInfo): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager        | deviceManager        | **function** unPublishDeviceDiscovery(publishId: number): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager        | deviceManager        | **function** authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback&lt;{deviceId: string, pinToken ?: number}&gt;): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** unAuthenticateDevice(deviceInfo: DeviceInfo): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback&lt;{deviceId: string, level: number}&gt;): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** setUserOperation(operateAction: number, params: string): void | ohos.permission.ACCESS_SERVICE_DM    |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** requestCredentialRegisterInfo(requestInfo: string, callback: AsyncCallback<{registerInfo: string}>): void; | ohos.permission.ACCESS_SERVICE_DM    |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** importCredential(credentialInfo: string, callback: AsyncCallback<{resultInfo: string}>): void; | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** deleteCredential(queryInfo: string, callback: AsyncCallback<{resultInfo: string}>): void; | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** on(type: 'uiStateChange', callback: Callback&lt;{ param: string}&gt;): void; | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** off(type: 'uiStateChange', callback?: Callback&lt;{ param: string}&gt;): void; | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager        | deviceManager        | **function** on(type: 'deviceStateChange',  callback: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager        | deviceManager        | **function** off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager        | deviceManager        | **function** on(type: 'deviceFound', callback: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager        | deviceManager        | **function** off(type: 'deviceFound', callback?: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager        | deviceManager        | **function** on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager        | deviceManager        | **function** off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager        | deviceManager        | **function** on(type: 'publishSuccess', callback: Callback&lt;{ publishId: number }&gt;): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager        | deviceManager        | **function** off(type: 'publishSuccess', callback?: Callback&lt;{ publishId: number }&gt;): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager        | deviceManager        | **function** on(type: 'publishFail', callback: Callback&lt;{ publishId: number, reason: number }&gt;): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager        | deviceManager        | **function** off(type: 'publishFail', callback?: Callback&lt;{ publishId: number, reason: number }&gt;): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager        | deviceManager        | **function** on(type: 'serviceDie', callback: () =&gt; void): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager        | deviceManager        | **function** off(type: 'serviceDie', callback?: () =&gt; void): void | ohos.permission.ACCESS_SERVICE_DM     |

**适配指导**

调用以上接口，需要申请相应的权限才能正常调用。
