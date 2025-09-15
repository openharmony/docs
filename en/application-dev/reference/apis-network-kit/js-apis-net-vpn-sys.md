# @ohos.net.vpn (VPN Management) (System API)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

The **vpn** module implements virtual private network (VPN) management, such as starting and stopping a VPN.
This module is the built-in VPN function provided by the OS. It allows users to set up VPN connections through the network settings of the OS. Generally, this module provides only limited functions and is subject to strict restrictions.

> **NOTE**
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```js
import { vpn } from '@kit.NetworkKit';
```

## vpn.createVpnConnection

createVpnConnection(context: AbilityContext): VpnConnection

Creates a VPN connection.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Parameters**

| Name | Type                                                                            | Mandatory| Description        |
| ------- | -------------------------------------------------------------------------------- | ---- | ------------ |
| context | [AbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | Yes  | Specified context.|

**Return value**

| Type                           | Description                   |
| :------------------------------ | :---------------------- |
| [VpnConnection](#vpnconnection) | VPN connection object.|

**Error codes**

For details about the error codes, see [VPN Error Codes](errorcode-net-vpn.md).

| ID| Error Message        |
| --------- | ---------------- |
| 202       | Non-system applications use system APIs.         |
| 401       | Parameter error.                                 |

**Example**

>**NOTE**
>
>In the sample code provided in this topic, **this.context** is used to obtain **UIAbilityContext**, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

Stage model:

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

Defines a VPN connection object. Before calling **VpnConnection** APIs, you need to create a VPN connection object by calling [vpn.createVpnConnection](#vpncreatevpnconnection).

### setUp

setUp(config: VpnConfig, callback: AsyncCallback\<number\>): void

Creates a VPN based on the specified configuration. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_VPN

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Parameters**

| Name  | Type                   | Mandatory| Description                                                                                              |
| -------- | ----------------------- | ---- | -------------------------------------------------------------------------------------------------- |
| config   | [VpnConfig](#vpnconfig) | Yes  | VPN configuration.                                                                         |
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the result. If a VPN is created successfully, **error** is **undefined** and **data** is the file descriptor of the vNIC. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [VPN Error Codes](errorcode-net-vpn.md).

| ID| Error Message                                        |
| --------- | ------------------------------------------------ |
| 201       | Permission denied.                               |
| 202       | Non-system applications use system APIs.         |
| 401       | Parameter error.                                 |
| 2200001   | Invalid parameter value.                         |
| 2200002   | Operation failed. Cannot connect to service.     |
| 2200003   | System internal error.                           |
| 2203001   | VPN creation denied. Check the user type.        |
| 2203002   | VPN already exists.                              |

**Example**

>**NOTE**
>
>In the sample code provided in this topic, **this.context** is used to obtain **UIAbilityContext**, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

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

Creates a VPN based on the specified configuration. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_VPN

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Parameters**

| Name| Type                   | Mandatory| Description                     |
| ------ | ----------------------- | ---- | ------------------------- |
| config | [VpnConfig](#vpnconfig) | Yes  | VPN configuration.|

**Return value**

| Type             | Description                                                          |
| ----------------- | -------------------------------------------------------------- |
| Promise\<number\> | Promise used to return the result, which is the file descriptor of the vNIC.|

**Error codes**

For details about the error codes, see [VPN Error Codes](errorcode-net-vpn.md).

| ID| Error Message                                        |
| --------- | ------------------------------------------------ |
| 201       | Permission denied.                               |
| 202       | Non-system applications use system APIs.         |
| 401       | Parameter error.                                 |
| 2200001   | Invalid parameter value.                         |
| 2200002   | Operation failed. Cannot connect to service.     |
| 2200003   | System internal error.                           |
| 2203001   | VPN creation denied. Check the user type.        |
| 2203002   | VPN already exists.                              |

**Example**

>**NOTE**
>
>In the sample code provided in this topic, **this.context** is used to obtain **UIAbilityContext**, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

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

Protects sockets against a VPN connection. The data sent through sockets is directly transmitted over the physical network and therefore the traffic does not traverse through the VPN. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_VPN

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Parameters**

| Name  | Type                 | Mandatory| Description                                                                                     |
| -------- | --------------------- | ---- | ----------------------------------------------------------------------------------------- |
| socketFd | number                | Yes  | Socket file descriptor. It can be obtained through [getSocketFd](js-apis-socket.md#getsocketfd10).|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined**. If the operation fails, an error message is returned.                           |

**Error codes**

For details about the error codes, see [VPN Error Codes](errorcode-net-vpn.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |
| 2203004   | Invalid socket file descriptor.              |

**Example**

>**NOTE**
>
>In the sample code provided in this topic, **this.context** is used to obtain **UIAbilityContext**, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

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

Protects sockets against a VPN connection. The data sent through sockets is directly transmitted over the physical network and therefore the traffic does not traverse through the VPN. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_VPN

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Parameters**

| Name  | Type  | Mandatory| Description                                                                                       |
| -------- | ------ | ---- | ------------------------------------------------------------------------------------------- |
| socketFd | number | Yes  | Socket file descriptor. It can be obtained through [getSocketFd](js-apis-socket.md#getsocketfd10-1).|

**Return value**

| Type           | Description                                                 |
| --------------- | ----------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, the operation result is returned. If the operation fails, an error message is returned.|

**Error codes**

For details about the error codes, see [VPN Error Codes](errorcode-net-vpn.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |
| 2203004   | Invalid socket file descriptor.              |

**Example**

>**NOTE**
>
>In the sample code provided in this topic, **this.context** is used to obtain **UIAbilityContext**, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

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

Destroys a VPN. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_VPN

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Parameters**

| Name  | Type                 | Mandatory| Description                                                          |
| -------- | --------------------- | ---- | -------------------------------------------------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined**. If the operation fails, an error message is returned.|

**Error codes**

For details about the error codes, see [VPN Error Codes](errorcode-net-vpn.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**Example**

>**NOTE**
>
>In the sample code provided in this topic, **this.context** is used to obtain **UIAbilityContext**, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

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

Destroys a VPN. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_VPN

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Return value**

| Type           | Description                                                 |
| --------------- | ----------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, the operation result is returned. If the operation fails, an error message is returned.|

**Error codes**

For details about the error codes, see [VPN Error Codes](errorcode-net-vpn.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 401       | Parameter error.                                 |
| 202       | Non-system applications use system APIs.     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**Example**

>**NOTE**
>
>In the sample code provided in this topic, **this.context** is used to obtain **UIAbilityContext**, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

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

Defines the VPN configuration.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Vpn

| Name               | Type                                                          | Read-Only|Optional| Description                               |
| ------------------- | -------------------------------------------------------------- | ---- | ---|----------------------------------- |
| addresses           | Array\<[LinkAddress](js-apis-net-connection.md#linkaddress)\> | No  |No| IP address of the vNIC.           |
| routes              | Array\<[RouteInfo](js-apis-net-connection.md#routeinfo)\>     | No  |Yes|Route information of the vNIC.           |
| dnsAddresses        | Array\<string\>                                                | No  |Yes|IP address of the DNS server.               |
| searchDomains       | Array\<string\>                                                | No  | Yes|List of DNS search domains.                 |
| mtu                 | number                                                         | No  |Yes|Maximum transmission unit (MTU), in bytes.    |
| isIPv4Accepted      | boolean                                                        | No  | Yes| Whether IPv4 is supported. The default value is **true**.     |
| isIPv6Accepted      | boolean                                                        | No  |Yes|Whether IPv6 is supported. The default value is **false**.    |
| isLegacy            | boolean                                                        | No  |Yes|Whether the built-in VPN is supported. The default value is **false**.  |
| isBlocking          | boolean                                                        | No  |Yes|Whether the blocking mode is used. The default value is **false**.      |
| trustedApplications | Array\<string\>                                                | No  |Yes|List of trusted applications, which are represented by bundle names of the string type. |
| blockedApplications | Array\<string\>                                                | No  |Yes|List of blocked applications, which are represented by bundle names of the string type. |
