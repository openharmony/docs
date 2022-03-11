# Call

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import call from '@ohos.telephony.call';
```

## call.dial<a name=call.dial-callback1></a>

dial\(phoneNumber: string, callback: AsyncCallback<boolean\>\): void

Initiates a call. This function uses an asynchronous callback to return the execution result.

**Required permission**: ohos.permission.PLACE\_CALL (a system permission)

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name       | Type                        | Mandatory| Description                                             |
| ----------- | ---------------------------- | ---- | ------------------------------------------------- |
| phoneNumber | string                       | Yes  | Phone number.                                       |
| callback    | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.<br>- **true**: success<br>- **false**: failure|

**Example**

```
call.dial("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.dial<a name=call.dial-callback2></a>

dial\(phoneNumber: string, options: DialOptions, callback: AsyncCallback<boolean\>\): void

Initiates a call. You can set call options as needed. This function uses an asynchronous callback to return the execution result.

**Required permission**: ohos.permission.PLACE\_CALL (a system permission)

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name       | Type                        | Mandatory| Description                                             |
| ----------- | ---------------------------- | ---- | ------------------------------------------------- |
| phoneNumber | string                       | Yes  | Phone number.                                       |
| options     | DialOptions                  | Yes  | Call options. For details, see [DialOptions](#DialOptions).      |
| callback    | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.<br>- **true**: success<br>- **false**: failure|

**Example**

```
call.dial("138xxxxxxxx", {
    extras: false
}, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.dial<a name=call.dial-promise></a>

dial\(phoneNumber: string, options?: DialOptions\): Promise<boolean\>

Initiates a call. You can set call options as needed. This function uses a promise to return the execution result.

**Required permission**: ohos.permission.PLACE\_CALL (a system permission)

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name       | Type       | Mandatory| Description                                       |
| ----------- | ----------- | ---- | ------------------------------------------- |
| phoneNumber | string      | Yes  | Phone number.                                 |
| options     | DialOptions | Yes  | Call options. For details, see [DialOptions](#DialOptions).|

**Return Value**

| Type                  | Description                             |
| ---------------------- | --------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

```
let promise = call.dial("138xxxxxxxx", {
    extras: false
});
promise.then(data => {
    console.log(`dial success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`dial fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.makeCall<sup>7+</sup><a name=call.makeCall-callback></a>

makeCall(phoneNumber: string, callback: AsyncCallback<void>): void

Launches the call screen and displays the dialed number. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name       | Type                     | Mandatory| Description                                      |
| ----------- | ------------------------- | ---- | ------------------------------------------ |
| phoneNumber | string                    | Yes  | Phone number.                                |
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```
call.makeCall("138xxxxxxxx", err => { 
    console.log(`makeCall callback: err->${JSON.stringify(err)}`); 
});
```


## call.makeCall<sup>7+</sup><a name=call.makeCall-promise></a>

makeCall(phoneNumber: string): Promise<void>

Launches the call screen and displays the dialed number. This method uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name       | Type  | Mandatory| Description      |
| ----------- | ------ | ---- | ---------- |
| phoneNumber | string | Yes  | Phone number.|

**Return Value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```
let promise = call.makeCall("138xxxxxxxx"); 
promise.then(() => { 
    console.log(`makeCall success`); 
}).catch(err => { 
    console.error(`makeCall fail, promise: err->${JSON.stringify(err)}`); 
});
```

## call.hasCall<a name=call.hasCall-callback></a>

hasCall\(callback: AsyncCallback<boolean\>\): void

Checks whether a call is in progress. This function uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name    | Type                        | Mandatory| Description                                                        |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.<br>- **true**: A call is in progress.<br>- **false**: No call is in progress.|

**Example**

```
call.hasCall((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.hasCall<a name=call.hasCall-promise></a>

hasCall\(\): Promise<boolean\>

Checks whether a call is in progress. This function uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Return Value**

| Type                  | Description                                   |
| ---------------------- | --------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

```
let promise = call.hasCall();
promise.then(data => {
    console.log(`hasCall success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`hasCall fail, promise: err->${JSON.stringify(err)}`);
});
```


## call.getCallState<a name=call.getCallState-callback></a>

getCallState\(callback: AsyncCallback<CallState\>\): void

Obtains the call status. This function uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name    | Type                                        | Mandatory| Description                                |
| -------- | -------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback&lt;[CallState](#CallState)&gt; | Yes  | Callback used to return the result.|

**Example**

```
call.getCallState((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.getCallState<a name="call.getCallState-promise"></a>

getCallState\(\): Promise<CallState\>

Obtains the call status. This function uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Return Value**

| Type                                  | Description                                     |
| -------------------------------------- | ----------------------------------------- |
| Promise&lt;[CallState](#CallState)&gt; | Promise used to return the result.|

**Example**

```
let promise = call.getCallState();
promise.then(data => {
    console.log(`getCallState success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getCallState fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.hasVoiceCapability<sup>7+</sup><a name=call.hasVoiceCapability></a>

hasVoiceCapability(): boolean

Checks whether a device supports voice calls. This function works in synchronous mode.

**System capability**: SystemCapability.Telephony.CallManager

**Return Value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | - **true**: The device supports voice calls.<br>- **false**: The device does not support voice calls.|

```
let result = call.hasVoiceCapability(); 
console.log(`hasVoiceCapability: ${JSON.stringify(result)}`);
```

## call.isEmergencyPhoneNumber<sup>7+</sup><a name=call.isEmergencyPhoneNumber-callback1></a>

isEmergencyPhoneNumber\(phoneNumber: string, callback: AsyncCallback<boolean\>\): void

Checks whether the call number of the SIM card in the specified slot is an emergency number. This function uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name       | Type                        | Mandatory| Description                                                        |
| ----------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                       | Yes  | Phone number.                                                  |
| callback    | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.<br>- **true**: The called number is an emergency number.<br>- **false**: The called number is not an emergency number.|

**Example**

```
call.isEmergencyPhoneNumber("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.isEmergencyPhoneNumber<sup>7+</sup><a name=call.isEmergencyPhoneNumber-callback2></a>

isEmergencyPhoneNumber\(phoneNumber: string, options: EmergencyNumberOptions, callback: AsyncCallback<boolean\>\): void

Checks whether the call number of the SIM card in the specified slot is an emergency number. This function uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name       | Type                        | Mandatory| Description                                                        |
| ----------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                       | Yes  | Phone number.                                                  |
| options     | EmergencyNumberOptions       | Yes  | Emergency number options defined in [EmergencyNumberOptions](#EmergencyNumberOptions).|
| callback    | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.<br>- **true**: The called number is an emergency number.<br>- **false**: The called number is not an emergency number.|

**Example**

```
call.isEmergencyPhoneNumber("112", {slotId: 1}, (err, value) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.isEmergencyPhoneNumber<sup>7+</sup><a name=call.isEmergencyPhoneNumber-promise></a>

isEmergencyPhoneNumber\(phoneNumber: string, options?: EmergencyNumberOptions\): Promise<boolean\>

Checks whether the call number of the SIM card in the specified slot is an emergency number. This function uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name       | Type                  | Mandatory| Description                                                        |
| ----------- | ---------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                 | Yes  | Phone number.                                                  |
| options     | EmergencyNumberOptions | Yes  | Emergency number options defined in [EmergencyNumberOptions](#EmergencyNumberOptions).|

**Return Value**

| Type                  | Description                                               |
| ---------------------- | --------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

```
let promise = call.isEmergencyPhoneNumber("138xxxxxxxx", {slotId: 1});
promise.then(data => {
    console.log(`isEmergencyPhoneNumber success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`isEmergencyPhoneNumber fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.formatPhoneNumber<sup>7+</sup><a name=call.formatPhoneNumber-callback1></a>

formatPhoneNumber\(phoneNumber: string, callback: AsyncCallback<string\>\): void

Formats a phone number based on the specified ISO country code. This function uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name       | Type                       | Mandatory| Description                                |
| ----------- | --------------------------- | ---- | ------------------------------------ |
| phoneNumber | string                      | Yes  | Phone number.                          |
| callback    | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result.|

**Example**

```
call.formatPhoneNumber("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.formatPhoneNumber<sup>7+</sup><a name=call.formatPhoneNumber-callback2></a>

formatPhoneNumber\(phoneNumber: string, options: NumberFormatOptions, callback: AsyncCallback<string\>\): void

Formats a phone number based on specified formatting options. This function uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name       | Type                       | Mandatory| Description                                                        |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                      | Yes  | Phone number.                                                  |
| options     | NumberFormatOptions         | Yes  | Number formatting options defined in [NumberFormatOptions](#NumberFormatOptions).|
| callback    | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result.                        |

**Example**

```
call.formatPhoneNumber("138xxxxxxxx",{
    countryCode: "CN"
}, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.formatPhoneNumber<sup>7+</sup><a name=call.formatPhoneNumber-promise></a>

formatPhoneNumber\(phoneNumber: string, options?: NumberFormatOptions\): Promise<string\>

Formats a phone number based on specified formatting options. This function uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name       | Type               | Mandatory| Description                                                        |
| ----------- | ------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string              | Yes  | Phone number.                                                  |
| options     | NumberFormatOptions | Yes  | Number formatting options defined in [NumberFormatOptions](#NumberFormatOptions).|

**Return Value**

| Type                 | Description                                       |
| --------------------- | ------------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**

```
let promise = call.formatPhoneNumber("138xxxxxxxx", {
    countryCode: "CN"
});
promise.then(data => {
    console.log(`formatPhoneNumber success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`formatPhoneNumber fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.formatPhoneNumberToE164<sup>7+</sup><a name=call.formatPhoneNumberToE164-callback></a>

formatPhoneNumberToE164\(phoneNumber: string, countryCode: string, callback: AsyncCallback<string\>\): void

Converts a phone number into the E.164 format. This function uses an asynchronous callback to return the result.

The phone number must match the specified country code. For example, for a China phone number, the country code must be **CN**. Otherwise, **null** will be returned.

All country codes are supported.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name       | Type                       | Mandatory| Description                                                 |
| ----------- | --------------------------- | ---- | ----------------------------------------------------- |
| phoneNumber | string                      | Yes  | Phone number.                                           |
| countryCode | string                      | Yes  | Country code, for example, **CN** (China). All country codes are supported.             |
| callback    | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result.|

**Example**

```
call.formatPhoneNumberToE164("138xxxxxxxx",{
    countryCode: "CN"
}, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.formatPhoneNumberToE164<sup>7+</sup><a name=call.formatPhoneNumberToE164-promise></a>

formatPhoneNumberToE164\(phoneNumber: string, countryCode: string\): Promise<string\>

Converts a phone number into the E.164 format. This function uses a promise to return the result.

The phone number must match the specified country code. For example, for a China phone number, the country code must be **CN**. Otherwise, **null** will be returned.

All country codes are supported.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name       | Type  | Mandatory| Description                                    |
| ----------- | ------ | ---- | ---------------------------------------- |
| phoneNumber | string | Yes  | Phone number.                              |
| countryCode | string | Yes  | Country code, for example, **CN** (China). All country codes are supported.|

**Return Value**

| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**

```
let promise = call.formatPhoneNumberToE164("138xxxxxxxx", {
    countryCode: "CN"
});
promise.then(data => {
    console.log(`formatPhoneNumberToE164 success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`formatPhoneNumberToE164 fail, promise: err->${JSON.stringify(err)}`);
});
```

## DialOptions<a name=DialOptions></a>

Provides an option for determining whether a call is a video call.

**System capability**: SystemCapability.Telephony.CallManager

| Parameter  | Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| extras | boolean | No  | Indication of a video call. <br>- **true**: video call<br>- **false** (default): voice call|

## CallState<a name=CallState></a>

Enumerates call states.

| Variable              | Value  | Description                                                        |
| ------------------ | ---- | ------------------------------------------------------------ |
| CALL_STATE_UNKNOWN | -1   | The call status fails to be obtained and is unknown.<br>**System capability**: SystemCapability.Telephony.CallManager|
| CALL_STATE_IDLE    | 0    | No call is in progress.<br>**System capability**: SystemCapability.Telephony.CallManager|
| CALL_STATE_RINGING | 1    | The call is in the ringing or waiting state.<br>**System capability**: SystemCapability.Telephony.CallManager|
| CALL_STATE_OFFHOOK | 2    | At least one call is in dialing, active, or on hold, and no new incoming call is ringing or waiting.<br>**System capability**: SystemCapability.Telephony.CallManager|

## EmergencyNumberOptions<sup>7+</sup><a name=EmergencyNumberOptions></a>

Provides an option for determining whether a number is an emergency number for the SIM card in the specified slot.

**System capability**: SystemCapability.Telephony.CallManager

| Parameter  | Type  | Mandatory| Description                                      |
| ------ | ------ | ---- | ------------------------------------------ |
| slotId | number | No  | Card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2|

## NumberFormatOptions<sup>7+</sup><a name=NumberFormatOptions></a>

Provides an option for number formatting.

**System capability**: SystemCapability.Telephony.CallManager

| Parameter       | Type  | Mandatory| Description                                                      |
| ----------- | ------ | ---- | ---------------------------------------------------------- |
| countryCode | string | No  | Country code, for example, **CN** (China). All country codes are supported. The default value is **CN**.|
