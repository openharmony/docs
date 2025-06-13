# SPP-based Data Transmission

## Introduction

Serial Port Profile (SPP) is a Bluetooth protocol used to establish serial communication connections between Bluetooth devices. With SPP, Bluetooth devices can transmit data, such as files and text, just like using a serial port.

## When to Use

You can use the APIs provided by the **spp** module to:
- Write data to the client.
- Connect to the peer device over a socket.

## Available APIs

For details about the APIs and sample code, see [@ohos.bluetooth.socket](../../reference/apis-connectivity-kit/js-apis-bluetooth-socket.md).

The following table describes the related APIs.

| API                            | Description                                                                      |
| ---------------------------------- | ------------------------------------------------------------------------------ |
| sppListen()                        | Creates a listening socket for the server.                                                      |
| sppAccept()                        | Accepts a connection request from the client over a socket of the server.                                                 |
| sppConnect()                       | Initiates an SPP connection to a remote device from the client.                                                    |
| sppCloseServerSocket()             | Closes the listening socket of the server.                                                          |
| sppCloseClientSocket()             | Closes the client socket.                                                              |
| sppWrite()                         | Sends data to the remote end over the socket.                                                      |
| on(type: 'sppRead')                | Subscribes to the SPP read request events.                                                             |
| off(type: 'sppRead')               | Unsubscribes from the SPP read request events.                                                          |

## How to Develop

### Writing Data to the Client
1. Import the **socket** module.
2. Check that the SystemCapability.Communication.Bluetooth.Core capability is available.
3. Apply for the **ohos.permission.ACCESS_BLUETOOTH** permission.
4. Enable Bluetooth on the device.
5. Creates a server socket. If the operation is successful, **serverId** is returned.
6. Create a communication channel between the server socket and the client socket. If the operation is successful, **clientId** is returned.
7. Write data to the client.
8. (Optional) Subscribe to the data written by the client.
9. Close the server socket.
10. Close the client socket.
11. Example:

    ```ts
    import { socket } from '@kit.ConnectivityKit';
    import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';

    // Create a server listening socket. serverId is returned if the socket is created.
    let serverNumber = -1;
    let sppOption: socket.SppOptions = {
      uuid: '00001101-0000-1000-8000-00805f9b34fb',
      secure: true,
      type: 0
    };
    socket.sppListen('server1', sppOption, (code, serverSocketID) => {
      if (code != null) {
        console.error('sppListen error, code is ' + (code as BusinessError).code);
        return;
      } else {
        serverNumber = serverSocketID;
        console.info('sppListen success, serverNumber = ' + serverNumber);
      }
    });

    // Establish a connection between the server socket and client socket. If the connection is successful, clientId is returned.
    let clientNumber = -1;
    socket.sppAccept(serverNumber, (code, clientSocketID) => {
      if (code != null) {
        console.error('sppAccept error, code is ' + (code as BusinessError).code);
        return;
      } else {
        clientNumber = clientSocketID;
        console.info('accept the client success');
      }
    })
    console.info('waiting for client connection');

    // Write data to the client.
    let array = new Uint8Array(990);
    array[0] = 'A'.charCodeAt(0);
    array[1] = 'B'.charCodeAt(0);
    array[2] = 'C'.charCodeAt(0);
    array[3] = 'D'.charCodeAt(0);
    socket.sppWrite(clientNumber, array.buffer);
    console.info('sppWrite success');

    // Subscribe to the read request event.
    socket.on('sppRead', clientNumber, (dataBuffer: ArrayBuffer) => {
      const data = new Uint8Array(dataBuffer);
      if (data != null) {
        console.info('sppRead success, data = ' + JSON.stringify(data));
      } else {
        console.error('sppRead error, data is null');
      }
    });

    // Unsubscribe from the read request event.
    socket.off('sppRead', clientNumber, (dataBuffer: ArrayBuffer) => {
      const data = new Uint8Array(dataBuffer);
      if (data != null) {
        console.info('offSppRead success, data = ' + JSON.stringify(data));
      } else {
        console.error('offSppRead error, data is null');
      }
    });

    // Close the server socket.
    socket.sppCloseServerSocket(serverNumber);
    console.info('sppCloseServerSocket success');

    // Close the client socket.
    socket.sppCloseClientSocket(clientNumber);
    console.info('sppCloseClientSocket success');
    ```

11. For details about the error codes, see [Bluetooth Error Codes](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md).

### Connecting to the Peer Device over a Socket
1. Import the **socket** module.
2. Check that the SystemCapability.Communication.Bluetooth.Core capability is available.
3. Enable Bluetooth on the device.
4. Start Bluetooth scanning to obtain the MAC address of the peer device.
5. Connect to the peer device.
6. Example:

    ```ts
    import { socket } from '@kit.ConnectivityKit';
    import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';

    // Start Bluetooth scanning to obtain the MAC address of the peer device.
    let deviceId = 'xx:xx:xx:xx:xx:xx';

    // Connect to the peer device.
    socket.sppConnect(deviceId, {
      uuid: '00001101-0000-1000-8000-00805f9b34fb',
      secure: true,
      type: 0
    }, (code, socketID) => {
      if (code != null) {
        console.error('sppConnect error, code = ' + (code as BusinessError).code);
        return;
      }
      console.info('sppConnect success, socketId = ' + socketID);
    })
    ```

7. For details about the error codes, see [Bluetooth Error Codes](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md).
