# @ohos.bluetooth.bas (蓝牙bas模块)(系统接口)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

bas模块提供了访问BAS（Battery Service，电量服务）相关能力的方法，包括读取远端设备电量信息、监听远端设备电量信息变化等。

**起始版本**：26.0.0


## 导入模块

```js
import { bas } from '@kit.ConnectivityKit';
```


## bas.isBasSupported

isBasSupported(): boolean

判断本机设备是否可以获取远端设备的电量。

**起始版本**：26.0.0

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**返回值**：

| 类型     | 说明                                                   |
| ------ | ---------------------------------------------------- |
| boolean | 返回true表示本机支持获取远端设备的电量；返回false表示本机不支持获取远端设备的电量。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|202 | Non-system applications are not allowed to use system APIs.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
try {
    let isSupported: boolean = bas.isBasSupported();
    console.info('isBasSupported: ' + isSupported);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```


## bas.getRemoteDeviceBatteryInfo

getRemoteDeviceBatteryInfo(deviceId: BluetoothAddress): Promise&lt;BatteryInfo&gt;

查询远端设备的电量信息。
- 使用此接口前建议使用[isBasSupported](#basisbassupported)查询本机是否支持获取远端设备的电量。
- 只有支持蓝牙标准协议定义的电量服务（UUID：0000180F-0000-1000-8000-00805F9B34FB）的BLE远端设备才支持获取电量信息。
- 对端蓝牙设备的电量信息变更通过[onBatteryChange](#basonbatterychange)的回调结果获取。
- 此接口支持使用对端设备的实际MAC地址和随机MAC地址获取电量信息。

**起始版本**：26.0.0

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名            | 类型                                      | 必填   | 说明                  |
| -------------- | --------------------------------------- | ---- | ------------------- |
| deviceId | [BluetoothAddress](js-apis-bluetooth-common.md#bluetoothaddress) | 是    | 表示远端设备的地址信息。<br>- BluetoothAddress中的address、addressType、rawAddressType均为必选参数。 |

**返回值**：

| 类型                                       | 说明                         |
| ---------------------------------------- | -------------------------- |
| Promise&lt;[BatteryInfo](#batteryinfo)&gt; | Promise对象，返回远端设备的电量信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.             |
|2900003 | Bluetooth disabled.                |
|2900004 | Remote device profile not supported.                |
|2900099 | Operation failed. Possible causes: 1. Unregistered bas observer. 2. Bas observers exceeds the limit. 3. Bas request busy.                 |
|2901003 | Connection not established.                |

**示例**：

```js
import { common } from '@kit.ConnectivityKit';

let deviceId: common.BluetoothAddress = {
    address:"11:22:33:44:55:66",
    addressType:common.BluetoothAddressType.REAL,
    rawAddressType:common.BluetoothRawAddressType.PUBLIC
}
try {
    bas.getRemoteDeviceBatteryInfo(deviceId).then((batteryInfo: bas.BatteryInfo) => {
        console.info('getRemoteDeviceBatteryInfo, batteryInfo: [address: ' + batteryInfo.deviceId.address +
            ', batteryLevel: ' + batteryInfo.batteryLevel + ']');
    });
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```


## bas.onBatteryChange

onBatteryChange(callback: Callback&lt;BatteryInfo&gt;): void

订阅远端设备电量状态变化事件。
- 只有支持蓝牙标准协议定义的电量服务（UUID：0000180F-0000-1000-8000-00805F9B34FB）的BLE远端设备才支持上报电量信息，不可与[connection.on('batteryChange')](js-apis-bluetooth-connection.md#connectiononbatterychange12)混用。
- 调用此接口会立即上报已连接电量服务设备的最新有效电量信息，后续仅当远端设备电量信息发生变化时上报电量信息。

**起始版本**：26.0.0

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名            | 类型                                      | 必填   | 说明                  |
| -------------- | --------------------------------------- | ---- | ------------------- |
| callback | Callback&lt;[BatteryInfo](#batteryinfo)&gt; | 是    | 回调函数，返回电量信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例**：

```js
let onReceiveEvent: (data: bas.BatteryInfo) => void = (data: bas.BatteryInfo) => {
    console.info(`address: ${data.deviceId.address}, batteryLevel: ${data.batteryLevel}`);
}
try {
    bas.onBatteryChange(onReceiveEvent);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```


## bas.offBatteryChange

offBatteryChange(callback?: Callback&lt;BatteryInfo&gt;): void

取消订阅远端设备电量状态变化事件。

不可与[connection.off('batteryChange')](js-apis-bluetooth-connection.md#connectionoffbatterychange12)混用。

**起始版本**：26.0.0

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名            | 类型                                      | 必填   | 说明                  |
| -------------- | --------------------------------------- | ---- | ------------------- |
| callback | Callback&lt;[BatteryInfo](#batteryinfo)&gt; | 否    | 回调函数。<br>若传参，则需与[bas.onBatteryChange](#basonbatterychange)中的回调函数一致；若无传参，则取消订阅电量变化所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例**：

```js
let onReceiveEvent: (data: bas.BatteryInfo) => void = (data: bas.BatteryInfo) => {
    console.info(`address: ${data.deviceId.address}, batteryLevel: ${data.batteryLevel}`);
}
try {
    bas.onBatteryChange(onReceiveEvent);
    bas.offBatteryChange(onReceiveEvent);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```


## BatteryInfo

描述设备的电量信息。

**起始版本**：26.0.0

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称       | 类型   | 只读   | 可选   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId | [BluetoothAddress](js-apis-bluetooth-common.md#bluetoothaddress) | 否    | 否    | 表示远端设备的地址信息。 |
| batteryLevel | number | 否    | 否    | 表示设备的电量值。取值范围为[-1, 100]，-1表示没有电量信息，单位: %。 |