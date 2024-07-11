# @ohos.app.appstartup.StartupConfigEntry


The @ohos.app.appstartup.StartupConfigEntry module provides the API for configuring the AppStartup framework.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { StartupConfigEntry } from '@kit.AbilityKit';
```

## StartupConfigEntry.onConfig

onConfig?(): StartupConfig

Called during application startup to configure the AppStartup framework.

**System capability**: SystemCapability.Ability.AppStartup

**Return value**

| Type| Description|
| -------- | -------- |
| StartupConfig | AppStartup framework configuration.|

**Example**

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
