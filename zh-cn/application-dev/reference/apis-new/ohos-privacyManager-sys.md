# @ohos.privacyManager    
本模块主要提供权限使用记录等隐私管理接口。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import privacyManager from '@ohos.privacyManager'    
```  
    
## addPermissionUsedRecord    
受应用权限保护的应用在被其他服务、应用调用时，可以使用该接口增加一条权限使用记录。  
 **调用形式：**     
    
- addPermissionUsedRecord(     tokenID: number,     permissionName: Permissions,     successCount: number,     failCount: number   ): Promise\<void>    
起始版本： 9    
- addPermissionUsedRecord(     tokenID: number,     permissionName: Permissions,     successCount: number,     failCount: number,     callback: AsyncCallback\<void>   ): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken  
 **需要权限：** ohos.permission.PERMISSION_USED_STATS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tokenID | number | true | 调用方的应用身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得。 |  
| permissionName | Permissions | true | 应用权限名称。 |  
| successCount | number | true | 访问成功的次数。 |  
| failCount | number | true | 访问失败的次数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当添加使用记录成功时，err为undefined；否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
| 12100001 | The parameter is invalid. The tokenID is 0, or the string size of permissionName is larger than 256, or the count value is invalid. |  
| 12100002 | The specified tokenID does not exist or refer to an application process. |  
| 12100003 | The specified permission does not exist or is not an user_grant permission. |  
| 12100007 | Service is abnormal. |  
| 12100008 | Out of memory. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import privacyManager from '@ohos.privacyManager';  
import { BusinessError } from '@ohos.base';  
  
let tokenID: number = 0; // 可以通过getApplicationInfo获取accessTokenId  
try {  
    privacyManager.addPermissionUsedRecord(tokenID, 'ohos.permission.READ_AUDIO', 1, 0, (err: BusinessError, data: void) => {  
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
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import privacyManager from '@ohos.privacyManager';  
import { BusinessError } from '@ohos.base';  
  
let tokenID: number = 0; // 可以通过getApplicationInfo获取accessTokenId  
try {  
    privacyManager.addPermissionUsedRecord(tokenID, 'ohos.permission.READ_AUDIO', 1, 0).then(() => {  
        console.log('addPermissionUsedRecord success');  
    }).catch((err: BusinessError) => {  
        console.log(`addPermissionUsedRecord fail, err->${JSON.stringify(err)}`);  
    });  
} catch(err) {  
    console.log(`catch err->${JSON.stringify(err)}`);  
}  
    
```    
  
    
## getPermissionUsedRecord    
获取历史权限使用记录  
 **调用形式：**     
    
- getPermissionUsedRecord(request: PermissionUsedRequest): Promise\<PermissionUsedResponse>    
起始版本： 9    
- getPermissionUsedRecord(     request: PermissionUsedRequest,     callback: AsyncCallback\<PermissionUsedResponse>   ): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken  
 **需要权限：** ohos.permission.PERMISSION_USED_STATS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request | PermissionUsedRequest | true | 查询权限使用记录的请求。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | AsyncCallback<[PermissionUsedResponse](#permissionusedresponse)> | 是 | 回调函数。当查询记录成功时，err为undefined，data为查询到的权限使用记录；否则为错误对象。 |  
| Promise<PermissionUsedResponse> | Promise对象。返回查询的权限使用记录。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
| 12100001 | The parameter is invalid. the value of flag in request is invalid. |  
| 12100002 | The specified tokenID does not exist or refer to an application process. |  
| 12100003 | The specified permission does not exist or is not an user_grant permission. |  
| 12100007 | Service is abnormal. |  
| 12100008 | Out of memory. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import privacyManager from '@ohos.privacyManager';  
import { BusinessError } from '@ohos.base';  
  
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
try {  
    privacyManager.getPermissionUsedRecord(request, (err: BusinessError, data: privacyManager.PermissionUsedResponse) => {  
        if (err) {  
            console.log(`getPermissionUsedRecord fail, err->${JSON.stringify(err)}`);  
        } else {  
            console.log(`getPermissionUsedRecord success, data->${JSON.stringify(data)}`);  
        }  
    });  
} catch(err) {  
    console.log(`catch err->${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import privacyManager from '@ohos.privacyManager';  
import { BusinessError } from '@ohos.base';  
  
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
try {  
    privacyManager.getPermissionUsedRecord(request).then((data) => {  
        console.log(`getPermissionUsedRecord success, data->${JSON.stringify(data)}`);  
    }).catch((err: BusinessError) => {  
        console.log(`getPermissionUsedRecord fail, err->${JSON.stringify(err)}`);  
    });  
} catch(err) {  
    console.log(`catch err->${JSON.stringify(err)}`);  
}  
    
```    
  
    
## startUsingPermission    
应用开始使用某项权限，可监听应用在前后台使用权限，并将使用权限的记录落盘，由系统服务调用。  
 **调用形式：**     
    
- startUsingPermission(tokenID: number, permissionName: Permissions): Promise\<void>    
起始版本： 9    
- startUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken  
 **需要权限：** ohos.permission.PERMISSION_USED_STATS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tokenID | number | true | 调用方的应用身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得。 |  
| permissionName | Permissions | true | 需要使用的权限名，合法的权限名取值可在[应用权限列表](../../security/permission-list.md)中查询。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当开始使用权限成功时，err为undefined；否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
| 12100001 | The tokenID is 0, permissionName is longer than 256 bytes, or the count value is invalid. |  
| 12100002 | The specified tokenID does not exist or refer to an application process. |  
| 12100003 | The specified permission does not exist or is not an user_grant permission. |  
| 12100004 | The interface is called repeatedly with the same input. It means the application specified by the tokenID has been using the specified permission. |  
| 12100007 | Service is abnormal. |  
| 12100008 | Out of memory. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import privacyManager from '@ohos.privacyManager';  
import { BusinessError } from '@ohos.base';  
  
let tokenID: number = 0; // 可以通过getApplicationInfo获取accessTokenId  
try {  
    privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', (err: BusinessError, data: void) => {  
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
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import privacyManager from '@ohos.privacyManager';  
import { BusinessError } from '@ohos.base';  
  
let tokenID: number = 0; // 可以通过getApplicationInfo获取accessTokenId  
try {  
    privacyManager.startUsingPermission(tokenID, 'ohos.permission.READ_AUDIO').then(() => {  
        console.log('startUsingPermission success');  
    }).catch((err: BusinessError) => {  
        console.log(`startUsingPermission fail, err->${JSON.stringify(err)}`);  
    });  
} catch(err) {  
    console.log(`catch err->${JSON.stringify(err)}`);  
}  
    
```    
  
    
## stopUsingPermission    
应用停止使用某项权限，与Start对应，由系统服务调用。  
 **调用形式：**     
    
- stopUsingPermission(tokenID: number, permissionName: Permissions): Promise\<void>    
起始版本： 9    
- stopUsingPermission(tokenID: number, permissionName: Permissions, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken  
 **需要权限：** ohos.permission.PERMISSION_USED_STATS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tokenID | number | true | 调用方的应用身份标识。可通过应用的[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)获得。  |  
| permissionName | Permissions | true | 需要使用的权限名，合法的权限名取值可在[应用权限列表](../../security/permission-list.md)中查询。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当停止使用权限成功时，err为undefined；否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
| 12100001 | The tokenID is 0, permissionName is longer than 256 bytes, or the count value is invalid. |  
| 12100002 | The specified tokenID does not exist or refer to an application process. |  
| 12100003 | The specified permission does not exist or is not an user_grant permission. |  
| 12100004 | The interface is not used with |  
| 12100007 | Service is abnormal. |  
| 12100008 | Out of memory. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import privacyManager from '@ohos.privacyManager';  
import { BusinessError } from '@ohos.base';  
  
let tokenID: number = 0; // 可以通过getApplicationInfo获取accessTokenId  
try {  
    privacyManager.stopUsingPermission(tokenID, 'ohos.permission.READ_AUDIO', (err: BusinessError, data: void) => {  
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
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import privacyManager from '@ohos.privacyManager';  
import { BusinessError } from '@ohos.base';  
  
let tokenID: number = 0; // 可以通过getApplicationInfo获取accessTokenId  
try {  
    privacyManager.stopUsingPermission(tokenID, 'ohos.permission.READ_AUDIO').then(() => {  
        console.log('stopUsingPermission success');  
    }).catch((err: BusinessError) => {  
        console.log(`stopUsingPermission fail, err->${JSON.stringify(err)}`);  
    });  
} catch(err) {  
    console.log(`catch err->${JSON.stringify(err)}`);  
}  
    
```    
  
    
## on('activeStateChange')    
订阅指定权限列表的权限使用状态变更事件。允许相同permissionList订阅多个callback。  不允许存在交集的permissionList订阅相同callback  
 **调用形式：**     
    
- on(     type: 'activeStateChange',     permissionList: Array\<Permissions>,     callback: Callback\<ActiveChangeResponse>   ): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken  
 **需要权限：** ohos.permission.PERMISSION_USED_STATS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 订阅事件类型，固定为'activeStateChange'，权限使用状态变更事件。 |  
| permissionList | Array<Permissions> | true | 订阅的权限名列表，为空时表示订阅所有的权限使用状态变化，合法的权限名取值可在[应用权限列表](../../security/permission-list.md)中查询。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 阅指定权限使用状态变更事件的回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
| 12100001 | The parameter is invalid. The tokenID is 0, or the string size of permissionName is larger than 256. |  
| 12100004 | The interface is called repeatedly with the same input. |  
| 12100005 | The registration time has exceeded the limitation. |  
| 12100007 | Service is abnormal. |  
| 12100008 | Out of memory. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import privacyManager, { Permissions } from '@ohos.privacyManager';  
import { BusinessError } from '@ohos.base';  
  
let permissionList: Array<Permissions> = [];  
try {  
    privacyManager.on('activeStateChange', permissionList, (data: privacyManager.ActiveChangeResponse) => {  
        console.debug('receive permission state change, data:' + JSON.stringify(data));  
    });  
} catch(err) {  
    console.log(`catch err->${JSON.stringify(err)}`);  
}  
    
```    
  
    
## off('activeStateChange')    
取消订阅指定权限列表的权限使用状态变更事件。  取消订阅不传callback时，批量删除permissionList下面的所有callback。  
 **调用形式：**     
    
- off(     type: 'activeStateChange',     permissionList: Array\<Permissions>,     callback?: Callback\<ActiveChangeResponse>   ): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken  
 **需要权限：** ohos.permission.PERMISSION_USED_STATS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消订阅事件类型，固定为'activeStateChange'，权限使用状态变更事件。  |  
| permissionList | Array<Permissions> | true | 取消订阅的权限名列表，为空时表示订阅所有的权限状态变化，必须与on的输入一致，合法的权限名取值可在[应用权限列表](../../security/permission-list.md)中查询。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅指定tokenId与指定权限名状态变更事件的回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
| 12100001 | The permissionNames in the list are all invalid, or the list size exceeds 1024 bytes. |  
| 12100004 | The interface is not used together with 'on |  
| 12100007 | Service is abnormal. |  
| 12100008 | Out of memory. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import privacyManager, { Permissions } from '@ohos.privacyManager';  
  
let permissionList: Array<Permissions> = [];  
try {  
    privacyManager.off('activeStateChange', permissionList);  
}catch(err) {  
    console.log(`catch err->${JSON.stringify(err)}`);  
}  
    
```    
  
    
## PermissionActiveStatus    
表示权限使用状态变化类型的枚举。    
    
 **系统能力:**  SystemCapability.Security.AccessToken    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PERM_INACTIVE | 0 | 表示未使用权限。 |  
| PERM_ACTIVE_IN_FOREGROUND | 1 | 表示前台使用权限。 |  
| PERM_ACTIVE_IN_BACKGROUND | 2 | 表示后台使用权限。 |  
    
## ActiveChangeResponse    
表示某次权限使用状态变化的详情。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken    
### 属性    
 **系统能力:**  SystemCapability.Security.AccessToken    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| tokenId | number | false | true |  被订阅的应用身份标识   |  
| permissionName | Permissions | false | true | 权限使用状态发生变化的权限名 |  
| deviceId | string | false | true | 设备号   |  
| activeStatus | PermissionActiveStatus | false | true | 权限使用状态变化类型     |  
    
## PermissionUsageFlag    
使用记录的查询方式的枚举。    
    
 **系统能力:**  SystemCapability.Security.AccessToken    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FLAG_PERMISSION_USAGE_SUMMARY | 0 | 表示查询总览数据。 |  
| FLAG_PERMISSION_USAGE_DETAIL | 1 | 表示查询详细数据。         |  
 |  
    
## PermissionUsedRequest    
表示使用记录的查询请求。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken    
### 属性    
 **系统能力:**  SystemCapability.Security.AccessToken    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| tokenId | number | false | false | 目标应用的身份标识。<br/> 默认查询所有应用。     |  
| isRemote | boolean | false | false | 指定是否查询远端设备。<br/> 默认值：false，默认查询本端设备。 |  
| deviceId | string | false | false | 目标应用所在设备的ID。<br/> 默认设备ID为本端设备ID。 |  
| bundleName | string | false | false | 目标应用的包名。<br/> 默认查询所有应用。 |  
| permissionNames | Array<Permissions> | false | false | 需要查询的权限集合。<br/> 默认查询所有权限的使用记录。  |  
| beginTime | number | false | false | 查询的起始时间，单位：ms。<br/>默认值0，不设定起始时间。 |  
| endTime | number | false | false | 查询的终止时间，单位：ms。<br/>默认值0，不设定终止时间。 |  
| flag | PermissionUsageFlag | false | true | 指定查询方式。 |  
    
## PermissionUsedResponse    
表示所有应用的访问记录。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken    
### 属性    
 **系统能力:**  SystemCapability.Security.AccessToken    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| beginTime | number | false | true | 查询记录的起始时间，单位：ms。 |  
| endTime | number | false | true | 查询记录的终止时间，单位：ms。 |  
| bundleRecords | Array<BundleUsedRecord> | false | true |  应用的权限使用记录集合。 |  
    
## BundleUsedRecord    
某个应用的访问记录。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken    
### 属性    
 **系统能力:**  SystemCapability.Security.AccessToken    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| tokenId | number | false | true | 目标应用的身份标识。 |  
| isRemote | boolean | false | true | 默认值false。 |  
| deviceId | string | false | true | 目标应用所在设备的ID。     |  
| bundleName | string | false | true | 目标应用的包名。 |  
| permissionRecords | Array<PermissionUsedRecord> | false | true | 每个应用的权限使用记录集合。          |  
    
## PermissionUsedRecord    
某个权限的访问记录。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken    
### 属性    
 **系统能力:**  SystemCapability.Security.AccessToken    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| permissionName | Permissions | false | true | 权限名。 |  
| accessCount | number | false | true | 该权限访问总次数。 |  
| rejectCount | number | false | true | 该权限拒绝总次数。 |  
| lastAccessTime | number | false | true | 最后一次访问时间，单位：ms。 |  
| lastRejectTime | number | false | true | 最后一次拒绝时间，单位：ms。 |  
| lastAccessDuration | number | false | true | 最后一次访问时长，单位：ms。 |  
| accessRecords | Array<UsedRecordDetail> | false | true | 访问记录集合，当flag为FLAG_PERMISSION_USAGE_DETAIL时生效，默认查询10条。 |  
| rejectRecords | Array<UsedRecordDetail> | false | true | 拒绝记录集合，当flag为FLAG_PERMISSION_USAGE_DETAIL时生效，默认查询10条。  |  
    
## UsedRecordDetail    
单次访问记录详情。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken    
### 属性    
 **系统能力:**  SystemCapability.Security.AccessToken    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| status | number | false | true | 访问状态。      |  
| timestamp | number | false | true | 访问时的时间戳，单位：ms。 |  
| accessDuration | number | false | true | 访问时长，单位：ms。  |  
