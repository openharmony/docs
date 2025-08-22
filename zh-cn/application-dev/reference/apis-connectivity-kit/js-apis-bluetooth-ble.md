# @ohos.bluetooth.ble (蓝牙ble模块)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

提供了基于低功耗蓝牙（Bluetooth Low Energy）技术的蓝牙能力，支持发起BLE扫描、发送BLE广播报文、以及基于通用属性协议（Generic Attribute Profile，GATT）的连接和传输数据。

> **说明：**
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 接口中涉及的UUID服务，可以通过工具函数[util.generateRandomUUID](../apis-arkts/js-apis-util.md#utilgeneraterandomuuid9)生成。



## 导入模块

```js
import { ble } from '@kit.ConnectivityKit';
```


## ProfileConnectionState<sup>10+</sup>

type ProfileConnectionState = constant.ProfileConnectionState

蓝牙设备的Profile协议连接状态。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| [constant.ProfileConnectionState](js-apis-bluetooth-constant.md#profileconnectionstate) | 蓝牙设备的profile连接状态。 |


## ble.createGattServer

createGattServer(): GattServer

创建[GattServer](#gattserver)实例，表示GATT连接中的server端。
- 通过该实例可以操作server端的行为，如添加服务[addService](#addservice)、通知特征值变化[notifyCharacteristicChanged](#notifycharacteristicchanged)等。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| [GattServer](#gattserver) | 返回一个Gatt服务的实例。 |

**示例：**

```js
let gattServer: ble.GattServer = ble.createGattServer();
console.info('gatt success');
```


## ble.createGattClientDevice

createGattClientDevice(deviceId: string): GattClientDevice

创建[GattClientDevice](#gattclientdevice)实例，表示GATT连接中的client端。
- 通过该实例可以操作client端行为，如调用[connect](#connect)向对端设备发起连接，调用[getServices](#getservices)获取对端设备支持的所有服务能力。
- 创建该实例所需要的设备地址表示server端设备。可以通过[ble.startBLEScan](#blestartblescan)或[BleScanner](#blescanner15)的[startScan](#startscan15)接口获取server端设备地址，且需保证server端设备的BLE广播是可连接的。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                   |
| -------- | ------ | ---- | ------------------------------------ |
| deviceId | string | 是    | 对端设备地址，&nbsp;例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                                    | 说明                                   |
| ------------------------------------- | ------------------------------------ |
| [GattClientDevice](#gattclientdevice) | client端类，使用client端方法之前需要创建该类的实例进行操作。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.getConnectedBLEDevices

getConnectedBLEDevices(): Array&lt;string&gt;

获取和本机设备已连接GATT的BLE设备集合。
- 建议给server端使用，client端使用返回的设备地址集合为空。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| Array&lt;string&gt; | 返回和本机设备已建立GATT连接的BLE设备地址集合。<br>基于信息安全考虑，此处获取的设备地址为虚拟MAC地址。<br>- 若和该设备地址配对成功后，该地址不会变更。<br>- 取消配对该设备或蓝牙关闭后，若重新获取，该虚拟地址会变更。<br>- 若要持久化保存该地址，可使用[access.addPersistentDeviceId](js-apis-bluetooth-access.md#accessaddpersistentdeviceid16)方法 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let result: Array<string> = ble.getConnectedBLEDevices();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.startBLEScan

startBLEScan(filters: Array&lt;ScanFilter&gt;, options?: ScanOptions): void

发起BLE扫描流程。
- 扫描结果会通过[ble.on('BLEDeviceFind')](#bleonbledevicefind)的回调函数获取到。只能扫描BLE设备，调用[ble.stopBLEScan](#blestopblescan)可以停止该方法开启的扫描流程。
- 该接口只支持单路扫描，即应用同时只能调用一次，下一次调用前，需要先调用[ble.stopBLEScan](#blestopblescan)停止上一次的扫描流程。
- 若需要使用多路扫描，可使用[BleScanner](#blescanner15)。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| filters | Array&lt;[ScanFilter](#scanfilter)&gt; | 是    | 表示扫描结果过滤策略集合，符合过滤条件的设备发现会保留。<br>-若该参数设置为null，将扫描所有可发现的周边BLE设备，但是不建议使用此方式，可能扫描到非预期设备，并增加功耗。 |
| options | [ScanOptions](#scanoptions)            | 否    | 表示扫描的参数配置。                     |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: Array<ble.ScanResult>) {
    console.info('BLE scan device find result = '+ JSON.stringify(data));
}
try {
    ble.on("BLEDeviceFind", onReceiveEvent);
    let scanFilter: ble.ScanFilter = {
            deviceId:"XX:XX:XX:XX:XX:XX",
            name:"test",
            serviceUuid:"00001888-0000-1000-8000-00805f9b34fb"
        };
    let scanOptions: ble.ScanOptions = {
    interval: 500,
    dutyMode: ble.ScanDuty.SCAN_MODE_LOW_POWER,
    matchMode: ble.MatchMode.MATCH_MODE_AGGRESSIVE
    }
    ble.startBLEScan([scanFilter],scanOptions);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.stopBLEScan

stopBLEScan(): void

停止BLE扫描流程。
- 停止的BLE扫描由[ble.startBLEScan](#blestartblescan)触发。
- 当应用不再需要扫描BLE设备时，需主动调用该方法停止扫描。
- 调用此接口后将不再收到扫描结果上报，重新开启BLE扫描即可再次扫到BLE设备。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    ble.stopBLEScan();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.startAdvertising

startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void

开始发送BLE广播报文。
- 当应用不再需要发送BLE广播报文时，需主动调用[ble.stopAdvertising](#blestopadvertising)停止发送。
- 同步接口，不要和API version 11的[ble.stopAdvertising](#blestopadvertising11)搭配使用。


**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名         | 类型                                    | 必填   | 说明             |
| ----------- | ------------------------------------- | ---- | -------------- |
| setting     | [AdvertiseSetting](#advertisesetting) | 是    | BLE广播的相关参数。    |
| advData     | [AdvertiseData](#advertisedata)       | 是    | BLE广播报文内容。   |
| advResponse | [AdvertiseData](#advertisedata)       | 否    | BLE扫描回复广播报文。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900010 | The number of advertising resources reaches the upper limit.       |
|2900099 | Operation failed.                        |
|2902054 | The length of the advertising data exceeds the upper limit.        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    ble.startAdvertising(setting, advData ,advResponse);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.stopAdvertising

stopAdvertising(): void

停止发送BLE广播报文。
- 停止的BLE广播是由[ble.startAdvertising](#blestartadvertising)触发的。
- 不可以和API version 11的[ble.startAdvertising](#blestartadvertising11)搭配使用。
- 当应用不再需要发送BLE广播报文时，需主动调用该方法停止发送。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    ble.stopAdvertising();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.startAdvertising<sup>11+</sup>

startAdvertising(advertisingParams: AdvertisingParams, callback: AsyncCallback&lt;number&gt;): void

首次启动发送BLE广播报文。使用Callback异步回调。
- 启动成功后，蓝牙子系统会分配相关资源，并使用Callback异步返回该广播的标识。
- 若携带了发送广播持续时间，则一定时间后，广播会停止发送，但分配的广播资源还存在，可以通过[ble.enableAdvertising](#bleenableadvertising11)重新启动发送该广播。
- 从API version 15开始，应用可多次调用，支持发起多路广播，每一路广播通过不同的ID标识管理。
- 当应用不再需要该广播时，需调用API version 11开始支持的[ble.stopAdvertising](#blestopadvertising11)完全停止该广播，不要与API version 10开始支持的[ble.stopAdvertising](#blestopadvertising)混用。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名               | 类型                                    | 必填  | 说明                             |
| ------------------- | --------------------------------------- | ----- | ------------------------------- |
| advertisingParams   | [AdvertisingParams](#advertisingparams11) | 是    | 启动BLE广播的相关参数。           |
| callback            | AsyncCallback&lt;number&gt;             | 是    | 广播ID标识，通过注册回调函数获取。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | -------------------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                       |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900010 | The number of advertising resources reaches the upper limit.       |
|2900099 | Operation failed.                        |
|2902054 | The length of the advertising data exceeds the upper limit.        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true,
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advertisingParams: ble.AdvertisingParams = {
        advertisingSettings: setting,
        advertisingData: advData,
        advertisingResponse: advResponse,
        duration: 0
    }
    let advHandle = 0xFF;
    ble.startAdvertising(advertisingParams, (err, outAdvHandle) => {
        if (err) {
            return;
        } else {
            advHandle = outAdvHandle;
            console.info("advHandle: " + advHandle);
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.startAdvertising<sup>11+</sup>

startAdvertising(advertisingParams: AdvertisingParams): Promise&lt;number&gt;

首次启动发送BLE广播报文。使用Promise异步回调。
- 启动成功后，蓝牙子系统会分配相关资源，并使用Promise异步返回该广播的标识。
- 若携带了发送广播持续时间，则一定时间后，广播会停止发送，但分配的广播资源还存在，可以通过[ble.enableAdvertising](#bleenableadvertising11)重新启动发送该广播。
- 从API version 15开始，应用可多次调用，支持发起多路广播，每一路广播通过不同的ID标识管理。
- 当应用不再需要该广播时，需调用API version 11开始支持的[ble.stopAdvertising](#blestopadvertising11-1)完全停止该广播，不要与API version 10开始支持的[ble.stopAdvertising](#blestopadvertising)混用。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名               | 类型                                   | 必填  | 说明                    |
| ------------------- | -------------------------------------- | ----- | ----------------------- |
| advertisingParams   | [AdvertisingParams](#advertisingparams11) | 是    | 启动BLE广播的相关参数。  |

**返回值：**

| 类型                       | 说明                            |
| -------------------------- | ------------------------------- |
| Promise&lt;number&gt;      | 广播ID标识，通过promise形式获取。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | -------------------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                       |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900010 | The number of advertising resources reaches the upper limit.       |
|2900099 | Operation failed.                        |
|2902054 | The length of the advertising data exceeds the upper limit.        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advertisingParams: ble.AdvertisingParams = {
        advertisingSettings: setting,
        advertisingData: advData,
        advertisingResponse: advResponse,
        duration: 0
    }
    let advHandle = 0xFF;
    ble.startAdvertising(advertisingParams)
        .then(outAdvHandle => {
            advHandle = outAdvHandle;
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.enableAdvertising<sup>11+</sup>

enableAdvertising(advertisingEnableParams: AdvertisingEnableParams, callback: AsyncCallback&lt;void&gt;): void

重新启动指定标识的BLE广播。使用Callback异步回调。
- [AdvertisingEnableParams](#advertisingenableparams11)中advertisingId对应的广播资源已在[ble.startAdvertising](#blestartadvertising11)首次启动广播时分配。
- 若[ble.startAdvertising](#blestartadvertising11)首次启动广播时指定了广播持续时间，超时后广播自动停止，调用此接口可重新启动同一路BLE广播。
- 通过[ble.disableAdvertising](#bledisableadvertising11)停止的广播，调用此接口可重新启动同一路BLE广播。
- 通过[ble.on('advertisingStateChange')](#bleonadvertisingstatechange11)回调获取重新启动广播结果。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名                    | 类型                                                 | 必填  | 说明                             |
| ------------------------- | --------------------------------------------------- | ----- | ------------------------------- |
| advertisingEnableParams   | [AdvertisingEnableParams](#advertisingenableparams11) | 是    | 临时启动BLE广播的相关参数。        |
| callback                  | AsyncCallback&lt;void&gt;                           | 是    | 回调函数。                        |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                     |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |
|2902055 | Invalid advertising id.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advertisingParams: ble.AdvertisingParams = {
        advertisingSettings: setting,
        advertisingData: advData,
        advertisingResponse: advResponse,
        duration: 300
    }
    let advHandle = 0xFF;
    ble.startAdvertising(advertisingParams, (err, outAdvHandle) => {
        if (err) {
            return;
        } else {
            advHandle = outAdvHandle;
            console.info("advHandle: " + advHandle);
        }
    });

    let advertisingEnableParams: ble.AdvertisingEnableParams = {
        advertisingId: advHandle,
        duration: 0
    }

    // after 3s, advertising disabled, then enable the advertising
    ble.enableAdvertising(advertisingEnableParams, (err) => {
        if (err) {
            return;
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.enableAdvertising<sup>11+</sup>

enableAdvertising(advertisingEnableParams: AdvertisingEnableParams): Promise&lt;void&gt;

重新启动指定标识的BLE广播。使用Promise异步回调。
- [AdvertisingEnableParams](#advertisingenableparams11)中advertisingId对应的广播资源已在[ble.startAdvertising](#blestartadvertising11)首次启动广播时分配。
- 若[ble.startAdvertising](#blestartadvertising11)首次启动广播时指定了广播持续时间，超时后广播自动停止，调用此接口可重新启动同一路BLE广播。
- 通过[ble.disableAdvertising](#bledisableadvertising11)停止的广播，调用此接口可重新启动同一路BLE广播。
- 通过[ble.on('advertisingStateChange')](#bleonadvertisingstatechange11)回调获取启动广播结果。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名                    | 类型                                                 | 必填  | 说明                             |
| ------------------------- | --------------------------------------------------- | ----- | ------------------------------- |
| advertisingEnableParams   | [AdvertisingEnableParams](#advertisingenableparams11) | 是    | 临时启动BLE广播的相关参数。        |

**返回值：**

| 类型                       | 说明          |
| -------------------------- | ------------ |
| Promise&lt;void&gt;      | 回调函数。    |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                   |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |
|2902055 | Invalid advertising id.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advertisingParams: ble.AdvertisingParams = {
        advertisingSettings: setting,
        advertisingData: advData,
        advertisingResponse: advResponse,
        duration: 300
    }
    let advHandle = 0xFF;
    ble.startAdvertising(advertisingParams, (err, outAdvHandle) => {
        if (err) {
            return;
        } else {
            advHandle = outAdvHandle;
            console.info("advHandle: " + advHandle);
        }
    });

    let advertisingEnableParams: ble.AdvertisingEnableParams = {
        advertisingId: advHandle,
        duration: 0
    }

    // after 3s, advertising disabled, then enable the advertising
    ble.enableAdvertising(advertisingEnableParams)
        .then(() => {
            console.info("enable success");
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.disableAdvertising<sup>11+</sup>

disableAdvertising(advertisingDisableParams: AdvertisingDisableParams, callback: AsyncCallback&lt;void&gt;): void

停止指定标识的BLE广播。使用Callback异步回调。
- 停止BLE广播，但不释放已申请的广播资源，调用[ble.enableAdvertising](#bleenableadvertising11)可重新启动此方法停止的广播。
- [AdvertisingDisableParams](#advertisingdisableparams11)中advertisingId对应的广播资源已在[ble.startAdvertising](#blestartadvertising11)首次启动广播时分配。
- 通过[ble.on('advertisingStateChange')](#bleonadvertisingstatechange11)回调获取停止广播结果。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名                    | 类型                                                   | 必填  | 说明                             |
| ------------------------- | ----------------------------------------------------- | ----- | ------------------------------- |
| advertisingDisableParams  | [AdvertisingDisableParams](#advertisingdisableparams11) | 是    | 临时关闭BLE广播的相关参数。        |
| callback                  | AsyncCallback&lt;void&gt;                             | 是    | 回调函数。                        |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                     |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |
|2902055 | Invalid advertising id.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advertisingParams: ble.AdvertisingParams = {
        advertisingSettings: setting,
        advertisingData: advData,
        advertisingResponse: advResponse,
        duration: 0
    }
    let advHandle = 0xFF;
    ble.startAdvertising(advertisingParams, (err, outAdvHandle) => {
        if (err) {
            return;
        } else {
            advHandle = outAdvHandle;
            console.info("advHandle: " + advHandle);
        }
    });

    let advertisingDisableParams: ble.AdvertisingDisableParams = {
        advertisingId: advHandle
    }
    ble.disableAdvertising(advertisingDisableParams, (err) => {
        if (err) {
            return;
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.disableAdvertising<sup>11+</sup>

disableAdvertising(advertisingDisableParams: AdvertisingDisableParams): Promise&lt;void&gt;

停止指定标识的BLE广播。使用Promise异步回调。
- 停止BLE广播，但不释放已申请的广播资源，调用[ble.enableAdvertising](#bleenableadvertising11)可重新启动此方法停止的广播。
- [AdvertisingDisableParams](#advertisingdisableparams11)中advertisingId对应的广播资源已在[ble.startAdvertising](#blestartadvertising11)首次启动广播时分配。
- 通过[ble.on('advertisingStateChange')](#bleonadvertisingstatechange11)回调获取停止广播结果。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名                    | 类型                                                   | 必填  | 说明                             |
| ------------------------- | ----------------------------------------------------- | ----- | ------------------------------- |
| advertisingDisableParams  | [AdvertisingDisableParams](#advertisingdisableparams11) | 是    | 临时关闭BLE广播的相关参数。        |

**返回值：**

| 类型                       | 说明          |
| -------------------------- | ------------ |
| Promise&lt;void&gt;        | 回调函数。    |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                  |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |
|2902055 | Invalid advertising id.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advertisingParams: ble.AdvertisingParams = {
        advertisingSettings: setting,
        advertisingData: advData,
        advertisingResponse: advResponse,
        duration: 0
    }
    let advHandle = 0xFF;
    ble.startAdvertising(advertisingParams, (err, outAdvHandle) => {
        if (err) {
            return;
        } else {
            advHandle = outAdvHandle;
            console.info("advHandle: " + advHandle);
        }
    });

    let advertisingDisableParams: ble.AdvertisingDisableParams = {
        advertisingId: advHandle
    }
    ble.disableAdvertising(advertisingDisableParams)
        .then(() => {
            console.info("enable success");
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## ble.stopAdvertising<sup>11+</sup>

stopAdvertising(advertisingId: number, callback: AsyncCallback&lt;void&gt;): void

完全停止发送BLE广播。使用Callback异步回调。
- 与API version 11开始支持的[ble.startAdvertising](#blestartadvertising11)搭配使用，会释放已经申请的广播资源。
- [ble.startAdvertising](#blestartadvertising11)首次启动广播时分配的广播标识也将失效。
- 不可以和API version 10开始支持的[ble.startAdvertising](#blestartadvertising)接口搭配使用。
- 通过[ble.on('advertisingStateChange')](#bleonadvertisingstatechange11)回调获取完全停止广播结果。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名                    | 类型                          | 必填  | 说明                         |
| ------------------------- | ---------------------------- | ----- | --------------------------- |
| advertisingId             | number                       | 是    | 需要停止的广播ID标识。        |
| callback                  | AsyncCallback&lt;void&gt;    | 是    | 回调函数。                   |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                  |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |
|2902055 | Invalid advertising id.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advertisingParams: ble.AdvertisingParams = {
        advertisingSettings: setting,
        advertisingData: advData,
        advertisingResponse: advResponse,
        duration: 0
    }
    let advHandle = 0xFF;
    ble.startAdvertising(advertisingParams, (err, outAdvHandle) => {
        if (err) {
            return;
        } else {
            advHandle = outAdvHandle;
            console.info("advHandle: " + advHandle);
        }
    });

    ble.stopAdvertising(advHandle, (err) => {
        if (err) {
            return;
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.stopAdvertising<sup>11+</sup>

stopAdvertising(advertisingId: number): Promise&lt;void&gt;

完全停止发送BLE广播。使用Promise异步回调。
- 与API version 11开始支持的[ble.startAdvertising](#blestartadvertising11)搭配使用，会释放已经申请的广播资源。
- [ble.startAdvertising](#blestartadvertising11)首次启动广播时分配的广播标识也将失效。
- 不可以和API version 10开始支持的[ble.startAdvertising](#blestartadvertising)接口搭配使用。
- 通过[ble.on('advertisingStateChange')](#bleonadvertisingstatechange11)回调获取完全停止广播结果。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名                    | 类型                          | 必填  | 说明                         |
| ------------------------- | ---------------------------- | ----- | --------------------------- |
| advertisingId             | number                       | 是    | 需要停止的广播ID标识。        |

**返回值：**

| 类型                       | 说明          |
| -------------------------- | ------------ |
| Promise&lt;void&gt;        | 回调函数。    |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                 |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |
|2902055 | Invalid advertising id.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advertisingParams: ble.AdvertisingParams = {
        advertisingSettings: setting,
        advertisingData: advData,
        advertisingResponse: advResponse,
        duration: 0
    }
    let advHandle = 0xFF;
    ble.startAdvertising(advertisingParams, (err, outAdvHandle) => {
        if (err) {
            return;
        } else {
            advHandle = outAdvHandle;
            console.info("advHandle: " + advHandle);
        }
    });

    ble.stopAdvertising(advHandle)
        .then(() => {
            console.info("enable success");
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.on('advertisingStateChange')<sup>11+</sup>

on(type: 'advertisingStateChange', callback: Callback&lt;AdvertisingStateChangeInfo&gt;): void

订阅BLE广播状态。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                                                    | 必填   | 说明                                                      |
| -------- | ------------------------------------------------------------------------- | ----- | ---------------------------------------------------------- |
| type     | string                                                                    | 是    | 事件回调类型，支持的事件为'advertisingStateChange'，表示广播状态事件。<br>当调用[ble.startAdvertising](#blestartadvertising11)、[ble.stopAdvertising](#blestopadvertising11)、[ble.enableAdvertising](#bleenableadvertising11)、[ble.disableAdvertising](#bledisableadvertising11)，广播状态改变时，均会触发该事件。     |
| callback | Callback&lt;[AdvertisingStateChangeInfo](#advertisingstatechangeinfo11)&gt; | 是    | 指定订阅的回调函数，会携带广播状态信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                       |
|801     | Capability not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: ble.AdvertisingStateChangeInfo) {
    console.info('bluetooth advertising state = ' + JSON.stringify(data));
}
try {
    ble.on('advertisingStateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.off('advertisingStateChange')<sup>11+</sup>

off(type: 'advertisingStateChange', callback?: Callback&lt;AdvertisingStateChangeInfo&gt;): void

取消订阅BLE广播状态。广播停止或启动将不再收到通知。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                                                    | 必填   | 说明                                                      |
| -------- | ------------------------------------------------------------------------- | ----- | ---------------------------------------------------------- |
| type     | string                                                                    | 是    | 事件回调类型，支持的事件为'advertisingStateChange'，表示广播状态事件。        |
| callback | Callback&lt;[AdvertisingStateChangeInfo](#advertisingstatechangeinfo11)&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[ble.on('advertisingStateChange')](#bleonadvertisingstatechange11)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                       |
|801     | Capability not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: ble.AdvertisingStateChangeInfo) {
    console.info('bluetooth advertising state = ' + JSON.stringify(data));
}
try {
    ble.on('advertisingStateChange', onReceiveEvent);
    ble.off('advertisingStateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.on('BLEDeviceFind')

on(type: 'BLEDeviceFind', callback: Callback&lt;Array&lt;ScanResult&gt;&gt;): void

订阅BLE设备扫描结果上报事件。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                  |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'BLEDeviceFind'，表示BLE设备扫描结果上报事件。<br>当调用[ble.startBLEScan](#blestartblescan) 后，开始BLE扫描，若扫描到BLE设备，触发该事件。 |
| callback | Callback&lt;Array&lt;[ScanResult](#scanresult)&gt;&gt; | 是    | 指定订阅的回调函数，会携带扫描结果的集合。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: Array<ble.ScanResult>) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
try {
    ble.on('BLEDeviceFind', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.off('BLEDeviceFind')

off(type: 'BLEDeviceFind', callback?: Callback&lt;Array&lt;ScanResult&gt;&gt;): void

取消订阅BLE设备扫描结果上报事件。
- 若不再需要扫描BLE设备，调用[ble.stopBLEScan](#blestopblescan)方法后，需要调用此方法取消订阅。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'BLEDeviceFind'，表示BLE设备扫描结果上报事件。        |
| callback | Callback&lt;Array&lt;[ScanResult](#scanresult)&gt;&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[ble.on('BLEDeviceFind')](#bleonbledevicefind)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。


| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: Array<ble.ScanResult>) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
try {
    ble.on('BLEDeviceFind', onReceiveEvent);
    ble.off('BLEDeviceFind', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## GattServer

GATT通信中的服务端类。
- 通过[ble.createGattServer](#blecreategattserver)方法可以构造server实例。
- 通过该实例可以操作server端的行为，如添加服务[addService](#addservice)、通知特征值变化[notifyCharacteristicChanged](#notifycharacteristicchanged)等。


### addService

addService(service: GattService): void

server端添加服务。该操作会在蓝牙子系统中注册该服务，表示server端支持的能力。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名     | 类型                          | 必填   | 说明                       |
| ------- | --------------------------- | ---- | ------------------------ |
| service | [GattService](#gattservice) | 是    | server端的service数据。表示支持的特定功能。<br>例如：00001800-0000-1000-8000-00805f9b34fb表示通用访问服务；00001801-0000-1000-8000-00805f9b34fb表示通用属性服务等。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// 创建descriptors。
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(2);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 0; // 以Client Characteristic Configuration描述符为例，表示bit0、bit1均为0，notification和indication均不开启
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;

// 创建characteristics。
let characteristics: Array<ble.BLECharacteristic> = [];
let arrayBufferC = new ArrayBuffer(8);
let cccV = new Uint8Array(arrayBufferC);
cccV[0] = 1;
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
characteristics[0] = characteristic;

// 创建gattService。
let gattService: ble.GattService = {serviceUuid:'00001810-0000-1000-8000-00805F9B34FB', isPrimary: true, characteristics:characteristics, includeServices:[]};

try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.addService(gattService);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### removeService

removeService(serviceUuid: string): void

删除server端已添加的服务。
- 该服务曾通过[addService](#addservice)添加。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名         | 类型     | 必填   | 说明                                       |
| ----------- | ------ | ---- | ---------------------------------------- |
| serviceUuid | string | 是    | 即将删除的服务的UUID。例如：00001810-0000-1000-8000-00805F9B34FB。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let server: ble.GattServer = ble.createGattServer();
try {
    // 调用removeService接口前需要完成server端和client端的配对及连接。
    server.removeService('00001810-0000-1000-8000-00805F9B34FB');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### close

close(): void

销毁server端实例。销毁后，通过[ble.createGattServer](#blecreategattserver)创建的实例将不可用。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let server: ble.GattServer = ble.createGattServer();
try {
    server.close();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### notifyCharacteristicChanged

notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic, callback: AsyncCallback&lt;void&gt;): void

server端发送特征值变化通知或者指示给client端。使用Callback异步回调。

- 建议该特征值的Client Characteristic Configuration描述符（UUID：00002902-0000-1000-8000-00805f9b34fb）notification（通知）或indication（指示）能力已被使能。
- 蓝牙标准协议规定Client Characteristic Configuration描述符的数据内容长度为2字节，bit0和bit1分别表示notification（通知）和indication（指示）能力是否使能，例如bit0 = 1表示notification enabled。
- 该特征值数据内容变化时调用。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名                  | 类型                                       | 必填   | 说明                                      |
| -------------------- | ---------------------------------------- | ---- | --------------------------------------- |
| deviceId             | string                                   | 是    | 接收通知的client设备地址。例如：“XX:XX:XX:XX:XX:XX”。 |
| notifyCharacteristic | [NotifyCharacteristic](#notifycharacteristic) | 是    | 通知给client的特征值数据对象。                               |
| callback | AsyncCallback&lt;void&gt;  | 是    | 回调函数。当通知成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let arrayBufferC = new ArrayBuffer(8);
let notifyCharacter: ble.NotifyCharacteristic = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    characteristicValue: arrayBufferC,
    confirm: true
};
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.notifyCharacteristicChanged('XX:XX:XX:XX:XX:XX', notifyCharacter, (err: BusinessError) => {
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


### notifyCharacteristicChanged

notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): Promise&lt;void&gt;

server端发送特征值变化通知或者指示给对端设备。使用Promise异步回调。

- 建议该特征值的Client Characteristic Configuration描述符notification（通知）或indication（指示）能力已被使能。
- 蓝牙标准协议规定Client Characteristic Configuration描述符的数据内容长度为2字节，bit0和bit1分别表示notification（通知）和indication（指示）能力是否使能，例如bit0 = 1表示notification enabled。
- 该特征值数据内容变化时调用。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名                  | 类型                                       | 必填   | 说明                                      |
| -------------------- | ---------------------------------------- | ---- | --------------------------------------- |
| deviceId             | string                                   | 是    | 接收通知的client设备地址。例如：“XX:XX:XX:XX:XX:XX”。 |
| notifyCharacteristic | [NotifyCharacteristic](#notifycharacteristic) | 是    | 通知给client的特征值数据对象。                               |

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let arrayBufferC = new ArrayBuffer(8);
let notifyCharacter: ble.NotifyCharacteristic = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    characteristicValue: arrayBufferC,
    confirm: true
};
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.notifyCharacteristicChanged('XX:XX:XX:XX:XX:XX', notifyCharacter).then(() => {
        console.info('notifyCharacteristicChanged promise successful');
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### sendResponse

sendResponse(serverResponse: ServerResponse): void

server端收到client的请求操作后，需要调用此接口回复client，否则可能导致链路异常，超时后断连。

client请求是指通过下述接口订阅回调收到的请求消息：

- [on('characteristicRead')](#oncharacteristicread)
- [on('characteristicWrite')](#oncharacteristicwrite)，需根据[CharacteristicWriteRequest](#characteristicwriterequest)中的needRsp决定是否需要回复。
- [on('descriptorRead')](#ondescriptorread)
- [on('descriptorWrite')](#ondescriptorwrite)，需根据[DescriptorWriteRequest](#descriptorwriterequest)中的needRsp决定是否需要回复。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名            | 类型                                | 必填   | 说明              |
| -------------- | --------------------------------- | ---- | --------------- |
| serverResponse | [ServerResponse](#serverresponse) | 是    | server端回复client的响应数据。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
/* send response */
let arrayBufferCCC = new ArrayBuffer(8);
let cccValue = new Uint8Array(arrayBufferCCC);
cccValue[0] = 1;
let serverResponse: ble.ServerResponse = {
    deviceId: 'XX:XX:XX:XX:XX:XX',
    transId: 0,
    status: 0,
    offset: 0,
    value: arrayBufferCCC
};
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.sendResponse(serverResponse);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### on('characteristicRead')

on(type: 'characteristicRead', callback: Callback&lt;CharacteristicReadRequest&gt;): void

server端订阅client的特征值读请求事件，server端收到该事件后需要调用[sendResponse](#sendresponse)接口回复client。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                    |
| -------- | ---------------------------------------- | ---- | ------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'characteristicRead'，表示特征值读请求事件。<br>当收到client端设备的读取特征值请求时，触发该事件。 |
| callback | Callback&lt;[CharacteristicReadRequest](#characteristicreadrequest)&gt; | 是    | 指定订阅的回调函数，会携带client端发送的读请求数据。            |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let arrayBufferCCC = new ArrayBuffer(8);
let cccValue = new Uint8Array(arrayBufferCCC);
cccValue[0] = 1;
let gattServer: ble.GattServer = ble.createGattServer();
function ReadCharacteristicReq(characteristicReadRequest: ble.CharacteristicReadRequest) {
    let deviceId: string = characteristicReadRequest.deviceId;
    let transId: number = characteristicReadRequest.transId;
    let offset: number = characteristicReadRequest.offset;
    let characteristicUuid: string = characteristicReadRequest.characteristicUuid;

    let serverResponse: ble.ServerResponse = {deviceId: deviceId, transId: transId, status: 0, offset: offset, value:arrayBufferCCC};

    try {
        gattServer.sendResponse(serverResponse);
    } catch (err) {
        console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
}
gattServer.on('characteristicRead', ReadCharacteristicReq);
```


### off('characteristicRead')

off(type: 'characteristicRead', callback?: Callback&lt;CharacteristicReadRequest&gt;): void

server端取消订阅client的特征值读请求事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'characteristicRead'，表示特征值读请求事件。    |
| callback | Callback&lt;[CharacteristicReadRequest](#characteristicreadrequest)&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[on('characteristicRead')](#oncharacteristicread)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.off('characteristicRead');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('characteristicWrite')

on(type: 'characteristicWrite', callback: Callback&lt;CharacteristicWriteRequest&gt;): void

server端订阅client的特征值写请求事件，server端收到该事件后需要根据[CharacteristicWriteRequest](#characteristicwriterequest)中的needRsp决定是否调用[sendResponse](#sendresponse)接口回复client。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                     |
| -------- | ---------------------------------------- | ---- | -------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'characteristicWrite'，表示特征值写请求事件。<br>当收到client端设备的写特征值请求时，触发该事件。 |
| callback | Callback&lt;[CharacteristicWriteRequest](#characteristicwriterequest)&gt; | 是    | 指定订阅的回调函数，会携带client端发送的写请求数据。             |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let arrayBufferCCC = new ArrayBuffer(8);
let cccValue = new Uint8Array(arrayBufferCCC);
let gattServer: ble.GattServer = ble.createGattServer();
function WriteCharacteristicReq(characteristicWriteRequest: ble.CharacteristicWriteRequest) {
    let deviceId: string = characteristicWriteRequest.deviceId;
    let transId: number = characteristicWriteRequest.transId;
    let offset: number = characteristicWriteRequest.offset;
    let isPrepared: boolean = characteristicWriteRequest.isPrepared;
    let needRsp: boolean = characteristicWriteRequest.needRsp;
    let value: Uint8Array =  new Uint8Array(characteristicWriteRequest.value);
    let characteristicUuid: string = characteristicWriteRequest.characteristicUuid;

    cccValue[0] = value[0];
    let serverResponse: ble.ServerResponse = {deviceId: deviceId, transId: transId, status: 0, offset: offset, value:arrayBufferCCC};

    try {
        gattServer.sendResponse(serverResponse);
    } catch (err) {
        console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
}
gattServer.on('characteristicWrite', WriteCharacteristicReq);
```


### off('characteristicWrite')

off(type: 'characteristicWrite', callback?: Callback&lt;CharacteristicWriteRequest&gt;): void

server端取消订阅client的特征值写请求事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'characteristicWrite'，表示特征值写请求事件。   |
| callback | Callback&lt;[CharacteristicWriteRequest](#characteristicwriterequest)&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[on('characteristicWrite')](#oncharacteristicwrite)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.off('characteristicWrite');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('descriptorRead')

on(type: 'descriptorRead', callback: Callback&lt;DescriptorReadRequest&gt;): void

server端订阅client的描述符读请求事件，server端收到该事件后需要调用[sendResponse](#sendresponse)接口回复client。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                |
| -------- | ---------------------------------------- | ---- | --------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'descriptorRead'，表示描述符读请求事件。<br>当收到client端设备的读取描述符请求时，触发该事件。 |
| callback | Callback&lt;[DescriptorReadRequest](#descriptorreadrequest)&gt; | 是    | 指定订阅的回调函数，会携带client端发送的读请求数据。        |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let arrayBufferDesc = new ArrayBuffer(8);
let descValue = new Uint8Array(arrayBufferDesc);
descValue[0] = 1;
let gattServer: ble.GattServer = ble.createGattServer();
function ReadDescriptorReq(descriptorReadRequest: ble.DescriptorReadRequest) {
    let deviceId: string = descriptorReadRequest.deviceId;
    let transId: number = descriptorReadRequest.transId;
    let offset: number = descriptorReadRequest.offset;
    let descriptorUuid: string = descriptorReadRequest.descriptorUuid;

    let serverResponse: ble.ServerResponse = {deviceId: deviceId, transId: transId, status: 0, offset: offset, value:arrayBufferDesc};

    try {
        gattServer.sendResponse(serverResponse);
    } catch (err) {
        console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
}
gattServer.on('descriptorRead', ReadDescriptorReq);
```


### off('descriptorRead')

off(type: 'descriptorRead', callback?: Callback&lt;DescriptorReadRequest&gt;): void

server端取消订阅client的描述符读请求事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'descriptorRead'，表示描述符读请求事件。        |
| callback | Callback&lt;[DescriptorReadRequest](#descriptorreadrequest)&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[on('descriptorRead')](#ondescriptorread)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.off('descriptorRead');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('descriptorWrite')

on(type: 'descriptorWrite', callback: Callback&lt;DescriptorWriteRequest&gt;): void

server端订阅client的描述符写请求事件，server端收到该事件后需要根据[DescriptorWriteRequest](#descriptorwriterequest)里的needRsp决定是否调用[sendResponse](#sendresponse)接口回复client。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                 |
| -------- | ---------------------------------------- | ---- | ---------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'descriptorWrite'，表示描述符写请求事件。<br>当收到client端设备的写描述符请求时，触发该事件。 |
| callback | Callback&lt;[DescriptorWriteRequest](#descriptorwriterequest)&gt; | 是    | 指定订阅的回调函数，会携带client端发送的写请求数据。         |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let arrayBufferDesc = new ArrayBuffer(8);
let descValue = new Uint8Array(arrayBufferDesc);
let gattServer: ble.GattServer = ble.createGattServer();
function WriteDescriptorReq(descriptorWriteRequest: ble.DescriptorWriteRequest) {
    let deviceId: string = descriptorWriteRequest.deviceId;
    let transId: number = descriptorWriteRequest.transId;
    let offset: number = descriptorWriteRequest.offset;
    let isPrepared: boolean = descriptorWriteRequest.isPrepared;
    let needRsp: boolean = descriptorWriteRequest.needRsp;
    let value: Uint8Array = new Uint8Array(descriptorWriteRequest.value);
    let descriptorUuid: string = descriptorWriteRequest.descriptorUuid;

    descValue[0] = value[0];
    let serverResponse: ble.ServerResponse = {deviceId: deviceId, transId: transId, status: 0, offset: offset, value:arrayBufferDesc};

    try {
        gattServer.sendResponse(serverResponse);
    } catch (err) {
        console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
}
gattServer.on('descriptorWrite', WriteDescriptorReq);
```


### off('descriptorWrite')

off(type: 'descriptorWrite', callback?: Callback&lt;DescriptorWriteRequest&gt;): void

server端取消订阅client的描述符写请求事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'descriptorWrite'，表示描述符写请求事件。       |
| callback | Callback&lt;[DescriptorWriteRequest](#descriptorwriterequest)&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[on('descriptorWrite')](#ondescriptorwrite)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
let gattServer: ble.GattServer = ble.createGattServer();
gattServer.off('descriptorWrite');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('connectionStateChange')

on(type: 'connectionStateChange', callback: Callback&lt;BLEConnectionChangeState&gt;): void

server端订阅GATT profile协议的连接状态变化事件。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'connectionStateChange'，表示GATT profile连接状态发生变化的事件。<br>当client和server端之间的连接状态发生变化时，触发该事件。<br>例如：收到连接请求或者断连请求时，可能引起连接状态生变化。 |
| callback | Callback&lt;[BLEConnectionChangeState](#bleconnectionchangestate)&gt; | 是    | 指定订阅的回调函数，会携带连接状态。                          |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let Connected = (bleConnectionChangeState: ble.BLEConnectionChangeState) => {
    let deviceId: string = bleConnectionChangeState.deviceId;
    let status: constant.ProfileConnectionState = bleConnectionChangeState.state;
}
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.on('connectionStateChange', Connected);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### off('connectionStateChange')

off(type: 'connectionStateChange', callback?: Callback&lt;BLEConnectionChangeState&gt;): void

server端取消订阅GATT profile协议的连接状态变化事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'connectionStateChange'，表示GATT profile连接状态发生变化的事件。 |
| callback | Callback&lt;[BLEConnectionChangeState](#bleconnectionchangestate)&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[on('connectionStateChange')](#onconnectionstatechange)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.off('connectionStateChange');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('BLEMtuChange')

on(type: 'BLEMtuChange', callback: Callback&lt;number&gt;): void

server端订阅MTU（最大传输单元）大小变更事件。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'BLEMtuChange'，表示MTU状态变化事件。<br>当收到了client端发起了MTU协商请求时，触发该事件。 |
| callback | Callback&lt;number&gt; | 是    | 指定订阅的回调函数，会携带协商后的MTU大小。单位：Byte。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.on('BLEMtuChange', (mtu: number) => {
    console.info('BLEMtuChange, mtu: ' + mtu);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### off('BLEMtuChange')

off(type: 'BLEMtuChange', callback?: Callback&lt;number&gt;): void

server端取消订阅MTU（最大传输单元）大小变更事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为"BLEMtuChange"，表示MTU状态变化事件。 |
| callback | Callback&lt;number&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[on('BLEMtuChange')](#onblemtuchange)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.off('BLEMtuChange');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## GattClientDevice

GATT客户端类，提供了和服务端进行连接和数据传输等操作方法。

- 使用该类的方法前，需通过[createGattClientDevice](#blecreategattclientdevice)方法构造该类的实例。
- 通过创建不同的该类实例，可以管理多路GATT连接。

### connect

connect(): void

client端主动发起和server蓝牙设备的GATT协议连接。

- 远端设备地址已通过[createGattClientDevice](#blecreategattclientdevice)方法中的deviceId参数指定。
- client可通过订阅[on('BLEConnectionStateChange')](#onbleconnectionstatechange)事件来感知连接是否成功。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.connect();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### disconnect

disconnect(): void

client断开与远端蓝牙低功耗设备的连接。

- client可通过订阅[on('BLEConnectionStateChange')](#onbleconnectionstatechange)事件来感知连接是否成功。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.disconnect();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### close

close(): void

销毁client端实例。销毁后，通过[GattClientDevice](#gattclientdevice)创建的实例将不可用。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.close();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getDeviceName

getDeviceName(callback: AsyncCallback&lt;string&gt;): void

client获取server端设备名称。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                          | 必填   | 说明                              |
| -------- | --------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback&lt;string&gt; | 是    | 回调函数。当读取成功，err为undefined，data为server端设备名称。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.          |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**示例：**

```js
import { ble, constant } from '@kit.ConnectivityKit';
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let gattClient: ble.GattClientDevice = ble.createGattClientDevice("11:22:33:44:55:66");
function ConnectStateChanged(state: ble.BLEConnectionChangeState) {
    console.info('bluetooth connect state changed');
    let connectState: ble.ProfileConnectionState = state.state;
    if (connectState == constant.ProfileConnectionState.STATE_CONNECTED) {
        gattClient.getDeviceName((err: BusinessError, data: string)=> {
            console.info('device name err ' + JSON.stringify(err));
            console.info('device name' + JSON.stringify(data));
        })
    }
}
// callback
try {
    gattClient.connect();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getDeviceName

getDeviceName(): Promise&lt;string&gt;

client获取远端蓝牙低功耗设备的名称。使用Promise异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型                    | 说明                                 |
| --------------------- | ---------------------------------- |
| Promise&lt;string&gt; | Promise对象，携带server端设备名称。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.             |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**示例：**

```js
import { ble, constant } from '@kit.ConnectivityKit';
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let gattClient: ble.GattClientDevice = ble.createGattClientDevice("11:22:33:44:55:66");
gattClient.on('BLEConnectionStateChange', ConnectStateChanged);
function ConnectStateChanged(state: ble.BLEConnectionChangeState) {
    console.info('bluetooth connect state changed');
    let connectState: ble.ProfileConnectionState = state.state;
    if (connectState == constant.ProfileConnectionState.STATE_CONNECTED) {
        gattClient.getDeviceName().then((data: string) => {
            console.info('device name' + JSON.stringify(data));
        })
    }
}
// promise
try {
    gattClient.connect();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getServices

getServices(callback: AsyncCallback&lt;Array&lt;GattService&gt;&gt;): void

client获取server端支持的所有服务能力，即服务发现流程。使用Callback异步回调。

应用调用该方法后，才能调用其他读写特征值、描述符等其他方法，且需确保server支持的服务能力中包含需要操作的特征值或描述符。包含接口如下所示：

- [readCharacteristicValue](#readcharacteristicvalue)
- [readDescriptorValue](#readdescriptorvalue)
- [writeCharacteristicValue](#writecharacteristicvalue)
- [writeDescriptorValue](#writedescriptorvalue)
- [setCharacteristicChangeNotification](#setcharacteristicchangenotification)
- [setCharacteristicChangeIndication](#setcharacteristicchangeindication)

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;Array&lt;[GattService](#gattservice)&gt;&gt; | 是    | 回调函数。当读取成功，err为undefined，data为server端的服务列表。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.            |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**示例：**

```js
import { ble, constant } from '@kit.ConnectivityKit';
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// callback 模式。
let getServices = (code: BusinessError, gattServices: Array<ble.GattService>) => {
    if (code && code.code != 0) {
        console.info('bluetooth code is ' + code.code);
        return;
    }
    let services: Array<ble.GattService> = gattServices;
    console.info('bluetooth services size is ', services.length);
    for (let i = 0; i < services.length; i++) {
        console.info('bluetooth serviceUuid is ' + services[i].serviceUuid);
    }
}
let device: ble.GattClientDevice = ble.createGattClientDevice("11:22:33:44:55:66");
function ConnectStateChanged(state: ble.BLEConnectionChangeState) {
    console.info('bluetooth connect state changed');
    let connectState: ble.ProfileConnectionState = state.state;
    if (connectState == constant.ProfileConnectionState.STATE_CONNECTED) {
        device.getServices(getServices);
    }
}

try {
    device.connect();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getServices

getServices(): Promise&lt;Array&lt;GattService&gt;&gt;

client端获取蓝牙低功耗设备的所有服务，即服务发现。使用Promise异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型                                       | 说明                          |
| ---------------------------------------- | --------------------------- |
| Promise&lt;Array&lt;[GattService](#gattservice)&gt;&gt; | Promise对象，返回获取到的server端服务列表。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.          |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**示例：**

```js
import { ble, constant } from '@kit.ConnectivityKit';
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// Promise 模式。
let device: ble.GattClientDevice = ble.createGattClientDevice("11:22:33:44:55:66");
function ConnectStateChanged(state: ble.BLEConnectionChangeState) {
    console.info('bluetooth connect state changed');
    let connectState: ble.ProfileConnectionState = state.state;
    if (connectState == constant.ProfileConnectionState.STATE_CONNECTED) {
        device.getServices().then((result: Array<ble.GattService>) => {
            console.info('getServices successfully:' + JSON.stringify(result));
        });
    }
}
try {
    device.connect();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### readCharacteristicValue

readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback&lt;BLECharacteristic&gt;): void

client端从指定的server端特征值读取数据。使用Callback异步回调。<br>
- 需要先调用[getServices](#getservices)，获取到server端所有支持的能力，且包含指定的入参特征值UUID；否则会读取失败。<br>
- 异步回调结果返回后，才能调用下一次读取或者写入操作，如[readCharacteristicValue](#readcharacteristicvalue)、[readDescriptorValue](#readdescriptorvalue)、[writeCharacteristicValue](#writecharacteristicvalue)、[writeDescriptorValue](#writedescriptorvalue)、[getRssiValue](#getrssivalue)、[setCharacteristicChangeNotification](#setcharacteristicchangenotification)和[setCharacteristicChangeIndication](#setcharacteristicchangeindication)。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名            | 类型                                       | 必填   | 说明                      |
| -------------- | ---------------------------------------- | ---- | ----------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic)  | 是    | 需要读取的特征值。                |
| callback       | AsyncCallback&lt;[BLECharacteristic](#blecharacteristic)&gt; | 是    | 回调函数。当读取成功，err为undefined，data为获取到的特征值对象，包含读取到的数据内容；否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901000 | Read forbidden.                         |
|2901003 | The connection is not established.                |
|2901004 | The connection is congested.                |
|2901005 | The connection is not encrypted.                |
|2901006 | The connection is not authenticated.                |
|2901007 | The connection is not authorized.                |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function readCcc(code: BusinessError, BLECharacteristic: ble.BLECharacteristic) {
  if (code.code != 0) {
      return;
  }
  console.info('bluetooth characteristic uuid: ' + BLECharacteristic.characteristicUuid);
  let value = new Uint8Array(BLECharacteristic.characteristicValue);
  console.info('bluetooth characteristic value: ' + value[0]);
}

let descriptors: Array<ble.BLEDescriptor> = [];
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 0; // 以Client Characteristic Configuration描述符为例，表示bit0、bit1均为0，notification和indication均不开启
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
characteristicValue: bufferCCC, descriptors:descriptors};

try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.readCharacteristicValue(characteristic, readCcc);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### readCharacteristicValue

readCharacteristicValue(characteristic: BLECharacteristic): Promise&lt;BLECharacteristic&gt;

client端从指定的server端特征值读取数据。使用Promise异步回调。<br>
- 需要先调用[getServices](#getservices)，获取到server端所有支持的能力，且包含指定的入参特征值UUID；否则会读取失败。<br>
- 异步回调结果返回后，才能调用下一次读取或者写入操作，如[readCharacteristicValue](#readcharacteristicvalue)、[readDescriptorValue](#readdescriptorvalue)、[writeCharacteristicValue](#writecharacteristicvalue)、[writeDescriptorValue](#writedescriptorvalue)、[getRssiValue](#getrssivalue)、[setCharacteristicChangeNotification](#setcharacteristicchangenotification)和[setCharacteristicChangeIndication](#setcharacteristicchangeindication)。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名            | 类型                                      | 必填   | 说明       |
| -------------- | --------------------------------------- | ---- | -------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | 是    | 需要读取的特征值。 |

**返回值：**

| 类型                                       | 说明                         |
| ---------------------------------------- | -------------------------- |
| Promise&lt;[BLECharacteristic](#blecharacteristic)&gt; | Promise对象，返回获取到的特征值对象，包含读取到的数据内容。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901000 | Read forbidden.                         |
|2901003 | The connection is not established.                |
|2901004 | The connection is congested.                |
|2901005 | The connection is not encrypted.                |
|2901006 | The connection is not authenticated.                |
|2901007 | The connection is not authorized.                |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let descriptors: Array<ble.BLEDescriptor> = [];
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 0; // 以Client Characteristic Configuration描述符为例，表示bit0、bit1均为0，notification和indication均不开启
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
characteristicValue: bufferCCC, descriptors:descriptors};

try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.readCharacteristicValue(characteristic);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### readDescriptorValue

readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback&lt;BLEDescriptor&gt;): void

client端从指定的server端描述符读取数据。使用Callback异步回调。<br>
- 需要先调用[getServices](#getservices)，获取到server端所有支持的能力，且包含指定的入参描述符UUID；否则会读取失败。<br>
- 异步回调结果返回后，才能调用下一次读取或者写入操作，如[readCharacteristicValue](#readcharacteristicvalue)、[readDescriptorValue](#readdescriptorvalue)、[writeCharacteristicValue](#writecharacteristicvalue)、[writeDescriptorValue](#writedescriptorvalue)、[getRssiValue](#getrssivalue)、[setCharacteristicChangeNotification](#setcharacteristicchangenotification)和[setCharacteristicChangeIndication](#setcharacteristicchangeindication)。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名        | 类型                                       | 必填   | 说明                      |
| ---------- | ---------------------------------------- | ---- | ----------------------- |
| descriptor | [BLEDescriptor](#bledescriptor)          | 是    | 需要读取的描述符。                |
| callback   | AsyncCallback&lt;[BLEDescriptor](#bledescriptor)&gt; | 是    | 回调函数。当读取成功，err为undefined，data为获取到的描述符对象，包含读取到的数据内容；否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901000 | Read forbidden.                         |
|2901003 | The connection is not established.                |
|2901004 | The connection is congested.                |
|2901005 | The connection is not encrypted.                |
|2901006 | The connection is not authenticated.                |
|2901007 | The connection is not authorized.                |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function readDesc(code: BusinessError, BLEDescriptor: ble.BLEDescriptor) {
    if (code.code != 0) {
        return;
    }
    console.info('bluetooth descriptor uuid: ' + BLEDescriptor.descriptorUuid);
    let value = new Uint8Array(BLEDescriptor.descriptorValue);
    console.info('bluetooth descriptor value: ' + value[0]);
}

let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 0; // 以Client Characteristic Configuration描述符为例，表示bit0、bit1均为0，notification和indication均不开启
let descriptor: ble.BLEDescriptor = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB',
    descriptorValue: bufferDesc
};
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.readDescriptorValue(descriptor, readDesc);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### readDescriptorValue

readDescriptorValue(descriptor: BLEDescriptor): Promise&lt;BLEDescriptor&gt;

client端从指定的server端描述符读取数据。使用Promise异步回调。<br>
- 需要先调用[getServices](#getservices)，获取到server端所有支持的能力，且包含指定的入参描述符UUID；否则会读取失败。<br>
- 异步回调结果返回后，才能调用下一次读取或者写入操作，如[readCharacteristicValue](#readcharacteristicvalue)、[readDescriptorValue](#readdescriptorvalue)、[writeCharacteristicValue](#writecharacteristicvalue)、[writeDescriptorValue](#writedescriptorvalue)、[getRssiValue](#getrssivalue)、[setCharacteristicChangeNotification](#setcharacteristicchangenotification)和[setCharacteristicChangeIndication](#setcharacteristicchangeindication)。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名        | 类型                              | 必填   | 说明       |
| ---------- | ------------------------------- | ---- | -------- |
| descriptor | [BLEDescriptor](#bledescriptor) | 是    | 需要读取的描述符。 |

**返回值：**

| 类型                                       | 说明                         |
| ---------------------------------------- | -------------------------- |
| Promise&lt;[BLEDescriptor](#bledescriptor)&gt; | Promise对象，返回获取到的描述符对象，包含读取到的数据内容。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.               |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901000 | Read forbidden.                         |
|2901003 | The connection is not established.                |
|2901004 | The connection is congested.                |
|2901005 | The connection is not encrypted.                |
|2901006 | The connection is not authenticated.                |
|2901007 | The connection is not authorized.                |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 0; // 以Client Characteristic Configuration描述符为例，表示bit0、bit1均为0，notification和indication均不开启
let descriptor: ble.BLEDescriptor = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB',
    descriptorValue: bufferDesc
};
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.readDescriptorValue(descriptor);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### writeCharacteristicValue

writeCharacteristicValue(characteristic: BLECharacteristic, writeType: GattWriteType, callback: AsyncCallback&lt;void&gt;): void

client端向指定的server端特征值写入数据。使用Callback异步回调。<br>
- 需要先调用[getServices](#getservices)，获取到server端所有支持的能力，且包含指定的入参特征值UUID；否则会写入失败。<br>
- 异步回调结果返回后，才能调用下一次读取或者写入操作，如[readCharacteristicValue](#readcharacteristicvalue)、[readDescriptorValue](#readdescriptorvalue)、[writeCharacteristicValue](#writecharacteristicvalue)、[writeDescriptorValue](#writedescriptorvalue)、[getRssiValue](#getrssivalue)、[setCharacteristicChangeNotification](#setcharacteristicchangenotification)和[setCharacteristicChangeIndication](#setcharacteristicchangeindication)。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名            | 类型                                      | 必填   | 说明                  |
| -------------- | --------------------------------------- | ---- | ------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | 是    | 需要写入的特征值，包含写入的数据内容。 |
| writeType | [GattWriteType](#gattwritetype) | 是    | 写入特征值的方式。 |
| callback   | AsyncCallback&lt;void&gt; | 是    | 回调函数。当写入成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901001 | Write forbidden.                        |
|2901003 | The connection is not established.                |
|2901004 | The connection is congested.                |
|2901005 | The connection is not encrypted.                |
|2901006 | The connection is not authenticated.                |
|2901007 | The connection is not authorized.                |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let descriptors: Array<ble.BLEDescriptor> = [];
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 0; // 以Client Characteristic Configuration描述符为例，表示bit0、bit1均为0，notification和indication均不开启
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  characteristicValue: bufferCCC, descriptors:descriptors};
function writeCharacteristicValueCallBack(code: BusinessError) {
    if (code != null) {
        return;
    }
    console.info('bluetooth writeCharacteristicValue success');
}
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.writeCharacteristicValue(characteristic, ble.GattWriteType.WRITE, writeCharacteristicValueCallBack);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### writeCharacteristicValue

writeCharacteristicValue(characteristic: BLECharacteristic, writeType: GattWriteType): Promise&lt;void&gt;

client端向指定的server端特征值写入数据。使用Promise异步回调。<br>
- 需要先调用[getServices](#getservices)，获取到server端所有支持的能力，且包含指定的入参特征值UUID；否则会写入失败。<br>
- 异步回调结果返回后，才能调用下一次读取或者写入操作，如[readCharacteristicValue](#readcharacteristicvalue)、[readDescriptorValue](#readdescriptorvalue)、[writeCharacteristicValue](#writecharacteristicvalue)、[writeDescriptorValue](#writedescriptorvalue)、[getRssiValue](#getrssivalue)、[setCharacteristicChangeNotification](#setcharacteristicchangenotification)和[setCharacteristicChangeIndication](#setcharacteristicchangeindication)。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名            | 类型                                      | 必填   | 说明                  |
| -------------- | --------------------------------------- | ---- | ------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | 是    | 需要写入的特征值，包含写入的数据内容。 |
| writeType | [GattWriteType](#gattwritetype) | 是    | 写入特征值的方式。 |

**返回值：**

| 类型                                       | 说明                         |
| ---------------------------------------- | -------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901001 | Write forbidden.                        |
|2901003 | The connection is not established.                |
|2901004 | The connection is congested.                |
|2901005 | The connection is not encrypted.                |
|2901006 | The connection is not authenticated.                |
|2901007 | The connection is not authorized.                |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let descriptors: Array<ble.BLEDescriptor>  = [];
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 0; // 以Client Characteristic Configuration描述符为例，表示bit0、bit1均为0，notification和indication均不开启
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  characteristicValue: bufferCCC, descriptors:descriptors};
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.writeCharacteristicValue(characteristic, ble.GattWriteType.WRITE);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### writeDescriptorValue

writeDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback&lt;void&gt;): void

client端向指定的server端描述符写入数据。使用Callback异步回调。<br>
- 需要先调用[getServices](#getservices)，获取到server端所有支持的能力，且包含指定的入参描述符UUID；否则会写入失败。<br>
- 异步回调结果返回后，才能调用下一次读取或者写入操作，如[readCharacteristicValue](#readcharacteristicvalue)、[readDescriptorValue](#readdescriptorvalue)、[writeCharacteristicValue](#writecharacteristicvalue)、[writeDescriptorValue](#writedescriptorvalue)、[getRssiValue](#getrssivalue)、[setCharacteristicChangeNotification](#setcharacteristicchangenotification)和[setCharacteristicChangeIndication](#setcharacteristicchangeindication)。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名        | 类型                              | 必填   | 说明                 |
| ---------- | ------------------------------- | ---- | ------------------ |
| descriptor | [BLEDescriptor](#bledescriptor) | 是    | 需要写入的描述符，包含写入的数据内容。 |
| callback   | AsyncCallback&lt;void&gt; | 是    | 回调函数。当写入成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901001 | Write forbidden.                        |
|2901003 | The connection is not established.                |
|2901004 | The connection is congested.                |
|2901005 | The connection is not encrypted.                |
|2901006 | The connection is not authenticated.                |
|2901007 | The connection is not authorized.                |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 0; // 以Client Characteristic Configuration描述符为例，表示bit0、bit1均为0，notification和indication均不开启
let descriptor: ble.BLEDescriptor = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB',
    descriptorValue: bufferDesc
};
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.writeDescriptorValue(descriptor, (err: BusinessError) => {
        if (err) {
            console.error('writeDescriptorValue callback failed');
        } else {
            console.info('writeDescriptorValue callback successful');
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### writeDescriptorValue

writeDescriptorValue(descriptor: BLEDescriptor): Promise&lt;void&gt;

client端向指定的server端描述符写入数据。使用Promise异步回调。<br>
- 需要先调用[getServices](#getservices)，获取到server端所有支持的能力，且包含指定的入参描述符UUID；否则会写入失败。<br>
- 异步回调结果返回后，才能调用下一次读取或者写入操作，如[readCharacteristicValue](#readcharacteristicvalue)、[readDescriptorValue](#readdescriptorvalue)、[writeCharacteristicValue](#writecharacteristicvalue)、[writeDescriptorValue](#writedescriptorvalue)、[getRssiValue](#getrssivalue)、[setCharacteristicChangeNotification](#setcharacteristicchangenotification)和[setCharacteristicChangeIndication](#setcharacteristicchangeindication)。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名        | 类型                              | 必填   | 说明                 |
| ---------- | ------------------------------- | ---- | ------------------ |
| descriptor | [BLEDescriptor](#bledescriptor) | 是    | 需要写入的描述符，包含写入的数据内容。 |

**返回值：**

| 类型                                       | 说明                         |
| ---------------------------------------- | -------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901001 | Write forbidden.                        |
|2901003 | The connection is not established.                |
|2901004 | The connection is congested.                |
|2901005 | The connection is not encrypted.                |
|2901006 | The connection is not authenticated.                |
|2901007 | The connection is not authorized.                |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 0; // 以Client Characteristic Configuration描述符为例，表示bit0、bit1均为0，notification和indication均不开启
let descriptor: ble.BLEDescriptor = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB',
    descriptorValue: bufferDesc
};
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.writeDescriptorValue(descriptor).then(() => {
        console.info('writeDescriptorValue promise success');
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getRssiValue

getRssiValue(callback: AsyncCallback&lt;number&gt;): void

client端获取GATT连接链路信号强度 (Received Signal Strength Indication, RSSI)。使用Callback异步回调。<br>
- 需先调用[connect](#connect)方法，等GATT profile连接成功后才能使用。
- 异步回调结果返回后，才能调用下一次读取或者写入操作，如[readCharacteristicValue](#readcharacteristicvalue)、[readDescriptorValue](#readdescriptorvalue)、[writeCharacteristicValue](#writecharacteristicvalue)、[writeDescriptorValue](#writedescriptorvalue)、[getRssiValue](#getrssivalue)、[setCharacteristicChangeNotification](#setcharacteristicchangenotification)和[setCharacteristicChangeIndication](#setcharacteristicchangeindication)。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                          | 必填   | 说明                             |
| -------- | --------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback&lt;number&gt; | 是    | 回调函数。获取链路信号强度成功，err为undefined，data为获取到的信号强度值，单位：dBm；否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.         |
|801 | Capability not supported.          |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901003 | The connection is not established.                |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// callback
try {
    let gattClient: ble.GattClientDevice = ble.createGattClientDevice("XX:XX:XX:XX:XX:XX");
    gattClient.connect();
    let rssi = gattClient.getRssiValue((err: BusinessError, data: number)=> {
        console.info('rssi err ' + JSON.stringify(err));
        console.info('rssi value' + JSON.stringify(data));
    })
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getRssiValue

getRssiValue(): Promise&lt;number&gt;

client端获取GATT连接链路信号强度 (Received Signal Strength Indication, RSSI)。使用Promise异步回调。<br>
- 需先调用[connect](#connect)方法，等GATT profile连接成功后才能使用。
- 异步回调结果返回后，才能调用下一次读取或者写入操作，如[readCharacteristicValue](#readcharacteristicvalue)、[readDescriptorValue](#readdescriptorvalue)、[writeCharacteristicValue](#writecharacteristicvalue)、[writeDescriptorValue](#writedescriptorvalue)、[getRssiValue](#getrssivalue)、[setCharacteristicChangeNotification](#setcharacteristicchangenotification)和[setCharacteristicChangeIndication](#setcharacteristicchangeindication)。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型                    | 说明                                |
| --------------------- | --------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回链路的信号强度，单位：dBm。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.               |
|801 | Capability not supported.          |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901003 | The connection is not established.                |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// promise
try {
    let gattClient: ble.GattClientDevice = ble.createGattClientDevice("XX:XX:XX:XX:XX:XX");
    gattClient.getRssiValue().then((data: number) => {
        console.info('rssi' + JSON.stringify(data));
    })
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### setBLEMtuSize

setBLEMtuSize(mtu: number): void

client端同server端协商MTU（最大传输单元）大小。<br>
- 需先调用[connect](#connect)方法，等GATT profile连接成功后才能使用。<br>
- 通过[on('BLEMtuChange')](#onblemtuchange-1)，订阅MTU协商结果。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名  | 类型     | 必填   | 说明             |
| ---- | ------ | ---- | -------------- |
| mtu  | number | 是    | 需要协商的mtu大小，取值范围：[23, 517]，单位：Byte。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.setBLEMtuSize(128);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### setCharacteristicChangeNotification

setCharacteristicChangeNotification(characteristic: BLECharacteristic, enable: boolean, callback: AsyncCallback&lt;void&gt;): void

client端启用或者禁用接收server端特征值内容变更通知的能力。使用Callback异步回调。<br>
- 需要先调用[getServices](#getservices)，获取到server端所有支持的能力，且需包含指定的入参特征值UUID。<br>
- server端对应的特征值需包含标准协议定义的Client Characteristic Configuration描述符UUID（00002902-0000-1000-8000-00805f9b34fb），server端才能支持发送变更通知。<br>
- 若启用该能力，系统蓝牙服务会自动往server端写Client Characteristic Configuration描述符，启用server端的通知能力。<br>
- 若禁用该能力，系统蓝牙服务会自动往server端写Client Characteristic Configuration描述符，禁用server端的通知能力。<br>
- 通过[on('BLECharacteristicChange')](#onblecharacteristicchange)接收server端特征值内容变更通知。<br>
- 若client端收到server端特征值内容变更通知后，无需回复确认。
- 异步回调结果返回后，才能调用下一次读取或者写入操作，如[readCharacteristicValue](#readcharacteristicvalue)、[readDescriptorValue](#readdescriptorvalue)、[writeCharacteristicValue](#writecharacteristicvalue)、[writeDescriptorValue](#writedescriptorvalue)、[getRssiValue](#getrssivalue)、[setCharacteristicChangeNotification](#setcharacteristicchangenotification)和[setCharacteristicChangeIndication](#setcharacteristicchangeindication)。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名            | 类型                                      | 必填   | 说明                            |
| -------------- | --------------------------------------- | ---- | ----------------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | 是    | 需要管理的server端特征值。                      |
| enable         | boolean                                 | 是    | 是否启用接收server端特征值通知的能力。<br>true表示启用，false表示禁用。 |
| callback   | AsyncCallback&lt;void&gt; | 是    | 回调函数。当调用成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901003 | The connection is not established.                |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// 创建descriptors。
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(2);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 0; // 以Client Characteristic Configuration描述符为例，表示bit0、bit1均为0，notification和indication均不开启
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;
let arrayBufferC = new ArrayBuffer(8);
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.setCharacteristicChangeNotification(characteristic, false, (err: BusinessError) => {
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


### setCharacteristicChangeNotification

setCharacteristicChangeNotification(characteristic: BLECharacteristic, enable: boolean): Promise&lt;void&gt;

client端启用或者禁用接收server端特征值内容变更通知的能力。使用Promise异步回调。<br>
- 需要先调用[getServices](#getservices)，获取到server端所有支持的能力，且需包含指定的入参特征值UUID。<br>
- server端对应的特征值需包含标准协议定义的Client Characteristic Configuration描述符UUID（00002902-0000-1000-8000-00805f9b34fb），server端才能支持发送变更通知。<br>
- 若启用该能力，系统蓝牙服务会自动往server端写Client Characteristic Configuration描述符，启用server端的通知能力。<br>
- 若禁用该能力，系统蓝牙服务会自动往server端写Client Characteristic Configuration描述符，禁用server端的通知能力。<br>
- 通过[on('BLECharacteristicChange')](#onblecharacteristicchange)接收server端特征值内容变更通知。<br>
- 若client端收到server端特征值内容变更通知后，无需回复确认。
- 异步回调结果返回后，才能调用下一次读取或者写入操作，如[readCharacteristicValue](#readcharacteristicvalue)、[readDescriptorValue](#readdescriptorvalue)、[writeCharacteristicValue](#writecharacteristicvalue)、[writeDescriptorValue](#writedescriptorvalue)、[getRssiValue](#getrssivalue)、[setCharacteristicChangeNotification](#setcharacteristicchangenotification)和[setCharacteristicChangeIndication](#setcharacteristicchangeindication)。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名            | 类型                                      | 必填   | 说明                            |
| -------------- | --------------------------------------- | ---- | ----------------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | 是    | 需要管理的server端特征值。                      |
| enable         | boolean                                 | 是    | 是否启用接收server端特征值通知的能力。<br>true表示启用，false表示禁用。 |

**返回值：**

| 类型                                       | 说明                         |
| ---------------------------------------- | -------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901003 | The connection is not established.                |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// 创建descriptors。
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(2);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 0; // 以Client Characteristic Configuration描述符为例，表示bit0、bit1均为0，notification和indication均不开启
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;
let arrayBufferC = new ArrayBuffer(8);
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
try {
  let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
  device.setCharacteristicChangeNotification(characteristic, false);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

```


### setCharacteristicChangeIndication

setCharacteristicChangeIndication(characteristic: BLECharacteristic, enable: boolean, callback: AsyncCallback&lt;void&gt;): void

client端启用或者禁用接收server端特征值内容变更指示的能力。使用Callback异步回调。<br>
- 需要先调用[getServices](#getservices)，获取到server端所有支持的能力，且需包含指定的入参特征值UUID。<br>
- server端对应的特征值需包含标准协议定义的Client Characteristic Configuration描述符UUID（00002902-0000-1000-8000-00805f9b34fb），server端才能支持发送变更指示。<br>
- 若启用该能力，系统蓝牙服务会自动往server端写Client Characteristic Configuration描述符，启用server端的指示能力。<br>
- 若禁用该能力，系统蓝牙服务会自动往server端写Client Characteristic Configuration描述符，禁用server端的指示能力。<br>
- 通过[on('BLECharacteristicChange')](#onblecharacteristicchange)接收server端特征值内容变更指示。<br>
- 若client端收到server端特征值内容变更指示后，系统蓝牙服务会主动回复确认，应用无需关注。
- 异步回调结果返回后，才能调用下一次读取或者写入操作，如[readCharacteristicValue](#readcharacteristicvalue)、[readDescriptorValue](#readdescriptorvalue)、[writeCharacteristicValue](#writecharacteristicvalue)、[writeDescriptorValue](#writedescriptorvalue)、[getRssiValue](#getrssivalue)、[setCharacteristicChangeNotification](#setcharacteristicchangenotification)和[setCharacteristicChangeIndication](#setcharacteristicchangeindication)。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名            | 类型                                      | 必填   | 说明                            |
| -------------- | --------------------------------------- | ---- | ----------------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | 是    | 需要管理的server端特征值。                      |
| enable         | boolean                                 | 是    | 是否启用接收server端特征值指示的能力。<br>true表示启用，false表示禁用。 |
| callback   | AsyncCallback&lt;void&gt; | 是    | 回调函数。当调用成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901003 | The connection is not established.                |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// 创建descriptors。
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(2);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 0; // 以Client Characteristic Configuration描述符为例，表示bit0、bit1均为0，notification和indication均不开启
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;
let arrayBufferC = new ArrayBuffer(8);
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
try {
  let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
  device.setCharacteristicChangeIndication(characteristic, false, (err: BusinessError) => {
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


### setCharacteristicChangeIndication

setCharacteristicChangeIndication(characteristic: BLECharacteristic, enable: boolean): Promise&lt;void&gt;

client端启用或者禁用接收server端特征值内容变更指示的能力。使用Callback异步回调。<br>
- 需要先调用[getServices](#getservices)，获取到server端所有支持的能力，且需包含指定的入参特征值UUID。<br>
- server端对应的特征值需包含标准协议定义的Client Characteristic Configuration描述符UUID（00002902-0000-1000-8000-00805f9b34fb），server端才能支持发送变更指示。<br>
- 若启用该能力，系统蓝牙服务会自动往server端写Client Characteristic Configuration描述符，启用server端的指示能力。<br>
- 若禁用该能力，系统蓝牙服务会自动往server端写Client Characteristic Configuration描述符，禁用server端的指示能力。<br>
- 通过[on('BLECharacteristicChange')](#onblecharacteristicchange)接收server端特征值内容变更指示。<br>
- 若client端收到server端特征值内容变更指示后，系统蓝牙服务会主动回复确认，应用无需关注。
- 异步回调结果返回后，才能调用下一次读取或者写入操作，如[readCharacteristicValue](#readcharacteristicvalue)、[readDescriptorValue](#readdescriptorvalue)、[writeCharacteristicValue](#writecharacteristicvalue)、[writeDescriptorValue](#writedescriptorvalue)、[getRssiValue](#getrssivalue)、[setCharacteristicChangeNotification](#setcharacteristicchangenotification)和[setCharacteristicChangeIndication](#setcharacteristicchangeindication)。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名            | 类型                                      | 必填   | 说明                            |
| -------------- | --------------------------------------- | ---- | ----------------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | 是    | 需要管理的server端特征值。                      |
| enable         | boolean                                 | 是    | 是否启用接收server端特征值指示的能力。<br>true表示启用，false表示禁用。 |

**返回值：**

| 类型                                       | 说明                         |
| ---------------------------------------- | -------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promis对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901003 | The connection is not established.                |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// 创建descriptors。
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(2);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 0; // 以Client Characteristic Configuration描述符为例，表示bit0、bit1均为0，notification和indication均不开启
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;
let arrayBufferC = new ArrayBuffer(8);
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
try {
  let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
  device.setCharacteristicChangeIndication(characteristic, false);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

```


### on('BLECharacteristicChange')

on(type: 'BLECharacteristicChange', callback: Callback&lt;BLECharacteristic&gt;): void

client端订阅server端特征值变化事件。使用Callback异步回调。<br>
-  需调用[setCharacteristicChangeNotification](#setcharacteristicchangenotification)或者[setCharacteristicChangeIndication](#setcharacteristicchangeindication)，且启用通知或者指示能力后，才能接收到server端的特征值内容变更通知或者指示。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'BLECharacteristicChange'，表示server端特征值变化事件。<br>当client端收到server端特征值内容变更的通知或者指示时，触发该事件。 |
| callback | Callback&lt;[BLECharacteristic](#blecharacteristic)&gt; | 是    | 指定订阅的回调函数，会携带server端变化后的特征值内容。                  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function CharacteristicChange(characteristicChangeReq: ble.BLECharacteristic) {
    let serviceUuid: string = characteristicChangeReq.serviceUuid;
    let characteristicUuid: string = characteristicChangeReq.characteristicUuid;
    let value: Uint8Array = new Uint8Array(characteristicChangeReq.characteristicValue);
}
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.on('BLECharacteristicChange', CharacteristicChange);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### off('BLECharacteristicChange')

off(type: 'BLECharacteristicChange', callback?: Callback&lt;BLECharacteristic&gt;): void

client端取消订阅server端特征值变化事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'BLECharacteristicChange'，表示server端特征值变化事件。 |
| callback | Callback&lt;[BLECharacteristic](#blecharacteristic)&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[on('BLECharacteristicChange')](#onblecharacteristicchange)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.off('BLECharacteristicChange');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### on('BLEConnectionStateChange')

on(type: 'BLEConnectionStateChange', callback: Callback&lt;BLEConnectionChangeState&gt;): void

client端订阅GATT profile协议的连接状态变化事件。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'BLEConnectionStateChange'，表示连接状态变化事件。<br>client和server端之间的连接状态发生变化时，触发该事件。<br>当client端调用[connect](#connect)或[disconnect](#disconnect)时，可能引起连接状态生变化。 |
| callback | Callback&lt;[BLEConnectionChangeState](#bleconnectionchangestate)&gt; | 是    | 指定订阅的回调函数，会携带连接状态信息。                           |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function ConnectStateChanged(state: ble.BLEConnectionChangeState) {
    console.info('bluetooth connect state changed');
    let connectState: ble.ProfileConnectionState = state.state;
}
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.on('BLEConnectionStateChange', ConnectStateChanged);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### off('BLEConnectionStateChange')

off(type: 'BLEConnectionStateChange', callback?: Callback&lt;BLEConnectionChangeState&gt;): void

client端取消订阅GATT profile协议的连接状态变化事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'BLEConnectionStateChange'，表示连接状态变化事件。 |
| callback | Callback&lt;[BLEConnectionChangeState](#bleconnectionchangestate)&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[on('BLEConnectionStateChange')](#onbleconnectionstatechange)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.off('BLEConnectionStateChange');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### on('BLEMtuChange')

on(type: 'BLEMtuChange', callback: Callback&lt;number&gt;): void

client端订阅MTU（最大传输单元）大小变更事件。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'BLEMtuChange'，表示MTU大小变更事件。<br>当调用[setBLEMtuSize](#setblemtusize)方法，client端发起MTU大小协商后，会触发该事件。 |
| callback | Callback&lt;number&gt; | 是    | 指定订阅的回调函数，会携带协商后的MTU大小。单位：Byte。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let gattClient: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    gattClient.on('BLEMtuChange', (mtu: number) => {
      console.info('BLEMtuChange, mtu: ' + mtu);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### off('BLEMtuChange')

off(type: 'BLEMtuChange', callback?: Callback&lt;number&gt;): void

client端取消订阅MTU（最大传输单元）大小变更事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'BLEMtuChange'，表示MTU大小变更事件。 |
| callback | Callback&lt;number&gt; | 否    | 指定取消订阅的回调函数通知。若传参，则需与[on('BLEMtuChange')](#onblemtuchange-1)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.off('BLEMtuChange');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## ble.createBleScanner<sup>15+</sup>

createBleScanner(): BleScanner

创建一个[BleScanner](#blescanner15)实例对象，可用于发起或停止BLE扫描等流程。

**原子化服务API**: 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型 | 说明 |
| ------------ | ------------- |
| [BleScanner](#blescanner15) | 返回一个BleScanner的实例。 |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { ble } from '@kit.ConnectivityKit';
let bleScanner: ble.BleScanner = ble.createBleScanner();
console.info('create bleScanner success');
```

## BleScanner<sup>15+</sup>

BLE扫描类，提供了扫描相关的操作方法。<br>
- 使用该类的方法前，需通过[createBleScanner](#blecreateblescanner15)方法构造该类的实例。<br>
- 通过创建不同的该类实例，可以管理多路不同的扫描流程。

### startScan<sup>15+</sup>

startScan(filters: Array&lt;ScanFilter&gt;, options?: ScanOptions): Promise&lt;void&gt;

发起BLE扫描流程。使用Promise异步回调。<br>
- 该接口只能扫描BLE设备。<br>
- 扫描结果会通过[on('BLEDeviceFind')](#onbledevicefind15)的回调函数获取到。<br>
- 调用[stopScan](#stopscan15)可以停止该方法开启的扫描流程。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| filters | Array&lt;[ScanFilter](#scanfilter)&gt; | 是    | 扫描BLE广播的过滤条件集合，符合过滤条件的设备会被上报。<br>-若该参数设置为null，将扫描所有可发现的周边BLE设备，但是不建议使用此方式，可能扫描到非预期设备，并增加功耗。 |
| options | [ScanOptions](#scanoptions)            | 否    | 扫描的配置参数。                     |

**返回值：**

| 类型                                       | 说明                         |
| ---------------------------------------- | -------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promis对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900009 | Fails to start scan as it is out of hardware resources.                 |
|2900099 | Operation failed.                        |
|2902050 | Failed to start scan as Ble scan is already started by the app.|

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { ble } from '@kit.ConnectivityKit';
let bleScanner: ble.BleScanner = ble.createBleScanner();
function onReceiveEvent(scanReport: ble.ScanReport) {
    console.info('BLE scan device find result = '+ JSON.stringify(scanReport));
}
try {
    bleScanner.on("BLEDeviceFind", onReceiveEvent);
    let scanFilter: ble.ScanFilter = {
            deviceId:"XX:XX:XX:XX:XX:XX",
            name:"test",
            serviceUuid:"00001888-0000-1000-8000-00805f9b34fb"
        };
    let scanOptions: ble.ScanOptions = {
        interval: 500,
        dutyMode: ble.ScanDuty.SCAN_MODE_LOW_POWER,
        matchMode: ble.MatchMode.MATCH_MODE_AGGRESSIVE,
        reportMode: ble.ScanReportMode.FENCE_SENSITIVITY_LOW
    }
    bleScanner.startScan([scanFilter],scanOptions);
    console.info('startScan success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### stopScan<sup>15+</sup>

stopScan(): Promise&lt;void&gt;

停止正在进行的BLE扫描。<br>
- 停止的扫描是由[startScan](#startscan15)触发的。<br>
- 当应用不再需要扫描BLE设备时，需主动调用该方法停止扫描。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型                                       | 说明                         |
| ---------------------------------------- | -------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promis对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { ble } from '@kit.ConnectivityKit';
let bleScanner: ble.BleScanner = ble.createBleScanner();
try {
    bleScanner.stopScan();
    console.info('stopScan success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### on('BLEDeviceFind')<sup>15+</sup>

on(type: 'BLEDeviceFind', callback: Callback&lt;ScanReport&gt;): void

订阅BLE设备扫描结果上报事件。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                  |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'BLEDeviceFind'，表示BLE设备扫描结果上报事件。<br>当调用[startScan](#startscan15) 后，开始BLE扫描，若扫描到BLE设备，触发该事件。  |
| callback | Callback&lt;[ScanReport](#scanreport15)&gt; | 是    | 指定订阅的回调函数，会携带扫描结果的集合。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { ble } from '@kit.ConnectivityKit';
function onReceiveEvent(scanReport: ble.ScanReport) {
    console.info('bluetooth device find = '+ JSON.stringify(scanReport));
}
let bleScanner: ble.BleScanner = ble.createBleScanner();
try {
    bleScanner.on('BLEDeviceFind', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### off('BLEDeviceFind')<sup>15+</sup>

off(type: 'BLEDeviceFind', callback?: Callback&lt;ScanReport&gt;): void

取消订阅BLE设备扫描结果上报事件。<br>
- 若不再需要扫描BLE设备，调用[stopScan](#stopscan15)方法后，需要调用此方法取消订阅。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'BLEDeviceFind'，表示BLE设备扫描结果上报事件。        |
| callback | Callback&lt;[ScanReport](#scanreport15)&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[on('BLEDeviceFind')](#onbledevicefind15)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { ble } from '@kit.ConnectivityKit';
function onReceiveEvent(scanReport: ble.ScanReport) {
    console.info('bluetooth device find = '+ JSON.stringify(scanReport));
}
let bleScanner: ble.BleScanner = ble.createBleScanner();
try {
    bleScanner.on('BLEDeviceFind', onReceiveEvent);
    bleScanner.off('BLEDeviceFind', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## GattService

GATT服务结构定义，可包含多个特征值[BLECharacteristic](#blecharacteristic)和依赖的其他服务。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称              | 类型                                     | 只读 | 可选   | 说明                                       |
| --------------- | ---------------------------------------- |---- | ---- | ---------------------------------------- |
| serviceUuid     | string                                   | 否 | 否    | 服务UUID，标识一个GATT服务。例如：00001888-0000-1000-8000-00805f9b34fb。 |
| isPrimary       | boolean                                  | 否 | 否    | 是否是主服务。true表示是主服务，false表示是次要服务。                |
| characteristics | Array&lt;[BLECharacteristic](#blecharacteristic)&gt; | 否 | 否    | 当前服务包含的特征值列表。                             |
| includeServices | Array&lt;[GattService](#gattservice)&gt; | 否 | 是    | 当前服务依赖的其它服务。                             |



## BLECharacteristic

GATT特征值结构定义，是服务[GattService](#gattservice)的核心数据单元。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                  | 类型                                     | 只读 | 可选   | 说明                                 |
| ------------------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| serviceUuid         | string                                   | 否 | 否    | 特征值所属的服务UUID。例如：00001888-0000-1000-8000-00805f9b34fb。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| characteristicUuid  | string                  | 否 | 否    | 特征值UUID。例如：00002a11-0000-1000-8000-00805f9b34fb。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| characteristicValue | ArrayBuffer                              | 否 | 否    | 特征值的数据内容。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                      |
| descriptors         | Array&lt;[BLEDescriptor](#bledescriptor)&gt; | 否 | 否    | 特征值包含的描述符列表。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                |
| properties  | [GattProperties](#gattproperties) | 否 | 是     | 特征值支持的属性。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。     |
| characteristicValueHandle<sup>18+</sup> | number                           | 否    | 是    | 特征值的唯一标识句柄。当server端BLE蓝牙设备提供了多个相同UUID特征值时，可以通过此句柄区分不同的特征值。<br>**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。                      |
| permissions<sup>20+</sup> | [GattPermissions](#gattpermissions20)   | 否    | 是    | 特征值读写操作需要的权限。<br>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。                  |


## BLEDescriptor

GATT描述符结构定义，是特征值[BLECharacteristic](#blecharacteristic)的数据单元，用于描述特征值的附加信息和属性。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                 | 类型        | 只读 | 可选   | 说明                                       |
| ------------------ | ----------- | ---- | ---- | ---------------------------------------- |
| serviceUuid        | string      | 否 | 否    | 特征值所属的服务UUID。例如：00001888-0000-1000-8000-00805f9b34fb。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| characteristicUuid | string      | 否 | 否    | 描述符所属的特征值UUID。例如：00002a11-0000-1000-8000-00805f9b34fb。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| descriptorUuid     | string      | 否 | 否    | 描述符UUID。例如：00002902-0000-1000-8000-00805f9b34fb。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| descriptorValue    | ArrayBuffer | 否 | 否    | 描述符的数据内容。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                              |
| descriptorHandle<sup>18+</sup> | number        | 否    | 是    | 描述符的唯一标识句柄。当server端BLE蓝牙设备提供了多个相同UUID描述符时，可以通过此句柄区分不同的描述符。<br>**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。                      |
| permissions<sup>20+</sup> | [GattPermissions](#gattpermissions20)       | 否    | 是    | 描述符读写操作需要的权限。<br>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。                  |


## NotifyCharacteristic

描述server端特征值发生变化时，server端发送特征值通知的参数结构。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                  | 类型        | 只读 | 可选   | 说明                                       |
| ------------------- | ----------- | ---- | ---- | ---------------------------------------- |
| serviceUuid         | string      | 否 | 否    | 特征值所属的服务UUID。例如：00001888-0000-1000-8000-00805f9b34fb。 |
| characteristicUuid  | string      | 否 | 否    | 内容发生变化的特征值UUID。例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| characteristicValue | ArrayBuffer | 否 | 否    | 特征值对应的数据内容。                               |
| confirm             | boolean     | 否 | 否    | true表示发送的是指示，需要client端回复确认。false表示发送的是通知，不需要client端回复确认。 |


## CharacteristicReadRequest

描述server端订阅client端读特征值请求事件后，接收到的事件参数结构。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                 | 类型   | 只读 | 可选   | 说明                                       |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | 否 | 否    | client端蓝牙设备地址。例如："XX:XX:XX:XX:XX:XX"。 |
| transId            | number | 否 | 否    | client端读请求的标识符，server端回复时需填写相同的transId。       |
| offset             | number | 否 | 否    | client端读数据的偏移值。例如：k表示从第k个字节开始读。<br>server端回复响应时需填写相同的offset。 |
| characteristicUuid | string | 否 | 否    | client端需要读取的特征值UUID。例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| serviceUuid        | string | 否 | 否    | 特征值所属的服务UUID。例如：00001888-0000-1000-8000-00805f9b34fb。 |


## CharacteristicWriteRequest

描述server端订阅client端写特征值请求事件后，接收到的事件参数结构。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                 | 类型   | 只读 | 可选   | 说明                                       |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | 否 | 否    | client端蓝牙设备地址。例如："XX:XX:XX:XX:XX:XX"。 |
| transId            | number | 否 | 否    | client端写请求的标识符，server端回复时需填写相同的transId。       |
| offset             | number | 否 | 否    | client端写数据的偏移值。例如：k表示从第k个字节开始写。<br>server端回复时需填写相同的offset。 |
| isPrepared             | boolean | 否 | 否    | 收到client端写请求后，是否立即回复。<br>true表示稍后回复，false表示立即回复。 |
| needRsp             | boolean | 否 | 否    | 是否需要回复client端。<br>true表示需要回复，false表示不需要回复。 |
| value             | ArrayBuffer | 否 | 否    | client端需要给特征值写入的数据。 |
| characteristicUuid | string | 否 | 否    | client端需要写入的特征值UUID。例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| serviceUuid        | string | 否 | 否    | 特征值所属的服务UUID。例如：00001888-0000-1000-8000-00805f9b34fb。 |


## DescriptorReadRequest

描述server端订阅client端读描述符请求事件后，接收到的事件参数结构。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                 | 类型   | 只读 | 可选   | 说明                                       |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | 否 | 否    | client端蓝牙设备地址。例如："XX:XX:XX:XX:XX:XX"。 |
| transId            | number | 否 | 否    | client端读请求的标识符，server端回复时需填写相同的transId。       |
| offset             | number | 否 | 否    | client端读数据的偏移值。例如：k表示从第k个字节开始读。<br>server端回复响应时需填写相同的offset。 |
| descriptorUuid     | string | 否 | 否    | client端需要读取的描述符UUID。例如：00002902-0000-1000-8000-00805f9b34fb。 |
| characteristicUuid | string | 否 | 否    | 描述符所属的特征值UUID。例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| serviceUuid        | string | 否 | 否    | 特征值所属的服务UUID。例如：00001888-0000-1000-8000-00805f9b34fb。 |


## DescriptorWriteRequest

描述server端订阅client端写描述符请求事件后，接收到的事件参数结构。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                 | 类型        | 只读 | 可选   | 说明                                       |
| ------------------ | ----------- | ---- | ---- | ---------------------------------------- |
| deviceId           | string      | 否 | 否    | client端蓝牙设备地址。例如："XX:XX:XX:XX:XX:XX"。 |
| transId            | number      | 否 | 否    | client端写请求的标识符，server端回复时需填写相同的transId。       |
| offset             | number      | 否 | 否    | client端写数据的偏移值。例如：k表示从第k个字节开始写。<br>server端回复时需填写相同的offset。 |
| isPrepared         | boolean     | 否 | 否    | 收到client端写请求后，是否立即回复。<br>true表示稍后回复，false表示立即回复。                             |
| needRsp            | boolean     | 否 | 否    | 是否需要回复client端。<br>true表示需要回复，false表示不需要回复。                       |
| value              | ArrayBuffer | 否 | 否    | client端需要给描述符写入的数据。                           |
| descriptorUuid     | string      | 否 | 否    | client端需要写入的描述符UUID。例如：00002902-0000-1000-8000-00805f9b34fb。 |
| characteristicUuid | string      | 否 | 否    | 描述符所属的特征值UUID。例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| serviceUuid        | string      | 否 | 否    | 特征值所属的服务UUID。例如：00001888-0000-1000-8000-00805f9b34fb。 |


## ServerResponse

描述server端回复client端读或者写请求的响应参数结构。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称       | 类型        | 只读 | 可选   | 说明                                     |
| -------- | ----------- | ---- |  ---- | -------------------------------------- |
| deviceId | string      | 否 | 否    | client端蓝牙设备地址。例如："XX:XX:XX:XX:XX:XX"。       |
| transId  | number      | 否 | 否    | 收到client端请求的标识符，与订阅client端读或者写请求事件携带的transId保持一致。        |
| status   | number      | 否 | 否    | 响应的状态，设置为0即可，表示正常。                   |
| offset   | number      | 否 | 否    | client端读或者写请求的数据偏移值，与订阅client端读或者写请求事件携带的offset保持一致。 |
| value    | ArrayBuffer | 否 | 否    | 回复的数据。                          |


## BLEConnectionChangeState

描述GATT profile协议连接状态。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称     | 类型                                          | 只读 | 可选 | 说明                                          |
| -------- | ------------------------------------------------- | ---- | ---- | --------------------------------------------- |
| deviceId | string                                            | 否 | 否   | 对端蓝牙设备地址。例如："XX:XX:XX:XX:XX:XX"。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| state    | [ProfileConnectionState](js-apis-bluetooth-constant.md#profileconnectionstate) | 否 | 否   | GATT profile连接状态。 <br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| reason<sup>20+</sup>    | [GattDisconnectReason](#gattdisconnectreason20) | 否 | 是   | GATT链路断连原因，仅在连接状态为 [STATE_DISCONNECTED](js-apis-bluetooth-constant.md#profileconnectionstate) 时提供，其他连接状态下断连原因默认为undefined。<br> **原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。|


## ScanResult

扫描到符合过滤条件的广播报文后，上报的扫描数据。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称       | 类型        | 只读 | 可选   | 说明                                 |
| -------- | ----------- | ---- | ---- | ---------------------------------- |
| deviceId | string      | 否 | 否    | 扫描到的蓝牙设备地址。例如："XX:XX:XX:XX:XX:XX"。<br>基于信息安全考虑，此处获取的设备地址为虚拟MAC地址。<br>- 若和该设备地址配对成功后，该地址不会变更。<br>- 若取消配对该设备或蓝牙关闭后，再次重新发起扫描，该虚拟地址会变更。<br>- 若要持久化保存该地址，可使用[access.addPersistentDeviceId](js-apis-bluetooth-access.md#accessaddpersistentdeviceid16)方法。 |
| rssi     | number      | 否 | 否    | 扫描到的设备信号强度，单位：dBm。                    |
| data     | ArrayBuffer | 否 | 否    | 扫描到的设备发送的广播报文内容。                    |
| deviceName | string | 否 | 否    | 扫描到的设备名称。                    |
| connectable  | boolean | 否 | 否    | 扫描到的设备是否可连接。true表示可连接，false表示不可连接。                    |


## AdvertiseSetting

描述BLE广播的发送参数。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称          | 类型    | 只读 | 可选   | 说明                                       |
| ----------- | ------- | ---- | ---- | ---------------------------------------- |
| interval    | number  | 否 | 是    | 广播发送间隔。<br>取值范围：[32, 16777215]，单位：slot（时间槽），一个slot代表0.625毫秒，默认值为1600。<br>其中传统广播的最大值是16384。 |
| txPower     | number  | 否 | 是    | 广播发送功率。取值范围：[-127, 1]，单位：dBm，默认值为-7。<br>考虑到发送广播的性能和功耗，建议高档取值为1，中档取为-7，低档取值为-15。   |
| connectable | boolean | 否 | 是    | 是否是可连接广播。true表示发送可连接广播，false表示发送不可连接广播，默认值为true。                   |


## AdvertiseData

描述BLE广播报文数据内容，也可以用作回复扫描请求的广播报文数据内容。当前只支持传统广播，因此报文最大长度为31个字节。若超出最大长度（31个字节）限制，会导致启动广播失败。若携带了所有参数，尤其是携带了蓝牙设备名称，需要注意广播报文长度。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称              | 类型                                     | 只读 | 可选   | 说明                          |
| --------------- | ---------------------------------------- | ---- | ---- | --------------------------- |
| serviceUuids    | Array&lt;string&gt;                      | 否 | 否    | 要携带的服务UUID。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| manufactureData | Array&lt;[ManufactureData](#manufacturedata)&gt; | 否 | 否    | 要携带的制造商数据内容。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。           |
| serviceData     | Array&lt;[ServiceData](#servicedata)&gt; | 否 | 否    | 要携带的服务数据内容。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。               |
| includeDeviceName | boolean     | 否 | 是    | 是否携带蓝牙设备名称。true表示携带，false表示不携带，默认值为false。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。        |
| includeTxPower<sup>18+</sup> | boolean     | 否    | 是    | 是否携带广播发送功率。<br>true表示携带广播发送功率，false表示不携带广播发送功率，默认值为false。<br>携带该值后，广播报文长度将多占用3个字节。<br>**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。      |


## AdvertisingParams<sup>11+</sup>

首次启动BLE广播时设置的参数。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 类型                             | 只读 | 可选  | 说明                      |
| ------------------- | ------------------------------- | ----- | ----- | ------------------------ |
| advertisingSettings<sup>11+</sup> | [AdvertiseSetting](#advertisesetting) | 否 | 否    | 广播的发送参数。    |
| advertisingData<sup>11+</sup>    | [AdvertiseData](#advertisedata) | 否 | 否    | 需要发送的广播报文数据内容。      |
| advertisingResponse<sup>11+</sup> | [AdvertiseData](#advertisedata) | 否 | 是    | 回复扫描请求的广播报文数据内容。 |
| duration<sup>11+</sup>    | number   | 否 | 是    | 发送广播的持续时间。取值范围：[1, 65535]，单位：10ms。<br>如果未指定此参数或者将其设置为0，则会持续发送广播。    |

## AdvertisingEnableParams<sup>11+</sup>

启动指定标识的BLE广播时设置的参数。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 类型                   | 只读 | 可选  | 说明                      |
| ------------------- | --------------------- | ----- | ----- | ------------------------ |
| advertisingId       | number                | 否 | 否    | 需要启动的广播标识。     |
| duration            | number                | 否 | 是    | 发送广播的持续时间。取值范围：[1, 65535]，单位：10ms。<br>如果未指定此参数或者将其设置为0，则会持续发送广播。   |

## AdvertisingDisableParams<sup>11+</sup>

停止指定标识的BLE广播时设置的参数。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 类型                   | 只读 | 可选  | 说明                      |
| ------------------- | --------------------- | ----- | ----- | ------------------------ |
| advertisingId       | number                | 否 | 否    | 需要停止的广播标识。     |

## AdvertisingStateChangeInfo<sup>11+</sup>

描述BLE广播启动、停止的状态信息。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 类型                                     | 只读 | 可选   | 说明                      |
| ------------------- | --------------------------------------- | ----- | ----- | ------------------------ |
| advertisingId       | number                                  | 否 | 否    |首次启动广播时会分配该值，后续用于标识当前操作的广播。           |
| state               | [AdvertisingState](#advertisingstate11)   | 否 | 否    | 操作广播后，收到的BLE广播状态。             |

## ManufactureData

描述BLE广播报文中制造商数据内容。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称               | 类型                | 只读 | 可选   | 说明                 |
| ---------------- | ------------------- | ---- | ---- | ------------------ |
| manufactureId    | number  | 否 | 否    | 制造商的标识，由蓝牙技术联盟分配。 |
| manufactureValue | ArrayBuffer         | 否 | 否    | 制造商特定的数据。     |


## ServiceData

描述BLE广播报文中的服务数据内容。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称           | 类型        | 只读 | 可选   | 说明         |
| ------------ | ----------- | ---- | ---- | ---------- |
| serviceUuid  | string      | 否  | 否    | 服务UUID。 |
| serviceValue | ArrayBuffer | 否  | 否    | 服务数据。    |


## ScanFilter

扫描BLE广播的过滤条件，只有符合该条件的广播报文才会上报。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                                     | 类型    | 只读 | 可选  | 说明                                                         |
| ------------------------------------------ | -------- | ---- | ---- | ------------------------------------------------------------ |
| deviceId                                 | string      | 否 | 是    | 过滤该BLE设备地址的广播报文。例如："XX:XX:XX:XX:XX:XX"。           |
| name                                     | string      | 否 | 是    | 过滤该BLE设备名称的广播报文。                                        |
| serviceUuid                              | string      | 否 | 是    | 过滤包含该服务UUID的广播报文。例如：00001888-0000-1000-8000-00805f9b34fb。 |
| serviceUuidMask             | string      | 否 | 是     | 搭配serviceUuid过滤器使用，可设置过滤部分服务UUID。例如：FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF。 |
| serviceSolicitationUuid     | string      | 否 | 是     | 过滤包含该服务请求UUID的广播报文。例如：00001888-0000-1000-8000-00805F9B34FB。 |
| serviceSolicitationUuidMask | string      | 否 | 是     | 搭配serviceSolicitationUuid过滤器使用，可设置过滤部分服务请求UUID。例如：FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF。 |
| serviceData                 | ArrayBuffer | 否 | 是     | 过滤包含该服务数据的广播报文。例如：[0x90,0x00,0xF1,0xF2]。 |
| serviceDataMask             | ArrayBuffer | 否 | 是     | 搭配serviceData过滤器使用，可设置过滤部分服务数据。例如：[0xFF,0xFF,0xFF,0xFF]。 |
| manufactureId               | number      | 否 | 是     | 过滤包含该制造商标识符的广播报文。例如：0x0006。                 |
| manufactureData             | ArrayBuffer | 否 | 是     | 搭配manufactureId过滤器使用，过滤包含该制造商数据的广播报文。例如：[0x1F,0x2F,0x3F]。 |
| manufactureDataMask         | ArrayBuffer | 否 | 是     | 搭配manufactureData过滤器使用，可设置过滤部分制造商数据。例如：[0xFF,0xFF,0xFF]。 |


## ScanOptions

BLE扫描的配置参数。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称        | 类型                    | 只读 | 可选   | 说明                                     |
| --------- | ----------------------- | ---- | ---- | -------------------------------------- |
| interval  | number                  | 否 | 是    | 扫描结果上报的延迟时间，单位：ms，默认值为0。搭配[ScanReportMode](#scanreportmode15)使用。<br>- 在常规或围栏扫描上报模式下，该值不生效，扫描到符合过滤条件的广播报文后立即上报。<br>- 在批量扫描上报模式下，该值生效，扫描到符合过滤条件的广播报文后，会存入缓存队列，延迟上报。若不设置该值或设置在[0, 5000)范围内，蓝牙子系统会默认设置延迟时间为5000ms。延迟时间内，若符合过滤条件的广播报文数量超过硬件缓存能力，蓝牙子系统会提前上报扫描结果。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                     |
| dutyMode  | [ScanDuty](#scanduty)   | 否 | 是    | 扫描模式，默认值为SCAN_MODE_LOW_POWER。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。        |
| matchMode | [MatchMode](#matchmode) | 否 | 是    | 硬件的过滤匹配模式，默认值为MATCH_MODE_AGGRESSIVE。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| phyType<sup>12+</sup> | [PhyType](#phytype12) | 否 | 是    | 扫描中使用的物理通道类型，默认值为PHY_LE_1M。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| reportMode<sup>15+</sup> | [ScanReportMode](#scanreportmode15) | 否 | 是    | 扫描结果数据上报模式，默认值为NORMAL。<br>**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。 |


## GattProperties

描述GATT特征值支持的属性。决定了特征值内容和描述符如何被使用和访问。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称       | 类型  | 只读 | 可选   | 说明          |
| -------- | ------ |---- |---- | ----------- |
| write    | boolean | 否 | 是  | 该特征值是否支持写入操作。<br>true表示支持，且被写入时需要回复对端设备，false表示不支持。默认值为true。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| writeNoResponse | boolean | 否 | 是   | 该特征值是否支持写入操作。<br>true表示支持，且被写入时无需回复对端设备，false表示不支持。默认值为true。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| read | boolean   | 否 |  是    | 该特征值是否支持读取操作。<br>true表示支持，false表示不支持。默认值为true。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| notify | boolean   | 否 | 是    | 该特征值是否支持主动向对端设备通知特征值内容。<br>true表示支持，且对端设备不需要回复确认，false表示不支持。默认值为false。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| indicate | boolean   | 否 | 是    | 该特征值是否支持向对端设备指示特征值内容。<br>true表示支持，对端设备需要回复确认，false表示不支持。默认值为false。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| broadcast<sup>20+</sup> | boolean   | 否 | 是    | 该特征值是否支持作为广播内容由server端发送。<br>true表示支持，server端可将特征值内容以[ServiceData](#servicedata)类型在广播报文中携带，false表示不支持。默认值为false。<br>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。 |
| authenticatedSignedWrite<sup>20+</sup> | boolean   | 否 | 是    | 该特征值是否支持签名写入操作，通过对写入内容进行签名校验替代加密流程。<br>true表示支持，且该特征值权限[GattPermissions](#gattpermissions20)中的writeSigned或writeSignedMitm需设置为true，否则该属性不生效，false表示不支持。默认值为false。<br>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。 |
| extendedProperties<sup>20+</sup> | boolean   | 否 | 是    | 该特征值是否存在扩展属性。<br>true表示存在扩展属性，false表示不存在。默认值为false。<br>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。 |


## GattPermissions<sup>20+</sup>

描述读写GATT特征值或描述符需具备的权限。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称       | 类型  | 只读 | 可选   | 说明          |
| -------- | ------ |---- |---- | ----------- |
| read | boolean   | 否 |  是    | 是否允许读取该特征值或描述符内容。<br>true表示允许，false表示不允许。默认值为true。 |
| readEncrypted | boolean   | 否 |  是    | 读取该特征值或描述符内容是否需要加密。<br>true表示需要加密后，方可读取内容，false表示不需要普通方式加密。默认值为false。 |
| readEncryptedMitm | boolean   | 否 |  是    | 读取该特征值或描述符内容是否需要防中间人攻击的加密。<br>防中间人攻击表示操作需要经过认证，防止数据被第三方篡改。true表示需要防中间人攻击的加密后才能读取内容，false表示不需要防中间人攻击的加密。默认值为false。 |
| write    | boolean | 否 | 是  | 是否允许写入该特征值或描述符内容。<br>true表示允许，false表示不允许。默认值为true。 |
| writeEncrypted    | boolean | 否 | 是  | 写入该特征值或描述符内容是否需要加密。<br>true表示需要加密后，方可写入内容，false表示不需要普通方式加密。默认值为false。 |
| writeEncryptedMitm    | boolean | 否 | 是  | 写入该特征值或描述符内容是否需要防中间人攻击的加密。<br>true表示需要防中间人攻击的加密后才能写入内容，false表示不需要防中间人攻击的加密。默认值为false。 |
| writeSigned    | boolean | 否 | 是  | 写入该特征值或描述符内容是否需要经过签名处理。<br>true表示内容需要签名处理后方可写入，false表示不需要签名处理。默认值为false。 |
| writeSignedMitm    | boolean | 否 | 是  | 写入该特征值或描述符内容是否需要经过防中间人攻击方式的签名处理。<br>true表示需要防中间人攻击方式的签名处理后方可写入，false表示不需要以防中间人攻击方式签名处理。默认值为false。 |


## GattWriteType

枚举，写入特征值的方式（不同的取值，对端蓝牙设备的表现不一样）。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                                   | 值    | 说明              |
| ------------------------------------| ------ | --------------- |
| WRITE               | 1 | 写入特征值后，对端蓝牙设备需要回复确认。   |
| WRITE_NO_RESPONSE   | 2 | 写入特征值后，对端蓝牙设备不需要回复。  |


## ScanDuty

枚举，扫描模式，表示不同的扫描性能和功耗情况。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                    | 值  | 说明           |
| --------------------- | ---- | ------------ |
| SCAN_MODE_LOW_POWER   | 0    | 低功耗模式，扫描性能较低，功耗也较低。 |
| SCAN_MODE_BALANCED    | 1    | 均衡模式，平衡扫描性能和功耗。      |
| SCAN_MODE_LOW_LATENCY | 2    | 低延迟模式，扫描性能较高，但功耗也较高。     |


## MatchMode

枚举，硬件过滤匹配模式。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                    | 值  | 说明                                       |
| --------------------- | ---- | ---------------------------------------- |
| MATCH_MODE_AGGRESSIVE | 1    | 当广播报文信号强度较低或者短时间内广播报文的发送次数较少时，可以更快地上报。 |
| MATCH_MODE_STICKY     | 2    | 广播报文信号强度较高或者短时间内广播报文的发送次数较多时，才会上报。       |

## AdvertisingState<sup>11+</sup>

枚举，不同操作对应的BLE广播状态。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称      | 值    | 说明                           |
| --------  | ---- | ------------------------------ |
| STARTED<sup>11+</sup>   | 1    | 调用[startAdvertising](#blestartadvertising11)方法后，广播首次启动成功，且会分配相关资源。       |
| ENABLED<sup>11+</sup>   | 2    | 调用[enableAdvertising](#bleenableadvertising11)方法后，广播启动成功。       |
| DISABLED<sup>11+</sup>  | 3    | 调用[disableAdvertising](#bledisableadvertising11)方法后，广播停止成功。       |
| STOPPED<sup>11+</sup>    | 4    | 调用[stopAdvertising](#blestopadvertising11)方法后，广播停止成功，且会释放首次启动广播时分配的相关资源。       |

## PhyType<sup>12+</sup>

枚举，指定扫描过程中接收BLE广播报文的物理通道。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称      | 值    | 说明                           |
| --------  | ---- | ------------------------------ |
| PHY_LE_1M<sup>12+</sup>   | 1    | 使用1M PHY类型扫描。       |
| PHY_LE_ALL_SUPPORTED<sup>12+</sup>   | 255    | 使用所有支持的PHY类型扫描。    |

## ScanReport<sup>15+</sup>

上报的扫描数据。

**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称      | 类型                  |只读   |可选   | 说明                                     |
| --------- | ----------------------- | ---- | ---- | ------------------------------ |
| reportType  | [ScanReportType](#scanreporttype15)        | 否 | 否 | 扫描结果上报类型。    |
| scanResult  | Array&lt;[ScanResult](#scanresult)&gt;    | 否 | 否 | 扫描到符合过滤条件的BLE广播报文后，上报的扫描数据。        |

## ScanReportType<sup>15+</sup>

枚举，扫描结果上报类型。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称      | 值    | 说明                           |
| --------  | ---- | ------------------------------ |
| ON_FOUND  | 1    | 扫描到符合过滤条件的BLE广播报文时，触发上报，可搭配常规和围栏上报模式使用。 <br> **原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。      |
| ON_LOST | 2    | 当不再扫描到符合过滤条件的BLE广播报文时，触发上报，只搭配围栏上报模式使用。 <br> **原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用    |
| ON_BATCH<sup>19+</sup> | 3    | 扫描到符合过滤条件的BLE广播报文时，以[ScanOptions](#scanoptions)中的interval字段为周期触发上报。 <br> **原子化服务API**：从API version 19开始，该接口支持在原子化服务中使用    |

## GattDisconnectReason<sup>20+</sup>

枚举，指定GATT链路断开的原因。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称      | 值    | 说明                           |
| --------  | ---- | ------------------------------ |
| CONN_TIMEOUT   | 1    | 连接超时。       |
| CONN_TERMINATE_PEER_USER   | 2    | 对端设备主动断开连接。    |
| CONN_TERMINATE_LOCAL_HOST   | 3    | 本端设备主动断开连接。    |
| CONN_UNKNOWN   | 4    | 未知断连原因。    |

## ScanReportMode<sup>15+</sup>

枚举，扫描结果上报模式。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称      | 值    | 说明                           |
| --------  | ---- | ------------------------------ |
| NORMAL  | 1    | 常规扫描上报模式，扫描到符合过滤条件的BLE广播报文后就会立刻上报。<br>**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。       |
| BATCH<sup>19+</sup>  | 2    | 批量扫描上报模式。<br>- 该模式可通过降低蓝牙芯片上报扫描结果频率，使系统更长时间地保持在休眠状态，从而降低整机功耗。<br>- 该模式下，扫描到符合过滤条件的BLE广播报文后不会立刻上报，需要缓存一段时间（[ScanOptions](#scanoptions)中的interval字段）后上报。 <br>**原子化服务API**：从API version 19开始，该接口支持在原子化服务中使用。       |
| FENCE_SENSITIVITY_LOW<sup>18+</sup>  | 10    | 低灵敏度围栏上报模式。<br>- 围栏模式表示只在广播进入或离开围栏时上报。<br>- 扫描到的广播信号强度高且广播数量多时，可进入低灵敏度围栏。<br>- 首次扫描到广播即进入围栏，触发一次上报。<br>- 一段时间内扫描不到广播即离开围栏，触发一次上报。<br>**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。    |
| FENCE_SENSITIVITY_HIGH<sup>18+</sup>  | 11    | 高灵敏度围栏上报模式。<br>- 围栏模式表示只在广播进入或离开围栏时上报。<br>- 扫描到的广播信号强度低且广播数量少时，可进入高灵敏度围栏。<br>- 首次扫描到广播即进入围栏，触发一次上报。<br>- 一段时间内扫描不到广播即离开围栏，触发一次上报。<br>**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。    |