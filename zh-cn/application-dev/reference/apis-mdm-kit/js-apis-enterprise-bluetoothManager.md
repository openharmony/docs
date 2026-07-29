# @ohos.enterprise.bluetoothManager（蓝牙管理）
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

本模块提供设备蓝牙管理的能力，包括设置蓝牙开关状态、查询蓝牙信息，管理蓝牙设备可用名单、蓝牙设备禁用名单、蓝牙协议禁用名单等。通过本模块，企业可以统一管理设备蓝牙功能，实现对蓝牙设备连接的精细化管控，提升企业信息安全水平，适用于企业需要对员工设备的蓝牙使用进行规范化管理的场景。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对设备管理应用开放，且调用接口前需激活设备管理应用，具体请参考[MDM Kit开发指南](../../mdm/mdm-kit-guide.md)。
>
> 全局通用限制类策略由restrictions统一提供，若要全局禁用蓝牙，请参考[@ohos.enterprise.restrictions（限制类策略）](js-apis-enterprise-restrictions.md)。

## 导入模块

```ts
import { bluetoothManager } from '@kit.MDMKit';
```

## bluetoothManager.getBluetoothInfo

getBluetoothInfo(admin: Want): BluetoothInfo

查询设备蓝牙信息。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |

**返回值：**

| 类型                            | 说明                                             |
| ------------------------------- | ------------------------------------------------ |
| [BluetoothInfo](#bluetoothinfo) | 蓝牙信息，包含蓝牙名称、蓝牙状态和蓝牙连接状态。 |

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
import { bluetoothManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

// 创建企业设备管理扩展组件
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // 获取蓝牙信息
  let result: bluetoothManager.BluetoothInfo = bluetoothManager.getBluetoothInfo(wantTemp);
  console.info(`Succeeded in getting bluetooth info: ${JSON.stringify(result)}`);
} catch(err) {
  console.error(`Failed to get bluetooth info. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.addAllowedBluetoothDevices

addAllowedBluetoothDevices(admin: Want, deviceIds: Array\<string>): void

添加蓝牙设备可用名单。添加蓝牙设备可用名单后当前设备仅允许连接该名单下的蓝牙设备。从API version 22开始，数组中的MAC地址必须符合蓝牙MAC规范（例如：00:1A:2B:3C:4D:5E），添加时会移除不合法的MAC地址，仅添加合法的MAC地址。

以下情况下，通过本接口添加蓝牙设备可用名单，会报策略冲突：

1. 已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口禁用了蓝牙。通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口启用蓝牙后，可解除冲突。
2. 已经通过[addDisallowedBluetoothDevices](#bluetoothmanageradddisallowedbluetoothdevices20)接口添加了蓝牙设备禁用名单。通过[removeDisallowedBluetoothDevices](#bluetoothmanagerremovedisallowedbluetoothdevices20)移除蓝牙设备禁用名单后，可解除冲突。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                |
| --------- | ------------------------------------------------------- | ---- | --------------------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                      |
| deviceIds | Array\<string>                                          | 是   | 蓝牙设备MAC地址的数组。蓝牙设备允许名单数组长度上限为1000，若当前允许名单中已有300个蓝牙设备MAC地址，则只允许再添加700个。 |

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
import { bluetoothManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

// 创建企业设备管理扩展组件
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 定义蓝牙设备MAC地址数组（需根据实际情况进行替换）
let deviceIds: Array<string> = ["00:1A:2B:3C:4D:5E","AA:BB:CC:DD:EE:FF"];
try {
  // 添加蓝牙设备允许名单
  bluetoothManager.addAllowedBluetoothDevices(wantTemp,deviceIds);
  console.info(`Succeeded in adding allowed bluetooth devices.`);
} catch(err) {
  console.error(`Failed to add allowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.removeAllowedBluetoothDevices

removeAllowedBluetoothDevices(admin: Want, deviceIds: Array\<string>): void

移除蓝牙设备可用名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                    |
| --------- | ------------------------------------------------------- | ---- | ----------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。          |
| deviceIds | Array\<string>                                          | 是   | 蓝牙设备MAC地址的数组。 |

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
import { bluetoothManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

// 创建企业设备管理扩展组件
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 定义蓝牙设备MAC地址数组（需根据实际情况进行替换）
let deviceIds: Array<string> = ["00:1A:2B:3C:4D:5E","AA:BB:CC:DD:EE:FF"];
try {
  // 移除蓝牙设备允许名单
  bluetoothManager.removeAllowedBluetoothDevices(wantTemp,deviceIds);
  console.info(`Succeeded in removing allowed bluetooth devices.`);
} catch(err) {
  console.error(`Failed to remove allowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.getAllowedBluetoothDevices

getAllowedBluetoothDevices(admin: Want | null): Array\<string>

获取蓝牙设备可用名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。<br>当设备存在多个MDM应用时，API版本26.0.0之前，传入Want时查询对应企业设备管理应用设置的策略。从API版本26.0.0开始，新增支持传入null时查询实际生效的策略。|

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Array\<string> | 可用名单中蓝牙设备MAC地址的数组。 |

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
import { bluetoothManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

// 创建企业设备管理扩展组件
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // 获取蓝牙设备允许名单
  let result: Array<string> = bluetoothManager.getAllowedBluetoothDevices(wantTemp);
  console.info(`Succeeded in getting allowed bluetooth devices. Result: ${JSON.stringify(result)}`);
} catch(err) {
  console.error(`Failed to get allowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.addDisallowedBluetoothDevices<sup>20+</sup>

addDisallowedBluetoothDevices(admin: Want, deviceIds: Array&lt;string&gt;): void

添加蓝牙设备禁用名单。添加禁用名单后当前设备不允许连接该名单下的蓝牙设备。从API version 22开始，数组中的MAC地址必须符合蓝牙MAC规范（例如：00:1A:2B:3C:4D:5E），添加时会移除不合法的MAC地址，仅添加合法的MAC地址。

以下情况下，通过本接口添加蓝牙设备禁用名单，会报策略冲突：

1. 已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口禁用了蓝牙。通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口启用蓝牙后，可解除冲突。
2. 已经通过[addAllowedBluetoothDevices](#bluetoothmanageraddallowedbluetoothdevices)接口添加了蓝牙设备可用名单。通过[removeAllowedBluetoothDevices](#bluetoothmanagerremoveallowedbluetoothdevices)移除蓝牙设备可用名单后，可解除冲突。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                |
| --------- | ------------------------------------------------------- | ---- | --------------------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                      |
| deviceIds | Array&lt;string&gt;                                          | 是   | 蓝牙设备MAC地址的数组。蓝牙设备禁用名单数组长度上限为1000，若当前禁用名单中已有300个蓝牙设备MAC地址，则只允许再添加700个。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { bluetoothManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

// 创建企业设备管理扩展组件
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 定义蓝牙设备MAC地址数组（需根据实际情况进行替换）
let deviceIds: Array<string> = ["00:1A:2B:3C:4D:5E","AA:BB:CC:DD:EE:FF"];
try {
  // 添加蓝牙设备禁用名单
  bluetoothManager.addDisallowedBluetoothDevices(wantTemp,deviceIds);
  console.info(`Succeeded in adding disallowed bluetooth devices.`);
} catch(err) {
  console.error(`Failed to add disallowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.removeDisallowedBluetoothDevices<sup>20+</sup>

removeDisallowedBluetoothDevices(admin: Want, deviceIds: Array&lt;string&gt;): void

移除蓝牙设备禁用名单。若移除禁用名单中的部分蓝牙设备，则当前设备不允许连接禁用名单内剩余的蓝牙设备。若移除禁用名单中的所有蓝牙设备，则当前设备可以连接任意的蓝牙设备。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                    |
| --------- | ------------------------------------------------------- | ---- | ----------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。          |
| deviceIds | Array&lt;string&gt;                                          | 是   | 蓝牙设备MAC地址的数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { bluetoothManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

// 创建企业设备管理扩展组件
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 定义蓝牙设备MAC地址数组（需根据实际情况进行替换）
let deviceIds: Array<string> = ["00:1A:2B:3C:4D:5E","AA:BB:CC:DD:EE:FF"];
try {
  // 移除蓝牙设备禁用名单
  bluetoothManager.removeDisallowedBluetoothDevices(wantTemp,deviceIds);
  console.info(`Succeeded in removing disallowed bluetooth devices.`);
} catch(err) {
  console.error(`Failed to remove disallowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.getDisallowedBluetoothDevices<sup>20+</sup>

getDisallowedBluetoothDevices(admin: Want | null): Array&lt;string&gt;

获取蓝牙设备禁用名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。<br>当设备存在多个MDM应用时，API版本26.0.0之前，传入Want时查询对应企业设备管理应用设置的策略。从API版本26.0.0开始，新增支持传入null时查询实际生效的策略。|

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Array&lt;string&gt; | 禁用名单中蓝牙设备MAC地址的数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { bluetoothManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

// 创建企业设备管理扩展组件
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // 获取蓝牙设备禁用名单
  let result: Array<string> = bluetoothManager.getDisallowedBluetoothDevices(wantTemp);
  console.info(`Succeeded in getting disallowed bluetooth devices. Result: ${JSON.stringify(result)}`);
} catch(err) {
  console.error(`Failed to get disallowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.turnOnBluetooth<sup>20+</sup>

turnOnBluetooth(admin: Want): void

开启蓝牙。蓝牙开启后用户可以手动关闭。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                   |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { bluetoothManager } from '@kit.MDMKit';

// 创建企业设备管理扩展组件
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // 开启蓝牙
  bluetoothManager.turnOnBluetooth(wantTemp);
  console.info(`Succeeded in turning on bluetooth.`);
} catch(err) {
  console.error(`Failed to turn on bluetooth. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.turnOffBluetooth<sup>20+</sup>

turnOffBluetooth(admin: Want): void

关闭蓝牙。蓝牙关闭后用户可以手动打开。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                   |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { bluetoothManager } from '@kit.MDMKit';

// 创建企业设备管理扩展组件
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // 关闭蓝牙
  bluetoothManager.turnOffBluetooth(wantTemp);
  console.info('Succeeded in turning off bluetooth.');
} catch(err) {
  console.error(`Failed to turn off bluetooth. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.addDisallowedBluetoothProtocols<sup>20+</sup>

addDisallowedBluetoothProtocols(admin: Want, accountId: number, protocols: Array&lt;Protocol&gt;): void

添加蓝牙协议禁用名单。添加后，指定用户将无法使用该禁用名单中的蓝牙协议向其他设备外发文件。通过该接口禁用GATT或SPP协议，对系统服务和系统应用不生效。当传入SPP协议时，会同时禁用接收和发送功能。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                   |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| accountId | number | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |
| protocols  | Array&lt;[Protocol](#protocol20)&gt; | 是   | 蓝牙协议的数组。数组长度上限为10000。 |

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
import { bluetoothManager } from '@kit.MDMKit';

// 创建企业设备管理扩展组件
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 定义用户ID（需根据实际情况进行替换）
let accountId: number = 100;
// 定义蓝牙协议数组（需根据实际情况进行替换）
let protocols: Array<bluetoothManager.Protocol> = [bluetoothManager.Protocol.GATT, bluetoothManager.Protocol.SPP];
try {
  // 添加蓝牙协议禁用名单
  bluetoothManager.addDisallowedBluetoothProtocols(wantTemp, accountId, protocols);
  console.info('Succeeded in adding disallowed bluetooth protocols policy.');
} catch (err) {
  console.error(`Failed to add disallowed bluetooth protocols. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.removeDisallowedBluetoothProtocols<sup>20+</sup>

removeDisallowedBluetoothProtocols(admin: Want, accountId: number, protocols: Array&lt;Protocol&gt;): void

移除蓝牙协议禁用名单。若移除禁用名单中某个用户的部分蓝牙协议，则该用户不能使用禁用名单内剩余的蓝牙协议向其他设备外发文件。若移除禁用名单中某个用户的所有蓝牙协议，则该用户可以使用任意蓝牙协议向其他设备外发文件。若移除禁用名单中不存在的蓝牙协议，接口可调用成功，但不会移除禁用名单中不存在的蓝牙协议。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                   |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| accountId | number | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |
| protocols  | Array&lt;[Protocol](#protocol20)&gt; | 是   | 蓝牙协议的数组。 |

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
import { bluetoothManager } from '@kit.MDMKit';

// 创建企业设备管理扩展组件
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 定义用户ID（需根据实际情况进行替换）
let accountId: number = 100;
// 定义蓝牙协议数组（需根据实际情况进行替换）
let protocols: Array<bluetoothManager.Protocol> = [bluetoothManager.Protocol.GATT, bluetoothManager.Protocol.SPP];
try {
  // 移除蓝牙协议禁用名单
  bluetoothManager.removeDisallowedBluetoothProtocols(wantTemp, accountId, protocols);
  console.info('Succeeded in removing disallowed bluetooth protocols policy.');
} catch (err) {
  console.error(`Failed to remove disallowed bluetooth protocols. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.getDisallowedBluetoothProtocols<sup>20+</sup>

getDisallowedBluetoothProtocols(admin: Want, accountId: number): Array&lt;Protocol&gt;

获取指定用户的蓝牙协议禁用名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                   |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| accountId | number | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。 |

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Array&lt;[Protocol](#protocol20)&gt; | 禁用名单中蓝牙协议的数组。 |

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
import { bluetoothManager } from '@kit.MDMKit';

// 创建企业设备管理扩展组件
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 定义用户ID（需根据实际情况进行替换）
let accountId: number = 100;
try {
  // 获取指定用户的蓝牙协议禁用名单
  let result: Array<bluetoothManager.Protocol> = bluetoothManager.getDisallowedBluetoothProtocols(wantTemp, accountId);
  console.info(`Succeeded in getting disallowed bluetooth protocols. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed bluetooth protocols. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.addDisallowedBluetoothProtocols

addDisallowedBluetoothProtocols(admin: Want, accountId: number, protocols: Array\<Protocol\>, policy: TransferPolicy): void

添加蓝牙协议至禁用名单。添加后，指定用户将无法根据指定的传输策略使用该禁用名单中的蓝牙协议。

> **说明：**
> 
> 1. 通过该接口禁用GATT或SPP协议，对系统服务和系统应用不生效。
> 2. 当传入SPP协议时，policy参数只能传入TransferPolicy.RECEIVE_SEND，否则会返回错误码9200012。
> 3. 本接口与[addDisallowedBluetoothProtocols<sup>20+</sup>](#bluetoothmanageradddisallowedbluetoothprotocols20)接口为重载接口。本接口增加了policy参数用于指定传输策略，可以更精细地控制蓝牙协议的禁用行为（如仅禁止发送、仅禁止接收或同时禁止发送和接收）。如果同时使用两个接口配置了禁用策略，策略会合并生效。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                               |
| accountId | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。|
| protocols | Array&lt;[Protocol](#protocol20)&gt; | 是 | 蓝牙协议数组，指定需要添加至禁用名单的协议。|
| policy | [TransferPolicy](#transferpolicy) | 是 | 传输策略,用于指定蓝牙协议的禁用方式。可选值包括:SEND_ONLY(禁止发送)、RECEIVE_ONLY(禁止接收)、RECEIVE_SEND(禁止发送和接收)。|

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { bluetoothManager } from '@kit.MDMKit';

// 创建企业设备管理扩展组件
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// 定义用户ID
let accountId: number = 100;
// 定义蓝牙协议数组
let protocols: Array<bluetoothManager.Protocol> = [
  bluetoothManager.Protocol.GATT,
  bluetoothManager.Protocol.SPP,
  bluetoothManager.Protocol.OPP
];

try {
  // 添加蓝牙协议禁用名单，指定传输策略为禁止发送和接收
  bluetoothManager.addDisallowedBluetoothProtocols(wantTemp, accountId, protocols, bluetoothManager.TransferPolicy.RECEIVE_SEND);
  console.info('Succeeded in adding disallowed bluetooth protocols.');
} catch (err) {
  console.error(`Failed to add disallowed bluetooth protocols. Code is ${err.code}, message is ${err.message}`);
}
```

## bluetoothManager.removeDisallowedBluetoothProtocols

removeDisallowedBluetoothProtocols(admin: Want, accountId: number, protocols: Array\<Protocol\>, policy: TransferPolicy): void

从禁用名单中移除蓝牙协议。移除后，指定用户将不再受该传输策略的限制，可以正常使用这些蓝牙协议。

> **说明：**
> 
> 1. 当传入SPP协议时，policy参数只能传入TransferPolicy.RECEIVE_SEND，否则会返回错误码9200012。
> 2. 本接口与[removeDisallowedBluetoothProtocols<sup>20+</sup>](#bluetoothmanagerremovedisallowedbluetoothprotocols20)接口为重载接口。本接口增加了policy参数，用于按传输策略移除禁用配置。若同一协议通过两个接口分别配置了不同策略的禁用，调用本接口仅移除对应策略的禁用配置，其他策略的禁用配置仍生效。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                               |
| accountId | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。|
| protocols    | Array&lt;[Protocol](#protocol20)&gt;                                     | 是   | 蓝牙协议数组，指定需要从禁用名单中移除的协议。|
| policy | [TransferPolicy](#transferpolicy) | 是 | 传输策略。|

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { bluetoothManager } from '@kit.MDMKit';

// 创建企业设备管理扩展组件
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// 定义用户ID
let accountId: number = 100;
// 定义蓝牙协议数组
let protocols: Array<bluetoothManager.Protocol> = [
  bluetoothManager.Protocol.GATT,
  bluetoothManager.Protocol.SPP,
  bluetoothManager.Protocol.OPP
];

try {
  // 移除蓝牙协议禁用名单，指定传输策略为禁止发送和接收
  bluetoothManager.removeDisallowedBluetoothProtocols(wantTemp, accountId, protocols, bluetoothManager.TransferPolicy.RECEIVE_SEND);
  console.info('Succeeded in removing disallowed bluetooth protocols.');
} catch (err) {
  console.error(`Failed to remove disallowed bluetooth protocols. Code is ${err.code}, message is ${err.message}`);
}
```

## bluetoothManager.getDisallowedBluetoothProtocols

getDisallowedBluetoothProtocols(admin: Want | null, accountId: number, policy: TransferPolicy): Array\<Protocol\>

获取指定用户指定传输策略下已禁用的蓝牙协议列表。

> **说明：**
>
> 1. 本接口与[getDisallowedBluetoothProtocols<sup>20+</sup>](#bluetoothmanagergetdisallowedbluetoothprotocols20)接口为重载接口。本接口增加了policy参数，用于按传输策略查询对应的禁用配置。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。|
| accountId | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。|
| policy | [TransferPolicy](#transferpolicy) | 是 | 传输策略。|

**返回值：**

| 类型                | 说明                             |
| ------------------- | -------------------------------- |
| Array&lt;[Protocol](#protocol20)&gt; | 返回禁用名单中的蓝牙协议数组。|

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { bluetoothManager } from '@kit.MDMKit';

// 创建企业设备管理扩展组件
let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// 定义用户ID
let accountId: number = 100;

try {
  // 获取指定用户指定传输策略下已禁用的蓝牙协议列表
  let result: Array<bluetoothManager.Protocol> = bluetoothManager.getDisallowedBluetoothProtocols(wantTemp, accountId, bluetoothManager.TransferPolicy.RECEIVE_SEND);
  console.info(`Succeeded in getting disallowed bluetooth protocols, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed bluetooth protocols. Code is ${err.code}, message is ${err.message}`);
}
```

## BluetoothInfo

设备的蓝牙信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称            | 类型                                                         | 只读 | 可选 | 说明                     |
| --------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------ |
| name            | string                                                       | 否   | 否 | 表示设备的蓝牙名称。     |
| state           | [access.BluetoothState](../apis-connectivity-kit/js-apis-bluetooth-access.md#bluetoothstate) | 否   | 否 | 表示设备的蓝牙状态。     |
| connectionState | [constant.ProfileConnectionState](../apis-connectivity-kit/js-apis-bluetooth-constant.md#profileconnectionstate) | 否   | 否 | 表示设备的蓝牙连接状态。 |

## Protocol<sup>20+</sup>

蓝牙协议类型。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称                | 值  | 说明    |
| ----------------- | ---- | ----- |
| GATT | 0 | [GATT协议](../../connectivity/terminology.md#gatt)。 |
| SPP | 1 | [SPP协议](../../connectivity/terminology.md#spp)。 |
| OPP | 2 | [OPP协议](../../connectivity/terminology.md#opp)。 |

## TransferPolicy

传输策略。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称                        | 值  | 说明    |
| ----------------------------| ----| ------------------------------- |
| SEND_ONLY   | 0   | 禁止发送。 |
| RECEIVE_ONLY        | 1   | 禁止接收。 |
| RECEIVE_SEND    | 2   | 禁止发送和接收。 |