# commonEventSubscriber

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## CommonEventSubscriber

The **CommonEventSubscriber** module provides APIs for describing the common event subscriber.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

### How to Use

Before using the **CommonEventSubscriber** module, you must obtain a **subscriber** object by calling **commonEventManager.createSubscriber**.

<!--code_no_check-->
```ts
import { commonEventManager } from '@kit.BasicServicesKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Define a subscriber to save the created subscriber object for subsequent subscription and unsubscription.
let subscriber: commonEventManager.CommonEventSubscriber;
// Subscriber information.
let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
	events: ['event']
};
// Create a subscriber.
subscriber = commonEventManager.createSubscriberSync(subscribeInfo);
```

### getCode

getCode(callback: AsyncCallback\<number>): void

Obtains the result code (number type) of an ordered common event. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                  | Mandatory| Description              |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 

**Example**

<!--code_no_check-->

```ts
subscriber.getCode((err: BusinessError, code: number) => {
  if (err) {
    console.error(`Failed to get code. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting code, code is ${JSON.stringify(code)}`);
});
```

### getCode

getCode(): Promise\<number>

Obtains the result code (number type) of an ordered common event. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<number> | Promise used to return the result.|

**Example**

<!--code_no_check-->

```ts
subscriber.getCode().then((code: number) => {
  console.info(`Succeeded in getting code, code is ${JSON.stringify(code)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get code. Code is ${err.code}, message is ${err.message}`);
});
```

### getCodeSync<sup>10+</sup>

getCodeSync(): number

Obtains the result code (number type) of an ordered common event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| number | Result code of an ordered common event.|

**Example**

<!--code_no_check-->

```ts
let code: number = subscriber.getCodeSync();
console.info(`Succeeded in getting code, code is ${JSON.stringify(code)}`);
```

### setCode

setCode(code: number, callback: AsyncCallback\<void>): void

Sets the result code (number type) of an ordered common event. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | Yes  | Result code of an ordered common event.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 

**Example**

<!--code_no_check-->

```ts
subscriber.setCode(1, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set code. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in setting code.`);
});
```

### setCode

setCode(code: number): Promise\<void>

Sets the result code (number type) of an ordered common event. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| code   | number | Yes  | Result code of an ordered common event.|

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 

**Example**

<!--code_no_check-->

```ts
subscriber.setCode(1).then(() => {
  console.info(`Succeeded in setting code.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set code. Code is ${err.code}, message is ${err.message}`);
});
```

### setCodeSync<sup>10+</sup>

setCodeSync(code: number): void

Sets the result code (number type) of an ordered common event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| code   | number | Yes  | Result code of an ordered common event.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.                    | 

**Example**

<!--code_no_check-->

```ts
try {
  subscriber.setCodeSync(1);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to set code. Code is ${err.code}, message is ${err.message}`);
}
```

### getData

getData(callback: AsyncCallback\<string>): void

Obtains the result data (string type) of an ordered common event. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                  | Mandatory| Description                |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 

**Example**

<!--code_no_check-->

```ts
// Obtain the result data (string type) of an ordered common event.
subscriber.getData((err: BusinessError, data: string) => {
  if (err) {
    console.error(`Failed to get data. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting data, data is ${JSON.stringify(data)}`);
});
```

### getData

getData(): Promise\<string>

Obtains the result data (string type) of an ordered common event. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description              |
| ---------------- | ------------------ |
| Promise\<string> | Promise used to return the result.|

**Example**

<!--code_no_check-->

```ts
subscriber.getData().then((data: string) => {
  console.info(`Succeeded in getting data, data is ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get data. Code is ${err.code}, message is ${err.message}`);
});
```

### getDataSync<sup>10+</sup>

getDataSync(): string

Obtains the result data (string type) of an ordered common event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description              |
| ---------------- | ------------------ |
| string | Result data of an ordered common event.|

**Example**

<!--code_no_check-->

```ts
let data: string = subscriber.getDataSync();
console.info(`Succeeded in getting data, data is ${data}`);
```

### setData

setData(data: string, callback: AsyncCallback\<void>): void

Sets the result data (string type) of an ordered common event. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| data     | string               | Yes  | Result data of an ordered common event.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 

**Example**

<!--code_no_check-->

```ts
subscriber.setData('publish_data_changed', (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set data. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in setting data.`);
});
```

### setData

setData(data: string): Promise\<void>

Sets the result data (string type) of an ordered common event. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| data   | string | Yes  | Result data of an ordered common event.|

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 

**Example**

<!--code_no_check-->

```ts
subscriber.setData('publish_data_changed').then(() => {
  console.info(`Succeeded in setting data.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set data. Code is ${err.code}, message is ${err.message}`);
});
```

### setDataSync<sup>10+</sup>

setDataSync(data: string): void

Sets the result data (string type) of an ordered common event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| data   | string | Yes  | Result data of an ordered common event.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.                    | 

**Example**

<!--code_no_check-->

```ts
try {
  subscriber.setDataSync('publish_data_changed');
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to set data. Code is ${err.code}, message is ${err.message}`);
}
```

### setCodeAndData

setCodeAndData(code: number, data: string, callback:AsyncCallback\<void>): void

Sets the result code and data of an ordered common event. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | Yes  | Result code of an ordered common event.  |
| data     | string               | Yes  | Result data of an ordered common event.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 

**Example**

<!--code_no_check-->

```ts
subscriber.setCodeAndData(1, 'publish_data_changed', (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set code and data. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in setting code and data.`);
});
```

### setCodeAndData

setCodeAndData(code: number, data: string): Promise\<void>

Sets the result code and data of an ordered common event. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| code   | number | Yes  | Result code of an ordered common event.|
| data   | string | Yes  | Result data of an ordered common event.|

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 

**Example**

<!--code_no_check-->

```ts
subscriber.setCodeAndData(1, 'publish_data_changed').then(() => {
  console.info(`Succeeded in setting code and data.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set code and data. Code is ${err.code}, message is ${err.message}`);
});
```

### setCodeAndDataSync<sup>10+</sup>

setCodeAndDataSync(code: number, data: string): void

Sets the result code and data of an ordered common event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| code   | number | Yes  | Result code of an ordered common event.|
| data   | string | Yes  | Result data of an ordered common event.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.                    | 

**Example**

<!--code_no_check-->

```ts
try {
  subscriber.setCodeAndDataSync(1, 'publish_data_changed');
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to set code and data. Code is ${err.code}, message is ${err.message}`);
}

```

### isOrderedCommonEvent

isOrderedCommonEvent(callback: AsyncCallback\<boolean>): void

Checks whether the current common event is an ordered common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. Returns **true** if the common event is an ordered one; returns **false** if the common event is an unordered one.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 

**Example**

<!--code_no_check-->

```ts
subscriber.isOrderedCommonEvent((err: BusinessError, isOrdered:boolean) => {
  if (err) {
    console.error(`isOrderedCommonEvent failed, code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`isOrderedCommonEvent ${JSON.stringify(isOrdered)}`);
});
```

### isOrderedCommonEvent

isOrderedCommonEvent(): Promise\<boolean>

Checks whether the current common event is an ordered common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                            |
| ----------------- | -------------------------------- |
| Promise\<boolean> | Promise used to return the result. Returns **true** if the common event is an ordered one; returns **false** if the common event is an unordered one.|

**Example**

<!--code_no_check-->

```ts
subscriber.isOrderedCommonEvent().then((isOrdered:boolean) => {
  console.info(`isOrderedCommonEvent ${JSON.stringify(isOrdered)}`);
}).catch((err: BusinessError) => {
  console.error(`isOrderedCommonEvent failed, code is ${err.code}, message is ${err.message}`);
});
```

### isOrderedCommonEventSync<sup>10+</sup>

isOrderedCommonEventSync(): boolean

Checks whether the current common event is an ordered common event.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                            |
| ----------------- | -------------------------------- |
| boolean |Returns **true** if the common event is an ordered one; returns **false** if the common event is an unordered one.|

**Example**

<!--code_no_check-->

```ts
let isOrdered: boolean = subscriber.isOrderedCommonEventSync();
console.info(`isOrderedCommonEventSync ${JSON.stringify(isOrdered)}`);
```

### isStickyCommonEvent

isStickyCommonEvent(callback: AsyncCallback\<boolean>): void

Checks whether a common event is a sticky one. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. Returns **true** if the common event is a sticky one; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 

**Example**

<!--code_no_check-->

```ts
subscriber.isStickyCommonEvent((err: BusinessError, isSticky:boolean) => {
  if (err) {
    console.error(`isStickyCommonEvent failed, code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`isStickyCommonEvent ${JSON.stringify(isSticky)}`);
});
```

### isStickyCommonEvent

isStickyCommonEvent(): Promise\<boolean>

Checks whether a common event is a sticky one. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                            |
| ----------------- | -------------------------------- |
| Promise\<boolean> | Promise used to return the result. Returns **true** if the common event is a sticky one; returns **false** otherwise.|

**Example**

<!--code_no_check-->

```ts
subscriber.isStickyCommonEvent().then((isSticky:boolean) => {
  console.info(`isStickyCommonEvent ${JSON.stringify(isSticky)}`);
}).catch((err: BusinessError) => {
  console.error(`isStickyCommonEvent failed, code is ${err.code}, message is ${err.message}`);
});
```

### isStickyCommonEventSync<sup>10+</sup>

isStickyCommonEventSync(): boolean

Checks whether a common event is a sticky one.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                            |
| ----------------- | -------------------------------- |
| boolean | Returns **true** if the common event is a sticky one; returns **false** otherwise.|

**Example**

<!--code_no_check-->

```ts
let isSticky: boolean = subscriber.isStickyCommonEventSync();
console.info(`isStickyCommonEventSync ${JSON.stringify(isSticky)}`);
```

### abortCommonEvent

abortCommonEvent(callback: AsyncCallback\<void>): void

Aborts an ordered common event. This API is used with [finishCommonEvent](#finishcommonevent9). After the abort, the common event is not sent to the next subscriber. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 

**Example**

<!--code_no_check-->

```ts
subscriber.abortCommonEvent((err: BusinessError) => {
  if (err) {
    console.error(`Failed to abort common event. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in aborting common event.`);
});
subscriber.finishCommonEvent((err: BusinessError) => {
  if (err) {
    console.error(`Failed to finish common event. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in finishing common event.`);
});
```

### abortCommonEvent

abortCommonEvent(): Promise\<void>

Aborts this ordered common event. This API is used with [finishCommonEvent](#finishcommonevent9). After the abort, the common event is not sent to the next subscriber. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise that returns no value.|

**Example**

<!--code_no_check-->

```ts
subscriber.abortCommonEvent().then(() => {
  console.info(`Succeeded in aborting common event.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to abort common event. Code is ${err.code}, message is ${err.message}`);
});
subscriber.finishCommonEvent().then(() => {
  console.info(`Succeeded in finishing common event.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to finish common event. Code is ${err.code}, message is ${err.message}`);
});
```

### abortCommonEventSync<sup>10+</sup>

abortCommonEventSync(): void

Aborts this ordered common event synchronously. This API is used with [finishCommonEvent](#finishcommonevent9). After the abort, the common event is not sent to the next subscriber.

**System capability**: SystemCapability.Notification.CommonEvent

**Example**

<!--code_no_check-->

```ts
subscriber.abortCommonEventSync();
subscriber.finishCommonEvent().then(() => {
  console.info(`Succeeded in finishing common event.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to finish common event. Code is ${err.code}, message is ${err.message}`);
});
```

### clearAbortCommonEvent

clearAbortCommonEvent(callback: AsyncCallback\<void>): void

Clears the aborted state of an ordered common event. Use this API together with [finishCommonEvent](#finishcommonevent9), and the common event can be passed to the next subscriber. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 

**Example**

<!--code_no_check-->

```ts
subscriber.clearAbortCommonEvent((err: BusinessError) => {
  if (err) {
    console.error(`Failed to clear abort common event. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in clearing abort common event.`);
});
subscriber.finishCommonEvent((err: BusinessError) => {
  if (err) {
    console.error(`Failed to finish common event. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in finishing common event.`);
});
```

### clearAbortCommonEvent

clearAbortCommonEvent(): Promise\<void>

Clears the aborted state of this ordered common event. Use this API together with [finishCommonEvent](#finishcommonevent9), and the common event can be passed to the next subscriber. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise that returns no value.|

**Example**

<!--code_no_check-->

```ts
subscriber.clearAbortCommonEvent().then(() => {
  console.info(`Succeeded in clearing abort common event.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to clear abort common event. Code is ${err.code}, message is ${err.message}`);
});
subscriber.finishCommonEvent().then(() => {
  console.info(`Succeeded in finishing common event.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to finish common event. Code is ${err.code}, message is ${err.message}`);
});
```

### clearAbortCommonEventSync<sup>10+</sup>

clearAbortCommonEventSync(): void

Clears the aborted state of this ordered common event. Use this API together with [finishCommonEvent](#finishcommonevent9), and the common event can be passed to the next subscriber.

**System capability**: SystemCapability.Notification.CommonEvent

**Example**

<!--code_no_check-->

```ts
subscriber.clearAbortCommonEventSync();
subscriber.finishCommonEvent().then(() => {
  console.info(`Succeeded in finishing common event.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to finish common event. Code is ${err.code}, message is ${err.message}`);
});
```

### getAbortCommonEvent

getAbortCommonEvent(callback: AsyncCallback\<boolean>): void

Checks whether this ordered common event should be aborted. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. Returns **true** if the ordered common event is in the aborted state; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 

**Example**

<!--code_no_check-->

```ts
subscriber.getAbortCommonEvent((err: BusinessError, abortEvent: boolean) => {
  if (err) {
    console.error(`Failed to get abort common event. Code is ${err.code}, message is ${err.message}`);
    return;
  } 
  console.info(`Succeeded in getting abort common event, abortEvent is ${JSON.stringify(abortEvent)}`);
});
```

### getAbortCommonEvent

getAbortCommonEvent(): Promise\<boolean>

Checks whether this ordered common event should be aborted. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                              |
| ----------------- | ---------------------------------- |
| Promise\<boolean> | Promise used to return the result. Returns **true** if the ordered common event is in the aborted state; returns **false** otherwise.|

**Example**

<!--code_no_check-->

```ts
subscriber.getAbortCommonEvent().then((abortEvent: boolean) => {
  console.info(`Succeeded in getting abort common event, abortEvent is ${JSON.stringify(abortEvent)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get abort common event. Code is ${err.code}, message is ${err.message}`);
});
```

### getAbortCommonEventSync<sup>10+</sup>

getAbortCommonEventSync(): boolean

Checks whether this ordered common event should be aborted.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                              |
| ----------------- | ---------------------------------- |
| boolean |Returns **true** if the ordered common event is in the aborted state; returns **false** otherwise.|

**Example**

<!--code_no_check-->

```ts
let abortEvent: boolean = subscriber.getAbortCommonEventSync();
console.info(`Succeeded in getting abort common event, abortEvent is ${JSON.stringify(abortEvent)}`);
```

### getSubscribeInfo

getSubscribeInfo(callback: AsyncCallback\<CommonEventSubscribeInfo>): void

Obtains the subscriber information. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                                                        | Mandatory| Description                  |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| callback | AsyncCallback\<[CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md)> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 

**Example**

<!--code_no_check-->

```ts
subscriber.getSubscribeInfo((err: BusinessError, subscribeInfo: commonEventManager.CommonEventSubscribeInfo) => {
  if (err) {
    console.error(`Failed to get subscribe info. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting subscribe info, subscribe info is ${JSON.stringify(subscribeInfo)}`);
});
```

### getSubscribeInfo

getSubscribeInfo(): Promise\<CommonEventSubscribeInfo>

Obtains the subscriber information. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| Promise\<[CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md)> | Promise used to return the result.|

**Example**

<!--code_no_check-->

```ts
subscriber.getSubscribeInfo().then((subscribeInfo: commonEventManager.CommonEventSubscribeInfo) => {
  console.info(`Succeeded in getting subscribe info, subscribe info is ${JSON.stringify(subscribeInfo)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get subscribe info. Code is ${err.code}, message is ${err.message}`);
});
```

### getSubscribeInfoSync<sup>10+</sup>

getSubscribeInfoSync(): CommonEventSubscribeInfo

Obtains the subscriber information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md) | Subscriber information.|

**Example**

<!--code_no_check-->

```ts
let subscribeInfo = subscriber.getSubscribeInfoSync();
console.info(`Succeeded in getting subscribe info, subscribe info is ${JSON.stringify(subscribeInfo)}`);
```

### finishCommonEvent<sup>9+</sup>

finishCommonEvent(callback: AsyncCallback\<void>): void

Finishes this ordered common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                 | Mandatory| Description                             |
| -------- | -------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 

**Example**

<!--code_no_check-->

```ts
subscriber.finishCommonEvent((err: BusinessError) => {
  if (err) {
    console.error(`Failed to finish common event. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in finishing common event.`);
});
```

### finishCommonEvent<sup>9+</sup>

finishCommonEvent(): Promise\<void>

Finishes this ordered common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise that returns no value.|

**Example**

<!--code_no_check-->

```ts
subscriber.finishCommonEvent().then(() => {
  console.info(`Succeeded in finishing common event.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to finish common event. Code is ${err.code}, message is ${err.message}`);
});
```
