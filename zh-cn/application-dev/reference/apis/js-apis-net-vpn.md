# @ohos.net.vpn (VPN管理)

VPN管理模块，支持VPN的启动和停止功能。

> **说明：**
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import vpn from '@ohos.net.vpn';
```

## vpn.createVpnConnection

createVpnConnection(context: AbilityContext): VpnConnection

创建一个VPN连接对象。

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| context | [AbilityContext](js-apis-inner-application-uiAbilityContext.md#uiabilitycontext) | 是   | 指定context                   |

**返回值：**

| 类型                               | 说明                    |
| :--------------------------------- | :---------------------- |
| [VpnConnection](#vpnconnection) | 返回一个VPN连接对象。 |

**错误码：**

以下错误码的详细介绍参见[VPN错误码](../errorcodes/errorcode-net-vpn.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401     | Parameter error.             |

**示例：**
Stage模型示例：

```ts
  // 获取context
  import UIAbility from '@ohos.app.ability.UIAbility';
  class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage){
      globalThis.context = this.context;
    }
  }
  let context = globalThis.context;
  let VpnConnection = vpn.createVpnConnection(context);
  console.info("vpn onInit: " + JSON.stringify(VpnConnection));
```

## VpnConnection

VPN连接对象。在调用VpnConnection的方法前，需要先通过[vpn.createVpnConnection](#vpncreatevpnconnection)创建VPN连接对象。

### setUp

setUp(config: VpnConfig, callback: AsyncCallback\<number\>): void

使用config创建一个vpn网络，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_VPN

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| config | [VpnConfig](#vpnconfig) | 是   | 指定VPN网络的配置信息。                   |
| callback | AsyncCallback\<number\>         | 是   | 回调函数，当成功启动VPN网络时，返回虚拟网卡的文件描述符fd, error为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍参见[VPN错误码](../errorcodes/errorcode-net-vpn.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.             |
| 401     | Parameter error.             |
| 2200001 | Invalid parameter value.             |
| 2200002 | Operation failed. Cannot connect to service.             |
| 2200003 | System internal error.         |
| 2203001 | VPN creation denied, please check the user type.         |
| 2203002 | VPN exist already, please execute destroy first.         |

**示例：**

```js
  import UIAbility from '@ohos.app.ability.UIAbility';
  class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage){
      globalThis.context = this.context;
    }
  }
  let VpnConnection = vpn.createVpnConnection(globalThis.context);

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
    trustedApplications:[],
    blockedApplications:[]
  }
  VpnConnection.setUp(config, (error, data) => {
    console.info(JSON.stringify(error));
    console.info("tunfd: " + JSON.stringify(data));
  })
```

### setUp

setUp(config: VpnConfig): Promise\<number\>

使用config创建一个vpn网络，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_VPN

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| config | [VpnConfig](#vpnconfig) | 是   | 指定VPN网络的配置信息。                   |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<number\> | 以Promise形式返回获取结果，返回指定虚拟网卡的文件描述符fd。 |

**错误码：**

以下错误码的详细介绍参见[VPN错误码](../errorcodes/errorcode-net-vpn.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.             |
| 401     | Parameter error.             |
| 2200001 | Invalid parameter value.             |
| 2200002 | Operation failed. Cannot connect to service.             |
| 2200003 | System internal error.         |
| 2203001 | VPN creation denied, please check the user type.         |
| 2203002 | VPN exist already, please execute destroy first.         |

**示例：**

```js
  import UIAbility from '@ohos.app.ability.UIAbility';
  class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage){
      globalThis.context = this.context;
    }
  }
  let VpnConnection = vpn.createVpnConnection(globalThis.context);

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
    trustedApplications:[],
    blockedApplications:[]
  }
  VpnConnection.setUp(config).then((data) => {
    console.info(TAG + "setUp success, tunfd: " + JSON.stringify(data))
  }).catch(err => {
    console.info(TAG + "setUp fail" + JSON.stringify(err))
  })
```

### protect

protect(socketFd: number, callback: AsyncCallback\<void\>): void

保护套接字不受VPN连接影响，通过该套接字发送的数据将直接基于物理网络收发，因此其流量不会通过VPN转发，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_VPN

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| socketFd | number | 是   | 指定保护的socketfd, 该文件描述符通过[getSocketFd](js-apis-socket.md#getsocketfd10)获取。                   |
| callback | AsyncCallback\<void\>         | 是   | 回调函数，成功时，error为undefined，失败返回错误码错误信息。 |

**错误码：**

以下错误码的详细介绍参见[VPN错误码](../errorcodes/errorcode-net-vpn.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.        |
| 401     | Parameter error.       |
| 2200001 | Invalid parameter value.        |
| 2200002 | Operation failed. Cannot connect to service.    |
| 2200003 | System internal error.         |
| 2203004 | Invalid socket file descriptor.         |

**示例：**

```js
  import socket from "@ohos.net.socket";
  import UIAbility from '@ohos.app.ability.UIAbility';
  class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage){
      globalThis.context = this.context;
    }
  }
  let VpnConnection = vpn.createVpnConnection(globalThis.context);

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
    VpnConnection.protect(tunnelfd, (error) => {
      console.info(JSON.stringify(error));
    })
  })
```

### protect

protect(socketFd: number): Promise\<void\>

保护套接字不受VPN连接影响，通过该套接字发送的数据将直接基于物理网络收发，因此其流量不会通过VPN转发, 使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_VPN

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| socketFd | number | 是   | 指定保护的socketfd, 该文件描述符通过[getSocketFd](js-apis-socket.md#getsocketfd10-1)获取。                   |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void\> | 以Promise形式返回设定结果，失败返回错误码错误信息。 |

**错误码：**

以下错误码的详细介绍参见[VPN错误码](../errorcodes/errorcode-net-vpn.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.        |
| 401     | Parameter error.       |
| 2200001 | Invalid parameter value.        |
| 2200002 | Operation failed. Cannot connect to service.    |
| 2200003 | System internal error.         |
| 2203004 | Invalid socket file descriptor.         |

**示例：**

```js
  import socket from "@ohos.net.socket";
  import UIAbility from '@ohos.app.ability.UIAbility';
  class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage){
      globalThis.context = this.context;
    }
  }
  let VpnConnection = vpn.createVpnConnection(globalThis.context);

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
    VpnConnection.protect(tunnelfd).then(() => {
      console.info("protect success.")
    }).catch(err => {
      console.info("protect fail" + JSON.stringify(err))
    })
  })
```

### destroy

destroy(callback: AsyncCallback\<void\>): void

销毁启动的VPN网络，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_VPN

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void\>         | 是   | 回调函数，成功时，error为undefined，失败返回错误码错误信息。 |

**错误码：**

以下错误码的详细介绍参见[VPN错误码](../errorcodes/errorcode-net-vpn.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.        |
| 401     | Parameter error.       |
| 2200002 | Operation failed. Cannot connect to service.    |
| 2200003 | System internal error.         |

**示例：**

```js
  import UIAbility from '@ohos.app.ability.UIAbility';
  class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage){
      globalThis.context = this.context;
    }
  }
  let VpnConnection = vpn.createVpnConnection(globalThis.context);
  VpnConnection.destroy((error) => {
    console.info(JSON.stringify(error));
  })
```

### destroy

destroy(): Promise\<void\>

销毁启动的VPN网络，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_VPN

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void\> | 以Promise形式返回设定结果，失败返回错误码错误信息。 |

**错误码：**

以下错误码的详细介绍参见[VPN错误码](../errorcodes/errorcode-net-vpn.md)。

| 错误码ID | 错误信息                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.        |
| 2200002 | Operation failed. Cannot connect to service.    |
| 2200003 | System internal error.         |

**示例：**

```js
  import UIAbility from '@ohos.app.ability.UIAbility';
  class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage){
      globalThis.context = this.context;
    }
  }
  let VpnConnection = vpn.createVpnConnection(globalThis.context);
  VpnConnection.destroy().then(() => {
    console.info("destroy success.")
  }).catch(err => {
    console.info("destroy fail" + JSON.stringify(err))
  });
```

## VpnConfig

VPN配置参数。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Vpn

| 名称 | 类型 | 必填 | 说明 |
| ------- | ------ | -- |------------------------------ |
| addresses | Array\<[LinkAddress](js-apis-net-connection.md#linkaddress8)\> | 是 | VPN虚拟网卡的IP地址。 |
| routes  | Array\<[RouteInfo](js-apis-net-connection.md#routeinfo8)\> | 否 | VPN虚拟网卡的路由信息。 |
| dnsAddresses    | Array\<string\> | 否 | DNS服务器地址信息。 |
| searchDomains | Array\<string\> | 否 | DNS的搜索域列表。 |
| mtu  | number | 否 | 最大传输单元MTU值(单位:字节)。 |
| isIPv4Accepted    | boolean | 否 | 是否支持IPV4, 默认值为true。 |
| isIPv6Accepted    | boolean | 否 | 是否支持IPV6, 默认值为flase。 ||
| isLegacy    | boolean | 否 | 是否支持内置VPN, 默认值为flase。 |
| isBlocking    | boolean | 否 | 是否阻塞模式, 默认值为flase。 |
| trustedApplications    | Array\<string\> | 否 | 白名单信息, string类型表示的包名。 |
| blockedApplications    | Array\<string\> | 否 | 黑名单信息, string类型表示的包名。 |
