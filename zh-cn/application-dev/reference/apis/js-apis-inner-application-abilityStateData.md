# AbilityStateData

定义Ability状态信息，可以通过[registerApplicationStateObserver](js-apis-application-appManager.md#appmanagerregisterapplicationstateobserver8)注册生命周期变化监听后，通过[ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md)的onAbilityStateChanged生命周期回调获取。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                     | 类型     | 可读 | 可写 | 说明                       |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| pid<sup>8+</sup>                     | number   | 是   | 否   | 进程ID。                    |
| bundleName<sup>8+</sup>              | string   | 是   | 否  | 应用包名。                  |
| abilityName<sup>8+</sup>             | string   | 是   | 否   | Ability名称。               |
| uid<sup>8+</sup>                     | number   | 是   | 否   | 用户ID。                  |
| state<sup>8+</sup>                   | number   | 是   | 否   | Ability状态。                |
| moduleName<sup>9+</sup> | string   | 是   | 否   | Ability所属的HAP包的名称。    |
| abilityType<sup>8+</sup> | string   | 是   | 否   | Ability类型：页面或服务等。 |

