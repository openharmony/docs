# MissionListener (System API)

The MissionListener module defines the listeners used to observe the mission status. The listeners can be registered by using [on](js-apis-app-ability-missionManager-sys.md#missionmanageronmission).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { missionManager } from '@kit.AbilityKit';
```

## Attributes

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

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
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
    console.log(`onMissionLabelUpdated mission: ${JSON.stringify(mission)}`);
  },
  onMissionIconUpdated: (mission, icon) => {
    console.log(`onMissionIconUpdated mission: ${JSON.stringify(mission)}`);
    console.log(`onMissionIconUpdated icon: ${JSON.stringify(icon)}`);
  },
  onMissionClosed: (mission) => {
    console.log(`onMissionClosed mission: ${JSON.stringify(mission)}`);
  }
};

try {
  let listenerId = missionManager.on('mission', listener);
} catch (paramError) {
  console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
}
```
