# AutoStartupInfo (System API)

The module defines information about the application component that automatically starts upon system boot.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
> The APIs provided by this module are system APIs.

## Properties

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                       | Type   | Read-Only| Optional| Description                                          |
| --------------------------- | ------- | ---- | ---- | ---------------------------------------------- |
| bundleName                  | string  | No  | No  | Bundle name.                        |
| moduleName                  | string  | No  | Yes  | Module name.                        |
| abilityName                 | string  | No  | No  | Ability name.                       |
| abilityTypeName             | string  | No  | Yes  | Ability type.                       |
| appCloneIndex               | number  | No  | Yes  | Index of an application clone.                                |
| userId<sup>20+</sup>        | number  | Yes  | Yes  | User ID of the application.                            |
| setterUserId<sup>20+</sup>  | number  | Yes  | Yes  | ID of the user who sets this application to start automatically on boot.            |
| canUserModify<sup>20+</sup> | boolean | Yes  | Yes  | Whether the developer can change the auto-start status of this application.|

**Example**

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';

autoStartupManager.setApplicationAutoStartup({
  bundleName: 'com.example.autostartupapp',
  moduleName: 'entry',
  abilityName: 'EntryAbility',
  abilityTypeName: 'ServiceExtension'
} as common.AutoStartupInfo, (err) => {
  if (err) {
    console.error(`setApplicationAutoStartup failed, err code: ${err.code}, err msg: ${err.message}.`);
    return;
  }
  console.info(`setApplicationAutoStartup success.`);
});
```
