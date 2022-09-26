# ExtensionRunningInfo

The **ExtensionRunningInfo** module provides running information and states for Extension abilities.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module are system APIs and cannot be called by third-party applications.

## Usage

The Extension ability running information is obtained through an **abilityManager** instance.

```js
import abilityManager from '@ohos.application.abilityManager';
let upperLimit=1
abilityManager.getExtensionRunningInfos(upperLimit, (err,data) => {
    console.log("getExtensionRunningInfos err: "  + err + " data: " + JSON.stringify(data));
});
```

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
| type | [bundle.ExtensionAbilityType](js-apis-Bundle.md#extensionabilitytype9) | Yes| No| Extension ability type.|
