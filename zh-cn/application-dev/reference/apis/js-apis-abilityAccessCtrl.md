# 程序访问控制管理

程序访问控制提供程序的权限管理能力，包括鉴权、授权和取消授权等。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl'
```

## abilityAccessCtrl.createAtManager

createAtManager(): AtManager

访问控制管理：获取访问控制模块对象。

**系统能力：** SystemCapability.Security.AccessToken


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [AtManager](#atmanager) | 获取访问控制模块的实例。 |

**示例：**

```js
var AtManager = abilityAccessCtrl.createAtManager();
```

## AtManager

管理访问控制模块的实例。

### verifyAccessToken

verifyAccessToken(tokenID: number, permissionName: string): Promise&lt;GrantStatus&gt;

校验应用是否授予权限，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 要校验的目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得              |
| permissionName | string | 是   | 需要校验的权限名称。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;GrantStatus&gt; | Promise实例，用于获取异步返回的授权状态结果。 |

**示例：**

```js
var AtManager = abilityAccessCtrl.createAtManager();
let tokenID = 0;
let promise = AtManager.verifyAccessToken(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS");
promise.then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

### verifyAccessTokenSync<sup>9+</sup>

verifyAccessTokenSync(tokenID: number, permissionName: string): GrantStatus

校验应用是否被授予权限，同步返回结果。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 要校验应用的身份标识。              |
| permissionName | string | 是   | 需要校验的权限名称。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| [GrantStatus](#grantstatus) | 枚举实例，返回授权状态。 |

**示例：**

```js
var AtManager = abilityAccessCtrl.createAtManager();
let tokenID = 0;
let data = AtManager.verifyAccessTokenSync(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS");
console.log(`data->${JSON.stringify(data)}`);
```

### grantUserGrantedPermission

grantUserGrantedPermission(tokenID: number, permissionName: string, permissionFlag: number): Promise&lt;number&gt;

授予应用user grant权限，使用Promise方式异步返回结果。

此接口为系统接口。

**需要权限：** ohos.permission.GRANT_SENSITIVE_PERMISSIONS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                                                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | 是   | 目标应用的身份标识。            |
| permissionName | string              | 是   | 被授予的权限名称。 |
| permissionFlag  | number | 是   | 授权选项，1表示下次仍需弹窗，2表示允许、禁止后不再提醒，3表示系统授权不允许更改。  |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise实例，用于获取异步返回的授权操作结果。 |

**示例：**

```js
var AtManager = abilityAccessCtrl.createAtManager();
let tokenID = 0;
let permissionFlag = 1;
let promise = AtManager.grantUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlag);
promise.then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

### grantUserGrantedPermission

grantUserGrantedPermission(tokenID: number, permissionName: string, permissionFlag: number, callback: AsyncCallback&lt;number&gt;): void

授予应用user grant权限，使用callback回调异步返回结果。

此接口为系统接口。

**需要权限：** ohos.permission.GRANT_SENSITIVE_PERMISSIONS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                          |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | 是   | 目标应用的身份标识。           |
| permissionName | string              | 是   | 被授予的权限名称。 |
| permissionFlag  | number | 是   | 授权选项，1表示下次仍需弹窗，2表示允许、禁止后不再提醒，3表示系统授权不允许更改。  |
| callback | AsyncCallback&lt;number&gt; | 是 | 检查授予应用user grant权限的操作结果同步的回调。 |

**示例：**

```js
var AtManager = abilityAccessCtrl.createAtManager();
let tokenID = 0;
let permissionFlag = 1;
AtManager.grantUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlag, (err, data) => {
    if (err) {
        console.log(`callback: err->${JSON.stringify(err)}`);
    } else {
        console.log(`callback: data->${JSON.stringify(data)}`);
    }
});
```

### revokeUserGrantedPermission

revokeUserGrantedPermission(tokenID: number, permissionName: string, permissionFlag: number): Promise&lt;number&gt;

撤销应用user grant权限，使用Promise方式异步返回结果。

此接口为系统接口。

**需要权限：** ohos.permission.REVOKE_SENSITIVE_PERMISSIONS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                                                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | 是   | 目标应用的身份标识。            |
| permissionName | string              | 是   | 被撤销的权限名称。 |
| permissionFlag  | number | 是   | 授权选项，1表示下次仍需弹窗，2表示允许、禁止后不再提醒，3表示系统授权不允许更改。  |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise实例，用于获取异步返回的授权操作结果。 |

**示例：**

```js
var AtManager = abilityAccessCtrl.createAtManager();
let tokenID = 0;
let permissionFlag = 1;
let promise = AtManager.revokeUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlag);
promise.then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

### revokeUserGrantedPermission

revokeUserGrantedPermission(tokenID: number, permissionName: string, permissionFlag: number, callback: AsyncCallback&lt;number&gt;): void

撤销应用user grant权限，使用callback回调异步返回结果。

此接口为系统接口。

**需要权限：** ohos.permission.REVOKE_SENSITIVE_PERMISSIONS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                          |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | 是   | 目标应用的身份标识。            |
| permissionName | string              | 是   | 被撤销的权限名称。 |
| permissionFlag  | number | 是   | 授权选项，1表示下次仍需弹窗，2表示允许、禁止后不再提醒，3表示系统授权不允许更改。  |
| callback | AsyncCallback&lt;number&gt; | 是 | 检查撤销应用user grant权限的操作结果同步的回调。 |

**示例：**

```js
var AtManager = abilityAccessCtrl.createAtManager();
let tokenID = 0;
let permissionFlag = 1;
AtManager.revokeUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlag, (err, data) => {
    if (err) {
        console.log(`callback: err->${JSON.stringify(err)}`);
    } else {
        console.log(`callback: data->${JSON.stringify(data)}`);
    }
});
```

### getPermissionFlags

getPermissionFlags(tokenID: number, permissionName: string): Promise&lt;number&gt;

获取指定应用的指定权限的flag，使用Promise方式异步返回结果。

此接口为系统接口。

**需要权限：** ohos.permission.GET_SENSITIVE_PERMISSIONS or ohos.permission.GRANT_SENSITIVE_PERMISSIONS or ohos.permission.REVOKE_SENSITIVE_PERMISSIONS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                          |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | 是   | 目标应用的身份标识。            |
| permissionName | string              | 是   | 查询的权限名称。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise实例，用于获取异步返回的查询结果。 |

**示例：**

```js
var AtManager = abilityAccessCtrl.createAtManager();
let tokenID = 0;
let promise = AtManager.getPermissionFlags(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS");
promise.then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

### getVersion<sup>9+</sup>

getVersion(): Promise&lt;number&gt;

获取当前权限管理的数据版本，使用Promise方式异步返回结果。

此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise实例，用于获取异步返回的版本号。 |

**示例：**

```js
var AtManager = abilityAccessCtrl.createAtManager();
let promise = AtManager.getVersion();
promise.then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

### on<sup>9+</sup>

on(type: 'permissionStateChange', tokenIDList: Array&lt;number&gt;, permissionNameList: Array&lt;string&gt;, callback: Callback&lt;PermissionStateChangeInfo&gt;): void;

订阅指定tokenId列表与权限列表的权限状态变更事件，使用callback回调异步返回结果。

此接口为系统接口。

**需要权限：** ohos.permission.GET_SENSITIVE_PERMISSIONS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名             | 类型                   | 必填 | 说明                                                          |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | 是   | 订阅事件类型，固定为'permissionStateChange'，权限状态变更事件。  |
| tokenIDList        | Array&lt;number&gt;   | 否   | 订阅的tokenId列表，为空时表示订阅所有的应用的权限状态变化。        |
| permissionNameList | Array&lt;string&gt;   | 否   | 订阅的权限名列表，为空时表示订阅所有的权限状态变化。               |
| callback | Callback&lt;[PermissionStateChangeInfo](#permissionstatechangeinfo9)&gt; | 是 | 订阅指定tokenId与指定权限名状态变更事件的回调。|

**示例：**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

function OnPermissionStateChanged(data){
    console.debug("receive permission state change, data:" + JSON.stringify(data));
}
let atManager = abilityAccessCtrl.createAtManager();
let type: 'permissionStateChange' = 'permissionStateChange';
let tokenIDList: Array<number> = [];
let permissionNameList: Array<string> = [];
try{
    atManager.on(type, tokenIDList, permissionNameList, OnPermissionStateChanged);
}
catch(err){
    console.error("on err:" + JSON.stringify(err));
}
```

### off<sup>9+</sup>

off(type: 'permissionStateChange', tokenIDList: Array&lt;number&gt;, permissionNameList: Array&lt;string&gt;, callback?: Callback&lt;PermissionStateChangeInfo&gt;): void;

取消订阅指定tokenId列表与权限列表的权限状态变更事件，使用callback回调异步返回结果。

此接口为系统接口。

**需要权限：** ohos.permission.GET_SENSITIVE_PERMISSIONS

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名             | 类型                   | 必填 | 说明                                                          |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | 是   | 订阅事件类型，固定为'permissionStateChange'，权限状态变更事件。  |
| tokenIDList        | Array&lt;number&gt;   | 否   | 订阅的tokenId列表，为空时表示订阅所有的应用的权限状态变化，必须与on的输入一致。 |
| permissionNameList | Array&lt;string&gt;   | 否   | 订阅的权限名列表，为空时表示订阅所有的权限状态变化，必须与on的输入一致。 |
| callback | Callback&lt;[PermissionStateChangeInfo](#permissionstatechangeinfo9)&gt; | 否 | 取消订阅指定tokenId与指定权限名状态变更事件的回调。|

**示例：**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let type: 'permissionStateChange' = 'permissionStateChange';
let tokenIDList: Array<number> = [];
let permissionNameList: Array<string> = [];
try{
    atManager.off(type, tokenIDList, permissionNameList);
}
catch(err){
    console.error("off err:" + JSON.stringify(err));
}
```

### GrantStatus

表示授权状态的枚举。

**系统能力：** SystemCapability.Security.AccessToken

| 名称               | 默认值 | 描述        |
| ------------------ | ----- | ----------- |
| PERMISSION_DENIED  | -1    | 表示未授权。 |
| PERMISSION_GRANTED | 0     | 表示已授权。 |

### PermissionStateChangeType<sup>9+</sup>

表示权限状态变化操作类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

| 名称                     | 默认值 | 描述              |
| ----------------------- | ------ | ----------------- |
| PERMISSION_REVOKED_OPER | 0      | 表示权限取消操作。 |
| PERMISSION_GRANTED_OPER | 1      | 表示权限授予操作。 |

### PermissionStateChangeInfo<sup>9+</sup>

**系统接口：** 此接口为系统接口。

 **系统能力:** SystemCapability.Security.AccessToken

| 名称           | 类型                       | 可读 | 可写 | 说明                |
| -------------- | ------------------------- | ---- | ---- | ------------------ |
| change         | [PermissionStateChangeType](#permissionstatechangetype9) | 是   | 否   | 权限变化类型        |
| tokenID        | number                    | 是   | 否   | 调用方的应用身份标识 |
| permissionName | string                    | 是   | 否   | 状态发生变化的权限名 |
