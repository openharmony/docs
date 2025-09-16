# Certificate Signing with PKCS #7

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

This feature is supported since API version 18.

PKCS #7 is a standard syntax for storing signed or encrypted data. The extension of PKCS#7, which is CMS, supports the following data types: data, signed data, enveloped data, signed and enveloped data, digest data, and encrypted data. It is often used to protect data integrity and confidentiality. Currently, only PKCS #7 signed data is supported.

## How to Develop

1. Import the [cert](../../reference/apis-device-certificate-kit/js-apis-cert.md) module.

   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   ```
2. Call [cert.createCmsGenerator](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatecmsgenerator18) to create a **cmsGenerator** object.

3. Call [cmsGenerator.addSigner](../../reference/apis-device-certificate-kit/js-apis-cert.md#addsigner18) to add the signer information.

4. Call [cmsGenerator.addCert](../../reference/apis-device-certificate-kit/js-apis-cert.md#addcert18) to add a certificate.

5. Call [cmsGenerator.doFinal](../../reference/apis-device-certificate-kit/js-apis-cert.md#dofinal18) to obtain the final signed data of the CMS.

- Example (using asynchronous APIs):

  ```ts
  import { cert } from '@kit.DeviceCertificateKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIICXjCCAcegAwIBAgIGAXKnJjrAMA0GCSqGSIb3DQEBCwUAMEgxCzAJBgNVBAYT\n' +
    'AkNOMQwwCgYDVQQIDANzaGExDTALBgNVBAcMBHhpYW4xDTALBgNVBAoMBHRlc3Qx\n' +
    'DTALBgNVBAMMBHRlc3QwHhcNMjQxMTIyMDkwNTIyWhcNMzQxMTIwMDkwNTIyWjBI\n' +
    'MQswCQYDVQQGEwJDTjEMMAoGA1UECAwDc2hhMQ0wCwYDVQQHDAR4aWFuMQ0wCwYD\n' +
    'VQQKDAR0ZXN0MQ0wCwYDVQQDDAR0ZXN0MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCB\n' +
    'iQKBgQC6nCZTM16Rk2c4P/hwfVm++jqe6GCA/PXXGe4YL218q1dTKMHBGEw8kXi0\n' +
    'XLDcyyC2yUn8ywN2QSyly6ke9EE6PGfZywStLp4g2PTTWB04sS3aXT2y+fToiTXQ\n' +
    '3AxfFYRpB+EgSdSCkJs6jKXVwbzu54kEtQTfs8UdBQ9nVKaJLwIDAQABo1MwUTAd\n' +
    'BgNVHQ4EFgQU6QXnt1smb2HRSO/2zuRQnz/SDxowHwYDVR0jBBgwFoAU6QXnt1sm\n' +
    'b2HRSO/2zuRQnz/SDxowDwYDVR0TAQH/BAUwAwEB/zANBgkqhkiG9w0BAQsFAAOB\n' +
    'gQBPR/+5xzFG1XlTdgwWVvqVxvhGUkbMTGW0IviJ+jbKsi57vnVsOtFzEA6y+bYx\n' +
    'xG/kEOcwLtzeVHOQA+ZU5SVcc+qc0dfFiWjL2PSAG4bpqSTjujpuUk+g8ugixbG1\n' +
    'a26pkDJhNeB/E3eBIbeydSY0A/dIGb6vbGo6BSq2KvnWAA==\n' +
    '-----END CERTIFICATE-----\n';

  let rsaStr1024: string  =
    '-----BEGIN RSA PRIVATE KEY-----\n' +
      'Proc-Type: 4,ENCRYPTED\n' +
      'DEK-Info: DES-EDE3-CBC,DB0AC6E3BEE16420\n\n' +
      '1N5xykdckthZnswMV7blxXm2RCqe/OByBfMwFI7JoXR8STtMiStd4xA3W405k1Ma\n' +
      'ExpsHgWwZaS23x+sQ1sL1dsqIPMrw1Vr+KrL20vQcCVjXPpGKauafVbtcWQ1r2PZ\n' +
      'QJ4KWP6FhUp+sGt2ItODW3dK+1GdqL22ZtANrgFzS42Wh8FSn0UMCf6RG62DK62J\n' +
      'z2jtf4XaorrGSjdTeY+fyyGfSyKidIMMBe+IXwlhCgAe7aHSaqXtMsv+BibB7PJ3\n' +
      'XmEp1D/0ptL3r46txyYcuy8jSNCkW8er93KKnlRN6KbuYZPvPNncWkzZBzV17t5d\n' +
      'QgtvVh32AKgqk5jm8YVnspOFiPrbrK9UN3IW15juFkfnhriM3IrKap4/kW+tfawZ\n' +
      'DmHkSyl8xqFK413Rv0UvYBTjOcGbs2BSJYEvp8CIjtA17SvLmNw70K2nXWuQYutY\n' +
      '+HyucPtHfEqUPQRzWTAMMntTru77u7dxo2WMMMxOtMJO5h7MAnZH9bAFiuO3ewcY\n' +
      'eEePg10d8Owcfh9G6kc0HIGT9MMLMi0mTXhpoQTuWPYuSx6uUZL1fsp1x2fuM0qn\n' +
      'bdf3+UnATYUu4tgvBHrMV7405Y6Y3PnqOFxVMeAHeOTo6UThtJ10mfeCPXGcUaHo\n' +
      'P5enw7h4145cha3+S4hNrUwj3skrtavld7tY74p4DvgZSlCMF3JAm3DhpnEMVcYP\n' +
      'Y6TkSevvxOpBvEHE41Y4VBCBwd9clcixI6cSBJKPUU4A/sc/kkNdGFcbzLQCg/zR\n' +
      '1m7YmBROb2qy4w3lv/uwVnPGLg/YV465irRaN3hgz7/1lm8STKQhmQ==\n' +
      '-----END RSA PRIVATE KEY-----\n';

  // Convert the string into a Uint8Array.
  function stringToUint8Array(str: string): Uint8Array {
    let arr: Array<number> = [];
    for (let i = 0, j = str.length; i < j; i++) {
      arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
  }

  async function testPkcs7SignByPromise() {
    let certEncodingBlob: cert.EncodingBlob = {
      data: stringToUint8Array(certData),
      // Assign a value based on the encodingData format. FORMAT_PEM and FORMAT_DER are supported.
      encodingFormat: cert.EncodingFormat.FORMAT_PEM
    };
    cert.createX509Cert(certEncodingBlob, (error, x509Cert) => {
      if (error) {
        console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
        try {
          let cmsContentType = cert.CmsContentType.SIGNED_DATA;
          let cmsGenerator = cert.createCmsGenerator(cmsContentType);
          console.info('testPkcs7SignByPromise createCmsGenerator success.');
          let privateKeyInfo: cert.PrivateKeyInfo = {
            key: rsaStr1024,
            password: '123456'
          };
          // If addCert is true, an error will be reported if the same certificate is added to addSigner or addCert.
          let config: cert.CmsSignerConfig = {
            mdName:'SHA256',
            addCert:false,
            addAttr:true,
            addSmimeCapAttr:true
          }
          cmsGenerator.addSigner(x509Cert, privateKeyInfo, config);
          console.info('testPkcs7SignByPromise addSigner success.');
          cmsGenerator.addCert(x509Cert);
          console.info('testPkcs7SignByPromise addCert success.');
          let content = new Uint8Array([1,2,3,4]);
          let optionsFinal: cert.CmsGeneratorOptions = {
            contentDataFormat : cert.CmsContentDataFormat.BINARY,
            outFormat : cert.CmsFormat.PEM,
            isDetached : true
          };
          cmsGenerator.doFinal(content, optionsFinal).then(result => {
            console.log('testPkcs7SignByPromise doFinal success, resullt = %s', result);
          }).catch((error: BusinessError) => {
            console.error('testPkcs7SignByPromise failed, errCode: ' + error.code + ', errMsg: ' + error.message);
          });
        } catch (err) {
          let e: BusinessError = err as BusinessError;
          console.error('testPkcs7SignByPromise failed, errCode: ' + e.code + ', errMsg: ' + e.message);
        }
      }
    });
  }
  ```

- Example (using synchronous APIs):

  ```ts
  import { cert } from '@kit.DeviceCertificateKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let certData = '-----BEGIN CERTIFICATE-----\n' +
    'MIICXjCCAcegAwIBAgIGAXKnJjrAMA0GCSqGSIb3DQEBCwUAMEgxCzAJBgNVBAYT\n' +
    'AkNOMQwwCgYDVQQIDANzaGExDTALBgNVBAcMBHhpYW4xDTALBgNVBAoMBHRlc3Qx\n' +
    'DTALBgNVBAMMBHRlc3QwHhcNMjQxMTIyMDkwNTIyWhcNMzQxMTIwMDkwNTIyWjBI\n' +
    'MQswCQYDVQQGEwJDTjEMMAoGA1UECAwDc2hhMQ0wCwYDVQQHDAR4aWFuMQ0wCwYD\n' +
    'VQQKDAR0ZXN0MQ0wCwYDVQQDDAR0ZXN0MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCB\n' +
    'iQKBgQC6nCZTM16Rk2c4P/hwfVm++jqe6GCA/PXXGe4YL218q1dTKMHBGEw8kXi0\n' +
    'XLDcyyC2yUn8ywN2QSyly6ke9EE6PGfZywStLp4g2PTTWB04sS3aXT2y+fToiTXQ\n' +
    '3AxfFYRpB+EgSdSCkJs6jKXVwbzu54kEtQTfs8UdBQ9nVKaJLwIDAQABo1MwUTAd\n' +
    'BgNVHQ4EFgQU6QXnt1smb2HRSO/2zuRQnz/SDxowHwYDVR0jBBgwFoAU6QXnt1sm\n' +
    'b2HRSO/2zuRQnz/SDxowDwYDVR0TAQH/BAUwAwEB/zANBgkqhkiG9w0BAQsFAAOB\n' +
    'gQBPR/+5xzFG1XlTdgwWVvqVxvhGUkbMTGW0IviJ+jbKsi57vnVsOtFzEA6y+bYx\n' +
    'xG/kEOcwLtzeVHOQA+ZU5SVcc+qc0dfFiWjL2PSAG4bpqSTjujpuUk+g8ugixbG1\n' +
    'a26pkDJhNeB/E3eBIbeydSY0A/dIGb6vbGo6BSq2KvnWAA==\n' +
    '-----END CERTIFICATE-----\n';

  let rsaStr1024: string  =
    '-----BEGIN RSA PRIVATE KEY-----\n' +
      'Proc-Type: 4,ENCRYPTED\n' +
      'DEK-Info: DES-EDE3-CBC,DB0AC6E3BEE16420\n\n' +
      '1N5xykdckthZnswMV7blxXm2RCqe/OByBfMwFI7JoXR8STtMiStd4xA3W405k1Ma\n' +
      'ExpsHgWwZaS23x+sQ1sL1dsqIPMrw1Vr+KrL20vQcCVjXPpGKauafVbtcWQ1r2PZ\n' +
      'QJ4KWP6FhUp+sGt2ItODW3dK+1GdqL22ZtANrgFzS42Wh8FSn0UMCf6RG62DK62J\n' +
      'z2jtf4XaorrGSjdTeY+fyyGfSyKidIMMBe+IXwlhCgAe7aHSaqXtMsv+BibB7PJ3\n' +
      'XmEp1D/0ptL3r46txyYcuy8jSNCkW8er93KKnlRN6KbuYZPvPNncWkzZBzV17t5d\n' +
      'QgtvVh32AKgqk5jm8YVnspOFiPrbrK9UN3IW15juFkfnhriM3IrKap4/kW+tfawZ\n' +
      'DmHkSyl8xqFK413Rv0UvYBTjOcGbs2BSJYEvp8CIjtA17SvLmNw70K2nXWuQYutY\n' +
      '+HyucPtHfEqUPQRzWTAMMntTru77u7dxo2WMMMxOtMJO5h7MAnZH9bAFiuO3ewcY\n' +
      'eEePg10d8Owcfh9G6kc0HIGT9MMLMi0mTXhpoQTuWPYuSx6uUZL1fsp1x2fuM0qn\n' +
      'bdf3+UnATYUu4tgvBHrMV7405Y6Y3PnqOFxVMeAHeOTo6UThtJ10mfeCPXGcUaHo\n' +
      'P5enw7h4145cha3+S4hNrUwj3skrtavld7tY74p4DvgZSlCMF3JAm3DhpnEMVcYP\n' +
      'Y6TkSevvxOpBvEHE41Y4VBCBwd9clcixI6cSBJKPUU4A/sc/kkNdGFcbzLQCg/zR\n' +
      '1m7YmBROb2qy4w3lv/uwVnPGLg/YV465irRaN3hgz7/1lm8STKQhmQ==\n' +
      '-----END RSA PRIVATE KEY-----\n';

  // Convert the string into a Uint8Array.
  function stringToUint8Array(str: string): Uint8Array {
    let arr: Array<number> = [];
    for (let i = 0, j = str.length; i < j; i++) {
      arr.push(str.charCodeAt(i));
    }
    return new Uint8Array(arr);
  }

  function testPkcs7SignBySync() {
    let certEncodingBlob: cert.EncodingBlob = {
      data: stringToUint8Array(certData),
      // Assign a value based on the encodingData format. FORMAT_PEM and FORMAT_DER are supported.
      encodingFormat: cert.EncodingFormat.FORMAT_PEM
    };
    cert.createX509Cert(certEncodingBlob, (error, x509Cert) => {
      if (error) {
        console.error('createX509Cert failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      } else {
          try {
            let cmsContentType = cert.CmsContentType.SIGNED_DATA;
            let cmsGenerator = cert.createCmsGenerator(cmsContentType);
            console.info('testPkcs7SignBySync createCmsGenerator success.');
            let privateKeyInfo: cert.PrivateKeyInfo = {
              key: rsaStr1024,
              password: '123456'
            };
            // If addCert is true, an error will be reported if the same certificate is added to addSigner or addCert.
            let config: cert.CmsSignerConfig = {
              mdName:'SHA256',
              addCert:false,
              addAttr:false,
              addSmimeCapAttr:false
            }
            cmsGenerator.addSigner(x509Cert, privateKeyInfo, config);
            console.info('testPkcs7SignBySync addSigner success.');
            cmsGenerator.addCert(x509Cert);
            console.info('testPkcs7SignBySync addCert success.');
            let content = new Uint8Array([1,2,3,4]);
            let optionsFinal: cert.CmsGeneratorOptions = {
              contentDataFormat : cert.CmsContentDataFormat.BINARY,
              outFormat : cert.CmsFormat.DER,
              isDetached : false
            };
            let output = cmsGenerator.doFinalSync(content, optionsFinal);
            console.info('testPkcs7SignBySync doFinalSync success, output = %s.', output);
          } catch (err) {
            let e: BusinessError = err as BusinessError;
            console.error('testPkcs7SignBySync failed, errCode: ' + e.code + ', errMsg: ' + e.message);
          }
      }
    });
  }
  ```
