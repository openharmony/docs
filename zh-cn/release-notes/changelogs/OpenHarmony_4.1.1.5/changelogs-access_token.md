# 程序访问控制子系统ChangeLog
## cl.access_token.1 通过requestPermissionsFromUser申请位置权限时行为变更

**变更原因**

根据安全隐私要求，位置权限申请使用时，申请精确/后台位置权限，要同时或提前申请模糊权限。

**变更影响**

变更前，通过调用[requestPermissionsFromUser](../../../application-dev/reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)接口申请位置权限，如下两种申请情况都可以顺利拉起弹窗：

1、在未申请模糊权限[ohos.permission.APPROXIMATELY_LOCATION](../../../application-dev/security/permission-list.md#ohospermissionapproximately_location)的情况下，请求后台位置权限[ohos.permission.LOCATION_IN_BACKGROUND](../../../application-dev/security/permission-list.md#ohospermissionlocation_in_background)

2、在未申请模糊权限[ohos.permission.APPROXIMATELY_LOCATION](../../../application-dev/security/permission-list.md#ohospermissionapproximately_location)的情况下，同时请求后台位置权限[ohos.permission.LOCATION_IN_BACKGROUND](../../../application-dev/security/permission-list.md#ohospermissionlocation_in_background)及精准权限[ohos.permission.LOCATION](../../../application-dev/security/permission-list.md#ohospermissionlocation)；

变更后，上述两种情况将无法拉起弹窗授予权限。应用在申请精准权限或后台权限时，必须同时申请模糊权限或确保已授权模糊权限。

**变更的接口/组件**

@ohos.abilityAccessCtrl.d.ts中requestPermissionsFromUser接口，使用该接口申请位置权限的应用，在申请精准权限或后台权限时，必须同时申请模糊权限或确保已授权模糊权限。

**适配指导**

修改EntryAbility.ets和导入GlobalThis等步骤参考[requestPermissionsFromUser](../../../application-dev/reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)

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
