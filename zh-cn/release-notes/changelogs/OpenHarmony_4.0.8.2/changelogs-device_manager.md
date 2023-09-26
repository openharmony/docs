# 设备管理ChangeLog
## cl.device_manager.1 接口权限变更

从Openharmony 4.0.8.2版本开始，部分接口新增权限校验。

**变更影响**

从Openharmony 4.0.8.2之后版本开发的应用，需要持有相应权限，否则无法正常调用接口。

**关键的接口/组件变更**

| 模块名                    | 类名                | 方法/属性/枚举/常量                                          | 新增权限 |
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** release(): void | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** getTrustedDeviceListSync(): Array&lt;DeviceInfo&gt; | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** getTrustedDeviceListSync(isRefresh: boolean): Array&lt;DeviceInfo&gt;; | ohos.permission.ACCESS_SERVICE_DM     |
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
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** requestCredentialRegisterInfo(requestInfo: string, callback: AsyncCallback&lt;{registerInfo: string}&gt;): void; | ohos.permission.ACCESS_SERVICE_DM    |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** importCredential(credentialInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void; | ohos.permission.ACCESS_SERVICE_DM     |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **function** deleteCredential(queryInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void; | ohos.permission.ACCESS_SERVICE_DM     |
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


## cl.device_manager.2 所有接口进行系统接口权限校验

从Openharmony 4.0.8.2版本开始，所有接口进行系统接口权限校验。

**变更影响**

非系统应用无法调用系统接口，如调用方为非系统应用或未申请SystemApi相关权限，将无法调用接口。

**关键的接口/组件变更**

所有接口均进行系统接口权限校验，接口明细如下：

| 接口、枚举或变量名 | 类型 | 是否为SystemApi |
| -------- | -------- | ------- |
| createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void;                 | interface | 是 |
| release(): void                                                                                        | interface | 是 |
| getTrustedDeviceListSync(): Array&lt;DeviceInfo&gt;                                                    | interface | 是 |
| getTrustedDeviceListSync(isRefresh: boolean): Array&lt;DeviceInfo&gt;;                                       | interface | 是 |
| getTrustedDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceInfo&gt;&gt;): void                      | interface | 是 |
| getTrustedDeviceList(): Promise&lt;Array&lt;DeviceInfo&gt;&gt;                                         | interface | 是 |
| getLocalDeviceInfoSync(): DeviceInfo                                                                   | interface | 是 |
| getLocalDeviceInfo(callback:AsyncCallback&lt;DeviceInfo&gt;): void                                     | interface | 是 |
| getLocalDeviceInfo(): Promise&lt;DeviceInfo&gt;                                                        | interface | 是 |
| getDeviceInfo(networkId: string, callback:AsyncCallback&lt;DeviceInfo&gt;): void                       | interface | 是 |
| getDeviceInfo(networkId: string): Promise&lt;DeviceInfo&gt;                                            | interface | 是 |
| startDeviceDiscovery(subscribeInfo: SubscribeInfo): void                                               | interface | 是 |
| startDeviceDiscovery(subscribeInfo: SubscribeInfo, filterOptions?: string): void                       | interface | 是 |
| stopDeviceDiscovery(subscribeId: number): void                                                         | interface | 是 |
| publishDeviceDiscovery(publishInfo: PublishInfo): void                                                 | interface | 是 |
| unPublishDeviceDiscovery(publishId: number): void                                                      | interface | 是 |
| authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback&lt;{deviceId: string, pinToken ?: number}&gt;): void   |interface | 是 |
| unAuthenticateDevice(deviceInfo: DeviceInfo): void                                                     | interface | 是 |
| verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback&lt;{deviceId: string, level: number}&gt;): void          | interface | 是 |
| setUserOperation(operateAction: number, params: string): void                                          | interface | 是 |
| requestCredentialRegisterInfo(requestInfo: string, callback: AsyncCallback&lt;{registerInfo: string}&gt;): void;    | interface | 是 |
| importCredential(credentialInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void;                | interface | 是 |
| deleteCredential(queryInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void;                     | interface | 是 |
| on(type: 'uiStateChange', callback: Callback&lt;{ param: string}&gt;): void;                                        | interface | 是 |
| off(type: 'uiStateChange', callback?: Callback&lt;{ param: string}&gt;): void;                                      | interface | 是 |
| on(type: 'deviceStateChange',  callback: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void                   | interface | 是 |
| off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void                  | interface | 是 |
| on(type: 'deviceFound', callback: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void                                      | interface | 是 |
| off(type: 'deviceFound', callback?: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void                                    | interface | 是 |
| on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void                                         | interface | 是 |
| off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void                                       | interface | 是 |
| on(type: 'publishSuccess', callback: Callback&lt;{ publishId: number }&gt;): void                                                         | interface | 是 |
| off(type: 'publishSuccess', callback?: Callback&lt;{ publishId: number }&gt;): void                                                       | interface | 是 |
| on(type: 'publishFail', callback: Callback&lt;{ publishId: number, reason: number }&gt;): void                                            | interface | 是 |
| off(type: 'publishFail', callback?: Callback&lt;{ publishId: number, reason: number }&gt;): void                                          | interface | 是 |
| on(type: 'serviceDie', callback: () =&gt; void): void                                                    | interface | 是 |
| off(type: 'serviceDie', callback?: () =&gt; void): void                                                  | interface | 是 |

**适配指导**

调用以上接口，调用方需要为系统应用或申请SystemApi相关权限。
