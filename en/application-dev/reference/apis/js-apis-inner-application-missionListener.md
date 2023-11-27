# MissionListener

The **MissionListener** module defines the listeners used to observe the mission status. The listeners can be registered by using [on](js-apis-app-ability-missionManager.md#missionmanageron).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import missionManager from '@ohos.app.ability.missionManager';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

| Name       | Type                | Mandatory| Description                                                        |
| ----------- | -------- | ---- | ------------------------------------------------------------ |
| onMissionCreated    | function               | No  | Called when the system creates a mission.                               |
| onMissionDestroyed   | function               | No  | Called when the system destroys the mission.|
| onMissionSnapshotChanged   | function               | No  | Called when the system updates the mission snapshot.|
| onMissionMovedToFront   | function               | No  | Called when the system moves the mission to the foreground.|
| onMissionLabelUpdated<sup>9+</sup>   | function               | No  | Called when the system updates the mission label.|
| onMissionIconUpdated<sup>9+</sup>   | function               | No  | Called when the system updates the mission icon.|
| onMissionClosed<sup>9+</sup>   | function               | No  | Called when the system closes the mission.|

**Example**
```ts
import missionManager from '@ohos.app.ability.missionManager';

let listener: missionManager.MissionListener = {
  onMissionCreated: (mission) => {
    console.log(`onMissionCreated mission: ${JSON.stringify(mission)}`);
  },
  onMissionDestroyed: (mission) => {
    console.log(`onMissionDestroyed mission: ${JSON.stringify(mission)}`);
  },
  onMissionSnapshotChanged: (mission) => {
    console.log(`onMissionSnapshotChanged mission: ${JSON.stringify(mission)}`);
  },
  onMissionMovedToFront: (mission) => {
    console.log(`onMissionMovedToFront mission: ${JSON.stringify(mission)}`);
  },
  onMissionLabelUpdated: (mission) => {
    console.log(`onMissionLabelUpdated mission: ' + ${JSON.stringify(mission)}`);
  },
  onMissionIconUpdated: (mission, icon) => {
    console.log(`onMissionIconUpdated mission: ' + ${JSON.stringify(mission)}`);
    console.log(`onMissionIconUpdated icon: ' + ${JSON.stringify(mission)}`);
  },
  onMissionClosed: (mission) => {
    console.log(`onMissionClosed mission: ' + ${JSON.stringify(mission)}`);
  },
}

try {
  let listenerId = missionManager.on('mission', listener);
} catch (paramError) {
  console.error(`error: ${paramError.code}, ${paramError.message}`);
}
```
