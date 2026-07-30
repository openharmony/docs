# @ohos.enterprise.browser（浏览器管理）
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

本模块提供浏览器管理能力，包括设置/取消浏览器策略、获取浏览器策略等。适用于企业设备管理、员工上网行为管控、安全合规审计等场景。

浏览器策略指通过配置或管理浏览器行为的一系列规则和设置，以确保安全性、合规性、性能优化和用户体验的一致性。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对设备管理应用开放，且调用接口前需激活设备管理应用，具体请参考[MDM Kit开发指南](../../mdm/mdm-kit-guide.md)。

## 导入模块

```ts
import { browser } from '@kit.MDMKit';
```

## browser.setPolicySync

setPolicySync(admin: Want, appId: string, policyName: string, policyValue: string): void

为指定的浏览器设置浏览器子策略，适用于企业统一管理员工浏览器行为的场景。<!--RP1--><!--RP1End-->

**需要权限：** ohos.permission.ENTERPRISE_SET_BROWSER_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** 同一个浏览器应用的同一个策略[独占](../../mdm/mdm-kit-multi-mdm.md#规则2独占)；不同浏览器、同一浏览器的不同策略[合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名      | 类型                                                    | 必填 | 说明                                                         |
| ----------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                               |
| appId       | string                                                  | 是   | 应用appId，用于指定浏览器，表示应用的唯一标识，详情信息可参考[什么是appId](../../quick-start/common-problem-of-application.md#什么是appid)。                                                                |
| policyName  | string                                                  | 是   | 浏览器子策略名，由接口调用方和指定浏览器约定。当此值为空字符串时，表示设置应用appId对应的浏览器策略。 |
| policyValue | string                                                  | 是   | 浏览器子策略值，由接口调用方和指定浏览器约定。当此值为空字符串时，表示取消浏览器策略名对应浏览器子策略。 |

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
import { browser } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// 此处参数appId的赋值应替换为开发者自己指定的浏览器的应用ID
let appId: string = 'com.example.******_******/******5t5CoBM=';
// 浏览器策略名称
let policyName: string = 'InsecurePrivateNetworkRequestsAllowed';
// 浏览器策略值
let policyValue: string = '{"level":"mandatory","scope":"machine","source":"platform","value":true}';

try {
  browser.setPolicySync(wantTemp, appId, policyName, policyValue);
  console.info('Succeeded in setting browser policies.');
} catch (err) {
  console.error(`Failed to set browser policies. Code is ${err.code}, message is ${err.message}`);
}
```

## browser.getPoliciesSync

getPoliciesSync(admin: Want | null, appId: string): string

通过appid获取指定浏览器设置的策略，适用于查询当前浏览器策略配置的场景，例如在企业设备管理应用中展示策略详情、验证策略是否生效等。<!--RP1--><!--RP1End-->

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                     |
| ------ | ------------------------------------------------------- | ---- | ------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。<br>当设备存在多个MDM应用时，API版本26.0.0之前，传入Want时查询对应企业设备管理应用设置的策略。从API版本26.0.0开始，新增支持传入null时查询实际生效的策略。|
| appId  | string                                                  | 是   | 应用ID，用于指定浏览器。详情信息可参考[什么是appId](../../quick-start/common-problem-of-application.md#什么是appid)。 |

**返回值：**

| 类型   | 说明         |
| ------ | ------------ |
| string | 浏览器策略。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { browser } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// 此处参数appId的赋值应替换为开发者自己指定的浏览器的应用ID
let appId: string = 'com.example.******_******/******5t5CoBM=';

try {
  let result: string = browser.getPoliciesSync(wantTemp, appId);
  console.info(`Succeeded in getting browser policies, result : ${JSON.stringify(result)}`);
} catch(err) {
  console.error(`Failed to get browser policies. Code is ${err.code}, message is ${err.message}`);
}
```

## browser.setManagedBrowserPolicy<sup>15+</sup>

setManagedBrowserPolicy(admin: Want, bundleName: string, policyName: string, policyValue: string): void

为指定的浏览器设置浏览器策略，适用于企业统一管理员工浏览器行为的场景，例如配置浏览器安全策略等。成功后会发布系统公共事件[COMMON_EVENT_MANAGED_BROWSER_POLICY_CHANGED](../apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_managed_browser_policy_changed)。

> **说明：**
>
> 在多MDM应用场景下，针对同一浏览器的同一策略，一旦被首个Admin配置并生效，其他Admin将无法配置。

**需要权限：** ohos.permission.ENTERPRISE_SET_BROWSER_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** 同一个浏览器应用的同一个策略[独占](../../mdm/mdm-kit-multi-mdm.md#规则2独占)；不同浏览器、同一浏览器的不同策略[合并](../../mdm/mdm-kit-multi-mdm.md#规则4合并)。

**参数：**

| 参数名      | 类型                                                    | 必填 | 说明                                                         |
| ----------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                               |
| bundleName  | string                                                  | 是   | 应用包名，用于指定浏览器，表示应用的唯一标识。                                     |
| policyName  | string                                                  | 是   | 浏览器策略名，由接口调用方和指定浏览器约定。 |
| policyValue | string                                                  | 是   | 浏览器策略值。当此值为空字符串时，表示取消浏览器策略名对应浏览器子策略。 |

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
import { browser } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
// 浏览器应用包名
let bundleName: string = 'com.example.testbrowser';
// 浏览器策略名称
let policyName: string = 'InsecurePrivateNetworkRequestsAllowed';
// 浏览器策略值
let policyValue: string = '{"level":"mandatory","scope":"machine","source":"platform","value":true}';

try {
  browser.setManagedBrowserPolicy(wantTemp, bundleName, policyName, policyValue);
  console.info('Succeeded in setting managed browser policy.');
} catch (err) {
  console.error(`Failed to set managed browser policy. Code is ${err.code}, message is ${err.message}`);
}
```

## browser.getManagedBrowserPolicy<sup>15+</sup>

getManagedBrowserPolicy(admin: Want, bundleName: string): ArrayBuffer

通过应用包名获取指定浏览器的浏览器策略，适用于查询当前浏览器策略配置的场景，例如在企业设备管理应用中展示策略详情、验证策略是否生效等。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                                                    | 必填 | 说明                     |
| ----------- | ------------------------------------------------------- | ---- | ------------------------ |
| admin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。           |
| bundleName  | string                                                  | 是   | 应用包名，用于指定浏览器。 |

**返回值：**

| 类型        | 说明         |
| ----------- | ------------ |
| ArrayBuffer | 浏览器策略。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { browser } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { util } from '@kit.ArkTS';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// 需根据实际情况进行替换
let bundleName: string = 'com.example.testbrowser';

try {
  let buffer: ArrayBuffer = browser.getManagedBrowserPolicy(wantTemp, bundleName);
  let intBuffer: Uint8Array = new Uint8Array(buffer);
  let decoder: util.TextDecoder = util.TextDecoder.create('utf-8');
  let stringData: string = decoder.decodeToString(intBuffer);
  console.info(`Succeeded in getting managed browser policy, result : ${stringData}`);
} catch(err) {
  console.error(`Failed to get managed browser policy. Code is ${err.code}, message is ${err.message}`);
}
```

## browser.getSelfManagedBrowserPolicyVersion<sup>15+</sup>

getSelfManagedBrowserPolicyVersion(): string

获取当前设备浏览器策略版本。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型    | 说明         |
| ------ | ------------ |
| string | 浏览器策略版本。 |

**示例：**

```ts
import { browser } from '@kit.MDMKit';

try {
  let version: string = browser.getSelfManagedBrowserPolicyVersion();
  console.info(`Succeeded in getting self managed browser policy version, result : ${version}`);
} catch(err) {
  console.error(`Failed to get self managed browser policy version. Code is ${err.code}, message is ${err.message}`);
}
```

## browser.getSelfManagedBrowserPolicy<sup>15+</sup>

getSelfManagedBrowserPolicy(): ArrayBuffer

获取当前设备浏览器策略。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型        | 说明         |
| ----------- | ------------ |
| ArrayBuffer | 浏览器策略。 |

**示例：**

```ts
import { browser } from '@kit.MDMKit';
import { util } from '@kit.ArkTS';

try {
  let buffer: ArrayBuffer = browser.getSelfManagedBrowserPolicy();
  let intBuffer: Uint8Array = new Uint8Array(buffer);
  let decoder: util.TextDecoder = util.TextDecoder.create('utf-8');
  let stringData: string = decoder.decodeToString(intBuffer);
  console.info(`Succeeded in getting self managed browser policy, result : ${stringData}`);
} catch(err) {
  console.error(`Failed to get self managed browser policy. Code is ${err.code}, message is ${err.message}`);
}
```