# MissionSnapshot

The **MissionSnapshot** module provides the mission snapshot information of an ability.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module are system APIs and cannot be called by third-party applications.

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| ability | ElementName | Yes| Yes| Information that matches an ability.|
| snapshot | [image.PixelMap](js-apis-image.md) | Yes| Yes| Snapshot of the mission.|

## How to Use

The mission snapshot information can be obtained by using **getMissionSnapShot** in **missionManager**.

**Example**
```ts
import ElementName from '@ohos.bundle';
import image from '@ohos.multimedia.image';
import missionManager from '@ohos.application.missionManager';

missionManager.getMissionInfos("", 10, (error, missions) => {
  console.log("getMissionInfos is called, error.code = " + error.code);
  console.log("size = " + missions.length);
  console.log("missions = " + JSON.stringify(missions));
  var id = missions[0].missionId;

  missionManager.getMissionSnapShot("", id, (error, snapshot) => {
    console.log("getMissionSnapShot is called, error.code = " + error.code);
    console.log("bundleName = " + snapshot.ability.bundleName);
  })
})
```
