# 标准NFC

本模块主要用于操作及管理NFC。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## **导入模块**

```
import controller from '@ohos.nfc.controller';
```


## controller.isNfcAvailable

isNfcAvailable(): boolean

查询是否有NFC功能

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| boolean | true:有NFC功能，&nbsp;false:无NFC功能。 |


## controller.openNfc

openNfc(): boolean

打开NFC开关。

**需要权限**：ohos.permission.MANAGE_SECURE_SETTINGS

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| boolean | true:打开NFC成功，&nbsp;false:打开NFC失败。 |

## controller.closeNfc

closeNfc(): boolean

关闭NFC开关。

**需要权限**：ohos.permission.MANAGE_SECURE_SETTINGS

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                                    |
| -------- | ------------------------------------------- |
| boolean  | true:关闭NFC成功，&nbsp;false:关闭NFC失败。 |

## controller.isNfcOpen

isNfcOpen(): boolean

查询NFC是否打开。

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                            |
| -------- | ----------------------------------- |
| boolean  | true:NFC打开，&nbsp;false:NFC关闭。 |

## controller.getNfcState

getNfcState(): boolean

查询NFC是否打开。

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                            |
| -------- | ----------------------------------- |
| boolean  | true:NFC打开，&nbsp;false:NFC关闭。 |

## controller.on('nfcStateChange')

on(type: "nfcStateChange", callback: Callback&lt;NfcState&gt;): void

注册NFC开关状态事件。

**系统能力**：SystemCapability.Communication.NFC

**参数**
  
  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"nfcStateChange"字符串 |
  | callback | Callback&lt;NfcState&gt; | 是 | 状态改变回调函数。 |



## controller.off('nfcStateChange')

off(type: "nfcStateChange", callback?: Callback&lt;NfcState&gt;): void

取消NFC开关状态事件的注册。

**系统能力**：SystemCapability.Communication.NFC

**参数**
  
  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"nfcStateChange"字符串 |
| callback | Callback&lt;NfcState&gt; | 否 | 状态改变回调函数。如果callback不填，将“去注册”该事件关联的所有回调函数。 |
  
**示例**

  ```js
  import nfcController from '@ohos.nfcController';
  
  var NFC_STATE_NOTIFY = "nfcStateChange";
  
  var recvNfcStateNotifyFunc = result => {
      console.info("nfc state receive state: " + result);
  }
  
  // 注册事件
  nfcController.on(NFC_STATE_NOTIFY, recvNfcStateNotifyFunc);
  
  // 解注册事件
  nfcController.off(NFC_STATE_NOTIFY, recvNfcStateNotifyFunc);
  ```

## NfcState

表示NFC状态的枚举。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| STATE_OFF | 1 | NFC关闭状态 |
| STATE_TURNING_ON | 2 | NFC正在打开状态 |
| STATE_ON | 3      | NFC打开状态 |
| STATE_TURNING_OFF | 4      | NFC正在关闭状态 |
