# @ohos.telephony.esim (eSIM Management)

The **esim** module provides basic eSIM management capabilities, including checking whether a specified card slot supports the eSIM function.

> **NOTE**
>
> The initial APIs of this module are supported since API version 18. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>

## Modules to Import

```ts
import { eSIM } from '@kit.TelephonyKit';
```

## eSIM.isSupported<sup>18+</sup>

isSupported\(slotId: number\): boolean

Checks whether the specified card slot supports the eSIM function.

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID. <br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Returns**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| boolean | A boolean value indicating whether the specified card slot supports the eSIM function. The value **true** indicates that the card slot supports the eSIM function, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID             | Error Message                          |
| --------------------- | ---------------------------------- |
| 401 | Invalid parameter value.     |
|3120001| Service connection failed. |
|3120002| System internal error.     |

**Example**

```ts
import { eSIM } from '@kit.TelephonyKit';

let isSupported: boolean = eSIM.isSupported(0);
console.log(`the esim is Supported:` + isSupported);
```

## eSIM.addProfile<sup>18+</sup>

addProfile\(profile: DownloadableProfile\): Promise\<boolean\>

Launches the download page for the user to add a single profile. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_TELEPHONY_ESIM_STATE_OPEN

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| profile | DownloadableProfile | Yes  | Profile that can be downloaded.|

**Returns**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise\<boolean\> | Promise used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID             | Error Message                          |
| --------------------- | ---------------------------------- |
| 201 | Permission denied.           |
| 401 | Invalid parameter value.     |
| 801 | Capability not supported.    |
|3120001| Service connection failed. |
|3120002| System internal error.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

let profile: eSIM.DownloadableProfile = {
  activationCode:'1',
  confirmationCode:'1',
  carrierName:'test',
  accessRules:[{
    certificateHashHexStr:'test',
    packageName:'com.example.testcoreservice',
    accessType:0
  }]
};

eSIM.addProfile(profile).then(() => {
    console.log(`addProfile invoking succeeded.`);
}).catch((err: BusinessError) => {
    console.error(`addProfile, promise: err->${JSON.stringify(err)}`);
});
```

## DownloadableProfile<sup>18+</sup>

Defines a downloadable profile.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Type| Mandatory| Description|
| ----- | ----- | ----- | -----|
| activationCode   | string             |  Yes | Activation code. For a profile that does not require an activation code, the value may be left empty.|
| confirmationCode | string             |  No | Confirmation code.     |
| carrierName      | string             |  No | Carrier name.   |
| accessRules      | Array\<AccessRule> |  No | Access rule array.|
