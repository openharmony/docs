# @ohos.telephony.call (Call)

The **call** module provides call management functions, including making calls, redirecting to the dial screen, obtaining the call status, and formatting phone numbers.

To subscribe to call status changes, use [`observer.on('callStateChange')`](js-apis-observer.md#observeroncallstatechange).

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { call } from '@kit.TelephonyKit';
```


## call.dial<sup>(deprecated)</sup>

dial\(phoneNumber: string, callback: AsyncCallback\<boolean\>\): void

Initiates a call. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. The substitute API is available only for system applications.

**Required permissions**: ohos.permission.PLACE_CALL (available only for system applications)

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                        | Mandatory| Description                                   |
| ----------- | ---------------------------- | ---- | --------------------------------------- |
| phoneNumber | string                       | Yes  | Phone number.                             |
| callback    | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.dial("138xxxxxxxx", (err: BusinessError, data: boolean) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.dial<sup>(deprecated)</sup>

dial\(phoneNumber: string, options: DialOptions, callback: AsyncCallback\<boolean\>\): void

Initiates a call. You can set call options as needed. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. The substitute API is available only for system applications.

**Required permissions**: ohos.permission.PLACE_CALL (available only for system applications)

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                        | Mandatory| Description                                   |
| ----------- | ---------------------------- | ---- | --------------------------------------- |
| phoneNumber | string                       | Yes  | Phone number.                             |
| options     | [DialOptions](#dialoptions)  | Yes  | Call option, which indicates whether the call is a voice call or video call. |
| callback    | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let dialOptions: call.DialOptions = {
    extras: false
}
call.dial("138xxxxxxxx", dialOptions, (err: BusinessError, data: boolean) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## call.dial<sup>(deprecated)</sup>

dial\(phoneNumber: string, options?: DialOptions\): Promise\<boolean\>

Initiates a call. You can set call options as needed. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. The substitute API is available only for system applications.

**Required permissions**: ohos.permission.PLACE_CALL (available only for system applications)

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                       | Mandatory| Description                                  |
| ----------- | --------------------------- | ---- | -------------------------------------- |
| phoneNumber | string                      | Yes  | Phone number.                            |
| options     | [DialOptions](#dialoptions) | No  | Call option, which indicates whether the call is a voice call or video call.|

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let dialOptions: call.DialOptions = {
    extras: false
}
call.dial("138xxxxxxxx", dialOptions).then((data: boolean) => {
    console.log(`dial success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`dial fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.makeCall<sup>7+</sup>

makeCall\(phoneNumber: string, callback: AsyncCallback\<void\>\): void

Launches the call screen and displays the dialed number. This API uses an asynchronous callback to return the result. This API can be called only in a UIAbility.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.Contacts

**Parameters**

| Name     | Type                     | Mandatory| Description                                      |
| ----------- | ------------------------- | ---- | ------------------------------------------ |
| phoneNumber | string                    | Yes  | Phone number.                                |
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
// The tel URI format is supported since API version 15, for example, tel:13xxxx.
call.makeCall("138xxxxxxxx", (err: BusinessError) => {
    if (err) {
        console.error(`makeCall fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`makeCall success`);
    }
});
```


## call.makeCall<sup>7+</sup>

makeCall\(phoneNumber: string\): Promise\<void\>

Launches the call screen and displays the dialed number. This API uses a promise to return the result. This API can be called only in a UIAbility.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Applications.Contacts

**Parameters**

| Name     | Type  | Mandatory| Description      |
| ----------- | ------ | ---- | ---------- |
| phoneNumber | string | Yes  | Phone number.|

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
// The tel URI format is supported since API version 15, for example, tel:13xxxx.
call.makeCall("138xxxxxxxx").then(() => {
    console.log(`makeCall success`);
}).catch((err: BusinessError) => {
    console.error(`makeCall fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.makeCall<sup>12+</sup>

makeCall\(context: Context, phoneNumber: string\): Promise\<void\>

Launches the call screen and displays the dialed number. This API uses a promise to return the result. You need to declare the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission if you want to call the API in the background.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Applications.Contacts

**Parameters**

| Name     | Type  | Mandatory| Description      |
| ----------- | ------ | ---- | ---------- |
| context | Context | Yes  | Application context.|
| phoneNumber | string | Yes  | Phone number.|

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

>**NOTE**
>
>In the sample code provided in this topic, **this.context** is used to obtain **UIAbilityContext**, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use UIAbilityContext APIs on pages, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';
// Obtain the application context.
let context = this.getUIContext().getHostContext() as Context;
// The tel URI format is supported since API version 15, for example, tel:13xxxx.
call.makeCall(context, "138xxxxxxxx").then(() => {
    console.log(`makeCall success`);
}).catch((err: BusinessError) => {
    console.error(`makeCall fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.hasCall

hasCall\(callback: AsyncCallback\<boolean\>\): void

Checks whether a call is in progress. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                        | Mandatory| Description                                                        |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** indicates that a call is in progress, and the value **false** indicates the opposite.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.hasCall((err: BusinessError, data: boolean) => {
    if (err) {
        console.error(`hasCall fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`hasCall success, data->${JSON.stringify(data)}`);
    }
});
```


## call.hasCall

hasCall\(\): Promise\<boolean\>

Checks whether a call is in progress. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type                  | Description                                   |
| ---------------------- | --------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that a call is in progress, and the value **false** indicates the opposite.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.hasCall().then(() => {
    console.log(`hasCall success`);
}).catch((err: BusinessError) => {
    console.error(`hasCall fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.hasCallSync<sup>10+</sup>

hasCallSync\(\): boolean

Checks whether a call is in progress.

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type                  | Description         |
| ---------------------- |-------------|
| boolean | Promise used to return the result. The value **true** indicates that a call is in progress, and the value **false** indicates the opposite.|

**Example**

```ts
let hasCall: boolean = call.hasCallSync();
console.log(`hasCallSync success, has call is ` + hasCall);
```


## call.getCallState

getCallState\(callback: AsyncCallback\<CallState\>\): void

Obtains the call status. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                        | Mandatory| Description                                |
| -------- | -------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback&lt;[CallState](#callstate)&gt; | Yes  | Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.getCallState((err: BusinessError, data: call.CallState) => {
    if (err) {
        console.error(`getCallState fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`getCallState success, data->${JSON.stringify(data)}`);
    }
});
```


## call.getCallState

getCallState\(\): Promise\<CallState\>

Obtains the call status. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type                                  | Description                                   |
| -------------------------------------- | --------------------------------------- |
| Promise&lt;[CallState](#callstate)&gt; | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.getCallState().then((data: call.CallState) => {
    console.log(`getCallState success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getCallState fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.getCallStateSync<sup>10+</sup>

getCallStateSync\(\): CallState

Obtains the call status.

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type                                 | Description         |
| ------------------------------------- |-------------|
| [CallState](#callstate) | Promise used to return the result.|

**Example**

```ts
let callState: call.CallState = call.getCallStateSync();
console.log(`the call state is:` + callState);
```

## call.hasVoiceCapability<sup>7+</sup>

hasVoiceCapability\(\): boolean

Checks whether a device supports voice calls.

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Result indicating whether the device supports voice calls. The value **true** indicates yes, and the value **false** indicates no.|

```ts
let result: boolean = call.hasVoiceCapability();
console.log(`hasVoiceCapability: ${JSON.stringify(result)}`);
```

## call.isEmergencyPhoneNumber<sup>7+</sup>

isEmergencyPhoneNumber\(phoneNumber: string, callback: AsyncCallback\<boolean\>\): void

Checks whether the called number is an emergency number. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                        | Mandatory| Description                                                        |
| ----------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                       | Yes  | Phone number.                                                  |
| callback    | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** indicates that the called number is an emergency number, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.isEmergencyPhoneNumber("138xxxxxxxx", (err: BusinessError, data: boolean) => {
    if (err) {
        console.error(`isEmergencyPhoneNumber fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`isEmergencyPhoneNumber success, data->${JSON.stringify(data)}`);
    }
});
```


## call.isEmergencyPhoneNumber<sup>7+</sup>

isEmergencyPhoneNumber\(phoneNumber: string, options: EmergencyNumberOptions, callback: AsyncCallback\<boolean\>\): void

Checks whether the called number is an emergency number based on the phone number. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                                              | Mandatory| Description                                                        |
| ----------- | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                                             | Yes  | Phone number.                                                  |
| options     | [EmergencyNumberOptions](#emergencynumberoptions7) | Yes  | Emergency number options.                                              |
| callback    | AsyncCallback&lt;boolean&gt;                       | Yes  | Callback used to return the result. The value **true** indicates that the called number is an emergency number, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let options: call.EmergencyNumberOptions = {slotId: 1}
call.isEmergencyPhoneNumber("112", options, (err: BusinessError, data: boolean) => {
    if (err) {
        console.error(`isEmergencyPhoneNumber fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`isEmergencyPhoneNumber success, data->${JSON.stringify(data)}`);
    }
});
```


## call.isEmergencyPhoneNumber<sup>7+</sup>

isEmergencyPhoneNumber\(phoneNumber: string, options?: EmergencyNumberOptions\): Promise\<boolean\>

Checks whether the called number is an emergency number based on the phone number. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                                              | Mandatory| Description          |
| ----------- | -------------------------------------------------- | ---- | -------------- |
| phoneNumber | string                                             | Yes  | Phone number.    |
| options     | [EmergencyNumberOptions](#emergencynumberoptions7) | No  | Emergency number options.|

**Return value**

| Type                  | Description                                               |
| ---------------------- | --------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that the called number is an emergency number, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let options: call.EmergencyNumberOptions = {slotId: 1}
call.isEmergencyPhoneNumber("138xxxxxxxx", options).then((data: boolean) => {
    console.log(`isEmergencyPhoneNumber success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isEmergencyPhoneNumber fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.formatPhoneNumber<sup>7+</sup>

formatPhoneNumber\(phoneNumber: string, callback: AsyncCallback\<string\>\): void

Formats a phone number. This API uses an asynchronous callback to return the result.

A formatted phone number is a standard numeric string, for example, 555 0100.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                       | Mandatory| Description                                |
| ----------- | --------------------------- | ---- | ------------------------------------ |
| phoneNumber | string                      | Yes  | Phone number.                          |
| callback    | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.formatPhoneNumber("138xxxxxxxx", (err: BusinessError, data: string) => {
    if (err) {
        console.error(`formatPhoneNumber fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`formatPhoneNumber success, data->${JSON.stringify(data)}`);
    }
});
```

## call.formatPhoneNumber<sup>7+</sup>

formatPhoneNumber\(phoneNumber: string, options: NumberFormatOptions, callback: AsyncCallback\<string\>\): void

Formats a phone number based on specified formatting options. This API uses an asynchronous callback to return the result.

A formatted phone number is a standard numeric string, for example, 555 0100.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                                        | Mandatory| Description                                |
| ----------- | -------------------------------------------- | ---- | ------------------------------------ |
| phoneNumber | string                                       | Yes  | Phone number.                          |
| options     | [NumberFormatOptions](#numberformatoptions7) | Yes  | Number formatting options, for example, country code.              |
| callback    | AsyncCallback&lt;string&gt;                  | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let options: call.NumberFormatOptions = {
    countryCode: "CN"
}
call.formatPhoneNumber("138xxxxxxxx", options, (err: BusinessError, data: string) => {
    if (err) {
        console.error(`formatPhoneNumber fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`formatPhoneNumber success, data->${JSON.stringify(data)}`);
    }
});
```


## call.formatPhoneNumber<sup>7+</sup>

formatPhoneNumber\(phoneNumber: string, options?: NumberFormatOptions\): Promise\<string\>

Formats a phone number based on specified formatting options. This API uses a promise to return the result.

A formatted phone number is a standard numeric string, for example, 555 0100.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                                        | Mandatory| Description                  |
| ----------- | -------------------------------------------- | ---- | ---------------------- |
| phoneNumber | string                                       | Yes  | Phone number.            |
| options     | [NumberFormatOptions](#numberformatoptions7) | No  | Number formatting options, for example, country code.|

**Return value**

| Type                 | Description                                       |
| --------------------- | ------------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let options: call.NumberFormatOptions = {
    countryCode: "CN"
}
call.formatPhoneNumber("138xxxxxxxx", options).then((data: string) => {
    console.log(`formatPhoneNumber success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`formatPhoneNumber fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.formatPhoneNumberToE164<sup>7+</sup>

formatPhoneNumberToE164\(phoneNumber: string, countryCode: string, callback: AsyncCallback\<string\>\): void

Converts a phone number into the E.164 format. This API uses an asynchronous callback to return the result.

The phone number must match the specified country code. For example, for a China phone number, the country code must be **CN**. Otherwise, **null** will be returned.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                       | Mandatory| Description                                                 |
| ----------- | --------------------------- | ---- | ----------------------------------------------------- |
| phoneNumber | string                      | Yes  | Phone number.                                           |
| countryCode | string                      | Yes  | Country code, for example, **CN** (China). All country codes are supported.             |
| callback    | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.formatPhoneNumberToE164("138xxxxxxxx", "CN", (err: BusinessError, data: string) => {
    if (err) {
        console.error(`formatPhoneNumberToE164 fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`formatPhoneNumberToE164 success, data->${JSON.stringify(data)}`);
    }
});
```


## call.formatPhoneNumberToE164<sup>7+</sup>

formatPhoneNumberToE164\(phoneNumber: string, countryCode: string\): Promise\<string\>

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

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.formatPhoneNumberToE164("138xxxxxxxx", "CN").then((data: string) => {
    console.log(`formatPhoneNumberToE164 success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`formatPhoneNumberToE164 fail, promise: err->${JSON.stringify(err)}`);
});
```

## DialOptions

Provides an option for determining whether a call is a video call.

**System capability**: SystemCapability.Telephony.CallManager

|        Name             | Type                              | Mandatory| Description                                                                                            |
| ------------------------ | ---------------------------------- | ---- | ----------------------------------------------------------------------------------------------- |
| extras                   | boolean                            | No  | Whether the call is a video call. <br>- **true**: video call<br>- **false** (default): voice call  | 

## CallState

Enumerates call states.

**System capability**: SystemCapability.Telephony.CallManager

| Name              | Value  | Description                                                        |
| ------------------ | ---- | ------------------------------------------------------------ |
| CALL_STATE_UNKNOWN | -1   | The call status fails to be obtained and is unknown.                        |
| CALL_STATE_IDLE    | 0    | No call is in progress.                                    |
| CALL_STATE_RINGING | 1    | The call is in the ringing or waiting state.                                    |
| CALL_STATE_OFFHOOK | 2    | At least one call is in dialing, active, or on hold, and no new incoming call is ringing or waiting.|
| CALL_STATE_ANSWERED<sup>11+</sup> | 3    | The incoming call is answered.|

## EmergencyNumberOptions<sup>7+</sup>

Provides an option for determining whether a number is an emergency number for the SIM card in the specified slot.

**System capability**: SystemCapability.Telephony.CallManager

|  Name | Type  | Mandatory| Description                                          |
| ------ | ------ | ---- | ---------------------------------------------- |
| slotId | number | No  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

## NumberFormatOptions<sup>7+</sup>

Provides an option for number formatting.

**System capability**: SystemCapability.Telephony.CallManager

|    Name    | Type  | Mandatory| Description                                                      |
| ----------- | ------ | ---- | ---------------------------------------------------------- |
| countryCode | string | No  | Country code, for example, **CN** (China). All country codes are supported. The default value is **CN**.|
