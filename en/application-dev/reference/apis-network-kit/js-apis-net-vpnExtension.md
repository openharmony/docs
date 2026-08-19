# @ohos.net.vpnExtension (Enhanced VPN Management)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=681375fe8e2ad6298fc081a819f69633a55a7ca2 translatedAt=2026-08-14T08:54:58.587Z pushedAt=2026-08-15T07:38:05.637Z -->

This module implements virtual private network (VPN) management, such as starting and stopping a third-party VPN. Third-party VPNs refer to VPN services provided by third parties. They usually support more security and privacy functions and more comprehensive customization options. Currently, the VPN capabilities provided to third-party applications are primarily used for creating virtual NICs and configuring VPN routing information. The connection tunnel process and internal connection protocols need to be implemented by the applications themselves.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Constraints

To ensure system security and stability and prevent **VpnExtensionAbility** from abusing system resources, the system manages its capabilities and does not support references to some modules. For details, see [Appendix](#appendix).

## Modules to Import

```js
import { vpnExtension } from '@kit.NetworkKit';
```

## LinkAddress

type LinkAddress = connection.LinkAddress

Defines the network link address information.

**System capability**: SystemCapability.Communication.NetManager.Core

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| [connection.LinkAddress](./js-apis-net-connection.md#linkaddress) | Network link address information.|

## RouteInfo

type RouteInfo = connection.RouteInfo

Defines the network route information.

**System capability**: SystemCapability.Communication.NetManager.Core

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| [connection.RouteInfo](./js-apis-net-connection.md#routeinfo) | Network route information.|

## VpnExtensionContext

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
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Want information.<br> Note: From API version 22, the **parameters** field in **want** can be passed when the VPN is started for the first time.|

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
import { Want } from '@kit.AbilityKit';
import { vpnExtension } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
          .fontSize(40)
          .fontWeight(FontWeight.Bold).onClick(() => {
          console.info("btn click")
        })
        Button('Start Extension').onClick(() => {
          vpnExtension.startVpnExtensionAbility(want).then(() => {
            console.info('startVpnExtensionAbility success');
          }).catch((err: BusinessError) => {
            console.error('startVpnExtensionAbility error: ' + JSON.stringify(err));
          })
        }).width('70%').fontSize(30).margin(16)
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
import { Want } from '@kit.AbilityKit';
import { vpnExtension } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
          console.info("btn click")
        })
        Button('Start Extension').onClick(() => {
          vpnExtension.startVpnExtensionAbility(want).then(() => {
            console.info('startVpnExtensionAbility success');
          }).catch((err: BusinessError) => {
            console.error('startVpnExtensionAbility error: ' + JSON.stringify(err));
          })
        }).width('70%').fontSize(30).margin(16)
        Button('Stop Extension').onClick(() => {
          console.info("btn end")
          vpnExtension.stopVpnExtensionAbility(want).then(() => {
            console.info('stopVpnExtensionAbility success');
          }).catch((err: BusinessError) => {
            console.error('stopVpnExtensionAbility error: ' + JSON.stringify(err));
          })
        }).width('70%').fontSize(30).margin(16)

      }.width('100%')
    }.height('100%')
  }
}
```

## vpnExtension.createVpnObserver

createVpnObserver(): VpnObserver

Creates a VPN observer object. It is used to listen for VPN-related events.

**Since**: 26.0.0

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Model restriction**: This API can be used only in the stage model.

**Return value**

| Type                           | Description                   |
| :------------------------------ | :---------------------- |
| [VpnObserver](#vpnobserver) | VPN observer object.|

**Example**

```ts
import { vpnExtension } from '@kit.NetworkKit';

let vpnObserver: vpnExtension.VpnObserver = vpnExtension.createVpnObserver();
```

## VpnObserver

Defines a VPN observer object. It is used to listen for VPN-related events. Before calling **VpnObserver** APIs, you need to create a VPN connection object by calling [vpnExtension.createVpnObserver](#vpnextensioncreatevpnobserver).

### onAuthorizationResult

onAuthorizationResult(callback: Callback\<boolean\>): void

Registers a listener for the user authorization result. The authorization result is displayed in a dialog box after [startVpnExtensionAbility](#vpnextensionstartvpnextensionability) is called. The notification is sent only when the user taps the dialog box, and only the result of the current VPN is received. If you do not need to listen for the authorization result, call [offAuthorizationResult](#offauthorizationresult) to cancel the registration.

>**NOTE**
>
>If this API is called multiple times, only the last callback takes effect.

**Since**: 26.0.0

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| callback  | Callback\<boolean\> |Yes  | Callback used to return the user authorization result. The value **true** indicates that the user agrees to the authorization, and the value **false** indicates the opposite.|

**Example**

```ts
import { vpnExtension } from '@kit.NetworkKit';

let vpnObserver: vpnExtension.VpnObserver = vpnExtension.createVpnObserver();
vpnObserver.onAuthorizationResult((result: boolean) => {
  if (result) {
    console.info('VPN authorization succeeded');
  } else {
    console.error('VPN authorization failed');
  }
});
```

### offAuthorizationResult

offAuthorizationResult(callback?: Callback\<boolean\>): void

Unregisters a listener for the user authorization result.

>**NOTE**
>
>If you have called [onAuthorizationResult](#onauthorizationresult) multiple times to register listeners and want to unregister the listener, you need to pass the callback passed in the last call or pass no parameter.

**Since**: 26.0.0

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| callback  | Callback\<boolean\> | No  | Listener callback used to return the user authorization result.<br>If this parameter is passed, the specified listener is unregistered. If no parameter is passed, all registered listeners are unregistered.|

**Example**

```ts
import { vpnExtension } from '@kit.NetworkKit';

let vpnObserver: vpnExtension.VpnObserver = vpnExtension.createVpnObserver();

let callback = (result: boolean) => {
  console.info('Authorization result: ' + result);
};
// Register a listener.
vpnObserver.onAuthorizationResult(callback);

// Unregister a specified listener.
vpnObserver.offAuthorizationResult(callback);

// Unregister all registered listeners.
vpnObserver.offAuthorizationResult();
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

> **NOTE**
>
> You are advised to call [destroy()](#destroy) or [destroy(vpnId: string)](#destroy20) to destroy the VPN and clear resources when the VPN is not needed.

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
    
    // If no VPN is required, call destroy() to destroy the VPN and clear resources.
    vpnConnection.destroy().then(() => {
      console.info("destroy success.");
    }).catch((error : BusinessError) => {
      console.error(`destroy fail. Code:${error.code}, message:${error.message}`);
    });
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

### destroy<sup>20+</sup>

destroy(vpnId: string): Promise\<void\>

Destroys a VPN based on the specified VPN ID. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Parameters**

| Name  | Type  | Mandatory| Description                                                                                       |
| -------- | ------ | ---- | ------------------------------------------------------------------------------------------- |
| vpnId | string |  Yes | Unique VPN ID.|

**Return value**

| Type           | Description                                                 |
| --------------- | ----------------------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [VPN Error Codes](errorcode-net-vpn.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 19900001       |  Invalid parameter value.  |
| 19900002  |  System internal error.  |

**Example**

```ts
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
import { BusinessError } from "@kit.BasicServicesKit";

export default class MyVpnExtAbility extends VpnExtensionAbility {
  onCreate() {
    let vpnConnection = vpnExtension.createVpnConnection(this.context);

    // You can call generateVpnId() to obtain the VPN ID.
    let vpnId = 'testVpnId';
    vpnConnection.destroy(vpnId).then(() => {
      console.info("destroy success");
    }).catch((error: BusinessError) => {
      console.error(`destroy fail, Code is ${error.code}, message is ${error.message}`);
    });
  }
}
```

### generateVpnId<sup>20+</sup>

generateVpnId(): Promise\<string\>

Generates a unique VPN ID. This API uses a promise to return the result.

To use the multi-VPN capability of the system, you need to call this API to generate a VPN ID and configure it in **VpnConfig**.

>**NOTE**
>
>Currently, the multi-VPN capability of the system supports only IPv4.

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Return value**

| Type           | Description                                                 |
| --------------- | ----------------------------------------------------- |
| Promise\<string\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [VPN Error Codes](errorcode-net-vpn.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 19900001       |  Invalid parameter value.  |
| 19900002  |  System internal error.  |

**Example**

```ts
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
import { BusinessError } from "@kit.BasicServicesKit";

export default class MyVpnExtAbility extends VpnExtensionAbility {
  onCreate() {
    let vpnConnection = vpnExtension.createVpnConnection(this.context);
    vpnConnection.generateVpnId().then((data) => {
      if (data) {
        console.info("generateVpnId success, vpnId = " + JSON.stringify(data));
      }
    }).catch((error: BusinessError) => {
      console.error(`generateVpnId fail, Code is ${error.code}, message is ${error.message}`);
    });
  }
}
```

### protectProcessNet<sup>22+</sup>

protectProcessNet(): Promise\<void\>

Protects application processes against a VPN connection. The data sent through the protected processes is transmitted over the physical network without traversing the VPN. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Return value**

| Type           | Description                                                 |
| --------------- | ----------------------------------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Example**

```js
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let g_tunnelFd = -1;
export default class MyVpnExtAbility  extends VpnExtensionAbility {
  onCreate() {
    let vpnConnection = vpnExtension.createVpnConnection(this.context);
    console.info("VPN createVpnConnection: " + JSON.stringify(vpnConnection));
    this.ProtectNetByProcess();
  }
  CreateTunnel() {
    g_tunnelFd = 8888;
  }
  ProtectNetByProcess() {
    hilog.info(0x0000, 'developTag', '%{public}s', 'vpn ProtectNetByProcess');
    let vpnConnection = vpnExtension.createVpnConnection(this.context);
    vpnConnection.protectProcessNet().then(() => {
      hilog.info(0x0000, 'developTag', '%{public}s', 'vpn ProtectNetByProcess Success');
      this.CreateTunnel();
    }).catch((err: Error) => {
      hilog.error(0x0000, 'developTag', 'vpn ProtectNetByProcess Failed %{public}s', JSON.stringify(err) ?? '');
    })
  }
}
```

## VpnConfig

Defines the VPN configuration.

**System capability**: SystemCapability.Communication.NetManager.Vpn

<!--Table: 19%; 20%; 8%; 8%; 45%-->

| Name            | Type                                     | Read-only| Optional| Description                                      |
| ---------------- | ----------------------------------------- | ---- | ---- | ------------------------------------------ |
| addresses           | Array\<[LinkAddress](js-apis-net-connection.md#linkaddress)\>  | No | No| IP addresses of vNICs. Before API version 23, a maximum of 64 IP addresses are supported. Starting from API version 23, a maximum of 2000 IP addresses are supported.                                 |
| vpnId<sup>20+</sup>           | string | No| Yes| Unique VPN ID.|
| routes              | Array\<[RouteInfo](js-apis-net-connection.md#routeinfo)\>      | No | Yes| Route information of the vNIC. Before API version 23, a maximum of 1024 routes can be configured. Starting from API version 23, a maximum of 10,000 routes can be configured.                 |
| dnsAddresses        | Array\<string\>                                                 | No  | Yes | DNS server address information. After the DNS server addresses are configured, the proxied apps use the configured DNS servers for DNS queries when the VPN is started. A maximum of 64 DNS server addresses can be configured.                                    |
| searchDomains       | Array\<string\>                                                | No | Yes| List of DNS search domains.                                    |
| mtu                 | number                                                         | No  | Yes | Maximum transmission unit (MTU) value, in bytes. Value range: [576, 1500].               |
| isIPv4Accepted      | boolean                                                         | No  | Yes | Whether to support IPv4. The value **true** indicates support, and **false** indicates no support. The default value is **true**.<br>**Note:** If IPv4 is supported, IPv4 addresses must be configured in **addresses**.  |
| isIPv6Accepted      | boolean                                                         | No  | Yes | Whether to support IPv6. The value **true** indicates support, and **false** indicates no support. The default value is **false**.<br>**Note:** If IPv6 is supported, IPv6 addresses must be configured in **addresses**.  |
| isInternal          | boolean                                                         | No  | Yes | Whether to support the built-in VPN. The value **true** indicates support, and **false** indicates no support. The default value is **false**. |
| isBlocking          | boolean                                                        | No  | Yes | Whether the blocking mode is used. The value **true** indicates the blocking mode, and **false** indicates the non-blocking mode. The default value is **false**.       |
| trustedApplications | Array\<string\>                                                | No | Yes| List of trusted applications, which are represented by bundle names of the string type. After such a list is configured, only the applications in the list can be proxied by the VPN according to the specified **routes**. Before API version 23, a maximum of 64 trusted application bundle names can be configured. Since API version 23, a maximum of 256 trusted application bundle names can be configured.<br>**Note**: Configure either **trustedApplications** or **blockedApplications** as they are mutually exclusive.                        |
| blockedApplications | Array\<string\>                                                 | No | Yes| List of blocked applications, which are represented by bundle names of the string type. After such a list is configured, applications that are in the list cannot be proxied by the VPN, while other applications can be proxied by the VPN according to the specified **routes**. Before API version 23, a maximum of 64 blocked application bundle names can be configured. Since API version 23, a maximum of 256 blocked application bundle names can be configured.<br>**Note**: Configure either **trustedApplications** or **blockedApplications** as they are mutually exclusive.                        |

**Example**

```js
import { vpnExtension} from '@kit.NetworkKit';

let vpnConfig: vpnExtension.VpnConfig = {
  addresses: [],
  vpnId: '123',
  routes: [{
    // If the network interface name is left empty, the system configures the route to the VPN virtual network interface by default.
    // If the actual name of a non-virtual network interface is entered, the route configuration may be abnormal.
    interface: "vpn-tun",
    destination: {
      address: {
        address:'',
        family:1,
        port:8080
      },
      prefixLength:1
    },
    gateway: {
      // If the gateway address is left empty, the system uses the VPN virtual network interface address as the gateway address by default.
      // If a non-VPN virtual network interface address is required, ensure that the address is reachable; otherwise, the route configuration may fail.
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

## Appendix

**VpnExtensionAbility** does not support references to the following modules.

| Kit | Module |
|--|--|
| Contacts Kit | [@ohos.contact (Contact)](../apis-contacts-kit/js-apis-contact.md) |
| Location Kit | [@ohos.geolocation (Geolocation)](../apis-location-kit/js-apis-geolocation.md) |
| Location Kit | [@ohos.geoLocationManager (Geolocation Manager)](../apis-location-kit/js-apis-geoLocationManager.md) |
| Audio Kit | [@ohos.multimedia.audio (Audio Management)](../apis-audio-kit/arkts-apis-audio.md) |
| Camera Kit | [@ohos.multimedia.camera (Camera Management)](../apis-camera-kit/arkts-apis-camera.md) |
| Telephony Kit | [@ohos.telephony.call (Call)](../apis-telephony-kit/js-apis-call.md) |
| Telephony Kit | [@ohos.telephony.sim (SIM Management)](../apis-telephony-kit/js-apis-sim.md) |
| Telephony Kit | [@ohos.telephony.sms (SMS)](../apis-telephony-kit/js-apis-sms.md) |