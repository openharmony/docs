# @ohos.deviceAttest (Device Attestation) (System API)

The **deviceAttest** module provides attestation of devices in OpenHarmony by comparing the device information with that stored in the cloud.
You can use the APIs provided by the **deviceAttest** module to obtain the device attestation result.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import deviceAttest from '@ohos.deviceAttest';
```

## deviceAttest.getAttestStatus

getAttestStatus(callback: AsyncCallback&lt;AttestResultInfo&gt;) : void

Obtains details about the device attestation result from the cloud. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.XTS.DeviceAttest

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;[AttestResultInfo](#attestresultinfo)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **error** is **undefined**, and **result** is the obtained [AttestResultInfo](#attestresultinfo). Otherwise, **error** is an error object.|

**Error codes**

| ID | Error Message            |
|----------|----------------------|
| 20000001 | system service exception. |

**Example**

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

Obtains details about the device attestation result from the cloud. This API uses a promise to return the result.

**System capability**: SystemCapability.XTS.DeviceAttest

**Return value**

| Type                                                 | Description                           |
| ----------------------------------------------------- | ------------------------------- |
| Promise&lt;[AttestResultInfo](#attestresultinfo)&gt; | Promise used to return the device attestation information obtained.|

**Error codes**

| ID | Error Message            |
|----------|----------------------|
| 20000001 | system service exception. |

**Example**

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

Obtains details about the device attestation result from the cloud synchronously.

**System capability**: SystemCapability.XTS.DeviceAttest

**Return value**

| Type                                                 | Description                           |
| ----------------------------------------------------- | ------------------------------- |
| [AttestResultInfo](#attestresultinfo) | Returns the device attestation information obtained.|

**Error codes**

| ID | Error Message            |
|----------|----------------------|
| 20000001 | system service exception. |

**Example**

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

Defines the device attestation result information.

**System capability**: SystemCapability.XTS.DeviceAttest

| Name                 | Type                 | Readable| Writable| Description                  |
| --------------------- | --------------------- | ---- | ---- | ---------------------- |
| authResult            | number               | Yes  | No  | Device hardware attestation result.   |
| softwareResult        | number               | Yes  | No  | Device software attestation result.   |
| softwareResultDetail  | Array&lt;number&gt;  | Yes  | No  | Detailed information about the device software attestation result.<br> - **softwareResultDetail[0]**: version ID attestation result.<br>- **softwareResultDetail[1]**: attestation result of the security patch label.<br>- **softwareResultDetail[2]**: version hash attestation result.<br>- **softwareResultDetail[3]**: attestation result of the system capability set.<br>- **softwareResultDetail[4]**: reserved. |
| ticket                | string               | Yes  | No  | Soft certificate delivered by the cloud.<br>If the device hardware attestation is successful, a value is returned. If the attestation fails, this parameter is empty.       |

> **NOTE**
>
> - The attestation result of device hardware and software information can be any of the following:<br> - **-2**: No attestation is performed.<br>- **-1**: The attestation fails.<br>- **0**: The attestation is successful.
