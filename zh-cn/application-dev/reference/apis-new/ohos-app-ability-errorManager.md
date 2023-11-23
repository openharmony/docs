# @ohos.app.ability.errorManager    
ErrorManager模块提供对错误观察器的注册和注销的能力。使用场景：应用想要捕获js crash。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import errorManager from '@ohos.app.ability.errorManager'    
```  
    
## on('error')    
注册错误观测器。  
 **调用形式：**     
- on(type: 'error', observer: ErrorObserver): number  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 填写'error'，表示错误观察器。 |  
| observer | ErrorObserver | true | 错误观察器。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 观察器的index值，和观察器一一对应。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000003 | Id does not exist. |  
    
 **示例代码：**   
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
  
    
## off('error')    
注销错误观测器。  
 **调用形式：**     
    
- off(type: 'error', observerId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- off(type: 'error', observerId: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 填写'error'，表示错误观察器。 |  
| observerId | number | true | 由on方法返回的观察器的index值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示指定的回调方法。 |  
| Promise<void> | 返回执行结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000003 | Id does not exist. |  
    
 **示例代码：**   
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
  
