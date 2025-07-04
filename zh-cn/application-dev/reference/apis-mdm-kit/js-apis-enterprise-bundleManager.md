# @ohos.enterprise.bundleManager（包管理）

本模块提供包管理能力，包括添加包安装白名单、获取包安装白名单、移除包安装白名单等。

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

添加应用至应用程序包安装白名单，添加至白名单的应用允许在当前/指定用户下安装，其它非白名单应用不允许安装。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| appIds    | Array&lt;string&gt;                                     | 是   | 应用ID数组。                                                 |
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
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
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

在应用程序包安装白名单中移除应用，在白名单存在的情况下，不在应用程序包安装白名单中的应用不允许在当前/指定用户下安装。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| appIds    | Array&lt;string&gt;                                     | 是   | 应用ID数组。                                                 |
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
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  bundleManager.removeAllowedInstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in removing allowed install bundles.');
} catch (err) {
  console.error(`Failed to remove allowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.getAllowedInstallBundlesSync

getAllowedInstallBundlesSync(admin: Want, accountId?: number): Array&lt;string&gt;

获取当前/指定用户下的应用程序包安装白名单。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| accountId | number                                                  | 否   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。<br> - 调用接口时，若传入accountId，表示指定用户。<br> - 调用接口时，若未传入accountId，表示当前用户。 |

**返回值：**

| 类型                | 说明                           |
| ------------------- | ------------------------------ |
| Array&lt;string&gt; | 返回当前用户下的应用程序包安装白名单。 |

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
  let result: Array<string> = bundleManager.getAllowedInstallBundlesSync(wantTemp, 100);
  console.info(`Succeeded in getting allowed install bundles, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get allowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.addDisallowedInstallBundlesSync

addDisallowedInstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

添加应用至应用程序包安装黑名单，添加至黑名单的应用不允许在当前/指定用户下安装。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| appIds    | Array&lt;string&gt;                                     | 是   | 应用ID数组。                                                 |
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
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
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

在应用程序包安装黑名单中移除应用，在黑名单存在的情况下，在应用程序包安装黑名单中的应用不允许在当前/指定用户下安装。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| appIds    | Array&lt;string&gt;                                     | 是   | 应用ID数组。                                                 |
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
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  bundleManager.removeDisallowedInstallBundlesSync(wantTemp, appIds, 100)
  console.info('Succeeded in removing disallowed install bundles.');
} catch (err) {
  console.error(`Failed to remove disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.getDisallowedInstallBundlesSync

getDisallowedInstallBundlesSync(admin: Want, accountId?: number): Array&lt;string&gt;

获取当前/指定用户下的应用程序包安装黑名单。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| accountId | number                                                  | 否   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。<br> - 调用接口时，若传入accountId，表示指定用户。<br> - 调用接口时，若未传入accountId，表示当前用户。 |

**返回值：**

| 类型                | 说明                           |
| ------------------- | ------------------------------ |
| Array&lt;string&gt; | 返回当前用户下的应用程序包安装黑名单。 |

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
  let result: Array<string> = bundleManager.getDisallowedInstallBundlesSync(wantTemp, 100);
  console.info(`Succeeded in getting disallowed install bundles, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.addDisallowedUninstallBundlesSync

addDisallowedUninstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

添加应用至包卸载黑名单，添加至黑名单的应用不允许在当前/指定用户下卸载。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| appIds    | Array&lt;string&gt;                                     | 是   | 应用ID数组。                                                 |
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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  bundleManager.addDisallowedUninstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in adding disallowed uninstall bundles.');
} catch (err) {
  console.error(`Failed to add disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.removeDisallowedUninstallBundlesSync

removeDisallowedUninstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

在包卸载黑名单中移除应用。在黑名单存在的情况下，在包卸载黑名单中的应用不允许在当前/指定用户下卸载。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| appIds    | Array&lt;string&gt;                                     | 是   | 应用ID数组。                                                 |
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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  bundleManager.removeDisallowedUninstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in removing disallowed uninstall bundles.');
} catch (err) {
  console.error(`Failed to remove disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.getDisallowedUninstallBundlesSync

getDisallowedUninstallBundlesSync(admin: Want, accountId?: number): Array&lt;string&gt;

获取当前/指定用户下包卸载黑名单接口。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| accountId | number                                                  | 否   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。<br> - 调用接口时，若传入accountId，表示指定用户。<br> - 调用接口时，若未传入accountId，表示当前用户。 |

**返回值：**

| 类型                | 说明                           |
| ------------------- | ------------------------------ |
| Array&lt;string&gt; | 返回当前用户下的包卸载黑名单。 |

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
  let result: Array<String> = bundleManager.getDisallowedUninstallBundlesSync(wantTemp, 100);
  console.info(`Succeeded in getting disallowed uninstall bundles, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.uninstall

uninstall(admin: Want, bundleName: string, userId?: number, isKeepData?: boolean): Promise&lt;void&gt;

卸载当前/指定用户下的指定包接口，选择是否保留包数据（由isKeepData指定）。使用promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名     | 类型                                                    | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| bundleName | string                                                  | 是   | 包名。                                                       |
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
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

bundleManager.uninstall(wantTemp, 'bundleName', 100, true).then(() => {
  console.info('Succeeded in uninstalling bundles.');
}).catch((err: BusinessError) => {
  console.error(`Failed to uninstall bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.install

install(admin: Want, hapFilePaths: Array\<string>, installParam?: InstallParam): Promise\<void>

安装指定路径下的应用包。使用promise异步回调。</br>此接口只能安装分发类型为enterprise_mdm（MDM应用）和enterprise_normal（企业普通应用）类型的应用。

**需要权限：** ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                   |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。         |
| hapFilePaths | Array\<string>                                          | 是   | 待安装应用包路径数组。 |
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
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 为当前用户安装应用
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let hapFilePaths: Array<string> = ['/data/storage/el2/base/haps/entry/testinstall/ExtensionTest.hap'];

bundleManager.install(wantTemp, hapFilePaths).then(() => {
  console.info('Succeeded in installing bundles.');
}).catch((err: BusinessError) => {
  console.error(`Failed to install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 为所有用户安装应用
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let hapFilePaths: Array<string> = ['/data/storage/el2/base/haps/entry/testinstall/ExtensionTest.hap'];
const params: Record<string, string> = {
  'ohos.bms.param.enterpriseForAllUser': 'true'
};
let installParam: bundleManager.InstallParam = {
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

## bundleManager.getInstalledBundleList<sup>20+</sup>

getInstalledBundleList(admin: Want, accountId: number): Promise\<Array\<BundleInfo>>

获取设备指定用户下已安装应用列表。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_GET_ALL_BUNDLE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                   |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。         |
| accountId    | number                                                  | 是   | 用户ID，取值为正整数，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |

**返回值：**

| 类型                | 说明                                                    |
| ------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[BundleInfo](#bundleinfo20)&gt;&gt; | Promise对象，返回已安装应用包信息。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |                          |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let accountId: number = 100;
bundleManager.getInstalledBundleList(wantTemp, accountId).then((result) => {
  console.info('Succeeded in getting installed bundle list.');
}).catch((err: BusinessError) => {
  console.error(`Failed to get installed bundle list. Code is ${err.code}, message is ${err.message}`);
});
```

## InstallParam

应用包安装需指定的参数信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称                     | 类型                   | 只读 | 可选 | 说明                                                         |
| ------------------------ | ---------------------- | ---- | ---- | ------------------------------------------------------------ |
| userId                   | number                 | 否   | 是 | 指示用户id，默认值：调用方所在用户，取值范围：大于等于0。    |
| installFlag              | number                 | 否   | 是 |安装标志。枚举值：0：应用初次安装，1：应用覆盖安装，2：应用免安装，默认值为应用初次安装。 |
| parameters<sup>19+</sup> | Record&lt;string, string&gt; | 否   | 是 | 扩展参数，默认值为空。key取值支持"ohos.bms.param.enterpriseForAllUser"，若对应的value值为"true"，表示为所有用户安装应用。 |

## bundleManager.addInstallationAllowedAppDistributionTypes<sup>20+</sup>

addInstallationAllowedAppDistributionTypes(admin: Want, appDistributionTypes: Array&lt;AppDistributionType&gt;): void

添加可安装应用的分发类型。添加成功后，当前设备可以安装对应分发类型的应用，但无法安装[AppDistributionType](#appdistributiontype20)中未添加的分发类型的应用。<br/>
应用程序签名证书的分发类型详细介绍请参见[ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md#applicationinfo-1)的appDistributionType属性。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名       | 类型                                                       | 必填 | 说明                                                         |
| ------------ | -------------------------------------------------------    | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md)    | 是   | 企业设备管理扩展组件。                                       |
| appDistributionTypes  | Array&lt;[AppDistributionType](#appdistributiontype20)&gt;  | 是   | 应用程序签名证书的分发类型数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |                     |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  //需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
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

**参数：**

| 参数名       | 类型                                                       | 必填 | 说明                                                         |
| ------------ | -------------------------------------------------------    | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md)    | 是   | 企业设备管理扩展组件。                                       |
| appDistributionTypes  | Array&lt;[AppDistributionType](#appdistributiontype20)&gt;  | 是 | 应用程序签名证书的分发类型数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |                     |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  //需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
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

getInstallationAllowedAppDistributionTypes(admin: Want): Array&lt;AppDistributionType&gt;

获取可安装的应用程序签名证书的分发类型。

**需要权限：** ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名       | 类型                                                       | 必填 | 说明                                                         |
| ------------ | -------------------------------------------------------    | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md)    | 是   | 企业设备管理扩展组件。                                       |

**返回值：**

| 类型                               | 说明                      |
| ---------------------------------- | ------------------------- |
| Array&lt;[AppDistributionType](#appdistributiontype20)&gt; | 应用程序签名证书的分发类型数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |                     |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  //需根据实际情况进行替换
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility'
};
try {
  let result: Array<bundleManager.AppDistributionType> = bundleManager.getInstallationAllowedAppDistributionTypes(wantTemp);
  console.info(`Succeeded in getting allowed appDistributionTypes. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get allowed appDistributionTypes. Code: ${err.code}, message: ${err.message}`);
}
```

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
| appInfo                           | [ApplicationInfo](#applicationinfo20)                        | 是   | 否   | 应用程序信息，包括应用程序名称、应用程序的安装目录等。 |
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
| appId     | string         | 是   | 否   | 应用的appId。                 |
|fingerprint| string         | 是   | 否   | 应用包的指纹信息。使用的签名证书发生变化，该字段会发生变化。          |
|appIdentifier| string         | 是   | 否   | 应用的唯一标识，是AppGallery Connect创建应用时分配的[APP ID](https://developer.huawei.com/consumer/cn/doc/app/agc-help-createharmonyapp-0000001945392297)，为云端统一分配的随机字符串。该ID在应用全生命周期中不会发生变化，包括版本升级、证书变更、开发者公私钥变更、应用转移等。          |
|certificate| string         | 是   | 是   | 应用的证书公钥。           |


## ApplicationInfo<sup>20+</sup>

应用程序信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称                       | 类型                                                         | 只读 | 可选 | 说明                                                         |
| -------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                       | string                                                       | 是   | 否   | 应用的Bundle名称。                                                 |
| description                | string                                                       | 是   | 否   | 应用的描述信息，使用示例：`"description": $string: mainability_description"`。关于description的详细信息可参见descriptionResource字段说明。 |
| descriptionId              | number                                                       | 是   | 否   | 应用的描述信息的资源id。 |
| enabled                    | boolean                                                      | 是   | 否   | 判断应用程序是否可以使用，true表示可以使用，false表示不可使用。 |
| label                      | string                                                       | 是   | 否   | 应用的名称，使用示例：`"label": "$string: mainability_description"`。关于label的详细信息可参见labelResource字段说明。 |
| labelId                    | number                                                       | 是   | 否   | 应用名称的资源id。 |
| icon                       | string                                                       | 是   | 否   | 应用程序的图标，使用示例：`"icon": "$media:icon"`。关于icon的详细信息可参见iconResource字段说明。 |
| iconId                     | number                                                       | 是   | 否   | 应用程序图标的资源id。 |
| process                    | string                                                       | 是   | 否   | 应用程序的进程名称。 |
| codePath                   | string                                                       | 是   | 否   | 应用程序的安装目录。 |
| removable                  | boolean                                                      | 是   | 否   | 应用程序是否可以被移除，true表示可以被移除，false表示不可以被移除。 |
| accessTokenId             | number                                                       | 是   | 否   | 应用程序的accessTokenId。 |
| uid                       | number                                                       | 是   | 否   | 应用程序的Uid。 |
| iconResource              | [Resource](#resource20) | 是 | 否 | 应用程序的图标资源信息，包含了该资源的信息的bundleName、moduleName和id。 |
| labelResource             | [Resource](#resource20) | 是 | 否 | 应用程序的标签资源信息，包含了该资源的信息的bundleName、moduleName和id。 |
| descriptionResource       | [Resource](#resource20) | 是 | 否 | 应用程序的描述资源信息，包含了该资源的信息的bundleName、moduleName和id。 |
| appDistributionType       | string                                                       | 是   | 否   | 应用程序签名证书的分发类型，分为： <br/> - app_gallery：应用市场分发的应用。 <br/> -  enterprise：企业应用，可以安装到个人设备上。<br/> -  enterprise_mdm：企业MDM应用，只能安装在企业设备上。需要设备管理特权，比如远程锁定，安装普通企业应用等。 <br/> - enterprise_normal：普通企业应用，只能通过企业MDM应用安装在企业设备上。无需设备管理特权。<br/> - os_integration：系统预置应用。<br/> - crowdtesting：众包测试应用。<br/> - internaltesting：应用市场内测的应用。<br/> - none：其他。 |
| appProvisionType          | string                                                       | 是   | 否   | 应用程序签名证书文件的类型，支持的取值如下：<br/> - debug：调试类型。<br/> - release：发布类型。 |
| systemApp          | boolean                                                       | 是   | 否   | 应用是否为系统应用，true表示系统应用，false表示非系统应用。 |
| debug       | boolean                                | 是   | 否   | 标识应用是否处于调试模式，true表示应用处于调试模式，false表示应用处于非调试模式。 |
| dataUnclearable       | boolean                      | 是   | 否   | 标识应用数据是否可被删除。true表示不可删除，false表示可以删除。 |
| nativeLibraryPath | string                                                                     | 是   | 否   | 应用程序的本地库文件路径。                                                  |
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

