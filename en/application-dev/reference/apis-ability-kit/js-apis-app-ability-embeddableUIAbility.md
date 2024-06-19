# @ohos.app.ability.EmbeddableUIAbility (Embeddable UIAbility)

The EmbeddableUIAbility module provides the UIAbility that can be started in embedded mode for atomic services. It inherits from [UIAbility](js-apis-app-ability-uiAbility.md) and supports two startup modes: redirection startup and embedded startup.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import EmbeddableUIAbility from '@ohos.app.ability.EmbeddableUIAbility';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name| Type| Read-only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [EmbeddableUIAbilityContext](js-apis-inner-application-EmbeddableUIAbilityContext.md) | No| Yes| Context of the UIAbility.|
