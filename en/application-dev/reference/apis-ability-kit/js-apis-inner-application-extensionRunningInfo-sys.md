# ExtensionRunningInfo (System API)

The **ExtensionRunningInfo** module encapsulates ExtensionAbility running information, which can be obtained through [getExtensionRunningInfos](js-apis-app-ability-abilityManager-sys.md#getextensionrunninginfos).

> **NOTE**
> 
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { abilityManager } from '@kit.AbilityKit';
```

## Usage

Import the **abilityManager** module and obtain the ExtensionAbility running information by calling the method in the **abilityManager** module.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: The following APIs are system APIs and cannot be called by third-party applications.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| extension | [ElementName](js-apis-bundleManager-elementName.md) | Yes | No | ExtensionAbility information. |
| pid | number | Yes | No | Process ID. |
| uid | number | Yes | No | UID of the application. |
| processName | string | Yes | No | Process name. |
| startTime | number | Yes | No | Timestamp when the ExtensionAbility is started. |
| clientPackage | Array&lt;String&gt; | Yes | No | Names of all packages in the process. |
| type | [ExtensionAbilityType](js-apis-bundleManager.md#extensionabilitytype) | Yes | No | ExtensionAbility type. |

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
      console.log(`extensionRunningInfo.extension: ${JSON.stringify(extensionRunningInfo.extension)}`);
      console.log(`extensionRunningInfo.pid: ${JSON.stringify(extensionRunningInfo.pid)}`);
      console.log(`extensionRunningInfo.uid: ${JSON.stringify(extensionRunningInfo.uid)}`);
      console.log(`extensionRunningInfo.processName: ${JSON.stringify(extensionRunningInfo.processName)}`);
      console.log(`extensionRunningInfo.startTime: ${JSON.stringify(extensionRunningInfo.startTime)}`);
      console.log(`extensionRunningInfo.clientPackage: ${JSON.stringify(extensionRunningInfo.clientPackage)}`);
      console.log(`extensionRunningInfo.type: ${JSON.stringify(extensionRunningInfo.type)}`);
    }
  });
}
```
