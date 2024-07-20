# 通用属性协议开发指导

## 简介
通用属性协议是GATT（Generic Attribute）的缩写，它是一种用于在蓝牙低功耗设备之间传输数据的协议，定义了一套通用的属性和服务框架。通过GATT协议，蓝牙设备可以向其他设备提供服务，也可以从其他设备获取服务。

## 场景介绍

主要场景有：
- 连接server端读取和写入信息。
- server端操作services和通知客户端信息。

## 接口说明

完整的 JS API 说明以及实例代码请参考：[GATT 接口](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md)。

具体接口说明如下表。

| 接口名                                      | 功能描述                                                                                               |
| ------------------------------------------ | ------------------------------------------------------------------------------------------------------ |
| connect()                                  | client端发起连接远端蓝牙低功耗设备。                                                                      |
| disconnect()                               | client端断开与远端蓝牙低功耗设备的连接。                                                                  |
| close()                                    | 关闭客户端功能，注销client在协议栈的注册，调用该接口后GattClientDevice实例将不能再使用。|
| getDeviceName()                            | client获取远端蓝牙低功耗设备名。                                                                          |
| getServices()                              | client端获取蓝牙低功耗设备的所有服务，即服务发现 。                                                         |
| readCharacteristicValue()                  | client端读取蓝牙低功耗设备特定服务的特征值。                                                               |
| readDescriptorValue()                      | client端读取蓝牙低功耗设备特定的特征包含的描述符。                                                         |
| writeCharacteristicValue()                 | client端向低功耗蓝牙设备写入特定的特征值。                                                                 |
| writeDescriptorValue()                     | client端向低功耗蓝牙设备特定的描述符写入二进制数据。                                                        |
| getRssiValue()                             | client获取远端蓝牙低功耗设备的信号强度 (Received Signal Strength Indication, RSSI)，调用connect接口连接成功后才能使用。|
| setBLEMtuSize()                            | client协商远端蓝牙低功耗设备的最大传输单元（Maximum Transmission Unit, MTU），调用connect接口连接成功后才能使用。|
| setCharacteristicChangeNotification()      | 向服务端发送设置通知此特征值请求。                                                                          |
| setCharacteristicChangeIndication()        | 向服务端发送设置通知此特征值请求。                                                                          |
| on(type: 'BLECharacteristicChange')        | 订阅蓝牙低功耗设备的特征值变化事件。需要先调用setNotifyCharacteristicChanged接口才能接收server端的通知。        |
| off(type: 'BLECharacteristicChange')       | 取消订阅蓝牙低功耗设备的特征值变化事件。                                                                     |
| on(type: 'BLEConnectionStateChange')       | client端订阅蓝牙低功耗设备的连接状态变化事件。                                                               |
| off(type: 'BLEConnectionStateChange')      | 取消订阅蓝牙低功耗设备的连接状态变化事件。                                                                   |
| on(type: 'BLEMtuChange')                   | client端订阅MTU状态变化事件。                                                                                |
| off(type: 'BLEMtuChange')                  | client端取消订阅MTU状态变化事件。                                                                            |
| addService()                               | server端添加服务。                                                                                           |
| removeService()                            | 删除已添加的服务。                                                                                           |
| close()                                    | 关闭服务端功能，去注销server在协议栈的注册，调用该接口后GattServer实例将不能再使用。                             |   
| notifyCharacteristicChanged()              | server端特征值发生变化时，主动通知已连接的client设备。                                                           |
| sendResponse()                             | server端回复client端的读写请求。                                                                             |
| on(type: 'characteristicRead')             | server端订阅特征值读请求事件。                                                                               |
| off(type: 'characteristicRead')            | server端取消订阅特征值读请求事件。                                                                           |
| on(type: 'characteristicWrite')            | server端订阅特征值写请求事件。                                                                               |
| off(type: 'characteristicWrite')           | server端取消订阅特征值写请求事件。                                                                           |
| on(type: 'descriptorRead')                 | server端订阅描述符读请求事件。                                                                               |
| off(type: 'descriptorRead')                | server端取消订阅描述符读请求事件。                                                                           |
| on(type: 'descriptorWrite')                | server端订阅描述符写请求事件。                                                                               |
| off(type: 'descriptorWrite')               | server端取消订阅描述符写请求事件。                                                                           |
| on(type: 'connectionStateChange')          | server端订阅BLE连接状态变化事件。                                                                            |
| off(type: 'connectionStateChange')         | server端取消订阅BLE连接状态变化事件。                                                                        |
| on(type: 'BLEMtuChange')                   | server端订阅MTU状态变化事件。                                                                                |
| off(type: 'BLEMtuChange')                  | server端取消订阅MTU状态变化事件。                                                                            |

## 主要场景开发步骤

### 连接server端读取和写入信息
1. import需要的ble模块。
2. 创建gattClient实例对象。
3. 连接gattServer。
4. 读取gattServer的特征值和描述符。
5. 向gattServer写入特征值和描述符。
6. 断开连接，销毁gattClient实例。
7. 示例代码:

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
      myFirstDescriptorUuid: string = '00002902-0000-1000-8000-00805F9B34FB'; // 2902一般用于notification或者indication
      mySecondDescriptorUuid: string = '00002903-0000-1000-8000-00805F9B34FB';
      found: boolean = false;

      // 构造BLEDescriptor
      private initDescriptor(des: string, value: ArrayBuffer): ble.BLEDescriptor {
        let descriptor: ble.BLEDescriptor = {
          serviceUuid: this.myServiceUuid,
          characteristicUuid: this.myCharacteristicUuid,
          descriptorUuid: des,
          descriptorValue: value
        };
        return descriptor;
      }

      // 构造BLECharacteristic
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

      // 1. 订阅连接状态变化事件
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

      // 2. client端主动连接时调用
      public startConnect(peerDevice: string) { // 对端设备一般通过ble scan获取到
        if (this.connectState != constant.ProfileConnectionState.STATE_DISCONNECTED) {
          console.error(TAG, 'startConnect failed');
          return;
        }
        console.info(TAG, 'startConnect ' + peerDevice);
        this.device = peerDevice;
        // 2.1 使用device构造gattClient，后续的交互都需要使用该实例
        this.gattClient = ble.createGattClientDevice(peerDevice);
        try {
          this.onGattClientStateChange(); // 2.2 订阅连接状态
          this.gattClient.connect(); // 2.3 发起连接
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }

      // 3. client端连接成功后，需要进行服务发现
      public discoverServices() {
        if (!this.gattClient) {
          console.info(TAG, 'no gattClient');
          return;
        }
        console.info(TAG, 'discoverServices');
        try {
          this.gattClient.getServices().then((result: Array<ble.GattService>) => {
            console.info(TAG, 'getServices success: ' + JSON.stringify(result));
            this.found = this.checkService(result); // 要确保server端的服务内容有业务所需要的服务
          });
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }

      // 4. 在确保拿到了server端的服务结果后，读取server端特定服务的特征值时调用
      public readCharacteristicValue() {
        if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
          console.error(TAG, 'no gattClient or not connected');
          return;
        }
        if (!this.found) { // 要确保server端有对应的characteristic
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

      // 5. 在确保拿到了server端的服务结果后，写入server端特定服务的特征值时调用
      public writeCharacteristicValue() {
        if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
          console.error(TAG, 'no gattClient or not connected');
          return;
        }
        if (!this.found) { // 要确保server端有对应的characteristic
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

      // 6. 在确保拿到了server端的服务结果后，读取server端特定服务的描述符时调用
      public readDescriptorValue() {
        if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
          console.error(TAG, 'no gattClient or not connected');
          return;
        }
        if (!this.found) { // 要确保server端有对应的descriptor
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

      // 7. 在确保拿到了server端的服务结果后，写入server端特定服务的描述符时调用
      public writeDescriptorValue() {
        if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
          console.error(TAG, 'no gattClient or not connected');
          return;
        }
        if (!this.found) { // 要确保server端有对应的descriptor
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

      // 8.client端主动断开时调用
      public stopConnect() {
        if (!this.gattClient || this.connectState != constant.ProfileConnectionState.STATE_CONNECTED) {
          console.error(TAG, 'no gattClient or not connected');
          return;
        }

        console.info(TAG, 'stopConnect ' + this.device);
        try {
          this.gattClient.disconnect(); // 8.1 断开连接
          this.gattClient.off('BLEConnectionStateChange', (stateInfo: ble.BLEConnectionChangeState) => {
          });
          this.gattClient.close() // 8.2 如果不再使用此gattClient，则需要close
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    }

    let gattClientManager = new GattClientManager();
    export default gattClientManager as GattClientManager;
    ```

9. 错误码请参见[蓝牙服务子系统错误码](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md)。


### server端操作services和通知客户端信息
1. import需要的ble模块。
2. 创建gattServer实例对象。
3. 添加services信息。
4. 当向gattServer写入特征值通知gattClient。
5. 移除services信息。
6. 注销gattServer实例。
7. 示例代码:

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
      myFirstDescriptorUuid: string = '00002902-0000-1000-8000-00805F9B34FB'; // 2902一般用于notification或者indication
      mySecondDescriptorUuid: string = '00002903-0000-1000-8000-00805F9B34FB';

      // 构造BLEDescriptor
      private initDescriptor(des: string, value: ArrayBuffer): ble.BLEDescriptor {
        let descriptor: ble.BLEDescriptor = {
          serviceUuid: this.myServiceUuid,
          characteristicUuid: this.myCharacteristicUuid,
          descriptorUuid: des,
          descriptorValue: value
        };
        return descriptor;
      }

      // 构造BLECharacteristic
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

      // 1. 订阅连接状态变化事件
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

      // 2. server端注册服务时调用
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
          this.gattServer = ble.createGattServer(); // 2.1 构造gattServer，后续的交互都需要使用该实例
          this.onGattServerStateChange(); // 2.2 订阅连接状态
          this.gattServer.addService(gattService);
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }

      // 3. 订阅来自gattClient的读取特征值请求时调用
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
              status: 0, // 0表示成功
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

      // 4. 订阅来自gattClient的写入特征值请求时调用
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
              status: 0, // 0表示成功
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

      // 5. 订阅来自gattClient的读取描述符请求时调用
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
              status: 0, // 0表示成功
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

      // 6. 订阅来自gattClient的写入描述符请求时调用
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
              status: 0, // 0表示成功
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

      // 7. server端删除服务，不再使用时调用
      public unRegisterServer() {
        if (!this.gattServer) {
          console.error(TAG, 'no gattServer');
          return;
        }

        console.info(TAG, 'unRegisterServer ' + this.myServiceUuid);
        try {
          this.gattServer.removeService(this.myServiceUuid); // 7.1 删除服务
          this.gattServer.off('connectionStateChange', (stateInfo: ble.BLEConnectionChangeState) => { // 7.2 取消订阅连接状态
          });
          this.gattServer.close() // 7.3 如果不再使用此gattServer，则需要close
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    }

    let gattServerManager = new GattServerManager();
    export default gattServerManager as GattServerManager;
    ```

8. 错误码请参见[蓝牙服务子系统错误码](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md)。