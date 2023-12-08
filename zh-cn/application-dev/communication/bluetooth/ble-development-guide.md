# 广播与扫描开发指导

## 简介
BLE是Bluetooth Low Energy的缩写，意为“低功耗蓝牙”。它是一种能够在低功耗情况下进行通信的蓝牙技术。与传统蓝牙相比，BLE的功耗更低，适用于需要长时间运行的低功耗设备，如智能手表、健康监测设备、智能家居等。BLE还具有较高的安全性和较长的通信距离。

## 场景介绍
主要场景有：

- 开启/关闭广播
- 开启/关闭扫描

## 接口说明

完整的 JS API 说明以及实例代码请参考：[BLE 接口](../../reference/apis/js-apis-bluetooth-ble.md)。

具体接口说明如下表。

| 接口名                             | 功能描述                                                                       |
| ---------------------------------- | ------------------------------------------------------------------------------ |
| startBLEScan()                     | 发起BLE扫描流程。                                                               |
| stopBLEScan()                      | 停止BLE扫描流程。                                                                |
| startAdvertising()                 | 开始发送BLE广播。                                                                |
| stopAdvertising()                  | 停止发送BLE广播。                                                                |
| enableAdvertising()                | 临时启动BLE广播。                                                                |
| disableAdvertising()               | 临时关闭BLE广播。                                                                |
| on(type: 'advertisingStateChange') | 订阅BLE广播状态。                                                                |
| off(type: 'advertisingStateChange')| 取消订阅BLE广播状态。                                                            |
| on(type: 'BLEDeviceFind')          | 订阅BLE设备发现上报事件。                                                        |
| off(type: 'BLEDeviceFind')         | 取消订阅BLE设备发现上报事件。                                                     |

## 主要场景开发步骤
说明：
  - 以下场景开发，都需要提前开启蓝牙。

### 开启广播
1. 导入模块: import ble from '@ohos.bluetooth.ble'。
2. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
3. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
4. 参数说明：

| 参数名         | 类型                                    | 必填   | 说明             |
| ----------- | ------------------------------------- | ---- | -------------- |
| setting     | [AdvertiseSetting](#advertisesetting) | 是    | BLE广播的相关设置参数。如果需要使用默认值，请配置为null。    |
| advData     | [AdvertiseData](#advertisedata)       | 是    | BLE广播包内容。      |
| advResponse | [AdvertiseData](#advertisedata)       | 否    | BLE回复扫描请求回复响应。 |
5. 示例代码：
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// 以下为样例数据
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;
let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 5;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;

// 构造接口第一个参数setting
let setting: ble.AdvertiseSetting = {
    interval: 150,
    txPower: 0,
    connectable: true
};
let manufactureDataUnit: ble.ManufactureData = {
    manufactureId: 4567,
    manufactureValue: manufactureValueBuffer.buffer
};
let serviceDataUnit: ble.ServiceData = {
    serviceUuid: "00001888-0000-1000-8000-00805f9b34fb",
    serviceValue: serviceValueBuffer.buffer
};

// 构造接口第二个参数advData
let advData: ble.AdvertiseData = {
    serviceUuids: ["00001888-0000-1000-8000-00805f9b34fb"],
    manufactureData: [manufactureDataUnit],
    serviceData: [serviceDataUnit]
};

// 构造接口第三个参数advResponse
let advResponse: ble.AdvertiseData = {
    serviceUuids: ["00001888-0000-1000-8000-00805f9b34fb"],
    manufactureData: [manufactureDataUnit],
    serviceData: [serviceDataUnit]
};

try {
    // 开启广播
    ble.startAdvertising(setting, advData, advResponse);
    promptAction.showToast({ message: 'startAdvertising success' });
} catch (err) {
    promptAction.showToast({
        message: 'startAdvertising failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
6. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
7. 如何验证：执行该用例代码，提示“startAdvertising success”，并且使用另外一部手机安装nrfConnect软件开启扫描，如果扫描到该广播，广播内容“Manufacturer data的值为:0x01020304，Service Data的值为:0x05060708”，表示开启广播成功。

### 关闭广播
1. 导入模块: import ble from '@ohos.bluetooth.ble'。
2. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
3. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
4. 示例代码：
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

try {
    // 关闭广播
    ble.stopAdvertising();
    promptAction.showToast({ message: 'stopAdvertising success' });
} catch (err) {
    promptAction.showToast({ message: 'stopAdvertising failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message});
}
```
5. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
6. 如何验证：执行该用例代码，弹框提示“stopAdvertising success”，并且使用另外一部手机上的nrfConnect进行扫描，搜索不到“Manufacturer data的值为:0x01020304，Service Data的值为:0x05060708”的广播内容，表示关闭广播成功。

### 开启扫描
1. 导入模块: import ble from '@ohos.bluetooth.ble。
2. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
3. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
4. 参数说明:

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| filters | Array&lt;[ScanFilter](#scanfilter)&gt; | 是    | 表示用于过滤指定设备的过滤器列表，如果不使用过滤的方式，该参数设置为null。 |
| options | [ScanOptions](#scanoptions)            | 否    | 表示扫描的参数配置，可选参数。如果用户没有赋值，则将使用默认值。 |
5. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// 构造过滤器，根据name扫描
let scanFilter: ble.ScanFilter = {
    name: 'Jackistang'
};

// 构造扫描选项
let scanOptions: ble.ScanOptions = {
    interval: 500,
    dutyMode: ble.ScanDuty.SCAN_MODE_LOW_POWER,
    matchMode: ble.MatchMode.MATCH_MODE_AGGRESSIVE
}

try {
    // 开启ble扫描
    ble.startBLEScan([scanFilter], scanOptions);
} catch (err) {
    promptAction.showToast({
        message: 'startBLEScan failed. errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}

// 接收扫描结果
ble.on('BLEDeviceFind', (data) => {
    if (data.length > 0) {
        promptAction.showToast({ message: 'BLE scan result = ' + data[0].deviceName });
    }
});
```
6. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
7. 如何验证：使用另外一部手机安装nrfConnect软件并且配置好广播，设备名称修改为“Jackistang”，开启广播。然后测试手机开启扫描，大概每隔0.5秒弹框“BLE scan result =  = Jackistang”，则表示开启扫描成功。

### 关闭扫描
1. 导入模块: import ble from '@ohos.bluetooth.ble。
2. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
3. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
4. 示例代码:
```
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

try {
    // 关闭ble扫描
    ble.stopBLEScan();
    promptAction.showToast({ message: 'stopBleScan success' });
} catch (err) {
    promptAction.showToast({
        message: 'stopBleScan failed. errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
5. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
6. 如何验证：开启扫描成功后，大概每隔0.5秒会弹框一次扫描结果。执行完该用例后，弹框提示“stopBleScan success”，并且不会再每隔0.5秒弹框提示扫描结果，则表示关闭扫描成功。