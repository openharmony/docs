# 隐私管理

该模块主要提供权限使用记录等隐私管理接口。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import privacyManager from '@ohos.privacyManager';
```


## privacyManager.addPermissionUsedRecord

addPermissionUsedRecord(tokenID: number, permissionName: string, successCount: number, failCount: number): Promise&lt;number&gt;

增加一条权限使用记录。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 要新增记录的目标应用的身份标识。              |
| permissionName | string | 是   | 要新增记录的权限名称。 |
| successCount | number | 是   | 访问成功的次数。 |
| failCount | number | 是   | 访问失败的次数。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise实例，用于获取异步返回的操作结果。 |

**示例：**

```js
let tokenID = 0;
privacyManager.addPermissionUsedRecord(tokenID, "ohos.permission.PERMISSION_USED_STATS", 1, 0).then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

## privacyManager.addPermissionUsedRecord

addPermissionUsedRecord(tokenID: number, permissionName: string, successCount: number, failCount: number, callback: AsyncCallback&lt;number&gt;): void

增加一条权限使用记录。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 要新增记录的目标应用的身份标识。              |
| permissionName | string | 是   | 要新增记录的权限名称。 |
| successCount | number | 是   | 访问成功的次数。 |
| failCount | number | 是   | 访问失败的次数。 |
| callback | AsyncCallback&lt;number&gt; | 是   | 指定的callback回调方法，用于获取返回值。 |

**示例：**

```js
let tokenID = 0;
privacyManager.privacyManager.addPermissionUsedRecord(tokenID, "ohos.permission.PERMISSION_USED_STATS", 1, 0, data => {
    console.log(`callback: data->${JSON.stringify(data)}`);
});
```

## privacyManager.getPermissionUsedRecords

getPermissionUsedRecords(request: PermissionUsedRequest): Promise&lt;PermissionUsedResponse&gt;

获取历史权限使用记录。

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| request   |  PermissionUsedRequest   | 是   | 查询权限使用记录的请求。              |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;PermissionUsedResponse&gt; | Promise实例，用于异步返回查询的权限使用记录结果。 |

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

此接口为系统接口，三方应用不支持调用。

**需要权限：** ohos.permission.PERMISSION_USED_STATS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| request   |  PermissionUsedRequest   | 是   | 查询权限使用记录的请求。              |
| callback | AsyncCallback&lt;PermissionUsedResponse&gt; | 是   | 指定的callback回调方法，用于获取权限使用记录。 |

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

表示使用记录的查询方式的枚举值。

**系统能力：** SystemCapability.Security.AccessToken

| 名称                    | 默认值 | 描述                   |
| ----------------------- | ------ | ---------------------- |
| FLAG_PERMISSION_USAGE_SUMMARY             | 0    | 表示查询总览数据，默认值。 |
| FLAG_PERMISSION_USAGE_DETAIL         | 1    | 表示查询详细数据。         |

## PermissionUsedRequest

表示使用记录的查询请求。

**系统能力：**  以下各项对应的系统能力均为SystemCapability.Security.AccessToken

| 名称       | 类型             | 必填   | 说明                                       |
| -------- | -------------- | ---- | ---------------------------------------- |
| tokenId  | number         | 否    | 需要查询的目标应用的身份标识。                                 |
| isRemote | boolean         | 否    | 默认值false，当。 |
| deviceId  | string         | 否    | 需要查询的目标应用的所在的设备ID。                                 |
| bundleName | string         | 否    | 要查询的目标应用的包名。 |
| permissionNames  | Array&lt;string&gt;         | 否    | 需要查询的权限集合。                                 |
| beginTime | number         | 否    | 查询的起始时间，默认值0，不设定起始时间。 |
| endTime | number         | 否    | 查询的终止时间，默认值0，不设定终止时间。 |
| flag | PermissionUsageFlag         | 是    | 查询方式，默认值FLAG_PERMISSION_USAGE_SUMMARY。 |

## PermissionUsedResponse

表示所有应用的访问记录。

**系统能力：**  以下各项对应的系统能力均为SystemCapability.Security.AccessToken

| 名称       | 类型             | 必填   | 说明                                       |
| -------- | -------------- | ---- | ---------------------------------------- |
| beginTime | number         | 否    | 查询记录的起始时间。 |
| endTime | number         | 否    | 查询记录的终止时间。 |
| bundleRecords  | Array&lt;BundleUsedRecord&gt;         | 否    | 应用的权限使用记录集合。                                 |

## BundleUsedRecord

每个应用下的权限访问记录。

**系统能力：**  以下各项对应的系统能力均为SystemCapability.Security.AccessToken

| 名称       | 类型             | 必填   | 说明                                       |
| -------- | -------------- | ---- | ---------------------------------------- |
| tokenId  | number         | 否    | 需要查询的目标应用的身份标识。                                 |
| isRemote | boolean         | 否    | 默认值false，当。 |
| deviceId  | string         | 否    | 需要查询的目标应用的所在的设备ID。                                 |
| bundleName | string         | 否    | 要查询的目标应用的包名。 |
| permissionRecords  | Array&lt;PermissionUsedRecord&gt;         | 否    | 每个应用的权限使用记录集合。                                 |

## PermissionUsedRecord

表示每一个权限对应的访问记录。

**系统能力：**  以下各项对应的系统能力均为SystemCapability.Security.AccessToken

| 名称       | 类型             | 必填   | 说明                                       |
| -------- | -------------- | ---- | ---------------------------------------- |
| permissionName  | string         | 否    | 权限名。                                 |
| accessCount | number         | 否    | 该权限访问总次数。 |
| rejectCount | number         | 否    | 该权限拒绝总次数。 |
| lastAccessTime | number         | 否    | 最后一次访问时间，单位：ms。 |
| lastRejectTime | number         | 否    | 最后一次拒绝时间，单位：ms。 |
| lastAccessDuration | number         | 否    | 最后一次访问时长，单位：ms。 |
| accessRecords  | Array&lt;UsedRecordDetail&gt;         | 否    | 访问记录集合，当flag为FLAG_PERMISSION_USAGE_SUMMARY时生效，默认查询10条。                                 |
| rejectRecords  | Array&lt;UsedRecordDetail&gt;         | 否    | 拒绝记录集合，当flag为FLAG_PERMISSION_USAGE_SUMMARY时生效，默认查询10条。                                 |

## UsedRecordDetail

每一次访问记录的详情。

**系统能力：**  以下各项对应的系统能力均为SystemCapability.Security.AccessToken

| 名称       | 类型             | 必填   | 说明                                       |
| -------- | -------------- | ---- | ---------------------------------------- |
| status  | number         | 否    | 访问状态。                                 |
| timestamp | number         | 否    | 访问时的时间戳，单位：ms。 |
| accessDuration  | number         | 否    | 访问时长，单位：ms。                                 |
