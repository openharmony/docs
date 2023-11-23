# @ohos.ability.particleAbility    
particleAbility模块提供了操作Service类型的Ability的能力，包括启动、停止指定的particleAbility，获取dataAbilityHelper，连接、断连指定的ServiceAbility等。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import particleAbility from '@ohos.ability.particleAbility'    
```  
    
## startAbility    
启动指定的particleAbility（callback形式）。  
 **调用形式：**     
    
- startAbility(parameter: StartAbilityParameter, callback: AsyncCallback\<void>): void    
起始版本： 7    
- startAbility(parameter: StartAbilityParameter): Promise\<void>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| parameter | StartAbilityParameter | true | 表示启动的ability  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以callback的形式返回启动Ability的结果 |  
| Promise<void> |  |  
    
 **示例代码：**   
```ts    
import particleAbility from '@ohos.ability.particleAbility';  
import wantConstant from '@ohos.ability.wantConstant';  
  
particleAbility.startAbility(  
    {  
        want:  
        {  
            action: 'ohos.want.action.home',  
            entities: ['entity.system.home'],  
            type: 'MIMETYPE',  
            flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,  
            deviceId: '',  
            bundleName: 'com.example.Data',  
            abilityName: 'EntryAbility',  
            uri: ''  
        },  
    },  
    (error, data) => {  
        if (error  error.code !== 0) {  
            console.error(`startAbility fail, error: ${JSON.stringify(error)}`);  
        } else {  
            console.log(`startAbility success, data: ${JSON.stringify(data)}`);  
        }  
    },  
);  
    
```    
  
    
## terminateSelf    
销毁当前particleAbility（callback形式）。  
 **调用形式：**     
    
- terminateSelf(callback: AsyncCallback\<void>): void    
起始版本： 7    
- terminateSelf(): Promise\<void>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以callback的形式返回停止当前Ability结果 |  
| Promise<void> |  |  
    
 **示例代码：**   
```ts    
import particleAbility from '@ohos.ability.particleAbility';  
  
particleAbility.terminateSelf(  
    (error, data) => {  
        if (error  error.code !== 0) {  
            console.error(`terminateSelf fail, error: ${JSON.stringify(error)}`);  
        } else {  
            console.log(`terminateSelf success, data: ${JSON.stringify(data)}`);  
        }  
    }  
);  
    
```    
  
    
## acquireDataAbilityHelper    
获取dataAbilityHelper对象。  
  
使用规则：  
 - 跨应用访问dataAbility，对端应用需配置关联启动  
 - 调用方应用位于后台时，使用该接口访问dataAbility需申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限（基于API 8或更早版本SDK开发的应用在启动DataAbility组件时不受此限制的约束）  
 - 跨应用场景下，目标dataAbility的visible属性若配置为false，调用方应用需申请`ohos.permission.START_INVISIBLE_ABILITY`权限  
 - 组件启动规则详见：[组件启动规则（FA模型）](../../application-models/component-startup-rules-fa.md)。  
 **调用形式：**     
- acquireDataAbilityHelper(uri: string): DataAbilityHelper  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 表示要打开的文件的路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DataAbilityHelper | 用来协助其他Ability访问DataAbility的工具类。 |  
    
 **示例代码：**   
```ts    
import particleAbility from '@ohos.ability.particleAbility';  
let uri = '';particleAbility.acquireDataAbilityHelper(uri);    
```    
  
    
## startBackgroundRunning<sup>(deprecated)</sup>    
向系统申请长时任务，使用callback形式返回结果，建议使用新接口[backgroundTaskManager.startBackgroundRunning](js-apis-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning8)。  
 **调用形式：**     
- startBackgroundRunning(id: number, request: NotificationRequest, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceschedule.backgroundTaskManager/backgroundTaskManager#startBackgroundRunning。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask  
 **需要权限：** ohos.permission.KEEP_BACKGROUND_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | true | 长时任务通知id号 |  
| request<sup>(deprecated)</sup> | NotificationRequest | true | 通知参数，用于显示通知栏的信息 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | callback形式返回启动长时任务的结果 |  
    
 **示例代码：**   
```ts    
import notification from '@ohos.notificationManager';  
import particleAbility from '@ohos.ability.particleAbility';  
import wantAgent from '@ohos.app.ability.wantAgent';  
import { BusinessError } from '@ohos.base';  
  
function callback(error: BusinessError, data: void) {  
    if (error  error.code !== 0) {  
        console.error(`Operation failed error: ${JSON.stringify(error)}`);  
    } else {  
        console.info(`Operation succeeded, data: ${data}`);  
    }  
}  
  
let wantAgentInfo: wantAgent.WantAgentInfo = {  
    wants: [  
        {  
            bundleName: 'com.example.myapplication',  
            abilityName: 'EntryAbility'  
        }  
    ],  
    operationType: wantAgent.OperationType.START_ABILITY,  
    requestCode: 0,  
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]  
};  
  
wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {  
    let id = 1;  
    particleAbility.startBackgroundRunning(id, {  
        content:  
        {  
            contentType: notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,  
            normal:  
            {  
                title: 'title',  
                text: 'text'  
            }  
        },  
        wantAgent: wantAgentObj  
    }, callback);  
});  
    
```    
  
    
## startBackgroundRunning<sup>(deprecated)</sup>    
向系统申请长时任务，使用promise形式返回结果，建议使用新接口[backgroundTaskManager.startBackgroundRunning](js-apis-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning8-1)。  
 **调用形式：**     
- startBackgroundRunning(id: number, request: NotificationRequest): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceschedule.backgroundTaskManager/backgroundTaskManager#startBackgroundRunning。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask  
 **需要权限：** ohos.permission.KEEP_BACKGROUND_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | true | 长时任务通知id号 |  
| request<sup>(deprecated)</sup> | NotificationRequest | true | 通知参数，用于显示通知栏的信息 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 使用Promise形式返回启动长时任务的结果。 |  
    
 **示例代码：**   
```ts    
import notification from '@ohos.notificationManager';  
import particleAbility from '@ohos.ability.particleAbility';  
import wantAgent from '@ohos.app.ability.wantAgent';  
import { BusinessError } from '@ohos.base';  
  
let wantAgentInfo: wantAgent.WantAgentInfo = {  
    wants: [  
        {  
            bundleName: 'com.example.myapplication',  
            abilityName: 'EntryAbility'  
        }  
    ],  
    operationType: wantAgent.OperationType.START_ABILITY,  
    requestCode: 0,  
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]  
};  
  
wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {  
    let id = 1;  
    particleAbility.startBackgroundRunning(id, {  
        content:  
        {  
            contentType: notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,  
            normal:  
            {  
                title: 'title',  
                text: 'text'  
            }  
        },  
        wantAgent: wantAgentObj  
    }).then(() => {  
        console.info('Operation succeeded');  
    }).catch((err: BusinessError) => {  
        console.error(`Operation failed cause: ${JSON.stringify(err)}`);  
    });  
});  
    
```    
  
    
## cancelBackgroundRunning<sup>(deprecated)</sup>    
向系统申请取消长时任务，使用callback形式返回结果，建议使用新接口[backgroundTaskManager.stopBackgroundRunning](js-apis-backgroundTaskManager.md#backgroundtaskmanagerstopbackgroundrunning8)。  
 **调用形式：**     
- cancelBackgroundRunning(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceschedule.backgroundTaskManager/backgroundTaskManager#stopBackgroundRunning。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | callback形式返回取消长时任务的结果 |  
    
 **示例代码：**   
```ts    
import particleAbility from '@ohos.ability.particleAbility';  
import { BusinessError } from '@ohos.base';  
  
function callback(error: BusinessError, data: void) {  
    if (error  error.code !== 0) {  
        console.error(`Operation failed error: ${JSON.stringify(error)}`);  
    } else {  
        console.info(`Operation succeeded, data: ${data}`);  
    }  
}  
  
particleAbility.cancelBackgroundRunning(callback);  
    
```    
  
    
## cancelBackgroundRunning<sup>(deprecated)</sup>    
向系统申请取消长时任务，使用promise形式返回结果，建议使用新接口[backgroundTaskManager.stopBackgroundRunning](js-apis-backgroundTaskManager.md#backgroundtaskmanagerstopbackgroundrunning8-1)。  
 **调用形式：**     
- cancelBackgroundRunning(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceschedule.backgroundTaskManager/backgroundTaskManager#stopBackgroundRunning。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 使用Promise形式返回取消长时任务的结果。 |  
    
 **示例代码：**   
```ts    
import particleAbility from '@ohos.ability.particleAbility';  
particleAbility.cancelBackgroundRunning().then(() => {    console.info('Operation succeeded');}).catch((err: BusinessError) => {    console.error(`Operation failed cause: ${JSON.stringify(err)}`);});    
```    
  
    
## connectAbility    
将当前ability与指定的ServiceAbility进行连接（callback形式）。  
 **调用形式：**     
- connectAbility(request: Want, options: ConnectOptions): number  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request | Want | true | 表示被连接的ServiceAbility。 |  
| options | ConnectOptions | true | 连接回调方法。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number |  |  
    
 **示例代码：**   
```ts    
import particleAbility from '@ohos.ability.particleAbility';import rpc from '@ohos.rpc';  
let connId = particleAbility.connectAbility(    {        bundleName: 'com.ix.ServiceAbility',        abilityName: 'ServiceAbilityA',    },    {        onConnect: (element, remote) => {            console.log(`ConnectAbility onConnect remote is proxy: ${(remote instanceof rpc.RemoteProxy)}`);        },        onDisconnect: (element) => {            console.log(`ConnectAbility onDisconnect element.deviceId: ${element.deviceId}`);        },        onFailed: (code) => {            console.error(`particleAbilityTest ConnectAbility onFailed errCode: ${code}`);        },    },);  
particleAbility.disconnectAbility(connId).then((data) => {    console.log(`data: ${data}`);}).catch((error: BusinessError) => {    console.error(`particleAbilityTest result errCode: ${error.code}`);});    
```    
  
    
## disconnectAbility    
断开当前ability与指定ServiceAbility的连接（callback形式）。  
 **调用形式：**     
    
- disconnectAbility(connection: number, callback: AsyncCallback\<void>): void    
起始版本： 7    
- disconnectAbility(connection: number): Promise\<void>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| connection | number | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback形式返回断开连接的结果 |  
| Promise<void> | 使用Promise形式返回结果。 |  
    
 **示例代码：**   
```ts    
import particleAbility from '@ohos.ability.particleAbility';import rpc from '@ohos.rpc';  
let connId = particleAbility.connectAbility(    {        bundleName: 'com.ix.ServiceAbility',        abilityName: 'ServiceAbilityA',    },    {        onConnect: (element, remote) => {            console.log(`ConnectAbility onConnect remote is proxy: ${(remote instanceof rpc.RemoteProxy)}`);        },        onDisconnect: (element) => {            console.log(`ConnectAbility onDisconnect element.deviceId: ${element.deviceId}`);        },        onFailed: (code) => {            console.error(`particleAbilityTest ConnectAbility onFailed errCode: ${code}`);        },    },);  
particleAbility.disconnectAbility(connId, (err) => {    console.error(`particleAbilityTest disconnectAbility err: ${JSON.stringify(err)}`);});    
```    
  
    
## ErrorCode    
表示错误码。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **模型约束：** 本模块接口仅可在FA模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| INVALID_PARAMETER | -1 | 无效的参数。 |  
