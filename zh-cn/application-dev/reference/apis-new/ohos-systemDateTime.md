# @ohos.systemDateTime    
本模块主要由系统时间和系统时区功能组成。开发者可以设置、获取系统时间及系统时区。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import systemDateTime from '@ohos.systemDateTime'    
```  
    
## getCurrentTime    
获取自Unix纪元以来经过的时间，使用异步回调。  
 **调用形式：**     
    
- getCurrentTime(isNano: boolean, callback: AsyncCallback\<number>): void    
起始版本： 9    
- getCurrentTime(callback: AsyncCallback\<number>): void    
起始版本： 9    
- getCurrentTime(isNano?: boolean): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isNano | boolean | true | 返回结果是否为纳秒数。<br>- true：表示返回结果为纳秒数（ns）。 <br>- false：表示返回结果为毫秒数（ms）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回自Unix纪元以来经过的时间戳。 |  
| Promise<number> | Promise对象，返回自Unix纪元以来经过的时间戳。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemDateTime.getCurrentTime(true, (error: BusinessError, time: number) => {  
    if (error) {  
      console.info(`Failed to get currentTime. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in getting currentTime : ${time}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get currentTime. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemDateTime.getCurrentTime().then((time: number) => {  
    console.info(`Succeeded in getting currentTime : ${time}`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to get currentTime. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get currentTime. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## getTime<sup>(10+)</sup>    
使用同步方式获取自Unix纪元以来经过的时间。  
 **调用形式：**     
- getTime(isNanoseconds?: boolean): number  
  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isNanoseconds | boolean | false | 返回结果是否为纳秒数。<br>- true：表示返回结果为纳秒数（ns）。 <br>- false：表示返回结果为毫秒数（ms）。<br>默认值为false。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 自Unix纪元以来经过的时间。 |  
    
 **示例代码：**   
```ts    
try {  
  let time = systemDateTime.getTime(true)  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get time. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## getRealActiveTime    
获取自系统启动以来经过的时间，不包括深度睡眠时间，使用异步回调。  
 **调用形式：**     
    
- getRealActiveTime(isNano: boolean, callback: AsyncCallback\<number>): void    
起始版本： 9    
- getRealActiveTime(callback: AsyncCallback\<number>): void    
起始版本： 9    
- getRealActiveTime(isNano?: boolean): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isNano | boolean | true | 返回结果是否为纳秒数,默认值为false。<br/>- true：表示返回结果为纳秒数（ns）。 <br/>- false：表示返回结果为毫秒数（ms）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回自系统启动以来经过的时间，但不包括深度睡眠时间。 |  
| Promise<number> | Promise对象，返回自系统启动以来经过的时间，但不包括深度睡眠时间。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemDateTime.getRealActiveTime(true, (error: BusinessError, time: number) => {  
    if (error) {  
      console.info(`Failed to get real active time. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in getting real active time : ${time}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get real active time. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemDateTime.getRealActiveTime().then((time: number) => {  
    console.info(`Succeeded in getting real active time : ${time}`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to get real active time. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get real active time. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## getRealTime    
获取自系统启动以来经过的时间，包括深度睡眠时间，使用异步回调。  
 **调用形式：**     
    
- getRealTime(isNano: boolean, callback: AsyncCallback\<number>): void    
起始版本： 9    
- getRealTime(callback: AsyncCallback\<number>): void    
起始版本： 9    
- getRealTime(isNano?: boolean): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isNano | boolean | true | 返回结果是否为纳秒数。<br/>- true：表示返回结果为纳秒数（ns）。 <br/>- false：表示返回结果为毫秒数（ms）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回自系统启动以来经过的时间，包括深度睡眠时间。 |  
| Promise<number> | Promise对象，返回自系统启动以来经过的时间，包括深度睡眠时间。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemDateTime.getRealTime(true, (error: BusinessError, time: number) => {  
    if (error) {  
      console.info(`Failed to get real time. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in getting real time : ${time}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get real time. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemDateTime.getRealTime().then((time: number) => {  
    console.info(`Succeeded in getting real time : ${time}`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to get real time. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get real time. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## TimeType<sup>(10+)</sup>    
定义获取时间的枚举类型。    
    
 **系统能力:**  SystemCapability.MiscServices.Time    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STARTUP | 0 | 自系统启动以来经过的毫秒数，包括深度睡眠时间。 |  
| ACTIVE | 1 | 自系统启动以来经过的毫秒数，不包括深度睡眠时间。 |  
    
## getUptime<sup>(10+)</sup>    
使用同步方式获取自系统启动以来经过的时间。  
 **调用形式：**     
- getUptime(timeType: TimeType, isNanoseconds?: boolean): number  
  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timeType | TimeType | true | 获取时间的类型。 |  
| isNanoseconds | boolean | false | 返回结果是否为纳秒数。<br/>- true：表示返回结果为纳秒数（ns）。 <br/>- false：表示返回结果为毫秒数（ms）。<br>默认值为false。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 自系统启动以来经过的时间。 |  
    
 **示例代码：**   
```ts    
try {  
  let time = systemDateTime.getUptime(systemDateTime.TimeType.ACTIVE, false);  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get uptime. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## getDate<sup>(deprecated)</sup>    
获取当前系统日期，使用callback异步回调。  
 **调用形式：**     
- getDate(callback: AsyncCallback\<Date>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: new。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Date> | true | 回调函数，返回当前系统日期。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemDateTime.getDate((error: BusinessError, date: Date) => {  
    if (error) {  
      console.info(`Failed to get date. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in getting date : ${date}`);;  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get date. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## getDate<sup>(deprecated)</sup>    
获取当前系统日期，使用Promise异步回调。  
 **调用形式：**     
- getDate(): Promise\<Date>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: new。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Date> | Promise对象，返回当前系统日期。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemDateTime.getDate().then((date: Date) => {  
    console.info(`Succeeded in getting date : ${date}`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to get date. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get date. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## getTimezone    
获取系统时区  
 **调用形式：**     
    
- getTimezone(callback: AsyncCallback\<string>): void    
起始版本： 9    
- getTimezone(): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回系统时区。具体可见[支持的系统时区](#支持的系统时区) 。 |  
| Promise<string> | Promise对象，返回系统时区。具体可见[支持的系统时区](#支持的系统时区) 。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemDateTime.getTimezone((error: BusinessError, data: string) => {  
    if (error) {  
      console.info(`Failed to get timezone. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in get timezone : ${data}`);;  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get timezone. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemDateTime.getTimezone().then((data: string) => {  
    console.info(`Succeeded in getting timezone: ${data}`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to get timezone. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get timezone. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## getTimezoneSync<sup>(10+)</sup>    
获取系统时区，使用同步方式。  
 **调用形式：**     
- getTimezoneSync(): string  
  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回系统时区。具体可见[支持的系统时区](#支持的系统时区) 。 |  
    
 **示例代码：**   
```ts    
try {  
  let timezone = systemDateTime.getTimezoneSync();  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get timezone. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
