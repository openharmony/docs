# @ohos.app.ability.ChildProcessOptions

The ChildProcessOptions module describes the startup configuration of a child process. When starting a child process through [childProcessManager](js-apis-app-ability-childProcessManager.md), you can configure the startup configuration of the child process through **ChildProcessOptions**.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { ChildProcessOptions } from '@kit.AbilityKit';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name       | Type     | Mandatory| Description                                                              |
| ----------- | --------------------   | ---- | ---------------------------------------------------- |
| isolationMode | boolean | No| Whether the child process runs in an independent sandbox and network environment. The value **true** means that the child process runs in an independent sandbox and network environment, and **false** means that the child process shares the sandbox and network environment with the main process. The default value is **false**.|

**Example**

```ts
import { ChildProcessArgs, ChildProcessOptions, childProcessManager } from '@kit.AbilityKit';

let args: ChildProcessArgs = {};
let options: ChildProcessOptions = {
  isolationMode: false
};
childProcessManager.startArkChildProcess("entry/./ets/process/DemoProcess.ets", args, options);
```
