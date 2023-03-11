# ContinueCallback

The **ContinueCallback** module defines the callback function that indicates the result of mission continuation. For details about mission continuation, see [continueMission](js-apis-distributedMissionManager.md#distributedmissionmanagercontinuemission).

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name                    | Type      | Readable   | Writable   | Description                 |
| --------------------- | -------- | ---- | ---- | ------------------ |
| onContinueDone | function | Yes    | No    | Mission continuation result.     |

**Example**

  ```ts
  import distributedMissionManager from '@ohos.distributedMissionManager';

  let continueDeviceInfo = {
    srcDeviceId: '123',
    dstDeviceId: '456',
    missionId: 123,
    wantParam: {
        'key':'value'
    }
  };

  let continueCallback = {
      onContinueDone(result) {
          console.log('onContinueDone, result: ' + JSON.stringify(result));
      }
  };

  distributedMissionManager.continueMission(continueDeviceInfo, continueCallback, (error) => {
    if (error.code != 0) {
        console.error('continueMission failed, cause: ' + JSON.stringify(error))
    }
    console.info('continueMission finished')
  })
  ```
