# @ohos.bundle.defaultAppManager    
本模块提供查询默认应用的能力，支持查询当前应用是否是默认应用。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import defaultAppManager from '@ohos.bundle.defaultAppManager'    
```  
    
## getDefaultApplication    
以异步方法根据系统已定义的应用类型或者符合媒体类型格式（type/subtype）的文件类型获取默认应用信息，使用Promise形式返回结果。  
 **调用形式：**     
    
- getDefaultApplication(type: string, userId: number, callback: AsyncCallback\<BundleInfo>): void    
起始版本： 9    
- getDefaultApplication(type: string, callback: AsyncCallback\<BundleInfo>): void    
起始版本： 9    
- getDefaultApplication(type: string, userId?: number): Promise\<BundleInfo>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.DefaultApp  
 **需要权限：** ohos.permission.GET_DEFAULT_APPLICATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 要查询的应用类型，取ApplicationType中的值。<br/> |  
| userId | number | true | 用户ID。默认值：调用方所在用户。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 程序启动作为入参的回调函数，返回包信息。 |  
| Promise<BundleInfo> | Promise形式返回默认应用包信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700004 | The specified user ID is not found. |  
| 17700023 | The specified default app does not exist. |  
| 17700025 | The specified type is invalid. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import defaultAppMgr from '@ohos.bundle.defaultAppManager';  
import { BusinessError } from '@ohos.base';  
  
let userId = 100;  
defaultAppMgr.getDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, userId, (err: BusinessError, data) => {  
  if (err) {  
    console.error('Operation failed. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Operation successful. bundleInfo:' + JSON.stringify(data));  
});  
  
defaultAppMgr.getDefaultApplication("image/png", userId, (err: BusinessError, data) => {  
  if (err) {  
    console.error('Operation failed. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Operation successful. bundleInfo:' + JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import defaultAppMgr from '@ohos.bundle.defaultAppManager';  
import { BusinessError } from '@ohos.base';  
  
defaultAppMgr.getDefaultApplication(defaultAppMgr.ApplicationType.BROWSER)  
  .then((data) => {  
    console.info('Operation successful. bundleInfo: ' + JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.error('Operation failed. Cause: ' + JSON.stringify(error));  
  });  
  
defaultAppMgr.getDefaultApplication("image/png")  
  .then((data) => {  
    console.info('Operation successful. bundleInfo: ' + JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.error('Operation failed. Cause: ' + JSON.stringify(error));  
  });  
    
```    
  
    
## getDefaultApplicationSync<sup>(10+)</sup>    
以同步方法根据系统已定义的应用类型或者符合媒体类型格式（type/subtype）的文件类型获取默认应用信息，使用BundleInfo返回结果。  
 **调用形式：**     
- getDefaultApplicationSync(type: string, userId?: number): BundleInfo  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.DefaultApp  
 **需要权限：** ohos.permission.GET_DEFAULT_APPLICATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 要查询的应用类型，取ApplicationType中的值。<br/> |  
| userId | number | false | 用户ID。默认值：调用方所在用户。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| BundleInfo | 返回的默认应用包信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700004 | The specified user ID is not found. |  
| 17700023 | The specified default app does not exist. |  
| 17700025 | The specified type is invalid. |  
    
 **示例代码：**   
```ts    
import defaultAppMgr from '@ohos.bundle.defaultAppManager';  
try {  
  let data = defaultAppMgr.getDefaultApplicationSync(defaultAppMgr.ApplicationType.BROWSER)  
  console.info('Operation successful. bundleInfo: ' + JSON.stringify(data));  
} catch(error) {  
  console.error('Operation failed. Cause: ' + JSON.stringify(error));  
};  
  
try {  
  let data = defaultAppMgr.getDefaultApplicationSync("image/png")  
  console.info('Operation successful. bundleInfo: ' + JSON.stringify(data));  
} catch(error) {  
  console.error('Operation failed. Cause: ' + JSON.stringify(error));  
};  
    
```    
  
    
## setDefaultApplication    
以异步方法根据系统已定义的应用类型或者符合媒体类型格式（type/subtype）的文件类型设置默认应用，使用Promise形式返回结果。  
 **调用形式：**     
    
- setDefaultApplication(type: string,     elementName: ElementName, userId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setDefaultApplication(type: string, elementName: ElementName, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setDefaultApplication(type: string, elementName: ElementName, userId?: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.DefaultApp  
 **需要权限：** ohos.permission.SET_DEFAULT_APPLICATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 要查询的应用类型，取ApplicationType中的值。<br/> |  
| elementName | ElementName | true | 要设置为默认应用的组件信息。 |  
| userId | number | true | 用户ID。默认值：调用方所在用户。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 程序启动作为入参的回调函数。 |  
| Promise<void> | Promise对象，无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700004 | The specified user ID is not found. |  
| 17700025 | The specified type is invalid. |  
| 17700028 | The specified ability does not match the type. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import defaultAppMgr from '@ohos.bundle.defaultAppManager';  
import { BusinessError } from '@ohos.base';  
  
let userId = 100;  
defaultAppMgr.setDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, {  
  bundleName: "com.example.myapplication",  
  moduleName: "module01",  
  abilityName: "EntryAbility"  
}, userId, (err: BusinessError, data) => {  
  if (err) {  
    console.error('Operation failed. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Operation successful.');  
});  
  
defaultAppMgr.setDefaultApplication("image/png", {  
  bundleName: "com.example.myapplication",  
  moduleName: "module01",  
  abilityName: "EntryAbility"  
}, userId, (err: BusinessError, data) => {  
  if (err) {  
    console.error('Operation failed. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Operation successful.');  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import defaultAppMgr from '@ohos.bundle.defaultAppManager';  
import { BusinessError } from '@ohos.base';  
  
defaultAppMgr.setDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, {  
  bundleName: "com.example.myapplication",  
  moduleName: "module01",  
  abilityName: "EntryAbility"  
}).then((data) => {  
  console.info('Operation successful.');  
}).catch((error: BusinessError) => {  
  console.error('Operation failed. Cause: ' + JSON.stringify(error));  
});  
  
let userId = 100;  
defaultAppMgr.setDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, {  
  bundleName: "com.example.myapplication",  
  moduleName: "module01",  
  abilityName: "EntryAbility"  
}, userId).then((data) => {  
  console.info('Operation successful.');  
}).catch((error: BusinessError) => {  
  console.error('Operation failed. Cause: ' + JSON.stringify(error));  
});  
  
defaultAppMgr.setDefaultApplication("image/png", {  
  bundleName: "com.example.myapplication",  
  moduleName: "module01",  
  abilityName: "EntryAbility"  
}, userId).then((data) => {  
  console.info('Operation successful.');  
}).catch((error: BusinessError) => {  
  console.error('Operation failed. Cause: ' + JSON.stringify(error));  
});  
    
```    
  
    
## setDefaultApplicationSync<sup>(10+)</sup>    
以同步方法根据系统已定义的应用类型或者符合媒体类型格式（type/subtype）的文件类型设置默认应用。  
。  
 **调用形式：**     
- setDefaultApplicationSync(type: string, elementName: ElementName, userId?: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.DefaultApp  
 **需要权限：** ohos.permission.SET_DEFAULT_APPLICATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 要设置的应用类型，取[ApplicationType](#defaultappmgrapplicationtype)中的值，或者符合媒体类型格式的文件类型。 |  
| elementName | ElementName | true | <table><tbody><tr><td>要设置为默认应用的组件信息。</td></tr><tr></tr></tbody></table> |  
| userId | number | false | 用户ID。默认值：调用方所在用户。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700004 | The specified user ID is not found. |  
| 17700025 | The specified type is invalid. |  
| 17700028 | The specified ability does not match the type. |  
    
 **示例代码：**   
```ts    
import defaultAppMgr from '@ohos.bundle.defaultAppManager';  
try {  
  defaultAppMgr.setDefaultApplicationSync(defaultAppMgr.ApplicationType.BROWSER, {  
  bundleName: "com.example.myapplication",  
  moduleName: "module01",  
  abilityName: "EntryAbility"  
});  
  console.info('Operation successful.');  
} catch(error) {  
  console.error('Operation failed. Cause: ' + JSON.stringify(error));  
};  
  
let userId = 100;  
try {  
  defaultAppMgr.setDefaultApplicationSync(defaultAppMgr.ApplicationType.BROWSER, {  
  bundleName: "com.example.myapplication",  
  moduleName: "module01",  
  abilityName: "EntryAbility"  
}, userId);  
  console.info('Operation successful.');  
} catch(error) {  
  console.error('Operation failed. Cause: ' + JSON.stringify(error));  
};  
  
try {  
  defaultAppMgr.setDefaultApplicationSync("image/png", {  
  bundleName: "com.example.myapplication",  
  moduleName: "module01",  
  abilityName: "EntryAbility"  
}, userId);  
  console.info('Operation successful.');  
} catch(error) {  
  console.error('Operation failed. Cause: ' + JSON.stringify(error));  
};  
    
```    
  
    
## resetDefaultApplication    
以异步方法根据系统已定义的应用类型或者符合媒体类型格式（type/subtype）的文件类型重置默认应用，使用Promise形式返回结果。  
 **调用形式：**     
    
- resetDefaultApplication(type: string, userId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- resetDefaultApplication(type: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- resetDefaultApplication(type: string, userId?: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.DefaultApp  
 **需要权限：** ohos.permission.SET_DEFAULT_APPLICATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 要查询的应用类型，取ApplicationType中的值。<br/> |  
| userId | number | true | 用户ID。默认值：调用方所在用户。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 程序启动作为入参的回调函数。 |  
| Promise<void> | Promise对象，无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700004 | The specified user ID is not found. |  
| 17700025 | The specified type is invalid. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import defaultAppMgr from '@ohos.bundle.defaultAppManager';  
import { BusinessError } from '@ohos.base';  
  
let userId = 100;  
defaultAppMgr.resetDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, userId, (err: BusinessError, data) => {  
  if (err) {  
    console.error('Operation failed. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Operation successful.');  
});  
  
defaultAppMgr.resetDefaultApplication("image/png", userId, (err: BusinessError, data) => {  
  if (err) {  
    console.error('Operation failed. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Operation successful.');  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import defaultAppMgr from '@ohos.bundle.defaultAppManager';  
import { BusinessError } from '@ohos.base';  
  
let userId = 100;  
defaultAppMgr.resetDefaultApplication(defaultAppMgr.ApplicationType.BROWSER, userId)  
  .then((data) => {  
    console.info('Operation successful.');  
  })  
  .catch((error: BusinessError) => {  
    console.error('Operation failed. Cause: ' + JSON.stringify(error));  
  });  
  
defaultAppMgr.resetDefaultApplication("image/png", userId)  
  .then((data) => {  
    console.info('Operation successful.');  
  })  
  .catch((error: BusinessError) => {  
    console.error('Operation failed. Cause: ' + JSON.stringify(error));  
  });  
    
```    
  
    
## resetDefaultApplicationSync<sup>(10+)</sup>  
 **调用形式：**     
- resetDefaultApplicationSync(type: string, userId?: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.DefaultApp  
 **需要权限：** ohos.permission.SET_DEFAULT_APPLICATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 要查询的应用类型，取ApplicationType中的值。<br/> |  
| userId | number | false | 用户ID。默认值：调用方所在用户。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700004 | The specified user ID is not found. |  
| 17700025 | The specified type is invalid. |  
    
 **示例代码：**   
```ts    
import defaultAppMgr from '@ohos.bundle.defaultAppManager';  
  
let userId = 100;  
try {  
  defaultAppMgr.resetDefaultApplicationSync(defaultAppMgr.ApplicationType.BROWSER, userId);  
  console.info('Operation successful.');  
} catch(error) {  
  console.error('Operation failed. Cause: ' + JSON.stringify(error));  
};  
  
try {  
  defaultAppMgr.resetDefaultApplicationSync("image/png", userId);  
  console.info('Operation successful.');  
} catch(error) {  
  console.error('Operation failed. Cause: ' + JSON.stringify(error));  
};  
    
```    
  
