# AbilityStateData
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhu-feimo-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->
定义了Ability状态信息，通过[on](js-apis-app-ability-appManager.md#appmanageronapplicationstate14)注册生命周期变化监听后，可使用[ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md)的onAbilityStateChanged生命周期回调获取。

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
| uid                    | number   | 否   | 否   | 应用程序的UID。                  |
| state                   | number   | 否   | 否   | Ability状态。<br>- Stage模型：UIAbility的状态参见[Ability状态](#ability状态)；ExtensionAbility的状态参见[Extension状态](#extension状态)。<br>- FA模型：参见[Ability状态](#ability状态)。                |
| moduleName | string   | 否   | 否   | Ability所属的HAP的名称。    |
| abilityType | number | 否   | 否   | [Ability类型](#ability类型)：页面或服务等。 |
| isAtomicService | boolean   | 否  | 否  | 判断Ability所属的应用是否是原子化服务。<br>- true：Ability所属的应用是原子化服务。<br>- false：Ability所属的应用不是原子化服务。     |
| appCloneIndex          | number   | 否   | 是   | 分身应用索引。                  |

### Ability状态

| 状态                        | 值  | 说明                    |
| --------------------------  | --- | ---------------------- |
| ABILITY_STATE_CREATE        | 0   |  Ability正在创建中。    |
| ABILITY_STATE_READY         | 1   |  Ability已创建完成。    |
| ABILITY_STATE_FOREGROUND    | 2   |  Ability处于前台。      |
| ABILITY_STATE_FOCUS         | 3   |   Ability已经获焦。     |
| ABILITY_STATE_BACKGROUND    | 4   |  Ability处于后台。      |
| ABILITY_STATE_TERMINATED    | 5   |  Ability已经销毁。      |
| ABILITY_STATE_CONNECTED     | 7   |  后台服务已被客户端连接。|
| ABILITY_STATE_DISCONNECTED  | 8   |  后台服务客户端断开连接。|

### Extension状态
| 状态                   | 值 | 说明                   |
| ---------------------- | ---- | ---------------------- |
| EXTENSION_STATE_CREATE | 0   | ExtensionAbility正在创建中。  |
| EXTENSION_STATE_READY  | 1   | ExtensionAbility已创建完成。  |
| EXTENSION_STATE_CONNECTED | 2  | ExtensionAbility已被客户端连接。  |
| EXTENSION_STATE_DISCONNECTED | 3 | ExtensionAbility客户端断开连接。 |
| EXTENSION_STATE_TERMINATED | 4  | ExtensionAbility已经销毁。  |

### Ability类型

| 状态    | 值      | 说明                  |
| ------  | ------- | --------------------- |
| UNKNOWN | 0 | 未知类型。              |
| PAGE    | 1 | UI界面类型的Ability。   |
| SERVICE | 2 | 后台服务类型的Ability。 |
| DATA    | 3 | 数据类型的Ability。              |
| FORM    | 4 | 卡片类型的Ability。   |
| EXTENSION | 5 | Extension类型的Ability。 |
