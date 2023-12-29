# @ohos.security.certManager (Certificate Management)

The **certManager** module provides system-level certificate management capabilities to ensure secure use and management of certificates throughout their lifecycle (installation, storage, use, and destruction).

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import certManager from '@ohos.security.certManager';
```

## CmKeyPurpose

Enumerates the purposes of using the key.

**System capability**: System SystemCapability.Security.CertificateManager

| Name      | Value|  Description     |
| ---------- | ------ | --------- |
| CM_KEY_PURPOSE_SIGN | 4      | The key is used for signing.|
| CM_KEY_PURPOSE_VERIFY | 8      | The key is used for signature verification.|

## CmKeyDigest

Enumerates the digest algorithms that can be used for signing and signature verification.

**System capability**: System SystemCapability.Security.CertificateManager

| Name      | Value|  Description     |
| ---------- | ------ | --------- |
| CM_DIGEST_NONE | 0      | No digest algorithm is required. If this option is used, the service needs to pass in the data with the digest generated for signing or signature verification.|
| CM_DIGEST_MD5 | 1      | MD5.|
| CM_DIGEST_SHA1 | 2      | SHA-1.|
| CM_DIGEST_SHA224 | 3      | SHA-224.|
| CM_DIGEST_SHA256 | 4      | SHA-256.|
| CM_DIGEST_SHA384 | 5      | SHA-384.|
| CM_DIGEST_SHA512 | 6      | SHA-512.|

## CmKeyPadding

Enumerates the padding modes that can be used for signing and signature verification.

**System capability**: System SystemCapability.Security.CertificateManager

| Name      | Value|  Description     |
| ---------- | ------ | --------- |
| CM_PADDING_NONE | 0      | No padding.|
| CM_PADDING_PSS | 1      | PSS.|
| CM_PADDING_PKCS1_V1_5 | 2      | PKCS1-V1_5.|

## CMSignatureSpec

Represents a set of parameters used for signing or signature verification, including the key usage purpose, padding mode, and digest algorithm.

**System capability**: System SystemCapability.Security.CertificateManager

| Name          | Type                             | Mandatory| Description                                                        |
| -------------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| purpose          | [CmKeyPurpose](#cmkeypurpose)                       | Yes  | Purpose of using the key.|
| padding?        | [CmKeyPadding](#cmkeypadding)                       | No  | Padding mode.|
| digest?        | [CmKeyDigest](#cmkeydigest)                       | No  | Digest algorithm.|


## CertInfo

Represents the detailed information about a certificate.

**System capability**: System SystemCapability.Security.CertificateManager

| Name          | Type                             | Readable| Writable| Description                                                        |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| uri          | string         | Yes  | Yes  | Unique identifier of the certificate.|
| certAlias          | string   | Yes  | Yes  | Alias of the certificate.|
| state          | boolean     | Yes  | Yes  | Certificate state. The value **true** indicates that the certificate is enabled, and **false** means the opposite.|
| issuerName          | string         | Yes  | Yes  | Issuer of the certificate.|
| subjectName          | string   | Yes  | Yes  | User of the certificate.|
| serial          | string     | Yes  | Yes  | Serial number of the certificate.|
| notBefore          | string         | Yes  | Yes  | Date from which the certificate takes effect.|
| notAfter          | string   | Yes  | Yes  | Date when the certificate expires.|
| fingerprintSha256     | string     | Yes  | Yes  | Fingerprint value of the certificate.|
| cert          | Uint8Array         | Yes  | Yes  | Certificate data in binary format.|

## CertAbstract

Represents the brief information about a certificate.

**System capability**: System SystemCapability.Security.CertificateManager

| Name          | Type                             | Readable| Writable| Description                                                        |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| uri          | string         | Yes  | Yes  | Unique identifier of the certificate.|
| certAlias          | string   | Yes  | Yes  | Alias of the certificate.|
| state          | boolean     | Yes  | Yes  | Certificate state. The value **true** indicates that the certificate is enabled, and **false** means the opposite.|
| issuerName          | string         | Yes  | Yes  | Issuer of the certificate.|
| subjectName          | string   | Yes  | Yes  | User of the certificate.|

## Credential

Represents the detailed information about a credential.

**System capability**: System SystemCapability.Security.CertificateManager

| Name          | Type                             | Readable| Writable| Description                                                        |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type          | string         | Yes  | Yes  | Type of the credential.|
| alias          | string   | Yes  | Yes  | Alias of the credential.|
| keyUri          | string     | Yes  | Yes  | Unique identifier of the credential.|
| certNum          | number         | Yes  | Yes  | Number of certificates contained in the credential.|
| keyNum          | number   | Yes  | Yes  | Number of keys contained in the credential.|
| credentialData          | Uint8Array   | Yes  | Yes  | Credential data in binary format.|

## CredentialAbstract

Represents the brief information about a credential.

**System capability**: System SystemCapability.Security.CertificateManager

| Name          | Type                             | Readable| Writable| Description                                                        |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type          | string         | Yes  | Yes  | Type of the credential.|
| alias          | string   | Yes  | Yes  | Alias of the credential.|
| keyUri          | string     | Yes  | Yes  | Unique identifier of the credential.|

## CMResult

Represents the result returned.

**System capability**: System SystemCapability.Security.CertificateManager

| Name          | Type                             | Readable| Writable| Description                                                        |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| certList?          | Array<[CertAbstract](#certabstract)> | Yes  | Yes  | Brief certificate information.|
| certInfo?          | [CertInfo](#certinfo) | Yes  | Yes  | Detailed certificate information.|
| credentialList?          | Array<[CredentialAbstract](#credentialabstract)> | Yes  | Yes  | Brief credential information.|
| credential?         | [Credential](#credential) | Yes  | Yes  | Credential detailed information.|
| appUidList?        | Array<string>     | Yes  | Yes  | List of authorized applications.|
| uri?         | string    | Yes  | Yes  | Unique identifier of the certificate or credential.|
| outData?         | Uint8Array    | Yes  | Yes  | Signature generated.|

## CMHandle

Represents the handle of the signing or signature verification operation.

**System capability**: System SystemCapability.Security.CertificateManager

| Name          | Type                             | Readable| Writable| Description                                                        |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| handle         | Uint8Array        | Yes  | Yes  | Handle returned by **certManager.init()** for the subsequent signing or signature verification operation.|

## CMErrorCode

Enumerates the error codes used in the certificate management APIs.

**System capability**: System SystemCapability.Security.CertificateManager

| Name      | Value|  Description     |
| ---------- | ------ | --------- |
| CM_ERROR_NO_PERMISSION   | 201      | The application does not have the permission to call the API.|
| CM_ERROR_NOT_SYSTEM_APP   | 202      | The caller is not a system application.<br> **System API**: This is a system API.|
| CM_ERROR_INVALID_PARAMS   | 401      | Invalid input parameter is found.|
| CM_ERROR_GENERIC  | 17500001      | An internal error occurs when the interface is called.|
| CM_ERROR_NO_FOUND  | 17500002      | The certificate or credential does not exist.|
| CM_ERROR_INCORRECT_FORMAT  | 17500003      | The certificate or credential is in invalid format.|

## certManager.installPrivateCertificate

installPrivateCertificate(keystore: Uint8Array, keystorePwd: string, certAlias: string, callback: AsyncCallback\<CMResult>) : void

Installs a private credential. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keystore | Uint8Array                   | Yes  | Keystore file containing the key pair and certificate.|
| keystorePwd | string | Yes  | Password of the keystore file. The password cannot exceed 32 bytes.|
| certAlias | string | Yes  | Certificate alias. Currently, the alias can contain only digits, letters, and underscores (_) and should not exceed 32 bytes.|
| callback | AsyncCallback\<[CMResult](#cmresult)> | Yes  | Callback invoked to return the result. If the operation is successful, the URI of the installed credential is returned.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](../errorcodes/errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500003 | The keystore is not valid format or keystorePwd is not correct. |

**Example**
```ts
import certManager from '@ohos.security.certManager';

/* The credential data to be installed must be assigned by the service. The data in this example is not the real credential data. */
let keystore: Uint8Array = new Uint8Array([
  0x30, 0x82, 0x0b, 0xc1, 0x02, 0x01,
]);
let keystorePwd: string = "123456";
try {
  certManager.installPrivateCertificate(keystore, keystorePwd, "test", (err, cmResult) => {
    if (err != null) {
      console.error("[Callback]installPrivateCertificate err: " + err.code);
    } else {
      let uri: string = (cmResult.uri == undefined) ? '' : cmResult.uri;
      console.log("[Callback]installPrivateCertificate success");
    }
  });
} catch (error) {
  console.error("[Callback]installPrivateCertificate failed");
}
```

## certManager.installPrivateCertificate

installPrivateCertificate(keystore: Uint8Array, keystorePwd: string, certAlias: string) : Promise\<CMResult>

Installs a private credential. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keystore | Uint8Array                   | Yes  | Keystore file containing the key pair and certificate.|
| keystorePwd | string | Yes  | Password of the keystore file. The password cannot exceed 32 bytes.|
| certAlias | string | Yes  | Credential alias. Currently, the alias can contain only digits, letters, and underscores (_) and should not exceed 32 bytes.|

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<[CMResult](#cmresult)> | Promise used to return the result. If the operation is successful, the URI of the installed credential is returned.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](../errorcodes/errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500003 | The keystore is not valid format or keystorePwd is not correct. |

**Example**

```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

/* The credential data to be installed must be assigned by the service. The data in this example is not the real credential data. */
let keystore: Uint8Array = new Uint8Array([
  0x30, 0x82, 0x0b, 0xc1, 0x02, 0x01,
]);
let keystorePwd: string = "123456";
try {
  certManager.installPrivateCertificate(keystore, keystorePwd, 'test').then((cmResult) => {
    let uri: string = (cmResult.uri == undefined) ? '' : cmResult.uri;
    console.log("[Promise]installPrivateCertificate success");
  }).catch((err: BusinessError) => {
    console.error('[Promise]installPrivateCertificate failed');
  })
} catch (err) {
  console.error("[Promise]installPrivateCertificate failed");
}
```

## certManager.getAllAppPrivateCertificates

getAllAppPrivateCertificates(callback: AsyncCallback\<CMResult>): void

Obtains all private credentials. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER and ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**System capability**: System SystemCapability.Security.CertificateManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<[CMResult](#cmresult)> | Yes  | Callback invoked to return the result. If the operation is successful, **credentialList** in [CMResult](#cmresult) is returned.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](../errorcodes/errorcode-certManager.md).

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
| Promise\<[CMResult](#cmresult)> | Promise used to return the result. If the operation is successful, **credentialList** in [CMResult](#cmresult) is returned.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](../errorcodes/errorcode-certManager.md).

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

## certManager.getPrivateCertificate

getPrivateCertificate(keyUri: string, callback: AsyncCallback\<CMResult>) : void

Obtains detailed information about a private credential. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | Yes  | Unique identifier of the target credential.|
| callback | AsyncCallback\<[CMResult](#cmresult)> | Yes  | Callback invoked to return the result. If the operation is successful, **credential** in [CMResult](#cmresult) is returned.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](../errorcodes/errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |

**Example**
```ts
import certManager from '@ohos.security.certManager';

let uri: string = 'test'; /* URI of the credential installed, which is omitted here. */
try {
  certManager.getPrivateCertificate(uri, (err, cmResult) => {
    if (err != null) {
      console.error("getPrivateCertificate error");
    } else {
      if (cmResult.credential == undefined) {
        console.log("[Callback]getPrivateCertificate result is undefined");
      } else {
        let list = cmResult.credential;
        console.log("[Callback]getPrivateCertificate success");
      }
    }
  });
} catch (error) {
  console.error("[Callback]installPrivateCertificate failed");
}
```

## certManager.getPrivateCertificate

getPrivateCertificate(keyUri: string) : Promise\<CMResult>

Obtains detailed information about a private credential. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | Yes  | Unique identifier of the target credential.|

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<[CMResult](#cmresult)> | Promise used to return the result. If the operation is successful, **credential** in [CMResult](#cmresult) is returned.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](../errorcodes/errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |

**Example**
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

let uri: string = 'test'; /* URI of the credential installed, which is omitted here. */
try {
  certManager.getPrivateCertificate(uri).then((cmResult) => {
    if (cmResult.credential == undefined) {
      console.log("[Promise]getPrivateCertificate result is undefined");
    } else {
      let list = cmResult.credential;
      console.log("[Promise]getPrivateCertificate success");
    }
  }).catch((err: BusinessError) => {
    console.error('[Promise]getPrivateCertificate failed');
  })
} catch (err) {
  console.error("[Promise]getPrivateCertificate failed");
}
```

## certManager.uninstallPrivateCertificate

uninstallPrivateCertificate(keyUri: string, callback: AsyncCallback\<void>) : void

Uninstalls a private credential. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | Yes  | Unique identifier of the credential to uninstall.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result. If the operation is successful, **error** is **null**.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](../errorcodes/errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |

**Example**
```ts
import certManager from '@ohos.security.certManager';

let uri: string = 'test'; /* URI of the credential installed, which is omitted here. */
try {
  certManager.uninstallPrivateCertificate(uri, (err, result) => {
    if (err != null) {
      console.error("[Callback]uninstallPrivateCertificate error");
    } else {
      console.log("[Callback]uninstallPrivateCertificate success");
    }
  });
} catch (err) {
  console.error("[Callback]uninstallPrivateCertificate failed");
}
```

## certManager.uninstallPrivateCertificate

uninstallPrivateCertificate(keyUri: string) : Promise\<void>

Uninstalls a private credential. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | Yes  | Unique identifier of the credential to uninstall.|

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](../errorcodes/errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |

**Example**
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

let uri: string = 'test'; /* URI of the credential installed, which is omitted here. */
try {
  certManager.uninstallPrivateCertificate(uri).then((cmResult) => {
    console.log("[Promise]uninstallPrivateCertificate success");
  }).catch((err: BusinessError) => {
    console.error('[Promise]uninstallPrivateCertificate failed, code =', err.code);
  })
} catch (err) {
  console.error("[Promise]uninstallPrivateCertificate failed");
}
```

## certManager.init

init(authUri: string, spec: CMSignatureSpec, callback: AsyncCallback\<CMHandle>) : void

Initializes the signing or signature verification operation using the specified credential. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| authUri | string                   | Yes  | Unique identifier of the credential to use.|
| spec | [CMSignatureSpec](#cmsignaturespec) | Yes  | Parameters for the signing or signature verification operation.|
| callback | AsyncCallback\<[CMHandle](#cmhandle)> | Yes  | Callback invoked to return an operation handle.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](../errorcodes/errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |

**Example**
```ts
import certManager from '@ohos.security.certManager';

let uri: string = 'test'; /* URI of the credential installed, which is omitted here. */
const req: certManager.CMSignatureSpec = {
  purpose: certManager.CmKeyPurpose.CM_KEY_PURPOSE_SIGN,
  padding: certManager.CmKeyPadding.CM_PADDING_PSS,
  digest: certManager.CmKeyDigest.CM_DIGEST_SHA256
}
try {
  certManager.init(uri, req, (err, cmHandle) => {
    if (err != null) {
      console.error("[Callback]init err");
    } else {
      console.log("[Callback]init success");
    }
  })
} catch (err) {
  console.error("[Callback]init failed");
}
```

## certManager.init

init(authUri: string, spec: CMSignatureSpec) : Promise\<CMHandle>

Initializes the signing or signature verification operation using the specified credential. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| authUri | string                   | Yes  | Unique identifier of the credential to use.|
| spec | [CMSignatureSpec](#cmsignaturespec) | Yes  | Parameters for the signing or signature verification operation.|

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<[CMHandle](#cmhandle)> | Promise used to return an operation handle.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](../errorcodes/errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |

**Example**
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

let uri: string = 'test'; /* URI of the credential installed, which is omitted here. */
const req: certManager.CMSignatureSpec = {
  purpose: certManager.CmKeyPurpose.CM_KEY_PURPOSE_VERIFY,
  padding: certManager.CmKeyPadding.CM_PADDING_PSS,
  digest: certManager.CmKeyDigest.CM_DIGEST_MD5
}
try {
  certManager.init(uri, req).then((handle) => {
    console.log('[Promise]init success');
  }).catch((error: BusinessError) => {
    console.error('[Promise]init failed');
  })
} catch (err) {
  console.error("[Promise]init failed");
}
```

## certManager.update

update(handle: Uint8Array, data: Uint8Array, callback: AsyncCallback\<void>): void

Updates the data for the signing or signature verification operation. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | Yes  | Operation handle returned by **init()**.|
| data | Uint8Array                   | Yes  | Data to be signed or verified.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result. If the operation is successful, **error** is **null**.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](../errorcodes/errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**Example**
```ts
import certManager from '@ohos.security.certManager';

/* cmHandle is the value returned by init(). The value here is only an example. */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
let srcData: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certManager.update(cmHandle, srcData, (err, result) => {
    if (err != null) {
      console.error("[Callback]certManager update error");
    } else {
      console.log("[Callback]certManager update success");
    }
  });
} catch (err) {
  console.error("[Callback]update failed");
}
```

## certManager.update

update(handle: Uint8Array, data: Uint8Array): Promise\<void>

Updates the data for the signing or signature verification operation. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | Yes  | Operation handle returned by **init()**.|
| data | Uint8Array                   | Yes  | Data to be signed or verified.|

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](../errorcodes/errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**Example**
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

/* cmHandle is the value returned by init(). The value here is only an example. */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
let srcData: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certManager.update(cmHandle, srcData).then((result) => {
    console.log('[Promise]update success');
  }).catch((error: BusinessError) => {
    console.error('[Promise]update failed');
  })
} catch (err) {
  console.error("[Promise]certManager update error");
}
```

## certManager.finish

finish(handle: Uint8Array, callback: AsyncCallback\<CMResult>) : void

Finishes the signing operation. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | Yes  | Operation handle returned by **init()**.|
| callback | AsyncCallback\<[CMResult](#cmresult)> | Yes  | Callback invoked to return the result. If the operation is successful, **outData** in [CMResult](#cmresult) is returned.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](../errorcodes/errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**Example**
```ts
import certManager from '@ohos.security.certManager';

/* cmHandle is the value returned by init(). The value here is only an example. */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certManager.finish(cmHandle, (err, cmResult) => {
    if (err != null) {
      console.error("[Callback]certManager sign failed");
    } else {
      if (cmResult.outData != undefined) {
        let signRes: Uint8Array = cmResult.outData;
        console.log("[Callback]certManager sign success");
      } else {
        console.error("[Callback]certManager sign failed");
      }
    }
  });
} catch(error) {
  console.error("[Callback]certManager finish error");
}
```

## certManager.finish

finish(handle: Uint8Array, signature: Uint8Array, callback: AsyncCallback\<CMResult>) : void

Finishes the signature verification operation. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | Yes  | Operation handle returned by **init()**.|
| signature | Uint8Array                   | Yes  | Signature data to verify.|
| callback | AsyncCallback\<[CMResult](#cmresult)> | Yes  | Callback invoked to return the result. If the operation is successful, **error** is **null**.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](../errorcodes/errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**Example**
```ts
import certManager from '@ohos.security.certManager';

/* cmHandle is the value returned by init(). The value here is only an example. */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
let signRes: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certManager.finish(cmHandle, signRes, (err, cmResult) => {
    if (err != null) {
      console.error("[Callback]certManager verify failed");
    } else {
      console.log("[Callback]certManager verify success");
    }
  });
} catch(error) {
  console.error("[Callback]certManager finish error");
}
```

## certManager.finish

finish(handle: Uint8Array, signature?: Uint8Array) : Promise\<CMResult>

Finishes the signing or signature verification operation. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | Yes  | Operation handle returned by **init()**.|
| signature | Uint8Array                   | No  | Data to sign or verify.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](#cmresult)> | Promise used to return the result. If the operation is successful, **outData** in [CMResult](#cmresult) is returned for a signing operation, and no data is returned for a signature verification operation.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](../errorcodes/errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**Example**
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

/* cmHandle is the value returned by init(). The value here is only an example. */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  /* Finish the signing operation. */
  certManager.finish(cmHandle).then((cmResult) => {
    if (cmResult.outData != undefined) {
      let signRes1: Uint8Array = cmResult.outData;
      console.log("[Promise]finish sign success");
    } else {
      console.error("[Promise]finish sign failed");
    }
  }).catch((err: BusinessError) => {
    console.error('[Promise]finish sign failed');
  })

  /* Signature generated. */
  let signRes: Uint8Array = new Uint8Array([
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
  ]);
  /* Finish the signature verification operation. */
  certManager.finish(cmHandle, signRes).then((cmResult) => {
    console.log("[Promise]finish verify success");
  }).catch((err: BusinessError) => {
    console.error('[Promise]finish verify failed');
  })
} catch(error) {
  console.error("[Promise]certManager finish error");
}
```

## certManager.abort

abort(handle: Uint8Array, callback: AsyncCallback\<void>) : void

Aborts the signing or signature verification operation. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | Yes  | Operation handle returned by **init()**.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result. If the operation is successful, **error** is **null**.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](../errorcodes/errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**Example**
```ts
import certManager from '@ohos.security.certManager';

/* cmHandle is the value returned by init(). The value here is only an example. */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certManager.abort(cmHandle, (err, cmResult) => {
    if (err != null) {
      console.error("[Callback]certManager abort failed");
    } else {
      console.log("[Callback]certManager abort success");
    }
  });
} catch(error) {
  console.error("[Callback]certManager abort error");
}
```

## certManager.abort

abort(handle: Uint8Array) : Promise\<void>

Aborts the signing or signature verification operation. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | Yes  | Operation handle returned by **init()**.|

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](../errorcodes/errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**Example**
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

/* cmHandle is the value returned by init(). The value here is only an example. */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certManager.abort(cmHandle).then((result) => {
    console.log('[Promise]abort success');
  }).catch((error: BusinessError) => {
    console.error('[Promise]abort failed');
  })
} catch (err) {
  console.error("[Promise]certManager abort error");
}
```
