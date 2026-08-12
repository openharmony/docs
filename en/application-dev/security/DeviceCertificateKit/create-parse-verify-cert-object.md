# Certificate Development

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=78d27a16851062ae03d6a51de8b99e33aec772a0 translatedAt=2026-08-11T02:01:29.458Z pushedAt=2026-08-11T07:42:28.559Z -->

This topic walks you through on how to create a certificate object, obtain information about the certificate, and check the validity period of the certificate.

## How to Develop

1. Import the [certificate module](../../reference/apis-device-certificate-kit/js-apis-cert.md).

   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   ```

2. Based on existing X.509 certificate data, call [cert.createX509Cert](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509cert) to create a certificate object.

3. Obtain certificate information.<br>

   Here, obtaining the certificate version, serial number, issuer name, certificate subject name, and string-type data of the certificate object is used as an example. For more field information retrieval APIs, see the API reference document [X509Cert](../../reference/apis-device-certificate-kit/js-apis-cert.md#x509cert).

4. Use [X509Cert.getPublicKey](../../reference/apis-device-certificate-kit/js-apis-cert.md#getpublickey) to obtain the public key in the certificate and use [X509Cert.verify](../../reference/apis-device-certificate-kit/js-apis-cert.md#verify) to verify the signature. In this example, a self-signed certificate is used. Therefore, the public key in the certificate is obtained. Your app needs to obtain the public key for signature verification based on actual situation.

5. Call [X509Cert.checkValidityWithDate](../../reference/apis-device-certificate-kit/js-apis-cert.md#checkvaliditywithdate) to verify the certificate validity period. The input parameter date is used to confirm whether this date falls within the validity period of the X.509 certificate.

<!-- @[certificate_object_creation_resolution_validation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/DeviceCertificateKit/CertificateAlgorithmLibrary/entry/src/main/ets/pages/CreateParseVerifyCertObject.ets) -->

``` TypeScript

import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

// The following is an example of the certificate binary data, which varies with the service.
let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIBLzCB1QIUO/QDVJwZLIpeJyPjyTvE43xvE5cwCgYIKoZIzj0EAwIwGjEYMBYG\n' +
  'A1UEAwwPRXhhbXBsZSBSb290IENBMB4XDTIzMDkwNDExMjAxOVoXDTI2MDUzMDEx\n' +
  'MjAxOVowGjEYMBYGA1UEAwwPRXhhbXBsZSBSb290IENBMFkwEwYHKoZIzj0CAQYI\n' +
  'KoZIzj0DAQcDQgAEHjG74yMIueO7z3T+dyuEIrhxTg2fqgeNB3SGfsIXlsiUfLTa\n' +
  'tUsU0i/sePnrKglj2H8Abbx9PK0tsW/VgqwDIDAKBggqhkjOPQQDAgNJADBGAiEA\n' +
  '0ce/fvA4tckNZeB865aOApKXKlBjiRlaiuq5mEEqvNACIQDPD9WyC21MXqPBuRUf\n' +
  'BetUokslUfjT6+s/X4ByaxycAA==\n' +
  '-----END CERTIFICATE-----\n';

// Certificate example.
function certSample(): void {
  let textEncoder = new util.TextEncoder();
  let encodingBlob: cert.EncodingBlob = {
    // Convert the certificate data from a string to a Uint8Array.
    data: textEncoder.encodeInto(certData),
    // Certificate format. Only PEM and DER are supported. In this example, the certificate is in PEM format.
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

  // Create an X509Cert object.
  cert.createX509Cert(encodingBlob, (err, x509Cert) => {
    if (err != null) {
      // The X509Cert object fails to be created.
      console.error(`createX509Cert failed, errCode:${err.code}, errMsg:${err.message}`);
      return;
    }
    // The X509Cert object is created.
    console.info('createX509Cert result: success.');

    // Obtain the certificate version.
    let version = x509Cert.getVersion();
    // Obtain the certificate serial number.
    let serial = x509Cert.getCertSerialNumber();
    console.info(`X509 version: ${version} , X509 serial:${serial}`);

    // Obtain the certificate issuer name.
    let issuerName = x509Cert.getIssuerName(cert.EncodingType.ENCODING_UTF8);
    console.info(`X509 issuerName: ${issuerName}`);

    // Obtain the certificate subject name.
    let subjectNameBin = x509Cert.getSubjectName(cert.EncodingType.ENCODING_UTF8);
    let encoder = util.TextDecoder.create();
    let subjectName = encoder.decodeToString(subjectNameBin.data);
    console.info(`X509 subjectName: ${subjectName}`);

    // Obtain the string-type data of the certificate object.
    let certString = x509Cert.toString(cert.EncodingType.ENCODING_UTF8);
    console.info(`X509 certString: ${certString}`);

    // Use the getPublicKey() method of the upper-level certificate object or the self-signed certificate object to obtain the public key object.
    try {
      let pubKey = x509Cert.getPublicKey();
      // Verify the certificate signature.
      x509Cert.verify(pubKey, (err, data) => {
        if (err == null) {
          // Signature verification is successful.
          console.info('verify result: success.');
        } else {
          // Signature verification fails.
          console.error(`verify failed, errCode: ${err.code} , errMsg:${err.message}`);
        }
      });
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error(`getPublicKey failed, errCode: ${e.code} , errMsg:${e.message}`);
    }

    // Use a string to represent the date.
    let date = '20230930000001Z';

    // Check the validity period of the certificate.
    try {
      x509Cert.checkValidityWithDate(date);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error(`checkValidityWithDate failed, errCode: ${e.code}, errMsg:${e.message}`);
    }
  });
}
```