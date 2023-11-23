# ErrorObserver    
定义异常监听，可以作为[ErrorManager.on](js-apis-app-ability-errorManager.md#errormanageron)的入参监听当前应用发生的异常。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ErrorObserver  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### onUnhandledException    
将在js运行时引发用户未捕获的异常时调用。  
 **调用形式：**     
- onUnhandledException(errMsg: string): void  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| errMsg | string | true | 有关异常的消息和错误堆栈跟踪。 |  
    
 **示例代码：**   
```ts    
import errorManager from '@ohos.app.ability.errorManager';  
  
let observer: errorManager.ErrorObserver = {  
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
  
    
### onException<sup>(10+)</sup>    
将在应用运行异常时调用。  
 **调用形式：**     
- onException?(errObject: Error): void  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| errObject | Error | true | 有关异常事件名字、消息和错误堆栈信息的对象。 |  
    
 **示例代码：**   
```ts    
import errorManager from '@ohos.app.ability.errorManager';  
  
let observer: errorManager.ErrorObserver = {  
onUnhandledException(errorMsg) {  
console.error('onUnhandledException, errorMsg: ', errorMsg);  
},  
onException(errorObj) {  
console.log('onException, name: ', errorObj.name);  
console.log('onException, message: ', errorObj.message);  
if (typeof(errorObj.stack) === 'string') {  
console.log('onException, stack: ', errorObj.stack);  
}  
}  
};  
  
try {  
errorManager.on('error', observer);  
} catch (error) {  
console.error('registerErrorObserver failed, error.code: ${error.code}, error.message: ${error.message}');  
}  
    
```    
  
