# CRL Development

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

This topic walks you through on how to create a certificate revocation list (CRL) instance, obtain CRL information, check whether a certificate has been revoked, and print the revocation date if the certificate has been revoked.

## How to Develop

1. Import the [certFramework](../../reference/apis-device-certificate-kit/js-apis-cert.md) and [cryptoFramework](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md) modules.
   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   import { cryptoFramework } from '@kit.CryptoArchitectureKit';
   ```

2. Use [cert.createX509CRL](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509crl11) to create an X.509 CRL instance.

3. Obtain CRL information.

   Here is an example of obtaining the CRL version, CRL type, CRL issuer name, and string-type data of the CRL object. For more field information, see [@ohos.security.cert (Certificate)](../../reference/apis-device-certificate-kit/js-apis-cert.md#x509crl11).

4. Create a **PublicKey** instance.

   For details, see [convertKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-3).

5. Use [X509CRL.verify](../../reference/apis-device-certificate-kit/js-apis-cert.md#verify11) to verify the signature.

6. Use [cert.createX509Cert](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509cert) to create an **X509Cert** object based on the existing X.509 certificate data.

7. Use [X509CRL.isRevoked](../../reference/apis-device-certificate-kit/js-apis-cert.md#isrevoked11) to check whether the X.509 certificate has been revoked.

8. Use [X509CRL.getRevokedCert](../../reference/apis-device-certificate-kit/js-apis-cert.md#getrevokedcert11) to obtain the revoked certificate.

9.  Use [X509CRLEntry.getRevocationDate](../../reference/apis-device-certificate-kit/js-apis-cert.md#getrevocationdate11) to obtain the date when the certificate was revoked.

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

// CRL data, which is only an example.
let crlData = '-----BEGIN X509 CRL-----\n' +
  'MIIByzCBtAIBATANBgkqhkiG9w0BAQsFADBXMQswCQYDVQQGEwJDTjEPMA0GA1UE\n' +
  'CAwG6ZmV6KW/MQ8wDQYDVQQHDAbopb/lrokxDzANBgNVBAoMBua1i+ivlTEVMBMG\n' +
  'A1UEAwwM5Lit5paH5rWL6K+VFw0yNTAyMjAwNjEzMTZaFw0yNTAzMjIwNjEzMTZa\n' +
  'MBkwFwIGAXKnJjrAFw0yNTAyMjAwNjEzMDNaoA4wDDAKBgNVHRQEAwIBADANBgkq\n' +
  'hkiG9w0BAQsFAAOCAQEAt9AZ/B5FQiXnKKBGocKmM5QKeky/3etcI+cAVyD0zfjI\n' +
  'r1UrL1aF+49LdZps3zQRqm4RQmo9CwL+KsMZiIMSeWF5Q6LW7BQa08hx5PtdjoOu\n' +
  '1IWVKAwR5IigpaOwMKRTq1xJ372EiUkDD83AsxEkQoQW0bBvFklGrzglSACeKST+\n' +
  'Pn6ywwFyYj34cfRuz3ueqwHRmN/mGzQdet7Ns8JBGWutDzfJsAiPC/TIaafTOocO\n' +
  'CHo81Q2rMcqAJj5uXyc1Gq8KfOEqsxo/oDwReghjwrUedJ+9l/cQBr0F8HPV4H8W\n' +
  '49sYMpseywjp9lxjWt/2nrx1z2yMaivGrVhoFasZvQ==\n' +
  '-----END X509 CRL-----\n'

let certData = '-----BEGIN CERTIFICATE-----\n' +
  'MIIDgTCCAmmgAwIBAgIGAXKnJjrAMA0GCSqGSIb3DQEBCwUAMFcxCzAJBgNVBAYT\n' +
  'AkNOMQ8wDQYDVQQIDAbpmZXopb8xDzANBgNVBAcMBuilv+WuiTEPMA0GA1UECgwG\n' +
  '5rWL6K+VMRUwEwYDVQQDDAzkuK3mlofmtYvor5UwHhcNMjUwMjIwMDYwOTUyWhcN\n' +
  'MzUwMjE4MDYwOTUyWjBXMQswCQYDVQQGEwJDTjEPMA0GA1UECAwG6ZmV6KW/MQ8w\n' +
  'DQYDVQQHDAbopb/lrokxDzANBgNVBAoMBua1i+ivlTEVMBMGA1UEAwwM5Lit5paH\n' +
  '5rWL6K+VMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA2DQpPYN7cJjQ\n' +
  'LWLlkP5dD8J/g1xx97t2bFciUOru14IBm9EeX6qkohDSl6kQHwfVSqTfcqdIn9We\n' +
  '73FiitfDjHc9xxbvBKbCYicCzS/eNl0W9q14FiEB8M9vz4dpKK00KZBcGc1QK2m+\n' +
  '/N6zw4Tw4wXZ97v6/M+bhY5X0b3qEJlgQNyz7dD0wF7SCuzLL9zbr403KktHMG5Y\n' +
  'MzyOBaGOaMuVQFlXMV/E5OWfqbM7n0Pu/cGj+AfkkziWxB+5WFCRP6Pw64LJGo+e\n' +
  'uZHgHp07kk6+a2YNnFMcdTsOIWBSpCvC3I612NjpBirn2bFRWqTD++YAuvJQagmM\n' +
  '+VhIjXD48wIDAQABo1MwUTAdBgNVHQ4EFgQUIN7ulBn89L5HXh9m9JM7rpkvlXUw\n' +
  'HwYDVR0jBBgwFoAUIN7ulBn89L5HXh9m9JM7rpkvlXUwDwYDVR0TAQH/BAUwAwEB\n' +
  '/zANBgkqhkiG9w0BAQsFAAOCAQEAxWNa3LSOR3QOJ+wE1Y/q5zzEPWmWR5OMrRJK\n' +
  'juBHhYbzsg3r74fBO3Hw8XggEpHr6SOI1rBpZhciA8D9E8RnM1aJLY53rpBDY5OV\n' +
  'wxTFzrjdwIknt13t6ILfGeLye5OAF0S8VPdfDqP9NddNNr/WFKpd3tKoBlG0ObMa\n' +
  'LaQvOqObz0MJrjKsyI680nJjFLjLZ6+lEDSg4rsGU+bxEkONerStAPNcN2x9z7O6\n' +
  'YJOvhiLjWvr8VRjlMZYVmT9gqCImoo+7JaHbu8jz9mjRxD6fo9I1OvCLNFyFw2sV\n' +
  'iYID9UEbT6IWv/kKBdr7Te9+SY6AWxUxO8Hd7HdPKDOCrGrU9A==\n' +
  '-----END CERTIFICATE-----\n';

let pubKeyData = new Uint8Array([
  0x30, 0x82, 0x01, 0x22, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01,
  0x01, 0x05, 0x00, 0x03, 0x82, 0x01, 0x0f, 0x00, 0x30, 0x82, 0x01, 0x0a, 0x02, 0x82, 0x01, 0x01,
  0x00, 0xd8, 0x34, 0x29, 0x3d, 0x83, 0x7b, 0x70, 0x98, 0xd0, 0x2d, 0x62, 0xe5, 0x90, 0xfe, 0x5d,
  0x0f, 0xc2, 0x7f, 0x83, 0x5c, 0x71, 0xf7, 0xbb, 0x76, 0x6c, 0x57, 0x22, 0x50, 0xea, 0xee, 0xd7,
  0x82, 0x01, 0x9b, 0xd1, 0x1e, 0x5f, 0xaa, 0xa4, 0xa2, 0x10, 0xd2, 0x97, 0xa9, 0x10, 0x1f, 0x07,
  0xd5, 0x4a, 0xa4, 0xdf, 0x72, 0xa7, 0x48, 0x9f, 0xd5, 0x9e, 0xef, 0x71, 0x62, 0x8a, 0xd7, 0xc3,
  0x8c, 0x77, 0x3d, 0xc7, 0x16, 0xef, 0x04, 0xa6, 0xc2, 0x62, 0x27, 0x02, 0xcd, 0x2f, 0xde, 0x36,
  0x5d, 0x16, 0xf6, 0xad, 0x78, 0x16, 0x21, 0x01, 0xf0, 0xcf, 0x6f, 0xcf, 0x87, 0x69, 0x28, 0xad,
  0x34, 0x29, 0x90, 0x5c, 0x19, 0xcd, 0x50, 0x2b, 0x69, 0xbe, 0xfc, 0xde, 0xb3, 0xc3, 0x84, 0xf0,
  0xe3, 0x05, 0xd9, 0xf7, 0xbb, 0xfa, 0xfc, 0xcf, 0x9b, 0x85, 0x8e, 0x57, 0xd1, 0xbd, 0xea, 0x10,
  0x99, 0x60, 0x40, 0xdc, 0xb3, 0xed, 0xd0, 0xf4, 0xc0, 0x5e, 0xd2, 0x0a, 0xec, 0xcb, 0x2f, 0xdc,
  0xdb, 0xaf, 0x8d, 0x37, 0x2a, 0x4b, 0x47, 0x30, 0x6e, 0x58, 0x33, 0x3c, 0x8e, 0x05, 0xa1, 0x8e,
  0x68, 0xcb, 0x95, 0x40, 0x59, 0x57, 0x31, 0x5f, 0xc4, 0xe4, 0xe5, 0x9f, 0xa9, 0xb3, 0x3b, 0x9f,
  0x43, 0xee, 0xfd, 0xc1, 0xa3, 0xf8, 0x07, 0xe4, 0x93, 0x38, 0x96, 0xc4, 0x1f, 0xb9, 0x58, 0x50,
  0x91, 0x3f, 0xa3, 0xf0, 0xeb, 0x82, 0xc9, 0x1a, 0x8f, 0x9e, 0xb9, 0x91, 0xe0, 0x1e, 0x9d, 0x3b,
  0x92, 0x4e, 0xbe, 0x6b, 0x66, 0x0d, 0x9c, 0x53, 0x1c, 0x75, 0x3b, 0x0e, 0x21, 0x60, 0x52, 0xa4,
  0x2b, 0xc2, 0xdc, 0x8e, 0xb5, 0xd8, 0xd8, 0xe9, 0x06, 0x2a, 0xe7, 0xd9, 0xb1, 0x51, 0x5a, 0xa4,
  0xc3, 0xfb, 0xe6, 0x00, 0xba, 0xf2, 0x50, 0x6a, 0x09, 0x8c, 0xf9, 0x58, 0x48, 0x8d, 0x70, 0xf8,
  0xf3, 0x02, 0x03, 0x01, 0x00, 0x01
]);

// CRL example.
function crlSample(): void {
  let textEncoder = new util.TextEncoder();
  let encodingBlob: cert.EncodingBlob = {
    // Convert the CRL data from a string to a Unit8Array.
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
    console.log('createX509CRL success');

    // Obtain the CRL version.
    let version = x509Crl.getVersion();
    // Obtain the CRL type.
    let revokedType = x509Crl.getType();
    console.log(`X509 CRL version: ${version}, type :${revokedType}`);

    // Obtain the CRL issuer name.
    let issuerName = x509Crl.getIssuerName(cert.EncodingType.ENCODING_UTF8);
    console.log(`X509 CRL issuerName: ${issuerName}`);

    // Obtain the string-type data of the CRL object.
    let crlString = x509Crl.toString(cert.EncodingType.ENCODING_UTF8);
    console.log(`X509 CRL crlString: ${crlString}`);


    // Pass in the public key binary data to convertKey() of @ohos.security.cryptoFramework to obtain a public key instance.
    try {
      let keyGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_3');
      console.log('createAsyKeyGenerator success');
      let pubEncodingBlob: cryptoFramework.DataBlob = {
        data: pubKeyData,
      };
      keyGenerator.convertKey(pubEncodingBlob, null, (e, keyPair) => {
        if (e == null) {
          console.log('convert key success');
          x509Crl.verify(keyPair.pubKey, (err, data) => {
            if (err == null) {
              // Signature verification is successful.
              console.log('verify success');
            } else {
              // Signature verification fails.
              console.error(`verify failed, errCode: ${err.code}, errMsg: ${err.message}`);
            }
          });
        } else {
          console.error(`convert key failed, message: ${e.message}, code: ${e.code} `);
        }
      })
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error(`get pubKey failed, errCode: ${e.code}, errMsg: ${e.message}` );
    }

    // Use createX509Cert() of certFramework to create an X509Cert instance.
    let certBlob: cert.EncodingBlob = {
      data: textEncoder.encodeInto(certData),
      encodingFormat: cert.EncodingFormat.FORMAT_PEM
    };
    let revokedFlag = true;
    let serial:bigint = BigInt('0');
    cert.createX509Cert(certBlob, (err, cert) => {
      serial = cert.getCertSerialNumber();
      if (err == null) {
        try {
          // Check whether the certificate has been revoked.
          revokedFlag = x509Crl.isRevoked(cert);
          console.log(`revokedFlag is: ${revokedFlag}`);
          if (!revokedFlag) {
              console.log('the given cert is not revoked.');
              return;
          }
          // Obtain the revoked certificate based on the serial number.
          try {
            let crlEntry = x509Crl.getRevokedCert(serial);
            console.log('get getRevokedCert success');
            let serialNumber = crlEntry.getSerialNumber();
            console.log(`crlEntry serialNumber is: ${serialNumber}`);

            // Obtain the revocation date of the certificate.
            let date = crlEntry.getRevocationDate();
            console.log(`revocation date is: ${date}`);
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
