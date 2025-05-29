# @ohos.telephony.call (拨打电话)(系统接口)

该模块提供呼叫管理功能，包括拨打电话、跳转到拨号界面、获取通话状态、格式化电话号码等。

如需订阅通话状态请使用[`observer.on('callStateChange')`](js-apis-observer.md#observeroncallstatechange)。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.telephony.call (拨打电话)](js-apis-call.md)。


## 导入模块

```ts
import { call } from '@kit.TelephonyKit';
```

## call.dialCall<sup>9+</sup>

dialCall\(phoneNumber: string, callback: AsyncCallback\<void\>\): void

拨打电话。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.PLACE_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                         | 必填 | 说明                                    |
| ----------- | ---------------------------- | ---- | -------------------------------------- |
| phoneNumber | string                       | 是   | 电话号码。                              |
| callback    | AsyncCallback&lt;void&gt;    | 是   | 以callback形式异步返回拨打电话的结果。   |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
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

**示例：**

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

拨打电话，可设置通话参数。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.PLACE_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      |                    类型             | 必填 | 说明                                 |
| ----------- | ----------------------------------- | ---- | ----------------------------------- |
| phoneNumber | string                              | 是   | 电话号码。                           |
| options     | [DialCallOptions](#dialcalloptions9)| 是   | 通话参数，携带呼叫的其他配置信息。    |
| callback    | AsyncCallback&lt;void&gt;           | 是   | 以callback形式异步返回拨打电话的结果。|

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let dialCallOptions: call.DialCallOptions = {
    accountId: 0,
    videoState: 0,
    dialScene: 0,
    dialType: 0,
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

拨打电话，可设置通话参数。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.PLACE_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      |                 类型                | 必填 |                说明                    |
| ----------- | ----------------------------------- | ---- | -------------------------------------- |
| phoneNumber | string                              | 是   | 电话号码。                             |
| options     | [DialCallOptions](#dialcalloptions9)| 否   | 通话参数，携带呼叫的其他配置信息。<br/>不填该参数则默认使用如下配置，参考[DialCallOptions](#dialcalloptions9)。<br/>- 帐户Id：卡槽1。 <br/>- 音视频类型：语音通话。 <br/>- 拨号场景：普通呼叫。 <br/>- 拨号类型：运营商通话。  |

**返回值：**

| 类型                   | 说明                          |
| ---------------------- | ---------------------------- |
| Promise&lt;void&gt;    | 以Promise形式异步返回拨号结果。|

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let dialCallOptions: call.DialCallOptions = {
    accountId: 0,
    videoState: 0,
    dialScene: 0,
    dialType: 0,
}
call.dialCall("138xxxxxxxx", dialCallOptions).then(() => {
    console.log(`dialCall success.`);
}).catch((err: BusinessError) => {
    console.error(`dialCall fail, promise: err->${JSON.stringify(err)}`);
});
```


## call.muteRinger<sup>8+</sup>

muteRinger\(callback: AsyncCallback\<void\>\): void

如果来电铃声响起，设备将停止铃声。否则，此方法不起作用。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                      | 必填 | 说明       |
| ----------- | ------------------------- | ---- | ---------- |
| callback    | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回停止铃声的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

如果来电铃声响起，设备将停止铃声。否则，此方法不起作用。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

接听来电。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                            |
| -------- | ------------------------- | ---- | ----------------------------------------------- |
| callId   | number                    | 是   | 呼叫Id。可以通过订阅callDetailsChange事件获得。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回接听电话的结果。            |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

接听来电。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| callId | number | 否   | 呼叫Id。可以通过订阅callDetailsChange事件获得。从API Version 9开始为可选参数。<br/>不填该参数则接通最近一通正在响铃的来电。|

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

接听来电。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回接听电话的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

挂断电话。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                            |
| -------- | ------------------------- | ---- | ----------------------------------------------- |
| callId   | number                    | 是   | 呼叫Id。可以通过订阅callDetailsChange事件获得。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回挂断电话的结果。            |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

挂断电话。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| callId | number | 否   | 呼叫Id。可以通过订阅callDetailsChange事件获得。从API Version 9开始为可选参数。</br>不填该参数则挂断最近一通正在进行/拨号/连接的通话。|

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

挂断电话。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回挂断电话的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |


**示例：**

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

拒绝来电。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                            |
| -------- | ------------------------- | ---- | ----------------------------------------------- |
| callId   | number                    | 是   | 呼叫Id。可以通过订阅callDetailsChange事件获得。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回拒接电话的结果。                           |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |


**示例：**

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

拒绝来电。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                                            |
| -------- | ---------------------------------------------- | ---- | ----------------------------------------------- |
| callId   | number                                         | 是   | 呼叫Id。可以通过订阅callDetailsChange事件获得。 |
| options  | [RejectMessageOptions](#rejectmessageoptions7) | 是   | 拒绝消息选项。                                  |
| callback | AsyncCallback&lt;void&gt;                      | 是   | 以回调函数的方式返回拒接电话的结果。            |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let rejectMessageOptions : call.RejectMessageOptions = {
    messageContent: "拦截陌生号码"
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

拒绝来电。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名  | 类型                                           | 必填 | 说明                                                         |
| ------- | ---------------------------------------------- | ---- | ------------------------------------------------------------ |
| callId  | number                                         | 否   | 呼叫Id。可以通过订阅callDetailsChange事件获得。从API Version 9开始为可选参数。<br/>不填该参数则拒接最近一通正在响铃的来电。|
| options | [RejectMessageOptions](#rejectmessageoptions7) | 否   | 拒绝消息选项。不填该参数则不会发送拒接短信。|

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let rejectMessageOptions: call.RejectMessageOptions = {
    messageContent: "拦截陌生号码"
}
call.rejectCall(1, rejectMessageOptions).then(() => {
    console.log(`rejectCall success.`);
}).catch((err: BusinessError) => {
    console.error(`rejectCall fail, promise: err->${JSON.stringify(err)}`);
});
```


## call.rejectCall<sup>9+</sup>

rejectCall\(callback: AsyncCallback\<void\>\): void

拒绝来电。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回拒接电话的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

拒绝来电。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                           | 必填 | 说明           |
| -------- | ---------------------------------------------- | ---- | -------------- |
| options  | [RejectMessageOptions](#rejectmessageoptions7) | 是   | 拒绝消息选项。 |
| callback | AsyncCallback&lt;void&gt;                      | 是   | 以回调函数的方式返回拒接电话的结果。     |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let rejectMessageOptions: call.RejectMessageOptions = {
    messageContent: "拦截陌生号码"
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

保持通话。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | 是   | 呼叫Id。   |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回保持电话的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

保持通话。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

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

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

取消保持通话。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | 是   | 呼叫Id。   |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回取消保持电话的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

取消保持通话。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

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

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

切换呼叫。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | 是   | 呼叫Id。   |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回交换电话的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

切换呼叫。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

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

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

合并通话，将两通电话合并成会议电话。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | 是   | 呼叫Id。   |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回合并会议的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300007  | The number of conference calls exceeds the limit. |

**示例：**

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

合并通话，将两通电话合并成会议电话。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| callId | number | 是   | 呼叫Id。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300007  | The number of conference calls exceeds the limit. |

**示例：**

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

移出电话会议，将指定通话从会议电话中挂断。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.PLACE_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | 是   | 呼叫Id。   |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回移出会议的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

移出电话会议，将指定通话从会议电话中挂断。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.PLACE_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| callId | number | 是   | 呼叫Id。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

获取主呼叫Id。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                        | 必填 | 说明                     |
| -------- | --------------------------- | ---- | ------------------------ |
| callId   | number                      | 是   | 呼叫Id。                 |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。返回主呼叫Id。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |


**示例：**

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

获取主呼叫Id。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| callId | number | 是   | 呼叫Id。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;number&gt; | 以Promise形式异步返回主呼叫Id。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |


**示例：**

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

获取子呼叫Id列表。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                           | 必填 | 说明                         |
| -------- | ------------------------------ | ---- | ---------------------------- |
| callId   | number                         | 是   | 呼叫Id。                     |
| callback | AsyncCallback<Array<string\>\> | 是   | 回调函数。返回子呼叫Id列表。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

获取子呼叫Id列表。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| callId | number | 是   | 呼叫Id。 |

**返回值：**

| 类型                          | 说明                                |
| ----------------------------- | ----------------------------------- |
| Promise&lt;Array<string\>&gt; | 以Promise形式异步返回子呼叫Id列表。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

获取会议的呼叫Id列表。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                | 必填 | 说明                             |
| -------- | ----------------------------------- | ---- | -------------------------------- |
| callId   | number                              | 是   | 呼叫Id。                         |
| callback | AsyncCallback&lt;Array<string\>&gt; | 是   | 回调函数。返回会议的呼叫Id列表。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

获取会议的呼叫Id列表。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| callId | number | 是   | 呼叫Id。 |

**返回值：**

| 类型                          | 说明                                    |
| ----------------------------- | --------------------------------------- |
| Promise&lt;Array<string\>&gt; | 以Promise形式异步返回会议的呼叫Id列表。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

获取呼叫等待状态。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                                                      | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。                       |
| callback | AsyncCallback&lt;[CallWaitingStatus](#callwaitingstatus7)\> | 是   | 回调函数。<br/>返回呼叫等待状态。<br/>- 0：禁用呼叫等待。 <br/>- 1：启用呼叫等待。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

获取呼叫等待状态。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型                                                    | 说明                                                         |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[CallWaitingStatus](#callwaitingstatus7)&gt; | 以Promise形式异步返回呼叫等待状态。<br/>- 0：禁用呼叫等待。 <br/>- 1：启用呼叫等待。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

设置呼叫等待。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number               | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。                       |
| activate | boolean              | 是   | 呼叫等待是否处于启用状态。<br/>- false：禁用呼叫等待。<br/>- true：启用呼叫等待。 |
| callback | AsyncCallback<void\> | 是   | 以回调函数的方式返回设置呼叫等待的结果。                     |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

设置呼叫等待。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型    | 必填 | 说明                                                         |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| slotId   | number  | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。                       |
| activate | boolean | 是   | 呼叫等待是否处于启用状态。<br/>- false：禁用呼叫等待。<br/>- true：启用呼叫等待。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

启动双音多频。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名    | 类型                 | 必填 | 说明       |
| --------- | -------------------- | ---- | ---------- |
| callId    | number               | 是   | 呼叫Id。   |
| character | string               | 是   | DTMF码。   |
| callback  | AsyncCallback<void\> | 是   | 以回调函数的方式返回启动双音多频的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

启动双音多频。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

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

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

停止双音多频。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | 是   | 呼叫Id。   |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回停止双音多频的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

停止双音多频。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| callId | number | 是   | 呼叫Id。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

继续进行通话。使用callback异步回调。

当用户呼叫号码为：“普通电话号码”+“;”+"DTMF字符"(例如：“400xxxxxxx;123”)，并且已经订阅了通话后延迟事件，
电话接通后，系统将上报通话后延迟事件，应用可以调用此接口选择是否发送DTMF音。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                           |
| -------- | ------------------------- | ---- | -------------------------------------------------------------- |
| callId   | number                    | 是   | 呼叫Id。                                                       |
| proceed  | boolean                   | 是   | 用户选择是否发送DTMF(Dual Tone Multi Frequency，双音多频)音。|
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回继续进行通话的结果。                    |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.postDialProceed(1, true, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## call.postDialProceed<sup>11+</sup>

postDialProceed\(callId: number, proceed: boolean\): Promise\<void\>

继续进行通话。使用Promise异步回调。

当用户呼叫号码为：“普通电话号码”+“;”+"DTMF字符"(例如：“400xxxxxxx;123”)，并且已经订阅了通话后延迟事件，
电话接通后，系统将上报通话后延迟事件，应用可以调用此接口选择是否发送DTMF音。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明                    |
| -------- | ------------------------- | ---- | ----------------------- |
| callId   | number                    | 是   | 呼叫Id。                |
| proceed  | boolean                   | 是   | 用户选择是否发送DTMF音。|

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

判断是否正在处于紧急呼叫。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                         | 必填 | 说明       |
| -------- | ---------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 以回调函数的方式返回结果。true表示紧急号码，false表示非紧急号码。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

判断是否正在处于紧急呼叫。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                   | 说明                        |
| ---------------------- | --------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式异步返回结果。true表示正在处于紧急呼叫，false表示不处于紧急呼叫。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

订阅callDetailsChange事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                       |
| -------- | ------------------------------------------------------- | ---- | -------------------------- |
| type     | string                                                  | 是   | 通话时监听通话详情的变化，参数固定为'callDetailsChange'。 |
| callback | Callback<[CallAttributeOptions](#callattributeoptions7)> | 是  | 以回调函数的方式返回订阅callDetailsChange事件的结果。     |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
call.on('callDetailsChange', (data: call.CallAttributeOptions) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('callEventChange')<sup>8+</sup>

on\(type: 'callEventChange', callback: Callback\<CallEventOptions\>\): void

订阅callEventChange事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                             | 必填 | 说明                       |
| -------- | ------------------------------------------------ | ---- | -------------------------- |
| type     | string                                           | 是   | 通话时监听通话事件的变化，参数固定为'callEventChange'。 |
| callback | Callback<[CallEventOptions](#calleventoptions8)> | 是   | 以回调函数的方式返回订阅callEventChange事件的结果。     |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
call.on('callEventChange', (data: call.CallEventOptions) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('callDisconnectedCause')<sup>8+</sup>

on\(type: 'callDisconnectedCause', callback: Callback\<DisconnectedDetails\>\): void

订阅callDisconnectedCause事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明                       |
| -------- | ------------------------------------------------------ | ---- | -------------------------- |
| type     | string                                                 | 是   | 通话时监听断开连接的原因，参数固定为'callDisconnectedCause'。 |
| callback | Callback<[DisconnectedDetails](#disconnecteddetails9)> | 是   | 以回调函数的方式返回订阅callDisconnectedCause事件的结果。    |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
call.on('callDisconnectedCause', (data: call.DisconnectedDetails) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('mmiCodeResult')<sup>9+</sup>

on\(type: 'mmiCodeResult', callback: Callback\<MmiCodeResults\>\): void

订阅mmiCodeResult事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                  |
| -------- | -------------------------------------------- | ---- | --------------------- |
| type     | string                                       | 是   | 通话时监听MMI码结果，参数固定为'mmiCodeResult'。 |
| callback | Callback<[MmiCodeResults](#mmicoderesults9)> | 是   | 以回调函数的方式返回订阅mmiCodeResult事件的结果。|

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
call.on('mmiCodeResult', (data: call.MmiCodeResults) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('callDetailsChange')<sup>7+</sup>

off\(type: 'callDetailsChange', callback?: Callback\<CallAttributeOptions\>\): void

取消订阅callDetailsChange事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                     | 必填 | 说明                               |
| -------- | -------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                   | 是   | 通话结束时取消监听通话详情的变化，参数固定为'callDetailsChange'。 |
| callback | Callback<[CallAttributeOptions](#callattributeoptions7)> | 否   | 回调函数。不填该参数将不会收到取消订阅的处理结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
call.off('callDetailsChange', (data: call.CallAttributeOptions) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('callEventChange')<sup>8+</sup>

off\(type: 'callEventChange', callback?: Callback\<CallEventOptions\>\): void

取消订阅callEventChange事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                             | 必填 | 说明                               |
| -------- | ------------------------------------------------ | ---- | ---------------------------------- |
| type     | string                                           | 是   | 通话结束时取消监听通话事件的变化，参数固定为'callEventChange'。 |
| callback | Callback<[CallEventOptions](#calleventoptions8)> | 否   | 回调函数。不填该参数将不会收到取消订阅的处理结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
call.off('callEventChange', (data: call.CallEventOptions) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('callDisconnectedCause')<sup>8+</sup>

off\(type: 'callDisconnectedCause', callback?: Callback\<DisconnectedDetails\>\): void

取消订阅callDisconnectedCause事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                       | 必填 | 说明                 |
| -------- | ---------------------------------------------------------- | ---- | ------------------- |
| type     | string                                                     | 是   | 调用断开连接的原因，参数固定为'callDisconnectedCause'。 |
| callback | Callback<[DisconnectedDetails](#disconnecteddetails9)>     | 否   | 回调函数。不填该参数将不会收到取消订阅的处理结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
call.off('callDisconnectedCause', (data: call.DisconnectedDetails) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('mmiCodeResult')<sup>9+</sup>

off\(type: 'mmiCodeResult', callback?: Callback\<MmiCodeResults\>\): void

取消订阅mmiCodeResult事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                              | 必填 | 说明        |
| -------- | ------------------------------------------------ | ---- | ----------- |
| type     | string                                           | 是   | MMI码结果，参数固定为'mmiCodeResult'。 |
| callback | Callback<[MmiCodeResults](#mmicoderesults9)>     | 否   | 回调函数。不填该参数将不会收到取消订阅的处理结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
call.off('mmiCodeResult', (data: call.MmiCodeResults) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```


## call.on('audioDeviceChange')<sup>10+</sup>

on\(type: 'audioDeviceChange', callback: Callback\<AudioDeviceCallbackInfo\>\): void

订阅通话音频设备切换事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                             | 必填 | 说明                                                |
| -------- | ----------------------------------------------- | ---- | --------------------------------------------------- |
| type     | string                                          | 是   | 通话音频设备发生变化，参数固定为'audioDeviceChange'。 |
| callback | Callback<[AudioDeviceCallbackInfo](#audiodevicecallbackinfo10)> | 是   | 以回调函数的方式返回订阅通话音频设备切换事件的结果。             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
call.on('audioDeviceChange', (data: call.AudioDeviceCallbackInfo) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```


## call.off('audioDeviceChange')<sup>10+</sup>

off\(type: 'audioDeviceChange', callback?: Callback\<AudioDeviceCallbackInfo\>\): void

取消订阅audioDeviceChange事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                       | 必填  |                           说明                      |
| -------- | ---------------------------------------------------------- | ---- | --------------------------------------------------- |
| type     | string                                                     | 是   | 通话音频设备发生变化，参数固定为'audioDeviceChange'。 |
| callback | Callback<[AudioDeviceCallbackInfo](#audiodevicecallbackinfo10)>            | 否   | 回调函数。不填该参数将不会收到取消订阅的处理结果。     |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
call.off('audioDeviceChange', (data: call.AudioDeviceCallbackInfo) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('postDialDelay')<sup>11+</sup>

on\(type: 'postDialDelay', callback: Callback\<string\>\): void

订阅拨号后延迟事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                             | 必填 | 说明                                                |
| -------- | ----------------------------------------------- | ---- | --------------------------------------------------- |
| type     | string                                          | 是   | 拨号后延迟，参数固定为'postDialDelay'。               |
| callback | Callback&lt;string&gt;                          | 是   |以回调函数的方式返回订阅拨号后延迟事件的结果。         |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
call.on('postDialDelay', (data: string) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('postDialDelay')<sup>11+</sup>

off\(type: 'postDialDelay', callback?: Callback\<string\>\): void

取消订阅拨号后延迟事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                       | 必填  |                           说明                      |
| -------- | ---------------------------------------------------------- | ---- | --------------------------------------------------- |
| type     | string                                                     | 是   | 拨号后延迟，参数固定为'postDialDelay'。              |
| callback | Callback&lt;string&gt;                                     | 否   | 回调函数。不填该参数将不会收到取消订阅的处理结果。    |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
call.off('postDialDelay', (data: string) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.isNewCallAllowed<sup>8+</sup>

isNewCallAllowed\(callback: AsyncCallback\<boolean\>\): void

判断是否允许再拨打一通新电话。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                         | 必填 | 说明       |
| -------- | ---------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 以回调函数的方式返回结果。true表示允许拨打，false表示不可拨打。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

判断是否允许再拨打一通新电话。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                   | 说明                        |
| ---------------------- | --------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式异步返回结果。true表示允许拨打，false表示不可拨打。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

分离会议电话。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callId   | number                    | 是   | 呼叫Id。   |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回分离会议电话的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300008  | Conference call is not active. |
| 8300999  | Unknown error code.                          |

**示例：**

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

分离会议电话。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| callId | number | 是   | 呼叫Id。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300008  | Conference call is not active. |
| 8300999  | Unknown error code.                          |

**示例：**

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

获取呼叫限制状态。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| type     | [CallRestrictionType](#callrestrictiontype8)                 | 是   | 呼叫限制类型。                        |
| callback | AsyncCallback&lt;[RestrictionStatus](#restrictionstatus8)&gt; | 是   | 回调函数。返回限制状态。               |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

获取呼叫限制状态。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型                                         | 必填 | 说明                                   |
| ------ | -------------------------------------------- | ---- | -------------------------------------- |
| slotId | number                                       | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| type   | [CallRestrictionType](#callrestrictiontype8) | 是   | 呼叫限制类型。                        |

**返回值：**

| 类型                                                    | 说明                        |
| ------------------------------------------------------- | --------------------------- |
| Promise&lt;[RestrictionStatus](#restrictionstatus8)&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

设置呼叫限制状态。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                   |
| -------- | ------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                      | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| info     | [CallRestrictionInfo](#callrestrictioninfo8) | 是   | 呼叫限制信息。                         |
| callback | AsyncCallback&lt;void&gt;                   | 是   | 以回调函数的方式返回设置呼叫限制状态的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

设置呼叫限制状态。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型                                         | 必填 | 说明                                   |
| ------ | -------------------------------------------- | ---- | -------------------------------------- |
| slotId | number                                       | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| info   | [CallRestrictionInfo](#callrestrictioninfo8) | 是   | 呼叫限制信息。                         |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

修改呼叫限制密码。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名          | 类型                                        | 必填 | 说明                                   |
| --------------- | ------------------------------------------- | ---- | ------------------------------------ |
| slotId          | number                                      | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| oldPassword     | string                                      | 是   | 呼叫限制旧密码。                       |
| newPassword     | string                                      | 是   | 呼叫限制新密码。                       |
| callback        | AsyncCallback&lt;void&gt;                   | 是   | 以回调函数的方式返回修改呼叫限制密码的结果。    |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

修改呼叫限制密码。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名          | 类型                                        | 必填 | 说明                                   |
| --------------- | ------------------------------------------- | ---- | ------------------------------------ |
| slotId          | number                                      | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| oldPassword     | string                                      | 是   | 呼叫限制旧密码。                       |
| newPassword     | string                                      | 是   | 呼叫限制新密码。                       |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

获取呼叫转移信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| type     | [CallTransferType](#calltransfertype8)                       | 是   | 呼叫转移类型。                         |
| callback | AsyncCallback&lt;[CallTransferResult](#calltransferresult8)&gt; | 是   | 回调函数。返回呼叫转移信息。           |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

获取呼叫转移信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型                                   | 必填 | 说明                                   |
| ------ | -------------------------------------- | ---- | -------------------------------------- |
| slotId | number                                 | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| type   | [CallTransferType](#calltransfertype8) | 是   | 呼叫转移类型。                         |

**返回值：**

| 类型                                                      | 说明                        |
| --------------------------------------------------------- | --------------------------- |
| Promise&lt;[CallTransferResult](#calltransferresult8)&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

设置呼叫转移信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                   |
| -------- | ------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| info     | [CallTransferInfo](#calltransferinfo8) | 是   | 呼叫转移信息。                        |
| callback | AsyncCallback&lt;void&gt;             | 是   | 以回调函数的方式返回设置呼叫转移信息的结果。      |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

设置呼叫转移信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型                                  | 必填 | 说明                                   |
| ------ | ------------------------------------- | ---- | -------------------------------------- |
| slotId | number                                | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| info   | [CallTransferInfo](#calltransferinfo8) | 是   | 呼叫转移信息。                        |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

判断是否正在响铃。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                         | 必填 | 说明       |
| -------- | ---------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 以回调函数的方式返回是否正在响铃的结果。true表示正在响铃，false表示没有在响铃。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

判断是否正在响铃。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                   | 说明                        |
| ---------------------- | --------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式异步返回结果。true表示正在响铃，false表示没有响铃。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

设置通话中的静音。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回设置通话中的静音的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

设置通话中的静音。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

取消通话中的静音。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回取消通话中的静音的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

取消通话中的静音。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

设置通话音频设备。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                         | 必填 | 说明       |
| -------- | ---------------------------- | ---- | ---------- |
| device   | [AudioDevice](#audiodevice10)| 是   | 音频设备。 |
| callback | AsyncCallback&lt;void&gt;    | 是   | 以回调函数的方式返回设置通话音频设备的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

设置通话音频设备。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                         | 必填 | 说明       |
| -------- | ---------------------------- | ---- | ---------- |
| device   | [AudioDevice](#audiodevice10)| 是   | 音频设备。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

加入会议。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名         | 类型                      | 必填 | 说明            |
| -------------- | ------------------------- | ---- | --------------- |
| mainCallId     | number                    | 是   | 主通话Id。      |
| callNumberList | Array<string\>            | 是   | 呼叫号码列表。 |
| callback       | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回加入会议的结果。      |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

加入会议。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

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

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

更新Ims呼叫模式。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                         | 必填 | 说明           |
| -------- | ---------------------------- | ---- | -------------- |
| callId   | number                       | 是   | 呼叫Id。       |
| mode     | [ImsCallMode](#imscallmode8) | 是   | Ims呼叫模式。 |
| callback | AsyncCallback&lt;void&gt;    | 是   | 以回调函数的方式返回更新Ims呼叫模式的结果。     |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

更新Ims呼叫模式。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

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

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

启用Ims开关。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                   |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回启用Ims开关的结果。          |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

启用Ims开关。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

禁用Ims开关。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                   |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回禁用Ims开关的结果。               |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

禁用Ims开关。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                    |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。  |

**返回值：**

| 类型                | 说明                         |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。  |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

判断Ims开关是否启用。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                   |
| -------- | ---------------------------- | ---- | -------------------------------------- |
| slotId   | number                       | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 以回调函数的方式返回判断Ims开关是否启用的结果。true表示Ims开关启用，false表示未启用。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

判断Ims开关是否启用。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式异步返回结果。true表示Ims开关启用，false表示未启用。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

判断Ims开关是否启用。调用此API返回结果。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型    | 说明                                                 |
| ------- | ---------------------------------------------------- |
| boolean | 用来返回结果。true表示Ims开关启用，false表示未启用。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Non-system applications use system APIs.                     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types; |
| 8300001  | Invalid parameter value.                                     |
| 8300002  | Operation failed. Cannot connect to service.                 |
| 8300003  | System internal error.                                       |
| 8300999  | Unknown error code.                                          |

**示例：**

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

取消未激活完成的非结构化补充数据业务。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                    |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。  |
| callback | AsyncCallback&lt;void&gt; | 是   | 以回调函数的方式返回取消未激活完成的非结构化补充数据业务的结果。                              |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

取消未激活完成的非结构化补充数据业务。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                    |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。  |

**返回值：**

| 类型                | 说明                         |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。  |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

设置NR语音的开关状态。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                           | 必填 | 说明                                                 |
| ----------- | ----------------------------- | ---- | ---------------------------------------------------- |
| slotId      | number                        | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。                |
| state       | [VoNRState](#vonrstate10)     | 是   | 开关状态。                                            |
| callback    | AsyncCallback&lt;void&gt;  | 是   | 以回调函数的方式返回设置NR语音的开关状态的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

设置NR语音的开关状态。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                           | 必填 | 说明                                        |
| ----------- | ----------------------------- | ---- | ------------------------------------------- |
| slotId      | number                        | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。     |
| state       | [VoNRState](#vonrstate10)     | 是   | 开关状态。                                   |

**返回值：**

| 类型                   | 说明                                          |
| ---------------------- | --------------------------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。     |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

查询NR语音的开关状态。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      |                     类型                      | 必填  | 说明                                                   |
| ----------- | --------------------------------------------- | ---- | ------------------------------------------------------ |
| slotId      | number                                        | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。                  |
| callback    | AsyncCallback&lt;[VoNRState](#vonrstate10)&gt;| 是   | 回调函数。返回NR语音开关的状态。                         |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

查询NR语音的开关状态。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                           | 必填 | 说明                                        |
| ----------- | ----------------------------- | ---- | ------------------------------------------- |
| slotId      | number                        | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。     |

**返回值：**

|                 类型                     | 说明                                        |
| ---------------------------------------- | ------------------------------------------- |
| Promise&lt;[VoNRState](#vonrstate10)&gt; | 以Promise形式异步返回开关状态。              |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

检查是否可以设置呼叫转移时间。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                           | 必填 | 说明                                                  |
| ----------- | ----------------------------- | ---- | ----------------------------------------------------- |
| slotId      | number                        | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。                 |
| callback    | AsyncCallback&lt;boolean&gt;  | 是   | 回调函数。返回true表示可以设置，返回false表示不可以设置。|

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

检查是否可以设置呼叫转移时间。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                           | 必填 | 说明                                        |
| ----------- | ----------------------------- | ---- | ------------------------------------------- |
| slotId      | number                        | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。     |

**返回值：**

| 类型                   | 说明                                          |
| ---------------------- | --------------------------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式异步返回是否可以设置呼叫转移时间。返回true表示可以设置，返回false表示不可以设置。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

暗码广播。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.PLACE_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                         | 必填 | 说明                                       |
| ----------- | ---------------------------- | ---- | ----------------------------------------- |
| inputCode   | string                       | 是   | 暗码。支持暗码字段, 如：*#*#2846579#*#*(工程菜单)。 |
| callback    | AsyncCallback&lt;void&gt;    | 是   | 以回调函数的方式返回暗码广播的结果。              |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

暗码广播。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.PLACE_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                         | 必填 | 说明                                       |
| ----------- | ---------------------------- | ---- | ----------------------------------------- |
| inputCode   | string                       | 是   | 暗码。支持暗码字段, 如：*#*#2846579#*#*(工程菜单)。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

删除未接来电通知。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE, ohos.permission.READ_CALL_LOG 和 ohos.permission.WRITE_CALL_LOG

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名      | 类型                         | 必填 | 说明                                      |
| ----------- | ---------------------------- | ---- | ---------------------------------------   |
| callback    | AsyncCallback&lt;void&gt;    | 是   | 以回调函数的方式返回删除未接来电通知的结果。  |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

删除未接来电通知。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE, ohos.permission.READ_CALL_LOG 和 ohos.permission.WRITE_CALL_LOG

**系统能力**：SystemCapability.Telephony.CallManager

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

发布通话界面事件。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名    | 类型   | 必填 | 说明     |
| --------- | ------ | ---- | -------- |
| callId    | number | 是   | 呼叫Id。 |
| eventName | string | 是   | 事件名称。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |

**示例：**

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

拨打电话的可选参数。

**系统能力**：SystemCapability.Telephony.CallManager

|        名称              | 类型                               | 必填 | 说明                                                                                             |
| ------------------------ | ---------------------------------- | ---- | ----------------------------------------------------------------------------------------------- |
| accountId <sup>8+</sup>  | number                             | 否   | 帐户Id。<br/>- 0：卡槽1。<br/>- 1：卡槽2。<br/>。此接口为系统接口。                                   |
| videoState <sup>8+</sup> | [VideoStateType](#videostatetype7) | 否   | 视频状态类型。此接口为系统接口。                                                                  |
| dialScene <sup>8+</sup>  | [DialScene](#dialscene8)           | 否   | 拨号场景。此接口为系统接口。                                                                      |
| dialType <sup>8+</sup>   | [DialType](#dialtype8)             | 否   | 拨号类型。此接口为系统接口。                                                                      |

## DialCallOptions<sup>9+</sup>

拨打电话的可选参数。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

|        名称              | 类型                               | 必填 | 说明                                         |
| ------------------------ | ---------------------------------- | ---- | ------------------------------------------- |
| accountId <sup>9+</sup>  | number                             | 否   | 帐户Id。<br/>- 0：卡槽1。<br/>- 1：卡槽2。    |
| videoState <sup>9+</sup> | [VideoStateType](#videostatetype7) | 否   | 视频状态类型。                               |
| dialScene <sup>9+</sup>  | [DialScene](#dialscene8)           | 否   | 拨号场景。                                   |
| dialType <sup>9+</sup>   | [DialType](#dialtype8)             | 否   | 拨号类型。                                   |


## ImsCallMode<sup>8+</sup>

IP多媒体系统调用模式。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                   | 值   | 说明               |
| ---------------------- | ---- | ------------------ |
| CALL_MODE_AUDIO_ONLY   | 0    | 仅限音频呼叫。       |
| CALL_MODE_SEND_ONLY    | 1    | 仅发送呼叫。         |
| CALL_MODE_RECEIVE_ONLY | 2    | 仅接收呼叫。         |
| CALL_MODE_SEND_RECEIVE | 3    | 允许发送和接收呼叫。 |
| CALL_MODE_VIDEO_PAUSED | 4    | 暂停视频呼叫。       |

## VoNRState<sup>10+</sup>

5G语音开关状态。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                   | 值   | 说明               |
| ---------------------- | ---- | ----------------- |
| VONR_STATE_OFF         | 0    | 关闭状态。           |
| VONR_STATE_ON          | 1    | 打开状态。           |

## AudioDevice<sup>10+</sup>

音频设备。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

|                名称               |                  类型                 | 必填  |        说明      |
| --------------------------------- | ------------------------------------- | ---- | ---------------- |
| deviceType <sup>10+</sup>         | [AudioDeviceType](#audiodevicetype10) | 是   | 音频设备类型。    |
| address <sup>10+</sup>            | string                                | 否   | 音频设备地址。    |
| deviceName <sup>11+</sup>         | string                                | 否   | 音频设备名称。    |

## AudioDeviceType<sup>10+</sup>

音频设备类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                 | 值   | 说明         |
| -------------------- | ---- | ----------- |
| DEVICE_EARPIECE      | 0    | 耳机设备。     |
| DEVICE_SPEAKER       | 1    | 扬声器设备。   |
| DEVICE_WIRED_HEADSET | 2    | 有线耳机设备。 |
| DEVICE_BLUETOOTH_SCO | 3    | 蓝牙SCO设备。  |
| DEVICE_DISTRIBUTED_AUTOMOTIVE<sup>11+</sup> | 4    | 分布式车机设备。|

## AudioDeviceCallbackInfo<sup>10+</sup>

音频设备信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

|                名称               |                  类型                 | 必填  |        说明      |
| --------------------------------- | ------------------------------------- | ---- | ---------------- |
| audioDeviceList <sup>10+</sup>    | [Array\<AudioDevice\>](#audiodevice10) | 是   | 音频设备列表。    |
| currentAudioDevice <sup>10+</sup> | [AudioDevice](#audiodevice10)          | 是   | 当前音频设备。    |
| isMuted <sup>10+</sup>            | boolean                               | 是   | 是否静音。        |


## CallRestrictionType<sup>8+</sup>

呼叫限制类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                                          | 值   | 说明                       |
| --------------------------------------------- | ---- | -------------------------- |
| RESTRICTION_TYPE_ALL_INCOMING                 | 0    | 限制所有呼入。               |
| RESTRICTION_TYPE_ALL_OUTGOING                 | 1    | 限制所有呼出。               |
| RESTRICTION_TYPE_INTERNATIONAL                | 2    | 限制国际通话。               |
| RESTRICTION_TYPE_INTERNATIONAL_EXCLUDING_HOME | 3    | 限制除归属国以外的国际通话。 |
| RESTRICTION_TYPE_ROAMING_INCOMING             | 4    | 限制漫游呼入。               |
| RESTRICTION_TYPE_ALL_CALLS                    | 5    | 限制所有通话。               |
| RESTRICTION_TYPE_OUTGOING_SERVICES            | 6    | 限制传出业务。               |
| RESTRICTION_TYPE_INCOMING_SERVICES            | 7    | 限制呼入业务。               |

## CallTransferInfo<sup>8+</sup>

呼叫转移信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

|          名称            | 类型                                                 | 必填 | 说明             |
| ------------------------ | ---------------------------------------------------- | ---- | ---------------- |
| transferNum              | string                                               | 是   | 转移编号。         |
| type                     | [CallTransferType](#calltransfertype8)               | 是   | 呼叫转移类型。     |
| settingType              | [CallTransferSettingType](#calltransfersettingtype8) | 是   | 设置呼叫转移类型。 |
| startHour<sup>9+</sup>   | number                                               | 否   | 开始时间的小时数。 |
| startMinute<sup>9+</sup> | number                                               | 否   | 开始时间的分钟数。 |
| endHour<sup>9+</sup>     | number                                               | 否   | 结束时间的小时数。 |
| endMinute<sup>9+</sup>   | number                                               | 否   | 结束时间的分钟数。 |

## CallTransferType<sup>8+</sup>

呼叫转移类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ------------ |
| TRANSFER_TYPE_UNCONDITIONAL | 0    | 无条件转移。   |
| TRANSFER_TYPE_BUSY          | 1    | 忙线转移。     |
| TRANSFER_TYPE_NO_REPLY      | 2    | 无回复转移。   |
| TRANSFER_TYPE_NOT_REACHABLE | 3    | 无法访问转移。 |

## CallTransferSettingType<sup>8+</sup>

设置呼叫转移类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                       | 值   | 说明         |
| -------------------------- | ---- | ------------ |
| CALL_TRANSFER_DISABLE      | 0    | 禁用呼叫转移。 |
| CALL_TRANSFER_ENABLE       | 1    | 启用呼叫转移。 |
| CALL_TRANSFER_REGISTRATION | 3    | 登记呼叫转移。 |
| CALL_TRANSFER_ERASURE      | 4    | 消除呼叫转移。 |

## CallAttributeOptions<sup>7+</sup>

调用属性选项。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

|      名称       | 类型                                     | 必填 | 说明           |
| --------------- | ---------------------------------------- | ---- | -------------- |
| accountNumber   | string                                   | 是   | 账号号码。       |
| speakerphoneOn  | boolean                                  | 是   | 扬声器接通电话。 |
| accountId       | number                                   | 是   | 帐户Id。         |
| videoState      | [VideoStateType](#videostatetype7)       | 是   | 视频状态类型。   |
| startTime       | number                                   | 是   | 开始时间。       |
| isEcc           | boolean                                  | 是   | 是否是Ecc。      |
| callType        | [CallType](#calltype7)                   | 是   | 通话类型。       |
| callId          | number                                   | 是   | 呼叫Id。         |
| callState       | [DetailedCallState](#detailedcallstate7) | 是   | 详细呼叫状态。   |
| conferenceState | [ConferenceState](#conferencestate7)     | 是   | 会议状态。       |
| voipCallAttribute<sup>11+</sup> | [VoipCallAttribute](#voipcallattribute11)     | 否   | VoIP通话信息。       |
| crsType<sup>11+</sup> | number                             | 是   | 视频彩振类型。|
| originalCallType<sup>11+</sup> | number                    | 是   | 视频彩振原始呼叫类型。|
| numberLocation<sup>12+</sup> | string | 否 | 号码归属地信息 |
| numberMarkInfo<sup>12+</sup> | [NumberMarkInfo](#numbermarkinfo12) | 否 | 号码标记信息。 |

## VoipCallAttribute<sup>11+</sup>

VoIP通话信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

|      名称       | 类型               | 必填 | 说明           |
| --------------- | ------------------- | ---- | -------------- |
| voipCallId   | string    | 是   | VoIP通话唯一Id。       |
| userName  | string    | 是   | 用户昵称。 |
| userProfile       | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)    | 是   | 用户头像图片。  |
| extensionId      | string     | 是   |  三方应用进程Id。  |
| abilityName      | string     | 是   |  需加载的三方应用的界面ability。  |
| voipBundleName    | string     | 是   |  三方应用包名。  |
| showBannerForIncomingCall<sup>12+</sup>    | boolean     | 否   |  上报来电时是否显示来电横幅。  |
| isConferenceCall<sup>12+</sup>    | boolean     | 否   |  上报是否是电话会议。  |
| isVoiceAnswerSupported<sup>12+</sup>    | boolean     | 否   |  上报来电时是否支持语音接听。  |

## ConferenceState<sup>7+</sup>

会议状态。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                         | 值   | 说明           |
| ---------------------------- | ---- | -------------- |
| TEL_CONFERENCE_IDLE          | 0    | 电话会议空闲。   |
| TEL_CONFERENCE_ACTIVE        | 1    | 电话会议激活。   |
| TEL_CONFERENCE_DISCONNECTING | 2    | 电话会议断开。   |
| TEL_CONFERENCE_DISCONNECTED  | 3    | 电话会议已断开。 |

## CallType<sup>7+</sup>

通话类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称          | 值   | 说明         |
| ------------- | ---- | ------------ |
| TYPE_CS       | 0    | CS通话。       |
| TYPE_IMS      | 1    | IMS通话。      |
| TYPE_OTT      | 2    | OTT通话。      |
| TYPE_ERR_CALL | 3    | 其他类型通话。 |
| TYPE_VOIP<sup>11+</sup> | 4    | VoIP通话。 |

## VideoStateType<sup>7+</sup>

视频状态类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                                   | 值   | 说明     |
| ------------------------------------- | ---- | --------|
| TYPE_VOICE                            | 0    | 语音状态。 |
| TYPE_VIDEO_SEND_ONLY<sup>11+</sup>    | 1    | 视频通话只发送数据状态。 |
| TYPE_VIDEO_RECEIVE_ONLY<sup>11+</sup> | 2    | 视频通话只接收数据状态。 |
| TYPE_VIDEO                            | 3    | 视频状态。 |
| TYPE_VIDEO_BIDIRECTIONAL<sup>11+</sup>| 4    | 视频通话接收发送数据状态。|

## DetailedCallState<sup>7+</sup>

详细的呼叫状态。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                      | 值   | 说明           |
| ------------------------- | ---- | -------------- |
| CALL_STATUS_ACTIVE        | 0    | 激活呼叫状态。   |
| CALL_STATUS_HOLDING       | 1    | 保持呼叫状态。   |
| CALL_STATUS_DIALING       | 2    | 呼叫状态拨号。   |
| CALL_STATUS_ALERTING      | 3    | 电话报警状态。   |
| CALL_STATUS_INCOMING      | 4    | 呼叫传入状态。   |
| CALL_STATUS_WAITING       | 5    | 呼叫等待状态。   |
| CALL_STATUS_DISCONNECTED  | 6    | 呼叫状态已断开。 |
| CALL_STATUS_DISCONNECTING | 7    | 呼叫状态断开。   |
| CALL_STATUS_IDLE          | 8    | 呼叫状态空闲。   |

## CallRestrictionInfo<sup>8+</sup>

呼叫限制信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

|   名称   | 类型                                         | 必填 | 说明         |
| -------- | -------------------------------------------- | ---- | ------------ |
| type     | [CallRestrictionType](#callrestrictiontype8) | 是   | 呼叫限制类型。 |
| password | string                                       | 是   | 密码。         |
| mode     | [CallRestrictionMode](#callrestrictionmode8) | 是   | 呼叫限制模式。 |

## CallRestrictionMode<sup>8+</sup>

呼叫限制模式。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                          | 值   | 说明         |
| ----------------------------- | ---- | ------------ |
| RESTRICTION_MODE_DEACTIVATION | 0    | 限制模式停用。 |
| RESTRICTION_MODE_ACTIVATION   | 1    | 限制模式激活。 |

## CallEventOptions<sup>8+</sup>

呼叫事件的可选参数。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

|   名称  | 类型                                       | 必填 | 说明           |
| ------- | ------------------------------------------ | ---- | -------------- |
| eventId | [CallAbilityEventId](#callabilityeventid8) | 是   | 呼叫能力事件Id。 |

## CallAbilityEventId<sup>8+</sup>

呼叫能力事件Id。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                                  | 值   | 说明            |
| ------------------------------------- | ---- | --------------- |
| EVENT_DIAL_NO_CARRIER                 | 1    | 拨号无载波事件。  |
| EVENT_INVALID_FDN_NUMBER              | 2    | 无效的FDN号事件。 |
| EVENT_HOLD_CALL_FAILED<sup>11+</sup>  | 3    | 保持通话失败事件。 |
| EVENT_SWAP_CALL_FAILED<sup>11+</sup>  | 4    | 保持当前通话并接听等待中电话失败事件。 |
| EVENT_COMBINE_CALL_FAILED<sup>11+</sup>  | 5 | 合并通话失败。 |
| EVENT_SPLIT_CALL_FAILED<sup>11+</sup> | 6    | 分离通话失败。 |
| EVENT_SHOW_FULL_SCREEN<sup>12+</sup>  | 7    | 全屏显示通话界面。   |
| EVENT_SHOW_FLOAT_WINDOW<sup>12+</sup> | 8    | 悬浮窗显示通话界面。 |

## DialScene<sup>8+</sup>

拨号场景。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称            | 值   | 说明         |
| --------------- | ---- | ------------ |
| CALL_NORMAL     | 0    | 呼叫正常。     |
| CALL_PRIVILEGED | 1    | 呼叫特权。     |
| CALL_EMERGENCY  | 2    | 拨打紧急电话。 |

## DialType<sup>8+</sup>

拨号类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                 | 值   | 说明             |
| -------------------- | ---- | ---------------- |
| DIAL_CARRIER_TYPE    | 0    | 载波拨号类型。     |
| DIAL_VOICE_MAIL_TYPE | 1    | 语音邮件拨号类型。 |
| DIAL_OTT_TYPE        | 2    | OTT拨号类型。      |

## RejectMessageOptions<sup>7+</sup>

拒绝消息可选参数。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

|     名称       | 类型   | 必填 | 说明     |
| -------------- | ------ | ---- | -------- |
| messageContent | string | 是   | 消息内容。 |

## CallTransferResult<sup>8+</sup>

呼叫转移结果。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

|          名称            |                 类型               | 必填 |       说明       |
| ------------------------ | ---------------------------------- | ---- | ---------------- |
| status                   | [TransferStatus](#transferstatus8) |  是  | 转移状态。         |
| number                   | string                             |  是  | 号码。             |
| startHour<sup>9+</sup>   | number                             |  是  | 开始时间的小时数。 |
| startMinute<sup>9+</sup> | number                             |  是  | 开始时间的分钟数。 |
| endHour<sup>9+</sup>     | number                             |  是  | 结束时间的小时数。 |
| endMinute<sup>9+</sup>   | number                             |  是  | 结束时间的分钟数。 |

## CallWaitingStatus<sup>7+</sup>

呼叫等待状态。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                 | 值   | 说明         |
| -------------------- | ---- | ------------ |
| CALL_WAITING_DISABLE | 0    | 禁用呼叫等待。 |
| CALL_WAITING_ENABLE  | 1    | 启用呼叫等待。 |

## RestrictionStatus<sup>8+</sup>

限制状态。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                | 值   | 说明     |
| ------------------- | ---- | -------- |
| RESTRICTION_DISABLE | 0    | 禁用限制。 |
| RESTRICTION_ENABLE  | 1    | 启用限制。 |

## TransferStatus<sup>8+</sup>

转移状态。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称             | 值   | 说明     |
| ---------------- | ---- | -------- |
| TRANSFER_DISABLE | 0    | 禁用转移。 |
| TRANSFER_ENABLE  | 1    | 启用转移。 |

## DisconnectedDetails<sup>9+</sup>

通话结束原因。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称    |                    类型                    | 必填 | 说明            |
| ------- | ------------------------------------------ | ---- | --------------- |
| reason  | [DisconnectedReason](#disconnectedreason8) | 是   | 通话结束原因。    |
| message | string                                     | 是   | 通话结束提示信息。|

## DisconnectedReason<sup>8+</sup>

断开连接的详细信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

|                              名称                            | 值   |                  说明                   |
| ------------------------------------------------------------ | ---- | --------------------------------------- |
| UNASSIGNED_NUMBER                                            | 1    | 未分配的号码(空号)。                      |
| NO_ROUTE_TO_DESTINATION                                      | 3    | 无至目的地的路由。                        |
| CHANNEL_UNACCEPTABLE                                         | 6    | 不可接受的通路。                          |
| OPERATOR_DETERMINED_BARRING                                  | 8    | 运营商闭锁。                              |
| CALL_COMPLETED_ELSEWHERE<sup>9+</sup>                        | 13   | 呼叫在其他地方完成。                      |
| NORMAL_CALL_CLEARING                                         | 16   | 清除正常呼叫。                            |
| USER_BUSY                                                    | 17   | 用户忙。                                  |
| NO_USER_RESPONDING                                           | 18   | 无用户响应。                              |
| USER_ALERTING_NO_ANSWER                                      | 19   | 已有用户提醒，但无应答。                  |
| CALL_REJECTED                                                | 21   | 呼叫拒绝。                                |
| NUMBER_CHANGED                                               | 22   | 号码改变。                                |
| CALL_REJECTED_DUE_TO_FEATURE_AT_THE_DESTINATION<sup>9+</sup> | 24   | 当由于目标地址(例如匿名)导致呼叫被拒绝。 |
| FAILED_PRE_EMPTION<sup>9+</sup>                              | 25   | 抢占失败。                                |
| NON_SELECTED_USER_CLEARING<sup>9+</sup>                      | 26   | 非选定用户清除。                          |
| DESTINATION_OUT_OF_ORDER                                     | 27   | 终点故障。                                |
| INVALID_NUMBER_FORMAT                                        | 28   | 无效号码格式。                            |
| FACILITY_REJECTED<sup>9+</sup>                               | 29   | 增补业务拒绝。                            |
| RESPONSE_TO_STATUS_ENQUIRY<sup>9+</sup>                      | 30   | 对状态查询的响应。                        |
| NORMAL_UNSPECIFIED<sup>9+</sup>                              | 31   | 正常，未指定。                            |
| NO_CIRCUIT_CHANNEL_AVAILABLE<sup>9+</sup>                    | 34   | 无电路/通道可用。                         |
| NETWORK_OUT_OF_ORDER                                         | 38   | 网络故障。                                |
| TEMPORARY_FAILURE                                            | 41   | 临时故障。                                |
| SWITCHING_EQUIPMENT_CONGESTION<sup>9+</sup>                  | 42   | 交换设备拥塞。                            |
| ACCESS_INFORMATION_DISCARDED<sup>9+</sup>                    | 43   | 已丢弃访问信息。                          |
| REQUEST_CIRCUIT_CHANNEL_NOT_AVAILABLE<sup>9+</sup>           | 44   | 请求的电路/通道不可用。                   |
| RESOURCES_UNAVAILABLE_UNSPECIFIED<sup>9+</sup>               | 47   | 未指定资源不可用。                        |
| QUALITY_OF_SERVICE_UNAVAILABLE<sup>9+</sup>                  | 49   | 服务质量不可用。                          |
| REQUESTED_FACILITY_NOT_SUBSCRIBED<sup>9+</sup>               | 50   | 请求的设施未订阅。                        |
| INCOMING_CALLS_BARRED_WITHIN_THE_CUG<sup>9+</sup>            | 55   | CUG内禁止来电。                           |
| BEARER_CAPABILITY_NOT_AUTHORIZED<sup>9+</sup>                | 57   | 未授权承载能力。                          |
| BEARER_CAPABILITY_NOT_PRESENTLY_AVAILABLE<sup>9+</sup>       | 58   | 承载能力目前不可用。                      |
| SERVICE_OR_OPTION_NOT_AVAILABLE_UNSPECIFIED<sup>9+</sup>     | 63   | 服务或选项不可用，未指定。                |
| BEARER_SERVICE_NOT_IMPLEMENTED<sup>9+</sup>                  | 65   | 未实现承载服务。                          |
| ACM_EQUALTO_OR_GREATER_THAN_THE_MAXIMUM_VALUE<sup>9+</sup>   | 68   | ACM大于或等于最大值。                     |
| REQUESTED_FACILITY_NOT_IMPLEMENTED<sup>9+</sup>              | 69   | 请求的设施未实施。                        |
| ONLY_RESTRICTED_DIGITAL_INFO_BEARER_CAPABILITY_IS_AVAILABLE<sup>9+</sup> | 70   | 仅限BC有限数字信息可用。      |
| SERVICE_OR_OPTION_NOT_IMPLEMENTED_UNSPECIFIED<sup>9+</sup>   | 79   | 服务或选项未实施，未指定。                |
| INVALID_TRANSACTION_IDENTIFIER_VALUE<sup>9+</sup>            | 81   | 无效的业务标识符值。                      |
| USER_NOT_MEMBER_OF_CUG<sup>9+</sup>                          | 87   | 用户不是CUG成员。                         |
| INCOMPATIBLE_DESTINATION<sup>9+</sup>                        | 88   | 目标不兼容。                              |
| INVALID_TRANSIT_NETWORK_SELECTION<sup>9+</sup>               | 91   | 选择的传输网络无效。                      |
| SEMANTICALLY_INCORRECT_MESSAGE<sup>9+</sup>                  | 95   | 语义错误的消息。                          |
| INVALID_MANDATORY_INFORMATION<sup>9+</sup>                   | 96   | 无效的强制信息。                          |
| MESSAGE_TYPE_NON_EXISTENT_OR_NOT_IMPLEMENTED<sup>9+</sup>    | 97   | 消息类型不存在或未实现。                  |
| MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE<sup>9+</sup> | 98   | 消息类型与协议状态不兼容。                |
| INFORMATION_ELEMENT_NON_EXISTENT_OR_NOT_IMPLEMENTED<sup>9+</sup>    | 99   | IE不存在或未实现。                 |
| CONDITIONAL_IE_ERROR<sup>9+</sup>                            | 100  | 条件IE错误。                              |
| MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE<sup>9+</sup>      | 101  | 消息与协议状态不兼容。                    |
| RECOVERY_ON_TIMER_EXPIRED<sup>9+</sup>                       | 102  | 计时器过期时恢复计时器编号。              |
| PROTOCOL_ERROR_UNSPECIFIED<sup>9+</sup>                      | 111  | 协议错误，未指定。                        |
| INTERWORKING_UNSPECIFIED<sup>9+</sup>                        | 127  | 互通，未指定。                            |
| CALL_BARRED<sup>9+</sup>                                     | 240  | 呼叫被禁止。                              |
| FDN_BLOCKED<sup>9+</sup>                                     | 241  | FDN受阻。                                 |
| IMSI_UNKNOWN_IN_VLR<sup>9+</sup>                             | 242  | VLR中的IMSI未知。                         |
| IMEI_NOT_ACCEPTED<sup>9+</sup>                               | 243  | IMEI未被接受。                            |
| DIAL_MODIFIED_TO_USSD<sup>9+</sup>                           | 244  | 拨号修改为USSD。                          |
| DIAL_MODIFIED_TO_SS<sup>9+</sup>                             | 245  | 拨号修改为USSD号。                        |
| DIAL_MODIFIED_TO_DIAL<sup>9+</sup>                           | 246  | 拨号已修改为正常。                        |
| RADIO_OFF<sup>9+</sup>                                       | 247  | 无线电通讯已关闭。                        |
| OUT_OF_SERVICE<sup>9+</sup>                                  | 248  | 停止服务。                                |
| NO_VALID_SIM<sup>9+</sup>                                    | 249  | SIM卡无效。                               |
| RADIO_INTERNAL_ERROR<sup>9+</sup>                            | 250  | 无线电通讯内部错误。                      |
| NETWORK_RESP_TIMEOUT<sup>9+</sup>                            | 251  | 网络响应超时。                            |
| NETWORK_REJECT<sup>9+</sup>                                  | 252  | 网络拒绝。                                |
| RADIO_ACCESS_FAILURE<sup>9+</sup>                            | 253  | 无线电接入故障。                          |
| RADIO_LINK_FAILURE<sup>9+</sup>                              | 254  | 无线电链路故障。                          |
| RADIO_LINK_LOST<sup>9+</sup>                                 | 255  | 无线电链路丢失。                          |
| RADIO_UPLINK_FAILURE<sup>9+</sup>                            | 256  | 无线电上行链路故障。                      |
| RADIO_SETUP_FAILURE<sup>9+</sup>                             | 257  | 无线电通讯设置失败。                      |
| RADIO_RELEASE_NORMAL<sup>9+</sup>                            | 258  | 无线电释放正常。                          |
| RADIO_RELEASE_ABNORMAL<sup>9+</sup>                          | 259  | 无线电释放异常。                          |
| ACCESS_CLASS_BLOCKED<sup>9+</sup>                            | 260  | 访问类被阻止。                            |
| NETWORK_DETACH<sup>9+</sup>                                  | 261  | 网络分离。                                |
| INVALID_PARAMETER                                            | 1025 | 无效参数。                                |
| SIM_NOT_EXIT                                                 | 1026 | SIM卡未退出。                             |
| SIM_PIN_NEED                                                 | 1027 | 需要SIM卡PIN码。                          |
| CALL_NOT_ALLOW                                               | 1029 | 不允许呼叫。                              |
| SIM_INVALID                                                  | 1045 | SIM卡无效。                               |
| UNKNOWN                                                      | 1279 | 未知原因。                                |

## MmiCodeResults<sup>9+</sup>

MMI码结果。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称    | 类型                             | 必填 | 说明            |
| ------- | -------------------------------- | ---- | --------------- |
| result  | [MmiCodeResult](#mmicoderesult9) | 是   | MMI码结果。 |
| message | string                           | 是   | MMI码消息。 |

## MmiCodeResult<sup>9+</sup>

MMI码结果。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称             | 值   | 说明          |
| ---------------- | ---- | ------------- |
| MMI_CODE_SUCCESS | 0    | 表示MMI码成功。 |
| MMI_CODE_FAILED  | 1    | 表示MMI码失败。 |

## call.answerCall<sup>11+</sup>

answerCall(videoState: VideoStateType, callId: number\): Promise\<void\>

接听来电。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.ANSWER_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名                   | 类型                | 必填 | 说明                                                         |
| ----------------------- | ------------------- | ---- | ------------------------------------------------------------ |
| videoState| [VideoStateType](#videostatetype7)| 是   | 接听通话类型。                                                 |
| callId    | number                            | 是   | 呼叫Id。可以通过订阅callDetailsChange事件获得。                 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回接听电话结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

视频通话升级过程中取消升级。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.PLACE_CALL

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型                         | 必填 | 说明           |
| ------ | ---------------------------- | ---- | -------------- |
| callId | number                       | 是   | 呼叫Id。可以通过订阅callDetailsChange事件获得。|

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回升级过程中取消视频升级结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

设置使用指定的相机进行视频通话，cameraId为空表示关闭相机。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型                         | 必填 | 说明           |
| ------ | ---------------------------- | ---- | -------------- |
| callId | number                       | 是   | 呼叫Id。可以通过订阅callDetailsChange事件获得。       |
| cameraId | string                     | 是   | 相机Id。cameraId获取方式可参考[相机管理](../apis-camera-kit/js-apis-camera.md#getsupportedcameras)。|

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回设置开启，关闭，切换相机结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

设置本端预览画面窗口。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型                         | 必填 | 说明           |
| ------ | ---------------------------- | ---- | -------------- |
| callId | number                       | 是   | 呼叫Id。可以通过订阅callDetailsChange事件获得。       |
| surfaceId | string                    | 是   | 预览窗口Id。surfaceId获取方式可参考[XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid)。   |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回设置本端预览画面窗口结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

设置远端画面窗口。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型                         | 必填 | 说明           |
| ------ | ---------------------------- | ---- | -------------- |
| callId | number                       | 是   | 呼叫Id。可以通过订阅callDetailsChange事件获得。       |
| surfaceId | string                    | 是   | 画面窗口Id。surfaceId获取方式可参考[XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid)。   |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回设置远端画面窗口结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

设置视频通话画面显示方向为设备方向。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名 | 类型                                             | 必填 | 说明           |
| ------ | ----------------------------------------------- | ---- | -------------- |
| callId | number                                          | 是   | 呼叫Id。可以通过订阅callDetailsChange事件获得。|
| deviceDirection  | [DeviceDirection](#devicedirection11) | 是   | 画面方向。该参数根据设备方向获取。     |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 以Promise形式异步返回设置视频通话画面方向结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

订阅imsCallModeChange事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                       |
| -------- | ------------------------------------------ | ---- | -------------------------- |
| type     | string                                     | 是   | 视频通话时监听通话模式的变化，参数固定为'imsCallModeChange'。 |
| callback | Callback<[ImsCallModeInfo](#imscallmode8)> | 是   | 以回调函数的方式返回订阅imsCallModeChange事件的结果。         |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.on('imsCallModeChange', (data: call.ImsCallModeInfo) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('imsCallModeChange')<sup>11+</sup>

off\(type: 'imsCallModeChange', callback?: Callback\<ImsCallModeInfo\>\): void

取消订阅imsCallModeChange事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                               |
| -------- | ------------------------------------------ | ---- | ---------------------------------- |
| type     | string                                     | 是   | 视频通话时取消监听通话模式的变化，参数固定为'imsCallModeChange'。 |
| callback | Callback<[ImsCallModeInfo](#imscallmode8)> | 否   | 回调函数。不填该参数将不会收到取消订阅的处理结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.off('imsCallModeChange', (data: call.ImsCallModeInfo) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('callSessionEvent')<sup>11+</sup>

on\(type: 'callSessionEvent', callback: Callback\<CallSessionEvent\>\): void

订阅callSessionEvent事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| type     | string                                            | 是   | 视频通话时监听通话事件，参数固定为'callSessionEvent'。 |
| callback | Callback<[CallSessionEvent](#callsessionevent11)> | 是   | 以回调函数的方式返回订阅callSessionEvent事件的结果。  |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.on('callSessionEvent', (data: call.CallSessionEvent) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('callSessionEvent')<sup>11+</sup>

off\(type: 'callSessionEvent', callback?: Callback\<CallSessionEvent\>\): void

取消订阅callSessionEvent事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                               |
| -------- | ------------------------------------------ | ---- | ---------------------------------- |
| type     | string                                     | 是   | 视频通话时取消监听通话事件，参数固定为'callSessionEvent'。 |
| callback | Callback<[CallSessionEvent](#callsessionevent11)> | 否   | 回调函数。不填该参数将不会收到取消订阅的处理结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.off('callSessionEvent', (data: call.CallSessionEvent) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('peerDimensionsChange')<sup>11+</sup>

on\(type: 'peerDimensionsChange', callback: Callback\<PeerDimensionsDetail\>\): void

订阅peerDimensionsChange事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                       | 必填 | 说明                       |
| -------- | --------------------------------------------------------- | ---- | -------------------------- |
| type     | string                                                    | 是   | 视频通话时监听对端画面分辨率的变化，参数固定为'peerDimensionsChange'。 |
| callback | Callback<[PeerDimensionsDetail](#peerdimensionsdetail11)> | 是   | 以回调函数的方式返回订阅peerDimensionsChange事件的结果。              |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.on('peerDimensionsChange', (data: call.PeerDimensionsDetail) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('peerDimensionsChange')<sup>11+</sup>

off\(type: 'peerDimensionsChange', callback?: Callback\<PeerDimensionsDetail\>\): void

取消订阅peerDimensionsChange事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                       | 必填 | 说明                       |
| -------- | --------------------------------------------------------- | ---- | -------------------------- |
| type     | string                                                    | 是   | 视频通话时监听对端画面分辨率的变化，参数固定为'peerDimensionsChange'。 |
| callback | Callback<[PeerDimensionsDetail](#peerdimensionsdetail11)> | 否   |  回调函数。不填该参数将不会收到取消订阅的处理结果。                 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

call.off('peerDimensionsChange', (data: call.PeerDimensionsDetail) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.on('cameraCapabilitiesChange')<sup>11+</sup>

on\(type: 'cameraCapabilitiesChange', callback: Callback\<CameraCapabilities\>\): void

订阅cameraCapabilitiesChange事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明                       |
| -------- | ------------------------------------------------------| ---- | -------------------------- |
| type     | string                                                | 是   | 视频通话时监听本端相机画面分辨率的变化，参数固定为'cameraCapabilitiesChange'。 |
| callback | Callback<[CameraCapabilities](#cameracapabilities11)> | 是   | 以回调函数的方式返回订阅cameraCapabilitiesChange事件的结果。                 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
call.on('cameraCapabilitiesChange', (data: call.CameraCapabilities) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## call.off('cameraCapabilitiesChange')<sup>11+</sup>

off\(type: 'cameraCapabilitiesChange', callback?: Callback\<CameraCapabilities\>\): void

取消订阅cameraCapabilitiesChange事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CallManager

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明                               |
| -------- | ----------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                | 是   | 视频通话时取消监听本端相机画面分辨率的变化，参数固定为'cameraCapabilitiesChange'。 |
| callback | Callback<[CameraCapabilities](#cameracapabilities11)> | 否   | 回调函数。不填该参数将不会收到取消订阅的处理结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2. Incorrect parameters types;|
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
call.off('cameraCapabilitiesChange', (data: call.CameraCapabilities) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## VideoRequestResultType<sup>11+</sup>

视频通话升降级请求结果类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                                       | 值     | 说明     |
| ------------------------------------------ | ------ | --------|
| TYPE_REQUEST_SUCCESS                       | 0      | 请求成功。 |
| TYPE_REQUEST_FAILURE                       | 1      | 请求失败。 |
| TYPE_REQUEST_INVALID                       | 2      | 请求无效。 |
| TYPE_REQUEST_TIMED_OUT                     | 3      | 请求超时。 |
| TYPE_REQUEST_REJECTED_BY_REMOTE            | 4      | 请求被拒绝。 |
| TYPE_REQUEST_UPGRADE_CANCELED              | 5      | 请求升级取消。 |
| TYPE_DOWNGRADE_RTP_OR_RTCP_TIMEOUT         | 100    | 视频通话降级RTP或RTCP超时。 |
| TYPE_DOWNGRADE_RTP_AND_RTCP_TIMEOUT        | 101    | 视频通话降级RTP和RTCP超时。 |

## DeviceDirection<sup>11+</sup>

视频通话画面方向类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                 | 值     | 说明     |
| -------------------- | ------ | --------|
| DEVICE_DIRECTION_0   | 0      | 视频画面0度方向。 |
| DEVICE_DIRECTION_90   | 90     | 视频画面90度方向。 |
| DEVICE_DIRECTION_180  | 180    | 视频画面180度方向。 |
| DEVICE_DIRECTION_270  | 270    | 视频画面270度方向。 |

## CallSessionEventId<sup>11+</sup>

视频通话事件类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                           | 值     | 说明     |
| ------------------------------ | ------ | --------|
| EVENT_CONTROL_CAMERA_FAILURE   | 0      | 相机设置失败。 |
| EVENT_CONTROL_CAMERA_READY     | 1      | 相机设置成功。 |
| EVENT_DISPLAY_SURFACE_RELEASED  | 100    | 远端画面窗口释放。 |
| EVENT_PREVIEW_SURFACE_RELEASED  | 101    | 本端画面窗口释放。 |

## ImsCallModeInfo<sup>11+</sup>

视频通话模式信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称    |                    类型                             | 必填 | 说明           |
| ------- | -------------------------------------------------- | ---- | ------------- |
| callId  | number                                             | 是   | 呼叫Id。         |
| isRequestInfo| boolean                                       | 是   | 该信息是否为请求信息。|
| imsCallMode  | [ImsCallMode](#imscallmode8)                  | 是   | 视频通话模式。    |
| result  | [VideoRequestResultType](#videorequestresulttype11)| 是   | 通话结束提示信息。|

## CallSessionEvent<sup>11+</sup>

视频通话事件信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称    |                    类型                             | 必填 | 说明           |
| ------- | -------------------------------------------------- | ---- | ------------- |
| callId  | number                                             | 是   | 呼叫Id。         |
| eventId  | [CallSessionEventId](#callsessioneventid11)       | 是   | 视频通话事件。    |

## PeerDimensionsDetail<sup>11+</sup>

视频通话对端画面分辨率信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称    |     类型      | 必填 | 说明           |
| ------- | ------------ | ---- | ------------- |
| callId  | number       | 是   | 呼叫Id。         |
| width   | number       | 是   | 对端画面图像尺寸宽(像素)。  |
| height  | number       | 是   | 对端画面图像尺寸高(像素)。  |

## CameraCapabilities<sup>11+</sup>

视频通话本端相机画面分辨率信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称    |     类型      | 必填 | 说明           |
| ------- | ------------ | ---- | ------------- |
| callId  | number       | 是   | 呼叫Id。         |
| width   | number       | 是   | 本端画面图像尺寸宽(像素)。  |
| height  | number       | 是   | 本端画面图像尺寸高(像素)。  |

## NumberMarkInfo<sup>12+</sup>

电话号码的标记信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称    |     类型      | 必填 | 说明           |
| ------- | ------------ | ---- | ------------- |
| markType | [MarkType](#marktype12) | 是   | 号码的标记类型。 |
| markContent | string | 否  | 号码的标记内容，markType为MARK_TYPE_ENTERPRISE时，该字段返回信息为“姓名 工号”。 |
| markCount | number       | 否  | 号码的标记次数。 |
| markSource | string | 否 | 号码的标记来源供应商。 |
| isCloud | boolean | 否 | 号码的标记是否来自云端。 |
| markDetails<sup>14+</sup> | string | 否 | 号码标记的详细信息，markType为MARK_TYPE_ENTERPRISE时，该字段返回信息为“部门 职位”。 |

## MarkType<sup>12+</sup>

号码标记的类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CallManager

| 名称                           | 值     | 说明     |
| ------------------------------ | ------ | --------|
| MARK_TYPE_NONE | 0      | 没有标记。 |
| MARK_TYPE_CRANK | 1      | 骚扰电话。 |
| MARK_TYPE_FRAUD | 2    | 诈骗电话。 |
| MARK_TYPE_EXPRESS | 3    | 快递送餐。 |
| MARK_TYPE_PROMOTE_SALES | 4 | 广告推销。 |
| MARK_TYPE_HOUSE_AGENT | 5 | 房产中介。 |
| MARK_TYPE_INSURANCE | 6 | 保险理财。 |
| MARK_TYPE_TAXI | 7 | 出租车。 |
| MARK_TYPE_CUSTOM | 8 | 用户自定义。 |
| MARK_TYPE_OTHERS | 9 | 其他。 |
| MARK_TYPE_YELLOW_PAGE | 10 | 黄页。 |
| MARK_TYPE_ENTERPRISE<sup>14+</sup> | 11 | 企业联系人。 |
