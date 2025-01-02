# @ohos.security.certManager (Certificate Management) (System API)

The **certManager** module provides system-level certificate management capabilities to ensure secure use and management of certificates throughout their lifecycle (installation, storage, use, and destruction).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.security.certManager (Certificate Management)](js-apis-certManager.md).

## Modules to Import

```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
```

## CMErrorCode

Enumerates the error codes used in the certificate management APIs.

**System capability**: System SystemCapability.Security.CertificateManager

| Name      | Value |  Description     |
| ---------- | ------ | --------- |
| CM_ERROR_NOT_SYSTEM_APP   | 202      | The caller is not a system application.<br>**System API**: This is a system API. |

## certificateManager.getAllAppPrivateCertificates

getAllAppPrivateCertificates(callback: AsyncCallback\<CMResult>): void

Obtains all private credentials. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER and ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**System capability**: System SystemCapability.Security.CertificateManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                       | Mandatory | Description                                                        |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[CMResult](js-apis-certManager.md#cmresult)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is **credentialList** in the [CMResult](#cmresult) object. Otherwise, **err** is an error object. |

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error. |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';

try {
  certificateManager.getAllAppPrivateCertificates((err, cmResult) => {
    if (err != null) {
      console.error(`Failed to get all app private certificates. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (cmResult.credentialList == undefined) {
        console.info('The result of getting all app private certificates is undefined.');
      } else {
        let list = cmResult.credentialList;
        console.info('Succeeded in getting all app private certificates.');
      }
    }
  });
} catch (error) {
  console.error(`Failed to get all app private certificates. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.getAllAppPrivateCertificates

getAllAppPrivateCertificates(): Promise\<CMResult>

Obtains all private credentials. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER and ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**System capability**: System SystemCapability.Security.CertificateManager

**System API**: This is a system API.

**Return value**

| Type                                                 | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise used to return all the private credentials obtained, that is, **credentialList** in the [CMResult](#cmresult) object. |

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID | Error Message     |
| -------- | ------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 17500001 | Internal error. |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  certificateManager.getAllAppPrivateCertificates().then((cmResult) => {
    if (cmResult.credentialList == undefined) {
      console.info('The result of getting all app private certificates is undefined.');
    } else {
      let list = cmResult.credentialList;
      console.info('Succeeded in getting all app private certificates.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get all app private certificates. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get all app private certificates. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.getAllSystemAppCertificates<sup>12+</sup>

getAllSystemAppCertificates(): Promise\<CMResult>

Obtains all system credentials. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**System API**: This is a system API.

**Return value**

| Type                                                 | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise used to return all the system credentials obtained, that is, **credentialList** in the [CMResult](#cmresult) object. |

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID | Error Message     |
| -------- | ------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 17500001 | Internal error. |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  certificateManager.getAllSystemAppCertificates().then((cmResult) => {
    if (cmResult.credentialList == undefined) {
      console.info('The result of getting all system app certificates is undefined.');
    } else {
      let list = cmResult.credentialList;
      console.info('Succeeded in getting all system app certificates.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get all system app certificates. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get all system app certificates. Code: ${error.code}, message: ${error.message}`);
}
```
