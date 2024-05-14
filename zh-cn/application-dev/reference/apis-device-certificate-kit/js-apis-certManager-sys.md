# @ohos.security.certManager (证书管理模块)(系统接口)

证书管理主要提供系统级的证书管理能力，实现证书全生命周期（安装，存储，使用，销毁）的管理和安全使用 。

> **说明：**
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.security.certManager (证书管理模块)](js-apis-certManager.md)。

## 导入模块

```ts
import certManager from '@ohos.security.certManager';
```

## CMErrorCode

表示调用证书管理相关API的错误码。

**系统能力：** SystemCapability.Security.CertificateManager

| 名称       | 值 |  说明      |
| ---------- | ------ | --------- |
| CM_ERROR_NOT_SYSTEM_APP   | 202      | 表示应用程序不是系统应用程序 <br> **系统接口：** 此接口为系统接口。 |

## certManager.getAllAppPrivateCertificates

getAllAppPrivateCertificates(callback: AsyncCallback\<CMResult>): void

表示获取所有私有凭据列表，使用Callback回调异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER 和 ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**参数**：

| 参数名   | 类型                                              | 必填 | 说明                       |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<[CMResult](js-apis-certManager.md#cmresult)> | 是   | 回调函数。表示获取所有私有凭据列表的结果，返回值为[CMResult](js-apis-certManager.md#cmresult)中的credentialList。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](errorcode-certManager.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The parameter check failed.Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17500001 | There is an generic error occurred when calling the API.     |

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
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | 表示获取所有私有凭据列表的结果，返回值为[CMResult](js-apis-certManager.md#cmresult)中的credentialList。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](errorcode-certManager.md)。

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

## certManager.getAllSystemAppCertificates<sup>12+</sup>

getAllSystemAppCertificates() : Promise\<CMResult>

表示获取所有系统凭据列表，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_CERT_MANAGER

**系统能力：** SystemCapability.Security.CertificateManager

**系统接口：** 此接口为系统接口。

**返回值**：

| 类型                                        | 说明                 |
| ------------------------------------------- | -------------------- |
| Promise\<[CMResult](js-apis-certManager.md#cmresult)> | 表示获取所有系统凭据列表的结果，返回值为[CMResult](js-apis-certManager.md#cmresult)中的credentialList。 |

**错误码：**

以下错误码的详细介绍请参见[证书管理错误码](errorcode-certManager.md)。

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 201 | The application has no permission to call the API. |
| 202 | The application is not system app. |
| 17500001 | There is an generic error occurred when calling the API. |

**示例**：
```ts
import certManager from '@ohos.security.certManager';
import { BusinessError } from '@ohos.base';

try {
  certManager.getAllSystemAppCertificates().then((cmResult) => {
    if (cmResult.credentialList == undefined) {
      console.log("[Promise]getAllSystemAppCertificates result is undefined");
    } else {
      let list = cmResult.credentialList;
      console.log("[Promise]getAllSystemAppCertificates success");
    }
  }).catch((err: BusinessError) => {
    console.error('[Promise]getAllSystemAppCertificates failed');
  })
} catch (error) {
  console.error("[Promise]getAllSystemAppCertificates failed");
}
```
