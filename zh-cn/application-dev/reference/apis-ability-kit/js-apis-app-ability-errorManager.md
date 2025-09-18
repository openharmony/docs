# @ohos.app.ability.errorManager (错误管理模块)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @rr_cn-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

ErrorManager模块提供对错误观测器的注册和注销的能力，主要是观测应用发生js crash和appfreeze等错误。

> **说明**：
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块
```ts
import { errorManager } from '@kit.AbilityKit';
```

## errorManager.on('error')

on(type: 'error', observer: ErrorObserver): number

注册错误观测器。注册后可以捕获到应用产生的js crash，属于应用崩溃的一种。观测器捕获到该异常时应用不退出，建议在回调函数执行完后，增加同步退出操作。

仅在主线程中使用。使用线程出错时，将抛出错误码，因此建议使用try-catch逻辑进行处理。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'error'，表示错误观测器。 |
| observer | [ErrorObserver](js-apis-inner-application-errorObserver.md) | 是 | 错误观测器。 |

**返回值**：

  | 类型 | 说明 |
  | -------- | -------- |
  | number | 观测器的索引值，与观测器一一对应。可用于`errorManager.off`函数中的`observerId`参数。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16000003 | The specified ID does not exist. |

**示例**：
    
```ts
import { errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observer: errorManager.ErrorObserver = {
  onUnhandledException(errorMsg) {
    console.info('onUnhandledException, errorMsg: ', errorMsg);
  },
  onException(errorObj) {
    console.info('onException, name: ', errorObj.name);
    console.info('onException, message: ', errorObj.message);
    if (typeof(errorObj.stack) === 'string') {
      console.info('onException, stack: ', errorObj.stack);
    }
  }
};
let observerId = -1;

try {
  observerId = errorManager.on('error', observer);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message}`);
}
```

## errorManager.on('globalErrorOccurred')<sup>18+</sup>

on(type: 'globalErrorOccurred', observer: GlobalObserver): void

在进程中的任意线程中注册 `errormanager.on` 接口，监听整个进程中任意线程的异常。观测器捕获到该异常时应用不退出，建议在回调函数执行完后，增加同步退出操作。

**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'globalErrorOccurred'，表示错误观测器。 |
| observer | [GlobalObserver](#globalobserver18) | 是 | 自定义异常处理回调函数。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16200001 | The caller has been released. |

**示例**：
    
```ts
import { errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

function errorFunc(observer: errorManager.GlobalError) {
    console.info("result name :" + observer.name);
    console.info("result message :" + observer.message);
    console.info("result stack :" + observer.stack);
    console.info("result instanceName :" + observer.instanceName);
    console.info("result instanceType :" + observer.instanceType);
}

try {
  errorManager.on('globalErrorOccurred', errorFunc);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message}`);
}
```

## errorManager.off('globalErrorOccurred')<sup>18+</sup>

off(type: 'globalErrorOccurred', observer?: GlobalObserver): void

注销错误观测器，注销之前注册在同一线程的callback全局监听。

如果传入的回调不在通过on方法注册的回调队列中，将抛出16300004错误码，因此建议使用try-catch逻辑进行处理。

**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'globalErrorOccurred'，表示错误观测器。 |
| observer | [GlobalObserver](#globalobserver18) | 否 | 由on方法注册的callback。建议使用该参数，缺省时默认清除所有通过on注册的相同env的callback，否则删除指定callback。  |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16200001 | The caller has been released. |
| 16300004 | The observer does not exist. |

**示例**：
    
```ts
import { errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

function errorFunc(observer: errorManager.GlobalError) {
    console.info("result name :" + observer.name);
    console.info("result message :" + observer.message);
    console.info("result stack :" + observer.stack);
    console.info("result instanceName :" + observer.instanceName);
    console.info("result instanceType :" + observer.instanceType);
}

try {
  errorManager.off('globalErrorOccurred', errorFunc)
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message}`);
}
```

## errorManager.off('error')

off(type: 'error', observerId: number,  callback: AsyncCallback\<void>): void

注销错误观测器。使用callback异步返回。

仅在主线程中使用。使用线程出错时，将抛出错误码，因此建议使用try-catch逻辑进行处理。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'error'，表示错误观测器。 |
| observerId | number | 是 | 由on方法返回的观测器的index值。 |
| callback | AsyncCallback\<void> | 是 | 表示指定的回调方法。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16000003 | The specified ID does not exist. |

**示例**：
    
```ts
import { errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observerId = 100;

function unregisterErrorObserverCallback(err: BusinessError) {
  if (err) {
    console.error('------------ unregisterErrorObserverCallback ------------', err);
  }
}

try {
  errorManager.off('error', observerId, unregisterErrorObserverCallback);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message}`);
}
```

## errorManager.off('error')

off(type: 'error', observerId: number): Promise\<void>

注销错误观测器。使用Promise异步返回。

仅在主线程中使用。使用线程出错时，将抛出错误码，因此建议使用try-catch逻辑进行处理。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'error'，表示错误观测器。 |
| observerId | number | 是 | 由on方法返回的观测器的index值。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16000003 | The specified ID does not exist. |

**示例**：
    
```ts
import { errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observerId = 100;

try {
  errorManager.off('error', observerId)
    .then((data) => {
      console.info('----------- unregisterErrorObserver success ----------', data);
    })
    .catch((err: BusinessError) => {
      console.error('----------- unregisterErrorObserver fail ----------', err);
    });
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message}`);
}
```

## errorManager.on('loopObserver')<sup>12+</sup>

on(type: 'loopObserver', timeout: number, observer: LoopObserver): void

注册主线程消息处理耗时监听器。注册后可以捕获到应用主线程处理消息的具体执行时间。

仅在主线程中使用。使用线程出错时，将抛出错误码，因此建议使用try-catch逻辑进行处理。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'loopObserver'，表示注册主线程消息处理耗时监听器。 |
| timeout | number | 是 |  表示事件执行阈值（单位：毫秒）。 阈值必须大于0。 |
| observer | [LoopObserver](js-apis-inner-application-loopObserver.md) | 是 | 注册主线程消息处理耗时监听器。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |

**示例**：
    
```ts
import { errorManager } from '@kit.AbilityKit';

let observer: errorManager.LoopObserver = {
  onLoopTimeOut(timeout: number) {
    console.info('Duration timeout: ' + timeout);
  }
};

errorManager.on("loopObserver", 1, observer);
```

## errorManager.on('globalUnhandledRejectionDetected')<sup>18+</sup>

on(type: 'globalUnhandledRejectionDetected', observer: GlobalObserver): void

在进程中任意线程注册被拒绝promise监听器，注册后可以捕获到当前进程中未被捕获到的promise rejection。

**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：
 
| 参数名                   | 类型                                                          | 必填 | 说明                                       |
|-----------------------|-------------------------------------------------------------| -------- |------------------------------------------|
| type                  | string                                                      | 是 | 填写'globalUnhandledRejectionDetected'，表示注册被拒绝promise监听器。 |
| observer              | [GlobalObserver](#globalobserver18) | 是 | 注册被拒绝promise的callback。                          |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16200001 | The caller has been released. |

**示例**：

```ts
import { errorManager } from '@kit.AbilityKit';

function promiseFunc(observer: errorManager.GlobalError) {
  console.info("result name :" + observer.name);
  console.info("result message :" + observer.message);
  console.info("result stack :" + observer.stack);
  console.info("result instanceName :" + observer.instanceName);
  console.info("result instanceType :" + observer.instanceType);
}

errorManager.on("globalUnhandledRejectionDetected", promiseFunc);
// 建议在抛出promise异常时，使用async抛出异常。
async function throwError() {
  throw new Error("uncaught error");
}

let promise1 = new Promise<void>(() => {}).then(() => {
  throwError();
});
```

## errorManager.on('unhandledRejection')<sup>12+</sup>

on(type: 'unhandledRejection', observer: UnhandledRejectionObserver): void

注册被拒绝promise监听器。注册后可以捕获到当前线程中未被捕获到的promise rejection。

仅在主线程中使用。使用线程出错时，将抛出错误码，因此建议使用try-catch逻辑进行处理。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：
 
| 参数名                   | 类型                                                          | 必填 | 说明                                       |
|-----------------------|-------------------------------------------------------------| -------- |------------------------------------------|
| type                  | string                                                      | 是 | 填写'unhandledRejection'，表示注册被拒绝promise监听器。 |
| observer              | [UnhandledRejectionObserver](#unhandledrejectionobserver12) | 是 | 注册被拒绝promise监听器。                          |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16200001 | The caller has been released. |

**示例**：
    
```ts
import { errorManager } from '@kit.AbilityKit';

let observer: errorManager.UnhandledRejectionObserver = (reason: Error, promise: Promise<void>) => {
  if (promise === promise1) {
    console.info("promise1 is rejected");
  }
  console.info("reason.name: ", reason.name);
  console.info("reason.message: ", reason.message);
  if (reason.stack) {
    console.info("reason.stack: ", reason.stack);
  }
};

errorManager.on("unhandledRejection", observer);

let promise1 = new Promise<void>(() => {}).then(() => {
  throw new Error("uncaught error");
});
```
## errorManager.on('freeze')<sup>18+</sup>

on(type: 'freeze', observer: FreezeObserver): void

注册应用主线程freeze监听。多次注册情况下，取最后一次注册的结果。

仅在主线程中使用。使用线程出错时，将抛出错误码，因此建议使用try-catch逻辑进行处理。

> **注意**：
>
> 如果该回调函数执行时间超过1s，可能导致[AppRecovery](./js-apis-app-ability-appRecovery.md)功能不可用。通过解析hilog日志中的begin与Freeze callback execution completed两者的时间差可以计算回调函数执行时长，如果超过1秒，可以尝试采用异步处理、减少阻塞操作、优化数据结构等方法优化回调逻辑，降低执行时长。
> 

**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'freeze'，表示应用主线程freeze观测器。 |
| observer | [FreezeObserver](#freezeobserver18) | 是 | 由on接口注册的freeze监听的callback。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.   |

**示例**：
    
```ts
import { errorManager } from '@kit.AbilityKit';

function freezeCallback() {
    console.info("freezecallback");
}
errorManager.on("freeze", freezeCallback);
```

## errorManager.off('loopObserver')<sup>12+</sup>

off(type: 'loopObserver', observer?: LoopObserver): void

注销主线程消息处理监听器。

仅在主线程中使用。使用线程出错时，将抛出错误码，因此建议使用try-catch逻辑进行处理。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'loopObserver'，表示应用主线程观测器。 |
| observer | [LoopObserver](js-apis-inner-application-loopObserver.md) | 否 | 应用主线程观测器标志。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |

**示例**：
    
```ts
import { errorManager } from '@kit.AbilityKit';

errorManager.off("loopObserver");
```

## errorManager.off('globalUnhandledRejectionDetected')<sup>18+</sup>

off(type: 'globalUnhandledRejectionDetected', observer?: GlobalObserver): void

注销被拒绝promise监听器，注销后无法监听进程中的promise异常。

如果传入的回调不在通过on方法注册的回调队列中，将抛出16300004错误码，因此建议使用try-catch逻辑进行处理。

**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名                   | 类型                              | 必填 | 说明                                           |
|-----------------------|---------------------------------|----|----------------------------------------------|
| type                  | string                          | 是  | 填写'globalUnhandledRejectionDetected'，表示注册被拒绝promise监听器。 |
| observer              | [GlobalObserver](#globalobserver18) | 否  | 由on接口注册的被拒绝promise的callback。建议使用该参数，缺省时默认清除所有通过on注册的相同env的callback，否则删除指定callback。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16200001 | The caller has been released. |
| 16300004 | The observer does not exist. |

**示例**：
    
```ts
import { errorManager } from '@kit.AbilityKit';

function promiseFunc(observer: errorManager.GlobalError) {
  console.info("result name :" + observer.name);
  console.info("result message :" + observer.message);
  console.info("result stack :" + observer.stack);
  console.info("result instanceName :" + observer.instanceName);
  console.info("result instanceType :" + observer.instanceType);
}

errorManager.on("globalUnhandledRejectionDetected", promiseFunc);

async function throwError() {
  throw new Error("uncaught error");
}

let promise1 = new Promise<void>(() => {}).then(() => {
  throwError();
});

errorManager.off("globalUnhandledRejectionDetected", promiseFunc);
```

## errorManager.off('unhandledRejection')<sup>12+</sup>

off(type: 'unhandledRejection', observer?: UnhandledRejectionObserver): void

注销被拒绝promise监听器。

仅在主线程中使用。使用线程出错时，将抛出错误码，因此建议使用try-catch逻辑进行处理。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名                   | 类型                              | 必填 | 说明                                           |
|-----------------------|---------------------------------|----|----------------------------------------------|
| type                  | string                          | 是  | 填写'unhandledRejection'，表示注册被拒绝promise监听器。 |
| observer              | [UnhandledRejectionObserver](#unhandledrejectionobserver12) | 否  | 注册了被拒绝promise监听器。建议使用该参数，缺省时默认清除所有通过on注册的相同env的observer，否则删除指定observer。                        |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16200001 | The caller has been released. |
| 16300004 | The observer does not exist. |

**示例**：
    
```ts
import { errorManager } from '@kit.AbilityKit';

let observer: errorManager.UnhandledRejectionObserver = (reason: Error, promise: Promise<void>) => {
  if (promise === promise1) {
    console.info("promise1 is rejected");
  }
  console.info("reason.name: ", reason.name);
  console.info("reason.message: ", reason.message);
  if (reason.stack) {
    console.info("reason.stack: ", reason.stack);
  }
};

errorManager.on("unhandledRejection", observer);

let promise1 = new Promise<void>(() => {}).then(() => {
  throw new Error("uncaught error")
})

errorManager.off("unhandledRejection");
```
或者
```ts
import { errorManager } from '@kit.AbilityKit';

let observer: errorManager.UnhandledRejectionObserver = (reason: Error, promise: Promise<void>) => {
  if (promise === promise1) {
    console.info("promise1 is rejected");
  }
  console.info("reason.name: ", reason.name);
  console.info("reason.message: ", reason.message);
  if (reason.stack) {
    console.info("reason.stack: ", reason.stack);
  }
};

errorManager.on("unhandledRejection", observer);

let promise1 = new Promise<void>(() => {}).then(() => {
  throw new Error("uncaught error")
})

errorManager.off("unhandledRejection", observer);
```

## errorManager.off('freeze')<sup>18+</sup>

off(type: 'freeze', observer?: FreezeObserver): void

取消之前注册的应用主线程freeze监听。

仅在主线程中使用。使用线程出错时，将抛出错误码，因此建议使用try-catch逻辑进行处理。

如果传入的回调与通过on方法注册回调不一致，将抛出16300004错误码，因此建议使用try-catch逻辑进行处理。

**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'freeze'，表示应用主线程freeze观测器。 |
| observer | [FreezeObserver](#freezeobserver18) | 否 | 由on接口注册的freeze监听的callback。建议使用该参数，如果参数不填会直接清空callback，否则删除指定的callback。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 16300004 | The observer does not exist. |

**示例**：
    
```ts
import { errorManager } from '@kit.AbilityKit';

function freezeCallback() {
    console.info("freezecallback");
}
errorManager.on("freeze", freezeCallback);
errorManager.off("freeze", freezeCallback);
```

## errorManager.setDefaultErrorHandler<sup>21+</sup>

setDefaultErrorHandler(defaultHandler?: ErrorHandler): ErrorHandler

发生JS_CRASH异常时，支持链式回调，返回上一次注册的处理器，仅限主线程调用。

如果传入非法参数或在子线程调用，将抛出错误码并返回undefined，因此建议使用try-catch逻辑进行处理。

若接口参数为空，后续注册的处理器将无法与前序已注册的处理器建立关联，从而中断链式调用。

**原子化服务API**：从API version 21开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| defaultHandler | [ErrorHandler](#errorhandler21) | 否 | 新注册的错误处理器，缺省时默认值为空。|

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [ErrorHandler](#errorhandler21) | 返回上一次注册的错误处理器。 |

**错误码**：

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000205      | The API is not called in the main thread. |

**示例**：
    
```ts
import { errorManager } from '@kit.AbilityKit';
import { process } from '@kit.ArkTS';

let oldHandler: errorManager.ErrorHandler;
const errorHandler: errorManager.ErrorHandler = (reason: Error) => {
    // 自定义的errorHandler实现逻辑
    console.info('[Handler]  Uncaught exception handler invoked.');
    if (oldHandler) {
        oldHandler(reason);
    } else {
        // 建议增加判空操作，如果为空采用同步退出方式
        const processManager = new process.ProcessManager();
        processManager.exit(0);
    }
};
oldHandler = errorManager.setDefaultErrorHandler(errorHandler);
```

## ErrorObserver

type ErrorObserver = _ErrorObserver.default

ErrorObserver模块。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_ErrorObserver.default](js-apis-inner-application-errorObserver.md) | ErrorObserver模块。 |

## LoopObserver<sup>12+</sup>

type LoopObserver = _LoopObserver

LoopObserver模块。定义异常监听，可作为 `errormanager.on` 函数的参数，监听并处理当前应用主线程超时的事件。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_LoopObserver](js-apis-inner-application-loopObserver.md) | LoopObserver模块。 |

## UnhandledRejectionObserver<sup>12+</sup>

type UnhandledRejectionObserver = (reason: Error | any, promise: Promise\<any>) => void

定义异常监听，用于捕获Promise异步操作失败的原因。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名    | 类型            | 必填 | 说明 |
|--------|---------------|---| -------- |
| reason | Error \| any  | 是 | 通常是`Error`类型，表示被拒绝的理由。 |
| promise | Promise\<any> | 是 | 被拒绝的promise。 |

## FreezeObserver<sup>18+</sup>

type FreezeObserver = () => void

定义应用主线程freeze回调，用于应用自定义添加freeze信息。

**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

## GlobalObserver<sup>18+</sup>

type GlobalObserver = (reason: GlobalError) => void

定义异常监听，可以作为[errorManager.on('globalErrorOccurred')](#errormanageronglobalerroroccurred18)和[errorManager.on('globalUnhandledRejectionDetected')](#errormanageronglobalunhandledrejectiondetected18)的入参监听当前应用主线程事件处理事件。

**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名  | 类型          | 必填 | 说明 |
|--------| ------------- | ---- | --- |
| reason | [GlobalError](#globalerror18)   | 是   | 有关异常事件名字、消息、错误堆栈信息、异常线程名称和类型的对象。 |


## GlobalError<sup>18+</sup>

有关异常事件名字、消息、错误堆栈信息、异常线程名称和类型的对象。

**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称  | 类型  | 只读  | 可选  | 说明  |
| ---- | ----- | ---- | ----- | ------ |
| instanceName | string | 否 | 否 | 表示虚拟机实例名称。 |
| instanceType | [InstanceType](#instancetype18) | 否 | 否 | 表示虚拟机的实例类型。 |

## InstanceType<sup>18+</sup>

虚拟机的实例类型。

**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称  | 值  | 说明   |
| ---- | --- | ------ |
| MAIN     | 0   | 表示主虚拟机实例。 |
| WORKER   | 1   | 表示工作虚拟机实例。 |
| TASKPOOL | 2   | 表示任务池虚拟机实例。 |
| CUSTOM   | 3   | 表示用户通过[napi_create_ark_runtime](../native-lib/napi.md#napi_create_ark_runtime)从本机代码创建的虚拟机实例。 |


## ErrorHandler<sup>21+</sup>

type ErrorHandler = (errObject: Error) => void

**原子化服务API**：从API version 21开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名  | 类型          | 必填 | 说明 |
|--------| ------------- | ---- | --- |
| errObject | Error   | 是   | 有关异常事件名字、消息、错误堆栈信息的对象。 |



