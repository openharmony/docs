# Introduction to Network Kit

Network Kit provides the following functions:

- [HTTP data request](http-request.md): initiates a data request through HTTP.
- [WebSocket connection](websocket-connection.md): establishes a bidirectional connection between the server and client through WebSocket.
- [Socket connection](socket-connection.md): transmits data through Socket.
- [Network connection management](net-connection-manager.md): provides basic network management capabilities, including management of Wi-Fi/cellular/Ethernet connection priorities, network quality evaluation, subscription to network connection status changes, query of network connection information, and DNS resolution.
- [mDNS management](net-mdns.md): provides Multicast DNS (mDNS) management capabilities, such as adding, removing, discovering, and resolving local services on a LAN.<!--Del-->
- [Network sharing](net-sharing.md): shares a device's Internet connection with other connected devices by means of Wi-Fi hotspot, Bluetooth, and USB sharing, and queries the network sharing state and shared mobile data volume.
- [Ethernet connection](net-ethernet.md): provides wired network capabilities, which allow you to set the IP address, subnet mask, gateway, and Domain Name System (DNS) server of a wired network.
<!--DelEnd-->


## Constraints

To use the functions of the network management module, you must obtain the permissions listed in the following table.
Before requesting permissions, ensure that the [basic principles for using permissions](../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Declare the permissions required by your application. For details, see [Declaring Permissions in the Configuration File](accesstoken-guidelines.md#declaring-permissions-in-the configuration-file).

| Permission                          | Description                                  |
| -------------------------------- | -------------------------------------- |
| ohos.permission.GET_NETWORK_INFO | Allows an application to obtain the network connection information.                    |
| ohos.permission.INTERNET         | Allows an application to open network sockets to connect to the network.|
