# @ohos.security.certManager (证书管理模块)

证书管理主要提供系统级的证书管理能力，实现证书全生命周期（安装，存储，使用，销毁）的管理和安全使用 。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import certManager from '@ohos.security.certManager';
```

## CmKeyPurpose

表示密钥使用目的的枚举，用于签名、验签。

**系统能力：** SystemCapability.Security.CertificateManager

| 名称       | 值 |  说明      |
| ---------- | ------ | --------- |
| CM_KEY_PURPOSE_SIGN | 4      | 签名 |
| CM_KEY_PURPOSE_VERIFY | 8      | 验签 |

## CmKeyDigest

表示签名、验签使用的摘要算法的枚举。

**系统能力：** SystemCapability.Security.CertificateManager

| 名称       | 值 |  说明      |
| ---------- | ------ | --------- |
| CM_DIGEST_NONE | 0      | 不需要摘要算法，选用此项时，需要业务传入已经计算过摘要的数据进行签名、验签。 |
| CM_DIGEST_MD5 | 1      | MD5摘要算法。 |
| CM_DIGEST_SHA1 | 2      | SHA1摘要算法。 |
| CM_DIGEST_SHA224 | 3      | SHA224摘要算法。 |
| CM_DIGEST_SHA256 | 4      | SHA256摘要算法。 |
| CM_DIGEST_SHA384 | 5      | SHA384摘要算法。 |
| CM_DIGEST_SHA512 | 6      | SHA512摘要算法。 |

## CmKeyPadding

表示签名、验签使用的填充方式的枚举。

**系统能力：** SystemCapability.Security.CertificateManager

| 名称       | 值 |  说明      |
| ---------- | ------ | --------- |
| CM_PADDING_NONE | 0      | 无填充。 |
| CM_PADDING_PSS | 1      | PSS方式填充。 |
| CM_PADDING_PKCS1_V1_5 | 2      | PKCS1_V1_5方式填充。 |

## CMSignatureSpec

表示签名、验签操作使用的参数集合，包括密钥使用目的、填充方式和摘要算法。

**系统能力：** SystemCapability.Security.CertificateManager

| 名称           | 类型                              | 必填 | 说明                                                         |
| -------------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| purpose          | [CmKeyPurpose](#cmkeypurpose)                       | 是   | 表示密钥使用目的的枚举。 |
| padding?        | [CmKeyPadding](#cmkeypadding)                       | 否   | 表示填充方式的枚举。 |
| digest?        | [CmKeyDigest](#cmkeydigest)                       | 否   | 表示摘要算法的枚举。 |


## CertInfo

表示证书详细信息。

**系统能力：** SystemCapability.Security.CertificateManager

| 名称           | 类型                              | 可读 | 可写 | 说明                                                         |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| uri          | string         | 是   | 是   | 表示证书的唯一标识符。 |
| certAlias          | string   | 是   | 是   | 表示证书的别名。 |
| state          | boolean     | 是   | 是   | 表示证书的状态，true为启用状态、false为禁用状态。 |
| issuerName          | string         | 是   | 是   | 表示证书的颁发者名称。 |
| subjectName          | string   | 是   | 是   | 表示证书的使用者名称。 |
| serial          | string     | 是   | 是   | 表示证书的序列号。 |
| notBefore          | string         | 是   | 是   | 表示证书有效期起始日期。 |
| notAfter          | string   | 是   | 是   | 表示证书有效期截止日期。 |
| fingerprintSha256     | string     | 是   | 是   | 表示证书的指纹值。 |
| cert          | Uint8Array         | 是   | 是   | 表示证书二进制数据。 |

## CertAbstract

表示证书简要信息。

**系统能力：** SystemCapability.Security.CertificateManager

| 名称           | 类型                              | 可读 | 可写 | 说明                                                         |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| uri          | string         | 是   | 是   | 表示证书的唯一标识符。 |
| certAlias          | string   | 是   | 是   | 表示证书的别名。 |
| state          | boolean     | 是   | 是   | 表示证书的状态，true为启用状态、false为禁用状态。 |
| issuerName          | string         | 是   | 是   | 表示证书的颁发者名称。 |
| subjectName          | string   | 是   | 是   | 表示证书的使用者名称。 |

## Credential

表示凭据详细信息。

**系统能力：** SystemCapability.Security.CertificateManager

| 名称           | 类型                              | 可读 | 可写 | 说明                                                         |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type          | string         | 是   | 是   | 表示凭据的类型。 |
| alias          | string   | 是   | 是   | 表示凭据的别名。 |
| keyUri          | string     | 是   | 是   | 表示凭据的唯一标识符。 |
| certNum          | number         | 是   | 是   | 表示凭据中包含的证书个数。 |
| keyNum          | number   | 是   | 是   | 表示凭据中包含的密钥个数。 |
| credentialData          | Uint8Array   | 是   | 是   | 表示凭据二进制数据。 |

## CredentialAbstract

表示凭据的简要信息。

**系统能力：** SystemCapability.Security.CertificateManager

| 名称           | 类型                              | 可读 | 可写 | 说明                                                         |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type          | string         | 是   | 是   | 表示凭据的类型。 |
| alias          | string   | 是   | 是   | 表示凭据的别名。 |
| keyUri          | string     | 是   | 是   | 表示凭据的唯一标识符。 |

## CMResult

表示接口的返回结果。

**系统能力：** SystemCapability.Security.CertificateManager

| 名称           | 类型                              | 可读 | 可写 | 说明                                                         |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| certList?          | Array<[CertAbstract](#certabstract)> | 是   | 是   | 表示证书简要信息的列表。 |
| certInfo?          | [CertInfo](#certinfo) | 是   | 是   | 表示证书详情。 |
| credentialList?          | Array<[CredentialAbstract](#credentialabstract)> | 是   | 是   | 表示凭据简要信息的列表。 |
| credential?         | [Credential](#credential) | 是   | 是   | 表示凭据详情。 |
| appUidList?        | Array<string>     | 是   | 是   | 表示授权应用列表。 |
| uri?         | string    | 是   | 是   | 表示证书或凭据的唯一标识符。 |
| outData?         | Uint8Array    | 是   | 是   | 表示签名结果。 |

## CMHandle

表示签名、验签的初始化操作句柄。

**系统能力：** SystemCapability.Security.CertificateManager

| 名称           | 类型                              | 可读 | 可写 | 说明                                                         |
| -------------- | --------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| handle         | Uint8Array        | 是   | 是   | 表示签名、验签的初始化操作句柄。 |

## CMErrorCode

表示调用证书管理相关API的错误码。

**系统能力：** SystemCapability.Security.CertificateManager

| 名称       | 值 |  说明      |
| ---------- | ------ | --------- |
| CM_ERROR_NO_PERMISSION   | 201      | 表示应用程序无权限调用接口。 |
| CM_ERROR_NOT_SYSTEM_APP   | 202      | 表示应用程序不是系统应用程序 <br> **系统接口：** 此接口为系统接口。 |
| CM_ERROR_INVALID_PARAMS   | 401      | 表示输入参数无效。 |
| CM_ERROR_GENERIC  | 17500001      | 表示调用接口时发生内部错误。 |
| CM_ERROR_NO_FOUND  | 17500002      | 表示证书或凭据不存在。 |
| CM_ERROR_INCORRECT_FORMAT  | 17500003      | 表示输入证书或凭据的数据格式无效。 |

## certManager.installPrivateCertificate

installPrivateCertificate(keystore: Uint8Array, keystorePwd: string, certAlias: string, callback: AsyncCallback\<CMResult>) : void

表示安装私有凭据，使用Callback回调异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keystore | Uint8Array                   | 是   | 表示带有密钥对和证书的密钥库文件。 |
| keystorePwd | string | 是   | 表示密钥库文件的密码，长度限制32字节以内。 |
| certAlias | string | 是   | 表示用户输入的凭据别名，当前仅支持传入数字、字母或下划线，长度建议32字节以内。 |
| callback | AsyncCallback\<[CMResult](#cmresult)> | 是   | 回调函数。表示安装凭据的结果，返回值为[CMResult](#cmresult)中的uri。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](../errorcodes/errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500003 | The keystore is not valid format or keystorePwd is not correct. |

**示例**：
```ts
import certManager from '@ohos.security.certManager';

/* 安装的凭据数据需要业务赋值，本例数据非凭据数据 */
let keystore: Uint8Array = new Uint8Array([
  0x30, 0x82, 0x0b, 0xc1, 0x02, 0x01,
]);
let keystorePwd: string = "123456";
try {
  certManager.installPrivateCertificate(keystore, keystorePwd, "test", (err, cmResult) => {
    if (err != null) {
      console.error("[Callback]installPrivateCertificate err: " + err.code);
    } else {
      let uri: string = (cmResult.uri == undefined) ? '' : cmResult.uri;
      console.log("[Callback]installPrivateCertificate success");
    }
  });
} catch (error) {
  console.error("[Callback]installPrivateCertificate failed");
}
```

## certManager.installPrivateCertificate

installPrivateCertificate(keystore: Uint8Array, keystorePwd: string, certAlias: string) : Promise\<CMResult>

表示安装私有证书，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keystore | Uint8Array                   | 是   | 表示带有密钥对和证书的密钥库文件。 |
| keystorePwd | string | 是   | 表示密钥库文件的密码，长度限制32字节以内。 |
| certAlias | string | 是   | 表示用户输入的凭据别名，当前仅支持传入数字、字母或下划线，长度建议32字节以内。 |

**返回值**：

| 类型                                        | 说明                 |
| ------------------------------------------- | -------------------- |
| Promise\<[CMResult](#cmresult)> | 回调函数。表示安装凭据的结果，返回值为[CMResult](#cmresult)中的uri。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](../errorcodes/errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500003 | The keystore is not valid format or keystorePwd is not correct. |

**示例**：

```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

/* 安装的凭据数据需要业务赋值，本例数据非凭据数据 */
let keystore: Uint8Array = new Uint8Array([
  0x30, 0x82, 0x0b, 0xc1, 0x02, 0x01,
]);
let keystorePwd: string = "123456";
try {
  certManager.installPrivateCertificate(keystore, keystorePwd, 'test').then((cmResult) => {
    let uri: string = (cmResult.uri == undefined) ? '' : cmResult.uri;
    console.log("[Promise]installPrivateCertificate success");
  }).catch((err: BusinessError) => {
    console.error('[Promise]installPrivateCertificate failed');
  })
} catch (err) {
  console.error("[Promise]installPrivateCertificate failed");
}
```

## certManager.getAllAppPrivateCertificates

getAllAppPrivateCertificates(callback: AsyncCallback\<CMResult>): void

表示获取所有私有凭据列表，使用Callback回调异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<[CMResult](#cmresult)> | 是   | 回调函数。表示获取所有私有凭据列表的结果，返回值为[CMResult](#cmresult)中的credentialList。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](../errorcodes/errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**示例**：
```ts
import certManager from '@ohos.security.certManager';

try {
  certManager.getAllAppPrivateCertificates((err, cmResult) => {
    if (err != null) {
      console.error("getAllAppPrivateCertificates error");
    } else {
      if (cmResult.credentialList == undefined) {
        console.log("[Callback]getAllAppPrivateCertificates result is undefined");
      } else {
        let list = cmResult.credentialList;
        console.log("[Callback]getAllAppPrivateCertificates success");
      }
    }
  });
} catch (error) {
  console.error("[Callback]getAllAppPrivateCertificates failed");
}
```

## certManager.getAllAppPrivateCertificates

getAllAppPrivateCertificates() : Promise\<CMResult>

表示获取所有私有凭据列表，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**返回值**：

| 类型                                        | 说明                 |
| ------------------------------------------- | -------------------- |
| Promise\<[CMResult](#cmresult)> | 表示获取所有私有凭据列表的结果，返回值为[CMResult](#cmresult)中的credentialList。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](../errorcodes/errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**示例**：
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

try {
  certManager.getAllAppPrivateCertificates().then((cmResult) => {
    if (cmResult.credentialList == undefined) {
      console.log("[Promise]getAllAppPrivateCertificates result is undefined");
    } else {
      let list = cmResult.credentialList;
      console.log("[Promise]getAllAppPrivateCertificates success");
    }
  }).catch((err: BusinessError) => {
    console.error('[Promise]getAllAppPrivateCertificates failed');
  })
} catch (error) {
  console.error("[Promise]getAllAppPrivateCertificates failed");
}
```

## certManager.getPrivateCertificate

getPrivateCertificate(keyUri: string, callback: AsyncCallback\<CMResult>) : void

表示获取私有凭据详情，使用Callback回调异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | 是   | 表示待获取凭据的唯一标识符。 |
| callback | AsyncCallback\<[CMResult](#cmresult)> | 是   | 回调函数。表示获取私有凭据详情的结果，返回值为[CMResult](#cmresult)中的credential。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](../errorcodes/errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |

**示例**：
```ts
import certManager from '@ohos.security.certManager';

let uri: string = 'test'; /* 业务安装凭据，返回唯一标识符，此处省略 */
try {
  certManager.getPrivateCertificate(uri, (err, cmResult) => {
    if (err != null) {
      console.error("getPrivateCertificate error");
    } else {
      if (cmResult.credential == undefined) {
        console.log("[Callback]getPrivateCertificate result is undefined");
      } else {
        let list = cmResult.credential;
        console.log("[Callback]getPrivateCertificate success");
      }
    }
  });
} catch (error) {
  console.error("[Callback]installPrivateCertificate failed");
}
```

## certManager.getPrivateCertificate

getPrivateCertificate(keyUri: string) : Promise\<CMResult>

表示获取私有凭据详情，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | 是   | 表示待获取凭据的唯一标识符。 |

**返回值**：

| 类型                                        | 说明                 |
| ------------------------------------------- | -------------------- |
| Promise\<[CMResult](#cmresult)> | 回调函数。表示获取私有凭据详情的结果，返回值[CMResult](#cmresult)中的credential。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](../errorcodes/errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |

**示例**：
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

let uri: string = 'test'; /* 业务安装凭据，返回唯一标识符，此处省略 */
try {
  certManager.getPrivateCertificate(uri).then((cmResult) => {
    if (cmResult.credential == undefined) {
      console.log("[Promise]getPrivateCertificate result is undefined");
    } else {
      let list = cmResult.credential;
      console.log("[Promise]getPrivateCertificate success");
    }
  }).catch((err: BusinessError) => {
    console.error('[Promise]getPrivateCertificate failed');
  })
} catch (err) {
  console.error("[Promise]getPrivateCertificate failed");
}
```

## certManager.uninstallPrivateCertificate

uninstallPrivateCertificate(keyUri: string, callback: AsyncCallback\<void>) : void

表示卸载指定的私有凭据，使用Callback回调异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | 是   | 表示待卸载凭据的唯一标识符。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。使用AsyncCallback的第一个error参数判断是否执行成功，error为null表示成功，不为null表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](../errorcodes/errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |

**示例**：
```ts
import certManager from '@ohos.security.certManager';

let uri: string = 'test'; /* 业务安装凭据，返回唯一标识符，此处省略 */
try {
  certManager.uninstallPrivateCertificate(uri, (err, result) => {
    if (err != null) {
      console.error("[Callback]uninstallPrivateCertificate error");
    } else {
      console.log("[Callback]uninstallPrivateCertificate success");
    }
  });
} catch (err) {
  console.error("[Callback]uninstallPrivateCertificate failed");
}
```

## certManager.uninstallPrivateCertificate

uninstallPrivateCertificate(keyUri: string) : Promise\<void>

表示卸载指定的私有凭据，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | 是   | 表示待卸载凭据的唯一标识符。 |

**返回值**：

| 类型                                        | 说明                 |
| ------------------------------------------- | -------------------- |
| Promise\<void> | Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](../errorcodes/errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |

**示例**：
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

let uri: string = 'test'; /* 业务安装凭据，返回唯一标识符，此处省略 */
try {
  certManager.uninstallPrivateCertificate(uri).then((cmResult) => {
    console.log("[Promise]uninstallPrivateCertificate success");
  }).catch((err: BusinessError) => {
    console.error('[Promise]uninstallPrivateCertificate failed, code =', err.code);
  })
} catch (err) {
  console.error("[Promise]uninstallPrivateCertificate failed");
}
```

## certManager.init

init(authUri: string, spec: CMSignatureSpec, callback: AsyncCallback\<CMHandle>) : void

表示使用凭据进行签名、验签的初始化操作，使用Callback回调异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| authUri | string                   | 是   | 表示使用凭据的唯一标识符。 |
| spec | [CMSignatureSpec](#cmsignaturespec) | 是   | 表示签名、验签的属性。 |
| callback | AsyncCallback\<[CMHandle](#cmhandle)> | 是   | 回调函数。表示初始化操作返回的句柄。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](../errorcodes/errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |

**示例**：
```ts
import certManager from '@ohos.security.certManager';

let uri: string = 'test'; /* 业务安装凭据，返回唯一标识符，此处省略 */
const req: certManager.CMSignatureSpec = {
  purpose: certManager.CmKeyPurpose.CM_KEY_PURPOSE_SIGN,
  padding: certManager.CmKeyPadding.CM_PADDING_PSS,
  digest: certManager.CmKeyDigest.CM_DIGEST_SHA256
}
try {
  certManager.init(uri, req, (err, cmHandle) => {
    if (err != null) {
      console.error("[Callback]init err");
    } else {
      console.log("[Callback]init success");
    }
  })
} catch (err) {
  console.error("[Callback]init failed");
}
```

## certManager.init

init(authUri: string, spec: CMSignatureSpec) : Promise\<CMHandle>

表示使用凭据进行签名、验签的初始化操作，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| authUri | string                   | 是   | 表示使用凭据的唯一标识符。 |
| spec | [CMSignatureSpec](#cmsignaturespec) | 是   | 表示签名、验签的属性。 |

**返回值**：

| 类型                                        | 说明                 |
| ------------------------------------------- | -------------------- |
| Promise\<[CMHandle](#cmhandle)> | 表示初始化操作返回的句柄。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](../errorcodes/errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |
| 17500002 | The certificate do not exist. |

**示例**：
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

let uri: string = 'test'; /* 业务安装凭据，返回唯一标识符，此处省略 */
const req: certManager.CMSignatureSpec = {
  purpose: certManager.CmKeyPurpose.CM_KEY_PURPOSE_VERIFY,
  padding: certManager.CmKeyPadding.CM_PADDING_PSS,
  digest: certManager.CmKeyDigest.CM_DIGEST_MD5
}
try {
  certManager.init(uri, req).then((handle) => {
    console.log('[Promise]init success');
  }).catch((error: BusinessError) => {
    console.error('[Promise]init failed');
  })
} catch (err) {
  console.error("[Promise]init failed");
}
```

## certManager.update

update(handle: Uint8Array, data: Uint8Array, callback: AsyncCallback\<void>): void

表示签名、验签时对数据的更新操作，使用Callback回调异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | 是   | 表示初始化操作返回的句柄。 |
| data | Uint8Array                   | 是   | 表示待签名、验签的数据。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。使用AsyncCallback的第一个error参数判断是否执行成功，error为null表示成功，不为null表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](../errorcodes/errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**示例**：
```ts
import certManager from '@ohos.security.certManager';

/* cmHandle为业务调用init接口的返回值，此处仅为示例 */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
let srcData: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certManager.update(cmHandle, srcData, (err, result) => {
    if (err != null) {
      console.error("[Callback]certManager update error");
    } else {
      console.log("[Callback]certManager update success");
    }
  });
} catch (err) {
  console.error("[Callback]update failed");
}
```

## certManager.update

update(handle: Uint8Array, data: Uint8Array): Promise\<void>

表示签名、验签时对数据的更新操作，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | 是   | 表示初始化操作返回的句柄。 |
| data | Uint8Array                   | 是   | 表示待签名、验签的数据。 |

**返回值**：

| 类型                                        | 说明                 |
| ------------------------------------------- | -------------------- |
| Promise\<void> | Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](../errorcodes/errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**示例**：
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

/* cmHandle为业务调用init接口的返回值，此处仅为示例 */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
let srcData: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certManager.update(cmHandle, srcData).then((result) => {
    console.log('[Promise]update success');
  }).catch((error: BusinessError) => {
    console.error('[Promise]update failed');
  })
} catch (err) {
  console.error("[Promise]certManager update error");
}
```

## certManager.finish

finish(handle: Uint8Array, callback: AsyncCallback\<CMResult>) : void

表示完成签名的操作，Callback回调异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | 是   | 表示初始化操作返回的句柄。 |
| callback | AsyncCallback\<[CMResult](#cmresult)> | 是   | 回调函数。表示签名的结果，返回值为[CMResult](#cmresult)中的outData。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](../errorcodes/errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**示例**：
```ts
import certManager from '@ohos.security.certManager';

/* cmHandle为业务调用init接口的返回值，此处仅为示例 */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certManager.finish(cmHandle, (err, cmResult) => {
    if (err != null) {
      console.error("[Callback]certManager sign failed");
    } else {
      if (cmResult.outData != undefined) {
        let signRes: Uint8Array = cmResult.outData;
        console.log("[Callback]certManager sign success");
      } else {
        console.error("[Callback]certManager sign failed");
      }
    }
  });
} catch(error) {
  console.error("[Callback]certManager finish error");
}
```

## certManager.finish

finish(handle: Uint8Array, signature: Uint8Array, callback: AsyncCallback\<CMResult>) : void

表示完成验签的操作，使用Callback回调异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | 是   | 表示初始化操作返回的句柄。 |
| signature | Uint8Array                   | 是   | 表示签名数据。 |
| callback | AsyncCallback\<[CMResult](#cmresult)> | 是   | 回调函数。使用AsyncCallback的第一个error参数判断是否执行成功，error为null表示成功，不为null表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](../errorcodes/errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**示例**：
```ts
import certManager from '@ohos.security.certManager';

/* cmHandle为业务调用init接口的返回值，此处仅为示例 */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
let signRes: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certManager.finish(cmHandle, signRes, (err, cmResult) => {
    if (err != null) {
      console.error("[Callback]certManager verify failed");
    } else {
      console.log("[Callback]certManager verify success");
    }
  });
} catch(error) {
  console.error("[Callback]certManager finish error");
}
```

## certManager.finish

finish(handle: Uint8Array, signature?: Uint8Array) : Promise\<CMResult>

表示完成签名、验签的操作，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | 是   | 表示初始化操作返回的句柄。 |
| signature | Uint8Array                   | 否   | 表示签名数据。 |

**返回值**：

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](#cmresult)> | 表示签名、验证操作的结果。执行签名操作时，表示签名的结果，返回值为[CMResult](#cmresult)中的outData；执行验签操作时，无数据返回，无异常则认为验签成功。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](../errorcodes/errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**示例**：
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

/* cmHandle为业务调用init接口的返回值，此处仅为示例 */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  /* 签名的finish操作 */
  certManager.finish(cmHandle).then((cmResult) => {
    if (cmResult.outData != undefined) {
      let signRes1: Uint8Array = cmResult.outData;
      console.log("[Promise]finish sign success");
    } else {
      console.error("[Promise]finish sign failed");
    }
  }).catch((err: BusinessError) => {
    console.error('[Promise]finish sign failed');
  })

  /* 签名的结果 */
  let signRes: Uint8Array = new Uint8Array([
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
  ]);
  /* 验签的finish操作 */
  certManager.finish(cmHandle, signRes).then((cmResult) => {
    console.log("[Promise]finish verify success");
  }).catch((err: BusinessError) => {
    console.error('[Promise]finish verify failed');
  })
} catch(error) {
  console.error("[Promise]certManager finish error");
}
```

## certManager.abort

abort(handle: Uint8Array, callback: AsyncCallback\<void>) : void

表示中止签名、验签的操作，使用Callback回调异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | 是   | 表示初始化操作返回的句柄。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。使用AsyncCallback的第一个error参数判断是否执行成功，error为null表示成功，不为null表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](../errorcodes/errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**示例**：
```ts
import certManager from '@ohos.security.certManager';

/* cmHandle为业务调用init接口的返回值，此处仅为示例 */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certManager.abort(cmHandle, (err, cmResult) => {
    if (err != null) {
      console.error("[Callback]certManager abort failed");
    } else {
      console.log("[Callback]certManager abort success");
    }
  });
} catch(error) {
  console.error("[Callback]certManager abort error");
}
```

## certManager.abort

abort(handle: Uint8Array) : Promise\<void>

表示中止签名、验签的操作，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| handle | Uint8Array                   | 是   | 表示初始化操作返回的句柄。 |

**返回值**：

| 类型                                        | 说明                 |
| ------------------------------------------- | -------------------- |
| Promise\<void> | Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](../errorcodes/errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17500001 | There is an generic error occurred when calling the API. |

**示例**：
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

/* cmHandle为业务调用init接口的返回值，此处仅为示例 */
let cmHandle: Uint8Array = new Uint8Array([
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]);
try {
  certManager.abort(cmHandle).then((result) => {
    console.log('[Promise]abort success');
  }).catch((error: BusinessError) => {
    console.error('[Promise]abort failed');
  })
} catch (err) {
  console.error("[Promise]certManager abort error");
}
```