# @ohos.app.ability.missionManager    
missionManager模块提供系统任务管理能力，包括对系统任务执行锁定、解锁、清理、切换到前台等操作。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import missionManager from '@ohos.app.ability.missionManager'    
```  
    
## on('mission')    
注册系统任务状态监听器。  
 **调用形式：**     
- on(type: 'mission', listener: MissionListener): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
| listener | MissionListener | true | 系统任务监听器。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 监听器的index值，由系统创建，在注册系统任务状态监听时分配，和监听器一一对应。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
import common from '@ohos.app.ability.common';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
import window from '@ohos.window';  
  
let listener: missionManager.MissionListener = {  
    onMissionCreated: (mission) => {console.log('--------onMissionCreated-------');},  
    onMissionDestroyed: (mission) => {console.log('--------onMissionDestroyed-------');},  
    onMissionSnapshotChanged: (mission) => {console.log('--------onMissionSnapshotChanged-------');},  
    onMissionMovedToFront: (mission) => {console.log('--------onMissionMovedToFront-------');},  
    onMissionIconUpdated: (mission, icon) => {console.log('--------onMissionIconUpdated-------');},  
    onMissionClosed: (mission) => {console.log('--------onMissionClosed-------');},  
    onMissionLabelUpdated: (mission) => {console.log('--------onMissionLabelUpdated-------');}  
};  
  
let listenerId = -1;  
let abilityWant: Want;  
let context: common.UIAbilityContext;  
  
export default class EntryAbility extends UIAbility {  
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
        console.log('[Demo] EntryAbility onCreate');  
        abilityWant = want;  
        context = this.context;  
    }  
  
    onDestroy() {  
        try {  
            if (listenerId !== -1) {  
                missionManager.off('mission', listenerId).catch((err: BusinessError) => {  
                    console.log(err);  
                });  
            }  
        } catch (paramError) {  
            let code = (paramError as BusinessError).code;  
            let message = (paramError as BusinessError).message;  
            console.error(`error: ${code}, ${message} `);  
        }  
        console.log('[Demo] EntryAbility onDestroy');  
    }  
  
    onWindowStageCreate(windowStage: window.WindowStage) {  
        // Main window is created, set main page for this ability  
        console.log('[Demo] EntryAbility onWindowStageCreate');  
        try {  
            listenerId = missionManager.on('mission', listener);  
        } catch (paramError) {  
            let code = (paramError as BusinessError).code;  
            let message = (paramError as BusinessError).message;  
            console.error(`error: ${code}, ${message} `);  
        }  
  
        windowStage.loadContent('pages/index', (err, data) => {  
            if (err.code) {  
                console.error(`Failed to load the content. Cause: ${JSON.stringify(err)}`);  
                return;  
            }  
            console.info(`Succeeded in loading the content. Data: ${JSON.stringify(data)}`);  
        });  
    }  
};  
    
```    
  
    
## off('mission')    
解注册任务状态监听器。  
 **调用形式：**     
    
- off(type: 'mission', listenerId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- off(type: 'mission', listenerId: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
| listenerId | number | true | 系统任务状态监器法的index值，和监听器一一对应，由on方法返回。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 执行结果回调函数。 |  
| Promise<void> | promise方式返回执行结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16300002 | Input error. The specified mission listener does not exist. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
import common from '@ohos.app.ability.common';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
import window from '@ohos.window';  
  
let listener: missionManager.MissionListener = {  
    onMissionCreated: (mission) => {console.log('--------onMissionCreated-------');},  
    onMissionDestroyed: (mission) => {console.log('--------onMissionDestroyed-------');},  
    onMissionSnapshotChanged: (mission) => {console.log('--------onMissionSnapshotChanged-------');},  
    onMissionMovedToFront: (mission) => {console.log('--------onMissionMovedToFront-------');},  
    onMissionIconUpdated: (mission, icon) => {console.log('--------onMissionIconUpdated-------');},  
    onMissionClosed: (mission) => {console.log('--------onMissionClosed-------');},  
    onMissionLabelUpdated: (mission) => {console.log('--------onMissionLabelUpdated-------');}  
};  
  
let listenerId = -1;  
let abilityWant: Want;  
let context: common.UIAbilityContext;  
  
export default class EntryAbility extends UIAbility {  
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
        console.log('[Demo] EntryAbility onCreate');  
        abilityWant = want;  
        context = this.context;  
    }  
  
    onDestroy() {  
        try {  
            if (listenerId !== -1) {  
                missionManager.off('mission', listenerId, (err) => {  
                    console.log('$(err.code)');  
                });  
            }  
        } catch (paramError) {  
            let code = (paramError as BusinessError).code;  
            let message = (paramError as BusinessError).message;  
            console.error(`error: ${code}, ${message} `);  
        }  
        console.log('[Demo] EntryAbility onDestroy');  
    }  
  
    onWindowStageCreate(windowStage: window.WindowStage) {  
        // Main window is created, set main page for this ability  
        console.log('[Demo] EntryAbility onWindowStageCreate');  
        try {  
            listenerId = missionManager.on('mission', listener);  
        } catch (paramError) {  
            let code = (paramError as BusinessError).code;  
            let message = (paramError as BusinessError).message;  
            console.error(`error: ${code}, ${message} `);  
        }  
  
        windowStage.loadContent('pages/index', (err: BusinessError, data) => {  
            if (err.code) {  
                console.error(`Failed to load the content. Cause: ${JSON.stringify(err)}`);  
                return;  
            }  
            console.info(`Succeeded in loading the content. Data: ${JSON.stringify(data)}`);  
        });  
    }  
};  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
import common from '@ohos.app.ability.common';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
import window from '@ohos.window';  
  
let listener: missionManager.MissionListener = {  
    onMissionCreated: (mission) => {console.log('--------onMissionCreated-------');},  
    onMissionDestroyed: (mission) => {console.log('--------onMissionDestroyed-------');},  
    onMissionSnapshotChanged: (mission) => {console.log('--------onMissionSnapshotChanged-------');},  
    onMissionMovedToFront: (mission) => {console.log('--------onMissionMovedToFront-------');},  
    onMissionIconUpdated: (mission, icon) => {console.log('--------onMissionIconUpdated-------');},  
    onMissionClosed: (mission) => {console.log('--------onMissionClosed-------');},  
    onMissionLabelUpdated: (mission) => {console.log('--------onMissionLabelUpdated-------');}  
};  
  
let listenerId = -1;  
let abilityWant: Want;  
let context: common.UIAbilityContext;  
  
export default class EntryAbility extends UIAbility {  
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
        console.log('[Demo] EntryAbility onCreate');  
        abilityWant = want;  
        context = this.context;  
    }  
  
    onDestroy() {  
        try {  
            if (listenerId !== -1) {  
                missionManager.off('mission', listenerId).catch((err: BusinessError) => {  
                    console.log('$(err.code)');  
                });  
            }  
        } catch (paramError) {  
            let code = (paramError as BusinessError).code;  
            let message = (paramError as BusinessError).message;  
            console.error(`error: ${code}, ${message} `);  
        }  
        console.log('[Demo] EntryAbility onDestroy');  
    }  
  
    onWindowStageCreate(windowStage: window.WindowStage) {  
        // Main window is created, set main page for this ability  
        console.log('[Demo] EntryAbility onWindowStageCreate');  
        try {  
            listenerId = missionManager.on('mission', listener);  
        } catch (paramError) {  
            let code = (paramError as BusinessError).code;  
            let message = (paramError as BusinessError).message;  
            console.error(`error: ${code}, ${message} `);  
        }  
  
        windowStage.loadContent('pages/index', (err: BusinessError, data) => {  
            if (err.code) {  
                console.error(`Failed to load the content. Cause: ${JSON.stringify(err)}`);  
                return;  
            }  
            console.info(`Succeeded in loading the content. Data: ${JSON.stringify(data)}`);  
        });  
    }  
};  
    
```    
  
    
## getMissionInfo    
获取任务信息，以promise方式返回任务信息。  
 **调用形式：**     
    
- getMissionInfo(deviceId: string, missionId: number, callback: AsyncCallback\<MissionInfo>): void    
起始版本： 9    
- getMissionInfo(deviceId: string, missionId: number): Promise\<MissionInfo>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 设备ID，本机默认为空字符串。 |  
| missionId | number | true | 任务ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 执行结果回调函数，返回任务信息。 |  
| Promise<MissionInfo> | 任务信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
    import { BusinessError } from '@ohos.base';  
  
    let testMissionId = 1;  
  
    missionManager.getMissionInfos('',10)  
    .then((allMissions) => {  
        try {  
        if (allMissions  allMissions.length > 0) {  
            testMissionId = allMissions[0].missionId;  
        }  
  
        missionManager.getMissionInfo('', testMissionId, (error, mission) => {  
            if (error) {  
            console.error('getMissionInfo failed, error.code: ${error.code}, error.message: ${error.message}');  
            } else {  
            console.log('mission.missionId = ${mission.missionId}');  
            console.log('mission.runningState = ${mission.runningState}');  
            console.log('mission.lockedState = ${mission.lockedState}');  
            console.log('mission.timestamp = ${mission.timestamp}');  
            console.log('mission.label = ${mission.label}');  
            console.log('mission.iconPath = ${mission.iconPath}');  
            }  
        });  
        } catch (paramError) {  
            let code = (paramError as BusinessError).code;  
            let message = (paramError as BusinessError).message;  
            console.error(`error: ${code}, ${message} `);  
        }  
    })  
    .catch((err: BusinessError) => {console.log('$(err.code)');});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
import { BusinessError } from '@ohos.base';  
  
let testMissionId = 1;  
try {  
    missionManager.getMissionInfo('', testMissionId).then((data) => {  
        console.info(`getMissionInfo successfully. Data: ${JSON.stringify(data)}`);  
    }).catch((error: BusinessError) => {  
        console.error(`getMissionInfo failed. Cause: ${error.message}`);  
    });  
} catch (error) {  
    console.error(`getMissionInfo failed. Cause: ${error.message}`);  
}  
    
```    
  
    
## getMissionInfos    
获取所有任务信息，以promise的方式返回任务信息数组。  
 **调用形式：**     
    
- getMissionInfos(deviceId: string, numMax: number, callback: AsyncCallback\<Array\<MissionInfo>>): void    
起始版本： 9    
- getMissionInfos(deviceId: string, numMax: number): Promise\<Array\<MissionInfo>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 设备ID，本机默认为空字符串。 |  
| numMax | number | true | 任务信息数量上限。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 执行结果回调函数，返回任务信息数组。 |  
| Promise<Array<MissionInfo>> | 任务信息数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
ort missionManager from '@ohos.app.ability.missionManager';  
  import { BusinessError } from '@ohos.base';  
  
  try {  
    missionManager.getMissionInfos('', 10, (error, missions) => {  
      if (error) {  
          console.error(`getMissionInfos failed, error.code: ${error.code}, error.message: ${error.message}`);  
      } else {  
        console.log(`size = ${missions.length}`);  
        console.log(`missions = ${JSON.stringify(missions)}`);  
      }  
    });  
  } catch (paramError) {  
        let code = (paramError as BusinessError).code;  
        let message = (paramError as BusinessError).message;  
        console.error(`error: ${code}, ${message} `);  
  }  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    missionManager.getMissionInfos('', 10).then((data) => {  
        console.info('getMissionInfos successfully. Data: ${JSON.stringify(data)}');  
    }).catch((error: BusinessError) => {  
        console.error('getMissionInfos failed. Cause: ${error.message}');  
    });  
} catch (error) {  
    console.error('getMissionInfos failed. Cause: ${error.message}');  
}  
    
```    
  
    
## getMissionSnapShot    
获取任务快照，以回调函数的方式返回快照内容。  
 **调用形式：**     
    
- getMissionSnapShot(deviceId: string, missionId: number, callback: AsyncCallback\<MissionSnapshot>): void    
起始版本： 9    
- getMissionSnapShot(deviceId: string, missionId: number): Promise\<MissionSnapshot>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 设备ID，本机默认为空字符串。 |  
| missionId | number | true | 任务ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 执行结果回调函数，返回任务快照信息。 |  
| Promise<MissionSnapshot> | 任务快照信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
  
let testMissionId = 2;  
try {  
    missionManager.getMissionSnapShot('', testMissionId, (err, data) => {  
        if (err) {  
            console.error(`getMissionSnapShot failed: ${err.message}`);  
        } else {  
            console.info(`getMissionSnapShot successfully: ${JSON.stringify(data)}`);  
        }  
    });  
} catch (err) {  
    console.error(`getMissionSnapShot failed: ${err.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
import { BusinessError } from '@ohos.base';  
  
let testMissionId = 2;  
try {  
    missionManager.getMissionSnapShot('', testMissionId).then((data) => {  
        console.info(`getMissionSnapShot successfully. Data: ${JSON.stringify(data)}`);  
    }).catch((error: BusinessError) => {  
        console.error(`getMissionSnapShot failed. Cause: ${error.message}`);  
    });  
} catch (error) {  
    console.error(`getMissionSnapShot failed. Cause: ${error.message}`);  
}  
    
```    
  
    
## getLowResolutionMissionSnapShot    
获取任务低分辨率快照。  
 **调用形式：**     
    
- getLowResolutionMissionSnapShot(     deviceId: string,     missionId: number,     callback: AsyncCallback\<MissionSnapshot>   ): void    
起始版本： 9    
- getLowResolutionMissionSnapShot(deviceId: string, missionId: number): Promise\<MissionSnapshot>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 设备ID，本机默认为空字符串。 |  
| missionId | number | true | 任务ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 执行结果回调函数，返回任务快照信息。 |  
| Promise<MissionSnapshot> | 任务快照信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
  
let testMissionId = 2;  
try {  
    missionManager.getLowResolutionMissionSnapShot('', testMissionId, (err, data) => {  
        if (err) {  
            console.error(`getLowResolutionMissionSnapShot failed: ${err.message}`);  
        } else {  
            console.info(`getLowResolutionMissionSnapShot successfully: ${JSON.stringify(data)}`);  
        }  
    });  
} catch (err) {  
    console.error(`getLowResolutionMissionSnapShot failed: ${err.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
import { BusinessError } from '@ohos.base';  
  
let testMissionId = 2;  
try {  
    missionManager.getLowResolutionMissionSnapShot('', testMissionId).then((data) => {  
        console.info(`getLowResolutionMissionSnapShot successfully. Data: ${JSON.stringify(data)}`);  
    }).catch((error: BusinessError) => {  
        console.error(`getLowResolutionMissionSnapShot failed. Cause: ${error.message}`);  
    });  
} catch (error) {  
    console.error(`getLowResolutionMissionSnapShot failed. Cause: ${error.message}`);  
}  
    
```    
  
    
## lockMission    
锁定指定任务id的任务，以回调函数的方式返回。  
 **调用形式：**     
    
- lockMission(missionId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- lockMission(missionId: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| missionId | number | true | 任务ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 执行结果回调函数。 |  
| Promise<void> | promise方式返回执行结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16300001 | Mission not found. |  
    
 **示例代码1：**   
  
示例(callback):  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
  
let testMissionId = 2;  
try {  
    missionManager.lockMission(testMissionId, (err, data) => {  
        if (err) {  
            console.error(`lockMission failed: ${err.message}`);  
        } else {  
            console.info(`lockMission successfully: ${JSON.stringify(data)}`);  
        }  
    });  
} catch (err) {  
    console.error(`lockMission failed: ${err.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
import { BusinessError } from '@ohos.base';  
  
let testMissionId = 2;  
try {  
    missionManager.lockMission(testMissionId).then((data) => {  
        console.info(`lockMission successfully. Data: ${JSON.stringify(data)}`);  
    }).catch((error: BusinessError) => {  
        console.error(`lockMission failed. Cause: ${error.message}`);  
    });  
} catch (error) {  
    console.error(`lockMission failed. Cause: ${error.message}`);  
}  
    
```    
  
    
## unlockMission    
解锁指定任务id的任务，以回调函数的方式返回。  
 **调用形式：**     
    
- unlockMission(missionId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- unlockMission(missionId: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| missionId | number | true | 任务ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 执行结果回调函数。 |  
| Promise<void> | promise方式返回执行结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16300001 | Mission not found. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
  
let testMissionId = 2;  
try {  
    missionManager.unlockMission(testMissionId, (err, data) => {  
        if (err) {  
            console.error(`unlockMission failed: ${err.message}`);  
        } else {  
            console.info(`unlockMission successfully: ${JSON.stringify(data)}`);  
        }  
    });  
} catch (err) {  
    console.error(`unlockMission failed: ${err.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
import { BusinessError } from '@ohos.base';  
  
let testMissionId = 2;  
try {  
    missionManager.unlockMission(testMissionId).then((data) => {  
        console.info(`unlockMission successfully. Data: ${JSON.stringify(data)}`);  
    }).catch((error: BusinessError) => {  
        console.error(`unlockMission failed. Cause: ${error.message}`);  
    });  
} catch (error) {  
    console.error(`unlockMission failed. Cause: ${error.message}`);  
}  
    
```    
  
    
## clearMission    
清理指定任务id的任务，无论该任务是否被锁定，以回调函数的方式返回。  
 **调用形式：**     
    
- clearMission(missionId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- clearMission(missionId: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| missionId | number | true | 任务ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 执行结果回调函数。 |  
| Promise<void> | promise方式返回执行结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
  
let testMissionId = 2;  
try {  
    missionManager.clearMission(testMissionId, (err, data) => {  
        if (err) {  
            console.error(`clearMission failed: ${err.message}`);  
        } else {  
            console.info(`clearMission successfully: ${JSON.stringify(data)}`);  
        }  
    });  
} catch (err) {  
    console.error(`clearMission failed: ${err.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
import { BusinessError } from '@ohos.base';  
  
let testMissionId = 2;  
try {  
    missionManager.clearMission(testMissionId).then((data) => {  
        console.info(`clearMission successfully. Data: ${JSON.stringify(data)}`);  
    }).catch((error: BusinessError) => {  
        console.error(`clearMission failed. Cause: ${error.message}`);  
    });  
} catch (error) {  
    console.error(`clearMission failed. Cause: ${error.message}`);  
}  
    
```    
  
    
## clearAllMissions    
清理所有未锁定的任务，以回调函数的方式返回。  
 **调用形式：**     
    
- clearAllMissions(callback: AsyncCallback\<void>): void    
起始版本： 9    
- clearAllMissions(): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> | promise方式返回执行结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
  
try {  
    missionManager.clearAllMissions(err => {  
        if (err) {  
            console.error('clearAllMissions failed: ${err.message}');  
        } else {  
            console.info('clearAllMissions successfully.');  
        }  
    });  
} catch (err) {  
    console.error('clearAllMissions failed: ${err.message}');  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    missionManager.clearAllMissions().then((data) => {  
        console.info(`clearAllMissions successfully. Data: ${JSON.stringify(data)}`);  
    }).catch((err: BusinessError) => {  
        console.error(`clearAllMissions failed: ${err.message}`);  
    });  
} catch (err) {  
    console.error(`clearAllMissions failed: ${err.message}`);  
}  
    
```    
  
    
## moveMissionToFront    
把指定任务id的任务切到前台，以回调函数的方式返回。  
 **调用形式：**     
    
- moveMissionToFront(missionId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- moveMissionToFront(missionId: number, options: StartOptions, callback: AsyncCallback\<void>): void    
起始版本： 9    
- moveMissionToFront(missionId: number, options?: StartOptions): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| missionId | number | true | 任务ID。 |  
| options | StartOptions | true | 启动参数选项，用于指定任务切到前台时的窗口模式，设备ID等。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 执行结果回调函数。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000009 | An ability cannot be started or stopped in Wukong mode. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
import { BusinessError } from '@ohos.base';  
  
let testMissionId = 2;  
try {  
    missionManager.moveMissionToFront(testMissionId).then((data) => {  
        console.info(`moveMissionToFront successfully. Data: ${JSON.stringify(data)}`);  
    }).catch((error: BusinessError) => {  
        console.error(`moveMissionToFront failed. Cause: ${error.message}`);  
    });  
} catch (error) {  
    console.error(`moveMissionToFront failed. Cause: ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
  
```ts    
import missionManager from '@ohos.app.ability.missionManager';  
  
let testMissionId = 2;  
try {  
    missionManager.moveMissionToFront(testMissionId, {windowMode : 101}, (err, data) => {  
        if (err) {  
            console.error(`moveMissionToFront failed: ${err.message}`);  
        } else {  
            console.info(`moveMissionToFront successfully: ${JSON.stringify(data)}`);  
        }  
    });  
} catch (err) {  
    console.error(`moveMissionToFront failed: ${err.message}`);  
}  
    
```    
  
    
## moveMissionsToForeground<sup>(10+)</sup>    
将指定任务批量切到前台，以回调函数的方式返回。  
 **调用形式：**     
    
- moveMissionsToForeground(missionIds: Array\<number>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- moveMissionsToForeground(missionIds: Array\<number>, topMission: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- moveMissionsToForeground(missionIds: Array\<number>, topMission?: number): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| missionIds | Array<number> | true | 任务ID数组。 |  
| topMission | number | true | 待移动到最顶层的任务ID |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 执行结果回调函数。 |  
| Promise<void> | promise方式返回执行结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000050 | Internal error. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import abilityManager from '@ohos.app.ability.abilityManager';  
import missionManager from '@ohos.app.ability.missionManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    missionManager.getMissionInfos("", 10, (error, missionInfos) => {  
        if (error.code) {  
            console.log("getMissionInfos failed, error.code:" + JSON.stringify(error.code));  
            return;  
        }  
        if (missionInfos.length < 1) {  
            return;  
        }  
  
        let toShows = new Array<number>();  
        for (let missionInfo of missionInfos) {  
            if (missionInfo.abilityState == abilityManager.AbilityState.BACKGROUND) {  
                toShows.push(missionInfo.missionId);  
            }  
        }  
        missionManager.moveMissionsToForeground(toShows, (err, data) => {  
            if (err) {  
                console.error(`moveMissionsToForeground failed: ${err.message}`);  
            } else {  
                console.info(`moveMissionsToForeground successfully: ${JSON.stringify(data)}`);  
            }  
        });  
    });  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`error: ${code}, ${message} `);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
<span style="font-size: 14px; letter-spacing: 0px;">import abilityManager from '@ohos.app.ability.abilityManager';</span>import missionManager from '@ohos.app.ability.missionManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    missionManager.getMissionInfos("", 10, (error, missionInfos) => {  
        if (error.code) {  
            console.log("getMissionInfos failed, error.code:" + JSON.stringify(error.code));  
            return;  
        }  
        if (missionInfos.length < 1) {  
            return;  
        }  
  
        let toShows = new Array<number>();  
        for (let missionInfo of missionInfos) {  
            if (missionInfo.abilityState == abilityManager.AbilityState.BACKGROUND) {  
                toShows.push(missionInfo.missionId);  
            }  
        }  
        missionManager.moveMissionsToForeground(toShows, toShows[0]).then(() => {  
            console.log("moveMissionsToForeground is called" );  
        });  
    });  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`error: ${code}, ${message} `);  
}  
<i></i><span style="font-size: 14px; letter-spacing: 0px;"></span>  
    
```    
  
    
## moveMissionsToBackground<sup>(10+)</sup>    
将指定任务批量切到后台，以回调函数的方式返回, 返回的结果任务ID按被隐藏时的任务层级排序。  
 **调用形式：**     
    
- moveMissionsToBackground(missionIds: Array\<number>, callback: AsyncCallback\<Array\<number>>): void    
起始版本： 10    
- moveMissionsToBackground(missionIds: Array\<number>): Promise\<Array\<number>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| missionIds | Array<number> | true | 任务ID数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 执行结果回调函数。 |  
| Promise<Array<number>> | promise方式返回执行结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000050 | Internal error. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import abilityManager from '@ohos.app.ability.abilityManager';  
import missionManager from '@ohos.app.ability.missionManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    missionManager.getMissionInfos("", 10, (error, missionInfos) => {  
        if (error.code) {  
            console.log("getMissionInfos failed, error.code:" + JSON.stringify(error.code));  
            return;  
        }  
        if (missionInfos.length < 1) {  
            return;  
        }  
  
        let toShows = new Array<number>();  
        for (let missionInfo of missionInfos) {  
            if (missionInfo.abilityState == abilityManager.AbilityState.BACKGROUND) {  
                toShows.push(missionInfo.missionId);  
            }  
        }  
        missionManager.moveMissionsToForeground(toShows, toShows[0]).then(() => {  
            console.log("moveMissionsToForeground is called" );  
        });  
    });  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`error: ${code}, ${message} `);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import abilityManager from '@ohos.app.ability.abilityManager';  
import missionManager from '@ohos.app.ability.missionManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    missionManager.getMissionInfos("", 10, (error, missionInfos) => {  
        if (error.code) {  
            console.log("getMissionInfos failed, error.code:" + JSON.stringify(error.code));  
            return;  
        }  
  
        let toHides = new Array<number>();  
        for (let missionInfo of missionInfos) {  
            if (missionInfo.abilityState ==  abilityManager.AbilityState.FOREGROUND) {  
            toHides.push(missionInfo.missionId);  
            }  
        }  
        missionManager.moveMissionsToBackground(toHides).then((hideRes) => {  
            console.log("moveMissionsToBackground is called, res: "+ JSON.stringify(hideRes));  
        });  
    });  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`error: ${code}, ${message} `);  
}  
    
```    
  
