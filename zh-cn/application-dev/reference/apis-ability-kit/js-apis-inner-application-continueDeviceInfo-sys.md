# ContinueDeviceInfo (系统接口)

表示发起Mission迁移时所需参数的枚举，迁移Mission详见：[continueMission接口](js-apis-distributedMissionManager-sys.md#distributedmissionmanagercontinuemission)。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

| 名称       | 类型   | 只读   | 可选   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| srcDeviceId | string | 否    | 否    | 表示任务迁移源设备ID。 |
| dstDeviceId | string | 否    | 否    | 表示任务迁移目标设备ID。 |
| missionId | number | 否    | 否    | 表示任务ID。 |
| wantParam | Record<string, Object> | 否    | 否    | 表示扩展参数。 |

