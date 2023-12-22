# @ohos.nfc.cardEmulation (标准NFC-cardEmulation)

本模块主要提供NFC卡模拟业务，包括判断支持哪种卡模拟类型，HCE卡模拟的业务实现等。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import cardEmulation from '@ohos.nfc.cardEmulation';
```

## FeatureType<sup>(deprecated)</sup>

定义不同的NFC卡模拟类型。

> **说明：**
> 从 API version 6 开始支持，从 API version 9 开始废弃，建议使用[hasHceCapability](#hashcecapability9)替代。

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

| 名称   | 值    | 说明       |
| ---- | ---- | -------- |
| HCE  | 0    | HCE 卡模拟。 |
| UICC | 1    | SIM 卡模拟。 |
| ESE  | 2    | ESE卡模拟。  |

## CardType<sup>9+</sup>

定义卡模拟应用所使用的业务类型，是支付类型，还是其他类型。

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

| 名称      | 值         | 说明                |
| ------- | --------- | ----------------- |
| PAYMENT | "payment" | 卡模拟应用所使用的业务是支付类型。 |
| OTHER   | "other"   | 卡模拟应用所使用的业务是其他类型。 |

## isSupported<sup>(deprecated)</sup>

isSupported(feature: number): boolean

是否支持某种类型的卡模拟。

> **说明：**
> 从 API version 6 开始支持，从 API version 9 开始废弃，建议使用[hasHceCapability](#hashcecapability9)替代。

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

**参数：**

| 参数名     | 类型     | 必填   | 说明                                       |
| ------- | ------ | ---- | ---------------------------------------- |
| feature | number | 是    | 卡模拟类型值，详细请见[FeatureType](#featuretype)枚举值。 |

**返回值：**

| **类型**  | **说明**                                 |
| ------- | -------------------------------------- |
| boolean | true: 支持该类型卡模拟，&nbsp;false: 不支持该类型卡模拟。 |

## hasHceCapability<sup>9+</sup>

hasHceCapability(): boolean

判断是否支持HCE功能。

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

**需要权限：** ohos.permission.NFC_CARD_EMULATION

**返回值：**

| **类型**  | **说明**                           |
| ------- | -------------------------------- |
| boolean | true: 支持HCE，&nbsp;false: 不支持HCE。 |

## isDefaultService<sup>9+</sup>

isDefaultService(elementName: ElementName, type: CardType): boolean

判断指定的应用是否为指定业务类型的默认应用。

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

**需要权限：** ohos.permission.NFC_CARD_EMULATION

**参数：**

| 参数名         | 类型                                       | 必填   | 说明                      |
| ----------- | ---------------------------------------- | ---- | ----------------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md#elementname) | 是    | 应用的描述，由Bundle名称和组件名称组成。 |
| type        | [CardType](#cardtype9)                   | 是    | 卡模拟业务类型。                |

**返回值：**

| **类型**  | **说明**                               |
| ------- | ------------------------------------ |
| boolean | true: 是默认支付应用，&nbsp;false: 不是默认支付应用。 |

## HceService<sup>8+</sup>

提供HCE卡模拟的实现，主要包括接收对端读卡设备的APDU数据，并响应APDU数据到对端读卡设备。使用HCE相关接口前，必须先判断设备是否支持HCE卡模拟能力。暂不支持使用，仅做接口声明。

### startHCE<sup>(deprecated)</sup>

startHCE(aidList: string[]): boolean

启动HCE业务功能。包括设置当前应用为前台优先，动态注册AID列表。暂不支持使用，仅做接口声明。

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃，建议使用[start](#start9)替代。

**需要权限：** ohos.permission.NFC_CARD_EMULATION

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

**参数：**

| 参数名  | 类型     | 必填 | 说明                    |
| ------- | -------- | ---- | ----------------------- |
| aidList | string[] | 是   | 动态注册卡模拟的AID列表。 |

**返回值：**

| **类型**  | **说明**                                 |
| ------- | -------------------------------------- |
| boolean | true: 启动HCE功能或HCE已启动，&nbsp;false: 启动失败。 |

### start<sup>9+</sup>

start(elementName: [ElementName](js-apis-bundleManager-elementName.md#elementname), aidList: string[]): void

启动HCE业务功能。包括设置当前应用为前台优先，动态注册AID列表。暂不支持使用，仅做接口声明。

**需要权限：** ohos.permission.NFC_CARD_EMULATION

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

**参数：**

| 参数名  | 类型     | 必填 | 说明                    |
| ------- | -------- | ---- | ----------------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md#elementname) | 是   | 服务能力的元素名称。 |
| aidList | string[] | 是   | 动态注册卡模拟的AID列表，允许为空。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](../errorcodes/errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 3100301 | Card emulation running state is abnormal in service. |

### stopHCE<sup>(deprecated)</sup>

stopHCE(): boolean

停止HCE业务功能。包括退出当前应用前台优先，释放动态注册的AID列表。暂不支持使用，仅做接口声明。

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃，建议使用[stop](#stop9)替代。

**需要权限：** ohos.permission.NFC_CARD_EMULATION

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

**返回值：**

| **类型**  | **说明**                                 |
| ------- | -------------------------------------- |
| boolean | true: 禁用HCE功能或HCE已禁用，&nbsp;false: 禁用失败。 |


### stop<sup>9+</sup>

stop(elementName: [ElementName](js-apis-bundleManager-elementName.md#elementname)): void

停止HCE业务功能。包括退出当前应用前台优先，释放动态注册的AID列表。暂不支持使用，仅做接口声明。

**需要权限：** ohos.permission.NFC_CARD_EMULATION

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

**参数：**

| 参数名  | 类型     | 必填 | 说明                    |
| ------- | -------- | ---- | ----------------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md#elementname) | 是   | 服务能力的元素名称。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](../errorcodes/errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 3100301 | Card emulation running state is abnormal in service. |

### on<sup>8+</sup>

on(type: "hceCmd", callback: AsyncCallback<number[]>): void

订阅回调，用于接收对端读卡设备发送的APDU数据。

**需要权限：** ohos.permission.NFC_CARD_EMULATION

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                         |
| -------- | ----------------------- | ---- | -------------------------------------------- |
| type     | string                  | 是   | 固定填"hceCmd"字符串。                         |
| callback | AsyncCallback<number[]> | 是   | 订阅的事件回调，入参是符合APDU协议的数据，每个number十六进制表示，范围是0x00~0xFF。 |

**示例：**
```js
import cardEmulation from '@ohos.nfc.cardEmulation';
import { AsyncCallback } from '@ohos.base';

let hceService: cardEmulation.HceService = new cardEmulation.HceService();

const apduCallback: AsyncCallback<number[]> = (err, data) => {
  //handle the data and err
  console.log("got apdu data");
};
hceService.on('hceCmd', apduCallback);
```


### sendResponse<sup>(deprecated)</sup>

sendResponse(responseApdu: number[]): void

发送APDU数据到对端读卡设备。暂不支持使用，仅做接口声明。

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃，建议使用[transmit](#transmit9)替代。

**需要权限：** ohos.permission.NFC_CARD_EMULATION

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

**参数：**

| 参数名       | 类型     | 必填 | 说明                                               |
| ------------ | -------- | ---- | -------------------------------------------------- |
| responseApdu | number[] | 是   | 发送到对端读卡设备的符合APDU协议的数据，每个number十六进制表示，范围是0x00~0xFF。 |

### transmit<sup>9+</sup>

transmit(response: number[]): Promise\<void>

发送APDU数据到对端读卡设备，使用Promise异步回调。

**需要权限：** ohos.permission.NFC_CARD_EMULATION

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

**参数：**

| 参数名       | 类型     | 必填 | 说明                                               |
| ------------ | -------- | ---- | -------------------------------------------------- |
| response | number[] | 是   | 发送到对端读卡设备的符合APDU协议的数据，每个number十六进制表示，范围是0x00~0xFF。 |

**返回值：**

| **类型**  | **说明**                                 |
| ------- | -------------------------------------- |
| Promise\<void> | 表示异步回调完成。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](../errorcodes/errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 3100301 | Card emulation running state is abnormal in service. |

**示例：**
```js
import cardEmulation from '@ohos.nfc.cardEmulation';
import { AsyncCallback } from '@ohos.base';

let hceService: cardEmulation.HceService = new cardEmulation.HceService();

// the data app wanna send, just a example data
const responseData = [0x1, 0x2];
hceService.transmit(responseData).then(() => {
  // handle the transmit promise
  console.log("send data.");
}).catch((err: BusinessError) => {
  console.log("send data error:", err);
});
```

### transmit<sup>9+</sup>

transmit(response: number[], callback: AsyncCallback\<void>): void

发送APDU数据到对端读卡设备。暂不支持使用，仅做接口声明。

**需要权限：** ohos.permission.NFC_CARD_EMULATION

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

**参数：**

| 参数名  | 类型     | 必填 | 说明                    |
| ------- | -------- | ---- | ----------------------- |
| response | number[] | 是   | 发送到对端读卡设备的符合APDU协议的数据，每个number十六进制表示，范围是0x00~0xFF。 |
| callback | AsyncCallback\<void> | 是   | 回调函数void |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](../errorcodes/errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 3100301 | Card emulation running state is abnormal in service. |

**示例：**

```js
import cardEmulation from '@ohos.nfc.cardEmulation';
import bundleManager from '@ohos.bundle.bundleManager';

let isHceSupported = cardEmulation.isSupported(cardEmulation.FeatureType.HCE);
if (!isHceSupported) {
    console.log('this device is not supported for HCE, ignore it.');
}

let hasHceCap = cardEmulation.hasHceCapability();
if (!hasHceCap) {
    console.log('this device hasHceCapability false, ignore it.');
}

let elementName: bundleManager.ElementName = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility",
};
let isDefaultService = cardEmulation.isDefaultService(elementName, cardEmulation.CardType.PAYMENT);
console.log('is the app is default service for this card type: ' + isDefaultService);
```

