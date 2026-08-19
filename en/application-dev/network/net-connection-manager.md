# Network Connection Management
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

## Introduction

The Network Connection Management module provides basic network management capabilities, including management of connection priorities among multiple networks such as Wi-Fi, cellular, and Ethernet, network quality evaluation, subscription to status changes of the default or specified network, query of network connection information, and DNS resolution.

> **NOTE**
>
> To ensure efficient application running, most API calls are asynchronous. For asynchronous APIs, both callback and Promise modes are available. The following examples use Promise mode. For details, see [@ohos.net.connection (Network Connection Management)](../reference/apis-network-kit/js-apis-net-connection.md).

## Basic Concepts

- Producer: a provider of data networks, such as Wi-Fi, cellular, and Ethernet.
- Consumer: a user of data networks, for example, an application or a system service.
- Network probe: a mechanism used to detect the network availability to prevent the switch from an available network to an unavailable network. The probe type can be binding network detection, DNS detection, HTTP detection, or HTTPS detection.
- Network selection: a mechanism used to select the optimal network when multiple networks coexist. It is triggered when the network status, network information, or network quality evaluation score changes.
- Default network: the network used by the system by default. It is determined by the system and is independent of whether an application specifies a network. It is usually one of Wi-Fi, cellular, Ethernet, or Bluetooth.
- Network handle: the unique identifier of a network.

## When to Use

Typical application scenarios of network connection management are as follows:

- Subscribing to status changes of the specified network
- Obtaining the list of all registered networks
- Querying the connection information of the default network or the specified network
- Resolving the domain name of the default network to obtain all IP addresses

The following describes the development procedure specific to each application scenario.

## Subscribing to Status Changes of the Specified Network

1. Declare the required permission: **ohos.permission.GET_NETWORK_INFO**.

   This permission is of the **normal** level. Before applying for the permission, ensure that the [basic principles for permission management](../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Declare the permissions required by your application. For details, see [Declaring Permissions in the Configuration File](../security/AccessToken/declare-permissions.md#declaring-permissions-in-the-configuration-file).

2. Import the **connection** namespace from **@kit.NetworkKit**.

   <!-- @[NetConnection_manage_case_module_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetConnection_Manage_case/entry/src/main/ets/pages/ConnectNetworkBtn.ets) -->
   
   ``` TypeScript
   // Import the required namespaces.
   import { connection } from '@kit.NetworkKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```
3. Call [createNetConnection](../reference/apis-network-kit/js-apis-net-connection.md#connectioncreatenetconnection) to create a **NetConnection** object. You can specify the network type, capability, and timeout interval. If you do not specify parameters, the default values will be used. 

   <!-- @[notification_network_create_NetConnection](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetConnection_Manage_case/entry/src/main/ets/pages/ConnectNetworkBtn.ets) -->
   
   ``` TypeScript
   let netSpecifier: connection.NetSpecifier = {
     netCapabilities: {
       // Assume that the default network is a cellular network connection. If you need to create a Wi-Fi network connection, set the network type to Wi-Fi.
       bearerTypes: [connection.NetBearType.BEARER_WIFI],
       // Set the network capability to INTERNET.
       networkCap: [connection.NetCap.NET_CAPABILITY_INTERNET],
     }
   };
   
   // Set the timeout value to 10s. The default value is 0.
   let TIMEOUT = 10 * NETWORK_CONNECTION_TIMEOUT;
   
   // Create a NetConnection object.
   let conn = connection.createNetConnection(netSpecifier, TIMEOUT);
   ```

4. Call [on()](../reference/apis-network-kit/js-apis-net-connection.md#onnetavailable) to subscribe to desired events. You must pass in **type** and **callback**.

   <!-- @[notification_network_netAvailable_netUnavailable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetConnection_Manage_case/entry/src/main/ets/pages/ConnectNetworkBtn.ets) -->
   
   ``` TypeScript
   // Subscribe to network status change events. If the network is available, an on_netAvailable event is returned.
   conn.on('netAvailable', (data: connection.NetHandle) => {
     hilog.info(0x0000, 'testTag', 'Network available, NetId is ' + data.netId);
     // ...
   });
     
   // Subscribe to network status change events. If the network is unavailable, an on_netUnavailable event is returned.
   conn.on('netUnavailable', (data: void) => {
     hilog.info(0x0000, 'testTag', 'Network unavailable, data is ' + JSON.stringify(data));
     // ...
   });
   // Subscribe to network capability change events. If the capability of the specified network changes, an on_netCapabilitiesChange event is returned.
   conn.on('netCapabilitiesChange', (data: connection.NetCapabilityInfo) => {
     hilog.info(0x0000, 'testTag', 'Network netCapabilitiesChange, data is ' + JSON.stringify(data));
     // ...
   });
     
   // Subscribe to network connection information change events. If the connection information of the specified network changes, an on_netConnectionPropertiesChange event is returned.
   conn.on('netConnectionPropertiesChange', (data: connection.NetConnectionPropertyInfo) => {
     hilog.info(0x0000, 'testTag', 'Network netConnectionPropertiesChange, data is ' + JSON.stringify(data));
     // ...
   });
     
   // Subscribe to network disconnection events. If the specified network is disconnected, an on_netLost event is returned.
   conn.on('netLost', (data: connection.NetHandle) => {
     hilog.info(0x0000, 'testTag', 'Network netLost, data is ' + JSON.stringify(data));
     // ...
   });
   ```

5. Call [register()](../reference/apis-network-kit/js-apis-net-connection.md#register) to subscribe to network status changes of the specified network. When the network is available, the **netAvailable** event is triggered. When the network is disconnected, the **netLost** event is triggered. When the network connection information changes (for example, IPv6 addresses are added to linkAddresses), the **netConnectionPropertiesChange** event is triggered. When the network capability changes (for example, the network connectivity changes), the **netCapabilitiesChange** event is triggered.

   <!-- @[notification_network_register](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetConnection_Manage_case/entry/src/main/ets/pages/ConnectNetworkBtn.ets) -->
   
   ``` TypeScript
   // Subscribe to connection state changes.
   conn.register((err: BusinessError, data: void) => {
     // ...
       hilog.error(0x0000, 'testTag', 'Error occurred during connection:', JSON.stringify(err));
       // ...
   });
   ```

6. Call [unregister()](../reference/apis-network-kit/js-apis-net-connection.md#unregister) to unsubscribe from the network status changes.

   <!-- @[notification_network_unregister](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetConnection_Manage_case/entry/src/main/ets/pages/ConnectNetworkBtn.ets) -->
   
   ``` TypeScript
   // Unregister the observer for network status changes.
   conn.unregister((err: BusinessError, data: void) => {
     if (err) {
       hilog.error(0x0000, 'testTag', 'Error occurred during unsubscription:', JSON.stringify(err));
     } else {
       // ...
       hilog.info(0x0000, 'testTag', 'Network connection disconnected.');
     }
   });
   ```

## Monitoring Changes of the Default Network and Re-establishing the Network Connection

Depending on the current network status and network quality, the default network may change, for example:
1. Switching the default network to the cellular network when the Wi-Fi signal is weak
2. Switching the default network to the Wi-Fi network when the cellular network signal is weak
3. Switching the default network to the cellular network when Wi-Fi is turned off
4. Switching the default network to the Wi-Fi network when the cellular network is turned off
5. Switching the default network to another Wi-Fi network when the Wi-Fi signal is weak (cross-network scenario)
6. Switching the default network to another cellular network when the cellular signal is weak (cross-network scenario)

The following describes how to monitor changes of the default network and migrate application packets to the new default network.
### Importing the Connection Namespace

<!-- @[net_Connection_create_connection_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetConnection_Manage_case/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { connection, socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
```
### Monitoring Changes of the Default Network 

<!-- @[monitor_default_network_change](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetConnection_Manage_case/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
const netConnection = connection.createNetConnection();
/* Listen for changes of the default network */
netConnection.on('netAvailable', (data: connection.NetHandle) => {
  hilog.info(0x0000, 'testTag', JSON.stringify(data));
});
```
### Re-establishing the Network Connection When the Default Network Is Changed

<!--RP1-->

<!--RP1End-->

**Original Network Connection Established via the Socket Module**

<!-- @[original_network_connection_uses_socket](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetConnection_Manage_case/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// Create a socket object.
let sock: socket.TCPSocket = socket.constructTCPSocketInstance();

// Original network connection established via the Socket module.
function useSocket() {
  let netAddress: socket.NetAddress = {
    address: '192.168.xx.xxx',
    port: 8080 // Port number. The default value is 8080.
  };

  let tcpConnectOptions: socket.TCPConnectOptions = {
    address: netAddress,
    timeout: 6000 // Connection timeout duration.
  };

  // Set up a socket connection.
  sock.connect(tcpConnectOptions, (err: BusinessError) => {
    if (err) {
      hilog.error(0x0000, 'testTag', 'connect fail: '+JSON.stringify(err));
    // ···
      return;
    }
    hilog.info(0x0000, 'testTag', 'connect success');

    // Send data over the socket.
    let tcpSendOptions: socket.TCPSendOptions = {
      data: 'Hello, server!'
    };
    socketSend(tcpSendOptions);
  });
}

// Send data over the socket.
function socketSend(tcpSendOptions: socket.TCPSendOptions) {
  sock.send(tcpSendOptions).then(() => {
    hilog.info(0x0000, 'testTag', 'send success');
    // ···
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'send fail');
    // ···
  });
}

function socketTest() {
  const netConnection = connection.createNetConnection();
  // The original socket becomes invalid if the network is disconnected due to network switching. In this case, you need to create a new socket.
  netConnection.on('netAvailable', (netHandle: connection.NetHandle) => {
    hilog.info(0x0000, 'testTag', 'default network changed: ' + JSON.stringify(netHandle));
    sock.close();
    sock = socket.constructTCPSocketInstance();
    // Send data over the socket.
    useSocket();
  });
// ···
    // Register an observer for network status changes.
    netConnection.register((error: BusinessError) => {
      if (error) {
        hilog.error(0x0000, 'testTag', 'register fail: ' + JSON.stringify(error));
      } else {
        hilog.info(0x0000, 'testTag', 'register success');
      }
    });
    // ···
}
```

**Original Network Connection Established via Socket Library**

Close the original socket and re-establish a socket connection when the default network is changed.

## Obtaining the List of All Registered Networks

1. Declare the required permission: **ohos.permission.GET_NETWORK_INFO**.

   This permission is of the **normal** level. Before applying for the permission, ensure that the [basic principles for permission management](../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Declare the permissions required by your application. For details, see [Declaring Permissions in the Configuration File](../security/AccessToken/declare-permissions.md#declaring-permissions-in-the-configuration-file).

2. Obtain the list of all connected networks.

   <!-- @[get_all_registered_networks](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetConnection_Manage_case/entry/src/main/ets/pages/GetAllNets.ets) -->
   
   ``` TypeScript
   // Import the connection namespace from @kit.NetworkKit.
   import { connection } from '@kit.NetworkKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   // ...
       // Call getAllNets to obtain the list of all connected networks via Array<NetHandle>.
       connection.getAllNets().then((data: connection.NetHandle[]) => {
         hilog.info(0x0000, 'testTag', 'getAllNets get data: ' + JSON.stringify(data));
         if (data) {
           // ...
           GlobalContext.getContext().netList = data;
           // ...
         }
       });
   ```
## Querying the Connection Information of the Default Network or the Specified Network

1. Declare the required permission: **ohos.permission.GET_NETWORK_INFO**.

   This permission is of the **normal** level. Before applying for the permission, ensure that the [basic principles for permission management](../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Declare the permissions required by your application. For details, see [Declaring Permissions in the Configuration File](../security/AccessToken/declare-permissions.md#declaring-permissions-in-the-configuration-file).
2. Query the connection information of the default network or the specified network.
   
   Call [getDefaultNet](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetdefaultnet) to obtain the default data network identified by **NetHandle** and call [getNetCapabilities](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetnetcapabilities) to obtain its network capability information. The capability information includes information such as the network type (cellular, Wi-Fi, or Ethernet network) and the specific network capabilities. Alternatively, you can call [getConnectionProperties](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetconnectionproperties) to obtain the connection information of the data network specified by **NetHandle**.

    <!-- @[get_default_network_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetConnection_Manage_case/entry/src/main/ets/pages/DefaultNetworkBtn.ets) -->
    
    ``` TypeScript
    // Import the connection namespace from @kit.NetworkKit.
    import { connection } from '@kit.NetworkKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    // ···
        let netHandleInfo:connection.NetHandle|null = null;
        // Call **getDefaultNet** to obtain the default data network specified by **NetHandle**.
        connection.getDefaultNet().then((data: connection.NetHandle) => {
          if (data.netId == 0) {
            hilog.info(0x0000, 'testTag', `don't have defaultNet`);
            // If the obtained netid of netHandler is 0 when no default network is specified, an exception has occurred and extra processing is needed.
            return;
          }
          if (data) {
            // ···
            hilog.info(0x0000, 'testTag', 'getDefaultNet get data: ' + JSON.stringify(data));
            // Obtain the network capability information of the data network specified by **NetHandle**. The capability information includes information such as the network type and specific network capabilities.
            netHandleInfo = data;
            connection.getNetCapabilities(netHandleInfo).then(
              (data: connection.NetCapabilities) => {
                hilog.info(0x0000, 'testTag', 'getNetCapabilities get data: ' + JSON.stringify(data));
                // Obtain the network type via bearerTypes.
                let bearerTypes: Set<number> = new Set(data.bearerTypes);
                let bearerTypesNum = Array.from(bearerTypes.values());
                for (let item of bearerTypesNum) {
                  if (item == 0) {
                    // Cellular network
                    hilog.info(0x0000, 'testTag', JSON.stringify('BEARER_CELLULAR'));
                  } else if (item == 1) {
                    // Wi-Fi network
                    hilog.info(0x0000, 'testTag', JSON.stringify('BEARER_WIFI'));
                  } else if (item == 3) {
                    // Ethernet network
                    hilog.info(0x0000, 'testTag', JSON.stringify('BEARER_ETHERNET'));
                  }
                }
    
                // Obtain the specific network capabilities via networkCap.
                let itemNumber: Set<number> = new Set(data.networkCap);
                let dataNumber = Array.from(itemNumber.values());
                for (let item of dataNumber) {
                  if (item == 0) {
                    // The network can connect to the carrier's Multimedia Messaging Service Center (MMSC) to send and receive multimedia messages.
                    hilog.info(0x0000, 'testTag', JSON.stringify('NET_CAPABILITY_MMS'));
                  } else if (item == 11) {
                    // The network traffic is not metered.
                    hilog.info(0x0000, 'testTag', JSON.stringify('NET_CAPABILITY_NOT_METERED'));
                  } else if (item == 12) {
                    // The network has the Internet access capability, which is set by the network provider.
                    hilog.info(0x0000, 'testTag', JSON.stringify('NET_CAPABILITY_INTERNET'));
                  } else if (item == 15) {
                    // The network does not use a Virtual Private Network (VPN).
                    hilog.info(0x0000, 'testTag', JSON.stringify('NET_CAPABILITY_NOT_VPN'));
                  } else if (item == 16) {
                    // The Internet access capability of the network is successfully verified by the connection management module.
                    hilog.info(0x0000, 'testTag', JSON.stringify('NET_CAPABILITY_VALIDATED'));
                  }
                }
              });
          }
        });
    
        // Obtain network connection information based on the specified netHandle.
        connection.getConnectionProperties(netHandleInfo).then((data: connection.ConnectionProperties) => {
          hilog.info(0x0000, 'testTag', 'getConnectionProperties get data: ' + JSON.stringify(data));
        })
    // ···
    ```
    
3. Query the connection information of all connected networks.
   
   Call [getAllNets](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetallnets) to obtain the list of all connected networks specified by **Array\<NetHandle>**. Then, traverse the obtained **NetHandle** array and call [getNetCapabilities](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetnetcapabilities) to obtain the capability information of the network identified by each **NetHandle**. The capability information includes the network type (cellular network, Wi-Fi network, or Ethernet network) and network capability. Alternatively, you can call [getConnectionProperties](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetconnectionproperties) to obtain the connection information of the data network specified by **NetHandle**.

    <!-- @[get_net_capabilities_and_get_connection_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetConnection_Manage_case/entry/src/main/ets/pages/AllNetworksBtn.ets) -->
    
    ``` TypeScript
    // Import the connection namespace from @kit.NetworkKit.
    import { connection } from '@kit.NetworkKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    // ...
      getAllNetworks() {
        // Call getAllNets to obtain the list of all connected networks specified by Array<NetHandle>.
        connection.getAllNets().then((data: connection.NetHandle[]) => {
          hilog.info(0x0000, 'testTag', 'getAllNets get data: ' + JSON.stringify(data));
          if (data) {
            // ...
            let itemNumber: Set<connection.NetHandle> = new Set(data);
            let dataNumber = Array.from(itemNumber.values());
            for (let item of dataNumber) {
              // Obtain the network capability information of the network specified by each netHandle on the network list cyclically.
              connection.getNetCapabilities(item).then((data: connection.NetCapabilities) => {
                hilog.info(0x0000, 'testTag', 'getNetCapabilities get data: ' + JSON.stringify(data));
              });
    
              // Obtain the connection information of the network specified by each netHandle on the network list cyclically.
              connection.getConnectionProperties(item).then((data: connection.ConnectionProperties) => {
                hilog.info(0x0000, 'testTag', 'getConnectionProperties get data: ' + JSON.stringify(data));
              });
            }
          }
        });
      }
    ```

## Checking Whether the Default Network Supports Internet Access

If an application needs to check whether the current network supports Internet access, perform the following steps:

1. Declare the required permission: **ohos.permission.GET_NETWORK_INFO**.

   This permission is of the **normal** level. Before applying for the permission, ensure that the [basic principles for permission management](../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Declare the permissions required by your application. For details, see [Declaring Permissions in the Configuration File](../security/AccessToken/declare-permissions.md#declaring-permissions-in-the-configuration-file).

2. Check whether the default network supports Internet access.
   
   Call [getDefaultNetSync](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetdefaultnetsync9) to obtain **netHandle** of the default network. If **netHandle** is valid, call [getNetCapabilitiesSync](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetnetcapabilitiessync10) to obtain the capability information of the corresponding network via **networkCap** and determine whether Internet access is supported.
   
   **NET_CAPABILITY_CHECKING_CONNECTIVITY** indicates that a network connectivity check is in progress. The network connectivity verification is successful if the network connectivity check is complete and **NET_CAPABILITY_VALIDATED** is contained in **networkCap**.

    <!-- @[NetConnection_manage_case_default_net_sync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetConnection_Manage_case/entry/src/main/ets/pages/DefaultNetSyncBtn.ets) -->
    
    ``` TypeScript
    // Import the connection namespace from @kit.NetworkKit.
    import { connection } from '@kit.NetworkKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    // ...
        // Obtain the default active data network.
        let netHandle = connection.getDefaultNetSync();
        if (!netHandle || netHandle.netId === 0) {
          hilog.error(0x0000, 'testTag', 'getDefaultNetSync fail');
          // ...
        } else {
          hilog.info(0x0000, 'testTag', 'default network: ' + JSON.stringify(netHandle));
          // Obtain network capability information based on the specified netHandle.
          let netCapabilities = connection.getNetCapabilitiesSync(netHandle);
          let cap = netCapabilities.networkCap;
          hilog.info(0x0000, 'testTag', 'network capabilities: ' + JSON.stringify(netCapabilities));
          // Check whether the network supports Internet access.
          if (cap?.includes(connection.NetCap.NET_CAPABILITY_CHECKING_CONNECTIVITY)) {
            // Network connectivity check is in progress. Please try again later.
            hilog.info(0x0000, 'testTag', 'default network is checking, please try again later');
          } else {
            if (cap?.includes(connection.NetCap.NET_CAPABILITY_VALIDATED)) {
              // Network connectivity check is successful. The default network supports Internet access.
              hilog.info(0x0000, 'testTag', 'default network is validated');
              // ...
            } else {
              // Network connectivity check fails. The default network does not support Internet access.
              hilog.info(0x0000, 'testTag', 'default network is not validated');
              // ...
            }
          }
        }
    ```

## Resolving the Domain Name of the Default Network to Obtain All IP Addresses

1. Declare the required permission: **ohos.permission.GET_NETWORK_INFO**.

   This permission is of the **normal** level. Before applying for the permission, ensure that the [basic principles for permission management](../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Declare the permissions required by your application. For details, see [Declaring Permissions in the Configuration File](../security/AccessToken/declare-permissions.md#declaring-permissions-in-the-configuration-file).

2. Use the default network to resolve the host name to obtain the list of all IP addresses.
   
   Call [getAddressesByName](../reference/apis-network-kit/js-apis-net-connection.md#connectiongetaddressesbyname) to use the default network to resolve the host name to obtain the list of all IP addresses.

    <!-- @[resolve_the_domain_name_and_get_all_ips](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetConnection_Manage_case/entry/src/main/ets/pages/DefaultNetworkIPBtn.ets) -->
    
    ``` TypeScript
    // Import the connection namespace from @kit.NetworkKit.
    import { connection } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    // ...
          // Use the default network to resolve the host name to obtain the list of all IP addresses.
          connection.getAddressesByName('xxxx').then((data: connection.NetAddress[]) => {
            hilog.info(0x0000, 'testTag', 'Successfully retrieved default network IP address: ' + JSON.stringify(data));
            // ...
          })
    ```
     
## Samples

The following samples are provided to help you better understand how to develop network connection features:

- [NetConnection_Manage_case](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetConnection_Manage_case)
