# ContinueMissionInfo

The **ContinueMissionInfo** module defines the parameters required for initiating mission continuation with the bundle name specified. For details about mission continuation, see [continueMission](js-apis-distributedMissionManager.md#distributedmissionmanagercontinuemission10).

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name      | Type  | Readable  | Writable  | Description     |
| -------- | ------ | ---- | ---- | ------- |
| srcDeviceId | string | Yes   | Yes   | ID of the source device.|
| dstDeviceId | string | Yes   | Yes   | ID of the target device.|
| bundleName | string | Yes   | Yes   | Name of the bundle to which the mission belongs.|
| wantParam | Record<string, Object> | Yes   | Yes   | Extended parameters.|
