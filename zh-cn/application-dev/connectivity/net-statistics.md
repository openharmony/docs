# 流量管理

## 简介

流量管理提供了基于物理网络的数据流量统计能力，支持基于网卡/UID的流量统计。

流量管理主要实现功能有：

- 支持基于网卡/UID的实时流量统计。
- 支持基于网卡/UID的历史流量统计。
- 支持基于网卡/UID的流量变化订阅。

> **说明：**
> 为了保证应用的运行效率，大部分API调用都是异步的，对于异步调用的API均提供了callback和Promise两种方式，以下示例均采用callback函数，更多方式可以查阅[API参考](../reference/apis/js-apis-net-statistics.md)。

以下分别介绍具体开发方式。

## 接口说明

完整的JS API说明以及实例代码请参考：[statistics链接](../reference/apis/js-apis-net-statistics.md)。

| 类型 | 接口 | 功能说明 |
| ---- | ---- | ---- |
| ohos.net.statistics | getIfaceRxBytes(nic: string, callback: AsyncCallback\<number>): void; |获取指定网卡实时下行流量数据。 |
| ohos.net.statistics | getIfaceTxBytes(nic: string, callback: AsyncCallback\<number>): void; |获取指定网卡实时上行流量数据。 |
| ohos.net.statistics | getCellularRxBytes(callback: AsyncCallback\<number>): void; |获取蜂窝实时下行流量数据。 |
| ohos.net.statistics | getCellularTxBytes(callback: AsyncCallback\<number>): void; |获取蜂窝实时上行流量数据。 |
| ohos.net.statistics | getAllRxBytes(callback: AsyncCallback\<number>): void; |获取所有网卡实时下行流量数据。 |
| ohos.net.statistics | getAllTxBytes(callback: AsyncCallback\<number>): void; |获取所有网卡实时上行流量数据。 |
| ohos.net.statistics | getUidRxBytes(uid: number, callback: AsyncCallback\<number>): void; |获取指定应用实时下行流量数据。 |
| ohos.net.statistics | getUidTxBytes(uid: number, callback: AsyncCallback\<number>): void; |获取指定应用实时上行流量数据。 |
| ohos.net.statistics | getTrafficStatsByIface(ifaceInfo: IfaceInfo, callback: AsyncCallback\<NetStatsInfo>): void; |获取指定网卡历史流量信息。 |
| ohos.net.statistics | getTrafficStatsByUid(uidInfo: UidInfo, callback: AsyncCallback\<NetStatsInfo>): void; |获取指定应用历史流量信息。 |
| ohos.net.statistics | on(type: 'netStatsChange', callback: Callback\<{ iface: string, uid?: number }>): void |订阅流量改变事件通知。 |
| ohos.net.statistics | off(type: 'netStatsChange', callback?: Callback\<{ iface: string, uid?: number }>): void; |取消订阅流量改变事件通知。 |

## 获取网卡/UID的实时流量统计数据

1. 获取指定网卡实时实时流量数据。
2. 获取蜂窝实时实时流量数据。
3. 获取所有网卡实时实时流量数据。
4. 获取指定应用实时实时流量数据。

```js
// 从@ohos.net.statistics中导入statistics命名空间
import statistics from '@ohos.net.statistics'

//获取指定网卡实时下行流量数据。
statistics.getIfaceRxBytes("wlan0", (error, stats) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(stats))
})

//获取指定网卡实时上行流量数据。
statistics.getIfaceTxBytes("wlan0", (error, stats) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(stats))
})

//获取蜂窝实时下行流量数据。
statistics.getCellularRxBytes((error, stats) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(stats))
})

//获取蜂窝实时上行流量数据。
statistics.getCellularTxBytes((error, stats) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(stats))
})

//获取所有网卡实时下行流量数据。
statistics.getAllRxBytes((error, stats) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(stats))
})

//获取所有网卡实时上行流量数据。
statistics.getAllTxBytes((error, stats) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(stats))
})

//获取指定应用实时下行流量数据。
let uid = 20010038;
statistics.getUidRxBytes(uid, (error, stats) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(stats))
})

//获取指定应用实时上行流量数据。
let uid = 20010038;
statistics.getUidTxBytes(uid, (error, stats) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(stats))
})
```

## 获取网卡/UID的历史流量统计数据

1. 获取指定网卡历史流量信息。
2. 获取指定应用历史流量信息。

```js
let ifaceInfo = {
    iface: "wlan0",
    startTime: 1685948465,
    endTime: 16859485670
}
//获取指定网卡历史流量信息。
statistics.getTrafficStatsByIface(ifaceInfo), (error, statsInfo) => {
    console.log(JSON.stringify(error))
    console.log("getTrafficStatsByIface bytes of received = " + JSON.stringify(statsInfo.rxBytes));
    console.log("getTrafficStatsByIface bytes of sent = " + JSON.stringify(statsInfo.txBytes));
    console.log("getTrafficStatsByIface packets of received = " + JSON.stringify(statsInfo.rxPackets));
    console.log("getTrafficStatsByIface packets of sent = " + JSON.stringify(statsInfo.txPackets));
});

let uidInfo = {
    ifaceInfo: {
      iface: "wlan0",
      startTime: 1685948465,
      endTime: 16859485670
    },
    uid: 20010037
}
//获取指定应用历史流量信息。
statistics.getTrafficStatsByUid(uidInfo), (error, statsInfo) => {
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

```js

let callback = data => {
    console.log("on netStatsChange, data:" + JSON.stringify(data));
}
//订阅流量改变事件通知。
statistics.on('netStatsChange', callback);

//取消订阅流量改变事件通知。可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
statistics.off('netStatsChange', callback);
statistics.off('netStatsChange');

```