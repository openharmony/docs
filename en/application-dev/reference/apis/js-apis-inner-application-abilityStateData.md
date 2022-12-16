# AbilityStateData

The **AbilityStateData** module defines the ability state information.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                    | Type    | Readable| Writable| Description                      |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| pid<sup>8+</sup>                     | number   | Yes  | No  | Process ID.                   |
| bundleName<sup>8+</sup>              | string   | Yes  | No | Bundle name of an application.                 |
| abilityName<sup>8+</sup>             | string   | Yes  | No  | Ability name.              |
| uid<sup>8+</sup>                     | number   | Yes  | No  | User ID.                 |
| state<sup>8+</sup>                   | number   | Yes  | No  | Ability state.               |
| moduleName<sup>9+</sup> | string   | Yes  | No  | Name of the HAP file to which the ability belongs.   |
| abilityType<sup>8+</sup> | string   | Yes  | No  | Ability type.   |

**Example**
```ts
import appManager from "@ohos.application.appManager"

appManager.getForegroundApplications((error, data) => {
    for(let i=0; i<data.length; i++) {
        let appStateData = data[i];
        console.info('appStateData.pid: ' + appStateData.pid);
        console.info('appStateData.bundleName: ' + appStateData.bundleName);
        console.info('appStateData.abilityName: ' + appStateData.abilityName);
        console.info('appStateData.uid: ' + appStateData.uid);
        console.info('appStateData.state: ' + appStateData.state);
        console.info('appStateData.moduleName: ' + appStateData.moduleName);
        console.info('appStateData.abilityType: ' + appStateData.abilityType);
    }
});
```
