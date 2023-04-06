# AbilityStateData

定义Ability状态信息，可以通过[registerApplicationStateObserver](js-apis-application-appManager.md#appmanagerregisterapplicationstateobserver8)注册生命周期变化监听后，通过[ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md)的onAbilityStateChanged生命周期回调获取。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                     | 类型     | 可读 | 可写 | 说明                       |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| pid<sup>8+</sup>                     | number   | 是   | 否   | 进程ID。                    |
| bundleName<sup>8+</sup>              | string   | 是   | 否  | 应用Bundle名称。          |
| abilityName<sup>8+</sup>             | string   | 是   | 否   | Ability名称。               |
| uid<sup>8+</sup>                     | number   | 是   | 否   | 用户ID。                  |
| state<sup>8+</sup>                   | number   | 是   | 否   | [Ability状态](#ability状态)。                |
| moduleName<sup>9+</sup> | string   | 是   | 否   | Ability所属的HAP的名称。    |
| abilityType<sup>8+</sup> | number | 是   | 否   | [Ability类型](#ability类型)：页面或服务等。 |

#### Ability状态

| 值   | 状态                       | 说明                   |
| ---- | -------------------------- | ---------------------- |
| 0    | ABILITY_STATE_CREATE       | Ability正在创建中      |
| 1    | ABILITY_STATE_READY        | Ability已创建完成      |
| 2    | ABILITY_STATE_FOREGROUND   | Ability处于前台        |
| 3    | ABILITY_STATE_FOCUS        | Ability已经获焦        |
| 4    | ABILITY_STATE_BACKGROUND   | Ability处于后台        |
| 5    | ABILITY_STATE_TERMINATED   | Ability已经销毁        |
| 8    | ABILITY_STATE_CONNECTED    | 后台服务已被客户端连接 |
| 9    | ABILITY_STATE_DISCONNECTED | 后台服务客户端断开连接 |

#### Ability类型

| 值   | 状态    | 说明                  |
| ---- | ------- | --------------------- |
| 0    | UNKNOWN | 未知类型              |
| 1    | PAGE    | UI界面类型的Ability   |
| 2    | SERVICE | 后台服务类型的Ability |
