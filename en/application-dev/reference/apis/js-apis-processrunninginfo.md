# ProcessRunningInfo

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

Provides process running information.

## Modules to Import

```js
import appManager from '@ohos.application.appManager'
```

## Usage

The process running information is obtained through an **appManager** instance.

```js
import appManager from '@ohos.application.appManager';
appManager.getProcessRunningInfos((error,data) => { 
    console.log("getProcessRunningInfos error: "  + error.code + " data: " + JSON.stringify(data));
});
```


## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

  | Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| pid | number | Yes| No| Process ID.| 
| uid | number | Yes| No| User ID.| 
| processName | string | Yes| No| Process name.| 
| bundleNames | Array&lt;string&gt; | Yes| No| Names of all bundles running in the process.| 
