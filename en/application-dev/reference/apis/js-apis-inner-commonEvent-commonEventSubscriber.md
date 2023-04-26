# CommonEventSubscriber

## getCode

```ts
getCode(callback: AsyncCallback<number>): void
```

Obtains the code of this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                  | Mandatory| Description              |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<number\> | Yes  | Common event code.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

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

```ts
getCode(): Promise<number>
```

Obtains the code of this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<number> | Common event code.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.getCode().then((code) => {
    console.info("getCode " + JSON.stringify(code));
}).catch((err) => {
    console.error(`getCode failed, code is ${err.code}, message is ${err.message}`);
});
```

## setCode

```ts
setCode(code: number, callback: AsyncCallback<void>): void
```

Sets the code for this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | Yes  | Common event code.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

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

```ts
setCode(code: number): Promise<void>
```

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
let subscriber;	// Subscriber object successfully created.

subscriber.setCode(1).then(() => {
    console.info("setCode");
}).catch((err) => {
    console.error(`setCode failed, code is ${err.code}, message is ${err.message}`);
});
```

## getData

```ts
getData(callback: AsyncCallback<string>): void
```

Obtains the data of this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                  | Mandatory| Description                |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | Yes  | Common event data.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

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

```ts
getData(): Promise<string>
```

Obtains the data of this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description              |
| ---------------- | ------------------ |
| Promise\<string> | Common event data.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

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
let subscriber;	// Subscriber object successfully created.

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

```ts
setData(data: string): Promise<void>
```

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
let subscriber;	// Subscriber object successfully created.

subscriber.setData("publish_data_changed").then(() => {
    console.info("setData");
}).catch((err) => {
    console.error(`setCode failed, code is ${err.code}, message is ${err.message}`);
});
```

## setCodeAndData

```ts
setCodeAndData(code: number, data: string, callback:AsyncCallback<void>): void
```

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
let subscriber;	// Subscriber object successfully created.

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

```ts
setCodeAndData(code: number, data: string): Promise<void>
```

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
let subscriber;	// Subscriber object successfully created.

subscriber.setCodeAndData(1, "publish_data_changed").then(() => {
    console.info("setCodeAndData");
}).catch((err) => {
    console.error(`setCodeAndData failed, code is ${err.code}, message is ${err.message}`);
});
```

## isOrderedCommonEvent

```ts
isOrderedCommonEvent(callback: AsyncCallback<boolean>): void
```

Checks whether this common event is an ordered one. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Returns **true** if the common event is an ordered one; returns **false** otherwise.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

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

```ts
isOrderedCommonEvent(): Promise<boolean>
```

Checks whether this common event is an ordered one. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                            |
| ----------------- | -------------------------------- |
| Promise\<boolean> | Returns **true** if the common event is an ordered one; returns **false** otherwise.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.isOrderedCommonEvent().then((isOrdered) => {
    console.info("isOrdered " + JSON.stringify(isOrdered));
}).catch((err) => {
    console.error(`isOrdered failed, code is ${err.code}, message is ${err.message}`);
});
```

## isStickyCommonEvent

```ts
isStickyCommonEvent(callback: AsyncCallback<boolean>): void
```

Checks whether this common event is a sticky one. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Returns **true** if the common event is a sticky one; returns **false** otherwise.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

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

```ts
isStickyCommonEvent(): Promise<boolean>
```

Checks whether this common event is a sticky one. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                            |
| ----------------- | -------------------------------- |
| Promise\<boolean> | Returns **true** if the common event is a sticky one; returns **false** otherwise.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.isStickyCommonEvent().then((isSticky) => {
    console.info("isSticky " + JSON.stringify(isSticky));
}).catch((err) => {
    console.error(`isSticky failed, code is ${err.code}, message is ${err.message}`);
});
```

## abortCommonEvent

```ts
abortCommonEvent(callback: AsyncCallback<void>): void
```

Aborts this common event. After the abort, the common event is not sent to the next subscriber. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

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

```ts
abortCommonEvent(): Promise<void>
```

Aborts this common event. After the abort, the common event is not sent to the next subscriber. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.abortCommonEvent().then(() => {
    console.info("abortCommonEvent");
}).catch((err) => {
    console.error(`abortCommonEvent failed, code is ${err.code}, message is ${err.message}`);
});
```

## clearAbortCommonEvent

```ts
clearAbortCommonEvent(callback: AsyncCallback<void>): void
```

Clears the aborted state of this common event. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

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

```ts
clearAbortCommonEvent(): Promise<void>
```

Clears the aborted state of this common event. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.clearAbortCommonEvent().then(() => {
    console.info("clearAbortCommonEvent");
}).catch((err) => {
    console.error(`clearAbortCommonEvent failed, code is ${err.code}, message is ${err.message}`);
});
```

## getAbortCommonEvent

```ts
getAbortCommonEvent(callback: AsyncCallback<boolean>): void
```

Checks whether this common event is in the aborted state. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Returns **true** if the ordered common event is in the aborted state; returns **false** otherwise.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

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

```ts
getAbortCommonEvent(): Promise<boolean>
```

Checks whether this common event is in the aborted state. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                              |
| ----------------- | ---------------------------------- |
| Promise\<boolean> | Returns **true** if the ordered common event is in the aborted state; returns **false** otherwise.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.getAbortCommonEvent().then((abortEvent) => {
    console.info("abortCommonEvent " + JSON.stringify(abortEvent));
}).catch((err) => {
    console.error(`getAbortCommonEvent failed, code is ${err.code}, message is ${err.message}`);
});
```

## getSubscribeInfo

```ts
getSubscribeInfo(callback: AsyncCallback<CommonEventSubscribeInfo>): void
```

Obtains the subscriber information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                                                        | Mandatory| Description                  |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| callback | AsyncCallback\<[CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md)> | Yes  | Callback used to return the subscriber information.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

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

```ts
getSubscribeInfo(): Promise<CommonEventSubscribeInfo>
```

Obtains the subscriber information. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| Promise\<[CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md)> | Promise used to return the subscriber information.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.getSubscribeInfo().then((subscribeInfo) => {
    console.info("subscribeInfo " + JSON.stringify(subscribeInfo));
}).catch((err) => {
    console.error(`getSubscribeInfo failed, code is ${err.code}, message is ${err.message}`);
});
```

## finishCommonEvent<sup>9+</sup>

```ts
finishCommonEvent(callback: AsyncCallback<void>): void
```

Finishes this common event. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                 | Mandatory| Description                             |
| -------- | -------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback returned after the ordered common event is finished.|

**Example**

```ts
let subscriber; // Subscriber object successfully created.

// Callback for ordered common event finishing.
function finishCB(err) {
  if (err.code) {
    console.error(`finishCommonEvent failed, code is ${err.code}, message is ${err.message}`);
} else {
    console.info("FinishCommonEvent");
}

subscriber.finishCommonEvent(finishCB);
```

## finishCommonEvent<sup>9+</sup>

```ts
finishCommonEvent(): Promise<void\>
```

Finishes this common event. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.finishCommonEvent().then(() => {
    console.info("FinishCommonEvent");
}).catch((err) => {
    console.error(`finishCommonEvent failed, code is ${err.code}, message is ${err.message}`);
});
```
