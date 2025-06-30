# MissionParameter (System API)

The **MissionParameter** module defines the parameters required for mission synchronization. It can be used an input parameter in [startSyncRemoteMissions](js-apis-distributedMissionManager-sys.md#distributedmissionmanagerstartsyncremotemissions).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

## Attributes

| Name         | Type   | Read-Only  | Optional  | Description         |
| ----------- | ------- | ---- | ---- | ----------- |
| deviceId    | string  | Yes   | No   | Device ID.    |
| fixConflict | boolean | Yes   | No   | Whether a version conflict exists. The value **true** means that a version conflict exists, and **false** means the opposite.|
| tag         | number  | Yes   | No   | Tag of the mission. The value **0** means the default tag.   |
