# 统计网络流量消耗
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

## 简介

流量管理提供了基于物理网络的数据流量统计能力，支持基于网卡/UID 的流量统计。

流量管理主要实现功能有：

- 支持基于网卡/UID 的实时流量统计。
- 支持基于网卡/UID 的历史流量统计。
- 支持基于网卡/UID 的流量变化订阅。

> **说明：**
> 为了保证应用的运行效率，大部分 API 调用都是异步的，对于异步调用的 API 均提供了 callback 和 Promise 两种方式，以下示例均采用 Promise 函数，更多方式可以查阅[API 参考](../reference/apis-network-kit/js-apis-net-statistics.md)。

以下分别介绍具体开发方式。

## 开发步骤

1. 导入statistics、socket以及错误码模块。

    ```ts
    import { statistics, socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. 获取指定网卡实时流量数据

    调用getIfaceRxBytes接口传入网卡名获取实时下行流量数据。

    ```ts
    // wlan0为主WiFi网卡名，获取主WiFi实时下行流量数据。
    statistics.getIfaceRxBytes("wlan0").then((stats: number) => {
      console.log(JSON.stringify(stats));
    });

    // wlan0为主WiFi网卡名，获取主WiFi实时上行流量数据。
    statistics.getIfaceTxBytes("wlan0").then((stats: number) => {
      console.log(JSON.stringify(stats));
    });
    ```

3. 获取蜂窝实时流量数据

    调用getCellularRxBytes接口获取蜂窝实时上下行流量数据。

    ```ts
    // 获取蜂窝实时下行流量数据。
    statistics.getCellularRxBytes().then((stats: number) => {
      console.log(JSON.stringify(stats));
    });

    // 获取蜂窝实时上行流量数据。
    statistics.getCellularTxBytes().then((stats: number) => {
      console.log(JSON.stringify(stats));
    });
    ```

4. 获取所有网卡实时流量数据

    调用getAllRxBytes接口获取所有网卡实时上下行流量数据。

    ```ts
    // 获取所有网卡实时下行流量数据。
    statistics.getAllRxBytes().then((stats: number) => {
      console.log(JSON.stringify(stats));
    });

    // 获取所有网卡实时上行流量数据。
    statistics.getAllTxBytes().then((stats: number) => {
      console.log(JSON.stringify(stats));
    });
    ```

5. 获取指定应用实时流量数据

    调用getUidRxBytes接口，传入UID获取指定应用实时上下行流量数据。

    ```ts
    // 获取指定应用实时下行流量数据。
    let uid = 20010038;
    statistics.getUidRxBytes(uid).then((stats: number) => {
      console.log(JSON.stringify(stats));
    });

    // 获取指定应用实时上行流量数据。
    let uid = 20010038;
    statistics.getUidTxBytes(uid).then((stats: number) => {
      console.log(JSON.stringify(stats));
    });
    ```

6. 获取指定socket实时流量数据

    调用getSockfdRxBytes接口，传入指定的sockFd获取指定socket实时上下行流量数据。

    ```ts
    // 获取指定socket实时下行流量数据。
    let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
    tcp.getSocketFd().then((sockfd: number) => {
      statistics.getSockfdRxBytes(sockfd).then((stats: number) => {
        console.log(JSON.stringify(stats));
      }).catch((err: BusinessError) => {
        console.error(JSON.stringify(err));
      });
    });

    // 获取指定socket实时上行流量数据。
    tcp.getSocketFd().then((sockfd: number) => {
      statistics.getSockfdTxBytes(sockfd).then((stats: number) => {
        console.log(JSON.stringify(stats));
      }).catch((err: BusinessError) => {
        console.error(JSON.stringify(err));
      });
    });
    ```

<!--Del-->
## 获取网卡/UID 的历史流量统计数据

1. 获取指定网卡历史流量信息。
2. 获取指定应用历史流量信息。

```ts
import { statistics } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

class IfaceInfo {
  iface: string = "wlan0"
  startTime: number = 1685948465
  endTime: number = 16859485670
}
// 获取指定网卡历史流量信息。
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

// 获取指定应用历史流量信息。
statistics.getTrafficStatsByUid(uidInfo).then((statsInfo: statistics.NetStatsInfo) => {
  console.log("getTrafficStatsByUid bytes of received = " + JSON.stringify(statsInfo.rxBytes));
  console.log("getTrafficStatsByUid bytes of sent = " + JSON.stringify(statsInfo.txBytes));
  console.log("getTrafficStatsByUid packets of received = " + JSON.stringify(statsInfo.rxPackets));
  console.log("getTrafficStatsByUid packets of sent = " + JSON.stringify(statsInfo.txPackets));
})
```

## 订阅流量变化事件

1. 订阅流量改变事件通知。
2. 取消订阅流量改变事件通知。

```ts
import { statistics } from '@kit.NetworkKit';

class Data {
  iface: string = ""
  uid?: number = 0
}

let callback = (data: Data) => {
  console.log('on netStatsChange, data:' + JSON.stringify(data));
};
// 订阅流量改变事件通知。
statistics.on('netStatsChange', callback);

// 取消订阅流量改变事件通知。可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
statistics.off('netStatsChange', callback);
statistics.off('netStatsChange');
```
<!--DelEnd-->

## 相关实例

针对流量管理的开发，有以下相关实例可供参考：

- [流量管理](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/FlowManagement_case)
