# AbilityStateData

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhu-feimo-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->
AbilityStateData是Ability状态信息的数据结构。使用[on](js-apis-app-ability-appManager.md#appmanageronapplicationstate14)注册生命周期变化监听后，可以通过[ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md)的onAbilityStateChanged回调的入参获取该数据结构。

> **说明：**
> 
> 本模块首批接口从API version 14开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { appManager } from '@kit.AbilityKit';
```

## AbilityStateData


**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                     | 类型     | 只读 | 可选 | 说明                       |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| pid                     | number   | 否   | 否   | 进程ID。                    |
| bundleName              | string   | 否   | 否  | 应用Bundle名称。          |
| abilityName            | string   | 否   | 否   | Ability名称。               |
| uid                    | number   | 否   | 否   | 所属应用程序的UID。                  |
| state                   | number   | 否   | 否   | Ability状态。<br>- Stage模型：[UIAbility](js-apis-app-ability-uiAbility.md)的状态参见[UIAbility状态](#uiability状态)；[ExtensionAbility](js-apis-app-ability-extensionAbility.md)的状态参见[ExtensionAbility状态](#extensionability状态)。<br>- FA模型：参见[Ability状态](#ability状态)。                |
| moduleName | string   | 否   | 否   | Ability所属的模块名称。    |
| abilityType | number | 否   | 否   | [Ability类型](#ability类型)：[UIAbility](js-apis-app-ability-uiAbility.md)或[ExtensionAbility](js-apis-app-ability-extensionAbility.md)等。 |
| isAtomicService | boolean | 否 | 否 | 判断Ability所属应用是否为原子化服务。<br>true: 是原子化服务。<br>false: 不是原子化服务。 |
| appCloneIndex          | number   | 否   | 是   | 应用包的[分身](../../quick-start/app-clone.md)索引标识。                  |

### UIAbility状态

| 值   | 状态                       | 说明                   |
| ---- | -------------------------- | ---------------------- |
| 0    | ABILITY_STATE_CREATE       | UIAbility正在创建中。      |
| 1    | ABILITY_STATE_READY        | UIAbility已创建完成。      |
| 2    | ABILITY_STATE_FOREGROUND   | UIAbility处于前台。        |
| 3    | ABILITY_STATE_FOCUS        | UIAbility已获得焦点。        |
| 4    | ABILITY_STATE_BACKGROUND   | UIAbility处于后台。        |
| 5    | ABILITY_STATE_TERMINATED   | UIAbility已经销毁。        |

### ExtensionAbility状态
| 值   | 状态    | 说明                  |
| ---- | -------------------------- | ---------------------- |
| 0    | EXTENSION_STATE_CREATE     | ExtensionAbility正在创建中。  |
| 1    | EXTENSION_STATE_READY      | ExtensionAbility已创建完成。  |
| 2    | EXTENSION_STATE_CONNECTED  | ExtensionAbility已与客户端建立连接。 |
| 3    | EXTENSION_STATE_DISCONNECTED | ExtensionAbility与客户端断开连接。 |
| 4    | EXTENSION_STATE_TERMINATED  | ExtensionAbility已经销毁。  |

### Ability状态

| 值   | 状态                       | 说明                   |
| ---- | -------------------------- | ---------------------- |
| 0    | ABILITY_STATE_CREATE       | Ability正在创建中。      |
| 1    | ABILITY_STATE_READY        | Ability已创建完成。      |
| 2    | ABILITY_STATE_FOREGROUND   | Ability处于前台。        |
| 3    | ABILITY_STATE_FOCUS        | Ability已获得焦点。       |
| 4    | ABILITY_STATE_BACKGROUND   | Ability处于后台。        |
| 5    | ABILITY_STATE_TERMINATED   | Ability已经销毁。        |
| 7    | ABILITY_STATE_CONNECTED    | 后台服务已被客户端连接。 |
| 8    | ABILITY_STATE_DISCONNECTED | 后台服务与客户端断开连接。 |

### Ability类型

| 值   | 状态    | 说明                  |
| ---- | ------- | --------------------- |
| 0    | UNKNOWN | 未知类型。（系统错误）              |
| 1    | PAGE    | UI界面类型的Ability，即[UIAbility](js-apis-app-ability-uiAbility.md)。  |
| 2    | SERVICE | 后台服务类型的Ability。（FA模型） |
| 3    | DATA | 数据类型的Ability。（FA模型）               |
| 4    | FORM    | 卡片类型的Ability。（FA模型）    |
| 5    | EXTENSION | 扩展类型的Ability。（Stage模型）  |
