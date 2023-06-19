# Network Sharing

## Introduction

The Network Sharing module allows you to share your device's Internet connection with other connected devices by means of Wi-Fi hotspot, Bluetooth, and USB sharing. It also allows you to query the network sharing state and shared mobile data volume.

> **Note:**
> To maximize the application running efficiency, most API calls are called asynchronously in callback or promise mode. The following code examples use the callback mode. For details about the APIs, see [sms API Reference](../reference/apis/js-apis-net-sharing.md).

## Basic Concepts

- Wi-Fi sharing: Shares the network through a Wi-Fi hotspot.
- Bluetooth sharing: Shares the network through Bluetooth.
- USB tethering: Shares the network using a USB flash drive.

## **Constraints**

- Programming language: C++ and JS
- System: Linux kernel
- The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## When to Use

Typical network sharing scenarios are as follows:

- Enabling Network Sharing
- Disabling network sharing
- Obtaining the data traffic of the shared network

The following describes the development procedure specific to each application scenario.

## Available APIs

For the complete list of APIs and example code, see [Network Sharing](../reference/apis/js-apis-net-sharing.md).

| Type| API| Description|
| ---- | ---- | ---- |
| ohos.net.sharing | function isSharingSupported(callback: AsyncCallback\<boolean>): void; | Checks whether the system supports network sharing. This API uses an asynchronous callback to return the result.|
| ohos.net.sharing | function isSharing(callback: AsyncCallback\<boolean>): void; | Checks whether network sharing is active. This API uses an asynchronous callback to return the result.|
| ohos.net.sharing | function startSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void; | Starts network sharing. This API uses an asynchronous callback to return the result.|
| ohos.net.sharing | function stopSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void; | Stops network sharing. This API uses an asynchronous callback to return the result.|
| ohos.net.sharing | function getStatsRxBytes(callback: AsyncCallback\<number>): void; | Obtains the received data traffic during network sharing, in KB. This API uses an asynchronous callback to return the result.|
| ohos.net.sharing | function getStatsTxBytes(callback: AsyncCallback\<number>): void; | Obtains the sent data traffic during network sharing, in KB. This API uses an asynchronous callback to return the result.|
| ohos.net.sharing | function getStatsTotalBytes(callback: AsyncCallback\<number>): void; | Obtains the total data traffic during network sharing, in KB. This API uses an asynchronous callback to return the result.|
| ohos.net.sharing | function getSharingIfaces(state: SharingIfaceState, callback: AsyncCallback\<Array\<string>>): void; | Obtains the names of network interface cards (NICs) in the specified network sharing state.. This API uses an asynchronous callback to return the result.|
| ohos.net.sharing | function getSharingState(type: SharingIfaceType, callback: AsyncCallback\<SharingIfaceState>): void; | Obtains the network sharing state of the specified type. This API uses an asynchronous callback to return the result.|
| ohos.net.sharing | function getSharableRegexes(type: SharingIfaceType, callback: AsyncCallback\<Array\<string>>): void; | Obtains regular expressions of NICs of a specified type. This API uses an asynchronous callback to return the result.|
| ohos.net.sharing | function on(type: 'sharingStateChange', callback: Callback\<boolean>): void; | Subscribes to network sharing state changes.|
| ohos.net.sharing | function off(type: 'sharingStateChange', callback?: Callback\<boolean>): void; | Unsubscribes from network sharing state changes.|
| ohos.net.sharing | unction on(type: 'interfaceSharingStateChange', callback: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void; | Subscribes to network sharing state changes of the specified NIC.|
| ohos.net.sharing | function off(type: 'interfaceSharingStateChange', callback?: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void; | Unsubscribes from network sharing state changes of the specified NIC.|
| ohos.net.sharing | function on(type: 'sharingUpstreamChange', callback: Callback\<NetHandle>): void; | Subscribes to upstream NIC changes.|
| ohos.net.sharing | function off(type: 'sharingUpstreamChange', callback?: Callback\<NetHandle>): void; | Unsubscribes from upstream NIC changes.|

## Enabling Network Sharing

1. Import the **sharing** namespace from **@ohos.net.sharing**.
2. Subscribe to network sharing state changes.
3. Call **startSharing** to start network sharing of the specified type.
4. Return the callback for successfully starting network sharing.

```js
// Import the sharing namespace from @ohos.net.sharing.
import sharing from '@ohos.net.sharing'

// Subscribe to network sharing state changes.
sharing.on('sharingStateChange', (error, data) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});

// Call startSharing to start network sharing of the specified type.
sharing.startSharing(sharing.SharingIfaceType.SHARING_WIFI, (error) => {
  console.log(JSON.stringify(error));
});
```

## Disabling network sharing

### How to Develop

1. Import the **sharing** namespace from **@ohos.net.sharing**.
2. Subscribe to network sharing state changes.
3. Call **stopSharing** to stop network sharing of the specified type.
4. Return the callback for successfully stopping network sharing.

```js
// Import the sharing namespace from @ohos.net.sharing.
import sharing from '@ohos.net.sharing'

// Subscribe to network sharing state changes.
sharing.on('sharingStateChange', (error, data) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});

// Call stopSharing to stop network sharing of the specified type.
sharing.stopSharing(sharing.SharingIfaceType.SHARING_WIFI, (error) => {
  console.log(JSON.stringify(error));
});
```

## Obtaining the data traffic of the shared network

### How to Develop

1. Import the **sharing** namespace from **@ohos.net.sharing**.
2. Call **startSharing** to start network sharing of the specified type.
3. Call **getStatsTotalBytes** to obtain the data traffic generated during data sharing.
4. Call **stopSharing** to stop network sharing of the specified type and clear the data volume of network sharing.

```js
// Import the sharing namespace from @ohos.net.sharing.
import sharing from '@ohos.net.sharing'

// Call startSharing to start network sharing of the specified type.
sharing.startSharing(sharing.SharingIfaceType.SHARING_WIFI, (error) => {
  console.log(JSON.stringify(error));
});

// Call getStatsTotalBytes to obtain the data traffic generated during data sharing.
sharing.getStatsTotalBytes((error, data) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});

// Call stopSharing to stop network sharing of the specified type and clear the data volume of network sharing.
sharing.stopSharing(sharing.SharingIfaceType.SHARING_WIFI, (error) => {
  console.log(JSON.stringify(error));
});

// Call getStatsTotalBytes again. The data volume of network sharing has been cleared.
sharing.getStatsTotalBytes((error, data) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```
