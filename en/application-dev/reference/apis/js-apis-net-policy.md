# Network Policy Management

The Network Policy Management module provides APIs for managing network policies, through which you can control and manage the data volume used.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import policy from '@ohos.net.policy'
```

## policy.setBackgroundPolicy

setBackgroundPolicy(isAllowed: boolean, callback: AsyncCallback\<void>): void

Sets a background network policy. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| isAllowed | boolean | Yes  | Whether applications running in the background are allowed to use mobile data.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
policy.setBackgroundPolicy(Boolean(Number.parseInt(this.isBoolean))), (err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
});
```

## policy.setBackgroundPolicy

setBackgroundPolicy(isAllowed: boolean): Promise\<void>

Sets a background network policy. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| isAllowed | boolean | Yes  | Whether applications running in the background are allowed to use mobile data.|

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
policy.setBackgroundPolicy(Boolean(Number.parseInt(this.isBoolean))).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## policy.getBackgroundPolicy

getBackgroundPolicy(callback: AsyncCallback\<boolean>): void;

Obtains the background network policy. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. If **true** is returned, applications running in the background are allowed to use mobile data.|

**Example**

```js
policy.getBackgroundPolicy((err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
});
```

## policy.getBackgroundPolicy

getBackgroundPolicy(): Promise\<boolean>;

Obtains the background network policy. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<boolean> | Promise used to return the result.|

**Example**

```js
policy.getBackgroundPolicy().then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.setPolicyByUid

setPolicyByUid(uid: number, policy: NetUidPolicy, callback: AsyncCallback\<void>): void;

Sets an application-specific network policy. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | Yes  | Unique ID of the application.|
| policy | [NetUidPolicy](#netuidpolicy) | Yes| Application-specific network policy to set.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
let param = {
    uid: Number.parseInt(this.firstParam), policy: Number.parseInt(this.currentNetUidPolicy)
}
policy.setPolicyByUid(Number.parseInt(this.firstParam), Number.parseInt(this.currentNetUidPolicy), (err, data) => {
    this.callBack(err, data);
});
```

## policy.setPolicyByUid

setPolicyByUid(uid: number, policy: NetUidPolicy): Promise\<void>;

Sets an application-specific network policy. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | Yes  | Unique ID of the application.|
| policy | [NetUidPolicy](#netuidpolicy) | Yes| Application-specific network policy to set.|

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
let param = {
    uid: Number.parseInt(this.firstParam), policy: Number.parseInt(this.currentNetUidPolicy)
}
policy.setPolicyByUid(Number.parseInt(this.firstParam), Number.parseInt(this.currentNetUidPolicy)).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.getPolicyByUid

getPolicyByUid(uid: number, callback: AsyncCallback\<NetUidPolicy>): void;

Obtains an application-specific network policy by **uid**. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | Yes| Unique ID of the application.|
| callback | AsyncCallback\<[NetUidPolicy](#netuidpolicy)> | Yes  | Callback used to return the result.|

**Example**

```js
policy.getPolicyByUid(Number.parseInt(this.firstParam), (err, data) => {
    this.callBack(err, data);
});
```

## policy.getPolicyByUid

getPolicyByUid(uid: number): Promise\<NetUidPolicy>;

Obtains an application-specific network policy by **uid**. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | Yes| Unique ID of the application.|

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<[NetUidPolicy](#netuidpolicy)> | Promise used to return the result.|

**Example**

```js
policy.getPolicyByUid(Number.parseInt(this.firstParam)).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.getUidsByPolicy

getUidsByPolicy(policy: NetUidPolicy, callback: AsyncCallback\<Array\<number>>): void;

Obtains the UID array of applications configured with a certain application-specific network policy. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| policy | [NetUidPolicy](#netuidpolicy) | Yes| Target application-specific network policy.|
| callback | AsyncCallback\<Array\<number>> | Yes  | Callback used to return the result.|

**Example**

```js
policy.getUidsByPolicy(Number.parseInt(this.currentNetUidPolicy), (err, data) => {
    this.callBack(err, data);
});
```

## policy.getUidsByPolicy

function getUidsByPolicy(policy: NetUidPolicy): Promise\<Array\<number>>;

Obtains the UID array of applications configured with a certain application-specific network policy. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| policy | [NetUidPolicy](#netuidpolicy) | Yes| Target application-specific network policy.|

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<Array\<number>> | Promise used to return the result.|

**Example**

```js
policy.getUidsByPolicy(Number.parseInt(this.firstParam)).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.getNetQuotaPolicies

getNetQuotaPolicies(callback: AsyncCallback\<Array\<NetQuotaPolicy>>): void;

Obtains the network quota policies. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<Array\<[NetQuotaPolicy](#netquotapolicy)>> | Yes  | Callback used to return the result.|

**Example**

```js
policy.getNetQuotaPolicies((err, data) => {
    this.callBack(err, data);
});
```

## policy.getNetQuotaPolicies

getNetQuotaPolicies(): Promise\<Array\<NetQuotaPolicy>>;

Obtains the network quota policies. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<Array\<[NetQuotaPolicy](#netquotapolicy)>> | Promise used to return the result.|

**Example**

```js
policy.getNetQuotaPolicies().then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.setNetQuotaPolicies

setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>, callback: AsyncCallback\<void>): void;

Sets an array of network quota policies. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| quotaPolicies | Array\<[NetQuotaPolicy](#netquotapolicy)> | Yes| An array of network quota policies to set.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
let param = {netType:Number.parseInt(this.netType), iccid:this.iccid, ident:this.ident, periodDuration:this.periodDuration, warningBytes:Number.parseInt(this.warningBytes),
    limitBytes:Number.parseInt(this.limitBytes), lastWarningRemind:this.lastWarningRemind, lastLimitRemind:this.lastLimitRemind, metered:Boolean(Number.parseInt(this.metered)), limitAction:this.limitAction};
this.netQuotaPolicyList.push(param);

policy.setNetQuotaPolicies(this.netQuotaPolicyList, (err, data) => {
    this.callBack(err, data);
});
```

## policy.setNetQuotaPolicies

setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>): Promise\<void>;

Sets an array of network quota policies. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| quotaPolicies | Array\<[NetQuotaPolicy](#netquotapolicy)> | Yes| An array of network quota policies to set.|

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
let param = {netType:Number.parseInt(this.netType), iccid:this.iccid, ident:this.ident, periodDuration:this.periodDuration, warningBytes:Number.parseInt(this.warningBytes),
    limitBytes:Number.parseInt(this.limitBytes), lastWarningRemind:this.lastWarningRemind, lastLimitRemind:this.lastLimitRemind, metered:Boolean(Number.parseInt(this.metered)), limitAction:this.limitAction};
this.netQuotaPolicyList.push(param);

policy.setNetQuotaPolicies(this.netQuotaPolicyList).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## policy.restoreAllPolicies

restoreAllPolicies(iccid: string, callback: AsyncCallback\<void>): void;

Restores all the policies (cellular network, background network, firewall, and application-specific network policies) for the given SIM card. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| iccid | string | Yes| SIM card ID.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
this.firstParam = iccid;
policy.restoreAllPolicies(this.firstParam, (err, data) => {
    this.callBack(err, data);
});
```

## policy.restoreAllPolicies

restoreAllPolicies(iccid: string): Promise\<void>;

Restores all the policies (cellular network, background network, firewall, and application-specific network policies) for the given SIM card. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| iccid | string | Yes| SIM card ID.|

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
this.firstParam = iccid;
policy.restoreAllPolicies(this.firstParam).then((err, data){
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.isUidNetAllowed

isUidNetAllowed(uid: number, isMetered: boolean, callback: AsyncCallback\<boolean>): void;

Checks whether an application is allowed to access metered networks. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | Yes| Unique ID of the application.|
| isMetered | boolean | Yes| Whether the network is a metered network.|
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The value **true** means that the application is allowed to access metered networks, and **false** means the opposite.|

**Example**

```js

let param = {
    uid: Number.parseInt(this.firstParam), isMetered: Boolean(Number.parseInt(this.isBoolean))
}
policy.isUidNetAllowed(Number.parseInt(this.firstParam), Boolean(Number.parseInt(this.isBoolean)), (err, data) => {
    this.callBack(err, data);
});
```

## policy.isUidNetAllowed

isUidNetAllowed(uid: number, isMetered: boolean): Promise\<boolean>;

Checks whether an application is allowed to access metered networks. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | Yes| Unique ID of the application.|
| isMetered | boolean | Yes| Whether the network is a metered network.|

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<boolean> | Promise used to return the result.|

**Example**

```js

let param = {
    uid: Number.parseInt(this.firstParam), isMetered: Boolean(Number.parseInt(this.isBoolean))
}
policy.isUidNetAllowed(Number.parseInt(this.firstParam), Boolean(Number.parseInt(this.isBoolean))).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.isUidNetAllowed

isUidNetAllowed(uid: number, iface: string, callback: AsyncCallback\<boolean>): void;

Checks whether an application is allowed to access the given network. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | Yes| Unique ID of the application.|
| iface | string | Yes| Name of the target network.|
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The value **true** means that the application is allowed to access the given network, and **false** means the opposite.|

**Example**

```js

let param = {
    uid: Number.parseInt(this.firstParam), iface: this.secondParam
}
policy.isUidNetAllowed(Number.parseInt(this.firstParam), this.secondParam, (err, data) => {
    this.callBack(err, data);
});
```

## policy.isUidNetAllowed

isUidNetAllowed(uid: number, iface: string): Promise\<boolean>;

Checks whether an application is allowed to access the given network. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | Yes| Unique ID of the application.|
| iface | string | Yes| Name of the target network.|

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<boolean> | Promise used to return the result.|

**Example**

```js
let param = {
    uid: Number.parseInt(this.firstParam), iface: this.secondParam
}
policy.isUidNetAllowed(Number.parseInt(this.firstParam), this.secondParam).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.setDeviceIdleAllowlist

setDeviceIdleAllowList(uid: number, isAllowed: boolean, callback: AsyncCallback\<void>): void;

Sets whether to add an application to the device idle allowlist. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | Yes| Unique ID of the application.|
| isAllowed | boolean | Yes| Whether to add the application to the allowlist.|
| callback | callback: AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
let param = {
    uid: Number.parseInt(this.firstParam), isAllowed: Boolean(Number.parseInt(this.isBoolean))
}
policy.setDeviceIdleAllowList(Number.parseInt(this.firstParam), Boolean(Number.parseInt(this.isBoolean)), (err, data) => {
    this.callBack(err, data);
});
```

## policy.setDeviceIdleAllowlist

setDeviceIdleAllowList(uid: number, isAllowed: boolean): Promise\<void>;

Sets whether to add an application to the device idle allowlist. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | Yes| Unique ID of the application.|
| isAllowed | boolean | Yes| Whether to add the application to the allowlist.|

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
let param = {
    uid: Number.parseInt(this.firstParam), isAllowed: Boolean(Number.parseInt(this.isBoolean))
}
policy.setDeviceIdleAllowList(Number.parseInt(this.firstParam), Boolean(Number.parseInt(this.isBoolean))).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.getDeviceIdleAllowlist

getDeviceIdleAllowList(callback: AsyncCallback\<Array\<number>>): void;

Obtains the UID array of applications that are on the device idle allowlist. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<Array\<number>> | Yes  | Callback used to return the result.|

**Example**

```js
policy.getDeviceIdleAllowList((err, data) => {
    this.callBack(err, data);
});
```

## policy.getDeviceIdleAllowlist

getDeviceIdleAllowList(): Promise\<Array\<number>>;

Obtains the UID array of applications that are on the device idle allowlist. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<Array\<number>> | Promise used to return the result.|

**Example**

```js
policy.getDeviceIdleAllowList().then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## policy.getBackgroundPolicyByUid

getBackgroundPolicyByUid(uid: number, callback: AsyncCallback\<NetBackgroundPolicy>): void;

Obtains the background network policies configured for the given application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | Yes| Unique ID of the application.|
| callback | AsyncCallback\<[NetBackgroundPolicy](#netbackgroundpolicy)> | Yes  | Callback used to return the result.|

**Example**

```js
this.firstParam = uid
policy.getBackgroundPolicyByUid(Number.parseInt(this.firstParam), (err, data) => {
    this.callBack(err, data);
});
```

## policy.getBackgroundPolicyByUid

getBackgroundPolicyByUid(uid: number): Promise\<NetBackgroundPolicy>;

Obtains the background network policies configured for the given application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | Yes| Unique ID of the application.|

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<[NetBackgroundPolicy](#netbackgroundpolicy)> | Promise used to return the result.|

**Example**

```js
this.firstParam = uid
policy.getBackgroundPolicyByUid(Number.parseInt(this.firstParam)).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## policy.resetPolicies

resetPolicies(iccid: string, callback: AsyncCallback\<void>): void;

Resets the policies (cellular network, background network, firewall, and application-specific network policies) for the given SIM card. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| iccid | string | Yes| SIM card ID.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
this.firstParam = iccid
policy.resetPolicies(this.firstParam, (err, data) => {
    this.callBack(err, data);
});
```

## policy.resetPolicies

resetPolicies(iccid: string): Promise\<void>;

Resets the policies (cellular network, background network, firewall, and application-specific network policies) for the given SIM card. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| iccid | string | Yes| SIM card ID.|

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
policy.getUidsByPolicy(Number.parseInt(this.firstParam)).then((err, data) {

})
this.firstParam = iccid
policy.resetPolicies(this.firstParam).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.updateRemindPolicy

updateRemindPolicy(netType: NetBearType, iccid: string, remindType: RemindType, callback: AsyncCallback\<void>): void;

Updates a reminder policy. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| netType | [NetBearType](js-apis-net-connection.md#netbeartype) | Yes| Network type.|
| iccid | string | Yes| SIM card ID.|
| remindType | [RemindType](#remindtype) | Yes| Reminder type.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
let param = {
    netType: Number.parseInt(this.netType), iccid: this.firstParam, remindType: this.currentRemindType
}
policy.updateRemindPolicy(Number.parseInt(this.netType), this.firstParam, Number.parseInt(this.currentRemindType), (err, data) => {
    this.callBack(err, data);
});
```

## policy.updateRemindPolicy

updateRemindPolicy(netType: NetBearType, iccid: string, remindType: RemindType): Promise\<void>;

Updates a reminder policy. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| netType | [NetBearType](js-apis-net-connection.md#netbeartype) | Yes| Network type.|
| iccid | string | Yes| SIM card ID.|
| remindType | [RemindType](#remindtype) | Yes| Reminder type.|

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
let param = {
    netType: Number.parseInt(this.netType), iccid: this.firstParam, remindType: this.currentRemindType
}
policy.updateRemindPolicy(Number.parseInt(this.netType), this.firstParam, Number.parseInt(this.currentRemindType)).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.on

Functions as the handle to a network policy.

### on('netUidPolicyChange')

on(type: "netUidPolicyChange", callback: Callback\<{ uid: number, policy: NetUidPolicy }>): void;

Subscribes to policy changes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                              | Mandatory| Description                                                        |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | netUidPolicyChange | Yes| Event type. The value **netUidPolicyChange** indicates a policy change event.|
| callback | Callback\<{ uid: number, policy: [NetUidPolicy](#netuidpolicy) }> | Yes  | Callback used to return the result.|

**Example**

```js
policy.on('netUidPolicyChange', (data) => {
    this.log('on netUidPolicyChange: ' + JSON.stringify(data));
})
```

### on('netUidRuleChange')

on(type: "netUidRuleChange", callback: Callback\<{ uid: number, rule: NetUidRule }>): void;

Subscribes to rule changes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                              | Mandatory| Description                                                        |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | netUidRuleChange | Yes| Event type. The value **netUidRuleChange** indicates a rule change event.|
| callback | Callback\<{ uid: number, rule: [NetUidRule](#netuidrule) }> | Yes  | Callback used to return the result.|

**Example**

```js
policy.on('netUidRuleChange', (data) => {
    this.log('on netUidRuleChange: ' + JSON.stringify(data));
})
```

### on('netMeteredIfacesChange')

on(type: "netMeteredIfacesChange", callback: Callback\<Array\<string>>): void;

Subscribes to metered network name (specified by **iface**) changes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                              | Mandatory| Description                                                        |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | netMeteredIfacesChange | Yes| Event type. The value **netMeteredIfacesChange** indicates a metered network name change event.|
| callback | Callback\<Array\<string>> | Yes  | Callback used to return the result.|

**Example**

```js
policy.on('netMeteredIfacesChange', (data) => {
    this.log('on netMeteredIfacesChange: ' + JSON.stringify(data));
})
```

### on('netQuotaPolicyChange')

on(type: "netQuotaPolicyChange", callback: Callback\<Array\<NetQuotaPolicy>>): void;

Subscribes to network quota policy changes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                              | Mandatory| Description                                                        |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | netQuotaPolicyChange | Yes| Event type. The value **netQuotaPolicyChange** indicates a network quota policy change event.|
| callback | Callback\<Array\<[NetQuotaPolicy](#netquotapolicy)>> | Yes  | Callback used to return the result.|

**Example**

```js
policy.on('netQuotaPolicyChange', (data) => {
    this.log('on netQuotaPolicyChange: ' + JSON.stringify(data));
})
```

### on('netBackgroundPolicyChange')

on(type: "netBackgroundPolicyChange", callback: Callback\<boolean>): void;

Subscribes to background network policy changes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                              | Mandatory| Description                                                        |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | netBackgroundPolicyChange | Yes| Event type. The value **netBackgroundPolicyChange** indicates a background network policy change event.|
| callback | Callback\<boolean> | Yes  | Callback used to return the result.|

**Example**

```js
policy.on('netBackgroundPolicyChange', (data) => {
    this.log('on netBackgroundPolicyChange: ' + JSON.stringify(data));
})
```

## NetBackgroundPolicy

Enumerates the background network policies.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name                 | Value  | Description                  |
| ------------------------ | ---- | ---------------------- |
| NET_BACKGROUND_POLICY_NONE       | 0 | Default policy.|
| NET_BACKGROUND_POLICY_ENABLE     | 1 | Applications running in the background are allowed to access metered networks.|
| NET_BACKGROUND_POLICY_DISABLE    | 2 | Applications running in the background are not allowed to access metered networks.|
| NET_BACKGROUND_POLICY_ALLOW_LIST | 3 | Only applications on the device idle allowlist are allowed to access metered networks when they are running in the background.|

## NetQuotaPolicy

Defines a network quota policy.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name                 | Type                               | Description                                                        |
| ----------------------- | ----------------------------------- | ------------------------------------------------------------ |
| netType           | [NetBearType](js-apis-net-connection.md#netbeartype) | Network type.|
| iccid             | string                      | Identifier of the SIM card on the metered cellular network. It is not used for Wi-Fi networks.|
| ident             | string                      | Identifier of the SIM card on the metered cellular network. It is used for Wi-Fi networks. It is used together with **iccid**.|
| periodDuration    | string                      | Start time of metering.|
| warningBytes      | number                      | Data volume threshold for generating an alarm.|
| limitBytes        | number                      | Data volume quota.|
| lastWarningRemind | string                      | Last time when an alarm was generated.|
| lastLimitRemind   | string                      | Last time when the quota was exhausted.|
| metered           | string                      | Whether the network is a metered network.|
| limitAction       | [LimitAction](#limitaction) | Action to take when the data volume quota is reached.|

## LimitAction

Enumerates the actions that can be taken when the data volume quota is reached.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name                 | Value| Description  |
| ---------------------- | ----- | ------------ |
| LIMIT_ACTION_NONE     | -1 | Default action.|
| LIMIT_ACTION_DISABLE  | 0  | Internet access is disabled.|
| LIMIT_ACTION_AUTO_BILL| 1  | Users will be automatically charged for the data volume they use.|

## NetUidRule

Enumerates the metered network rules.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name                 | Value| Description  |
| ---------------------- | ----- | ------------ |
| NET_RULE_NONE                     | 0 | Default rule.|
| NET_RULE_ALLOW_METERED_FOREGROUND | 1 | Applications running in the foreground are allowed to access metered networks.|
| NET_RULE_ALLOW_METERED            | 2 | Applications are allowed to access metered networks.|
| NET_RULE_REJECT_METERED           | 4 | Applications are not allowed to access metered networks.|
| NET_RULE_ALLOW_ALL                | 32 | Applications are allowed to access all networks (metered or non-metered).|
| NET_RULE_REJECT_ALL               | 64 | Applications are not allowed to access any networks (metered or non-metered).|

## RemindType

Enumerates the reminder types.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name                 | Value| Description  |
| ---------------------- | - | ------- |
| REMIND_TYPE_WARNING    | 1 | Warning.|
| REMIND_TYPE_LIMIT      | 2 | Limit.|

## NetUidPolicy

Enumerates the application-specific network policies.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name                 | Value| Description  |
| ---------------------- | ----- | ------------ |
| NET_POLICY_NONE                       | 0 | Default network policy.|
| NET_POLICY_ALLOW_METERED_BACKGROUND   | 1 | Applications running in the background are allowed to access metered networks.|
| NET_POLICY_REJECT_METERED_BACKGROUND  | 2 | Applications running in the background are not allowed to access metered networks.|
