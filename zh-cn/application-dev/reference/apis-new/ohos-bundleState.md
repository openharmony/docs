# @ohos.bundleState    
本模块提供设备使用信息统计能力。  
  
设备使用信息统计，系统应用可调用接口实现如下功能：  
  
- 查询设备上各应用在不同时间段的使用时长、各应用的事件（前台、后台、长时任务开始、长时任务结束）信息及各应用的通知次数信息。  
- 查询应用分组信息（仅限自身应用）。  
- 查询应用空闲状态（其他应用和自身应用）。  
  
三方应用可调用接口实现如下功能：  
  
- 查询应用空闲状态（仅限自身应用）。  
- 查询应用分组信息（仅限自身应用）。  
- 查询应用事件（仅限自身应用）。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import bundleState from '@ohos.bundleState'    
```  
    
## BundleStateInfo<sup>(deprecated)</sup>    
提供应用使用时长的具体信息。  
    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.resourceschedule.usageStatistics.BundleStatsInfo替代。  
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.App    
### 属性    
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.App    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。 |  
| abilityInFgTotalTime<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用在前台使用的总时间。<br/> |  
| abilityPrevAccessTime<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用最后一次使用的时间。<br/> |  
| abilityPrevSeenTime<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用最后一次在前台可见的时间。<br/> |  
| abilitySeenTotalTime<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用在前台可见的总时间。<br/> |  
| bundleName<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用的bundleName。       |  
| fgAbilityAccessTotalTime<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用访问前台的总时间。<br/> |  
| fgAbilityPrevAccessTime<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用最后一次访问前台的时间。<br/> |  
| infosBeginTime<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>BundleActiveInfo对象中第一条应用使用统计的记录时间。<br/> |  
| infosEndTime<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>BundleActiveInfo对象中最后一条应用使用统计的记录时间。<br/> |  
    
### merge<sup>(deprecated)</sup>    
合并相同包名的应用使用信息。  
  
 **调用形式：**     
- merge(toMerge: BundleStateInfo): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.App    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| toMerge<sup>(deprecated)</sup> | BundleStateInfo | true | 相同包名的应用使用统计信息。<br/> |  
    
## BundleActiveState<sup>(deprecated)</sup>    
提供应用事件的具体信息。提供应用使用时长的具体信息。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.resourceschedule.usageStatistics.BundleEvents替代。  
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.App    
### 属性    
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.App    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| appUsagePriorityGroup<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用程序的使用优先级组。<br/> |  
| bundleName<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用包名。<br/> |  
| indexOfLink<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>快捷方式id。<br/> |  
| nameOfClass<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>类名。<br/> |  
| stateOccurredTime<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用事件发生的时间戳。<br/> |  
| stateType<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>应用事件类型。<br/> |  
    
## isIdleState<sup>(deprecated)</sup>    
判断指定bundleName的应用当前是否是空闲状态，三方应用只能查询自身的空闲状态，查询其他应用空闲状态，需要申请权限ohos.permission.BUNDLE_ACTIVE_INFO，使用Callback形式返回。  
 **调用形式：**     
- isIdleState(bundleName: string, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceschedule.usageStatistics.isIdleState。  
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.AppGroup    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 应用的bundleName。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 指定的callback回调方法。如果指定的bundleName有效，则返回指定bundleName的应用当前是否是空闲状态；否则返回null。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
bundleState.isIdleState("com.ohos.camera", (err: BusinessError, res: boolean) => {  
  if (err) {  
    console.log('BUNDLE_ACTIVE isIdleState callback failed, because: ' + err.code);  
  } else {  
    console.log('BUNDLE_ACTIVE isIdleState callback succeeded, result: ' + JSON.stringify(res));  
  }  
});  
    
```    
  
    
## isIdleState<sup>(deprecated)</sup>    
判断指定bundleName的应用当前是否是空闲状态，三方应用只能查询自身的空闲状态，查询其他应用空闲状态，需要申请权限ohos.permission.BUNDLE_ACTIVE_INFO，使用Promise形式返回。  
 **调用形式：**     
- isIdleState(bundleName: string): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceschedule.usageStatistics.isIdleState。  
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.AppGroup    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 应用的bundleName。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 指定的Promise回调方法。如果指定的bundleName有效，则返回指定bundleName的应用当前是否是空闲状态；否则返回null。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
bundleState.isIdleState("com.ohos.camera").then((res: boolean) => {  
  console.log('BUNDLE_ACTIVE isIdleState promise succeeded, result: ' + JSON.stringify(res));  
}).catch((err: BusinessError) => {  
  console.log('BUNDLE_ACTIVE isIdleState promise failed, because: ' + err.code);  
});  
    
```    
  
    
## queryAppUsagePriorityGroup<sup>(deprecated)</sup>    
查询当前应用的优先级分组。使用Promise形式返回其应用分组。  
 **调用形式：**     
- queryAppUsagePriorityGroup(callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceschedule.usageStatistics.queryAppGroup。  
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.AppGroup    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 指定的CallBack回调方法。返回查询的应用分组。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```null    
import { BusinessError } from '@ohos.base';  
  
bundleState.queryAppUsagePriorityGroup((err: BusinessError, res: number) => {  
  if(err) {  
    console.log('BUNDLE_ACTIVE QueryPackageGroup callback failed. because: ' + err.code);  
  } else {  
    console.log('BUNDLE_ACTIVE QueryPackageGroup callback succeeded. result: ' + JSON.stringify(res));  
  }  
});  
    
```    
  
    
## queryAppUsagePriorityGroup<sup>(deprecated)</sup>    
查询当前应用的优先级分组。使用Promise形式返回其应用分组。  
 **调用形式：**     
- queryAppUsagePriorityGroup(): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceschedule.usageStatistics.queryAppGroup。  
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.AppGroup    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 指定的Promise回调方法。返回查询的应用分组结果。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
bundleState.queryAppUsagePriorityGroup().then((res: number) => {  
  console.log('BUNDLE_ACTIVE QueryPackageGroup promise succeeded. result: ' + JSON.stringify(res));  
}).catch((err: BusinessError) => {  
  console.log('BUNDLE_ACTIVE QueryPackageGroup promise failed. because: ' + err.code);  
});  
    
```    
  
    
## BundleActiveInfoResponse<sup>(deprecated)</sup>    
提供应用使用时长的具体信息。  
    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.resourceschedule.usageStatistics.BundleStatsMap替代。  
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.App    
## IntervalType<sup>(deprecated)</sup>    
通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息，使用Callback形式返回。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.resourceschedule.usageStatistics.IntervalType替代。    
    
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.App    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| BY_OPTIMIZED<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示系统自行判断最合适的查询类型（天、周、月、年）去查询指定时间段间隔的应用使用时长信息。<br/> |  
| BY_DAILY<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示系统按照天去查询指定时间段间隔的应用使用时长信息。<br/> |  
| BY_WEEKLY<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示系统按照周去查询指定时间段间隔的应用使用时长信息。<br/> |  
| BY_MONTHLY<sup>(deprecated)</sup> | 3 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示系统按照月去查询指定时间段间隔的应用使用时长信息。<br/> |  
| BY_ANNUALLY<sup>(deprecated)</sup> | 4 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示系统按照年去查询指定时间段间隔的应用使用时长信息。<br/> |  
    
## queryCurrentBundleActiveStates<sup>(deprecated)</sup>    
通过指定起始和结束时间查询当前应用的事件集合，使用Callback形式返回。  
 **调用形式：**     
- queryCurrentBundleActiveStates(     begin: number,     end: number,     callback: AsyncCallback\<Array\<BundleActiveState>>   ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceschedule.usageStatistics.queryCurrentBundleEvents。  
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.App    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| begin<sup>(deprecated)</sup> | number | true | 起始时间，单位毫秒。 |  
| end<sup>(deprecated)</sup> | number | true | 结束时间，单位毫秒。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<BundleActiveState>> | true | 指定的callback回调方法。返回指定起始和结束时间查询当前应用的事件集合。 |  
    
## queryCurrentBundleActiveStates<sup>(deprecated)</sup>    
通过指定起始和结束时间查询当前应用的事件集合，使用Promise形式返回。  
 **调用形式：**     
- queryCurrentBundleActiveStates(begin: number, end: number): Promise\<Array\<BundleActiveState>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceschedule.usageStatistics.queryCurrentBundleEvents。  
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.App    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| begin<sup>(deprecated)</sup> | number | true | 起始时间，单位毫秒。<br/> |  
| end<sup>(deprecated)</sup> | number | true | 结束时间，单位毫秒。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<BundleActiveState>> | 指定的Promise回调方法。返回指定起始和结束时间查询所有应用的事件集合。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
bundleState.queryCurrentBundleActiveStates(0, 20000000000000).then((res: Array<bundleState.BundleActiveState>) => {  
  console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise success.');  
  for (let i = 0; i < res.length; i++) {  
    console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise number : ' + (i + 1));  
    console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise result ' + JSON.stringify(res[i]));  
  }  
}).catch((err: BusinessError) => {  
  console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise failed, because: ' + err.code);  
});  
    
```    
  
