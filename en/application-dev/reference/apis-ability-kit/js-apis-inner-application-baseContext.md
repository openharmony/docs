# BaseContext

**BaseContext** is an abstract class that specifies whether a child class **Context** is used for the stage model or FA model. It is the parent class for all types of **Context**.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## Attributes

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name      | Type  | Readable  | Writable  | Description     |
| -------- | ------ | ---- | ---- | ------- |
| stageMode | boolean | Yes   | Yes   | Whether the child class **Context** is used for the stage model.<br>**true**: used for the stage model.<br>**false**: used for the FA model. |

**Example**

Take the stage model as an example. You can access the **stageMode** field through **UIAbilityContext**.

```ts
import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    // EntryAbility onCreate, isStageMode: true
    console.log(`EntryAbility onCreate, isStageMode: ${this.context.stageMode}`);
  }
}
```
