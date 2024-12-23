# @ohos.net.netFirewall (Network Firewall) (System API)

This module provides the firewall configuration and query functions for applications. You can configure firewall policies to implement access control for devices based on IP addresses, domain names, and DNS servers. In addition to adding, modifying, removing, and querying firewall policies, you can query firewall interception records.

> **NOTE**
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import netfirewall from '@ohos.net.netFirewall';
```

## netFirewall.setNetFirewallPolicy

setNetFirewallPolicy(userId: number, policy: NetFirewallPolicy): Promise\<void>

Sets a firewall policy.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.netfirewall

**Parameters**

| Name| Type                                   | Mandatory| Description                                        |
| ------ | ----------------------------------------| ---- | -------------------------------------------- |
| userId | number                                  | Yes  | User ID. It must be unique in the system.|
| policy | [NetFirewallPolicy](#netfirewallpolicy) | Yes  | Firewall policy.                          |

**Return value**

| Type               | Description                                    |
| ------------------- | ---------------------------------------- |
| Promise\<void>      | Promise that returns no value.               |

**Error codes**

| ID| Error Message                                           |
| -------  | ----------------------------------------------------|
| 201      | Permission denied.                                  |
| 202      | Non-system applications use system APIs.            |
| 401      | Parameter error.                                    |
| 2100001  | Invalid parameter value.                            |
| 2100002  | Operation failed. Cannot connect to service.        |
| 2100003  | System internal error.                              |
| 29400000 | The specified user does not exist.                  |

**Example**

```ts
import { netFirewall } '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let policy: netFirewall.NetFirewallPolicy = {
  isOpen: true,
  inAction: netFirewall.FirewallRuleAction.RULE_DENY,
  outAction: netFirewall.FirewallRuleAction.RULE_ALLOW
};
netFirewall.setNetFirewallPolicy(100, policy).then(() => {
  console.info("set firewall policy success.");
}).catch((error : BusinessError) => {
  console.error("set firewall policy failed: " + JSON.stringify(error));
});
```

## netFirewall.getNetFirewallPolicy

getNetFirewallPolicy(userId: number): Promise\<NetFirewallPolicy>

Obtains a firewall policy.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters**

| Name  | Type                  | Mandatory| Description                                          |
| -------- | ---------------------- | ---- | ---------------------------------------------- |
| userId   | number                 | Yes  | User ID. It must be unique in the system.  |

**Return value**

| Type                                             | Description                                 |
| ------------------------------------------------- | ------------------------------------- |
| Promise\<[NetFirewallPolicy](#netfirewallpolicy)> | Promise used to return the result, which is a firewall policy.|


**Error codes**

| ID| Error Message                                           |
| -------  | ----------------------------------------------------|
| 201      | Permission denied.                                  |
| 202      | Non-system applications use system APIs.            |
| 401      | Parameter error.                                    |
| 2100001  | Invalid parameter value.                            |
| 2100002  | Operation failed. Cannot connect to service.        |
| 2100003  | System internal error.                              |
| 29400000 | The specified user does not exist.                  |

**Example**

```ts
import { netFirewall } '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

netFirewall.getNetFirewallPolicy(100).then((result: netFirewall.NetFirewallPolicy) => {
  console.info('firewall policy: ', JSON.stringify(result));
}, (reason: BusinessError) => {
  console.error('get firewall policy failed: ', JSON.stringify(reason));
});
```

## netFirewall.addNetFirewallRule

addNetFirewallRule(rule: NetFirewallRule): Promise\<number>

Adds a firewall rule.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters**

| Name  | Type                                             | Mandatory| Description        |
| -------- | ------------------------------------------------- | ---- | ------------ |
| rule    |  [NetFirewallRule](#netfirewallrule)               | Yes  | Firewall rule.|

**Return value**

| Type                     | Description                    	                                  |
| ------------------------- | ----------------------------------------------------------- |
| Promise\<number>          | Promise used to return the result, which is the firewall rule ID automatically generated by the system.|

**Error codes**

| ID| Error Message                                                                |
| -------  | ------------------------------------------------------------------------ |
| 201      | Permission denied.                                                       |
| 202      | Non-system applications use system APIs.                                 |
| 401      | Parameter error.                                                         |
| 2100001  | Invalid parameter value.                                                 |
| 2100002  | Operation failed. Cannot connect to service.                             |
| 2100003  | System internal error.                                                   |
| 29400000 | The specified user does not exist.                                       |
| 29400001 | The number of firewall rules exceeds the maximum.                        |
| 29400002 | The number of IP address rules in the firewall rule exceeds the maximum. |
| 29400003 | The number of port rules in the firewall rule exceeds the maximum.       |
| 29400004 | The number of domain rules in the firewall rule exceeds the maximum.     |
| 29400005 | The number of domain rules exceeds the maximum.                          |
| 29400007 | The dns rule is duplication.                                             |

**Example**

```ts
import { netFirewall } '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ipRule: netFirewall.NetFirewallRule = {
  name: "rule1",
  description: "rule1 description",
  direction: netFirewall.NetFirewallRuleDirection.RULE_IN,
  action:netFirewall.NetFirewallRuleDirection.RULE_DENY,
  type: netFirewall.NetFirewallRuleType.RULE_IP,
  isEnabled: true,
  appUid: 20001,
  localIps: [
    {
      family: 1,
      type: 1,
      address: "10.10.1.1",
      mask: 24
    },{
      family: 1,
      type: 2,
      startIp: "10.20.1.1",
      endIp: "10.20.1.10"
    }],
  remoteIps:[
    {
      family: 1,
      type: 1,
      address: "20.10.1.1",
      mask: 24
    },{
      family: 1,
      type: 2,
      startIp: "20.20.1.1",
      endIp: "20.20.1.10"
    }],
  protocol: 6,
  localPorts: [
    {
      startPort: 1000,
      endPort: 1000
    },{
      startPort: 2000,
      endPort: 2001
    }],
  remotePorts: [
    {
      startPort: 443,
      endPort: 443
    }],
  userId: 100
};
netFirewall.addNetFirewallRule(ipRule).then((result: number) => {
  console.info('rule Id: ', result);
}, (reason: BusinessError) => {
  console.error('add firewall rule failed: ', JSON.stringify(reason));
});

let domainRule: netFirewall.NetFirewallRule = {
  name: "rule2",
  description: "rule2 description",
  direction: netFirewall.NetFirewallRuleDirection.RULE_IN,
  action:netFirewall.NetFirewallRuleDirection.RULE_DENY,
  type: netFirewall.NetFirewallRuleType.RULE_DOMAIN,
  isEnabled: true,
  appUid: 20002,
  domains: [
    {
      isWildcard: false,
      domain: "www.example.cn"
    },{
      isWildcard: true,
      domain: "*.example.cn"
    }],
  userId: 100
};
netFirewall.addNetFirewallRule(domainRule).then((result: number) => {
  console.info('rule Id: ', result);
}, (reason: BusinessError) => {
  console.error('add firewall rule failed: ', JSON.stringify(reason));
});

let dnsRule: netFirewall.NetFirewallRule = {
  name: "rule3",
  description: "rule3 description",
  direction: netFirewall.NetFirewallRuleDirection.RULE_IN,
  action:netFirewall.NetFirewallRuleDirection.RULE_DENY,
  type: netFirewall.NetFirewallRuleType.RULE_DNS,
  isEnabled: true,
  appUid: 20003,
  primaryDns: "4.4.4.4",
  standbyDns: "8.8.8.8",
  userId: 100
};
netFirewall.addNetFirewallRule(dnsRule).then((result: number) => {
  console.info('rule Id: ', result);
}, (reason: BusinessError) => {
  console.error('add firewall rule failed: ', JSON.stringify(reason));
});
```

## netFirewall.updateNetFirewallRule

updateNetFirewallRule(rule: NetFirewallRule): Promise\<void>

Updates a firewall rule.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters**

| Name | Type                                  | Mandatory| Description                            |
| ------- | -------------------------------------- | ---- | -------------------------------- |
| rule    | [NetFirewallRule](#netfirewallrule)    | Yes  | Firewall rule.                    |

**Return value**

| Type                | Description                                                               |
| -------------------  | ------------------------------------------------------------------- |
| Promise\<void>       | Promise that returns no value.                                          |

**Error codes**

| ID| Error Message                                                                       |
| -------  | ------------------------------------------------------------------------------- |
| 201      | Permission denied.                                                              |
| 202      | Non-system applications use system APIs.                                        |
| 401      | Parameter error.                                                                |
| 2100001  | Invalid parameter value.                                                        |
| 2100002  | Operation failed. Cannot connect to service.                                    |
| 2100003  | System internal error.                                                          |
| 29400000 | The specified user does not exist.                                              |
| 29400002 | The number of IP address rules in the firewall rule exceeds the maximum.        |
| 29400003 | The number of port rules in the firewall rule exceeds the maximum.              |
| 29400004 | The number of domain rules in the firewall rule exceeds the maximum.            |
| 29400005 | The number of domain rules exceeds the maximum.                                 |
| 29400006 | The specified rule does not exist.                                              |
| 29400007 | The dns rule is duplication.                                                    |
  
**Example**

```ts
import { netFirewall } '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ipRuleUpd: netFirewall.NetFirewallRule = {
  id: 1,
  name: "rule1",
  description: "rule1 description update",
  direction: netFirewall.NetFirewallRuleDirection.RULE_IN,
  action:netFirewall.NetFirewallRuleDirection.RULE_DENY,
  type: netFirewall.NetFirewallRuleType.RULE_IP,
  isEnabled: false,
  appUid: 20001,
  localIps: [
    {
      family: 1,
      type: 1,
      address: "10.10.1.1",
      mask: 24
    },{
      family: 1,
      type: 2,
      startIp: "10.20.1.1",
      endIp: "10.20.1.10"
    }],
  userId: 100
};
netFirewall.updateNetFirewallRule(ipRuleUpd).then(() => {
  console.info('update firewall rule success.');
}, (reason: BusinessError) => {
  console.error('update firewall rule failed: ', JSON.stringify(reason));
});
```
 
## netFirewall.removeNetFirewallRule

removeNetFirewallRule(userId: number, ruleId: number): Promise\<void>

Removes a firewall rule.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters**

| Name  | Type                            | Mandatory| Description                                        |
| -------- | -------------------------------- | ---- | -------------------------------------------- |
| rule     | NetFirewallRule                  | Yes  | Firewall rule.                                |
| userId   | number                           | Yes  | User ID. It must be unique in the system.|
| ruleId   | number                           | Yes  | ID of the firewall rule.                              |

**Return value**

| Type               | Description                                                                |
| ------------------- | ---------------------------------------------------------------------|
| Promise\<void>      | Promise that returns no value.                                           |

**Error codes**

| ID| Error Message                                                                       |
| -------  | ------------------------------------------------------------------------------- |
| 201      | Permission denied.                                                              |
| 202      | Non-system applications use system APIs.                                        |
| 401      | Parameter error.                                                                |
| 2100001  | Invalid parameter value.                                                        |
| 2100002  | Operation failed. Cannot connect to service.                                    |
| 2100003  | System internal error.                                                          |
| 29400000 | The specified user does not exist.                                              |
| 29400006 | The specified rule does not exist.                                              |
  
**Example**

```ts
import { netFirewall } '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

netFirewall.removeNetFirewallRule(100, 1).then(() => {
  console.info("delete firewall rule success.");
}).catch((error : BusinessError) => {
  console.error("delete firewall rule failed: " + JSON.stringify(error));
});
```
   
## netFirewall.getNetFirewallRules

getNetFirewallRules(userId: number, requestParam: RequestParam): Promise\<FirewallRulePage>

Obtains firewall rules by user ID. You need to specify the pagination query parameter when calling this API.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters**

| Name         | Type                         | Mandatory| Description                                        |
| --------------- | ----------------------------- | ---- | -------------------------------------------- |
| userId          | number                        | Yes  | User ID. It must be unique in the system.|
| requestParam    | [RequestParam](#requestparam) | Yes  | Pagination query parameter.                              |

**Return value**

| Type                                           | Description                                    |
| ----------------------------------------------- | ---------------------------------------- |
| Promise\<[FirewallRulePage](#firewallrulepage)> | Promise used to return the result, which is list of firewall rules.   |

**Error codes**

| ID| Error Message                                                                       |
| -------  | --------------------------------------------------------------------------------|
| 201      | Permission denied.                                                              |
| 202      | Non-system applications use system APIs.                                        |
| 401      | Parameter error.                                                                |
| 2100001  | Invalid parameter value.                                                        |
| 2100002  | Operation failed. Cannot connect to service.                                    |
| 2100003  | System internal error.                                                          |
| 29400000 | The specified user does not exist.                                              |
  
**Example**

```ts
import { netFirewall } '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ruleParam: netFirewall.RequestParam = {
  page: 1,
  pageSize: 10,
  orderField: netFirewall.NetFirewallOrderField.ORDER_BY_RULE_NAME,
  orderType: netFirewall.NetFirewallOrderType.ORDER_ASC
};
netFirewall.getNetFirewallRules(100, ruleParam).then((result: netfirewall.FirewallRulePage) => {
  console.info("result:", JSON.stringify(result));
}, (error: BusinessError) => {
  console.error("get firewall rules failed: " + JSON.stringify(error));
});
```

## netFirewall.getNetFirewallRule

getNetFirewallRule(userId: number, ruleId: number): Promise\<NetFirewallRule>

Obtains a firewall rule based on the specified user ID and rule ID.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters**

| Name  | Type                     | Mandatory| Description                                        |
| -------- | ------------------------- | ---- | -------------------------------------------- |
| userId   | number                    | Yes  | User ID. It must be unique in the system.|
| ruleId   | number                    | Yes  | ID of the firewall rule.                              |

**Return value**

| Type                                           | Description                                    |
| ----------------------------------------------- | ---------------------------------------- |
| Promise\<[NetFirewallRule](#netfirewallrule)>   | Promise used to return the result, which is a firewall rule.           |

**Error codes**

| ID| Error Message                                                                       |
| -------  | ------------------------------------------------------------------------------- |
| 201      | Permission denied.                                                              |
| 202      | Non-system applications use system APIs.                                        |
| 401      | Parameter error.                                                                |
| 2100001  | Invalid parameter value.                                                        |
| 2100002  | Operation failed. Cannot connect to service.                                    |
| 2100003  | System internal error.                                                          |
| 29400000 | The specified user does not exist.                                              |
| 29400006 | The specified rule does not exist.                                              |
  
**Example**

```ts
import { netFirewall } '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

netFirewall.getNetFirewallRule(100, 1).then((rule: netFirewall.NetFirewallRule) => {
  console.info("result:", JSON.stringify(rule));
}).catch((error : BusinessError) => {
  console.error(" get firewall rules failed: " + JSON.stringify(error));
});
```

## netFirewall.getInterceptedRecords

getInterceptedRecords(userId: number, requestParam: RequestParam): Promise<\InterceptedRecordPage>

Obtains interception records based on the specified user ID. You need to specify the pagination query parameter when calling this API.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters**

| Name      | Type                         | Mandatory| Description                                        |
| ------------ | --------------------------- | ---- | -------------------------------------------- |
| userId       | number                        | Yes  | User ID. It must be unique in the system.|
| requestParam | [RequestParam](#requestparam) | Yes  | Query parameter.                                  |

**Return value**

| Type                                                     | Description                           |
| --------------------------------------------------------- | ------------------------------- |
| Promise\<[InterceptedRecordPage](#interceptedrecordpage)> | Promise used to return the result, which is a list of interception records.|

**Error codes**

| ID| Error Message                                                                       |
| -------  | --------------------------------------------------------------------------------|
| 201      | Permission denied.                                                              |
| 202      | Non-system applications use system APIs.                                        |
| 401      | Parameter error.                                                                |
| 2100001  | Invalid parameter value.                                                        |
| 2100002  | Operation failed. Cannot connect to service.                                    |
| 2100003  | System internal error.                                                          |
| 29400000 | The specified user does not exist.                                              |
  
**Example**

```ts
import { netFirewall } '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let interceptRecordParam: netFirewall.RequestParam = {
  page: 1,
  pageSize: 10,
  orderField: netFirewall.NetFirewallOrderField.ORDER_BY_RECORD_TIME,
  orderType: netFirewall.NetFirewallOrderType.ORDER_DESC
};
netFirewall.getInterceptedRecords(100, interceptRecordParam).then((result: netFirewall.InterceptedRecordPage) => {
  console.info("result:", JSON.stringify(result));
}, (error: BusinessError) => {
  console.error("get intercept records failed: " + JSON.stringify(error));
});
```

## NetFirewallRuleDirection

Enumerates interception directions for firewall rules.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name        | Value  | Description  |
|--------------|------|--------|
| RULE_IN      | 1    | Inbound direction.|
| RULE_OUT     | 2    | Outbound direction.|

## FirewallRuleAction

Enumerates actions for firewall rules.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name          | Value  | Description  |
|----------------|------|------- |
| RULE_ALLOW     | 0    | Allowing network connection.|
| RULE_DENY      | 1    | Denying network connection.|

## NetFirewallRuleType

Enumerates firewall rule types.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name          | Value  | Description        |
|----------------| ---- | ------------ |
| RULE_IP        | 1    | IP address-based firewall rule.  |
| RULE_DOMAIN    | 2    | Domain name-based rule.|
| RULE_DNS       | 3    | DNS-based firewall rule.   |

## NetFirewallOrderField

Enumerates firewall rule sorting types.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name                 | Value  | Description                  |
| --------------------- | ---- | ---------- ----------- |
| ORDER_BY_RULE_NAME    | 1    | Sorting of firewall rules by name.|
| ORDER_BY_RECORD_TIME  | 100  | Sorting of firewall rules by time.    |

## NetFirewallOrderType

Enumerates firewall rule sorting orders.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name      | Value  | Description                          |
| ---------- | ---- | ------------------------------ |
| ORDER_ASC  | 1    | Sorting in ascending order.|
| ORDER_DESC | 100  | Sorting in descending order.|

## NetFirewallPolicy

Defines a firewall policy.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name      | Type                                      | Mandatory| Description         |
| -----------| -------------------------------------------|------|-------------- |
| isOpen     | boolean                                    | Yes  | Whether to enable or disable the firewall.|
| inAction   | [FirewallRuleAction](#firewallruleaction)  | Yes  | Inbound action.   |
| outAction  | [FirewallRuleAction](#firewallruleaction)  | Yes  | Outbound action.   |

## NetFirewallIpParams

Defines the IP address information of a firewall rule.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name       | Type  |Mandatory| Description                                                       |
| ----------- | -------|----|------------------------------------------------------------ |
| type        | number | Yes| IP address type. The value **1** indicates an IP address or subnet. When a single IP address is used, the mask is 32. The value **2** indicates an IP address segment.         |
| family      | number | No| IP address family. The value **1** indicates IPv4 and value **2** indicates IPv6. The default value is IPv4. Other values are not supported.                 |
| address     | string | No| IP address. This parameter is valid only when **type** is set to **1**.                  |
| mask        | number | No| Subnet mask for an IPv4 address and prefix for an IPv6 address. This parameter is valid only when **type** is set to **1**.|
| startIp     | string | No| Start IP address: This parameter is valid only when **type** is set to **2**.                  |
| endIp       | string | No| End IP address: This parameter is valid only when **type** is set to **2**.                  |

## NetFirewallPortParams

Defines the port parameters of a firewall rule.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name        | Type  | Mandatory| Description      |
| ------------ | -------|------|----------- |
| startPort    | number | Yes  | Start port number.|
| endPort      | number | Yes  | End port number.|

## NetFirewallDomainParams

Defines the domain information of a firewall rule.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name        | Type   | Mandatory| Description                                     |
| ------------ | --------|------|------------------------------------------ |
| isWildcard   | boolean | Yes  | Whether to contain wildcards.                         |
| domain       | string  | Yes  | DNS domain. If **isWildcard** is **false**, you need to specify the complete domain name.|

## NetFirewallDnsParams

Defines the DNS information of a firewall rule.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name        | Type   | Mandatory| Description          |
| ------------ | --------|------|--------------- |
| primaryDns   | string  | Yes  | Active DNS server.|
| standbyDns   | string  | No  | Standby DNS server.     |


## NetFirewallRule

Defines a firewall rule.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name       | Type                                                       |Mandatory| Description                                                          |
| ------------|-------------------------------------------------------------|----|--------------------------------------------------------------  |
| userId      | number                                                      | Yes| User ID. It must be unique in the system.                  |
| name        | string                                                      | Yes| Rule name. This parameter is mandatory and can contain a maximum of 128 characters.                               |
| direction   | [NetFirewallRuleDirection](#netfirewallruledirection)       | Yes| Interception direction, which can be inbound or outbound.                                        |
| action      | [FirewallRuleAction](#firewallruleaction)                   | Yes| Action.                                                        |
| type        | [NetFirewallRuleType](#netfirewallruletype)                 | Yes| Rule type.                                                    |
| isEnabled   | boolean                                                     | Yes| Whether to enable the firewall rule.                                                    |
| id          | number                                                      | No| Firewall rule ID.                                                      |
| description | string                                                      | No| Firewall rule description. This parameter is optional and can contain a maximum of 256 characters.                               |
| appUid      | number                                                      | No| Application or service UID.                                           |
| localIps    | Array\<[NetFirewallIpParams](#netfirewallipparams)>         | No| List of local IP addresses. This parameter is valid when **ruleType** is set to **RULE_IP**. A maximum of 10 local IP addresses are supported.        |
| remoteIps   | Array\<[NetFirewallIpParams](#netfirewallipparams)>         | No| List of remote IP addresses. This parameter is valid when **ruleType** is set to **RULE_IP**. A maximum of 10 local IP addresses are supported.|
| protocol    | number                                                      | No| Protocol. The value **6** indicates TCP and value **17** indicates UDP. This parameter is valid only when **ruleType** is set to **RULE_IP**. |
| localPorts  | Array\<[NetFirewallPortParams](#netfirewallportparams)>     | No| List of local ports. This parameter is valid when **ruleType** is set to **RULE_IP**. A maximum of 10 local ports are supported.  |
| remotePorts | Array\<[NetFirewallPortParams](#netfirewallportparams)>     | No| List of remote ports. This parameter is valid when **ruleType** is set to **RULE_IP**. A maximum of 10 remote ports are supported.  |
| domains     | Array\<[NetFirewallDomainParams](#netfirewalldomainparams)> | No| List of domain names. This parameter is valid only when **ruleType** is set to **RULE_DOMAIN**.        |
| dns         | [NetFirewallDnsParams](#netfirewalldnsparams)               | No| List of DNS server names. This parameter is valid only when **ruleType** is set to **RULE_DNS**.                 |

## InterceptedRecord

Defines an interception record.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name      | Type  | Mandatory| Description               |
|------------| -------|------|-------------------- |
| time       | number | Yes  | Timestamp.           |
| localIp    | string | No  | Local IP address.           |
| remoteIp   | string | No  | Remote IP address.           |
| localPort  | number | No  | Local port.         |
| remotePort | number | No  | Remote port.         |
| protocol   | number | No  | Transport layer protocol.       |
| appUid     | number | No  | Application or service UID.|
| domain     | string | No  | Domain name.             |


## RequestParam

Defines query parameters.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name      | Type                                            | Mandatory| Description                       |
|------------|--------------------------------------------------|------|---------------------------- |
| page       | number                                           | Yes  | Page number. The value range is [1,1000].   |
| pageSize   | number                                           | Yes  | Page size. The value range is [1,50]. |
| orderField | [NetFirewallOrderField](#netfirewallorderfield)  | Yes  | Sorting order field.                 |
| orderType  | [NetFirewallOrderType](#netfirewallordertype)    | Yes  | Sorting order type.                 |
## FirewallRulePage

Defines the pagination structure for firewall rules.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name      | Type                                       | Mandatory| Description         |
|------------|-------------------------------------------- |------|---------------|
| page       | number                                      | Yes  | Current page.   |
| pageSize   | number                                      | Yes  | Page size.     |
| totalPage  | number                                      | Yes  | Total number of pages.     |
| data       | Array\<[NetFirewallRule](#netfirewallrule)> | Yes  | Page data.   |

## InterceptedRecordPage

Defines the pagination structure for interception records.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name      | Type                                           | Mandatory| Description      |
|------------| ----------------------------------------------- |------|----------  |
| page       | number                                          | Yes  | Current page.|
| pageSize   | number                                          | Yes  | Page size.|
| totalPage  | number                                          | Yes  | Total number of pages.  |
| data       | Array\<[InterceptedRecord](#interceptedrecord)> | Yes  | Page data.|
