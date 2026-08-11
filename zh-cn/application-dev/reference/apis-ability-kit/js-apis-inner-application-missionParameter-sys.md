# MissionParameter (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: DistributedAbilityManager-->
<!--Owner: @hobbycao-->
<!--Designer: @gsxiaowen-->
<!--Tester: @zhaodengqi-->
<!--Adviser: @hu-zhiqiong-->

作为[startSyncRemoteMissions](js-apis-distributedMissionManager-sys.md#distributedmissionmanagerstartsyncremotemissions)的入参，表示同步时所需参数的接口。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```js
import { distributedMissionManager } from '@kit.AbilityKit';
```

## MissionParameter

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称          | 类型    | 只读   | 可选   | 说明          |
| ----------- | ------- | ---- | ---- | ----------- |
| deviceId    | string  | 否    | 否    | 同步目标设备的ID。     |
| fixConflict | boolean | 否    | 否    | 是否处理版本冲突，true表示处理冲突，false表示不处理冲突。 |
| tag         | number  | 否    | 否    | 任务的标签，取值为非负整数，0表示默认标签，用于标识和区分不同的同步任务。    |
