# @ohos.telephony.call    
该模块提供呼叫管理功能，包括拨打电话、跳转到拨号界面、获取通话状态、格式化电话号码等。  
  
如需订阅通话状态请使用[`observer.on('callStateChange')`](js-apis-observer.md#observeroncallstatechange)。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import call from '@ohos.telephony.call'    
```  
    
## dial<sup>(deprecated)</sup>    
拨打电话，可设置通话参数。使用callback异步回调。  
 **调用形式：**     
- dial(phoneNumber: string, options: DialOptions, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: telephony.call#dialCall。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.PLACE_CALL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| phoneNumber<sup>(deprecated)</sup> | string | true | 电话号码。 |  
| options<sup>(deprecated)</sup> | DialOptions | true | 通话参数，选择为语音通话还是视频通话。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数，返回true为成功，false为失败。 |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let dialOptions: call.DialOptions = {  
    extras: false  
}  
call.dial("138xxxxxxxx", dialOptions, (err: BusinessError, data: boolean) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
## dial<sup>(deprecated)</sup>    
拨打电话，可设置通话参数。使用Promise异步回调。  
 **调用形式：**     
- dial(phoneNumber: string, options?: DialOptions): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: telephony.call#dialCall。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.PLACE_CALL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| phoneNumber<sup>(deprecated)</sup> | string | true | 电话号码。 |  
| options<sup>(deprecated)</sup> | DialOptions | false | 通话参数，选择为语音通话还是视频通话。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 以Promise形式返回拨打电话的结果，返回true为成功，false为失败。 |  
    
 **示例代码：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let dialOptions: call.DialOptions = {  
    extras: false  
}  
call.dial("138xxxxxxxx", dialOptions).then((data: boolean) => {  
    console.log(`dial success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`dial fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## dial<sup>(deprecated)</sup>    
拨打电话。使用callback异步回调。  
 **调用形式：**     
- dial(phoneNumber: string, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: telephony.call#dialCall。  
 **系统能力:**  SystemCapability.Telephony.CallManager  
 **需要权限：** ohos.permission.PLACE_CALL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| phoneNumber<sup>(deprecated)</sup> | string | true | 电话号码。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数，返回true为成功，false为失败。 |  
    
 **示例代码：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.dial("138xxxxxxxx", (err: BusinessError, data: boolean) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
## makeCall<sup>(7+)</sup>    
跳转到拨号界面，并显示待拨出的号码。  
 **调用形式：**     
    
- makeCall(phoneNumber: string, callback: AsyncCallback\<void>): void    
起始版本： 7    
- makeCall(phoneNumber: string): Promise\<void>    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Applications.Contacts    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| phoneNumber | string | true | 电话号码。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以callback形式异步返回跳转拨号界面的结果。 |  
| Promise<void> | 以Promise形式异步返回拨号的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.makeCall("138xxxxxxxx", (err: BusinessError) => {  
    console.log(`makeCall callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.makeCall("138xxxxxxxx").then(() => {  
    console.log(`makeCall success`);  
}).catch((err: BusinessError) => {  
    console.error(`makeCall fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## hasCall    
判断是否存在通话。  
 **调用形式：**     
    
- hasCall(callback: AsyncCallback\<boolean>): void    
起始版本： 6    
- hasCall(): Promise\<boolean>    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示当前存在通话，false表示当前不存在通话。 |  
| Promise<boolean> | 以Promise形式异步返回判断是否存在通话。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.hasCall((err: BusinessError, data: boolean) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.hasCall().then(() => {  
    console.log(`hasCall success`);  
}).catch((err: BusinessError) => {  
    console.error(`hasCall fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## hasCallSync<sup>(10+)</sup>    
判断是否存在通话。  
 **调用形式：**     
- hasCallSync(): boolean  
  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回判断是否存在通话。 |  
    
 **示例代码：**   
```ts    
let hasCall: boolean = call.hasCallSync();console.log(`hasCallSync success, has call is ` + hasCall);    
```    
  
    
## getCallState    
获取当前通话状态。  
 **调用形式：**     
    
- getCallState(callback: AsyncCallback\<CallState>): void    
起始版本： 6    
- getCallState(): Promise\<CallState>    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回获取到的通话状态。 |  
| Promise<CallState> | 以Promise形式异步返回获取到的通话状态。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.getCallState((err: BusinessError, data: call.CallState) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.getCallState().then((data: call.CallState) => {  
    console.log(`getCallState success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getCallState fail, promise: err->${JSON.stringify(err)}`);  
});<i></i><span style="font-size: 14px; letter-spacing: 0px;"></span>  
    
```    
  
    
## getCallStateSync<sup>(10+)</sup>    
获取当前通话状态。  
 **调用形式：**     
- getCallStateSync(): CallState  
  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| CallState | 返回获取到的通话状态。 |  
    
 **示例代码：**   
```ts    
let callState: call.CallState = call.getCallStateSync();console.log(`the call state is:` + callState);    
```    
  
    
## hasVoiceCapability<sup>(7+)</sup>    
检查当前设备是否具备语音通话能力。  
 **调用形式：**     
- hasVoiceCapability(): boolean  
  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示设备具备语音通话能力，返回false表示设备不具备语音通话能力。 |  
    
 **示例代码：**   
```ts    
let result: boolean = call.hasVoiceCapability();console.log(`hasVoiceCapability: ${JSON.stringify(result)}`);    
```    
  
    
## isEmergencyPhoneNumber<sup>(7+)</sup>    
根据电话号码参数，判断是否是紧急电话号码。  
 **调用形式：**     
    
- isEmergencyPhoneNumber(phoneNumber: string, options: EmergencyNumberOptions, callback: AsyncCallback\<boolean>): void    
起始版本： 7    
- isEmergencyPhoneNumber(phoneNumber: string, options?: EmergencyNumberOptions): Promise\<boolean>    
起始版本： 7    
- isEmergencyPhoneNumber(phoneNumber: string, callback: AsyncCallback\<boolean>): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| phoneNumber | string | true | 电话号码。 |  
| options | EmergencyNumberOptions | true | 电话号码参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示是紧急电话号码，返回false表示不是紧急电话号码。 |  
| Promise<boolean> | 以Promise形式异步返回判断是否是紧急电话号码的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let options: call.EmergencyNumberOptions = {slotId: 1}  
call.isEmergencyPhoneNumber("112", options, (err: BusinessError, data: boolean) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let options: call.EmergencyNumberOptions = {slotId: 1}  
call.isEmergencyPhoneNumber("138xxxxxxxx", options).then((data: boolean) => {  
    console.log(`isEmergencyPhoneNumber success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`isEmergencyPhoneNumber fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## formatPhoneNumber<sup>(7+)</sup>    
格式化电话号码，可设置格式化参数。  
 **调用形式：**     
    
- formatPhoneNumber(phoneNumber: string, options: NumberFormatOptions, callback: AsyncCallback\<string>): void    
起始版本： 7    
- formatPhoneNumber(phoneNumber: string, options?: NumberFormatOptions): Promise\<string>    
起始版本： 7    
- formatPhoneNumber(phoneNumber: string, callback: AsyncCallback\<string>): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| phoneNumber | string | true | 电话号码。 |  
| options | NumberFormatOptions | true | 格式化参数，如国家码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回格式化电话号码的结果。 |  
| Promise<string> | 以Promise形式异步返回格式化电话号码的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let options: call.NumberFormatOptions = {  
    countryCode: "CN"  
}  
call.formatPhoneNumber("138xxxxxxxx", options, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
let options: call.NumberFormatOptions = {  
    countryCode: "CN"  
}  
call.formatPhoneNumber("138xxxxxxxx", options).then((data: string) => {  
    console.log(`formatPhoneNumber success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`formatPhoneNumber fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## formatPhoneNumberToE164<sup>(7+)</sup>    
将电话号码格式化为E.164表示形式。  
 **调用形式：**     
    
- formatPhoneNumberToE164(phoneNumber: string, countryCode: string, callback: AsyncCallback\<string>): void    
起始版本： 7    
- formatPhoneNumberToE164(phoneNumber: string, countryCode: string): Promise\<string>    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CallManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| phoneNumber | string | true | 电话号码。   |  
| countryCode | string | true | 国家码，支持所有国家码，如：中国（CN）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 国家码，支持所有国家码，如：中国（CN）。 |  
| Promise<string> | 以Promise形式异步返回将电话号码格式化为E.164表示形式的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.formatPhoneNumberToE164("138xxxxxxxx", "CN", (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
  
call.formatPhoneNumberToE164("138xxxxxxxx", "CN").then((data: string) => {  
    console.log(`formatPhoneNumberToE164 success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`formatPhoneNumberToE164 fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## CallState    
通话状态码。    
    
 **系统能力:**  SystemCapability.Telephony.CallManager    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CALL_STATE_UNKNOWN | -1 | 无效状态，当获取呼叫状态失败时返回。 |  
| CALL_STATE_IDLE | 0 | 表示没有正在进行的呼叫 |  
| CALL_STATE_RINGING | 1 | 表示来电正在振铃或等待。 |  
| CALL_STATE_OFFHOOK | 2 | 表示至少有一个呼叫处于拨号、通话中或呼叫保持状态，并且没有新的来电振铃或等待。 |  
    
## DialOptions    
拨打电话的可选参数。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CallManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| extras | boolean | false | false | 根据extras的值判断是否为视频通话，默认为语音通话。<br/>- true：视频通话。<br/>- false：语音通话。 |  
    
## EmergencyNumberOptions<sup>(7+)</sup>    
判断是否是紧急电话号码的可选参数。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CallManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| slotId<sup>(7+)</sup> | number | false | false | 卡槽ID：<br/>- 卡槽1：`0`。<br/>- 卡槽2：`1`。 |  
    
## NumberFormatOptions<sup>(7+)</sup>    
格式化号码的可选参数。  
 **系统能力:**  SystemCapability.Telephony.CallManager    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CallManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| countryCode<sup>(7+)</sup> | string | false | false | 国家码，支持所有国家的国家码，如：CN（中国）。默认为：CN。 |  
