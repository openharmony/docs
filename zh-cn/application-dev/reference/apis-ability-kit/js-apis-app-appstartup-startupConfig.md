# @ohos.app.appstartup.StartupConfig

本模块提供组件初始化的配置接口。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```js
import { StartupConfig } from '@kit.AbilityKit';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AppStartup

  | 名称 | 类型 | 只读 | 必填 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| timeoutMs | number | 是 | 否 | 执行所有组件初始化的超时时间，默认值为10000毫秒。 |
| startupListener | [StartupListener](./js-apis-app-appstartup-startupListener.md) | 是 | 否 | 表示启动框架的监听器，该监听器将在所有组件初始化完成时调用。 |

**示例：**

```ts
import { StartupConfig, StartupConfigEntry, StartupListener } from '@kit.AbilityKit';
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
