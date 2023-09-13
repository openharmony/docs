# Certificate Development

> **NOTE**
>
> This guide applies only to JavaScript development using the SDK of API version 9 or later.

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

For details about the APIs, see [Certificate](../reference/apis/js-apis-cert.md).

The table below describes the APIs used in this guide.

| Instance         | API                                                      | Description                                        |
| --------------- | ------------------------------------------------------------ | -------------------------------------------- |
| cryptoCert | createX509Cert(inStream : EncodingBlob, callback : AsyncCallback\<X509Cert>) : void | Parses certificate data to create an **X509Cert** instance. This API uses an asynchronous callback to return the result.|
| cryptoCert | createX509Cert(inStream : EncodingBlob) : Promise\<X509Cert>  | Parses certificate data to create an **X509Cert** instance. This API uses a promise to return the result. |
| X509Cert        | verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void  | Verifies the certificate signature. This API uses an asynchronous callback to return the result.                |
| X509Cert        | verify(key : cryptoFramework.PubKey) : Promise\<void>                         | Verifies the certificate signature. This API uses a promise to return the result.                 |
| X509Cert        | getEncoded(callback : AsyncCallback\<EncodingBlob>) : void    | Obtains serialized certificate data. This API uses an asynchronous callback to return the result.          |
| X509Cert        | getEncoded() : Promise\<EncodingBlob>                         | Obtains serialized certificate data. This API uses a promise to return the result.           |
| X509Cert        | getPublicKey() : cryptoFramework.PubKey                       | Obtains the certificate public key.                              |
| X509Cert        | checkValidityWithDate(date: string) : void                   | Checks the certificate validity period.                             |
| X509Cert        | getVersion() : number                                        | Obtains the certificate version.                                |
| X509Cert | getCertSerialNumber() : bigint<sup>10+</sup> | Obtains the certificate serial number.|
| X509Cert        | getIssuerName() : DataBlob                                   | Obtains the certificate issuer.                          |
| X509Cert        | getSubjectName() : DataBlob                                  | Obtains the certificate subject.                            |
| X509Cert        | getNotBeforeTime() : string                                  | Obtains the time from which the certificate takes effect.                      |
| X509Cert        | getNotAfterTime() : string                                   | Obtains the expiration time of the certificate.                      |
| X509Cert        | getSignature() : DataBlob                                    | Obtains the certificate signature.                                |
| X509Cert        | getSignatureAlgName() : string                               | Obtains the certificate signing algorithm.                        |
| X509Cert        | getSignatureAlgOid() : string                                | Obtains the certificate signing algorithm object identifier (OID).                         |
| X509Cert        | getSignatureAlgParams() : DataBlob                           | Obtains the certificate signing algorithm parameters.                        |
| X509Cert        | getKeyUsage() : DataBlob                                     | Obtains the key usage of the certificate.                            |
| X509Cert        | getExtKeyUsage() : DataArray                                 | Obtains the usage of the certificate extension key.                        |
| X509Cert        | getBasicConstraints() : number                               | Obtains the basic constraints on the certificate.                            |
| X509Cert        | getSubjectAltNames() : DataArray                             | Obtains the Subject Alternative Names (SANs) of the certificate.                        |
| X509Cert        | getIssuerAltNames() : DataArray                              | Obtains the Issuer Alternative Names (IANs) of the certificate.                      |
| X509Cert        | getItem(itemType: CertItemType) : DataBlob<sup>10+</sup>          | Obtains the fields of the X.509 certificate.                      |
**How to Develop**

Example: Parse the X.509 certificate data to create an **X509Cert** instance and call APIs to perform certificate operations.

```javascript
import cryptoCert from '@ohos.security.cert';
import cryptoFramework from '@ohos.security.cryptoFramework';

// Certificate data, which is only an example. The certificate data varies with the service.
let certData = "-----BEGIN CERTIFICATE-----\n"
+ "MIID/jCCAuagAwIBAgIBATANBgkqhkiG9w0BAQsFADCBjDELMAkGA1UEBhMCQ04x\n"
+ "ETAPBgNVBAgMCHNoYW5naGFpMQ8wDQYDVQQHDAZodWF3ZWkxFTATBgNVBAoMDHd3\n"
+ "dy50ZXN0LmNvbTENMAsGA1UECwwEdGVzdDEVMBMGA1UEAwwMd3d3LnRlc3QuY29t\n"
+ "MRwwGgYJKoZIhvcNAQkBFg10ZXN0QHRlc3QuY29tMB4XDTIyMDgyOTA2NTUwM1oX\n"
+ "DTIzMDgyOTA2NTUwM1owezELMAkGA1UEBhMCQ04xETAPBgNVBAgMCHNoYW5naGFp\n"
+ "MRUwEwYDVQQKDAx3d3cudGVzdC5jb20xDTALBgNVBAsMBHRlc3QxFTATBgNVBAMM\n"
+ "DHd3dy50ZXN0LmNvbTEcMBoGCSqGSIb3DQEJARYNdGVzdEB0ZXN0LmNvbTCCASIw\n"
+ "DQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAJmY9T4SzXXwKvfMvnvMWY7TqUJK\n"
+ "jnWf2Puv0YUQ2fdvyoKQ2LQXdtzoUL53j587oI+IXelOr7dg020zPyun0cmZHZ4y\n"
+ "l/qAcrWbDjZeEGcbbb5UtQtn1WOEnv8pkXluO355mbZQUKK9L3gFWseXJKGbIXw0\n"
+ "NRpaJZzqvPor4m3a5pmJKPHOlivUdYfLaKSkNj3DlaFzCWKV82k5ee6gzVyETtG+\n"
+ "XN+vq8qLybT+fIFsLNMmAHzRxlqz3NiH7yh+1/p/Knvf8bkkRVR2btH51RyX2RSu\n"
+ "DjPM0/VRL8fxDSDeWBq+Gvn/E6AbOVMmkx63tcyWHhklCSaZtyz7kq39TQMCAwEA\n"
+ "AaN7MHkwCQYDVR0TBAIwADAsBglghkgBhvhCAQ0EHxYdT3BlblNTTCBHZW5lcmF0\n"
+ "ZWQgQ2VydGlmaWNhdGUwHQYDVR0OBBYEFFiFDysfADQCzRZCOSPupQxFicwzMB8G\n"
+ "A1UdIwQYMBaAFNYQRQiPsG8HefOTsmsVhaVjY7IPMA0GCSqGSIb3DQEBCwUAA4IB\n"
+ "AQAeppxf6sKQJxJQXKPTT3xHKaskidNwDBbOSIvnVvWXicZXDs+1sF6tUaRgvPxL\n"
+ "OL58+P2Jy0tfSwj2WhqQRGe9MvQ5iFHcdelZc0ciW6EQ0VDHIaDAQc2nQzej/79w\n"
+ "UE7BJJV3b9n1be2iCsuodKO14pOkMb84WcIxng+8SD+MiFqV5BPO1QyKGdO1PE1b\n"
+ "+evjyTpFSTgZf2Mw3fGtu5hfEXyHw1lnsFY2MlSwiRlAym/gm4aXy+4H6LyXKd56\n"
+ "UYQ6fituD0ziaw3RI6liyIe7aENHCkZf6bAvMRhk4QiU4xu6emwX8Qt1bT7RthP0\n"
+ "1Vsro0IOeXT9WAcqEtQUegsi\n"
+ "-----END CERTIFICATE-----\n";

// Convert the certificate data form a string to a Uint8Array.
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
            console.log("createX509Cert failed, errCode: " + err.code + ", errMsg: " + err.message);
            return;
        }
        // The X509Cert instance is successfully created.
        console.log("createX509Cert success");

        // Obtain the certificate version.
        let version = x509Cert.getVersion();
        
        // Obtain the serialized data of the certificate.
        x509Cert.getEncoded(function (err, data) {
            if (err != null) {
                // Failed to obtain the serialized data of the certificate.
                console.log("getEncoded failed, errCode: " + err.code + ", errMsg: " + err.message);
            } else {
                // The serialized data of the certificate is successfully obtained.
                console.log("getEncoded success");
            }
        });

        // Obtain the public key object using the getPublicKey() of the upper-level certificate object or this (self-signed) certificate object.
        let pubKey = null;
        try {
            pubKey = x509Cert.getPublicKey();
        } catch (error) {
            console.log("getPublicKey failed, errCode: " + error.code + ", errMsg: " + error.message);
        }

        // Verify the certificate signature.
        x509Cert.verify(pubKey, function (err, data) {
            if (err == null) {
                // The signature verification is successful.
                console.log("verify success");
            } else {
                // The signature verification failed.
                console.log("verify failed, errCode: " + err.code + ", errMsg: " + err.message);
            }
        });

        // Time represented in a string.
        let date = "20220830000001Z";
        
        // Verify the certificate validity period.
        try {
            x509Cert.checkValidityWithDate(date);
        } catch (error) {
            console.log("checkValidityWithDate failed, errCode: " + error.code + ", errMsg: " + error.message);
        }
    });
}
```

## Operating Certificate Extensions

> **NOTE**
>
> The following scenario applies to JS development using API version 10 and OpenHarmony SDK 4.0.9 or later.

**When to Use**

Typical operations involve the following:

1. Parse the certificate extension data to generate a certificate extension object.
2. Obtain certificate extension information, for example, obtaining the object identifiers (OIDs) of certificate extensions and obtaining specific data based on an OID.
3. Check whether a certificate is a CA certificate.

**Available APIs**

For details about the APIs, see [Certificate](../reference/apis/js-apis-cert.md).

The table below describes the APIs used in this guide.

| Instance       | API                                                      | Description                                  |
| ------------- | ------------------------------------------------------------ | -------------------------------------- |
| cryptoCert    | createCertExtension(inStream : EncodingBlob, callback : AsyncCallback) : void | Creates a **certExtension** instance. This API uses an asynchronous callback to return the result.|
| cryptoCert    | createCertExtension(inStream : EncodingBlob) : Promise       | Creates a **certExtension** instance. This API uses a promise to return the result. |
| CertExtension | getEncoded() : EncodingBlob                                  | Obtains the serialized data of the certificate extension.            |
| CertExtension | getOidList(valueType : ExtensionOidType) : DataArray         | Obtains the OIDs of certificate extensions.        |
| CertExtension | getEntry(valueType: ExtensionEntryType, oid : DataBlob) : DataBlob | Obtains the certificate extension object information.              |
| CertExtension | checkCA() : number                                           | Checks whether the certificate is a CA certificate.                  |

**How to Develop**

Example: Parse the X.509 certificate extension data to generate a **CerExtension** instance and call the related APIs.

```javascript
import cryptoCert from '@ohos.security.cert';

// Certificate extension data, which is only an example. Set it based on service requirements.
let certData = new Uint8Array([
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

// Convert the string into a Uint8Array.
function stringToUint8Array(str) {
  var arr = [];
  for (var i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate extension example.
function certExtensionSample() {
  let encodingBlob = {
    data: certData,
    // Certificate extension format. Currently, only the DER format is supported.
    encodingFormat: cryptoCert.EncodingFormat.FORMAT_DER
  };

  // Create a CerExtension instance.
  cryptoCert.createCertExtension(encodingBlob, function (err, certExtension) {
    if (err != null) {
      // The CerExtension instance fails to be created.
      console.log("createCertExtension failed, errCode: " + err.code + ", errMsg: " + err.message);
      return;
    }
    // A CerExtension instance is created.
    console.log("createCertExtension success");
    
    try {
      // Obtain the serialized data of the CerExtension instance.
      let encodedData = certExtension.getEncoded();
      
      // Obtain the OIDs of the certificate extensions.
      let oidList = certExtension.getOidList(cryptoCert.ExtensionOidType.EXTENSION_OID_TYPE_ALL);
      
      // Obtain the certificate extension information based on a OID.
      let oidData = "2.5.29.14";
      let oid = {
        data: stringToUint8Array(oidData),
      }
      let entry = certExtension.getEntry(cryptoCert.ExtensionEntryType.EXTENSION_ENTRY_TYPE_ENTRY, oid);
        
      // Check whether the certificate is a CA certificate.
      let pathLen = certExtension.checkCA();
    } catch (err) {
      console.log("operation failed: " + JSON.stringify(err));
    }
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

For details about the APIs, see [Certificate](../reference/apis/js-apis-cert.md).

The table below describes the APIs used in this guide.

| Instance         | API                                                      | Description                                                        |
| --------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| cryptoCert | createX509Crl(inStream : EncodingBlob, callback : AsyncCallback\<X509Crl>) : void | Parses the X.509 CRL data to create an **X509Crl** instance. This API uses an asynchronous callback to return the result.|
| cryptoCert | createX509Crl(inStream : EncodingBlob) : Promise\<X509Crl>    | Parses the X.509 CRL data to create an **X509Crl** instance. This API uses a promise to return the result. |
| X509Crl         | isRevoked(cert : X509Cert) : boolean                     |  Checks whether the certificate is revoked.                           |
| X509Crl         | getType() : string                                           | Obtains the CRL type.                                       |
| X509Crl         | getEncoded(callback : AsyncCallback\<EncodingBlob>) : void    | Obtains the serialized CRL data. This API uses an asynchronous callback to return the result.                  |
| X509Crl         | getEncoded() : Promise\<EncodingBlob>                         | Obtains the serialized CRL data. This API uses a promise to return the result.                   |
| X509Crl         | verify(key : cryptoFramework.PubKey, callback : AsyncCallback\<void>) : void  | Verifies the CRL signature. This API uses an asynchronous callback to return the result.       |
| X509Crl         | verify(key : cryptoFramework.PubKey) : Promise\<void>                         | Verifies the CRL signature. This API uses a promise to return the result.        |
| X509Crl         | getVersion() : number                                        | Obtains the CRL version.                                       |
| X509Crl         | getIssuerName() : DataBlob                                   | Obtains the CRL issuer.                                  |
| X509Crl         | getLastUpdate() : string                                     | Obtains the date when the CRL was last updated.                              |
| X509Crl         | getNextUpdate() : string                                     | Obtains the next update date of the CRL.                              |
| X509Crl         | getRevokedCert(serialNumber : number) : X509CrlEntry         | Obtains the revoked certificate in the CRL based on the serial number.                      |
| X509Crl         | getRevokedCertWithCert(cert : X509Cert) : X509CrlEntry         | Obtains the revoked certificate in the CRL based on the X.509 certificate.                  |
| X509Crl         | getRevokedCerts(callback : AsyncCallback\<Array\<X509CrlEntry>>) : void | Obtains all revoked certificates in the CRL. This API uses an asynchronous callback to return the result.   |
| X509Crl         | getRevokedCerts() : Promise\<Array\<X509CrlEntry>>             | Obtains all revoked certificates in the CRL. This API uses a promise to return the result.             |
| X509Crl         | getTbsInfo() : DataBlob                                      | Obtains **tbsCertList** of the CRL.                               |
| X509Crl         | getSignature() : DataBlob                                    | Obtains the CRL signature.                                      |
| X509Crl         | getSignatureAlgName() : string                               | Obtains the CRL signing algorithm.                               |
| X509Crl         | getSignatureAlgOid() : string                                | Obtains the signing algorithm OID of the CRL.                                |
| X509Crl         | getSignatureAlgParams() : DataBlob                           | Obtains the signing algorithm parameters of the CRL.                               |

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

// Convert the certificate data form a string to a Uint8Array.
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
            console.log("createX509Crl failed, errCode: " + err.code + ", errMsg: " + err.message);
            return;
        }
        // The X509Crl instance is successfully created.
        console.log("createX509Crl success");

        // Obtain the CRL version.
        let version = x509Crl.getVersion();
        
        // Obtain the serialized data of the CRL.
        x509Crl.getEncoded(function (err, data) {
            if (err != null) {
                // Failed to obtain the serialized data of the certificate.
                console.log("getEncoded failed, errCode: " + err.code + ", errMsg: " + err.message);
            } else {
                // The serialized data of the certificate is successfully obtained.
                console.log("getEncoded success");
            }
        });

        // Create an X509Cert instance by using createX509Cert() of cryptoFramework. The process is omitted here.
        let x509Cert = null;
        // Check whether the certificate is revoked.
        try {
            let revokedFlag = x509Crl.isRevoked(x509Cert);
        } catch (error) {
           console.log("isRevoked failed, errCode: " + error.code + ", errMsg: " + error.message);
        }

        // The binary data of the public key needs to be passed to convertKey() of @ohos.security.cryptoFramework to obtain the PubKey object. The process is omitted here.
        let pubKey = null;
        
        // Verify the CRL signature.
        x509Crl.verify(pubKey, function (err, data) {
            if (err == null) {
                // The signature verification is successful.
                console.log("verify success");
            } else {
                // The signature verification failed.
                console.log("verify failed, errCode: " + err.code + ", errMsg: " + err.message);
            }
        });

        // Certificate serial number, which must be set based on the service.
        let serialNumber = 1000;

        // Obtain the revoked certificate based on the serial number.
        try {
            let entry = x509Crl.getRevokedCert(serialNumber);
        } catch (error) {
           console.log("getRevokedCert failed, errCode: " + error.code + ", errMsg: " + error.message);
        }
    });
}
```

## Verifying Certificate Chains

**When to Use**

You need to use the certificate chain validator in certificate chain verification.

**Available APIs**

For details about the APIs, see [Certificate](../reference/apis/js-apis-cert.md).

The table below describes the APIs used in this guide.

| Instance            | API                                                      | Description                            |
| ------------------ | ------------------------------------------------------------ | -------------------------------- |
| cryptoCert | createCertChainValidator(algorithm :string) : CertChainValidator | Creates a **CertChainValidator** instance.|
| CertChainValidator | validate(certChain : CertChainData, callback : AsyncCallback\<void>) : void | Verifies the certificate chain. This API uses an asynchronous callback to return the result.  |
| CertChainValidator | validate(certChain : CertChainData) : Promise\<void>          | Verifies the certificate chain. This API uses a promise to return the result.       |
| CertChainValidator | algorithm : string                                           | Obtains the certificate chain validator algorithm.            |

**How to Develop**

Example: Create a **CertChainValidator** instance and verify the certificate chain.

```javascript
import cryptoCert from '@ohos.security.cert';

// CA certificate data, which is only an example. The certificate data varies with the service.
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

// Convert the certificate data form a string to a Uint8Array..
function stringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; i++) {
        arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
}

// Certificate chain validator example: In this example, a two-level certificate chain is verified. The code may vary with the service requirements.
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
        // Certificate format. Only PEM and DER are supported. In this example, the certificate is in PEM format.
        encodingFormat: cryptoCert.EncodingFormat.FORMAT_PEM
    };
    
    // Verify the certificate chain.
    validator.validate(certChainData, function (err, data) {
        if (err != null) {
            // Failed to verify the certificate chain.
            console.log("validate failed, errCode: " + err.code + ", errMsg: " + err.message);
        } else {
            // The certificate chain verification is successful.
            console.log("validate success");
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

For details about the APIs, see [Certificate](../reference/apis/js-apis-cert.md).

The table below describes the APIs used in this guide.

| Instance      | API                                                     | Description                                     |
| ------------ | ----------------------------------------------------------- | ---------------------------------------- |
| X509CrlEntry | getEncoded(callback : AsyncCallback\<EncodingBlob>) : void;  | Obtains the serialized data of the revoked certificate. This API uses an asynchronous callback to return the result.|
| X509CrlEntry | getEncoded() : Promise\<EncodingBlob>;                       | Obtains the serialized data of the revoked certificate. This API uses a promise to return the result. |
| X509CrlEntry | getSerialNumber() : number;                                  | Obtains the serial number of the revoked certificate.                   |
| X509CrlEntry | getCertIssuer() : DataBlob;                                  | Obtains the issuer of the revoked certificate.                    |
| X509CrlEntry | getRevocationDate() : string;                                | Obtains the revocation date of the revoked certificate.                 |

**How to Develop**

Example: Obtain a revoked certificate instance and call the APIs.

```javascript
import cryptoCert from '@ohos.security.cert';

// Example of a revoked certificate.
function crlEntrySample() {
    // Create an X509Crl object by using createX509Crl() of the cryptoFramework. The process is omitted here.
    let x509Crl = null;
    
    // Obtain a revoked certificate instance. The service needs to call the X509Crl interface to obtain the revoked certificate object. In this example, getRevokedCert() is used to obtain the revoked certificate instance.
    let serialNumber = 1000;
    let crlEntry = null;
    try {
        crlEntry = x509Crl.getRevokedCert(serialNumber);
    } catch (error) {
        console.log("getRevokedCert failed, errCode: " + error.code + ", errMsg: " + error.message);
    }

    // Obtain the serial number of the revoked certificate.
    serialNumber = crlEntry.getSerialNumber();
    
    // Obtain the revocation date of the revoked certificate.
    try {
        crlEntry.getRevocationDate();
    } catch (error) {
        console.log("getRevocationDate failed, errCode: " + error.code + ", errMsg: " + error.message);
    }

    // Obtain the serialized data of the revoked certificate instance.
    crlEntry.getEncoded(function (err, data) {
        if (err != null) {
            // Failed to obtain the serialized data of the certificate.
            console.log("getEncoded failed, errCode: " + err.code + ", errMsg: " + err.message);
        } else {
            // The serialized data of the certificate is successfully obtained.
            console.log("getEncoded success");
        }
    });
}
```