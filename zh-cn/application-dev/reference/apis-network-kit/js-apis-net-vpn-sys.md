# @ohos.net.vpn (VPN 管理)（系统接口）

VPN 管理模块，支持 VPN 的启动和停止功能。
本模块是操作系统提供的内置VPN功能，允许用户通过系统的网络设置进行VPN连接，通常提供的功能较少，而且有比较严格的限制。

> **说明：**
> 本模块首批接口从 API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块为系统接口。

## 导入模块

```js
import { vpn } from '@kit.NetworkKit';
```

## vpn.createVpnConnection

createVpnConnection(context: AbilityContext): VpnConnection

创建一个 VPN 连接对象。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**参数：**

| 参数名  | 类型                                                                             | 必填 | 说明         |
| ------- | -------------------------------------------------------------------------------- | ---- | ------------ |
| context | [AbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontext) | 是   | 指定 context。 |

**返回值：**

| 类型                            | 说明                    |
| :------------------------------ | :---------------------- |
| [VpnConnection](#vpnconnection) | 返回一个 VPN 连接对象。 |

**错误码：**

以下错误码的详细介绍参见[VPN 错误码](errorcode-net-vpn.md)。

| 错误码 ID | 错误信息         |
| --------- | ---------------- |
| 202       | Non-system applications use system APIs.         |
| 401       | Parameter error.                                 |

**示例：**

>**说明：** 
>
>在本文档的示例中，通过this.context来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

Stage 模型示例：

```ts
import { vpn } from '@kit.NetworkKit';
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  private context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
  private VpnConnection: vpn.VpnConnection = vpn.createVpnConnection(this.context);
  functiontest()
  {
    console.info("vpn createVpnConnection: " + JSON.stringify(this.VpnConnection));
  }
  build() {  }
}
```

## VpnConnection

VPN 连接对象。在调用 VpnConnection 的方法前，需要先通过[vpn.createVpnConnection](#vpncreatevpnconnection)创建 VPN 连接对象。

### setUp

setUp(config: VpnConfig, callback: AsyncCallback\<number\>): void

使用 config 创建一个 vpn 网络，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_VPN

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                                                               |
| -------- | ----------------------- | ---- | -------------------------------------------------------------------------------------------------- |
| config   | [VpnConfig](#vpnconfig) | 是   | 指定 VPN 网络的配置信息。                                                                          |
| callback | AsyncCallback\<number\> | 是   | 回调函数，当成功启动 VPN 网络时，返回虚拟网卡的文件描述符 fd, error 为 undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍参见[VPN 错误码](errorcode-net-vpn.md)。

| 错误码 ID | 错误信息                                         |
| --------- | ------------------------------------------------ |
| 201       | Permission denied.                               |
| 202       | Non-system applications use system APIs.         |
| 401       | Parameter error.                                 |
| 2200001   | Invalid parameter value.                         |
| 2200002   | Operation failed. Cannot connect to service.     |
| 2200003   | System internal error.                           |
| 2203001   | VPN creation denied. Check the user type.        |
| 2203002   | VPN already exists.                              |

**示例：**

>**说明：** 
>
>在本文档的示例中，通过this.context来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

```js
import { vpn } from '@kit.NetworkKit';
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  private context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
  private VpnConnection: vpn.VpnConnection = vpn.createVpnConnection(this.context);
  SetUp(): void {
    let config: vpn.VpnConfig = {
      addresses: [{
        address: {
          address: "10.0.0.5",
          family: 1
        },
        prefixLength: 24
      }],
      mtu: 1400,
      dnsAddresses: ["114.114.114.114"]
    }
    this.VpnConnection.setUp(config, (error: BusinessError, data: number) => {
      console.error(JSON.stringify(error));
      console.info("tunfd: " + JSON.stringify(data));
    });
  }
  build() { }
}
```

### setUp

setUp(config: VpnConfig): Promise\<number\>

使用 config 创建一个 vpn 网络，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_VPN

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**参数：**

| 参数名 | 类型                    | 必填 | 说明                      |
| ------ | ----------------------- | ---- | ------------------------- |
| config | [VpnConfig](#vpnconfig) | 是   | 指定 VPN 网络的配置信息。 |

**返回值：**

| 类型              | 说明                                                           |
| ----------------- | -------------------------------------------------------------- |
| Promise\<number\> | 以 Promise 形式返回获取结果，返回指定虚拟网卡的文件描述符 fd。 |

**错误码：**

以下错误码的详细介绍参见[VPN 错误码](errorcode-net-vpn.md)。

| 错误码 ID | 错误信息                                         |
| --------- | ------------------------------------------------ |
| 201       | Permission denied.                               |
| 202       | Non-system applications use system APIs.         |
| 401       | Parameter error.                                 |
| 2200001   | Invalid parameter value.                         |
| 2200002   | Operation failed. Cannot connect to service.     |
| 2200003   | System internal error.                           |
| 2203001   | VPN creation denied. Check the user type.        |
| 2203002   | VPN already exists.                              |

**示例：**

>**说明：** 
>
>在本文档的示例中，通过this.context来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

```js
import { vpn } from '@kit.NetworkKit';
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  private context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
  private VpnConnection: vpn.VpnConnection = vpn.createVpnConnection(this.context);
  SetUp(): void {
    let config: vpn.VpnConfig = {
      addresses: [{
        address: {
          address: "10.0.0.5",
          family: 1
        },
        prefixLength: 24
      }],
      mtu: 1400,
      dnsAddresses: ["114.114.114.114"]
    }
    this.VpnConnection.setUp(config).then((data: number) => {
      console.info("setUp success, tunfd: " + JSON.stringify(data));
    }).catch((err: BusinessError) => {
      console.error("setUp fail" + JSON.stringify(err));
    });
  }
  build() { }
}
```

### protect

protect(socketFd: number, callback: AsyncCallback\<void\>): void

保护套接字不受 VPN 连接影响，通过该套接字发送的数据将直接基于物理网络收发，因此其流量不会通过 VPN 转发，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_VPN

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                                                                      |
| -------- | --------------------- | ---- | ----------------------------------------------------------------------------------------- |
| socketFd | number                | 是   | 指定保护的 socketfd, 该文件描述符通过[getSocketFd](js-apis-socket.md#getsocketfd10)获取。 |
| callback | AsyncCallback\<void\> | 是   | 回调函数，成功时，error 为 undefined，失败返回错误码错误信息。                            |

**错误码：**

以下错误码的详细介绍参见[VPN 错误码](errorcode-net-vpn.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |
| 2203004   | Invalid socket file descriptor.              |

**示例：**

>**说明：** 
>
>在本文档的示例中，通过this.context来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

```js
import { socket, vpn } from '@kit.NetworkKit';
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  private context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
  private VpnConnection: vpn.VpnConnection = vpn.createVpnConnection(this.context);

  Protect(): void {
    let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
    let ipAddress: socket.NetAddress = {
      address: "0.0.0.0"
    }
    tcp.bind(ipAddress);
    let netAddress: socket.NetAddress = {
      address: "192.168.1.11",
      port: 8888
    }
    let addressConnect: socket.TCPConnectOptions = {
      address: netAddress,
      timeout: 6000
    }
    tcp.connect(addressConnect);
    tcp.getSocketFd().then((tunnelfd: number) => {
      console.info("tunenlfd: " + tunnelfd);
      this.VpnConnection.protect(tunnelfd, (error: BusinessError) => {
        console.error(JSON.stringify(error));
      });
    });
  }
  build() { }
}
```

### protect

protect(socketFd: number): Promise\<void\>

保护套接字不受 VPN 连接影响，通过该套接字发送的数据将直接基于物理网络收发，因此其流量不会通过 VPN 转发, 使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_VPN

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------------------------------------- |
| socketFd | number | 是   | 指定保护的 socketfd, 该文件描述符通过[getSocketFd](js-apis-socket.md#getsocketfd10-1)获取。 |

**返回值：**

| 类型            | 说明                                                  |
| --------------- | ----------------------------------------------------- |
| Promise\<void\> | 以 Promise 形式返回设定结果，失败返回错误码错误信息。 |

**错误码：**

以下错误码的详细介绍参见[VPN 错误码](errorcode-net-vpn.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |
| 2203004   | Invalid socket file descriptor.              |

**示例：**

>**说明：** 
>
>在本文档的示例中，通过this.context来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

```js
import { socket, vpn } from '@kit.NetworkKit';
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  private context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
  private VpnConnection: vpn.VpnConnection = vpn.createVpnConnection(this.context);

  Protect(): void {
    let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
    let ipAddress: socket.NetAddress = {
      address: "0.0.0.0"
    }
    tcp.bind(ipAddress);
    let netAddress: socket.NetAddress = {
      address: "192.168.1.11",
      port: 8888
    }
    let addressConnect: socket.TCPConnectOptions = {
      address: netAddress,
      timeout: 6000
    }
    tcp.connect(addressConnect);
    tcp.getSocketFd().then((tunnelfd: number) => {
      console.info("tunenlfd: " + tunnelfd);
      this.VpnConnection.protect(tunnelfd).then(() => {
        console.info("protect success.");
      }).catch((err: BusinessError) => {
        console.error("protect fail" + JSON.stringify(err));
      });
    });
  }
  build() { }
}
```

### destroy

destroy(callback: AsyncCallback\<void\>): void

销毁启动的 VPN 网络，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_VPN

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                                           |
| -------- | --------------------- | ---- | -------------------------------------------------------------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数，成功时，error 为 undefined，失败返回错误码错误信息。 |

**错误码：**

以下错误码的详细介绍参见[VPN 错误码](errorcode-net-vpn.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**示例：**

>**说明：** 
>
>在本文档的示例中，通过this.context来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

```js
import { vpn } from '@kit.NetworkKit';
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  private context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
  private VpnConnection: vpn.VpnConnection = vpn.createVpnConnection(this.context);
  Destroy(): void {
    this.VpnConnection.destroy((error: BusinessError) => {
      console.error(JSON.stringify(error));
    });
  }
  build() { }
}
```

### destroy

destroy(): Promise\<void\>

销毁启动的 VPN 网络，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_VPN

**系统能力**：SystemCapability.Communication.NetManager.Vpn

**返回值：**

| 类型            | 说明                                                  |
| --------------- | ----------------------------------------------------- |
| Promise\<void\> | 以 Promise 形式返回设定结果，失败返回错误码错误信息。 |

**错误码：**

以下错误码的详细介绍参见[VPN 错误码](errorcode-net-vpn.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 401       | Parameter error.                                 |
| 202       | Non-system applications use system APIs.     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**示例：**

>**说明：** 
>
>在本文档的示例中，通过this.context来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

```js
import { vpn } from '@kit.NetworkKit';
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  private context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
  private VpnConnection: vpn.VpnConnection = vpn.createVpnConnection(this.context);
  Destroy(): void {
    this.VpnConnection.destroy().then(() => {
      console.info("destroy success.");
    }).catch((err: BusinessError) => {
      console.error("destroy fail" + JSON.stringify(err));
    });
  }
  build() { }
}
```

## VpnConfig

VPN 配置参数。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Vpn

| 名称                | 类型                                                           | 必填 | 说明                                |
| ------------------- | -------------------------------------------------------------- | ---- | ----------------------------------- |
| addresses           | Array\<[LinkAddress](js-apis-net-connection.md#linkaddress)\> | 是   | VPN 虚拟网卡的 IP 地址。            |
| routes              | Array\<[RouteInfo](js-apis-net-connection.md#routeinfo)\>     | 否   | VPN 虚拟网卡的路由信息。            |
| dnsAddresses        | Array\<string\>                                                | 否   | DNS 服务器地址信息。                |
| searchDomains       | Array\<string\>                                                | 否   | DNS 的搜索域列表。                  |
| mtu                 | number                                                         | 否   | 最大传输单元 MTU 值(单位:字节)。     |
| isIPv4Accepted      | boolean                                                        | 否   | 是否支持 IPV4, 默认值为 true。      |
| isIPv6Accepted      | boolean                                                        | 否   | 是否支持 IPV6, 默认值为 flase。     |
| isLegacy            | boolean                                                        | 否   | 是否支持内置 VPN, 默认值为 flase。   |
| isBlocking          | boolean                                                        | 否   | 是否阻塞模式, 默认值为 flase。       |
| trustedApplications | Array\<string\>                                                | 否   | 白名单信息, string 类型表示的包名。  |
| blockedApplications | Array\<string\>                                                | 否   | 黑名单信息, string 类型表示的包名。  |