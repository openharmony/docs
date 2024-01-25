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
| [windowMode](js-apis-app-ability-abilityConstant.md#abilityconstantwindowmode) | number | No| Window mode.<br>**System API**: This is a system API and cannot be called by third-party applications.|
| displayId | number | No| Display ID. The default value is **0**, indicating the current display.|
| withAnimation<sup>11+</sup> | boolean | No| Whether the ability has the animation effect.|
| windowLeft<sup>11+</sup> | number | No| Left position of the window.|
| windowTop<sup>11+</sup> | number | No| Top position of the window.|
| windowWidth<sup>11+</sup> | number | No| Width of the window.|
| windowHeight<sup>11+</sup> | number | No| Height of the window.|

**Example**

  ```ts
  import missionManager from '@ohos.app.ability.missionManager';
  import StartOptions from '@ohos.app.ability.StartOptions';
  import { BusinessError } from '@ohos.base';

  try {
    missionManager.getMissionInfos('', 10, (error, missions) => {
      if (error) {
          console.error(`getMissionInfos failed, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}`);
          return;
      }
      console.log(`size = ${missions.length}`);
      console.log(`missions = ${JSON.stringify(missions)}`);
      let id = missions[0].missionId;

      let startOptions: StartOptions = {
          windowMode : 101,
          displayId: 0
      };
      missionManager.moveMissionToFront(id, startOptions).then(() => {
  	    console.log('moveMissionToFront is called');
      });
    });
  } catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`error: ${code}, ${message}`);
  }
  ```
