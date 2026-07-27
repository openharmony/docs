# ContinueDeviceInfo (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: DistributedAbilityManager-->
<!--Owner: @hobbycao-->
<!--Designer: @gsxiaowen-->
<!--Tester: @hanjiawei-->
<!--Adviser: @hu-zhiqiong-->

表示发起Mission迁移时所需参数的接口对象，迁移Mission详见：[continueMission接口](js-apis-distributedMissionManager-sys.md#distributedmissionmanagercontinuemission)。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。
> 本模块接口仅可在Stage模型下使用。

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

| 名称       | 类型   | 只读   | 可选   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| srcDeviceId | string | 否    | 否    | 表示Mission迁移源设备ID。 |
| dstDeviceId | string | 否    | 否    | 表示Mission迁移目标设备ID。 |
| missionId | number | 否    | 否    | 表示Mission迁移任务ID。 |
| wantParam | Record<string, Object> | 否    | 否    | 表示Mission迁移扩展参数，用于传递任务迁移时的自定义信息。可以包含开发者自定义的键值对，用于标识迁移场景或携带迁移相关的配置信息。 |
