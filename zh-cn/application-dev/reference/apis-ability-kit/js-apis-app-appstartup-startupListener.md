# @ohos.app.appstartup.StartupListener


本模块提供监听组件初始化的能力。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import StartupListener from '@ohos.app.appstartup.StartupListener';
```

## StartupListener.onCompleted

onCompleted?(error: BusinessError\<void\>): void

在所有组件初始化完成时调用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AppStartup

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| error | [BusinessError](../apis-basic-services-kit/js-apis-base.md#businesserror) | 是 | 错误信息。 |

**示例：**

```ts
import StartupConfig from '@ohos.app.appstartup.StartupConfig';
import StartupConfigEntry from '@ohos.app.appstartup.StartupConfigEntry';
import StartupListener from '@ohos.app.appstartup.StartupListener';

export default class MyStartupConfigEntry extends StartupConfigEntry {
  onConfig() {
    console.info('StartupTest MyStartupConfigEntry onConfig');
    let onCompletedCallback = (error) => {
      console.info('StartupTest MyStartupConfigEntry callback, error=' + JSON.stringify(error));
      if (error) {
        console.error('onCompletedCallback: %{public}d, mssage: %{public}s', error.code, error.mssage);
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