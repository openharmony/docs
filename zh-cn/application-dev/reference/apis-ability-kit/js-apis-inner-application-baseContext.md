# BaseContext

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

BaseContext抽象类用于表示继承的子类Context是Stage模型还是FA模型，是所有Context类型的父类。

> **说明：**
>
> 本模块首批接口从API version 8 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## 属性

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称       | 类型   | 只读   | 可选   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| stageMode | boolean | 否    | 否    | 表示是否Stage模型。<br>true：[Stage模型](../../application-models/ability-terminology.md#stage模型)。<br>false：[FA模型](../../application-models/ability-terminology.md#fa模型)。 |

**示例：**

以Stage模型为例，用户可通过UIAbilityContext访问stageMode字段。

```ts
import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    // EntryAbility onCreate, isStageMode: true
    console.info(`EntryAbility onCreate, isStageMode: ${this.context.stageMode}`);
  }
}
```
