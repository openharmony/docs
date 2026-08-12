# Certificate Decapsulation with CMS

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=cdfa46c08dbbfca7e797a254b21f1337ee1c8281 translatedAt=2026-08-11T01:59:16.093Z pushedAt=2026-08-11T07:35:21.711Z -->

Certificate CMS decapsulation is supported since API version 22.

PKCS #7 is a standard syntax for storing signed or encrypted data. As an extension of PKCS #7, CMS supports the following data types: data, signed data, encapsulated data, signed and encapsulated data, digested data, and encrypted data. This standard is commonly used to protect data integrity and confidentiality.

Currently, only CMS signature data and encapsulated data are supported.

## How to Develop

1. Import the [certificate module](../../reference/apis-device-certificate-kit/js-apis-cert.md).

   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   ```

2. Call [Certificate Encapsulation with CMS](../../security/DeviceCertificateKit/create-cms-enveloped-object.md) to encapsulate CMS data.

3. Call [cert.createCmsParser](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatecmsparser22) to create a **CmsParser** object.

4. Call [cmsParser.setRawData](../../reference/apis-device-certificate-kit/js-apis-cert.md#setrawdata22) to set CMS data.

5. Call [cmsParser.decryptEnvelopedData](../../reference/apis-device-certificate-kit/js-apis-cert.md#decryptenvelopeddata22) to decapsulate data.

Decapsulation example:

<!-- @[create-cms-decapsulation-object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/DeviceCertificateKit/CertificateAlgorithmLibrary/entry/src/main/ets/pages/CreateCmsDecapsulationObject.ets) -->

``` TypeScript

import { cert } from '@kit.DeviceCertificateKit';

let ECC_256_PUBKEY: string =
  '-----BEGIN CERTIFICATE-----\n' +
    'MIICGDCCAb6gAwIBAgIGAXKnJjrAMAoGCCqGSM49BAMCMFcxCzAJBgNVBAYTAkNO\n' +
    'MQ8wDQYDVQQIDAbpmZXopb8xDzANBgNVBAcMBuilv+WuiTEPMA0GA1UECgwG5rWL\n' +
    '6K+VMRUwEwYDVQQDDAzkuK3mlofmtYvor5UwHhcNMjUwOTE2MDY0MTMwWhcNMzUw\n' +
    'OTE0MDY0MTMwWjBXMQswCQYDVQQGEwJDTjEPMA0GA1UECAwG6ZmV6KW/MQ8wDQYD\n' +
    'VQQHDAbopb/lrokxDzANBgNVBAoMBua1i+ivlTEVMBMGA1UEAwwM5Lit5paH5rWL\n' +
    '6K+VMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEB06h4SzOryi3d7PW9yN2wACC\n' +
    'VxlduBQjVLWZlDKhFKkdZjve8mUyytSSbBj/rrzR2XmzUzofuNkUbAtje3DDJqN2\n' +
    'MHQwHQYDVR0OBBYEFNtUldgBESf31bwTnYtApIctaSdtMB8GA1UdIwQYMBaAFNtU\n' +
    'ldgBESf31bwTnYtApIctaSdtMAsGA1UdDwQEAwIBBjAJBgNVHREEAjAAMAkGA1Ud\n' +
    'EgQCMAAwDwYDVR0TAQH/BAUwAwEB/zAKBggqhkjOPQQDAgNIADBFAiEAzxzaG2vR\n' +
    'zUnFFL3X3lRQ0IOJrb6cvkSZuaFd4bW2lgUCIHW6QGGnECDFMbDNz7Og9kjkt+3k\n' +
    'FmEJWqEMYudBH3Ul\n' +
    '-----END CERTIFICATE-----';
let ECC_256_PRIVATE: string =
  '-----BEGIN PRIVATE KEY-----\n' +
    'MIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQgOYwEyIw3ZNIAL4xO\n' +
    'pP6eVcQYcrL2sfnt6vB0z9tKmMmhRANCAAQHTqHhLM6vKLd3s9b3I3bAAIJXGV24\n' +
    'FCNUtZmUMqEUqR1mO97yZTLK1JJsGP+uvNHZebNTOh+42RRsC2N7cMMm\n' +
    '-----END PRIVATE KEY-----';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  };
  return new Uint8Array(arr);
}

async function createX509Cert(inStream: string): Promise<cert.X509Cert> {
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(inStream),
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };
  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(encodingBlob);
  } catch (error) {
    console.error(`createX509Cert failed: errCode: ${error.code}, message: ${error.message}`);
  }
  return x509Cert;
}

async function testCmsDecryptTest() {
  try {
    let plainText: Uint8Array = new Uint8Array([0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07]);
    let x509CertEc: cert.X509Cert = await createX509Cert(ECC_256_PUBKEY);
    let cms: cert.CmsGenerator = cert.createCmsGenerator(cert.CmsContentType.ENVELOPED_DATA);
    let option: cert.CmsGeneratorOptions = {
      outFormat: cert.CmsFormat.PEM
    };
    cms.setRecipientEncryptionAlgorithm(cert.CmsRecipientEncryptionAlgorithm.AES_128_GCM);
    let recipientInfo: cert.CmsRecipientInfo = {
      keyAgreeInfo: {
        cert: x509CertEc,
        digestAlgorithm: cert.CmsKeyAgreeRecipientDigestAlgorithm.SHA256
      }
    };
    await cms.addRecipientInfo(recipientInfo);
    console.info('add recipient result: success, digestAlgorithm = ' + recipientInfo.keyAgreeInfo?.digestAlgorithm);
    let envelopeData = await cms.doFinal(plainText, option);
    console.info('doFinal result: success, envelopeData = ' + envelopeData);
    let cipherText = await cms.getEncryptedContentData();
    console.info('getEncryptedContentData result: success, cipherText = ' + cipherText);
    let config: cert.CmsEnvelopedDecryptionConfig = {
      keyInfo: {
        key: ECC_256_PRIVATE
      },
    };
    let cmsDecrypt: cert.CmsParser = cert.createCmsParser();
    await cmsDecrypt.setRawData(envelopeData, cert.CmsFormat.PEM);
    let decPlainText: Uint8Array = await cmsDecrypt.decryptEnvelopedData(config);
    console.info('decryptEnvelopedData result: success, decPlainText = ' + decPlainText);
    console.info('decryptEnvelopedData result: success.');
  } catch (error) {
    console.error(`decryptEnvelopedData failed: errCode: ${error.code}, message: ${error.message}`);
  }
}
```