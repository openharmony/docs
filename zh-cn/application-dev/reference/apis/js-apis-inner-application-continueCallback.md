# ContinueCallback

表示跨设备迁移Mission完成后，返回迁移结果的回调函数，迁移Mission详见：[continueMission接口](js-apis-distributedMissionManager.md#distributedmissionmanagercontinuemission)。

## ContinueCallback.onContinueDone

onContinueDone(result: number): void;

Mission迁移完成后调用，返回迁移结果。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | result |  number | 否 | 迁移任务的结果。 |

**示例：**

  ```ts
  import distributedMissionManager from '@ohos.distributedMissionManager'

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
  };

  distributedMissionManager.continueMission(continueDeviceInfo, continueCallback, (error) => {
      if (error && error.code) {
          console.log('continueMission failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
      }
      console.log('continueMission finished');
  })
  ```
