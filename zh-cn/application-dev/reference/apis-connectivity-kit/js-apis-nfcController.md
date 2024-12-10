# @ohos.nfc.controller (标准NFC)

本模块主要用于管理NFC状态，包括打开和关闭NFC，读取NFC的状态等。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## **导入模块**

```js
import { nfcController } from '@kit.ConnectivityKit';
```

## NfcState

定义不同的NFC状态值。

**系统能力：** SystemCapability.Communication.NFC.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| STATE_OFF | 1 | NFC已关闭状态。 |
| STATE_TURNING_ON | 2 | NFC正在打开状态。 |
| STATE_ON | 3      | NFC已打开状态。 |
| STATE_TURNING_OFF | 4      | NFC正在关闭状态。 |

## nfcController.isNfcAvailable<sup>(deprecated)</sup>

isNfcAvailable(): boolean

查询设备是否有NFC能力。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[canIUse("SystemCapability.Communication.NFC.Core")](../common/init.md#caniuse)替代。

**系统能力：** SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| boolean | true: 设备具备NFC能力，&nbsp;false: 设备不具备NFC能力。 |


## nfcController.openNfc<sup>(deprecated)</sup>

openNfc(): boolean

打开NFC开关。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[enableNfc](#nfccontrollerenablenfc9)替代。

**需要权限：** ohos.permission.MANAGE_SECURE_SETTINGS（该权限仅系统应用可申请）

**系统能力：** SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| boolean | true: 打开NFC成功，&nbsp;false: 打开NFC失败。 |

## nfcController.enableNfc<sup>9+</sup>

enableNfc(): void

打开NFC开关，该接口只能被系统应用调用。

**需要权限：** ohos.permission.MANAGE_SECURE_SETTINGS（该权限仅系统应用可申请）

**系统能力：** SystemCapability.Communication.NFC.Core

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
|201 | Permission denied.                 |
|801 | Capability not supported.          |
| 3100101 | NFC state is abnormal in service. |

## nfcController.closeNfc<sup>(deprecated)</sup>

closeNfc(): boolean

关闭NFC开关。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[disableNfc](#nfccontrollerdisablenfc9)替代。

**需要权限：** ohos.permission.MANAGE_SECURE_SETTINGS（该权限仅系统应用可申请）

**系统能力：** SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                                    |
| -------- | ------------------------------------------- |
| boolean  | true: 关闭NFC成功，&nbsp;false: 关闭NFC失败。 |

## nfcController.disableNfc<sup>9+</sup>

disableNfc(): void

关闭NFC开关，该接口只能被系统应用调用。

**需要权限：** ohos.permission.MANAGE_SECURE_SETTINGS（该权限仅系统应用可申请）

**系统能力：** SystemCapability.Communication.NFC.Core

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
|201 | Permission denied.                 |
|801 | Capability not supported.          |
| 3100101 | NFC state is abnormal in service. |

## nfcController.isNfcOpen

isNfcOpen(): boolean

查询NFC是否打开。

**系统能力：** SystemCapability.Communication.NFC.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                            |
| -------- | ----------------------------------- |
| boolean  | true: NFC是打开的，&nbsp;false: NFC是关闭的。 |

## nfcController.getNfcState

getNfcState(): [NfcState](#nfcstate)

查询NFC状态。

**系统能力：** SystemCapability.Communication.NFC.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**               |
| -------- | ---------------------- |
| [NfcState](#nfcstate) | NFC状态值，详细请见[NfcState](#nfcstate)枚举值。 |

## nfcController.on('nfcStateChange')

on(type: 'nfcStateChange', callback: Callback&lt;[NfcState](#nfcstate)&gt;): void

注册NFC开关状态事件，通过Callback方式获取NFC状态的变化通知。

**系统能力：** SystemCapability.Communication.NFC.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数**
 
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"nfcStateChange"字符串。 |
| callback | Callback&lt;[NfcState](#nfcstate)&gt; | 是 | NFC状态改变通知的回调函数。 |

## nfcController.off('nfcStateChange')

off(type: 'nfcStateChange', callback?: Callback&lt;[NfcState](#nfcstate)&gt;): void

取消NFC开关状态事件的注册，取消后NFC状态变化时，就不会再收到Callback的通知。

**系统能力：** SystemCapability.Communication.NFC.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"nfcStateChange"字符串。 |
| callback | Callback&lt;[NfcState](#nfcstate)&gt; | 否 | NFC状态改变回调函数，可以空缺不填。如果callback不填，将取消注册该事件关联的所有回调函数 |
  
**示例**

```js
import { nfcController } from '@kit.ConnectivityKit';

// register callback to receive the nfc state changed notification
nfcController.on("nfcStateChange", (nfcState : number)=> {
  console.log("nfcController on callback nfcState: " + nfcState);
});

// open nfc, require permission: ohos.permission.MANAGE_SECURE_SETTINGS（This permission can only be requested by system apps.）
if (!nfcController.isNfcOpen()) {
  // from api9, use 'enableNfc' to open nfc.
  try {
    nfcController.enableNfc();
    console.log("nfcController enableNfc success");
  } catch (businessError) {
    console.error("nfcController enableNfc businessError: " + businessError);
  }
} else {
  console.log("nfcController NFC has been opened");
}

// close nfc, require permission: ohos.permission.MANAGE_SECURE_SETTINGS（This permission can only be requested by system apps.）
if (nfcController.isNfcOpen()) {
  // from api9, use 'disableNfc' to close nfc.
  try {
    nfcController.disableNfc();
    console.log("nfcController disableNfc success");
  } catch (businessError) {
    console.error("nfcController disableNfc businessError: " + businessError);
  }
} else {
  console.log("nfcController NFC has been closed");
}

// unregister callback
nfcController.off("nfcStateChange");
```
