# ContinueDeviceInfo

The **ContinueDeviceInfo** module defines the parameters required for initiating mission continuation. For details about mission continuation, see [continueMission](js-apis-distributedMissionManager.md#distributedmissionmanagercontinuemission).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

| Name      | Type  | Readable  | Writable  | Description     |
| -------- | ------ | ---- | ---- | ------- |
| srcDeviceId | string | Yes   | Yes   | ID of the source device.|
| dstDeviceId | string | Yes   | Yes   | ID of the target device.|
| missionId | number | Yes   | Yes   | Mission ID.|
| wantParam | {[key: string]: any} | Yes   | Yes   | Extended parameters.|

**Example**

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
