# Device Manager ChangeLog

## cl.device_manager.1 Error Information Return Method Change of APIs

The device manager API uses service logic return values to indicate the error information, which does not comply with the API error code specifications of OpenHarmony. The following changes are made in API version 9 and later:

Asynchronous API: An error message is returned via **AsyncCallback** or the **error** object of **Promise**.

Synchronous API: An error message is returned via an exception.

**Change Impacts**

The application developed based on earlier versions needs to adapt the method for returning API error information. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

Error code processing is added for the following APIs:
  - createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void;
  - release(): void;
  - getTrustedDeviceListSync(): Array&lt;DeviceInfo&gt;
  - getTrustedDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceInfo&gt;&gt;): void;
  - getTrustedDeviceList(): Promise&lt;Array&lt;DeviceInfo&gt;&gt;
  - getLocalDeviceInfoSync(): DeviceInfo;
  - getLocalDeviceInfo(callback:AsyncCallback&lt;DeviceInfo&gt;): void;
  - getLocalDeviceInfo(): Promise&lt;DeviceInfo&gt;
  - startDeviceDiscovery(subscribeInfo: SubscribeInfo): void;
  - startDeviceDiscovery(subscribeInfo: SubscribeInfo, filterOptions?: string): void;
  - stopDeviceDiscovery(subscribeId: number): void;
  - publishDeviceDiscovery(publishInfo: PublishInfo): void;
  - unPublishDeviceDiscovery(publishId: number): void;
  - authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback&lt;{deviceId: string, pinToken ?: number}&gt;): void;
  - unAuthenticateDevice(deviceInfo: DeviceInfo): void;
  - verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback&lt;{deviceId: string, level: number}&gt;): void;
  - setUserOperation(operateAction: number, params: string): void;
  - on(type: 'uiStateChange', callback: Callback&lt;{ param: string}&gt;): void;
  - off(type: 'uiStateChange', callback?: Callback&lt;{ param: string}&gt;): void;
  - on(type: 'deviceStateChange',  callback: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void;
  - off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void;
  - on(type: 'deviceFound', callback: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void;
  - off(type: 'deviceFound', callback?: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void;
  - on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void;
  - off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void;
  - on(type: 'publishSuccess', callback: Callback&lt;{ publishId: number }&gt;): void;
  - off(type: 'publishSuccess', callback?: Callback&lt;{ publishId: number }&gt;): void;
  - on(type: 'publishFail', callback: Callback&lt;{ publishId: number, reason: number }&gt;): void;
  - off(type: 'publishFail', callback?: Callback&lt;{ publishId: number, reason: number }&gt;): void;
  - on(type: 'serviceDie', callback: () =&gt; void): void;
  - off(type: 'serviceDie', callback?: () =&gt; void): void;

**Adaptation Guide**

The following uses **getTrustedDeviceList** as an example for asynchronous APIs:

```ts
import account_osAccount from "@ohos.distributedHardware.deviceManager"
dmInstance.getTrustedDeviceList((err, data) => {
    console.log("getTrustedDeviceList err: " + JSON.stringify(err));
    console.log('get trusted device info: ' + JSON.stringify(data));
});

try {
  dmInstance.getTrustedDeviceList((err, data) => {
    if (err) {
      console.error("getTrustedDeviceList errCode:" + err.code + ",errMessage:" + err.message);
      return;
    }
    console.log('get trusted device info: ' + JSON.stringify(data));
  });
} catch (err) {
  console.error("getTrustedDeviceList errCode:" + err.code + ",errMessage:" + err.message);
}
```

The following uses **startDeviceDiscovery** as an example for synchronous APIs:

```ts
// Automatically generate a unique subscription ID.
var subscribeId = Math.floor(Math.random() * 10000 + 1000);
var subscribeInfo = {
    "subscribeId": subscribeId,
    "mode": 0xAA, // Active discovery
    "medium": 0,  // Automatic. Multiple media can be used for device discovery.
    "freq": 2,    // High frequency
    "isSameAccount": false,
    "isWakeRemote": false,
    "capability": 1
};
dmInstance.startDeviceDiscovery(subscribeInfo); // The deviceFound callback is called to notify the application when a device is discovered.

// Automatically generate a unique subscription ID.
var subscribeId = Math.floor(Math.random() * 10000 + 1000);
var subscribeInfo = {
    "subscribeId": subscribeId,
    "mode": 0xAA, // Active discovery
    "medium": 0,  // Automatic. Multiple media can be used for device discovery.
    "freq": 2, // High frequency
    "isSameAccount": false,
    "isWakeRemote": false,
    "capability": 1
};
try {
  dmInstance.startDeviceDiscovery(subscribeInfo); // The deviceFound callback is called to notify the application when a device is discovered.
} catch (err) {
  console.error("startDeviceDiscovery errCode:" + err.code + ",errMessage:" + err.message);
}
```
