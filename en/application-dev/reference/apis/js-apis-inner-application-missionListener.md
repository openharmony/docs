# MissionListener

The **MissionListener** module defines the listeners used to observe the mission status. The listeners can be registered by using [on](js-apis-app-ability-missionManager.md#missionmanageron).

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name       | Type                | Mandatory| Description                                                        |
| ----------- | -------- | ---- | ------------------------------------------------------------ |
| onMissionCreated    | function               | No  | Called when the system creates a mission.                               |
| onMissionDestroyed   | function               | No  | Called when the system destroys the mission.|
| onMissionSnapshotChanged   | function               | No  | Called when the system updates the mission snapshot.|
| onMissionMovedToFront   | function               | No  | Called when the system moves the mission to the foreground.|
| onMissionLabelUpdated   | function               | No  | Called when the system updates the mission label.|
| onMissionIconUpdated   | function               | No  | Called when the system updates the mission icon.|
| onMissionClosed   | function               | No  | Called when the system closes the mission.|

**Example**
```ts
import missionManager from '@ohos.app.ability.missionManager'

let listener = {
    onMissionCreated: function (mission) {
        console.log("onMissionCreated mission: " + JSON.stringify(mission));
    },
    onMissionDestroyed: function (mission) {
        console.log("onMissionDestroyed mission: " + JSON.stringify(mission));
    },
    onMissionSnapshotChanged: function (mission) {
        console.log("onMissionSnapshotChanged mission: " + JSON.stringify(mission));
    },
    onMissionMovedToFront: function (mission) {
        console.log("onMissionMovedToFront mission: " + JSON.stringify(mission));
    },
    onMissionIconUpdated: function (mission, icon) {
        console.log("onMissionIconUpdated mission: " + JSON.stringify(mission));
    },
    onMissionClosed: function (mission) {
        console.log("onMissionClosed mission: " + JSON.stringify(mission));
    }
};

try {
    let listenerId = missionManager.on("mission", listener);
} catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
}
```
