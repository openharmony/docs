# @ohos.net.networkSecurity (Network Security)

本模块提供网络安全校验能力。应用可以通过证书校验API完成证书校验功能。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { networkSecurity } from '@kit.NetworkKit';
```

## 完整实例

```ts
import { networkSecurity } from '@kit.NetworkKit';

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

> **注意**：
> 
> 请务必将示例中的证书数据替换为实际的证书内容。

## CertType

证书编码类型。

**系统能力**: SystemCapability.Communication.NetStack

| 名称          | 值    |      说明     |
| ------------- | ----- | ------------- |
| CERT_TYPE_PEM | 0     | PEM格式证书。 |
| CERT_TYPE_DER | 1     | DER格式证书。 |


## CertBlob

证书数据。 

**系统能力**: SystemCapability.Communication.NetStack

| 名称  | 类型                   | 必填      | 说明           |
| ----- | --------------------- | --------- | -------------- |
| type  | CertType              | 是      | 证书编码类型。  |
| data  | string \| ArrayBuffer | 是       | 证书内容。      |


## networkSecurity.certVerification

certVerification(cert: CertBlob, caCert?: CertBlob): Promise\<number\>

从证书管理获取系统预置的CA证书和用户安装的CA证书，对应用传入的证书进行校验。

**系统能力**: SystemCapability.Communication.NetStack

**参数**

| 参数名 | 类型     | 必填 | 说明                   |
| ------ | -------- | ---- | ---------------------- |
| cert   | CertBlob | 是   | 被校验的证书。       |
| caCert | CertBlob | 否   | 传入自定义的CA证书。 |

**返回值：**

| 类型            | 说明                                                         |
| --------------- | ------------------------------------------------------------ |
| Promise\<number\> | 以promise形式返回一个数字，表示证书验证的结果。如果证书验证成功，则返回0； 否则验证失败。 |

**错误码：**

| 错误码ID | 错误信息                                             |
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

> **说明：**
> 
> 这些错误代码对应于证书验证过程中的各种失败，提供有关所遇到问题的详细信息。

**示例：**

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
> **注意**：
> 
> 请务必将示例中的证书数据替换为实际的证书内容。



## networkSecurity.certVerificationSync

certVerificationSync(cert: CertBlob, caCert?: CertBlob): number

从证书管理获取系统预置的CA证书和用户安装的CA证书，对应用传入的证书进行校验。

**系统能力**：SystemCapability.Communication.NetStack

**参数**：

| 参数名 | 类型     | 必填 | 说明                   |
| ------ | -------- | ---- | ---------------------- |
| cert   | CertBlob | 是  | 被校验的证书。       |
| caCert | CertBlob | 否   | 传入自定义的CA证书。 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 表示证书验证的结果。如果证书验证成功，则返回0； 否则验证失败。 |

**错误码：**

| 错误码ID | 错误信息                                             |
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

> **说明：**
>
> 这些错误代码对应于证书验证过程中的各种失败，提供有关所遇到问题的详细信息。

**示例：**

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

> **注意**：
>
> 请务必将示例中的证书数据替换为实际的证书内容。
