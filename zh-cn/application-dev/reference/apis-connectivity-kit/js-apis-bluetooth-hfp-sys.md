# @ohos.bluetooth.hfp (蓝牙hfp模块)(系统接口)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

hfp模块提供了访问蓝牙呼叫接口的方法。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.bluetooth.hfp (蓝牙hfp模块)](js-apis-bluetooth-hfp.md)。


## 导入模块

```js
import { hfp } from '@kit.ConnectivityKit';
```


## HandsFreeAudioGatewayProfile

该实例表示蓝牙通话音频中的[HFP AG](../../connectivity/bluetooth/terminology.md#hfp-ag)角色‌。
- 该类继承于[BaseProfile](js-apis-bluetooth-hfp.md#baseprofile)，因此可以使用其父类中的方法。
- 使用该类的接口前，需通过[createHfpAgProfile](js-apis-bluetooth-hfp.md#hfpcreatehfpagprofile)接口构造该类的实例。
- 和该实例角色相对应的是[HF](../../connectivity/bluetooth/terminology.md#hf)角色。

**系统能力**：SystemCapability.Communication.Bluetooth.Core


### connect

connect(deviceId: string): void

连接设备的HFP服务。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数**：

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备的MAC地址，例如："XX:XX:XX:XX:XX:XX"。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let hfpAg = hfp.createHfpAgProfile();
    hfpAg.connect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### disconnect

disconnect(deviceId: string): void

断开连接设备的HFP服务。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数**：

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备的MAC地址，例如："XX:XX:XX:XX:XX:XX"。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let hfpAg = hfp.createHfpAgProfile();
    hfpAg.disconnect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## HandsFreeHfProfile

该实例表示蓝牙通话音频中的[HF](../../connectivity/bluetooth/terminology.md#hf)角色‌。
- 该类继承于[BaseProfile](js-apis-bluetooth-hfp.md#baseprofile)，因此可以使用其父类中的方法。
- 使用该类的接口前，需通过[createHfpHfProfile](js-apis-bluetooth-hfp.md#hfpcreatehfphfprofile)接口构造该类的实例。
- 和该实例角色相对应的是[HFP AG](../../connectivity/bluetooth/terminology.md#hfp-ag)角色。

**起始版本**： 26.0.0

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。


### connect

connect(deviceId: string): void

连接设备的HFP服务。

需要通过[BaseProfile.on('connectionStateChange')](js-apis-bluetooth-baseProfile.md#baseprofileonconnectionstatechange)接口注册回调，来感知设备的HFP Profile的连接状态变化。

**起始版本**： 26.0.0

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备的MAC地址，例如："XX:XX:XX:XX:XX:XX"。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Internal system error. For example, IPC error.     |

**示例**：

```js
try {
    let hf = hfp.createHfpHfProfile();
    hf.connect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```


### disconnect

disconnect(deviceId: string): void

断开连接设备的HFP服务。

需要通过[BaseProfile.on('connectionStateChange')](js-apis-bluetooth-baseProfile.md#baseprofileonconnectionstatechange)接口注册回调，来感知设备的HFP Profile的连接状态变化。

**起始版本**： 26.0.0

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备的MAC地址，例如："XX:XX:XX:XX:XX:XX"。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Internal system error. For example, IPC error.          |

**示例：**

```js
try {
    let hf = hfp.createHfpHfProfile();
    hf.disconnect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```