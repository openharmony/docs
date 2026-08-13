# About This Kit

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=742fd8e7f742ee980eb300ddfd075065ca362dff translatedAt=2026-08-13T03:08:18.329Z pushedAt=2026-08-13T06:37:20.044Z -->

Network Kit provides the following functions:

- [HTTP data request](http-request.md): initiates a data request through HTTP.

- [WebSocket connection](websocket-connection.md): establishes a bidirectional connection between the server and client through WebSocket.

- [Socket connection](socket-connection.md): transmits data through Socket.

- [Network connection management](net-connection-manager.md): provides basic network management capabilities, including priority management of multiple network connections such as Wi-Fi, cellular, and Ethernet, network quality evaluation, subscription to default/specified network connection state changes, query of network connection information, and DNS resolution.

- [mDNS management](net-mdns.md): provides Multicast DNS (mDNS) management capabilities, such as adding, removing, discovering, and resolving local services on a LAN.<!--Del-->

- [Network sharing](net-sharing-sys.md): shares a device's Internet connection with other connected devices by means of Wi-Fi hotspot, Bluetooth, and USB sharing, and queries the network sharing state and shared mobile data volume.

- [Ethernet connection](net-ethernet-sys.md): provides wired network capabilities, including setting the IP address, subnet mask, gateway, and DNS information of a wired network.

<!--DelEnd-->

<!--RP1-->
<!--RP1End-->

## Constraints

To use the functions of the network management module, you must obtain the permissions listed in the following table.

Before requesting permissions, ensure that the [basic principles for using permissions](../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Declare the permissions required by your application. For details, see [Declaring Permissions in the Configuration File](../security/AccessToken/declare-permissions.md#declaring-permissions-in-the-configuration-file).

| Permission                          | Description                                  |
| -------------------------------- | -------------------------------------- |
| ohos.permission.GET_NETWORK_INFO | Allows an application to obtain the network connection information.                    |
| ohos.permission.INTERNET         | Allows an application to open network sockets to connect to the network.|