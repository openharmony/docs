# 广播与扫描开发指导

## 简介
广播与扫描，主要提供了蓝牙设备的开启广播、关闭广播、开启扫描、关闭扫描方法，通过广播和扫描发现对端蓝牙设备，实现低功耗的通信。

## 场景介绍
主要场景有：

- 开启、关闭广播
- 开启、关闭扫描

## 接口说明

完整的 JS API 说明以及实例代码请参考：[BLE 接口](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md)。

具体接口说明如下表。

| 接口名                             | 功能描述                                                                       |
| ---------------------------------- | ------------------------------------------------------------------------------ |
| startBLEScan()                     | 发起BLE扫描流程。                                                               |
| stopBLEScan()                      | 停止BLE扫描流程。                                                                |
| startAdvertising()                 | 开始发送BLE广播。                                                                |
| disableAdvertising()                | 临时停止BLE广播。                                                                |
| enableAdvertising()                | 临时启动BLE广播。                                                                |
| stopAdvertising()                  | 停止发送BLE广播。                                                                |
| on(type: 'advertisingStateChange') | 订阅BLE广播状态。                                                                |
| off(type: 'advertisingStateChange')| 取消订阅BLE广播状态。                                                            |
| on(type: 'BLEDeviceFind')          | 订阅BLE设备发现上报事件。                                                        |
| off(type: 'BLEDeviceFind')         | 取消订阅BLE设备发现上报事件。                                                     |

## 主要场景开发步骤

### 开启、关闭广播
1. import需要的ble模块。
2. 开启设备的蓝牙。
3. 需要SystemCapability.Communication.Bluetooth.Core系统能力。
4. 开启广播，对端设备扫描该广播。
5. 关闭广播。
6. 示例代码：

```ts
import { ble } from '@kit.ConnectivityKit';
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';

export class BleAdvertisingManager {
  private advHandle: number = 0xFF; // default invalid value

  // 1 订阅广播状态
  public onAdvertisingStateChange() {
    try {
      ble.on('advertisingStateChange', (data: ble.AdvertisingStateChangeInfo) {
        console.info('bluetooth advertising state = ' + JSON.stringify(data));
      });
    } catch (err) {
        console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 2 首次启动广播
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
    let serviceDataUnit: ble.ServiceData = {
      serviceUuid: "00001888-0000-1000-8000-00805f9b34fb",
      serviceValue: serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
      serviceUuids: ["00001888-0000-1000-8000-00805f9b34fb"],
      manufactureData: [manufactureDataUnit],
      serviceData: [serviceDataUnit],
      includeDeviceName: false // 表示是否携带设备名，可选参数。注意带上设备名时广播包长度不能超出31个字节。
    };
    let advResponse: ble.AdvertiseData = {
      serviceUuids: ["00001888-0000-1000-8000-00805f9b34fb"],
      manufactureData: [manufactureDataUnit],
      serviceData: [serviceDataUnit]
    };
    // 2.3 构造广播启动完整参数AdvertisingParams
    let advertisingParams: ble.AdvertisingParams = {
      advertisingSettings: setting,
      advertisingData: advData,
      advertisingResponse: advResponse,
      duration: 0 // 可选参数，若大于0，则广播发送一段时间后，则会临时停止，可重新启动发送
    }

    // 2.4 首次启动广播，且获取所启动广播的标识ID
    try {
      this.advHandle = await ble.startAdvertising(advertisingParams);
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 4 临时停止广播，该广播资源仍然存在
  public async disableAdvertising() {
    // 4.1 构造临时停止广播参数
    let advertisingDisableParams: ble.AdvertisingDisableParams = {
      advertisingId: this.advHandle // 使用首次启动广播时获取到的广播标识ID
    }
    // 4.2 临时停止
    try {
      await ble.disableAdvertising(advertisingDisableParams);
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 5 再次启动广播
  public async enableAdvertising() {
    // 5.1 构造临时启动广播参数
    let advertisingEnableParams: ble.AdvertisingEnableParams = {
      advertisingId: this.advHandle, // 使用首次启动广播时获取到的广播标识ID
      duration: 0
    }
    // 5.2 再次启动
    try {
      await ble.enableAdvertising(advertisingEnableParams);
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 6 完全关闭广播，释放广播资源
  public async stopAdvertising() {
    try {
      await ble.stopAdvertising(this.advHandle);
      ble.off('advertisingStateChange', (data: ble.AdvertisingStateChangeInfo) {
        console.info('bluetooth advertising state = ' + JSON.stringify(data));
      });
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }
}

let bleAdvertisingManager = new BleAdvertisingManager();
export default bleAdvertisingManager as BleAdvertisingManager;
```

7. 错误码请参见[蓝牙服务子系统错误码](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md)。
8. 如何验证：执行开启广播的用例代码，记录日志“startAdvertising success”，并且使用另外一部手机安装nrfConnect软件开启扫描，如果扫描到该广播，广播内容“Manufacturer data的值为:0x01020304，Service Data的值为:0x05060708”，表示开启广播成功。关闭广播后，扫描不到该内容的广播。

### 开启、关闭扫描
1. import需要的ble模块。
2. 开启设备的蓝牙。
3. 需要SystemCapability.Communication.Bluetooth.Core系统能力。
4. 对端设备开启广播。
5. 本端设备开启扫描，获取扫描结果。
6. 关闭扫描。
7. 示例代码:

```ts
import { ble } from '@kit.ConnectivityKit';
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';

export class BleScanManager {
  // 1 订阅扫描结果
  public onScanResult() {
    ble.on('BLEDeviceFind', (data) => {
      if (data.length > 0) {
        console.info('BLE scan result = ' + data[0].deviceName);
      }
    });
  }

  // 2 开启扫描
  public startScan() {
    // 2.1 构造扫描过滤器，需要能够匹配预期的广播包内容
    let scanFilter: ble.ScanFilter = {
      name: 'BLESCAN'  // 如以该名字过滤，那么发广播端需要包含该名字
    };

    // 2.2 构造扫描参数
    let scanOptions: ble.ScanOptions = {
      interval: 0,
      dutyMode: ble.ScanDuty.SCAN_MODE_LOW_POWER,
      matchMode: ble.MatchMode.MATCH_MODE_AGGRESSIVE,
      phyType: ble.PhyType.PHY_LE_1M
    }
    ble.startBLEScan([scanFilter], scanOptions);
    console.info('startBleScan success');
  }

  // 3 关闭扫描
  public stopScan() {
    ble.stopBLEScan();
    console.info('stopBleScan success');
  }
}

let bleScanManager = new BleScanManager();
export default bleScanManager as BleScanManager;
```

8. 错误码请参见[蓝牙服务子系统错误码](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md)。
9. 如何验证：使用另外一部手机安装nrfConnect软件并且配置好广播，设备名称修改为“Jackistang”，开启广播。然后测试手机开启扫描，大概每隔0.5秒记录日志“BLE scan result =  = Jackistang”，则表示开启扫描成功。关闭扫描后，不会再有该记录日志产生。