# @ohos.net.networkSecurity (Network Security)

The **networkSecurity** module provides the network security verification capability. Specifically, it provides APIs for applications to verify the certificates in use.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { networkSecurity } from '@kit.NetworkKit';
```

## Sample Code

```ts
import { networkSecurity } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Define certificate blobs
const cert: networkSecurity.CertBlob = {
  type: networkSecurity.CertType.CERT_TYPE_PEM,
  data: '-----BEGIN CERTIFICATE-----\n... (certificate data) ...\n-----END CERTIFICATE-----',
};

const caCert: networkSecurity.CertBlob = {
  type: networkSecurity.CertType.CERT_TYPE_PEM,
  data: '-----BEGIN CERTIFICATE-----\n... (CA certificate data) ...\n-----END CERTIFICATE-----',
};

// Perform asynchronous certificate verification
networkSecurity.certVerification(cert, caCert)
  .then((result) => {
    console.info('Certificate verification result:', result);
  })
  .catch((error: BusinessError) => {
    console.error('Certificate verification failed:', error);
  });
```

> **NOTE**
> 
> Be sure to replace the certificate data in the example with the actual certificate data.

## CertType

Enumerates certificate types.

**System capability**: SystemCapability.Communication.NetStack

| Name         | Value   |      Description    |
| ------------- | ----- | ------------- |
| CERT_TYPE_PEM | 0     | PEM certificate|
| CERT_TYPE_DER | 1     | DER certificate.|


## CertBlob

Defines the certificate data.

**System capability**: SystemCapability.Communication.NetStack

| Name | Type                  | Mandatory     | Description          |
| ----- | --------------------- | --------- | -------------- |
| type  | CertType              | Yes     | Certificate type. |
| data  | string \| ArrayBuffer | Yes      | Certificate data.     |


## networkSecurity.certVerification

certVerification(cert: CertBlob, caCert?: CertBlob): Promise\<number\>

Obtains the preset CA certificate and custom CA certificate from the certificate management module, and verifies the certificate passed by the application.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name| Type    | Mandatory| Description                  |
| ------ | -------- | ---- | ---------------------- |
| cert   | CertBlob | Yes  | Certificate to be verified.      |
| caCert | CertBlob | No  | Custom CA certificate.|

**Return values:**

| Type           | Description                                                        |
| --------------- | ------------------------------------------------------------ |
| Promise\<number\> | Promise used to return the result. The value **0** indicates that the certificate verification is successful, and a non-0 value indicates that the verification has failed.|

**Error codes**

For details about the error codes, see [Network Security Error Codes](errorcode-net-networkSecurity.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 401      | Parameter error.                                     |
| 2305001  | Unspecified error.                                   |
| 2305002  | Unable to get issuer certificate.                    |
| 2305003  | Unable to get certificate revocation list (CRL).     |
| 2305004  | Unable to decrypt certificate signature.             |
| 2305005  | Unable to decrypt CRL signature.                     |
| 2305006  | Unable to decode issuer public key.                  |
| 2305007  | Certificate signature failure.                       |
| 2305008  | CRL signature failure.                               |
| 2305009  | Certificate is not yet valid.                        |
| 2305010  | Certificate has expired.                             |
| 2305011  | CRL is not yet valid.                                |
| 2305012  | CRL has expired.                                     |
| 2305018  | Self-signed certificate.                             |
| 2305023  | Certificate has been revoked.                        |
| 2305024  | Invalid certificate authority (CA).                  |
| 2305027  | Certificate is untrusted.                            |
| 2305069  | Invalid certificate verification context.            |

> **NOTE**
> 
> The preceding error codes indicate errors that may occur during certificate verification.

**Example**

```ts
import { networkSecurity } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Define certificate blobs
const cert:networkSecurity.CertBlob = {
  type: networkSecurity.CertType.CERT_TYPE_PEM,
  data: '-----BEGIN CERTIFICATE-----\n... (certificate data) ...\n-----END CERTIFICATE-----',
};

const caCert:networkSecurity.CertBlob = {
  type: networkSecurity.CertType.CERT_TYPE_PEM,
  data: '-----BEGIN CERTIFICATE-----\n... (CA certificate data) ...\n-----END CERTIFICATE-----',
};

// Perform asynchronous certificate verification
networkSecurity.certVerification(cert, caCert)
  .then((result) => {
    console.info('Certificate verification result:', result);
  })
  .catch((error: BusinessError) => {
    console.error('Certificate verification failed:', error);
  });
```
> **NOTE**
> 
> Be sure to replace the certificate data in the example with the actual certificate data.



## networkSecurity.certVerificationSync

certVerificationSync(cert: CertBlob, caCert?: CertBlob): number

Obtains the preset CA certificate and custom CA certificate from the certificate management module, and verifies the certificate passed by the application.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name| Type    | Mandatory| Description                  |
| ------ | -------- | ---- | ---------------------- |
| cert   | CertBlob | Yes | Certificate to be verified.      |
| caCert | CertBlob | No  | Custom CA certificate.|

**Return values:**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| number | Certificate verification result. The value **0** indicates that the certificate verification is successful, and a non-0 value indicates that the verification has failed.|

**Error codes**

For details about the error codes, see [Network Security Error Codes](errorcode-net-networkSecurity.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 401      | Parameter error.                                     |
| 2305001  | Unspecified error.                                   |
| 2305002  | Unable to get issuer certificate.                    |
| 2305003  | Unable to get certificate revocation list (CRL).     |
| 2305004  | Unable to decrypt certificate signature.             |
| 2305005  | Unable to decrypt CRL signature.                     |
| 2305006  | Unable to decode issuer public key.                  |
| 2305007  | Certificate signature failure.                       |
| 2305008  | CRL signature failure.                               |
| 2305009  | Certificate is not yet valid.                        |
| 2305010  | Certificate has expired.                             |
| 2305011  | CRL is not yet valid.                                |
| 2305012  | CRL has expired.                                     |
| 2305018  | Self-signed certificate.                             |
| 2305023  | Certificate has been revoked.                        |
| 2305024  | Invalid certificate authority (CA).                  |
| 2305027  | Certificate is untrusted.                            |
| 2305069  | Invalid certificate verification context.            |

> **NOTE**
>
> The preceding error codes indicate errors that may occur during certificate verification.

**Example**

```ts
import { networkSecurity } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Create certificate blobs
const cert: networkSecurity.CertBlob = {
  type: networkSecurity.CertType.CERT_TYPE_PEM,
  data: '-----BEGIN CERTIFICATE-----\n...'
};

const caCert: networkSecurity.CertBlob = {
  type: networkSecurity.CertType.CERT_TYPE_PEM,
  data: '-----BEGIN CERTIFICATE-----\n...'
};

// Asynchronous verification
networkSecurity.certVerification(cert, caCert)
  .then((result) => {
    console.info('Verification Result:', result);
  })
  .catch((error: BusinessError) => {
    console.error('Verification Error:', error);
  });

// Synchronous verification
let resultSync: number = networkSecurity.certVerificationSync(cert, caCert);
console.info('Synchronous Verification Result:', resultSync);
```

> **NOTE**
>
> Be sure to replace the certificate data in the example with the actual certificate data.

## networkSecurity.isCleartextPermitted<sup>18+</sup>

isCleartextPermitted(): boolean

Checks whether plaintext HTTP access is allowed from the preset **network_config.json** file of the application. By default, plaintext HTTP access is allowed.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return values:**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| boolean | Boolean value indicating whether plaintext HTTP is allowed. The value **true** indicates that plaintext HTTP is allowed, and the value **false** indicates the opposite. The default value is **true**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 201      | Permission denied.                                  |

**Example**

```ts
import { networkSecurity } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let result: boolean = networkSecurity.isCleartextPermitted();
  console.info(`isCleartextPermitted Result: ${JSON.stringify(result)}`);
} catch (error) {
  console.error(`isCleartextPermitted Error: ${JSON.stringify(error)}`);
}
```

## networkSecurity.isCleartextPermittedByHostName<sup>18+</sup>

isCleartextPermittedByHostName(hostName: string): boolean

Checks whether host name–based plaintext HTTP access is allowed from the preset **network_config.json** file of the application. By default, plaintext HTTP access is allowed.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name| Type    | Mandatory| Description                  |
| ------ | -------- | ---- | ---------------------- |
| hostName | string | Yes | Host name.|

**Return values:**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| boolean | Boolean value indicating whether host name–based plaintext HTTP is allowed. The value **true** indicates that plaintext HTTP is allowed, and the value **false** indicates the opposite. The default value is **true**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 201      | Permission denied.                                     |

**Example**

```ts
import { networkSecurity } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let result: boolean = networkSecurity.isCleartextPermittedByHostName("xxx");
  console.info(`isCleartextPermitted Result: ${JSON.stringify(result)}`);
} catch (error) {
  console.error(`isCleartextPermitted Error: ${JSON.stringify(error)}`);
}
```
