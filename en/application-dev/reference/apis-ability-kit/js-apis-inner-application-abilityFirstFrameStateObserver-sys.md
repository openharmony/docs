# AbilityFirstFrameStateObserver (System API)

**AbilityFirstFrameStateObserver** defines the observer used to listen for the complete of the first frame rendering of a given ability. It is used as an input parameter of [on](js-apis-app-ability-appManager-sys.md#appmanageronabilityfirstframestate12) to listen for the completion event.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { appManager } from '@kit.AbilityKit';
```

## AbilityFirstFrameStateObserver

### onAbilityFirstFrameDrawn

onAbilityFirstFrameDrawn(data: AbilityFirstFrameStateData): void

Called when the first frame of the ability is rendered.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | [AbilityFirstFrameStateData](js-apis-inner-application-abilityFirstFrameStateData-sys.md) | Yes| Data returned after the first frame is rendered.|

**Example**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observer: appManager.AbilityFirstFrameStateObserver = {
  onAbilityFirstFrameDrawn(data: appManager.AbilityFirstFrameStateData) {
    console.info(`onAbilityFirstFrameDrawn success, abilityFirstFrameStateData: ${data}.`);
  }
};

try {
  appManager.on('abilityFirstFrameState', observer);
} catch (e) {
  let code = (e as BusinessError).code;
  let msg = (e as BusinessError).message;
  console.error(`appmanager.on failed, err code: ${code}, err msg: ${msg}.`);
}
```
