# @ohos.app.appstartup.StartupConfigEntry (AppStartup Configuration)


The module provides APIs for configuring AppStartup.

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

Called during application startup to configure AppStartup.

**System capability**: SystemCapability.Ability.AppStartup

**Return value**

| Type| Description|
| -------- | -------- |
| StartupConfig | AppStartup configuration.|

**Example**

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

Called to obtain a custom match rule during application launch. Depending on the parameters in the Want passed in, you can return various custom rules to match against the **customization** field in **matchRules** configured for the startup task. If a match is successful, the task is executed automatically. This API is useful when the URI, action, and intent name fail to find a match rule. For details, see [Adding a Task Match Rule](../../application-models/app-startup.md).

**System capability**: SystemCapability.Ability.AppStartup

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target UIAbility.|

**Return value**

| Type| Description|
| -------- | -------- |
| string | Custom match rule, which is used to determine whether to automatically execute the task.|

**Example**

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
