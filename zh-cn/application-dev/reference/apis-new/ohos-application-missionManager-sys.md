# @ohos.application.missionManager    
missionManager模块提供系统任务管理能力，包括对系统任务执行锁定、解锁、清理、切换到前台等操作。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import missionManager from '@ohos.application.missionManager'    
```  
    
## registerMissionListener<sup>(deprecated)</sup>    
注册系统任务状态监听器。  
 **调用形式：**     
- registerMissionListener(listener: MissionListener): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#on。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| listener<sup>(deprecated)</sup> | MissionListener | true | 系统任务监听器。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 监听器的index值，由系统创建，在注册系统任务状态监听器时分配，和监听器一一对应。 |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.application.missionManager';  
console.log('registerMissionListener');let listenerid = missionManager.registerMissionListener({ onMissionCreated: (mission) => {console.log('--------onMissionCreated-------');}, onMissionDestroyed: (mission) => {console.log('--------onMissionDestroyed-------');}, onMissionSnapshotChanged: (mission) => {console.log('--------onMissionSnapshotChanged-------');}, onMissionMovedToFront: (mission) => {console.log('--------onMissionMovedToFront-------');}, onMissionIconUpdated: (mission, icon) => {console.log('--------onMissionIconUpdated-------');}, onMissionClosed: (mission) => {console.log('--------onMissionClosed-------');}, onMissionLabelUpdated: (mission) => {console.log('--------onMissionLabelUpdated-------');}});    
```    
  
    
## unregisterMissionListener<sup>(deprecated)</sup>    
unregisterMissionListener(listenerId: number, callback: AsyncCallbacklt;voidgt;): void;解注册任务状态监听器。  
 **调用形式：**     
- unregisterMissionListener(listenerId: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#off。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| listenerId<sup>(deprecated)</sup> | number | true | 系统任务状态监听器的index值，和监听器一一对应，由registerMissionListener方法返回。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 执行结果回调函数。 |  
    
 **示例代码：**   
```ts    
 import missionManager from '@ohos.application.missionManager';  
 console.log('registerMissionListener'); let listenerid = missionManager.registerMissionListener({  onMissionCreated: (mission) => {console.log('--------onMissionCreated-------');},  onMissionDestroyed: (mission) => {console.log('--------onMissionDestroyed-------');},  onMissionSnapshotChanged: (mission) => {console.log('--------onMissionSnapshotChanged-------');},  onMissionMovedToFront: (mission) => {console.log('--------onMissionMovedToFront-------');},  onMissionIconUpdated: (mission, icon) => {console.log('--------onMissionIconUpdated-------');},  onMissionClosed: (mission) => {console.log('--------onMissionClosed-------');},  onMissionLabelUpdated: (mission) => {console.log('--------onMissionLabelUpdated-------');} });  
 missionManager.unregisterMissionListener(listenerid, (error) => {   console.error('unregisterMissionListener fail, error: ${error}'); });    
```    
  
    
## unregisterMissionListener<sup>(deprecated)</sup>    
反注册任务状态监听器，以promise方式返回执行结果。  
 **调用形式：**     
- unregisterMissionListener(listenerId: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#off。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| listenerId<sup>(deprecated)</sup> | number | true | 系统任务状态监听器的index值，和监听器一一对应，由registerMissionListener方法返回。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | promise方式返回执行结果。 |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.application.missionManager';  
  import { BusinessError } from '@ohos.base';  
  
  console.log('registerMissionListener');  
  let listenerid = missionManager.registerMissionListener({  
    onMissionCreated: (mission) => {console.log('--------onMissionCreated-------');},  
    onMissionDestroyed: (mission) => {console.log('--------onMissionDestroyed-------');},  
    onMissionSnapshotChanged: (mission) => {console.log('--------onMissionSnapshotChanged-------');},  
    onMissionMovedToFront: (mission) => {console.log('--------onMissionMovedToFront-------');},  
    onMissionIconUpdated: (mission, icon) => {console.log('--------onMissionIconUpdated-------');},  
    onMissionClosed: (mission) => {console.log('--------onMissionClosed-------');},  
    onMissionLabelUpdated: (mission) => {console.log('--------onMissionLabelUpdated-------');}  
  });  
  
  missionManager.unregisterMissionListener(listenerid).catch((error: BusinessError) => {  
      console.error('unregisterMissionListener fail, error: ${error}');  
  });  
    
```    
  
    
## getMissionInfo<sup>(deprecated)</sup>    
获取单个任务信息，以异步回调的方式返回任务信息。  
 **调用形式：**     
- getMissionInfo(deviceId: string, missionId: number, callback: AsyncCallback\<MissionInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#getMissionInfo。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 设备ID，本机默认为空字符串。 |  
| missionId<sup>(deprecated)</sup> | number | true | 任务ID。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<MissionInfo> | true | 执行结果回调函数，返回任务信息。 |  
    
## getMissionInfo<sup>(deprecated)</sup>    
获取单个任务信息，以promise方式返回任务信息。  
 **调用形式：**     
- getMissionInfo(deviceId: string, missionId: number): Promise\<MissionInfo>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#getMissionInfo。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 设备ID，本机默认为空字符串。 |  
| missionId<sup>(deprecated)</sup> | number | true | 任务ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<MissionInfo> | 任务信息。 |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.application.missionManager';  
  import { BusinessError } from '@ohos.base';  
  
  let mission = missionManager.getMissionInfo('', 10).catch((error: BusinessError) => {  
      console.error('getMissionInfo fail, error: ${error}');  
  });  
    
```    
  
    
## getMissionInfos<sup>(deprecated)</sup>    
获取所有任务信息，以回调函数的方式返回任务信息数组。  
 **调用形式：**     
- getMissionInfos(deviceId: string, numMax: number, callback: AsyncCallback\<Array\<MissionInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#getMissionInfos。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 设备ID，本机默认为空字符串。 |  
| numMax<sup>(deprecated)</sup> | number | true | 任务信息数量上限。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<MissionInfo>> | true | 执行结果回调函数，返回任务信息数组。 |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.application.missionManager';  
  import { BusinessError } from '@ohos.base';  
  
  let allMissions=missionManager.getMissionInfos('',10).catch((err: BusinessError) => {  
    console.log('${err}');});  
  missionManager.getMissionInfo('', allMissions[0].missionId, (error, mission) => {  
    if (error.code) {  
      console.error('getMissionInfo failed, error.code: ${error.code}, error.message: ${error.message}');  
      return;  
    }  
  
    console.log('mission.missionId = ${mission.missionId}');  
    console.log('mission.runningState = ${mission.runningState}');  
    console.log('mission.lockedState = ${mission.lockedState}');  
    console.log('mission.timestamp = ${mission.timestamp}');  
    console.log('mission.label = ${mission.label}');  
    console.log('mission.iconPath = ${mission.iconPath}');  
  });  
    
```    
  
    
## getMissionInfos<sup>(deprecated)</sup>    
获取所有任务信息，以promise的方式返回任务信息数组。  
 **调用形式：**     
- getMissionInfos(deviceId: string, numMax: number): Promise\<Array\<MissionInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#getMissionInfos。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 设备ID，本机默认为空字符串。 |  
| numMax<sup>(deprecated)</sup> | number | true | 任务信息数量上限。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<MissionInfo>> | 任务信息数组。 |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.application.missionManager';  
  import { BusinessError } from '@ohos.base';  
  
  let allMissions = missionManager.getMissionInfos('', 10).catch((error: BusinessError) => {  
      console.error('getMissionInfos fail, error: ${error}');  
  });  
    
```    
  
    
## getMissionSnapShot<sup>(deprecated)</sup>    
获取任务快照，以回调函数的方式返回快照内容。  
 **调用形式：**     
- getMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback\<MissionSnapshot>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#getMissionSnapShot。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 设备ID，本机默认为空字符串。 |  
| missionId<sup>(deprecated)</sup> | number | true | 任务ID。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<MissionSnapshot> | true | 执行结果回调函数，返回任务快照信息。 |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.application.missionManager';  
 missionManager.getMissionInfos('', 10, (error, missions) => {  if (error.code) {    console.error(`getMissionInfos failed, error.code: ${error.code}, error.message: ${error.message}`);    return;  }  console.log(`size = ${missions.length}`);  console.log(`missions = ${JSON.stringify(missions)}`);  let id = missions[0].missionId;  
  missionManager.getMissionSnapShot('', id, (error, snapshot) => {   if (error.code) {     console.error(`getMissionSnapShot failed, error.code: ${error.code}, error.message: ${error.message}`);     return;   }   console.log(`bundleName = ${snapshot.ability.bundleName}`);  }); });    
```    
  
    
## getMissionSnapShot<sup>(deprecated)</sup>    
获取任务快照，以promise的方式返回快照内容。  
 **调用形式：**     
- getMissionSnapShot(deviceId: string, missionId: number): Promise\<MissionSnapshot>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#getMissionSnapShot。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 设备ID，本机默认为空字符串。 |  
| missionId<sup>(deprecated)</sup> | number | true | 任务ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<MissionSnapshot> | 任务快照信息。 |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.application.missionManager';  
  import { BusinessError } from '@ohos.base';  
  
  let id: number = -1;  
  missionManager.getMissionInfos('',10).then((res) => {  
    let allMissions = res;  
    console.log(`size = ${allMissions.length}`);  
    console.log(`missions = ${JSON.stringify(allMissions)}`);  
    id = allMissions[0].missionId;  
  }).catch((error: BusinessError) => {  
    console.error(`getMissionInfos fail, error: ${error}`);  
  });  
  
  let snapshot = missionManager.getMissionSnapShot('', id).catch((error: BusinessError) => {  
    console.error(`getMissionSnapShot fail, error: ${error}`);  
  });  
    
```    
  
    
## lockMission<sup>(deprecated)</sup>    
锁定指定任务id的任务，以回调函数的方式返回。  
 **调用形式：**     
- lockMission(missionId: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#lockMission。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| missionId<sup>(deprecated)</sup> | number | true | 任务ID。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 执行结果回调函数。 |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.application.missionManager';  
 missionManager.getMissionInfos('', 10, (error, missions) => {  if (error.code) {    console.error(`getMissionInfos failed, error.code: ${error.code}, error.message: ${error.message}`);    return;  }  console.log(`size = ${missions.length}`);  console.log(`missions = ${JSON.stringify(missions)}`);  let id = missions[0].missionId;  
  missionManager.lockMission(id).then(() => {   console.log('lockMission is called ');  }); });    
```    
  
    
## lockMission<sup>(deprecated)</sup>    
锁定指定任务id的任务，以promise方式返回。  
 **调用形式：**     
- lockMission(missionId: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#lockMission。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| missionId<sup>(deprecated)</sup> | number | true | 任务ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | promise方式返回执行结果 |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.application.missionManager';  
  import { BusinessError } from '@ohos.base';  
  
  let id: number = -1;  
  missionManager.getMissionInfos('',10).then((res) => {  
    let allMissions = res;  
    console.log(`size = ${allMissions.length}`);  
    console.log(`missions = ${JSON.stringify(allMissions)}`);  
    id = allMissions[0].missionId;  
  }).catch((error: BusinessError) => {  
      console.error(`getMissionInfos fail, error: ${error}`);  
  });  
  
  missionManager.lockMission(id).catch((error: BusinessError) => {  
      console.error(`lockMission fail, error: ${error}`);  
  });  
    
```    
  
    
## unlockMission<sup>(deprecated)</sup>    
解锁指定任务id的任务，以回调函数的方式返回。  
 **调用形式：**     
- unlockMission(missionId: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#unlockMission。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| missionId<sup>(deprecated)</sup> | number | true | 任务ID。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 执行结果回调函数。 |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.application.missionManager';  
 missionManager.getMissionInfos('', 10, (error, missions) => {  if (error.code) {    console.error(`getMissionInfos failed, error.code: ${error.code}, error.message: ${error.message}`);    return;  }  console.log(`size = ${missions.length}`);  console.log(`missions = ${JSON.stringify(missions)}`);  let id = missions[0].missionId;  
  missionManager.unlockMission(id).then(() => {   console.log('unlockMission is called ');  }); });    
```    
  
    
## unlockMission<sup>(deprecated)</sup>    
解锁指定任务id的任务，以promise的方式返回。  
 **调用形式：**     
- unlockMission(missionId: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#unlockMission。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| missionId<sup>(deprecated)</sup> | number | true | 任务ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | promise方式返回执行结果。 |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.application.missionManager';  
  import { BusinessError } from '@ohos.base';  
  
  let id: number = -1;  
  missionManager.getMissionInfos('',10).then((res) => {  
    let allMissions = res;  
    console.log(`size = ${allMissions.length}`);  
    console.log(`missions = ${JSON.stringify(allMissions)}`);  
    id = allMissions[0].missionId;  
  }).catch((error: BusinessError) => {  
      console.error(`getMissionInfos fail, error: ${error}`);  
  });  
  
  missionManager.lockMission(id).catch((error: BusinessError) => {  
      console.error(`lockMission fail, error: ${error}`);  
  });  
  missionManager.unlockMission(id).catch((error: BusinessError) => {  
      console.error(`unlockMission fail, error: ${error}`);  
  });  
    
```    
  
    
## clearMission<sup>(deprecated)</sup>    
清理指定任务id的任务，无论该任务是否被锁定，以回调函数的方式返回。  
 **调用形式：**     
- clearMission(missionId: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#clearMission。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| missionId<sup>(deprecated)</sup> | number | true | 任务ID。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 执行结果回调函数。 |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.application.missionManager';  
 missionManager.getMissionInfos('', 10, (error, missions) => {  if (error.code) {    console.error(`getMissionInfos failed, error.code: ${error.code}, error.message: ${error.message}`);    return;  }  console.log(`size = ${missions.length}`);  console.log(`missions = ${JSON.stringify(missions)}`);  let id = missions[0].missionId;  
  missionManager.clearMission(id).then(() => {   console.log('clearMission is called ');  }); });    
```    
  
    
## clearMission<sup>(deprecated)</sup>    
清理指定任务id的任务，无论该任务是否被锁定，以promise的方式返回。  
 **调用形式：**     
- clearMission(missionId: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#clearMission。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| missionId<sup>(deprecated)</sup> | number | true | 任务ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | promise方式返回执行结果。 |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.application.missionManager';  
  import { BusinessError } from '@ohos.base';  
  
  let id: number = -1;  
  missionManager.getMissionInfos('',10).then((res) => {  
    let allMissions = res;  
    console.log(`size = ${allMissions.length}`);  
    console.log(`missions = ${JSON.stringify(allMissions)}`);  
    id = allMissions[0].missionId;  
  }).catch((error: BusinessError) => {  
      console.error(`getMissionInfos fail, error: ${error}`);  
  });  
  
  missionManager.clearMission(id).catch((error: BusinessError) => {  
    console.error(`clearMission fail, error: ${error}`);  
  });  
    
```    
  
    
## clearAllMissions<sup>(deprecated)</sup>    
清理所有未锁定的任务，以回调函数的方式返回。  
 **调用形式：**     
- clearAllMissions(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#clearAllMissions。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true |  |  
    
 **示例代码：**   
```ts    
 import missionManager from '@ohos.application.missionManager'  
 missionManager.clearAllMissions().then(() => {  console.log('clearAllMissions is called '); });    
```    
  
    
## clearAllMissions<sup>(deprecated)</sup>    
清理所有未锁定的任务，以promise的方式返回。  
 **调用形式：**     
- clearAllMissions(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#clearAllMissions。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | promise方式返回执行结果。 |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.application.missionManager';  
  import { BusinessError } from '@ohos.base';  
  
  missionManager.clearAllMissions().catch((error: BusinessError) => {  
      console.error('clearAllMissions fail, error: ${error}');  
  });  
    
```    
  
    
## moveMissionToFront<sup>(deprecated)</sup>    
把指定任务id的任务切到前台，以回调函数的方式返回。  
 **调用形式：**     
- moveMissionToFront(missionId: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#moveMissionToFront。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| missionId<sup>(deprecated)</sup> | number | true | 任务ID。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 执行结果回调函数。 |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.application.missionManager';  
 missionManager.getMissionInfos('', 10, (error, missions) => {  if (error.code) {    console.error(`getMissionInfos failed, error.code: ${error.code}, error.message: ${error.message}`);    return;  }  console.log(`size = ${missions.length}`);  console.log(`missions = ${JSON.stringify(missions)}`);  let id = missions[0].missionId;  
  missionManager.moveMissionToFront(id).then(() => {   console.log('moveMissionToFront is called ');  }); });    
```    
  
    
## moveMissionToFront<sup>(deprecated)</sup>    
把指定任务id的任务切到前台，同时指定任务切换到前台时的启动参数，例如窗口模式、设备ID等，以回调函数的方式返回。  
 **调用形式：**     
- moveMissionToFront(missionId: number, options: StartOptions, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#moveMissionToFront。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| missionId<sup>(deprecated)</sup> | number | true | 任务ID。 |  
| options<sup>(deprecated)</sup> | StartOptions | true | 启动参数选项，用于指定任务切到前台时的窗口模式，设备ID等。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 执行结果回调函数。 |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.application.missionManager';  
 missionManager.getMissionInfos('', 10, (error, missions) => {  if (error.code) {    console.error(`getMissionInfos failed, error.code: ${error.code}, error.message: ${error.message}`);    return;  }  console.log(`size = ${missions.length}`);  console.log(`missions = ${JSON.stringify(missions)}`);  let id = missions[0].missionId;  
  missionManager.moveMissionToFront(id,{windowMode : 101}).then(() => {   console.log('moveMissionToFront is called ');  }); });    
```    
  
    
## moveMissionToFront<sup>(deprecated)</sup>    
把指定任务id的任务切到前台，同时指定任务切换到前台时的启动参数，例如窗口模式、设备ID等，以promise的方式返回。  
 **调用形式：**     
- moveMissionToFront(missionId: number, options?: StartOptions): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.missionManager/missionManager#moveMissionToFront。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| missionId<sup>(deprecated)</sup> | number | true | 任务ID。 |  
| options<sup>(deprecated)</sup> | StartOptions | false | 启动参数选项，用于指定任务切到前台时的窗口模式，设备ID等。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | promise方式返回执行结果。 |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.application.missionManager';  
  import { BusinessError } from '@ohos.base';  
  
  let id: number = -1;  
  missionManager.getMissionInfos('',10).then((res) => {  
    let allMissions = res;  
    console.log(`size = ${allMissions.length}`);  
    console.log(`missions = ${JSON.stringify(allMissions)}`);  
    id = allMissions[0].missionId;  
  }).catch((error: BusinessError) => {  
      console.error(`getMissionInfos fail, error: ${error}`);  
  });  
  
  missionManager.moveMissionToFront(id).catch((error: BusinessError) => {  
    console.error(`moveMissionToFront fail, error: ${error}`);  
  });  
    
```    
  
