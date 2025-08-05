# GATT-based Connection and Data Transmission

## Introduction
This document guides you through implementing Bluetooth Low Energy (BLE) connection and data transmission between devices in accordance with the Generic Attribute Profile (GATT). When two devices communicate via GATT, they can be distinguished as client and server based on their respective functions. This guide describes the implementation methods for both the client and server.

GATT is the core protocol of BLE, defining the mechanism for Bluetooth communication and data transmission based on services, characteristics, and descriptors. For details about related terms, see [Terminology](../terminology.md).

## How to Implement
After obtaining the server's device address, the client can initiate a connection to the server. The server's device address can be obtained through the BLE scanning process. Once the connection between the server and the client is successfully established, the client can initiate operations such as querying services, reading from and writing to characteristics, and receiving notifications from the server, thereby enabling the client to send data to and receive data from the server.

The server must broadcast BLE advertisements to be discoverable by the client. It should support the services the client intends to connect to and await the client's connection request. Once connected, the server can handle the client's requests to read and write characteristics, as well as send notifications to the client, thus enabling the server to both receive data from and send data to the client.

For details about BLE scanning by the client and BLE advertising by the server, see [Bluetooth Discovery Development](ble-development-guide.md).

## How to Develop

### Applying for Required Permissions
Apply for the **ohos.permission.ACCESS_BLUETOOTH** permission. For details about how to configure and apply for permissions, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md) and [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

### Importing Required Modules
Import the **ble**, **constant**, and **BusinessError** modules.
```ts
import { ble, constant } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
```
### Client

#### 1. Creating a Client Instance
After the client discovers the target device through the device discovery process, it can instantiate a client object. All subsequent operations will be performed using this client instance.
```ts
// The following is pseudo code.
let device = 'XX:XX:XX:XX:XX:XX';

try {
  let gattClient: ble.GattClientDevice = ble.createGattClientDevice(device);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 2. Subscribing to Connection State Changes
You can subscribe to connection state changes to obtain the real-time GATT connection state. The connection process involves various state transitions. [STATE_CONNECTED](../../reference/apis-connectivity-kit/js-apis-bluetooth-constant.md#profileconnectionstate) indicates that the connection is established, and [STATE_DISCONNECTED](../../reference/apis-connectivity-kit/js-apis-bluetooth-constant.md#profileconnectionstate) indicates that the connection is disconnected.
```ts
// The following is pseudo code.
let device = 'XX:XX:XX:XX:XX:XX';

function clientConnectStateChanged(state: ble.BLEConnectionChangeState) {
  console.info('bluetooth connect state changed');
  let connectState: ble.ProfileConnectionState = state.state;
}

try {
  let gattClient: ble.GattClientDevice = ble.createGattClientDevice(device);
  gattClient.on('BLEConnectionStateChange', clientConnectStateChanged);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 3. Initiating a Connection
Initiate a connection using the created client instance. Determine whether the connection is successful based on the connection state change event.
```ts
// The following is pseudo code.
let device = 'XX:XX:XX:XX:XX:XX';

try {
    let gattClient: ble.GattClientDevice = ble.createGattClientDevice(device);
    gattClient.connect();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 4. Implementing Service Discovery
Service discovery is a process of obtaining all the service capabilities supported by the server. The client needs to determine whether the server supports the service capabilities required by the application based on the service discovery result.
- Characteristics and descriptors can be read or written only after service discovery is complete.
- The characteristics or descriptors specified in subsequent read and write operations must be included in the service capability set. Otherwise, the operations will fail.
```ts
// The following is pseudo code.
let device = 'XX:XX:XX:XX:XX:XX';

try {
  let gattClient: ble.GattClientDevice = ble.createGattClientDevice(device);
  // The following is pseudo code and can be called only after the connection is established.
  gattClient.getServices().then((result: Array<ble.GattService>) => {
    console.info('getServices successfully:' + JSON.stringify(result));
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 5. Transmitting Data
Data transmission is implemented by operating the characteristic or descriptor of the server.

**5.1 Reading or Writing a Characteristic**<br>
Reading a characteristic enables the client to retrieve the value of that characteristic from the server.<br>
Writing a characteristic allows the client to update the value of the corresponding characteristic on the server.<br>
For details about related APIs, see [readCharacteristicValue](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#readcharacteristicvalue) and [writeCharacteristicValue](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#writecharacteristicvalue).
```ts
// The following is pseudo code.
let device = 'XX:XX:XX:XX:XX:XX';
let descriptors: Array<ble.BLEDescriptor> = [];
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor: ble.BLEDescriptor = {
  serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00008888-0000-1000-8000-00805F9B34FB',
  descriptorValue: bufferDesc
};
descriptors[0] = descriptor;
let bufferCCC = new ArrayBuffer(2);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic: ble.BLECharacteristic = {
  serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  characteristicValue: bufferCCC,
  descriptors:descriptors
};

let gattClient: ble.GattClientDevice = ble.createGattClientDevice(device);

// Read a characteristic.
try {
  gattClient.readCharacteristicValue(characteristic).then((outData: ble.BLECharacteristic) => {
  });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

// Write a characteristic.
try {
  gattClient.writeCharacteristicValue(characteristic, ble.GattWriteType.WRITE, (err) => {
    if (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
      return;
    }
    console.info(TAG, 'writeCharacteristicValue success');
  });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**5.2 Reading or Writing a Descriptor**<br>
Reading a descriptor enables the client to retrieve the value of that descriptor from the server.<br>
Writing a descriptor allows the client to update the value of the corresponding descriptor on the server.<br>
For details about related APIs, see [readDescriptorValue](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#readdescriptorvalue) and [writeDescriptorValue](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#writedescriptorvalue).
```ts
// The following is pseudo code.
let device = 'XX:XX:XX:XX:XX:XX';
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor: ble.BLEDescriptor = {
  serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00008888-0000-1000-8000-00805F9B34FB',
  descriptorValue: bufferDesc
};
let gattClient: ble.GattClientDevice = ble.createGattClientDevice(device);

// Read a descriptor.
try {
  gattClient.readDescriptorValue(descriptor).then((outData: ble.BLEDescriptor) => {
  });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

// Write a descriptor.
try {
  gattClient.writeDescriptorValue(descriptor, (err) => {
    if (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
      return;
    }
  });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**5.3 Receiving Notifications or Indications for Server's Characteristic Value Changes**<br>
When the server's characteristic value changes, the client can receive notifications or indications of this change to update its local data. For a characteristic to support these capabilities, it must include the UUID (00002902-0000-1000-8000-00805f9b34fb) of the CCC descriptor as defined by the Bluetooth protocol.

Notifications do not require a client response, while indications mandate an acknowledgment. This acknowledgment mechanism is handled by the Bluetooth subsystem and therefore you do not need to implement this mechanism on your own. To enable the client to receive notifications or indications, also perform the following:

- Subscribe to server's characteristic changes. For details, see [on('BLECharacteristicChange ')](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#onblecharacteristicchange).
- Depending on the use case, enable the notification or indication function for server's characteristic changes. For details about related APIs, see [setCharacteristicChangeNotification](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#setcharacteristicchangenotification) and [setCharacteristicChangeIndication](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#setcharacteristicchangeindication).
```ts
// The following is pseudo code.
let device = 'XX:XX:XX:XX:XX:XX';

// Define the server's characteristic change event.
function characteristicChange(characteristicChangeReq: ble.BLECharacteristic) {
  let serviceUuid: string = characteristicChangeReq.serviceUuid;
  let characteristicUuid: string = characteristicChangeReq.characteristicUuid;
  let value: Uint8Array = new Uint8Array(characteristicChangeReq.characteristicValue);
}

let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(2);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
let descriptor: ble.BLEDescriptor = {
  serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB',
  descriptorValue: arrayBuffer
};
descriptors[0] = descriptor;
let arrayBufferC = new ArrayBuffer(2);
let characteristic: ble.BLECharacteristic = {
  serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  characteristicValue: arrayBufferC,
  descriptors:descriptors
};

let gattClient: ble.GattClientDevice = ble.createGattClientDevice(device);

// Subscribe to server's characteristic changes.
try {
    gattClient.on('BLECharacteristicChange', characteristicChange);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

// Enable the notification or indication function for characteristic value changes.
// Enable the notification function for characteristic value changes.
try {
  // enable: true if the notification function is enabled; false otherwise.
  gattClient.setCharacteristicChangeNotification(characteristic, true, (err: BusinessError) => {
    if (err) {
      console.error('setCharacteristicChangeNotification callback failed');
    } else {
      console.info('setCharacteristicChangeNotification callback successful');
    }
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

// Enable the indication function for characteristic value changes.
try {
  // enable: true if the indication function is enabled; false otherwise.
  gattClient.setCharacteristicChangeIndication(characteristic, true, (err: BusinessError) => {
    if (err) {
      console.error('setCharacteristicChangeIndication callback failed');
    } else {
      console.info('setCharacteristicChangeIndication callback successful');
    }
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 6. Terminating the Connection
If a connection is no longer needed, the application must disconnect the connection.
```ts
// The following is pseudo code.
let device = 'XX:XX:XX:XX:XX:XX';

let gattClient: ble.GattClientDevice = ble.createGattClientDevice(device);
try {
  // Initiate disconnection.
  gattClient.disconnect();

  // Close the gattClient instance if it is no longer needed. It becomes unavailable after being closed.
  gattClient.close() 
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### Server

#### 1. Creating a Server Instance
Create a server instance. All subsequent operations will be performed using this server instance.
```ts
try {
  let gattServer: ble.GattServer = ble.createGattServer();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 2. Adding Services
Add a service required by the application. The service will be registered with the Bluetooth subsystem using the specified UUID. The client initiates a service query to check whether the service is supported by the server.
```ts
// Create descriptors.
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(2);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
let descriptor: ble.BLEDescriptor = {
  serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB',
  descriptorValue: arrayBuffer};
descriptors[0] = descriptor;

// Create characteristics.
let characteristics: Array<ble.BLECharacteristic> = [];
let arrayBufferC = new ArrayBuffer(2);
let cccV = new Uint8Array(arrayBufferC);
cccV[0] = 1;
let characteristic: ble.BLECharacteristic = {
  serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  characteristicValue: arrayBufferC,
  descriptors:descriptors
};
characteristics[0] = characteristic;

// Create a gattService instance.
let gattService: ble.GattService = {
  serviceUuid:'00001810-0000-1000-8000-00805F9B34FB',
  isPrimary: true,
  characteristics:characteristics,
  includeServices:[]
};

try {
  let gattServer: ble.GattServer = ble.createGattServer(); 
  gattServer.addService(gattService);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 3. Subscribing to Connection State Changes
You can subscribe to connection state changes to obtain the real-time GATT connection state and the device address of the client. The connection process involves various state transitions. [STATE_CONNECTED](../../reference/apis-connectivity-kit/js-apis-bluetooth-constant.md#profileconnectionstate) indicates that the connection is established, and [STATE_DISCONNECTED](../../reference/apis-connectivity-kit/js-apis-bluetooth-constant.md#profileconnectionstate) indicates that the connection is disconnected.
```ts
function ServerConnectStateChanged(state: ble.BLEConnectionChangeState) {
  console.info('bluetooth connect state changed');
  let connectState: ble.ProfileConnectionState = state.state;
  let device = state.deviceId;
}

try {
  let gattServer: ble.GattServer = ble.createGattServer(); 
  gattServer.on('connectionStateChange', ServerConnectStateChanged);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 4. Transmitting Data
Data transmission can be implemented by reading and writing characteristics, reading and writing descriptors, and actively sending notifications or indications of characteristic changes.

**4.1 Subscribing to Characteristic Read or Write Events**<br>
You can subscribe to characteristic read or write events to obtain the operation requests of the client. For details about the related APIs, see [on('characteristicRead ')](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#oncharacteristicread) and [on('characteristicWrite ')](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#oncharacteristicwrite).

- When receiving a characteristic read request, call [sendResponse](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#sendresponse) needs to be called to return the value of the corresponding characteristic.
- When receiving a characteristic write request, save the characteristic value written by the client. Based on the **needRsp** parameter in [CharacteristicWriteRequest](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#characteristicwriterequest), determine whether to call [sendResponse](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#sendresponse) to acknowledge the write operation.
```ts
let gattServer: ble.GattServer = ble.createGattServer();
let arrayBufferCCC = new ArrayBuffer(2);
let cccValue = new Uint8Array(arrayBufferCCC);
cccValue[0] = 1;

// Define the callback for the characteristic read request.
function readCharacteristicReq(characteristicReadRequest: ble.CharacteristicReadRequest) {
  let deviceId: string = characteristicReadRequest.deviceId;
  let transId: number = characteristicReadRequest.transId;
  let offset: number = characteristicReadRequest.offset;
  let characteristicUuid: string = characteristicReadRequest.characteristicUuid;

  let serverResponse: ble.ServerResponse = {
    deviceId: deviceId,
    transId: transId,
    status: 0,
    offset: offset,
    value:arrayBufferCCC // Characteristic value. The following is pseudo code.
  };

  try {
    gattServer.sendResponse(serverResponse);
  } catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
  }
}

// Define the callback for the characteristic write request.
function writeCharacteristicReq(characteristicWriteRequest: ble.CharacteristicWriteRequest) {
  let deviceId: string = characteristicWriteRequest.deviceId;
  let transId: number = characteristicWriteRequest.transId;
  let offset: number = characteristicWriteRequest.offset;
  let needRsp: boolean = characteristicWriteRequest.needRsp;
  if (!needRsp) { // Check whether a response needs to be returned to the client.
      return;
  }
  let value: Uint8Array = new Uint8Array(characteristicWriteRequest.value); // Save the written characteristic value.
  let characteristicUuid: string = characteristicWriteRequest.characteristicUuid;
  cccValue[0] = value[0];
  let serverResponse: ble.ServerResponse = {
    deviceId: deviceId,
    transId: transId,
    status: 0,
    offset: offset,
    value:arrayBufferCCC
  };

  try {
    gattServer.sendResponse(serverResponse);
  } catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
  }
}

// Subscribe to characteristic read events.
gattServer.on('characteristicRead', readCharacteristicReq);

// Subscribe to characteristic write events.
gattServer.on('characteristicWrite', writeCharacteristicReq);
```

**4.2 Subscribing to Descriptor Read or Write Events**<br>
You can subscribe to descriptor read or write events to obtain the operation requests of the client. For details about the related APIs, see [on('descriptorRead')](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#ondescriptorread) and [on('descriptorWrite')](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#ondescriptorwrite).

- When receiving a descriptor read request, call [sendResponse](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#sendresponse) to return the value of the corresponding descriptor.
- When receiving a descriptor write request, save the descriptor value written by the client. Based on the **needRsp** parameter in the client [DescriptorWriteRequest](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#descriptorwriterequest), determine whether to call [sendResponse](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#sendresponse) to acknowledge the write operation.
```ts
let gattServer: ble.GattServer = ble.createGattServer();

// Define the callback for the descriptor read request.
let arrayBufferDesc = new ArrayBuffer(2);
let descValue = new Uint8Array(arrayBufferDesc);
descValue[0] = 1;
function readDescriptorReq(descriptorReadRequest: ble.DescriptorReadRequest) {
  let deviceId: string = descriptorReadRequest.deviceId;
  let transId: number = descriptorReadRequest.transId;
  let offset: number = descriptorReadRequest.offset;
  let descriptorUuid: string = descriptorReadRequest.descriptorUuid;

  let serverResponse: ble.ServerResponse = {
    deviceId: deviceId,
    transId: transId,
    status: 0,
    offset: offset,
    value:arrayBufferDesc
  };

  try {
    gattServer.sendResponse(serverResponse);
  } catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
  }
}

// Define the callback for the descriptor write request.
function writeDescriptorReq(descriptorWriteRequest: ble.DescriptorWriteRequest) {
  let deviceId: string = descriptorWriteRequest.deviceId;
  let transId: number = descriptorWriteRequest.transId;
  let offset: number = descriptorWriteRequest.offset;
  let isPrepared: boolean = descriptorWriteRequest.isPrepared;
  let needRsp: boolean = descriptorWriteRequest.needRsp;
  if (!needRsp) { // Check whether a response needs to be returned to the client.
      return;
  }

  let value: Uint8Array = new Uint8Array(descriptorWriteRequest.value); // Save the written descriptor value.
  let descriptorUuid: string = descriptorWriteRequest.descriptorUuid;
  descValue[0] = value[0];
  let serverResponse: ble.ServerResponse = {
    deviceId: deviceId,
    transId: transId,
    status: 0,
    offset: offset,
    value:arrayBufferDesc
  };

  try {
    gattServer.sendResponse(serverResponse);
  } catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
  }
}

// Subscribe to descriptor read events.
gattServer.on('descriptorRead', readDescriptorReq);

// Subscribe to descriptor write events.
gattServer.on('descriptorWrite', writeDescriptorReq);
```

**4.3 Sending Notifications or Indications of Descriptor Value Changes**<br>
When the server's characteristic value changes, the server can notify the client of the change using a notification or indication. For details about the related APIs, see [notifyCharacteristicChanged](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#notifycharacteristicchanged).

Notifications do not require a client response, while indications mandate an acknowledgment. The application determines whether to send a notification or indication based on the **confirm** parameter in [NotifyCharacteristic](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#notifycharacteristic). To enable the server to notify the client of characteristic value changes, also perform the following:

- Include the UUID (00002902-0000-1000-8000-00805f9b34fb) of the CCC descriptor in the characteristic as defined by the Bluetooth protocol.
- Depending on the use case, enable the notification or indication function by using [setCharacteristicChangeNotification](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#setcharacteristicchangenotification) or [setCharacteristicChangeIndication](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#setcharacteristicchangeindication).
```ts
let device = 'XX:XX:XX:XX:XX:XX'; // Device address, which is the client address and can be obtained from the connection state change event.
let arrayBufferC = new ArrayBuffer(2);
let notifyCharacter: ble.NotifyCharacteristic = {
  serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  characteristicValue: arrayBufferC,
  confirm: true // Determine whether to send a notification or instruction.
};
try {
  let gattServer: ble.GattServer = ble.createGattServer();
  // Send a change notification or indication.
  gattServer.notifyCharacteristicChanged(device, notifyCharacter, (err: BusinessError) => {
    if (err) {
      console.error('notifyCharacteristicChanged callback failed');
    } else {
      console.info('notifyCharacteristicChanged callback successful');
    }
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

#### 5. Closing the Server Instance
If the server instance is no longer needed, you need to close it to release related resources. For example, if you want to delete the registered service and unsubscribe from change events, use the following code:
```ts
try {
  let gattServer: ble.GattServer = ble.createGattServer();
  gattServer.removeService('00001810-0000-1000-8000-00805F9B34FB'); // Delete the registered service.
  gattServer.close() // Close the gattServer instance if it is no longer needed.
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## Complete Sample Code

### Client
```ts
import { ble, constant } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = 'GattClientManager';

export class GattClientManager {
  device: string = '';
  gattClient: ble.GattClientDevice | undefined = undefined;
  connectState: ble.ProfileConnectionState = constant.ProfileConnectionState.STATE_DISCONNECTED;
  myServiceUuid: string = '00001810-0000-1000-8000-00805F9B34FB';
  myCharacteristicUuid: string = '00001820-0000-1000-8000-00805F9B34FB';
  // Client Characteristic Configuration (CCC), a standard GATT descriptor used to enable notifications or indications for characteristic value changes.
  myFirstDescriptorUuid: string = '00002902-0000-1000-8000-00805F9B34FB';
  // Custom descriptor.
  mySecondDescriptorUuid: string = '00008888-0000-1000-8000-00805F9B34FB';

  myService: ble.GattService | undefined = undefined;
  myCharacteristic: ble.BLECharacteristic | undefined = undefined;
  myFirstDescriptor: ble.BLEDescriptor | undefined = undefined;
  mySecondDescriptor: ble.BLEDescriptor | undefined = undefined;

  foundService: boolean = false;
  foundChar: boolean = false;
  foundFirstDes: boolean = false;
  foundSecondDes: boolean = false;

  // Construct BLEDescriptor.
  private initDescriptor(des: string, value: ArrayBuffer): ble.BLEDescriptor {
    let descriptor: ble.BLEDescriptor = {
      serviceUuid: this.myServiceUuid,
      characteristicUuid: this.myCharacteristicUuid,
      descriptorUuid: des,
      descriptorValue: value
    };
    return descriptor;
  }

  // Construct BLECharacteristic.
  private initCharacteristic(isWrite: boolean): ble.BLECharacteristic {
    let descriptors: Array<ble.BLEDescriptor> = [];
    let charBuffer = new ArrayBuffer(2);
    if (isWrite) {
      let charValue = new Uint8Array(charBuffer);
      charValue[0] = 21;
      charValue[1] = 22;
    }
    let characteristic: ble.BLECharacteristic = {
      serviceUuid: this.myServiceUuid,
      characteristicUuid: this.myCharacteristicUuid,
      characteristicValue: charBuffer,
      descriptors: descriptors
    };
    return characteristic;
  }

  private logCharacteristic(char: ble.BLECharacteristic) {
    let message = 'logCharacteristic uuid:' + char.characteristicUuid + ', value: ';
    let value = new Uint8Array(char.characteristicValue);
    message += 'logCharacteristic value: ';
    for (let i = 0; i < char.characteristicValue.byteLength; i++) {
      message += value[i] + ' ';
    }
    console.info(TAG, message);
  }

  private logDescriptor(des: ble.BLEDescriptor) {
    let message = 'logDescriptor uuid:' + des.descriptorUuid + ', value: ';
    let value = new Uint8Array(des.descriptorValue);
    message += 'logDescriptor value: ';
    for (let i = 0; i < des.descriptorValue.byteLength; i++) {
      message += value[i] + ' ';
    }
    console.info(TAG, message);
  }

  private checkService(services: Array<ble.GattService>) {
    for (let i = 0; i < services.length; i++) {
      if (services[i].serviceUuid != this.myServiceUuid) {
        continue;
      }
      this.myService = services[i];
      this.foundService = true;
      for (let j = 0; j < services[i].characteristics.length; j++) {
        if (services[i].characteristics[j].characteristicUuid != this.myCharacteristicUuid) {
          continue;
        }
        this.logCharacteristic(services[i].characteristics[j]);
        this.myCharacteristic = services[i].characteristics[j];
        this.foundChar = true;
        for (let k = 0; k < services[i].characteristics[j].descriptors.length; k++) {
          if (services[i].characteristics[j].descriptors[k].descriptorUuid == this.myFirstDescriptorUuid) {
            this.myFirstDescriptor= services[i].characteristics[j].descriptors[k];
            this.foundFirstDes = true;
            continue;
          }
          if (services[i].characteristics[j].descriptors[k].descriptorUuid == this.mySecondDescriptorUuid) {
            this.mySecondDescriptor = services[i].characteristics[j].descriptors[k];
            this.foundSecondDes = true;
            continue;
          }
        }
      }
    }
    console.info(TAG, 'foundService: ' + this.foundService + ', foundChar: ' + this.foundChar +
      ', foundFirDes: ' + this.foundFirstDes + ', foundSecDes: ' + this.foundSecondDes);
  }

  // 1. Define the callback for connection state changes.
  onGattClientStateChange = (stateInfo: ble.BLEConnectionChangeState) => {
    let state = '';
    switch (stateInfo.state) {
      case 0:
        state = 'DISCONNECTED';
        break;
      case 1:
        state = 'CONNECTING';
        break;
      case 2:
        state = 'CONNECTED';
        break;
      case 3:
        state = 'DISCONNECTING';
        break;
      default:
        state = 'undefined';
        break;
    }
    console.info(TAG, 'onGattClientStateChange: device=' + stateInfo.deviceId + ', state=' + state);
    if (stateInfo.deviceId == this.device) {
      this.connectState = stateInfo.state;
    }
  };

  // 2. Called when the client proactively connects to the server.
  public startConnect(peerDevice: string) { // The peer device is usually obtained via BLE.
    if (this.connectState != constant.ProfileConnectionState.STATE_DISCONNECTED) {
      console.error(TAG, 'startConnect failed');
      return;
    }
    console.info(TAG, 'startConnect ' + peerDevice);
    this.device = peerDevice;
    // 2.1 Use device to construct gattClient. This instance is used for subsequent interactions.
    this.gattClient = ble.createGattClientDevice(peerDevice);
    try {
      // 2.2 Subscribe to the connection state changes.
      this.gattClient.on('BLEConnectionStateChange', this.onGattClientStateChange);

      // 2.3 Initiate a connection.
      this.gattClient.connect();
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 3. After the client is connected, start service discovery.
  public async discoverServices() {
    if (!this.gattClient) {
      console.error(TAG, 'gattClient does not exist');
      return;
    }
    console.info(TAG, 'discoverServices');
    try {
      let serverSerice = await this.gattClient.getServices();
      this.checkService(serverSerice); // Ensure that the required service is available on the server.
      if (typeof this.myService !== 'undefined') {
        console.info(TAG, 'Service: ' + JSON.stringify(this.myService));
      }
      if (typeof this.myCharacteristic !== 'undefined') {
        this.logCharacteristic(this.myCharacteristic);
      }
      if (typeof this.myFirstDescriptor !== 'undefined') {
        this.logDescriptor(this.myFirstDescriptor);
      }
      if (typeof this.mySecondDescriptor !== 'undefined') {
        this.logDescriptor(this.mySecondDescriptor);
      }
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 4. Read a specific characteristic after obtaining the services on the server.
  public readCharacteristicValue() {
    if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
      console.error(TAG, 'gattClient does not exist or state not connected');
      return;
    }
    if (!this.foundChar) { // Ensure that the corresponding characteristic is available on the server.
      console.error(TAG, 'server characteristic does not exist');
      return;
    }

    let characteristic = this.initCharacteristic(false);
    console.info(TAG, 'readCharacteristicValue');
    try {
      this.gattClient.readCharacteristicValue(characteristic).then((outData: ble.BLECharacteristic) => {
        this.myCharacteristic = outData;
        this.logCharacteristic(this.myCharacteristic);
      });
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 5. Write a characteristic value after obtaining the services on the server.
  public writeCharacteristicValue() {
    if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
      console.error(TAG, 'gattClient does not exist or state not connected');
      return;
    }
    if (!this.foundChar) { // Ensure that the corresponding characteristic is available on the server.
      console.error(TAG, 'server characteristic does not exist');
      return;
    }

    let characteristic = this.initCharacteristic(true);
    console.info(TAG, 'writeCharacteristicValue');
    try {
      this.gattClient.writeCharacteristicValue(characteristic, ble.GattWriteType.WRITE, (err) => {
        if (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
          return;
        }
        console.info(TAG, 'writeCharacteristicValue success');
      });
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 6. Read a specific service descriptor after obtaining the services on the server. 
  public readDescriptorValue() {
    if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
      console.error(TAG, 'gattClient does not exist or state not connected');
      return;
    }
    if (!this.foundSecondDes) { // Ensure that the corresponding descriptor is available on the server.
      console.error(TAG, 'server descriptor does not exist');
      return;
    }

    let descBuffer = new ArrayBuffer(0);
    let descriptor = this.initDescriptor(this.mySecondDescriptorUuid, descBuffer);
    console.info(TAG, 'readDescriptorValue');
    try {
      this.gattClient.readDescriptorValue(descriptor).then((outData: ble.BLEDescriptor) => {
        this.logDescriptor(outData);
      });
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 7. Write a service descriptor after obtaining the services on the server. 
  public writeDescriptorValue() {
    if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
      console.error(TAG, 'gattClient does not exist or state not connected');
      return;
    }
    if (!this.foundSecondDes) { // Ensure that the corresponding descriptor is available on the server.
      console.error(TAG, 'server descriptor does not exist');
      return;
    }

    let descBuffer = new ArrayBuffer(2);
    let descValue = new Uint8Array(descBuffer);
    descValue[0] = 41;
    descValue[1] = 42;
    let descriptor = this.initDescriptor(this.mySecondDescriptorUuid, descBuffer);
    console.info(TAG, 'writeDescriptorValue');
    try {
      this.gattClient.writeDescriptorValue(descriptor, (err) => {
        if (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
          return;
        }
        console.info(TAG, 'writeDescriptorValue success');
      });
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 8. Define the callback for characteristic value changes.
  onCharacteristicChange = (char: ble.BLECharacteristic) => {
    console.info(TAG, 'onCharacteristicChange: uuid: ' + char.characteristicUuid + ', value: ' + JSON.stringify(new Uint8Array(char.characteristicValue)));
    this.myCharacteristic = char;
    this.logCharacteristic(this.myCharacteristic);
  }

  // 9. Enable the notification or indication function for characteristic value changes.
  public Notify(enable: boolean) {
    if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
      console.error(TAG, 'gattClient does not exist or state not connected');
      return;
    }

    if (!this.foundFirstDes) { // Ensure that the corresponding client configuration descriptor is available on the server.
      console.error(TAG, 'server client configuration descriptor does not exist');
      return;
    }

    console.info(TAG, 'Notify ' + this.device + ' enable: ' + enable);
    try {
      // Subscribe to characteristic value changes.
      this.gattClient.on('BLECharacteristicChange', this.onCharacteristicChange);
      // Enable the notification function for characteristic value changes. The value true means to enable the the notification function, and the value false means the opposite.
      this.gattClient.setCharacteristicChangeNotification(this.myCharacteristic, enable, (err: BusinessError) => {
        if (err) {
          console.error('setCharacteristicChangeNotification callback failed');
        } else {
          console.info('setCharacteristicChangeNotification callback successful');
        }
      });
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 10. Enable the indication function for characteristic value changes.
  public Indicate(enable: boolean) {
    if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
      console.error(TAG, 'gattClient does not exist or state not connected');
      return;
    }

    if (!this.foundFirstDes) { // Ensure that the corresponding client configuration descriptor is available on the server.
      console.error(TAG, 'server client configuration descriptor does not exist');
      return;
    }

    console.info(TAG, 'Indicate ' + this.device + ' enable: ' + enable);
    try {
      // Subscribe to characteristic value changes.
      this.gattClient.on('BLECharacteristicChange', this.onCharacteristicChange);
      // Enable the indication function for characteristic value changes. The value true means to enable the the indication function, and the value false means the opposite.
      this.gattClient.setCharacteristicChangeIndication(this.myCharacteristic, enable, (err: BusinessError) => {
        if (err) {
          console.error('setCharacteristicChangeIndication callback failed');
        } else {
          console.info('setCharacteristicChangeIndication callback successful');
        }
      });
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 11. Disconnect the client from the server.
  public stopConnect() {
    if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
      console.error(TAG, 'gattClient does not exist or state not connected');
      return;
    }

    console.info(TAG, 'stopConnect ' + this.device);
    try {
      this.gattClient.disconnect(); // 11.1 Disconnect the connection.
      this.gattClient.off('BLEConnectionStateChange', this.onGattClientStateChange); // 11.2 Unsubscribe from connection state changes.
      this.gattClient.off('BLECharacteristicChange', this.onCharacteristicChange); // 11.3 Unsubscribe from characteristic value changes.
      this.gattClient.close() // 11.4 If the gattClient instance is no longer needed, close it to release related resources.
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }
}

let gattClientManager = new GattClientManager();
export default gattClientManager as GattClientManager;
```

### Server
```ts
import { ble, constant } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = 'GattServerManager';

export class GattServerManager {
  device = '';
  gattServer: ble.GattServer | undefined = undefined;
  connectState: ble.ProfileConnectionState = constant.ProfileConnectionState.STATE_DISCONNECTED;
  myServiceUuid: string = '00001810-0000-1000-8000-00805F9B34FB';
  myCharacteristicUuid: string = '00001820-0000-1000-8000-00805F9B34FB';
  // Client Characteristic Configuration (CCC), a standard GATT descriptor used to enable notifications or indications for characteristic value changes.
  myFirstDescriptorUuid: string = '00002902-0000-1000-8000-00805F9B34FB';
  // Custom descriptor.
  mySecondDescriptorUuid: string = '00008888-0000-1000-8000-00805F9B34FB';

  charBuffer = new ArrayBuffer(2);
  charValue = new Uint8Array(this.charBuffer);

  firDescBuffer = new ArrayBuffer(2);
  firDescValue = new Uint8Array(this.firDescBuffer);

  secDescBuffer = new ArrayBuffer(2);
  secDescValue = new Uint8Array(this.secDescBuffer);

  // Construct BLEDescriptor.
  private initDescriptor(des: string, value: ArrayBuffer): ble.BLEDescriptor {
    let descriptor: ble.BLEDescriptor = {
      serviceUuid: this.myServiceUuid,
      characteristicUuid: this.myCharacteristicUuid,
      descriptorUuid: des,
      descriptorValue: value
    };
    return descriptor;
  }

  // Construct BLECharacteristic.
  private initCharacteristic(): ble.BLECharacteristic {
    let descriptors: Array<ble.BLEDescriptor> = [];
    // By default, the notification or indication of characteristic value changes is disabled for the CCC descriptor.
    descriptors[0] = this.initDescriptor(this.myFirstDescriptorUuid, this.firDescBuffer);
    this.secDescValue[0] = 31;
    this.secDescValue[1] = 32;
    descriptors[1] = this.initDescriptor(this.mySecondDescriptorUuid, this.secDescBuffer);
    this.charValue[0] = 1;
    this.charValue[1] = 2;
    let characteristic: ble.BLECharacteristic = {
      serviceUuid: this.myServiceUuid,
      characteristicUuid: this.myCharacteristicUuid,
      characteristicValue: this.charBuffer,
      descriptors: descriptors
    };
    return characteristic;
  }

  // 1. Define the callback for connection state changes.
  onGattServerStateChange = (stateInfo: ble.BLEConnectionChangeState) => {
    let state = '';
    switch (stateInfo.state) {
      case 0:
        state = 'DISCONNECTED';
      break;
      case 1:
        state = 'CONNECTING';
      break;
      case 2:
        state = 'CONNECTED';
      break;
      case 3:
        state = 'DISCONNECTING';
      break;
      default:
        state = 'undefined';
      break;
    }
    console.info(TAG, 'onGattServerStateChange: device=' + stateInfo.deviceId + ', state=' + state);
    this.device = stateInfo.deviceId;
  }

  // 2. Define the callback for characteristic read events.
  onCharacteristicRead = (charReq: ble.CharacteristicReadRequest) => {
    let deviceId: string = charReq.deviceId;
    let transId: number = charReq.transId;
    let offset: number = charReq.offset;
    console.info(TAG, 'receive characteristicRead: uuid: ' + charReq.characteristicUuid + ', value: ' + JSON.stringify(this.charValue));
    let serverResponse: ble.ServerResponse = {
      deviceId: deviceId,
      transId: transId,
      status: 0, // The value 0 indicates the operation is successful.
      offset: offset,
      value: this.charBuffer
    };

    try {
      this.gattServer?.sendResponse(serverResponse);
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  };

  // Check whether the notification function is enabled for the client configuration descriptor.
  private checkDescriptorNotification(buffer: Uint8Array): boolean {
    const notify = new ArrayBuffer(2);
    let notifyValue = new Uint8Array(notify);
    notifyValue.set([1, 0]); // The notification function is enabled for the client configuration descriptor.
    return notifyValue.every((value, index) => value === buffer[index]);
  }

  // Check whether the indication function is enabled for the client configuration descriptor.
  private checkDescriptorIndication(buffer: Uint8Array): boolean {
    const notify = new ArrayBuffer(2);
    let notifyValue = new Uint8Array(notify);
    notifyValue.set([2, 0]); // The indication function is enabled for the client configuration descriptor.
    return notifyValue.every((value, index) => value === buffer[index]);
  }

  // 3. Define the callback for characteristic write events.
  onCharacteristicWrite = (charReq: ble.CharacteristicWriteRequest) => {
    let deviceId: string = charReq.deviceId;
    let transId: number = charReq.transId;
    let offset: number = charReq.offset;
    this.charBuffer = charReq.value;
    this.charValue = new Uint8Array(charReq.value);
    console.info(TAG, 'receive characteristicWrite: uuid: ' + charReq.characteristicUuid + ', needRsp=' + charReq.needRsp + ', value: ' + JSON.stringify(this.charValue));
    if (!charReq.needRsp) {
      return;
    }
    let rspBuffer = new ArrayBuffer(0);
    let serverResponse: ble.ServerResponse = {
      deviceId: deviceId,
      transId: transId,
      status: 0, // The value 0 indicates the operation is successful.
      offset: offset,
      value: rspBuffer
    };

    try {
      this.gattServer?.sendResponse(serverResponse);
      this.sendCharacterChange(); // Simulate the scenario in which a notification or indication is proactively sent when the characteristic value changes.
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 4. Define the callback for descriptor read events.
  onDescriptorRead = (desReq: ble.DescriptorReadRequest) => {
    let deviceId: string = desReq.deviceId;
    let transId: number = desReq.transId;
    let offset: number = desReq.offset;
    let tmpBuffer = new ArrayBuffer(2);
    if (desReq.descriptorUuid == this.myFirstDescriptorUuid) {
      tmpBuffer = this.firDescBuffer;
    } else {
      tmpBuffer = this.secDescBuffer;
    }
    let tmpValue = new Uint8Array(tmpBuffer);
    console.info(TAG, 'receive descriptorRead: ' + desReq.descriptorUuid + ', tmpValue: ' + JSON.stringify(tmpValue));
    let serverResponse: ble.ServerResponse = {
      deviceId: deviceId,
      transId: transId,
      status: 0, // The value 0 indicates the operation is successful.
      offset: offset,
      value: tmpBuffer
    };

    try {
      this.gattServer?.sendResponse(serverResponse);
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 5. Define the callback for descriptor write events.
  onDescriptorWrite = (desReq: ble.DescriptorWriteRequest) => {
    let deviceId: string = desReq.deviceId;
    let transId: number = desReq.transId;
    let offset: number = desReq.offset;
    console.info(TAG, 'receive descriptorWrite: uuid: ' + desReq.descriptorUuid + ', needRsp: '+ desReq.needRsp + ', value: ' + JSON.stringify(new Uint8Array(desReq.value)));
    if (desReq.descriptorUuid == this.myFirstDescriptorUuid) {
      this.firDescBuffer = desReq.value;
      this.firDescValue = new Uint8Array(desReq.value);
    } else {
      this.secDescBuffer = desReq.value;
      this.secDescValue = new Uint8Array(desReq.value);
    }
    if (!desReq.needRsp) {
      return;
    }
    let rspBuffer = new ArrayBuffer(0);
    let serverResponse: ble.ServerResponse = {
      deviceId: deviceId,
      transId: transId,
      status: 0, // The value 0 indicates the operation is successful.
      offset: offset,
      value: rspBuffer
    };

    try {
      this.gattServer?.sendResponse(serverResponse);
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 6. Register a service with the server.
  public registerServer() {
    let characteristics: Array<ble.BLECharacteristic> = [];
    let characteristic = this.initCharacteristic();
    characteristics.push(characteristic);
    let gattService: ble.GattService = {
      serviceUuid: this.myServiceUuid,
      isPrimary: true,
      characteristics: characteristics
    };

    console.info(TAG, 'registerServer ' + this.myServiceUuid);
    try {
      this.gattServer = ble.createGattServer(); // 6.1 Create a gattServer instance, which is used in subsequent interactions.
      this.gattServer.addService(gattService); // 6.2 Register a service.
      this.gattServer.on('connectionStateChange', this.onGattServerStateChange); // 6.3 Subscribe to the connection state changes.
      this.gattServer.on('characteristicRead', this.onCharacteristicRead); // 6.4 Subscribe to characteristic read events.
      this.gattServer.on('characteristicWrite', this.onCharacteristicWrite); // 6.5 Subscribe to characteristic write events.
      this.gattServer.on('descriptorRead', this.onDescriptorRead); // 6.6 Subscribe to descriptor read events.
      this.gattServer.on('descriptorWrite', this.onDescriptorWrite); // 6.7 Subscribe to descriptor write events.
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 7. Send a notification or indication when the characteristic value changes.
  public sendCharacterChange() {
    console.info(TAG, 'sendCharacterChange: uuid: ' + this.myCharacteristicUuid + ', value: ' + JSON.stringify(new Uint8Array(this.charBuffer)));
    if (this.checkDescriptorNotification(this.firDescValue)) {
      let notifyCharacter: ble.NotifyCharacteristic = {
        serviceUuid: this.myServiceUuid,
        characteristicUuid: this.myCharacteristicUuid,
        characteristicValue: this.charBuffer,
        confirm: false
      };
      console.info(TAG, 'sendCharacterChange notification');
      this.gattServer?.notifyCharacteristicChanged(this.device, notifyCharacter, (err: BusinessError) => {
        if (err) {
          console.error(TAG, 'notifyCharacteristicChanged notification callback failed');
        } else {
          console.info(TAG, 'notifyCharacteristicChanged notification callback successful');
        }
      });
    } else if (this.checkDescriptorIndication(this.firDescValue)) {
      let notifyCharacter: ble.NotifyCharacteristic = {
        serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
        characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
        characteristicValue: this.charBuffer,
        confirm: true
      };
      console.info(TAG, 'sendCharacterChange indication');
      this.gattServer?.notifyCharacteristicChanged(this.device, notifyCharacter, (err: BusinessError) => {
        if (err) {
          console.error(TAG, 'notifyCharacteristicChanged indication callback failed');
        } else {
          console.info(TAG, 'notifyCharacteristicChanged indication callback successful');
        }
      });
    } else {
      console.info(TAG, 'notification/indication is disabled');
    }
  }

  // 8. Delete the service from the server if it is no longer needed.
  public unRegisterServer() {
    if (!this.gattServer) {
      console.error(TAG, 'no gattServer');
      return;
    }

    console.info(TAG, 'unRegisterServer ' + this.myServiceUuid);
    try {
      this.gattServer.removeService(this.myServiceUuid); // 8.1 Delete the service.
      this.gattServer.off('connectionStateChange', this.onGattServerStateChange) // 8.2 Unsubscribe from the connection state changes.
      this.gattServer.on('characteristicRead', this.onCharacteristicRead); // 8.3 Subscribe to characteristic read events.
      this.gattServer.on('characteristicWrite', this.onCharacteristicWrite); // 8.4 Subscribe to characteristic write events.
      this.gattServer.on('descriptorRead', this.onDescriptorRead); // 8.5 Subscribe to descriptor read events.
      this.gattServer.on('descriptorWrite', this.onDescriptorWrite); // 8.6 Subscribe to descriptor write events.
      this.gattServer.close() // 8.7 Close the gattServer instance if it is no longer needed.
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }
}

let gattServerManager = new GattServerManager();
export default gattServerManager as GattServerManager;
```
