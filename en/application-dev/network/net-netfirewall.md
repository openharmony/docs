# Using the Network Firewall

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=347d255af45ee8903284b9e542c2eff6d5717de4 translatedAt=2026-08-13T03:08:57.932Z pushedAt=2026-08-13T06:38:25.675Z -->

## Introduction

The network firewall module provides the following functions:

- Basic firewall management functions, such as enabling and disabling of firewalls and firewall rules, and audit.

- Firewall rule configuration, including the rule name, description, operation, applicable application, protocol type, address, port, and outbound/inbound direction.

- DNS policy configuration, including the domain names allowed or not allowed for resolution and the DNS server (active or standby) used for resolution (application level).

> **NOTE**
> To ensure app running efficiency, all API calls are asynchronous. For asynchronous APIs, a promise is provided. The following examples use the promise mode. For more modes, see [@ohos.net.netFirewall (Network Firewall)](../reference/apis-network-kit/js-apis-net-netfirewall.md).

## When to Use

Typical firewall scenarios include:

- IP address-based access control

1. Restricting network access for specific applications

2. Restricting network communication to specific IP addresses, protocols, ports, and physical NICs.

3. Restricting network communication of specific applications to specific IP addresses, protocols, ports, and physical NICs.

4. Applying interception rules immediately after they are delivered. For TCP, any existing intercepted TCP connections must be disconnected.

- Domain name-based access control

1. Restricting DNS resolution for specific domain names. Only standard unencrypted DNS is restricted. Encrypted DNS and private DNS are not affected.

2. Restricting DNS resolution for specific domain names by specific applications. Only standard unencrypted DNS is restricted. Encrypted DNS and private DNS are not affected.

3. Applying interception rules immediately after they are delivered. For TCP, any existing intercepted TCP connections must be disconnected.

<!--Del-->

- Traceable network access

1. Query of interception records for system applications

2. Automatic saving of interception rules and automatic recovery upon startup

<!--DelEnd-->

The following describes the development procedure specific to each application scenario.

## IP address-based access control

1. Use a network cable to connect the device to a network port.

2. Import the **netFirewall** namespace from **@kit.NetworkKit**.

   <!-- @[net_firewall_case_import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetFireWall_case/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // Import the netFirewall namespace from @kit.NetworkKit.
   import { netFirewall } from '@kit.NetworkKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

3. Call **setNetFirewallPolicy** to enable the firewall.

   <!-- @[net_firewall_set_net_firewall_policy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetFireWall_case/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // IP address type
   interface IpType{
     family:number;
     type:number;
     address?:string;
     mask?:number;
     startIp?:string;
     endIp?:string;
   }
   // Port number
   interface IpPort{
     startPort:number;
     endPort:number;
   }
   // ...
       // Define the firewall policy to enable the firewall and deny inbound traffic while allowing outbound traffic.
       let policy: netFirewall.NetFirewallPolicy = {
         isOpen: true,
         inAction: netFirewall.FirewallRuleAction.RULE_DENY,
         outAction: netFirewall.FirewallRuleAction.RULE_ALLOW
       };
   
       // Set the firewall policy for user 100.
       netFirewall.setNetFirewallPolicy(100, policy).then(() => {
         hilog.info(0x0000, 'testTag', `set firewall policy success.`);
       }).catch((error : BusinessError) => {
         hilog.error(0x0000, 'testTag', `error: set firewall policy failed: ${JSON.stringify(error)}`);
       });
   ```

4. Call **addNetFirewallRule** to add firewall rules.

   <!-- @[net_firewall_add_net_firewall_rule](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetFireWall_case/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // Initialize firewall rules for specific types of IP addresses.
   let ipRule: netFirewall.NetFirewallRule = {
     name: 'rule1',
     description: 'rule1 description',
     direction: netFirewall.NetFirewallRuleDirection.RULE_IN,
     action: netFirewall.FirewallRuleAction.RULE_DENY,
     type: netFirewall.NetFirewallRuleType.RULE_IP,
     isEnabled: true,
     appUid: 20001,
     localIps: [
       {
         family: 1,
         type: 1,
         address: '10.10.1.1',
         mask: 32
       },{
       family: 1,
       type: 2,
       startIp: '10.20.1.1',
       endIp: '10.20.1.10'
     }] as IpType[],
     remoteIps:[
       {
         family: 1,
         type: 1,
         address: '20.10.1.1',
         mask: 32
       },{
       family: 1,
       type: 2,
       startIp: '20.20.1.1',
       endIp: '20.20.1.10'
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
     userId: 100,
     interface:'wlan0' // Supported since API version 26.0.0.
   };
   // Add firewall rules.
   netFirewall.addNetFirewallRule(ipRule).then((result: number) => {
     // ...
     hilog.info(0x0000, 'testTag', `rule Id: ${result}`);
   }, (reason: BusinessError) => {
     // ...
     hilog.error(0x0000, 'testTag', `error: add firewall rule failed:  ${JSON.stringify(reason)}`);
   });
   ```

## Domain Name-based Access Control

1. Use a network cable to connect the device to a network port.

2. Import the **netFirewall** namespace from **@kit.NetworkKit**.

   <!-- @[net_firewall_case_import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetFireWall_case/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // Import the netFirewall namespace from @kit.NetworkKit.
   import { netFirewall } from '@kit.NetworkKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

3. Call **setNetFirewallPolicy** to enable the firewall.

   <!-- @[net_firewall_set_net_firewall_policy_domain_names](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetFireWall_case/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   interface domain{
     isWildcard: boolean;
     domain: string;
   }
   // ...
       // Define the firewall policy to enable the firewall and deny inbound traffic while allowing outbound traffic.
       let policy: netFirewall.NetFirewallPolicy = {
         isOpen: true,
         inAction: netFirewall.FirewallRuleAction.RULE_DENY,
         outAction: netFirewall.FirewallRuleAction.RULE_ALLOW
       };
   
       // Set the firewall policy for user 100.
       netFirewall.setNetFirewallPolicy(100, policy).then(() => {
         hilog.info(0x0000, 'testTag', `set firewall policy success.`);
       }).catch((error : BusinessError) => {
         hilog.error(0x0000, 'testTag', `error: set firewall policy failed: ${JSON.stringify(error)}`);
       });
   ```

4. Call **addNetFirewallRule** to add firewall rules.

   <!-- @[net_firewall_add_net_firewall_rule_domain_names](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_NetManager/NetFireWall_case/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // Initialize firewall rules for specific types of domain names.
   let domainRule: netFirewall.NetFirewallRule = {
     name: 'rule2',
     description: 'rule2 description',
     direction: netFirewall.NetFirewallRuleDirection.RULE_IN,
     action: netFirewall.FirewallRuleAction.RULE_DENY,
     type: netFirewall.NetFirewallRuleType.RULE_DOMAIN,
     isEnabled: true,
     appUid: 20002,
     domains: [
       {
         isWildcard: false,
         domain: 'www.HarmonyOS.cn'
       },{
       isWildcard: true,
       domain: '*.HarmonyOS.cn'
     }] as domain[],
     userId: 100,
     interface:'wlan0' // Supported since API version 26.0.0.
   };
   
   // Add firewall rules.
   netFirewall.addNetFirewallRule(domainRule).then((result: number) => {
     // ...
     hilog.info(0x0000, 'testTag', `rule Id: ${result}`);
   }, (reason: BusinessError) => {
     // ...
     hilog.error(0x0000, 'testTag', `error: add firewall rule failed:  ${JSON.stringify(reason)}`);
   });
   ```

<!--Del-->

## Query of Firewall Interception Records

1. Use a network cable to connect the device to a network port.

2. Import the **netFirewall** namespace from **@kit.NetworkKit**.

    ```ts
    // Import the netFirewall namespace from @kit.NetworkKit.
    import { netFirewall } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

3. Call **getInterceptRecords** to query firewall interception records in user mode.

    ```ts
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