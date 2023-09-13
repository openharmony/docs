# @ohos.security.cert (Certificate)

The certificate algorithm library framework provides certificate-related APIs. For details about the APIs for implementing the basic algorithm capabilities based on the cryptographic (crypto) framework, see [Crypto Framework](js-apis-cryptoFramework.md).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The following code snippets apply only to JavaScript development.

## Modules to Import

```javascript
import cryptoCert from '@ohos.security.cert';
import cryptoFramework from "@ohos.security.cryptoFramework"
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

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
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

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob).then(x509Cert => {
    console.log("createX509Cert success");
}, error => {
    console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
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

| ID| Error Message          |
| -------- | ------------------ |
| 19030001 | crypto operation error.      |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        // Obtain the public key by using getPublicKey() of the upper-level X509Cert object.
		let pubKey = null;
        x509Cert.verify(pubKey, function (error, data) {
            if (error != null) {
                console.log("verify failed, errCode: " + error.code + ", errMsg: " + error.message);
            } else {
                console.log("verify success");
            }
        });
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

| ID| Error Message          |
| -------- | ------------------ |
| 19030001 | crypto operation error.      |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob).then(x509Cert => {
    console.log("createX509Cert success");
    // Obtain the public key by using getPublicKey() of the upper-level X509Cert object.
	let pubKey = null;
    x509Cert.verify(pubKey).then(result => {
        console.log("verify success");
    }, error => {
        console.log("verify failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
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

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        x509Cert.getEncoded(function (error, data) {
           if (error != null) {
               console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               console.log("getEncoded success");
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

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob).then(x509Cert => {
    console.log("createX509Cert success");
    x509Cert.getEncoded().then(result => {
        console.log("getEncoded success");
    }, error => {
        console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
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

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19030001 | crypto operation error.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';
import cryptoFramework from "@ohos.security.cryptoFramework"

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let pubKey = null;
        try {
            pubKey = x509Cert.getPublicKey();
        } catch (error) {
            console.log("getPublicKey failed, errCode: " + error.code + ", errMsg: " + error.message);
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

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19030001 | crypto operation error.|
| 19030003 | the certificate has not taken effect.                                     |
| 19030004 | the certificate has expired.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let date = "150527000001Z";
        
        // Verify the certificate validity period.
        try {
            x509Cert.checkValidityWithDate(date);
        } catch (error) {
            console.log("checkValidityWithDate failed, errCode: " + error.code + ", errMsg: " + error.message);
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

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
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

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
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

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020002 | runtime error.                                    |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let serialNumber = x509Cert.getCertSerialNumber();
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

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let issuerName = x509Cert.getIssuerName();
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

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let subjectName = x509Cert.getSubjectName();
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

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let notBefore = x509Cert.getNotBeforeTime();
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

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let notAfter = x509Cert.getNotAfterTime();
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

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let signature = x509Cert.getSignature();
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

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let sigAlgName = x509Cert.getSignatureAlgName();
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

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let sigAlgOid = x509Cert.getSignatureAlgOid();
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

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let sigAlgParams = x509Cert.getSignatureAlgParams();
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

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                    |
| 19030001 | crypto operation error.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let keyUsage = x509Cert.getKeyUsage();
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

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let extKeyUsage = x509Cert.getExtKeyUsage();
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

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
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

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let subjectAltNames = x509Cert.getSubjectAltNames();
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

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 19020001 | memory error.                                     |
| 19020002 | runtime error.                                    |
| 19030001 | crypto operation error.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let issuerAltNames = x509Cert.getIssuerAltNames();
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Certificate binary data, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Cert success");
        let tbs = x509Cert.getItem(cryptoCert.CertItemType.CERT_ITEM_TYPE_TBS);
        let pubKey = x509Cert.getItem(cryptoCert.CertItemType.CERT_ITEM_TYPE_PUBLIC_KEY);
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

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the certificate extension, which needs to be assigned by the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Assign a value based on the encodingData format. Currently, only FORMAT_DER is supported.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_DER
};
cryptoCert.createCertExtension(encodingBlob, function (error, certExt) {
    if (error != null) {
        console.log("createCertExtension failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createCertExtension success");
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

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the certificate extension, which needs to be assigned by the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Assign a value based on the encodingData format. Currently, only FORMAT_DER is supported.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_DER
};
cryptoCert.createCertExtension(encodingBlob).then(certExt => {
    console.log("createCertExtension success");
}, error => {
    console.log("createCertExtension failed, errCode: " + error.code + ", errMsg: " + error.message);
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the certificate extension, which needs to be assigned by the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Assign a value based on the encodingData format. Currently, only FORMAT_DER is supported.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_DER
};
cryptoCert.createCertExtension(encodingBlob, function (error, certExt) {
    if (error != null) {
        console.log("createCertExtension failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createCertExtension success");
        let encodingBlob = certExt.getEncoded()
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the certificate extension, which needs to be assigned by the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Assign a value based on the encodingData format. Currently, only FORMAT_DER is supported.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_DER
};
cryptoCert.createCertExtension(encodingBlob, function (error, certExt) {
    if (error != null) {
        console.log("createCertExtension failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createCertExtension success");
        let oidList = certExt.getOidList(cryptoCert.ExtensionOidType.EXTENSION_OID_TYPE_ALL)
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the certificate extension, which needs to be assigned by the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Assign a value based on the encodingData format. Currently, only FORMAT_DER is supported.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_DER
};
cryptoCert.createCertExtension(encodingBlob, function (error, certExt) {
    if (error != null) {
        console.log("createCertExtension failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createCertExtension success");
        let oid = new Uint8Array([0x31, 0x2e, 0x32, 0x2e, 0x38, 0x2e, 0x31])
        let oidBlob = {
            data: oid
        }
        let entry = certExt.getEntry(cryptoCert.ExtensionEntryType.EXTENSION_ENTRY_TYPE_ENTRY, oidBlob)
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
| number | If the key purpose in the certificate extension contains signing and the CA field in the basic constraints is **true**, the certificate is a CA certificate.<br/>Returns **-1** if the certificate is not a CA certificate; returns the path length in the basic constraints otherwise. <br/>Returns **-2** if the certificate is a CA certificate but the path length is not specified in the basic constraints, which means the path length is not limited. |

**Error codes**

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the certificate extension, which needs to be assigned by the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Assign a value based on the encodingData format. Currently, only FORMAT_DER is supported.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_DER
};
cryptoCert.createCertExtension(encodingBlob, function (error, certExt) {
    if (error != null) {
        console.log("createCertExtension failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createCertExtension success");
        let res = certExt.checkCA()
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

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
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

| ID| Error Message     |
| -------- | ------------- |
| 19020001 | memory error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob).then(x509Crl => {
    console.log("createX509Crl success");
}, error => {
    console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
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

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        // Create an X509Cert instance.
        let x509Cert = null;
        try {
            let revokedFlag = x509Crl.isRevoked(x509Cert);
        } catch (error) {
           console.log("isRevoked failed, errCode: " + error.code + ", errMsg: " + error.message);
        }
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

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        x509Crl.getEncoded(function (error, data) {
           if (error != null) {
               console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               console.log("getEncoded success");
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob).then(x509Crl => {
    console.log("createX509Crl success");
    x509Crl.getEncoded().then(result => {
        console.log("getEncoded success");
    }, error => {
        console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';
import cryptoFramework from "@ohos.security.cryptoFramework"

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        // Generate the public key by using AsyKeyGenerator.
        let pubKey = null;
        x509Crl.verify(pubKey, function (error, data) {
           if (error != null) {
               console.log("verify failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               console.log("verify success");
           }
        });
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';
import cryptoFramework from "@ohos.security.cryptoFramework"

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob).then(x509Crl => {
    console.log("createX509Crl success");
    // Generate the public key by using AsyKeyGenerator.
    let pubKey = null;
    x509Crl.verify(pubKey).then(result => {
        console.log("verify success");
    }, error => {
        console.log("verify failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
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

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        let issuerName = x509Crl.getIssuerName();
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        let lastUpdate = x509Crl.getLastUpdate();
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        let nextUpdate = x509Crl.getNextUpdate();
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        // Set the serial number of the certificate.
        let serialNumber = 1000;
        try {
            let entry = x509Crl.getRevokedCert(serialNumber);
        } catch (error) {
           console.log("getRevokedCert failed, errCode: " + error.code + ", errMsg: " + error.message);
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        // Create an X509Cert instance.
        let x509Cert = null;
        try {
            let entry = x509Crl.getRevokedCertWithCert(x509Cert);
        } catch (error) {
           console.log("getRevokedCertWithCert failed, errCode: " + error.code + ", errMsg: " + error.message);
        }
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        x509Crl.getRevokedCerts(function (error, array) {
            if (error != null) {
                console.log("getRevokedCerts failed, errCode: " + error.code + ", errMsg: " + error.message);
            } else {
                console.log("getRevokedCerts success");
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob).then(x509Crl => {
    console.log("createX509Crl success");
    x509Crl.getRevokedCerts().then(array => {
        console.log("getRevokedCerts success");
    }, error => {
        console.log("getRevokedCerts failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        try {
            let tbsInfo = x509Crl.getTbsInfo();
        } catch (error) {
           console.log("getTbsInfo failed, errCode: " + error.code + ", errMsg: " + error.message);
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        let signature = x509Crl.getSignature();
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        let sigAlgName = x509Crl.getSignatureAlgName();
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        let sigAlgOid = x509Crl.getSignatureAlgOid();
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Binary data of the CRL, which must be set based on the service.
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
};
cryptoCert.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("createX509Crl success");
        let sigAlgParams = x509Crl.getSignatureAlgParams();
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

let validator = cryptoCert.createCertChainValidator("PKIX");
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

```js
import cryptoCert from '@ohos.security.cert';

let validator = cryptoCert.createCertChainValidator("PKIX");
// Certificate chain binary data, which must be set based on the service.
let encodingData = null;
// Number of certificates in the certificate chain. It must be set based on the service.
let certCount = 2;
let certChainData = {
    data: encodingData,
    count: certCount,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM 
};
validator.validate(certChainData, function (error, data) {
    if (error != null) {
        console.log("validate failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("validate success");
    }
});
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

```js
import cryptoCert from '@ohos.security.cert';

let validator = cryptoCert.createCertChainValidator("PKIX");
// Certificate chain binary data, which must be set based on the service.
let encodingData = null;
// Number of certificates in the certificate chain. It must be set based on the service.
let certCount = 2;
let certChainData = {
    data: encodingData,
    count: certCount,
    // Set the encoding format, which can be FORMAT_PEM or FORMAT_DER.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM 
};
validator.validate(certChainData).then(result => {
    console.log("validate success");
}, error => {
    console.log("validate failed, errCode: " + error.code + ", errMsg: " + error.message);
});
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

```js
import cryptoCert from '@ohos.security.cert';

let validator = cryptoCert.createCertChainValidator("PKIX");
let algorithm = validator.algorithm;
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Obtain X509CrlEntry by using getRevokedCert() of X509Crl.
let x509CrlEntry = null;
x509CrlEntry.getEncoded(function (error, data) {
    if (error != null) {
        console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        console.log("getEncoded success");
    }
});
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Obtain X509CrlEntry by using getRevokedCert() of X509Crl.
let x509CrlEntry = null;
x509CrlEntry.getEncoded().then(result => {
    console.log("getEncoded success");
}, error => {
    console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
});
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

```js
import cryptoCert from '@ohos.security.cert';

// Obtain X509CrlEntry by using getRevokedCert() of X509Crl.
let x509CrlEntry = null;
let serialNumber = x509CrlEntry.getSerialNumber();
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

| ID| Error Message      |
| -------- | -------------- |
| 19020001 | memory error.  |
| 19020002 | runtime error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Obtain X509CrlEntry by using getRevokedCert() of X509Crl.
let x509CrlEntry = null;
try {
    let issuer = x509CrlEntry.getCertIssuer();
} catch (error) {
    console.log("getCertIssuer failed, errCode: " + error.code + ", errMsg: " + error.message);
}
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

| ID| Error Message               |
| -------- | ----------------------- |
| 19020001 | memory error.           |
| 19020002 | runtime error.          |
| 19030001 | crypto operation error. |

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Obtain X509CrlEntry by using getRevokedCert() of X509Crl.
let x509CrlEntry = null;
try {
    let date = x509CrlEntry.getRevocationDate();
} catch (error) {
    console.log("getRevocationDate failed, errCode: " + error.code + ", errMsg: " + error.message);
}
```
