# Requesting User Authorization for the Second Time

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--SE: @linshuqing; @hehehe-li-->
<!--TSE: @leiyuqian-->

If an application [requests user authorization](request-user-authorization.md) via a dialog box using [requestPermissionsFromUser()](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) and the user denies it, the application cannot show the same dialog box again with this API. The user needs to manually grant the permission in **Settings**.

The path in **Settings** is as follows:
<!--RP1-->
**Privacy** > **Permission manager** > *Permission type (such as **Location***) > *App*
<!--RP1End-->

Alternatively, start the permission settings dialog box by using [requestPermissionOnSetting()](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissiononsetting12) and guide the user to grant the permission.

**Figure 1** Requesting user authorization for the second time

<!--RP2-->
![en_image_location](figures/en_image_location_second.png)
<!--RP2End-->

The following sample code shows how to open the dialog box again to request ohos.permission.APPROXIMATELY_LOCATION.

```ts
import { abilityAccessCtrl, Context, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
atManager.requestPermissionOnSetting(context, ['ohos.permission.APPROXIMATELY_LOCATION']).then((data: Array<abilityAccessCtrl.GrantStatus>) => {
  console.info('data:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error('data:' + JSON.stringify(err));
});
```
