# Certificate Development

> **NOTE**
>
> The SDK of API version 9 or later must be used.

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

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Certificate data, which is only an example. The certificate data varies with the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBLzCB1QIUO/QDVJwZLIpeJyPjyTvE43xvE5cwCgYIKoZIzj0EAwIwGjEYMBYG\n' +
  'A1UEAwwPRXhhbXBsZSBSb290IENBMB4XDTIzMDkwNDExMjAxOVoXDTI2MDUzMDEx\n' +
  'MjAxOVowGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYI\n' +
  'KoZIzj0DAQcDQgAEHjG74yMIueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTa\n' +
  'tUsU0i/sePnrKglj2H8Abbx9PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEA\n' +
  '0ce/fvA4tckNZeB865aOApKXKlBjiRlaiuq5mEEqvNACIQDPD9WyC21MXqPBuRUf\n' +
  'BetUokslUfjT6+s/X4ByaxycAA==\n' +
  '-----END CERTIFICATE-----\n';

// Convert the certificate data form a string to a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate example
function certSample(): void {
  let encodingBlob: certFramework.EncodingBlob = {
    // Convert the certificate data string to a Uint8Array.
    data: stringToUint8Array(certData),
    // Certificate format. Only PEM and DER are supported. In this example, the certificate is in PEM format.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  // Create an X509Cert instance.
  certFramework.createX509Cert(encodingBlob, (err, x509Cert) => {
    if (err != null) {
      // Failed to create the X509Cert instance.
      console.error('createX509Cert failed, errCode: ' + err.code + ', errMsg: ' + err.message);
      return;
    }
    // The X509Cert instance is successfully created.
    console.log('createX509Cert success');

    // Obtain the certificate version.
    let version = x509Cert.getVersion();

    // Obtain the serialized data of the certificate.
    x509Cert.getEncoded((err, data) => {
      if (err != null) {
        // Failed to obtain the serialized data of the certificate.
        console.error('getEncoded failed, errCode: ' + err.code + ', errMsg: ' + err.message);
      } else {
        // The serialized data of the certificate is successfully obtained.
        console.log('getEncoded success');
      }
    });

    // Obtain the public key object using the getPublicKey() of the upper-level certificate object or this (self-signed) certificate object.
    try {
      let pubKey = x509Cert.getPublicKey();

      // Verify the certificate signature.
      x509Cert.verify(pubKey, (err, data) => {
        if (err == null) {
          // The signature verification is successful.
          console.log('verify success');
        } else {
          // The signature verification failed.
          console.error('verify failed, errCode: ' + err.code + ', errMsg: ' + err.message);
        }
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getPublicKey failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }


    // Time represented in a string.
    let date = '20230930000001Z';

    // Verify the certificate validity period.
    try {
      x509Cert.checkValidityWithDate(date);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('checkValidityWithDate failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  });
}
```

## Operating Certificate Extensions

> **NOTE**
>
> API version 10 and SDK version 4.0.9 or later must be used.

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

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

// Certificate extension data, which is only an example. Set it based on service requirements.
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

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate extension example.
function certExtensionSample(): void {
  let encodingBlob: certFramework.EncodingBlob = {
    data: extData,
    // Certificate extension format. Currently, only the DER format is supported.
    encodingFormat: certFramework.EncodingFormat.FORMAT_DER
  };

  // Create a CerExtension instance.
  certFramework.createCertExtension(encodingBlob, (err, certExtension) => {
    if (err != null) {
      // The CerExtension instance fails to be created.
      console.error('createCertExtension failed, errCode: ' + err.code + ', errMsg: ' + err.message);
      return;
    }
    // A CerExtension instance is created.
    console.log('createCertExtension success');

    try {
      // Obtain the serialized data of the CerExtension instance.
      let encodedData = certExtension.getEncoded();

      // Obtain the OIDs of the certificate extensions.
      let oidList = certExtension.getOidList(certFramework.ExtensionOidType.EXTENSION_OID_TYPE_ALL);

      // Obtain the certificate extension information based on a OID.
      let oidData = '2.5.29.14';
      let oid: certFramework.DataBlob = {
        data: stringToUint8Array(oidData),
      }
      let entry = certExtension.getEntry(certFramework.ExtensionEntryType.EXTENSION_ENTRY_TYPE_ENTRY, oid);

      // Check whether the certificate is a CA certificate.
      let pathLen = certExtension.checkCA();
      console.log('test cert extension success');
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error('operation failed, message: ' + e.message + ' code: ' + e.code);
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

```ts
import certFramework from '@ohos.security.cert';
import cryptoFramework from '@ohos.security.cryptoFramework';
import { BusinessError } from '@ohos.base';

// CRL data, which is only an example. The CRL data varies with the service.
let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'


let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBLzCB1QIUO/QDVJwZLIpeJyPjyTvE43xvE5cwCgYIKoZIzj0EAwIwGjEYMBYG\n' +
  'A1UEAwwPRXhhbXBsZSBSb290IENBMB4XDTIzMDkwNDExMjAxOVoXDTI2MDUzMDEx\n' +
  'MjAxOVowGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYI\n' +
  'KoZIzj0DAQcDQgAEHjG74yMIueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTa\n' +
  'tUsU0i/sePnrKglj2H8Abbx9PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEA\n' +
  '0ce/fvA4tckNZeB865aOApKXKlBjiRlaiuq5mEEqvNACIQDPD9WyC21MXqPBuRUf\n' +
  'BetUokslUfjT6+s/X4ByaxycAA==\n' +
  '-----END CERTIFICATE-----\n';

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

// Convert the certificate data form a string to a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Example of a CRL.
function crlSample(): void {
  let encodingBlob: certFramework.EncodingBlob = {
    // Convert the CRL data from a string to a Uint8Array.
    data: stringToUint8Array(crlData),
    // CRL format. Only PEM and DER are supported. In this example, the CRL is in PEM format.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  // Create an X509Crl instance.
  certFramework.createX509Crl(encodingBlob, (err, x509Crl) => {
    if (err != null) {
      // Failed to create the X509Crl instance.
      console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
      return;
    }
    // The X509Crl instance is successfully created.
    console.log('createX509Crl success');

    // Obtain the CRL version.
    let version = x509Crl.getVersion();

    // Obtain the serialized data of the CRL.
    x509Crl.getEncoded((err, data) => {
      if (err != null) {
        // Failed to obtain the serialized data of the certificate.
        console.error('getEncoded failed, errCode: ' + err.code + ', errMsg: ' + err.message);
      } else {
        // The serialized data of the certificate is successfully obtained.
        console.log('getEncoded success');
      }
    });

    // Create an X509Cert instance by using createX509Cert() of certFramework.
    let certBlob: certFramework.EncodingBlob = {
      data: stringToUint8Array(certData),
      encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
    };
    certFramework.createX509Cert(certBlob, (err, cert) => {
      if (err == null) {
        try {
          // Check whether the certificate is revoked.
          let revokedFlag = x509Crl.isRevoked(cert);
          console.log('revokedFlag is: ' + revokedFlag);
        } catch (error) {
          let e: BusinessError = error as BusinessError;
          console.error('isRevoked failed, errCode: ' + e.code + ', errMsg: ' + e.message);
        }
      } else {
        console.error('create x509 cert failed errCode: ' + err.code + ', errMsg: ' + err.message);
      }
    })

    // The binary data of the public key needs to be passed to convertKey() of @ohos.security.cryptoFramework to obtain the PubKey object. The process is omitted here.
    try {
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
              // The signature verification is successful.
              console.log('verify success');
            } else {
              // The signature verification failed.
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

    // Certificate serial number, which must be set based on the service.
    let serialNumber = 1000;

    // Obtain the revoked certificate based on the serial number.
    try {
      let entry = x509Crl.getRevokedCert(serialNumber);
      console.log('get getRevokedCert success');
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
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

```ts
import certFramework from '@ohos.security.cert';

// CA certificate data, which is only an example. The CA certificate data varies with the service.
let caCertData = '-----BEGIN CERTIFICATE-----\n' +
  '...\n' +
  '...\n' +
  '...\n' +
  '-----END CERTIFICATE-----\n';

// End-entity certificate data, which is only an example. The certificate data varies with the service.
let secondCaCertData = '-----BEGIN CERTIFICATE-----\n' +
  '...\n' +
  '...\n' +
  '...\n' +
  '-----END CERTIFICATE-----\n';

// Convert the certificate data form a string to a Uint8Array..
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Certificate chain validator example. In this example, a two-level certificate chain is verified.
function certChainValidatorSample(): void {
  // Certificate chain validator algorithm. Currently, only PKIX is supported.
  let algorithm = 'PKIX';

  // Create a CertChainValidator instance.
  let validator = certFramework.createCertChainValidator(algorithm);

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
  for (let i = 0; i < uint8ArrayOf2ndCaCertDataLen.length; i++) {
    encodingData[i] = uint8ArrayOf2ndCaCertDataLen[i];
  }
  for (let i = 0; i < uint8ArrayOf2ndCaCertData.length; i++) {
    encodingData[uint8ArrayOf2ndCaCertDataLen.length + i] = uint8ArrayOf2ndCaCertData[i];
  }
  for (let i = 0; i < uint8ArrayOfCaCertDataLen.length; i++) {
    encodingData[uint8ArrayOf2ndCaCertDataLen.length + uint8ArrayOf2ndCaCertData.length + i] = uint8ArrayOfCaCertDataLen[i];
  }
  for (let i = 0; i < uint8ArrayOfCaCertData.length; i++) {
    encodingData[uint8ArrayOf2ndCaCertDataLen.length + uint8ArrayOf2ndCaCertData.length +
    uint8ArrayOfCaCertDataLen.length + i] = uint8ArrayOfCaCertData[i];
  }

  let certChainData: certFramework.CertChainData = {
    // Uint8Array type: L-V format (certificate data length-certificate data)
    data: encodingData,
    // Number of certificates. It is 2 in this example.
    count: 2,
    // Certificate format. Only PEM and DER are supported. In this example, the certificate is in PEM format.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  // Verify the certificate chain.
  validator.validate(certChainData, (err, data) => {
    if (err != null) {
      // The operation fails.
      console.error('validate failed, errCode: ' + err.code + ', errMsg: ' + err.message);
    } else {
      // The operation is successful.
      console.log('validate success');
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

```ts
import certFramework from '@ohos.security.cert';
import { BusinessError } from '@ohos.base';

let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIHzMF4CAQMwDQYJKoZIhvcNAQEEBQAwFTETMBEGA1UEAxMKQ1JMIGlzc3VlchcN\n' +
  'MTcwODA3MTExOTU1WhcNMzIxMjE0MDA1MzIwWjAVMBMCAgPoFw0zMjEyMTQwMDUz\n' +
  'MjBaMA0GCSqGSIb3DQEBBAUAA4GBACEPHhlaCTWA42ykeaOyR0SGQIHIOUR3gcDH\n' +
  'J1LaNwiL+gDxI9rMQmlhsUGJmPIPdRs9uYyI+f854lsWYisD2PUEpn3DbEvzwYeQ\n' +
  '5SqQoPDoM+YfZZa23hoTLsu52toXobP74sf/9K501p/+8hm4ROMLBoRT86GQKY6g\n' +
  'eavsH0Q3\n' +
  '-----END X509 CRL-----\n'

// Convert the certificate data form a string to a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: Array<number> = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Example of a revoked certificate.
function crlEntrySample(): void {
  // Create an **X509Crl** instance by using createX509Crl() of certFramework.
  let encodingBlob: certFramework.EncodingBlob = {
    // Convert the CRL data from a string to a Uint8Array.
    data: stringToUint8Array(crlData),
    // CRL format. Only PEM and DER are supported. In this example, the CRL is in PEM format.
    encodingFormat: certFramework.EncodingFormat.FORMAT_PEM
  };

  // Create an X509Crl instance.
  certFramework.createX509Crl(encodingBlob, (err, x509Crl) => {
    if (err != null) {
      // Failed to create the X509Crl instance.
      console.error('createX509Crl failed, errCode: ' + err.code + ', errMsg: ' + err.message);
      return;
    }
    console.log('create x509 crl success');

    // Obtain a revoked certificate instance. In this example, the instance is obtained by using getRevokedCert().
    try {
      let serialNumber = 1000;
      let crlEntry = x509Crl.getRevokedCert(serialNumber);

      // Obtain the serial number of the revoked certificate.
      serialNumber = crlEntry.getSerialNumber();
      console.log('serialNumber is: ', serialNumber);

      // Obtain the revocation date of the revoked certificate.
      let date = crlEntry.getRevocationDate();
      console.log('revocation date is: ', date);

      // Obtain the serialized data of the revoked certificate instance.
      crlEntry.getEncoded((err, data) => {
        if (err != null) {
          // Failed to obtain the serialized data of the certificate.
          console.error('getEncoded failed, errCode: ' + err.code + ', errMsg: ' + err.message);
        } else {
          // The serialized data of the certificate is successfully obtained.
          console.log('getEncoded success');
        }
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error('getRevokedCert failed, errCode: ' + e.code + ', errMsg: ' + e.message);
    }
  })
}
```