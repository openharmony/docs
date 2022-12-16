# ContinueCallback

The **ContinueCallback** module defines the callback invoked when the mission continuation is complete.

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name                   | Type      | Readable  | Writable  | Description                |
| --------------------- | -------- | ---- | ---- | ------------------ |
| onContinueDone | function | Yes   | No   | Callback used to notify the user that the mission continuation is complete and return the continuation result.    |

**Example**

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
