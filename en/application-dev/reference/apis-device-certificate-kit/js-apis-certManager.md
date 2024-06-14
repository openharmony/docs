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

Represents detailed information about a certificate.

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

Represents brief information about a certificate.

**System capability**: System SystemCapability.Security.CertificateManager

| Name          | Type                             | Readable| Writable| Description                                                        |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| uri          | string         | Yes  | Yes  | Unique identifier of the certificate.|
| certAlias          | string   | Yes  | Yes  | Alias of the certificate.|
| state          | boolean     | Yes  | Yes  | Certificate state. The value **true** indicates that the certificate is enabled, and **false** means the opposite.|
| issuerName          | string         | Yes  | Yes  | Issuer of the certificate.|
| subjectName          | string   | Yes  | Yes  | User of the certificate.|

## Credential

Represents detailed information about a credential.

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

Represents brief information about a credential.

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
| credential?         | [Credential](#credential) | Yes  | Yes  | Detailed credential information.|
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
| CM_ERROR_INVALID_PARAMS   | 401      | Invalid input parameter is found.|
| CM_ERROR_GENERIC  | 17500001      | An internal error occurs when the interface is called.|
| CM_ERROR_NO_FOUND  | 17500002      | The certificate or credential does not exist.|
| CM_ERROR_INCORRECT_FORMAT  | 17500003      | The certificate or credential is in invalid format.|
| CM_ERROR_MAX_CERT_COUNT_REACHED<sup>12+</sup>  | 17500004      | The number of certificates or credentials has reached the limit.|
| CM_ERROR_NO_AUTHORIZATION<sup>12+</sup>  | 17500005      | The application has not obtained user authorization.|

## certManager.installPrivateCertificate

installPrivateCertificate(keystore: Uint8Array, keystorePwd: string, certAlias: string, callback: AsyncCallback\<CMResult>): void

Installs a private credential. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keystore | Uint8Array                   | Yes  | Keystore file containing the key pair and certificate.|
| keystorePwd | string | Yes  | Password of the keystore file. The password cannot exceed 32 bytes.|
| certAlias | string | Yes  | Credential alias. Currently, the alias can contain only digits, letters, and underscores (_) and should not exceed 32 bytes.|
| callback | AsyncCallback\<[CMResult](#cmresult)> | Yes  | Callback invoked to return the result. If the operation is successful, the URI of the installed credential (**uri** in [CMResult](#cmresult)) is returned.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | The application has no permission to call the API.     |
| 401      | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API.     |
| 17500003 | The keystore is not valid format or keystorePwd is not correct. |
| 17500004<sup>12+</sup> | The count of credentials reach the max. |

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
      console.error(`Failed to install private certificate. Code: ${err.code}, message: ${err.message}`);
    } else {
      let uri: string = (cmResult.uri == undefined) ? '' : cmResult.uri;
      console.info('Succeeded in installing private certificate.');
    }
  });
} catch (error) {
  console.error(`Failed to install private certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certManager.installPrivateCertificate

installPrivateCertificate(keystore: Uint8Array, keystorePwd: string, certAlias: string): Promise\<CMResult>

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
| Promise\<[CMResult](#cmresult)> | Promise used to return the result. If the operation is successful, the URI of the installed credential (**uri** in [CMResult](#cmresult)) is returned.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | The application has no permission to call the API.     |
| 401      | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API.     |
| 17500003 | The keystore is not valid format or keystorePwd is not correct. |
| 17500004<sup>12+</sup> | The count of credentials reach the max. |

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
    console.info('Succeeded in installing private certificate.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to install private certificate. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to install private certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certManager.getPrivateCertificate

getPrivateCertificate(keyUri: string, callback: AsyncCallback\<CMResult>): void

Obtains detailed information about a private credential. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | Yes  | Unique identifier of the target credential.|
| callback | AsyncCallback\<[CMResult](#cmresult)> | Yes  | Callback invoked to return the result. If the operation is successful, **credential** in [CMResult](#cmresult) is returned.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201      | The application has no permission to call the API.     |
| 401 | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |

**Example**
```ts
import certManager from '@ohos.security.certManager';

let uri: string = 'test'; /* URI of the credential installed. The process for installing the credential is omitted here. */
try {
  certManager.getPrivateCertificate(uri, (err, cmResult) => {
    if (err != null) {
      console.error(`Failed to get private certificate. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (cmResult.credential == undefined) {
        console.info('The result of getting private certificate is undefined.');
      } else {
        let list = cmResult.credential;
        console.info('Succeeded in getting private certificate.');
      }
    }
  });
} catch (error) {
  console.error(`Failed to get private certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certManager.getPrivateCertificate

getPrivateCertificate(keyUri: string): Promise\<CMResult>

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

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201      | The application has no permission to call the API.     |
| 401 | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |

**Example**
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

let uri: string = 'test'; /* URI of the credential installed. The process for installing the credential is omitted here. */
try {
  certManager.getPrivateCertificate(uri).then((cmResult) => {
    if (cmResult.credential == undefined) {
      console.info('The result of getting private certificate is undefined.');
    } else {
      let list = cmResult.credential;
      console.info('Succeeded in getting private certificate.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get private certificate. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get private certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certManager.uninstallPrivateCertificate

uninstallPrivateCertificate(keyUri: string, callback: AsyncCallback\<void>): void

Uninstalls a private credential. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | Yes  | Unique identifier of the credential to uninstall.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result. If the operation is successful, **error** is **null**.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201      | The application has no permission to call the API.     |
| 401 | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |

**Example**
```ts
import certManager from '@ohos.security.certManager';

let uri: string = 'test'; /* URI of the credential installed. The process for installing the credential is omitted here. */
try {
  certManager.uninstallPrivateCertificate(uri, (err, result) => {
    if (err != null) {
      console.error(`Failed to uninstall private certificate. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('Succeeded in uninstalling private certificate.');
    }
  });
} catch (error) {
  console.error(`Failed to uninstall private certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certManager.uninstallPrivateCertificate

uninstallPrivateCertificate(keyUri: string): Promise\<void>

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

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201      | The application has no permission to call the API.     |
| 401 | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |

**Example**
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

let uri: string = 'test'; /* URI of the credential installed. The process for installing the credential is omitted here. */
try {
  certManager.uninstallPrivateCertificate(uri).then((cmResult) => {
    console.info('Succeeded in uninstalling private certificate.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to uninstall private certificate. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to uninstall private certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certManager.init

init(authUri: string, spec: CMSignatureSpec, callback: AsyncCallback\<CMHandle>): void

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

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201      | The application has no permission to call the API.     |
| 401 | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |
| 17500005<sup>12+</sup> | The application is not authorized by user. |

**Example**
```ts
import certManager from '@ohos.security.certManager';

let uri: string = 'test'; /* URI of the credential. The process for installing the credential is omitted here. */
const req: certManager.CMSignatureSpec = {
  purpose: certManager.CmKeyPurpose.CM_KEY_PURPOSE_SIGN,
  padding: certManager.CmKeyPadding.CM_PADDING_PSS,
  digest: certManager.CmKeyDigest.CM_DIGEST_SHA256
}
try {
  certManager.init(uri, req, (err, cmHandle) => {
    if (err != null) {
      console.error(`Failed to init. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('Succeeded in initiating.');
    }
  })
} catch (error) {
  console.error(`Failed to init. Code: ${error.code}, message: ${error.message}`);
}
```

## certManager.init

init(authUri: string, spec: CMSignatureSpec): Promise\<CMHandle>

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

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201      | The application has no permission to call the API.     |
| 401 | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |
| 17500005<sup>12+</sup> | The application is not authorized by user. |

**Example**
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

let uri: string = 'test'; /* URI of the credential. The process for installing the credential is omitted here. */
const req: certManager.CMSignatureSpec = {
  purpose: certManager.CmKeyPurpose.CM_KEY_PURPOSE_VERIFY,
  padding: certManager.CmKeyPadding.CM_PADDING_PSS,
  digest: certManager.CmKeyDigest.CM_DIGEST_MD5
}
try {
  certManager.init(uri, req).then((handle) => {
    console.info('Succeeded in initiating.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to init. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to init. Code: ${error.code}, message: ${error.message}`);
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

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | The application has no permission to call the API.     |
| 401      | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API.     |

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
      console.error(`Failed to update. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('Succeeded in updating.');
    }
  });
} catch (error) {
  console.error(`Failed to update. Code: ${error.code}, message: ${error.message}`);
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

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | The application has no permission to call the API.     |
| 401      | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API.     |

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
    console.info('Succeeded in updating.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to update. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to update. Code: ${error.code}, message: ${error.message}`);
}
```

## certManager.finish

finish(handle: Uint8Array, callback: AsyncCallback\<CMResult>): void

Finishes the signing operation. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | Yes  | Operation handle returned by **init()**.|
| callback | AsyncCallback\<[CMResult](#cmresult)> | Yes  | Callback invoked to return the result. If the operation is successful, **outData** in [CMResult](#cmresult) is returned.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | The application has no permission to call the API.     |
| 401      | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API.     |

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
      console.error(`Failed to finish. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (cmResult.outData != undefined) {
        let signRes: Uint8Array = cmResult.outData;
        console.info('Succeeded in finishing.');
      } else {
        console.info('The result of finishing is undefined.');
      }
    }
  });
} catch(error) {
  console.error(`Failed to finish. Code: ${error.code}, message: ${error.message}`);
}
```

## certManager.finish

finish(handle: Uint8Array, signature: Uint8Array, callback: AsyncCallback\<CMResult>): void

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

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | The application has no permission to call the API.     |
| 401      | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API.     |

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
      console.error(`Failed to finish. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('Succeeded in finishing.');
    }
  });
} catch(error) {
  console.error(`Failed to finish. Code: ${error.code}, message: ${error.message}`);
}
```

## certManager.finish

finish(handle: Uint8Array, signature?: Uint8Array): Promise\<CMResult>

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

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | The application has no permission to call the API.     |
| 401      | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API.     |

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
      console.info('Succeeded in finishing signature.');
    } else {
      console.info('The result of signature is undefined.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to finish signature. Code: ${err.code}, message: ${err.message}`);
  })

  /* Signature generated. */
  let signRes: Uint8Array = new Uint8Array([
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
  ]);
  /* Finish the signature verification operation. */
  certManager.finish(cmHandle, signRes).then((cmResult) => {
    console.info('Succeeded in finishing verification.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to finish verification. Code: ${err.code}, message: ${err.message}`);
  })
} catch(error) {
  console.error(`Failed to finish. Code: ${error.code}, message: ${error.message}`);
}
```

## certManager.abort

abort(handle: Uint8Array, callback: AsyncCallback\<void>): void

Aborts the signing or signature verification operation. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | Yes  | Operation handle returned by **init()**.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result. If the operation is successful, **error** is **null**.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | The application has no permission to call the API.     |
| 401      | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API.     |

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
      console.error(`Failed to abort. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('Succeeded in aborting.');
    }
  });
} catch(error) {
  console.error(`Failed to abort. Code: ${error.code}, message: ${error.message}`);
}
```

## certManager.abort

abort(handle: Uint8Array): Promise\<void>

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

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | The application has no permission to call the API.     |
| 401      | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API.     |

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
    console.info('Succeeded in aborting.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to abort. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to abort. Code: ${error.code}, message: ${error.message}`);
}
```

## certManager.getPublicCertificate<sup>12+</sup>

getPublicCertificate(keyUri: string): Promise\<CMResult>

Obtains detailed information about a public credential. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | Yes  | Unique identifier of the public credential.|

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<[CMResult](#cmresult)> | Promise used to return the result. If the operation is successful, **credential** in [CMResult](#cmresult) is returned.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | The application has no permission to call the API. |
| 401 | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |
| 17500005 | The application is not authorized by user. |

**Example**
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

let uri: string = 'test'; /* Unique identifier of the public credential. The process for installing the public credential is omitted here. */
try {
  certManager.getPublicCertificate(uri).then((cmResult) => {
    if (cmResult.credential == undefined) {
      console.info('The result of getting public certificate is undefined.');
    } else {
      let cred = cmResult.credential;
      console.info('Succeeded in getting Public certificate.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get Public certificate. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get Public certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certManager.isAuthorizedApp<sup>12+</sup>

isAuthorizedApp(keyUri: string): Promise\<boolean>

Checks whether this application is authorized by the specified user credential. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | Yes  | Unique identifier of the credential.|

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means the application is authorized by the specified user credential; the value **false** means the opposite.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | The application has no permission to call the API. |
| 401 | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API. |

**Example**
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

let uri: string = 'test'; /* Unique identifier of the credential. The process for authorizing the credential to the application is omitted here. */
try {
  certManager.isAuthorizedApp(uri).then((res) => {
    if (res) {
      console.info('The application is authorized by the user.');
    } else {
      console.info('The application is not authorized by the user.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get Public certificate. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get Public certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certManager.getAllUserTrustedCertificates<sup>12+</sup>

getAllUserTrustedCertificates(): Promise\<CMResult>

Obtains all the user root CA certificates. The API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<[CMResult](#cmresult)> | Promise used to return the user root CA certificates (that is, **certList** in [CMResult](#cmresult)) obtained.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | The application has no permission to call the API. |
| 17500001 | There is an generic error occurred when calling the API. |

**Example**
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

try {
  certManager.getAllUserTrustedCertificates().then((cmResult) => {
    if (cmResult.certList == undefined) {
      console.info('The result of getting all user trusted certificates is undefined.');
    } else {
      let list = cmResult.certList;
      console.info('Succeeded in getting all user trusted certificates.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get all user trusted certificates. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get all user trusted certificates. Code: ${error.code}, message: ${error.message}`);
}
```

## certManager.getUserTrustedCertificate<sup>12+</sup>

getUserTrustedCertificate(certUri: string): Promise\<CMResult>

Obtains the detailed information about a user root CA certificate. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| certUri | string                   | Yes  | Unique identifier of the user root CA certificate.|

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<[CMResult](#cmresult)> | Promise used to return the detailed certificate information (that is, **certInfo** in [CMResult](#cmresult)) obtained.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | The application has no permission to call the API. |
| 401 | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |

**Example**
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

let certUri: string = 'testUserCert'; /* Unique identifer of the user root CA certificate. The process of installing the user root CA certificate is omitted here. */
try {
  certManager.getUserTrustedCertificate(certUri).then((cmResult) => {
    if (cmResult.certInfo == undefined) {
      console.info('The result of getting user trusted certificate is undefined.');
    } else {
      let cert = cmResult.certInfo;
      console.info('Succeeded in getting user trusted certificate.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get user trusted certificate. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get user trusted certificate. Code: ${error.code}, message: ${error.message}`);
}
```
