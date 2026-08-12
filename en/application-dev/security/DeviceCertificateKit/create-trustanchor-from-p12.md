# Creating a TrustAnchor Object Array from a PKCS #12 File

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=78d27a16851062ae03d6a51de8b99e33aec772a0 translatedAt=2026-08-11T02:01:12.490Z pushedAt=2026-08-11T07:45:43.529Z -->

Construct a **TrustAnchor** object array from a PKCS #12 file during certificate chain validation.

## How to Develop

1. Import the [certificate module](../../reference/apis-device-certificate-kit/js-apis-cert.md).

2. Based on the existing PKCS #12 file data, use [cert.createTrustAnchorsWithKeyStore](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatetrustanchorswithkeystore12) to create an [X509TrustAnchor](../../reference/apis-device-certificate-kit/js-apis-cert.md#x509trustanchor11) object array and return the result.

<!-- @[trust_array_constructed_from_p12_file_during_validation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/DeviceCertificateKit/CertificateAlgorithmLibrary/entry/src/main/ets/pages/CreateTrustanchorFromP12.ets) -->

``` TypeScript
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

function test() {
  // ...
  try {
    cert.createTrustAnchorsWithKeyStore(p12Data, '123456').then((data) => {
      console.info('createTrustAnchorsWithKeyStore result: success, the num of result is :' + data.length);
    }).catch((err: BusinessError) => {
      console.error(`createTrustAnchorsWithKeyStore failed, errCode: ${err.code}, message: ${err.message}`);
    })
  } catch (error) {
    console.error(`createTrustAnchorsWithKeyStore failed, errCode: ${error.code}, message: ${error.message}`);
  }
}
```