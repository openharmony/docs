# 数据传输开发指导

## 简介
GATT是指蓝牙技术中的通用属性（Generic Attribute），它是一种用于在蓝牙低功耗设备之间传输数据的协议。GATT协议定义了一套通用的属性和服务框架，用于描述蓝牙设备之间的通信。通过GATT协议，蓝牙设备可以向其他设备提供服务，也可以从其他设备获取服务。GATT协议是蓝牙低功耗设备之间进行数据传输的核心协议之一。

## 场景介绍

主要场景有：
- 连接server端读取和写入信息。
- server端操作services和通知客户端信息。

## 接口说明

完整的 JS API 说明以及实例代码请参考：[GATT 接口](../../reference/apis/js-apis-bluetooth-ble.md)。

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
4. 获取gattServer的设备名称、services信息、信号强度。
5. 读取gattServer的特征值和描述符。
6. 向gattServer写入特征值和描述符。
7. 断开连接，销毁gattClient实例。
8. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';

// serverDeviceId的值，是开启ble扫描获取gattServer的deviceId的值。
let serverDeviceId = 'xx:xx:xx:xx:xx:xx';

// 创建客户端
let clientDevice = ble.createGattClientDevice(serverDeviceId);

// 连接GattServer服务
clientDevice.connect();

// 订阅连接状态改变事件
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

// 获取gattServer设备名称
clientDevice.getDeviceName((err: BusinessError, data: string) => {
  console.info('getDeviceName success, deviceName = ' + JSON.stringify(data));
})

// 获取server的services信息
clientDevice.getServices((code, gattServices) => {
  let message = '';
  if (code != null) {
    console.info('getServices error, errCode: ' + (code as BusinessError).code + ', errMessage: ' + (code as BusinessError).message);
  } else {
    for (let i = 0; i < gattServices.length; i++) {
      message += 'serviceUuid is ' + gattServices[i].serviceUuid + '\n';
    }
    console.info('getServices success, ' + message);
  }
})

// 读取信号强度
clientDevice.getRssiValue((err, cbRssi) => {
  console.info('return code = ' + JSON.stringify(err) + ', RSSI = ' + JSON.stringify(cbRssi))
});

// 设置最大传输单元，示例为256
clientDevice.setBLEMtuSize(256);

// 读取特征值
// 下面字段的值，是getServices之后，从结果中拿到的
let serviceUuid = 'xxx';
let characteristicUuid = 'xxx';
let descriptorUuid = 'xxx';
let descriptorValue = new Uint8Array('xxx'.length).buffer;
let characteristicValue = new Uint8Array('xxx'.length).buffer;
let descriptors = [];
let descriptor = {
  serviceUuid: serviceUuid,
  characteristicUuid: characteristicUuid,
  descriptorUuid: descriptorUuid,
  descriptorValue: descriptorValue
}
descriptors.push(descriptor);
let bleCharacteristicDataIn = {
  serviceUuid: serviceUuid,
  characteristicUuid: characteristicUuid,
  characteristicValue: characteristicValue,
  descriptors: descriptors
};
clientDevice.readCharacteristicValue(bleCharacteristicDataIn, (err, bleCharacteristicDataOut) => {
  if (err != null) {
    console.info('readCharacteristicValue error, code = ' + err.code)
    return;
  }
  let message = 'characteristic value = ';
  let value = new Uint8Array(bleCharacteristicDataOut.characteristicValue);
  for (let i = 0; i < bleCharacteristicDataOut.characteristicValue.byteLength; i++) {
    message += value[i];
  }
  console.info(message);
});

// 读取描述符
let descriptorIn = {
  serviceUuid: serviceUuid,
  characteristicUuid: characteristicUuid,
  descriptorUuid: descriptorUuid,
  descriptorValue: descriptorValue
};
clientDevice.readDescriptorValue(descriptorIn, (err, descriptorOut) => {
  if (err != null) {
    console.info('readDescriptorValue error, code: ' + err.code.toString())
    return;
  }
  let message = 'descriptor value: ';
  let value = new Uint8Array(descriptorOut.descriptorValue);
  for (let i = 0; i < descriptorOut.descriptorValue.byteLength; i++) {
    message += value[i];
  }
  console.info(message);
});

// 写入特征值
function string2ArrayBuffer(str) {
  let array = new Uint8Array(str.length);
  for (var i = 0; i < str.length; i++) {
    array[i] = str.charCodeAt(i);
  }
  return array.buffer;
}

let bufferCCC = string2ArrayBuffer('V');
let characteristic = {
  serviceUuid: serviceUuid,
  characteristicUuid: characteristicUuid,
  characteristicValue: bufferCCC,
  descriptors: descriptors
};
clientDevice.writeCharacteristicValue(characteristic, ble.GattWriteType.WRITE);

// 写入描述符
let message = '';
if (clientDevice.writeDescriptorValue(descriptor)) {
  message = 'writeDescriptorValue success';
} else {
  message = 'writeDescriptorValue failed';
}
console.info(message);

// 断开连接
clientDevice.disconnect();
console.info('disconnect success')

// 关闭GattClient实例
clientDevice.close();
console.info('close gattClientDevice success');
```
9. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。


### server端操作services和通知客户端信息
1. import需要的ble模块。
2. 创建gattServer实例对象。
3. 添加services信息。
4. 当向gattServer写入特征值通知gattClient。
5. 移除services信息。
6. 注销gattServer实例。
7. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';

// 创建gattServer实例
let gattServerInstance = ble.createGattServer();

// 添加services
function string2ArrayBuffer(str) {
  let array = new Uint8Array(str.length);
  for (var i = 0; i < str.length; i++) {
    array[i] = str.charCodeAt(i);
  }
  return array.buffer;
}

var characteristicsArray = new Array();
var descriptorsArray = new Array();
var characteristics1 = {
  serviceUuid: '0000aaaa-0000-1000-8000-00805f9b34fb',
  characteristicUuid: '00002a10-0000-1000-8000-00805f9b34fb',
  characteristicValue: string2ArrayBuffer('I am charac1'),
  descriptors: descriptorsArray
};
characteristicsArray.push(characteristics1);

var descriptors1 = {
  serviceUuid: '0000aaaa-0000-1000-8000-00805f9b34fb',
  characteristicUuid: '00002a10-0000-1000-8000-00805f9b34fb',
  descriptorUuid: '00002904-0000-1000-8000-00805f9b34fb',
  descriptorValue: string2ArrayBuffer('I am Server Descriptor1')
}
var descriptors2 = {
  serviceUuid: '0000aaaa-0000-1000-8000-00805f9b34fb',
  characteristicUuid: '00002a10-0000-1000-8000-00805f9b34fb',
  descriptorUuid: '00002905-0000-1000-8000-00805f9b34fb',
  descriptorValue: string2ArrayBuffer('I am Server Descriptor2')
}
descriptorsArray.push(descriptors1);
descriptorsArray.push(descriptors2);

var service = {
  serviceUuid: '0000aaaa-0000-1000-8000-00805f9b34fb',
  isPrimary: true,
  characteristics: characteristicsArray
};
gattServerInstance.addService(service);
console.info('addService success');

// 订阅写特征值事件，向gattClient发送response
gattServerInstance.on('characteristicWrite', (characteristicWriteReq) => {
  let deviceId = characteristicWriteReq.deviceId;
  let transId = characteristicWriteReq.transId;
  let offset = characteristicWriteReq.offset;
  let needRsp = characteristicWriteReq.needRsp;
  let arrayBufferCCC = string2ArrayBuffer('characteristicWriteForResponse');
  let serverResponse = {
    deviceId: deviceId,
    transId: transId,
    status: 0,
    offset: offset,
    value: arrayBufferCCC
  };
  // 发送response
  if (needRsp) {
    gattServerInstance.sendResponse(serverResponse);
    console.info('sendResponse success, response data: ' + JSON.stringify(serverResponse));
  }
  // 关闭订阅写特征值事件
  gattServerInstance.off('characteristicWrite');
})

// 订阅写特征值事件，特征值变化，通知gattClient
gattServerInstance.on('characteristicWrite', (characteristicWriteReq) => {
  let characteristicUuid = characteristicWriteReq.characteristicUuid;
  let serviceUuid = characteristicWriteReq.serviceUuid;
  let deviceId = characteristicWriteReq.deviceId;
  let notifyCharacteristic = {
    serviceUuid: serviceUuid,
    characteristicUuid: characteristicUuid,
    characteristicValue: string2ArrayBuffer('Value4notifyCharacteristic'),
    confirm: false
  }
  // 特征值变化时，通知已连接的client设备
  gattServerInstance.notifyCharacteristicChanged(deviceId, notifyCharacteristic);
  console.info('notifyCharacteristicChanged success, deviceId = ' + deviceId);
  // 关闭订阅写特征值事件
  gattServerInstance.off('characteristicWrite');
})

// 移除service
gattServerInstance.removeService('0000aaaa-0000-1000-8000-00805f9b34fb');
console.info('removeService success')

// 注销gattServer实例
gattServerInstance.close();
console.info('close gattServerInstance success');
```
8. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。