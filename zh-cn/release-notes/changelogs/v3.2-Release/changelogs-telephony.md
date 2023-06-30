# 电话子系统ChangeLog



## cl.telephony.1 call模块reject接口变更
从API9开始，废弃此接口，改为使用rejectCall接口。

开发者需要根据以下说明对应用进行适配。

**变更影响**

该接口删除无法再使用，请使用新增的接口rejectCall替换，否则会影响原有功能。

- 涉及接口

```js
  function reject(callId: number, callback: AsyncCallback<void>): void;
  function reject(callId: number, options: RejectMessageOptions, callback: AsyncCallback<void>): void;
  function reject(callId?: number, options?: RejectMessageOptions): Promise<void>;
  function reject(callback: AsyncCallback<void>): void;
  function reject(options: RejectMessageOptions, callback: AsyncCallback<void>): void;
```

- 变更前：

```js
  function reject(callId: number, callback: AsyncCallback<void>): void;
  function reject(callId: number, options: RejectMessageOptions, callback: AsyncCallback<void>): void;
  function reject(callId?: number, options?: RejectMessageOptions): Promise<void>;
  function reject(callback: AsyncCallback<void>): void;
  function reject(options: RejectMessageOptions, callback: AsyncCallback<void>): void;
```

- 变更后：

```js
  function rejectCall(callId: number, callback: AsyncCallback<void>): void;
  function rejectCall(callId: number, options: RejectMessageOptions, callback: AsyncCallback<void>): void;
  function rejectCall(callId?: number, options?: RejectMessageOptions): Promise<void>;
  function rejectCall(callback: AsyncCallback<void>): void;
  function rejectCall(options: RejectMessageOptions, callback: AsyncCallback<void>): void;
```


**适配指导**

该接口删除无法再使用，请使用新增的接口rejectCall替换。
使用变更后的接口，示例代码如下：

```js
call.rejectCall("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


```js
let rejectMessageOptions={
    messageContent: "拦截陌生号码"
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
    messageContent: "拦截陌生号码"
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
    messageContent: "拦截陌生号码"
}
call.rejectCall(rejectMessageOptions, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## cl.telephony.2 call模块answer接口变更
从API9开始，废弃此接口，改为使answerCall接口。

开发者需要根据以下说明对应用进行适配。

**变更影响**

该接口删除无法再使用，请使用新增的接口answerCall替换，否则会影响原有功能。

- 涉及接口

```js
  function answer(callId: number, callback: AsyncCallback<void>): void;
  function answer(callId?: number): Promise<void>;
  function answer(callback: AsyncCallback<void>): void;
```

- 变更前：

```js
  function answer(callId: number, callback: AsyncCallback<void>): void;
  function answer(callId?: number): Promise<void>;
  function answer(callback: AsyncCallback<void>): void;
```

- 变更后：

```js
  function answerCall(callId: number, callback: AsyncCallback<void>): void;
  function answerCall(callId?: number): Promise<void>;
  function answerCall(callback: AsyncCallback<void>): void;
```


**适配指导**

该接口删除无法再使用，请使用新增的接口answerCall替换。
使用变更后的接口，示例代码如下：

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


## cl.telephony.1 call模块hangup接口变更
从API9开始，废弃此接口，改为使用hangUpCall接口。

开发者需要根据以下说明对应用进行适配。

**变更影响**

该接口删除无法再使用，请使用新增的接口hangUpCall替换，否则会影响原有功能。

- 涉及接口

```js
  function hangup(callId: number, callback: AsyncCallback<void>): void;
  function hangup(callId?: number): Promise<void>;
  function hangup(callback: AsyncCallback<void>): void;
```

- 变更前：

```js
  function hangup(callId: number, callback: AsyncCallback<void>): void;
  function hangup(callId?: number): Promise<void>;
  function hangup(callback: AsyncCallback<void>): void;
```

- 变更后：

```js
  function hangUpCall(callId: number, callback: AsyncCallback<void>): void;
  function hangUpCall(callId?: number): Promise<void>;
  function hangUpCall(callback: AsyncCallback<void>): void;
```


**适配指导**

该接口删除无法再使用，请使用新增的接口hangUpCall替换。
使用变更后的接口，示例代码如下：

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