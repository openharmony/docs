# @ohos.nfc.cardEmulation (标准NFC-cardEmulation)（系统接口）

本模块主要提供NFC卡模拟业务，包括判断支持哪种卡模拟类型，HCE卡模拟的业务实现等。
HCE(Host Card Emulation)，称为基于主机的卡模拟，表示不依赖安全单元芯片，应用程序模拟NFC卡片，可以通过NFC服务和NFC读卡器通信。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。<br>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.nfc.cardEmulation (标准NFC-cardEmulation)](js-apis-cardEmulation.md)。


## 导入模块

```
import { cardEmulation } from '@kit.ConnectivityKit';
```

## getPaymentServices<sup>11+</sup>

getPaymentServices(): [AbilityInfo](../apis-ability-kit/js-apis-bundleManager-abilityInfo.md)[]

获取所有支付类型的服务列表。如果应用程序声明支持HCE功能，并且声明了"payment-aid"，则会包含在列表里面，参考[HCE卡模拟和AID列表的声明定义](js-apis-cardEmulation.md#hce卡模拟和aid列表的声明定义)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.NFC.CardEmulation

**需要权限：** ohos.permission.NFC_CARD_EMULATION

**返回值：**

| **类型**  | **说明**                               |
| ------- | ------------------------------------ |
| [AbilityInfo](../apis-ability-kit/js-apis-bundleManager-abilityInfo.md)[] | 返回所有支付类型的服务。 |

**错误码**：

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|801 | Capability not supported.          |

**示例：**
```js
import { cardEmulation } from '@kit.ConnectivityKit';

let paymentServices = cardEmulation.getPaymentServices();
if (paymentServices == undefined || paymentServices.length == 0) {
  console.log('paymentServices is null.');
}

```

