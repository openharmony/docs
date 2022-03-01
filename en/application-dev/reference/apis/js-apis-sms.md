# SMS

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import sms from '@ohos.telephony.sms';
```

## sms.createMessage<a name=sms.createMessage-callback></a>

createMessage\(pdu: Array<number\>, specification: string, callback: AsyncCallback<ShortMessage\>\): void

Creates an SMS message instance based on the protocol data unit (PDU) and the specified SMS protocol. This function uses an asynchronous callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------- | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| pdu           | Array&lt;number&gt;                                | Yes| PDU, which is obtained from the received SMS message.|
| specification | string                                             | Yes| SMS protocol type. The options are as follows: <br/> - **3gpp**: GSM/UMTS/LTE SMS<br/> - **3gpp2**: CDMA SMS|
| callback      | AsyncCallback&lt;[ShortMessage](#ShortMessage)&gt; | Yes| Callback used to return the result.|

**Example**

```
const specification = '3gpp';
// Display PDUs using numbers in an array, for example, [0x08, 0x91, ...].
const pdu = [0x08, 0x91];
sms.createMessage(pdu, specification, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.createMessage<a name=sms.createMessage-promise></a>

createMessage\(pdu: Array<number\>, specification: string\): Promise<ShortMessage\>

Creates an SMS message instance based on the PDU and the specified SMS protocol. This function uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------- | ------------------- | ---- | ------------------------------------------------------------ |
| pdu           | Array&lt;number&gt; | Yes| PDU, which is obtained from the received SMS message.|
| specification | string              | Yes| SMS protocol type. The options are as follows: <br/> - **3gpp**: GSM/UMTS/LTE SMS<br/> - **3gpp2**: CDMA SMS|

**Return value**

| Type| Description|
| -------------------------------------------- | --------------------------------- |
| Promise&lt;[ShortMessage](#ShortMessage)&gt; | Promise used to return the result.|

**Example**

```
const specification = '3gpp';
// Display PDUs using numbers in an array, for example, [0x08, 0x91, ...].
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

Sends an SMS message.

Before using this API, you must declare the **ohos.permission.SEND_MESSAGES** permission.

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [SendMessageOptions](#SendMessageOptions) | Yes| Options (including the callback) for sending an SMS message. For details, see [SendMessageOptions](#SendMessageOptions).|

**Example**

```
let sendCallback = function (err, data) {    
    console.log(`sendCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`); 
}
let deliveryCallback = function (err, data) {    
    console.log(`deliveryCallback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`); 
}
let slotId = 0;
let content ='SMS message content';
let destinationHost = '+861xxxxxxxxxx';
let serviceCenter = '+861xxxxxxxxxx';
let destinationPort = 1000;
let options = {slotId, content, destinationHost, serviceCenter, destinationPort, sendCallback, deliveryCallback};
sms.sendMessage(options);
```


## sms.getDefaultSmsSlotId<sup>7+</sup><a name=sms.getDefaultSmsSlotId-callback></a>

getDefaultSmsSlotId\(callback: AsyncCallback<number\>\): void

Obtains the default slot of the SIM card used to send SMS messages. This function uses an asynchronous callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | --------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the result, <br/> - **0**: slot 1 <br/> - **1**: slot 2|

**Example**

```
sms.getDefaultSmsSlotId((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getDefaultSmsSlotId<sup>7+</sup><a name=sms.getDefaultSmsSlotId-promise></a>

getDefaultSmsSlotId\(\): Promise<number\>

Obtains the default slot of the SIM card used to send SMS messages. This function uses a promise to return the result.

**Return value**

| Type| Description|
| --------------- | ------------------------------------------------------------ |
| Promise<number> | Promise used to return the result.<br/> - **0**: slot 1<br/> - **1**: slot 2|

**Example**

```
let promise = call.getDefaultSmsSlotId();
promise.then(data => {
    console.log(`getDefaultSmsSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getDefaultSmsSlotId fail, promise: err->${JSON.stringify(err)}`);
});
```


## sms.setSmscAddr<sup>7+</sup><a name=sms.setSmscAddr-callback></a>

setSmscAddr\(slotId: number, smscAddr: string, callback: AsyncCallback<void\>\): void

Sets the short message service center (SMSC) address. This function uses an asynchronous callback to return the result.

Before using this API, you must declare the **ohos.permission.SET\_TELEPHONY\_STATE** permission.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------- | ---- | ----------------------------------------- |
| slotId   | number                    | Yes| SIM card slot ID: <br/> - **0**: slot 1<br/> - **1**: slot 2|
| smscAddr | string                    | Yes| SMSC address. |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

```
let slotId = 0;
let smscAddr = '+861xxxxxxxxxx';
sms.setSmscAddr(slotId, smscAddr, (err,data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.setSmscAddr<sup>7+</sup><a name=sms.setSmscAddr-promise></a>

setSmscAddr\(slotId: number, smscAddr: string\): Promise<void\>

Sets the SMSC address. This function uses a promise to return the result.

Before using this API, you must declare the **ohos.permission.SET\_TELEPHONY\_STATE** permission.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------ | ---- | ----------------------------------------- |
| slotId   | number | Yes| SIM card slot ID: <br/> - **0**: slot 1<br/> - **1**: slot 2|
| smscAddr | string | Yes| SMSC address. |

**Return value**

| Type| Description|
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```
let slotId = 0;
let smscAddr = '+861xxxxxxxxxx';
let promise = sms.setSmscAddr(slotId, smscAddr);
promise.then(data => {
    console.log(`setSmscAddr success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`setSmscAddr fail, promise: err->${JSON.stringify(err)}`);
});
```


## sms.getSmscAddr<sup>7+</sup><a name=sms.getSmscAddr-callback></a>

getSmscAddr\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the SMSC address. This function uses an asynchronous callback to return the result.

Before using this API, you must declare the **ohos.permission.GET\_TELEPHONY\_STATE** permission.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | --------------------------- | ---- | ----------------------------------------- |
| slotId   | number                      | Yes| SIM card slot ID: <br/> - **0**: slot 1<br/> - **1**: slot 2|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result.|

**Example**

```
let slotId = 0;
sms.getSmscAddr(slotId, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getSmscAddr<sup>7+</sup><a name=sms.getSmscAddr-promise></a>

getSmscAddr\(slotId: number\): Promise<string\>

Obtains the SMSC address. This function uses a promise to return the result.

Before using this API, you must declare the **ohos.permission.GET\_TELEPHONY\_STATE** permission.

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ---- | ----------------------------------------- |
| slotId | number | Yes| SIM card slot ID: <br/> - **0**: slot 1<br/> - **1**: slot 2|

**Return value**

| Type| Description|
| --------------------- | --------------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**

```
let slotId = 0;
let promise = sms.getSmscAddr(slotId);
promise.then(data => {
    console.log(`getSmscAddr success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getSmscAddr fail, promise: err->${JSON.stringify(err)}`);
});
```


## ShortMessage<a name=ShortMessage></a>

Defines an SMS message instance.

| Variable| Type| Description|
| ------------------------ | --------------------------------------- | ------------------------------------------------------------ |
| emailAddress             | string                                  | Email address.|
| emailMessageBody         | string                                  | Email body.|
| hasReplyPath             | boolean                                 | Whether the received SMS contains **TP-Reply-Path**. The default value is **false**. <br/>**TP-Reply-Path**: the path in which the mobile phone can reply to the SMS message through the originating SMSC.|
| isEmailMessage           | boolean                                 | Whether the received SMS message is an email.|
| isReplaceMessage         | boolean                                 | Whether the received SMS message is a **replace short message**. The default value is **false**. <br/>For details, see section 9.2.3.9 in **3GPP TS 23.040**.|
| isSmsStatusReportMessage | boolean                                 | Whether the received SMS message is an SMS delivery status report. The default value is **false**. <br/>SMS delivery status report: a message sent from the SMSC to show the current status of the SMS message you delivered.|
| messageClass             | [ShortMessageClass](#ShortMessageClass) | SMS message type.|
| pdu                      | Array&lt;number&gt;                     | PDU in the SMS message.|
| protocolId               | number                                  | ID of the protocol used for sending SMS messages.|
| scAddress                | string                                  | Address of the short message service center (SMSC).|
| scTimestamp              | number                                  | SMSC timestamp.|
| status                   | number                                  | SMS message status sent by the SMSC in the **SMS-STATUS-REPORT** message.|
| userRawData              | Array&lt;number&gt;                     | User data except the data header.|
| visibleMessageBody       | string                                  | SMS message body.|
| visibleRawAddress        | string                                  | Sender address.|


## ShortMessageClass<a name=ShortMessageClass></a>

Enumerates SMS message types.

| Variable| Value| Description|
| ---------------- | ---- | ---------------------------------------- |
| UNKNOWN          | 0    | Unknown type.|
| INSTANT_MESSAGE  | 1    | Instant message, which is displayed immediately after being received.|
| OPTIONAL_MESSAGE | 2    | Message stored in the device or SIM card.|
| SIM_MESSAGE      | 3    | Message containing SIM card information, which is to be stored in the SIM card.|
| FORWARD_MESSAGE  | 4    | Message to be forwarded to another device.|


## SendMessageOptions<a name=SendMessageOptions></a>

Provides the options (including callbacks) for sending an SMS message.

For example, you can specify the SMS message type by the optional parameter **content**.

| Name| Type| Mandatory| Description|
| ---------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| slotId           | number                                                       | Yes| Slot ID of the SIM card used for sending SMS messages: <br/> - **0**: slot 1 <br/> - **1**: slot 2|
| destinationHost  | string                                                       | Yes| Destination address of the SMS message.|
| content          | string \| Array&lt;number&gt;                                | Yes| SMS message type. If the content is comprised of character strings, the SMS message is a text message. If the content is comprised of byte arrays, the SMS message is a data message.|
| serviceCenter    | string                                                       | No| SMSC address. By default, the SMSC address in the SIM card is used.|
| destinationPort  | number                                                       | No| Destination port of the SMS message. This parameter is mandatory only for a data message. Otherwise, it is optional.|
| sendCallback     | AsyncCallback&lt;[ISendShortMessageCallback](#ISendShortMessageCallback)&gt; | No| Callback used to return the SMS message sending result. For details, see [ISendShortMessageCallback](#ISendShortMessageCallback).|
| deliveryCallback | AsyncCallback&lt;[IDeliveryShortMessageCallback](#IDeliveryShortMessageCallback)&gt; | No| Callback used to return the SMS message delivery report. For details, see [IDeliveryShortMessageCallback](#IDeliveryShortMessageCallback).|


## ISendShortMessageCallback<a name=ISendShortMessageCallback></a>

Provides the callback for the SMS message delivery report. It consists of three parts: SMS message sending result, URI for storing the sent SMS message, and whether the SMS message is the last part of a long SMS message.

| Name| Type| Mandatory| Description|
| ---------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| isLastPart | boolean                         | No| Whether this SMS message is the last part of a long SMS message. The value **true** indicates that this SMS message is the last part of a long SMS message, and value **false** indicates the opposite. The default value is **false**.|
| result     | [SendSmsResult](#SendSmsResult) | Yes| SMS message sending result.|
| url        | string                          | Yes| URI for storing sent SMS messages.|


## IDeliveryShortMessageCallback<a name=IDeliveryShortMessageCallback></a>

Provides the callback for the SMS message delivery report. Return the SMS delivery report.

| Name| Type| Mandatory| Description|
| ------ | ------------------- | ---- | -------------- |
| pdu    | Array&lt;number&gt; | Yes| SMS message delivery report.|


## SendSmsResult<a name=SendSmsResult></a>

Enumerates SMS message sending results.

| Name| Value| Description|
| ------------------------------------ | ---- | ------------------------------------------------------ |
| SEND_SMS_SUCCESS                     | 0    | SMS message sent successfully.|
| SEND_SMS_FAILURE_UNKNOWN             | 1    | Failed to send the SMS message due to unknown reasons.|
| SEND_SMS_FAILURE_RADIO_OFF           | 2    | Failed to send the SMS message because the modem is shut down.|
| SEND_SMS_FAILURE_SERVICE_UNAVAILABLE | 3    | Failed to send the SMS message because the network is unavailable or SMS message sending or receiving is not supported.|
