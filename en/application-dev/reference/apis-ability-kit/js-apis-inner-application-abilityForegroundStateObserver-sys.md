# AbilityForegroundStateObserver (System API)

The module defines the listener used to listen for ability foreground and background state changes.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { abilityManager } from '@kit.AbilityKit';
```

## AbilityForegroundStateObserver

### onAbilityStateChanged

onAbilityStateChanged(abilityStateData: AbilityStateData): void

Called when the ability is switched between foreground and background.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ----- | ----- | ----- |
| abilityStateData   | [AbilityStateData](js-apis-inner-application-abilityStateData.md)   | Yes| Ability state data.|

**Example**
```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observer: abilityManager.AbilityForegroundStateObserver = {
  onAbilityStateChanged(abilityStateData) {
    console.info(`onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);
  },
};
try {
  abilityManager.on('abilityForegroundState', observer);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error code: ${code}, error msg: ${message}`);
}
```
