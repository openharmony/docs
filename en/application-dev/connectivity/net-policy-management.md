# Network Policy Management

## Introduction

The Network Policy Management module allows you to restrict network capabilities by setting network policies, including cellular network policy, sleep/power-saving mode policy, and background network policy, and to reset network policies as needed.

> **NOTE**
> To maximize the application running efficiency, most API calls are called asynchronously in callback or promise mode. The following code examples use the callback mode. For details about the APIs, see [sms API Reference](../reference/apis/js-apis-net-policy.md).

## Basic Concepts

- Sleep mode: A mode in which the system shuts down some idle components and peripherals to enter the low-power mode and restricts some applications from accessing the network.
- Power-saving mode: A mode in which the system disables certain functions and features to save power. When this mode is enabled, the system performance deteriorates and some applications are restricted from accessing the network.
- Traffic-saving mode: A mode in which the system restricts background applications that use the metering network. It is equivalent to the background network policy.
- Cellular network: A mobile communication network.
- Metering network: A mobile network with preconfigured traffic quota, WLAN network, or Ethernet network.

## **Constraints**

- Programming language: C++ and JS
- System: Linux kernel
- The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## When to Use

Typical application scenarios of network policy management are as follows:

- Managing the metering network policy: Set the metering network quota and obtain the configured metering network policy.
- Managing network access for an application in the background: Set and obtain the status of the background network restriction switch, and check whether the application indicated by the specified UID can access the network in the background.
- Managing the metering network access policy: Set and obtain the policy for the application indicated by the specified UID to access the metering network, and obtain the UIDs of the applications for which the policy is configured.
- Restoring network policies
- Checking whether an application indicated by the specified UID can access a metering or non-metering network
- Adding a UID to or removing a UID from the sleep mode allowlist, and obtaining the sleep mode allowlist
- Adding a UID to or removing a UID from the power-saving mode allowlist, and obtaining the power-saving mode allowlist
- Updating the network notification policy

The following describes the development procedure specific to each application scenario.

## Available APIs

For the complete list of APIs and example code, see [Network Policy Management](../reference/apis/js-apis-net-policy.md).

| Type| API| Description|
| ---- | ---- | ---- |
| ohos.net.policy | function setBackgroundPolicy(isAllowed: boolean, callback: AsyncCallback\<void>): void |Sets a background network policy. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function isBackgroundAllowed(callback: AsyncCallback\<boolean>): void; |Obtains the background network policy. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function setPolicyByUid(uid: number, policy: NetUidPolicy, callback: AsyncCallback\<void>): void; |Sets an application-specific network policy by **uid**. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function getPolicyByUid(uid: number, callback: AsyncCallback\<NetUidPolicy>): void;| Obtains an application-specific network policy by **uid**. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function getUidsByPolicy(policy: NetUidPolicy, callback: AsyncCallback\<Array\<number>>): void; | Obtains the UID array of applications configured with a certain application-specific network policy. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function getNetQuotaPolicies(callback: AsyncCallback\<Array\<NetQuotaPolicy>>): void; |Obtains the network quota policies. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>, callback: AsyncCallback\<void>): void; |Sets an array of network quota policies. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function restoreAllPolicies(iccid: string, callback: AsyncCallback\<void>): void; | Restores all the policies (cellular network, background network, firewall, and application-specific network policies) for the given SIM card. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function isUidNetAllowed(uid: number, isMetered: boolean, callback: AsyncCallback\<boolean>): void; | Checks whether an application is allowed to access metering or non-metering networks. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function isUidNetAllowed(uid: number, iface: string, callback: AsyncCallback\<boolean>): void; | Checks whether an application is allowed to access the given network. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function setDeviceIdleAllowList(uid: number, isAllowed: boolean, callback: AsyncCallback\<void>): void; | Sets whether to add an application to the device idle allowlist. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function getDeviceIdleAllowList(callback: AsyncCallback\<Array\<number>>): void; | Obtains the UID array of applications that are on the device idle allowlist. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function getBackgroundPolicyByUid(uid: number, callback: AsyncCallback\<NetBackgroundPolicy>): void; | Obtains the background network policies configured for the given application. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function resetPolicies(iccid: string, callback: AsyncCallback\<void>): void; | Restores all the policies (cellular network, background network, firewall, and application-specific network policies) for the given SIM card. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function updateRemindPolicy(netType: NetBearType, iccid: string, remindType: RemindType, callback: AsyncCallback\<void>): void; | Updates a reminder policy. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function setPowerSaveAllowList(uid: number, isAllowed: boolean, callback: AsyncCallback\<void>): void; | Sets whether to add an application to the power-saving allowlist. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function getPowerSaveAllowList(callback: AsyncCallback\<Array\<number>>): void; | Obtains the UID array of applications that are on the power-saving allowlist. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function on(type: "netUidPolicyChange", callback: Callback\<{ uid: number, policy: NetUidPolicy }>): void; | Subscribes to policy changes. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function off(type: "netUidPolicyChange", callback: Callback\<{ uid: number, policy: NetUidPolicy }>): void; | Unsubscribes from policy changes. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function on(type: "netUidRuleChange", callback: Callback\<{ uid: number, rule: NetUidRule }>): void; | Subscribes to rule changes. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function off(type: "netUidRuleChange", callback: Callback\<{ uid: number, rule: NetUidRule }>): void; | Unsubscribes from rule changes. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function on(type: "netMeteredIfacesChange", callback: Callback\<Array\<string>>): void; | Subscribes to metered **iface** changes. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function off(type: "netMeteredIfacesChange", callback: Callback\<Array\<string>>): void; | Unsubscribes from metered **iface** changes. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function on(type: "netQuotaPolicyChange", callback: Callback\<Array\<NetQuotaPolicy>>): void; | Subscribes to network quota policy changes. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function off(type: "netQuotaPolicyChange", callback: Callback\<Array\<NetQuotaPolicy>>): void; | Unsubscribes from network quota policy changes. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function on(type: "netBackgroundPolicyChange", callback: Callback\<boolean>): void; | Subscribes to background network policy changes. This API uses an asynchronous callback to return the result.|
| ohos.net.policy | function off(type: "netBackgroundPolicyChange", callback: Callback\<boolean>): void; | Unsubscribes from background network policy changes. This API uses an asynchronous callback to return the result.|

## Managing the Metering Network Policy

1. Import the **policy** namespace from **@ohos.net.policy.d.ts**.

2. Call **setNetQuotaPolicies** to configure the metering network policy.

3. Call **getNetQuotaPolicies** to obtain the configured metering network policy.

```js
   // Import the policy namespace.
   import policy from '@ohos.net.policy';

   addNetQuotaPolicy(){
       let param = {
           // For details about the value of netType, see [NetBearType](../reference/apis/js-apis-net-connection.md#netbeartype).
           netType:Number.parseInt(this.netType),

           // Integrated circuit card identifier (ICCID) of the SIM card on the metering cellular network. It is not available for an Ethernet or Wi-Fi network.
           iccid:this.iccid,

           // Used together with ICCID on the metering cellular network. It is used independently on an Ethernet or Wi-Fi network.
           ident:this.ident,

           // Metering start time, for example, M1, D1, and Y1.
           periodDuration:this.periodDuration,

           // Set the traffic threshold for generating an alarm to an integer greater than 0.
           warningBytes:Number.parseInt(this.warningBytes),

           // Set the traffic quota to an integer greater than 0.
           limitBytes:Number.parseInt(this.limitBytes),

           // Specify whether the network is a metering network. The value true means a metering network and false means a non-metering network.
           metered:Boolean(Number.parseInt(this.metered)),https://gitee.com/openharmony/docs/pulls/14404
           // For details about the action triggered after the traffic limit is reached, see [LimitAction](../reference/apis/js-apis-net-policy.md#limitation).
           limitAction:Number.parseInt(this.limitAction)
       };
       this.netQuotaPolicyList.push(param);
   },

   // Subscribe to metered iface changes.
   policy.on('netMeteredIfacesChange', (data) => {
       this.log('on netMeteredIfacesChange: ' + JSON.stringify(data));
   });

   // Subscribe to metering network policy changes.
   policy.on('netQuotaPolicyChange', (data) => {
       this.log('on netQuotaPolicyChange: ' + JSON.stringify(data));
   });

   // Call setNetQuotaPolicies to configure the metering network policy.
   setNetQuotaPolicies(){
       this.dialogType = DialogType.HIDE;
       policy.setNetQuotaPolicies(this.netQuotaPolicyList, (err, data) => {
           console.log(JSON.stringify(err));
           console.log(JSON.stringify(data));
       });
   },

   // Call getNetQuotaPolicies to obtain the configured metering network policy.
   getNetQuotaPolicies(){
       policy.getNetQuotaPolicies((err, data) => {
           this.callBack(err, data);
           if(data){
               this.netQuotaPolicyList = data;
           }
       });
   },

   // Unsubscribe from metered iface changes.
   policy.off('netMeteredIfacesChange', (data) => {
       this.log('off netMeteredIfacesChange: ' + JSON.stringify(data));
   });

   // Unsubscribe from metering network policy changes.
   policy.off('netQuotaPolicyChange', (data) => {
       this.log('off netQuotaPolicyChange: ' + JSON.stringify(data));
   });
```

## Managing Network Access for an Application in the Background 

### How to Develop

1. Import the **policy** namespace from **@ohos.net.policy.d.ts**.

2. Call **setBackgroundAllowed** to enable or disable the background network restriction switch.

3. Call **isBackgroundAllowed** to check whether the background network restriction switch is enabled or disabled.

4. Call **getBackgroundPolicyByUid** to check whether the application indicated b the specified UID can access the network in the background.

```js
   // Import the policy namespace.
   import policy from '@ohos.net.policy'

   // Subscribe to background network policy changes.
   policy.on('netBackgroundPolicyChange', (data) => {
       this.log('on netBackgroundPolicyChange: ' + JSON.stringify(data));
   });

   // Call setBackgroundAllowed to enable or disable the background network restriction switch.
   setBackgroundAllowed() {
       policy.setBackgroundAllowed(Boolean(Number.parseInt(this.isBoolean)), (err, data) => {
           console.log(JSON.stringify(err));
           console.log(JSON.stringify(data))
       });
   },

   // Call isBackgroundAllowed to check whether the background network restriction switch is enabled or disabled.
   isBackgroundAllowed() {
        policy.isBackgroundAllowed((err, data) => {
            console.log(JSON.stringify(err));
            console.log(JSON.stringify(data))
        });
   },

   // Call getBackgroundPolicyByUid to check whether the application indicated b the specified UID can access the network in the background.
   getBackgroundPolicyByUid() {
       policy.getBackgroundPolicyByUid(Number.parseInt(this.firstParam), (err, data) => {
           console.log(JSON.stringify(err));
           console.log(JSON.stringify(data))
       });
   },

   // Unsubscribe from background network policy changes.
   policy.off('netBackgroundPolicyChange', (data) => {
       this.log('off netBackgroundPolicyChange: ' + JSON.stringify(data));
   });
```

## Managing the Metering Network Access Policy

### How to Develop

1. Import the **policy** namespace from **@ohos.net.policy.d.ts**.

2. Call **setPolicyByUid** to set whether the application indicated by the specified UID can access the network in the background.

3. Call **getPolicyByUid** to check whether the metering network access policy for the application indicated by the specified UID.

4. Call **getUidsByPolicy** to obtain the UIDs of the applications for which the metering network access policy is configured.

```js
   // Import the policy namespace.
   import policy from '@ohos.net.policy'

   // Subscribe to policy changes of the application indicated by the specified UID.
   policy.on('netUidPolicyChange', (data) => {
       this.log('on netUidPolicyChange: ' + JSON.stringify(data));
   });

   // Subscribe to rule changes of the application indicated by the specified UID.
   policy.on('netUidRuleChange', (data) => {
       this.log('on netUidRuleChange: ' + JSON.stringify(data));
   });

   // Call setPolicyByUid to set whether the application indicated by the specified UID can access the network in the background.
   setPolicyByUid() {
       let param = {
           uid: Number.parseInt(this.firstParam), policy: Number.parseInt(this.currentNetUidPolicy)
       }
       policy.setPolicyByUid(Number.parseInt(this.firstParam), Number.parseInt(this.currentNetUidPolicy), (err, data) => {
           console.log(JSON.stringify(err));
           console.log(JSON.stringify(data))
       });
   },

   // Call getPolicyByUid to check whether the metering network access policy for the application indicated by the specified UID.
   getPolicyByUid() {
       policy.getPolicyByUid(Number.parseInt(this.firstParam), (err, data) => {
           console.log(JSON.stringify(err));
           console.log(JSON.stringify(data))
       });
   },

   // Call getUidsByPolicy to obtain the UIDs of the applications for which the metering network access policy is configured.
   getUidsByPolicy(){
       policy.getUidsByPolicy(Number.parseInt(this.currentNetUidPolicy), (err, data) => {
           console.log(JSON.stringify(err));
           console.log(JSON.stringify(data))
       });
   },

   // Unsubscribe from policy changes of the application indicated by the specified UID.
   policy.off('netUidPolicyChange', (data) => {
       this.log('off netUidPolicyChange: ' + JSON.stringify(data));
   });

   // Unsubscribe from rule changes of the application indicated by the specified UID.
   policy.off('netUidRuleChange', (data) => {
       this.log('off netUidRuleChange: ' + JSON.stringify(data));
   });

```

## Restoring Network Policies

### How to Develop

1. Import the **policy** namespace from **@ohos.net.policy.d.ts**.

2. Call **restoreAllPolicies** to restore all network policies.

```js
   // Import the policy namespace.
   import policy from '@ohos.net.policy'

   // Call restoreAllPolicies to restore all network policies.
   restoreAllPolicies(){
       policy.restoreAllPolicies(this.firstParam, (err, data) => {
           console.log(JSON.stringify(err));
           console.log(JSON.stringify(data))
       });
   },
```

## Checking Access to a Metering or Non-metering Network

### How to Develop

1. Import the **policy** namespace from **@ohos.net.policy.d.ts**.

2. Call **isUidNetAllowed** to check whether the UID can access the metering or non-metering network.

```js
   // Import the policy namespace.
   import policy from '@ohos.net.policy'

   // Call isUidNetAllowed to check whether the application indicated by the specified UID can access the metering or non-metering network.
   isUidNetAllowedIsMetered(){
       let param = {
           uid: Number.parseInt(this.firstParam), isMetered: Boolean(Number.parseInt(this.isBoolean))
       }
       policy.isUidNetAllowed(Number.parseInt(this.firstParam), Boolean(Number.parseInt(this.isBoolean)), (err, data) => {
           console.log(JSON.stringify(err));
           console.log(JSON.stringify(data))
       });
   },
```

## Managing the Sleep Mode Allowlist

### How to Develop

1. Import the **policy** namespace from **@ohos.net.policy.d.ts**.

2. Call **setDeviceIdleAllowList** to add a UID to or remove a UID from the sleep mode allowlist.

3. Call **getDeviceIdleAllowList** to obtain the UIDs added to the sleep mode allowlist.

```js
   // Import the policy namespace.
   import policy from '@ohos.net.policy'

   // Call setDeviceIdleAllowList to add a UID to or remove a UID from the sleep mode allowlist.
   setDeviceIdleAllowList(){
       let param = {
           uid: Number.parseInt(this.firstParam), isAllowed: Boolean(Number.parseInt(this.isBoolean))
       }
       policy.setDeviceIdleAllowList(Number.parseInt(this.firstParam), Boolean(Number.parseInt(this.isBoolean)), (err, data) => {
           console.log(JSON.stringify(err));
           console.log(JSON.stringify(data))
       });
   },

   // Call getDeviceIdleAllowList to obtain the UIDs added to the sleep mode allowlist.
   getDeviceIdleAllowList(){
       policy.getDeviceIdleAllowList((err, data) => {
           console.log(JSON.stringify(err));
           console.log(JSON.stringify(data))
       });
   },
```

## Managing the Power-saving Mode Allowlist

### How to Develop

1. Import the **policy** namespace from **@ohos.net.policy.d.ts**.
2. Call **setPowerSaveAllowList** to add a UID to or remove a UID from the power-saving mode allowlist.
3. Call **getPowerSaveAllowList** to obtain the UIDs added to the power-saving mode allowlist.

```js
   // Import the policy namespace.
   import policy from '@ohos.net.policy'

   // Call setPowerSaveAllowList to add a UID to or remove a UID from the power-saving mode allowlist.
   setPowerSaveAllowList(){
       let param = {
           uid: Number.parseInt(this.firstParam), isAllowed: Boolean(Number.parseInt(this.isBoolean))
       }
       policy.setPowerSaveAllowList(Number.parseInt(this.firstParam), Boolean(Number.parseInt(this.isBoolean)), (err, data) => {
           console.log(JSON.stringify(err));
           console.log(JSON.stringify(data))
       });
   },

   // Call getPowerSaveAllowList to obtain the UIDs added to the power-saving mode allowlist.
   getPowerSaveAllowList(){
       policy.getPowerSaveAllowList((err, data) => {
           console.log(JSON.stringify(err));
           console.log(JSON.stringify(data))
       });
   },
```

## Updating the Network Notification Policy

### How to Develop

1. Import the **policy** namespace from **@ohos.net.policy.d.ts**.

2. Call **updateRemindPolicy** to update the network notification policy.

```js
   // Import the policy namespace.
   import policy from '@ohos.net.policy'

   // Call updateRemindPolicy to update the network notification policy.
   updateRemindPolicy() {
       let param = {
           netType: Number.parseInt(this.netType), iccid: this.firstParam, remindType: this.currentRemindType
       }
       policy.updateRemindPolicy(Number.parseInt(this.netType), this.firstParam, Number.parseInt(this.currentRemindType), (err, data) => {
           console.log(JSON.stringify(err));
           console.log(JSON.stringify(data))
       });
   },
```
