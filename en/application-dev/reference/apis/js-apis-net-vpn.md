# @ohos.net.vpn (VPN Management)

The **vpn** module implements virtual private network (VPN) management, such as starting and stopping a VPN.

> **NOTE**
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import vpn from '@ohos.net.vpn';
```

## vpn.createVpnConnection

createVpnConnection(context: AbilityContext): VpnConnection

Creates a VPN connection.

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Parameters**

| Name      | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| context | [AbilityContext](js-apis-inner-application-uiAbilityContext.md#uiabilitycontext) | Yes  | Specified context.                  |

**Return value**

| Type                              | Description                   |
| :--------------------------------- | :---------------------- |
| [VpnConnection](#vpnconnection) | VPN connection object.|

**Error codes**

For details about the error codes, see [VPN Error Codes](../errorcodes/errorcode-net-vpn.md).

| ID| Error Message                       |
| ------- | -----------------------------  |
| 401     | Parameter error.             |

**Example**
Stage model:

```ts
// Obtain the context.
import UIAbility from '@ohos.app.ability.UIAbility';
class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage){
    globalThis.context = this.context;
  }
}
let context = globalThis.context;
VpnConnection = vpn.createVpnConnection(context);
console.info("vpn onInit: " + JSON.stringify(VpnConnection));
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

| Name      | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| config | [VpnConfig](#vpnconfig) | Yes  | VPN configuration.                  |
| callback | AsyncCallback\<number\>         | Yes  | Callback used to return the result. If a VPN is created successfully, **error** is **undefined** and **data** is the file descriptor of the vNIC. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [VPN Error Codes](../errorcodes/errorcode-net-vpn.md).

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.             |
| 401     | Parameter error.             |
| 2200001 | Invalid parameter value.             |
| 2200002 | Operation failed. Cannot connect to service.             |
| 2200003 | System internal error.         |
| 2203001 | VPN creation denied, please check the user type.         |
| 2203002 | VPN exist already, please execute destroy first.         |

**Example**

```js
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

Creates a VPN based on the specified configuration. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_VPN

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Parameters**

| Name      | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| config | [VpnConfig](#vpnconfig) | Yes  | VPN configuration.                  |

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<number\> | The obtaining result is returned in Promise format. The file descriptor fd of the specified virtual network adapter is returned.|

**Error codes**

For details about the error codes, see [VPN Error Codes](../errorcodes/errorcode-net-vpn.md).

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.             |
| 401     | Parameter error.             |
| 2200001 | Invalid parameter value.             |
| 2200002 | Operation failed. Cannot connect to service.             |
| 2200003 | System internal error.         |
| 2203001 | VPN creation denied, please check the user type.         |
| 2203002 | VPN exist already, please execute destroy first.         |

**Example**

```js
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

Protects sockets against a VPN connection. The data sent through sockets is directly transmitted over the physical network and therefore the traffic does not traverse through the VPN. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_VPN

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Parameters**

| Name      | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| socketFd | number | Yes  | Socket file descriptor. It can be obtained through [getSocketFd](js-apis-socket.md#getsocketfd10).                  |
| callback | AsyncCallback\<void\>         | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined**. If the operation fails, an error message is returned.|

**Error codes**

For details about the error codes, see [VPN Error Codes](../errorcodes/errorcode-net-vpn.md).

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.        |
| 401     | Parameter error.       |
| 2200001 | Invalid parameter value.        |
| 2200002 | Operation failed. Cannot connect to service.    |
| 2200003 | System internal error.         |
| 2203004 | Invalid socket file descriptor.         |

**Example**

```js
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
    VpnConnection.protect(tunnelfd, (error) => {
      console.info(JSON.stringify(error));
    })
  })
```

### protect

protect(socketFd: number): Promise\<void\>

Protects sockets against a VPN connection. The data sent through sockets is directly transmitted over the physical network and therefore traffic does not traverse through the VPN. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_VPN

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Parameters**

| Name      | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| socketFd | number | Yes  | Socket file descriptor. It can be obtained through [getSocketFd](js-apis-socket.md#getsocketfd10-1).                  |

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, the operation result is returned. If the operation fails, an error message is returned.|

**Error codes**

For details about the error codes, see [VPN Error Codes](../errorcodes/errorcode-net-vpn.md).

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.        |
| 401     | Parameter error.       |
| 2200001 | Invalid parameter value.        |
| 2200002 | Operation failed. Cannot connect to service.    |
| 2200003 | System internal error.         |
| 2203004 | Invalid socket file descriptor.         |

**Example**

```js
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
    VpnConnection.protect(tunnelfd).then(() => {
      console.info("protect success.")
    }).catch(err => {
      console.info("protect fail" + JSON.stringify(err))
    })
  })
```

### destroy

destroy(callback: AsyncCallback\<void\>): void

Destroys a VPN. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_VPN

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Parameters**

| Name      | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void\>         | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined**. If the operation fails, an error message is returned.|

**Error codes**

For details about the error codes, see [VPN Error Codes](../errorcodes/errorcode-net-vpn.md).

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.        |
| 401     | Parameter error.       |
| 2200002 | Operation failed. Cannot connect to service.    |
| 2200003 | System internal error.         |

**Example**

```js
  VpnConnection.destroy((error) => {
    console.info(JSON.stringify(error));
  })
```

### destroy

destroy(): Promise\<void\>

Destroys a VPN. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_VPN

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, the operation result is returned. If the operation fails, an error message is returned.|

**Error codes**

For details about the error codes, see [VPN Error Codes](../errorcodes/errorcode-net-vpn.md).

| ID| Error Message                      |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.        |
| 2200002 | Operation failed. Cannot connect to service.    |
| 2200003 | System internal error.         |

**Example**

```js
  VpnConnection.destroy().then(() => {
    console.info("destroy success.")
  }).catch(err => {
    console.info("destroy fail" + JSON.stringify(err))
  });
```

## VpnConfig

Defines the VPN configuration.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Vpn

| Name| Type| Mandatory| Description|
| ------- | ------ | -- |------------------------------ |
| addresses | Array\<[LinkAddress](js-apis-net-connection.md#linkaddress8)\> | Yes| IP address of the vNIC.|
| routes  | Array\<[RouteInfo](js-apis-net-connection.md#routeinfo8)\> | No| Route information of the vNIC.|
| dnsAddresses    | Array\<string\> | No| IP address of the DNS server.|
| searchDomains | Array\<string\> | No| List of DNS search domains.|
| mtu  | number | No| Maximum transmission unit (MTU), in bytes.|
| isIPv4Accepted    | boolean | No| Whether IPv4 is supported. The default value is **true**.|
| isIPv6Accepted    | boolean | No| Whether IPv6 is supported. The default value is **false**.|
| isLegacy    | boolean | No| Whether the built-in VPN is supported. The default value is **false**.|
| isBlocking    | boolean | No| Whether the blocking mode is used. The default value is **false**.|
| trustedApplications    | Array\<string\> | No| List of trusted applications, which are represented by bundle names of the string type.|
| blockedApplications    | Array\<string\> | No| List of blocked applications, which are represented by bundle names of the string type.|
