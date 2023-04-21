| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.distributedHardware.deviceManager<br>类名: DeviceInfo<br>方法 or 属性：range: number;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|类名：DeviceInfo<br>方法or属性：range: number;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|模块名: ohos.distributedHardware.deviceManager<br>类名: PublishInfo|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|类名：PublishInfo<br>方法or属性：|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|模块名: ohos.distributedHardware.deviceManager<br>类名: PublishInfo<br>方法 or 属性：publishId: number;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|类名：PublishInfo<br>方法or属性：publishId: number;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|模块名: ohos.distributedHardware.deviceManager<br>类名: PublishInfo<br>方法 or 属性：mode: DiscoverMode;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|类名：PublishInfo<br>方法or属性：mode: DiscoverMode;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|模块名: ohos.distributedHardware.deviceManager<br>类名: PublishInfo<br>方法 or 属性：freq: ExchangeFreq;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|类名：PublishInfo<br>方法or属性：freq: ExchangeFreq;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|模块名: ohos.distributedHardware.deviceManager<br>类名: PublishInfo<br>方法 or 属性：ranging : boolean;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|类名：PublishInfo<br>方法or属性：ranging : boolean;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|类名：DeviceManager<br>方法or属性：startDeviceDiscovery(subscribeInfo: SubscribeInfo, filterOptions?: string): void;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|类名：DeviceManager<br>方法or属性：publishDeviceDiscovery(publishInfo: PublishInfo): void;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|类名：DeviceManager<br>方法or属性：unPublishDeviceDiscovery(publishId: number): void;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|类名：DeviceManager<br>方法or属性：setUserOperation(operateAction: number, params: string): void;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|类名：DeviceManager<br>方法or属性：on(type: 'uiStateChange', callback: Callback\<{ param: string}>): void;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|类名：DeviceManager<br>方法or属性：off(type: 'uiStateChange', callback?: Callback\<{ param: string}>): void;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|类名：DeviceManager<br>方法or属性：on(type: 'publishSuccess', callback: Callback\<{ publishId: number }>): void;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|类名：DeviceManager<br>方法or属性：off(type: 'publishSuccess', callback?: Callback\<{ publishId: number }>): void;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|类名：DeviceManager<br>方法or属性：on(type: 'publishFail', callback: Callback\<{ publishId: number, reason: number }>): void;|@ohos.distributedHardware.deviceManager.d.ts|
|新增|NA|类名：DeviceManager<br>方法or属性：off(type: 'publishFail', callback?: Callback\<{ publishId: number, reason: number }>): void;|@ohos.distributedHardware.deviceManager.d.ts|
|访问级别有变化|类名：DeviceType<br>访问级别：公开API|类名：DeviceType<br>访问级别：系统API|@ohos.distributedHardware.deviceManager.d.ts|
|起始版本有变化|类名：DeviceManager<br>方法 or 属性：startDeviceDiscovery(subscribeInfo: SubscribeInfo): void;<br>起始版本：N/A|类名：DeviceManager<br>方法 or 属性：startDeviceDiscovery(subscribeInfo: SubscribeInfo): void;<br>起始版本：8|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：deviceManager<br>方法 or 属性：function createDeviceManager(bundleName: string, callback: AsyncCallback\<DeviceManager>): void;<br>错误码内容: 401|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：release(): void;<br>错误码内容: 11600101|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：getTrustedDeviceListSync(): Array\<DeviceInfo>;<br>错误码内容: 401, 11600101|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：getTrustedDeviceList(callback:AsyncCallback\<Array\<DeviceInfo>>): void;<br>错误码内容: 401|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：getTrustedDeviceList(): Promise\<Array\<DeviceInfo>>;<br>错误码内容: 401|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：getLocalDeviceInfoSync(): DeviceInfo;<br>错误码内容: 401, 11600101|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：getLocalDeviceInfo(callback:AsyncCallback\<DeviceInfo>): void;<br>错误码内容: 401|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：getLocalDeviceInfo(): Promise\<DeviceInfo>;<br>错误码内容: 401|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：startDeviceDiscovery(subscribeInfo: SubscribeInfo): void;<br>错误码内容: 401, 201, 11600104, 11600101|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：stopDeviceDiscovery(subscribeId: number): void;<br>错误码内容: 401, 201, 11600101|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：unAuthenticateDevice(deviceInfo: DeviceInfo): void<br>错误码内容: 401, 201, 11600101|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback\<{deviceId: string, level: number}>): void;<br>错误码内容: 401|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：on(type: 'deviceStateChange', callback: Callback\<{ action: DeviceStateChangeAction, device: DeviceInfo }>): void;<br>错误码内容: 401|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：off(type: 'deviceStateChange', callback?: Callback\<{ action: DeviceStateChangeAction, device: DeviceInfo }>): void;<br>错误码内容: 401|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：on(type: 'deviceFound', callback: Callback\<{ subscribeId: number, device: DeviceInfo }>): void;<br>错误码内容: 401|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：off(type: 'deviceFound', callback?: Callback\<{ subscribeId: number, device: DeviceInfo }>): void;<br>错误码内容: 401|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：on(type: 'discoverFail', callback: Callback\<{ subscribeId: number, reason: number }>): void;<br>错误码内容: 401|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：off(type: 'discoverFail', callback?: Callback\<{ subscribeId: number, reason: number }>): void;<br>错误码内容: 401|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：on(type: 'serviceDie', callback: () => void): void;<br>错误码内容: 401|@ohos.distributedHardware.deviceManager.d.ts|
|新增(错误码)|NA|类名：DeviceManager<br>方法 or 属性：off(type: 'serviceDie', callback?: () => void): void;<br>错误码内容: 401|@ohos.distributedHardware.deviceManager.d.ts|
|函数有变化|类名：DeviceManager<br>方法 or 属性：authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback\<{deviceId: string, pinTone ?: number}>): void;<br>|类名：DeviceManager<br>方法 or 属性：authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback\<{deviceId: string, pinToken ?: number}>): void;<br>|@ohos.distributedHardware.deviceManager.d.ts|
