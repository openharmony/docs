# @ohos.security.certManager (证书管理模块)(系统接口)

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @chaceli-->
<!--SE: @chande-->
<!--TSE: @zhangzhi1995-->

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

以下错误码的详细介绍请参见[证书管理错误码](errorcode-certManager.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 17500001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. |

**示例**：
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';

try {
  certificateManager.getAllAppPrivateCertificates((err, cmResult) => {
    if (err != null) {
      console.error(`Failed to get all app private certificates. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (cmResult === undefined) { // 私有凭据个数为0时，返回cmResult为undefined。
        console.info('the count of the app private certificates is 0');
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

表示获取所有私有凭据列表，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**返回值**：

| 类型                                                  | 说明                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise对象。表示获取所有私有凭据列表的结果，返回值为[CMResult](js-apis-certManager.md#cmresult)对象中的credentialList属性。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 17500001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. |

**示例**：
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  certificateManager.getAllAppPrivateCertificates().then((cmResult) => {
    if (cmResult === undefined) { // 私有凭据个数为0时，返回cmResult为undefined。
      console.info('the count of the app private certificates is 0');
    } else if (cmResult.credentialList == undefined) {
      console.info('The result of getting all app private certificates is undefined.');
    } else {
      let list = cmResult.credentialList;
      console.info('Succeeded in getting all app private certificates.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get all app private certificates. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get all app private certificates. Code: ${error.code}, message: ${error.message}`);
}
```

## certificateManager.getAllSystemAppCertificates<sup>12+</sup>

getAllSystemAppCertificates(): Promise\<CMResult>

表示获取所有系统凭据列表，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**返回值**：

| 类型                                                  | 说明                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | Promise对象。表示获取所有系统凭据列表的结果，返回值为[CMResult](js-apis-certManager.md#cmresult)对象中的credentialList属性。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 17500001 | Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error. |

**示例**：
```ts
import { certificateManager } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  certificateManager.getAllSystemAppCertificates().then((cmResult) => {
    if (cmResult === undefined) { // 系统凭据个数为0时，返回cmResult为undefined。
      console.info('the count of the system certificates is 0');
    } else if (cmResult.credentialList == undefined) {
      console.info('The result of getting all system app certificates is undefined.');
    } else {
      let list = cmResult.credentialList;
      console.info('Succeeded in getting all system app certificates.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get all system app certificates. Code: ${err.code}, message: ${err.message}`);
  })
} catch (error) {
  console.error(`Failed to get all system app certificates. Code: ${error.code}, message: ${error.message}`);
}
```
