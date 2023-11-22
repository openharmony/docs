# @ohos.telephony.sms    
短信服务提供了管理短信的一些基础能力，包括创建、发送短信，获取、设置发送短信的默认SIM卡槽ID，获取、设置短信服务中心（SMSC）地址，以及检查当前设备是否具备短信发送和接收能力等。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import sms from '@ohos.telephony.sms'    
```  
    
## createMessage    
根据协议数据单元（PDU）和指定的短信协议创建短信实例。  
 **调用形式：**     
    
- createMessage(pdu: Array\<number>, specification: string, callback: AsyncCallback\<ShortMessage>): void    
起始版本： 6    
- createMessage(pdu: Array\<number>, specification: string): Promise\<ShortMessage>    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pdu | Array<number> | true | 协议数据单元，从收到的信息中获取。 |  
| specification | string | true | 短信协议类型。<br/>- 3gpp：表示GSM/UMTS/LTE SMS<br/>- 3gpp2：表示CDMA SMS |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<ShortMessage> | 以Promise形式返回创建的短信实例。 |  
    
    
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
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
const specification: string = '3gpp';  
// 以数组的形式显示协议数据单元（PDU），类型为number，例如[0x08, 0x91, ...]  
const pdu: Array<number> = [0x08, 0x91];  
sms.createMessage(pdu, specification, (err: BusinessError, data: sms.ShortMessage) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
const specification: string = '3gpp';  
// 以数组的形式显示协议数据单元（PDU），类型为number，例如[0x08, 0x91, ...]  
const pdu: Array<number> = [0x08, 0x91];  
sms.createMessage(pdu, specification).then((data: sms.ShortMessage) => {  
    console.log(`createMessage success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`createMessage failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## sendMessage<sup>(deprecated)</sup>    
发送短信。  
 **调用形式：**     
- sendMessage(options: SendMessageOptions): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: telephony.sms#sendShortMessage。  
 **系统能力:**  SystemCapability.Telephony.SmsMms  
 **需要权限：** ohos.permission.SEND_MESSAGES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | SendMessageOptions | true | 发送短信的参数和回调，参考[SendMessageOptions](#sendmessageoptions)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
import sms from '@ohos.telephony.sms';  
import { AsyncCallback } from '@ohos.base';  
import { BusinessError } from '@ohos.base';  
  
let sendCallback: AsyncCallback<sms.ISendShortMessageCallback> = (err: BusinessError, data: sms.ISendShortMessageCallback) => {  
    console.log(`sendCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);   
}  
let deliveryCallback: AsyncCallback<sms.IDeliveryShortMessageCallback> = (err: BusinessError, data: sms.IDeliveryShortMessageCallback) => {  
    console.log(`deliveryCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);   
}  
let options: sms.SendMessageOptions = {  
    slotId: 0,  
    content: '短信内容',  
    destinationHost: '+861xxxxxxxxxx',  
    serviceCenter: '+861xxxxxxxxxx',  
    destinationPort: 1000,  
    sendCallback: sendCallback,  
    deliveryCallback: deliveryCallback  
};  
sms.sendMessage(options);  
    
```    
  
    
## sendShortMessage<sup>(10+)</sup>    
发送短信。  
 **调用形式：**     
    
- sendShortMessage(options: SendMessageOptions, callback: AsyncCallback\<void>): void    
起始版本： 10    
- sendShortMessage(options: SendMessageOptions): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Telephony.SmsMms  
 **需要权限：** ohos.permission.SEND_MESSAGES    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | SendMessageOptions | true | 发送短信的参数和回调，参考[SendMessageOptions](#sendmessageoptions)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式返回发送短信的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { AsyncCallback } from '@ohos.base';  
import { BusinessError } from '@ohos.base';  
  
let sendCallback: AsyncCallback<sms.ISendShortMessageCallback> = (err: BusinessError, data: sms.ISendShortMessageCallback) => {  
    console.log(`sendCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
}  
let deliveryCallback: AsyncCallback<sms.IDeliveryShortMessageCallback> = (err: BusinessError, data: sms.IDeliveryShortMessageCallback) => {  
    console.log(`deliveryCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
}  
let options: sms.SendMessageOptions = {  
    slotId: 0,  
    content: '短信内容',  
    destinationHost: '+861xxxxxxxxxx',  
    serviceCenter: '+861xxxxxxxxxx',  
    destinationPort: 1000,  
    sendCallback: sendCallback,  
    deliveryCallback: deliveryCallback  
};  
sms.sendShortMessage(options, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { AsyncCallback } from '@ohos.base';  
import { BusinessError } from '@ohos.base';  
  
let sendCallback: AsyncCallback<sms.ISendShortMessageCallback> = (err: BusinessError, data: sms.ISendShortMessageCallback) => {  
    console.log(`sendCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
}  
let deliveryCallback: AsyncCallback<sms.IDeliveryShortMessageCallback> = (err: BusinessError, data: sms.IDeliveryShortMessageCallback) => {  
    console.log(`deliveryCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
}  
let options: sms.SendMessageOptions = {  
    slotId: 0,  
    content: '短信内容',  
    destinationHost: '+861xxxxxxxxxx',  
    serviceCenter: '+861xxxxxxxxxx',  
    destinationPort: 1000,  
    sendCallback: sendCallback,  
    deliveryCallback: deliveryCallback  
};  
let promise = sms.sendShortMessage(options);  
promise.then(() => {  
    console.log(`sendShortMessage success`);  
}).catch((err: BusinessError) => {  
    console.error(`sendShortMessage failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getDefaultSmsSlotId<sup>(7+)</sup>    
获取发送短信的默认SIM卡槽ID。  
 **调用形式：**     
    
- getDefaultSmsSlotId(callback: AsyncCallback\<number>): void    
起始版本： 7    
- getDefaultSmsSlotId(): Promise\<number>    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| Promise<number> | 以Promise形式返回发送短信的默认SIM卡：<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
sms.getDefaultSmsSlotId((err: BusinessError, data: number) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});<i></i><span style="font-size: 14px; letter-spacing: 0px;"></span>  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
sms.getDefaultSmsSlotId().then((data: number) => {  
    console.log(`getDefaultSmsSlotId success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getDefaultSmsSlotId failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## hasSmsCapability<sup>(7+)</sup>    
检查当前设备是否具备短信发送和接收能力，该方法是同步方法。  
 **调用形式：**     
- hasSmsCapability(): boolean  
  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | - true：设备具备短信发送和接收能力。<br/>- false：设备不具备短信发送和接收能力。 |  
    
 **示例代码：**   
```ts    
import sms from '@ohos.telephony.sms';  
let result = sms.hasSmsCapability(); console.log(`hasSmsCapability: ${JSON.stringify(result)}`);    
```    
  
    
## getDefaultSmsSimId<sup>(10+)</sup>    
获取发送短信的默认SIM卡ID。  
 **调用形式：**     
    
- getDefaultSmsSimId(callback: AsyncCallback\<number>): void    
起始版本： 10    
- getDefaultSmsSimId(): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。<br/>与SIM卡绑定，从1开始递增。 |  
| Promise<number> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
sms.getDefaultSmsSimId((err: BusinessError, data: number) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import sms from '@ohos.telephony.sms';  
import { BusinessError } from '@ohos.base';  
  
let promise = sms.getDefaultSmsSimId();  
promise.then((data: number) => {  
    console.log(`getDefaultSmsSimId success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getDefaultSmsSimId failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## ShortMessage  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| visibleMessageBody | string | false | true | 短信正文。 |  
| visibleRawAddress | string | false | true | 发送者地址。 |  
| messageClass | ShortMessageClass | false | true | 短信类型。 |  
| protocolId | number | false | true | 发送短信时使用的协议标识。 |  
| scAddress | string | false | true | 短消息服务中心（SMSC）地址。 |  
| scTimestamp | number | false | true | SMSC时间戳。 |  
| isReplaceMessage | boolean | false | true | 收到的短信是否为“替换短信”，默认为false。<br/>“替换短信”有关详细信息，参见 “3GPP TS 23.040 9.2.3.9”。 |  
| hasReplyPath | boolean | false | true | 收到的短信是否包含“TP-Reply-Path”，默认为false。<br/>“TP-Reply-Path”：设备根据发送SMS消息的短消息中心进行回复。 |  
| pdu | Array<number> | false | true | SMS消息中的协议数据单元 （PDU）。 |  
| status | number | false | true | SMS-STATUS-REPORT消息中的短信状态指示短信服务中心（SMSC）发送的短信状态。 |  
| isSmsStatusReportMessage | boolean | false | true | 当前消息是否为“短信状态报告”，默认为false。<br/>“短信状态报告”是一种特定格式的短信，被用来从Service Center到Mobile Station传送状态报告。 |  
    
## ShortMessageClass    
短信类型。    
    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNKNOWN | 0 | 未知类型。 |  
| INSTANT_MESSAGE | 1 | 即时消息，收到后立即显示。 |  
| OPTIONAL_MESSAGE | 2 | 存储在设备或SIM卡上的短信。 |  
| SIM_MESSAGE | 3 | 包含SIM卡信息的短信，需要存储在SIM卡中。 |  
| FORWARD_MESSAGE | 4 | 要转发到另一台设备的短信。 |  
    
## SendMessageOptions    
发送短信的参数和回调。根据SendMessageOptions中的可选参数content的值判断短信类型。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| slotId | number | false | true | 用于发送短信的SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| destinationHost | string | false | true | 短信的发送地址。 |  
| serviceCenter | string | false | false | 如果内容是字符串，则这是一条文本短信。如果内容是字节数组，则这是一条数据短信。 |  
| content | string \| Array<number> | false | true | 短信中心地址。默认使用SIM卡中的短信中心地址。 |  
| destinationPort | number | false | false | 如果发送数据消息，destinationPort 是必需的。否则是可选的。 |  
| sendCallback | AsyncCallback<ISendShortMessageCallback> | false | false | 短信发送结果回调，返回短信发送的结果，参考[ISendShortMessageCallback](#isendshortmessagecallback)。 |  
| deliveryCallback | AsyncCallback<IDeliveryShortMessageCallback> | false | false | 短信送达结果回调，返回短信递送报告，参考[IDeliveryShortMessageCallback](#ideliveryshortmessagecallback)。 |  
    
## ISendShortMessageCallback    
回调实例。返回短信发送结果、存储已发送短信的URI和是否为长短信的最后一部分。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| result | SendSmsResult | false | true | 短信发送结果。 |  
| url | string | false | true | 存储发送短信的URI。 |  
| isLastPart | boolean | false | true | 指定这是否是长短信的最后一部分。true表示这是长短信的最后一部分，false表示不是。默认为false。 |  
    
## IDeliveryShortMessageCallback    
回调实例，返回短信送达报告。  
 **系统能力:**  SystemCapability.Telephony.SmsMms    
### 属性    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| pdu | Array<number> | false | true | 短信送达报告。 |  
    
## SendSmsResult    
短信发送结果。    
    
 **系统能力:**  SystemCapability.Telephony.SmsMms    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SEND_SMS_SUCCESS | 0 | 发送短信成功。 |  
| SEND_SMS_FAILURE_UNKNOWN | 1 | 发送短信失败，原因未知。 |  
| SEND_SMS_FAILURE_RADIO_OFF | 2 | 发送短信失败，原因为调制解调器关机。 |  
| SEND_SMS_FAILURE_SERVICE_UNAVAILABLE | 3 | 发送短信失败，原因为网络不可用、不支持发送或接收短信。 |  
