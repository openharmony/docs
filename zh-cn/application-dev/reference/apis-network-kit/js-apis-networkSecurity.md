# @ohos.net.networkSecurity (网络安全校验)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

本模块提供网络安全校验能力。应用可以通过证书校验API完成证书校验功能。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { networkSecurity } from '@kit.NetworkKit';
```

## 完整示例

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

| 名称  | 类型                   | 只读      |可选| 说明           |
| ----- | --------------------- | --------- | ----|---------- |
| type  | CertType              | 否    |否 |证书编码类型。  |
| data  | string \| ArrayBuffer | 否    | 否|证书内容。      |


## networkSecurity.certVerification

certVerification(cert: CertBlob, caCert?: CertBlob): Promise\<number\>

系统将使用证书管理中的预置CA证书和用户安装的CA证书来校验应用传入的证书。使用Promise异步回调。

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

以下错误码的详细介绍请参见[网络安全校验错误码](errorcode-net-networkSecurity.md)和[通用错误码](../errorcode-universal.md)。

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
| 2305018  | Self-signed certificate. <br>适用版本：12+ |
| 2305023  | Certificate has been revoked.                        |
| 2305024  | Invalid certificate authority (CA).                  |
| 2305027  | Certificate is untrusted.                            |
| 2305069  | Invalid certificate verification context. <br>适用版本：12+ |

> **说明：**
> 
> 这些错误代码对应于证书验证过程中的各种失败。

**示例：**

```ts
import { networkSecurity } from '@kit.NetworkKit';

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

系统将使用证书管理中的预置CA证书和用户安装的CA证书来校验应用传入的证书，使用同步方式返回。

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

以下错误码的详细介绍请参见[网络安全校验错误码](errorcode-net-networkSecurity.md)和[通用错误码](../errorcode-universal.md)。

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
| 2305018  | Self-signed certificate. <br>适用版本：12+ |
| 2305023  | Certificate has been revoked.                        |
| 2305024  | Invalid certificate authority (CA).                  |
| 2305027  | Certificate is untrusted.                            |
| 2305069  | Invalid certificate verification context. <br>适用版本：12+ |

> **说明：**
>
> 这些错误代码对应于证书验证过程中的各种失败。

**示例：**

```ts
import { networkSecurity } from '@kit.NetworkKit';

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

## networkSecurity.verifyCertChain

verifyCertChain(cert: CertBlob\[\], caCert?: CertBlob, hostname?: string): Promise\<CertBlob\[\]\>

传入证书链数组，进行证书链校验并构建排序后的证书链。系统将使用证书管理中的预置CA证书和用户安装的CA证书来配合校验传入的证书。使用promise异步回调。

**起始版本：** 26.0.0

**系统能力**：SystemCapability.Communication.NetStack

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名 | 类型     | 必填 | 说明                   |
| ------ | -------- | ---- | ---------------------- |
| cert   | [CertBlob](#certblob)\[\] | 是   | 待校验证书数组。第一个元素必须是叶子证书（end-entity certificate），其余元素为中间证书。 |
| caCert | [CertBlob](#certblob) | 否   | 传入自定义的CA证书。不传入则使用系统预置CA证书。 |
| hostname | string | 否   | 需要验证的主机名，用于校验证书中的主机名是否匹配。不传入则跳过主机名验证。 |

**返回值：**

| 类型            | 说明                                                         |
| --------------- | ------------------------------------------------------------ |
| Promise\<[CertBlob](#certblob)\[\]\> | 以promise形式返回排序后的证书链数组，顺序为从叶子节点到根节点。 |

**错误码：**

以下错误码的详细介绍请参见[网络安全校验错误码](errorcode-net-networkSecurity.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 2305001  | Unspecified error.                                   |
| 2305002  | Unable to get issuer certificate.                    |
| 2305004  | Unable to decrypt certificate signature.             |
| 2305006  | Unable to decode issuer public key.                  |
| 2305007  | Certificate signature failure.                       |
| 2305009  | Certificate is not yet valid.                        |
| 2305010  | Certificate has expired.                             |
| 2305018  | Self-signed certificate.                             |
| 2305024  | Invalid certificate authority (CA).                  |
| 2305027  | Certificate is untrusted.                            |
| 2305062  | Invalid hostname.                                    |
| 2305069  | Invalid certificate verification context.            |

> **说明：**
> 
> 这些错误代码对应于证书验证过程中的各种失败。

**示例：**

```ts
import { networkSecurity } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Define certificate blobs
const cert1: networkSecurity.CertBlob = {
  type: networkSecurity.CertType.CERT_TYPE_PEM,
  data: '-----BEGIN CERTIFICATE-----\n... (server certificate) ...\n-----END CERTIFICATE-----',
};

const cert2: networkSecurity.CertBlob = {
  type: networkSecurity.CertType.CERT_TYPE_PEM,
  data: '-----BEGIN CERTIFICATE-----\n... (intermediate certificate) ...\n-----END CERTIFICATE-----',
};

const caCert: networkSecurity.CertBlob = {
  type: networkSecurity.CertType.CERT_TYPE_PEM,
  data: '-----BEGIN CERTIFICATE-----\n... (CA certificate) ...\n-----END CERTIFICATE-----',
};

// Verify and build sorted cert chain
networkSecurity.verifyCertChain([cert1, cert2], caCert, "example.com")
  .then((sortedChain: Array<networkSecurity.CertBlob>) => {
    console.info('Certificate chain verified and sorted, chain length:', sortedChain.length);
    for (let i = 0; i < sortedChain.length; i++) {
      console.info(`Certificate ${i}: type=${sortedChain[i].type}, data=${sortedChain[i].data}`);
    }
  })
  .catch((error: BusinessError) => {
    console.error('Certificate chain verification failed:', error);
  });
```
> **注意**：
> 
> 请务必将示例中的证书数据替换为实际的证书内容。

## networkSecurity.isCleartextPermitted<sup>18+</sup>

isCleartextPermitted(): boolean

从应用预置network_config.json文件中获取整体明文HTTP是否允许信息，默认允许明文HTTP访问。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| boolean | 整体明文HTTP是否允许。返回true表示允许访问明文HTTP，false表示不允许。默认返回true。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission denied.                                  |

**示例：**

```ts
import { networkSecurity } from '@kit.NetworkKit';

try {
  let result: boolean = networkSecurity.isCleartextPermitted();
  console.info(`isCleartextPermitted Result: ${JSON.stringify(result)}`);
} catch (error) {
  console.error(`isCleartextPermitted Error: ${JSON.stringify(error)}`);
}
```

## networkSecurity.isCleartextPermittedByHostName<sup>18+</sup>

isCleartextPermittedByHostName(hostName: string): boolean

从应用预置network_config.json文件中获取按域名明文HTTP是否允许信息，默认允许明文HTTP访问。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数**：

| 参数名 | 类型     | 必填 | 说明                   |
| ------ | -------- | ---- | ---------------------- |
| hostName | string | 是  | 需要查询的主机名。|

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| boolean | 按域名明文HTTP是否允许。返回true表示允许明文HTTP访问该主机，false表示不允许。默认返回true。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission denied.                                     |

**示例：**

```ts
import { networkSecurity } from '@kit.NetworkKit';

try {
  let result: boolean = networkSecurity.isCleartextPermittedByHostName("xxx");
  console.info(`isCleartextPermitted Result: ${JSON.stringify(result)}`);
} catch (error) {
  console.error(`isCleartextPermitted Error: ${JSON.stringify(error)}`);
}
```