# ContinueCallback

The **ContinueCallback** module defines the callback function that indicates the result of mission continuation. For details about mission continuation, see [continueMission](js-apis-distributedMissionManager.md#distributedmissionmanagercontinuemission).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ContinueCallback.onContinueDone

onContinueDone(result: number): void;

Called when the mission continuation is complete.

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name                   | Type      | Readable  | Writable  | Description                |
| --------------------- | -------- | ---- | ---- | ------------------ |
| onContinueDone | function | Yes   | No   | Mission continuation result.    |

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
