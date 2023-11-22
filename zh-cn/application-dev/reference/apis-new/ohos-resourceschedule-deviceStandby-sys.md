# @ohos.resourceschedule.deviceStandby    
当设备长时间未被使用或通过按键，可以使设备进入待机模式。待机模式不影响应用使用，还可以延长电池续航时间。通过本模块接口，可查询设备或应用是否为待机模式，以及为应用申请或取消待机资源管控。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import deviceStandby from '@ohos.resourceschedule.deviceStandby'    
```  
    
## getExemptedApps    
获取进入待机模式的应用名单。  
 **调用形式：**     
    
- getExemptedApps(resourceTypes: number, callback: AsyncCallback\<Array\<ExemptedAppInfo>>): void    
起始版本： 10    
- getExemptedApps(resourceTypes: number): Promise\<Array\<ExemptedAppInfo>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ResourceSchedule.DeviceStandby  
 **需要权限：** ohos.permission.DEVICE_STANDBY_EXEMPTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resourceTypes | number | true | 资源类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 豁免应用信息 。 |  
| Promise<Array<ExemptedAppInfo>> | 豁免应用信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 9800001 | Memory operation failed. |  
| 9800002 | Parcel operation failed. |  
| 9800003 | Inner transact failed. |  
| 9800004 | System service operation failed. |  
| 18700001 | Caller information verification failed. |  
    
 **示例代码1：**   
示例callback：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let resourceTypes: deviceStandby.ResourceType = deviceStandby.ResourceType.TIMER;  
deviceStandby.getExemptedApps(resourceTypes, (err: BusinessError, res: Array<deviceStandby.ExemptedAppInfo>) => {  
if (err) {  
console.log('DEVICE_STANDBY getExemptedApps callback failed. code is: ' + err.code + ',message is: ' + err.message);  
} else {  
console.log('DEVICE_STANDBY getExemptedApps callback success.');  
for (let i = 0; i < res.length; i++) {  
console.log('DEVICE_STANDBY getExemptedApps callback result ' + JSON.stringify(res[i]));  
}  
}  
});  
    
```    
  
    
 **示例代码2：**   
示例promise：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let resourceTypes: deviceStandby.ResourceType = deviceStandby.ResourceType.TIMER;  
deviceStandby.getExemptedApps(resourceTypes).then( (res: Array<deviceStandby.ExemptedAppInfo>) => {  
  console.log('DEVICE_STANDBY getExemptedApps promise success.');  
  for (let i = 0; i < res.length; i++) {  
    console.log('DEVICE_STANDBY getExemptedApps promise result ' + JSON.stringify(res[i]));  
  }  
}).catch( (err: BusinessError) => {  
  console.log('DEVICE_STANDBY getExemptedApps promise failed. code is: ' + err.code + ',message is: ' + err.message);  
});  
    
```    
  
    
## requestExemptionResource    
应用订阅申请豁免，使应用临时不进入待机管控。  
 **调用形式：**     
- requestExemptionResource(request: ResourceRequest): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ResourceSchedule.DeviceStandby  
 **需要权限：** ohos.permission.DEVICE_STANDBY_EXEMPTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request | ResourceRequest | true | 资源请求。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 9800001 | Memory operation failed. |  
| 9800002 | Parcel operation failed. |  
| 9800003 | Inner transact failed. |  
| 9800004 | System service operation failed. |  
| 18700001 | Caller information verification failed. |  
    
 **示例代码：**   
```ts    
let resRequest: deviceStandby.ResourceRequest = {  resourceTypes: deviceStandby.ResourceType.TIMER,  uid:10003,  name:"com.example.app",  duration:10,  reason:"apply",};deviceStandby.requestExemptionResource(resRequest);    
```    
  
    
## releaseExemptionResource    
取消应用订阅申请豁免。  
 **调用形式：**     
- releaseExemptionResource(request: ResourceRequest): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ResourceSchedule.DeviceStandby  
 **需要权限：** ohos.permission.DEVICE_STANDBY_EXEMPTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request | ResourceRequest | true | 资源请求 。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 9800001 | Memory operation failed. |  
| 9800002 | Parcel operation failed. |  
| 9800003 | Inner transact failed. |  
| 9800004 | System service operation failed. |  
| 18700001 | Caller information verification failed. |  
    
 **示例代码：**   
```ts    
let resRequest: deviceStandby.ResourceRequest = {  resourceTypes: deviceStandby.ResourceType.TIMER,  uid:10003,  name:"com.demo.app",  duration:10,  reason:"unapply",};deviceStandby.releaseExemptionResource(resRequest);    
```    
  
    
## ResourceType    
非待机应用资源枚举。    
    
 **系统能力:**  SystemCapability.ResourceSchedule.DeviceStandby    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NETWORK | 1 | 网络访问资源 |  
| RUNNING_LOCK | 1 << 1 | cpu-runninglock资源 |  
| TIMER | 1 << 2 | timer任务资源 |  
| WORK_SCHEDULER | 1 << 3 | work任务资源 |  
| AUTO_SYNC | 1 << 4 | 自动同步的资源 |  
| PUSH | 1 << 5 | pushkit资源 |  
| FREEZE | 1 << 6 | 冻结应用资源 |  
    
## ExemptedAppInfo    
豁免应用信息，未进入待机管控的应用信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ResourceSchedule.DeviceStandby    
### 属性    
 **系统能力:**  SystemCapability.ResourceSchedule.DeviceStandby    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| resourceTypes | number | false | true | |应用的资源类型 |  
| name | string | false | true |  应用名  |  
| duration | number | false | true | 豁免时长 |  
    
## ResourceRequest    
待机资源请求体。  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ResourceSchedule.DeviceStandby    
### 属性    
 **系统能力:**  SystemCapability.ResourceSchedule.DeviceStandby    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| resourceTypes | number | false | true | 应用的资源类型 |  
| uid | number | false | true | 应用uid  |  
| name | string | false | true | 应用名称 |  
| duration | number | false | true | 豁免时长  |  
| reason | string | false | true | 申请原因。 |  
