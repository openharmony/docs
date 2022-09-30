# ProcessRunningInfo<sup>(deprecated)</sup>

The **ProcessRunningInfo** module provides process running information.

> **NOTE**
> - The APIs provided by this module are deprecated since API version 9. You are advised to use [ProcessRunningInformation<sup>9+</sup>](js-apis-processrunninginformation.md) instead.
> - The initial APIs of this module are supported since API version 8.

## Usage

The process running information is obtained through an **appManager** instance.

```js
import appManager from '@ohos.application.appManager';
appManager.getProcessRunningInfos((error,data) => { 
    console.log("getProcessRunningInfos error: "  + error.code + " data: " + JSON.stringify(data));
});
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| pid | number | Yes| No| Process ID.| 
| uid | number | Yes| No| User ID.| 
| processName | string | Yes| No| Process name.| 
| bundleNames | Array&lt;string&gt; | Yes| No| Names of all bundles running in the process.| 
