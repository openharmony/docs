# @ohos.FusionConnectivity.PartnerAgentExtensionAbility (ExtensionAbility Component Supporting Device Status Notifications)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=14ca614ebb030bf413b2d8393352ad7521a1d1b9 translatedAt=2026-08-20T07:49:05.946Z pushedAt=2026-08-20T08:05:22.882Z -->

As the base class of the peripheral interconnection extension capability, **PartnerAgentExtensionAbility** provides the device discovery and device offline notification features. This class needs to be inherited by the application. The **type** attribute of [extensionabilities](../../quick-start/module-configuration-file.md#extensionabilities) in the module-level configuration file [module.json5](../../quick-start/module-configuration-file.md) must be set to **partnerAgent**.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 23. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module can be used only in the stage model.

## Constraints

To ensure system security and stability and prevent **PartnerAgentExtensionAbility** from abusing system resources, the system restricts its capabilities. Referencing certain modules is not supported. For details, please refer to the [Appendix](#appendix).

## Modules to Import

```ts
import { PartnerAgentExtensionAbility, partnerAgent } from '@kit.ConnectivityKit';
```

## PartnerDeviceAddress

type PartnerDeviceAddress = partnerAgent.PartnerDeviceAddress

Describes the device address information.

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

| **Type**                 | **Description**                 |
| ------------------- | ------------------- |
| [partnerAgent.PartnerDeviceAddress](js-apis-fusionConnectivity-partnerAgent.md#partnerdeviceaddress) | Address of the device to be interconnected. |

## PartnerAgentExtensionAbilityDestroyReason

type PartnerAgentExtensionAbilityDestroyReason = partnerAgent.PartnerAgentExtensionAbilityDestroyReason

Describes the reason why **PartnerAgentExtensionAbility** is destroyed.

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

| **Type**                 | **Description**                 |
| ------------------- | ------------------- |
| [partnerAgent.PartnerAgentExtensionAbilityDestroyReason](js-apis-fusionConnectivity-partnerAgent.md#partneragentextensionabilitydestroyreason) | Reason why **PartnerAgentExtensionAbility** is destroyed. |

## PartnerAgentExtensionAbility

As the base class of the peripheral interconnection extension capability, **PartnerAgentExtensionAbility** provides the device discovery and device offline notification features. This class needs to be inherited by the application. It is inherited from [ExtensionAbility](../apis-ability-kit/js-apis-app-ability-extensionAbility.md).

### Attribute

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

| **Name**| **Type**| **Read-Only**| **Optional**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| context | [PartnerAgentExtensionContext](js-apis-fusionConnectivity-partnerAgentExtensionContext.md)  | No| No| Context of **PartnerAgentExtensionAbility**.|

### onDestroyWithReason

onDestroyWithReason(reason: PartnerAgentExtensionAbilityDestroyReason): void

Called when the peripheral interconnection extension capability is destroyed.

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| reason | [PartnerAgentExtensionAbilityDestroyReason](js-apis-fusionConnectivity-partnerAgent.md#partneragentextensionabilitydestroyreason) | Yes | Destruction reason. |

**Example**

```ts
export default class PartnerAgentExtAbility extends PartnerAgentExtensionAbility {
  onDestroyWithReason(reason: partnerAgent.PartnerAgentExtensionAbilityDestroyReason): void {
    console.info(`onDestroyWithReason is: ${reason}`);
  }
}
```

### onDeviceDiscovered

onDeviceDiscovered(deviceAddress: PartnerDeviceAddress): void

Called when a registered device is discovered.

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| deviceAddress | [PartnerDeviceAddress](js-apis-fusionConnectivity-partnerAgent.md#partnerdeviceaddress) | Yes | Address information of the device registered by the application.<br>The application must be configured with the **bluetoothAddress** option of the **PartnerDeviceAddress** type. |

**Example**

```ts
export default class PartnerAgentExtAbility extends PartnerAgentExtensionAbility {
  onDeviceDiscovered(deviceAddress: partnerAgent.PartnerDeviceAddress): void {
    console.info(`onDeviceDiscovered success: ${deviceAddress.bluetoothAddress}`);
  }
}
```

## Appendix

**PartnerAgentExtensionAbility** does not support referencing the following modules.

| Kit | Module |
| ------ | ------ |
| Ability Kit | [@ohos.backgroundTaskManager (Background Task Management)](../../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md) |
| Ability Kit | [@ohos.resourceschedule.backgroundTaskManager (Background Task Management)](../../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md) |
| <!--DelRow-->Camera Kit | [@ohos.multimedia.camera (Camera Management) (System API)](../../reference/apis-camera-kit/js-apis-camera-sys.md) |
| Camera Kit | [@ohos.multimedia.cameraPicker (Camera Picker)](../../reference/apis-camera-kit/js-apis-cameraPicker.md) |
| Connectivity Kit | [@ohos.connectedTag (Active Tags)](../../reference/apis-connectivity-kit/js-apis-connectedTag.md) |
| Connectivity Kit | [@ohos.nfc.cardEmulation (Standard NFC Card Emulation)](../../reference/apis-connectivity-kit/js-apis-cardEmulation.md) |
| Connectivity Kit | [@ohos.nfc.controller (Standard NFC)](../../reference/apis-connectivity-kit/js-apis-nfcController.md) |
| Connectivity Kit | [@ohos.nfc.tag (Standard NFC Tags)](../../reference/apis-connectivity-kit/js-apis-nfcTag.md) |
| Connectivity Kit | [tagSession (Standard NFC Tag Session)](../../reference/apis-connectivity-kit/js-apis-tagSession.md) |
| Connectivity Kit | [@ohos.wifiext (WLAN Extension)](../../reference/apis-connectivity-kit/js-apis-wifiext.md) |
| Connectivity Kit | [@ohos.wifiManager (WLAN)](../../reference/apis-connectivity-kit/js-apis-wifiManager.md) |
| Connectivity Kit | [@ohos.wifiManagerExt (WLAN Extension)](../../reference/apis-connectivity-kit/js-apis-wifiManagerExt.md) |
| Location Kit | [@ohos.geolocation (Geolocation)](../../reference/apis-location-kit/js-apis-geolocation.md) |
| Location Kit | [@ohos.geoLocationManager (Geolocation Manager)](../../reference/apis-location-kit/js-apis-geoLocationManager.md) |
| <!--DelRow-->Media Kit | [@ohos.multimedia.media (Media) (System API)](../../reference/apis-media-kit/js-apis-media-sys.md) |
| Media Library Kit | [@ohos.multimedia.movingphotoview (MovingPhotoView Component)](../../reference/apis-media-library-kit/ohos-multimedia-movingphotoview.md) |
| Telephony Kit | [@ohos.telephony.sim (SIM Management)](../../reference/apis-telephony-kit/js-apis-sim.md) |
| Telephony Kit | [@ohos.telephony.sms (SMS)](../../reference/apis-telephony-kit/js-apis-sms.md) |