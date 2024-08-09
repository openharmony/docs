# GATT Development

## Introduction
Generic Attribute Profile (GATT) provides profile discovery and description services for BLE protocol. It defines how ATT attributes are organized and exchanged over a BLE connection.

A GATT server (referred to as server in this topic) is a device that stores attribute data locally and provides data access to a remote GATT client paired via BLE. A GATT client (referred to as client in this topic) is a device that accesses data on the remote GATT server via read, write, notify, or indicate operations.

## When to Use

You can use the APIs provided by the **gatt** module to:
- Connect to the server to read and write data.
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

### Reading and Writing Data on the Server
1. Import the **ble** module.
2. Create a **gattClient** instance.
3. Connect to the server.
4. Read characteristics and descriptors from the server.
5. Write characteristics and descriptors to the server.
6. Disconnect from the server and destroy the **gattClient** instance.

    Example:

    ```ts
    import { ble } from '@kit.ConnectivityKit';
    import { constant } from '@kit.ConnectivityKit';
    import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
    
    const TAG: string = 'GattClientManager';
    
    export class GattClientManager {
      device: string = undefined;
      gattClient: ble.GattClientDevice = undefined;
      connectState: ble.ProfileConnectionState = constant.ProfileConnectionState.STATE_DISCONNECTED;
      myServiceUuid: string = '00001810-0000-1000-8000-00805F9B34FB';
      myCharacteristicUuid: string = '00001820-0000-1000-8000-00805F9B34FB';
      myFirstDescriptorUuid: string = '00002902-0000-1000-8000-00805F9B34FB'; // 2902 is generally used for notification or indication.
      mySecondDescriptorUuid: string = '00002903-0000-1000-8000-00805F9B34FB';
      found: boolean = false;
    
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
        let descBuffer = new ArrayBuffer(2);
        let descValue = new Uint8Array(descBuffer);
        descValue[0] = 11;
        descValue[1] = 12;
        descriptors[0] = this.initDescriptor(this.myFirstDescriptorUuid, new ArrayBuffer(2));
        descriptors[1] = this.initDescriptor(this.mySecondDescriptorUuid, descBuffer);
        let charBuffer = new ArrayBuffer(2);
        let charValue = new Uint8Array(charBuffer);
        charValue[0] = 1;
        charValue[1] = 2;
        let characteristic: ble.BLECharacteristic = {
          serviceUuid: this.myServiceUuid,
          characteristicUuid: this.myCharacteristicUuid,
          characteristicValue: charBuffer,
          descriptors: descriptors
        };
        return characteristic;
      }
    
      private logCharacteristic(char: ble.BLECharacteristic) {
        let message = 'logCharacteristic uuid:' + char.characteristicUuid + '\n';
        let value = new Uint8Array(char.characteristicValue);
        message += 'logCharacteristic value: ';
        for (let i = 0; i < char.characteristicValue.byteLength; i++) {
          message += value[i] + ' ';
        }
        console.info(TAG, message);
      }
    
      private logDescriptor(des: ble.BLEDescriptor) {
        let message = 'logDescriptor uuid:' + des.descriptorUuid + '\n';
        let value = new Uint8Array(des.descriptorValue);
        message += 'logDescriptor value: ';
        for (let i = 0; i < des.descriptorValue.byteLength; i++) {
          message += value[i] + ' ';
        }
        console.info(TAG, message);
      }
    
      private checkService(services: Array<ble.GattService>): boolean {
        for (let i = 0; i < services.length; i++) {
          if (services[i].serviceUuid != this.myServiceUuid) {
            continue;
          }
          for (let j = 0; j < services[i].characteristics.length; j++) {
            if (services[i].characteristics[j].characteristicUuid != this.myCharacteristicUuid) {
              continue;
            }
            for (let k = 0; k < services[i].characteristics[j].descriptors.length; k++) {
              if (services[i].characteristics[j].descriptors[k].descriptorUuid == this.myFirstDescriptorUuid) {
                console.info(TAG, 'find expected service from server');
                return true;
              }
            }
          }
        }
        console.error(TAG, 'no expected service from server');
        return false;
      }
    
      // 1. Subscribe to the connection status change event.
      public onGattClientStateChange() {
        if (!this.gattClient) {
          console.error(TAG, 'no gattClient');
          return;
        }
        try {
          this.gattClient.on('BLEConnectionStateChange', (stateInfo: ble.BLEConnectionChangeState) => {
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
          });
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    
      // 2. Called when the client proactively connects to the server.
      public startConnect(peerDevice: string) {// The peer device is generally discovered through BLE scan.
        if (this.connectState != constant.ProfileConnectionState.STATE_DISCONNECTED) {
          console.error(TAG, 'startConnect failed');
          return;
        }
        console.info(TAG, 'startConnect ' + peerDevice);
        this.device = peerDevice;
        // 2.1 Use device to construct gattClient. This instance is used for subsequent interactions.
        this.gattClient = ble.createGattClientDevice(peerDevice);
        try {
          this.onGattClientStateChange(); // 2.2 Subscribe to the connection status.
          this.gattClient.connect(); // 2.3 Initiate a connection.
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    
      // 3. After the client is connected, start service discovery.
      public discoverServices() {
        if (!this.gattClient) {
          console.info(TAG, 'no gattClient');
          return;
        }
        console.info(TAG, 'discoverServices');
        try {
          this.gattClient.getServices().then((result: Array<ble.GattService>) => {
            console.info(TAG, 'getServices success: ' + JSON.stringify(result));
            this.found = this.checkService(result); // Ensure that the service required exists on the server.
          });
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    
      // 4. Read a specific characteristic after obtaining the services on the server.
      public readCharacteristicValue() {
        if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
          console.error(TAG, 'no gattClient or not connected');
          return;
        }
        if (!this.found) {// Ensure that the server has the corresponding characteristic.
          console.error(TAG, 'no characteristic from server');
          return;
        }
    
        let characteristic = this.initCharacteristic();
        console.info(TAG, 'readCharacteristicValue');
        try {
          this.gattClient.readCharacteristicValue(characteristic).then((outData: ble.BLECharacteristic) => {
            this.logCharacteristic(outData);
          })
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    
      // 5. Write a characteristic value after obtaining the services on the server.
      public writeCharacteristicValue() {
        if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
          console.error(TAG, 'no gattClient or not connected');
          return;
        }
        if (!this.found) {// Ensure that the server has the corresponding characteristic.
          console.error(TAG, 'no characteristic from server');
          return;
        }
    
        let characteristic = this.initCharacteristic();
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
          console.error(TAG, 'no gattClient or not connected');
          return;
        }
        if (!this.found) {// Ensure that the server has the corresponding descriptor.
          console.error(TAG, 'no descriptor from server');
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
          console.error(TAG, 'no gattClient or not connected');
          return;
        }
        if (!this.found) {// Ensure that the server has the corresponding descriptor.
          console.error(TAG, 'no descriptor from server');
          return;
        }
    
        let descBuffer = new ArrayBuffer(2);
        let descValue = new Uint8Array(descBuffer);
        descValue[0] = 11;
        descValue[1] = 12;
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
    
      // 8. The client proactively disconnects from the server.
      public stopConnect() {
        if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
          console.error(TAG, 'no gattClient or not connected');
          return;
        }
    
        console.info(TAG, 'stopConnect ' + this.device);
        try {
          this.gattClient.disconnect (); // 8.1 Disconnect from the server.
          this.gattClient.off('BLEConnectionStateChange', (stateInfo: ble.BLEConnectionChangeState) => {
          });
          this.gattClient.close () // 8.2 Close this gattClient if it is no longer required.
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    }
    
    let gattClientManager = new GattClientManager();
    export default gattClientManager as GattClientManager;
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
    import { ble } from '@kit.ConnectivityKit';
    import { constant } from '@kit.ConnectivityKit';
    import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
    
    const TAG: string = 'GattServerManager';
    
    export class GattServerManager {
      gattServer: ble.GattServer = undefined;
      connectState: ble.ProfileConnectionState = constant.ProfileConnectionState.STATE_DISCONNECTED;
      myServiceUuid: string = '00001810-0000-1000-8000-00805F9B34FB';
      myCharacteristicUuid: string = '00001820-0000-1000-8000-00805F9B34FB';
      myFirstDescriptorUuid: string = '00002902-0000-1000-8000-00805F9B34FB'; // 2902 is generally used for notification or indication.
      mySecondDescriptorUuid: string = '00002903-0000-1000-8000-00805F9B34FB';
    
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
        let descBuffer = new ArrayBuffer(2);
        let descValue = new Uint8Array(descBuffer);
        descValue[0] = 31;
        descValue[1] = 32;
        descriptors[0] = this.initDescriptor(this.myFirstDescriptorUuid, new ArrayBuffer(2));
        descriptors[1] = this.initDescriptor(this.mySecondDescriptorUuid, descBuffer);
        let charBuffer = new ArrayBuffer(2);
        let charValue = new Uint8Array(charBuffer);
        charValue[0] = 21;
        charValue[1] = 22;
        let characteristic: ble.BLECharacteristic = {
          serviceUuid: this.myServiceUuid,
          characteristicUuid: this.myCharacteristicUuid,
          characteristicValue: charBuffer,
          descriptors: descriptors
        };
        return characteristic;
      }
    
      // 1. Subscribe to the connection status change event.
      public onGattServerStateChange() {
        if (!this.gattServer) {
          console.error(TAG, 'no gattServer');
          return;
        }
        try {
          this.gattServer.on('connectionStateChange', (stateInfo: ble.BLEConnectionChangeState) => {
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
          });
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    
      // 2. Register a service with the server.
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
          The this.gattServer = ble.createGattServer(); // 2.1 Create a gattServer instance, which is used in subsequent interactions.
          this.onGattServerStateChange(); // 2.2 Subscribe to the connection status.
          this.gattServer.addService(gattService);
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    
      // 3. Subscribe to the characteristic read requests from the gattClient.
      public onCharacteristicRead() {
        if (!this.gattServer) {
          console.error(TAG, 'no gattServer');
          return;
        }
    
        console.info(TAG, 'onCharacteristicRead');
        try {
          this.gattServer.on('characteristicRead', (charReq: ble.CharacteristicReadRequest) => {
            let deviceId: string = charReq.deviceId;
            let transId: number = charReq.transId;
            let offset: number = charReq.offset;
            console.info(TAG, 'receive characteristicRead');
            let rspBuffer = new ArrayBuffer(2);
            let rspValue = new Uint8Array(rspBuffer);
            rspValue[0] = 21;
            rspValue[1] = 22;
            let serverResponse: ble.ServerResponse = {
              deviceId: deviceId,
              transId: transId,
              status: 0, // The value 0 indicates the operation is successful.
              offset: offset,
              value: rspBuffer
            };
    
            try {
              this.gattServer.sendResponse(serverResponse);
            } catch (err) {
              console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
            }
          });
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    
      // 4. Subscribe to the characteristic write requests from the gattClient.
      public onCharacteristicWrite() {
        if (!this.gattServer) {
          console.error(TAG, 'no gattServer');
          return;
        }
    
        console.info(TAG, 'onCharacteristicWrite');
        try {
          this.gattServer.on('characteristicWrite', (charReq: ble.CharacteristicWriteRequest) => {
            let deviceId: string = charReq.deviceId;
            let transId: number = charReq.transId;
            let offset: number = charReq.offset;
            console.info(TAG, 'receive characteristicWrite: needRsp=' + charReq.needRsp);
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
              this.gattServer.sendResponse(serverResponse);
            } catch (err) {
              console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
            }
          });
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    
      // 5. Subscribe to the descriptor read requests from the gattClient.
      public onDescriptorRead() {
        if (!this.gattServer) {
          console.error(TAG, 'no gattServer');
          return;
        }
    
        console.info(TAG, 'onDescriptorRead');
        try {
          this.gattServer.on('descriptorRead', (desReq: ble.DescriptorReadRequest) => {
            let deviceId: string = desReq.deviceId;
            let transId: number = desReq.transId;
            let offset: number = desReq.offset;
            console.info(TAG, 'receive descriptorRead');
            let rspBuffer = new ArrayBuffer(2);
            let rspValue = new Uint8Array(rspBuffer);
            rspValue[0] = 31;
            rspValue[1] = 32;
            let serverResponse: ble.ServerResponse = {
              deviceId: deviceId,
              transId: transId,
              status: 0, // The value 0 indicates the operation is successful.
              offset: offset,
              value: rspBuffer
            };
    
            try {
              this.gattServer.sendResponse(serverResponse);
            } catch (err) {
              console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
            }
          });
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    
      // 6. Subscribe to the descriptor write requests from the gattClient.
      public onDescriptorWrite() {
        if (!this.gattServer) {
          console.error(TAG, 'no gattServer');
          return;
        }
    
        console.info(TAG, 'onDescriptorWrite');
        try {
          this.gattServer.on('descriptorWrite', (desReq: ble.DescriptorWriteRequest) => {
            let deviceId: string = desReq.deviceId;
            let transId: number = desReq.transId;
            let offset: number = desReq.offset;
            console.info(TAG, 'receive descriptorWrite: needRsp=' + desReq.needRsp);
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
              this.gattServer.sendResponse(serverResponse);
            } catch (err) {
              console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
            }
          });
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    
      // 7. Unregister the service that is not required from the server.
      public unRegisterServer() {
        if (!this.gattServer) {
          console.error(TAG, 'no gattServer');
          return;
        }
    
        console.info(TAG, 'unRegisterServer ' + this.myServiceUuid);
        try {
          this.gattServer.removeService (this.myServiceUuid); // 7.1 Remove the service.
          this.gattServer.off('connectionStateChange', (stateInfo: ble.BLEConnectionChangeState) => { // 7.2 Unsubscribe from the connection state changes.
          });
          this.gattServer.close() // 7.3 Close the gattServer if it is no longer required.
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    }
    
    let gattServerManager = new GattServerManager();
    export default gattServerManager as GattServerManager;
    ```

    For details about the error codes, see [Bluetooth Error Codes](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md).
