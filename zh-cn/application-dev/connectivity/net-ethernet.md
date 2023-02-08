# 以太网连接

## 简介
以太网连接的功能是提供支持设备通过硬件接口，以插入网线的形式访问互联网的能力。
设备接入网线后，可以获取动态分配的IP地址，xxx等一系列网络属性；也可以通过静态模式，手动配置与获取设备的网络属性。

> **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 约束
-   开发语言：C++ JS
-   系统：linux内核

## 场景介绍
以太网连接的典型场景有：
-   DHCP模式，通过动态分配IP地址，子网掩码，Gateway，DNS等一系列网络属性，使能访问网络。
-   静态模式，通过静态配置IP地址，子网掩码，Gateway，DNS等一系列网络属性，使能访问网络。

以下分别介绍具体开发方式。

## 接口说明
完整的JS API说明以及实例代码请参考：[以太网连接](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-net-ethernet.md)。

| 类型 | 接口 | 功能说明 |
| ---- | ---- | ---- |
| ohos.net.ethernet | function setIfaceConfig(iface: string, ic: InterfaceConfiguration, callback: AsyncCallback\<void>): void | 配置指定以太网的网络属性，iface为网口名称，ic为配置信息，调用callback |
| ohos.net.ethernet | function setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<boolean>; | 配置指定以太网的网络属性，iface为网口名称，ic为配置信息，返回promise |
| ohos.net.ethernet | function getIfaceConfig(iface: string, callback: AsyncCallback\<InterfaceConfiguration>): void | 获取指定以太网的网络属性，iface为网口名称，调用callback |
| ohos.net.ethernet | function getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>; | 获取指定以太网的网络属性，iface为网口名称，返回promise |
| ohos.net.ethernet | function isIfaceActive(iface: string, callback: AsyncCallback\<number>): void | 判断指定网口是否已激活，iface为网卡名称（无参为是否有激活网口），调用callback |
| ohos.net.ethernet | function isIfaceActive(iface: string): Promise\<number>; | 判断指定网口是否已激活，iface为网卡名称（无参为是否有激活网口），返回promise |
| ohos.net.ethernet | function getAllActiveIfaces(callback: AsyncCallback\<Array\<string>>): void; | 获取所有活动的网络接口，调用callback |
| ohos.net.ethernet | function getAllActiveIfaces(): Promise\<Array\<string>>; | 获取所有活动的网络接口，返回promise |

## 以太网连接-DHCP模式

### 开发步骤

1. 设备通过硬件接口，插入网线。
2. 从@ohos.net.ethernet中导入ethernet命名空间。
3. 调用getAllActiveIfaces方法，获取所有激活的有线网卡名称，如：“eth0”，“eth1”。
4. 用户态通过isIfaceActive方法，来判断网口“eth0”是否已激活。
5. 用户态通过getIfaceConfig方法，来获取指定网口“eth0”的网络属性，未设置过的以太网络默认为DHCP模式，获取自动分配的网络属性。

```js
   // 从@ohos.net.ethernet中导入ethernet命名空间
   import ethernet from '@ohos.net.ethernet'

   // getAllActiveIfaces获取所有活动的网络设备名称
   ethernet.getAllActiveIfaces((error, data) => {
       if (error) {
           console.log("getAllActiveIfaces callback error = " + error);
       } else {
           console.log("getAllActiveIfaces callback data.length = " + data.length);
           for (let i = 0; i < data.length; i++) {
               console.log("getAllActiveIfaces callback = " + data[i]);
           }
       }
   });

   // isIfaceActive判断指定网口是否已激活
   ethernet.isIfaceActive("eth0", (error, data) => {
       if (error) {
           console.log("isIfaceActive callback error = " + error);
       } else {
           console.log("isIfaceActive callback = " + data);
       }
   });

   // getIfaceConfig获取指定以太网的网络属性
   ethernet.getIfaceConfig("eth0", (error, data) => {
       if (error) {
           console.log("getIfaceConfig  callback error = " + error);
       } else {
           console.log("getIfaceConfig callback mode = " + data.mode);
           console.log("getIfaceConfig callback ipAddr = " + data.ipAddr);
           console.log("getIfaceConfig callback routeAddr = " + data.routeAddr);
           console.log("getIfaceConfig callback gateAddr = " + data.gateAddr);
           console.log("getIfaceConfig callback maskAddr = " + data.maskAddr);
           console.log("getIfaceConfig callback dns0Addr = " + data.dns0Addr);
           console.log("getIfaceConfig callback dns1Addr = " + data.dns1Addr);
       }
   });
```
## 以太网连接-静态模式

### 开发步骤

1. 设备通过硬件接口，插入网线。
2. 从@ohos.net.ethernet中导入ethernet命名空间。
3. 用户态通过getAllActiveIfaces方法，来获取所有活动的网络设备名称，如：“eth0”，“eth1”。
4. 用户态通过isIfaceActive方法，来判断网口“eth0”是否已激活。
5. 用户态调用setIfaceConfig方法，来设置指定网口"eth0"为静态模式，手动IP地址，子网掩码，Gateway，DNS等网络属性。
6. 用户态通过getIfaceConfig方法，来获取指定网口“eth0”的静态网络属性。

```js
   // 从@ohos.net.ethernet中导入ethernet命名空间
   import ethernet from '@ohos.net.ethernet'

   // getAllActiveIfaces获取所有活动的网络设备名称
   ethernet.getAllActiveIfaces((error, data) => {
       if (error) {
           console.log("getAllActiveIfaces callback error = " + error);
       } else {
           console.log("getAllActiveIfaces callback data.length = " + data.length);
           for (let i = 0; i < data.length; i++) {
               console.log("getAllActiveIfaces callback = " + data[i]);
           }
       }
   });

   // isIfaceActive判断指定网口是否已激活
   ethernet.isIfaceActive("eth0", (error, data) => {
       if (error) {
           console.log("isIfaceActive callback error = " + error);
       } else {
           console.log("isIfaceActive callback = " + data);
       }
   });

   // setIfaceConfig配置指定以太网的网络属性
   ethernet.setIfaceConfig("eth0", {mode:ethernet.STATIC,ipAddr:"192.168.xx.xx", routeAddr:"192.168.xx.xx",
       gateAddr:"192.168.xx.xx", maskAddr:"255.255.xx.xx", dnsAddr0:"1.1.xx.xx", dnsAddr1:"2.2.xx.xx"},(error) => {
       if (error) {
           console.log("setIfaceConfig callback error = " + error);
       } else {
           console.log("setIfaceConfig callback ok ");
       }
   });

   // getIfaceConfig获取指定以太网的网络属性
   ethernet.getIfaceConfig("eth0", (error, data) => {
       if (error) {
           console.log("getIfaceConfig  callback error = " + error);
       } else {
           console.log("getIfaceConfig callback mode = " + data.mode);
           console.log("getIfaceConfig callback ipAddr = " + data.ipAddr);
           console.log("getIfaceConfig callback routeAddr = " + data.routeAddr);
           console.log("getIfaceConfig callback gateAddr = " + data.gateAddr);
           console.log("getIfaceConfig callback maskAddr = " + data.maskAddr);
           console.log("getIfaceConfig callback dns0Addr = " + data.dns0Addr);
           console.log("getIfaceConfig callback dns1Addr = " + data.dns1Addr);
       }
   });
```
