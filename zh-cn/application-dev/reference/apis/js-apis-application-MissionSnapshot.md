# MissionSnapshot

MissionSnapshot模块提供设置与任务对应的任务快照的任务元素名称的能力。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口均为系统接口，三方应用不支持调用

## 使用说明

通过missionManager中的getMissionSnapShot来获取。

```js
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
## MissionSnapshot

表示任务对应的任务快照的枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Mission

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| ability | ElementName | 是 | 是 | 表示Ability任务元素名称。 |
| snapshot | [image.PixelMap](js-apis-image.md) | 是 | 是 | 表示任务快照。 |
