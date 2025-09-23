# @ohos.data.unifiedDataChannel (Unified Data Channel) (System API)

As a part of the Unified Data Management Framework (UDMF), the **unifiedDataChannel** module provides APIs to control the sharing range of the data in the drag data channel.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.data.unifiedDataChannel](js-apis-data-unifiedDataChannel.md).

## Import modules.

```ts
import { unifiedDataChannel } from '@kit.ArkData';
```

## Intention

Enumerates the data channel types supported by the UDMF. It is used to identify different service scenarios, to which the UDMF data channels apply.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Value    | Description                               |
| ---- | ------ | ----------------------------------- |
| DRAG<sup>12+</sup> | 'Drag' | Channel in which data can be dragged.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|

## unifiedDataChannel.setAppShareOptions<sup>12+</sup>

setAppShareOptions(intention: Intention, shareOptions: ShareOptions): void

Sets the [ShareOptions](js-apis-data-unifiedDataChannel.md#shareoptions12) for the application data. Currently, only the drag data channel is supported.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name     | Type                        | Mandatory| Description                          |
|----------|----------------------------|----|------------------------------|
| intention | [Intention](#intention) | Yes | Type of the data channel. Currently, only the data channel of the **DRAG** type is supported.|
| shareOptions | [ShareOptions](js-apis-data-unifiedDataChannel.md#shareoptions12) | Yes | Sharing range of the [UnifiedData](js-apis-data-unifiedDataChannel.md#unifieddata).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [UDMF Error Codes](errorcode-udmf.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 202          | Permission verification failed, application which is not a system application uses system API. |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 20400001     | Settings already exist.                                      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  unifiedDataChannel.setAppShareOptions(unifiedDataChannel.Intention.DRAG, unifiedDataChannel.ShareOptions.IN_APP);
  console.info(`[UDMF]setAppShareOptions success. `);
}catch (e){
  let error: BusinessError = e as BusinessError;
  console.error(`[UDMF]setAppShareOptions throws an exception. code is ${error.code},message is ${error.message} `);
}
```

## unifiedDataChannel.removeAppShareOptions<sup>12+</sup>

removeAppShareOptions(intention: Intention): void

Removes the data control set by [setAppShareOptions](#unifieddatachannelsetappshareoptions12).

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name   | Type                   | Mandatory| Description                                                        |
| --------- | ----------------------- | ---- | ------------------------------------------------------------ |
| intention | [Intention](#intention) | Yes  | Type of the data channel. Currently, only the data channel of the **DRAG** type is supported.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 202          | Permission verification failed, application which is not a system application uses system API. |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  unifiedDataChannel.removeAppShareOptions(unifiedDataChannel.Intention.DRAG);
  console.info(`[UDMF]removeAppShareOptions success. `);
}catch (e){
  let error: BusinessError = e as BusinessError;
  console.error(`[UDMF]removeAppShareOptions throws an exception. code is ${error.code},message is ${error.message} `);
}
```
