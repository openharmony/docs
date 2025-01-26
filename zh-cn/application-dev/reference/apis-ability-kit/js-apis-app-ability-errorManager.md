# @ohos.app.ability.errorManager (ErrorManager)

ErrorManager模块提供对错误观察器的注册和注销的能力。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块
```ts
import { errorManager } from '@kit.AbilityKit';
```

## errorManager.on('error')

> **注意：**
> 
> 在主线程注册errormanager.on接口，当前版本不支持捕获子线程（如：taskpool）中的异常。
>
> 使用errormanager.on接口应用不会退出，建议在回调函数执行完后，增加同步退出操作。

on(type: 'error', observer: ErrorObserver): number

注册错误观测器。注册后可以捕获到应用产生的js crash，应用崩溃时进程不会退出。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'error'，表示错误观察器。 |
| observer | [ErrorObserver](js-apis-inner-application-errorObserver.md) | 是 | 错误观察器。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | number | 观察器的index值，和观察器一一对应。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16000003 | The specified ID does not exist. |

**示例：**
    
```ts
import { errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observer: errorManager.ErrorObserver = {
  onUnhandledException(errorMsg) {
    console.log('onUnhandledException, errorMsg: ', errorMsg);
  },
  onException(errorObj) {
    console.log('onException, name: ', errorObj.name);
    console.log('onException, message: ', errorObj.message);
    if (typeof(errorObj.stack) === 'string') {
      console.log('onException, stack: ', errorObj.stack);
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

## errorManager.on('globalErrorOccurred')<sup>16+</sup>

on(type: 'globalErrorOccurred', observer: GlobalObserver): void

在进程中的任一线程注册errormanager.on接口，支持捕获其他子线程（如：taskpool）中的异常,应用崩溃时进程不会退出，建议在回调函数执行完后，增加同步退出操作。

**原子化服务API**：从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'globalErrorOccurred'，表示错误观察器。 |
| observer | [GlobalObserver](js-apis-inner-application-GlobalObserver.md) | 是 | 自定义异常处理回调函数。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | void | 返回值为空。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16000003 | The specified ID does not exist. |

**示例：**
    
```ts
import { errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

function errorFunc(observer: errorManager.GlobalError) {
    console.log("result name :" + observer.name);
    console.log("result message :" + observer.message);
    console.log("result stack :" + observer.stack);
    console.log("result instanceName :" + observer.instanceName);
    console.log("result instaceType :" + observer.instanceType);
}

try {
  errorManager.on('globalErrorOccurred', errorFunc);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message}`);
}
```

## errorManager.off('globalErrorOccurred')<sup>16+</sup>

off(type: 'globalErrorOccurred', observer?: GlobalObserver): void

注销错误观测器，即取消以前注册的callback监听，取消之后无法实现全局监听。

**原子化服务API**：从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'globalErrorOccurred'，表示错误观察器。 |
| observer | [GlobalObserver](js-apis-inner-application-GlobalObserver.md) | 是 | 由on方法注册的callback。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| void | 无返回结果。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16000003 | The specified ID does not exist. |

**示例：**
    
```ts
import { errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

function errorFunc(observer: errorManager.GlobalError) {
    console.log("result name :" + observer.name);
    console.log("result message :" + observer.message);
    console.log("result stack :" + observer.stack);
    console.log("result instanceName :" + observer.instanceName);
    console.log("result instaceType :" + observer.instanceType);
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

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'error'，表示错误观察器。 |
| observerId | number | 是 | 由on方法返回的观察器的index值。 |
| callback | AsyncCallback\<void> | 是 | 表示指定的回调方法。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16000003 | The specified ID does not exist. |

**示例：**
    
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

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'error'，表示错误观察器。 |
| observerId | number | 是 | 由on方法返回的观察器的index值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16000003 | The specified ID does not exist. |

**示例：**
    
```ts
import { errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observerId = 100;

try {
  errorManager.off('error', observerId)
    .then((data) => {
      console.log('----------- unregisterErrorObserver success ----------', data);
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

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
 
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

**示例：**
    
```ts
import { errorManager } from '@kit.AbilityKit';

let observer: errorManager.LoopObserver = {
  onLoopTimeOut(timeout: number) {
    console.log('Duration timeout: ' + timeout);
  }
};

errorManager.on("loopObserver", 1, observer);
```

## errorManager.on('globalUnhandledRejectionDetected')<sup>16+</sup>

on(type: 'globalUnhandledRejectionDetected', observer: GlobalObserver): void

在进程中任一线程注册被拒绝promise监听器，注册后可以捕获到当前进程中未被捕获到的promise rejection。

**原子化服务API**：从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
 
| 参数名                   | 类型                                                          | 必填 | 说明                                       |
|-----------------------|-------------------------------------------------------------| -------- |------------------------------------------|
| type                  | string                                                      | 是 | 填写'globalUnhandledRejectionDetected'，表示注册被拒绝promise监听器。 |
| observer              | [GlobalObserver](js-apis-inner-application-GlobalObserver.md) | 是 | 注册被拒绝promise的callback。                          |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16200001 | If the caller is invalid. |

**示例：**

```ts
import { errorManager } from '@kit.AbilityKit';

function promiseFunc(observer: errorManager.GlobalError) {
  console.log("result name :" + observer.name);
  console.log("result message :" + observer.message);
  console.log("result stack :" + observer.stack);
  console.log("result instanceName :" + observer.instanceName);
  console.log("result instaceType :" + observer.instanceType);
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

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
 
| 参数名                   | 类型                                                          | 必填 | 说明                                       |
|-----------------------|-------------------------------------------------------------| -------- |------------------------------------------|
| type                  | string                                                      | 是 | 填写'unhandledRejection'，表示注册被拒绝promise监听器。 |
| observer              | [UnhandledRejectionObserver](#unhandledrejectionobserver12) | 是 | 注册被拒绝promise监听器。                          |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16200001 | If the caller is invalid. |

**示例：**
    
```ts
import { errorManager } from '@kit.AbilityKit';

let observer: errorManager.UnhandledRejectionObserver = (reason: Error, promise: Promise<void>) => {
  if (promise === promise1) {
    console.log("promise1 is rejected");
  }
  console.log("reason.name: ", reason.name);
  console.log("reason.message: ", reason.message);
  if (reason.stack) {
    console.log("reason.stack: ", reason.stack);
  }
};

errorManager.on("unhandledRejection", observer);

let promise1 = new Promise<void>(() => {}).then(() => {
  throw new Error("uncaught error");
});
```

## errorManager.off('loopObserver')<sup>12+</sup>

off(type: 'loopObserver', observer?: LoopObserver): void

注销主线程消息处理监听器。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'loopObserver'，表示应用主线程观察器。 |
| observer | [LoopObserver](js-apis-inner-application-loopObserver.md) | 否 | 应用主线程观察器标志。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |

**示例：**
    
```ts
import { errorManager } from '@kit.AbilityKit';

errorManager.off("loopObserver");
```

## errorManager.off('globalUnhandledRejectionDetected')<sup>16+</sup>

off(type: 'globalUnhandledRejectionDetected', observer?: GlobalObserver): void

注销被拒绝promise监听器，注销后无法监听进程中的promise异常。

**原子化服务API**：从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名                   | 类型                              | 必填 | 说明                                           |
|-----------------------|---------------------------------|----|----------------------------------------------|
| type                  | string                          | 是  | 填写'globalUnhandledRejectionDetected'，表示注册被拒绝promise监听器。 |
| observer              | [GlobalObserver](js-apis-inner-application-GlobalObserver.md) | 是  | 由on接口注册的被拒绝promise的callback。                        |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16200001 | If the caller is invalid. |
| 16300004 | If the observer does not exist. |

以上错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**
    
```ts
import { errorManager } from '@kit.AbilityKit';

function promiseFunc(observer: errorManager.GlobalError) {
  console.log("result name :" + observer.name);
  console.log("result message :" + observer.message);
  console.log("result stack :" + observer.stack);
  console.log("result instanceName :" + observer.instanceName);
  console.log("result instaceType :" + observer.instanceType);
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

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名                   | 类型                              | 必填 | 说明                                           |
|-----------------------|---------------------------------|----|----------------------------------------------|
| type                  | string                          | 是  | 填写'unhandledRejection'，表示注册被拒绝promise监听器。 |
| observer              | [UnhandledRejectionObserver](#unhandledrejectionobserver12) | 否  | 注册了被拒绝promise监听器。                        |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |
| 16200001 | If the caller is invalid. |
| 16300004 | If the observer does not exist. |

以上错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**
    
```ts
import { errorManager } from '@kit.AbilityKit';

let observer: errorManager.UnhandledRejectionObserver = (reason: Error, promise: Promise<void>) => {
  if (promise === promise1) {
    console.log("promise1 is rejected");
  }
  console.log("reason.name: ", reason.name);
  console.log("reason.message: ", reason.message);
  if (reason.stack) {
    console.log("reason.stack: ", reason.stack);
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
    console.log("promise1 is rejected");
  }
  console.log("reason.name: ", reason.name);
  console.log("reason.message: ", reason.message);
  if (reason.stack) {
    console.log("reason.stack: ", reason.stack);
  }
};

errorManager.on("unhandledRejection", observer);

let promise1 = new Promise<void>(() => {}).then(() => {
  throw new Error("uncaught error")
})

errorManager.off("unhandledRejection", observer);
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

LoopObserver模块。

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

**参数：**

| 参数名    | 类型            | 必填 | 说明 |
|--------|---------------|---| -------- |
| reason | Error \| any  | 是 | 通常是`Error`类型，表示被拒绝的理由。 |
| promise | Promise\<any> | 是 | 被拒绝的promise。 |
