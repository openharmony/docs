# ContinueDeviceInfo

表示发起Mission迁移时所需参数的枚举，迁移Mission详见：[continueMission接口](js-apis-distributedMissionManager.md#distributedmissionmanagercontinuemission)。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称       | 类型   | 可读   | 可写   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| srcDeviceId | string | 是    | 是    | 表示任务迁移源设备ID。 |
| dstDeviceId | string | 是    | 是    | 表示任务迁移目标设备ID。 |
| missionId | number | 是    | 是    | 表示任务ID。 |
| wantParam | {[key: string]: any} | 是    | 是    | 表示扩展参数。 |

**示例：**

  ```ts
  import distributedMissionManager from '@ohos.distributedMissionManager';

  distributedMissionManager.continueMission(
    {
      srcDeviceId: '123',
      dstDeviceId: '456',
      missionId: 123,
      wantParam: {
          'key':'value'
      }
    },
    {
      onContinueDone(result): void {
          console.log(`onContinueDone, result: ${JSON.stringify(result)}`);
      }
    }, (error) => {
      if (error && error.code) {
          console.error(`continueMission failed, error.code: ${error.code}, error.message: ${error.message}`);
      }
      console.log('continueMission finished');
  });
  ```
