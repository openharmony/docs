# GATT Development

## Introduction
Generic Attribute Profile (GATT) provides profile discovery and description services for BLE protocol. It defines how ATT attributes are organized and exchanged over a BLE connection.<br>A GATT server (referred to as server in this topic) is a device that stores attribute data locally and provides data access to a remote GATT client paired via BLE. A GATT client (referred to as client in this topic) is a device that accesses data on the remote GATT server via read, write, notify, or indicate operations.

## When to Use

You can use the APIs provided by the **gatt** module to:
- Connect to the server and read and write data in the server.
- Manage services on the server and respond to the requests from the client.

## Available APIs

For details about the APIs and sample code, see [@ohos.bluetooth.ble](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md).

The following table describes the related APIs.

| API                                     | Description                                                                                              |
| ------------------------------------------ | ------------------------------------------------------------------------------------------------------ |
| connect()                                  | Connects the client to the remote BLE device.                                                                     |
| disconnect()                               | Disconnects the client from the remote BLE device.                                                                 |
| close()                                    | Closes this client to unregister it from the protocol stack. After this API is called, this **GattClientDevice** instance cannot be used any longer.|
| getDeviceName()                            | Obtains the name of the remote BLE device for the client.                                                                         |
| getServices()                              | Obtains all services of the remote BLE device for the client.                                                        |
| readCharacteristicValue()                  | Reads a characteristic value of a service of the remote BLE device.                                                              |
| readDescriptorValue()                      | Reads the descriptor contained in a characteristic of the remote BLE device.                                                        |
| writeCharacteristicValue()                 | Writes a characteristic value to the remote BLE device.                                                                |
| writeDescriptorValue()                     | Writes binary data to a descriptor of the remote BLE device.                                                       |
| getRssiValue()                             | Obtains the received signal strength indication (RSSI) of the peer BLE device. This API can be used only after a connection is set up by **connect()**.|
| setBLEMtuSize()                            | Sets the maximum transmission unit (MTU) that can be transmitted between the client and its peer BLE device. This API can be used only after a connection is set up by **connect()**.|
| setCharacteristicChangeNotification()      | Sets the characteristic change notification. The client will be notified when the characteristic value of the remote BLE device changes.                                                                         |
| setCharacteristicChangeIndication()        | Sets the characteristic change indication. The client will be indicated when the characteristic value of the remote BLE device changes.                                                                         |
| on(type: 'BLECharacteristicChange')        | Subscribes to the BLE characteristic changes. The client can receive a notification from the server only after the **setNotifyCharacteristicChanged** method is called.       |
| off(type: 'BLECharacteristicChange')       | Unsubscribes from the BLE characteristic changes.                                                                    |
| on(type: 'BLEConnectionStateChange')       | Subscribes to the BLE connection state changes for the client.                                                              |
| off(type: 'BLEConnectionStateChange')      | Unsubscribes from the BLE connection state changes for the client.                                                                  |
| on(type: 'BLEMtuChange')                   | Subscribes to MTU status changes for the client.                                                                               |
| off(type: 'BLEMtuChange')                  | Unsubscribes from MTU status changes for the client.                                                                           |
| addService()                               | Adds a service to this server.                                                                                          |
| removeService()                            | Removes a service from this server.                                                                                          |
| close()                                    | Closes this server to unregister it from the protocol stack. After this API is called, the **GattServer** instance cannot be used any longer.                            |
| notifyCharacteristicChanged()              | Notifies a connected client device when a characteristic value changes.                                                          |
| sendResponse()                             | Sends a response to a read or write request from the client.                                                                            |
| on(type: 'characteristicRead')             | Subscribes to the characteristic read request event for the server.                                                                              |
| off(type: 'characteristicRead')            | Unsubscribes from the characteristic read request event for the server.                                                                          |
| on(type: 'characteristicWrite')            | Subscribes to the characteristic write request event for the server.                                                                              |
| off(type: 'characteristicWrite')           | Unsubscribes from the characteristic write request event for the server.                                                                          |
| on(type: 'descriptorRead')                 | Subscribes to the descriptor read request event for the server.                                                                              |
| off(type: 'descriptorRead')                | Unsubscribes from the descriptor read request event for the server.                                                                          |
| on(type: 'descriptorWrite')                | Subscribes to the descriptor write request event for the server.                                                                              |
| off(type: 'descriptorWrite')               | Unsubscribes from the descriptor write request event for the server.                                                                          |
| on(type: 'connectionStateChange')          | Subscribes to the BLE connection state changes for the server.                                                                           |
| off(type: 'connectionStateChange')         | Unsubscribes from the BLE connection state changes for the server.                                                                       |
| on(type: 'BLEMtuChange')                   | Subscribes to MTU status changes for the server.                                                                               |
| off(type: 'BLEMtuChange')                  | Unsubscribes from MTU status changes for the server.                                                                           |

## How to Develop

### Reading and Writing Data in the Server
1. Import the **ble** module.
2. Create a **gattClient** instance.
3. Connect to the server.
4. Obtain the device name, services information, and RSSI of the server.
5. Read characteristics and descriptors from the server.
6. Write characteristics and descriptors to the server.
7. Disconnect from the server and close the **gattClient** instance.

Example:

```ts
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';

// serverDeviceId is the device ID of the GATT server obtained after Bluetooth scanning is started.
let serverDeviceId = 'xx:xx:xx:xx:xx:xx';

// Create a GattClientDevice instance.
let clientDevice = ble.createGattClientDevice(serverDeviceId);

// Connect to the server.
clientDevice.connect();

// Subscribe to connection status changes.
clientDevice.on('BLEConnectionStateChange', (bleConnectionState) => {
  let bleConnectionStateInfo = '';
  switch (bleConnectionState.state) {
    case 0:
      bleConnectionStateInfo = 'DISCONNECTED';
      break;
    case 1:
      bleConnectionStateInfo = 'CONNECTING';
      break;
    case 2:
      bleConnectionStateInfo = 'STATE_CONNECTED';
      break;
    case 3:
      bleConnectionStateInfo = 'STATE_DISCONNECTING';
      break;
    default:
      bleConnectionStateInfo = 'undefined';
      break;
  }
  console.info('status: ' + bleConnectionStateInfo);
})

// Obtain the server device name.
clientDevice.getDeviceName((err: BusinessError, data: string) => {
  console.info('getDeviceName success, deviceName = ' + JSON.stringify(data));
})

// Obtain the service information of the server.
clientDevice.getServices((code, gattServices) => {
  let message = '';
  if (code != null) {
    console.error('getServices error, errCode: ' + (code as BusinessError).code + ', errMessage: ' + (code as BusinessError).message);
  } else {
    for (let i = 0; i < gattServices.length; i++) {
      message += 'serviceUuid is ' + gattServices[i].serviceUuid + '\n';
    }
    console.info('getServices success, ' + message);
  }
})

// Obtain the RSSI.
clientDevice.getRssiValue((err, cbRssi) => {
  console.info('return code = ' + JSON.stringify(err) + ', RSSI = ' + JSON.stringify(cbRssi))
});

// Set the MTU to 256.
clientDevice.setBLEMtuSize(256);

// Read a characteristic from the server.
// The values of the following fields are obtained from the result returned by getServices().
let serviceUuid = 'xxx';
let characteristicUuid = 'xxx';
let descriptorUuid = 'xxx';
let descriptorValue = new Uint8Array('xxx'.length).buffer;
let characteristicValue = new Uint8Array('xxx'.length).buffer;
let descriptors: Array<ble.BLEDescriptor> = new Array<ble.BLEDescriptor>();
let descriptor: ble.BLEDescriptor = {
  serviceUuid: serviceUuid,
  characteristicUuid: characteristicUuid,
  descriptorUuid: descriptorUuid,
  descriptorValue: descriptorValue
}
descriptors.push(descriptor);
let bleCharacteristicDataIn: ble.BLECharacteristic = {
  serviceUuid: serviceUuid,
  characteristicUuid: characteristicUuid,
  characteristicValue: characteristicValue,
  descriptors: descriptors
};
clientDevice.readCharacteristicValue(bleCharacteristicDataIn, (err, bleCharacteristicDataOut) => {
  if (err != null) {
    console.error('readCharacteristicValue error, code = ' + (err as BusinessError).code)
    return;
  }
  let message = 'characteristic value = ';
  let value = new Uint8Array(bleCharacteristicDataOut.characteristicValue);
  for (let i = 0; i < bleCharacteristicDataOut.characteristicValue.byteLength; i++) {
    message += value[i];
  }
  console.info(message);
});

// Read a descriptor.
let descriptorIn: ble.BLEDescriptor = {
  serviceUuid: serviceUuid,
  characteristicUuid: characteristicUuid,
  descriptorUuid: descriptorUuid,
  descriptorValue: descriptorValue
};
clientDevice.readDescriptorValue(descriptorIn, (err, descriptorOut) => {
  if (err != null) {
    console.error('readDescriptorValue error, code: ' + (err as BusinessError).code)
    return;
  }
  let message = 'descriptor value: ';
  let value = new Uint8Array(descriptorOut.descriptorValue);
  for (let i = 0; i < descriptorOut.descriptorValue.byteLength; i++) {
    message += value[i];
  }
  console.info(message);
});

// Write a characteristic.
let string2ArrayBuffer: (str: string) => ArrayBuffer = (str: string): ArrayBuffer => {
  let array = new Uint8Array(str.length);
  for (let i = 0; i < str.length; i++) {
    array[i] = str.charCodeAt(i);
  }
  return array.buffer;
}

let bufferCCC = string2ArrayBuffer('V');
let characteristic: ble.BLECharacteristic = {
  serviceUuid: serviceUuid,
  characteristicUuid: characteristicUuid,
  characteristicValue: bufferCCC,
  descriptors: descriptors
};
clientDevice.writeCharacteristicValue(characteristic, ble.GattWriteType.WRITE);

// Write a descriptor.
let message = '';
if (clientDevice.writeDescriptorValue(descriptor)) {
  message = 'writeDescriptorValue success';
} else {
  message = 'writeDescriptorValue failed';
}
console.info(message);

// Disconnect from the server.
clientDevice.disconnect();
console.info('disconnect success')

// Close the GattClient instance.
clientDevice.close();
console.info('close gattClientDevice success');
```

For details about the error codes, see [Bluetooth Error Codes](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md).


### Managing Services on the Server and Notifying the Client
1. Import the **ble** module.
2. Create a **gattServer** object.
3. Add services.
4. Notify the client after a characteristic is written to the server.
5. Remove services.
6. Close the gattServer instance.

Example:

```ts
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';

// Create a gattServer instance.
let gattServerInstance = ble.createGattServer();

// Add services.
let string2ArrayBuffer: (str: string) => ArrayBuffer = (str: string): ArrayBuffer => {
  let array = new Uint8Array(str.length);
  for (let i = 0; i < str.length; i++) {
    array[i] = str.charCodeAt(i);
  }
  return array.buffer;
}

let characteristicsArray: Array<ble.BLECharacteristic> = new Array<ble.BLECharacteristic>();
let descriptorsArray: Array<ble.BLEDescriptor> = new Array<ble.BLEDescriptor>();
let characteristics1: ble.BLECharacteristic = {
  serviceUuid: '0000aaaa-0000-1000-8000-00805f9b34fb',
  characteristicUuid: '00002a10-0000-1000-8000-00805f9b34fb',
  characteristicValue: string2ArrayBuffer('I am charac1'),
  descriptors: descriptorsArray
};
characteristicsArray.push(characteristics1);

let descriptors1: ble.BLEDescriptor = {
  serviceUuid: '0000aaaa-0000-1000-8000-00805f9b34fb',
  characteristicUuid: '00002a10-0000-1000-8000-00805f9b34fb',
  descriptorUuid: '00002904-0000-1000-8000-00805f9b34fb',
  descriptorValue: string2ArrayBuffer('I am Server Descriptor1')
}
let descriptors2: ble.BLEDescriptor = {
  serviceUuid: '0000aaaa-0000-1000-8000-00805f9b34fb',
  characteristicUuid: '00002a10-0000-1000-8000-00805f9b34fb',
  descriptorUuid: '00002905-0000-1000-8000-00805f9b34fb',
  descriptorValue: string2ArrayBuffer('I am Server Descriptor2')
}
descriptorsArray.push(descriptors1);
descriptorsArray.push(descriptors2);

let service: ble.GattService = {
  serviceUuid: '0000aaaa-0000-1000-8000-00805f9b34fb',
  isPrimary: true,
  characteristics: characteristicsArray
};
gattServerInstance.addService(service);
console.info('addService success');

// Subscribe to the characteristic write event and send a response to gattClient.
gattServerInstance.on('characteristicWrite', (characteristicWriteReq) => {
  let deviceId = characteristicWriteReq.deviceId;
  let transId = characteristicWriteReq.transId;
  let offset = characteristicWriteReq.offset;
  let needRsp = characteristicWriteReq.needRsp;
  let arrayBufferCCC: ArrayBuffer = string2ArrayBuffer('characteristicWriteForResponse');
  let serverResponse: ble.ServerResponse = {
    deviceId: deviceId,
    transId: transId,
    status: 0,
    offset: offset,
    value: arrayBufferCCC
  };
  // Send a response.
  if (needRsp) {
    gattServerInstance.sendResponse(serverResponse);
    console.info('sendResponse success, response data: ' + JSON.stringify(serverResponse));
  }
  // Unsubscribe from the characteristic write event.
  gattServerInstance.off('characteristicWrite');
})

// Subscribe to the characteristic write event and notify the gattClient of the characteristic change.
gattServerInstance.on('characteristicWrite', (characteristicWriteReq) => {
  let characteristicUuid = characteristicWriteReq.characteristicUuid;
  let serviceUuid = characteristicWriteReq.serviceUuid;
  let deviceId = characteristicWriteReq.deviceId;
  let notifyCharacteristic: ble.NotifyCharacteristic = {
    serviceUuid: serviceUuid,
    characteristicUuid: characteristicUuid,
    characteristicValue: string2ArrayBuffer('Value4notifyCharacteristic'),
    confirm: false
  }
  // Notify the connected client devices when the characteristic changes.
  gattServerInstance.notifyCharacteristicChanged(deviceId, notifyCharacteristic);
  console.info('notifyCharacteristicChanged success, deviceId = ' + deviceId);
  // Unsubscribe from the characteristic write event.
  gattServerInstance.off('characteristicWrite');
})

// Remove a service.
gattServerInstance.removeService('0000aaaa-0000-1000-8000-00805f9b34fb');
console.info('removeService success')

// Close the gattServer instance.
gattServerInstance.close();
console.info('close gattServerInstance success');
```

For details about the error codes, see [Bluetooth Error Codes](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md).
