# @ohos.telephony.call (Call) (System API)

The **call** module provides call management functions, including making calls, redirecting to the dial screen, obtaining the call status, and formatting phone numbers.

To subscribe to call status changes, use [`observer.on('callStateChange')`](js-apis-observer.md#observeroncallstatechange).

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.telephony.call (Call)](js-apis-call.md).


## Modules to Import

```ts
import { call } from '@kit.TelephonyKit';
```

## call.dialCall<sup>9+</sup>

dialCall\(phoneNumber: string, callback: AsyncCallback\<void\>\): void

Initiates a call. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required Permissions**: ohos.permission.PLACE_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                        | Mandatory| Description                                   |
| ----------- | ---------------------------- | ---- | -------------------------------------- |
| phoneNumber | string                       | Yes  | Phone number.                             |
| callback    | AsyncCallback&lt;void&gt;    | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300005  | Airplane mode is on.                         |
| 8300006  | Network not in service.                      |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.dialCall("138xxxxxxxx", (err: BusinessError) => {
    if (err) {
        console.error(`dialCall fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`dialCall success.`);
    }
});
```


## call.dialCall<sup>9+</sup>

dialCall\(phoneNumber: string, options: DialCallOptions, callback: AsyncCallback\<void\>\): void

Initiates a call. You can set call options as needed. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required Permissions**: ohos.permission.PLACE_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     |                    Type            | Mandatory| Description                                |
| ----------- | ----------------------------------- | ---- | ----------------------------------- |
| phoneNumber | string                              | Yes  | Phone number.                          |
| options     | [DialCallOptions](#dialcalloptions9)| Yes  | Call options, which carry other configuration information of the call.   |
| callback    | AsyncCallback&lt;void&gt;           | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300005  | Airplane mode is on.                         |
| 8300006  | Network not in service.                      |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let dialCallOptions: call.DialCallOptions = {
    accountId: 0,
    videoState: 0,
    dialScene: 0,
    dialType: 0
}
call.dialCall("138xxxxxxxx", dialCallOptions, (err: BusinessError) => {
    if (err) {
        console.error(`dialCall fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`dialCall success.`);
    }
});
```


## call.dialCall<sup>9+</sup>

dialCall\(phoneNumber: string, options?: DialCallOptions\): Promise\<void\>

Initiates a call. You can set call options as needed. This API uses a promise to return the result.

**System API**: This is a system API.

**Required Permissions**: ohos.permission.PLACE_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     |                 Type               | Mandatory|                Description                   |
| ----------- | ----------------------------------- | ---- | -------------------------------------- |
| phoneNumber | string                              | Yes  | Phone number.                            |
| options     | [DialCallOptions](#dialcalloptions9)| No  | Call options, which carry other configuration information of the call.<br>If this field is not set, the following configuration is used by default. For details, see [DialCallOptions](#dialcalloptions9).<br>- **accountId**: 0 (card slot 1)<br>- **videoState**: voice call<br>- **dialScene**: common call<br>- **dialType**: carrier call |

**Return value**

| Type                  | Description                         |
| ---------------------- | ---------------------------- |
| Promise&lt;void&gt;    | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300005  | Airplane mode is on.                         |
| 8300006  | Network not in service.                      |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let dialCallOptions: call.DialCallOptions = {
    accountId: 0,
    videoState: 0,
    dialScene: 0,
    dialType: 0
}
call.dialCall("138xxxxxxxx", dialCallOptions).then(() => {
    console.log(`dialCall success.`);
}).catch((err: BusinessError) => {
    console.error(`dialCall fail, promise: err->${JSON.stringify(err)}`);
});
```


## call.muteRinger<sup>8+</sup>

muteRinger\(callback: AsyncCallback\<void\>\): void

Mutes the ringtone while it is playing. It does not work if the ringtone has been muted. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                     | Mandatory| Description      |
| ----------- | ------------------------- | ---- | ---------- |
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.muteRinger((err: BusinessError) => {
    if (err) {
        console.error(`muteRinger fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`muteRinger success.`);
    }
});
```


## call.muteRinger<sup>8+</sup>

muteRinger\(\): Promise\<void\>

Mutes the ringtone while it is playing. It does not work if the ringtone has been muted. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.muteRinger().then(() => {
    console.log(`muteRinger success.`);
}).catch((err: BusinessError) => {
    console.error(`muteRinger fail, promise: err->${JSON.stringify(err)}`);
});
```


## call.answerCall<sup>9+</sup>

answerCall\(callId: number, callback: AsyncCallback\<void\>\): void

Answers a call. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description                                           |
| -------- | ------------------------- | ---- | ----------------------------------------------- |
| callId   | number                    | Yes  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.           |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.answerCall(1, (err: BusinessError) => {
    if (err) {
        console.error(`answerCall fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`answerCall success.`);
    }
});
```


## call.answerCall<sup>9+</sup>

answerCall(callId?: number\): Promise\<void\>

Answers a call. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| callId | number | No  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events. This field is optional from API version 9.<br>If this field is not set, the latest ringing call will be connected.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.answerCall(1).then(() => {
    console.log(`answerCall success.`);
}).catch((err: BusinessError) => {
    console.error(`answerCall fail, promise: err->${JSON.stringify(err)}`);
});
```


## call.answerCall<sup>9+</sup>

answerCall\(callback: AsyncCallback\<void\>\): void

Answers a call. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.answerCall((err: BusinessError) => {
    if (err) {
        console.error(`answerCall fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`answerCall success.`);
    }
});
```


## call.hangUpCall<sup>9+</sup>

hangUpCall\(callId: number, callback: AsyncCallback\<void\>\): void

Ends a call. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description                                           |
| -------- | ------------------------- | ---- | ----------------------------------------------- |
| callId   | number                    | Yes  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.           |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.hangUpCall(1, (err: BusinessError) => {
    if (err) {
        console.error(`hangUpCall fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`hangUpCall success.`);
    }
});
```


## call.hangUpCall<sup>9+</sup>

hangUpCall\(callId?: number\): Promise\<void\>

Ends a call. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| callId | number | No  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events. This field is optional from API version 9.<br>If this field is not set, the latest ongoing, dialed, or connected call will be ended.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.hangUpCall(1).then(() => {
    console.log(`hangUpCall success.`);
}).catch((err: BusinessError) => {
    console.error(`hangUpCall fail, promise: err->${JSON.stringify(err)}`);
});
```


## call.hangUpCall<sup>9+</sup>

hangUpCall\(callback: AsyncCallback\<void\>\): void

Ends a call. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.hangUpCall((err: BusinessError) => {
    if (err) {
        console.error(`hangUpCall fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`hangUpCall success.`);
    }
});
```


## call.rejectCall<sup>9+</sup>

rejectCall\(callId: number, callback: AsyncCallback\<void\>\): void

Rejects a call. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description                                           |
| -------- | ------------------------- | ---- | ----------------------------------------------- |
| callId   | number                    | Yes  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.rejectCall(1, (err: BusinessError) => {
    if (err) {
        console.error(`rejectCall fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`rejectCall success.`);
    }
});
```


## call.rejectCall<sup>9+</sup>

rejectCall\(callId: number, options: RejectMessageOptions, callback: AsyncCallback\<void\>\): void

Rejects a call. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                          | Mandatory| Description                                           |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| callId   | number                                         | Yes  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events.|
| options  | [RejectMessageOptions](#rejectmessageoptions7) | Yes  | Options for the call rejection message.                                 |
| callback | AsyncCallback&lt;void&gt;                      | Yes  | Callback used to return the result.           |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let rejectMessageOptions : call.RejectMessageOptions = {
    messageContent: "Unknown number blocked"
}
call.rejectCall(1, rejectMessageOptions, (err: BusinessError) => {
    if (err) {
        console.error(`rejectCall fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`rejectCall success.`);
    }
});
```


## call.rejectCall<sup>9+</sup>

rejectCall\(callId?: number, options?: RejectMessageOptions\): Promise\<void\>

Rejects a call. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name | Type                                          | Mandatory| Description                                                        |
| ------- | ---------------------------------------------- | ---- | ------------------------------------------------------------ |
| callId  | number                                         | No  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events. This field is optional from API version 9.<br>If this field is not set, the latest ringing call will be rejected.|
| options | [RejectMessageOptions](#rejectmessageoptions7) | No  | Options for the call rejection message. If this field is not set, no call rejection message will be sent.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let rejectMessageOptions: call.RejectMessageOptions = {
    messageContent: "Unknown number blocked"
}
call.rejectCall(1, rejectMessageOptions).then(() => {
    console.log(`rejectCall success.`);
}).catch((err: BusinessError) => {
    console.error(`rejectCall fail, promise: err->${JSON.stringify(err)}`);
});
```


## call.rejectCall<sup>9+</sup>

rejectCall\(callback: AsyncCallback\<void\>\): void

Rejects a call. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.rejectCall((err: BusinessError) => {
    if (err) {
        console.error(`rejectCall fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`rejectCall success.`);
    }
});
```


## call.rejectCall<sup>9+</sup>

rejectCall\(options: RejectMessageOptions, callback: AsyncCallback\<void\>\): void

Rejects a call. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                          | Mandatory| Description          |
| -------- | ---------------------------------------------- | ---- | -------------- |
| options  | [RejectMessageOptions](#rejectmessageoptions7) | Yes  | Options for the call rejection message.|
| callback | AsyncCallback&lt;void&gt;                      | Yes  | Callback used to return the result.    |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let rejectMessageOptions: call.RejectMessageOptions = {
    messageContent: "Unknown number blocked"
}
call.rejectCall(rejectMessageOptions, (err: BusinessError) => {
    if (err) {
        console.error(`rejectCall fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`rejectCall success.`);
    }
});
```


## call.holdCall<sup>7+</sup>

holdCall\(callId: number, callback: AsyncCallback\<void\>\): void

Holds a call based on the specified call ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | Yes  | Call ID.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.holdCall(1, (err: BusinessError) => {
    if (err) {
        console.error(`holdCall fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`holdCall success.`);
    }
});
```


## call.holdCall<sup>7+</sup>

holdCall\(callId: number\): Promise\<void\>

Holds a call based on the specified call ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.holdCall(1).then(() => {
    console.log(`holdCall success.`);
}).catch((err: BusinessError) => {
    console.error(`holdCall fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.unHoldCall<sup>7+</sup>

unHoldCall\(callId: number, callback: AsyncCallback\<void\>\): void

Unholds a call based on the specified call ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | Yes  | Call ID.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.unHoldCall(1, (err: BusinessError) => {
    if (err) {
        console.error(`unHoldCall fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`unHoldCall success.`);
    }
});
```


## call.unHoldCall<sup>7+</sup>

unHoldCall\(callId: number\): Promise\<void\>

Unholds a call based on the specified call ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.unHoldCall(1).then(() => {
    console.log(`unHoldCall success.`);
}).catch((err: BusinessError) => {
    console.error(`unHoldCall fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.switchCall<sup>7+</sup>

switchCall\(callId: number, callback: AsyncCallback\<void\>\): void

Switches a call. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | Yes  | Call ID.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.switchCall(1, (err: BusinessError) => {
    if (err) {
        console.error(`switchCall fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`switchCall success.`);
    }
});
```


## call.switchCall<sup>7+</sup>

switchCall\(callId: number\): Promise\<void\>

Switches a call. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.switchCall(1).then(() => {
    console.log(`switchCall success.`);
}).catch((err: BusinessError) => {
    console.error(`switchCall fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.combineConference<sup>11+</sup>

combineConference\(callId: number, callback: AsyncCallback\<void\>\): void

Combines two calls into a conference call. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | Yes  | Call ID.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300007  | The number of conference calls exceeds the limit. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.combineConference(1, (err: BusinessError) => {
    if (err) {
        console.error(`combineConference fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`combineConference success.`);
    }
});
```


## call.combineConference<sup>11+</sup>

combineConference\(callId: number\): Promise\<void\>

Combines two calls into a conference call. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300007  | The number of conference calls exceeds the limit. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.combineConference(1).then(() => {
    console.log(`combineConference success.`);
}).catch((err: BusinessError) => {
    console.error(`combineConference fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.kickOutFromConference<sup>10+</sup>

kickOutFromConference\(callId: number, callback: AsyncCallback\<void\>\): void

Removes a specified call from a conference call. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required Permissions**: ohos.permission.PLACE_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | Yes  | Call ID.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.kickOutFromConference(1, (err: BusinessError) => {
    if (err) {
        console.error(`kickOutFromConference fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`kickOutFromConference success.`);
    }
});
```

## call.kickOutFromConference<sup>10+</sup>

kickOutFromConference\(callId: number\): Promise\<void\>

Removes a specified call from a conference call. This API uses a promise to return the result.

**System API**: This is a system API.

**Required Permissions**: ohos.permission.PLACE_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.kickOutFromConference(1).then(() => {
    console.log(`kickOutFromConference success.`);
}).catch((err: BusinessError) => {
    console.error(`kickOutFromConference fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.getMainCallId<sup>7+</sup>

getMainCallId\(callId: number, callback: AsyncCallback\<number\>\): void

Obtains the main call ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                       | Mandatory| Description                    |
| -------- | --------------------------- | ---- | ------------------------ |
| callId   | number                      | Yes  | Call ID.                |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.getMainCallId(1, (err: BusinessError, data: number) => {
    if (err) {
        console.error(`getMainCallId fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`getMainCallId success, data->${JSON.stringify(data)}`);
    }
});
```


## call.getMainCallId<sup>7+</sup>

getMainCallId\(callId: number\): Promise\<number\>

Obtains the main call ID. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.getMainCallId(1).then((data: number) => {
    console.log(`getMainCallId success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getMainCallId fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.getSubCallIdList<sup>7+</sup>

getSubCallIdList\(callId: number, callback: AsyncCallback\<Array\<string\>\>\): void

Obtains the list of subcall IDs. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                          | Mandatory| Description                        |
| -------- | ------------------------------ | ---- | ---------------------------- |
| callId   | number                         | Yes  | Call ID.                    |
| callback | AsyncCallback<Array<string\>\> | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.getSubCallIdList(1, (err: BusinessError, data: Array<string>) => {
    if (err) {
        console.error(`getSubCallIdList fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`getSubCallIdList success, data->${JSON.stringify(data)}`);
    }
});
```


## call.getSubCallIdList<sup>7+</sup>

getSubCallIdList\(callId: number\): Promise\<Array\<string\>\>

Obtains the list of subcall IDs. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type                         | Description                               |
| ----------------------------- | ----------------------------------- |
| Promise&lt;Array<string\>&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.getSubCallIdList(1).then((data: Array<string>) => {
    console.log(`getSubCallIdList success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSubCallIdList fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.getCallIdListForConference<sup>7+</sup>

getCallIdListForConference\(callId: number, callback: AsyncCallback\<Array\<string\>\>\): void

Obtains the list of call IDs in a conference. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                               | Mandatory| Description                            |
| -------- | ----------------------------------- | ---- | -------------------------------- |
| callId   | number                              | Yes  | Call ID.                        |
| callback | AsyncCallback&lt;Array<string\>&gt; | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.getCallIdListForConference(1, (err: BusinessError, data: Array<string>) => {
    if (err) {
        console.error(`getCallIdListForConference fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`getCallIdListForConference success, data->${JSON.stringify(data)}`);
    }
});
```


## call.getCallIdListForConference<sup>7+</sup>

getCallIdListForConference\(callId: number\): Promise\<Array\<string\>\>

Obtains the list of call IDs in a conference. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type                         | Description                                   |
| ----------------------------- | --------------------------------------- |
| Promise&lt;Array<string\>&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.getCallIdListForConference(1).then((data: Array<string>) => {
    console.log(`getCallIdListForConference success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getCallIdListForConference fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.getCallWaitingStatus<sup>7+</sup>

getCallWaitingStatus\(slotId: number, callback: AsyncCallback\<CallWaitingStatus\>\): void

Obtains the call waiting status. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                                                      | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.                      |
| callback | AsyncCallback&lt;[CallWaitingStatus](#callwaitingstatus7)\> | Yes  | Callback used to return the result.<br>The value can be:<br>- **0**: Call waiting is disabled.<br>- **1**: Call waiting is enabled.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.getCallWaitingStatus(0, (err: BusinessError, data: call.CallWaitingStatus) => {
    if (err) {
        console.error(`getCallWaitingStatus fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`getCallWaitingStatus success, data->${JSON.stringify(data)}`);
    }
});
```


## call.getCallWaitingStatus<sup>7+</sup>

getCallWaitingStatus\(slotId: number\): Promise\<CallWaitingStatus\>

Obtains the call waiting status. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.|

**Return value**

| Type                                                   | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[CallWaitingStatus](#callwaitingstatus7)&gt; | Promise used to return the result.<br>- **0**: Call waiting is disabled.<br>- **1**: Call waiting is enabled.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.getCallWaitingStatus(0).then((data: call.CallWaitingStatus) => {
    console.log(`getCallWaitingStatus success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getCallWaitingStatus fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.setCallWaiting<sup>7+</sup>

setCallWaiting\(slotId: number, activate: boolean, callback: AsyncCallback\<void\>\): void

Specifies whether to enable the call waiting service. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number               | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.                      |
| activate | boolean              | Yes  | Whether to enable call waiting.<br>- **false**: Disable call waiting.<br>- **true**: Enable call waiting.|
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.                    |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.setCallWaiting(0, true, (err: BusinessError) => {
    if (err) {
        console.error(`setCallWaiting fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`setCallWaiting success.`);
    }
});
```


## call.setCallWaiting<sup>7+</sup>

setCallWaiting\(slotId: number, activate: boolean\): Promise\<void\>

Specifies whether to enable the call waiting service. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| slotId   | number  | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.                      |
| activate | boolean | Yes  | Whether to enable call waiting.<br>- **false**: Disable call waiting.<br>- **true**: Enable call waiting.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.setCallWaiting(0, true).then(() => {
    console.log(`setCallWaiting success.`);
}).catch((err: BusinessError) => {
    console.error(`setCallWaiting fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.startDTMF<sup>7+</sup>

startDTMF\(callId: number, character: string, callback: AsyncCallback\<void\>\): void

Starts playing DTMF tones. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name   | Type                | Mandatory| Description      |
| --------- | -------------------- | ---- | ---------- |
| callId    | number               | Yes  | Call ID.  |
| character | string               | Yes  | DTMF string.  |
| callback  | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.startDTMF(1, "0", (err: BusinessError) => {
    if (err) {
        console.error(`startDTMF fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`startDTMF success.`);
    }
});
```


## call.startDTMF<sup>7+</sup>

startDTMF\(callId: number, character: string\): Promise\<void\>

Starts playing DTMF tones. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name   | Type  | Mandatory| Description    |
| --------- | ------ | ---- | -------- |
| callId    | number | Yes  | Call ID.|
| character | string | Yes  | DTMF string.|

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.startDTMF(1, "0").then(() => {
    console.log(`startDTMF success.`);
}).catch((err: BusinessError) => {
    console.error(`startDTMF fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.stopDTMF<sup>7+</sup>

stopDTMF\(callId: number, callback: AsyncCallback\<void\>\): void

Stops playing DTMF tones. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | Yes  | Call ID.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.stopDTMF(1, (err: BusinessError) => {
    if (err) {
        console.error(`stopDTMF fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`stopDTMF success.`);
    }
});
```


## call.stopDTMF<sup>7+</sup>

stopDTMF\(callId: number\): Promise\<void\>

Stops playing DTMF tones. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.stopDTMF(1).then(() => {
    console.log(`stopDTMF success.`);
}).catch((err: BusinessError) => {
    console.error(`stopDTMF fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.postDialProceed<sup>11+</sup>

postDialProceed\(callId: number, proceed: boolean, callback: AsyncCallback\<void\>\): void

Continues a call by playing a post-dial DTMF string. This API uses an asynchronous callback to return the result.

If the called number is in the format of "common phone number + semicolon (;) + DTMF string", for example, **400xxxxxxx;123**, and the listening for **postDialDelay** events is enabled,
the system reports a **postDialDelay** event when the call is connected. The application can then call this API to send DTMF tones.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description                                                          |
| -------- | ------------------------- | ---- | -------------------------------------------------------------- |
| callId   | number                    | Yes  | Call ID.                                                      |
| proceed  | boolean                   | Yes  | Whether to send DTMF tones. The default value is **false**.<br>- **true**: Send DTMF tones.<br>- **false**: Do not send DTMF tones.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                   |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.postDialProceed(1, true, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## call.postDialProceed<sup>11+</sup>

postDialProceed\(callId: number, proceed: boolean\): Promise\<void\>

Continues a call by playing a post-dial DTMF string. This API uses a promise to return the result.

If the called number is in the format of "common phone number + semicolon (;) + DTMF string", for example, **400xxxxxxx;123**, and the listening for **postDialDelay** events is enabled,
the system reports a **postDialDelay** event when the call is connected. The application can then call this API to send DTMF tones.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description                   |
| -------- | ------------------------- | ---- | ----------------------- |
| callId   | number                    | Yes  | Call ID.               |
| proceed  | boolean                   | Yes  | Whether to send DTMF tones. The default value is **false**.<br>- **true**: Send DTMF tones.<br>- **false**: Do not send DTMF tones.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.postDialProceed(1, true).then(() => {
    console.log(`postDialProceed success.`);
}).catch((err: BusinessError) => {
    console.error(`postDialProceed fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.isInEmergencyCall<sup>7+</sup>

isInEmergencyCall\(callback: AsyncCallback\<boolean\>\): void

Checks whether a call is an emergency call. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                        | Mandatory| Description      |
| -------- | ---------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback function used to return the result. The value **true** indicates an emergency call, and the value **false** indicates a non-emergency call.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.isInEmergencyCall((err: BusinessError, data: boolean) => {
    if (err) {
        console.error(`isInEmergencyCall fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`isInEmergencyCall success, data->${JSON.stringify(data)}`);
    }
});
```


## call.isInEmergencyCall<sup>7+</sup>

isInEmergencyCall\(\): Promise\<boolean\>

Checks whether a call is an emergency call. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type                  | Description                       |
| ---------------------- | --------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates an emergency call, and the value false indicates a non-emergency call.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.isInEmergencyCall().then((data: boolean) => {
    console.log(`isInEmergencyCall success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isInEmergencyCall fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.on('callDetailsChange')<sup>7+</sup>

on\(type: 'callDetailsChange', callback: Callback\<CallAttributeOptions\>\): void

Subscribes to **callDetailsChange** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                   | Mandatory| Description                      |
| -------- | ------------------------------------------------------- | ---- | -------------------------- |
| type     | string                                                  | Yes  | Call event change. This field has a fixed value of **callDetailsChange**.|
| callback | Callback<[CallAttributeOptions](#callattributeoptions7)> | Yes | Callback used to return the result.    |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
call.on('callDetailsChange', (data: call.CallAttributeOptions) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('callEventChange')<sup>8+</sup>

on\(type: 'callEventChange', callback: Callback\<CallEventOptions\>\): void

Subscribes to **callEventChange** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                            | Mandatory| Description                      |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| type     | string                                           | Yes  | Call event change. This field has a fixed value of **callEventChange**.|
| callback | Callback<[CallEventOptions](#calleventoptions8)> | Yes  | Callback used to return the result.    |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
call.on('callEventChange', (data: call.CallEventOptions) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('callDisconnectedCause')<sup>8+</sup>

on\(type: 'callDisconnectedCause', callback: Callback\<DisconnectedDetails\>\): void

Subscribes to **callDisconnectedCause** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                  | Mandatory| Description                      |
| -------- | ------------------------------------------------------ | ---- | -------------------------- |
| type     | string                                                 | Yes  | Call disconnection cause. This field has a fixed value of **callDisconnectedCause**.|
| callback | Callback<[DisconnectedDetails](#disconnecteddetails9)> | Yes  | Callback used to return the result.   |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
call.on('callDisconnectedCause', (data: call.DisconnectedDetails) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('mmiCodeResult')<sup>9+</sup>

on\(type: 'mmiCodeResult', callback: Callback\<MmiCodeResults\>\): void

Subscribes to **mmiCodeResult** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                        | Mandatory| Description                 |
| -------- | -------------------------------------------- | ---- | --------------------- |
| type     | string                                       | Yes  | MMI code result. This field has a fixed value of **mmiCodeResult**.|
| callback | Callback<[MmiCodeResults](#mmicoderesults9)> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
call.on('mmiCodeResult', (data: call.MmiCodeResults) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('callDetailsChange')<sup>7+</sup>

off\(type: 'callDetailsChange', callback?: Callback\<CallAttributeOptions\>\): void

Unsubscribes from **callDetailsChange** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                    | Mandatory| Description                              |
| -------- | -------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                   | Yes  | Call details change. This field has a fixed value of **callDetailsChange**.|
| callback | Callback<[CallAttributeOptions](#callattributeoptions7)> | No  | Callback used to return the result. If this field is not set, no subscription cancellation result will be received.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
call.off('callDetailsChange', (data: call.CallAttributeOptions) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('callEventChange')<sup>8+</sup>

off\(type: 'callEventChange', callback?: Callback\<CallEventOptions\>\): void

Unsubscribes from **callEventChange** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                            | Mandatory| Description                              |
| -------- | ------------------------------------------------ | ---- | ---------------------------------- |
| type     | string                                           | Yes  | Call event change. This field has a fixed value of **callEventChange**.|
| callback | Callback<[CallEventOptions](#calleventoptions8)> | No  | Callback used to return the result. If this field is not set, no subscription cancellation result will be received.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
call.off('callEventChange', (data: call.CallEventOptions) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('callDisconnectedCause')<sup>8+</sup>

off\(type: 'callDisconnectedCause', callback?: Callback\<DisconnectedDetails\>\): void

Unsubscribes from **callDisconnectedCause** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                      | Mandatory| Description                |
| -------- | ---------------------------------------------------------- | ---- | ------------------- |
| type     | string                                                     | Yes  | Call disconnection cause. This field has a fixed value of **callDisconnectedCause**.|
| callback | Callback<[DisconnectedDetails](#disconnecteddetails9)>     | No  | Callback used to return the result. If this field is not set, no subscription cancellation result will be received.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
call.off('callDisconnectedCause', (data: call.DisconnectedDetails) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('mmiCodeResult')<sup>9+</sup>

off\(type: 'mmiCodeResult', callback?: Callback\<MmiCodeResults\>\): void

Unsubscribes from **mmiCodeResult** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                             | Mandatory| Description       |
| -------- | ------------------------------------------------ | ---- | ----------- |
| type     | string                                           | Yes  | MMI code result. This field has a fixed value of **mmiCodeResult**.|
| callback | Callback<[MmiCodeResults](#mmicoderesults9)>     | No  | Callback used to return the result. If this field is not set, no subscription cancellation result will be received.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
call.off('mmiCodeResult', (data: call.MmiCodeResults) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```


## call.on('audioDeviceChange')<sup>10+</sup>

on\(type: 'audioDeviceChange', callback: Callback\<AudioDeviceCallbackInfo\>\): void

Subscribes to audio device change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                            | Mandatory| Description                                               |
| -------- | ----------------------------------------------- | ---- | --------------------------------------------------- |
| type     | string                                          | Yes  | Audio device change. This field has a fixed value of **audioDeviceChange**.|
| callback | Callback<[AudioDeviceCallbackInfo](#audiodevicecallbackinfo10)> | Yes  | Callback used to return the result.            |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
call.on('audioDeviceChange', (data: call.AudioDeviceCallbackInfo) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```


## call.off('audioDeviceChange')<sup>10+</sup>

off\(type: 'audioDeviceChange', callback?: Callback\<AudioDeviceCallbackInfo\>\): void

Unsubscribes from **audioDeviceChange** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                      | Mandatory |                           Description                     |
| -------- | ---------------------------------------------------------- | ---- | --------------------------------------------------- |
| type     | string                                                     | Yes  | Audio device change. This field has a fixed value of **audioDeviceChange**.|
| callback | Callback<[AudioDeviceCallbackInfo](#audiodevicecallbackinfo10)>            | No  | Callback used to return the result. If this field is not set, no subscription cancellation result will be received.    |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
call.off('audioDeviceChange', (data: call.AudioDeviceCallbackInfo) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('postDialDelay')<sup>11+</sup>

on\(type: 'postDialDelay', callback: Callback\<string\>\): void

Subscribes to **postDialDelay** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                            | Mandatory| Description                                               |
| -------- | ----------------------------------------------- | ---- | --------------------------------------------------- |
| type     | string                                          | Yes  | Post-dial delay. This field has a fixed value of **postDialDelay**.              |
| callback | Callback&lt;string&gt;                          | Yes  |Callback used to return the result.        |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
call.on('postDialDelay', (data: string) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('postDialDelay')<sup>11+</sup>

off\(type: 'postDialDelay', callback?: Callback\<string\>\): void

Unsubscribes from **postDialDelay** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                      | Mandatory |                           Description                     |
| -------- | ---------------------------------------------------------- | ---- | --------------------------------------------------- |
| type     | string                                                     | Yes  | Post-dial delay. This field has a fixed value of **postDialDelay**.             |
| callback | Callback&lt;string&gt;                                     | No  | Callback used to return the result. If this field is not set, no subscription cancellation result will be received.   |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
call.off('postDialDelay', (data: string) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.isNewCallAllowed<sup>8+</sup>

isNewCallAllowed\(callback: AsyncCallback\<boolean\>\): void

Checks whether a new call is allowed. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                        | Mandatory| Description      |
| -------- | ---------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback function used to return the result. The value **true** indicates that the call is allowed, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.isNewCallAllowed((err: BusinessError, data: boolean) => {
    if (err) {
        console.error(`isNewCallAllowed fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`isNewCallAllowed success, data->${JSON.stringify(data)}`);
    }
});
```


## call.isNewCallAllowed<sup>8+</sup>

isNewCallAllowed\(\): Promise\<boolean\>

Checks whether a new call is allowed. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type                  | Description                       |
| ---------------------- | --------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that the call is allowed, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.isNewCallAllowed().then((data: boolean) => {
    console.log(`isNewCallAllowed success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isNewCallAllowed fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.separateConference<sup>11+</sup>

separateConference\(callId: number, callback: AsyncCallback\<void\>\): void

Separates calls from a conference call. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | Yes  | Call ID.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300008  | Conference call is not active. |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.separateConference(1, (err: BusinessError) => {
    if (err) {
        console.error(`separateConference fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`separateConference success.`);
    }
});
```


## call.separateConference<sup>11+</sup>

separateConference\(callId: number\): Promise\<void\>

Separates calls from a conference call. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| callId | number | Yes  | Call ID.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300008  | Conference call is not active. |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.separateConference(1).then(() => {
    console.log(`separateConference success.`);
}).catch((err: BusinessError) => {
    console.error(`separateConference fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.getCallRestrictionStatus<sup>8+</sup>

getCallRestrictionStatus\(slotId: number, type: CallRestrictionType, callback: AsyncCallback\<RestrictionStatus\>\): void

Obtains the call restriction status. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.|
| type     | [CallRestrictionType](#callrestrictiontype8)                 | Yes  | Call restriction type.                       |
| callback | AsyncCallback&lt;[RestrictionStatus](#restrictionstatus8)&gt; | Yes  | Callback used to return the result.                |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.getCallRestrictionStatus(0, 1, (err: BusinessError, data: call.RestrictionStatus) => {
    if (err) {
        console.error(`getCallRestrictionStatus fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`getCallRestrictionStatus success, data->${JSON.stringify(data)}`);
    }
});
```


## call.getCallRestrictionStatus<sup>8+</sup>

getCallRestrictionStatus\(slotId: number, type: CallRestrictionType\): Promise\<RestrictionStatus\>

Obtains the call restriction status. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type                                        | Mandatory| Description                                  |
| ------ | -------------------------------------------- | ---- | -------------------------------------- |
| slotId | number                                       | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.|
| type   | [CallRestrictionType](#callrestrictiontype8) | Yes  | Call restriction type.                       |

**Return value**

| Type                                                   | Description                       |
| ------------------------------------------------------- | --------------------------- |
| Promise&lt;[RestrictionStatus](#restrictionstatus8)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.getCallRestrictionStatus(0, 1).then((data: call.RestrictionStatus) => {
    console.log(`getCallRestrictionStatus success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getCallRestrictionStatus fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.setCallRestriction<sup>8+</sup>

setCallRestriction\(slotId: number, info: CallRestrictionInfo, callback: AsyncCallback\<void\>\): void

Sets the call restriction status. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                       | Mandatory| Description                                  |
| -------- | ------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                      | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.|
| info     | [CallRestrictionInfo](#callrestrictioninfo8) | Yes  | Call restriction information.                        |
| callback | AsyncCallback&lt;void&gt;                   | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let callRestrictionInfo: call.CallRestrictionInfo = {
    type: call.CallRestrictionType.RESTRICTION_TYPE_ALL_OUTGOING,
    password: "123456",
    mode: call.CallRestrictionMode.RESTRICTION_MODE_ACTIVATION
}
call.setCallRestriction(0, callRestrictionInfo, (err: BusinessError) => {
    if (err) {
        console.error(`setCallRestriction fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`setCallRestriction success.`);
    }
});
```


## call.setCallRestriction<sup>8+</sup>

setCallRestriction\(slotId: number, info: CallRestrictionInfo\): Promise\<void\>

Sets the call restriction status. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type                                        | Mandatory| Description                                  |
| ------ | -------------------------------------------- | ---- | -------------------------------------- |
| slotId | number                                       | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.|
| info   | [CallRestrictionInfo](#callrestrictioninfo8) | Yes  | Call restriction information.                        |

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let callRestrictionInfo: call.CallRestrictionInfo = {
    type: call.CallRestrictionType.RESTRICTION_TYPE_ALL_INCOMING,
    password: "123456",
    mode: call.CallRestrictionMode.RESTRICTION_MODE_ACTIVATION
}
call.setCallRestriction(0, callRestrictionInfo).then(() => {
    console.log(`setCallRestriction success.`);
}).catch((err: BusinessError) => {
    console.error(`setCallRestriction fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.setCallRestrictionPassword<sup>10+</sup>

setCallRestrictionPassword\(slotId: number, oldPassword: string, newPassword: string, callback: AsyncCallback\<void\>\): void

Changes the call barring password. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name         | Type                                       | Mandatory| Description                                  |
| --------------- | ------------------------------------------- | ---- | ------------------------------------ |
| slotId          | number                                      | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.|
| oldPassword     | string                                      | Yes  | Old password for call barring.                      |
| newPassword     | string                                      | Yes  | New password for call barring.                      |
| callback        | AsyncCallback&lt;void&gt;                   | Yes  | Callback used to return the result.   |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.setCallRestrictionPassword(0, "123456", "654321", (err: BusinessError) => {
    if (err) {
        console.error(`setCallRestrictionPassword fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`setCallRestrictionPassword success.`);
    }
});
```

## call.setCallRestrictionPassword<sup>10+</sup>

setCallRestrictionPassword\(slotId: number, oldPassword: string, newPassword: string\): Promise\<void\>

Changes the call barring password. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name         | Type                                       | Mandatory| Description                                  |
| --------------- | ------------------------------------------- | ---- | ------------------------------------ |
| slotId          | number                                      | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.|
| oldPassword     | string                                      | Yes  | Old password for call barring.                      |
| newPassword     | string                                      | Yes  | New password for call barring.                      |

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.setCallRestrictionPassword(0, "123456", "654321").then(() => {
    console.log(`setCallRestrictionPassword success.`);
}).catch((err: BusinessError) => {
    console.error(`setCallRestrictionPassword fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.getCallTransferInfo<sup>8+</sup>

getCallTransferInfo\(slotId: number, type: CallTransferType, callback: AsyncCallback\<CallTransferResult\>\): void

Obtains call transfer information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.|
| type     | [CallTransferType](#calltransfertype8)                       | Yes  | Call transfer type.                        |
| callback | AsyncCallback&lt;[CallTransferResult](#calltransferresult8)&gt; | Yes  | Callback used to return the result.            |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.getCallTransferInfo(0, call.CallTransferType.TRANSFER_TYPE_BUSY, (err: BusinessError, data: call.CallTransferResult) => {
    if (err) {
        console.error(`getCallTransferInfo fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`getCallTransferInfo success, data->${JSON.stringify(data)}`);
    }
});
```


## call.getCallTransferInfo<sup>8+</sup>

getCallTransferInfo\(slotId: number, type: CallTransferType\): Promise\<CallTransferResult\>

Obtains call transfer information. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type                                  | Mandatory| Description                                  |
| ------ | -------------------------------------- | ---- | -------------------------------------- |
| slotId | number                                 | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.|
| type   | [CallTransferType](#calltransfertype8) | Yes  | Call transfer type.                        |

**Return value**

| Type                                                     | Description                       |
| --------------------------------------------------------- | --------------------------- |
| Promise&lt;[CallTransferResult](#calltransferresult8)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.getCallTransferInfo(0, call.CallTransferType.TRANSFER_TYPE_BUSY).then((data: call.CallTransferResult) => {
    console.log(`getCallTransferInfo success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getCallTransferInfo fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.setCallTransfer<sup>8+</sup>

setCallTransfer\(slotId: number, info: CallTransferInfo, callback: AsyncCallback\<void\>\): void

Sets call transfer information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                 | Mandatory| Description                                  |
| -------- | ------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.|
| info     | [CallTransferInfo](#calltransferinfo8) | Yes  | Call transfer information.                       |
| callback | AsyncCallback&lt;void&gt;             | Yes  | Callback used to return the result.     |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let callTransferInfo: call.CallTransferInfo = {
    transferNum: "111",
    type: call.CallTransferType.TRANSFER_TYPE_BUSY,
    settingType: call.CallTransferSettingType.CALL_TRANSFER_ENABLE
}
call.setCallTransfer(0, callTransferInfo, (err: BusinessError) => {
    if (err) {
        console.error(`setCallTransfer fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`setCallTransfer success.`);
    }
});
```


## call.setCallTransfer<sup>8+</sup>

setCallTransfer\(slotId: number, info: CallTransferInfo\): Promise\<void\>

Sets call transfer information. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type                                 | Mandatory| Description                                  |
| ------ | ------------------------------------- | ---- | -------------------------------------- |
| slotId | number                                | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.|
| info   | [CallTransferInfo](#calltransferinfo8) | Yes  | Call transfer information.                       |

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let callTransferInfo: call.CallTransferInfo = {
    transferNum: "111",
    type: call.CallTransferType.TRANSFER_TYPE_BUSY,
    settingType: call.CallTransferSettingType.CALL_TRANSFER_ENABLE
}
call.setCallTransfer(0, callTransferInfo).then(() => {
    console.log(`setCallTransfer success.`);
}).catch((err: BusinessError) => {
    console.error(`setCallTransfer fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.isRinging<sup>8+</sup>

isRinging\(callback: AsyncCallback\<boolean\>\): void

Checks whether the ringtone is playing. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                        | Mandatory| Description      |
| -------- | ---------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value true indicates that the **ringtone** is playing, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.isRinging((err: BusinessError, data: boolean) => {
    if (err) {
        console.error(`isRinging fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`isRinging success, data->${JSON.stringify(data)}`);
    }
});
```


## call.isRinging<sup>8+</sup>

isRinging\(\): Promise\<boolean\>

Checks whether the ringtone is playing. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type                  | Description                       |
| ---------------------- | --------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value true indicates that the **ringtone** is playing, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.isRinging().then((data: boolean) => {
    console.log(`isRinging success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isRinging fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.setMuted<sup>8+</sup>

setMuted\(callback: AsyncCallback\<void\>\): void

Sets call muting. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.setMuted((err: BusinessError) => {
    if (err) {
        console.error(`setMuted fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`setMuted success.`);
    }
});
```


## call.setMuted<sup>8+</sup>

setMuted\(\): Promise\<void\>

Sets call muting. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.setMuted().then(() => {
    console.log(`setMuted success.`);
}).catch((err: BusinessError) => {
    console.error(`setMuted fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.cancelMuted<sup>8+</sup>

cancelMuted\(callback: AsyncCallback\<void\>\): void

Cancels call muting. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.cancelMuted((err: BusinessError) => {
    if (err) {
        console.error(`cancelMuted fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`cancelMuted success.`);
    }
});
```


## call.cancelMuted<sup>8+</sup>

cancelMuted\(\): Promise\<void\>

Cancels call muting. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.cancelMuted().then(() => {
    console.log(`cancelMuted success.`);
}).catch((err: BusinessError) => {
    console.error(`cancelMuted fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.setAudioDevice<sup>8+</sup>

setAudioDevice\(device: AudioDevice, callback: AsyncCallback\<void\>\): void

Sets the audio device for a call. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                        | Mandatory| Description      |
| -------- | ---------------------------- | ---- | ---------- |
| device   | [AudioDevice](#audiodevice10)| Yes  | Audio device.|
| callback | AsyncCallback&lt;void&gt;    | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let audioDevice: call.AudioDevice = {
    deviceType: call.AudioDeviceType.DEVICE_EARPIECE
}
call.setAudioDevice(audioDevice, (err: BusinessError) => {
    if (err) {
        console.error(`setAudioDevice fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`setAudioDevice success.`);
    }
});
```

## call.setAudioDevice<sup>10+</sup>

setAudioDevice\(device: AudioDevice): Promise\<void\>

Sets the audio device for a call. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                        | Mandatory| Description      |
| -------- | ---------------------------- | ---- | ---------- |
| device   | [AudioDevice](#audiodevice10)| Yes  | Audio device.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let audioDevice: call.AudioDevice = {
    deviceType: call.AudioDeviceType.DEVICE_EARPIECE
}
call.setAudioDevice(audioDevice).then(() => {
    console.log(`setAudioDevice success.`);
}).catch((err: BusinessError) => {
    console.error(`setAudioDevice fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.joinConference<sup>8+</sup>

joinConference\(mainCallId: number, callNumberList: Array\<string\>, callback: AsyncCallback\<void\>\): void

Joins a conference call. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name        | Type                     | Mandatory| Description           |
| -------------- | ------------------------- | ---- | --------------- |
| mainCallId     | number                    | Yes  | Main call ID.     |
| callNumberList | Array<string\>            | Yes  | List of call numbers.|
| callback       | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.     |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let callNumberList: Array<string> = [
    "138XXXXXXXX"
];
call.joinConference(1, callNumberList, (err: BusinessError) => {
    if (err) {
        console.error(`joinConference fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`joinConference success.`);
    }
});
```

## call.joinConference<sup>8+</sup>

joinConference\(mainCallId: number, callNumberList: Array\<string\>\): Promise\<void\>

Joins a conference call. This API uses a promise to return the result.

**System API**: This is a system API.

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

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let callNumberList: Array<string> = [
    "138XXXXXXXX"
];
call.joinConference(1, callNumberList).then(() => {
    console.log(`joinConference success.`);
}).catch((err: BusinessError) => {
    console.error(`joinConference fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.updateImsCallMode<sup>8+</sup>

updateImsCallMode\(callId: number, mode: ImsCallMode, callback: AsyncCallback\<void\>\): void

Updates the IMS call mode. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                        | Mandatory| Description          |
| -------- | ---------------------------- | ---- | -------------- |
| callId   | number                       | Yes  | Call ID.      |
| mode     | [ImsCallMode](#imscallmode8) | Yes  | IMS call mode.|
| callback | AsyncCallback&lt;void&gt;    | Yes  | Callback used to return the result.    |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.updateImsCallMode(1, 1, (err: BusinessError) => {
    if (err) {
        console.error(`updateImsCallMode fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`updateImsCallMode success.`);
    }
});
```

## call.updateImsCallMode<sup>8+</sup>

updateImsCallMode\(callId: number, mode: ImsCallMode\): Promise\<void\>

Updates the IMS call mode. This API uses a promise to return the result.

**System API**: This is a system API.

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

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.updateImsCallMode(1, 1).then(() => {
    console.log(`updateImsCallMode success.`);
}).catch((err: BusinessError) => {
    console.error(`updateImsCallMode fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.enableImsSwitch<sup>8+</sup>

enableImsSwitch\(slotId: number, callback: AsyncCallback\<void\>\): void

Enables the IMS service. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description                                  |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.         |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.enableImsSwitch(0, (err: BusinessError) => {
    if (err) {
        console.error(`enableImsSwitch fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`enableImsSwitch success.`);
    }
});
```

## call.enableImsSwitch<sup>8+</sup>

enableImsSwitch\(slotId: number\): Promise\<void\>

Enables the IMS service. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.enableImsSwitch(0).then(() => {
    console.log(`enableImsSwitch success.`);
}).catch((err: BusinessError) => {
    console.error(`enableImsSwitch fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.disableImsSwitch<sup>8+</sup>

disableImsSwitch\(slotId: number, callback: AsyncCallback\<void\>\): void

Disables the IMS service. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description                                  |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.              |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.disableImsSwitch(0, (err: BusinessError) => {
    if (err) {
        console.error(`disableImsSwitch fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`disableImsSwitch success.`);
    }
});
```

## call.disableImsSwitch<sup>8+</sup>

disableImsSwitch\(slotId: number\): Promise\<void\>

Disables the IMS service. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2. |

**Return value**

| Type               | Description                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result. |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.disableImsSwitch(0).then(() => {
    console.log(`disableImsSwitch success.`);
}).catch((err: BusinessError) => {
    console.error(`disableImsSwitch fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.isImsSwitchEnabled<sup>8+</sup>

isImsSwitchEnabled\(slotId: number, callback: AsyncCallback\<boolean\>\): void

Checks whether the IMS service is enabled. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                        | Mandatory| Description                                  |
| -------- | ---------------------------- | ---- | -------------------------------------- |
| slotId   | number                       | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.|
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** indicates that the IMS service is enabled, and the value **false** indicates the opposite. The value **true** indicates that the IMS service is enabled, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.isImsSwitchEnabled(0, (err: BusinessError, data: boolean) => {
    if (err) {
        console.error(`isImsSwitchEnabled fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`isImsSwitchEnabled success, data->${JSON.stringify(data)}`);
    }
});
```

## call.isImsSwitchEnabled<sup>8+</sup>

isImsSwitchEnabled\(slotId: number\): Promise\<boolean\>

Checks whether the IMS service is enabled. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that the IMS service is enabled, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.isImsSwitchEnabled(0).then((data: boolean) => {
    console.log(`isImsSwitchEnabled success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isImsSwitchEnabled fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.isImsSwitchEnabledSync<sup>12+</sup>

isImsSwitchEnabledSync\(slotId: number\): boolean

Checks whether the IMS service is enabled. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.|

**Return value**

| Type   | Description                                                |
| ------- | ---------------------------------------------------- |
| boolean | Boolean value indicating whether the IMS service is enabled. The value **true** indicates that the IMS service is enabled, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Non-system applications use system APIs.                     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types; |
| 8300001  | Invalid parameter value.                                     |
| 8300002  | Operation failed. Cannot connect to service.                 |
| 8300003  | System internal error.                                       |
| 8300999  | Unknown error code.                                          |

**Example**

<!--code_no_check-->

```ts
let slotId: number = 0;
try {
    let isEnabled: boolean = call.isImsSwitchEnabledSync(slotId);
    console.log(`isImsSwitchEnabledSync success : ${isEnabled}`);
} catch (error) {
    console.error(`isImsSwitchEnabledSync fail : err->${JSON.stringify(error)}`);  
}
```

## call.closeUnfinishedUssd<sup>10+</sup>

closeUnfinishedUssd\(slotId: number, callback: AsyncCallback\<void\>\): void

Cancels the unfinished USSD services. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                     | Mandatory| Description                                   |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2. |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                             |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
call.closeUnfinishedUssd(slotId, (err: BusinessError) => {
    if (err) {
        console.error(`closeUnfinishedUssd fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`closeUnfinishedUssd success.`);
    }
});
```

## call.closeUnfinishedUssd<sup>10+</sup>

closeUnfinishedUssd\(slotId: number\): Promise\<void\>

Cancels the unfinished USSD services. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type  | Mandatory| Description                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2. |

**Return value**

| Type               | Description                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result. |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
call.closeUnfinishedUssd(slotId).then(() => {
    console.log(`closeUnfinishedUssd success.`);
}).catch((err: BusinessError) => {
    console.error(`closeUnfinishedUssd fail, promise: err->${JSON.stringify(err)}`);
});
```


## call.setVoNRState<sup>10+</sup>

setVoNRState\(slotId: number, state: VoNRState, callback: AsyncCallback\<void\>\): void

Sets the status of the VoNR switch. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                          | Mandatory| Description                                                |
| ----------- | ----------------------------- | ---- | ---------------------------------------------------- |
| slotId      | number                        | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.               |
| state       | [VoNRState](#vonrstate10)     | Yes  | Status of the VoNR switch.                                           |
| callback    | AsyncCallback&lt;void&gt;  | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let state: call.VoNRState = call.VoNRState.VONR_STATE_ON;
call.setVoNRState(slotId, state, (err: BusinessError) => {
    if (err) {
        console.error(`setVoNRState fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`setVoNRState success`);
    }
});
```


## call.setVoNRState<sup>10+</sup>

setVoNRState\(slotId: number, state: VoNRState\): Promise\<void\>

Sets the status of the VoNR switch. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                          | Mandatory| Description                                       |
| ----------- | ----------------------------- | ---- | ------------------------------------------- |
| slotId      | number                        | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.    |
| state       | [VoNRState](#vonrstate10)     | Yes  | Status of the VoNR switch.                                  |

**Return value**

| Type                  | Description                                         |
| ---------------------- | --------------------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.    |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let state: call.VoNRState = call.VoNRState.VONR_STATE_ON;
call.setVoNRState(slotId, state).then(() => {
    console.log(`setVoNRState success`);
}).catch((err: BusinessError) => {
    console.error(`setVoNRState fail, promise: err->${JSON.stringify(err)}`);
});
```


## call.getVoNRState<sup>10+</sup>

getVoNRState\(slotId: number, callback: AsyncCallback\<VoNRState\>\): void

Obtains the status of the VoNR switch. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     |                     Type                     | Mandatory | Description                                                  |
| ----------- | --------------------------------------------- | ---- | ------------------------------------------------------ |
| slotId      | number                                        | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.                 |
| callback    | AsyncCallback&lt;[VoNRState](#vonrstate10)&gt;| Yes  | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
call.getVoNRState(slotId, (err: BusinessError, data: call.VoNRState) => {
    if (err) {
        console.error(`getVoNRState fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`getVoNRState success, data->${JSON.stringify(data)}`);
    }
});
```


## call.getVoNRState<sup>10+</sup>

getVoNRState\(slotId: number\): Promise\<VoNRState\>

Obtains the status of the VoNR switch. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                          | Mandatory| Description                                       |
| ----------- | ----------------------------- | ---- | ------------------------------------------- |
| slotId      | number                        | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.    |

**Return value**

|                 Type                    | Description                                       |
| ---------------------------------------- | ------------------------------------------- |
| Promise&lt;[VoNRState](#vonrstate10)&gt; | Promise used to return the result.             |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
call.getVoNRState(slotId).then((data: call.VoNRState) => {
    console.log(`getVoNRState success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getVoNRState fail, promise: err->${JSON.stringify(err)}`);
});
```


## call.canSetCallTransferTime<sup>10+</sup>

canSetCallTransferTime\(slotId: number, callback: AsyncCallback\<boolean\>\): void

Checks whether the call forwarding time can be set. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                          | Mandatory| Description                                                 |
| ----------- | ----------------------------- | ---- | ----------------------------------------------------- |
| slotId      | number                        | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.                |
| callback    | AsyncCallback&lt;boolean&gt;  | Yes  | Callback used to return the result. The value **true** indicates that the call forwarding time can be set, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
call.canSetCallTransferTime(slotId, (err: BusinessError, data: boolean) => {
    if (err) {
        console.error(`canSetCallTransferTime fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`canSetCallTransferTime success, data->${JSON.stringify(data)}`);
    }
});
```


## call.canSetCallTransferTime<sup>10+</sup>

canSetCallTransferTime\(slotId: number\): Promise\<boolean\>

Checks whether the call forwarding time can be set. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                          | Mandatory| Description                                       |
| ----------- | ----------------------------- | ---- | ------------------------------------------- |
| slotId      | number                        | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.    |

**Return value**

| Type                  | Description                                         |
| ---------------------- | --------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that the call forwarding time can be set, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
call.canSetCallTransferTime(slotId).then((data: boolean) => {
    console.log(`canSetCallTransferTime success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`canSetCallTransferTime fail, promise: err->${JSON.stringify(err)}`);
});
```


## call.inputDialerSpecialCode<sup>10+</sup>

inputDialerSpecialCode\(inputCode: string, callback: AsyncCallback\<void\>\): void

Performs a secret code broadcast. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required Permissions**: ohos.permission.PLACE_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                        | Mandatory| Description                                      |
| ----------- | ---------------------------- | ---- | ----------------------------------------- |
| inputCode   | string                       | Yes  | Secret code, for example, *#*#2846579#*#* (project menu).|
| callback    | AsyncCallback&lt;void&gt;    | Yes  | Callback used to return the result.             |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.inputDialerSpecialCode('*#*#2846579#*#*', (err: BusinessError) => {
    if (err) {
        console.error(`inputDialerSpecialCode fail, err->${JSON.stringify(err)}`);
    } else {
        console.log(`inputDialerSpecialCode success`);
    }
});
```

## call.inputDialerSpecialCode<sup>10+</sup>

inputDialerSpecialCode\(inputCode: string\): Promise\<void\>

Performs a secret code broadcast. This API uses a promise to return the result.

**System API**: This is a system API.

**Required Permissions**: ohos.permission.PLACE_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                        | Mandatory| Description                                      |
| ----------- | ---------------------------- | ---- | ----------------------------------------- |
| inputCode   | string                       | Yes  | Secret code, for example, *#*#2846579#*#* (project menu).|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    call.inputDialerSpecialCode('*#*#2846579#*#*');
    console.log(`inputDialerSpecialCode success`);
} catch (error) {
    console.error(`inputDialerSpecialCode fail, promise: err->${JSON.stringify(error)}`);
}
```


## call.removeMissedIncomingCallNotification<sup>10+</sup>

removeMissedIncomingCallNotification\(callback: AsyncCallback\<void\>\): void

Removes missed call notifications. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_TELEPHONY_STATE, ohos.permission.READ_CALL_LOG, and ohos.permission.WRITE_CALL_LOG

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name     | Type                        | Mandatory| Description                                     |
| ----------- | ---------------------------- | ---- | ---------------------------------------   |
| callback    | AsyncCallback&lt;void&gt;    | Yes  | Callback used to return the result. |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.removeMissedIncomingCallNotification((err: BusinessError) => {
    if (err) {
        console.error(`removeMissedIncomingCallNotification failed, err->${JSON.stringify(err)}`);
    } else {
        console.log(`removeMissedIncomingCallNotification success`);
    }
});
```


## call.removeMissedIncomingCallNotification<sup>10+</sup>

removeMissedIncomingCallNotification\(\): Promise\<void\>

Removes missed call notifications. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_TELEPHONY_STATE, ohos.permission.READ_CALL_LOG, and ohos.permission.WRITE_CALL_LOG

**System capability**: SystemCapability.Telephony.CallManager

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.removeMissedIncomingCallNotification().then(() => {
    console.log(`removeMissedIncomingCallNotification success`);
}).catch((err: BusinessError) => {
    console.error(`removeMissedIncomingCallNotification failed, promise: err->${JSON.stringify(err)}`);
});
```

## call.sendCallUiEvent<sup>12+</sup>

sendCallUiEvent\(callId: number, eventName: string\): Promise\<void\>

Sends a call UI event. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name   | Type  | Mandatory| Description    |
| --------- | ------ | ---- | -------- |
| callId    | number | Yes  | Call ID.|
| eventName | string | Yes  | Event name.|

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let callId: number = 0;
call.sendCallUiEvent(callId, 'eventName').then(() => {
    console.log(`sendCallUiEvent success.`);
}).catch((err: BusinessError) => {
    console.error(`sendCallUiEvent fail, promise: err->${JSON.stringify(err)}`);
});
```

## DialOptions

Provides an option for determining whether a call is a video call.

**System capability**: SystemCapability.Telephony.CallManager

|        Name             | Type                              | Mandatory| Description                                                                                            |
| ------------------------ | ---------------------------------- | ---- | ----------------------------------------------------------------------------------------------- |
| accountId <sup>8+</sup>  | number                             | No  | Account ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.<br> This is a system API.                                  |
| videoState <sup>8+</sup> | [VideoStateType](#videostatetype7) | No  | Video state type. This is a system API.                                                                 |
| dialScene <sup>8+</sup>  | [DialScene](#dialscene8)           | No  | Dialup scenario. This is a system API.                                                                     |
| dialType <sup>8+</sup>   | [DialType](#dialtype8)             | No  | Dialup type. This is a system API.                                                                     |

## DialCallOptions<sup>9+</sup>

Provides an option for determining whether a call is a video call.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

|        Name             | Type                              | Mandatory| Description                                        |
| ------------------------ | ---------------------------------- | ---- | ------------------------------------------- |
| accountId <sup>9+</sup>  | number                             | No  | Account ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.   |
| videoState <sup>9+</sup> | [VideoStateType](#videostatetype7) | No  | Video state type.                              |
| dialScene <sup>9+</sup>  | [DialScene](#dialscene8)           | No  | Dialup scenario.                                  |
| dialType <sup>9+</sup>   | [DialType](#dialtype8)             | No  | Dialup type.                                  |


## ImsCallMode<sup>8+</sup>

Enumerates IMS call modes.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                  | Value  | Description              |
| ---------------------- | ---- | ------------------ |
| CALL_MODE_AUDIO_ONLY   | 0    | Audio call only.      |
| CALL_MODE_SEND_ONLY    | 1    | Sending calls only.        |
| CALL_MODE_RECEIVE_ONLY | 2    | Receiving calls only.        |
| CALL_MODE_SEND_RECEIVE | 3    | Sending and receiving calls.|
| CALL_MODE_VIDEO_PAUSED | 4    | Pausing video calls.      |

## VoNRState<sup>10+</sup>

Enumerates VoNR switch states.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                  | Value  | Description              |
| ---------------------- | ---- | ----------------- |
| VONR_STATE_OFF         | 0    | Disabled.          |
| VONR_STATE_ON          | 1    | Enabled.          |

## AudioDevice<sup>10+</sup>

Enumerates audio devices.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

|                Name              |                  Type                | Mandatory |        Description     |
| --------------------------------- | ------------------------------------- | ---- | ---------------- |
| deviceType <sup>10+</sup>         | [AudioDeviceType](#audiodevicetype10) | Yes  | Audio device type.   |
| address <sup>10+</sup>            | string                                | No  | Audio device address.   |
| deviceName <sup>11+</sup>         | string                                | No  | Audio device name.   |

## AudioDeviceType<sup>10+</sup>

Enumerates audio device types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                | Value  | Description        |
| -------------------- | ---- | ----------- |
| DEVICE_EARPIECE      | 0    | Headset device.    |
| DEVICE_SPEAKER       | 1    | Speaker device.  |
| DEVICE_WIRED_HEADSET | 2    | Wired headset device.|
| DEVICE_BLUETOOTH_SCO | 3    | Bluetooth SCO device. |
| DEVICE_DISTRIBUTED_AUTOMOTIVE<sup>11+</sup> | 4    | Distributed head unit.|

## AudioDeviceCallbackInfo<sup>10+</sup>

Defines the audio device information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

|                Name              |                  Type                | Mandatory |        Description     |
| --------------------------------- | ------------------------------------- | ---- | ---------------- |
| audioDeviceList <sup>10+</sup>    | [Array\<AudioDevice\>](#audiodevice10) | Yes  | Audio device list.   |
| currentAudioDevice <sup>10+</sup> | [AudioDevice](#audiodevice10)          | Yes  | Current audio device.   |
| isMuted <sup>10+</sup>            | boolean                               | Yes  | Whether the audio device is muted.       |


## CallRestrictionType<sup>8+</sup>

Enumerates call restriction types.

**System API**: This is a system API.

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

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

|          Name           | Type                                                | Mandatory| Description            |
| ------------------------ | ---------------------------------------------------- | ---- | ---------------- |
| transferNum              | string                                               | Yes  | Call transfer number.        |
| type                     | [CallTransferType](#calltransfertype8)               | Yes  | Call transfer type.    |
| settingType              | [CallTransferSettingType](#calltransfersettingtype8) | Yes  | Enumerates call transfer setting types.|
| startHour<sup>9+</sup>   | number                                               | No  | Hour in the start time.|
| startMinute<sup>9+</sup> | number                                               | No  | Minute in the start time.|
| endHour<sup>9+</sup>     | number                                               | No  | Hour in the end time.|
| endMinute<sup>9+</sup>   | number                                               | No  | Minute in the end time.|

## CallTransferType<sup>8+</sup>

Enumerates call transfer types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                       | Value  | Description        |
| --------------------------- | ---- | ------------ |
| TRANSFER_TYPE_UNCONDITIONAL | 0    | Call forwarding unconditional.  |
| TRANSFER_TYPE_BUSY          | 1    | Call forwarding busy.    |
| TRANSFER_TYPE_NO_REPLY      | 2    | Call forwarding on no reply.  |
| TRANSFER_TYPE_NOT_REACHABLE | 3    | Call forwarding on no user not reachable.|

## CallTransferSettingType<sup>8+</sup>

Enumerates call transfer setting types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                      | Value  | Description        |
| -------------------------- | ---- | ------------ |
| CALL_TRANSFER_DISABLE      | 0    | Disabling of call transfer.|
| CALL_TRANSFER_ENABLE       | 1    | Enabling of call transfer.|
| CALL_TRANSFER_REGISTRATION | 3    | Registration of call transfer.|
| CALL_TRANSFER_ERASURE      | 4    | Erasing of call transfer.|

## CallAttributeOptions<sup>7+</sup>

Defines the call attribute options.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

|      Name      | Type                                    | Mandatory| Description          |
| --------------- | ---------------------------------------- | ---- | -------------- |
| accountNumber   | string                                   | Yes  | Account number.      |
| speakerphoneOn  | boolean                                  | Yes  | Speakerphone on.|
| accountId       | number                                   | Yes  | Account ID.        |
| videoState      | [VideoStateType](#videostatetype7)       | Yes  | Video state type.  |
| startTime       | number                                   | Yes  | Start time.      |
| isEcc           | boolean                                  | Yes  | Whether the call is an ECC.     |
| callType        | [CallType](#calltype7)                   | Yes  | Enumerates call types.      |
| callId          | number                                   | Yes  | Call ID.        |
| callState       | [DetailedCallState](#detailedcallstate7) | Yes  | Detailed call state.  |
| conferenceState | [ConferenceState](#conferencestate7)     | Yes  | Enumerates conference states.      |
| voipCallAttribute<sup>11+</sup> | [VoipCallAttribute](#voipcallattribute11)     | No  | Defines the VoIP call information.      |
| crsType<sup>11+</sup> | number                             | Yes  | Video RBT type.|
| originalCallType<sup>11+</sup> | number                    | Yes  | Original call type of the Video RBT service.|
| numberLocation<sup>12+</sup> | string | No| Home location area of the number.|
| numberMarkInfo<sup>12+</sup> | [NumberMarkInfo](#numbermarkinfo12) | No| Number mark.|

## VoipCallAttribute<sup>11+</sup>

Defines the VoIP call information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

|      Name      | Type              | Mandatory| Description          |
| --------------- | ------------------- | ---- | -------------- |
| voipCallId   | string    | Yes  | Unique ID of a VoIP call.      |
| userName  | string    | Yes  | User nickname.|
| userProfile       | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)    | Yes  | User profile picture. |
| extensionId      | string     | Yes  |  Process ID of the third-party application. |
| abilityName      | string     | Yes  |  Ability name of the third-party application. |
| voipBundleName    | string     | Yes  |  Bundle name of the third-party application. |
| showBannerForIncomingCall<sup>12+</sup>    | boolean     | No  |  Whether to display the incoming call banner. |
| isConferenceCall<sup>12+</sup>    | boolean     | No  |  Whether the call is a conference call. |
| isVoiceAnswerSupported<sup>12+</sup>    | boolean     | No  |  Whether call answering with voice commands is supported. |

## ConferenceState<sup>7+</sup>

Enumerates conference states.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                        | Value  | Description          |
| ---------------------------- | ---- | -------------- |
| TEL_CONFERENCE_IDLE          | 0    | Idle state.  |
| TEL_CONFERENCE_ACTIVE        | 1    | Active state.  |
| TEL_CONFERENCE_DISCONNECTING | 2    | Disconnecting state.  |
| TEL_CONFERENCE_DISCONNECTED  | 3    | Disconnected state.|

## CallType<sup>7+</sup>

Enumerates call types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name         | Value  | Description        |
| ------------- | ---- | ------------ |
| TYPE_CS       | 0    | CS call.      |
| TYPE_IMS      | 1    | IMS call.     |
| TYPE_OTT      | 2    | OTT call.     |
| TYPE_ERR_CALL | 3    | Error call type.|
| TYPE_VOIP<sup>11+</sup> | 4    | VoIP call.|

## VideoStateType<sup>7+</sup>

Video state type.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                                  | Value  | Description    |
| ------------------------------------- | ---- | --------|
| TYPE_VOICE                            | 0    | Voice state.|
| TYPE_VIDEO_SEND_ONLY<sup>11+</sup>    | 1    | Data sending only during a video call.|
| TYPE_VIDEO_RECEIVE_ONLY<sup>11+</sup> | 2    | Data receiving only during a video call.|
| TYPE_VIDEO                            | 3    | Video state.|
| TYPE_VIDEO_BIDIRECTIONAL<sup>11+</sup>| 4    | Data receiving/sending status during a video call.|

## DetailedCallState<sup>7+</sup>

Enumerates detailed call states.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                     | Value  | Description          |
| ------------------------- | ---- | -------------- |
| CALL_STATUS_ACTIVE        | 0    | Active state.  |
| CALL_STATUS_HOLDING       | 1    | Hold state.  |
| CALL_STATUS_DIALING       | 2    | Dialing state.  |
| CALL_STATUS_ALERTING      | 3    | Alerting state.  |
| CALL_STATUS_INCOMING      | 4    | Incoming state.  |
| CALL_STATUS_WAITING       | 5    | Enumerates call waiting states.  |
| CALL_STATUS_DISCONNECTED  | 6    | Disconnected state.|
| CALL_STATUS_DISCONNECTING | 7    | Disconnecting state.  |
| CALL_STATUS_IDLE          | 8    | Idle state.  |

## CallRestrictionInfo<sup>8+</sup>

Defines the call restriction information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

|   Name  | Type                                        | Mandatory| Description        |
| -------- | -------------------------------------------- | ---- | ------------ |
| type     | [CallRestrictionType](#callrestrictiontype8) | Yes  | Call restriction type.|
| password | string                                       | Yes  | Password.        |
| mode     | [CallRestrictionMode](#callrestrictionmode8) | Yes  | Enumerates call restriction modes.|

## CallRestrictionMode<sup>8+</sup>

Enumerates call restriction modes.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                         | Value  | Description        |
| ----------------------------- | ---- | ------------ |
| RESTRICTION_MODE_DEACTIVATION | 0    | Call restriction deactivated.|
| RESTRICTION_MODE_ACTIVATION   | 1    | Call restriction activated.|

## CallEventOptions<sup>8+</sup>

Defines the call event options.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

|   Name | Type                                      | Mandatory| Description          |
| ------- | ------------------------------------------ | ---- | -------------- |
| eventId | [CallAbilityEventId](#callabilityeventid8) | Yes  | Enumerates call ability event IDs.|

## CallAbilityEventId<sup>8+</sup>

Enumerates call ability event IDs.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                                 | Value  | Description           |
| ------------------------------------- | ---- | --------------- |
| EVENT_DIAL_NO_CARRIER                 | 1    | No available carrier during dialing. |
| EVENT_INVALID_FDN_NUMBER              | 2    | Invalid FDN.|
| EVENT_HOLD_CALL_FAILED<sup>11+</sup>  | 3    | Failed to place the call on hold.|
| EVENT_SWAP_CALL_FAILED<sup>11+</sup>  | 4    | Failed to place the current call on hold and answer the waiting call.|
| EVENT_COMBINE_CALL_FAILED<sup>11+</sup>  | 5 | Failed to combine calls.|
| EVENT_SPLIT_CALL_FAILED<sup>11+</sup> | 6    | Failed to split the call.|
| EVENT_SHOW_FULL_SCREEN<sup>12+</sup>  | 7    | Displaying the call UI in full screen.  |
| EVENT_SHOW_FLOAT_WINDOW<sup>12+</sup> | 8    | Displaying the call UI in a floating widow.|

## DialScene<sup>8+</sup>

Enumerates dialup scenarios.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name           | Value  | Description        |
| --------------- | ---- | ------------ |
| CALL_NORMAL     | 0    | Common call.    |
| CALL_PRIVILEGED | 1    | Privileged call.    |
| CALL_EMERGENCY  | 2    | Emergency call.|

## DialType<sup>8+</sup>

Enumerates dialup types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                | Value  | Description            |
| -------------------- | ---- | ---------------- |
| DIAL_CARRIER_TYPE    | 0    | Carrier.    |
| DIAL_VOICE_MAIL_TYPE | 1    | Voice mail.|
| DIAL_OTT_TYPE        | 2    | OTT.     |

## RejectMessageOptions<sup>7+</sup>

Defines options for the call rejection message.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

|     Name      | Type  | Mandatory| Description    |
| -------------- | ------ | ---- | -------- |
| messageContent | string | Yes  | Message content.|

## CallTransferResult<sup>8+</sup>

Defines the call transfer result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

|          Name           |                 Type              | Mandatory|       Description      |
| ------------------------ | ---------------------------------- | ---- | ---------------- |
| status                   | [TransferStatus](#transferstatus8) |  Yes | Enumerates call transfer states.        |
| number                   | string                             |  Yes | Call transfer number.            |
| startHour<sup>9+</sup>   | number                             |  Yes | Hour in the start time.|
| startMinute<sup>9+</sup> | number                             |  Yes | Minute in the start time.|
| endHour<sup>9+</sup>     | number                             |  Yes | Hour in the end time.|
| endMinute<sup>9+</sup>   | number                             |  Yes | Minute in the end time.|

## CallWaitingStatus<sup>7+</sup>

Enumerates call waiting states.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                | Value  | Description        |
| -------------------- | ---- | ------------ |
| CALL_WAITING_DISABLE | 0    | Call waiting disabled.|
| CALL_WAITING_ENABLE  | 1    | Call waiting enabled.|

## RestrictionStatus<sup>8+</sup>

Enumerates call restriction states.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name               | Value  | Description    |
| ------------------- | ---- | -------- |
| RESTRICTION_DISABLE | 0    | Call restriction disabled.|
| RESTRICTION_ENABLE  | 1    | Call restriction enabled.|

## TransferStatus<sup>8+</sup>

Enumerates call transfer states.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name            | Value  | Description    |
| ---------------- | ---- | -------- |
| TRANSFER_DISABLE | 0    | Call transfer disabled.|
| TRANSFER_ENABLE  | 1    | Call transfer enabled.|

## DisconnectedDetails<sup>9+</sup>

Defines the call disconnection cause.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name   |                    Type                   | Mandatory| Description           |
| ------- | ------------------------------------------ | ---- | --------------- |
| reason  | [DisconnectedReason](#disconnectedreason8) | Yes  | Defines the call disconnection cause.   |
| message | string                                     | Yes  | Call ending message.|

## DisconnectedReason<sup>8+</sup>

Enumerates call disconnection causes.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

|                              Name                           | Value  |                  Description                  |
| ------------------------------------------------------------ | ---- | --------------------------------------- |
| UNASSIGNED_NUMBER                                            | 1    | Unallocated (unassigned) number.                     |
| NO_ROUTE_TO_DESTINATION                                      | 3    | No route to destination.                       |
| CHANNEL_UNACCEPTABLE                                         | 6    | Channel unacceptable.                         |
| OPERATOR_DETERMINED_BARRING                                  | 8    | Operator determined barring (ODB).                             |
| CALL_COMPLETED_ELSEWHERE<sup>9+</sup>                        | 13   | Call completed elsewhere.                     |
| NORMAL_CALL_CLEARING                                         | 16   | Normal call clearing.                           |
| USER_BUSY                                                    | 17   | User busy.                                 |
| NO_USER_RESPONDING                                           | 18   | No user responding.                             |
| USER_ALERTING_NO_ANSWER                                      | 19   | User alerting, no answer.                 |
| CALL_REJECTED                                                | 21   | Call rejected.                               |
| NUMBER_CHANGED                                               | 22   | Number changed.                               |
| CALL_REJECTED_DUE_TO_FEATURE_AT_THE_DESTINATION<sup>9+</sup> | 24   | Call rejected due to reasons of the destination, for example, activation of Anonymous Call Rejection.|
| FAILED_PRE_EMPTION<sup>9+</sup>                              | 25   | Failed preemption.                               |
| NON_SELECTED_USER_CLEARING<sup>9+</sup>                      | 26   | Non-selected user clearing.                         |
| DESTINATION_OUT_OF_ORDER                                     | 27   | Destination out of order.                               |
| INVALID_NUMBER_FORMAT                                        | 28   | Invalid number format (incomplete number).                           |
| FACILITY_REJECTED<sup>9+</sup>                               | 29   | Facility rejected.                           |
| RESPONSE_TO_STATUS_ENQUIRY<sup>9+</sup>                      | 30   | Response to status enquiry.                       |
| NORMAL_UNSPECIFIED<sup>9+</sup>                              | 31   | Normal, unspecified.                           |
| NO_CIRCUIT_CHANNEL_AVAILABLE<sup>9+</sup>                    | 34   | No circuit/channel available.                        |
| NETWORK_OUT_OF_ORDER                                         | 38   | Network fault.                               |
| TEMPORARY_FAILURE                                            | 41   | Temporary failure.                               |
| SWITCHING_EQUIPMENT_CONGESTION<sup>9+</sup>                  | 42   | Switching equipment congestion.                           |
| ACCESS_INFORMATION_DISCARDED<sup>9+</sup>                    | 43   | Access information discarded.                         |
| REQUEST_CIRCUIT_CHANNEL_NOT_AVAILABLE<sup>9+</sup>           | 44   | Requested circuit/channel unavailable.                  |
| RESOURCES_UNAVAILABLE_UNSPECIFIED<sup>9+</sup>               | 47   | Resources unavailable, unspecified.                       |
| QUALITY_OF_SERVICE_UNAVAILABLE<sup>9+</sup>                  | 49   | QoS unavailable.                         |
| REQUESTED_FACILITY_NOT_SUBSCRIBED<sup>9+</sup>               | 50   | Requested facility not subscribed.                       |
| INCOMING_CALLS_BARRED_WITHIN_THE_CUG<sup>9+</sup>            | 55   | Incoming calls barred within the CUG.                          |
| BEARER_CAPABILITY_NOT_AUTHORIZED<sup>9+</sup>                | 57   | Bearer capability not authorized.                         |
| BEARER_CAPABILITY_NOT_PRESENTLY_AVAILABLE<sup>9+</sup>       | 58   | Bearer capability presently available.                     |
| SERVICE_OR_OPTION_NOT_AVAILABLE_UNSPECIFIED<sup>9+</sup>     | 63   | Service or option not available, unspecified.               |
| BEARER_SERVICE_NOT_IMPLEMENTED<sup>9+</sup>                  | 65   | Bearer service not implemented.                         |
| ACM_EQUALTO_OR_GREATER_THAN_THE_MAXIMUM_VALUE<sup>9+</sup>   | 68   | ACM greater than or equal to the maximum value.                    |
| REQUESTED_FACILITY_NOT_IMPLEMENTED<sup>9+</sup>              | 69   | Requested facility not implemented.                       |
| ONLY_RESTRICTED_DIGITAL_INFO_BEARER_CAPABILITY_IS_AVAILABLE<sup>9+</sup> | 70   | Only restricted digital information bearer capability available.     |
| SERVICE_OR_OPTION_NOT_IMPLEMENTED_UNSPECIFIED<sup>9+</sup>   | 79   | Service or option not implemented, unspecified.               |
| INVALID_TRANSACTION_IDENTIFIER_VALUE<sup>9+</sup>            | 81   | Invalid transaction identifier value.                     |
| USER_NOT_MEMBER_OF_CUG<sup>9+</sup>                          | 87   | User not member of CUG.                        |
| INCOMPATIBLE_DESTINATION<sup>9+</sup>                        | 88   | Incompatible destination.                             |
| INVALID_TRANSIT_NETWORK_SELECTION<sup>9+</sup>               | 91   | Invalid transit network selection.                     |
| SEMANTICALLY_INCORRECT_MESSAGE<sup>9+</sup>                  | 95   | Semantically incorrect message.                         |
| INVALID_MANDATORY_INFORMATION<sup>9+</sup>                   | 96   | Invalid mandatory information.                         |
| MESSAGE_TYPE_NON_EXISTENT_OR_NOT_IMPLEMENTED<sup>9+</sup>    | 97   | Message type non-existent or not implemented.                 |
| MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE<sup>9+</sup> | 98   | Message type not compatible with protocol state.               |
| INFORMATION_ELEMENT_NON_EXISTENT_OR_NOT_IMPLEMENTED<sup>9+</sup>    | 99   | IE non-existent or not implemented.                |
| CONDITIONAL_IE_ERROR<sup>9+</sup>                            | 100  | Conditional IE error.                             |
| MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE<sup>9+</sup>      | 101  | Message not compatible with protocol state.                   |
| RECOVERY_ON_TIMER_EXPIRED<sup>9+</sup>                       | 102  | Recovery on timer expiry.             |
| PROTOCOL_ERROR_UNSPECIFIED<sup>9+</sup>                      | 111  | Protocol error, unspecified.                       |
| INTERWORKING_UNSPECIFIED<sup>9+</sup>                        | 127  | Interworking, unspecified.                           |
| CALL_BARRED<sup>9+</sup>                                     | 240  | Call barred.                             |
| FDN_BLOCKED<sup>9+</sup>                                     | 241  | FDN blocked.                                |
| IMSI_UNKNOWN_IN_VLR<sup>9+</sup>                             | 242  | IMSI unknown in VLR.                        |
| IMEI_NOT_ACCEPTED<sup>9+</sup>                               | 243  | IMEI not accepted.                           |
| DIAL_MODIFIED_TO_USSD<sup>9+</sup>                           | 244  | Dial request modified to USSD request.                         |
| DIAL_MODIFIED_TO_SS<sup>9+</sup>                             | 245  | Dial request modified to SS request.                       |
| DIAL_MODIFIED_TO_DIAL<sup>9+</sup>                           | 246  | Dial request modified to dial with different number.                       |
| RADIO_OFF<sup>9+</sup>                                       | 247  | Radio off.                       |
| OUT_OF_SERVICE<sup>9+</sup>                                  | 248  | Stops the service.                               |
| NO_VALID_SIM<sup>9+</sup>                                    | 249  | No valid SIM.                              |
| RADIO_INTERNAL_ERROR<sup>9+</sup>                            | 250  | Radio internal error.                     |
| NETWORK_RESP_TIMEOUT<sup>9+</sup>                            | 251  | Network response timeout.                           |
| NETWORK_REJECT<sup>9+</sup>                                  | 252  | Request rejected by network.                               |
| RADIO_ACCESS_FAILURE<sup>9+</sup>                            | 253  | Radio access failure.                         |
| RADIO_LINK_FAILURE<sup>9+</sup>                              | 254  | Radio link failure.                         |
| RADIO_LINK_LOST<sup>9+</sup>                                 | 255  | Radio link lost.                         |
| RADIO_UPLINK_FAILURE<sup>9+</sup>                            | 256  | Radio uplink failure.                     |
| RADIO_SETUP_FAILURE<sup>9+</sup>                             | 257  | Radio setup failure.                     |
| RADIO_RELEASE_NORMAL<sup>9+</sup>                            | 258  | Radio release normal.                         |
| RADIO_RELEASE_ABNORMAL<sup>9+</sup>                          | 259  | Radio release abnormal.                         |
| ACCESS_CLASS_BLOCKED<sup>9+</sup>                            | 260  | Access class blocked.                           |
| NETWORK_DETACH<sup>9+</sup>                                  | 261  | Network detached.                               |
| INVALID_PARAMETER                                            | 1025 | Invalid parameter.                               |
| SIM_NOT_EXIT                                                 | 1026 | SIM not exit.                            |
| SIM_PIN_NEED                                                 | 1027 | SIM PIN needed.                         |
| CALL_NOT_ALLOW                                               | 1029 | Call not allowed.                             |
| SIM_INVALID                                                  | 1045 | No valid SIM.                              |
| UNKNOWN                                                      | 1279 | Unknown reason.                               |

## MmiCodeResults<sup>9+</sup>

Defines the MMI code result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name   | Type                            | Mandatory| Description           |
| ------- | -------------------------------- | ---- | --------------- |
| result  | [MmiCodeResult](#mmicoderesult9) | Yes  | Defines the MMI code result.|
| message | string                           | Yes  | MMI code message.|

## MmiCodeResult<sup>9+</sup>

Defines the MMI code result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name            | Value  | Description         |
| ---------------- | ---- | ------------- |
| MMI_CODE_SUCCESS | 0    | Success.|
| MMI_CODE_FAILED  | 1    | Failure.|

## call.answerCall<sup>11+</sup>

answerCall(videoState: VideoStateType, callId: number\): Promise\<void\>

Answers a call. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ANSWER_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name                  | Type               | Mandatory| Description                                                        |
| ----------------------- | ------------------- | ---- | ------------------------------------------------------------ |
| videoState| [VideoStateType](#videostatetype7)| Yes  | Video state.                                                |
| callId    | number                            | Yes  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events.                |

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.answerCall(0, 1).then(() => {
    console.log(`answerCall success.`);
}).catch((err: BusinessError) => {
    console.error(`answerCall fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.cancelCallUpgrade<sup>11+</sup>

cancelCallUpgrade\(callId: number\): Promise\<void\>

Cancels the upgrade of a video call. This API uses a promise to return the result.

**System API**: This is a system API.

**Required Permissions**: ohos.permission.PLACE_CALL

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type                        | Mandatory| Description          |
| ------ | ---------------------------- | ---- | -------------- |
| callId | number                       | Yes  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.cancelCallUpgrade(1).then(() => {
    console.log(`cancelCallUpgrade success.`);
}).catch((err: BusinessError) => {
    console.error(`cancelCallUpgrade fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.controlCamera<sup>11+</sup>

controlCamera\(callId: number, cameraId: string\): Promise\<void\>

Uses the specified camera to make a video call. If **cameraId** is left empty, the camera is disabled. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type                        | Mandatory| Description          |
| ------ | ---------------------------- | ---- | -------------- |
| callId | number                       | Yes  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events.      |
| cameraId | string                     | Yes  | Camera ID. For details about how to obtain the camera ID, see [Camera Management](../apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedcameras).|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result of starting, closing, or switching a camera.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.controlCamera(1, "1").then(() => {
    console.log(`controlCamera success.`);
}).catch((err: BusinessError) => {
    console.error(`controlCamera fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.setPreviewSurface<sup>11+</sup>

setPreviewSurface\(callId: number, surfaceId: string\): Promise\<void\>

Sets the local preview window. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type                        | Mandatory| Description          |
| ------ | ---------------------------- | ---- | -------------- |
| callId | number                       | Yes  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events.      |
| surfaceId | string                    | Yes  | Preview window ID. For details about how to obtain **surfaceId**, see [getXComponentSurfaceId](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid9).  |

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.setPreviewSurface(1, "surfaceId1").then(() => {
    console.log(`setPreviewSurface success.`);
}).catch((err: BusinessError) => {
    console.error(`setPreviewSurface fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.setDisplaySurface<sup>11+</sup>

setDisplaySurface\(callId: number, surfaceId: string\): Promise\<void\>

Sets the remote display window. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type                        | Mandatory| Description          |
| ------ | ---------------------------- | ---- | -------------- |
| callId | number                       | Yes  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events.      |
| surfaceId | string                    | Yes  | Display window ID. For details about how to obtain **surfaceId**, see [getXComponentSurfaceId](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid9).  |

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.setDisplaySurface(1, "surfaceId1").then(() => {
    console.log(`setDisplaySurface success.`);
}).catch((err: BusinessError) => {
    console.error(`setDisplaySurface fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.setDeviceDirection<sup>11+</sup>

setDeviceDirection\(callId: number, deviceDirection: DeviceDirection\): Promise\<void\>

Sets the video call screen to follow the device direction. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name| Type                                            | Mandatory| Description          |
| ------ | ----------------------------------------------- | ---- | -------------- |
| callId | number                                          | Yes  | Call ID. You can obtain the value by subscribing to **callDetailsChange** events.|
| deviceDirection  | [DeviceDirection](#devicedirection11) | Yes  | Device direction. It determines the direction of the video call screen.    |

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.setDeviceDirection(1, 0).then(() => {
    console.log(`setDeviceDirection success.`);
}).catch((err: BusinessError) => {
    console.error(`setDeviceDirection fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.on('imsCallModeChange')<sup>11+</sup>

on\(type: 'imsCallModeChange', callback: Callback\<ImsCallModeInfo\>\): void

Subscribes to **imsCallModeChange** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                       | Mandatory| Description                      |
| -------- | ------------------------------------------ | ---- | -------------------------- |
| type     | string                                     | Yes  | Call mode change. This field has a fixed value of **imsCallModeChange**.|
| callback | Callback<[ImsCallModeInfo](#imscallmode8)> | Yes  | Callback used to return the result.        |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.on('imsCallModeChange', (data: call.ImsCallModeInfo) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('imsCallModeChange')<sup>11+</sup>

off\(type: 'imsCallModeChange', callback?: Callback\<ImsCallModeInfo\>\): void

Unsubscribes from **imsCallModeChange** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                       | Mandatory| Description                              |
| -------- | ------------------------------------------ | ---- | ---------------------------------- |
| type     | string                                     | Yes  | Call mode change. This field has a fixed value of **imsCallModeChange**.|
| callback | Callback<[ImsCallModeInfo](#imscallmode8)> | No  | Callback used to return the result. If this field is not set, no subscription cancellation result will be received.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.off('imsCallModeChange', (data: call.ImsCallModeInfo) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('callSessionEvent')<sup>11+</sup>

on\(type: 'callSessionEvent', callback: Callback\<CallSessionEvent\>\): void

Subscribes to **callSessionEvent** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                               | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| type     | string                                            | Yes  | Call session event. This field has a fixed value of **callSessionEvent**.|
| callback | Callback<[CallSessionEvent](#callsessionevent11)> | Yes  | Callback used to return the result. |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.on('callSessionEvent', (data: call.CallSessionEvent) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('callSessionEvent')<sup>11+</sup>

off\(type: 'callSessionEvent', callback?: Callback\<CallSessionEvent\>\): void

Unsubscribes from **callSessionEvent** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                       | Mandatory| Description                              |
| -------- | ------------------------------------------ | ---- | ---------------------------------- |
| type     | string                                     | Yes  | Call session event. This field has a fixed value of **callSessionEvent**.|
| callback | Callback<[CallSessionEvent](#callsessionevent11)> | No  | Callback used to return the result. If this field is not set, no subscription cancellation result will be received.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.off('callSessionEvent', (data: call.CallSessionEvent) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('peerDimensionsChange')<sup>11+</sup>

on\(type: 'peerDimensionsChange', callback: Callback\<PeerDimensionsDetail\>\): void

Subscribes to **peerDimensionsChange** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                      | Mandatory| Description                      |
| -------- | --------------------------------------------------------- | ---- | -------------------------- |
| type     | string                                                    | Yes  | Screen resolution change. This field has a fixed value of **peerDimensionsChange**.|
| callback | Callback<[PeerDimensionsDetail](#peerdimensionsdetail11)> | Yes  | Callback used to return the result.             |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.on('peerDimensionsChange', (data: call.PeerDimensionsDetail) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('peerDimensionsChange')<sup>11+</sup>

off\(type: 'peerDimensionsChange', callback?: Callback\<PeerDimensionsDetail\>\): void

Unsubscribes from **peerDimensionsChange** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                      | Mandatory| Description                      |
| -------- | --------------------------------------------------------- | ---- | -------------------------- |
| type     | string                                                    | Yes  | Screen resolution change. This field has a fixed value of **peerDimensionsChange**.|
| callback | Callback<[PeerDimensionsDetail](#peerdimensionsdetail11)> | No  |  Callback used to return the result. If this field is not set, no subscription cancellation result will be received.                |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.off('peerDimensionsChange', (data: call.PeerDimensionsDetail) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('cameraCapabilitiesChange')<sup>11+</sup>

on\(type: 'cameraCapabilitiesChange', callback: Callback\<CameraCapabilities\>\): void

Subscribes to **cameraCapabilitiesChange** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                  | Mandatory| Description                      |
| -------- | ------------------------------------------------------| ---- | -------------------------- |
| type     | string                                                | Yes  | Camera capability change. This field has a fixed value of **cameraCapabilitiesChange**.|
| callback | Callback<[CameraCapabilities](#cameracapabilities11)> | Yes  | Callback used to return the result.                |

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
call.on('cameraCapabilitiesChange', (data: call.CameraCapabilities) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('cameraCapabilitiesChange')<sup>11+</sup>

off\(type: 'cameraCapabilitiesChange', callback?: Callback\<CameraCapabilities\>\): void

Unsubscribes from **cameraCapabilitiesChange** events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CallManager

**Parameters**

| Name  | Type                                                  | Mandatory| Description                              |
| -------- | ----------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                | Yes  | Camera capability change. This field has a fixed value of **cameraCapabilitiesChange**.|
| callback | Callback<[CameraCapabilities](#cameracapabilities11)> | No  | Callback used to return the result. If this field is not set, no subscription cancellation result will be received.|

**Error codes**

For details about the error codes, see [ohos.telephony (Telephony) Error Codes](errorcode-telephony.md) and [Universal Error Codes](../errorcode-universal.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
call.off('cameraCapabilitiesChange', (data: call.CameraCapabilities) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## VideoRequestResultType<sup>11+</sup>

Enumerates video call upgrade or downgrade request types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                                      | Value    | Description    |
| ------------------------------------------ | ------ | --------|
| TYPE_REQUEST_SUCCESS                       | 0      | Success.|
| TYPE_REQUEST_FAILURE                       | 1      | Failed.|
| TYPE_REQUEST_INVALID                       | 2      | Invalid request.|
| TYPE_REQUEST_TIMED_OUT                     | 3      | Request timeout.|
| TYPE_REQUEST_REJECTED_BY_REMOTE            | 4      | Request denied.|
| TYPE_REQUEST_UPGRADE_CANCELED              | 5      | Upgrade request canceled.|
| TYPE_DOWNGRADE_RTP_OR_RTCP_TIMEOUT         | 100    | RTP or RTCP downgrade timeout.|
| TYPE_DOWNGRADE_RTP_AND_RTCP_TIMEOUT        | 101    | RTP and RTCP downgrade timeout.|

## DeviceDirection<sup>11+</sup>

Enumerates device directions in a video call.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                | Value    | Description    |
| -------------------- | ------ | --------|
| DEVICE_DIRECTION_0   | 0      | 0-degree direction.|
| DEVICE_DIRECTION_90   | 90     | 90-degree direction.|
| DEVICE_DIRECTION_180  | 180    | 180-degree direction.|
| DEVICE_DIRECTION_270  | 270    | 270-degree direction.|

## CallSessionEventId<sup>11+</sup>

Enumerates video call event types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                          | Value    | Description    |
| ------------------------------ | ------ | --------|
| EVENT_CONTROL_CAMERA_FAILURE   | 0      | Camera setting failed.|
| EVENT_CONTROL_CAMERA_READY     | 1      | Camera setting succeeded.|
| EVENT_DISPLAY_SURFACE_RELEASED  | 100    | Remote display window released.|
| EVENT_PREVIEW_SURFACE_RELEASED  | 101    | Local preview window released.|

## ImsCallModeInfo<sup>11+</sup>

Defines the video call mode information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name   |                    Type                            | Mandatory| Description          |
| ------- | -------------------------------------------------- | ---- | ------------- |
| callId  | number                                             | Yes  | Call ID.        |
| isRequestInfo| boolean                                       | Yes  | Whether the information is request information.|
| imsCallMode  | [ImsCallMode](#imscallmode8)                  | Yes  | Video call mode.   |
| result  | [VideoRequestResultType](#videorequestresulttype11)| Yes  | Call ending message.|

## CallSessionEvent<sup>11+</sup>

Defines the video call event information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name   |                    Type                            | Mandatory| Description          |
| ------- | -------------------------------------------------- | ---- | ------------- |
| callId  | number                                             | Yes  | Call ID.        |
| eventId  | [CallSessionEventId](#callsessioneventid11)       | Yes  | Video call event.   |

## PeerDimensionsDetail<sup>11+</sup>

Defines the peer image resolution in a video call.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name   |     Type     | Mandatory| Description          |
| ------- | ------------ | ---- | ------------- |
| callId  | number       | Yes  | Call ID.        |
| width   | number       | Yes  | Width of the peer image, in pixels. |
| height  | number       | Yes  | Height of the peer image, in pixels. |

## CameraCapabilities<sup>11+</sup>

Defines the local image resolution in a video call.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name   |     Type     | Mandatory| Description          |
| ------- | ------------ | ---- | ------------- |
| callId  | number       | Yes  | Call ID.        |
| width   | number       | Yes  | Width of the local image, in pixels. |
| height  | number       | Yes  | Height of the local image, in pixels. |

## NumberMarkInfo<sup>12+</sup>

Defines a number mark.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name   |     Type     | Mandatory| Description          |
| ------- | ------------ | ---- | ------------- |
| markType | [MarkType](#marktype12) | Yes  | Mark type.|
| markContent | string | No | Mark content. When **markType** is set to **MARK_TYPE_ENTERPRISE**, the returned information consists of the employee name and ID.|
| markCount | number       | No | Mark count.|
| markSource | string | No| Mark source.|
| isCloud | boolean | No| Whether the number mark is from the cloud. The default value is **false**.<br>- **true**: The number mark is from the cloud.<br>- **false**: The number mark is not from the cloud.|
| markDetails<sup>14+</sup> | string | No| Mark details. When **markType** is set to **MARK_TYPE_ENTERPRISE**, the value of this parameter is the department position.|

## MarkType<sup>12+</sup>

Enumerates number mark types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CallManager

| Name                          | Value    | Description    |
| ------------------------------ | ------ | --------|
| MARK_TYPE_NONE | 0      | No mark.|
| MARK_TYPE_CRANK | 1      | Spam call.|
| MARK_TYPE_FRAUD | 2    | Fraud call.|
| MARK_TYPE_EXPRESS | 3    | Express & delivery.|
| MARK_TYPE_PROMOTE_SALES | 4 | Advertising.|
| MARK_TYPE_HOUSE_AGENT | 5 | Estate agent.|
| MARK_TYPE_INSURANCE | 6 | Insurance & loans.|
| MARK_TYPE_TAXI | 7 | Taxi.|
| MARK_TYPE_CUSTOM | 8 | User-defined.|
| MARK_TYPE_OTHERS | 9 | Other.|
| MARK_TYPE_YELLOW_PAGE | 10 | Yellow page.|
| MARK_TYPE_ENTERPRISE<sup>14+</sup> | 11 | Enterprise contact.|

<!--no_check-->