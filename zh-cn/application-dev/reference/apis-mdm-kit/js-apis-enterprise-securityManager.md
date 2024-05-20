

# @ohos.enterprise.securityManager（安全管理）

本模块提供设备安全管理的能力，包括查询安全补丁状态、查询文件加密状态等。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](enterpriseDeviceManagement-overview.md#基本概念)开放，需将设备管理应用激活后调用，实现相应功能。

## 导入模块

```ts
import securityManager from '@ohos.enterprise.securityManager';
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

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | the application is not an administrator of the device.       |
| 9200002  | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
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
