# ContinueCallback

The **ContinueCallback** module defines the callback function that indicates the result of mission continuation. For details about mission continuation, see [continueMission](js-apis-distributedMissionManager.md#distributedmissionmanagercontinuemission).

## ContinueCallback.onContinueDone

onContinueDone(result: number): void;

Called when the mission continuation is complete.

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | result |  number | No| Mission continuation result.|

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
          console.log('onContinueDone, result: ${JSON.stringify(result)}');
      }
  };

  distributedMissionManager.continueMission(continueDeviceInfo, continueCallback, (error) => {
      if (error && error.code) {
          console.error('continueMission failed, error.code: ${error.code}, error.message: ${error.message}');
      }
      console.log('continueMission finished');
  });
  ```
