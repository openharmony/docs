# @ohos.enterprise.securityManager（安全管理）(系统接口)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima-->
<!--Designer: @liuzuming-->
<!--Tester: @lpw_work-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供设备安全管理的能力，包括查询安全补丁状态、查询文件加密状态等。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](../../mdm/mdm-kit-term.md#mdm应用设备管理应用)开放，需将[设备管理应用激活](js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin-2)后调用。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见。其他公开接口参见[@ohos.enterprise.securityManager](js-apis-enterprise-securityManager.md)。

## 导入模块

```ts
import { securityManager } from '@kit.MDMKit';
```

## securityManager.getSecurityPatchTag

getSecurityPatchTag(admin: Want): string

查询设备安全补丁Tag。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统API：** 此接口为系统接口。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                   |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| string | 补丁Tag结果，返回补丁Tag字符串。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { securityManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
    let res: string = securityManager.getSecurityPatchTag(wantTemp);
    console.info(`Succeeded in getting security patch tag. tag: ${res}`);
} catch(err) {
    console.error(`Failed to get security patch tag. Code: ${err.code}, message: ${err.message}`);
}
```
## securityManager.getDeviceEncryptionStatus

getDeviceEncryptionStatus(admin: Want): DeviceEncryptionStatus

查询设备文件系统加密状态。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统API：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 企业设备管理扩展组件。            |

**返回值：**

| 类型                                              | 说明                                                   |
| ------------------------------------------------- | ------------------------------------------------------ |
| [DeviceEncryptionStatus](#deviceencryptionstatus) | 文件加密状态结构体，现只含有是否进行加密字段（bool）。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { securityManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
    let result: securityManager.DeviceEncryptionStatus = securityManager.getDeviceEncryptionStatus(wantTemp);
    console.info(`Succeeded in getting device encryption status. isEncrypted: ${result.isEncrypted}`);
} catch(err) {
    console.error(`Failed to get device encryption status. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.getPasswordPolicy<sup>12+</sup>

getPasswordPolicy(): PasswordPolicy

获取设备口令策略。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统API：** 此接口为系统接口。

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| [PasswordPolicy](./js-apis-enterprise-securityManager.md#passwordpolicy) | 设备口令策略。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { securityManager } from '@kit.MDMKit';

try {
    let result: securityManager.PasswordPolicy = securityManager.getPasswordPolicy();
    console.info(`Succeeded in getting password policy, result : ${JSON.stringify(result)}`);
} catch(err) {
    console.error(`Failed to get password policy. Code: ${err.code}, message: ${err.message}`);
}
```

## DeviceEncryptionStatus

设备管理应用的文件系统加密状态。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统API**: 此接口为系统接口。

| 名称         | 类型     | 只读 | 可选 |  说明                            |
| ----------- | --------| ---- | ----| ---------------------------- |
| isEncrypted | boolean | 否   | 否 | 表示设备的文件系统是否加密。true：表示已加密。false：表示未加密。 |
