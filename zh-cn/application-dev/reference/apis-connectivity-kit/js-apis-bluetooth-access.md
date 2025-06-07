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

订阅蓝牙设备开关状态事件。使用Callback异步回调。从API18开始不再校验ohos.permission.ACCESS_BLUETOOTH权限。

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

取消订阅蓝牙设备开关状态事件。从API18开始不再校验ohos.permission.ACCESS_BLUETOOTH权限。

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

## access.addPersistentDeviceId<sup>16+</sup>

addPersistentDeviceId(deviceId: string): Promise&lt;void&gt;

应用通过蓝牙扫描获取得到的设备地址是虚拟随机的，若应用想长期使用该虚拟随机地址，需要调用该接口持久化存储虚拟随机地址。

需注意，使用该接口时，开发者应明确该虚拟随机地址对应的对端蓝牙设备真实地址是不变的，若对端设备地址发生变化，持久化保存的地址信息也会失效，无法继续使用。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.PERSISTENT_BLUETOOTH_PEERS_MAC

**原子化服务API**：从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| deviceId     | string                                   | 是    | 表示远程设备的虚拟地址，例如："XX:XX:XX:XX:XX:XX"，该地址一般来源于蓝牙扫描结果。  |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900003 | Bluetooth disabled. |
|2900010 | The number of supported device addresses has reached the upper limit. |
|2900099 | Add persistent device address failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { access } from '@kit.ConnectivityKit';

let deviceId = '11:22:33:44:55:66'  // 该地址可通过BLE扫描获取
try {
    access.addPersistentDeviceId(deviceId);
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## access.deletePersistentDeviceId<sup>16+</sup>

deletePersistentDeviceId(deviceId: string): Promise&lt;void&gt;

删除一个持久化的蓝牙虚拟设备地址。


**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.PERSISTENT_BLUETOOTH_PEERS_MAC

**原子化服务API**：从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| deviceId     | string                                   | 是    | 表示远程设备的虚拟地址，例如："XX:XX:XX:XX:XX:XX"，该地址一般来源于蓝牙扫描结果。           |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900003 | Bluetooth disabled. |
|2900099 | delete persistent device address failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { access } from '@kit.ConnectivityKit';

let deviceId = '11:22:33:44:55:66'  // 该地址可通过BLE扫描获取
try {
    access.deletePersistentDeviceId(deviceId);
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## access.getPersistentDeviceIds<sup>16+</sup>

getPersistentDeviceIds(): string[];

获取该应用持久化过的蓝牙虚拟设备地址。


**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.PERSISTENT_BLUETOOTH_PEERS_MAC

**原子化服务API**：从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型                              | 说明              |
| --------------------------------- | ---------------- |
| string[] | 表示该应用持久化过的蓝牙虚拟设备地址列表。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900003 | Bluetooth disabled. |
|2900099 | Get persistent device address failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { access } from '@kit.ConnectivityKit';

try {
    let deviceIds = access.getPersistentDeviceIds();
    console.info("deviceIds: " + deviceIds);
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## access.isValidRandomDeviceId<sup>16+</sup>

isValidRandomDeviceId(deviceId: string): boolean;

判断对端蓝牙设备的虚拟地址是否是有效。


**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| deviceId     | string                                   | 是    | 表示远程设备的虚拟地址，例如："XX:XX:XX:XX:XX:XX"，该地址一般来源于蓝牙扫描结果。           |

**返回值：**

| 类型                              | 说明              |
| --------------------------------- | ---------------- |
| boolean | 表明蓝牙虚拟设备地址是否有效。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900003 | Bluetooth disabled. |
|2900099 | Check persistent device address failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { access } from '@kit.ConnectivityKit';

try {
    let deviceId = '11:22:33:44:55:66'  // 该地址可通过BLE扫描获取
    let isValid = access.isValidRandomDeviceId(deviceId);
    console.info("isValid: " + isValid);
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## BluetoothState

枚举，蓝牙开关状态。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

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

