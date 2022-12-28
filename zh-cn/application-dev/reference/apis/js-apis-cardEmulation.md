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

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| HCE | 0 | HCE 卡模拟。 |
| UICC | 1 | SIM 卡模拟。 |
| ESE | 2      | ESE卡模拟。 |

## CardType

定义卡模拟应用是支付类型，还是非支付类型。

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| PAYMENT | "payment" | 卡模拟应用是支付类型。 |
| OTHER | "other" | 卡模拟应用是非支付类型。 |

## cardEmulation.isSupported

isSupported(feature: number): boolean

是否支持某种类型的卡模拟。

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

**参数：**

| 参数名  | 类型     | 必填 | 说明                    |
| ------- | -------- | ---- | ----------------------- |
| feature | number | 是   | 卡模拟类型值，详细请见[FeatureType](#featuretype)枚举值。 |

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| boolean | true: 支持该类型卡模拟，&nbsp;false: 不支持该类型卡模拟。|

## cardEmulation.isDefaultService

isDefaultService(elementName: ElementName, type: CardType): boolean

判断指定的应用是否为默认支付应用。

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

**参数：**

| 参数名  | 类型     | 必填 | 说明                    |
| ------- | -------- | ---- | ----------------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md#elementname) | 是 | 应用的描述，由Bundle名称和组件名称组成。 |
| type | [CardType](#cardtype) | 是 | 支付类型。 |

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| boolean | true: 是默认支付应用，&nbsp;false: 不是默认支付应用。|

**示例：**

```js
import cardEmulation from '@ohos.nfc.cardEmulation';

var isHceSupported = cardEmulation.isSupported(cardEmulation.FeatureType.HCE);
if (!isHceSupported) {
    console.log('this device is not supported for HCE, ignore it.');
    return;
}

var elementName = {
    "bundleName": "com.test.cardemulation",
    "abilityName": "com.test.cardemulation.MainAbility",
};
var isDefaultService = cardEmulation.isDefaultService(elementName, cardEmulation.CardType.PAYMENT);
console.log('is the app is default service for this card type: ' + isDefaultService);
```

