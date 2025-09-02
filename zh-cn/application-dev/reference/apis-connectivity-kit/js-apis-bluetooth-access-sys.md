# @ohos.bluetooth.access (蓝牙access模块)(系统接口)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

access模块提供了打开蓝牙、关闭蓝牙和获取蓝牙状态的方法。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.bluetooth.access (蓝牙access模块)](js-apis-bluetooth-access.md)。


## 导入模块

```js
import { access } from '@kit.ConnectivityKit';
```


## access.factoryReset<sup>11+</sup>

factoryReset(callback: AsyncCallback&lt;void&gt;): void

恢复蓝牙出厂设置。使用Callback异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名   | 类型                                               | 必填  | 说明                                                       |
| -------- | ------------------------------------------------- | ----- | ---------------------------------------------------------- |
| callback     | AsyncCallback&lt;void&gt;             | 是    | 回调函数。当恢复蓝牙出厂设置时成功，err为undefined，否则为错误对象。       |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

|错误码ID   | 错误信息           |
| -------- | ------------------ |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.           |
|801 | Capability not supported.          |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    access.factoryReset((err: BusinessError) => {
        if (err) {
            console.error("factoryReset error");
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## access.factoryReset<sup>11+</sup>

factoryReset(): Promise&lt;void&gt;

恢复蓝牙出厂设置。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型                              | 说明              |
| --------------------------------- | ---------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

|错误码ID   | 错误信息           |
| -------- | ------------------ |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|801 | Capability not supported.          |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    access.factoryReset().then(() => {
        console.info("factoryReset");
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## access.getLocalAddress<sup>11+</sup><a name="getLocalAddress"></a>

getLocalAddress(): string

获取本端设备的蓝牙地址。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.GET_BLUETOOTH_LOCAL_MAC

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型      | 说明                |
| --------- | ------------------ |
| string    | 本端设备的蓝牙地址。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

|错误码ID   | 错误信息           |
| -------- | ------------------ |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|801 | Capability not supported.          |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let localAddr = access.getLocalAddress();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## access.restrictBluetooth<sup>12+</sup><a name="restrictBluetooth"></a>

restrictBluetooth(): Promise&lt;void&gt;

约束当前蓝牙设备的BR/EDR能力。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型                              | 说明              |
| --------------------------------- | ---------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

|错误码ID   | 错误信息           |
| -------- | ------------------ |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|801 | Capability not supported.          |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    access.restrictBluetooth().then(() => {
        console.info("restrictBluetooth");
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## access.notifyDialogResult<sup>20+</sup>

notifyDialogResult(notifyDialogResultParams: NotifyDialogResultParams): Promise&lt;void&gt;

通知用户操作蓝牙对话框的行为。使用Promise异步回调。
- 与API version 20开始支持的[access.enableBluetoothAsync](js-apis-bluetooth-access.md#accessenablebluetoothasync20)搭配使用，应用申请开启蓝牙，调用该接口会将用户操作开关蓝牙对话框的行为通知给蓝牙服务。
- 与API version 20开始支持的[access.disableBluetoothAsync](js-apis-bluetooth-access.md#accessdisablebluetoothasync20)搭配使用，应用申请关闭蓝牙，调用该接口会将用户操作开关蓝牙对话框的行为通知给蓝牙服务。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名   | 类型                                               | 必填  | 说明                                                       |
| -------- | ------------------------------------------------- | ----- | ---------------------------------------------------------- |
|  notifyDialogResultParams   | [NotifyDialogResultParams](#notifydialogresultparams20)             | 是    | 用户操作对话框的行为。       |

**返回值：**

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息                                                    |
| -------- | ----------------------------------------------------------- |
| 201      | Permission denied.                                          |
| 202      | Non-system applications are not allowed to use system APIs. |
| 801      | Capability not supported.                                   |
| 2900001  | Service stopped.                                            |
| 2900099  | Operation failed.                                           |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let notifyDialogResultParams: access.NotifyDialogResultParams = {
        "dialogType": 0,
        "dialogResult": true,
    };
    access.notifyDialogResult(notifyDialogResultParams);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## NotifyDialogResultParams<sup>20+</sup>

用户操作对话框的行为。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称        | 类型                    | 只读   | 可选   | 说明                                     |
| ------------------- | ----------------------- | ---- | ---- | -------------------------------------- |
|   dialogType     | [DialogType](#dialogtype20)      | 否    | 否    | 表示对话框的类型。 |
|   dialogResult     | boolean      | 否    | 否    | 表示用户操作对话框的行为。true表示用户同意该操作，false表示拒绝该操作。 |


## DialogType<sup>20+</sup>

枚举，对话框类型。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                    | 值  | 说明                 |
| --------------------- | ---- | ------------------ |
| BLUETOOTH_SWITCH      | 0    | 蓝牙开关对话框。          |