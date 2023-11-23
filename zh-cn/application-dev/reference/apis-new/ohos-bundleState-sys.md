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
    
## queryBundleStateInfos<sup>(deprecated)</sup>    
通过指定起始和结束时间查询应用使用时长统计信息，使用Callback形式返回。  
 **调用形式：**     
- queryBundleStateInfos(begin: number, end: number, callback: AsyncCallback\<BundleActiveInfoResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceschedule.usageStatistics.queryBundleStatsInfos。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.App  
 **需要权限：** ohos.permission.BUNDLE_ACTIVE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| begin<sup>(deprecated)</sup> | number | true | 起始时间，单位毫秒。<br/> |  
| end<sup>(deprecated)</sup> | number | true | 结束时间，单位毫秒。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<BundleActiveInfoResponse> | true | <table><tbody><tr><td><br/>指定的callback回调方法。返回指定起始和结束时间内应用使用时长统计信息。</td></tr></tbody></table> |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
bundleState.queryBundleStateInfos(0, 20000000000000, (err: BusinessError ,  
  res: bundleState.BundleActiveInfoResponse ) => {  
  if (err) {  
    console.log('BUNDLE_ACTIVE queryBundleStateInfos callback failed, because: ' + err.code);  
  } else {  
    console.log('BUNDLE_ACTIVE queryBundleStateInfos callback success.');  
    console.log('BUNDLE_ACTIVE queryBundleStateInfos callback result ' + JSON.stringify(res));  
  }  
});  
    
```    
  
    
## queryBundleStateInfos<sup>(deprecated)</sup>    
通过指定起始和结束时间查询应用使用时长统计信息，使用Promise形式返回。  
 **调用形式：**     
- queryBundleStateInfos(begin: number, end: number): Promise\<BundleActiveInfoResponse>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceschedule.usageStatistics.queryBundleStatsInfos。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.App  
 **需要权限：** ohos.permission.BUNDLE_ACTIVE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| begin<sup>(deprecated)</sup> | number | true | 起始时间，单位毫秒。<br/> |  
| end<sup>(deprecated)</sup> | number | true | 结束时间，单位毫秒。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<BundleActiveInfoResponse> | 指定的Promise回调方法。返回指定起始和结束时间内应用使用时长统计信息。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
bundleState.queryBundleStateInfos(0, 20000000000000).then((res: bundleState.BundleActiveInfoResponse) => {  
  console.log('BUNDLE_ACTIVE queryBundleStateInfos promise success.');  
  console.log('BUNDLE_ACTIVE queryBundleStateInfos promise result ' + JSON.stringify(res));  
}).catch((err: BusinessError) => {  
  console.log('BUNDLE_ACTIVE queryBundleStateInfos promise failed, because: ' + err.code);  
});  
    
```    
  
    
## queryBundleStateInfoByInterval<sup>(deprecated)</sup>    
通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息，使用Callback形式返回。  
 **调用形式：**     
- queryBundleStateInfoByInterval(     byInterval: IntervalType,     begin: number,     end: number,     callback: AsyncCallback\<Array\<BundleStateInfo>>   ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceschedule.usageStatistics.queryBundleStatsInfoByInterval。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.App  
 **需要权限：** ohos.permission.BUNDLE_ACTIVE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| byInterval<sup>(deprecated)</sup> | IntervalType | true | 查询类型。 |  
| begin<sup>(deprecated)</sup> | number | true | 起始时间，单位毫秒。 |  
| end<sup>(deprecated)</sup> | number | true | 结束时间，单位毫秒。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<BundleStateInfo>> | true | 指定的callback回调方法。返回指定时间段间隔（天、周、月、年）查询应用使用时长统计信息。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
bundleState.queryBundleStateInfoByInterval(bundleState.IntervalType.BY_OPTIMIZED, 0, 20000000000000, (err: BusinessError, res: Array<bundleState.BundleStateInfo>) => {  
  if (err) {  
    console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval callback failed, because: ' + err.code);  
  } else {  
    console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval callback success.');  
    for (let i = 0; i < res.length; i++) {  
      console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval callback number : ' + (i + 1));  
      console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval callback result ' + JSON.stringify(res[i]));  
    }  
  }  
});  
    
```    
  
    
## queryBundleStateInfoByInterval<sup>(deprecated)</sup>    
通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息，使用Promise形式返回。  
 **调用形式：**     
- queryBundleStateInfoByInterval(     byInterval: IntervalType,     begin: number,     end: number   ): Promise\<Array\<BundleStateInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceschedule.usageStatistics.queryBundleStatsInfoByInterval。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.App  
 **需要权限：** ohos.permission.BUNDLE_ACTIVE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| byInterval<sup>(deprecated)</sup> | IntervalType | true | 查询类型。 |  
| begin<sup>(deprecated)</sup> | number | true | 起始时间，单位毫秒。 |  
| end<sup>(deprecated)</sup> | number | true | 结束时间，单位毫秒。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<BundleStateInfo>> | 指定的Promise回调方法。返回指定时间段间隔（天、周、月、年）查询应用使用时长统计信息。 |  
    
 **示例代码：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
bundleState.queryBundleStateInfoByInterval(bundleState.IntervalType.BY_OPTIMIZED, 0, 20000000000000).then((res: Array<bundleState.BundleStateInfo>) => {  
  console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise success.');  
  for (let i = 0; i < res.length; i++) {  
    console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise number : ' + (i + 1));  
    console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise result ' + JSON.stringify(res[i]));  
  }  
}).catch((err: BusinessError) => {  
  console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise failed, because: ' + err.code);  
});  
    
```    
  
    
## queryBundleActiveStates<sup>(deprecated)</sup>    
通过指定起始和结束时间查询所有应用的事件集合，使用Callback形式返回。  
 **调用形式：**     
- queryBundleActiveStates(begin: number, end: number, callback: AsyncCallback\<Array\<BundleActiveState>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceschedule.usageStatistics.queryBundleEvents。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.App  
 **需要权限：** ohos.permission.BUNDLE_ACTIVE_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| begin<sup>(deprecated)</sup> | number | true | 起始时间，单位毫秒。<br/> |  
| end<sup>(deprecated)</sup> | number | true | 结束时间，单位毫秒。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<BundleActiveState>> | true | 指定的callback回调方法。返回指定起始和结束时间查询所有应用的事件集合。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
bundleState.queryBundleActiveStates(0, 20000000000000, (err: BusinessError, res: Array<bundleState.BundleActiveState>) => {  
  if (err) {  
    console.log('BUNDLE_ACTIVE queryBundleActiveStates callback failed, because: ' + err.code);  
  } else {  
    console.log('BUNDLE_ACTIVE queryBundleActiveStates callback success.');  
    for (let i = 0; i < res.length; i++) {  
      console.log('BUNDLE_ACTIVE queryBundleActiveStates callback number : ' + (i + 1));  
      console.log('BUNDLE_ACTIVE queryBundleActiveStates callback result ' + JSON.stringify(res[i]));  
    }  
  }  
});  
    
```    
  
    
## queryBundleActiveStates<sup>(deprecated)</sup>    
通过指定起始和结束时间查询所有应用的事件集合，使用Promise形式返回。  
 **调用形式：**     
- queryBundleActiveStates(begin: number, end: number): Promise\<Array\<BundleActiveState>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceschedule.usageStatistics.queryBundleEvents。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.ResourceSchedule.UsageStatistics.App  
 **需要权限：** ohos.permission.BUNDLE_ACTIVE_INFO    
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
  
bundleState.queryBundleActiveStates(0, 20000000000000).then((res: Array<bundleState.BundleActiveState>) => {  
  console.log('BUNDLE_ACTIVE queryBundleActiveStates promise success.');  
  for (let i = 0; i < res.length; i++) {  
    console.log('BUNDLE_ACTIVE queryBundleActiveStates promise number : ' + (i + 1));  
    console.log('BUNDLE_ACTIVE queryBundleActiveStates promise result ' + JSON.stringify(res[i]));  
  }  
}).catch((err: BusinessError) => {  
  console.log('BUNDLE_ACTIVE queryBundleActiveStates promise failed, because: ' + err.code);  
});  
    
```    
  
