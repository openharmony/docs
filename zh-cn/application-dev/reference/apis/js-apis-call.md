# 拨打电话

call模块提供呼叫管理功能，包括拨打电话、跳转到拨号界面、获取通话状态、格式化电话号码等。

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
| options     | [DialOptions](#dialoptions) | 是   | 通话参数，选择为语音通话还是视频通话。 |

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
call.isEmergencyPhoneNumber("112", {slotId: 1}, (err, value) => {
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
| options     | [EmergencyNumberOptions](#emergencynumberoptions7) | 是   | 电话号码参数。 |

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
call.formatPhoneNumber("138xxxxxxxx",{
    countryCode: "CN"
}, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.formatPhoneNumber<sup>7+</sup>

formatPhoneNumber\(phoneNumber: string, options?: NumberFormatOptions\): Promise<string\>

格式化电话号码，可设置格式化参数。使用Promise异步回调。

电话号码格式化后为标准数字字串，例如：”138 xxxx xxxx“、”0755 xxxx xxxx“。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                                         | 必填 | 说明                   |
| ----------- | -------------------------------------------- | ---- | ---------------------- |
| phoneNumber | string                                       | 是   | 电话号码。             |
| options     | [NumberFormatOptions](#numberformatoptions7) | 是   | 格式化参数，如国家码。 |

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
call.formatPhoneNumberToE164("138xxxxxxxx",{
    countryCode: "CN"
}, (err, data) => {
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

拨打电话的可选参数。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| extras | boolean | 否   | 根据extras的值判断是否为视频通话，默认为语音通话。<br/>- true：视频通话。<br/>- false：语音通话。 |

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

| 参数名 | 类型   | 必填 | 说明                                           |
| ------ | ------ | ---- | ---------------------------------------------- |
| slotId | number | 否   | 卡槽ID：<br/>- 卡槽1为`0`。<br/>- 卡槽2为`1`。 |

## NumberFormatOptions<sup>7+</sup>

格式化号码的可选参数。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CallManager。

| 参数名      | 类型   | 必填 | 说明                                                       |
| ----------- | ------ | ---- | ---------------------------------------------------------- |
| countryCode | string | 否   | 国家码，支持所有国家的国家码，如：中国（CN）。默认为：CN。 |