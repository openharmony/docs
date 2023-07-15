| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Module name: ohos.distributedHardware.deviceManager<br>Class name: DeviceInfo<br>Method or attribute name: range: number;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Class name: DeviceInfo<br>Method or attribute name: range: number;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Module name: ohos.distributedHardware.deviceManager<br>Class name: PublishInfo|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Class name: PublishInfo<br>Method or attribute name: |@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Module name: ohos.distributedHardware.deviceManager<br>Class name: PublishInfo<br>Method or attribute name: publishId: number;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Class name: PublishInfo<br>Method or attribute name: publishId: number;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Module name: ohos.distributedHardware.deviceManager<br>Class name: PublishInfo<br>Method or attribute name: mode: DiscoverMode;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Class name: PublishInfo<br>Method or attribute name: mode: DiscoverMode;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Module name: ohos.distributedHardware.deviceManager<br>Class name: PublishInfo<br>Method or attribute name: freq: ExchangeFreq;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Class name: PublishInfo<br>Method or attribute name: freq: ExchangeFreq;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Module name: ohos.distributedHardware.deviceManager<br>Class name: PublishInfo<br>Method or attribute name: ranging : boolean;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Class name: PublishInfo<br>Method or attribute name: ranging : boolean;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Class name: DeviceManager<br>Method or attribute name: startDeviceDiscovery(subscribeInfo: SubscribeInfo, filterOptions?: string): void;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Class name: DeviceManager<br>Method or attribute name: publishDeviceDiscovery(publishInfo: PublishInfo): void;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Class name: DeviceManager<br>Method or attribute name: unPublishDeviceDiscovery(publishId: number): void;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Class name: DeviceManager<br>Method or attribute name: setUserOperation(operateAction: number, params: string): void;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Class name: DeviceManager<br>Method or attribute name: on(type: 'uiStateChange', callback: Callback\<{ param: string}>): void;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Class name: DeviceManager<br>Method or attribute name: off(type: 'uiStateChange', callback?: Callback\<{ param: string}>): void;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Class name: DeviceManager<br>Method or attribute name: on(type: 'publishSuccess', callback: Callback\<{ publishId: number }>): void;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Class name: DeviceManager<br>Method or attribute name: off(type: 'publishSuccess', callback?: Callback\<{ publishId: number }>): void;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Class name: DeviceManager<br>Method or attribute name: on(type: 'publishFail', callback: Callback\<{ publishId: number, reason: number }>): void;|@ohos.distributedHardware.deviceManager.d.ts|
|Added|NA|Class name: DeviceManager<br>Method or attribute name: off(type: 'publishFail', callback?: Callback\<{ publishId: number, reason: number }>): void;|@ohos.distributedHardware.deviceManager.d.ts|
|Access level changed|Class name: DeviceType<br>Access level: public API|Class name: DeviceType<br>Access level: system API|@ohos.distributedHardware.deviceManager.d.ts|
|Initial version changed|Class name: DeviceManager<br>Method or attribute name: startDeviceDiscovery(subscribeInfo: SubscribeInfo): void;<br>Initial version: N/A|Class name: DeviceManager<br>Method or attribute name: startDeviceDiscovery(subscribeInfo: SubscribeInfo): void;<br>Initial version: 8|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: deviceManager<br>Method or attribute name: function createDeviceManager(bundleName: string, callback: AsyncCallback\<DeviceManager>): void;<br>Error code: 401|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: release(): void;<br>Error code: 11600101|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: getTrustedDeviceListSync(): Array\<DeviceInfo>;<br>Error code: 401, 11600101|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: getTrustedDeviceList(callback:AsyncCallback\<Array\<DeviceInfo>>): void;<br>Error code: 401|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: getTrustedDeviceList(): Promise\<Array\<DeviceInfo>>;<br>Error code: 401|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: getLocalDeviceInfoSync(): DeviceInfo;<br>Error code: 401, 11600101|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: getLocalDeviceInfo(callback:AsyncCallback\<DeviceInfo>): void;<br>Error code: 401|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: getLocalDeviceInfo(): Promise\<DeviceInfo>;<br>Error code: 401|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: startDeviceDiscovery(subscribeInfo: SubscribeInfo): void;<br>Error code: 401, 201, 11600104, 11600101|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: stopDeviceDiscovery(subscribeId: number): void;<br>Error code: 401, 201, 11600101|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: unAuthenticateDevice(deviceInfo: DeviceInfo): void<br>Error code: 401, 201, 11600101|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback\<{deviceId: string, level: number}>): void;<br>Error code: 401|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: on(type: 'deviceStateChange', callback: Callback\<{ action: DeviceStateChangeAction, device: DeviceInfo }>): void;<br>Error code: 401|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: off(type: 'deviceStateChange', callback?: Callback\<{ action: DeviceStateChangeAction, device: DeviceInfo }>): void;<br>Error code: 401|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: on(type: 'deviceFound', callback: Callback\<{ subscribeId: number, device: DeviceInfo }>): void;<br>Error code: 401|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: off(type: 'deviceFound', callback?: Callback\<{ subscribeId: number, device: DeviceInfo }>): void;<br>Error code: 401|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: on(type: 'discoverFail', callback: Callback\<{ subscribeId: number, reason: number }>): void;<br>Error code: 401|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: off(type: 'discoverFail', callback?: Callback\<{ subscribeId: number, reason: number }>): void;<br>Error code: 401|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: on(type: 'serviceDie', callback: () => void): void;<br>Error code: 401|@ohos.distributedHardware.deviceManager.d.ts|
|Error code added|NA|Class name: DeviceManager<br>Method or attribute name: off(type: 'serviceDie', callback?: () => void): void;<br>Error code: 401|@ohos.distributedHardware.deviceManager.d.ts|
|Function changed|Class name: DeviceManager<br>Method or attribute name: authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback\<{deviceId: string, pinTone ?: number}>): void;<br>|Class name: DeviceManager<br>Method or attribute name: authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback\<{deviceId: string, pinToken ?: number}>): void;<br>|@ohos.distributedHardware.deviceManager.d.ts|
