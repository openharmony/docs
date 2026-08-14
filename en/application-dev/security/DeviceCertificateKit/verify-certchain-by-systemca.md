# Using the Prebuilt CA Certificate to Validate a Certificate Chain

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=586ca0df7c9e6070a6064e9c1b3f797ce18bcafe translatedAt=2026-08-11T02:02:10.690Z pushedAt=2026-08-11T07:57:07.898Z -->

Starting from API version 20, the system prebuilt CA certificate is supported for verifying certificate chains.

To do so, you need to create a certificate chain object first.

## How to Develop

1. Import the [certificate module](../../reference/apis-device-certificate-kit/js-apis-cert.md).

   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   ```

2. Based on the existing certificate data, call [cert.createX509CertChain](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509certchain11) to create an X.509 certificate chain object and return the result.

3. Call [x509CertChain.validate](../../reference/apis-device-certificate-kit/js-apis-cert.md#validate11) to set **trustSystemCa** to **true** and use the prebuilt CA certificate to validate the certificate chain and return the result.

<!-- @[verify-certchain-by-systemca](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/DeviceCertificateKit/CertificateAlgorithmLibrary/entry/src/main/ets/pages/VerifyCertchainBySystemca.ets) -->

``` TypeScript

import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';
// ...
async function sample() {
  let textEncoder = new util.TextEncoder();
  // Binary data of the certificate chain, which needs to be assigned by the service.
  const encodingBlob: cert.EncodingBlob = {
    data: textEncoder.encodeInto(certChainData),
    // Assign a value based on the encodingData format. FORMAT_PEM, FORMAT_DER, and FORMAT_PKCS7 are supported.
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };
  let x509CertChain: cert.X509CertChain = {} as cert.X509CertChain;
  try {
    x509CertChain = await cert.createX509CertChain(encodingBlob);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error(`createX509CertChain failed, errCode: ${e.code}, errMsg: ${e.message}`);
  }

  // Certificate chain verification data, which needs to be assigned by the service.
  const param: cert.CertChainValidationParameters = {
    date: '20250623163000Z',
    trustAnchors: [{}],
    trustSystemCa: true,
  };
  try {
    const validationRes = await x509CertChain.validate(param);
    console.info('X509CertChain validate result: success.');
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error(`X509CertChain validate failed, errCode: ${e.code}, errMsg: ${e.message}`);
  }
}
```