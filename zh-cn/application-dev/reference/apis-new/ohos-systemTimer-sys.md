# @ohos.systemTimer    
本模块主要由系统定时器功能组成。开发者可以使用定时功能实现定时服务，如闹钟等。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import systemTimer from '@ohos.systemTimer'    
```  
    
 **常量：**     
 **系统能力:**  SystemCapability.MiscServices.Time    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| TIMER_TYPE_REALTIME | number |  | 系统启动时间定时器。（定时器启动时间不能晚于当前设置的系统时间） |  
| TIMER_TYPE_WAKEUP | number |  | 唤醒定时器。  |  
| TIMER_TYPE_EXACT | number |  | 精准定时器。 |  
| TIMER_TYPE_IDLE | number |  | IDLE模式定时器（暂不支持）。 |  
    
## createTimer    
创建定时器  
 **调用形式：**     
    
- createTimer(options: TimerOptions, callback: AsyncCallback\<number>): void    
起始版本： 7    
- createTimer(options: TimerOptions): Promise\<number>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | TimerOptions | true | 创建系统定时器的初始化选项，包括定时器类型、是否循环触发、间隔时间、WantAgent通知机制等。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回定时器的ID。 |  
| Promise<number> | Promise对象，返回定时器的ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）:  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let options: systemTimer.TimerOptions = {  
  type: systemTimer.TIMER_TYPE_REALTIME,  
  repeat: false  
};  
try {  
  systemTimer.createTimer(options, (error: BusinessError, timerId: Number) => {  
    if (error) {  
      console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in creating timer. timerId: ${timerId}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let options: systemTimer.TimerOptions = {  
  type: systemTimer.TIMER_TYPE_REALTIME,  
  repeat:false  
};  
try {  
  systemTimer.createTimer(options).then((timerId: Number) => {  
    console.info(`Succeeded in creating timer. timerId: ${timerId}`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## startTimer    
开启定时器  
 **调用形式：**     
    
- startTimer(timer: number, triggerTime: number, callback: AsyncCallback\<void>): void    
起始版本： 7    
- startTimer(timer: number, triggerTime: number): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timer | number | true | 定时器的ID。 |  
| triggerTime | number | true | 定时器的触发时间，单位：毫秒。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let options: systemTimer.TimerOptions = {  
  type: systemTimer.TIMER_TYPE_REALTIME,  
  repeat:false  
}  
let triggerTime = new Date().getTime();  
triggerTime += 3000;  
  
try {  
  systemTimer.createTimer(options).then((timerId: number) => {  
    systemTimer.startTimer(timerId, triggerTime, (error: BusinessError) => {  
      if (error) {  
        console.info(`Failed to start timer. message: ${error.message}, code: ${error.code}`);  
        return;  
      }  
      console.info(`Succeeded in starting timer.`);  
    });  
    console.info(`Succeeded in creating timer. timerId: ${timerId}`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let options: systemTimer.TimerOptions = {  
  type: systemTimer.TIMER_TYPE_REALTIME,  
  repeat:false  
}  
let triggerTime = new Date().getTime();  
triggerTime += 3000;  
  
try {  
  systemTimer.createTimer(options).then((timerId: number) => {  
    systemTimer.startTimer(timerId, triggerTime).then(() => {  
      console.info(`Succeeded in starting timer.`);  
    }).catch((error: BusinessError) => {  
      console.info(`Failed to start timer. message: ${error.message}, code: ${error.code}`);  
    });  
    console.info(`Succeeded in creating timer. timerId: ${timerId}`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## stopTimer    
停止定时器  
 **调用形式：**     
    
- stopTimer(timer: number, callback: AsyncCallback\<void>): void    
起始版本： 7    
- stopTimer(timer: number): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timer | number | true | 定时器的ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let options: systemTimer.TimerOptions = {  
  type: systemTimer.TIMER_TYPE_REALTIME,  
  repeat:false  
}  
let triggerTime = new Date().getTime();  
triggerTime += 3000;  
  
try {  
  systemTimer.createTimer(options).then((timerId: number) => {  
    systemTimer.startTimer(timerId, triggerTime);  
    systemTimer.stopTimer(timerId, (error: BusinessError) => {  
      if (error) {  
        console.info(`Failed to stop timer. message: ${error.message}, code: ${error.code}`);  
        return;  
      }  
    console.info(`Succeeded in stopping timer.`);  
    });  
    console.info(`Succeeded in creating timer. timerId: ${timerId}`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let options: systemTimer.TimerOptions = {  
  type: systemTimer.TIMER_TYPE_REALTIME,  
  repeat:false  
}  
let triggerTime = new Date().getTime();  
triggerTime += 3000;  
  
try {  
  systemTimer.createTimer(options).then((timerId: number) => {  
    systemTimer.startTimer(timerId, triggerTime);  
    systemTimer.stopTimer(timerId).then(() => {  
      console.info(`Succeeded in stopping timer.`);  
    }).catch((error: BusinessError) => {  
      console.info(`Failed to stop timer. message: ${error.message}, code: ${error.code}`);  
    });  
    console.info(`Succeeded in creating timer. timerId: ${timerId}`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## destroyTimer    
销毁定时器  
 **调用形式：**     
    
- destroyTimer(timer: number, callback: AsyncCallback\<void>): void    
起始版本： 7    
- destroyTimer(timer: number): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timer | number | true | 定时器的ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let options: systemTimer.TimerOptions = {  
  type: systemTimer.TIMER_TYPE_REALTIME,  
  repeat:false  
}  
let triggerTime = new Date().getTime();  
triggerTime += 3000;  
  
try {  
  systemTimer.createTimer(options).then((timerId: number) => {  
    systemTimer.startTimer(timerId, triggerTime);  
    systemTimer.stopTimer(timerId);  
    systemTimer.destroyTimer(timerId, (error: BusinessError) => {  
      if (error) {  
        console.info(`Failed to destroy timer. message: ${error.message}, code: ${error.code}`);  
        return;  
      }  
    console.info(`Succeeded in destroying timer.`);  
    });  
    console.info(`Succeeded in creating timer. timerId: ${timerId}`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let options: systemTimer.TimerOptions = {  
  type: systemTimer.TIMER_TYPE_REALTIME,  
  repeat:false  
}  
let triggerTime = new Date().getTime();  
triggerTime += 3000;  
  
try {  
  systemTimer.createTimer(options).then((timerId: number) => {  
    systemTimer.startTimer(timerId, triggerTime);  
    systemTimer.stopTimer(timerId);  
    systemTimer.destroyTimer(timerId).then(() => {  
      console.info(`Succeeded in destroying timer.`);  
    }).catch((error: BusinessError) => {  
      console.info(`Failed to destroy timer. message: ${error.message}, code: ${error.code}`);  
    });  
    console.info(`Succeeded in creating timer. timerId: ${timerId}`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to create timer. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## TimerOptions    
创建系统定时器的初始化选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Time    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.Time    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | number | false | true | 定时器类型。<br>取值为1，表示为系统启动时间定时器（定时器启动时间不能晚于当前设置的系统时间） ；<br>取值为2，表示为唤醒定时器；<br>取值为4，表示为精准定时器；<br>取值为8，表示为IDLE模式定时器（暂不支持）。 |  
| repeat | boolean | false | true | 是否为循环定时器。<br>true为循环定时器，false为单次定时器。 |  
| interval | number | false | false | 定时器时间间隔。<br>如果是循环定时器，interval值应大于5000毫秒；单次定时器interval值为0。 |  
| wantAgent | WantAgent | false | false | 设置通知的WantAgent，定时器到期后通知。（支持拉起应用MainAbility，暂不支持拉起ServiceAbility。） |  
| callback | () => void | false | false | 以回调函数的形式返回定时器的ID。 |  
