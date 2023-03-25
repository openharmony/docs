# ErrorObserver

定义异常监听，可以作为[ErrorManager.on](js-apis-app-ability-errorManager.md#errormanageron)的入参监听当前应用发生的异常。

## ErrorObserver.onUnhandledException

onUnhandledException(errMsg: string): void;

将在js运行时引发用户未捕获的异常时调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| errMsg | string | 否 | 有关异常的消息和错误堆栈跟踪。 |

**示例：**

```ts
import errorManager from '@ohos.app.ability.errorManager';

let observer = {
  onUnhandledException(errorMsg) {
    console.error('onUnhandledException, errorMsg: ', errorMsg);
  }
};

try {
    errorManager.on('error', observer);
} catch (error) {
    console.error('registerErrorObserver failed, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}');
}
```

## ErrorObserver.onException

onException?(errObject: Error): void;

当Native层发生异常事件并且需要通知js层时调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| errObject | Error | 否 | 有关于异常事件名字、消息和错误堆栈信息的对象。 |

**示例：**

```ts
import errorManager from '@ohos.app.ability.errorManager';

let observer = {
  onUnhandledException(errorMsg) {
    console.error('onUnhandledException, errorMsg: ', errorMsg);
  }
  onException(errObject) {
    console.log('onException, name: ', errorObj.name);
    console.log('onException, message: ', errorObj.message);
    if (typeof(errorObject.stack) === 'string') {
        console.log('onException, stack: ', errorObj.stack);
    }
  }
};

try {
    errorManager.on('error', observer);
} catch (error) {
    console.error('registerErrorObserver failed, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}');
}
```
