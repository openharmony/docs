# Network Sharing (For System Applications Only)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=742fd8e7f742ee980eb300ddfd075065ca362dff translatedAt=2026-08-13T03:09:02.389Z pushedAt=2026-08-13T06:39:53.673Z -->

## Overview

The Network Sharing module allows you to share your device's Internet connection with other connected devices by means of Wi-Fi hotspot, Bluetooth, and USB sharing. It also allows you to query the network sharing state and shared mobile data volume.

> **NOTE**
> To ensure app running efficiency, most API calls are asynchronous. For asynchronous APIs, both callback and Promise modes are provided. The following examples use promise functions. For more modes, see [@ohos.net.sharing (Network Sharing Management)](../reference/apis-network-kit/js-apis-net-sharing-sys.md).

## Basic Concepts

- Wi-Fi sharing: Shares the network through a Wi-Fi hotspot.

- Bluetooth sharing: Shares the network through Bluetooth.

- USB tethering: Shares the network using a USB flash drive.

## Constraint

- Programming language: JS

- The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## When to Use

Typical network sharing scenarios are as follows:

- Enabling network sharing

- Disabling network sharing

- Obtaining the data traffic of the shared network

The following describes the development procedure specific to each application scenario.

## Available APIs

For the complete list of APIs and example code, see [Network Sharing](../reference/apis-network-kit/js-apis-net-sharing-sys.md).

| Name                                                                  | Description                                                                                                   |
| --------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------- |
| isSharingSupported(callback: AsyncCallback\<boolean>): void;    | Checks whether the system supports network sharing. This API uses an asynchronous callback to return the result.                                                      |
| isSharing(callback: AsyncCallback\<boolean>): void;             | Checks whether network sharing is active. This API uses an asynchronous callback to return the result.                                                                  |
| startSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;  | Starts sharing. The parameter **type** indicates the sharing type, which currently supports Wi-Fi hotspot, Bluetooth, and USB. This API uses an asynchronous callback to return the result.                |
| stopSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;  | Stops sharing of the specified type. The parameter **type** indicates the sharing type, including Wi-Fi hotspot, Bluetooth, and USB. This API uses an asynchronous callback to return the result.             |
| getStatsRxBytes(callback: AsyncCallback\<number>): void;         | Obtains the received data traffic during network sharing, in KB. This API uses an asynchronous callback to return the result.                                                       |
| getStatsTxBytes(callback: AsyncCallback\<number>): void;         | Obtains the sent data traffic during network sharing, in KB. This API uses an asynchronous callback to return the result.                                                       |
| getStatsTotalBytes(callback: AsyncCallback\<number>): void;      | Obtains the total data traffic during network sharing, in KB. This API uses an asynchronous callback to return the result.                                                       |
| getSharingIfaces(state: SharingIfaceState, callback: AsyncCallback\<Array\<string>>): void;  | Obtains the names of network interface cards (NICs) in the specified network sharing state. This API uses an asynchronous callback to return the result.|
| getSharingState(type: SharingIfaceType, callback: AsyncCallback\<SharingIfaceState>): void;  | Obtains the sharing state of the specified type. The parameter **type** indicates the type, which currently supports Wi-Fi hotspot, Bluetooth, and USB. This API uses an asynchronous callback to return the result.  |
| getSharableRegexes(type: SharingIfaceType, callback: AsyncCallback\<Array\<string>>): void;  | Obtains the list of NIC regular expressions that match the specified type. The parameter **type** indicates the type, which currently supports Wi-Fi hotspot, Bluetooth, and USB. This API uses an asynchronous callback to return the result. |
| on(type: 'sharingStateChange', callback: Callback\<boolean>): void;        | Subscribes to network sharing state changes.                                                               |
| off(type: 'sharingStateChange', callback?: Callback\<boolean>): void;      | Unsubscribes from network sharing state changes.                                                               |
| function on(type: 'interfaceSharingStateChange', callback: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;    | Subscribes to network sharing state changes of the specified NIC.   |
| off(type: 'interfaceSharingStateChange', callback?: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void; | Unsubscribes from network sharing state changes of the specified NIC.            |
| on(type: 'sharingUpstreamChange', callback: Callback\<NetHandle>): void;               | Subscribes to upstream NIC changes.                                                                        |
| off(type: 'sharingUpstreamChange', callback?: Callback\<NetHandle>): void;             | Unsubscribes from upstream NIC changes.                                                                        |

## Enabling network sharing

1. Import the **sharing** namespace from **@kit.NetworkKit**.

2. Subscribe to network sharing state changes.

3. Call **startSharing** to start network sharing of the specified type.

4. Return the callback for successfully starting network sharing.

```ts
// Import the sharing namespace from @kit.NetworkKit.
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Subscribe to network sharing state changes.
sharing.on('sharingStateChange', (data: boolean) => {
  console.info(JSON.stringify(data));
});

// Call startSharing to start network sharing of the specified type.
sharing.startSharing(sharing.SharingIfaceType.SHARING_WIFI).then(() => {
  console.info('start wifi sharing successful');
}).catch((error: BusinessError) => {
  console.error('start wifi sharing failed');
});
```

## Disabling Network Sharing

### How to Develop

1. Import the **sharing** namespace from **@kit.NetworkKit**.

2. Subscribe to network sharing state changes.

3. Call **stopSharing** to stop network sharing of the specified type.

4. Return the callback for successfully stopping network sharing.

```ts
// Import the sharing namespace from @kit.NetworkKit.
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Subscribe to network sharing state changes.
sharing.on('sharingStateChange', (data: boolean) => {
  console.info(JSON.stringify(data));
});

// Call stopSharing to stop network sharing of the specified type.
sharing.stopSharing(sharing.SharingIfaceType.SHARING_WIFI).then(() => {
  console.info('stop wifi sharing successful');
}).catch((error: BusinessError) => {
  console.error('start wifi sharing failed');
});
```

## Obtaining the Data Traffic of the Shared Network

### How to Develop

1. Import the **sharing** namespace from **@kit.NetworkKit**.

2. Call **startSharing** to start network sharing of the specified type.

3. Call **getStatsTotalBytes** to obtain the data traffic generated during data sharing.

4. Call **stopSharing** to stop network sharing of the specified type and clear the data volume of network sharing.

```ts
// Import the sharing namespace from @kit.NetworkKit.
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Call startSharing to start network sharing of the specified type.
sharing.startSharing(sharing.SharingIfaceType.SHARING_WIFI).then(() => {
  console.info('start wifi sharing successful');
}).catch((error: BusinessError) => {
  console.error('start wifi sharing failed');
});

// Call getStatsTotalBytes to obtain the data traffic generated during data sharing.
sharing.getStatsTotalBytes().then((data: number) => {
  console.info(JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.error(JSON.stringify(error));
});

// Call stopSharing to stop network sharing of the specified type and clear the data volume of network sharing.
sharing.stopSharing(sharing.SharingIfaceType.SHARING_WIFI).then(() => {
  console.info('stop wifi sharing successful');
}).catch((error: BusinessError) => {
  console.error('start wifi sharing failed');
});

// Call getStatsTotalBytes again. The data volume of network sharing has been cleared.
sharing.getStatsTotalBytes().then((data: number) => {
  console.info(JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```