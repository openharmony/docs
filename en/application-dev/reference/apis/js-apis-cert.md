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


## cryptoCert.createX509Cert

createX509Cert(inStream : EncodingBlob, callback : AsyncCallback\<X509Cert>) : void

Creates an **X509Cert** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                                 | Mandatory| Description                      |
| -------- | ------------------------------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob)         | Yes  | X.509 certificate serialization data.        |
| callback | AsyncCallback\<[X509Cert](#x509cert)> | Yes  | Callback invoked to return the result. **X509Cert** instance created.|

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
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | Yes  | Callback invoked to return the result. Promise used to return the serialized X.509 certificate data obtained.|

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

// Binary data of the certificate extension, which needs to be assigned by the service.
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

// Binary data of the certificate extension, which needs to be assigned by the service.
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
| [EncodingBlob](#encodingblob) | Returns the serialized data obtained.|

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

// Binary data of the certificate extension, which needs to be assigned by the service.
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
| [DataArray](#dataarray) | Returns a list of the OIDs obtained.|

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

// Binary data of the certificate extension, which needs to be assigned by the service.
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
| [DataBlob](#datablob) | Returns the certificate extension object information obtained.|

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

// Binary data of the certificate extension, which needs to be assigned by the service.
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

// Binary data of the certificate extension, which needs to be assigned by the service.
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

## cryptoCert.createX509Crl

createX509Crl(inStream : EncodingBlob, callback : AsyncCallback\<X509Crl>) : void

Creates an **X509Crl** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                               | Mandatory| Description                          |
| -------- | ----------------------------------- | ---- | ------------------------------ |
| inStream | [EncodingBlob](#encodingblob)       | Yes  | Serialized certificate revocation list (CRL) data.    |
| callback | AsyncCallback\<[X509Crl](#x509crl)> | Yes  | Callback invoked to return the result. Promise used to return the **X509Crl** instance created.|

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

## cryptoCert.createX509Crl

createX509Crl(inStream : EncodingBlob) : Promise\<X509Crl>

Creates an **X509Crl** instance. This API uses a promise to return the result.

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

## X509Crl

Provides APIs for X.509 certificate CRL operations.

### isRevoked

isRevoked(cert : X509Cert) : boolean

Checks whether an X.509 certificate is revoked. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name| Type    | Mandatory| Description                |
| ------ | -------- | ---- | -------------------- |
| cert   | X509Cert | Yes  | X.509 certificate to check.|

**Return value**

| Type     | Description                                          |
| --------- | --------------------------------------------- |
| boolean   | Promise used to return the result. The value **true** indicates the certificate is revoked; the value **false** indicates the opposite.|

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

### getType

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

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    let type = x509Crl.getType();
  }
});
```

### getEncoded

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

Obtains the serialized X.509 CRL data. This API uses an asynchronous callback to return the result.

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

### getEncoded

getEncoded() : Promise\<EncodingBlob>

Obtains the serialized X.509 CRL data. This API uses a promise to return the result.

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

### verify

verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void

Verifies the signature of the X.509 CRL. This API uses an asynchronous callback to return the result. The RSA algorithm is supported.

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

### verify

verify(key : cryptoFramework.PubKey) : Promise\<void>

Verifies the signature of the X.509 CRL. This API uses a promise to return the result. The RSA algorithm is supported.

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

### getVersion

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

certFramework.createX509Crl(encodingBlob, (error, x509Crl) => {
  if (error != null) {
    console.error('createX509Crl failed, errCode: ' + error.code + ', errMsg: ' + error.message);
  } else {
    console.log('createX509Crl success');
    let version = x509Crl.getVersion();
  }
});
```

### getIssuerName

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

### getLastUpdate

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

### getNextUpdate

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

### getRevokedCert

getRevokedCert(serialNumber : number) : X509CrlEntry

Obtains the revoked X.509 certificate based on the specified serial number of the certificate. This API uses an asynchronous callback to return the result.

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

### getRevokedCertWithCert

getRevokedCertWithCert(cert : X509Cert) : X509CrlEntry

Obtains the revoked X.509 certificate based on the specified certificate. This API uses an asynchronous callback to return the result.

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

### getRevokedCerts

getRevokedCerts(callback : AsyncCallback<Array\<X509CrlEntry>>) : void

Obtains all the revoked X.509 certificates. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                                                | Mandatory| Description                            |
| -------- | ---------------------------------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback<Array\<[X509CrlEntry](#x509crlentry)>> | Yes  | Callback invoked to return the result. Promise used to return a list of revoked X.509 certificates.|

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

### getRevokedCerts

getRevokedCerts() : Promise<Array\<X509CrlEntry>>

Obtains all the revoked X.509 certificates. This API uses a promise to return the result.

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

### getTbsInfo

getTbsInfo() : DataBlob

Obtains the DER-encoded CRL information, the **tbsCertList** from this CRL. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type                 | Description                           |
| --------------------- | ------------------------------- |
| [DataBlob](#datablob) | Promise used to return the **tbsCertList** information obtained.|

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

### getSignature

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

### getSignatureAlgName

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

### getSignatureAlgOid

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

### getSignatureAlgParams

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

Validates the X.509 certificate chain. This API uses an asynchronous callback to return the result.
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

## X509CrlEntry

Provides APIs for operating the revoked certificates.

### getEncoded

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

Obtains the serialized data of this revoked certificate. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type                                         | Mandatory| Description                                |
| -------- | --------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | Yes  | Callback invoked to return the result. Promise used to return the serialized data of the revoked certificate obtained.|

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

### getEncoded

getEncoded() : Promise\<EncodingBlob>

Obtains the serialized data of this revoked certificate. This API uses a promise to return the result.

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

### getSerialNumber

getSerialNumber() : number

Obtains the serial number of this revoked certificate.

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

### getCertIssuer

getCertIssuer() : DataBlob

Obtains the issuer of this revoked certificate. This API uses an asynchronous callback to return the result.

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

### getRevocationDate

getRevocationDate() : string

Obtains the date when the certificate was revoked. This API uses an asynchronous callback to return the result.

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
