# Telephony Subsystem Changelog



## cl.telephony.1 Call Module reject API Change
Changed the `reject` API to the `rejectCall` API in the call module of the telephony subsystem since API version 9.

You need to adapt your application based on the following information.

**Change Impact**

The `reject` API is deprecated and cannot be used anymore. Use the `rejectCall` API instead. Otherwise, relevant functions will be affected.

- Involved APIs:

```js
  function reject(callId: number, callback: AsyncCallback<void>): void;
  function reject(callId: number, options: RejectMessageOptions, callback: AsyncCallback<void>): void;
  function reject(callId?: number, options?: RejectMessageOptions): Promise<void>;
  function reject(callback: AsyncCallback<void>): void;
  function reject(options: RejectMessageOptions, callback: AsyncCallback<void>): void;
```

- Before change:

```js
  function reject(callId: number, callback: AsyncCallback<void>): void;
  function reject(callId: number, options: RejectMessageOptions, callback: AsyncCallback<void>): void;
  function reject(callId?: number, options?: RejectMessageOptions): Promise<void>;
  function reject(callback: AsyncCallback<void>): void;
  function reject(options: RejectMessageOptions, callback: AsyncCallback<void>): void;
```

- After change:

```js
  function rejectCall(callId: number, callback: AsyncCallback<void>): void;
  function rejectCall(callId: number, options: RejectMessageOptions, callback: AsyncCallback<void>): void;
  function rejectCall(callId?: number, options?: RejectMessageOptions): Promise<void>;
  function rejectCall(callback: AsyncCallback<void>): void;
  function rejectCall(options: RejectMessageOptions, callback: AsyncCallback<void>): void;
```


**Adaptation Guide**

The `reject` API is deprecated and cannot be used anymore. Use the `rejectCall` API instead.
Use the new API. The sample code is as follows:

```js
call.rejectCall("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


```js
let rejectMessageOptions={
    messageContent: "Unknown number blocked"
}
let promise = call.rejectCall(1, rejectMessageOptions);
promise.then(data => {
    console.log(`rejectCall success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`rejectCall fail, promise: err->${JSON.stringify(err)}`);
});
```


```js
let rejectMessageOptions={
    messageContent: "Unknown number blocked"
}
let promise = call.rejectCall(1, rejectMessageOptions);
promise.then(data => {
    console.log(`rejectCall success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`rejectCall fail, promise: err->${JSON.stringify(err)}`);
});
```


```js
call.rejectCall((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


```js
let rejectMessageOptions={
    messageContent: "Unknown number blocked"
}
call.rejectCall(rejectMessageOptions, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## cl.telephony.2 Call Module answer API Change
Changed the `answer` API to the `answerCall` API in the call module of the telephony subsystem since API version 9.

You need to adapt your application based on the following information.

**Change Impact**

The `answer` API is deprecated and cannot be used anymore. Use the `answerCall` API instead. Otherwise, relevant functions will be affected.

- Involved APIs:

```js
  function answer(callId: number, callback: AsyncCallback<void>): void;
  function answer(callId?: number): Promise<void>;
  function answer(callback: AsyncCallback<void>): void;
```

- Before change:

```js
  function answer(callId: number, callback: AsyncCallback<void>): void;
  function answer(callId?: number): Promise<void>;
  function answer(callback: AsyncCallback<void>): void;
```

- After change:

```js
  function answerCall(callId: number, callback: AsyncCallback<void>): void;
  function answerCall(callId?: number): Promise<void>;
  function answerCall(callback: AsyncCallback<void>): void;
```


**Adaptation Guide**

The `answer` API is deprecated and cannot be used anymore. Use the `answerCall` API instead.
Use the new API. The sample code is as follows:

```js
call.answerCall(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


```js
let promise = call.answerCall(1);
promise.then(data => {
    console.log(`answerCall success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`answerCall fail, promise: err->${JSON.stringify(err)}`);
});
```


```js
call.answerCall((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## cl.telephony.1 Call Module hangup API Change
Changed the `hangup` API to the `hangUpCall` API in the call module of the telephony subsystem since API version 9.

You need to adapt your application based on the following information.

**Change Impact**

The `hangup` API is deprecated and cannot be used anymore. Use the `hangUpCall` API instead. Otherwise, relevant functions will be affected.

- Involved APIs:

```js
  function hangup(callId: number, callback: AsyncCallback<void>): void;
  function hangup(callId?: number): Promise<void>;
  function hangup(callback: AsyncCallback<void>): void;
```

- Before change:

```js
  function hangup(callId: number, callback: AsyncCallback<void>): void;
  function hangup(callId?: number): Promise<void>;
  function hangup(callback: AsyncCallback<void>): void;
```

- After change:

```js
  function hangUpCall(callId: number, callback: AsyncCallback<void>): void;
  function hangUpCall(callId?: number): Promise<void>;
  function hangUpCall(callback: AsyncCallback<void>): void;
```


**Adaptation Guide**

The `hangup` API is deprecated and cannot be used anymore. Use the `hangUpCall` API instead.
Use the new API. The sample code is as follows:

```js
call.hangUpCall(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


```js
let promise = call.hangUpCall(1);
promise.then(data => {
    console.log(`hangUpCall success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`hangUpCall fail, promise: err->${JSON.stringify(err)}`);
});
```


```js
call.hangUpCall((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```
