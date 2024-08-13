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
| userId            | number                                           | Yes      | Indicates the user ID. It cannot be the ID of a user that does not exis.    |
| policy            | [NetFirewallPolicy](#NetFirewallPolicy)          | Yes      | The firewall policy to be set                                               |

**Return value:**

| Type                 | Explanation    |
| -------------------- | -------------- |
| Promise\<void>       | Returns void.  |

**Error code:**

| Error code ID | Error message                                |
| ------------- | -------------------------------------------- |
| 201           | Permission denied.                           |
| 202           | Non-system applications use system APIs.     |
| 401           | Parameter error.                             |
| 2100001       | Invalid parameter value.                     |
| 2100002       | Operation failed. Cannot connect to service. |
| 2100003       | System internal error.                       |
| 29400000      | The specified user does not exist.           |

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

| Parameter Name | Type                | Required | Explanation                                                              |
| -------------- | ------------------- | -------- | ------------------------------------------------------------------------ |
| userId         | number              | Yes      | Indicates the user ID. It cannot be the ID of a user that does not exist.|

**Return value:**

| Type                                              | Explanation                                           |
| ------------------------------------------------- | ----------------------------------------------------- |
| Promise\<[NetFirewallPolicy](#NetFirewallPolicy)> | Current user firewall policy.                         |


**Error code:**

| Error code ID | Error message                                 |
| ------------- | --------------------------------------------- |
| 201           | Permission denied.                            |
| 202           | Non-system applications use system APIs.      |
| 401           | Parameter error.                              |
| 2100001       | Invalid parameter value.                      |
| 2100002       | Operation failed. Cannot connect to service.  |
| 2100003       | System internal error.                        |
| 29400000      | The specified user does not exist.            |

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

| Parameter Name   | Type                                | Required | Explanation          |
| ---------------- | ----------------------------------- | -------- | -------------------- |
| rule             |  [NetFirewallRule](#NetFirewallRule)| Yes      | Firewall rule.       |

**Return value:**

| Type                              | Explanation                                          |
| --------------------------------- | ---------------------------------------------------- |
| Promise\<number>                  | Indicates the rule ID, generated by the system.      |

**Error code:**

| Error code ID | Error message                                                            |
| ------------- | -----------------------------------------------------------------------  |
| 201           | Permission denied.                                                       |
| 202           | Non-system applications use system APIs.                                 |
| 401           | Parameter error.                                                         |
| 2100001       | Invalid parameter value.                                                 |
| 2100002       | Operation failed. Cannot connect to service.                             |
| 2100003       | System internal error.                                                   |
| 29400000      | The specified user does not exist.                                       |
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

| Parameter Name   | Type                                       | Required | Explanation          |
| ---------------- | -------------------------------------------| -------- | -------------------- |
| rule             | [NetFirewallRule](#NetFirewallRule)        | Yes      | Firewall rule        |

**Return value:**

| Type                | Explanation                                                               |
| ------------------- | ------------------------------------------------------------------------- |
| Promise\<void>      | Returns void.                                                             |

**Error code:**

| Error code ID | Error message                                                                   |
| ------------- | --------------------------------------------------------------------------------|
| 201           | Permission denied.                                                              |
| 202           | Non-system applications use system APIs.                                        |
| 401           | Parameter error.                                                                |
| 2100001       | Invalid parameter value.                                                        |
| 2100002       | Operation failed. Cannot connect to service.                                    |
| 2100003       | System internal error.                                                          |
| 29400000      | The specified user does not exist.                                              |
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

| Parameter Name | Type            | Required | Explanation                                                              |
| -------------- | --------------- | -------- | ------------------------------------------------------------------------ |
| rule           | NetFirewallRule | Yes      | Firewall rule                                                            |
| userId         | number          | Yes      | Indicates the user ID. It cannot be the ID of a user that does not exist.|
| ruleId         | number          | Yes      | Firewall rules ID.                                                       |

**Return value:**

| Type                | Explanation                                                               |
| ------------------- | ------------------------------------------------------------------------- |
| Promise\<void>      |  Returns void.                                                            |

**Error code:**

| Error code ID | Error message                                                                   |
| ------------- | --------------------------------------------------------------------------------|
| 201           | Permission denied.                                                              |
| 202           | Non-system applications use system APIs.                                        |
| 401           | Parameter error.                                                                |
| 2100001       | Invalid parameter value.                                                        |
| 2100002       | Operation failed. Cannot connect to service.                                    |
| 2100003       | System internal error.                                                          |
| 29400000      | The specified user does not exist.                                              |
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

Get firewall rules by userId, and it is necessary to specify the pagination query parameters.

**System interface**: This interface is a system interface.

**Permission required**: ohos.permission.GET_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters:**

| Parameter Name| Type                         | Required | Explanation                                                              |
| ------------- | ---------------------------- | -------- | ------------------------------------------------------------------------ |
| userId        | number                       | Yes      | Indicates the user ID. It cannot be the ID of a user that does not exist.|
| requestParam  | [RequestParam](#RequestParam)| Yes      | Paging query input parameters.                                           |

**Return value:**

| Type                              | Explanation                                                 |
| --------------------------------- | ----------------------------------------------------------- |
| Promise\<[FirewallRulePage](#FirewallRulePage)>   | Paginated firewall rule list.               |

**Error code:**

| Error code ID | Error message                                                                   |
| ------------- | --------------------------------------------------------------------------------|
| 201           | Permission denied.                                                              |
| 202           | Non-system applications use system APIs.                                        |
| 401           | Parameter error.                                                                |
| 2100001       | Invalid parameter value.                                                        |
| 2100002       | Operation failed. Cannot connect to service.                                    |
| 2100003       | System internal error.                                                          |
| 29400000      | The specified user does not exist.                                              |
  
**Example:**

```ts
import { netFirewall } from '@ohos.net.netFirewall';
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

Get a specified firewall rule by userId and ruleId.

**System interface**: This interface is a system interface.

**Permission required**: ohos.permission.GET_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters:**

| Parameter Name| Type   | Required | Explanation                                                               |
| ------------- | ------ | -------- | ------------------------------------------------------------------------- |
| userId        | number | Yes      | Indicates the user ID. It cannot be the ID of a user that does not exist. |
| ruleId        | number | Yes      | Firewall rules ID.                                                        |

**Return value:**

| Type                                            | Explanation                                   |
| ----------------------------------------------- | --------------------------------------------- |
| Promise\<[NetFirewallRule](#NetFirewallRule)>   | Firewall Rule.                                |

**Error code:**

| Error code ID | Error message                                                                   |
| ------------- | --------------------------------------------------------------------------------|
| 201           | Permission denied.                                                              |
| 202           | Non-system applications use system APIs.                                        |
| 401           | Parameter error.                                                                |
| 2100001       | Invalid parameter value.                                                        |
| 2100002       | Operation failed. Cannot connect to service.                                    |
| 2100003       | System internal error.                                                          |
| 29400000      | The specified user does not exist.                                              |
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

## netFirewall.getInterceptedRecords

getInterceptedRecords(userId: number, requestParam: RequestParam): Promise<\InterceptedRecordPage>

Get intercepted records by userId, and it is necessary to specify the pagination query parameters.

**System interface**: This interface is a system interface.

**Permission required**: ohos.permission.GET_NET_FIREWALL

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

**Parameters:**

| Parameter Name | Type                          | Required | Explanation                                                               |
| -------------- | ----------------------------- | -------- | ------------------------------------------------------------------------- |
| userId         | number                        | Yes      | Indicates the user ID. It cannot be the ID of a user that does not exist. |
| requestParam   | [RequestParam](#RequestParam) | Yes      | Query parameters                                                          |

**Return value:**

| Type                                                      | Explanation                                                   |
| --------------------------------------------------------- | ------------------------------------------------------------- |
| Promise\<[InterceptedRecordPage](#InterceptedRecordPage)> | Block Record List.                                            |

**Error code:**

| Error code ID | Error message                                           |
| ------------- | --------------------------------------------------------|
| 201           | Permission denied.                                      |
| 202           | Non-system applications use system APIs.                |
| 401           | Parameter error.                                        |
| 2100001       | Invalid parameter value.                                |
| 2100002       | Operation failed. Cannot connect to service.            |
| 2100003       | System internal error.                                  |
| 29400000      | The specified user does not exist.                      |
  
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
netFirewall.getInterceptedRecords(100, interceptRecordParam).then((result: netFirewall.InterceptedRecordPage) => {
  console.info("result:", JSON.stringify(result));
}, (error: BusinessError) => {
  console.error("get intercept records failed: " + JSON.stringify(error));
});
```

## NetFirewallRuleDirection

Firewall rule direction enumeration.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name         | Value   | Explanation   |
| ------------ | ------- | ------------- |
| RULE_IN      | 1       | Inbound.      |
| RULE_OUT     | 2       | Outbound.     |

## FirewallRuleAction

Firewall rule behavior enumeration.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name           | Value   | Explanation   |
| -------------- | ------- |-------------- |
| RULE_ALLOW     | 0       | Allow access. |
| RULE_DENY      | 1       | Deny access.  |

## NetFirewallRuleType

Indicates the firewall rule type.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name           | Value   | Explanation        |
| -------------- | ------- | ------------------ |
| RULE_IP        | 1       | IP type rules.     |
| RULE_DOMAIN    | 2       | Domain type rules. |
| RULE_DNS       | 3       | DNS type rul       |

## NetFirewallOrderField

Pagination query sorting field.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name                  | Value   | Explanation                                                                             |
| --------------------- | ------- | --------------------------------------------------------------------------------------- |
| ORDER_BY_RULE_NAME    | 1       | Sort rule names, it can be referenced only by the getNetFirewallRules interface.        |
| ORDER_BY_RECORD_TIME  | 100     | Sort the recorded time, it can be referenced only by the getNetFirewallRules interface. |

## NetFirewallOrderType

Pagination query sorting type.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Name                  | Value   | Explanation       |
| --------------------- | ------- | ----------------- |
| ORDER_ASC             | 1       | Ascending order.  |
| ORDER_DESC            | 100     | Descending order. |

## NetFirewallPolicy

Firewall policy.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name | Type                                       | Required | Explanation                                            |
| -------------- | ------------------------------------------ |--------- |------------------------------------------------------- |
| isOpen         | boolean                                    | Yes      | Whether the firewall is open.                          |
| inAction       | [FirewallRuleAction](#FirewallRuleAction)  | Yes      | Inbound connections are allowed or denied by default.  |
| outAction      | [FirewallRuleAction](#FirewallRuleAction)  | Yes      | Outbound connections are allowed or denied by default. |

## NetFirewallIpParams

Firewall IP parameters.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name | Type   | Required | Explanation                                                                              |
| -------------- | ------ | -------- | ---------------------------------------------------------------------------------------- |
| type           | number | Yes      | 1: IP address or subnet, when using a single IP, the mask is 32; 2: IP segment.          |
| family         | number | No       | 1: IPv4, 2: IPv6, default is IPv4.                                                       |
| address        | string | No       | IP address: Valid when type equals 1, otherwise it will be ignored.                      |
| mask           | number | No       | IPv4: subnet mask, IPv6: prefix, valid when type equals 1, otherwise it will be ignored. |
| startIp        | string | No       | Start IP: valid when type equals 2, otherwise it will be ignored.                        |
| endIp          | string | No       | End IP: valid when type equals 2, otherwise it will be ignored.                          |

## NetFirewallPortParams

Firewall port parameters.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name | Type   | Required | Explanation                                                                             |
| -------------- | ------ | -------- | --------------------------------------------------------------------------------------- |
| startPort      | number | Yes      | Start port, when there is only one port, the start port is the same as the end port.    |
| endPort        | number | Yes      | End port, when there is only one port, the start port is the same as the end port.      |

## NetFirewallDomainParams

Firewall domain name parameters.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name  | Type    | Required | Explanation                                                                         |
| --------------- | ------- | -------- | ----------------------------------------------------------------------------------- |
| isWildcard      | boolean | Yes      | Is there a universal configuration rule.                                            |
| domain          | string  | Yes      | Domain: when isWildcard is false, the complete domain that needs to be determined; 
When isWildcard is true, fuzzy domain only support domains like *.openharmony.cn; *.com.  |

## NetFirewallDnsParams

Firewall DNS parameters.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name    | Type    | Required | Explanation             |
| ----------------- | ------- | -------- | ----------------------- |
| primaryDns        | string  | Yes      | Primary DNS.            |
| standbyDns        | string  | No       | Backup DNS              |


## NetFirewallRule

Firewall rules.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name | Type                                                       | Required | Explanation                                                                      |
| -------------- | ---------------------------------------------------------- | -------- | -------------------------------------------------------------------------------- |
| userId         | number                                                     | Yes      | User id.                                                                         |
| name           | string                                                     | Yes      | Rule name.                                                                       |
| direction      | [NetFirewallRuleDirection](#NetFirewallRuleDirection)      | Yes      | Rule direction, Inbound or Outbound.                                             |
| action         | [FirewallRuleAction](#FirewallRuleAction)                  | Yes      | Rule action.                                                                     |
| type           | [NetFirewallRuleType](#NetFirewallRuleType)                | Yes      | Rule type.                                                                       |
| isEnabled      | boolean                                                    | Yes      | Whether the rule is enabled.                                                     |
| id             | number                                                     | No       | Rule id: When a rule is added to the system, the system generates a rule ID.     |
| description    | string                                                     | No       | Rule description.                                                                |
| appUid         | number                                                     | No       | Application or service UID.                                                      |
| localIps       | Array\<[NetFirewallIpParams](#NetFirewallIpParams)>        | No       | Local IP address: valid when ruleType = RULE_IP, otherwise it will be ignored.   |
| remoteIps      | Array\<[NetFirewallIpParams](#NetFirewallIpParams)>        | No       | Remote IP address: valid when ruleType = RULE_IP, otherwise it will be ignored.  |
| protocol       | number                                                     | No       | Protocol, 1: ICMPv4, 6: TCP, 17: UDP, 58: ICMPv6. Valid when ruleType = RULE_IP, otherwise it will be ignored.  |
| localPorts     | Array\<[NetFirewallPortParams](#NetFirewallPortParams)>    | No       | Local ports: valid when ruleType = RULE_IP, otherwise it will be ignored.        |
| remotePorts    | Array\<[NetFirewallPortParams](#NetFirewallPortParams)>    | No       | Remote ports: valid when ruleType = RULE_IP, otherwise it will be ignored.       |
| domains        | Array\<[NetFirewallDomainParams](#NetFirewallDomainParams)>| No       | Domain name list: valid when ruleType = RULE_DOMAIN, otherwise it will be ignored.                              |
| dns            | [NetFirewallDnsParams](#NetFirewallDnsParams)              | No       | DNS: valid when ruleType = RULE_DNS, otherwise it will be ignored.               |

## InterceptedRecord

Intercepted record.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name | Type   | Required | Explanation                      |
| -------------- | ------ | -------- | -------------------------------- |
| time           | number | Yes      | Time stamp.                      |
| localIp        | string | No       | Local IP.                        |
| remoteIp       | string | No       | Remote IP.                       |
| localPort      | number | No       | Local port.                      |
| remotePort     | number | No       | Remote port.                     |
| protocol       | number | No       | Transport layerpProtocol.        |
| appUid         | number | No       | Application or service UID.      |
| domain         | string | No       | Blocked domain name information. |

## RequestParam

Pagination query input parameters.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name | Type                                            | Required | Explanation                                                                 |
| -------------- | ----------------------------------------------- | -------- | --------------------------------------------------------------------------- |
| page           | number                                          | Yes      | Page number: indicates the page number to be queried. The start value is 1. |
| pageSize       | number                                          | Yes      | Page size: indicates the number of data records to be queried at a time. The maximum value is 50.  |
| orderField     |  [NetFirewallOrderField](#NetFirewallOrderField)| Yes      | Sort field.                                                                 |
| orderType      |  [NetFirewallOrderType](#NetFirewallOrderType)  | Yes      | Sort Type: ascending or descending.                                         |

## FirewallRulePage

Rule page information.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name | Type                                        | Required | Explanation                                                   |
| -------------- | ------------------------------------------- | -------- |-------------------------------------------------------------- |
| page           | number                                      | Yes      | Current page number: indicates the page number of this query. |
| pageSize       | number                                      | Yes      | Page size: maximum number of records on a page for this query.|
| totalPage      | number                                      | Yes      | Total pages: total number of pages.                           |
| data           | Array\<[NetFirewallRule](#NetFirewallRule)> | Yes      | Page data: all records displayed on this page.                |

## InterceptedRecordPage

Intercepted record page information.

**System interface**: This interface is a system interface.

**System capability**: SystemCapability.Communication.NetManager.NetFirewall

| Parameter Name | Type                                           | Required | Explanation                                                   |
| -------------- | ---------------------------------------------- | -------- | ------------------------------------------------------------- |
| page           | number                                         | Yes      | Current page number: indicates the page number of this query. |
| pageSize       | number                                         | Yes      | Page size: maximum number of records on a page for this query.|
| totalPage      | number                                         | Yes      | Total pages: total number of pages.                           |
| data           | Array\<[InterceptedRecord](#InterceptedRecord)>| Yes      | Page data: all records displayed on this page.                |
