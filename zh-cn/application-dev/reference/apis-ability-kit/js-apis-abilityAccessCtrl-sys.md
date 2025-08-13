# @ohos.abilityAccessCtrl (程序访问控制管理)(系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--SE: @linshuqing; @hehehe-li-->
<!--TSE: @leiyuqian-->

程序访问控制提供程序的权限管理能力，包括鉴权、授权和取消授权等。

> **说明：**
>
> - 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.abilityAccessCtrl (程序访问控制管理)](js-apis-abilityAccessCtrl.md)。

## 导入模块

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
```

## AtManager

管理访问控制模块的实例。

### grantUserGrantedPermission

grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number): Promise&lt;void&gt;

授予应用user_grant权限。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GRANT_SENSITIVE_PERMISSIONS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                                                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | 是   | 目标应用的身份标识，可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | Permissions              | 是   | 被授予的权限名称，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。 |
| permissionFlags  | number | 是   | 授权选项。<br>- 1表示当次用户若选择禁止该权限，下次权限弹窗仍可以弹出申请用户授权。<br>- 2表示当次用户若选择禁止该权限，下次不会再弹出权限弹窗。用户需要在setting的权限管理中进行授权。<br>- 64表示当次用户若选择仅本次允许，权限仅本次授权。应用切换后台状态或退出后取消授权。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.GRANT_SENSITIVE_PERMISSIONS". |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters or is not declared in the module.json file, or the flags value is invalid. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100006 | The application specified by the tokenID is not allowed to be granted with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | The service is abnormal. |

**示例：**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取,普通应用可以通过bundleManager.getBundleInfoForSelf获取
let permissionFlags: number = 1;
atManager.grantUserGrantedPermission(tokenID, 'ohos.permission.READ_AUDIO', permissionFlags).then(() => {
  console.log('grantUserGrantedPermission success');
}).catch((err: BusinessError) => {
  console.error(`grantUserGrantedPermission fail, err->${JSON.stringify(err)}`);
});
```

### grantUserGrantedPermission

grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number, callback: AsyncCallback&lt;void&gt;): void

授予应用user_grant权限。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GRANT_SENSITIVE_PERMISSIONS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                          |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | 是   | 目标应用的身份标识，可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | Permissions              | 是   | 被授予的权限名称，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。 |
| permissionFlags  | number | 是   | 授权选项。<br>- 1表示当次用户若选择禁止该权限，下次权限弹窗仍可以弹出申请用户授权。<br>- 2表示当次用户若选择禁止该权限，下次不会再弹出权限弹窗，用户需要在setting的权限管理中进行授权。<br>- 64表示当次用户若选择仅本次允许，权限仅本次授权。应用切换后台状态或退出后取消授权。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 授予应用user_grant权限，当授予权限成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.GRANT_SENSITIVE_PERMISSIONS". |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters or is not declared in the module.json file, or the flags value is invalid. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100006 | The application specified by the tokenID is not allowed to be granted with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | The service is abnormal. |

**示例：**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取,普通应用可以通过bundleManager.getBundleInfoForSelf获取
let permissionFlags: number = 1;
atManager.grantUserGrantedPermission(tokenID, 'ohos.permission.READ_AUDIO', permissionFlags, (err: BusinessError, data: void) => {
  if (err) {
    console.error(`grantUserGrantedPermission fail, err->${JSON.stringify(err)}`);
  } else {
    console.log('grantUserGrantedPermission success');
  }
});
```

### revokeUserGrantedPermission

revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number): Promise&lt;void&gt;

撤销应用user_grant权限。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.REVOKE_SENSITIVE_PERMISSIONS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                                                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | 是   | 目标应用的身份标识，可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | Permissions              | 是   | 被撤销的权限名称，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。 |
| permissionFlags  | number | 是   | 授权选项。<br>- 1表示当次用户若选择禁止该权限，下次权限弹窗仍可以弹出申请用户授权。<br>- 2表示当次用户若选择禁止该权限，下次不会再弹出权限弹窗，用户需要在setting的权限管理中进行授权。<br>- 64表示当次用户若选择仅本次允许，权限仅本次授权。应用切换后台状态或退出后取消授权。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.REVOKE_SENSITIVE_PERMISSIONS". |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters or is not declared in the module.json file, or the flags value is invalid. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100006 | The application specified by the tokenID is not allowed to be revoked with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | The service is abnormal. |

**示例：**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取,普通应用可以通过bundleManager.getBundleInfoForSelf获取
let permissionFlags: number = 1;
atManager.revokeUserGrantedPermission(tokenID, 'ohos.permission.READ_AUDIO', permissionFlags).then(() => {
  console.log('revokeUserGrantedPermission success');
}).catch((err: BusinessError) => {
  console.error(`revokeUserGrantedPermission fail, err->${JSON.stringify(err)}`);
});
```

### revokeUserGrantedPermission

revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number, callback: AsyncCallback&lt;void&gt;): void

撤销应用user_grant权限。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.REVOKE_SENSITIVE_PERMISSIONS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                          |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | 是   | 目标应用的身份标识，可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | Permissions              | 是   | 被撤销的权限名称，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。 |
| permissionFlags  | number | 是   | 授权选项。<br>- 1表示当次用户若选择禁止该权限，下次权限弹窗仍可以弹出申请用户授权。<br>- 2表示当次用户若选择禁止该权限，下次不会再弹出权限弹窗，用户需要在setting的权限管理中进行授权。<br>- 64表示当次用户若选择仅本次允许，权限仅本次授权。应用切换后台状态或退出后取消授权。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 撤销应用user_grant权限，当撤销权限成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.REVOKE_SENSITIVE_PERMISSIONS". |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters or is not declared in the module.json file, or the flags value is invalid. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100006 | The application specified by the tokenID is not allowed to be revoked with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | The service is abnormal. |

**示例：**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取,普通应用可以通过bundleManager.getBundleInfoForSelf获取
let permissionFlags: number = 1;
atManager.revokeUserGrantedPermission(tokenID, 'ohos.permission.READ_AUDIO', permissionFlags, (err: BusinessError, data: void) => {
  if (err) {
    console.error(`revokeUserGrantedPermission fail, err->${JSON.stringify(err)}`);
  } else {
    console.log('revokeUserGrantedPermission success');
  }
});
```

### getPermissionFlags

getPermissionFlags(tokenID: number, permissionName: Permissions): Promise&lt;number&gt;

获取指定应用的指定权限的flag。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_SENSITIVE_PERMISSIONS or ohos.permission.GRANT_SENSITIVE_PERMISSIONS or ohos.permission.REVOKE_SENSITIVE_PERMISSIONS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                          |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | 是   | 目标应用的身份标识，可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | Permissions              | 是   | 查询的权限名称，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回查询结果。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission specified below. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, or the permissionName exceeds 256 characters. |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist or is not declared in the module.json file. |
| 12100006 | The operation is not allowed. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | The service is abnormal. |

**示例：**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取,普通应用可以通过bundleManager.getBundleInfoForSelf获取
atManager.getPermissionFlags(tokenID, 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS').then((data: number) => {
  console.log(`getPermissionFlags success, data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`getPermissionFlags fail, err->${JSON.stringify(err)}`);
});
```

### setPermissionRequestToggleStatus<sup>12+</sup>

setPermissionRequestToggleStatus(permissionName: Permissions, status: PermissionRequestToggleStatus): Promise&lt;void&gt;

设置当前用户指定权限的弹窗开关状态。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.DISABLE_PERMISSION_DIALOG。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                          |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| permissionName | Permissions              | 是   | 待设置弹窗开关状态的权限名称，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。 |
| status | [PermissionRequestToggleStatus](#permissionrequesttogglestatus12)    | 是   | 指定权限的弹窗开关状态值。             |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission specified below. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The permissionName exceeds 256 characters, the specified permission is not a user_grant permission, or the status value is invalid. |
| 12100003 | The specified permission does not exist. |
| 12100007 | The service is abnormal. |

**示例：**

```ts
import { abilityAccessCtrl, Permissions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager = abilityAccessCtrl.createAtManager();
let permission: Permissions = 'ohos.permission.CAMERA';

atManager.setPermissionRequestToggleStatus(permission, abilityAccessCtrl.PermissionRequestToggleStatus.CLOSED).then((err) => {
  console.info('toggle_status: Set closed successful');
}).catch((err: BusinessError) => {
  console.error(`toggle_status: Code is ${err.code}, message is ${err.message}`);
});
```

### getPermissionRequestToggleStatus<sup>12+</sup>

getPermissionRequestToggleStatus(permissionName: Permissions): Promise&lt;PermissionRequestToggleStatus&gt;

获取当前用户指定权限的弹窗开关状态。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_SENSITIVE_PERMISSIONS。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                          |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| permissionName | Permissions              | 是   | 待查询弹窗开关状态的权限名称，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;[PermissionRequestToggleStatus](#permissionrequesttogglestatus12)&gt; | Promise对象，返回指定权限的弹窗开关状态值。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission specified below. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The permissionName exceeds 256 characters, or the specified permission is not a user_grant permission. |
| 12100003 | The specified permission does not exist. |
| 12100007 | The service is abnormal. |

**示例：**

```ts
import { abilityAccessCtrl, Permissions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager = abilityAccessCtrl.createAtManager();
let permission: Permissions = 'ohos.permission.CAMERA';

atManager.getPermissionRequestToggleStatus(permission).then((res) => {
  if (res == abilityAccessCtrl.PermissionRequestToggleStatus.CLOSED) {
    console.info('toggle_status: The toggle status is close');
  } else {
    console.info('toggle_status: The toggle status is open');
  }
}).catch((err: BusinessError) => {
console.error(`toggle_status: Code is ${err.code}, message is ${err.message}`);
});
```

### getVersion<sup>9+</sup>

getVersion(): Promise&lt;number&gt;

获取当前权限管理的数据版本。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回查询到的版本号。 |

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |

**示例：**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let promise = atManager.getVersion();
promise.then((data: number) => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

### getPermissionsStatus<sup>12+</sup>

getPermissionsStatus(tokenID: number, permissionList: Array&lt;Permissions&gt;): Promise&lt;Array&lt;PermissionStatus&gt;&gt;

获取指定应用权限状态列表。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_SENSITIVE_PERMISSIONS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                          |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | 是   | 目标应用的身份标识，可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionList | Array&lt;Permissions&gt;   | 是   | 待获取权限状态的权限名列表，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[PermissionStatus](js-apis-abilityAccessCtrl.md#permissionstatus20)&gt;&gt; | Promise对象，返回查询到的权限状态列表。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.GET_SENSITIVE_PERMISSIONS". |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0 or the permissionList is empty or exceeds the size limit. |
| 12100002 | The specified tokenID does not exist. |
| 12100007 | The service is abnormal. |

**示例：**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取,普通应用可以通过bundleManager.getBundleInfoForSelf获取
atManager.getPermissionsStatus(tokenID, ['ohos.permission.CAMERA']).then((data: Array<abilityAccessCtrl.PermissionStatus>) => {
  console.log(`getPermissionsStatus success, data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`getPermissionsStatus fail, err->${JSON.stringify(err)}`);
});
```

### on<sup>9+</sup>

on(type: 'permissionStateChange', tokenIDList: Array&lt;number&gt;, permissionList: Array&lt;Permissions&gt;, callback: Callback&lt;PermissionStateChangeInfo&gt;): void

订阅指定tokenId列表与权限列表的权限状态变更事件。

允许指定tokenId列表与权限列表订阅多个callback。

不允许存在交集的tokenId列表与权限列表订阅相同callback。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_SENSITIVE_PERMISSIONS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名             | 类型                   | 必填 | 说明                                                          |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | 是   | 订阅事件类型，固定为'permissionStateChange'，权限状态变更事件。  |
| tokenIDList        | Array&lt;number&gt;   | 是   | 订阅的tokenId列表，为空时表示订阅所有的应用的权限状态变化。 |
| permissionList | Array&lt;Permissions&gt;   | 是   | 订阅的权限名列表，为空时表示订阅所有的权限状态变化，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。|
| callback | Callback&lt;[PermissionStateChangeInfo](js-apis-abilityAccessCtrl.md#permissionstatechangeinfo18)&gt; | 是 | 订阅指定tokenId与指定权限名状态变更事件的回调。|

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.GET_SENSITIVE_PERMISSIONS". |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. Possible causes: 1. The tokenIDList or permissionList exceeds the size limit; 2. The tokenIDs or permissionNames in the list are all invalid. |
| 12100004 | The API is used repeatedly with the same input. |
| 12100005 | The registration time has exceeded the limit. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { abilityAccessCtrl, Permissions, bundleManager } from '@kit.AbilityKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let appInfo: bundleManager.ApplicationInfo = bundleManager.getApplicationInfoSync('com.example.myapplication', 0, 100);
let tokenIDList: Array<number> = [appInfo.accessTokenId];
let permissionList: Array<Permissions> = ['ohos.permission.DISTRIBUTED_DATASYNC'];
try {
    atManager.on('permissionStateChange', tokenIDList, permissionList, (data: abilityAccessCtrl.PermissionStateChangeInfo) => {
        console.debug('receive permission state change, data:' + JSON.stringify(data));
    });
} catch(err) {
    console.error(`catch err->${JSON.stringify(err)}`);
}
```

### off<sup>9+</sup>

off(type: 'permissionStateChange', tokenIDList: Array&lt;number&gt;, permissionList: Array&lt;Permissions&gt;, callback?: Callback&lt;PermissionStateChangeInfo&gt;): void

取消订阅指定tokenId列表与权限列表的权限状态变更事件，使用callback回调异步返回结果。

取消订阅时，若不传入callback，则批量删除tokenIDList和permissionList中的所有callback。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_SENSITIVE_PERMISSIONS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名             | 类型                   | 必填 | 说明                                                          |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string         | 是   | 订阅事件类型，固定为'permissionStateChange'，权限状态变更事件。  |
| tokenIDList        | Array&lt;number&gt;   | 是   | 取消订阅的tokenId列表，为空时表示取消订阅所有的应用的权限状态变化，必须与on的输入一致。 |
| permissionList | Array&lt;Permissions&gt;   | 是   | 取消订阅的权限名列表，为空时表示取消订阅所有的权限状态变化，必须与on的输入一致，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。 |
| callback | Callback&lt;[PermissionStateChangeInfo](js-apis-abilityAccessCtrl.md#permissionstatechangeinfo18)&gt; | 否 | 取消订阅指定tokenId与指定权限名状态变更事件的回调。|

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.GET_SENSITIVE_PERMISSIONS". |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenIDList or permissionList is not in the listening list. |
| 12100004 | The API is not used in pair with 'on'. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { abilityAccessCtrl, Permissions, bundleManager } from '@kit.AbilityKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let appInfo: bundleManager.ApplicationInfo = bundleManager.getApplicationInfoSync('com.example.myapplication', 0, 100);
let tokenIDList: Array<number> = [appInfo.accessTokenId];
let permissionList: Array<Permissions> = ['ohos.permission.DISTRIBUTED_DATASYNC'];
try {
    atManager.off('permissionStateChange', tokenIDList, permissionList);
} catch(err) {
    console.error(`catch err->${JSON.stringify(err)}`);
}
```

### requestPermissionOnApplicationSetting<sup>18+</sup>

requestPermissionOnApplicationSetting(tokenID: number): Promise&lt;void&gt;

拉起应用权限设置页面。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                                                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | 是   | 目标应用的身份标识，可通过该应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 12100002 | The specified tokenID does not exist. |
| 12100007 | The service is abnormal. |

**示例：**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取
atManager.requestPermissionOnApplicationSetting(tokenID).then(() => {
  console.log('requestPermissionOnApplicationSetting success');
}).catch((err: BusinessError) => {
  console.error(`requestPermissionOnApplicationSetting fail, err->${JSON.stringify(err)}`);
});
```

### PermissionRequestToggleStatus<sup>12+</sup>

表示指定权限对应的弹窗开关状态的枚举。

**系统能力：** SystemCapability.Security.AccessToken

| 名称               |    值 | 说明        |
| ------------------ | ----- | ----------- |
| CLOSED  | 0    | 表示关闭状态。 |
| OPEN | 1     | 表示开启状态。 |