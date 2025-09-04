# ExtensionRunningInfo (System API)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yewei0794-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

The ExtensionRunningInfo module encapsulates ExtensionAbility running information, which can be obtained through [getExtensionRunningInfos](js-apis-app-ability-abilityManager-sys.md#getextensionrunninginfos).

> **NOTE**
> 
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { abilityManager } from '@kit.AbilityKit';
```

## Usage

Import the abilityManager module and obtain the ExtensionAbility running information by calling the method in the abilityManager module.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| extension | [ElementName](js-apis-bundleManager-elementName.md) | No| No| ExtensionAbility information.|
| pid | number | No| No| Process ID.|
| uid | number | No| No| UID of the application.|
| processName | string | No| No| Process name.|
| startTime | number | No| No| Timestamp when the ExtensionAbility is started.|
| clientPackage | Array&lt;String&gt; | No| No| Names of all packages in the process.|
| type | [bundle.ExtensionAbilityType](js-apis-bundleManager.md#extensionabilitytype) | No| No| ExtensionAbility type.|

**Example**
```ts
import { abilityManager } from '@kit.AbilityKit';

let upperLimit = 1;

function getExtensionInfos() {
  abilityManager.getExtensionRunningInfos(upperLimit, (error, data) => {
    if (error) {
      console.error(`getForegroundApplications failed, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}`);
      return;
    }

    for (let i = 0; i < data.length; i++) {
      let extensionRunningInfo = data[i];
      console.info(`extensionRunningInfo.extension: ${JSON.stringify(extensionRunningInfo.extension)}`);
      console.info(`extensionRunningInfo.pid: ${JSON.stringify(extensionRunningInfo.pid)}`);
      console.info(`extensionRunningInfo.uid: ${JSON.stringify(extensionRunningInfo.uid)}`);
      console.info(`extensionRunningInfo.processName: ${JSON.stringify(extensionRunningInfo.processName)}`);
      console.info(`extensionRunningInfo.startTime: ${JSON.stringify(extensionRunningInfo.startTime)}`);
      console.info(`extensionRunningInfo.clientPackage: ${JSON.stringify(extensionRunningInfo.clientPackage)}`);
      console.info(`extensionRunningInfo.type: ${JSON.stringify(extensionRunningInfo.type)}`);
    }
  });
}
```
