# @ohos.app.ability.StartOptions (StartOptions)

**StartOptions** is used as an input parameter of [startAbility()](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1) to specify the window mode of an ability.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import StartOptions from '@ohos.app.ability.StartOptions';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| [windowMode](js-apis-app-ability-abilityConstant.md#abilityconstantwindowmode) | number | No| Window mode.|
| displayId | number | No| Display ID. The default value is **0**, indicating the current display.|

**Example**

  ```ts
  import missionManager from '@ohos.app.ability.missionManager';

  try {
    missionManager.getMissionInfos('', 10, (error, missions) => {
      if (error) {
          console.error(`getMissionInfos failed, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}`);
          return;
      }
      console.log(`size = ${missions.length}`);
      console.log(`missions = ${JSON.stringify(missions)}`);
      let id = missions[0].missionId;

      let startOptions = {
          windowMode : 101,
          displayId: 0
      };
      missionManager.moveMissionToFront(id, startOptions).then(() => {
  	    console.log('moveMissionToFront is called');
      });
    });
  } catch (paramError) {
    console.error(`error: ${paramError.code}, ${paramError.message}`);
  }
  ```
