# ProcessInformation

The **ProcessInformation** module defines the running information of a process.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import appManager from '@ohos.app.ability.appManager';
```

## How to Use

The process information is obtained by calling [getRunningProcessInformation](js-apis-app-ability-appManager.md#appmanagergetrunningprocessinformation9) of the **appManager** module.

```ts
import appManager from '@ohos.app.ability.appManager';

appManager.getRunningProcessInformation((error, data) => { 
    if (error) {
        console.error(`getRunningProcessInformation fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getRunningProcessInformation success, data: ${JSON.stringify(data)}`);
    }
});
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| pid | number | Yes| No| Process ID.|
| uid | number | Yes| No| User ID.|
| processName | string | Yes| No| Process name.|
| bundleNames | Array&lt;string&gt; | Yes| No| Names of all running bundles in the process.|
| state<sup>10+</sup> | [appManager.ProcessState](js-apis-app-ability-appManager.md#processstate)| Yes| No| Running status of the process.|
