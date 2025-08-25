# @ohos.app.ability.ChildProcess (子进程基类)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

开发者自定义子进程的基类。通过[childProcessManager](js-apis-app-ability-childProcessManager.md)启动子进程时，需要继承此类并重写入口方法。

> **说明：**
> 
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { ChildProcess } from '@kit.AbilityKit';
```

## ChildProcess.onStart

onStart(args?: ChildProcessArgs): void

子进程的入口方法，通过[childProcessManager](js-apis-app-ability-childProcessManager.md)启动子进程后调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | args<sup>12+</sup> | [ChildProcessArgs](js-apis-app-ability-childProcessArgs.md) | 否 | 传递到子进程的参数。 |

**示例：**
```ts
import { ChildProcess, ChildProcessArgs } from '@kit.AbilityKit';

export default class DemoProcess extends ChildProcess {

  onStart(args?: ChildProcessArgs) {
    let entryParams = args?.entryParams;
    let fd = args?.fds?.key1;
    // ..
  }
}
```