# MissionListener    
定义系统任务状态监听，可以通过[on](js-apis-app-ability-missionManager.md#missionmanageron)注册。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## MissionListener  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
### onMissionCreated    
表示当系统创建任务时回调执行。  
 **调用形式：**     
- onMissionCreated(mission: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mission | number | true |  |  
    
### onMissionDestroyed    
表示当系统销毁任务时回调执行。  
 **调用形式：**     
- onMissionDestroyed(mission: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mission | number | true |  |  
    
### onMissionSnapshotChanged    
表示当系统更新任务缩略图时回调执行。  
 **调用形式：**     
- onMissionSnapshotChanged(mission: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mission | number | true |  |  
    
### onMissionMovedToFront    
表示当系统将任务移动到前台时回调执行。  
 **调用形式：**     
- onMissionMovedToFront(mission: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mission | number | true |  |  
    
### onMissionLabelUpdated<sup>(9+)</sup>    
表示当系统更新任务标签时回调执行。  
 **调用形式：**     
- onMissionLabelUpdated(mission: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mission | number | true |  |  
    
### onMissionIconUpdated<sup>(9+)</sup>    
表示当系统更新任务图标时回调执行。  
 **调用形式：**     
- onMissionIconUpdated(mission: number, icon: image.PixelMap): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mission | number | true |  |  
| icon | image.PixelMap | true |  |  
    
### onMissionClosed<sup>(9+)</sup>    
表示当系统关闭任务时回调执行。  
 **调用形式：**     
- onMissionClosed(mission: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mission | number | true |  |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
  
let listener: missionManager.MissionListener = {  
  onMissionCreated: (mission) => {  
    console.log(`onMissionCreated mission: ${JSON.stringify(mission)}`);  
  },  
  onMissionDestroyed: (mission) => {  
    console.log(`onMissionDestroyed mission: ${JSON.stringify(mission)}`);  
  },  
  onMissionSnapshotChanged: (mission) => {  
    console.log(`onMissionSnapshotChanged mission: ${JSON.stringify(mission)}`);  
  },  
  onMissionMovedToFront: (mission) => {  
    console.log(`onMissionMovedToFront mission: ${JSON.stringify(mission)}`);  
  },  
  onMissionLabelUpdated: (mission) => {  
    console.log(`onMissionLabelUpdated mission: ${JSON.stringify(mission)}`);  
  },  
  onMissionIconUpdated: (mission, icon) => {  
    console.log(`onMissionIconUpdated mission: ${JSON.stringify(mission)}`);  
    console.log(`onMissionIconUpdated icon: ${JSON.stringify(mission)}`);  
  },  
  onMissionClosed: (mission) => {  
    console.log(`onMissionClosed mission: ${JSON.stringify(mission)}`);  
    }  
};  
  
try {  
  let listenerId = missionManager.on('mission', listener);  
} catch (paramError) {  
  console.error(`error: ${paramError.code}, ${paramError.message}`);  
}  
    
```    
  
