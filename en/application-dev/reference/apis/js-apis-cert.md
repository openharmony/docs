# Certificate

The **certificate** module provides APIs for performing certificate operations. The APIs of this module depend on the basic algorithm capabilities provided by the cryptography framework. For details about the cryptography framework APIs, see [Cryptography Framework](./js-apis-cryptoFramework.md).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9.

## Modules to Import

```javascript
import cryptoCert from '@ohos.security.cert';
import cryptoFramework from "@ohos.security.cryptoFramework"
```

## CertResult

 Enumerates the error codes.

 **System capability**: SystemCapability.Security.Cert

| Name                                 | Default Value  | Description                         |
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

| Name       | Default Value  | Description      |
| ------------| ---------| -----------|
| FORMAT_DER  | 0        | Distinguished Encoding Rules (DER) format. |
| FORMAT_PEM  | 1        | Privacy-Enhanced Mail (PEM) format. |


## EncodingBlob

Defines a certificate binary array in encoding format.

### Attributes

**System capability**: SystemCapability.Security.Cert

| Name          | Type          | Readable| Writable| Description                             |
| -------------- | -------------- | ---- | ---- | ----------------------------------|
| data           | Uint8Array     | Yes  | Yes  | Certificate data.   |
| encodingFormat | [EncodingFormat](#encodingformat) | Yes  | Yes  | Certificate encoding format.|


## CertChainData

Defines the certificate chain data, which is passed in as input parameters during certificate chain verification.

### Attributes

**System capability**: SystemCapability.Security.Cert

| Name          | Type          | Readable| Writable| Description                                                        |
| -------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| data           | Uint8Array     | Yes  | Yes  | Certificate data, in the *length* (2 bytes) + *data* format. For example, **08ABCDEFGH07ABCDEFG**. The first two bytes indicate the length of the first certificate is eight bytes, and the following eight bytes indicate the certificate data. Then, the next two bytes indicates the length of another certificate is seven bytes, and the seven bytes followed indicate the certificate data.  |
| count          | number         | Yes  | Yes  | Number of certificates contained in the input data.                            |
| encodingFormat | [EncodingFormat](#encodingformat) | Yes  | Yes  | Certificate encoding format.|


## cryptoCert.createX509Cert

createX509Cert(inStream : EncodingBlob, callback : AsyncCallback\<X509Cert>) : void

Creates an **X509Cert** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type         | Mandatory| Description              |
| -------- | ------------- | ---- | ------------------ |
| inStream | [EncodingBlob](#encodingblob)  | Yes  | X.509 certificate serialization data.|
| callback | AsyncCallback\<X509Cert> | No  | Callback invoked to return the **X509Cert** instance created.          |


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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
    }
});
```

## cryptoCert.createX509Cert

createX509Cert(inStream : EncodingBlob) : Promise\<X509Cert>

Creates an **X509Cert** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type        | Mandatory| Description              |
| -------- | ------------ | ---- | ------------------ |
| inStream | [EncodingBlob](#encodingblob) | Yes  | X.509 certificate serialization data.|

**Return value**

| Type    | Description            |
| :------- | ---------------- |
| Promise\<X509Cert> |Promise used to return the **X509Cer** instance created.|

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
    Console.log("createX509Cert success");
}, error => {
    Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

## X509Cert

Provides APIs for X.509 certificate operations.

### verify

verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void

Verifies the certificate signature. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type         | Mandatory| Description              |
| -------- | ------------- | ---- | ------------------ |
| key      | cryptoFramework.PubKey        | Yes  | Public key used for signature verification.|
| callback | AsyncCallback\<void>) | No  | Callback invoked to return the result. If **error** is **null**, the signature verification is successful. If **error** is not **null**, the signature verification fails.          |


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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        // Generate a public key by AsyKeyGenerator or obtain the public key by using getPublicKey() of the X509Cert instance.
		let pubKey = null;
        x509Cert.verify(pubKey, function (error, data) {
            if (error != null) {
                Console.log("verify failed, errCode: " + error.code + ", errMsg: " + error.message);
            } else {
                Console.log("verify success");
            }
        });
    }
});
```

### verify

verify(key : cryptoFramework.PubKey) : Promise\<void>

Verifies the certificate signature. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| key    | cryptoFramework.PubKey | Yes  | Public key used for signature verification.|

**Return value**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| Promise\<void> | Promise used to return the result.|

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
    Console.log("createX509Cert success");
    // Generate a public key by AsyKeyGenerator or obtain the public key by using getPublicKey() of the X509Cert instance.
	let pubKey = null;
    x509Cert.verify(pubKey).then(result => {
        Console.log("verify success");
    }, error => {
        Console.log("verify failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getEncoded

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

Obtains the serialized X.509 certificate data. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type         | Mandatory| Description    |
| -------- | ------------- | ---- | -------- |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | No  | Callback invoked to return the serialized X.509 certificate data obtained.|


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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        x509Cert.getEncoded(function (error, data) {
           if (error != null) {
               Console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               Console.log("getEncoded success");
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

| Type        | Description                  |
| ------------ | ---------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | Promise used to return the serialized X.509 certificate data obtained.|

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
    Console.log("createX509Cert success");
    x509Cert.getEncoded().then(result => {
        Console.log("getEncoded success");
    }, error => {
        Console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getPublicKey

getPublicKey(callback : AsyncCallback\<cryptoFramework.PubKey>) : void

Obtains the public key of this X.509 certificate. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type         | Mandatory| Description    |
| -------- | ------------- | ---- | -------- |
| callback | AsyncCallback | No  | Callback invoked to return the public key obtained.|


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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        x509Cert.getPublicKey(function (error, pubKey) {
           if (error != null) {
               Console.log("getPublicKey failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               Console.log("getPublicKey success");
           }
        });
    }
});
```

### getPublicKey

getPublicKey() : Promise\<cryptoFramework.PubKey>

Obtains the public key of this X.509 certificate. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description            |
| ------ | ---------------- |
| cryptoFramework.PubKey | X.509 certificate public key obtained.|

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
cryptoCert.createX509Cert(encodingBlob).then(x509Cert => {
    Console.log("createX509Cert success");
    x509Cert.getPublicKey().then(pubKey => {
        Console.log("getPublicKey success");
    }, error => {
        Console.log("getPublicKey failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### checkValidityWithDate

checkValidityWithDate(date: string, callback : AsyncCallback\<void>) : void

Checks the validity period of this X.509 certificate. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type         | Mandatory| Description    |
| -------- | ------------- | ---- | -------- |
| date     | string        | Yes  | Date of the certificate to check.    |
| callback | AsyncCallback\<void> | No  | Callback invoked to return the result. If **error** is **null**, the certificate is valid. If **error** is not **null**, the certificate has expired.|


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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let date = "150527000001Z";
        x509Cert.checkValidityWithDate(date, function (error, data) {
           if (error != null) {
               Console.log("checkValidityWithDate failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               Console.log("checkValidityWithDate success");
           }
        });
    }
});
```

### checkValidityWithDate

checkValidityWithDate(date: string) : Promise\<void>

Checks the validity period of this X.509 certificate. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name| Type  | Mandatory| Description|
| ------ | ------ | ---- | ---- |
| date   | string | Yes  | Date of the certificate to check.|

**Return value**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| Promise\<void> | Promise used to return the result.|

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
    Console.log("createX509Cert success");
    let date = "150527000001Z";
    x509Cert.checkValidityWithDate(date).then(result => {
        Console.log("checkValidityWithDate success");
    }, error => {
        Console.log("checkValidityWithDate failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let version = x509Cert.getVersion();
    }
});
```

### getSerialNumber

getSerialNumber() : number

Obtains the X.509 certificate serial number.

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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let serialNumber = x509Cert.getSerialNumber();
    }
});
```

### getIssuerName

getIssuerName() : DataBlob

Obtains the X.509 certificate issuer.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type    | Description                  |
| -------- | ---------------------- |
| [DataBlob](#datablob) | X.509 certificate issuer obtained.|

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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let issuerName = x509Cert.getIssuerName();
    }
});
```

### getSubjectName

getSubjectName() : DataBlob

Obtains the subject of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type    | Description                |
| -------- | -------------------- |
| [DataBlob](#datablob) | Subject name obtained.|

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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let subjectName = x509Cert.getSubjectName();
    }
});
```

### getNotBeforeTime

getNotBeforeTime() : string

Obtains the start time of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| string | Start time of the X.509 certificate obtained.|

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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let notBefore = x509Cert.getNotBeforeTime();
    }
});
```

### getNotAfterTime

getNotAfterTime() : string

Obtains the expiration time of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| string | Expiration time of the X.509 certificate obtained.|

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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let notAfter = x509Cert.getNotAfterTime();
    }
});
```

### getSignature

getSignature() : DataBlob

Obtains the signature data of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type    | Description                |
| -------- | -------------------- |
| [DataBlob](#datablob) | Signature data obtained.|

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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let sigAlgOid = x509Cert.getSignatureAlgOid();
    }
});
```

### getSignatureAlgParams

getSignatureAlgParams() : DataBlob

Obtains the signing algorithm parameters of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type    | Description                    |
| -------- | ------------------------ |
| [DataBlob](#datablob) | X.509 certificate signing algorithm parameters obtained.|

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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let sigAlgParams = x509Cert.getSignatureAlgParams();
    }
});
```

### getKeyUsage

getKeyUsage() : DataBlob

Obtains the key usage of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type    | Description                |
| -------- | -------------------- |
| [DataBlob](#datablob) | Key usage of the X.509 certificate obtained.|

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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let keyUsage = x509Cert.getKeyUsage();
    }
});
```

### getExtKeyUsage

getExtKeyUsage() : DataArray

Obtains the usage of the extended key of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type     | Description                    |
| --------- | ------------------------ |
| [DataArray](#dataarray) | Usage of the extended key obtained.|

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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let basicConstraints = x509Cert.getBasicConstraints();
    }
});
```

### getSubjectAltNames

getSubjectAltNames() : DataArray

Obtains the Subject Alternative Names (SANs) of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type     | Description                    |
| --------- | ------------------------ |
| [DataArray](#dataarray) | SANs obtained.|

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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let subjectAltNames = x509Cert.getSubjectAltNames();
    }
});
```

### getIssuerAltNames

getIssuerAltNames() : DataArray

Obtains the Issuer Alternative Names (IANs) of this X.509 certificate.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type     | Description                      |
| --------- | -------------------------- |
| [DataArray](#dataarray) | IANs obtained.|

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
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let issuerAltNames = x509Cert.getIssuerAltNames();
    }
});
```

## cryptoCert.createX509Crl

createX509Crl(inStream : EncodingBlob, callback : AsyncCallback\<X509Crl>) : void

Creates an **X509Crl** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type         | Mandatory| Description                      |
| -------- | ------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob)  | Yes  | Serialized certificate revocation list (CRL) data.|
| callback | AsyncCallback\<X509Crl> | No  | Callback invoked to return the **X509Crl** instance created.                  |


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
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
    }
});
```

## cryptoCert.createX509Crl

createX509Crl(inStream : EncodingBlob) : Promise\<X509Crl>

Creates an **X509Crl** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type        | Mandatory| Description                      |
| -------- | ------------ | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob) | Yes  | Serialized CRL data.|

**Return value**

| Type   | Description                |
| ------- | -------------------- |
| Promise\<X509Crl> | Promise used to return the **X509Crl** instance created.|

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
    Console.log("createX509Crl success");
}, error => {
    Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

## X509Crl

Provides APIs for X.509 certificate CRL operations.

### isRevoked

isRevoked(cert : X509Cert, callback : AsyncCallback\<boolean>) : void

Checks whether an X.509 certificate is revoked. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type         | Mandatory| Description                |
| -------- | ------------- | ---- | -------------------- |
| cert     | [X509Cert](#x509cert)      | Yes  | X.509 certificate to check.|
| callback | AsyncCallback\<boolean> | No  | Callback invoked to return the result. The value **true** indicates that the certificate is revoked, and **false** indicates the opposite.            |


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
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        // Create an X509Cert instance.
        let x509Cert = null;
        x509Crl.isRevoked(x509Cert, function (error, isRevoked) {
           if (error != null) {
               Console.log("call isRevoked failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               Console.log("call isRevoked success");
           }
        });
    }
});
```

### isRevoked

isRevoked(cert : X509Cert) : Promise\<boolean>

Checks whether an X.509 certificate is revoked. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name| Type    | Mandatory| Description                |
| ------ | -------- | ---- | -------------------- |
| cert   | X509Cert | Yes  | X.509 certificate to check.|

**Return value**

| Type   | Description                                             |
| ------- | ------------------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** indicates the certificate is revoked; the value **false** indicates the opposite.|

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
    Console.log("createX509Crl success");
    // Create an X509Cert instance.
    let x509Cert = null;
    x509Crl.isRevoked(x509Cert).then(isRevoked => {
        Console.log("call isRevoked success");
    }, error => {
        Console.log("call isRevoked failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
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
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        let type = x509Crl.getType();
    }
});
```

### getEncoded

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

Obtains the serialized X.509 CRL data. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type         | Mandatory| Description    |
| -------- | ------------- | ---- | -------- |
| callback |  AsyncCallback\<EncodingBlob> | No  | Callback invoked to return the serialized X.509 CRL data obtained.|


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
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        x509Crl.getEncoded(function (error, data) {
           if (error != null) {
               Console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               Console.log("getEncoded success");
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

| Type        | Description                            |
| ------------ | -------------------------------- |
| Promise\<EncodingBlob> | Promise used to return the serialized X.509 CRL data obtained.|

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
    Console.log("createX509Crl success");
    x509Crl.getEncoded().then(result => {
        Console.log("getEncoded success");
    }, error => {
        Console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### verify

verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void

Verifies the signature of the X.509 CRL. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type         | Mandatory| Description                  |
| -------- | ------------- | ---- | ---------------------- |
| key      | cryptoFramework.PubKey        | Yes  | Public key used for signature verification.|
| callback | AsyncCallback\<void> | No  | Callback invoked to return the result. If **error** is **null**, the signature verification is successful. If **error** is not **null**, the signature verification fails.      |


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
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        // Generate the public key by AsyKeyGenerator.
        let pubKey = null;
        x509Crl.verify(pubKey, function (error, data) {
           if (error != null) {
               Console.log("verify failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               Console.log("verify success");
           }
        });
    }
});
```

### verify

verify(key : cryptoFramework.PubKey) : Promise\<void>

Verifies the signature of the X.509 CRL. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| key    | cryptoFramework.PubKey | Yes  | Public key used for signature verification.|

**Return value**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| Promise\<void> | Promise used to return the result.|

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
    Console.log("createX509Crl success");
    // Generate the public key by AsyKeyGenerator.
    let pubKey = null;
    x509Crl.verify(pubKey).then(result => {
        Console.log("verify success");
    }, error => {
        Console.log("verify failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
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
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        let version = x509Crl.getVersion();
    }
});
```

### getIssuerName

getIssuerName() : DataBlob

Obtains the issuer of the X.509 CRL.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type    | Description                          |
| -------- | ------------------------------ |
| [DataBlob](#datablob) | Issuer of the X.509 CRL obtained.|

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
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
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
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
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
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        let nextUpdate = x509Crl.getNextUpdate();
    }
});
```

### getRevokedCert

getRevokedCert(serialNumber : number, callback : AsyncCallback\<X509CrlEntry>) : void

Obtains the revoked X.509 certificate based on the specified serial number of the certificate. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name      | Type         | Mandatory| Description          |
| ------------ | ------------- | ---- | -------------- |
| serialNumber | number        | Yes  | Serial number of the certificate.|
| callback     | AsyncCallback\<X509CrlEntry> | No  | Callback invoked to return the revoked X.509 certificate.      |


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
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        // Set the serial number of the corresponding certificate.
        let serialNumber = 1000;
        x509Crl.getRevokedCert(serialNumber, function (error, entry) {
            if (error != null) {
                Console.log("getRevokedCert failed, errCode: " + error.code + ", errMsg: " + error.message);
            } else {
                Console.log("getRevokedCert success");
            }
        });
    }
});
```

### getRevokedCert

getRevokedCert(serialNumber : number) : Promise\<X509CrlEntry>

Obtains the revoked X.509 certificate based on the specified serial number of the certificate. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name      | Type  | Mandatory| Description          |
| ------------ | ------ | ---- | -------------- |
| serialNumber | number | Yes  | Serial number of the certificate.|

**Return value**

| Type        | Description                  |
| ------------ | ---------------------- |
| Promise\<X509CrlEntry> | Promise used to return the revoked X.509 certificate obtained.|

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
    Console.log("createX509Crl success");
    // Set the serial number of the corresponding certificate.
    let serialNumber = 1000;
    x509Crl.getRevokedCert(serialNumber).then(entry => {
        Console.log("getRevokedCert success");
    }, error => {
        Console.log("getRevokedCert failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getRevokedCertWithCert

getRevokedCertWithCert(cert : X509Cert, callback : AsyncCallback\<X509CrlEntry>) : void

Obtains the revoked X.509 certificate based on the specified certificate. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type         | Mandatory| Description        |
| -------- | ------------- | ---- | ------------ |
| cert     | X509Cert      | Yes  | Certificate based on which the revoked certificate is obtained.|
| callback | AsyncCallback\<X509CrlEntry> | No  | Callback invoked to return the revoked X.509 certificate obtained.   |


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
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        // Create an X509Cert instance.
        let x509Cert = null;
        x509Crl.getRevokedCertWithCert(x509Cert, function (error, entry) {
            if (error != null) {
                Console.log("getRevokedCertWithCert failed, errCode: " + error.code + ", errMsg: " + error.message);
            } else {
                Console.log("getRevokedCertWithCert success");
            }
        });
    }
});
```

### getRevokedCertWithCert

getRevokedCertWithCert(cert : X509Cert) : Promise\<X509CrlEntry>

Obtains the revoked X.509 certificate based on the specified certificate. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name| Type    | Mandatory| Description        |
| ------ | -------- | ---- | ------------ |
| cert   | X509Cert | Yes  | Certificate based on which the revoked certificate is obtained.|

**Return value**

| Type        | Description                  |
| ------------ | ---------------------- |
| Promise\<X509CrlEntry> | Promise used to return the revoked X.509 certificate obtained.|

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
    Console.log("createX509Crl success");
    // Create an X509Cert instance.
    let x509Cert = null;
    x509Crl.getRevokedCertWithCert(x509Cert).then(entry => {
        Console.log("getRevokedCertWithCert success");
    }, error => {
        Console.log("getRevokedCertWithCert failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getRevokedCerts

getRevokedCerts(callback : AsyncCallback<Array\<X509CrlEntry>>) : void

Obtains all the revoked X.509 certificates. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type         | Mandatory| Description    |
| -------- | ------------- | ---- | -------- |
| callback | AsyncCallback<Array\<X509CrlEntry>> | No  | Callback invoked to return the revoked X.509 certificates obtained.|


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
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        x509Crl.getRevokedCerts(function (error, array) {
            if (error != null) {
                Console.log("getRevokedCerts failed, errCode: " + error.code + ", errMsg: " + error.message);
            } else {
                Console.log("getRevokedCerts success");
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

| Type               | Description                  |
| ------------------- | ---------------------- |
|Promise<Array\<X509CrlEntry>> | Promise used to return a list of revoked X.509 certificates.|

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
    Console.log("createX509Crl success");
    x509Crl.getRevokedCerts().then(array => {
        Console.log("getRevokedCerts success");
    }, error => {
        Console.log("getRevokedCerts failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getTbsInfo

getTbsInfo(callback : AsyncCallback\<DataBlob>) : void

Obtains the DER-encoded CRL information, the **tbsCertList** from this CRL. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type         | Mandatory| Description    |
| -------- | ------------- | ---- | -------- |
| callback | AsyncCallback\<[DataBlob](#datablob)> | No  | Callback invoked to return the tbsCertList information obtained.|


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
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        x509Crl.getTbsInfo(function (error, tbsInfo) {
            if (error != null) {
                Console.log("getTbsInfo failed, errCode: " + error.code + ", errMsg: " + error.message);
            } else {
                Console.log("getTbsInfo success");
            }
        });
    }
});
```

### getTbsInfo

getTbsInfo() : Promise\<DataBlob>

Obtains the DER-encoded CRL information, the **tbsCertList** from this CRL. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type    | Description                             |
| -------- | --------------------------------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the **tbsCertList** information obtained.|

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
    Console.log("createX509Crl success");
    x509Crl.getTbsInfo().then(tbsInfo => {
        Console.log("getTbsInfo success");
    }, error => {
        Console.log("getTbsInfo failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getSignature

getSignature() : DataBlob

Obtains the signature data of the X.509 CRL.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type    | Description                          |
| -------- | ------------------------------ |
| [DataBlob](#datablob) | Signature data of the X.509 CRL obtained.|

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
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
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
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
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
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        let sigAlgOid = x509Crl.getSignatureAlgOid();
    }
});
```

### getSignatureAlgParams

getSignatureAlgParams() : DataBlob

Obtains the parameters of the X.509 CRL signing algorithm.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type    | Description                              |
| -------- | ---------------------------------- |
| [DataBlob](#datablob) | Algorithm parameters obtained.|

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
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
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

**Example**

```js
import cryptoCert from '@ohos.security.cert';

let validator = cryptoCert.createCertChainValidator("PKIX");
```

## CertChainValidator

Provides APIs for certificate chain validator operations.

### validate

validate(certChain : CertChainData, callback : AsyncCallback\<void>) : void

Validates the X.509 certificate chain. This API uses an asynchronous callback to return the result.
The certificate chain validator does not verify the certificate validity period because the system time on the device is untrusted. To check the validity period of a certificate, use the [checkValidityWithDate()](#checkvaliditywithdate) API of the **X509Cert** class. For details, see [Certificate Specifications](./../security/cert-overview.md#certificate-specifications).

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name   | Type         | Mandatory| Description                    |
| --------- | ------------- | ---- | ------------------------ |
| certChain | [CertChainData](#certchaindata) | Yes  | Serialized X.509 certificate chain data.|
| callback  | AsyncCallback\<void> | No  | Callback invoked to return the result. If **error** is **null**, the X.509 certificate chain is valid. If **error** is not **null**, the X.509 certificate chain is not valid.                |


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
        Console.log("validate failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("validate success");
    }
});
```

### validate

validate(certChain : CertChainData) : Promise\<void>

Validates the X.509 certificate chain. This API uses a promise to return the result.
The certificate chain validator does not verify the certificate validity period because the system time on the device is untrusted. To check the validity period of a certificate, use the [checkValidityWithDate()](#checkvaliditywithdate) API of the **X509Cert** class. For details, see [Certificate Specifications](./../security/cert-overview.md#certificate-specifications).

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name   | Type         | Mandatory| Description                    |
| --------- | ------------- | ---- | ------------------------ |
| certChain | [CertChainData](#certchaindata) | Yes  | Serialized X.509 certificate chain data.|

**Return value**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| Promise\<void> | Promise used to return the result.|

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
    Console.log("validate success");
}, error => {
    Console.log("validate failed, errCode: " + error.code + ", errMsg: " + error.message);
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

| Name  | Type         | Mandatory| Description    |
| -------- | ------------- | ---- | -------- |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | No  | Callback invoked to return the serialized data of the revoked certificate.|


**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Obtain X509CrlEntry by using getRevokedCert() of X509Crl.
let x509CrlEntry = null;
x509CrlEntry.getEncoded(function (error, data) {
    if (error != null) {
        Console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("getEncoded success");
    }
});
```

### getEncoded

getEncoded() : Promise\<EncodingBlob>

Obtains the serialized data of this revoked certificate. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type        | Description                      |
| ------------ | -------------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | Promise used to return the serialized data of the revoked certificate obtained.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Obtain X509CrlEntry by using getRevokedCert() of X509Crl.
let x509CrlEntry = null;
x509CrlEntry.getEncoded().then(result => {
    Console.log("getEncoded success");
}, error => {
    Console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
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

getCertIssuer(callback : AsyncCallback\<DataBlob>) : void

Obtains the issuer of this revoked certificate. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type         | Mandatory| Description    |
| -------- | ------------- | ---- | -------- |
| callback | AsyncCallback\<[DataBlob](#datablob)> | No  | Callback invoked to return the issuer of the revoked certificate obtained.|


**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Obtain X509CrlEntry by using getRevokedCert() of X509Crl.
let x509CrlEntry = null;
x509CrlEntry.getCertIssuer(function (error, issuer) {
    if (error != null) {
        Console.log("getCertIssuer failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("getCertIssuer success");
    }
});
```

### getCertIssuer

getCertIssuer() : Promise\<DataBlob>

Obtains the issuer of this revoked certificate. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type    | Description                      |
| -------- | -------------------------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the issuer of the revoked certificate obtained.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Obtain X509CrlEntry by using getRevokedCert() of X509Crl.
let x509CrlEntry = null;
x509CrlEntry.getCertIssuer().then(issuer => {
    Console.log("getCertIssuer success");
}, error => {
    Console.log("getCertIssuer failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getRevocationDate

getRevocationDate(callback : AsyncCallback\<string>) : void

Obtains the date when the certificate was revoked. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.Cert

**Parameters**

| Name  | Type         | Mandatory| Description    |
| -------- | ------------- | ---- | -------- |
| callback | AsyncCallback\<string> | No  | Callback invoked to return the certificate revocation date obtained.|


**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Obtain X509CrlEntry by using getRevokedCert() of X509Crl.
let x509CrlEntry = null;
x509CrlEntry.getRevocationDate(function (error, date) {
    if (error != null) {
        Console.log("getRevocationDate failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("getRevocationDate success");
    }
});
```

### getRevocationDate

getRevocationDate() : Promise\<string>

Obtains the date when the certificate was revoked. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.Cert

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| Promise\<string> | Promise used to return the certificate revocation date obtained.|

**Example**

```js
import cryptoCert from '@ohos.security.cert';

// Obtain X509CrlEntry by using getRevokedCert() of X509Crl.
let x509CrlEntry = null;
x509CrlEntry.getRevocationDate().then(date => {
    Console.log("getRevocationDate success");
}, error => {
    Console.log("getRevocationDate failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```
