# @ohos.privacyManager (隐私管理)(系统接口)

本模块主要提供权限使用记录等隐私管理接口。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块为系统接口。

## 导入模块

```ts
import { privacyManager } from '@kit.AbilityKit';
```


## privacyManager.addPermissionUsedRecord

addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number, options?: AddPermissionUsedRecordOptions): Promise&lt;void&gt;

受应用权限保护的应用在被其他服务、应用调用时，可以使用该接口增加一条权限使用记录。使用Promise异步回调。
权限使用记录包括：调用方的应用身份标识、使用的应用权限名称，和其访问本应用成功、失败的次数。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 调用方的应用身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | Permissions | 是   | 应用权限名称。 |
| successCount | number | 是   | 访问成功的次数。 |
| failCount | number | 是   | 访问失败的次数。 |
| options<sup>12+</sup> | [AddPermissionUsedRecordOptions](#addpermissionusedrecordoptions12) | 否   | 添加权限使用记录可选参数，从API version 12开始支持。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, the count value is invalid, or usedType in AddPermissionUsedRecordOptions is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // 可以通过getApplicationInfo获取accessTokenId
privacyManager.addPermissionUsedRecord(tokenID, 'ohos.permission.READ_AUDIO', 1, 0).then(() => {
  console.log('addPermissionUsedRecord success');
}).catch((err: BusinessError) => {
  console.error(`addPermissionUsedRecord fail, err->${JSON.stringify(err)}`);
});
// with options param
let options: privacyManager.AddPermissionUsedRecordOptions = {
  usedType: privacyManager.PermissionUsedType.PICKER_TYPE
};
privacyManager.addPermissionUsedRecord(tokenID, 'ohos.permission.READ_AUDIO', 1, 0, options).then(() => {
  console.log('addPermissionUsedRecord success');
}).catch((err: BusinessError) => {
  console.error(`addPermissionUsedRecord fail, err->${JSON.stringify(err)}`);
});
```

## privacyManager.addPermissionUsedRecord

addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number, callback: AsyncCallback&lt;void&gt;): void

受应用权限保护的应用在被其他服务、应用调用时，可以使用该接口增加一条权限使用记录。使用callback异步回调。
权限使用记录包括：调用方的应用身份标识、使用的应用权限名称，和其访问本应用成功、失败的次数。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 调用方的应用身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | Permissions | 是   | 应用权限名称，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。 |
| successCount | number | 是   | 访问成功的次数。 |
| failCount | number | 是   | 访问失败的次数。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当添加使用记录成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // 可以通过getApplicationInfo获取accessTokenId
privacyManager.addPermissionUsedRecord(tokenID, 'ohos.permission.READ_AUDIO', 1, 0, (err: BusinessError, data: void) => {
  if (err) {
    console.error(`addPermissionUsedRecord fail, err->${JSON.stringify(err)}`);
  } else {
    console.log('addPermissionUsedRecord success');
  }
});
```

## privacyManager.getPermissionUsedRecord

getPermissionUsedRecord(request: PermissionUsedRequest): Promise&lt;PermissionUsedResponse&gt;

获取历史权限使用记录。使用Promise异步回调。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| request   |  [PermissionUsedRequest](#permissionusedrequest)   | 是   | 查询权限使用记录的请求。              |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise<[PermissionUsedResponse](#permissionusedresponse)> | Promise对象。返回查询的权限使用记录。|

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The value of flag in request is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let request: privacyManager.PermissionUsedRequest = {
    'tokenId': 1,
    'isRemote': false,
    'deviceId': 'device',
    'bundleName': 'bundle',
    'permissionNames': [],
    'beginTime': 0,
    'endTime': 1,
    'flag':privacyManager.PermissionUsageFlag.FLAG_PERMISSION_USAGE_DETAIL,
};

privacyManager.getPermissionUsedRecord(request).then((data) => {
  console.log(`getPermissionUsedRecord success, data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`getPermissionUsedRecord fail, err->${JSON.stringify(err)}`);
});
```

## privacyManager.getPermissionUsedRecord

getPermissionUsedRecord(request: PermissionUsedRequest, callback: AsyncCallback&lt;PermissionUsedResponse&gt;): void

获取历史权限使用记录。使用callback异步回调。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| request | [PermissionUsedRequest](#permissionusedrequest) | 是 | 查询权限使用记录的请求。 |
| callback | AsyncCallback<[PermissionUsedResponse](#permissionusedresponse)> | 是 | 回调函数。当查询记录成功时，err为undefined，data为查询到的权限使用记录；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The value of flag in request is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let request: privacyManager.PermissionUsedRequest = {
    'tokenId': 1,
    'isRemote': false,
    'deviceId': 'device',
    'bundleName': 'bundle',
    'permissionNames': [],
    'beginTime': 0,
    'endTime': 1,
    'flag':privacyManager.PermissionUsageFlag.FLAG_PERMISSION_USAGE_DETAIL,
};

privacyManager.getPermissionUsedRecord(request, (err: BusinessError, data: privacyManager.PermissionUsedResponse) => {
  if (err) {
    console.error(`getPermissionUsedRecord fail, err->${JSON.stringify(err)}`);
  } else {
    console.log(`getPermissionUsedRecord success, data->${JSON.stringify(data)}`);
  }
});
```

## privacyManager.setPermissionUsedRecordToggleStatus<sup>16+</sup>

setPermissionUsedRecordToggleStatus(status: boolean): Promise&lt;void&gt;

设置是否记录当前用户的权限使用情况。系统应用调用此接口，可以设置当前用户的权限使用记录开关状态，使用Promise异步回调。

status为true时，[addPermissionUsedRecord](#privacymanageraddpermissionusedrecord)接口可以正常添加使用记录；status为false时，[addPermissionUsedRecord](#privacymanageraddpermissionusedrecord)接口不记录权限使用记录，并且删除当前用户的历史记录。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型   | 必填 | 说明                                  |
| -------------- | ------ | ---- | ------------------------------------ |
| status        | boolean | 是   | 权限使用记录开关状态。true为开，false为关。|

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。|

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100007 | The service is abnormal. |
| 12100009 | Common inner error. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

privacyManager.setPermissionUsedRecordToggleStatus(true).then(() => {
  console.log('setPermissionUsedRecordToggleStatus success');
}).catch((err: BusinessError) => {
  console.error(`setPermissionUsedRecordToggleStatus fail, err->${JSON.stringify(err)}`);
});
```

## privacyManager.getPermissionUsedRecordToggleStatus<sup>16+</sup>

getPermissionUsedRecordToggleStatus(): Promise&lt;boolean&gt;

系统应用调用此接口，可以获取当前用户的权限使用记录开关状态，使用Promise异步回调。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回当前用户的开关状态值。|

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 12100007 | The service is abnormal. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

privacyManager.getPermissionUsedRecordToggleStatus().then((res) => {
  console.log('getPermissionUsedRecordToggleStatus success');
  if (res == true) {
    console.log('get status is TRUE');
  } else {
    console.log('get status is FALSE');
  }
}).catch((err: BusinessError) => {
  console.error(`getPermissionUsedRecordToggleStatus fail, err->${JSON.stringify(err)}`);
});
```

## privacyManager.startUsingPermission

startUsingPermission(tokenID: number, permissionName: Permissions): Promise&lt;void&gt;

系统应用调用此接口，能够传递应用在前后台的权限使用情况，并依据应用的生命周期做出相应的响应。使用Promise异步回调。

当应用开始使用某项权限时，隐私服务将通知隐私指示器该应用正在使用该权限；当应用退出时，隐私服务将通知隐私指示器该应用已停止使用该权限，并清除相应的缓存。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型   | 必填 | 说明                                  |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | 是   | 调用方的应用身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | Permissions | 是   | 需要使用的权限名，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。|

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。|

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100004 | The API is used repeatedly with the same input. It means the application specified by the tokenID has been using the specified permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // 可以通过getApplicationInfo获取accessTokenId
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO').then(() => {
  console.log('startUsingPermission success');
}).catch((err: BusinessError) => {
  console.error(`startUsingPermission fail, err->${JSON.stringify(err)}`);
});
```

## privacyManager.startUsingPermission<sup>16+</sup>

startUsingPermission(tokenID: number, permissionName: Permissions, pid?: number, usedType?: PermissionUsedType): Promise&lt;void&gt;

系统应用调用此接口，能够传递应用在前后台的权限使用情况，并依据应用的生命周期做出相应的响应。使用Promise异步回调。

当应用按照某种权限授予方式使用权限时，隐私服务将通知隐私指示器该应用正在使用该权限；当应用退出时，隐私服务将通知隐私指示器该应用已停止使用该权限，并清除相应的缓存。

在传递多进程应用的权限使用情况时，可以指定应用进程的pid。若未指定pid，默认按应用响应，在应用退出时，隐私服务通知隐私指示器并清除缓存。

若指定了pid，当该进程退出时，隐私服务通知隐私指示器并清除缓存，此时pid必须为tokenID对应应用的进程pid，不能为其他应用的pid。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型   | 必填 | 说明                                  |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | 是   | 调用方的应用身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | Permissions | 是   | 需要使用的权限名，合法的权限名取值可在[应用权限列表](../../security/AccessToken/permissions-for-all.md)中查询。|
| pid            | number | 否   | 调用方的进程pid，默认-1，-1表示不根据进程生命周期响应。|
| usedType       | [PermissionUsedType](#permissionusedtype12) | 否 | 敏感权限访问方式，默认NORMAL_TYPE。 |

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。|

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100004 | The API is used repeatedly with the same input. It means the application specified by the tokenID has been using the specified permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit'

let tokenID: number = rpc.IPCSkeleton.getCallingTokenId(); // 也可以通过bundleManager.getBundleInfoForSelfSync获取accessTokenId
let pid: number = rpc.IPCSkeleton.getCallingPid();
let usedType: privacyManager.PermissionUsedType = privacyManager.PermissionUsedType.PICKER_TYPE;

// without pid and usedType
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO').then(() => {
  console.log('startUsingPermission success');
}).catch((err: BusinessError) => {
  console.error(`startUsingPermission fail, err->${JSON.stringify(err)}`);
});
// with pid
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', pid).then(() => {
  console.log('startUsingPermission success');
}).catch((err: BusinessError) => {
  console.error(`startUsingPermission fail, err->${JSON.stringify(err)}`);
});
// with usedType
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', -1, usedType).then(() => {
  console.log('startUsingPermission success');
}).catch((err: BusinessError) => {
  console.error(`startUsingPermission fail, err->${JSON.stringify(err)}`);
});
// with pid and usedType
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', pid, usedType).then(() => {
  console.log('startUsingPermission success');
}).catch((err: BusinessError) => {
  console.error(`startUsingPermission fail, err->${JSON.stringify(err)}`);
});
```

## privacyManager.startUsingPermission

startUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback&lt;void&gt;): void

系统应用调用此接口，能够传递应用在前后台的权限使用情况，并依据应用的生命周期做出相应的响应。使用callback异步回调。

当应用开始使用某项权限时，隐私服务将通知隐私指示器该应用正在使用该权限；当应用退出时，隐私服务将通知隐私指示器该应用已停止使用该权限，并清除相应的缓存。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型                  | 必填 | 说明                                  |
| -------------- | --------------------- | ---- | ------------------------------------ |
| tokenID        | number                | 是   | 调用方的应用身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | Permissions                | 是   | 需要使用的权限名，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。|
| callback       | AsyncCallback&lt;void&gt; | 是   | 回调函数。当开始使用权限成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100004 | The API is used repeatedly with the same input. It means the application specified by the tokenID has been using the specified permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // 可以通过getApplicationInfo获取accessTokenId
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', (err: BusinessError, data: void) => {
  if (err) {
    console.error(`startUsingPermission fail, err->${JSON.stringify(err)}`);
  } else {
    console.log('startUsingPermission success');
  }
});
```

## privacyManager.stopUsingPermission

stopUsingPermission(tokenID: number, permissionName: Permissions): Promise&lt;void&gt;

应用停止使用某项权限，与Start对应，由系统服务调用。使用Promise异步回调。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型   | 必填 | 说明                                  |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | 是   | 调用方的应用身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | Permissions | 是   | 需要使用的权限名，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。|

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。|

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100004 | The API is not used in pair with 'startUsingPermission'. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // 可以通过getApplicationInfo获取accessTokenId
privacyManager.stopUsingPermission(tokenID, 'ohos.permission.READ_AUDIO').then(() => {
  console.log('stopUsingPermission success');
}).catch((err: BusinessError) => {
  console.error(`stopUsingPermission fail, err->${JSON.stringify(err)}`);
});
```

## privacyManager.stopUsingPermission<sup>16+</sup>

stopUsingPermission(tokenID: number, permissionName: Permissions, pid?: number): Promise&lt;void&gt;

应用停止使用某项权限，与Start对应，由系统服务调用。使用Promise异步回调。

pid需要与startUsingPermission传入的pid相同。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型   | 必填 | 说明                                  |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | 是   | 调用方的应用身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | Permissions | 是   | 需要使用的权限名，合法的权限名取值可在[应用权限列表](../../security/AccessToken/permissions-for-all.md)中查询。|
| pid            | number | 否   | 与startUsingPermission传入的pid相同，默认-1。|

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。|

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100004 | The API is not used in pair with 'startUsingPermission'. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit'

let tokenID: number = rpc.IPCSkeleton.getCallingTokenId(); // 也可以通过bundleManager.getBundleInfoForSelfSync获取accessTokenId
let pid: number = rpc.IPCSkeleton.getCallingPid();

// without pid
privacyManager.stopUsingPermission(tokenID, 'ohos.permission.READ_AUDIO').then(() => {
  console.log('stopUsingPermission success');
}).catch((err: BusinessError) => {
  console.error(`stopUsingPermission fail, err->${JSON.stringify(err)}`);
});

// with pid
privacyManager.stopUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', pid).then(() => {
  console.log('stopUsingPermission success');
}).catch((err: BusinessError) => {
  console.error(`stopUsingPermission fail, err->${JSON.stringify(err)}`);
});
```

## privacyManager.stopUsingPermission

stopUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback&lt;void&gt;): void

应用停止使用某项权限，与Start对应，由系统服务调用。使用callback异步回调。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型                  | 必填 | 说明                                  |
| -------------- | --------------------- | ---- | ------------------------------------ |
| tokenID        | number                | 是   | 调用方的应用身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)的accessTokenId字段获得。|
| permissionName | Permissions                | 是   | 需要使用的权限名，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。|
| callback       | AsyncCallback&lt;void&gt; | 是   | 回调函数。当停止使用权限成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not an user_grant permission. |
| 12100004 | The API is not used in pair with 'startUsingPermission'. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // 可以通过getApplicationInfo获取accessTokenId
privacyManager.stopUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', (err: BusinessError, data: void) => {
  if (err) {
    console.error(`stopUsingPermission fail, err->${JSON.stringify(err)}`);
  } else {
    console.log('stopUsingPermission success');
  }
});
```

## privacyManager.on

on(type: 'activeStateChange', permissionList: Array&lt;Permissions&gt;, callback: Callback&lt;ActiveChangeResponse&gt;): void

订阅指定权限列表的权限使用状态变更事件。

允许相同permissionList订阅多个callback。

不允许存在交集的permissionList订阅相同callback。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名             | 类型                   | 必填 | 说明                                                          |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | 是   | 订阅事件类型，固定为'activeStateChange'，权限使用状态变更事件。   |
| permissionList | Array&lt;Permissions&gt;   | 是   | 订阅的权限名列表，为空时表示订阅所有的权限使用状态变化，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。|
| callback | Callback&lt;[ActiveChangeResponse](#activechangeresponse)&gt; | 是 | 订阅指定权限使用状态变更事件的回调。 |

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, or the permissionName exceeds 256 characters. |
| 12100004 | The API is used repeatedly with the same input. |
| 12100005 | The registration time has exceeded the limitation. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager, Permissions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let permissionList: Array<Permissions> = [];
try {
    privacyManager.on('activeStateChange', permissionList, (data: privacyManager.ActiveChangeResponse) => {
        console.debug('receive permission state change, data:' + JSON.stringify(data));
    });
} catch(err) {
    console.error(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.off

off(type: 'activeStateChange', permissionList: Array&lt;Permissions&gt;, callback?: Callback&lt;ActiveChangeResponse&gt;): void

取消订阅指定权限列表的权限使用状态变更事件。

取消订阅不传callback时，批量删除permissionList下面的所有callback。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名             | 类型                   | 必填 | 说明                                                          |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | 是   | 取消订阅事件类型，固定为'activeStateChange'，权限使用状态变更事件。   |
| permissionList | Array&lt;Permissions&gt;   | 是   | 取消订阅的权限名列表，为空时表示订阅所有的权限状态变化，必须与on的输入一致，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。|
| callback | Callback&lt;[ActiveChangeResponse](#activechangeresponse)&gt; | 否 | 取消订阅指定tokenId与指定权限名状态变更事件的回调。|

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The permissionNames in the list are all invalid, or the list size exceeds 1024 bytes. |
| 12100004 | The API is not used in pair with 'on'. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager, Permissions } from '@kit.AbilityKit';

let permissionList: Array<Permissions> = [];
try {
    privacyManager.off('activeStateChange', permissionList);
} catch(err) {
    console.error(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.getPermissionUsedTypeInfos<sup>12+</sup>

getPermissionUsedTypeInfos(tokenId?: number, permissionName?: Permissions): Promise&lt;Array&lt;PermissionUsedTypeInfo&gt;&gt;

查询设备上指定应用访问敏感权限时的信息（包括敏感权限名称、敏感权限访问方式）。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名             | 类型                   | 必填 | 说明                                                          |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| tokenId            | number                | 否   | 访问敏感权限的应用身份标识，为空时表示查询所有应用的敏感权限访问类型信息。   |
| permissionName     | Permissions           | 否   | 被访问的敏感权限名称，为空时标识查询所有敏感权限的访问类型信息。   |

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;Array&lt;[PermissionUsedTypeInfo](#permissionusedtypeinfo12)&gt;&gt; | Promise对象。返回权限访问类型信息列表的Promise对象。|

**错误码：**

以下错误码的详细介绍请参见[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 12100001 | Invalid parameter. PermissionName exceeds 256 characters. |
| 12100002 | The input tokenId does not exist. |
| 12100003 | The input permissionName does not exist. |

**示例：**

```ts
import { privacyManager, Permissions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenId: number = 0; // 可以通过bundleManager.getApplicationInfo获取accessTokenId
let permissionName: Permissions = 'ohos.permission.CAMERA';
// without any param
privacyManager.getPermissionUsedTypeInfos().then(() => {
  console.log('getPermissionUsedTypeInfos success');
}).catch((err: BusinessError) => {
  console.error(`getPermissionUsedTypeInfos fail, err->${JSON.stringify(err)}`);
});
// only tokenId
privacyManager.getPermissionUsedTypeInfos(tokenId).then(() => {
  console.log('getPermissionUsedTypeInfos success');
}).catch((err: BusinessError) => {
  console.error(`getPermissionUsedTypeInfos fail, err->${JSON.stringify(err)}`);
});
// only permissionName
privacyManager.getPermissionUsedTypeInfos(null, permissionName).then(() => {
  console.log('getPermissionUsedTypeInfos success');
}).catch((err: BusinessError) => {
  console.error(`getPermissionUsedTypeInfos fail, err->${JSON.stringify(err)}`);
});
// tokenId and permissionName
privacyManager.getPermissionUsedTypeInfos(tokenId, permissionName).then(() => {
  console.log('getPermissionUsedTypeInfos success');
}).catch((err: BusinessError) => {
  console.error(`getPermissionUsedTypeInfos fail, err->${JSON.stringify(err)}`);
});
```

## PermissionUsageFlag

使用记录的查询方式的枚举。

**系统能力：** SystemCapability.Security.AccessToken

| 名称                    | 值 | 说明                   |
| ----------------------- | ------ | ---------------------- |
| FLAG_PERMISSION_USAGE_SUMMARY             | 0    | 表示查询总览数据。 |
| FLAG_PERMISSION_USAGE_DETAIL         | 1    | 表示查询详细数据。         |

## PermissionUsedRequest

表示使用记录的查询请求。

**系统能力：** SystemCapability.Security.AccessToken

| 名称       | 类型             | 必填   | 说明                                       |
| -------- | -------------- | ---- | ---------------------------------------- |
| tokenId  | number         | 否    | 目标应用的身份标识。<br/> 默认查询所有应用。         |
| isRemote | boolean         | 否    | 指定是否查询远端设备。<br/> 默认值：false，默认查询本端设备。 |
| deviceId  | string         | 否    | 目标应用所在设备的ID。<br/> 默认设备ID为本端设备ID。   |
| bundleName | string         | 否    | 目标应用的包名。<br/> 默认查询所有应用。 |
| permissionNames  | Array&lt;Permissions&gt;         | 否    | 需要查询的权限集合。<br/> 默认查询所有权限的使用记录。               |
| beginTime | number         | 否    | 查询的起始时间，单位：ms。<br/>默认值0，不设定起始时间。 |
| endTime | number         | 否    | 查询的终止时间，单位：ms。<br/>默认值0，不设定终止时间。 |
| flag | [PermissionUsageFlag](#permissionusageflag)         | 是    | 指定查询方式。 |

## PermissionUsedResponse

表示所有应用的访问记录。

**系统能力：** SystemCapability.Security.AccessToken

| 名称       | 类型             | 可读 | 可写 | 说明                                       |
| --------- | -------------- | ---- | ---- | ---------------------------------------- |
| beginTime | number         | 是    | 否    | 查询记录的起始时间，单位：ms。 |
| endTime   | number         | 是    | 否    | 查询记录的终止时间，单位：ms。 |
| bundleRecords  | Array&lt;[BundleUsedRecord](#bundleusedrecord)&gt;         | 是    | 否    | 应用的权限使用记录集合。                                 |

## BundleUsedRecord

某个应用的访问记录。

**系统能力：** SystemCapability.Security.AccessToken

| 名称       | 类型             | 可读 | 可写 | 说明                                       |
| -------- | -------------- | ---- | ---- | ---------------------------------------- |
| tokenId  | number         | 是    | 否    | 目标应用的身份标识。                                 |
| isRemote | boolean         | 是    | 否    | 默认值false。 |
| deviceId  | string         | 是    | 否    | 目标应用所在设备的ID。                                 |
| bundleName | string         | 是    | 否    | 目标应用的包名。 |
| permissionRecords  | Array&lt;[PermissionUsedRecord](#permissionusedrecord)&gt;         | 是    | 否    | 每个应用的权限使用记录集合。                                 |

## PermissionUsedRecord

某个权限的访问记录。

**系统能力：** SystemCapability.Security.AccessToken

| 名称       | 类型             | 可读 | 可写 | 说明                                       |
| -------- | -------------- | ---- | ---- | ---------------------------------------- |
| permissionName  | Permissions         | 是    | 否    | 权限名。                                 |
| accessCount | number         | 是    | 否    | 该权限访问总次数。 |
| rejectCount | number         | 是    | 否    | 该权限拒绝总次数。 |
| lastAccessTime | number         | 是    | 否    | 最后一次访问时间，单位：ms。 |
| lastRejectTime | number         | 是    | 否    | 最后一次拒绝时间，单位：ms。 |
| lastAccessDuration | number         | 是    | 否    | 最后一次访问时长，单位：ms。 |
| accessRecords  | Array&lt;[UsedRecordDetail](#usedrecorddetail)&gt;         | 是    | 否    | 访问记录集合，当flag为FLAG_PERMISSION_USAGE_DETAIL时生效，默认查询10条。                                 |
| rejectRecords  | Array&lt;[UsedRecordDetail](#usedrecorddetail)&gt;         | 是    | 否    | 拒绝记录集合，当flag为FLAG_PERMISSION_USAGE_DETAIL时生效，默认查询10条。                                 |

## UsedRecordDetail

单次访问记录详情。

**系统能力：** SystemCapability.Security.AccessToken

| 名称       | 类型             | 可读 | 可写 | 说明                                       |
| -------- | -------------- | ---- | ---- | ---------------------------------------- |
| status  | number         | 是    | 否    | 访问状态。                                 |
| lockScreenStatus<sup>11+</sup>  | number         | 是    | 否    | 访问时的锁屏状态。<br> - 1，表示非锁屏场景使用权限。<br> - 2，表示锁屏场景使用权限。                                 |
| timestamp | number         | 是    | 否    | 访问时的时间戳，单位：ms。 |
| accessDuration  | number         | 是    | 否    | 访问时长，单位：ms。                                 |
| count<sup>11+</sup> | number | 是 | 否    | 成功或失败次数。
| usedType<sup>12+</sup> | [PermissionUsedType](#permissionusedtype12) | 是 | 否    | 敏感权限访问方式。 |

## PermissionActiveStatus

表示权限使用状态变化类型的枚举。

**系统能力：** SystemCapability.Security.AccessToken

| 名称                      | 值     | 说明              |
| ------------------------- | ------ | ---------------- |
| PERM_INACTIVE             | 0      | 表示未使用权限。   |
| PERM_ACTIVE_IN_FOREGROUND | 1      | 表示前台使用权限。 |
| PERM_ACTIVE_IN_BACKGROUND | 2      | 表示后台使用权限。 |

## ActiveChangeResponse

表示某次权限使用状态变化的详情。

 **系统能力:** SystemCapability.Security.AccessToken

| 名称           | 类型                    | 可读 | 可写 | 说明                   |
| -------------- | ---------------------- | ---- | ---- | --------------------- |
| callingTokenId<sup>16+</sup> | number   | 是   | 否   | 接口调用方的应用身份标识，activeStatus是INACTIVE时该值无效。 |
| tokenId        | number                 | 是   | 否   | 被订阅的应用身份标识。    |
| permissionName | Permissions            | 是   | 否   | 权限使用状态发生变化的权限名。 |
| deviceId       | string                 | 是   | 否   | 设备号。                 |
| activeStatus   | [PermissionActiveStatus](#permissionactivestatus) | 是   | 否   | 权限使用状态变化类型。        |
| usedType<sup>16+</sup> | [PermissionUsedType](#permissionusedtype12) | 是   | 否   | 敏感权限使用类型，activeStatus是INACTIVE时该值无效。 |

## PermissionUsedType<sup>12+</sup>

表示通过何种方式使用敏感权限的枚举。

**系统能力：** SystemCapability.Security.AccessToken

| 名称                    | 值 | 说明              |
| ----------------------- | -- | ---------------- |
| NORMAL_TYPE             | 0  | 表示通过弹窗授权或设置授权的方式来使用敏感权限。   |
| PICKER_TYPE             | 1  | 表示通过某个PICKER服务来使用敏感权限，此方式未授予权限。 |
| SECURITY_COMPONENT_TYPE | 2  | 表示通过安全控件授权的方式来使用敏感权限。 |

## PermissionUsedTypeInfo<sup>12+</sup>

表示某次权限使用类型的详情。

 **系统能力:** SystemCapability.Security.AccessToken

| 名称           | 类型                    | 可读 | 可写 | 说明                   |
| -------------- | ---------------------- | ---- | ---- | --------------------- |
| tokenId        | number                 | 是   | 否   | 访问敏感权限的应用身份标识。 |
| permissionName | Permissions            | 是   | 否   | 被访问的敏感权限名称。 |
| usedType | [PermissionUsedType](#permissionusedtype12) | 是 | 否    | 敏感权限使用类型。 |

## AddPermissionUsedRecordOptions<sup>12+</sup>

添加权限使用记录可选参数集。

 **系统能力:** SystemCapability.Security.AccessToken

| 名称           | 类型                    | 可读 | 可写 | 说明                   |
| -------------- | ---------------------- | ---- | ---- | --------------------- |
| usedType | [PermissionUsedType](#permissionusedtype12) | 是 | 否    | 敏感权限使用类型。 |
