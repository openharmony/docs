# MissionCallbacks    
作为可以[registerMissionListener](js-apis-distributedMissionManager.md#distributedmissionmanagerregistermissionlistener)的入参，表示开始同步后，建立的回调函数。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## MissionCallback  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
### notifyMissionsChanged    
通知任务变化，返回设备ID。  
 **调用形式：**     
- notifyMissionsChanged(deviceId: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | string<br/> |  
    
### notifySnapshot    
通知快照变化，返回设备ID，任务ID  
 **调用形式：**     
- notifySnapshot(deviceId: string, mission: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | string<br/> |  
| mission | number | true | number<br/> |  
    
### notifyNetDisconnect    
通知断开连接，返回设备ID，网络状态。  
 **调用形式：**     
- notifyNetDisconnect(deviceId: string, state: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | string<br/> |  
| state | number | true | number。 |  
    
 **示例代码：**   
```ts    
import distributedMissionManager from '@ohos.distributedMissionManager';  
distributedMissionManager.registerMissionListener(    {        deviceId: '123456'    },    {        notifyMissionsChanged: (deviceId) => {            console.log(`notifyMissionsChanged deviceId: ${JSON.stringify(deviceId)}`);        },        notifySnapshot: (deviceId, mission) => {            console.log(`notifySnapshot deviceId: ${JSON.stringify(deviceId)}`);            console.log(`notifySnapshot mission: ${JSON.stringify(mission)}`);        },        notifyNetDisconnect: (deviceId, state) => {            console.log(`notifyNetDisconnect deviceId: ${JSON.stringify(deviceId)}`);            console.log(`notifyNetDisconnect state: ${JSON.stringify(state)}`);        }    });    
```    
  
