# EmbeddableUIAbilityContext

**EmbeddableUIAbilityContext**, inherited from [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md), provides the context environment for the [EmbeddableUIAbility](js-apis-app-ability-embeddableUIAbility.md) that needs to store its status. **EmbeddableUIAbilityContext** provides EmbeddableUIAbility-related configuration and APIs for operating EmbeddableUIAbilities and ServiceExtensionAbilities. For example, you can use the APIs to start an EmbeddableUIAbility, terminate an EmbeddableUIAbility to which the EmbeddableUIAbilityContext belongs, and start, terminate, connect to, or disconnect from a ServiceExtensionAbility.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.
>  - The APIs of this module must be used in the main thread, but not in sub-threads such as Worker and TaskPool.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```
