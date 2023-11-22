# @ohos.telephony.sms    
短信服务提供了管理短信的一些基础能力，包括创建、发送短信，获取、设置发送短信的默认SIM卡槽ID，获取、设置短信服务中心（SMSC）地址，以及检查当前设备是否具备短信发送和接收能力等。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import sms from '@ohos.telephony.sms'    
```  
    
## splitMessage<sup>(8+)</sup>    
将长短信拆分为多个片段。  
 **调用形式：**     
    
- splitMessage(content: string, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 8    
- splitMessage(content: string): Promise\<Array\<string>>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms  
 **需要权限：** ohos.permission.SEND_MESSAGES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| content | string | true | 指示短消息内容，不能为null。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<Array<string>> | 以Promise形式返回多个片段的的结果。 |  
    
    
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
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let content: string = "long message";  
sms.splitMessage(content, (err: BusinessError, data: string[]) => {  
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let content: string = "long message";  
let promise = sms.splitMessage(content);  
promise.then((data: string[]) => {  
    console.log(`splitMessage success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`splitMessage failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setDefaultSmsSlotId<sup>(7+)</sup>    
设置发送短信的默认SIM卡槽ID。  
 **调用形式：**     
    
- setDefaultSmsSlotId(slotId: number, callback: AsyncCallback\<void>): void    
起始版本： 7    
- setDefaultSmsSlotId(slotId: number): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | SIM卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2<br/>- -1：清除默认配置 |  
    
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
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
sms.setDefaultSmsSlotId(0, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}.`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
sms.setDefaultSmsSlotId(0).then(() => {  
    console.log(`setDefaultSmsSlotId success.`);  
}).catch((err: BusinessError) => {  
    console.error(`setDefaultSmsSlotId failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setSmscAddr<sup>(7+)</sup>    
设置短信服务中心（SMSC）地址。  
 **调用形式：**     
    
- setSmscAddr(slotId: number, smscAddr: string, callback: AsyncCallback\<void>): void    
起始版本： 7    
- setSmscAddr(slotId: number, smscAddr: string): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| smscAddr | string | true | 短信服务中心地址。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回设置结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs.. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let smscAddr: string = '+861xxxxxxxxxx';  
sms.setSmscAddr(slotId, smscAddr, (err: BusinessError) => {  
      console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let smscAddr: string = '+861xxxxxxxxxx';  
sms.setSmscAddr(slotId, smscAddr).then(() => {  
    console.log(`setSmscAddr success.`);  
}).catch((err: BusinessError) => {  
    console.error(`setSmscAddr failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getSmscAddr<sup>(7+)</sup>    
获取短信服务中心（SMSC）地址。  
 **调用形式：**     
    
- getSmscAddr(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 7    
- getSmscAddr(slotId: number): Promise\<string>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<string> | 以Promise形式返回获取短信服务中心地址的结果。 |  
    
    
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
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
sms.getSmscAddr(slotId, (err: BusinessError, data: string) => {  
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
sms.getSmscAddr(slotId).then((data: string) => {  
    console.log(`getSmscAddr success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getSmscAddr failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## addSimMessage<sup>(7+)</sup>    
添加SIM卡消息。  
 **调用形式：**     
    
- addSimMessage(options: SimMessageOptions, callback: AsyncCallback\<void>): void    
起始版本： 7    
- addSimMessage(options: SimMessageOptions): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms  
 **需要权限：** ohos.permission.RECEIVE_SMS and ohos.permission.SEND_MESSAGES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | SimMessageOptions | true | SIM卡消息选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式返回添加的结果。 |  
    
    
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
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let simMessageOptions: sms.SimMessageOptions = {  
    slotId: 0,  
    smsc: "test",  
    pdu: "xxxxxx",  
    status: sms.SimMessageStatus.SIM_MESSAGE_STATUS_READ  
};  
sms.addSimMessage(simMessageOptions, (err: BusinessError) => {  
      console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let simMessageOptions: sms.SimMessageOptions = {  
    slotId: 0,  
    smsc: "test",  
    pdu: "xxxxxx",  
    status: sms.SimMessageStatus.SIM_MESSAGE_STATUS_READ  
};  
sms.addSimMessage(simMessageOptions).then(() => {  
    console.log(`addSimMessage success.`);  
}).catch((err: BusinessError) => {  
    console.error(`addSimMessage failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## delSimMessage<sup>(7+)</sup>    
删除SIM卡消息。  
 **调用形式：**     
    
- delSimMessage(slotId: number, msgIndex: number, callback: AsyncCallback\<void>): void    
起始版本： 7    
- delSimMessage(slotId: number, msgIndex: number): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms  
 **需要权限：** ohos.permission.RECEIVE_SMS and ohos.permission.SEND_MESSAGES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| msgIndex | number | true | 消息索引。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式返回删除的结果。 |  
    
    
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
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let msgIndex: number = 1;  
sms.delSimMessage(slotId, msgIndex, (err: BusinessError) => {  
      console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let msgIndex: number = 1;  
let promise = sms.delSimMessage(slotId, msgIndex);  
promise.then(() => {  
    console.log(`delSimMessage success.`);  
}).catch((err: BusinessError) => {  
    console.error(`delSimMessage failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## updateSimMessage<sup>(7+)</sup>    
更新SIM卡消息。  
 **调用形式：**     
    
- updateSimMessage(options: UpdateSimMessageOptions, callback: AsyncCallback\<void>): void    
起始版本： 7    
- updateSimMessage(options: UpdateSimMessageOptions): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms  
 **需要权限：** ohos.permission.RECEIVE_SMS and ohos.permission.SEND_MESSAGES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | UpdateSimMessageOptions | true | 更新SIM卡消息选项。 |  
    
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
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let updateSimMessageOptions: sms.UpdateSimMessageOptions = {  
    slotId: 0,  
    msgIndex: 1,  
    newStatus: sms.SimMessageStatus.SIM_MESSAGE_STATUS_FREE,  
    pdu: "xxxxxxx",  
    smsc: "test"  
};  
sms.updateSimMessage(updateSimMessageOptions, (err: BusinessError) => {  
      console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let updateSimMessageOptions: sms.UpdateSimMessageOptions = {  
    slotId: 0,  
    msgIndex: 1,  
    newStatus: sms.SimMessageStatus.SIM_MESSAGE_STATUS_FREE,  
    pdu: "xxxxxxx",  
    smsc: "test"  
};  
let promise = sms.updateSimMessage(updateSimMessageOptions);  
promise.then(() => {  
    console.log(`updateSimMessage success.`);  
}).catch((err: BusinessError) => {  
    console.error(`updateSimMessage failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getAllSimMessages<sup>(7+)</sup>    
获取所有SIM卡消息。  
 **调用形式：**     
    
- getAllSimMessages(slotId: number, callback: AsyncCallback\<Array\<SimShortMessage>>): void    
起始版本： 7    
- getAllSimMessages(slotId: number): Promise\<Array\<SimShortMessage>>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms  
 **需要权限：** ohos.permission.RECEIVE_SMS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<Array<SimShortMessage>> | 以Promise形式返回获取的SIM短消息。 |  
    
    
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
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
sms.getAllSimMessages(slotId, (err: BusinessError, data: sms.SimShortMessage[]) => {  
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let promise = sms.getAllSimMessages(slotId);  
promise.then((data: sms.SimShortMessage) => {  
    console.log(`getAllSimMessages success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getAllSimMessages failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setCBConfig<sup>(7+)</sup>    
设置小区广播配置。  
 **调用形式：**     
    
- setCBConfig(options: CBConfigOptions, callback: AsyncCallback\<void>): void    
起始版本： 7    
- setCBConfig(options: CBConfigOptions): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms  
 **需要权限：** ohos.permission.RECEIVE_SMS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | CBConfigOptions | true | 小区广播配置选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式返回设置的结果。 |  
    
    
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
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let cbConfigOptions: sms.CBConfigOptions = {  
    slotId: 0,  
    enable: true,  
    startMessageId: 100,  
    endMessageId: 200,  
    ranType: sms.RanType.TYPE_GSM  
};  
sms.setCBConfig(cbConfigOptions, (err: BusinessError) => {  
      console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let cbConfigOptions: sms.CBConfigOptions = {  
    slotId: 0,  
    enable: true,  
    startMessageId: 100,  
    endMessageId: 200,  
    ranType: sms.RanType.TYPE_GSM  
};  
let promise = sms.setCBConfig(cbConfigOptions);  
promise.then(() => {  
    console.log(`setCBConfig success.`);  
}).catch((err: BusinessError) => {  
    console.error(`setCBConfig failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getSmsSegmentsInfo<sup>(8+)</sup>    
获取短信段信息。  
 **调用形式：**     
    
- getSmsSegmentsInfo(slotId: number, message: string, force7bit: boolean, callback: AsyncCallback\<SmsSegmentsInfo>): void    
起始版本： 8    
- getSmsSegmentsInfo(slotId: number, message: string, force7bit: boolean): Promise\<SmsSegmentsInfo>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| message | string | true | 消息。 |  
| force7bit | boolean | true | 是否使用7 bit编码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<SmsSegmentsInfo> | 以Promise形式返回短信段信息。 |  
    
    
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
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
sms.getSmsSegmentsInfo(slotId, "message", false, (err: BusinessError, data: sms.SmsSegmentsInfo) => {  
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let promise = sms.getSmsSegmentsInfo(slotId, "message", false);  
promise.then((data: sms.SmsSegmentsInfo) => {  
    console.log(`getSmsSegmentsInfo success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getSmsSegmentsInfo failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## isImsSmsSupported<sup>(8+)</sup>    
如果IMS已注册并且在IMS上支持SMS，则支持通过IMS发送SMS。  
 **调用形式：**     
    
- isImsSmsSupported(slotId: number, callback: AsyncCallback\<boolean>): void    
起始版本： 8    
- isImsSmsSupported(slotId: number): Promise\<boolean>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<boolean> | 以Promise形式返回结果。 |  
    
    
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
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
sms.isImsSmsSupported(slotId, (err: BusinessError, data: boolean) => {  
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let promise = sms.isImsSmsSupported(slotId);  
promise.then((data: boolean) => {  
    console.log(`isImsSmsSupported success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`isImsSmsSupported failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getImsShortMessageFormat<sup>(8+)</sup>    
获取IMS上支持的SMS格式。  
 **调用形式：**     
    
- getImsShortMessageFormat(callback: AsyncCallback\<string>): void    
起始版本： 8    
- getImsShortMessageFormat(): Promise\<string>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<string> | 以Promise形式返回SMS格式。 |  
    
    
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
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
sms.getImsShortMessageFormat((err: BusinessError, data: string) => {  
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
sms.getImsShortMessageFormat().then((data: string) => {  
    console.log(`getImsShortMessageFormat success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getImsShortMessageFormat failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## decodeMms<sup>(8+)</sup>    
彩信解码。  
 **调用形式：**     
    
- decodeMms(mmsFilePathName: string | Array\<number>, callback: AsyncCallback\<MmsInformation>): void    
起始版本： 8    
- decodeMms(mmsFilePathName: string | Array\<number>): Promise\<MmsInformation>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mmsFilePathName | string | true | 彩信文件路径名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<MmsInformation> | 以Promise形式返回彩信信息。 |  
    
    
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
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let mmsFilePathName: string = "filename";  
sms.decodeMms(mmsFilePathName, (err: BusinessError, data: sms.MmsInformation) => {  
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let mmsFilePathName: string = "filename";  
let promise = sms.decodeMms(mmsFilePathName);  
promise.then((data: sms.MmsInformation) => {  
    console.log(`decodeMms success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`decodeMms failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## encodeMms<sup>(8+)</sup>    
彩信编码。  
 **调用形式：**     
    
- encodeMms(mms: MmsInformation, callback: AsyncCallback\<Array\<number>>): void    
起始版本： 8    
- encodeMms(mms: MmsInformation): Promise\<Array\<number>>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mms | MmsInformation | true | 彩信信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<Array<number>> | 以Promise形式返回彩信编码后的结果。 |  
    
    
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
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let mmsAcknowledgeInd: sms.MmsAcknowledgeInd = {  
    transactionId: "100",  
    version: sms.MmsVersionType.MMS_VERSION_1_0,  
    reportAllowed: sms.ReportType.MMS_YES  
};  
let mmsInformation: sms.MmsInformation = {  
    messageType: sms.MessageType.TYPE_MMS_ACKNOWLEDGE_IND,  
    mmsType: mmsAcknowledgeInd  
};  
sms.encodeMms(mmsInformation, (err: BusinessError, data: number[]) => {  
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let mmsAcknowledgeInd: sms.MmsAcknowledgeInd = {  
    transactionId: "100",  
    version: sms.MmsVersionType.MMS_VERSION_1_0,  
    reportAllowed: sms.ReportType.MMS_YES  
};  
let mmsInformation: sms.MmsInformation = {  
    messageType: sms.MessageType.TYPE_MMS_ACKNOWLEDGE_IND,  
    mmsType: mmsAcknowledgeInd  
};  
sms.encodeMms(mmsInformation).then((data: number[]) => {  
    console.log(`encodeMms success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`encodeMms failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## MmsInformation<sup>(8+)</sup>    
彩信信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| messageType<sup>(8+)</sup> | MessageType | false | true | 消息类型。 |  
| mmsType<sup>(8+)</sup> | MmsSendReq \| MmsSendConf \| MmsNotificationInd \| MmsRespInd \| MmsRetrieveConf \| MmsAcknowledgeInd \|MmsDeliveryInd \| MmsReadOrigInd \| MmsReadRecInd | false | true | PDU头类型 |  
| attachment<sup>(8+)</sup> | Array<MmsAttachment> | false | false | 附件 |  
    
## sendMms<sup>(11+)</sup>    
发送彩信。  
 **调用形式：**     
    
- sendMms(context: Context, mmsParams: MmsParams, callback: AsyncCallback\<void>): void    
起始版本： 11    
- sendMms(context: Context, mmsParams: MmsParams): Promise\<void>    
起始版本： 11  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms  
 **需要权限：** ohos.permission.SEND_MESSAGES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文。<br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-uiAbilityContext.md)。 |  
| mmsParams | MmsParams | true | 发送彩信的参数和回调，参考[MmsParams](#mmsparams)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式返回发送彩信的结果。 |  
    
    
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
    
## downloadMms<sup>(11+)</sup>    
下载彩信。  
 **调用形式：**     
    
- downloadMms(context: Context, mmsParams: MmsParams, callback: AsyncCallback\<void>): void    
起始版本： 11    
- downloadMms(context: Context, mmsParams: MmsParams): Promise\<void>    
起始版本： 11  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms  
 **需要权限：** ohos.permission.RECEIVE_MMS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用上下文。<br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-uiAbilityContext.md)。 |  
| mmsParams | MmsParams | true | 下载彩信的参数和回调，参考[MmsParams](#mmsparams)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式返回发送彩信的结果。 |  
    
    
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
    
## MmsParams<sup>(11+)</sup>    
发送彩信的参数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| slotId<sup>(11+)</sup> | number | false | true | 用于发送短信的SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| mmsc<sup>(11+)</sup> | string | false | true | 彩信中心地址。 |  
| data<sup>(11+)</sup> | string | false | true | 彩信PDU地址。 |  
| mmsConfig<sup>(11+)</sup> | MmsConfig | false | false | 彩信配置文件，参考[MmsConfig](#mmsconfig)。 |  
    
## MmsConfig<sup>(11+)</sup>    
彩信配置文件。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| userAgent<sup>(11+)</sup> | string | false | true | 用户代理。 |  
| userAgentProfile<sup>(11+)</sup> | string | false | true | 用户代理配置。 |  
    
## MmsSendReq<sup>(8+)</sup>    
彩信发送请求。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| from<sup>(8+)</sup> | MmsAddress | false | true | 彩信来源 |  
| transactionId<sup>(8+)</sup> | string | false | true | 事务ID |  
| contentType<sup>(8+)</sup> | string | false | true | 内容类型 |  
| version<sup>(8+)</sup> | MmsVersionType | false | true | 版本 |  
| to<sup>(8+)</sup> | Array<MmsAddress> | false | false | 发送至 |  
| date<sup>(8+)</sup> | number | false | false | 日期 |  
| cc<sup>(8+)</sup> | Array<MmsAddress> | false | false | 抄送 |  
| bcc<sup>(8+)</sup> | Array<MmsAddress> | false | false | 暗抄送 |  
| subject<sup>(8+)</sup> | string | false | false | 主题 |  
| messageClass<sup>(8+)</sup> | number | false | false | 消息类 |  
| expiry<sup>(8+)</sup> | number | false | false | 到期 |  
| priority<sup>(8+)</sup> | MmsPriorityType | false | false | 优先 |  
| senderVisibility<sup>(8+)</sup> | number | false | false | 发件人可见性 |  
| deliveryReport<sup>(8+)</sup> | number | false | false | 交付报告 |  
| readReport<sup>(8+)</sup> | number | false | false | 阅读报告 |  
    
## MmsSendConf<sup>(8+)</sup>    
彩信发送配置。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| responseState<sup>(8+)</sup> | number | false | true | 响应状态 |  
| transactionId<sup>(8+)</sup> | string | false | true | 事务ID |  
| version<sup>(8+)</sup> | MmsVersionType | false | true | 版本 |  
| messageId<sup>(8+)</sup> | string | false | false | 消息ID |  
    
## MmsNotificationInd<sup>(8+)</sup>    
彩信通知索引。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| transactionId<sup>(8+)</sup> | string | false | true | 事务ID |  
| messageClass<sup>(8+)</sup> | number | false | true | 消息类 |  
| messageSize<sup>(8+)</sup> | number | false | true | 消息大小 |  
| expiry<sup>(8+)</sup> | number | false | true | 到期 |  
| contentLocation<sup>(8+)</sup> | string | false | true | 内容位置 |  
| version<sup>(8+)</sup> | MmsVersionType | false | true | 版本 |  
| from<sup>(8+)</sup> | MmsAddress | false | false | 来源 |  
| subject<sup>(8+)</sup> | string | false | false | 主题 |  
| deliveryReport<sup>(8+)</sup> | number | false | false | 状态报告 |  
| contentClass<sup>(8+)</sup> | number | false | false | 内容类 |  
    
## MmsRespInd<sup>(8+)</sup>    
彩信回复标志。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| transactionId<sup>(8+)</sup> | string | false | true | 事件ID |  
| status<sup>(8+)</sup> | number | false | true | 状态 |  
| version<sup>(8+)</sup> | MmsVersionType | false | true | 版本 |  
| reportAllowed<sup>(8+)</sup> | ReportType | false | false | 允许报告 |  
    
## MmsRetrieveConf<sup>(8+)</sup>    
彩信检索配置。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| transactionId<sup>(8+)</sup> | string | false | true | 事务ID |  
| messageId<sup>(8+)</sup> | string | false | true | 消息ID |  
| date<sup>(8+)</sup> | number | false | true | 日期 |  
| contentType<sup>(8+)</sup> | string | false | true | 内容类型 |  
| to<sup>(8+)</sup> | Array<MmsAddress> | false | true | 发送至 |  
| version<sup>(8+)</sup> | MmsVersionType | false | true | 版本 |  
| from<sup>(8+)</sup> | MmsAddress | false | false | 来源 |  
| cc<sup>(8+)</sup> | Array<MmsAddress> | false | false | 抄送 |  
| subject<sup>(8+)</sup> | string | false | false | 主题 |  
| priority<sup>(8+)</sup> | MmsPriorityType | false | false | 优先级 |  
| deliveryReport<sup>(8+)</sup> | number | false | false | 状态报告 |  
| readReport<sup>(8+)</sup> | number | false | false | 阅读报告 |  
| retrieveStatus<sup>(8+)</sup> | number | false | false | 检索状态 |  
| retrieveText<sup>(8+)</sup> | string | false | false | 检索文本 |  
    
## MmsAcknowledgeInd<sup>(8+)</sup>    
彩信确认索引。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| transactionId<sup>(8+)</sup> | string | false | true | 事务ID |  
| version<sup>(8+)</sup> | MmsVersionType | false | true | 版本 |  
| reportAllowed<sup>(8+)</sup> | ReportType | false | false | 允许报告 |  
    
## MmsDeliveryInd<sup>(8+)</sup>    
彩信发送标识。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| messageId<sup>(8+)</sup> | string | false | true | 消息ID |  
| date<sup>(8+)</sup> | number | false | true | 日期 |  
| to<sup>(8+)</sup> | Array<MmsAddress> | false | true | 发送至 |  
| status<sup>(8+)</sup> | number | false | true | 状态 |  
| version<sup>(8+)</sup> | MmsVersionType | false | true | 版本 |  
    
## MmsReadOrigInd<sup>(8+)</sup>    
彩信读取原始索引。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| version<sup>(8+)</sup> | MmsVersionType | false | true | 版本 |  
| messageId<sup>(8+)</sup> | string | false | true | 消息ID |  
| to<sup>(8+)</sup> | Array<MmsAddress> | false | true | 发送至 |  
| from<sup>(8+)</sup> | MmsAddress | false | true | 来源 |  
| date<sup>(8+)</sup> | number | false | true | 日期 |  
| readStatus<sup>(8+)</sup> | number | false | true | 阅读状态 |  
    
## MmsReadRecInd<sup>(8+)</sup>    
彩信读取记录索引。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| version<sup>(8+)</sup> | MmsVersionType | false | true | 版本 |  
| messageId<sup>(8+)</sup> | string | false | true | 消息ID |  
| to<sup>(8+)</sup> | Array<MmsAddress> | false | true | 发送至 |  
| from<sup>(8+)</sup> | MmsAddress | false | true | 来源 |  
| readStatus<sup>(8+)</sup> | number | false | true | 阅读状态 |  
| date<sup>(8+)</sup> | number | false | false | 日期 |  
    
## MmsAttachment<sup>(8+)</sup>    
彩信附件。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| contentId<sup>(8+)</sup> | string | false | true | 内容ID |  
| contentLocation<sup>(8+)</sup> | string | false | true | 内容位置 |  
| contentDisposition<sup>(8+)</sup> | DispositionType | false | true | 内容处理 |  
| contentTransferEncoding<sup>(8+)</sup> | string | false | true | 内容传输编码 |  
| contentType<sup>(8+)</sup> | string | false | true | 内容类型 |  
| isSmil<sup>(8+)</sup> | boolean | false | true | 同步多媒体集成语言 |  
| path<sup>(8+)</sup> | string | false | false | 路径 |  
| inBuff<sup>(8+)</sup> | Array<number> | false | false | 缓冲区中 |  
| fileName<sup>(8+)</sup> | string | false | false | 文件名 |  
| charset<sup>(8+)</sup> | MmsCharSets | false | false | 字符集 |  
    
## MmsAddress<sup>(8+)</sup>    
彩信地址。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| address<sup>(8+)</sup> | string | false | true | 地址 |  
| charset<sup>(8+)</sup> | MmsCharSets | false | true | 字符集 |  
    
## MessageType<sup>(8+)</sup>    
消息类型。    
    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_MMS_SEND_REQ | 128 | 彩信发送请求类型 |  
| TYPE_MMS_SEND_CONF | 129 | 彩信发送配置类型 |  
| TYPE_MMS_NOTIFICATION_IND | 130 | 彩信通知索引类型 |  
| TYPE_MMS_RESP_IND | 131 | 彩信回复索引类型 |  
| TYPE_MMS_RETRIEVE_CONF | 132 | 彩信检索配置类型 |  
| TYPE_MMS_ACKNOWLEDGE_IND | 133 | 彩信确认索引类型 |  
| TYPE_MMS_DELIVERY_IND | 134 | 彩信传送索引类型 |  
| TYPE_MMS_READ_REC_IND | 135 | 彩信读取接收索引类型 |  
| TYPE_MMS_READ_ORIG_IND | 136 | 彩信读取原始索引类型 |  
    
## MmsPriorityType<sup>(8+)</sup>    
彩信优先级类型。    
    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MMS_LOW | 128 | 彩信优先级低 |  
| MMS_NORMAL | 129 | 彩信优先级正常 |  
| MMS_HIGH | 130 | 彩信优先级高 |  
    
## MmsVersionType<sup>(8+)</sup>    
彩信版本类型。    
    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MMS_VERSION_1_0 | 0x10 | 彩信版本1_0 |  
| MMS_VERSION_1_1 | 17 | 彩信版本1_1 |  
| MMS_VERSION_1_2 | 18 | 彩信版本1_2 |  
| MMS_VERSION_1_3 | 19 | 彩信版本1_3 |  
    
## MmsCharSets<sup>(8+)</sup>    
彩信字符集。    
    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| BIG5 | 0X07EA | BIG5格式 |  
| ISO_10646_UCS_2 | 0X03E8 | ISO_10646_UCS_2格式 |  
| ISO_8859_1 | 0X04 | <span style="letter-spacing: 0px;">ISO_8859_1格式</span>。 |  
| ISO_8859_2 | 5 | ISO_8859_2格式 |  
| ISO_8859_3 | 6 | ISO_8859_3格式 |  
| ISO_8859_4 | 7 | ISO_8859_4格式 |  
| ISO_8859_5 | 8 | ISO_8859_5格式 |  
| ISO_8859_6 | 9 | ISO_8859_6格式 |  
| ISO_8859_7 | 10 | ISO_8859_7格式 |  
| ISO_8859_8 | 11 | ISO_8859_8格式 |  
| ISO_8859_9 | 12 | ISO_8859_9格式 |  
| SHIFT_JIS | 0X11 | SHIFT_JIS格式 |  
| US_ASCII | 0X03 | US_ASCII格式 |  
| UTF_8 | 0X6A | UTF_8格式 |  
    
## DispositionType<sup>(8+)</sup>    
处理类型。    
    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FROM_DATA | 0 | 数据来源 |  
| ATTACHMENT | 1 | 附件 |  
| INLINE | 2 | 内联 |  
    
## ReportType<sup>(8+)</sup>    
报告类型。    
    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MMS_YES | 128 | YES。 |  
| MMS_NO | 129 | NO |  
    
## CBConfigOptions<sup>(7+)</sup>    
小区广播配置选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| slotId<sup>(7+)</sup> | number | false | true | 卡槽ID |  
| enable<sup>(7+)</sup> | boolean | false | true | 可行 |  
| startMessageId<sup>(7+)</sup> | number | false | true | 消息起始ID |  
| endMessageId<sup>(7+)</sup> | number | false | true | 消息结束ID |  
| ranType<sup>(7+)</sup> | RanType | false | true | 设备网络制式 |  
    
## SimMessageOptions<sup>(7+)</sup>    
SIM卡消息选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| slotId<sup>(7+)</sup> | number | false | true | 卡槽ID |  
| smsc<sup>(7+)</sup> | string | false | true | 短消息业务中心 |  
| pdu<sup>(7+)</sup> | string | false | true | 协议数据单元 |  
| status<sup>(7+)</sup> | SimMessageStatus | false | true | 状态 |  
    
## UpdateSimMessageOptions<sup>(7+)</sup>    
更新SIM卡消息选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| slotId<sup>(7+)</sup> | number | false | true | 卡槽ID |  
| msgIndex<sup>(7+)</sup> | number | false | true | 消息索引 |  
| newStatus<sup>(7+)</sup> | SimMessageStatus | false | true | 新状态 |  
| pdu<sup>(7+)</sup> | string | false | true | 协议数据单元 |  
| smsc<sup>(7+)</sup> | string | false | true | 短消息业务中心 |  
    
## SimShortMessage<sup>(7+)</sup>    
SIM卡短消息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| shortMessage<sup>(7+)</sup> | ShortMessage | false | true | 短消息 |  
| simMessageStatus<sup>(7+)</sup> | SimMessageStatus | false | true | SIM卡消息状态 |  
| indexOnSim<sup>(7+)</sup> | number | false | true | SIM卡索引 |  
    
## SimMessageStatus<sup>(7+)</sup>    
SIM卡消息状态。    
    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SIM_MESSAGE_STATUS_FREE | 0 | SIM卡上的状态可用空间 |  
| SIM_MESSAGE_STATUS_READ | 1 | 消息已读状态 |  
| SIM_MESSAGE_STATUS_UNREAD | 3 | 消息未读状态 |  
| SIM_MESSAGE_STATUS_SENT | 5 | 存储发送消息（仅适用于SMS） |  
| SIM_MESSAGE_STATUS_UNSENT | 7 | 储未发送消息（仅适用于SMS） |  
    
## RanType<sup>(7+)</sup>    
设备网络制式。    
    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_GSM | 1 | GSM |  
| TYPE_CDMA | 2 | CMDA |  
    
## SmsSegmentsInfo<sup>(8+)</sup>    
短信段信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| splitCount<sup>(8+)</sup> | number | false | true | 拆分计数 |  
| encodeCount<sup>(8+)</sup> | number | false | true | 编码计数 |  
| encodeCountRemaining<sup>(8+)</sup> | number | false | true | 剩余编码计数 |  
| scheme<sup>(8+)</sup> | SmsEncodingScheme | false | true | 短信编码方案 |  
    
## SmsEncodingScheme<sup>(8+)</sup>    
短信编码方案。    
    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SMS_ENCODING_UNKNOWN | 0 | 未知短信编码 |  
| SMS_ENCODING_7BIT | 1 | 7位短信编码。 |  
| SMS_ENCODING_8BIT | 2 | 8位短信编码 |  
| SMS_ENCODING_16BIT | 3 | 16位短信编码。 |  
