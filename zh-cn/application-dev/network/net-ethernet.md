# 以太网连接（仅对系统应用开放）

## 简介

以太网连接的功能是提供支持设备通过硬件接口，以插入网线的形式访问互联网的能力。 设备接入网线后，可以获取动态分配的IP地址，子网掩码，Gateway，DNS等一系列网络属性；通过静态模式，手动配置与获取设备的网络属性。

> **说明：**
> 为了保证应用的运行效率，大部分API调用都是异步的，对于异步调用的API均提供了callback和Promise两种方式，以下示例均采用promise函数，更多方式可以查阅[API参考](../reference/apis-network-kit/js-apis-net-ethernet-sys.md)。

## 约束

- 开发语言：JS
- 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 场景介绍

以太网连接的典型场景有：

- DHCP模式，通过动态分配IP地址，子网掩码，Gateway，DNS等一系列网络属性，使能访问网络。
- 静态模式，通过静态配置IP地址，子网掩码，Gateway，DNS等一系列网络属性，使能访问网络。

以下分别介绍具体开发方式。

## 接口说明

完整的JS API说明以及实例代码请参考：[以太网连接](../reference/apis-network-kit/js-apis-net-ethernet-sys.md)。

| 类型 | 接口 | 功能说明 |
| ---- | ---- | ---- |
| setIfaceConfig(iface: string, ic: InterfaceConfiguration, callback: AsyncCallback\<void>): void | 配置指定以太网的网络属性，iface为网口名称，ic为配置信息，调用callback。 | 设置网络接口配置信息。 |
| getIfaceConfig(iface: string, callback: AsyncCallback\<InterfaceConfiguration>): void | 获取指定以太网的网络属性，iface为网口名称，调用callback。 | 获取指定网络接口信息。 |
| isIfaceActive(iface: string, callback: AsyncCallback\<number>): void | 判断指定网口是否已激活，iface为网卡名称（无参为是否有激活网口），调用callback。 | 判断接口是否已激活。 |
| getAllActiveIfaces(callback: AsyncCallback\<Array\<string>>): void | 获取所有活动的网络接口，调用callback。 | 获取活动的网络接口。 |
| on(type: 'interfaceStateChange', callback: Callback\<{ iface: string, active: boolean }\>): void | 注册网络接口监听函数。 | 注册网卡热插拔事件。 |
| off(type: 'interfaceStateChange', callback?: Callback\<{ iface: string, active: boolean }\>): void | 解除注册网络接口监听函数。 | 注销网卡热插拔事件。 |

## 以太网连接-DHCP模式

1. 设备通过硬件接口，插入网线。
2. 从@kit.NetworkKit中导入ethernet命名空间。
3. 调用getAllActiveIfaces方法，获取所有激活的有线网卡名称，如：“eth0”，“eth1”。
4. 用户态通过isIfaceActive方法，来判断网口“eth0”是否已激活。
5. 用户态通过getIfaceConfig方法，来获取指定网口“eth0”的网络属性，未设置过的以太网络默认为DHCP模式，获取自动分配的网络属性。

```ts
// 从@kit.NetworkKit中导入ethernet命名空间
import { ethernet } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// getAllActiveIfaces获取所有活动的网络设备名称
ethernet.getAllActiveIfaces().then((data: string[]) => {
  console.log("getAllActiveIfaces promise data.length = " + JSON.stringify(data.length));
  for (let i = 0; i < data.length; i++) {
    console.log("getAllActiveIfaces promise  = " + JSON.stringify(data[i]));
  }
}).catch((error:BusinessError) => {
  console.error("getAllActiveIfaces promise error = " + JSON.stringify(error));
});

// isIfaceActive判断指定网口是否已激活
ethernet.isIfaceActive("eth0").then((data: number) => {
  console.log("isIfaceActive promise = " + JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.error("isIfaceActive promise error = " + JSON.stringify(error));
});

// getIfaceConfig获取指定以太网的网络属性
ethernet.getIfaceConfig("eth0").then((data: ethernet.InterfaceConfiguration) => {
  console.log("getIfaceConfig promise mode = " + JSON.stringify(data.mode));
  console.log("getIfaceConfig promise ipAddr = " + JSON.stringify(data.ipAddr));
  console.log("getIfaceConfig promise route = " + JSON.stringify(data.route));
  console.log("getIfaceConfig promise gateway = " + JSON.stringify(data.gateway));
  console.log("getIfaceConfig promise netMask = " + JSON.stringify(data.netMask));
  console.log("getIfaceConfig promise dnsServers = " + JSON.stringify(data.dnsServers));
}).catch((error: BusinessError) => {
  console.error("getIfaceConfig promise error = " + JSON.stringify(error));
});
```

## 以太网连接-静态模式

### 开发步骤

1. 设备通过硬件接口，插入网线。
2. 从@kit.NetworkKit中导入ethernet命名空间。
3. 用户态通过getAllActiveIfaces方法，来获取所有活动的网络设备名称，如：“eth0”，“eth1”。
4. 用户态通过isIfaceActive方法，来判断网口“eth0”是否已激活。
5. 用户态调用setIfaceConfig方法，来设置指定网口"eth0"为静态模式，手动IP地址，子网掩码，Gateway，DNS等网络属性。
6. 用户态通过getIfaceConfig方法，来获取指定网口“eth0”的静态网络属性。

```ts
// 从@kit.NetworkKit中导入ethernet命名空间
import { ethernet } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// getAllActiveIfaces获取所有活动的网络设备名称
ethernet.getAllActiveIfaces().then((data: string[]) => {
  console.log("getAllActiveIfaces promise data.length = " + JSON.stringify(data.length));
  for (let i = 0; i < data.length; i++) {
    console.log("getAllActiveIfaces promise  = " + JSON.stringify(data[i]));
  }
}).catch((error:BusinessError) => {
  console.error("getAllActiveIfaces promise error = " + JSON.stringify(error));
});

// isIfaceActive判断指定网口是否已激活
ethernet.isIfaceActive("eth0").then((data: number) => {
  console.log("isIfaceActive promise = " + JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.error("isIfaceActive promise error = " + JSON.stringify(error));
});

// setIfaceConfig配置指定以太网的网络属性
let config: ethernet.InterfaceConfiguration = {
  mode: 0,
  ipAddr: "192.168.xx.xxx",
  route: "192.168.xx.xxx",
  gateway: "192.168.xx.xxx",
  netMask: "255.255.255.0",
  dnsServers: "1.1.1.1"
};

const setConfigPromise = ethernet.setIfaceConfig("eth0", config);

setConfigPromise.then(() => {
  console.log("setIfaceConfig promise ok");
}).catch((error: BusinessError)  => {
  console.error("setIfaceConfig promise error = " + JSON.stringify(error));
});

// getIfaceConfig获取指定以太网的网络属性
ethernet.getIfaceConfig("eth0").then((data: ethernet.InterfaceConfiguration) => {
  console.log("getIfaceConfig promise mode = " + JSON.stringify(data.mode));
  console.log("getIfaceConfig promise ipAddr = " + JSON.stringify(data.ipAddr));
  console.log("getIfaceConfig promise route = " + JSON.stringify(data.route));
  console.log("getIfaceConfig promise gateway = " + JSON.stringify(data.gateway));
  console.log("getIfaceConfig promise netMask = " + JSON.stringify(data.netMask));
  console.log("getIfaceConfig promise dnsServers = " + JSON.stringify(data.dnsServers));
}).catch((error: BusinessError) => {
  console.error("getIfaceConfig promise error = " + JSON.stringify(error));
});
```

## 监听网络设备接口状态变化

### 开发步骤

1. 从@kit.NetworkKit中导入ethernet命名空间。
2. 调用该对象的on()方法，订阅interfaceStateChange事件。可以根据业务需要订阅此消息。
3. 订阅interfaceStateChange事件后，回调函数会在网卡设备的接口状态发生变化时触发。
4. 调用该对象的off()方法，取消订阅interfaceStateChange事件。

```ts
// 从@kit.NetworkKit中导入ethernet命名空间
import { ethernet } from '@kit.NetworkKit';

// 订阅interfaceStateChange事件
class EthernetData{
  iface: string = ""
  active: boolean = false
}

ethernet.on('interfaceStateChange', (data: EthernetData) => {
  console.log(JSON.stringify(data));
});

// 取消事件订阅
ethernet.off('interfaceStateChange');
```
