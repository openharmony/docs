# MissionDeviceInfo    
作为可以[registerMissionListener](js-apis-distributedMissionManager.md#distributedmissionmanagerregistermissionlistener)的入参，表示注册监听时所需参数的枚举。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## MissionDeviceInfo  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
### 属性    
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId | string | false | true | 表示设备ID。 |  
    
 **示例代码：**   
```ts    
import distributedMissionManager from '@ohos.distributedMissionManager';  
distributedMissionManager.registerMissionListener(    {        deviceId: '123456'    },    {        notifyMissionsChanged: (deviceId) => {            console.log(`notifyMissionsChanged deviceId: ${JSON.stringify(deviceId)}`);        },        notifySnapshot: (mission, deviceId) => {            console.log(`notifySnapshot mission: ${JSON.stringify(mission)}`);            console.log(`notifySnapshot deviceId: ${JSON.stringify(deviceId)}`);        },        notifyNetDisconnect: (mission, state) => {            console.log(`notifyNetDisconnect mission: ${JSON.stringify(mission)}`);            console.log(`notifyNetDisconnect state: ${JSON.stringify(state)}`);        }    });    
```    
  
