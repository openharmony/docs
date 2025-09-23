# VPN Management
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

## Introduction

A virtual private network (VPN) is a dedicated network established on a public network. Unlike a traditional private network, a VPN does not require an end-to-end physical link between any two nodes. It is built over a network platform (for example, Internet) provided by a public network service provider. User data is transmitted over the logical link.

OpenHarmony provides the VPN Extension solution for enhanced VPN management. Currently, the VPN capabilities provided to third-party applications are primarily used for creating virtual NICs and configuring VPN routing information. The connection tunnel process and internal connection protocols need to be implemented by the applications themselves. The following guides you through on how to develop your own VPN client.

> **NOTE**
>
>- To maximize the application running efficiency, all APIs are called asynchronously in callback or promise mode. The following code examples use the promise mode. For details about the APIs, see [API Reference](../reference/apis-network-kit/js-apis-net-vpnExtension.md).
>- For details about the complete JavaScript APIs and sample code, see [API Reference](../reference/apis-network-kit/js-apis-net-vpnExtension.md).
>- To use related APIs, you must declare the [ohos.permission.INTERNET](../security/AccessToken/permissions-for-all.md#ohospermissioninternet) permission.

## VPN Extension Ability UI

With the VPN Extension APIs provided by OpenHarmony, you can build VPN services that support different protocols. OpenHarmony provides a UI for users to learn about VPN startup and connection.

- When the VPN application sets up a connection for the first time, the VPN connection authorization dialog box is displayed. The dialog box prompts users whether to trust the VPN application and accept the VPN connection request.
- If the VPN connection is successful, a VPN icon (a key) is displayed in the status bar to remind the user that the VPN is connected.

To facilitate the query and configuration, your VPN application needs to provide the following UIs:

- UI for manually starting and stopping the VPN connection.
- UI for displaying the connection status of the VPN application in the notification bar or providing network statistics (such as the connection duration and traffic) of the VPN connection. Touching the notification in notification bar should bring your VPN application to the foreground.


## How to Develop

### Creating a VPN Extension Ability

To enable your application to support the VPN functionality, you need to create an **ExtensionAbilities** instance inherited from **VpnExtensionAbility**.

```ts
// Assume that the VNP application is named MyVpnExtAbility. Define it in module.json5.
"extensionAbilities": [
  {
    "name": "MyVpnExtAbility",
    "description": "vpnservice",
    "type": "vpn",
    "srcEntry": "./ets/serviceextability/MyVpnExtAbility.ts"
  }
]
```

> **NOTE**
>
> If the DevEco Studio tool displays a message indicating unrecognizable **"type": "vpn"**, you need to manually add **vpn** to the **type** enums corresponding to **extensionAbilities** in the **toolchains\modulecheck\module.json** file of the SDK and clear the build cache.

Next, you need to configure, start, and stop the VPN in the created **VpnExtensionAbility**.

- Establish a VPN tunnel. The following uses the UDP tunnel as an example. For details, see the **UdpConnect()** API in the [napi_init](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/VPNControl_Case/entry/src/main/cpp/napi_init.cpp) demo project.
- Use [VpnConnection.protect](../reference/apis-network-kit/js-apis-net-vpnExtension.md#protect) to enable protection for the UDP tunnel.
- Construct VPN Config parameters. For details, see [VPN Config Parameters](#description-of-vpn-config-parameters).
- Use [VpnConnection.create](../reference/apis-network-kit/js-apis-net-vpnExtension.md#create) to establish a VPN connection.
- Process data of the virtual network interface card (vNIC), such as reading or writing data.

### Starting the VPN Extension Ability

To start a connection from the VPN application, you need to call **startVpnExtensionAbility** with the **VpnExtensionAbility** information specified. Make sure that **bundleName** is the same as that of the VPN application, and **abilityName** is the name of the **VpnExtensionAbility** you created. The sample code is as follows:

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
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold).onClick(() => {
          console.info("btn click")
        })
        Button('Start Extension').onClick(() => {
          vpnExtension.startVpnExtensionAbility(want);
        }).width('70%').fontSize(45).margin(16)
      }.width('100%')
    }.height('100%')
  }
}
```

If your VPN app is not trusted by the user, the system displays a dialog box asking the user to authorize the VPN connection. After obtaining the authorization, the system automatically calls [onCreate](../reference/apis-network-kit/js-apis-VpnExtensionAbility.md#vpnextensionabilityoncreate) of the **VpnExtensionAbility**.

Currently, only one active VPN connection is supported. If the application calls **startVpnExtensionAbility** when a VPN connection is active, it will receive a system rejection error. In this case, you are advised to remind the user to disconnect the active VPN connection first.



### Stopping the VPN Extension Ability

To stop a VPN connection, the VPN application needs to call **stopVpnExtensionAbility** with the target **VpnExtensionAbility** specified. The system verifies the permission of the caller. The caller of **stopVpnExtensionAbility** must have obtained the VPN connection authorization of the user and can only stop the **VpnExtensionAbility** it started. Therefore, make sure that the value of **bundleName** passed by the API is the same as that of the VPN application, and the value of **abilityName** is the same as that of the target **VpnExtensionAbility**.

The sample code is as follows:

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
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold).onClick(() => {
          console.info("btn click")
        })
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

After the **VPNExtensionAbility** is stopped, call [onDestroy](../reference/apis-network-kit/js-apis-VpnExtensionAbility.md#vpnextensionabilityondestroy) to destroy the VPN connection and release related resources.

```ts
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let context: vpnExtension.VpnExtensionContext;

export default class MyVpnExtAbility extends VpnExtensionAbility {
  onDestroy() {
    let VpnConnection: vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
    console.info("vpn createVpnConnection: " + JSON.stringify(VpnConnection));
    VpnConnection.destroy().then(() => {
      console.info("destroy success.");
    }).catch((error: BusinessError) => {
      console.error("destroy fail" + JSON.stringify(error));
    });
  }
}
```

### Generating a VPN ID

When creating a VPN, generate a VPN ID as the unique identifier of the VPN.
The sample code is as follows:

```ts
import VpnExtensionAbility from "@ohos.app.ability.VpnExtensionAbility";
import { vpnExtension } from "@kit.NetworkKit";

export default class VpnTest extends VpnExtensionAbility {
  vpnId: string = ''

  getVpnId() {
    let vpnConnection = vpnExtension.createVpnConnection(this.context);
    vpnConnection?.generateVpnId().then((data) => {
      if (data) {
        this.vpnId = data;
      }
    });
  }
}
```

### Disconnecting from the VPN

To disconnect from the VPN, use the sample code below:
```ts
import VpnExtensionAbility from "@ohos.app.ability.VpnExtensionAbility";
import { vpnExtension } from "@kit.NetworkKit";

export default class VpnTest extends VpnExtensionAbility {
  vpnId: string = 'test_vpn_id'
  vpnConnection: vpnExtension.VpnConnection | undefined

  destroy() {
    this.vpnConnection = vpnExtension.createVpnConnection(this.context);
    this.vpnConnection?.destroy(this.vpnId);
  }
}
```

## Service Lifecycle Management

To ensure network connectivity, the system automatically stops the VPN connection when detecting that the VPN application is abnormal:

- The application process that calls **startVpnExtensionAbility** exits.
- The VPN service process is destroyed.

## Description of VPN Config parameters

| Name               | Type                                                        | Read-only|Optional| Description                                                        |
| ------------------- | ------------------------------------------------------------ | ---- | ---|------------------------------------------------------------ |
| addresses           | Array\<[LinkAddress](../reference/apis-network-kit/js-apis-net-connection.md#linkaddress)\> | No  |No| IP addresses of virtual network interface cards (vNICs).                                       |
| routes              | Array\<[RouteInfo](../reference/apis-network-kit/js-apis-net-connection.md#routeinfo)\> | No  | Yes|Routes of vNICs. Currently, a maximum of 1024 routes can be configured.           |
| dnsAddresses        | Array\<string\>                                              | No  |Yes|IP addresses of DNS servers. After the IP address is configured, when the VPN is active and proxy-enabled applications access the Internet, the configured DNS server will be used for DNS queries.|
| searchDomains       | Array\<string\>                                              | No  |Yes|List of DNS search domains.                                           |
| mtu                 | number                                                       | No  |Yes| Maximum transmission unit (MTU), in bytes.                              |
| isIPv4Accepted      | boolean                                                      | No  |Yes|Whether IPv4 is supported. The default value is **true**. The value **true** indicates that IPV4 is supported, and the value **false** indicates the opposite.                                |
| isIPv6Accepted      | boolean                                                      | No  |Yes|Whether IPv6 is supported. The default value is **false**. The value **true** indicates that IPV6 is supported, and the value **false** indicates the opposite.                               |
| isInternal          | boolean                                                      | No  |Yes| Whether the built-in VPN is supported. The default value is **false**. The value **true** indicates that the built-in VPN is supported, and the value **false** indicates the opposite.                            |
| isBlocking          | boolean                                                      | No  |Yes|Whether the blocking mode is used. The default value is **false**. The value **true** indicates that the blocking mode is used, and the value **false** indicates the opposite.                               |
| trustedApplications | Array\<string\>                                              | No  | Yes|List of trusted applications, which are represented by package names of the string type. After such a list is configured, only the applications in the list can be proxied by the VPN according to the specified **routes**.<br>Note: Configure either **trustedApplications** or **blockedApplications** as they are mutually exclusive.             |
| blockedApplications | Array\<string\>                                              | No  | Yes|List of blocked applications, which are represented by package names of the string type. After such a list is configured, only applications that are not in the list can be proxied by the VPN according to the specified **routes**.<br>Note: Configure either **trustedApplications** or **blockedApplications** as they are mutually exclusive.         |

**Example**

```ts
import { vpnExtension } from '@kit.NetworkKit';

let vpnConfig: vpnExtension.VpnConfig = {
  // Configure the IP address of the vNIC.
  addresses: [{
    address: {
      address: '192.x.x.5',
      family: 1
    },
    prefixLength: 24
  }],
  // Configure route information.
  routes: [{
    // Set the name of the vNIC, which has a fixed value of vpn-tun.
    interface: 'vpn-tun',
    destination: {
      address: {
        address: '10.x.x.8',
        family: 1,
        port: 8080
      },
      prefixLength: 24
    },
    gateway: {
      address: '10.x.x.5',
      family: 1,
      port: 8080
    },
    hasGateway: false,
    isDefaultRoute: false,
  }],
  // Configure the MTU.
  mtu: 1400,
  // Configure IP addresses of DNS serves.
  dnsAddresses: ['223.x.x.5', '223.x.x.6'],
  // Configure trusted VPN applications.
  trustedApplications: ['com.test.browser'],
  // Configure blocked VPN applications.
  blockedApplications: ['com.test.games'],
}
let context: vpnExtension.VpnExtensionContext;

function vpnCreate() {
  let VpnConnection: vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
  VpnConnection.create(vpnConfig).then((data) => {
    console.info("vpn create " + JSON.stringify(data));
  })
}
```



## VPN Demo

The OpenHarmony project provides a sample application named [VPN](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/VPNControl_Case), which showcases how to implement the VPN service.
