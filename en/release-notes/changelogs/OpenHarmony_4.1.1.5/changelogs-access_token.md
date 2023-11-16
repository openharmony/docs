# Application Access Control Subsystem Changelog
## cl.access_token.1 Behavior Change When Location Permission Is Requested by requestPermissionsFromUser

**Change Impact**

Before the change, when [requestPermissionsFromUser](../../../application-dev/reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) is called to request the location permission, an authorization dialog box will be displayed in either of the following cases:

- The [ohos.permission.LOCATION_IN_BACKGROUND](../../../application-dev/security/permission-list.md#ohospermissionlocation_in_background) permission is requested without the [ohos.permission.APPROXIMATELY_LOCATION](../../../application-dev/security/permission-list.md#ohospermissionapproximately_location) permission.

- The [ohos.permission.LOCATION_IN_BACKGROUND](../../../application-dev/security/permission-list.md#ohospermissionlocation_in_background) and [ohos.permission.LOCATION](../../../application-dev/security/permission-list.md#ohospermissionlocation) permissions are requested without the [ohos.permission.APPROXIMATELY_LOCATION](../../../application-dev/security/permission-list.md#ohospermissionapproximately_location) permission.

After the change, the authorization dialog box cannot be displayed in the preceding two cases. When applying for the [ohos.permission.LOCATION](../../../application-dev/security/permission-list.md#ohospermissionlocation) or [ohos.permission.LOCATION_IN_BACKGROUND](../../../application-dev/security/permission-list.md#ohospermissionlocation_in_background) permission, the application must also apply for or have the [ohos.permission.APPROXIMATELY_LOCATION](../../../application-dev/security/permission-list.md#ohospermissionapproximately_location) permission.

**Adaptation Guide**

Refer to [requestPermissionsFromUser](../../../application-dev/reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) when modifying **EntryAbility.ets** and importing **GlobalThis**.

```ts
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';
import { BusinessError } from '@ohos.base';
import common from '@ohos.app.ability.common';
import { GlobalThis } from '../utils/globalThis';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
try {
    let context: common.UIAbilityContext = GlobalThis.getInstance().getContext('context');
    atManager.requestPermissionsFromUser(context, ['ohos.permission.APPROXIMATELY_LOCATION', 'ohos.permission.LOCATION', 'ohos.permission.LOCATION_IN_BACKGROUND']).then((data) => {
        console.info('data:' + JSON.stringify(data));
        console.info('data permissions:' + data.permissions);
        console.info('data authResults:' + data.authResults);
    }).catch((err: BusinessError) => {
        console.info('data:' + JSON.stringify(err));
    })
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```
