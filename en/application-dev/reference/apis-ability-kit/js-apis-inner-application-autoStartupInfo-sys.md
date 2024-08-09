 # AutoStartupInfo (System API)

The **AutoStartupInfo** module defines information about the application component that automatically starts upon system boot.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
> The APIs provided by this module are system APIs.

## Properties

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                     | Type  | Mandatory | Description      |
| ------------------------- | ------ | ---- | --------- |
| bundleName   | string | Yes | Bundle name. |
| moduleName | string | No  | Module name. |
| abilityName | string | Yes | Ability name. |
| abilityTypeName | string | No | Ability type. |
| appCloneIndex | number   | No  | Index of an application clone. |

**Example**

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';

autoStartupManager.setApplicationAutoStartup({
  bundleName: 'com.example.autostartupapp',
  moduleName: 'entry',
  abilityName: 'EntryAbility',
  abilityTypeName: 'ServiceExtension'
} as common.AutoStartupInfo, (err, data) => {
  console.info('====> err: ' + JSON.stringify(err) + ' data: ' + JSON.stringify(data));
});
```
