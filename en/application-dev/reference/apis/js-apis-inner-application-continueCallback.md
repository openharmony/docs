# ContinueCallback

The **ContinueCallback** module defines the callback function that indicates the result of mission continuation. For details about mission continuation, see [continueMission](js-apis-distributedMissionManager.md#distributedmissionmanagercontinuemission).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ContinueCallback.onContinueDone

onContinueDone(result: number): void;

Called when the mission continuation is complete.

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | result |  number | Yes| Mission continuation result.|

**Example**

  ```ts
  import distributedMissionManager from '@ohos.distributedMissionManager';
  import { BusinessError } from '@ohos.base';

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
      onContinueDone(result) {
          console.log(`onContinueDone, result: ${JSON.stringify(result)}`);
      }
    }, (error: BusinessError) => {
      if (error && error.code) {
          console.error(`continueMission failed, error.code: ${error.code}, error.message: ${error.message}`);
      }
      console.log(`continueMission finished`);
    });
  ```
