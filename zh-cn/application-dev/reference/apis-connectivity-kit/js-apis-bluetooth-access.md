# @ohos.bluetooth.access (蓝牙access模块)

access模块提供了打开和关闭蓝牙、获取蓝牙状态的方法。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import { access } from '@kit.ConnectivityKit';
```


## access.enableBluetooth

enableBluetooth(): void

开启蓝牙。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息            |
| -------- | ------------------ |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    access.enableBluetooth();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## access.disableBluetooth

disableBluetooth(): void

关闭蓝牙。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

|错误码ID   | 错误信息           |
| -------- | ------------------ |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    access.disableBluetooth();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## access.getState

getState(): BluetoothState

获取蓝牙开关状态。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型                              | 说明              |
| --------------------------------- | ---------------- |
| [BluetoothState](#bluetoothstate) | 表示蓝牙开关状态。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

|错误码ID   | 错误信息           |
| -------- | ------------------ |
|801 | Capability not supported.          |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let state = access.getState();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## access.on('stateChange')<a name="stateChange"></a>

on(type: 'stateChange', callback: Callback&lt;BluetoothState&gt;): void

订阅蓝牙设备开关状态事件。使用Callback异步回调。从API16开始不再校验ohos.permission.ACCESS_BLUETOOTH权限。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名   | 类型                                               | 必填  | 说明                                                       |
| -------- | ------------------------------------------------- | ----- | ---------------------------------------------------------- |
| type     | string                                            | 是    | 填写"stateChange"字符串，表示蓝牙状态改变事件。               |
| callback | Callback&lt;[BluetoothState](#bluetoothstate)&gt; | 是    | 表示回调函数的入参，蓝牙状态。回调函数由用户创建并通过该接口注册。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

|错误码ID   | 错误信息           |
| -------- | ------------------ |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099   | Operation failed.  |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: access.BluetoothState) {
    console.info('bluetooth state = '+ JSON.stringify(data));
}
try {
    access.on('stateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## access.off('stateChange')

off(type: 'stateChange', callback?: Callback&lt;BluetoothState&gt;): void

取消订阅蓝牙设备开关状态事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"stateChange"字符串，表示蓝牙状态改变事件。           |
| callback | Callback&lt;[BluetoothState](#bluetoothstate)&gt; | 否    | 表示取消订阅蓝牙状态改变事件上报。不填该参数则取消订阅该type对应的所有回调。 |

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
function onReceiveEvent(data: access.BluetoothState) {
    console.info('bluetooth state = '+ JSON.stringify(data));
}
try {
    access.on('stateChange', onReceiveEvent);
    access.off('stateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## BluetoothState

枚举，蓝牙开关状态。

**原子化服务API**: 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                    | 值  | 说明                 |
| --------------------- | ---- | ------------------ |
| STATE_OFF             | 0    | 表示蓝牙已关闭。          |
| STATE_TURNING_ON      | 1    | 表示蓝牙正在打开。          |
| STATE_ON              | 2    | 表示蓝牙已打开。           |
| STATE_TURNING_OFF     | 3    | 表示蓝牙正在关闭。          |
| STATE_BLE_TURNING_ON  | 4    | 表示蓝牙正在打开LE-only模式。 |
| STATE_BLE_ON          | 5    | 表示蓝牙正处于LE-only模式。  |
| STATE_BLE_TURNING_OFF | 6    | 表示蓝牙正在关闭LE-only模式。 |

