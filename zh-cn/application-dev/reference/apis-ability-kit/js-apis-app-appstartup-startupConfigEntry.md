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

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AppStartup

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| StartupConfig | 启动框架配置。 |

**示例：**

```ts
import { StartupConfigEntry, StartupConfig, StartupListener } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class MyStartupConfigEntry extends StartupConfigEntry {
  onConfig() {
    console.info('StartupTest MyStartupConfigEntry onConfig');
    let onCompletedCallback = (error: BusinessError) => {
      console.info('StartupTest MyStartupConfigEntry callback, error=' + JSON.stringify(error));
      if (error) {
        console.error('onCompletedCallback: %{public}d, message: %{public}s', error.code, error.message);
      } else {
        console.info('onCompletedCallback: success');
      }
    }
    let startupListener: StartupListener = {
      'onCompleted': onCompletedCallback
    }
    let config: StartupConfig = {
      'timeoutMs': 5000,
      'startupListener': startupListener
    }
    return config;
  }
}
```
