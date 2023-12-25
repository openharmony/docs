# Traffic Management

## Introduction

The traffic management module allows you to query real-time or historical data traffic by the specified network interface card (NIC) or user ID (UID).

Its functions include:

- Obtaining real-time traffic data by NIC or UID
- Obtaining historical traffic data by NIC or UID
- Subscribing to traffic change events by NIC or UID

> **NOTE**
> To maximize the application running efficiency, most API calls are called asynchronously in callback or promise mode. The following code examples use the callback mode. For details about the APIs, see [sms API Reference](../reference/apis/js-apis-net-statistics.md).

The following describes the development procedure specific to each application scenario.

## Available APIs

For the complete list of APIs and example code, see [Traffic Management](../reference/apis/js-apis-net-statistics.md).

| API                                                                                     | Description                        |
| ------------------------------------------------------------------------------------------- | ---------------------------- |
| getIfaceRxBytes(nic: string, callback: AsyncCallback\<number>): void;                       | Obtains the real-time downlink data traffic of the specified NIC. |
| getIfaceTxBytes(nic: string, callback: AsyncCallback\<number>): void;                       | Obtains the real-time uplink data traffic of the specified NIC. |
| getCellularRxBytes(callback: AsyncCallback\<number>): void;                                 | Obtains the real-time downlink data traffic of the cellular network.    |
| getCellularTxBytes(callback: AsyncCallback\<number>): void;                                 | Obtains the real-time uplink data traffic of the cellular network.    |
| getAllRxBytes(callback: AsyncCallback\<number>): void;                                      | Obtains the real-time downlink data traffic of the all NICs. |
| getAllTxBytes(callback: AsyncCallback\<number>): void;                                      | Obtains the real-time uplink data traffic of the all NICs. |
| getUidRxBytes(uid: number, callback: AsyncCallback\<number>): void;                         | Obtains the real-time downlink data traffic of the specified application. |
| getUidTxBytes(uid: number, callback: AsyncCallback\<number>): void;                         | Obtains the real-time uplink data traffic of the specified application. |
| getTrafficStatsByIface(ifaceInfo: IfaceInfo, callback: AsyncCallback\<NetStatsInfo>): void; | Obtains the historical data traffic of the specified NIC.     |
| getTrafficStatsByUid(uidInfo: UidInfo, callback: AsyncCallback\<NetStatsInfo>): void;       | Obtains the historical data traffic of the specified application.     |
| on(type: 'netStatsChange', callback: Callback\<{ iface: string, uid?: number }>): void      | Subscribes to traffic change events.        |
| off(type: 'netStatsChange', callback?: Callback\<{ iface: string, uid?: number }>): void;   | Unsubscribes from traffic change events.    |

## Obtaining Real-Time Traffic Data by NIC or UID

1. Obtain the real-time data traffic of the specified NIC. 
2. Obtain the real-time data traffic of the cellular network.
3. Obtain the real-time data traffic of all NICs. 
4. Obtain the real-time data traffic of the specified application. 

```ts
// Import the statistics namespace from @ohos.net.statistics.
import statistics from '@ohos.net.statistics';
import { BusinessError } from '@ohos.base';

// Obtain the real-time downlink data traffic of the specified NIC. 
statistics.getIfaceRxBytes('wlan0', (error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});

// Obtain the real-time uplink data traffic of the specified NIC. 
statistics.getIfaceTxBytes('wlan0', (error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});

// Obtain the real-time downlink data traffic of the cellular network.
statistics.getCellularRxBytes((error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});

// Obtain the real-time uplink data traffic of the cellular network.
statistics.getCellularTxBytes((error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});

// Obtain the real-time downlink data traffic of the all NICs. 
statistics.getAllRxBytes((error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});

// Obtain the real-time uplink data traffic of the all NICs. 
statistics.getAllTxBytes((error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});

// Obtain the real-time downlink data traffic of the specified application. 
let uid = 20010038;
statistics.getUidRxBytes(uid, (error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});

// Obtain the real-time uplink data traffic of the specified application. 
let uids = 20010038;
statistics.getUidTxBytes(uids, (error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});
```

## Obtaining Historical Traffic Data by NIC or UID

1. Obtain the historical data traffic of the specified NIC. 
2. Obtain the historical data traffic of the specified application. 

```ts
import statistics from '@ohos.net.statistics';
import { BusinessError } from '@ohos.base';

class IfaceInfo {
  iface: string = "wlan0"
  startTime: number = 1685948465
  endTime: number = 16859485670
}
// Obtain the historical data traffic of the specified NIC. 
statistics.getTrafficStatsByIface(new IfaceInfo(), (error: BusinessError, statsInfo: statistics.NetStatsInfo) => {
  console.log(JSON.stringify(error))
  console.log("getTrafficStatsByIface bytes of received = " + JSON.stringify(statsInfo.rxBytes));
  console.log("getTrafficStatsByIface bytes of sent = " + JSON.stringify(statsInfo.txBytes));
  console.log("getTrafficStatsByIface packets of received = " + JSON.stringify(statsInfo.rxPackets));
  console.log("getTrafficStatsByIface packets of sent = " + JSON.stringify(statsInfo.txPackets));
});

class UidInfo {
  uid: number = 20010037
  ifaceInfo: IfaceInfo = new IfaceInfo()
}

let uidInfo = new UidInfo()

// Obtain the historical data traffic of the specified application. 
statistics.getTrafficStatsByUid(uidInfo, (error: BusinessError, statsInfo: statistics.NetStatsInfo) => {
  console.log(JSON.stringify(error))
  console.log("getTrafficStatsByUid bytes of received = " + JSON.stringify(statsInfo.rxBytes));
  console.log("getTrafficStatsByUid bytes of sent = " + JSON.stringify(statsInfo.txBytes));
  console.log("getTrafficStatsByUid packets of received = " + JSON.stringify(statsInfo.rxPackets));
  console.log("getTrafficStatsByUid packets of sent = " + JSON.stringify(statsInfo.txPackets));
});
```

## Subscribing to Traffic Change Events

1. Subscribe to traffic change events.
2. Unsubscribe from traffic change events.

```ts
import statistics from '@ohos.net.statistics';
class Data {
  iface: string = ""
  uid?: number = 0
}

let callback = (data: Data) => {
  console.log('on netStatsChange, data:' + JSON.stringify(data));
};
// Subscribe to traffic change events.
statistics.on('netStatsChange', callback);

// Unsubscribe from traffic change events. You can pass the callback of the **on** function if you want to unsubscribe from a certain type of event. If you do not pass the callback, you will unsubscribe from all events.
statistics.off('netStatsChange', callback);
statistics.off('netStatsChange');
```
