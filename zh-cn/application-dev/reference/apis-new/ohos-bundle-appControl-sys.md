# @ohos.bundle.appControl    
本模块提供应用拦截能力。对应用设置处置状态后，应用会被禁止运行；用户点击桌面图标时，会根据应用的处置状态，跳转到对应的页面。本模块支持对应用的处置状态进行设置、获取、删除。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import appControl from '@ohos.bundle.appControl'    
```  
    
## setDisposedStatus    
以异步方法设置应用的处置状态。成功返回null，失败返回对应错误信息。  
 **调用形式：**     
    
- setDisposedStatus(appId: string, disposedWant: Want, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setDisposedStatus(appId: string, disposedWant: Want): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.AppControl  
 **需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| appId | string | true | 需要设置处置状态的应用的appId。<br/>appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见获取应用的appId。 |  
| disposedWant | Want | true | 对应用的处置意图。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当设置处置状态成功，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700005 | The specified app ID is empty string. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import Want from '@ohos.app.ability.Want';  
import appControl from '@ohos.bundle.appControl';  
  
let appId = "com.example.myapplication_xxxxx";  
let want:Want = {bundleName: 'com.example.myapplication'};  
  
try {  
    appControl.setDisposedStatus(appId, want)  
        .then(() => {  
            console.info('setDisposedStatus success');  
        }).catch((error: BusinessError) => {  
            let message = (error as BusinessError).message;  
            console.error('setDisposedStatus failed ' + message);  
        });  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('setDisposedStatus failed ' + message);  
}  
    
```    
  
    
## setDisposedStatusSync<sup>(10+)</sup>    
以异步方法设置应用的处置状态。使用Promise异步回调。成功返回null，失败返回对应错误信息。  
 **调用形式：**     
- setDisposedStatusSync(appId: string, disposedWant: Want): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.AppControl  
 **需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| appId | string | true | 需要设置处置状态的应用的appId。<br/>appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见获取应用的appId。<br/> |  
| disposedWant | Want | true | 对应用的处置意图。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700005 | The specified app ID is empty string. |  
    
 **示例代码：**   
```ts    
import appControl from '@ohos.bundle.appControl';  
import { BusinessError } from '@ohos.base';  
import Want from '@ohos.app.ability.Want';  
  
let appId: string = "com.example.myapplication_xxxxx";  
let want: Want = {bundleName: 'com.example.myapplication'};  
  
try {  
  appControl.setDisposedStatusSync(appId, want);  
} catch (error) {  
  let message = (error as BusinessError).message;  
  console.error('setDisposedStatusSync failed ' + message);  
}  
    
```    
  
    
## getDisposedStatus    
以异步方法获取指定应用已设置的处置状态。使用Promise异步回调，成功返回应用的处置状态，失败返回对应错误信息。  
 **调用形式：**     
    
- getDisposedStatus(appId: string, callback: AsyncCallback\<Want>): void    
起始版本： 9    
- getDisposedStatus(appId: string): Promise\<Want>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.AppControl  
 **需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| appId | string | true | 需要设置处置状态的应用的appId。<br/>appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见获取应用的appId。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当获取应用的处置状态成功时，err为null，data为获取到的处置状态；否则为错误对象。 |  
| Promise<Want> | Promise对象，返回应用的处置状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700005 | The specified app ID is empty string. |  
    
 **示例代码：**   
```ts    
import appControl from '@ohos.bundle.appControl';  
import { BusinessError } from '@ohos.base';  
  
let appId = "com.example.myapplication_xxxxx";  
  
try {  
  appControl.getDisposedStatus(appId)  
    .then((data) => {  
      console.info('getDisposedStatus success. DisposedStatus: ' + JSON.stringify(data));  
    }).catch((error: BusinessError) => {  
    let message = (error as BusinessError).message;  
    console.error('getDisposedStatus failed ' + message);  
  });  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('getDisposedStatus failed ' + message);  
}  
    
```    
  
    
## getDisposedStatusSync<sup>(10+)</sup>    
以同步方法获取指定应用已设置的处置状态。成功返回应用的处置状态，失败抛出对应异常。  
 **调用形式：**     
- getDisposedStatusSync(appId: string): Want  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.AppControl  
 **需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| appId | string | true | 需要设置处置状态的应用的appId。<br/>appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见获取应用的appId。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Want | 返回应用的处置状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700005 | The specified app ID is empty string. |  
    
 **示例代码：**   
```ts    
import appControl from '@ohos.bundle.appControl';  
import { BusinessError } from '@ohos.base';  
import Want from '@ohos.app.ability.Want';  
  
let appId: string = "com.example.myapplication_xxxxx";  
let want: Want;  
  
try {  
    want = appControl.getDisposedStatusSync(appId);  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('getDisposedStatusSync failed ' + message);  
}  
    
```    
  
    
## deleteDisposedStatus    
设置指定应用的拦截规则。  
 **调用形式：**     
    
- deleteDisposedStatus(appId: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- deleteDisposedStatus(appId: string): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.AppControl  
 **需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| appId | string | true | 需要设置处置状态的应用的appId。<br/>appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见获取应用的appId。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当设置处置状态成功，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象，返回应用的处置状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700005 | The specified app ID is empty string. |  
    
 **示例代码：**   
```ts    
import appControl from '@ohos.bundle.appControl';  
import { BusinessError } from '@ohos.base';  
  
let appId = "com.example.myapplication_xxxxx";  
  
try {  
  appControl.deleteDisposedStatus(appId)  
    .then(() => {  
      console.info('deleteDisposedStatus success');  
    }).catch((error: BusinessError) => {  
      let message = (error as BusinessError).message;  
      console.error('deleteDisposedStatus failed ' + message);  
  });  
} catch (error) {  
  let message = (error as BusinessError).message;  
  console.error('deleteDisposedStatus failed ' + message);  
}  
    
```    
  
    
## deleteDisposedStatusSync<sup>(10+)</sup>    
以同步方法删除应用的处置状态。成功返回null，失败抛出对应异常。  
 **调用形式：**     
- deleteDisposedStatusSync(appId: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.AppControl  
 **需要权限：** ohos.permission.MANAGE_DISPOSED_APP_STATUS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| appId | string | true | 需要设置处置状态的应用的appId。<br/>appId是应用的唯一标识，由应用Bundle名称和签名信息决定，获取方法参见获取应用的appId。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 17700005 | The specified app ID is empty string. |  
    
 **示例代码：**   
```ts    
import appControl from '@ohos.bundle.appControl';  
import { BusinessError } from '@ohos.base';  
  
let appId: string = "com.example.myapplication_xxxxx";  
  
try {  
    appControl.deleteDisposedStatusSync(appId);  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('deleteDisposedStatusSync failed ' + message);  
}  
    
```    
  
