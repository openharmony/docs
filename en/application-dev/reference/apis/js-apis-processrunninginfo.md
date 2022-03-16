# ProcessRunningInfo

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Provides process running information.


## Usage


The process running information is obtained through an **appManager** instance.


  
```
import appManager from '@ohos.application.appManager';
appManager.getProcessRunningInfos((error,data) => { 
    console.log("getProcessRunningInfos error: "  + error.code + " data: " + JSON.stringify(data));
});
```


## Attributes

  | Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| pid | number | Yes| No| Process ID. <br><b>System capability</b>: SystemCapability.Ability.AbilityRuntime.Core| 
| uid | number | Yes| No| User ID. <br><b>System capability</b>: SystemCapability.Ability.AbilityRuntime.Core| 
| processName | string | Yes| No| Process name. <br><b>System capability</b>: SystemCapability.Ability.AbilityRuntime.Core| 
| bundleNames | Array&lt;string&gt; | Yes| No| Names of all bundles running in the process. <br><b>System capability</b>: SystemCapability.Ability.AbilityRuntime.Core| 
