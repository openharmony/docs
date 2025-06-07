# 蓝牙子系统Changelog

## cl.bluetooth.1 蓝牙BLE接口错误码变更


**访问级别**

公开接口

**变更原因**

蓝牙子系统BLE相关接口错误码不够清晰，开发者无法通过错误信息明确需要如何修复问题，影响开发效率。

**变更影响**

此变更涉及应用适配。

变更前：BLE广播、BLE扫描、GATT Client、GATT Server接口异常时仅返回2900099错误码。

变更后：BLE广播、BLE扫描、GATT Client、GATT Server接口异常时会返回更详细的错误码。

**起始API Level**

10

**变更发生版本**

从OpenHarmony SDK 6.0.0.32开始。

**变更的接口/组件**

| 模块名                                | 命名空间                | 类名 | 接口声明                                                   |主要变更点说明    |
| ------------------------------------ | ------------------- | -- | ------------------------------------------------------------ | -------------- |
| @ohos.bluetooth.ble.d.ts       | ble             |  | function startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void; | 新增2900010错误码：广播资源已耗尽；<br>新增2902054错误码：广播报文数据长度超限； |
| @ohos.bluetooth.ble.d.ts       | ble        |  | function startAdvertising(advertisingParams: AdvertisingParams, callback: AsyncCallback&lt;number&gt;): void; | 新增2900010错误码：广播资源已耗尽；<br>新增2902054错误码：广播报文数据长度超限；  |
| @ohos.bluetooth.ble.d.ts       | ble        |  | function startAdvertising(advertisingParams: AdvertisingParams): Promise&lt;number&gt;; | 新增2900010错误码：广播资源已耗尽；<br>新增2902054错误码：广播报文数据长度超限；  |
| @ohos.bluetooth.ble.d.ts       | ble        |  | function enableAdvertising(advertisingEnableParams: AdvertisingEnableParams, callback: AsyncCallback&lt;void&gt;): void; | 新增2902055错误码：无效的广播ID；  |
| @ohos.bluetooth.ble.d.ts       | ble        |  | function enableAdvertising(advertisingEnableParams: AdvertisingEnableParams): Promise&lt;void&gt;; | 新增2902055错误码：无效的广播ID；  |
| @ohos.bluetooth.ble.d.ts       | ble        |  | function disableAdvertising(advertisingDisableParams: AdvertisingDisableParams, callback: AsyncCallback&lt;void&gt;): void; | 新增2902055错误码：无效的广播ID；  |
| @ohos.bluetooth.ble.d.ts       | ble        |  | function disableAdvertising(advertisingDisableParams: AdvertisingDisableParams): Promise&lt;void&gt;; | 新增2902055错误码：无效的广播ID；  |
| @ohos.bluetooth.ble.d.ts       | ble        |  | function stopAdvertising(advertisingId: number, callback: AsyncCallback&lt;void&gt;): void; | 新增2902055错误码：无效的广播ID；  |
| @ohos.bluetooth.ble.d.ts       | ble        |  | function stopAdvertising(advertisingId: number): Promise&lt;void&gt;; | 新增2902055错误码：无效的广播ID；  |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback&lt;BLECharacteristic&gt;): void; | 新增2900011错误码：操作忙碌，需等待上一次操作结束；<br>新增2901000错误码：读失败，对端禁止读操作；<br>新增2901003错误码：读失败，未与对端建立连接；<br>新增2901004错误码：读失败，连接链路拥塞；<br>新增2901005错误码：读失败，连接链路未加密；<br>新增2901006错误码：读失败，连接链路未认证；<br>新增2901007错误码：读失败，连接链路未授权；  |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | readCharacteristicValue(characteristic: BLECharacteristic): Promise&lt;BLECharacteristic&gt;; | 新增2900011错误码：操作忙碌，需等待上一次操作结束；<br>新增2901000错误码：读失败，对端禁止读操作；<br>新增2901003错误码：读失败，未与对端建立连接；<br>新增2901004错误码：读失败，连接链路拥塞；<br>新增2901005错误码：读失败，连接链路未加密；<br>新增2901006错误码：读失败，连接链路未认证；<br>新增2901007错误码：读失败，连接链路未授权；  |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback&lt;BLEDescriptor&gt;): void; | 新增2900011错误码：操作忙碌，需等待上一次操作结束；<br>新增2901000错误码：读失败，对端禁止读操作；<br>新增2901003错误码：读失败，未与对端建立连接；<br>新增2901004错误码：读失败，连接链路拥塞；<br>新增2901005错误码：读失败，连接链路未加密；<br>新增2901006错误码：读失败，连接链路未认证；<br>新增2901007错误码：读失败，连接链路未授权；  |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | readDescriptorValue(descriptor: BLEDescriptor): Promise&lt;BLEDescriptor&gt;; | 新增2900011错误码：操作忙碌，需等待上一次操作结束；<br>新增2901000错误码：读失败，对端禁止读操作；<br>新增2901003错误码：读失败，未与对端建立连接；<br>新增2901004错误码：读失败，连接链路拥塞；<br>新增2901005错误码：读失败，连接链路未加密；<br>新增2901006错误码：读失败，连接链路未认证；<br>新增2901007错误码：读失败，连接链路未授权；  |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | writeCharacteristicValue(characteristic: BLECharacteristic, writeType: GattWriteType, callback: AsyncCallback&lt;void> ): void; | 新增2900011错误码：操作忙碌，需等待上一次操作结束；<br>新增2901001错误码：写失败，对端禁止写操作；<br>新增2901003错误码：写失败，未与对端建立连接；<br>新增2901004错误码：写失败，连接链路拥塞；<br>新增2901005错误码：写失败，连接链路未加密；<br>新增2901006错误码：写失败，连接链路未认证；<br>新增2901007错误码：写失败，连接链路未授权；   |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | writeCharacteristicValue(characteristic: BLECharacteristic, writeType: GattWriteType): Promise&lt;void&gt;; | 新增2900011错误码：操作忙碌，需等待上一次操作结束；<br>新增2901001错误码：写失败，对端禁止写操作；<br>新增2901003错误码：写失败，未与对端建立连接；<br>新增2901004错误码：写失败，连接链路拥塞；<br>新增2901005错误码：写失败，连接链路未加密；<br>新增2901006错误码：写失败，连接链路未认证；<br>新增2901007错误码：写失败，连接链路未授权；   |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | writeDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback&lt;void&gt;): void; | 新增2900011错误码：操作忙碌，需等待上一次操作结束；<br>新增2901001错误码：写失败，对端禁止写操作；<br>新增2901003错误码：写失败，未与对端建立连接；<br>新增2901004错误码：写失败，连接链路拥塞；<br>新增2901005错误码：写失败，连接链路未加密；<br>新增2901006错误码：写失败，连接链路未认证；<br>新增2901007错误码：写失败，连接链路未授权；   |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | writeDescriptorValue(descriptor: BLEDescriptor): Promise&lt;void&gt;; | 新增2900011错误码：操作忙碌，需等待上一次操作结束；<br>新增2901001错误码：写失败，对端禁止写操作；<br>新增2901003错误码：写失败，未与对端建立连接；<br>新增2901004错误码：写失败，连接链路拥塞；<br>新增2901005错误码：写失败，连接链路未加密；<br>新增2901006错误码：写失败，连接链路未认证；<br>新增2901007错误码：写失败，连接链路未授权；   |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | getRssiValue(callback: AsyncCallback&lt;number&gt;): void; | 新增2900011错误码：操作忙碌，需等待上一次操作结束；<br>新增2901003错误码：未与对端建立连接； |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | getRssiValue(): Promise&lt;number&gt;; | 新增2900011错误码：操作忙碌，需等待上一次操作结束；<br>新增2901003错误码：未与对端建立连接； |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | setCharacteristicChangeNotification(characteristic: BLECharacteristic, enable: boolean, callback: AsyncCallback&lt;void&gt;): void; | 新增2900011错误码：操作忙碌，需等待上一次操作结束；<br>新增2901003错误码：未与对端建立连接； |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | setCharacteristicChangeNotification(characteristic: BLECharacteristic, enable: boolean): Promise&lt;void&gt;; | 新增2900011错误码：操作忙碌，需等待上一次操作结束；<br>新增2901003错误码：未与对端建立连接； |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | setCharacteristicChangeIndication( characteristic: BLECharacteristic, enable: boolean, callback: AsyncCallback&lt;void&gt;): void; | 新增2900011错误码：操作忙碌，需等待上一次操作结束；<br>新增2901003错误码：未与对端建立连接； |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | setCharacteristicChangeIndication(characteristic: BLECharacteristic, enable: boolean): Promise&lt;void&gt;; | 新增2900011错误码：操作忙碌，需等待上一次操作结束；<br>新增2901003错误码：未与对端建立连接； |

**适配指导**

应用可将接口调用的错误码打印出来，辅助定位问题。

以广播报文数据超过最大长度限制导致开启BLE广播失败为例：

```ts
let advSettings: ble.AdvertiseSetting = {
  "interval": 160,
  "connectable": true,
};
// 1）开发者构造的广播报文数据长度超过最大长度限制
let serviceUuidsArray: Array<string> = new Array();
serviceUuidsArray.push("00001111-1111-1000-8000-00805f9b34fb");
serviceUuidsArray.push("00001111-2222-1000-8000-00805f9b34fb");
serviceUuidsArray.push("00001111-3333-1000-8000-00805f9b34fb");
let advData: ble.AdvertiseData = {
  "serviceUuids": serviceUuidsArray,
  "manufactureData": new Array(),
  "serviceData": new Array(),
  "includeDeviceName": true,
};

try {
  ble.startAdvertising(advSettings, advData);
} catch (err) {
  // 2）通过日志打印发现接口调用报错2902054，即表示广播报文数据长度超过最大长度限制
  console.error("errCode: " + err.code + ", errMessage: " + err.message);
}
// 3）开发者根据错误码确定广播报文构造方式的合理性。建议：
//  - 是否有必要携带本机蓝牙设备名
//  - 是否将部分广播报文构造成入参advResponse
```
