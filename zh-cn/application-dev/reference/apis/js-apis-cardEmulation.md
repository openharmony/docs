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

## isSupported

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

**示例：**

```js
import cardEmulation from '@ohos.nfc.cardEmulation';

var isHceSupported = cardEmulation.isSupported(cardEmulation.FeatureType.HCE);
if (!isHceSupported) {
    console.log('this device is not supported for HCE, ignore it.');
}

var hasHceCap = cardEmulation.hasHceCapability();
if (!hasHceCap) {
    console.log('this device hasHceCapability false, ignore it.');
}

var elementName = {
    "bundleName": "com.example.myapplication",
    "abilityName": "EntryAbility",
};
var isDefaultService = cardEmulation.isDefaultService(elementName, cardEmulation.CardType.PAYMENT);
console.log('is the app is default service for this card type: ' + isDefaultService);
```

