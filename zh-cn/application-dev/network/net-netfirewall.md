# 网络防火墙

## 简介

网络防火墙提供如下功能：
- 防火墙的基础能力，包括防火墙的使能、规则的启用与禁用、审计能力。
- 防火墙规则的配置能力，包括规则的名称、描述、操作、生效应用、协议类型、地址、端口、出站/入站方向等。
- DNS策略的配置能力，包括配置禁止/允许解析的域名、解析使用的DNS服务器（主选/备选）（应用级）。

> **说明：**
>
> 为了保证应用的运行效率，所有API调用都是异步的，对于异步调用的API均提供了Promise的方式，以下示例均采用Promise方式，更多方式可以查阅[API参考](../reference/apis-network-kit/js-apis-net-netfirewall.md)。

## 约束

- 开发语言：JS

## 场景介绍

防火墙的典型场景有：
- 针对特定IP联网访问控制
1. 支持限制特定应用访问网络。
2. 支持限制对特定IP、特定协议、特定端口的网络通信。
3. 支持限制特定应用对特定IP、特定协议、特定端口的网络通信。
4. 支持拦截规则下发后立即生效（此点针对TCP协议：需断开已有被拦截的TCP连接）	。
- 针对域名联网访问控制支持拦截
1. 支持限制应用对特定域名的DNS解析能力（仅限制非加密标准DNS协议，不限制加密、私标DNS协议）。
2. 支持限制特地应用对特定域名的DNS解析能力（仅限制非加密标准DNS协议，不限制加密、私标DNS协议）。
3. 支持拦截规则下发后立即生效（此点针对TCP协议：需断开已有被拦截的TCP连接）。
<!--Del-->
- 联网访问控制支持可追溯
1. 支持拦截记录追溯，支持对系统应用提供查询拦截记录的能力。
2. 支持所有拦截规则的自动保存和开机自动恢复。
<!--DelEnd-->

以下分别介绍具体开发方式。

## 接口说明

完整的JS API说明以及实例代码请参考：[网络防火墙](../reference/apis-network-kit/js-apis-net-netfirewall.md)。

| 接口                                                                                               | 描述              |
| -------------------------------------------------------------------------------------------------- | ----------------- |
| setNetFirewallPolicy(userId: number, policy: NetFirewallPolicy): Promise\<void>                    | 设置防火墙状态。    |
| getNetFirewallPolicy(userId: number): Promise\<NetFirewallPolicy>                                  | 查询防火墙状态。    |
| addNetFirewallRule(rule: NetFirewallRule): Promise\<number>                                        | 添加防火墙规则。    |
| updateNetFirewallRule(rule: NetFirewallRule): Promise\<void>                                       | 更新防火墙规则。   |
| removeNetFirewallRule(userId: number, ruleId: number): Promise\<void>                              | 删除防火墙规则。    |
| getNetFirewallRules(userId: number, requestParam: RequestParam): Promise\<FirewallRulePage>        | 分页查询防火墙规则。 |
| getNetFirewallRule(userId: number, ruleId: number): Promise\<NetFirewallRule>                      | 查询单条防火墙规则。 |
| <!--DelRow-->getInterceptedRecords(userId: number, requestParam: RequestParam): Promise\<InterceptedRecordPage> | 查询防火墙拦截记录。 |

## 针对特定IP联网访问控制

1. 设备通过硬件接口，插入网线。
2. 从@kit.NetworkKit中导入netfirewall命名空间。
3. 用户调用setNetFirewallPolicy方法，打开防火墙。
4. 用户通过addNetFirewallRule方法，添加防火墙规则。

```ts
// 从@kit.NetworkKit中导入netFirewall命名空间
import { netFirewall } '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 定义防火墙策略：打开，入站阻止，出站允许
let policy: netFirewall.NetFirewallPolicy = {
  isOpen: true,
  inAction: netFirewall.FirewallRuleAction.RULE_DENY,
  outAction: netFirewall.FirewallRuleAction.RULE_ALLOW
};
// 给用户100设置防火墙策略
netFirewall.setNetFirewallPolicy(100, policy).then(() => {
  console.info("set firewall policy success.");
}).catch((error : BusinessError) => {
  console.error("set firewall policy failed: " + JSON.stringify(error));
});

// 初始化具体的防火墙ip类型规则
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
// 添加防火墙规则
netFirewall.addNetFirewallRule(ipRule).then((result: number) => {
  console.info('rule Id: ', result);
}, (reason: BusinessError) => {
  console.error('add firewall rule failed: ', JSON.stringify(reason));
});
```

## 针对域名联网访问控制支持拦截

1. 设备通过硬件接口，插入网线。
2. 从@kit.NetworkKit中导入netFirewall命名空间。
3. 用户态调用setNetFirewallPolicy方法，打开防火墙。
4. 用户态通过addNetFirewallRule方法，添加防火墙规则。

```ts
// 从@kit.NetworkKit中导入netFirewall命名空间
import { netFirewall } '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 定义防火墙策略：打开，入站阻止，出站允许
let policy: netFirewall.NetFirewallPolicy = {
  isOpen: true,
  inAction: netFirewall.FirewallRuleAction.RULE_DENY,
  outAction: netFirewall.FirewallRuleAction.RULE_ALLOW
};
// 给用户100设置防火墙策略
netFirewall.setNetFirewallPolicy(100, policy).then(() => {
  console.info("set firewall policy success.");
}).catch((error : BusinessError) => {
  console.error("set firewall policy failed: " + JSON.stringify(error));
});

// 初始化具体的防火墙域名类型规则
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
// 添加防火墙规则
netFirewall.addNetFirewallRule(domainRule).then((result: number) => {
  console.info('rule Id: ', result);
}, (reason: BusinessError) => {
  console.error('add firewall rule failed: ', JSON.stringify(reason));
});
```

<!--Del-->
## 查询防火墙拦截记录

1. 设备通过硬件接口，插入网线。
2. 从@kit.NetworkKit中导入netfirewall命名空间。
3. 用户态通过getInterceptRecords方法查询拦截记录。

```ts
// 从@kit.NetworkKit中导入netFirewall命名空间
import { netFirewall } '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 通过getInterceptedRecords方法分页查询拦截记录
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
<!--DelEnd-->
