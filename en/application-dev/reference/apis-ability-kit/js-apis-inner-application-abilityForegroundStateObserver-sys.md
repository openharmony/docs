# AbilityForegroundStateObserver (System API)

The **AbilityForegroundStateObserver** module defines the listener used to listen for ability foreground and background state changes.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { abilityManager } from '@kit.AbilityKit';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                            | Type                   | Readable| Writable| Description  |
| -------------------------------- | ---------------------- | ---- | ---- | ------------------ |
| onAbilityStateChanged   | AsyncCallback\<void>   | Yes  | No  | Callback invoked when the foreground or background state of an ability changes. The parameter type passed in is [AbilityStateData](js-apis-inner-application-abilityStateData.md).|

**Example**
```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observer: abilityManager.AbilityForegroundStateObserver = {
  onAbilityStateChanged(abilityStateData) {
    console.log(`onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);
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
