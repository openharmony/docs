# @ohos.data.cloudData (端云服务)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @lvcong_oh-->
<!--Designer: @lvcong_oh-->
<!--Tester: @ltttjs; @logic42-->
<!--Adviser: @ge-yafang-->

端云服务提供端云策略能力。

端云策略提供端云同步策略配置的能力。

> **说明：**
>
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { cloudData } from '@kit.ArkData';
```

## StrategyType

云同步策略类型枚举。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

| 名称      | 值 | 说明        |
| --------- |---|-----------|
| NETWORK | 0 | 通过网络同步策略。 |

## NetWorkStrategy

网络策略参数枚举。

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

| 名称      | 值 | 说明        |
| --------- |---|-----------|
| WIFI | 1 | WIFI网络策略。 |
| CELLULAR | 2 | 蜂窝网络策略。   |

## AutoSyncTriggerMode

自动同步触发模式枚举。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称 | 值 | 说明 |
|------|---|------|
| ACCOUNT_LOGIN | 0 | 账号登录触发模式。 |
| CLOUD_SWITCH_ON | 1 | 同步开关触发模式。 |
| NETWORK_RECOVER | 2 | 网络恢复后的触发模式。 |
| CLOUD_DATA_CHANGE | 3 | 云端数据变更触发模式。 |
| USER_CHANGE | 4 | 用户变更触发模式。 |

## AutoSyncTriggerInfo

自动同步触发信息。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------|------|------|------|------|
| mode | [AutoSyncTriggerMode](#autosynctriggermode) | 否 | 否 | 自动同步触发模式。 |

## cloudData.setCloudStrategy

setCloudStrategy(strategy: StrategyType, param?: Array&lt;commonType.ValueType&gt;): Promise&lt;void&gt;

设置应用自身的云同步策略，使用Promise异步回调。
 
**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**参数：**

| 参数名     | 类型                                                                          | 必填 | 说明                             |
| ---------- |-----------------------------------------------------------------------------| ---- | -------------------------------- |
| strategy  | [StrategyType](#strategytype)                                               | 是   | 配置的策略类型。             |
| param | Array&lt;[commonType.ValueType](js-apis-data-commonType.md#valuetype)&gt; | 否   | 策略参数，类型为Array&lt;commonType.ValueType&gt;，实际传入值为[NetWorkStrategy](#networkstrategy)枚举值，取值范围为WIFI和CELLULAR，默认支持WIFI和蜂窝网络策略。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801       | Capability not supported.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 仅WIFI同步
cloudData.setCloudStrategy(cloudData.StrategyType.NETWORK, [cloudData.NetWorkStrategy.WIFI]).then(() => {
  console.info('Succeeded in setting the cloud strategy');
}).catch((err: BusinessError) => {
  console.error(`Failed to set cloud strategy. Code: ${err.code}, message: ${err.message}`);
});

```

## cloudData.onAutoSyncTrigger

onAutoSyncTrigger(observer: Callback&lt;AutoSyncTriggerInfo&gt;): void

在已打开端云同步且应用关闭自动同步的条件下，注册自动同步触发事件通知。当满足自动触发条件时，回调函数会被调用。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| observer | Callback&lt;[AutoSyncTriggerInfo](#autosynctriggerinfo)&gt; | 是 | 回调函数，返回自动同步触发信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 801      | Capability not supported. |

**示例：**

```ts
function autoSyncTriggerObserver(info: cloudData.AutoSyncTriggerInfo) {
  console.info(`Auto sync triggered, mode: ${info.mode}`);
}

cloudData.onAutoSyncTrigger(autoSyncTriggerObserver);
```

## cloudData.offAutoSyncTrigger

offAutoSyncTrigger(observer?: Callback&lt;AutoSyncTriggerInfo&gt;): void

取消订阅自动同步触发事件通知。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.DistributedDataManager.CloudSync.Client

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| observer | Callback&lt;[AutoSyncTriggerInfo](#autosynctriggerinfo)&gt; | 否 | 回调函数。 若传入observer，则取消指定回调函数的订阅；若不传入observer，则取消所有已注册的订阅。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 801      | Capability not supported. |

**示例：**

```ts
function autoSyncTriggerObserver(info: cloudData.AutoSyncTriggerInfo) {
  console.info(`Auto sync triggered, mode: ${info.mode}`);
}

// 订阅
cloudData.onAutoSyncTrigger(autoSyncTriggerObserver);

// 取消指定订阅
cloudData.offAutoSyncTrigger(autoSyncTriggerObserver);

// 取消所有订阅
cloudData.offAutoSyncTrigger();
```
<!--no_check-->
