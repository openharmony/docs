# Ethernet Connection Management

The Ethernet Connection Management module provides wired network capabilities, which allow users to set the IP address, subnet mask, gateway, and Domain Name System (DNS) server of a wired network.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import ethernet from '@ohos.net.ethernet'
```

## ethernet.setIfaceConfig

setIfaceConfig(iface: string, ic: InterfaceConfiguration, callback: AsyncCallback\<void>): void;

Sets the network interface configuration. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                             | Mandatory| Description                                      |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------ |
| iface    | string                                            | Yes  | Name of the network interface.                                    |
| ic       | [InterfaceConfiguration](#interfaceconfiguration) | Yes  | Network interface configuration to set.                  |
| callback | AsyncCallback\<void>                     | Yes  | Callback used to return the result. If the operation is successful, the return result is empty. If the operation fails, an error code is returned.|

**Example**

```js
ethernet.setIfaceConfig("eth0", {mode:ethernet.STATIC,ipAddr:"192.168.1.123", routeAddr:"192.168.1.1",
    gateAddr:"192.168.1.1", maskAddr:"255.255.255.0", dnsAddr0:"1.1.1.1", dnsAddr1:"2.2.2.2"},
    (error) => {
        if (error) {
            console.log("setIfaceConfig callback error = " + error);
        } else {
            console.log("setIfaceConfig callback ok ");
        }
    });
```

## ethernet.setIfaceConfig

setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>;

Sets the network interface configuration. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type                                             | Mandatory| Description                    |
| ------ | ------------------------------------------------- | ---- | ------------------------ |
| iface  | string                                            | Yes  | Name of the network interface.                  |
| ic     | [InterfaceConfiguration](#interfaceconfiguration) | Yes  | Network interface configuration to set.|

**Return value**

| Type               | Description                                                       |
| ------------------- | ----------------------------------------------------------- |
| Promise\<void>       | Promise that returns no value.|

**Example**

```js
ethernet.setIfaceConfig("eth0", {mode:ethernet.STATIC,ipAddr:"192.168.1.123", routeAddr:"192.168.1.1",
    gateAddr:"192.168.1.1", maskAddr:"255.255.255.0", dnsAddr0:"1.1.1.1", dnsAddr1:"2.2.2.2"}).then(() => {
    console.log("setIfaceConfig promiss ok ");
}).catch((error) => {
    console.log("setIfaceConfig promiss error = " + error);
});
```

## ethernet.getIfaceConfig

getIfaceConfig(iface: string, callback: AsyncCallback\<InterfaceConfiguration>): void;

Obtains the configuration of a network interface. This API uses an asynchronous callback to return the result. 

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                           | Mandatory | Description        |
| -------- | ----------------------------------------------- | ----- | ------------ |
| iface    | string                                          | Yes   | Name of the network interface.|
| callback | AsyncCallback\<[InterfaceConfiguration](#interfaceconfiguration)> | Yes   | Callback used to return the configuration.  |

**Example**

```js
ethernet.getIfaceConfig("eth0", (error, value) => {
    if (error) {
        console.log("getIfaceConfig  callback error = " + error);
    } else {
        console.log("getIfaceConfig callback mode = " + value.mode);
        console.log("getIfaceConfig callback ipAddr = " + value.ipAddr);
        console.log("getIfaceConfig callback routeAddr = " + value.routeAddr);
        console.log("getIfaceConfig callback gateAddr = " + value.gateAddr);
        console.log("getIfaceConfig callback maskAddr = " + value.maskAddr);
        console.log("getIfaceConfig callback dns0Addr = " + value.dns0Addr);
        console.log("getIfaceConfig callback dns1Addr = " + value.dns1Addr);
    }
});
```

## ethernet.getIfaceConfig

getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>;

Obtains the configuration of a network interface. This API uses a promise to return the result. 

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description        |
| -------- | --------------------------------------- | ---- | ------------ |
| iface    | string                                  | Yes  | Name of the network interface.|

**Return value**

| Type                             | Description                              |
| --------------------------------- | ---------------------------------- |
| Promise\<[InterfaceConfiguration](#interfaceconfiguration)>   | Promise used to return the configuration.       |

**Example**

```js
ethernet.getIfaceConfig("eth0").then((data) => {
    console.log("getIfaceConfig promiss mode = " + data.mode);
    console.log("getIfaceConfig promiss ipAddr = " + data.ipAddr);
    console.log("getIfaceConfig promiss routeAddr = " + data.routeAddr);
    console.log("getIfaceConfig promiss gateAddr = " + data.gateAddr);
    console.log("getIfaceConfig promiss maskAddr = " + data.maskAddr);
    console.log("getIfaceConfig promiss dns0Addr = " + data.dns0Addr);
    console.log("getIfaceConfig promiss dns1Addr = " + data.dns1Addr);
}).catch((error) => {
    console.log("getIfaceConfig promiss error = " + error);
});
```

## ethernet.isIfaceActive

isIfaceActive(iface?: string, callback: AsyncCallback\<number>): void;

Checks whether a network interface is active. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                                              |
| -------- | --------------------------- | ---- | -------------------------------------------------- |
| iface    | string                      | No  | Name of the network interface. If this parameter is left empty, the API checks for any active network interface.            |
| callback | AsyncCallback\<number>       | Yes  | Callback used to return the result. The value **1** means that the network interface is active, **0** means that the network interface is inactive, and any other value means that an error has occurred.|

**Example**

```js
ethernet.isIfaceActive("eth0", (error, value) => {
  if (error) {
    console.log("whether2Activate callback error = " + error);
  } else {
    console.log("whether2Activate callback = " + value);
  }
});
```

## ethernet.isIfaceActive

isIfaceActive(iface?: string): Promise\<number>;

Checks whether a network interface is active. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| iface  | string | No  | Name of the network interface. If this parameter is left empty, the API checks for any active network interface.|

**Return value**

| Type           | Description                                                              |
| ----------------| ------------------------------------------------------------------ |
| Promise\<number> | Promise used to return the result. The value **1** means that the network interface is active, **0** means that the network interface is inactive, and any other value means that an error has occurred.|

**Example**

```js
ethernet.isIfaceActive("eth0").then((data) => {
  console.log("isIfaceActive promiss = " + data);
}).catch((error) => {
  console.log("isIfaceActive promiss error = " + error);
});
```

## ethernet.getAllActiveIfaces

getAllActiveIfaces(callback: AsyncCallback\<Array\<string>>): void;

Obtains all active network interfaces. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                          |
| -------- | ------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback\<Array\<string>>         | Yes  | Callback used to return all the active network interface names obtained.|

**Example**

```js
ethernet.getAllActiveIfaces((error, value) => {
  if (error) {
    console.log("getAllActiveIfaces callback error = " + error);
  } else {
      console.log("getAllActiveIfaces callback value.length = " + value.length);
    for (let i = 0; i < value.length; i++) {
      console.log("getAllActiveIfaces callback = " + value[i]);
    }
  }
});
```

## ethernet.getAllActiveIfaces

getAllActiveIfaces(): Promise\<Array\<string>>;

Obtains all active network interfaces. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

**Return value**

| Type                          | Description                                           |
| ------------------------------ | ----------------------------------------------- |
| Promise\<Array\<string>>         | Promise used to return all the active network interface names obtained.|

**Example**

```js
ethernet.getAllActiveIfaces().then((data) => {
    console.log("getAllActiveIfaces promiss data.length = " + data.length);
  for (let i = 0; i < data.length; i++) {
    console.log("getAllActiveIfaces promiss  = " + data[i]);
  }
}).catch((error) => {
  console.log("getAllActiveIfaces promiss error = " + error);
});
```

## InterfaceConfiguration

Defines the network configuration for the Ethernet connection.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name                 | Type                               | Description                                                        |
| ----------------------- | ----------------------------------- | ------------------------------------------------------------ |
| mode         | [IPSetMode](#ipsetmode) | Configuration mode of the Ethernet connection.|
| ipAddr       | string                  | Static IP address of the Ethernet connection. The value must be an IPv4 address, which is a 32-bit number displayed in dotted decimal notation and each 8-bit field ranges from 0 to 255. This parameter does not need to be configured in Dynamic Host Configuration Protocol (DHCP) mode.|
| route        | string                  | Route of the Ethernet connection. The value must be an IPv4 address. This parameter does not need to be configured in DHCP mode.|
| gateway      | string                  | Gateway of the Ethernet connection. The value must be an IPv4 address. This parameter does not need to be configured in DHCP mode.|
| netMask      | string                  | Subnet mask of the Ethernet connection. The value must be an IPv4 address. This parameter does not need to be configured in DHCP mode.|
| dnsServers   | string                  | DNS server addresses of the Ethernet connection. The value must be an IPv4 address. This parameter does not need to be configured in DHCP mode. Multiple addresses are separated by commas (,).|

## IPSetMode

Defines the configuration mode of the Ethernet connection.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name                 | Value  | Description                  |
| ------------------------ | ---- | ---------------------- |
| STATIC | 0 | Static configuration.|
| DHCP   | 1 | Dynamic configuration.|
