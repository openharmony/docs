# Certificate Extension Development

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=78d27a16851062ae03d6a51de8b99e33aec772a0 translatedAt=2026-08-11T02:00:46.590Z pushedAt=2026-08-11T07:42:35.722Z -->

This example demonstrates how to create, parse, and verify a certificate extension object by obtaining a specified Object Identifier (OID) field from a certificate and determining whether it is a CA (Certificate Authority) certificate.

## How to Develop

1. Import the [certificate module](../../reference/apis-device-certificate-kit/js-apis-cert.md).

   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   ```

2. Parse the certificate extension data and use [cert.createCertExtension](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatecertextension10) to create a **CertExtension** instance.

3. Use [CertExtension.getEntry](../../reference/apis-device-certificate-kit/js-apis-cert.md#getentry10) to obtain the certificate extension information for the specified OID. For example, obtain the OID list for certificate extension and obtain specific data based on an OID.

4. Use [CertExtension.checkCA](../../reference/apis-device-certificate-kit/js-apis-cert.md#checkca10) to check whether the certificate is a CA certificate.

<!-- @[create_parse_validate_certificate_extension_info_objects](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/DeviceCertificateKit/CertificateAlgorithmLibrary/entry/src/main/ets/pages/CreateParseVerifyCertextensionObject.ets) -->

``` TypeScript

import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

// Certificate extension data. The following is only an example. The value needs to be assigned based on the specific service.
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

// Certificate extension example.
function certExtensionSample(): void {
  let textEncoder = new util.TextEncoder();
  let encodingBlob: cert.EncodingBlob = {
    data: extData,
    // Certificate extension format. Currently, only the DER format is supported.
    encodingFormat: cert.EncodingFormat.FORMAT_DER
  };

  // Create a CertExtension object.
  cert.createCertExtension(encodingBlob, (err, certExtension) => {
    if (err != null) {
      // The CertExtension object fails to be created.
      console.error(`createCertExtension failed, errCode:${err.code}, errMsg:${err.message}`);
      return;
    }
    // The CertExtension object is created.
    console.info('createCertExtension result: success.');

    try {
      // Obtain the certificate extension information based on an OID.
      let oidData = '2.5.29.14';
      let oid: cert.DataBlob = {
        data: textEncoder.encodeInto(oidData),
      }
      let entry = certExtension.getEntry(cert.ExtensionEntryType.EXTENSION_ENTRY_TYPE_ENTRY, oid);

      // Check whether the certificate is a CA certificate.
      let pathLen = certExtension.checkCA();
      console.info('checkCA result: success.');
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`operation failed, errCode:${e.code}, errMsg:${e.message}`);
    }
  });
}
```