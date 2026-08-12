# @ohos.bluetooth.ble (蓝牙ble模块)(系统接口)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

本模块提供了基于低功耗蓝牙（Bluetooth Low Energy，[BLE](../../connectivity/bluetooth/terminology.md#ble)）技术的蓝牙能力，首批接口包括基于通用属性协议（Generic Attribute Profile，[GATT](../../connectivity/bluetooth/terminology.md#gatt)）的写特征值方法。

> **说明：**
>
> - 本模块首批接口从API version 23开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.bluetooth.ble (蓝牙ble模块)](js-apis-bluetooth-ble.md)。



## 导入模块

```js
import { ble } from '@kit.ConnectivityKit';
```

## GattClientDevice

GATT客户端类，提供了和服务端进行连接和数据传输等操作方法。

- 使用该类的方法前，需通过[createGattClientDevice](js-apis-bluetooth-ble.md#blecreategattclientdevice)方法构造该类的实例。
- 通过创建不同的该类实例，可以管理多路GATT连接。

### writeCharacteristicValueWithContext

writeCharacteristicValueWithContext(characteristic: BLECharacteristic, writeType: GattWriteType): Promise&lt;GattRspContext&gt;

client端向指定的server端特征值写入数据。使用Promise异步回调。<br>
- 与[writeCharacteristicValue](js-apis-bluetooth-ble.md#writecharacteristicvalue)接口不同，此接口新增了返回server端响应信息的功能。在完成特征值写入操作后，调用方可以获取本端接收到server端回复消息的时间戳等信息。
- 为获取server端的响应信息，此接口仅支持writeType为[WRITE](js-apis-bluetooth-ble.md#gattwritetype)的写入模式。
- 需要先调用[getServices](js-apis-bluetooth-ble.md#getservices)，获取到server端所有支持的能力，且包含指定的入参特征值UUID；否则会写入失败。<br>
- 异步回调结果返回后，才能调用下一次读取或者写入操作，如[readCharacteristicValue](js-apis-bluetooth-ble.md#readcharacteristicvalue)、[readDescriptorValue](js-apis-bluetooth-ble.md#readdescriptorvalue)、[writeCharacteristicValue](js-apis-bluetooth-ble.md#writecharacteristicvalue)、[writeDescriptorValue](js-apis-bluetooth-ble.md#writedescriptorvalue)、[setCharacteristicChangeNotification](js-apis-bluetooth-ble.md#setcharacteristicchangenotification)和[setCharacteristicChangeIndication](js-apis-bluetooth-ble.md#setcharacteristicchangeindication)。<br>
- 应用单次可写入的特征值数据长度限制为（MTU-3）字节。调用方可根据实际需要通过[setBLEMtuSize](js-apis-bluetooth-ble.md#setblemtusize)接口指定MTU大小，进而修改单次可写入的特征值数据长度。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名            | 类型                                      | 必填   | 说明                  |
| -------------- | --------------------------------------- | ---- | ------------------- |
| characteristic | [BLECharacteristic](js-apis-bluetooth-ble.md#blecharacteristic) | 是    | 需要写入的特征值，包含写入的数据内容。 |
| writeType | [GattWriteType](js-apis-bluetooth-ble.md#gattwritetype) | 是    | 写入特征值的方式。 |

**返回值：**

| 类型                                       | 说明                         |
| ---------------------------------------- | -------------------------- |
| Promise&lt;GattRspContext&gt; | Promise对象，返回[GattRspContext](#gattrspcontext)对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs.                 |
|801 | Capability not supported.          |
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
    device.writeCharacteristicValueWithContext(characteristic, ble.GattWriteType.WRITE).then((rspContext: ble.GattRspContext) => {
        console.info('timestamp is: ' + rspContext.timestamp);
    });
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## GattRspContext

client端调用[writeCharacteristicValueWithContext](#writecharacteristicvaluewithcontext)等接口并接收到server端的回复消息后，蓝牙子系统上报给应用的信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称       | 类型        | 只读 | 可选   | 说明                                 |
| -------- | ----------- | ---- | ---- | ---------------------------------- |
| timestamp     | number      | 否 | 否    | 本端接收到对端GATT回复消息的时间点，格式为微秒级的UNIX时间戳。                    |

## ScanFilter

扫描BLE广播的过滤条件，只有符合该条件的广播报文才会上报。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                                     | 类型    | 只读 | 可选  | 说明                                                         |
| ------------------------------------------ | -------- | ---- | ---- | ------------------------------------------------------------ |
| irk<sup>23+</sup> | Uint8Array | 否 | 是 | 通过蓝牙设备地址解析密钥（Identity Resolving Key, IRK）过滤携带可解析私有地址([BluetoothRawAddressType](./js-apis-bluetooth-common.md#bluetoothrawaddresstype23))的BLE广播报文。<br>蓝牙设备的可解析私有地址会随时间变化，若已知该设备的IRK和Public类型地址或者Static Random类型的地址，即可过滤同一个蓝牙设备在不同时间发出的BLE广播报文。<br>使用本参数时，必须同时通过[ScanFilter](js-apis-bluetooth-ble.md#scanfilter)中的address参数指定地址和地址类型等信息。其中，地址必须为有效的Public类型地址或Static Random类型地址，[addressType](js-apis-bluetooth-common.md#bluetoothaddresstype)必须设置为REAL，[rawAddressType](js-apis-bluetooth-common.md#bluetoothrawaddresstype23)必须根据address的实际情况进行设置。<br>**系统接口**：此接口为系统接口。|