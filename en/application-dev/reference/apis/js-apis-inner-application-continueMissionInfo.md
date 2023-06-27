# ContinueMissionInfo

The **ContinueMissionInfo** module defines the parameters required for initiating mission continuation with the bundle name specified. For details about mission continuation, see [continueMission](js-apis-distributedMissionManager.md#distributedmissionmanagercontinuemission10).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import distributedMissionManager from '@ohos.distributedMissionManager';
```

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name      | Type  | Readable  | Writable  | Description     |
| -------- | ------ | ---- | ---- | ------- |
| srcDeviceId | string | Yes   | Yes   | ID of the source device.|
| dstDeviceId | string | Yes   | Yes   | ID of the target device.|
| bundleName | string | Yes   | Yes   | Name of the bundle to which the mission belongs.|
| wantParam | {[key: string]: any} | Yes   | Yes   | Extended parameters.|

**Example**

  ```ts
  import distributedMissionManager from '@ohos.distributedMissionManager';

  var parameter =  {
      srcDeviceId: "",
      dstDeviceId: "",
      bundleName: "ohos.test.continueapp",
      wantParam: {"key": "value"}
  };
  try {
      distributedMissionManager.continueMission(parameter, (error) => {
          if (error.code != 0) {
              console.error('continueMission failed, cause: ' + JSON.stringify(error))
          }
          console.info('continueMission finished')
      })
  } catch (error) {
      console.error('continueMission failed, cause: ' + JSON.stringify(error))
  }
  ```
