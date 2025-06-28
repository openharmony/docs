# @ohos.enterprise.networkManager（网络管理）

本模块提供设备网络管理能力，包括查询设备IP地址、MAC地址信息等。

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

获取所有激活的有线网络接口。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
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

根据网络接口获取设备IP地址。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名           | 类型                                                    | 必填 | 说明           |
| ---------------- | ------------------------------------------------------- | ---- | -------------- |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |
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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  let result: string = networkManager.getIpAddressSync(wantTemp, 'eth0');
  console.info(`Succeeded in getting ip address, result : ${result}`);
} catch (err) {
  console.error(`Failed to get ip address. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.getMacSync

getMacSync(admin: Want, networkInterface: string): string

根据网络接口获取设备MAC地址。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名           | 类型                                                    | 必填 | 说明           |
| ---------------- | ------------------------------------------------------- | ---- | -------------- |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |
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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  let result: string = networkManager.getMacSync(wantTemp, 'eth0');
  console.info(`Succeeded in getting mac, result : ${result}`);
} catch (err) {
  console.error(`Failed to get mac. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.isNetworkInterfaceDisabledSync

isNetworkInterfaceDisabledSync(admin: Want, networkInterface: string): boolean

查询指定网络接口是否被禁用。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名           | 类型                                                    | 必填 | 说明           |
| ---------------- | ------------------------------------------------------- | ---- | -------------- |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |
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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  let result: boolean = networkManager.isNetworkInterfaceDisabledSync(wantTemp, 'eth0');
  console.info(`Succeeded in querying network interface is disabled or not, result : ${result}`);
} catch (err) {
  console.error(`Failed to query network interface is disabled or not. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.setNetworkInterfaceDisabledSync

setNetworkInterfaceDisabledSync(admin: Want, networkInterface: string, isDisabled: boolean): void

禁止设备使用指定网络接口。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名           | 类型                                                    | 必填 | 说明                                              |
| ---------------- | ------------------------------------------------------- | ---- | ------------------------------------------------- |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                            |
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
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  networkManager.setNetworkInterfaceDisabledSync(wantTemp, 'eth0', true);
  console.info(`Succeeded in setting network interface disabled`);
} catch (err) {
  console.error(`Failed to set network interface disabled. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.setGlobalProxySync

setGlobalProxySync(admin: Want, httpProxy: connection.HttpProxy): void

设置网络全局代理。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名    | 类型                                                         | 必填 | 说明                       |
| --------- | ------------------------------------------------------------ | ---- | -------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是   | 企业设备管理扩展组件。             |
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
import { Want } from '@kit.AbilityKit';
import { connection } from '@kit.NetworkKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let exclusionStr: string = "192.168,baidu.com"
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

设置指定用户下的网络代理，当前仅支持2in1设备。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名    | 类型                                                         | 必填 | 说明                       |
| --------- | ------------------------------------------------------------ | ---- | -------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是   | 设备管理应用。             |
| accountId | number                                                  | 是   | 用户ID，取值范围：大于等于0。<br> accountId可以通过@ohos.account.osAccount中的[getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1)等接口来获取。|
| httpProxy | [connection.HttpProxy](../apis-network-kit/js-apis-net-connection.md#httpproxy10) | 是   | 网络代理配置信息。 |

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
import { connection } from '@kit.NetworkKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let httpProxy: connection.HttpProxy = {
  host: '192.168.xx.xxx',
  port: 8080,
  exclusionList: ['192.168', 'baidu.com']
};

try {
  networkManager.setGlobalProxyForAccount(wantTemp, httpProxy, 100);
  console.info(`Succeeded in setting network global proxy.`);
} catch (err) {
  console.error(`Failed to set network global proxy. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.getGlobalProxySync

getGlobalProxySync(admin: Want): connection.HttpProxy

获取网络全局代理。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

**返回值：**

| 类型                                                         | 说明                           |
| ------------------------------------------------------------ | ------------------------------ |
| [connection.HttpProxy](../apis-network-kit/js-apis-net-connection.md#httpproxy10) | 返回网络全局Http代理配置信息。 |

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
import { connection } from '@kit.NetworkKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  let result: connection.HttpProxy = networkManager.getGlobalProxySync(wantTemp);
  console.info(`Succeeded in getting network global proxy, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get network global proxy. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.getGlobalProxyForAccount<sup>15+</sup>

getGlobalProxyForAccount(admin: Want, accountId: number): connection.HttpProxy

获取指定用户下的网络代理，当前仅支持2in1设备。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。 |
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
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { connection } from '@kit.NetworkKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  let result: connection.HttpProxy = networkManager.getGlobalProxyForAccount(wantTemp, 100);
  console.info(`Succeeded in getting network global proxy, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get network global proxy. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.addFirewallRule

addFirewallRule(admin: Want, firewallRule: FirewallRule): void

为设备添加防火墙过滤规则，仅支持IPv4。<br/>
添加了[Action](#action)为ALLOW规则后，将会默认添加DENY规则，不在ALLOW规则之内的网络数据包将会被丢弃或拦截。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                 |
| ------------ | ------------------------------------------------------- | ---- | -------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。       |
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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let firewallRule: networkManager.FirewallRule = {
  "srcAddr": "192.168.1.1-192.188.22.66",
  "destAddr": "10.1.1.1",
  "srcPort": "8080",
  "destPort": "8080",
  "appUid": "9696",
  "direction": networkManager.Direction.OUTPUT,
  "action": networkManager.Action.DENY,
  "protocol": networkManager.Protocol.UDP,
}

networkManager.addFirewallRule(wantTemp, firewallRule);
```

## networkManager.removeFirewallRule

removeFirewallRule(admin: Want, firewallRule?: FirewallRule): void

移除设备防火墙过滤规则，仅支持IPv4。<br/>
移除规则后如果不存在[Action](#action)为ALLOW规则后，会将[addFirewallRule](#networkmanageraddfirewallrule)添加的默认DENY规则清空。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                                                 |
| ------------ | ------------------------------------------------------- | ---- | ---------------------------------------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                       |
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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
// 移除指定的规则
let firewallRule: networkManager.FirewallRule = {
  "srcAddr": "192.168.1.1-192.188.22.66",
  "destAddr": "10.1.1.1",
  "srcPort": "8080",
  "destPort": "8080",
  "appUid": "9696",
  "direction": networkManager.Direction.OUTPUT,
  "action": networkManager.Action.DENY,
  "protocol": networkManager.Protocol.UDP,
}
networkManager.removeFirewallRule(wantTemp, firewallRule);

// 清空所有规则
networkManager.removeFirewallRule(wantTemp);
```

## networkManager.getFirewallRules

getFirewallRules(admin: Want): Array\<FirewallRule>

查询设备防火墙过滤规则，仅支持IPv4。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let firewallRule: Array<networkManager.FirewallRule>;
firewallRule = networkManager.getFirewallRules(wantTemp);
```

## networkManager.addDomainFilterRule

addDomainFilterRule(admin: Want, domainFilterRule: DomainFilterRule): void

为设备添加域名过滤规则。<br/>
添加了[Action](#action)为ALLOW规则后，将会默认添加DENY规则，不在ALLOW规则之内的域名解析数据包将会被丢弃或拦截。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名           | 类型                                                    | 必填 | 说明               |
| ---------------- | ------------------------------------------------------- | ---- | ------------------ |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。     |
| domainFilterRule | [DomainFilterRule](#domainfilterrule)                   | 是   | 添加域名过滤规则。 |

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
let domainFilterRule: networkManager.DomainFilterRule = {
  "domainName": "www.example.com",
  "appUid": "9696",
  "action": networkManager.Action.DENY,
}

networkManager.addDomainFilterRule(wantTemp, domainFilterRule);
```

## networkManager.removeDomainFilterRule

removeDomainFilterRule(admin: Want, domainFilterRule?: DomainFilterRule): void

移除设备域名过滤规则。<br/>
移除规则后如果不存在[Action](#action)为ALLOW规则后，会将[addDomainFilterRule](#networkmanageradddomainfilterrule)添加的默认DENY规则清空。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名           | 类型                                                    | 必填 | 说明                                             |
| ---------------- | ------------------------------------------------------- | ---- | ------------------------------------------------ |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                   |
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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
// 移除指定的规则
let domainFilterRule: networkManager.DomainFilterRule = {
  "domainName": "www.example.com",
  "appUid": "9696",
  "action": networkManager.Action.DENY,
}
networkManager.removeDomainFilterRule(wantTemp, domainFilterRule);

// 清空所有规则
networkManager.removeDomainFilterRule(wantTemp);
```

## networkManager.getDomainFilterRules

getDomainFilterRules(admin: Want): Array\<DomainFilterRule>

查询设备域名过滤规则。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let domainFilterRule: Array<networkManager.DomainFilterRule>;
domainFilterRule = networkManager.getDomainFilterRules(wantTemp);
```

## networkManager.turnOnMobileData<sup>20+</sup>

turnOnMobileData(admin: Want, isForce: boolean): void

开启移动数据网络。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_NETWORK

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |
| isForce  | boolean | 是   | 是否强制打开移动数据网络。true表示强制开启，强制开启后不支持用户在设备上手动关闭，必须采用[turnOffMobileData](#networkmanagerturnoffmobiledata20)接口关闭。false表示非强制开启，此时用户可以在设备上手动操作关闭移动数据网络。 |

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
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
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


**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

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
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  networkManager.turnOffMobileData(wantTemp);
  console.info(`Turn off mobile data succeeded`);
} catch (err) {
  console.error(`Failed to turn off mobile data. Code: ${err.code}, message: ${err.message}`);
}
```

## FirewallRule

防火墙过滤规则。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


| 名称      | 类型                    | 必填 | 说明                                                         |
| --------- | ----------------------- | ---- | ------------------------------------------------------------ |
| srcAddr   | string                  | 否   | ip源地址。支持IP段，例如：192.168.0.0/22或者192.168.1.100-192.168.1.200 |
| destAddr  | string                  | 否   | ip目标地址。支持IP段，例如：192.168.0.0/22或者192.168.1.100-192.168.1.200 |
| srcPort   | string                  | 否   | 源端口。                                                     |
| destPort  | string                  | 否   | 目标端口。                                                   |
| appUid    | string                  | 否   | 应用uid。                                                    |
| direction | [Direction](#direction) | 否   | 规则链。<br/>添加防护墙过滤规则时必填；<br/>移除防火墙时非必填，当值为空时，表示清空所有的[Direction](#direction)链，且srcAddr，destAddr，srcPort，destPort，appUid也必须传入空值。 |
| action    | [Action](#action)       | 否   | 接收或者丢弃数据包。<br/>添加防护墙过滤规则时必填；<br/>移除防火墙时非必填，当值为空时，表示清空所有的匹配[Action](#action)规则的链，且srcAddr，destAddr，srcPort，destPort，appUid也必须传入空值。 |
| protocol  | [Protocol](#protocol)   | 否   | 网络协议。当值为ALL或者ICMP时，不允许设置srcPort与destPort。 |

## DomainFilterRule

域名过滤规则。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


| 名称       | 类型              | 必填 | 说明                                                         |
| ---------- | ----------------- | ---- | ------------------------------------------------------------ |
| domainName | string            | 否   | 域名。添加域名过滤规则时必填。                               |
| appUid     | string            | 否   | 应用uid。                                                    |
| action     | [Action](#action) | 否   | 接收或者丢弃数据包。<br/>添加域名过滤规则时必填；<br/>移除域名过滤规则时非必填，当值为空时，表示清空所有的匹配[Action](#action)规则的链，且domainName，appUid也必须传入空值。 |
| direction<sup>15+</sup> | [Direction](#direction) | 否 |规则链。<br/>添加防护墙过滤规则时必填；<br/>移除防火墙时非必填，当值为空时，表示清空所有的[Direction](#direction)链，且domainName，appUid也必须传入空值。|

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