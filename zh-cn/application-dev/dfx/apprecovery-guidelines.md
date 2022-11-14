# 应用恢复开发指导

## 场景介绍

应用在运行中不可避免会产生一些非预期的行为，如运行时抛出未处理的异常和错误，违反框架的调用/运行约束等。

系统默认对异常的处理方式为进程退出，如果应用使用过程中产生了用户数据，直接退出可能会导致用户工作中断，数据丢失。
如果使用应用故障恢复相关接口，则可对临时数据进行保存，应用退出后会重启应用并恢复先前的状态和数据，能给用户带来更好的使用体验。

目前该接口仅支持单进程单Ability的Stage模型应用开发。

## 接口说明

应用故障恢复接口由appRecovery模块提供，开发者可以通过import引入，详见[开发示例](#开发示例)。本文档描述的为API9版本的接口行为，后续接口行为变更会更新本文档。

### 应用恢复接口功能介绍

| 接口名称                                                       | 说明                                                 |
| ------------------------------------------------------------ | ---------------------------------------------------- |
| enableAppRecovery(restart?: RestartFlag, saveOccasion?: SaveOccasionFlag, saveMode?: SaveModeFlag) : void; | 使能应用恢复功能。|
| saveAppState(): boolean; | 主动保存当前应用中Ability的状态。  |
| restartApp(): void; | 重启当前进程，如果有已经保存的Ability状态，会在Ability的OnCreate生命周期回调的want参数中的wantParam属性传入。 |

由于本接口为故障处理时使用，不会返回异常，需要开发者熟悉使用的场景。

**enableAppRecovery:** 需要在应用初始化阶段调用，比如AbilityStage的OnCreate调用赋能。具体其各参数定义详见[参数说明](../reference/apis/js-apis-app-ability-appRecovery.md)。

**saveAppState:** 调用后框架会回调Ability的onSaveState方法，如果在onSaveState方法中同意保存数据，则会将相关数据及Ability的页面栈持久化到应用的本地缓存。

**restartApp:** 调用后框架会杀死当前应用进程，并重新拉起处于前台的Ability，其中启动原因为APP_RECOVERY。

### 框架故障管理理流程示意

故障管理是应用提升用户体验的重要手段。鸿蒙应用框架为开发者提供了故障监听，故障恢复以及故障查询三种方式来管理应用的故障。

- 故障监听指的是通过[errorManager](../reference/apis/js-apis-errorManager.md)注册[ErrorObserver](../reference/apis/js-apis-errorManager.md#errorobserver)，监听故障的发生，并通知到监听方。

- 故障恢复指的是[appRecovery](../reference/apis/js-apis-app-ability-appRecovery.md)，及故障发生后，将应用重启恢复到故障之前的状态。

- 故障查询指的是[faultLogger](../reference/apis/js-apis-faultLogger.md)通过其查询接口获取当前的故障信息。

下图中并没有标记[faultLogger](../reference/apis/js-apis-faultLogger.md)的调用时机，开发者可以根据应用启动时传入的[LastExitReason](../reference/apis/js-apis-application-abilityConstant.md#abilityconstantlastexitreason)来决定是否调用[faultLogger](../reference/apis/js-apis-faultLogger.md)查询上次的故障信息。
![故障处理流程示意](./figures/20221106203527.png)
这里建议应用开发者使用[errorManager](../reference/apis/js-apis-errorManager.md)对应用的异常进行处理，处理完成后开发者可以选择调用状态保存接口并主动重启应用。
如果开发者没有注册[ErrorObserver](../reference/apis/js-apis-errorManager.md#errorobserver)也没有使能自动恢复，则按照系统的默认逻辑执行进程退出。用户可以选择从启动器再次打开应用。
如果开发者使能了自动恢复，框架会首先检查当前故障是否支持状态保存以及开发者是否配置了状态保存，如果支持则会回调[Ability](../reference/apis/js-apis-application-ability.md#ability)的[onSaveState](../reference/apis/js-apis-application-ability.md#abilityonsavestate)的接口。最后重启应用。

### 应用故障管理接口支持场景

通常的故障类型有JS程序Crash、应用程序卡死、C++程序Crash。Crash故障时应用一般都会被关闭。Freeze故障为应用无响应卡屏场景。应用上层无需关注故障类型，底层恢复框架会根据故障类型来实现不同场景的故障管理。

| 故障名称   | 故障监听  | 状态保存 | 自动重启 | 日志查询 |
| ----------|--------- |--------- |--------- |--------- |
| [JS_CRASH](../reference/apis/js-apis-faultLogger.md#faulttype) | 支持|支持|支持|支持|
| [APP_FREEZE](../reference/apis/js-apis-faultLogger.md#faulttype) | 不支持|不支持|支持|支持|
| [CPP_CRASH](../reference/apis/js-apis-faultLogger.md#faulttype) | 不支持|不支持|不支持|支持|

这里状态保存指的是故障时状态保存，对于应用卡死场景，开发者可以采用定时保存状态或者在Ability切入后台后自动保存的方式最大限度的保护用户数据。



## 开发示例

### 使能开启自恢复特性

   开发者需要在应用模块初始化时使能appRecovery功能。下面为示例的AbilityStage。

```ts
import AbilityStage from '@ohos.app.ability.AbilityStage'
import appRecovery from '@ohos.app.ability.appRecovery'

export default class MyAbilityStage extends AbilityStage {
    onCreate() {
        console.info("[Demo] MyAbilityStage onCreate")
        appRecovery.enableAppRecovery(appRecovery.RestartFlag.ALWAYS_RESTART,
            appRecovery.SaveOccasionFlag.SAVE_WHEN_ERROR | appRecovery.SaveOccasionFlag.SAVE_WHEN_BACKGROUND,
            appRecovery.SaveModeFlag.SAVE_WITH_FILE);
    }
}
```

### 数据保存和恢复

在使能appRecovery功能后，开发者可以在Ability中采用主动保存状态，主动恢复或者选择被动恢复的方式使用appRecovery功能。
下面为示例的MainAbility。

#### 导包

```ts
import errorManager from '@ohos.app.ability.errorManager'
import appRecovery from '@ohos.app.ability.appRecovery'
import AbilityConstant from '@ohos.app.ability.AbilityConstant'
```

#### 主动触发保存和恢复

- 定义和注册[ErrorObserver](../reference/apis/js-apis-errorManager.md#errorobserver) callback

```ts
  var registerId = -1;
  var callback = {
      onUnhandledException: function (errMsg) {
          console.log(errMsg);
          appRecovery.saveAppState();
          appRecovery.restartApp();
      }
  }

  onWindowStageCreate(windowStage) {
      // Main window is created, set main page for this ability
      console.log("[Demo] MainAbility onWindowStageCreate")

      globalThis.registerObserver = (() => {
          registerId = errorManager.registerErrorObserver(callback);
      })

      windowStage.loadContent("pages/index", null);
  }
```

- 数据保存

callback触发appRecovery.saveAppState()调用后，会触发MainAbility的onSaveState(state, wantParams)函数回调。

```ts
  onSaveState(state, wantParams) {
      // Ability has called to save app data
      console.log("[Demo] MainAbility onSaveState")
      wantParams["myData"] = "my1234567";
      return AbilityConstant.onSaveResult.ALL_AGREE;
  }
```

- 数据恢复

callback触发后appRecovery.restartApp()调用后，应用会重启，重启后会走到MainAbility的onSaveState(state, wantParams)函数，保存的数据会在want参数的parameters里。

```ts
storage: LocalStorage
onCreate(want, launchParam) {
    console.log("[Demo] MainAbility onCreate")
    globalThis.abilityWant = want;
    if (launchParam.launchReason == AbilityConstant.LaunchReason.APP_RECOVERY) {
        this.storage = new LocalStorage();
        let recoveryData = want.parameters["myData"];
        this.storage.setOrCreate("myData", recoveryData);
        this.context.restoreWindowStage(this.storage);
    }
}
```

- 取消注册ErrorObserver callback

```ts
onWindowStageDestroy() {
    // Main window is destroyed, release UI related resources
    console.log("[Demo] MainAbility onWindowStageDestroy")

    globalThis.unRegisterObserver = (() => {
        errorManager.unregisterErrorObserver(registerId, (result) => {
            console.log("[Demo] result " + result.code + ";" + result.message)
        });
    })
}
```

#### 被动保存和恢复

被动保存和恢复依赖恢复框架底层触发，无需注册监听ErrorObserver callback，只需实现Ability的onSaveState接口数据保存和onCreate接口数据恢复流程即可。

```ts
export default class MainAbility extends Ability {
    storage: LocalStorage
    onCreate(want, launchParam) {
        console.log("[Demo] MainAbility onCreate")
        globalThis.abilityWant = want;
        if (launchParam.launchReason == AbilityConstant.LaunchReason.APP_RECOVERY) {
            this.storage = new LocalStorage();
            let recoveryData = want.parameters["myData"];
            this.storage.setOrCreate("myData", recoveryData);
            this.context.restoreWindowStage(this.storage);
        }
    }

    onSaveState(state, wantParams) {
        // Ability has called to save app data
        console.log("[Demo] MainAbility onSaveState")
        wantParams["myData"] = "my1234567";
        return AbilityConstant.onSaveResult.ALL_AGREE;
    }
}
```

