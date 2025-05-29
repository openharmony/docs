# MissionParameter (系统接口)

作为[startSyncRemoteMissions](js-apis-distributedMissionManager-sys.md#distributedmissionmanagerstartsyncremotemissions)的入参，表示同步时所需参数的枚举。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

## 属性

| 名称          | 类型    | 只读   | 可选   | 说明          |
| ----------- | ------- | ---- | ---- | ----------- |
| deviceId    | string  | 是    | 否    | 表示设备ID。     |
| fixConflict | boolean | 是    | 否    | 表示是否存在版本冲突，true表示存在冲突，false表示不存在冲突。 |
| tag         | number  | 是    | 否    | 表示任务的标签，0表示默认标签。    |
