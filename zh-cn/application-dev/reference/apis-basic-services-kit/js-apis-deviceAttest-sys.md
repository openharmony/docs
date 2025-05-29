# @ohos.deviceAttest (设备证明)(系统接口)

为了证明设备是OpenHarmony生态中的合法设备，设备证明模块会把设备信息通过云端进行一致性合法校验。
通过本模块接口，可查询设备在云端校验的结果。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。

## 导入模块

```ts
import deviceAttest from '@ohos.deviceAttest';
```

## deviceAttest.getAttestStatus

getAttestStatus(callback: AsyncCallback&lt;AttestResultInfo&gt;) : void

获取端云校验结果的详细信息。使用callback异步回调。

**系统能力：** SystemCapability.XTS.DeviceAttest

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;[AttestResultInfo](#attestresultinfo)&gt; | 是   | 回调函数。当获取端云校验结果的详细信息成功，error为undefined，result为获取到的[AttestResultInfo](#attestresultinfo)；否则为错误对象。 |

**错误码：**  
以下错误码的详细介绍请参见[设备证明错误码](./errorcode-deviceAttest.md)和[通用错误码说明文档](../errorcode-universal.md)。  
| 错误码ID  | 错误信息             |
|----------|----------------------|
| 202     | This api is system api, Please use the system application to call this api. |
| 401     | Input parameters wrong, the number of parameters is incorrect, or the type of parameters is incorrect. |
| 20000001 | System service exception, please try again or reboot your device. |

**示例：**

```ts
import base from '@ohos.base';

try {
    deviceAttest.getAttestStatus((error: base.BusinessError, value: deviceAttest.AttestResultInfo) => {
    if (typeof error != 'undefined') {
        console.info("error code:" + error.code + " message:" + error.message);
    } else {
        console.info("auth:" + value.authResult + " software:" + value.softwareResult + " ticket:" + value.ticket);
        console.info("versionIdResult:" + value.softwareResultDetail[0],
        " patchLevelResult:" + value.softwareResultDetail[1],
        " rootHashResult:" + value.softwareResultDetail[2],
        " PCIDResult:" + value.softwareResultDetail[3],
        " reserver:" + value.softwareResultDetail[4]);
    }
    })
} catch (error) {
    let code: number = (error as base.BusinessError).code;
    let message: string = (error as base.BusinessError).message;
    console.info("error code:" + code + " message:" + message);
}
```

## deviceAttest.getAttestStatus

getAttestStatus() : Promise&lt;AttestResultInfo&gt;

获取端云校验结果的详细信息。使用Promise异步回调。

**系统能力：** SystemCapability.XTS.DeviceAttest

**返回值：**

| 类型                                                  | 说明                            |
| ----------------------------------------------------- | ------------------------------- |
| Promise&lt;[AttestResultInfo](#attestresultinfo)&gt; | Promise对象，返回端云校验结果的详细信息。 |

**错误码：**  
以下错误码的详细介绍请参见[设备证明错误码](./errorcode-deviceAttest.md)和[通用错误码说明文档](../errorcode-universal.md)。  
| 错误码ID  | 错误信息             |
|----------|----------------------|
| 202     | This api is system api, Please use the system application to call this api. |
| 401     | Input parameters wrong, the number of parameters is incorrect, or the type of parameters is incorrect. |
| 20000001 | System service exception, please try again or reboot your device. |

**示例：**

```ts
import base from '@ohos.base';

try {
    deviceAttest.getAttestStatus().then((value: deviceAttest.AttestResultInfo) => {
    console.info("auth:" + value.authResult + " software:" + value.softwareResult + " ticket:" + value.ticket);
    console.info("versionIdResult:" + value.softwareResultDetail[0],
        " patchLevelResult:" + value.softwareResultDetail[1],
        " rootHashResult:" + value.softwareResultDetail[2],
        " PCIDResult:" + value.softwareResultDetail[3],
        " reserver:" + value.softwareResultDetail[4]);
    }).catch((error: base.BusinessError) => {
        console.info("error code:" + error.code + " message:" + error.message);
    });
} catch (error) {
    let code: number = (error as base.BusinessError).code;
    let message: string = (error as base.BusinessError).message;
    console.info("error code:" + code + " message:" + message);
}
```

## deviceAttest.getAttestStatusSync

getAttestStatusSync() : AttestResultInfo

以同步方式获取端云校验结果的详细信息。

**系统能力：** SystemCapability.XTS.DeviceAttest

**返回值：**

| 类型                                                  | 说明                            |
| ----------------------------------------------------- | ------------------------------- |
| [AttestResultInfo](#attestresultinfo) | 返回端云校验结果的详细信息。 |

**错误码：**  
以下错误码的详细介绍请参见[设备证明错误码](./errorcode-deviceAttest.md)和[通用错误码说明文档](../errorcode-universal.md)。  
| 错误码ID  | 错误信息             |
|----------|----------------------|
| 202     | This api is system api, Please use the system application to call this api. |
| 401     | Input parameters wrong, the number of parameters is incorrect, or the type of parameters is incorrect. |
| 20000001 | System service exception, please try again or reboot your device. |

**示例：**

```ts
import base from '@ohos.base';

try {
    let value: deviceAttest.AttestResultInfo = deviceAttest.getAttestStatusSync();
    console.info("auth:" + value.authResult + " software:" + value.softwareResult + " ticket:" + value.ticket);
    console.info("versionIdResult:" + value.softwareResultDetail[0],
    " patchLevelResult:" + value.softwareResultDetail[1],
    " rootHashResult:" + value.softwareResultDetail[2],
    " PCIDResult:" + value.softwareResultDetail[3],
    " reserver:" + value.softwareResultDetail[4]);
} catch (error) {
    let code: number = (error as base.BusinessError).code;
    let message: string = (error as base.BusinessError).message;
    console.info("error code:" + code + " message:" + message);
}
```

## AttestResultInfo

端云校验结果的详细信息。

**系统能力：** SystemCapability.XTS.DeviceAttest

| 名称                  | 类型                  | 可读 | 可写 | 说明                   |
| --------------------- | --------------------- | ---- | ---- | ---------------------- |
| authResult            | number               | 是   | 否   | 设备硬件信息校验结果。    |
| softwareResult        | number               | 是   | 否   | 设备软件信息校验结果。    |
| softwareResultDetail  | Array&lt;number&gt;  | 是   | 否   | 设备软件信息校验结果详细说明：<br/> - softwareResultDetail[0]：版本Id的校验结果。<br/>- softwareResultDetail[1]：安全补丁标签的校验结果。<br/>- softwareResultDetail[2]：版本Hash的校验结果。<br/>- softwareResultDetail[3]：系统能力集合的校验结果。<br/>- softwareResultDetail[4]：保留位。  |
| ticket                | string               | 是   | 否   | 云侧下发的软证书。<br/>设备硬件信息校验结果通过后有值；校验结果失败，该值为空。        |

> **说明：**
>
> - 设备硬件信息和设备软件信息的校验结果返回值有-2、-1、0。-2表示未认证，-1表示认证失败，0表示认证通过。
