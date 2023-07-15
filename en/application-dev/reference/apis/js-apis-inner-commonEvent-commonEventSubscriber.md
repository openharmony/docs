# CommonEventSubscriber

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Usage

Before using the **CommonEventSubscriber** module, you must obtain a **subscriber** object by calling **CommonEvent.createSubscriber**.

```ts
import CommonEvent from '@ohos.commonEvent';
let subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
let subscribeInfo = {
	events: ["event"]
};

// Callback for subscriber creation.
function createCB(err, commonEventSubscriber) {
    if (err.code) {
        console.error(`createSubscriber failed, code is ${err.code}`);
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
    }
}

// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo, createCB);
```

## getCode

getCode(callback: AsyncCallback\<number>): void

Obtains the code of this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                  | Mandatory| Description              |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<number\> | Yes  | Common event code.|

**Example**

```ts
// Callback for result code obtaining of an ordered common event.
function getCodeCB(err, code) {
    if (err.code) {
        console.error(`getCode failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getCode " + JSON.stringify(code));
    }
}
subscriber.getCode(getCodeCB);
```

## getCode

getCode(): Promise\<number>

Obtains the code of this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<number> | Common event code.|

**Example**

```ts
subscriber.getCode().then((code) => {
    console.info("getCode " + JSON.stringify(code));
}).catch((err) => {
    console.error(`getCode failed, code is ${err.code}, message is ${err.message}`);
});
```

## setCode

setCode(code: number, callback: AsyncCallback\<void>): void

Sets the code for this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | Yes  | Common event code.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
// Callback for result code setting of an ordered common event.
function setCodeCB(err) {
    if (err.code) {
        console.error(`setCode failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setCode");
    }
}
subscriber.setCode(1, setCodeCB);
```

## setCode

setCode(code: number): Promise\<void>

Sets the code for this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| code   | number | Yes  | Common event code.|

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
subscriber.setCode(1).then(() => {
    console.info("setCode");
}).catch((err) => {
    console.error(`setCode failed, code is ${err.code}, message is ${err.message}`);
});
```

## getData

getData(callback: AsyncCallback\<string>): void

Obtains the data of this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                  | Mandatory| Description                |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | Yes  | Common event data.|

**Example**

```ts
// Callback for result data obtaining of an ordered common event.
function getDataCB(err, data) {
    if (err.code) {
        console.error(`getData failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getData " + JSON.stringify(data));
    }
}
subscriber.getData(getDataCB);
```

## getData

getData(): Promise\<string>

Obtains the data of this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description              |
| ---------------- | ------------------ |
| Promise\<string> | Common event data.|

**Example**

```ts
subscriber.getData().then((data) => {
    console.info("getData " + JSON.stringify(data));
}).catch((err) => {
    console.error(`getData failed, code is ${err.code}, message is ${err.message}`);
});
```

## setData

setData(data: string, callback: AsyncCallback\<void>): void

Sets the data for this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| data     | string               | Yes  | Common event data.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
// Callback for result data setting of an ordered common event
function setDataCB(err) {
    if (err.code) {
        console.error(`setCode failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setData");
    }
}
subscriber.setData("publish_data_changed", setDataCB);
```

## setData

setData(data: string): Promise\<void>

Sets the data for this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| data   | string | Yes  | Common event data.|

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
subscriber.setData("publish_data_changed").then(() => {
    console.info("setData");
}).catch((err) => {
    console.error(`setCode failed, code is ${err.code}, message is ${err.message}`);
});
```

## setCodeAndData

setCodeAndData(code: number, data: string, callback:AsyncCallback\<void>): void

Sets the code and data for this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | Yes  | Common event code.  |
| data     | string               | Yes  | Common event data.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
// Callback for code and data setting of an ordered common event.
function setCodeDataCB(err) {
    if (err.code) {
        console.error(`setCodeAndData failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setCodeDataCallback");
    }
}
subscriber.setCodeAndData(1, "publish_data_changed", setCodeDataCB);
```

## setCodeAndData

setCodeAndData(code: number, data: string): Promise\<void>

Sets the code and data for this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| code   | number | Yes  | Common event code.|
| data   | string | Yes  | Common event data.|

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
subscriber.setCodeAndData(1, "publish_data_changed").then(() => {
    console.info("setCodeAndData");
}).catch((err) => {
    console.error(`setCodeAndData failed, code is ${err.code}, message is ${err.message}`);
});
```

## isOrderedCommonEvent

isOrderedCommonEvent(callback: AsyncCallback\<boolean>): void

Checks whether this common event is an ordered one. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Returns **true** if the common event is an ordered one; returns **false** otherwise.|

**Example**

```ts
// Callback for checking whether the current common event is an ordered one.
function isOrderedCB(err, isOrdered) {
    if (err.code) {
        console.error(`isOrderedCommonEvent failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isOrdered " + JSON.stringify(isOrdered));
    }
}
subscriber.isOrderedCommonEvent(isOrderedCB);
```

## isOrderedCommonEvent

isOrderedCommonEvent(): Promise\<boolean>

Checks whether this common event is an ordered one. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                            |
| ----------------- | -------------------------------- |
| Promise\<boolean> | Returns **true** if the common event is an ordered one; returns **false** otherwise.|

**Example**

```ts
subscriber.isOrderedCommonEvent().then((isOrdered) => {
    console.info("isOrdered " + JSON.stringify(isOrdered));
}).catch((err) => {
    console.error(`isOrdered failed, code is ${err.code}, message is ${err.message}`);
});
```

## isStickyCommonEvent

isStickyCommonEvent(callback: AsyncCallback\<boolean>): void

Checks whether this common event is a sticky one. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Returns **true** if the common event is a sticky one; returns **false** otherwise.|

**Example**

```ts
// Callback for checking whether the current common event is a sticky one.
function isStickyCB(err, isSticky) {
    if (err.code) {
        console.error(`isStickyCommonEvent failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isSticky " + JSON.stringify(isSticky));
    }
}
subscriber.isStickyCommonEvent(isStickyCB);
```

## isStickyCommonEvent

isStickyCommonEvent(): Promise\<boolean>

Checks whether this common event is a sticky one. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                            |
| ----------------- | -------------------------------- |
| Promise\<boolean> | Returns **true** if the common event is a sticky one; returns **false** otherwise.|

**Example**

```ts
subscriber.isStickyCommonEvent().then((isSticky) => {
    console.info("isSticky " + JSON.stringify(isSticky));
}).catch((err) => {
    console.error(`isSticky failed, code is ${err.code}, message is ${err.message}`);
});
```

## abortCommonEvent

abortCommonEvent(callback: AsyncCallback\<void>): void

Aborts this common event. After the abort, the common event is not sent to the next subscriber. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
// Callback for common event aborting.
function abortCB(err) {
    if (err.code) {
		console.error(`abortCommonEvent failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("abortCommonEvent");
    }
}
subscriber.abortCommonEvent(abortCB);
```

## abortCommonEvent

abortCommonEvent(): Promise\<void>

Aborts this common event. After the abort, the common event is not sent to the next subscriber. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
subscriber.abortCommonEvent().then(() => {
    console.info("abortCommonEvent");
}).catch((err) => {
    console.error(`abortCommonEvent failed, code is ${err.code}, message is ${err.message}`);
});
```

## clearAbortCommonEvent

clearAbortCommonEvent(callback: AsyncCallback\<void>): void

Clears the aborted state of this common event. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
// Callback for clearing the aborted state of the current common event.
function clearAbortCB(err) {
    if (err.code) {
        console.error(`clearAbortCommonEvent failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("clearAbortCommonEvent");
    }
}
subscriber.clearAbortCommonEvent(clearAbortCB);
```

## clearAbortCommonEvent

clearAbortCommonEvent(): Promise\<void>

Clears the aborted state of this common event. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
subscriber.clearAbortCommonEvent().then(() => {
    console.info("clearAbortCommonEvent");
}).catch((err) => {
    console.error(`clearAbortCommonEvent failed, code is ${err.code}, message is ${err.message}`);
});
```

## getAbortCommonEvent

getAbortCommonEvent(callback: AsyncCallback\<boolean>): void

Checks whether this common event is in the aborted state. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Returns **true** if the ordered common event is in the aborted state; returns **false** otherwise.|

**Example**

```ts
// Callback for checking whether the current common event is in the aborted state.
function getAbortCB(err, abortEvent) {
    if (err.code) {
        console.error(`getAbortCommonEvent failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("abortCommonEvent " + abortEvent)
    }
}
subscriber.getAbortCommonEvent(getAbortCB);
```

## getAbortCommonEvent

getAbortCommonEvent(): Promise\<boolean>

Checks whether this common event is in the aborted state. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                              |
| ----------------- | ---------------------------------- |
| Promise\<boolean> | Returns **true** if the ordered common event is in the aborted state; returns **false** otherwise.|

**Example**

```ts
subscriber.getAbortCommonEvent().then((abortEvent) => {
    console.info("abortCommonEvent " + JSON.stringify(abortEvent));
}).catch((err) => {
    console.error(`getAbortCommonEvent failed, code is ${err.code}, message is ${err.message}`);
});
```

## getSubscribeInfo

getSubscribeInfo(callback: AsyncCallback\<CommonEventSubscribeInfo>): void

Obtains the subscriber information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                                                        | Mandatory| Description                  |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| callback | AsyncCallback\<[CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md)> | Yes  | Callback used to return the subscriber information.|

**Example**

```ts
// Callback for subscriber information obtaining.
function getCB(err, subscribeInfo) {
    if (err.code) {
        console.error(`getSubscribeInfo failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeInfo " + JSON.stringify(subscribeInfo));
    }
}
subscriber.getSubscribeInfo(getCB);
```

## getSubscribeInfo

getSubscribeInfo(): Promise\<CommonEventSubscribeInfo>

Obtains the subscriber information. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| Promise\<[CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md)> | Promise used to return the subscriber information.|

**Example**

```ts
subscriber.getSubscribeInfo().then((subscribeInfo) => {
    console.info("subscribeInfo " + JSON.stringify(subscribeInfo));
}).catch((err) => {
    console.error(`getSubscribeInfo failed, code is ${err.code}, message is ${err.message}`);
});
```

## finishCommonEvent<sup>9+</sup>

finishCommonEvent(callback: AsyncCallback\<void>): void

Finishes this common event. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                 | Mandatory| Description                             |
| -------- | -------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback returned after the ordered common event is finished.|

**Example**

```ts
// Callback for ordered common event finishing.
function finishCB(err) {
  if (err.code) {
    console.error(`finishCommonEvent failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("FinishCommonEvent");
  }
}

subscriber.finishCommonEvent(finishCB);
```

## finishCommonEvent<sup>9+</sup>

finishCommonEvent(): Promise\<void>

Finishes this common event. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
subscriber.finishCommonEvent().then(() => {
    console.info("FinishCommonEvent");
}).catch((err) => {
    console.error(`finishCommonEvent failed, code is ${err.code}, message is ${err.message}`);
});
```
