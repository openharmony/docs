# MissionInfo

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import MissionInfo from '@ohos.application.missionInfo'
```

## MissionInfo

Provides the mission information.

**System capability**: SystemCapability.Ability.AbilityBase

| Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| missionId | number | Yes| Yes| Mission ID.| 
| runningState | number | Yes| Yes| Running state of the mission.| 
| lockedState | boolean | Yes| Yes| Locked state of the mission.| 
| timestamp | string | Yes| Yes| Latest time when the mission was created or updated.| 
| want | [Want](js-apis-application-Want.md) | Yes| Yes| **Want** information of the mission.| 
| label | string | Yes| Yes| Label of the mission.| 
| iconPath | string | Yes| Yes| Path of the mission icon.| 
| continuable | boolean | Yes| Yes| Whether the mission is continuable.| 
