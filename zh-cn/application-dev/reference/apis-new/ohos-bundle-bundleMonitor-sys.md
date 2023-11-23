# @ohos.bundle.bundleMonitor    
本模块提供监听应用安装，卸载，更新的能力。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import bundleMonitor from '@ohos.bundle.bundleMonitor'    
```  
    
## BundleChangedInfo    
此接口为系统接口。  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | true | true | 应用状态发生变化的应用Bundle名称。<br/> |  
| userId | number | true | true | 应用状态发生变化的用户id。<br/> |  
    
## BundleChangedEvent    
监听的事件类型。  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| add | 监听应用事件。 |  
| update | 监听更新事件。 |  
| remove | 监听删除事件。 |  
    
## on    
注册监听应用的安装，卸载，更新。  
 **调用形式：**     
- on(type: BundleChangedEvent, callback: Callback\<BundleChangedInfo>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.LISTEN_BUNDLE_CHANGE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | BundleChangedEvent | true | 注册监听的事件类型。<br/> |  
| callback | Callback<BundleChangedInfo> | true | 注册监听的回调函数。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import bundleMonitor from '@ohos.bundle.bundleMonitor';  
import { BusinessError } from '@ohos.base';  
  
try {  
    bundleMonitor.on('add', (bundleChangeInfo) => {  
        console.info(`bundleName : ${bundleChangeInfo.bundleName} userId : ${bundleChangeInfo.userId}`);  
	})  
} catch (errData) {  
    let message = (errData as BusinessError).message;  
    let errCode = (errData as BusinessError).code;  
    console.log(`errData is errCode:${errCode}  message:${message}`);  
}  
    
```    
  
    
## off    
注销监听应用的安装，卸载，更新。  
 **调用形式：**     
- off(type: BundleChangedEvent, callback?: Callback\<BundleChangedInfo>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.LISTEN_BUNDLE_CHANGE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | BundleChangedEvent | true | 注销监听的事件类型。<br/> |  
| callback | Callback<BundleChangedInfo> | false | 注销监听的回调函数，默认值：注销当前事件的所有callback。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import bundleMonitor from '@ohos.bundle.bundleMonitor';  
import { BusinessError } from '@ohos.base';  
  
try {  
    bundleMonitor.off('add');  
} catch (errData) {  
    let message = (errData as BusinessError).message;  
    let errCode = (errData as BusinessError).code;  
    console.log(`errData is errCode:${errCode}  message:${message}`);  
}  
    
```    
  
