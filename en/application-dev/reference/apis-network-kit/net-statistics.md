# Traffic Management

## Introduction

The traffic management module allows you to query real-time or historical data traffic by the specified network interface card (NIC) or user ID (UID).

Its functions include:

- Obtaining real-time traffic data by NIC or UID
- Obtaining historical traffic data by NIC or UID
- Subscribing to traffic change events by NIC or UID

> **NOTE**
> To maximize the application running efficiency, most API calls are called asynchronously in callback or promise mode. The following code examples use the promise mode. For details about the APIs, see [API Reference](js-apis-net-statistics.md).

The following describes the development procedure specific to each application scenario.

## Available APIs

For the complete list of APIs and example code, see [Traffic Management](js-apis-net-statistics.md).

| API                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| getIfaceRxBytes(nic: string, callback: AsyncCallback\<number>): void; | Obtains the real-time downlink data traffic of the specified NIC.                               |
| getIfaceTxBytes(nic: string, callback: AsyncCallback\<number>): void; | Obtains the real-time uplink data traffic of the specified NIC.                               |
| getCellularRxBytes(callback: AsyncCallback\<number>): void;  | Obtains the real-time downlink data traffic of the cellular network.                                  |
| getCellularTxBytes(callback: AsyncCallback\<number>): void;  | Obtains the real-time uplink data traffic of the cellular network.                                  |
| getAllRxBytes(callback: AsyncCallback\<number>): void;       | Obtains the real-time downlink data traffic of the all NICs.                               |
| getAllTxBytes(callback: AsyncCallback\<number>): void;       | Obtains the real-time uplink data traffic of the all NICs.                               |
| getUidRxBytes(uid: number, callback: AsyncCallback\<number>): void; | Obtains the real-time downlink data traffic of the specified application.                               |
| getUidTxBytes(uid: number, callback: AsyncCallback\<number>): void; | Obtains the real-time uplink data traffic of the specified application.                               |
| <!--DelRow-->getTrafficStatsByIface(ifaceInfo: IfaceInfo, callback: AsyncCallback\<NetStatsInfo>): void; | Obtains the historical data traffic of the specified NIC. This is a system API. For details, see [API Reference](js-apis-net-statistics-sys.md#statisticsgettrafficstatsbyiface10).|
| <!--DelRow-->getTrafficStatsByUid(uidInfo: UidInfo, callback: AsyncCallback\<NetStatsInfo>): void; | Obtains the historical data traffic of the specified application. This is a system API. For details, see [API Reference](js-apis-net-statistics-sys.md#statisticsgettrafficstatsbyuid10).|
| getSockfdRxBytes(sockfd: number, callback: AsyncCallback\<number>): void; | Obtains the real-time downlink data traffic of the specified socket.                             |
| getSockfdTxBytes(sockfd: number, callback: AsyncCallback\<number>): void; | Obtains the real-time uplink data traffic of the specified socket.                             |
| <!--DelRow-->on(type: 'netStatsChange', callback: Callback\<{ iface: string, uid?: number }>): void; | Subscribes to traffic change events. This is a system API. For details, see [API Reference](js-apis-net-statistics-sys.md#statisticsonnetstatschange10).|
| <!--DelRow-->off(type: 'netStatsChange', callback?: Callback\<{ iface: string, uid?: number }>): void; | Unsubscribes from traffic change events. This is a system API. For details, see [API Reference](js-apis-net-statistics-sys.md#statisticsoffnetstatschange10).|
| <!--DelRow-->getTrafficStatsByNetwork(networkInfo: NetworkInfo): Promise\<UidNetStatsInfo\>; | Obtains the traffic statistics of all applications on the specified network within the specified period. This is a system API. For details, see [API Reference](js-apis-net-statistics-sys.md#statisticsgettrafficstatsbynetwork12).|
| <!--DelRow-->getTrafficStatsByUidNetwork(uid: number, networkInfo: NetworkInfo): Promise\<NetStatsInfoSequence\>; | Obtains the traffic statistics of the specified application on the specified network within the specified period. This is a system API. For details, see [API Reference](js-apis-net-statistics-sys.md#statisticsgettrafficstatsbynetwork12).|

## Obtaining Real-Time Traffic Data by NIC or UID

1. Obtain the real-time data traffic of the specified NIC. 
2. Obtain the real-time data traffic of the cellular network.
3. Obtain the real-time data traffic of all NICs.
4. Obtain the real-time data traffic of the specified application. 
5. Obtains the real-time data traffic of the specified socket.

```ts
// Import the statistics namespace from @kit.NetworkKit.
import { statistics, socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the real-time downlink data traffic of the specified NIC. 
statistics.getIfaceRxBytes("wlan0").then((stats: number) => {
  console.log(JSON.stringify(stats));
});

// Obtain the real-time uplink data traffic of the specified NIC. 
statistics.getIfaceTxBytes("wlan0").then((stats: number) => {
  console.log(JSON.stringify(stats));
});

// Obtain the real-time downlink data traffic of the cellular network.
statistics.getCellularRxBytes().then((stats: number) => {
  console.log(JSON.stringify(stats));
});

// Obtain the real-time uplink data traffic of the cellular network.
statistics.getCellularTxBytes().then((stats: number) => {
  console.log(JSON.stringify(stats));
});

// Obtain the real-time downlink data traffic of the all NICs. 
statistics.getAllRxBytes().then((stats: number) => {
  console.log(JSON.stringify(stats));
});

// Obtain the real-time uplink data traffic of the all NICs. 
statistics.getAllTxBytes().then((stats: number) => {
  console.log(JSON.stringify(stats));
});

// Obtain the real-time downlink data traffic of the specified application. 
let uid = 20010038;
statistics.getUidRxBytes(uid).then((stats: number) => {
  console.log(JSON.stringify(stats));
});

// Obtain the real-time uplink data traffic of the specified application. 
let uids = 20010038;
statistics.getUidTxBytes(uids).then((stats: number) => {
  console.log(JSON.stringify(stats));
});

// Obtain the real-time downlink data traffic of the specified socket. 
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
tcp.getSocketFd().then((sockfd: number) => {
  statistics.getSockfdRxBytes(sockfd).then((stats: number) => {
    console.log(JSON.stringify(stats));
  }).catch((err: BusinessError) => {
    console.error(JSON.stringify(err));
  });
});

// Obtain the real-time uplink data traffic of the specified socket. 
tcp.getSocketFd().then((sockfd: number) => {
  statistics.getSockfdTxBytes(sockfd).then((stats: number) => {
    console.log(JSON.stringify(stats));
  }).catch((err: BusinessError) => {
    console.error(JSON.stringify(err));
  });
});
```

<!--Del-->
## Obtaining Historical Traffic Data by NIC or UID

1. Obtain the historical data traffic of the specified NIC. 
2. Obtain the historical data traffic of the specified application. 

```ts
import { statistics } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

class IfaceInfo {
  iface: string = "wlan0"
  startTime: number = 1685948465
  endTime: number = 16859485670
}
// Obtain the historical data traffic of the specified NIC. 
statistics.getTrafficStatsByIface(new IfaceInfo()).then((statsInfo: statistics.NetStatsInfo) => {
  console.log(
    "getTrafficStatsByIface bytes of received = " +
    JSON.stringify(statsInfo.rxBytes)
  );
  console.log(
    "getTrafficStatsByIface bytes of sent = " +
    JSON.stringify(statsInfo.txBytes)
  );
  console.log(
    "getTrafficStatsByIface packets of received = " +
    JSON.stringify(statsInfo.rxPackets)
  );
  console.log(
    "getTrafficStatsByIface packets of sent = " +
    JSON.stringify(statsInfo.txPackets)
  );
});

class UidInfo {
  uid: number = 20010037
  ifaceInfo: IfaceInfo = new IfaceInfo()
}

let uidInfo = new UidInfo()

// Obtain the historical data traffic of the specified application. 
statistics.getTrafficStatsByUid(uidInfo).then((statsInfo: statistics.NetStatsInfo) => {
  console.log("getTrafficStatsByUid bytes of received = " + JSON.stringify(statsInfo.rxBytes));
  console.log("getTrafficStatsByUid bytes of sent = " + JSON.stringify(statsInfo.txBytes));
  console.log("getTrafficStatsByUid packets of received = " + JSON.stringify(statsInfo.rxPackets));
  console.log("getTrafficStatsByUid packets of sent = " + JSON.stringify(statsInfo.txPackets));
})
```

## Subscribing to Traffic Change Events

1. Subscribe to traffic change events.
2. Unsubscribe from traffic change events.

```ts
import { statistics } from '@kit.NetworkKit';

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
<!--DelEnd-->
