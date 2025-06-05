# Network Firewall

## Introduction

The network firewall module provides the following functions:
- Basic firewall management functions, such as enabling and disabling of firewalls and firewall rules, and audit.
- Firewall rule configuration, including the rule name, description, operation, applicable application, protocol type, address, port, and outbound/inbound direction.
- DNS policy configuration, including the domain names allowed or not allowed for resolution and the DNS server (active or standby) used for resolution (application level).

> **NOTE**
> To maximize the application running efficiency, all APIs are called asynchronously in callback or promise mode. The following code examples use the promise mode. For details about the APIs, see [API Reference](../reference/apis-network-kit/js-apis-net-netfirewall.md).

## **Constraints**

- Programming language: JS

## When to Use

Typical firewall scenarios include:
- IP address-based access control
1. Restricting network access for specific applications
2. Restricting network communication to specific IP addresses, protocols, and ports
3. Restricting network communication of specific applications to specific IP addresses, protocols, and ports
4. Putting interception rules into effect immediately after delivery (This function is applicable only to the TCP protocol. An intercepted TCP connection must be disconnected.)
- Domain name-based access control
1. Restricting DNS resolution of an application for specific domain names (This function is applicable to standard unencrypted DNS protocols, but not encrypted and private DNS protocols.)
2. Restricting DNS resolution of specific applications for specific domain names (This function is applicable to standard unencrypted DNS protocols, but not encrypted and private DNS protocols.)
3. Putting interception rules into effect immediately after delivery (This function is applicable only to the TCP protocol. An intercepted TCP connection must be disconnected.)
<!--Del-->
- Traceable network access
1. Query of interception records for system applications
2. Automatic saving of interception rules and automatic recovery upon startup
<!--DelEnd-->

The following describes the development procedure specific to each application scenario.

## Available APIs

For the complete list of APIs and example code, see [Network Firewall](../reference/apis-network-kit/js-apis-net-netfirewall.md).

| Name                                                                                              | Description             |
| -------------------------------------------------------------------------------------------------- | ----------------- |
| setNetFirewallPolicy(userId: number, policy: NetFirewallPolicy): Promise\<void>                    | Sets a firewall policy.   |
| getNetFirewallPolicy(userId: number): Promise\<NetFirewallPolicy>                                  | Obtains a firewall policy.   |
| addNetFirewallRule(rule: NetFirewallRule): Promise\<number>                                        | Adds a firewall rule.   |
| updateNetFirewallRule(rule: NetFirewallRule): Promise\<void>                                       | Updates a firewall rule.  |
| removeNetFirewallRule(userId: number, ruleId: number): Promise\<void>                              | Removes a firewall rule.   |
| getNetFirewallRules(userId: number, requestParam: RequestParam): Promise\<FirewallRulePage>        | Performs pagination query on firewall rules.|
| getNetFirewallRule(userId: number, ruleId: number): Promise\<NetFirewallRule>                      | Queries a firewall rule.|
| <!--DelRow-->getInterceptedRecords(userId: number, requestParam: RequestParam): Promise\<InterceptedRecordPage> | Queries firewall interception records.|

## IP address-based access control

1. Use a network cable to connect the device to a network port.
2. Import the **netFirewall** namespace from **@kit.NetworkKit**.
3. Call **setNetFirewallPolicy** to enable the firewall.
4. Call **addNetFirewallRule** to add firewall rules.

```ts
// Import the netFirewall namespace from @kit.NetworkKit.
import { netFirewall } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

interface IpType{
      family:number;
      type:number;
      address?:string;
      mask?:number;
      startIp?:string;
      endIp?:string;
}
interface IpPort{
    startPort:number;
    endPort:number;
}

// Define the firewall policy to enable the firewall and deny inbound traffic while allowing outbound traffic.
let policy: netFirewall.NetFirewallPolicy = {
  isOpen: true,
  inAction: netFirewall.FirewallRuleAction.RULE_DENY,
  outAction: netFirewall.FirewallRuleAction.RULE_ALLOW
};
// Set the firewall policy for user 100.
netFirewall.setNetFirewallPolicy(100, policy).then(() => {
  console.info("set firewall policy success.");
}).catch((error : BusinessError) => {
  console.error("set firewall policy failed: " + JSON.stringify(error));
});

// Initialize firewall rules for specific types of IP addresses.
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
    }] as IpType[],
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
    }] as IpType[],
  protocol: 6,
  localPorts: [
    {
      startPort: 1000,
      endPort: 1000
    },{
      startPort: 2000,
      endPort: 2001
    }] as IpPort[],
  remotePorts: [
    {
      startPort: 443,
      endPort: 443
    }] as IpPort[],
  userId: 100
};
// Add firewall rules.
netFirewall.addNetFirewallRule(ipRule).then((result: number) => {
  console.info('rule Id: ', result);
}, (reason: BusinessError) => {
  console.error('add firewall rule failed: ', JSON.stringify(reason));
});
```

## Domain Name-based Access Control

1. Use a network cable to connect the device to a network port.
2. Import the **netFirewall** namespace from **@kit.NetworkKit**.
3. Call **setNetFirewallPolicy** to enable the firewall in user mode.
4. Call **addNetFirewallRule** to add firewall rules in user mode.

```ts
// Import the netFirewall namespace from @kit.NetworkKit.
import { netFirewall } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

interface domain{
    isWildcard: boolean;
    domain: string;
}

// Define the firewall policy to enable the firewall and deny inbound traffic while allowing outbound traffic.
let policy: netFirewall.NetFirewallPolicy = {
  isOpen: true,
  inAction: netFirewall.FirewallRuleAction.RULE_DENY,
  outAction: netFirewall.FirewallRuleAction.RULE_ALLOW
};
// Set the firewall policy for user 100.
netFirewall.setNetFirewallPolicy(100, policy).then(() => {
  console.info("set firewall policy success.");
}).catch((error : BusinessError) => {
  console.error("set firewall policy failed: " + JSON.stringify(error));
});

// Initialize firewall rules for specific types of domain names.
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
    }] as domain[],
  userId: 100
};
// Add firewall rules.
netFirewall.addNetFirewallRule(domainRule).then((result: number) => {
  console.info('rule Id: ', result);
}, (reason: BusinessError) => {
  console.error('add firewall rule failed: ', JSON.stringify(reason));
});
```

<!--Del-->
## Query of Firewall Interception Records

1. Use a network cable to connect the device to a network port.
2. Import the **netFirewall** namespace from **@kit.NetworkKit**.
3. Call **getInterceptRecords** to query firewall interception records in user mode.

```ts
// Import the netFirewall namespace from @kit.NetworkKit.
import { netFirewall } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Call getInterceptedRecords to perform pagination query on firewall interception records.
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
