# @ohos.telephony.esim (eSIM Management) (System API)

The **esim** module provides APIs for eSIM management and eSIM services.

> **NOTE**
>
> The initial APIs of this module are supported since API version 18. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.telephony.esim (eSIM Management)](js-apis-esim.md).

## Modules to Import

```ts
import { eSIM } from '@kit.TelephonyKit';
```

## eSIM.getEid<sup>18+</sup>

getEid\(slotId: number\): Promise\<string\>

Obtains the EID of the embedded universal integrated circuit card (eUICC) in the specified slot.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_ESIM_STATE

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2  |

**Returns**

| Type                 | Description                               |
| --------------------- | ---------------------------------- |
| string | EID of the eUICC in the specified slot.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                | Error Message                        |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: <br>1. Mandatory parameters are left unspecified. <br>    2. Incorrect parameter types. <br>3. Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**Example**

```ts
import { eSIM } from '@kit.TelephonyKit';

let eid: string = eSIM.getEid(0);
console.log(`the EID is:` + eid);
```

## eSIM.getOsuStatus<sup>18+</sup>

getOsuStatus\(slotId: number\): Promise\<OsuStatus\>

Obtains the OS upgrade status for the eSIM in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_ESIM_STATE

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Returns**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise\<[OsuStatus](#osustatus18)\> |  Promise used to return the OS upgrade status.<br> 1. Updating.<br>   2. Update failed.<br>  3. Update succeeded.<br>  4. Already the latest version.<br> 5. Update service unavailable.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                | Error Message                              |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: <br>1. Mandatory parameters are left unspecified. <br>    2. Incorrect parameter types. <br>3. Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.getOsuStatus(0).then(() => {
    console.log(`getOsuStatus invoking succeeded.`);
}).catch((err: BusinessError) => {
    console.error(`getOsuStatus, promise: err->${JSON.stringify(err)}`);
});
```

## eSIM.startOsu<sup>18+</sup>

startOsu\(slotId: number\): Promise\<OsuStatus\>

Upgrades the OS if the OS version of the eSIM in the specified slot is not the latest. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_ESIM_STATE

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Returns**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise\<[OsuStatus](#osustatus18)\> |  Promise used to return the OS upgrade status.<br> 1. Updating.<br>   2. Update failed.<br>  3. Update succeeded.<br>  4. Already the latest version.<br> 5. Update service unavailable.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                | Error Message                              |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: <br>1. Mandatory parameters are left unspecified. <br>    2. Incorrect parameter types. <br>3. Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.startOsu(0).then(() => {
    console.log(`startOsu invoking succeeded.`);
}).catch((err: BusinessError) => {
    console.error(`startOsu, ErrorState: err->${JSON.stringify(err)}`);
});
```

## eSIM.getDownloadableProfileMetadata<sup>18+</sup>

getDownloadableProfileMetadata\(slotId: number, portIndex: number,
    profile: DownloadableProfile, forceDisableProfile: boolean\): Promise\<GetDownloadableProfileMetadataResult\>

Obtains the metadata of the downloadable profile. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_ESIM_STATE

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ----- | ----- |
| slotId              | number                                        | Yes| Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| portIndex           | number                                        | Yes| Port index of the slot.    |
| profile             | [DownloadableProfile](#downloadableprofile18) | Yes| Downloadable profile.|
| forceDisableProfile | boolean | Yes| Whether to forcibly diable the active SIM. If the value is **true**, the operation can be performed only after the active SIM card is disabled. If the value is **false**, the system displays a message asking the user to agree to the operation.|

**Returns**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise\<[GetDownloadableProfileMetadataResult](#getdownloadableprofilemetadataresult18)\> | Promise used to return the metadata of the downloadable profile.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                | Error Message                              |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: <br>1. Mandatory parameters are left unspecified. <br>    2. Incorrect parameter types. <br>3. Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

let profile: eSIM.DownloadableProfile={
  activationCode:'1',
  confirmationCode:'1',
  carrierName:'test',
  accessRules:[{
    certificateHashHexStr:'test',
    packageName:'com.example.testcoreservice',
    accessType:0
  }]
};

eSIM.getDownloadableProfileMetadata(0, 0, profile, true).then((data: eSIM.GetDownloadableProfileMetadataResult) => {
    console.log(`getDownloadableProfileMetadata, GetDownloadableProfileMetadataResult: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDownloadableProfileMetadata, GetDownloadableProfileMetadataResult: err->${JSON.stringify(err)}`);
});
```

## eSIM.getDownloadableProfiles<sup>18+</sup>

getDownloadableProfiles\(slotId: number, portIndex: number,
    forceDisableProfile: boolean\): Promise\<GetDownloadableProfilesResult\>

Obtains the list of downloadable profiles. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_ESIM_STATE

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ----- | ----- |
| slotId              | number  | Yes| Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| portIndex           | number  | Yes| Port index of the slot.|
| forceDisableProfile | boolean | Yes| Whether to forcibly diable the active SIM. If the value is **true**, the operation can be performed only after the active SIM card is disabled. If the value is **false**, the system displays a message asking the user to agree to the operation.|

**Returns**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise\<[GetDownloadableProfilesResult](#getdownloadableprofilesresult18)\> | Promise used to return the list of downloadable profiles.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                | Error Message                              |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: <br>1. Mandatory parameters are left unspecified. <br>    2. Incorrect parameter types. <br>3. Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.getDownloadableProfiles(0, 0, true).then((data: eSIM.GetDownloadableProfilesResult) => {
    console.log(`getDownloadableProfiles, GetDownloadableProfilesResult: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDownloadableProfiles, GetDownloadableProfilesResult: err->${JSON.stringify(err)}`);
});
```

## eSIM.downloadProfile<sup>18+</sup>

downloadProfile\(slotId: number, portIndex: number, profile: DownloadableProfile,
      configuration: DownloadConfiguration\): Promise\<DownloadProfileResult\>

Downloads a profile. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_ESIM_STATE

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ----- | ----- |
| slotId        | number                                            | Yes| Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| portIndex     | number                                            | Yes| Port index of the slot.|
| profile       | [DownloadableProfile](#downloadableprofile18)     | Yes| Downloadable profile.|
| configuration | [DownloadConfiguration](#downloadconfiguration18) | Yes| Download configuration.|

**Returns**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise\<[DownloadProfileResult](#downloadprofileresult18)\> | Promise used to return the profile download result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                | Error Message                              |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: <br>1. Mandatory parameters are left unspecified. <br>    2. Incorrect parameter types. <br>3. Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

let profile: eSIM.DownloadableProfile={
  activationCode:'1',
  confirmationCode:'1',
  carrierName:'test',
  accessRules:[{
    certificateHashHexStr:'test',
    packageName:'com.example.testcoreservice',
    accessType:0
  }]
};

let configuration: eSIM.DownloadConfiguration = {
  switchAfterDownload: true,
  forceDisableProfile: true,
  isAlowPpr: true,
};

eSIM.downloadProfile(0, 0, profile, configuration).then((data: eSIM.DownloadProfileResult) => {
    console.log(`downloadProfile, DownloadProfileResult: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`downloadProfile, DownloadProfileResult: err->${JSON.stringify(err)}`);
});
```

## eSIM.getEuiccProfileInfoList<sup>18+</sup>

getEuiccProfileInfoList\(slotId: number\): Promise\<GetEuiccProfileInfoListResult\>

Obtains the profile information list. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_ESIM_STATE

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ----- | ----- |
| slotId | number | Yes| Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Returns**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise\<[GetEuiccProfileInfoListResult](#geteuiccprofileinfolistresult18)\> | Promise used to return the profile information list.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                | Error Message                              |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: <br>1. Mandatory parameters are left unspecified. <br>    2. Incorrect parameter types. <br>3. Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.getEuiccProfileInfoList(0).then((data: eSIM.GetEuiccProfileInfoListResult) => {
    console.log(`getEuiccProfileInfoList, GetEuiccProfileInfoListResult: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getEuiccProfileInfoList, GetEuiccProfileInfoListResult: err->${JSON.stringify(err)}`);
});
```

## eSIM.getEuiccInfo<sup>18+</sup>

getEuiccInfo\(slotId: number\): Promise\<EuiccInfo\>

Obtains eUICC information. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_ESIM_STATE

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ----- | ----- |
| slotId | number | Yes| Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Returns**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise\<[EuiccInfo](#euiccinfo18)\> | Promise used to return the eUICC information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                | Error Message                              |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: <br>1. Mandatory parameters are left unspecified. <br>    2. Incorrect parameter types. <br>3. Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.getEuiccInfo(0).then((data: eSIM.EuiccInfo) => {
    console.log(`getEuiccInfo, EuiccInfo: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getEuiccInfo, EuiccInfo: err->${JSON.stringify(err)}`);
});
```

## eSIM.deleteProfile<sup>18+</sup>

deleteProfile\(slotId: number, iccid: string\): Promise\<ResultCode\>

Deletes a profile. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_ESIM_STATE

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ----- | ----- |
| slotId | number | Yes| Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| iccid  | string | Yes| Profile ID.|

**Returns**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise\<[ResultCode](#resultcode18)\> | Promise used to return the operation result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                | Error Message                              |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: <br>1. Mandatory parameters are left unspecified. <br>    2. Incorrect parameter types. <br>3. Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.deleteProfile(0, testId).then(() => {
    console.log(`deleteProfile invoking succeeded.`);
}).catch((err: BusinessError) => {
    console.error(`deleteProfile, ErrorState: err->${JSON.stringify(err)}`);
});
```

## eSIM.switchToProfile<sup>18+</sup>

switchToProfile\(slotId: number, portIndex: number, iccid: string,
    forceDisableProfile: boolean\): Promise\<ResultCode\>

Switches to the specified profile. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_ESIM_STATE

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ----- | ----- |
| slotId              | number  | Yes| Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| portIndex           | number  | Yes| Port index of the slot.|
| iccid               | string  | Yes| Profile ID.  |
| forceDisableProfile | boolean | Yes| Whether to forcibly diable the active SIM. If the value is **true**, the operation can be performed only after the active SIM card is disabled. If the value is **false**, the system displays a message asking the user to agree to the operation.|

**Returns**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise\<[ResultCode](#resultcode18)\> | Promise used to return the operation result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                | Error Message                              |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: <br>1. Mandatory parameters are left unspecified. <br>    2. Incorrect parameter types. <br>3. Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.switchToProfile(0, 0, testId, true).then(() => {
    console.log(`switchToProfile invoking succeeded.`);
}).catch((err: BusinessError) => {
    console.error(`switchToProfile, ErrorState: err->${JSON.stringify(err)}`);
});
```

## eSIM.setProfileNickname<sup>18+</sup>

setProfileNickname\(slotId: number, iccid: string, nickname: string\): Promise\<ResultCode\>

Sets a nickname for the specified profile. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_ESIM_STATE

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ----- | ----- |
| slotId   | number | Yes| Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| iccid    | string | Yes| Profile ID.|
| nickname | string | Yes| Profile nickname.|

**Returns**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise\<[ResultCode](#resultcode18)\> | Promise used to return the operation result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                | Error Message                              |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: <br>1. Mandatory parameters are left unspecified. <br>    2. Incorrect parameter types. <br>3. Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.setProfileNickname(0, testId, testName).then(() => {
    console.log(`setProfileNickname invoking succeeded.`);
}).catch((err: BusinessError) => {
    console.error(`setProfileNickname, ErrorState: err->${JSON.stringify(err)}`);
});
```

## eSIM.resetMemory<sup>18+</sup>

resetMemory\(slotId: number, options?: ResetOption\): Promise\<ResultCode\>

Clears all specific profiles and resets the eUICC. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_ESIM_STATE

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ----- | ----- |
| slotId  | number                        | Yes| Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| options | [ResetOption](#resetoption18) | No| Reset options.|

**Returns**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise\<[ResultCode](#resultcode18)\> | Promise used to return the operation result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                | Error Message                              |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: <br>1. Mandatory parameters are left unspecified. <br>    2. Incorrect parameter types. <br>3. Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.resetMemory(0).then(() => {
    console.log(`resetMemory invoking succeeded.`);
}).catch((err: BusinessError) => {
    console.error(`resetMemory, ErrorState: err->${JSON.stringify(err)}`);
});
```

## eSIM.reserveProfilesForFactoryRestore<sup>18+</sup>

reserveProfilesForFactoryRestore\(slotId: number\): Promise\<ResultCode\>

Restores factory settings and retains profiles. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_ESIM_STATE

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ----- | ----- |
| slotId | number | Yes| Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Returns**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise\<[ResultCode](#resultcode18)\> | Promise used to return the operation result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                | Error Message                              |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: <br>1. Mandatory parameters are left unspecified. <br>    2. Incorrect parameter types. <br>3. Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.reserveProfilesForFactoryRestore(0).then(() => {
    console.log(`reserveProfilesForFactoryRestore invoking succeeded.`);
}).catch((err: BusinessError) => {
    console.error(`reserveProfilesForFactoryRestore, ErrorState: err->${JSON.stringify(err)}`);
});
```

## eSIM.setDefaultSmdpAddress<sup>18+</sup>

setDefaultSmdpAddress\(slotId: number, address: string\): Promise\<ResultCode\>

Sets or updates the default SM-DP+ address stored in the eUICC. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_ESIM_STATE

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ----- | ----- |
| slotId  | number | Yes| Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| address | string | Yes| Default SM-DP+ address.|

**Returns**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise\<[ResultCode](#resultcode18)\> | Promise used to return the operation result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                | Error Message                              |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: <br>1. Mandatory parameters are left unspecified. <br>    2. Incorrect parameter types. <br>3. Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.setDefaultSmdpAddress(0, testAddress).then(() => {
    console.log(`setDefaultSmdpAddress invoking succeeded.`);
}).catch((err: BusinessError) => {
    console.error(`setDefaultSmdpAddress, ErrorState: err->${JSON.stringify(err)}`);
});
```

## eSIM.getDefaultSmdpAddress<sup>18+</sup>

getDefaultSmdpAddress\(slotId: number\): Promise\<string\>

Obtains the default SM-DP+ address stored in the eUICC. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_ESIM_STATE

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ----- | ----- |
| slotId | number | Yes| Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Returns**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise\<string\> | Promise used to return the SM-DP+ address.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                | Error Message                              |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: <br>1. Mandatory parameters are left unspecified. <br>    2. Incorrect parameter types. <br>3. Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.getDefaultSmdpAddress(0).then((data: string) => {
    console.log(`getDefaultSmdpAddress, result: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDefaultSmdpAddress, ErrorState: err->${JSON.stringify(err)}`);
});
```

## eSIM.cancelSession<sup>18+</sup>

cancelSession\(slotId: number, transactionId: string, cancelReason: CancelReason\): Promise\<ResultCode\>

Cancels a session. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_ESIM_STATE

**System capability**: SystemCapability.Telephony.CoreService.Esim

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ----- | ----- |
| slotId        | number                          | Yes| Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| transactionId | string                          | Yes| Service ID.|
| cancelReason  | [CancelReason](#cancelreason18) | Yes| Reason for canceling the session.|

**Returns**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise\<[ResultCode](#resultcode18)\> | Promise used to return the operation result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                | Error Message                              |
| --------------------- | ---------------------------------- |
| 201   | Permission denied. |
| 202   | Non-system applications use system APIs. |
| 401   | Parameter error. Possible causes: <br>1. Mandatory parameters are left unspecified. <br> 2. Incorrect parameter types. <br>3. Invalid parameter value.|
| 801   | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.cancelSession(0, testId, CancelReason::CANCEL_REASON_END_USER_REJECTION).then((data: string) => {
    console.log(`cancelSession, result: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`cancelSession execution failed: err->${JSON.stringify(err)}`);
});
```

## AccessRule<sup>18+</sup>

Defines access rules.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Type| Mandatory| Description|
| ----- | ----- | ----- | -----|
| certificateHashHexStr | string  |  Yes | Hex string of the certificate hash.|
| packageName           | string  |  Yes | Package name.|
| accessType            | number  |  Yes | Rule type.|

## DownloadableProfile<sup>18+</sup>

Defines a downloadable profile.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Type| Mandatory| Description|
| ----- | ----- | ----- | -----|
| activationCode   | string             |  Yes | Activation code. For a profile that does not require an activation code, the value may be left empty.|
| confirmationCode | string             |  No | Confirmation code.     |
| carrierName      | string             |  No | Carrier name.   |
| accessRules      | Array\<AccessRule> |  No | Access rule array.|

## GetDownloadableProfileMetadataResult<sup>18+</sup>

Obtains the metadata of the downloadable profile.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Type| Mandatory| Description|
| ----- | ----- | ----- | -----|
| downloadableProfile | DownloadableProfile  |  Yes | Downloadable profile.  |
| pprType             | number               |  Yes | Profile policy rule type.|
| pprFlag             | boolean              |  Yes | Profile policy rule flag.|
| iccid               | string               |  Yes | Profile ICCID.    |
| serviceProviderName | string               |  Yes | Service provider name.|
| profileName         | string               |  Yes | Profile name.|
| profileClass        | ProfileClass         |  Yes | Profile class.  |
| solvableErrors      | SolvableErrors       |  Yes | Solvable errors.|
| responseResult      | ResultCode           |  Yes | Operation result code.  |

## GetDownloadableProfilesResult<sup>18+</sup>

Obtains the list of default downloadable profiles.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Type| Mandatory| Description|
| ----- | ----- | ----- | -----|
| responseResult       | ResultCode                   |  Yes | Promise used to return the operation result.    |
| downloadableProfiles | Array\<DownloadableProfile>  |  Yes | Downloadable file array.|

## DownloadProfileResult<sup>18+</sup>

Defines the profile download result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Type| Mandatory| Description|
| ----- | ----- | ----- | -----|
| responseResult | ResultCode     |  Yes | Operation result code.|
| solvableErrors | SolvableErrors |  Yes | Solvable errors.|
| cardId         | number         |  Yes | Card ID.  |

## GetEuiccProfileInfoListResult<sup>18+</sup>

Obtains the profile information list.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Type| Mandatory| Description|
| ----- | ----- | ----- | -----|
| responseResult  |ResultCode            |  Yes | Promise used to return the operation result.   |
| profiles        | Array\<EuiccProfile> |  Yes | Profile array.     |
| isRemovable     | boolean              |  Yes | Checks whether the eUICC is removable.|

## OperatorId<sup>18+</sup>

Obtains information about the eUICC chip or device.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Type| Mandatory| Description|
| ----- | ----- | ----- | -----|
| mcc  | string |  Yes | Mobile country code (MCC).|
| mnc  | string |  Yes | Network code.    |
| gid1 | string |  Yes | Group ID level 1.  |
| gid2 | string |  Yes | Group ID level 2.  |

## EuiccProfile<sup>18+</sup>

Profile information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Type| Mandatory| Description|
| ----- | ----- | ----- | -----|
| iccid               | string             |  Yes | Profile ICCID.|
| nickName            | string             |  Yes | Profile nickname.|
| serviceProviderName | string             |  Yes | Service provider name.|
| profileName         | string             |  Yes | Profile name.  |
| state               | ProfileState       |  Yes | Profile status.|
| profileClass        | ProfileClass       |  Yes | Profile class.    |
| operatorId          | OperatorId         |  Yes | Operation ID of the profile.|
| policyRules         | PolicyRules        |  Yes | Profile policy rules.  |
| accessRules         | Array\<AccessRule> |  Yes | Profile access rules.  |

## EuiccInfo<sup>18+</sup>

Defines the eUICC information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Type| Mandatory| Description|
| ----- | ----- | ----- | -----|
| osVersion | string |  Yes | OS version.|

## ResetOption<sup>18+</sup>

Defines the reset options.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Value| Description|
| ----- | ----- | ----- |
|DELETE_OPERATIONAL_PROFILES       | 1      | Deletion of all operational profiles.|
|DELETE_FIELD_LOADED_TEST_PROFILES | 1 << 1 | Deletion of the downloaded test profiles.|
|RESET_DEFAULT_SMDP_ADDRESS        | 1 << 2 | Resetting of the default SM-DP+ address.|

## OsuStatus<sup>18+</sup>

Defines the OS upgrade status.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Value| Description|
| ----- | ----- | ----- |
|EUICC_UPGRADE_IN_PROGRESS         | 1 | Upgrading.|
|EUICC_UPGRADE_FAILED              | 2 | Upgrade failed.|
|EUICC_UPGRADE_SUCCESSFUL          | 3 | Update succeeded.|
|EUICC_UPGRADE_ALREADY_LATEST      | 4 | Already the latest version.|
|EUICC_UPGRADE_SERVICE_UNAVAILABLE | 5 | Update service unavailable.|

## ResultCode<sup>18+</sup>

Enumerates the result codes.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Value| Description|
| ----- | ----- | ----- |
| RESULT_SOLVABLE_ERRORS                                   | -2  | Solving of the solvable errors required.       |
| RESULT_MUST_DISABLE_PROFILE                              | -1  | Disabling of the active profile required.|
| RESULT_OK                                                | 0   | Operation success.|
| RESULT_GET_EID_FAILED                                    | 201 | Failed to obtain the EID.|
| RESULT_ACTIVATION_CODE_CHANGED                           | 203 | Activation code changed upon user confirmation.  |
| RESULT_ACTIVATION_CODE_INVALID                           | 204 | Invalid activation code. |
| RESULT_SMDP_ADDRESS_INVALID                              | 205 | Invalid SM-DP+ server address.|
| RESULT_EUICC_INFO_INVALID                                | 206 | Invalid eUICC information.     |
| RESULT_TLS_HANDSHAKE_FAILED                              | 207 | TLS handshake failed.         |
| RESULT_CERTIFICATE_IO_ERROR                              | 208 | Certificate network connection error.     |
| RESULT_CERTIFICATE_RESPONSE_TIMEOUT                      | 209 | Invalid certificate address or response timeout.|
| RESULT_AUTHENTICATION_FAILED                             | 210 | Authentication failed.    |
| RESULT_RESPONSE_HTTP_FAILED                              | 211 | HTTP response failed.|
| RESULT_CONFIRMATION_CODE_INCORRECT                       | 212 | Incorrect confirmation code.|
| RESULT_EXCEEDED_CONFIRMATION_CODE_TRY_LIMIT              | 213 | Maximum confirmation code retries reached.     |
| RESULT_NO_PROFILE_ON_SERVER                              | 214 | No downloadable profile available on the server.|
| RESULT_TRANSACTION_ID_INVALID                            | 215 | Invalid transaction ID.   |
| RESULT_SERVER_ADDRESS_INVALID                            | 216 | Invalid server address.|
| RESULT_GET_BOUND_PROFILE_PACKAGE_FAILED                  | 217 | Failed to obtain the BPP.   |
| RESULT_USER_CANCEL_DOWNLOAD                              | 218 | Download cancelled by the user.  |
| RESULT_SERVER_UNAVAILABLE                                | 220 | Carrier server unavailable.|
| RESULT_PROFILE_NON_DELETE                                | 223 | File deletion not allowed by the PPR rule.   |
| RESULT_SMDP_ADDRESS_INCORRECT                            | 226 | Incorrect SMDP server address.  |
| RESULT_ANALYZE_AUTHENTICATION_SERVER_RESPONSE_FAILED     | 228 | Failed to parse the server authentication response.|
| RESULT_ANALYZE_AUTHENTICATION_CLIENT_RESPONSE_FAILED     | 229 | Failed to parse the client authentication response.|
| RESULT_ANALYZE_AUTHENTICATION_CLIENT_MATCHING_ID_REFUSED | 231 | Failed to parse the client authentication response because the matching ID was rejected.|
| RESULT_PROFILE_TYPE_ERROR_AUTHENTICATION_STOPPED         | 233 | Authentication stopped due to incorrect profile type.    |
| RESULT_CARRIER_SERVER_REFUSED_ERRORS                     | 249 | Rejection cause code of the carrier server, which is 3.8.|
| RESULT_CERTIFICATE_INVALID                               | 251 | Invalid certificate.|
| RESULT_OUT_OF_MEMORY                                     | 263 | Failed to install the profile due to insufficient memory.|
| RESULT_PPR_FORBIDDEN                                     | 268 | Operation not allowed by the PPR rule.|
| RESULT_NOTHING_TO_DELETE                                 | 270 | No configuration file for deletion.|
| RESULT_PPR_NOT_MATCH                                     | 276 | PPR rule mismatch.  |
| RESULT_CAT_BUSY                                          | 283 | Session in progress.  |
| RESULT_PROFILE_EID_INVALID                               | 284 | eSIM profile in use or invalid.|
| RESULT_DOWNLOAD_TIMEOUT                                  | 287 | Download timeout.                  |
| RESULT_SGP_22_OTHER                                      | 400 | Other errors defined in SGP.22.     |

## CancelReason<sup>18+</sup>

Reason for canceling the session.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Value| Description|
| ----- | ----- | ----- |
|CANCEL_REASON_END_USER_REJECTION | 0 | The user has rejected the download.         |
|CANCEL_REASON_POSTPONED          | 1 | The download has been delayed. You can restart it later.|
|CANCEL_REASON_TIMEOUT            | 2 | The download has timed out. You can restart it later.|
|CANCEL_REASON_PPR_NOT_ALLOWED    | 3 | The installation cannot be performed because the authorization table or other installed profile on the eUICC does not allow its policy rules.|

## ProfileState<sup>18+</sup>

Enumerates the profile states.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Value| Description|
| ----- | ----- | ----- |
|PROFILE_STATE_UNSPECIFIED | -1 | Profile status unspecified.|
|PROFILE_STATE_DISABLED    | 0  | Profile disabled.  |
|PROFILE_STATE_ENABLED     | 1  | Profile enabled.|

## ProfileClass<sup>18+</sup>

Enumerates the profile classes.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Value| Description|
| ----- | ----- | ----- |
|PROFILE_CLASS_UNSPECIFIED  | -1 | Profile class unspecified.          |
|PROFILE_CLASS_TEST         | 0  | Test profile.              |
|PROFILE_CLASS_PROVISIONING | 1  | Profile preloaded to the eUICC.  |
|PROFILE_CLASS_OPERATIONAL  | 2  | Profile that can be preloaded or downloaded.|

## PolicyRules<sup>18+</sup>

Enumerates the profile policy rules.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Value| Description|
| ----- | ----- | ----- |
|POLICY_RULE_DISABLE_NOT_ALLOWED | 1      | A profile cannot be disabled after being enabled.|
|POLICY_RULE_DELETE_NOT_ALLOWED  | 1 << 1 | The profile cannot be deleted.         |
|POLICY_RULE_DISABLE_AND_DELETE  | 1 << 2 | A profile must be deleted immediately after being enabled.     |

## SolvableErrors<sup>18+</sup>

Enumerates the solvable errors.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Value| Description|
| ----- | ----- | ----- |
|SOLVABLE_ERROR_NEED_CONFIRMATION_CODE | 1 << 0 | The user needs to enter the confirmation code during the download.               |
|SOLVABLE_ERROR_NEED_POLICY_RULE       | 1 << 1 | The download process requires user consent to allow the profile policy rules.|

## DownloadConfiguration<sup>18+</sup>

Defines the download configuration.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService.Esim

| Name| Type| Mandatory| Description|
| ----- | ----- | ----- | -----|
|switchAfterDownload | boolean | Yes| Whether to enable the profile after being downloaded.|
|forceDisableProfile | boolean | Yes| Whether to forcibly disable a profile.        |
|isPprAllowed        | boolean | Yes| Whether to allow the service provider to enforce the profile policy rule after the user is informed of its restrictions.|
