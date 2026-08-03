# @ohos.enterprise.telephonyManager（通话管理）
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

本模块提供通话管理能力。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅适用于Stage模型。
>
> 本模块接口仅对设备管理应用开放，调用接口前需激活该应用，详情请参考[MDM Kit开发指南](../../mdm/mdm-kit-guide.md)。
>
> 全局通用限制类策略由restrictions提供，若要全局禁用通话，请参考[@ohos.enterprise.restrictions（限制类策略）](js-apis-enterprise-restrictions.md)。

## 导入模块

```ts
import { telephonyManager } from '@kit.MDMKit';
```

## telephonyManager.setSimDisabled

setSimDisabled(admin: Want, slotId: number): void

禁用指定卡槽的SIM卡。禁用后，无法使用该卡槽的SIM卡接打电话、收发短信、上网。例如，企业设备管理员可在员工离职或设备丢失时，禁用SIM卡防止未授权使用。适用于企业需要限制员工设备通话能力的场景，例如员工离职或设备遗失时防止SIM卡被滥用，保障企业通信安全和成本控制。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [从严管控](../../mdm/mdm-kit-multi-mdm.md#规则1从严管控)。

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| slotId | number                     | 是   | 卡槽ID，目前仅支持单卡槽设备和双卡槽设备，取值范围为0或1，其中0表示卡槽1，1表示卡槽2。 |

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
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // 设置要禁用的卡槽ID
  let slotId: number = 0;
  // 禁用指定卡槽的SIM卡
  telephonyManager.setSimDisabled(wantTemp, slotId);
  console.info(`Succeeded in setting slotId: ${slotId} disabled.`);
} catch (err) {
  console.error(`Failed to set slotId disabled. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.setSimEnabled

setSimEnabled(admin: Want, slotId: number): void

解除指定卡槽的SIM卡禁用。使用setSimDisabled禁用SIM卡后，再用setSimEnabled启用SIM卡，需要到设置-移动网络-SIM卡管理界面手动打开SIM卡开关。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [从严管控](../../mdm/mdm-kit-multi-mdm.md#规则1从严管控)。

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| slotId | number                     | 是   |卡槽ID，目前仅支持单卡槽设备和双卡槽设备，取值范围为0或1，其中0表示卡槽1，1表示卡槽2。  |

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
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // 设置要启用的卡槽ID
  let slotId: number = 0;
  // 启用指定卡槽的SIM卡
  telephonyManager.setSimEnabled(wantTemp, slotId);
  console.info(`Succeeded in setting slotId: ${slotId} enabled.`);
} catch (err) {
  console.error(`Failed to set slotId enabled. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.isSimDisabled

isSimDisabled(admin: Want, slotId: number): boolean

查询指定卡槽是否禁用。适用于企业管理员需要确认SIM卡禁用策略是否生效的场景，帮助管理员验证策略执行状态，确保通话管控策略正确实施。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                   |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| slotId | number                     | 是   |卡槽ID，目前仅支持单卡槽设备和双卡槽设备，取值范围为0或1，其中0表示卡槽1，1表示卡槽2。  |

**返回值：**

| 类型                               | 说明                      |
| ---------------------------------- | ------------------------- |
| boolean | 指定卡槽的禁用状态。true表示已被禁用，false表示未被禁用。|

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
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // 设置要查询的卡槽ID
  let slotId: number = 0;
  // 查询指定卡槽的SIM卡是否被禁用
  let result: boolean = telephonyManager.isSimDisabled(wantTemp, slotId);
  console.info(`Succeeded in querying slotId: ${slotId} is disabled or not, result: ${result}`);
} catch (err) {
  console.error(`Failed to query sim is disabled or not. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.addOutgoingCallPolicyNumbers

addOutgoingCallPolicyNumbers(admin: Want, policy: adminManager.Policy, numbers: Array\<string>): void

添加通话呼出的允许或禁用名单，如果不添加名单，任意号码都可以呼出，添加后只有名单内的号码允许或禁止呼出。例如，企业可限制员工只能拨打客户服务热线，或禁止拨打特定号码。

以下情况下，通过本接口添加通话呼出的允许或禁用名单，会报策略冲突：

1. 已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口禁用了设备通话能力，再通过本接口添加通话呼出的禁用或允许名单，返回203错误码。通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口解除禁用设备通话能力后，可解除冲突。
2. 已经通过本接口设置了通话呼出的禁用名单，再通过本接口添加通话呼出允许名单，返回9200010错误码。通过[removeOutgoingCallPolicyNumbers](#telephonymanagerremoveoutgoingcallpolicynumbers)接口将之前设置的通话呼出禁用名单移除后，可解除冲突。
3. 已经通过本接口设置了通话呼出的允许名单，再通过本接口添加通话呼出禁用名单，返回9200010错误码。通过[removeOutgoingCallPolicyNumbers](#telephonymanagerremoveoutgoingcallpolicynumbers)接口将之前设置的通话呼出允许名单移除后，可解除冲突。


**需要权限：** ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                   |
| --------- | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| policy | [adminManager.Policy](js-apis-enterprise-adminManager.md#policy20)    | 是   | 允许或禁用名单策略。BLOCK_LIST为禁用名单，TRUST_LIST为允许名单。   |
| numbers | Array\<string>    | 是   | 通话号码列表，当前仅支持全号码匹配。数组总长度不能超过1000。例如，若当前允许名单数组中已有100个号码，则最多支持通过该接口再添加900个。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 9200012  | Parameter verification failed.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';
import { adminManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // 设置策略类型为禁用名单
  let policy: adminManager.Policy = adminManager.Policy.BLOCK_LIST;
  // 设置要添加到禁用名单的通话号码
  let numbers: Array<string> = [
    // 需根据实际情况进行替换
    "13112345678"
  ];
  // 添加通话呼出禁用名单
  telephonyManager.addOutgoingCallPolicyNumbers(wantTemp, policy, numbers);
  console.info('Succeeded in adding outgoing call policy.');
} catch (err) {
  console.error(`Failed to add outgoing call policy. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.removeOutgoingCallPolicyNumbers

removeOutgoingCallPolicyNumbers(admin: Want, policy: adminManager.Policy, numbers: Array\<string>): void

移除通话呼出的允许或禁用名单，若在该名单尚未设置时进行移除，则会移除失败。例如，企业可在解除通话限制、恢复员工正常通话权限时使用。

以下情况下，通过本接口移除通话呼出的允许或禁用名单，会报策略冲突：

已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口禁用了设备通话能力，再通过本接口移除通话呼出的禁用或允许名单，返回203错误码。通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口解除禁用设备通话能力后，可解除冲突。


**需要权限：** ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                   |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| policy | [adminManager.Policy](js-apis-enterprise-adminManager.md#policy20)    | 是   | 允许或禁用名单策略。BLOCK_LIST为禁用名单，TRUST_LIST为允许名单。   |
| numbers | Array\<string>    | 是   | 待移除的通话号码数组。数组总长度不能超过1000。  |


**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';
import { adminManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // 设置策略类型为禁用名单
  let policy: adminManager.Policy = adminManager.Policy.BLOCK_LIST;
  // 设置要从禁用名单中移除的通话号码
  let numbers: Array<string> = [
    // 需根据实际情况进行替换
    "13112345678"
  ];
  // 移除通话呼出禁用名单中的指定号码
  telephonyManager.removeOutgoingCallPolicyNumbers(wantTemp, policy, numbers);
  console.info('Succeeded in removing outgoing call policy.');
} catch (err) {
  console.error(`Failed to remove outgoing call policy. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.getOutgoingCallPolicyNumbers

getOutgoingCallPolicyNumbers(admin: Want | null, policy: adminManager.Policy): Array\<string>

获取通话呼出的允许或禁用名单。


**需要权限：** ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名     | 类型                                                    | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。<br>当设备存在多个MDM应用时，API版本26.0.0之前，传入Want时查询对应企业设备管理应用设置的策略。从API版本26.0.0开始，新增支持传入null时查询实际生效的策略。|
| policy | [adminManager.Policy](js-apis-enterprise-adminManager.md#policy20)    | 是   | 允许或禁用名单策略。 BLOCK_LIST为禁用名单，TRUST_LIST为允许名单。  |


**返回值：**

| 类型                                     | 说明                    |
| ---------------------------------------- | ----------------------- |
| Array\<string> | 通话呼出禁用或允许名单的号码数组。 |

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
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';
import { adminManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // 设置策略类型为禁用名单
  let policy: adminManager.Policy = adminManager.Policy.BLOCK_LIST;
  // 获取通话呼出禁用名单
  let numbers: Array<string> = telephonyManager.getOutgoingCallPolicyNumbers(wantTemp, policy);
  console.info(`Succeeded in getting outgoing call policy. result: ${JSON.stringify(numbers)}`);
} catch (err) {
  console.error(`Failed to get outgoing call policy. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.addIncomingCallPolicyNumbers

addIncomingCallPolicyNumbers(admin: Want, policy: adminManager.Policy, numbers: Array\<string>): void

添加通话呼入的允许或禁用名单，如果不添加名单，则任意号码都可以呼入，添加后仅名单内的号码允许或禁止呼入。例如，企业可限制员工只能接听客户来电，或禁止接听骚扰电话。

以下情况下，通过本接口添加通话呼入的允许或禁用名单，会报策略冲突：

1. 已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口禁用了设备通话能力，再通过本接口添加通话呼入的禁用或允许名单，返回203错误码。通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口解除禁用设备通话能力后，可解除冲突。
2. 已经通过本接口设置了通话呼入的禁用名单，再通过本接口添加通话呼入允许名单，返回9200010错误码。通过[removeIncomingCallPolicyNumbers](#telephonymanagerremoveincomingcallpolicynumbers)接口将之前设置的通话呼入禁用名单移除后，可解除冲突。
3. 已经通过本接口设置了通话呼入的允许名单，再通过本接口添加通话呼入禁用名单，返回9200010错误码。通过[removeIncomingCallPolicyNumbers](#telephonymanagerremoveincomingcallpolicynumbers)接口将之前设置的通话呼入允许名单移除后，可解除冲突。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                   |
| --------- | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| policy | [adminManager.Policy](js-apis-enterprise-adminManager.md#policy20)    | 是   | 允许或禁用名单策略。BLOCK_LIST为禁用名单，TRUST_LIST为允许名单。   |
| numbers | Array\<string>    | 是   | 通话号码列表，当前仅支持全号码匹配。数组总长度不能超过1000。例如，若当前允许名单数组中已有100个号码，则最多支持通过该接口再添加900个。  |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 9200012  | Parameter verification failed.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';
import { adminManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // 设置策略类型为禁用名单
  let policy: adminManager.Policy = adminManager.Policy.BLOCK_LIST;
  // 设置要添加到禁用名单的通话号码
  let numbers: Array<string> = [
    // 需根据实际情况进行替换
    "13112345678"
  ];
  // 添加通话呼入禁用名单
  telephonyManager.addIncomingCallPolicyNumbers(wantTemp, policy, numbers);
  console.info('Succeeded in adding incoming call policy.');
} catch (err) {
  console.error(`Failed to add incoming call policy. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.removeIncomingCallPolicyNumbers

removeIncomingCallPolicyNumbers(admin: Want, policy: adminManager.Policy, numbers: Array\<string>): void

移除通话呼入的允许或禁用名单，若在该名单尚未设置时进行移除，则会移除失败。例如，企业可在解除呼入通话限制、恢复员工正常接听权限时使用。

以下情况下，通过本接口移除通话呼入的允许或禁用名单，会报策略冲突：

1. 已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口禁用了设备通话能力，再通过本接口移除通话呼入的禁用或允许名单，返回203错误码。通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口解除禁用设备通话能力后，可解除冲突。


**需要权限：** ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                   |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| policy | [adminManager.Policy](js-apis-enterprise-adminManager.md#policy20)    | 是   | 允许或禁用名单策略。BLOCK_LIST为禁用名单，TRUST_LIST为允许名单。   |
| numbers | Array\<string>    | 是   | 待移除的通话号码数组。数组总长度不能超过1000。   |


**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';
import { adminManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // 设置策略类型为禁用名单
  let policy: adminManager.Policy = adminManager.Policy.BLOCK_LIST;
  // 设置要从禁用名单中移除的通话号码
  let numbers: Array<string> = [
    // 需根据实际情况进行替换
    "13112345678"
  ];
  // 移除通话呼入禁用名单中的指定号码
  telephonyManager.removeIncomingCallPolicyNumbers(wantTemp, policy, numbers);
  console.info('Succeeded in removing incoming call policy.');
} catch (err) {
  console.error(`Failed to remove incoming call policy. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.getIncomingCallPolicyNumbers

getIncomingCallPolicyNumbers(admin: Want | null, policy: adminManager.Policy): Array\<string>

获取通话呼入的允许或禁用名单。


**需要权限：** ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名     | 类型                                                    | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。<br>当设备存在多个MDM应用时，API版本26.0.0之前，传入Want时查询对应企业设备管理应用设置的策略。从API版本26.0.0开始，新增支持传入null时查询实际生效的策略。|
| policy | [adminManager.Policy](js-apis-enterprise-adminManager.md#policy20)    | 是   | 允许或禁用名单策略。BLOCK_LIST为禁用名单，TRUST_LIST为允许名单。   |


**返回值：**

| 类型                                     | 说明                    |
| ---------------------------------------- | ----------------------- |
| Array\<string> | 通话呼入禁用或允许名单的号码数组。 |

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
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';
import { adminManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // 设置策略类型为禁用名单
  let policy: adminManager.Policy = adminManager.Policy.BLOCK_LIST;
  // 获取通话呼入禁用名单
  let numbers: Array<string> = telephonyManager.getIncomingCallPolicyNumbers(wantTemp, policy);
  console.info(`Succeeded in getting incoming call policy. result: ${JSON.stringify(numbers)}`);
} catch (err) {
  console.error(`Failed to get incoming call policy. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.hangupCalling<sup>23+</sup>

hangupCalling(admin: Want): void

挂断当前通话。仅支持运营商通话，不包括畅联等。例如，企业设备管理员可在企业安全管理场景中，强制挂断员工正在进行的不合规通话。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |

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
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // 挂断当前通话
  telephonyManager.hangupCalling(wantTemp);
} catch (err) {
  console.error(`Failed to hang up calling. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.activeSim

activeSim(admin: Want, slotId: number): void

启用指定卡槽的SIM卡。设备已经插入SIM卡但是并未启用的场景，可以通过该接口启用SIM卡，无需用户手动启用。SIM卡启用后可以使用该SIM卡进行通信。该接口需要插入SIM卡并关闭飞行模式才能成功调用。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| slotId | number                     | 是   | 卡槽ID，目前仅支持单卡槽设备和双卡槽设备，取值范围为0或1，其中0表示卡槽1，1表示卡槽2。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 9201017  | SIM card activation or deactivation failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 设置要启用的卡槽ID
let slotId: number = 0;
try {
  // 启用指定卡槽的SIM卡
  telephonyManager.activeSim(wantTemp, slotId);
  console.info(`success to active SIM`);
} catch (err) {
  console.error(`Failed to active SIM. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.deactiveSim

deactiveSim(admin: Want, slotId: number): void

停用指定卡槽SIM卡。停用该SIM卡，无法使用该卡槽的SIM卡接打电话，收发短信，上网。例如，企业可在员工休假或设备维护期间，临时停用SIM卡。该接口需要插入SIM卡并关闭飞行模式才能成功调用。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| slotId | number                     | 是   | 卡槽ID，目前仅支持单卡槽设备和双卡槽设备，取值范围为0或1，其中0表示卡槽1，1表示卡槽2。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 9201017  | SIM card activation or deactivation failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 设置要停用的卡槽ID
let slotId: number = 0;
try {
  // 停用指定卡槽的SIM卡
  telephonyManager.deactiveSim(wantTemp, slotId);
  console.info(`success to deactive SIM`);
} catch (err) {
  console.error(`Failed to deactive SIM. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.setDefaultData

setDefaultData(admin: Want, slotId: number): void

设置指定卡槽的SIM卡为默认数据流量卡，设备将使用指定卡槽的SIM卡流量上网。例如，企业可在双卡设备管理场景中，为员工设备指定默认的数据流量卡以统一管理流量使用。该接口需要插入SIM卡并关闭飞行模式才能成功调用。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| slotId | number                     | 是   | 卡槽ID，目前仅支持单卡槽设备和双卡槽设备，取值范围为0或1，其中0表示卡槽1，1表示卡槽2。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 9201020  | Failed to set the default data SIM card. The airplane mode is enabled or no SIM card is inserted. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 设置要作为默认数据流量卡的卡槽ID
let slotId: number = 0;
try {
  // 设置指定卡槽为默认数据流量卡
  telephonyManager.setDefaultData(wantTemp, slotId);
  console.info(`success to set default data SIM ID`);
} catch (err) {
  console.error(`Failed to set default data. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.getDefaultData

getDefaultData(admin: Want): number

获取设备当前默认使用的数据流量卡卡槽ID。例如，企业设备管理员可在设备管理过程中查询当前配置的默认数据流量卡，以便进行流量管理或切换数据卡配置。未插卡或者飞行模式下会获取上一次使用的数据流量卡卡槽ID、设备从未设置过默认数据流量卡场景下，该接口返回默认卡槽1，值为0。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在Phone和Tablet设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |

**返回值：**

| 类型                               | 说明                      |
| ---------------------------------- | ------------------------- |
| number | 卡槽ID，目前仅支持单卡槽设备和双卡槽设备，取值范围为0或1，其中0表示卡槽1，1表示卡槽2。|

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // 获取当前默认数据流量卡的卡槽ID
  let slotId: number = telephonyManager.getDefaultData(wantTemp);
  console.info(`success to get default data SIM ID, current is ${slotId}`);
} catch (err) {
  console.error(`Failed to get default data. Code: ${err.code}, message: ${err.message}`);
}
```