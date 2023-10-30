# Device Management JS API Changelog

From OpenHarmony 4.1.2.3, all the APIs of the **deviceManager** module are deprecated. You are advised to use [@ohos.distributedDeviceManager](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md).

**Key API/Component Changes**

| Class| Interface Type| Declaration| Change Type|
| -- | -- | -- | -- |
| deviceManager | method | function createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void | Deprecated|
| DeviceManager | method | function release(): void | Deprecated|
| DeviceManager | method | function getTrustedDeviceListSync(): Array&lt;DeviceInfo&gt; |Deprecated|
| DeviceManager | method | function getTrustedDeviceListSync(isRefresh: boolean): Array&lt;DeviceInfo&gt;; | Deprecated|
| DeviceManager | method | function getTrustedDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceInfo&gt;&gt;): void | Deprecated|
| DeviceManager | method | function getTrustedDeviceList(): Promise&lt;Array&lt;DeviceInfo&gt;&gt; | Deprecated|
| DeviceManager | method | function getLocalDeviceInfoSync(): DeviceInfo | Deprecated|
| DeviceManager | method | function getLocalDeviceInfo(callback:AsyncCallback&lt;DeviceInfo&gt;): void | Deprecated|
| DeviceManager | method | function getLocalDeviceInfo(): Promise&lt;DeviceInfo&gt; | Deprecated|
| DeviceManager | method | function getDeviceInfo(networkId: string, callback:AsyncCallback&lt;DeviceInfo&gt;): void | Deprecated|
| DeviceManager | method | function getDeviceInfo(networkId: string): Promise&lt;DeviceInfo&gt; | Deprecated|
| DeviceManager | method | function startDeviceDiscovery(subscribeInfo: SubscribeInfo): void | Deprecated|
| DeviceManager | method | function startDeviceDiscovery(subscribeInfo: SubscribeInfo, filterOptions?: string): void | Deprecated|
| DeviceManager | method | function stopDeviceDiscovery(subscribeId: number): void | Deprecated|
| DeviceManager | method | function publishDeviceDiscovery(publishInfo: PublishInfo): void | Deprecated|
| DeviceManager | method | function unPublishDeviceDiscovery(publishId: number): void | Deprecated|
| DeviceManager | method | function authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback&lt;{deviceId: string, pinToken ?: number}&gt;): void | Deprecated|
| DeviceManager | method | function unAuthenticateDevice(deviceInfo: DeviceInfo): void | Deprecated|
| DeviceManager | method | function verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback&lt;{deviceId: string, level: number}&gt;): void | Deprecated|
| DeviceManager | method | function setUserOperation(operateAction: number, params: string): void | Deprecated|
| DeviceManager | method | function requestCredentialRegisterInfo(requestInfo: string, callback: AsyncCallback&lt;{registerInfo: string}&gt;): void; | Deprecated|
| DeviceManager | method | function importCredential(credentialInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void; | Deprecated|
| DeviceManager | method | function deleteCredential(queryInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void; | Deprecated|
| DeviceManager | method | function on(type: 'uiStateChange', callback: Callback&lt;{ param: string}&gt;): void; | Deprecated|
| DeviceManager | method | function off(type: 'uiStateChange', callback?: Callback&lt;{ param: string}&gt;): void; | Deprecated|
| DeviceManager | method | function on(type: 'deviceStateChange',  callback: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void | Deprecated|
| DeviceManager | method | function off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void | Deprecated|
| DeviceManager | method | function on(type: 'deviceFound', callback: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void | Deprecated|
| DeviceManager | method | function off(type: 'deviceFound', callback?: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void | Deprecated|
| DeviceManager | method | function on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void | Deprecated|
| DeviceManager | method | function off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void | Deprecated|
| DeviceManager | method | function on(type: 'publishSuccess', callback: Callback&lt;{ publishId: number }&gt;): void | Deprecated|
| DeviceManager | method | function off(type: 'publishSuccess', callback?: Callback&lt;{ publishId: number }&gt;): void | Deprecated|
| DeviceManager | method | function on(type: 'publishFail', callback: Callback&lt;{ publishId: number, reason: number }&gt;): void | Deprecated|
| DeviceManager | method | function off(type: 'publishFail', callback?: Callback&lt;{ publishId: number, reason: number }&gt;): void | Deprecated|
| DeviceManager | method | function on(type: 'serviceDie', callback: () =&gt; void): void | Deprecated|
| DeviceManager | method | function off(type: 'serviceDie', callback?: () =&gt; void): void | Deprecated|
| deviceManager | interface | DeviceInfo | Deprecated|
| deviceManager | interface | SubscribeInfo | Deprecated|
| deviceManager | interface | AuthParam | Deprecated|
| deviceManager | interface | AuthInfo | Deprecated|
| deviceManager | interface | PublishInfo | Deprecated|
| deviceManager | enum | DeviceType | Deprecated|
| deviceManager | enum | AuthForm | Deprecated|
| deviceManager | enum | DeviceStateChangeAction | Deprecated|
| deviceManager | enum | DiscoverMode | Deprecated|
| deviceManager | enum | ExchangeMedium | Deprecated|
| deviceManager | enum | ExchangeFreq | Deprecated|
| deviceManager | enum | SubscribeCap | Deprecated|

**Adaptation Guide**

You need to adapt the changed interfaces.
