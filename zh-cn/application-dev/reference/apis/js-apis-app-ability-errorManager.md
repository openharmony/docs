# @ohos.app.ability.errorManager (ErrorManager)

ErrorManager模块提供对错误观察器的注册和注销的能力。使用场景：应用想要捕获js crash。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块
```ts
import errorManager from '@ohos.app.ability.errorManager';
```

## ErrorManager.on

on(type: 'error', observer: ErrorObserver): number;

注册错误观测器。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'error'，表示错误观察器。 |
| observer | [ErrorObserver](./js-apis-inner-application-errorObserver.md) | 是 | 错误观察器。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | number | 观察器的index值，和观察器一一对应。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000003 | Id does not exist. |

以上错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)。

**示例：**
    
```ts
import errorManager from '@ohos.app.ability.errorManager';
import { BusinessError } from '@ohos.base';

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

## ErrorManager.off

off(type: 'error', observerId: number,  callback: AsyncCallback\<void>): void;

注销错误观测器。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'error'，表示错误观察器。 |
| observerId | number | 是 | 由on方法返回的观察器的index值。 |
| callback | AsyncCallback\<void> | 是 | 表示指定的回调方法。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000003 | Id does not exist. |

以上错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)。

**示例：**
    
```ts
import errorManager from '@ohos.app.ability.errorManager';
import { BusinessError } from '@ohos.base';

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

## ErrorManager.off

off(type: 'error', observerId: number): Promise\<void>;

注销错误观测器。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写'error'，表示错误观察器。 |
| observerId | number | 是 | 由on方法返回的观察器的index值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 返回执行结果。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000003 | Id does not exist. |

以上错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)。

**示例：**
    
```ts
import errorManager from '@ohos.app.ability.errorManager';
import { BusinessError } from '@ohos.base';

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
