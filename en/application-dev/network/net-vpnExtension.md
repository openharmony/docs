# VPN Management

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=8d3dade79c7254af98ff73abd19b721fdb7a8535 translatedAt=2026-08-13T03:09:49.385Z pushedAt=2026-08-13T07:09:09.547Z -->

## Overview

A virtual private network (VPN) is a dedicated network established on a public network. Unlike a traditional private network, a VPN does not require an end-to-end physical link between any two nodes. It is built over a network platform (for example, Internet) provided by a public network service provider. User data is transmitted over the logical link.

OpenHarmony provides the VPN Extension solution for enhanced VPN management. Currently, the VPN capabilities provided to third-party applications are primarily used for creating virtual NICs and configuring VPN routing information. The connection tunnel process and internal connection protocols need to be implemented by the applications themselves. The following guides you through on how to develop your own VPN client.

> **NOTE**
>
> - To ensure app running efficiency, all API calls are asynchronous. For asynchronous APIs, the promise mode is provided. The following examples use the promise mode. For more modes, see [@ohos.net.vpnExtension (Enhanced VPN Management)](../reference/apis-network-kit/js-apis-net-vpnExtension.md).
> - For the complete JS API description and sample code, see [@ohos.net.vpnExtension (Enhanced VPN Management)](../reference/apis-network-kit/js-apis-net-vpnExtension.md).
> - To use this feature, you need the [ohos.permission.INTERNET](../security/AccessToken/permissions-for-all.md#ohospermissioninternet) permission.
> - For the restrictions on VpnExtensionAbility API calls, see [Constraints](../reference/apis-network-kit/js-apis-net-vpnExtension.md#constraints) in the API reference.

## VPN Extension Ability UI

With the [vpnExtension](../reference/apis-network-kit/js-apis-net-vpnExtension.md) APIs provided by the system, you can build VPN services that support different protocols. OpenHarmony provides a UI that allows users to learn about the startup and connection of the current VPN app service:

- When the VPN application sets up a connection for the first time, the VPN connection authorization dialog box is displayed. The dialog box prompts users whether to trust the VPN application and accept the VPN connection request.

- When the VPN connection is started successfully, a VPN (key) icon is displayed in the status bar to remind users that the VPN is connected.

To facilitate the query and configuration, your VPN application needs to provide the following UIs:

- UI for manually starting and stopping the VPN connection.

- When the VPN connection is started, the connection status of the VPN app is displayed in the notification panel, or network statistics (such as connection duration and traffic) are provided. Tapping the notification brings your VPN app to the foreground.

## How to Develop

### Creating a VPN Extension Ability

To enable your application to support the VPN functionality, you need to create an **ExtensionAbilities** instance inherited from **VpnExtensionAbility**.

<!-- @[create_vpn_extension_ability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/VPNControl_Case/entry/src/main/module.json5) -->

``` JSON5
// Assume that the VNP application is named MyVpnExtAbility. Define it in module.json5.
"extensionAbilities": [
// ···
  {
    "name": "MyVpnExtAbility",
    "srcEntry": "./ets/vpnability/VPNExtentionAbility.ets",
    "type": "vpn"
  }
],
```

> **NOTE**
>
> If the DevEco Studio tool displays a message indicating unrecognizable **"type": "vpn"**, you need to manually add **vpn** to the **type** enums corresponding to **extensionAbilities** in the **toolchains\modulecheck\module.json** file of the SDK, clear the build cache, and restart DevEco Studio.

Next, you need to configure, start, and stop the VPN in the created **VpnExtensionAbility**.

- Establish a VPN tunnel. The following uses the UDP tunnel as an example. For details, see the **UdpConnect()** API in the [napi_init](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/VPNControl_Case/entry/src/main/cpp/napi_init.cpp) demo project.

- Use [VpnConnection.protect](../reference/apis-network-kit/js-apis-net-vpnExtension.md#protect) to enable protection for the UDP tunnel.

- Construct VPN Config parameters. For details, see [VPN Config Parameters](#description-of-vpn-config-parameters).

- Use [VpnConnection.create](../reference/apis-network-kit/js-apis-net-vpnExtension.md#create) to establish a VPN connection.

- Process data of the virtual network interface card (vNIC), such as reading or writing data.

### Starting the VPN Extension Ability

To start a connection from the VPN application, you need to call **startVpnExtensionAbility** with the **VpnExtensionAbility** information specified. Make sure that **bundleName** is the same as that of the VPN application, and **abilityName** is the name of the **VpnExtensionAbility** you created. The sample code is as follows:

<!-- @[start_vpn_extension_ability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/VPNControl_Case/entry/src/main/ets/pages/StartVpn.ets) -->

``` TypeScript
import { common, Want } from '@kit.AbilityKit';
import { vpnExtension } from '@kit.NetworkKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
// ···

const TITLE_FONT_SIZE = 35; // Title font size.
const BUTTON_FONT_SIZE = 25; // Button font size.
const BUTTON_MARGIN = 16;

let want: Want = {
  deviceId: '',
  bundleName: 'com.samples.vpncontrol_case',
  abilityName: 'MyVpnExtAbility',
};

@Entry
@Component
struct StartVpn {
  @State message: string = 'VPN';
// ···
  build() {
    Row() {
      Column() {
        // ···
        Text(this.message)
          .fontSize(TITLE_FONT_SIZE)
          .fontWeight(FontWeight.Bold)
        // ···
          .onClick(() => {
            hilog.info(0x0000, 'testTag', 'developTag', '%{public}s', 'vpn Client');
          })
        // ···
        Button($r('app.string.start_vpnExt'))
          .onClick(() => {
            // ···
              vpnExtension.startVpnExtensionAbility(want)
            // ···
          })
          .width('70%')
        // ···
          .fontSize(BUTTON_FONT_SIZE)
          .margin(BUTTON_MARGIN)
        // ···
      }.width('100%');
    }.height('100%');

  }
}
```

If your VPN app is not trusted by the user, the system displays a dialog box asking the user to authorize the VPN connection. After obtaining the authorization, the system automatically calls [onCreate](../reference/apis-network-kit/js-apis-VpnExtensionAbility.md#vpnextensionabilityoncreate) of the **VpnExtensionAbility**.

Currently, only one active VPN connection is supported. If the application calls **startVpnExtensionAbility** when a VPN connection is active, it will receive a system rejection error. In this case, you are advised to remind the user to disconnect the active VPN connection first.

### Stopping the VPN Extension Ability

To stop a VPN connection, the VPN application needs to call **stopVpnExtensionAbility** with the target **VpnExtensionAbility** specified. The system verifies the permission of the caller. The caller of **stopVpnExtensionAbility** must have obtained the VPN connection authorization of the user and can only stop the **VpnExtensionAbility** it started. Therefore, make sure that the value of **bundleName** passed by the API is the same as that of the VPN application, and the value of **abilityName** is the same as that of the target **VpnExtensionAbility**.

The sample code is as follows:

<!-- @[stop_vpn_extension_ability_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/VPNControl_Case/entry/src/main/ets/pages/StopVpn.ets) -->    

``` TypeScript
import { common, Want } from '@kit.AbilityKit';
import { vpnExtension } from '@kit.NetworkKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
```

<!-- @[stop_vpn_extension_ability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/VPNControl_Case/entry/src/main/ets/pages/StopVpn.ets) -->    

``` TypeScript
const TITLE_FONT_SIZE = 35; // Title font size.
const BUTTON_FONT_SIZE = 25; // Button font size.
const BUTTON_MARGIN = 16;

let want: Want = {
  deviceId: '',
  bundleName: 'com.samples.vpncontrol_case',
  abilityName: 'MyVpnExtAbility',
};

@Entry
@Component
struct StopVpn {
  @State message: string = 'VPN';

  // ...
  build() {
    Row() {
      Column() {
        // ...
        Text(this.message)
          .fontSize(TITLE_FONT_SIZE)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            hilog.info(0x0000, 'testTag', 'developTag', '%{public}s', 'vpn Client');
          })
        // ...
        Button('Start Extension').onClick(() => {
          vpnExtension.startVpnExtensionAbility(want);
        }).width('70%').fontSize(20).margin(16);
        Button($r('app.string.stop_vpnExt'))
          .onClick(() => {
            try {
              hilog.info(0x0000, 'testTag', 'btn end')
              vpnExtension.stopVpnExtensionAbility(want)
              // ...
            } catch (err) {
              // ...
              hilog.error(0x0000, 'testTag', 'developTag', 'stop vpnExt Fail %{public}s', JSON.stringify(err) ?? '');
            }

          })
          .width('70%')
          // ...
          .fontSize(BUTTON_FONT_SIZE)
          .margin(BUTTON_MARGIN)
      }.width('100%');
    }.height('100%');
  }
}
```

After the **VPNExtensionAbility** is stopped, call [onDestroy](../reference/apis-network-kit/js-apis-VpnExtensionAbility.md#vpnextensionabilityondestroy) to destroy the VPN connection and release related resources.

<!-- @[stop_vpn_extension_ability_on_destroy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/VPNControl_Case/entry/src/main/ets/pages/StopVpn.ets) -->    

``` TypeScript
private context = this.getUIContext().getHostContext() as common.VpnExtensionContext;
private vpnConnection: vpnExtension.VpnConnection = vpnExtension.createVpnConnection(this.context);

Destroy() {
  hilog.info(0x0000, 'testTag', 'developTag', '%{public}s', 'vpn Destroy');
  // ...
  this.vpnConnection.destroy().then(() => {
    hilog.info(0x0000, 'testTag', 'developTag', '%{public}s', 'vpn Destroy Success');
    // ...
  }).catch((err: Error) => {
     hilog.error(0x0000, 'testTag', 'developTag', 'vpn Destroy Failed: %{public}s', JSON.stringify(err) ?? '');
    // ...
  })
}
```

### Generating a VPN ID

When creating a VPN, generate a VPN ID as the unique identifier of the VPN.

The sample code is as follows:

<!-- @[get_vpn_id_ability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/VPNControl_Case/entry/src/main/ets/vpnability/GetVpnIdTest.ets) --> 

``` TypeScript
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
// ...
export class VpnTest extends VpnExtensionAbility {
  public vpnId: string = '';
  // ...
  getVpnId() {
    // ...
      let vpnConnection = vpnExtension.createVpnConnection(this.context);
      vpnConnection?.generateVpnId().then((data) => {
        if (data) {
          this.vpnId = data;
        }
      });
    // ...
  }
};
```

### Disconnecting from the VPN

To disconnect from the VPN, use the sample code below:

<!-- @[destroy_vpn_ability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/VPNControl_Case/entry/src/main/ets/vpnability/DestroyVpnTest.ets) --> 

``` TypeScript
import { vpnExtension, VpnExtensionAbility } from '@kit.NetworkKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
// ...
export class VpnTest extends VpnExtensionAbility {
  public vpnId: string = 'test_vpn_id';
  public vpnConnection: vpnExtension.VpnConnection | undefined;
  // ...
  destroy() {
    // ...
      this.vpnConnection = vpnExtension.createVpnConnection(this.context);
      hilog.info(0x0000, 'testTag', 'create success');
      this.vpnConnection?.destroy(this.vpnId);
      // ...
  }
};
```

## Service Lifecycle Management

To ensure network connectivity, the system automatically stops the VPN connection when detecting that the VPN application is abnormal:

- The application process that calls **startVpnExtensionAbility** exits.

- The VPN service process is destroyed.

## Description of VPN Config parameters

<!--Table: 20%; 20%; 10%; 10%; 40%-->

| Name      | Type                                      | Read-only|Optional| Description         |
| ------------------- | ------------------------------------------------------------ | ---- | ---|------------------------------------------------------------ |
| addresses           | Array\<[LinkAddress](../reference/apis-network-kit/js-apis-net-connection.md#linkaddress)\> | No  |No| IP addresses of virtual network interface cards (vNICs).                                         |
| routes              | Array\<[RouteInfo](../reference/apis-network-kit/js-apis-net-connection.md#routeinfo)\> | No   | Yes|Route information of the VPN virtual network interface card (up to 1024 routes can be configured).              |
| dnsAddresses        | Array\<string\>                                              | No  |Yes|IP addresses of DNS servers. After the IP address is configured, when the VPN is active and proxy-enabled applications access the Internet, the configured DNS server will be used for DNS queries.|
| searchDomains       | Array\<string\>                                              | No  |Yes|List of DNS search domains.                                           |
| mtu                 | number                                                       | No   |Yes| Maximum transmission unit (MTU) value (in bytes).                               |
| isIPv4Accepted      | boolean                                                      | No  |Yes|Whether IPv4 is supported. The default value is **true**. The value **true** indicates that IPV4 is supported, and the value **false** indicates the opposite.                                |
| isIPv6Accepted      | boolean                                                      | No  |Yes|Whether IPv6 is supported. The default value is **false**. The value **true** indicates that IPV6 is supported, and the value **false** indicates the opposite.                               |
| isInternal          | boolean                                                      | No  |Yes| Whether the built-in VPN is supported. The default value is **false**. The value **true** indicates that the built-in VPN is supported, and the value **false** indicates the opposite.                            |
| isBlocking          | boolean                                                      | No  |Yes|Whether the blocking mode is used. The default value is **false**. The value **true** indicates that the blocking mode is used, and the value **false** indicates the opposite.                               |
| trustedApplications | Array\<string\>                                              | No  | Yes|List of trusted applications, which are represented by package names of the string type. After such a list is configured, only the applications in the list can be proxied by the VPN according to the specified **routes**.<br>Note: Configure either **trustedApplications** or **blockedApplications** as they are mutually exclusive.             |
| blockedApplications | Array\<string\>                                              | No  | Yes|List of blocked applications, which are represented by package names of the string type. After such a list is configured, only applications that are not in the list can be proxied by the VPN according to the specified **routes**.<br>Note: Configure either **trustedApplications** or **blockedApplications** as they are mutually exclusive.         |

**Example**

<!-- @[vpn_config_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/VPNControl_Case/entry/src/main/ets/pages/SetupVpn.ets) -->    

``` TypeScript
import { vpnExtension } from '@kit.NetworkKit';
import { common } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
```

```ts
let vpnConfig: vpnExtension.VpnConfig = {
  // Configure the IP address of the vNIC.
  addresses: [{
    address: {
      address:'192.x.x.5',
      family:1
    },
    prefixLength:24
  }],
  // Configure route information.
  routes: [{
    // Set the name of the vNIC, which has a fixed value of vpn-tun.
    interface: 'vpn-tun',
    destination: {
      address: {
        address:'10.x.x.8',
        family:1,
        port:8080
      },
      prefixLength:24
    },
    gateway: {
      address:'10.x.x.5',
      family:1,
      port:8080
    },
    hasGateway: false,
    isDefaultRoute: false,
  }],
  // Configure the MTU.
  mtu: 1400,
  // Configure IP addresses of DNS serves.
  dnsAddresses: ['223.x.x.5', '223.x.x.6'],
  // Trusted app information list. When this item is configured, the blocked app information list must be empty.
  trustedApplications: ['com.test.browser'],
  // Blocked app information list. When this item is configured, the trusted app information list must be empty.
  blockedApplications: ['com.test.games'],
}
```

<!-- @[vpn_config_parameters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/VPNControl_Case/entry/src/main/ets/pages/SetupVpn.ets) -->    

``` TypeScript
let context = this.getUIContext().getHostContext() as common.VpnExtensionContext;
let vpnConnection: vpnExtension.VpnConnection = vpnExtension.createVpnConnection(context);
// Create a VPN connection and apply the configuration.
vpnConnection.create(vpnConfig).then((data) => {
  hilog.info(0x0000, 'testTag', 'vpn create ' + JSON.stringify(data));
  // ...
})
```

## VPN Demo

The OpenHarmony project provides a sample application named [VPN](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/VPNControl_Case), which showcases how to implement the VPN service.