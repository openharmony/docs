# @ohos.net.networkSecurity (Network Security)

The networkSecurity module provides network security verification capabilities. The application can complete the certificate chain verification function through the certificate chain verification API.

> **NOTE**
>
> This module requires the system capability `SystemCapability.Communication.NetStack` and is available since API version 11.

## Modules to Import

```ts
import networkSecurity from '@ohos.net.networkSecurity';
```

## Examples

```ts
import networkSecurity from '@ohos.net.networkSecurity';

// Define certificate blobs
const cert = {
  type: networkSecurity.CertType.CERT_TYPE_PEM,
  data: '-----BEGIN CERTIFICATE-----\n... (certificate data) ...\n-----END CERTIFICATE-----',
};

const caCert = {
  type: networkSecurity.CertType.CERT_TYPE_PEM,
  data: '-----BEGIN CERTIFICATE-----\n... (CA certificate data) ...\n-----END CERTIFICATE-----',
};

// Perform asynchronous certificate verification
networkSecurity.certVerification(cert, caCert)
  .then((result) => {
    console.info('Certificate verification result:', result);
  })
  .catch((error) => {
    console.error('Certificate verification failed:', error);
  });
```
> **NOTE**
> Make sure to replace the certificate data in the example with the actual certificate content.


## CertType

Defines the type of certificates.

**System capability**: SystemCapability.Communication.NetStack

| Name           | Value | Description              |
| -------------- | ----- | ------------------------ |
| CERT_TYPE_PEM  | 0     | PEM type certificate.    |
| CERT_TYPE_DER  | 1     | DER type certificate.    |



## CertBlob

Defines the structure of certificate data. 

**System capability**: SystemCapability.Communication.NetStack

| Name  | Type                | Mandatory | Description                               |
| ----- | ------------------- | --------- | ----------------------------------------- |
| type  | CertType            | Yes       | Certificate type (PEM or DER).            |
| data  | string \| ArrayBuffer | Yes       | Certificate data as a string or ArrayBuffer. |



## networkSecurity.certVerification

function certVerification(cert: CertBlob, caCert?: CertBlob): Promise<number>

Obtain the system-preset CA certificate and the user-installed CA certificate from the certificate management, and verify the certificate chain passed in by the application.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name   | Type     | Mandatory | Description                  |
| ------ | -------- | --------- | ---------------------------- |
| cert   | CertBlob | Yes       | Certificates to be verified. |
| caCert | CertBlob | No        | Incoming custom CA cert.     |

**Return value**

| Type            | Description                                                  |
| --------------- | ------------------------------------------------------------ |
| Promise<number> | A promise that resolves to a number indicating the result of certificate verification.<br />Returns 0 if the verification of the certificate succeeds; otherwise, verification failed. |

**Error codes**

| ID      | Error Message                                   |
| ------- | ----------------------------------------------- |
| 2305001 | Unspecified error.                              |
| 2305002 | Unable to get issuer certificate.                |
| 2305003 | Unable to get the certificate revocation list (CRL). |
| 2305004 | Unable to decrypt the certificate signature.    |
| 2305005 | Unable to decrypt the CRL signature.            |
| 2305006 | Unable to decode the issuer's public key.       |
| 2305007 | Certificate signature failure.                  |
| 2305008 | CRL signature failure.                          |
| 2305009 | Certificate is not yet valid.                   |
| 2305010 | Certificate has expired.                        |
| 2305011 | CRL is not yet valid.                           |
| 2305012 | CRL has expired.                                |
| 2305023 | Certificate has been revoked.                   |
| 2305024 | Invalid certificate authority (CA).            |
| 2305027 | Certificate is untrusted.                       |

> **NOTE**
> These error codes correspond to various failures during the certificate verification process, providing detailed information about the encountered issues.

**Example**

```ts
import networkSecurity from '@ohos.net.networkSecurity';

// Define certificate blobs
const cert = {
  type: networkSecurity.CertType.CERT_TYPE_PEM,
  data: '-----BEGIN CERTIFICATE-----\n... (certificate data) ...\n-----END CERTIFICATE-----',
};

const caCert = {
  type: networkSecurity.CertType.CERT_TYPE_PEM,
  data: '-----BEGIN CERTIFICATE-----\n... (CA certificate data) ...\n-----END CERTIFICATE-----',
};

// Perform asynchronous certificate verification
networkSecurity.certVerification(cert, caCert)
  .then((result) => {
    console.info('Certificate verification result:', result);
  })
  .catch((error) => {
    console.error('Certificate verification failed:', error);
  });
```
> **NOTE**
> Make sure to replace the certificate data in the example with the actual certificate content.


## networkSecurity.certVerificationSync

function certVerificationSync(cert: CertBlob, caCert?: CertBlob): number

Obtain the system-preset CA certificate and the user-installed CA certificate from the certificate management, and verify the certificate chain passed in by the application.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name   | Type     | Mandatory | Description                  |
| ------ | -------- | --------- | ---------------------------- |
| cert   | CertBlob | Yes       | Certificates to be verified. |
| caCert | CertBlob | No        | Incoming custom CA cert.     |

**Return value**

| Type   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| number | Returns 0 if the verification of the certificate succeeds; otherwise, verification failed. |

**Error codes**

| ID      | Error Message                                        |
| ------- | ---------------------------------------------------- |
| 2305001 | Unspecified error.                                   |
| 2305002 | Unable to get issuer certificate.                    |
| 2305003 | Unable to get the certificate revocation list (CRL). |
| 2305004 | Unable to decrypt the certificate signature.         |
| 2305005 | Unable to decrypt the CRL signature.                 |
| 2305006 | Unable to decode the issuer's public key.            |
| 2305007 | Certificate signature failure.                       |
| 2305008 | CRL signature failure.                               |
| 2305009 | Certificate is not yet valid.                        |
| 2305010 | Certificate has expired.                             |
| 2305011 | CRL is not yet valid.                                |
| 2305012 | CRL has expired.                                     |
| 2305023 | Certificate has been revoked.                        |
| 2305024 | Invalid certificate authority (CA).                  |
| 2305027 | Certificate is untrusted.                            |

> **NOTE**
> These error codes correspond to various failures during the certificate verification process, providing detailed information about the encountered issues.

**Example**

```ts
import networkSecurity from '@ohos.net.networkSecurity';

// Create certificate blobs
const cert: networkSecurity.CertBlob = {
  type: networkSecurity.CertType.CERT_TYPE_PEM,
  data: '-----BEGIN CERTIFICATE-----\n...'
};

const caCert: networkSecurity.CertBlob = {
  type: networkSecurity.CertType.CERT_TYPE_PEM,
  data: '-----BEGIN CERTIFICATE-----\n...'
};

// Synchronous verification
const resultSync = networkSecurity.certVerificationSync(cert, caCert);
console.info('Synchronous Verification Result:', resultSync);
```

> **NOTE**
> Make sure to replace the certificate data in the example with the actual certificate content.
