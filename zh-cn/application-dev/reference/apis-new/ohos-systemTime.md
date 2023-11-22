# @ohos.systemTime    
本模块主要由系统时间和系统时区功能组成。开发者可以设置、获取系统时间及系统时区。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import systemTime from '@ohos.systemTime'    
```  
    
## setTime<sup>(deprecated)</sup>    
设置系统时间，使用callback异步回调。  
 **调用形式：**     
- setTime(time: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Time  
 **需要权限：** ohos.permission.SET_TIME    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| time<sup>(deprecated)</sup> | number | true | 目标时间戳（ms）。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or permission denied or system error. |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
// time对应的时间为2021-01-20 02:36:25  
let time = 1611081385000;  
try {  
  systemTime.setTime(time, (error: BusinessError) => {  
    if (error) {  
      console.info(`Failed to setting time. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in setting time`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to set time. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## setTime<sup>(deprecated)</sup>    
设置系统时间，使用Promise异步回调。  
 **调用形式：**     
- setTime(time: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Time  
 **需要权限：** ohos.permission.SET_TIME    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| time<sup>(deprecated)</sup> | number | true | 目标时间戳（ms）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or permission denied or system error. |  
    
 **示例代码：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
// time对应的时间为2021-01-20 02:36:25  
let time = 1611081385000;  
try {  
  systemTime.setTime(time).then(() => {  
    console.info(`Succeeded in setting time.`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to setting time. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to set time. message: ${error.message}, code: ${error.code}`);  
}    
```    
  
    
## getCurrentTime<sup>(deprecated)</sup>    
获取自Unix纪元以来经过的时间，使用callback异步回调。  
 **调用形式：**     
- getCurrentTime(isNano: boolean, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.systemDateTime/systemDateTime.getCurrentTime。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isNano<sup>(deprecated)</sup> | boolean | true | 返回结果是否为纳秒数。<br>- true：表示返回结果为纳秒数（ns）。 <br>- false：表示返回结果为毫秒数（ms）。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数，返回自Unix纪元以来经过的时间。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or system error. |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemTime.getCurrentTime(true, (error: BusinessError, time: number) => {  
    if (error) {  
      console.info(`Failed to getting currentTime. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in getting currentTime: ${time}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get currentTime. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## getCurrentTime<sup>(deprecated)</sup>    
获取自Unix纪元以来经过的时间，使用callback异步回调。  
 **调用形式：**     
- getCurrentTime(callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.systemDateTime/systemDateTime.getCurrentTime。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数，返回自Unix纪元以来经过的时间。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or system error. |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemTime.getCurrentTime((error: BusinessError, time: number) => {  
    if (error) {  
      console.info(`Failed to getting currentTime. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in getting currentTime : ${time}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get currentTime. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## getCurrentTime<sup>(deprecated)</sup>    
获取自Unix纪元以来经过的时间，使用Promise异步回调。  
 **调用形式：**     
- getCurrentTime(isNano?: boolean): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.systemDateTime/systemDateTime.getCurrentTime。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isNano<sup>(deprecated)</sup> | boolean | false | 返回结果是否为纳秒数，默认值为false。<br/>默认值为false。<br/>- true：表示返回结果为纳秒数（ns）。 <br/>- false：表示返回结果为毫秒数（ms）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象，返回自Unix纪元以来经过的时间。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or system error. |  
    
 **示例代码：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemTime.getCurrentTime().then((time: number) => {  
    console.info(`Succeeded in getting currentTime : ${time}`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to getting currentTime. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get currentTime. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## getRealActiveTime<sup>(deprecated)</sup>    
获取自系统启动以来经过的时间，不包括深度睡眠时间，使用callback异步回调。  
 **调用形式：**     
- getRealActiveTime(isNano: boolean, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.systemDateTime/systemDateTime.getRealActiveTime。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isNano<sup>(deprecated)</sup> | boolean | true | 返回结果是否为纳秒数。<br/>- true：表示返回结果为纳秒数（ns）。 <br/>- false：表示返回结果为毫秒数（ms）。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数，返回自系统启动以来经过的时间，但不包括度睡眠时间。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or system error. |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemTime.getRealActiveTime(true, (error: BusinessError, time: number) => {  
    if (error) {  
      console.info(`Failed to getting real active time. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in getting real active time : ${time}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get real active time. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## getRealActiveTime<sup>(deprecated)</sup>    
获取自系统启动以来经过的时间，不包括深度睡眠时间，使用callback异步回调。  
 **调用形式：**     
- getRealActiveTime(callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.systemDateTime/systemDateTime.getRealActiveTime。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数，返回自系统启动以来经过的时间，但不包括度睡眠时间。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or system error. |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemTime.getRealActiveTime((error: BusinessError, time: number) => {  
    if (error) {  
      console.info(`Failed to getting real active time. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in getting real active time : ${time}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get real active time. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## getRealActiveTime<sup>(deprecated)</sup>    
获取自系统启动以来经过的时间，不包括深度睡眠时间，使用Promise异步回调。  
 **调用形式：**     
- getRealActiveTime(isNano?: boolean): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.systemDateTime/systemDateTime.getRealActiveTime。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isNano<sup>(deprecated)</sup> | boolean | false | 返回结果是否为纳秒数，默认值为false。<br/>默认值为false。<br/>- true：表示返回结果为纳秒数（ns）。 <br/>- false：表示返回结果为毫秒数（ms）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象，返回自系统启动以来经过的时间，但不包括深度睡眠时间。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or system error. |  
    
 **示例代码：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemTime.getRealActiveTime().then((time: number) => {  
    console.info(`Succeeded in getting real active time : ${time}`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to getting real active time. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get real active time. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## getRealTime<sup>(deprecated)</sup>    
获取自系统启动以来经过的时间，包括深度睡眠时间，使用callback异步回调。  
 **调用形式：**     
- getRealTime(isNano: boolean, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.systemDateTime/systemDateTime.getRealTime。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isNano<sup>(deprecated)</sup> | boolean | true | 返回结果是否为纳秒数。<br/>- true：表示返回结果为纳秒数（ns）。 <br/>- false：表示返回结果为毫秒数（ms）。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数，返回自系统启动以来经过的时间，包括深度睡眠时间。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or system error. |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemTime.getRealTime(true, (error: BusinessError, time: number) => {  
    if (error) {  
      console.info(`Failed to getting real time. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in getting real time : ${time}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get real time. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## getRealTime<sup>(deprecated)</sup>    
获取自系统启动以来经过的时间，包括深度睡眠时间，使用callback异步回调。  
 **调用形式：**     
- getRealTime(callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.systemDateTime/systemDateTime.getRealTime。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数，返回自系统启动以来经过的时间，包括深度睡眠时间。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or system error. |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemTime.getRealTime((error: BusinessError, time: number) => {  
    if (error) {  
      console.info(`Failed to getting real time. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in getting real time : ${time}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get real time. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## getRealTime<sup>(deprecated)</sup>    
获取自系统启动以来经过的时间，包括深度睡眠时间，使用Promise异步回调。  
 **调用形式：**     
- getRealTime(isNano?: boolean): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.systemDateTime/systemDateTime.getRealTime。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isNano<sup>(deprecated)</sup> | boolean | false | 返回结果是否为纳秒数，默认值为false。<br/>默认值为false。<br/>- true：表示返回结果为纳秒数（ns）。 <br/>- false：表示返回结果为毫秒数（ms）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象，返回自系统启动以来经过的时间，包括深度睡眠时间。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or system error. |  
    
 **示例代码：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemTime.getRealTime().then((time: number) => {  
    console.info(`Succeeded in getting real time : ${time}`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to getting real time. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get real time. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## setDate<sup>(deprecated)</sup>    
设置系统日期，使用callback异步回调。  
 **调用形式：**     
- setDate(date: Date, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Time  
 **需要权限：** ohos.permission.SET_TIME    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| date<sup>(deprecated)</sup> | Date | true | 目标日期。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or permission denied or system error. |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let date = new Date();  
try {  
  systemTime.setDate(date, (error: BusinessError) => {  
    if (error) {  
      console.info(`Failed to setting date. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in setting date.`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to set date. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## setDate<sup>(deprecated)</sup>    
设置系统日期，使用Promise异步回调。  
 **调用形式：**     
- setDate(date: Date): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Time  
 **需要权限：** ohos.permission.SET_TIME    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| date<sup>(deprecated)</sup> | Date | true | 目标日期。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or permission denied or system error. |  
    
 **示例代码：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let date = new Date();   
try {  
  systemTime.setDate(date).then(() => {  
    console.info(`Succeeded in setting date.`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to setting date. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to set date. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## getDate<sup>(deprecated)</sup>    
获取当前系统日期，使用callback异步回调。  
 **调用形式：**     
- getDate(callback: AsyncCallback\<Date>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.systemDateTime/systemDateTime.getDate。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Date> | true | 回调函数，返回当前系统日期。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or system error. |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemTime.getDate((error: BusinessError, date: Date) => {  
    if (error) {  
      console.info(`Failed to get date. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in get date : ${date}`);;  
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
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.systemDateTime/systemDateTime.getDate。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Date> | Promise对象，返回当前系统日期。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or system error. |  
    
 **示例代码：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemTime.getDate().then((date: Date) => {  
    console.info(`Succeeded in getting date : ${date}`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to getting date. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get date. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## setTimezone<sup>(deprecated)</sup>    
设置系统时区，使用callback异步回调。  
 **调用形式：**     
- setTimezone(timezone: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Time  
 **需要权限：** ohos.permission.SET_TIME_ZONE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timezone<sup>(deprecated)</sup> | string | true | 系统时区。 具体可见[支持的系统时区](#支持的系统时区) 。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or permission denied or system error. |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemTime.setTimezone('Asia/Shanghai', (error: BusinessError) => {  
    if (error) {  
      console.info(`Failed to setting timezone. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in setting timezone.`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to set timezone. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## setTimezone<sup>(deprecated)</sup>    
设置系统时区，使用Promise异步回调。  
 **调用形式：**     
- setTimezone(timezone: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.MiscServices.Time  
 **需要权限：** ohos.permission.SET_TIME_ZONE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timezone<sup>(deprecated)</sup> | string | true | 系统时区。具体可见[支持的系统时区](#支持的系统时区) 。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or permission denied or system error. |  
    
 **示例代码：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemTime.setTimezone('Asia/Shanghai').then(() => {  
    console.info(`Succeeded in setting timezone.`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to setting timezone. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to set timezone. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## getTimezone<sup>(deprecated)</sup>    
获取系统时区，使用callback异步回调。  
 **调用形式：**     
- getTimezone(callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.systemDateTime/systemDateTime.getTimezone。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 回调函数，返回系统时区。具体可见[支持的系统时区](#支持的系统时区) 。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or system error. |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemTime.getTimezone((error: BusinessError, data: string) => {  
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
  
    
## getTimezone<sup>(deprecated)</sup>    
获取系统时区，使用Promise异步回调。  
 **调用形式：**     
- getTimezone(): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.systemDateTime/systemDateTime.getTimezone。  
 **系统能力:**  SystemCapability.MiscServices.Time    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise对象，返回系统时区。具体可见[支持的系统时区](#支持的系统时区) 。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| -1 | The parameter check failed or system error. |  
    
 **示例代码：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemTime.getTimezone().then((data: string) => {  
    console.info(`Succeeded in getting timezone: ${data}`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to getting timezone. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to get timezone. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
