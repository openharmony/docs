# VPN管理

## 简介

VPN即虚拟专网（VPN-Virtual Private Network）在公用网络上建立专用网络的技术。整个VPN网络的任意两个节点之间的连接并没有传统专网所需的端到端的物理链路，而是架构在公用网络服务商所提供的网络平台（如Internet）之上的逻辑网络，用户数据在逻辑链路中传输。

> **说明：**
> 为了保证应用的运行效率，大部分API调用都是异步的，对于异步调用的API均提供了callback和Promise两种方式，以下示例均采用callback函数，更多方式可以查阅[API参考](../reference/apis/js-apis-net-vpn.md)。

以下分别介绍具体开发方式。

## 接口说明

完整的JS API说明以及实例代码请参考：[vpn链接](../reference/apis/js-apis-net-vpn.md)。

| 类型 | 接口 | 功能说明 |
| ---- | ---- | ---- |
| ohos.net.vpn | setUp(config: VpnConfig, callback: AsyncCallback\<number\>): void | 建立一个VPN网络，使用callback方式作为异步方法。 |
| ohos.net.vpn | protect(socketFd: number, callback: AsyncCallback\<void\>): void | 保护VPN的隧道，使用callback方式作为异步方法。 |
| ohos.net.vpn | destroy(callback: AsyncCallback\<void\>): void | 销毁一个VPN网络，使用callback方式作为异步方法。 |

## 启动VPN的流程

1. 建立一个VPN的网络隧道，下面以TCP隧道为例。
2. 保护前一步建立的TCP隧道。
3. 建立一个VPN网络。
4. 处理虚拟网卡的数据，如：读写操作。

```js
import vpn from '@ohos.net.vpn'

// FA模型获取context
import featureAbility from '@ohos.ability.featureAbility';
let context = featureAbility.getContext();

// Stage模型获取context
import UIAbility from '@ohos.app.ability.UIAbility';
class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage){
    globalThis.context = this.context;
  }
}
let context = globalThis.context;

// 获取VpnConnection对象
VpnConnection = vpn.createVpnConnection(context);
console.info("vpn onInit: " + JSON.stringify(VpnConnection));

// 建立TCP 隧道
import socket from "@ohos.net.socket";
var tcp = socket.constructTCPSocketInstance();
tcp.bind({
  address: "0.0.0.0",
  family: 1
})
let connectAddress = {
  address: "192.168.1.11",
  port: 8888,
  family: 1
};
tcp.connect({
  address: connectAddress, timeout: 6000
})
tcp.getSocketFd().then((tunnelfd) => {
  console.info("tunenlfd: " + tunnelfd);
  VpnConnection.protect(tunnelfd, (error, data) => {
    console.info(JSON.stringify(error));
    console.info(JSON.stringify(data));
  })
})

// 建立 VPN 网络
let config = {
  addresses: [{
    address: {
      address: "10.0.0.5",
      family: 1
    },
    prefixLength: 24,
  }],
  routes: [],
  mtu: 1400,
  dnsAddresses:[
    "114.114.114.114"
  ],
  acceptedApplications:[],
  refusedApplications:[]
}
let tunfd = 0
VpnConnection.setUp(config).then((data) => {
  console.info("setUp success, tunfd: " + JSON.stringify(data))
  tunfd = data
  StartReadFromTun(data)
}).catch(err => {
  console.info("setUp fail" + JSON.stringify(err))
})

// 处理虚拟网卡的数据
import fs from '@ohos.file.fs';
async function StartReadFromTun(tunFd) {
  let buf = new ArrayBuffer(4096);
  while (tunFd) {
    await sleep(1)
    fs.read(tunFd, buf).then((readLen) => {
      console.info("read file data succeed, len: ", readLen);
      await tcp.send({ data: buffer.slice(0, readLen) })
    }).catch((err) => {
      console.info("read file data failed with error message: " + err.message + ", error code: " + err.code);
    });
  }
}

tcp.on('message', (data) => {
  console.log("on message:" + JSON.stringify(data.message) + ", remoteInfo:" + JSON.stringify(data.remoteInfo));
  if (data.message) {
    if (!tunfd) {
      console.info("tunfd is null")
      return;
    }
    fs.write(tunfd, buffer).then(function (number) {
      console.info("write data to file succeed and size is:" + number);
    }).catch(function (err) {
      console.info("write data to file failed with error:" + err);
    });
  }
})
```
