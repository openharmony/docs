# ProcessInformation

The **ProcessInformation** module defines the running information of a process.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import appManager from '@ohos.app.ability.appManager';
```

## Properties

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-Only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| pid | number | No| Yes| Process ID.|
| uid | number | No| Yes| User ID.|
| processName | string | No| Yes| Process name.|
| bundleNames | Array&lt;string&gt; | No| Yes| Names of all running bundles in the process.|
| state<sup>10+</sup> | [appManager.ProcessState](js-apis-app-ability-appManager.md#processstate10)| No| Yes| Running status of the process.|
| bundleType<sup>12+</sup> | [bundleManager.BundleType](js-apis-bundleManager.md#bundletype) | No| Yes| Type of the bundle running in the process.|
| appCloneIndex          | number   | No  | No  | Index of an application clone.                 |

## How to Use

The process information is obtained by calling [getRunningProcessInformation](js-apis-app-ability-appManager.md#appmanagergetrunningprocessinformation) of the **appManager** module.

**Example**

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
