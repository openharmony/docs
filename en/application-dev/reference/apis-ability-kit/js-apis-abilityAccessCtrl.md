# @ohos.abilityAccessCtrl (Application Access Control)

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--SE: @linshuqing; @hehehe-li-->
<!--TSE: @leiyuqian-->

The **abilityAccessCtrl** module provides APIs for application permission management, including authentication and authorization.

> **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
```

## abilityAccessCtrl.createAtManager

createAtManager(): AtManager

Creates an **AtManager** instance for application access control.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Security.AccessToken


**Return value**

| Type| Description|
| -------- | -------- |
| [AtManager](#atmanager) | **AtManager** instance created.|

**Example**

```ts
let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
```

## AtManager

Provides APIs for application access control.

### checkAccessToken<sup>9+</sup>

checkAccessToken(tokenID: number, permissionName: Permissions): Promise&lt;GrantStatus&gt;

Checks whether the user has granted the permission. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Identifier of the target application, which is the value of **accessTokenId** contained in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions | Yes  | Permission to verify. For details about the permission, see [Application Permissions](../../security/AccessToken/app-permissions.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;[GrantStatus](#grantstatus)&gt; | Promise used to return the authorization result.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, or the permissionName exceeds 256 characters. |

**Example**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a third-party application.
atManager.checkAccessToken(tokenID, 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS').then((data: abilityAccessCtrl.GrantStatus) => {
  console.log(`checkAccessToken success, data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`checkAccessToken fail, err->${JSON.stringify(err)}`);
});
```

### checkAccessTokenSync<sup>10+</sup>

checkAccessTokenSync(tokenID: number, permissionName: Permissions): GrantStatus

Verifies whether a permission is granted to an application. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Identifier of the target application, which is the value of **accessTokenId** contained in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions | Yes  | Permission to verify. For details about the permission, see [Application Permissions](../../security/AccessToken/app-permissions.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| [GrantStatus](#grantstatus) | Permission grant state.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, or the permissionName exceeds 256 characters. |

**Example**

```ts
import { abilityAccessCtrl, Permissions } from '@kit.AbilityKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a third-party application.
let permissionName: Permissions = 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS';
let data: abilityAccessCtrl.GrantStatus = atManager.checkAccessTokenSync(tokenID, permissionName);
console.log(`data->${JSON.stringify(data)}`);
```

### on<sup>18+</sup>

on(type: 'selfPermissionStateChange', permissionList: Array&lt;Permissions&gt;, callback: Callback&lt;PermissionStateChangeInfo&gt;): void

Subscribes to changes in the state of the specified permissions for this application.

Multiple callbacks can be registered for the same permission list.

The same callback cannot be registered for overlapping permission lists.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | Yes  | Event type. The value is **'selfPermissionStateChange'**, which indicates the changes in the permission states specific to this application alone. |
| permissionList | Array&lt;Permissions&gt;   | Yes  | List of target permissions. If this parameter is not specified, this API will subscribe to state changes of all permissions. For details about the permissions, see [Application Permissions](../../security/AccessToken/app-permissions.md).|
| callback | Callback&lt;[PermissionStateChangeInfo](#permissionstatechangeinfo18)&gt; | Yes| Callback used to return the permission state change.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. Possible causes: 1. The permissionList exceeds the size limit; 2. The permissionNames in the list are all invalid. |
| 12100004 | The API is used repeatedly with the same input. |
| 12100005 | The registration time has exceeded the limit. |
| 12100007 | The service is abnormal. |

**Example**

```ts
import { abilityAccessCtrl, Permissions } from '@kit.AbilityKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let permissionList: Array<Permissions> = ['ohos.permission.APPROXIMATELY_LOCATION'];
try {
    atManager.on('selfPermissionStateChange', permissionList, (data: abilityAccessCtrl.PermissionStateChangeInfo) => {
        console.log('receive permission state change, data:' + JSON.stringify(data));
    });
} catch(err) {
    console.error(`catch err->${JSON.stringify(err)}`);
}
```
### off<sup>18+</sup>

off(type: 'selfPermissionStateChange', permissionList: Array&lt;Permissions&gt;, callback?: Callback&lt;PermissionStateChangeInfo&gt;): void

Unsubscribes from changes in the state of the specified permissions for this application.

If **callback** is not specified, this API will unregister all callbacks for **permissionList**.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name            | Type                  | Mandatory| Description                                                         |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string         | Yes  | Event type. The value is **'selfPermissionStateChange'**, which indicates the changes in the permission states specific to this application alone. |
| permissionList | Array&lt;Permissions&gt;   | Yes  | List of target permissions. The value must be the same as that in **on()**. If this parameter is not specified, this API will unsubscribe from state changes for all permissions. For details about the permissions, see [Application Permissions](../../security/AccessToken/app-permissions.md).|
| callback | Callback&lt;[PermissionStateChangeInfo](#permissionstatechangeinfo18)&gt; | No| Callback to unregister.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The permissionNames in the list are all invalid. |
| 12100004 | The API is not used in pair with 'on'. |
| 12100007 | The service is abnormal. |

**Example**

```ts
import { abilityAccessCtrl, Permissions } from '@kit.AbilityKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let permissionList: Array<Permissions> = ['ohos.permission.APPROXIMATELY_LOCATION'];
try {
    atManager.off('selfPermissionStateChange', permissionList);
} catch(err) {
    console.error(`catch err->${JSON.stringify(err)}`);
}
```

### requestPermissionsFromUser<sup>9+</sup>

requestPermissionsFromUser(context: Context, permissionList: Array&lt;Permissions&gt;, requestCallback: AsyncCallback&lt;PermissionRequestResult&gt;): void

Requests user authorization in a dialog box opened by a <!--RP1-->UIAbility<!--RP1End-->. This API uses an asynchronous callback to return the result.

If the user rejects to grant permissions, the dialog box cannot be displayed again. If permission granting is required, the user can manually grant permissions on the **Settings** page or call [requestPermissionOnSetting](#requestpermissiononsetting12) to display the permission settings dialog box for the user to grant permissions.

> **NOTE**
>
> Only <!--RP1-->UIAbility<!--RP1End--> is supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | [Context](js-apis-inner-application-context.md) | Yes| Context of the <!--RP1-->UIAbility<!--RP1End--> that requests the permission.|
| permissionList | Array&lt;Permissions&gt; | Yes| Permissions to request. For details about the permissions, see [Application Permissions](../../security/AccessToken/app-permissions.md).|
| requestCallback | AsyncCallback&lt;[PermissionRequestResult](js-apis-permissionrequestresult.md)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The context is invalid when it does not belong to the application itself. |

**Example**

For details about how to obtain the context in the example, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).
For details about the process and example of applying for user authorization, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).
<!--code_no_check-->
```ts
import { abilityAccessCtrl, Context, PermissionRequestResult, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
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

Requests user authorization in a dialog box opened by a <!--RP1-->UIAbility<!--RP1End-->. This API uses a promise to return the result.

If the user rejects to grant permissions, the dialog box cannot be displayed again. If permission granting is required, the user can manually grant permissions on the **Settings** page or call [requestPermissionOnSetting](#requestpermissiononsetting12) to display the permission settings dialog box for the user to grant permissions.

> **NOTE**
>
> Only <!--RP1-->UIAbility<!--RP1End--> is supported.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | [Context](js-apis-inner-application-context.md) | Yes| Context of the <!--RP1-->UIAbility<!--RP1End--> that requests the permission.|
| permissionList | Array&lt;Permissions&gt; | Yes| Permission to verify. For details about the permission, see [Application Permissions](../../security/AccessToken/app-permissions.md).|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[PermissionRequestResult](js-apis-permissionrequestresult.md)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The context is invalid when it does not belong to the application itself. |

**Example**

For details about how to obtain the context in the example, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).
For details about the process and example of applying for user authorization, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).
<!--code_no_check-->
```ts
import { abilityAccessCtrl, Context, PermissionRequestResult, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
atManager.requestPermissionsFromUser(context, ['ohos.permission.CAMERA']).then((data: PermissionRequestResult) => {
  console.info('data:' + JSON.stringify(data));
  console.info('data permissions:' + data.permissions);
  console.info('data authResults:' + data.authResults);
  console.info('data dialogShownResults:' + data.dialogShownResults);
}).catch((err: BusinessError) => {
  console.error('data:' + JSON.stringify(err));
});
```

### requestPermissionOnSetting<sup>12+</sup>

requestPermissionOnSetting(context: Context, permissionList: Array&lt;Permissions&gt;): Promise&lt;Array&lt;GrantStatus&gt;&gt;

Requests permissions in a **Settings** dialog box. This API displays a permission settings dialog box for a UIAbility/UIExtensionAbility to grant permissions the second time.

Before calling this API, the application must have called [requestPermissionsFromUser](#requestpermissionsfromuser9). If the user grants the permissions required when the authorization dialog box is displayed the first time, calling this API will not display the permission settings dialog box.

> **NOTE**
>
> This API supports only UIAbilities/UIExtensionAbilities.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | [Context](js-apis-inner-application-context.md) | Yes| Context of the UIAbility/UIExtensionAbility that requests the permissions.|
| permissionList | Array&lt;Permissions&gt; | Yes| Permissions to request. For details about the permissions, see [Application Permission Groups](../../security/AccessToken/app-permission-group-list.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;Array&lt;[GrantStatus](#grantstatus)&gt;&gt; | Promise used to return the authorization result.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. Possible causes: 1. The context is invalid because it does not belong to the application itself; 2. The permission list contains the permission that is not declared in the module.json file; 3. The permission list is invalid because the permissions in it do not belong to the same permission group. |
| 12100010 | The request already exists. |
| 12100011 | All permissions in the permission list have been granted. |
| 12100012 | The permission list contains the permission that has not been revoked by the user. |

**Example**
For details about how to obtain the context in the example, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).
<!--code_no_check-->
```ts
import { abilityAccessCtrl, Context, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
atManager.requestPermissionOnSetting(context, ['ohos.permission.CAMERA']).then((data: Array<abilityAccessCtrl.GrantStatus>) => {
  console.info('data:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error('data:' + JSON.stringify(err));
});
```

### requestGlobalSwitch<sup>12+</sup>

requestGlobalSwitch(context: Context, type: SwitchType): Promise&lt;boolean&gt;

Displays a dialog box for setting a global switch.

When the features such as recording and photographing are disabled, the application can display the dialog box, asking the user to enable the related features. If the global switch is turned on, no dialog box will be displayed.

> **NOTE**
>
> This API supports only UIAbilities/UIExtensionAbilities.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | [Context](js-apis-inner-application-context.md) | Yes| Context of the UIAbility/UIExtensionAbility that requests the permissions.|
| type | [SwitchType](#switchtype12) | Yes| Type of the global switch.|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the global switch status. **true** to enable, **false** otherwise.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12100001 | Invalid parameter. Possible causes: 1. The context is invalid because it does not belong to the application itself; 2. The type of global switch is not support. |
| 12100010 | The request already exists. |
| 12100013 | The specific global switch is already open. |

**Example**
For details about how to obtain the context in the example, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).
<!--code_no_check-->
```ts
import { abilityAccessCtrl, Context, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
atManager.requestGlobalSwitch(context, abilityAccessCtrl.SwitchType.CAMERA).then((data: Boolean) => {
  console.info('data:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error('data:' + JSON.stringify(err));
});
```

### getSelfPermissionStatus<sup>20+</sup>

getSelfPermissionStatus(permissionName: Permissions): PermissionStatus

Queries the permission status of an application. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| permissionName | Permissions | Yes  | Permission to verify. For details about the permission, see [Application Permissions](../../security/AccessToken/app-permissions.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| [PermissionStatus](#permissionstatus20) | Permission status.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 12100001 | Invalid parameter. The permissionName is empty or exceeds 256 characters. |
| 12100007 | The service is abnormal. |

**Example**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
try {
  let data: abilityAccessCtrl.PermissionStatus = atManager.getSelfPermissionStatus('ohos.permission.CAMERA');
  console.info(`data->${JSON.stringify(data)}`);
} catch(err) {
  console.error(`catch err->${JSON.stringify(err)}`);
}
```

### verifyAccessTokenSync<sup>9+</sup>

verifyAccessTokenSync(tokenID: number, permissionName: Permissions): GrantStatus

Verifies whether a permission is granted to an application. This API returns the result synchronously.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Identifier of the target application, which is the value of **accessTokenId** contained in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions | Yes  | Permission to verify. For details about the permission, see [Application Permissions](../../security/AccessToken/app-permissions.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| [GrantStatus](#grantstatus) | Permission grant state.|

**Error codes**

For details about the error codes, see [Access Control Error Codes](errorcode-access-token.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, or the permissionName exceeds 256 characters. |

**Example**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a third-party application.
try {
  let data: abilityAccessCtrl.GrantStatus = atManager.verifyAccessTokenSync(tokenID, 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS');
  console.log(`data->${JSON.stringify(data)}`);
} catch(err) {
  console.error(`catch err->${JSON.stringify(err)}`);
}
```

### verifyAccessToken<sup>9+</sup>

verifyAccessToken(tokenID: number, permissionName: Permissions): Promise&lt;GrantStatus&gt;

Checks whether the user has granted the permission. This API uses a promise to return the result.

> **NOTE**
>
> You are advised to use [checkAccessToken](#checkaccesstoken9).

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Identifier of the target application, which is the value of **accessTokenId** contained in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions | Yes  | Permission to verify. For details about the permission, see [Application Permissions](../../security/AccessToken/app-permissions.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;[GrantStatus](#grantstatus)&gt; | Promise used to return the authorization result.|

**Example**

```ts
import { abilityAccessCtrl, Permissions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a third-party application.
let permissionName: Permissions = 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS';
atManager.verifyAccessToken(tokenID, permissionName).then((data: abilityAccessCtrl.GrantStatus) => {
  console.log(`promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`verifyAccessToken fail, err->${JSON.stringify(err)}`);
});
```

### verifyAccessToken<sup>(deprecated)</sup>

verifyAccessToken(tokenID: number, permissionName: string): Promise&lt;GrantStatus&gt;

Checks whether the user has granted the permission. This API uses a promise to return the result.

> **NOTE**
>
> This API is no longer maintained since API version 9. Use [checkAccessToken](#checkaccesstoken9) instead.

**System capability**: SystemCapability.Security.AccessToken

**Parameters**

| Name  | Type                | Mandatory| Description                                      |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | Yes  | Identifier of the target application, which is the value of **accessTokenId** contained in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | string | Yes  | Permission to verify. For details about the permission, see [Application Permissions](../../security/AccessToken/app-permissions.md).|

**Return value**

| Type         | Description                               |
| :------------ | :---------------------------------- |
| Promise&lt;[GrantStatus](#grantstatus)&gt; | Promise used to return the authorization result.|

**Example**

```ts
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
let tokenID: number = 0; // Use bundleManager.getApplicationInfo() to obtain the token ID for a system application, and use bundleManager.getBundleInfoForSelf() to obtain the token ID for a third-party application.
atManager.verifyAccessToken(tokenID, 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS').then((data: abilityAccessCtrl.GrantStatus) => {
  console.log(`promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`verifyAccessToken fail, err->${JSON.stringify(err)}`);
});
```

## GrantStatus

Enumerates the permission grant states.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Security.AccessToken

| Name              |    Value| Description       |
| ------------------ | ----- | ----------- |
| PERMISSION_DENIED  | -1    | The permission is not granted.|
| PERMISSION_GRANTED | 0     | The permission is granted.|

## SwitchType<sup>12+</sup>

Enumerates the global switch types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Security.AccessToken

| Name              |    Value| Description       |
| ------------------ | ----- | ----------- |
| CAMERA  | 0    | Global switch of the camera.|
| MICROPHONE | 1     | Global switch of the microphone.|
| LOCATION | 2     | Global switch of the location service.|

## PermissionStateChangeType<sup>18+</sup>

Enumerates the operations that trigger permission state changes.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Security.AccessToken

| Name                    |    Value| Description             |
| ----------------------- | ------ | ----------------- |
| PERMISSION_REVOKED_OPER | 0      | Operation to revoke a permission.|
| PERMISSION_GRANTED_OPER | 1      | Operation to grant a permission.|

## PermissionStateChangeInfo<sup>18+</sup>

Represents the permission state change details.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Security.AccessToken

| Name          | Type                      | Read Only| Optional| Description               |
| -------------- | ------------------------- | ---- | ---- | ------------------ |
| change         | [PermissionStateChangeType](#permissionstatechangetype18) | Yes  | No  | Operation that triggers the permission state change.       |
| tokenID        | number                    | Yes  | No  | Identifier of the target application, which is the value of **accessTokenId** contained in [ApplicationInfo](js-apis-bundleManager-applicationInfo.md).|
| permissionName | Permissions                    | Yes  | No  | Permissions whose authorization state changes. For details about the permissions, see [Application Permissions](../../security/AccessToken/app-permissions.md).|

## PermissionRequestResult<sup>10+</sup>

type PermissionRequestResult = _PermissionRequestResult

Represents the permission request result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.AccessToken

| Type| Description|
| -------- | -------- |
| [_PermissionRequestResult](js-apis-permissionrequestresult.md) | Permission request result object.|

## Context<sup>10+</sup>

type Context = _Context

Represents the context for the ability or application. It allows access to application-specific resources.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.AccessToken

| Type| Description|
| -------- | -------- |
| [_Context](js-apis-inner-application-context.md) | Context for an ability or application to access to application-specific resources.|

## PermissionStatus<sup>20+</sup>

Enumerates the permission states.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Security.AccessToken

| Name              |    Value| Description       |
| ------------------ | ----- | ----------- |
| DENIED  | -1    | The permission is not granted.|
| GRANTED | 0     | The permission is granted.|
| NOT_DETERMINED | 1     | The permission state is not determined. This value is returned when the application declares [user_grant permissions](../../security/AccessToken/permissions-for-all-user.md) and does not call [requestPermissionsFromUser](#requestpermissionsfromuser9) to request user authorization, or when the user changes the permission state to **Ask each time** in **Settings**.|
| INVALID | 2     | The permission is invalid. The application does not [declare permissions](../../security/AccessToken/declare-permissions.md) or cannot process the request. For example, if the status of the approximate location permission is **NOT_DETERMINED**, this value will be returned when the status of the precise location permission is queried.|
| RESTRICTED | 3     | The permission is restricted. <!--RP2-->The application is not allowed to call [requestPermissionsFromUser](#requestpermissionsfromuser9) to request user authorization.<!--RP2End--> |
