# Ethernet Connection Management (for System Applications Only)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=742fd8e7f742ee980eb300ddfd075065ca362dff translatedAt=2026-08-13T03:08:03.569Z pushedAt=2026-08-13T06:33:11.131Z -->

## Overview

The Ethernet connection function provides the capability for a device to access the Internet through a hardware interface by inserting a network cable. After a device is connected to the network cable, it can obtain a series of dynamically assigned network attributes, such as the IP address, subnet mask, gateway, and DNS. In static mode, you can manually configure and obtain the network attributes of the device.

> **NOTE**
> To maximize the app running efficiency, most API calls are asynchronous. For asynchronous API calls, both callback and promise modes are provided. The following examples use the promise mode. For details about more modes, see [@ohos.net.ethernet (Ethernet Connection Management)](../reference/apis-network-kit/js-apis-net-ethernet-sys.md).

## Constraint

- Programming language: JS

- The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## When to Use

Typical application scenarios of Ethernet connection are as follows:

- In DHCP mode, dynamically assigning a series of network attributes, such as the IP address, subnet mask, gateway, and DNS, to enable network access.

- In static mode, statically configuring a series of network attributes, such as the IP address, subnet mask, gateway, and DNS, to enable network access.

The following describes the development procedure specific to each application scenario.

## Available APIs

For the complete list of APIs and example code, see [Ethernet Connection](../reference/apis-network-kit/js-apis-net-ethernet-sys.md).

| Interface Name | Description |
| ---- | ---- |
| setIfaceConfig(iface: string, ic: InterfaceConfiguration, callback: AsyncCallback\<void>): void | Configures the network attributes of the specified Ethernet network. **iface** indicates the network port name, and **ic** indicates the configuration information. This API uses an asynchronous callback to return the result. |
| getIfaceConfig(iface: string, callback: AsyncCallback\<InterfaceConfiguration>): void | Obtains the network attributes of the specified Ethernet network. **iface** indicates the network port name. This API uses an asynchronous callback to return the result. |
| isIfaceActive(iface: string, callback: AsyncCallback\<number>): void | Checks whether the specified network port is active. **iface** indicates the network port name. This API uses an asynchronous callback to return the result. |
| getAllActiveIfaces(callback: AsyncCallback\<Array\<string>>): void | Obtains the list of all active network ports. This API uses an asynchronous callback to return the result. |
| on(type: 'interfaceStateChange', callback: Callback\<{ iface: string, active: boolean }\>): void | Subscribes to interface state change events. |
| off(type: 'interfaceStateChange', callback?: Callback\<{ iface: string, active: boolean }\>): void | Unsubscribes from interface state change events. |

## Ethernet Connection – DHCP Mode

1. Use a network cable to connect the device to the **eth** network port.

2. Import the **ethernet** namespace from **@kit.NetworkKit**.

3. Call **getAllActiveIfaces** to obtain the list of all active network ports, for example, **eth0** and **eth1**.

4. Call **isIfaceActive** in user mode to check whether the **eth0** port is active.

5. Call **getIfaceConfig** in user mode to obtain the network attributes of the **eth0** port. By default, an unconfigured Ethernet network uses the DHCP mode, in which the Ethernet network obtains the automatically assigned network attributes.

```ts
// Import the ethernet namespace from @kit.NetworkKit.
import { ethernet } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Call getAllActiveIfaces to obtain the list of all active network ports.
ethernet.getAllActiveIfaces().then((data: string[]) => {
  console.info("getAllActiveIfaces promise data.length = " + JSON.stringify(data.length));
  for (let i = 0; i < data.length; i++) {
    console.info("getAllActiveIfaces promise  = " + JSON.stringify(data[i]));
  }
}).catch((error:BusinessError) => {
  console.error("getAllActiveIfaces promise error = " + JSON.stringify(error));
});

// Call isIfaceActive to check whether the specified network port is active.
ethernet.isIfaceActive("eth0").then((data: number) => {
  console.info("isIfaceActive promise = " + JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.error("isIfaceActive promise error = " + JSON.stringify(error));
});

// Call getIfaceConfig to obtain the network attributes of the specified Ethernet network.
ethernet.getIfaceConfig("eth0").then((data: ethernet.InterfaceConfiguration) => {
  console.info("getIfaceConfig promise mode = " + JSON.stringify(data.mode));
  console.info("getIfaceConfig promise ipAddr = " + JSON.stringify(data.ipAddr));
  console.info("getIfaceConfig promise route = " + JSON.stringify(data.route));
  console.info("getIfaceConfig promise gateway = " + JSON.stringify(data.gateway));
  console.info("getIfaceConfig promise netMask = " + JSON.stringify(data.netMask));
  console.info("getIfaceConfig promise dnsServers = " + JSON.stringify(data.dnsServers));
}).catch((error: BusinessError) => {
  console.error("getIfaceConfig promise error = " + JSON.stringify(error));
});
```

## Ethernet Connection – Static Mode

### How to Develop

1. Use a network cable to connect the device to the **eth** network port.

2. Import the **ethernet** namespace from **@kit.NetworkKit**.

3. Call **getAllActiveIfaces** in user mode to obtain the list of all active network ports, for example, **eth0** and **eth1**.

4. Call **isIfaceActive** in user mode to check whether the **eth0** port is active.

5. Call **setIfaceConfig** in user mode to set the **eth0** port to the static mode, in which you need to manually assign the network attributes (including the IP address, subnet mask, gateway, and DNS).

6. Call **getIfaceConfig** in user mode to obtain the static network attributes of the **eth0** port.

```ts
// Import the ethernet namespace from @kit.NetworkKit.
import { ethernet } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Call getAllActiveIfaces to obtain the list of all active network ports.
ethernet.getAllActiveIfaces().then((data: string[]) => {
  console.info("getAllActiveIfaces promise data.length = " + JSON.stringify(data.length));
  for (let i = 0; i < data.length; i++) {
    console.info("getAllActiveIfaces promise  = " + JSON.stringify(data[i]));
  }
}).catch((error:BusinessError) => {
  console.error("getAllActiveIfaces promise error = " + JSON.stringify(error));
});

// Call isIfaceActive to check whether the specified network port is active.
ethernet.isIfaceActive("eth0").then((data: number) => {
  console.info("isIfaceActive promise = " + JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.error("isIfaceActive promise error = " + JSON.stringify(error));
});

// Call setIfaceConfig to configure the network attributes of the specified Ethernet network.
let config: ethernet.InterfaceConfiguration = {
  mode: 0,
  ipAddr: "192.168.xx.xxx",
  route: "192.168.xx.xxx",
  gateway: "192.168.xx.xxx",
  netMask: "255.255.255.0",
  dnsServers: "1.1.1.1"
};

const setConfigPromise = ethernet.setIfaceConfig("eth0", config);

setConfigPromise.then(() => {
  console.info("setIfaceConfig promise ok");
}).catch((error: BusinessError)  => {
  console.error("setIfaceConfig promise error = " + JSON.stringify(error));
});

// Call getIfaceConfig to obtain the network attributes of the specified Ethernet network.
ethernet.getIfaceConfig("eth0").then((data: ethernet.InterfaceConfiguration) => {
  console.info("getIfaceConfig promise mode = " + JSON.stringify(data.mode));
  console.info("getIfaceConfig promise ipAddr = " + JSON.stringify(data.ipAddr));
  console.info("getIfaceConfig promise route = " + JSON.stringify(data.route));
  console.info("getIfaceConfig promise gateway = " + JSON.stringify(data.gateway));
  console.info("getIfaceConfig promise netMask = " + JSON.stringify(data.netMask));
  console.info("getIfaceConfig promise dnsServers = " + JSON.stringify(data.dnsServers));
}).catch((error: BusinessError) => {
  console.error("getIfaceConfig promise error = " + JSON.stringify(error));
});
```

## Subscribing to Status Changes of Network Device Interfaces

### How to Develop

1. Import the **ethernet** namespace from **@kit.NetworkKit**.

2. Call the **on()** method to subscribe to **interfaceStateChange** events. It is up to you whether to listen for **interfaceStateChange** events.

3. Check whether an **interfaceStateChange** event is triggered when the interface state changes.

4. Call the **off()** method to unsubscribe from **interfaceStateChange** events.

```ts
// Import the ethernet namespace from @kit.NetworkKit.
import { ethernet } from '@kit.NetworkKit';

// Subscribe to interfaceStateChange events.
class EthernetData{
  iface: string = ""
  active: boolean = false
}

ethernet.on('interfaceStateChange', (data: EthernetData) => {
  console.info(JSON.stringify(data));
});

// Unsubscribe from interfaceStateChange events.
ethernet.off('interfaceStateChange');
```