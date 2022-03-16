# ExtensionRunningInfo

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Provides extension running information.


## Usage


The extension running information is obtained through an **abilityManager** instance.


  
```
import abilitymanager from '@ohos.application.abilityManager';
abilitymanager.getExtensionRunningInfos(upperLimit, (err,data) => { 
    console.log("getExtensionRunningInfos err: "  + err + " data: " + JSON.stringify(data));
});
```


### Attributes

  | Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| extension | ElementName | Yes| No| Information that matches an extension. <br><b>System capabilities: </b>SystemCapability.Ability.AbilityRuntime.Core| 
| pid | number | Yes| No| Process ID. <br><b>System capabilities: </b>SystemCapability.Ability.AbilityRuntime.Core| 
| uid | number | Yes| No| User ID. <br><b>System capabilities: </b>SystemCapability.Ability.AbilityRuntime.Core| 
| processName | string | Yes| No| Process name. <br><b>System capabilities: </b>SystemCapability.Ability.AbilityRuntime.Core| 
| startTime | number | Yes| No| Extension start time. <br><b>System capabilities: </b>SystemCapability.Ability.AbilityRuntime.Core| 
| clientPackage | Array&lt;String&gt; | Yes| No| Names of all packages in the process. <br><b>System capabilities: </b>SystemCapability.Ability.AbilityRuntime.Core| 
| type | [bundle.ExtensionAbilityType](#bundle-extensionabilitytype) | Yes| No| Extension type. <br><b>System capabilities: </b>SystemCapability.Ability.AbilityRuntime.Core| 


## bundle.ExtensionAbilityType

Enumerates the extension types.

  | Name| Value| Description| 
| -------- | -------- | -------- |
| FORM | 0 | Extension information of the form type. <br><b>System capabilities: </b>SystemCapability.BundleManager.BundleFramework| 
| WORK_SCHEDULER | 1 | Extension information of the work scheduler type. <br><b>System capabilities: </b>SystemCapability.BundleManager.BundleFramework| 
| INPUT_METHOD | 2 | Extension information of the input method type. <br><b>System capabilities: </b>SystemCapability.BundleManager.BundleFramework| 
| SERVICE | 3 | Extension information of the service type. <br><b>System capabilities: </b>SystemCapability.BundleManager.BundleFramework| 
| ACCESSIBILITY | 4 | Extension information of the accessibility type. <br><b>System capabilities: </b>SystemCapability.BundleManager.BundleFramework| 
| DATA_SHARE | 5 | Extension information of the data share type. <br><b>System capabilities: </b>SystemCapability.BundleManager.BundleFramework| 
| FILE_SHARE | 6 | Extension information of the file share type. <br><b>System capabilities: </b>SystemCapability.BundleManager.BundleFramework| 
| STATIC_SUBSCRIBER | 7 | Extension information of the static subscriber type. <br><b>System capabilities: </b>SystemCapability.BundleManager.BundleFramework| 
| WALLPAPER | 8 | Extension information of the wallpaper type. <br><b>System capabilities: </b>SystemCapability.BundleManager.BundleFramework| 
| UNSPECIFIED | 9 | Extension information of the unspecified type. <br><b>System capabilities: </b>SystemCapability.BundleManager.BundleFramework| 
