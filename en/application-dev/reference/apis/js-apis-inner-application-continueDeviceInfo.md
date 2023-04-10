# ContinueDeviceInfo

The **ContinueDeviceInfo** module defines the parameters required for initiating mission continuation. For details about mission continuation, see [continueMission](js-apis-distributedMissionManager.md#distributedmissionmanagercontinuemission).

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name      | Type  | Readable  | Writable  | Description     |
| -------- | ------ | ---- | ---- | ------- |
| srcDeviceId | string | Yes   | Yes   | ID of the source device.|
| dstDeviceId | string | Yes   | Yes   | ID of the target device.|
| missionId | number | Yes   | Yes   | Mission ID.|
| wantParam | {[key: string]: any} | Yes   | Yes   | Extended parameters.|

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
