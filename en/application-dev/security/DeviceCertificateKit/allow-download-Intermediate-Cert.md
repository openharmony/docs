# Downloading the Missing Intermediate CA Certificate During Certificate Chain Validation

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=78d27a16851062ae03d6a51de8b99e33aec772a0 translatedAt=2026-08-11T01:57:16.226Z pushedAt=2026-08-11T02:39:07.044Z -->

Since API version 23, the missing intermediate CA certificate can be downloaded during certificate chain validation.

This topic uses the creation of an X.509 certificate chain as an example to demonstrate how to create a certificate chain object while allowing the download of missing intermediate certificates during validation.

## How to Develop

1. Import the [certificate module](../../reference/apis-device-certificate-kit/js-apis-cert.md).

   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   ```

2. Based on the existing certificate data, call [cert.createX509Cert](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509cert-1) to create an X.509 certificate object and return the result.

3. Call [cert.buildX509CertChain](../../reference/apis-device-certificate-kit/js-apis-cert.md#certbuildx509certchain12) to create an X.509 certificate chain object. Set the **allowDownloadIntermediateCa** parameter of **validationParameters** to **true** to enable downloading missing intermediate CA certificates from the network during validation.

> **NOTE**
>
> The sample code provided in this development guide must be executed with the network configured. Declare the **ohos.permission.INTERNET** permission. For details, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

<!-- @[allow-download-intermediate-cert](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/DeviceCertificateKit/CertificateAlgorithmLibrary/entry/src/main/ets/pages/AllowDownloadIntermediateCert.ets) -->

``` TypeScript

import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

let rootCert = '-----BEGIN CERTIFICATE-----\n' +
  'MIIDjjCCAnagAwIBAgIQAzrx5qcRqaC7KGSxHQn65TANBgkqhkiG9w0BAQsFADBh\n' +
  'MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3\n' +
  'd3cuZGlnaWNlcnQuY29tMSAwHgYDVQQDExdEaWdpQ2VydCBHbG9iYWwgUm9vdCBH\n' +
  'MjAeFw0xMzA4MDExMjAwMDBaFw0zODAxMTUxMjAwMDBaMGExCzAJBgNVBAYTAlVT\n' +
  'MRUwEwYDVQQKEwxEaWdpQ2VydCBJbmMxGTAXBgNVBAsTEHd3dy5kaWdpY2VydC5j\n' +
  'b20xIDAeBgNVBAMTF0RpZ2lDZXJ0IEdsb2JhbCBSb290IEcyMIIBIjANBgkqhkiG\n' +
  '9w0BAQEFAAOCAQ8AMIIBCgKCAQEAuzfNNNx7a8myaJCtSnX/RrohCgiN9RlUyfuI\n' +
  '2/Ou8jqJkTx65qsGGmvPrC3oXgkkRLpimn7Wo6h+4FR1IAWsULecYxpsMNzaHxmx\n' +
  '1x7e/dfgy5SDN67sH0NO3Xss0r0upS/kqbitOtSZpLYl6ZtrAGCSYP9PIUkY92eQ\n' +
  'q2EGnI/yuum06ZIya7XzV+hdG82MHauVBJVJ8zUtluNJbd134/tJS7SsVQepj5Wz\n' +
  'tCO7TG1F8PapspUwtP1MVYwnSlcUfIKdzXOS0xZKBgyMUNGPHgm+F6HmIcr9g+UQ\n' +
  'vIOlCsRnKPZzFBQ9RnbDhxSJITRNrw9FDKZJobq7nMWxM4MphQIDAQABo0IwQDAP\n' +
  'BgNVHRMBAf8EBTADAQH/MA4GA1UdDwEB/wQEAwIBhjAdBgNVHQ4EFgQUTiJUIBiV\n' +
  '5uNu5g/6+rkS7QYXjzkwDQYJKoZIhvcNAQELBQADggEBAGBnKJRvDkhj6zHd6mcY\n' +
  '1Yl9PMWLSn/pvtsrF9+wX3N3KjITOYFnQoQj8kVnNeyIv/iPsGEMNKSuIEyExtv4\n' +
  'NeF22d+mQrvHRAiGfzZ0JFrabA0UWTW98kndth/Jsw1HKj2ZL7tcu7XUIOGZX1NG\n' +
  'Fdtom/DzMNU+MeKNhJ7jitralj41E6Vf8PlwUHBHQRFXGU7Aj64GxJUTFy8bJZ91\n' +
  '8rGOmaFvE7FBcf6IKshPECBV1/MUReXgRPTqh5Uykw7+U0b6LJ3/iyK5S9kJRaTe\n' +
  'pLiaWN0bfVKfjllDiIGknibVb63dDcY3fe0Dkhvld1927jyNxF1WW6LZZm6zNTfl\n' +
  'MrY=\n' +
  '-----END CERTIFICATE-----';

let leafCert = '-----BEGIN CERTIFICATE-----\n' +
  'MIIGIzCCBQugAwIBAgIQD8vHwz7g05mDl1F5X17HGzANBgkqhkiG9w0BAQsFADBg\n' +
  'MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3\n' +
  'd3cuZGlnaWNlcnQuY29tMR8wHQYDVQQDExZSYXBpZFNTTCBUTFMgUlNBIENBIEcx\n' +
  'MB4XDTI1MDMyNDAwMDAwMFoXDTI2MDMyMzIzNTk1OVowFzEVMBMGA1UEAwwMKi5k\n' +
  'b3ViYW8uY29tMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAw6eEA/GD\n' +
  'ShJ0Rtlet3Lf+uYiYzzFJ6J1iJeT/JyvTwDOTKO2VgMjsFHgUcFJBG6QGZT6PXSv\n' +
  'vhkdzzIqqXzJwDsqqowwTwMk0YN/JUB0yr/9aFlmQakLZClu1W5og7uxp4ME+ep6\n' +
  'aJhoQ9MMCCn3/pvDnLoX1hG9z0pgbUsnIrM+1roLpH+D0FwC4jww7+tDr89/kjb4\n' +
  '/+LMqjAbe1fLtXJRuxH5O+kAQNqLL/0ECvq+4KpC/r/0UxTlRTpGZY2M3MPUEXfp\n' +
  'RKMmkRoRSKwDMJ5u2DK0qanvV6mu7ORPoDsC/fTAiqonjh8rClm/zpj5GN9BQKfu\n' +
  'UoaeWIN/XMZSzQIDAQABo4IDIDCCAxwwHwYDVR0jBBgwFoAUDNtsgkkPSmcKuBTu\n' +
  'esRIUojrVjgwHQYDVR0OBBYEFCseEe+vZQ8BzqzkOju1EhGQwoCYMCMGA1UdEQQc\n' +
  'MBqCDCouZG91YmFvLmNvbYIKZG91YmFvLmNvbTA+BgNVHSAENzA1MDMGBmeBDAEC\n' +
  'ATApMCcGCCsGAQUFBwIBFhtodHRwOi8vd3d3LmRpZ2ljZXJ0LmNvbS9DUFMwDgYD\n' +
  'VR0PAQH/BAQDAgWgMB0GA1UdJQQWMBQGCCsGAQUFBwMBBggrBgEFBQcDAjA/BgNV\n' +
  'HR8EODA2MDSgMqAwhi5odHRwOi8vY2RwLnJhcGlkc3NsLmNvbS9SYXBpZFNTTFRM\n' +
  'U1JTQUNBRzEuY3JsMHYGCCsGAQUFBwEBBGowaDAmBggrBgEFBQcwAYYaaHR0cDov\n' +
  'L3N0YXR1cy5yYXBpZHNzbC5jb20wPgYIKwYBBQUHMAKGMmh0dHA6Ly9jYWNlcnRz\n' +
  'LnJhcGlkc3NsLmNvbS9SYXBpZFNTTFRMU1JTQUNBRzEuY3J0MAwGA1UdEwEB/wQC\n' +
  'MAAwggF9BgorBgEEAdZ5AgQCBIIBbQSCAWkBZwB2AA5XlLzzrqk+MxssmQez95Df\n' +
  'm8I9cTIl3SGpJaxhxU4hAAABlcjhhZsAAAQDAEcwRQIhAKfZw1gNPE4sWKi3WL0U\n' +
  'vO4EGn+MD1hScKPMNHex6Ty+AiBv0yYWRuEURh/8ywDMHC+1f3xFaj9kshfv389b\n' +
  'e09MhAB1AGQRxGykEuyniRyiAi4AvKtPKAfUHjUnq+r+1QPJfc3wAAABlcjhhcUA\n' +
  'AAQDAEYwRAIgClXL9SnQFh+6HEqsT/3aBM6jK9NmzG+hrmJGowOKVFYCIEsGPJda\n' +
  'TtsBnc/PrhZSjOHitpzrzKhW02hHOzkrtlR/AHYASZybad4dfOz8Nt7Nh2SmuFuv\n' +
  'CoeAGdFVUvvp6ynd+MMAAAGVyOGF3gAABAMARzBFAiBExgNNV8q5xfdSU+yL6NAJ\n' +
  'l1ze5IYXTetQf04caLUhKgIhALvTCHHHdvokmFbRKQvrY50ihwDoHd4pKbzRtyQ0\n' +
  'H16bMA0GCSqGSIb3DQEBCwUAA4IBAQAsjyQpYDf1JiYBsO4koUcFPeAdvTp9FbRL\n' +
  'yC0PN34rekPHwcjqsEU7mbuUaZ4EMklHqIqkniStPcKyIDCpSwBu17iezM57fwJA\n' +
  'tb9XfzjxZH1vWEFHImcvMEwR0BLRmwXUnnRt3qOeetTV/UpIwH4HGfHldtRNqSnj\n' +
  'xDiM1c2oRjv+4Qs5CTet70NHsaQBjkUWvioCgigE+vuCPnjwVNXJkfSHjC+DWWzf\n' +
  'Nc+rSFEOvO8Fe4d2rvboT7vXigvTciOeQdig9ySCJQCkWxOvB1AcvZc+kw0YhrpM\n' +
  'xUBhDd+DaUWOgmmVS3n6k3GfOqm2EU7iCp8KyfRu2DAsnlsO/YpH\n' +
  '-----END CERTIFICATE-----';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  const encoder = new util.TextEncoder();
  return encoder.encodeInto(str);
}

async function createX509Cert(certData: string): Promise<cert.X509Cert> {
  // Certificate binary data, which needs to match your case.
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // Assign a value based on the encodingData format. FORMAT_PEM and FORMAT_DER are supported.
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(encodingBlob);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`createX509Cert failed: errCode: ${e.code}, message: ${e.message}`);
  }
  return x509Cert;
}

async function buildX509CertChain() {
  try {
    const root = await createX509Cert(rootCert);
    const leaf = await createX509Cert(leafCert);
    let certCrlCollection = cert.createCertCRLCollection([leaf, root]);
    let param: cert.CertChainBuildParameters = {
      certMatchParameters: {},
      validationParameters: {
        certCRLs: [certCrlCollection],
        allowDownloadIntermediateCa: true,
        trustAnchors: [{ CACert: root }],
      }
    }
    let data = await cert.buildX509CertChain(param);
    console.info('buildX509CertChain result: success, certChainLength = ' + data.certChain.getCertList().length);
  } catch (err) {
    console.error(`buildX509CertChain failed: errCode: ${err.code}, message: ${err.message}`);
  }
}
```