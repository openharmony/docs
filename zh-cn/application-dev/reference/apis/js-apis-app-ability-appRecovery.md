# appRecovery

appRecovery模块提供应用故障状态恢复能力。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。当前版本仅支持单进程中单Ability的应用恢复。

## 导入模块
```
import appRecovery from '@ohos.app.ability.appRecovery'
```


## appRecovery.RestartFlag

[enableAppRecovery](#apprecoveryenableapprecovery)接口重启选项参数。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 变量                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| ALWAYS_RESTART           | 0    | 总是重启应用。 |
| CPP_CRASH_NO_RESTART           | 1    | 发生CPP_CRASH时不重启应用。 |
| JS_CRASH_NO_RESTART           | 2    | 发生JS_CRASH时不重启应用。 |
| APP_FREEZE_NO_RESTART           | 4    | 发生APP_FREEZE时不重启应用。 |
| NO_RESTART           | 65535  | 总是不重启应用。 |

## appRecovery.SaveOccasionFlag

[enableAppRecovery](#apprecoveryenableapprecovery)接口状态保存时机选项参数。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 变量                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| SAVE_WHEN_ERROR            | 1    | 当发生应用故障时保存。 |
| SAVE_WHEN_BACKGROUND            | 2    | 当应用切入后台时保存。 |

## appRecovery.SaveModeFlag  

[enableAppRecovery](#apprecoveryenableapprecovery)接口状态保存方式的参数。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 变量                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| SAVE_WITH_FILE             | 1    | 每次状态保存都会写入到本地文件缓存。 |
| SAVE_WITH_SHARED_MEMORY             | 2    | 状态先保存在内存中，应用故障退出时写入到本地文件缓存。 |

## appRecovery.enableAppRecovery

enableAppRecovery(restart?: RestartFlag, saveOccasion?: SaveOccasionFlag, saveMode?: SaveModeFlag) : void;

使能应用恢复功能，参数按顺序填入。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| restart | [RestartFlag](#apprecoveryrestartflag) | 否 | 发生对应故障时是否重启，默认为不重启 |
| saveOccasion | [SaveOccasionFlag](#apprecoverysaveoccasionflag) | 否 | 状态保存时机，默认为故障时保存 |
| saveMode | [SaveModeFlag](#apprecoverysavemodeflag) | 否 | 状态保存方式， 默认为文件缓存 |

**示例：**
    
```js
export default class MyAbilityStage extends AbilityStage {
    onCreate() {
        appRecovery.enableAppRecovery(RestartFlag::ALWAYS_RESTART, SaveOccasionFlag::SAVE_WHEN_ERROR, SaveModeFlag::SAVE_WITH_FILE);
    }
}
```

## appRecovery.restartApp

restartApp(): void;

重启当前App进程，可以配合[errorManager](js-apis-errorManager.md#errorobserver)相关接口使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core


**示例：**
    
```js
var observer = {
    onUnhandledException(errorMsg) {
        console.log('onUnhandledException, errorMsg: ', errorMsg)
        appRecovery.restartApp();
    }
}

```

## appRecovery.saveAppState

saveAppState(): boolean;

保存当前App状态，可以配合[errorManager](js-apis-errorManager.md#errorobserver)相关接口使用

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 保存成功与否。 |

**示例：**
    
```js
var observer = {
    onUnhandledException(errorMsg) {
        console.log('onUnhandledException, errorMsg: ', errorMsg)
        appRecovery.saveAppState();
    }
}

```
