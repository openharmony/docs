# @ohos.app.ability.abilityManager (Ability Information Management)

The AbilityManager module provides APIs for obtaining ability information and running status information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

## Modules to Import

```ts
import { abilityManager } from '@kit.AbilityKit';
```

## AbilityState<sup>14+</sup>

Enumerates the ability states. This enum can be used together with [AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo.md) to return the ability state.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Value| Description| 
| -------- | -------- | -------- |
| INITIAL | 0 | The ability is in the initial state.| 
| FOCUS | 2 | The ability has the focus.|
| FOREGROUND | 9 | The ability is in the foreground state. | 
| BACKGROUND | 10 | The ability is in the background state. | 
| FOREGROUNDING | 11 | The ability is in the state of being switched to the foreground. | 
| BACKGROUNDING | 12 | The ability is in the state of being switched to the background. | 


## abilityManager.getAbilityRunningInfos<sup>14+</sup>

getAbilityRunningInfos(): Promise\<Array\<AbilityRunningInfo>>

Obtains the UIAbility running information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<Array\<[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo.md)>> | Promise used to return the API call result and the UIAbility running information. You can perform error handling or custom processing in it.|

**Error codes**

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  abilityManager.getAbilityRunningInfos()
    .then((data: abilityManager.AbilityRunningInfo[]) => {
      console.log(`getAbilityRunningInfos success, data: ${JSON.stringify(data)}`);
    })
    .catch((error: BusinessError) => {
      console.error(`getAbilityRunningInfos fail, error code: ${JSON.stringify(error.code)}, error msg: ${JSON.stringify(error.message)}`);
    })
} catch (e) {
  let code = (e as BusinessError).code;
  let msg = (e as BusinessError).message;
  console.error(`getAbilityRunningInfos fail, error code: ${JSON.stringify(code)}, error msg: ${JSON.stringify(msg)}`);
}
```

## AbilityRunningInfo<sup>14+</sup>

type AbilityRunningInfo = _AbilityRunningInfo

Defines the level-2 module AbilityRunningInfo.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Type| Description|
| --- | --- |
| [_AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo.md) | AbilityRunningInfo, a level-2 module that provides the information and state related to an ability.|

## AbilityStateData<sup>14+</sup>

type AbilityStateData = _AbilityStateData.default

Defines the level-2 module AbilityStateData.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Type| Description|
| --- | --- |
| [_AbilityStateData.default](js-apis-inner-application-abilityStateData.md) | AbilityStateData, a level-2 module that provides the ability state information.|
