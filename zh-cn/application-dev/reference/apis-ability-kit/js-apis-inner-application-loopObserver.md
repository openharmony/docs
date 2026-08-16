# LoopObserver

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @Chenyufan466765692-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe--> 
<!--Adviser: @jinqiuheng-->

定义应用主线程异常监听，可以作为[ErrorManager.on](./js-apis-app-ability-errorManager.md#errormanageronloopobserver12)的入参，用于监听应用主线程事件处理超时的情况。通过回调机制实时获取主线程消息实际执行时间，帮助开发者及时发现和定位故障问题。

> **说明：**
> 
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 

## 导入模块

```ts
import { errorManager } from '@kit.AbilityKit';
```

## LoopObserver.onLoopTimeOut

onLoopTimeOut?(timeout: number): void

当JS运行时应用主线程处理事件超时时触发的回调函数。

使用场景：用于监控应用主线程处理事件的执行情况，当主线程处理事件超时时触发该回调，开发者可以根据超时情况记录日志、优化代码逻辑等。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| timeout | number | 是 | 表示应用主线程消息实际执行时间，单位：毫秒，取值范围：大于0的正整数。 |

**示例：**

```ts
import { errorManager } from '@kit.AbilityKit';

let observer: errorManager.LoopObserver = {
  onLoopTimeOut(timeout: number) {
    console.info('Duration timeout: ' + timeout);
  }
};

errorManager.on('loopObserver', 1, observer);
```
