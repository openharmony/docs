# @ohos.abilityAccessCtrl    
  
  
程序访问控制提供程序的权限管理能力，包括鉴权、授权和取消授权等。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import abilityAccessCtrl from '@ohos.abilityAccessCtrl'    
```  
    
## createAtManager    
访问控制管理：获取访问控制模块对象。  
 **调用形式：**     
- createAtManager(): AtManager  
  
 **系统能力:**  SystemCapability.Security.AccessToken    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AtManager | 获取访问控制模块的实例。 |  
    
 **示例代码：**   
```ts    
let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();    
```    
  
    
## AtManager    
管理访问控制模块的实例。  
 **系统能力:**  SystemCapability.Security.AccessToken    
### verifyAccessToken<sup>(deprecated)</sup>    
校验应用是否授予权限。使用Promise异步回调。  
 **调用形式：**     
- verifyAccessToken(tokenID: number, permissionName: string): Promise\<GrantStatus>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.abilityAccessCtrl.AtManager#checkAccessToken。  
 **系统能力:**  SystemCapability.Security.AccessToken    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tokenID<sup>(deprecated)</sup> | number | true | 要校验的目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)获得。 |  
| permissionName<sup>(deprecated)</sup> | string | true | 需要校验的权限名称，合法的权限名取值可在[应用权限列表](../../security/permission-list.md)中查询。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<GrantStatus> | Promise对象。返回授权状态结果。 |  
    
 **示例代码：**   
```ts    
import abilityAccessCtrl, { Permissions } from '@ohos.abilityAccessCtrl';  
import { BusinessError } from '@ohos.base';  
  
let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();  
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取,普通应用可以通过bundleManager.getBundleInfoForSelf获取  
let permissionName: Permissions = 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS';  
try {  
    atManager.verifyAccessToken(tokenID, permissionName).then((data: abilityAccessCtrl.GrantStatus) => {  
        console.log(`promise: data->${JSON.stringify(data)}`);  
    }).catch((err: BusinessError) => {  
        console.log(`verifyAccessToken fail, err->${JSON.stringify(err)}`);  
    });  
}catch(err) {  
    console.log(`catch err->${JSON.stringify(err)}`);  
}  
    
```    
  
    
### verifyAccessToken<sup>(9+)</sup>    
校验应用是否授予权限。使用Promise异步回调。  
 **调用形式：**     
    
- verifyAccessToken(tokenID: number, permissionName: Permissions): Promise\<GrantStatus>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Security.AccessToken    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tokenID | number | true | 要校验的目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)获得。 |  
| permissionName | Permissions | true | 需要校验的权限名称，合法的权限名取值可在[应用权限列表](../../security/permission-list.md)中查询。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<GrantStatus> | Promise对象。返回授权状态结果。 |  
    
 **示例代码：**   
```ts    
import abilityAccessCtrl, { Permissions } from '@ohos.abilityAccessCtrl';  
import { BusinessError } from '@ohos.base';  
  
let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();  
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取,普通应用可以通过bundleManager.getBundleInfoForSelf获取  
let permissionName: Permissions = 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS';  
try {  
    atManager.verifyAccessToken(tokenID, permissionName).then((data: abilityAccessCtrl.GrantStatus) => {  
        console.log(`promise: data->${JSON.stringify(data)}`);  
    }).catch((err: BusinessError) => {  
        console.log(`verifyAccessToken fail, err->${JSON.stringify(err)}`);  
    });  
}catch(err) {  
    console.log(`catch err->${JSON.stringify(err)}`);  
}  
    
```    
  
    
### verifyAccessTokenSync<sup>(9+)</sup>    
校验应用是否被授予权限，同步返回结果。  
 **调用形式：**     
- verifyAccessTokenSync(tokenID: number, permissionName: Permissions): GrantStatus  
  
 **系统能力:**  SystemCapability.Security.AccessToken    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tokenID | number | true | 要校验应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)获得。 |  
| permissionName | Permissions | true | 需要校验的权限名称，合法的权限名取值可在[应用权限列表](../../security/permission-list.md)中查询。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| GrantStatus | 枚举实例，返回授权状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12100001 | The parameter is invalid. The tokenID is 0, or the string size of permissionName is larger than 256. |  
    
 **示例代码：**   
```ts    
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';  
let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取,普通应用可以通过bundleManager.getBundleInfoForSelf获取let data: abilityAccessCtrl.GrantStatus = atManager.verifyAccessTokenSync(tokenID, 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS');console.log(`data->${JSON.stringify(data)}`);    
```    
  
    
### checkAccessToken<sup>(9+)</sup>    
校验应用是否授予权限。使用Promise异步回调。  
 **调用形式：**     
    
- checkAccessToken(tokenID: number, permissionName: Permissions): Promise\<GrantStatus>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Security.AccessToken    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tokenID | number | true | 要校验的目标应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)获得。 |  
| permissionName | Permissions | true | 需要校验的权限名称，合法的权限名取值可在[应用权限列表](../../security/permission-list.md)中查询。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<GrantStatus> | Promise对象。返回授权状态结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12100001 | The parameter is invalid. The tokenID is 0, or the string size of permissionName is larger than 256. |  
    
 **示例代码：**   
```ts    
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';  
import { BusinessError } from '@ohos.base';  
  
let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();  
let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取,普通应用可以通过bundleManager.getBundleInfoForSelf获取  
try {  
    atManager.checkAccessToken(tokenID, 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS').then((data: abilityAccessCtrl.GrantStatus) => {  
        console.log(`checkAccessToken success, data->${JSON.stringify(data)}`);  
    }).catch((err: BusinessError) => {  
        console.log(`checkAccessToken fail, err->${JSON.stringify(err)}`);  
    });  
} catch(err) {  
    console.log(`catch err->${JSON.stringify(err)}`);  
}  
    
```    
  
    
### checkAccessTokenSync<sup>(10+)</sup>    
校验应用是否被授予权限，同步返回结果。  
 **调用形式：**     
- checkAccessTokenSync(tokenID: number, permissionName: Permissions): GrantStatus  
  
 **系统能力:**  SystemCapability.Security.AccessToken    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tokenID | number | true |  要校验应用的身份标识。可通过应用的[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)获得。 |  
| permissionName | Permissions | true | 需要校验的权限名称，合法的权限名取值可在[应用权限列表](../../security/permission-list.md)中查询。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| GrantStatus | 枚举实例，返回授权状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12100001 | The parameter is invalid. The tokenID is 0, or the string size of permissionName is larger than 256. |  
    
 **示例代码：**   
```ts    
import abilityAccessCtrl, { Permissions } from '@ohos.abilityAccessCtrl';  
let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();let tokenID: number = 0; // 系统应用可以通过bundleManager.getApplicationInfo获取,普通应用可以通过bundleManager.getBundleInfoForSelf获取let permissionName: Permissions = 'ohos.permission.GRANT_SENSITIVE_PERMISSIONS';let data: abilityAccessCtrl.GrantStatus = atManager.checkAccessTokenSync(tokenID, permissionName);console.log(`data->${JSON.stringify(data)}`);    
```    
  
    
### requestPermissionsFromUser<sup>(9+)</sup>  
 **调用形式：**     
- requestPermissionsFromUser(       context: Context,       permissionList: Array\<Permissions>,       requestCallback: AsyncCallback\<PermissionRequestResult>     ): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Security.AccessToken    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true |  |  
| permissionList | Array<Permissions> | true |  |  
| requestCallback | AsyncCallback<PermissionRequestResult> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12100001 |  |  
    
 **示例代码：**   
```ts    
import abilityAccessCtrl, { Context, PermissionRequestResult } from '@ohos.abilityAccessCtrl';  
import { BusinessError } from '@ohos.base';  
  
let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();  
try {  
    let context = getContext(this);  
    atManager.requestPermissionsFromUser(context, ['ohos.permission.CAMERA'], (err: BusinessError, data: PermissionRequestResult)=>{  
    console.info('data:' + JSON.stringify(data));  
    console.info('data permissions:' + data.permissions);  
    console.info('data authResults:' + data.authResults);  
    });  
} catch(err) {  
    console.log(`catch err->${JSON.stringify(err)}`);  
}  
    
```    
  
    
### requestPermissionsFromUser<sup>(9+)</sup>    
用于UIAbility拉起弹框请求用户授权。使用promise异步回调。  
 **调用形式：**     
    
- requestPermissionsFromUser(context: Context, permissionList: Array\<Permissions>): Promise\<PermissionRequestResult>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Security.AccessToken    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 请求权限的UIAbility的UIAbilityContext。 |  
| permissionList | Array<Permissions> | true | 需要校验的权限名称，合法的权限名取值可在[应用权限列表](../../security/permission-list.md)中查询。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<PermissionRequestResult> | 返回一个Promise，包含接口的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12100001 | The parameter is invalid. The context is invalid when it does not belong to the application itself. |  
    
 **示例代码：**   
修改EntryAbility.ets和导入GlobalThis等步骤同上，此处不再重复  
```ts    
import abilityAccessCtrl, { Context, PermissionRequestResult } from '@ohos.abilityAccessCtrl';  
import { BusinessError } from '@ohos.base';  
import { GlobalThis } from '../utils/globalThis';  
  
let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();  
try {  
    let context: Context = GlobalThis.getInstance().getContext('context');  
    atManager.requestPermissionsFromUser(context, ['ohos.permission.CAMERA']).then((data: PermissionRequestResult) => {  
        console.info('data:' + JSON.stringify(data));  
        console.info('data permissions:' + data.permissions);  
        console.info('data authResults:' + data.authResults);  
    }).catch((err: BusinessError) => {  
        console.info('data:' + JSON.stringify(err));  
    })  
} catch(err) {  
    console.log(`catch err->${JSON.stringify(err)}`);  
}  
    
```    
  
    
## GrantStatus    
表示授权状态的枚举。    
    
 **系统能力:**  SystemCapability.Security.AccessToken    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PERMISSION_DENIED | -1 | 表示未授权。 |  
| PERMISSION_GRANTED | 0 | 表示已授权。 |  
