# AutoStartupCallback (System API)

The module defines the callback to be invoked when auto-startup is set or canceled for an application component.

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
import { autoStartupManager, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let autoStartupCallback: common.AutoStartupCallback = {
  onAutoStartupOn(data: common.AutoStartupInfo) {
    console.info(`autostartupmanager onAutoStartupOn, data: ${JSON.stringify(data)}.`);
  },
  onAutoStartupOff(data: common.AutoStartupInfo) {
    console.info(`autostartupmanager onAutoStartupOff, data: ${JSON.stringify(data)}.`);
  }
}

try {
  autoStartupManager.on('systemAutoStartup', autoStartupCallback);
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`autoStartupManager.on failed, err code: ${code}, err msg: ${msg}.`);
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
import { autoStartupManager, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let autoStartupCallback: common.AutoStartupCallback = {
  onAutoStartupOn(data: common.AutoStartupInfo) {
    console.info(`autostartupmanager onAutoStartupOn, data: ${JSON.stringify(data)}.`);
  },
  onAutoStartupOff(data: common.AutoStartupInfo) {
    console.info(`autostartupmanager onAutoStartupOff, data: ${JSON.stringify(data)}.`);
  }
}

try {
  autoStartupManager.on('systemAutoStartup', autoStartupCallback);
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`autoStartupManager.on failed, err code: ${code}, err msg: ${msg}.`);
}
```
