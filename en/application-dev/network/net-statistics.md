# Collecting Network Statistics

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=399a9878312d58ff8c5c91bed5439ca285e92651 translatedAt=2026-08-13T03:10:33.038Z pushedAt=2026-08-13T06:47:55.127Z -->

## Introduction

Traffic management provides the capability of collecting traffic data based on the physical network, and supports traffic statistics based on NIC/UID.

Its functions include:

- Supports traffic statistics based on NIC.

- Supports traffic statistics based on app UID.

> **NOTE**
>
> - To maximize the app running efficiency, most API calls are asynchronous. For asynchronous APIs, both callback and promise modes are provided. The following examples use the promise mode. For details about other modes, see [@ohos.net.statistics (traffic management)](../reference/apis-network-kit/js-apis-net-statistics.md).
> - Uplink traffic refers to the amount of data sent from the terminal device to the network side, and downlink traffic refers to the amount of data transmitted from the network side to the terminal device.

The following describes the development procedure specific to each application scenario.

## How to Develop

1. Import the [statistics](../reference/apis-network-kit/js-apis-net-statistics.md), [socket](../reference/apis-network-kit/js-apis-socket.md), and error code modules.

   <!-- @[flow_management_case_module_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/FlowManagement_case/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   import { socket, statistics } from '@kit.NetworkKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. Get the traffic data of the specified NIC.

   Call [getIfaceRxBytes](../reference/apis-network-kit/js-apis-net-statistics.md#statisticsgetifacerxbytes-1) and [getIfaceTxBytes](../reference/apis-network-kit/js-apis-net-statistics.md#statisticsgetifacetxbytes-1) separately, and pass the NIC name to get the downlink and uplink traffic data of the specified NIC since the last startup.

   <!-- @[flow_management_getIfaceRxBytes_and_getIfaceTxBytes](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/FlowManagement_case/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
     // Obtain the real-time downlink data traffic of the primary Wi-Fi NIC. wlan0 is the name of the primary Wi-Fi NIC.
     statistics.getIfaceRxBytes('wlan0').then((stats: number) => {
       hilog.info(0x0000, 'testTag', JSON.stringify(stats));
       // ...
     })
     .catch((err: BusinessError) => {
       hilog.error(0x0000, 'testTag', JSON.stringify(err));
       // ...
     });
     // ...
     // Obtain the real-time uplink data traffic of the primary Wi-Fi NIC. wlan0 is the name of the primary Wi-Fi NIC.
     statistics.getIfaceTxBytes('wlan0').then((stats: number) => {
       hilog.info(0x0000, 'testTag', JSON.stringify(stats));
       // ...
     })
     .catch((err: BusinessError) => {
       hilog.error(0x0000, 'testTag', JSON.stringify(err));
       // ...
     });
   // ...
   ```

3. Obtain the cellular traffic data.

    Call [getCellularRxBytes](../reference/apis-network-kit/js-apis-net-statistics.md#statisticsgetcellularrxbytes-1) and [getCellularTxBytes](../reference/apis-network-kit/js-apis-net-statistics.md#statisticsgetcellulartxbytes-1) separately to obtain the cellular downlink and uplink traffic data since the last startup.

   <!-- @[flow_management_getCellularRxBytes_and_getCellularTxBytes](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/FlowManagement_case/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // Obtain the real-time downlink data traffic of the cellular network.
   statistics.getCellularRxBytes().then((stats: number) => {
     hilog.info(0x0000, 'testTag', JSON.stringify(stats));
     // ...
   })
   // ...
   // Obtain the real-time uplink data traffic of the cellular network.
   statistics.getCellularTxBytes().then((stats: number) => {
     hilog.info(0x0000, 'testTag', JSON.stringify(stats));
     // ...
   })
   // ...
   ```

4. Obtain the traffic data of all NICs.

    Call [getAllRxBytes](../reference/apis-network-kit/js-apis-net-statistics.md#statisticsgetallrxbytes-1) and [getAllTxBytes](../reference/apis-network-kit/js-apis-net-statistics.md#statisticsgetalltxbytes-1) separately to obtain the downlink and uplink traffic data of all NICs since the last startup.

   <!-- @[flow_management_getAllRxBytes_and_getAllTxBytes](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/FlowManagement_case/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // Obtain the real-time downlink data traffic of all NICs. 
   statistics.getAllRxBytes().then((stats: number) => {
     hilog.info(0x0000, 'testTag', JSON.stringify(stats));
     // ...
   })
   // ...
   // Obtain the real-time uplink data traffic of all NICs. 
   statistics.getAllTxBytes().then((stats: number) => {
     hilog.info(0x0000, 'testTag', JSON.stringify(stats));
     // ...
   })
   // ...
   ```

5. Get the traffic data of the specified app.

    Call [getUidRxBytes](../reference/apis-network-kit/js-apis-net-statistics.md#statisticsgetuidrxbytes-1) and [getUidTxBytes](../reference/apis-network-kit/js-apis-net-statistics.md#statisticsgetuidtxbytes-1) separately, and pass the UID to get the downlink and uplink traffic data of the specified app since the last startup.<br>
    Here, the app UID 20010038 is used as an example. Replace it with the actual UID when calling.

   ```ts
    let UID = 20010038;
   ```

   <!-- @[flow_management_getUidRxBytes_and_getUidTxBytes](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/FlowManagement_case/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // Obtain the real-time downlink data traffic of the specified application. 
   // ...
   statistics.getUidRxBytes(UID).then((stats: number) => {
     hilog.info(0x0000, 'testTag', JSON.stringify(stats));
     // ...
   })
   // ...
   // Obtain the real-time uplink data traffic of the specified application. 
   // ...
   statistics.getUidTxBytes(UID).then((stats: number) => {
     hilog.info(0x0000, 'testTag', JSON.stringify(stats));
     // ...
   })
   // ...
   ```

6. Obtain the traffic data of the specified socket.

    Call [getSockfdRxBytes](../reference/apis-network-kit/js-apis-net-statistics.md#statisticsgetsockfdrxbytes11-1) and [getSockfdTxBytes](../reference/apis-network-kit/js-apis-net-statistics.md#statisticsgetsockfdtxbytes11-1) separately, and pass the socket FD to get the downlink and uplink traffic data of the specified socket.

   <!-- @[flow_management_getSockfdRxBytes_and_getSockfdTxBytes](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/FlowManagement_case/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // Obtain the real-time downlink data traffic of the specified socket. 
   let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
   // ...
   tcp.getSocketFd().then((sockfd: number) => {
     statistics.getSockfdRxBytes(sockfd).then((stats: number) => {
       hilog.info(0x0000, 'testTag', JSON.stringify(stats));
       // ...
     }).catch((err: BusinessError) => {
       hilog.error(0x0000, 'testTag', JSON.stringify(err));
       // ...
     });
   })
   // ...
   // Obtain the real-time uplink data traffic of the specified socket. 
   tcp.getSocketFd().then((sockfd: number) => {
     statistics.getSockfdTxBytes(sockfd).then((stats: number) => {
       hilog.info(0x0000, 'testTag', JSON.stringify(stats));
       // ...
     }).catch((err: BusinessError) => {
       hilog.error(0x0000, 'testTag', JSON.stringify(err));
       // ...
     });
   })
   // ...
   ```

<!--Del-->

## Obtaining Historical Traffic Data by NIC or App UID

1. Obtain the historical data traffic of the specified NIC. 

2. Obtain the historical data traffic of the specified application.

      ```ts
      import { statistics } from '@kit.NetworkKit';

      class IfaceInfo {
        iface: string = "wlan0",
        startTime: number = 1685948465,
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

## Samples

The following samples are provided to help you better understand how to develop traffic management features:

- [Traffic Management](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/FlowManagement_case)