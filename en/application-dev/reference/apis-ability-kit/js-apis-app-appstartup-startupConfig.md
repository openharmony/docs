# @ohos.app.appstartup.StartupConfig

The @ohos.app.appstartup.StartupConfig module provides the configuration of component initialization.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```js
import { StartupConfig } from '@kit.AbilityKit';
```

## Properties

**System capability**: SystemCapability.Ability.AppStartup

  | Name| Type| Read Only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| timeoutMs | number | Yes| No| Timeout for initializing all components. The default value is 10000 ms.|
| startupListener | [StartupListener](./js-apis-app-appstartup-startupListener.md) | Yes| No| AppStartup framework listener, which is called when all the components are initialized.|

**Example**

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
