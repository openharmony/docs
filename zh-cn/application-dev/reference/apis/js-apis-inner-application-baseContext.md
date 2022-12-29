# BaseContext

BaseContext抽象类用于表示继承的子类Context是Stage模型还是FA模型。

> **说明：**
>
> 本模块首批接口从API version 8 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称       | 类型   | 可读   | 可写   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| stageMode | boolean | 是    | 是    | 表示是否Stage模型。<br>true：Stage模型<br>false：FA模型。 |

**示例：**

  ```ts
  class MyContext extends BaseContext {
      constructor(stageMode) {
          this.stageMode = stageMode;
      }
  }
  ```
