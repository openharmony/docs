# @ohos.app.ability.errorManager (ErrorManager)

ErrorManager模块提供对错误观察器的注册和注销的能力。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块
```
import errorManager from '@ohos.app.ability.errorManager'
```

## ErrorManager.on

on(type: "error", observer: ErrorObserver): number;

注册错误观测器。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 调用接口类型 |
| observer | [ErrorObserver](./js-apis-inner-application-errorObserver.md) | 是 | 返回观察者的数字代码。 |

**示例：**
    
```js
var observer = {
    onUnhandledException(errorMsg) {
        console.log('onUnhandledException, errorMsg: ', errorMsg)
    }
}
try {
    errorManager.on("error", observer);
} catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
}
```

## ErrorManager.off

off(type: "error", observerId: number,  callback: AsyncCallback\<void>): void;

注销错误观测器。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 调用接口类型 |
| observerId | number | 是 | 返回观察者的数字代码。 |
| callback | AsyncCallback\<void> | 是 | 表示指定的回调方法。 |

**示例：**
    
```js
var observerId = 100;

function unregisterErrorObserverCallback(err) {
    if (err) {
        console.log('------------ unregisterErrorObserverCallback ------------', err);
    }
}
try {
    errorManager.off("error", observerId, unregisterErrorObserverCallback);
} catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
}
```

## ErrorManager.off

off(type: "error", observerId: number): Promise\<void>;

注销错误观测器。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
 
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 调用接口类型 |
| observerId | number | 是 | 返回观察者的数字代码。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 返回执行结果。 |

**示例：**
    
```js
var observerId = 100;
try {
    errorManager.off("error", observerId)
        .then((data) => {
            console.log('----------- unregisterErrorObserver success ----------', data);
        })
        .catch((err) => {
            console.log('----------- unregisterErrorObserver fail ----------', err);
    })
} catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
}

```
