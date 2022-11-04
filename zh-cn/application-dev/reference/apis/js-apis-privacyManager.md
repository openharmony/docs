# 隐私管理

本模块主要提供权限使用记录等隐私管理接口。

> **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 导入模块

```js
import privacyManager from '@ohos.privacyManager';
```


## privacyManager.addPermissionUsedRecord

addPermissionUsedRecord(tokenID: number, permissionName: Permissions, successCount: number, failCount: number): Promise&lt;void&gt;

受应用权限保护的应用在被其他服务、应用调用时，可以使用该接口增加一条权限使用记录。使用Promise异步回调。
权限使用记录包括：调用方的应用身份标识、使用的应用权限名称，和其访问本应用成功、失败的次数。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 调用方的应用身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得。              |
| permissionName | Permissions | 是   | 应用权限名称。 |
| successCount | number | 是   | 访问成功的次数。 |
| failCount | number | 是   | 访问失败的次数。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。
| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | Parameter invalid. |
| 12100002 | TokenId does not exist. |
| 12100003 | Permission does not exist. |

**示例：**

```js
import privacyManager from '@ohos.privacyManager';

let tokenID = 0; // 可以通过getApplicationInfo获取accessTokenId
try {
    privacyManager.addPermissionUsedRecord(tokenID, "ohos.permission.PERMISSION_USED_STATS", 1, 0).then(() => {
        console.log('addPermissionUsedRecord success');
    }).catch((err) => {
        console.log(`addPermissionUsedRecord fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
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
| tokenID   |  number   | 是   | 调用方的应用身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得。              |
| permissionName | Permissions | 是   | 应用权限名称。 |
| successCount | number | 是   | 访问成功的次数。 |
| failCount | number | 是   | 访问失败的次数。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当添加使用记录成功时，err为undefine；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。
| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | Parameter invalid. |
| 12100002 | TokenId does not exist. |
| 12100003 | Permission does not exist. |

**示例：**

```js
import privacyManager from '@ohos.privacyManager';

let tokenID = 0; // 可以通过getApplicationInfo获取accessTokenId
try {
    privacyManager.addPermissionUsedRecord(tokenID, "ohos.permission.PERMISSION_USED_STATS", 1, 0, (err, data) => {
        if (err) {
            console.log(`addPermissionUsedRecord fail, err->${JSON.stringify(err)}`);
        } else {
            console.log('addPermissionUsedRecord success');
        }
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.getPermissionUsedRecords

getPermissionUsedRecords(request: PermissionUsedRequest): Promise&lt;PermissionUsedResponse&gt;

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

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。
| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | Parameter invalid. |
| 12100002 | TokenId does not exist. |
| 12100003 | Permission does not exist. |

**示例：**

```js
import privacyManager from '@ohos.privacyManager';

let request = {
    "tokenId": 1,
    "isRemote": false,
    "deviceId": "device",
    "bundleName": "bundle",
    "permissionNames": [],
    "beginTime": 0,
    "endTime": 1,
    "flag":privacyManager.PermissionUsageFlag.FLAG_PERMISSION_USAGE_DETAIL,
};
try {
    privacyManager.getPermissionUsedRecords(request).then((data) => {
        console.log(`getPermissionUsedRecords success, data->${JSON.stringify(data)}`);
    }).catch((err) => {
        console.log(`getPermissionUsedRecords fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.getPermissionUsedRecords

getPermissionUsedRecords(request: PermissionUsedRequest, callback: AsyncCallback&lt;PermissionUsedResponse&gt;): void

获取历史权限使用记录。使用callback异步回调。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| request | [PermissionUsedRequest](#permissionusedrequest) | 是 | 查询权限使用记录的请求。 |
| callback | AsyncCallback<[PermissionUsedResponse](#permissionusedresponse)> | 是 | 回调函数。当查询记录成功时，err为undefine，data为查询到的权限使用记录；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。
| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | Parameter invalid. |
| 12100002 | TokenId does not exist. |
| 12100003 | Permission does not exist. |

**示例：**

```js
import privacyManager from '@ohos.privacyManager';

let request = {
    "tokenId": 1,
    "isRemote": false,
    "deviceId": "device",
    "bundleName": "bundle",
    "permissionNames": [],
    "beginTime": 0,
    "endTime": 1,
    "flag":privacyManager.PermissionUsageFlag.FLAG_PERMISSION_USAGE_DETAIL,
};
try {
    privacyManager.getPermissionUsedRecords(request, (err, data) => {
        if (err) {
            console.log(`getPermissionUsedRecords fail, err->${JSON.stringify(err)}`);
        } else {
            console.log(`getPermissionUsedRecords success, data->${JSON.stringify(data)}`);
        }
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.startUsingPermission

startUsingPermission(tokenID: number, permissionName: Permissions): Promise&lt;void&gt;

应用开始使用某项权限，可监听应用在前后台使用权限，并将使用权限的记录落盘，由系统服务调用。使用Promise异步回调。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型   | 必填 | 说明                                  |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | 是   | 调用方的应用身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得。 |
| permissionName | Permissions | 是   | 需要使用的权限名。                     |

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。|

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。
| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | Parameter invalid. |
| 12100002 | TokenId does not exist. |
| 12100003 | Permission does not exist. |
| 12100004 | The interface is not used together. |

**示例：**

```js
import privacyManager from '@ohos.privacyManager';

let tokenID = 0; // 可以通过getApplicationInfo获取accessTokenId
try {
    privacyManager.startUsingPermission(tokenID, "ohos.permission.PERMISSION_USED_STATS").then(() => {
        console.log('startUsingPermission success');
    }).catch((err) => {
        console.log(`startUsingPermission fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.startUsingPermission

startUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback&lt;void&gt;): void

应用开始使用某项权限，可监听应用在前后台使用权限，并将使用权限的记录落盘，由系统服务调用。使用callback异步回调。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型                  | 必填 | 说明                                  |
| -------------- | --------------------- | ---- | ------------------------------------ |
| tokenID        | number                | 是   | 调用方的应用身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得。 |
| permissionName | Permissions                | 是   | 需要使用的权限名。                     |
| callback       | AsyncCallback&lt;void&gt; | 是   | 回调函数。当开始使用权限成功时，err为undefine；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。
| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | Parameter invalid. |
| 12100002 | TokenId does not exist. |
| 12100003 | Permission does not exist. |
| 12100004 | The interface is not used together. |

**示例：**

```js
import privacyManager from '@ohos.privacyManager';

let tokenID = 0; // 可以通过getApplicationInfo获取accessTokenId
try {
    privacyManager.startUsingPermission(tokenID, "ohos.permission.PERMISSION_USED_STATS", (err, data) => {
        if (err) {
            console.log(`startUsingPermission fail, err->${JSON.stringify(err)}`);
        } else {
            console.log('startUsingPermission success');
        }
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.stopUsingPermission

stopUsingPermission(tokenID: number, permissionName: string): Promise&lt;void&gt;

应用停止使用某项权限，与Start对应，由系统服务调用。使用Promise异步回调。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型   | 必填 | 说明                                  |
| -------------- | ------ | ---- | ------------------------------------ |
| tokenID        | number | 是   | 调用方的应用身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得。 |
| permissionName | Permissions | 是   | 需要使用的权限名。                     |

**返回值：**

| 类型          | 说明                                    |
| ------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。|

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。
| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | Parameter invalid. |
| 12100002 | TokenId does not exist. |
| 12100003 | Permission does not exist. |
| 12100004 | The interface is not used together. |

**示例：**

```js
import privacyManager from '@ohos.privacyManager';

let tokenID = 0; // 可以通过getApplicationInfo获取accessTokenId
try {
    privacyManager.stopUsingPermission(tokenID, "ohos.permission.PERMISSION_USED_STATS").then(() => {
        console.log('stopUsingPermission success');
    }).catch((err) => {
        console.log(`stopUsingPermission fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.stopUsingPermission

stopUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback&lt;void&gt;): void

应用停止使用某项权限，与Start对应，由系统服务调用。使用callback异步回调。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名          | 类型                  | 必填 | 说明                                  |
| -------------- | --------------------- | ---- | ------------------------------------ |
| tokenID        | number                | 是   | 调用方的应用身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得。 |
| permissionName | Permissions                | 是   | 需要使用的权限名。                      |
| callback       | AsyncCallback&lt;void&gt; | 是   | 回调函数。当停止使用权限成功时，err为undefine；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。
| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | Parameter invalid. |
| 12100002 | TokenId does not exist. |
| 12100003 | Permission does not exist. |
| 12100004 | The interface is not used together. |

**示例：**

```js
import privacyManager from '@ohos.privacyManager';

let tokenID = 0; // 可以通过getApplicationInfo获取accessTokenId
try {
    privacyManager.stopUsingPermission(tokenID, "ohos.permission.PERMISSION_USED_STATS", (err, data) => {
        if (err) {
            console.log(`stopUsingPermission fail, err->${JSON.stringify(err)}`);
        } else {
            console.log('stopUsingPermission success');
        }
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.on

on(type: 'activeStateChange', permissionNameList: Array&lt;Permissions&gt;, callback: Callback&lt;ActiveChangeResponse&gt;): void

订阅指定权限列表的权限使用状态变更事件。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名             | 类型                   | 必填 | 说明                                                          |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | 是   | 订阅事件类型，固定为'activeStateChange'，权限使用状态变更事件。   |
| permissionNameList | Array&lt;Permissions&gt;   | 否   | 订阅的权限名列表，为空时表示订阅所有的权限使用状态变化。           |
| callback | Callback&lt;[ActiveChangeResponse](#activechangeresponse)&gt; | 是 | 订阅指定权限使用状态变更事件的回调。 |

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。
| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | Parameter invalid. |
| 12100004 | The interface is not used together. |
| 12100005 | The number of listeners exceeds the limit. |

**示例：**

```js
import privacyManager from '@ohos.privacyManager';

let permissionNameList: Array<Permissions> = [];
try {
    atManager.on('activeStateChange', permissionNameList, (data) => {
        console.debug("receive permission state change, data:" + JSON.stringify(data));
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## privacyManager.off

off(type: 'activeStateChange', permissionNameList: Array&lt;Permissions&gt;, callback?: Callback&lt;ActiveChangeResponse&gt;): void;

取消订阅指定权限列表的权限使用状态变更事件。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名             | 类型                   | 必填 | 说明                                                          |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | 是   | 订阅事件类型，固定为'activeStateChange'，权限使用状态变更事件。   |
| permissionNameList | Array&lt;Permissions&gt;   | 否   | 订阅的权限名列表，为空时表示订阅所有的权限状态变化，必须与on的输入一致。 |
| callback | Callback&lt;[ActiveChangeResponse](#activechangeresponse)&gt; | 否 | 取消订阅指定tokenId与指定权限名状态变更事件的回调。|

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。
| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | Parameter invalid. |
| 12100004 | The interface is not used together. |

**示例：**

```js
import privacyManager from '@ohos.privacyManager';

let permissionNameList: Array<Permissions> = [];
try {
    privacyManager.off('activeStateChange', permissionNameList);
}catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## PermissionUsageFlag

使用记录的查询方式的枚举。

**系统能力：** SystemCapability.Security.AccessToken

| 名称                    | 值 | 描述                   |
| ----------------------- | ------ | ---------------------- |
| FLAG_PERMISSION_USAGE_SUMMARY             | 0    | 表示查询总览数据。 |
| FLAG_PERMISSION_USAGE_DETAIL         | 1    | 表示查询详细数据。         |

## PermissionUsedRequest

表示使用记录的查询请求。

**系统能力：** SystemCapability.Security.AccessToken

| 名称       | 类型             | 必填   | 说明                                       |
| -------- | -------------- | ---- | ---------------------------------------- |
| tokenId  | number         | 否    | 目标应用的身份标识。                                 |
| isRemote | boolean         | 否    | 默认值false。 |
| deviceId  | string         | 否    | 目标应用所在设备的ID。                                 |
| bundleName | string         | 否    | 目标应用的包名。 |
| permissionNames  | Array&lt;Permissions&gt;         | 否    | 需要查询的权限集合。                                 |
| beginTime | number         | 否    | 查询的起始时间，单位：ms，默认值0，不设定起始时间。 |
| endTime | number         | 否    | 查询的终止时间，单位：ms，默认值0，不设定终止时间。 |
| flag | [PermissionUsageFlag](#permissionusageflag)         | 是    | 查询方式，默认值FLAG_PERMISSION_USAGE_SUMMARY。 |

## PermissionUsedResponse

表示所有应用的访问记录。

**系统能力：** SystemCapability.Security.AccessToken

| 名称       | 类型             | 必填   | 说明                                       |
| -------- | -------------- | ---- | ---------------------------------------- |
| beginTime | number         | 否    | 查询记录的起始时间，单位：ms。 |
| endTime | number         | 否    | 查询记录的终止时间，单位：ms。 |
| bundleRecords  | Array&lt;[BundleUsedRecord](#bundleusedrecord)&gt;         | 否    | 应用的权限使用记录集合。                                 |

## BundleUsedRecord

某个应用的访问记录。

**系统能力：** SystemCapability.Security.AccessToken

| 名称       | 类型             | 必填   | 说明                                       |
| -------- | -------------- | ---- | ---------------------------------------- |
| tokenId  | number         | 否    | 目标应用的身份标识。                                 |
| isRemote | boolean         | 否    | 默认值false。 |
| deviceId  | string         | 否    | 目标应用所在设备的ID。                                 |
| bundleName | string         | 否    | 目标应用的包名。 |
| permissionRecords  | Array&lt;[PermissionUsedRecord](#permissionusedrecord)&gt;         | 否    | 每个应用的权限使用记录集合。                                 |

## PermissionUsedRecord

某个权限的访问记录。

**系统能力：** SystemCapability.Security.AccessToken

| 名称       | 类型             | 必填   | 说明                                       |
| -------- | -------------- | ---- | ---------------------------------------- |
| permissionName  | Permissions         | 否    | 权限名。                                 |
| accessCount | number         | 否    | 该权限访问总次数。 |
| rejectCount | number         | 否    | 该权限拒绝总次数。 |
| lastAccessTime | number         | 否    | 最后一次访问时间，单位：ms。 |
| lastRejectTime | number         | 否    | 最后一次拒绝时间，单位：ms。 |
| lastAccessDuration | number         | 否    | 最后一次访问时长，单位：ms。 |
| accessRecords  | Array&lt;[UsedRecordDetail](#usedrecorddetail)&gt;         | 否    | 访问记录集合，当flag为FLAG_PERMISSION_USAGE_SUMMARY时生效，默认查询10条。                                 |
| rejectRecords  | Array&lt;[UsedRecordDetail](#usedrecorddetail)&gt;         | 否    | 拒绝记录集合，当flag为FLAG_PERMISSION_USAGE_SUMMARY时生效，默认查询10条。                                 |

## UsedRecordDetail

单次访问记录详情。

**系统能力：** SystemCapability.Security.AccessToken

| 名称       | 类型             | 必填   | 说明                                       |
| -------- | -------------- | ---- | ---------------------------------------- |
| status  | number         | 否    | 访问状态。                                 |
| timestamp | number         | 否    | 访问时的时间戳，单位：ms。 |
| accessDuration  | number         | 否    | 访问时长，单位：ms。                                 |

## PermissionActiveStatus

表示权限使用状态变化类型的枚举。

**系统能力：** SystemCapability.Security.AccessToken

| 名称                      | 默认值 | 描述              |
| ------------------------- | ------ | ---------------- |
| PERM_INACTIVE             | 0      | 表示未使用权限。   |
| PERM_ACTIVE_IN_FOREGROUND | 1      | 表示前台使用权限。 |
| PERM_ACTIVE_IN_BACKGROUND | 2      | 表示后台使用权限。 |

## ActiveChangeResponse

表示某次权限使用状态变化的详情。

 **系统能力:** SystemCapability.Security.AccessToken

| 名称           | 类型                    | 可读 | 可写 | 说明                   |
| -------------- | ---------------------- | ---- | ---- | --------------------- |
| tokenId        | number                 | 是   | 否   | 被订阅的应用身份标识    |
| permissionName | Permissions                 | 是   | 否   | 权限使用状态发生变化的权限名 |
| deviceId       | string                 | 是   | 否   | 设备号                 |
| activeStatus   | [PermissionActiveStatus](#permissionactivestatus) | 是   | 否   | 权限使用状态变化类型        |
