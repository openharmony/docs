# Certificate Development

> **NOTE**
>
> This development guide applies to API version 9, OpenHarmony SDK version 3.2.9 or later, and JS development.

## Using Certificates

**When to Use**

Typical operations involve the following:

1. Parse X.509 certificate data to generate a certificate object.
2. Obtain certificate information, such as the version and serial number of the certificate.
3. Obtains the serialized data of the certificate object.
4. Obtain the certificate public key.
5. Verify the certificate signature.
6. Verify the certificate validity period.

**Available APIs**


The table below describes the APIs used in this guide.

| Instance         | API                                                      | Description                                        |
| --------------- | ------------------------------------------------------------ | -------------------------------------------- |
| cryptoCert | createX509Cert(inStream : EncodingBlob, callback : AsyncCallback<X509Cert>) : void | Parses certificate data to create an **X509Cert** instance. This API uses an asynchronous callback to return the result.|
| cryptoCert | createX509Cert(inStream : EncodingBlob) : Promise<X509Cert>  | Parses certificate data to create an **X509Cert** instance. This API uses a promise to return the result. |
| X509Cert        | verify(key : cryptoFramework.PubKey, callback : AsyncCallback<void>) : void  | Verifies the certificate signature. This API uses an asynchronous callback to return the result.                |
| X509Cert        | verify(key : cryptoFramework.PubKey) : Promise<void>                         | Verifies the certificate signature. This API uses a promise to return the result.                 |
| X509Cert        | getEncoded(callback : AsyncCallback<EncodingBlob>) : void    | Obtains serialized certificate data. This API uses an asynchronous callback to return the result.          |
| X509Cert        | getEncoded() : Promise<EncodingBlob>                         | Obtains serialized certificate data. This API uses a promise to return the result.           |
| X509Cert        | getPublicKey(callback : AsyncCallback<cryptoFramework.PubKey>) : void        | Obtains the certificate public key. This API uses an asynchronous callback to return the result.                |
| X509Cert        | getPublicKey() : Promise<cryptoFramework.PubKey>                             | Obtains the certificate public key. This API uses a promise to return the result.                 |
| X509Cert        | checkValidityWithDate(date: string, callback : AsyncCallback<void>) : void | Verifies the certificate validity period. This API uses an asynchronous callback to return the result.              |
| X509Cert        | checkValidityWithDate(date: string) : Promise<void>          | Verifies the certificate validity period. This API uses a promise to return the result.               |
| X509Cert        | getVersion() : number                                        | Obtains the certificate version.                                |
| X509Cert        | getSerialNumber() : number                                   | Obtains the certificate serial number.                              |
| X509Cert        | getIssuerName() : DataBlob                                   | Obtains the certificate issuer.                          |
| X509Cert        | getSubjectName() : DataBlob                                  | Obtains the certificate subject.                            |
| X509Cert        | getNotBeforeTime() : string                                  | Obtains the time from which the certificate takes effect.                      |
| X509Cert        | getNotAfterTime() : string                                   | Obtains the expiration time of the certificate.                      |
| X509Cert        | getSignature() : DataBlob                                    | Obtains the certificate signature.                                |
| X509Cert        | getSignatureAlgName() : string                               | Obtain the certificate signing algorithm.                        |
| X509Cert        | getSignatureAlgOid() : string                                | Obtains the certificate signing algorithm object identifier (OID).                         |
| X509Cert        | getSignatureAlgParams() : DataBlob                           | Obtains the certificate signing algorithm parameters.                        |
| X509Cert        | getKeyUsage() : DataBlob                                     | Obtains the key usage of the certificate.                            |
| X509Cert        | getExtKeyUsage() : DataArray                                 | Obtains the usage of the certificate extension key.                        |
| X509Cert        | getBasicConstraints() : number                               | Obtains the basic constraints on the certificate.                            |
| X509Cert        | getSubjectAltNames() : DataArray                             | Obtains the Subject Alternative Names (SANs) of the certificate.                        |
| X509Cert        | getIssuerAltNames() : DataArray                              | Obtains the Issuer Alternative Names (IANs) of the certificate.                      |

**How to Develop**

Example: Parse the X.509 certificate data to create an **X509Cert** instance and call APIs to perform certificate operations.

```javascript
import cryptoCert from '@ohos.security.cert';
import cryptoFramework from '@ohos.security.cryptoFramework';

// Certificate data, which is only an example. The certificate data varies with the service.
let certData = "-----BEGIN CERTIFICATE-----\n"
+ "IBzTCCAXCgAwIBAgIGAXKnMKNyMAwGCCqBHM9VAYN1BQAwSTELMAkGA1UEBhMC\n"
+ "04xDjAMBgNVBAoTBUdNU1NMMRAwDgYDVQQLEwdQS0kvU00yMRgwFgYDVQQDEw9S\n"
+ "290Q0EgZm9yIFRlc3QwIhgPMjAxNTEyMzExNjAwMDBaGA8yMDM1MTIzMDE2MDAw\n"
+ "FowSTELMAkGA1UEBhMCQ04xDjAMBgNVBAoTBUdNU1NMMRAwDgYDVQQLEwdQS0kv\n"
+ "00yMRgwFgYDVQQDEw9Sb290Q0EgZm9yIFRlc3QwWTATBgcqhkjOPQIBBggqgRzP\n"
+ "QGCLQNCAATj+apYlL+ddWXZ7+mFZXZJGbcJFXUN+Fszz6humeyWZP4qEEr2N0+a\n"
+ "dwo/21ft232yo0jPLzdscKB261zSQXSoz4wPDAZBgNVHQ4EEgQQnGnsD7oaOcWv\n"
+ "CTrspwSBDAPBgNVHRMBAf8EBTADAQH/MA4GA1UdDwEB/wQEAwIAxjAMBggqgRzP\n"
+ "QGDdQUAA0kAMEYCIQCEnW5BlQh0vmsOLxSoXYc/7zs++wWyFc1tnBHENR4ElwIh\n"
+ "I1Lwu6in1ruflZhzseWulXwcITf3bm/Y5X1g1XFWQUH\n"
+ "-----END CERTIFICATE-----\n";

// Convert the string into a Uint8Array.
function stringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; i++) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

// Certificate example
function certSample() {
    let encodingBlob = {
        // Convert the certificate data string to a Uint8Array.
        data: stringToUint8Array(certData),
        // Certificate format. Only PEM and DER are supported. In this example, the certificate is in PEM format.
        encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
    };

    // Create an X509Cert instance.
    cryptoCert.createX509Cert(encodingBlob, function (err, x509Cert) {
        if (err != null) {
            // Failed to create the X509Cert instance.
            Console.log("createX509Cert failed, errCode: " + err.code + ", errMsg: " + err.message);
            return;
        }
        // The X509Cert instance is successfully created.
        Console.log("createX509Cert success");

        // Obtain the certificate version.
        let version = x509Cert.getVersion();
        
        // Obtain the serialized data of the certificate.
        x509Cert.getEncoded(function (err, data) {
            if (err != null) {
                // Failed to obtain the serialized data of the certificate.
                Console.log("getEncoded failed, errCode: " + err.code + ", errMsg: " + err.message);
            } else {
                // The serialized data of the certificate is successfully obtained.
                Console.log("getEncoded success");
            }
        });
        
        // Obtain the certificate public key.
        x509Cert.getPublicKey(function (err, pubKey) {
            if (err != null) {
                // Failed to obtain the certificate public key.
                Console.log("getPublicKey failed, errCode: " + err.code + ", errMsg: " + err.message);
            } else {
                // The certificate public key is successfully obtained.
                Console.log("getPublicKey success");
            }
        });
        
        // Obtain the public key object using the getPublicKey() of the upper-level certificate object or this (self-signed) certificate object.
        let pubKey = null;
        
        // Verify the certificate signature.
        x509Cert.verify(pubKey, function (err, data) {
            if (err == null) {
                // The signature verification is successful.
                Console.log("verify success");
            } else {
                // The signature verification failed.
                Console.log("verify failed, errCode: " + err.code + ", errMsg: " + err.message);
            }
        });
        
        // Time represented in a string.
        let date = "150527000001Z";
        
        // Verify the certificate validity period.
        x509Cert.checkValidityWithDate(date, function (err, data) {
            if (err != null) {
                // Failed to verify the certificate validity period.
                Console.log("checkValidityWithDate failed, errCode: " + err.code + ", errMsg: " + err.message);
            } else {
                // The certificate validity period is verified successfully.
                Console.log("checkValidityWithDate success");
            }
        });
    });
}
```

## Using the CRL

**When to Use**

Typical operations involve the following:

1. Parse the X.509 CRL data to create an **X509Crl** instance.
2. Obtain the CRL information, such as the CRL version and type.
3. Obtain the serialized data of the CRL.
4. Check whether the certificate is revoked.
5. Verify the CRL signature.
6. Obtain the revoked certificates.

**Available APIs**


The table below describes the APIs used in this guide.

| Instance         | API                                                      | Description                                                        |
| --------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| cryptoCert | createX509Crl(inStream : EncodingBlob, callback : AsyncCallback<X509Crl>) : void | Parses the X.509 CRL data to create an **X509Crl** instance. This API uses an asynchronous callback to return the result.|
| cryptoCert | createX509Crl(inStream : EncodingBlob) : Promise<X509Crl>    | Parses the X.509 CRL data to create an **X509Crl** instance. This API uses a promise to return the result. |
| X509Crl         | isRevoked(cert : X509Cert, callback : AsyncCallback<boolean>) : void | Checks whether the certificate is revoked. This API uses an asynchronous callback to return the result.                          |
| X509Crl         | isRevoked(cert : X509Cert) : Promise<boolean>                | Checks whether the certificate is revoked. This API uses a promise to return the result.                           |
| X509Crl         | getType() : string                                           | Obtains the CRL type.                                        |
| X509Crl         | getEncoded(callback : AsyncCallback<EncodingBlob>) : void    | Obtains the serialized CRL data. This API uses an asynchronous callback to return the result.                  |
| X509Crl         | getEncoded() : Promise<EncodingBlob>                         | Obtains the serialized CRL data. This API uses a promise to return the result.                   |
| X509Crl         | verify(key : cryptoFramework.PubKey, callback : AsyncCallback<void>) : void  | Verifies the CRL signature. This API uses an asynchronous callback to return the result.                        |
| X509Crl         | verify(key : cryptoFramework.PubKey) : Promise<void>                         | Verifies the CRL signature. This API uses a promise to return the result.                         |
| X509Crl         | getVersion() : number                                        | Obtains the CRL version.                                        |
| X509Crl         | getIssuerName() : DataBlob                                   | Obtains the CRL issuer.                                  |
| X509Crl         | getLastUpdate() : string                                     | Obtains the date when the CRL was last updated.                              |
| X509Crl         | getNextUpdate() : string                                     | Obtains the next update date of the CRL.                              |
| X509Crl         | getRevokedCert(serialNumber : number, callback : AsyncCallback<X509CrlEntry>) : void | Obtains the revoked certificate in the CRL based on the specified serial number. This API uses an asynchronous callback to return the result.    |
| X509Crl         | getRevokedCert(serialNumber : number) : Promise<X509CrlEntry> | Obtains the revoked certificate in the CRL based on the specified serial number. This API uses a promise to return the result.     |
| X509Crl         | getRevokedCertWithCert(cert : X509Cert, callback : AsyncCallback<X509CrlEntry>) : void | Obtains the specified X.509 certificate from the CRL. This API uses an asynchronous callback to return the result.  |
| X509Crl         | getRevokedCertWithCert(cert : X509Cert) : Promise<X509CrlEntry> | Obtains the specified X.509 certificate from the CRL. This API uses a promise to return the result.   |
| X509Crl         | getRevokedCerts(callback : AsyncCallback<Array<X509CrlEntry>>) : void | Obtains all revoked certificates in the CRL. This API uses an asynchronous callback to return the result.            |
| X509Crl         | getRevokedCerts() : Promise<Array<X509CrlEntry>>             | Obtains all revoked certificates in the CRL. This API uses a promise to return the result.             |
| X509Crl         | getTbsInfo(callback : AsyncCallback<DataBlob>) : void        | Obtains the tbsCertList of the CRL. This API uses an asynchronous callback to return the result.               |
| X509Crl         | getTbsInfo() : Promise<DataBlob>                             | Obtains the tbsCertList of the CRL. This API uses a promise to return the result.                |
| X509Crl         | getSignature() : DataBlob                                    | Obtains the CRL signature.                                      |
| X509Crl         | getSignatureAlgName() : string                               | Obtains the CRL signing algorithm.                              |
| X509Crl         | getSignatureAlgOid() : string                                | Obtains the signing algorithm OID of the CRL.                               |
| X509Crl         | getSignatureAlgParams() : DataBlob                           | Obtains the signing algorithm parameters of the CRL.                              |

**How to Develop**

Example: Parse the X.509 CRL data to create an **X509Crl** instance and call APIs to perform CRL operations.

```javascript
import cryptoCert from '@ohos.security.cert';
import cryptoFramework from '@ohos.security.cryptoFramework';

// CRL data, which is only an example. The CRL data varies with the service.
let crlData = "-----BEGIN X509 CRL-----\n"
+ "MIIBijB0AgEBMA0GCSqGSIb3DQEBCwUAMBMxETAPBgNVBAMMCHJvb3QtY2ExFw0y\n"
+ "MDA2MTkxNjE1NDhaFw0yMDA3MTkxNjE1NDhaMBwwGgIJAMsozRATnap1Fw0yMDA2\n"
+ "MTkxNjEyMDdaoA8wDTALBgNVHRQEBAICEAIwDQYJKoZIhvcNAQELBQADggEBACPs\n"
+ "9gQB+djaXPHHRmAItebZpD3iJ/e36Dxr6aMVkn9FkI8OVpUI4RNcCrywyCZHQJte\n"
+ "995bbPjP7f1sZstOTZS0fDPgJ5SPAxkKOQB+SQnBFrlZSsxoUNU60gRqd2imR0Rn\n"
+ "1r09rP69F6E4yPc9biEld+llLGgoImP3zPOVDD6fbfcvVkjStY3bssVEQ/vjp4a3\n"
+ "/I12U7ZnSe3jaKqaQBoVJppkTFOIOq7IOxf5/IkMPmvRHDeC2IzDMzcUxym0dkny\n"
+ "EowHrjzo0bZVqpHMA2YgKZuwTpVLHk9GeBEK2hVkIoPVISkmiU4HFg0S6z68C5yd\n"
+ "DrAA7hErVgXhtURLbAI=\n"
+ "-----END X509 CRL-----\n";

// Convert the string into a Uint8Array.
function stringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; i++) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

// Example of a CRL.
function crlSample() {
    let encodingBlob = {
        // Convert the CRL data from a string to a Uint8Array.
        data: stringToUint8Array(crlData),
        // CRL format. Only PEM and DER are supported. In this example, the CRL is in PEM format.
        encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
    };

    // Create an X509Crl instance.
    cryptoCert.createX509Crl(encodingBlob, function (err, x509Crl) {
        if (err != null) {
            // Failed to create the X509Crl instance.
            Console.log("createX509Crl failed, errCode: " + err.code + ", errMsg: " + err.message);
            return;
        }
        // The X509Crl instance is successfully created.
        Console.log("createX509Crl success");

        // Obtain the CRL version.
        let version = x509Crl.getVersion();
        
        // Obtain the serialized data of the CRL.
        x509Crl.getEncoded(function (err, data) {
            if (err != null) {
                // Failed to obtain the serialized CRL data.
                Console.log("getEncoded failed, errCode: " + err.code + ", errMsg: " + err.message);
            } else {
                // The serialized CRL data is successfully obtained.
                Console.log("getEncoded success");
            }
        });
        
        // Create an X509Cert instance by using createX509Cert() of cryptoFramework.
        let x509Cert = null;
        
        // Check whether the certificate is revoked.
        x509Crl.isRevoked(x509Cert, function (err, isRevoked) {
            if (err != null) {
                // The operation fails.
                Console.log("isRevoked failed, errCode: " + err.code + ", errMsg: " + err.message);
            } else {
                // The operation is successful.
                Console.log("isRevoked success, isRevoked? " + isRevoked);
            }
        });
        
        // Obtain the PubKey instance by using generateKeyPair() or convertKey() of AsyKeyGenerator. The process is omitted here.
        let pubKey = null;
        
        // Verify the CRL signature.
        x509Crl.verify(pubKey, function (err, data) {
            if (err == null) {
                // The operation is successful.
                Console.log("verify success");
            } else {
                // The operation fails.
                Console.log("verify failed, errCode: " + err.code + ", errMsg: " + err.message);
            }
        });
        
        // Certificate serial number, which must be set based on the service.
        let serialNumber = 1000;
        
        // Obtain the revoked certificate based on the serial number.
        x509Crl.getRevokedCert(serialNumber, function (err, entry) {
            if (err != null) {
                // The operation fails.
                Console.log("getRevokedCert failed, errCode: " + err.code + ", errMsg: " + err.message);
            } else {
                // The operation is successful.
                Console.log("getRevokedCert success");
            }
        });
    });
}
```

## Verifying Certificate Chains

**When to Use**

You need to use the certificate chain validator in certificate chain verification.

**Available APIs**


The table below describes the APIs used in this guide.

| Instance            | API                                                      | Description                            |
| ------------------ | ------------------------------------------------------------ | -------------------------------- |
| cryptoCert | createCertChainValidator(algorithm :string) : CertChainValidator | Creates a **CertChainValidator** instance.|
| CertChainValidator | validate(certChain : CertChainData, callback : AsyncCallback<void>) : void | Verifies the certificate chain. This API uses an asynchronous callback to return the result.  |
| CertChainValidator | validate(certChain : CertChainData) : Promise<void>          | Verifies the certificate chain. This API uses a promise to return the result.       |
| CertChainValidator | algorithm : string                                           | Obtains the certificate chain validator algorithm.            |

**How to Develop**

Example: Create a **CertChainValidator** instance and verify the certificate chain.

```javascript
import cryptoCert from '@ohos.security.cert';

// CA certificate data, which is only an example. The CA certificate data varies with the service.
let caCertData = "-----BEGIN CERTIFICATE-----\n"
+ "...\n"
+ "...\n"
+ "...\n"
+ "-----END CERTIFICATE-----\n";

// End-entity certificate data, which is only an example. The certificate data varies with the service.
let secondCaCertData = "-----BEGIN CERTIFICATE-----\n"
+ "...\n"
+ "...\n"
+ "...\n"
+ "-----END CERTIFICATE-----\n";

// Convert the certificate data form a string to a Uint8Array.
function stringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; i++) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

// Certificate chain validator example. In this example, a two-level certificate chain is verified.
function certChainValidatorSample() {
    // Certificate chain validator algorithm. Currently, only PKIX is supported.
    let algorithm = "PKIX";
    
    // Create a CertChainValidator instance.
    let validator = cryptoCert.createCertChainValidator(algorithm);
    
    // CA certificate data.
    let uint8ArrayOfCaCertData = stringToUint8Array(caCertData);
    
    // Length of the CA certificate data.
    let uint8ArrayOfCaCertDataLen = new Uint8Array(new Uint16Array([uint8ArrayOfCaCertData.byteLength]).buffer);
    
    // End-entity certificate data.
    let uint8ArrayOf2ndCaCertData = stringToUint8Array(secondCaCertData);
    
    // Length of the end-entity certificate data.
    let uint8ArrayOf2ndCaCertDataLen = new Uint8Array(new Uint16Array([uint8ArrayOf2ndCaCertData.byteLength]).buffer);
    
    // Certificate chain binary data: end-entity certificate data length + end-entity certificate data + CA certificate data length + CA certificate data (in L-V format).
    let encodingData = new Uint8Array(uint8ArrayOf2ndCaCertDataLen.length + uint8ArrayOf2ndCaCertData.length +
                                     uint8ArrayOfCaCertDataLen.length + uint8ArrayOfCaCertData.length);
    for (var i = 0; i < uint8ArrayOf2ndCaCertDataLen.length; i++) {
        encodingData[i] = uint8ArrayOf2ndCaCertDataLen[i];
    }
    for (var i = 0; i < uint8ArrayOf2ndCaCertData.length; i++) {
        encodingData[uint8ArrayOf2ndCaCertDataLen.length + i] = uint8ArrayOf2ndCaCertData[i];
    }
    for (var i = 0; i < uint8ArrayOfCaCertDataLen.length; i++) {
        encodingData[uint8ArrayOf2ndCaCertDataLen.length + uint8ArrayOf2ndCaCertData.length + i] = uint8ArrayOfCaCertDataLen[i];
    }
    for (var i = 0; i < uint8ArrayOfCaCertData.length; i++) {
        encodingData[uint8ArrayOf2ndCaCertDataLen.length + uint8ArrayOf2ndCaCertData.length +
                     uint8ArrayOfCaCertDataLen.length + i] = uint8ArrayOfCaCertData[i];
    }
    
    let certChainData = {
        // Uint8Array type: L-V format (certificate data length-certificate data)
        data: encodingData,
        // Number of certificates. It is 2 in this example.
        count: 2,
        // Certificate format. PEM and DER are supported. In this example, the certificate is in PEM format.
        encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
    };
    
    // Verify the certificate chain.
    validator.validate(certChainData, function (err, data) {
        if (err != null) {
            // The operation fails.
            Console.log("validate failed, errCode: " + err.code + ", errMsg: " + err.message);
        } else {
            // The operation is successful.
            Console.log("validate success");
        }
	});
}
```

## Managing Revoked Certificates

**When to Use**

Typical operations involve the following:

1. Obtain a revoked certificate instance.
2. Obtain information, such as the serial number, issuer, and certificate revocation date, of the revoked certificate.
3. Obtain the serialized data of the revoked certificate.

**Available APIs**


The table below describes the APIs used in this guide.

| Instance      | API                                                     | Description                                      |
| ------------ | ----------------------------------------------------------- | ------------------------------------------ |
| X509CrlEntry | getEncoded(callback : AsyncCallback<EncodingBlob>) : void;  | Obtains the serialized data of the revoked certificate. This API uses an asynchronous callback to return the result.|
| X509CrlEntry | getEncoded() : Promise<EncodingBlob>;                       | Obtains the serialized data of the revoked certificate. This API uses a promise to return the result. |
| X509CrlEntry | getSerialNumber() : number;                                 | Obtains the serial number of the revoked certificate.                    |
| X509CrlEntry | getCertIssuer(callback : AsyncCallback<DataBlob>) : void;   | Obtains the issuer of the revoked certificate. This API uses an asynchronous callback to return the result.      |
| X509CrlEntry | getCertIssuer() : Promise<DataBlob>;                        | Obtains the issuer of the revoked certificate. This API uses a promise to return the result.       |
| X509CrlEntry | getRevocationDate(callback : AsyncCallback<string>) : void; | Obtains the revocation date of the certificate. This API uses an asynchronous callback to return the result.  |
| X509CrlEntry | getRevocationDate() : Promise<string>;                      | Obtains the issuer of the revoked certificate. This API uses a promise to return the result.   |

**How to Develop**

Example: Obtain a revoked certificate instance and call the APIs.

```javascript
import cryptoCert from '@ohos.security.cert';

// Example of a revoked certificate.
function crlEntrySample() {
    // Create an **X509Crl** instance by using createX509Crl() of cryptoFramework.
    let x509Crl = null;
    
    // Obtain a revoked certificate instance. In this example, the instance is obtained by using getRevokedCert().
    let serialNumber = 1000;
    x509Crl.getRevokedCert(serialNumber, function (err, crlEntry) {
        if (err != null) {
            // Failed to obtain the revoked certificate instance.
            Console.log("getRevokedCert failed, errCode: " + err.code + ", errMsg: " + err.message);
            return;
        }
        // The revoked certificate instance is successfully obtained.
        Console.log("getRevokedCert success");
        
        // Obtain the serial number of the revoked certificate.
        let serialNumber = crlEntry.getSerialNumber();
        
        // Obtain the revocation date of the revoked certificate.
        crlEntry.getRevocationDate(function (err, date) {
            if (err != null) {
                // Failed to obtain the revocation date.
                Console.log("getRevocationDate failed, errCode: " + err.code + ", errMsg: " + err.message);
            } else {
                // The revocation date is successfully obtained.
                Console.log("getRevocationDate success, date is: " + date);
            }
        });
        
        // Obtain the serialized data of the revoked certificate instance.
        crlEntry.getEncoded(function (err, data) {
            if (err != null) {
                // Failed to obtain the serialized data.
                Console.log("getEncoded failed, errCode: " + err.code + ", errMsg: " + err.message);
            } else {
                // The serialized data is successfully obtained.
                Console.log("getEncoded success");
            }
        });
    });
}
```
