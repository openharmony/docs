# @ohos.enterprise.adminManager (admin权限管理)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima-->
<!--SE: @liuzuming-->
<!--TSE: @lpw_work-->

本模块为企业MDM应用提供admin权限管理能力，包括激活/解除激活admin权限、事件订阅、委托授权等。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅对设备管理应用开放，具体请参考[MDM Kit开发指南](../../mdm/mdm-kit-guide.md)。

## 导入模块

```ts
import { adminManager } from '@kit.MDMKit';
```

## adminManager.disableAdmin

disableAdmin(admin: Want, userId?: number): Promise\<void>

解除激活指定用户的设备管理应用。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN（仅系统应用支持申请） 或 ohos.permission.START_PROVISIONING_MESSAGE
<br/>- 从API version 20 开始，支持申请ohos.permission.START_PROVISIONING_MESSAGE权限。仅当解除激活BYOD设备管理应用时，可以申请该权限。
<br/>- API 19及之前的版本，需要申请ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN（仅系统应用支持申请）。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。解除激活BYOD设备管理应用时，仅支持传入当前应用的企业设备管理扩展组件。    |
| userId | number                                                  | 否   | 用户ID，取值范围：大于等于0。<br> - 调用接口时，若传入userId，表示指定用户。<br> - 调用接口时，若未传入userId，表示当前用户。 |

**返回值：**

| 类型           | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | 无返回结果的Promise对象。当解除激活设备管理应用失败时，会抛出错误对象。 |

**错误码**:

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200005  | Failed to deactivate the administrator application of the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例**：

```ts
import { adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

adminManager.disableAdmin(wantTemp, 100).catch((err: BusinessError) => {
  console.error(`Failed to disable admin. Code: ${err.code}, message: ${err.message}`);
});
```

## adminManager.isByodAdmin<sup>20+</sup>

isByodAdmin(admin: Want): boolean

根据企业设备管理扩展组件查询当前应用是否被激活为BYOD设备管理应用。

**需要权限：** ohos.permission.START_PROVISIONING_MESSAGE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束：** 此接口仅可在Stage模型下使用。

**参数**：

| 参数名        | 类型     | 必填   | 说明        |
| ---------- | ------ | ---- | --------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。仅支持传入当前应用的企业设备管理扩展组件。 |

**返回值：**

| 类型         | 说明                 |
| ----------------- | ------------------- |
| boolean | 返回true表示被激活为BYOD设备管理应用，返回false表示没有被激活为BYOD设备管理应用。 |

**错误码**:

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 9200012      | Parameter verification failed.|

**示例**：

```ts
import { Want } from '@kit.AbilityKit';
import { adminManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 请根据实际情况替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  let result: boolean = adminManager.isByodAdmin(wantTemp);
  console.info(`Succeeded in querying admin is byod admin or not : ${result}`);
} catch (error) {
  console.error(`Failed to query admin is byod admin or not. Code is ${error.code}, message is ${error.message}`);
}
```

## adminManager.subscribeManagedEventSync

subscribeManagedEventSync(admin: Want, managedEvents: Array\<ManagedEvent>): void

订阅系统管理事件。

**需要权限：** ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名        | 类型                                                    | 必填 | 说明                   |
| ------------- | ------------------------------------------------------- | ---- | ---------------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |
| managedEvents | Array\<[ManagedEvent](#managedevent)>                   | 是   | 订阅事件数组。         |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200008  | The specified system event is invalid.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED, adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];

try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}
```

## adminManager.unsubscribeManagedEventSync

unsubscribeManagedEventSync(admin: Want, managedEvents: Array\<ManagedEvent>): void

取消订阅系统管理事件。

**需要权限：** ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名        | 类型                                                    | 必填 | 说明                   |
| ------------- | ------------------------------------------------------- | ---- | ---------------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |
| managedEvents | Array\<[ManagedEvent](#managedevent)>                   | 是   | 取消订阅事件数组。     |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200008  | The specified system event is invalid.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED, adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];

try {
  adminManager.unsubscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in unsubscribing managed event.');
} catch (err) {
  console.error(`Failed to unsubscribe managed event. Code: ${err.code}, message: ${err.message}`);
}
```

## adminManager.setDelegatedPolicies<sup>14+</sup>

setDelegatedPolicies(admin: Want, bundleName: string, policies: Array&lt;string&gt;): void

委托其他应用来设置设备的管控策略。被委托的其他应用需申请委托策略对应接口所需权限。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_DELEGATED_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名        | 类型                                                    | 必填 | 说明               |
| ------------- | ------------------------------------------------------- | ---- | ------------------ |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |
| bundleName | string                   | 是   | 被委托应用包名。被委托应用仅支持分发类型为enterprise_normal（企业普通应用）和enterprise_mdm（企业MDM应用）两种类型，开发者可在[Profile文件](https://developer.huawei.com/consumer/cn/doc/app/agc-help-add-releaseprofile-0000001914714796)中查询分发类型字段app-distribution-type。 |
| policies |  Array&lt;string&gt;                   | 是   | [委托策略列表](#可委托策略列表)。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device.                       |
| 9200009  | Failed to grant the permission to the application.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let admin: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
// 需根据实际情况进行替换
let policies: Array<string> = ["disabled_hdc"];

try {
  // 参数需根据实际情况进行替换
  adminManager.setDelegatedPolicies(admin, "com.example.enterprise.xxx", policies);
  console.info('Succeeded in setting delegated policies.');
} catch (err) {
  console.error(`Failed to set delegated policies. Code: ${err.code}, message: ${err.message}`);
}
```

## adminManager.getDelegatedPolicies<sup>14+</sup>

getDelegatedPolicies(admin: Want, bundleName: string): Array&lt;string&gt;

查询被委托应用可访问的策略列表。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_DELEGATED_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名     | 类型                                                    | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                       |
| bundleName | string                                                  | 是   | 被委托应用包名。被委托应用仅支持分发类型为enterprise_normal（企业普通应用）和enterprise_mdm（企业MDM应用）两种类型，开发者可在[Profile文件](https://developer.huawei.com/consumer/cn/doc/app/agc-help-add-releaseprofile-0000001914714796)中查询分发类型字段app-distribution-type。 |


**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Array&lt;string&gt; | 委托策略列表。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let admin: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  // 参数需根据实际情况进行替换
  let policies: Array<string> = adminManager.getDelegatedPolicies(admin, "com.example.enterprise.xxx");
  console.info(`Succeeded in getting delegated policies.${JSON.stringify(policies)}`);
} catch (err) {
  console.error(`Failed to get delegated policies. Code: ${err.code}, message: ${err.message}`);
}
```

## adminManager.getDelegatedBundleNames<sup>14+</sup>

getDelegatedBundleNames(admin: Want, policy: string): Array&lt;string&gt;

查询可以访问某个委托策略的被委托应用，输出被委托应用列表。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_DELEGATED_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名        | 类型                                                    | 必填 | 说明               |
| ------------- | ------------------------------------------------------- | ---- | ------------------ |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |
| policy | string                   | 是   | 委托策略。 |


**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Array&lt;string&gt; | 被委托应用列表。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let admin: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  // 参数需根据实际情况进行替换
  let bundleNames: Array<string> = adminManager.getDelegatedBundleNames(admin, "disabled_hdc");
  console.info(`Succeeded in getting delegated bundles.${JSON.stringify(bundleNames)}`);
} catch (err) {
  console.error(`Failed to get delegated bundles. Code: ${err.code}, message: ${err.message}`);
}
```

## adminManager.startAdminProvision<sup>15+</sup>

startAdminProvision(admin: Want, type: AdminType, context: common.Context, parameters: Record\<string, string>): void

设备管理应用拉起BYOD管理员激活页面进行激活。

**需要权限：** ohos.permission.START_PROVISIONING_MESSAGE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| type  | [AdminType](#admintype15)             | 是    | 激活的设备管理应用类型，仅支持ADMIN_TYPE_BYOD类型。  |
| context  | [common.Context](../apis-ability-kit/js-apis-app-ability-common.md) | 是 | 管理应用的上下文信息。 |
| parameters  | Record\<string, string> | 是 | 自定义参数信息，其中Key值必须包含："activateId"。 |

**错误码**：

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

<!--code_no_check-->
```ts
import { adminManager } from '@kit.MDMKit';
import { common, Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let recordParameters: Record<string, string> = {
  // 需根据实际情况进行替换
  "activateId": "activateId testValue",
  "customizedInfo": "customizedInfo testValue"
};
// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
const context = this.getUIContext().getHostContext() as common.UIAbilityContext;
try {
  console.info('context:' + JSON.stringify(context));
  adminManager.startAdminProvision(wantTemp, adminManager.AdminType.ADMIN_TYPE_BYOD, context, recordParameters);
  console.info('startAdminProvision::success');
} catch (error) {
  console.error('startAdminProvision::errorCode: ' + error.code + ' errorMessage: ' + error.message);
}
```

## ManagedEvent

可订阅的系统管理事件。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



| 名称                                         | 值   | 说明           |
| -------------------------------------------- | ---- | -------------- |
| MANAGED_EVENT_BUNDLE_ADDED                   | 0    | 应用安装事件。 |
| MANAGED_EVENT_BUNDLE_REMOVED                 | 1    | 应用卸载事件。 |
| MANAGED_EVENT_APP_START                      | 2    | 应用启动事件。 |
| MANAGED_EVENT_APP_STOP                       | 3    | 应用停止事件。 |
| MANAGED_EVENT_SYSTEM_UPDATE                  | 4    | 系统更新事件。 |
| MANAGED_EVENT_ACCOUNT_ADDED<sup>18+</sup>    | 5    | 账号新增事件。 |
| MANAGED_EVENT_ACCOUNT_SWITCHED<sup>18+</sup> | 6    | 账号切换事件。 |
| MANAGED_EVENT_ACCOUNT_REMOVED<sup>18+</sup>  | 7    | 账号删除事件。 |

## AdminType<sup>15+</sup>

设备管理应用的类型。 

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称                | 值  | 说明    |
| ----------------- | ---- | ----- |
| ADMIN_TYPE_BYOD  | 0x02 | BYOD设备管理应用。 |

## Policy<sup>20+</sup>

允许或禁用名单的策略类型。 

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束**：此接口仅可在Stage模型下使用。

| 名称                | 值  | 说明    |
| ----------------- | ---- | ----- |
| BLOCK_LIST  | 0 | 禁用名单。 |
| TRUST_LIST  | 1 | 允许名单。 |

## 附录
### 可委托策略列表
| 策略名称 | 对应接口                                                     | 说明 |
| --- | --- | --- |
|disallow_add_local_account| [accountManager.disallowOsAccountAddition](js-apis-enterprise-accountManager.md#accountmanagerdisallowosaccountaddition)<br>[accountManager.isOsAccountAdditionDisallowed](js-apis-enterprise-accountManager.md#accountmanagerisosaccountadditiondisallowed) | 不传accountId参数，禁止设备创建本地用户。<br>不传accountId参数，查询是否禁止设备创建本地用户。|
|disallow_add_os_account_by_user| [accountManager.disallowOsAccountAddition](js-apis-enterprise-accountManager.md#accountmanagerdisallowosaccountaddition)<br>[accountManager.isOsAccountAdditionDisallowed](js-apis-enterprise-accountManager.md#accountmanagerisosaccountadditiondisallowed) | 需传入accountId参数，禁止指定用户添加账号。<br>需传入accountId参数，查询是否禁止指定用户添加账号。|
|disallow_running_bundles|[applicationManager.addDisallowedRunningBundlesSync](js-apis-enterprise-applicationManager.md#applicationmanageradddisallowedrunningbundlessync)<br>[applicationManager.removeDisallowedRunningBundlesSync](js-apis-enterprise-applicationManager.md#applicationmanagerremovedisallowedrunningbundlessync)<br>[applicationManager.getDisallowedRunningBundlesSync](js-apis-enterprise-applicationManager.md#applicationmanagergetdisallowedrunningbundlessync)|添加应用至应用运行禁止名单，添加至禁止名单的应用不允许在当前/指定用户下运行。<br>从应用运行禁止名单中移除应用。<br>获取当前/指定用户下的应用运行禁止名单。 |
|manage_auto_start_apps|[applicationManager.addAutoStartApps](js-apis-enterprise-applicationManager.md#applicationmanageraddautostartapps)<br>[applicationManager.removeAutoStartApps](js-apis-enterprise-applicationManager.md#applicationmanagerremoveautostartapps)<br>[applicationManager.getAutoStartApps](js-apis-enterprise-applicationManager.md#applicationmanagergetautostartapps)|添加开机自启动应用名单。该能力当前仅支持PC/2in1设备。<br>从开机自启动应用名单中移除应用。该能力当前仅支持PC/2in1设备。<br>查询开机自启动应用名单。该能力当前仅支持PC/2in1设备。|
|allowed_bluetooth_devices|[bluetoothManager.addAllowedBluetoothDevices](js-apis-enterprise-bluetoothManager.md#bluetoothmanageraddallowedbluetoothdevices)<br>[bluetoothManager.removeAllowedBluetoothDevices](js-apis-enterprise-bluetoothManager.md#bluetoothmanagerremoveallowedbluetoothdevices)<br>[bluetoothManager.getAllowedBluetoothDevices](js-apis-enterprise-bluetoothManager.md#bluetoothmanagergetallowedbluetoothdevices)|添加蓝牙设备可用名单。<br>从蓝牙设备可用名单中移除。<br>查询蓝牙设备可用名单。|
|set_browser_policies|[browser.setPolicySync](js-apis-enterprise-browser.md#browsersetpolicysync)<br>[browser.getPoliciesSync](js-apis-enterprise-browser.md#browsergetpoliciessync)|为指定的浏览器设置浏览器子策略。<br>获取指定浏览器的策略。|
|allowed_install_bundles|[bundleManager.addAllowedInstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanageraddallowedinstallbundlessync)<br>[bundleManager.removeAllowedInstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanagerremoveallowedinstallbundlessync)<br>[bundleManager.getAllowedInstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanagergetallowedinstallbundlessync)|添加应用至应用程序包安装允许名单，添加至允许名单的应用允许在当前/指定用户下安装，否则不允许安装。<br>从应用程序包安装允许名单中移除应用。<br>获取当前/指定用户下的应用程序包安装允许名单。|
|disallowed_install_bundles|[bundleManager.addDisallowedInstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanageradddisallowedinstallbundlessync)<br>[bundleManager.removeDisallowedInstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanagerremoveallowedinstallbundlessync)<br>[bundleManager.getDisallowedInstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanagergetdisallowedinstallbundlessync)|添加应用至应用程序包安装禁止名单，添加至禁止名单的应用不允许在当前/指定用户下安装。<br>从应用程序包安装禁止名单中移除应用。<br>获取当前/指定用户下的应用程序包安装禁止名单。|
|disallowed_uninstall_bundles|[bundleManager.addDisallowedUninstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanageradddisalloweduninstallbundlessync)<br>[bundleManager.removeDisallowedUninstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanagerremovedisalloweduninstallbundlessync)<br>[bundleManager.getDisallowedUninstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanagergetdisalloweduninstallbundlessync)|添加应用至应用程序包卸载禁止名单，添加至禁止名单的应用不允许在当前/指定用户下卸载。<br>从应用程序包卸载禁止名单中移除应用。<br>获取当前/指定用户下的应用包程序卸载禁止名单。|
|get_device_info|[deviceInfo.getDeviceInfo](js-apis-enterprise-deviceInfo.md#deviceinfogetdeviceinfo)|获取设备信息。|
|location_policy|[locationManager.setLocationPolicy](js-apis-enterprise-locationManager.md#locationmanagersetlocationpolicy)<br>[locationManager.getLocationPolicy](js-apis-enterprise-locationManager.md#locationmanagergetlocationpolicy)|设置位置服务管理策略。<br>查询位置服务策略。|
|disabled_network_interface|[networkManager.setNetworkInterfaceDisabledSync](js-apis-enterprise-networkManager.md#networkmanagersetnetworkinterfacedisabledsync)<br>[networkManager.isNetworkInterfaceDisabledSync](js-apis-enterprise-networkManager.md#networkmanagerisnetworkinterfacedisabledsync)|禁止设备使用指定网络。<br>查询指定网络接口是否被禁用。|
|global_proxy|[networkManager.setGlobalProxySync](js-apis-enterprise-networkManager.md#networkmanagersetglobalproxysync)<br>[networkManager.getGlobalProxySync](js-apis-enterprise-networkManager.md#networkmanagergetglobalproxysync)|设置网络全局代理。<br>获取网络全局代理。|
|disabled_bluetooth|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|feature传入bluetooth，禁用/启用蓝牙能力。<br>feature传入bluetooth，查询是否禁用蓝牙能力。|
|disallow_modify_datetime|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|feature传入modifyDateTime，禁用/启用设置系统时间能力。<br>feature传入modifyDateTime，查询是否禁用修改系统时间能力。|
|disabled_printer|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|feature传入printer，禁用/启用打印能力。<br>feature传入printer，查询是否禁用打印能力。|
|disabled_hdc|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|feature传入hdc，禁用/启用HDC能力。<br>feature传入hdc，查询是否禁用HDC能力。|
|disable_microphone|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|feature传入microphone，禁用/启用麦克风能力。<br>feature传入microphone，查询是否禁用麦克风能力。|
|fingerprint_auth|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)<br>[restrictions.setDisallowedPolicyForAccount](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccount14)<br>[restrictions.getDisallowedPolicyForAccount](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicyforaccount14)|feature传入fingerprint，禁用/启用指纹认证能力。<br>feature传入fingerprint，查询是否禁用指纹认证能力。<br>feature传入fingerprint，禁用/启用指定用户的指纹认证能力。<br>feature传入fingerprint，查询是否禁用指定用户的指纹认证能力。|
|disable_usb|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|feature传入usb，禁用/启用USB能力。<br>feature传入usb，查询是否禁用USB能力。|
|disable_wifi|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|feature传入wifi，禁用/启用Wi-Fi能力。<br>feature传入wifi，查询是否禁用Wi-Fi能力。|
|disallowed_tethering|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|feature传入tethering，禁用/启用网络共享能力。<br>feature传入tethering，查询是否禁用网络共享能力。|
|inactive_user_freeze|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|feature传入inactiveUserFreeze，禁用/启用非活跃用户运行能力。<br>feature传入inactiveUserFreeze，查询是否禁用非活跃用户运行能力。|
|snapshot_skip|[restrictions.addDisallowedListForAccount](js-apis-enterprise-restrictions.md#restrictionsadddisallowedlistforaccount14)<br>[restrictions.removeDisallowedListForAccount](js-apis-enterprise-restrictions.md#restrictionsremovedisallowedlistforaccount14)<br>[restrictions.getDisallowedListForAccount](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedlistforaccount14)|feature传入snapshotSkip，禁用屏幕快照能力的应用名单。<br>feature传入snapshotSkip，从禁用屏幕快照能力的应用名单中移除。<br>feature传入snapshotSkip，查询禁用屏幕快照能力的应用名单。|
|password_policy|[securityManager.setPasswordPolicy](js-apis-enterprise-securityManager.md#securitymanagersetpasswordpolicy)<br>[securityManager.getPasswordPolicy](js-apis-enterprise-securityManager.md#securitymanagergetpasswordpolicy)|设置设备口令策略。<br>获取设备口令策略。|
|clipboard_policy|[securityManager.setAppClipboardPolicy](js-apis-enterprise-securityManager.md#securitymanagersetappclipboardpolicy)<br>[securityManager.getAppClipboardPolicy](js-apis-enterprise-securityManager.md#securitymanagergetappclipboardpolicy)|设置设备剪贴板策略。<br>获取设备剪贴板策略。|
|watermark_image_policy|[securityManager.setWatermarkImage](js-apis-enterprise-securityManager.md#securitymanagersetwatermarkimage14)<br>[securityManager.cancelWatermarkImage](js-apis-enterprise-securityManager.md#securitymanagercancelwatermarkimage14)|设置水印策略，当前仅支持PC/2in1使用。<br>取消水印策略，当前仅支持PC/2in1使用。|
|ntp_server|[systemManager.setNTPServer](js-apis-enterprise-systemManager.md#systemmanagersetntpserver)<br>[systemManager.getNTPServer](js-apis-enterprise-systemManager.md#systemmanagergetntpserver)|设置NTP服务器的策略。<br>获取NTP服务器信息。|
|set_update_policy|[systemManager.setOtaUpdatePolicy](js-apis-enterprise-systemManager.md#systemmanagersetotaupdatepolicy)<br>[systemManager.getOtaUpdatePolicy](js-apis-enterprise-systemManager.md#systemmanagergetotaupdatepolicy)|设置升级策略。<br>查询升级策略。|
|notify_upgrade_packages|[systemManager.notifyUpdatePackages](js-apis-enterprise-systemManager.md#systemmanagernotifyupdatepackages)<br>[systemManager.getUpdateResult](js-apis-enterprise-systemManager.md#systemmanagergetupdateresult)|通知系统更新包信息。<br>获取系统更新结果。|
|allowed_usb_devices|[usbManager.addAllowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageraddallowedusbdevices)<br>[usbManager.removeAllowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanagerremoveallowedusbdevices)<br>[usbManager.getAllowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanagergetallowedusbdevices)|添加USB设备可用名单。<br>移除USB设备可用名单。<br>获取USB设备可用名单。|
|usb_read_only|[usbManager.setUsbStorageDeviceAccessPolicy](js-apis-enterprise-usbManager.md#usbmanagersetusbstoragedeviceaccesspolicy)<br>[usbManager.getUsbStorageDeviceAccessPolicy](js-apis-enterprise-usbManager.md#usbmanagergetusbstoragedeviceaccesspolicy)|设置USB存储设备访问策略。<br>获取USB存储设备访问策略。|
|disallowed_usb_devices|[usbManager.addDisallowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageradddisallowedusbdevices14)<br>[usbManager.removeDisallowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanagerremovedisallowedusbdevices14)<br>[usbManager.getDisallowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanagergetdisallowedusbdevices14)|添加禁止使用的USB设备类型。<br>移除禁止使用的USB设备类型。<br>获取禁止使用的USB设备类型。|
|disallowed_sms|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|feature传入sms，禁用/启用设备接收、发送短信的能力，当前仅支持手机、平板设备使用。<br>feature传入sms，查询是否禁用设备接收、发送短信的能力，当前仅支持手机、平板设备使用。|
|disallowed_mms|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|feature传入mms，禁用/启用设备接收、发送彩信的能力，当前仅支持手机、平板设备使用。<br>feature传入mms，查询是否禁用设备接收、发送彩信的能力，当前仅支持手机、平板设备使用。|
|disable_backup_and_restore|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|feature传入backupAndRestore，禁用/启用备份和恢复能力，当前仅支持手机、平板使用。<br>feature传入backupAndRestore，查询是否禁用备份和恢复能力，当前仅支持手机、平板使用。|
|installed_bundle_info_list|[bundleManager.getInstalledBundleList](js-apis-enterprise-bundleManager.md#bundlemanagergetinstalledbundlelist20)|获取设备指定用户下已安装应用列表。|
|clear_up_application_data|[applicationManager.clearUpApplicationData](js-apis-enterprise-applicationManager.md#applicationmanagerclearupapplicationdata20)|清除应用产生的所有数据。|

