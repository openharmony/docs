# @ohos.security.cert (Certificate)

The certificate algorithm library framework provides certificate-related APIs. For details about the APIs for implementing the basic algorithm capabilities based on the cryptographic (crypto) framework, see [Crypto Framework](js-apis-cryptoFramework.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import certFramework from '@ohos.security.cert';
import cryptoFramework from '@ohos.security.cryptoFramework';
```

## CertResult

 Enumerates the error codes.

 **System capability**: SystemCapability.Security.Cert

| Name                                 | Value  | Description                         |
| --------------------------------------| -------- | -----------------------------|
| INVALID_PARAMS                        | 401      | Invalid parameters.                   |
| NOT_SUPPORT                           | 801      | This operation is not supported.                 |
| ERR_OUT_OF_MEMORY                     | 19020001 | Memory error.                   |
| ERR_RUNTIME_ERROR                     | 19020002 | Runtime error.             |
| ERR_CRYPTO_OPERATION                  | 19030001 | Crypto operation error.      |
| ERR_CERT_SIGNATURE_FAILURE            | 19030002 | The certificate signature verification failed.           |
| ERR_CERT_NOT_YET_VALID                | 19030003 | The certificate has not taken effect.               |
| ERR_CERT_HAS_EXPIRED                  | 19030004 | The certificate has expired.                  |
| ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY | 19030005 | Failed to obtain the certificate issuer.       |
| ERR_KEYUSAGE_NO_CERTSIGN              | 19030006 | The key cannot be used for signing a certificate.  |
| ERR_KEYUSAGE_NO_DIGITAL_SIGNATURE     | 19030007 |  The key cannot be used for digital signature. |

## DataBlob
Defines a binary data array.
 **System capability**: SystemCapability.Security.Cert
| Name          | Type          | Readable| Writable| Description             |
| -------------- | -------------- | ---- | ---- | ----------------|
| data           | Uint8Array     | Yes  | Yes  | Data.   |

## DataArray

Defines a list of data arrays.
 **System capability**: SystemCapability.Security.Cert
| Name          | Type          | Readable| Writable| Description              |
| -------------- | -------------- | ---- | ---- | ----------------|
| data           | Uint8Array     | Yes  | Yes  | Data list.   |

## EncodingFormat

 Enumerates the certificate encoding formats.

 **System capability**: SystemCapability.Security.Cert

| Name      | Value|  Description     |
| ---------- | ------ | --------- |
| FORMAT_DER | 0      | Distinguished Encoding Rules (DER) format.|
| FORMAT_PEM | 1      | Privacy-Enhanced Mail (PEM) format.|
| FORMAT_PKCS7<sup>11+</sup> | 2 | PKCS7 format.|

## CertItemType<sup>10+</sup>

 Enumerates the certificate fields that can be obtained.

 **System capability**: SystemCapability.Security.Cert

| Name                            | Value  | Description                          |
| -------------------------------- | ---- | ------------------------------ |
| CERT_ITEM_TYPE_TBS               | 0    | Information to be signed.    |
| CERT_ITEM_TYPE_PUBLIC_KEY        | 1    | Public key of the certificate.      |
| CERT_ITEM_TYPE_ISSUER_UNIQUE_ID  | 2    | Unique ID of the certificate issuer.|
| CERT_ITEM_TYPE_SUBJECT_UNIQUE_ID | 3    | Unique ID of the certificate subject.  |
| CERT_ITEM_TYPE_EXTENSIONS        | 4    | Certificate extensions, each of which is identified by a unique object identifier (OID).    |

## ExtensionOidType<sup>10+</sup>

 Enumerates the OID types of the certificate extensions that can be obtained.

 **System capability**: SystemCapability.Security.Cert

| Name                         | Value  | Description                                         |
| ----------------------------- | ---- | --------------------------------------------- |
| EXTENSION_OID_TYPE_ALL        | 0    | All object identifiers.           |
| EXTENSION_OID_TYPE_CRITICAL   | 1    | Object identifier whose **critical** is **true**. |
| EXTENSION_OID_TYPE_UNCRITICAL | 2    | Object identifier whose **critical** is **false**.|

## ExtensionEntryType<sup>10+</sup>

 Enumerates the object types in certificate extensions that can be obtained.

 **System capability**: SystemCapability.Security.Cert

| Name                               | Value  | Description                        |
| ----------------------------------- | ---- | ---------------------------- |
| EXTENSION_ENTRY_TYPE_ENTRY          | 0    | Entire object.          |
| EXTENSION_ENTRY_TYPE_ENTRY_CRITICAL | 1    | Critical attribute of the object.|
| EXTENSION_ENTRY_TYPE_ENTRY_VALUE    | 2    | Data of the object.        |

## EncodingBlob

Defines a certificate binary array in encoding format.

### Attributes

**System capability**: SystemCapability.Security.Cert

| Name          | Type                             | Readable| Writable| Description                          |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------ |
| data           | Uint8Array                        | Yes  | Yes  | Certificate data.|
| encodingFormat | [EncodingFormat](#encodingformat) | Yes  | Yes  | Certificate encoding format.            |


## CertChainData

Defines the certificate chain data, which is passed in as input parameters during certificate chain verification.

### Attributes

**System capability**: SystemCapability.Security.Cert

| Name          | Type                             | Readable| Writable| Description                                                        |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| data           | Uint8Array                        | Yes  | Yes  | Certificate data, in the *length* (2 bytes) + *data* format. For example, **08ABCDEFGH07ABCDEFG**. The first two bytes indicate the length of the first certificate is eight bytes, and the following eight bytes indicate the certificate data. Then, the next two bytes indicate the length of another certificate is seven bytes, and the seven bytes followed indicate the certificate data.|
| count          | number                            | Yes  | Yes  | Number of certificates contained in the input data.                              |
| encodingFormat | [EncodingFormat](#encodingformat) | Yes  | Yes  | Certificate encoding format.                                          |

## X509CertMatchParameters<sup>11+</sup>

Defines the parameters used to match a certificate. If no parameter is specified, all certificates are matched.

**System capability**: SystemCapability.Security.Cert

| Name          | Type                             | Mandatory| Description              |
| -------------- | --------------------------------- | ---- | ------------------ |
| x509Cert | [X509Cert](#x509cert)    | No|  Certificate object. |
| validDate | string    | No |  Certificate validity period. |
| issuer | Uint8Array | No | Certificate issuer, in DER format.|
| keyUsage | Array\<boolean> | No | Key usage.|
| serialNumber | bigint    | No |  Serial number of the certificate. |
| subject | Uint8Array | No | Certificate subject, in DER format.|
| publicKey | [DataBlob](#datablob) | No | Public key of the certificate, in DER format.|
| publicKeyAlgID | string | No | Algorithm of the certificate public key.|

## X509CRLMatchParameters<sup>11+</sup>

Defines the parameters used to match a CRL. If no parameter is specified, all CRLs are matched.


**System capability**: SystemCapability.Security.Cert

| Name          | Type                             | Mandatory| Description              |
| -------------- | --------------------------------- | ---- | ------------------ |
| issuer | Array\<Uint8Array> | No | Issuers of the certificates. At least one issuer must be matched.|
| x509Cert | [X509Cert](#x509cert)        | No | Certificate object used to determine whether the certificate is in the CRL.|

## X509TrustAnchor<sup>11+</sup>

Represents an X.509 trust anchor, which is used to verify the certificate chain. The certificate or public key in the trust anchor is used as the trusted root to verify the certificate chain.

**System capability**: SystemCapability.Security.Cert

| Name     | Type                 | Readable| Writable| Description                       |
| --------- | --------------------- | ---- | ---- | --------------------------- |
| CACert    | [X509Cert](#x509cert) | Yes  | Yes  | Trusted CA certificate.             |
| CAPubKey  | Uint8Array            | Yes  | Yes  | Public key of the trusted CA certificate, in DER format.|
| CASubject | Uint8Array            | Yes  | Yes  | Subject of the trusted CA certificate, in DER format.|

## CertChainValidationParameters<sup>11+</sup>

Defines the parameters for certificate chain validation.

**System capability**: SystemCapability.Security.Cert

| Name        | Type                                             | Mandatory| Description                                  |
| ------------ | ------------------------------------------------- | ---- | -------------------------------------- |
| date         | string                                            | No  | Validity period of the certificate to validate.            |
| trustAnchors | Array\<[X509TrustAnchor](#x509trustanchor11)>     | Yes  | List of trusted anchors.                      |
| certCRLs     | Array\<[CertCRLCollection](#certcrlcollection11)> | No  | Check whether the certificate is in a CRL.|

## CertChainValidationResult<sup>11+</sup>

Represents the return value of certificate chain validation.

**System capability**: SystemCapability.Security.Cert

| Name       | Type                                 | Readable| Writable| Description          |
| ----------- | ------------------------------------- | ---- | ---- | -------------- |
| trustAnchor | [X509TrustAnchor](#x509trustanchor11) | Yes  | No  | Trust anchor.  |
| entityCert  | [X509Cert](#x509cert)                 | Yes  | No  | Entity certificate.|

## cryptoCert.createX509Cert

createX509Cert(inStream : EncodingBlob, callback : AsyncCallback\<X509Cert>) : void

Creates an **X509Cert** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob)         | Yes  | X.509 certificate serialization data.        |
| callback | AsyncCallback\<[X509Cert](#x509cert)> | Yes  | Callback invoked to return the **X509Cert** instance created.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
  }
});
```

## cryptoCert.createX509Cert

createX509Cert(inStream : EncodingBlob) : Promise\<X509Cert>

Creates an **X509Cert** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                         | Mandatory| Description              |
| -------- | ----------------------------- | ---- | ------------------ |
| inStream | [EncodingBlob](#encodingblob) | Yes  | X.509 certificate serialization data.|

**Return value**

| Type    | Description            |
| ------- | ---------------- |
| Promise\<[X509Cert](#x509cert)> | **X509Cert** instance created.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob).then(x509Cert => {
  console.log('createX509Cert success');
}).catch((error: BusinessError) => {
  console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

## X509Cert

Provides APIs for X.509 certificate operations.

### verify

verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void

Verifies the signature of an X.509 certificate. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                 | Mandatory| Description                                                        |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| key      | cryptoFramework.PubKey     | Yes  | Public key used for signature verification.                                          |
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result. If **error** is **null**, the signature verification is successful. If **error** is not **null**, the signature verification fails.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message          |
| -------- | ------------------ |
| 19030001 | crypto operation error.      |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');

    // Obtain PubKey by using getPublicKey() of the upper-level X509Cert object (or the current certificate object is a self-signed certificate).
    try {
      let pubKey = x509Cert.getPublicKey();

      // Verify the certificate signature.
      x509Cert.verify(pubKey, (err, data) => {
        if (err == null) {
          console.log('verify success');
        } else {
          console.error('verify failed, errCode: ' + err.code + ', errMsg: ' + err.message);
        }
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getPublicKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### verify

verify(key : cryptoFramework.PubKey) : Promise\<void>

Verifies the signature of an X.509 certificate. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| key    | cryptoFramework.PubKey | Yes  | Public key used for signature verification.|

**Return value**

| Type          | Description       |
| -------------- | ----------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message          |
| -------- | ------------------ |
| 19030001 | crypto operation error.      |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob).then(x509Cert => {
  console.log('createX509Cert success');

  try {
    // Obtain PubKey by using getPublicKey() of the upper-level X509Cert object (or the current certificate object is a self-signed certificate).
    let pubKey = x509Cert.getPublicKey();
    x509Cert.verify(pubKey).then(result => {
      console.log('verify success');
    }).catch((error: BusinessError) => {
      console.error('verify failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    });
  } catch (err) {
    console.error('get public key failed');
  }
}).catch((error: BusinessError) => {
  console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getEncoded

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

Obtains the serialized X.509 certificate data. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                                         | Mandatory| Description                            |
| -------- | --------------------------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | Yes  | Callback invoked to return the serialized X.509 certificate data obtained. |

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```ts
import certFramework from '@ohos.security.cert';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    x509Cert.getEncoded((error, data) => {
      if (error != null) {
        console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('getEncoded success');
      }
    });
  }
});
```

### getEncoded

getEncoded() : Promise\<EncodingBlob>

Obtains the serialized X.509 certificate data. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                                   | Description                  |
| --------------------------------------- | ---------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | Promise used to return the serialized X.509 certificate data obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBLzCB1QIUO/QDVJwZLIpeJyPjyTvE43xvE5cwCgYIKoZIzj0EAwIwGjEYMBYG\n' +
  'A1UEAwwPRXhhbXBsZSBSb290IENBMB4XDTIzMDkwNDExMjAxOVoXDTI2MDUzMDEx\n' +
  'MjAxOVowGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYI\n' +
  'KoZIzj0DAQcDQgAEHjG74yMIueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTa\n' +
  'tUsU0i/sePnrKglj2H8Abbx9PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEA\n' +
  '0ce/fvA4tckNZeB865aOApKXKlBjiRlaiuq5mEEqvNACIQDPD9WyC21MXqPBuRUf\n' +
  'BetUokslUfjT6+s/X4ByaxycAA==\n' +
  '-----END CERTIFICATE-----\n';

// Certificate binary data, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};
certFramework.createX509Cert(encodingBlob).then(x509Cert => {
  console.log('createX509Cert success');
  x509Cert.getEncoded().then(result => {
    console.log('getEncoded success');
  }).catch((error: BusinessError) => {
    console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
}).catch((error: BusinessError) => {
  console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getPublicKey

getPublicKey() : cryptoFramework.PubKey

Obtains the public key of this X.509 certificate. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description            |
| ------ | ---------------- |
| cryptoFramework.PubKey | Public key of the X509 certificate obtained. This object is used only for **verify()** of **X509Cert**.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19030001 | crypto operation error.|

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let pubKey = x509Cert.getPublicKey();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getPublicKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### checkValidityWithDate

checkValidityWithDate(date: string) : void

Checks the validity period of this X.509 certificate. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type           | Mandatory| Description       |
| -------- | -------------- | ---- | ---------- |
| date     | string         | Yes  | Date in the YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ format. The date must end with **Z**, which indicates the UTC.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19030001 | crypto operation error.|
| 19030003 | the certificate has not taken effect.                                     |
| 19030004 | the certificate has expired.|

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');

    let date = '231001000001Z';
    // Verify the certificate validity period.
    try {
      x509Cert.checkValidityWithDate(date);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('checkValidityWithDate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getVersion

getVersion() : number

Obtains the X.509 certificate version.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description            |
| ------ | ---------------- |
| number | X.509 certificate version obtained.|

**Example**

```ts
import certFramework from '@ohos.security.cert';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};
certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    let version = x509Cert.getVersion();
  }
});
```

### getSerialNumber<sup>(deprecated)</sup>

getSerialNumber() : number

Obtains the X.509 certificate serial number.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 10. You are advised to use [getCertSerialNumber](#getcertserialnumber10).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | X.509 certificate serial number obtained.|

**Example**

```ts
import certFramework from '@ohos.security.cert';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    let serialNumber = x509Cert.getSerialNumber();
  }
});
```

### getCertSerialNumber<sup>10+</sup>

getCertSerialNumber() : bigint

Obtains the X.509 certificate serial number.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| bigint | X.509 certificate serial number obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020002 | runtime error.                                    |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let serialNumber = x509Cert.getCertSerialNumber();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getCertSerialNumber failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getIssuerName

getIssuerName() : DataBlob

Obtains the X.509 certificate issuer.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                  |
| --------------------- | ---------------------- |
| [DataBlob](#datablob) | X.509 certificate issuer obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let issuerName = x509Cert.getIssuerName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getIssuerName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSubjectName

getSubjectName() : DataBlob

Obtains the subject of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                |
| --------------------- | -------------------- |
| [DataBlob](#datablob) | Subject name obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let subjectName = x509Cert.getSubjectName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSubjectName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getNotBeforeTime

getNotBeforeTime() : string

Obtains the start time of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| string | Start time of the X509 certificate validity period, in the YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ format. The value must end with **Z**, which indicates the UTC.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let notBefore = x509Cert.getNotBeforeTime();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getNotBeforeTime failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getNotAfterTime

getNotAfterTime() : string

Obtains the expiration time of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| string | Expiration time of the X509 certificate validity period, in the YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ format. The value must end with **Z**, which indicates the UTC.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```ts
import certFramework from '@ohos.security.cert';

import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let notAfter = x509Cert.getNotAfterTime();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getNotAfterTime failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignature

getSignature() : DataBlob

Obtains the signature data of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                |
| --------------------- | -------------------- |
| [DataBlob](#datablob) | Signature data obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```ts
import certFramework from '@ohos.security.cert';

import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let signature = x509Cert.getSignature();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignature failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgName

getSignatureAlgName() : string

Obtains the signing algorithm of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| string | X.509 certificate signing algorithm obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```ts
import certFramework from '@ohos.security.cert';

import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let sigAlgName = x509Cert.getSignatureAlgName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgOid

getSignatureAlgOid() : string

Obtains the object identifier (OID) of the X.509 certificate signing algorithm. OIDs are allocated by the International Organization for Standardization (ISO).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                             |
| ------ | --------------------------------- |
| string | OID obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let sigAlgOid = x509Cert.getSignatureAlgOid();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgOid failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgParams

getSignatureAlgParams() : DataBlob

Obtains the signing algorithm parameters of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                    |
| --------------------- | ------------------------ |
| [DataBlob](#datablob) | X.509 certificate signing algorithm parameters obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let sigAlgParams = x509Cert.getSignatureAlgParams();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgParams failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getKeyUsage

getKeyUsage() : DataBlob

Obtains the key usage of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                |
| --------------------- | -------------------- |
| [DataBlob](#datablob) | Key usage of the X.509 certificate obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                    |
| 19030001 | crypto operation error.|

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let keyUsage = x509Cert.getKeyUsage();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getKeyUsage failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getExtKeyUsage

getExtKeyUsage() : DataArray

Obtains the usage of the extended key of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                   | Description                    |
| ----------------------- | ------------------------ |
| [DataArray](#dataarray) | Usage of the extended key obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let extKeyUsage = x509Cert.getExtKeyUsage();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getNotBeforeTime failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getBasicConstraints

getBasicConstraints() : number

Obtains the basic constraints for obtaining this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| number | Basic constraints obtained.|

**Example**

```ts
import certFramework from '@ohos.security.cert';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    let basicConstraints = x509Cert.getBasicConstraints();
  }
});
```

### getSubjectAltNames

getSubjectAltNames() : DataArray

Obtains the Subject Alternative Names (SANs) of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                   | Description                    |
| ----------------------- | ------------------------ |
| [DataArray](#dataarray) | SANs obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let subjectAltNames = x509Cert.getSubjectAltNames();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSubjectAltNames failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getIssuerAltNames

getIssuerAltNames() : DataArray

Obtains the Issuer Alternative Names (IANs) of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                   | Description                      |
| ----------------------- | -------------------------- |
| [DataArray](#dataarray) | IANs obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let issuerAltNames = x509Cert.getIssuerAltNames();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getIssuerAltNames failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getItem<sup>10+</sup>

getItem(itemType: CertItemType) : DataBlob

Obtains the fields in the X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                                     |
| --------------------- | ----------------------------------------- |
| [DataBlob](#datablob) | Returns the obtained fields in DER format.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
  'Qw==\n' +
  '-----END CERTIFICATE-----\n';

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Cert(encodingBlob, (error, x509Cert) => {
  if (error != null) {
    console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Cert success');
    try {
      let tbs = x509Cert.getItem(certFramework.CertItemType.CERT_ITEM_TYPE_TBS);
      let pubKey = x509Cert.getItem(certFramework.CertItemType.CERT_ITEM_TYPE_PUBLIC_KEY);
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getItem failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```
### match<sup>11+</sup>

match(param: X509CertMatchParameters): boolean

Matches a certificate.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name   | Type  | Mandatory| Description                                      |
| --------- | ------ | ---- | ------------------------------------------ |
| param | [X509CertMatchParameters](#x509certmatchparameters11) | Yes  | Parameters used to match the certificate.|

**Return value**

| Type                 | Description                                     |
| --------------------- | ----------------------------------------- |
| boolean | Returns **true** if a certificate is matched; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509Cert(): Promise<certFramework.X509Cert> {
  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
    'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
    'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
    'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
    'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
    'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
    'Qw==\n' +
    '-----END CERTIFICATE-----\n';

  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certData),
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: certFramework.X509Cert = {} as certFramework.X509Cert;
  try {
    x509Cert = await certFramework.createX509Cert(encodingBlob);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509Cert;
}

async function matchX509Cert() {
  const x509Cert = await createX509Cert();
  try {
    // The value should be assigned by the service side.
    const param: certFramework.X509CertMatchParameters = {
      x509Cert,
      validDate: '20231121074700Z',
      issuer: new Uint8Array([0x30, 0x64, 0x31]), // The values need to be assigned by the service side.
      keyUsage: [false, false, false, false, false, false, true, true, true],
      serialNumber: BigInt('232100834349818463'),
      subject: new Uint8Array([0x30, 0x6c, 0x31]), // The values need to be assigned by the service side.
      publicKey: {
        data: new Uint8Array([0x30, 0x82, 0x01]) // The values need to be assigned by the service side.
      },
      publicKeyAlgID: '1.2.840.113549.1.1.1'
    };
    const result = x509Cert.match(param);
    console.log('call x509Cert match success');
  } catch (err) {
    console.error('call x509Cert match failed');
  }
}
```
## cryptoCert.createCertExtension<sup>10+</sup>

createCertExtension(inStream : EncodingBlob, callback : AsyncCallback\<CertExtension>) : void

Creates a **CertExtension** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                                             | Mandatory| Description                      |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob)                     | Yes  | Serialized data of the certificate extension.|
| callback | AsyncCallback\<[CertExtension](#certextension10)> | Yes  | Callback invoked to return the **CertExtension** instance created.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';

// Binary data of the certificate extensions, which must be assigned based on the service.
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: certFramework.EncodingBlob = {
  data: extData,
  // Assign a value based on the encodingData format. Currently, only FORMAT_DER is supported.
  encodingFormat: certFramework.EncodingFormat.FORMAT_DER
};

certFramework.createCertExtension(encodingBlob, (error, certExt) => {
  if (error != null) {
    console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createCertExtension success');
  }
});
```

## cryptoCert.createCertExtension<sup>10+</sup>

createCertExtension(inStream : EncodingBlob) : Promise\<CertExtension>

Creates a **CertExtension** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                         | Mandatory| Description                      |
| -------- | ----------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob) | Yes  | Serialized data of the certificate extension.|

**Return value**

| Type                                       | Description                |
| ------------------------------------------- | -------------------- |
| Promise\<[CertExtension](#certextension10)> | Promise used to return the **CertExtension** instance created.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Binary data of the certificate extensions, which must be assigned based on the service.
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: certFramework.EncodingBlob = {
  data: extData,
  // Assign a value based on the encodingData format. Currently, only FORMAT_DER is supported.
  encodingFormat: certFramework.EncodingFormat.FORMAT_DER
};

certFramework.createCertExtension(encodingBlob).then(certExt => {
  console.log('createCertExtension success');
}).catch((error: BusinessError) => {
  console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

## CertExtension<sup>10+</sup>

Provides APIs for operating the certificate extensions.

### getEncoded<sup>10+</sup>

getEncoded() : EncodingBlob

Obtains the serialized data of the certificate extensions.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                         | Description                        |
| ----------------------------- | ---------------------------- |
| [EncodingBlob](#encodingblob) | Serialized data obtained. |

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Binary data of the certificate extensions, which must be assigned based on the service.
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: certFramework.EncodingBlob = {
  data: extData,
  // Assign a value based on the encodingData format. Currently, only FORMAT_DER is supported.
  encodingFormat: certFramework.EncodingFormat.FORMAT_DER
};

certFramework.createCertExtension(encodingBlob, (error, certExt) => {
  if (error != null) {
    console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createCertExtension success');
    try {
      let extEncodedBlob = certExt.getEncoded();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('ext getEncoded failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getOidList<sup>10+</sup>

getOidList(valueType : ExtensionOidType) : DataArray

Obtains the OIDs of the certificate extensions.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name   | Type                                 | Mandatory| Description                          |
| --------- | ------------------------------------- | ---- | ------------------------------ |
| valueType | [ExtensionOidType](#extensionoidtype) | Yes  | Type of the OIDs to obtain.|

**Return value**

| Type                   | Description                            |
| ----------------------- | -------------------------------- |
| [DataArray](#dataarray) | A list of the OIDs obtained. |

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Binary data of the certificate extensions, which must be assigned based on the service.
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: certFramework.EncodingBlob = {
  data: extData,
  // Assign a value based on the encodingData format. Currently, only FORMAT_DER is supported.
  encodingFormat: certFramework.EncodingFormat.FORMAT_DER
};

certFramework.createCertExtension(encodingBlob, (error, certExt) => {
  if (error != null) {
    console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createCertExtension success');
    try {
      let oidList = certExt.getOidList(certFramework.ExtensionOidType.EXTENSION_OID_TYPE_ALL);
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('ext getOidList failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getEntry<sup>10+</sup>

getEntry(valueType: ExtensionEntryType, oid : DataBlob) : DataBlob

Obtains the certificate extension object information.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name   | Type                                     | Mandatory| Description                            |
| --------- | ----------------------------------------- | ---- | -------------------------------- |
| valueType | [ExtensionEntryType](#extensionentrytype) | Yes  | Type of the information to obtain.      |
| oid       | [DataBlob](#datablob)                     | Yes  | OID of the certificate extension to obtain.|

**Return value**

| Type                 | Description                        |
| --------------------- | ---------------------------- |
| [DataBlob](#datablob) | Certificate extension object information obtained. |

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Binary data of the certificate extensions, which must be assigned based on the service.
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: certFramework.EncodingBlob = {
  data: extData,
  // Assign a value based on the encodingData format. Currently, only FORMAT_DER is supported.
  encodingFormat: certFramework.EncodingFormat.FORMAT_DER
};

certFramework.createCertExtension(encodingBlob, (error, certExt) => {
  if (error != null) {
    console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createCertExtension success');
    let oid = new Uint8Array([0x32, 0x2e, 0x35, 0x2e, 0x32, 0x39, 0x2e, 0x31, 0x35]);
    let oidBlob: certFramework.DataBlob = {
      data: oid
    }
    try {
      let entry = certExt.getEntry(certFramework.ExtensionEntryType.EXTENSION_ENTRY_TYPE_ENTRY, oidBlob);
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('ext getEntry failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```


### checkCA<sup>10+</sup>

checkCA() : number

Checks whether the certificate is a CA certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| number | If the key purpose in the certificate extension contains signing and the CA field in the basic constraints is **true**, the certificate is a CA certificate. Returns **-1** if the certificate is not a CA certificate; returns the path length in the basic constraints otherwise. Returns **-2** if the certificate is a CA certificate but the path length is not specified in the basic constraints, which means the path length is not limited.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Binary data of the certificate extensions, which must be assigned based on the service.
let extData = new Uint8Array([
  0x30, 0x40, 0x30, 0x0F, 0x06, 0x03, 0x55, 0x1D,
  0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03,
  0x01, 0x01, 0xFF, 0x30, 0x0E, 0x06, 0x03, 0x55,
  0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03,
  0x02, 0x01, 0xC6, 0x30, 0x1D, 0x06, 0x03, 0x55,
  0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0xE0, 0x8C,
  0x9B, 0xDB, 0x25, 0x49, 0xB3, 0xF1, 0x7C, 0x86,
  0xD6, 0xB2, 0x42, 0x87, 0x0B, 0xD0, 0x6B, 0xA0,
  0xD9, 0xE4
]);

let encodingBlob: certFramework.EncodingBlob = {
  data: extData,
  // Assign a value based on the encodingData format. Currently, only FORMAT_DER is supported.
  encodingFormat: certFramework.EncodingFormat.FORMAT_DER
};
certFramework.createCertExtension(encodingBlob, (error, certExt) => {
  if (error != null) {
    console.error('createCertExtension failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createCertExtension success');
    try {
      let res = certExt.checkCA();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('ext checkCA failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### hasUnsupportedCriticalExtension<sup>11+</sup>

hasUnsupportedCriticalExtension(): boolean

Checks whether there is critical extension that is not supported.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type   | Description                                                   |
| ------- | ------------------------------------------------------- |
| boolean | Returns **true** if unsupported critical extension is found; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import cert from "@ohos.security.cert";
import { BusinessError } from '@ohos.base';

const encodingData = [
  0x30, 0x40, 0x30, 0x0f, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x01, 0x01, 0xff, 0x04,
  0x05, 0x30, 0x03, 0x01, 0x01, 0xff, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x1d, 0x0f,
];
let encodingBlob: cert.EncodingBlob = {
  data: new Uint8Array(encodingData),
  encodingFormat: cert.EncodingFormat.FORMAT_DER
};

cert.createCertExtension(encodingBlob).then((extensionObj) => {
  console.log('createCertExtension success!');
  const result = extensionObj.hasUnsupportedCriticalExtension()
  console.log('has unsupported critical extension result is:' + result);
}).catch((err: BusinessError) => {
  console.error('createCertExtension failed');
});
```

## cryptoCert.createX509Crl<sup>(deprecated)</sup>

createX509Crl(inStream : EncodingBlob, callback : AsyncCallback\<X509Crl>) : void

Creates an **X509Crl** instance. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [cryptoCert.createX509CRL](#cryptocertcreatex509crl11).

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                               | Mandatory| Description                          |
| -------- | ----------------------------------- | ---- | ------------------------------ |
| inStream | [EncodingBlob](#encodingblob)       | Yes  | Serialized certificate revocation list (CRL) data.    |
| callback | AsyncCallback\<[X509Crl](#x509crl)> | Yes  | Callback invoked to return the **X509Crl** instance created. |

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
  }
});
```

## cryptoCert.createX509Crl<sup>(deprecated)</sup>

createX509Crl(inStream : EncodingBlob) : Promise\<X509Crl>

Creates an **X509Crl** instance. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [cryptoCert.createX509CRL](#cryptocertcreatex509crl11-1).

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                         | Mandatory| Description                      |
| -------- | ----------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob) | Yes  | Serialized CRL data.|

**Return value**

| Type                         | Description                |
| ----------------------------- | -------------------- |
| Promise\<[X509Crl](#x509crl)> | Promise used to return the **X509Crl** instance created.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob).then(x509Crl => {
  console.log('createX509Crl success');
}).catch((error: BusinessError) => {
  console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

## cryptoCert.createX509CRL<sup>11+</sup>

createX509CRL(inStream : EncodingBlob, callback : AsyncCallback\<X509CRL>) : void

Creates an **X509Crl** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                                 | Mandatory| Description                          |
| -------- | ------------------------------------- | ---- | ------------------------------ |
| inStream | [EncodingBlob](#encodingblob)         | Yes  | Serialized certificate revocation list (CRL) data.    |
| callback | AsyncCallback\<[X509CRL](#x509crl11)> | Yes  | Callback invoked to return the **X509Crl** instance created.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, X509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
  }
});
```

## cryptoCert.createX509CRL<sup>11+</sup>

createX509CRL(inStream : EncodingBlob) : Promise\<X509CRL>

Creates an **X509Crl** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                         | Mandatory| Description                      |
| -------- | ----------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob) | Yes  | Serialized CRL data.|

**Return value**

| Type                           | Description                |
| ------------------------------- | -------------------- |
| Promise\<[X509CRL](#x509crl11)> | Promise used to return the **X509Crl** instance created.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob).then(X509CRL => {
  console.log('createX509CRL success');
}).catch((error: BusinessError) => {
  console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

## X509Crl<sup>(deprecated)</sup>

Provides APIs for X.509 certificate CRL operations.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL](#x509crl11).

### isRevoked<sup>(deprecated)</sup>

isRevoked(cert : X509Cert) : boolean

Checks whether an X.509 certificate is revoked.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.isRevoked](#isrevoked11).

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name| Type    | Mandatory| Description                |
| ------ | -------- | ---- | -------------------- |
| cert   | X509Cert | Yes  | X.509 certificate to check.|

**Return value**

| Type     | Description                                          |
| --------- | --------------------------------------------- |
| boolean   | Returns **true** if the certificate is revoked; returns **false** otherwise. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBLzCB1QIUO/QDVJwZLIpeJyPjyTvE43xvE5cwCgYIKoZIzj0EAwIwGjEYMBYG\n' +
  'A1UEAwwPRXhhbXBsZSBSb290IENBMB4XDTIzMDkwNDExMjAxOVoXDTI2MDUzMDEx\n' +
  'MjAxOVowGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYI\n' +
  'KoZIzj0DAQcDQgAEHjG74yMIueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTa\n' +
  'tUsU0i/sePnrKglj2H8Abbx9PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEA\n' +
  '0ce/fvA4tckNZeB865aOApKXKlBjiRlaiuq5mEEqvNACIQDPD9WyC21MXqPBuRUf\n' +
  'BetUokslUfjT6+s/X4ByaxycAA==\n' +
  '-----END CERTIFICATE-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

let certEncodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    // Create an X509Cert instance.
    certFramework.createX509Cert(certEncodingBlob, (error, x509Cert) => {
      if (error == null) {
        try {
          let revokedFlag = x509Crl.isRevoked(x509Cert);
        } catch (error) {
          let e: BusinessError = error as BusinessError;
          console.error('isRevoked failed, errCode: ' + e.code + ', errMsg: ' + e.message);
        }
      }
    });
  }
});
```

### getType<sup>(deprecated)</sup>

getType() : string

Obtains the CRL type.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.getType](#gettype11).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| string | CRL type obtained.|

**Example**

```ts
import certFramework from '@ohos.security.cert';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    let type = x509Crl.getType();
  }
});
```

### getEncoded<sup>(deprecated)</sup>

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

Obtains the serialized X.509 CRL data. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.getEncoded](#getencoded11).

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                        | Mandatory| Description                                      |
| -------- | ---------------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback\<EncodingBlob> | Yes  | Callback invoked to return the serialized X.509 CRL data obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    x509Crl.getEncoded((error, data) => {
      if (error != null) {
        console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('getEncoded success');
      }
    });
  }
});
```

### getEncoded<sup>(deprecated)</sup>

getEncoded() : Promise\<EncodingBlob>

Obtains the serialized X.509 CRL data. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.getEncoded](#getencoded11-1).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                  | Description                            |
| ---------------------- | -------------------------------- |
| Promise\<EncodingBlob> | Promise used to return the serialized X.509 CRL data obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob).then(x509Crl => {
  console.log('createX509Crl success');
  x509Crl.getEncoded().then(result => {
    console.log('getEncoded success');
  }).catch((error: BusinessError) => {
    console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
}).catch((error: BusinessError) => {
  console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### verify<sup>(deprecated)</sup>

verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void

Verifies the signature of the X.509 CRL. This API uses an asynchronous callback to return the result. The RSA algorithm is supported.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.verify](#verify11).

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| key      | cryptoFramework.PubKey | Yes  | Public key used for signature verification.                                      |
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result. If **error** is **null**, the signature verification is successful. If **error** is not **null**, the signature verification fails.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let pubKeyData = new Uint8Array([
  0x30, 0x81, 0x9F, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01,
  0x05, 0x00, 0x03, 0x81, 0x8D, 0x00, 0x30, 0x81, 0x89, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D,
  0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED, 0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE,
  0x76, 0xB0, 0xDB, 0xDF, 0xA1, 0x2C, 0x6C, 0x67, 0x95, 0xDA, 0x63, 0x3D, 0x4F, 0x71, 0x48, 0x8C,
  0x3E, 0xFA, 0x24, 0x79, 0xE9, 0xF2, 0xF2, 0x20, 0xCB, 0xF1, 0x59, 0x6B, 0xED, 0xC8, 0x72, 0x66,
  0x6E, 0x31, 0xD4, 0xF3, 0xCE, 0x0B, 0x12, 0xC4, 0x17, 0x39, 0xB4, 0x52, 0x16, 0xD3, 0xE3, 0xC0,
  0xF8, 0x48, 0xB3, 0xF6, 0x40, 0xD5, 0x47, 0x23, 0x30, 0x7F, 0xA7, 0xC5, 0x5A, 0x5A, 0xBB, 0x5C,
  0x7B, 0xEF, 0x69, 0xE2, 0x74, 0x35, 0x24, 0x22, 0x25, 0x45, 0x7E, 0xFC, 0xE8, 0xC4, 0x52, 0x65,
  0xA0, 0x4E, 0xBC, 0xFD, 0x3F, 0xD9, 0x85, 0x14, 0x8A, 0x5A, 0x93, 0x02, 0x24, 0x6C, 0x19, 0xBA,
  0x81, 0xBE, 0x65, 0x2E, 0xCB, 0xBB, 0xE9, 0x91, 0x7B, 0x7C, 0x47, 0xC2, 0x61, 0x02, 0x03, 0x01,
  0x00, 0x01
]);

let priKeyData = new Uint8Array([
  0x30, 0x82, 0x02, 0x77, 0x02, 0x01, 0x00, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
  0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x04, 0x82, 0x02, 0x61, 0x30, 0x82, 0x02, 0x5D, 0x02, 0x01,
  0x00, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D, 0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED,
  0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE, 0x76, 0xB0, 0xDB, 0xDF, 0xA1, 0x2C, 0x6C, 0x67,
  0x95, 0xDA, 0x63, 0x3D, 0x4F, 0x71, 0x48, 0x8C, 0x3E, 0xFA, 0x24, 0x79, 0xE9, 0xF2, 0xF2, 0x20,
  0xCB, 0xF1, 0x59, 0x6B, 0xED, 0xC8, 0x72, 0x66, 0x6E, 0x31, 0xD4, 0xF3, 0xCE, 0x0B, 0x12, 0xC4,
  0x17, 0x39, 0xB4, 0x52, 0x16, 0xD3, 0xE3, 0xC0, 0xF8, 0x48, 0xB3, 0xF6, 0x40, 0xD5, 0x47, 0x23,
  0x30, 0x7F, 0xA7, 0xC5, 0x5A, 0x5A, 0xBB, 0x5C, 0x7B, 0xEF, 0x69, 0xE2, 0x74, 0x35, 0x24, 0x22,
  0x25, 0x45, 0x7E, 0xFC, 0xE8, 0xC4, 0x52, 0x65, 0xA0, 0x4E, 0xBC, 0xFD, 0x3F, 0xD9, 0x85, 0x14,
  0x8A, 0x5A, 0x93, 0x02, 0x24, 0x6C, 0x19, 0xBA, 0x81, 0xBE, 0x65, 0x2E, 0xCB, 0xBB, 0xE9, 0x91,
  0x7B, 0x7C, 0x47, 0xC2, 0x61, 0x02, 0x03, 0x01, 0x00, 0x01, 0x02, 0x81, 0x80, 0x5A, 0xCF, 0x0F,
  0xF5, 0xA6, 0x1C, 0x19, 0x65, 0x8C, 0x94, 0x40, 0xF6, 0x84, 0x28, 0x74, 0x40, 0x42, 0x34, 0xDE,
  0xC3, 0x00, 0x5E, 0x72, 0x4D, 0x96, 0xE9, 0x4C, 0xBD, 0xC9, 0xDB, 0x14, 0x9F, 0xD5, 0xBB, 0xA9,
  0x0C, 0x20, 0xC2, 0xBE, 0x7A, 0x80, 0x89, 0xEC, 0x99, 0x04, 0xF0, 0xEE, 0x7B, 0x83, 0x20, 0x1D,
  0x37, 0x19, 0x55, 0x85, 0xF6, 0x8E, 0x3B, 0xFB, 0x16, 0xF3, 0xD3, 0x6F, 0xEE, 0x73, 0x12, 0x53,
  0xCA, 0x77, 0xD7, 0x6C, 0x29, 0xF5, 0x08, 0xA3, 0x09, 0x01, 0x0B, 0x00, 0x05, 0x57, 0xAD, 0x4D,
  0xF0, 0x92, 0xB2, 0x5A, 0x8B, 0x19, 0x09, 0x81, 0x86, 0xFE, 0x66, 0xB9, 0x33, 0x88, 0x28, 0xF3,
  0x37, 0x73, 0x09, 0x5F, 0xD7, 0xC9, 0xC6, 0xFA, 0x13, 0x74, 0xFE, 0xAE, 0x53, 0xA9, 0x71, 0x67,
  0xCE, 0x3A, 0xE6, 0x8D, 0x35, 0xD1, 0xB8, 0xFD, 0x6F, 0x0D, 0x43, 0xC2, 0xD1, 0x02, 0x41, 0x00,
  0xF7, 0x33, 0xE5, 0x6C, 0x29, 0x5A, 0x30, 0x58, 0xA4, 0x52, 0x65, 0xA0, 0x39, 0xC2, 0xE8, 0xAE,
  0x5F, 0xA3, 0x2D, 0x0C, 0x65, 0xB1, 0x7B, 0xFD, 0x92, 0xBF, 0x47, 0x87, 0x97, 0x40, 0xCB, 0x54,
  0xF9, 0xBB, 0x50, 0x27, 0x70, 0x51, 0xD0, 0xD8, 0x48, 0x0D, 0xC6, 0x47, 0x60, 0xF8, 0x4E, 0x0A,
  0x32, 0x76, 0x6D, 0xA4, 0xBA, 0x40, 0xE5, 0x58, 0xF8, 0x4A, 0x39, 0x4E, 0xF8, 0x3F, 0x4E, 0x2D,
  0x02, 0x41, 0x00, 0xE4, 0x23, 0x2A, 0x5F, 0x59, 0xCF, 0x7C, 0x91, 0x24, 0x0D, 0xA2, 0x44, 0x17,
  0xCD, 0x37, 0xDE, 0x1F, 0x53, 0x4D, 0x33, 0x9F, 0x90, 0x4D, 0xD9, 0x72, 0x64, 0x25, 0xBA, 0xAB,
  0x47, 0x91, 0xC4, 0x99, 0x95, 0x86, 0xB5, 0x8A, 0xEA, 0x77, 0xF7, 0x64, 0x72, 0x5E, 0xB7, 0xBB,
  0x16, 0xA1, 0x64, 0xA4, 0xE1, 0x2D, 0x76, 0x6D, 0xEF, 0xB1, 0x5E, 0xD6, 0x17, 0xE8, 0xAA, 0xB6,
  0xA0, 0xD9, 0x85, 0x02, 0x41, 0x00, 0xDF, 0xC8, 0x5B, 0x28, 0x4F, 0x47, 0x15, 0xFD, 0x28, 0xC4,
  0x6E, 0xBB, 0x5D, 0x8E, 0xD4, 0x95, 0x06, 0x7E, 0xF1, 0x89, 0x07, 0x86, 0x64, 0x78, 0x69, 0x20,
  0x3F, 0xE0, 0xBF, 0x4C, 0x28, 0xC6, 0x04, 0x4D, 0x4D, 0x82, 0x66, 0x6B, 0xAA, 0x64, 0x20, 0xD6,
  0x57, 0x68, 0xC6, 0xA0, 0x02, 0x05, 0xB9, 0x28, 0xFC, 0x98, 0xE3, 0x03, 0x5C, 0x9B, 0xEE, 0x29,
  0x43, 0x37, 0xFA, 0x03, 0x55, 0x01, 0x02, 0x40, 0x69, 0x5B, 0x7C, 0x24, 0x10, 0xDB, 0xEB, 0x91,
  0x33, 0xEF, 0x3F, 0xF2, 0xE6, 0x73, 0x15, 0xCB, 0xF4, 0xF7, 0x89, 0x7D, 0xBF, 0xC0, 0xEA, 0xD2,
  0xF3, 0x2B, 0x20, 0xE9, 0x76, 0x54, 0x55, 0x13, 0x50, 0x42, 0x67, 0xB5, 0xCB, 0x73, 0xC0, 0xF7,
  0x75, 0x62, 0x04, 0x30, 0x21, 0xAC, 0xAF, 0xD8, 0x44, 0xF4, 0xE1, 0x04, 0x02, 0x7D, 0x61, 0x92,
  0x84, 0x99, 0x02, 0x10, 0x64, 0xCB, 0x1F, 0xE9, 0x02, 0x41, 0x00, 0xAB, 0x4B, 0x7D, 0x90, 0x7C,
  0x57, 0x08, 0x6B, 0xC0, 0x43, 0x72, 0x09, 0x8A, 0x18, 0x35, 0x36, 0x64, 0x9D, 0x84, 0x8D, 0xF1,
  0x84, 0x94, 0x48, 0xC6, 0x80, 0x9D, 0xB9, 0xA2, 0x58, 0x0A, 0x4D, 0x0A, 0xCA, 0x1E, 0xD6, 0x05,
  0x55, 0x5B, 0xFE, 0xD7, 0xAA, 0x70, 0xED, 0x76, 0xB3, 0x40, 0x2E, 0xA0, 0xB3, 0x32, 0x37, 0xB0,
  0xA0, 0xB9, 0x96, 0x2D, 0xC4, 0x70, 0xE9, 0x99, 0x10, 0x67, 0x8D
]);

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      // Generate the public key by AsyKeyGenerator.
      let keyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_3');
      console.log('createAsyKeyGenerator success');
      let priEncodingBlob: cryptoFramework.DataBlob = {
        data: priKeyData,
      };
      let pubEncodingBlob: cryptoFramework.DataBlob = {
        data: pubKeyData,
      };
      keyGenerator.convertKey(pubEncodingBlob, priEncodingBlob, (e, keyPair) => {
        if (e == null) {
          console.log('convert key success');
          x509Crl.verify(keyPair.pubKey, (err, data) => {
            if (err == null) {
              console.log('verify success');
            } else {
              console.error('verify failed, errCode: ' + err.code + ', errMsg: ' + err.message);
            }
          });
        } else {
          console.error('convert key failed, message: ' + e.message + 'code: ' + e.code);
        }
      })
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('get pubKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### verify<sup>(deprecated)</sup>

verify(key : cryptoFramework.PubKey) : Promise\<void>

Verifies the signature of the X.509 CRL. This API uses a promise to return the result. The RSA algorithm is supported.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.verify](#verify11-1).

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| key    | cryptoFramework.PubKey | Yes  | Public key used for signature verification.|

**Return value**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import cryptoFramework from '@ohos.security.cryptoFramework'
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let pubKeyData = new Uint8Array([
  0x30, 0x81, 0x9F, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01,
  0x05, 0x00, 0x03, 0x81, 0x8D, 0x00, 0x30, 0x81, 0x89, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D,
  0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED, 0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE,
  0x76, 0xB0, 0xDB, 0xDF, 0xA1, 0x2C, 0x6C, 0x67, 0x95, 0xDA, 0x63, 0x3D, 0x4F, 0x71, 0x48, 0x8C,
  0x3E, 0xFA, 0x24, 0x79, 0xE9, 0xF2, 0xF2, 0x20, 0xCB, 0xF1, 0x59, 0x6B, 0xED, 0xC8, 0x72, 0x66,
  0x6E, 0x31, 0xD4, 0xF3, 0xCE, 0x0B, 0x12, 0xC4, 0x17, 0x39, 0xB4, 0x52, 0x16, 0xD3, 0xE3, 0xC0,
  0xF8, 0x48, 0xB3, 0xF6, 0x40, 0xD5, 0x47, 0x23, 0x30, 0x7F, 0xA7, 0xC5, 0x5A, 0x5A, 0xBB, 0x5C,
  0x7B, 0xEF, 0x69, 0xE2, 0x74, 0x35, 0x24, 0x22, 0x25, 0x45, 0x7E, 0xFC, 0xE8, 0xC4, 0x52, 0x65,
  0xA0, 0x4E, 0xBC, 0xFD, 0x3F, 0xD9, 0x85, 0x14, 0x8A, 0x5A, 0x93, 0x02, 0x24, 0x6C, 0x19, 0xBA,
  0x81, 0xBE, 0x65, 0x2E, 0xCB, 0xBB, 0xE9, 0x91, 0x7B, 0x7C, 0x47, 0xC2, 0x61, 0x02, 0x03, 0x01,
  0x00, 0x01
]);

let priKeyData = new Uint8Array([
  0x30, 0x82, 0x02, 0x77, 0x02, 0x01, 0x00, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
  0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x04, 0x82, 0x02, 0x61, 0x30, 0x82, 0x02, 0x5D, 0x02, 0x01,
  0x00, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D, 0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED,
  0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE, 0x76, 0xB0, 0xDB, 0xDF, 0xA1, 0x2C, 0x6C, 0x67,
  0x95, 0xDA, 0x63, 0x3D, 0x4F, 0x71, 0x48, 0x8C, 0x3E, 0xFA, 0x24, 0x79, 0xE9, 0xF2, 0xF2, 0x20,
  0xCB, 0xF1, 0x59, 0x6B, 0xED, 0xC8, 0x72, 0x66, 0x6E, 0x31, 0xD4, 0xF3, 0xCE, 0x0B, 0x12, 0xC4,
  0x17, 0x39, 0xB4, 0x52, 0x16, 0xD3, 0xE3, 0xC0, 0xF8, 0x48, 0xB3, 0xF6, 0x40, 0xD5, 0x47, 0x23,
  0x30, 0x7F, 0xA7, 0xC5, 0x5A, 0x5A, 0xBB, 0x5C, 0x7B, 0xEF, 0x69, 0xE2, 0x74, 0x35, 0x24, 0x22,
  0x25, 0x45, 0x7E, 0xFC, 0xE8, 0xC4, 0x52, 0x65, 0xA0, 0x4E, 0xBC, 0xFD, 0x3F, 0xD9, 0x85, 0x14,
  0x8A, 0x5A, 0x93, 0x02, 0x24, 0x6C, 0x19, 0xBA, 0x81, 0xBE, 0x65, 0x2E, 0xCB, 0xBB, 0xE9, 0x91,
  0x7B, 0x7C, 0x47, 0xC2, 0x61, 0x02, 0x03, 0x01, 0x00, 0x01, 0x02, 0x81, 0x80, 0x5A, 0xCF, 0x0F,
  0xF5, 0xA6, 0x1C, 0x19, 0x65, 0x8C, 0x94, 0x40, 0xF6, 0x84, 0x28, 0x74, 0x40, 0x42, 0x34, 0xDE,
  0xC3, 0x00, 0x5E, 0x72, 0x4D, 0x96, 0xE9, 0x4C, 0xBD, 0xC9, 0xDB, 0x14, 0x9F, 0xD5, 0xBB, 0xA9,
  0x0C, 0x20, 0xC2, 0xBE, 0x7A, 0x80, 0x89, 0xEC, 0x99, 0x04, 0xF0, 0xEE, 0x7B, 0x83, 0x20, 0x1D,
  0x37, 0x19, 0x55, 0x85, 0xF6, 0x8E, 0x3B, 0xFB, 0x16, 0xF3, 0xD3, 0x6F, 0xEE, 0x73, 0x12, 0x53,
  0xCA, 0x77, 0xD7, 0x6C, 0x29, 0xF5, 0x08, 0xA3, 0x09, 0x01, 0x0B, 0x00, 0x05, 0x57, 0xAD, 0x4D,
  0xF0, 0x92, 0xB2, 0x5A, 0x8B, 0x19, 0x09, 0x81, 0x86, 0xFE, 0x66, 0xB9, 0x33, 0x88, 0x28, 0xF3,
  0x37, 0x73, 0x09, 0x5F, 0xD7, 0xC9, 0xC6, 0xFA, 0x13, 0x74, 0xFE, 0xAE, 0x53, 0xA9, 0x71, 0x67,
  0xCE, 0x3A, 0xE6, 0x8D, 0x35, 0xD1, 0xB8, 0xFD, 0x6F, 0x0D, 0x43, 0xC2, 0xD1, 0x02, 0x41, 0x00,
  0xF7, 0x33, 0xE5, 0x6C, 0x29, 0x5A, 0x30, 0x58, 0xA4, 0x52, 0x65, 0xA0, 0x39, 0xC2, 0xE8, 0xAE,
  0x5F, 0xA3, 0x2D, 0x0C, 0x65, 0xB1, 0x7B, 0xFD, 0x92, 0xBF, 0x47, 0x87, 0x97, 0x40, 0xCB, 0x54,
  0xF9, 0xBB, 0x50, 0x27, 0x70, 0x51, 0xD0, 0xD8, 0x48, 0x0D, 0xC6, 0x47, 0x60, 0xF8, 0x4E, 0x0A,
  0x32, 0x76, 0x6D, 0xA4, 0xBA, 0x40, 0xE5, 0x58, 0xF8, 0x4A, 0x39, 0x4E, 0xF8, 0x3F, 0x4E, 0x2D,
  0x02, 0x41, 0x00, 0xE4, 0x23, 0x2A, 0x5F, 0x59, 0xCF, 0x7C, 0x91, 0x24, 0x0D, 0xA2, 0x44, 0x17,
  0xCD, 0x37, 0xDE, 0x1F, 0x53, 0x4D, 0x33, 0x9F, 0x90, 0x4D, 0xD9, 0x72, 0x64, 0x25, 0xBA, 0xAB,
  0x47, 0x91, 0xC4, 0x99, 0x95, 0x86, 0xB5, 0x8A, 0xEA, 0x77, 0xF7, 0x64, 0x72, 0x5E, 0xB7, 0xBB,
  0x16, 0xA1, 0x64, 0xA4, 0xE1, 0x2D, 0x76, 0x6D, 0xEF, 0xB1, 0x5E, 0xD6, 0x17, 0xE8, 0xAA, 0xB6,
  0xA0, 0xD9, 0x85, 0x02, 0x41, 0x00, 0xDF, 0xC8, 0x5B, 0x28, 0x4F, 0x47, 0x15, 0xFD, 0x28, 0xC4,
  0x6E, 0xBB, 0x5D, 0x8E, 0xD4, 0x95, 0x06, 0x7E, 0xF1, 0x89, 0x07, 0x86, 0x64, 0x78, 0x69, 0x20,
  0x3F, 0xE0, 0xBF, 0x4C, 0x28, 0xC6, 0x04, 0x4D, 0x4D, 0x82, 0x66, 0x6B, 0xAA, 0x64, 0x20, 0xD6,
  0x57, 0x68, 0xC6, 0xA0, 0x02, 0x05, 0xB9, 0x28, 0xFC, 0x98, 0xE3, 0x03, 0x5C, 0x9B, 0xEE, 0x29,
  0x43, 0x37, 0xFA, 0x03, 0x55, 0x01, 0x02, 0x40, 0x69, 0x5B, 0x7C, 0x24, 0x10, 0xDB, 0xEB, 0x91,
  0x33, 0xEF, 0x3F, 0xF2, 0xE6, 0x73, 0x15, 0xCB, 0xF4, 0xF7, 0x89, 0x7D, 0xBF, 0xC0, 0xEA, 0xD2,
  0xF3, 0x2B, 0x20, 0xE9, 0x76, 0x54, 0x55, 0x13, 0x50, 0x42, 0x67, 0xB5, 0xCB, 0x73, 0xC0, 0xF7,
  0x75, 0x62, 0x04, 0x30, 0x21, 0xAC, 0xAF, 0xD8, 0x44, 0xF4, 0xE1, 0x04, 0x02, 0x7D, 0x61, 0x92,
  0x84, 0x99, 0x02, 0x10, 0x64, 0xCB, 0x1F, 0xE9, 0x02, 0x41, 0x00, 0xAB, 0x4B, 0x7D, 0x90, 0x7C,
  0x57, 0x08, 0x6B, 0xC0, 0x43, 0x72, 0x09, 0x8A, 0x18, 0x35, 0x36, 0x64, 0x9D, 0x84, 0x8D, 0xF1,
  0x84, 0x94, 0x48, 0xC6, 0x80, 0x9D, 0xB9, 0xA2, 0x58, 0x0A, 0x4D, 0x0A, 0xCA, 0x1E, 0xD6, 0x05,
  0x55, 0x5B, 0xFE, 0xD7, 0xAA, 0x70, 0xED, 0x76, 0xB3, 0x40, 0x2E, 0xA0, 0xB3, 0x32, 0x37, 0xB0,
  0xA0, 0xB9, 0x96, 0x2D, 0xC4, 0x70, 0xE9, 0x99, 0x10, 0x67, 0x8D
]);

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob).then(x509Crl => {
  console.log('createX509Crl success');

  try {
    // Generate a public key object.
    let keyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_3');
    console.log('createAsyKeyGenerator success');
    let priEncodingBlob: cryptoFramework.DataBlob = {
      data: priKeyData,
    };
    let pubEncodingBlob: cryptoFramework.DataBlob = {
      data: pubKeyData,
    };
    keyGenerator.convertKey(pubEncodingBlob, priEncodingBlob).then((keyPair) => {
      console.log('convert key success');
      x509Crl.verify(keyPair.pubKey).then(result => {
        console.log('verify success');
      }).catch((error: BusinessError) => {
        console.error('verify failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      });
    }).catch((error: BusinessError) => {
      console.error('convert key failed, message: ' + error.message + 'code: ' + error.code);
    });
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('get pubKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}).catch((error: BusinessError) => {
  console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getVersion<sup>(deprecated)</sup>

getVersion() : number

Obtains the version of the X.509 CRL.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.getVersion](#getversion11).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                            |
| ------ | -------------------------------- |
| number | Version of the X.509 CRL obtained.|

**Example**

```ts
import certFramework from '@ohos.security.cert';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    let version = x509Crl.getVersion();
  }
});
```

### getIssuerName<sup>(deprecated)</sup>

getIssuerName() : DataBlob

Obtains the issuer of the X.509 CRL.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.getIssuerName](#getissuername11).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                          |
| --------------------- | ------------------------------ |
| [DataBlob](#datablob) | Issuer of the X.509 CRL obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let issuerName = x509Crl.getIssuerName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getIssuerName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getLastUpdate<sup>(deprecated)</sup>

getLastUpdate() : string

Obtains the date when the X.509 CRL was last updated.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.getLastUpdate](#getlastupdate11).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| string | Last update date of the X.509 CRL.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let lastUpdate = x509Crl.getLastUpdate();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getLastUpdate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getNextUpdate<sup>(deprecated)</sup>

getNextUpdate() : string

Obtains the date when the CRL will be updated the next time.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.getNextUpdate](#getnextupdate11).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| string | Next update date obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let nextUpdate = x509Crl.getNextUpdate();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getNextUpdate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getRevokedCert<sup>(deprecated)</sup>

getRevokedCert(serialNumber : number) : X509CrlEntry

Obtains the revoked X.509 certificate based on the specified serial number of the certificate. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.getRevokedCert](#getrevokedcert11).

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name      | Type  | Mandatory| Description          |
| ------------ | ------ | ---- | -------------- |
| serialNumber | number | Yes  | Serial number of the certificate.|

**Return value**

| Type                  | Description                  |
| ---------------------- | --------------------- |
| [X509CrlEntry](#x509crlentry) | Promise used to return the revoked X.509 certificate obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    let serialNumber = 1000;
    try {
      let entry = x509Crl.getRevokedCert(serialNumber);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getRevokedCertWithCert<sup>(deprecated)</sup>

getRevokedCertWithCert(cert : X509Cert) : X509CrlEntry

Obtains the revoked X.509 certificate based on the specified certificate. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.getRevokedCertWithCert](#getrevokedcertwithcert11).

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name| Type                 | Mandatory| Description        |
| ------ | --------------------- | ---- | ------------ |
| cert   | [X509Cert](#x509cert) | Yes  | Certificate based on which the revoked certificate is obtained.|

**Return value**

| Type        | Description                 |
| ------------ | -------------------- |
| [X509CrlEntry](#x509crlentry) | Promise used to return the revoked X.509 certificate obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n'
  'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n'
  'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n'
  'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n'
  'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n'
  'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n'
  'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n'
  'Qw==\n'
  '-----END CERTIFICATE-----\n';

let certEncodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    // Create an X.509 certificate object.
    certFramework.createX509Cert(certEncodingBlob).then((x509Cert) => {
      try {
        let entry = x509Crl.getRevokedCertWithCert(x509Cert);
      } catch (error) {
        let e: BusinessError = error as BusinessError;
        console.error('getRevokedCertWithCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
      }
    }).catch((error: BusinessError) => {
      console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    })
  }
});
```

### getRevokedCerts<sup>(deprecated)</sup>

getRevokedCerts(callback : AsyncCallback<Array\<X509CrlEntry>>) : void

Obtains the revoked X.509 certificates. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.getRevokedCerts](#getrevokedcerts11).

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                                                | Mandatory| Description                            |
| -------- | ---------------------------------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback<Array\<[X509CrlEntry](#x509crlentry)>> | Yes  | Callback invoked to return a list of revoked X.509 certificates. |

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    x509Crl.getRevokedCerts((error, array) => {
      if (error != null) {
        console.error('getRevokedCerts failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('getRevokedCerts success');
      }
    });
  }
});
```

### getRevokedCerts<sup>(deprecated)</sup>

getRevokedCerts() : Promise<Array\<X509CrlEntry>>

Obtains the revoked X.509 certificates. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.getRevokedCerts](#getrevokedcerts11-1).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                                          | Description                  |
| ---------------------------------------------- | ---------------------- |
| Promise<Array\<[X509CrlEntry](#x509crlentry)>> | Promise used to return a list of revoked X.509 certificates.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob).then(x509Crl => {
  console.log('createX509Crl success');
  x509Crl.getRevokedCerts().then(array => {
    console.log('getRevokedCerts success');
  }).catch((error: BusinessError) => {
    console.error('getRevokedCerts failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
}).catch((error: BusinessError) => {
  console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getTbsInfo<sup>(deprecated)</sup>

getTbsInfo() : DataBlob

Obtains the DER-encoded CRL information, the **tbsCertList** from this CRL. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.getTBSInfo](#gettbsinfo11).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                           |
| --------------------- | ------------------------------- |
| [DataBlob](#datablob) | **tbsCertList** information obtained. |

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let tbsInfo = x509Crl.getTbsInfo();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getTbsInfo failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignature<sup>(deprecated)</sup>

getSignature() : DataBlob

Obtains the signature data of the X.509 CRL.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.getSignature](#getsignature11).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                          |
| --------------------- | ------------------------------ |
| [DataBlob](#datablob) | Signature data of the X.509 CRL obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let signature = x509Crl.getSignature();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignature failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgName<sup>(deprecated)</sup>

getSignatureAlgName() : string

Obtains the signing algorithm of the X.509 CRL.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.getSignatureAlgName](#getsignaturealgname11).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                            |
| ------ | -------------------------------- |
| string | Signing algorithm obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let sigAlgName = x509Crl.getSignatureAlgName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgOid<sup>(deprecated)</sup>

getSignatureAlgOid() : string

Obtains the OID of the X.509 CRL signing algorithm. OIDs are allocated by the International Organization for Standardization (ISO).

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.getSignatureAlgOid](#getsignaturealgoid11).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                                         |
| ------ | --------------------------------------------- |
| string | OID of the X.509 CRL signing algorithm obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let sigAlgOid = x509Crl.getSignatureAlgOid();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgOid failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgParams<sup>(deprecated)</sup>

getSignatureAlgParams() : DataBlob

Obtains the parameters of the X.509 CRL signing algorithm.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use [X509CRL.getSignatureAlgParams](#getsignaturealgparams11).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| [DataBlob](#datablob) | Algorithm parameters obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      let sigAlgParams = x509Crl.getSignatureAlgParams();
    } catch (err) {
      let e: BusinessError = error as BusinessError;
      console.error('getSignatureAlgParams failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```
## X509CRL<sup>11+</sup>

Provides APIs for managing a CRL object.

### isRevoked<sup>11+</sup>

isRevoked(cert : X509Cert) : boolean

Checks whether an X.509 certificate is revoked.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name| Type    | Mandatory| Description                |
| ------ | -------- | ---- | -------------------- |
| cert   | [X509Cert](#x509cert) | Yes  | X.509 certificate to check.|

**Return value**

| Type   | Description                                             |
| ------- | ------------------------------------------------- |
| boolean | Returns **true** if the certificate is revoked; returns **false** otherwise.|

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBLzCB1QIUO/QDVJwZLIpeJyPjyTvE43xvE5cwCgYIKoZIzj0EAwIwGjEYMBYG\n' +
  'A1UEAwwPRXhhbXBsZSBSb290IENBMB4XDTIzMDkwNDExMjAxOVoXDTI2MDUzMDEx\n' +
  'MjAxOVowGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYI\n' +
  'KoZIzj0DAQcDQgAEHjG74yMIueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTa\n' +
  'tUsU0i/sePnrKglj2H8Abbx9PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEA\n' +
  '0ce/fvA4tckNZeB865aOApKXKlBjiRlaiuq5mEEqvNACIQDPD9WyC21MXqPBuRUf\n' +
  'BetUokslUfjT6+s/X4ByaxycAA==\n' +
  '-----END CERTIFICATE-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

let certEncodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    // Create an X509Cert instance.
    certFramework.createX509Cert(certEncodingBlob, (error, x509Cert) => {
      if (error == null) {
        try {
          let revokedFlag = x509CRL.isRevoked(x509Cert);
        } catch (error) {
          let e: BusinessError = error as BusinessError;
          console.error('isRevoked failed, errCode: ' + e.code + ', errMsg: ' + e.message);
        }
      }
    });
  }
});
```

### getType<sup>11+</sup>

getType() : string

Obtains the CRL type.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| string | CRL type obtained.|

**Example**

```ts
import certFramework from '@ohos.security.cert';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    let type = x509CRL.getType();
  }
});
```

### getEncoded<sup>11+</sup>

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

Obtains the serialized X.509 CRL data. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                                         | Mandatory| Description                                      |
| -------- | --------------------------------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | Yes  | Callback invoked to return the serialized X.509 CRL data obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    x509CRL.getEncoded((error, data) => {
      if (error != null) {
        console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('getEncoded success');
      }
    });
  }
});
```

### getEncoded<sup>11+</sup>

getEncoded() : Promise\<EncodingBlob>

Obtains the serialized X.509 CRL data. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                                   | Description                            |
| --------------------------------------- | -------------------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | Promise used to return the serialized X.509 CRL data obtained.|
**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob).then(x509CRL => {
  console.log('createX509CRL success');
  x509CRL.getEncoded().then(result => {
    console.log('getEncoded success');
  }).catch((error: BusinessError) => {
    console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
}).catch((error: BusinessError) => {
  console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### verify<sup>11+</sup>

verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void

Verifies the signature of the X.509 CRL. This API uses an asynchronous callback to return the result. The RSA algorithm is supported.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| key      | [cryptoFramework.PubKey](js-apis-cryptoFramework.md#pubkey) | Yes  | Public key used for signature verification.                                      |
| callback | AsyncCallback\<void>                                        | Yes  | Callback invoked to return the result. If **error** is **null**, the signature verification is successful. If **error** is not **null**, the signature verification fails.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let pubKeyData = new Uint8Array([
  0x30, 0x81, 0x9F, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01,
  0x05, 0x00, 0x03, 0x81, 0x8D, 0x00, 0x30, 0x81, 0x89, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D,
  0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED, 0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE,
]);

let priKeyData = new Uint8Array([
  0x30, 0x82, 0x02, 0x77, 0x02, 0x01, 0x00, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
  0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x04, 0x82, 0x02, 0x61, 0x30, 0x82, 0x02, 0x5D, 0x02, 0x01,
  0x00, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D, 0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED,
]);

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    try {
      // Generate the public key by AsyKeyGenerator.
      let keyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_3');
      console.log('createAsyKeyGenerator success');
      let priEncodingBlob: cryptoFramework.DataBlob = {
        data: priKeyData,
      };
      let pubEncodingBlob: cryptoFramework.DataBlob = {
        data: pubKeyData,
      };
      keyGenerator.convertKey(pubEncodingBlob, priEncodingBlob, (e, keyPair) => {
        if (e == null) {
          console.log('convert key success');
          x509CRL.verify(keyPair.pubKey, (err, data) => {
            if (err == null) {
              console.log('verify success');
            } else {
              console.error('verify failed, errCode: ' + err.code + ', errMsg: ' + err.message);
            }
          });
        } else {
          console.error('convert key failed, message: ' + e.message + 'code: ' + e.code);
        }
      })
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('get pubKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### verify<sup>11+</sup>

verify(key : cryptoFramework.PubKey) : Promise\<void>

Verifies the signature of the X.509 CRL. This API uses a promise to return the result. The RSA algorithm is supported.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name| Type                                                       | Mandatory| Description                    |
| ------ | ----------------------------------------------------------- | ---- | ------------------------ |
| key    | [cryptoFramework.PubKey](js-apis-cryptoFramework.md#pubkey) | Yes  | Public key used for signature verification.|

**Return value**

| Type          | Description       |
| -------------- | ----------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import cryptoFramework from '@ohos.security.cryptoFramework'
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

let pubKeyData = new Uint8Array([
  0x30, 0x81, 0x9F, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01,
  0x05, 0x00, 0x03, 0x81, 0x8D, 0x00, 0x30, 0x81, 0x89, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D,
  0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED, 0x3E, 0x90, 0x29, 0x51, 0xF7, 0x70, 0x15, 0xFE,
]);

let priKeyData = new Uint8Array([
  0x30, 0x82, 0x02, 0x77, 0x02, 0x01, 0x00, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
  0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x04, 0x82, 0x02, 0x61, 0x30, 0x82, 0x02, 0x5D, 0x02, 0x01,
  0x00, 0x02, 0x81, 0x81, 0x00, 0xDC, 0x4C, 0x2D, 0x57, 0x49, 0x3D, 0x42, 0x52, 0x1A, 0x09, 0xED,
]);

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob).then(x509CRL => {
  console.log('createX509Crl success');

  try {
    // Generate a public key object.
    let keyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_3');
    console.log('createAsyKeyGenerator success');
    let priEncodingBlob: cryptoFramework.DataBlob = {
      data: priKeyData,
    };
    let pubEncodingBlob: cryptoFramework.DataBlob = {
      data: pubKeyData,
    };
    keyGenerator.convertKey(pubEncodingBlob, priEncodingBlob).then((keyPair) => {
      console.log('convert key success');
      x509CRL.verify(keyPair.pubKey).then(result => {
        console.log('verify success');
      }).catch((error: BusinessError) => {
        console.error('verify failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      });
    }).catch((error: BusinessError) => {
      console.error('convert key failed, message: ' + error.message + 'code: ' + error.code);
    });
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('get pubKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
}).catch((error: BusinessError) => {
  console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getVersion<sup>11+</sup>

getVersion() : number

Obtains the version of the X.509 CRL.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                            |
| ------ | -------------------------------- |
| number | Version of the X.509 CRL obtained.|

**Example**

```ts
import certFramework from '@ohos.security.cert';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    let version = x509CRL.getVersion();
  }
});
```

### getIssuerName<sup>11+</sup>

getIssuerName() : DataBlob

Obtains the issuer of the X.509 CRL.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                          |
| --------------------- | ------------------------------ |
| [DataBlob](#datablob) | Issuer of the X.509 CRL obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let issuerName = x509CRL.getIssuerName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getIssuerName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getLastUpdate<sup>11+</sup>

getLastUpdate() : string

Obtains the date when the X.509 CRL was last updated.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| string | Last update date of the X.509 CRL.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let lastUpdate  = x509CRL.getLastUpdate();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getLastUpdate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getNextUpdate<sup>11+</sup>

getNextUpdate() : string

Obtains the date when the CRL will be updated the next time.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| string | Next update date obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let nextUpdate = x509CRL.getNextUpdate();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getNextUpdate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getRevokedCert<sup>11+</sup>

getRevokedCert(serialNumber : bigint) : X509CRLEntry

Obtains the revoked X.509 certificate based on the specified serial number of the certificate.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name      | Type  | Mandatory| Description          |
| ------------ | ------ | ---- | -------------- |
| serialNumber | bigint | Yes  | Serial number of the certificate.|

**Return value**

| Type                           | Description                  |
| ------------------------------- | ---------------------- |
| [X509CRLEntry](#x509crlentry11) | Revoked X.509 certificate obtained. |

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    let serialNumber = BigInt(1000);
    try {
      let entry = x509CRL.getRevokedCert(serialNumber);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getRevokedCertWithCert<sup>11+</sup>

getRevokedCertWithCert(cert : X509Cert) : X509CRLEntry

Obtains the revoked X.509 certificate based on the specified certificate.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name| Type                 | Mandatory| Description        |
| ------ | --------------------- | ---- | ------------ |
| cert   | [X509Cert](#x509cert) | Yes  | Certificate based on which the revoked certificate is obtained.|

**Return value**

| Type                           | Description                  |
| ------------------------------- | ---------------------- |
| [X509CRLEntry](#x509crlentry11) | Revoked X.509 certificate obtained. |

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Certificate binary data, which must be set based on the service.
let certData = '-----BEGIN CERTIFICATE-----\n'
'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n'
'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n'
'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n'
'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n'
'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n'
'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n'
'Qw==\n'
'-----END CERTIFICATE-----\n';

let certEncodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    // Create an X.509 certificate object.
    certFramework.createX509Cert(certEncodingBlob).then((x509Cert) => {
      try {
        let entry = x509CRL.getRevokedCertWithCert(x509Cert);
      } catch (error) {
        let e: BusinessError = error as BusinessError;
        console.error('getRevokedCertWithCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
      }
    }).catch((error: BusinessError) => {
      console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    })
  }
});
```

### getRevokedCerts<sup>11+</sup>

getRevokedCerts(callback : AsyncCallback<Array\<X509CRLEntry>>) : void

Obtains the revoked X.509 certificates. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                                                  | Mandatory| Description                            |
| -------- | ------------------------------------------------------ | ---- | -------------------------------- |
| callback | AsyncCallback<Array\<[X509CRLEntry](#x509crlentry11)>> | Yes  | Callback invoked to return a list of revoked X.509 certificates. |

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    x509CRL.getRevokedCerts((error, array) => {
      if (error != null) {
        console.error('getRevokedCerts failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('getRevokedCerts success');
      }
    });
  }
});
```

### getRevokedCerts<sup>11+</sup>

getRevokedCerts() : Promise<Array\<X509CRLEntry>>

Obtains the revoked X.509 certificates. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                                            | Description                  |
| ------------------------------------------------ | ---------------------- |
| Promise<Array\<[X509CRLEntry](#x509crlentry11)>> | Promise used to return a list of revoked X.509 certificates.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob).then(x509CRL => {
  console.log('createX509CRL success');
  x509CRL.getRevokedCerts().then(array => {
    console.log('getRevokedCerts success');
  }).catch((error: BusinessError) => {
    console.error('getRevokedCerts failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
}).catch((error: BusinessError) => {
  console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
});
```

### getSignature<sup>11+</sup>

getSignature() : DataBlob

Obtains the signature data of the X.509 CRL.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                          |
| --------------------- | ------------------------------ |
| [DataBlob](#datablob) | Signature data of the X.509 CRL obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let signature = x509CRL.getSignature();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignature failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgName<sup>11+</sup>

getSignatureAlgName() : string

Obtains the signing algorithm of the X.509 CRL.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                            |
| ------ | -------------------------------- |
| string | Signing algorithm obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let sigAlgName = x509CRL.getSignatureAlgName();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgName failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgOid<sup>11+</sup>

getSignatureAlgOid() : string

Obtains the OID of the X.509 CRL signing algorithm. OIDs are allocated by the International Organization for Standardization (ISO).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                                         |
| ------ | --------------------------------------------- |
| string | OID of the X.509 CRL signing algorithm obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let sigAlgOid = x509CRL.getSignatureAlgOid();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('getSignatureAlgOid failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getSignatureAlgParams<sup>11+</sup>

getSignatureAlgParams() : DataBlob

Obtains the parameters of the X.509 CRL signing algorithm.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| [DataBlob](#datablob) | Algorithm parameters obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let sigAlgParams = x509CRL.getSignatureAlgParams();
    } catch (err) {
      let e: BusinessError = error as BusinessError;
      console.error('getSignatureAlgParams failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getTBSInfo<sup>11+</sup>

getTBSInfo() : DataBlob

Obtains the DER-encoded CRL information, the **tbsCertList** from this CRL.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                             |
| --------------------- | --------------------------------- |
| [DataBlob](#datablob) | **tbsCertList** information obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let tbsInfo = x509CRL.getTBSInfo();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getTBSInfo failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### getExtensions<sup>11+</sup>

getExtensions(): DataBlob

Obtains the CRL extensions.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description               |
| --------------------- | ------------------- |
| [DataBlob](#datablob) | X.509 CRL extensions obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (error, x509CRL) => {
  if (error != null) {
    console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509CRL success');
    try {
      let extensions = x509CRL.getExtensions();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getExtensions failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### match<sup>11+</sup>

match(param: X509CRLMatchParameters): boolean

Matches a CRL.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name   | Type  | Mandatory| Description                                      |
| --------- | ------ | ---- | ------------------------------------------ |
| param | [X509CRLMatchParameters](#x509crlmatchparameters11)| Yes  | Parameters specified for matching the CRL.|

**Return value**

| Type                 | Description                                     |
| --------------------- | ----------------------------------------- |
| boolean | Returns **true** if a CRL is matched; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message      |
| -------- | -------------- |
| 19020001 | memory error.  |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n';

// Binary data of the CRL, which must be set based on the service.
let crlEncodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

const certData = "-----BEGIN CERTIFICATE-----\r\n" +
  "MIIC8TCCAdmgAwIBAgIIFB75m06RTHwwDQYJKoZIhvcNAQELBQAwWDELMAkGA1UE\r\n" +
  "BhMCQ04xEDAOBgNVBAgTB0ppYW5nc3UxEDAOBgNVBAcTB05hbmppbmcxCzAJBgNV\r\n" +
  "BAoTAnRzMQswCQYDVQQLEwJ0czELMAkGA1UEAxMCdHMwHhcNMjMxMTIzMDMzMjAw\r\n" +
  "WhcNMjQxMTIzMDMzMjAwWjBhMQswCQYDVQQGEwJDTjEQMA4GA1UECBMHSmlhbmdz\r\n" +
  "dTEQMA4GA1UEBxMHTmFuamluZzEMMAoGA1UEChMDdHMxMQwwCgYDVQQLEwN0czEx\r\n" +
  "EjAQBgNVBAMTCTEyNy4wLjAuMTAqMAUGAytlcAMhALsWnY9cMNC6jzduM69vI3Ej\r\n" +
  "pUlgHtEHS8kRfmYBupJSo4GvMIGsMAwGA1UdEwEB/wQCMAAwHQYDVR0OBBYEFNSg\r\n" +
  "poQvfxR8A1Y4St8NjOHkRpm4MAsGA1UdDwQEAwID+DAnBgNVHSUEIDAeBggrBgEF\r\n" +
  "BQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEyNy4wLjAuMTAR\r\n" +
  "BglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0\r\n" +
  "ZTANBgkqhkiG9w0BAQsFAAOCAQEAfnLmPF6BtAUCZ9pjt1ITdXc5M4LJfMw5IPcv\r\n" +
  "fUAvhdaUXtqBQcjGCWtDdhyb1n5Xp+N7oKz/Cnn0NGFTwVArtFiQ5NEP2CmrckLh\r\n" +
  "Da4VnsDFU+zx2Bbfwo5Ms7iArxyx0fArbMZzN9D1lZcVjiIxp1+3k1/0sdCemcY/\r\n" +
  "y7mw5NwkcczLWLBZl1/Ho8b4dlo1wTA7TZk9uu8UwYBwXDrQe6S9rMcvMcRKiJ9e\r\n" +
  "V4SYZIO7ihr8+n4LQDQP+spvX4cf925a3kyZrftfvGCJ2ZNwvsPhyumYhaBqAgSy\r\n" +
  "Up2BImymAqPi157q9EeYcQz170TtDZHGmjYzdQxhOAHRb6/IdQ==\r\n" +
  "-----END CERTIFICATE-----\r\n";
const certEncodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certData),
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM,
};

async function crlMatch() {
  let x509Cert: certFramework.X509Cert = {} as certFramework.X509Cert;
  try {
    x509Cert = await certFramework.createX509Cert(certEncodingBlob);
    console.log('createX509Cert success');
  } catch (err) {
    console.error('createX509Cert failed');
  }

  certFramework.createX509CRL(crlEncodingBlob, (error, x509CRL) => {
    if (error != null) {
      console.error('createX509CRL failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    } else {
      console.log('createX509CRL success');
      try {
        const param: certFramework.X509CRLMatchParameters = {
          issuer: [new Uint8Array([0x30, 0x58, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x43, 0x4E, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x07, 0x4A, 0x69, 0x61, 0x6E, 0x67, 0x73, 0x75, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13, 0x07, 0x4E, 0x61, 0x6E, 0x6A, 0x69, 0x6E, 0x67, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x02, 0x74, 0x73])],
          x509Cert: x509Cert
        }
        const result = x509CRL.match(param);
      } catch (error) {
        let e: BusinessError = error as BusinessError;
        console.error('x509CRL match failed, errCode: ' + e.code + ', errMsg: ' + e.message);
      }
    }
  });
}
```

## cryptoCert.createCertChainValidator

createCertChainValidator(algorithm :string) : CertChainValidator

Creates a **CertChainValidator** object.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name   | Type  | Mandatory| Description                                      |
| --------- | ------ | ---- | ------------------------------------------ |
| algorithm | string | Yes  | Certificate chain validator algorithm. Currently, only **PKIX** is supported.|

**Return value**

| Type              | Description                |
| ------------------ | -------------------- |
| CertChainValidator | **CertChainValidator** object created.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

try {
  let validator = certFramework.createCertChainValidator('PKIX');
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error('createCertChainValidator failed, errCode: ' + e.code + ', errMsg: ' + e.message);
}
```

## CertChainValidator

Provides APIs for certificate chain validator operations.


### Attributes

**System capability**: SystemCapability.Security.Cert

| Name   | Type  | Readable| Writable| Description                        |
| ------- | ------ | ---- | ---- | -------------------------- |
| algorithm  | string | Yes  | No  | Algorithm used by the X509 certificate chain validator.|


### validate

validate(certChain : CertChainData, callback : AsyncCallback\<void>) : void

Validates an X.509 certificate chain. This API uses an asynchronous callback to return the result.
The certificate chain validator does not verify the certificate validity period because the system time on the device is untrusted. To check the validity period of a certificate, use the [checkValidityWithDate()](#checkvaliditywithdate) API of the **X509Cert** class. For details, see [Certificate Specifications](../../security/cert-overview.md#certificate-specifications).

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name   | Type                           | Mandatory| Description                                                        |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| certChain | [CertChainData](#certchaindata) | Yes  | Serialized X.509 certificate chain data.                                    |
| callback  | AsyncCallback\<void>            | Yes  | Callback invoked to return the result. If **error** is **null**, the X.509 certificate chain is valid. If **error** is not **null**, the X.509 certificate chain is not valid.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.                           |
| 19030002 | the certificate signature verification failed.    |
| 19030003 | the certificate has not taken effect.             |
| 19030004 | the certificate has expired.                      |
| 19030005 | failed to obtain the certificate issuer.          |
| 19030006 | the key cannot be used for signing a certificate. |
| 19030007 | the key cannot be used for digital signature.     |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Certificate chain binary data, which must be set based on the service.
let certChainBuff = new Uint8Array([0x30, 0x82, 0x44]);

let certChainData: certFramework.CertChainData = {
  data: certChainBuff,
  // Number of certificates in the certificate chain. It must be set based on the service.
  count: 2,
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

try {
  let validator = certFramework.createCertChainValidator('PKIX');
  validator.validate(certChainData, (error, data) => {
    if (error != null) {
      console.error('validate failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    } else {
      console.log('validate success');
    }
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error('getNotBeforeTime failed, errCode: ' + e.code + ', errMsg: ' + e.message);
}
```

### validate

validate(certChain : CertChainData) : Promise\<void>

Validates the X.509 certificate chain. This API uses a promise to return the result.
The certificate chain validator does not verify the certificate validity period because the system time on the device is untrusted. To check the validity period of a certificate, use the [checkValidityWithDate()](#checkvaliditywithdate) API of the **X509Cert** class. For details, see [Certificate Specifications](../../security/cert-overview.md#certificate-specifications).

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name   | Type                           | Mandatory| Description                      |
| --------- | ------------------------------- | ---- | -------------------------- |
| certChain | [CertChainData](#certchaindata) | Yes  | Serialized X.509 certificate chain data.|

**Return value**

| Type          | Description       |
| -------------- | ----------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.                           |
| 19030002 | the certificate signature verification failed.    |
| 19030003 | the certificate has not taken effect.             |
| 19030004 | the certificate has expired.                      |
| 19030005 | failed to obtain the certificate issuer.          |
| 19030006 | the key cannot be used for signing a certificate. |
| 19030007 | the key cannot be used for digital signature.     |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Certificate chain binary data, which must be set based on the service.
let certChainBuff = new Uint8Array([0x30, 0x82, 0x44]);

let certChainData: certFramework.CertChainData = {
  data: certChainBuff,
  // Number of certificates in the certificate chain. It must be set based on the service.
  count: 2,
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

try {
  let validator = certFramework.createCertChainValidator('PKIX');
  validator.validate(certChainData).then(result => {
    console.log('validate success');
  }).catch((error: BusinessError) => {
    console.error('validate failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error('getNotBeforeTime failed, errCode: ' + e.code + ', errMsg: ' + e.message);
}
```

### algorithm

algorithm : string

Obtains the algorithm of the X.509 certificate chain validator.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| string | Algorithm of the X.509 certificate chain validator obtained.|

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

try {
  let validator = certFramework.createCertChainValidator('PKIX');
  let algorithm = validator.algorithm;
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error('createCertChainValidator failed, errCode: ' + e.code + ', errMsg: ' + e.message);
}
```


## X509CrlEntry<sup>(deprecated)</sup>

Provides APIs for operating the revoked certificates.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use[X509CrlEntry](#x509crlentry11).

### getEncoded<sup>(deprecated)</sup>

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

Obtains the serialized data of the revoked certificate. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use[X509CRLEntry.getEncoded](#getencoded11-2).

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                                         | Mandatory| Description                                |
| -------- | --------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | Yes  | Callback invoked to return the serialized data of the revoked certificate obtained. |

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (err, x509Crl) => {
  if (err != null) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = 1000;
      let crlEntry = x509Crl.getRevokedCert(serialNumber);
      crlEntry.getEncoded((error, data) => {
        if (error != null) {
          console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
        } else {
          console.log('getEncoded success');
        }
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getEncoded<sup>(deprecated)</sup>

getEncoded() : Promise\<EncodingBlob>

Obtains the serialized data of the revoked certificate. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use[X509CRLEntry.getEncoded](#getencoded11-3).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                                   | Description                      |
| --------------------------------------- | -------------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | Promise used to return the serialized data of the revoked certificate obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (err, x509Crl) => {
  if (err != null) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = 1000;
      let crlEntry = x509Crl.getRevokedCert(serialNumber);
      crlEntry.getEncoded().then(result => {
        console.log('getEncoded success');
      }).catch((error: BusinessError) => {
        console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getSerialNumber<sup>(deprecated)</sup>

getSerialNumber() : number

Obtains the serial number of this revoked certificate.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use[X509CRLEntry.getSerialNumber](#getserialnumber11).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| number | Serial number of the revoked certificate obtained.|

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (err, x509Crl) => {
  if (err != null) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = 1000;
      let crlEntry = x509Crl.getRevokedCert(serialNumber);
      serialNumber = crlEntry.getSerialNumber();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getSerialNumber failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getCertIssuer<sup>(deprecated)</sup>

getCertIssuer() : DataBlob

Obtains the issuer of this revoked certificate. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use[X509CRLEntry.getCertIssuer](#getcertissuer11).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                    |
| --------------------- | ----------------------- |
| [DataBlob](#datablob) | Promise used to return the issuer of the revoked certificate obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message      |
| -------- | -------------- |
| 19020001 | memory error.  |
| 19020002 | runtime error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (err, x509Crl) => {
  if (err != null) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = 1000;
      let crlEntry = x509Crl.getRevokedCert(serialNumber);
      let issuer = crlEntry.getCertIssuer();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getCertIssuer failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getRevocationDate<sup>(deprecated)</sup>

getRevocationDate() : string

Obtains the date when the certificate was revoked. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 11. You are advised to use[X509CRLEntry.getRevocationDate](#getrevocationdate11).

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description               |
| ------ | ------------------ |
| string | Promise used to return the certificate revocation date obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509Crl(encodingBlob, (err, x509Crl) => {
  if (err != null) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = 1000;
      let crlEntry = x509Crl.getRevokedCert(serialNumber);
      let date = crlEntry.getRevocationDate();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getRevocationDate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

## X509CRLEntry<sup>11+</sup>

Provides APIs for operating the revoked certificates.

### getEncoded<sup>11+</sup>

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

Obtains the serialized data of the revoked certificate. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                                         | Mandatory| Description                                |
| -------- | --------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | Yes  | Callback invoked to return the serialized data of the revoked certificate obtained. |

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err != null) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      crlEntry.getEncoded((error, data) => {
        if (error != null) {
          console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
        } else {
          console.log('getEncoded success');
        }
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getEncoded<sup>11+</sup>

getEncoded() : Promise\<EncodingBlob>

Obtains the serialized data of the revoked certificate. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                                   | Description                      |
| --------------------------------------- | -------------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | Promise used to return the serialized data of the revoked certificate obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err != null) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      crlEntry.getEncoded().then(result => {
        console.log('getEncoded success');
      }).catch((error: BusinessError) => {
        console.error('getEncoded failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getSerialNumber<sup>11+</sup>

getSerialNumber() : bigint

Obtains the serial number of this revoked certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| bigint | Serial number of the revoked certificate obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err != null) {
    console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 crl success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      serialNumber = crlEntry.getSerialNumber();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getSerialNumber failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getCertIssuer<sup>11+</sup>

getCertIssuer() : DataBlob

Obtains the issuer of this revoked certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                      |
| --------------------- | -------------------------- |
| [DataBlob](#datablob) | Issuer of the revoked certificate obtained. |

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err != null) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      let issuer = crlEntry.getCertIssuer();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getCertIssuer failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getRevocationDate<sup>11+</sup>

getRevocationDate() : string

Obtains the date when the certificate was revoked.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| string | Certificate revocation date obtained. |

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err != null) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      let date = crlEntry.getRevocationDate();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getRevocationDate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### getExtensions<sup>11+</sup>

getExtensions(): DataBlob

Obtains the CRL extensions.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                    |
| --------------------- | ------------------------ |
| [DataBlob](#datablob) | CRL extensions obtained. |

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err != null) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      let extensions = crlEntry.getExtensions();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or getExtensions failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```

### hasExtensions<sup>11+</sup>

hasExtensions(): boolean

Checks whether this CRL entry has extensions.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type   | Description                                                |
| ------- | ---------------------------------------------------- |
| boolean | Returns **true** if the CRL entry has extension; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(crlData),
  // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CRL(encodingBlob, (err, x509CRL) => {
  if (err != null) {
    console.error('createX509CRL failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('create x509 CRL success');

    try {
      let serialNumber = BigInt(1000);
      let crlEntry = x509CRL.getRevokedCert(serialNumber);
      let hasExtensions = crlEntry.hasExtensions();
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert or hasExtensions failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
})
```
## cryptoCert.createCertCRLCollection<sup>11+</sup>

createCertCRLCollection(certs: Array\<X509Cert>, crls?: Array\<X509CRL>): CertCRLCollection

Creates an object for a collection of X.509 certificates and CRLs.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                                 | Mandatory| Description                          |
| -------- | ------------------------------------- | ---- | ------------------------------ |
| certs | Array\<[X509Cert](#x509cert)>    | Yes  |  X.509 certificates. |
| crls | Array\<[X509CRL](#x509crl11)>     | No  |  X.509 CRLs. |

**Return value**

| Type              | Description                |
| ------------------ | -------------------- |
| [CertCRLCollection](#certcrlcollection11) | **CertCRLCollection** object created.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509CRL(): Promise<certFramework.X509CRL> {
  let crlData = '-----BEGIN X509 CRL-----\n' +
    'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
    'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
    'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
    'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
    '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
    'eavsH0Q3\n' +
    '-----END X509 CRL-----\n';

  // Binary data of the CRL, which must be set based on the service.
  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(crlData),
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };
  let x509CRL: certFramework.X509CRL = {} as certFramework.X509CRL;
  try {
    x509CRL = await certFramework.createX509CRL(encodingBlob);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509CRL failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CRL;
}

async function createX509Cert(): Promise<certFramework.X509Cert> {
  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
    'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
    'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
    'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
    'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
    'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
    'Qw==\n' +
    '-----END CERTIFICATE-----\n';

  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certData),
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: certFramework.X509Cert = {} as certFramework.X509Cert;
  try {
    x509Cert = await certFramework.createX509Cert(encodingBlob);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509Cert;
}

async function createCollection() {
  const x509Cert = await createX509Cert();
  const x509CRL = await createX509CRL();
  try {
    const collection: certFramework.CertCRLCollection = certFramework.createCertCRLCollection([x509Cert], [x509CRL]);
    console.log('createCertCRLCollection success');
  } catch (err) {
    console.error('createCertCRLCollection failed');
  }
}
```

## CertCRLCollection<sup>11+</sup>

Provides APIs for locating certificates or CRLs in a **CertCRLCollection** object.

### selectCerts<sup>11+</sup>

selectCerts(param: X509CertMatchParameters): Promise\<Array\<X509Cert>>

Selects certificates that match the specified parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name   | Type                           | Mandatory| Description     |
| --------- | ------------------------------- | ---- | ------------ |
| param | [X509CertMatchParameters](#x509certmatchparameters11) | Yes  | Parameters used to match the certificates. |

**Return value**

| Type                                   | Description                                   |
| --------------------------------------- | --------------------------------------- |
| Promise\<Array\<[X509Cert](#x509cert)>> | Promise used to return the matched certificates.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509Cert(): Promise<certFramework.X509Cert> {
  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
    'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
    'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
    'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
    'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
    'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
    'Qw==\n' +
    '-----END CERTIFICATE-----\n';

  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certData),
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: certFramework.X509Cert = {} as certFramework.X509Cert;
  try {
    x509Cert = await certFramework.createX509Cert(encodingBlob);
  } catch (err) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509Cert;
}

async function selectCerts() {
  const x509Cert = await createX509Cert();
  const collection = certFramework.createCertCRLCollection([x509Cert]);

  try {
    const param: certFramework.X509CertMatchParameters = {
      x509Cert,
      validDate: '20231121074700Z',
      issuer: new Uint8Array([0x30, 0x64, 0x31]), // The values must be assigned based on the service.     
      keyUsage: [false, false, false, false, false, false, true, true, true],
      serialNumber: BigInt('232100834349818463'),
      subject: new Uint8Array([0x30, 0x6c, 0x31]), // The values must be assigned based on the service.
      publicKey: {
        data: new Uint8Array([0x30, 0x82, 0x01]) // The values must be assigned based on the service.
      },
      publicKeyAlgID: '1.2.840.113549.1.1.1'
    };
    const certs = await collection.selectCerts(param);
    console.log('call selectCerts success');
  } catch (err) {
    console.error('call selectCerts failed');
  }
}
```

### selectCerts<sup>11+</sup>

selectCerts(param: X509CertMatchParameters, callback: AsyncCallback\<Array\<X509Cert>>): void

Selects certificates that match the specified parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name   | Type                           | Mandatory| Description           |
| --------- | ------------------------------- | ---- | ----------------- |
| param | [X509CertMatchParameters](#x509certmatchparameters11) | Yes  | Parameters used to match the certificates.  |
| callback  | AsyncCallback\<Array\<[X509Cert](#x509cert)>>    | Yes  | Callback invoked to return the matched certificates.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509Cert(): Promise<certFramework.X509Cert> {
  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
    'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
    'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
    'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
    'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
    'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
    'Qw==\n' +
    '-----END CERTIFICATE-----\n';

  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certData),
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: certFramework.X509Cert = {} as certFramework.X509Cert;
  try {
    x509Cert = await certFramework.createX509Cert(encodingBlob);
  } catch (err) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509Cert;
}

async function selectCerts() {
  const x509Cert = await createX509Cert();
  const collection = certFramework.createCertCRLCollection([x509Cert]);
  // The values must be assigned based on the service.
  const param: certFramework.X509CertMatchParameters = {
    x509Cert,
    validDate: '20231121074700Z',
    issuer: new Uint8Array([0x30, 0x64, 0x31]), // The values must be assigned based on the service.
    keyUsage: [false, false, false, false, false, false, true, true, true],
    serialNumber: BigInt('232100834349818463'),
    subject: new Uint8Array([0x30, 0x6c, 0x31]), // The values must be assigned based on the service.
    publicKey: {
      data: new Uint8Array([0x30, 0x82, 0x01]) // The values must be assigned based on the service.
    },
    publicKeyAlgID: '1.2.840.113549.1.1.1'
  };
  collection.selectCerts(param, (err, certs) => {
    if (err != null) {
      console.error('selectCerts failed, errCode: ' + err.code + ', errMsg: ' + err.message);
    } else {
      console.log('selectCerts success');
    }
  });
}
```

### selectCRLs<sup>11+</sup>

selectCRLs(param: X509CRLMatchParameters): Promise\<Array\<X509CRL>>

Selects CRLs that match the specified parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name   | Type                           | Mandatory| Description     |
| --------- | ------------------------------- | ---- | ------------ |
| param | [X509CRLMatchParameters](#x509crlmatchparameters11) | Yes  | Parameters used to match the CRLs.  |

**Return value**

| Type          | Description       |
| -------------- | ----------- |
| Promise\<Array\<[X509CRL](#x509crl)>> | Promise used to return the matched CRLs.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509CRL(): Promise<certFramework.X509CRL> {
  let crlData = '-----BEGIN X509 CRL-----\n' +
    'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
    'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
    'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
    'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
    '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
    'eavsH0Q3\n' +
    '-----END X509 CRL-----\n';

  // Binary data of the CRL, which must be set based on the service.
  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(crlData),
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };
  let x509CRL: certFramework.X509CRL = {} as certFramework.X509CRL;
  try {
    x509CRL = await certFramework.createX509CRL(encodingBlob);
  } catch (err) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CRL failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CRL;
}

async function createX509Cert(): Promise<certFramework.X509Cert> {
  const certData = "-----BEGIN CERTIFICATE-----\r\n" +
    "MIIC8TCCAdmgAwIBAgIIFB75m06RTHwwDQYJKoZIhvcNAQELBQAwWDELMAkGA1UE\r\n" +
    "BhMCQ04xEDAOBgNVBAgTB0ppYW5nc3UxEDAOBgNVBAcTB05hbmppbmcxCzAJBgNV\r\n" +
    "BAoTAnRzMQswCQYDVQQLEwJ0czELMAkGA1UEAxMCdHMwHhcNMjMxMTIzMDMzMjAw\r\n" +
    "WhcNMjQxMTIzMDMzMjAwWjBhMQswCQYDVQQGEwJDTjEQMA4GA1UECBMHSmlhbmdz\r\n" +
    "dTEQMA4GA1UEBxMHTmFuamluZzEMMAoGA1UEChMDdHMxMQwwCgYDVQQLEwN0czEx\r\n" +
    "EjAQBgNVBAMTCTEyNy4wLjAuMTAqMAUGAytlcAMhALsWnY9cMNC6jzduM69vI3Ej\r\n" +
    "pUlgHtEHS8kRfmYBupJSo4GvMIGsMAwGA1UdEwEB/wQCMAAwHQYDVR0OBBYEFNSg\r\n" +
    "poQvfxR8A1Y4St8NjOHkRpm4MAsGA1UdDwQEAwID+DAnBgNVHSUEIDAeBggrBgEF\r\n" +
    "BQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEyNy4wLjAuMTAR\r\n" +
    "BglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0\r\n" +
    "ZTANBgkqhkiG9w0BAQsFAAOCAQEAfnLmPF6BtAUCZ9pjt1ITdXc5M4LJfMw5IPcv\r\n" +
    "fUAvhdaUXtqBQcjGCWtDdhyb1n5Xp+N7oKz/Cnn0NGFTwVArtFiQ5NEP2CmrckLh\r\n" +
    "Da4VnsDFU+zx2Bbfwo5Ms7iArxyx0fArbMZzN9D1lZcVjiIxp1+3k1/0sdCemcY/\r\n" +
    "y7mw5NwkcczLWLBZl1/Ho8b4dlo1wTA7TZk9uu8UwYBwXDrQe6S9rMcvMcRKiJ9e\r\n" +
    "V4SYZIO7ihr8+n4LQDQP+spvX4cf925a3kyZrftfvGCJ2ZNwvsPhyumYhaBqAgSy\r\n" +
    "Up2BImymAqPi157q9EeYcQz170TtDZHGmjYzdQxhOAHRb6/IdQ==\r\n" +
    "-----END CERTIFICATE-----\r\n";
  const certEncodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certData),
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM,
  };

  let x509Cert: certFramework.X509Cert = {} as certFramework.X509Cert;
  try {
    x509Cert = await certFramework.createX509Cert(certEncodingBlob);
    console.log('createX509Cert success');
  } catch (err) {
    console.error('createX509Cert failed');
  }
  return x509Cert;
}

async function selectCRLs() {
  const x509CRL = await createX509CRL();
  const x509Cert = await createX509Cert();
  const collection = certFramework.createCertCRLCollection([], [x509CRL]);

  const param: certFramework.X509CRLMatchParameters = {
    issuer: [new Uint8Array([0x30, 0x58, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x43, 0x4E, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x07, 0x4A, 0x69, 0x61, 0x6E, 0x67, 0x73, 0x75, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13, 0x07, 0x4E, 0x61, 0x6E, 0x6A, 0x69, 0x6E, 0x67, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x02, 0x74, 0x73])],
    x509Cert: x509Cert
  }
  try {
    const crls = await collection.selectCRLs(param);
    console.log('selectCRLs success');
  } catch (err) {
    console.error('selectCRLs failed');
  }
}
```

### selectCRLs<sup>11+</sup>

selectCRLs(param: X509CRLMatchParameters, callback: AsyncCallback\<Array\<X509CRL>>): void

Selects CRLs that match the specified parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name   | Type                           | Mandatory| Description           |
| --------- | ------------------------------- | ---- | ----------------- |
| param | [X509CRLMatchParameters](#x509crlmatchparameters11) | Yes  | Parameters used to match the CRLs.|
| callback  | AsyncCallback\<Array\<[X509CRL](#x509crl)>>    | Yes  | Callback invoked to return the matched CRLs.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509CRL(): Promise<certFramework.X509CRL> {
  let crlData = '-----BEGIN X509 CRL-----\n' +
    'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
    'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
    'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
    'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
    '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
    'eavsH0Q3\n' +
    '-----END X509 CRL-----\n';

  // Binary data of the CRL, which must be set based on the service.
  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(crlData),
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };
  let x509CRL: certFramework.X509CRL = {} as certFramework.X509CRL;
  try {
    x509CRL = await certFramework.createX509CRL(encodingBlob);
  } catch (err) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CRL failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CRL;
}

async function createX509Cert(): Promise<certFramework.X509Cert> {
  const certData = "-----BEGIN CERTIFICATE-----\r\n" +
    "MIIC8TCCAdmgAwIBAgIIFB75m06RTHwwDQYJKoZIhvcNAQELBQAwWDELMAkGA1UE\r\n" +
    "BhMCQ04xEDAOBgNVBAgTB0ppYW5nc3UxEDAOBgNVBAcTB05hbmppbmcxCzAJBgNV\r\n" +
    "BAoTAnRzMQswCQYDVQQLEwJ0czELMAkGA1UEAxMCdHMwHhcNMjMxMTIzMDMzMjAw\r\n" +
    "WhcNMjQxMTIzMDMzMjAwWjBhMQswCQYDVQQGEwJDTjEQMA4GA1UECBMHSmlhbmdz\r\n" +
    "dTEQMA4GA1UEBxMHTmFuamluZzEMMAoGA1UEChMDdHMxMQwwCgYDVQQLEwN0czEx\r\n" +
    "EjAQBgNVBAMTCTEyNy4wLjAuMTAqMAUGAytlcAMhALsWnY9cMNC6jzduM69vI3Ej\r\n" +
    "pUlgHtEHS8kRfmYBupJSo4GvMIGsMAwGA1UdEwEB/wQCMAAwHQYDVR0OBBYEFNSg\r\n" +
    "poQvfxR8A1Y4St8NjOHkRpm4MAsGA1UdDwQEAwID+DAnBgNVHSUEIDAeBggrBgEF\r\n" +
    "BQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEyNy4wLjAuMTAR\r\n" +
    "BglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0\r\n" +
    "ZTANBgkqhkiG9w0BAQsFAAOCAQEAfnLmPF6BtAUCZ9pjt1ITdXc5M4LJfMw5IPcv\r\n" +
    "fUAvhdaUXtqBQcjGCWtDdhyb1n5Xp+N7oKz/Cnn0NGFTwVArtFiQ5NEP2CmrckLh\r\n" +
    "Da4VnsDFU+zx2Bbfwo5Ms7iArxyx0fArbMZzN9D1lZcVjiIxp1+3k1/0sdCemcY/\r\n" +
    "y7mw5NwkcczLWLBZl1/Ho8b4dlo1wTA7TZk9uu8UwYBwXDrQe6S9rMcvMcRKiJ9e\r\n" +
    "V4SYZIO7ihr8+n4LQDQP+spvX4cf925a3kyZrftfvGCJ2ZNwvsPhyumYhaBqAgSy\r\n" +
    "Up2BImymAqPi157q9EeYcQz170TtDZHGmjYzdQxhOAHRb6/IdQ==\r\n" +
    "-----END CERTIFICATE-----\r\n";
  const certEncodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certData),
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM,
  };

  let x509Cert: certFramework.X509Cert = {} as certFramework.X509Cert;
  try {
    x509Cert = await certFramework.createX509Cert(certEncodingBlob);
    console.log('createX509Cert success');
  } catch (err) {
    console.error('createX509Cert failed');
  }
  return x509Cert;
}

async function selectCRLs() {
  const x509CRL = await createX509CRL();
  const x509Cert = await createX509Cert();
  const collection = certFramework.createCertCRLCollection([], [x509CRL]);

  const param: certFramework.X509CRLMatchParameters = {
    issuer: [new Uint8Array([0x30, 0x58, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x43, 0x4E, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x07, 0x4A, 0x69, 0x61, 0x6E, 0x67, 0x73, 0x75, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13, 0x07, 0x4E, 0x61, 0x6E, 0x6A, 0x69, 0x6E, 0x67, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x02, 0x74, 0x73, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x02, 0x74, 0x73])],
    x509Cert: x509Cert
  }
  collection.selectCRLs(param, (err, crls) => {
    if (err != null) {
      console.error('selectCRLs failed, errCode: ' + err.code + ', errMsg: ' + err.message);
    } else {
      console.log('selectCRLs success');
    }
  });
}
```

## cryptoCert.createX509CertChain<sup>11+</sup>

createX509CertChain(inStream: EncodingBlob): Promise\<X509CertChain>

Creates an X.509 certificate chain instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                         | Mandatory| Description                |
| -------- | ----------------------------- | ---- | -------------------- |
| inStream | [EncodingBlob](#encodingblob) | Yes  | X.509 certificate serialization data.|

**Return value**

| Type                           | Description            |
| ------------------------------- | ---------------- |
| Promise\<[X509CertChain](#x509certchain11)> | Promise used to return the **X509CertChain** object created.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509CertChain(): Promise<certFramework.X509CertChain> {
  let certChainData = "-----BEGIN CERTIFICATE-----\n" +
    "MIID6jCCAtKgAwIBAgIIIM2q/TmRoLcwDQYJKoZIhvcNAQELBQAwWjELMAkGA1UE\n" +
    "BhMCRU4xEDAOBgNVBAgTB0VuZ2xhbmQxDzANBgNVBAcTBkxvbmRvbjEMMAoGA1UE\n" +
    "ChMDdHMyMQwwCgYDVQQLEwN0czIxDDAKBgNVBAMTA3RzMjAeFw0yMzEyMDUwNzM5\n" +
    "MDBaFw0yNDEwMzEyMzU5MDBaMGExCzAJBgNVBAYTAkNOMRAwDgYDVQQIEwdKaWFu\n" +
    "Z3N1MRAwDgYDVQQHEwdOYW5qaW5nMQwwCgYDVQQKEwN0czMxDDAKBgNVBAsTA3Rz\n" +
    "MzESMBAGA1UEAxMJMTI3LjAuMC4xMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\n" +
    "CgKCAQEAtt+2QxUevbolYLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLR\n" +
    "p26LFV/F8ebwPyo8YEBKSwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmc\n" +
    "rVvLBNMeVnxY86xHpo0MTNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0j\n" +
    "zT9GjeUP6JLdLFUZJKUPSTK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/U\n" +
    "T+p5ThAMH593zszlz330nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI3\n" +
    "8MFQFJKvRHfgTAvVsvAvpBUM2DuBKwIDAQABo4GsMIGpMAkGA1UdEwQCMAAwHQYD\n" +
    "VR0OBBYEFDfsHTMZwoA6eaDFlBUyDpka+sYtMAsGA1UdDwQEAwID+DAnBgNVHSUE\n" +
    "IDAeBggrBgEFBQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEy\n" +
    "Ny4wLjAuMTARBglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBj\n" +
    "ZXJ0aWZpY2F0ZTANBgkqhkiG9w0BAQsFAAOCAQEAp5vTvXrt8ZpgRJVtzv9ss0lJ\n" +
    "izp1fJf+ft5cDXrs7TSD5oHrSW2vk/ZieIMhexU4LFwhs4OE7jK6pgI48Dseqxx7\n" +
    "B/KktxhVMJUmVXd9Ayjp6f+BtZlIk0cArPuoXToXjsV8caTGBXHRdzxpAk/w9syc\n" +
    "GYrbH9TrdNMuTizOb+k268oKXUageZNxHmd7YvOXkcNgrd29jzwXKDYYiUa1DISz\n" +
    "DnYaJOgPt0B/5izhoWNK7GhJDy9KEuLURcTSWFysbbnljwO9INPT9MmlS83PdAgN\n" +
    "iS8VXF4pce1W9U5jH7d7k0JDVSXybebe1iPFphsZpYM/NE+jap+mPy1nTCbf9g==\n" +
    "-----END CERTIFICATE-----\n" +
    "-----BEGIN CERTIFICATE-----\n" +
    "MIIC0zCCAoWgAwIBAgIIXpLoPpQVWnkwBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
    "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
    "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDczNzAwWhcNMjQw\n" +
    "OTAxMjM1OTAwWjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
    "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czIxDDAKBgNVBAsTA3RzMjEMMAoGA1UE\n" +
    "AxMDdHMyMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAtt+2QxUevbol\n" +
    "YLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLRp26LFV/F8ebwPyo8YEBK\n" +
    "SwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmcrVvLBNMeVnxY86xHpo0M\n" +
    "TNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0jzT9GjeUP6JLdLFUZJKUP\n" +
    "STK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/UT+p5ThAMH593zszlz330\n" +
    "nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI38MFQFJKvRHfgTAvVsvAv\n" +
    "pBUM2DuBKwIDAQABo28wbTAMBgNVHRMEBTADAQH/MB0GA1UdDgQWBBQ37B0zGcKA\n" +
    "OnmgxZQVMg6ZGvrGLTALBgNVHQ8EBAMCAQYwEQYJYIZIAYb4QgEBBAQDAgAHMB4G\n" +
    "CWCGSAGG+EIBDQQRFg94Y2EgY2VydGlmaWNhdGUwBQYDK2VwA0EAuasLBe55YgvF\n" +
    "b4wmHeohylc9r8cFGS1LNQ5UcSn3sGqMYf6ehnef16NLuCW6upHCs8Sui4iAMvsP\n" +
    "uKPWR9dKBA==\n" +
    "-----END CERTIFICATE-----\n" +
    "-----BEGIN CERTIFICATE-----\n"  +
    "MIIB3zCCAZGgAwIBAgIIWQvOEDl+ya4wBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
    "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
    "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDAwMDAwWhcNMjQx\n" +
    "MjA0MjM1OTU5WjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
    "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czExDDAKBgNVBAsTA3RzMTEMMAoGA1UE\n" +
    "AxMDdHMxMCowBQYDK2VwAyEAuxadj1ww0LqPN24zr28jcSOlSWAe0QdLyRF+ZgG6\n" +
    "klKjdTBzMBIGA1UdEwEB/wQIMAYBAf8CARQwHQYDVR0OBBYEFNSgpoQvfxR8A1Y4\n" +
    "St8NjOHkRpm4MAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEEBAMCAAcwHgYJYIZI\n" +
    "AYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTAFBgMrZXADQQAblBgoa72X/K13WOvc\n" +
    "KW0fqBgFKvLy85hWD6Ufi61k4ProQiZzMK+0+y9jReKelPx/zRdCCgSbQroAR2mV\n" +
    "xjoE\n" +
    "-----END CERTIFICATE-----\n";

  // Certificate chain binary data, which must be set based on the service.
  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certChainData),
    // Set the encoding format, which can be FORMAT_PEM, FORMAT_DER, or FORMAT_PKCS7.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };
  let x509CertChain: certFramework.X509CertChain = {} as certFramework.X509CertChain;
  try {
    x509CertChain = await certFramework.createX509CertChain(encodingBlob);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CertChain failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CertChain;
}

createX509CertChain();
```

## cryptoCert.createX509CertChain<sup>11+</sup>

createX509CertChain(inStream: EncodingBlob, callback: AsyncCallback\<X509CertChain>): void

Creates an X.509 certificate chain instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob)         | Yes  | X.509 certificate serialization data.       |
| callback | AsyncCallback\<[X509CertChain](#x509certchain11)> | Yes  | Callback invoked to return the **X509CertChain** object created.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let certChainData = "-----BEGIN CERTIFICATE-----\n" +
  "MIID6jCCAtKgAwIBAgIIIM2q/TmRoLcwDQYJKoZIhvcNAQELBQAwWjELMAkGA1UE\n" +
  "BhMCRU4xEDAOBgNVBAgTB0VuZ2xhbmQxDzANBgNVBAcTBkxvbmRvbjEMMAoGA1UE\n" +
  "ChMDdHMyMQwwCgYDVQQLEwN0czIxDDAKBgNVBAMTA3RzMjAeFw0yMzEyMDUwNzM5\n" +
  "MDBaFw0yNDEwMzEyMzU5MDBaMGExCzAJBgNVBAYTAkNOMRAwDgYDVQQIEwdKaWFu\n" +
  "Z3N1MRAwDgYDVQQHEwdOYW5qaW5nMQwwCgYDVQQKEwN0czMxDDAKBgNVBAsTA3Rz\n" +
  "MzESMBAGA1UEAxMJMTI3LjAuMC4xMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\n" +
  "CgKCAQEAtt+2QxUevbolYLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLR\n" +
  "p26LFV/F8ebwPyo8YEBKSwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmc\n" +
  "rVvLBNMeVnxY86xHpo0MTNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0j\n" +
  "zT9GjeUP6JLdLFUZJKUPSTK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/U\n" +
  "T+p5ThAMH593zszlz330nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI3\n" +
  "8MFQFJKvRHfgTAvVsvAvpBUM2DuBKwIDAQABo4GsMIGpMAkGA1UdEwQCMAAwHQYD\n" +
  "VR0OBBYEFDfsHTMZwoA6eaDFlBUyDpka+sYtMAsGA1UdDwQEAwID+DAnBgNVHSUE\n" +
  "IDAeBggrBgEFBQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEy\n" +
  "Ny4wLjAuMTARBglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBj\n" +
  "ZXJ0aWZpY2F0ZTANBgkqhkiG9w0BAQsFAAOCAQEAp5vTvXrt8ZpgRJVtzv9ss0lJ\n" +
  "izp1fJf+ft5cDXrs7TSD5oHrSW2vk/ZieIMhexU4LFwhs4OE7jK6pgI48Dseqxx7\n" +
  "B/KktxhVMJUmVXd9Ayjp6f+BtZlIk0cArPuoXToXjsV8caTGBXHRdzxpAk/w9syc\n" +
  "GYrbH9TrdNMuTizOb+k268oKXUageZNxHmd7YvOXkcNgrd29jzwXKDYYiUa1DISz\n" +
  "DnYaJOgPt0B/5izhoWNK7GhJDy9KEuLURcTSWFysbbnljwO9INPT9MmlS83PdAgN\n" +
  "iS8VXF4pce1W9U5jH7d7k0JDVSXybebe1iPFphsZpYM/NE+jap+mPy1nTCbf9g==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n" +
  "MIIC0zCCAoWgAwIBAgIIXpLoPpQVWnkwBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDczNzAwWhcNMjQw\n" +
  "OTAxMjM1OTAwWjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czIxDDAKBgNVBAsTA3RzMjEMMAoGA1UE\n" +
  "AxMDdHMyMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAtt+2QxUevbol\n" +
  "YLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLRp26LFV/F8ebwPyo8YEBK\n" +
  "SwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmcrVvLBNMeVnxY86xHpo0M\n" +
  "TNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0jzT9GjeUP6JLdLFUZJKUP\n" +
  "STK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/UT+p5ThAMH593zszlz330\n" +
  "nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI38MFQFJKvRHfgTAvVsvAv\n" +
  "pBUM2DuBKwIDAQABo28wbTAMBgNVHRMEBTADAQH/MB0GA1UdDgQWBBQ37B0zGcKA\n" +
  "OnmgxZQVMg6ZGvrGLTALBgNVHQ8EBAMCAQYwEQYJYIZIAYb4QgEBBAQDAgAHMB4G\n" +
  "CWCGSAGG+EIBDQQRFg94Y2EgY2VydGlmaWNhdGUwBQYDK2VwA0EAuasLBe55YgvF\n" +
  "b4wmHeohylc9r8cFGS1LNQ5UcSn3sGqMYf6ehnef16NLuCW6upHCs8Sui4iAMvsP\n" +
  "uKPWR9dKBA==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n"  +
  "MIIB3zCCAZGgAwIBAgIIWQvOEDl+ya4wBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDAwMDAwWhcNMjQx\n" +
  "MjA0MjM1OTU5WjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czExDDAKBgNVBAsTA3RzMTEMMAoGA1UE\n" +
  "AxMDdHMxMCowBQYDK2VwAyEAuxadj1ww0LqPN24zr28jcSOlSWAe0QdLyRF+ZgG6\n" +
  "klKjdTBzMBIGA1UdEwEB/wQIMAYBAf8CARQwHQYDVR0OBBYEFNSgpoQvfxR8A1Y4\n" +
  "St8NjOHkRpm4MAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEEBAMCAAcwHgYJYIZI\n" +
  "AYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTAFBgMrZXADQQAblBgoa72X/K13WOvc\n" +
  "KW0fqBgFKvLy85hWD6Ufi61k4ProQiZzMK+0+y9jReKelPx/zRdCCgSbQroAR2mV\n" +
  "xjoE\n" +
  "-----END CERTIFICATE-----\n";

// Certificate chain binary data, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certChainData),
  // Set the encoding format, which can be FORMAT_PEM, FORMAT_DER, or FORMAT_PKCS7.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CertChain(encodingBlob, (err, certChain) => {
  if (err != null) {
    console.error('createX509CertChain failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('createX509CertChain success');
  }
});
```

## cryptoCert.createX509CertChain<sup>11+</sup>

createX509CertChain(certs: Array\<X509Cert>): X509CertChain

Creates an X.509 certificate chain object based on the specified certificates. This API returns the result synchronously.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                 | Mandatory| Description                      |
| -------- | -------------------- | ---- | -------------------------- |
| certs    | Array\<[X509Cert](#x509cert)> | Yes  | Array of X.509 certificates.|

**Return value**

| Type                             | Description                |
| --------------------------------- | -------------------- |
| [X509CertChain](#x509certchain11) | **X509CertChain** object created.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509Cert(): Promise<certFramework.X509Cert> {
  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIIBHTCBwwICA+gwCgYIKoZIzj0EAwIwGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290\n' +
    'IENBMB4XDTIzMDkwNTAyNDgyMloXDTI2MDUzMTAyNDgyMlowGjEYMBYGA1UEAwwP\n' +
    'RXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEHjG74yMI\n' +
    'ueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTatUsU0i/sePnrKglj2H8Abbx9\n' +
    'PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEApVZno/Z7WyDc/muRN1y57uaY\n' +
    'Mjrgnvp/AMdE8qmFiDwCIQCrIYdHVO1awaPgcdALZY+uLQi6mEs/oMJLUcmaag3E\n' +
    'Qw==\n' +
    '-----END CERTIFICATE-----\n';

  // Certificate binary data, which must be set based on the service.
  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certData),
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: certFramework.X509Cert = {} as certFramework.X509Cert;
  try {
    x509Cert = await certFramework.createX509Cert(encodingBlob);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509Cert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509Cert;
}

async function createX509CertChain(): Promise<certFramework.X509CertChain> {
  const x509Cert = await createX509Cert();
  let x509CertChain: certFramework.X509CertChain = {} as certFramework.X509CertChain;
  try {
    x509CertChain = certFramework.createX509CertChain([x509Cert]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CertChain failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CertChain;
}

createX509CertChain();
```

## X509CertChain<sup>11+</sup>

Provides APIs for managing the X.509 certificate chain.

### getCertList<sup>11+</sup>

getCertList(): Array\<X509Cert>

Obtains the X.509 certificate list.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type          | Description       |
| -------------- | ----------- |
| Array\<[X509Cert](#x509cert)> | X.509 certificate list obtained.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let certChainData = "-----BEGIN CERTIFICATE-----\n" +
  "MIID6jCCAtKgAwIBAgIIIM2q/TmRoLcwDQYJKoZIhvcNAQELBQAwWjELMAkGA1UE\n" +
  "BhMCRU4xEDAOBgNVBAgTB0VuZ2xhbmQxDzANBgNVBAcTBkxvbmRvbjEMMAoGA1UE\n" +
  "ChMDdHMyMQwwCgYDVQQLEwN0czIxDDAKBgNVBAMTA3RzMjAeFw0yMzEyMDUwNzM5\n" +
  "MDBaFw0yNDEwMzEyMzU5MDBaMGExCzAJBgNVBAYTAkNOMRAwDgYDVQQIEwdKaWFu\n" +
  "Z3N1MRAwDgYDVQQHEwdOYW5qaW5nMQwwCgYDVQQKEwN0czMxDDAKBgNVBAsTA3Rz\n" +
  "MzESMBAGA1UEAxMJMTI3LjAuMC4xMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\n" +
  "CgKCAQEAtt+2QxUevbolYLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLR\n" +
  "p26LFV/F8ebwPyo8YEBKSwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmc\n" +
  "rVvLBNMeVnxY86xHpo0MTNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0j\n" +
  "zT9GjeUP6JLdLFUZJKUPSTK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/U\n" +
  "T+p5ThAMH593zszlz330nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI3\n" +
  "8MFQFJKvRHfgTAvVsvAvpBUM2DuBKwIDAQABo4GsMIGpMAkGA1UdEwQCMAAwHQYD\n" +
  "VR0OBBYEFDfsHTMZwoA6eaDFlBUyDpka+sYtMAsGA1UdDwQEAwID+DAnBgNVHSUE\n" +
  "IDAeBggrBgEFBQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEy\n" +
  "Ny4wLjAuMTARBglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBj\n" +
  "ZXJ0aWZpY2F0ZTANBgkqhkiG9w0BAQsFAAOCAQEAp5vTvXrt8ZpgRJVtzv9ss0lJ\n" +
  "izp1fJf+ft5cDXrs7TSD5oHrSW2vk/ZieIMhexU4LFwhs4OE7jK6pgI48Dseqxx7\n" +
  "B/KktxhVMJUmVXd9Ayjp6f+BtZlIk0cArPuoXToXjsV8caTGBXHRdzxpAk/w9syc\n" +
  "GYrbH9TrdNMuTizOb+k268oKXUageZNxHmd7YvOXkcNgrd29jzwXKDYYiUa1DISz\n" +
  "DnYaJOgPt0B/5izhoWNK7GhJDy9KEuLURcTSWFysbbnljwO9INPT9MmlS83PdAgN\n" +
  "iS8VXF4pce1W9U5jH7d7k0JDVSXybebe1iPFphsZpYM/NE+jap+mPy1nTCbf9g==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n" +
  "MIIC0zCCAoWgAwIBAgIIXpLoPpQVWnkwBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDczNzAwWhcNMjQw\n" +
  "OTAxMjM1OTAwWjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czIxDDAKBgNVBAsTA3RzMjEMMAoGA1UE\n" +
  "AxMDdHMyMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAtt+2QxUevbol\n" +
  "YLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLRp26LFV/F8ebwPyo8YEBK\n" +
  "SwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmcrVvLBNMeVnxY86xHpo0M\n" +
  "TNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0jzT9GjeUP6JLdLFUZJKUP\n" +
  "STK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/UT+p5ThAMH593zszlz330\n" +
  "nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI38MFQFJKvRHfgTAvVsvAv\n" +
  "pBUM2DuBKwIDAQABo28wbTAMBgNVHRMEBTADAQH/MB0GA1UdDgQWBBQ37B0zGcKA\n" +
  "OnmgxZQVMg6ZGvrGLTALBgNVHQ8EBAMCAQYwEQYJYIZIAYb4QgEBBAQDAgAHMB4G\n" +
  "CWCGSAGG+EIBDQQRFg94Y2EgY2VydGlmaWNhdGUwBQYDK2VwA0EAuasLBe55YgvF\n" +
  "b4wmHeohylc9r8cFGS1LNQ5UcSn3sGqMYf6ehnef16NLuCW6upHCs8Sui4iAMvsP\n" +
  "uKPWR9dKBA==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n"  +
  "MIIB3zCCAZGgAwIBAgIIWQvOEDl+ya4wBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDAwMDAwWhcNMjQx\n" +
  "MjA0MjM1OTU5WjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czExDDAKBgNVBAsTA3RzMTEMMAoGA1UE\n" +
  "AxMDdHMxMCowBQYDK2VwAyEAuxadj1ww0LqPN24zr28jcSOlSWAe0QdLyRF+ZgG6\n" +
  "klKjdTBzMBIGA1UdEwEB/wQIMAYBAf8CARQwHQYDVR0OBBYEFNSgpoQvfxR8A1Y4\n" +
  "St8NjOHkRpm4MAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEEBAMCAAcwHgYJYIZI\n" +
  "AYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTAFBgMrZXADQQAblBgoa72X/K13WOvc\n" +
  "KW0fqBgFKvLy85hWD6Ufi61k4ProQiZzMK+0+y9jReKelPx/zRdCCgSbQroAR2mV\n" +
  "xjoE\n" +
  "-----END CERTIFICATE-----\n";

// Certificate chain binary data, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certChainData),
  // Set the encoding format, which can be FORMAT_PEM, FORMAT_DER, or FORMAT_PKCS7.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

certFramework.createX509CertChain(encodingBlob, (err, certChain) => {
  if (err != null) {
    console.error('createX509CertChain failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('createX509CertChain success');
    try {
      let certList = certChain.getCertList();
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('X509CertChain getCertList failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  }
});
```

### validate<sup>11+</sup>

validate(param: CertChainValidationParameters): Promise\<CertChainValidationResult>

Validates a certificate chain. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name   | Type                           | Mandatory| Description           |
| --------- | ------------------------------- | ---- | ----------------- |
| param | [CertChainValidationParameters](#certchainvalidationparameters11) | Yes  | Parameters for validating the X.509 certificate chain.|

**Return value**

| Type                                                        | Description                             |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<[CertChainValidationResult](#certchainvalidationresult11)> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error. |
| 19030001 | crypto operation error.           |
| 19030002 | the certificate signature verification failed. |
| 19030003 | the certificate has not taken effect.           |
| 19030004 | the certificate has expired. |
| 19030005 | failed to obtain the certificate issuer.           |
| 19030006 | the key cannot be used for signing a certificate. |
| 19030007 | the key cannot be used for digital signature.      |

**Example**

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createX509CertChain(): Promise<certFramework.X509CertChain> {
  let certChainData = "-----BEGIN CERTIFICATE-----\n" +
    "MIID6jCCAtKgAwIBAgIIIM2q/TmRoLcwDQYJKoZIhvcNAQELBQAwWjELMAkGA1UE\n" +
    "BhMCRU4xEDAOBgNVBAgTB0VuZ2xhbmQxDzANBgNVBAcTBkxvbmRvbjEMMAoGA1UE\n" +
    "ChMDdHMyMQwwCgYDVQQLEwN0czIxDDAKBgNVBAMTA3RzMjAeFw0yMzEyMDUwNzM5\n" +
    "MDBaFw0yNDEwMzEyMzU5MDBaMGExCzAJBgNVBAYTAkNOMRAwDgYDVQQIEwdKaWFu\n" +
    "Z3N1MRAwDgYDVQQHEwdOYW5qaW5nMQwwCgYDVQQKEwN0czMxDDAKBgNVBAsTA3Rz\n" +
    "MzESMBAGA1UEAxMJMTI3LjAuMC4xMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\n" +
    "CgKCAQEAtt+2QxUevbolYLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLR\n" +
    "p26LFV/F8ebwPyo8YEBKSwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmc\n" +
    "rVvLBNMeVnxY86xHpo0MTNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0j\n" +
    "zT9GjeUP6JLdLFUZJKUPSTK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/U\n" +
    "T+p5ThAMH593zszlz330nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI3\n" +
    "8MFQFJKvRHfgTAvVsvAvpBUM2DuBKwIDAQABo4GsMIGpMAkGA1UdEwQCMAAwHQYD\n" +
    "VR0OBBYEFDfsHTMZwoA6eaDFlBUyDpka+sYtMAsGA1UdDwQEAwID+DAnBgNVHSUE\n" +
    "IDAeBggrBgEFBQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEy\n" +
    "Ny4wLjAuMTARBglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBj\n" +
    "ZXJ0aWZpY2F0ZTANBgkqhkiG9w0BAQsFAAOCAQEAp5vTvXrt8ZpgRJVtzv9ss0lJ\n" +
    "izp1fJf+ft5cDXrs7TSD5oHrSW2vk/ZieIMhexU4LFwhs4OE7jK6pgI48Dseqxx7\n" +
    "B/KktxhVMJUmVXd9Ayjp6f+BtZlIk0cArPuoXToXjsV8caTGBXHRdzxpAk/w9syc\n" +
    "GYrbH9TrdNMuTizOb+k268oKXUageZNxHmd7YvOXkcNgrd29jzwXKDYYiUa1DISz\n" +
    "DnYaJOgPt0B/5izhoWNK7GhJDy9KEuLURcTSWFysbbnljwO9INPT9MmlS83PdAgN\n" +
    "iS8VXF4pce1W9U5jH7d7k0JDVSXybebe1iPFphsZpYM/NE+jap+mPy1nTCbf9g==\n" +
    "-----END CERTIFICATE-----\n" +
    "-----BEGIN CERTIFICATE-----\n" +
    "MIIC0zCCAoWgAwIBAgIIXpLoPpQVWnkwBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
    "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
    "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDczNzAwWhcNMjQw\n" +
    "OTAxMjM1OTAwWjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
    "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czIxDDAKBgNVBAsTA3RzMjEMMAoGA1UE\n" +
    "AxMDdHMyMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAtt+2QxUevbol\n" +
    "YLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLRp26LFV/F8ebwPyo8YEBK\n" +
    "SwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmcrVvLBNMeVnxY86xHpo0M\n" +
    "TNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0jzT9GjeUP6JLdLFUZJKUP\n" +
    "STK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/UT+p5ThAMH593zszlz330\n" +
    "nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI38MFQFJKvRHfgTAvVsvAv\n" +
    "pBUM2DuBKwIDAQABo28wbTAMBgNVHRMEBTADAQH/MB0GA1UdDgQWBBQ37B0zGcKA\n" +
    "OnmgxZQVMg6ZGvrGLTALBgNVHQ8EBAMCAQYwEQYJYIZIAYb4QgEBBAQDAgAHMB4G\n" +
    "CWCGSAGG+EIBDQQRFg94Y2EgY2VydGlmaWNhdGUwBQYDK2VwA0EAuasLBe55YgvF\n" +
    "b4wmHeohylc9r8cFGS1LNQ5UcSn3sGqMYf6ehnef16NLuCW6upHCs8Sui4iAMvsP\n" +
    "uKPWR9dKBA==\n" +
    "-----END CERTIFICATE-----\n" +
    "-----BEGIN CERTIFICATE-----\n"  +
    "MIIB3zCCAZGgAwIBAgIIWQvOEDl+ya4wBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
    "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
    "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDAwMDAwWhcNMjQx\n" +
    "MjA0MjM1OTU5WjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
    "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czExDDAKBgNVBAsTA3RzMTEMMAoGA1UE\n" +
    "AxMDdHMxMCowBQYDK2VwAyEAuxadj1ww0LqPN24zr28jcSOlSWAe0QdLyRF+ZgG6\n" +
    "klKjdTBzMBIGA1UdEwEB/wQIMAYBAf8CARQwHQYDVR0OBBYEFNSgpoQvfxR8A1Y4\n" +
    "St8NjOHkRpm4MAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEEBAMCAAcwHgYJYIZI\n" +
    "AYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTAFBgMrZXADQQAblBgoa72X/K13WOvc\n" +
    "KW0fqBgFKvLy85hWD6Ufi61k4ProQiZzMK+0+y9jReKelPx/zRdCCgSbQroAR2mV\n" +
    "xjoE\n" +
    "-----END CERTIFICATE-----\n";

  // Certificate chain binary data, which must be set based on the service.
  let encodingBlob: certFramework.EncodingBlob = {
    data: stringToUint8Array(certChainData),
    // Set the encoding format, which can be FORMAT_PEM, FORMAT_DER, or FORMAT_PKCS7.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };
  let x509CertChain: certFramework.X509CertChain = {} as certFramework.X509CertChain;
  try {
    x509CertChain = await certFramework.createX509CertChain(encodingBlob);
  }
  catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error('createX509CertChain failed, errCode: ' + e.code + ', errMsg: ' + e.message);
  }
  return x509CertChain;
}

async function validate() {
  const certChain = await createX509CertChain();
  // Certificate chain validation data, which must be assigned based on the service.
  const param: certFramework.CertChainValidationParameters = {
    date: '20231212080000Z',
    trustAnchors: [{
        CAPubKey: new Uint8Array([0x30, 0x2a, 0x30, 0x05, 0x06, 0x03, 0x2b, 0x65, 0x70, 0x03, 0x21, 0x00, 0xbb, 0x16,0x9d, 0x8f, 0x5c, 0x30, 0xd0, 0xba, 0x8f, 0x37, 0x6e, 0x33, 0xaf, 0x6f, 0x23, 0x71, 0x23, 0xa5, 0x49, 0x60,0x1e, 0xd1, 0x07, 0x4b, 0xc9, 0x11, 0x7e, 0x66, 0x01, 0xba, 0x92, 0x52]),
        CASubject: new Uint8Array([0x30, 0x5a, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x45,0x4e, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x07, 0x45, 0x6e, 0x67, 0x6c, 0x61, 0x6e,0x64, 0x31, 0x0f, 0x30, 0x0d, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13, 0x06, 0x4c, 0x6f, 0x6e, 0x64, 0x6f, 0x6e,0x31, 0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x03, 0x74, 0x73, 0x31, 0x31, 0x0c, 0x30, 0x0a,0x06, 0x03, 0x55, 0x04, 0x0b, 0x13, 0x03, 0x74, 0x73, 0x31, 0x31, 0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04,0x03, 0x13, 0x03, 0x74, 0x73, 0x31]),
    }]
  }
  try {
    const validationRes = await certChain.validate(param);
    console.log('X509CertChain validate success');
  }
  catch (err) {
    console.error('X509CertChain validate failed');
  }
}

validate();
```

### validate<sup>11+</sup>

validate(param: CertChainValidationParameters, callback: AsyncCallback\<CertChainValidationResult>): void

Validates a certificate chain. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name   | Type                           | Mandatory| Description     |
| --------- | ------------------------------- | ---- | ------------ |
| param | [CertChainValidationParameters](#certchainvalidationparameters11) | Yes  | Parameters for validating the X.509 certificate chain.|
| callback  | AsyncCallback\<[CertChainValidationResult](#certchainvalidationresult11)> | Yes  | Callback invoked to return the certificate chain validation result.|

**Error codes**

For details about the error codes, see [Certificate Error Codes](../errorcodes/errorcode-cert.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error. |
| 19030001 | crypto operation error.           |
| 19030002 | the certificate signature verification failed. |
| 19030003 | the certificate has not taken effect.           |
| 19030004 | the certificate has expired. |
| 19030005 | failed to obtain the certificate issuer.           |
| 19030006 | the key cannot be used for signing a certificate. |
| 19030007 | the key cannot be used for digital signature.      |

**Example**

```ts
import certFramework from '@ohos.security.cert';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let certChainData = "-----BEGIN CERTIFICATE-----\n" +
  "MIID6jCCAtKgAwIBAgIIIM2q/TmRoLcwDQYJKoZIhvcNAQELBQAwWjELMAkGA1UE\n" +
  "BhMCRU4xEDAOBgNVBAgTB0VuZ2xhbmQxDzANBgNVBAcTBkxvbmRvbjEMMAoGA1UE\n" +
  "ChMDdHMyMQwwCgYDVQQLEwN0czIxDDAKBgNVBAMTA3RzMjAeFw0yMzEyMDUwNzM5\n" +
  "MDBaFw0yNDEwMzEyMzU5MDBaMGExCzAJBgNVBAYTAkNOMRAwDgYDVQQIEwdKaWFu\n" +
  "Z3N1MRAwDgYDVQQHEwdOYW5qaW5nMQwwCgYDVQQKEwN0czMxDDAKBgNVBAsTA3Rz\n" +
  "MzESMBAGA1UEAxMJMTI3LjAuMC4xMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\n" +
  "CgKCAQEAtt+2QxUevbolYLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLR\n" +
  "p26LFV/F8ebwPyo8YEBKSwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmc\n" +
  "rVvLBNMeVnxY86xHpo0MTNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0j\n" +
  "zT9GjeUP6JLdLFUZJKUPSTK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/U\n" +
  "T+p5ThAMH593zszlz330nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI3\n" +
  "8MFQFJKvRHfgTAvVsvAvpBUM2DuBKwIDAQABo4GsMIGpMAkGA1UdEwQCMAAwHQYD\n" +
  "VR0OBBYEFDfsHTMZwoA6eaDFlBUyDpka+sYtMAsGA1UdDwQEAwID+DAnBgNVHSUE\n" +
  "IDAeBggrBgEFBQcDAQYIKwYBBQUHAwIGCCsGAQUFBwMEMBQGA1UdEQQNMAuCCTEy\n" +
  "Ny4wLjAuMTARBglghkgBhvhCAQEEBAMCBkAwHgYJYIZIAYb4QgENBBEWD3hjYSBj\n" +
  "ZXJ0aWZpY2F0ZTANBgkqhkiG9w0BAQsFAAOCAQEAp5vTvXrt8ZpgRJVtzv9ss0lJ\n" +
  "izp1fJf+ft5cDXrs7TSD5oHrSW2vk/ZieIMhexU4LFwhs4OE7jK6pgI48Dseqxx7\n" +
  "B/KktxhVMJUmVXd9Ayjp6f+BtZlIk0cArPuoXToXjsV8caTGBXHRdzxpAk/w9syc\n" +
  "GYrbH9TrdNMuTizOb+k268oKXUageZNxHmd7YvOXkcNgrd29jzwXKDYYiUa1DISz\n" +
  "DnYaJOgPt0B/5izhoWNK7GhJDy9KEuLURcTSWFysbbnljwO9INPT9MmlS83PdAgN\n" +
  "iS8VXF4pce1W9U5jH7d7k0JDVSXybebe1iPFphsZpYM/NE+jap+mPy1nTCbf9g==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n" +
  "MIIC0zCCAoWgAwIBAgIIXpLoPpQVWnkwBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDczNzAwWhcNMjQw\n" +
  "OTAxMjM1OTAwWjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czIxDDAKBgNVBAsTA3RzMjEMMAoGA1UE\n" +
  "AxMDdHMyMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAtt+2QxUevbol\n" +
  "YLp51QGcUpageI4fwGLIqv4fj4aoVnHFOOBqVOVpfCLRp26LFV/F8ebwPyo8YEBK\n" +
  "SwXzMD1573rMSbaH9BalscH5lZYAbetXoio6YRvzlcmcrVvLBNMeVnxY86xHpo0M\n" +
  "TNyP7W024rZsxWO98xFQVdoiaBC+7+midlisx2Y+7u0jzT9GjeUP6JLdLFUZJKUP\n" +
  "STK3jVzw9v1eZQZKYoNfU6vFMd6ndtwW6qEnwpzmmX/UT+p5ThAMH593zszlz330\n" +
  "nTSXBjIsGkyvOz9gSB0Z0LAuJj06XUNhGL5xKJYKbdI38MFQFJKvRHfgTAvVsvAv\n" +
  "pBUM2DuBKwIDAQABo28wbTAMBgNVHRMEBTADAQH/MB0GA1UdDgQWBBQ37B0zGcKA\n" +
  "OnmgxZQVMg6ZGvrGLTALBgNVHQ8EBAMCAQYwEQYJYIZIAYb4QgEBBAQDAgAHMB4G\n" +
  "CWCGSAGG+EIBDQQRFg94Y2EgY2VydGlmaWNhdGUwBQYDK2VwA0EAuasLBe55YgvF\n" +
  "b4wmHeohylc9r8cFGS1LNQ5UcSn3sGqMYf6ehnef16NLuCW6upHCs8Sui4iAMvsP\n" +
  "uKPWR9dKBA==\n" +
  "-----END CERTIFICATE-----\n" +
  "-----BEGIN CERTIFICATE-----\n"  +
  "MIIB3zCCAZGgAwIBAgIIWQvOEDl+ya4wBQYDK2VwMFoxCzAJBgNVBAYTAkVOMRAw\n" +
  "DgYDVQQIEwdFbmdsYW5kMQ8wDQYDVQQHEwZMb25kb24xDDAKBgNVBAoTA3RzMTEM\n" +
  "MAoGA1UECxMDdHMxMQwwCgYDVQQDEwN0czEwHhcNMjMxMjA1MDAwMDAwWhcNMjQx\n" +
  "MjA0MjM1OTU5WjBaMQswCQYDVQQGEwJFTjEQMA4GA1UECBMHRW5nbGFuZDEPMA0G\n" +
  "A1UEBxMGTG9uZG9uMQwwCgYDVQQKEwN0czExDDAKBgNVBAsTA3RzMTEMMAoGA1UE\n" +
  "AxMDdHMxMCowBQYDK2VwAyEAuxadj1ww0LqPN24zr28jcSOlSWAe0QdLyRF+ZgG6\n" +
  "klKjdTBzMBIGA1UdEwEB/wQIMAYBAf8CARQwHQYDVR0OBBYEFNSgpoQvfxR8A1Y4\n" +
  "St8NjOHkRpm4MAsGA1UdDwQEAwIBBjARBglghkgBhvhCAQEEBAMCAAcwHgYJYIZI\n" +
  "AYb4QgENBBEWD3hjYSBjZXJ0aWZpY2F0ZTAFBgMrZXADQQAblBgoa72X/K13WOvc\n" +
  "KW0fqBgFKvLy85hWD6Ufi61k4ProQiZzMK+0+y9jReKelPx/zRdCCgSbQroAR2mV\n" +
  "xjoE\n" +
  "-----END CERTIFICATE-----\n";

// Certificate chain binary data, which must be set based on the service.
let encodingBlob: certFramework.EncodingBlob = {
  data: stringToUint8Array(certChainData),
  // Set the encoding format, which can be FORMAT_PEM, FORMAT_DER, or FORMAT_PKCS7.
  encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
};

// Certificate chain validation data, which must be assigned based on the service.
let param: certFramework.CertChainValidationParameters = {
  date: '20231212080000Z',
  trustAnchors: [{
    CAPubKey: new Uint8Array([0x30, 0x2a, 0x30, 0x05, 0x06, 0x03, 0x2b, 0x65, 0x70, 0x03, 0x21, 0x00, 0xbb, 0x16,0x9d, 0x8f, 0x5c, 0x30, 0xd0, 0xba, 0x8f, 0x37, 0x6e, 0x33, 0xaf, 0x6f, 0x23, 0x71, 0x23, 0xa5, 0x49, 0x60,0x1e, 0xd1, 0x07, 0x4b, 0xc9, 0x11, 0x7e, 0x66, 0x01, 0xba, 0x92, 0x52]),
    CASubject: new Uint8Array([0x30, 0x5a, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x45,0x4e, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x07, 0x45, 0x6e, 0x67, 0x6c, 0x61, 0x6e,0x64, 0x31, 0x0f, 0x30, 0x0d, 0x06, 0x03, 0x55, 0x04, 0x07, 0x13, 0x06, 0x4c, 0x6f, 0x6e, 0x64, 0x6f, 0x6e,0x31, 0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x03, 0x74, 0x73, 0x31, 0x31, 0x0c, 0x30, 0x0a,0x06, 0x03, 0x55, 0x04, 0x0b, 0x13, 0x03, 0x74, 0x73, 0x31, 0x31, 0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04,0x03, 0x13, 0x03, 0x74, 0x73, 0x31]),
  }]
};

certFramework.createX509CertChain(encodingBlob, (err, certChain) => {
  if (err != null) {
    console.error('createX509CertChain failed, errCode: ' + err.code + ', errMsg: ' + err.message);
  } else {
    console.log('createX509CertChain success');
    certChain.validate(param, (error, validationRes) => {
      if (error != null) {
        console.error('X509CertChain validate failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        console.log('X509CertChain validate success');
      }
    });
  }
});
```
