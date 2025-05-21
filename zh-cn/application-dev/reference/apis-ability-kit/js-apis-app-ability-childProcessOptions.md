# @ohos.app.ability.ChildProcessOptions

子进程的启动配置选项。通过[childProcessManager](js-apis-app-ability-childProcessManager.md)启动子进程时，可以通过ChildProcessOptions配置子进程启动选项。

> **说明：**
> 
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { ChildProcessOptions } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称        | 类型      | 必填 | 说明                                                               |
| ----------- | --------------------   | ---- | ---------------------------------------------------- |
| isolationMode | boolean | 否 | 表示子进程是否运行在独立沙箱和网络环境中。true表示子进程运行在独立沙箱和网络环境中，false表示与主进程共享沙箱和网络环境。默认为false。|

**示例：**

```ts
import { ChildProcessArgs, ChildProcessOptions, childProcessManager } from '@kit.AbilityKit';

let args: ChildProcessArgs = {};
let options: ChildProcessOptions = {
  isolationMode: false
};
childProcessManager.startArkChildProcess("entry/./ets/process/DemoProcess.ets", args, options);
```
