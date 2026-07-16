# @ohos.privacyManager (隐私管理)(系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--Designer: @linshuqing; @hehehe-li-->
<!--Tester: @leiyuqian-->
<!--Adviser: @zengyawen-->

本模块主要提供权限使用记录等隐私管理接口，支持系统应用记录、查询、监听和控制敏感权限的使用情况。权限使用记录用于描述某项敏感权限何时被使用、以何种方式被使用、当前是否处于使用中，以及这些使用记录是否允许被记录或查询。

该模块主要用于以下场景：

- 添加/查询指定应用的敏感权限访问记录。
- 订阅权限使用状态变化事件，感知权限从未使用到前台使用、后台使用的变化，与业务逻辑进行联动。
- 控制当前用户的权限访问记录开关。
- 查询某个权限当前是否正在被使用。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块为系统接口。

## 关键Class/Interface介绍

### 核心枚举类型

- **[PermissionUsageFlag](#permissionusageflag)：** 权限使用记录查询方式枚举，用于指定查询汇总数据或明细数据。
- **[PermissionActiveStatus](#permissionactivestatus)：** 权限使用状态变化类型枚举，用于表示未使用、前台使用或后台使用状态。
- **[PermissionUsedType](#permissionusedtype12)：** 敏感权限使用类型枚举，用于表示通过普通授权、Picker或安全控件方式使用敏感权限。

### 核心接口类型

- **[PermissionUsedRequest](#permissionusedrequest)：** 权限使用记录查询请求对象，用于指定查询应用、权限、时间范围和查询方式。
- **[PermissionUsedResponse](#permissionusedresponse)：** 权限使用记录查询响应对象，用于返回查询时间范围和应用维度记录集合。
- **[BundleUsedRecord](#bundleusedrecord)：** 应用或设备维度的权限使用记录对象，用于返回某个应用或远端设备的权限访问记录。
- **[PermissionUsedRecord](#permissionusedrecord)：** 单个权限的访问记录对象，用于返回访问次数、拒绝次数、最后访问时间和明细记录。
- **[UsedRecordDetail](#usedrecorddetail)：** 单次访问记录详情对象，用于返回访问状态、时间戳、访问时长和使用类型等信息。
- **[ActiveChangeResponse](#activechangeresponse)：** 权限使用状态变化事件对象，用于返回权限活跃状态变化详情。
- **[PermissionUsedTypeInfo](#permissionusedtypeinfo12)：** 权限使用类型信息对象，用于返回应用访问敏感权限时的使用类型。
- **[AddPermissionUsedRecordOptions](#addpermissionusedrecordoptions12)：** 添加权限使用记录可选参数对象，用于指定敏感权限使用类型和扩展身份。
- **[PermissionUsingOptions](#permissionusingoptions)：** 权限使用可选参数对象，用于指定扩展身份。

### 核心函数类型

- **[addPermissionUsedRecord](#privacymanageraddpermissionusedrecord)：** 添加权限使用记录。
- **[getPermissionUsedRecord](#privacymanagergetpermissionusedrecord)：** 查询权限使用记录。
- **[setPermissionUsedRecordToggleStatus](#privacymanagersetpermissionusedrecordtogglestatus18)：** 设置权限使用记录开关状态。
- **[getPermissionUsedRecordToggleStatus](#privacymanagergetpermissionusedrecordtogglestatus18)：** 查询权限使用记录开关状态。
- **[startUsingPermission](#privacymanagerstartusingpermission)：** 标记开始使用敏感权限。
- **[stopUsingPermission](#privacymanagerstopusingpermission)：** 标记停止使用敏感权限。
- **[checkPermissionInUse](#privacymanagercheckpermissioninuse)：** 检查指定权限当前是否正在被使用。
- **[on](#privacymanageron)：** 订阅权限使用状态变化事件。
- **[off](#privacymanageroff)：** 取消订阅权限使用状态变化事件。
- **[getPermissionUsedTypeInfos](#privacymanagergetpermissionusedtypeinfos12)：** 查询敏感权限访问类型信息。

### 核心类

- **privacyManager：** 提供隐私管理的核心类。

![](figures/privacyManager.png)

### API组合使用关系说明

场景1：维护权限使用记录。

场景说明：
- 系统应用访问敏感权限时，需要在使用开始时调用[startUsingPermission](#privacymanagerstartusingpermission)，在使用结束时调用[stopUsingPermission](#privacymanagerstopusingpermission)，以便系统感知对应的权限使用状态变化；
- 系统应用访问敏感权限后，可以调用[addPermissionUsedRecord](#privacymanageraddpermissionusedrecord)，以便系统记录对应的敏感权限访问事件。

典型使用流程如下：

```ts
import { privacyManager, Permissions } from '@kit.AbilityKit';

let tokenID: number = 0; // 获取tokenID的方式可参考相关BundleInfo章节的描述。
let permissionName: Permissions = 'ohos.permission.CAMERA';
let pid: number = 0; // 可以通过rpc.IPCSkeleton.getCallingPid()获取。
let usedType: privacyManager.PermissionUsedType = privacyManager.PermissionUsedType.NORMAL_TYPE;
let successCount: number = 1;
let failCount: number = 0;
let options: privacyManager.AddPermissionUsedRecordOptions = {
  usedType: privacyManager.PermissionUsedType.NORMAL_TYPE
};

// 1. 标记应用开始使用敏感权限。
await privacyManager.startUsingPermission(tokenID, permissionName, pid, usedType);

// 2. 在流程结束后补充访问记录。
await privacyManager.addPermissionUsedRecord(tokenID, permissionName, successCount, failCount, options);

// 3. 标记应用结束使用敏感权限。
await privacyManager.stopUsingPermission(tokenID, permissionName, pid);
```

场景2：查询权限使用记录。

场景说明：系统应用需要查询敏感权限历史使用情况时，可构造[PermissionUsedRequest](#permissionusedrequest)指定查询范围，再调用[getPermissionUsedRecord](#privacymanagergetpermissionusedrecord)获取访问次数、时间戳、时长等历史记录。若需要查询敏感权限的访问方式分类（普通授权、Picker或安全控件），可调用[getPermissionUsedTypeInfos](#privacymanagergetpermissionusedtypeinfos12)。

典型使用流程如下：

```ts
import { privacyManager, Permissions } from '@kit.AbilityKit';

let tokenID: number = 0; // 获取tokenID的方式可参考相关BundleInfo章节的描述。
let permissionName: Permissions = 'ohos.permission.CAMERA';
let request: privacyManager.PermissionUsedRequest = {
  tokenId: tokenID,
  permissionNames: [permissionName],
  beginTime: 0,
  endTime: 0,
  flag: privacyManager.PermissionUsageFlag.FLAG_PERMISSION_USAGE_DETAIL
};

// 1. 查询历史权限使用记录。
await privacyManager.getPermissionUsedRecord(request);

// 2. 查询敏感权限访问类型信息。
await privacyManager.getPermissionUsedTypeInfos(tokenID, permissionName);
```

场景3：监听和检查权限使用状态。

场景说明：系统应用需要感知敏感权限当前是否处于使用中，或在权限使用状态变化时联动业务流程，例如在权限管理界面实时展示权限使用状态、在权限使用时触发安全审计、在检测到异常权限使用时发出告警，可组合使用[checkPermissionInUse](#privacymanagercheckpermissioninuse)、[on](#privacymanageron)和[off](#privacymanageroff)。

典型使用流程如下：

```ts
import { privacyManager, Permissions } from '@kit.AbilityKit';

let permissionName: Permissions = 'ohos.permission.CAMERA';
let permissionList: Array<Permissions> = [permissionName];
let callback: (data: privacyManager.ActiveChangeResponse) => void =
  (data: privacyManager.ActiveChangeResponse): void => {
    console.info(`receive permission state change, data: ${JSON.stringify(data)}`);
  };

// 1. 查询当前权限是否正在使用中。
privacyManager.checkPermissionInUse(permissionName);

// 2. 订阅指定权限的使用状态变化。
privacyManager.on('activeStateChange', permissionList, callback);

// 3. 不再需要时取消订阅。
privacyManager.off('activeStateChange', permissionList, callback);
```

## 导入模块

```ts
import { privacyManager } from '@kit.AbilityKit';
```

## privacyManager.addPermissionUsedRecord

addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number, options?: AddPermissionUsedRecordOptions): Promise&lt;void&gt;

受权限保护的应用在被其他服务、应用调用时，可以使用该接口增加一条权限使用记录。建议在访问敏感权限后调用此接口，以便系统记录对应的敏感权限访问事件。使用Promise异步回调。

权限使用记录包括：调用方的应用身份标识、使用的应用权限名称，以及调用方访问本应用成功和失败的次数。

权限使用记录受[setPermissionUsedRecordToggleStatus](#privacymanagersetpermissionusedrecordtogglestatus18)设置的开关状态控制。开关关闭时，调用此接口不会产生权限使用记录。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 调用方的应用身份标识。可通过应用[BundleInfo](js-apis-bundleManager-bundleInfo.md)中的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md#applicationinfo-1)的accessTokenId字段获取。该参数必须为大于0的整数，传入0时返回错误码12100001。|
| permissionName | [Permissions](../../security/AccessToken/app-permissions.md) | 是   | 需要记录的权限名称。权限名长度不能超过256个字符，传入无效值时返回错误码12100001。 |
| successCount | number | 是   | 访问成功的次数，取值必须为非负整数。传入无效值时返回错误码12100001。 |
| failCount | number | 是   | 访问失败的次数，取值必须为非负整数。传入无效值时返回错误码12100001。 |
| options<sup>12+</sup> | [AddPermissionUsedRecordOptions](#addpermissionusedrecordoptions12) | 否   | 添加权限使用记录可选参数，用于指定敏感权限使用类型和扩展身份。当需要区分权限访问方式（如通过Picker或安全控件访问）或标识调用方扩展身份时传入此参数。<br>usedType：从API version 12开始支持。<br>默认值：NORMAL_TYPE。<br>enhancedIdentity：从API版本26.0.0开始支持，长度不超过48个字符。<br>默认值：""。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, the count value is invalid, usedType in [AddPermissionUsedRecordOptions](#addpermissionusedrecordoptions12) is invalid, or the enhancedIdentity in [AddPermissionUsedRecordOptions](#addpermissionusedrecordoptions12) exceeds 48 characters. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |
| 12100009 | Common inner error. A database error occurs. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // 可以通过应用BundleInfo中的ApplicationInfo的accessTokenId字段获取。
// 添加权限使用记录
privacyManager.addPermissionUsedRecord(tokenID, 'ohos.permission.READ_AUDIO', 1, 0).then(() => {
  console.info('addPermissionUsedRecord success');
}).catch((err: BusinessError): void => {
  console.error(`addPermissionUsedRecord fail, code: ${err.code}, message: ${err.message}`);
});
// with options param
let options: privacyManager.AddPermissionUsedRecordOptions = {
  usedType: privacyManager.PermissionUsedType.PICKER_TYPE,
  enhancedIdentity: 'test'
};
privacyManager.addPermissionUsedRecord(tokenID, 'ohos.permission.READ_AUDIO', 1, 0, options).then(() => {
  console.info('addPermissionUsedRecord success');
}).catch((err: BusinessError): void => {
  console.error(`addPermissionUsedRecord fail, code: ${err.code}, message: ${err.message}`);
});
```

## privacyManager.addPermissionUsedRecord

addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number, callback: AsyncCallback&lt;void&gt;): void

受权限保护的应用在被其他服务、应用调用时，可以使用该接口增加一条权限使用记录。建议在访问敏感权限后调用此接口，以便系统记录对应的敏感权限访问事件。使用callback异步回调。

权限使用记录包括：调用方的应用身份标识、使用的应用权限名称，以及调用方访问本应用成功和失败的次数。

权限使用记录受[setPermissionUsedRecordToggleStatus](#privacymanagersetpermissionusedrecordtogglestatus18)设置的开关状态控制。开关关闭时，调用此接口不会产生权限使用记录。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 调用方的应用身份标识。可通过应用[BundleInfo](js-apis-bundleManager-bundleInfo.md)中的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md#applicationinfo-1)的accessTokenId字段获取。该参数必须为大于0的整数，传入0时返回错误码12100001。|
| permissionName | [Permissions](../../security/AccessToken/app-permissions.md) | 是   | 需要记录的权限名称。权限名长度不能超过256个字符，传入无效值时返回错误码12100001。 |
| successCount | number | 是   | 访问成功的次数，取值必须为非负整数。传入无效值时返回错误码12100001。 |
| failCount | number | 是   | 访问失败的次数，取值必须为非负整数。传入无效值时返回错误码12100001。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当添加使用记录成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the count value is invalid. |
| 12100002 | The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |
| 12100009 | Common inner error. A database error occurs. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // 可以通过应用BundleInfo中的ApplicationInfo的accessTokenId字段获取。
// 添加权限使用记录
privacyManager.addPermissionUsedRecord(tokenID, 'ohos.permission.READ_AUDIO', 1, 0, (err: BusinessError, data: void) => {
  if (err) {
    console.error(`addPermissionUsedRecord fail, code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('addPermissionUsedRecord success');
  }
});
```

## privacyManager.getPermissionUsedRecord

getPermissionUsedRecord(request: PermissionUsedRequest): Promise&lt;PermissionUsedResponse&gt;

获取历史权限使用记录，可用于权限审计或安全监控场景，例如检查某应用在指定时间段内对敏感权限的使用情况。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| request   |  [PermissionUsedRequest](#permissionusedrequest)   | 是   | 查询权限使用记录的请求。              |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise<[PermissionUsedResponse](#permissionusedresponse)> | Promise对象，返回查询的权限使用记录。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The value of flag, begin, or end in request is invalid. |
| 12100007 | The service is abnormal. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let request: privacyManager.PermissionUsedRequest = {
    'tokenId': 1, // 可以通过应用BundleInfo中的ApplicationInfo的accessTokenId字段获取。
    'isRemote': false,
    'deviceId': 'device',
    'bundleName': 'bundle',
    'permissionNames': [],
    'beginTime': 0,
    'endTime': 1,
    'flag': privacyManager.PermissionUsageFlag.FLAG_PERMISSION_USAGE_DETAIL,
};

// 查询历史权限使用记录
privacyManager.getPermissionUsedRecord(request).then((data) => {
  console.info(`getPermissionUsedRecord success, result: ${data}`);
}).catch((err: BusinessError): void => {
  console.error(`getPermissionUsedRecord fail, code: ${err.code}, message: ${err.message}`);
});
```

## privacyManager.getPermissionUsedRecord

getPermissionUsedRecord(request: PermissionUsedRequest, callback: AsyncCallback&lt;PermissionUsedResponse&gt;): void

获取历史权限使用记录，可用于权限审计或安全监控场景，例如检查某应用在指定时间段内对敏感权限的使用情况。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| request | [PermissionUsedRequest](#permissionusedrequest) | 是 | 查询权限使用记录的请求。 |
| callback | AsyncCallback<[PermissionUsedResponse](#permissionusedresponse)> | 是 | 回调函数。当查询记录成功时，err为undefined，data为查询到的权限使用记录；否则err为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The value of flag, begin, or end in request is invalid. |
| 12100007 | The service is abnormal. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let request: privacyManager.PermissionUsedRequest = {
    'tokenId': 1, // 可以通过应用BundleInfo中的ApplicationInfo的accessTokenId字段获取。
    'isRemote': false,
    'deviceId': 'device',
    'bundleName': 'bundle',
    'permissionNames': [],
    'beginTime': 0,
    'endTime': 1,
    'flag': privacyManager.PermissionUsageFlag.FLAG_PERMISSION_USAGE_DETAIL,
};

// 查询历史权限使用记录
privacyManager.getPermissionUsedRecord(request, (err: BusinessError, data: privacyManager.PermissionUsedResponse) => {
  if (err) {
    console.error(`getPermissionUsedRecord fail, code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getPermissionUsedRecord success, result: ${data}`);
  }
});
```

## privacyManager.setPermissionUsedRecordToggleStatus<sup>18+</sup>

setPermissionUsedRecordToggleStatus(status: boolean): Promise&lt;void&gt;

设置是否记录当前用户的权限使用情况。系统应用调用此接口，可以设置当前用户的权限使用记录开关状态。使用Promise异步回调。

status为true时，[addPermissionUsedRecord](#privacymanageraddpermissionusedrecord)接口可以正常添加使用记录；status为false时，[addPermissionUsedRecord](#privacymanageraddpermissionusedrecord)接口不产生权限使用记录，并且删除当前用户的历史记录。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_RECORD_TOGGLE

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型   | 必填 | 说明                                  |
| -------------- | ------ | ---- | ------------------------------------ |
| status        | boolean | 是   | 权限使用记录开关状态。true为开，false为关。|

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_RECORD_TOGGLE". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100007 | The service is abnormal. |
| 12100009 | Common inner error. Possible causes: 1. A database error occurs; 2. Failed to query applications under the user. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 设置权限使用记录开关状态
privacyManager.setPermissionUsedRecordToggleStatus(true).then(() => {
  console.info('setPermissionUsedRecordToggleStatus success');
}).catch((err: BusinessError): void => {
  console.error(`setPermissionUsedRecordToggleStatus fail, code: ${err.code}, message: ${err.message}`);
});
```

## privacyManager.getPermissionUsedRecordToggleStatus<sup>18+</sup>

getPermissionUsedRecordToggleStatus(): Promise&lt;boolean&gt;

系统应用调用此接口，可以获取当前用户的权限使用记录开关状态，例如在权限管理界面展示当前开关设置状态。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象，返回true，表示当前用户的开关状态值为开启。返回false，表示当前用户的开关状态值为关闭。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 12100007 | The service is abnormal. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 查询权限使用记录开关状态
privacyManager.getPermissionUsedRecordToggleStatus().then((status) => {
  console.info('getPermissionUsedRecordToggleStatus success');
  if (status == true) {
    console.info('get status is TRUE');
  } else {
    console.info('get status is FALSE');
  }
}).catch((err: BusinessError): void => {
  console.error(`getPermissionUsedRecordToggleStatus fail, code: ${err.code}, message: ${err.message}`);
});
```

## privacyManager.startUsingPermission

startUsingPermission(tokenID: number, permissionName: Permissions): Promise&lt;void&gt;

系统应用调用此接口，能够向系统上报应用在前后台的权限使用状态。隐私服务将此状态通知所有该权限使用状态变更事件的订阅者（订阅方法参考[on](#privacymanageron)）。使用Promise异步回调。

开始使用权限后，需要在权限使用结束时调用[stopUsingPermission](#privacymanagerstopusingpermission)停止使用权限。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型   | 必填 | 说明                                  |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | 是   | 目标应用的身份标识。可通过应用[BundleInfo](js-apis-bundleManager-bundleInfo.md)中的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md#applicationinfo-1)的accessTokenId字段获取。该参数必须为大于0的整数，传入0时返回错误码12100001。|
| permissionName | [Permissions](../../security/AccessToken/app-permissions.md) | 是   | 需要使用的权限名称。权限名长度不能超过256个字符，传入无效值时返回错误码12100001。|

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the type of the specified tokenID is not of the application type. |
| 12100002 | (Deprecated in 12) The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100004 | The API is used repeatedly with the same input. It means the application specified by the tokenID has been using the specified permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // 可以通过应用BundleInfo中的ApplicationInfo的accessTokenId字段获取。
// 开始使用指定权限
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO').then(() => {
  console.info('startUsingPermission success');
}).catch((err: BusinessError): void => {
  console.error(`startUsingPermission fail, code: ${err.code}, message: ${err.message}`);
});
```

## privacyManager.startUsingPermission<sup>18+</sup>

startUsingPermission(tokenID: number, permissionName: Permissions, pid?: number, usedType?: PermissionUsedType): Promise&lt;void&gt;

系统应用调用此接口，能够向系统上报应用在前后台的权限使用状态。隐私服务将此状态通知所有该权限使用状态变更事件的订阅者（订阅方法参考[on](#privacymanageron)）。使用Promise异步回调。

开始使用权限后，需要在权限使用结束时调用[stopUsingPermission](#privacymanagerstopusingpermission18)停止使用权限。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型   | 必填 | 说明                                  |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | 是   | 目标应用的身份标识。可通过应用[BundleInfo](js-apis-bundleManager-bundleInfo.md)中的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md#applicationinfo-1)的accessTokenId字段获取。该参数必须为大于0的整数，传入0时返回错误码12100001。|
| permissionName | [Permissions](../../security/AccessToken/app-permissions.md) | 是   | 需要使用的权限名称。权限名长度不能超过256个字符，传入无效值时返回错误码12100001。|
| pid            | number | 否   | 调用方的进程pid，用于根据进程生命周期管理权限使用状态。当需要精确控制特定进程的权限使用状态（例如进程退出时自动停止权限使用）时传入此参数。需要与[stopUsingPermission](#privacymanagerstopusingpermission18)传入的pid相同。<br>默认值：-1，表示不根据进程生命周期响应。|
| usedType       | [PermissionUsedType](#permissionusedtype12) | 否 | 敏感权限访问方式。<br>默认值：NORMAL_TYPE。 |

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, the type of the specified tokenID is not of the application type, or usedType is invalid. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100004 | The API is used repeatedly with the same input. It means the application specified by the tokenID has been using the specified permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';

let tokenID: number = rpc.IPCSkeleton.getCallingTokenId(); // 也可以通过应用BundleInfo中的ApplicationInfo的accessTokenId字段获取。
let pid: number = rpc.IPCSkeleton.getCallingPid();
let usedType: privacyManager.PermissionUsedType = privacyManager.PermissionUsedType.PICKER_TYPE;

// 开始使用指定权限
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO').then(() => {
  console.info('startUsingPermission success');
}).catch((err: BusinessError): void => {
  console.error(`startUsingPermission fail, code: ${err.code}, message: ${err.message}`);
});
// with pid
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', pid).then(() => {
  console.info('startUsingPermission success');
}).catch((err: BusinessError): void => {
  console.error(`startUsingPermission fail, code: ${err.code}, message: ${err.message}`);
});
// with usedType
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', -1, usedType).then(() => {
  console.info('startUsingPermission success');
}).catch((err: BusinessError): void => {
  console.error(`startUsingPermission fail, code: ${err.code}, message: ${err.message}`);
});
// with pid and usedType
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', pid, usedType).then(() => {
  console.info('startUsingPermission success');
}).catch((err: BusinessError): void => {
  console.error(`startUsingPermission fail, code: ${err.code}, message: ${err.message}`);
});
```

## privacyManager.startUsingPermission

startUsingPermission(tokenID: number, permissionName: Permissions, pid?: number, usedType?: PermissionUsedType, options?: PermissionUsingOptions): Promise&lt;void&gt;

系统应用调用此接口，能够向系统上报应用在前后台的权限使用状态。隐私服务将此状态通知所有该权限使用状态变更事件的订阅者（订阅方法参考[on](#privacymanageron)）。使用Promise异步回调。

开始使用权限后，需要在权限使用结束时调用[stopUsingPermission](#privacymanagerstopusingpermission-1)停止使用权限。

当传入pid时，pid需要与[stopUsingPermission](#privacymanagerstopusingpermission-1)传入的pid相同，不满足配套关系返回错误码12100004。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名          | 类型   | 必填 | 说明                                  |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | 是   | 目标应用的身份标识。可通过应用[BundleInfo](js-apis-bundleManager-bundleInfo.md)中的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md#applicationinfo-1)的accessTokenId字段获取。该参数必须为大于0的整数，传入0时返回错误码12100001。|
| permissionName | [Permissions](../../security/AccessToken/app-permissions.md) | 是   | 需要使用的权限名称。权限名长度不能超过256个字符，传入无效值时返回错误码12100001。|
| pid            | number | 否   | 调用方的进程pid，用于根据进程生命周期管理权限使用状态。当需要精确控制特定进程的权限使用状态（例如进程退出时自动停止权限使用）时传入此参数。<br>默认值：-1，表示不根据进程生命周期响应。|
| usedType       | [PermissionUsedType](#permissionusedtype12) | 否 | 敏感权限访问方式。<br>默认值：NORMAL_TYPE。 |
| options        | [PermissionUsingOptions](#permissionusingoptions)| 否 | 权限使用可选参数，用于指定扩展身份。当需要标识调用方的扩展身份信息时传入此参数。<br>默认值：enhancedIdentity为空字符串。 |

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, the type of the specified tokenID is not of the application type, usedType is invalid, or the enhancedIdentity in PermissionUsingOptions exceeds 48 characters. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100004 | The API is used repeatedly with the same input. It means the application specified by the tokenID has been using the specified permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';

let tokenID: number = rpc.IPCSkeleton.getCallingTokenId(); // 也可以通过应用BundleInfo中的ApplicationInfo的accessTokenId字段获取。
let pid: number = rpc.IPCSkeleton.getCallingPid();
let usedType: privacyManager.PermissionUsedType = privacyManager.PermissionUsedType.PICKER_TYPE;

// 不带pid和usedType参数
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO').then(() => {
  console.info('startUsingPermission success.');
}).catch((err: BusinessError): void => {
  console.error(`startUsingPermission fail, code: ${err.code}, message: ${err.message}`);
});
// 带pid参数
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', pid).then(() => {
  console.info('startUsingPermission success.');
}).catch((err: BusinessError): void => {
  console.error(`startUsingPermission fail, code: ${err.code}, message: ${err.message}`);
});
// 带usedType参数
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', -1, usedType).then(() => {
  console.info('startUsingPermission success.');
}).catch((err: BusinessError): void => {
  console.error(`startUsingPermission fail, code: ${err.code}, message: ${err.message}`);
});
// 带pid和usedType参数
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', pid, usedType).then(() => {
  console.info('startUsingPermission success.');
}).catch((err: BusinessError): void => {
  console.error(`startUsingPermission fail, code: ${err.code}, message: ${err.message}`);
});
// 带pid、usedType和enhancedIdentity
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', pid, usedType, {enhancedIdentity: 'test'}).then(() => {
  console.info('startUsingPermission success.');
}).catch((err: BusinessError): void => {
  console.error(`startUsingPermission fail, code: ${err.code}, message: ${err.message}`);
});
```

## privacyManager.startUsingPermission

startUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback&lt;void&gt;): void

系统应用调用此接口，能够向系统上报应用在前后台的权限使用状态。隐私服务将此状态通知所有该权限使用状态变更事件的订阅者（订阅方法参考[on](#privacymanageron)）。使用callback异步回调。

开始使用权限后，需要在权限使用结束时调用[stopUsingPermission](#privacymanagerstopusingpermission-2)停止使用权限。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型                  | 必填 | 说明                                  |
| -------------- | --------------------- | ---- | ------------------------------------ |
| tokenID        | number                | 是   | 目标应用的身份标识。可通过应用[BundleInfo](js-apis-bundleManager-bundleInfo.md)中的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md#applicationinfo-1)的accessTokenId字段获取。该参数必须为大于0的整数，传入0时返回错误码12100001。|
| permissionName | [Permissions](../../security/AccessToken/app-permissions.md)                | 是   | 需要使用的权限名称。权限名长度不能超过256个字符，传入无效值时返回错误码12100001。|
| callback       | AsyncCallback&lt;void&gt; | 是   | 回调函数。当开始使用权限成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the type of the specified tokenID is not of the application type. |
| 12100002 | (Deprecated in 12) The specified tokenID does not exist or refer to an application process. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100004 | The API is used repeatedly with the same input. It means the application specified by the tokenID has been using the specified permission. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // 可以通过应用BundleInfo中的ApplicationInfo的accessTokenId字段获取。
// 开始使用指定权限
privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', (err: BusinessError, data: void) => {
  if (err) {
    console.error(`startUsingPermission fail, code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('startUsingPermission success');
  }
});
```

## privacyManager.stopUsingPermission

stopUsingPermission(tokenID: number, permissionName: Permissions): Promise&lt;void&gt;

系统应用调用此接口，标记不再使用指定权限。调用成功后，隐私服务将此状态变化通知所有该权限使用状态变更事件的订阅者。适用于应用完成敏感操作后或退出前台时，通知系统权限使用结束。使用Promise异步回调。

该接口需与[startUsingPermission](#privacymanagerstartusingpermission)配套使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型   | 必填 | 说明                                  |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | 是   | 目标应用的身份标识。可通过应用[BundleInfo](js-apis-bundleManager-bundleInfo.md)中的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md#applicationinfo-1)的accessTokenId字段获取。该参数必须为大于0的整数，传入0时返回错误码12100001。|
| permissionName | [Permissions](../../security/AccessToken/app-permissions.md) | 是   | 需要停止使用的权限名称。权限名长度不能超过256个字符，传入无效值时返回错误码12100001。|

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the type of the specified tokenID is not of the application type. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100004 | The API is not used in pair with 'startUsingPermission'. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // 可以通过应用BundleInfo中的ApplicationInfo的accessTokenId字段获取。
// 停止使用指定权限
privacyManager.stopUsingPermission(tokenID, 'ohos.permission.READ_AUDIO').then(() => {
  console.info('stopUsingPermission success');
}).catch((err: BusinessError): void => {
  console.error(`stopUsingPermission fail, code: ${err.code}, message: ${err.message}`);
});
```

## privacyManager.stopUsingPermission<sup>18+</sup>

stopUsingPermission(tokenID: number, permissionName: Permissions, pid?: number): Promise&lt;void&gt;

系统应用调用此接口，标记不再使用指定权限。调用成功后，隐私服务将此状态变化通知所有该权限使用状态变更事件的订阅者。适用于应用完成敏感操作后或退出前台时，通知系统权限使用结束。使用Promise异步回调。

pid需要与[startUsingPermission](#privacymanagerstartusingpermission18)传入的pid相同。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型   | 必填 | 说明                                  |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | 是   | 目标应用的身份标识。可通过应用[BundleInfo](js-apis-bundleManager-bundleInfo.md)中的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md#applicationinfo-1)的accessTokenId字段获取。该参数必须为大于0的整数，传入0时返回错误码12100001。|
| permissionName | [Permissions](../../security/AccessToken/app-permissions.md) | 是   | 需要停止使用的权限名称。权限名长度不能超过256个字符，传入无效值时返回错误码12100001。|
| pid            | number | 否   | 与[startUsingPermission](#privacymanagerstartusingpermission18)传入的pid相同。不满足配套关系可能导致API调用失败（错误码12100004）。<br>默认值：-1，表示不根据进程生命周期响应。|

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the type of the specified tokenID is not of the application type. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100004 | The API is not used in pair with 'startUsingPermission'. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';

let tokenID: number = rpc.IPCSkeleton.getCallingTokenId(); // 也可以通过应用BundleInfo中的ApplicationInfo的accessTokenId字段获取。
let pid: number = rpc.IPCSkeleton.getCallingPid();

// without pid
privacyManager.stopUsingPermission(tokenID, 'ohos.permission.READ_AUDIO').then(() => {
  console.info('stopUsingPermission success');
}).catch((err: BusinessError): void => {
  console.error(`stopUsingPermission fail, code: ${err.code}, message: ${err.message}`);
});

// with pid
privacyManager.stopUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', pid).then(() => {
  console.info('stopUsingPermission success');
}).catch((err: BusinessError): void => {
  console.error(`stopUsingPermission fail, code: ${err.code}, message: ${err.message}`);
});
```

## privacyManager.stopUsingPermission

stopUsingPermission(tokenID: number, permissionName: Permissions, pid?: number, options?: PermissionUsingOptions): Promise&lt;void&gt;

系统应用调用此接口，标记不再使用指定权限。调用成功后，隐私服务将此状态变化通知所有该权限使用状态变更事件的订阅者。适用于应用完成敏感操作后或退出前台时，通知系统权限使用结束。使用Promise异步回调。

pid需要与[startUsingPermission](#privacymanagerstartusingpermission-1)传入的pid相同。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名          | 类型   | 必填 | 说明                                  |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | 是   | 目标应用的身份标识。可通过应用[BundleInfo](js-apis-bundleManager-bundleInfo.md)中的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md#applicationinfo-1)的accessTokenId字段获取。该参数必须为大于0的整数，传入0时返回错误码12100001。|
| permissionName | [Permissions](../../security/AccessToken/app-permissions.md) | 是   | 需要停止使用的权限名称。权限名长度不能超过256个字符，传入无效值时返回错误码12100001。|
| pid            | number | 否   | 调用方的进程pid，需与[startUsingPermission](#privacymanagerstartusingpermission-1)传入的pid相同。不满足配套关系可能导致API调用失败（错误码12100004）。<br>默认值：-1，表示不根据进程生命周期响应。 |
| options        | [PermissionUsingOptions](#permissionusingoptions)| 否 | 权限使用可选参数，用于指定扩展身份。当需要标识调用方的扩展身份信息时传入此参数。<br>默认值：enhancedIdentity为空字符串。 |

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, the type of the specified tokenID is not of the application type, or the enhancedIdentity in PermissionUsingOptions exceeds 48 characters. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100004 | The API is not used in pair with 'startUsingPermission'. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';

let tokenID: number = rpc.IPCSkeleton.getCallingTokenId(); // 也可以通过应用BundleInfo中的ApplicationInfo的accessTokenId字段获取。
let pid: number = rpc.IPCSkeleton.getCallingPid();

// 不带pid参数
privacyManager.stopUsingPermission(tokenID, 'ohos.permission.READ_AUDIO').then(() => {
  console.info('stopUsingPermission success');
}).catch((err: BusinessError): void => {
  console.error(`stopUsingPermission fail, code: ${err.code}, message: ${err.message}`);
});

// 带pid参数
privacyManager.stopUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', pid).then(() => {
  console.info('stopUsingPermission success');
}).catch((err: BusinessError): void => {
  console.error(`stopUsingPermission fail, code: ${err.code}, message: ${err.message}`);
});

// 带扩展身份标识
privacyManager.stopUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', pid, {enhancedIdentity: 'test'}).then(() => {
  console.info('stopUsingPermission success');
}).catch((err: BusinessError): void => {
  console.error(`stopUsingPermission fail, code: ${err.code}, message: ${err.message}`);
});
```

## privacyManager.stopUsingPermission

stopUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback&lt;void&gt;): void

系统应用调用此接口，标记不再使用指定权限。调用成功后，隐私服务将此状态变化通知所有该权限使用状态变更事件的订阅者。适用于应用完成敏感操作后或退出前台时，通知系统权限使用结束。使用callback异步回调。

该接口需与[startUsingPermission](#privacymanagerstartusingpermission-2)配套使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型                  | 必填 | 说明                                  |
| -------------- | --------------------- | ---- | ------------------------------------ |
| tokenID        | number                | 是   | 目标应用的身份标识。可通过应用[BundleInfo](js-apis-bundleManager-bundleInfo.md)中的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md#applicationinfo-1)的accessTokenId字段获取。该参数必须为大于0的整数，传入0时返回错误码12100001。|
| permissionName | [Permissions](../../security/AccessToken/app-permissions.md)                | 是   | 需要停止使用的权限名称。权限名长度不能超过256个字符，传入无效值时返回错误码12100001。|
| callback       | AsyncCallback&lt;void&gt; | 是   | 回调函数。当停止使用权限成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The tokenID is 0, the permissionName exceeds 256 characters, or the type of the specified tokenID is not of the application type. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100004 | The API is not used in pair with 'startUsingPermission'. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenID: number = 0; // 可以通过应用BundleInfo中的ApplicationInfo的accessTokenId字段获取。
// 停止使用指定权限
privacyManager.stopUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', (err: BusinessError, data: void) => {
  if (err) {
    console.error(`stopUsingPermission fail, code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('stopUsingPermission success');
  }
});
```

## privacyManager.checkPermissionInUse

checkPermissionInUse(permissionName: Permissions): boolean

查询指定敏感权限是否正在被使用，可用于权限管理界面展示权限实时使用状态场景。判断依据为当前是否存在通过[startUsingPermission](#privacymanagerstartusingpermission)标记开始使用且尚未通过[stopUsingPermission](#privacymanagerstopusingpermission)标记停止使用的活跃调用。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名          | 类型   | 必填 | 说明                                  |
| -------------- | ------ | ---- | ------------------------------------ |
| permissionName | [Permissions](../../security/AccessToken/app-permissions.md)                | 是   | 需要查询的权限名称。权限名不能为空，且长度不能超过256个字符，传入无效值时返回错误码12100001。|

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| boolean | 指定的敏感权限是否正在被使用。true：指定的敏感权限正在被使用；false：指定的敏感权限未被使用。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system application. Interface caller is not a system application. |
| 12100001 | Invalid parameter. The permissionName is empty or exceeds 256 characters. |
| 12100003 | The specified permission does not exist or is not a user_grant permission. |
| 12100007 | The service is abnormal. |

**示例：**

```ts
import { privacyManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 查询指定权限是否正在被使用
  let isPermissionInUse = privacyManager.checkPermissionInUse('ohos.permission.CAMERA');
  console.info('checkPermissionInUse success, result: ' + isPermissionInUse);
} catch (err) {
  let error = err as BusinessError;
  console.error(`checkPermissionInUse fail, code: ${error.code}, message: ${error.message}`);
}
```

## privacyManager.on

on(type: 'activeStateChange', permissionList: Array&lt;Permissions&gt;, callback: Callback&lt;ActiveChangeResponse&gt;): void

订阅指定权限列表的权限使用状态变更事件。权限使用状态变更由[startUsingPermission](#privacymanagerstartusingpermission)和[stopUsingPermission](#privacymanagerstopusingpermission)调用触发。订阅成功后，当权限使用状态变更时，回调函数会被触发，返回[ActiveChangeResponse](#activechangeresponse)对象，包含权限使用状态变化的详情。使用callback异步回调。

允许相同permissionList订阅多个回调函数。

不允许使用有交集的两个permissionList分别订阅同一个回调函数。即如果两个permissionList包含相同的权限名，则不能使用同一个回调函数进行订阅。

该接口通常与[off](#privacymanageroff)配套使用，当不再需要监听时应调用off取消订阅。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名             | 类型                   | 必填 | 说明                                                          |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | 是   | 订阅事件类型，固定为'activeStateChange'，权限使用状态变更事件。   |
| permissionList | Array&lt;[Permissions](../../security/AccessToken/app-permissions.md)&gt;   | 是   | 订阅的权限名列表，数组长度不能超过1024。为空时表示订阅所有的权限使用状态变化。传入无效值时返回错误码12100001。|
| callback | Callback&lt;[ActiveChangeResponse](#activechangeresponse)&gt; | 是 | 回调函数，返回订阅指定权限使用状态变更事件的对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The permissionList exceeds the size limit, or the permissionNames in the list are all invalid. |
| 12100004 | The API is used repeatedly with the same input. |
| 12100005 | The registration time has exceeded the limit. |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager, Permissions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let permissionList: Array<Permissions> = [];
try {
    // 订阅权限使用状态变更事件
    privacyManager.on('activeStateChange', permissionList, (data: privacyManager.ActiveChangeResponse) => {
        console.debug(`receive permission state change, data: ${data}`);
    });
} catch (err) {
    let error = err as BusinessError;
    console.error(`Catch errcode: ${error.code}, message: ${error.message}`);
}
```

## privacyManager.off

off(type: 'activeStateChange', permissionList: Array&lt;Permissions&gt;, callback?: Callback&lt;ActiveChangeResponse&gt;): void

取消订阅指定权限列表的权限使用状态变更事件。取消订阅成功后，将不再接收指定权限列表的状态变更通知。

取消订阅时，若不传入回调函数，则批量删除permissionList下的所有回调函数。

该接口通常与[on](#privacymanageron)配套使用，用于取消通过on创建的监听关系。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名             | 类型                   | 必填 | 说明                                                          |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | 是   | 取消订阅事件类型，固定为'activeStateChange'，权限使用状态变更事件。   |
| permissionList | Array&lt;[Permissions](../../security/AccessToken/app-permissions.md)&gt;   | 是   | 取消订阅的权限名列表，为空时表示取消订阅所有的权限状态变化，必须与[on](#privacymanageron)的输入一致。|
| callback | Callback&lt;[ActiveChangeResponse](#activechangeresponse)&gt; | 否 | 回调函数，返回取消订阅指定tokenId与指定权限名状态变更事件的对象。需与[on](#privacymanageron)传入的callback一致；不传入此参数时，将批量删除permissionList下的所有回调函数。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12100001 | Invalid parameter. The permissionList is not in the listening list. |
| 12100004 | The API is not used in pair with "on". |
| 12100007 | The service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```ts
import { privacyManager, Permissions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let permissionList: Array<Permissions> = [];
try {
    // 取消订阅权限使用状态变更事件
    privacyManager.off('activeStateChange', permissionList);
} catch (err) {
    let error = err as BusinessError;
    console.error(`Catch errcode: ${error.code}, message: ${error.message}`);
}
```

## privacyManager.getPermissionUsedTypeInfos<sup>12+</sup>

getPermissionUsedTypeInfos(tokenId?: number | null, permissionName?: Permissions): Promise&lt;Array&lt;PermissionUsedTypeInfo&gt;&gt;

查询设备上指定应用访问敏感权限时的信息（包括敏感权限名称、敏感权限访问方式）。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名             | 类型                   | 必填 | 说明                                                          |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| tokenId            | number \| null                | 否   | 访问敏感权限的应用身份标识。可通过应用[BundleInfo](js-apis-bundleManager-bundleInfo.md)中的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md#applicationinfo-1)的accessTokenId字段获取。当需要查询特定应用的敏感权限访问类型信息时传入具体的tokenId；为0或null时表示查询所有应用的敏感权限访问类型信息。从API version 20开始，新增支持null类型。<br>默认值：0。   |
| permissionName     | [Permissions](../../security/AccessToken/app-permissions.md)           | 否   | 被访问的敏感权限名称。当需要查询特定敏感权限的访问类型信息时传入具体的权限名；为空时表示查询所有敏感权限的访问类型信息。权限名长度不能超过256个字符，传入无效值时返回错误码12100001。<br>默认值：空。   |

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;Array&lt;[PermissionUsedTypeInfo](#permissionusedtypeinfo12)&gt;&gt; | Promise对象，返回权限访问类型信息列表。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[访问控制错误码](errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. Interface caller does not have permission "ohos.permission.PERMISSION_USED_STATS". |
| 202 | Not system app. Interface caller is not a system app. |
| 12100001 | Invalid parameter. PermissionName exceeds 256 characters. |
| 12100002 | The input tokenId does not exist. |
| 12100003 | The input permissionName does not exist. |
| 12100009 | Common inner error. A database error occurs. |

**示例：**

```ts
import { privacyManager, Permissions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tokenId: number = 0; // 可以通过应用BundleInfo中的ApplicationInfo的accessTokenId字段获取。
let permissionName: Permissions = 'ohos.permission.CAMERA';
// without any param
privacyManager.getPermissionUsedTypeInfos().then((data: Array<privacyManager.PermissionUsedTypeInfo>) => {
  console.info('getPermissionUsedTypeInfos success, result: ' + JSON.stringify(data));
}).catch((err: BusinessError): void => {
  console.error(`getPermissionUsedTypeInfos fail, code: ${err.code}, message: ${err.message}`);
});
// only tokenId
privacyManager.getPermissionUsedTypeInfos(tokenId).then((data: Array<privacyManager.PermissionUsedTypeInfo>) => {
  console.info('getPermissionUsedTypeInfos success, result: ' + JSON.stringify(data));
}).catch((err: BusinessError): void => {
  console.error(`getPermissionUsedTypeInfos fail, code: ${err.code}, message: ${err.message}`);
});
// only permissionName
privacyManager.getPermissionUsedTypeInfos(null, permissionName).then((data: Array<privacyManager.PermissionUsedTypeInfo>) => {
  console.info('getPermissionUsedTypeInfos success, result: ' + JSON.stringify(data));
}).catch((err: BusinessError): void => {
  console.error(`getPermissionUsedTypeInfos fail, code: ${err.code}, message: ${err.message}`);
});
// tokenId and permissionName
privacyManager.getPermissionUsedTypeInfos(tokenId, permissionName).then((data: Array<privacyManager.PermissionUsedTypeInfo>) => {
  console.info('getPermissionUsedTypeInfos success, result: ' + JSON.stringify(data));
}).catch((err: BusinessError): void => {
  console.error(`getPermissionUsedTypeInfos fail, code: ${err.code}, message: ${err.message}`);
});
```

## PermissionUsageFlag

表示使用记录的查询方式的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

| 名称                    | 值 | 说明                   |
| ----------------------- | ------ | ---------------------- |
| FLAG_PERMISSION_USAGE_SUMMARY             | 0    | 表示查询总览数据。 |
| FLAG_PERMISSION_USAGE_DETAIL         | 1    | 表示查询详细数据。         |

## PermissionUsedRequest

表示使用记录的查询请求。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

| 名称       | 类型             | 只读 | 可选 | 说明                                       |
| -------- | -------------- | ---- | ---- | ---------------------------------------- |
| tokenId  | number         | 否    | 是    | 目标应用的身份标识。可通过应用[BundleInfo](js-apis-bundleManager-bundleInfo.md)中的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md#applicationinfo-1)的accessTokenId字段获取。<br/>默认值：0，查询所有应用。         |
| isRemote | boolean         | 否    | 是    | 指定是否查询远端设备。false表示查询本端设备的权限使用记录，true表示查询远端设备记录。<br>默认值：false。 |
| deviceId  | string         | 否    | 是    | 目标应用所在设备的ID。<br>默认值：本端设备ID。 |
| bundleName | string         | 否    | 是    | 目标应用的包名。<br>默认值：查询所有应用。 |
| permissionNames  | Array&lt;[Permissions](../../security/AccessToken/app-permissions.md)&gt;         | 否    | 是    | 需要查询的权限集合。<br>默认值：查询所有权限的使用记录。 |
| beginTime | number         | 否    | 是    | 查询的起始时间，单位：ms，取值范围为[0, +∞)。<br>默认值：0，表示不限制起始时间。 |
| endTime | number         | 否    | 是    | 查询的终止时间，单位：ms，取值范围为[0, +∞)。应不早于beginTime，否则返回错误码12100001。<br>默认值：0，表示不限制终止时间。 |
| flag | [PermissionUsageFlag](#permissionusageflag)         | 否    | 否    | 指定查询方式。设置为FLAG_PERMISSION_USAGE_SUMMARY时返回汇总信息；设置为FLAG_PERMISSION_USAGE_DETAIL时返回明细记录。 |

## PermissionUsedResponse

表示所有应用或设备的访问记录。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

| 名称       | 类型             | 只读 | 可选 | 说明                                       |
| --------- | -------------- | ---- | ---- | ---------------------------------------- |
| beginTime | number         | 否    | 否    | 查询记录的起始时间，单位：ms。 |
| endTime   | number         | 否    | 否    | 查询记录的终止时间，单位：ms。 |
| bundleRecords  | Array&lt;[BundleUsedRecord](#bundleusedrecord)&gt;         | 否    | 否    | 每个元素表示一个应用维度下的权限访问记录，开发者可进一步遍历permissionRecords获取具体权限使用详情。                                 |

## BundleUsedRecord

某个应用或设备的访问记录。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

| 名称       | 类型             | 只读 | 可选 | 说明                                       |
| -------- | -------------- | ---- | ---- | ---------------------------------------- |
| tokenId  | number         | 否    | 否    | 使用权限的应用身份标识。分布式场景下该字段无效，需结合deviceId和deviceName识别来源设备。                                 |
| isRemote | boolean         | 否    | 否    | 是否是分布式场景的访问记录。false表示本端应用记录，true表示远端设备上的权限使用记录。 |
| deviceId  | string         | 否    | 否    | 使用权限的应用所在设备ID。主要在分布式场景下用于识别远端设备来源；本端场景下通常可忽略该字段。                                 |
| deviceName<sup>24+</sup>  | string         | 否    | 是    | 使用权限的应用所在设备名称，仅用于分布式场景。可用于在界面中展示更易理解的设备标识。<br>默认值：空字符串。                                 |
| bundleName | string         | 否    | 否    | 使用权限的应用包名。在本端场景下可用于直接定位目标应用；分布式场景下该字段无效。 |
| permissionRecords  | Array&lt;[PermissionUsedRecord](#permissionusedrecord)&gt;         | 否    | 否    | 当前应用或设备下的权限使用记录集合。每个元素对应一个具体权限，可进一步查看访问次数、拒绝次数、最后访问时间及明细记录。                                 |

## PermissionUsedRecord

某个权限的访问记录。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

| 名称       | 类型             | 只读 | 可选 | 说明                                       |
| -------- | -------------- | ---- | ---- | ---------------------------------------- |
| permissionName  | [Permissions](../../security/AccessToken/app-permissions.md)         | 否    | 否    | 权限名，用于标识当前统计记录对应的敏感权限。                        |
| accessCount | number         | 否    | 否    | 该权限访问总次数，表示在查询时间窗口内成功使用该权限的累计次数。 |
| rejectCount | number         | 否    | 否    | 该权限拒绝总次数，表示在查询时间窗口内权限访问失败或被拒绝的累计次数。 |
| lastAccessTime | number         | 否    | 否    | 最后一次访问时间，单位：ms。 |
| lastRejectTime | number         | 否    | 否    | 最后一次拒绝时间，单位：ms。 |
| lastAccessDuration | number         | 否    | 否    | 最后一次访问时长，单位：ms。 |
| accessRecords  | Array&lt;[UsedRecordDetail](#usedrecorddetail)&gt;         | 否    | 否    | 访问记录集合，仅当flag为FLAG_PERMISSION_USAGE_DETAIL时生效。<br>默认值：查询最近10条成功访问记录。                                 |
| rejectRecords  | Array&lt;[UsedRecordDetail](#usedrecorddetail)&gt;         | 否    | 否    | 拒绝记录集合，仅当flag为FLAG_PERMISSION_USAGE_DETAIL时生效。<br>默认值：查询最近10条失败或拒绝记录。                                 |
| enhancedIdentity| string | 否 | 是 | 扩展身份，长度不超过48个字符。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## UsedRecordDetail

单次访问记录详情。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

| 名称       | 类型             | 只读 | 可选 | 说明                                       |
| -------- | -------------- | ---- | ---- | ---------------------------------------- |
| status  | number         | 否    | 否    | 访问状态。0表示停止使用，1表示前台使用，2表示后台使用。 |
| lockScreenStatus<sup>11+</sup>  | number         | 否    | 是    | 访问时的锁屏状态。<br> - 1，表示非锁屏场景使用权限。<br> - 2，表示锁屏场景使用权限。<br>默认值：1。 |
| timestamp | number         | 否    | 否    | 访问时的时间戳，单位：ms。 |
| accessDuration  | number         | 否    | 否    | 访问时长，单位：ms，取值范围为[0, +∞)。 |
| count<sup>11+</sup> | number | 否 | 是    | 访问次数。在accessRecords中表示成功访问次数，在rejectRecords中表示失败或拒绝次数。<br>默认值：0。 |
| usedType<sup>12+</sup> | [PermissionUsedType](#permissionusedtype12) | 否 | 是    | 敏感权限访问方式。<br>默认值：NORMAL_TYPE。 |

## PermissionActiveStatus

表示权限使用状态变化类型的枚举。用于描述权限使用状态的变更类型，在订阅权限使用状态变更事件（通过[on('activeStateChange')](#privacymanageron)）的回调中返回，帮助系统应用感知权限从未使用到前台使用、后台使用的状态切换。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

| 名称                      | 值     | 说明              |
| ------------------------- | ------ | ---------------- |
| PERM_INACTIVE             | 0      | 表示未使用权限。   |
| PERM_ACTIVE_IN_FOREGROUND | 1      | 表示前台使用权限。 |
| PERM_ACTIVE_IN_BACKGROUND | 2      | 表示后台使用权限。 |

## ActiveChangeResponse

表示某次权限使用状态变化的详情。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

| 名称           | 类型                    | 只读 | 可选 | 说明                   |
| -------------- | ---------------------- | ---- | ---- | --------------------- |
| callingTokenId<sup>18+</sup> | number   | 否   | 是   | 接口调用方的应用身份标识，当activeStatus为INACTIVE时该值无效。<br>默认值：0。 |
| tokenId        | number                 | 否   | 否   | 被订阅的应用身份标识。    |
| permissionName | [Permissions](../../security/AccessToken/app-permissions.md)            | 否   | 否   | 权限使用状态发生变化的权限名。 |
| deviceId       | string                 | 否   | 否   | 权限使用状态发生变化时所在设备的ID。                 |
| activeStatus   | [PermissionActiveStatus](#permissionactivestatus) | 否   | 否   | 权限使用状态变化类型。        |
| usedType<sup>18+</sup> | [PermissionUsedType](#permissionusedtype12) | 否   | 是   | 敏感权限使用类型，当activeStatus为INACTIVE时该值无效。<br>默认值：NORMAL_TYPE。 |
| enhancedIdentity | string | 否 | 是 | 扩展身份，用于标识调用方的附加身份信息。当需要区分同一应用下不同调用来源的权限使用记录时返回此字段。长度不超过48个字符。<br>默认值：空字符串。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## PermissionUsedType<sup>12+</sup>

表示通过何种方式使用敏感权限的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

| 名称                    | 值 | 说明              |
| ----------------------- | -- | ---------------- |
| NORMAL_TYPE             | 0  | 表示通过弹窗授权或设置授权来使用敏感权限。   |
| PICKER_TYPE             | 1  | 表示通过某个PICKER服务来使用敏感权限，但此方式不会授予权限。 |
| SECURITY_COMPONENT_TYPE | 2  | 表示通过安全控件授权的方式来使用敏感权限。安全控件是系统提供的授权控件，用户点击后应用可临时获取对应权限。 |

## PermissionUsedTypeInfo<sup>12+</sup>

表示某次权限使用类型的详情。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

| 名称           | 类型                    | 只读 | 可选 | 说明                   |
| -------------- | ---------------------- | ---- | ---- | --------------------- |
| tokenId        | number                 | 否   | 否   | 访问敏感权限的应用身份标识。 |
| permissionName | [Permissions](../../security/AccessToken/app-permissions.md)            | 否   | 否   | 被访问的敏感权限名称。 |
| usedType | [PermissionUsedType](#permissionusedtype12) | 否 | 否    | 敏感权限使用类型。 |

## AddPermissionUsedRecordOptions<sup>12+</sup>

添加权限使用记录可选参数集。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

| 名称           | 类型                    | 只读 | 可选 | 说明                   |
| -------------- | ---------------------- | ---- | ---- | --------------------- |
| usedType | [PermissionUsedType](#permissionusedtype12) | 否 | 是    | 敏感权限使用类型。<br>默认值：NORMAL_TYPE。 |
| enhancedIdentity | string | 否 | 是 | 扩展身份，用于标识调用方的附加身份信息。当需要区分同一应用下不同调用来源的权限使用记录时传入此字段。长度不超过48个字符，调用[addPermissionUsedRecord](#privacymanageraddpermissionusedrecord)时传入超长值会返回错误码12100001。<br>默认值：空字符串。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## PermissionUsingOptions

权限使用可选参数集。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称           | 类型                    | 只读 | 可选 | 说明                   |
| -------------- | ---------------------- | ---- | ---- | --------------------- |
| enhancedIdentity | string | 否 | 是 | 扩展身份，用于标识调用方的附加身份信息。当需要区分同一应用下不同调用来源的权限使用记录时传入此字段。长度不超过48个字符，调用[startUsingPermission](#privacymanagerstartusingpermission)或[stopUsingPermission](#privacymanagerstopusingpermission)时传入超长值会返回错误码12100001。<br>默认值：空字符串。|
