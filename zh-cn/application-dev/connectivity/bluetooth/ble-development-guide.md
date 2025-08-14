# 查找设备

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

## 简介
本指南主要提供了BLE扫描和BLE广播相关操作的开发指导。可以实现发现周边BLE设备和其他设备发现本机设备的场景。

## 开发步骤

### 申请蓝牙权限
需要申请权限ohos.permission.ACCESS_BLUETOOTH。如何配置和申请权限，请参考[声明权限](../../security/AccessToken/declare-permissions.md)和[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

### 导入所需API模块
导入ble和错误码模块。
```ts
import { ble } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
```

### BLE扫描流程

**1. 订阅扫描结果上报事件**<br>
- 推荐使用API version 15开始支持的扫描方式，该方式支持应用发起和管理多路扫描。该方式支持的上报事件请参考[on('BLEDeviceFind')](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#onbledevicefind15)。
```ts
// 定义扫描结果上报回调函数
function onReceiveEvent(scanReport: ble.ScanReport) {
  console.info('BLE scan device find result: '+ JSON.stringify(scanReport));
}

// 创建ble扫描实例，可以管理该实例下创建的扫描流程
let bleScanner: ble.BleScanner = ble.createBleScanner();

try {
  // 发起订阅
  bleScanner.on('BLEDeviceFind', onReceiveEvent);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

- API version 14及以前支持的扫描方式只支持应用发起单路扫描。该方式支持的上报事件请参考[ble.on('BLEDeviceFind')](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#bleonbledevicefind)。
```ts
// 定义扫描结果上报回调函数
function onReceiveEvent(data: Array<ble.ScanResult>) {
  console.info('BLE scan device find result: '+ JSON.stringify(data));
}

try {
  // 发起订阅
  ble.on('BLEDeviceFind', onReceiveEvent);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

- 如何解析扫描到的广播报文，具体可参考本章节[完整示例](#完整示例)。

**2. 发起扫描**<br>
通过BLE扫描周边其他设备发出的BLE广播，可以发现或者查找到应用需要的目标设备，适用于查找设备场景。

若本机设备扫描到可连接的BLE广播，则可以和该设备进行通用属性协议（Generic Attribute Profile，GATT）的连接和数据传输，此时本机设备角色也被称为GATT客户端。具体操作请参考[连接和传输数据](gatt-development-guide.md)。

- 推荐使用API version 15开始支持的扫描方式，该方式支持应用发起和管理多路扫描。可通过[createBleScanner](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blecreateblescanner15)创建扫描实例[BleScanner](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blescanner15)，并调用[startScan](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#startscan15)。
```ts
// 创建ble扫描实例
let bleScanner: ble.BleScanner = ble.createBleScanner();

// 构造扫描BLE广播的过滤条件，目标BLE广播报文需符合该过滤条件
let manufactureId = 4567;
let manufactureData: Uint8Array = new Uint8Array([1, 2, 3, 4]);
let manufactureDataMask: Uint8Array = new Uint8Array([0xFF, 0xFF, 0xFF, 0xFF]);
let scanFilter: ble.ScanFilter = { // 根据业务实际情况定义过滤器
  manufactureId: manufactureId,
  manufactureData: manufactureData.buffer,
  manufactureDataMask: manufactureDataMask.buffer
};

// 构造扫描配置参数
let scanOptions: ble.ScanOptions = {
  interval: 0,
  dutyMode: ble.ScanDuty.SCAN_MODE_LOW_POWER,
  matchMode: ble.MatchMode.MATCH_MODE_AGGRESSIVE
}

try {
  // 发起扫描
  bleScanner.startScan([scanFilter], scanOptions);
  console.info('startBleScan success');
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

- API version 14及以前支持的扫描方式只支持应用发起单路扫描。若要再次发起扫描，必须先停止上一路的扫描流程。详情请见[ble.startBLEScan](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blestartblescan)。
```ts
// 构造扫描BLE广播的过滤条件，目标BLE广播报文需符合该过滤条件
let manufactureId = 4567;
let manufactureData: Uint8Array = new Uint8Array([1, 2, 3, 4]);
let manufactureDataMask: Uint8Array = new Uint8Array([0xFF, 0xFF, 0xFF, 0xFF]);
let scanFilter: ble.ScanFilter = { // 根据业务实际情况定义过滤器
  manufactureId: manufactureId,
  manufactureData: manufactureData.buffer,
  manufactureDataMask: manufactureDataMask.buffer
};

// 构造扫描配置参数
let scanOptions: ble.ScanOptions = {
  interval: 0,
  dutyMode: ble.ScanDuty.SCAN_MODE_LOW_POWER,
  matchMode: ble.MatchMode.MATCH_MODE_AGGRESSIVE
}
try {
  // 发起扫描
  ble.startBLEScan([scanFilter], scanOptions);
  console.info('startBleScan success');
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**3. 停止扫描**<br>
扫描流程会消耗蓝牙硬件资源和影响设备功耗。当应用不再需要该扫描时，需要主动停止。

- 搭配API version 15开始支持的多路扫描方式。详情请见[stopScan](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#stopscan15)。
```ts
// 定义扫描结果上报回调函数
function onReceiveEvent(scanReport: ble.ScanReport) {
  console.info('BLE scan device find result: '+ JSON.stringify(scanReport));
}

// 创建ble扫描实例
let bleScanner: ble.BleScanner = ble.createBleScanner();

try {
  bleScanner.off('BLEDeviceFind', onReceiveEvent);
  // 停止扫描
  bleScanner.stopScan();
  console.info('stopBleScan success');
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

- 搭配API version 14及以前支持的单路扫描方式。详情请见[ble.stopBLEScan](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blestopblescan)。
```ts
// 定义扫描结果上报回调函数
function onReceiveEvent(data: Array<ble.ScanResult>) {
  console.info('BLE scan device find result: '+ JSON.stringify(data));
}

try {
  // 取消订阅
  ble.off('BLEDeviceFind', onReceiveEvent);
  // 停止扫描
  ble.stopBLEScan();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### BLE广播流程
本机设备发送BLE广播后，可以实现被其他设备发现的功能。

若本机设备发送的是可连接广播，则可以接受其他设备发起的通用属性协议（Generic Attribute Profile，GATT）连接，此时本机设备角色也被称为GATT服务端。具体操作请参考[连接和传输数据](gatt-development-guide.md)。

推荐使用API version 11及以后开始支持的广播操作方式。

**1. 订阅广播状态上报事件**<br>
搭配API version 11开始支持的广播操作方式。
```ts
function onReceiveEvent(data: ble.AdvertisingStateChangeInfo) {
    console.info('bluetooth advertising state = ' + JSON.stringify(data));
}

try {
    ble.on('advertisingStateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**2. 启动广播**<br>
- 推荐使用API version 11开始支持的广播操作方式。支持在不释放相关广播资源情况下，多次操作启动或者停止指定标识的广播，且支持设置广播持续发送的时间。<br>
相关API请参考[ble.startAdvertising](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blestartadvertising11)和[ble.enableAdvertising](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#bleenableadvertising11)。<br>
首次启动广播接口[ble.startAdvertising](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blestartadvertising11)会分配广播相关资源，从API version 15开始，该接口支持应用多次调用，实现启动多路广播的功能，并通过不同的广播标识进行管理。
```ts
// 设置广播发送的参数
let setting: ble.AdvertiseSetting = {
    interval: 160,
    txPower: 0,
    connectable: true // 发送支持连接的广播
};
// 构造广播数据
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
let manufactureDataUnit: ble.ManufactureData = {
  manufactureId: 4567,
  manufactureValue: manufactureValueBuffer.buffer
};
let serviceDataUnit1: ble.ServiceData = {
  serviceUuid: "00001999-0000-1000-8000-00805f9b34fb",
  serviceValue: serviceValueBuffer.buffer
};
let serviceDataUnit2: ble.ServiceData = {
  serviceUuid: "19991999-0000-1000-8000-00805f9b34fb",
  serviceValue: serviceValueBuffer.buffer
};
let advData: ble.AdvertiseData = {
  serviceUuids: ["00001888-0000-1000-8000-00805f9b34fb", "18881888-0000-1000-8000-00805f9b34fb"],
  manufactureData: [manufactureDataUnit],
  serviceData: [],
  includeDeviceName: false // 表示是否携带设备名，可选参数。注意：带上设备名时，容易导致广播报文长度超出31个字节，使得广播启动失败
};
let advResponse: ble.AdvertiseData = {
  serviceUuids: [],
  manufactureData: [],
  serviceData: [serviceDataUnit1, serviceDataUnit2]
};
// 构造广播启动完整参数AdvertisingParams
let advertisingParams: ble.AdvertisingParams = {
  advertisingSettings: setting,
  advertisingData: advData, // 注意: 广播报文长度不能超过31个字节
  advertisingResponse: advResponse, // 注意: 广播报文长度不能超过31个字节
  duration: 0 // 可选参数，若大于0，则广播发送一段时间后，则会停止，但分配的广播资源还在，可重新启动发送
}

let advHandle = 0xFF; // 定义广播标识

// 首次启动广播，蓝牙子系统会分配相关资源，包括应用获取到的广播的标识ID
try {
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

// 构造启动广播参数
let advertisingEnableParams: ble.AdvertisingEnableParams = {
  advertisingId: advHandle, // 使用首次启动广播时获取到的广播标识ID
  duration: 300
}
try {
  // 再次启动
  ble.enableAdvertising(advertisingEnableParams, (err) => {
    if (err) {
      return;
    }
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

- API version 10及以前支持的广播操作方式只支持应用启动单路广播。若要再次启动广播，必须先停止上一路的广播流程。详情请见[ble.startAdvertising](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blestartadvertising)。
```ts
// 设置广播发送的参数
let setting: ble.AdvertiseSetting = {
    interval: 160,
    txPower: 0,
    connectable: true
};
// 构造广播数据
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
let manufactureDataUnit: ble.ManufactureData = {
  manufactureId: 4567,
  manufactureValue: manufactureValueBuffer.buffer
};
let serviceDataUnit1: ble.ServiceData = {
  serviceUuid: "00001999-0000-1000-8000-00805f9b34fb",
  serviceValue: serviceValueBuffer.buffer
};
let serviceDataUnit2: ble.ServiceData = {
  serviceUuid: "19991999-0000-1000-8000-00805f9b34fb",
  serviceValue: serviceValueBuffer.buffer
};
let advData: ble.AdvertiseData = {
  serviceUuids: ["00001888-0000-1000-8000-00805f9b34fb", "18881888-0000-1000-8000-00805f9b34fb"],
  manufactureData: [manufactureDataUnit],
  serviceData: [],
  includeDeviceName: false // 表示是否携带设备名，可选参数。注意：带上设备名时，容易导致广播报文长度超出31个字节
};
let advResponse: ble.AdvertiseData = {
  serviceUuids: [],
  manufactureData: [],
  serviceData: [serviceDataUnit1, serviceDataUnit2]
};
try {
  // 启动广播
  ble.startAdvertising(setting, advData ,advResponse);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**3. 停止广播**<br>
广播流程会消耗蓝牙硬件资源和影响设备功耗。当应用不再需要该广播时，需要主动停止。

- 搭配API version 11开始支持的广播方式。相关API请参考[ble.disableAdvertising](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#bledisableadvertising11)和[ble.stopAdvertising](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blestopadvertising11)。<br>
完全停止广播接口[ble.stopAdvertising](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blestopadvertising11)会释放所有广播资源，因此首次启动广播分配的广播标识将无效。
```ts
let advHandle = 1; // 注意：该值是首次启动广播时获取到的广播标识，此处是伪代码ID

// 构造停止广播参数
let advertisingDisableParams: ble.AdvertisingDisableParams = {
    advertisingId: advHandle // 使用首次启动广播时获取到的广播标识ID
}
try {
  // 停止
  ble.disableAdvertising(advertisingDisableParams, (err) => {
    if (err) {
      return;
    }
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

try {
  // 完全停止
  ble.stopAdvertising(advHandle, (err) => {
    if (err) {
      return;
    }
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

```

- 搭配API version 11及以前支持的单路广播方式。相关API请参考[ble.stopAdvertising](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blestopadvertising)。
```ts
try {
  // 停止
  ble.stopAdvertising();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## 完整示例

### BLE扫描流程
```ts
import { ble } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

const TAG: string = 'BleAdvertisingManager';

// 参考蓝牙标准协议规范Core Assigned Numbers
const BLE_ADV_TYPE_FLAG = 0x01;
const BLE_ADV_TYPE_16_BIT_SERVICE_UUIDS_INCOMPLETE = 0x02;
const BLE_ADV_TYPE_16_BIT_SERVICE_UUIDS_COMPLETE = 0x03;
const BLE_ADV_TYPE_32_BIT_SERVICE_UUIDS_INCOMPLETE = 0x04;
const BLE_ADV_TYPE_32_BIT_SERVICE_UUIDS_COMPLETE = 0x05;
const BLE_ADV_TYPE_128_BIT_SERVICE_UUIDS_INCOMPLETE = 0x06;
const BLE_ADV_TYPE_128_BIT_SERVICE_UUIDS_COMPLETE = 0x07;
const BLE_ADV_TYPE_LOCAL_NAME_SHORT = 0x08;
const BLE_ADV_TYPE_LOCAL_NAME_COMPLETE = 0x09;
const BLE_ADV_TYPE_TX_POWER_LEVEL = 0x0A;
const BLE_ADV_TYPE_16_BIT_SERVICE_SOLICITATION_UUIDS = 0x14;
const BLE_ADV_TYPE_128_BIT_SERVICE_SOLICITATION_UUIDS = 0x15;
const BLE_ADV_TYPE_32_BIT_SERVICE_SOLICITATION_UUIDS = 0x1F;
const BLE_ADV_TYPE_16_BIT_SERVICE_DATA = 0x16;
const BLE_ADV_TYPE_32_BIT_SERVICE_DATA = 0x20;
const BLE_ADV_TYPE_128_BIT_SERVICE_DATA = 0x21;
const BLE_ADV_TYPE_MANUFACTURER_SPECIFIC_DATA = 0xFF;

const BLUETOOTH_UUID_16_BIT_LENGTH = 2;
const BLUETOOTH_UUID_32_BIT_LENGTH = 4;
const BLUETOOTH_UUID_128_BIT_LENGTH = 16;

const BLUETOOTH_MANUFACTURE_ID_LENGTH = 2;

export class BleScanManager {
  bleScanner: ble.BleScanner = ble.createBleScanner();

  // 1. 定义扫描结果上报回调函数
  onReceiveEvent = (scanReport: ble.ScanReport) => {
    console.info(TAG, 'BLE scan device find result: '+ JSON.stringify(scanReport));
    if (scanReport.scanResult.length > 0) {
      console.info(TAG, 'BLE scan result: ' + scanReport.scanResult[0].deviceId);
      this.parseScanResult(scanReport.scanResult[0].data);
    }
  };

  public parseScanResult(data: ArrayBuffer) {
    let advData = new Uint8Array(data);
    if (advData.byteLength == 0) {
      console.warn(TAG, 'adv data length is 0');
      return;
    }

    let advertiseFlags: number = -1;
    let txPowerLevel: number = -1;
    let localName: string = '';
    let serviceUuids: string[] = [];
    let serviceSolicitationUuids: string[] = [];
    let manufactureSpecificDatas: Record<number, Uint8Array> = {};
    let serviceDatas: Record<string, Uint8Array> = {};

    let curPos = 0;
    while (curPos < advData.byteLength) {
      let length = advData[curPos++]; // 获取当前广播类型的长度（length+data），curPos指向下一个位置
      if (length == 0) {
        break;
      }

      // 获取当前广播类型内容长度（data）
      let advDataLength = length - 1;

      // 获取当前广播类型，curPos指向下一个位置，从该位置解析实际内容，参考Core Specification Supplement, PartA
      let advDataType = advData[curPos++];
      switch (advDataType) {
        case BLE_ADV_TYPE_FLAG:
          advertiseFlags = advData[curPos];
          break;
        case BLE_ADV_TYPE_LOCAL_NAME_SHORT:
        case BLE_ADV_TYPE_LOCAL_NAME_COMPLETE:
          localName = advData.slice(curPos, curPos + advDataLength).toString();
          break;
        case BLE_ADV_TYPE_TX_POWER_LEVEL:
          txPowerLevel = advData[curPos];
          break;
        case BLE_ADV_TYPE_16_BIT_SERVICE_UUIDS_INCOMPLETE:
        case BLE_ADV_TYPE_16_BIT_SERVICE_UUIDS_COMPLETE:
          this.parseServiceUuid(BLUETOOTH_UUID_16_BIT_LENGTH, curPos, advDataLength, advData, serviceUuids);
          break;
        case BLE_ADV_TYPE_32_BIT_SERVICE_UUIDS_INCOMPLETE:
        case BLE_ADV_TYPE_32_BIT_SERVICE_UUIDS_COMPLETE:
          this.parseServiceUuid(BLUETOOTH_UUID_32_BIT_LENGTH, curPos, advDataLength, advData, serviceUuids);
          break;
        case BLE_ADV_TYPE_128_BIT_SERVICE_UUIDS_INCOMPLETE:
        case BLE_ADV_TYPE_128_BIT_SERVICE_UUIDS_COMPLETE:
          this.parseServiceUuid(BLUETOOTH_UUID_128_BIT_LENGTH, curPos, advDataLength, advData, serviceUuids);
          break;
        case BLE_ADV_TYPE_16_BIT_SERVICE_SOLICITATION_UUIDS:
          this.parseServiceSolicitationUuid(BLUETOOTH_UUID_16_BIT_LENGTH, curPos, advDataLength,
            advData, serviceSolicitationUuids);
          break;
        case BLE_ADV_TYPE_32_BIT_SERVICE_SOLICITATION_UUIDS:
          this.parseServiceSolicitationUuid(BLUETOOTH_UUID_32_BIT_LENGTH, curPos, advDataLength,
            advData, serviceSolicitationUuids);
          break;
        case BLE_ADV_TYPE_128_BIT_SERVICE_SOLICITATION_UUIDS:
          this.parseServiceSolicitationUuid(BLUETOOTH_UUID_128_BIT_LENGTH, curPos, advDataLength,
            advData, serviceSolicitationUuids);
          break;
        case BLE_ADV_TYPE_16_BIT_SERVICE_DATA:
          this.parseServiceData(BLUETOOTH_UUID_16_BIT_LENGTH, curPos, advDataLength, advData, serviceDatas);
          break;
        case BLE_ADV_TYPE_32_BIT_SERVICE_DATA:
          this.parseServiceData(BLUETOOTH_UUID_32_BIT_LENGTH, curPos, advDataLength, advData, serviceDatas);
          break;
        case BLE_ADV_TYPE_128_BIT_SERVICE_DATA:
          this.parseServiceData(BLUETOOTH_UUID_128_BIT_LENGTH, curPos, advDataLength, advData, serviceDatas);
          break;
        case BLE_ADV_TYPE_MANUFACTURER_SPECIFIC_DATA:
          this.parseManufactureData(curPos, advDataLength, advData, manufactureSpecificDatas);
          break;
        default:
          break;
      }
      curPos += advDataLength; // curPos指向下一个字段类型
    }
    console.info(TAG, 'advertiseFlags: ' + advertiseFlags);
    console.info(TAG, 'txPowerLevel: ' + txPowerLevel);
    console.info(TAG, 'localName: ' + localName);
    console.info(TAG, 'serviceUuids: ' + JSON.stringify(serviceUuids));
    console.info(TAG, 'serviceSolicitationUuids: ' + JSON.stringify(serviceSolicitationUuids));
    console.info(TAG, 'manufactureSpecificDatas: ' + JSON.stringify(manufactureSpecificDatas));
    console.info(TAG, 'serviceDatas: ' + JSON.stringify(serviceDatas));
  }

  private parseServiceUuid(uuidLength: number, curPos: number, advDataLength: number,
    advData: Uint8Array, serviceUuids: string[]) {
    while (advDataLength > 0) {
      let tmpData: Uint8Array = advData.slice(curPos, curPos + uuidLength);
      serviceUuids.push(this.getUuidFromUint8Array(uuidLength, tmpData));
      advDataLength -= uuidLength;
      curPos += uuidLength;
    }
  }

  private parseServiceSolicitationUuid(uuidLength: number, curPos: number, advDataLength: number,
    advData: Uint8Array, serviceSolicitationUuids: string[]) {
    while (advDataLength > 0) {
      let tmpData: Uint8Array = advData.slice(curPos, curPos + uuidLength);
      serviceSolicitationUuids.push(this.getUuidFromUint8Array(uuidLength, tmpData));
      advDataLength -= uuidLength;
      curPos += uuidLength;
    }
  }

  private getUuidFromUint8Array(uuidLength: number, uuidData: Uint8Array): string {
    let uuid = "";
    let temp: string = "";
    for (let i = uuidLength - 1; i > -1; i--) {
      temp += uuidData[i].toString(16).padStart(2, "0");
    }
    switch (uuidLength) {
      case BLUETOOTH_UUID_16_BIT_LENGTH:
        uuid = `0000${temp}-0000-1000-8000-00805F9B34FB`;
        break;
      case BLUETOOTH_UUID_32_BIT_LENGTH:
        uuid = `${temp}-0000-1000-8000-00805F9B34FB`;
        break;
      case BLUETOOTH_UUID_128_BIT_LENGTH:
        uuid = `${temp.substring(0, 8)}-${temp.substring(8, 12)}-${temp.substring(12, 16)}-${temp.substring(16, 20)}-${temp.substring(20, 32)}`;
        break;
      default:
        break;
    }
    return uuid;
  }

  private parseServiceData(uuidLength: number, curPos: number, advDataLength: number,
    advData: Uint8Array, serviceDatas: Record<number, Uint8Array>) {
    let uuid: Uint8Array = advData.slice(curPos, curPos + uuidLength);
    let data: Uint8Array = advData.slice(curPos + uuidLength, curPos + advDataLength);
    serviceDatas[this.getUuidFromUint8Array(uuidLength, uuid)] = data;
  }

  private parseManufactureData(curPos: number, advDataLength: number,
    advData: Uint8Array, manufactureSpecificDatas: Record<number, Uint8Array>) {
    let manufactureId: number = (advData[curPos + 1] << 8) + advData[curPos];
    let data: Uint8Array = advData.slice(curPos + BLUETOOTH_MANUFACTURE_ID_LENGTH, curPos + advDataLength);
    manufactureSpecificDatas[manufactureId] = data;
  }

  // 2. 开启扫描
  public startScan() {
    // 2.1 构造扫描BLE广播的过滤条件，目标BLE广播报文需符合该过滤条件
    let manufactureId = 4567;
    let manufactureData: Uint8Array = new Uint8Array([1, 2, 3, 4]);
    let manufactureDataMask: Uint8Array = new Uint8Array([0xFF, 0xFF, 0xFF, 0xFF]);
    let scanFilter: ble.ScanFilter = { // 根据业务实际情况定义过滤器
      manufactureId: manufactureId,
      manufactureData: manufactureData.buffer,
      manufactureDataMask: manufactureDataMask.buffer
    };

    // 2.2 构造扫描配置参数
    let scanOptions: ble.ScanOptions = {
      interval: 0,
      dutyMode: ble.ScanDuty.SCAN_MODE_LOW_POWER,
      matchMode: ble.MatchMode.MATCH_MODE_AGGRESSIVE
    }
    try {
      // 发起订阅
      this.bleScanner.on('BLEDeviceFind', this.onReceiveEvent);
      // 发起扫描
      this.bleScanner.startScan([scanFilter], scanOptions);
      console.info('startBleScan success');
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 3. 关闭扫描
  public stopScan() {
    try {
      // 取消订阅
      this.bleScanner.off('BLEDeviceFind', this.onReceiveEvent);
      // 停止扫描
      this.bleScanner.stopScan();
      console.info('stopBleScan success');
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }
}

let bleScanManager = new BleScanManager();
export default bleScanManager as BleScanManager;
```

### BLE广播流程
```ts
import { ble } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = 'BleAdvertisingManager';

export class BleAdvertisingManager {
  private advHandle: number = 0xFF; // 初始的无效值

  // 1. 定义广播状态上报事件
  onReceiveEvent = (data: ble.AdvertisingStateChangeInfo) => {
    console.info(TAG, 'bluetooth advertising state = ' + JSON.stringify(data));
    AppStorage.setOrCreate('advertiserState', data.state);
  };

  // 2. 首次启动广播
  public async startAdvertising() {
    // 2.1 设置广播发送的参数
    let setting: ble.AdvertiseSetting = {
      interval: 160,
      txPower: 0,
      connectable: true
    };
    // 2.2 构造广播数据
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
    let manufactureDataUnit: ble.ManufactureData = {
      manufactureId: 4567,
      manufactureValue: manufactureValueBuffer.buffer
    };
    let serviceDataUnit1: ble.ServiceData = {
      serviceUuid: "00001999-0000-1000-8000-00805f9b34fb",
      serviceValue: serviceValueBuffer.buffer
    };
    let serviceDataUnit2: ble.ServiceData = {
      serviceUuid: "19991999-0000-1000-8000-00805f9b34fb",
      serviceValue: serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
      serviceUuids: ["00001888-0000-1000-8000-00805f9b34fb", "18881888-0000-1000-8000-00805f9b34fb"],
      manufactureData: [manufactureDataUnit],
      serviceData: [],
      includeDeviceName: false // 表示是否携带设备名，可选参数。注意：带上设备名时，容易导致广播报文长度超出31个字节，使得广播启动失败
    };
    let advResponse: ble.AdvertiseData = {
      serviceUuids: [],
      manufactureData: [],
      serviceData: [serviceDataUnit1, serviceDataUnit2]
    };
    // 2.3 构造广播启动完整参数AdvertisingParams
    let advertisingParams: ble.AdvertisingParams = {
      advertisingSettings: setting,
      advertisingData: advData, // 注意: 广播报文长度不能超过31个字节
      advertisingResponse: advResponse, // 注意: 广播报文长度不能超过31个字节
      duration: 0 // 可选参数，若参数大于0，则广播发送一段时间后会停止，但分配的广播资源还在，可重新启动发送
    }

    // 2.4 首次启动广播，蓝牙子系统会分配相关资源，包括应用获取到的广播标识ID
    try {
      ble.on('advertisingStateChange', this.onReceiveEvent);
      this.advHandle = await ble.startAdvertising(advertisingParams);
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 3. 停止指定标识的广播，即首次启动时分配的标识，停止后，该路广播资源仍然存在
  public async disableAdvertising() {
    // 3.1 构造停止广播参数
    let advertisingDisableParams: ble.AdvertisingDisableParams = {
      advertisingId: this.advHandle // 使用首次启动广播时获取到的广播标识ID
    }
    try {
      // 3.2 停止
      await ble.disableAdvertising(advertisingDisableParams);
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 4. 启动指定标识的广播，即首次启动时分配的标识
  public async enableAdvertising(enableDuration: number) {
    // 4.1 构造启动广播参数
    let advertisingEnableParams: ble.AdvertisingEnableParams = {
      advertisingId: this.advHandle, // 使用首次启动广播时获取到的广播标识ID
      duration: enableDuration
    }
    try {
      // 4.2 再次启动
      await ble.enableAdvertising(advertisingEnableParams);
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 5. 完全停止广播，释放广播资源
  public async stopAdvertising() {
    try {
      await ble.stopAdvertising(this.advHandle);
      ble.off('advertisingStateChange', this.onReceiveEvent);
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }
}

let bleAdvertisingManager = new BleAdvertisingManager();
export default bleAdvertisingManager as BleAdvertisingManager;
```