# @ohos.resourceschedule.backgroundTaskManager    
本模块提供申请后台任务的接口。当应用退至后台时，开发者可以通过本模块接口为应用申请短时、长时任务，避免应用进程被终止或挂起。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager'    
```  
    
## DelaySuspendInfo    
短时任务信息。  
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask    
### 属性    
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| requestId | number | false | true | 短时任务的请求ID。    |  
| actualDelayTime | number | false | true | 应用实际申请的短时任务时间，单位为毫秒。<br/>短时任务申请时间最长为3分钟，[低电量](js-apis-battery-info.md)时最长为1分钟。 |  
    
## cancelSuspendDelay    
取消短时任务。  
。  
 **调用形式：**     
- cancelSuspendDelay(requestId: number): void  
  
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| requestId | number | true | 短时任务的请求ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9800001 | Memory operation failed. |  
| 9800002 | Parcel operation failed. |  
| 9800003 | Inner transact failed. |  
| 9800004 | System service operation failed. |  
| 9900001 | Caller information verification failed. |  
| 9900002 | Background task verification failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
  
  let id = 1;  
  try {  
    backgroundTaskManager.cancelSuspendDelay(id);  
  } catch (error) {  
    console.error(`cancelSuspendDelay failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);  
  }  
    
```    
  
    
## getRemainingDelayTime    
获取本次短时任务的剩余时间。  
 **调用形式：**     
    
- getRemainingDelayTime(requestId: number, callback: AsyncCallback\<number>): void    
起始版本： 9    
- getRemainingDelayTime(requestId: number): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| requestId | number | true |  短时任务的请求ID。    |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回本次短时任务的剩余时间，单位为毫秒。 |  
| Promise<number> | Promise对象，返回本次短时任务的剩余时间，单位为毫秒。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9800001 | Memory operation failed. |  
| 9800002 | Parcel operation failed. |  
| 9800003 | Inner transact failed. |  
| 9800004 | System service operation failed. |  
| 9900001 | Caller information verification failed. |  
| 9900002 | Background task verification failed. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let id = 1;  
backgroundTaskManager.getRemainingDelayTime(id, (error: BusinessError, res: number) => {  
    if(error) {  
        console.error(`callback => Operation getRemainingDelayTime failed. code is ${error.code} message is ${error.message}`);  
    } else {  
        console.log('callback => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));  
    }  
})  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let id = 1;  
backgroundTaskManager.getRemainingDelayTime(id).then((res: number) => {  
    console.log('promise => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));  
}).catch((error: BusinessError) => {  
    console.error(`promise => Operation getRemainingDelayTime failed. code is ${error.code} message is ${error.message}`);  
})  
    
```    
  
    
## requestSuspendDelay    
申请短时任务。  
 **调用形式：**     
    
- requestSuspendDelay(reason: string, callback: Callback\<void>): DelaySuspendInfo    
起始版本： 9  
  
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| reason | string | true | 申请短时任务的原因。    |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 短时任务即将超时的回调函数，一般在超时前6秒，通过此回调通知应用。 |  
| DelaySuspendInfo | 返回短时任务信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9800001 | Memory operation failed |  
| 9800002 | Parcel operation failed. |  
| 9800003 | Inner transact failed. |  
| 9800004 | System service operation failed. |  
| 9900001 | Caller information verification failed. |  
| 9900002 | Background task verification failed. |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let myReason = 'test requestSuspendDelay';  
try {  
let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {  
    console.info("Request suspension delay will time out.");  
})  
let id = delayInfo.requestId;  
let time = delayInfo.actualDelayTime;  
console.info("The requestId is: " + id);  
console.info("The actualDelayTime is: " + time);  
} catch (error) {  
console.error(`requestSuspendDelay failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);  
}  
    
```    
  
    
## startBackgroundRunning    
申请长时任务。  
 **调用形式：**     
    
- startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback\<void>): void    
起始版本： 9    
- startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask  
 **需要权限：** ohos.permission.KEEP_BACKGROUND_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-context.md)。  |  
| bgMode | BackgroundMode | true | 长时任务模式。   |  
| wantAgent | WantAgent | true |  通知参数，用于指定点击长时任务通知后跳转的界面。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，申请长时任务成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
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
| 9800005 | Background task verification failed. |  
| 9800006 | Notification verification failed. |  
| 9800007 | Task storage failed. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';    
import wantAgent, { WantAgent } from '@ohos.app.ability.wantAgent';  
import Want from '@ohos.app.ability.Want';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
import { BusinessError } from '@ohos.base';  
  
function callback(error: BusinessError, data: void) {  
    if (error) {  
        console.error(`Operation startBackgroundRunning failed. code is ${error.code} message is ${error.message}`);  
    } else {  
        console.info("Operation startBackgroundRunning succeeded");  
    }  
}  
  
export default class EntryAbility extends UIAbility {  
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
        let wantAgentInfo: wantAgent.WantAgentInfo = {  
            // 点击通知后，将要执行的动作列表  
            wants: [  
                {  
                    bundleName: "com.example.myapplication",  
                    abilityName: "EntryAbility"  
                }  
            ],  
            // 点击通知后，动作类型  
            operationType: wantAgent.OperationType.START_ABILITY,  
            // 使用者自定义的一个私有值  
            requestCode: 0,  
            // 点击通知后，动作执行属性  
            wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]  
        };  
  
        try {  
            // 通过wantAgent模块下getWantAgent方法获取WantAgent对象  
            wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {  
                try {  
                    backgroundTaskManager.startBackgroundRunning(this.context,  
                        backgroundTaskManager.BackgroundMode.LOCATION, wantAgentObj, callback)  
                } catch (error) {  
                    console.error(`Operation startBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);  
                }  
            });  
        } catch (error) {  
            console.error(`Operation getWantAgent failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);  
        }  
    }  
};  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';   
import wantAgent, { WantAgent } from '@ohos.app.ability.wantAgent';  
import Want from '@ohos.app.ability.Want';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
import { BusinessError } from '@ohos.base';  
  
export default class EntryAbility extends UIAbility {  
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
        let wantAgentInfo: wantAgent.WantAgentInfo = {  
            // 点击通知后，将要执行的动作列表  
            wants: [  
                {  
                    bundleName: "com.example.myapplication",  
                    abilityName: "EntryAbility"  
                }  
            ],  
            // 点击通知后，动作类型  
            operationType: wantAgent.OperationType.START_ABILITY,  
            // 使用者自定义的一个私有值  
            requestCode: 0,  
            // 点击通知后，动作执行属性  
            wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]  
        };  
  
        try {  
            // 通过wantAgent模块下getWantAgent方法获取WantAgent对象  
            wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {  
                try {  
                    backgroundTaskManager.startBackgroundRunning(this.context,  
                        backgroundTaskManager.BackgroundMode.LOCATION, wantAgentObj).then(() => {  
                        console.info("Operation startBackgroundRunning succeeded");  
                    }).catch((error: BusinessError) => {  
                        console.error(`Operation startBackgroundRunning failed. code is ${error.code} message is ${error.message}`);  
                    });  
                } catch (error) {  
                    console.error(`Operation startBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);  
                }  
            });  
        } catch (error) {  
            console.error(`Operation getWantAgent failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);  
        }  
    }  
};  
    
```    
  
    
## stopBackgroundRunning    
取消长时任务。  
 **调用形式：**     
    
- stopBackgroundRunning(context: Context, callback: AsyncCallback\<void>): void    
起始版本： 9    
- stopBackgroundRunning(context: Context): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-context.md)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，取消长时任务成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 9800001 | Memory operation failed. |  
| 9800002 | Parcel operation failed. |  
| 9800003 | Inner transact failed. |  
| 9800004 | System service operation failed. |  
| 9800005 | Background task verification failed. |  
| 9800006 | Notification verification failed. |  
| 9800007 | Task storage failed. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';    
import Want from '@ohos.app.ability.Want';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
import { BusinessError } from '@ohos.base';  
  
function callback(error: BusinessError, data: void) {  
    if (error) {  
        console.error(`Operation stopBackgroundRunning failed. code is ${error.code} message is ${error.message}`);  
    } else {  
        console.info("Operation stopBackgroundRunning succeeded");  
    }  
}  
  
export default class EntryAbility extends UIAbility {  
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
        try {  
            backgroundTaskManager.stopBackgroundRunning(this.context, callback);  
        } catch (error) {  
            console.error(`Operation stopBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);  
        }  
    }  
};  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';    
import Want from '@ohos.app.ability.Want';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
import { BusinessError } from '@ohos.base';  
  
export default class EntryAbility extends UIAbility {  
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
        try {  
            backgroundTaskManager.stopBackgroundRunning(this.context).then(() => {  
                console.info("Operation stopBackgroundRunning succeeded");  
            }).catch((error: BusinessError) => {  
                console.error(`Operation stopBackgroundRunning failed. code is ${error.code} message is ${error.message}`);  
            });  
        } catch (error) {  
            console.error(`Operation stopBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);  
        }  
    }  
};  
    
```    
  
    
## BackgroundMode    
长时任务模式。    
    
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DATA_TRANSFER | 1 | 数据传输。    |  
| AUDIO_PLAYBACK | 2 | 音频播放。 |  
| AUDIO_RECORDING | 3 | 录音。 |  
| LOCATION | 4 | 定位导航。 |  
| BLUETOOTH_INTERACTION | 5 | 蓝牙相关。 |  
| MULTI_DEVICE_CONNECTION | 6 | 多设备互联。 |  
| TASK_KEEPING | 9 | 计算任务（仅对特定设备开放）。  |  
