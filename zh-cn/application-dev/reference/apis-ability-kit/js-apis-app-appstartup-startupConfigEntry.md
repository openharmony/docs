# @ohos.app.appstartup.StartupConfigEntry


本模块提供应用启动框架配置的能力。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { StartupConfigEntry } from '@kit.AbilityKit';
```

## StartupConfigEntry.onConfig

onConfig?(): StartupConfig

应用启动时调用以配置应用启动框架的设置。

**系统能力**：SystemCapability.Ability.AppStartup

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| StartupConfig | 启动框架配置。 |

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
        hilog.info(0x0000, 'testTag', 'onCompletedCallback: %{public}d, message: %{public}s', error.code, error.message);
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

## StartupConfigEntry.onRequestCustomMatchRule<sup>20+</sup>

onRequestCustomMatchRule(want: Want): string

应用启动时，启动框架会调用此接口获取自定义匹配规则。可以根据传入Want中的不同参数来返回不同的自定义规则值，并与启动任务配置的matchRules中customization字段进行匹配。若匹配成功，任务将在自动模式执行。当uri、action和意图名称匹配规则都无法满足时，可以使用此接口。详细说明请参考[添加任务匹配规则](../../application-models/app-startup.md#可选添加任务匹配规则)章节。

**系统能力**：SystemCapability.Ability.AppStartup

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动UIAbility的Want信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回自定义匹配规则值，用于匹配启动任务是否自动执行。 |

**示例：**

```ts
import { StartupConfig, StartupConfigEntry, StartupListener, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class MyStartupConfigEntry extends StartupConfigEntry {

  // ...

  onRequestCustomMatchRule(want: Want): string {
    if (want?.parameters?.customParam == 'param1') {
      return 'customRule1';
    }
    return "";
  }
}
```