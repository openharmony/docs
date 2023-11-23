# @ohos.file.storageStatistics    
该模块提供空间查询相关的常用功能：包括对内外卡的空间查询，对应用分类数据统计的查询，对应用数据的查询等。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import storageStatistics from '@ohos.file.storageStatistics'    
```  
    
## BundleStats<sup>(9+)</sup>    
  
  
 **系统能力:**  SystemCapability.FileManagement.StorageService.SpatialStatistics    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.StorageService.SpatialStatistics    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| appSize<sup>(9+)</sup> | number | false | true | app数据大小（单位为Byte） |  
| cacheSize<sup>(9+)</sup> | number | false | true | 缓存数据大小（单位为Byte） |  
| dataSize<sup>(9+)</sup> | number | false | true | 应用总数据大小（单位为Byte） |  
    
## getCurrentBundleStats<sup>(9+)</sup>    
第三方应用异步获取当前应用存储空间大小（单位为Byte）。  
 **调用形式：**     
    
- getCurrentBundleStats(callback: AsyncCallback\<BundleStats>): void    
起始版本： 9    
- getCurrentBundleStats(): Promise\<BundleStats>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.StorageService.SpatialStatistics    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取指定卷上的应用存储空间大小之后的回调 |  
| Promise<BundleStats> | Promise对象，返回指定卷上的应用存空间大小（单位为Byte） |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | The input parameter is invalid. |  
| 13600001 | IPC error. |  
| 13900042 | Unknown error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
storageStatistics.getCurrentBundleStats((error: BusinessError, bundleStats: storageStatistics.BundleStats) => {  
  if (error) {  
    console.info("getCurrentBundleStats failed with error:" + JSON.stringify(error));  
  } else {  
    // do something  
    console.info("getCurrentBundleStats successfully:" + JSON.stringify(bundleStats));  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
storageStatistics.getCurrentBundleStats().then((BundleStats: storageStatistics.BundleStats) => {  
  console.info("getCurrentBundleStats successfully:" + JSON.stringify(BundleStats));  
}).catch((err: BusinessError) => {  
  console.info("getCurrentBundleStats failed with error:"+ JSON.stringify(err));  
});  
    
```    
  
