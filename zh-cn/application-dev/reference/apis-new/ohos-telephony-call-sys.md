# @ohos.telephony.call    
该模块提供呼叫管理功能，包括拨打电话、跳转到拨号界面、获取通话状态、格式化电话号码等。  
  
如需订阅通话状态请使用[`observer.on('callStateChange')`](js-apis-observer.md#observeroncallstatechange)。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import call from '@ohos.telephony.call'    
```  
    
## dialCall<sup>(9+)</sup>    
拨打电话，可设置通话参数。  
 **调用形式：**     
    
- dialCall(phoneNumber: string, options: DialCallOptions, callback: AsyncCallback\<void>): void    
起始版本： 9    
- dialCall(phoneNumber: string, options?: DialCallOptions): Promise\<void>    
起始版本： 9    
- dialCall(phoneNumber: string, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.PLACE_CALL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| phoneNumber | string | true | 电话号码。 |  
| options | DialCallOptions | true | 通话参数，携带呼叫的其他配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以callback形式异步返回拨打电话的结果。 |  
| Promise<void> | 以Promise形式异步返回拨号结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300005 | Airplane mode is on. |  
| 8300006 | Network not in service. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let dialCallOptions: call.DialCallOptions = {  
    accountId: 0,  
    videoState: 0,  
    dialScene: 0,  
    dialType: 0,  
}  
call.dialCall("138xxxxxxxx", dialCallOptions, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let dialCallOptions: call.DialCallOptions = {  
    accountId: 0,  
    videoState: 0,  
    dialScene: 0,  
    dialType: 0,  
}  
call.dialCall("138xxxxxxxx", dialCallOptions).then(() => {  
    console.log(`dialCall success.`);  
}).catch((err: BusinessError) => {  
    console.error(`dialCall fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## muteRinger<sup>(8+)</sup>    
如果来电铃声响起，设备将停止铃声。否则，此方法不起作用。  
 **调用形式：**     
    
- muteRinger(callback: AsyncCallback\<void>): void    
起始版本： 8    
- muteRinger(): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.muteRinger((err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.muteRinger().then(() => {  
    console.log(`muteRinger success.`);  
}).catch((err: BusinessError) => {  
    console.error(`muteRinger fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## answerCall<sup>(9+)</sup>    
接听来电。  
 **调用形式：**     
    
- answerCall(callId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- answerCall(callId?: number): Promise\<void>    
起始版本： 9    
- answerCall(callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.ANSWER_CALL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callId | number | true | 呼叫Id。可以通过订阅callDetailsChange事件获得。从API Version 9开始为可选参数。<br/>不填该参数则接通最近一通正在响铃的来电。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
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
  
call.answerCall(1, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.answerCall(1).then(() => {  
    console.log(`answerCall success.`);  
}).catch((err: BusinessError) => {  
    console.error(`answerCall fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## hangUpCall<sup>(9+)</sup>    
挂断电话。  
 **调用形式：**     
    
- hangUpCall(callId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- hangUpCall(callId?: number): Promise\<void>    
起始版本： 9    
- hangUpCall(callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.ANSWER_CALL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callId | number | true | 呼叫id。可以通过订阅callDetailsChange事件获得。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
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
  
call.hangUpCall(1, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.hangUpCall(1).then(() => {  
    console.log(`hangUpCall success.`);  
}).catch((err: BusinessError) => {  
    console.error(`hangUpCall fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## rejectCall<sup>(9+)</sup>    
拒绝来电。  
 **调用形式：**     
    
- rejectCall(callId: number, options: RejectMessageOptions, callback: AsyncCallback\<void>): void    
起始版本： 9    
- rejectCall(callId?: number, options?: RejectMessageOptions): Promise\<void>    
起始版本： 9    
- rejectCall(callId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- rejectCall(callback: AsyncCallback\<void>): void    
起始版本： 9    
- rejectCall(options: RejectMessageOptions, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.ANSWER_CALL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callId | number | true | 呼叫Id。可以通过订阅callDetailsChange事件获得。 |  
| options | RejectMessageOptions | true | 拒绝消息选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
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
  
let rejectMessageOptions : call.RejectMessageOptions = {  
    messageContent: "拦截陌生号码"  
}  
call.rejectCall(1, rejectMessageOptions, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let rejectMessageOptions: call.RejectMessageOptions = {  
    messageContent: "拦截陌生号码"  
}  
call.rejectCall(1, rejectMessageOptions).then(() => {  
    console.log(`rejectCall success.`);  
}).catch((err: BusinessError) => {  
    console.error(`rejectCall fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## holdCall<sup>(7+)</sup>    
保持通话。  
 **调用形式：**     
    
- holdCall(callId: number, callback: AsyncCallback\<void>): void    
起始版本： 7    
- holdCall(callId: number): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.ANSWER_CALL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callId | number | true | 呼叫Id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
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
  
call.holdCall(1, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.holdCall(1).then(() => {  
    console.log(`holdCall success.`);  
}).catch((err: BusinessError) => {  
    console.error(`holdCall fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## unHoldCall<sup>(7+)</sup>    
取消保持通话。  
 **调用形式：**     
    
- unHoldCall(callId: number, callback: AsyncCallback\<void>): void    
起始版本： 7    
- unHoldCall(callId: number): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.ANSWER_CALL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callId | number | true | 呼叫Id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
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
  
call.unHoldCall(1, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.unHoldCall(1).then(() => {  
    console.log(`unHoldCall success.`);  
}).catch((err: BusinessError) => {  
    console.error(`unHoldCall fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## switchCall<sup>(7+)</sup>    
切换呼叫。  
 **调用形式：**     
    
- switchCall(callId: number, callback: AsyncCallback\<void>): void    
起始版本： 7    
- switchCall(callId: number): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.ANSWER_CALL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callId | number | true | 呼叫Id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
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
  
call.switchCall(1, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.switchCall(1).then(() => {  
    console.log(`switchCall success.`);  
}).catch((err: BusinessError) => {  
    console.error(`switchCall fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## combineConference<sup>(7+)</sup>    
合并通话，将两通电话合并成会议电话。  
 **调用形式：**     
    
- combineConference(callId: number, callback: AsyncCallback\<void>): void    
起始版本： 7    
- combineConference(callId: number, callback: AsyncCallback\<void>): void    
起始版本： 11    
- combineConference(callId: number): Promise\<void>    
起始版本： 7    
- combineConference(callId: number): Promise\<void>    
起始版本： 11  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callId | number | true | 呼叫Id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 801 | Capability not supported. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300007 | The number of conference calls exceeds the limit. |  
    
 **示例代码1：**   
示例（callback）:  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.combineConference(1, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.combineConference(1).then(() => {  
    console.log(`combineConference success.`);  
}).catch((err: BusinessError) => {  
    console.error(`combineConference fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getMainCallId<sup>(7+)</sup>    
获取主呼叫Id。  
 **调用形式：**     
    
- getMainCallId(callId: number, callback: AsyncCallback\<number>): void    
起始版本： 7    
- getMainCallId(callId: number): Promise\<number>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callId | number | true | 呼叫Id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回主呼叫Id。 |  
| Promise<number> | 以Promise形式异步返回主呼叫Id。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 801 | Capability not supported. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.getMainCallId(1, (err: BusinessError, data: number) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.getMainCallId(1).then((data: number) => {  
    console.log(`getMainCallId success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getMainCallId fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getSubCallIdList<sup>(7+)</sup>    
获取子呼叫Id列表。  
 **调用形式：**     
    
- getSubCallIdList(callId: number, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 7    
- getSubCallIdList(callId: number): Promise\<Array\<string>>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callId | number | true | 呼叫Id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回子呼叫Id列表。 |  
| Promise<Array<string>> | 以Promise形式异步返回子呼叫Id列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 801 |  |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.getSubCallIdList(1, (err: BusinessError, data: Array<string>) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.getSubCallIdList(1).then((data: Array<string>) => {  
    console.log(`getSubCallIdList success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getSubCallIdList fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getCallIdListForConference<sup>(7+)</sup>    
获取会议的呼叫Id列表。  
 **调用形式：**     
    
- getCallIdListForConference(callId: number, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 7    
- getCallIdListForConference(callId: number): Promise\<Array\<string>>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callId | number | true | 呼叫Id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回会议的呼叫Id列表。 |  
| Promise<Array<string>> | 以Promise形式异步返回会议的呼叫Id列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 801 | Capability not supported. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.getCallIdListForConference(1, (err: BusinessError, data: Array<string>) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.getCallIdListForConference(1).then((data: Array<string>) => {  
    console.log(`getCallIdListForConference success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getCallIdListForConference fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getCallWaitingStatus<sup>(7+)</sup>    
获取呼叫等待状态  
 **调用形式：**     
    
- getCallWaitingStatus(slotId: number, callback: AsyncCallback\<CallWaitingStatus>): void    
起始版本： 7    
- getCallWaitingStatus(slotId: number): Promise\<CallWaitingStatus>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。<br/>返回呼叫等待状态。<br/>- 0：禁用呼叫等待 <br/>- 1：启用呼叫等待 |  
| Promise<CallWaitingStatus> | 以Promise形式异步返回呼叫等待状态。<br/>- 0：禁用呼叫等待 <br/>- 1：启用呼叫等待 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 801 | Capability not supported. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）:  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.getCallWaitingStatus(0, (err: BusinessError, data: call.CallWaitingStatus) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.getCallWaitingStatus(0).then((data: call.CallWaitingStatus) => {  
    console.log(`getCallWaitingStatus success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getCallWaitingStatus fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setCallWaiting<sup>(7+)</sup>    
设置呼叫等待。  
 **调用形式：**     
    
- setCallWaiting(slotId: number, activate: boolean, callback: AsyncCallback\<void>): void    
起始版本： 7    
- setCallWaiting(slotId: number, activate: boolean): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| activate | boolean | true | 呼叫等待是否处于启用状态。<br/>- false：禁用呼叫等待<br/>- true：启用呼叫等待 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 801 | Permission denied. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）:  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.setCallWaiting(0, true, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.setCallWaiting(0, true).then(() => {  
    console.log(`setCallWaiting success.`);  
}).catch((err: BusinessError) => {  
    console.error(`setCallWaiting fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## startDTMF<sup>(7+)</sup>    
启动双音多频。  
 **调用形式：**     
    
- startDTMF(callId: number, character: string, callback: AsyncCallback\<void>): void    
起始版本： 7    
- startDTMF(callId: number, character: string): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callId | number | true | 呼叫Id。 |  
| character | string | true | DTMF码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 801 | Permission denied. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）:  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.startDTMF(1, "0", (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.startDTMF(1, "0").then(() => {  
    console.log(`startDTMF success.`);  
}).catch((err: BusinessError) => {  
    console.error(`startDTMF fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## stopDTMF<sup>(7+)</sup>    
停止双音多频。  
 **调用形式：**     
    
- stopDTMF(callId: number, callback: AsyncCallback\<void>): void    
起始版本： 7    
- stopDTMF(callId: number): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callId | number | true | 呼叫Id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 801 | Permission denied. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.stopDTMF(1, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.stopDTMF(1).then(() => {  
    console.log(`stopDTMF success.`);  
}).catch((err: BusinessError) => {  
    console.error(`stopDTMF fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## postDialProceed<sup>(11+)</sup>    
继续进行通话。  当用户呼叫号码为：“普通电话号码”+“;”+"DTMF字符"，例如“400xxxxxxx;123”，并且已经订阅了通话后延迟事件， 电话接通后，系统将上报通话后延迟事件，应用可以调用此接口选择是否发送DTMF音。  
 **调用形式：**     
    
- postDialProceed(callId: number, proceed: boolean, callback: AsyncCallback\<void>): void    
起始版本： 11    
- postDialProceed(callId: number, proceed: boolean): Promise\<void>    
起始版本： 11  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callId | number | true | 呼叫Id。 |  
| proceed | boolean | true | 用户选择是否发送DTMF（Dual Tone Multi Frequency，双音多频）音。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 801 | Permission denied. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.postDialProceed(1, true, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.postDialProceed(1, true).then(() => {  
    console.log(`postDialProceed success.`);  
}).catch((err: BusinessError) => {  
    console.error(`postDialProceed fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## isInEmergencyCall<sup>(7+)</sup>    
判断是否正在处于紧急呼叫。  
 **调用形式：**     
    
- isInEmergencyCall(callback: AsyncCallback\<boolean>): void    
起始版本： 7    
- isInEmergencyCall(): Promise\<boolean>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<boolean> | 以Promise形式异步返回结果。 |  
    
    
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
  
call.isInEmergencyCall((err: BusinessError, data: boolean) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.isInEmergencyCall().then((data: boolean) => {  
    console.log(`isInEmergencyCall success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`isInEmergencyCall fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## on('callDetailsChange')<sup>(7+)</sup>    
订阅callDetailsChange事件。  
 **调用形式：**     
    
- on(type: 'callDetailsChange', callback: Callback\<CallAttributeOptions>): void    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 通话时监听通话详情的变化，参数固定为'callDetailsChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
    
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
    
 **示例代码：**   
```ts    
call.on('callDetailsChange', (data: call.CallAttributeOptions) => {    console.log(`callback: data->${JSON.stringify(data)}`);});    
```    
  
    
## off('callDetailsChange')<sup>(7+)</sup>    
取消订阅callDetailsChange事件。  
 **调用形式：**     
    
- off(type: 'callDetailsChange', callback?: Callback\<CallAttributeOptions>): void    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 通话结束时取消监听通话详情的变化，参数固定为'callDetailsChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。不填该参数将不会收到取消订阅的处理结果。 |  
    
    
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
    
 **示例代码：**   
```ts    
call.off('callDetailsChange', (data: call.CallAttributeOptions) => {    console.log(`callback: data->${JSON.stringify(data)}`);});    
```    
  
    
## on('callEventChange')<sup>(8+)</sup>    
订阅callEventChange事件。  
 **调用形式：**     
    
- on(type: 'callEventChange', callback: Callback\<CallEventOptions>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | <span style="font-family: monospace, monospace; font-size: 1em; letter-spacing: 0px;">通话时监听通话事件的变化，参数固定为'callEventChange'。</span> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
    
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
    
 **示例代码：**   
```ts    
call.on('callEventChange', (data: call.CallEventOptions) => {    console.log(`callback: data->${JSON.stringify(data)}`);});    
```    
  
    
## off('callEventChange')<sup>(8+)</sup>    
取消订阅callEventChange事件。  
 **调用形式：**     
    
- off(type: 'callEventChange', callback?: Callback\<CallEventOptions>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 通话结束时取消监听通话事件的变化，参数固定为'callEventChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。不填该参数将不会收到取消订阅的处理结果。 |  
    
    
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
    
 **示例代码：**   
```ts    
call.off('callEventChange', (data: call.CallEventOptions) => {    console.log(`callback: data->${JSON.stringify(data)}`);});    
```    
  
    
## on('callDisconnectedCause')<sup>(8+)</sup>    
订阅callDisconnectedCause事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'callDisconnectedCause', callback: Callback\<DisconnectedDetails>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 通话时监听断开连接的原因，参数固定为'callDisconnectedCause'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
    
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
    
 **示例代码：**   
```ts    
call.on('callDisconnectedCause', (data: call.DisconnectedDetails) => {    console.log(`callback: data->${JSON.stringify(data)}`);});    
```    
  
    
## off('callDisconnectedCause')<sup>(8+)</sup>    
取消订阅callDisconnectedCause事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'callDisconnectedCause', callback?: Callback\<DisconnectedDetails>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 调用断开连接的原因，参数固定为'callDisconnectedCause'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 调用断开连接的原因，参数固定为'callDisconnectedCause'。 |  
    
    
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
    
 **示例代码：**   
```ts    
call.off('callDisconnectedCause', (data: call.DisconnectedDetails) => {    console.log(`callback: data->${JSON.stringify(data)}`);});    
```    
  
    
## on('mmiCodeResult')<sup>(9+)</sup>    
订阅mmiCodeResult事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'mmiCodeResult', callback: Callback\<MmiCodeResults>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 通话时监听MMI码结果，参数固定为'mmiCodeResult'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
    
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
    
 **示例代码：**   
```ts    
call.on('mmiCodeResult', (data: call.MmiCodeResults) => {    console.log(`callback: data->${JSON.stringify(data)}`);});    
```    
  
    
## off('mmiCodeResult')<sup>(9+)</sup>    
取消订阅mmiCodeResult事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'mmiCodeResult', callback?: Callback\<MmiCodeResults>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | MMI码结果，参数固定为'mmiCodeResult'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。不填该参数将不会收到取消订阅的处理结果。 |  
    
    
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
    
 **示例代码：**   
```ts    
call.off('mmiCodeResult', (data: call.MmiCodeResults) => {    console.log(`callback: data->${JSON.stringify(data)}`);});    
```    
  
    
## on('audioDeviceChange')<sup>(10+)</sup>    
订阅通话音频设备切换事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'audioDeviceChange', callback: Callback\<AudioDeviceCallbackInfo>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 通话音频设备发生变化，参数固定为'audioDeviceChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
    
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
    
 **示例代码：**   
```ts    
call.on('audioDeviceChange', (data: call.AudioDeviceCallbackInfo) => {    console.log(`callback: data->${JSON.stringify(data)}`);});    
```    
  
    
## off('audioDeviceChange')<sup>(10+)</sup>    
取消订阅audioDeviceChange事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'audioDeviceChange', callback?: Callback\<AudioDeviceCallbackInfo>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 通话音频设备发生变化，参数固定为'audioDeviceChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。不填该参数将不会收到取消订阅的处理结果。 |  
    
    
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
    
 **示例代码：**   
示例（callback）:  
```ts    
call.off('audioDeviceChange', (data: call.AudioDeviceCallbackInfo) => {    console.log(`callback: data->${JSON.stringify(data)}`);});    
```    
  
    
## on('postDialDelay')<sup>(11+)</sup>    
订阅拨号后延迟事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'postDialDelay', callback: Callback\<string>): void    
起始版本： 11  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 拨号后延迟，参数固定为'postDialDelay'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
    
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
    
 **示例代码：**   
示例（callback）:  
```ts    
call.on('postDialDelay', (data: string) => {    console.log(`callback: data->${JSON.stringify(data)}`);});    
```    
  
    
## off('postDialDelay')<sup>(11+)</sup>    
取消订阅拨号后延迟事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'postDialDelay', callback?: Callback\<string>): void    
起始版本： 11  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 拨号后延迟，参数固定为'postDialDelay'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。不填该参数将不会收到取消订阅的处理结果。 |  
    
    
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
    
 **示例代码：**   
示例（callback）:  
  
```ts    
call.off('postDialDelay', (data: string) => {    console.log(`callback: data->${JSON.stringify(data)}`);});    
```    
  
    
## isNewCallAllowed<sup>(8+)</sup>    
判断是否允许再拨打一通新电话。  
 **调用形式：**     
    
- isNewCallAllowed(callback: AsyncCallback\<boolean>): void    
起始版本： 8    
- isNewCallAllowed(): Promise\<boolean>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<boolean> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
  
call.isNewCallAllowed((err: BusinessError, data: boolean) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.isNewCallAllowed().then((data: boolean) => {  
    console.log(`isNewCallAllowed success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`isNewCallAllowed fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## separateConference<sup>(8+)</sup>    
分离会议电话。  
 **调用形式：**     
    
- separateConference(callId: number, callback: AsyncCallback\<void>): void    
起始版本： 8    
- separateConference(callId: number, callback: AsyncCallback\<void>): void    
起始版本： 11    
- separateConference(callId: number): Promise\<void>    
起始版本： 8    
- separateConference(callId: number): Promise\<void>    
起始版本： 11  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callId | number | true | 呼叫Id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
| 8300008 |  |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.separateConference(1, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.separateConference(1).then(() => {  
    console.log(`separateConference success.`);  
}).catch((err: BusinessError) => {  
    console.error(`separateConference fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getCallRestrictionStatus<sup>(8+)</sup>    
获取呼叫限制状态。  
 **调用形式：**     
    
- getCallRestrictionStatus(slotId: number, type: CallRestrictionType, callback: AsyncCallback\<RestrictionStatus>): void    
起始版本： 8    
- getCallRestrictionStatus(slotId: number, type: CallRestrictionType): Promise\<RestrictionStatus>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| type | CallRestrictionType | true | 呼叫限制类型。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回限制状态。 |  
| Promise<RestrictionStatus> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 801 | Capability not supported. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.getCallRestrictionStatus(0, 1, (err: BusinessError, data: call.RestrictionStatus) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.getCallRestrictionStatus(0, 1).then((data: call.RestrictionStatus) => {  
    console.log(`getCallRestrictionStatus success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getCallRestrictionStatus fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setCallRestriction<sup>(8+)</sup>    
设置呼叫限制状态。  
 **调用形式：**     
    
- setCallRestriction(slotId: number, info: CallRestrictionInfo, callback: AsyncCallback\<void>): void    
起始版本： 8    
- setCallRestriction(slotId: number, info: CallRestrictionInfo): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true |  卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| info | CallRestrictionInfo | true |  呼叫限制信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 801 | Capability not supported. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let callRestrictionInfo: call.CallRestrictionInfo = {  
    type: call.CallRestrictionType.RESTRICTION_TYPE_ALL_OUTGOING,  
    password: "123456",  
    mode: call.CallRestrictionMode.RESTRICTION_MODE_ACTIVATION  
}  
call.setCallRestriction(0, callRestrictionInfo, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let callRestrictionInfo: call.CallRestrictionInfo = {  
    type: call.CallRestrictionType.RESTRICTION_TYPE_ALL_INCOMING,  
    password: "123456",  
    mode: call.CallRestrictionMode.RESTRICTION_MODE_ACTIVATION  
}  
call.setCallRestriction(0, callRestrictionInfo).then(() => {  
    console.log(`setCallRestriction success.`);  
}).catch((err: BusinessError) => {  
    console.error(`setCallRestriction fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setCallRestrictionPassword<sup>(10+)</sup>    
修改呼叫限制密码  
 **调用形式：**     
    
- setCallRestrictionPassword(slotId: number, oldPassword: string, newPassword: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setCallRestrictionPassword(slotId: number, oldPassword: string, newPassword: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| oldPassword | string | true | 呼叫限制旧密码。    |  
| newPassword | string | true | 呼叫限制新密码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 801 | Capability not supported. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.setCallRestrictionPassword(0, "123456", "654321", (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.setCallRestrictionPassword(0, "123456", "654321").then(() => {  
    console.log(`setCallRestrictionPassword success.`);  
}).catch((err: BusinessError) => {  
    console.error(`setCallRestrictionPassword fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getCallTransferInfo<sup>(8+)</sup>    
获取呼叫转移信息。  
 **调用形式：**     
    
- getCallTransferInfo(slotId: number, type: CallTransferType, callback: AsyncCallback\<CallTransferResult>): void    
起始版本： 8    
- getCallTransferInfo(slotId: number, type: CallTransferType): Promise\<CallTransferResult>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| type | CallTransferType | true | 呼叫转移类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回呼叫转移信息。 |  
| Promise<CallTransferResult> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 801 | Capability not supported. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.getCallTransferInfo(0, call.CallTransferType.TRANSFER_TYPE_BUSY, (err: BusinessError, data: call.CallTransferResult) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.getCallTransferInfo(0, call.CallTransferType.TRANSFER_TYPE_BUSY).then((data: call.CallTransferResult) => {  
    console.log(`getCallTransferInfo success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getCallTransferInfo fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setCallTransfer<sup>(8+)</sup>    
设置呼叫转移信息。  
 **调用形式：**     
    
- setCallTransfer(slotId: number, info: CallTransferInfo, callback: AsyncCallback\<void>): void    
起始版本： 8    
- setCallTransfer(slotId: number, info: CallTransferInfo): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| info | CallTransferInfo | true | 呼叫转移信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 801 | Capability not supported. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let callTransferInfo: call.CallTransferInfo = {  
    transferNum: "111",  
    type: call.CallTransferType.TRANSFER_TYPE_BUSY,  
    settingType: call.CallTransferSettingType.CALL_TRANSFER_ENABLE  
}  
call.setCallTransfer(0, callTransferInfo, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let callTransferInfo: call.CallTransferInfo = {  
    transferNum: "111",  
    type: call.CallTransferType.TRANSFER_TYPE_BUSY,  
    settingType: call.CallTransferSettingType.CALL_TRANSFER_ENABLE  
}  
call.setCallTransfer(0, callTransferInfo).then(() => {  
    console.log(`setCallTransfer success.`);  
}).catch((err: BusinessError) => {  
    console.error(`setCallTransfer fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## isRinging<sup>(8+)</sup>    
判断是否正在响铃。  
 **调用形式：**     
    
- isRinging(callback: AsyncCallback\<boolean>): void    
起始版本： 8    
- isRinging(): Promise\<boolean>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<boolean> | 以Promise形式异步返回结果。 |  
    
    
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
  
call.isRinging((err: BusinessError, data: boolean) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.isRinging().then((data: boolean) => {  
    console.log(`isRinging success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`isRinging fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setMuted<sup>(8+)</sup>    
设置通话中的静音。  
 **调用形式：**     
    
- setMuted(callback: AsyncCallback\<void>): void    
起始版本： 8    
- setMuted(): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
  
call.setMuted((err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.setMuted().then(() => {  
    console.log(`setMuted success.`);  
}).catch((err: BusinessError) => {  
    console.error(`setMuted fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## cancelMuted<sup>(8+)</sup>    
取消通话中的静音。  
 **调用形式：**     
    
- cancelMuted(callback: AsyncCallback\<void>): void    
起始版本： 8    
- cancelMuted(): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
  
call.cancelMuted((err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.cancelMuted().then(() => {  
    console.log(`cancelMuted success.`);  
}).catch((err: BusinessError) => {  
    console.error(`cancelMuted fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setAudioDevice<sup>(8+)</sup>    
设置通话音频设备。  
 **调用形式：**     
    
- setAudioDevice(device: AudioDevice, callback: AsyncCallback\<void>): void    
起始版本： 8    
- setAudioDevice(device: AudioDevice): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device | AudioDevice | true | 音频设备。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
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
  
let audioDevice: call.AudioDevice = {  
    deviceType: call.AudioDeviceType.DEVICE_EARPIECE  
}  
call.setAudioDevice(audioDevice, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let audioDevice: call.AudioDevice = {  
    deviceType: call.AudioDeviceType.DEVICE_EARPIECE  
}  
call.setAudioDevice(audioDevice).then(() => {  
    console.log(`setAudioDevice success.`);  
}).catch((err: BusinessError) => {  
    console.error(`setAudioDevice fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## joinConference<sup>(8+)</sup>    
加入会议。  
 **调用形式：**     
    
- joinConference(mainCallId: number, callNumberList: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 8    
- joinConference(mainCallId: number, callNumberList: Array\<string>): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mainCallId | number | true | 主通话Id。 |  
| callNumberList | Array<string> | true | 呼叫号码列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
  
let callNumberList: Array<string> = [  
    "138XXXXXXXX"  
];  
call.joinConference(1, callNumberList, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let callNumberList: Array<string> = [  
    "138XXXXXXXX"  
];  
call.joinConference(1, callNumberList).then(() => {  
    console.log(`joinConference success.`);  
}).catch((err: BusinessError) => {  
    console.error(`joinConference fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## kickOutFromConference<sup>(10+)</sup>    
移出电话会议，将指定通话从会议电话中挂断。  
 **调用形式：**     
    
- kickOutFromConference(callId: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- kickOutFromConference(callId: number): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.PLACE_CALL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callId | number | true | 呼叫Id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
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
  
call.kickOutFromConference(1, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.kickOutFromConference(1).then(() => {  
    console.log(`kickOutFromConference success.`);  
}).catch((err: BusinessError) => {  
    console.error(`kickOutFromConference fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## updateImsCallMode<sup>(8+)</sup>    
更新Ims呼叫模式。  
 **调用形式：**     
    
- updateImsCallMode(callId: number, mode: ImsCallMode, callback: AsyncCallback\<void>): void    
起始版本： 8    
- updateImsCallMode(callId: number, mode: ImsCallMode): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callId | number | true | 呼叫Id。 |  
| mode | ImsCallMode | true | Ims呼叫模式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
  
call.updateImsCallMode(1, 1, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.updateImsCallMode(1, 1).then(() => {  
    console.log(`updateImsCallMode success.`);  
}).catch((err: BusinessError) => {  
    console.error(`updateImsCallMode fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## enableImsSwitch<sup>(8+)</sup>    
启用Ims开关。  
 **调用形式：**     
    
- enableImsSwitch(slotId: number, callback: AsyncCallback\<void>): void    
起始版本： 8    
- enableImsSwitch(slotId: number): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
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
  
call.enableImsSwitch(0, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.enableImsSwitch(0).then(() => {  
    console.log(`enableImsSwitch success.`);  
}).catch((err: BusinessError) => {  
    console.error(`enableImsSwitch fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## disableImsSwitch<sup>(8+)</sup>    
禁用Ims开关。  
 **调用形式：**     
    
- disableImsSwitch(slotId: number, callback: AsyncCallback\<void>): void    
起始版本： 8    
- disableImsSwitch(slotId: number): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
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
  
call.disableImsSwitch(0, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.disableImsSwitch(0).then(() => {  
    console.log(`disableImsSwitch success.`);  
}).catch((err: BusinessError) => {  
    console.error(`disableImsSwitch fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## isImsSwitchEnabled<sup>(8+)</sup>    
判断Ims开关是否启用。  
 **调用形式：**     
    
- isImsSwitchEnabled(slotId: number, callback: AsyncCallback\<boolean>): void    
起始版本： 8    
- isImsSwitchEnabled(slotId: number): Promise\<boolean>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<boolean> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
  
call.isImsSwitchEnabled(0, (err: BusinessError, data: boolean) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.isImsSwitchEnabled(0).then((data: boolean) => {  
    console.log(`isImsSwitchEnabled success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`isImsSwitchEnabled fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## closeUnfinishedUssd<sup>(10+)</sup>    
取消未激活完成的非结构化补充数据业务。  
 **调用形式：**     
    
- closeUnfinishedUssd(slotId: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- closeUnfinishedUssd(slotId: number): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
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
let slotId: number = 0;call.closeUnfinishedUssd(slotId, (err: BusinessError) => {    console.log(`callback: err->${JSON.stringify(err)}`);});    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
call.closeUnfinishedUssd(slotId).then(() => {  
    console.log(`closeUnfinishedUssd success.`);  
}).catch((err: BusinessError) => {  
    console.error(`closeUnfinishedUssd fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setVoNRState<sup>(10+)</sup>    
设置NR语音的开关状态。  
 **调用形式：**     
    
- setVoNRState(slotId: number, state: VoNRState, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setVoNRState(slotId: number, state: VoNRState): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2  |  
| state | VoNRState | true |  开关状态。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
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
  
let slotId: number = 0;  
let state: call.VoNRState = call.VoNRState.VONR_STATE_ON;  
call.setVoNRState(slotId, state, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let state: call.VoNRState = call.VoNRState.VONR_STATE_ON;  
call.setVoNRState(slotId, state).then(() => {  
    console.log(`setVoNRState success`);  
}).catch((err: BusinessError) => {  
    console.error(`setVoNRState fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getVoNRState<sup>(10+)</sup>    
查询NR语音的开关状态。  
 **调用形式：**     
    
- getVoNRState(slotId: number, callback: AsyncCallback\<VoNRState>): void    
起始版本： 10    
- getVoNRState(slotId: number): Promise\<VoNRState>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回NR语音开关的状态。 |  
| Promise<VoNRState> | 以Promise形式异步返回开关状态。 |  
    
    
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
  
let slotId: number = 0;  
call.getVoNRState(slotId, (err: BusinessError, data: call.VoNRState) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
call.getVoNRState(slotId).then((data: call.VoNRState) => {  
    console.log(`getVoNRState success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getVoNRState fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## canSetCallTransferTime<sup>(10+)</sup>    
检查是否可以设置呼叫转移时间。  
 **调用形式：**     
    
- canSetCallTransferTime(slotId: number, callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- canSetCallTransferTime(slotId: number): Promise\<boolean>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2      |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示可以设置，返回false表示不可以设置。 |  
| Promise<boolean> | 以Promise形式异步返回是否可以设置呼叫转移时间。 |  
    
    
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
  
let slotId: number = 0;  
call.canSetCallTransferTime(slotId, (err: BusinessError, data: boolean) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
call.canSetCallTransferTime(slotId).then((data: boolean) => {  
    console.log(`canSetCallTransferTime success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`canSetCallTransferTime fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## inputDialerSpecialCode<sup>(10+)</sup>    
暗码广播。  
 **调用形式：**     
    
- inputDialerSpecialCode(inputCode: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- inputDialerSpecialCode(inputCode: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.PLACE_CALL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| inputCode | string | true | 暗码。支持暗码字段, 如：2846579(工程菜单)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.inputDialerSpecialCode('2846579', (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    call.inputDialerSpecialCode('2846579');  
    console.log(`inputDialerSpecialCode success`);  
} catch (error) {  
    console.log(`inputDialerSpecialCode fail, promise: err->${JSON.stringify(error)}`);  
}  
    
```    
  
    
## removeMissedIncomingCallNotification<sup>(10+)</sup>    
删除未接来电通知。  
 **调用形式：**     
    
- removeMissedIncomingCallNotification(callback: AsyncCallback\<void>): void    
起始版本： 10    
- removeMissedIncomingCallNotification(): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE and ohos.permission.READ_CALL_LOG and ohos.permission.WRITE_CALL_LOG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数 |  
| Promise<void> | 以Promise形式异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 |  |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.removeMissedIncomingCallNotification((err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.removeMissedIncomingCallNotification().then(() => {  
    console.log(`removeMissedIncomingCallNotification success`);  
}).catch((err: BusinessError) => {  
    console.log(`removeMissedIncomingCallNotification failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## ImsCallMode<sup>(8+)</sup>    
仅限音频呼叫。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CALL_MODE_AUDIO_ONLY | 0 |  |  
| CALL_MODE_SEND_ONLY | 1 | 仅发送呼叫 |  
| CALL_MODE_RECEIVE_ONLY | 2 | 仅接收呼叫 |  
| CALL_MODE_SEND_RECEIVE | 3 | 允许发送和接收呼叫 |  
| CALL_MODE_VIDEO_PAUSED | 4 | 暂停视频呼叫 |  
    
## VoNRState<sup>(10+)</sup>    
5G语音开关状态。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| VONR_STATE_OFF | 0 | 关闭状态 |  
| VONR_STATE_ON | 1 | 打开状态  |  
    
## AudioDeviceType<sup>(10+)</sup>    
音频设备类型。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEVICE_EARPIECE | 0 | 耳机设备  |  
| DEVICE_SPEAKER | 1 | 扬声器设备 |  
| DEVICE_WIRED_HEADSET | 2 | 有线耳机设备 |  
| DEVICE_BLUETOOTH_SCO | 3 | 蓝牙SCO设备 |  
    
## AudioDevice<sup>(10+)</sup>    
音频设备。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceType<sup>(10+)</sup> | AudioDeviceType | false | true | 音频设备类型。 |  
| address<sup>(10+)</sup> | string | false | false | 音频设备地址。 |  
    
## AudioDeviceCallbackInfo<sup>(10+)</sup>    
音频设备信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| audioDeviceList<sup>(10+)</sup> | Array<AudioDevice> | false | true | 音频设备列表。 |  
| currentAudioDevice<sup>(10+)</sup> | AudioDevice | false | true | 当前音频设备。 |  
| isMuted<sup>(10+)</sup> | boolean | false | true | 是否静音。 |  
    
## CallRestrictionType<sup>(8+)</sup>    
呼叫限制类型。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| RESTRICTION_TYPE_ALL_INCOMING | 0 | 限制所有呼入 |  
| RESTRICTION_TYPE_ALL_OUTGOING | 1 | 限制所有呼出 |  
| RESTRICTION_TYPE_INTERNATIONAL | 2 | 限制国际通话 |  
| RESTRICTION_TYPE_INTERNATIONAL_EXCLUDING_HOME | 3 | 限制除归属国以外的国际通话 |  
| RESTRICTION_TYPE_ROAMING_INCOMING | 4 | 限制漫游呼入 |  
| RESTRICTION_TYPE_ALL_CALLS | 5 | 限制所有通话 |  
| RESTRICTION_TYPE_OUTGOING_SERVICES | 6 | 限制传出业务 |  
| RESTRICTION_TYPE_INCOMING_SERVICES | 7 | 限制呼入业务  |  
    
## CallTransferInfo<sup>(8+)</sup>    
呼叫转移信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| transferNum<sup>(8+)</sup> | string | false | true | 转移编号 |  
| type<sup>(8+)</sup> | CallTransferType | false | true | 呼叫转移类型 |  
| settingType<sup>(8+)</sup> | CallTransferSettingType | false | true | 设置呼叫转移类型 |  
| startHour<sup>(9+)</sup> | number | false | false | 开始时间的小时数 |  
| startMinute<sup>(9+)</sup> | number | false | false | 开始时间的分钟数 |  
| endHour<sup>(9+)</sup> | number | false | false | 结束时间的分钟数 |  
| endMinute<sup>(9+)</sup> | number | false | false | 结束时间的分钟数 |  
    
## CallTransferType<sup>(8+)</sup>    
呼叫转移类型。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TRANSFER_TYPE_UNCONDITIONAL | 0 | 无条件转移 |  
| TRANSFER_TYPE_BUSY | 1 | 忙线转移  |  
| TRANSFER_TYPE_NO_REPLY | 2 | 无回复转移 |  
| TRANSFER_TYPE_NOT_REACHABLE | 3 | 无法访问转移 |  
    
## CallTransferSettingType<sup>(8+)</sup>    
设置呼叫转移类型。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CALL_TRANSFER_DISABLE | 0 | 禁用呼叫转移 |  
| CALL_TRANSFER_ENABLE | 1 | 启用呼叫转移 |  
| CALL_TRANSFER_REGISTRATION | 3 | 登记呼叫转移 |  
| CALL_TRANSFER_ERASURE | 4 | 消除呼叫转移 |  
    
## CallAttributeOptions<sup>(7+)</sup>    
调用属性选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| accountNumber<sup>(7+)</sup> | string | false | true | 帐号号码 |  
| speakerphoneOn<sup>(7+)</sup> | boolean | false | true | 扬声器接通电话 |  
| accountId<sup>(7+)</sup> | number | false | true | 帐户Id |  
| videoState<sup>(7+)</sup> | VideoStateType | false | true | 视频状态类型 |  
| startTime<sup>(7+)</sup> | number | false | true | 开始时间 |  
| isEcc<sup>(7+)</sup> | boolean | false | true | 是否是Ecc |  
| callType<sup>(7+)</sup> | CallType | false | true | 通话类型 |  
| callId<sup>(7+)</sup> | number | false | true | 呼叫Id |  
| callState<sup>(7+)</sup> | DetailedCallState | false | true | 详细呼叫状态 |  
| conferenceState<sup>(7+)</sup> | ConferenceState | false | true | 会议状态 |  
    
## ConferenceState<sup>(7+)</sup>    
会议状态。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TEL_CONFERENCE_IDLE | 0 | 电话会议空闲 |  
| TEL_CONFERENCE_ACTIVE | 1 | 电话会议激活 |  
| TEL_CONFERENCE_DISCONNECTING | 2 | 电话会议断开 |  
| TEL_CONFERENCE_DISCONNECTED | 3 | 电话会议已断开 |  
    
## CallType<sup>(7+)</sup>    
通话类型。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_CS | 0 | CS通话  |  
| TYPE_IMS | 1 | IMS通话 |  
| TYPE_OTT | 2 | OTT通话 |  
| TYPE_ERR_CALL | 3 | 其他类型通话 |  
    
## VideoStateType<sup>(7+)</sup>    
视频状态类型。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_VOICE | 0 | 语音状态 |  
| TYPE_VIDEO | 1 | 视频状态 |  
    
## DetailedCallState<sup>(7+)</sup>    
详细的呼叫状态。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CALL_STATUS_ACTIVE | 0 | 激活呼叫状态 |  
| CALL_STATUS_HOLDING | 1 | 保持呼叫状态 |  
| CALL_STATUS_DIALING | 2 | 呼叫状态拨号 |  
| CALL_STATUS_ALERTING | 3 | 电话报警状态 |  
| CALL_STATUS_INCOMING | 4 | 呼叫传入状态 |  
| CALL_STATUS_WAITING | 5 |  呼叫等待状态 |  
| CALL_STATUS_DISCONNECTED | 6 | 呼叫状态已断开 |  
| CALL_STATUS_DISCONNECTING | 7 | 呼叫状态断开 |  
| CALL_STATUS_IDLE | 8 | 呼叫状态空闲 |  
    
## CallRestrictionInfo<sup>(8+)</sup>    
呼叫限制信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type<sup>(8+)</sup> | CallRestrictionType | false | true | 呼叫限制类型 |  
| password<sup>(8+)</sup> | string | false | true |  密码 |  
| mode<sup>(8+)</sup> | CallRestrictionMode | false | true | 呼叫限制模式 |  
    
## CallRestrictionMode<sup>(8+)</sup>    
呼叫限制模式。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| RESTRICTION_MODE_DEACTIVATION | 0 |  限制模式停用 |  
| RESTRICTION_MODE_ACTIVATION | 1 | 限制模式激活 |  
    
## CallEventOptions<sup>(8+)</sup>    
呼叫事件的可选参数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| eventId<sup>(8+)</sup> | CallAbilityEventId | false | true | 呼叫能力事件Id |  
    
## CallAbilityEventId<sup>(8+)</sup>    
呼叫能力事件Id。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| EVENT_DIAL_NO_CARRIER | 1 | 拨号无载波事件 |  
| EVENT_INVALID_FDN_NUMBER | 2 | 无效的FDN号事件 |  
| EVENT_HOLD_CALL_FAILED<sup>(11+)</sup> | 3 | 保持通话失败事件 |  
| EVENT_SWAP_CALL_FAILED<sup>(11+)</sup> | 4 | 保持当前通话并接听等待中电话失败事件 |  
| EVENT_COMBINE_CALL_FAILED<sup>(11+)</sup> | 5 | 合并通话失败 |  
| EVENT_SPLIT_CALL_FAILED<sup>(11+)</sup> | 6 | 分离通话失败 |  
    
## DialOptions    
拨打电话的可选参数。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| accountId<sup>(8+)</sup> | number | false | false | 帐户Id。<br/>- 0：卡槽1<br/>- 1：卡槽2<br/>。此接口为系统接口。 |  
| videoState<sup>(8+)</sup> | VideoStateType | false | false | 视频状态类型。此接口为系统接口。  |  
| dialScene<sup>(8+)</sup> | DialScene | false | false | 拨号场景。此接口为系统接口。 |  
| dialType<sup>(8+)</sup> | DialType | false | false | 拨号类型。此接口为系统接口。 |  
    
## DialCallOptions<sup>(9+)</sup>    
拨打电话的可选参数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| accountId<sup>(9+)</sup> | number | false | false | 帐户Id。<br/>- 0：卡槽1<br/>- 1：卡槽2<br/>。 |  
| videoState<sup>(9+)</sup> | VideoStateType | false | false | 视频状态类型。 |  
| dialScene<sup>(9+)</sup> | DialScene | false | false | 拨号场景。  |  
| dialType<sup>(9+)</sup> | DialType | false | false | 拨号类型。  |  
    
## DialScene<sup>(8+)</sup>    
拨号场景。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CALL_NORMAL | 0 | 呼叫正常 |  
| CALL_PRIVILEGED | 1 | 呼叫特权   |  
| CALL_EMERGENCY | 2 | 拨打紧急电话 |  
    
## DialType<sup>(8+)</sup>    
拨号类型。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DIAL_CARRIER_TYPE | 0 | 载波拨号类型   |  
| DIAL_VOICE_MAIL_TYPE | 1 | 语音邮件拨号类型  |  
| DIAL_OTT_TYPE | 2 | OTT拨号类型 |  
    
## RejectMessageOptions<sup>(7+)</sup>    
拒绝消息可选参数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| messageContent<sup>(7+)</sup> | string | false | true | 消息内容 |  
    
## CallTransferResult<sup>(8+)</sup>    
呼叫转移结果。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| status<sup>(8+)</sup> | TransferStatus | false | true | 转移状态   |  
| number<sup>(8+)</sup> | string | false | true | 号码    |  
| startHour<sup>(9+)</sup> | number | false | true | 开始时间的小时数 |  
| startMinute<sup>(9+)</sup> | number | false | true | 开始时间的分钟数 |  
| endHour<sup>(9+)</sup> | number | false | true | 结束时间的分钟数 |  
| endMinute<sup>(9+)</sup> | number | false | true | 结束时间的分钟数 |  
    
## CallWaitingStatus<sup>(7+)</sup>    
呼叫等待状态。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CALL_WAITING_DISABLE | 0 | 禁用呼叫等待 |  
| CALL_WAITING_ENABLE | 1 | 启用呼叫等待  |  
    
## RestrictionStatus<sup>(8+)</sup>    
限制状态。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| RESTRICTION_DISABLE | 0 | 禁用限制  |  
| RESTRICTION_ENABLE | 1 | 启用限制  |  
    
## TransferStatus<sup>(8+)</sup>    
转移状态。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TRANSFER_DISABLE | 0 | 禁用转移 |  
| TRANSFER_ENABLE | 1 | 启用转移 |  
    
## MmiCodeResults<sup>(9+)</sup>    
MMI码结果。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| result<sup>(9+)</sup> | MmiCodeResult | false | true | MMI码结果 |  
| message<sup>(9+)</sup> | string | false | true | MMI码消息 |  
    
## MmiCodeResult<sup>(9+)</sup>    
MMI码结果。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MMI_CODE_SUCCESS | 0 | 表示MMI码成功 |  
| MMI_CODE_FAILED | 1 | 表示MMI码失败 |  
    
## DisconnectedReason<sup>(8+)</sup>    
断开连接的详细信息。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNASSIGNED_NUMBER | 1 | 未分配的号码(空号)  |  
| NO_ROUTE_TO_DESTINATION | 3 | 无至目的地的路由 |  
| CHANNEL_UNACCEPTABLE | 6 | 不可接受的通路 |  
| OPERATOR_DETERMINED_BARRING | 8 | 运营商闭锁  |  
| CALL_COMPLETED_ELSEWHERE<sup>(9+)</sup> | 13 | 呼叫在其他地方完成 |  
| NORMAL_CALL_CLEARING | 16 | 清除正常呼叫 |  
| USER_BUSY | 17 | 用户忙 |  
| NO_USER_RESPONDING | 18 | 无用户响应 |  
| USER_ALERTING_NO_ANSWER | 19 | 已有用户提醒，但无应答  |  
| CALL_REJECTED | 21 | 呼叫拒绝 |  
| NUMBER_CHANGED | 22 | 号码改变 |  
| CALL_REJECTED_DUE_TO_FEATURE_AT_THE_DESTINATION<sup>(9+)</sup> | 24 | 当由于目标地址（例如匿名）导致呼叫被拒绝 |  
| FAILED_PRE_EMPTION<sup>(9+)</sup> | 25 | 抢占失败  |  
| NON_SELECTED_USER_CLEARING<sup>(9+)</sup> | 26 | 非选定用户清除  |  
| DESTINATION_OUT_OF_ORDER | 27 | 终点故障 |  
| INVALID_NUMBER_FORMAT | 28 | 无效号码格式 |  
| FACILITY_REJECTED<sup>(9+)</sup> | 29 | 增补业务拒绝    |  
| RESPONSE_TO_STATUS_ENQUIRY<sup>(9+)</sup> | 30 | 对状态查询的响应 |  
| NORMAL_UNSPECIFIED<sup>(9+)</sup> | 31 | 正常，未指定  |  
| NO_CIRCUIT_CHANNEL_AVAILABLE<sup>(9+)</sup> | 34 | 无电路/通道可用  |  
| NETWORK_OUT_OF_ORDER | 38 | 网络故障 |  
| TEMPORARY_FAILURE | 41 | 临时故障 |  
| SWITCHING_EQUIPMENT_CONGESTION<sup>(9+)</sup> | 42 | 交换设备拥塞 |  
| ACCESS_INFORMATION_DISCARDED<sup>(9+)</sup> | 43 | 已丢弃访问信息 |  
| REQUEST_CIRCUIT_CHANNEL_NOT_AVAILABLE<sup>(9+)</sup> | 44 | 请求的电路/通道不可用  |  
| RESOURCES_UNAVAILABLE_UNSPECIFIED<sup>(9+)</sup> | 47 | 未指定资源不可用  |  
| QUALITY_OF_SERVICE_UNAVAILABLE<sup>(9+)</sup> | 49 | 服务质量不可用  |  
| REQUESTED_FACILITY_NOT_SUBSCRIBED<sup>(9+)</sup> | 50 | 请求的设施未订阅  |  
| INCOMING_CALLS_BARRED_WITHIN_THE_CUG<sup>(9+)</sup> | 55 | CUG内禁止来电   |  
| BEARER_CAPABILITY_NOT_AUTHORIZED<sup>(9+)</sup> | 57 | 未授权承载能力 |  
| BEARER_CAPABILITY_NOT_PRESENTLY_AVAILABLE<sup>(9+)</sup> | 58 | 承载能力目前不可用  |  
| SERVICE_OR_OPTION_NOT_AVAILABLE_UNSPECIFIED<sup>(9+)</sup> | 63 |  服务或选项不可用，未指定 |  
| BEARER_SERVICE_NOT_IMPLEMENTED<sup>(9+)</sup> | 65 | 未实现承载服务 |  
| ACM_EQUALTO_OR_GREATER_THAN_THE_MAXIMUM_VALUE<sup>(9+)</sup> | 68 | ACM大于或等于最大值  |  
| REQUESTED_FACILITY_NOT_IMPLEMENTED<sup>(9+)</sup> | 69 | 请求的设施未实施   |  
| ONLY_RESTRICTED_DIGITAL_INFO_BEARER_CAPABILITY_IS_AVAILABLE<sup>(9+)</sup> | 70 | 仅限BC有限数字信息可用 |  
| SERVICE_OR_OPTION_NOT_IMPLEMENTED_UNSPECIFIED<sup>(9+)</sup> | 79 | 服务或选项未实施，未指定 |  
| INVALID_TRANSACTION_IDENTIFIER_VALUE<sup>(9+)</sup> | 81 | 无效的业务标识符值  |  
| USER_NOT_MEMBER_OF_CUG<sup>(9+)</sup> | 87 | 用户不是CUG成员  |  
| INCOMPATIBLE_DESTINATION<sup>(9+)</sup> | 88 | 目标不兼容  |  
| INVALID_TRANSIT_NETWORK_SELECTION<sup>(9+)</sup> | 91 | 选择的传输网络无效 |  
| SEMANTICALLY_INCORRECT_MESSAGE<sup>(9+)</sup> | 95 | 语义错误的消息 |  
| INVALID_MANDATORY_INFORMATION<sup>(9+)</sup> | 96 | 无效的强制信息 |  
| MESSAGE_TYPE_NON_EXISTENT_OR_NOT_IMPLEMENTED<sup>(9+)</sup> | 97 | 消息类型不存在或未实现 |  
| MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE<sup>(9+)</sup> | 98 | 消息类型与协议状态不兼容 |  
| INFORMATION_ELEMENT_NON_EXISTENT_OR_NOT_IMPLEMENTED<sup>(9+)</sup> | 99 | IE不存在或未实现 |  
| CONDITIONAL_IE_ERROR<sup>(9+)</sup> | 100 | 条件IE错误 |  
| MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE<sup>(9+)</sup> | 101 | 消息与协议状态不兼容 |  
| RECOVERY_ON_TIMER_EXPIRED<sup>(9+)</sup> | 102 | 计时器过期时恢复计时器编号  |  
| PROTOCOL_ERROR_UNSPECIFIED<sup>(9+)</sup> | 111 | 协议错误，未指定 |  
| INTERWORKING_UNSPECIFIED<sup>(9+)</sup> | 127 | 互通，未指定  |  
| CALL_BARRED<sup>(9+)</sup> | 240 | 呼叫被禁止 |  
| FDN_BLOCKED<sup>(9+)</sup> | 241 | FDN受阻 |  
| IMSI_UNKNOWN_IN_VLR<sup>(9+)</sup> | 242 | VLR中的IMSI未知 |  
| IMEI_NOT_ACCEPTED<sup>(9+)</sup> | 243 | IMEI未被接受  |  
| DIAL_MODIFIED_TO_USSD<sup>(9+)</sup> | 244 | 拨号修改为USSD  |  
| DIAL_MODIFIED_TO_SS<sup>(9+)</sup> | 245 | 拨号修改为USSD号  |  
| DIAL_MODIFIED_TO_DIAL<sup>(9+)</sup> | 246 | 拨号已修改为正常 |  
| RADIO_OFF<sup>(9+)</sup> | 247 | 无线电通讯已关闭  |  
| OUT_OF_SERVICE<sup>(9+)</sup> | 248 | 停止服务 |  
| NO_VALID_SIM<sup>(9+)</sup> | 249 |  SIM卡无效 |  
| RADIO_INTERNAL_ERROR<sup>(9+)</sup> | 250 | 无线电通讯内部错误  |  
| NETWORK_RESP_TIMEOUT<sup>(9+)</sup> | 251 | 网络响应超时  |  
| NETWORK_REJECT<sup>(9+)</sup> | 252 | 网络拒绝  |  
| RADIO_ACCESS_FAILURE<sup>(9+)</sup> | 253 | 无线电接入故障  |  
| RADIO_LINK_FAILURE<sup>(9+)</sup> | 254 | 无线电链路故障  |  
| RADIO_LINK_LOST<sup>(9+)</sup> | 255 | 无线电链路丢失  |  
| RADIO_UPLINK_FAILURE<sup>(9+)</sup> | 256 | 无线电上行链路故障  |  
| RADIO_SETUP_FAILURE<sup>(9+)</sup> | 257 | 无线电通讯设置失败    |  
| RADIO_RELEASE_NORMAL<sup>(9+)</sup> | 258 | 无线电释放正常   |  
| RADIO_RELEASE_ABNORMAL<sup>(9+)</sup> | 259 | 无线电释放异常 |  
| ACCESS_CLASS_BLOCKED<sup>(9+)</sup> | 260 | 访问类被阻止  |  
| NETWORK_DETACH<sup>(9+)</sup> | 261 | 网络分离 |  
| INVALID_PARAMETER | 1025 | 无效参数 |  
| SIM_NOT_EXIT | 1026 | SIM卡未退出   |  
| SIM_PIN_NEED | 1027 | 需要SIM卡PIN码    |  
| CALL_NOT_ALLOW | 1029 | 不允许呼叫  |  
| SIM_INVALID | 1045 |  SIM卡无效    |  
| UNKNOWN | 1279 | 未知原因   |  
    
## DisconnectedDetails<sup>(9+)</sup>    
通话结束原因。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| reason<sup>(9+)</sup> | DisconnectedReason | false | true | 通话结束原因。 |  
| message<sup>(9+)</sup> | string | false | true | 通话结束提示信息。 |  
