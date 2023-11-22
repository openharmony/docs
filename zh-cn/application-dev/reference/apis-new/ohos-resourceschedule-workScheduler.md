# @ohos.resourceschedule.workScheduler    
本模块提供延迟任务注册、取消、查询的能力。在开发过程中，对于实时性要求不高的任务，可以调用本模块接口注册延迟任务，在系统空闲时根据性能、功耗、热等情况进行调度执行。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import workScheduler from '@ohos.resourceschedule.workScheduler'    
```  
    
## WorkInfo    
延迟任务的具体信息。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
### 属性    
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| workId | number | false | true |  延迟任务ID。 |  
| bundleName | string | false | true | 延迟任务包名。     |  
| abilityName | string | false | true | 延迟任务回调通知的组件名。  |  
| isPersisted | boolean | false | false |  是否持久化保存工作。<br>- true表示持久化保存工作。false表示非持久化保存工作。 |  
| networkType | NetworkType | false | false | 网络类型。  |  
| isCharging | boolean | false | false | 是否充电。<br>- true表示充电触发延迟回调，false表示不充电触发延迟回调。 |  
| chargerType | ChargingType | false | false | 充电类型。 |  
| batteryLevel | number | false | false | 电量。 |  
| batteryStatus | BatteryStatus | false | false | 电池状态。 |  
| storageRequest | StorageRequest | false | false | 存储状态。  |  
| repeatCycleTime | number | false | false | 是否循环任务。<br>- true表示循环任务，false表示非循环任务。 |  
| isRepeat | boolean | false | false | 循环间隔，单位为毫秒。 |  
| repeatCount | number | false | false | 循环次数。 |  
| isDeepIdle | boolean | false | false | 是否要求设备进入空闲状态。<br>- true表示需要，false表示不需要。 |  
| idleWaitTime | number | false | false |  空闲等待时间，单位为毫秒。 |  
| parameters | { [key: string]: number \| string \| boolean } | false | false | 携带参数信息。 |  
    
## startWork    
申请延迟任务。  
 **调用形式：**     
- startWork(work: WorkInfo): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| work | WorkInfo | true | 要添加到执行队列的延迟任务。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9700001 | Memory operation failed. |  
| 9700002 | Parcel operation failed. |  
| 9700003 | System service operation failed. |  
| 9700004 | Check workInfo failed. |  
| 9700005 | StartWork failed. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
    
  let workInfo: workScheduler.WorkInfo = {  
      workId: 1,  
      batteryStatus:workScheduler.BatteryStatus.BATTERY_STATUS_LOW,  
      isRepeat: false,  
      isPersisted: true,  
      bundleName: "com.example.myapplication",  
      abilityName: "MyExtension",  
      parameters: {  
          mykey0: 1,  
          mykey1: "string value",  
          mykey2: true,  
          mykey3: 1.5  
      }  
  }  
  try{  
    workScheduler.startWork(workInfo);  
    console.info('workschedulerLog startWork success');  
  } catch (error) {  
    console.error(`workschedulerLog startwork failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);  
  }  
    
```    
  
    
## stopWork    
取消延迟任务。  
 **调用形式：**     
- stopWork(work: WorkInfo, needCancel?: boolean): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| work | WorkInfo | true | 要停止或移除的延迟任务。 |  
| needCancel | boolean | false | 是否需要移除的任务。<br>- true表示停止并移除，false表示只停止不移除。默认为false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9700001 | Memory operation failed. |  
| 9700002 | Parcel operation failed. |  
| 9700003 | System service operation failed. |  
| 9700004 | Check workInfo failed. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
  let workInfo: workScheduler.WorkInfo = {  
      workId: 1,  
      batteryStatus:workScheduler.BatteryStatus.BATTERY_STATUS_LOW,  
      isRepeat: false,  
      isPersisted: true,  
      bundleName: "com.example.myapplication",  
      abilityName: "MyExtension",  
      parameters: {  
          mykey0: 1,  
          mykey1: "string value",  
          mykey2: true,  
          mykey3: 1.5  
      }  
     }  
  try{  
    workScheduler.stopWork(workInfo, false);  
    console.info('workschedulerLog stopWork success');  
  } catch (error) {  
    console.error(`workschedulerLog stopWork failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);  
  }  
    
```    
  
    
## getWorkStatus    
通过workId获取延迟任务  
 **调用形式：**     
    
- getWorkStatus(workId: number, callback: AsyncCallback\<WorkInfo>): void    
起始版本： 9    
- getWorkStatus(workId: number): Promise\<WorkInfo>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| workId | number | true | 延迟任务Id。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果workId有效，则返回从WorkSchedulerService获取的任务，否则抛出异常。 |  
| Promise<WorkInfo> | Promise对象，如果workId有效，则返回从WorkSchedulerService获取的任务。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9700001 | Memory operation failed. |  
| 9700002 | Parcel operation failed. |  
| 9700003 | System service operation failed. |  
| 9700004 | Check workInfo failed. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
  workScheduler.getWorkStatus(50, (error: BusinessError, res: workScheduler.WorkInfo) => {  
    if (error) {  
      console.error(`workschedulerLog getWorkStatus failed. code is ${error.code} message is ${error.message}`);  
    } else {  
      console.info(`workschedulerLog getWorkStatus success, ${JSON.stringify(res)}`);  
    }  
  });  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
  workScheduler.getWorkStatus(50).then((res: workScheduler.WorkInfo) => {  
    console.info(`workschedulerLog getWorkStatus success, ${JSON.stringify(res)}`);  
  }).catch((error: BusinessError) => {  
    console.error(`workschedulerLog getWorkStatus failed. code is ${error.code} message is ${error.message}`);  
  })  
    
```    
  
    
## obtainAllWorks<sup>(deprecated)</sup>    
获取当前应用所有的延迟任务，使用Callback异步回调。  
  
 **调用形式：**     
- obtainAllWorks(callback: AsyncCallback\<void>): Array\<WorkInfo>  
  
 **废弃说明：** 从API version 10 开始废弃。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 。回调函数，获取成功时，err为undefined，否则为错误对象 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<WorkInfo> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9700001 | Memory operation failed |  
| 9700002 | Parcel operation failed. |  
| 9700003 | System service operation failed. |  
    
 **示例代码：**   
    
## obtainAllWorks<sup>(10+)</sup>    
获取当前应用所有的延迟任务  
 **调用形式：**     
    
- obtainAllWorks(callback: AsyncCallback\<Array\<WorkInfo>>): void    
起始版本： 10    
- obtainAllWorks(): Promise\<Array\<WorkInfo>>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Array<WorkInfo>> | Promise对象，返回当前应用所有的延迟任务。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9700001 |  |  
| 9700002 |  |  
| 9700003 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
workScheduler.obtainAllWorks((error: BusinessError, res: Array<workScheduler.WorkInfo>) =>{  
if (error) {  
console.error(`workschedulerLog obtainAllWorks failed. code is ${error.code} message is ${error.message}`);  
} else {  
console.info(`workschedulerLog obtainAllWorks success, data is: ${JSON.stringify(res)}`);  
}  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
workScheduler.obtainAllWorks().then((res: Array<workScheduler.WorkInfo>) => {  
console.info(`workschedulerLog obtainAllWorks success, data is: ${JSON.stringify(res)}`);  
}).catch((error: BusinessError) => {  
console.error(`workschedulerLog obtainAllWorks failed. code is ${error.code} message is ${error.message}`);  
})  
    
```    
  
    
## stopAndClearWorks    
停止和取消当前应用所有的延迟任务。  
 **调用形式：**     
- stopAndClearWorks(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9700001 | Memory operation failed. |  
| 9700002 | Parcel operation failed. |  
| 9700003 | System service operation failed. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
  try{  
    workScheduler.stopAndClearWorks();  
    console.info(`workschedulerLog stopAndClearWorks success`);  
  } catch (error) {  
    console.error(`workschedulerLog stopAndClearWorks failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);  
  }  
    
```    
  
    
## isLastWorkTimeOut<sup>(deprecated)</sup>    
检查延迟任务的最后一次执行是否超时。  
 **调用形式：**     
- isLastWorkTimeOut(workId: number, callback: AsyncCallback\<void>): boolean  
  
 **废弃说明：** 从API version 10 开始废弃。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| workId<sup>(deprecated)</sup> | number | true |  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9700001 |  |  
| 9700002 |  |  
| 9700003 |  |  
| 9700004 |  |  
    
## isLastWorkTimeOut<sup>(10+)</sup>    
检查延迟任务的最后一次执行是否超时  
 **调用形式：**     
    
- isLastWorkTimeOut(workId: number, callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- isLastWorkTimeOut(workId: number): Promise\<boolean>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| workId | number | true | 指定延迟任务的Id。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<boolean> | Promise对象。返回true表示指定任务的最后一次执行超时，false表示未超时。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9700001 | Memory operation failed. |  
| 9700002 | Parcel operation failed. |  
| 9700003 | System service operation failed. |  
| 9700004 | Check workInfo failed. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
  workScheduler.isLastWorkTimeOut(500, (error: BusinessError, res: boolean) =>{  
    if (error) {  
      console.error(`workschedulerLog isLastWorkTimeOut failed. code is ${error.code} message is ${error.message}`);  
    } else {  
      console.info(`workschedulerLog isLastWorkTimeOut success, data is: ${res}`);  
    }  
  });  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
  workScheduler.isLastWorkTimeOut(500)  
    .then((res: boolean) => {  
      console.info(`workschedulerLog isLastWorkTimeOut success, data is: ${res}`);  
    })  
    .catch((error: BusinessError) =>  {  
      console.error(`workschedulerLog isLastWorkTimeOut failed. code is ${error.code} message is ${error.message}`);  
    });  
    
```    
  
    
## NetworkType    
触发延迟回调的网络类型。    
    
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NETWORK_TYPE_ANY | 0 | 表示这个触发条件是任何类型的网络连接。 |  
| NETWORK_TYPE_MOBILE | 1 | 表示这个触发条件是Mobile网络连接。 |  
| NETWORK_TYPE_WIFI | 2 | 表示这个触发条件是Wifi类型的网络连接。 |  
| NETWORK_TYPE_BLUETOOTH | 3 | 表示这个触发条件是Bluetooth网络连接。 |  
| NETWORK_TYPE_WIFI_P2P | 4 | 表示这个触发条件是Wifi P2P网络连接。 |  
| NETWORK_TYPE_ETHERNET | 5 | 表示这个触发条件是有线网络连接。 |  
    
## ChargingType    
触发延迟回调的充电类型。    
    
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CHARGING_PLUGGED_ANY | 0 | 表示这个触发条件是任何类型的充电器连接。 |  
| CHARGING_PLUGGED_AC | 1 | 表示这个触发条件是直流充电器连接。 |  
| CHARGING_PLUGGED_USB | 2 | 表示这个触发条件是USB充连接。 |  
| CHARGING_PLUGGED_WIRELESS | 3 | 表示这个触发条件是无线充电器连接。 |  
    
## BatteryStatus    
触发延迟回调的电池状态    
    
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| BATTERY_STATUS_LOW | 0 | 表示这个触发条件是低电告警。 |  
| BATTERY_STATUS_OKAY | 1 | 表示这个触发条件是从低电恢复到正常电量。  |  
| BATTERY_STATUS_LOW_OR_OKAY | 2 | 表示这个触发条件是从低电恢复到正常电量或者低电告警。  |  
    
## StorageRequest    
触发延迟回调的存储状态。    
    
 **系统能力:**  SystemCapability.ResourceSchedule.WorkScheduler    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STORAGE_LEVEL_LOW | 0 | 表示这个触发条件是存储空间不足。 |  
| STORAGE_LEVEL_OKAY | 1 | 表示这个触发条件是从存储空间不足恢复到正常。   |  
| STORAGE_LEVEL_LOW_OR_OKAY | 2 | 表示这个触发条件是存储空间不足或者从存储空间不足恢复到正常。 |  
