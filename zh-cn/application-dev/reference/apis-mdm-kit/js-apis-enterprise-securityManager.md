# @ohos.enterprise.securityManager（安全管理）

本模块提供设备安全管理的能力，包括查询安全补丁状态、查询文件加密状态等。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](../../mdm/mdm-kit-guide.md#功能介绍)开放，需将设备管理应用激活后调用，实现相应功能。

## 导入模块

```ts
import { securityManager } from '@kit.MDMKit';
```

## securityManager.uninstallUserCertificate

uninstallUserCertificate(admin: Want, certUri: string): Promise&lt;void&gt;

指定设备管理应用卸载用户证书，使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名  | 类型                                                    | 必填 | 说明                              |
| ------- | ------------------------------------------------------- | ---- | --------------------------------- |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。                    |
| certUri | string                                                  | 是   | 证书uri，由安装用户证书接口返回。 |

**返回值：**

| 类型                | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当指定设备管理应用卸载用户证书失败时会抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9201001  | Failed to manage the certificate.                            |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let aliasStr = "certName"
securityManager.uninstallUserCertificate(wantTemp, aliasStr).then(() => {
  console.info(`Succeeded in uninstalling user certificate.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to uninstall user certificate. Code is ${err.code}, message is ${err.message}`);
});
```

## securityManager.installUserCertificate

installUserCertificate(admin: Want, certificate: CertBlob): Promise&lt;string&gt;

指定设备管理应用安装用户证书，使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名      | 类型                                                    | 必填 | 说明           |
| ----------- | ------------------------------------------------------- | ---- | -------------- |
| admin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。 |
| certificate | [CertBlob](#certblob)                                   | 是   | 证书信息。     |

**返回值：**

| 类型                  | 说明                                                 |
| --------------------- | ---------------------------------------------------- |
| Promise&lt;string&gt; | Promise对象，返回当前证书安装后的uri，用于卸载证书。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9201001  | Failed to manage the certificate.                            |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let certFileArray: Uint8Array = new Uint8Array();
// The variable context needs to be initialized in MainAbility's onCreate callback function
// test.cer needs to be placed in the rawfile directory
getContext().resourceManager.getRawFileContent("test.cer").then((value) => {
  certFileArray = value
  securityManager.installUserCertificate(wantTemp, { inData: certFileArray, alias: "cert_alias_xts" })
    .then((result) => {
      console.info(`Succeeded in installing user certificate, result : ${JSON.stringify(result)}`);
    }).catch((err: BusinessError) => {
    console.error(`Failed to install user certificate. Code: ${err.code}, message: ${err.message}`);
  })
}).catch((err: BusinessError) => {
  console.error(`Failed to get row file content. message: ${err.message}`);
  return
});
```

## securityManager.getSecurityStatus

getSecurityStatus(admin: Want, item: string): string

获取安全策略信息。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。                                               |
| item   | string                                                  | 是   | 安全策略名称。<br/>- patch：设备安全补丁。<br/>- encryption：设备文件系统加密。 <!--RP1--><!--RP1End-->|

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| string | 返回安全策略状态值。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  let result: string = securityManager.getSecurityStatus(wantTemp, 'patch');
  console.info(`Succeeded in getting security patch tag. tag: ${result}`);
} catch (err) {
  console.error(`Failed to get security patch tag. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.setPasswordPolicy<sup>12+</sup>

setPasswordPolicy(admin: Want, policy: PasswordPolicy): void

指定设备管理应用设置设备口令策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 设备管理应用。                  |
| policy | [PasswordPolicy](#passwordpolicy) | 是 | 设备口令策略。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

let policy: securityManager.PasswordPolicy = {
  complexityRegex: '^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)[a-zA-Z\d]{8,}$',
  validityPeriod: 1,
  additionalDescription: '至少八个字符，至少一个大写字母，一个小写字母，一个数字和一个特殊字符',
}
try {
    securityManager.setPasswordPolicy(wantTemp, policy);
    console.info(`Succeeded in setting password policy.`);
} catch(err) {
    console.error(`Failed to set password policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.getPasswordPolicy<sup>12+</sup>

getPasswordPolicy(admin: Want): PasswordPolicy

指定设备管理应用获取设备口令策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 设备管理应用。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| [PasswordPolicy](#passwordpolicy) | 设备口令策略。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
    let result: securityManager.PasswordPolicy = securityManager.getPasswordPolicy(wantTemp);
    console.info(`Succeeded in getting password policy, result : ${JSON.stringify(result)}`);
} catch(err) {
    console.error(`Failed to get password policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.setAppClipboardPolicy<sup>12+</sup>

setAppClipboardPolicy(admin: Want, tokenId: number, policy: ClipboardPolicy): void

指定设备管理应用设置设备剪贴板策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 设备管理应用。                  |
| tokenId | number | 是 | 目标应用的身份标识。可通过应用的[ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md)获得。当前只支持最多100个tokenId被保存策略。 |
| policy | [ClipboardPolicy](#clipboardpolicy) | 是 | 剪贴板策略。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let tokenId: number = 586874394;
try {
    securityManager.setAppClipboardPolicy(wantTemp, tokenId, securityManager.ClipboardPolicy.IN_APP);
    console.info(`Succeeded in setting clipboard policy.`);
} catch(err) {
    console.error(`Failed to set clipboard policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.getAppClipboardPolicy<sup>12+</sup>

getAppClipboardPolicy(admin: Want, tokenId?: number): string

指定设备管理应用获取设备剪贴板策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 设备管理应用。                  |
| tokenId | number | 否 | 目标应用的身份标识。可通过应用的[ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md)获得。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| ClipboardPolicy | 设备剪贴板策略。|

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let tokenId: number = 586874394;
try {
    let result: string = securityManager.getAppClipboardPolicy(wantTemp, tokenId);
    console.info(`Succeeded in getting password policy, result : ${result}`);
} catch(err) {
    console.error(`Failed to set clipboard policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.setWatermarkImage<sup>14+</sup>

setWatermarkImage(admin: Want, bundleName: string, source: string | image.PixelMap, accountId: number): void

指定应用设置水印策略，当前仅支持2in1使用。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 设备管理应用。                  |
| bundleName | string    | 是   | 被设置水印的应用包名。                                                       |
| image | string \| [image.PixelMap](../apis-image-kit/js-apis-image.md)  | 是   | string表示图像路径，图像路径为应用沙箱路径等应用有权限访问的路径。<br>image.PixelMap表示图像对象，图像像素占用大小不能超过500KB。                                                       |
| accountId     | number     | 是   | 用户ID。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let bundleName: string = 'com.example.myapplication';
let image: string = '/data/storage/el1/base/test.png';
let accountId: number = 100;
try {
    securityManager.setWatermarkImage(wantTemp, bundleName, image, accountId);
    console.info(`Succeeded in setting set watermarkImage policy.`);
} catch(err) {
    console.error(`Failed to set watermarkImage policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.cancelWatermarkImage<sup>14+</sup>

cancelWatermarkImage(admin: Want, bundleName: string, accountId: number): void

指定应用取消水印策略，当前仅支持2in1使用。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 设备管理应用。                  |
| bundleName | string    | 是   | 被取消水印的应用包名。                                                       |
| accountId     | number     | 是   | 用户ID。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let bundleName: string = 'com.example.myapplication';
let accountId: number = 100;
try {
    securityManager.cancelWatermarkImage(wantTemp, bundleName, accountId);
    console.info(`Succeeded in setting cancel watermarkImage policy.`);
} catch(err) {
    console.error(`Failed to cancel watermarkImage policy. Code: ${err.code}, message: ${err.message}`);
}
```

## CertBlob

证书信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称   | 类型       | 必填 | 说明               |
| ------ | ---------- | ---- | ------------------ |
| inData | Uint8Array | 是   | 证书的二进制内容。 |
| alias  | string     | 是   | 证书别名。         |

## PasswordPolicy

设备口令策略。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称         | 类型     | 必填 | 说明                            |
| ----------- | --------| ---- | ------------------------------- |
| complexityRegex | string | 否 | 口令复杂度正则表达式。 |
| validityPeriod | number | 否 | 密码有效期（单位：毫秒）。 |
| additionalDescription | string | 否 | 描述文本。 |

## ClipboardPolicy

设备剪贴板策略。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称         | 值 | 说明                            |
| ----------- | -------- | ------------------------------- |
| DEFAULT | 0  | 默认。 |
| IN_APP | 1  | 剪贴板可在同一应用使用。 |
| LOCAL_DEVICE | 2  | 剪贴板可在同一设备使用。 |
| CROSS_DEVICE | 3  | 剪贴板可跨设备使用。 |