# Distributed Device Management Subsystem Changelog

## c1.device_manager.1 Deprecation of APIs

**Access Level**

Before the change, the APIs are system interfaces and can be called only by system applications.

**Reason for Change**

The APIs need to be open to third-party applications. The new APIs incorporate complete functions of the old system interfaces and are more standard and atomic, with full compliance with community API specifications.

**Change Impact**

The change is not compatible with earlier versions. You are advised to use new APIs.

**Valid Since**

OpenHarmony SDK 4.1.2.3

**Deprecated APIs**

| API| Description| Substitute API|
| -- | -- | -- |
| function createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void | Use [deviceManager.createDeviceManager](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#devicemanagercreatedevicemanager) to create a **DeviceManager** instance.| function createDeviceManager(bundleName: string): DeviceManager; |
| function release(): void | Use [deviceManager.releaseDeviceManager](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#devicemanagerreleasedevicemanager) to release a **DeviceManager** instance.| function releaseDeviceManager(deviceManager: DeviceManager): void; |
| function getTrustedDeviceListSync(): Array&lt;DeviceInfo&gt; | Use [getAvailableDeviceListSync](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getavailabledevicelistsync) to obtain all trusted devices. This API returns the result synchronously.| function getAvailableDeviceListSync(): Array&lt;DeviceBasicInfo&gt;; |
| function getTrustedDeviceListSync(isRefresh: boolean): Array&lt;DeviceInfo&gt;; | Deprecated| N/A|
| function getTrustedDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceInfo&gt;&gt;): void | Use [getAvailableDeviceList](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getavailabledevicelist) to obtain all trusted devices. This API uses an asynchronous callback to return the result.| function getAvailableDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceBasicInfo&gt;&gt;): void; |
| function getTrustedDeviceList(): Promise&lt;Array&lt;DeviceInfo&gt;&gt; | Use [getAvailableDeviceList](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getavailabledevicelist-1) to obtain all trusted devices. This API uses a promise to return the result.| function getAvailableDeviceList(): Promise&lt;Array&lt;DeviceBasicInfo&gt;&gt;; |
| function getLocalDeviceInfoSync(): DeviceInfo | Use [getLocalDeviceNetworkId](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicenetworkid) to obtain the network ID of the local device.<br> Use [getLocalDeviceName](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicename) to obtain the name of the local device.<br> Use [getLocalDeviceType](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicetype) to obtain the type of the local device.<br> Use [getLocalDeviceId](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldeviceid) to obtain the ID of the local device.| function getLocalDeviceNetworkId(): string; <br> function getLocalDeviceName(): string; <br> function getLocalDeviceType(): number; <br> function getLocalDeviceId(): string; |
| function getLocalDeviceInfo(callback:AsyncCallback&lt;DeviceInfo&gt;): void | Use [getLocalDeviceNetworkId](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicenetworkid) to obtain the network ID of the local device.<br> Use [getLocalDeviceName](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicename) to obtain the name of the local device.<br> Use [getLocalDeviceType](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicetype) to obtain the type of the local device.<br> Use [getLocalDeviceId](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldeviceid) to obtain the ID of the local device.| function getLocalDeviceNetworkId(): string; <br> function getLocalDeviceName(): string; <br> function getLocalDeviceType(): number; <br> function getLocalDeviceId(): string; |
| function getLocalDeviceInfo(): Promise&lt;DeviceInfo&gt; | Use [getLocalDeviceNetworkId](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicenetworkid) to obtain the network ID of the local device.<br> Use [getLocalDeviceName](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicename) to obtain the name of the local device.<br> Use [getLocalDeviceType](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldevicetype) to obtain the type of the local device.<br> Use [getLocalDeviceId](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getlocaldeviceid) to obtain the ID of the local device.| function getLocalDeviceNetworkId(): string; <br> function getLocalDeviceName(): string; <br> function getLocalDeviceType(): number; <br> function getLocalDeviceId(): string; |
| function getDeviceInfo(networkId: string, callback:AsyncCallback&lt;DeviceInfo&gt;): void | Use [getDeviceName](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getdevicename) to obtain the device name based on a network ID.<br> Use [getDeviceType](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getdevicetype) to obtain the device type based on a network ID.| function getDeviceName(networkId: string): string; <br> function getDeviceType(networkId: string): number; |
| function getDeviceInfo(networkId: string): Promise&lt;DeviceInfo&gt; | Use [getDeviceName](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getdevicename) to obtain the device name based on a network ID.<br> Use [getDeviceType](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#getdevicetype) to obtain the device type based on a network ID.| function getDeviceName(networkId: string): string; <br> function getDeviceType(networkId: string): number; |
| function startDeviceDiscovery(subscribeInfo: SubscribeInfo): void | Use [startDiscovering](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#startdiscovering) to discover devices nearby.| function startDiscovering(discoverParam: {[key:&nbsp;string]:&nbsp;Object} , filterOptions?: {[key:&nbsp;string]:&nbsp;Object} ): void; |
| function startDeviceDiscovery(subscribeInfo: SubscribeInfo, filterOptions?: string): void | Use [startDiscovering](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#startdiscovering) to discover devices nearby.| function startDiscovering(discoverParam: {[key:&nbsp;string]:&nbsp;Object} , filterOptions?: {[key:&nbsp;string]:&nbsp;Object} ): void; |
| function stopDeviceDiscovery(subscribeId: number): void | Use [stopDiscovering](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#stopdiscovering) to stop discovering nearby devices.| function stopDiscovering(): void; |
| function publishDeviceDiscovery(publishInfo: PublishInfo): void | Deprecated| N/A|
| function unPublishDeviceDiscovery(publishId: number): void | Deprecated| N/A|
| function authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback&lt;{deviceId: string, pinToken ?: number}&gt;): void | Use [bindTarget](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#bindtarget) to bind a device.| function bindTarget(deviceId: string, bindParam: {[key:&nbsp;string]:&nbsp;Object} , callback: AsyncCallback&lt;{deviceId: string}>): void; |
| function unAuthenticateDevice(deviceInfo: DeviceInfo): void | Use [unbindTarget](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#unbindtarget) to unbind a device.| function unbindTarget(deviceId: string): void; |
| function verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback&lt;{deviceId: string, level: number}&gt;): void | Deprecated| N/A|
| function setUserOperation(operateAction: number, params: string): void | Use [replyUiAction](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#replyuiaction) to reply to the user's UI operation behavior.| function replyUiAction(action: number, actionResult: string): void; |
| function requestCredentialRegisterInfo(requestInfo: string, callback: AsyncCallback&lt;{registerInfo: string}&gt;): void; | Deprecated| N/A|
| function importCredential(credentialInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void; | Deprecated| N/A|
| function deleteCredential(queryInfo: string, callback: AsyncCallback&lt;{resultInfo: string}&gt;): void; | Deprecated| N/A|
| function on(type: 'uiStateChange', callback: Callback&lt;{ param: string}&gt;): void; | Use [on('replyResult')](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#onreplyresult) to subscribe to the UI operation reply result.| function on(type: 'replyResult', callback: Callback&lt;{ param: string}&gt;): void; |
| function off(type: 'uiStateChange', callback?: Callback&lt;{ param: string}&gt;): void; | Use [off('replyResult')](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#offreplyresult) to unsubscribe from the UI operation reply result.| function off(type: 'replyResult', callback?: Callback&lt;{ param: string}&gt;): void; |
| function on(type: 'deviceStateChange',  callback: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void | Use [on('deviceStateChange')](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#ondevicestatechange) to subscribe to device state changes.| function on(type: 'deviceStateChange', callback: Callback&lt;{ action: DeviceStateChange, device: DeviceBasicInfo }&gt;): void; |
| function off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void | Use [off('deviceStateChange')](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#offdevicestatechange) to unsubscribe from device state changes.| function off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChange, device: DeviceBasicInfo }&gt;): void; |
| function on(type: 'deviceFound', callback: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void | Use [on('discoverSuccess')](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#ondiscoversuccess) to subscribe to successful discovery of devices.| function on(type: 'discoverSuccess', callback: Callback&lt;{ device: DeviceBasicInfo }&gt;): void; |
| function off(type: 'deviceFound', callback?: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void | Use [off('discoverSuccess')](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#offdiscoversuccess) to unsubscribe from successful discovery of devices.| function off(type: 'discoverSuccess', callback?: Callback&lt;{ device: DeviceBasicInfo }&gt;): void; |
| function on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void | Use [on('discoverFailure')](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#ondiscoverfailure) to subscribe to failed discovery of devices.| function on(type: 'discoverFailure', callback: Callback&lt;{ reason: number }&gt;): void; |
| function off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void | Use [off('discoverFailure')](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#offdiscoverfailure) to unsubscribe from failed discovery of devices.| function off(type: 'discoverFailure', callback?: Callback&lt;{ reason: number }&gt;): void; |
| function on(type: 'publishSuccess', callback: Callback&lt;{ publishId: number }&gt;): void |  Deprecated| N/A|
| function off(type: 'publishSuccess', callback?: Callback&lt;{ publishId: number }&gt;): void |  Deprecated| N/A|
| function on(type: 'publishFail', callback: Callback&lt;{ publishId: number, reason: number }&gt;): void |  Deprecated| N/A|
| function off(type: 'publishFail', callback?: Callback&lt;{ publishId: number, reason: number }&gt;): void |  Deprecated| N/A|
| function on(type: 'serviceDie', callback: () =&gt; void): void | Use [on('serviceDie')](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#onservicedie) to subscribe to unexpected termination of the DeviceManager service.| function on(type: 'serviceDie', callback?: Callback&lt;{}&gt;): void; |
| function off(type: 'serviceDie', callback?: () =&gt; void): void | Use [off('serviceDie')](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#offservicedie) to unsubscribe from unexpected termination of the DeviceManager service.| function off(type: 'serviceDie', callback?: Callback&lt;{}&gt;): void; |
| interface DeviceInfo | Use [DeviceBasicInfo](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#devicebasicinfo) to represent the basic information about a distributed device.| interface DeviceBasicInfo |
| interface SubscribeInfo | Deprecated| N/A|
| interface AuthParam | Deprecated| N/A|
| interface AuthInfo | Deprecated| N/A|
| interface PublishInfo | Deprecated| N/A|
| enum DeviceType | Deprecated| N/A|
| enum AuthForm | Deprecated| N/A|
| enum DeviceStateChangeAction | Use [DeviceStateChange](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md#devicestatechange) to enumerate device states.| enum DeviceStateChange |
| enum DiscoverMode | Deprecated| N/A|
| enum ExchangeMedium | Deprecated| N/A|
| enum ExchangeFreq | Deprecated| N/A|
| enum SubscribeCap | Deprecated| N/A|

**Adaptation Guide**

You are advised to use [@ohos.distributedDeviceManager](../../../application-dev/reference/apis/js-apis-distributedDeviceManager.md).
