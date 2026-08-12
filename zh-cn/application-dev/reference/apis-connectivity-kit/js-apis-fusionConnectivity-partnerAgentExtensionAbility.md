# @ohos.FusionConnectivity.PartnerAgentExtensionAbility (支持设备状态通知的ExtensionAbility组件)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

PartnerAgentExtensionAbility是外设互通扩展能力的基础类，提供设备发现与设备下线的通知功能，需要应用继承实现。应用模块级配置文件[module.json5](../../quick-start/module-configuration-file.md) 中的[extensionabilities](../../quick-start/module-configuration-file.md#extensionabilities标签)的type属性应该配置为partnerAgent。

> **说明：**
>
> - 本模块首批接口从API version 23开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口仅可在Stage模型下使用。

## 约束限制

为保障系统安全性和稳定性，防止PartnerAgentExtensionAbility滥用系统资源，系统对其能力进行管控，不支持部分模块的引用，详情请参考[附录](#附录)。

## 导入模块

```ts
import { PartnerAgentExtensionAbility, partnerAgent } from '@kit.ConnectivityKit';
```
## PartnerDeviceAddress

type PartnerDeviceAddress = partnerAgent.PartnerDeviceAddress

描述设备地址信息。

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**： 此接口仅可在Stage模型下使用。

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| [partnerAgent.PartnerDeviceAddress](js-apis-fusionConnectivity-partnerAgent.md#partnerdeviceaddress) | 信息互通设备的地址信息。 |

## PartnerAgentExtensionAbilityDestroyReason

type PartnerAgentExtensionAbilityDestroyReason = partnerAgent.PartnerAgentExtensionAbilityDestroyReason

描述PartnerAgentExtensionAbility被销毁的原因。

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**： 此接口仅可在Stage模型下使用。

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| [partnerAgent.PartnerAgentExtensionAbilityDestroyReason](js-apis-fusionConnectivity-partnerAgent.md#partneragentextensionabilitydestroyreason) | PartnerAgentExtensionAbility被销毁的原因。 |

## PartnerAgentExtensionAbility 
PartnerAgentExtensionAbility是外设互通扩展能力的基础类，提供设备发现与设备下线的通知功能，需要应用继承实现。本能力继承自[ExtensionAbility](../apis-ability-kit/js-apis-app-ability-extensionAbility.md)。

### 属性

**系统能力**： SystemCapability.Communication.FusionConnectivity.Core

**模型约束**： 此接口仅可在Stage模型下使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [PartnerAgentExtensionContext](js-apis-fusionConnectivity-partnerAgentExtensionContext.md)  | 否 | 否 | PartnerAgentExtensionAbility的上下文。|

### onDestroyWithReason

onDestroyWithReason(reason: PartnerAgentExtensionAbilityDestroyReason): void

外设互通扩展能力被销毁时触发的方法回调。

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**： 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| reason | [PartnerAgentExtensionAbilityDestroyReason](js-apis-fusionConnectivity-partnerAgent.md#partneragentextensionabilitydestroyreason) | 是 | 通知销毁该应用的原因。 |

**示例：**

```ts
export default class PartnerAgentExtAbility extends PartnerAgentExtensionAbility {
  onDestroyWithReason(reason: partnerAgent.PartnerAgentExtensionAbilityDestroyReason): void {
    console.info(`onDestroyWithReason is: ${reason}`);
  }
}
```

### onDeviceDiscovered

onDeviceDiscovered(deviceAddress: PartnerDeviceAddress): void

当已注册的设备被发现时，系统会调用此回调方法。

**系统能力**：SystemCapability.Communication.FusionConnectivity.Core

**模型约束**： 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceAddress | [PartnerDeviceAddress](js-apis-fusionConnectivity-partnerAgent.md#partnerdeviceaddress) | 是 | 应用注册的设备地址信息。<br>应用需在PartnerDeviceAddress类型中设置bluetoothAddress选项。 |

**示例：**

```ts
export default class PartnerAgentExtAbility extends PartnerAgentExtensionAbility {
  onDeviceDiscovered(deviceAddress: partnerAgent.PartnerDeviceAddress): void {
    console.info(`onDeviceDiscovered success: ${deviceAddress.bluetoothAddress}`);
  }
}
```

## 附录

PartnerAgentExtensionAbility不支持以下模块的引用。
| Kit | 模块 |
| ------ | ------ |
| Ability Kit | [@ohos.backgroundTaskManager (后台任务管理)](../../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md) |
| Ability Kit | [@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md) |
| <!--DelRow-->Camera Kit | [@ohos.multimedia.camera (相机管理)(系统接口)](../../reference/apis-camera-kit/js-apis-camera-sys.md) |
| Camera Kit | [@ohos.multimedia.cameraPicker (相机选择器)](../../reference/apis-camera-kit/js-apis-cameraPicker.md) |
| Connectivity Kit | [@ohos.connectedTag (有源标签)](../../reference/apis-connectivity-kit/js-apis-connectedTag.md) |
| Connectivity Kit | [@ohos.nfc.cardEmulation (标准NFC-cardEmulation)](../../reference/apis-connectivity-kit/js-apis-cardEmulation.md) |
| Connectivity Kit | [@ohos.nfc.controller (标准NFC)](../../reference/apis-connectivity-kit/js-apis-nfcController.md) |
| Connectivity Kit | [@ohos.nfc.tag (标准NFC-Tag)](../../reference/apis-connectivity-kit/js-apis-nfcTag.md) |
| Connectivity Kit | [tagSession (标准NFC-Tag TagSession)](../../reference/apis-connectivity-kit/js-apis-tagSession.md) |
| Connectivity Kit | [@ohos.wifiext (WLAN扩展接口)](../../reference/apis-connectivity-kit/js-apis-wifiext.md) |
| Connectivity Kit | [@ohos.wifiManager (WLAN)](../../reference/apis-connectivity-kit/js-apis-wifiManager.md) |
| Connectivity Kit | [@ohos.wifiManagerExt (WLAN扩展接口)](../../reference/apis-connectivity-kit/js-apis-wifiManagerExt.md) |
| Location Kit | [@ohos.geolocation (位置服务)](../../reference/apis-location-kit/js-apis-geolocation.md) |
| Location Kit | [@ohos.geoLocationManager (位置服务)](../../reference/apis-location-kit/js-apis-geoLocationManager.md) |
| <!--DelRow-->Media Kit | [@ohos.multimedia.media (媒体服务)(系统接口)](../../reference/apis-media-kit/js-apis-media-sys.md) |
| Media Library Kit | [@ohos.multimedia.movingphotoview (动态照片)](../../reference/apis-media-library-kit/ohos-multimedia-movingphotoview.md) |
| Telephony Kit | [@ohos.telephony.sim (SIM卡管理)](../../reference/apis-telephony-kit/js-apis-sim.md) |
| Telephony Kit | [@ohos.telephony.sms (短信服务)](../../reference/apis-telephony-kit/js-apis-sms.md) |