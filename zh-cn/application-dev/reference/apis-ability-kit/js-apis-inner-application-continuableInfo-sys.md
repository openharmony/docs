# ContinuableInfo (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: DistributedAbilityManager-->
<!--Owner: @hobbycao-->
<!--Designer: @gsxiaowen-->
<!--Tester: @zhaodengqi-->
<!--Adviser: @hu-zhiqiong-->

当注册应用任务流转状态监听的回调时，返回应用任务流转状态和流转信息，注册详见：[distributedMissionManager.on('continueStateChange')](js-apis-distributedMissionManager-sys.md#distributedmissionmanageroncontinuestatechange10)。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。
> 本模块接口仅可在Stage模型下使用。

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

## 导入模块

```js
import { distributedMissionManager } from '@kit.AbilityKit';
```

## ContinuableInfo

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**系统接口**：此接口为系统接口。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称       | 类型   | 只读   | 可选   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| srcDeviceId | string | 否    | 否    | 表示任务流转源设备ID。|
| bundleName | string | 否    | 否    | 表示任务所属目标端应用包名。该参数作为srcBundleName的默认值使用，当srcBundleName未传入时，其值默认与bundleName相同。 |
| srcBundleName<sup>12+</sup> | string | 否    | 是    | 表示任务所属源端应用包名。当源端和目标端应用包名不同时需要传入（如跨应用迁移、应用包名变更等场景），不传入时默认与bundleName相同。 |
| continueType<sup>12+</sup> | string | 否    | 是    | 表示任务所属应用迁移类型。取值由应用在配置文件中自定义，用于标识不同的任务流转策略（如多设备协同时的任务流转、跨设备复制任务状态等场景）。如果不传，则使用系统默认值。 |
