# @ohos.app.appstartup.StartupConfigEntry (启动框架配置)


本模块提供[应用启动框架](../../application-models/app-startup.md)配置的能力。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { StartupConfigEntry } from '@kit.AbilityKit';
```

## StartupConfigEntry

### onConfig

onConfig?(): StartupConfig

在回调[AbilityStage.onCreate](js-apis-app-ability-abilityStage.md#oncreate)前，若该AbilityStage对应的HAP中启动框架配置文件中[定义了启动框架配置](../../application-models/app-startup.md#定义启动框架配置文件)，则会触发该回调。

开发者可以在该回调中设置启动框架配置信息，详细使用方法可参考[设置启动参数](../../application-models/app-startup.md#设置启动参数)章节。

**系统能力**：SystemCapability.Ability.AppStartup

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [StartupConfig](js-apis-app-appstartup-startupConfig.md#startupconfig) | 启动框架配置信息。 |

**示例：**

```ts
import { StartupConfig, StartupConfigEntry, StartupListener } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class MyStartupConfigEntry extends StartupConfigEntry {
  onConfig() {
    hilog.info(0x0000, 'testTag', `onConfig`);
    let onCompletedCallback = (error: BusinessError<void>) => {
      hilog.info(0x0000, 'testTag', `onCompletedCallback`);
      if (error) {
        hilog.info(0x0000, 'testTag', 'onCompletedCallback: %{public}d, message: %{public}s', error.code,
          error.message);
      } else {
        hilog.info(0x0000, 'testTag', `onCompletedCallback: success.`);
      }
    }
    let startupListener: StartupListener = {
      'onCompleted': onCompletedCallback
    }
    let config: StartupConfig = {
      'timeoutMs': 10000,
      'startupListener': startupListener
    }
    return config;
  }
}
```
