# 设备管理 JS API 变更 Changelog

从OpenHarmony 4.1.2.3版本开始，设备管理模块能力更新至新模块[@ohos.distributedDeviceManager](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md)，本模块中接口全部废弃。

**关键的接口/组件变更**

| 类名 | 接口类型 | 接口声明 | 变更类型 |
| -- | -- | -- | -- |
| deviceManager | method | function createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void | 接口废弃 |
| DeviceManager | method | function release(): void | 接口废弃 |
| DeviceManager | method | function getTrustedDeviceListSync(): Array&lt;DeviceInfo&gt; |接口废弃 |
| DeviceManager | method | function getTrustedDeviceListSync(isRefresh: boolean): Array&lt;DeviceInfo&gt;; | 接口废弃 |
| DeviceManager | method | function getTrustedDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceInfo&gt;&gt;): void | 接口废弃 |
| DeviceManager | method | function getTrustedDeviceList(): Promise&lt;Array&lt;DeviceInfo&gt;&gt; | 接口废弃 |
| DeviceManager | method | function getLocalDeviceInfoSync(): DeviceInfo | 接口废弃 |
| DeviceManager | method | function getLocalDeviceInfo(callback:AsyncCallback&lt;DeviceInfo&gt;): void | 接口废弃 |
| DeviceManager | method | function getLocalDeviceInfo(): Promise&lt;DeviceInfo&gt; | 废弃 |
| DeviceManager | method | function getDeviceInfo(networkId: string, callback:AsyncCallback&lt;DeviceInfo&gt;): void | 接口废弃 |
| DeviceManager | method | function getDeviceInfo(networkId: string): Promise&lt;DeviceInfo&gt; | 接口废弃 |
| DeviceManager | method | function startDeviceDiscovery(subscribeInfo: SubscribeInfo): void | 接口废弃 |
| DeviceManager | method | function startDeviceDiscovery(subscribeInfo: SubscribeInfo, filterOptions?: string): void | 接口废弃 |
| DeviceManager | method | function stopDeviceDiscovery(subscribeId: number): void | 接口废弃 |
| DeviceManager | method | function publishDeviceDiscovery(publishInfo: PublishInfo): void | 接口废弃 |
| DeviceManager | method | function unPublishDeviceDiscovery(publishId: number): void | 接口废弃 |
| DeviceManager | method | function authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback&lt;{deviceId: string, pinToken ?: number}&gt;): void | 接口废弃 |
| DeviceManager | method | function unAuthenticateDevice(deviceInfo: DeviceInfo): void | 接口废弃 |
| DeviceManager | method | function verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback&lt;{deviceId: string, level: number}&gt;): void | 接口废弃 |
| DeviceManager | method | function setUserOperation(operateAction: number, params: string): void | 接口废弃 |
| DeviceManager | method | function requestCredentialRegisterInfo(requestInfo: string, callback: AsyncCallback&lt;{registerInfo: string}&gt;): void; | 接口废弃 |
| DeviceManager | method | function importCredential(credentialInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void; | 接口废弃 |
| DeviceManager | method | function deleteCredential(queryInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void; | 接口废弃 |
| DeviceManager | method | function on(type: 'uiStateChange', callback: Callback&lt;{ param: string}&gt;): void; | 接口废弃 |
| DeviceManager | method | function off(type: 'uiStateChange', callback?: Callback&lt;{ param: string}&gt;): void; | 接口废弃 |
| DeviceManager | method | function on(type: 'deviceStateChange',  callback: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void | 接口废弃 |
| DeviceManager | method | function off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void | 接口废弃 |
| DeviceManager | method | function on(type: 'deviceFound', callback: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void | 接口废弃 |
| DeviceManager | method | function off(type: 'deviceFound', callback?: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void | 接口废弃 |
| DeviceManager | method | function on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void | 接口废弃 |
| DeviceManager | method | function off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void | 接口废弃 |
| DeviceManager | method | function on(type: 'publishSuccess', callback: Callback&lt;{ publishId: number }&gt;): void | 接口废弃 |
| DeviceManager | method | function off(type: 'publishSuccess', callback?: Callback&lt;{ publishId: number }&gt;): void | 接口废弃 |
| DeviceManager | method | function on(type: 'publishFail', callback: Callback&lt;{ publishId: number, reason: number }&gt;): void | 接口废弃 |
| DeviceManager | method | function off(type: 'publishFail', callback?: Callback&lt;{ publishId: number, reason: number }&gt;): void | 接口废弃 |
| DeviceManager | method | function on(type: 'serviceDie', callback: () =&gt; void): void | 接口废弃 |
| DeviceManager | method | function off(type: 'serviceDie', callback?: () =&gt; void): void | 接口废弃 |
| deviceManager | interface | DeviceInfo | 接口废弃 |
| deviceManager | interface | SubscribeInfo | 接口废弃 |
| deviceManager | interface | AuthParam | 接口废弃 |
| deviceManager | interface | AuthInfo | 接口废弃 |
| deviceManager | interface | PublishInfo | 接口废弃 |
| deviceManager | enum | DeviceType | 接口废弃 |
| deviceManager | enum | AuthForm | 接口废弃 |
| deviceManager | enum | DeviceStateChangeAction | 接口废弃 |
| deviceManager | enum | DiscoverMode | 接口废弃 |
| deviceManager | enum | ExchangeMedium | 接口废弃 |
| deviceManager | enum | ExchangeFreq | 接口废弃 |
| deviceManager | enum | SubscribeCap | 接口废弃 |

**适配指导**

开发者需要关注变更的接口的适配。
