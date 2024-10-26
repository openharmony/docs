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

## Properties

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                    | Type                | Read Only| Mandatory| Description                                                        |
| ------------------------ | -------------------- | ---- | ---- | ------------------------------------------------------------ |
| onAbilityFirstFrameDrawn | AsyncCallback\<void> | Yes  | No  | Callback invoked when the first frame of an ability is rendered. The parameter type passed in is [AbilityFirstFrameStateData](js-apis-inner-application-abilityFirstFrameStateData-sys).|
