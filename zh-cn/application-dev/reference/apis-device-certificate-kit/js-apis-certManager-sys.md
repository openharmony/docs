# @ohos.security.certManager (证书管理模块)(系统接口)

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @chaceli-->
<!--Designer: @chande-->
<!--Tester: @zhangzhi1995-->
<!--Adviser: @zengyawen-->

证书管理主要提供系统级的证书管理能力，实现证书全生命周期（安装，存储，使用，销毁）的管理和安全使用。

> **说明：**
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.security.certManager (证书管理模块)](js-apis-certManager.md)。

## 导入模块

```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
```

## CMErrorCode

表示调用证书管理相关API的错误码。

**系统能力：** SystemCapability.Security.CertificateManager

| 名称       | 值 |  说明      |
| ---------- | ------ | --------- |
| CM_ERROR_NOT_SYSTEM_APP   | 202      | 表示应用程序不是系统应用程序。 <br> **系统接口：** 此接口为系统接口。 |
| CM_ERROR_PASSWORD_IS_ERR   | 17500008      | 表示密码错误。 <br> **系统接口：** 此接口为系统接口。<br>**起始版本：** 26.0.0<br>**模型约束**：此接口仅可在Stage模型下使用。 |

## certificateManager.getAllAppPrivateCertificates

getAllAppPrivateCertificates(callback: AsyncCallback\<CMResult>): void

表示获取所有私有凭据列表，使用Callback回调异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**参数**：

| 参数名   | 类型                                                        | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[CMResult](js-apis-certManager.md#cmresult)> | 是   | 回调函数。当获取所有私有凭据列表成功时，err为null，data为[CMResult](js-apis-certManager.md#cmresult)对象中的credentialList属性；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |

**示例**：
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';

try {
  certificateManager.getAllAppPrivateCertificates((err, cmResult) => {
    if (err != null) {
      console.error(`Failed to get all app private certificates. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (cmResult === undefined) { // 私有凭据个数为0时，返回cmResult为undefined。
        console.info('The count of the app private certificates is 0.');
      } else if (cmResult.credentialList == undefined) {
        console.info('The result of getting all app private certificates is undefined.');
      } else {
        let list = cmResult.credentialList;
        console.info('Succeeded in getting all app private certificates.');
      }
    }
  });
} catch (error) {
  console.error(`Failed to get all app private certificates. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.getAllAppPrivateCertificates

getAllAppPrivateCertificates(): Promise\<CMResult>

表示获取所有私有凭据列表。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**返回值**：

| 类型                                                  | 说明                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise对象，返回获取所有私有凭据列表的结果，返回值为[CMResult](js-apis-certManager.md#cmresult)对象中的credentialList属性。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 17500001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |

**示例**：
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  certificateManager.getAllAppPrivateCertificates().then((cmResult) => {
    if (cmResult === undefined) { // 私有凭据个数为0时，返回cmResult为undefined。
      console.info('The count of the app private certificates is 0.');
    } else if (cmResult.credentialList == undefined) {
      console.info('The result of getting all app private certificates is undefined.');
    } else {
      let list = cmResult.credentialList;
      console.info('Succeeded in getting all app private certificates.');
    }
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to get all app private certificates. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get all app private certificates. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.getAllSystemAppCertificates<sup>12+</sup>

getAllSystemAppCertificates(): Promise\<CMResult>

表示获取所有系统凭据列表。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**返回值**：

| 类型                                                  | 说明                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise对象，返回获取所有系统凭据列表的结果，返回值为[CMResult](js-apis-certManager.md#cmresult)对象中的credentialList属性。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 17500001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |

**示例**：
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  certificateManager.getAllSystemAppCertificates().then((cmResult) => {
    if (cmResult === undefined) { // 系统凭据个数为0时，返回cmResult为undefined。
      console.info('The count of the system certificates is 0.');
    } else if (cmResult.credentialList == undefined) {
      console.info('The result of getting all system app certificates is undefined.');
    } else {
      let list = cmResult.credentialList;
      console.info('Succeeded in getting all system app certificates.');
    }
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to get all system app certificates. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get all system app certificates. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.getSystemTrustedCertificate

getSystemTrustedCertificate(certUri: string): Promise\<CMResult>

获取系统信任的CA证书详情，仅证书管理应用调用。使用Promise异步回调。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| certUri | string                   | 是   | 表示证书的唯一标识符。可通过[getSystemTrustedCertificateList](#certificatemanagergetsystemtrustedcertificatelist)接口获取。 |

**返回值**：

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise对象，返回获取系统信任CA证书详细信息的结果，返回值为[CMResult](js-apis-certManager.md#cmresult)对象中的certInfo属性。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter verification failed. Possible causes: the URI is null or the URI format is wrong. |
| 17500001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |
| 17500002 | The certificate does not exist. |

**示例**：
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let certUri: string = 'test'; /* 证书的唯一标识符，可通过getSystemTrustedCertificateList接口获取 */
try {
  certificateManager.getSystemTrustedCertificate(certUri).then((cmResult: certificateManager.CMResult) => {
    if (cmResult?.certInfo == undefined) {
      console.info('The result of getting system trusted certificate is undefined.');
    } else {
      let cert: certificateManager.CertInfo = cmResult.certInfo;
      console.info('Succeeded in getting system trusted certificate.');
    }
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to get system trusted certificate. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get system trusted certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.getSystemTrustedCertificateList

getSystemTrustedCertificateList(): Promise\<CMResult>

获取系统信任的CA证书列表，仅证书管理应用调用。使用Promise异步回调。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值**：

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise对象，返回获取系统信任CA证书列表的结果，返回值为[CMResult](js-apis-certManager.md#cmresult)对象中的certList属性。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 17500001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |

**示例**：
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  certificateManager.getSystemTrustedCertificateList().then((cmResult: certificateManager.CMResult) => {
    if (cmResult === undefined) { // 系统信任CA证书个数为0时，返回cmResult为undefined。
      console.info('The count of system trusted certificates is 0.');
    } else if (cmResult.certList == undefined) {
      console.info('The result of getting system trusted certificates is undefined.');
    } else {
      let list: Array<certificateManager.CertAbstract> = cmResult.certList;
      console.info('Succeeded in getting system trusted certificates.');
    }
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to get system trusted certificates. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get system trusted certificates. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.setCertificateStatus

setCertificateStatus(certUri: string, certType: CertType, enabled: boolean) : Promise\<void>

设置CA证书的状态，当前仅支持设置用户CA证书状态，仅证书管理应用调用。使用Promise异步回调。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_USER_TRUSTED_CERT

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| certUri | string                   | 是   | 表示证书的唯一标识符。当前仅支持用户CA证书。 |
| certType | [CertType](js-apis-certManager.md#certtype18) | 是   | 表示证书类型。当前仅支持设置用户CA证书（CA_CERT_USER）的状态。 |
| enabled | boolean                   | 是   | 表示证书状态是否启用。true：已启用，false：已禁用。 |

**返回值**：

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter verification failed. Possible causes: the URI is null or the URI format is wrong, the certType's value is invalid or not supported. |
| 17500001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |
| 17500002 | The certificate does not exist. |

**示例**：
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let certUri: string = 'test'; /* 用户CA证书的唯一标识符 */
try {
  /* 设置用户CA证书状态为启用 */
  certificateManager.setCertificateStatus(certUri, certificateManager.CertType.CA_CERT_USER, true).then(() => {
    console.info('Succeeded in setting certificate status.');
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to set certificate status. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to set certificate status. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.uninstallAllUserTrustedCertificate

uninstallAllUserTrustedCertificate() : Promise\<void>

卸载所有用户信任的CA证书，仅证书管理应用调用。使用Promise异步回调。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_USER_TRUSTED_CERT

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值**：

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 17500001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |

**示例**：
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  certificateManager.uninstallAllUserTrustedCertificate().then(() => {
    console.info('Succeeded in uninstalling all user trusted certificates.');
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to uninstall all user trusted certificates. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to uninstall all user trusted certificates. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.installPublicCertificate

installPublicCertificate(keystore: Uint8Array, keystorePwd: string) : Promise\<CMResult>

安装用户的公共凭据，仅证书管理应用调用。使用Promise异步回调。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型       | 必填 |说明                                            |
| ----------- | ---------- | ---- |---------------------------------------------------|
| keystore    | Uint8Array | 是  |表示带有密钥对和证书的密钥库文件，仅支持P12格式。 |
| keystorePwd | string     | 是  |表示密钥库文件的密码。 |

**返回值**：

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise对象，返回安装用户公共凭据的结果，返回值为[CMResult](js-apis-certManager.md#cmresult)对象中的uri属性。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID    | 错误信息                                                                                                                                            |
| ----------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201                    | Permission verification failed. The application does not have the permission required to call the API. |
| 202                    | Permission verification failed. A non-system application calls a system API. |
| 401                    | Parameter verification failed. Possible causes: the keystore parameter is empty or exceeds the maximum length. |
| 17500001               | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |
| 17500003               | Indicates that the certificate is in an invalid format. |
| 17500004               | Indicates that the number of certificates reaches the maximum allowed. |
| 17500008               | Indicates that the password is error. |

**示例**：

```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

/* 安装的凭据数据需要业务赋值，本例数据非凭据数据。 */
let keystore: Uint8Array = new Uint8Array([
    0x30, 0x82, 0x0b, 0xc1, 0x02, 0x01,
]);
let keystorePwd: string = "123456";
try {
  certificateManager.installPublicCertificate(keystore, keystorePwd).then((cmResult: certificateManager.CMResult) => {
    let uri: string = (cmResult?.uri == undefined) ? '' : cmResult.uri;
    console.info('Succeeded in installing public certificate.');
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to install public certificate. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to install public certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.uninstallPublicCertificate

uninstallPublicCertificate(keyUri: string) : Promise\<void>

卸载用户的公共凭据，仅证书管理应用调用。使用Promise异步回调。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | 是   | 表示用户公共凭据的唯一标识符。 |

**返回值**：

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID    | 错误信息                                                                                                                                            |
| ----------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201                    | Permission verification failed. The application does not have the permission required to call the API. |
| 202                    | Permission verification failed. A non-system application calls a system API. |
| 401                    | Parameter verification failed. Possible causes: the URI is null or the URI format is wrong. |
| 17500001               | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |
| 17500002               | Indicates that the certificate does not exist. |

**示例**：

```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let keyUri: string = 'test'; /* 用户公共凭据的唯一标识符 */
try {
  certificateManager.uninstallPublicCertificate(keyUri).then(() => {
    console.info('Succeeded in uninstalling public certificate.');
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to uninstall public certificate. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to uninstall public certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.getAllPublicCertificates

getAllPublicCertificates() : Promise\<CMResult>

获取所有用户的公共凭据，仅证书管理应用调用。使用Promise异步回调。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值**：

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise对象，返回获取所有用户公共凭据的结果，返回值为[CMResult](js-apis-certManager.md#cmresult)对象中的credentialDetailList属性。<br>**说明**：用户公共凭据个数为0时，返回CMResult为undefined。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID    | 错误信息                                                                                                                                            |
| ----------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201                    | Permission verification failed. The application does not have the permission required to call the API. |
| 202                    | Permission verification failed. A non-system application calls a system API. |
| 17500001               | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |

**示例**：

```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  certificateManager.getAllPublicCertificates().then((cmResult: certificateManager.CMResult) => {
    if (cmResult === undefined) { // 用户公共凭据个数为0时，返回cmResult为undefined。
      console.info('The count of public certificates is 0.');
    } else if (cmResult.credentialDetailList == undefined) {
      console.info('The result of getting all public certificates is undefined.');
    } else {
      let list: Array<certificateManager.Credential> = cmResult.credentialDetailList;
      console.info('Succeeded in getting all public certificates.');
    }
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to get all public certificates. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get all public certificates. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.grantPublicCertificate

grantPublicCertificate(keyUri: string, clientAppUid: number) : Promise\<CMResult>

授予应用使用用户公共凭据的权限，仅证书管理应用调用。使用Promise异步回调。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名       | 类型       | 必填 |说明                                            |
| ------------ | ---------- | ---- |---------------------------------------------------|
| keyUri       | string     | 是  |表示用户公共凭据的唯一标识符。 |
| clientAppUid | number        | 是  |表示应用UID。 |

**返回值**：

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise对象，返回授予应用使用用户公共凭据权限的结果，返回值为[CMResult](js-apis-certManager.md#cmresult)对象中的uri属性。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID    | 错误信息                                                                                                                                            |
| ----------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201                    | Permission verification failed. The application does not have the permission required to call the API. |
| 202                    | Permission verification failed. A non-system application calls a system API. |
| 401                    | Parameter verification failed. Possible causes: the URI is null or the URI format is wrong. |
| 17500001               | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |
| 17500002               | Indicates that the certificate does not exist. |

**示例**：

```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let keyUri: string = 'test'; /* 用户公共凭据的唯一标识符 */
let clientAppUid: number = 1001; /* 应用UID */
try {
  certificateManager.grantPublicCertificate(keyUri, clientAppUid).then((cmResult: certificateManager.CMResult) => {
    let uri: string = (cmResult?.uri == undefined) ? '' : cmResult.uri;
    console.info('Succeeded in granting public certificate.');
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to grant public certificate. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to grant public certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.getAuthorizedAppList

getAuthorizedAppList(keyUri: string) : Promise\<CMResult>

获取用户公共凭据的授权应用列表，仅证书管理应用调用。使用Promise异步回调。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | 是   | 表示用户公共凭据的唯一标识符。 |

**返回值**：

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise对象，返回获取授权应用列表的结果，返回值为[CMResult](js-apis-certManager.md#cmresult)对象中的appUidList属性。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID    | 错误信息                                                                                                                                            |
| ----------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201                    | Permission verification failed. The application does not have the permission required to call the API. |
| 202                    | Permission verification failed. A non-system application calls a system API. |
| 401                    | Parameter verification failed. Possible causes: the URI is null or the URI format is wrong. |
| 17500001               | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |
| 17500002               | Indicates that the certificate does not exist. |

**示例**：

```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let keyUri: string = 'test'; /* 用户公共凭据的唯一标识符 */
try {
  certificateManager.getAuthorizedAppList(keyUri).then((cmResult: certificateManager.CMResult) => {
    if (cmResult?.appUidList == undefined) {
      console.info('The result of getting authorized app list is undefined.');
    } else {
      let appUidList: Array<string> = cmResult.appUidList;
      console.info('Succeeded in getting authorized app list.');
    }
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to get authorized app list. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get authorized app list. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.removeGrantedPublicCertificate

removeGrantedPublicCertificate(keyUri: string, clientAppUid: number) : Promise\<void>

移除应用使用用户公共凭据的权限，仅证书管理应用调用。使用Promise异步回调。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名       | 类型       | 必填 |说明                                            |
| ------------ | ---------- | ---- |---------------------------------------------------|
| keyUri       | string     | 是  |表示用户公共凭据的唯一标识符。 |
| clientAppUid | number        | 是  |表示应用UID。 |

**返回值**：

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID    | 错误信息                                                                                                                                            |
| ----------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201                    | Permission verification failed. The application does not have the permission required to call the API. |
| 202                    | Permission verification failed. A non-system application calls a system API. |
| 401                    | Parameter verification failed. Possible causes: the URI is null or the URI format is wrong. |
| 17500001               | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |
| 17500002               | Indicates that the certificate does not exist. |

**示例**：

```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let keyUri: string = 'test'; /* 用户公共凭据的唯一标识符 */
let clientAppUid: number = 1001; /* 应用UID */
try {
  certificateManager.removeGrantedPublicCertificate(keyUri, clientAppUid).then(() => {
    console.info('Succeeded in removing granted public certificate.');
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to remove granted public certificate. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to remove granted public certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.getAllAppPrivateCertificatesByUid

getAllAppPrivateCertificatesByUid(appUid: number) : Promise\<CMResult>

获取指定应用的所有私有凭据，仅证书管理应用调用。使用Promise异步回调。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| appUid | number                   | 是   | 表示应用UID。 |

**返回值**：

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise对象，返回获取指定应用的所有私有凭据的结果，返回值为[CMResult](js-apis-certManager.md#cmresult)对象中的credentialDetailList属性。<br>**说明**：私有凭据个数为0时，返回CMResult为undefined。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID    | 错误信息                                                                                                                                            |
| ----------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201                    | Permission verification failed. The application does not have the permission required to call the API. |
| 202                    | Permission verification failed. A non-system application calls a system API. |
| 17500001               | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |

**示例**：

```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let appUid: number = 1001; /* 应用UID */
try {
  certificateManager.getAllAppPrivateCertificatesByUid(appUid).then((cmResult: certificateManager.CMResult) => {
    if (cmResult === undefined) { // 指定应用的私有凭据个数为0时，返回cmResult为undefined。
      console.info('The count of private certificates is 0.');
    } else if (cmResult.credentialDetailList == undefined) {
      console.info('The result of getting all private certificates is undefined.');
    } else {
      let list: Array<certificateManager.Credential> = cmResult.credentialDetailList;
      console.info('Succeeded in getting all private certificates.');
    }
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to get all private certificates. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get all private certificates. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.installSystemAppCertificate

installSystemAppCertificate(keystore: Uint8Array, keystorePwd: string): Promise\<CMResult>

安装系统应用凭据，仅证书管理应用调用。使用Promise异步回调。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_SYSTEM_APP_CERT

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型       | 必填 |说明                                            |
| ----------- | ---------- | ---- |---------------------------------------------------|
| keystore    | Uint8Array | 是  |表示带有密钥对和证书的密钥库文件，仅支持P12格式。 |
| keystorePwd | string     | 是  |表示密钥库文件的密码。 |

**返回值**：

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise对象，返回安装系统应用凭据的结果，返回值为[CMResult](js-apis-certManager.md#cmresult)对象中的uri属性。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID    | 错误信息                                                                                                                                            |
| ----------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201                    | Permission verification failed. The application does not have the permission required to call the API. |
| 202                    | Permission verification failed. A non-system application calls a system API. |
| 401                    | Parameter verification failed. Possible causes: The keystore parameter is empty or exceeds the maximum length. |
| 17500001               | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |
| 17500003               | Indicates that the certificate is in an invalid format. |
| 17500004               | Indicates that the number of certificates reaches the maximum allowed. |
| 17500008               | Indicates that the password is error. |

**示例**：

```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

/* 安装的凭据数据需要业务赋值，本例数据非凭据数据。 */
let keystore: Uint8Array = new Uint8Array([
    0x30, 0x82, 0x0b, 0xc1, 0x02, 0x01,
]);
let keystorePwd: string = "123456";
try {
  certificateManager.installSystemAppCertificate(keystore, keystorePwd).then((cmResult: certificateManager.CMResult) => {
    let uri: string = (cmResult?.uri == undefined) ? '' : cmResult.uri;
    console.info('Succeeded in installing system app certificate.');
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to install system app certificate. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to install system app certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.getSystemAppCertificate

getSystemAppCertificate(keyUri: string) : Promise\<CMResult>

获取系统应用的凭据详情，仅证书管理应用调用。使用Promise异步回调。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_SYSTEM_APP_CERT

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | 是   | 表示系统应用凭据的唯一标识符。 |

**返回值**：

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise对象，返回获取系统应用凭据详细信息的结果，返回值为[CMResult](js-apis-certManager.md#cmresult)对象中的credential属性。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID    | 错误信息                                                                                                                                            |
| ----------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201                    | Permission verification failed. The application does not have the permission required to call the API. |
| 202                    | Permission verification failed. A non-system application calls a system API. |
| 401                    | Parameter verification failed. Possible causes: the URI is null or the URI format is wrong. |
| 17500001               | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |
| 17500002               | Indicates that the certificate does not exist. |

**示例**：

```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let keyUri: string = 'test'; /* 系统应用凭据的唯一标识符 */
try {
  certificateManager.getSystemAppCertificate(keyUri).then((cmResult: certificateManager.CMResult) => {
    if (cmResult?.credential == undefined) {
      console.info('The result of getting system app certificate is undefined.');
    } else {
      let cred: certificateManager.Credential = cmResult.credential;
      console.info('Succeeded in getting system app certificate.');
    }
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to get system app certificate. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get system app certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.uninstallSystemAppCertificate

uninstallSystemAppCertificate(keyUri: string) : Promise\<void>

卸载系统应用的凭据，仅证书管理应用调用。使用Promise异步回调。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_SYSTEM_APP_CERT

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| keyUri | string                   | 是   | 表示系统应用凭据的唯一标识符。 |

**返回值**：

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID    | 错误信息                                                                                                                                            |
| ----------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201                    | Permission verification failed. The application does not have the permission required to call the API. |
| 202                    | Permission verification failed. A non-system application calls a system API. |
| 401                    | Parameter verification failed. Possible causes: the URI is null or the URI format is wrong. |
| 17500001               | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |
| 17500002               | Indicates that the certificate does not exist. |

**示例**：

```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

let keyUri: string = 'test'; /* 系统应用凭据的唯一标识符 */
try {
  certificateManager.uninstallSystemAppCertificate(keyUri).then(() => {
    console.info('Succeeded in uninstalling system app certificate.');
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to uninstall system app certificate. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to uninstall system app certificate. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.uninstallAllAppCertificate

uninstallAllAppCertificate() : Promise\<void>

卸载所有系统应用凭据和用户公共凭据，仅证书管理应用调用。使用Promise异步回调。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_CERT_MANAGER_INTERNAL 和 ohos.permission.ACCESS_SYSTEM_APP_CERT

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值**：

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[证书管理错误码](errorcode-certManager.md)。

| 错误码ID    | 错误信息                                                                                                                                            |
| ----------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| 201                    | Permission verification failed. The application does not have the permission required to call the API. |
| 202                    | Permission verification failed. A non-system application calls a system API. |
| 17500001               | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. Please try again. |

**示例**：

```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  certificateManager.uninstallAllAppCertificate().then(() => {
    console.info('Succeeded in uninstalling all app certificates.');
  }).catch((error: Error) => {
    let err = error as BusinessError;
    console.error(`Failed to uninstall all app certificates. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to uninstall all app certificates. Code: ${error.code}, message: ${error.message}`);
}
```
