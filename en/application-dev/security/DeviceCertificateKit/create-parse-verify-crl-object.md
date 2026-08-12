# CRL Development

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=586ca0df7c9e6070a6064e9c1b3f797ce18bcafe translatedAt=2026-08-11T02:01:13.312Z pushedAt=2026-08-11T07:43:31.128Z -->

This topic walks you through on how to create a certificate revocation list (CRL) instance, obtain CRL information, check whether a certificate has been revoked, and print the revocation date if the certificate has been revoked.

## How to Develop

1. Import the [certificate module](../../reference/apis-device-certificate-kit/js-apis-cert.md) and the [crypto framework](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md).

   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   import { cryptoFramework } from '@kit.CryptoArchitectureKit';
   ```

2. Based on existing CRL data, call [cert.createX509CRL](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509crl11) to create an X.509 CRL object.

3. Parse CRL information.

   This example demonstrates how to obtain the CRL version, CRL type, CRL issuer name, and string-type data of the CRL object. For more field retrieval APIs, see the API reference [X509CRL11+](../../reference/apis-device-certificate-kit/js-apis-cert.md#x509crl11).

4. Create a **PublicKey** instance based on the existing public key.

   For details, see Crypto Architecture Kit - Generating an Asymmetric Key Pair from Binary Data [convertKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-3).

5. Use [X509CRL.verify](../../reference/apis-device-certificate-kit/js-apis-cert.md#verify11) to verify the signature.

6. Based on existing X.509 certificate data, call [cert.createX509Cert](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509cert) to create a certificate object.

7. Call [X509CRL.isRevoked](../../reference/apis-device-certificate-kit/js-apis-cert.md#isrevoked11) to check whether the X.509 certificate has been revoked.

8. Use [X509CRL.getRevokedCert](../../reference/apis-device-certificate-kit/js-apis-cert.md#getrevokedcert11) to obtain the revoked certificate.

9.  Use [X509CRLEntry.getRevocationDate](../../reference/apis-device-certificate-kit/js-apis-cert.md#getrevocationdate11) to obtain the date when the certificate was revoked.

<!-- @[create_parse_verify_certificate_revocation_list_objects](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/DeviceCertificateKit/CertificateAlgorithmLibrary/entry/src/main/ets/pages/CreateParseVerifyCrlObject.ets) -->

``` TypeScript


import { cert } from '@kit.DeviceCertificateKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

// ...
// CRL example.
function crlSample(): void {
  let textEncoder = new util.TextEncoder();
  let encodingBlob: cert.EncodingBlob = {
    // Convert the CRL data from a string to a Uint8Array.
    data: textEncoder.encodeInto(crlData),
    // CRL format. Only the PEM and DER formats are supported. In this example, the CRL is in PEM format.
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

  // Create an X509CRL instance.
  cert.createX509CRL(encodingBlob, (err, x509Crl) => {
    if (err != null) {
      // The X509CRL instance fails to be created.
      console.error(`createX509Crl failed, errCode: ${err.code}, errMsg:${err.message} `);
      return;
    }
    // The X509CRL instance is successfully created.
    console.info('createX509CRL result: success.');

    // Obtain the CRL version.
    let version = x509Crl.getVersion();
    // Obtain the CRL type.
    let revokedType = x509Crl.getType();
    console.info(`X509 CRL version: ${version}, type :${revokedType}`);

    // Obtain the CRL issuer name.
    let issuerName = x509Crl.getIssuerName(cert.EncodingType.ENCODING_UTF8);
    console.info(`X509 CRL issuerName: ${issuerName}`);

    // Obtain the string-type data of the CRL object.
    let crlString = x509Crl.toString(cert.EncodingType.ENCODING_UTF8);
    console.info(`X509 CRL crlString: ${crlString}`);


    // Pass in the public key binary data to convertKey() of @ohos.security.cryptoFramework to obtain a public key instance.
    try {
      let keyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_3');
      console.info('createAsyKeyGenerator result: success.');
      let pubEncodingBlob: cryptoFramework.DataBlob = {
        data: pubKeyData,
      };
      keyGenerator.convertKey(pubEncodingBlob, null, (e, keyPair) => {
        if (e == null) {
          console.info('convertKey result: success.');
          x509Crl.verify(keyPair.pubKey, (err, data) => {
            if (err == null) {
              // Signature verification is successful.
              console.info('verify result: success.');
            } else {
              // Signature verification fails.
              console.error(`verify failed, errCode: ${err.code}, errMsg: ${err.message}`);
            }
          });
        } else {
          console.error(`convert key failed, errCode: ${e.code}, errMsg: ${e.message}`);
        }
      })
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error(`get pubKey failed, errCode: ${e.code}, errMsg: ${e.message}`);
    }

    // Use createX509Cert() of certFramework to create an X509Cert instance.
    let certBlob: cert.EncodingBlob = {
      data: textEncoder.encodeInto(certData),
      encodingFormat: cert.EncodingFormat.FORMAT_PEM
    };
    let revokedFlag = true;
    let serial: bigint = BigInt('0');
    cert.createX509Cert(certBlob, (err, x509Cert) => {
      serial = x509Cert.getCertSerialNumber();
      if (err == null) {
        try {
          // Check whether the certificate has been revoked.
          revokedFlag = x509Crl.isRevoked(x509Cert);
          console.info(`revokedFlag is: ${revokedFlag}`);
          if (!revokedFlag) {
            console.info('the given x509Cert is not revoked.');
            return;
          }
          // Obtain the revoked certificate based on the serial number.
          try {
            let crlEntry = x509Crl.getRevokedCert(serial);
            console.info('getRevokedCert result: success.');
            let serialNumber = crlEntry.getSerialNumber();
            console.info(`crlEntry serialNumber is: ${serialNumber}`);

            // Obtain the revocation date of the certificate.
            let date = crlEntry.getRevocationDate();
            console.info(`revocation date is: ${date}`);
          } catch (error) {
            let e: BusinessError = error as BusinessError;
            console.error(`getRevokedCert failed, errCode: ${e.code}, errMsg: ${e.message}`);
          }
        } catch (error) {
          let e: BusinessError = error as BusinessError;
          console.error(`isRevoked failed, errCode: ${e.code}, errMsg:${e.message}`);
        }
      } else {
        console.error(`create x509 cert failed, errCode: ${err.code}, errMsg: ${err.message}`);
      }
    })

  });
}
```