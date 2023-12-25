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
| wantParam | Record<string, Object> | Yes   | Yes   | Extended parameters.|
