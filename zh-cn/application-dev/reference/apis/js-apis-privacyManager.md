# 隐私管理

该模块主要提供权限使用记录等隐私管理接口。

> **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口，三方应用不支持调用。

## 导入模块

```js
import privacyManager from '@ohos.privacyManager';
```


## privacyManager.addPermissionUsedRecord

addPermissionUsedRecord(tokenID: number, permissionName: string, successCount: number, failCount: number): Promise&lt;number&gt;

受应用权限保护的应用在被其他服务、应用调用时，可以使用该接口增加一条权限使用记录。使用Promise异步回调。
权限使用记录包括：调用方的应用身份标识、使用的应用权限名称，和其访问本应用成功、失败的次数。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 调用方的应用身份标识。              |
| permissionName | string | 是   | 应用权限名称。 |
| successCount | number | 是   | 访问成功的次数。 |
| failCount | number | 是   | 访问失败的次数。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回`0`表示成功增加记录，返回`-1`表示失败。 |

**示例：**

```js
var tokenID = appInfo.accessTokenId; // 可以通过getApplicationInfo获取accessTokenId
privacyManager.addPermissionUsedRecord(tokenID, "ohos.permission.PERMISSION_USED_STATS", 1, 0).then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

## privacyManager.addPermissionUsedRecord

addPermissionUsedRecord(tokenID: number, permissionName: string, successCount: number, failCount: number, callback: AsyncCallback&lt;number&gt;): void

受应用权限保护的应用在被其他服务、应用调用时，可以使用该接口增加一条权限使用记录。使用callback异步回调。
权限使用记录包括：调用方的应用身份标识、使用的应用权限名称，和其访问本应用成功、失败的次数。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 调用方的应用身份标识。              |
| permissionName | string | 是   | 应用权限名称。 |
| successCount | number | 是   | 访问成功的次数。 |
| failCount | number | 是   | 访问失败的次数。 |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。返回`0`表示成功增加记录，返回`-1`表示失败。 |

**示例：**

```js
var tokenID = appInfo.accessTokenId; // 可以通过getApplicationInfo获取accessTokenId
privacyManager.privacyManager.addPermissionUsedRecord(tokenID, "ohos.permission.PERMISSION_USED_STATS", 1, 0, (err, data) => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## privacyManager.getPermissionUsedRecords

getPermissionUsedRecords(request: PermissionUsedRequest): Promise&lt;PermissionUsedResponse&gt;

获取历史权限使用记录。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| request   |  [PermissionUsedRequest](#permissionusedrequest)   | 是   | 查询权限使用记录的请求。              |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise<[PermissionUsedResponse](#permissionusedresponse)> | Promise对象。返回权限使用记录。|

**示例：**

```js
let request = {
    "tokenId": 1,
    "isRemote": 1,
    "deviceId": "device",
    "bundleName": "bundle",
    "permissionNames": 1,
    "beginTime": 0,
    "endTime": 1,
    "flag":privacyManager.PermissionUsageFlag.FLAG_PERMISSION_USAGE_DETAIL,
};
privacyManager.getPermissionUsedRecords(request).then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

## privacyManager.getPermissionUsedRecords

getPermissionUsedRecords(request: PermissionUsedRequest, callback: AsyncCallback&lt;PermissionUsedResponse&gt;): void

获取历史权限使用记录。

**需要权限：** ohos.permission.PERMISSION_USED_STATS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| request | [PermissionUsedRequest](#permissionusedrequest) | 是 | 查询权限使用记录的请求。 |
| callback | AsyncCallback<[PermissionUsedResponse](#permissionusedresponse)> | 是 | 回调函数。返回权限使用记录。 |

**示例：**

```js
let request = {
    "tokenId": 1,
    "isRemote": 1,
    "deviceId": "device",
    "bundleName": "bundle",
    "permissionNames": 1,
    "beginTime": 0,
    "endTime": 1,
    "flag":privacyManager.PermissionUsageFlag.FLAG_PERMISSION_USAGE_DETAIL,
};
privacyManager.getPermissionUsedRecords(request, (err, data) => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
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

**系统能力：**  以下各项对应的系统能力均为SystemCapability.Security.AccessToken

| 名称       | 类型             | 必填   | 说明                                       |
| -------- | -------------- | ---- | ---------------------------------------- |
| tokenId  | number         | 否    | 目标应用的身份标识。                                 |
| isRemote | boolean         | 否    | 默认值false。 |
| deviceId  | string         | 否    | 目标应用所在设备的ID。                                 |
| bundleName | string         | 否    | 目标应用的包名。 |
| permissionNames  | Array&lt;string&gt;         | 否    | 需要查询的权限集合。                                 |
| beginTime | number         | 否    | 查询的起始时间，单位：ms，默认值0，不设定起始时间。 |
| endTime | number         | 否    | 查询的终止时间，单位：ms，默认值0，不设定终止时间。 |
| flag | [PermissionUsageFlag](#permissionusageflag)         | 是    | 查询方式，默认值FLAG_PERMISSION_USAGE_SUMMARY。 |

## PermissionUsedResponse

表示所有应用的访问记录。

**系统能力：**  以下各项对应的系统能力均为SystemCapability.Security.AccessToken

| 名称       | 类型             | 必填   | 说明                                       |
| -------- | -------------- | ---- | ---------------------------------------- |
| beginTime | number         | 否    | 查询记录的起始时间，单位：ms。 |
| endTime | number         | 否    | 查询记录的终止时间，单位：ms。 |
| bundleRecords  | Array&lt;[BundleUsedRecord](#BundleUsedRecord)&gt;         | 否    | 应用的权限使用记录集合。                                 |

## BundleUsedRecord

某个应用的访问记录。

**系统能力：**  以下各项对应的系统能力均为SystemCapability.Security.AccessToken

| 名称       | 类型             | 必填   | 说明                                       |
| -------- | -------------- | ---- | ---------------------------------------- |
| tokenId  | number         | 否    | 目标应用的身份标识。                                 |
| isRemote | boolean         | 否    | 默认值false。 |
| deviceId  | string         | 否    | 目标应用所在设备的ID。                                 |
| bundleName | string         | 否    | 目标应用的包名。 |
| permissionRecords  | Array&lt;[PermissionUsedRecord](#PermissionUsedRecord)&gt;         | 否    | 每个应用的权限使用记录集合。                                 |

## PermissionUsedRecord

某个权限的访问记录。

**系统能力：**  以下各项对应的系统能力均为SystemCapability.Security.AccessToken

| 名称       | 类型             | 必填   | 说明                                       |
| -------- | -------------- | ---- | ---------------------------------------- |
| permissionName  | string         | 否    | 权限名。                                 |
| accessCount | number         | 否    | 该权限访问总次数。 |
| rejectCount | number         | 否    | 该权限拒绝总次数。 |
| lastAccessTime | number         | 否    | 最后一次访问时间，单位：ms。 |
| lastRejectTime | number         | 否    | 最后一次拒绝时间，单位：ms。 |
| lastAccessDuration | number         | 否    | 最后一次访问时长，单位：ms。 |
| accessRecords  | Array&lt;[UsedRecordDetail](#usedrecorddetail)&gt;         | 否    | 访问记录集合，当flag为FLAG_PERMISSION_USAGE_SUMMARY时生效，默认查询10条。                                 |
| rejectRecords  | Array&lt;[UsedRecordDetail](#usedrecorddetail)&gt;         | 否    | 拒绝记录集合，当flag为FLAG_PERMISSION_USAGE_SUMMARY时生效，默认查询10条。                                 |

## UsedRecordDetail

单次访问记录详情。

**系统能力：**  以下各项对应的系统能力均为SystemCapability.Security.AccessToken

| 名称       | 类型             | 必填   | 说明                                       |
| -------- | -------------- | ---- | ---------------------------------------- |
| status  | number         | 否    | 访问状态。                                 |
| timestamp | number         | 否    | 访问时的时间戳，单位：ms。 |
| accessDuration  | number         | 否    | 访问时长，单位：ms。                                 |
