# @ohos.enterprise.accountManager（账号管理）
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

本模块提供设备账号管理能力，包括禁止创建本地账号等。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对设备管理应用开放，且调用接口前需激活设备管理应用，具体请参考[MDM Kit开发指南](../../mdm/mdm-kit-guide.md)。

## 导入模块

```ts
import { accountManager } from '@kit.MDMKit';
```

## accountManager.disallowOsAccountAddition

disallowOsAccountAddition(admin: Want, disallow: boolean, accountId?: number): void

禁止用户添加账号。调用成功后，系统将禁止指定用户或所有用户添加新账号。适用于企业设备管理场景，如防止员工随意创建本地账号、加强设备安全管理等。

**需要权限：** ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [从严管控](../../mdm/mdm-kit-multi-mdm.md#规则1从严管控)。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                       |
| disallow  | boolean                                                 | 是   | 是否禁止创建本地账号，true表示禁止创建，false表示允许创建。  |
| accountId | number                                                  | 否   | 用户ID，指定具体用户。当不传入此参数时，表示禁止所有用户添加账号；当传入此参数时，表示禁止指定用户添加账号。取值范围：大于等于0。<br/>accountId可以通过[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |

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
import { accountManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // 参数需根据实际情况进行替换
  accountManager.disallowOsAccountAddition(wantTemp, true, 100);
  console.info('Succeeded in disallowing os account addition.');
} catch (err) {
  console.error(`Failed to disallow os account addition. Code: ${err.code}, message: ${err.message}`);
}
```

## accountManager.isOsAccountAdditionDisallowed

isOsAccountAdditionDisallowed(admin: Want, accountId?: number): boolean

查询是否禁止用户添加账号。适用于企业审计和合规检查场景，帮助管理员确认账号策略执行情况。

本接口通过传入Want查询对应企业设备管理应用设置的策略，如需查询实际生效的策略，请使用[accountManager.isOsAccountAdditionDisallowed](#accountmanagerisosaccountadditiondisallowed-1)接口。

**需要权限：** ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                         |
| accountId | number                                                  | 否   | 用户ID，指定具体用户。当不传入此参数时，表示查询所有用户是否禁止添加账号；当传入此参数时，表示查询指定用户是否禁止添加账号。取值范围：大于等于0。<br/>accountId可以通过[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |

**返回值：**

| 类型    | 说明                                                       |
| ------- | ---------------------------------------------------------- |
| boolean | 返回true表示禁止添加账号。<br/>返回false表示允许添加账号。 |

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
import { accountManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // 参数需根据实际情况进行替换
  let isDisallowed: boolean = accountManager.isOsAccountAdditionDisallowed(wantTemp, 100);
  console.info(`Succeeded in querying the os account addition or not: ${isDisallowed}`);
} catch (err) {
  console.error(`Failed to query the os account addition or not. Code: ${err.code}, message: ${err.message}`);
}
```

## accountManager.isOsAccountAdditionDisallowed

isOsAccountAdditionDisallowed(admin: Want | null, accountId?: number): boolean

查询是否禁止用户添加账号。适用于企业审计和合规检查场景，帮助管理员确认账号策略执行情况。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。<br>当设备存在多个MDM应用时，传入Want时查询对应企业设备管理应用设置的策略，传入null时查询实际生效的策略。                          |
| accountId | number                                                  | 否   | 用户ID，指定具体用户。当不传入此参数时，表示查询所有用户是否禁止添加账号；当传入此参数时，表示查询指定用户是否禁止添加账号。取值范围：大于等于0。<br/>accountId可以通过[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |

**返回值：**

| 类型    | 说明                                                       |
| ------- | ---------------------------------------------------------- |
| boolean | 是否禁止添加账号。返回true表示禁止添加账号。<br/>返回false表示允许添加账号。 |

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
import { accountManager } from '@kit.MDMKit';

try {
  // 参数需根据实际情况进行替换
  let isDisallowed: boolean = accountManager.isOsAccountAdditionDisallowed(null, 100);
  console.info(`Succeeded in querying the os account addition or not: ${isDisallowed}`);
} catch (err) {
  console.error(`Failed to query the os account addition or not. Code: ${err.code}, message: ${err.message}`);
}
```

## accountManager.addOsAccountAsync

addOsAccountAsync(admin: Want, name: string, type: osAccount.OsAccountType): Promise&lt;osAccount.OsAccountInfo&gt;

后台添加账号。使用Promise异步回调。适用于企业批量创建账号或远程管理场景，无需用户交互即可完成账号创建，提升管理效率。

> **说明：**
> 
> 创建账号的流程比较耗时，当调用此接口后，后续如果在应用主线程调用其他同步接口时需要等待该接口异步返回。

**需要权限：** ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                       |
| name   | string                                                       | 是   | 账号名，指要添加的账号的名称。无法创建同名、名称为空的账号，创建同名账号时会报错误码9201003，创建名称为空的账号时会报错误码401。 |
| type   | [osAccount.OsAccountType](../apis-basic-services-kit/js-apis-osAccount.md#osaccounttype) | 是   | 要添加的账号的类型。<br/>取值范围：ADMIN、NORMAL、GUEST。<br/>· ADMIN：管理员账号。<br/>· NORMAL：普通账号。<br/>· GUEST：访客账号。 |

**返回值：**

| 类型                                                         | 说明                 |
| ------------------------------------------------------------ | -------------------- |
| Promise&lt;[osAccount.OsAccountInfo](../apis-basic-services-kit/js-apis-osAccount.md#osaccountinfo)&gt; | Promise对象，返回添加的账号信息。 |

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
import { accountManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError, osAccount } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// 参数需根据实际情况进行替换
accountManager.addOsAccountAsync(wantTemp, "TestAccountName", osAccount.OsAccountType.NORMAL).then((info) => {
  console.info(`Succeeded in creating os account: ${JSON.stringify(info)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to create os account. Code: ${err.code}, message: ${err.message}`);
});
```
## accountManager.setDomainAccountPolicy<sup>19+</sup>

setDomainAccountPolicy(admin: Want, domainAccountInfo: osAccount.DomainAccountInfo, policy: DomainAccountPolicy): void

设置域账号策略。

**需要权限：** ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在PC/2in1设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

<!--Table: 19%; 21%; 8%; 52%-->
| 参数名            | 类型                                                         | 必填 | 说明                                                         |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin             | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                       |
| domainAccountInfo | [osAccount.DomainAccountInfo](../apis-basic-services-kit/js-apis-osAccount.md#domainaccountinfo8) | 是   | 域账号信息。<br />若传入的domainAccountInfo内部属性均为空，则会设置为全局域账号策略。全局策略对所有的域账号生效。<br />若传入的domainAccountInfo内部属性不为空，则为指定域账号设置策略。<br />指定域账号策略的优先级高于全局策略，若指定域账号已有域账号策略，则全局策略对其不生效。<br />**说明：**若为指定域账号设置策略，DomainAccountInfo的serverConfigId字段必填。 |
| policy            | [DomainAccountPolicy](#domainaccountpolicy19)                | 是   | 域账号策略。<br />**说明：**设置域账号策略后须在设备侧修改域账号密码，若未修改密码，则DomainAccountPolicy中的passwordValidityPeriod、passwordExpirationNotification配置不生效。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
import { accountManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError, osAccount } from '@kit.BasicServicesKit';

async function setDomainAccountPolicy() {
  let wantTemp: Want = {
    // 需根据实际情况进行替换
    bundleName: 'com.example.myapplication',
    abilityName: 'EnterpriseAdminAbility'
  };
  let policy: accountManager.DomainAccountPolicy = {
    // 需根据实际情况进行替换
    authenticationValidityPeriod: 300,
    passwordValidityPeriod: 420,
    passwordExpirationNotification: 60
  };
  // 设置全局域账号策略
  let accountInfo: osAccount.DomainAccountInfo = {
    domain: '',
    accountName: '',
    serverConfigId: ''
  };
  try {
    accountManager.setDomainAccountPolicy(wantTemp, accountInfo, policy);
    console.info('Succeeded in setting global domainAccount policy.');
  } catch (err) {
    console.error(`Failed to set domainAccount policy. Code: ${err.code}, message: ${err.message}`);
  }
  // 设置指定域账号策略
  let accountInfo2: osAccount.DomainAccountInfo = {
    domain: '',
    accountName: '',
    serverConfigId: ''
  };
  // 需根据实际情况替换
  let userId: number = 100;
  await osAccount.getAccountManager().getOsAccountDomainInfo(userId)
    .then((domainAccountInfo: osAccount.DomainAccountInfo) => {
      accountInfo2 = domainAccountInfo;
    }).catch((err: BusinessError) => {
      console.error(`Failed to get account domain info. Code: ${err.code}, message: ${err.message}`);
    });
  try {
    accountManager.setDomainAccountPolicy(wantTemp, accountInfo2, policy);
    console.info('Succeeded in setting domain account policy.');
  } catch (err) {
    console.error(`Failed to set domain account policy. Code: ${err.code}, message: ${err.message}`);
  }
}
```



## accountManager.getDomainAccountPolicy<sup>19+</sup>

getDomainAccountPolicy(admin: Want, domainAccountInfo: osAccount.DomainAccountInfo): DomainAccountPolicy

获取域账号策略。适用于企业管理场景，如查询当前域账号策略配置、策略合规性审计等。

**需要权限：** ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在PC/2in1设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名            | 类型                                                         | 必填 | 说明                                                         |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin             | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                       |
| domainAccountInfo | [osAccount.DomainAccountInfo](../apis-basic-services-kit/js-apis-osAccount.md#domainaccountinfo8) | 是   | 域账号信息。<br />若传入的domainAccountInfo内部属性均为空，则查询全局域账号策略。<br />若传入的domainAccountInfo内部属性不为空，则查询指定域账号策略。<br />**说明：**若查询指定域账号策略，DomainAccountInfo的serverConfigId字段必填。 |

**返回值：**

| 类型                                                         | 说明                 |
| ------------------------------------------------------------ | -------------------- |
| [DomainAccountPolicy](#domainaccountpolicy19) | 域账号策略。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
import { accountManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError, osAccount } from '@kit.BasicServicesKit';

async function getDomainAccountPolicy() {
  let wantTemp: Want = {
    // 需根据实际情况进行替换
    bundleName: 'com.example.myapplication',
    abilityName: 'EnterpriseAdminAbility'
  };
  let domainAccountPolicy: accountManager.DomainAccountPolicy = {};
  // 查询全局域账号策略
  let accountInfo: osAccount.DomainAccountInfo = {
    domain: '',
    accountName: '',
    serverConfigId: ''
  };
  try {
    domainAccountPolicy = accountManager.getDomainAccountPolicy(wantTemp, accountInfo);
    console.info('Succeeded in getting global domain account policy.');
  } catch (err) {
    console.error(`Failed to get domain account policy. Code: ${err.code}, message: ${err.message}`);
  }
  // 查询指定域账号策略
  let accountInfo2: osAccount.DomainAccountInfo = {
    domain: '',
    accountName: '',
    serverConfigId: ''
  };
  // 需根据实际情况进行替换
  let userId: number = 100;
  await osAccount.getAccountManager()
    .getOsAccountDomainInfo(userId)
    .then((domainAccountInfo: osAccount.DomainAccountInfo) => {
      accountInfo2 = domainAccountInfo;
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to get account domain info. Code: ${err.code}, message: ${err.message}`);
    });
  try {
    domainAccountPolicy = accountManager.getDomainAccountPolicy(wantTemp, accountInfo2);
    console.info('Succeeded in getting domain account policy.');
  } catch (err) {
    console.error(`Failed to get domain account policy. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## DomainAccountPolicy<sup>19+</sup>

域账号策略。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

<!--Table: 28%; 10%; 8%; 8%; 46%-->
| 名称                           | 类型   | 只读 | 可选 | 说明                                                         |
| ------------------------------ | ------ | ---- | ---- |------------------------------------------------------------ |
| authenticationValidityPeriod   | number | 否   | 是   |表示域账号认证Token的有效期（单位：s），用于控制用户在Token有效期内无需重复认证即可访问系统资源。取值范围是[-1, 2147483647]。有效期起始时间为最后一次域账号的认证时间点，如登录、锁屏后解锁等。<br/>默认值为-1，表示Token永久有效。取值为0，表示Token立即失效。Token过期/失效后，用户进入系统时必须进行域账号认证，验证域账号和密码。 |
| passwordValidityPeriod         | number | 否   | 是   |表示域账号密码有效期（单位：s），用于用户定期修改密码以提升账号安全性。取值范围是[-1, 2147483647]，有效期起始时间为设备侧最后一次修改密码的时间点。<br/>默认值为-1，表示域账号密码永久有效。 |
| passwordExpirationNotification | number | 否   | 是   |表示域账号密码过期前提示时间（单位：s），取值范围是[0, 2147483647]。<br/>默认值为0，表示域账号密码过期不提示。<br/>**说明：**passwordExpirationNotification需与passwordValidityPeriod配合使用，当系统时间大于或等于（设备侧最后一次修改域账号密码时间 + passwordValidityPeriod - passwordExpirationNotification）时，会发页面通知提示密码即将过期。 |

## accountManager.createNormalOsAccount

createNormalOsAccount(admin: Want, name: string): Promise&lt;osAccount.OsAccountInfo&gt;

创建普通系统账号。使用Promise异步回调。最多可以创建2个normal类型的系统账号 ([osAccount.OsAccountType](../apis-basic-services-kit/js-apis-osAccount.md#osaccounttype)) 。
> **说明：**
> 
> 创建账号的流程比较耗时，当调用此接口后，后续如果在应用主线程调用其他同步接口时需要等待该接口异步返回。
> 
> 创建系统账号对设备的性能影响较大，此接口仅支持12GB及以上运行内存的手机、平板设备使用。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                       |
| name   | string                                                       | 是   | 系统账号名称。系统账号名称不能重复且不能为空，会报错误码9200012。 |

**返回值：**

| 类型                                                         | 说明                 |
| ------------------------------------------------------------ | -------------------- |
| Promise&lt;[osAccount.OsAccountInfo](../apis-basic-services-kit/js-apis-osAccount.md#osaccountinfo)&gt; | Promise对象，返回创建的系统账号信息。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                                 |
| 9201003  | Failed to add an OS account.                                 |
| 9201040  | The number of accounts reaches the upper limit.                           |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 204      | Access denied due to user access control policy. Possible causes: 1. The operation is restricted by the OS-account constraint; 2. The required privilege for the operation has not been granted. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例**：

```ts
import { accountManager } from '@kit.MDMKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { osAccount } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// 创建普通系统账号，需要传入账号名称
accountManager.createNormalOsAccount(wantTemp, "TestAccountName").then((accountInfo: osAccount.OsAccountInfo) => {
  console.info('Succeeded in creating normal os account, accountInfo: ' + JSON.stringify(accountInfo));
}).catch((err: BusinessError) => {
  console.error(`Failed to create normal os account: code is ${err.code}, message is ${err.message}`);
});
```

## accountManager.removeOsAccount

removeOsAccount(admin: Want, accountId: number): Promise&lt;void&gt;

移除系统账号。使用Promise异步回调。当前仅支持手机、平板设备使用，可以移除使用[createNormalOsAccount](#accountmanagercreatenormalosaccount)创建的普通系统账号（normal类型）和[addOsAccountAsync](#accountmanageraddosaccountasync)创建的系统账号（admin、normal、guest类型），不可移除默认系统账号（ID为100）。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                       |
| accountId   | number                                                  | 是   | 系统账号ID，指将被移除系统账号的ID。不可移除默认系统账号 (ID为100) ，会报错误码9201041。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当移除系统账号失败时，会抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                                 |
| 9200016  | Service timeout.                                 |
| 9201041  | Restricted account.                           |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 204      | Access denied due to user access control policy. Possible causes: 1. The operation is restricted by the OS-account constraint; 2. The required privilege for the operation has not been granted. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例**：

```ts
import { accountManager } from '@kit.MDMKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { osAccount } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// 创建普通系统账号
accountManager.createNormalOsAccount(wantTemp, "TestAccountName").then((accountInfo: osAccount.OsAccountInfo) => {
  console.info('Succeeded in creating normal os account, accountInfo: ' + JSON.stringify(accountInfo));
  // 根据系统账号ID移除创建的账号
  let accountId: number = accountInfo.localId;
  return accountManager.removeOsAccount(wantTemp, accountId);
}).then(() => {
  console.info('Succeeded in removing os account');
}).catch((err: BusinessError) => {
  console.error(`Failed to create and remove normal os account: code is ${err.code}, message is ${err.message}`);
});
```

## accountManager.activateOsAccount

activateOsAccount(admin: Want, accountId: number): Promise&lt;void&gt;

切换系统账号。使用Promise异步回调。当前仅支持手机、平板设备使用，只能在[createNormalOsAccount](#accountmanagercreatenormalosaccount)创建的普通系统账号和默认系统账号 (ID为100) 之间切换。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_INTERACT_ACROSS_LOCAL_ACCOUNTS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                      |
| accountId   | number                                                  | 是   | 系统账号ID。切换不存在的系统账号，会报错误码9200012。切换受限制的系统账号，例如使用[addOsAccountAsync](#accountmanageraddosaccountasync)创建的系统账号，会报错误码9201041。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当切换系统账号失败时，会抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                                 |
| 9200016  | Service timeout.                                 |
| 9201041  | Restricted account.                            |
| 9201046  | The number of signed-in accounts reaches the upper limit.                            |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例**：

```ts
import { accountManager } from '@kit.MDMKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { osAccount } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// 创建普通系统账号
accountManager.createNormalOsAccount(wantTemp, "TestAccountName").then((accountInfo: osAccount.OsAccountInfo) => {
  console.info('Succeeded in creating normal os account, accountInfo: ' + JSON.stringify(accountInfo));
  // 根据系统账号ID切换账号
  let accountId: number = accountInfo.localId;
  return accountManager.activateOsAccount(wantTemp, accountId);
}).then(() => {
  console.info('Succeeded in activating os account');
}).catch((err: BusinessError) => {
  console.error(`Failed to create and activate normal os account: code is ${err.code}, message is ${err.message}`);
});
```
