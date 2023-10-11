# 设备管理 JS API 变更 Changelog

从OpenHarmony 4.1.2.3版本开始，设备管理模块能力更新至新模块[@ohos.distributedDeviceManager](js-apis-distributedDeviceManager.md)，本模块中接口全部废弃。

**关键的接口/组件变更**

| 模块名                 | 类名                    | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **method** createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **interface** DeviceInfo | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **enum** DeviceType | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **enum** AuthForm | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **enum** DeviceStateChangeAction | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **interface** SubscribeInfo | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **enum** DiscoverMode | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **enum** ExchangeMedium | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **enum** ExchangeFreq | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **enum** SubscribeCap | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **interface** AuthParam | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **interface** AuthInfo | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | deviceManager        | **interface** PublishInfo | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** release(): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** getTrustedDeviceListSync(): Array&lt;DeviceInfo&gt; |接口废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** getTrustedDeviceListSync(isRefresh: boolean): Array&lt;DeviceInfo&gt;; | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** getTrustedDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceInfo&gt;&gt;): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** getTrustedDeviceList(): Promise&lt;Array&lt;DeviceInfo&gt;&gt; | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** getLocalDeviceInfoSync(): DeviceInfo | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** getLocalDeviceInfo(callback:AsyncCallback&lt;DeviceInfo&gt;): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** getLocalDeviceInfo(): Promise&lt;DeviceInfo&gt; | 废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** getDeviceInfo(networkId: string, callback:AsyncCallback&lt;DeviceInfo&gt;): void | 接口废弃   |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** getDeviceInfo(networkId: string): Promise&lt;DeviceInfo&gt; | 接口废弃   |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** startDeviceDiscovery(subscribeInfo: SubscribeInfo): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** startDeviceDiscovery(subscribeInfo: SubscribeInfo, filterOptions?: string): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** stopDeviceDiscovery(subscribeId: number): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** publishDeviceDiscovery(publishInfo: PublishInfo): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager        | DeviceManager        | **method** unPublishDeviceDiscovery(publishId: number): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager        | DeviceManager        | **method** authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback&lt;{deviceId: string, pinToken ?: number}&gt;): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** unAuthenticateDevice(deviceInfo: DeviceInfo): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback&lt;{deviceId: string, level: number}&gt;): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** setUserOperation(operateAction: number, params: string): void | 接口废弃   |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** requestCredentialRegisterInfo(requestInfo: string, callback: AsyncCallback&lt;{registerInfo: string}&gt;): void; | 接口废弃   |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** importCredential(credentialInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void; | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** deleteCredential(queryInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void; | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** on(type: 'uiStateChange', callback: Callback&lt;{ param: string}&gt;): void; | 接口废弃    |
| @ohos.distributedHardware.deviceManager       | DeviceManager        | **method** off(type: 'uiStateChange', callback?: Callback&lt;{ param: string}&gt;): void; | 接口废弃    |
| @ohos.distributedHardware.deviceManager        | DeviceManager        | **method** on(type: 'deviceStateChange',  callback: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager        | DeviceManager        | **method** off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager        | DeviceManager        | **method** on(type: 'deviceFound', callback: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager        | DeviceManager        | **method** off(type: 'deviceFound', callback?: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager        | DeviceManager        | **method** on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager        | DeviceManager        | **method** off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager        | DeviceManager        | **method** on(type: 'publishSuccess', callback: Callback&lt;{ publishId: number }&gt;): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager        | DeviceManager        | **method** off(type: 'publishSuccess', callback?: Callback&lt;{ publishId: number }&gt;): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager        | DeviceManager        | **method** on(type: 'publishFail', callback: Callback&lt;{ publishId: number, reason: number }&gt;): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager        | DeviceManager        | **method** off(type: 'publishFail', callback?: Callback&lt;{ publishId: number, reason: number }&gt;): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager        | DeviceManager        | **method** on(type: 'serviceDie', callback: () =&gt; void): void | 接口废弃    |
| @ohos.distributedHardware.deviceManager        | DeviceManager        | **method** off(type: 'serviceDie', callback?: () =&gt; void): void | 接口废弃    |

**适配指导**

开发者需要关注变更的接口的适配。
