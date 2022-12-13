# @ohos.nfc.cardEmulation (标准NFC-cardEmulation)

本模块主要提供NFC卡模拟业务，包括判断支持哪种卡模拟类型，HCE卡模拟的业务实现等。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import cardEmulation from '@ohos.nfc.cardEmulation';
```

## FeatureType

定义不同的NFC卡模拟类型。

**系统能力：** SystemCapability.Communication.NFC.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| HCE | 0 | HCE 卡模拟。 |
| UICC | 1 | SIM 卡模拟。 |
| ESE | 2      | ESE卡模拟。 |

## cardEmulation.isSupported

isSupported(feature: number): boolean

是否支持某种类型的卡模拟。

**系统能力：** SystemCapability.Communication.NFC.Core

**参数：**

| 参数名  | 类型     | 必填 | 说明                    |
| ------- | -------- | ---- | ----------------------- |
| feature | number | 是   | 卡模拟类型值，详细请见[FeatureType](#featuretype)枚举值。 |

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| boolean | true: 支持该类型卡模拟，&nbsp;false: 不支持该类型卡模拟。|

## HceService<sup>8+</sup>

提供HCE卡模拟的实现，主要包括接收对端读卡设备的APDU数据，并响应APDU数据到对端读卡设备。使用HCE相关接口前，必须先判断设备是否支持HCE卡模拟能力。

### startHCE<sup>8+</sup>

startHCE(aidList: string[]): boolean

启动HCE业务功能。包括设置当前应用为前台优先，动态注册AID列表。

**需要权限：** ohos.permission.NFC_CARD_EMULATION

**系统能力：** SystemCapability.Communication.NFC.Core

**参数：**

| 参数名  | 类型     | 必填 | 说明                    |
| ------- | -------- | ---- | ----------------------- |
| aidList | string[] | 是   | 动态注册卡模拟的AID列表。 |

### stopHCE<sup>8+</sup>

stopHCE(): boolean

停止HCE业务功能。包括退出当前应用前台优先，释放动态注册的AID列表。

**需要权限：** ohos.permission.NFC_CARD_EMULATION

**系统能力：** SystemCapability.Communication.NFC.Core

### on<sup>8+</sup>

on(type: "hceCmd", callback: AsyncCallback<number[]>): void;

订阅回调，用于接收对端读卡设备发送的APDU数据。

**需要权限：** ohos.permission.NFC_CARD_EMULATION

**系统能力：** SystemCapability.Communication.NFC.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                         |
| -------- | ----------------------- | ---- | -------------------------------------------- |
| type     | string                  | 是   | 固定填"hceCmd"字符串。                         |
| callback | AsyncCallback<number[]> | 是   | 订阅的事件回调，入参是符合APDU协议的数据，每个number十六进制表示，范围是0x00~0xFF。 |

### sendResponse<sup>8+</sup>

sendResponse(responseApdu: number[]): void;

发送APDU数据到对端读卡设备。

**需要权限：** ohos.permission.NFC_CARD_EMULATION

**系统能力：** SystemCapability.Communication.NFC.Core

**参数：**

| 参数名       | 类型     | 必填 | 说明                                               |
| ------------ | -------- | ---- | -------------------------------------------------- |
| responseApdu | number[] | 是   | 发送到对端读卡设备的符合APDU协议的数据，每个number十六进制表示，范围是0x00~0xFF。 |

**示例：**

```js
import cardEmulation from '@ohos.nfc.cardEmulation';

var isHceSupported = cardEmulation.isSupported(cardEmulation.FeatureType.HCE);
if (!isHceSupported) {
    console.log('this device is not supported for HCE, ignore it.');
    return;
}

// device supports HCE, transimit APDU with remote nfc reader.
var hceService = new cardEmulation.HceService();
hceService.startHCE([
    "F0010203040506", "A0000000041010"
]);

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

// stop HCE when the application exit the nfc card emulation.
hceService.stopHCE();
```

