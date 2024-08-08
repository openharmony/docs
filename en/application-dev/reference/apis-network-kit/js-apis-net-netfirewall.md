# @ohos.net.netFirewall (Network firewall) (System interface)

The network firewall provides the following functions :
- The basic capabilities of firewalls,including enabling firewalls, enabling and disabling rules, and auditing capabilities.
- The ability to configure firewall rules,including the name, description, operation, effective application, protocol type, address, port, outbound/inbound direction, etc. of the rule.
- The ability to configure DNS policies,include configuring domain names that are prohibited/allowed for resolution,analyze the DNS server used (Primary/alternative) (application level).

> **Explain:**
> The first batch of interfaces in this module will be supported starting from API version 12.Subsequent versions of the newly added interface will use superscripts to separately mark the starting version of the interface.
> This module is the system interface.

## Import module

```ts
import netfirewall from '@ohos.net.netFirewall';
```

## netFirewall.setNetFirewallPolicy

setNetFirewallPolicy(userId: number, policy: NetFirewallPolicy): Promise\<void>

Set firewall policy.

**System interface**: This interface is a system interface.

**Permission required**: ohos.permission.MANAGE_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.netfirewall

**Parameters:**

| Parameter Name    | Type                                             | Required | Explanation                                                                 |
| ----------------- | ------------------------------------------------ | -------- | --------------------------------------------------------------------------- |
| userId            | number                                           | Yes      | User ID                                                                     |
| policy            | [NetFirewallPolicy](#NetFirewallPolicy)          | Yes      | Firewall on/off status,Default actions for inbound and outbound connections |

**Return value:**

| Type                 | Explanation                                                                                                              |
| -------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| Promise\<void>       | Return the execution result in the form of Promise.Success does not return, failure returns the corresponding error code.|

**Error code:**

| Error code ID | Error message                                |
| ------------- | -------------------------------------------- |
| 201           | Permission denied.                           |
| 401           | Parameter error.                             |
| 2100001       | Invalid parameter value.                     |
| 2100002       | Operation failed. Cannot connect to service. |
| 2100003       | System internal error.                       |
| 29400000      | The specified user does not exit.            |

**Example:**

```ts
import { netFirewall } from '@ohos.net.netFirewall';
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

Check the policy of the firewall.

**System interface**: This interface is a system interface.

**Permission required**: ohos.permission.GET_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters:**

| Parameter Name | Type                                              | Required | Explanation                                |
| -------------- | ------------------------------------------------- | -------- | ------------------------------------------ |
| userId         | number                                            | Yes      | User ID                                    |

**Return value:**

| Type                                              | Explanation                                           |
| ------------------------------------------------- | ----------------------------------------------------- |
| Promise\<[NetFirewallPolicy](#NetFirewallPolicy)> | Return interface information in the form of a Promise.|


**Error code:**

| Error code ID | Error message                                 |
| ------------- | --------------------------------------------- |
| 201           | Permission denied.                            |
| 401           | Parameter error.                              |
| 2100001       | Invalid parameter value.                      |
| 2100002       | Operation failed. Cannot connect to service.  |
| 2100003       | System internal error.                        |
| 29400000      | The specified user does not exit.             |

**Example:**

```ts
import { netFirewall } from '@ohos.net.netFirewall';
import { BusinessError } from '@kit.BasicServicesKit';

netFirewall.getNetFirewallPolicy(100).then((result: netFirewall.NetFirewallPolicy) => {
  console.info('firewall policy: ', JSON.stringify(result));
}, (reason: BusinessError) => {
  console.error('get firewall policy failed: ', JSON.stringify(reason));
});
```

## netFirewall.addNetFirewallRule

addNetFirewallRule(rule: NetFirewallRule): Promise\<number>

Add firewall rules.

**System interface**: This interface is a system interface.

**Permission required**: ohos.permission.MANAGE_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters:**

| Parameter Name   | Type                                              | Required | Explanation                                |
| ---------------- | ------------------------------------------------- | -------- | ------------------------------------------ |
| rule             |  [NetFirewallRule](#NetFirewallRule)              | Yes      | Firewall rules                             |

**Return value:**

| Type                              | Explanation                                             |
| --------------------------------- | ------------------------------------------------------- |
| Promise\<number>                  | Return interface information in the form of a Promise.  |

**Error code:**

| Error code ID | Error message                                                            |
| ------------- | -----------------------------------------------------------------------  |
| 201           | Permission denied.                                                       |
| 401           | Parameter error.                                                         |
| 2100001       | Invalid parameter value.                                                 |
| 2100002       | Operation failed. Cannot connect to service.                             |
| 2100003       | System internal error.                                                   |
| 29400000      | The specified user does not exit.                                        |
| 29400001      | The number of firewall rules exceeds the maximum.                        |
| 29400002      | The number of IP address rules in the firewall rule exceeds the maximum. |
| 29400003      | The number of port rules in the firewall rule exceeds the maximum.       |
| 29400004      | The number of domain rules in the firewall rule exceeds the maximum.     |
| 29400005      | The number of domain rules exceeds the maximum.                          |
| 29400007      | The dns rule is duplication.                                             |

**Example:**

```ts
import { netFirewall } from '@ohos.net.netFirewall';
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
      domain: "www.openharmony.cn"
    },{
      isWildcard: true,
      domain: "*.openharmony.cn"
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

Update firewall rules.

**System interface**: This interface is a system interface.

**Permission required**: ohos.permission.MANAGE_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters:**

| Parameter Name   | Type                                              | Required | Explanation                                |
| ---------------- | ------------------------------------------------- | -------- | ------------------------------------------ |
| rule             | [NetFirewallRule](#NetFirewallRule)               | Yes      | Firewall rules                             |

**Return value:**

| Type                | Explanation                                                                                                               |
| ------------------- | ------------------------------------------------------------------------------------------------------------------------- |
| Promise\<void>      | Return the execution result in the form of Promise.Success does not return, failure returns the corresponding error code. |

**Error code:**

| Error code ID | Error message                                                                   |
| ------------- | --------------------------------------------------------------------------------|
| 201           | Permission denied.                                                              |
| 401           | Parameter error.                                                                |
| 2100001       | Invalid parameter value.                                                        |
| 2100002       | Operation failed. Cannot connect to service.                                    |
| 2100003       | System internal error.                                                          |
| 29400000      | The specified user does not exit.                                               |
| 29400002      | The number of IP address rules in the firewall rule exceeds the maximum.        |
| 29400003      | The number of port rules in the firewall rule exceeds the maximum.              |
| 29400004      | The number of domain rules in the firewall rule exceeds the maximum.            |
| 29400005      | The number of domain rules exceeds the maximum.                                 |
| 29400006      | The specified rule does not exist.                                              |
| 29400007      | The dns rule is duplication.                                                    |
  
**Example:**

```ts
import { netFirewall } from '@ohos.net.netFirewall';
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

Delete firewall rules.

**System interface**: This interface is a system interface.

**Permission required**: ohos.permission.MANAGE_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters:**

| Parameter Name   | Type                                              | Required | Explanation                                |
| ---------------- | ------------------------------------------------- | -------- | ------------------------------------------ |
| rule             | NetFirewallRule                                   | Yes      | Firewall rules                             |
| userId           | number                                            | Yes      | User ID                                    |
| ruleId           | number                                            | Yes      | Firewall rules ID                          |

**Return value:**

| Type                | Explanation                                                                                                              |
| ------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| Promise\<void>      | Return the execution result in the form of Promise.Success does not return, failure returns the corresponding error code.|

**Error code:**

| Error code ID | Error message                                                                   |
| ------------- | --------------------------------------------------------------------------------|
| 201           | Permission denied.                                                              |
| 401           | Parameter error.                                                                |
| 2100001       | Invalid parameter value.                                                        |
| 2100002       | Operation failed. Cannot connect to service.                                    |
| 2100003       | System internal error.                                                          |
| 29400000      | The specified user does not exit.                                               |
| 29400006      | The specified rule does not exist.                                              |
  
**Example:**

```ts
import { netFirewall } from '@ohos.net.netFirewall';
import { BusinessError } from '@kit.BasicServicesKit';

netFirewall.removeNetFirewallRule(100, 1).then(() => {
  console.info("delete firewall rule success.");
}).catch((error : BusinessError) => {
  console.error("delete firewall rule failed: " + JSON.stringify(error));
});
```
   
## netFirewall.getNetFirewallRules

getNetFirewallRules(userId: number, requestParam: RequestParam): Promise\<FirewallRulePage>

Query all firewall rules for the user.

**System interface**: This interface is a system interface.

**Permission required**: ohos.permission.GET_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters:**

| Parameter Name   | Type                                              | Required | Explanation                       |
| ---------------- | ------------------------------------------------- | -------- | --------------------------------- |
| userId           | number                                            | Yes      | User ID                           |
| requestParam     | RequestParam [RequestParam](#RequestParam)        | Yes      | Query firewall rule parameters    |

**Return value:**

| Type                              | Explanation                                                            |
| --------------------------------- | ---------------------------------------------------------------------- |
| Promise\<[FirewallRulePage](#FirewallRulePage)>   | Return interface information in the form of a Promise. |

**Error code:**

| Error code ID | Error message                                                                   |
| ------------- | --------------------------------------------------------------------------------|
| 201           | Permission denied.                                                              |
| 401           | Parameter error.                                                                |
| 2100001       | Invalid parameter value.                                                        |
| 2100002       | Operation failed. Cannot connect to service.                                    |
| 2100003       | System internal error.                                                          |
| 29400000      | The specified user does not exit.                                               |
  
**Example:**

```ts
import { netFirewall } from '@kit.NetworkKit';
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

Query individual firewall rules for users.

**System interface**: This interface is a system interface.

**Permission required**: ohos.permission.GET_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters:**

| Parameter Name   | Type                                              | Required | Explanation        |
| ---------------- | ------------------------------------------------- | -------- | ------------------ |
| userId           | number                                            | Yes      | User ID            |
| ruleId           | number                                            | Yes      | Firewall rules ID  |

**Return value:**

| Type                                            | Explanation                                            |
| ----------------------------------------------- | ------------------------------------------------------ |
| Promise\<[NetFirewallRule](#NetFirewallRule)>   | Return interface information in the form of a Promise. |

**Error code:**

| Error code ID | Error message                                                                   |
| ------------- | --------------------------------------------------------------------------------|
| 201           | Permission denied.                                                              |
| 401           | Parameter error.                                                                |
| 2100001       | Invalid parameter value.                                                        |
| 2100002       | Operation failed. Cannot connect to service.                                    |
| 2100003       | System internal error.                                                          |
| 29400000      | The specified user does not exit.                                               |
| 29400006      | The specified rule does not exist.                                              |
  
**Example:**

```ts
import { netFirewall } from '@ohos.net.netFirewall';
import { BusinessError } from '@kit.BasicServicesKit';

netFirewall.getNetFirewallRule(100, 1).then((rule: netFirewall.NetFirewallRule) => {
  console.info("result:", JSON.stringify(rule));
}).catch((error : BusinessError) => {
  console.error(" get firewall rules failed: " + JSON.stringify(error));
});
```

## netFirewall.getInterceptRecords

getInterceptRecords(userId: number, requestParam: RequestParam): Promise<\InterceptRecordPage>

Query the firewall's interception records.

**System interface**: This interface is a system interface.

**Permission required**: ohos.permission.GET_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters:**

| Parameter Name   | Type                              | Required | Explanation         |
| ---------------- | --------------------------------- | -------- | ------------------- |
| userId           | number                            | Yes      | User ID             |
| requestParam     |  [RequestParam](#RequestParam)    | Yes      | Query parameters    |

**Return value:**

| Type                                                    | Explanation                                                   |
| ------------------------------------------------------- | ------------------------------------------------------------- |
| Promise\<[InterceptRecordPage](#InterceptRecordPage)>   | Return interface information in the form of a Promise.        |

**Error code:**

| Error code ID | Error message                                           |
| ------------- | --------------------------------------------------------|
| 201           | Permission denied.                                      |
| 401           | Parameter error.                                        |
| 2100001       | Invalid parameter value.                                |
| 2100002       | Operation failed. Cannot connect to service.            |
| 2100003       | System internal error.                                  |
| 29400000      | The specified user does not exit.                       |
  
**Example:**

```ts
import { netFirewall } from '@ohos.net.netFirewall';
import { BusinessError } from '@kit.BasicServicesKit';

let interceptRecordParam: netFirewall.RequestParam = {
  page: 1,
  pageSize: 10,
  orderField: netFirewall.NetFirewallOrderField.ORDER_BY_RECORD_TIME,
  orderType: netFirewall.NetFirewallOrderType.ORDER_DESC
};
netFirewall.getInterceptRecords(100, interceptRecordParam).then((result: netFirewall.InterceptRecordPage) => {
  console.info("result:", JSON.stringify(result));
}, (error: BusinessError) => {
  console.error("get intercept records failed: " + JSON.stringify(error));
});
```

## NetFirewallRuleDirection

Firewall rules' interception directions are enumerated.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name         | Value   | Explanation   |
| ------------ | ------- | ------------- |
| RULE_IN      | 1       | Inbound       |
| RULE_OUT     | 2       | Outbound      |

## FirewallRuleAction

Firewall rule action enumeration.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name           | Value   | Explanation   |
| -------------- | ------- |-------------- |
| RULE_ALLOW     | 0       | Allow         |
| RULE_DENY      | 1       | Refuse        |

## NetFirewallRuleType

Enumeration of firewall rule types.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name           | Value   | Explanation       |
| -------------- | ------- | ----------------- |
| RULE_IP        | 1       | IP class rules    |
| RULE_DOMAIN    | 2       | Domain name rules |
| RULE_DNS       | 3       | DNS rules         |

## NetFirewallOrderField

Enumeration of firewall rule sorting types.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name                  | Value   | Explanation                |
| --------------------- | ------- | -------------------------- |
| ORDER_BY_RULE_NAME    | 1       | Sort by firewall rule name |
| ORDER_BY_RECORD_TIME  | 100     | Sort by record time        |

## NetFirewallOrderType

Enumeration of firewall rule sorting types.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name                  | Value   | Explanation      |
| --------------------- | ------- | ---------------- |
| ORDER_ASC             | 1       | Ascending order  |
| ORDER_DESC            | 100     | Descending order |

## NetFirewallPolicy

Firewall policy.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name | Type                                       | Required | Explanation     |
| -------------- | ------------------------------------------ |--------- |---------------- |
| isOpen         | boolean                                    | Yes      | Firewall on/off |
| inAction       | [FirewallRuleAction](#FirewallRuleAction)  | Yes      | Inbound Action  |
| outAction      | [FirewallRuleAction](#FirewallRuleAction)  | Yes      | Outbound action |

## NetFirewallIpParam

Firewall rule IP parameters.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name | Type   | Required | Explanation                                                                  |    
| -------------- | ------ | -------- | ---------------------------------------------------------------------------- |
| family         | number | No       | IPv4=1, IPv6=2, Default IPv4, Currently not supported for others             |
| type           | number | Yes      | 1:IP address or subnet,When using a single IP, the mask is 32; 2:IP segment  |
| address        | string | No       | IP address: Valid when type equals 1, otherwise ignored                      |
| mask           | number | No       | IPv4:subnet mask,IPv6:prefix, Valid when type equals 1, otherwise ignored    |
| startIp        | string | No       | Starting IP: Valid when type equals 2, otherwise ignored                     |
| endIp          | string | No       | End IP: Valid when type equals 2, otherwise ignored                          |

## NetFirewallPortParam

Firewall rule port parameters.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name | Type   | Required | Explanation     |
| -------------- | ------ | -------- | --------------- |
| startPort      | number | Yes      | Start Port      |
| endPort        | number | Yes      | End port        |

## NetFirewallDomainParam

Firewall rule domain information.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name  | Type    | Required | Explanation                                                               |
| --------------- | ------- | -------- | ------------------------------------------------------------------------- |
| isWildcard      | boolean | Yes      | Does it contain wildcard characters                                       |
| domain          | string  | Yes      | When isWildcard is false, the complete domain that needs to be determined |

## NetFirewallDnsParam

Firewall rule DNS information.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name    | Type    | Required | Explanation             |
| ----------------- | ------- | -------- | ----------------------- |
| primaryDns        | string  | Yes      | Main Domain Name Server |
| standbyDns        | string  | No       | Backup DNS              |


## NetFirewallRule

Firewall rule information structure.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name  | Type                                                     | Required | Explanation                                                                             |
| --------------- | -------------------------------------------------------- | -------- | --------------------------------------------------------------------------------------- |
| id              | number                                                   | No       | Rule ID                                                                                 |
| name            | string                                                   | Yes      | Rule Name,Required, at most 128 character                                               |
| description     | string                                                   | No       | Rule Description, Optional, at most 256 character                                       |
| direction       | [NetFirewallRuleDirection](#NetFirewallRuleDirection)    | Yes      | Rule direction, Inbound or Outbound                                                     |
| action          | [FirewallRuleAction](#FirewallRuleAction)                | Yes      | behavior                                                                                |
| type            | [NetFirewallRuleType](#NetFirewallRuleType)              | Yes      | Rule type                                                                               |
| isEnabled       | boolean                                                  | Yes      | Is it enabled                                                                           |
| appUid          | number                                                   | No       | Application or Service UID                                                              |
| localIps        | Array\<[NetFirewallIpParam](#NetFirewallIpParam)>        | No       | Local IP address: Valid when ruleType=RULE-IP,otherwise, it will be ignored ,at most 20 |
| remoteIps       | Array\<[NetFirewallIpParam](#NetFirewallIpParam)>        | No       | Remote IP address: Valid when ruleType=RULE-IP,otherwise, it will be ignored,at most 20 |
| protocol        | number                                                   | No       | Protocol, TCP:6, UDP:17, Valid when ruleType=RULE-IP,otherwise, it will be ignored      |
| localPorts      | Array\<[NetFirewallPortParam](#NetFirewallPortParam)>    | No       | Local Port: Valid when ruleType=RULE-IP,otherwise, it will be ignored,at most 10        |
| remotePorts     | Array\<[NetFirewallPortParam](#NetFirewallPortParam)>    | No       | Teleport: Valid when ruleType=RULE-IP,otherwise, it will be ignored,at most 10          |
| domains         | Array\<[NetFirewallDomainParam](#NetFirewallDomainParam)>| No       | Domain Name List: Valid when ruleType=RULE-IP,otherwise, it will be ignored             |
| dns             | [NetFirewallDnsParam](#NetFirewallDnsParam)              | No       | DNS:Valid when ruleType=RULE-DNS, otherwise ignored                                     |
| userId          | number                                                   | Yes      | User ID                                                                                 |

## InterceptRecord

Intercept the structure of recorded information.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name | Type   | Required | Explanation                |
| -------------- | ------ | -------- | -------------------------- |
| time           | number | Yes      | Time stamp                 |
| localIp        | string | No       | Local IP                   |
| remoteIp       | string | No       | Remote IP                  |
| localPort      | number | No       | Local Port                 |
| remotePort     | number | No       | Remote Port                |
| protocol       | number | No       | Transport Layer Protocol   |
| appUid         | number | No       | Application or Service UID |
| domain         | string | No       | Domain name                |

## RequestParam

Query input information structure.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name | Type                                              | Required | Explanation                         |
| -------------- | ------------------------------------------------- | -------- | ----------------------------------- |
| page           | number                                            | Yes      | Current page, value range: [1,1000] |
| pageSize       | number                                            | Yes      | Page size, value range: [1,50]      |
| orderField     |  [NetFirewallOrderField](#NetFirewallOrderField)  | Yes      | Search Rules                        |
| orderType      |  [NetFirewallOrderType](#NetFirewallOrderType)    | Yes      | Sort order                          |

## FirewallRulePage

Firewall rule page information structure.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name | Type                                        | Required | Explanation     |
| -------------- | ------------------------------------------- | -------- |---------------- |
| page           | number                                      | Yes      | Current page    |
| pageSize       | number                                      | Yes      | Page size       |
| totalPage      | number                                      | Yes      | PageCount       |
| data           | Array\<[NetFirewallRule](#NetFirewallRule)> | Yes      | Page data       |

## InterceptRecordPage

Intercept the structure of paginated information in the record.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name | Type                                         | Required | Explanation         |
| -------------- | -------------------------------------------- | -------- | ------------------- |
| page           | number                                       | Yes      | Current page number |
| pageSize       | number                                       | Yes      | Page size           |
| totalPage      | number                                       | Yes      | PageCount           |
| data           | Array\<[InterceptRecord](#InterceptRecord)>  | Yes      | Page data           |
