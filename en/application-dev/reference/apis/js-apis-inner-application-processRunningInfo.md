# ProcessRunningInfo

The **ProcessRunningInfo** module provides process running information.

> **NOTE**
> - The APIs provided by this module are deprecated since API version 9. You are advised to use [ProcessRunningInformation<sup>9+</sup>](js-apis-inner-application-processRunningInformation.md) instead.
> - The initial APIs of this module are supported since API version 8.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| pid | number | Yes| No| Process ID.|
| uid | number | Yes| No| User ID.|
| processName | string | Yes| No| Process name.|
| bundleNames | Array&lt;string&gt; | Yes| No| Names of all running bundles in the process.|

## Usage

The process running information is obtained through [getProcessRunningInfos](js-apis-application-appManager.md##appManager.getProcessRunningInfos<sup>(deprecated)</sup>).

**Example**
```ts
import appManager from '@ohos.application.appManager';
app.getProcessRunningInfos().then((data) => {
    console.log('success:' + JSON.stringify(data));
}).catch((error) => {
    console.log('failed:' + JSON.stringify(error));
});
```
