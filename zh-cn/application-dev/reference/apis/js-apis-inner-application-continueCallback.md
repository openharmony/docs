# ContinueCallback

表示迁移完成后，返回迁移结果回调函数，可以作为[continueMission](js-apis-distributedMissionManager.md#distributedmissionmanagercontinuemission)的入参监听迁移回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称                    | 类型       | 可读   | 可写   | 说明                 |
| --------------------- | -------- | ---- | ---- | ------------------ |
| onContinueDone | function | 是    | 否    | 通知迁移完成，返回迁移结果。     |

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