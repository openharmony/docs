# MissionSnapshot

The **MissionSnapshot** module defines the snapshot of a mission. The snapshot can be obtained through [getMissionSnapShot](js-apis-app-ability-missionManager.md#missionmanagergetmissionsnapshot).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module are system APIs and cannot be called by third-party applications.

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| ability | ElementName | Yes| Yes| Ability information of the mission.|
| snapshot | [image.PixelMap](js-apis-image.md) | Yes| Yes| Snapshot of the mission.|

## How to Use

The mission snapshot information can be obtained by using **getMissionSnapShot** in **missionManager**.

**Example**
```ts
  import ElementName from '@ohos.bundle';
  import image from '@ohos.multimedia.image';
  import missionManager from '@ohos.app.ability.missionManager';

  try {
    missionManager.getMissionInfos("", 10, (error, missions) => {
      if (error.code) {
          console.log("getMissionInfos failed, error.code:" + JSON.stringify(error.code) +
            "error.message:" + JSON.stringify(error.message));
          return;
      }
      console.log("size = " + missions.length);
      console.log("missions = " + JSON.stringify(missions));
      var id = missions[0].missionId;

      missionManager.getMissionSnapShot("", id, (err, snapshot) => {
        if (err.code) {
          console.log("getMissionInfos failed, err.code:" + JSON.stringify(err.code) +
            "err.message:" + JSON.stringify(err.message));
          return;
        }

        // Carry out normal service processing.
        console.log("bundleName = " + snapshot.ability.bundleName);
      })
    })
  } catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
  }
```
