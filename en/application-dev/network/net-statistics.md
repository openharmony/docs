# Collecting Network Statistics
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

## Introduction

The traffic management module allows you to query real-time or historical data traffic by the specified network interface card (NIC) or user ID (UID).

Its functions include:

- Obtaining real-time traffic data by NIC or UID
- Obtaining historical traffic data by NIC or UID
- Subscribing to traffic change events by NIC or UID

> **NOTE**
> To maximize the application running efficiency, most API calls are called asynchronously in callback or promise mode. The following code examples use the promise mode. For details about the APIs, see [API Reference](../reference/apis-network-kit/js-apis-net-statistics.md).

The following describes the development procedure specific to each application scenario.

## How to Develop

1. Import the **statistics**, **socket**, and **BusinessError** modules.

    ```ts
    import { statistics, socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. Obtain the real-time data traffic of the specified NIC. 

    Call **getIfaceRxBytes** with the NIC name specified to obtain the real-time downlink data traffic.

    ```ts
    // Obtain the real-time downlink data traffic of the primary Wi-Fi NIC. wlan0 is the name of the primary Wi-Fi NIC.
    statistics.getIfaceRxBytes("wlan0").then((stats: number) => {
      console.info(JSON.stringify(stats));
    });

    // Obtain the real-time uplink data traffic of the primary Wi-Fi NIC. wlan0 is the name of the primary Wi-Fi NIC.
    statistics.getIfaceTxBytes("wlan0").then((stats: number) => {
      console.info(JSON.stringify(stats));
    });
    ```

3. Obtain the real-time data traffic of the cellular network.

    Call **getCellularRxBytes** to obtain the real-time uplink and downlink data traffic of the cellular network.

    ```ts
    // Obtain the real-time downlink data traffic of the cellular network.
    statistics.getCellularRxBytes().then((stats: number) => {
      console.info(JSON.stringify(stats));
    });

    // Obtain the real-time uplink data traffic of the cellular network.
    statistics.getCellularTxBytes().then((stats: number) => {
      console.info(JSON.stringify(stats));
    });
    ```

4. Obtain the real-time data traffic of all NICs.

    Call **getAllRxBytes** to obtain the real-time uplink and downlink data traffic of all NICs.

    ```ts
    // Obtain the real-time downlink data traffic of all NICs. 
    statistics.getAllRxBytes().then((stats: number) => {
      console.info(JSON.stringify(stats));
    });

    // Obtain the real-time uplink data traffic of all NICs. 
    statistics.getAllTxBytes().then((stats: number) => {
      console.info(JSON.stringify(stats));
    });
    ```

5. Obtain the real-time data traffic of the specified application.

    Call **getUidRxBytes** with the UID specified to obtain the real-time uplink and downlink data traffic of the specified application.

    ```ts
    // Obtain the real-time downlink data traffic of the specified application. 
    let uid = 20010038;
    statistics.getUidRxBytes(uid).then((stats: number) => {
      console.info(JSON.stringify(stats));
    });

    // Obtain the real-time uplink data traffic of the specified application. 
    let uid = 20010038;
    statistics.getUidTxBytes(uid).then((stats: number) => {
      console.info(JSON.stringify(stats));
    });
    ```

6. Obtains the real-time data traffic of the specified socket.

    Call **getSockfdRxBytes** with **sockFd** specified to obtain the real-time uplink and downlink data traffic of the specified socket.

    ```ts
    // Obtain the real-time downlink data traffic of the specified socket. 
    let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
    tcp.getSocketFd().then((sockfd: number) => {
      statistics.getSockfdRxBytes(sockfd).then((stats: number) => {
        console.info(JSON.stringify(stats));
      }).catch((err: BusinessError) => {
        console.error(JSON.stringify(err));
      });
    });

    // Obtain the real-time uplink data traffic of the specified socket. 
    tcp.getSocketFd().then((sockfd: number) => {
      statistics.getSockfdTxBytes(sockfd).then((stats: number) => {
        console.info(JSON.stringify(stats));
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
  console.info(
    "getTrafficStatsByIface bytes of received = " +
    JSON.stringify(statsInfo.rxBytes)
  );
  console.info(
    "getTrafficStatsByIface bytes of sent = " +
    JSON.stringify(statsInfo.txBytes)
  );
  console.info(
    "getTrafficStatsByIface packets of received = " +
    JSON.stringify(statsInfo.rxPackets)
  );
  console.info(
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
  console.info("getTrafficStatsByUid bytes of received = " + JSON.stringify(statsInfo.rxBytes));
  console.info("getTrafficStatsByUid bytes of sent = " + JSON.stringify(statsInfo.txBytes));
  console.info("getTrafficStatsByUid packets of received = " + JSON.stringify(statsInfo.rxPackets));
  console.info("getTrafficStatsByUid packets of sent = " + JSON.stringify(statsInfo.txPackets));
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
  console.info('on netStatsChange, data:' + JSON.stringify(data));
};
// Subscribe to traffic change events.
statistics.on('netStatsChange', callback);

// Unsubscribe from traffic change events. You can pass the callback of the **on** function if you want to unsubscribe from a certain type of event. If you do not pass the callback, you will unsubscribe from all events.
statistics.off('netStatsChange', callback);
statistics.off('netStatsChange');
```
<!--DelEnd-->


