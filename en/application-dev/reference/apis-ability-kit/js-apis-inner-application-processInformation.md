# ProcessInformation

The **ProcessInformation** module defines the running information of a process.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { appManager } from '@kit.AbilityKit';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| pid | number | No| No| Process ID.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| uid | number | No| No| User ID.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| processName | string | No| No| Process name.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| bundleNames | Array&lt;string&gt; | No| No| Names of all running bundles in the process.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| state<sup>10+</sup> | [appManager.ProcessState](js-apis-app-ability-appManager.md#processstate10)| No| No| Running status of the process.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| bundleType<sup>12+</sup> | [bundleManager.BundleType](js-apis-bundleManager.md#bundletype) | No| No| Type of the bundle running in the process.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| appCloneIndex<sup>12+</sup> | number   | No  | Yes  | Index of an application clone.<br>**Atomic service API**: This API can be used in atomic services since API version 12. |

## How to Use

The process information is obtained by calling [getRunningProcessInformation](js-apis-app-ability-appManager.md#appmanagergetrunningprocessinformation) of the **appManager** module.

**Example**

```ts
import { appManager } from '@kit.AbilityKit';

appManager.getRunningProcessInformation((error, data) => {
  if (error) {
    console.error(`getRunningProcessInformation fail, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`getRunningProcessInformation success, data: ${JSON.stringify(data)}`);
  }
});
```
