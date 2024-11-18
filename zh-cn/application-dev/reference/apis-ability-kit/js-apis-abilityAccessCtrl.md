# @ohos.abilityAccessCtrl (程序访问控制管理)

程序访问控制提供程序的权限管理能力，包括鉴权、授权等。

> **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit'
```

## abilityAccessCtrl.createAtManager

createAtManager(): AtManager

访问控制管理：获取访问控制模块对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.AccessToken


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [AtManager](#atmanager) | 获取访问控制模块的实例。 |

**示例：**

```ts
let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
```

## AtManager

管理访问控制模块的实例。

### checkAccessToken<sup>9+</sup>

checkAccessToken(tokenID: number, permissionName: Permissions): Promise&lt;GrantStatus&gt;

校验应用是否授予权限。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 要校验的目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | Permissions | 是   | 需要校验的权限名称，合法的权限名取值可在[应用权限列表](../../security/AccessToken/permissions-for-all.md)中查询。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;[GrantStatus](#grantstatus)&gt; | Promise对象。返回授权状态结果。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, or the permissionName exceeds 256 characters. |

**示例：**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取，三方应用可以通过bundleManager.getBundleInfoForSelf获取
atManager.checkAccessToken(tokenID, 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS').then((data: abilityAccessCtrl.GrantStatus) => {
  console.log(`checkAccessToken success, data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`checkAccessToken fail, err->${JSON.stringify(err)}`);
});
```

### verifyAccessTokenSync<sup>9+</sup>

verifyAccessTokenSync(tokenID: number, permissionName: Permissions): GrantStatus

校验应用是否被授予权限，同步返回结果。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 要校验应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | Permissions | 是   | 需要校验的权限名称，合法的权限名取值可在[应用权限列表](../../security/AccessToken/permissions-for-all.md)中查询。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| [GrantStatus](#grantstatus) | 枚举实例，返回授权状态。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, or the permissionName exceeds 256 characters. |

**示例：**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取，三方应用可以通过bundleManager.getBundleInfoForSelf获取
try {
  let data: abilityAccessCtrl.GrantStatus = atManager.verifyAccessTokenSync(tokenID, 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS');
  console.log(`data->${JSON.stringify(data)}`);
} catch(err) {
  console.error(`catch err->${JSON.stringify(err)}`);
}
```

### verifyAccessToken<sup>9+</sup>

verifyAccessToken(tokenID: number, permissionName: Permissions): Promise&lt;GrantStatus&gt;

校验应用是否授予权限。使用Promise异步回调。

> **说明：**
>
> 建议使用[checkAccessToken](#checkaccesstoken9)替代。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 要校验的目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | Permissions | 是   | 需要校验的权限名称，合法的权限名取值可在[应用权限列表](../../security/AccessToken/permissions-for-all.md)中查询。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;[GrantStatus](#grantstatus)&gt; | Promise对象。返回授权状态结果。 |

**示例：**

```ts
import { abilityAccessCtrl, Permissions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取，三方应用可以通过bundleManager.getBundleInfoForSelf获取
let permissionName: Permissions = 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS';
atManager.verifyAccessToken(tokenID, permissionName).then((data: abilityAccessCtrl.GrantStatus) => {
  console.log(`promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`verifyAccessToken fail, err->${JSON.stringify(err)}`);
});
```

### requestPermissionsFromUser<sup>9+</sup>

requestPermissionsFromUser(context: Context, permissionList: Array&lt;Permissions&gt;, requestCallback: AsyncCallback&lt;PermissionRequestResult&gt;): void

用于<!--RP1-->UIAbility<!--RP1End-->拉起弹框请求用户授权。使用callback异步回调。

如果用户拒绝授权，将无法再次拉起弹框，需要用户在系统应用“设置”的界面中，手动授予权限。或是调用[requestPermissionOnSetting](#requestpermissiononsetting12)，拉起权限设置弹框，引导用户授权。

> **说明：**
>
> 仅支持<!--RP1-->UIAbility<!--RP1End-->。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**: SystemCapability.Security.AccessToken

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| context | [Context](js-apis-inner-application-context.md) | 是 | 请求权限的<!--RP1-->UIAbility<!--RP1End-->的Context。 |
| permissionList | Array&lt;Permissions&gt; | 是 | 权限名列表，合法的权限名取值可在[应用权限列表](../../security/AccessToken/permissions-for-all.md)中查询。 |
| requestCallback | AsyncCallback&lt;[PermissionRequestResult](js-apis-permissionrequestresult.md)&gt; | 是 | 回调函数，返回接口调用是否成功的结果。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The context is invalid when it does not belong to the application itself. |

**示例：**
示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

```ts
import { abilityAccessCtrl, Context, PermissionRequestResult, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let context: Context = getContext(this) as common.UIAbilityContext;
atManager.requestPermissionsFromUser(context, ['ohos.permission.CAMERA'], (err: BusinessError, data: PermissionRequestResult) => {
  if (err) {
    console.error(`requestPermissionsFromUser fail, err->${JSON.stringify(err)}`);
  } else {
    console.info('data:' + JSON.stringify(data));
    console.info('data permissions:' + data.permissions);
    console.info('data authResults:' + data.authResults);
    console.info('data dialogShownResults:' + data.dialogShownResults);
  }
});
```

### requestPermissionsFromUser<sup>9+</sup>

requestPermissionsFromUser(context: Context, permissionList: Array&lt;Permissions&gt;): Promise&lt;PermissionRequestResult&gt;

用于<!--RP1-->UIAbility<!--RP1End-->拉起弹框请求用户授权。使用promise异步回调。

如果用户拒绝授权，将无法再次拉起弹框，需要用户在系统应用“设置”的界面中，手动授予权限。或是调用[requestPermissionOnSetting](#requestpermissiononsetting12)，拉起权限设置弹框，引导用户授权。

> **说明：**
>
> 仅支持<!--RP1-->UIAbility<!--RP1End-->。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**: SystemCapability.Security.AccessToken

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| context | [Context](js-apis-inner-application-context.md) | 是 | 请求权限的<!--RP1-->UIAbility<!--RP1End-->的Context。 |
| permissionList | Array&lt;Permissions&gt; | 是 | 需要校验的权限名称，合法的权限名取值可在[应用权限列表](../../security/AccessToken/permissions-for-all.md)中查询。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[PermissionRequestResult](js-apis-permissionrequestresult.md)&gt; | 返回一个Promise，包含接口的结果。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The context is invalid when it does not belong to the application itself. |

**示例：**
示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

```ts
import { abilityAccessCtrl, Context, PermissionRequestResult, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let context: Context = getContext(this) as common.UIAbilityContext;
atManager.requestPermissionsFromUser(context, ['ohos.permission.CAMERA']).then((data: PermissionRequestResult) => {
  console.info('data:' + JSON.stringify(data));
  console.info('data permissions:' + data.permissions);
  console.info('data authResults:' + data.authResults);
  console.info('data dialogShownResults:' + data.dialogShownResults);
}).catch((err: BusinessError) => {
  console.error('data:' + JSON.stringify(err));
});
```

### verifyAccessToken<sup>(deprecated)</sup>

verifyAccessToken(tokenID: number, permissionName: string): Promise&lt;GrantStatus&gt;

校验应用是否授予权限。使用Promise异步回调。

> **说明：**
>
> 从API version 9开始不再维护，建议使用[checkAccessToken](#checkaccesstoken9)替代。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 要校验的目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | string | 是   | 需要校验的权限名称，合法的权限名取值可在[应用权限列表](../../security/AccessToken/permissions-for-all.md)中查询。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;[GrantStatus](#grantstatus)&gt; | Promise对象。返回授权状态结果。 |

**示例：**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取，三方应用可以通过bundleManager.getBundleInfoForSelf获取
atManager.verifyAccessToken(tokenID, 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS').then((data: abilityAccessCtrl.GrantStatus) => {
  console.log(`promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`verifyAccessToken fail, err->${JSON.stringify(err)}`);
});
```

### checkAccessTokenSync<sup>10+</sup>

checkAccessTokenSync(tokenID: number, permissionName: Permissions): GrantStatus

校验应用是否被授予权限，同步返回结果。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 要校验应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | Permissions | 是   | 需要校验的权限名称，合法的权限名取值可在[应用权限列表](../../security/AccessToken/permissions-for-all.md)中查询。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| [GrantStatus](#grantstatus) | 枚举实例，返回授权状态。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, or the permissionName exceeds 256 characters. |

**示例：**

```ts
import { abilityAccessCtrl, Permissions } from '@kit.AbilityKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取，三方应用可以通过bundleManager.getBundleInfoForSelf获取
let permissionName: Permissions = 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS';
let data: abilityAccessCtrl.GrantStatus = atManager.checkAccessTokenSync(tokenID, permissionName);
console.log(`data->${JSON.stringify(data)}`);
```

### GrantStatus

表示授权状态的枚举。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.AccessToken

| 名称               |    值 | 说明        |
| ------------------ | ----- | ----------- |
| PERMISSION_DENIED  | -1    | 表示未授权。 |
| PERMISSION_GRANTED | 0     | 表示已授权。 |

### requestPermissionOnSetting<sup>12+</sup>

requestPermissionOnSetting(context: Context, permissionList: Array&lt;Permissions&gt;): Promise&lt;Array&lt;GrantStatus&gt;&gt;

用于UIAbility/UIExtensionAbility二次拉起权限设置弹框。

在调用此接口前，应用需要先调用[requestPermissionsFromUser](#requestpermissionsfromuser9)，如果用户在首次弹窗授权时已授权，调用当前接口将无法拉起弹窗。

> **说明：**
>
> 仅支持UIAbility/UIExtensionAbility。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**: SystemCapability.Security.AccessToken

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| context | [Context](js-apis-inner-application-context.md) | 是 | 请求权限的UIAbility/UIExtensionAbility的Context。 |
| permissionList | Array&lt;Permissions&gt; | 是 | 权限名列表，合法的权限名取值可在[应用权限组列表](../../security/AccessToken/app-permission-group-list.md)中查询。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[GrantStatus](#grantstatus)&gt;&gt; | Promise对象。返回授权状态结果。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. Possible causes: 1. The context is invalid because it does not belong to the application itself; 2. The permission list contains the permission that is not declared in the module.json file; 3. The permission list is invalid because the permissions in it do not belong to the same permission group. |
| 12100010 | The request already exists. |
| 12100011 | All permissions in the permission list have been granted. |
| 12100012 | The permission list contains the permission that has not been revoked by the user. |

**示例：**
示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

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

### requestGlobalSwitch<sup>12+</sup>

requestGlobalSwitch(context: Context, type: SwitchType): Promise&lt;boolean&gt;

用于UIAbility/UIExtensionAbility拉起全局开关设置弹框。

部分情况下，录音、拍照等功能禁用，应用可拉起此弹框请求用户同意开启对应功能。如果当前全局开关的状态为开启，则不拉起弹框。

> **说明：**
>
> 仅支持UIAbility/UIExtensionAbility。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**: SystemCapability.Security.AccessToken

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| context | [Context](js-apis-inner-application-context.md) | 是 | 请求权限的UIAbility/UIExtensionAbility>的Context。 |
| type | [SwitchType](#switchtype12) | 是 | 全局开关类型。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回全局开关状态。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12100001 | Invalid parameter. Possible causes: 1. The context is invalid because it does not belong to the application itself; 2. The type of global switch is not support. |
| 12100010 | The request already exists. |
| 12100013 | The specific global switch is already open. |

**示例：**
示例中context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

```ts
import { abilityAccessCtrl, Context, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let context: Context = getContext(this) as common.UIAbilityContext;
atManager.requestGlobalSwitch(context, abilityAccessCtrl.SwitchType.CAMERA).then((data: Boolean) => {
  console.info('data:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error('data:' + JSON.stringify(err));
});
```

### SwitchType<sup>12+</sup>

表示全局开关类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Security.AccessToken

| 名称               |    值 | 说明        |
| ------------------ | ----- | ----------- |
| CAMERA  | 0    | 表示相机全局开关。 |
| MICROPHONE | 1     | 表示麦克风全局开关。 |
| LOCATION | 2     | 表示位置全局开关。 |