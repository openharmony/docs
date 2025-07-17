# ProcessRunningInfo
<!--deprecated_code_no_check-->

The module defines the running information of a process.

> **NOTE**
> - The APIs provided by this module are deprecated since API version 9. You are advised to use [ProcessInformation<sup>9+</sup>](js-apis-inner-application-processInformation.md) instead.
> - The initial APIs of this module are supported since API version 8.

## Modules to Import

```ts
import appManager from '@ohos.application.appManager';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| pid | number | No| No| Process ID.|
| uid | number | No| No| User ID.|
| processName | string | No| No| Process name.|
| bundleNames | Array&lt;string&gt; | No| No| Names of all running bundles in the process.|

## Usage

The process running information is obtained by using [getProcessRunningInfos](js-apis-application-appManager.md#appmanagergetprocessrunninginfosdeprecated) in appManager.

**Example**
```ts
import appManager from '@ohos.application.appManager';
import { BusinessError } from '@ohos.base';

appManager.getProcessRunningInfos().then((data) => {
    console.info(`success: ${JSON.stringify(data)}`);
}).catch((error: BusinessError) => {
    console.error(`failed: ${JSON.stringify(error)}`);
});
```
