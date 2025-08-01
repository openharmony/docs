# @ohos.app.ability.contextConstant (Context相关常量)

ContextConstant提供Context相关的枚举，当前仅包含数据加密等级的枚举。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { contextConstant } from '@kit.AbilityKit';
```

## AreaMode

数据加密等级。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称  | 值 | 说明                                                                                                                   |
|-----| -------- |----------------------------------------------------------------------------------------------------------------------|
| EL1 | 0 | 设备级加密区，设备开机后可访问的数据区。<br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。    |
| EL2 | 1 | 用户级加密区，设备开机，首次输入密码后才能够访问的数据区。<br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。       |
| EL3<sup>11+<sup> | 2 | 用户级加密区，不同场景的文件权限如下：<br/>已打开文件：锁屏时，可读写；解锁后，可读写。<br/>未打开文件：锁屏时，不可打开、不可读写；解锁后，可打开、可读写。<br/>创建新文件：锁屏时，可创建、可打开、可写不可读；解锁后，可创建、可打开、可读写。<br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| EL4<sup>11+<sup> | 3 | 用户级加密区，不同场景的文件权限如下：<br/>已打开文件：锁屏时，不可读写；解锁后，可读写。<br/>未打开文件：锁屏时，不可打开、不可读写；解锁后，可打开、可读写。<br/>创建新文件：锁屏时，不可创建；解锁后，可创建、可打开、可读写。<br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。  |
| EL5<sup>12+<sup> | 4 | 应用级加密区，不同场景的文件权限如下：<br/>已打开文件：锁屏时，可读写；解锁后，可读写。<br/>未打开文件：锁屏时，调用[Access](js-apis-screenLockFileManager.md#screenlockfilemanageracquireaccess)接口获取保留密钥后，可打开、可读写，否则不可打开、不可读写；解锁后，可打开、可读写。<br/>创建新文件：锁屏时，可创建、可打开、可读写；解锁后，可创建、可打开、可读写。<br/>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |


## ProcessMode<sup>12+</sup>

进程模式。该功能仅在2in1和tablet设备上生效。

ProcessMode作为[StartOptions](js-apis-app-ability-startOptions.md)的一个属性，仅在[UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#startability-1)中生效，用来指定目标Ability的进程模式。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称  | 值 | 说明                                                                                                                   |
|-----| -------- |----------------------------------------------------------------------------------------------------------------------|
| NEW_PROCESS_ATTACH_TO_PARENT | 1 | 创建一个新进程，并在该进程上启动Ability。该进程会跟随父进程退出。<br>**约束：**<br>使用此模式时，要求目标Ability跟调用方是在同一个应用。                     |
| NEW_PROCESS_ATTACH_TO_STATUS_BAR_ITEM | 2 | 创建一个新进程，在该进程上启动Ability，并绑定该进程到状态栏图标上。<br>**约束：**<br>使用此模式时，要求目标Ability跟调用方是在同一个应用，并且应用要在状态栏中有图标。                  |
| ATTACH_TO_STATUS_BAR_ITEM | 3 | 启动Ability，并绑定该Ability所在进程到状态栏图标上。<br>**约束：**<br>使用此模式时，要求目标Ability跟调用方是在同一个应用，并且应用要在状态栏中有图标。                  |

**示例：**

  ```ts
  import { UIAbility, Want, StartOptions, contextConstant } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  export default class EntryAbility extends UIAbility {
    onForeground() {
      let want: Want = {
        deviceId: '',
        bundleName: 'com.example.myapplication',
        abilityName: 'MainAbility2'
      };
      let options: StartOptions = {
        processMode: contextConstant.ProcessMode.NEW_PROCESS_ATTACH_TO_STATUS_BAR_ITEM,
        startupVisibility: contextConstant.StartupVisibility.STARTUP_HIDE
      };

      try {
        this.context.startAbility(want, options, (err: BusinessError) => {
          if (err.code) {
            // 处理业务逻辑错误
            console.error(`startAbility failed, code is ${err.code}, message is ${err.message}`);
            return;
          }
          // 执行正常业务
          console.info('startAbility succeed');
        });
      } catch (err) {
        // 处理入参错误异常
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.error(`startAbility failed, code is ${code}, message is ${message}`);
      }
    }
  }
  ```

## StartupVisibility<sup>12+</sup>

Ability启动后的可见性。该功能仅在2in1和tablet设备上生效。

StartupVisibility作为[StartOptions](js-apis-app-ability-startOptions.md)的一个属性，仅在[UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#startability-1)中生效，用来指定目标Ability启动后的可见性。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称  | 值 | 说明                                                                                                                   |
|-----| -------- |----------------------------------------------------------------------------------------------------------------------|
| STARTUP_HIDE | 0 | 目标Ability启动后，进入隐藏状态。不会调用Ability的onForeground生命周期。        |
| STARTUP_SHOW | 1 | 目标Ability启动后，正常显示。     |

**示例：**

  参见[ContextConstant.ProcessMode](#processmode12)。

## Scenarios<sup>20+</sup>

表示不触发[onNewWant](./js-apis-app-ability-uiAbility.md#onnewwant)生命周期回调场景的枚举，用于[setOnNewWantSkipScenarios](./js-apis-inner-application-uiAbilityContext.md#setonnewwantskipscenarios20)接口。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称  | 值 | 说明                                                                                                                   |
|-----| -------- |----------------------------------------------------------------------------------------------------------------------|
| SCENARIO_MOVE_MISSION_TO_FRONT | 0x00000001 | <!--RP1-->系统接口[missionManager.moveMissionToFront](./js-apis-app-ability-missionManager-sys.md#missionmanagermovemissiontofront-2)接口触发的UIAbility到前台场景。<!--RP1End-->        |
| SCENARIO_SHOW_ABILITY | 0x00000002 | [showAbility](./js-apis-inner-application-uiAbilityContext.md#showability12)接口触发的UIAbility到前台场景。     |
| SCENARIO_BACK_TO_CALLER_ABILITY_WITH_RESULT | 0x00000004 | [backToCallerAbilityWithResult](./js-apis-inner-application-uiAbilityContext.md#backtocallerabilitywithresult12)接口触发的UIAbility到前台场景。     |

**示例：**

```ts
import { AbilityConstant, contextConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let scenarios: number = contextConstant.Scenarios.SCENARIO_MOVE_MISSION_TO_FRONT |
      contextConstant.Scenarios.SCENARIO_SHOW_ABILITY |
      contextConstant.Scenarios.SCENARIO_BACK_TO_CALLER_ABILITY_WITH_RESULT;

    try {
      this.context.setOnNewWantSkipScenarios(scenarios).then(() => {
        // 执行正常业务
        console.info('setOnNewWantSkipScenarios succeed');
      }).catch((err: BusinessError) => {
        // 处理业务逻辑错误
        console.error(`setOnNewWantSkipScenarios failed, code is ${err.code}, message is ${err.message}`);
      });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`setOnNewWantSkipScenarios failed, code is ${code}, message is ${message}`);
    }
  }
}
```