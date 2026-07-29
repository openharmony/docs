# @ohos.enterprise.bundleManager（包管理）
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

本模块提供包管理能力，包括安装和卸载应用包，管理包安装允许名单、包安装禁止名单、包卸载禁止名单、可安装应用的分发类型等。在企业设备管理场景中，通过这些能力可以实现应用安装卸载的精细化管控，防止未授权应用的安装和卸载，保障企业设备安全，降低安全风险。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对设备管理应用开放，且调用接口前需激活设备管理应用，具体请参考[MDM Kit开发指南](../../mdm/mdm-kit-guide.md)。

## 导入模块

```ts
import { bundleManager } from '@kit.MDMKit';
```

## bundleManager.addAllowedInstallBundlesSync

addAllowedInstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

添加应用至应用程序包安装允许名单，添加至允许名单的应用允许在当前/指定用户下安装，其它非允许名单应用不允许安装。系统应用卸载后重新安装不会受到接口限制；而普通应用在卸载后重新安装时，则会受到接口限制。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                       |
| appIds    | Array&lt;string&gt;                                     | 是   | 应用ID数组。<br/>**说明：** 从API version 21版本开始，支持传入应用的[appId](../../quick-start/common-problem-of-application.md#什么是appid)和[appIdentifier](../../quick-start/common-problem-of-application.md#什么是appidentifier)，推荐使用[appIdentifier](../../quick-start/common-problem-of-application.md#什么是appidentifier)。API version 20及之前版本，仅支持[appId](../../quick-start/common-problem-of-application.md#什么是appid)。 |
| accountId | number                                                  | 否   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。<br> - 调用接口时，若传入accountId，表示指定用户。<br> - 调用接口时，若未传入accountId，表示当前用户。 |

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  bundleManager.addAllowedInstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in adding allowed install bundles.');
} catch (err) {
  console.error(`Failed to add allowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.removeAllowedInstallBundlesSync

removeAllowedInstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

在应用程序包安装允许名单中移除应用，在允许名单存在的情况下，不在应用程序包安装允许名单中的应用不允许在当前/指定用户下安装。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                               |
| appIds    | Array&lt;string&gt;                                     | 是   | 应用ID数组。<br/>**说明：** 从API version 21版本开始，数组中的元素支持使用[appId](../../quick-start/common-problem-of-application.md#什么是appid)和[appIdentifier](../../quick-start/common-problem-of-application.md#什么是appidentifier)，仅移除传入的[appId](../../quick-start/common-problem-of-application.md#什么是appid)（或[appIdentifier](../../quick-start/common-problem-of-application.md#什么是appidentifier)），不会移除同一应用的[appIdentifier](../../quick-start/common-problem-of-application.md#什么是appidentifier)（或[appId](../../quick-start/common-problem-of-application.md#什么是appid)）。API version 20及之前版本，数组中的元素只支持使用[appId](../../quick-start/common-problem-of-application.md#什么是appid)。       |
| accountId | number                                                  | 否   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。<br> - 调用接口时，若传入accountId，表示指定用户。<br> - 调用接口时，若未传入accountId，表示当前用户。 |

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  bundleManager.removeAllowedInstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in removing allowed install bundles.');
} catch (err) {
  console.error(`Failed to remove allowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.getAllowedInstallBundlesSync

getAllowedInstallBundlesSync(admin: Want | null, accountId?: number): Array&lt;string&gt;

获取当前/指定用户下的应用程序包安装允许名单。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。<br>当设备存在多个MDM应用时，API版本26.0.0之前，传入Want时查询对应企业设备管理应用设置的策略。从API版本26.0.0开始，新增支持传入null时查询实际生效的策略。|
| accountId | number                                                  | 否   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。<br> - 调用接口时，若传入accountId，表示指定用户。<br> - 调用接口时，若未传入accountId，表示当前用户。 |

**返回值：**

| 类型                | 说明                           |
| ------------------- | ------------------------------ |
| Array&lt;string&gt; | 返回当前/指定用户下的应用程序包安装允许名单。 |

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: Array<string> = bundleManager.getAllowedInstallBundlesSync(wantTemp, 100);
  console.info(`Succeeded in getting allowed install bundles, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get allowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.addDisallowedInstallBundlesSync

addDisallowedInstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

添加应用至应用程序包安装禁止名单，添加至禁止名单的应用不允许在当前/指定用户下安装。系统应用卸载后重新安装不会受到接口限制；而普通应用在卸载后重新安装时，则会受到接口限制。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                               |
| appIds    | Array&lt;string&gt;                                     | 是   | 应用ID数组。<br/>**说明：** 从API version 21版本开始，支持传入应用的[appId](../../quick-start/common-problem-of-application.md#什么是appid)和[appIdentifier](../../quick-start/common-problem-of-application.md#什么是appidentifier)，推荐使用[appIdentifier](../../quick-start/common-problem-of-application.md#什么是appidentifier)。API version 20及之前版本，仅支持[appId](../../quick-start/common-problem-of-application.md#什么是appid)。 |
| accountId | number                                                  | 否   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。<br> - 调用接口时，若传入accountId，表示指定用户。<br> - 调用接口时，若未传入accountId，表示当前用户。 |

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  bundleManager.addDisallowedInstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in adding disallowed install bundles.');
} catch (err) {
  console.error(`Failed to add disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.removeDisallowedInstallBundlesSync

removeDisallowedInstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

在应用程序包安装禁止名单中移除应用，在禁止名单存在的情况下，在应用程序包安装禁止名单中的应用不允许在当前/指定用户下安装。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                               |
| appIds    | Array&lt;string&gt;                                     | 是   | 应用ID数组。<br/>**说明：** 从API version 21版本开始，数组中的元素支持使用[appId](../../quick-start/common-problem-of-application.md#什么是appid)和[appIdentifier](../../quick-start/common-problem-of-application.md#什么是appidentifier)，仅移除传入的[appId](../../quick-start/common-problem-of-application.md#什么是appid)（或[appIdentifier](../../quick-start/common-problem-of-application.md#什么是appidentifier)），不会移除同一应用的[appIdentifier](../../quick-start/common-problem-of-application.md#什么是appidentifier)（或[appId](../../quick-start/common-problem-of-application.md#什么是appid)）。API version 20及之前版本，数组中的元素只支持使用[appId](../../quick-start/common-problem-of-application.md#什么是appid)。               |
| accountId | number                                                  | 否   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。<br> - 调用接口时，若传入accountId，表示指定用户。<br> - 调用接口时，若未传入accountId，表示当前用户。 |

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  bundleManager.removeDisallowedInstallBundlesSync(wantTemp, appIds, 100)
  console.info('Succeeded in removing disallowed install bundles.');
} catch (err) {
  console.error(`Failed to remove disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.getDisallowedInstallBundlesSync

getDisallowedInstallBundlesSync(admin: Want | null, accountId?: number): Array&lt;string&gt;

获取当前/指定用户下的应用程序包安装禁止名单。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。<br>当设备存在多个MDM应用时，API版本26.0.0之前，传入Want时查询对应企业设备管理应用设置的策略。从API版本26.0.0开始，新增支持传入null时查询实际生效的策略。|
| accountId | number                                                  | 否   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。<br> - 调用接口时，若传入accountId，表示指定用户。<br> - 调用接口时，若未传入accountId，表示当前用户。 |

**返回值：**

| 类型                | 说明                           |
| ------------------- | ------------------------------ |
| Array&lt;string&gt; | 返回当前/指定用户下的应用程序包安装禁止名单。 |

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // 参数需根据实际情况进行替换
  let result: Array<string> = bundleManager.getDisallowedInstallBundlesSync(wantTemp, 100);
  console.info(`Succeeded in getting disallowed install bundles, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.addDisallowedUninstallBundlesSync

addDisallowedUninstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

添加应用至包卸载禁止名单，添加至禁止名单的应用不允许在当前/指定用户下卸载。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                               |
| appIds    | Array&lt;string&gt;                                     | 是   | 应用ID数组。<br/>取值范围：单个用户下该名单总数不能超过200。例如100用户下已经设置了50个、101用户未设置，则100用户还能再设置150个，101用户还能再设置200个。不建议一次性设置个数大于50个，可能引入性能问题。<br/>**说明：** 从API version 21版本开始，支持传入应用的[appId](../../quick-start/common-problem-of-application.md#什么是appid)和[appIdentifier](../../quick-start/common-problem-of-application.md#什么是appidentifier)，推荐使用[appIdentifier](../../quick-start/common-problem-of-application.md#什么是appidentifier)。API version 20及之前版本，仅支持[appId](../../quick-start/common-problem-of-application.md#什么是appid)。 |
| accountId | number                                                  | 否   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。<br> - 调用接口时，若传入accountId，表示指定用户。<br> - 调用接口时，若未传入accountId，表示当前用户。 |

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  // 参数需根据实际情况进行替换
  bundleManager.addDisallowedUninstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in adding disallowed uninstall bundles.');
} catch (err) {
  console.error(`Failed to add disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.removeDisallowedUninstallBundlesSync

removeDisallowedUninstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

在包卸载禁止名单中移除应用。在禁止名单存在的情况下，在包卸载禁止名单中的应用不允许在当前/指定用户下卸载。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                               |
| appIds    | Array&lt;string&gt;                                     | 是   | 应用ID数组。<br/>取值范围：不建议一次性设置个数大于50个，可能引入性能问题。<br/>**说明：** 从API version 21版本开始，数组中的元素支持使用[appId](../../quick-start/common-problem-of-application.md#什么是appid)和[appIdentifier](../../quick-start/common-problem-of-application.md#什么是appidentifier)，仅移除传入的[appId](../../quick-start/common-problem-of-application.md#什么是appid)（或[appIdentifier](../../quick-start/common-problem-of-application.md#什么是appidentifier)），不会移除同一应用的[appIdentifier](../../quick-start/common-problem-of-application.md#什么是appidentifier)（或[appId](../../quick-start/common-problem-of-application.md#什么是appid)）。API version 20及之前版本，数组中的元素只支持使用[appId](../../quick-start/common-problem-of-application.md#什么是appid)。                   |
| accountId | number                                                  | 否   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。<br> - 调用接口时，若传入accountId，表示指定用户。<br> - 调用接口时，若未传入accountId，表示当前用户。 |

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  // 参数需根据实际情况进行替换
  bundleManager.removeDisallowedUninstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in removing disallowed uninstall bundles.');
} catch (err) {
  console.error(`Failed to remove disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.getDisallowedUninstallBundlesSync

getDisallowedUninstallBundlesSync(admin: Want | null, accountId?: number): Array&lt;string&gt;

获取当前/指定用户下包卸载禁止名单。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。<br>当设备存在多个MDM应用时，API版本26.0.0之前，传入Want时查询对应企业设备管理应用设置的策略。从API版本26.0.0开始，新增支持传入null时查询实际生效的策略。|
| accountId | number                                                  | 否   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。<br> - 调用接口时，若传入accountId，表示指定用户。<br> - 调用接口时，若未传入accountId，表示当前用户。 |

**返回值：**

| 类型                | 说明                           |
| ------------------- | ------------------------------ |
| Array&lt;string&gt; | 返回当前/指定用户下的包卸载禁止名单。 |

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // 参数需根据实际情况进行替换
  let result: Array<string> = bundleManager.getDisallowedUninstallBundlesSync(wantTemp, 100);
  console.info(`Succeeded in getting disallowed uninstall bundles, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.uninstall

uninstall(admin: Want, bundleName: string, userId?: number, isKeepData?: boolean): Promise&lt;void&gt;

卸载当前/指定用户下的指定包，选择是否保留包数据（由isKeepData指定）。使用Promise异步回调。调用成功后，应用被卸载，数据根据isKeepData参数保留或删除。

> **说明：**
>
> 当应用为不可卸载的预置应用或者通过[addDisallowedUninstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanageradddisalloweduninstallbundlessync)接口设置了不允许卸载时，调用此接口卸载应用会返回401错误码。

**需要权限：** ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名     | 类型                                                    | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                               |
| bundleName | string                                                  | 是   | 应用程序包名。                                                       |
| userId     | number                                                  | 否   | 用户ID，取值范围：大于等于0。<br> - 调用接口时，若传入userId，表示指定用户。<br> - 调用接口时，若未传入userId，表示当前用户。 |
| isKeepData | boolean                                                 | 否   | 是否保留包数据，true表示保留，false表示不保留。              |

**返回值：**

| 类型                | 说明                                                  |
| ------------------- | ----------------------------------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当包卸载失败时抛出错误对象。 |

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// 参数需根据实际情况进行替换
bundleManager.uninstall(wantTemp, 'bundleName', 100, true).then(() => {
  console.info('Succeeded in uninstalling bundles.');
}).catch((err: BusinessError) => {
  console.error(`Failed to uninstall bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.install

install(admin: Want, hapFilePaths: Array\<string>, installParam?: InstallParam): Promise\<void>

安装指定路径下的应用包。使用Promise异步回调。<br/>此接口只能安装分发类型为enterprise_mdm（MDM应用）和enterprise_normal（普通企业应用）类型的应用，可以通过[getBundleInfoForSelf](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口查询应用自身的[BundleInfo](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md)，其中BundleInfo.appInfo.appDistributionType为应用的分发类型。自API版本26.0.0起，建议使用[installForResult](#bundlemanagerinstallforresult)，以获取更详细的错误码返回值。
> **说明：**
> 
> 该接口比较耗时，当调用此接口后，后续如果在应用主线程调用其他同步接口时需要等待该接口异步返回。

**需要权限：** ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                   |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。         |
| hapFilePaths | Array\<string>                                          | 是   | 待安装应用包路径数组。应用包路径为应用沙箱路径(应用沙箱路径和真实路径的对应关系可参见：[应用沙箱路径和真实物理路径的对应关系](../../file-management/app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系))等应用有权限访问的路径。 |
| installParam | [InstallParam](#installparam)                           | 否   | 应用包安装参数。       |

**返回值：**

| 类型                | 说明                                                    |
| ------------------- | ------------------------------------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当应用程序包安装失败时，抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9201002  | Failed to install the application.                           |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 为当前用户安装应用
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let hapFilePaths: Array<string> = ['/data/storage/el2/base/haps/entry/testinstall/ExtensionTest.hap'];

bundleManager.install(wantTemp, hapFilePaths).then(() => {
  console.info('Succeeded in installing bundles.');
}).catch((err: BusinessError) => {
  console.error(`Failed to install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 为所有用户安装应用
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let hapFilePaths: Array<string> = ['/data/storage/el2/base/haps/entry/testinstall/ExtensionTest.hap'];
const params: Record<string, string> = {
  'ohos.bms.param.enterpriseForAllUser': 'true'
};
let installParam: bundleManager.InstallParam = {
  // 需根据实际情况进行替换
  userId: 100,
  installFlag: 0,
  parameters: params
};
bundleManager.install(wantTemp, hapFilePaths, installParam).then(() => {
  console.info('Succeeded in installing bundles.');
}).catch((err: BusinessError) => {
  console.error(`Failed to install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.installForResult

installForResult(admin: Want, hapFilePaths: Array\<string>, installParam?: InstallParam): Promise\<void\>

安装指定路径下的应用包，并返回安装结果。使用Promise异步回调。<br/>此接口只能安装分发类型为enterprise_mdm（MDM应用）和enterprise_normal（普通企业应用）类型的应用，可以通过[getBundleInfoForSelf](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口查询应用自身的[BundleInfo](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md)，其中BundleInfo.appInfo.appDistributionType为应用的分发类型。

> **说明：**
> 
> 该接口比较耗时，当调用此接口后，后续如果在应用主线程调用其他同步接口时需要等待该接口异步返回。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                   |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。         |
| hapFilePaths | Array\<string>                                          | 是   | 待安装应用包路径数组。应用包路径为应用沙箱路径(应用沙箱路径和真实路径的对应关系可参见：[应用沙箱路径和真实物理路径的对应关系](../../file-management/app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系))等应用有权限访问的路径。 |
| installParam | [InstallParam](#installparam)                           | 否   | 应用包安装参数。       |

**返回值：**

| 类型                | 说明                                                    |
| ------------------- | ------------------------------------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当应用程序包安装失败时，抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9201002  | Failed to install the application.                           |
| 9201022  | Failed to install the HAP because of insufficient system disk space. |
| 9201023  | Failed to install the HAP because enterprise device management disallows the installation. |
| 9201024  | Failed to install the HAP because the HAP fails to be parsed. |
| 9201025  | Failed to install the HAP because the HAP signature fails to be verified. |
| 9201026  | Failed to install the HAP because the HAP path is invalid or the HAP is too large. |
| 9201027  | Failed to install the HAPs because they have different configuration information. |
| 9201028  | Failed to install the HAP because the isolationMode configured is not supported. |
| 9201029  | Failed to install the HAP since the version of the HAP to install is too early. |
| 9201030  | Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode. |
| 9201031  | Installation failed because the dependent module does not exist. |
| 9201032  | The specified user ID is not found. |
| 9201033  | Failed to install the HAP because the overlay check failed. |
| 9201034  | Failed to install the HSP due to missing required permissions. |
| 9201035  | Installation failed because the installation of cross-app shared libraries is not allowed. |
| 9201036  | Failed to install the HAP due to incorrect URI in the data proxy. |
| 9201037  | Failed to install the HAP due to incorrect permission configuration in the data proxy. |
| 9201038  | Failed to install the HAP due to code signature verification failure. |
| 9201039  | Failed to install the HAP due to enterprise device verification failure. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**
不传入installParam参数使用示例：
```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 为当前用户安装应用
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换bundleName，例如bundleName为com.example.myapplication，则有效路径为'/data/storage/el2/base/com.example.myapplication/haps/entry/testinstall/ExtensionTest.hap'
// 请确保对应路径下的文件必须存在，并且应用有权限访问。
let hapFilePaths: Array<string> = ['/data/storage/el2/base/bundleName/haps/entry/testinstall/ExtensionTest.hap'];

bundleManager.installForResult(wantTemp, hapFilePaths).then(() => {
  console.info('Succeeded in installing bundles.');
}).catch((err: BusinessError) => {
  // 在此处获取到错误码后，可参考接口注释中的错误原因进行相应的错误处理。
  console.error(`Failed to install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

传入installParam参数使用示例：
```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 为所有用户安装应用
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换bundleName，例如bundleName为com.example.myapplication，则有效路径为'/data/storage/el2/base/com.example.myapplication/haps/entry/testinstall/ExtensionTest.hap'
// 请确保对应路径下的文件必须存在，并且应用有权限访问。
let hapFilePaths: Array<string> = ['/data/storage/el2/base/bundleName/haps/entry/testinstall/ExtensionTest.hap'];
const params: Record<string, string> = {
  'ohos.bms.param.enterpriseForAllUser': 'true'
};
let installParam: bundleManager.InstallParam = {
  // 需根据实际情况进行替换
  userId: 100,
  installFlag: 0,
  parameters: params
};
bundleManager.installForResult(wantTemp, hapFilePaths, installParam).then(() => {
  console.info('Succeeded in installing bundles.');
}).catch((err: BusinessError) => {
  // 在此处获取到错误码后，可参考接口注释中的错误原因进行相应的错误处理。
  console.error(`Failed to install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.getInstalledBundleList<sup>20+</sup>

getInstalledBundleList(admin: Want, accountId: number): Promise\<Array\<BundleInfo>>

获取设备指定用户下已安装应用列表。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_ALL_BUNDLE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                   |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                       |
| accountId    | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |

**返回值：**

| 类型                | 说明                                                    |
| ------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[BundleInfo](#bundleinfo20)&gt;&gt; | Promise对象，返回已安装应用包信息。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let accountId: number = 100;
bundleManager.getInstalledBundleList(wantTemp, accountId).then((result) => {
  console.info('Succeeded in getting installed bundle list.');
}).catch((err: BusinessError) => {
  console.error(`Failed to get installed bundle list. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.getInstalledBundleList<sup>23+</sup>

getInstalledBundleList(admin: Want, accountId: number, bundleInfoGetFlag: number): Promise\<Array\<BundleInfo>>

根据给定的bundleInfoGetFlag获取设备指定用户下已安装应用列表。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_ALL_BUNDLE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                   |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。         |
| accountId    | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |
| [bundleInfoGetFlag](js-apis-enterprise-bundleManager.md#bundleinfogetflag23)    | number              | 是   | 指定返回的BundleInfo所包含的信息。 |

**返回值：**

| 类型                | 说明                                                    |
| ------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[BundleInfo](#bundleinfo20)&gt;&gt; | Promise对象，返回已安装应用包信息。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let accountId: number = 100;
let bundleInfoGetFlag: number = bundleManager.BundleInfoGetFlag.WITH_APPLICATION_INFO
  | bundleManager.BundleInfoGetFlag.WITH_SIGNATURE_INFO;
bundleManager.getInstalledBundleList(wantTemp, accountId, bundleInfoGetFlag).then((result) => {
  console.info('Succeeded in getting installed bundle list.');
}).catch((err: BusinessError) => {
  console.error(`Failed to get installed bundle list. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.addInstallationAllowedAppDistributionTypes<sup>20+</sup>

addInstallationAllowedAppDistributionTypes(admin: Want, appDistributionTypes: Array&lt;AppDistributionType&gt;): void

添加可安装应用的分发类型。添加成功后，当前设备可以安装对应分发类型的应用，但无法安装[AppDistributionType](#appdistributiontype20)中未添加的分发类型的应用。<br/>
应用程序签名证书的分发类型详细介绍请参见[ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md#applicationinfo-1)的appDistributionType属性。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名       | 类型                                                       | 必填 | 说明                                                         |
| ------------ | -------------------------------------------------------    | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md)    | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                       |
| appDistributionTypes  | Array&lt;[AppDistributionType](#appdistributiontype20)&gt;  | 是   | 应用程序签名证书的分发类型数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                               |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let appDistributionTypes: Array<bundleManager.AppDistributionType> = [bundleManager.AppDistributionType.APP_GALLERY];
  bundleManager.addInstallationAllowedAppDistributionTypes(wantTemp, appDistributionTypes);
  console.info('Succeeded in adding allowed appDistributionTypes.');
} catch (err) {
  console.error(`Failed to add allowed appDistributionTypes. Code: ${err.code}, message: ${err.message}`);
}
```

## bundleManager.removeInstallationAllowedAppDistributionTypes<sup>20+</sup>

removeInstallationAllowedAppDistributionTypes(admin: Want, appDistributionTypes: Array&lt;AppDistributionType&gt;): void

移除应用的分发类型。若只移除了数组中部分的分发类型，则当前设备可以安装数组中剩下的分发类型的应用，但无法安装[AppDistributionType](#appdistributiontype20)中未添加的分发类型的应用。<br/>
应用程序签名证书的分发类型详细介绍请参见[ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md#applicationinfo-1)的appDistributionType属性。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名       | 类型                                                       | 必填 | 说明                                                         |
| ------------ | -------------------------------------------------------    | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md)    | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                       |
| appDistributionTypes  | Array&lt;[AppDistributionType](#appdistributiontype20)&gt;  | 是 | 应用程序签名证书的分发类型数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                               |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let appDistributionTypes: Array<bundleManager.AppDistributionType> = [bundleManager.AppDistributionType.APP_GALLERY];
  bundleManager.removeInstallationAllowedAppDistributionTypes(wantTemp, appDistributionTypes);
  console.info('Succeeded in removing allowed appDistributionTypes.');
} catch (err) {
  console.error(`Failed to remove allowed appDistributionTypes. Code: ${err.code}, message: ${err.message}`);
}
```

## bundleManager.getInstallationAllowedAppDistributionTypes<sup>20+</sup>

getInstallationAllowedAppDistributionTypes(admin: Want | null): Array&lt;AppDistributionType&gt;

获取可安装的应用程序签名证书的分发类型。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名       | 类型                                                       | 必填 | 说明                                                         |
| ------------ | -------------------------------------------------------    | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。<br>当设备存在多个MDM应用时，API版本26.0.0之前，传入Want时查询对应企业设备管理应用设置的策略。从API版本26.0.0开始，新增支持传入null时查询实际生效的策略。|

**返回值：**

| 类型                               | 说明                      |
| ---------------------------------- | ------------------------- |
| Array&lt;[AppDistributionType](#appdistributiontype20)&gt; | 应用程序签名证书的分发类型数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.edmtest',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let result: Array<bundleManager.AppDistributionType> = bundleManager.getInstallationAllowedAppDistributionTypes(wantTemp);
  console.info(`Succeeded in getting allowed appDistributionTypes. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get allowed appDistributionTypes. Code: ${err.code}, message: ${err.message}`);
}
```

## bundleManager.installMarketApps<sup>22+</sup>

installMarketApps(admin: Want, bundleNames: Array\<string>): void

下载并安装应用市场应用。
> **说明：**
>
> 本接口调用成功后会在桌面上生成应用下载任务，此任务与从应用市场下载所创建任务一致。下载安装结束后，安装结果会通过回调[EnterpriseAdminExtensionAbility.onMarketAppInstallResult](./js-apis-EnterpriseAdminExtensionAbility.md#onmarketappinstallresult22)返回。<!--RP1--><!--RP1End-->

**需要权限：** ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                   |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。         |
| bundleNames    | Array&lt;string&gt;                                                  | 是   | 应用包名列表，一次最多传入10个。包名需与应用市场中包名一致，否则无法创建下载任务，并抛出错误码9201002。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 9201002  | Failed to install the application. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let bundleNames: Array<string> = [ 'com.huaweicloud.m' ];
try {
  bundleManager.installMarketApps(wantTemp, bundleNames);
  console.info(`Succeeded in installing market apps.`);
} catch(err) {
  console.error(`Failed to install market apps. Code: ${err.code}, message: ${err.message}`);
}
```

## bundleManager.getInstalledBundleStorageStats

getInstalledBundleStorageStats(admin: Want, bundleNames: Array\<string>, accountId: number): Promise\<Array\<BundleStorageStats>>

获取设备指定用户下已安装应用的存储占用信息。使用Promise异步回调。

> **说明：**
> 
> 1.仅能获取已安装应用的存储占用信息。
>
> 2.bundleNames参数为empty或全部传入未安装的应用包名，会抛出9200012错误码。
>
> 3.bundleNames参数传递的包名部分应用已安装，部分应用未安装时，接口返回正常，已安装的应用返回实际的存储占用信息，未安装的应用存储占用信息为0。
>
> 4.该接口支持跨用户查询，比如可以在100用户下，查询101用户下的某些应用的存储占用信息。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_GET_ALL_BUNDLE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                   |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。         |
| bundleNames  | Array&lt;string&gt;                                     | 是   | 应用包名列表。取值范围：小于等于200个应用包名。 |
| accountId    | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |

**返回值：**

| 类型                | 说明                                                    |
| ------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[BundleStorageStats](#bundlestoragestats)&gt;&gt; | Promise对象，返回已安装应用的存储占用信息。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                               |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let bundleNames: Array<string> = ['com.example.app1', 'com.example.app2'];
let accountId: number = 100;
bundleManager.getInstalledBundleStorageStats(wantTemp, bundleNames, accountId).then((result) => {
  console.info('Succeeded in getting installed bundle storage stats.');
}).catch((err: BusinessError) => {
  console.error(`Failed to get installed bundle storage stats. Code is ${err.code}, message is ${err.message}`);
});
```
<!--code_no_check-->
```ts
// 返回示例
[
  {
    "bundleName": "com.example.edmtest",
    "appSize": 38185408,
    "dataSize": 1216566
  },
  // ...
]
```


## InstallParam

应用包安装需指定的参数信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称                     | 类型                   | 只读 | 可选 | 说明                                                         |
| ------------------------ | ---------------------- | ---- | ---- | ------------------------------------------------------------ |
| userId                   | number                 | 否   | 是 | 指示用户ID，默认值：调用方所在用户，取值范围：大于等于0。    |
| installFlag              | number                 | 否   | 是 |安装标志。枚举值：0：应用初次安装，1：应用覆盖安装，2：应用免安装，默认值为0(应用初次安装)。 |
| parameters<sup>19+</sup> | Record&lt;string, string&gt; | 否   | 是 | 扩展参数，默认值为空。key取值支持"ohos.bms.param.enterpriseForAllUser"，若对应的value值为"true"，表示为所有用户安装应用。 |

## AppDistributionType<sup>20+</sup>

应用程序签名证书的分发类型。详细介绍请参见[ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md#applicationinfo-1)的appDistributionType属性。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称         | 值 | 说明                            |
| ----------- | -------- | ------------------------------- |
| APP_GALLERY | 1  | 应用市场安装的应用。 |
| ENTERPRISE | 2  | 企业应用。 |
| ENTERPRISE_NORMAL | 3  | 普通企业应用。 |
| ENTERPRISE_MDM | 4  | 企业MDM应用。 |
| INTERNALTESTING | 5  | 应用市场内测的应用。 |
| CROWDTESTING | 6  | 众包测试应用。 |

## BundleInfo<sup>20+</sup>

描述应用包信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称                              | 类型                                                         | 只读 | 可选 | 说明                                                         |
| --------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                              | string                                                       | 是   | 否   | 应用包的名称，对应[app.json5](../../quick-start/app-configuration-file.md)中配置的bundleName字段。 |
| vendor                            | string                                                       | 是   | 否   | 应用包的供应商，对应[app.json5](../../quick-start/app-configuration-file.md)中配置的vendor字段。 |
| versionCode                       | number                                                       | 是   | 否   | 应用包的版本号，对应[app.json5](../../quick-start/app-configuration-file.md)中配置的versionCode字段。 |
| versionName                       | string                                                       | 是   | 否   | 应用包的版本文本描述信息，对应[app.json5](../../quick-start/app-configuration-file.md)中配置的versionName字段。 |
| minCompatibleVersionCode          | number                                                       | 是   | 否   | 分布式场景下的应用包兼容的最低版本，对应[app.json5](../../quick-start/app-configuration-file.md)中配置的minCompatibleVersionCode字段。 |
| targetVersion                     | number                                                       | 是   | 否   | 应用运行目标版本，对应[app.json5](../../quick-start/app-configuration-file.md)中配置的targetAPIVersion字段。 |
| appInfo                           | [ApplicationInfo](#applicationinfo20)                        | 是   | 否   | 应用程序的配置信息。 |
| signatureInfo                     | [SignatureInfo](#signatureinfo20)                            | 是   | 否   | 应用包的签名信息。 |
| installTime                       | number                                                       | 是   | 否   | 应用包安装时间戳，表示从1970-01-01 08:00:00 UTC+8逝去的毫秒数，单位毫秒。 |
| updateTime                        | number                                                       | 是   | 否   | 应用包更新时间戳，表示从1970-01-01 08:00:00 UTC+8逝去的毫秒数，单位毫秒。 |
| appIndex                          | number                                                       | 是   | 否   | 应用包的分身索引标识，仅在分身应用中生效。 |
| firstInstallTime                  | number                                                       | 是   | 是   | 应用在当前设备的首次安装时间戳，表示从1970-01-01 08:00:00 UTC+8逝去的毫秒数，单位毫秒，预置应用的首次安装时间戳为1533657660000。 |


## SignatureInfo<sup>20+</sup>

描述应用包的签名信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称      | 类型           | 只读 | 可选 | 说明                        |
| --------- | -------------- | ---- | ---- | --------------------------- |
| appId     | string         | 是   | 否   | 应用的appId，表示应用的唯一标识，详情信息可参考[什么是appId](../../quick-start/common-problem-of-application.md#什么是appid)。                 |
|fingerprint| string         | 是   | 否   | 应用包的指纹信息，由签名证书通过SHA-256算法计算哈希值生成。使用的签名证书发生变化时，该字段也会发生变化。          |
|appIdentifier| string         | 是   | 否   | 应用的唯一标识。详情信息可参考[什么是appIdentifier](../../quick-start/common-problem-of-application.md#什么是appidentifier)。          |
|certificate| string         | 是   | 是   | 应用的证书公钥。           |


## ApplicationInfo<sup>20+</sup>

应用程序信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称                       | 类型                                                         | 只读 | 可选 | 说明                                                         |
| -------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                       | string                                                       | 是   | 否   | 应用包的名称，对应[app.json5](../../quick-start/app-configuration-file.md)中配置的bundleName字段。                                                 |
| description                | string                                                       | 是   | 否   | 标识应用的描述信息，对应[app.json5](../../quick-start/app-configuration-file.md)中配置的description字段。关于description的详细信息详见本表中的descriptionResource字段说明。 |
| descriptionId              | number                                                       | 是   | 否   | 标识应用的描述信息的资源id，是编译构建时根据应用配置的description自动生成的资源id。 |
| enabled                    | boolean                                                      | 是   | 否   | 判断应用程序是否可以使用，取值为true表示可以使用，取值为false表示不可使用。 |
| label                      | string                                                       | 是   | 否   | 标识应用的名称。 |
| labelId                    | number                                                       | 是   | 否   | 标识应用名称的资源id，是编译构建时根据应用配置的label自动生成的资源id。 |
| icon                       | string                                                       | 是   | 否   | 应用程序的图标，对应[app.json5](../../quick-start/app-configuration-file.md)中配置的icon字段。关于icon的详细信息详见本表中的iconResource字段说明。 |
| iconData<sup>23+</sup>     | string                                                       | 是   | 否   | 应用程序的图标，为base64编码格式。 |
| iconId                     | number                                                       | 是   | 否   | 应用程序图标的资源id，是编译构建时根据应用配置的icon自动生成的资源id。 |
| process                    | string                                                       | 是   | 否   | 应用程序的进程名称。 |
| codePath                   | string                                                       | 是   | 否   | 应用程序的安装目录。 |
| removable                  | boolean                                                      | 是   | 否   | 应用程序是否可以被移除，取值为true表示可以被移除，取值为false表示不可以被移除。 |
| accessTokenId             | number                                                       | 是   | 否   | 应用程序的accessTokenId，应用的身份标识，在程序访问控制校验接口[checkAccessToken](../apis-ability-kit/js-apis-abilityAccessCtrl.md#checkaccesstoken9)中使用。 |
| uid                       | number                                                       | 是   | 否   | 应用程序的UID。 |
| iconResource              | [Resource](#resource20) | 是 | 否 | 应用程序的图标资源信息，包含了该资源的信息的bundleName、moduleName和id。 |
| labelResource             | [Resource](#resource20) | 是 | 否 | 应用程序的标签资源信息，包含了该资源的信息的bundleName、moduleName和id。 |
| descriptionResource       | [Resource](#resource20) | 是 | 否 | 应用程序的描述资源信息，包含了该资源的信息的bundleName、moduleName和id。 |
| appDistributionType       | string                                                       | 是   | 否   | 应用程序签名证书的分发类型，详细信息请参考[ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md#applicationinfo-1)的appProvisionType字段。|
| appProvisionType          | string                                                       | 是   | 否   | 应用程序签名证书文件的类型，分为debug和release两种类型。 |
| systemApp          | boolean                                                       | 是   | 否   | 标识应用是否为系统应用，取值为true表示系统应用，取值为false表示非系统应用。 |
| debug       | boolean                                | 是   | 否   | 标识应用是否处于调试模式，取值为true表示应用处于调试模式，取值为false表示应用处于非调试模式。 |
| dataUnclearable       | boolean                      | 是   | 否   | 标识应用数据是否可被删除。true表示不可删除，false表示可以删除。 |
| nativeLibraryPath | string                                                                     | 是   | 否   | 应用程序的本地库文件路径。|
| appIndex    | number    | 是   | 否   | 应用包的分身索引标识，仅在分身应用中生效。 |
| installSource    | string    | 是   | 否   | 应用程序的安装来源，支持的取值如下：<br/> - pre-installed表示应用为第一次开机时安装的预置应用。<br/> - ota表示应用为系统升级时新增的预置应用。<br/> - recovery表示卸载后再恢复的预置应用。<br/> - bundleName表示应用由此包名对应的应用安装。<br/> - unknown表示应用安装来源未知。 |
| releaseType      | string    | 是   | 否   | 标识应用打包时使用的SDK的发布类型。当前SDK的发布类型可能为Canary、Beta、Release，其中Canary和Beta可能通过序号进一步细分，例如Canary1、Canary2、Beta1、Beta2等。开发者可通过对比应用打包依赖的SDK发布类型和OS的发布类型（[deviceInfo.distributionOSReleaseType](../apis-basic-services-kit/js-apis-device-info.md)）来判断兼容性。 |


## Resource<sup>20+</sup>

资源相关信息，包括应用包名、应用模块名、资源id。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称         | 类型     | 只读   | 可选  |说明          |
| ---------- | ------ | ----- | ----  | ---------------|
| bundleName | string | 否    | 否 | 应用的bundle名称。 |
| moduleName | string | 否    | 否 | 应用的module名称。 |
| id         | number | 否    | 否 | 资源的id值。      |

## BundleInfoGetFlag<sup>23+</sup>

包信息获取标志，指示需要获取的包信息的内容。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称                           | 值        | 说明                                                         |
| --------------------------    | ---------- | ------------------------------------------------------------ |
| DEFAULT                       | 0 | 用于获取默认包信息，不包含applicationInfo、signatureInfo的信息。 |
| WITH_APPLICATION_INFO         | 1 << 0 | 用于获取默认包信息和applicationInfo的信息，获取的applicationInfo中不包含iconData的信息。 |
| WITH_SIGNATURE_INFO           | 1 << 1 | 用于获取默认包信息和signatureInfo的信息。 |
| WITH_APPLICATION_ICON_INFO    | 1 << 2 | 用于获取默认包信息和applicationInfo的iconData信息。 |

## BundleStorageStats

应用的存储占用信息。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称      | 类型           | 只读 | 可选 | 说明                        |
| --------- | -------------- | ---- | ---- | --------------------------- |
| bundleName| string         | 否   | 否   | 应用的包名。                 |
| appSize   | number         | 否   | 否   | 应用安装文件大小，单位为Byte。<br/>应用安装文件保存在以下目录：<br/>/data/storage/el1/bundle         |
| dataSize  | number         | 否   | 否   | 应用的本地数据、分布式数据和数据库数据大小，单位为Byte。<br/>本地文件保存在以下目录（注意缓存文件目录为以下目录的子目录）：<br/>/data/storage/\${el1-el5}/base<br/>分布式文件保存在以下目录：<br/>/data/storage/el2/distributedfiles<br/>数据库文件保存在以下目录：<br/>/data/storage/\${el1-el5}/database<br/> **说明：**\${el1-el5}指的是[el1，el2，el3，el4，el5目录](../../../application-dev/file-management/app-sandbox-directory.md#应用文件目录与应用文件路径)。 |

