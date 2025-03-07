# PermissionRequestResult

权限请求结果对象，在调用[requestPermissionsFromUser](js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)申请权限时返回此对象表明此次权限申请的结果。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> - 本模块接口仅可在Stage模型下使用。

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.AccessToken

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | 是 | 否 | 用户传入的权限。<br> **原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| authResults | Array&lt;number&gt; | 是 | 否 | 相应请求权限的结果：<br>- -1：未授权。①dialogShownResults返回为true，表示用户首次申请；②dialogShownResults返回为false，表示权限已设置，无需弹窗，需要用户在"设置"中修改。<br>- 0：已授权。<br>- 2：未授权，表示请求无效。可能原因有：①未在设置文件中声明目标权限；②权限名非法；③部分权限存在特殊申请条件，在申请对应权限时未满足其指定的条件，见[ohos.permission.LOCATION](../../security/AccessToken/permissions-for-all-user.md#ohospermissionlocation)与[ohos.permission.APPROXIMATELY_LOCATION](../../security/AccessToken/permissions-for-all-user.md#ohospermissionapproximately_location)。 <br> **原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| dialogShownResults<sup>12+</sup> | Array&lt;boolean&gt; | 是 | 是 | 此权限申请是否有弹窗：<br>- true：有弹窗。<br>- false：无弹窗。<br> **原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| errorReasons<sup>18+</sup> | Array&lt;number&gt; | 是 | 是 | 申请相应权限的返回值说明：<br>- 0：本次申请合法。<br>- 1：权限名非法。<br>- 2：权限未声明。<br>- 3：不满足对应权限的申请条件，请参考[权限列表](../../security/AccessToken/permissions-for-all-user.md)中具体权限的说明。当前仅位置权限涉及。<br>- 4：用户未同意隐私声明。<br>- 5：该权限不支持通过权限弹窗进行申请。<br>- 12：服务异常。<br> **原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。 |

## 使用说明

通过atManager实例来获取。

**示例：**
示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

```ts
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';
import { BusinessError } from '@ohos.base';
import common from '@ohos.app.ability.common';

let atManager = abilityAccessCtrl.createAtManager();
try {
  let context: Context = getContext(this) as common.UIAbilityContext;
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