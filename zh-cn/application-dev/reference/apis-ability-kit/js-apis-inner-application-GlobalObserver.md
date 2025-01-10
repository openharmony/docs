# GlobalObserver

定义异常监听，可以作为[ErrorManager.on('globalErrorOccurred')](./js-apis-app-ability-errorManager.md#errormanageronglobalerroroccurred16) 和 [ErrorManager.on('globalUnhandledRejectionDetected')](./js-apis-app-ability-errorManager.md#errormanageronglobalunhandledrejectiondetected16)的入参监听当前应用主线程事件处理事件。

> **说明：**
> 
> 本模块首批接口从API version 16开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 

## 导入模块

```ts
import { errorManager } from '@kit.AbilityKit';
```

## 属性

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| reason | GlobalError | 是 | 有关异常事件名字、消息、错误堆栈信息、异常线程名称和类型的对象。 |

**示例：**

```ts
import { errorManager } from '@kit.AbilityKit';

function errorFunc(observer: errorManager.GlobalObserver) {
    console.log("result name :" + observer.name);
    console.log("result message :" + observer.message);
    console.log("result stack :" + observer.stack);
    console.log("result instanceName :" + observer.instanceName);
    console.log("result instaceType :" + observer.instanceType);
}

errorManager.off('globalErrorOccurred', errorFunc)
```
