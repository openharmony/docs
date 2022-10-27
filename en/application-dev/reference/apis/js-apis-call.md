# Call

The call module provides call management functions, including making calls, redirecting to the dial screen, obtaining the call status, and formatting phone numbers.

To subscribe to the call status, use [`observer.on('callStateChange')`](js-apis-observer.md#observeroncallstatechange).

>**NOTE**<br>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import call from '@ohos.telephony.call';
```

## call.dial

dial\(phoneNumber: string, callback: AsyncCallback<boolean\>\): void

Initiates a call. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.PLACE\_CALL (a system permission)

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                        | Mandatory | Description |
| ----------- | ---------------------------- | ---- | -------------------------------- |
| phoneNumber | string                        | Yes  | Phone number.  |
| callback    | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.<br>- **true**: success<br>- **false**: failure |

**Example**

```js
call.dial("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.dial

dial\(phoneNumber: string, options: DialOptions, callback: AsyncCallback<boolean\>\): void

Initiates a call based on the specified options. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.PLACE\_CALL (a system permission)

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                        | Mandatory | Description                             |
| ----------- | ---------------------------- | ---- | --------------------------------------- |
| phoneNumber | string                       | Yes  | Phone number.                           |
| options     | [DialOptions](#dialoptions)  | Yes  | Call option, which indicates whether the call is a voice call or video call. |
| callback    | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.<br>- **true**: success<br>- **false**: failure |

**Example**

```js
call.dial("138xxxxxxxx", {
    extras: false
}, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.dial

dial\(phoneNumber: string, options?: DialOptions\): Promise<boolean\>

Initiates a call based on the specified options. This API uses a promise to return the result.

**Required permission**: ohos.permission.PLACE\_CALL (a system permission)

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                       | Mandatory | Description                            |
| ----------- | --------------------------- | ---- | -------------------------------------- |
| phoneNumber | string                      | Yes  | Phone number.                          |
| options     | [DialOptions](#dialoptions) | Yes  | Call option, which indicates whether the call is a voice call or video call. |

**Return value**

| Type                   | Description                                                       |
| ---------------------- | ---------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.<br>- **true**: success<br>- **false**: failure |

**Example**

```js
let promise = call.dial("138xxxxxxxx", {
    extras: false
});
promise.then(data => {
    console.log(`dial success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`dial fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.makeCall<sup>7+</sup>

makeCall(phoneNumber: string, callback: AsyncCallback\<void\>): void

Launches the call screen and displays the dialed number. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Applications.Contacts

**Parameters**

| Name     | Type                     | Mandatory | Description                                      |
| ----------- | ------------------------- | ---- | ------------------------------------------ |
| phoneNumber | string                    | Yes  | Phone number.                                |
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. |

**Example**

```js
call.makeCall("138xxxxxxxx", err => { 
    console.log(`makeCall callback: err->${JSON.stringify(err)}`); 
});
```


## call.makeCall<sup>7+</sup>

makeCall(phoneNumber: string): Promise\<void\>

Launches the call screen and displays the dialed number. This API uses a promise to return the result.

**System capability**: SystemCapability.Applications.Contacts

**Parameters**

| Name     | Type  | Mandatory | Description      |
| ----------- | ------ | ---- | ---------- |
| phoneNumber | string | Yes  | Phone number. |

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result. |

**Example**

```js
let promise = call.makeCall("138xxxxxxxx"); 
promise.then(() => { 
    console.log(`makeCall success`); 
}).catch(err => { 
    console.error(`makeCall fail, promise: err->${JSON.stringify(err)}`); 
});
```

## call.hasCall

hasCall\(callback: AsyncCallback<boolean\>\): void

Checks whether a call is in progress. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                        | Mandatory | Description                                                        |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. Callback used to return the result.<br>- **true**: A call is in progress.<br>- **false**: No call is in progress. |

**Example**

```js
call.hasCall((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.hasCall

hasCall\(\): Promise<boolean\>

Checks whether a call is in progress. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type                  | Description                                   |
| ---------------------- | --------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. |

**Example**

```js
let promise = call.hasCall();
promise.then(data => {
    console.log(`hasCall success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`hasCall fail, promise: err->${JSON.stringify(err)}`);
});
```


## call.getCallState

getCallState\(callback: AsyncCallback<CallState\>\): void

Obtains the call status. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                        | Mandatory | Description                                |
| -------- | -------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback&lt;[CallState](#callstate)&gt; | Yes  | Callback used to return the result. |

**Example**

```js
call.getCallState((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.getCallState

getCallState\(\): Promise<CallState\>

Obtains the call status. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type                                  | Description                                   |
| -------------------------------------- | --------------------------------------- |
| Promise&lt;[CallState](#callstate)&gt; | Promise used to return the result. |

**Example**

```js
let promise = call.getCallState();
promise.then(data => {
    console.log(`getCallState success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getCallState fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.hasVoiceCapability<sup>7+</sup>

hasVoiceCapability(): boolean

Checks whether a device supports voice calls.

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | - **true**: The device supports voice calls.<br>- **false**: The device does not support voice calls. |

```js
let result = call.hasVoiceCapability(); 
console.log(`hasVoiceCapability: ${JSON.stringify(result)}`);
```

## call.isEmergencyPhoneNumber<sup>7+</sup>

isEmergencyPhoneNumber\(phoneNumber: string, callback: AsyncCallback<boolean\>\): void

Checks whether the called number is an emergency number. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                        | Mandatory | Description                                                        |
| ----------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                       | Yes  | Phone number.                                                  |
| callback    | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.<br> - **true**: The called number is an emergency number.<br>- **false**: The called number is not an emergency number. |

**Example**

```js
call.isEmergencyPhoneNumber("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.isEmergencyPhoneNumber<sup>7+</sup>

isEmergencyPhoneNumber\(phoneNumber: string, options: EmergencyNumberOptions, callback: AsyncCallback<boolean\>\): void

Checks whether the called number is an emergency number based on the specified phone number options. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                                              | Mandatory | Description                                                       |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| phoneNumber | string                                             | Yes  | Phone number.                                                 |
| options     | [EmergencyNumberOptions](#emergencynumberoptions7) | Yes  | Phone number options.        |
| callback    | AsyncCallback&lt;boolean&gt;                       | Yes  | Callback used to return the result.<br> - **true**: The called number is an emergency number.<br>- **false**: The called number is not an emergency number. |

**Example**

```js
call.isEmergencyPhoneNumber("112", {slotId: 1}, (err, value) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.isEmergencyPhoneNumber<sup>7+</sup>

isEmergencyPhoneNumber\(phoneNumber: string, options?: EmergencyNumberOptions\): Promise<boolean\>

Checks whether the called number is an emergency number based on the specified phone number options. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                                              | Mandatory | Description          |
| ----------- | -------------------------------------------------- | ---- | -------------- |
| phoneNumber | string                                             | Yes  | Phone number.    |
| options     | [EmergencyNumberOptions](#emergencynumberoptions7) | Yes  | Phone number options. |

**Return value**

| Type                  | Description                                               |
| ---------------------- | --------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. |

**Example**

```js
let promise = call.isEmergencyPhoneNumber("138xxxxxxxx", {slotId: 1});
promise.then(data => {
    console.log(`isEmergencyPhoneNumber success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`isEmergencyPhoneNumber fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.formatPhoneNumber<sup>7+</sup>

formatPhoneNumber\(phoneNumber: string, callback: AsyncCallback<string\>\): void

Formats a phone number. This API uses an asynchronous callback to return the result.

A formatted phone number is a standard numeric string, for example, 555 0100.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                       | Mandatory | Description                                |
| ----------- | --------------------------- | ---- | ------------------------------------ |
| phoneNumber | string                      | Yes  | Phone number.                          |
| callback    | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result. |

**Example**

```js
call.formatPhoneNumber("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## call.formatPhoneNumber<sup>7+</sup>

formatPhoneNumber\(phoneNumber: string, options: NumberFormatOptions, callback: AsyncCallback<string\>\): void

Formats a phone number based on the specified formatting options. This API uses an asynchronous callback to return the result.

A formatted phone number is a standard numeric string, for example, 555 0100.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                                        | Mandatory | Description                                |
| ----------- | -------------------------------------------- | ---- | ------------------------------------ |
| phoneNumber | string                                       | Yes  | Phone number.                          |
| options     | [NumberFormatOptions](#numberformatoptions7) | Yes  | Number formatting options, for example, country code.              |
| callback    | AsyncCallback&lt;string&gt;                  | Yes  | Callback used to return the result. |

**Example**

```js
call.formatPhoneNumber("138xxxxxxxx", {
    countryCode: "CN"
}, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.formatPhoneNumber<sup>7+</sup>

formatPhoneNumber\(phoneNumber: string, options?: NumberFormatOptions\): Promise<string\>

Formats a phone number based on the specified formatting options. This API uses a promise to return the result.

A formatted phone number is a standard numeric string, for example, 555 0100.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                                        | Mandatory | Description                  |
| ----------- | -------------------------------------------- | ---- | ---------------------- |
| phoneNumber | string                                       | Yes  | Phone number.            |
| options     | [NumberFormatOptions](#numberformatoptions7) | Yes  | Number formatting options, for example, country code. |

**Return value**

| Type                 | Description                                       |
| --------------------- | ------------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result. |

**Example**

```js
let promise = call.formatPhoneNumber("138xxxxxxxx", {
    countryCode: "CN"
});
promise.then(data => {
    console.log(`formatPhoneNumber success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`formatPhoneNumber fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.formatPhoneNumberToE164<sup>7+</sup>

formatPhoneNumberToE164\(phoneNumber: string, countryCode: string, callback: AsyncCallback<string\>\): void

Converts a phone number into the E.164 format. This API uses an asynchronous callback to return the result.

The phone number must match the specified country code. For example, for a China phone number, the country code must be **CN**. Otherwise, **null** will be returned.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                       | Mandatory | Description                                                 |
| ----------- | --------------------------- | ---- | ----------------------------------------------------- |
| phoneNumber | string                      | Yes  | Phone number.                                           |
| countryCode | string                      | Yes  | Country code, for example, **CN** (China). All country codes are supported.             |
| callback    | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result. |

**Example**

```js
call.formatPhoneNumberToE164("138xxxxxxxx", {
    countryCode: "CN"
}, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.formatPhoneNumberToE164<sup>7+</sup>

formatPhoneNumberToE164\(phoneNumber: string, countryCode: string\): Promise<string\>

Converts a phone number into the E.164 format. This API uses a promise to return the result.

The phone number must match the specified country code. For example, for a China phone number, the country code must be **CN**. Otherwise, **null** will be returned.

All country codes are supported.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type  | Mandatory | Description                                    |
| ----------- | ------ | ---- | ---------------------------------------- |
| phoneNumber | string | Yes  | Phone number.                              |
| countryCode | string | Yes  | Country code, for example, **CN** (China). All country codes are supported. |

**Return value**

| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; | Promise used to return the result. |

**Example**

```js
let promise = call.formatPhoneNumberToE164("138xxxxxxxx", {
    countryCode: "CN"
});
promise.then(data => {
    console.log(`formatPhoneNumberToE164 success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`formatPhoneNumberToE164 fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.muteRinger<sup>8+</sup>

muteRinger\(callback: AsyncCallback<void\>\): void

Mutes the ringtone while it is playing.  This API uses an asynchronous callback to return the result.

This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                     | Mandatory| Description      |
| ----------- | ------------------------- | ---- | ---------- |
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
call.muteRinger((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.muteRinger<sup>8+</sup>

muteRinger\(\): Promise<void\>

Mutes the ringtone while it is playing.  This API uses a promise to return the result.

This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.muteRinger();
promise.then(data => {
    console.log(`muteRinger success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`muteRinger fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.answer<sup>7+</sup>

answer\(callback: AsyncCallback<void\>\): void

Answers a call. This API uses an asynchronous callback to return the result.

This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
call.answer((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.answer<sup>7+</sup>

answer\(callId: number, callback: AsyncCallback<void\>\): void

Answers a call based on the specified call ID. This API uses an asynchronous callback to return the result.

This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description                                           |
| -------- | ------------------------- | ---- | ----------------------------------------------- |
| callId   | number                    | Yes  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                                     |

**Example**

```js
call.answer(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.answer<sup>7+</sup>

answer(callId?: number\): Promise<void\>

Answers a call based on the specified call ID. This API uses a promise to return the result.

This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| callId | number | No  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events. This parameter is optional from API version 9.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.answer(1);
promise.then(data => {
    console.log(`answer success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`answer fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.hangup<sup>7+</sup>

hangup\(callback: AsyncCallback<void\>\): void

Ends a call. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
call.hangup((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.hangup<sup>7+</sup>

hangup\(callId: number, callback: AsyncCallback<void\>\): void

Ends a call based on the specified call ID. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description                                           |
| -------- | ------------------------- | ---- | ----------------------------------------------- |
| callId   | number                    | Yes  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                                     |

**Example**

```js
call.hangup(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.hangup<sup>7+</sup>

hangup\(callId?: number\): Promise<void\>

Ends a call based on the specified call ID. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| callId | number | No  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events. This parameter is optional from API version 9.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.hangup(1);
promise.then(data => {
    console.log(`hangup success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`hangup fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.reject<sup>7+</sup>

reject\(callback: AsyncCallback<void\>\): void

Rejects a call. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
call.reject((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.reject<sup>7+</sup>

reject\(options: RejectMessageOptions, callback: AsyncCallback<void\>\): void

Rejects a call based on the specified options. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                          | Mandatory| Description          |
| -------- | ---------------------------------------------- | ---- | -------------- |
| options  | [RejectMessageOptions](#rejectmessageoptions7) | Yes  | Options for the call rejection message.|
| callback | AsyncCallback&lt;void&gt;                      | Yes  | Callback used to return the result.    |

**Example**

```js
let rejectMessageOptions={
    messageContent: "Unknown number blocked"
}
call.reject(rejectMessageOptions, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.reject<sup>7+</sup>

reject(callId: number, callback: AsyncCallback\<void>): void

Rejects a call based on the specified call ID. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description                                           |
| -------- | ------------------------- | ---- | ----------------------------------------------- |
| callId   | number                    | Yes  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                                     |

**Example**

```js
call.reject(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## call.reject<sup>7+</sup>

reject\(callId: number, options: RejectMessageOptions, callback: AsyncCallback<void\>\): void

Rejects a call based on the specified call ID and options. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                          | Mandatory| Description                                           |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| callId   | number                                         | Yes  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events.|
| options  | [RejectMessageOptions](#rejectmessageoptions7) | Yes  | Options for the call rejection message.                                 |
| callback | AsyncCallback&lt;void&gt;                      | Yes  | Callback used to return the result.                                     |

**Example**

```js
let rejectMessageOptions={
    messageContent: "Unknown number blocked"
}
call.reject(1, rejectMessageOptions, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.reject<sup>7+</sup>

reject(callId?: number, options?: RejectMessageOptions\): Promise<void\>

Rejects a call based on the specified call ID and options. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name | Type                                          | Mandatory| Description                                                        |
| ------- | ---------------------------------------------- | ---- | ------------------------------------------------------------ |
| callId  | number                                         | No  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events. This parameter is optional from API version 9.|
| options | [RejectMessageOptions](#rejectmessageoptions7) | No  | Options for the call rejection message.                                              |

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let rejectMessageOptions={
    messageContent: "Unknown number blocked"
}
let promise = call.reject(1, rejectMessageOptions);
promise.then(data => {
    console.log(`reject success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`reject fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.holdCall<sup>7+</sup>

holdCall\(callId: number, callback: AsyncCallback<void\>\): void

Holds a call based on the specified call ID. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | Yes  | Call ID.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
call.holdCall(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.holdCall<sup>7+</sup>

holdCall\(callId: number\): Promise<void\>

Holds a call based on the specified call ID. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.holdCall(1);
promise.then(data => {
    console.log(`holdCall success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`holdCall fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.unHoldCall<sup>7+</sup>

unHoldCall\(callId: number, callback: AsyncCallback<void\>\): void

Unholds a call based on the specified call ID. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | Yes  | Call ID.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
call.unHoldCall(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.unHoldCall<sup>7+</sup>

unHoldCall\(callId: number\): Promise<void\>

Unholds a call based on the specified call ID. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.unHoldCall(1);
promise.then(data => {
    console.log(`unHoldCall success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`unHoldCall fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.switchCall<sup>7+</sup>

switchCall\(callId: number, callback: AsyncCallback<void\>\): void

Switches a call. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | Yes  | Call ID.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
call.switchCall(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.switchCall<sup>7+</sup>

switchCall\(callId: number\): Promise<void\>

Switches a call. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.switchCall(1);
promise.then(data => {
    console.log(`switchCall success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`switchCall fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.combineConference<sup>7+</sup>

combineConference\(callId: number, callback: AsyncCallback<void\>\): void

Combines two calls into a conference call. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | Yes  | Call ID.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
call.combineConference(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.combineConference<sup>7+</sup>

combineConference\(callId: number\): Promise<void\>

Combines two calls into a conference call. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.combineConference(1);
promise.then(data => {
    console.log(`combineConference success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`combineConference fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.getMainCallId<sup>7+</sup>

getMainCallId\(callId: number, callback: AsyncCallback<number\>\): void

Obtains the main call ID. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                       | Mandatory| Description                    |
| -------- | --------------------------- | ---- | ------------------------ |
| callId   | number                      | Yes  | Call ID.                |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result.  |

**Example**

```js
call.getMainCallId(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.getMainCallId<sup>7+</sup>

getMainCallId\(callId: number\): Promise<number\>

Obtains the main call ID. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.getMainCallId(1);
promise.then(data => {
    console.log(`getMainCallId success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getMainCallId fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.getSubCallIdList<sup>7+</sup>

getSubCallIdList\(callId: number, callback: AsyncCallback<Array<string\>\>\): void

Obtains the list of subcall IDs. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                          | Mandatory| Description                        |
| -------- | ------------------------------ | ---- | ---------------------------- |
| callId   | number                         | Yes  | Call ID.                    |
| callback | AsyncCallback<Array<string\>\> | Yes  | Callback used to return the result.  |

**Example**

```js
call.getSubCallIdList(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.getSubCallIdList<sup>7+</sup>

getSubCallIdList\(callId: number\): Promise<Array<string\>\>

Obtains the list of subcall IDs. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type                         | Description                               |
| ----------------------------- | ----------------------------------- |
| Promise&lt;Array<string\>&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.getSubCallIdList(1);
promise.then(data => {
    console.log(`getSubCallIdList success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getSubCallIdList fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.getCallIdListForConference<sup>7+</sup>

getCallIdListForConference\(callId: number, callback: AsyncCallback<Array<string\>>\): void

Obtains the list of call IDs in a conference. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                               | Mandatory| Description                            |
| -------- | ----------------------------------- | ---- | -------------------------------- |
| callId   | number                              | Yes  | Call ID.                        |
| callback | AsyncCallback&lt;Array<string\>&gt; | Yes  | Callback used to return the result.  |

**Example**

```js
call.getCallIdListForConference(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.getCallIdListForConference<sup>7+</sup>

getCallIdListForConference\(callId: number\): Promise<Array<string\>\>

Obtains the list of call IDs in a conference. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type                         | Description                                   |
| ----------------------------- | --------------------------------------- |
| Promise&lt;Array<string\>&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.getCallIdListForConference(1);
promise.then(data => {
    console.log(`getCallIdListForConference success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getCallIdListForConference fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.getCallWaitingStatus<sup>7+</sup>

getCallWaitingStatus\(slotId: number, callback: AsyncCallback<CallWaitingStatus\>\): void

Obtains the call waiting status. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                                                      | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                      |
| callback | AsyncCallback&lt;[CallWaitingStatus](#callwaitingstatus7)\> | Yes  | Callback used to return the result.<br><br>- **0**: Call waiting is disabled.<br>- **1**: Call waiting is enabled.|

**Example**

```js
call.getCallWaitingStatus(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.getCallWaitingStatus<sup>7+</sup>

getCallWaitingStatus\(slotId: number\): Promise<CallWaitingStatus\>

Obtains the call waiting status. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                                                   | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[CallWaitingStatus](#callwaitingstatus7)&gt; | Promise used to return the result.<br>- **0**: Call waiting is disabled.<br>- **1**: Call waiting is enabled.|

**Example**

```js
let promise = call.getCallWaitingStatus(0);
promise.then(data => {
    console.log(`getCallWaitingStatus success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getCallWaitingStatus fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.setCallWaiting<sup>7+</sup>

setCallWaiting\(slotId: number, activate: boolean, callback: AsyncCallback<void\>\): void

Sets the call waiting switch. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number               | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                      |
| activate | boolean              | Yes  | Whether to enable call waiting.<br>- **false**: Disable call waiting.<br>- **true**: Enable call waiting.|
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.                                                  |

**Example**

```js
call.setCallWaiting(0, true, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.setCallWaiting<sup>7+</sup>

setCallWaiting\(slotId: number, activate: boolean\): Promise<void\>

Sets the call waiting switch. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| slotId   | number  | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                      |
| activate | boolean | Yes  | Whether to enable call waiting.<br>- **false**: Disable call waiting.<br>- **true**: Enable call waiting.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.setCallWaiting(0, true);
promise.then(data => {
    console.log(`setCallWaiting success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`setCallWaiting fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.startDTMF<sup>7+</sup>

startDTMF\(callId: number, character: string, callback: AsyncCallback<void\>\): void

Enables dual-tone multifrequency (DTMF). This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name   | Type                | Mandatory| Description      |
| --------- | -------------------- | ---- | ---------- |
| callId    | number               | Yes  | Call ID.  |
| character | string               | Yes  | DTMF code.  |
| callback  | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```js
call.startDTMF(1, "0", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.startDTMF<sup>7+</sup>

startDTMF\(callId: number, character: string\): Promise<void\>

Enables DTMF. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name   | Type  | Mandatory| Description    |
| --------- | ------ | ---- | -------- |
| callId    | number | Yes  | Call ID.|
| character | string | Yes  | DTMF code.|

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.startDTMF(1, "0");
promise.then(data => {
    console.log(`startDTMF success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`startDTMF fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.stopDTMF<sup>7+</sup>

stopDTMF\(callId: number, callback: AsyncCallback<void\>\): void

Stops DTMF. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | Yes  | Call ID.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
call.stopDTMF(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.stopDTMF<sup>7+</sup>

stopDTMF\(callId: number\): Promise<void\>

Stops DTMF. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.stopDTMF(1);
promise.then(data => {
    console.log(`stopDTMF success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`stopDTMF fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.isInEmergencyCall<sup>7+</sup>

isInEmergencyCall\(callback: AsyncCallback<boolean\>\): void

Checks whether a call is an emergency call. This API uses an asynchronous callback to return the result.

This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                        | Mandatory| Description      |
| -------- | ---------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.|

**Example**

```js
call.isInEmergencyCall((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.isInEmergencyCall<sup>7+</sup>

isInEmergencyCall\(\): Promise<boolean\>

Checks whether a call is an emergency call. This API uses a promise to return the result.

This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type                  | Description                       |
| ---------------------- | --------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.isInEmergencyCall();
promise.then(data => {
    console.log(`isInEmergencyCall success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`isInEmergencyCall fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.on('callDetailsChange')<sup>7+</sup>

on\(type: 'callDetailsChange', callback: Callback<CallAttributeOptions\>\): void

Subscribes to **callDetailsChange** events. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                   | Mandatory| Description                      |
| -------- | ------------------------------------------------------- | ---- | -------------------------- |
| type     | string                                                  | Yes  | Call details change during a call.|
| callback | Callback<[CallAttributeOptions](#callattributeoptions7)> | Yes  | Callback used to return the result.                |

**Example**

```js
call.on('callDetailsChange', data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('callEventChange')<sup>8+</sup>

on\(type: 'callEventChange', callback: Callback<CallEventOptions\>\): void

Subscribes to **callEventChange** events. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                            | Mandatory| Description                      |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| type     | string                                           | Yes  | Call event change during a call.|
| callback | Callback<[CallEventOptions](#calleventoptions8)> | Yes  | Callback used to return the result.                |

**Example**

```js
call.on('callEventChange', data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('callDisconnectedCause')<sup>8+</sup>

on\(type: 'callDisconnectedCause', callback: Callback<DisconnectedDetails\>): void

Subscribes to **callDisconnectedCause** events. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                  | Mandatory| Description                      |
| -------- | ------------------------------------------------------ | ---- | -------------------------- |
| type     | string                                                 | Yes  | Cause of the call disconnection.|
| callback | Callback<[DisconnectedDetails](#disconnecteddetails8)> | Yes  | Callback used to return the result.                |

**Example**

```js
call.on('callDisconnectedCause', data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('mmiCodeResult')<sup>9+</sup>

on\(type: 'mmiCodeResult', callback: Callback<MmiCodeResults\>\): void

Subscribes to **mmiCodeResult** events. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                        | Mandatory| Description                 |
| -------- | -------------------------------------------- | ---- | --------------------- |
| type     | string                                       | Yes  | Man-machine interface (MMI) code result.|
| callback | Callback<[MmiCodeResults](#mmicoderesults9)> | Yes  | Callback used to return the result.           |

**Example**

```js
call.on('mmiCodeResult', data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('callDetailsChange')<sup>7+</sup>

off\(type: 'callDetailsChange', callback?: Callback<CallAttributeOptions\>\): void

Unsubscribes from **callDetailsChange** events. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                    | Mandatory| Description                              |
| -------- | -------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                   | Yes  | Unsubscription from call details changes when a call ends.|
| callback | Callback<[CallAttributeOptions](#callattributeoptions7)> | No  | Callback used to return the result.                        |

**Example**

```js
call.off('callDetailsChange', data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('callEventChange')<sup>8+</sup>

off\(type: 'callEventChange', callback?: Callback<CallEventOptions\>\): void

Unsubscribes from **callEventChange** events. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                            | Mandatory| Description                              |
| -------- | ------------------------------------------------ | ---- | ---------------------------------- |
| type     | string                                           | Yes  | Unsubscription from call event changes when a call ends.|
| callback | Callback<[CallEventOptions](#calleventoptions8)> | No  | Callback used to return the result.                        |

**Example**

```js
call.off('callEventChange', data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('callDisconnectedCause')<sup>8+</sup>

off\(type: 'callDisconnectedCause', callback?: Callback<DisconnectedDetails\>\): void

Unsubscribes from **callDisconnectedCause** events. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                      | Mandatory| Description                |
| -------- | ---------------------------------------------------------- | ---- | -------------------- |
| type     | 'callDisconnectedCause'                                    | Yes  | Unsubscription from the call disconnection cause when a call ends.|
| callback | Callback**<**[DisconnectedDetails](#disconnecteddetails8)> | No  | Callback used to return the result.          |

**Example**

```js
call.off('callDisconnectedCause', data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('mmiCodeResult')<sup>9+</sup>

off\(type: 'mmiCodeResult', callback?: Callback<MmiCodeResults\>\): void

Unsubscribes from **mmiCodeResult** events. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                            | Mandatory| Description       |
| -------- | ------------------------------------------------ | ---- | ----------- |
| type     | 'mmiCodeResult'                                  | Yes  | MMI code result.|
| callback | Callback<[MmiCodeResults](#mmicoderesults9)> | No  | Callback used to return the result. |

**Example**

```js
call.off('mmiCodeResult', data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.isNewCallAllowed<sup>8+</sup>

isNewCallAllowed\(callback: AsyncCallback<boolean\>\): void

Checks whether a new call is allowed. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                        | Mandatory| Description      |
| -------- | ---------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.|

**Example**

```js
call.isNewCallAllowed((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.isNewCallAllowed<sup>8+</sup>

isNewCallAllowed\(\): Promise<boolean\>

Checks whether a new call is allowed. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type                  | Description                       |
| ---------------------- | --------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.isNewCallAllowed();
promise.then(data => {
    console.log(`isNewCallAllowed success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`isNewCallAllowed fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.separateConference<sup>8+</sup>

separateConference\(callId: number, callback: AsyncCallback<void\>\): void

Separates a conference call. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | Yes  | Call ID.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
call.separateConference(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.separateConference<sup>8+</sup>

separateConference\(callId: number\): Promise<void\>

Separates a conference call. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.separateConference(1);
promise.then(data => {
    console.log(`separateConference success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`separateConference fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.getCallRestrictionStatus<sup>8+</sup>

getCallRestrictionStatus\(slotId: number, type: CallRestrictionType, callback: AsyncCallback<RestrictionStatus\>\): void

Obtains the call restriction status. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| type     | [CallRestrictionType](#callrestrictiontype8)                 | Yes  | Call restriction type.                       |
| callback | AsyncCallback&lt;[RestrictionStatus](#restrictionstatus8)&gt; | Yes  | Callback used to return the result.                |

**Example**

```js
call.getCallRestrictionStatus(0, 1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.getCallRestrictionStatus<sup>8+</sup>

getCallRestrictionStatus\(slotId: number, type: CallRestrictionType\): Promise<RestrictionStatus\>

Obtains the call restriction status. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type                                        | Mandatory| Description                                  |
| ------ | -------------------------------------------- | ---- | -------------------------------------- |
| slotId | number                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| type   | [CallRestrictionType](#callrestrictiontype8) | Yes  | Call restriction type.                       |

**Return value**

| Type                                                   | Description                       |
| ------------------------------------------------------- | --------------------------- |
| Promise&lt;[RestrictionStatus](#restrictionstatus8)&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.getCallRestrictionStatus(0, 1);
promise.then(data => {
    console.log(`getCallRestrictionStatus success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getCallRestrictionStatus fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.setCallRestriction<sup>8+</sup>

setCallRestriction\(slotId: number, info: CallRestrictionInfo, callback: AsyncCallback<void\>\): void

Sets the call restriction status. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                       | Mandatory| Description                                  |
| -------- | ------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                      | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| info     | [CallRestrictionInfo](#callrestrictioninfo8) | Yes  | Call restriction information.                        |
| callback | AsyncCallback&lt;void&gt;                   | Yes  | Callback used to return the result.                            |

**Example**

```js
let callRestrictionInfo={
    type: 1,
    password: "123456",
    mode: 1
}
call.setCallRestriction(0, callRestrictionInfo, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.setCallRestriction<sup>8+</sup>

setCallRestriction\(slotId: number, info: CallRestrictionInfo\): Promise<void\>

Sets the call restriction status. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type                                        | Mandatory| Description                                  |
| ------ | -------------------------------------------- | ---- | -------------------------------------- |
| slotId | number                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| info   | [CallRestrictionInfo](#callrestrictioninfo8) | Yes  | Call restriction information.                        |

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let callRestrictionInfo={
    type: 1,
    password: "123456",
    mode: 1
}
let promise = call.setCallRestriction(0, callRestrictionInfo);
promise.then(data => {
    console.log(`setCallRestriction success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`setCallRestriction fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.getCallTransferInfo<sup>8+</sup>

getCallTransferInfo\(slotId: number, type: CallTransferType, callback: AsyncCallback<CallTransferResult\>\): void

Obtains call transfer information. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| type     | [CallTransferType](#calltransfertype8)                       | Yes  | Call transfer type.                        |
| callback | AsyncCallback&lt;[CallTransferResult](#calltransferresult8)&gt; | Yes  | Callback used to return the result.            |

**Example**

```js
let callTransferTyp={
    CallTransferType: 1
}
call.getCallTransferInfo(0, callTransferTyp, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.getCallTransferInfo<sup>8+</sup>

getCallTransferInfo\(slotId: number, type: CallTransferType): Promise<CallTransferResult\>

Obtains call transfer information. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type                                  | Mandatory| Description                                  |
| ------ | -------------------------------------- | ---- | -------------------------------------- |
| slotId | number                                 | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| type   | [CallTransferType](#calltransfertype8) | Yes  | Call transfer type.                        |

**Return value**

| Type                                                     | Description                       |
| --------------------------------------------------------- | --------------------------- |
| Promise&lt;[CallTransferResult](#calltransferresult8)&gt; | Promise used to return the result.|

**Example**

```js
let callTransferTyp={
    CallTransferType: 1
}
let promise = call.getCallTransferInfo(0, callTransferTyp);
promise.then(data => {
    console.log(`getCallTransferInfo success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getCallTransferInfo fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.setCallTransfer<sup>8+</sup>

setCallTransfer\(slotId: number, info: CallTransferInfo, callback: AsyncCallback<void\>\): void

Sets call transfer information. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                 | Mandatory| Description                                  |
| -------- | ------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| info     | [CallTransferInfo](#calltransferinfo8) | Yes  | Call transfer information.                       |
| callback | AsyncCallback&lt;void&gt;             | Yes  | Callback used to return the result.                            |

**Example**

```js
let callTransferInfo={
    transferNum: "111",
    type: 1,
    settingType: 1
}
call.setCallTransfer(0, callTransferInfo, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.setCallTransfer<sup>8+</sup>

setCallTransfer\(slotId: number, info: CallTransferInfo): Promise<void\>

Sets call transfer information. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type                                 | Mandatory| Description                                  |
| ------ | ------------------------------------- | ---- | -------------------------------------- |
| slotId | number                                | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| info   | [CallTransferInfo](#calltransferinfo8) | Yes  | Call transfer information.                       |

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let callTransferInfo={
    transferNum: "111",
    type: 1,
    settingType: 1
}
let promise = call.setCallTransfer(0, callTransferInfo);
promise.then(data => {
    console.log(`setCallTransfer success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`setCallTransfer fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.isRinging<sup>8+</sup>

isRinging\(callback: AsyncCallback<boolean\>\): void

Checks whether the ringtone is playing. This API uses an asynchronous callback to return the result.

This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                        | Mandatory| Description      |
| -------- | ---------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.|

**Example**

```js
call.isRinging((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.isRinging<sup>8+</sup>

isRinging\(\): Promise<boolean\>

Checks whether the ringtone is playing. This API uses a promise to return the result.

This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type                  | Description                       |
| ---------------------- | --------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.isRinging();
promise.then(data => {
    console.log(`isRinging success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`isRinging fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.setMuted<sup>8+</sup>

setMuted\(callback: AsyncCallback<void\>\): void

Sets call muting. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
call.setMuted((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.setMuted<sup>8+</sup>

setMuted\(\): Promise<void\>

Sets call muting. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.setMuted();
promise.then(data => {
    console.log(`setMuted success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`setMuted fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.cancelMuted<sup>8+</sup>

cancelMuted(callback: AsyncCallback<void\>): void

Cancels call muting. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
call.cancelMuted((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.cancelMuted<sup>8+</sup>

cancelMuted(): Promise<void\>

Cancels call muting. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.cancelMuted();
promise.then(data => {
    console.log(`cancelMuted success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`cancelMuted fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.setAudioDevice<sup>8+</sup>

setAudioDevice\(device: AudioDevice, callback: AsyncCallback<void\>\): void

Sets the audio device for a call. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                        | Mandatory| Description      |
| -------- | ---------------------------- | ---- | ---------- |
| device   | [AudioDevice](#audiodevice8) | Yes  | Audio device.|
| callback | AsyncCallback&lt;void&gt;    | Yes  | Callback used to return the result.|

**Example**

```js
call.setAudioDevice(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.setAudioDevice<sup>8+</sup>

setAudioDevice\(device: AudioDevice, options: AudioDeviceOptions, callback: AsyncCallback<void\>\): void

Sets the audio device for a call based on the specified options. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                      | Mandatory| Description          |
| -------- | ------------------------------------------ | ---- | -------------- |
| device   | [AudioDevice](#audiodevice8)               | Yes  | Audio device.    |
| options  | [AudioDeviceOptions](#audiodeviceoptions9) | Yes  | Audio device parameters.|
| callback | AsyncCallback&lt;void&gt;                  | Yes  | Callback used to return the result.    |

**Example**

```js
let audioDeviceOptions={
    bluetoothAddress: "IEEE 802-2014"
}
call.setAudioDevice(1, audioDeviceOptions, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.setAudioDevice<sup>8+</sup>

setAudioDevice(device: AudioDevice, options?: AudioDeviceOptions): Promise<void\>

Sets the audio device for a call based on the specified options. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name | Type                                      | Mandatory| Description              |
| ------- | ------------------------------------------ | ---- | ------------------ |
| device  | [AudioDevice](#audiodevice8)               | Yes  | Audio device.        |
| options | [AudioDeviceOptions](#audiodeviceoptions9) | No  | Audio device parameters.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let audioDeviceOptions={
    bluetoothAddress: "IEEE 802-2014"
}
let promise = call.setAudioDevice(1, audioDeviceOptions);
promise.then(data => {
    console.log(`setAudioDevice success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`setAudioDevice fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.joinConference<sup>8+</sup>

joinConference(mainCallId: number, callNumberList: Array<string\>, callback: AsyncCallback<void\>): void

Joins a conference call. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name        | Type                     | Mandatory| Description           |
| -------------- | ------------------------- | ---- | --------------- |
| mainCallId     | number                    | Yes  | Main call ID.     |
| callNumberList | Array<string\>            | Yes  | List of call numbers.|
| callback       | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.     |

**Example**

```js
call.joinConference(1, "138XXXXXXXX", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## call.joinConference<sup>8+</sup>

joinConference(mainCallId: number, callNumberList: Array<string\>): Promise<void\>

Joins a conference call. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name        | Type          | Mandatory| Description           |
| -------------- | -------------- | ---- | --------------- |
| mainCallId     | number         | Yes  | Main call ID.     |
| callNumberList | Array<string\> | Yes  | List of call numbers.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.joinConference(1, "138XXXXXXXX");
promise.then(data => {
    console.log(`joinConference success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`joinConference fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.updateImsCallMode<sup>8+</sup>

updateImsCallMode(callId: number, mode: ImsCallMode, callback: AsyncCallback<void\>): void

Updates the IMS call mode. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                        | Mandatory| Description          |
| -------- | ---------------------------- | ---- | -------------- |
| callId   | number                       | Yes  | Call ID.      |
| mode     | [ImsCallMode](#imscallmode8) | Yes  | IMS call mode.|
| callback | AsyncCallback&lt;void&gt;    | Yes  | Callback used to return the result.    |

**Example**

```js
call.updateImsCallMode(1, 1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## call.updateImsCallMode<sup>8+</sup>

updateImsCallMode(callId: number, mode: ImsCallMode): Promise<void\>

Updates the IMS call mode. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type                        | Mandatory| Description          |
| ------ | ---------------------------- | ---- | -------------- |
| callId | number                       | Yes  | Call ID.      |
| mode   | [ImsCallMode](#imscallmode8) | Yes  | IMS call mode.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.updateImsCallMode(1, 1);
promise.then(data => {
    console.log(`updateImsCallMode success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`updateImsCallMode fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.enableImsSwitch<sup>8+</sup>

enableImsSwitch(slotId: number, callback: AsyncCallback<void\>): void

Enables the IMS switch. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description                                  |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                            |

**Example**

```js
call.enableImsSwitch(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## call.enableImsSwitch<sup>8+</sup>

enableImsSwitch(slotId: number): Promise<void\>

Enables the IMS switch. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.enableImsSwitch(0);
promise.then(data => {
    console.log(`enableImsSwitch success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`enableImsSwitch fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.disableImsSwitch<sup>8+</sup>

disableImsSwitch(slotId: number, callback: AsyncCallback<void\>): void

Disables the IMS switch. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description                                  |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                            |

**Example**

```js
call.disableImsSwitch(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## call.disableImsSwitch<sup>8+</sup>

disableImsSwitch(slotId: number): Promise<void\>

Disables the IMS switch. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.disableImsSwitch(0);
promise.then(data => {
    console.log(`disableImsSwitch success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`disableImsSwitch fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.isImsSwitchEnabled<sup>8+</sup>

isImsSwitchEnabled(slotId: number, callback: AsyncCallback<boolean\>): void

Checks whether the IMS switch is enabled. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                        | Mandatory| Description                                  |
| -------- | ---------------------------- | ---- | -------------------------------------- |
| slotId   | number                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.                            |

**Example**

```js
call.isImsSwitchEnabled(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## call.isImsSwitchEnabled<sup>8+</sup>

isImsSwitchEnabled(slotId: number): Promise<boolean\>

Checks whether the IMS switch is enabled. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
let promise = call.isImsSwitchEnabled(0);
promise.then(data => {
    console.log(`isImsSwitchEnabled success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`isImsSwitchEnabled fail, promise: err->${JSON.stringify(err)}`);
});
```


## DialOptions

Defines the dialup options.

**System capability**: SystemCapability.Telephony.CallManager

| Name                  | Type                              | Mandatory| Description                                                        |
| ------------------------ | ---------------------------------- | ---- | ------------------------------------------------------------ |
| extras                   | boolean                            | No  | Indication of a video call. <br>- **true**: video call<br>- **false** (default): voice call|
| accountId <sup>8+</sup>  | number                             | No  | Account ID.<br>- **0**: card slot 1<br>- **1**: card slot 2<br>This is a system API.         |
| videoState <sup>8+</sup> | [VideoStateType](#videostatetype7) | No  | Video state type. This is a system API.                            |
| dialScene <sup>8+</sup>  | [DialScene](#dialscene8)           | No  | Dialup scenario. This is a system API.                                |
| dialType <sup>8+</sup>   | [DialType](#dialtype8)             | No  | Dialup type. This is a system API.                                |

## CallState

Enumerates call states.

**System capability**: SystemCapability.Telephony.CallManager

| Name              | Value  | Description                                                        |
| ------------------ | ---- | ------------------------------------------------------------ |
| CALL_STATE_UNKNOWN | -1   | The call status fails to be obtained and is unknown.                        |
| CALL_STATE_IDLE    | 0    | No call is in progress.                                    |
| CALL_STATE_RINGING | 1    | The call is in the ringing or waiting state.                                    |
| CALL_STATE_OFFHOOK | 2    | At least one call is in dialing, active, or on hold, and no new incoming call is ringing or waiting. |

## EmergencyNumberOptions<sup>7+</sup>

Defines options for determining whether a number is an emergency number.

**System capability**: SystemCapability.Telephony.CallManager

| Name| Type  | Mandatory | Description                                          |
| ------ | ------ | ---- | ---------------------------------------------- |
| slotId | number | No  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

## NumberFormatOptions<sup>7+</sup>

Defines the number formatting options.

**System capability**: SystemCapability.Telephony.CallManager

| Name     | Type  | Mandatory | Description                                                      |
| ----------- | ------ | ---- | ---------------------------------------------------------- |
| countryCode | string | No  | Country code, for example, **CN** (China). All country codes are supported. The default value is **CN**. |

## ImsCallMode<sup>8+</sup>

Enumerates IMS call modes.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                  | Value  | Description              |
| ---------------------- | ---- | ------------------ |
| CALL_MODE_AUDIO_ONLY   | 0    | Audio call only.      |
| CALL_MODE_SEND_ONLY    | 1    | Sending calls only.        |
| CALL_MODE_RECEIVE_ONLY | 2    | Receiving calls only.        |
| CALL_MODE_SEND_RECEIVE | 3    | Sending and receiving calls.|
| CALL_MODE_VIDEO_PAUSED | 4    | Pausing video calls.      |

## AudioDevice<sup>8+</sup>

Enumerates audio devices.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                | Value  | Description        |
| -------------------- | ---- | ------------ |
| DEVICE_EARPIECE      | 0    | Earpiece.    |
| DEVICE_SPEAKER       | 1    | Speaker.|
| DEVICE_WIRED_HEADSET | 2    | Wired headset.|
| DEVICE_BLUETOOTH_SCO | 3    | Bluetooth SCO device. |
| DEVICE_MIC           | 4    | Microphone. |

## CallRestrictionType<sup>8+</sup>

Enumerates call restriction types.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                                         | Value  | Description                      |
| --------------------------------------------- | ---- | -------------------------- |
| RESTRICTION_TYPE_ALL_INCOMING                 | 0    | Barring of all incoming calls.              |
| RESTRICTION_TYPE_ALL_OUTGOING                 | 1    | Barring of all outgoing calls.              |
| RESTRICTION_TYPE_INTERNATIONAL                | 2    | Barring of international calls.              |
| RESTRICTION_TYPE_INTERNATIONAL_EXCLUDING_HOME | 3    | Barring of international calls except those in the home country.|
| RESTRICTION_TYPE_ROAMING_INCOMING             | 4    | Barring of incoming roaming calls.              |
| RESTRICTION_TYPE_ALL_CALLS                    | 5    | Barring of all calls.              |
| RESTRICTION_TYPE_OUTGOING_SERVICES            | 6    | Barring of outgoing services.              |
| RESTRICTION_TYPE_INCOMING_SERVICES            | 7    | Barring of incoming services.              |

## CallTransferInfo<sup>8+</sup>

Defines the call transfer information.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name     | Type                                                | Mandatory| Description            |
| ----------- | ---------------------------------------------------- | ---- | ---------------- |
| transferNum | string                                               | Yes  | Call transfer number.        |
| type        | [CallTransferType](#calltransfertype8)               | Yes  | Call transfer type.    |
| settingType | [CallTransferSettingType](#calltransfersettingtype8) | Yes  | Call transfer setting type.|

## CallTransferType<sup>8+</sup>

Enumerates call transfer types.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                       | Value  | Description        |
| --------------------------- | ---- | ------------ |
| TRANSFER_TYPE_UNCONDITIONAL | 0    | Call forwarding unconditional.  |
| TRANSFER_TYPE_BUSY          | 1    | Call forwarding busy.    |
| TRANSFER_TYPE_NO_REPLY      | 2    | Call forwarding on no reply.  |
| TRANSFER_TYPE_NOT_REACHABLE | 3    | Call forwarding on no user not reachable.|

## CallTransferSettingType<sup>8+</sup>

Enumerates call transfer setting types.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                      | Value  | Description        |
| -------------------------- | ---- | ------------ |
| CALL_TRANSFER_DISABLE      | 0    | Disabling of call transfer.|
| CALL_TRANSFER_ENABLE       | 1    | Enabling of call transfer.|
| CALL_TRANSFER_REGISTRATION | 3    | Registration of call transfer.|
| CALL_TRANSFER_ERASURE      | 4    | Erasing of call transfer.|

## CallAttributeOptions<sup>7+</sup>

Defines the call attribute options.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name         | Type                                    | Mandatory| Description          |
| --------------- | ---------------------------------------- | ---- | -------------- |
| accountNumber   | string                                   | Yes  | Account number.      |
| speakerphoneOn  | boolean                                  | Yes  | Speakerphone on.|
| accountId       | number                                   | Yes  | Account ID.        |
| videoState      | [VideoStateType](#videostatetype7)       | Yes  | Video state type.  |
| startTime       | number                                   | Yes  | Start time.      |
| isEcc           | boolean                                  | Yes  | Whether the call is an ECC.     |
| callType        | [CallType](#calltype7)                   | Yes  | Call type.      |
| callId          | number                                   | Yes  | Call ID.        |
| callState       | [DetailedCallState](#detailedcallstate7) | Yes  | Detailed call state.  |
| conferenceState | [ConferenceState](#conferencestate7)     | Yes  | Conference state.      |

## ConferenceState<sup>7+</sup>

Enumerates conference states.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                        | Value  | Description          |
| ---------------------------- | ---- | -------------- |
| TEL_CONFERENCE_IDLE          | 0    | Idle state.  |
| TEL_CONFERENCE_ACTIVE        | 1    | Active state.  |
| TEL_CONFERENCE_DISCONNECTING | 2    | Disconnecting state.  |
| TEL_CONFERENCE_DISCONNECTED  | 3    | Disconnected state.|

## CallType<sup>7+</sup>

Enumerates call types.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name         | Value  | Description        |
| ------------- | ---- | ------------ |
| TYPE_CS       | 0    | CS call.      |
| TYPE_IMS      | 1    | IMS call.     |
| TYPE_OTT      | 2    | OTT call.     |
| TYPE_ERR_CALL | 3    | Error call type.|

## VideoStateType<sup>7+</sup>

Enumerates video state types.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name      | Value  | Description    |
| ---------- | ---- | -------- |
| TYPE_VOICE | 0    | Voice state.|
| TYPE_VIDEO | 1    | Video state.|

## DetailedCallState<sup>7+</sup>

Enumerates detailed call states.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                     | Value  | Description          |
| ------------------------- | ---- | -------------- |
| CALL_STATUS_ACTIVE        | 0    | Active state.  |
| CALL_STATUS_HOLDING       | 1    | Hold state.  |
| CALL_STATUS_DIALING       | 2    | Dialing state.  |
| CALL_STATUS_ALERTING      | 3    | Alerting state.  |
| CALL_STATUS_INCOMING      | 4    | Incoming state.  |
| CALL_STATUS_WAITING       | 5    | Waiting state.  |
| CALL_STATUS_DISCONNECTED  | 6    | Disconnected state.|
| CALL_STATUS_DISCONNECTING | 7    | Disconnecting state.  |
| CALL_STATUS_IDLE          | 8    | Idle state.  |

## CallRestrictionInfo<sup>8+</sup>

Defines the call restriction information.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name  | Type                                        | Mandatory| Description        |
| -------- | -------------------------------------------- | ---- | ------------ |
| type     | [CallRestrictionType](#callrestrictiontype8) | Yes  | Call restriction type.|
| password | string                                       | Yes  | Password.        |
| mode     | [CallRestrictionMode](#callrestrictionmode8) | Yes  | Call restriction mode.|

## CallRestrictionMode<sup>8+</sup>

Enumerates call restriction modes.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                         | Value  | Description        |
| ----------------------------- | ---- | ------------ |
| RESTRICTION_MODE_DEACTIVATION | 0    | Call restriction deactivated.|
| RESTRICTION_MODE_ACTIVATION   | 1    | Call restriction activated.|

## CallEventOptions<sup>8+</sup>

Defines the call event options.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name | Type                                      | Mandatory| Description          |
| ------- | ------------------------------------------ | ---- | -------------- |
| eventId | [CallAbilityEventId](#callabilityeventid8) | Yes  | Call ability event ID.|

## CallAbilityEventId<sup>8+</sup>

Enumerates call ability event IDs.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                    | Value  | Description           |
| ------------------------ | ---- | --------------- |
| EVENT_DIAL_NO_CARRIER    | 1    | No available carrier during dialing. |
| EVENT_INVALID_FDN_NUMBER | 2    | Invalid FDN.|

## DialScene<sup>8+</sup>

Enumerates dialup scenarios.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name           | Value  | Description        |
| --------------- | ---- | ------------ |
| CALL_NORMAL     | 0    | Common call.    |
| CALL_PRIVILEGED | 1    | Privileged call.    |
| CALL_EMERGENCY  | 2    | Emergency call.|

## DialType<sup>8+</sup>

Enumerates dialup types.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                | Value  | Description            |
| -------------------- | ---- | ---------------- |
| DIAL_CARRIER_TYPE    | 0    | Carrier.    |
| DIAL_VOICE_MAIL_TYPE | 1    | Voice mail.|
| DIAL_OTT_TYPE        | 2    | OTT.     |

## RejectMessageOptions<sup>7+</sup>

Defines options for the call rejection message.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name        | Type  | Mandatory| Description    |
| -------------- | ------ | ---- | -------- |
| messageContent | string | Yes  | Message content.|

## CallTransferResult<sup>8+</sup>

Defines the call transfer result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name| Type                              | Mandatory| Description    |
| ------ | ---------------------------------- | ---- | -------- |
| status | [TransferStatus](#transferstatus8) | Yes  | Transfer status.|
| number | string                             | Yes  | Number.    |

## CallWaitingStatus<sup>7+</sup>

Enumerates call waiting states.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                | Value  | Description        |
| -------------------- | ---- | ------------ |
| CALL_WAITING_DISABLE | 0    | Call waiting disabled.|
| CALL_WAITING_ENABLE  | 1    | Call waiting enabled.|

## RestrictionStatus<sup>8+</sup>

Enumerates call restriction states.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name               | Value  | Description    |
| ------------------- | ---- | -------- |
| RESTRICTION_DISABLE | 0    | Call restriction disabled.|
| RESTRICTION_ENABLE  | 1    | Call restriction enabled.|

## TransferStatus<sup>8+</sup>

Enumerates call transfer states.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name            | Value  | Description    |
| ---------------- | ---- | -------- |
| TRANSFER_DISABLE | 0    | Call transfer disabled.|
| TRANSFER_ENABLE  | 1    | Call transfer enabled.|

## DisconnectedDetails<sup>8+</sup>

Enumerates causes of call disconnection.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                       | Value  | Description                  |
| --------------------------- | ---- | ---------------------- |
| UNASSIGNED_NUMBER           | 1    | Unallocated number.    |
| NO_ROUTE_TO_DESTINATION     | 3    | No route to the destination.      |
| CHANNEL_UNACCEPTABLE        | 6    | Unacceptable channel.        |
| OPERATOR_DETERMINED_BARRING | 8    | Operator determined barring (ODB).            |
| NORMAL_CALL_CLEARING        | 16   | Normal call clearing.          |
| USER_BUSY                   | 17   | User busy.                |
| NO_USER_RESPONDING          | 18   | No user response.            |
| USER_ALERTING_NO_ANSWER     | 19   | Alerting but no answer.|
| CALL_REJECTED               | 21   | Call rejected.              |
| NUMBER_CHANGED              | 22   | Number changed.              |
| DESTINATION_OUT_OF_ORDER    | 27   | Destination fault.              |
| INVALID_NUMBER_FORMAT       | 28   | Invalid number format.          |
| NETWORK_OUT_OF_ORDER        | 38   | Network fault.              |
| TEMPORARY_FAILURE           | 41   | Temporary fault.              |
| INVALID_PARAMETER           | 1025 | Invalid parameter.              |
| SIM_NOT_EXIT                | 1026 | SIM card not exit.           |
| SIM_PIN_NEED                | 1027 | SIM card PIN required.        |
| CALL_NOT_ALLOW              | 1029 | Call not allowed.            |
| SIM_INVALID                 | 1045 | Invalid SIM card.             |
| UNKNOWN                     | 1279 | Unknown reason.              |

## MmiCodeResults<sup>9+</sup>

Defines the MMI code result.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name   | Type                            | Mandatory| Description           |
| ------- | -------------------------------- | ---- | --------------- |
| result  | [MmiCodeResult](#mmicoderesult9) | Yes  | MMI code result.|
| message | string                           | Yes  | MMI code message.|

## MmiCodeResult<sup>9+</sup>

Enumerates MMI code results.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name            | Value  | Description         |
| ---------------- | ---- | ------------- |
| MMI_CODE_SUCCESS | 0    | Success.|
| MMI_CODE_FAILED  | 1    | Failure.|

## AudioDeviceOptions<sup>9+</sup>

Defines audio device options.

This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name            | Type  | Mandatory| Description    |
| ---------------- | ------ | ---- | -------- |
| bluetoothAddress | string | No  | Bluetooth address.|
