# @ohos.resourceschedule.backgroundTaskManager    
本模块提供申请后台任务的接口。当应用退至后台时，开发者可以通过本模块接口为应用申请短时、长时任务，避免应用进程被终止或挂起。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager'    
```  
    
## applyEfficiencyResources    
申请能效资源。  
 **调用形式：**     
- applyEfficiencyResources(request: EfficiencyResourcesRequest): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request | EfficiencyResourcesRequest | true | 请求的必要信息，包括资源类型、超时时间等。 |  
    
    
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
```js    
import { BusinessError } from '@ohos.base';  
  
let request: backgroundTaskManager.EfficiencyResourcesRequest = {  
    resourceTypes: backgroundTaskManager.ResourceType.CPU,  
    isApply: true,  
    timeOut: 0,  
    reason: "apply",  
    isPersist: true,  
    isProcess: false,  
};  
try {  
    backgroundTaskManager.applyEfficiencyResources(request);  
    console.info("applyEfficiencyResources success. ");  
} catch (error) {  
    console.error(`applyEfficiencyResources failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);  
}  
    
```    
  
    
## resetAllEfficiencyResources    
释放已申请的全部能效资源。  
 **调用形式：**     
- resetAllEfficiencyResources(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply    
    
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
```js    
import { BusinessError } from '@ohos.base';  
  
try {  
    backgroundTaskManager.resetAllEfficiencyResources();  
} catch (error) {  
    console.error(`resetAllEfficiencyResources failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);  
}  
    
```    
  
    
## BackgroundMode    
长时任务模式。    
    
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| WIFI_INTERACTION | 7 |  WLAN相关。<br>**系统API**: 此接口为系统接口。 |  
| VOIP | 8 | 音视频通话。<br>**系统API**: 此接口为系统接口。 |  
    
## ResourceType    
能效资源类型。    
    
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CPU | 1 | CPU资源，申请后应用进程不被挂起。    |  
| COMMON_EVENT | 1 << 1 | 公共事件资源，申请后应用进程被挂起后，可以收到公共事件。 |  
| TIMER | 1 << 2 |  计时器，申请后应用进程被挂起后，Timer仍然可以唤醒应用。 |  
| WORK_SCHEDULER | 1 << 3 | 延迟任务资源，申请后延迟任务管控变宽松。 |  
| BLUETOOTH | 1 << 4 | 蓝牙资源，申请后应用进程被挂起后，蓝牙相关事件仍然可以唤醒应用。 |  
| GPS | 1 << 5 | GPS资源，申请后应用进程被挂起后，GPS相关事件可以唤醒应用。 |  
| AUDIO | 1 << 6 | 音频资源，有音频播放时对应的应用进程不被挂起。  |  
| RUNNING_LOCK<sup>(10+)</sup> | 1 << 7 |  RUNNING_LOCK资源，申请后挂起状态不会代理RUNNING_BACKGROUND锁。 |  
| SENSOR<sup>(10+)</sup> | 1 << 8 | 申请后不拦截Sensor回调。 |  
    
## EfficiencyResourcesRequest    
能效资源申请参数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply    
### 属性    
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| resourceTypes | number | false | true | 申请的资源类型。  |  
| isApply | boolean | false | true | 申请或释放资源。<br>- true表示申请资源，false表示释放部分资源。 |  
| timeOut | number | false | true | 资源使用时间，单位为毫秒。      |  
| isPersist | boolean | false | false | 是否永久持有资源，默认为false。<br>- true表示永久持有，false表示有限时间内持有。 |  
| isProcess | boolean | false | false | 进程或应用申请，默认为false。<br>- true表示进程申请，false表示应用申请。 |  
| reason | string | false | true |  申请资源原因。 。 |  
