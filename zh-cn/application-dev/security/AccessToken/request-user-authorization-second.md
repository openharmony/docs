# 二次向用户申请授权

当应用通过[requestPermissionsFromUser()](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)拉起弹框[请求用户授权](request-user-authorization.md)时，用户拒绝授权。应用将无法再次拉起弹框，需要用户在系统应用“设置”的界面中，手动授予权限。

在“设置”应用中的路径：
<!--RP1-->
- 隐私 > 权限管理 > 位置信息 > 具体应用
<!--RP1End-->

应用也可以通过如下方式，直接拉起权限设置弹框，引导用户授予权限。以下示例代码以再次拉起弹窗申请ohos.permission.CAMERA权限为例。

```ts
import { abilityAccessCtrl, Context, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let context: Context = getContext(this) as common.UIAbilityContext;
atManager.requestPermissionOnSetting(context, ['ohos.permission.CAMERA']).then((data: Array<abilityAccessCtrl.GrantStatus>) => {
  console.info('data:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error('data:' + JSON.stringify(err));
});
```