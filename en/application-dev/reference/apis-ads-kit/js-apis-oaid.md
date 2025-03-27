# @ohos.identifier.oaid (OAID)

The **OAID** module provides APIs for obtaining Open Anonymous Device Identifiers (OAIDs).

> **NOTE**
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> To use the APIs for obtaining OAIDs, you must [request the ohos.permission.APP_TRACKING_CONSENT permission](../../security/AccessToken/request-user-authorization.md).

## Modules to Import

```ts
import { identifier } from '@kit.AdsKit';
```

## identifier.getOAID

getOAID(): Promise&lt;string&gt;

Obtains an OAID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.APP_TRACKING_CONSENT

**System capability**: SystemCapability.Advertising.OAID

**Return value**

| Type                   | Description                                                                                                                                                                                                                                                                                                                                                                    | 
|-----------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Promise&lt;string&gt; | Promise used to return the OAID.<br>1. If the application has configured the permission **ohos.permission.APP_TRACKING_CONSENT** and the permission is allowed, the OAID is returned.<br>2. If the application has configured the permission **ohos.permission.APP_TRACKING_CONSENT** and the permission is disallowed, 00000000-0000-0000-0000-000000000000 is returned.<br>3. If the application has not configured the permission **ohos.permission.APP_TRACKING_CONSENT**, 00000000-0000-0000-0000-000000000000 is returned.| 

**Error codes**

For details about the following error codes, see [OAID Error Codes](errorcode-oaid.md).

| ID   | Error Message                            | 
|----------|----------------------------------|
| 17300001 | System&nbsp;internal&nbsp;error. | 

**Example**

```ts
import { identifier } from '@kit.AdsKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

identifier.getOAID().then((data) => {
  const oaid: string = data;
  hilog.info(0x0000, 'testTag', `Succeed in getting oaid. Oaid is ${oaid}`);
}).catch((err: BusinessError) => {
  hilog.error(0x0000, 'testTag', `Fail to get oaid. Code is ${err.code}, message is ${err.message}`);
})
```

## identifier.getOAID

getOAID(callback: AsyncCallback&lt;string&gt;): void

Obtains an OAID. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.APP_TRACKING_CONSENT

**System capability**: SystemCapability.Advertising.OAID

**Parameters**

| Name     | Type                         | Mandatory| Description                                                                                                                                                                                                                                                                                                                                                               | 
|----------|-----------------------------|----|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| callback | AsyncCallback&lt;string&gt; | Yes | Callback used to return the OAID.<br>1. If the application has configured the permission **ohos.permission.APP_TRACKING_CONSENT** and the permission is allowed, the OAID is returned.<br>2. If the application has configured the permission **ohos.permission.APP_TRACKING_CONSENT** and the permission is disallowed, 00000000-0000-0000-0000-000000000000 is returned.<br>3. If the application has not configured the permission **ohos.permission.APP_TRACKING_CONSENT**, 00000000-0000-0000-0000-000000000000 is returned.| 

**Error codes**

For details about the following error codes, see [OAID Error Codes](errorcode-oaid.md).

| ID   | Error Message                            | 
|----------|----------------------------------|
| 17300001 | System&nbsp;internal&nbsp;error. | 

**Example**

```ts
import { identifier } from '@kit.AdsKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
 
identifier.getOAID((err: BusinessError, data: string) => {
  if (err.code) {
    hilog.error(0x0000, 'testTag', `Fail to get oaid. Code is ${err.code}, message is ${err.message}`);
  } else {
    const oaid: string = data;
    hilog.info(0x0000, 'testTag', `Succeed in getting oaid. Oaid is ${oaid}`);
  }
});
```
