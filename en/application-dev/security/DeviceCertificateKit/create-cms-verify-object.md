# Certificate Signature Verification with CMS

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=ae628f395efd1389baf7d540181f9bb8c5132144 translatedAt=2026-08-11T01:59:34.164Z pushedAt=2026-08-11T07:37:08.863Z -->

Certificate signature verification with CMS is supported since API version 22.

PKCS #7 is a standard syntax for storing signed or encrypted data. CMS (Cryptographic Message Syntax), as an extension of PKCS #7, supports the following data types: data, signed data, encapsulated data, signed and encapsulated data, digest data, and encrypted data. This standard is commonly used to protect data integrity and confidentiality.

Currently, only CMS signature data and encapsulated data are supported.

## How to Develop

1. Import the [certificate module](../../reference/apis-device-certificate-kit/js-apis-cert.md).

   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   ```

2. For signature development steps, see [CMS Signature](../../security/DeviceCertificateKit/create-cms-sign-object.md).

3. Call [cert.createCmsParser](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatecmsparser22) to create a **CmsParser** object.

4. Call [cmsParser.setRawData](../../reference/apis-device-certificate-kit/js-apis-cert.md#setrawdata22) to set CMS data.

5. Call [cmsParser.verifySignedData](../../reference/apis-device-certificate-kit/js-apis-cert.md#verifysigneddata22) to verify the signature.

Signature verification example:

<!-- @[create-cms-verify-object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/DeviceCertificateKit/CertificateAlgorithmLibrary/entry/src/main/ets/pages/CreateCmsVerifyObject.ets) -->

``` TypeScript

import { cert } from '@kit.DeviceCertificateKit';

let ECC_256_PUB_ENTRY_CERT: string =
  '-----BEGIN CERTIFICATE-----\n' +
    'MIICejCCAiCgAwIBAgIUGE371/LcCW79mzMm6UiJdyC4khcwCgYIKoZIzj0EAwIw\n' +
    'fjELMAkGA1UEBhMCQ04xEDAOBgNVBAgMB0JlaWppbmcxEDAOBgNVBAcMB0JlaWpp\n' +
    'bmcxHjAcBgNVBAoMFUVDRFNBIEludGVybWVkaWF0ZSBDQTELMAkGA1UECwwCSVQx\n' +
    'HjAcBgNVBAMMFUVDRFNBIEludGVybWVkaWF0ZSBDQTAeFw0yNTA5MjgxMDU0MDVa\n' +
    'Fw0zNTA5MjYxMDU0MDVaMHUxCzAJBgNVBAYTAkNOMRAwDgYDVQQIDAdCZWlqaW5n\n' +
    'MRAwDgYDVQQHDAdCZWlqaW5nMRswGQYDVQQKDBJFQ0RTQSBFeGFtcGxlIENvcnAx\n' +
    'CzAJBgNVBAsMAklUMRgwFgYDVQQDDA93d3cuZXhhbXBsZS5jb20wWTATBgcqhkjO\n' +
    'PQIBBggqhkjOPQMBBwNCAAQNKO5YXAsmdm/ShEU5VyQlQSdnV6hNQIofHhQ/GyeK\n' +
    '1W7t3KnMie4cv/wnA4Qmor2KeBBXUFUnYJqqWOHsivIuo4GEMIGBMAkGA1UdEwQC\n' +
    'MAAwCwYDVR0PBAQDAgK0MCcGA1UdEQQgMB6CD3d3dy5leGFtcGxlLmNvbYILZXhh\n' +
    'bXBsZS5jb20wHQYDVR0OBBYEFD7RUSUimy0SWShmPIus91tDS0u9MB8GA1UdIwQY\n' +
    'MBaAFFjgVG0DwmSwxzJWELNvxGtm3mxUMAoGCCqGSM49BAMCA0gAMEUCIQCTw7sx\n' +
    'X0tt1xiNvIQ9LD4bECzdgzIuBaU97GgYDusIUgIgTkc0wYZ3EUg0COHPly4cVsTj\n' +
    '1Cyy/+qufhBUJw5om7E=\n' +
    '-----END CERTIFICATE-----';

let ECC_256_PUB_INTER_CERT: string =
  '-----BEGIN CERTIFICATE-----\n' +
    'MIICTDCCAfGgAwIBAgIUc1x0keEiLIcS1oKtSpeEiPoaepkwCgYIKoZIzj0EAwIw\n' +
    'bjELMAkGA1UEBhMCQ04xEDAOBgNVBAgMB0JlaWppbmcxEDAOBgNVBAcMB0JlaWpp\n' +
    'bmcxFjAUBgNVBAoMDUVDRFNBIFJvb3QgQ0ExCzAJBgNVBAsMAklUMRYwFAYDVQQD\n' +
    'DA1FQ0RTQSBSb290IENBMB4XDTI1MDkyODEwNTM0OVoXDTMwMDkyNzEwNTM0OVow\n' +
    'fjELMAkGA1UEBhMCQ04xEDAOBgNVBAgMB0JlaWppbmcxEDAOBgNVBAcMB0JlaWpp\n' +
    'bmcxHjAcBgNVBAoMFUVDRFNBIEludGVybWVkaWF0ZSBDQTELMAkGA1UECwwCSVQx\n' +
    'HjAcBgNVBAMMFUVDRFNBIEludGVybWVkaWF0ZSBDQTBZMBMGByqGSM49AgEGCCqG\n' +
    'SM49AwEHA0IABGoCqpHBV/glJeezsp693/hhflYOKpHvaNszVBLkTurkqrbhbaMo\n' +
    'hw1oO2Zro54rhZ8tom2UAGn1rzNmRVBCxTajXTBbMAwGA1UdEwQFMAMBAf8wCwYD\n' +
    'VR0PBAQDAgEGMB0GA1UdDgQWBBRY4FRtA8JksMcyVhCzb8RrZt5sVDAfBgNVHSME\n' +
    'GDAWgBTmNm24RfPnLf1HMNCocS90CGalJjAKBggqhkjOPQQDAgNJADBGAiEAstMv\n' +
    'puHi/dgAlvycicL3VQ5iITvUSG2fo286LYc01CQCIQCyw4+94ovyRtaT/WWoZh3u\n' +
    'ia4tt478nYeQgMChg+xtSw==\n' +
    '-----END CERTIFICATE-----';

let ECC_256_PUB_ROOT_CERT: string =
  '-----BEGIN CERTIFICATE-----\n' +
    'MIICUzCCAfqgAwIBAgIUPma0DkC+ck+t/3eykmsKsy5D0egwCgYIKoZIzj0EAwIw\n' +
    'bjELMAkGA1UEBhMCQ04xEDAOBgNVBAgMB0JlaWppbmcxEDAOBgNVBAcMB0JlaWpp\n' +
    'bmcxFjAUBgNVBAoMDUVDRFNBIFJvb3QgQ0ExCzAJBgNVBAsMAklUMRYwFAYDVQQD\n' +
    'DA1FQ0RTQSBSb290IENBMB4XDTI1MDkyODEwNTMyN1oXDTM1MDkyNjEwNTMyN1ow\n' +
    'bjELMAkGA1UEBhMCQ04xEDAOBgNVBAgMB0JlaWppbmcxEDAOBgNVBAcMB0JlaWpp\n' +
    'bmcxFjAUBgNVBAoMDUVDRFNBIFJvb3QgQ0ExCzAJBgNVBAsMAklUMRYwFAYDVQQD\n' +
    'DA1FQ0RTQSBSb290IENBMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEA3KYWepl\n' +
    'wjHe/Htx2cAhrjaZpWPJOUyL6siUFRayVebaqOQejuUPypbj+u4ZHodsviUe12E1\n' +
    '50Q+R9Uayes+WKN2MHQwHQYDVR0OBBYEFOY2bbhF8+ct/Ucw0KhxL3QIZqUmMB8G\n' +
    'A1UdIwQYMBaAFOY2bbhF8+ct/Ucw0KhxL3QIZqUmMAsGA1UdDwQEAwIBBjAJBgNV\n' +
    'HREEAjAAMAkGA1UdEgQCMAAwDwYDVR0TAQH/BAUwAwEB/zAKBggqhkjOPQQDAgNH\n' +
    'ADBEAiAjo+sFDtGVhyc+NqdwxhepqSXOjRI5As6TSz3OYTvERwIgayLgfBn2uABH\n' +
    'wYQI60CEJkDF9Pn2fxsGuNEyyn0ks28=\n' +
    '-----END CERTIFICATE-----';
let ECC_256_PRI_ENTRY_KEY: string =
  '-----BEGIN EC PRIVATE KEY-----\n' +
    'MHcCAQEEII8+yfaMTjUyWtjIopGgNxHUMPKhAYTnIVYbiTOVB4x5oAoGCCqGSM49\n' +
    'AwEHoUQDQgAEDSjuWFwLJnZv0oRFOVckJUEnZ1e oTUCKHx4UPxsnitVu7dypzInu\n' +
    'HL/8JwOEJqK9ingQV1BVJ2Caqljh7IryLg==\n' +
    '-----END EC PRIVATE KEY-----';

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

async function testCmsVerifyTest() {
  try {
    let plainText: Uint8Array = new Uint8Array([0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07]);
    let x509CertEntry: cert.X509Cert = await createX509Cert(ECC_256_PUB_ENTRY_CERT);
    let x509CertInter: cert.X509Cert = await createX509Cert(ECC_256_PUB_INTER_CERT);
    let x509CertRoot: cert.X509Cert = await createX509Cert(ECC_256_PUB_ROOT_CERT);
    let cms: cert.CmsGenerator = cert.createCmsGenerator(cert.CmsContentType.SIGNED_DATA);
    let signerConfig: cert.CmsSignerConfig = {
      mdName: 'SHA256',
    };
    let keyInfo: cert.PrivateKeyInfo = {
      key: ECC_256_PRI_ENTRY_KEY
    };
    let option: cert.CmsGeneratorOptions = {
      outFormat: cert.CmsFormat.PEM
    };
    cms.addSigner(x509CertEntry, keyInfo, signerConfig);
    let signData = cms.doFinalSync(plainText, option);
    let config: cert.CmsVerificationConfig = {
      trustCerts: [x509CertRoot, x509CertInter],
    };
    let verify: cert.CmsParser = cert.createCmsParser();
    await verify.setRawData(signData, cert.CmsFormat.PEM);
    await verify.verifySignedData(config);
    console.info(`verifySignedData result: success.`);
  } catch (error) {
    console.error(`verifySignedData failed: errCode: ${error.code}, message: ${error.message}`);
  }
}
```