# @ohos.enterprise.accountManager（账户管理）

本模块提供设备账户管理能力，包括禁止创建本地用户等。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](../../mdm/mdm-kit-guide.md#功能介绍)开放，需将设备管理应用激活后调用，实现相应功能。

## 导入模块

```ts
import { accountManager } from '@kit.MDMKit';
```

## accountManager.disallowOsAccountAddition

disallowOsAccountAddition(admin: Want, disallow: boolean, accountId?: number): void

指定设备管理应用禁止用户添加账号。

**需要权限：** ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                        |
| --------- | ------------------------------------------------------- | ---- | ----------------------------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。                                              |
| disallow  | boolean                                                 | 是   | 是否禁止创建本地用户，true表示禁止创建，false表示允许创建。 |
| accountId | number                                                  | 否   | 用户ID，指定具体用户，取值范围：大于等于0。                 |

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
  accountManager.disallowOsAccountAddition(wantTemp, true, 100);
  console.info('Succeeded in disallowing os account addition.');
} catch (err) {
  console.error(`Failed to disallow os account addition. Code: ${err.code}, message: ${err.message}`);
}
```

## accountManager.isOsAccountAdditionDisallowed

isOsAccountAdditionDisallowed(admin: Want, accountId?: number): boolean

指定设备管理应用查询是否禁止某用户添加账号。

**需要权限：** ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。                              |
| accountId | number                                                  | 否   | 用户ID，指定具体用户，取值范围：大于等于0。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示该用户禁止添加账号，<br/>返回false表示该用户允许添加账号。 |

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
  let isDisallowed: boolean = accountManager.isOsAccountAdditionDisallowed(wantTemp, 100);
  console.info(`Succeeded in querying the os account addition or not: ${isDisallowed}`);
} catch (err) {
  console.error(`Failed to query the os account addition or not. Code: ${err.code}, message: ${err.message}`);
}
```

## accountManager.addOsAccountAsync

addOsAccountAsync(admin: Want, name: string, type: osAccount.OsAccountType): Promise&lt;osAccount.OsAccountInfo&gt;

指定设备管理应用后台添加账号。使用promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是   | 设备管理应用。                                               |
| name   | string                                                       | 是   | 用户ID，指定具体用户，取值范围：大于等于0。                  |
| type   | [osAccount.OsAccountType](../apis-basic-services-kit/js-apis-osAccount.md#osaccounttype) | 是   | 要添加的账号的类型。<br/>取值范围：ADMIN、NORMAL、GUEST。<br/>· ADMIN：管理员账号。<br/>· NORMAL：普通账号。<br/>· GUEST：访客账号。 |

**返回值：**

| 类型                                                         | 说明                 |
| ------------------------------------------------------------ | -------------------- |
| [osAccount.OsAccountInfo](../apis-basic-services-kit/js-apis-osAccount.md#osaccounttype) | 返回添加的账号信息。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9201003  | Failed to add an OS account.                                 |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例**：

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError, osAccount } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

accountManager.addOsAccountAsync(wantTemp, "TestAccountName", osAccount.OsAccountType.NORMAL).then((info) => {
  console.info(`Succeeded in creating os account: ${JSON.stringify(info)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to creating os account. Code: ${err.code}, message: ${err.message}`);
});
```
