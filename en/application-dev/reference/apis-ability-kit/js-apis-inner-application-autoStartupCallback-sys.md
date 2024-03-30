# AutoStartupCallback (System API)

The **AutoStartupCallback** module defines the callback to be invoked when auto-startup is set or canceled for an application component.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
> The APIs provided by this module are system APIs.

## AutoStartupCallback.onAutoStartupOn

onAutoStartupOn(info: AutoStartupInfo): void;

Called when auto-startup is set for an application component.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| info | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)   | Yes| Information about the target application component.|

**Example**

```ts
import AutoStartupManager from '@ohos.app.ability.autoStartupManager';
import common from '@ohos.app.ability.common';

let autoStartupCallback: common.AutoStartupCallback = {
  onAutoStartupOn(data: common.AutoStartupInfo) {
    console.info('===> autostartupmanager onAutoStartupOn data: ' + JSON.stringify(data));
  },
  onAutoStartupOff(data: common.AutoStartupInfo) {
    console.info('===> autostartupmanager onAutoStartupOff data: ' + JSON.stringify(data));
  }
}
try {
  AutoStartupManager.on('systemAutoStartup', autoStartupCallback)
} catch (err) {
  console.info('===> autostartupmanager on callback err: ' + JSON.stringify(err));
}
```

## AutoStartupCallback.onAutoStartupOff

onAutoStartupOff(info: AutoStartupInfo): void;

Called when the auto-startup setting of an application component is canceled.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type           | Mandatory| Description                |
| ------ | --------------- | ---- | -------------------- |
| info   | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)   | Yes  | Information about the target application component.|

**Example**

```ts
import AutoStartupManager from '@ohos.app.ability.autoStartupManager';
import common from '@ohos.app.ability.common';

let autoStartupCallback: common.AutoStartupCallback = {
  onAutoStartupOn(data: common.AutoStartupInfo) {
    console.info('===> autostartupmanager onAutoStartupOn data: ' + JSON.stringify(data));
  },
  onAutoStartupOff(data: common.AutoStartupInfo) {
    console.info('===> autostartupmanager onAutoStartupOff data: ' + JSON.stringify(data));
  }
}
try {
  AutoStartupManager.on('systemAutoStartup', autoStartupCallback)
} catch (err) {
  console.info('===> autostartupmanager on callback err: ' + JSON.stringify(err));
}
```
