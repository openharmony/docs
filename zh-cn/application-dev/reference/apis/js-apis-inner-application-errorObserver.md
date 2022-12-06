# ErrorObserver

定义异常监听。

## onUnhandledException

onUnhandledException(errMsg: string): void;

将在js运行时引发用户未捕获的异常时调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| errMsg | string | 否 | 有关异常的消息和错误堆栈跟踪。 |

**示例：**
    
```ts
import errorManager from '@ohos.application.errorManager';

let observer = {
    onUnhandledException(errorMsg) {
        console.log('onUnhandledException, errorMsg: ' + JSON.stringify(errorMsg));
    }
}
errorManager.registerErrorObserver(observer)
```