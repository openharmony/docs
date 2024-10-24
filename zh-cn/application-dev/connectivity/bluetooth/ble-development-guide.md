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

    const TAG: string = 'BleAdvertisingManager';

    export class BleAdvertisingManager {
      private advHandle: number = 0xFF; // default invalid value

      // 1 订阅广播状态
      public onAdvertisingStateChange() {
        try {
          ble.on('advertisingStateChange', (data: ble.AdvertisingStateChangeInfo) => {
            console.info(TAG, 'bluetooth advertising state = ' + JSON.stringify(data));
            AppStorage.setOrCreate('advertiserState', data.state);
          });
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
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
          this.onAdvertisingStateChange();
          this.advHandle = await ble.startAdvertising(advertisingParams);
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
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
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }

      // 5 再次启动广播
      public async enableAdvertising(enableDuration: number) {
        // 5.1 构造临时启动广播参数
        let advertisingEnableParams: ble.AdvertisingEnableParams = {
          advertisingId: this.advHandle, // 使用首次启动广播时获取到的广播标识ID
          duration: enableDuration
        }
        // 5.2 再次启动
        try {
          await ble.enableAdvertising(advertisingEnableParams);
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }

      // 6 完全关闭广播，释放广播资源
      public async stopAdvertising() {
        try {
          await ble.stopAdvertising(this.advHandle);
          ble.off('advertisingStateChange', (data: ble.AdvertisingStateChangeInfo) => {
            console.info(TAG, 'bluetooth advertising state = ' + JSON.stringify(data));
          });
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    }

    let bleAdvertisingManager = new BleAdvertisingManager();
    export default bleAdvertisingManager as BleAdvertisingManager;
    ```

7. 错误码请参见[蓝牙服务子系统错误码](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md)。

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

    const TAG: string = 'BleScanManager';
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
      // 1 订阅扫描结果
      public onScanResult() {
        ble.on('BLEDeviceFind', (data: Array<ble.ScanResult>) => {
          if (data.length > 0) {
            console.info(TAG, 'BLE scan result = ' + data[0].deviceId);
            this.parseScanResult(data[0].data);
          }
        });
      }

      private parseScanResult(data: ArrayBuffer) {
        let advData = new Uint8Array(data);
        if (advData.byteLength == 0) {
          console.warn(TAG, 'nothing, adv data length is 0');
          return;
        }
        console.info(TAG, 'advData: ' + JSON.stringify(advData));

        let advFlags: number = -1;
        let txPowerLevel: number = -1;
        let localName: string = "";
        let serviceUuids: string[] = [];
        let serviceSolicitationUuids: string[] = [];
        let serviceDatas: Record<string, Uint8Array> = {};
        let manufactureSpecificDatas: Record<number, Uint8Array> = {};

        let curPos = 0;
        while (curPos < advData.byteLength) {
          let length = advData[curPos++];
          if (length == 0) {
            break;
          }
          let advDataLength = length - 1;
          let advDataType = advData[curPos++];
          switch (advDataType) {
            case BLE_ADV_TYPE_FLAG:
              advFlags = advData[curPos];
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
          curPos += advDataLength;
        }
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
        advData: Uint8Array, serviceDatas: Record<string, Uint8Array>) {
        let tmpUuid: Uint8Array = advData.slice(curPos, curPos + uuidLength);
        let tmpValue: Uint8Array = advData.slice(curPos + uuidLength, curPos + advDataLength);
        serviceDatas[tmpUuid.toString()] = tmpValue;
      }

      private parseManufactureData(curPos: number, advDataLength: number,
        advData: Uint8Array, manufactureSpecificDatas: Record<number, Uint8Array>) {
        let manufactureId: number = (advData[curPos + 1] << 8) + advData[curPos];
        let tmpValue: Uint8Array = advData.slice(curPos + BLUETOOTH_MANUFACTURE_ID_LENGTH, curPos + advDataLength);
        manufactureSpecificDatas[manufactureId] = tmpValue;
      }

      // 2 开启扫描
      public startScan() {
        // 2.1 构造扫描过滤器，需要能够匹配预期的广播包内容
        let manufactureId = 4567;
        let manufactureData: Uint8Array = new Uint8Array([1, 2, 3, 4]);
        let manufactureDataMask: Uint8Array = new Uint8Array([0xFF, 0xFF, 0xFF, 0xFF]);
        let scanFilter: ble.ScanFilter = { // 根据业务实际情况定义过滤器
          manufactureId: manufactureId,
          manufactureData: manufactureData.buffer,
          manufactureDataMask: manufactureDataMask.buffer
        };

        // 2.2 构造扫描参数
        let scanOptions: ble.ScanOptions = {
          interval: 0,
          dutyMode: ble.ScanDuty.SCAN_MODE_LOW_POWER,
          matchMode: ble.MatchMode.MATCH_MODE_AGGRESSIVE
        }
        try {
          this.onScanResult(); // 订阅扫描结果
          ble.startBLEScan([scanFilter], scanOptions);
          console.info(TAG, 'startBleScan success');
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }

      // 3 关闭扫描
      public stopScan() {
        try {
          ble.off('BLEDeviceFind', (data: Array<ble.ScanResult>) => { // 取消订阅扫描结果
            console.info(TAG, 'off success');
          });
          ble.stopBLEScan();
          console.info(TAG, 'stopBleScan success');
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    }

    let bleScanManager = new BleScanManager();
    export default bleScanManager as BleScanManager;
    ```

8. 错误码请参见[蓝牙服务子系统错误码](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md)。