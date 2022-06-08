# SMS

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import sms from '@ohos.telephony.sms';
```

## sms.createMessage

createMessage\(pdu: Array&lt;number&gt;, specification: string, callback: AsyncCallback<ShortMessage\>\): void

Creates an SMS message instance based on the protocol data unit (PDU) and the specified SMS protocol. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name       | Type                                              | Mandatory| Description                                                        |
| ------------- | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| pdu           | Array&lt;number&gt;                                | Yes  | PDU, which is obtained from the received SMS message.                          |
| specification | string                                             | Yes  | SMS protocol type. <br>- **3gpp**: GSM/UMTS/LTE SMS<br>- **3gpp2**: CDMA SMS|
| callback      | AsyncCallback&lt;[ShortMessage](#shortmessage)&gt; | Yes  | Callback used to return the result.                                                  |

**Example**

```
const specification = '3gpp';
// Display PDUs using numbers in an array, for example, [0x08, 0x91, ...].
const pdu = [0x08, 0x91];
sms.createMessage(pdu, specification, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.createMessage

createMessage\(pdu: Array&lt;number&gt;, specification: string\): Promise<ShortMessage\>

Creates an SMS message instance based on the PDU and the specified SMS protocol. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name       | Type               | Mandatory| Description                                                        |
| ------------- | ------------------- | ---- | ------------------------------------------------------------ |
| pdu           | Array&lt;number&gt; | Yes  | PDU, which is obtained from the received SMS message.                          |
| specification | string              | Yes  | SMS protocol type. <br>- **3gpp**: GSM/UMTS/LTE SMS<br>- **3gpp2**: CDMA SMS|

**Return Value**

| Type                                        | Description                             |
| -------------------------------------------- | --------------------------------- |
| Promise&lt;[ShortMessage](#shortmessage)&gt; | Promise used to return the result.|

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

**Required permission**: ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [SendMessageOptions](#sendmessageoptions) | Yes  | Options (including the callback) for sending an SMS message. For details, see [SendMessageOptions](#sendmessageoptions).|

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


## sms.getDefaultSmsSlotId<sup>7+</sup>

getDefaultSmsSlotId\(callback: AsyncCallback&lt;number&gt;\): void

Obtains the default slot of the SIM card used to send SMS messages. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                       | Mandatory| Description                                    |
| -------- | --------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Example**

```
sms.getDefaultSmsSlotId((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getDefaultSmsSlotId<sup>7+</sup>

getDefaultSmsSlotId\(\): Promise&lt;number&gt;

Obtains the default slot of the SIM card used to send SMS messages. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.SmsMms

**Return Value**

| Type           | Description                                                        |
| --------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the result.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Example**

```
let promise = sms.getDefaultSmsSlotId();
promise.then(data => {
    console.log(`getDefaultSmsSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getDefaultSmsSlotId fail, promise: err->${JSON.stringify(err)}`);
});
```


## sms.setSmscAddr<sup>7+</sup>

setSmscAddr\(slotId: number, smscAddr: string, callback: AsyncCallback<void\>\): void

Sets the short message service center (SMSC) address. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE (a system permission)

**System capability**: SystemCapability.Telephony.SmsMms

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                     | Mandatory| Description                                     |
| -------- | ------------------------- | ---- | ----------------------------------------- |
| slotId   | number                    | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| smscAddr | string                    | Yes  | SMSC address.                        |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                               |

**Example**

```
let slotId = 0;
let smscAddr = '+861xxxxxxxxxx';
sms.setSmscAddr(slotId, smscAddr, (err,data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.setSmscAddr<sup>7+</sup>

setSmscAddr\(slotId: number, smscAddr: string\): Promise<void\>

Sets the SMSC address. This API uses a promise to return the result.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE (a system permission)

**System capability**: SystemCapability.Telephony.SmsMms

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type  | Mandatory| Description                                     |
| -------- | ------ | ---- | ----------------------------------------- |
| slotId   | number | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| smscAddr | string | Yes  | SMSC address.                        |

**Return Value**

| Type               | Description                           |
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


## sms.getSmscAddr<sup>7+</sup>

getSmscAddr\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the SMSC address. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE (a system permission)

**System capability**: SystemCapability.Telephony.SmsMms

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                       | Mandatory| Description                                     |
| -------- | --------------------------- | ---- | ----------------------------------------- |
| slotId   | number                      | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result.                               |

**Example**

```
let slotId = 0;
sms.getSmscAddr(slotId, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getSmscAddr<sup>7+</sup>

getSmscAddr\(slotId: number\): Promise<string\>

Obtains the SMSC address. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE (a system permission)

**System capability**: SystemCapability.Telephony.SmsMms

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type  | Mandatory| Description                                     |
| ------ | ------ | ---- | ----------------------------------------- |
| slotId | number | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return Value**

| Type                 | Description                                         |
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

## sms.hasSmsCapability<sup>7+</sup>

hasSmsCapability(): boolean

Checks whether the current device can send and receive SMS messages. This API works in synchronous mode.

**System capability**: SystemCapability.Telephony.SmsMms

**Return Value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | - **true**: The device can send and receive SMS messages.<br>- **false**: The device cannot send or receive SMS messages.|

```
let result = sms.hasSmsCapability(); 
console.log(`hasSmsCapability: ${JSON.stringify(result)}`);
```

## ShortMessage

Defines an SMS message instance.

**System capability**: SystemCapability.Telephony.SmsMms

| Name                  | Type                                   | Description                                                        |
| ------------------------ | --------------------------------------- | ------------------------------------------------------------ |
| hasReplyPath             | boolean                                 | Whether the received SMS contains **TP-Reply-Path**. The default value is **false**.<br>**TP-Reply-Path**: the path in which the device can reply to the SMS message through the originating SMSC.|
| isReplaceMessage         | boolean                                 | Whether the received SMS message is a **replace short message**. The default value is **false**.<br>For details, see section 9.2.3.9 in **3GPP TS 23.040**.|
| isSmsStatusReportMessage | boolean                                 | Whether the received SMS message is an SMS delivery status report. The default value is **false**.<br>**SMS-Status-Report**: a message sent from the SMSC to the mobile station to show the SMS message delivery status.|
| messageClass             | [ShortMessageClass](#shortmessageclass) | SMS message type.                                                  |
| pdu                      | Array&lt;number&gt;                     | PDU in the SMS message.                           |
| protocolId               | number                                  | ID of the protocol used for sending SMS messages.                                  |
| scAddress                | string                                  | Address of the short message service center (SMSC).                                |
| scTimestamp              | number                                  | SMSC timestamp.                                                |
| status                   | number                                  | SMS message status sent by the SMSC in the **SMS-STATUS-REPORT** message.|
| visibleMessageBody       | string                                  | SMS message body.                                                  |
| visibleRawAddress        | string                                  | Sender address.                                                |


## ShortMessageClass

SMS message type.

**System capability**: SystemCapability.Telephony.SmsMms

| Name            | Value  | Description                                    |
| ---------------- | ---- | ---------------------------------------- |
| UNKNOWN          | 0    | Unknown type.                              |
| INSTANT_MESSAGE  | 1    | Instant message, which is displayed immediately after being received.              |
| OPTIONAL_MESSAGE | 2    | Message stored in the device or SIM card.             |
| SIM_MESSAGE      | 3    | Message containing SIM card information, which is to be stored in the SIM card.|
| FORWARD_MESSAGE  | 4    | Message to be forwarded to another device.              |


## SendMessageOptions

Provides the options (including callbacks) for sending an SMS message. For example, you can specify the SMS message type by the optional parameter **content**.

**System capability**: SystemCapability.Telephony.SmsMms

| Name          | Type                                                        | Mandatory| Description                                                        |
| ---------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| slotId           | number                                                       | Yes  | Slot ID of the SIM card used for sending SMS messages. <br>- **0**: card slot 1<br>- **1**: card slot 2     |
| destinationHost  | string                                                       | Yes  | Destination address of the SMS message.                                            |
| content          | string \| Array&lt;number&gt;                                | Yes  | SMS message type. If the content is composed of character strings, the SMS message is a text message. If the content is composed of byte arrays, the SMS message is a data message.|
| serviceCenter    | string                                                       | No  | SMSC address. By default, the SMSC address in the SIM card is used.               |
| destinationPort  | number                                                       | No  | Destination port of the SMS message. This field is mandatory only for a data message. Otherwise, it is optional.  |
| sendCallback     | AsyncCallback&lt;[ISendShortMessageCallback](#isendshortmessagecallback)&gt; | No  | Callback used to return the SMS message sending result. For details, see [ISendShortMessageCallback](#isendshortmessagecallback).|
| deliveryCallback | AsyncCallback&lt;[IDeliveryShortMessageCallback](#ideliveryshortmessagecallback)&gt; | No  | Callback used to return the SMS message delivery report. For details, see [IDeliveryShortMessageCallback](#ideliveryshortmessagecallback).|


## ISendShortMessageCallback

Provides the callback for the SMS message sending result. It consists of three parts: SMS message sending result, URI for storing the sent SMS message, and whether the SMS message is the last part of a long SMS message.

**System capability**: SystemCapability.Telephony.SmsMms

| Name    | Type                           | Mandatory| Description                                                        |
| ---------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| isLastPart | boolean                         | No  | Whether this SMS message is the last part of a long SMS message. The value **true** indicates that this SMS message is the last part of a long SMS message, and value **false** indicates the opposite. The default value is **false**.|
| result     | [SendSmsResult](#sendsmsresult) | Yes  | SMS message sending result.                                              |
| url        | string                          | Yes  | URI for storing sent SMS messages.                                         |


## IDeliveryShortMessageCallback

Provides the callback for the SMS message sending result. Return the SMS delivery report.

**System capability**: SystemCapability.Telephony.SmsMms

| Name| Type               | Mandatory| Description          |
| ------ | ------------------- | ---- | -------------- |
| pdu    | Array&lt;number&gt; | Yes  | SMS message delivery report.|


## SendSmsResult

Enumerates SMS message sending results.

**System capability**: SystemCapability.Telephony.SmsMms

| Name                                | Value  | Description                                                  |
| ------------------------------------ | ---- | ------------------------------------------------------ |
| SEND_SMS_SUCCESS                     | 0    | SMS message sent successfully.                                        |
| SEND_SMS_FAILURE_UNKNOWN             | 1    | Failed to send the SMS message due to unknown reasons.                              |
| SEND_SMS_FAILURE_RADIO_OFF           | 2    | Failed to send the SMS message because the modem is shut down.                  |
| SEND_SMS_FAILURE_SERVICE_UNAVAILABLE | 3    | Failed to send the SMS message because the network is unavailable or SMS message sending or receiving is not supported.|
