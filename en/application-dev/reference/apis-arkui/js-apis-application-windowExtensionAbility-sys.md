# @ohos.application.WindowExtensionAbility (WindowExtensionAbility) (System API)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @chbchb12-->
<!--Designer: @stupidb-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

**WindowExtensionAbility** inherits from **ExtensionAbility**. The content in a WindowExtensionAbility object can be displayed as an ability component in other application windows.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.
>
> - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { WindowExtensionAbility } from '@kit.ArkUI';
```

## Attributes

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name     | Type| Read-Only| Optional| Description                     |
| --------- | -------- | ---- | ---- | ------------------------- |
| context      | [WindowExtensionContext](js-apis-inner-application-windowExtensionContext-sys.md)   | No  | No  | Context of an Extension ability.     |

## WindowExtensionAbility.onConnect

onConnect(want: Want): void

Called when this WindowExtensionAbility is connected to an ability for the first time.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| Information related to this WindowExtensionAbility, including the ability name and bundle name.|

**Example**

```ts
import { WindowExtensionAbility } from '@kit.ArkUI';
import { Want } from '@kit.AbilityKit';

export default class MyWindowExtensionAbility extends WindowExtensionAbility {
  onConnect(want: Want) {
    console.info(`WindowExtAbility onConnect, abilityName: ${want.abilityName}`);
  }
}
```

## WindowExtensionAbility.onDisconnect

onDisconnect(want: Want): void

Called when this WindowExtensionAbility is disconnected from all connected abilities.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| Information related to this WindowExtensionAbility, including the ability name and bundle name.|


**Example**

```ts
import { WindowExtensionAbility } from '@kit.ArkUI';
import { Want } from '@kit.AbilityKit';

export default class MyWindowExtensionAbility extends WindowExtensionAbility {
  onDisconnect(want: Want) {
    console.info(`WindowExtAbility onDisconnect, abilityName: ${want.abilityName}`);
  }
}
```

## WindowExtensionAbility.onWindowReady

onWindowReady(window: window.Window): void

Called when a window is ready.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| window | [window.Window](arkts-apis-window-Window.md) | Yes| Current Window instance.|


**Example**

```ts
import { WindowExtensionAbility, window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class MyWindowExtensionAbility extends WindowExtensionAbility {
  onWindowReady(window: window.Window) {
    window.setUIContent('WindowExtAbility/pages/index1',(err:BusinessError) => {
      let pro = window.getWindowProperties();
      console.info(`WindowExtension pro: ${JSON.stringify(pro)}`);
      window.showWindow();
    });
  }
}
```
