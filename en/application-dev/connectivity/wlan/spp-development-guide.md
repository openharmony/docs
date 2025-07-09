# SPP-based Connection and Data Transmission

## Introduction
This document provides guidance on how to connect devices and transfer data via Serial Port Profile (SPP). When two devices communicate via SPP, they can be distinguished as client and server based on their respective functions. This guide describes the implementation methods for both the client and server.

## How to Implement
After obtaining the server's device address, the client can initiate a connection to the specific UUID of the server. The server's device address can be obtained through the device discovery process. For details, see [Bluetooth Discovery Development](br-discovery-development-guide.md). Once the connection between the two ends is successfully established, the client can send data to the server or receive data from the server.

The server needs to support the UUID service for client connections and maintain listening for connection status changes. After the connection between the two ends is successfully established, the server can receive data from the client or send data to the client.

Both the client and the server can actively disconnect. The application needs to determine which end performs the disconnection.

## How to Develop

### Applying for Required Permissions
Apply for the **ohos.permission.ACCESS_BLUETOOTH** permission. For details about how to configure and apply for permissions, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md) and [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

### Importing Required Modules
Import the related modules.
```ts
import { socket } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
```

### Client

#### 1. Initiating a Connection
The client can initiate a connection after searching for the target device through the device discovery process. The UUID service to be connected to must be consistent with the UUID service constructed when the server creates the socket. During the connection process, the Bluetooth subsystem will check whether the server supports this UUID service; if not, the connection will fail. Therefore, the application must ensure that the target device supports the required UUID service; otherwise, the connection initiated will be invalid.
```ts
// Obtain the device address through the device discovery process.
let peerDevice = 'XX:XX:XX:XX:XX:XX';

// Define the client socket ID.
let clientNumber = -1;

// Configure connection parameters.
let option: socket.SppOptions = {
  uuid: '00009999-0000-1000-8000-00805F9B34FB', // The UUID service to be connected must be supported by the server.
  secure: false,
  type: socket.SppType.SPP_RFCOMM
};
console.info('startConnect ' + peerDevice);
socket.sppConnect(peerDevice, option, (err, num: number) => {
  if (err) {
    console.error('startConnect errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
  } else {
    console.info('startConnect clientNumber: ' + num);
    clientNumber = num;
  }
});
console.info('startConnect after ' + peerDevice);
```

#### 2. Transmitting Data

**2.1 Sending Data**<br>
After the connection between the client and server is established, the client can send data to the server.
```ts
let clientNumber = 1; // Note: The value is the client socket ID in the asynchronous callback returned when the client initiates a connection. The ID here is a pseudo-code ID.
let arrayBuffer = new ArrayBuffer(2);
let data = new Uint8Array(arrayBuffer);
data[0] = 3;
data[1] = 4;
try {
  socket.sppWrite(clientNumber, arrayBuffer);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**2.2 Receiving Data**<br>
After the connection between the client and server is established, the client can receive data from the server. This is implemented through [socket.on('sppRead ')](../../reference/apis-connectivity-kit/js-apis-bluetooth-socket.md#socketonsppread).
```ts
let clientNumber = 1; // Note: The value is the client socket ID in the asynchronous callback returned when the client initiates a connection. The ID here is a pseudo-code ID.

// Define the callback for data read events.
function read(dataBuffer: ArrayBuffer) {
  let data = new Uint8Array(dataBuffer);
  console.info('client data: ' + JSON.stringify(data));
}

try {
  // Enable listening for data read events.
  socket.on('sppRead', clientNumber, read);
} catch (err) {
  console.error('readData errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 3. Terminating the Connection
When an application no longer needs an established connection, it can proactively disconnect from the client. Before that, you need to disable listening for data read events.
```ts
let clientNumber = 1; // Note: The value is the client socket ID in the asynchronous callback returned when the client initiates a connection. The ID here is a pseudo-code ID.

// Define the callback for data read events.
function read(dataBuffer: ArrayBuffer) {
  let data = new Uint8Array(dataBuffer);
  console.info('client data: ' + JSON.stringify(data));
}

try {
  // Disable listening for data read events.
  socket.off('sppRead', clientNumber, read);
} catch (err) {
  console.error('off sppRead errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
try {
  // Disconnect from the client.
  socket.sppCloseClientSocket(clientNumber);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### Server

#### 1. Create a server socket.
The server needs to register the specified UUID service in the Bluetooth subsystem by creating a socket. The UUID service can be named freely, such as using the application name. When a client sends a connection request, it includes a UUID to specify the target service. Connection establishment is permitted only when the server's and client's UUIDs are identical.
```ts
// Define the server socket ID.
let serverNumber = -1;

// Set listening parameters.
let option: socket.SppOptions = {
  uuid: '00009999-0000-1000-8000-00805F9B34FB',
  secure: false,
  type: socket.SppType.SPP_RFCOMM
};

// Create a listening socket on the server. The UUID service is registered in the Bluetooth subsystem.
socket.sppListen("demonstration", option, (err, num: number) => {
  if (err) {
    console.error('sppListen errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
  } else {
    console.info('sppListen serverNumber: ' + num);
    serverNumber = num;
  }
});
```

#### 2. Enable listening for client connections.
After the server socket is created, the server can listen for client connections. When a connection request is received, the server obtains the socket ID of the client. At this time, the connection between the server and client is successfully established.
```ts
let serverNumber = 1; // Note: The value is the server socket ID in the asynchronous callback returned when the server socket is created. The ID here is a pseudo-code ID.

// Define the client socket ID.
let clientNumber = -1;

socket.sppAccept(serverNumber, (err, num: number) => {
  if (err) {
    console.error('accept errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
  } else {
    console.info('accept clientNumber: ' + num);
    clientNumber = num;
  }
});
```

#### 3. Transmitting Data

**3.1 Sending Data**<br>
After the connection between the server and client is established, the server can send data to the client.
```ts
let clientNumber = 1; // Note: The value is the client socket ID in the asynchronous callback returned when the server listens for a client connection. The ID here is a pseudo-code ID.

let arrayBuffer = new ArrayBuffer(2);
let data = new Uint8Array(arrayBuffer);
data[0] = 9;
data[1] = 8;
try {
  socket.sppWrite(clientNumber, arrayBuffer);
} catch (err) {
  console.error('sppWrite errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**3.2 Receiving Data**<br>
After the connection between the server and client is established, the server can receive data from the client. This is implemented through [socket.on('sppRead ')](../../reference/apis-connectivity-kit/js-apis-bluetooth-socket.md#socketonsppread).
```ts
let clientNumber = 1; // Note: This value is the client socket ID obtained by the asynchronous callback when the server listens to the connection. This is a pseudo code ID.

// Define the callback for data read events.
read(dataBuffer: ArrayBuffer) {
  let data = new Uint8Array(dataBuffer);
  console.info('client data: ' + JSON.stringify(data));
}

try {
  // Enable listening for data read events.
  socket.on('sppRead', clientNumber, this.read);
} catch (err) {
  console.error('readData errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```
#### 4. Terminating the Connection
When an application no longer needs an established connection, it can proactively disconnect from the server.

- Before that, you need to disable listening for data read events.
```ts
let clientNumber = 1; // Note: This value is the client socket ID obtained by the asynchronous callback when the server listens to the connection. This is a pseudo code ID.

// Define the callback for data read events.
function read(dataBuffer: ArrayBuffer) {
  let data = new Uint8Array(dataBuffer);
  console.info('client data: ' + JSON.stringify(data));
}

try {
  // Disable listening for data read events.
  socket.off('sppRead', clientNumber, read);
} catch (err) {
  console.error('off sppRead errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
try {
  // Disconnect from the server.
  socket.sppCloseClientSocket(this.clientNumber);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 5. Deleting the Server Socket
When the application no longer needs the server socket, it needs to proactively close the socket. The Bluetooth subsystem then deletes the corresponding UUID service registered earlier. If the client initiates a connection at this time, the connection fails.

- The application can also disconnect from the server when deleting the socket. Before that, the application needs to disable listening for data read events.
```ts
let serverNumber = 1; // Note: The value is the server socket ID in the asynchronous callback returned when the server socket is created. The ID here is a pseudo-code ID.

// Define the callback for data read events.
function read(dataBuffer: ArrayBuffer) {
  let data = new Uint8Array(dataBuffer);
  console.info('client data: ' + JSON.stringify(data));
}

try {
  // Disable listening for data read events.
  socket.off('sppRead', clientNumber, read);
} catch (err) {
  console.error('off sppRead errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

try {
  // If the application no longer needs the server socket, proactively delete it.
  socket.sppCloseServerSocket(serverNumber);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## Complete Sample Code

### Client
```ts
import { socket } from '@kit.ConnectivityKit'
import { BusinessError } from '@kit.BasicServicesKit';

class SppClientManager {
  // Define the client socket ID.
  clientNumber: number = -1;

  // Initiate a connection.
  public startConnect(peerDevice: string): void {
    // Configure connection parameters.
    let option: socket.SppOptions = {
      uuid: '00009999-0000-1000-8000-00805F9B34FB', // The UUID service to be connected must be supported by the server.
      secure: false,
      type: socket.SppType.SPP_RFCOMM
    };
    console.info('startConnect ' + peerDevice);
    socket.sppConnect(peerDevice, option, (err, num: number) => {
      if (err) {
        console.error('startConnect errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
      } else {
        console.info('startConnect clientNumber: ' + num);
        this.clientNumber = num;
      }
    });
    console.info('startConnect after ' + peerDevice);
  }

  // Send data.
  public sendData() {
    console.info('sendData ' + this.clientNumber);
    let arrayBuffer = new ArrayBuffer(2);
    let data = new Uint8Array(arrayBuffer);
    data[0] = 3;
    data[1] = 4;
    try {
      socket.sppWrite(this.clientNumber, arrayBuffer);
    } catch (err) {
      console.error('sppWrite errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // Define the callback for data read events.
  read = (dataBuffer: ArrayBuffer) => {
    let data = new Uint8Array(dataBuffer);
    console.info('client data: ' + JSON.stringify(data));
  };

  // Read data.
  public readData() {
    try {
      // Enable listening for data read events.
      socket.on('sppRead', this.clientNumber, this.read);
    } catch (err) {
      console.error('readData errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // Terminate the connection.
  public stopConnect() {
    console.info('closeSppClient ' + this.clientNumber);
    try {
      // Disable listening for data read events.
      socket.off('sppRead', this.clientNumber, this.read);
    } catch (err) {
      console.error('off sppRead errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
    try {
      // Disconnect from the client.
      socket.sppCloseClientSocket(this.clientNumber);
    } catch (err) {
      console.error('stopConnect errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }
}

let sppClientManager = new SppClientManager();
export default sppClientManager as SppClientManager;
```

### Server
```ts
import { socket } from '@kit.ConnectivityKit'
import { BusinessError } from '@kit.BasicServicesKit';

class SppServerManager {
  serverNumber: number = -1;
  clientNumber: number = -1;

  // Create a listening socket on the server.
  public startListen(): void {
    console.info('startListen');

    // Set listening parameters.
    let option: socket.SppOptions = {
      uuid: '00009999-0000-1000-8000-00805F9B34FB',
      secure: false,
      type: socket.SppType.SPP_RFCOMM
    };

    // Create a listening socket on the server. The UUID service is registered in the Bluetooth subsystem.
    socket.sppListen("demonstration", option, (err, num: number) => {
      if (err) {
        console.error('sppListen errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
      } else {
        console.info('sppListen serverNumber: ' + num);
        this.serverNumber = num;
      }
    });
  }

  // Enable listening for connection requests and wait for connections.
  public accept() {
    console.info('accept ' + this.serverNumber);
    socket.sppAccept(this.serverNumber, (err, num: number) => {
      if (err) {
        console.error('accept errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
      } else {
        console.info('accept clientNumber: ' + num);
        this.clientNumber = num;
      }
    });
  }

  // Send data.
  public sendData() {
    console.info('sendData serverNumber: ' + this.serverNumber + ' clientNumber: ' + this.clientNumber);
    let arrayBuffer = new ArrayBuffer(2);
    let data = new Uint8Array(arrayBuffer);
    data[0] = 9;
    data[1] = 8;
    try {
      socket.sppWrite(this.clientNumber, arrayBuffer);
    } catch (err) {
      console.error('sppWrite errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // Define the callback for data read events.
  read = (dataBuffer: ArrayBuffer) => {
    let data = new Uint8Array(dataBuffer);
    console.info('client data: ' + JSON.stringify(data));
  };

  // Read data.
  public readData() {
    try {
      // Enable listening for data read events.
      socket.on('sppRead', this.clientNumber, this.read);
    } catch (err) {
      console.error('readData errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // Terminate the connection.
  public stopConnect() {
    console.info('stopConnect');
    try {
      // Disable listening for data read events.
      socket.off('sppRead', this.clientNumber, this.read);
    } catch (err) {
      console.error('off sppRead errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
    try {
      // Disconnect from the server.
      socket.sppCloseClientSocket(this.clientNumber);
    } catch (err) {
      console.error('stopConnect errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // Close the server socket.
  public closeSppServer() {
    console.info('closeSppServer');
    try {
      // If the application no longer needs the server socket, proactively delete it.
      socket.sppCloseServerSocket(this.serverNumber);
    } catch (err) {
      console.error('sppCloseServerSocket errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }
}

let sppServerManager = new SppServerManager();
export default sppServerManager as SppServerManager;
```
