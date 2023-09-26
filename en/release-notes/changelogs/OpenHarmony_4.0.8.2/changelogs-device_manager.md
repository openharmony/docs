# Device Management Changelog
## cl.device_manager.1 API Permission Change

Added permission verification for some APIs.

**Change Impact**

The apps developed using OpenHarmony 4.0.8.2 or later must have the corresponding permissions. Otherwise, the related APIs cannot be called.

**Key API/Component Changes**

| Module                   | Class               | Method/Attribute/Enum/Constant                                         | Added Permission|
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

**Adaptation Guide**

Apply for the corresponding permissions for your application before these APIs are called.


## cl.device_manager.2 Permission Verification for All System APIs

Added permission verification for all system APIs.

**Change Impact**

Non-system applications and applications without system API permission cannot call system APIs.

**Key API/Component Changes**

System API permission verification is performed on all APIs. The table below describes the APIs.

| API/Enum/Variable| Type| System API|
| -------- | -------- | ------- |
| createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void;                 | interface | Yes|
| release(): void                                                                                        | interface | Yes|
| getTrustedDeviceListSync(): Array&lt;DeviceInfo&gt;                                                    | interface | Yes|
| getTrustedDeviceListSync(isRefresh: boolean): Array&lt;DeviceInfo&gt;;                                       | interface | Yes|
| getTrustedDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceInfo&gt;&gt;): void                      | interface | Yes|
| getTrustedDeviceList(): Promise&lt;Array&lt;DeviceInfo&gt;&gt;                                         | interface | Yes|
| getLocalDeviceInfoSync(): DeviceInfo                                                                   | interface | Yes|
| getLocalDeviceInfo(callback:AsyncCallback&lt;DeviceInfo&gt;): void                                     | interface | Yes|
| getLocalDeviceInfo(): Promise&lt;DeviceInfo&gt;                                                        | interface | Yes|
| getDeviceInfo(networkId: string, callback:AsyncCallback&lt;DeviceInfo&gt;): void                       | interface | Yes|
| getDeviceInfo(networkId: string): Promise&lt;DeviceInfo&gt;                                            | interface | Yes|
| startDeviceDiscovery(subscribeInfo: SubscribeInfo): void                                               | interface | Yes|
| startDeviceDiscovery(subscribeInfo: SubscribeInfo, filterOptions?: string): void                       | interface | Yes|
| stopDeviceDiscovery(subscribeId: number): void                                                         | interface | Yes|
| publishDeviceDiscovery(publishInfo: PublishInfo): void                                                 | interface | Yes|
| unPublishDeviceDiscovery(publishId: number): void                                                      | interface | Yes|
| authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback&lt;{deviceId: string, pinToken ?: number}&gt;): void   |interface | Yes|
| unAuthenticateDevice(deviceInfo: DeviceInfo): void                                                     | interface | Yes|
| verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback&lt;{deviceId: string, level: number}&gt;): void          | interface | Yes|
| setUserOperation(operateAction: number, params: string): void                                          | interface | Yes|
| requestCredentialRegisterInfo(requestInfo: string, callback: AsyncCallback&lt;{registerInfo: string}&gt;): void;    | interface | Yes|
| importCredential(credentialInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void;                | interface | Yes|
| deleteCredential(queryInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void;                     | interface | Yes|
| on(type: 'uiStateChange', callback: Callback&lt;{ param: string}&gt;): void;                                        | interface | Yes|
| off(type: 'uiStateChange', callback?: Callback&lt;{ param: string}&gt;): void;                                      | interface | Yes|
| on(type: 'deviceStateChange',  callback: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void                   | interface | Yes|
| off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void                  | interface | Yes|
| on(type: 'deviceFound', callback: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void                                      | interface | Yes|
| off(type: 'deviceFound', callback?: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void                                    | interface | Yes|
| on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void                                         | interface | Yes|
| off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void                                       | interface | Yes|
| on(type: 'publishSuccess', callback: Callback&lt;{ publishId: number }&gt;): void                                                         | interface | Yes|
| off(type: 'publishSuccess', callback?: Callback&lt;{ publishId: number }&gt;): void                                                       | interface | Yes|
| on(type: 'publishFail', callback: Callback&lt;{ publishId: number, reason: number }&gt;): void                                            | interface | Yes|
| off(type: 'publishFail', callback?: Callback&lt;{ publishId: number, reason: number }&gt;): void                                          | interface | Yes|
| on(type: 'serviceDie', callback: () =&gt; void): void                                                    | interface | Yes|
| off(type: 'serviceDie', callback?: () =&gt; void): void                                                  | interface | Yes|

**Adaptation Guide**

The caller must be a system application or an application with the system API permission.
