# Building and Verifying a Certificate Chain

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=108cfcdbfe0194d8e3c64ec5128e21493da21f53 translatedAt=2026-08-11T01:57:07.985Z pushedAt=2026-08-11T02:39:57.349Z -->

Since API version 26.0.0, the certificate chain validator provides the capabilities of building and verifying a certificate chain. It supports building and verifying a certificate chain through [CertValidationParams](../../reference/apis-device-certificate-kit/js-apis-cert.md#certvalidationparams), including trust anchor setting, certificate revocation check, and date verification.

## Development Procedure

1. Import [@ohos.security.cert](../../reference/apis-device-certificate-kit/js-apis-cert.md).

   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   ```

2. Create the [X509Cert](../../reference/apis-device-certificate-kit/js-apis-cert.md#x509cert) certificate object to be verified based on the existing certificate data.

3. Call [cert.createCertChainValidator](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatecertchainvalidator) to create a certificate chain validator object.

4. Create a [CertValidationParams](../../reference/apis-device-certificate-kit/js-apis-cert.md#certvalidationparams) validation parameter object.

5. Call the [validateCert(cert: X509Cert, params: CertValidationParams): Promise&lt;CertValidationResult&gt;](../../reference/apis-device-certificate-kit/js-apis-cert.md#validatecert) API to build and verify the certificate chain. The certificate chain [CertValidationResult](../../reference/apis-device-certificate-kit/js-apis-cert.md#certvalidationresult) that passes the verification is returned.

## Scenario 1: Specifying a Trust Certificate

If the application has a custom trust anchor certificate, you can use the [trustedCerts](../../reference/apis-device-certificate-kit/js-apis-cert.md#certvalidationparams) parameter to specify the trusted CA certificate.

<!-- @[certificate_chain_validation_with_custom_trust_anchor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/DeviceCertificateKit/CertificateAlgorithmLibrary/entry/src/main/ets/pages/ValidateCertChainWithCustomTrustAnchor.ets) -->

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
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
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

async function validateCertChainWithCustomTrustAnchor(): Promise<void> {
  try {
    // Add a certificate object.
    let endEntityCert = await createX509Cert(endEntityCertData);
    let intermediateCaCert = await createX509Cert(intermediateCaCertData);
    let rootCaCert = await createX509Cert(rootCaCertData);

    // Construct verification parameters.
    let params: cert.CertValidationParams = {
      // Untrusted certificates used only for building a certificate chain.
      untrustedCerts: [intermediateCaCert],
      // Trust anchor certificate used to verify the certificate chain.
      trustedCerts: [rootCaCert],
      // Do not trust the CA certificates preset in the system.
      trustSystemCa: false,
      date: '20260422121212Z'
    };
    // Create a certificate chain validator instance.
    let validator = cert.createCertChainValidator('PKIX');

    // Verify endEntityCert.
    let result: cert.CertValidationResult = await validator.validateCert(endEntityCert, params);
    console.info('validate success, certChain length: ' + result.certChain.length);
    for (let i = 0; i < result.certChain.length; i++) {
      let subject = result.certChain[i].getSubjectX500DistinguishedName().getName(cert.EncodingType.ENCODING_UTF8);
      console.info(`Cert ${i} subject: ${subject}`);
    }
  } catch (err) {
    // Validation failed.
    let error = err as BusinessError;
    console.error('validate failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    throw new Error(error.message)
  }
}
```

## Scenario 2: Trusting the CA Certificates Preset in the System

When an application needs to verify an Internet public certificate (such as an HTTPS website certificate), it can use the system's built-in CA certificate as a trust anchor. By setting [trustSystemCa](../../reference/apis-device-certificate-kit/js-apis-cert.md#certvalidationparams) to **true**, the validator will use the system's built-in CA certificate store to build and verify the certificate chain.

<!-- @[certificate_chain_validation_with_system_ca](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/DeviceCertificateKit/CertificateAlgorithmLibrary/entry/src/main/ets/pages/ValidateCertChainWithSystemCa.ets) -->

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
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
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

async function validateCertChainWithSystemCa(): Promise<void> {
  try {
    // Add a certificate object.
    let endEntityCert = await createX509Cert(endEntityCertData);
    let intermediateCaCert = await createX509Cert(intermediateCaCertData);

    // Construct verification parameters.
    let params: cert.CertValidationParams = {
      // Untrusted certificates used only for building a certificate chain.
      untrustedCerts: [intermediateCaCert],
      // Trust the CA certificates preset in the system.
      trustSystemCa: true,
      // Ignore certificate expiration or invalidity.
      ignoreErrs: [cert.CertResult.ERR_CERT_HAS_EXPIRED, cert.CertResult.ERR_CERT_NOT_YET_VALID],
    };

    // Create a certificate chain validator instance.
    let validator = cert.createCertChainValidator('PKIX');

    // Verify endEntityCert.
    let result: cert.CertValidationResult = await validator.validateCert(endEntityCert, params);
    console.info('validate success, certChain length: ' + result.certChain.length);
    for (let i = 0; i < result.certChain.length; i++) {
      let subject = result.certChain[i].getSubjectX500DistinguishedName().getName(cert.EncodingType.ENCODING_UTF8);
      console.info(`Cert ${i} subject: ${subject}`);
    }
  } catch (err) {
    let error = err as BusinessError;
    console.error('validate failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    throw new Error(error.message)
  }
}
```

## Scenario 3: Verifying Certificate Revocation (CRL)

You can specify a CRL using the [crls](../../reference/apis-device-certificate-kit/js-apis-cert.md#x509certrevokedparams) parameter to check whether a certificate has been revoked.

<!-- @[certificate_chain_validation_with_crl](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/DeviceCertificateKit/CertificateAlgorithmLibrary/entry/src/main/ets/pages/ValidateCertChainWithCrl.ets) -->

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
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
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

async function createX509CRL(crlDataStr: string): Promise<cert.X509CRL> {
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(crlDataStr),
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };

  let x509CRL: cert.X509CRL = {} as cert.X509CRL;
  try {
    x509CRL = await cert.createX509CRL(encodingBlob);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`createX509CRL failed: errCode: ${e.code}, message: ${e.message}`);
  }
  return x509CRL;
}

async function validateCertChainWithCrl(): Promise<void> {
  try {
    // Add a certificate object.
    let endEntityCert = await createX509Cert(endEntityCertData);
    let intermediateCaCert = await createX509Cert(intermediateCaCertData);
    let rootCaCert = await createX509Cert(rootCaCertData);

    // Create a CRL object.
    let crl = await createX509CRL(crlData);

    // Construct revocation verification parameters.
    let revokedParams: cert.X509CertRevokedParams = {
      // Enable CRL check.
      revocationFlags: [cert.CertRevocationFlag.CERT_REVOCATION_CRL_CHECK],
      // Provide the CRL.
      crls: [crl]
    };

    // Construct verification parameters.
    let params: cert.CertValidationParams = {
      untrustedCerts: [intermediateCaCert],
      trustedCerts: [rootCaCert],
      trustSystemCa: false,
      // Do not verify the certificate validity period. (This is only an example. You are advised to enable the verification in actual scenarios.)
      validateDate: false,
      // Set revocation verification parameters.
      revokedParams: revokedParams,
    };

    // Create a certificate chain validator instance.
    let validator = cert.createCertChainValidator('PKIX');

    // Verify endEntityCert.
    let result: cert.CertValidationResult = await validator.validateCert(endEntityCert, params);
    console.info('validate success, certChain length: ' + result.certChain.length);
    for (let i = 0; i < result.certChain.length; i++) {
      let subject = result.certChain[i].getSubjectX500DistinguishedName().getName(cert.EncodingType.ENCODING_UTF8);
      console.info(`Cert ${i} subject: ${subject}`);
    }
  } catch (err) {
    let error = err as BusinessError;
    if (error.code === cert.CertResult.ERR_CERT_HAS_REVOKED) {
      console.error('certificate has been revoked');
    } else {
      console.error('validate failed, errCode: ' + error.code + ', errMsg: ' + error.message);
      throw new Error(error.message)
    }
  }
}
```

## Scenario 4: Verifying the SM Certificate Chain

To verify the SM2 certificate chain, you need to set the [userId](../../reference/apis-device-certificate-kit/js-apis-cert.md#certvalidationparams) parameter.

<!-- @[certificate_chain_validation_for_sm2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/DeviceCertificateKit/CertificateAlgorithmLibrary/entry/src/main/ets/pages/ValidateSm2CertChain.ets) -->

``` TypeScript

import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

function stringToUint8Array(str: string): Uint8Array {
  const encoder = new util.TextEncoder();
  return encoder.encodeInto(str);
}

// ...

async function createX509Cert(certData: string): Promise<cert.X509Cert> {
  let encodingBlob: cert.EncodingBlob = {
    data: stringToUint8Array(certData),
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

async function validateSm2CertChain(): Promise<void> {
  try {
    let sm2EndEntityCert = await createX509Cert(sm2EndEntityCertData);
    let sm2IntermediateCaCert = await createX509Cert(sm2IntermediateCaCertData);
    let sm2RootCaCert = await createX509Cert(sm2RootCaCertData);

    let userId = new Uint8Array([
      0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38,
      0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38
    ]);

    let params: cert.CertValidationParams = {
      // Untrusted certificates used only for building a certificate chain.
      untrustedCerts: [sm2IntermediateCaCert],
      // Trust anchor certificate used to verify the certificate chain.
      trustedCerts: [sm2RootCaCert],
      // Do not verify the certificate validity period. (This is only an example. You are advised to enable the verification in actual scenarios.)
      validateDate: false,
      // User ID used for SM2 signature verification.
      userId: userId
    };
    // Create a certificate chain validator instance.
    let validator = cert.createCertChainValidator('PKIX');

    // Verify the sm2EndEntityCert certificate.
    let result: cert.CertValidationResult = await validator.validateCert(sm2EndEntityCert, params);
    console.info('validate success, certChain length: ' + result.certChain.length);
    for (let i = 0; i < result.certChain.length; i++) {
      let subject = result.certChain[i].getSubjectX500DistinguishedName().getName(cert.EncodingType.ENCODING_UTF8);
      console.info(`Cert ${i} subject: ${subject}`);
      let alg = result.certChain[i].getSignatureAlgName()
      console.info(`Cert ${i} Signature Algorithm: ${alg}`);
    }
  } catch (err) {
    let error = err as BusinessError;
    console.error('validate failed, errCode: ' + error.code + ', errMsg: ' + error.message);
    throw new Error(error.message)
  }
}
```