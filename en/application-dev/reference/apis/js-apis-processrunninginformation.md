# ProcessRunningInformation<sup>9+</sup>

The **ProcessRunningInformation** module provides process running information.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Usage Guidelines

The process running information is obtained through [appManager](js-apis-appmanager.md#appmanagergetprocessrunninginformation9).

```js
import appManager from '@ohos.application.appManager';
appManager.getProcessRunningInformation((error,data) => { 
    console.log("getProcessRunningInformation error: "  + error.code + " data: " + JSON.stringify(data));
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
