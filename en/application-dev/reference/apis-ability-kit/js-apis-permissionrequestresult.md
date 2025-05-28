# PermissionRequestResult

The **PermissionRequestResult** module defines the permission request result returned by [requestPermissionsFromUser](js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> - The APIs of this module can be used only in the stage model.

## Properties

**System capability**: SystemCapability.Security.AccessToken

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | Yes| No| Permissions requested.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| authResults | Array&lt;number&gt; | Yes| No| Result of the permission request.<br>- **-1**: The permission is not granted. If **dialogShownResults** is **true**, it is the first time that the user requests the permission. If **dialogShownResults** is **false**, the permission has been set and no dialog box is displayed. The user can modify the permission settings in **Settings**.<br>- **0**: The permission is granted.<br>- **2**: The permission request is invalid. The possible causes are as follows: 1. The permission is not declared in the configuration file. 2. The permission name is invalid. 3. The conditions for requesting the permission are not met. For details, see [ohos.permission.LOCATION](../../security/AccessToken/permissions-for-all-user.md#ohospermissionlocation) and [ohos.permission.APPROXIMATELY_LOCATION](../../security/AccessToken/permissions-for-all-user.md#ohospermissionapproximately_location).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| dialogShownResults<sup>12+</sup> | Array&lt;boolean&gt; | Yes| Yes| Whether to display a dialog box.<br>The value **true** means to display a dialog box; the value **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| errorReasons<sup>18+</sup> | Array&lt;number&gt; | Yes| Yes| Return value.<br>- **0**: The request is valid.<br>- **1**: The permission name is invalid.<br>- **2**: The permission is not declared in the configuration file.<br>- **3**: The conditions for requesting the permission are not met. For details, see the permission description in [Permission List](../../security/AccessToken/permissions-for-all-user.md). Currently, only the location permissions are involved.<br>- **4**: The user does not agree to the privacy statement.<br>- **5**: This permission cannot be requested via a dialog box.<br>- **12**: The service is abnormal.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

## Usage

The permission request result is obtained through an **atManager** instance.

**Example**
For details about how to obtain the context in the example, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

```ts
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';
import { BusinessError } from '@ohos.base';
import common from '@ohos.app.ability.common';

let atManager = abilityAccessCtrl.createAtManager();
try {
  let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  atManager.requestPermissionsFromUser(context, ["ohos.permission.CAMERA"]).then((data) => {
      console.info("data:" + JSON.stringify(data));
      console.info("data permissions:" + data.permissions);
      console.info("data authResults:" + data.authResults);
      console.info("data dialogShownResults:" + data.dialogShownResults);
      console.info("data errorReasons:" + data.errorReasons);
  }).catch((err: BusinessError) => {
      console.error("data:" + JSON.stringify(err));
  })
} catch(err) {
  console.error(`catch err->${JSON.stringify(err)}`);
}
```
