# @ohos.telephony.sim    
SIM卡管理模块提供了SIM卡管理的基础能力，包括获取指定卡槽SIM卡的名称、号码、ISO国家码、归属PLMN号、服务提供商名称、SIM卡状态、卡类型、是否插卡、是否激活、锁状态，设置指定卡槽SIM卡显示的名称、号码、锁状态，激活、禁用指定卡槽SIM卡，更改Pin密码，以及解锁指定卡槽SIM卡密码、SIM卡密码的解锁密码等。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import sim from '@ohos.telephony.sim'    
```  
    
## getSimIccId<sup>(7+)</sup>    
获取指定卡槽SIM卡的ICCID。  
 **调用形式：**     
    
- getSimIccId(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 7    
- getSimIccId(slotId: number): Promise\<string>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<string> | 以Promise形式返回获取指定卡槽SIM卡的ICCID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getSimIccId(0, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getSimIccId(0).then((data:string) => {  
    console.log(`getSimIccId success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getSimIccId failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getVoiceMailIdentifier<sup>(8+)</sup>    
获取指定卡槽中SIM卡语音信箱的alpha标识符。  
 **调用形式：**     
    
- getVoiceMailIdentifier(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 8    
- getVoiceMailIdentifier(slotId: number): Promise\<string>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<string> | 以Promise形式返回获取指定卡槽SIM卡的alpha标识符。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getVoiceMailIdentifier(0, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getVoiceMailIdentifier(0).then((data: string) => {  
    console.log(`getVoiceMailIdentifier success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getVoiceMailIdentifier failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getVoiceMailNumber<sup>(8+)</sup>    
获取指定卡槽中SIM卡的语音信箱号。  
 **调用形式：**     
    
- getVoiceMailNumber(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 8    
- getVoiceMailNumber(slotId: number): Promise\<string>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<string> | 以Promise形式返回获取指定卡槽SIM卡的语音信箱号。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getVoiceMailNumber(0, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getVoiceMailNumber(0).then((data: string) => {  
    console.log(`getVoiceMailNumber success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getVoiceMailNumber failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setVoiceMailInfo<sup>(8+)</sup>    
设置语音邮件信息。  
 **调用形式：**     
    
- setVoiceMailInfo(slotId: number, mailName: string, mailNumber: string, callback: AsyncCallback\<void>): void    
起始版本： 8    
- setVoiceMailInfo(slotId: number, mailName: string, mailNumber: string): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| mailName | string | true | 邮件名字 |  
| mailNumber | string | true | 邮件号码 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
| 8301002 | SIM card operation error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.setVoiceMailInfo(0, "mail", "xxx@xxx.com", (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.setVoiceMailInfo(0, "mail", "xxx@xxx.com").then(() => {  
    console.log(`setVoiceMailInfo success.`);  
}).catch((err: BusinessError) => {  
    console.log(`setVoiceMailInfo failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getSimTelephoneNumber<sup>(8+)</sup>    
获取指定卡槽中SIM卡的MSISDN。  
 **调用形式：**     
    
- getSimTelephoneNumber(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 8    
- getSimTelephoneNumber(slotId: number): Promise\<string>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_PHONE_NUMBERS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<string> | 以Promise形式返回获取指定卡槽SIM卡的MSISDN。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getSimTelephoneNumber(0, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getSimTelephoneNumber(0).then((data: string) => {  
    console.log(`getSimTelephoneNumber success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getSimTelephoneNumber failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getSimGid1<sup>(7+)</sup>    
获取指定卡槽中SIM卡的组标识符级别1（GID1）。  
 **调用形式：**     
    
- getSimGid1(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 7    
- getSimGid1(slotId: number): Promise\<string>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<string> | 以Promise形式返回获取指定卡槽SIM卡的标识符级别1。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getSimGid1(0, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getSimGid1(0).then((data: string) => {  
    console.log(`getSimGid1 success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getSimGid1 failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getIMSI    
获取国际移动用户识别码。  
 **调用形式：**     
    
- getIMSI(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 6    
- getIMSI(slotId: number): Promise\<string>    
起始版本： 6  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<string> | 以Promise形式返回获取的国际移动用户识别码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getIMSI(0, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getIMSI(0).then((data: string) => {  
    console.log(`getIMSI success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getIMSI failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setDefaultVoiceSlotId<sup>(7+)</sup>    
设置默认语音业务的卡槽ID。  
 **调用形式：**     
    
- setDefaultVoiceSlotId(slotId: number, callback: AsyncCallback\<void>): void    
起始版本： 7    
- setDefaultVoiceSlotId(slotId: number): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2<br/>- -1：清除默认配置 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回设置结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
| 8301001 | SIM card is not activated. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.setDefaultVoiceSlotId(0, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.setDefaultVoiceSlotId(0).then(() => {  
    console.log(`setDefaultVoiceSlotId success.`);  
}).catch((err: BusinessError) => {  
    console.log(`setDefaultVoiceSlotId failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## activateSim<sup>(8+)</sup>    
激活指定卡槽SIM卡。  
 **调用形式：**     
    
- activateSim(slotId: number, callback: AsyncCallback\<void>): void    
起始版本： 8    
- activateSim(slotId: number): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回设置结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.activateSim(0, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.activateSim(0).then(() => {  
    console.log(`activateSim success.`);  
}).catch((err: BusinessError) => {  
    console.log(`activateSim failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## deactivateSim<sup>(8+)</sup>    
禁用指定卡槽SIM卡。  
 **调用形式：**     
    
- deactivateSim(slotId: number, callback: AsyncCallback\<void>): void    
起始版本： 8    
- deactivateSim(slotId: number): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回设置结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.deactivateSim(0, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.deactivateSim(0).then(() => {  
    console.log(`deactivateSim success.`);  
}).catch((err: BusinessError) => {  
    console.log(`deactivateSim failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setShowName<sup>(8+)</sup>    
设置指定卡槽SIM卡显示的名称。  
 **调用形式：**     
    
- setShowName(slotId: number, name: string, callback: AsyncCallback\<void>): void    
起始版本： 8    
- setShowName(slotId: number, name: string): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| name | string | true | SIM卡名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回设置结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let name: string = "ShowName";  
sim.setShowName(0, name, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let name: string = "ShowName";  
sim.setShowName(0, name).then(() => {  
    console.log(`setShowName success.`);  
}).catch((err: BusinessError) => {  
    console.log(`setShowName failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getShowName<sup>(8+)</sup>    
获取指定卡槽SIM卡的名称。  
 **调用形式：**     
    
- getShowName(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 8    
- getShowName(slotId: number): Promise\<string>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回指定卡槽SIM卡的名称。 |  
| Promise<string> | 以Promise形式返回指定卡槽SIM卡的名称。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getShowName(0, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getShowName(0).then((data: string) => {  
    console.log(`getShowName success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getShowName failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setShowNumber<sup>(8+)</sup>    
设置指定卡槽SIM卡的号码。  
 **调用形式：**     
    
- setShowNumber(slotId: number, number: string, callback: AsyncCallback\<void>): void    
起始版本： 8    
- setShowNumber(slotId: number, number: string): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| number | string | true | SIM卡号码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回设置结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let number: string = '+861xxxxxxxxxx';  
sim.setShowNumber(0, number, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let number: string = '+861xxxxxxxxxx';  
sim.setShowNumber(0, number).then(() => {  
    console.log(`setShowNumber success.`);  
}).catch((err: BusinessError) => {  
    console.log(`setShowNumber failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getShowNumber<sup>(8+)</sup>    
获取指定卡槽SIM卡的号码。  
 **调用形式：**     
    
- getShowNumber(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 8    
- getShowNumber(slotId: number): Promise\<string>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回指定卡槽的号码。 |  
| Promise<string> | 以Promise形式返回指定卡槽的号码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getShowNumber(0, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getShowNumber(0).then((data: string) => {  
    console.log(`getShowNumber success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getShowNumber failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getOperatorConfigs<sup>(8+)</sup>    
获取运营商配置。  
 **调用形式：**     
    
- getOperatorConfigs(slotId: number, callback: AsyncCallback\<Array\<OperatorConfig>>): void    
起始版本： 8    
- getOperatorConfigs(slotId: number): Promise\<Array\<OperatorConfig>>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<Array<OperatorConfig>> | 以Promise形式返回运营商配置。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getOperatorConfigs(0, (err: BusinessError, data: Array<sim.OperatorConfig>) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getOperatorConfigs(0).then((data: Array<sim.OperatorConfig>) => {  
    console.log(`getOperatorConfigs success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getOperatorConfigs failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## unlockPin<sup>(7+)</sup>    
解锁指定卡槽SIM卡密码。  
 **调用形式：**     
    
- unlockPin(slotId: number, pin: string, callback: AsyncCallback\<LockStatusResponse>): void    
起始版本： 7    
- unlockPin(slotId: number, pin: string): Promise\<LockStatusResponse>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| pin | string | true | SIM卡的密码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<LockStatusResponse> | 以Promise形式返回获取指定卡槽的SIM卡锁状态的响应。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
| 8301002 | SIM card operation error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let pin: string = '1234';  
sim.unlockPin(0, pin, (err: BusinessError, data: sim.LockStatusResponse) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let pin: string = '1234';  
sim.unlockPin(0, pin).then((data: sim.LockStatusResponse) => {  
    console.log(`unlockPin success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`unlockPin failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## unlockPuk<sup>(7+)</sup>    
解锁指定卡槽SIM卡密码的解锁密码。  
 **调用形式：**     
    
- unlockPuk(slotId: number, newPin: string, puk: string, callback: AsyncCallback\<LockStatusResponse>): void    
起始版本： 7    
- unlockPuk(slotId: number, newPin: string, puk: string): Promise\<LockStatusResponse>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| newPin | string | true | 重置SIM卡的密码。 |  
| puk | string | true | SIM卡密码的解锁密码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<LockStatusResponse> | 以Promise形式返回获取指定卡槽的SIM卡锁状态的响应。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
| 8301002 | SIM card operation error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let puk: string = '1xxxxxxx';  
let newPin: string = '1235';  
sim.unlockPuk(0, newPin, puk, (err: BusinessError, data: sim.LockStatusResponse) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let puk: string = '1xxxxxxx';  
let newPin: string = '1235';  
sim.unlockPuk(0, newPin, puk).then((data: sim.LockStatusResponse) => {  
    console.log(`unlockPuk success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`unlockPuk failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## alterPin<sup>(7+)</sup>    
更改Pin密码。  
 **调用形式：**     
    
- alterPin(slotId: number, newPin: string, oldPin: string, callback: AsyncCallback\<LockStatusResponse>): void    
起始版本： 7    
- alterPin(slotId: number, newPin: string, oldPin: string): Promise\<LockStatusResponse>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| newPin | string | true | 新密码。 |  
| oldPin | string | true | 旧密码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<LockStatusResponse> | 以Promise形式返回指定卡槽SIM卡的Pin是否成功。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
| 8301002 | SIM card operation error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.alterPin(0, "1234", "0000", (err: BusinessError, data: sim.LockStatusResponse) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.alterPin(0, "1234", "0000").then((data: sim.LockStatusResponse) => {  
    console.log(`alterPin success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`alterPin failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setLockState<sup>(7+)</sup>    
设置指定卡槽SIM卡的锁状态。  
 **调用形式：**     
    
- setLockState(slotId: number, options: LockInfo, callback: AsyncCallback\<LockStatusResponse>): void    
起始版本： 7    
- setLockState(slotId: number, options: LockInfo): Promise\<LockStatusResponse>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| options | LockInfo | true | 锁信息。<br/>- lockType: [LockType](#locktype8)<br/>- password: string<br/>- state: [LockState](#lockstate8) |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<LockStatusResponse> | 以Promise形式返回获取指定卡槽SIM卡的锁状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
| 8301002 | SIM card operation error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let lockInfo: sim.LockInfo = {  
    lockType: sim.LockType.PIN_LOCK,  
    password: "1234",  
    state: sim.LockState.LOCK_OFF  
};  
sim.setLockState(0, lockInfo, (err: BusinessError, data: sim.LockStatusResponse) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let lockInfo: sim.LockInfo = {  
    lockType: sim.LockType.PIN_LOCK,  
    password: "1234",  
    state: sim.LockState.LOCK_OFF  
};  
sim.setLockState(0, lockInfo).then((data: sim.LockStatusResponse) => {  
    console.log(`setLockState success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`setLockState failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## unlockPin2<sup>(8+)</sup>    
解锁指定卡槽SIM卡密码。  
 **调用形式：**     
    
- unlockPin2(slotId: number, pin2: string, callback: AsyncCallback\<LockStatusResponse>): void    
起始版本： 8    
- unlockPin2(slotId: number, pin2: string): Promise\<LockStatusResponse>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| pin2 | string | true | SIM卡的密码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<LockStatusResponse> | 以Promise形式返回获取指定卡槽的SIM卡锁状态的响应。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
| 8301002 | SIM card operation error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let pin2: string = '1234';  
sim.unlockPin2(0, pin2, (err: BusinessError, data: sim.LockStatusResponse) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let pin2: string = '1234';  
sim.unlockPin2(0, pin2).then((data: sim.LockStatusResponse) => {  
    console.log(`unlockPin2 success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`unlockPin2 failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## unlockPuk2<sup>(8+)</sup>    
解锁指定卡槽SIM卡密码的解锁密码。  
 **调用形式：**     
    
- unlockPuk2(slotId: number, newPin2: string, puk2: string, callback: AsyncCallback\<LockStatusResponse>): void    
起始版本： 8    
- unlockPuk2(slotId: number, newPin2: string, puk2: string): Promise\<LockStatusResponse>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| newPin2 | string | true | 重置SIM卡的密码。 |  
| puk2 | string | true | SIM卡密码的解锁密码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<LockStatusResponse> | 以Promise形式返回获取指定卡槽的SIM卡锁状态的响应。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
| 8301002 | SIM card operation error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let puk2: string = '1xxxxxxx';  
let newPin2: string = '1235';  
sim.unlockPuk2(0, newPin2, puk2, (err: BusinessError, data: sim.LockStatusResponse) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let puk2: string = '1xxxxxxx';  
let newPin2: string = '1235';  
sim.unlockPuk2(0, newPin2, puk2).then((data: sim.LockStatusResponse) => {  
    console.log(`unlockPuk2 success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`unlockPuk2 failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## alterPin2<sup>(8+)</sup>    
更改Pin2密码。  
 **调用形式：**     
    
- alterPin2(slotId: number, newPin2: string, oldPin2: string, callback: AsyncCallback\<LockStatusResponse>): void    
起始版本： 8    
- alterPin2(slotId: number, newPin2: string, oldPin2: string): Promise\<LockStatusResponse>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| newPin2 | string | true | 新密码。 |  
| oldPin2 | string | true | 旧密码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<LockStatusResponse> | 以Promise形式返回指定卡槽SIM卡的Pin是否成功。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
| 8301002 | SIM card operation error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.alterPin2(0, "1234", "0000", (err: BusinessError, data: sim.LockStatusResponse) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.alterPin2(0, "1234", "0000").then((data: sim.LockStatusResponse) => {  
    console.log(`alterPin2 success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`alterPin2 failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## queryIccDiallingNumbers<sup>(8+)</sup>    
查询SIM卡联系人号码。  
 **调用形式：**     
    
- queryIccDiallingNumbers(slotId: number, type: ContactType, callback: AsyncCallback\<Array\<DiallingNumbersInfo>>): void    
起始版本： 8    
- queryIccDiallingNumbers(slotId: number, type: ContactType): Promise\<Array\<DiallingNumbersInfo>>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.READ_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| type | ContactType | true | 联系人类型。<br/>- 1 : GENERAL_CONTACT<br/>- 2 : FIXED_DIALING |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<Array<DiallingNumbersInfo>> | 以Promise形式返回Icc拨号号码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
| 8301002 | SIM card operation error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.queryIccDiallingNumbers(0, 1, (err: BusinessError, data: Array<sim.DiallingNumbersInfo>) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.queryIccDiallingNumbers(0, 1).then((data:  Array<sim.DiallingNumbersInfo>) => {  
    console.log(`queryIccDiallingNumbers success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`queryIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## addIccDiallingNumbers<sup>(8+)</sup>    
添加SIM卡联系人号码。  
 **调用形式：**     
    
- addIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback\<void>): void    
起始版本： 8    
- addIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.WRITE_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| type | ContactType | true | 联系人类型。<br/>- 1 : GENERAL_CONTACT<br/>- 2 : FIXED_DIALING |  
| diallingNumbers | DiallingNumbersInfo | true | 拨号号码信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式返回添加结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
| 8301002 | SIM card operation error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let diallingNumbersInof: sim.DiallingNumbersInfo = {  
    alphaTag: "alpha",  
    number: "138xxxxxxxx",  
    pin2: "1234"  
};  
sim.addIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let diallingNumbersInof: sim.DiallingNumbersInfo = {  
    alphaTag: "alpha",  
    number: "138xxxxxxxx"  
};  
sim.addIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof).then(() => {  
    console.log(`addIccDiallingNumbers success.`);  
}).catch((err: BusinessError) => {  
    console.log(`addIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## delIccDiallingNumbers<sup>(8+)</sup>    
删除SIM卡联系人号码。  
 **调用形式：**     
    
- delIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback\<void>): void    
起始版本： 8    
- delIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.WRITE_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| type | ContactType | true | 联系人类型。<br/>- 1 : GENERAL_CONTACT<br/>- 2 : FIXED_DIALING |  
| diallingNumbers | DiallingNumbersInfo | true | 拨号号码信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式返回删除结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
| 8301002 | SIM card operation error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let diallingNumbersInof: sim.DiallingNumbersInfo = {  
    alphaTag: "alpha",  
    number: "138xxxxxxxx",  
    recordNumber: 123,  
    pin2: "1234"  
};  
sim.delIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let diallingNumbersInof: sim.DiallingNumbersInfo = {  
    alphaTag: "alpha",  
    number: "138xxxxxxxx"  
};  
sim.delIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof).then(() => {  
    console.log(`delIccDiallingNumbers success.`);  
}).catch((err: BusinessError) => {  
    console.log(`delIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## updateIccDiallingNumbers<sup>(8+)</sup>    
更新SIM卡联系人号码。  
 **调用形式：**     
    
- updateIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback\<void>): void    
起始版本： 8    
- updateIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.WRITE_CONTACTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| type | ContactType | true | 联系人类型。<br/>- 1 : GENERAL_CONTACT<br/>- 2 : FIXED_DIALING |  
| diallingNumbers | DiallingNumbersInfo | true | 拨号号码信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式返回更新的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
| 8301002 | SIM card operation error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let diallingNumbersInof: sim.DiallingNumbersInfo = {  
    alphaTag: "alpha",  
    number: "138xxxxxxxx",  
    recordNumber: 123,  
    pin2: "1234"  
};  
sim.updateIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let diallingNumbersInof: sim.DiallingNumbersInfo = {  
    alphaTag: "alpha",  
    number: "138xxxxxxxx",  
    recordNumber: 123  
};  
sim.updateIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof).then(() => {  
    console.log(`updateIccDiallingNumbers success.`);  
}).catch((err: BusinessError) => {  
    console.log(`updateIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getLockState<sup>(8+)</sup>    
获取指定卡槽SIM卡的锁状态。  
 **调用形式：**     
    
- getLockState(slotId: number, lockType: LockType, callback: AsyncCallback\<LockState>): void    
起始版本： 8    
- getLockState(slotId: number, lockType: LockType): Promise\<LockState>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| lockType | LockType | true | 锁类型。<br/>- 1: PIN锁<br/>- 2: PIN2锁 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<LockState> | 以Promise形式返回获取指定卡槽SIM卡的锁状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
| 8301002 | SIM card operation error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getLockState(0, 1, (err: BusinessError, data: sim.LockState) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getLockState(0, 1).then((data: sim.LockState) => {  
    console.log(`getLockState success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getLockState failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## sendEnvelopeCmd<sup>(8+)</sup>    
发送信封命令。  
 **调用形式：**     
    
- sendEnvelopeCmd(slotId: number, cmd: string, callback: AsyncCallback\<void>): void    
起始版本： 8    
- sendEnvelopeCmd(slotId: number, cmd: string): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| cmd | string | true | 命令。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式返回发送结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.sendEnvelopeCmd(0, "ls", (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.sendEnvelopeCmd(0, "ls").then(() => {  
    console.log(`sendEnvelopeCmd success.`);  
}).catch((err: BusinessError) => {  
    console.log(`sendEnvelopeCmd failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## sendTerminalResponseCmd<sup>(8+)</sup>    
发送终端响应命令。  
 **调用形式：**     
    
- sendTerminalResponseCmd(slotId: number, cmd: string, callback: AsyncCallback\<void>): void    
起始版本： 8    
- sendTerminalResponseCmd(slotId: number, cmd: string): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| cmd | string | true | 命令。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式返回发送结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.sendTerminalResponseCmd(0, "ls", (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.sendTerminalResponseCmd(0, "ls").then(() => {  
    console.log(`sendTerminalResponseCmd success.`);  
}).catch((err: BusinessError) => {  
    console.log(`sendTerminalResponseCmd failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## unlockSimLock<sup>(8+)</sup>    
解锁SIM卡锁。  
 **调用形式：**     
    
- unlockSimLock(slotId: number, lockInfo: PersoLockInfo, callback: AsyncCallback\<LockStatusResponse>): void    
起始版本： 8    
- unlockSimLock(slotId: number, lockInfo: PersoLockInfo): Promise\<LockStatusResponse>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| lockInfo | PersoLockInfo | true | 定制锁类型信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<LockStatusResponse> | 以Promise形式返回锁状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
| 8301002 | SIM card operation error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let persoLockInfo: sim.PersoLockInfo = {  
    lockType: sim.PersoLockType.PN_PIN_LOCK,  
    password: "1234"  
};  
sim.unlockSimLock(0, persoLockInfo, (err: BusinessError, data: sim.LockStatusResponse) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let persoLockInfo: sim.PersoLockInfo = {  
    lockType: sim.PersoLockType.PN_PIN_LOCK,  
    password: "1234"  
};  
sim.unlockSimLock(0, persoLockInfo).then((data: sim.LockStatusResponse) => {  
    console.log(`unlockSimLock success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`unlockSimLock failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## OperatorConfig<sup>(8+)</sup>    
运营商配置。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| field<sup>(8+)</sup> | string | false | true | 字段 |  
| value<sup>(8+)</sup> | string | false | true | 值 |  
    
## LockStatusResponse<sup>(7+)</sup>    
锁状态响应。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| result<sup>(7+)</sup> | number | false | true | 当前操作的结果。 |  
| remain<sup>(7+)</sup> | number | false | false | 剩余次数（可以为空）。 |  
    
## DiallingNumbersInfo<sup>(8+)</sup>    
拨号号码信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| alphaTag<sup>(8+)</sup> | string | false | true | 标签。 |  
| number<sup>(8+)</sup> | string | false | true | 号码。 |  
| recordNumber<sup>(8+)</sup> | number | false | false | 记录编号。 |  
| pin2<sup>(8+)</sup> | string | false | false | pin2密码。 |  
    
## LockInfo<sup>(8+)</sup>    
锁状态响应。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| lockType<sup>(8+)</sup> | LockType | false | true | 锁类型。 |  
| password<sup>(8+)</sup> | string | false | true | 密码。 |  
| state<sup>(8+)</sup> | LockState | false | true | 锁状态。 |  
    
## PersoLockInfo<sup>(8+)</sup>    
锁状态响应。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| lockType<sup>(8+)</sup> | PersoLockType | false | true | 定制锁的类型。 |  
| password<sup>(8+)</sup> | string | false | true | 密码。 |  
    
## LockType<sup>(8+)</sup>    
锁类型。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PIN_LOCK | 1 | SIM卡密码锁。 |  
| FDN_LOCK | 2 | 固定拨号锁。 |  
    
## LockState<sup>(8+)</sup>    
锁状态。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| LOCK_OFF | 0 | 锁关闭状态 |  
| LOCK_ON | 1 | 锁开启状态 |  
    
## ContactType<sup>(8+)</sup>    
联系人类型。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| GENERAL_CONTACT | 1 | 通用联系人。 |  
| FIXED_DIALING | 2 | 固定拨号。 |  
    
## PersoLockType<sup>(8+)</sup>    
定制锁类型。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PN_PIN_LOCK | 0 | 定制网络PIN锁(参照 3GPP TS 22.022 [33])。 |  
| PN_PUK_LOCK | 1 | 定制网络PUk锁。 |  
| PU_PIN_LOCK | 2 | 定制网络子集PIN锁(参照 3GPP TS 22.022 [33])。 |  
| PU_PUK_LOCK | 3 | 定制网络子集PUK锁。 |  
| PP_PIN_LOCK | 4 | 定制服务提供者PIN锁(参照 3GPP TS 22.022 [33])。 |  
| PP_PUK_LOCK | 5 | 定制服务提供者PUK锁。 |  
| PC_PIN_LOCK | 6 | 定制企业PIN锁(参照 3GPP TS 22.022 [33])。 |  
| PC_PUK_LOCK | 7 | 定制企业Puk锁。 |  
| SIM_PIN_LOCK | 8 | 定制SIM的PIN锁(参照 3GPP TS 22.022 [33])。 |  
| SIM_PUK_LOCK | 9 | 定制SIM的PUK锁。 |  
    
## OperatorConfigKey<sup>(9+)</sup>    
运营商配置键。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| KEY_VOICE_MAIL_NUMBER_STRING | voice_mail_number_string | 语音邮件号码。 |  
| KEY_IMS_SWITCH_ON_BY_DEFAULT_BOOL | ims_switch_on_by_default_bool | 固定拨号。 |  
| KEY_HIDE_IMS_SWITCH_BOOL | hide_ims_switch_bool | 是否隐藏ims开关。 |  
| KEY_VOLTE_SUPPORTED_BOOL | volte_supported_bool | 是否支持volte模式。 |  
| KEY_NR_MODE_SUPPORTED_LIST_INT_ARRAY | nr_mode_supported_list_int_array | nr模式支持的列表。 |  
| KEY_VOLTE_PROVISIONING_SUPPORTED_BOOL | volte_provisioning_supported_bool | 是否支持配置VOLTE。 |  
| KEY_SS_OVER_UT_SUPPORTED_BOOL | ss_over_ut_supported_bool | SS服务是否支持UT。 |  
| KEY_IMS_GBA_REQUIRED_BOOL | ims_gba_required_bool | IMS是否需要GBA。 |  
| KEY_UT_PROVISIONING_SUPPORTED_BOOL | ut_provisioning_supported_bool | 是否支持UT配置。 |  
| KEY_IMS_PREFER_FOR_EMERGENCY_BOOL | ims_prefer_for_emergency_bool | IMS紧急首选项。 |  
| KEY_CALL_WAITING_SERVICE_CLASS_INT | call_waiting_service_class_int | 呼叫等待服务。 |  
| KEY_CALL_TRANSFER_VISIBILITY_BOOL | call_transfer_visibility_bool | 呼叫转移可见性。 |  
| KEY_IMS_CALL_DISCONNECT_REASON_INFO_MAPPING_STRING_ARRAY | ims_call_disconnect_reason_info_mapping_string_array | IMS呼叫结束原因列表。 |  
| KEY_FORCE_VOLTE_SWITCH_ON_BOOL | force_volte_switch_on_bool | 强制VOLTE开关。 |  
| KEY_ENABLE_OPERATOR_NAME_CUST_BOOL | enable_operator_name_cust_bool | 是否显示运营商名称。 |  
| KEY_OPERATOR_NAME_CUST_STRING | operator_name_cust_string | 运营商名称。 |  
| KEY_SPN_DISPLAY_CONDITION_CUST_INT | spn_display_condition_cust_int | SPN显示规则。 |  
| KEY_PNN_CUST_STRING_ARRAY | pnn_cust_string_array | PLMN名称。 |  
| KEY_OPL_CUST_STRING_ARRAY | opl_cust_string_array | 运营商PLMN信息。 |  
| KEY_EMERGENCY_CALL_STRING_ARRAY | emergency_call_string_array | 紧急呼叫列表。 |  
