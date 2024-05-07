# @ohos.security.certManager (Certificate Management) (System API)

The **certManager** module provides system-level certificate management capabilities to ensure secure use and management of certificates throughout their lifecycle (installation, storage, use, and destruction).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.security.certManager (Certificate Management)](js-apis-certManager.md).

## Modules to Import

```ts
import certManager from '@ohos.security.certManager';
```

## CMErrorCode

Enumerates the error codes used in the certificate management APIs.

**System capability**: System SystemCapability.Security.CertificateManager

| Name      | Value|  Description     |
| ---------- | ------ | --------- |
| CM_ERROR_NOT_SYSTEM_APP   | 202      | The caller is not a system application.<br> **System API**: This is a system API.|

## certManager.getAllAppPrivateCertificates

getAllAppPrivateCertificates(callback: AsyncCallback\<CMResult>): void

Obtains all private credentials. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER and ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**System capability**: System SystemCapability.Security.CertificateManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<[CMResult](js-apis-certManager.md#cmresult)> | Yes  | Callback invoked to return **credentialList** in [CMResult](js-apis-certManager.md#cmresult).|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**Example**
```ts
import certManager from '@ohos.security.certManager';

try {
  certManager.getAllAppPrivateCertificates((err, cmResult) => {
    if (err != null) {
      console.error("getAllAppPrivateCertificates error");
    } else {
      if (cmResult.credentialList == undefined) {
        console.log("[Callback]getAllAppPrivateCertificates result is undefined");
      } else {
        let list = cmResult.credentialList;
        console.log("[Callback]getAllAppPrivateCertificates success");
      }
    }
  });
} catch (error) {
  console.error("[Callback]getAllAppPrivateCertificates failed");
}
```


## certManager.getAllAppPrivateCertificates

getAllAppPrivateCertificates() : Promise\<CMResult>

Obtains all private credentials. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER and ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**System capability**: System SystemCapability.Security.CertificateManager

**System API**: This is a system API.

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise used to return **credentialList** in [CMResult](js-apis-certManager.md#cmresult).|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**Example**
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

try {
  certManager.getAllAppPrivateCertificates().then((cmResult) => {
    if (cmResult.credentialList == undefined) {
      console.log("[Promise]getAllAppPrivateCertificates result is undefined");
    } else {
      let list = cmResult.credentialList;
      console.log("[Promise]getAllAppPrivateCertificates success");
    }
  }).catch((err: BusinessError) => {
    console.error('[Promise]getAllAppPrivateCertificates failed');
  })
} catch (error) {
  console.error("[Promise]getAllAppPrivateCertificates failed");
}
```
