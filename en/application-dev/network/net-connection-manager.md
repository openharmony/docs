# Network Connection Management

## Introduction

The Network Connection Management module provides basic network management capabilities, including management of Wi-Fi/cellular/Ethernet connection priorities, network quality evaluation, subscription to network connection status changes, query of network connection information, and DNS resolution.

> **NOTE**
>
> To maximize the application running efficiency, most API calls are called asynchronously in callback or promise mode. The following code examples use the promise mode. For details about the APIs, see [API Reference](../reference/apis-network-kit/js-apis-net-connection.md).

## Basic Concepts

- Producer: a provider of data networks,  such as Wi-Fi, cellular, and Ethernet.
- Consumer: a user of data networks, for example, an application or a system service.
- Network probe: a mechanism used to detect the network availability to prevent the switch from an available network to an unavailable network. The probe type can be binding network detection, DNS detection, HTTP detection, or HTTPS detection.
- Network selection: a mechanism used to select the optimal network when multiple networks coexist. It is triggered when the network status, network information, or network quality evaluation score changes.
- Default network: network where the default route is located.

## **Constraints**

- Programming language: JS
- The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## When to Use

Typical application scenarios of network connection management are as follows:

- Subscribing to status changes of the specified network
- Obtaining the list of all registered networks
- Querying network connection information based on the data network
- Resolving the domain name of a network to obtain all IP addresses

The following describes the development procedure specific to each application scenario.

## Available APIs

For the complete list of APIs and example code, see [Network Connection Management](../reference/apis-network-kit/js-apis-net-connection.md).

| API| Description|
| ---- | ---- |
| getDefaultNet(callback: AsyncCallback\<NetHandle>): void; |Creates a **NetHandle** object that contains the **netId** of the default network. This API uses an asynchronous callback to return the result.|
| <!--DelRow--> getGlobalHttpProxy(callback: AsyncCallback\<HttpProxy>): void;| Obtains the global HTTP proxy for the network. This API uses an asynchronous callback to return the result.|
| <!--DelRow--> setGlobalHttpProxy(httpProxy: HttpProxy, callback: AsyncCallback\<void>): void;| Sets the global HTTP proxy for the network. This API uses an asynchronous callback to return the result.|
| setAppHttpProxy(httpProxy: HttpProxy): void;| Sets the application-level HTTP proxy configuration of the network.|
| getAppNet(callback: AsyncCallback\<NetHandle>): void;| Obtains a **NetHandle** object that contains the **netId** of the network bound to the application. This API uses an asynchronous callback to return the result.|
| setAppNet(netHandle: NetHandle, callback: AsyncCallback\<void>): void;| Binds an application to the specified network. The application can access the external network only through this network. This API uses an asynchronous callback to return the result.|
| getDefaultNetSync(): NetHandle; |Obtains the default active data network in synchronous mode. You can use **getNetCapabilities** to obtain information such as the network type and capabilities.|
| hasDefaultNet(callback: AsyncCallback\<boolean>): void; |Checks whether the default data network is activated. This API uses an asynchronous callback to return the result.|
| getAllNets(callback: AsyncCallback\<Array\<NetHandle>>): void;| Obtains the list of **NetHandle** objects of the connected network. This API uses an asynchronous callback to return the result.|
| getConnectionProperties(netHandle: NetHandle, callback: AsyncCallback\<ConnectionProperties>): void; |Obtains network connection information of the network corresponding to the **netHandle**. This API uses an asynchronous callback to return the result.|
| getNetCapabilities(netHandle: NetHandle, callback: AsyncCallback\<NetCapabilities>): void; |Obtains capability information of the network corresponding to the **netHandle**. This API uses an asynchronous callback to return the result.|
| isDefaultNetMetered(callback: AsyncCallback\<boolean>): void; |Checks whether the data traffic usage on the current network is metered. This API uses an asynchronous callback to return the result.|
| reportNetConnected(netHandle: NetHandle, callback: AsyncCallback\<void>): void;| Reports a **netAvailable** event to NetManager. If this API is called, the application considers that its network status (ohos.net.connection.NetCap.NET_CAPABILITY_VAILDATED) is inconsistent with that of NetManager. This API uses an asynchronous callback to return the result.|
| reportNetDisconnected(netHandle: NetHandle, callback: AsyncCallback\<void>): void;| Reports a **netUnavailable** event to NetManager. If this API is called, the application considers that its network status (ohos.net.connection.NetCap.NET_CAPABILITY_VAILDATED) is inconsistent with that of NetManager. This API uses an asynchronous callback to return the result.|
| getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void; |Obtains all IP addresses of the specified network by resolving the domain name. This API uses an asynchronous callback to return the result.|
| <!--DelRow--> enableAirplaneMode(callback: AsyncCallback\<void>): void; | Enables the airplane mode. This API uses an asynchronous callback to return the result.|
| <!--DelRow--> disableAirplaneMode(callback: AsyncCallback\<void>): void;| Disables the airplane mode. This API uses an asynchronous callback to return the result.|
| createNetConnection(netSpecifier?: NetSpecifier, timeout?: number): NetConnection; | Creates a **NetConnection** object. **netSpecifier** specifies the network to be concerned. **timeout** specifies the timeout interval in ms. **timeout** is configurable only when **netSpecifier** is specified. If neither of them is present, the default network is used.|
| bindSocket(socketParam: TCPSocket \| UDPSocket, callback: AsyncCallback\<void>): void; | Binds TCPSocket or UDPSocket to the current network. This API uses an asynchronous callback to return the result.|
| getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void; |Obtains an IP address of the specified network by resolving the domain name. This API uses an asynchronous callback to return the result.|
| on(type: 'netAvailable', callback: Callback\<NetHandle>): void;                   |Subscribes to **netAvailable** events.|
| on(type: 'netCapabilitiesChange', callback: Callback\<NetCapabilityInfo\>): void; |Subscribes to **netCapabilitiesChange** events.|
| on(type: 'netConnectionPropertiesChange', callback: Callback\<{ netHandle: NetHandle, connectionProperties: ConnectionProperties }>): void; |Subscribes to **netConnectionPropertiesChange** events.|
| on(type: 'netBlockStatusChange', callback: Callback<{ netHandle: NetHandle, blocked: boolean }>): void; |Registers a listener for **netBlockStatusChange** events. This API uses an asynchronous callback to return the result.|
| on(type: 'netLost', callback: Callback\<NetHandle>): void; |Subscribes to **netLost** events.|
| on(type: 'netUnavailable', callback: Callback\<void>): void; |Subscribes to **netUnavailable** events.|
| register(callback: AsyncCallback\<void>): void; |Subscribes to network status changes.|
| unregister(callback: AsyncCallback\<void>): void; |Unsubscribes from network status changes.|

## Subscribing to Status Changes of the Specified Network

1. Declare the required permission: **ohos.permission.GET_NETWORK_INFO**.
This permission is of the **normal** level. Before applying for the permission, ensure that the [basic principles for permission management](../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Declare the permissions required by your application. For details, see [Declaring Permissions in the Configuration File](accesstoken-guidelines.md#declaring-permissions-in-the configuration-file).

2. Import the **connection** namespace from **@kit.NetworkKit**.

3. Call [createNetConnection](../reference/apis-network-kit/js-apis-net-connection.md#connectioncreatenetconnection) to create a **NetConnection** object. You can specify the network type, capability, and timeout interval. If you do not specify parameters, the default values will be used. 

4. Call [on()](../reference/apis-network-kit/js-apis-net-connection.md#onnetavailable) to subscribe to desired events. You must pass in **type** and **callback**.

5. Call [register()](../reference/apis-network-kit/js-apis-net-connection.md#register) to subscribe to network status changes of the specified network.

6. When the network is available, the callback will be invoked to return the **netAvailable** event. When the network is unavailable, the callback will be invoked to return the **netUnavailable** event.

7. Call [unregister()](../reference/apis-network-kit/js-apis-net-connection.md#unregister) to unsubscribe from the network status changes.

```ts
// Import the required namespaces.
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let netSpecifier: connection.NetSpecifier = {
  netCapabilities: {
    // Assume that the default network is Wi-Fi. If you need to create a cellular network connection, set the network type to CELLULAR.
    bearerTypes: [connection.NetBearType.BEARER_CELLULAR],
    // Set the network capability to INTERNET.
    networkCap: [connection.NetCap.NET_CAPABILITY_INTERNET]
  },
};

// Set the timeout value to 10s. The default value is 0.
let timeout = 10 * 1000;

// Create a NetConnection object.
let conn = connection.createNetConnection(netSpecifier, timeout);

// Register an observer for network status changes.
conn.register((err: BusinessError, data: void) => {
  console.log(JSON.stringify(err));
});

// Subscribe to network status change events. If the network is available, an on_netAvailable event is returned.
conn.on('netAvailable', ((data: connection.NetHandle) => {
  console.log("net is available, netId is " + data.netId);
}));

// Subscribe to network status change events. If the network is unavailable, an on_netUnavailable event is returned.
conn.on('netUnavailable', ((data: void) => {
  console.log("net is unavailable, data is " + JSON.stringify(data));
}));

// Unregister the observer for network status changes.
conn.unregister((err: BusinessError, data: void) => {
});
```

## Monitoring Changes of the Default Network and Re-establishing the Network Connection

Depending on the current network status and network quality, the default network may change, for example:
1. Switching the default network to the cellular network when the Wi-Fi signal is weak
2. Switching the default network to the Wi-Fi network when the cellular network signal is weak
3. Switching the default network to the cellular network when the Wi-Fi network is disabled
4. Switching the default network to the Wi-Fi network when the cellular network is disabled
5. Switching the default network to another Wi-Fi network when the Wi-Fi signal is weak (cross-network scenario)
6. Switching the default network to cellular Wi-Fi network when the cellular signal is weak (cross-network scenario)

The following describes how to monitor changes of the default network and migrate application packets to the new default network.

### Monitoring Changes of the Default Network 

```ts
import { connection } from '@kit.NetworkKit';

async function test() {
  const netConnection = connection.createNetConnection();

  /* Listen for changes of the default network */
  netConnection.on('netAvailable', (data: connection.NetHandle) => {
    console.log(JSON.stringify(data));
  });
}
```

### Re-establishing the Network Connection When the Default Network Is Changed

#### Original Network Connection Established via the HTTP Module

If the original network connection is established through the HTTP module, the socket is not closed immediately after the default network is changed and a new network connection is set up. The reason is that the HTTP module does not provide the **Close** API for closing a socket. Therefore, use Remote Communication Kit to re-establish a network connection.

#### Original Network Connection Established via Remote Communication Kit

```ts
import { rcp } from '@kit.RemoteCommunicationKit';
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let session = rcp.createSession();

async function useRcp() {
  /* Create an RCP request */
  try {
    const request = await session.get('https://www.example.com');
    console.info(request.statusCode.toString());
  } catch (e) {
    console.error(e.code.toString());
  }
}

async function rcpTest() {
  const netConnection = connection.createNetConnection();
  netConnection.on('netAvailable', async (netHandle: connection.NetHandle) => {
    /* Re-establish a session when the default network is changed */
    session.close();
    session = rcp.createSession();
    useRcp();
  });
  try {
    netConnection.register(() => {
    });
    useRcp();
  } catch (e) {
    console.error(e.code.toString());
  }
}
```

#### Original Network Connection Established via the Socket Module

```ts
import { connection, socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let sock: socket.TCPSocket = socket.constructTCPSocketInstance();

async function useSocket() {
  let tcpConnectOptions: socket.TCPConnectOptions = {
    address: {
      address: '192.168.xx.xxx',
      port: 8080
    },
    timeout: 6000
  }

  /* Set up a socket connection */
  sock.connect(tcpConnectOptions, (err: BusinessError) => {
    if (err) {
      console.error('connect fail');
      return;
    }
    console.log('connect success');

    /* Send data over the socket */
    let tcpSendOptions: socket.TCPSendOptions = {
      data: 'Hello, server!'
    }
    sock.send(tcpSendOptions).then(() => {
      console.log('send success');
    }).catch((err: BusinessError) => {
      console.error('send fail');
    });
  })
}

async function socketTest() {
  const netConnection = connection.createNetConnection();
  netConnection.on('netAvailable', async (netHandle: connection.NetHandle) => {
    console.log('default network changed');
    await sock.close();
    sock = socket.constructTCPSocketInstance();
    useSocket();
  });
  try {
    netConnection.register(() => {
    });
    useSocket();
  } catch (e) {
    console.error(e.code.toString());
  }
}
```

#### Original Network Connection Established via Socket Library

Close the original socket and re-establish a socket connection when the default network is changed.

## Obtaining the List of All Registered Networks

1. Declare the required permission: **ohos.permission.GET_NETWORK_INFO**.
This permission is of the **normal** level. Before applying for the permission, ensure that the [basic principles for permission management](../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Declare the permissions required by your application. For details, see [Declaring Permissions in the Configuration File](accesstoken-guidelines.md#declaring-permissions-in-the configuration-file).

2. Import the **connection** namespace from **@kit.NetworkKit**.

3. Call [getAllNets](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetallnets) to obtain the list of all connected networks.

```ts
// Import the required namespaces.
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Construct a singleton object.
export class GlobalContext {
  public netList: connection.NetHandle[] = [];
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

// Obtain the list of all connected networks.
connection.getAllNets().then((data: connection.NetHandle[]) => {
  console.info("Succeeded to get data: " + JSON.stringify(data));
  if (data) {
    GlobalContext.getContext().netList = data;
  }
});
```

## Querying Network Capability Information and Connection Information of Specified Data Network

1. Declare the required permission: **ohos.permission.GET_NETWORK_INFO**.
This permission is of the **normal** level. Before applying for the permission, ensure that the [basic principles for permission management](../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Declare the permissions required by your application. For details, see [Declaring Permissions in the Configuration File](accesstoken-guidelines.md#declaring-permissions-in-the configuration-file).

2. Import the **connection** namespace from **@kit.NetworkKit**.

3. Call [getDefaultNet](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetdefaultnet) to obtain the default data network specified by **NetHandle** or call [getAllNets](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetallnets) to obtain the list of all connected networks specified by **Array\<NetHandle>**.

4. Call [getNetCapabilities](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetnetcapabilities) to obtain the network capability information of the data network specified by **NetHandle**. The capability information includes information such as the network type (cellular, Wi-Fi, or Ethernet network) and the specific network capabilities.

5. Call [getConnectionProperties](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetconnectionproperties) to obtain the connection information of the data network specified by **NetHandle**.

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Construct a singleton object.
export class GlobalContext {
  public netList: connection.NetHandle[] = [];
  public netHandle: connection.NetHandle|null = null;
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

// Call getDefaultNet to obtain the default data network specified by NetHandle.
connection.getDefaultNet().then((data:connection.NetHandle) => {
  if (data.netId == 0) {
    // If the obtained netid of netHandler is 0 when no default network is specified, an exception has occurred and extra processing is needed.
    return;
  }
  if (data) {
    console.info("getDefaultNet get data: " + JSON.stringify(data));
    GlobalContext.getContext().netHandle = data;
    // Obtain the network capability information of the data network specified by NetHandle. The capability information includes information such as the network type and specific network capabilities.
    connection.getNetCapabilities(GlobalContext.getContext().netHandle).then(
      (data: connection.NetCapabilities) => {
      console.info("getNetCapabilities get data: " + JSON.stringify(data));
      // Obtain the network type via bearerTypes.
      let bearerTypes: Set<number> = new Set(data.bearerTypes);
      let bearerTypesNum = Array.from(bearerTypes.values());
      for (let item of bearerTypesNum) {
        if (item == 0) {
          // Cellular network
          console.log(JSON.stringify("BEARER_CELLULAR"));
        } else if (item == 1) {
          // Wi-Fi network
          console.log(JSON.stringify("BEARER_WIFI"));
        } else if (item == 3) {
          // Ethernet network
          console.log(JSON.stringify("BEARER_ETHERNET"));
        }
      }

      // Obtain the specific network capabilities via networkCap.
      let itemNumber : Set<number> = new Set(data.networkCap);
      let dataNumber = Array.from(itemNumber.values());
      for (let item of dataNumber) {
        if (item == 0) {
          // The network can connect to the carrier's Multimedia Messaging Service Center (MMSC) to send and receive multimedia messages.
          console.log(JSON.stringify("NET_CAPABILITY_MMS"));
        } else if (item == 11) {
          // The network traffic is not metered.
          console.log(JSON.stringify("NET_CAPABILITY_NOT_METERED"));
        } else if (item == 12) {
          // The network has the Internet access capability, which is set by the network provider.
          console.log(JSON.stringify("NET_CAPABILITY_INTERNET"));
        } else if (item == 15) {
          // The network does not use a Virtual Private Network (VPN).
          console.log(JSON.stringify("NET_CAPABILITY_NOT_VPN"));
        } else if (item == 16) {
          // The Internet access capability of the network is successfully verified by the connection management module.
          console.log(JSON.stringify("NET_CAPABILITY_VALIDATED"));
        }
      }
    })
  }
});

// Obtain the connection information of the data network specified by NetHandle. Connection information includes link and route information.
connection.getConnectionProperties(GlobalContext.getContext().netHandle).then((data: connection.ConnectionProperties) => {
  console.info("getConnectionProperties get data: " + JSON.stringify(data));
})

// Call getAllNets to obtain the list of all connected networks specified by Array<NetHandle>.
connection.getAllNets().then((data: connection.NetHandle[]) => {
  console.info("getAllNets get data: " + JSON.stringify(data));
  if (data) {
    GlobalContext.getContext().netList = data;

    let itemNumber : Set<connection.NetHandle> = new Set(GlobalContext.getContext().netList);
    let dataNumber = Array.from(itemNumber.values());
    for (let item of dataNumber) {
      // Obtain the network capability information of the network specified by each netHandle on the network list cyclically.
      connection.getNetCapabilities(item).then((data: connection.NetCapabilities) => {
        console.info("getNetCapabilities get data: " + JSON.stringify(data));
      })

      // Obtain the connection information of the network specified by each netHandle on the network list cyclically.
      connection.getConnectionProperties(item).then((data: connection.ConnectionProperties) => {
        console.info("getConnectionProperties get data: " + JSON.stringify(data));
      })
    }
  }
})
```

## Resolving the Domain Name of a Network to Obtain All IP Addresses

1. Declare the required permission: **ohos.permission.GET_NETWORK_INFO**.
This permission is of the **normal** level. Before applying for the permission, ensure that the [basic principles for permission management](../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Declare the permissions required by your application. For details, see [Declaring Permissions in the Configuration File](accesstoken-guidelines.md#declaring-permissions-in-the configuration-file).

2. Import the **connection** namespace from **@kit.NetworkKit**.

3. Call [getAddressesByName](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetaddressesbyname) to use the default network to resolve the host name to obtain the list of all IP addresses.

```ts
// Import the required namespaces.
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Use the default network to resolve the host name to obtain the list of all IP addresses.
connection.getAddressesByName("xxxx").then((data: connection.NetAddress[]) => {
  console.info("Succeeded to get data: " + JSON.stringify(data));
});
```
