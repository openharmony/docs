# SendableContext

SendableContext complies with the [Sendable protocol](../../arkts-utils/arkts-sendable.md#sendable-protocol) and inherits from [lang.ISendable](../apis-arkts/js-apis-arkts-lang.md#langisendable).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { sendableContextManager } from '@kit.AbilityKit';
```

## SendableContext

SendableContext, which complies with the [Sendable protocol](../../arkts-utils/arkts-sendable.md#sendable-protocol), can be converted to a Context object to implement data transmission between concurrent ArkTS instances (including the main thread and the worker thread of TaskPool or Worker).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 12.
