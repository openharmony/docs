# 标准NFC-cardEmulation

本模块主要用于操作及管理NFC卡模拟。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import cardEmulation from '@ohos.nfc.cardEmulation';
```


## cardEmulation.isSupported

isSupported(feature: number): boolean

是否支持某种类型的卡模拟

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:支持该类型卡模拟，&nbsp;false:不支持该类型卡模拟。 |

## HceService

管理HCE卡模拟。在调用HceService的接口前，需要先通过new cardEmulation.HceService()创建实例。

### startHCE

startHCE(aidList: string[]): boolean

开始使用HCE能力。

**需要权限**：ohos.permission.NFC_CARD_EMULATION

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名  | 类型     | 必填 | 说明                    |
| ------- | -------- | ---- | ----------------------- |
| aidList | string[] | 是   | 注册进行卡模拟的aid列表 |

### stopHCE

stopHCE(): boolean

停止使用HCE能力。

**需要权限**：ohos.permission.NFC_CARD_EMULATION

**系统能力：** SystemCapability.Communication.NFC

### on

on(type: "hceCmd", callback: AsyncCallback<number[]>): void;

在startHCE后，订阅对端设备消息。

**需要权限**：ohos.permission.NFC_CARD_EMULATION

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                         |
| -------- | ----------------------- | ---- | -------------------------------------------- |
| type     | string                  | 是   | 固定填"hceCmd"字符串                         |
| callback | AsyncCallback<number[]> | 是   | 订阅的事件回调，入参是符合APDU协议的数据数组 |

### sendResponse

sendResponse(responseApdu: number[]): void;

发送数据到对端设备。

**需要权限**：ohos.permission.NFC_CARD_EMULATION

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名       | 类型     | 必填 | 说明                                               |
| ------------ | -------- | ---- | -------------------------------------------------- |
| responseApdu | number[] | 是   | 准备发送到对端的数据，入参是符合APDU协议的数据数组 |

**示例：**

```js
var hceService = new cardEmulation.HceService();
hceService.startHCE([
    "F0010203040506", "A0000000041010"
])
hceService.stopHCE();
hceService.on("hceCmd", (err, res) => {
    if(err.data === 0) {
        console.log('callback => Operation hceCmd succeeded. Data: ' + JSON.stringify(res));
          hceService.sendResponse([0x00,0xa4,0x04,0x00,
          0x0e,0x32,0x50,0x41,0x59,0x2e,0x53,0x59,0x53,0x2e,0x44,0x44,
          0x46,0x30,0x31,0x00]);
    } else {
        console.log('callback => Operation hceCmd failed. Cause: ' + err.data);
    }
})
```

