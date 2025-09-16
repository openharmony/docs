# @ohos.application.StaticSubscriberExtensionAbility (StaticSubscriberExtensionAbility)
<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @michael_woo888-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @huipeizi-->

<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @peixu-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @huipeizi-->

The **StaticSubscriberExtensionAbility** module provides Extension abilities for static subscribers.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { StaticSubscriberExtensionAbility } from '@kit.BasicServicesKit';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name   | Type                                                        | Read Only| Optional| Description    |
| ------- | ------------------------------------------------------------ | ---- | ---- | -------- |
| context<sup>10+</sup> | [StaticSubscriberExtensionContext](js-apis-application-StaticSubscriberExtensionContext-sys.md) | No  | No  | Context of the ExtensionAbility.|

## StaticSubscriberExtensionAbility.onReceiveEvent

onReceiveEvent(event: CommonEventData): void

Represents a callback of the common event of a static subscriber.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event | [CommonEventData](./js-apis-inner-commonEvent-commonEventData.md) | Yes| Common event of a static subscriber.|

**Example**
  ```ts
  import { commonEventManager } from '@kit.BasicServicesKit';

    class MyStaticSubscriberExtensionAbility extends StaticSubscriberExtensionAbility {
        onReceiveEvent(event: commonEventManager.CommonEventData) {
            console.log(`onReceiveEvent, event: ${JSON.stringify(event)}`);
        }
    }
  ```
