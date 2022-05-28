# Call

The call module provides call management functions, including making calls, redirecting to the dial screen, obtaining the call status, and formatting phone numbers.

To subscribe to the call status, use [`observer.on('callStateChange')`](js-apis-observer.md#observeroncallstatechange).

>**NOTE**<br>
>
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

| Name     | Type                        | Mandatory| Description                                   |
| ----------- | ---------------------------- | ---- | --------------------------------------- |
| phoneNumber | string                       | Yes  | Phone number.                             |
| callback    | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.<br>- **true**: success<br>- **false**: failure|

**Example**

```js
call.dial("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.dial

dial\(phoneNumber: string, options: DialOptions, callback: AsyncCallback<boolean\>\): void

Initiates a call. You can set call options as needed. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.PLACE\_CALL (a system permission)

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                        | Mandatory| Description                                   |
| ----------- | ---------------------------- | ---- | --------------------------------------- |
| phoneNumber | string                       | Yes  | Phone number.                             |
| options     | [DialOptions](#dialoptions)  | Yes  | Call option, which indicates whether the call is a voice call or video call. |
| callback    | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.<br>- **true**: success<br>- **false**: failure|

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

Initiates a call. You can set call options as needed. This API uses a promise to return the result.

**Required permission**: ohos.permission.PLACE\_CALL (a system permission)

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                       | Mandatory| Description                                  |
| ----------- | --------------------------- | ---- | -------------------------------------- |
| phoneNumber | string                      | Yes  | Phone number.                            |
| options     | [DialOptions](#dialoptions) | Yes  | Call option, which indicates whether the call is a voice call or video call.|

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result.<br>- **true**: success<br>- **false**: failure|

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

| Name     | Type                     | Mandatory| Description                                      |
| ----------- | ------------------------- | ---- | ------------------------------------------ |
| phoneNumber | string                    | Yes  | Phone number.                                |
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

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

| Name     | Type  | Mandatory| Description      |
| ----------- | ------ | ---- | ---------- |
| phoneNumber | string | Yes  | Phone number.|

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

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

| Name  | Type                        | Mandatory| Description                                                        |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. Callback used to return the result.<br>- **true**: A call is in progress.<br>- **false**: No call is in progress.|

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
| Promise&lt;boolean&gt; | Promise used to return the result.|

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

| Name  | Type                                        | Mandatory| Description                                |
| -------- | -------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback&lt;[CallState](#callstate)&gt; | Yes  | Callback used to return the result.|

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
| Promise&lt;[CallState](#callstate)&gt; | Promise used to return the result.|

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
| boolean | - **true**: The device supports voice calls.<br>- **false**: The device does not support voice calls.|

```js
let result = call.hasVoiceCapability(); 
console.log(`hasVoiceCapability: ${JSON.stringify(result)}`);
```

## call.isEmergencyPhoneNumber<sup>7+</sup>

isEmergencyPhoneNumber\(phoneNumber: string, callback: AsyncCallback<boolean\>\): void

Checks whether the called number is an emergency number. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                        | Mandatory| Description                                                        |
| ----------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                       | Yes  | Phone number.                                                  |
| callback    | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.<br> - **true**: The called number is an emergency number.<br>- **false**: The called number is not an emergency number.|

**Example**

```js
call.isEmergencyPhoneNumber("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.isEmergencyPhoneNumber<sup>7+</sup>

isEmergencyPhoneNumber\(phoneNumber: string, options: EmergencyNumberOptions, callback: AsyncCallback<boolean\>\): void

Checks whether the called number is an emergency number based on the phone number. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                                              | Mandatory| Description                                                       |
| ----------- | -------------------------------------------------- | ---- | -------------------------------------------- |
| phoneNumber | string                                             | Yes  | Phone number.                                                 |
| options     | [EmergencyNumberOptions](#emergencynumberoptions7) | Yes  | Phone number option.        |
| callback    | AsyncCallback&lt;boolean&gt;                       | Yes  | Callback used to return the result.<br> - **true**: The called number is an emergency number.<br>- **false**: The called number is not an emergency number.|

**Example**

```js
call.isEmergencyPhoneNumber("112", {slotId: 1}, (err, value) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.isEmergencyPhoneNumber<sup>7+</sup>

isEmergencyPhoneNumber\(phoneNumber: string, options?: EmergencyNumberOptions\): Promise<boolean\>

Checks whether the called number is an emergency number based on the phone number. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                                              | Mandatory| Description          |
| ----------- | -------------------------------------------------- | ---- | -------------- |
| phoneNumber | string                                             | Yes  | Phone number.    |
| options     | [EmergencyNumberOptions](#emergencynumberoptions7) | Yes  | Phone number option.|

**Return value**

| Type                  | Description                                               |
| ---------------------- | --------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

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

| Name     | Type                       | Mandatory| Description                                |
| ----------- | --------------------------- | ---- | ------------------------------------ |
| phoneNumber | string                      | Yes  | Phone number.                          |
| callback    | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result.|

**Example**

```js
call.formatPhoneNumber("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## call.formatPhoneNumber<sup>7+</sup>

formatPhoneNumber\(phoneNumber: string, options: NumberFormatOptions, callback: AsyncCallback<string\>\): void

Formats a phone number based on specified formatting options. This API uses an asynchronous callback to return the result.

A formatted phone number is a standard numeric string, for example, 555 0100.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                                        | Mandatory| Description                                |
| ----------- | -------------------------------------------- | ---- | ------------------------------------ |
| phoneNumber | string                                       | Yes  | Phone number.                          |
| options     | [NumberFormatOptions](#numberformatoptions7) | Yes  | Number formatting option, for example, country code.              |
| callback    | AsyncCallback&lt;string&gt;                  | Yes  | Callback used to return the result.|

**Example**

```js
call.formatPhoneNumber("138xxxxxxxx",{
    countryCode: "CN"
}, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.formatPhoneNumber<sup>7+</sup>

formatPhoneNumber\(phoneNumber: string, options?: NumberFormatOptions\): Promise<string\>

Formats a phone number based on specified formatting options. This API uses a promise to return the result.

A formatted phone number is a standard numeric string, for example, 555 0100.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                                        | Mandatory| Description                  |
| ----------- | -------------------------------------------- | ---- | ---------------------- |
| phoneNumber | string                                       | Yes  | Phone number.            |
| options     | [NumberFormatOptions](#numberformatoptions7) | Yes  | Number formatting option, for example, country code.|

**Return value**

| Type                 | Description                                       |
| --------------------- | ------------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

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

| Name     | Type                       | Mandatory| Description                                                 |
| ----------- | --------------------------- | ---- | ----------------------------------------------------- |
| phoneNumber | string                      | Yes  | Phone number.                                           |
| countryCode | string                      | Yes  | Country code, for example, **CN** (China). All country codes are supported.             |
| callback    | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result.|

**Example**

```js
call.formatPhoneNumberToE164("138xxxxxxxx",{
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

| Name     | Type  | Mandatory| Description                                    |
| ----------- | ------ | ---- | ---------------------------------------- |
| phoneNumber | string | Yes  | Phone number.                              |
| countryCode | string | Yes  | Country code, for example, **CN** (China). All country codes are supported.|

**Return value**

| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; | Promise used to return the result.|

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

## DialOptions

Provides an option for determining whether a call is a video call.

**System capability**: SystemCapability.Telephony.CallManager

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| extras | boolean | No  | Indication of a video call. <br>- **true**: video call<br>- **false** (default): voice call|

## CallState

Enumerates call states.

**System capability**: SystemCapability.Telephony.CallManager

| Name              | Value  | Description                                                        |
| ------------------ | ---- | ------------------------------------------------------------ |
| CALL_STATE_UNKNOWN | -1   | The call status fails to be obtained and is unknown.                        |
| CALL_STATE_IDLE    | 0    | No call is in progress.                                    |
| CALL_STATE_RINGING | 1    | The call is in the ringing or waiting state.                                    |
| CALL_STATE_OFFHOOK | 2    | At least one call is in dialing, active, or on hold, and no new incoming call is ringing or waiting.|

## EmergencyNumberOptions<sup>7+</sup>

Provides an option for determining whether a number is an emergency number for the SIM card in the specified slot.

**System capability**: SystemCapability.Telephony.CallManager

| Name| Type  | Mandatory| Description                                          |
| ------ | ------ | ---- | ---------------------------------------------- |
| slotId | number | No  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

## NumberFormatOptions<sup>7+</sup>

Provides an option for number formatting.

**System capability**: SystemCapability.Telephony.CallManager

| Name     | Type  | Mandatory| Description                                                      |
| ----------- | ------ | ---- | ---------------------------------------------------------- |
| countryCode | string | No  | Country code, for example, **CN** (China). All country codes are supported. The default value is **CN**.|
