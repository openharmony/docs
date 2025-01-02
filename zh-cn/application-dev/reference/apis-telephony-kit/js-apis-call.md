# @ohos.telephony.call (拨打电话)

该模块提供呼叫管理功能，包括拨打电话、跳转到拨号界面、获取通话状态、格式化电话号码等。

如需订阅通话状态请使用[`observer.on('callStateChange')`](js-apis-observer.md#observeroncallstatechange)。

>**说明：**
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { call } from '@kit.TelephonyKit';
```


## call.dial<sup>(deprecated)</sup>

dial\(phoneNumber: string, callback: AsyncCallback\<boolean\>\): void

拨打电话。使用callback异步回调。

> **说明：**
>
> 从API version 6 开始支持，从API version 9 开始废弃。替代接口能力仅对系统应用开放。

**需要权限**：ohos.permission.PLACE_CALL（该权限仅系统应用可申请）

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                         | 必填 | 说明                                    |
| ----------- | ---------------------------- | ---- | --------------------------------------- |
| phoneNumber | string                       | 是   | 电话号码。                              |
| callback    | AsyncCallback&lt;boolean&gt; | 是   | 回调函数，返回true为成功，false为失败。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.dial("138xxxxxxxx", (err: BusinessError, data: boolean) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## call.dial<sup>(deprecated)</sup>

dial\(phoneNumber: string, options: DialOptions, callback: AsyncCallback\<boolean\>\): void

拨打电话，可设置通话参数。使用callback异步回调。

> **说明：**
>
> 从API version 6 开始支持，从API version 9 开始废弃。替代接口能力仅对系统应用开放。

**需要权限**：ohos.permission.PLACE_CALL（该权限仅系统应用可申请）

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                         | 必填 | 说明                                    |
| ----------- | ---------------------------- | ---- | --------------------------------------- |
| phoneNumber | string                       | 是   | 电话号码。                              |
| options     | [DialOptions](#dialoptions)  | 是   | 通话参数，选择为语音通话还是视频通话。  |
| callback    | AsyncCallback&lt;boolean&gt; | 是   | 回调函数，返回true为成功，false为失败。 |

**示例：**

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

拨打电话，可设置通话参数。使用Promise异步回调。

> **说明：**
>
> 从API version 6 开始支持，从API version 9 开始废弃。替代接口能力仅对系统应用开放。

**需要权限**：ohos.permission.PLACE_CALL（该权限仅系统应用可申请）

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

跳转到拨号界面，并显示待拨出的号码。使用callback异步回调。只支持在UIAbility中调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Applications.Contacts

**参数：**

| 参数名      | 类型                      | 必填 | 说明                                       |
| ----------- | ------------------------- | ---- | ------------------------------------------ |
| phoneNumber | string                    | 是   | 电话号码。                                 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 以callback形式异步返回跳转拨号界面的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

跳转到拨号界面，并显示待拨出的号码。使用Promise异步回调。只支持在UIAbility中调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Applications.Contacts

**参数：**

| 参数名      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| phoneNumber | string | 是   | 电话号码。 |

**返回值：**

| 类型                | 说明                              |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回拨号的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.makeCall("138xxxxxxxx").then(() => {
    console.log(`makeCall success`);
}).catch((err: BusinessError) => {
    console.error(`makeCall fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.makeCall<sup>12+</sup>

makeCall\(context: Context, phoneNumber: string\): Promise\<void\>

跳转到拨号界面，并显示待拨出的号码。使用Promise异步回调。后台调用需要申请ohos.permission.START_ABILITIES_FROM_BACKGROUND权限

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Applications.Contacts

**参数：**

| 参数名      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| context | Context | 是   | 应用上下文Context |
| phoneNumber | string | 是   | 电话号码。 |

**返回值：**

| 类型                | 说明                              |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回拨号的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
// 获取context
let context = getContext(this) as Context;
call.makeCall(context, "138xxxxxxxx").then(() => {
    console.log(`makeCall success`);
}).catch((err: BusinessError) => {
    console.error(`makeCall fail, promise: err->${JSON.stringify(err)}`);
});
```

## call.hasCall

hasCall\(callback: AsyncCallback\<boolean\>\): void

判断是否存在通话。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                         |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示当前存在通话，false表示当前不存在通话。 |

**示例：**

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

判断是否存在通话。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                   | 说明                                    |
| ---------------------- | --------------------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式异步返回判断是否存在通话。返回true表示当前存在通话，false表示当前不存在通话。 |

**示例：**

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

判断是否存在通话。

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                   | 说明          |
| ---------------------- |-------------|
| boolean | 返回判断是否存在通话。返回true表示当前存在通话，false表示当前不存在通话。 |

**示例：**

```ts
let hasCall: boolean = call.hasCallSync();
console.log(`hasCallSync success, has call is ` + hasCall);
```


## call.getCallState

getCallState\(callback: AsyncCallback\<CallState\>\): void

获取当前通话状态。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                 |
| -------- | -------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback&lt;[CallState](#callstate)&gt; | 是   | 回调函数，异步返回获取到的通话状态。 |

**示例：**

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

获取当前通话状态。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                                   | 说明                                    |
| -------------------------------------- | --------------------------------------- |
| Promise&lt;[CallState](#callstate)&gt; | 以Promise形式异步返回获取到的通话状态。 |

**示例：**

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

获取当前通话状态。

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                                  | 说明          |
| ------------------------------------- |-------------|
| [CallState](#callstate) | 返回获取到的通话状态。 |

**示例：**

```ts
let callState: call.CallState = call.getCallStateSync();
console.log(`the call state is:` + callState);
```

## call.hasVoiceCapability<sup>7+</sup>

hasVoiceCapability\(\): boolean

检查当前设备是否具备语音通话能力。

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示设备具备语音通话能力，返回false表示设备不具备语音通话能力。 |

```ts
let result: boolean = call.hasVoiceCapability();
console.log(`hasVoiceCapability: ${JSON.stringify(result)}`);
```

## call.isEmergencyPhoneNumber<sup>7+</sup>

isEmergencyPhoneNumber\(phoneNumber: string, callback: AsyncCallback\<boolean\>\): void

判断是否是紧急电话号码。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                         | 必填 | 说明                                                         |
| ----------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                       | 是   | 电话号码。                                                   |
| callback    | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示是紧急电话号码，返回false表示不是紧急电话号码。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

根据电话号码参数，判断是否是紧急电话号码。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                                               | 必填 | 说明                                                         |
| ----------- | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| phoneNumber | string                                             | 是   | 电话号码。                                                   |
| options     | [EmergencyNumberOptions](#emergencynumberoptions7) | 是   | 电话号码参数。                                               |
| callback    | AsyncCallback&lt;boolean&gt;                       | 是   | 回调函数。返回true表示是紧急电话号码，返回false表示不是紧急电话号码。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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
| Promise&lt;boolean&gt; | 以Promise形式异步返回判断是否是紧急电话号码的结果。返回true表示是紧急电话号码，返回false表示不是紧急电话号码。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

格式化电话号码。使用callback异步回调。

电话号码格式化后为标准数字字串，例如：“138 xxxx xxxx”、“0755 xxxx xxxx”。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                        | 必填 | 说明                                 |
| ----------- | --------------------------- | ---- | ------------------------------------ |
| phoneNumber | string                      | 是   | 电话号码。                           |
| callback    | AsyncCallback&lt;string&gt; | 是   | 回调函数，返回格式化电话号码的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

格式化电话号码，可设置格式化参数。使用callback异步回调。

电话号码格式化后为标准数字字串，例如：“138 xxxx xxxx”、“0755 xxxx xxxx”。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                                         | 必填 | 说明                                 |
| ----------- | -------------------------------------------- | ---- | ------------------------------------ |
| phoneNumber | string                                       | 是   | 电话号码。                           |
| options     | [NumberFormatOptions](#numberformatoptions7) | 是   | 格式化参数，如国家码。               |
| callback    | AsyncCallback&lt;string&gt;                  | 是   | 回调函数，返回格式化电话号码的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

将电话号码格式化为E.164表示形式。使用callback异步回调。

待格式化的电话号码需要与传入的国家码相匹配，如中国电话号码需要传入国家码CN，否则格式化后的电话号码为null。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                        | 必填 | 说明                                                  |
| ----------- | --------------------------- | ---- | ----------------------------------------------------- |
| phoneNumber | string                      | 是   | 电话号码。                                            |
| countryCode | string                      | 是   | 国家码，支持所有国家码，如：中国（CN）。              |
| callback    | AsyncCallback&lt;string&gt; | 是   | 回调函数，返回将电话号码格式化为E.164表示形式的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.formatPhoneNumberToE164("138xxxxxxxx", "CN").then((data: string) => {
    console.log(`formatPhoneNumberToE164 success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`formatPhoneNumberToE164 fail, promise: err->${JSON.stringify(err)}`);
});
```

## DialOptions

拨打电话的可选参数。

**系统能力**：SystemCapability.Telephony.CallManager

|        名称              | 类型                               | 必填 | 说明                                                                                             |
| ------------------------ | ---------------------------------- | ---- | ----------------------------------------------------------------------------------------------- |
| extras                   | boolean                            | 否   | 根据extras的值判断是否为视频通话，默认为语音通话。<br/>- true：视频通话。<br/>- false：语音通话。   | 

## CallState

通话状态码。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称               | 值   | 说明                                                         |
| ------------------ | ---- | ------------------------------------------------------------ |
| CALL_STATE_UNKNOWN | -1   | 无效状态，当获取呼叫状态失败时返回。                         |
| CALL_STATE_IDLE    | 0    | 表示没有正在进行的呼叫。                                     |
| CALL_STATE_RINGING | 1    | 表示来电正在振铃或等待。                                     |
| CALL_STATE_OFFHOOK | 2    | 表示至少有一个呼叫处于拨号、通话中或呼叫保持状态，并且没有新的来电振铃或等待。 |
| CALL_STATE_ANSWERED<sup>11+</sup> | 3    | 表示来电已经接听。 |

## EmergencyNumberOptions<sup>7+</sup>

判断是否是紧急电话号码的可选参数。

**系统能力**：SystemCapability.Telephony.CallManager

|  名称  | 类型   | 必填 | 说明                                           |
| ------ | ------ | ---- | ---------------------------------------------- |
| slotId | number | 否   | 卡槽ID：<br/>- 卡槽1：`0`。<br/>- 卡槽2：`1`。 |

## NumberFormatOptions<sup>7+</sup>

格式化号码的可选参数。

**系统能力**：SystemCapability.Telephony.CallManager

|    名称     | 类型   | 必填 | 说明                                                       |
| ----------- | ------ | ---- | ---------------------------------------------------------- |
| countryCode | string | 否   | 国家码，支持所有国家的国家码，如：CN（中国）。默认为：CN。 |
