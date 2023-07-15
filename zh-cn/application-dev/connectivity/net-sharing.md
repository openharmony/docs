# 网络共享

## 简介

网络共享管理分享设备已有网络给其他连接设备，支持Wi-Fi热点共享、蓝牙共享和USB共享，同时提供网络共享状态、共享流量查询功能。

> **说明：**
> 为了保证应用的运行效率，大部分API调用都是异步的，对于异步调用的API均提供了callback和Promise两种方式，以下示例均采用callback函数，更多方式可以查阅[API参考](../reference/apis/js-apis-net-sharing.md)。

## 基本概念

- WIFI共享：通过WIFI热点共享网络。
- 蓝牙共享：通过蓝牙共享网络。
- USB共享：通过USB共享网络。

## 约束

- 开发语言：C++ JS
- 系统：linux内核
- 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 场景介绍

网络共享的典型场景有：

- 开启网络共享
- 停止网络共享
- 获取共享网络的数据流量

以下分别介绍具体开发方式。

## 接口说明

完整的JS API说明以及实例代码请参考：[网络共享](../reference/apis/js-apis-net-sharing.md)。

| 类型 | 接口 | 功能说明 |
| ---- | ---- | ---- |
| ohos.net.sharing | function isSharingSupported(callback: AsyncCallback\<boolean>): void; | 获取当前系统是否支持网络共享，使用callback方式作为异步方法 |
| ohos.net.sharing | function isSharing(callback: AsyncCallback\<boolean>): void; | 获取当前共享状态，使用callback方式作为异步方法 |
| ohos.net.sharing | function startSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void; | 开启共享，type为共享类型，目前支持Wifi热点、蓝牙、USB，使用callback方式作为异步方法 |
| ohos.net.sharing | function stopSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void; | 停止指定类型共享，type为共享类型，包括Wifi热点、蓝牙、USB，使用callback方式作为异步方法 |
| ohos.net.sharing | function getStatsRxBytes(callback: AsyncCallback\<number>): void; | 获取共享接收数据量，单位KB，使用callback方式作为异步方法 |
| ohos.net.sharing | function getStatsTxBytes(callback: AsyncCallback\<number>): void; | 获取共享发送数据量，单位KB，使用callback方式作为异步方法 |
| ohos.net.sharing | function getStatsTotalBytes(callback: AsyncCallback\<number>): void; | 获取共享总数据流量，单位KB，使用callback方式作为异步方法 |
| ohos.net.sharing | function getSharingIfaces(state: SharingIfaceState, callback: AsyncCallback\<Array\<string>>): void; | 获取指定状态的网卡名称，state为状态，包括正在共享、可共享、共享错误，使用callback方式作为异步方法 |
| ohos.net.sharing | function getSharingState(type: SharingIfaceType, callback: AsyncCallback\<SharingIfaceState>): void; | 获取指定类型共享状态，type为类型，目前支持Wifi热点、蓝牙、USB，使用callback方式作为异步方法 |
| ohos.net.sharing | function getSharableRegexes(type: SharingIfaceType, callback: AsyncCallback\<Array\<string>>): void; | 获取与指定类型匹配的网卡正则表达式列表，type为类型，目前支持Wifi热点、蓝牙、USB，使用callback方式作为异步方法 |
| ohos.net.sharing | function on(type: 'sharingStateChange', callback: Callback\<boolean>): void; | 注册共享状态改变监听，返回网络共享的状态。 |
| ohos.net.sharing | function off(type: 'sharingStateChange', callback?: Callback\<boolean>): void; | 注销共享状态改变监听，返回网络共享的状态。 |
| ohos.net.sharing | unction on(type: 'interfaceSharingStateChange', callback: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void; | 注册指定网卡共享状态改变监听 |
| ohos.net.sharing | function off(type: 'interfaceSharingStateChange', callback?: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void; | 注销指定网卡共享状态改变监听 |
| ohos.net.sharing | function on(type: 'sharingUpstreamChange', callback: Callback\<NetHandle>): void; | 注册上行网卡改变监听 |
| ohos.net.sharing | function off(type: 'sharingUpstreamChange', callback?: Callback\<NetHandle>): void; | 注销上行网卡改变监听 |

## 开启网络共享

1. 从@ohos.net.sharing中导入sharing命名空间。
2. 注册监听共享状态的改变。
3. 调用startSharing方法，来开启指定类型共享。
4. 接收到共享状态开启的回调，开启共享成功。

```js
// 从@ohos.net.sharing中导入sharing命名空间
import sharing from '@ohos.net.sharing'

// 注册监听共享状态的改变
sharing.on('sharingStateChange', (error, data) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});

// 调用startSharing方法，来开启指定类型共享
sharing.startSharing(sharing.SharingIfaceType.SHARING_WIFI, (error) => {
  console.log(JSON.stringify(error));
});
```

## 停止网络共享

### 开发步骤

1. 从@ohos.net.sharing中导入sharing命名空间。
2. 注册监听共享状态的改变。
3. 调用stopSharing方法，来停止指定类型共享。
4. 接收到共享状态关闭的回调，停止共享成功。

```js
// 从@ohos.net.sharing中导入sharing命名空间
import sharing from '@ohos.net.sharing'

// 注册监听共享状态的改变
sharing.on('sharingStateChange', (error, data) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});

// 调用stopSharing方法，来停止指定类型共享
sharing.stopSharing(sharing.SharingIfaceType.SHARING_WIFI, (error) => {
  console.log(JSON.stringify(error));
});
```

## 获取共享网络的数据流量

### 开发步骤

1. 从@ohos.net.sharing中导入sharing命名空间。
2. 调用startSharing方法，来开启指定类型共享。
3. 调用getStatsTotalBytes方法，来获取共享网络数据量。
4. 调用stopSharing方法，来停止指定类型共享，共享网络数据量清零。

```js
// 从@ohos.net.sharing中导入sharing命名空间
import sharing from '@ohos.net.sharing'

// 调用startSharing方法，来开启指定类型共享
sharing.startSharing(sharing.SharingIfaceType.SHARING_WIFI, (error) => {
  console.log(JSON.stringify(error));
});

// 调用getStatsTotalBytes方法，来获取共享网络数据量
sharing.getStatsTotalBytes((error, data) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});

// 调用stopSharing方法，来停止指定类型共享，共享网络数据量清零
sharing.stopSharing(sharing.SharingIfaceType.SHARING_WIFI, (error) => {
  console.log(JSON.stringify(error));
});

// 再次调用getStatsTotalBytes方法，共享网络数据量已清零
sharing.getStatsTotalBytes((error, data) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```
