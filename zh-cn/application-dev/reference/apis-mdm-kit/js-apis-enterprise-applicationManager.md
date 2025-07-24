# @ohos.enterprise.applicationManager（应用管理）

本模块提供应用管理能力，包括添加应用运行禁止名单、获取应用运行禁止名单、移除应用运行禁止名单等。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对设备管理应用开放，且调用接口前需激活设备管理应用，具体请参考[MDM Kit开发指南](../../mdm/mdm-kit-guide.md)。[applicationManager.isAppKioskAllowed](#applicationmanagerisappkioskallowed20)除外，该接口对所有应用开放。
>

## 导入模块

```ts
import { applicationManager } from '@kit.MDMKit';
```

## applicationManager.addDisallowedRunningBundlesSync

addDisallowedRunningBundlesSync(admin: Want, appIds: Array\<string>, accountId?: number): void

添加应用至应用运行禁止名单，添加至禁止名单的应用不允许在当前/指定用户下运行。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| appIds    | Array&lt;string&gt;                                     | 是   | 应用ID数组，指定具体应用。                                   |
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
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
// 需根据实际情况进行替换
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  applicationManager.addDisallowedRunningBundlesSync(wantTemp, appIds);
  console.info('Succeeded in adding disallowed running bundles.');
} catch (err) {
  console.error(`Failed to add disallowed running bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.removeDisallowedRunningBundlesSync

removeDisallowedRunningBundlesSync(admin: Want, appIds:  Array\<string>, accountId?: number): void

将应用从当前/指定用户下的应用运行禁止名单中移除。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| appIds    | Array&lt;string&gt;                                     | 是   | 应用ID数组，指定具体应用。                                   |
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
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
// 需根据实际情况进行替换
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  applicationManager.removeDisallowedRunningBundlesSync(wantTemp, appIds);
  console.info('Succeeded in removing disallowed running bundles.');
} catch (err) {
  console.error(`Failed to remove disallowed running bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.getDisallowedRunningBundlesSync

getDisallowedRunningBundlesSync(admin: Want, accountId?: number): Array&lt;string>

获取当前/指定用户下的应用运行禁止名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| accountId | number                                                  | 否   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。<br/> - 调用接口时，若传入accountId，表示指定用户。<br/> - 调用接口时，若未传入accountId，表示当前用户。 |

**返回值：**

| 类型                | 说明                             |
| ------------------- | -------------------------------- |
| Array&lt;string&gt; | 返回当前/指定用户下的应用运行禁止名单。 |

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
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  let result: Array<string> = applicationManager.getDisallowedRunningBundlesSync(wantTemp);
  console.info(`Succeeded in getting disallowed running bundles, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed running bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.addAutoStartApps

addAutoStartApps(admin: Want, autoStartApps: Array\<Want>): void

添加开机自启动应用名单（对应用户为当前登录用户）。本接口添加的应用，禁止用户取消应用自启动。该能力当前仅支持PC/2in1设备。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名        | 类型                                                         | 必填 | 说明                                   |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是   | 企业设备管理扩展组件。                         |
| autoStartApps | Array\<[Want](../apis-ability-kit/js-apis-app-ability-want.md)> | 是   | 开机自启动应用。数组长度上限为10。 |

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
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let autoStartApps: Array<Want> = [
  {
    // 需根据实际情况进行替换
    bundleName: 'com.example.autoStartApplication',
    abilityName: 'EntryAbility'
  }
];

try {
  applicationManager.addAutoStartApps(wantTemp, autoStartApps);
  console.info(`Succeeded in adding auto start applications.`);
} catch(err) {
  console.error(`Failed to add auto start applications. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.removeAutoStartApps

removeAutoStartApps(admin: Want, autoStartApps: Array\<Want>): void

删除开机自启动应用名单。该能力当前仅支持PC/2in1设备。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名        | 类型                                                         | 必填 | 说明             |
| ------------- | ------------------------------------------------------------ | ---- | ---------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是   | 企业设备管理扩展组件。   |
| autoStartApps | Array\<[Want](../apis-ability-kit/js-apis-app-ability-want.md)> | 是   | 开机自启动应用。 |

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
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let autoStartApps: Array<Want> = [
  {
    // 需根据实际情况进行替换
    bundleName: 'com.example.autoStartApplication',
    abilityName: 'EntryAbility'
  }
];

try {
  applicationManager.removeAutoStartApps(wantTemp, autoStartApps);
  console.info(`Succeeded in removing auto start applications.`);
} catch(err) {
  console.error(`Failed to remove auto start applications. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.getAutoStartApps

getAutoStartApps(admin: Want): Array\<Want>

查询开机自启动应用名单。该能力当前仅支持PC/2in1设备。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

**返回值：**

| 类型                                                         | 说明                 |
| ------------------------------------------------------------ | -------------------- |
| Array\<[Want](../apis-ability-kit/js-apis-app-ability-want.md)> | 应用自启动名单数组。 |

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
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  let res: Array<Want> = applicationManager.getAutoStartApps(wantTemp);
  console.info(`Succeeded in adding auto start apps: ${JSON.stringify(res)}`);
} catch(err) {
  console.error(`Failed to auto start apps. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.addAutoStartApps<sup>20+</sup>

addAutoStartApps(admin: Want, autoStartApps: Array\<Want>, accountId: number, disallowModify: boolean): void

添加开机自启动应用名单，并设置是否禁止用户取消应用自启动。该能力当前仅支持PC/2in1设备。本接口与addAutoStartApps（API12）接口均可添加开机自启动应用名单，两个接口设置的应用自启动名单同时生效，相同用户下，自启动应用名单可设置的应用数量总数最大为10个。例如：若当前已通过API12接口添加3个应用，则最多还能通过本接口为本用户添加7个应用。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名        | 类型                                                         | 必填 | 说明                                   |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是   | 企业设备管理扩展组件。                         |
| autoStartApps | Array\<[Want](../apis-ability-kit/js-apis-app-ability-want.md)> | 是   | 开机自启动应用名单。Want需要传入bundleName和abilityName，数组总长度不能超过10。例如：若当前已通过本接口设置5个应用，则最多还能通过本接口再设置5个。 |
| accountId | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。|
| disallowModify | boolean | 是   | true禁止用户取消自启，false允许用户取消自启。<br>配置后，用户可通过设置-应用和元服务-应用启动管理，管理应用的自启。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

let autoStartApps: Array<Want> = [
  // 需根据实际情况进行替换
  {
    bundleName: 'com.example.autoStartApplication',
    abilityName: 'EntryAbility'
  }
];

try {
  applicationManager.addAutoStartApps(wantTemp, autoStartApps, 100, true);
  console.info(`Succeeded in adding auto start applications and set disllowModify.`);
} catch(err) {
  console.error(`Failed to add auto start applications and set disallowModify. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.removeAutoStartApps<sup>20+</sup>

removeAutoStartApps(admin: Want, autoStartApps: Array\<Want>, accountId: number): void

删除开机自启动应用名单。该能力当前仅支持PC/2in1设备。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名        | 类型                                                         | 必填 | 说明             |
| ------------- | ------------------------------------------------------------ | ---- | ---------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是   | 企业设备管理扩展组件。   |
| autoStartApps | Array\<[Want](../apis-ability-kit/js-apis-app-ability-want.md)> | 是   | 开机自启动应用名单。 |
| accountId | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。|

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
 
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

let autoStartApps: Array<Want> = [
  // 需根据实际情况进行替换
  {
    bundleName: 'com.example.autoStartApplication',
    abilityName: 'EntryAbility'
  }
];

try {
  applicationManager.removeAutoStartApps(wantTemp, autoStartApps, 100);
  console.info(`Succeeded in removing auto start applications.`);
} catch(err) {
  console.error(`Failed to remove auto start applications. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.getAutoStartApps<sup>20+</sup>

getAutoStartApps(admin: Want, accountId: number): Array\<Want>

查询开机自启动应用名单。该能力当前仅支持PC/2in1设备。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |
| accountId | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。|

**返回值：**

| 类型                                                         | 说明                 |
| ------------------------------------------------------------ | -------------------- |
| Array\<[Want](../apis-ability-kit/js-apis-app-ability-want.md)> | 应用自启动名单。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  let res: Array<Want> = applicationManager.getAutoStartApps(wantTemp, 100);
  console.info(`Succeeded in getting auto start apps: ${JSON.stringify(res)}`);
} catch(err) {
  console.error(`Failed to get auto start apps. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.isModifyAutoStartAppsDisallowed<sup>20+</sup>

isModifyAutoStartAppsDisallowed(admin: Want, autoStartApp: Want, accountId: number): boolean

查询应用是否禁止取消自启动。该能力当前仅支持PC/2in1设备。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |
| autoStartApp | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 开机自启动应用。 |
| accountId | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。|

**返回值：**

| 类型                                                         | 说明                 |
| ------------------------------------------------------------ | -------------------- |
| boolean | 是否禁止取消应用自启动。true禁止取消自启动，false允许取消自启动。|

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

let autoStartApp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.autoStartApplication',
  abilityName: 'EntryAbility'
};

try {
  let res: boolean = applicationManager.isModifyAutoStartAppsDisallowed(wantTemp, autoStartApp, 100);
  console.info(`Succeeded in getting disallow modify auto start app: ${JSON.stringify(res)}`);
} catch(err) {
  console.error(`Failed to get disallow modify auto start app. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.addKeepAliveApps<sup>14+</sup>

addKeepAliveApps(admin: Want, bundleNames: Array\<string>, accountId: number): void

添加保活应用，当前接口添加的应用，禁止用户取消保活，当前仅支持PC/2in1设备。如果将应用添加至应用禁止运行名单[addDisallowedRunningBundlesSync](#applicationmanageradddisallowedrunningbundlessync)，就不能将应用添加至保活，否则会冲突。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| bundleNames    | Array&lt;string&gt;                                     | 是   | 应用包名数组，指定需要添加保活的应用，最大支持5个。                                   |
| accountId | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。|

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured. |
| 9201005  | Add keep alive applications failed. |
| 201  | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
// 需根据实际情况进行替换
let bundleNames: Array<string> = ['com.example.myapplication'];

try {
  applicationManager.addKeepAliveApps(wantTemp, bundleNames, 100);
  console.info('Succeeded in adding keep alive apps.');
} catch (err) {
  console.error(`Failed to add keep alive apps. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.addKeepAliveApps<sup>20+</sup>

addKeepAliveApps(admin: Want, bundleNames: Array\<string>, accountId: number, disallowModify: boolean): void

添加保活应用，并设置是否禁止用户取消应用保活，当前仅支持PC/2in1设备。如果将应用添加至应用禁止运行名单[addDisallowedRunningBundlesSync](#applicationmanageradddisallowedrunningbundlessync)，就不能将应用添加至保活，否则会冲突。被保活应用需满足接入托盘服务的应用或者安装在系统用户（u1用户）下，entry包的[mainElement](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/module-configuration-file)是AppServiceExtension的应用。addKeepAliveApps（API14）接口均可添加保活应用，两个接口设置的保活应用同时生效，相同用户下，可设置的保活应用数量总数最大为5个。例如：若当前已通过API14接口添加3个应用保活，则最多还能通过本接口添加2个应用。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| bundleNames    | Array&lt;string&gt;                                     | 是   | 应用包名数组，指定需要添加保活的应用，最大支持5个。                                   |
| accountId | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。|
| disallowModify | boolean | 是   | true表示禁止用户取消保活，false表示允许用户取消保活<br>配置后，ToB版本用户可在设置-应用和元服务-应用常驻管理中查看和修改 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured. |
| 9201005  | Add keep alive applications failed. |
| 201  | Permission verification failed.The application does not have the permission required to call the API. |

**示例：**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

// 需根据实际情况进行替换
let bundleNames: Array<string> = ['com.example.myapplication'];

try {
  applicationManager.addKeepAliveApps(wantTemp, bundleNames, 100, true);
  console.info('Succeeded in adding keep alive apps and set disallowModify.');
} catch (err) {
  console.error(`Failed to add keep alive apps and set disallowModify. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.removeKeepAliveApps<sup>14+</sup>

removeKeepAliveApps(admin: Want, bundleNames: Array\<string>, accountId: number): void

移除保活应用，当前仅支持PC/2in1设备。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| bundleNames    | Array&lt;string&gt;                                     | 是   | 应用包名数组，指定需要移除保活的应用，最大支持5个。                                   |
| accountId | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201  | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
// 需根据实际情况进行替换
let bundleNames: Array<string> = ['com.example.myapplication'];

try {
  applicationManager.removeKeepAliveApps(wantTemp, bundleNames, 100);
  console.info('Succeeded in removing keep alive apps.');
} catch (err) {
  console.error(`Failed to remove keep alive apps. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.getKeepAliveApps<sup>14+</sup>

getKeepAliveApps(admin: Want, accountId: number): Array&lt;string>

获取保活应用包名，当前仅支持PC/2in1设备。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| accountId | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |

**返回值：**

| 类型                | 说明                             |
| ------------------- | -------------------------------- |
| Array&lt;string&gt; | 返回指定用户下保活应用的包名。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201  | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  let result: Array<string> = applicationManager.getKeepAliveApps(wantTemp, 100);
  console.info('Succeeded in getting keep alive apps.');
} catch (err) {
  console.error(`Failed to get keep alive apps. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.isModifyKeepAliveAppsDisallowed<sup>20+</sup>

isModifyKeepAliveAppsDisallowed(admin: Want, accountId: number, bundleName: string): boolean

查询应用是否禁止取消保活。该能力当前仅支持PC/2in1设备。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |
| accountId | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。|
| bundleName | string | 是 | 查询的应用包名。 |

**返回值：**

| 类型                                                         | 说明                 |
| ------------------------------------------------------------ | -------------------- |
| boolean | 是否禁止取消应用保活。true表示禁止用户取消保活，false表示允许用户取消保活。|

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

// 需根据实际情况进行替换
let keepAliveApp: string = 'com.example.keepAliveApplication';

try {
  let res: boolean = applicationManager.isModifyKeepAliveAppsDisallowed(wantTemp, 100, keepAliveApp);
  console.info(`Succeeded in getting disallow modify keep alive app: ${JSON.stringify(res)}`);
} catch(err) {
  console.error(`Failed to get disallow modify keep alive app. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.clearUpApplicationData<sup>20+</sup>

clearUpApplicationData(admin: Want, bundleName: string, appIndex: number, accountId: number): void

清除应用产生的所有数据。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名     | 类型                                                    | 必填 | 说明                                                         |
| ---------  | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| bundleName | string                                                  | 是   | 应用包名，指定需要清除数据的应用包名。 |
| appIndex | number                                                    | 是   | 应用分身索引，取值范围：大于等于0的整数。<br> appIndex可以通过@ohos.bundle.bundleManager中的[getAppCloneIdentity](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetappcloneidentity14)等接口来获取。|
| accountId | number                                                   | 是   | 用户ID，取值范围：大于等于0的整数。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201  | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { applicationManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
// 需根据实际情况进行替换
let bundleName: string = 'com.example.exampleapplication';

try {
  // 需根据实际情况进行替换
  applicationManager.clearUpApplicationData(wantTemp, bundleName, 0, 100);
  console.info('Succeeded in clear up application data.');
} catch (err) {
  console.error(`Failed to clear up application data. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.setAllowedKioskApps<sup>20+</sup>

setAllowedKioskApps(admin: Want, bundleNames: Array&lt;string&gt;): void

设置允许在Kiosk模式下运行的应用。

Kiosk模式为系统层面提供的一种应用运行模式，该模式下会将设备锁定在单个应用或者一组应用运行，同时对锁屏状态、状态栏、手势操作和关键功能进行控制，防止用户在设备上启动其它应用或执行其它操作。

**需要权限：** ohos.permission.ENTERPRISE_SET_KIOSK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| bundleNames | Array&lt;string&gt;                                   | 是   | 应用包名数组，设置允许在Kiosk模式下运行的应用。重复设置时，新设置的数组会覆盖旧的设置，最多设置200个。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201  | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { applicationManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility'
};

try {
  // 需根据实际情况进行替换
  let bundleNames: Array<string> = ['com.example.test'];
  applicationManager.setAllowedKioskApps(wantTemp, bundleNames);
  console.info('Succeeded in setting allowed kiosk apps.');
} catch (err) {
  console.error(`Failed to set allowed kiosk apps. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.getAllowedKioskApps<sup>20+</sup>

getAllowedKioskApps(admin: Want): Array&lt;string&gt;

获取允许在Kiosk模式下运行的应用。

**需要权限：** ohos.permission.ENTERPRISE_SET_KIOSK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                       |

**返回值：**

| 类型                | 说明                             |
| ------------------- | -------------------------------- |
| Array&lt;string&gt; | 允许在Kiosk模式下运行的应用包名清单。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201  | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { applicationManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility'
};

try {
  let bundleNames: Array<string> = applicationManager.getAllowedKioskApps(wantTemp);
  console.info(`Succeeded in getting allowed kiosk apps, bundleNames: ${JSON.stringify(bundleNames)}`);
} catch (err) {
  console.error(`Failed to get allowed kiosk apps. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.isAppKioskAllowed<sup>20+</sup>

isAppKioskAllowed(bundleName: string): boolean

查询某应用是否允许在Kiosk模式下运行。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string                                                 | 是   | 应用包名。                                       |

**返回值：**

| 类型                | 说明                             |
| ------------------- | -------------------------------- |
| boolean    | true表示允许在Kiosk模式下运行。false表示不允许在Kiosk模式下运行。 |

**示例：**

```ts
import { applicationManager } from '@kit.MDMKit';

try {
  // 需根据实际情况进行替换
  let isAllowed: boolean = applicationManager.isAppKioskAllowed('com.example.test');
  console.info(`Succeeded in querying if the app is allowed kiosk, isAllowed: ${isAllowed}`);
} catch (err) {
  console.error(`Failed to query if the app is allowed kiosk. Code is ${err.code}, message is ${err.message}`);
}
```