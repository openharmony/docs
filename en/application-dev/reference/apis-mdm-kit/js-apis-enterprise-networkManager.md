# @ohos.enterprise.networkManager (Network Management)

The **networkManager** module provides APIs for network management of enterprise devices, including obtaining the device IP address and MAC address.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a [device administrator application](../../mdm/mdm-kit-guide.md#introduction) that is enabled.
>

## Modules to Import

```ts
import { networkManager } from '@kit.MDMKit';
```

## networkManager.getAllNetworkInterfacesSync

getAllNetworkInterfacesSync(admin: Want): Array&lt;string&gt;

Obtains all activated network ports through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.|

**Return value**

| Type               | Description                  |
| ------------------- | ---------------------- |
| Array&lt;string&gt; | Network ports obtained.|

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

Obtains the device IP address based on the network port through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name          | Type                                                   | Mandatory| Description          |
| ---------------- | ------------------------------------------------------- | ---- | -------------- |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.|
| networkInterface | string                                                  | Yes  | Network port.|

**Return value**

| Type  | Description            |
| ------ | ---------------- |
| string | Device IP address obtained.|

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

Obtains the device MAC address based on the network port through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name          | Type                                                   | Mandatory| Description          |
| ---------------- | ------------------------------------------------------- | ---- | -------------- |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.|
| networkInterface | string                                                  | Yes  | Network port.|

**Return value**

| Type  | Description             |
| ------ | ----------------- |
| string | Device MAC address obtained.|

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

Checks whether a network port is disabled through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name          | Type                                                   | Mandatory| Description          |
| ---------------- | ------------------------------------------------------- | ---- | -------------- |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.|
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

Disables a network port through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name          | Type                                                   | Mandatory| Description                                             |
| ---------------- | ------------------------------------------------------- | ---- | ------------------------------------------------- |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                                   |
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

Sets the global network proxy through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name   | Type                                                        | Mandatory| Description                      |
| --------- | ------------------------------------------------------------ | ---- | -------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | Device administrator application.            |
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

## networkManager.getGlobalProxySync

getGlobalProxySync(admin: Want): connection.HttpProxy

Obtains the global network proxy through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.|

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
import { BusinessError } from '@kit.BasicServicesKit';
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

## networkManager.addFirewallRule

addFirewallRule(admin: Want, firewallRule: FirewallRule): void

Adds a firewall rule for devices through the specified device administrator application.<br>
After a rule with [Action](#action) set to **ALLOW** is added, a rule with **Action** set to **DENY** is added by default to discard or intercept all network data packets that do not meet the **ALLOW** rule.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name      | Type                                                   | Mandatory| Description                |
| ------------ | ------------------------------------------------------- | ---- | -------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.      |
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

Removes a firewall rule for devices through the specified device administrator application.<br>
If there is no rule with [Action](#action) being **ALLOW** after the rule is removed, the **DENY** rules that are added by default with [addFirewallRule](#networkmanageraddfirewallrule) will be removed.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                |
| ------------ | ------------------------------------------------------- | ---- | ---------------------------------------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                                      |
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

Obtains firewall rules through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.|

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

Adds a domain name filtering rule for the device through the specified device administrator application.<br>
After a rule with [Action](#action) set to **ALLOW** is added, a rule with **Action** set to **DENY** is added by default to discard or intercept all packets for domain name resolution that do not meet the **ALLOW** rule.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name          | Type                                                   | Mandatory| Description              |
| ---------------- | ------------------------------------------------------- | ---- | ------------------ |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.    |
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

Removes a domain name filtering rule through the specified device administrator application.<br>
If there is no rule with [Action](#action) being **ALLOW** after the rule is removed, the **DENY** rules that are added by default with [addDomainFilterRule](#networkmanageradddomainfilterrule) will be removed.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name          | Type                                                   | Mandatory| Description                                            |
| ---------------- | ------------------------------------------------------- | ---- | ------------------------------------------------ |
| admin            | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                                  |
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

Obtains domain name filtering rules through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_NETWORK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.|

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

## FirewallRule

Represents a firewall rule.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


| Name     | Type                   | Mandatory| Description                                                        |
| --------- | ----------------------- | ---- | ------------------------------------------------------------ |
| srcAddr   | string                  | No  | Source IP address. An IP address segment, for example, **192.168.0.0/22** or **192.168.1.100-192.168.1.200** is supported.|
| destAddr  | string                  | No  | Destination IP address. An IP address segment, for example, **192.168.0.0/22** or **192.168.1.100-192.168.1.200** is supported.|
| srcPort   | string                  | No  | Source port.                                                    |
| destPort  | string                  | No  | Destination port.                                                  |
| appUid    | string                  | No  | UID of the application.                                                   |
| direction | [Direction](#direction) | No  | Direction chains to which the rule applies.<br>This parameter is mandatory when you add a firewall rule. If it is not specified when you remove a firewall rule, all [direction](#direction) chains will be removed.<br>If this parameter is empty, **srcAddr**, **destAddr**, **srcPort**, **destPort**, and **appUid** must also be empty.|
| action    | [Action](#action)       | No  | Action to take, that is, receive or discard data packets.<br>This parameter is mandatory when a firewall rule is added. It is optional when a firewall rule is removed. If it is not specified, all chains that match the [Action](#action) rule will be removed.<br>If this parameter is empty, **srcAddr**, **destAddr**, **srcPort**, **destPort**, and **appUid** must also be empty.|
| protocol  | [Protocol](#protocol)   | No  | Network protocol. If this parameter is set to **ALL** or **ICMP**, **srcPort** and **destPort** cannot be set.|

## DomainFilterRule

Represents a domain name filtering rule.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


| Name      | Type             | Mandatory| Description                                                        |
| ---------- | ----------------- | ---- | ------------------------------------------------------------ |
| domainName | string            | No  | Domain name. This parameter is mandatory when a domain name filtering rule is added.                              |
| appUid     | string            | No  | UID of the application.                                                   |
| action     | [Action](#action) | No  | Action to take, that is, receive or discard data packets.<br>This parameter is mandatory when you add a domain name filtering rule. If it is not specified when you remove a domain name filtering rule, all chains that match the [Action](#action) rule will be removed.<br>If this parameter is empty, **domainName** and **appUid** must also be empty.|

## Direction

Direction chains to which the rule applies.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


| Name  | Value  | Description    |
| ------ | ---- | -------- |
| INPUT  | 0    | Input chain.|
| OUTPUT | 1    | Output chain.|

## Action

Enumerates the actions that can be taken for data packets.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


| Name | Value  | Description        |
| ----- | ---- | ------------ |
| ALLOW | 0    | Receive data packets.|
| DENY  | 1    | Discard data packets.|

## Protocol

Network protocol.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


| Name| Value  | Description          |
| ---- | ---- | -------------- |
| ALL  | 0    | All network protocols.|
| TCP  | 1    | TCP. |
| UDP  | 2    | UDP. |
| ICMP | 3    | ICMP.|
