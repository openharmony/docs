# 拨打电话

该模块提供呼叫管理功能，包括拨打电话、跳转到拨号界面、获取通话状态、格式化电话号码等。

如需订阅通话状态请使用[`observer.on('callStateChange')`](js-apis-observer.md#observeroncallstatechange)。

>**说明：** 
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import call from '@ohos.telephony.call';
```

## call.dial

dial\(phoneNumber: string, callback: AsyncCallback<boolean\>\): void

拨打电话。使用callback异步回调。

**需要权限**：ohos.permission.PLACE\_CALL，该权限为系统权限

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                         | 必填 | 说明                                    |
| ----------- | ---------------------------- | ---- | --------------------------------------- |
| phoneNumber | string                       | 是   | 电话号码。                              |
| callback    | AsyncCallback&lt;boolean&gt; | 是   | 回调函数，返回true为成功，false为失败。 |

**示例：**

```js
call.dial("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.dial

dial\(phoneNumber: string, options: DialOptions, callback: AsyncCallback<boolean\>\): void

拨打电话，可设置通话参数。使用callback异步回调。

**需要权限**：ohos.permission.PLACE\_CALL，该权限为系统权限

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                         | 必填 | 说明                                    |
| ----------- | ---------------------------- | ---- | --------------------------------------- |
| phoneNumber | string                       | 是   | 电话号码。                              |
| options     | [DialOptions](#dialoptions)  | 是   | 通话参数，选择为语音通话还是视频通话。  |
| callback    | AsyncCallback&lt;boolean&gt; | 是   | 回调函数，返回true为成功，false为失败。 |

**示例：**

```js
call.dial("138xxxxxxxx", {
    extras: false
}, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.dial

dial\(phoneNumber: string, options?: DialOptions\): Promise<boolean\>

拨打电话，可设置通话参数。使用Promise异步回调。

**需要权限**：ohos.permission.PLACE\_CALL，该权限为系统权限

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                        | 必填 | 说明                                   |
| ----------- | --------------------------- | ---- | -------------------------------------- |
| phoneNumber | string                      | 是   | 电话号码。                             |
| options     | [DialOptions](#dialoptions) | 否   | 通话参数，选择为语音通话还是视频通话。 |

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | 以Promise形式返回拨打电话的结果，返回true为成功，false为失败。 |

**示例：**

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

跳转到拨号界面，并显示待拨出的号码。使用callback异步回调。

**系统能力**：SystemCapability.Applications.Contacts

**参数：**

| 参数名      | 类型                      | 必填 | 说明                                       |
| ----------- | ------------------------- | ---- | ------------------------------------------ |
| phoneNumber | string                    | 是   | 电话号码。                                 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 以callback形式异步返回跳转拨号界面的结果。 |

**示例：**

```js
call.makeCall("138xxxxxxxx", err => { 
    console.log(`makeCall callback: err->${JSON.stringify(err)}`); 
});
```


## call.makeCall<sup>7+</sup>

makeCall(phoneNumber: string): Promise\<void\>

跳转到拨号界面，并显示待拨出的号码。使用Promise异步回调。

**系统能力**：SystemCapability.Applications.Contacts

**参数：**

| 参数名      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| phoneNumber | string | 是   | 电话号码。 |

**返回值：**

| 类型                | 说明                              |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回拨号的结果。 |

**示例：**

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

判断是否存在通话。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                         |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示当前存在通话，false表示当前不存在通话。 |

**示例：**

```js
call.hasCall((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.hasCall

hasCall\(\): Promise<boolean\>

判断是否存在通话。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                   | 说明                                    |
| ---------------------- | --------------------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式异步返回判断是否存在通话。 |

**示例：**

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

获取当前通话状态。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                 |
| -------- | -------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback&lt;[CallState](#callstate)&gt; | 是   | 回调函数，异步返回获取到的通话状态。 |

**示例：**

```js
call.getCallState((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.getCallState

getCallState\(\): Promise<CallState\>

获取当前通话状态。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                                   | 说明                                    |
| -------------------------------------- | --------------------------------------- |
| Promise&lt;[CallState](#callstate)&gt; | 以Promise形式异步返回获取到的通话状态。 |

**示例：**

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

检查当前设备是否具备语音通话能力。

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示设备具备语音通话能力，返回false表示设备不具备语音通话能力。 |

```js
let result = call.hasVoiceCapability(); 
console.log(`hasVoiceCapability: ${JSON.stringify(result)}`);
```

## call.isEmergencyPhoneNumber<sup>7+</sup>

isEmergencyPhoneNumber\(phoneNumber: string, callback: AsyncCallback<boolean\>\): void

判断是否是紧急电话号码。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                         | 必填 | 说明                                                         |
| ----------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                       | 是   | 电话号码。                                                   |
| callback    | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示是紧急电话号码，返回false表示不是紧急电话号码。 |

**示例：**

```js
call.isEmergencyPhoneNumber("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.isEmergencyPhoneNumber<sup>7+</sup>

isEmergencyPhoneNumber\(phoneNumber: string, options: EmergencyNumberOptions, callback: AsyncCallback<boolean\>\): void

根据电话号码参数，判断是否是紧急电话号码。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                                               | 必填 | 说明                                                         |
| ----------- | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                                             | 是   | 电话号码。                                                   |
| options     | [EmergencyNumberOptions](#emergencynumberoptions7) | 是   | 电话号码参数。                                               |
| callback    | AsyncCallback&lt;boolean&gt;                       | 是   | 回调函数。返回true表示是紧急电话号码，返回false表示不是紧急电话号码。 |

**示例：**

```js
call.isEmergencyPhoneNumber("112", {slotId: 1}, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.isEmergencyPhoneNumber<sup>7+</sup>

isEmergencyPhoneNumber\(phoneNumber: string, options?: EmergencyNumberOptions\): Promise<boolean\>

根据电话号码参数，判断是否是紧急电话号码。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                                               | 必填 | 说明           |
| ----------- | -------------------------------------------------- | ---- | -------------- |
| phoneNumber | string                                             | 是   | 电话号码。     |
| options     | [EmergencyNumberOptions](#emergencynumberoptions7) | 否   | 电话号码参数。 |

**返回值：**

| 类型                   | 说明                                                |
| ---------------------- | --------------------------------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式异步返回判断是否是紧急电话号码的结果。 |

**示例：**

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

格式化电话号码。使用callback异步回调。

电话号码格式化后为标准数字字串，例如：“138 xxxx xxxx”、“0755 xxxx xxxx”。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                        | 必填 | 说明                                 |
| ----------- | --------------------------- | ---- | ------------------------------------ |
| phoneNumber | string                      | 是   | 电话号码。                           |
| callback    | AsyncCallback&lt;string&gt; | 是   | 回调函数，返回格式化电话号码的结果。 |

**示例：**

```js
call.formatPhoneNumber("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## call.formatPhoneNumber<sup>7+</sup>

formatPhoneNumber\(phoneNumber: string, options: NumberFormatOptions, callback: AsyncCallback<string\>\): void

格式化电话号码，可设置格式化参数。使用callback异步回调。

电话号码格式化后为标准数字字串，例如：“138 xxxx xxxx”、“0755 xxxx xxxx”。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                                         | 必填 | 说明                                 |
| ----------- | -------------------------------------------- | ---- | ------------------------------------ |
| phoneNumber | string                                       | 是   | 电话号码。                           |
| options     | [NumberFormatOptions](#numberformatoptions7) | 是   | 格式化参数，如国家码。               |
| callback    | AsyncCallback&lt;string&gt;                  | 是   | 回调函数，返回格式化电话号码的结果。 |

**示例：**

```js
call.formatPhoneNumber("138xxxxxxxx", {
    countryCode: "CN"
}, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.formatPhoneNumber<sup>7+</sup>

formatPhoneNumber\(phoneNumber: string, options?: NumberFormatOptions\): Promise<string\>

格式化电话号码，可设置格式化参数。使用Promise异步回调。

电话号码格式化后为标准数字字串，例如：“138 xxxx xxxx”、“0755 xxxx xxxx”。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                                         | 必填 | 说明                   |
| ----------- | -------------------------------------------- | ---- | ---------------------- |
| phoneNumber | string                                       | 是   | 电话号码。             |
| options     | [NumberFormatOptions](#numberformatoptions7) | 否   | 格式化参数，如国家码。 |

**返回值：**

| 类型                  | 说明                                        |
| --------------------- | ------------------------------------------- |
| Promise&lt;string&gt; | 以Promise形式异步返回格式化电话号码的结果。 |

**示例：**

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

将电话号码格式化为E.164表示形式。使用callback异步回调。

待格式化的电话号码需要与传入的国家码相匹配，如中国电话号码需要传入国家码CN，否则格式化后的电话号码为null。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                        | 必填 | 说明                                                  |
| ----------- | --------------------------- | ---- | ----------------------------------------------------- |
| phoneNumber | string                      | 是   | 电话号码。                                            |
| countryCode | string                      | 是   | 国家码，支持所有国家码，如：中国（CN）。              |
| callback    | AsyncCallback&lt;string&gt; | 是   | 回调函数，返回将电话号码格式化为E.164表示形式的结果。 |

**示例：**

```js
call.formatPhoneNumberToE164("138xxxxxxxx", "CN", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.formatPhoneNumberToE164<sup>7+</sup>

formatPhoneNumberToE164\(phoneNumber: string, countryCode: string\): Promise<string\>

将电话号码格式化为E.164表示形式。使用Promise异步回调。

待格式化的电话号码需要与传入的国家码相匹配，如中国电话号码需要传入国家码CN，否则格式化后的电话号码为null。

支持所有国家码。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型   | 必填 | 说明                                     |
| ----------- | ------ | ---- | ---------------------------------------- |
| phoneNumber | string | 是   | 电话号码。                               |
| countryCode | string | 是   | 国家码，支持所有国家码，如：中国（CN）。 |

**返回值：**

| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; | 以Promise形式异步返回将电话号码格式化为E.164表示形式的结果。 |

**示例：**

```js
let promise = call.formatPhoneNumberToE164("138xxxxxxxx", "CN");
promise.then(data => {
    console.log(`formatPhoneNumberToE164 success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`formatPhoneNumberToE164 fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.muteRinger<sup>8+</sup>

muteRinger\(callback: AsyncCallback<void\>\): void

如果来电铃声响起，设备将停止铃声。否则，此方法不起作用。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                      | 必填 | 说明       |
| ----------- | ------------------------- | ---- | ---------- |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
call.muteRinger((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.muteRinger<sup>8+</sup>

muteRinger\(\): Promise<void\>

如果来电铃声响起，设备将停止铃声。否则，此方法不起作用。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

```js
let promise = call.muteRinger();
promise.then(data => {
    console.log(`muteRinger success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`muteRinger fail, promise: err->${JSON.stringify(err)}`);
});
```


## call.answer<sup>7+</sup>

answer\(callId: number, callback: AsyncCallback<void\>\): void

接听来电。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                            |
| -------- | ------------------------- | ---- | ----------------------------------------------- |
| callId   | number                    | 是   | 呼叫Id。可以通过订阅callDetailsChange事件获得。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                      |

**示例：**

```js
call.answer(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.answer<sup>7+</sup>

answer(callId?: number\): Promise<void\>

接听来电。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| callId | number | 否   | 呼叫Id。可以通过订阅callDetailsChange事件获得。从API Version 9开始为可选参数。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

```js
let promise = call.answer(1);
promise.then(data => {
    console.log(`answer success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`answer fail, promise: err->${JSON.stringify(err)}`);
});
```


## call.hangup<sup>7+</sup>

hangup\(callId: number, callback: AsyncCallback<void\>\): void

挂断电话。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                            |
| -------- | ------------------------- | ---- | ----------------------------------------------- |
| callId   | number                    | 是   | 呼叫id。可以通过订阅callDetailsChange事件获得。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                      |

**示例：**

```js
call.hangup(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.answer<sup>9+</sup>

answer\(callback: AsyncCallback<void\>\): void

接听来电。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
call.answer((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.hangup<sup>7+</sup>

hangup\(callId?: number\): Promise<void\>

挂断电话。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| callId | number | 否   | 呼叫id。可以通过订阅callDetailsChange事件获得。从API Version 9开始为可选参数。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

```js
let promise = call.hangup(1);
promise.then(data => {
    console.log(`hangup success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`hangup fail, promise: err->${JSON.stringify(err)}`);
});
```


## call.hangup<sup>9+</sup>

hangup\(callback: AsyncCallback<void\>\): void

挂断电话。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
call.hangup((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.reject<sup>7+</sup>

reject(callId: number, callback: AsyncCallback\<void>): void

拒绝来电。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                            |
| -------- | ------------------------- | ---- | ----------------------------------------------- |
| callId   | number                    | 是   | 呼叫Id。可以通过订阅callDetailsChange事件获得。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                      |

**示例：**

```js
call.reject(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.reject<sup>7+</sup>

reject\(callId: number, options: RejectMessageOptions, callback: AsyncCallback<void\>\): void

拒绝来电。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                                            |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| callId   | number                                         | 是   | 呼叫Id。可以通过订阅callDetailsChange事件获得。 |
| options  | [RejectMessageOptions](#rejectmessageoptions7) | 是   | 拒绝消息选项。                                  |
| callback | AsyncCallback&lt;void&gt;                      | 是   | 回调函数。                                      |

**示例：**

```js
let rejectMessageOptions={
    messageContent: "拦截陌生号码"
}
call.reject(1, rejectMessageOptions, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.reject<sup>7+</sup>

reject(callId?: number, options?: RejectMessageOptions\): Promise<void\>

拒绝来电。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名  | 类型                                           | 必填 | 说明                                                         |
| ------- | ---------------------------------------------- | ---- | ------------------------------------------------------------ |
| callId  | number                                         | 否   | 呼叫Id。可以通过订阅callDetailsChange事件获得。从API Version 9开始为可选参数。 |
| options | [RejectMessageOptions](#rejectmessageoptions7) | 否   | 拒绝消息选项。                                               |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

```js
let rejectMessageOptions={
    messageContent: "拦截陌生号码"
}
let promise = call.reject(1, rejectMessageOptions);
promise.then(data => {
    console.log(`reject success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`reject fail, promise: err->${JSON.stringify(err)}`);
});
```


## call.reject<sup>9+</sup>

reject\(callback: AsyncCallback<void\>\): void

拒绝来电。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
call.reject((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.reject<sup>9+</sup>

reject\(options: RejectMessageOptions, callback: AsyncCallback<void\>\): void

拒绝来电。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                           | 必填 | 说明           |
| -------- | ---------------------------------------------- | ---- | -------------- |
| options  | [RejectMessageOptions](#rejectmessageoptions7) | 是   | 拒绝消息选项。 |
| callback | AsyncCallback&lt;void&gt;                      | 是   | 回调函数。     |

**示例：**

```js
let rejectMessageOptions={
    messageContent: "拦截陌生号码"
}
call.reject(rejectMessageOptions, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.holdCall<sup>7+</sup>

holdCall\(callId: number, callback: AsyncCallback<void\>\): void

保持通话。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | 是   | 呼叫Id。   |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
call.holdCall(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.holdCall<sup>7+</sup>

holdCall\(callId: number\): Promise<void\>

保持通话。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| callId | number | 是   | 呼叫Id。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

取消保持通话。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | 是   | 呼叫Id。   |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
call.unHoldCall(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.unHoldCall<sup>7+</sup>

unHoldCall\(callId: number\): Promise<void\>

取消保持通话。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| callId | number | 是   | 呼叫Id。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

切换呼叫。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | 是   | 呼叫Id。   |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
call.switchCall(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.switchCall<sup>7+</sup>

switchCall\(callId: number\): Promise<void\>

切换呼叫。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| callId | number | 是   | 呼叫Id。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

合并通话，将两通电话合并成会议电话。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | 是   | 呼叫Id。   |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
call.combineConference(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.combineConference<sup>7+</sup>

combineConference\(callId: number\): Promise<void\>

合并通话，将两通电话合并成会议电话。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| callId | number | 是   | 呼叫Id。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

获取主呼叫Id。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                        | 必填 | 说明                     |
| -------- | --------------------------- | ---- | ------------------------ |
| callId   | number                      | 是   | 呼叫Id。                 |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。返回主呼叫Id。 |

**示例：**

```js
call.getMainCallId(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.getMainCallId<sup>7+</sup>

getMainCallId\(callId: number\): Promise<number\>

获取主呼叫Id。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| callId | number | 是   | 呼叫Id。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回主呼叫Id。 |

**示例：**

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

获取子呼叫Id列表。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                           | 必填 | 说明                         |
| -------- | ------------------------------ | ---- | ---------------------------- |
| callId   | number                         | 是   | 呼叫Id。                     |
| callback | AsyncCallback<Array<string\>\> | 是   | 回调函数。返回子呼叫Id列表。 |

**示例：**

```js
call.getSubCallIdList(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.getSubCallIdList<sup>7+</sup>

getSubCallIdList\(callId: number\): Promise<Array<string\>\>

获取子呼叫Id列表。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| callId | number | 是   | 呼叫Id。 |

**返回值：**

| 类型                          | 说明                                |
| ----------------------------- | ----------------------------------- |
| Promise&lt;Array<string\>&gt; | 以Promise形式异步返回子呼叫Id列表。 |

**示例：**

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

获取会议的呼叫Id列表。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                | 必填 | 说明                             |
| -------- | ----------------------------------- | ---- | -------------------------------- |
| callId   | number                              | 是   | 呼叫Id。                         |
| callback | AsyncCallback&lt;Array<string\>&gt; | 是   | 回调函数。返回会议的呼叫Id列表。 |

**示例：**

```js
call.getCallIdListForConference(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.getCallIdListForConference<sup>7+</sup>

getCallIdListForConference\(callId: number\): Promise<Array<string\>\>

获取会议的呼叫Id列表。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| callId | number | 是   | 呼叫Id。 |

**返回值：**

| 类型                          | 说明                                    |
| ----------------------------- | --------------------------------------- |
| Promise&lt;Array<string\>&gt; | 以Promise形式异步返回会议的呼叫Id列表。 |

**示例：**

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

获取呼叫等待状态。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                                                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                       |
| callback | AsyncCallback&lt;[CallWaitingStatus](#callwaitingstatus7)\> | 是   | 回调函数。<br/>返回呼叫等待状态。<br/>- 0：禁用呼叫等待 <br/>- 1：启用呼叫等待 |

**示例：**

```js
call.getCallWaitingStatus(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.getCallWaitingStatus<sup>7+</sup>

getCallWaitingStatus\(slotId: number\): Promise<CallWaitingStatus\>

获取呼叫等待状态。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                                                    | 说明                                                         |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[CallWaitingStatus](#callwaitingstatus7)&gt; | 以Promise形式异步返回呼叫等待状态。<br/>- 0：禁用呼叫等待 <br/>- 1：启用呼叫等待 |

**示例：**

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

设置呼叫等待。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number               | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                       |
| activate | boolean              | 是   | 呼叫等待是否处于启用状态。<br/>- false：禁用呼叫等待<br/>- true：启用呼叫等待 |
| callback | AsyncCallback<void\> | 是   | 回调函数。                                                   |

**示例：**

```js
call.setCallWaiting(0, true, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.setCallWaiting<sup>7+</sup>

setCallWaiting\(slotId: number, activate: boolean\): Promise<void\>

设置呼叫等待。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型    | 必填 | 说明                                                         |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| slotId   | number  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                       |
| activate | boolean | 是   | 呼叫等待是否处于启用状态。<br/>- false：禁用呼叫等待<br/>- true：启用呼叫等待 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

启动双音多频。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名    | 类型                 | 必填 | 说明       |
| --------- | -------------------- | ---- | ---------- |
| callId    | number               | 是   | 呼叫Id。   |
| character | string               | 是   | DTMF码。   |
| callback  | AsyncCallback<void\> | 是   | 回调函数。 |

**示例：**

```js
call.startDTMF(1, "0", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.startDTMF<sup>7+</sup>

startDTMF\(callId: number, character: string\): Promise<void\>

启动双音多频。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名    | 类型   | 必填 | 说明     |
| --------- | ------ | ---- | -------- |
| callId    | number | 是   | 呼叫Id。 |
| character | string | 是   | DTMF码。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回。 |

**示例：**

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

停止双音多频。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | 是   | 呼叫Id。   |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
call.stopDTMF(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.stopDTMF<sup>7+</sup>

stopDTMF\(callId: number\): Promise<void\>

停止双音多频。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| callId | number | 是   | 呼叫Id。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

判断是否正在处于紧急呼叫。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                         | 必填 | 说明       |
| -------- | ---------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。 |

**示例：**

```js
call.isInEmergencyCall((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.isInEmergencyCall<sup>7+</sup>

isInEmergencyCall\(\): Promise<boolean\>

判断是否正在处于紧急呼叫。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                   | 说明                        |
| ---------------------- | --------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

订阅callDetailsChange事件。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                       |
| -------- | ------------------------------------------------------- | ---- | -------------------------- |
| type     | string                                                  | 是   | 通话时监听通话详情的变化。 |
| callback | Callback<[CallAttributeOptions](#callattributeoptions7)> | 是   | 回调函数。                 |

**示例：**

```js
call.on('callDetailsChange', data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('callEventChange')<sup>8+</sup>

on\(type: 'callEventChange', callback: Callback<CallEventOptions\>\): void

订阅callEventChange事件。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                             | 必填 | 说明                       |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| type     | string                                           | 是   | 通话时监听通话事件的变化。 |
| callback | Callback<[CallEventOptions](#calleventoptions8)> | 是   | 回调函数。                 |

**示例：**

```js
call.on('callEventChange', data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('callDisconnectedCause')<sup>8+</sup>

on\(type: 'callDisconnectedCause', callback: Callback<DisconnectedDetails\>): void

订阅callDisconnectedCause事件。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明                       |
| -------- | ------------------------------------------------------ | ---- | -------------------------- |
| type     | string                                                 | 是   | 通话时监听断开连接的原因。 |
| callback | Callback<[DisconnectedDetails](#disconnecteddetails9)> | 是   | 回调函数。                 |

**示例：**

```js
call.on('callDisconnectedCause', data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('mmiCodeResult')<sup>9+</sup>

on\(type: 'mmiCodeResult', callback: Callback<MmiCodeResults\>\): void

订阅mmiCodeResult事件。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                  |
| -------- | -------------------------------------------- | ---- | --------------------- |
| type     | string                                       | 是   | 通话时监听MMI码结果。 |
| callback | Callback<[MmiCodeResults](#mmicoderesults9)> | 是   | 回调函数。            |

**示例：**

```js
call.on('mmiCodeResult', data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('callDetailsChange')<sup>7+</sup>

off\(type: 'callDetailsChange', callback?: Callback<CallAttributeOptions\>\): void

取消订阅callDetailsChange事件。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                     | 必填 | 说明                               |
| -------- | -------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                   | 是   | 通话结束时取消监听通话详情的变化。 |
| callback | Callback<[CallAttributeOptions](#callattributeoptions7)> | 否   | 回调函数。                         |

**示例：**

```js
call.off('callDetailsChange', data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('callEventChange')<sup>8+</sup>

off\(type: 'callEventChange', callback?: Callback<CallEventOptions\>\): void

取消订阅callEventChange事件。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                             | 必填 | 说明                               |
| -------- | ------------------------------------------------ | ---- | ---------------------------------- |
| type     | string                                           | 是   | 通话结束时取消监听通话事件的变化。 |
| callback | Callback<[CallEventOptions](#calleventoptions8)> | 否   | 回调函数。                         |

**示例：**

```js
call.off('callEventChange', data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('callDisconnectedCause')<sup>8+</sup>

off\(type: 'callDisconnectedCause', callback?: Callback<DisconnectedDetails\>\): void

取消订阅callDisconnectedCause事件。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                       | 必填 | 说明                 |
| -------- | ---------------------------------------------------------- | ---- | -------------------- |
| type     | 'callDisconnectedCause'                                    | 是   | 调用断开连接的原因。 |
| callback | Callback**<**[DisconnectedDetails](#disconnecteddetails9)> | 否   | 回调函数。           |

**示例：**

```js
call.off('callDisconnectedCause', data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('mmiCodeResult')<sup>9+</sup>

off\(type: 'mmiCodeResult', callback?: Callback<MmiCodeResults\>\): void

取消订阅mmiCodeResult事件。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                             | 必填 | 说明        |
| -------- | ------------------------------------------------ | ---- | ----------- |
| type     | 'mmiCodeResult'                                  | 是   | MMI码结果。 |
| callback | Callback<[MmiCodeResults](#mmicoderesults9)> | 否   | 回调函数。  |

**示例：**

```js
call.off('mmiCodeResult', data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.isNewCallAllowed<sup>8+</sup>

isNewCallAllowed\(callback: AsyncCallback<boolean\>\): void

判断是否允许再拨打一通新电话。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                         | 必填 | 说明       |
| -------- | ---------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。 |

**示例：**

```js
call.isNewCallAllowed((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.isNewCallAllowed<sup>8+</sup>

isNewCallAllowed\(\): Promise<boolean\>

判断是否允许再拨打一通新电话。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                   | 说明                        |
| ---------------------- | --------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

分离会议电话。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | 是   | 呼叫Id。   |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
call.separateConference(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.separateConference<sup>8+</sup>

separateConference\(callId: number\): Promise<void\>

分离会议电话。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| callId | number | 是   | 呼叫Id。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

获取呼叫限制状态。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| type     | [CallRestrictionType](#callrestrictiontype8)                 | 是   | 呼叫限制类型。                        |
| callback | AsyncCallback&lt;[RestrictionStatus](#restrictionstatus8)&gt; | 是   | 回调函数。返回限制状态。               |

**示例：**

```js
call.getCallRestrictionStatus(0, 1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.getCallRestrictionStatus<sup>8+</sup>

getCallRestrictionStatus\(slotId: number, type: CallRestrictionType\): Promise<RestrictionStatus\>

获取呼叫限制状态。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型                                         | 必填 | 说明                                   |
| ------ | -------------------------------------------- | ---- | -------------------------------------- |
| slotId | number                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| type   | [CallRestrictionType](#callrestrictiontype8) | 是   | 呼叫限制类型。                        |

**返回值：**

| 类型                                                    | 说明                        |
| ------------------------------------------------------- | --------------------------- |
| Promise&lt;[RestrictionStatus](#restrictionstatus8)&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

设置呼叫限制状态。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                   |
| -------- | ------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| info     | [CallRestrictionInfo](#callrestrictioninfo8) | 是   | 呼叫限制信息。                         |
| callback | AsyncCallback&lt;void&gt;                   | 是   | 回调函数。                             |

**示例：**

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

设置呼叫限制状态。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型                                         | 必填 | 说明                                   |
| ------ | -------------------------------------------- | ---- | -------------------------------------- |
| slotId | number                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| info   | [CallRestrictionInfo](#callrestrictioninfo8) | 是   | 呼叫限制信息。                         |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

获取呼叫转移信息。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| type     | [CallTransferType](#calltransfertype8)                       | 是   | 呼叫转移类型。                         |
| callback | AsyncCallback&lt;[CallTransferResult](#calltransferresult8)&gt; | 是   | 回调函数。返回呼叫转移信息。           |

**示例：**

```js
call.getCallTransferInfo(0, call.CallTransferType.TRANSFER_TYPE_BUSY, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.getCallTransferInfo<sup>8+</sup>

getCallTransferInfo\(slotId: number, type: CallTransferType): Promise<CallTransferResult\>

获取呼叫转移信息。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型                                   | 必填 | 说明                                   |
| ------ | -------------------------------------- | ---- | -------------------------------------- |
| slotId | number                                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| type   | [CallTransferType](#calltransfertype8) | 是   | 呼叫转移类型。                         |

**返回值：**

| 类型                                                      | 说明                        |
| --------------------------------------------------------- | --------------------------- |
| Promise&lt;[CallTransferResult](#calltransferresult8)&gt; | 以Promise形式异步返回结果。 |

**示例：**

```js
let promise = call.getCallTransferInfo(0, call.CallTransferType.TRANSFER_TYPE_BUSY);
promise.then(data => {
    console.log(`getCallTransferInfo success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`getCallTransferInfo fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.setCallTransfer<sup>8+</sup>

setCallTransfer\(slotId: number, info: CallTransferInfo, callback: AsyncCallback<void\>\): void

设置呼叫转移信息。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                   |
| -------- | ------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| info     | [CallTransferInfo](#calltransferinfo8) | 是   | 呼叫转移信息。                        |
| callback | AsyncCallback&lt;void&gt;             | 是   | 回调函数。                             |

**示例：**

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

设置呼叫转移信息。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型                                  | 必填 | 说明                                   |
| ------ | ------------------------------------- | ---- | -------------------------------------- |
| slotId | number                                | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| info   | [CallTransferInfo](#calltransferinfo8) | 是   | 呼叫转移信息。                        |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

判断是否正在响铃。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                         | 必填 | 说明       |
| -------- | ---------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。 |

**示例：**

```js
call.isRinging((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.isRinging<sup>8+</sup>

isRinging\(\): Promise<boolean\>

判断是否正在响铃。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                   | 说明                        |
| ---------------------- | --------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

设置通话中的静音。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
call.setMuted((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.setMuted<sup>8+</sup>

setMuted\(\): Promise<void\>

设置通话中的静音。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

取消通话中的静音。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
call.cancelMuted((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.cancelMuted<sup>8+</sup>

cancelMuted(): Promise<void\>

取消通话中的静音。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

设置通话音频设备。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                         | 必填 | 说明       |
| -------- | ---------------------------- | ---- | ---------- |
| device   | [AudioDevice](#audiodevice8) | 是   | 音频设备。 |
| callback | AsyncCallback&lt;void&gt;    | 是   | 回调函数。 |

**示例：**

```js
call.setAudioDevice(1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.setAudioDevice<sup>9+</sup>

setAudioDevice\(device: AudioDevice, options: AudioDeviceOptions, callback: AsyncCallback<void\>\): void

设置通话音频设备。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明           |
| -------- | ------------------------------------------ | ---- | -------------- |
| device   | [AudioDevice](#audiodevice8)               | 是   | 音频设备。     |
| options  | [AudioDeviceOptions](#audiodeviceoptions9) | 是   | 音频设备参数。 |
| callback | AsyncCallback&lt;void&gt;                  | 是   | 回调函数。     |

**示例：**

```js
let audioDeviceOptions={
    bluetoothAddress: "IEEE 802-2014"
}
call.setAudioDevice(1, audioDeviceOptions, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.setAudioDevice<sup>9+</sup>

setAudioDevice(device: AudioDevice, options?: AudioDeviceOptions): Promise<void\>

设置通话音频设备。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名  | 类型                                       | 必填 | 说明               |
| ------- | ------------------------------------------ | ---- | ------------------ |
| device  | [AudioDevice](#audiodevice8)               | 是   | 音频设备。         |
| options | [AudioDeviceOptions](#audiodeviceoptions9) | 否   | 音频设备参数参数。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回设置结果。 |

**示例：**

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

加入会议。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名         | 类型                      | 必填 | 说明            |
| -------------- | ------------------------- | ---- | --------------- |
| mainCallId     | number                    | 是   | 主通话Id。      |
| callNumberList | Array<string\>            | 是   | 呼叫号码列表。 |
| callback       | AsyncCallback&lt;void&gt; | 是   | 回调函数。      |

**示例：**

```js
let callNumberList: Array<string> = [
    "138XXXXXXXX"
];
call.joinConference(1, callNumberList, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## call.joinConference<sup>8+</sup>

joinConference(mainCallId: number, callNumberList: Array<string\>): Promise<void\>

加入会议。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名         | 类型           | 必填 | 说明            |
| -------------- | -------------- | ---- | --------------- |
| mainCallId     | number         | 是   | 主通话Id。      |
| callNumberList | Array<string\> | 是   | 呼叫号码列表。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

```js
let callNumberList: Array<string> = [
    "138XXXXXXXX"
];
let promise = call.joinConference(1, callNumberList);
promise.then(data => {
    console.log(`joinConference success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`joinConference fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.updateImsCallMode<sup>8+</sup>

updateImsCallMode(callId: number, mode: ImsCallMode, callback: AsyncCallback<void\>): void

更新Ims呼叫模式。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                         | 必填 | 说明           |
| -------- | ---------------------------- | ---- | -------------- |
| callId   | number                       | 是   | 呼叫Id。       |
| mode     | [ImsCallMode](#imscallmode8) | 是   | Ims呼叫模式。 |
| callback | AsyncCallback&lt;void&gt;    | 是   | 回调函数。     |

**示例：**

```js
call.updateImsCallMode(1, 1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## call.updateImsCallMode<sup>8+</sup>

updateImsCallMode(callId: number, mode: ImsCallMode): Promise<void\>

更新Ims呼叫模式。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型                         | 必填 | 说明           |
| ------ | ---------------------------- | ---- | -------------- |
| callId | number                       | 是   | 呼叫Id。       |
| mode   | [ImsCallMode](#imscallmode8) | 是   | Ims呼叫模式。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

启用Ims开关。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                   |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                             |

**示例：**

```js
call.enableImsSwitch(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## call.enableImsSwitch<sup>8+</sup>

enableImsSwitch(slotId: number): Promise<void\>

启用Ims开关。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

禁用Ims开关。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                   |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                             |

**示例：**

```js
call.disableImsSwitch(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## call.disableImsSwitch<sup>8+</sup>

disableImsSwitch(slotId: number): Promise<void\>

禁用Ims开关。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

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

判断Ims开关是否启用。使用callback异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                   |
| -------- | ---------------------------- | ---- | -------------------------------------- |
| slotId   | number                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。                             |

**示例：**

```js
call.isImsSwitchEnabled(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## call.isImsSwitchEnabled<sup>8+</sup>

isImsSwitchEnabled(slotId: number): Promise<boolean\>

判断Ims开关是否启用。使用Promise异步回调。

此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**示例：**

```js
let promise = call.isImsSwitchEnabled(0);
promise.then(data => {
    console.log(`isImsSwitchEnabled success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.error(`isImsSwitchEnabled fail, promise: err->${JSON.stringify(err)}`);
});
```

## DialOptions

拨打电话的可选参数。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

|        名称              | 类型                               | 必填 | 说明                                                         |
| ------------------------ | ---------------------------------- | ---- | ------------------------------------------------------------ |
| extras                   | boolean                            | 否   | 根据extras的值判断是否为视频通话，默认为语音通话。<br/>- true：视频通话。<br/>- false：语音通话。 |
| accountId <sup>8+</sup>  | number                             | 否   | 帐户Id。<br/>- 0：卡槽1<br/>- 1：卡槽2<br/>此接口为系统接口。                                   |
| videoState <sup>8+</sup> | [VideoStateType](#videostatetype7) | 否   | 视频状态类型。此接口为系统接口。                             |
| dialScene <sup>8+</sup>  | [DialScene](#dialscene8)           | 否   | 拨号场景。此接口为系统接口。                                 |
| dialType <sup>8+</sup>   | [DialType](#dialtype8)             | 否   | 拨号类型。此接口为系统接口。                                 |

## CallState

通话状态码。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称               | 值   | 说明                                                         |
| ------------------ | ---- | ------------------------------------------------------------ |
| CALL_STATE_UNKNOWN | -1   | 无效状态，当获取呼叫状态失败时返回。                         |
| CALL_STATE_IDLE    | 0    | 表示没有正在进行的呼叫。                                     |
| CALL_STATE_RINGING | 1    | 表示来电正在振铃或等待。                                     |
| CALL_STATE_OFFHOOK | 2    | 表示至少有一个呼叫处于拨号、通话中或呼叫保持状态，并且没有新的来电振铃或等待。 |

## EmergencyNumberOptions<sup>7+</sup>

判断是否是紧急电话号码的可选参数。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

|  名称  | 类型   | 必填 | 说明                                           |
| ------ | ------ | ---- | ---------------------------------------------- |
| slotId | number | 否   | 卡槽ID：<br/>- 卡槽1：`0`。<br/>- 卡槽2：`1`。 |

## NumberFormatOptions<sup>7+</sup>

格式化号码的可选参数。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

|    名称     | 类型   | 必填 | 说明                                                       |
| ----------- | ------ | ---- | ---------------------------------------------------------- |
| countryCode | string | 否   | 国家码，支持所有国家的国家码，如：CN（中国）。默认为：CN。 |

## ImsCallMode<sup>8+</sup>

IP多媒体系统调用模式。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称                   | 值   | 说明               |
| ---------------------- | ---- | ------------------ |
| CALL_MODE_AUDIO_ONLY   | 0    | 仅限音频呼叫       |
| CALL_MODE_SEND_ONLY    | 1    | 仅发送呼叫         |
| CALL_MODE_RECEIVE_ONLY | 2    | 仅接收呼叫         |
| CALL_MODE_SEND_RECEIVE | 3    | 允许发送和接收呼叫 |
| CALL_MODE_VIDEO_PAUSED | 4    | 暂停视频呼叫       |

## AudioDevice<sup>8+</sup>

音频设备。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称                 | 值   | 说明         |
| -------------------- | ---- | ------------ |
| DEVICE_EARPIECE      | 0    | 耳机设备     |
| DEVICE_SPEAKER       | 1    | 扬声器设备 |
| DEVICE_WIRED_HEADSET | 2    | 有线耳机设备 |
| DEVICE_BLUETOOTH_SCO | 3    | 蓝牙SCO设备  |
| DEVICE_MIC           | 4    | 麦克风设备 |

## CallRestrictionType<sup>8+</sup>

呼叫限制类型。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称                                          | 值   | 说明                       |
| --------------------------------------------- | ---- | -------------------------- |
| RESTRICTION_TYPE_ALL_INCOMING                 | 0    | 限制所有呼入               |
| RESTRICTION_TYPE_ALL_OUTGOING                 | 1    | 限制所有呼出               |
| RESTRICTION_TYPE_INTERNATIONAL                | 2    | 限制国际通话               |
| RESTRICTION_TYPE_INTERNATIONAL_EXCLUDING_HOME | 3    | 限制除归属国以外的国际通话 |
| RESTRICTION_TYPE_ROAMING_INCOMING             | 4    | 限制漫游呼入               |
| RESTRICTION_TYPE_ALL_CALLS                    | 5    | 限制所有通话               |
| RESTRICTION_TYPE_OUTGOING_SERVICES            | 6    | 限制传出业务               |
| RESTRICTION_TYPE_INCOMING_SERVICES            | 7    | 限制呼入业务               |

## CallTransferInfo<sup>8+</sup>

呼叫转移信息。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

|          名称            | 类型                                                 | 必填 | 说明             |
| ------------------------ | ---------------------------------------------------- | ---- | ---------------- |
| transferNum              | string                                               | 是   | 转移编号         |
| type                     | [CallTransferType](#calltransfertype8)               | 是   | 呼叫转移类型     |
| settingType              | [CallTransferSettingType](#calltransfersettingtype8) | 是   | 设置呼叫转移类型 |
| startHour<sup>9+</sup>   | number                                               | 否   | 开始时间的小时数 |
| startMinute<sup>9+</sup> | number                                               | 否   | 开始时间的分钟数 |
| endHour<sup>9+</sup>     | number                                               | 否   | 结束时间的分钟数 |
| endMinute<sup>9+</sup>   | number                                               | 否   | 结束时间的分钟数 |

## CallTransferType<sup>8+</sup>

呼叫转移类型。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ------------ |
| TRANSFER_TYPE_UNCONDITIONAL | 0    | 无条件转移   |
| TRANSFER_TYPE_BUSY          | 1    | 忙线转移     |
| TRANSFER_TYPE_NO_REPLY      | 2    | 无回复转移   |
| TRANSFER_TYPE_NOT_REACHABLE | 3    | 无法访问转移 |

## CallTransferSettingType<sup>8+</sup>

设置呼叫转移类型。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称                       | 值   | 说明         |
| -------------------------- | ---- | ------------ |
| CALL_TRANSFER_DISABLE      | 0    | 禁用呼叫转移 |
| CALL_TRANSFER_ENABLE       | 1    | 启用呼叫转移 |
| CALL_TRANSFER_REGISTRATION | 3    | 登记呼叫转移 |
| CALL_TRANSFER_ERASURE      | 4    | 消除呼叫转移 |

## CallAttributeOptions<sup>7+</sup>

调用属性选项。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

|      名称       | 类型                                     | 必填 | 说明           |
| --------------- | ---------------------------------------- | ---- | -------------- |
| accountNumber   | string                                   | 是   | 帐号号码       |
| speakerphoneOn  | boolean                                  | 是   | 扬声器接通电话 |
| accountId       | number                                   | 是   | 帐户Id         |
| videoState      | [VideoStateType](#videostatetype7)       | 是   | 视频状态类型   |
| startTime       | number                                   | 是   | 开始时间       |
| isEcc           | boolean                                  | 是   | 是否是Ecc      |
| callType        | [CallType](#calltype7)                   | 是   | 通话类型       |
| callId          | number                                   | 是   | 呼叫Id         |
| callState       | [DetailedCallState](#detailedcallstate7) | 是   | 详细呼叫状态   |
| conferenceState | [ConferenceState](#conferencestate7)     | 是   | 会议状态       |

## ConferenceState<sup>7+</sup>

会议状态。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称                         | 值   | 说明           |
| ---------------------------- | ---- | -------------- |
| TEL_CONFERENCE_IDLE          | 0    | 电话会议空闲   |
| TEL_CONFERENCE_ACTIVE        | 1    | 电话会议激活   |
| TEL_CONFERENCE_DISCONNECTING | 2    | 电话会议断开   |
| TEL_CONFERENCE_DISCONNECTED  | 3    | 电话会议已断开 |

## CallType<sup>7+</sup>

通话类型。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称          | 值   | 说明         |
| ------------- | ---- | ------------ |
| TYPE_CS       | 0    | CS通话       |
| TYPE_IMS      | 1    | IMS通话      |
| TYPE_OTT      | 2    | OTT通话      |
| TYPE_ERR_CALL | 3    | 其他类型通话 |

## VideoStateType<sup>7+</sup>

视频状态类型。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称       | 值   | 说明     |
| ---------- | ---- | -------- |
| TYPE_VOICE | 0    | 语音状态 |
| TYPE_VIDEO | 1    | 视频状态 |

## DetailedCallState<sup>7+</sup>

详细的呼叫状态。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称                      | 值   | 说明           |
| ------------------------- | ---- | -------------- |
| CALL_STATUS_ACTIVE        | 0    | 激活呼叫状态   |
| CALL_STATUS_HOLDING       | 1    | 保持呼叫状态   |
| CALL_STATUS_DIALING       | 2    | 呼叫状态拨号   |
| CALL_STATUS_ALERTING      | 3    | 电话报警状态   |
| CALL_STATUS_INCOMING      | 4    | 呼叫传入状态   |
| CALL_STATUS_WAITING       | 5    | 呼叫等待状态   |
| CALL_STATUS_DISCONNECTED  | 6    | 呼叫状态已断开 |
| CALL_STATUS_DISCONNECTING | 7    | 呼叫状态断开   |
| CALL_STATUS_IDLE          | 8    | 呼叫状态空闲   |

## CallRestrictionInfo<sup>8+</sup>

呼叫限制信息。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

|   名称   | 类型                                         | 必填 | 说明         |
| -------- | -------------------------------------------- | ---- | ------------ |
| type     | [CallRestrictionType](#callrestrictiontype8) | 是   | 呼叫限制类型 |
| password | string                                       | 是   | 密码         |
| mode     | [CallRestrictionMode](#callrestrictionmode8) | 是   | 呼叫限制模式 |

## CallRestrictionMode<sup>8+</sup>

呼叫限制模式。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称                          | 值   | 说明         |
| ----------------------------- | ---- | ------------ |
| RESTRICTION_MODE_DEACTIVATION | 0    | 限制模式停用 |
| RESTRICTION_MODE_ACTIVATION   | 1    | 限制模式激活 |

## CallEventOptions<sup>8+</sup>

呼叫事件的可选参数。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

|   名称  | 类型                                       | 必填 | 说明           |
| ------- | ------------------------------------------ | ---- | -------------- |
| eventId | [CallAbilityEventId](#callabilityeventid8) | 是   | 呼叫能力事件Id |

## CallAbilityEventId<sup>8+</sup>

呼叫能力事件Id。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称                     | 值   | 说明            |
| ------------------------ | ---- | --------------- |
| EVENT_DIAL_NO_CARRIER    | 1    | 拨号无载波事件  |
| EVENT_INVALID_FDN_NUMBER | 2    | 无效的FDN号事件 |

## DialScene<sup>8+</sup>

拨号场景。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称            | 值   | 说明         |
| --------------- | ---- | ------------ |
| CALL_NORMAL     | 0    | 呼叫正常     |
| CALL_PRIVILEGED | 1    | 呼叫特权     |
| CALL_EMERGENCY  | 2    | 拨打紧急电话 |

## DialType<sup>8+</sup>

拨号类型。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称                 | 值   | 说明             |
| -------------------- | ---- | ---------------- |
| DIAL_CARRIER_TYPE    | 0    | 载波拨号类型     |
| DIAL_VOICE_MAIL_TYPE | 1    | 语音邮件拨号类型 |
| DIAL_OTT_TYPE        | 2    | OTT拨号类型      |

## RejectMessageOptions<sup>7+</sup>

拒绝消息可选参数。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

|     名称       | 类型   | 必填 | 说明     |
| -------------- | ------ | ---- | -------- |
| messageContent | string | 是   | 消息内容 |

## CallTransferResult<sup>8+</sup>

呼叫转移结果。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

|          名称            |                 类型               | 必填 |       说明       |
| ------------------------ | ---------------------------------- | ---- | ---------------- |
| status                   | [TransferStatus](#transferstatus8) |  是  | 转移状态         |
| number                   | string                             |  是  | 号码             |
| startHour<sup>9+</sup>   | number                             |  是  | 开始时间的小时数 |
| startMinute<sup>9+</sup> | number                             |  是  | 开始时间的分钟数 |
| endHour<sup>9+</sup>     | number                             |  是  | 结束时间的分钟数 |
| endMinute<sup>9+</sup>   | number                             |  是  | 结束时间的分钟数 |

## CallWaitingStatus<sup>7+</sup>

呼叫等待状态。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称                 | 值   | 说明         |
| -------------------- | ---- | ------------ |
| CALL_WAITING_DISABLE | 0    | 禁用呼叫等待 |
| CALL_WAITING_ENABLE  | 1    | 启用呼叫等待 |

## RestrictionStatus<sup>8+</sup>

限制状态。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称                | 值   | 说明     |
| ------------------- | ---- | -------- |
| RESTRICTION_DISABLE | 0    | 禁用限制 |
| RESTRICTION_ENABLE  | 1    | 启用限制 |

## TransferStatus<sup>8+</sup>

转移状态。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称             | 值   | 说明     |
| ---------------- | ---- | -------- |
| TRANSFER_DISABLE | 0    | 禁用转移 |
| TRANSFER_ENABLE  | 1    | 启用转移 |

## DisconnectedDetails<sup>9+</sup>

通话结束原因。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称    |                    类型                    | 必填 | 说明            |
| ------- | ------------------------------------------ | ---- | --------------- |
| reason  | [DisconnectedReason](#disconnectedreason8) | 是   | 通话结束原因    |
| message | string                                     | 是   | 通话结束提示信息|

## DisconnectedReason<sup>8+</sup>

断开连接的详细信息。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

|                              名称                            | 值   |                  说明                   |
| ------------------------------------------------------------ | ---- | --------------------------------------- |
| UNASSIGNED_NUMBER                                            | 1    | 未分配的号码(空号)                      |
| NO_ROUTE_TO_DESTINATION                                      | 3    | 无至目的地的路由                        |
| CHANNEL_UNACCEPTABLE                                         | 6    | 不可接受的通路                          |
| OPERATOR_DETERMINED_BARRING                                  | 8    | 运营商闭锁                              |
| CALL_COMPLETED_ELSEWHERE<sup>9+</sup>                        | 13   | 呼叫在其他地方完成                      |
| NORMAL_CALL_CLEARING                                         | 16   | 清除正常呼叫                            |
| USER_BUSY                                                    | 17   | 用户忙                                  |
| NO_USER_RESPONDING                                           | 18   | 无用户响应                              |
| USER_ALERTING_NO_ANSWER                                      | 19   | 已有用户提醒，但无应答                  |
| CALL_REJECTED                                                | 21   | 呼叫拒绝                                |
| NUMBER_CHANGED                                               | 22   | 号码改变                                |
| CALL_REJECTED_DUE_TO_FEATURE_AT_THE_DESTINATION<sup>9+</sup> | 24   | 当由于目标地址（例如匿名）导致呼叫被拒绝 |
| FAILED_PRE_EMPTION<sup>9+</sup>                              | 25   | 抢占失败                                |
| NON_SELECTED_USER_CLEARING<sup>9+</sup>                      | 26   | 非选定用户清除                          |
| DESTINATION_OUT_OF_ORDER                                     | 27   | 终点故障                                |
| INVALID_NUMBER_FORMAT                                        | 28   | 无效号码格式                            |
| FACILITY_REJECTED<sup>9+</sup>                               | 29   | 增补业务拒绝                            |
| RESPONSE_TO_STATUS_ENQUIRY<sup>9+</sup>                      | 30   | 对状态查询的响应                        |
| NORMAL_UNSPECIFIED<sup>9+</sup>                              | 31   | 正常，未指定                            |
| NO_CIRCUIT_CHANNEL_AVAILABLE<sup>9+</sup>                    | 34   | 无电路/通道可用                         |
| NETWORK_OUT_OF_ORDER                                         | 38   | 网络故障                                |
| TEMPORARY_FAILURE                                            | 41   | 临时故障                                |
| SWITCHING_EQUIPMENT_CONGESTION<sup>9+</sup>                  | 42   | 交换设备拥塞                            |
| ACCESS_INFORMATION_DISCARDED<sup>9+</sup>                    | 43   | 已丢弃访问信息                          |
| REQUEST_CIRCUIT_CHANNEL_NOT_AVAILABLE<sup>9+</sup>           | 44   | 请求的电路/通道不可用                   |
| RESOURCES_UNAVAILABLE_UNSPECIFIED<sup>9+</sup>               | 47   | 未指定资源不可用                        |
| QUALITY_OF_SERVICE_UNAVAILABLE<sup>9+</sup>                  | 49   | 服务质量不可用                          |
| REQUESTED_FACILITY_NOT_SUBSCRIBED<sup>9+</sup>               | 50   | 请求的设施未订阅                        |
| INCOMING_CALLS_BARRED_WITHIN_THE_CUG<sup>9+</sup>            | 55   | CUG内禁止来电                           |
| BEARER_CAPABILITY_NOT_AUTHORIZED<sup>9+</sup>                | 57   | 未授权承载能力                          |
| BEARER_CAPABILITY_NOT_PRESENTLY_AVAILABLE<sup>9+</sup>       | 58   | 承载能力目前不可用                      |
| SERVICE_OR_OPTION_NOT_AVAILABLE_UNSPECIFIED<sup>9+</sup>     | 63   | 服务或选项不可用，未指定                |
| BEARER_SERVICE_NOT_IMPLEMENTED<sup>9+</sup>                  | 65   | 未实现承载服务                          |
| ACM_EQUALTO_OR_GREATER_THAN_THE_MAXIMUM_VALUE<sup>9+</sup>   | 68   | ACM大于或等于最大值                     |
| REQUESTED_FACILITY_NOT_IMPLEMENTED<sup>9+</sup>              | 69   | 请求的设施未实施                        |
| ONLY_RESTRICTED_DIGITAL_INFO_BEARER_CAPABILITY_IS_AVAILABLE<sup>9+</sup> | 70   | 仅限BC有限数字信息可用      |
| SERVICE_OR_OPTION_NOT_IMPLEMENTED_UNSPECIFIED<sup>9+</sup>   | 79   | 服务或选项未实施，未指定                |
| INVALID_TRANSACTION_IDENTIFIER_VALUE<sup>9+</sup>            | 81   | 无效的业务标识符值                      |
| USER_NOT_MEMBER_OF_CUG<sup>9+</sup>                          | 87   | 用户不是CUG成员                         |
| INCOMPATIBLE_DESTINATION<sup>9+</sup>                        | 88   | 目标不兼容                              |
| INVALID_TRANSIT_NETWORK_SELECTION<sup>9+</sup>               | 91   | 选择的传输网络无效                      |
| SEMANTICALLY_INCORRECT_MESSAGE<sup>9+</sup>                  | 95   | 语义错误的消息                          |
| INVALID_MANDATORY_INFORMATION<sup>9+</sup>                   | 96   | 无效的强制信息                          |
| MESSAGE_TYPE_NON_EXISTENT_OR_NOT_IMPLEMENTED<sup>9+</sup>    | 97   | 消息类型不存在或未实现                  |
| MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE<sup>9+</sup> | 98   | 消息类型与协议状态不兼容                |
| INFORMATION_ELEMENT_NON_EXISTENT_OR_NOT_IMPLEMENTED<sup>9+</sup>    | 99   | IE不存在或未实现                 |
| CONDITIONAL_IE_ERROR<sup>9+</sup>                            | 100  | 条件IE错误                              |
| MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE<sup>9+</sup>      | 101  | 消息与协议状态不兼容                    |
| RECOVERY_ON_TIMER_EXPIRED<sup>9+</sup>                       | 102  | 计时器过期时恢复计时器编号              |
| PROTOCOL_ERROR_UNSPECIFIED<sup>9+</sup>                      | 111  | 协议错误，未指定                        |
| INTERWORKING_UNSPECIFIED<sup>9+</sup>                        | 127  | 互通，未指定                            |
| CALL_BARRED<sup>9+</sup>                                     | 240  | 呼叫被禁止                              |
| FDN_BLOCKED<sup>9+</sup>                                     | 241  | FDN受阻                                 |
| IMSI_UNKNOWN_IN_VLR<sup>9+</sup>                             | 242  | VLR中的IMSI未知                         |
| IMEI_NOT_ACCEPTED<sup>9+</sup>                               | 243  | IMEI未被接受                            |
| DIAL_MODIFIED_TO_USSD<sup>9+</sup>                           | 244  | 拨号修改为USSD                          |
| DIAL_MODIFIED_TO_SS<sup>9+</sup>                             | 245  | 拨号修改为USSD号                        |
| DIAL_MODIFIED_TO_DIAL<sup>9+</sup>                           | 246  | 拨号已修改为正常                        |
| RADIO_OFF<sup>9+</sup>                                       | 247  | 无线电通讯已关闭                        |
| OUT_OF_SERVICE<sup>9+</sup>                                  | 248  | 停止服务                                |
| NO_VALID_SIM<sup>9+</sup>                                    | 249  | SIM卡无效                               |
| RADIO_INTERNAL_ERROR<sup>9+</sup>                            | 250  | 无线电通讯内部错误                      |
| NETWORK_RESP_TIMEOUT<sup>9+</sup>                            | 251  | 网络响应超时                            |
| NETWORK_REJECT<sup>9+</sup>                                  | 252  | 网络拒绝                                |
| RADIO_ACCESS_FAILURE<sup>9+</sup>                            | 253  | 无线电接入故障                          |
| RADIO_LINK_FAILURE<sup>9+</sup>                              | 254  | 无线电链路故障                          |
| RADIO_LINK_LOST<sup>9+</sup>                                 | 255  | 无线电链路丢失                          |
| RADIO_UPLINK_FAILURE<sup>9+</sup>                            | 256  | 无线电上行链路故障                      |
| RADIO_SETUP_FAILURE<sup>9+</sup>                             | 257  | 无线电通讯设置失败                      |
| RADIO_RELEASE_NORMAL<sup>9+</sup>                            | 258  | 无线电释放正常                          |
| RADIO_RELEASE_ABNORMAL<sup>9+</sup>                          | 259  | 无线电释放异常                          |
| ACCESS_CLASS_BLOCKED<sup>9+</sup>                            | 260  | 访问类被阻止                            |
| NETWORK_DETACH<sup>9+</sup>                                  | 261  | 网络分离                                |
| INVALID_PARAMETER                                            | 1025 | 无效参数                                |
| SIM_NOT_EXIT                                                 | 1026 | SIM卡未退出                             |
| SIM_PIN_NEED                                                 | 1027 | 需要SIM卡PIN码                          |
| CALL_NOT_ALLOW                                               | 1029 | 不允许呼叫                              |
| SIM_INVALID                                                  | 1045 | SIM卡无效                               |
| UNKNOWN                                                      | 1279 | 未知原因                                |

## MmiCodeResults<sup>9+</sup>

MMI码结果。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称    | 类型                             | 必填 | 说明            |
| ------- | -------------------------------- | ---- | --------------- |
| result  | [MmiCodeResult](#mmicoderesult9) | 是   | MMI码结果 |
| message | string                           | 是   | MMI码消息 |

## MmiCodeResult<sup>9+</sup>

MMI码结果。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称             | 值   | 说明          |
| ---------------- | ---- | ------------- |
| MMI_CODE_SUCCESS | 0    | 表示MMI码成功 |
| MMI_CODE_FAILED  | 1    | 表示MMI码失败 |

## AudioDeviceOptions<sup>9+</sup>

音频设备选项。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 名称             | 类型   | 必填 | 说明     |
| ---------------- | ------ | ---- | -------- |
| bluetoothAddress | string | 否   | 蓝牙地址 |

