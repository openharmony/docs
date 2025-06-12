# AbilityStateData

定义Ability状态信息，可以通过[on](js-apis-app-ability-appManager.md#appmanageronapplicationstate14)注册生命周期变化监听后，通过[ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md)的onAbilityStateChanged生命周期回调获取。

> **说明：**
> 
> 本模块首批接口从API version 14开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { appManager } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                     | 类型     | 只读 | 可选 | 说明                       |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| pid                     | number   | 否   | 否   | 进程ID。                    |
| bundleName              | string   | 否   | 否  | 应用Bundle名称。          |
| abilityName            | string   | 否   | 否   | Ability名称。               |
| uid                    | number   | 否   | 否   | 用户ID。                  |
| state                   | number   | 否   | 否   | Ability状态。<br>- Stage模型：UIAbility的状态参见[Ability状态](#ability状态)；ExtensionAbility的状态参见[Extension状态](#extension状态)。<br>- FA模型：参见[Ability状态](#ability状态)。                |
| moduleName | string   | 否   | 否   | Ability所属的HAP的名称。    |
| abilityType | number | 否   | 否   | [Ability类型](#ability类型)：页面或服务等。 |
| isAtomicService | boolean   | 否  | 否  | 判断Ability所属的应用是否是原子化服务。<br>true:Ability所属的应用是原子化服务。<br>false:Ability所属的应用不是原子化服务。     |
| appCloneIndex          | number   | 否   | 是   | 分身应用索引。                  |

### Ability状态

| 值   | 状态                       | 说明                   |
| ---- | -------------------------- | ---------------------- |
| 0    | ABILITY_STATE_CREATE       | Ability正在创建中。      |
| 1    | ABILITY_STATE_READY        | Ability已创建完成。      |
| 2    | ABILITY_STATE_FOREGROUND   | Ability处于前台。        |
| 3    | ABILITY_STATE_FOCUS        | Ability已经获焦。        |
| 4    | ABILITY_STATE_BACKGROUND   | Ability处于后台。        |
| 5    | ABILITY_STATE_TERMINATED   | Ability已经销毁。        |
| 7    | ABILITY_STATE_CONNECTED    | 后台服务已被客户端连接。 |
| 8    | ABILITY_STATE_DISCONNECTED | 后台服务客户端断开连接。 |

### Extension状态
| 值   | 状态    | 说明                  |
| ---- | -------------------------- | ---------------------- |
| 0    | EXTENSION_STATE_CREATE     | ExtensionAbility正在创建中。  |
| 1    | EXTENSION_STATE_READY      | ExtensionAbility已创建完成。  |
| 2    | EXTENSION_STATE_CONNECTED  | ExtensionAbility已被客户端连接。  |
| 3    | EXTENSION_STATE_DISCONNECTED | ExtensionAbility客户端断开连接。 |
| 4    | EXTENSION_STATE_TERMINATED  | ExtensionAbility已经销毁。  |

### Ability类型

| 值   | 状态    | 说明                  |
| ---- | ------- | --------------------- |
| 0    | UNKNOWN | 未知类型。              |
| 1    | PAGE    | UI界面类型的Ability。   |
| 2    | SERVICE | 后台服务类型的Ability。 |
| 3    | DATA | 数据类型的Ability。              |
| 4    | FORM    | 卡片类型的Ability。   |
| 5    | EXTENSION | Extension类型的Ability。 |
