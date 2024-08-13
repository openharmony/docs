# @ohos.net.netFirewall（网络防火墙）（系统接口）

网络防火墙提供如下功能：
1. 防火墙的基础能力，包括防火墙的使能、规则的启用与禁用、审计能力
2. 防火墙规则的配置能力，包括规则的名称、描述、操作、生效应用、协议类型、地址、端口、出站/入站方向等
3. DNS策略的配置能力，包括配置禁止/允许解析的域名、解析使用的DNS服务器（主选/备选）（应用级）

> **说明：**
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块为系统接口。

## 导入模块

```ts
import netfirewall from '@ohos.net.netFirewall';
```

## netFirewall.setNetFirewallPolicy

setNetFirewallPolicy(userId: number, policy: NetFirewallPolicy): Promise\<void>

设置防火墙状态。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_FIREWALL

**系统能力**：SystemCapability.Communication.NetManager.netfirewall

**参数：**

| 参数名 | 类型                                    | 必填 | 说明                          |
| ------ | ----------------------------------------| ---- | ----------------------------- |
| userId | number                                  | 是   | 用户ID，不能是不存在的ID。    |
| policy | [NetFirewallPolicy](#NetFirewallPolicy) | 是   | 设置的防火墙策略              |

**返回值：**

| 类型                | 说明                                     |
| ------------------- | ---------------------------------------- |
| Promise\<void>      | 返回空。                                 |

**错误码：**

| 错误码ID | 错误信息                                             |
| -------  | ----------------------------------------------------|
| 201      | Permission denied.                                  |
| 202      | Non-system applications use system APIs.            |
| 401      | Parameter error.                                    |
| 2100001  | Invalid parameter value.                            |
| 2100002  | Operation failed. Cannot connect to service.        |
| 2100003  | System internal error.                              |
| 29400000 | The specified user does not exist.                  |

**示例：**

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

查询防火墙状态。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NET_FIREWALL

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

**参数：**

| 参数名   | 类型                   | 必填 | 说明                         |
| -------- | ---------------------- | ---- | ---------------------------- |
| userId   | number                 | 是   | 用户ID，不能是不存在的ID。   |

**返回值：**

| 类型                                              | 说明                |
| ------------------------------------------------- | --------------------|
| Promise\<[NetFirewallPolicy](#NetFirewallPolicy)> | 当前用户防火墙策略。|


**错误码：**

| 错误码ID | 错误信息                                            | 
| -------  | ----------------------------------------------------|
| 201      | Permission denied.                                  |
| 202      | Non-system applications use system APIs.            |
| 401      | Parameter error.                                    |
| 2100001  | Invalid parameter value.                            |
| 2100002  | Operation failed. Cannot connect to service.        |
| 2100003  | System internal error.                              |
| 29400000 | The specified user does not exist.                  |

**示例：**

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

添加防火墙规则。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_FIREWALL

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

**参数：**

| 参数名   | 类型                                              | 必填 | 说明         |
| -------- | ------------------------------------------------- | ---- | ------------ |
| rule    |  [NetFirewallRule](#NetFirewallRule)               | 是   | 防火墙规则   |

**返回值：**

| 类型                      | 说明                     	                             |
| ------------------------- | ------------------------------------------------------ |
| Promise\<number>   	    | 防火墙规则ID，由系统自动生成。                         |

**错误码：**

| 错误码ID | 错误信息                                                                |
| -------  | ----------------------------------------------------------------------  |
| 201      | Permission denied.        						     |
| 202      | Non-system applications use system APIs.                                |
| 401      | Parameter error.                                                        |
| 2100001  | Invalid parameter value.                                                |
| 2100002  | Operation failed. Cannot connect to service.                            |
| 2100003  | System internal error.                                                  |
| 29400000 | The specified user does not exist.                                      |
| 29400001 | The number of firewall rules exceeds the maximum.                       |
| 29400002 | The number of IP address rules in the firewall rule exceeds the maximum.|
| 29400003 | The number of port rules in the firewall rule exceeds the maximum.	     |
| 29400004 | The number of domain rules in the firewall rule exceeds the maximum.    |
| 29400005 | The number of domain rules exceeds the maximum.			     |
| 29400007 | The dns rule is duplication.					     |

**示例：**

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

更新防火墙规则。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_FIREWALL

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

**参数：**

| 参数名  | 类型                                   | 必填 | 说明                             |
| ------- | -------------------------------------- | ---- | -------------------------------- |
| rule    | [NetFirewallRule](#NetFirewallRule)    | 是   | 防火墙规则                       |

**返回值：**

| 类型                 | 说明                                                                |
| -------------------  | ------------------------------------------------------------------- |
| Promise\<void>       | 返回空。                                                            |

**错误码：**

| 错误码ID | 错误信息                                                                        |
| -------  | --------------------------------------------------------------------------------|
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
  
**示例：**

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

删除防火墙规则。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_FIREWALL

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

**参数：**

| 参数名   | 类型                             | 必填 | 说明                                  |
| -------- | -------------------------------- | ---- | ------------------------------------- |
| rule     | NetFirewallRule                  | 是   | 防火墙规则                            |
| userId   | number                           | 是   | 用户ID，不能是不存在的ID。            |
| ruleId   | number                           | 是   | 防火墙规则ID                          |

**返回值：**

| 类型                | 说明                                                                 |
| ------------------- | ---------------------------------------------------------------------|
| Promise\<void>      | 返回空。                                                             |

**错误码：**

| 错误码ID | 错误信息                                                                        |
| -------  | --------------------------------------------------------------------------------|
| 201      | Permission denied.                                                              |
| 202      | Non-system applications use system APIs.                                        |
| 401      | Parameter error.                                                                |
| 2100001  | Invalid parameter value.                                                        |
| 2100002  | Operation failed. Cannot connect to service.                                    |
| 2100003  | System internal error.                                                          |
| 29400000 | The specified user does not exist.                                              |
| 29400006 | The specified rule does not exist.                                              |
  
**示例：**

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

按userId获取防火墙规则，需要指定分页查询参数。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NET_FIREWALL

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

**参数：**

| 参数名          | 类型                           | 必填 | 说明                             |
| --------------- | ------------------------------ | ---- | -------------------------------- |
| userId          | number                         | 是   | 用户ID，不能是不存在的ID。       |
| requestParam    | [RequestParam](#RequestParam)  | 是   | 分页查询参数。                   |

**返回值：**

| 类型                                              | 说明                                   |
| ------------------------------------------------- | ---------------------------------------|
| Promise\<[FirewallRulePage](#FirewallRulePage)>   | 防火墙分页规则列表。                   |

**错误码：**

| 错误码ID | 错误信息                                                                        |
| -------  | --------------------------------------------------------------------------------|
| 201      | Permission denied.                                                              |
| 202      | Non-system applications use system APIs.                                        |
| 401      | Parameter error.                                                                |
| 2100001  | Invalid parameter value.                                                        |
| 2100002  | Operation failed. Cannot connect to service.                                    |
| 2100003  | System internal error.                                                          |
| 29400000 | The specified user does not exist.                                              |
  
**示例：**

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

通过userId和ruleId获取指定的防火墙规则。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NET_FIREWALL

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                              |
| -------- | ------------------------------------ | ---- | --------------------------------- |
| userId   | number                               | 是   | 用户ID，不能是没有的ID。          |
| ruleId   | number                               | 是   | 防火墙规则ID                      |

**返回值：**

| 类型                         		          | 说明                                     |
| ----------------------------------------------- | ---------------------------------------- |
| Promise\<[NetFirewallRule](#NetFirewallRule)>   | 返回防火墙规则。                         |

**错误码：**

| 错误码ID | 错误信息                                                                        |
| -------  | --------------------------------------------------------------------------------|
| 201      | Permission denied.                                                              |
| 202      | Non-system applications use system APIs.                                        |
| 401      | Parameter error.                                                                |
| 2100001  | Invalid parameter value.                                                        |
| 2100002  | Operation failed. Cannot connect to service.                                    |
| 2100003  | System internal error.                                                          |
| 29400000 | The specified user does not exist.                                              |
| 29400006 | The specified rule does not exist.                                              |
  
**示例：**

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

按userId获取截获的记录，需要指定分页查询参数。。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NET_FIREWALL

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

**参数：**

| 参数名           | 类型                             | 必填 | 说明                         |
| -------------- | ---------------------------------  | ---- | ---------------------------- |
| userId         | number                             | 是   | 用户ID，不能是没有的ID。     |
| requestParam   |  [RequestParam](#RequestParam)     | 是   | 查询参数                     |

**返回值：**

| 类型                                                       | 说明                          |
| ---------------------------------------------------------- | ----------------------------- |
| Promise\<[InterceptedRecordPage](#InterceptedRecordPage)>  | 拦截记录列表.                 |

**错误码：**

| 错误码ID | 错误信息                                                                        |
| -------  | --------------------------------------------------------------------------------|
| 201      | Permission denied.                                                              |
| 202      | Non-system applications use system APIs.                                        |
| 401      | Parameter error.                                                                |
| 2100001  | Invalid parameter value.                                                        |
| 2100002  | Operation failed. Cannot connect to service.                                    |
| 2100003  | System internal error.                                                          |
| 29400000 | The specified user does not exist.                                              |
  
**示例：**

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

防火墙规则拦截方向枚举。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

| 名称         | 值   | 说明 |
|--------------|------|------|
| RULE_IN      | 1    | 入站 |
| RULE_OUT     | 2    | 出站 |

## FirewallRuleAction

防火墙规则行动枚举。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

| 名称           | 值   | 说明 |
|----------------|------|------|
| RULE_ALLOW     | 0    | 允许 |
| RULE_DENY      | 1    | 拒绝 |

## NetFirewallRuleType

防火墙规则类型枚举。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

| 名称           | 值   | 说明       |
|----------------| ---- | -----------|
| RULE_IP        | 1    | IP类规则   |
| RULE_DOMAIN    | 2    | 域名类规则 |
| RULE_DNS       | 3    | DNS规则    |

## NetFirewallOrderField

防火墙规则排序类型枚举。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

| 名称                  | 值   | 说明                 |
| --------------------- | ---- | ---------- ----------|
| ORDER_BY_RULE_NAME    | 1    | 根据防火墙规则名排序 |
| ORDER_BY_RECORD_TIME  | 100  | 根据记录时间排序     |

## NetFirewallOrderType

防火墙规则排序类型枚举。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

| 名称                  | 值   | 说明 |
| --------------------- | ---- | -----|
| ORDER_ASC             | 1    | 升序 |
| ORDER_DESC            | 100  | 降序 |

## NetFirewallPolicy

防火墙状态。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

| 名称         | 类型                                       | 必填 | 说明        |
| ------------ | -------------------------------------------|------|-------------|
| isOpen       | boolean                                    | 是   | 防火墙开/关 |
| inAction     | [FirewallRuleAction](#FirewallRuleAction)  | 是   | 入站行动    |
| outAction    | [FirewallRuleAction](#FirewallRuleAction)  | 是   | 出站行动    |

## NetFirewallIpParams

防火墙规则ip参数。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

| 名称          | 类型   |必填| 说明                                                      |
| --------------| -------|----|---------------------------------------------------------- |
| type          | number | 是 | 1:IP地址或子网，当使用单个IP时，掩码为32; 2:IP段          |
| family        | number | 否 | IPv4=1, IPv6=2, 默认IPv4，其他当前不支持                  |
| address       | string | 否 | IP地址：当类型等于1时有效，否则将被忽略                   |
| mask          | number | 否 | IPv4:子网掩码，IPv6:前缀，当类型等于1时有效，否则将被忽略 |
| startIp       | string | 否 | 起始IP：当类型等于2时有效，否则将被忽略                   |
| endIp         | string | 否 | 结束IP: 当类型等于2时有效，否则将被忽略                   |

## NetFirewallPortParams

防火墙规则端口参数。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

| 名称         | 类型   | 必填 | 说明     |
| ------------ | -------|------|----------|
| startPort    | number | 是   | 开始端口 |
| endPort      | number | 是   | 结束端口 |

## NetFirewallDomainParams

防火墙规则域信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

| 名称         | 类型    | 必填 | 说明                                    |
| ------------ | --------|------|-----------------------------------------|
| isWildcard   | boolean | 是   | 是否包含通配符                          |
| domain       | string  | 是   | 当isWildcard为false时，需要确定的完整域 |

## NetFirewallDnsParams

防火墙规则DNS信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

| 名称         | 类型    | 必填 | 说明         |
| ------------ | --------|------|--------------|
| primaryDns   | string  | 是   | 主域名服务器 |
| standbyDns   | string  | 否   | 备份DNS      |


## NetFirewallRule

防火墙规则信息结构。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

| 名称        | 类型                                                        |必填| 说明                                                         |
| ------------|-------------------------------------------------------------|----|--------------------------------------------------------------|
| userId      | number                                                      | 是 | 用户ID                                                       |
| name        | string                                                      | 是 | 规则名称，必填，最多128个字符                                |
| direction   | [NetFirewallRuleDirection](#NetFirewallRuleDirection)       | 是 | 规则方向，入站或出站                                         |
| action      | [FirewallRuleAction](#FirewallRuleAction)                   | 是 | 行为                                                         |
| type        | [NetFirewallRuleType](#NetFirewallRuleType)                 | 是 | 规则类型                                                     |
| isEnabled   | boolean                                                     | 是 | 是否启用                                                     |
| id          | number                                                      | 否 | 规则ID                                                       |
| description | string                                                      | 否 | 规则描述，可选，最多256个字符                                |
| appUid      | number                                                      | 否 | 应用程序或服务UID                                            |
| localIps    | Array\<[NetFirewallIpParams](#NetFirewallIpParams)>         | 否 | 本地IP地址：ruleType=RULE_IP有效，否则忽略，最多10个         |
| remoteIps   | Array\<[NetFirewallIpParams](#NetFirewallIpParams)>         | 否 | 远端IP地址：当ruleType=RULE_IP时有效，否则将被忽略，最多10个 |
| protocol    | number                                                      | 否 | 协议，TCP:6，UDP:17，当ruleType=RULE_IP时有效，否则将被忽略  |
| localPorts  | Array\<[NetFirewallPortParams](#NetFirewallPortParams)>     | 否 | 本地端口：当ruleType=RULE_IP时有效，否则将被忽略，最多10个   |
| remotePorts | Array\<[NetFirewallPortParams](#NetFirewallPortParams)>     | 否 | 远端端口：当ruleType=RULE_IP时有效，否则将被忽略，最多10个   |
| domains     | Array\<[NetFirewallDomainParams](#NetFirewallDomainParams)> | 否 | 域名列表：当ruleType=RULE_DOMAIN时有效，否则将被忽略         |
| dns         | [NetFirewallDnsParams](#NetFirewallDnsParams)               | 否 | DNS:当ruleType=RULE_DNS时有效，否则将被忽略                  |

## InterceptRecord

拦截记录信息结构。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

| 名称       | 类型   | 必填 | 说明              |
|------------| -------|------|------------------ |
| time       | number | 是   | 时间戳            |
| localIp    | string | 否   | 本地IP            |
| remoteIp   | string | 否   | 远端IP            |
| localPort  | number | 否   | 本地端口          |
| remotePort | number | 否   | 远端端口          |
| protocol   | number | 否   | 传输层协议        |
| appUid     | number | 否   | 应用程序或服务UID |
| domain     | string | 否   | 域名              |


## RequestParam

查询输入信息结构。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

| 名称       | 类型                                             | 必填 | 说明                      |
|------------|--------------------------------------------------|------|---------------------------|
| page       | number                                           | 是   | 页码，值范围：[1,1000]    |
| pageSize   | number                                           | 是   | 页面大小，值范围：[1,50]  |
| orderField | [NetFirewallOrderField](#NetFirewallOrderField)  | 是   | 排序字段                  |
| orderType  | [NetFirewallOrderType](#NetFirewallOrderType)    | 是   | 排序顺序                  |
## FirewallRulePage

防火墙规则页信息结构。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

| 名称       | 类型                   | 必填 | 说明                               |
|------------|-------------------------------------------- |------|---------------|
| page       | number                                      | 是   | 当前页码      |
| pageSize   | number                                      | 是   | 页大小        |
| totalPage  | number                                      | 是   | 总页数        |
| data       | Array\<[NetFirewallRule](#NetFirewallRule)> | 是   | 页面数据      |

## InterceptedRecordPage

拦截记录分页信息结构。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.NetFirewall

| 名称       | 类型                                            | 必填 | 说明     |
|------------| ----------------------------------------------- |------|--------- |
| page       | number                                          | 是   | 当前页码 |
| pageSize   | number                                          | 是   | 页面大小 |
| totalPage  | number                                          | 是   | 总页数   |
| data       | Array\<[InterceptedRecord](#InterceptedRecord)> | 是   | 页面数据 |
