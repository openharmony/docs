# @ohos.abilityAccessCtrl (程序访问控制管理)

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
let atManager = abilityAccessCtrl.createAtManager();
```

## AtManager

管理访问控制模块的实例。

### checkAccessToken<sup>9+</sup>

checkAccessToken(tokenID: number, permissionName: Permissions): Promise&lt;GrantStatus&gt;

校验应用是否授予权限。使用Promise异步回调。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 要校验的目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得。             |
| permissionName | Permissions | 是   | 需要校验的权限名称。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;GrantStatus&gt; | Promise对象。返回授权状态结果。 |

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0 |

**示例：**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // 可以通过getApplicationInfo获取accessTokenId
try {
    atManager.checkAccessToken(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS").then((data) => {
        console.log(`checkAccessToken success, data->${JSON.stringify(data)}`);
    }).catch((err) => {
        console.log(`checkAccessToken fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

### verifyAccessTokenSync<sup>9+</sup>

verifyAccessTokenSync(tokenID: number, permissionName: Permissions): GrantStatus

校验应用是否被授予权限，同步返回结果。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 要校验应用的身份标识。              |
| permissionName | Permissions | 是   | 需要校验的权限名称。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| [GrantStatus](#grantstatus) | 枚举实例，返回授权状态。 |

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0 |

**示例：**

```js
let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0;
let data = atManager.verifyAccessTokenSync(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS");
console.log(`data->${JSON.stringify(data)}`);
```

### grantUserGrantedPermission

grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number): Promise&lt;void&gt;

授予应用user grant权限。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GRANT_SENSITIVE_PERMISSIONS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                                                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | 是   | 目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得。            |
| permissionName | Permissions              | 是   | 被授予的权限名称。 |
| permissionFlag  | number | 是   | 授权选项，1表示下次仍需弹窗，2表示允许、禁止后不再提醒，3表示系统授权不允许更改。  |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0 |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist. |
| 12100006 | The application specified by the tokenID is not allowed to be granted with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | Service is abnormal. |

**示例：**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // 可以通过getApplicationInfo获取accessTokenId
let permissionFlag = 1;
try {
    atManager.grantUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlag).then(() => {
        console.log('grantUserGrantedPermission success');
    }).catch((err) => {
        console.log(`grantUserGrantedPermission fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

### grantUserGrantedPermission

grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number, callback: AsyncCallback&lt;void&gt;): void

授予应用user grant权限。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GRANT_SENSITIVE_PERMISSIONS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                          |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | 是   | 目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得。|
| permissionName | Permissions              | 是   | 被授予的权限名称。 |
| permissionFlag  | number | 是   | 授权选项，1表示下次仍需弹窗，2表示允许、禁止后不再提醒，3表示系统授权不允许更改。  |
| callback | AsyncCallback&lt;void&gt; | 是 | 授予应用user grant权限。当授予权限成功时，err为undefine；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0 |
| 12100002 | TokenId does not exist. |
| 12100003 | Permission does not exist. |
| 12100006 | The specified application does not support the permissions granted or ungranted as specified. |

**示例：**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // 可以通过getApplicationInfo获取accessTokenId
let permissionFlag = 1;
try {
    atManager.grantUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlag, (err, data) => {
        if (err) {
            console.log(`grantUserGrantedPermission fail, err->${JSON.stringify(err)}`);
        } else {
            console.log('grantUserGrantedPermission success');
        }
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

### revokeUserGrantedPermission

revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number): Promise&lt;void&gt;

撤销应用user grant权限。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.REVOKE_SENSITIVE_PERMISSIONS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                                                         |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | 是   | 目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得。           |
| permissionName | Permissions              | 是   | 被撤销的权限名称。 |
| permissionFlag  | number | 是   | 授权选项，1表示下次仍需弹窗，2表示允许、禁止后不再提醒，3表示系统授权不允许更改。  |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0 |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist. |
| 12100006 | The application specified by the tokenID is not allowed to be revoked with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | Service is abnormal. |

**示例：**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // 可以通过getApplicationInfo获取accessTokenId
let permissionFlag = 1;
try {
    atManager.revokeUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlag).then(() => {
        console.log('revokeUserGrantedPermission success');
    }).catch((err) => {
        console.log(`revokeUserGrantedPermission fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

### revokeUserGrantedPermission

revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlag: number, callback: AsyncCallback&lt;void&gt;): void

撤销应用user grant权限。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.REVOKE_SENSITIVE_PERMISSIONS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名    | 类型                | 必填 | 说明                          |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| tokenID      | number              | 是   | 目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得。           |
| permissionName | Permissions              | 是   | 被撤销的权限名称。 |
| permissionFlag  | number | 是   | 授权选项，1表示下次仍需弹窗，2表示允许、禁止后不再提醒，3表示系统授权不允许更改。  |
| callback | AsyncCallback&lt;void&gt; | 是 | 撤销应用user grant权限。当撤销权限成功时，err为undefine；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0 |
| 12100002 | TokenId does not exist. |
| 12100003 | Permission does not exist. |
| 12100006 | The specified application does not support the permissions granted or ungranted as specified. |

**示例：**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // 可以通过getApplicationInfo获取accessTokenId
let permissionFlag = 1;
try {
    atManager.revokeUserGrantedPermission(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS", permissionFlag, (err, data) => {
        if (err) {
            console.log(`revokeUserGrantedPermission fail, err->${JSON.stringify(err)}`);
        } else {
            console.log('revokeUserGrantedPermission success');
        }
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
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
| tokenID      | number              | 是   | 目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得。            |
| permissionName | Permissions              | 是   | 查询的权限名称。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回查询结果。 |

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0 |
| 12100002 | The specified tokenID does not exist. |
| 12100003 | The specified permission does not exist. |
| 12100006 | The operation is not allowed. Either the application is a sandbox or the tokenID is from a remote device. |
| 12100007 | Service is abnormal. |

**示例：**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // 可以通过getApplicationInfo获取accessTokenId
try {
    atManager.getPermissionFlags(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS").then((data) => {
        console.log(`getPermissionFlags success, data->${JSON.stringify(data)}`);
    }).catch((err) => {
        console.log(`getPermissionFlags fail, err->${JSON.stringify(err)}`);
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

### getVersion<sup>9+</sup>

getVersion(): Promise&lt;number&gt;

获取当前权限管理的数据版本。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回查询到的版本号。 |

**示例：**

```js
let atManager = abilityAccessCtrl.createAtManager();
let promise = atManager.getVersion();
promise.then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

### on<sup>9+</sup>

on(type: 'permissionStateChange', tokenIDList: Array&lt;number&gt;, permissionNameList: Array&lt;Permissions&gt;, callback: Callback&lt;PermissionStateChangeInfo&gt;): void;

订阅指定tokenId列表与权限列表的权限状态变更事件。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_SENSITIVE_PERMISSIONS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名             | 类型                   | 必填 | 说明                                                          |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | 是   | 订阅事件类型，固定为'permissionStateChange'，权限状态变更事件。  |
| tokenIDList        | Array&lt;number&gt;   | 是   | 订阅的tokenId列表，为空时表示订阅所有的应用的权限状态变化。        |
| permissionNameList | Array&lt;Permissions&gt;   | 是   | 订阅的权限名列表，为空时表示订阅所有的权限状态变化。               |
| callback | Callback&lt;[PermissionStateChangeInfo](#permissionstatechangeinfo9)&gt; | 是 | 订阅指定tokenId与指定权限名状态变更事件的回调。|

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID is 0 |
| 12100004 | The interface is called repeatedly with the same input. |
| 12100005 | The registration time has exceeded the limitation. |
| 12100007 | Service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```js
import abilityAccessCtrl, {Permissions} from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let appInfo = bundle.getApplicationInfoSync('com.example.myapplication', 0, 100);
let tokenIDList: Array<number> = [appInfo.accessTokenId];
let permissionNameList: Array<Permissions> = ["ohos.permission.DISTRIBUTED_DATASYNC"];
try {
    atManager.on('permissionStateChange', tokenIDList, permissionNameList, (data) => {
        console.debug("receive permission state change, data:" + JSON.stringify(data));
    });
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

### off<sup>9+</sup>

off(type: 'permissionStateChange', tokenIDList: Array&lt;number&gt;, permissionNameList: Array&lt;Permissions&gt;, callback?: Callback&lt;PermissionStateChangeInfo&gt;): void;

取消订阅指定tokenId列表与权限列表的权限状态变更事件，使用callback回调异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_SENSITIVE_PERMISSIONS，仅系统应用可用。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名             | 类型                   | 必填 | 说明                                                          |
| ------------------ | --------------------- | ---- | ------------------------------------------------------------ |
| type               | string                | 是   | 订阅事件类型，固定为'permissionStateChange'，权限状态变更事件。  |
| tokenIDList        | Array&lt;number&gt;   | 是   | 订阅的tokenId列表，为空时表示订阅所有的应用的权限状态变化，必须与on的输入一致。 |
| permissionNameList | Array&lt;Permissions&gt;   | 是   | 订阅的权限名列表，为空时表示订阅所有的权限状态变化，必须与on的输入一致。 |
| callback | Callback&lt;[PermissionStateChangeInfo](#permissionstatechangeinfo9)&gt; | 否 | 取消订阅指定tokenId与指定权限名状态变更事件的回调。|

**错误码：**

以下错误码的详细介绍请参见[程序访问控制错误码](../errorcodes/errorcode-access-token.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12100001 | The parameter is invalid. The tokenID in list is all invalid |
| 12100004 | The interface is not used with |
| 12100007 | Service is abnormal. |
| 12100008 | Out of memory. |

**示例：**

```js
import abilityAccessCtrl, {Permissions} from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let appInfo = bundle.getApplicationInfoSync('com.example.myapplication', 0, 100);
let tokenIDList: Array<number> = [appInfo.accessTokenId];
let permissionNameList: Array<Permissions> = ["ohos.permission.DISTRIBUTED_DATASYNC"];
try {
    atManager.off('permissionStateChange', tokenIDList, permissionNameList);
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

### verifyAccessToken<sup>9+</sup>

verifyAccessToken(tokenID: number, permissionName: Permissions): Promise&lt;GrantStatus&gt;

校验应用是否授予权限。使用Promise异步回调。

> **说明：** 建议使用[checkAccessToken](#checkaccesstoken9)替代。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 要校验的目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得。             |
| permissionName | Permissions | 是   | 需要校验的权限名称。仅支持输入有效的权限名称。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;GrantStatus&gt; | Promise对象。返回授权状态结果。 |

**示例：**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // 可以通过getApplicationInfo获取accessTokenId
let promise = atManager.verifyAccessToken(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS");
promise.then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

### verifyAccessToken<sup>(deprecated)</sup>

verifyAccessToken(tokenID: number, permissionName: string): Promise&lt;GrantStatus&gt;

校验应用是否授予权限。使用Promise异步回调。

> **说明：** 从API version 9开始不再维护，建议使用[checkAccessToken](#checkaccesstoken9)替代。

**系统能力：** SystemCapability.Security.AccessToken

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 要校验的目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得。             |
| permissionName | string | 是   | 需要校验的权限名称。 |

**返回值：**

| 类型          | 说明                                |
| :------------ | :---------------------------------- |
| Promise&lt;GrantStatus&gt; | Promise对象。返回授权状态结果。 |

**示例：**

```js
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';

let atManager = abilityAccessCtrl.createAtManager();
let tokenID = 0; // 可以通过getApplicationInfo获取accessTokenId
let promise = atManager.verifyAccessToken(tokenID, "ohos.permission.GRANT_SENSITIVE_PERMISSIONS");
promise.then(data => {
    console.log(`promise: data->${JSON.stringify(data)}`);
});
```

### GrantStatus

表示授权状态的枚举。

**系统能力：** SystemCapability.Security.AccessToken

| 名称               |    值 | 说明        |
| ------------------ | ----- | ----------- |
| PERMISSION_DENIED  | -1    | 表示未授权。 |
| PERMISSION_GRANTED | 0     | 表示已授权。 |

### PermissionStateChangeType<sup>9+</sup>

表示权限授权状态变化操作类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

| 名称                     |    值 | 说明              |
| ----------------------- | ------ | ----------------- |
| PERMISSION_REVOKED_OPER | 0      | 表示权限取消操作。 |
| PERMISSION_GRANTED_OPER | 1      | 表示权限授予操作。 |

### PermissionStateChangeInfo<sup>9+</sup>

表示某次权限授权状态变化的详情。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.AccessToken

| 名称           | 类型                       | 可读 | 可写 | 说明                |
| -------------- | ------------------------- | ---- | ---- | ------------------ |
| change         | [PermissionStateChangeType](#permissionstatechangetype9) | 是   | 否   | 权限授权状态变化类型。        |
| tokenID        | number                    | 是   | 否   | 被订阅的应用身份标识。 |
| permissionName | Permissions                    | 是   | 否   | 当前授权状态发生变化的权限名。 |
