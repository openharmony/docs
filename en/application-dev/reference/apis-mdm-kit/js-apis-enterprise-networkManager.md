# @ohos.enterprise.networkManager (Network Management)

The **networkManager** module provides APIs for network management of enterprise devices, including obtaining the device IP address and MAC address.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).
>

## Modules to Import

```ts
import { networkManager } from '@kit.MDMKit';
```

## networkManager.getAllNetworkInterfacesSync

getAllNetworkInterfacesSync(admin: Want): Array&lt;string&gt;

Obtains all activated wired network interfaces.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

**Return value**

| Type               | Description                  |
| ------------------- | ---------------------- |
| Array&lt;string&gt; | Names of all activated wired network interfaces.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Obtains the device IP address based on the network interface.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name          | Type                                                   | Mandatory| Description          |
| ---------------- | ------------------------------------------------------- | ---- | -------------- |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| networkInterface | string                                                  | Yes  | Network port.|

**Return value**

| Type  | Description            |
| ------ | ---------------- |
| string | IP address of the network interface specified by the device.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Obtains the MAC address of a device based on the network interface.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name          | Type                                                   | Mandatory| Description          |
| ---------------- | ------------------------------------------------------- | ---- | -------------- |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| networkInterface | string                                                  | Yes  | Network port.|

**Return value**

| Type  | Description             |
| ------ | ----------------- |
| string | MAC address of the network interface specified by the device.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Queries whether a specified network interface is disabled.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name          | Type                                                   | Mandatory| Description          |
| ---------------- | ------------------------------------------------------- | ---- | -------------- |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| networkInterface | string                                                  | Yes  | Network port.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the network port is disabled; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Disables the device from using the specified network interface.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name          | Type                                                   | Mandatory| Description                                             |
| ---------------- | ------------------------------------------------------- | ---- | ------------------------------------------------- |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                           |
| networkInterface | string                                                  | Yes  | Network port.                                   |
| isDisabled       | boolean                                                 | Yes  | Network port status to set. The value **true** means to disable the network port, and **false** means to enable the network port.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Sets the global network proxy.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name   | Type                                                        | Mandatory| Description                      |
| --------- | ------------------------------------------------------------ | ---- | -------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility.            |
| httpProxy | [connection.HttpProxy](../apis-network-kit/js-apis-net-connection.md#httpproxy10) | Yes  | Global HTTP proxy to set.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Sets the network proxy of a specified user. Currently, only 2-in-1 devices are supported.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name   | Type                                                        | Mandatory| Description                      |
| --------- | ------------------------------------------------------------ | ---- | -------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | Device administrator application.            |
| accountId | number                                                  | Yes  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of **@ohos.account.osAccount** to obtain the user ID.|
| httpProxy | [connection.HttpProxy](../apis-network-kit/js-apis-net-connection.md#httpproxy10) | Yes  | HTTP proxy configuration of the network.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Obtains the global network proxy.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

**Return value**

| Type                                                        | Description                          |
| ------------------------------------------------------------ | ------------------------------ |
| [connection.HttpProxy](../apis-network-kit/js-apis-net-connection.md#httpproxy10) | Global HTTP proxy configuration obtained.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Obtains the network proxy of a specified user. Currently, only 2-in-1 devices are supported.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.|
| accountId | number                                                  | Yes  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of **@ohos.account.osAccount** to obtain the user ID.|

**Return value**

| Type                                                        | Description                          |
| ------------------------------------------------------------ | ------------------------------ |
| [connection.HttpProxy](../apis-network-kit/js-apis-net-connection.md#httpproxy10) | HTTP proxy configuration of the network.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Adds firewall rules for the device. Only IPv4 is supported.<br>
After a rule with [Action](#action) set to **ALLOW** is added, a rule with **Action** set to **DENY** is added by default to discard or intercept all network data packets that do not meet the **ALLOW** rule.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name      | Type                                                   | Mandatory| Description                |
| ------------ | ------------------------------------------------------- | ---- | -------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.      |
| firewallRule | [FirewallRule](#firewallrule)                           | Yes  | Firewall rule to add.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Removes the firewall rules for the device. Only IPv4 is supported.<br>
If there is no rule with [Action](#action) being **ALLOW** after the rule is removed, the **DENY** rules that are added by default with [addFirewallRule](#networkmanageraddfirewallrule) will be removed.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                |
| ------------ | ------------------------------------------------------- | ---- | ---------------------------------------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                      |
| firewallRule | [FirewallRule](#firewallrule)                           | No  | Firewall rule to remove. If the value is empty, all firewall rules will be removed.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
// Remove the specified firewall rule.
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

// Remove all firewall rules.
networkManager.removeFirewallRule(wantTemp);
```

## networkManager.getFirewallRules

getFirewallRules(admin: Want): Array\<FirewallRule>

Queries firewall rules of a device. Only IPv4 is supported.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

**Return value**

| Type                                 | Description                                                        |
| ------------------------------------- | ------------------------------------------------------------ |
| Array\<[FirewallRule](#firewallrule)> | A list of firewall rules configured for the device is returned. If the operation fails, an exception will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Adds domain name filtering rules for the device.<br>
After a rule with [Action](#action) set to **ALLOW** is added, a rule with **Action** set to **DENY** is added by default to discard or intercept all packets for domain name resolution that do not meet the **ALLOW** rule.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name          | Type                                                   | Mandatory| Description              |
| ---------------- | ------------------------------------------------------- | ---- | ------------------ |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.    |
| domainFilterRule | [DomainFilterRule](#domainfilterrule)                   | Yes  | Domain name filtering rule to add.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Removes the domain name filtering rules.<br>
If there is no rule with [Action](#action) being **ALLOW** after the rule is removed, the **DENY** rules that are added by default with [addDomainFilterRule](#networkmanageradddomainfilterrule) will be removed.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name          | Type                                                   | Mandatory| Description                                            |
| ---------------- | ------------------------------------------------------- | ---- | ------------------------------------------------ |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                  |
| domainFilterRule | [DomainFilterRule](#domainfilterrule)                   | No  | Domain name filtering rule to remove. If the value is empty, all domain name filtering rules will be removed.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
// Remove the specified domain name filtering rule.
let domainFilterRule: networkManager.DomainFilterRule = {
  "domainName": "www.example.com",
  "appUid": "9696",
  "action": networkManager.Action.DENY,
}
networkManager.removeDomainFilterRule(wantTemp, domainFilterRule);

// Remove all domain name filtering rules.
networkManager.removeDomainFilterRule(wantTemp);
```

## networkManager.getDomainFilterRules

getDomainFilterRules(admin: Want): Array\<DomainFilterRule>

Queries domain name filtering rules.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

**Return value**

| Type                                         | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| Array\<[DomainFilterRule](#domainfilterrule)> | A list of domain name filtering rules configured for the device is returned. If the operation fails, an exception will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Turns on mobile data.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| isForce  | boolean | Yes  | Whether to forcibly enable mobile data. <br>The value **true** means to forcibly enable mobile data. Once enabled, it cannot be turned off manually; it can only be disabled via the [turnOffMobileData](#networkmanagerturnoffmobiledata20) API. The value **false** means not to forcibly enable mobile data. It can be turned off manually.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

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

Turns off mobile data.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

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

## networkManager.addApn<sup>20+</sup>

addApn(admin: Want, apnInfo: Record\<string, string>): void

Adds an access point name (APN).

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| apnInfo  | Record\<string, string> | Yes  | APN information to be added.<br>- **apnName**: APN identifier, which is mandatory.<br>- **mcc**: 3-digit mobile country code (MCC), which is mandatory.<br>- **mnc**: 2-digit or 3-digit mobile network code (MNC), which is mandatory.<br>- **apn**: access point name, which is mandatory.<br>- **type**: APN service type, which is optional.<br>- **user**: user name for APN authentication, which is optional.<br>- **password**: password for APN authentication, which is optional.<br>- **proxy**: address of the proxy server for a common data connection, which is optional.<br>- **mmsproxy**: dedicated proxy address of the MMS service, which is optional.<br>- **authType**: authentication protocol type of the APN, which is optional.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { networkManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let apnInfo: Record<string, string> = {
  // Replace it as required.
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

Deletes the APN.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| apnId  | string | Yes  | APN ID to be deleted. You can obtain device information using [networkManager.queryApn](#networkmanagerqueryapn20).|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { networkManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let apnId: string = "1"; // Replace it as required.
try {
  networkManager.deleteApn(wantTemp, apnId);
  console.info(`Succeeded in deleting apn.`);
} catch (err) {
  console.error(`Failed to delete apn. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.updateApn<sup>20+</sup>

updateApn(admin: Want, apnInfo: Record\<string, string>, apnId: string): void

Updates the APN.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| apnInfo  | Record\<string, string> | Yes  | APN information to be updated.<br>- **apnName**: APN identifier, which is optional.<br>- **mcc**: 3-digit mobile country code (MCC), which is optional.<br>- **mnc**: 2-digit or 3-digit mobile network code (MNC), which is optional.<br>- **APN**: access point name, which is optional.<br>- **type**: APN service type, which is optional.<br>- **user**: user name for APN authentication, which is optional.<br>- **password**: password for APN authentication, which is optional.<br>- **proxy**: address of the proxy server for a common data connection, which is optional.<br>- **mmsproxy**: dedicated proxy address of the MMS service, which is optional.<br>- **authType**: authentication protocol type of the APN, which is optional.|
| apnId  | string | Yes  | APN ID to be updated. You can obtain device information using [networkManager.queryApn](#networkmanagerqueryapn20).|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { networkManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let apnInfo: Record<string, string> = {
  // Replace it as required.
  "apnName": "CTNET",
  "apn": "CTNET",
  "mnc": "11",
  "mcc": "460",
};
let apnId: string = "1"; // Replace it as required.
try {
  networkManager.updateApn(wantTemp, apnInfo, apnId);
  console.info(`Succeeded in updating apn.`);
} catch (err) {
  console.error(`Failed to update apn. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.setPreferredApn<sup>20+</sup>

setPreferredApn(admin: Want, apnId: string): void

Sets the preferred APN.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| apnId  | string | Yes  | Preferred APN ID to be set. You can obtain device information using [networkManager.queryApn](#networkmanagerqueryapn20).|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { networkManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let apnId: string = "1"; // Replace it as required.
try {
  networkManager.setPreferredApn(wantTemp, apnId);
  console.info(`Succeeded in setting preferred apn.`);
} catch (err) {
  console.error(`Failed to set preferred apn. Code: ${err.code}, message: ${err.message}`);
}
```

## networkManager.queryApn<sup>20+</sup>

queryApn(admin: Want, apnInfo: Record\<string, string>): Array\<string>

Queries the APN ID.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| apnInfo  | Record\<string, string> | Yes  | APN information.<br>- **apnName**: APN identifier, which is optional.<br>- **mcc**: 3-digit mobile country code (MCC), which is optional.<br>- **mnc**: 2-digit or 3-digit mobile network code (MNC), which is optional.<br>- **apn**: access point name, which is optional.<br>- **type**: APN service type, which is optional.<br>- **user**: user name for APN authentication, which is optional.<br>- **proxy**: address of the proxy server for a common data connection, which is optional.<br>- **mmsproxy**: dedicated proxy address of the MMS service, which is optional.<br>- **authType**: authentication protocol type of the APN, which is optional.|

**Return value**

| Type                                         | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| Array\<string> | APN ID obtained.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { networkManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let apnInfo: Record<string, string> = {
  // Replace it as required.
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

Queries the APN parameter information.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| apnId  | string | Yes  | Specified APN ID. You can obtain device information using [networkManager.queryApn](#networkmanagerqueryapn20).|

**Return value**

| Type                                         | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| Record\<string, string> | APN parameter information of the specified APN ID.<br>- **apnName**: APN identifier.<br>- **mcc**: 3-digit mobile country code (MCC).<br>- **mnc**: 2-digit or 3-digit mobile network code (MNC).<br>- **apn**: access point name.<br>- **type**: APN service type.<br>- **user**: user name for APN authentication.<br>- **proxy**: address of the proxy server for a common data connection.<br>- **mmsproxy**: dedicated proxy address of the MMS service.<br>- **authType**: authentication protocol type of the APN.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { networkManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let apnId: string = "1"; // Replace it as required.
try {
  let queryResult: Record<string, string> = networkManager.queryApn(wantTemp, apnId);
  console.info(`Succeeded in querying apn, result : ${JSON.stringify(queryResult)}`);
} catch (err) {
  console.error(`Failed to query apn. Code: ${err.code}, message: ${err.message}`);
}
```

## FirewallRule

Represents a firewall rule.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


| Name     | Type                   | Read-only| Optional| Description                                                        |
| --------- | ----------------------- | ---- | ---- |------------------------------------------------------------ |
| srcAddr   | string                  | No  | Yes|Source IP address. An IP address segment, for example, **192.168.0.0/22** or **192.168.1.100-192.168.1.200** is supported.|
| destAddr  | string                  | No  | Yes|Destination IP address. An IP address segment, for example, **192.168.0.0/22** or **192.168.1.100-192.168.1.200** is supported.|
| srcPort   | string                  | No  | Yes|Source port.                                                    |
| destPort  | string                  | No  | Yes|Destination port.                                                  |
| appUid    | string                  | No  | Yes|UID of the application.                                                   |
| direction | [Direction](#direction) | No  | Yes|Direction chains to which the rule applies.<br>This parameter is mandatory when a firewall rule is added.<br>This parameter is optional when a firewall is removed. If this parameter is left empty, all [Direction](#direction) chains are cleared, and **srcAddr**, **destAddr**, **srcPort**, **destPort**, and **appUid** must be also left empty.|
| action    | [Action](#action)       | No  | Yes|Action to take, that is, receive or discard the data packets.<br>This parameter is mandatory when a firewall rule is added.<br>This parameter is optional when a firewall is removed. If this parameter is left empty, all [Action](#action) chains are cleared, and **srcAddr**, **destAddr**, **srcPort**, **destPort**, and **appUid** must be also left empty.|
| protocol  | [Protocol](#protocol)   | No  | Yes|Network protocol. If this parameter is set to **ALL** or **ICMP**, **srcPort** and **destPort** cannot be set.|

## DomainFilterRule

Represents a domain name filtering rule.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


| Name      | Type             | Read-only| Optional| Description                                                        |
| ---------- | ----------------- | ---- | ---- | ------------------------------------------------------------ |
| domainName | string            | No  | Yes|Domain name. This parameter is mandatory when a domain name filtering rule is added.                              |
| appUid     | string            | No  | Yes|UID of the application.                                                   |
| action     | [Action](#action) | No  | Yes|Action to take, that is, receive or discard the data packets.<br>This parameter is mandatory when a domain name filtering rule is added.<br>This parameter is optional when a domain name filtering rule is removed. If this parameter is left empty, all [Action](#action) chains are cleared, and **domainName** and **appUid** must be also left empty.|
| direction<sup>15+</sup> | [Direction](#direction) | No| Yes|Direction chains to which the rule applies.<br>This parameter is mandatory when a firewall rule is added.<br>This parameter is optional when a firewall is removed. If this parameter is left empty, all [Direction](#direction) chains are cleared, and **domainName** and **appUid** must be also left empty.|

## Direction

Direction chains to which the rule applies.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


| Name  | Value  | Description    |
| ------ | ---- | -------- |
| INPUT  | 0    | Input chain.|
| OUTPUT | 1    | Output chain.|
| FORWARD<sup>15+</sup> | 2   | Forward chain. |

## Action

Enumerates the actions that can be taken for data packets.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


| Name | Value  | Description        |
| ----- | ---- | ------------ |
| ALLOW | 0    | Receive data packets.|
| DENY  | 1    | Discard data packets.|
| REJECT<sup>15+</sup> | 2 | Reject data packets.|

## Protocol

Network protocol.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


| Name| Value  | Description          |
| ---- | ---- | -------------- |
| ALL  | 0    | All network protocols.|
| TCP  | 1    | TCP. |
| UDP  | 2    | UDP. |
| ICMP | 3    | ICMP.|
