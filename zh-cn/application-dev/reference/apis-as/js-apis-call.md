# @ohos.telephony.call (拨打电话)

该模块提供跳转到拨号界面，并显示待拨出号码的功能。

如需订阅通话状态请使用[`observer.on('callStateChange')`](../apis/js-apis-observer.md#observeroncallstatechange)。

>**说明：**
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import call from '@ohos.telephony.call';
```


## call.makeCall<sup>7+</sup>

makeCall\(phoneNumber: string, callback: AsyncCallback\<void\>\): void

跳转到拨号界面，并显示待拨出的号码。使用callback异步回调。

**系统能力**：SystemCapability.Applications.Contacts

**参数：**

| 参数名      | 类型                      | 必填 | 说明                                       |
| ----------- | ------------------------- | ---- | ------------------------------------------ |
| phoneNumber | string                    | 是   | 电话号码。                                 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 以callback形式异步返回跳转拨号界面的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)和[通用错误码](../../reference/errorcodes/errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

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

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)和[通用错误码](../../reference/errorcodes/errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

call.makeCall("138xxxxxxxx").then(() => {
    console.log(`makeCall success`);
}).catch((err: BusinessError) => {
    console.error(`makeCall fail, promise: err->${JSON.stringify(err)}`);
});
```

