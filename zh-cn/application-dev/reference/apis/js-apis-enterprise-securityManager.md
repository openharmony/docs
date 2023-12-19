# @ohos.enterprise.securityManager（安全管理）

本模块提供设备安全管理的能力，包括查询安全补丁状态、查询文件加密状态等。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](enterpriseDeviceManagement-overview.md#基本概念)开放，需将[设备管理应用激活](js-apis-enterprise-adminManager.md#adminmanagerenableadmin)后调用，实现相应功能。

## 导入模块

```ts
import securityManager from '@ohos.enterprise.securityManager';
```

## securityManager.getSecurityPatchTag

getSecurityPatchTag(admin: Want): string

以同步方法查询设备安全补丁Tag。成功返回安全补丁Tag，失败抛出对应异常。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| string | 补丁Tag结果，返回补丁Tag字符串。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
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

以同步方法查询设备文件系统加密状态。成功返回设备文件系统加密状态，失败抛出对应异常。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SECURITY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API：** 此接口为系统接口。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理应用。                  |

**返回值：**

| 类型                   | 说明                                                   |
| ---------------------- | ------------------------------------------------------ |
| DeviceEncryptionStatus | 文件加密状态结构体，现只含有是否进行加密字段（bool）。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
    let result: securityManager.DeviceEncryptionStatus = securityManager.getDeviceEncryptionStatus(wantTemp);
    console.info(`Succeeded in getting device encryption status. isEncrypted: ${result.isEncrypted}`);
} catch(err) {
    console.error(`Failed to get device encryption status. Code: ${err.code}, message: ${err.message}`);
}
```

## DeviceEncryptionStatus

设备管理应用的文件系统加密状态。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称         | 类型     | 必填 | 说明                            |
| ----------- | --------| ---- | ------------------------------- |
| isEncrypted | boolean | 是   | 表示设备的文件系统是否加密。true:表示已加密  false:表示未加密 |
