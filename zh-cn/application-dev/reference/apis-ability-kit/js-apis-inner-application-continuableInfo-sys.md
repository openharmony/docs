# ContinuableInfo (系统接口)

当注册应用任务流转状态监听的回调时，返回应用任务流转状态和流转信息，注册详见：[on('continueStateChange')接口](js-apis-distributedMissionManager-sys.md#distributedmissionmanageroncontinuestatechange10)。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 属性

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称       | 类型   | 只读   | 必填   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| srcDeviceId | string | 否    | 是    | 表示任务迁移源设备ID。 |
| bundleName | string | 否    | 是    | 表示任务所属目标端应用包名。 |
| srcBundleName<sup>12+</sup> | string | 否    | 否    | 表示任务所属源端应用包名，默认与bundleName相同。 |
| continueType<sup>12+</sup> | string | 否    | 否    | 表示任务所属应用迁移类型。 |