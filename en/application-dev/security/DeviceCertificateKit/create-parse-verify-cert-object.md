# Certificate Development

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

This topic walks you through on how to create a certificate object, obtain information about the certificate, and check the validity period of the certificate.

## How to Develop

1. Import the [certFramework](../../reference/apis-device-certificate-kit/js-apis-cert.md) module.
   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   ```

2. Use [cert.createX509Cert](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509cert) to create an **X509Cert** object based on the existing X.509 certificate data.

3. Obtain certificate information.<br>
   Here is an example of obtaining the certificate version, certificate serial number, certificate issuer name, certificate subject name, and string-type data of the certificate object. For more field information, see [@ohos.security.cert (Certificate)](../../reference/apis-device-certificate-kit/js-apis-cert.md#x509cert).

4. Use [X509Cert.getPublicKey](../../reference/apis-device-certificate-kit/js-apis-cert.md#getpublickey) to obtain the public key in the certificate and use [X509Cert.verify](../../reference/apis-device-certificate-kit/js-apis-cert.md#verify) to verify the signature. In this example, a self-signed certificate is used. Therefore, the public key in the certificate is obtained. In your app experience, obtain the public key for signature verification based on actual situation.

5. Use [X509Cert.checkValidityWithDate](../../reference/apis-device-certificate-kit/js-apis-cert.md#checkvaliditywithdate) to check the certificate validity period. The input parameter **date** is used to check whether the specified date is within the validity period of the X.509 certificate.

```ts
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
    // Convert the certificate data from a string to a Unit8Array.
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
    console.log('createX509Cert success');

    // Obtain the certificate version.
    let version = x509Cert.getVersion();
    // Obtain the certificate serial number.
    let serial = x509Cert.getCertSerialNumber();
    console.log(`X509 version: ${version} , X509 serial:${serial}`);

    // Obtain the certificate issuer name.
    let issuerName = x509Cert.getIssuerName(cert.EncodingType.ENCODING_UTF8);
    console.log(`X509 issuerName: ${issuerName}`);

    // Obtain the certificate subject name.
    let subjectNameBin = x509Cert.getSubjectName(cert.EncodingType.ENCODING_UTF8);
    let encoder = util.TextDecoder.create();
    let subjectName = encoder.decodeToString(subjectNameBin.data);
    console.log(`X509 subjectName: ${subjectName}`);

    // Obtain the string-type data of the certificate object.
    let certString = x509Cert.toString(cert.EncodingType.ENCODING_UTF8);
    console.log(`X509 certString: ${certString}`);

    // Use the getPublicKey() method of the upper-level certificate object or the self-signed certificate object to obtain the public key object.
    try {
      let pubKey = x509Cert.getPublicKey();
      // Verify the certificate signature.
      x509Cert.verify(pubKey, (err, data) => {
        if (err == null) {
          // Signature verification is successful.
          console.log('verify success');
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
