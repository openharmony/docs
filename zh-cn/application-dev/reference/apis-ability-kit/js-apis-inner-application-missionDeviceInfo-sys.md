# MissionDeviceInfo (系统接口)

可以作为[registerMissionListener](js-apis-distributedMissionManager-sys.md#distributedmissionmanagerregistermissionlistener)的入参，表示注册监听时所需参数的枚举。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口为系统接口。

## 导入模块

```ts
import { distributedMissionManager } from '@kit.AbilityKit';
```

## 属性

**系统接口**：该接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称       | 类型   | 可读   | 可写   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| deviceId | string | 是    | 是    | 表示设备ID。 |
