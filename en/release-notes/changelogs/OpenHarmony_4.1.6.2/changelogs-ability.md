# Ability Subsystem Changelog

## cl.ability.1 Permission Changed for startAbilityByCall

**Access Level**

Public APIs

**Reason for the Change**

The **startAbilityByCall** API is a public API and does not match the **ohos.permission.ABILITY_BACKGROUND_COMMUNICATION** permission level. The permission level should be **ohos.permission.DISTRIBUTED_DATASYNC**.

**Change Impact**

The API calling permission is changed.

The APIs can be used only after the corresponding permission is configured.
After the change, the API can be used only in migration scenarios. The corresponding system API will be provided to support more scenarios.

**API Level**

9

**Change Since**

Openharmony SDK OpenHarmony_4.1.6.1

**Key API/Component Changes**

| API| Before Change| After Change|
| ------- | ----- | ------ |
| startAbilityByCall(want: Want): Promise\<Caller> | The **ohos.permission.ABILITY_BACKGROUND_COMMUNICATION** permission is required| The **ohos.permission.DISTRIBUTED_DATASYNC** permission is required.|

**Adaptation Guide**

Declare the **ohos.permission.DISTRIBUTED_DATASYNC** permission, and use the API only in migration scenarios.

