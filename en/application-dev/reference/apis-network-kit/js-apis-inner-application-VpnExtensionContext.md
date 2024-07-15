# VpnExtensionContext

**VpnExtensionContext** represents the context of **VpnExtensionAbility** and is inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).

This module provides the context required for APIs to access the resources of a **VpnExtensionAbility** object.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Modules to Import
```ts
import { VpnExtensionAbility } from '@kit.NetworkKit';
```
## How to Use

You can obtain a **VpnExtensionContext** object through a **VpnExtensionAbility** child class instance.

```ts
import { VpnExtensionAbility, vpnExtension } from '@kit.NetworkKit';
import { Want } from '@kit.AbilityKit';

export default class MyVpnExtAbility extends VpnExtensionAbility {
  private vpnServerIp: string = 'xxx.xxx.x.x';
  private tunIp: string = 'x.x.x.x';
  private blockedAppName: string = 'xxxx';

  onCreate(want: Want) {
    let VpnConnection: vpnExtension.VpnConnection = vpnExtension.createVpnConnection(this.context);
    console.info("vpn createVpnConnection: " + JSON.stringify(VpnConnection));
  }
}
```

## VpnExtensionAbility

Represents the VPN extension capability.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core.

**Model restriction**: This API can be used only in the stage model.

| Name  | Type                                                        | Mandatory| Description          |
|------| ------------------------------------------------------------ | ---- | -------------- |
| context | [VpnExtensionContext](js-apis-inner-application-VpnExtensionContext.md) | Yes  | Specified context.|


### onCreate

onCreate(want: Want): void

Represents the callback triggered when the extended VPN is initialized.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                               | Mandatory| Description       |
| ------ | ----------------------------------- | ---- |-----------|
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Want information.|

### onDestroy

onDestroy(): void

Represents the callback triggered when the extended VPN is destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core.

**Model restriction**: This API can be used only in the stage model.
