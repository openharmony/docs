# ErrorObserver

定义异常监听，可以作为[errorManager.on](js-apis-app-ability-errorManager.md#errormanageron)的入参监听当前应用发生的异常。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 

## 导入模块

```ts
import errorManager from '@ohos.app.ability.errorManager';
```

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
    console.error('registerErrorObserver failed, error.code: ${error.code}, error.message: ${error.message}');
}
```
```