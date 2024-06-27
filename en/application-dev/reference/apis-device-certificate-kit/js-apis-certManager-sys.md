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
| callback | AsyncCallback\<[CMResult](js-apis-certManager.md#cmresult)> | Yes  | Callback invoked to return the private credentials (that is, **credentialList** in [CMResult](js-apis-certManager.md#cmresult)) obtained.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error. |

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
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise used to return the private credentials (that is, **credentialList** in [CMResult](js-apis-certManager.md#cmresult)) obtained.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 17500001 | Internal error. |

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

## certManager.getAllSystemAppCertificates<sup>12+</sup>

getAllSystemAppCertificates() : Promise\<CMResult>

Obtains all system credentials. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**System API**: This is a system API.

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise used to return the system credentials (that is, **credentialList** in [CMResult](js-apis-certManager.md#cmresult)) obtained.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 17500001 | Internal error. |

**Example**
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

try {
  certManager.getAllSystemAppCertificates().then((cmResult) => {
    if (cmResult.credentialList == undefined) {
      console.log("[Promise]getAllSystemAppCertificates result is undefined");
    } else {
      let list = cmResult.credentialList;
      console.log("[Promise]getAllSystemAppCertificates success");
    }
  }).catch((err: BusinessError) => {
    console.error('[Promise]getAllSystemAppCertificates failed');
  })
} catch (error) {
  console.error("[Promise]getAllSystemAppCertificates failed");
}
```
