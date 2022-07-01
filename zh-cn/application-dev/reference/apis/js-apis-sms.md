# 短信服务

短信服务提供了管理短信的一些基础能力，包括创建、发送短信，获取、设置发送短信的默认SIM卡槽ID，获取、设置短信服务中心（SMSC）地址，以及检查当前设备是否具备短信发送和接收能力等。

>**说明：** 
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import sms from '@ohos.telephony.sms';
```

## sms.createMessage

createMessage\(pdu: Array&lt;number&gt;, specification: string, callback: AsyncCallback<ShortMessage\>\): void

根据协议数据单元（PDU）和指定的短信协议创建短信实例，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名        | 类型                                               | 必填 | 说明                                                         |
| ------------- | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| pdu           | Array&lt;number&gt;                                | 是   | 协议数据单元，从收到的信息中获取。                           |
| specification | string                                             | 是   | 短信协议类型。<br/>- 3gpp表示GSM/UMTS/LTE SMS<br/>- 3gpp2表示CDMA SMS |
| callback      | AsyncCallback&lt;[ShortMessage](#shortmessage)&gt; | 是   | 回调函数。                                                   |

**示例：**

```js
const specification = '3gpp';
// 以数组的形式显示协议数据单元（PDU），类型为number，例如[0x08, 0x91, ...]
const pdu = [0x08, 0x91];
sms.createMessage(pdu, specification, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.createMessage

createMessage\(pdu: Array&lt;number&gt;, specification: string\): Promise<ShortMessage\>

根据协议数据单元（PDU）和指定的短信协议创建短信实例，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名        | 类型                | 必填 | 说明                                                         |
| ------------- | ------------------- | ---- | ------------------------------------------------------------ |
| pdu           | Array&lt;number&gt; | 是   | 协议数据单元，从收到的信息中获取。                           |
| specification | string              | 是   | 短信协议类型。<br/>- 3gpp表示GSM/UMTS/LTE SMS<br/>- 3gpp2表示CDMA SMS |

**返回值：**

| 类型                                         | 说明                              |
| -------------------------------------------- | --------------------------------- |
| Promise&lt;[ShortMessage](#shortmessage)&gt; | 以Promise形式返回创建的短信实例。 |

**示例：**

```js
const specification = '3gpp';
// 以数组的形式显示协议数据单元（PDU），类型为number，例如[0x08, 0x91, ...]
const pdu = [0x08, 0x91];
let promise = sms.createMessage(pdu, specification);
promise.then(data => {
    console.log(`createMessage success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`createMessage fail, promise: err->${JSON.stringify(err)}`);
});
```

## sms.sendMessage

sendMessage(options: SendMessageOptions): void

发送短信。

**需要权限**：ohos.permission.SEND_MESSAGES

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名  | 类型                                      | 必填 | 说明                                                         |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [SendMessageOptions](#sendmessageoptions) | 是   | 发送短信的参数和回调，参考[SendMessageOptions](#sendmessageoptions)。 |

**示例：**

```js
let sendCallback = function (err, data) {    
    console.log(`sendCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`); 
}
let deliveryCallback = function (err, data) {    
    console.log(`deliveryCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`); 
}
let slotId = 0;
let content = '短信内容';
let destinationHost = '+861xxxxxxxxxx';
let serviceCenter = '+861xxxxxxxxxx';
let destinationPort = 1000;
let options = {slotId, content, destinationHost, serviceCenter, destinationPort, sendCallback, deliveryCallback};
sms.sendMessage(options);
```


## sms.getDefaultSmsSlotId<sup>7+</sup>

getDefaultSmsSlotId\(callback: AsyncCallback&lt;number&gt;\): void

获取发送短信的默认SIM卡槽ID，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                     |
| -------- | --------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**示例：**

```js
sms.getDefaultSmsSlotId((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getDefaultSmsSlotId<sup>7+</sup>

getDefaultSmsSlotId\(\): Promise&lt;number&gt;

获取发送短信的默认SIM卡槽ID，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Telephony.SmsMms

**返回值：**

| 类型            | 说明                                                         |
| --------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | 以Promise形式返回发送短信的默认SIM卡：<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**示例：**

```js
let promise = sms.getDefaultSmsSlotId();
promise.then(data => {
    console.log(`getDefaultSmsSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getDefaultSmsSlotId fail, promise: err->${JSON.stringify(err)}`);
});
```

## sms.setDefaultSmsSlotId<sup>7+</sup>

setDefaultSmsSlotId\(slotId: number,callback: AsyncCallback&lt;void&gt;\): void

设置发送短信的默认SIM卡槽ID，使用callback方式作为异步方法。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.SmsMms

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                    | 是   | SIM卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2<br/>- -1：清除默认配置 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |

**示例：**

```js
sms.setDefaultSmsSlotId(0,(err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.setDefaultSmsSlotId<sup>7+</sup>

setDefaultSmsSlotId\(slotId: number\): Promise&lt;void&gt;

设置发送短信的默认SIM卡槽ID，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.SmsMms

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| slotId | number | 是   | SIM卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2<br/>- -1：清除默认配置 |

**返回值：**

| 类型            | 说明                            |
| --------------- | ------------------------------- |
| Promise\<void\> | 以Promise形式异步返回设置结果。 |

**示例：**

```js
let promise = sms.setDefaultSmsSlotId(0);
promise.then(data => {
    console.log(`setDefaultSmsSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`setDefaultSmsSlotId fail, promise: err->${JSON.stringify(err)}`);
});
```

## sms.setSmscAddr<sup>7+</sup>

setSmscAddr\(slotId: number, smscAddr: string, callback: AsyncCallback<void\>\): void

设置短信服务中心（SMSC）地址，使用callback方式作为异步方法。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE，该权限为系统权限

**系统能力**：SystemCapability.Telephony.SmsMms

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                      |
| -------- | ------------------------- | ---- | ----------------------------------------- |
| slotId   | number                    | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| smscAddr | string                    | 是   | 短信服务中心地址。                        |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                |

**示例：**

```js
let slotId = 0;
let smscAddr = '+861xxxxxxxxxx';
sms.setSmscAddr(slotId, smscAddr, (err,data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.setSmscAddr<sup>7+</sup>

setSmscAddr\(slotId: number, smscAddr: string\): Promise\<void\>

设置短信服务中心（SMSC）地址，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE，该权限为系统权限

**系统能力**：SystemCapability.Telephony.SmsMms

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型   | 必填 | 说明                                      |
| -------- | ------ | ---- | ----------------------------------------- |
| slotId   | number | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| smscAddr | string | 是   | 短信服务中心地址。                        |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回设置结果。 |

**示例：**

```js
let slotId = 0;
let smscAddr = '+861xxxxxxxxxx';
let promise = sms.setSmscAddr(slotId, smscAddr);
promise.then(data => {
    console.log(`setSmscAddr success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`setSmscAddr fail, promise: err->${JSON.stringify(err)}`);
});
```


## sms.getSmscAddr<sup>7+</sup>

getSmscAddr\(slotId: number, callback: AsyncCallback<string\>\): void

获取短信服务中心（SMSC）地址，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE，该权限为系统权限

**系统能力**：SystemCapability.Telephony.SmsMms

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                      |
| -------- | --------------------------- | ---- | ----------------------------------------- |
| slotId   | number                      | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。                                |

**示例：**

```js
let slotId = 0;
sms.getSmscAddr(slotId, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getSmscAddr<sup>7+</sup>

getSmscAddr\(slotId: number\): Promise<string\>

获取短信服务中心（SMSC）地址，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE，该权限为系统权限

**系统能力**：SystemCapability.Telephony.SmsMms

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| slotId | number | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                  | 说明                                          |
| --------------------- | --------------------------------------------- |
| Promise&lt;string&gt; | 以Promise形式返回获取短信服务中心地址的结果。 |

**示例：**

```js
let slotId = 0;
let promise = sms.getSmscAddr(slotId);
promise.then(data => {
    console.log(`getSmscAddr success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getSmscAddr fail, promise: err->${JSON.stringify(err)}`);
});
```

## sms.hasSmsCapability<sup>7+</sup>

hasSmsCapability(): boolean

检查当前设备是否具备短信发送和接收能力，该方法是同步方法。

**系统能力**：SystemCapability.Telephony.SmsMms

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | - true：设备具备短信发送和接收能力<br/>- false：设备不具备短信发送和接收能力 |

```js
let result = sms.hasSmsCapability(); 
console.log(`hasSmsCapability: ${JSON.stringify(result)}`);
```

## ShortMessage

短信实例。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

| 参数名                   | 类型                                    | 说明                                                         |
| ------------------------ | --------------------------------------- | ------------------------------------------------------------ |
| hasReplyPath             | boolean                                 | 收到的短信是否包含“TP-Reply-Path”，默认为false。<br/>“TP-Reply-Path”：设备根据发送SMS消息的短消息中心进行回复。 |
| isReplaceMessage         | boolean                                 | 收到的短信是否为“替换短信”，默认为false。<br/>“替换短信”有关详细信息，参见 “3GPP TS 23.040 9.2.3.9”。 |
| isSmsStatusReportMessage | boolean                                 | 当前消息是否为“短信状态报告”，默认为false。<br/>“短信状态报告”是一种特定格式的短信，被用来从Service Center到Mobile Station传送状态报告。 |
| messageClass             | [ShortMessageClass](#shortmessageclass) | 短信类型。                                                   |
| pdu                      | Array&lt;number&gt;                     | SMS消息中的协议数据单元 （PDU）。                            |
| protocolId               | number                                  | 发送短信时使用的协议标识。                                   |
| scAddress                | string                                  | 短消息服务中心（SMSC）地址。                                 |
| scTimestamp              | number                                  | SMSC时间戳。                                                 |
| status                   | number                                  | SMS-STATUS-REPORT消息中的短信状态指示短信服务中心（SMSC）发送的短信状态。 |
| visibleMessageBody       | string                                  | 短信正文。                                                   |
| visibleRawAddress        | string                                  | 发送者地址。                                                 |


## ShortMessageClass

短信类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

| 名称             | 值   | 说明                                     |
| ---------------- | ---- | ---------------------------------------- |
| UNKNOWN          | 0    | 未知类型。                               |
| INSTANT_MESSAGE  | 1    | 即时消息，收到后立即显示。               |
| OPTIONAL_MESSAGE | 2    | 存储在设备或SIM卡上的短信。              |
| SIM_MESSAGE      | 3    | 包含SIM卡信息的短信，需要存储在SIM卡中。 |
| FORWARD_MESSAGE  | 4    | 要转发到另一台设备的短信。               |


## SendMessageOptions

发送短信的参数和回调。根据SendMessageOptions中的可选参数content的值判断短信类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

| 参数名           | 类型                                                         | 必填 | 说明                                                         |
| ---------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| slotId           | number                                                       | 是   | 用于发送短信的SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2      |
| destinationHost  | string                                                       | 是   | 短信的发送地址。                                             |
| content          | string \| Array&lt;number&gt;                                | 是   | 如果内容是字符串，则这是一条文本短信。如果内容是字节数组，则这是一条数据短信。 |
| serviceCenter    | string                                                       | 否   | 短信中心地址。默认使用SIM卡中的短信中心地址。                |
| destinationPort  | number                                                       | 否   | 如果发送数据消息，destinationPort 是必需的。否则是可选的。   |
| sendCallback     | AsyncCallback&lt;[ISendShortMessageCallback](#isendshortmessagecallback)&gt; | 否   | 短信发送结果回调，返回短信发送的结果，参考[ISendShortMessageCallback](#isendshortmessagecallback)。 |
| deliveryCallback | AsyncCallback&lt;[IDeliveryShortMessageCallback](#ideliveryshortmessagecallback)&gt; | 否   | 短信送达结果回调，返回短信递送报告，参考[IDeliveryShortMessageCallback](#ideliveryshortmessagecallback)。 |


## ISendShortMessageCallback

回调实例。返回短信发送结果、存储已发送短信的URI和是否为长短信的最后一部分。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

| 参数名     | 类型                            | 必填 | 说明                                                         |
| ---------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| isLastPart | boolean                         | 否   | 指定这是否是长短信的最后一部分。true表示这是长短信的最后一部分，false表示不是。默认为false。 |
| result     | [SendSmsResult](#sendsmsresult) | 是   | 短信发送结果。                                               |
| url        | string                          | 是   | 存储发送短信的URI。                                          |


## IDeliveryShortMessageCallback

回调实例。返回短信送达报告。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

| 参数名 | 类型                | 必填 | 说明           |
| ------ | ------------------- | ---- | -------------- |
| pdu    | Array&lt;number&gt; | 是   | 短信送达报告。 |


## SendSmsResult

短信发送结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.SmsMms。

| 名称                                 | 值   | 说明                                                   |
| ------------------------------------ | ---- | ------------------------------------------------------ |
| SEND_SMS_SUCCESS                     | 0    | 发送短信成功。                                         |
| SEND_SMS_FAILURE_UNKNOWN             | 1    | 发送短信失败，原因未知。                               |
| SEND_SMS_FAILURE_RADIO_OFF           | 2    | 发送短信失败，原因为调制解调器关机。                   |
| SEND_SMS_FAILURE_SERVICE_UNAVAILABLE | 3    | 发送短信失败，原因为网络不可用、不支持发送或接收短信。 |