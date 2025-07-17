# ContinueDeviceInfo (System API)

The module defines the parameters required for initiating mission continuation. For details about mission continuation, see [continueMission](js-apis-distributedMissionManager-sys.md#distributedmissionmanagercontinuemission).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

| Name      | Type  | Read-Only  | Optional  | Description     |
| -------- | ------ | ---- | ---- | ------- |
| srcDeviceId | string | No   | No   | ID of the source device.|
| dstDeviceId | string | No   | No   | ID of the target device.|
| missionId | number | No   | No   | Mission ID.|
| wantParam | Record<string, Object> | No   | No   | Extended parameters.|
