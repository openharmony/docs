# @ohos.systemDateTime    
本模块主要由系统时间和系统时区功能组成。开发者可以设置、获取系统时间及系统时区。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import systemDateTime from '@ohos.systemDateTime'    
```  
    
## setTime    
设置系统时间，使用异步回调。  
 **调用形式：**     
    
- setTime(time: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setTime(time: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Time  
 **需要权限：** ohos.permission.SET_TIME    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| time | number | true | 目标时间戳（ms）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
// time对应的时间为2021-01-20 02:36:25  
let time = 1611081385000;  
try {  
  systemDateTime.setTime(time, (error: BusinessError) => {  
    if (error) {  
      console.info(`Failed to set time. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in setting time`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to set time. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
// time对应的时间为2021-01-20 02:36:25  
let time = 1611081385000;  
try {  
  systemDateTime.setTime(time).then(() => {  
    console.info(`Succeeded in setting time.`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to set time. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to set time. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## setDate<sup>(deprecated)</sup>    
设置系统日期，使用callback异步回调。  
 **调用形式：**     
- setDate(date: Date, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: systemDateTime.setTime。  
 **系统API:**  此接口为系统接口。  
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
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
示例（callback）:  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let date = new Date();  
try {  
  systemDateTime.setDate(date, (error: BusinessError) => {  
    if (error) {  
      console.info(`Failed to set date. message: ${error.message}, code: ${error.code}`);  
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
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: systemDateTime.setTime。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Time  
 **需要权限：** ohos.permission.SET_TIME    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| date<sup>(deprecated)</sup> | Date | true | 目标日期。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let date = new Date();   
try {  
  systemDateTime.setDate(date).then(() => {  
    console.info(`Succeeded in setting date.`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to set date. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to set date. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
## setTimezone    
设置系统时区，使用异步回调。  
 **调用形式：**     
    
- setTimezone(timezone: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setTimezone(timezone: string): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.Time  
 **需要权限：** ohos.permission.SET_TIME_ZONE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timezone | string | true | 系统时区。 具体可见[支持的系统时区](#支持的系统时区) 。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemDateTime.setTimezone('Asia/Shanghai', (error: BusinessError) => {  
    if (error) {  
      console.info(`Failed to set timezone. message: ${error.message}, code: ${error.code}`);  
      return;  
    }  
    console.info(`Succeeded in setting timezone.`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to set timezone. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  systemDateTime.setTimezone('Asia/Shanghai').then(() => {  
    console.info(`Succeeded in setting timezone.`);  
  }).catch((error: BusinessError) => {  
    console.info(`Failed to set timezone. message: ${error.message}, code: ${error.code}`);  
  });  
} catch(e) {  
  let error = e as BusinessError;  
  console.info(`Failed to set timezone. message: ${error.message}, code: ${error.code}`);  
}  
    
```    
  
