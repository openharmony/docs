# Ethernet Connection (For System Applications Only)

## Overview

The Ethernet Connection module allows a device to access the Internet through a network cable. After a device is connected to the Ethernet through a network cable, the device can obtain a series of network attributes, such as the dynamically allocated IP address, subnet mask, gateway, and DNS. You can manually configure and obtain the network attributes of the device in static mode.

> **NOTE**
> To maximize the application running efficiency, most API calls are called asynchronously in callback or promise mode. The following code examples use the promise mode. For details about the APIs, see [API Reference](../reference/apis-network-kit/js-apis-net-ethernet-sys.md).

## **Constraints**

- Programming language: JS
- The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Scenario

Typical application scenarios of Ethernet connection are as follows:

- Dynamically assigning a series of network attributes, such as the IP address, subnet mask, gateway, and DNS in DHCP mode to enable network access
- Configuring a series of network attributes, such as the IP address, subnet mask, gateway, and DNS, in static mode to enable network access.

The following describes the development procedure specific to each application scenario.

## Available APIs

For the complete list of APIs and example code, see [Ethernet Connection](../reference/apis-network-kit/js-apis-net-ethernet-sys.md).

| Type| API| Description|
| ---- | ---- | ---- |
| setIfaceConfig(iface: string, ic: InterfaceConfiguration, callback: AsyncCallback\<void>): void | Configures the network attributes of the specified Ethernet network. This API uses an asynchronous callback to return the result.|
| getIfaceConfig(iface: string, callback: AsyncCallback\<InterfaceConfiguration>): void | Obtains the network attributes of the specified Ethernet network. This API uses an asynchronous callback to return the result.|
| isIfaceActive(iface: string, callback: AsyncCallback\<number>): void | Checks whether the specified network port is active. This API uses an asynchronous callback to return the result.|
| getAllActiveIfaces(callback: AsyncCallback\<Array\<string>>): void; | Obtains the list of all active network ports. This API uses an asynchronous callback to return the result.|
| on(type: 'interfaceStateChange', callback: Callback\<{ iface: string, active: boolean }\>): void; | Subscribes to interface state change events.|
| off(type: 'interfaceStateChange', callback?: Callback\<{ iface: string, active: boolean }\>): void; | Unsubscribes from interface state change events.|

## Ethernet Connection – DHCP Mode

1. Use a network cable to connect the device to a network port.
2. Import the **ethernet** namespace from **@kit.NetworkKit**.
3. Call **getAllActiveIfaces** to obtain the list of all active network ports, for example, **eth0** and **eth1**.
4. Call **isIfaceActive** in user mode to check whether the **eth0** port is active.
5. Call **getIfaceConfig** in user mode to obtain the static network attributes of the **eth0** port. By default, an unconfigured Ethernet network uses the DHCP mode, in which the Ethernet network obtains the automatically assigned network attributes.

```ts
// Import the ethernet namespace from @kit.NetworkKit.
import { ethernet } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Call getAllActiveIfaces to obtain the list of all active network ports.
ethernet.getAllActiveIfaces().then((data: string[]) => {
  console.log("getAllActiveIfaces promise data.length = " + JSON.stringify(data.length));
  for (let i = 0; i < data.length; i++) {
    console.log("getAllActiveIfaces promise  = " + JSON.stringify(data[i]));
  }
}).catch((error:BusinessError) => {
  console.log("getAllActiveIfaces promise error = " + JSON.stringify(error));
});

// Call isIfaceActive to check whether the specified network port is active.
ethernet.isIfaceActive("eth0").then((data: number) => {
  console.log("isIfaceActive promise = " + JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.log("isIfaceActive promise error = " + JSON.stringify(error));
});

// Call getIfaceConfig to obtain the network attributes of the specified Ethernet network.
ethernet.getIfaceConfig("eth0").then((data: ethernet.InterfaceConfiguration) => {
  console.log("getIfaceConfig promise mode = " + JSON.stringify(data.mode));
  console.log("getIfaceConfig promise ipAddr = " + JSON.stringify(data.ipAddr));
  console.log("getIfaceConfig promise route = " + JSON.stringify(data.route));
  console.log("getIfaceConfig promise gateway = " + JSON.stringify(data.gateway));
  console.log("getIfaceConfig promise netMask = " + JSON.stringify(data.netMask));
  console.log("getIfaceConfig promise dnsServers = " + JSON.stringify(data.dnsServers));
}).catch((error: BusinessError) => {
  console.log("getIfaceConfig promise error = " + JSON.stringify(error));
});
```

## Ethernet Connection – Static Mode

### How to Develop

1. Use a network cable to connect the device to a network port.
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
  console.log("getAllActiveIfaces promise data.length = " + JSON.stringify(data.length));
  for (let i = 0; i < data.length; i++) {
    console.log("getAllActiveIfaces promise  = " + JSON.stringify(data[i]));
  }
}).catch((error:BusinessError) => {
  console.log("getAllActiveIfaces promise error = " + JSON.stringify(error));
});

// Call isIfaceActive to check whether the specified network port is active.
ethernet.isIfaceActive("eth0").then((data: number) => {
  console.log("isIfaceActive promise = " + JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.log("isIfaceActive promise error = " + JSON.stringify(error));
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
  console.log("setIfaceConfig promise ok");
}).catch((error: BusinessError)  => {
  console.log("setIfaceConfig promise error = " + JSON.stringify(error));
});

// Call getIfaceConfig to obtain the network attributes of the specified Ethernet network.
ethernet.getIfaceConfig("eth0").then((data: ethernet.InterfaceConfiguration) => {
  console.log("getIfaceConfig promise mode = " + JSON.stringify(data.mode));
  console.log("getIfaceConfig promise ipAddr = " + JSON.stringify(data.ipAddr));
  console.log("getIfaceConfig promise route = " + JSON.stringify(data.route));
  console.log("getIfaceConfig promise gateway = " + JSON.stringify(data.gateway));
  console.log("getIfaceConfig promise netMask = " + JSON.stringify(data.netMask));
  console.log("getIfaceConfig promise dnsServers = " + JSON.stringify(data.dnsServers));
}).catch((error: BusinessError) => {
  console.log("getIfaceConfig promise error = " + JSON.stringify(error));
});
```

## Subscribes the status change of network device interfaces.

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
  console.log(JSON.stringify(data));
});

// Unsubscribe from interfaceStateChange events.
ethernet.off('interfaceStateChange');
```
