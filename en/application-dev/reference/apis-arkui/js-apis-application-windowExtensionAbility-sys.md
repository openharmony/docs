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
> - This module is deprecated since API version 21. You are advised to use [UIExtensionAbility](../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md) instead.
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
| context<sup>(deprecated)</sup>  | [WindowExtensionContext](js-apis-inner-application-windowExtensionContext-sys.md)   | No  | No  | Context of an ExtensionAbility.<br>- Note: This API is supported since API version 9 and deprecated since API version 21. You are advised to use [UIExtensionAbility.context](../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md#properties) instead.<br>     |

## WindowExtensionAbility.onConnect<sup>(deprecated)</sup>

onConnect(want: Want): void

Called when this WindowExtensionAbility is connected to an ability for the first time.

> **NOTE**
>
>  This API is supported since API version 9 and deprecated since API version 21. You are advised to use [UIExtensionAbility.onCreate](../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md#oncreate).

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

## WindowExtensionAbility.onDisconnect<sup>(deprecated)</sup>

onDisconnect(want: Want): void

Called when this WindowExtensionAbility is disconnected from all connected abilities.

> **NOTE**
>
>  This API is supported since API version 9 and deprecated since API version 21. You are advised to use [UIExtensionAbility.onDestroy](../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md#ondestroy) instead.

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

## WindowExtensionAbility.onWindowReady<sup>(deprecated)</sup>

onWindowReady(window: window.Window): void

Called when a window is ready.

> **NOTE**
>
>  This API is supported since API version 9 and deprecated since API version 21. You are advised to use [UIExtensionAbility.onSessionCreate](../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md#onsessioncreate) instead.

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
