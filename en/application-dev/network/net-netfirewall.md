# @ohos.net.netFirewall (Network firewall) (System interface)

## Synopsis
The network firewall provides the following functions :
- The basic capabilities of firewalls,including enabling firewalls, enabling and disabling rules, and auditing capabilities.
- The ability to configure firewall rules,including the name, description, operation, effective application, protocol type, address, port, outbound/inbound direction, etc. of the rule.
- The ability to configure DNS policies,include configuring domain names that are prohibited/allowed for resolution,analyze the DNS server used (Primary/alternative) (application level).

>**Explain:**
>To ensure the efficiency of application operation, All API calls are asynchronous, and a Promise method is provided for asynchronous API calls.The following examples all use the promise method,for more information, please refer to [API Reference](../reference/apis-network-kit/js-apis-net-netfirewall.md).

## Constraint

- Development language : JS
- The first batch of interfaces in this module will be supported starting from API version 12.Subsequent versions of the newly added interface will use superscripts to separately mark the starting version of the interface.

## Application scenarios

Typical scenarios for firewalls include :
- Targeting specific IP networking access control.
1. Support restricting specific applications from accessing the network.
2. Support restricting network communication to specific IPs, protocols, and ports.
3. Support restricting network communication between specific applications and specific IPs, protocols, and ports.
4. Support interception rules to take effect immediately after they are issued (This point applies to the TCP protocol: it is necessary to disconnect existing intercepted TCP connections).
- Support interception for domain name networking access control
1. Support limiting the DNS resolution capability of applications for specific domain names (Restrict non encrypted standard DNS protocols only, do not restrict encrypted or private DNS protocols).
2. Support limiting the DNS resolution capability of specific domain names for specific applications (Restrict non encrypted standard DNS protocols only, do not restrict encrypted or private DNS protocols).
3. Support interception rules to take effect immediately after they are issued (This point applies to the TCP protocol: it is necessary to disconnect existing intercepted TCP connections).
- Network access control traceability
1. Support intercepting and dropping records, and provide the ability to query intercepted records for system applications.
2. Supports automatic saving of all interception rules and automatic recovery upon startup.

The specific development methods are introduced below.

## Interface Description

Please refer to the complete JS API description and instance code for reference : [network firewall](../reference/apis-network-kit/js-apis-net-netfirewall.md).

| Interface                                                                                          | Describe                                                             |
| -------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------- |
| setNetFirewallPolicy(userId: number, policy: NetFirewallPolicy): Promise\<void>                    | Set firewall policy.                                                 |
| getNetFirewallPolicy(userId: number): Promise\<NetFirewallPolicy>                                  | Check the policy of the firewall.                                    |
| addNetFirewallRule(rule: NetFirewallRule): Promise\<number>                                        | Add firewall rules.                                                  |
| updateNetFirewallRule(rule: NetFirewallRule): Promise\<void>                                       | Update firewall rules.                                               |
| removeNetFirewallRule(userId: number, ruleId: number): Promise\<void>                              | Delete firewall rules.                                               |
| getNetFirewallRules(userId: number, requestParam: RequestParam): Promise\<FirewallRulePage>        | Get firewall rules by userId, and it is necessary to specify the pagination query parameters. |
| getNetFirewallRule(userId: number, ruleId: number): Promise\<NetFirewallRule>                      | Get a specified firewall rule by userId and ruleId.                  |
| getInterceptedRecords(userId: number, requestParam: RequestParam): Promise\<InterceptedRecordPage> | Get intercepted records by userId, and it is necessary to specify the pagination query parameters. |

## Targeting specific IP networking access control

### Development steps

1. The device is plugged into a network cable through a hardware interface.
2. Import the netFirewall namespace from @ohos.net.netFirewall.
3. Call the setNetFirewallStatus method in user mode to open firewall.
4. Call the addNetFirewallRule method in user mode to add the firewall rules.

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
```

## Support interception for domain name networking access control

### Development steps

1. The device is plugged into a network cable through a hardware interface.
2. Import the netFirewall namespace from @ohos.net.netFirewall.
3. Call the setNetFirewallStatus method in user mode to open the firewall.
4. Call the addNetFirewallRule method in user mode to add firewall rules.

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
```

## Network access control traceability

### Development steps

1. The device is plugged into a network cable through a hardware interface.
2. Import the netFirewall namespace from @ohos.net.netFirewall.
3. Call the getAllInterceptRecords method in user mode to query interception records.

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
