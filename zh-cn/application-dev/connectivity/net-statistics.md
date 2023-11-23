# 流量管理

## 简介

流量管理提供了基于物理网络的数据流量统计能力，支持基于网卡/UID 的流量统计。

流量管理主要实现功能有：

- 支持基于网卡/UID 的实时流量统计。
- 支持基于网卡/UID 的历史流量统计。
- 支持基于网卡/UID 的流量变化订阅。

> **说明：**
> 为了保证应用的运行效率，大部分 API 调用都是异步的，对于异步调用的 API 均提供了 callback 和 Promise 两种方式，以下示例均采用 callback 函数，更多方式可以查阅[API 参考](../reference/apis/js-apis-net-statistics.md)。

以下分别介绍具体开发方式。

## 接口说明

完整的 JS API 说明以及实例代码请参考：[statistics 链接](../reference/apis/js-apis-net-statistics.md)。

| 接口名                                                                                      | 描述                         |
| ------------------------------------------------------------------------------------------- | ---------------------------- |
| getIfaceRxBytes(nic: string, callback: AsyncCallback\<number>): void;                       | 获取指定网卡实时下行流量数据。 |
| getIfaceTxBytes(nic: string, callback: AsyncCallback\<number>): void;                       | 获取指定网卡实时上行流量数据。 |
| getCellularRxBytes(callback: AsyncCallback\<number>): void;                                 | 获取蜂窝实时下行流量数据。     |
| getCellularTxBytes(callback: AsyncCallback\<number>): void;                                 | 获取蜂窝实时上行流量数据。     |
| getAllRxBytes(callback: AsyncCallback\<number>): void;                                      | 获取所有网卡实时下行流量数据。 |
| getAllTxBytes(callback: AsyncCallback\<number>): void;                                      | 获取所有网卡实时上行流量数据。 |
| getUidRxBytes(uid: number, callback: AsyncCallback\<number>): void;                         | 获取指定应用实时下行流量数据。 |
| getUidTxBytes(uid: number, callback: AsyncCallback\<number>): void;                         | 获取指定应用实时上行流量数据。 |
| getTrafficStatsByIface(ifaceInfo: IfaceInfo, callback: AsyncCallback\<NetStatsInfo>): void; | 获取指定网卡历史流量信息。     |
| getTrafficStatsByUid(uidInfo: UidInfo, callback: AsyncCallback\<NetStatsInfo>): void;       | 获取指定应用历史流量信息。     |
| on(type: 'netStatsChange', callback: Callback\<{ iface: string, uid?: number }>): void      | 订阅流量改变事件通知。         |
| off(type: 'netStatsChange', callback?: Callback\<{ iface: string, uid?: number }>): void;   | 取消订阅流量改变事件通知。     |

## 获取网卡/UID 的实时流量统计数据

1. 获取指定网卡实时实时流量数据。
2. 获取蜂窝实时实时流量数据。
3. 获取所有网卡实时实时流量数据。
4. 获取指定应用实时实时流量数据。

```ts
// 从@ohos.net.statistics中导入statistics命名空间
import statistics from '@ohos.net.statistics';
import { BusinessError } from '@ohos.base';

//获取指定网卡实时下行流量数据。
statistics.getIfaceRxBytes('wlan0', (error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});

//获取指定网卡实时上行流量数据。
statistics.getIfaceTxBytes('wlan0', (error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});

//获取蜂窝实时下行流量数据。
statistics.getCellularRxBytes((error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});

//获取蜂窝实时上行流量数据。
statistics.getCellularTxBytes((error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});

//获取所有网卡实时下行流量数据。
statistics.getAllRxBytes((error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});

//获取所有网卡实时上行流量数据。
statistics.getAllTxBytes((error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});

//获取指定应用实时下行流量数据。
let uid = 20010038;
statistics.getUidRxBytes(uid, (error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});

//获取指定应用实时上行流量数据。
let uids = 20010038;
statistics.getUidTxBytes(uids, (error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});
```

## 获取网卡/UID 的历史流量统计数据

1. 获取指定网卡历史流量信息。
2. 获取指定应用历史流量信息。

```ts
import statistics from '@ohos.net.statistics';
import { BusinessError } from '@ohos.base';

class IfaceInfo {
  iface: string = "wlan0"
  startTime: number = 1685948465
  endTime: number = 16859485670
}
//获取指定网卡历史流量信息。
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

//获取指定应用历史流量信息。
statistics.getTrafficStatsByUid(uidInfo, (error: BusinessError, statsInfo: statistics.NetStatsInfo) => {
  console.log(JSON.stringify(error))
  console.log("getTrafficStatsByUid bytes of received = " + JSON.stringify(statsInfo.rxBytes));
  console.log("getTrafficStatsByUid bytes of sent = " + JSON.stringify(statsInfo.txBytes));
  console.log("getTrafficStatsByUid packets of received = " + JSON.stringify(statsInfo.rxPackets));
  console.log("getTrafficStatsByUid packets of sent = " + JSON.stringify(statsInfo.txPackets));
});
```

## 订阅流量变化事件

1. 订阅流量改变事件通知。
2. 取消订阅流量改变事件通知。

```ts
import statistics from '@ohos.net.statistics';
class Data {
  iface: string = ""
  uid?: number = 0
}

let callback = (data: Data) => {
  console.log('on netStatsChange, data:' + JSON.stringify(data));
};
//订阅流量改变事件通知。
statistics.on('netStatsChange', callback);

//取消订阅流量改变事件通知。可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
statistics.off('netStatsChange', callback);
statistics.off('netStatsChange');
```
