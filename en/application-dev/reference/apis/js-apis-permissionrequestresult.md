# PermissionRequestResult

The **PermissionRequestResult** module defines the result of a permission request. The result is returned when [requestPermissionsFromUser](js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) is called to request permissions.

> **NOTE**
> 
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> - The APIs of this module can be used only in the stage model.

## Attributes

**System capability**: SystemCapability.Security.AccessToken

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | Yes| No| Permissions requested.|
| authResults | Array&lt;number&gt; | Yes| No| Result of the permission request.<br>- **-1**: The permission is not authorized and must be set in **Settings** without displaying a dialog box.<br>- **0**: The permission is authorized.<br>- **2**: The permission is not authorized due to an invalid request. The possible causes are as follows:<br>  - The permission is not declared in the configuration file.<br>  - The permission name is invalid.<br>  - Special conditions for applying for the permission are not satisfied. See [ohos.permission.LOCATION](../../security/permission-list.md#ohospermissionlocation) and [ohos.permission.APPROXIMATELY_LOCATION](../../security/permission-list.md#ohospermissionapproximately_location).|

## Usage

The permission request result is obtained through an **atManager** instance.

**Example**
```ts
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';
let atManager = abilityAccessCtrl.createAtManager();
try {
  atManager.requestPermissionsFromUser(this.context, ["ohos.permission.CAMERA"]).then((data) => {
      console.info("data:" + JSON.stringify(data));
      console.info("data permissions:" + data.permissions);
      console.info("data authResults:" + data.authResults);
  }).catch((err) => {
      console.info("data:" + JSON.stringify(err));
  })
} catch(err) {
  console.log(`catch err->${JSON.stringify(err)}`);
}
```
