# @ohos.enterprise.usbManager（USB管理）
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

本模块提供USB管理能力。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对设备管理应用开放，且调用接口前需激活设备管理应用，具体请参考[MDM Kit开发指南](../../mdm/mdm-kit-guide.md)。
>
> 全局通用限制类策略由restrictions统一提供，若要全局禁用USB，请参考[@ohos.enterprise.restrictions（限制类策略）](js-apis-enterprise-restrictions.md)。

## 导入模块

```ts
import { usbManager } from '@kit.MDMKit';
```

## usbManager.addAllowedUsbDevices

addAllowedUsbDevices(admin: Want, usbDeviceIds: Array\<UsbDeviceId>): void

添加USB设备可用名单。

**使用场景**：
- 企业安全管理场景，需要限制只有特定的USB设备可以接入设备
- 设备管理员需要精确控制哪些USB设备能够被识别和使用
- 配合[removeAllowedUsbDevices](#usbmanagerremoveallowedusbdevices)接口实现USB设备的动态管理

以下情况下，调用本接口会报策略冲突：

1. 已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口禁用了设备USB或者USB转串口能力。
2. 已经通过[setUsbStorageDeviceAccessPolicy](#usbmanagersetusbstoragedeviceaccesspolicy)接口设置了USB存储设备访问策略为禁用。
3. 已经通过[addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14)接口添加了禁止使用的USB设备类型。
4. 已经通过[addDisallowedPermissiveUsbDevices](#usbmanageradddisallowedpermissiveusbdevices)接口添加了禁止使用的USB设备类型。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                       |
| usbDeviceIds | Array<[UsbDeviceId](#usbdeviceid)>                      | 是   | USB设备ID数组，UsbDeviceId信息可以通过[getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices)接口获取。USB设备可用名单数组长度上限为1000，若当前允许名单中已有300个USB设备ID，则只允许再添加700个。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200007 | The system ability works abnormally. |
| 9200010  | A conflict policy has been configured.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let usbDeviceIds: Array<usbManager.UsbDeviceId> = [{
    vendorId: 1,
    productId: 1
  }];
  usbManager.addAllowedUsbDevices(wantTemp, usbDeviceIds);
  console.info(`Succeeded in adding allowed USB devices.`);
} catch (err) {
  console.error(`Failed to add allowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.removeAllowedUsbDevices

removeAllowedUsbDevices(admin: Want, usbDeviceIds: Array\<UsbDeviceId>): void

移除USB设备可用名单。

**使用场景**：
- 企业安全管理场景，需要撤销某些USB设备的访问权限
- 设备管理员需要动态调整允许使用的USB设备列表
- 当USB设备不再需要或存在安全风险时，从允许名单中移除

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                       |
| usbDeviceIds | Array<[UsbDeviceId](#usbdeviceid)>                      | 是   | USB设备ID数组，UsbDeviceId信息可以通过[getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices)接口获取。 |

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let usbDeviceIds: Array<usbManager.UsbDeviceId> = [{
    vendorId: 1,
    productId: 1
  }];
  usbManager.removeAllowedUsbDevices(wantTemp, usbDeviceIds);
  console.info(`Succeeded in removing allowed USB devices.`);
} catch (err) {
  console.error(`Failed to remove allowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.getAllowedUsbDevices

getAllowedUsbDevices(admin: Want): Array\<UsbDeviceId>

获取USB设备可用名单。一般使用场景：在修改策略前，需要先获取现有策略进行评估；管理界面需要展示当前的USB存储设备访问控制状态。

本接口通过传入Want查询对应企业设备管理应用设置的策略，如需查询实际生效的策略，请使用[usbManager.getAllowedUsbDevices](#usbmanagergetallowedusbdevices-1)接口。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                   |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。|

**返回值：**

| 类型                               | 说明                      |
| ---------------------------------- | ------------------------- |
| Array<[UsbDeviceId](#usbdeviceid)> | USB设备可用名单的设备ID数组。 |

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let result: Array<usbManager.UsbDeviceId> = usbManager.getAllowedUsbDevices(wantTemp);
  console.info(`Succeeded in getting allowed USB devices. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get allowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```


## usbManager.getAllowedUsbDevices

getAllowedUsbDevices(admin: Want | null): Array\<UsbDeviceId>

获取USB设备可用名单。一般使用场景：在修改策略前，需要先获取现有策略进行评估；管理界面需要展示当前的USB存储设备访问控制状态。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                   |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。<br>当设备存在多个MDM应用时，传入Want时查询对应企业设备管理应用设置的策略，传入null时查询实际生效的策略。|

**返回值：**

| 类型                               | 说明                      |
| ---------------------------------- | ------------------------- |
| Array<[UsbDeviceId](#usbdeviceid)> | USB设备可用名单的设备ID数组。 |

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
import { usbManager } from '@kit.MDMKit';

try {
  // 参数需根据实际情况进行替换
  let result: Array<usbManager.UsbDeviceId> = usbManager.getAllowedUsbDevices(null);
  console.info(`Succeeded in getting allowed USB devices. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get allowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```
## usbManager.setUsbStorageDeviceAccessPolicy

setUsbStorageDeviceAccessPolicy(admin: Want, usbPolicy: UsbPolicy): void

设置USB存储设备（baseClass = 0x08）访问策略。

> **说明：**
> 在调用接口前，确保已暂停USB存储设备的读写操作，保证操作的稳定性和数据的完整性，否则可能出现不可预期的异常。

以下情况下，通过本接口设置USB存储设备访问策略为可读可写/只读，会报策略冲突：

1. 已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口禁用了设备USB能力。
2. 已经通过[addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14)接口将存储类型的USB设备添加为禁止使用的USB设备类型。
3. 已经通过[setDisallowedPolicyForAccount](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccountdeprecated)接口禁用了某用户USB存储设备写入能力。

以下情况下，通过本接口设置USB存储设备访问策略为禁用，会报策略冲突：

1. 已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口禁用了设备USB能力。
2. 已经通过[addAllowedUsbDevices](#usbmanageraddallowedusbdevices)接口添加了USB设备可用名单。
3. 已经通过[setDisallowedPolicyForAccount](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccountdeprecated)接口禁用了某用户USB存储设备写入能力。

通过本接口设置，或者通过[addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14)接口添加存储类型的USB设备，均可禁用USB存储设备。推荐使用后者。

**需要权限：** 

- API版本26.0.0之前：ohos.permission.ENTERPRISE_MANAGE_USB
- API版本26.0.0开始：ohos.permission.ENTERPRISE_MANAGE_USB 或者 ohos.permission.PERSONAL_MANAGE_RESTRICTIONS（应用调用[adminManager.startAdminProvision](./js-apis-enterprise-adminManager.md#adminmanagerstartadminprovision15)接口激活为自带设备管理应用）。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [从严管控](../../mdm/mdm-kit-multi-mdm.md#规则1从严管控), 严格优先级： 禁用 > 只读 > 可读可写。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                   |
| --------- | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| usbPolicy | [UsbPolicy](#usbpolicy)                                 | 是   | USB存储设备访问策略。                  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200007 | The system ability works abnormally. |
| 9200010  | A conflict policy has been configured.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let policy: usbManager.UsbPolicy = usbManager.UsbPolicy.DISABLED;
  usbManager.setUsbStorageDeviceAccessPolicy(wantTemp, policy);
  console.info(`Succeeded in setting USB storage device access policy.`);
} catch (err) {
  console.error(`Failed to set USB storage device access policy. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.getUsbStorageDeviceAccessPolicy

getUsbStorageDeviceAccessPolicy(admin: Want): UsbPolicy

获取USB存储设备（baseClass = 0x08）访问策略。

本接口通过传入Want查询对应企业设备管理应用设置的策略，如需查询实际生效的策略，请使用[usbManager.getUsbStorageDeviceAccessPolicy](#usbmanagergetusbstoragedeviceaccesspolicy-1)接口。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB 或者 ohos.permission.PERSONAL_MANAGE_RESTRICTIONS（应用调用[adminManager.startAdminProvision](./js-apis-enterprise-adminManager.md#adminmanagerstartadminprovision15)接口激活为自带设备管理应用）。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                   |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。|

**返回值：**

| 类型                    | 说明                  |
| ----------------------- | --------------------- |
| [UsbPolicy](#usbpolicy) | USB存储设备访问策略。设置为READ_WRITE表示允许读写USB存储设备；设置为READ_ONLY表示仅允许读取USB存储设备，禁止写入；设置为DISABLED表示完全禁止访问USB存储设备。 |

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let result: usbManager.UsbPolicy = usbManager.getUsbStorageDeviceAccessPolicy(wantTemp);
  console.info(`Succeeded in getting USB storage device access policy. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get USB storage device access policy. Code: ${err.code}, message: ${err.message}`);
}
```


## usbManager.getUsbStorageDeviceAccessPolicy

getUsbStorageDeviceAccessPolicy(admin: Want | null): UsbPolicy

获取USB存储设备（baseClass = 0x08）访问策略。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB 或者 ohos.permission.PERSONAL_MANAGE_RESTRICTIONS（应用调用[adminManager.startAdminProvision](./js-apis-enterprise-adminManager.md#adminmanagerstartadminprovision15)接口激活为自带设备管理应用）。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                   |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。<br>当设备存在多个MDM应用时，传入Want时查询对应企业设备管理应用设置的策略，传入null时查询实际生效的策略。|

**返回值：**

| 类型                    | 说明                  |
| ----------------------- | --------------------- |
| [UsbPolicy](#usbpolicy) | USB存储设备访问策略。设置为READ_WRITE表示允许读写USB存储设备；设置为READ_ONLY表示仅允许读取USB存储设备，禁止写入；设置为DISABLED表示完全禁止访问USB存储设备。 |

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
import { usbManager } from '@kit.MDMKit';

try {
  // 参数需根据实际情况进行替换
  let result: usbManager.UsbPolicy = usbManager.getUsbStorageDeviceAccessPolicy(null);
  console.info(`Succeeded in getting USB storage device access policy. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get USB storage device access policy. Code: ${err.code}, message: ${err.message}`);
}
```
## usbManager.addDisallowedUsbDevices<sup>14+</sup>

addDisallowedUsbDevices(admin: Want, usbDevices: Array\<UsbDeviceType>): void

添加禁止使用的USB设备类型。一般使用场景：企业安全管理场景，需要禁用特定类型的USB设备；防止数据泄露：禁用USB存储设备类型；设备管理员需要根据安全策略，禁止使用某些类型的USB设备；配合[removeDisallowedUsbDevices](#usbmanagerremovedisallowedusbdevices14)接口实现USB设备类型的动态管理。

> **说明：**
>
> 推荐使用[addDisallowedPermissiveUsbDevices](#usbmanageradddisallowedpermissiveusbdevices)接口。

以下情况下，调用本接口会报策略冲突：

1. 已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口禁用了设备USB能力。
2. 已经通过[addAllowedUsbDevices](#usbmanageraddallowedusbdevices)接口添加了USB设备可用名单。
3. 已经通过[setDisallowedPolicyForAccount](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccountdeprecated)接口禁用了某用户USB存储设备写入能力。
4. 已经通过[addDisallowedPermissiveUsbDevices](#usbmanageradddisallowedpermissiveusbdevices)接口添加了禁止使用的USB设备类型。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名     | 类型                                                    | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                       |
| usbDevices | Array<[UsbDeviceType](#usbdevicetype14)>                | 是   | 要添加的USB设备类型的数组，UsbDeviceType信息可以通过[getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices)接口获取。USB设备禁用名单数组长度上限为200，若当前禁用名单中已有100个USB设备ID，则只允许再添加100个。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let usbDevices: Array<usbManager.UsbDeviceType> = [{
    baseClass: 8,
    subClass: 0,
    protocol: 0,
    descriptor: usbManager.Descriptor.INTERFACE
  }];
  usbManager.addDisallowedUsbDevices(wantTemp, usbDevices);
  console.info(`Succeeded in adding disallowed USB devices.`);
} catch (err) {
  console.error(`Failed to add disallowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.removeDisallowedUsbDevices<sup>14+</sup>

removeDisallowedUsbDevices(admin: Want, usbDevices: Array\<UsbDeviceType>): void

移除禁止使用的USB设备类型。

**使用场景**：
- 企业安全管理场景，需要解除对某些USB设备类型的禁用
- 设备管理员需要动态调整禁止使用的USB设备类型列表
- 当某些USB设备类型不再存在安全风险时，从禁用名单中移除

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名     | 类型                                                    | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                       |
| usbDevices | Array<[UsbDeviceType](#usbdevicetype14)>                | 是   | 要移除的USB设备类型的数组，UsbDeviceType信息可以通过[getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices)接口获取。 |

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let usbDevices: Array<usbManager.UsbDeviceType> = [{
    baseClass: 8,
    subClass: 0,
    protocol: 0,
    descriptor: usbManager.Descriptor.INTERFACE
  }];
  usbManager.removeDisallowedUsbDevices(wantTemp, usbDevices);
  console.info(`Succeeded in removing disallowed USB devices.`);
} catch (err) {
  console.error(`Failed to remove disallowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.getDisallowedUsbDevices<sup>14+</sup>

getDisallowedUsbDevices(admin: Want): Array\<UsbDeviceType>

获取禁止使用的USB设备类型。一般使用场景：设备管理员需要查看当前禁止使用的USB设备类型列表；在修改禁用名单前，需要先获取现有名单进行比对；管理界面需要展示当前的USB设备类型禁用策略配置。

本接口通过传入Want查询对应企业设备管理应用设置的策略，如需查询实际生效的策略，请使用[usbManager.getDisallowedUsbDevices](#usbmanagergetdisallowedusbdevices)接口。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                   |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。|

**返回值：**

| 类型                                     | 说明                    |
| ---------------------------------------- | ----------------------- |
| Array<[UsbDeviceType](#usbdevicetype14)> | 禁止使用的USB设备类型。 |

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let result: Array<usbManager.UsbDeviceType> = usbManager.getDisallowedUsbDevices(wantTemp);
  console.info(`Succeeded in getting disallowed USB devices. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```


## usbManager.getDisallowedUsbDevices

getDisallowedUsbDevices(admin: Want | null): Array\<UsbDeviceType>

获取禁止使用的USB设备类型。一般使用场景：设备管理员需要查看当前禁止使用的USB设备类型列表；在修改禁用名单前，需要先获取现有名单进行比对；管理界面需要展示当前的USB设备类型禁用策略配置。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                   |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。<br>当设备存在多个MDM应用时，传入Want时查询对应企业设备管理应用设置的策略，传入null时查询实际生效的策略。|

**返回值：**

| 类型                                     | 说明                    |
| ---------------------------------------- | ----------------------- |
| Array<[UsbDeviceType](#usbdevicetype14)> | 禁止使用的USB设备类型。 |

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
import { usbManager } from '@kit.MDMKit';

try {
  // 参数需根据实际情况进行替换
  let result: Array<usbManager.UsbDeviceType> = usbManager.getDisallowedUsbDevices(null);
  console.info(`Succeeded in getting disallowed USB devices. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```
## usbManager.addDisallowedPermissiveUsbDevices

addDisallowedPermissiveUsbDevices(admin: Want, usbDevices: Array\<PermissiveUsbDeviceType>): void

添加禁止使用的USB设备类型。与[addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14)接口不同的是，本接口可以不按照[defined-class-codes](https://www.usb.org/defined-class-codes)标准进行匹配。对已连接的USB设备热生效，无需重新插拔，例如USB线控耳机正常使用时，调用本接口禁用该耳机，会导致耳机不可用。

以下情况下，调用本接口会报策略冲突：

1. 已经通过[addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14)接口添加了禁止使用的USB设备类型。
2. 已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口禁用了设备USB能力。
3. 已经通过[addAllowedUsbDevices](#usbmanageraddallowedusbdevices)接口添加了USB设备可用名单。
4. 已经通过[setDisallowedPolicyForAccount](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccountdeprecated)接口禁用了某用户USB存储设备写入能力。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名     | 类型                                                     | 必填 | 说明 |
| ---------- | ------------------------------------------------------- | ---- | ---- |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| usbDevices | Array\<[PermissiveUsbDeviceType](#permissiveusbdevicetype)> | 是   | 要添加的USB设备类型的数组，支持部分字段匹配。USB设备禁用名单数组长度上限为1000，若当前禁用名单中已有500个USB设备ID，则只允许再添加500个。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 9200012  | Parameter verification failed.                               |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // 禁用USB存储设备（以实际USB设备类型参数为准）
  let usbDevices1: Array<usbManager.PermissiveUsbDeviceType> = [{
    baseClass: 8
  }];
  usbManager.addDisallowedPermissiveUsbDevices(wantTemp, usbDevices1);

  // 禁用USB线控耳机（以实际USB设备类型参数为准）
  let usbDevices2: Array<usbManager.PermissiveUsbDeviceType> = [{
    baseClass: 0,
    subClass: 0,
    protocol: 0,
    descriptor: usbManager.Descriptor.DEVICE
  }];
  usbManager.addDisallowedPermissiveUsbDevices(wantTemp, usbDevices2);

  // 禁用USB线控键盘输入（以实际USB设备类型参数为准）
  let usbDevices3: Array<usbManager.PermissiveUsbDeviceType> = [{
    baseClass: 3,
    subClass: 1,
    protocol: 1,
    descriptor: usbManager.Descriptor.INTERFACE
  }];
  usbManager.addDisallowedPermissiveUsbDevices(wantTemp, usbDevices3);
  console.info(`Succeeded in adding disallowed permissive USB devices.`);
} catch (err) {
  console.error(`Failed to add disallowed permissive USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.removeDisallowedPermissiveUsbDevices

removeDisallowedPermissiveUsbDevices(admin: Want, usbDevices: Array\<PermissiveUsbDeviceType>): void

移除通过[addDisallowedPermissiveUsbDevices](#usbmanageradddisallowedpermissiveusbdevices)接口禁用的USB设备类型。被移除的USB设备类型可恢复正常使用。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名     | 类型                                                       | 必填 | 说明 |
| ---------- | --------------------------------------------------------- | ---- | ----- |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md)   | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| usbDevices | Array\<[PermissiveUsbDeviceType](#permissiveusbdevicetype)> | 是   | 要移除的USB设备类型的数组。 |

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let usbDevices: Array<usbManager.PermissiveUsbDeviceType> = [{
    baseClass: 8
  }];
  usbManager.removeDisallowedPermissiveUsbDevices(wantTemp, usbDevices);
  console.info(`Succeeded in removing disallowed permissive USB devices.`);
} catch (err) {
  console.error(`Failed to remove disallowed permissive USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.getDisallowedPermissiveUsbDevices

getDisallowedPermissiveUsbDevices(admin: Want | null): Array\<PermissiveUsbDeviceType>

获取通过[addDisallowedPermissiveUsbDevices](#usbmanageradddisallowedpermissiveusbdevices)接口禁用的USB设备类型。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明 |
| ------ | ------------------------------------------------------- | ---- | ----- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。当取值为null时，表示获取当前设备禁止使用的USB设备类型。 |

**返回值：**

| 类型                                                     | 说明                         |
| -------------------------------------------------------- | ---------------------------- |
| Array\<[PermissiveUsbDeviceType](#permissiveusbdevicetype)> | 禁止使用的USB设备类型数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let result: Array<usbManager.PermissiveUsbDeviceType> = usbManager.getDisallowedPermissiveUsbDevices(wantTemp);
  console.info(`Succeeded in getting disallowed permissive USB devices. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed permissive USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## UsbDeviceId

USB设备ID信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称      | 类型   | 只读 | 可选 | 说明     |
| --------- | ------ | ---- | ---- | -------- |
| vendorId  | number | 否   | 否 | 厂商ID。 |
| productId | number | 否   | 否 | 产品ID。 |

## UsbDeviceType<sup>14+</sup>

USB设备类型信息。

可通过[getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices)接口获取已接入主设备的USB设备列表，并从返回值列表中查找当前设备的类型信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称       | 类型                        | 只读 | 可选 | 说明                                                         |
| ---------- | --------------------------- | ---- | ---- | ------------------------------------------------------------ |
| baseClass  | number                      | 否   | 否 | 类型编码。<br>先根据此值确定descriptor应该传入的类型。若descriptor为DEVICE，则本字段取USBDevice.clazz字段值，若descriptor为INTERFACE，则本字段取USBDevice.configs.interfaces.clazz字段值。<br>若字段值为255，表示此设备的类型编码是厂商自定义编码，则使用[addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14)/[removeDisallowedUsbDevices](#usbmanagerremovedisallowedusbdevices14)接口禁用/解禁该设备不生效；若字段值未在[defined-class-codes](https://www.usb.org/defined-class-codes)中定义，则使用[addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14)/[removeDisallowedUsbDevices](#usbmanagerremovedisallowedusbdevices14)接口禁用/解禁该设备不生效。 |
| subClass   | number                      | 否   | 否 | 子类型编码。<br>先根据baseClass的值确定descriptor应该传入的类型。若descriptor为DEVICE，则本字段取USBDevice.subClass字段值，若descriptor为INTERFACE，则本字段取USBDevice.configs.interfaces.subClass字段值。<br>若字段值为255，表示此设备的子类型编码是厂商自定义编码，则使用[addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14)/[removeDisallowedUsbDevices](#usbmanagerremovedisallowedusbdevices14)接口禁用/解禁该设备不生效；若字段值未在[defined-class-codes](https://www.usb.org/defined-class-codes)中定义，则使用[addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14)/[removeDisallowedUsbDevices](#usbmanagerremovedisallowedusbdevices14)接口禁用/解禁该设备不生效。 |
| protocol   | number                      | 否   | 否 | 协议编码。<br>先根据baseClass的值确定descriptor应该传入的类型。若descriptor为DEVICE，则本字段取USBDevice.protocol字段值，若descriptor为INTERFACE，则本字段取USBDevice.configs.interfaces.protocol字段值。<br>若字段值为255，表示此设备的协议编码是厂商自定义编码，则使用[addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14)/[removeDisallowedUsbDevices](#usbmanagerremovedisallowedusbdevices14)接口禁用/解禁该设备不生效；若字段值未在[defined-class-codes](https://www.usb.org/defined-class-codes)中定义，则使用[addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14)/[removeDisallowedUsbDevices](#usbmanagerremovedisallowedusbdevices14)接口禁用/解禁该设备不生效。 |
| descriptor | [Descriptor](#descriptor14) | 否   | 否 | USB描述符。<br>若此值USBDevice.clazz字段值为0，则须在[defined-class-codes](https://www.usb.org/defined-class-codes)中的Base Class列查找此值USBDevice.configs.interfaces.clazz字段值，查找结果所在行所对应的Descriptor Usage列就表示当前应该传入的descriptor类型（若Descriptor Usage列为Both，表示两种类型都可以传入，需要设备级禁用时传入DEVICE，需要接口级禁用时传入INTERFACE）;<br>若此值USBDevice.clazz字段值为255，表示此设备的类型编码是厂商自定义编码，则使用[addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14)/[removeDisallowedUsbDevices](#usbmanagerremovedisallowedusbdevices14)接口禁用/解禁该设备不生效；若此值USBDevice.clazz字段值为其他值，则须在[defined-class-codes](https://www.usb.org/defined-class-codes)中的Base Class列查找该值，查找结果所在行所对应的Descriptor Usage列就表示当前应该传入的descriptor类型（若Descriptor Usage列为Both，表示两种类型都可以传入，需要设备级禁用时传入DEVICE，需要接口级禁用时传入INTERFACE）。 |

## UsbPolicy

USB读写策略的枚举。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称       | 值   | 说明       |
| ---------- | ---- | ---------- |
| READ_WRITE | 0    | 可读可写。 |
| READ_ONLY  | 1    | 只读。     |
| DISABLED   | 2    | 禁用。     |

## Descriptor<sup>14+</sup>

USB存储设备访问策略的枚举。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称      | 值   | 说明         |
| --------- | ---- | ------------ |
| INTERFACE | 0    | 接口描述符。 |
| DEVICE    | 1    | 设备描述符。 |

## PermissiveUsbDeviceType

USB设备类型信息，支持部分字段匹配。

- 与[UsbDeviceType](#usbdevicetype14)相比，本接口的subClass、protocol、descriptor字段为可选字段，实现更灵活的USB设备禁用策略。

- 支持仅根据baseClass字段进行匹配。

- 支持配置多个字段，多个字段同时满足才匹配。

- 可通过[getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices)接口获取已接入主设备的USB设备列表，并从返回值列表中查找当前设备的类型信息。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称       | 类型                        | 只读 | 可选 | 说明                                                         |
| ---------- | --------------------------- | ---- | ---- | ------------------------------------------------------------ |
| baseClass  | number                      | 否   | 否   | 类型编码。取值范围为[0, 255]。<br>若descriptor为DEVICE，则本字段取USBDevice.clazz字段值；若descriptor为INTERFACE，则本字段取USBDevice.configs.interfaces.clazz字段值。 |
| subClass   | number                      | 否   | 是   | 子类型编码。取值范围为[0, 255]。<br>若descriptor为DEVICE，则本字段取USBDevice.subClass字段值；若descriptor为INTERFACE，则本字段取USBDevice.configs.interfaces.subClass字段值。 |
| protocol   | number                      | 否   | 是   | 协议编码。取值范围为[0, 255]。<br>若descriptor为DEVICE，则本字段取USBDevice.protocol字段值；若descriptor为INTERFACE，则本字段取USBDevice.configs.interfaces.protocol字段值。 |
| descriptor | [Descriptor](#descriptor14) | 否   | 是   | USB描述符。<br>若USBDevice.clazz字段值为0，则须在[defined-class-codes](https://www.usb.org/defined-class-codes)中的Base Class列查找USBDevice.configs.interfaces.clazz字段值，查找结果所在行所对应的Descriptor Usage列就表示当前应该传入的descriptor类型（若Descriptor Usage列为Both，表示两种类型都可以传入，需要设备级禁用时传入DEVICE，需要接口级禁用时传入INTERFACE）；若USBDevice.clazz字段值为其他值，则须在[defined-class-codes](https://www.usb.org/defined-class-codes)中的Base Class列查找该值，查找结果所在行所对应的Descriptor Usage列就表示当前应该传入的descriptor类型（若Descriptor Usage列为Both，表示两种类型都可以传入，需要设备级禁用时传入DEVICE，需要接口级禁用时传入INTERFACE）。 |
