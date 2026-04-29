# @ohos.enterprise.securityManager（安全管理）
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

本模块提供设备安全管理的能力，包括查询安全补丁状态、查询文件加密状态等。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对设备管理应用开放，且调用接口前需激活设备管理应用，具体请参考[MDM Kit开发指南](../../mdm/mdm-kit-guide.md)。

## 导入模块

```ts
import { securityManager } from '@kit.MDMKit';
```

## securityManager.uninstallUserCertificate

uninstallUserCertificate(admin: Want, certUri: string): Promise&lt;void&gt;

卸载用户证书，使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名  | 类型                                                    | 必填 | 说明                              |
| ------- | ------------------------------------------------------- | ---- | --------------------------------- |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                    |
| certUri | string                                                  | 是   | 证书uri，由安装用户证书接口[installUserCertificate](#securitymanagerinstallusercertificate)设置返回。 |

**返回值：**

| 类型                | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当卸载用户证书失败时会抛出错误对象。 |

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
import { securityManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let aliasStr = "certName";
securityManager.uninstallUserCertificate(wantTemp, aliasStr).then(() => {
  console.info(`Succeeded in uninstalling user certificate.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to uninstall user certificate. Code is ${err.code}, message is ${err.message}`);
});
```

## securityManager.installUserCertificate

installUserCertificate(admin: Want, certificate: CertBlob): Promise&lt;string&gt;

安装用户证书，使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                                                    | 必填 | 说明           |
| ----------- | ------------------------------------------------------- | ---- | -------------- |
| admin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| certificate | [CertBlob](#certblob)                                   | 是   | 证书信息。证书文件应放在应用沙箱路径(应用沙箱路径和真实路径的对应关系可参见：[应用沙箱路径和真实物理路径的对应关系](../../file-management/app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系))等应用有权限访问的路径下。     |

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

<!--code_no_check-->
```ts
import { securityManager } from '@kit.MDMKit';
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let certFileArray: Uint8Array = new Uint8Array();
// 变量context需要在MainAbility的onCreate回调函数中进行初始化
// test.cer需要放置在rawfile目录下
// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
const context = this.getUIContext().getHostContext() as common.UIAbilityContext;
context.resourceManager.getRawFileContent("test.cer").then((value) => {
  certFileArray = value;
  securityManager.installUserCertificate(wantTemp, { inData: certFileArray, alias: "cert_alias_xts" })
    .then((result) => {
      console.info(`Succeeded in installing user certificate, result : ${JSON.stringify(result)}`);
    }).catch((err: BusinessError) => {
      console.error(`Failed to install user certificate. Code: ${err.code}, message: ${err.message}`);
  })
}).catch((err: BusinessError) => {
  console.error(`Failed to get raw file content. message: ${err.message}`);
  return;
});
```

## securityManager.installUserCertificate<sup>18+</sup>

installUserCertificate(admin: Want, certificate: CertBlob, accountId: number): string

支持按系统账户安装用户证书。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                                                    | 必填 | 说明           |
| ----------- | ------------------------------------------------------- | ---- | -------------- |
| admin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| certificate | [CertBlob](#certblob)                                   | 是   | 证书信息。证书文件应放在应用沙箱路径(应用沙箱路径和真实路径的对应关系可参见：[应用沙箱路径和真实物理路径的对应关系](../../file-management/app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系))等应用有权限访问的路径下。     |
| accountId   | number                                                  | 是   | 用户ID，指定具体用户，取值范围：大于等于0。accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |

**返回值：**

| 类型                  | 说明                                                 |
| --------------------- | ---------------------------------------------------- |
| string      | 返回当前证书安装后的uri，用于卸载证书。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9201001  | Failed to manage the certificate.                            |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

<!--code_no_check-->
```ts
import { securityManager } from '@kit.MDMKit';
import { common, Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let certFileArray: Uint8Array = new Uint8Array();
let accountId: number = 100;
// 变量context需要在MainAbility的onCreate回调函数中进行初始化
// test.cer需要放置在rawfile目录下
// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
const context = this.getUIContext().getHostContext() as common.UIAbilityContext;
context.resourceManager.getRawFileContent("test.cer").then((value) => {
  certFileArray = value;
  try {
    let result: string = securityManager.installUserCertificate(wantTemp, { inData: certFileArray, alias: "cert_alias_xts" }, accountId);
    console.info(`Succeeded in installing user certificate. result: ${result}`);
  } catch (err) {
    console.error(`Failed to install user certificate. Code: ${err.code}, message: ${err.message}`);
  }
});
```
## securityManager.getUserCertificates<sup>18+</sup>

getUserCertificates(admin: Want, accountId: number): Array&lt;string&gt;

获取指定系统账户下的用户证书信息。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                               |
| accountId | number                                               | 是   | 用户ID，指定具体用户，取值范围：大于等于0。accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| Array&lt;string&gt; | 返回在指定用户ID下安装的所有用户证书。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { securityManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let accountId: number = 100;
try {
  let result: Array<string> = securityManager.getUserCertificates(wantTemp, accountId);
  console.info(`Succeeded in getting the uri list of user Certificates. result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get the uri list of user Certificates. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.getSecurityStatus

getSecurityStatus(admin: Want, item: string): string

获取当前设备安全策略信息。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                               |
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
import { securityManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: string = securityManager.getSecurityStatus(wantTemp, 'patch');
  console.info(`Succeeded in getting security patch tag. tag: ${result}`);
} catch (err) {
  console.error(`Failed to get security patch tag. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.setPasswordPolicy

setPasswordPolicy(admin: Want, policy: PasswordPolicy): void

设置设备锁屏口令策略。当用户设置锁屏口令时，如果设置的锁屏口令不符合要求，会有安全提示重新设置锁屏口令。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                  |
| policy | [PasswordPolicy](#passwordpolicy) | 是 | 设备锁屏口令策略。 |

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
import { securityManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let policy: securityManager.PasswordPolicy = {
  complexityRegex: '^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[!@#$%^&*])[a-zA-Z\\d!@#$%^&*]{8,}$',
  validityPeriod: 1,
  additionalDescription: '至少八个字符，至少一个大写字母，一个小写字母，一个数字和一个特殊字符',
};
try {
  securityManager.setPasswordPolicy(wantTemp, policy);
  console.info(`Succeeded in setting password policy.`);
} catch(err) {
  console.error(`Failed to set password policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.getPasswordPolicy

getPasswordPolicy(admin: Want): PasswordPolicy

获取设备锁屏口令策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                  |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| [PasswordPolicy](#passwordpolicy) | 设备锁屏口令策略。 |

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
import { securityManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: securityManager.PasswordPolicy = securityManager.getPasswordPolicy(wantTemp);
  console.info(`Succeeded in getting password policy, result : ${JSON.stringify(result)}`);
} catch(err) {
  console.error(`Failed to get password policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.setAppClipboardPolicy

setAppClipboardPolicy(admin: Want, tokenId: number, policy: ClipboardPolicy): void

设置设备剪贴板策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [从严管控](../../mdm/mdm-kit-multi-mdm.md#规则1从严管控)。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                  |
| tokenId | number | 是 | 目标应用的身份标识。可通过[bundleManager.getApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md)获取accessTokenId。当前只支持最多100个tokenId被保存策略。 |
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
import { securityManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let tokenId: number = 586874394;
try {
  securityManager.setAppClipboardPolicy(wantTemp, tokenId, securityManager.ClipboardPolicy.IN_APP);
  console.info(`Succeeded in setting clipboard policy.`);
} catch(err) {
  console.error(`Failed to set clipboard policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.getAppClipboardPolicy

getAppClipboardPolicy(admin: Want, tokenId?: number): string

获取设备剪贴板策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。      |
| tokenId | number | 否 | 目标应用的身份标识。可通过[bundleManager.getApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md)获取accessTokenId。当前只支持最多100个tokenId被保存策略。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| string | 返回JSON字符串形式的设备剪贴板策略。|

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
import { securityManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let tokenId: number = 586874394;
try {
  let result: string = securityManager.getAppClipboardPolicy(wantTemp, tokenId);
  console.info(`Succeeded in getting password policy, result : ${result}`);
} catch(err) {
  console.error(`Failed to set clipboard policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.setAppClipboardPolicy<sup>18+</sup>

setAppClipboardPolicy(admin: Want, bundleName: string, accountId: number, policy: ClipboardPolicy): void

设置指定用户下指定应用的设备剪贴板策略。当前只支持最多保存100个策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [从严管控](../../mdm/mdm-kit-multi-mdm.md#规则1从严管控)。

**参数：**

| 参数名     | 类型                                                      | 必填  | 说明                                                                                                                                                        |
| -------    | ------------------------------------------------------- | --- | --------------------------------------------------------------------------------------------------------------------------------------------------------- |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                                                                                                                          |
| bundleName | string                                                  | 是   | 被设置剪贴板策略的应用包名。                                                                                                                                      |
| accountId  | number                                                  | 是   | 用户ID，指定具体用户，取值范围：大于等于0。accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |
| policy     | [ClipboardPolicy](#clipboardpolicy)                     | 是   | 剪贴板策略。                                                                                                                                                    |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                                                                                                                            |
| ------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                                                                              |
| 9200002 | The administrator application does not have permission to manage the device.                                                                    |
| 201     | Permission verification failed. The application does not have the permission required to call the API.                                          |

**示例：**

```ts
import { securityManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let bundleName: string = 'com.example.myapplication';
let accountId: number = 100;
try {
  securityManager.setAppClipboardPolicy(wantTemp, bundleName, accountId, securityManager.ClipboardPolicy.IN_APP);
  console.info(`Succeeded in setting clipboard policy.`);
} catch(err) {
  console.error(`Failed to set clipboard policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.getAppClipboardPolicy<sup>18+</sup>

getAppClipboardPolicy(admin: Want, bundleName: string, accountId: number): string

获取指定用户下指定应用的设备剪贴板策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名     | 类型                                                      | 必填  | 说明                                                                                                                                                        |
| -------    | ------------------------------------------------------- | --- | --------------------------------------------------------------------------------------------------------------------------------------------------------- |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                                                                                                                               |
| bundleName | string                                                  | 是   | 被设置剪贴板策略的应用包名。                                                                                                                            |
| accountId  | number                                                  | 是   | 用户ID，指定具体用户，取值范围：大于等于0。accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |

**返回值：**

| 类型                                  | 说明       |
| ----------------------------------- | -------- |
| string | 返回JSON字符串形式的设备剪贴板策略。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                                                                                                                            |
| ------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                                                                              |
| 9200002 | The administrator application does not have permission to manage the device.                                                                    |
| 201     | Permission verification failed. The application does not have the permission required to call the API.                                          |

**示例：**

```ts
import { securityManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let bundleName: string = 'com.example.myapplication';
let accountId: number = 100;
try {
  let result: string = securityManager.getAppClipboardPolicy(wantTemp, bundleName, accountId);
  console.info(`Succeeded in getting password policy, result : ${result}`);
} catch(err) {
  console.error(`Failed to set clipboard policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.setWatermarkImage<sup>14+</sup>

setWatermarkImage(admin: Want, bundleName: string, source: string | image.PixelMap, accountId: number): void

为指定用户的指定应用设置水印策略。当前只支持最多保存100个策略。
> **说明：**
>
> 本接口适用于企业场景下为三方应用设置水印，降低企业信息泄露风险。不建议为系统应用设置水印（如：桌面应用），可能存在未知异常。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [独占](../../mdm/mdm-kit-multi-mdm.md#规则2独占), 同一个用户下的同一个应用的水印独占。不同用户、不同应用的水印[合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。      |
| bundleName | string    | 是   | 被设置水印的应用包名。                                                       |
| source | string \| [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)  | 是   | string表示图像路径，图像路径为应用沙箱路径(应用沙箱路径和真实路径的对应关系可参见：[应用沙箱路径和真实物理路径的对应关系](../../file-management/app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系))等应用有权限访问的路径。<br>image.PixelMap表示图像对象，图像像素占用大小不得超过500KB。<br>图像像素占用大小计算公式：图像宽度(像素)×图像高度 (像素)×每个像素占用的字节数（通常为4）。例如：一张 100x100 的图片，图像像素占用大小为100×100×4=40000字节。                                                       |
| accountId     | number     | 是   | 用户ID。accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |

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
import { securityManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let bundleName: string = 'com.example.myapplication';
let source: string = '/data/storage/el1/base/test.png';
let accountId: number = 100;
try {
  securityManager.setWatermarkImage(wantTemp, bundleName, source, accountId);
  console.info(`Succeeded in setting set watermarkImage policy.`);
} catch(err) {
  console.error(`Failed to set watermarkImage policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.cancelWatermarkImage<sup>14+</sup>

cancelWatermarkImage(admin: Want, bundleName: string, accountId: number): void

取消指定用户的水印策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。        |
| bundleName | string    | 是   | 被取消水印的应用包名。                                                       |
| accountId     | number     | 是   | 用户ID。accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |

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
import { securityManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let bundleName: string = 'com.example.myapplication';
let accountId: number = 100;
try {
  securityManager.cancelWatermarkImage(wantTemp, bundleName, accountId);
  console.info(`Succeeded in setting cancel watermarkImage policy.`);
} catch(err) {
  console.error(`Failed to cancel watermarkImage policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.setPermissionManagedState<sup>20+</sup>

setPermissionManagedState(admin: Want, applicationInstance: ApplicationInstance, permissions: Array\<string>, managedState: PermissionManagedState): void

设置指定应用的[user_grant权限](../../security/AccessToken/permissions-for-all-user.md)的管理策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USER_GRANT_PERMISSION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** 同一个应用实例的同一个权限[独占](../../mdm/mdm-kit-multi-mdm.md#规则2独占)，不同应用实例不同权限[合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。      |
| applicationInstance    | [ApplicationInstance](#applicationinstance20)  | 是 | 指定应用实例。 |
| permissions | Array&lt;string&gt;  | 是 | 需要管理的权限名称列表，仅支持[user_grant权限](../../security/AccessToken/permissions-for-all-user.md)。权限名称列表以[应用权限组](../../security/AccessToken/app-permission-group-list.md)为单位。列表中应包含应用在[module.json5](../../quick-start/module-configuration-file.md)中声明的同一权限组内的所有权限。例如：应用如果在module.json5中声明需要ohos.permission.READ_CALENDAR和ohos.permission.WRITE_CALENDAR权限，则传入的权限名称列表必须同时包含ohos.permission.READ_CALENDAR和ohos.permission.WRITE_CALENDAR两个权限。 |
| managedState | [PermissionManagedState](#permissionmanagedstate20) | 是 | 应用权限的管理策略。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |
| 9200010 | A conflict policy has been configured. |
| 9200012 | Parameter verification failed. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { securityManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let appInstanceTemp: securityManager.ApplicationInstance = {
  // 需根据实际情况进行替换
  appIdentifier: '736498586',
  appIndex: 0,
  accountId: 100
};
let permissionsTemp: Array<string> = ['ohos.permission.CAMERA', 'ohos.permission.LOCATION'];
try {
  securityManager.setPermissionManagedState(wantTemp, appInstanceTemp, permissionsTemp, securityManager.PermissionManagedState.GRANTED);
  console.info('Succeeded in setting permission managed state.');
} catch(err) {
  console.error(`Failed to set permission managed state.  Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.getPermissionManagedState<sup>20+</sup>

getPermissionManagedState(admin: Want, applicationInstance: ApplicationInstance, permission: string): PermissionManagedState

获取指定应用的指定[user_grant权限](../../security/AccessToken/permissions-for-all-user.md)的管理策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USER_GRANT_PERMISSION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。      |
| applicationInstance  | [ApplicationInstance](#applicationinstance20)  | 是 | 指定应用实例。 |
| permission | string | 是 | 需要获取管理策略的权限名称，仅支持user_grant权限。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| [PermissionManagedState](#permissionmanagedstate20) | 应用权限的管理策略。|

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |
| 9200012 | Parameter verification failed. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { securityManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let appInstanceTemp: securityManager.ApplicationInstance = {
  // 需根据实际情况进行替换
  appIdentifier: '736498586',
  appIndex: 0,
  accountId: 100
};
let permissionTemp: string = 'ohos.permission.ENTERPRISE_MANAGE_USER_GRANT_PERMISSION';
try {
  let result: securityManager.PermissionManagedState = securityManager.getPermissionManagedState(wantTemp, appInstanceTemp, permissionTemp);
  console.info(`Succeeded in getting permission managed state, result : ${result}`);
} catch(err) {
  console.error(`Failed to get permission managed state. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.setExternalSourceExtensionsPolicy<sup>22+</sup>

setExternalSourceExtensionsPolicy(admin: Want, policy: common.ManagedPolicy): void

设置外部来源扩展程序的管控策略。

- DEFAULT：

  默认，表示无管控策略，用户可以通过“设置-隐私与安全-高级”中的“运行外部来源的扩展程序”开关来设置是否允许扩展程序运行。

- DISALLOW：

  禁用。设置此策略后，禁止运行外部来源的扩展程序，运行中的扩展程序可继续运行，扩展程序关闭后无法启动运行。用户无法开启“设置-隐私和安全-高级”中的“运行外部来源的扩展程序”开关。

- FORCE_OPEN：

  强制开启。设置此策略后，允许运行外部来源的扩展程序，用户无法关闭“设置-隐私和安全-高级”中的“运行外部来源的扩展程序”开关。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在PC/2in1设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [独占](../../mdm/mdm-kit-multi-mdm.md#规则2独占)。

**参数：**

| 参数名     | 类型                                                      | 必填  | 说明                                                                                                                                                        |
| -------    | ------------------------------------------------------- | --- | --------------------------------------------------------------------------------------------------------------------------------------------------------- |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md#want) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                                                                                                                          |
| policy     | [common.ManagedPolicy](../apis-mdm-kit/js-apis-enterprise-common.md#managedpolicy)                     | 是   | 管控策略。                                                                                                                                                    |

**错误码：**

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                                                                                                                            |
| ------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                                                                              |
| 9200002 | The administrator application does not have permission to manage the device.                                                                    |
| 9200010 | A conflict policy has been configured.                                          |
| 9200012 | Parameter verification failed.                                          |
| 201     | Permission verification failed. The application does not have the permission required to call the API.                                          |

**示例：**

```ts
import { common, securityManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  securityManager.setExternalSourceExtensionsPolicy(wantTemp, common.ManagedPolicy.FORCE_OPEN);
  console.info(`Succeeded in setting managed policy.`);
} catch(err) {
  console.error(`Failed to set managed policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.getExternalSourceExtensionsPolicy<sup>22+</sup>

getExternalSourceExtensionsPolicy(admin: Want): common.ManagedPolicy

获取外部来源扩展程序的管控策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在PC/2in1设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名     | 类型                                                      | 必填  | 说明                                                                                                                                                        |
| -------    | ------------------------------------------------------- | --- | --------------------------------------------------------------------------------------------------------------------------------------------------------- |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md#want) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。      |                                                                               

**返回值：**

| 类型                                  | 说明       |
| ----------------------------------- | -------- |
|  [common.ManagedPolicy](../apis-mdm-kit/js-apis-enterprise-common.md#managedpolicy) | 返回ManagedPolicy枚举类型的管控策略。 |

**错误码：**

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息                                                                                                                                            |
| ------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                                                                              |
| 9200002 | The administrator application does not have permission to manage the device.                                                                    |
| 201     | Permission verification failed. The application does not have the permission required to call the API.                                          |

**示例：**

```ts
import { common, securityManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: common.ManagedPolicy = securityManager.getExternalSourceExtensionsPolicy(wantTemp);
  console.info(`Succeeded in getting managed policy, result : ${result}`);
} catch(err) {
  console.error(`Failed to get managed policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.installEnterpriseReSignatureCertificate<sup>24+</sup>

installEnterpriseReSignatureCertificate(admin: Want, certificateAlias: string, fd: number, accountId: number): void

安装企业应用重签名证书。

同一用户下最多可下发10本不同证书。证书别名作为证书的唯一标识，不支持重复下发相同别名的证书。如需更新同一别名的证书，需先调用[uninstallEnterpriseReSignatureCertificate](#securitymanageruninstallenterpriseresignaturecertificate24)进行卸载。

在MDM应用卸载或admin取消激活场景下，已安装的证书会保留在设备上，不会被移除。

在企业应用分发场景下，<!--RP2--><!--RP2End-->开发者可以使用重签名证书对企业应用进行二次签名，签名完成后将应用包提供给企业管理员。企业管理员可以将重签名后的应用安装在已部署重签名证书的企业设备上。

企业应用重签名证书使用流程：<!--RP3--><!--RP3End--><br>1.通过MDM应用安装企业应用重签名证书；<br>2.开发者利用签名工具（如ohos-signer或DevEco Studio签名插件），对原始HAP包进行二次签名；<br>3.安装重签名应用（可以通过企业私有应用市场安装）；<br>4.运行应用。

规格约束：<br>1.安装新的签名证书之后，使用旧签名证书的应用可以继续运行；<br>2.已经安装的企业应用，安装了新的企业签名证书后，已安装的应用如需更新，可以直接覆盖安装，无需先卸载原应用；<br>3.企业场景下，特别是在涉及信息安全的场景中，企业需要确保员工使用的移动设备中仅安装并运行特定的内部软件和工具。企业应用重签名证书通过统一的应用身份标识，与系统的应用管理与权限控制机制配合使用，可支持企业应用的静默安装、受控的系统能力调用及运行范围限制，从而实现企业软件在受控终端上的准入控制与安全管理。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名      | 类型                                                    | 必填 | 说明           |
| ----------- | ------------------------------------------------------- | ---- | -------------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| certificateAlias | string | 是 | 证书别名，必须以'.cer'结尾。 |
| fd | number | 是 | 表示已存在的重签名证书文件描述符，证书文件需要放置于[应用沙箱目录](../../file-management/app-sandbox-directory.md)。 |
| accountId | number | 是 | 用户ID，指定具体用户，取值范围：大于等于0。accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 9201006  | The number of certificates has reached the limit. |
| 9201007  | The certificate is invalid. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { securityManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { fileIo as fs } from '@kit.CoreFileKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// test.cer证书文件需要放置在应用沙箱目录下，并确保是有效的企业应用重签名证书
// 需根据实际情况进行替换
const filePath = '/test.cer';
// 需根据实际情况进行替换
let certificateAlias: string = 'test.cer';
let fd: number = fs.openSync(filePath, fs.OpenMode.READ_ONLY).fd;
// 需根据实际情况进行替换
let accountId: number = 100;
try {
  securityManager.installEnterpriseReSignatureCertificate(
    wantTemp, certificateAlias, fd, accountId);
  console.info('Success to install enterprise re signature certificate.');
} catch (err) {
  console.error(`Failed to install enterprise re signature certificate.
    Code: ${err.code}, message: ${err.message}`);
};
```

## securityManager.uninstallEnterpriseReSignatureCertificate<sup>24+</sup>

uninstallEnterpriseReSignatureCertificate(admin: Want, certificateAlias: string, accountId: number): void

卸载企业应用重签名证书。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                                                    | 必填 | 说明           |
| ----------- | ------------------------------------------------------- | ---- | -------------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| certificateAlias | string | 是 | 证书别名，必须以'.cer'结尾。 |
| accountId | number | 是 | 用户ID，指定具体用户，取值范围：大于等于0。accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 9201008  | The certificate does not exist. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { securityManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let certificateAlias: string = 'test.cer';
// 需根据实际情况进行替换
let accountId: number = 100;
try {
  securityManager.uninstallEnterpriseReSignatureCertificate(
    wantTemp, certificateAlias, accountId);
  console.info('Success to uninstall enterprise re signature certificate.');
} catch (err) {
  console.error(`Failed to uninstall enterprise re signature certificate.
    Code: ${err.code}, message: ${err.message}`);
};
```

## CertBlob

证书信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称   | 类型       | 只读 | 可选 | 说明               |
| ------ | ---------- | ---- | ---- | ------------------ |
| inData | Uint8Array | 否   | 否 |证书的二进制内容。 |
| alias  | string     | 否   | 否 |证书别名，别名长度小于40个字符。         |

## PasswordPolicy

设备锁屏口令策略。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称         | 类型     | 只读 | 可选 | 说明                            |
| ----------- | --------| ---- | ---- | --------------------------- |
| complexityRegex | string | 否 | 是 | 口令复杂度正则表达式。 |
| validityPeriod | number | 否 | 是 | 密码有效期（单位：毫秒）。 |
| additionalDescription | string | 否 | 是 | 口令复杂度描述文本，例如：密码中必须包含字母、数字、特殊字符，至少8个字符，最多30个字符。 |

## ClipboardPolicy

设备剪贴板策略。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称         | 值 | 说明                            |
| ----------- | -------- | ------------------------------- |
| DEFAULT | 0  | 默认，表示无策略。 |
| IN_APP | 1  | 剪贴板可在同一应用使用。 |
| LOCAL_DEVICE | 2  | 剪贴板可在同一设备使用。 |
| CROSS_DEVICE | 3  | 剪贴板可跨设备使用。 |

## ApplicationInstance<sup>20+</sup>

应用实例。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称         | 类型     | 只读 | 可选 | 说明                            |
| ----------- | --------| ---- | ---- | --------------------------- |
| appIdentifier | string | 否 | 否 | 应用[唯一标识符](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md#signatureinfo)，如果应用没有appIdentifier可使用appId代替，可以通过接口[bundleManager.getBundleInfo](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfo14-2)获取bundleInfo.signatureInfo.appIdentifier和bundleInfo.signatureInfo.appId。|
| accountId  | number     | 否 | 否 | 用户ID，指定具体用户，取值范围：大于等于0。accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。         |
| appIndex  | number     | 否 | 否 | 表示分身应用的索引，默认值为0。<br> appIndex为0时，表示主应用。appIndex大于0时，表示指定的分身应用。        |

## PermissionManagedState<sup>20+</sup>

应用权限的管理状态。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称         | 值 | 说明                            |
| ----------- | -------- | ------------------------------- |
| DEFAULT | 1  | 默认由用户授予。 |
| GRANTED | 0  | 已静默授予。 |
| DENIED | -1  | 已静默拒绝。 |