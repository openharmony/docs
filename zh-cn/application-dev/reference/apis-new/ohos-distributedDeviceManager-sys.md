# @ohos.distributedDeviceManager    
本模块提供分布式设备管理能力。  
应用可调用接口实现如下功能：  
- 注册和解除注册设备上下线变化监听- 发现周边不可信设备- 认证和取消认证设备- 查询可信设备列表- 查询本地设备信息，包括设备名称，设备类型和设备标识等。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import distributedDeviceManager from '@ohos.distributedDeviceManager'    
```  
    
## DeviceManager    
设备管理实例，用于获取可信设备和本地设备的相关信息。在调用DeviceManager的方法前，需要先通过createDeviceManager构建一个DeviceManager实例dmInstance。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
### replyUiAction    
回复用户ui操作行为。此接口只能被devicemanager的PIN码hap使用。  
 **调用形式：**     
- replyUiAction(action: number, actionResult: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| action | number | true | 用户操作动作。  |  
| actionResult | string | true | 表示用户操作结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
  /*  
    action = 0 - 允许授权  
    action = 1 - 取消授权  
    action = 2 - 授权框用户操作超时  
    action = 3 - 取消pin码框展示  
    action = 4 - 取消pin码输入框展示  
    action = 5 - pin码输入框确定操作  
  */  
  let operation = 0;  
  dmInstance.replyUiAction(operation, "extra")  
  } catch (err) {  
    let e: BusinessError = err as BusinessError;  
    console.error("replyUiAction errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### on('replyResult')    
注册设备管理服务死亡监听。  
 **调用形式：**     
    
- on(type: 'replyResult', callback: Callback\<{ param: string }>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 注册serviceDie回调，以便在devicemanager服务异常终止时通知应用程序。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 注册serviceDie的回调方法。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
class Data {  
  param: string = ""  
}  
  
interface TmpStr {  
  verifyFailed: boolean  
}  
  
try {  
  dmInstance.on('replyResult', (data: Data) => {  
  console.log("replyResult executed, dialog closed" + JSON.stringify(data))  
  let tmpStr: TmpStr = JSON.parse(data.param)  
  let isShow = tmpStr.verifyFailed  
  console.log("replyResult executed, dialog closed" + isShow)  
});  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("replyResult errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### off('replyResult')    
取消注册设备管理服务死亡监听。  
 **调用形式：**     
    
- off(type: 'replyResult', callback?: Callback\<{ param: string }>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消注册serviceDie回调，以便在devicemanager服务异常终止时通知应用程序。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消注册serviceDie的回调方法。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
  dmInstance.off('replyResult');  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("replyResult errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
