# 数据传输开发指导

## 简介
GATT是指蓝牙技术中的通用属性（Generic Attribute），它是一种用于在蓝牙低功耗设备之间传输数据的协议。GATT协议定义了一套通用的属性和服务框架，用于描述蓝牙设备之间的通信。通过GATT协议，蓝牙设备可以向其他设备提供服务，也可以从其他设备获取服务。GATT协议是蓝牙低功耗设备之间进行数据传输的核心协议之一。

## 场景介绍
主要场景有：

- 客户端模块：
  - 连接/断连server。
  - 获取设备名称。
  - 获取服务。
  - 读取/写特征值。
  - 读取/写描述符。
  - 获取信号强度。
  - 设置最大传输单元。
- 服务端模块：
  - server端添加/删除服务。
  - server端特征值发生变化时，主动通知已连接的client设备。
  - server端回复client端的读写请求。

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
说明：
  - gattClient相关场景的实现，都需要提前开启蓝牙，获取gattServer地址(可通过开启ble扫描获取)，创建gattClient，连接gattServer。
  - gattServer相关场景的实现，都需要提前开启蓝牙，创建gattServer实例，添加services。

### 连接Server
1. 导入模块: import ble from '@ohos.bluetooth.ble。
2. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
3. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
4. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// serverDeviceId的值，是开启ble扫描获取gattServer的deviceId的值。
let serverDeviceId = 'xx:xx:xx:xx:xx:xx';
let clientDevice = ble.createGattClientDevice(serverDeviceId);

try {
    // 链接GattServer服务
    clientDevice.connect();
} catch (err) {
    promptAction.showToast({
        message: 'connectGattServer failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}

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
    promptAction.showToast({ message: 'status: ' + bleConnectionStateInfo });
})
```
5. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
6. 如何验证：使用另外一部手机安装nrfConnect软件并且配置好gattServer，设备名称修改为“Jackistang”，开启广播。测试手机成功开启ble扫描，创建gatt客户端，执行用例代码，先弹框提示“CONNECTING”，再弹框“STATE_CONNECTED”，则表示连接gattServer成功。

### 获取设备名
1. 导入模块: import ble from '@ohos.bluetooth.ble。
2. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
3. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
4. 参数说明：

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback\<string\> | 是    | client获取对端server设备名，通过注册回调函数获取。 |
5. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

try {
    // serverDeviceId的值，是开启ble扫描获取gattServer的deviceId的值。
    let serverDeviceId = 'xx:xx:xx:xx:xx:xx';
    let clientDevice = ble.createGattClientDevice(serverDeviceId);

    // 链接GattServer服务
    clientDevice.connect();

    // 获取gattServer设备名称
    clientDevice.getDeviceName((err: BusinessError, data: string) => {
        promptAction.showToast({ message: 'getDeviceName success, deviceName = ' + JSON.stringify(data) });
    })
} catch (err) {
    promptAction.showToast({
        message: 'getDeviceName failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
6. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
7. 如何验证：使用另外一部手机安装nrfConnect软件并且配置好gattServer，设备名称修改为“Jackistang”，开启广播。测试手机开启ble扫描，创建gattClient，连接gattServer。执行用例代码，如果弹框提示“getDeviceName success, deviceName = Jackistang”，则表示获取deviceName成功。

### 发现服务
1. 导入模块: import ble from '@ohos.bluetooth.ble'。
2. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
3. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
4. 参数说明：

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback\<Array\<GattService\>\> | 是    | client进行服务发现，通过注册回调函数获取。 |
5. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// serverDeviceId的值，是开启ble扫描获取gattServer的deviceId的值。
let serverDeviceId = 'xx:xx:xx:xx:xx:xx';
let clientDevice = ble.createGattClientDevice(serverDeviceId);

// 链接GattServer服务
clientDevice.connect();

// 获取Gatt服务信息
let message = '';
try {
    clientDevice.getServices((code, gattServices) => {
        if (code != null) {
            promptAction.showToast({
                message: 'getServices error, errCode: ' + (code as BusinessError).code + ', errMessage: ' + (code as BusinessError).message
            });
        } else {
            for (let i = 0; i < gattServices.length; i++) {
                message += 'serviceUuid is ' + gattServices[i].serviceUuid + '\n';
            }
            promptAction.showToast({ message: 'getServices success, ' + message });
        }
    })
} catch (code) {
    promptAction.showToast({
        message: 'getServices failed, errCode: ' + (code as BusinessError).code + ', errMessage: ' + (code as BusinessError).message
    });
}
```
6. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
7. 如何验证：使用另外一部手机安装nrfConnect软件并且配置好gattServer，设备名称修改为“Jackistang”，开启广播。测试机开启ble扫描，创建gattClient，连接gattServer，执行用例代码，若弹框提示“getServices success, serviceUuid is xxx”，则表示获取services成功。

### 读取特定服务的特征值
1. 获取services。
2. 导入模块: import ble from '@ohos.bluetooth.ble'。
3. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
4. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
5. 参数说明：

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| characteristic | BLECharacteristic | 是    | 待读取的特征值。 |
| callback | AsyncCallback\<BLECharacteristic\> | 是    | client读取特征值，通过注册回调函数获取。 |
6. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// serverDeviceId的值，是开启ble扫描获取gattServer的deviceId的值。
let serverDeviceId = 'xx:xx:xx:xx:xx:xx';
let clientDevice = ble.createGattClientDevice(serverDeviceId);

// 链接GattServer服务
clientDevice.connect();

// 下面字段的值，是getServices之后，从结果中拿到的
let serviceUuid = 'xxx';
let characteristicUuid = 'xxx';
let descriptorUuid = 'xxx';
let descriptorValue = new Uint8Array('xxx'.length).buffer;
let characteristicValue = new Uint8Array('xxx'.length).buffer;

// 组装characteristic参数
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
try {
    // 读取特征值
    clientDevice.readCharacteristicValue(bleCharacteristicDataIn, (err, bleCharacteristicDataOut) => {
        if (err != null) {
            promptAction.showToast({ message: 'readCharacteristicValue error, code = ' + err.code })
            return;
        }
        let message = 'characteristic value = ';
        let value = new Uint8Array(bleCharacteristicDataOut.characteristicValue);
        for (let i = 0; i < bleCharacteristicDataOut.characteristicValue.byteLength; i++) {
            message += value[i];
        }
        promptAction.showToast({ message: message });
    });
} catch (err) {
    promptAction.showToast({
        message: 'readCharacteristicValue failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
7. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
8. 如何验证：使用另外一部手机安装nrfConnect软件并且配置好gattServer，设备名称修改为“Jackistang”，开启广播。测试手机开启ble扫描，创建gattClient，连接gattServer，获取services，执行用例代码，如果弹框提示“characteristic value =  xxx”，则表示读取特征值成功。

### 读取特定的特征值包含的描述符
1. 获取services。
2. 导入模块: import ble from '@ohos.bluetooth.ble'。
3. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
4. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
5. 参数说明：

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| descriptor | BLEDescriptor | 是    | 待读取的描述符。 |
| callback | AsyncCallback\<BLEDescriptor\> | 是    | client读取描述符，通过注册回调函数获取。 |
6. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// serverDeviceId的值，是开启ble扫描获取gattServer的deviceId的值。
let serverDeviceId = 'xx:xx:xx:xx:xx:xx';
let clientDevice = ble.createGattClientDevice(serverDeviceId);

// 链接GattServer服务
clientDevice.connect();

// 下面字段的值，是getServices之后，从结果中拿到的
let serviceUuid = 'xxx';
let characteristicUuid = 'xxx';
let descriptorUuid = 'xxx';
let descriptorValue = new Uint8Array('xxx'.length).buffer;

// 组装参数
let descriptorIn = {
    serviceUuid: serviceUuid,
    characteristicUuid: characteristicUuid,
    descriptorUuid: descriptorUuid,
    descriptorValue: descriptorValue
};
try {
    // 读取描述符
    clientDevice.readDescriptorValue(descriptorIn, (err, descriptorOut) => {
        if (err != null) {
            promptAction.showToast({ message: 'readDescriptorValue error, code: ' + err.code.toString() })
            return;
        }
        let message = 'descriptor value: ';
        let value = new Uint8Array(descriptorOut.descriptorValue);
        for (let i = 0; i < descriptorOut.descriptorValue.byteLength; i++) {
            message += value[i];
        }
        promptAction.showToast({ message: message });
    });
} catch (err) {
    promptAction.showToast({
        message: 'Read descriptorValue failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
7. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
8. 如何验证：使用另外一部手机安装nrfConnect软件并且配置好gattServer，设备名称修改为“Jackistang”，开启广播。测试手机开启ble扫描，创建gattClient，连接gattServer，获取services，执行用例代码，如果弹框提示“descriptor value:  xxx”，则表示读取描述符成功。

### 获取信号强度
1. 导入模块: import ble from '@ohos.bluetooth.ble'。
2. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
3. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
4. 参数说明：

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback\<number\> | 是    | 返回信号强度，单位 dBm，通过注册回调函数获取。 |
5. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// serverDeviceId的值，是开启ble扫描获取gattServer的deviceId的值。
let serverDeviceId = 'xx:xx:xx:xx:xx:xx';
let clientDevice = ble.createGattClientDevice(serverDeviceId);

// 链接GattServer服务
clientDevice.connect();

try {
    // 读取信号强度
    clientDevice.getRssiValue((err, cbRssi) => {
        promptAction.showToast({
            message: 'return code = ' + JSON.stringify(err) + ', RSSI = ' + JSON.stringify(cbRssi)
        })
    });
} catch (err) {
    promptAction.showToast({
        message: 'getRssiValue failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
6. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
7. 如何验证：使用另外一部手机安装nrfConnect软件并且配置好gattServer，设备名称修改为“Jackistang”，开启广播。测试手机开启ble扫描，创建gattClient，连接gattServer，执行用例代码，如果弹框提示“return code = null, RSSI = xxx”，则表示读取信号强度成功。

### 设置最大传输单元
1. 导入模块: import ble from '@ohos.bluetooth.ble'。
2. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
3. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
4. 参数说明：

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| mtu | number | 是    | 设置范围为22~512字节。 |
5. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// serverDeviceId的值，是开启ble扫描获取gattServer的deviceId的值。
let serverDeviceId = 'xx:xx:xx:xx:xx:xx';
let clientDevice = ble.createGattClientDevice(serverDeviceId);

// 链接GattServer服务
clientDevice.connect();

// 设置最大传输单元，示例为256
try {
    clientDevice.setBLEMtuSize(256);
} catch (err) {
    promptAction.showToast({
        message: 'setBLEMtuSize failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}

// 订阅MTU变化事件
clientDevice.on('BLEMtuChange', (data) => {
    promptAction.showToast({ message: 'mtu changed, data = ' + data });
})
```
6. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
7. 如何验证：使用另外一部手机安装nrfConnect软件并且配置好gattServer，设备名称修改为“Jackistang”，开启广播。测试手机开启ble扫描，创建gattClient，连接gattServer，执行用例代码，如果弹框提示“mtu changed, data = xxx”，则表示设置MTU成功。

### 设置特征值变化时对客户端的通知
1. 获取services。
2. 导入模块: import ble from '@ohos.bluetooth.ble'。
3. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
4. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
5. 参数说明：

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| characteristic | BLECharacteristic | 是    | 蓝牙低功耗特征。 |
| enable | boolean | 是    | 启用接收notify，设置为true，否则设置为false。 |
| callback | AsyncCallback<void> | 是    | 回调函数。当发送成功，err为undefined，否则为错误对象。 |
6. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// serverDeviceId的值，是开启ble扫描获取gattServer的deviceId的值。
let serverDeviceId = 'xx:xx:xx:xx:xx:xx';
let clientDevice = ble.createGattClientDevice(serverDeviceId);

// 链接GattServer服务
clientDevice.connect();

// 下面字段的值，是getServices之后，从结果中拿到的
let serviceUuid = 'xxx';
let characteristicUuid = 'xxx';
let descriptorUuid = 'xxx';

// 创建descriptors
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(8);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
let descriptor: ble.BLEDescriptor = {
    serviceUuid: serviceUuid,
    characteristicUuid: characteristicUuid,
    descriptorUuid: descriptorUuid,
    descriptorValue: arrayBuffer
};
descriptors[0] = descriptor;

// 创建characteristic
let arrayBufferC = new ArrayBuffer(8);
let characteristic: ble.BLECharacteristic = {
    serviceUuid: serviceUuid,
    characteristicUuid: characteristicUuid,
    characteristicValue: arrayBufferC,
    descriptors: descriptors
};

// 设置特征值变化的通知
let message = '';
try {
    if (clientDevice.setCharacteristicChangeNotification(characteristic, true)) {
        message = 'setCharacteristicChangeNotification success';
    } else {
        message = 'setCharacteristicChangeNotification failed';
    }
    promptAction.showToast({ message: message });
} catch (err) {
    promptAction.showToast({
        message: 'setCharacteristicChangeNotification failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}

// 订阅特征值变化事件
clientDevice.on('BLECharacteristicChange', (data) => {
    if (data == null) {
        promptAction.showToast({ message: 'BLECharacteristic is null' });
    } else {
        let tempCharacteristicUuid = data.characteristicUuid;
        let tempBleCharacteristicChangeInfo = 'characteristicUuid: ' + tempCharacteristicUuid + 'value: ';
        let value = new Uint8Array(data.characteristicValue);
        for (let i = 0; i < data.characteristicValue.byteLength; i++) {
            tempBleCharacteristicChangeInfo += value[i]
        }
        promptAction.showToast({
            message: 'BLECharacteristicChange, ' + tempBleCharacteristicChangeInfo
        });
    }
})
```
7. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
8. 如何验证：使用另外一部手机安装nrfConnect软件并且配置好gattServer，设备名称修改为“Jackistang”，开启广播。测试手机开启ble扫描，创建gattClient，连接gattServer，获取services，然后在对端手机设置新的特征值并且发送，如果弹框提示“BLECharacteristicChange, characteristicUuid: xxx, value: xxx”，则表示设置特征值变化通知成功。

### 设置特征值变化时对客户端的通知。
1. 获取services。
2. 导入模块: import ble from '@ohos.bluetooth.ble'。
3. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
4. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
5. 参数说明：

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| characteristic | BLECharacteristic | 是    | 蓝牙低功耗特征。 |
| enable | boolean | 是    | 启用接收notify，设置为true，否则设置为false。 |
| callback | AsyncCallback\<void\> | 是    | 回调函数。当发送成功，err为undefined，否则为错误对象。 |
6. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// serverDeviceId的值，是开启ble扫描获取gattServer的deviceId的值。
let serverDeviceId = 'xx:xx:xx:xx:xx:xx';
let clientDevice = ble.createGattClientDevice(serverDeviceId);

// 链接GattServer服务
clientDevice.connect();

// 下面字段的值，是getServices之后，从结果中拿到的
let serviceUuid = 'xxx';
let characteristicUuid = 'xxx';
let descriptorUuid = 'xxx';

// 创建descriptors
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(8);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
let descriptor: ble.BLEDescriptor = {
    serviceUuid: serviceUuid,
    characteristicUuid: characteristicUuid,
    descriptorUuid: descriptorUuid,
    descriptorValue: arrayBuffer
};
descriptors[0] = descriptor;

let arrayBufferC = new ArrayBuffer(8);
let characteristic: ble.BLECharacteristic = {
    serviceUuid: serviceUuid,
    characteristicUuid: characteristicUuid,
    characteristicValue: arrayBufferC,
    descriptors: descriptors
};

// 设置特征值变化的指示
let message = '';
try {
    if (clientDevice.setCharacteristicChangeIndication(characteristic, true)) {
        message = 'setCharacteristicChangeIndication success';
    } else {
        message = 'setCharacteristicChangeIndication failed';
    }
    promptAction.showToast({ message: message });
} catch (err) {
    promptAction.showToast({
        message: 'setCharacteristicChangeIndication failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}

// 订阅特征值变化事件
clientDevice.on('BLECharacteristicChange', (data) => {
    if (data == null) {
        promptAction.showToast({ message: 'BLECharacteristic is null' })
    } else {
        let tempCharacteristicUuid = data.characteristicUuid;
        let tempBleCharacteristicChangeInfo = 'characteristicUuid: ' + tempCharacteristicUuid + 'value: ';
        let value = new Uint8Array(data.characteristicValue);
        for (let i = 0; i < data.characteristicValue.byteLength; i++) {
            tempBleCharacteristicChangeInfo += value[i]
        }
        promptAction.showToast({
            message: 'BLECharacteristicChange, ' + tempBleCharacteristicChangeInfo
        });
    }
})
```
7. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
8. 如何验证：使用另外一部手机安装nrfConnect软件并且配置好gattServer，设备名称修改为“Jackistang”，开启广播。测试手机开启ble扫描，创建gattClient，连接gattServer，获取services，然后在对端手机设置新的特征值并且发送，如果弹框提示“BLECharacteristicChange, characteristicUuid: xxx, value: xxx”，则表示设置特征值变化通知成功。

### 写入特征值
1. 获取services。
2. 导入模块: import ble from '@ohos.bluetooth.ble'。
3. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
4. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
5. 参数说明：

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| characteristic | BLECharacteristic | 是    | 蓝牙设备特征对应的二进制值及其它参数。 |
| writeType | GattWriteType | 是    | 蓝牙设备特征的写入类型。 |
| callback | AsyncCallback\<void\> | 是    | 回调函数。当写入成功，err为undefined，否则为错误对象。 |
6. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// serverDeviceId的值，是开启ble扫描获取gattServer的deviceId的值。
let serverDeviceId = 'xx:xx:xx:xx:xx:xx';
let clientDevice = ble.createGattClientDevice(serverDeviceId);

// 链接GattServer服务
clientDevice.connect();

// 下面字段的值，是getServices之后，从结果中拿到的
let serviceUuid = 'xxx';
let characteristicUuid = 'xxx';
let descriptorUuid = 'xxx';

function string2ArrayBuffer(str) {
    let array = new Uint8Array(str.length);
    for (var i = 0; i < str.length; i++) {
        array[i] = str.charCodeAt(i);
    }
    return array.buffer;
}

// 待写入的描述符值，示例为"PPT"
let descriptors = [];
let descriptor = {
    serviceUuid: serviceUuid,
    characteristicUuid: characteristicUuid,
    descriptorUuid: descriptorUuid,
    descriptorValue: string2ArrayBuffer('PPT')
}
descriptors.push(descriptor);

// 待写入的特征值，示例为"V"
let bufferCCC = string2ArrayBuffer('V');
let characteristic = {
    serviceUuid: serviceUuid,
    characteristicUuid: characteristicUuid,
    characteristicValue: bufferCCC,
    descriptors: descriptors
};

// 写入特征值
try {
    clientDevice.writeCharacteristicValue(characteristic, ble.GattWriteType.WRITE);
    promptAction.showToast({ message: 'writeCharacteristicValue success' });
} catch (err) {
    promptAction.showToast({
        message: 'writeCharacteristicValue failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
7. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
8. 如何验证：使用另外一部手机安装nrfConnect软件并且配置好gattServer，设备名称修改为“Jackistang”，开启广播。测试手机开启ble扫描，创建gattClient，连接gattServer，获取services，执行用例代码，弹框“writeCharacteristicValue success”，并且对端手机特征值变化，则表示写入特征值成功。

### 写入描述符
1. 获取services。
2. 导入模块: import ble from '@ohos.bluetooth.ble'。
3. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
4. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
5. 参数说明：

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| descriptor | BLEDescriptor | 是    | 蓝牙设备描述符的二进制值及其它参数。 |
| callback | AsyncCallback\<void\> | 是    | 回调函数。当写入成功，err为undefined，否则为错误对象。 |
6. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// serverDeviceId的值，是开启ble扫描获取gattServer的deviceId的值。
let serverDeviceId = 'xx:xx:xx:xx:xx:xx';
let clientDevice = ble.createGattClientDevice(serverDeviceId);

// 链接GattServer服务
clientDevice.connect();

// 下面字段的值，是getServices之后，从结果中拿到的
let serviceUuid = 'xxx';
let characteristicUuid = 'xxx';
let descriptorUuid = 'xxx';

function string2ArrayBuffer(str) {
    let array = new Uint8Array(str.length);
    for (var i = 0; i < str.length; i++) {
        array[i] = str.charCodeAt(i);
    }
    return array.buffer;
}

let bufferDesc = string2ArrayBuffer('QQ');
let descriptor = {
    serviceUuid: serviceUuid,
    characteristicUuid: characteristicUuid,
    descriptorUuid: descriptorUuid,
    descriptorValue: bufferDesc
};

// 写入描述符
let message = '';
try {
    if (clientDevice.writeDescriptorValue(descriptor)) {
        message = 'writeDescriptorValue success';
    } else {
        message = 'writeDescriptorValue failed';
    }
    promptAction.showToast({ message: message });
} catch (err) {
    promptAction.showToast({
        message: 'writeDescriptorValue failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
7. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
8. 如何验证：使用另外一部手机安装nrfConnect软件并且配置好gattServer，设备名称修改为“Jackistang”，开启广播。测试手机开启ble扫描，创建gattClient，连接gattServer，获取services，执行用例代码，弹框提示“writeDescriptorValue success”，并且对端手机描述符变化，则表示写入描述符成功。

### 断开和Server的连接
1. 导入模块: import ble from '@ohos.bluetooth.ble'。
2. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
3. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
4. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// serverDeviceId的值，是开启ble扫描获取gattServer的deviceId的值。
let serverDeviceId = 'xx:xx:xx:xx:xx:xx';
let clientDevice = ble.createGattClientDevice(serverDeviceId);

// 链接GattServer服务
clientDevice.connect();

// 断开连接
try {
    clientDevice.disconnect();
    promptAction.showToast({ message: 'disconnect success' })
} catch (err) {
    promptAction.showToast({
        message: 'disconnect failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
5. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
6. 如何验证：使用另外一部手机安装nrfConnect软件并且配置好gattServer，设备名称修改为“Jackistang”，开启广播。测试手机开启ble扫描，创建gattClient，连接gattServer，执行用例代码，弹框提示“disconnect success”，并且对端手机显示disconnected，则表示断开连接成功。

### 注销客户端
1. 导入模块: import ble from '@ohos.bluetooth.ble'。
2. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
3. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
4. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// serverDeviceId的值，是开启ble扫描获取gattServer的deviceId的值。
let serverDeviceId = 'xx:xx:xx:xx:xx:xx';
let clientDevice = ble.createGattClientDevice(serverDeviceId);

// 链接GattServer服务
clientDevice.connect();

// 关闭GattClient实例
try {
    clientDevice.close();
    promptAction.showToast({ message: 'close gattClientDevice success' });
} catch (err) {
    promptAction.showToast({
        message: 'close gattClientDevice failed. errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
5. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
6. 如何验证：使用另外一部手机安装nrfConnect软件并且配置好gattServer，设备名称修改为“Jackistang”，开启广播。测试手机开启ble扫描，创建gattClient，执行用例代码，弹框显示“close gattClientDevice success”，则表示关闭客户端成功。

### 添加Services
1. 导入模块: import ble from '@ohos.bluetooth.ble'。
2. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
3. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
4. 参数说明：

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| service | GattService | 是    | 服务端的service数据。BLE广播的相关参数。 |
5. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

function string2ArrayBuffer(str) {
    let array = new Uint8Array(str.length);
    for (var i = 0; i < str.length; i++) {
        array[i] = str.charCodeAt(i);
    }
    return array.buffer;
}

// 以下serviceUuid, characteristicUuid,descriptorUuid的值为示例数据
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

// 创建gattServer实例
let gattServerInstance = ble.createGattServer();

try {
    // 添加service
    gattServerInstance.addService(service);
    promptAction.showToast({ message: 'addService success' });
} catch (err) {
    promptAction.showToast({
        message: 'addService failed. errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
6. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
7. 如何验证：使用另外一部手机安装nrfConnect软件开启扫描。测试手机创建gattServer，执行用例代码，开启广播，弹框提示“addService success”。并且安装了nrfConnect的手机扫描到了新增的service。则表示添加service成功。

### 发送响应
1. 开启广播。
2. 导入模块: import ble from '@ohos.bluetooth.ble'。
3. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
4. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
5. 参数说明：

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| serverResponse | ServerResponse | 是    | erver端回复的响应数据。 |
6. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// 创建gattServer，并且添加service，开启广播
let gattServerInstance = ble.createGattServer();

function string2ArrayBuffer(str) {
    let array = new Uint8Array(str.length);
    for (var i = 0; i < str.length; i++) {
        array[i] = str.charCodeAt(i);
    }
    return array.buffer;
}

// 订阅写特征值事件
gattServerInstance.on('characteristicWrite', (characteristicWriteReq) => {
    // 组装参数
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
        try {
            gattServerInstance.sendResponse(serverResponse);
            promptAction.showToast({
                message: 'sendResponse success, response data: ' + JSON.stringify(serverResponse)
            });
        } catch (err) {
            promptAction.showToast({
                message: 'sendResponse failed. errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
            });
        }
    }

    // 关闭订阅写特征值事件
    gattServerInstance.off('characteristicWrite');
})
```
7. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
8. 如何验证：使用另外一部手机安装nrfConnect软件开启扫描。测试手机创建gattServer，添加service，开启广播。另外那部手机扫描到了新增的service，写入特征值，弹框提示“sendResponse success, response data = xxx”，则表示sendResponse成功。

### 特征值变化通知客户端
1. 开启广播。
2. 导入模块: import ble from '@ohos.bluetooth.ble'。
3. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
4. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
5. 参数说明：

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| deviceId | string | 是    | 接收通知的client端设备地址，例如“XX:XX:XX:XX:XX:XX”。 |
| notifyCharacteristic | NotifyCharacteristic | 是    | 通知的特征值数据。 |
| callback | AsyncCallback\<void\> | 是    | 回调函数。当通知成功，err为undefined，否则为错误对象。 |
6. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// 创建gattServer，并且添加service，开启广播
let gattServerInstance = ble.createGattServer();

function string2ArrayBuffer(str) {
    let array = new Uint8Array(str.length);
    for (var i = 0; i < str.length; i++) {
        array[i] = str.charCodeAt(i);
    }
    return array.buffer;
}

// 订阅写特征值事件
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
    try {
        gattServerInstance.notifyCharacteristicChanged(deviceId, notifyCharacteristic);
        promptAction.showToast({ message: 'notifyCharacteristicChanged success, deviceId = ' + deviceId });
    } catch (err) {
        promptAction.showToast({
            message: 'notifyCharacteristicChanged failed. errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
        });
    }
    // 关闭订阅写特征值事件
    gattServerInstance.off('characteristicWrite');
})
```
7. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
8. 如何验证：使用另外一部手机安装nrfConnect软件开启扫描。测试手机创建gattServer，添加service，启广播。另外一部手机手机扫描到了新增的service，写入特征值，弹框提示“notifyCharacteristicChanged success, deviceId = xxx”，则表示notifyCharacteristicChanged成功。

### 移除Service
1. 开启广播。
2. 导入模块: import ble from '@ohos.bluetooth.ble'。
3. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
4. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
5. 参数说明：

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| serviceUuid | string | 是    | service的UUID，例如“0000aaaa-0000-1000-8000-00805f9b34fb”。 |
6. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// 创建gattServer，并且添加service，开启广播
let gattServerInstance = ble.createGattServer();

// 这里的uuid是添加service的uuid
let serviceUuid = 'xxx';

// 移除service
try {
    gattServerInstance.removeService('0000aaaa-0000-1000-8000-00805f9b34fb');
    promptAction.showToast({ message: 'removeService success' })
} catch (err) {
    promptAction.showToast({
        message: 'removeService failed. errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
7. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
8. 如何验证：使用另外一部手机安装nrfConnect软件开启扫描。测试手机创建gattServer，然后添加service，开启广播。另外一部手机扫描到了新增的service。执行用例代码弹框“removeService success”，重新扫描广播并且连接，里面没有之前添加的service，则表示删除service成功。

### 注销服务端
1. 导入模块: import ble from '@ohos.bluetooth.ble'。
2. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
3. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
4. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// 创建gattServer
let gattServerInstance = ble.createGattServer();

// 注销gattServer实例
try {
    gattServerInstance.close();
    promptAction.showToast({ message: 'close gattServerInstance success' });
} catch (err) {
    promptAction.showToast({
        message: 'close gattServerInstance failed. errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
5. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
6. 如何验证：使用测试手机创建gattServer，执行用例代码弹框“close gattServerInstance success”，并且添加service，会报操作失败。则表示注销gattServer实例成功。