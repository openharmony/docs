# Online Validation of Certificate Revocation Status of a Certificate Chain

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=586ca0df7c9e6070a6064e9c1b3f797ce18bcafe translatedAt=2026-08-11T02:01:32.954Z pushedAt=2026-08-11T07:47:32.056Z -->

## Checking the Revocation Status of Local Certificate Chain with Only Leaf Certificate Checked

The revocation status check of the local certificate chain supports checking only the leaf certificate since API version 22.

### How to Develop

1. Import the [certificate module](../../reference/apis-device-certificate-kit/js-apis-cert.md).

   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   ```

2. Call [cert.createX509CertChain](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509certchain11) to create a certificate chain object.

3. Call [cert.createX509Cert](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509cert) to create an X.509 certificate object.

4. Call [cert.createX509CRL](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509crl11) to create an X.509 CRL object.

5. Construct the [cert.CertChainValidationParameters](../../reference/apis-device-certificate-kit/js-apis-cert.md#certchainvalidationparameters11) parameter object for certificate chain verification.

6. Call [cert.validate](../../reference/apis-device-certificate-kit/js-apis-cert.md#validate11) and pass the certificate chain verification parameters to verify the certificate chain.

Example:

<!-- @[create-only-check-leaf-cert-revocate-object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/DeviceCertificateKit/CertificateAlgorithmLibrary/entry/src/main/ets/pages/CreateOnlyCheckLeafCertRevocateObject.ets) -->

``` TypeScript

import { cert } from '@kit.DeviceCertificateKit';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createCertChain(certData: string): Promise<cert.X509CertChain> {
  // Certificate binary data, which needs to match your case.
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // Assign a value based on the encodingData format. FORMAT_PEM and FORMAT_DER are supported.
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

  let x509CertChain: cert.X509CertChain = {} as cert.X509CertChain;
  try {
    x509CertChain = await cert.createX509CertChain(encodingBlob);
  } catch (err) {
    console.error(`createCertChain failed: errCode: ${err.code}, message: ${err.message}`);
  }
  return x509CertChain;
}

async function createCert(certData: string): Promise<cert.X509Cert> {
  // Certificate binary data, which needs to match your case.
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // Assign a value based on the encodingData format. FORMAT_PEM and FORMAT_DER are supported.
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(encodingBlob);
  } catch (err) {
    console.error(`createCert failed: errCode: ${err.code}, message: ${err.message}`);
  }
  return x509Cert;
}

export async function createCRL(crlPem: string): Promise<cert.CertCRLCollection> {
  try {
    let crlEncodingBlob: cert.EncodingBlob = {
      data: stringToUint8Array(crlPem),
      encodingFormat: cert.EncodingFormat.FORMAT_PEM
    }
    let crl: cert.X509CRL = await cert.createX509CRL(crlEncodingBlob);
    let collection: cert.CertCRLCollection = cert.createCertCRLCollection([], [crl]);
    return collection;
  } catch (error) {
    throw error as Error;
  }
}
// ...
async function doTestLeafCertCrlCheck() {
  try {
    let x509CertChain: cert.X509CertChain = await createCertChain(certChainData);
    let x509Cert: cert.X509Cert = await createCert(trustRootCertPem);
    let caCollection: cert.CertCRLCollection = await createCRL(crl);
    const param: cert.CertChainValidationParameters = {
      date: '20250926080000Z',
      trustAnchors: [{
        CACert: x509Cert
      }],
      certCRLs: [caCollection],
      revocationCheckParam: {
        options: [
          cert.RevocationCheckOptions.REVOCATION_CHECK_OPTION_LOCAL_CRL_ONLY_CHECK_END_ENTITY_CERT
        ],
      }
    };
    await x509CertChain.validate(param);
    console.info(`validate result: success.`);
  } catch (error) {
    console.error(`x509CertChain validate failed: errCode: ${error.code}, message: ${error.message}`);
  }
}
```

## Checking the Revocation Status of Intermediate CA Certificates in a Certificate Chain Online

Starting from API version 22, you can check the revocation status of intermediate CA certificates in a certificate chain online.

### How to Develop

1. Import the [certificate module](../../reference/apis-device-certificate-kit/js-apis-cert.md).

   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   ```

2. Call [cert.createX509CertChain](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509certchain11) to create a certificate chain object.

3. Call [cert.createX509Cert](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509cert) to create an X.509 certificate object.

4. Construct the [cert.CertChainValidationParameters](../../reference/apis-device-certificate-kit/js-apis-cert.md#certchainvalidationparameters11) certificate chain verification parameters.

5. Call [cert.validate](../../reference/apis-device-certificate-kit/js-apis-cert.md#validate11) and pass the certificate chain verification parameters to verify the certificate chain.

> **NOTE**
>
> The sample code provided in this development guide must be executed with the network configured.

Example:

<!-- @[create-online-check-intermediate-certificateonly-object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/DeviceCertificateKit/CertificateAlgorithmLibrary/entry/src/main/ets/pages/CreateOnlineCheckIntermediateCertificateonlyObject.ets) -->

``` TypeScript

import { cert } from '@kit.DeviceCertificateKit';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  let arr: number[] = [];
  for (let i = 0, j = str.length; i < j; i++) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

async function createCertChain(certData: string): Promise<cert.X509CertChain> {
  // Certificate binary data, which needs to match your case.
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // Assign a value based on the encodingData format. FORMAT_PEM and FORMAT_DER are supported.
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

  let x509CertChain: cert.X509CertChain = {} as cert.X509CertChain;
  try {
    x509CertChain = await cert.createX509CertChain(encodingBlob);
  } catch (err) {
    console.error(`createCertChain failed: errCode: ${err.code}, message: ${err.message}`);
  }
  return x509CertChain;
}

async function createCert(certData: string): Promise<cert.X509Cert> {
  // Certificate binary data, which needs to match your case.
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
    // Assign a value based on the encodingData format. FORMAT_PEM and FORMAT_DER are supported.
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

  let x509Cert: cert.X509Cert = {} as cert.X509Cert;
  try {
    x509Cert = await cert.createX509Cert(encodingBlob);
  } catch (err) {
    console.error(`createCert failed: errCode: ${err.code}, message: ${err.message}`);
  }
  return x509Cert;
}

// ...
async function doTestCaCheck() {
  try {
    let x509CertChain: cert.X509CertChain = await createCertChain(caChain);
    let x509Cert: cert.X509Cert = await createCert(caTrustCert);
    const param: cert.CertChainValidationParameters = {
      trustAnchors: [{
        CACert: x509Cert
      }],
      revocationCheckParam: {
        options: [
          cert.RevocationCheckOptions.REVOCATION_CHECK_OPTION_ACCESS_NETWORK,
          cert.RevocationCheckOptions.REVOCATION_CHECK_OPTION_CHECK_INTERMEDIATE_CA_ONLINE
        ],
      }
    };
    await x509CertChain.validate(param);
    console.info(`validate result: success.`);
  } catch (error) {
    console.error(`x509CertChain validate failed: errCode: ${error.code}, message: ${error.message}`);
  }
}
```

## Ignoring the Network Unreachable Exception During Online Certificate Revocation Check in Certificate Chain Validation

Starting from API version 23, you can ignore the network unreachable exception during online certificate revocation check in certificate chain validation.

### How to Develop

1. Import the [certificate module](../../reference/apis-device-certificate-kit/js-apis-cert.md).

   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   ```

2. Call [cert.createX509CertChain](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509certchain11-2) to create a certificate chain object.

3. Call [cert.createX509Cert](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509cert) to create an X.509 certificate object. Construct the `cert.CertChainValidationParameters` certificate chain validation parameters, and set `revocationCheckParam` to `RevocationCheckOptions.REVOCATION_CHECK_OPTION_IGNORE_NETWORK_ERROR` to ignore the network unreachable scenario.

4. Call [cert.validate](../../reference/apis-device-certificate-kit/js-apis-cert.md#validate11) and pass the certificate chain verification parameters to verify the certificate chain.

Example:

<!-- @[ignore-network-unreachable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/DeviceCertificateKit/CertificateAlgorithmLibrary/entry/src/main/ets/pages/IgnoreNetworkUnreachable.ets) -->

``` TypeScript

import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

// Convert the string into a Uint8Array.
function stringToUint8Array(str: string): Uint8Array {
  const encoder = new util.TextEncoder();
  return encoder.encodeInto(str);
}
// ...
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

async function createX509CertChain(): Promise<cert.X509CertChain> {
  const root = await createX509Cert(rootCert);
  const intermediate = await createX509Cert(intermediateCert);
  const leaf = await createX509Cert(leafCert);
  let x509CertChain: cert.X509CertChain = {} as cert.X509CertChain;
  try {
    x509CertChain = cert.createX509CertChain([leaf, intermediate, root]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`createX509CertChain failed: errCode: ${e.code}, message: ${e.message}`);
  }
  return x509CertChain;
}

async function validateCRL() {
  const certChain = await createX509CertChain();
  console.info('createX509CertChain result: success.');
  const root = await createX509Cert(rootCert);
  // Certificate chain verification data, which needs to be assigned by the service.
  const param: cert.CertChainValidationParameters = {
    trustAnchors: [{ CACert: root }],
    revocationCheckParam: {
      options: [
        cert.RevocationCheckOptions.REVOCATION_CHECK_OPTION_IGNORE_NETWORK_ERROR,
        cert.RevocationCheckOptions.REVOCATION_CHECK_OPTION_ACCESS_NETWORK
      ],
    }
  }
  try {
    await certChain.validate(param);
    console.info('validateCRL result: success.');
  } catch (err) {
    console.error(`X509CertChain validate failed: errCode: ${err.code}, message: ${err.message}`);
  }
}
```