# 拨打电话

>**说明：** 
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import call from '@ohos.telephony.call';
```

## call.dial<a name=call.dial-callback1></a>

dial\(phoneNumber: string, callback: AsyncCallback<boolean\>\): void

拨打电话，使用callback方式作为异步方法。

**需要权限**：ohos.permission.PLACE\_CALL，该权限为系统权限

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数        | 类型                         | 必填 | 说明                                              |
| ----------- | ---------------------------- | ---- | ------------------------------------------------- |
| phoneNumber | string                       | 是   | 电话号码。                                        |
| callback    | AsyncCallback&lt;boolean&gt; | 是   | 回调函数：<br/>- true：成功。<br/>- false：失败。 |

**示例：**

```
call.dial("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.dial<a name=call.dial-callback2></a>

dial\(phoneNumber: string, options: DialOptions, callback: AsyncCallback<boolean\>\): void

拨打电话，可设置通话参数，使用callback方式作为异步方法。

**需要权限**：ohos.permission.PLACE\_CALL，该权限为系统权限

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数        | 类型                         | 必填 | 说明                                              |
| ----------- | ---------------------------- | ---- | ------------------------------------------------- |
| phoneNumber | string                       | 是   | 电话号码。                                        |
| options     | DialOptions                  | 是   | 通话参数，参考[DialOptions](#DialOptions)。       |
| callback    | AsyncCallback&lt;boolean&gt; | 是   | 回调函数：<br/>- true：成功。<br/>- false：失败。 |

**示例：**

```
call.dial("138xxxxxxxx", {
    extras: false
}, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.dial<a name=call.dial-promise></a>

dial\(phoneNumber: string, options?: DialOptions\): Promise<boolean\>

拨打电话，可设置通话参数，使用promise方式作为异步方法。

**需要权限**：ohos.permission.PLACE\_CALL，该权限为系统权限

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数        | 类型        | 必填 | 说明                                        |
| ----------- | ----------- | ---- | ------------------------------------------- |
| phoneNumber | string      | 是   | 电话号码。                                  |
| options     | DialOptions | 是   | 通话参数，参考[DialOptions](#DialOptions)。 |

**返回值：**

| 类型                   | 说明                              |
| ---------------------- | --------------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式返回拨打电话的结果。 |

**示例：**

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

跳转到拨号界面，并显示拨号的号码，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数        | 类型                      | 必填 | 说明                                       |
| ----------- | ------------------------- | ---- | ------------------------------------------ |
| phoneNumber | string                    | 是   | 电话号码。                                 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 以callback形式异步返回跳转拨号界面的结果。 |

**示例：**

```
call.makeCall("138xxxxxxxx", err => { 
    console.log(`makeCall callback: err->${JSON.stringify(err)}`); 
});
```


## call.makeCall<sup>7+</sup><a name=call.makeCall-promise></a>

makeCall(phoneNumber: string): Promise<void>

跳转到拨号界面，并显示拨号的号码，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数        | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| phoneNumber | string | 是   | 电话号码。 |

**返回值：**

| 类型                | 说明                              |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回拨号的结果。 |

**示例：**

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

判断是否存在通话，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数     | 类型                         | 必填 | 说明                                                         |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数：<br/>- true：当前存在通话。<br/>- false：当前不存在通话。 |

**示例：**

```
call.hasCall((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.hasCall<a name=call.hasCall-promise></a>

hasCall\(\): Promise<boolean\>

判断是否存在通话，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                   | 说明                                    |
| ---------------------- | --------------------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式异步返回判断是否存在通话。 |

**示例：**

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

获取通话状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数     | 类型                                         | 必填 | 说明                                 |
| -------- | -------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback&lt;[CallState](#CallState)&gt; | 是   | 回调函数：异步返回获取到的通话状态。 |

**示例：**

```
call.getCallState((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.getCallState<a name="call.getCallState-promise"></a>

getCallState\(\): Promise<CallState\>

获取通话状态，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                                   | 说明                                      |
| -------------------------------------- | ----------------------------------------- |
| Promise&lt;[CallState](#CallState)&gt; | 以Promise形式异步返回获取通话状态的结果。 |

**示例：**

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

检查当前设备是否具备语音通话能力，该方法是同步方法。

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | - true：设备具备语音通话能力<br/>- false：设备不具备语音通话能力 |

```
let result = call.hasVoiceCapability(); 
console.log(`hasVoiceCapability: ${JSON.stringify(result)}`);
```

## call.isEmergencyPhoneNumber<sup>7+</sup><a name=call.isEmergencyPhoneNumber-callback1></a>

isEmergencyPhoneNumber\(phoneNumber: string, callback: AsyncCallback<boolean\>\): void

判断是否是紧急电话号码，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数        | 类型                         | 必填 | 说明                                                         |
| ----------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                       | 是   | 电话号码。                                                   |
| callback    | AsyncCallback&lt;boolean&gt; | 是   | 回调函数，返回判断是否是紧急电话号码的结果：<br/>- true：是紧急电话号码。<br/>- false：不是紧急电话号码。 |

**示例：**

```
call.isEmergencyPhoneNumber("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.isEmergencyPhoneNumber<sup>7+</sup><a name=call.isEmergencyPhoneNumber-callback2></a>

isEmergencyPhoneNumber\(phoneNumber: string, options: EmergencyNumberOptions, callback: AsyncCallback<boolean\>\): void

判断是否是紧急电话号码，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数        | 类型                         | 必填 | 说明                                                         |
| ----------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                       | 是   | 电话号码。                                                   |
| options     | EmergencyNumberOptions       | 是   | 手机参数，参考[EmergencyNumberOptions](#EmergencyNumberOptions)。 |
| callback    | AsyncCallback&lt;boolean&gt; | 是   | 回调函数，返回判断是否是紧急电话号码的结果：<br/>- true：是紧急电话号码。<br/>- false：不是紧急电话号码。 |

**示例：**

```
call.isEmergencyPhoneNumber("112", {slotId: 1}, (err, value) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.isEmergencyPhoneNumber<sup>7+</sup><a name=call.isEmergencyPhoneNumber-promise></a>

isEmergencyPhoneNumber\(phoneNumber: string, options?: EmergencyNumberOptions\): Promise<boolean\>

判断是否是紧急电话号码，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数        | 类型                   | 必填 | 说明                                                         |
| ----------- | ---------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                 | 是   | 电话号码。                                                   |
| options     | EmergencyNumberOptions | 是   | 手机参数，参考[EmergencyNumberOptions](#EmergencyNumberOptions)。 |

**返回值：**

| 类型                   | 说明                                                |
| ---------------------- | --------------------------------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式异步返回判断是否是紧急电话号码的结果。 |

**示例：**

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

格式化电话号码，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数        | 类型                        | 必填 | 说明                                 |
| ----------- | --------------------------- | ---- | ------------------------------------ |
| phoneNumber | string                      | 是   | 电话号码。                           |
| callback    | AsyncCallback&lt;string&gt; | 是   | 回调函数，返回格式化电话号码的结果。 |

**示例：**

```
call.formatPhoneNumber("138xxxxxxxx", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.formatPhoneNumber<sup>7+</sup><a name=call.formatPhoneNumber-callback2></a>

formatPhoneNumber\(phoneNumber: string, options: NumberFormatOptions, callback: AsyncCallback<string\>\): void

格式化电话号码，可设置格式化参数，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数        | 类型                        | 必填 | 说明                                                         |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                      | 是   | 电话号码。                                                   |
| options     | NumberFormatOptions         | 是   | 格式化参数，参考[NumberFormatOptions](#NumberFormatOptions)。 |
| callback    | AsyncCallback&lt;string&gt; | 是   | 回调函数，返回格式化电话号码的结果。                         |

**示例：**

```
call.formatPhoneNumber("138xxxxxxxx",{
    countryCode: "CN"
}, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.formatPhoneNumber<sup>7+</sup><a name=call.formatPhoneNumber-promise></a>

formatPhoneNumber\(phoneNumber: string, options?: NumberFormatOptions\): Promise<string\>

格式化电话号码，可设置格式化参数，使用promise方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数        | 类型                | 必填 | 说明                                                         |
| ----------- | ------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string              | 是   | 电话号码。                                                   |
| options     | NumberFormatOptions | 是   | 格式化参数，参考[NumberFormatOptions](#NumberFormatOptions)。 |

**返回值：**

| 类型                  | 说明                                        |
| --------------------- | ------------------------------------------- |
| Promise&lt;string&gt; | 以Promise形式异步返回格式化电话号码的结果。 |

**示例：**

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

将电话号码格式化为E.164表示形式，使用callback方式作为异步方法。

需要格式化的电话号码需要与传入国家码相匹配，如中国手机号需要传入国家码CN，否则格式化后的手机号为null。

支持所有国家码。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数        | 类型                        | 必填 | 说明                                                  |
| ----------- | --------------------------- | ---- | ----------------------------------------------------- |
| phoneNumber | string                      | 是   | 电话号码。                                            |
| countryCode | string                      | 是   | 国家码，支持所有国家码，如：中国（CN）。              |
| callback    | AsyncCallback&lt;string&gt; | 是   | 回调函数，返回将电话号码格式化为E.164表示形式的结果。 |

**示例：**

```
call.formatPhoneNumberToE164("138xxxxxxxx",{
    countryCode: "CN"
}, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.formatPhoneNumberToE164<sup>7+</sup><a name=call.formatPhoneNumberToE164-promise></a>

formatPhoneNumberToE164\(phoneNumber: string, countryCode: string\): Promise<string\>

将电话号码格式化为E.164表示形式，使用promise方式作为异步方法。

需要格式化的手机号码需要与传入国家码相匹配，如中国手机号需要传入国家码CN，否则格式化后的手机号为null。

支持所有国家码。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数        | 类型   | 必填 | 说明                                     |
| ----------- | ------ | ---- | ---------------------------------------- |
| phoneNumber | string | 是   | 电话号码。                               |
| countryCode | string | 是   | 国家码，支持所有国家码，如：中国（CN）。 |

**返回值：**

| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; | 以Promise形式异步返回将电话号码格式化为E.164表示形式的结果。 |

**示例：**

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

拨打电话的可选参数。

**系统能力**：SystemCapability.Telephony.CallManager

| 参数   | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| extras | boolean | 否   | 根据extras的值判断是否为视频通话，默认为语音通话。<br/>- true：视频通话。<br/>- fasle：语音通话。 |

## CallState<a name=CallState></a>

通话状态码。

| 变量               | 值   | 说明                                                         |
| ------------------ | ---- | ------------------------------------------------------------ |
| CALL_STATE_UNKNOWN | -1   | 无效状态，当获取呼叫状态失败时返回。<br />**系统能力**：SystemCapability.Telephony.CallManager |
| CALL_STATE_IDLE    | 0    | 表示没有正在进行的呼叫。<br />**系统能力**：SystemCapability.Telephony.CallManager |
| CALL_STATE_RINGING | 1    | 表示来电正在振铃或等待。<br />**系统能力**：SystemCapability.Telephony.CallManager |
| CALL_STATE_OFFHOOK | 2    | 表示至少有一个呼叫处于拨号、通话中或呼叫保持状态，并且没有新的来电振铃或等待。<br />**系统能力**：SystemCapability.Telephony.CallManager |

## EmergencyNumberOptions<sup>7+</sup><a name=EmergencyNumberOptions></a>

判断是否是紧急电话号码的可选参数。

**系统能力**：SystemCapability.Telephony.CallManager

| 参数   | 类型   | 必填 | 说明                                       |
| ------ | ------ | ---- | ------------------------------------------ |
| slotId | number | 否   | 卡槽ID：<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

## NumberFormatOptions<sup>7+</sup><a name=NumberFormatOptions></a>

格式化号码的可选参数。

**系统能力**：SystemCapability.Telephony.CallManager

| 参数        | 类型   | 必填 | 说明                                                       |
| ----------- | ------ | ---- | ---------------------------------------------------------- |
| countryCode | string | 否   | 国家码，支持所有国家的国家码，如：中国（CN）。默认为：CN。 |