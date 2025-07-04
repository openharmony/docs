# @ohos.net.vpnExtension (Enhanced VPN Management)

This module implements virtual private network (VPN) management, such as starting and stopping a third-party VPN. Third-party VPNs refer to VPN services provided by third parties. They usually support more security and privacy functions and more comprehensive customization options. Currently, the VPN capabilities provided to third-party applications are primarily used for creating virtual NICs and configuring VPN routing information. The connection tunnel process and internal connection protocols need to be implemented by the applications themselves.

> **NOTE**
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { vpnExtension } from '@kit.NetworkKit';
```

## LinkAddress<sup>11+</sup>
type LinkAddress = connection.LinkAddress

Defines the network link address information.

**System capability**: SystemCapability.Communication.NetManager.Core

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| [connection.LinkAddress](./js-apis-net-connection.md#linkaddress) | Network link address information.|

## RouteInfo<sup>11+</sup>
type RouteInfo = connection.RouteInfo

Defines the network route information.

**System capability**: SystemCapability.Communication.NetManager.Core

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| [connection.RouteInfo](./js-apis-net-connection.md#routeinfo) | Network route information.|

## VpnExtensionContext<sup>11+</sup>
type VpnExtensionContext = _VpnExtensionContext

Defines the VPN extension context. It allows access to serviceExtension-specific resources.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core.

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| [_VpnExtensionContext](./js-apis-inner-application-VpnExtensionContext.md) | VPN extension context.|

## vpnExtension.startVpnExtensionAbility

startVpnExtensionAbility(want: Want): Promise\<void>

Enables the VPN extension ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                               | Mandatory| Description              |
| ------ | ----------------------------------- | ---- | ------------------ |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Want information.|

**Return value**

| Type          | Description                   |
| -------------- | ----------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Ability Error Codes](../apis-ability-kit/errorcode-ability.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| --------- | -------------------------------------- |
| 401       | If the input parameter is not valid parameter.|
| 16000001  | The specified ability does not exist.  |
| 16000002  | Incorrect ability type.                |
| 16000006  | Cross-user operations are not allowed. |
| 16000008  | The crowdtesting application expires.  |
| 16000011  | The context does not exist.            |
| 16000050  | Internal error.                        |
| 16200001  | The caller has been released.          |

**Example**
Stage model:

```ts
import { common, Want } from '@kit.AbilityKit';
import { vpnExtension } from '@kit.NetworkKit';

let want: Want = {
  deviceId: "",
  bundleName: "com.example.myvpndemo",
  abilityName: "MyVpnExtAbility",
};

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold).onClick(() => {
          console.info("btn click") })
        Button('Start Extension').onClick(() => {
          vpnExtension.startVpnExtensionAbility(want);
        }).width('70%').fontSize(45).margin(16)
        }.width('100%')
    }.height('100%')
  }
}
```

## vpnExtension.stopVpnExtensionAbility

stopVpnExtensionAbility(want: Want): Promise\<void>

Stops the VPN extension ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                               | Mandatory| Description            |
| ------ | ----------------------------------- | ---- | ---------------- |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Want information.|

**Return value**

| Type          | Description                   |
| -------------- | ----------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Ability Error Codes](../apis-ability-kit/errorcode-ability.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                              |
| --------- | -------------------------------------- |
| 401       | If the input parameter is not valid parameter.|
| 16000001  | The specified ability does not exist.  |
| 16000002  | Incorrect ability type.                |
| 16000006  | Cross-user operations are not allowed. |
| 16000011  | The context does not exist.            |
| 16000050  | Internal error.                        |
| 16200001  | The caller has been released.          |

**Example**
Stage model:

```ts
import { common, Want } from '@kit.AbilityKit';
import { vpnExtension } from '@kit.NetworkKit';

let want: Want = {
  deviceId: "",
  bundleName: "com.example.myvpndemo",
  abilityName: "MyVpnExtAbility",
};

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold).onClick(() => {
          console.info("btn click") })
        Button('Start Extension').onClick(() => {
          vpnExtension.startVpnExtensionAbility(want);
        }).width('70%').fontSize(45).margin(16)
        Button('Stop Extension').onClick(() => {
          console.info("btn end")
          vpnExtension.stopVpnExtensionAbility(want);
        }).width('70%').fontSize(45).margin(16)

        }.width('100%')
    }.height('100%')
  }
}
```

## vpnExtension.createVpnConnection

createVpnConnection(context: VpnExtensionContext): VpnConnection

Creates a **VpnConnection** object.

> **NOTE**
>
> Before calling **createVpnConnection**, call **startVpnExtensionAbility** to enable the VPN function.

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type                                                        | Mandatory| Description          |
| ------- | ------------------------------------------------------------ | ---- | -------------- |
| context | [VpnExtensionContext](js-apis-inner-application-VpnExtensionContext.md) | Yes  | Specified context.|

**Return value**

| Type                           | Description                   |
| :------------------------------ | :---------------------- |
| [VpnConnection](#vpnconnection) | VPN connection object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message        |
| --------- | ---------------- |
| 401       | Parameter error. |

**Example**
Stage model:

```ts
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
import { common, Want } from '@kit.AbilityKit';

let context: vpnExtension.VpnExtensionContext;
export default class MyVpnExtAbility extends VpnExtensionAbility {
  onCreate(want: Want) {
    let vpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
    console.info("VPN createVpnConnection: " + JSON.stringify(vpnConnection));
  }
}
```

## VpnConnection

Defines a VPN connection object. Before calling **VpnConnection** APIs, you need to create a VPN connection object by calling **vpnExt.createVpnConnection**.

### create

create(config: VpnConfig): Promise\<number\>

Creates a VPN based on the specified configuration. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Parameters**

| Name| Type                   | Mandatory| Description                     |
| ------ | ----------------------- | ---- | ------------------------- |
| config | [VpnConfig](#vpnconfig) | Yes  | VPN configuration.|

**Return value**

| Type             | Description                                                          |
| ----------------- | -------------------------------------------------------------- |
| Promise\<number\> | Promise used to return the result, which is the file descriptor of the virtual network interface card (vNIC).|

**Error codes**

For details about the error codes, see [VPN Error Codes](errorcode-net-vpn.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                        |
| --------- | ------------------------------------------------ |
| 401       | Parameter error.                                 |
| 2200001   | Invalid parameter value.                         |
| 2200002   | Operation failed. Cannot connect to service.     |
| 2200003   | System internal error.                           |
| 2203001   | VPN creation denied, please check the user type. |
| 2203002   | VPN exist already, please execute destroy first. |

**Example**

```js
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
import { common, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let context: vpnExtension.VpnExtensionContext;
export default class MyVpnExtAbility extends VpnExtensionAbility {
  private tunIp: string = '10.0.0.5';
  private blockedAppName: string = 'com.example.myvpndemo';
  onCreate(want: Want) {
    let vpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
    console.info("vpn createVpnConnection: " + JSON.stringify(vpnConnection));
    this.SetupVpn();
  }
  SetupVpn() {
        class Address {
            address: string;
            family: number;

            constructor(address: string, family: number) {
                this.address = address;
                this.family = family;
            }
        }

        class AddressWithPrefix {
            address: Address;
            prefixLength: number;

            constructor(address: Address, prefixLength: number) {
                this.address = address;
                this.prefixLength = prefixLength;
            }
        }

        class Config {
            addresses: AddressWithPrefix[];
            mtu: number;
            dnsAddresses: string[];
            trustedApplications: string[];
            blockedApplications: string[];

            constructor(
                tunIp: string,
                blockedAppName: string
            ) {
                this.addresses = [
                    new AddressWithPrefix(new Address(tunIp, 1), 24)
                ];
                this.mtu = 1400;
                this.dnsAddresses = ["114.114.114.114"];
                this.trustedApplications = [];
                this.blockedApplications = [blockedAppName];
            }
        }

        let config = new Config(this.tunIp, this.blockedAppName);

        try {
            let vpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
            vpnConnection.create(config).then((data) => {
                hilog.error(0x0000, 'developTag', 'tunfd: %{public}s', JSON.stringify(data) ?? '');
            })
        } catch (error) {
            hilog.error(0x0000, 'developTag', 'VPN setUp fail: %{public}s', JSON.stringify(error) ?? '');
        }
    }
}
```

### protect

protect(socketFd: number): Promise\<void\>

Protects sockets against a VPN connection. The data sent through sockets is directly transmitted over the physical network and therefore the traffic does not traverse through the VPN. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Parameters**

| Name  | Type  | Mandatory| Description                                                                                       |
| -------- | ------ | ---- | ------------------------------------------------------------------------------------------- |
| socketFd | number | Yes  | Socket file descriptor. It can be obtained through [getSocketFd](js-apis-socket.md#getsocketfd10-1).|

**Return value**

| Type           | Description                                                 |
| --------------- | ----------------------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [VPN Error Codes](errorcode-net-vpn.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |
| 2203004   | Invalid socket file descriptor.              |

**Example**

```js
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
import { common, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let g_tunnelFd = -1;
let context: vpnExtension.VpnExtensionContext;
export default class MyVpnExtAbility extends VpnExtensionAbility {
  private vpnServerIp: string = '192.168.31.13';
  onCreate(want: Want) {
    let vpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
    console.info("VPN createVpnConnection: " + JSON.stringify(vpnConnection));
    this.CreateTunnel();
    this.Protect();
  }
  CreateTunnel() {
      g_tunnelFd = 8888;
  }
  Protect() {
        hilog.info(0x0000, 'developTag', '%{public}s', 'VPN Protect');
        let vpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
        vpnConnection.protect(g_tunnelFd).then(() => {
            hilog.info(0x0000, 'developTag', '%{public}s', 'VPN Protect Success');
        }).catch((err : Error) => {
            hilog.error(0x0000, 'developTag', 'VPN Protect Failed %{public}s', JSON.stringify(err) ?? '');
        })
  }
}
```

### destroy

destroy(): Promise\<void\>

Destroys a VPN. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Return value**

| Type           | Description                                                 |
| --------------- | ----------------------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [VPN Error Codes](errorcode-net-vpn.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**Example**

```js
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let context: vpnExtension.VpnExtensionContext;
export default class MyVpnExtAbility extends VpnExtensionAbility {
  onCreate(want: Want) {
    let vpnConnection : vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
    console.info("VPN createVpnConnection: " + JSON.stringify(vpnConnection));
    vpnConnection.destroy().then(() => {
      console.info("destroy success.");
    }).catch((error : BusinessError) => {
      console.error("destroy fail" + JSON.stringify(error));
    });
  }
}
```

## VpnConfig

Defines the VPN configuration.

**System capability**: SystemCapability.Communication.NetManager.Vpn

| Name               | Type                                                          | Mandatory| Description                                            |
| ------------------- | -------------------------------------------------------------- | ---- |------------------------------------------------|
| addresses           | Array\<[LinkAddress](js-apis-net-connection.md#linkaddress)\> | Yes  | IP addresses of vNICs.                                 |
| routes              | Array\<[RouteInfo](js-apis-net-connection.md#routeinfo)\>     | No  | Routes of vNICs. Currently, a maximum of 1024 routes can be configured.                 |
| dnsAddresses        | Array\<string\>                                                | No  | IP address of the DNS server.                                   |
| searchDomains       | Array\<string\>                                                | No  | List of DNS search domains.                                    |
| mtu                 | number                                                         | No  | Maximum transmission unit (MTU), in bytes. The value range is [576,1500].              |
| isIPv4Accepted      | boolean                                                        | No  | Whether IPv4 is supported. The value **true** indicates that the IPv4 is supported, and the value **false** indicates the opposite. The default value is **true**. |
| isIPv6Accepted      | boolean                                                        | No  | Whether IPV6 is supported. The value **true** indicates that the IPV6 is supported, and the value **false** indicates the opposite. The default value is **false**.|
| isInternal          | boolean                                                        | No  | Whether the built-in VPN is supported. The value **true** indicates that the built-in VPN is supported, and the value **false** indicates the opposite. The default value is **false**.|
| isBlocking          | boolean                                                        | No  | Whether the blocking mode is used. The value **true** indicates that the blocking mode is used, and the value **false** indicates the opposite. The default value is **false**.      |
| trustedApplications | Array\<string\>                                                | No  | List of trusted applications, which are represented by package names of the string type.                        |
| blockedApplications | Array\<string\>                                                | No  | List of blocked applications, which are represented by package names of the string type.                        |

**Example**

```js
import { vpnExtension} from '@kit.NetworkKit';

let vpnConfig: vpnExtension.VpnConfig = {
  addresses: [],
  routes: [{
    interface: "eth0",
    destination: {
      address: {
        address:'',
        family:1,
        port:8080
      },
      prefixLength:1
    },
    gateway: {
      address:'',
      family:1,
      port:8080
    },
    hasGateway: true,
    isDefaultRoute: true,
  }],
  mtu: 1400,
  dnsAddresses: ["223.5.5.5", "223.6.6.6"],
  trustedApplications: [],
  blockedApplications: [],
}
let context: vpnExtension.VpnExtensionContext;

function vpnCreate(){
  let vpnConnection: vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
  vpnConnection.create(vpnConfig).then((data) => {
    console.info("VPN create " + JSON.stringify(data));
  })
}
```
