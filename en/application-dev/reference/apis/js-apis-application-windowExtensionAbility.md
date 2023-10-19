# @ohos.application.WindowExtensionAbility (WindowExtensionAbility)

**WindowExtensionAbility** inherits from **ExtensionAbility**. The content in a **WindowExtensionAbility** object can be displayed as an ability component in other application windows.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import WindowExtensionAbility from '@ohos.application.WindowExtensionAbility';
```

## Attributes

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name     | Type| Readable| Writable| Description                     |
| --------- | -------- | ---- | ---- | ------------------------- |
| context      | [WindowExtensionContext](js-apis-inner-application-windowExtensionContext.md)   | Yes  | No  | Context of an Extension ability.     |

## WindowExtensionAbility.onConnect

onConnect(want: Want): void

Called when this Window Extension ability is connected to an ability for the first time.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Information related to this Window Extension ability, including the ability name and bundle name.|

**Example**

```ts
import WindowExtensionAbility from '@ohos.application.WindowExtensionAbility';
import Want from '@ohos.app.ability.Want';

export default class MyWindowExtensionAbility extends WindowExtensionAbility {
  onConnect(want: Want) {
    console.info('WindowExtAbility onConnect, abilityName: ${want.abilityName}');
  }
}
```

## WindowExtensionAbility.onDisconnect

onDisconnect(want: Want): void

Called when this Window Extension ability is disconnected from all connected abilities.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Information related to this Window Extension ability, including the ability name and bundle name.|


**Example**

```ts
import WindowExtensionAbility from '@ohos.application.WindowExtensionAbility';
import Want from '@ohos.app.ability.Want';

export default class MyWindowExtensionAbility extends WindowExtensionAbility {
  onDisconnect(want: Want) {
    console.info('WindowExtAbility onDisconnect, abilityName: ${want.abilityName}');
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
| window | [window.Window](js-apis-window.md#window) | Yes| Current **Window** instance.|


**Example**

```ts
import WindowExtensionAbility from '@ohos.application.WindowExtensionAbility';
import window from '@ohos.window';

export default class MyWindowExtensionAbility extends WindowExtensionAbility {
  onWindowReady(window: window.Window) {
    window.loadContent('WindowExtAbility/pages/index1').then(() => {
      window.getProperties().then((pro: window.WindowProperties) => {
        console.log('WindowExtension pro: ${JSON.stringify(pro)}');
      });
      window.show();
    });
  }
}
```
