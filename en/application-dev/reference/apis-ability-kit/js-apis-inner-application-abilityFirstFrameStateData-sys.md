# AbilityFirstFrameStateData (System API)

**AbilityFirstFrameStateData** defines the data reported by the callback when the first frame of an ability is rendered. Specifically, the data is returned in the **onAbilityFirstFrameDrawn** callback of [AbilityFirstFrameStateObserver](js-apis-inner-application-abilityFirstFrameStateObserver-sys.md) after the first frame rendering completion event is listened for by calling [on](js-apis-app-ability-appManager-sys.md#appmanageronabilityfirstframestate12).

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { appManager } from '@kit.AbilityKit';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

| Name       | Type   | Read Only| Mandatory| Description            |
| ----------- | ------- | ---- | ---- | ---------------- |
| bundleName  | string  | Yes  | No  | Bundle name.|
| moduleName  | string  | Yes  | No  | Module name.|
| abilityName | string  | Yes  | No  | Ability name.   |
| appIndex    | number  | Yes  | No  | Index of the DLP sandbox. |
| isColdStart | boolean | Yes  | No  | Enabled status of cold start.    |
