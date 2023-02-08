# 网络策略管理部件

## 简介

网络策略管理提供一些限制网络的基础能力，包括蜂窝网络策略、休眠/省电模式策略、后台网络策略、重置网络策略等功能。

> **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 基本概念

- 休眠模式：设备在不需要工作的时候把一些部件、外设关掉(进入低功耗模式)，并限制部分应用对网络的访问。
- 省电模式：省电模式是系统里的一个开关，开启后会降低设备的性能，并限制部分应用对网络的访问。
- 省流量模式：即后台网络策略，对处于后台的使用计量网络的应用进行限制。
- 蜂窝网络：移动通信网络。
- 计量网络：设置了流量配额的电话卡网络、Wlan网络以及以太网。

## 约束

- 开发语言：C++ JS
- 系统：linux内核

## 场景介绍

网络策略管理的典型场景有：

- 设置计量网络配额/获取已经设置的计量网络策略
- 后台网络限制开关/获取后台网络限制状态/获取指定uid在后台状态下能否访问网络
- 设定指定uid访问计量网络的策略/获取指定uid访问计量网络的策略/获取设置了对应策略的uids
- 重置网络策略
- 判断uid能否访问计量/非计量网络
- 将对应uid从休眠白名单里添加、移除/获取休眠模式的白名单列表
- 将对应uid从省电白名单里添加、移除/获取省电模式的白名单列表
- 更新网络提醒策略

以下分别介绍具体开发方式。

## 接口说明

完整的JS API说明以及实例代码请参考：[网络策略管理](../reference/apis/js-apis-net-policy.md)。

| 类型 | 接口 | 功能说明 |
| ---- | ---- | ---- |
| ohos.net.policy | function setBackgroundPolicy(isAllowed: boolean, callback: AsyncCallback\<void>): void |设置后台网络策略，使用callback方式作为异步方法 |
| ohos.net.policy | function setBackgroundPolicy(isAllowed: boolean): Promise\<void> |设置后台网络策略，使用Promise方式作为异步方法 |
| ohos.net.policy | function isBackgroundAllowed(callback: AsyncCallback\<boolean>): void; |获取后台网络策略，使用callback方式作为异步方法 |
| ohos.net.policy | function isBackgroundAllowed(): Promise\<boolean>; |获取后台网络策略，使用Promise方式作为异步方法 |
| ohos.net.policy | function setPolicyByUid(uid: number, policy: NetUidPolicy, callback: AsyncCallback\<void>): void; |设置对应uid应用的访问计量网络的策略，使用callback方式作为异步方法 |
| ohos.net.policy | function setPolicyByUid(uid: number, policy: NetUidPolicy): Promise\<void>;| 设置对应uid应用的访问计量网络的策略，使用Promise方式作为异步方法 |
| ohos.net.policy | function getPolicyByUid(uid: number, callback: AsyncCallback\<NetUidPolicy>): void;| 通过应用uid获取策略，使用callback方式作为异步方法 |
| ohos.net.policy | function getPolicyByUid(uid: number): Promise\<NetUidPolicy>; | 通过应用uid获取策略，使用Promise方式作为异步方法 |
| ohos.net.policy | function getUidsByPolicy(policy: NetUidPolicy, callback: AsyncCallback\<Array\<number>>): void; | 通过策略获取设置这一策略的应用uid数组，使用callback方式作为异步方法 |
| ohos.net.policy | function getUidsByPolicy(policy: NetUidPolicy): Promise\<Array\<number>>; | 通过策略获取设置这一策略的应用uid数组，使用Promise方式作为异步方法 |
| ohos.net.policy | function getNetQuotaPolicies(callback: AsyncCallback\<Array\<NetQuotaPolicy>>): void; |获取计量网络策略，使用callback方式作为异步方法 |
| ohos.net.policy | function getNetQuotaPolicies(): Promise\<Array\<NetQuotaPolicy>>; |获取计量网络策略，使用Promise方式作为异步方法 |
| ohos.net.policy | function setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>, callback: AsyncCallback\<void>): void; |设置计量网络策略，使用callback方式作为异步方法 |
| ohos.net.policy | function setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>): Promise\<void>; | 设置计量网络策略，使用Promise方式作为异步方法 |
| ohos.net.policy | function restoreAllPolicies(iccid: string, callback: AsyncCallback\<void>): void; | 重置对应sim卡id的蜂窝网络、后台网络策略、防火墙策略、应用对应的策略，使用callback方式作为异步方法 |
| ohos.net.policy | function restoreAllPolicies(iccid: string): Promise\<void>; | 重置对应sim卡id的蜂窝网络、后台网络策略、防火墙策略、应用对应的策略，使用Promise方式作为异步方法 |
| ohos.net.policy | function isUidNetAllowed(uid: number, isMetered: boolean, callback: AsyncCallback\<boolean>): void; | 获取对应uid能否访问计量或非计量网络，使用callback方式作为异步方法 |
| ohos.net.policy | function isUidNetAllowed(uid: number, isMetered: boolean): Promise\<boolean>; | 获取对应uid能否访问计量或非计量网络，使用Promise方式作为异步方法 |
| ohos.net.policy | function isUidNetAllowed(uid: number, iface: string, callback: AsyncCallback\<boolean>): void; | 获取对应uid能否访问指定的iface的网络，使用callback方式作为异步方法 |
| ohos.net.policy | function isUidNetAllowed(uid: number, iface: string): Promise\<boolean>; | 获取对应uid能否访问指定的iface的网络，使用Promise方式作为异步方法 |
| ohos.net.policy | function setDeviceIdleAllowList(uid: number, isAllowed: boolean, callback: AsyncCallback\<void>): void; | 设置指定uid应用是否在休眠防火墙的白名单，使用callback方式作为异步方法 |
| ohos.net.policy | function setDeviceIdleAllowList(uid: number, isAllowed: boolean): Promise\<void>; | 设置指定uid应用是否在休眠防火墙的白名单，使用Promise方式作为异步方法 |
| ohos.net.policy | function getDeviceIdleAllowList(callback: AsyncCallback\<Array\<number>>): void; | 获取休眠模式白名单所包含的uid数组，使用callback方式作为异步方法 |
| ohos.net.policy | function getDeviceIdleAllowList(): Promise\<Array\<number>>; | 获取休眠模式白名单所包含的uid数组，使用Promise方式作为异步方法 |
| ohos.net.policy | function getBackgroundPolicyByUid(uid: number, callback: AsyncCallback\<NetBackgroundPolicy>): void; | 获取指定uid能否访问后台网络，使用callback方式作为异步方法 |
| ohos.net.policy | function getBackgroundPolicyByUid(uid: number): Promise\<NetBackgroundPolicy>; | 获取指定uid能否访问后台网络，使用Promise方式作为异步方法 |
| ohos.net.policy | function resetPolicies(iccid: string, callback: AsyncCallback\<void>): void; | 重置对应sim卡id的蜂窝网络、后台网络策略、防火墙策略、应用对应的策略，使用callback方式作为异步方法 |
| ohos.net.policy | function resetPolicies(iccid: string): Promise\<void>; | 重置对应sim卡id的蜂窝网络、后台网络策略、防火墙策略、应用对应的策略，使用Promise方式作为异步方法 |
| ohos.net.policy | function updateRemindPolicy(netType: NetBearType, iccid: string, remindType: RemindType, callback: AsyncCallback\<void>): void; | 更新提醒策略，使用callback方式作为异步方法 |
| ohos.net.policy | function updateRemindPolicy(netType: NetBearType, iccid: string, remindType: RemindType): Promise\<void>; | 更新提醒策略，使用Promise方式作为异步方法。 |
| ohos.net.policy | function setPowerSaveAllowList(uid: number, isAllowed: boolean, callback: AsyncCallback\<void>): void; | 设置指定uid应用是否在省电防火墙的白名单，使用callback方式作为异步方法 |
| ohos.net.policy | function setPowerSaveAllowList(uid: number, isAllowed: boolean): Promise\<void>; | 设置指定uid应用是否在省电防火墙的白名单，使用Promise方式作为异步方法 |
| ohos.net.policy | function getPowerSaveAllowList(callback: AsyncCallback\<Array\<number>>): void; | 获取省电模式白名单所包含的uid数组，使用callback方式作为异步方法 |
| ohos.net.policy | function getPowerSaveAllowList(): Promise\<Array\<number>>; | 获取休眠模式白名单所包含的uid数组，使用Promise方式作为异步方法 |
| ohos.net.policy | function on(type: "netUidPolicyChange", callback: Callback\<{ uid: number, policy: NetUidPolicy }>): void; | 订阅policy发生改变时的回调，使用callback方式作为异步方法 |
| ohos.net.policy | function off(type: "netUidPolicyChange", callback: Callback\<{ uid: number, policy: NetUidPolicy }>): void; | 取消订阅policy发生改变时的回调，使用callback方式作为异步方法 |
| ohos.net.policy | function on(type: "netUidRuleChange", callback: Callback\<{ uid: number, rule: NetUidRule }>): void; | 订阅rule发生改变时的回调，使用callback方式作为异步方法 |
| ohos.net.policy | function off(type: "netUidRuleChange", callback: Callback\<{ uid: number, rule: NetUidRule }>): void; | 取消订阅rule发生改变时的回调，使用callback方式作为异步方法 |
| ohos.net.policy | function on(type: "netMeteredIfacesChange", callback: Callback\<Array\<string>>): void; | 订阅计量iface发生改变时的回调，使用callback方式作为异步方法 |
| ohos.net.policy | function off(type: "netMeteredIfacesChange", callback: Callback\<Array\<string>>): void; | 取消订阅计量iface发生改变时的回调，使用callback方式作为异步方法 |
| ohos.net.policy | function on(type: "netQuotaPolicyChange", callback: Callback\<Array\<NetQuotaPolicy>>): void; | 订阅计量网络策略发生改变时的回调，使用callback方式作为异步方法 |
| ohos.net.policy | function off(type: "netQuotaPolicyChange", callback: Callback\<Array\<NetQuotaPolicy>>): void; | 取消订阅计量网络策略发生改变时的回调，使用callback方式作为异步方法 |
| ohos.net.policy | function on(type: "netBackgroundPolicyChange", callback: Callback\<boolean>): void; | 订阅后台网络策略发生改变时的回调，使用callback方式作为异步方法 |
| ohos.net.policy | function off(type: "netBackgroundPolicyChange", callback: Callback\<boolean>): void; | 取消订阅后台网络策略发生改变时的回调，使用callback方式作为异步方法 |

## 设置计量网络配额/获取已经设置的计量网络策略

### 开发步骤

1. 从@ohos.net.policy.d.ts中导入policy命名空间。

2. 调用setNetQuotaPolicies方法，设置计量网络策略。

3. 调用getNetQuotaPolicies方法，获取计量网络策略。

```js
   // 引入包名
   import policy from '@ohos.net.policy';

   addNetQuotaPolicy(){
       let param = {
           // netType值详见 [NetBearType](../reference/apis/js-apis-net-connection.md#netbeartype)
           netType:Number.parseInt(this.netType),

           // 计量蜂窝网络的SIM卡的标识值。以太网，wifi网络不会用到
           iccid:this.iccid,

           // 计量蜂窝网络中配合iccid联合使用。以太网，wifi网络单独使用。用于标记类型
           ident:this.ident,

           // 计量开始时间。例如M1、D1、Y1等
           periodDuration:this.periodDuration,

           // 发出警告的流量阈值 大于0的整数即可
           warningBytes:Number.parseInt(this.warningBytes),

           // 流量设置的配额 大于0的整数即可
           limitBytes:Number.parseInt(this.limitBytes),

           // 是否为计量网络 true为计量网络 false为非计量网络
           metered:Boolean(Number.parseInt(this.metered)),

           // 到达流量限制后的动作 详见[LimitAction](../reference/apis/js-apis-net-policy.md#limitaction)
           limitAction:Number.parseInt(this.limitAction)
       };
       this.netQuotaPolicyList.push(param);
   },

   // 订阅计量网络iface发生改变时的回调
   policy.on('netMeteredIfacesChange', (data) => {
       this.log('on netMeteredIfacesChange：' + JSON.stringify(data));
   });

   // 订阅计量网络策略发生改变时的回调
   policy.on('netQuotaPolicyChange', (data) => {
       this.log('on netQuotaPolicyChange：' + JSON.stringify(data));
   });

   // 调用setNetQuotaPolicies方法，设置计量网络策略
   setNetQuotaPolicies(){
       this.dialogType = DialogType.HIDE;
       policy.setNetQuotaPolicies(this.netQuotaPolicyList, (err, data) => {
           console.log(JSON.stringify(err))；
           console.log(JSON.stringify(data))；
       });
   },

   // 调用getNetQuotaPolicies方法，获取计量网络策略
   getNetQuotaPolicies(){
       policy.getNetQuotaPolicies((err, data) => {
           this.callBack(err, data);
           if(data){
               this.netQuotaPolicyList = data;
           }
       });
   },

   // 取消订阅计量网络iface发生改变时的回调
   policy.off('netMeteredIfacesChange', (data) => {
       this.log('off netMeteredIfacesChange：' + JSON.stringify(data));
   });

   // 取消订阅计量网络策略发生改变时的回调
   policy.off('netQuotaPolicyChange', (data) => {
       this.log('off netQuotaPolicyChange：' + JSON.stringify(data));
   });
```

## 后台网络限制开关/获取后台网络限制状态/获取指定uid在后台状态下能否访问网络

### 开发步骤

1. 从@ohos.net.policy.d.ts中导入policy命名空间。

2. 调用setBackgroundAllowed方法，设置开启后台省流量或关闭后台省流量。

3. 调用isBackgroundAllowed方法，获取后台网络限制状态（省流量）是开启还是关闭。

4. 调用getBackgroundPolicyByUid方法，获取指定uid在后台状态下能否访问网络。

```js
   // 引入包名
   import policy from '@ohos.net.policy'

   // 订阅后台网络策略发生改变时的回调
   policy.on('netBackgroundPolicyChange', (data) => {
       this.log('on netBackgroundPolicyChange：' + JSON.stringify(data));
   });

   // 调用setBackgroundAllowed方法，设置开启后台省流量或关闭后台省流量
   setBackgroundAllowed() {
       policy.setBackgroundAllowed(Boolean(Number.parseInt(this.isBoolean)), (err, data) => {
           console.log(JSON.stringify(err))；
           console.log(JSON.stringify(data))
       });
   },

   // 调用isBackgroundAllowed方法，获取后台网络限制状态（省流量）是开启还是关闭。
   isBackgroundAllowed() {
        policy.isBackgroundAllowed((err, data) => {
            console.log(JSON.stringify(err))；
            console.log(JSON.stringify(data))
        });
   },

   // 调用getBackgroundPolicyByUid方法，获取指定uid在后台状态下能否访问网络。
   getBackgroundPolicyByUid() {
       policy.getBackgroundPolicyByUid(Number.parseInt(this.firstParam), (err, data) => {
           console.log(JSON.stringify(err))；
           console.log(JSON.stringify(data))
       });
   },

   // 取消订阅后台网络策略发生改变时的回调
   policy.off('netBackgroundPolicyChange', (data) => {
       this.log('off netBackgroundPolicyChange：' + JSON.stringify(data));
   });
```

## 设定指定uid访问计量网络的策略/获取指定uid访问计量网络的策略/获取设置了对应策略的uids

### 开发步骤

1. 从@ohos.net.policy.d.ts中导入policy命名空间。

2. 调用setPolicyByUid方法，设置指定uid是否可以访问后台网络。

3. 调用getPolicyByUid方法，获取指定uid的策略。

4. 调用getUidsByPolicy方法，获取使用指定策略的uids。

```js
   // 引入包名
   import policy from '@ohos.net.policy'

   // 订阅uid的policy发生改变时的回调
   policy.on('netUidPolicyChange', (data) => {
       this.log('on netUidPolicyChange：' + JSON.stringify(data));
   });

   // 订阅uid的rule发生改变时的回调
   policy.on('netUidRuleChange', (data) => {
       this.log('on netUidRuleChange：' + JSON.stringify(data));
   });

   // 调用setPolicyByUid方法，设置指定uid是否可以访问后台网络
   setPolicyByUid() {
       let param = {
           uid: Number.parseInt(this.firstParam), policy: Number.parseInt(this.currentNetUidPolicy)
       }
       policy.setPolicyByUid(Number.parseInt(this.firstParam), Number.parseInt(this.currentNetUidPolicy), (err, data) => {
           console.log(JSON.stringify(err))；
           console.log(JSON.stringify(data))
       });
   },

   // 调用getPolicyByUid方法，获取指定uid的策略
   getPolicyByUid() {
       policy.getPolicyByUid(Number.parseInt(this.firstParam), (err, data) => {
           console.log(JSON.stringify(err))；
           console.log(JSON.stringify(data))
       });
   },

   // 调用getUidsByPolicy方法，获取使用指定策略的uids
   getUidsByPolicy(){
       policy.getUidsByPolicy(Number.parseInt(this.currentNetUidPolicy), (err, data) => {
           console.log(JSON.stringify(err))；
           console.log(JSON.stringify(data))
       });
   },

   // 取消订阅uid的policy发生改变时的回调
   policy.off('netUidPolicyChange', (data) => {
       this.log('off netUidPolicyChange：' + JSON.stringify(data));
   });

   // 取消订阅uid的rule发生改变时的回调
   policy.off('netUidRuleChange', (data) => {
       this.log('off netUidRuleChange：' + JSON.stringify(data));
   });

```

## 重置网络策略

### 开发步骤

1. 从@ohos.net.policy.d.ts中导入policy命名空间。

2. 调用restoreAllPolicies方法，重置网络策略。

```js
   // 引入包名
   import policy from '@ohos.net.policy'

   // 调用restoreAllPolicies方法，重置网络策略
   restoreAllPolicies(){
       policy.restoreAllPolicies(this.firstParam, (err, data) => {
           console.log(JSON.stringify(err))；
           console.log(JSON.stringify(data))
       });
   },
```

## 判断uid能否访问计量/非计量网络

### 开发步骤

1. 从@ohos.net.policy.d.ts中导入policy命名空间。

2. 调用isUidNetAllowed方法，获取uid能否访问计量/非计量网络。

```js
   // 引入包名
   import policy from '@ohos.net.policy'

   // 调用isUidNetAllowed方法，获取uid能否访问计量/非计量网络
   isUidNetAllowedIsMetered(){
       let param = {
           uid: Number.parseInt(this.firstParam), isMetered: Boolean(Number.parseInt(this.isBoolean))
       }
       policy.isUidNetAllowed(Number.parseInt(this.firstParam), Boolean(Number.parseInt(this.isBoolean)), (err, data) => {
           console.log(JSON.stringify(err))；
           console.log(JSON.stringify(data))
       });
   },
```

## 将对应uid从休眠白名单里添加、移除/获取休眠模式的白名单列表

### 开发步骤

1. 从@ohos.net.policy.d.ts中导入policy命名空间。

2. 调用setDeviceIdleAllowList方法，设置uid是否添加到休眠模式白名单。

3. 调用getDeviceIdleAllowList方法，获取添加在休眠模式白名单的uids。

```js
   // 引入包名
   import policy from '@ohos.net.policy'

   // 调用setDeviceIdleAllowList方法，设置uid是否添加到休眠模式白名单
   setDeviceIdleAllowList(){
       let param = {
           uid: Number.parseInt(this.firstParam), isAllowed: Boolean(Number.parseInt(this.isBoolean))
       }
       policy.setDeviceIdleAllowList(Number.parseInt(this.firstParam), Boolean(Number.parseInt(this.isBoolean)), (err, data) => {
           console.log(JSON.stringify(err))；
           console.log(JSON.stringify(data))
       });
   },

   // 调用getDeviceIdleAllowList方法，获取添加在休眠模式白名单的uids
   getDeviceIdleAllowList(){
       policy.getDeviceIdleAllowList((err, data) => {
           console.log(JSON.stringify(err))；
           console.log(JSON.stringify(data))
       });
   },
```

## 将对应uid从省电白名单里添加、移除/获取省电模式的白名单列表

### 开发步骤

1. 从@ohos.net.policy.d.ts中导入policy命名空间。
2. 调用setPowerSaveAllowList方法，设置uid是否添加到省电模式白名单。
3. 调用getPowerSaveAllowList方法，获取添加在省电模式白名单的uids。

```js
   // 引入包名
   import policy from '@ohos.net.policy'

   // 调用setPowerSaveAllowList方法，设置uid是否添加到省电模式白名单
   setPowerSaveAllowList(){
       let param = {
           uid: Number.parseInt(this.firstParam), isAllowed: Boolean(Number.parseInt(this.isBoolean))
       }
       policy.setPowerSaveAllowList(Number.parseInt(this.firstParam), Boolean(Number.parseInt(this.isBoolean)), (err, data) => {
           console.log(JSON.stringify(err))；
           console.log(JSON.stringify(data))
       });
   },

   // 调用getPowerSaveAllowList方法，获取添加在省电模式白名单的uids
   getPowerSaveAllowList(){
       policy.getPowerSaveAllowList((err, data) => {
           console.log(JSON.stringify(err))；
           console.log(JSON.stringify(data))
       });
   },
```

## 更新网络提醒策略

### 开发步骤

1. 从@ohos.net.policy.d.ts中导入policy命名空间。

2. 调用updateRemindPolicy，更新网络提醒策略。

```js
   // 引入包名
   import policy from '@ohos.net.policy'

   // 调用updateRemindPolicy，更新网络提醒策略
   updateRemindPolicy() {
       let param = {
           netType: Number.parseInt(this.netType), iccid: this.firstParam, remindType: this.currentRemindType
       }
       policy.updateRemindPolicy(Number.parseInt(this.netType), this.firstParam, Number.parseInt(this.currentRemindType), (err, data) => {
           console.log(JSON.stringify(err))；
           console.log(JSON.stringify(data))
       });
   },
```