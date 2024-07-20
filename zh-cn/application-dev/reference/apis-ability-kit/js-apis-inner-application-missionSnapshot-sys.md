# MissionSnapshot (系统接口)

一个任务的任务快照对象，可以通过[missionManager.getMissionSnapShot](js-apis-app-ability-missionManager-sys.md#missionmanagergetmissionsnapshot)获取。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口均为系统接口，三方应用不支持调用。

## 导入模块

```ts
import { missionManager } from '@kit.AbilityKit';
```

## 属性

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| ability | ElementName | 是 | 是 | 表示该任务的组件信息。 | 
| snapshot | [PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | 是 | 是 | 表示任务快照。 |

## 使用说明

通过missionManager中的getMissionSnapShot来获取。

**示例：**
```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  missionManager.getMissionInfos('', 10, (error, missions) => {
    if (error) {
      console.error(`getMissionInfos failed, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}`);
      return;
    }
    console.log(`size = ${missions.length}`);
    console.log(`missions = ${JSON.stringify(missions)}`);
    let id = missions[0].missionId;

    missionManager.getMissionSnapShot('', id, (err, snapshot) => {
      if (err) {
        console.error(`getMissionInfos failed, err.code: ${JSON.stringify(err.code)}, err.message: ${JSON.stringify(err.message)}`);
        return;
      }
      // 执行正常业务
      console.log(`bundleName = ${snapshot.ability.bundleName}`);
    });
  });
} catch (paramError) {
  console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
}
```