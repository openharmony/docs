# @ohos.app.ability.ChildProcess

**ChildProcess** is the base class for you to customize child processes. When starting a child process through [childProcessManager](js-apis-app-ability-childProcessManager.md), you must inherit this class and override the entrypoint method.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import ChildProcess from '@ohos.app.ability.ChildProcess';
```

## ChildProcess.onStart

onStart(): void;

Entrypoint method of the child process. This callback is triggered when the child process is started through [childProcessManager](js-apis-app-ability-childProcessManager.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Example**
```ts
import ChildProcess from '@ohos.app.ability.ChildProcess';

export default class DemoProcess extends ChildProcess {
  onStart() {
    console.log("DemoProcess OnStart() called");
  }
}
```
