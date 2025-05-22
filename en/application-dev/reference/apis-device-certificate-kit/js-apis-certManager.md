# @ohos.security.certManager (Certificate Management)

The **certManager** module provides system-level certificate management capabilities to ensure secure use and management of certificates throughout their lifecycle (installation, storage, use, and destruction).

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
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
| CM_DIGEST_SM3<sup>16+</sup> | 7 | SM3.|

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

| Name          | Type                             | Read-Only| Optional| Description                                                        |
| -------------- | --------------------------------- | ---- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| purpose          | [CmKeyPurpose](#cmkeypurpose)                       | No | No | Purpose of using the key.|
| padding        | [CmKeyPadding](#cmkeypadding)                       | No  | Yes | Padding mode.|
| digest        | [CmKeyDigest](#cmkeydigest)                       | No  | Yes | Digest algorithm.|


## CertInfo

Represents detailed information about a certificate.

**System capability**: System SystemCapability.Security.CertificateManager

| Name          | Type                             | Read-Only| Optional| Description                                                        |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| uri          | string         | No  | No | Unique identifier of the certificate.|
| certAlias          | string   | No | No | Alias of the certificate.|
| state          | boolean     | No | No | Certificate state. The value **true** indicates that the certificate is enabled, and **false** means the opposite.|
| issuerName          | string         | No | No | Issuer of the certificate.|
| subjectName          | string   | No | No | User of the certificate.|
| serial          | string     | No | No | Serial number of the certificate.|
| notBefore          | string         | No | No | Date from which the certificate takes effect.|
| notAfter          | string   | No | No | Date when the certificate expires.|
| fingerprintSha256     | string     | No | No | Fingerprint value of the certificate.|
| cert          | Uint8Array         | No | No | Certificate data in binary format.|

## CertAbstract

Represents brief information about a certificate.

**System capability**: System SystemCapability.Security.CertificateManager

| Name          | Type                             | Read-Only| Optional| Description                                                        |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| uri          | string         | No | No | Unique identifier of the certificate.|
| certAlias          | string   | No | No | Alias of the certificate.|
| state          | boolean     | No | No | Certificate state. The value **true** indicates that the certificate is enabled, and **false** means the opposite.|
| subjectName          | string   | No | No | User of the certificate.|

## Credential

Represents detailed information about a credential.

**System capability**: System SystemCapability.Security.CertificateManager

| Name          | Type                             | Read-Only| Optional| Description                                                        |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type          | string         | No | No | Type of the credential.|
| alias          | string   | No | No | Alias of the credential.|
| keyUri          | string     | No | No | Unique identifier of the credential.|
| certNum          | number         | No | No | Number of certificates contained in the credential.|
| keyNum          | number   | No | No | Number of keys contained in the credential.|
| credentialData          | Uint8Array   | No | No | Credential data in binary format.|

## CredentialAbstract

Represents brief information about a credential.

**System capability**: System SystemCapability.Security.CertificateManager

| Name          | Type                             | Read-Only| Optional| Description                                                        |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type          | string         | No| No | Type of the credential.|
| alias          | string   | No | No | Alias of the credential.|
| keyUri          | string     | No | No | Unique identifier of the credential.|

## CMResult

Represents the result returned.

**System capability**: System SystemCapability.Security.CertificateManager

| Name          | Type                             | Read-Only| Optional| Description                                                        |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| certList          | Array<[CertAbstract](#certabstract)> | No | Yes  | Brief certificate information.|
| certInfo          | [CertInfo](#certinfo) | No | Yes  | Detailed certificate information.|
| credentialList          | Array<[CredentialAbstract](#credentialabstract)> | No | Yes  | Brief credential information.|
| credential         | [Credential](#credential) | No | Yes  | Detailed credential information.|
| appUidList        | Array\<string>     | No | Yes  | List of authorized applications.|
| uri         | string    | No | Yes  | Unique identifier of the certificate or credential.|
| outData         | Uint8Array    | No | Yes  | Signature generated.|

## CMHandle

Represents the handle to a signing or signature verification operation.

**System capability**: System SystemCapability.Security.CertificateManager

| Name          | Type                             | Read-Only| Optional| Description                                                        |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| handle         | Uint8Array        | No | No  | Handle returned by **certManager.init()** for the subsequent signing or signature verification operation.|

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

## CertType<sup>16+</sup>

Enumerates the certificate types.

**System capability**: System SystemCapability.Security.CertificateManager

| Name      | Value|  Description     |
| ---------- | ------ | --------- |
| CA_CERT_SYSTEM   | 0      | System CA certificate.|
| CA_CERT_USER   | 1      | User CA certificate.|

## CertScope<sup>16+</sup>

Enumerates the certificate scopes.

**System capability**: System SystemCapability.Security.CertificateManager

| Name      | Value|  Description     |
| ---------- | ------ | --------- |
| CURRENT_USER   | 1      | The certificate is accessible only to the current user.|
| GLOBAL_USER   | 2      | The certificate is accessible to all users.|

## CertStoreProperty<sup>16+</sup>

Represents the storage information about a certificate, including the certificate type and location.

**System capability**: System SystemCapability.Security.CertificateManager

| Name          | Type                             | Read-Only| Optional| Description                                                        |
| -------------- | --------------------------------- | ---- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| certType          | [CertType](#certtype16)                     | No | No | Type of the certificate.|
| certScope        | [CertScope](#certscope16)                     | No  | Yes | Scope of the certificate. This parameter is mandatory when **certType** is **CA_CERT_USER**.|


## certificateManager.installPrivateCertificate

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
| callback | AsyncCallback\<[CMResult](#cmresult)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is **uri** in the [CMResult](#cmresult) object. Otherwise, **err** is an error object.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error.     |
| 17500003 | The keystore is in an invalid format or the keystore password is incorrect. |
| 17500004<sup>12+</sup> | The number of certificates or credentials reaches the maximum allowed. |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';

/* The credential data to be installed must be assigned by the service. The data in this example is not the real credential data. */
let keystore: Uint8Array = new Uint8Array([
  0x30, 0x82, 0x0b, 0xc1, 0x02, 0x01,
]);
let keystorePwd: string = "123456";
try {
  certificateManager.installPrivateCertificate(keystore, keystorePwd, "test", (err, cmResult) => {
    if (err != null) {
      console.error(`Failed to install private certificate. Code: ${err.code}, message: ${err.message}`);
    } else {
      let uri: string = (cmResult?.uri == undefined) ? '' : cmResult.uri;
      console.info('Succeeded in installing private certificate.');
    }
  });
} catch (error) {
  console.error(`Failed to install private certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.installPrivateCertificate

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

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](#cmresult)> | Promise used to return the operation result, that is, **uri** in the [CMResult](#cmresult) object.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error.     |
| 17500003 | The keystore is in an invalid format or the keystore password is incorrect. |
| 17500004<sup>12+</sup> | The number of certificates or credentials reaches the maximum allowed. |

**Example**

```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

/* The credential data to be installed must be assigned by the service. The data in this example is not the real credential data. */
let keystore: Uint8Array = new Uint8Array([
  0x30, 0x82, 0x0b, 0xc1, 0x02, 0x01,
]);
let keystorePwd: string = "123456";
try {
  certificateManager.installPrivateCertificate(keystore, keystorePwd, 'test').then((cmResult) => {
    let uri: string = (cmResult?.uri == undefined) ? '' : cmResult.uri;
    console.info('Succeeded in installing private certificate.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to install private certificate. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to install private certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.getPrivateCertificate

getPrivateCertificate(keyUri: string, callback: AsyncCallback\<CMResult>): void

Obtains detailed information about a private credential. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | Yes  | Unique identifier of the target credential.|
| callback | AsyncCallback\<[CMResult](#cmresult)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is **credential** in the [CMResult](#cmresult) object. Otherwise, **err** is an error object.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error. |
| 17500002 | The certificate does not exist. |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';

let uri: string = 'test'; /* URI of the credential installed. The process for installing the credential is omitted here. */
try {
  certificateManager.getPrivateCertificate(uri, (err, cmResult) => {
    if (err != null) {
      console.error(`Failed to get private certificate. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (cmResult?.credential == undefined) {
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

## certificateManager.getPrivateCertificate

getPrivateCertificate(keyUri: string): Promise\<CMResult>

Obtains detailed information about a private credential. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | Yes  | Unique identifier of the target credential.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](#cmresult)> | Promise used to return the private credential details obtained, that is, **credential** in the [CMResult](#cmresult) object.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error. |
| 17500002 | The certificate does not exist. |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri: string = 'test'; /* URI of the credential installed. The process for installing the credential is omitted here. */
try {
  certificateManager.getPrivateCertificate(uri).then((cmResult) => {
    if (cmResult?.credential == undefined) {
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

## certificateManager.uninstallPrivateCertificate

uninstallPrivateCertificate(keyUri: string, callback: AsyncCallback\<void>): void

Uninstalls a private credential. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | Yes  | Unique identifier of the credential to uninstall.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error. |
| 17500002 | The certificate does not exist. |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';

let uri: string = 'test'; /* URI of the credential installed. The process for installing the credential is omitted here. */
try {
  certificateManager.uninstallPrivateCertificate(uri, (err, result) => {
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

## certificateManager.uninstallPrivateCertificate

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
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error. |
| 17500002 | The certificate does not exist. |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri: string = 'test'; /* URI of the credential installed. The process for installing the credential is omitted here. */
try {
  certificateManager.uninstallPrivateCertificate(uri).then((cmResult) => {
    console.info('Succeeded in uninstalling private certificate.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to uninstall private certificate. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to uninstall private certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.installUserTrustedCertificateSync<sup>16+</sup>

installUserTrustedCertificateSync(cert: Uint8Array, certScope: CertScope) : CMResult

Installs a user CA certificate.

**Required permissions**: ohos.permission.ACCESS_ENTERPRISE_USER_TRUSTED_CERT<!--Del--> or ohos.permission.ACCESS_USER_TRUSTED_CERT<!--DelEnd-->

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name      | Type                        | Mandatory| Description          |
|-----------|----------------------------|----|--------------|
| cert      | Uint8Array                 | Yes | Data of the CA certificate to install.   |
| certScope | [CertScope](#certscope16)  | Yes | Scope of the CA certificate.|

**Return value**

| Type                   | Description                               |
|-----------------------|-----------------------------------|
| [CMResult](#cmresult) | CA certificate installation result. The **uri** property in **CMResult** is returned if the certificate is installed successfully.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID                 | Error Message                                                                                                                                           |
|------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201                    | Permission verification failed. The application does not have the permission required to call the API.                                          |
| 401                    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001               | Internal error.                                                                                                                                 |
| 17500003               | Indicates that the certificate is in an invalid format.                                                                                         |
| 17500004<sup>12+</sup> | Indicates that the number of certificates reaches the maximum allowed.                                                                          |
| 17500007<sup>16+</sup> | Indicates that the device enters advanced security mode. In this mode, the user CA certificate cannot be installed.                             |

**Example**

```ts
import {certificateManager} from '@kit.DeviceCertificateKit';

/* The CA certificate data must be assigned by the service. In this example, the data is not CA certificate data. */
let certData: Uint8Array = new Uint8Array([
    0x30, 0x82, 0x0b, 0xc1, 0x02, 0x01,
]);
try {
    let result: certificateManager.CMResult = certificateManager.installUserTrustedCertificateSync(certData, certificateManager.CertScope.CURRENT_USER);
    let certUri = result.uri;
    if (certUri === undefined) {
        console.error("The result of install user trusted certificate is undefined.");
    } else {
        console.info("Successed to install user trusted certificate.");
    }
} catch (error) {
    console.error(`Failed to install user trusted certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.uninstallUserTrustedCertificateSync<sup>16+</sup>

uninstallUserTrustedCertificateSync(certUri: string) : void

Uninstalls a user CA certificate.

**Required permissions**: ohos.permission.ACCESS_ENTERPRISE_USER_TRUSTED_CERT<!--Del--> or ohos.permission.ACCESS_USER_TRUSTED_CERT<!--DelEnd-->

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name      | Type                        | Mandatory| Description          |
|-----------|----------------------------|----|--------------|
| certUri     | string                 | Yes | Unique identifier of the certificate to uninstall.   |

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID                 | Error Message                                                                                                                                           |
|------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201                    | Permission verification failed. The application does not have the permission required to call the API.                                          |
| 401                    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001               | Internal error.                                                                                                                                 |
| 17500002               | Indicates that the certificate does not exist.                                                                                                  |

**Example**

```ts
import {certificateManager} from '@kit.DeviceCertificateKit';

let certUri: string = "test"; /* Unique identifier of the certificate installed. The installation process is omitted here. */
try {
    certificateManager.uninstallUserTrustedCertificateSync(certUri);
} catch (error) {
    console.error(`Failed to uninstall user trusted certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.init

init(authUri: string, spec: CMSignatureSpec, callback: AsyncCallback\<CMHandle>): void

Initializes the signing or signature verification operation using the specified credential. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| authUri | string                   | Yes  | Unique identifier of the credential to use.|
| spec | [CMSignatureSpec](#cmsignaturespec) | Yes  | Parameters for the signing or signature verification operation.|
| callback | AsyncCallback\<[CMHandle](#cmhandle)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the obtained **CMHandle**. Otherwise, **err** is an error object.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error. |
| 17500002 | The certificate does not exist. |
| 17500005<sup>12+</sup> | The application is not authorized by the user. |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';

let uri: string = 'test'; /* URI of the credential installed. The process for installing the credential is omitted here. */
const req: certificateManager.CMSignatureSpec = {
  purpose: certificateManager.CmKeyPurpose.CM_KEY_PURPOSE_SIGN,
  padding: certificateManager.CmKeyPadding.CM_PADDING_PSS,
  digest: certificateManager.CmKeyDigest.CM_DIGEST_SHA256
}
try {
  certificateManager.init(uri, req, (err, cmHandle) => {
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

## certificateManager.init

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
| Promise\<[CMHandle](#cmhandle)> | Promise used to return a **CMHandle** object.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error. |
| 17500002 | The certificate does not exist. |
| 17500005<sup>12+</sup> | The application is not authorized by the user. |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri: string = 'test'; /* URI of the credential installed. The process for installing the credential is omitted here. */
const req: certificateManager.CMSignatureSpec = {
  purpose: certificateManager.CmKeyPurpose.CM_KEY_PURPOSE_VERIFY,
  padding: certificateManager.CmKeyPadding.CM_PADDING_PSS,
  digest: certificateManager.CmKeyDigest.CM_DIGEST_MD5
}
try {
  certificateManager.init(uri, req).then((handle) => {
    console.info('Succeeded in initiating.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to init. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to init. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.update

update(handle: Uint8Array, data: Uint8Array, callback: AsyncCallback\<void>): void

Updates the data for the signing or signature verification operation. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | Yes  | Operation handle returned by **init()**.|
| data | Uint8Array                   | Yes  | Data to be signed or verified.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error.     |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';

/* cmHandle is the value returned by init(). The value here is only an example. */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
let srcData: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certificateManager.update(cmHandle, srcData, (err, result) => {
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

## certificateManager.update

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
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error.     |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

/* cmHandle is the value returned by init(). The value here is only an example. */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
let srcData: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certificateManager.update(cmHandle, srcData).then((result) => {
    console.info('Succeeded in updating.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to update. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to update. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.finish

finish(handle: Uint8Array, callback: AsyncCallback\<CMResult>): void

Finishes the signing operation. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | Yes  | Operation handle returned by **init()**.|
| callback | AsyncCallback\<[CMResult](#cmresult)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the signature, that is, **outData** of the [CMResult](#cmresult) object. Otherwise, **err** is an error object.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error.     |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';

/* cmHandle is the value returned by init(). The value here is only an example. */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certificateManager.finish(cmHandle, (err, cmResult) => {
    if (err != null) {
      console.error(`Failed to finish. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (cmResult?.outData != undefined) {
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

## certificateManager.finish

finish(handle: Uint8Array, signature: Uint8Array, callback: AsyncCallback\<CMResult>): void

Finishes the signature verification operation. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | Yes  | Operation handle returned by **init()**.|
| signature | Uint8Array                   | Yes  | Signature data to verify.|
| callback | AsyncCallback\<[CMResult](#cmresult)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error.     |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';

/* cmHandle is the value returned by init(). The value here is only an example. */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
let signRes: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certificateManager.finish(cmHandle, signRes, (err, cmResult) => {
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

## certificateManager.finish

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
| Promise\<[CMResult](#cmresult)> | Promise used to return the result. For a signing operation, the promise returns the signature, that is, **outData** in the [CMResult](#cmresult) object, is returned. For a signature verification operation, the promise returns no value.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error.     |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

/* cmHandle is the value returned by init(). The value here is only an example. */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  /* Finish the signing operation. */
  certificateManager.finish(cmHandle).then((cmResult) => {
    if (cmResult?.outData != undefined) {
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
  certificateManager.finish(cmHandle, signRes).then((cmResult) => {
    console.info('Succeeded in finishing verification.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to finish verification. Code: ${err.code}, message: ${err.message}`);
  })
} catch(error) {
  console.error(`Failed to finish. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.abort

abort(handle: Uint8Array, callback: AsyncCallback\<void>): void

Aborts the signing or signature verification operation. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | Yes  | Operation handle returned by **init()**.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error.     |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';

/* cmHandle is the value returned by init(). The value here is only an example. */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certificateManager.abort(cmHandle, (err, cmResult) => {
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

## certificateManager.abort

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
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error.     |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

/* cmHandle is the value returned by init(). The value here is only an example. */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certificateManager.abort(cmHandle).then((result) => {
    console.info('Succeeded in aborting.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to abort. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to abort. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.getPublicCertificate<sup>12+</sup>

getPublicCertificate(keyUri: string): Promise\<CMResult>

Obtains detailed information about a public credential. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | Yes  | Unique identifier of the public credential.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](#cmresult)> | Promise used to return the detailed information about the user's public credential obtained, that is, **credential** in the [CMResult](#cmresult) object.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error. |
| 17500002 | The certificate does not exist. |
| 17500005 | The application is not authorized by the user. |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri: string = 'test'; /* Unique identifier of the public credential. The process for installing the public credential is omitted here. */
try {
  certificateManager.getPublicCertificate(uri).then((cmResult) => {
    if (cmResult?.credential == undefined) {
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

## certificateManager.isAuthorizedApp<sup>12+</sup>

isAuthorizedApp(keyUri: string): Promise\<boolean>

Checks whether this application is authorized by the specified user credential. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | Yes  | Unique identifier of the credential.|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return a Boolean value, which indicates whether the application is authorized by the specified user credential.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error. |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri: string = 'test'; /* Unique identifier of the credential. The process for authorizing the credential to the application is omitted here. */
try {
  certificateManager.isAuthorizedApp(uri).then((res) => {
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

## certificateManager.getAllUserTrustedCertificates<sup>12+</sup>

getAllUserTrustedCertificates(): Promise\<CMResult>

Obtains all user trusted root CA certificates of the device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](#cmresult)> | Promise used to return the user's root CA certificates obtained, that is, **certList** in the [CMResult](#cmresult) object.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 17500001 | Internal error. |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  certificateManager.getAllUserTrustedCertificates().then((cmResult) => {
    if (cmResult == undefined) { // If the number of root CA certificates is 0, return undefined in cmResult.
      console.info('the count of the user trusted certificates is 0');
    } else if (cmResult.certList == undefined) {
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

## certificateManager.getAllUserTrustedCertificates<sup>16+</sup>

getAllUserTrustedCertificates(scope: CertScope): Promise\<CMResult>

Obtains the user root CA certificates based on the certificate scope. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name| Type                     | Mandatory| Description            |
| ------ | ------------------------- | ---- | ---------------- |
| scope  | [CertScope](#certscope16) | Yes  | Scope of the certificates to obtain.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](#cmresult)> | Promise used to return the user's root CA certificates obtained, that is, **certList** in the [CMResult](#cmresult) object.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error.                                              |

**Example**

```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  /* Obtain the user root CA certificates of the current user. To obtain the user root CA certificates accessible to all users, pass in GLOBAL_USER. */
  let scope: certificateManager.CertScope = certificateManager.CertScope.CURRENT_USER;
  certificateManager.getAllUserTrustedCertificates(scope).then((cmResult) => {
    if (cmResult == undefined) { // If the number of root CA certificates is 0, return undefined in cmResult.
      console.info('the count of the user trusted certificates is 0');
    } else if (cmResult.certList == undefined) {
      console.info('The result of getting current user trusted certificates is undefined.');
    } else {
      let list = cmResult.certList;
      console.info('Succeeded in getting current user trusted certificates.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get current user trusted certificates. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get current user trusted certificates. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.getUserTrustedCertificate<sup>12+</sup>

getUserTrustedCertificate(certUri: string): Promise\<CMResult>

Obtains the detailed information about a user root CA certificate. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| certUri | string                   | Yes  | Unique identifier of the user root CA certificate.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](#cmresult)> | Promise used to return the detailed CA certificate information obtained, that is, **certInfo** in the [CMResult](#cmresult) object.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error. |
| 17500002 | The certificate does not exist. |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let certUri: string = 'testUserCert'; /* Unique identifier of the user root CA certificate. The process of installing the user root CA certificate is omitted here. */
try {
  certificateManager.getUserTrustedCertificate(certUri).then((cmResult) => {
    if (cmResult?.certInfo == undefined) {
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
## certificateManager.getPrivateCertificates<sup>13+</sup>

getPrivateCertificates(): Promise\<CMResult>

Obtains the credentials for installing the application. This API uses a promise to return the result asynchronously.

**Required permissions**: ohos.permission.ACCESS_CERT_MANAGER

**System capability**: System SystemCapability.Security.CertificateManager

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](#cmresult)> | Promise used to return the credentials obtained, which is **credentialList** in [CMResult](#cmresult).|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 17500001 | Internal error. |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  certificateManager.getPrivateCertificates().then((cmResult) => {
    if (cmResult = = undefined) { // If the number of certificate credentials is 0, return undefined in cmResult.
      console.info('the count of the private certificates is 0');
    } else if (cmResult.credentialList == undefined) {
      console.info('The result of getting all private certificates installed by the application is undefined.');
    } else {
      let list = cmResult.credentialList;
      console.info('Succeeded in getting all private certificates installed by the application.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get all private certificates installed by the application. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get all private certificates installed by the application. Code: ${error.code}, message: ${error.message}`);
}
```
## certificateManager.getCertificateStorePath<sup>16+</sup>

getCertificateStorePath(property: CertStoreProperty): string;

Obtains the certificate storage path.

**System capability**: System SystemCapability.Security.CertificateManager

**Parameters**

| Name  | Type                                     | Mandatory| Description                            |
| -------- | ----------------------------------------- | ---- | -------------------------------- |
| property | [CertStoreProperty](#certstoreproperty16) | Yes  | Storage information about the target certificate.|

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| string | Certificate storage path obtained.|

**Error codes**

For details about the following error codes, see [Certificate Management Error Codes](errorcode-certManager.md).

| ID| Error Message     |
| -------- | ------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error. |

**Example**
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';

try {
  /* Obtain the storage path of the system CA certificates. */
  let property1: certificateManager.CertStoreProperty = {
    certType: certificateManager.CertType.CA_CERT_SYSTEM,
  }
  let systemCAPath = certificateManager.getCertificateStorePath(property1);
  console.info(`Success to get system ca path: ${systemCAPath}`);
    
  /* Obtain the storage path of the CA certificates for the current user. */
  let property2: certificateManager.CertStoreProperty = {
    certType: certificateManager.CertType.CA_CERT_USER,
    certScope: certificateManager.CertScope.CURRENT_USER,
  }
  let userCACurrentPath = certificateManager.getCertificateStorePath(property2);
  console.info(`Success to get current user's user ca path: ${userCACurrentPath}`);
  
  /* Obtain the storage path of the CA certificates for all users. */
  let property3: certificateManager.CertStoreProperty = {
    certType: certificateManager.CertType.CA_CERT_USER,
    certScope: certificateManager.CertScope.GLOBAL_USER,
  }
  let globalCACurrentPath = certificateManager.getCertificateStorePath(property3);
  console.info(`Success to get global user's user ca path: ${globalCACurrentPath}`);
} catch (error) {
  console.error(`Failed to get store path. Code: ${error.code}, message: ${error.message}`);
}
```
