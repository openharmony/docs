# @ohos.abilityAccessCtrl    
  
  
程序访问控制提供程序的权限管理能力，包括鉴权、授权和取消授权等。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import abilityAccessCtrl from '@ohos.abilityAccessCtrl'    
```  
    
## AtManager    
管理访问控制模块的实例。  
 **系统能力:**  SystemCapability.Security.AccessToken    
### grantUserGrantedPermission    
授予应用user_grant权限。使用Promise异步回调。  
 **调用形式：**     
    
- grantUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number): Promise\<void>    
起始版本： 8    
- grantUserGrantedPermission(       tokenID: number,       permissionName: Permissions,       permissionFlags: number,       callback: AsyncCallback\<void>     ): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken  
 **需要权限：** ohos.permission.GRANT_SENSITIVE_PERMISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tokenID | number | true | 目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)获得。 |  
| permissionName | Permissions | true | 被授予的权限名称，合法的权限名取值可在[应用权限列表](../../security/permission-list.md)中查询。  |  
| permissionFlags | number | true | 授权选项<br>- 0表示权限未经过用户主动设置。<br>- 1表示当次用户若选择禁止该权限，下次权限弹窗仍可以弹出申请用户授权。<br>- 2表示当次用户若选择禁止该权限，下次不会再弹出权限弹窗，需要用户在setting的权限管理中进行授权。<br>- 4表示当次权限设置为系统授权，用户不可更改这个权限授权状态。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
| 12100001 | The parameter is invalid. The tokenID is 0, or the string size of permissionName is larger than 256, or the flags value is invalid. |  
| 12100002 | The specified tokenID does not exist. |  
| 12100003 | The specified permission does not exist. |  
| 12100006 | The application specified by the tokenID is not allowed to be granted with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |  
| 12100007 | Service is abnormal. |  
    
 **示例代码：**   
```ts    
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';  
import { BusinessError } from '@ohos.base';  
  
let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();  
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取,普通应用可以通过bundleManager.getBundleInfoForSelf获取  
let permissionFlags: number = 1;  
try {  
    atManager.grantUserGrantedPermission(tokenID, 'ohos.permission.READ_AUDIO', permissionFlags).then(() => {  
        console.log('grantUserGrantedPermission success');  
    }).catch((err: BusinessError) => {  
        console.log(`grantUserGrantedPermission fail, err->${JSON.stringify(err)}`);  
    });  
} catch(err) {  
    console.log(`catch err->${JSON.stringify(err)}`);  
}  
    
```    
  
    
### revokeUserGrantedPermission    
撤销应用user_grant权限。使用Promise异步回调。  
 **调用形式：**     
    
- revokeUserGrantedPermission(tokenID: number, permissionName: Permissions, permissionFlags: number): Promise\<void>    
起始版本： 8    
- revokeUserGrantedPermission(       tokenID: number,       permissionName: Permissions,       permissionFlags: number,       callback: AsyncCallback\<void>     ): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken  
 **需要权限：** ohos.permission.REVOKE_SENSITIVE_PERMISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tokenID | number | true | 目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)获得。 |  
| permissionName | Permissions | true | 被撤销的权限名称，合法的权限名取值可在[应用权限列表](../../security/permission-list.md)中查询。 |  
| permissionFlags | number | true | 授权选项<br>- 0表示权限未经过用户主动设置。<br>- 1表示当次用户若选择禁止该权限，下次权限弹窗仍可以弹出申请用户授权。<br>- 2表示当次用户若选择禁止该权限，下次不会再弹出权限弹窗，需要用户在setting的权限管理中进行授权。<br>- 4表示当次权限设置为系统授权，用户不可更改这个权限授权状态。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
| 12100001 | The parameter is invalid. The tokenID is 0, or the string size of permissionName is larger than 256, or the flags value is invalid. |  
| 12100002 | The specified tokenID does not exist. |  
| 12100003 | The specified permission does not exist. |  
| 12100006 | The application specified by the tokenID is not allowed to be revoked with the specified permission. Either the application is a sandbox or the tokenID is from a remote device. |  
| 12100007 | Service is abnormal. |  
    
 **示例代码：**   
```ts    
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';  
import { BusinessError } from '@ohos.base';  
  
let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();  
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取,普通应用可以通过bundleManager.getBundleInfoForSelf获取  
let permissionFlags: number = 1;  
try {  
    atManager.revokeUserGrantedPermission(tokenID, 'ohos.permission.READ_AUDIO', permissionFlags).then(() => {  
        console.log('revokeUserGrantedPermission success');  
    }).catch((err: BusinessError) => {  
        console.log(`revokeUserGrantedPermission fail, err->${JSON.stringify(err)}`);  
    });  
} catch(err) {  
    console.log(`catch err->${JSON.stringify(err)}`);  
}  
    
```    
  
    
### getPermissionFlags    
获取指定应用的指定权限的flag。使用Promise异步回调。  
 **调用形式：**     
    
- getPermissionFlags(tokenID: number, permissionName: Permissions): Promise\<number>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken  
 **需要权限：** ohos.permission.GET_SENSITIVE_PERMISSIONS or ohos.permission.GRANT_SENSITIVE_PERMISSIONS or ohos.permission.REVOKE_SENSITIVE_PERMISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tokenID | number | true | 目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)获得。  |  
| permissionName | Permissions | true | 查询的权限名称，合法的权限名取值可在[应用权限列表](../../security/permission-list.md)中查询。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<number> | Promise对象。返回查询结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
| 12100001 | The parameter is invalid. The tokenID is 0, or the string size of permissionName is larger than 256. |  
| 12100002 | The specified tokenID does not exist. |  
| 12100003 | The specified permission does not exist. |  
| 12100006 | The operation is not allowed. Either the application is a sandbox or the tokenID is from a remote device. |  
| 12100007 | Service is abnormal. |  
    
 **示例代码：**   
```ts    
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';  
import { BusinessError } from '@ohos.base';  
  
let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();  
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取,普通应用可以通过bundleManager.getBundleInfoForSelf获取  
try {  
    atManager.getPermissionFlags(tokenID, 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS').then((data: number) => {  
        console.log(`getPermissionFlags success, data->${JSON.stringify(data)}`);  
    }).catch((err: BusinessError) => {  
        console.log(`getPermissionFlags fail, err->${JSON.stringify(err)}`);  
    });  
} catch(err) {  
    console.log(`catch err->${JSON.stringify(err)}`);  
}  
    
```    
  
    
### getVersion<sup>(9+)</sup>    
获取当前权限管理的数据版本。使用Promise异步回调。  
 **调用形式：**     
    
- getVersion(): Promise\<number>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<number> | Promise对象。返回查询到的版本号。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
```ts    
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';  
let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();let promise = atManager.getVersion();promise.then((data: number) => {    console.log(`promise: data->${JSON.stringify(data)}`);});    
```    
  
    
### on('permissionStateChange')<sup>(9+)</sup>    
订阅指定tokenId列表与权限列表的权限状态变更事件。  允许指定tokenId列表与权限列表订阅多个callback。  不允许存在交集的tokenId列表与权限列表订阅相同callback。  
 **调用形式：**     
    
- on(       type: 'permissionStateChange',       tokenIDList: Array\<number>,       permissionList: Array\<Permissions>,       callback: Callback\<PermissionStateChangeInfo>     ): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken  
 **需要权限：** ohos.permission.GET_SENSITIVE_PERMISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  订阅事件类型，固定为'permissionStateChange'，权限状态变更事件。 |  
| tokenIDList | Array<number> | true | 订阅的tokenId列表，为空时表示订阅所有的应用的权限状态变化。 |  
| permissionList | Array<Permissions> | true | 订阅的权限名列表，为空时表示订阅所有的权限状态变化，合法的权限名取值可在[应用权限列表](../../security/permission-list.md)中查询。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
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
```ts    
import abilityAccessCtrl, { Permissions } from '@ohos.abilityAccessCtrl';  
import bundleManager from '@ohos.bundle.bundleManager';  
  
let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();  
let appInfo: bundleManager.ApplicationInfo = bundleManager.getApplicationInfoSync('com.example.myapplication', 0, 100);  
let tokenIDList: Array<number> = [appInfo.accessTokenId];  
let permissionList: Array<Permissions> = ['ohos.permission.DISTRIBUTED_DATASYNC'];  
try {  
    atManager.on('permissionStateChange', tokenIDList, permissionList, (data: abilityAccessCtrl.PermissionStateChangeInfo) => {  
        console.debug('receive permission state change, data:' + JSON.stringify(data));  
    });  
} catch(err) {  
    console.log(`catch err->${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('permissionStateChange')<sup>(9+)</sup>    
取消订阅指定tokenId列表与权限列表的权限状态变更事件，使用callback回调异步返回结果。  取消订阅不传callback时，批量删除tokenIDList和permissionList下面的所有callback。  
 **调用形式：**     
    
- off(       type: 'permissionStateChange',       tokenIDList: Array\<number>,       permissionList: Array\<Permissions>,       callback?: Callback\<PermissionStateChangeInfo>     ): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken  
 **需要权限：** ohos.permission.GET_SENSITIVE_PERMISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 订阅事件类型，固定为'permissionStateChange'，权限状态变更事件。 |  
| tokenIDList | Array<number> | true | 订阅的tokenId列表，为空时表示订阅所有的应用的权限状态变化，必须与on的输入一致。 |  
| permissionList | Array<Permissions> | true | 订阅的权限名列表，为空时表示订阅所有的权限状态变化，必须与on的输入一致，合法的权限名取值可在[应用权限列表](../../security/permission-list.md)中查询。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 202 |  |  
| 12100001 | The parameter is invalid. The tokenIDs or permissionNames in the list are all invalid. |  
| 12100004 | The interface is not used together with 'on'. |  
| 12100007 | Service is abnormal. |  
| 12100008 | Out of memory. |  
    
 **示例代码：**   
```ts    
import abilityAccessCtrl, { Permissions } from '@ohos.abilityAccessCtrl';  
import bundleManager from '@ohos.bundle.bundleManager';  
  
let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();  
let appInfo: bundleManager.ApplicationInfo = bundleManager.getApplicationInfoSync('com.example.myapplication', 0, 100);  
let tokenIDList: Array<number> = [appInfo.accessTokenId];  
let permissionList: Array<Permissions> = ['ohos.permission.DISTRIBUTED_DATASYNC'];  
try {  
    atManager.off('permissionStateChange', tokenIDList, permissionList);  
} catch(err) {  
    console.log(`catch err->${JSON.stringify(err)}`);  
}  
    
```    
  
    
## PermissionStateChangeType<sup>(9+)</sup>    
表示权限授权状态变化操作类型的枚举。    
    
 **系统能力:**  SystemCapability.Security.AccessToken    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PERMISSION_REVOKED_OPER | 0 | 表示权限取消操作。 |  
| PERMISSION_GRANTED_OPER | 1 | 表示权限授予操作。 |  
    
## PermissionStateChangeInfo<sup>(9+)</sup>    
表示某次权限授权状态变化的详情。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Security.AccessToken    
### 属性    
 **系统能力:**  SystemCapability.Security.AccessToken    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| change<sup>(9+)</sup> | PermissionStateChangeType | false | true | 权限授权状态变化类型。    |  
| tokenID<sup>(9+)</sup> | number | false | true | 被订阅的应用身份标识。 |  
| permissionName<sup>(9+)</sup> | Permissions | false | true | 当前授权状态发生变化的权限名，合法的权限名取值可在[应用权限列表](../../security/permission-list.md)中查询。 |  
