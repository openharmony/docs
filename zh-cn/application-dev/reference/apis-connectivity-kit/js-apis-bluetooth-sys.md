# @ohos.bluetooth (蓝牙)（系统接口）

蓝牙模块提供了基础的传统蓝牙能力以及BLE的扫描、广播等功能。

> **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 从API Version 9 开始，该接口不再维护，推荐使用[`@ohos.bluetooth.ble`](js-apis-bluetooth-ble.md)等相关profile接口。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.bluetooth (蓝牙)](js-apis-bluetooth.md)。

## 导入模块

```js
import bluetooth from '@ohos.bluetooth';
```

## bluetooth.cancelPairedDevice<sup>8+</sup><sup>(deprecated)</sup><a name="cancelPairedDevice"></a>

cancelPairedDevice(deviceId: string): boolean

删除配对的远程设备。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.cancelPairedDevice](js-apis-bluetoothManager-sys.md#bluetoothmanagercancelpaireddevicedeprecated)替代。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型     | 必填   | 说明                                    |
| -------- | ------ | ---- | ------------------------------------- |
| deviceId | string | 是    | 表示要删除的远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型      | 说明                         |
| ------- | -------------------------- |
| boolean | 启动取消配对，成功返回true，否则返回false。 |

**示例：**

```js
let result : boolean = bluetooth.cancelPairedDevice("XX:XX:XX:XX:XX:XX");
```
