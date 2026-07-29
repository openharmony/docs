# @ohos.enterprise.networkManager（网络管理）
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

本模块提供设备网络管理能力，包括查询设备IP地址、MAC地址信息、管理网络接口状态、配置网络全局代理、管理防火墙规则和域名过滤规则、控制移动数据网络、管理APN配置、配置以太网网络等。适用于企业IT管理员对设备网络进行集中管理和安全管控，帮助企业实现网络访问策略统一管理、防止网络攻击和数据泄露、降低网络管理成本。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对设备管理应用开放，且调用接口前需激活设备管理应用，具体请参考[MDM Kit开发指南](../../mdm/mdm-kit-guide.md)。
>

## 导入模块

```ts
import { networkManager } from '@kit.MDMKit';
```

## networkManager.getAllNetworkInterfacesSync

getAllNetworkInterfacesSync(admin: Want): Array&lt;string&gt;

获取所有激活的有线网络接口。适用于企业网络管理场景，例如查看当前设备可用的网络连接、审计网络接口状态、为后续网络配置操作做准备，帮助企业了解设备网络连接状态，便于集中管理网络资源和排查网络问题。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |

**返回值：**

| 类型                | 说明                   |
| ------------------- | ---------------------- |
| Array&lt;string&gt; | 返回所有激活的有线网络接口名称数组。 |

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
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: Array<string> = networkManager.getAllNetworkInterfacesSync(wantTemp);
  console.info(`Succeeded in getting all network interfaces, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get all network interfaces. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.getIpAddressSync

getIpAddressSync(admin: Want, networkInterface: string): string

根据网络接口获取设备IP地址。适用于企业网络管理场景，例如网络审计、设备定位、网络连接问题排查、IP地址分配管理，帮助企业IT管理员了解设备网络配置，便于网络管理和故障诊断。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名           | 类型                                                    | 必填 | 说明           |
| ---------------- | ------------------------------------------------------- | ---- | -------------- |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| networkInterface | string                                                  | 是   | 指定网络接口。 |

**返回值：**

| 类型   | 说明             |
| ------ | ---------------- |
| string | 返回设备指定网络接口的IP地址。 |

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
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // 参数需根据实际情况进行替换
  let result: string = networkManager.getIpAddressSync(wantTemp, 'eth0');
  console.info(`Succeeded in getting ip address, result : ${result}`);
} catch (err) {
  console.error(`Failed to get ip address. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.getMacSync

getMacSync(admin: Want, networkInterface: string): string

根据网络接口获取设备MAC地址。适用于企业网络管理场景，例如设备识别、网络准入控制、MAC地址审计、设备资产管理，帮助企业识别和追踪设备，实现精细化的网络访问控制。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名           | 类型                                                    | 必填 | 说明           |
| ---------------- | ------------------------------------------------------- | ---- | -------------- |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| networkInterface | string                                                  | 是   | 指定网络接口。 |

**返回值：**

| 类型   | 说明              |
| ------ | ----------------- |
| string | 返回设备指定网络接口的MAC地址。 |

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
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // 参数需根据实际情况进行替换
  let result: string = networkManager.getMacSync(wantTemp, 'eth0');
  console.info(`Succeeded in getting mac, result : ${result}`);
} catch (err) {
  console.error(`Failed to get mac. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.isNetworkInterfaceDisabledSync

isNetworkInterfaceDisabledSync(admin: Want | null, networkInterface: string): boolean

查询指定网络接口是否被禁用。适用于企业网络管理场景，例如检查网络接口状态、审计网络接口使用情况、验证网络策略执行效果，帮助企业确认网络接口管理策略是否生效，便于策略调整和问题排查。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名           | 类型                                                    | 必填 | 说明           |
| ---------------- | ------------------------------------------------------- | ---- | -------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。<br>当设备存在多个MDM应用时，API版本26.0.0之前，传入Want时查询对应企业设备管理应用设置的策略。从API版本26.0.0开始，新增支持传入null时查询实际生效的策略。|
| networkInterface | string                                                  | 是   | 指定网络接口。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回指定网络接口是否被禁用，true表示该网络接口被禁用，false表示该网络接口未被禁用。 |

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
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // 参数需根据实际情况进行替换
  let result: boolean = networkManager.isNetworkInterfaceDisabledSync(wantTemp, 'eth0');
  console.info(`Succeeded in querying network interface is disabled or not, result : ${result}`);
} catch (err) {
  console.error(`Failed to query network interface is disabled or not. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.setNetworkInterfaceDisabledSync

setNetworkInterfaceDisabledSync(admin: Want, networkInterface: string, isDisabled: boolean): void

禁止设备使用指定网络接口。适用于企业网络安全管控场景，例如禁用高风险网络接口、限制设备使用特定网络连接、防止通过网络接口进行数据泄露，帮助企业降低网络安全风险，防止通过特定网络接口进行的攻击或数据外泄。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [从严管控](../../mdm/mdm-kit-multi-mdm.md#规则1从严管控)。

**参数：**

| 参数名           | 类型                                                    | 必填 | 说明                                              |
| ---------------- | ------------------------------------------------------- | ---- | ------------------------------------------------- |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                            |
| networkInterface | string                                                  | 是   | 指定网络接口。                                    |
| isDisabled       | boolean                                                 | 是   | true表示禁用该网络接口，false表示开启该网络接口。 |

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
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // 参数需根据实际情况进行替换
  networkManager.setNetworkInterfaceDisabledSync(wantTemp, 'eth0', true);
  console.info(`Succeeded in setting network interface disabled`);
} catch (err) {
  console.error(`Failed to set network interface disabled. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.setGlobalProxySync

setGlobalProxySync(admin: Want, httpProxy: connection.HttpProxy): void

设置网络全局代理。适用于企业网络管理场景，例如设置企业统一的网络代理、实现网络访问审计、控制网络访问路径、优化网络性能，帮助企业集中管理网络访问，实现网络访问的可审计和可控制。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名    | 类型                                                         | 必填 | 说明                       |
| --------- | ------------------------------------------------------------ | ---- | -------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。             |
| httpProxy | [connection.HttpProxy](../apis-network-kit/js-apis-net-connection.md#httpproxy10) | 是   | 网络全局Http代理配置信息。 |

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
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { connection } from '@kit.NetworkKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// 需根据实际情况进行替换
let exclusionStr: string = "192.168,baidu.com";
let exclusionArray: Array<string> = exclusionStr.split(',');
let httpProxy: connection.HttpProxy = {
  host: "192.168.xx.xxx",
  port: 8080,
  exclusionList: exclusionArray
};

try {
  networkManager.setGlobalProxySync(wantTemp, httpProxy);
  console.info(`Succeeded in setting network global proxy.`);
} catch (err) {
  console.error(`Failed to set network global proxy. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.setGlobalProxyForAccount<sup>15+</sup>

setGlobalProxyForAccount(admin: Want, httpProxy: connection.HttpProxy, accountId: number): void

设置指定用户下的网络代理。适用于企业多用户环境下的网络管理场景，例如为不同用户设置不同的网络代理策略、实现用户级网络访问控制、满足不同用户的网络访问需求，帮助企业实现精细化的用户级网络管理。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在PC/2in1设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名    | 类型                                                         | 必填 | 说明                       |
| --------- | ------------------------------------------------------------ | ---- | -------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。             |
| httpProxy | [connection.HttpProxy](../apis-network-kit/js-apis-net-connection.md#httpproxy10) | 是   | 网络代理配置信息。 |
| accountId | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。|

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { connection } from '@kit.NetworkKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let httpProxy: connection.HttpProxy = {
  // 需根据实际情况进行替换
  host: '192.168.xx.xxx',
  port: 8080,
  exclusionList: ['192.168', 'baidu.com']
};

try {
  // 参数需根据实际情况进行替换
  networkManager.setGlobalProxyForAccount(wantTemp, httpProxy, 100);
  console.info(`Succeeded in setting network global proxy.`);
} catch (err) {
  console.error(`Failed to set network global proxy. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.getGlobalProxySync

getGlobalProxySync(admin: Want): connection.HttpProxy

获取网络全局代理。适用于企业网络管理场景，例如审计当前网络代理配置、验证代理策略是否生效、排查网络访问问题，帮助企业检查网络代理设置，确保网络访问策略正确执行。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |

**返回值：**

| 类型                                                         | 说明                           |
| ------------------------------------------------------------ | ------------------------------ |
| [connection.HttpProxy](../apis-network-kit/js-apis-net-connection.md#httpproxy10) | 返回网络全局HTTP代理配置信息。 |

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
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { connection } from '@kit.NetworkKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: connection.HttpProxy = networkManager.getGlobalProxySync(wantTemp);
  console.info(`Succeeded in getting network global proxy, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get network global proxy. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.getGlobalProxyForAccount<sup>15+</sup>

getGlobalProxyForAccount(admin: Want | null, accountId: number): connection.HttpProxy

获取指定用户下的网络代理。适用于企业多用户环境下的网络管理场景，例如审计用户级网络代理配置、验证用户网络访问策略、排查用户网络访问问题，帮助企业检查和验证用户级网络管理策略。

> **说明：**
>
> 本接口用于获取通过setGlobalProxyForAccount设置的、指定用户的代理配置。如果需要获取应用于所有用户的全局代理配置，建议使用[getGlobalProxySync](#networkmanagergetglobalproxysync)接口。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**设备行为差异：** 该接口在PC/2in1设备中可正常调用，在其他设备中返回801错误码。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| accountId | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。|

**返回值：**

| 类型                                                         | 说明                           |
| ------------------------------------------------------------ | ------------------------------ |
| [connection.HttpProxy](../apis-network-kit/js-apis-net-connection.md#httpproxy10) | 网络代理配置信息。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. <br>适用版本：20+ |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { connection } from '@kit.NetworkKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // 参数需根据实际情况进行替换
  let result: connection.HttpProxy = networkManager.getGlobalProxyForAccount(wantTemp, 100);
  console.info(`Succeeded in getting network global proxy, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get network global proxy. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.addFirewallRule

addFirewallRule(admin: Want, firewallRule: FirewallRule): void

为设备添加防火墙过滤规则。<!--RP3--><!--RP3End-->适用于企业网络安全管控场景，例如限制特定IP地址的网络访问、防止恶意网络攻击、控制应用程序的网络通信、实现网络访问的允许名单或禁用名单管理，帮助企业精细化控制网络访问，防止网络攻击和数据泄露。

API version 21及之前版本，仅支持IPv4。从API version 22开始，支持IPv4和IPv6。

从API version 23开始，支持[LogType](#logtype23)。

> **说明：**
>
> - 添加了[Action](#action)为ALLOW规则后，将会默认添加DENY规则，不在ALLOW规则之内的网络数据包将会被丢弃或拦截。
> - 设备重启，将会清空防火墙过滤规则。
> - 规则匹配顺序：先匹配域名过滤规则（由[addDomainFilterRule](#networkmanageradddomainfilterrule)添加），再匹配本接口添加的IP防火墙规则；在域名规则或IP规则中，均按[Action](#action)为ALLOW、DENY、REJECT的顺序进行匹配。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                 |
| ------------ | ------------------------------------------------------- | ---- | -------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。       |
| firewallRule | [FirewallRule](#firewallrule)                           | 是   | 添加防火墙过滤规则。 |

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
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let firewallRule: networkManager.FirewallRule = {
  // 需根据实际情况进行替换
  "srcAddr": "192.168.1.1-192.168.22.66",
  "destAddr": "10.1.1.1",
  "srcPort": "8080",
  "destPort": "8080",
  "appUid": "9696",
  "direction": networkManager.Direction.OUTPUT,
  "action": networkManager.Action.DENY,
  "protocol": networkManager.Protocol.UDP,
  "family": 1,
  "logType": networkManager.LogType.NFLOG
};

try {
  networkManager.addFirewallRule(wantTemp, firewallRule);
  console.info('Succeeded in adding firewall rule.');
} catch (err) {
  console.error(`Failed to add firewall rule. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.removeFirewallRule

removeFirewallRule(admin: Want, firewallRule?: FirewallRule): void

移除设备防火墙过滤规则。适用于企业网络安全策略调整场景，例如取消某些网络访问限制、调整防火墙策略、清理过时或无效的规则，帮助企业灵活调整网络安全策略，确保网络访问控制策略与实际需求保持一致。

API version 21及之前版本，仅支持IPv4。从API version 22开始，支持IPv4和IPv6。

从API version 23开始，支持[LogType](#logtype23)。

移除规则后如果不存在[Action](#action)为ALLOW规则后，会将[addFirewallRule](#networkmanageraddfirewallrule)添加的默认DENY规则清空。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                                                 |
| ------------ | ------------------------------------------------------- | ---- | ---------------------------------------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                       |
| firewallRule | [FirewallRule](#firewallrule)                           | 否   | 移除防火墙过滤规则。值为空时，清空所有的防火墙规则。 |

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
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let firewallRule: networkManager.FirewallRule = {
  // 需根据实际情况进行替换
  "srcAddr": "192.168.1.1-192.168.22.66",
  "destAddr": "10.1.1.1",
  "srcPort": "8080",
  "destPort": "8080",
  "appUid": "9696",
  "direction": networkManager.Direction.OUTPUT,
  "action": networkManager.Action.DENY,
  "protocol": networkManager.Protocol.UDP,
  "family": 1,
  "logType": networkManager.LogType.NFLOG
};

// 移除指定的规则
try {
  networkManager.removeFirewallRule(wantTemp, firewallRule);
  console.info('Succeeded in removing firewall rule.');
} catch (err) {
  console.error(`Failed to remove firewall rule. Code: ${err.code}, message: ${err.message}`);
}

// 清空IP协议版本为IPv4的所有规则
try {
  networkManager.removeFirewallRule(wantTemp);
  console.info('Succeeded in removing all firewall rule.');
} catch (err) {
  console.error(`Failed to remove all firewall rule. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.getFirewallRules

getFirewallRules(admin: Want): Array\<FirewallRule>

查询设备防火墙过滤规则。适用于企业网络安全审计场景，例如检查当前防火墙策略配置、审计网络访问控制规则、验证防火墙规则是否正确执行、排查网络访问问题，帮助企业审核和验证网络安全策略，确保网络访问控制符合安全要求。

API version 21及之前版本，仅支持IPv4。从API version 22开始，支持IPv4和IPv6。

从API version 23开始，支持[LogType](#logtype23)。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |

**返回值：**

| 类型                                  | 说明                                                         |
| ------------------------------------- | ------------------------------------------------------------ |
| Array\<[FirewallRule](#firewallrule)> | 返回当前设备配置的防火墙过滤规则列表，当方法调用错误时会抛出异常。 |

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
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let firewallRule: Array<networkManager.FirewallRule>;
try {
  firewallRule = networkManager.getFirewallRules(wantTemp);
  console.info('Succeeded in getting firewall rules');
} catch (err) {
  console.error(`Failed to get firewall rules. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.addDomainFilterRule

addDomainFilterRule(admin: Want, domainFilterRule: DomainFilterRule): void

为设备添加域名过滤规则。<!--RP3--><!--RP3End-->

API version 21及之前版本，仅支持IPv4。从API version 22开始，支持IPv4和IPv6。

从API version 23开始，支持[LogType](#logtype23)。

> **说明：**
>
> - 添加[Action](#action)为ALLOW规则后会自动添加默认DENY规则，不在ALLOW规则之内的域名解析数据包将被丢弃或拦截。
> - 添加的规则在设备重启后会被清空。
> - 为避免DNS缓存导致拦截规则失效，建议系统启动后立即配置域名过滤规则。若已因DNS缓存导致拦截失效，重启系统可清除缓存，恢复拦截功能。
> - 规则匹配顺序：先匹配本接口添加的域名过滤规则，再匹配IP防火墙规则（由[addFirewallRule](#networkmanageraddfirewallrule)添加）；在域名规则或IP规则中，均按[Action](#action)为ALLOW、DENY、REJECT的顺序进行匹配。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名           | 类型                                                    | 必填 | 说明               |
| ---------------- | ------------------------------------------------------- | ---- | ------------------ |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。     |
| domainFilterRule | [DomainFilterRule](#domainfilterrule)                   | 是   | 域名过滤规则对象，包含域名、应用UID、IP协议版本等配置项。 |

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
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let domainFilterRule: networkManager.DomainFilterRule = {
  // 需根据实际情况进行替换
  "domainName": "www.example.com",
  "appUid": "9696",
  "action": networkManager.Action.DENY,
  "family": 1,
  "logType": networkManager.LogType.NFLOG
};

try {
  networkManager.addDomainFilterRule(wantTemp, domainFilterRule);
  console.info('Succeeded in adding domain filter rules');
} catch (err) {
  console.error(`Failed to add domain filter rules. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.removeDomainFilterRule

removeDomainFilterRule(admin: Want, domainFilterRule?: DomainFilterRule): void

移除设备域名过滤规则。适用于企业网络安全策略调整场景，例如取消某些域名访问限制、调整域名过滤策略、清理过时或无效的规则、解决误拦截问题，帮助企业灵活调整域名访问策略，确保网络访问控制策略符合实际需求。

API version 21及之前版本，仅支持IPv4。从API version 22开始，支持IPv4和IPv6。

从API version 23开始，支持[LogType](#logtype23)。

移除规则后如果不存在[Action](#action)为ALLOW规则后，会将[addDomainFilterRule](#networkmanageradddomainfilterrule)添加的默认DENY规则清空。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名           | 类型                                                    | 必填 | 说明                                             |
| ---------------- | ------------------------------------------------------- | ---- | ------------------------------------------------ |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。                                   |
| domainFilterRule | [DomainFilterRule](#domainfilterrule)                   | 否   | 移除域名过滤规则。值为空时，清空所有的域名规则。 |

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
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let domainFilterRule: networkManager.DomainFilterRule = {
  // 需根据实际情况进行替换
  "domainName": "www.example.com",
  "appUid": "9696",
  "action": networkManager.Action.DENY,
  "family": 1,
  "logType": networkManager.LogType.NFLOG
};

// 移除指定的规则
try {
  networkManager.removeDomainFilterRule(wantTemp, domainFilterRule);
  console.info('Succeeded in removing domain filter rules');
} catch (err) {
  console.error(`Failed to remove domain filter rules. Code: ${err.code}, message: ${err.message}`);
}

// 清空IP协议版本为IPv4的所有规则
try {
  networkManager.removeDomainFilterRule(wantTemp);
  console.info('Succeeded in removing all domain filter rules');
} catch (err) {
  console.error(`Failed to remove all domain filter rules. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.getDomainFilterRules

getDomainFilterRules(admin: Want): Array\<DomainFilterRule>

查询设备域名过滤规则。适用于企业网络安全审计场景，例如检查当前域名过滤策略配置、审计域名访问控制规则、验证域名过滤规则是否正确执行、排查域名访问问题，帮助企业审核和验证域名访问控制策略，确保网络访问控制符合安全要求。

API version 21及之前版本，仅支持IPv4。从API version 22开始，支持IPv4和IPv6。

从API version 23开始，支持[LogType](#logtype23)。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |

**返回值：**

| 类型                                          | 说明                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| Array\<[DomainFilterRule](#domainfilterrule)> | 返回当前设备配置的域名过滤规则列表，当方法调用错误时会抛出异常。 |

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
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let domainFilterRule: Array<networkManager.DomainFilterRule>;
try {
  domainFilterRule = networkManager.getDomainFilterRules(wantTemp);
  console.info('Succeeded in getting domain filter rules');
} catch (err) {
  console.error(`Failed to get domain filter rules. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.turnOnMobileData<sup>20+</sup>

turnOnMobileData(admin: Want, isForce: boolean): void

开启移动数据网络。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** 任意MDM应用通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口禁用了移动数据网络，则无法通过本接口直接开启移动数据网络。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| isForce  | boolean | 是   | 是否强制打开移动数据网络。true表示强制开启，强制开启后不支持用户在设备上手动关闭，必须采用[turnOffMobileData](#networkmanagerturnoffmobiledata20)接口关闭。false表示非强制开启，此时用户可以在设备上手动操作关闭移动数据网络。适用于企业网络安全管控场景，例如防止通过移动数据网络进行数据泄露、控制网络连接方式、降低通信成本、确保设备仅使用企业网络，帮助企业控制设备网络访问方式，防止通过移动数据网络的安全风险和数据外泄。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  networkManager.turnOnMobileData(wantTemp, true);
  console.info(`Turn on mobile data succeeded`);
} catch (err) {
  console.error(`Failed to turn on mobile data. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.turnOffMobileData<sup>20+</sup>

turnOffMobileData(admin: Want): void

关闭移动数据网络。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** 任意MDM应用通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated)接口禁用了移动数据网络，则无法通过本接口直接关闭移动数据网络。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { networkManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  networkManager.turnOffMobileData(wantTemp);
  console.info(`Turn off mobile data succeeded`);
} catch (err) {
  console.error(`Failed to turn off mobile data. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.addApn<sup>20+</sup>

addApn(admin: Want, apnInfo: Record\<string, string>): void

添加APN（Access Point Name，接入点名称）。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| apnInfo  | Record\<string, string> | 是   | 需要添加的APN参数信息。设置后系统将使用这些参数配置移动数据网络的接入点，影响网络连接方式和数据传输路径。<br/>- apnName：APN配置的名称标识符，必选。<br/>- mcc：3位数字的移动国家代码，必选。<br/>- mnc：2-3位数字的移动网络代码，必选。<br/>- apn：接入点名称，必选。<br/>- type：APN的服务类型，可选。<br/>- user：APN身份验证的用户名，可选。<br/>- password：APN身份验证的密码，可选。<br/>- proxy：普通数据连接的代理服务器地址，可选。<br/>- mmsproxy：彩信服务的专用代理地址，可选。<br/>- authType：APN的认证协议类型，可选。 |

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
import { networkManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};
let apnInfo: Record<string, string> = {
  // 需根据实际情况进行替换
  "apnName": "CTNET",
  "apn": "CTNET",
  "mnc": "11",
  "mcc": "460",
};
try {
  networkManager.addApn(wantTemp, apnInfo);
  console.info(`Succeeded in adding apn.`);
} catch (err) {
  console.error(`Failed to add apn. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.deleteApn<sup>20+</sup>

deleteApn(admin: Want, apnId: string): void

删除APN。适用于企业移动网络配置管理场景，例如清理无效的APN配置、调整移动网络接入点配置、防止使用错误的APN配置，帮助企业维护正确的移动网络配置，确保设备使用正确的接入点连接移动网络。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| apnId  | string | 是   | 需要删除的APN ID。设置后系统将移除该APN配置，对应的接入点将不再可用。可以通过[networkManager.queryApn](#networkmanagerqueryapn20)获取设备APN信息。 |

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
import { networkManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};
let apnId: string = "1"; // 需根据实际情况进行替换
try {
  networkManager.deleteApn(wantTemp, apnId);
  console.info(`Succeeded in deleting apn.`);
} catch (err) {
  console.error(`Failed to delete apn. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.updateApn<sup>20+</sup>

updateApn(admin: Want, apnInfo: Record\<string, string>, apnId: string): void

更新APN。适用于企业移动网络配置管理场景，例如修改APN配置参数、调整运营商设置、优化移动网络连接性能，帮助企业灵活调整移动网络配置，确保设备移动网络连接参数符合实际需求。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| apnInfo  | Record\<string, string> | 是   | 需要更新的APN参数信息。设置后系统将使用更新后的参数修改对应APN配置，影响网络连接方式和数据传输路径。<br/>- apnName：APN配置的名称标识符，可选。<br/>- mcc：3位数字的移动国家代码，可选。<br/>- mnc：2-3位数字的移动网络代码，可选。<br/>- APN：接入点名称，可选。<br/>- type：APN的服务类型，可选。<br/>- user：APN身份验证的用户名，可选。<br/>- password：APN身份验证的密码，可选。<br/>- proxy：普通数据连接的代理服务器地址，可选。<br/>- mmsproxy：彩信服务的专用代理地址，可选。<br/>- authType：APN的认证协议类型，可选。 |
| apnId  | string | 是   | 需要更新的APN ID。可以通过[networkManager.queryApn](#networkmanagerqueryapn20)获取设备APN信息。 |

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
import { networkManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};
let apnInfo: Record<string, string> = {
  // 需根据实际情况进行替换
  "apnName": "CTNET",
  "apn": "CTNET",
  "mnc": "11",
  "mcc": "460",
};
let apnId: string = "1"; // 需根据实际情况进行替换
try {
  networkManager.updateApn(wantTemp, apnInfo, apnId);
  console.info(`Succeeded in updating apn.`);
} catch (err) {
  console.error(`Failed to update apn. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.setPreferredApn<sup>20+</sup>

setPreferredApn(admin: Want, apnId: string): void

设置优选APN。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| apnId  | string | 是   | 需要设置成优选的APN ID。可以通过[networkManager.queryApn](#networkmanagerqueryapn20)获取设备APN信息。 |

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
import { networkManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};
let apnId: string = "1"; // 需根据实际情况进行替换
try {
  networkManager.setPreferredApn(wantTemp, apnId);
  console.info(`Succeeded in setting preferred apn.`);
} catch (err) {
  console.error(`Failed to set preferred apn. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.queryApn<sup>20+</sup>

queryApn(admin: Want, apnInfo: Record\<string, string>): Array\<string>

查询符合特定APN信息的APN ID。适用于企业移动网络配置审计场景，例如查找特定配置的APN、验证APN配置是否存在、为APN管理操作提供APN ID参数，帮助企业查找和管理APN配置，为APN的更新和删除操作提供必要的参数信息。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| apnInfo  | Record\<string, string> | 是   | APN的查询条件。设置后系统将根据这些条件筛选匹配的APN配置，返回符合条件的APN ID列表。<br/>- apnName：APN配置的名称标识符，可选。<br/>- mcc：3位数字的移动国家代码，可选。<br/>- mnc：2-3位数字的移动网络代码，可选。<br/>- apn：接入点名称，可选。<br/>- type：APN的服务类型，可选。<br/>- user：APN身份验证的用户名，可选。<br/>- proxy：普通数据连接的代理服务器地址，可选。<br/>- mmsproxy：彩信服务的专用代理地址，可选。<br/>- authType：APN的认证协议类型，可选。 |

**返回值：**

| 类型                                          | 说明                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| Array\<string> | 满足要求的APN ID。 |

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
import { networkManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};
let apnInfo: Record<string, string> = {
  // 需根据实际情况进行替换
  "apnName": "CTNET",
  "apn": "CTNET",
  "mnc": "11",
  "mcc": "460",
};
try {
  let queryResult: Array<string> = networkManager.queryApn(wantTemp, apnInfo);
  console.info(`Succeeded in querying apn, result : ${JSON.stringify(queryResult)}`);
} catch (err) {
  console.error(`Failed to query apn. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.queryApn<sup>20+</sup>

queryApn(admin: Want, apnId: string): Record\<string, string>

查询特定APN的APN参数信息。适用于企业移动网络配置审计场景，例如检查特定APN的配置参数、验证APN配置是否正确、审计移动网络接入点配置，帮助企业审核和验证APN配置，确保移动网络配置符合要求。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_APN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| apnId  | string | 是   | 指定的APN ID。设置后将查询该APN ID对应的详细参数配置信息。可以通过[networkManager.queryApn](#networkmanagerqueryapn20)获取设备信息。 |

**返回值：**

| 类型                                          | 说明                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| Record\<string, string> | 指定APN ID的APN参数信息。<br/>- apnName：APN配置的名称标识符。<br/>- mcc：3位数字的移动国家代码。<br/>- mnc：2-3位数字的移动网络代码。<br/>- apn：接入点名称。<br/>- type：APN的服务类型。<br/>- user：APN身份验证的用户名。<br/>- proxy：普通数据连接的代理服务器地址。<br/>- mmsproxy：彩信服务的专用代理地址。<br/>- authType：APN的认证协议类型。 |

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
import { networkManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};
let apnId: string = "1"; // 需根据实际情况进行替换
try {
  let queryResult: Record<string, string> = networkManager.queryApn(wantTemp, apnId);
  console.info(`Succeeded in querying apn, result : ${JSON.stringify(queryResult)}`);
} catch (err) {
  console.error(`Failed to query apn. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.setEthernetConfig<sup>23+</sup>

setEthernetConfig(admin: Want, networkInterface: string, config: InterfaceConfig): void

设置特定以太网网络接口的IP地址。适用于企业网络管理场景，例如配置设备静态IP地址、统一管理企业网络设备IP分配、设置网络参数，帮助企业集中管理网络配置，确保设备网络参数符合企业网络管理策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**冲突规则：** [配置](../../mdm/mdm-kit-multi-mdm.md#规则3配置)。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。Want中必须包含企业设备管理扩展能力的abilityName和所在应用的bundleName。 |
| networkInterface  | string | 是   | 要设置的网络接口名。 |
| config  | [InterfaceConfig](#interfaceconfig23) | 是   | 要设置的网络接口配置信息。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 9201010  | Ethernet configuration failed. Ethernet device not connected. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { networkManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility',
};
let config: networkManager.InterfaceConfig = {
  // 需根据实际情况进行替换
  "ipSetMode": networkManager.IpSetMode.STATIC,
  "ipAddress": "192.168.1.121",
  "gateway": "192.168.1.1",
  "netMask": "255.255.255.0",
  "dnsServers": "192.168.1.1"
}
let networkInterface: string = "eth0"; // 需根据实际情况进行替换
try {
  networkManager.setEthernetConfig(wantTemp, networkInterface, config);
  console.info('Succeeded in setting ethernet config.');
} catch (err) {
  console.error(`Failed to set ethernet config. Code: ${err.code}, message: ${err.message}`);
}
```

## FirewallRule

防火墙过滤规则。

API version 21及之前版本，仅支持IPv4。从API version 22开始，支持IPv4和IPv6。

从API version 23开始，支持[LogType](#logtype23)。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


| 名称      | 类型                    | 只读 | 可选 | 说明                                                         |
| --------- | ----------------------- | ---- | ---- |------------------------------------------------------------ |
| srcAddr   | string                  | 否   | 是 |ip源地址。支持IP段，例如：192.168.0.0/22或者192.168.1.100-192.168.1.200 |
| destAddr  | string                  | 否   | 是 |ip目标地址。支持IP段，例如：192.168.0.0/22或者192.168.1.100-192.168.1.200 |
| srcPort   | string                  | 否   | 是 |源端口。                                                     |
| destPort  | string                  | 否   | 是 |目标端口。                                                   |
| appUid    | string                  | 否   | 是 |应用uid。                                                    |
| direction | [Direction](#direction) | 否   | 是 |规则链。<br/>添加防火墙过滤规则时必填；<br/>移除防火墙时非必填，当值为空时，表示清空所有的[Direction](#direction)链，且srcAddr，destAddr，srcPort，destPort，appUid也必须传入空值。 |
| action    | [Action](#action)       | 否   | 是 |接收或者丢弃数据包。<br/>添加防火墙过滤规则时必填；<br/>移除防火墙时非必填，当值为空时，表示清空所有的匹配[Action](#action)规则的链，且srcAddr，destAddr，srcPort，destPort，appUid也必须传入空值。 |
| protocol  | [Protocol](#protocol)   | 否   | 是 |网络协议。当值为ALL或者ICMP时，设置srcPort与destPort无效。 |
| family<sup>22+</sup>    | number    | 否   | 是 |IP协议版本。支持取值为1或2，取值为1表示IPv4，取值为2表示IPv6。|
| logType<sup>23+</sup> | [LogType](#logtype23) | 否 | 是 |日志类型，当前仅支持配置NFLOG类型，该参数仅支持PC/2in1设备。<br/>添加防火墙过滤规则时，此参数非必填。若填写，仅在丢弃或拒绝数据包时生效。<!--RP1--><!--RP1End--><br/>移除防火墙过滤规则时，当清空某条链时非必填，不影响整条链的清空；当移除单条规则时，是否填写必须与该规则一致，否则可能导致过滤规则已经移除，但是日志还在记录的问题；相同过滤规则移除时必须按添加时的顺序移除。<br/>获取防火墙过滤规则时，仅日志生效的场景可以获取到logType字段。|

## DomainFilterRule

域名过滤规则。

API version 21及之前版本，仅支持IPv4。从API version 22开始，支持IPv4和IPv6。

从API version 23开始，支持[LogType](#logtype23)。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


| 名称       | 类型              | 只读 | 可选 | 说明                                                         |
| ---------- | ----------------- | ---- | ---- | ------------------------------------------------------------ |
| domainName | string            | 否   | 是 |域名。添加域名过滤规则时必填。支持域名分段匹配，例如，domainName传入`example.com`，那么`example.com`、`www.example.com`、`www.test.example.com`会被匹配，`linkexample.com`不会被匹配。                               |
| appUid     | string            | 否   | 是 |应用uid。                                                    |
| action     | [Action](#action) | 否   | 是 |接收或者丢弃数据包。<br/>添加域名过滤规则时必填；<br/>移除域名过滤规则时非必填，当值为空时，表示清空所有的匹配[Action](#action)规则的链，且domainName，appUid也必须传入空值。 |
| direction<sup>15+</sup> | [Direction](#direction) | 否 | 是 |规则链。<br/>添加域名过滤规则时非必填；当值为空，以及设为输出链或输入链时，实际效果为输出链。设为转发链时，appUid需设置为空，否则会报401错误码。<br/>移除域名过滤规则时非必填，当值为空时，表示清空所有的[Direction](#direction)链，且domainName，appUid也必须传入空值。|
| family<sup>22+</sup>    | number| 否   | 是 |IP协议版本。支持取值为1或2，取值为1表示IPv4，取值为2表示IPv6。|
| logType<sup>23+</sup> | [LogType](#logtype23) | 否 | 是 |日志类型，当前仅支持配置NFLOG类型，该参数仅支持PC/2in1设备。<br/>添加域名过滤规则时，此参数非必填。若填写，仅在丢弃或拒绝数据包时生效。<!--RP2--><!--RP2End--><br/>移除域名过滤规则时，当清空某条链时非必填，不影响整条链的清空；当移除单条规则时，是否填写必须与该规则一致，否则可能导致过滤规则已经移除，但是日志还在记录的问题；相同过滤规则移除时必须按添加时的顺序移除。<br/>获取域名过滤规则时，仅日志生效的场景可以获取到logType字段。|

## Direction

规则链。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


| 名称   | 值   | 说明     |
| ------ | ---- | -------- |
| INPUT  | 0    | 输入链。 |
| OUTPUT | 1    | 输出链。 |
| FORWARD<sup>15+</sup> | 2   | 转发链。  |

## Action

数据包的行为。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


| 名称  | 值   | 说明         |
| ----- | ---- | ------------ |
| ALLOW | 0    | 接收数据包。 |
| DENY  | 1    | 丢弃数据包。 |
| REJECT<sup>15+</sup> | 2 | 拒绝数据包。 |

## Protocol

网络协议。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


| 名称 | 值   | 说明           |
| ---- | ---- | -------------- |
| ALL  | 0    | 全部网络协议。 |
| TCP  | 1    | 网络协议TCP。  |
| UDP  | 2    | 网络协议UDP。  |
| ICMP | 3    | 网络协议ICMP。 |

## LogType<sup>23+</sup>

日志类型。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


| 名称  | 值   | 说明                                  |
| ----- | ---- | ------------------------------------- |
| NFLOG | 0    | 内核Netfilter框架中的数据包日志功能。 |

## InterfaceConfig<sup>23+</sup>

以太网的网络接口配置。仅支持IPv4。<br/>

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


| 名称      | 类型                    | 只读 | 可选 | 说明                                                         |
| --------- | ----------------------- | ---- | ---- |------------------------------------------------------------ |
| ipSetMode   | [IpSetMode](#ipsetmode23)                  | 否   | 否 |以太网连接配置模式。 |
| ipAddress  | string                  | 否   | 是 |静态IP地址，地址值范围0.0.0.0到255.255.255.255（DHCP模式无需配置）。 |
| gateway  | string                  | 否   | 是 |网关，地址值范围0.0.0.0到255.255.255.255（DHCP模式无需配置）。 |
| netMask  | string                  | 否   | 是 |子网掩码，地址值范围0.0.0.0到255.255.255.255（DHCP模式无需配置）。 |
| dnsServers  | string                  | 否   | 是 |DNS服务地址，地址值范围0.0.0.0到255.255.255.255（DHCP模式无需配置），多地址间用“,”隔开。 |

## IpSetMode<sup>23+</sup>

以太网连接模式。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


| 名称 | 值   | 说明           |
| ---- | ---- | -------------- |
| STATIC  | 0    | 以太网连接静态配置网络信息，设置为该模式时，需要同步设置IP地址、子网掩码、默认网关、DNS服务器。 |
| DHCP  | 1    | 以太网连接动态配置网络信息，设置为该模式时，由网络中的DHCP服务器自动分配IP地址等信息。  |

