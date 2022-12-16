# ExtensionRunningInfo

The **ExtensionRunningInfo** module provides running information and states for Extension abilities.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module are system APIs and cannot be called by third-party applications.

## Usage

The Extension ability running information is obtained through an **abilityManager** instance.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| extension | ElementName | Yes| No| Information that matches an Extension ability.|
| pid | number | Yes| No| Process ID.|
| uid | number | Yes| No| User ID.|
| processName | string | Yes| No| Process name.|
| startTime | number | Yes| No| Start time of the Extension ability.|
| clientPackage | Array&lt;String&gt; | Yes| No| Names of all packages in the process.|
| type | [bundle.ExtensionAbilityType](js-apis-Bundle.md) | Yes| No| Extension ability type.|

**Example**
```ts
import abilityManager from '@ohos.application.abilityManager';
let upperLimit=1;
abilityManager.getExtensionRunningInfos(upperLimit, (err,data) => {
    console.log("getExtensionRunningInfos err: "  + err + " data: " + JSON.stringify(data));
    for (let i=0; i<data.length; i++) {
        let extensionRunningInfo = data[i];
        console.log("extensionRunningInfo.extension: " + JSON.stringify(extensionRunningInfo.extension));
        console.log("extensionRunningInfo.pid: " + JSON.stringify(extensionRunningInfo.pid));
        console.log("extensionRunningInfo.uid: " + JSON.stringify(extensionRunningInfo.uid));
        console.log("extensionRunningInfo.processName: " + JSON.stringify(extensionRunningInfo.processName));
        console.log("extensionRunningInfo.startTime: " + JSON.stringify(extensionRunningInfo.startTime));
        console.log("extensionRunningInfo.clientPackage: " + JSON.stringify(extensionRunningInfo.clientPackage));
        console.log("extensionRunningInfo.type: " + JSON.stringify(extensionRunningInfo.type));
    }
});
```
