# 网络共享（仅对系统应用开放）
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

## 简介

网络共享管理分享设备已有网络给其他连接设备，支持 Wi-Fi 热点共享、蓝牙共享和 USB 共享，同时提供网络共享状态、共享流量查询功能。

> **说明：**
> 为了保证应用的运行效率，大部分 API 调用都是异步的，对于异步调用的 API 均提供了 callback 和 Promise 两种方式，以下示例均采用 promise 函数，更多方式可以查阅[API 参考](../reference/apis-network-kit/js-apis-net-sharing-sys.md)。

## 基本概念

- WIFI 共享：通过 WIFI 热点共享网络。
- 蓝牙共享：通过蓝牙共享网络。
- USB 共享：通过 USB 共享网络。

## 约束

- 开发语言：JS
- 本模块首批接口从 API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 场景介绍

网络共享的典型场景有：

- 开启网络共享
- 停止网络共享
- 获取共享网络的数据流量

以下分别介绍具体开发方式。

## 接口说明

完整的 JS API 说明以及实例代码请参考：[网络共享](../reference/apis-network-kit/js-apis-net-sharing-sys.md)。

| 接口名                                                                   | 描述                                                                                                    |
| --------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------- |
| isSharingSupported(callback: AsyncCallback\<boolean>): void;    | 获取当前系统是否支持网络共享，使用 callback 方式作为异步方法。                                                       |
| isSharing(callback: AsyncCallback\<boolean>): void;             | 获取当前共享状态，使用 callback 方式作为异步方法。                                                                   |
| startSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;  | 开启共享，type 为共享类型，目前支持 Wifi 热点、蓝牙、USB，使用 callback 方式作为异步方法。                |
| stopSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;  | 停止指定类型共享，type 为共享类型，包括 Wifi 热点、蓝牙、USB，使用 callback 方式作为异步方法。             |
| getStatsRxBytes(callback: AsyncCallback\<number>): void;         | 获取共享接收数据量，单位 KB，使用 callback 方式作为异步方法。                                                        |
| getStatsTxBytes(callback: AsyncCallback\<number>): void;         | 获取共享发送数据量，单位 KB，使用 callback 方式作为异步方法。                                                        |
| getStatsTotalBytes(callback: AsyncCallback\<number>): void;      | 获取共享总数据流量，单位 KB，使用 callback 方式作为异步方法。                                                        |
| getSharingIfaces(state: SharingIfaceState, callback: AsyncCallback\<Array\<string>>): void;  | 获取指定状态的网卡名称，state 为状态，包括正在共享、可共享、共享错误，使用 callback 方式作为异步方法。 |
| getSharingState(type: SharingIfaceType, callback: AsyncCallback\<SharingIfaceState>): void;  | 获取指定类型共享状态，type 为类型，目前支持 Wifi 热点、蓝牙、USB，使用 callback 方式作为异步方法。  |
| getSharableRegexes(type: SharingIfaceType, callback: AsyncCallback\<Array\<string>>): void;  | 获取与指定类型匹配的网卡正则表达式列表，type 为类型，目前支持 Wifi 热点、蓝牙、USB，使用 callback 方式作为异步方法。 |
| on(type: 'sharingStateChange', callback: Callback\<boolean>): void;        | 注册共享状态改变监听，返回网络共享的状态。                                                                |
| off(type: 'sharingStateChange', callback?: Callback\<boolean>): void;      | 注销共享状态改变监听，返回网络共享的状态。                                                                |
| unction on(type: 'interfaceSharingStateChange', callback: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;    | 注册指定网卡共享状态改变监听。    |
| off(type: 'interfaceSharingStateChange', callback?: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void; | 注销指定网卡共享状态改变监听。             |
| on(type: 'sharingUpstreamChange', callback: Callback\<NetHandle>): void;               | 注册上行网卡改变监听。                                                                         |
| off(type: 'sharingUpstreamChange', callback?: Callback\<NetHandle>): void;             | 注销上行网卡改变监听。                                                                         |

## 开启网络共享

1. 从@kit.NetworkKit 中导入 sharing 命名空间。
2. 注册监听共享状态的改变。
3. 调用 startSharing 方法，来开启指定类型共享。
4. 接收到共享状态开启的回调，开启共享成功。

```ts
// 从@kit.NetworkKit中导入sharing命名空间
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 注册监听共享状态的改变
sharing.on('sharingStateChange', (data: boolean) => {
  console.log(JSON.stringify(data));
});

// 调用startSharing方法，来开启指定类型共享
sharing.startSharing(sharing.SharingIfaceType.SHARING_WIFI).then(() => {
  console.log('start wifi sharing successful');
}).catch((error: BusinessError) => {
  console.error('start wifi sharing failed');
});
```

## 停止网络共享

### 开发步骤

1. 从@kit.NetworkKit 中导入 sharing 命名空间。
2. 注册监听共享状态的改变。
3. 调用 stopSharing 方法，来停止指定类型共享。
4. 接收到共享状态关闭的回调，停止共享成功。

```ts
// 从@kit.NetworkKit中导入sharing命名空间
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 注册监听共享状态的改变
sharing.on('sharingStateChange', (data: boolean) => {
  console.log(JSON.stringify(data));
});

// 调用stopSharing方法，来停止指定类型共享
sharing.stopSharing(sharing.SharingIfaceType.SHARING_WIFI).then(() => {
  console.log('start wifi sharing successful');
}).catch((error: BusinessError) => {
  console.error('start wifi sharing failed');
});
```

## 获取共享网络的数据流量

### 开发步骤

1. 从@kit.NetworkKit 中导入 sharing 命名空间。
2. 调用 startSharing 方法，来开启指定类型共享。
3. 调用 getStatsTotalBytes 方法，来获取共享网络数据量。
4. 调用 stopSharing 方法，来停止指定类型共享，共享网络数据量清零。

```ts
// 从@kit.NetworkKit中导入sharing命名空间
import { sharing } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 调用startSharing方法，来开启指定类型共享
sharing.startSharing(sharing.SharingIfaceType.SHARING_WIFI).then(() => {
  console.log('start wifi sharing successful');
}).catch((error: BusinessError) => {
  console.error('start wifi sharing failed');
});

// 调用getStatsTotalBytes方法，来获取共享网络数据量
sharing.getStatsTotalBytes().then((data: number) => {
  console.log(JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.error(JSON.stringify(error));
});

// 调用stopSharing方法，来停止指定类型共享，共享网络数据量清零
sharing.stopSharing(sharing.SharingIfaceType.SHARING_WIFI).then(() => {
  console.log('start wifi sharing successful');
}).catch((error: BusinessError) => {
  console.error('start wifi sharing failed');
});

// 再次调用getStatsTotalBytes方法，共享网络数据量已清零
sharing.getStatsTotalBytes().then((data: number) => {
  console.log(JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```