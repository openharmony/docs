# PermissionRequestResult

The **PermissionRequestResult** module provides the result of a permission request.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Usage

The permission request result is obtained through an **AbilityStage** instance.

```js
import Ability from '@ohos.application.Ability'
export default class MainAbility extends Ability {
  onWindowStageCreate(windowStage) {
    var permissions=['com.example.permission']
    var permissionRequestResult;
    this.context.requestPermissionsFromUser(permissions,(err,result) => {
      if(err){
        console.log('requestPermissionsFromUserError: ' + JSON.stringify(err));
      }else{
        permissionRequestResult=result;
        console.log('permissionRequestResult: ' + JSON.stringify(permissionRequestResult));
      }    
    });
  }
}
```


## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

  | Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | Yes| No| Permissions requested.| 
| authResults | Array&lt;number&gt; | Yes| No| Whether the requested permissions are granted or denied. The value **0** means that the requests permissions are granted, and a non-zero value means the opposite. | 
