# Network Management Overview

Network management functions include:

- [HTTP Data Request](http-request.md): Initiates a data request through HTTP.
- [WebSocket Connection](websocket-connection.md): Establishes a bidirectional connection between the server and client through WebSocket.
- [Socket Connection](socket-connection.md): Transmits data through Socket.

## Constraints

To use the functions of the network management module, you must obtain the permissions listed in the following table.

| Permission                          | Description                                   |
| -------------------------------- | -------------------------------------- |
| ohos.permission.GET_NETWORK_INFO | Allows an application to obtain the network connection information.                    |
| ohos.permission.SET_NETWORK_INFO | Allows an application to modify the network connection state.                    |
| ohos.permission.INTERNET         | Allows an application to open network sockets to connect to the network.|
