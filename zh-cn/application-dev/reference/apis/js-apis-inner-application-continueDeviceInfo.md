# ContinueDeviceInfo

表示发起任务迁移时所需参数的枚举，可以作为[continueMission](js-apis-distributedMissionManager.md#distributedmissionmanagercontinuemission)的入参指定迁移相关参数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称       | 类型   | 可读   | 可写   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| srcDeviceId | string | 是    | 是    | 表示任务迁移源设备ID。 |
| dstDeviceId | string | 是    | 是    | 表示任务迁移目标设备ID。 |
| missionId | number | 是    | 是    | 表示任务ID。 |
| wantParam | {[key: string]: any} | 是    | 是    | 表示扩展参数。 |

**示例：**

  ```ts
  import distributedMissionManager from '@ohos.distributedMissionManager';

  let continueDeviceInfo = {
    srcDeviceId: "123",
    dstDeviceId: "456",
    missionId: 123,
    wantParam: {
        "key":"value"
    }
  };

  let continueCallback = {
      onContinueDone(result) {
          console.log('onContinueDone, result: ' + JSON.stringify(result));
      }
  }

  distributedMissionManager.continueMission(continueDeviceInfo, continueCallback, (error) => {
    if (error.code != 0) {
        console.error('continueMission failed, cause: ' + JSON.stringify(error))
    }
    console.info('continueMission finished')
  })
  ```