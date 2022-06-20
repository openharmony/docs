# ExtensionRunningInfo

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Provides extension running information.

## Modules to Import

```js
import abilitymanager from '@ohos.application.abilityManager';
```

## Usage


The extension running information is obtained through an **abilityManager** instance.

```js
import abilitymanager from '@ohos.application.abilityManager';
abilitymanager.getExtensionRunningInfos(upperLimit, (err,data) => { 
    console.log("getExtensionRunningInfos err: "  + err + " data: " + JSON.stringify(data));
});
```


### Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| extension | ElementName | Yes| No| Information that matches an extension.|
| pid | number | Yes| No| Process ID.|
| uid | number | Yes| No| User ID.|
| processName | string | Yes| No| Process name.|
| startTime | number | Yes| No| Extension start time.|
| clientPackage | Array&lt;String&gt; | Yes| No| Names of all packages in the process.|
| type | [bundle.ExtensionAbilityType](#bundleextensionabilitytype) | Yes| No| Extension type.|


## bundle.ExtensionAbilityType

Enumerates extension types.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name| Value| Description|
| -------- | -------- | -------- |
| FORM | 0 | Extension information of the form type.< |
| WORK_SCHEDULER | 1 | Extension information of the work scheduler type.< |
| INPUT_METHOD | 2 | Extension information of the input method type.< |
| SERVICE | 3 | Extension information of the service type.< |
| ACCESSIBILITY | 4 | Extension information of the accessibility type.< |
| DATA_SHARE | 5 | Extension information of the data share type.< |
| FILE_SHARE | 6 | Extension information of the file share type.< |
| STATIC_SUBSCRIBER | 7 | Extension information of the static subscriber type.< |
| WALLPAPER | 8 | Extension information of the wallpaper type.< |
| UNSPECIFIED | 9 | Extension information of the unspecified type.< |
