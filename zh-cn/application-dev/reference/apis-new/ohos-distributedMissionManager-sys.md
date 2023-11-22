# @ohos.distributedMissionManager    
分布式任务管理模块提供跨设备任务管理能力，包括注册和取消任务状态监听、开始和停止同步远端设备任务列表、通过任务ID和包名进行迁移任务等。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import distributedMissionManager from '@ohos.distributedMissionManager'    
```  
    
## ContinueState<sup>(10+)</sup>    
当前任务流转状态的枚举。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ACTIVE | 0 | 表示当前任务流转处于激活状态。                              |  
| INACTIVE | 1 | 表示当前任务流转处于未激活状态。                             |  
    
## startSyncRemoteMissions    
开始同步远端设备的任务列表。  
 **调用形式：**     
    
- startSyncRemoteMissions(parameter: MissionParameter, callback: AsyncCallback\<void>): void    
起始版本： 9    
- startSyncRemoteMissions(parameter: MissionParameter): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| parameter | MissionParameter | true | 同步信息。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，同步远端任务列表成功时，err为undefined，否则返回错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import distributedMissionManager from '@ohos.distributedMissionManager'  
import { BusinessError } from '@ohos.base';  
  
try {  
  distributedMissionManager.startSyncRemoteMissions(  
    {  
      deviceId: "",  
      fixConflict: false,  
      tag: 0  
    },  
    (error: BusinessError) => {  
      if (error.code != 0) {  
        console.error('startSyncRemoteMissions failed, cause: ' + JSON.stringify(error))  
      }  
      console.info('startSyncRemoteMissions finished')}  
  )  
} catch (error) {  
  console.error('startSyncRemoteMissions failed, cause: ' + JSON.stringify(error))  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import distributedMissionManager from '@ohos.distributedMissionManager'  
import { BusinessError } from '@ohos.base';  
  
try {  
  distributedMissionManager.startSyncRemoteMissions(  
    {  
      deviceId: "",  
      fixConflict: false,  
      tag: 0  
    }  
  ).then(() => {  
      console.info('startSyncRemoteMissions finished successfully');  
    }).catch((error: BusinessError) => {  
    console.error('startSyncRemoteMissions failed, cause: ' + JSON.stringify(error));  
  })  
} catch (error) {  
  console.error('startSyncRemoteMissions failed, cause: ' + JSON.stringify(error))  
}  
    
```    
  
    
## stopSyncRemoteMissions    
停止同步远端设备的任务列表。使用promise异步回调。  
 **调用形式：**     
    
- stopSyncRemoteMissions(parameter: MissionDeviceInfo, callback: AsyncCallback\<void>): void    
起始版本： 9    
- stopSyncRemoteMissions(parameter: MissionDeviceInfo): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| parameter | MissionDeviceInfo | true | 同步信息。      |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，停止同步远端任务列表成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import distributedMissionManager from '@ohos.distributedMissionManager'  
import { BusinessError } from '@ohos.base';  
  
try {  
  distributedMissionManager.stopSyncRemoteMissions(  
    {  
      deviceId: ""  
    },  
    (error: BusinessError) => {  
      if (error.code != 0) {  
        console.error('stopSyncRemoteMissions failed, cause: ' + JSON.stringify(error))  
      }  
      console.info('stopSyncRemoteMissions finished')}  
  )  
} catch (error) {  
  console.error('stopSyncRemoteMissions failed, cause: ' + JSON.stringify(error))  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import distributedMissionManager from '@ohos.distributedMissionManager'  
import { BusinessError } from '@ohos.base';  
  
try {  
  distributedMissionManager.stopSyncRemoteMissions(  
    {  
      deviceId: ""  
    }).then((data: void) => {  
      console.info('stopSyncRemoteMissions finished successfully');  
    }).catch((error: BusinessError) => {  
    console.error('stopSyncRemoteMissions failed, cause: ' + JSON.stringify(error));  
  })  
} catch (error) {  
  console.error('stopSyncRemoteMissions failed, cause: ' + JSON.stringify(error))  
}  
    
```    
  
    
## registerMissionListener    
注册任务状态监听。使用promise异步回调。  
 **调用形式：**     
    
- registerMissionListener(    parameter: MissionDeviceInfo,    options: MissionCallback,    callback: AsyncCallback\<void>  ): void    
起始版本： 9    
- registerMissionListener(parameter: MissionDeviceInfo, options: MissionCallback): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| parameter | MissionDeviceInfo | true | 注册监听时的设备信息。    |  
| options | MissionCallback | true | 注册的回调方法。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，注册监听成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import distributedMissionManager from '@ohos.distributedMissionManager'  
import { BusinessError } from '@ohos.base';  
  
// 实现回调函数  
function NotifyMissionsChanged(deviceId: string): void {  
  console.log('NotifyMissionsChanged deviceId ' + JSON.stringify(deviceId));  
}  
function NotifySnapshot(deviceId: string, missionId: number): void {  
  console.log('NotifySnapshot deviceId ' + JSON.stringify(deviceId));  
  console.log('NotifySnapshot missionId ' + JSON.stringify(missionId));  
}  
function NotifyNetDisconnect(deviceId: string, state: number): void {  
  console.log('NotifyNetDisconnect deviceId ' + JSON.stringify(deviceId));  
  console.log('NotifyNetDisconnect state ' + JSON.stringify(state));  
}  
try {  
  // 调用registerMissionListener接口  
  distributedMissionManager.registerMissionListener(  
    { deviceId: "" },  
    {  
      notifyMissionsChanged: NotifyMissionsChanged,  
      notifySnapshot: NotifySnapshot,  
      notifyNetDisconnect: NotifyNetDisconnect  
    },  
    (error: BusinessError) => {  
      if (error.code != 0) {  
        console.error('registerMissionListener failed, cause: ' + JSON.stringify(error))  
      }  
      console.info('registerMissionListener finished')  
    });  
} catch (error) {  
  console.error('registerMissionListener failed, cause: ' + JSON.stringify(error))  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
  
```ts    
import distributedMissionManager from '@ohos.distributedMissionManager'  
import { BusinessError } from '@ohos.base';  
  
// 实现回调函数  
function NotifyMissionsChanged(deviceId: string): void {  
  console.log('NotifyMissionsChanged deviceId ' + JSON.stringify(deviceId));  
}  
function NotifySnapshot(deviceId: string, missionId: number): void {  
  console.log('NotifySnapshot deviceId ' + JSON.stringify(deviceId));  
  console.log('NotifySnapshot missionId ' + JSON.stringify(missionId));  
}  
function NotifyNetDisconnect(deviceId: string, state: number): void {  
  console.log('NotifyNetDisconnect deviceId ' + JSON.stringify(deviceId));  
  console.log('NotifyNetDisconnect state ' + JSON.stringify(state));  
}  
try {  
    // 调用registerMissionListener接口  
    distributedMissionManager.registerMissionListener(  
      { deviceId: "" },  
      {  
        notifyMissionsChanged: NotifyMissionsChanged,  
        notifySnapshot: NotifySnapshot,  
        notifyNetDisconnect: NotifyNetDisconnect  
      }).then((data: void) => {  
        console.info('registerMissionListener finished, ' + JSON.stringify(data));  
    }).catch((error: BusinessError) => {  
        console.error('registerMissionListener failed, cause: ' + JSON.stringify(error));  
    })  
} catch (error) {  
    console.error('registerMissionListener failed, cause: ' + JSON.stringify(error))  
}  
    
```    
  
    
## unRegisterMissionListener    
取消任务状态监听。使用promise异步回调。  
 **调用形式：**     
    
- unRegisterMissionListener(parameter: MissionDeviceInfo, callback: AsyncCallback\<void>): void    
起始版本： 9    
- unRegisterMissionListener(parameter: MissionDeviceInfo): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| parameter | MissionDeviceInfo | true | 注册监听时的设备信息。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，取消监听成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import distributedMissionManager from '@ohos.distributedMissionManager'  
import { BusinessError } from '@ohos.base';  
  
try {  
  distributedMissionManager.unRegisterMissionListener(  
    { deviceId: "" },  
    (error: BusinessError) => {  
      if (error.code != 0) {  
          console.error('unRegisterMissionListener failed, cause: ' + JSON.stringify(error))  
      }  
      console.info('unRegisterMissionListener finished')  
  })  
} catch (error) {  
    console.error('unRegisterMissionListener failed, cause: ' + JSON.stringify(error))  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import distributedMissionManager from '@ohos.distributedMissionManager'  
import { BusinessError } from '@ohos.base';  
  
try {  
  distributedMissionManager.unRegisterMissionListener({deviceId: ""}).then(() => {  
    console.info('unRegisterMissionListener finished successfully');  
  }).catch((error: BusinessError) => {  
      console.error('unRegisterMissionListener failed, cause: ' + JSON.stringify(error));  
  })  
} catch (error) {  
    console.error('unRegisterMissionListener failed, cause: ' + JSON.stringify(error))  
}  
    
```    
  
    
## on('continueStateChange')<sup>(10+)</sup>    
注册当前任务流转状态的监听。  
 **调用形式：**     
    
- on(type: 'continueStateChange', callback: Callback\<{ state: ContinueState, info: ContinuableInfo }>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 当前任务流转状态，取值为'continueStateChange'。     |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回当前任务的流转状态和流转信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import distributedMissionManager from '@ohos.distributedMissionManager'  
  
  try {  
    distributedMissionManager.on('continueStateChange', (data) => {  
      console.info("continueStateChange on:" + JSON.stringify(data));  
    });  
  } catch (error) {  
    console.error("continueStateChange err: " + JSON.stringify(error));  
  }  
    
```    
  
    
## off('continueStateChange')<sup>(10+)</sup>    
取消当前任务流转的状态监听。  
 **调用形式：**     
    
- off(type: 'continueStateChange', callback?: Callback\<{ state: ContinueState, info: ContinuableInfo }>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 当前任务流转状态，取值为'continueStateChange'。     |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回当前任务的流转状态和流转信息。<br>参数不填写，取消type对应的所有回调监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import distributedMissionManager from '@ohos.distributedMissionManager'  
  
  try {  
    distributedMissionManager.off('continueStateChange', (data) => {  
      console.info("continueStateChange off:" + JSON.stringify(data));  
    });  
  } catch (err) {  
    console.error("continueStateChange err: " + JSON.stringify(err));  
  }  
    
```    
  
    
## continueMission    
通过指定任务ID（missionId）的方式进行迁移任务。使用promise异步回调。  
 **调用形式：**     
    
- continueMission(    parameter: ContinueDeviceInfo,    options: ContinueCallback,    callback: AsyncCallback\<void>  ): void    
起始版本： 9    
- continueMission(parameter: ContinueDeviceInfo, options: ContinueCallback): Promise\<void>    
起始版本： 9    
- continueMission(parameter: ContinueMissionInfo, callback: AsyncCallback\<void>): void    
起始版本： 10    
- continueMission(parameter: ContinueMissionInfo): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission  
 **需要权限：** ohos.permission.MANAGE_MISSIONS and ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| parameter | ContinueDeviceInfo | true | 迁移信息。  |  
| options | ContinueCallback | true | 迁移任务完成回调函数。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，迁移任务完成时，err为undefined，否则返回错误对象。 |  
| Promise<void> | 无返回结果的promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16300501 | The system ability work abnormally. |  
| 16300502 | Failed to get the missionInfo of the specified missionId. |  
| 16300503 | The application is not installed on the remote end and installation-free is not supported. |  
| 16300504 | The application is not installed on the remote end but installation-free is supported, try again with freeInstall flag. |  
| 16300505 | The operation device must be the device where the application to be continued is located or the target device to be continued. |  
| 16300506 | The local continuation task is already in progress. |  
| 16300507 | Failed to get the missionInfo of the specified bundle name. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import distributedMissionManager from '@ohos.distributedMissionManager'  
import { BusinessError } from '@ohos.base';  
  
// 实现回调函数  
function onContinueDone(resultCode: number): void {  
  console.log('onContinueDone resultCode: ' + JSON.stringify(resultCode));  
};  
try {  
  // 调用continueMission接口  
  distributedMissionManager.continueMission(  
    {  
      srcDeviceId: "",  
      dstDeviceId: "",  
      missionId: 1,  
      wantParam: {"key": "value"}  
    },  
    { onContinueDone: onContinueDone },  
    (error: BusinessError) => {  
      if (error.code != 0) {  
        console.error('continueMission failed, cause: ' + JSON.stringify(error))  
      }  
      console.info('continueMission finished')  
  })  
} catch (error) {  
  console.error('continueMission failed, cause: ' + JSON.stringify(error))  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import distributedMissionManager from '@ohos.distributedMissionManager'  
import { BusinessError } from '@ohos.base';  
  
// 实现回调函数  
function onContinueDone(resultCode: number): void {  
  console.log('onContinueDone resultCode: ' + JSON.stringify(resultCode));  
};  
try {  
  // 调用continueMission接口  
  distributedMissionManager.continueMission(  
    {  
      srcDeviceId: "",  
      dstDeviceId: "",  
      missionId: 1,  
      wantParam: {"key": "value"}  
    },  
    { onContinueDone: onContinueDone }).then(() => {  
      console.info('continueMission finished successfully');  
    }).catch((error: BusinessError) => {  
    console.error('continueMission failed, cause: ' + JSON.stringify(error));  
  })  
} catch (error) {  
  console.error('continueMission failed, cause: ' + JSON.stringify(error))  
}  
    
```    
  
