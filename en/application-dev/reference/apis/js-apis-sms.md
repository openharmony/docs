# SMS

The SMS module provides basic SMS management functions. You can create and send SMS messages, and obtain and set the default SIM card for sending and receiving SMS messages. Besides, you can obtain and set the SMSC address, and check whether the current device can send and receive SMS messages.

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import sms from '@ohos.telephony.sms';
```

## sms.createMessage

createMessage\(pdu: Array&lt;number&gt;, specification: string, callback: AsyncCallback<ShortMessage\>\): void

Creates an SMS message instance based on the protocol data unit (PDU) and the specified SMS protocol. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name       | Type                                              | Mandatory| Description                                                        |
| ------------- | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| pdu           | Array&lt;number&gt;                                | Yes  | Protocol data unit, which is obtained from the received SMS message.                          |
| specification | string                                             | Yes  | SMS protocol type. <br>- **3gpp**: GSM/UMTS/LTE SMS<br>- **3gpp2**: CDMA SMS|
| callback      | AsyncCallback&lt;[ShortMessage](#shortmessage)&gt; | Yes  | Callback used to return the result.                                                  |

**Example**

```js
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
| pdu           | Array&lt;number&gt; | Yes  | Protocol data unit, which is obtained from the received SMS message.                          |
| specification | string              | Yes  | SMS protocol type. <br>- **3gpp**: GSM/UMTS/LTE SMS<br>- **3gpp2**: CDMA SMS|

**Return value**

| Type                                        | Description                             |
| -------------------------------------------- | --------------------------------- |
| Promise&lt;[ShortMessage](#shortmessage)&gt; | Promise used to return the result.|

**Example**

```js
const specification = '3gpp';
// Display PDUs using numbers in an array, for example, [0x08, 0x91, ...].
const pdu = [0x08, 0x91];
let promise = sms.createMessage(pdu, specification);
promise.then(data => {
    console.log(`createMessage success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`createMessage failed, promise: err->${JSON.stringify(err)}`);
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
| options | [SendMessageOptions](#sendmessageoptions) | Yes  | Options (including the callback) for sending an SMS message.|

**Example**

```js
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
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result. <br>- **0**: card slot 1<br>- **1**: card slot 2|

**Example**

```js
sms.getDefaultSmsSlotId((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getDefaultSmsSlotId<sup>7+</sup>

getDefaultSmsSlotId\(\): Promise&lt;number&gt;

Obtains the default slot of the SIM card used to send SMS messages. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.SmsMms

**Return value**

| Type           | Description                                                        |
| --------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the result.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Example**

```js
let promise = sms.getDefaultSmsSlotId();
promise.then(data => {
    console.log(`getDefaultSmsSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getDefaultSmsSlotId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.setDefaultSmsSlotId<sup>7+</sup>

setDefaultSmsSlotId\(slotId: number, callback: AsyncCallback&lt;void&gt;\): void

Sets the default slot of the SIM card used to send SMS messages. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                    | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2<br>- **-1**: clearing the default configuration|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                                                  |

**Example**

```js
sms.setDefaultSmsSlotId(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.setDefaultSmsSlotId<sup>7+</sup>

setDefaultSmsSlotId\(slotId: number\): Promise&lt;void&gt;

Sets the default slot of the SIM card used to send SMS messages. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| slotId | number | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2<br>- **-1**: clearing the default configuration|

**Return value**

| Type          | Description                           |
| -------------- | ------------------------------- |
| Promise\<void\> | Promise used to return the result. |

**Example**

```js
let promise = sms.setDefaultSmsSlotId(0);
promise.then(data => {
    console.log(`setDefaultSmsSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`setDefaultSmsSlotId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.setSmscAddr<sup>7+</sup>

setSmscAddr\(slotId: number, smscAddr: string, callback: AsyncCallback<void\>\): void

Sets the short message service center (SMSC) address. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE (a system permission)

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                     | Mandatory| Description                                     |
| -------- | ------------------------- | ---- | ----------------------------------------- |
| slotId   | number                    | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| smscAddr | string                    | Yes  | SMSC address.                       |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                               |

**Example**

```js
let slotId = 0;
let smscAddr = '+861xxxxxxxxxx';
sms.setSmscAddr(slotId, smscAddr, (err,data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.setSmscAddr<sup>7+</sup>

setSmscAddr\(slotId: number, smscAddr: string\): Promise\<void\>

Sets the SMSC address. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE (a system permission)

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type  | Mandatory| Description                                     |
| -------- | ------ | ---- | ----------------------------------------- |
| slotId   | number | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| smscAddr | string | Yes  | SMSC address.                       |

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let slotId = 0;
let smscAddr = '+861xxxxxxxxxx';
let promise = sms.setSmscAddr(slotId, smscAddr);
promise.then(data => {
    console.log(`setSmscAddr success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`setSmscAddr failed, promise: err->${JSON.stringify(err)}`);
});
```


## sms.getSmscAddr<sup>7+</sup>

getSmscAddr\(slotId: number, callback: AsyncCallback<string\>\): void

Obtains the SMSC address. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE (a system permission)

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                       | Mandatory| Description                                     |
| -------- | --------------------------- | ---- | ----------------------------------------- |
| slotId   | number                      | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result.                               |

**Example**

```js
let slotId = 0;
sms.getSmscAddr(slotId, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getSmscAddr<sup>7+</sup>

getSmscAddr\(slotId: number\): Promise<string\>

Obtains the SMSC address. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE (a system permission)

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name| Type  | Mandatory| Description                                     |
| ------ | ------ | ---- | ----------------------------------------- |
| slotId | number | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                 | Description                                         |
| --------------------- | --------------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**

```js
let slotId = 0;
let promise = sms.getSmscAddr(slotId);
promise.then(data => {
    console.log(`getSmscAddr success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getSmscAddr failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.hasSmsCapability<sup>7+</sup>

hasSmsCapability(): boolean

Checks whether the current device can send and receive SMS messages. This API returns the result synchronously.

**System capability**: SystemCapability.Telephony.SmsMms

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | - **true**: The device can send and receive SMS messages.<br>- **false**: The device cannot send or receive SMS messages.|

```js
let result = sms.hasSmsCapability(); 
console.log(`hasSmsCapability: ${JSON.stringify(result)}`);
```

## sms.splitMessage<sup>8+</sup>

splitMessage(content: string, callback: AsyncCallback<Array<string\>>): void

Splits an SMS message into multiple segments. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                         | Mandatory| Description                         |
| -------- | ----------------------------- | ---- | ----------------------------- |
| content  | string                        | Yes  | SMS message content. The value cannot be null.|
| callback | AsyncCallback<Array<string\>> | Yes  | Callback used to return the result.                   |

**Example**

```js
let content = "long message";
sms.splitMessage(content, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.splitMessage<sup>8+</sup>

splitMessage(content: string): Promise<Array<string\>>

Splits an SMS message into multiple segments. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name | Type  | Mandatory| Description                        |
| ------- | ------ | ---- | ---------------------------- |
| content | string | Yes  | SMS message content. The value cannot be null.|

**Return value**

| Type                   | Description                               |
| ----------------------- | ----------------------------------- |
| Promise<Array<string\>> | Promise used to return the result.|

**Example**

```js
let content = "long message";
let promise = sms.splitMessage(content);
promise.then(data => {
    console.log(`splitMessage success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`splitMessage failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.addSimMessage<sup>7+</sup>

addSimMessage(options: SimMessageOptions, callback: AsyncCallback<void\>): void

Adds a SIM message. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.RECEIVE_SMS,ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                                    | Mandatory| Description           |
| -------- | ---------------------------------------- | ---- | --------------- |
| options  | [SimMessageOptions](#simmessageoptions7) | Yes  | SIM message options.|
| callback | AsyncCallback&lt;void&gt;                | Yes  | Callback used to return the result.     |

**Example**

```js
let simMessageOptions = {
    slotId: 0,
    smsc: "test",
    pdu: "xxxxxx",
    status: sms.SimMessageStatus.SIM_MESSAGE_STATUS_READ
};
sms.addSimMessage(simMessageOptions, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.addSimMessage<sup>7+</sup>

addSimMessage(options: SimMessageOptions): Promise<void\>

Adds a SIM message. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.RECEIVE_SMS,ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name | Type                                    | Mandatory| Description           |
| ------- | ---------------------------------------- | ---- | --------------- |
| options | [SimMessageOptions](#simmessageoptions7) | Yes  | SIM message options.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; |  Promise used to return the result.|

**Example**

```js
let simMessageOptions = {
    slotId: 0,
    smsc: "test",
    pdu: "xxxxxx",
    status: sms.SimMessageStatus.SIM_MESSAGE_STATUS_READ
};
let promise = sms.addSimMessage(simMessageOptions);
promise.then(data => {
    console.log(`addSimMessage success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`addSimMessage failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.delSimMessage<sup>7+</sup>

delSimMessage(slotId: number, msgIndex: number, callback: AsyncCallback<void\>): void

Deletes a SIM message. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.RECEIVE_SMS,ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                     | Mandatory| Description                                     |
| -------- | ------------------------- | ---- | ----------------------------------------- |
| slotId   | number                    | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| msgIndex | number                    | Yes  | Message index.                                 |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                               |

**Example**

```js
let slotId = 0;
let msgIndex = 1;
sms.delSimMessage(slotId, msgIndex, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.delSimMessage<sup>7+</sup>

delSimMessage(slotId: number, msgIndex: number): Promise<void\>

Deletes a SIM message. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.RECEIVE_SMS,ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type  | Mandatory| Description                                     |
| -------- | ------ | ---- | ----------------------------------------- |
| slotId   | number | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| msgIndex | number | Yes  | Message index.                                 |

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; |  Promise used to return the result.|

**Example**

```js
let slotId = 0;
let msgIndex = 1;
let promise = sms.delSimMessage(slotId, msgIndex);
promise.then(data => {
    console.log(`delSimMessage success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`delSimMessage failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.updateSimMessage<sup>7+</sup>

updateSimMessage(options: UpdateSimMessageOptions, callback: AsyncCallback<void\>): void

Updates a SIM message. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.RECEIVE_SMS,ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                                                | Mandatory| Description               |
| -------- | ---------------------------------------------------- | ---- | ------------------- |
| options  | [UpdateSimMessageOptions](#updatesimmessageoptions7) | Yes  | SIM message updating options.|
| callback | AsyncCallback&lt;void&gt;                            | Yes  | Callback used to return the result.         |

**Example**

```js
let updateSimMessageOptions = {
    slotId: 0,
    msgIndex: 1,
    newStatus: sms.SimMessageStatus.SIM_MESSAGE_STATUS_FREE,
    pdu: "xxxxxxx",
    smsc: "test"
};
sms.updateSimMessage(updateSimMessageOptions, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.updateSimMessage<sup>7+</sup>

updateSimMessage(options: UpdateSimMessageOptions): Promise<void\>

Updates a SIM message. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.RECEIVE_SMS,ohos.permission.SEND_MESSAGES

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name | Type                                                | Mandatory| Description               |
| ------- | ---------------------------------------------------- | ---- | ------------------- |
| options | [UpdateSimMessageOptions](#updatesimmessageoptions7) | Yes  | SIM message updating options.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let updateSimMessageOptions = {
    slotId: 0,
    msgIndex: 1,
    newStatus: sms.SimMessageStatus.SIM_MESSAGE_STATUS_FREE,
    pdu: "xxxxxxx",
    smsc: "test"
};
let promise = sms.updateSimMessage(updateSimMessageOptions);
promise.then(data => {
    console.log(`updateSimMessage success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`updateSimMessage failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.getAllSimMessages<sup>7+</sup>

getAllSimMessages(slotId: number, callback: AsyncCallback<Array<SimShortMessage\>>): void

Obtains all SIM card messages. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.RECEIVE_SMS

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                     |
| -------- | ----------------------------------------------------------- | ---- | ----------------------------------------- |
| slotId   | number                                                      | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback<Array<[SimShortMessage](#simshortmessage7)\>> | Yes  | Callback used to return the result.                               |

**Example**

```js
let slotId = 0;
sms.getAllSimMessages(slotId, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getAllSimMessages<sup>7+</sup>

getAllSimMessages(slotId: number): Promise<Array<SimShortMessage\>>

Obtains all SIM card messages. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.RECEIVE_SMS

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name| Type  | Mandatory| Description                                     |
| ------ | ------ | ---- | ----------------------------------------- |
| slotId | number | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                                                   | Description                              |
| ------------------------------------------------------- | ---------------------------------- |
| PromiseArray<[SimShortMessage](#simshortmessage7)\>&gt; | Promise used to return the result.|

**Example**

```js
let slotId = 0;
let promise = sms.getAllSimMessages(slotId);
promise.then(data => {
    console.log(`getAllSimMessages success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getAllSimMessages failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.setCBConfig<sup>7+</sup>

setCBConfig(options: CBConfigOptions, callback: AsyncCallback<void\>): void

Sets the cell broadcast configuration. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.RECEIVE_SMS

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                                | Mandatory| Description        |
| -------- | ------------------------------------ | ---- | ------------ |
| options  | [CBConfigOptions](#cbconfigoptions7) | Yes  | Cell broadcast configuration options.|
| callback | AsyncCallback&lt;void&gt;            | Yes  | Callback used to return the result.  |

**Example**

```js
let cbConfigOptions = {
    slotId: 0,
    enable: true,
    startMessageId: 100,
    endMessageId: 200,
    ranType: sms.RanType.TYPE_GSM
};
sms.setCBConfig(cbConfigOptions, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.setCBConfig<sup>7+</sup>

setCBConfig(options: CBConfigOptions): Promise<void\>

Sets the cell broadcast configuration. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.RECEIVE_SMS

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name | Type                                | Mandatory| Description        |
| ------- | ------------------------------------ | ---- | ------------ |
| options | [CBConfigOptions](#cbconfigoptions7) | Yes  | Cell broadcast configuration options.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let cbConfigOptions = {
    slotId: 0,
    enable: true,
    startMessageId: 100,
    endMessageId: 200,
    ranType: sms.RanType.TYPE_GSM
};
let promise = sms.setCBConfig(cbConfigOptions);
promise.then(data => {
    console.log(`setCBConfig success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`setCBConfig failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.getSmsSegmentsInfo<sup>8+</sup>

getSmsSegmentsInfo(slotId: number, message: string, force7bit: boolean, callback: AsyncCallback<SmsSegmentsInfo\>): void

Obtains SMS message segment information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name   | Type                                                        | Mandatory| Description                                     |
| --------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| slotId    | number                                                       | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| message   | string                                                       | Yes  | SMS message.                                     |
| force7bit | boolean                                                      | Yes  | Whether to use 7-bit coding.                         |
| callback  | | Yes  | Callback used to return the result.                                 |

**Example**

```js
let slotId = 0;
sms.getSmsSegmentsInfo(slotId, "message", false, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getSmsSegmentsInfo<sup>8+</sup>

getSmsSegmentsInfo(slotId: number, message: string, force7bit: boolean): Promise<SmsSegmentsInfo\>

Obtains SMS message segment information. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name   | Type   | Mandatory| Description                                     |
| --------- | ------- | ---- | ----------------------------------------- |
| slotId    | number  | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|
| message   | string  | Yes  | Message                                     |
| force7bit | boolean | Yes  | Whether to use 7-bit coding.                         |

**Return value**

| Type                                                   | Description                         |
| ------------------------------------------------------- | ----------------------------- |
| | Promise used to return the result.|

**Example**

```js
let slotId = 0;
let promise = sms.getSmsSegmentsInfo(slotId, "message", false);
promise.then(data => {
    console.log(`getSmsSegmentsInfo success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getSmsSegmentsInfo failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.isImsSmsSupported<sup>8+</sup>

isImsSmsSupported(callback: AsyncCallback<boolean\>): void

Checks whether SMS is supported on IMS. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                        | Mandatory| Description      |
| -------- | ---------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.|

**Example**

```js
sms.isImsSmsSupported((err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.isImsSmsSupported<sup>8+</sup>

isImsSmsSupported(): Promise<boolean\>

Checks whether SMS is supported on IMS. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Return value**

| Type                  | Description                   |
| ---------------------- | ----------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

```js
let promise = sms.isImsSmsSupported();
promise.then(data => {
    console.log(`isImsSmsSupported success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`isImsSmsSupported failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.getImsShortMessageFormat<sup>8+</sup>

getImsShortMessageFormat(callback: AsyncCallback<string\>): void

Obtains the SMS format supported by the IMS. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                       | Mandatory| Description      |
| -------- | --------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result.|

**Example**

```js
sms.getImsShortMessageFormat((err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.getImsShortMessageFormat<sup>8+</sup>

getImsShortMessageFormat(): Promise<string\>

Obtains the SMS format supported by the IMS. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Return value**

| Type                 | Description                      |
| --------------------- | -------------------------- |
| Promise&lt;string&gt; | Promise used to return the result. |

**Example**

```js
let promise = sms.getImsShortMessageFormat();
promise.then(data => {
    console.log(`getImsShortMessageFormat success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getImsShortMessageFormat failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.decodeMms<sup>8+</sup>

decodeMms(mmsFilePathName: string | Array<number\>, callback: AsyncCallback<MmsInformation\>): void

Decodes MMS messages. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name         | Type                                                   | Mandatory| Description          |
| --------------- | ------------------------------------------------------- | ---- | -------------- |
| mmsFilePathName | string \|Array<number\>                                 | Yes  | MMS message file path.|
| callback        | AsyncCallback&lt;[MmsInformation](#mmsinformation8)&gt; | Yes  | Callback used to return the result.    |

**Example**

```js
let mmsFilePathName = "filename";
sms.decodeMms(mmsFilePathName, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.decodeMms<sup>8+</sup>

decodeMms(mmsFilePathName: string | Array<number\>): Promise<MmsInformation\>

Decodes MMS messages. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name         | Type                   | Mandatory| Description          |
| --------------- | ----------------------- | ---- | -------------- |
| mmsFilePathName | string \|Array<number\> | Yes  | MMS message file path.|

**Return value**

| Type                                                     | Description                       |
| --------------------------------------------------------- | --------------------------- |
| Promise&lt;&lt;[MmsInformation](#mmsinformation8)&gt;&gt; | Promise used to return the result.|

**Example**

```js
let mmsFilePathName = "filename";
let promise = sms.decodeMms(mmsFilePathName);
promise.then(data => {
    console.log(`decodeMms success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`decodeMms failed, promise: err->${JSON.stringify(err)}`);
});
```

## sms.encodeMms<sup>8+</sup>

encodeMms(mms: MmsInformation, callback: AsyncCallback<Array<number\>>): void

Encodes MMS messages. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name  | Type                               | Mandatory| Description      |
| -------- | ----------------------------------- | ---- | ---------- |
| mms      | [MmsInformation](#mmsinformation8)  | Yes  | MMS message information.|
| callback | AsyncCallback&lt;Array<number\>&gt; | Yes  | Callback used to return the result.|

**Example**

```js
let mmsAcknowledgeInd = {
    transactionId: "100",
    version: sms.MmsVersionType.MMS_VERSION_1_0,
    reportAllowed: sms.ReportType.MMS_YES
};
let mmsInformation = {
    messageType: sms.MessageType.TYPE_MMS_ACKNOWLEDGE_IND,
    mmsType: mmsAcknowledgeInd
};
sms.encodeMms(mmsInformation, (err, data) => {
      console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sms.encodeMms<sup>8+</sup>

encodeMms(mms: MmsInformation): Promise<Array<number\>>

Encodes MMS messages. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

**Parameters**

| Name| Type                              | Mandatory| Description      |
| ------ | ---------------------------------- | ---- | ---------- |
| mms    | [MmsInformation](#mmsinformation8) | Yes  | MMS message information.|

**Return value**

| Type                         | Description                               |
| ----------------------------- | ----------------------------------- |
| Promise&lt;Array<number\>&gt; | Promise used to return the result.|

**Example**

```js
let mmsAcknowledgeInd = {
    transactionId: "100",
    version: sms.MmsVersionType.MMS_VERSION_1_0,
    reportAllowed: sms.ReportType.MMS_YES
};
let mmsInformation = {
    messageType: sms.MessageType.TYPE_MMS_ACKNOWLEDGE_IND,
    mmsType: mmsAcknowledgeInd
};
let promise = sms.encodeMms(mmsInformation);
promise.then(data => {
    console.log(`encodeMms success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`encodeMms failed, promise: err->${JSON.stringify(err)}`);
});
```

## ShortMessage

Defines an SMS message instance.

**System capability**: SystemCapability.Telephony.SmsMms

| Name                  | Type                                   | Description                                                        |
| ------------------------ | --------------------------------------- | ------------------------------------------------------------ |
| hasReplyPath             | boolean                                 | Whether the received SMS contains **TP-Reply-Path**. The default value is **false**.<br>**TP-Reply-Path**: The device returns a response based on the SMSC that sends the SMS message.|
| isReplaceMessage         | boolean                                 | Whether the received SMS message is a **replace short message**. The default value is **false**.<br>For details, see section 9.2.3.9 in **3GPP TS 23.040**.|
| isSmsStatusReportMessage | boolean                                 | Whether the received SMS message is an SMS delivery status report. The default value is **false**.<br>**SMS-Status-Report**: a message sent from the SMSC to the mobile station to show the SMS message delivery status.|
| messageClass             | [ShortMessageClass](#shortmessageclass) | Enumerates SMS message types.                                                  |
| pdu                      | Array&lt;number&gt;                     | PDU in the SMS message.                           |
| protocolId               | number                                  | Protocol identifier used for delivering the SMS message.                                  |
| scAddress                | string                                  | SMSC address.                                |
| scTimestamp              | number                                  | SMSC timestamp.                                                |
| status                   | number                                  | SMS message status sent by the SMSC in the **SMS-STATUS-REPORT** message.|
| visibleMessageBody       | string                                  | SMS message body.                                                  |
| visibleRawAddress        | string                                  | Sender address.                                                |


## ShortMessageClass

Enumerates SMS message types.

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
| url        | string                          | Yes  | URI for storing the sent SMS message.                                         |


## IDeliveryShortMessageCallback

Provides the callback for  the SMS message delivery report.

**System capability**: SystemCapability.Telephony.SmsMms

| Name| Type               | Mandatory| Description          |
| ------ | ------------------- | ---- | -------------- |
| pdu    | Array&lt;number&gt; | Yes  | SMS message delivery report.|


## SendSmsResult

Enumerates SMS message sending results.

**System capability**: SystemCapability.Telephony.SmsMms

| Name                                | Value  | Description                                                  |
| ------------------------------------ | ---- | ------------------------------------------------------ |
| SEND_SMS_SUCCESS                     | 0    | The SMS message is sent successfully.                                        |
| SEND_SMS_FAILURE_UNKNOWN             | 1    | Failed to send the SMS message due to an unknown reason.                              |
| SEND_SMS_FAILURE_RADIO_OFF           | 2    | Failed to send the SMS message because the modem is shut down.                  |
| SEND_SMS_FAILURE_SERVICE_UNAVAILABLE | 3    | Failed to send the SMS message because the network is unavailable or SMS message sending or receiving is not supported.|


## MmsInformation<sup>8+</sup>

Defines the MMS message information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name     | Type                                                        | Mandatory| Description     |
| ----------- | ------------------------------------------------------------ | ---- | --------- |
| messageType | [MessageType](#messagetype8)                                 | Yes  | Message type. |
| mmsType     | [MmsSendReq](#mmssendreq8) \|[MmsSendConf](#mmssendconf8) \|[MmsNotificationInd](#mmsnotificationind8) \|[MmsRespInd](#mmsrespind8) \|[MmsRetrieveConf](#mmsretrieveconf8)\|[MmsAcknowledgeInd](#mmsacknowledgeind8)\|[MmsDeliveryInd](#mmsdeliveryind8)\|[MmsReadOrigInd](#mmsreadorigind8)\|[MmsReadRecInd](#mmsreadrecind8)| Yes  | PDU header type.|
| attachment  | Array<[MmsAttachment](#mmsattachment8)\>                     | No  | Attachment.     |

## MmsSendReq<sup>8+</sup>

Defines an MMS message sending request.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name          | Type                                | Mandatory| Description        |
| ---------------- | ------------------------------------ | ---- | ------------ |
| from             | [MmsAddress](#mmsaddress8)           | Yes  | MMS message source.    |
| transactionId    | string                               | Yes  | Transaction ID.      |
| contentType      | string                               | Yes  | Content type.    |
| version          | [MmsVersionType](#mmsversiontype8)   | Yes  | Version.        |
| to               | Array<[MmsAddress](#mmsaddress8)\>   | No  | Address to which the message is sent.      |
| date             | number                               | No  | Date.        |
| cc               | Array<[MmsAddress](#mmsaddress8)\>   | No  | Carbon copy.        |
| bcc              | Array<[MmsAddress](#mmsaddress8)\>   | No  | Blind carbon copy.      |
| subject          | string                               | No  | Subject.        |
| messageClass     | number                               | No  | Message class.      |
| expiry           | number                               | No  | Expiration.        |
| priority         | [MmsPriorityType](#mmsprioritytype8) | No  | Priority.        |
| senderVisibility | number                               | No  | Sender visibility.|
| deliveryReport   | number                               | No  | Delivery report.    |
| readReport       | number                               | No  | Read report.    |

## MmsSendConf<sup>8+</sup>

Defines the MMS message sending configuration.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name       | Type                              | Mandatory| Description    |
| ------------- | ---------------------------------- | ---- | -------- |
| responseState | number                             | Yes  | Response status.|
| transactionId | string                             | Yes  | Transaction ID.  |
| version       | [MmsVersionType](#mmsversiontype8) | Yes  | Version.    |
| messageId     | string                             | No  | Message ID.  |

## MmsNotificationInd<sup>8+</sup>

Defines an MMS notification index.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name         | Type                              | Mandatory| Description    |
| --------------- | ---------------------------------- | ---- | -------- |
| transactionId   | string                             | Yes  | Transaction ID.  |
| messageClass    | number                             | Yes  | Message class.  |
| messageSize     | number                             | Yes  | Message size.|
| expiry          | number                             | Yes  | Expiration.    |
| contentLocation | string                             | Yes  | Content location.|
| version         | [MmsVersionType](#mmsversiontype8) | Yes  | Version.    |
| from            | [MmsAddress](#mmsaddress8)         | No  | Source.    |
| subject         | string                             | No  | Subject.    |
| deliveryReport  | number                             | No  | Status report.|
| contentClass    | number                             | No  | Content class.  |

## MmsAcknowledgeInd<sup>8+</sup>

Defines an MMS confirmation index.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name       | Type                              | Mandatory| Description    |
| ------------- | ---------------------------------- | ---- | -------- |
| transactionId | string                             | Yes  | Transaction ID.  |
| version       | [MmsVersionType](#mmsversiontype8) | Yes  | Version.    |
| reportAllowed | [ReportType](#reporttype8)         | No  | Report allowed.|

## MmsRetrieveConf<sup>8+</sup>

Defines the MMS message retrieval configuration.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name        | Type                                | Mandatory| Description    |
| -------------- | ------------------------------------ | ---- | -------- |
| transactionId  | string                               | Yes  | Transaction ID.  |
| messageId      | string                               | Yes  | Message ID.  |
| date           | number                               | Yes  | Date.    |
| contentType    | string                               | Yes  | Content type.|
| to             | Array<[MmsAddress](#mmsaddress8)\>   | Yes  | Address to which the message is sent.  |
| version        | [MmsVersionType](#mmsversiontype8)   | Yes  | Version    |
| from           | [MmsAddress](#mmsaddress8)           | No  | Source.    |
| cc             | Array<[MmsAddress](#mmsaddress8)\>   | No  | Carbon copy.    |
| subject        | string                               | No  | Subject.    |
| priority       | [MmsPriorityType](#mmsprioritytype8) | No  | Priority.  |
| deliveryReport | number                               | No  | Status report.|
| readReport     | number                               | No  | Read report.|
| retrieveStatus | number                               | No  | Retrieval status.|
| retrieveText   | string                               | No  | Retrieval text.|

## MmsReadOrigInd<sup>8+</sup>

Defines the original MMS message reading index.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name    | Type                              | Mandatory| Description    |
| ---------- | ---------------------------------- | ---- | -------- |
| version    | [MmsVersionType](#mmsversiontype8) | Yes  | Version.    |
| messageId  | string                             | Yes  | Message ID.  |
| to         | Array<[MmsAddress](#mmsaddress8)\> | Yes  | Address to which the message is sent.  |
| from       | [MmsAddress](#mmsaddress8)         | Yes  | Source.    |
| date       | number                             | Yes  | Date.    |
| readStatus | number                             | Yes  | Read status.|


## MmsReadRecInd<sup>8+</sup>

Defines the MMS message reading index.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name    | Type                              | Mandatory| Description    |
| ---------- | ---------------------------------- | ---- | -------- |
| version    | [MmsVersionType](#mmsversiontype8) | Yes  | Version    |
| messageId  | string                             | Yes  | Message ID.  |
| to         | Array<[MmsAddress](#mmsaddress8)\> | Yes  | Destination.  |
| from       | [MmsAddress](#mmsaddress8)         | Yes  | Source.    |
| readStatus | number                             | Yes  | Read state.|
| date       | number                             | No  | Date.    |


## MmsAttachment<sup>8+</sup>

Defines the attachment of an MMS message.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name                 | Type                                | Mandatory| Description              |
| ----------------------- | ------------------------------------ | ---- | ------------------ |
| contentId               | string                               | Yes  | Content ID.            |
| contentLocation         | string                               | Yes  | Content location.          |
| contentDisposition      | [DispositionType](#dispositiontype8) | Yes  | Content disposition.          |
| contentTransferEncoding | string                               | Yes  | Encoding for content transfer.      |
| contentType             | string                               | Yes  | Content type.          |
| isSmil                  | boolean                              | Yes  | Whether the synchronized multimedia integration language is used.|
| path                    | string                               | No  | Path.              |
| inBuff                  | Array<number\>                       | No  | In the buffer          |
| fileName                | string                               | No  | File name.            |
| charset                 | [MmsCharSets](#mmscharsets8)         | No  | Character set.            |

## MmsAddress<sup>8+</sup>

Defines an MMSC address.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name | Type                        | Mandatory| Description  |
| ------- | ---------------------------- | ---- | ------ |
| address | string                       | Yes  | MMSC address.  |
| charset | [MmsCharSets](#mmscharsets8) | Yes  | Character set.|

## MessageType<sup>8+</sup>

Enumerates message types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name                   | Value  | Description                |
| ------------------------- | ---- | -------------------- |
| TYPE_MMS_SEND_REQ         | 128  | MMS message sending request.    |
| TYPE_MMS_SEND_CONF        | 129  | MMS message sending configuration.    |
| TYPE_MMS_NOTIFICATION_IND | 130  | MMS notification index.    |
| TYPE_MMS_RESP_IND         | 131  | MMS message response index.    |
| TYPE_MMS_RETRIEVE_CONF    | 132  | MMS message retrieval configuration.    |
| TYPE_MMS_ACKNOWLEDGE_IND  | 133  | MMS message acknowledgement index.    |
| TYPE_MMS_DELIVERY_IND     | 134  | MMS message delivery index.    |
| TYPE_MMS_READ_REC_IND     | 135  | MMS message reading and receiving index.|
| TYPE_MMS_READ_ORIG_IND    | 136  | Original MMS message reading index.|

## MmsPriorityType<sup>8+</sup>

Enumerates MMS message priorities.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name    | Value  | Description          |
| ---------- | ---- | -------------- |
| MMS_LOW    | 128  | Low priority.  |
| MMS_NORMAL | 129  | Normal priority.|
| MMS_HIGH   | 130  | High priority.  |

## MmsVersionType<sup>8+</sup>

Enumerates MMS versions.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name         | Value  | Description       |
| --------------- | ---- | ----------- |
| MMS_VERSION_1_0 | 0x10 | MMS version 1_0.|
| MMS_VERSION_1_1 | 0x11 | MMS version 1_1.|
| MMS_VERSION_1_2 | 0x12 | MMS version 1_2.|
| MMS_VERSION_1_3 | 0x13 | MMS version 1_3.|

## MmsCharSets<sup>8+</sup>

Enumerates MMS character sets.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name         | Value    | Description               |
| --------------- | ------ | ------------------- |
| BIG5            | 0X07EA | BIG5 format.           |
| ISO_10646_UCS_2 | 0X03E8 | ISO_10646_UCS_2 format.|
| ISO_8859_1      | 0X04   | ISO_8859_1 format.     |
| ISO_8859_2      | 0X05   | ISO_8859_2 format.     |
| ISO_8859_3      | 0X06   | ISO_8859_3 format.     |
| ISO_8859_4      | 0X07   | ISO_8859_4 format.     |
| ISO_8859_5      | 0X08   | ISO_8859_5 format.     |
| ISO_8859_6      | 0X09   | ISO_8859_6 format.     |
| ISO_8859_7      | 0X0A   | ISO_8859_7 format.     |
| ISO_8859_8      | 0X0B   | ISO_8859_8 format.     |
| ISO_8859_9      | 0X0C   | ISO_8859_9 format.     |
| SHIFT_JIS       | 0X11   | SHIFT_JIS format.      |
| US_ASCII        | 0X03   | US_ASCII format.       |
| UTF_8           | 0X6A   | UTF_8 format.          |

## DispositionType<sup>8+</sup>

Enumerates disposition types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name    | Value  | Description    |
| ---------- | ---- | -------- |
| FROM_DATA  | 0    | Data source.|
| ATTACHMENT | 1    | Attachment.    |
| INLINE     | 2    | Inlining.    |

## ReportType<sup>8+</sup>

Enumerates report types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name | Value  | Description|
| ------- | ---- | ---- |
| MMS_YES | 128  | YES  |
| MMS_NO  | 129  | NO   |

## CBConfigOptions<sup>7+</sup>

Defines the cell broadcast configuration options.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name        | Type                | Mandatory| Description        |
| -------------- | -------------------- | ---- | ------------ |
| slotId         | number               | Yes  | Card slot ID.      |
| enable         | boolean              | Yes  | Whether to enable cell broadcast.        |
| startMessageId | number               | Yes  | Start message ID.  |
| endMessageId   | number               | Yes  | End message ID.  |
| ranType        | [RanType](#rantype7) | Yes  | RAN type.|

## SimMessageStatus<sup>7+</sup>

Defines the SIM message status.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name                   | Value  | Description                       |
| ------------------------- | ---- | --------------------------- |
| SIM_MESSAGE_STATUS_FREE   | 0    | Free state.      |
| SIM_MESSAGE_STATUS_READ   | 1    | Read state.               |
| SIM_MESSAGE_STATUS_UNREAD | 3    | Unread state.               |
| SIM_MESSAGE_STATUS_SENT   | 5    | Storage of sent messages (applicable only to SMS).|
| SIM_MESSAGE_STATUS_UNSENT | 7    | Storage of unsent messages (applicable only to SMS).|

## RanType<sup>7+</sup>

Enumerates RAN types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name   | Value  | Description|
| --------- | ---- | ---- |
| TYPE_GSM  | 1    | GSM  |
| TYPE_CDMA | 2    | CMDA |

## SmsEncodingScheme<sup>8+</sup>

Enumerates SMS encoding schemes.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name              | Value  | Description        |
| -------------------- | ---- | ------------ |
| SMS_ENCODING_UNKNOWN | 0    | Unknown code.|
| SMS_ENCODING_7BIT    | 1    | 7-digit code. |
| SMS_ENCODING_8BIT    | 2    | 8-digit code. |
| SMS_ENCODING_16BIT   | 3    | 16-digit code.|

## SimMessageOptions<sup>7+</sup>

Defines the SIM message options.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name| Type                                  | Mandatory| Description          |
| ------ | -------------------------------------- | ---- | -------------- |
| slotId | number                                 | Yes  | Card slot ID.        |
| smsc   | string                                 | Yes  | Short message service center.|
| pdu    | string                                 | Yes  | Protocol data unit.  |
| status | [SimMessageStatus](#simmessagestatus7) | Yes  | Message status.          |

## UpdateSimMessageOptions<sup>7+</sup>

Defines the updating SIM message options.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name   | Type                                  | Mandatory| Description          |
| --------- | -------------------------------------- | ---- | -------------- |
| slotId    | number                                 | Yes  | Card slot ID.        |
| msgIndex  | number                                 | Yes  | Message index.      |
| newStatus | [SimMessageStatus](#simmessagestatus7) | Yes  | New status.        |
| pdu       | string                                 | Yes  | Protocol data unit.  |
| smsc      | string                                 | Yes  | Short message service center.|

## SimShortMessage<sup>7+</sup>

Defines a SIM message.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name          | Type                                  | Mandatory| Description         |
| ---------------- | -------------------------------------- | ---- | ------------- |
| shortMessage     | [ShortMessage](#shortmessage)          | Yes  | SMS message.       |
| simMessageStatus | [SimMessageStatus](#simmessagestatus7) | Yes  | SIM message status.|
| indexOnSim       | number                                 | Yes  | SIM card index.    |

## MmsDeliveryInd<sup>8+</sup>

Defines an MMS message delivery index.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name   | Type                              | Mandatory| Description  |
| --------- | ---------------------------------- | ---- | ------ |
| messageId | string                             | Yes  | Message ID.|
| date      | number                             | Yes  | Date.  |
| to        | Array<[MmsAddress](#mmsaddress8)\> | Yes  | Address to which the message is sent.|
| status    | number                             | Yes  | Status.  |
| version   | [MmsVersionType](#mmsversiontype8) | Yes  | Version.  |

## MmsRespInd<sup>8+</sup>

Defines an MMS response index.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name       | Type                              | Mandatory| Description    |
| ------------- | ---------------------------------- | ---- | -------- |
| transactionId | string                             | Yes  | Event ID.  |
| status        | number                             | Yes  | Status.    |
| version       | [MmsVersionType](#mmsversiontype8) | Yes  | Version.    |
| reportAllowed | [ReportType](#reporttype8)         | No  | Report allowed.|

## SmsSegmentsInfo<sup>8+</sup>

Defines the SMS message segment information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.SmsMms

| Name              | Type                                    | Mandatory| Description        |
| -------------------- | ---------------------------------------- | ---- | ------------ |
| splitCount           | number                                   | Yes  | Split count.    |
| encodeCount          | number                                   | Yes  | Encoding count.    |
| encodeCountRemaining | number                                   | Yes  | Remaining encoding count.|
| scheme               | [SmsEncodingScheme](#smsencodingscheme8) | Yes  | Encoding scheme.|
