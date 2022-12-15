# BaseContext

The abstract class **BaseContext** specifies whether its child class **Context** is used for the stage model or FA model.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name      | Type  | Readable  | Writable  | Description     |
| -------- | ------ | ---- | ---- | ------- |
| stageMode | boolean | Yes   | Yes   | Whether the context is used for the stage model.|

**Example**
    
  ```ts
  class MyContext extends BaseContext {
      constructor(stageMode) {
          this.stageMode = stageMode;
      }
  }
  ```
