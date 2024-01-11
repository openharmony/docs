# @ohos.bluetooth.access (蓝牙access模块)

access模块提供了打开和关闭蓝牙、获取蓝牙状态的方法。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import access from '@ohos.bluetooth.access';
```

## access.getState

getState(): BluetoothState

获取蓝牙开关状态。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型                              | 说明              |
| --------------------------------- | ---------------- |
| [BluetoothState](#bluetoothstate) | 表示蓝牙开关状态。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

|错误码ID   | 错误信息           |
| -------- | ------------------ |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let state = access.getState();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## BluetoothState

枚举，蓝牙开关状态。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                    | 值  | 说明                 |
| --------------------- | ---- | ------------------ |
| STATE_OFF             | 0    | 表示蓝牙已关闭。           |
| STATE_TURNING_ON      | 1    | 表示蓝牙正在打开。          |
| STATE_ON              | 2    | 表示蓝牙已打开。           |
| STATE_TURNING_OFF     | 3    | 表示蓝牙正在关闭。          |
| STATE_BLE_TURNING_ON  | 4    | 表示蓝牙正在打开LE-only模式。 |
| STATE_BLE_ON          | 5    | 表示蓝牙正处于LE-only模式。  |
| STATE_BLE_TURNING_OFF | 6    | 表示蓝牙正在关闭LE-only模式。 |

