# ContinueMissionInfo (系统接口)

表示发起按照包名迁移时所需参数的枚举，迁移Mission详见：[continueMission接口](js-apis-distributedMissionManager-sys.md#distributedmissionmanagercontinuemission10)。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 属性

**系统接口**: 此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称       | 类型   | 只读   | 必填   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| srcDeviceId | string | 否    | 是    | 表示任务迁移源设备ID。 |
| dstDeviceId | string | 否    | 是    | 表示任务迁移目标设备ID。 |
| bundleName | string | 否    | 是    | 表示任务所属目标端应用包名。 |
| wantParam | Record<string, Object> | 否    | 是    | 表示扩展参数。 |
| srcBundleName<sup>12+</sup> | string | 否    | 否    | 表示任务所属源端应用包名，默认与bundleName相同。 |
| continueType<sup>12+</sup> | string | 否    | 否    | 表示任务所属应用迁移类型。 |
