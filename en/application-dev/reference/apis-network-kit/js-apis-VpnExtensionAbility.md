# @ohos.app.ability.VpnExtensionAbility (Enhanced VPN Management)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

This module provides lifecycle callbacks for third-party VPNs, including VPN creation and destruction.

>  **NOTE**
>
>  - The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { VpnExtensionAbility } from '@kit.NetworkKit';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core.

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [VpnExtensionContext](js-apis-inner-application-VpnExtensionContext.md) | No| No| Context of the **VpnExtension**. This context is inherited from **ExtensionContext**.|

## VpnExtensionAbility.onCreate

onCreate(want: Want): void

Called when the third-party VPN is initialized upon startup.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type                                      | Mandatory  | Description            |
| ---- | ---------------------------------------- | ---- | -------------- |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Want information.|

**Example**

  ```ts
import { VpnExtensionAbility } from '@kit.NetworkKit';
import { Want } from '@kit.AbilityKit';

class MyVpnExtAbility extends VpnExtensionAbility {
    onCreate(want: Want) {
       console.info('MyVpnExtAbility onCreate');
    }
}
  ```

## VpnExtensionAbility.onDestroy

onDestroy(): void

Called when the third-party VPN is destroyed to clear resources.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Example**

  ```ts
import { VpnExtensionAbility } from '@kit.NetworkKit';

class MyVpnExtAbility extends VpnExtensionAbility {
    onDestroy() {
       console.info('MyVpnExtAbility onDestroy');
    }
}
  ```
