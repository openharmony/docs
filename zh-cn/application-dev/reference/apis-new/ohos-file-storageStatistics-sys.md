# @ohos.file.storageStatistics    
该模块提供空间查询相关的常用功能：包括对内外卡的空间查询，对应用分类数据统计的查询，对应用数据的查询等。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import storageStatistics from '@ohos.file.storageStatistics'    
```  
    
## getTotalSizeOfVolume    
异步获取外置存储设备中指定卷设备的总空间大小（单位为Byte）。  
 **调用形式：**     
    
- getTotalSizeOfVolume(volumeUuid: string, callback: AsyncCallback\<number>): void    
起始版本： 8    
- getTotalSizeOfVolume(volumeUuid: string): Promise\<number>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.SpatialStatistics  
 **需要权限：** ohos.permission.STORAGE_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| volumeUuid | string | true | 卷设备uuid |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取指定卷设备总空间之后的回调 |  
| Promise<number> | Promise对象，返回指定卷设备的总空间大小（单位为Byte |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
| 13600001 | IPC error. |  
| 13600008 | No such object. |  
| 13900042 | Unknown error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import volumemanager from "@ohos.file.volumeManager";  
import { BusinessError } from '@ohos.base';  
volumemanager.getAllVolumes().then((volumes: Array<volumemanager.Volume>) => {  
  let uuid: string = volumes[0].uuid;  
  storageStatistics.getTotalSizeOfVolume(uuid, (error: BusinessError, number: number) => {  
    if (error) {  
      console.info("getTotalSizeOfVolume failed with error:" + JSON.stringify(error));  
    } else {  
      // do something  
      console.info("getTotalSizeOfVolume successfully:" + number);  
    }  
  });  
}).catch((err: BusinessError) => {  
  console.info("getAllVolumes failed with error:" + JSON.stringify(err));  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import volumemanager from "@ohos.file.volumeManager";  
import { BusinessError } from '@ohos.base';  
volumemanager.getAllVolumes().then((volumes: Array<volumemanager.Volume>) => {  
  let uuid: string = volumes[0].uuid;  
  storageStatistics.getTotalSizeOfVolume(uuid).then((number: number) => {  
    console.info("getTotalSizeOfVolume successfully:" + number);  
  }).catch((err: BusinessError) => {  
    console.info("getTotalSizeOfVolume failed with error:" + JSON.stringify(err));  
  });  
}).catch((err: BusinessError) => {  
  console.info("getAllVolumes failed with error:" + JSON.stringify(err));  
});  
    
```    
  
    
## getFreeSizeOfVolume    
异步获取外置存储设备中指定卷设备的可用空间大小（单位为Byte）。  
 **调用形式：**     
    
- getFreeSizeOfVolume(volumeUuid: string, callback: AsyncCallback\<number>): void    
起始版本： 8    
- getFreeSizeOfVolume(volumeUuid: string): Promise\<number>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.SpatialStatistics  
 **需要权限：** ohos.permission.STORAGE_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| volumeUuid | string | true | 卷设备uuid |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取指定卷可用空间之后的回调 |  
| Promise<number> | Promise对象，返回指定卷的可用空间大小（单位为Byte） |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
| 13600001 | IPC error. |  
| 13600008 | No such object. |  
| 13900042 | Unknown error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import volumemanager from "@ohos.file.volumeManager";  
import { BusinessError } from '@ohos.base';  
volumemanager.getAllVolumes().then((volumes: Array<volumemanager.Volume>) => {  
  let uuid: string = volumes[0].uuid;  
  storageStatistics.getFreeSizeOfVolume(uuid, (error: BusinessError, number: number) => {  
    if (error) {  
      console.info("getFreeSizeOfVolume failed with error:" + JSON.stringify(error));  
    } else {  
      // do something  
      console.info("getFreeSizeOfVolume successfully: " + number);  
    }  
  });  
}).catch((err: BusinessError) => {  
  console.info("getAllVolumes failed with error:" + JSON.stringify(err));  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import volumemanager from "@ohos.file.volumeManager";  
import { BusinessError } from '@ohos.base';  
volumemanager.getAllVolumes().then((volumes: Array<volumemanager.Volume>) => {  
  let uuid: string = volumes[0].uuid;  
  storageStatistics.getFreeSizeOfVolume(uuid).then((number: number) => {  
    console.info("getFreeSizeOfVolume successfully:" + number);  
  }).catch((err: BusinessError) => {  
    console.info("getFreeSizeOfVolume failed with error:" + JSON.stringify(err));  
  });  
}).catch((err: BusinessError) => {  
  console.info("getAllVolumes failed with error:" + JSON.stringify(err));  
});  
    
```    
  
    
## getBundleStats<sup>(9+)</sup>    
异步获取应用存储空间大小（单位为Byte）。  
 **调用形式：**     
    
- getBundleStats(packageName: string, callback: AsyncCallback\<BundleStats>): void    
起始版本： 9    
- getBundleStats(packageName: string): Promise\<BundleStats>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.SpatialStatistics  
 **需要权限：** ohos.permission.STORAGE_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| packageName | string | true | 应用包名 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取指定卷上的应用存储数据之后的回调 |  
| Promise<BundleStats> | Promise对象，返回指定卷上的应用存储数据（单位为Byte） |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
| 13600001 | IPC error. |  
| 13600008 | No such object. |  
| 13900042 | Unknown error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let packageName: string = "";  
storageStatistics.getBundleStats(packageName, (error: BusinessError, BundleStats: storageStatistics.BundleStats) => {  
  if (error) {  
    console.info("getBundleStats failed with error:" + JSON.stringify(error));  
  }  else {  
    // do something  
    console.info("getBundleStats successfully:" + JSON.stringify(BundleStats));  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let packageName: string = "";  
storageStatistics.getBundleStats(packageName).then((BundleStats: storageStatistics.BundleStats) => {  
  console.info("getBundleStats successfully:" + JSON.stringify(BundleStats));  
}).catch((err: BusinessError) => {  
  console.info("getBundleStats failed with error:" + JSON.stringify(err));  
});  
    
```    
  
    
## getSystemSize<sup>(9+)</sup>    
异步获取系统数据的空间大小（单位为Byte）。  
 **调用形式：**     
    
- getSystemSize(callback: AsyncCallback\<number>): void    
起始版本： 9    
- getSystemSize(): Promise\<number>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.SpatialStatistics  
 **需要权限：** ohos.permission.STORAGE_MANAGER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取系统数据的空间大小之后的回调 |  
| Promise<number> | Promise对象，返回系统数据的空间大小（单位为Byte） |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
| 13600001 | IPC error. |  
| 13900042 | Unknown error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
storageStatistics.getSystemSize((error: BusinessError, number: number) => {  
  if (error) {  
    console.info("getSystemSize failed with error:" + JSON.stringify(error));  
  } else {  
    // do something  
    console.info("getSystemSize successfully:" + number);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
storageStatistics.getSystemSize().then((number: number) => {  
  console.info("getSystemSize successfully:" + number);  
}).catch((err: BusinessError) => {  
  console.info("getSystemSize failed with error:" + JSON.stringify(err));  
});  
    
```    
  
    
## StorageStats<sup>(9+)</sup>  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.SpatialStatistics    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.StorageService.SpatialStatistics    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| total<sup>(9+)</sup> | number | false | true | 内置存储总空间大小（单位为Byte） |  
| audio<sup>(9+)</sup> | number | false | true | 音频数据大小 （单位为Byte） |  
| video<sup>(9+)</sup> | number | false | true | 视频数据大小（单位为Byte） |  
| image<sup>(9+)</sup> | number | false | true | 图像数据大小 （单位为Byte） |  
| file<sup>(9+)</sup> | number | false | true | 文件数据大小 （单位为Byte） |  
| app<sup>(9+)</sup> | number | false | true | 应用数据大小（单位为Byte） |  
    
## getUserStorageStats<sup>(9+)</sup>    
异步获取当前用户各类别存储空间大小（单位为Byte）。  
 **调用形式：**     
    
- getUserStorageStats(): Promise\<StorageStats>    
起始版本： 9    
- getUserStorageStats(callback: AsyncCallback\<StorageStats>): void    
起始版本： 9    
- getUserStorageStats(userId: number): Promise\<StorageStats>    
起始版本： 9    
- getUserStorageStats(userId: number, callback: AsyncCallback\<StorageStats>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.SpatialStatistics  
 **需要权限：** ohos.permission.STORAGE_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| userId | number | true | 用户id |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回各类别数据大小之后的回调 |  
| Promise<StorageStats> | Promise对象，返回当前用户各类别存储空间大小（单位为Byte） |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
| 13600001 | IPC error. |  
| 13900042 | Unknown error. |  
| 13600009 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let userId: number = 100;  
storageStatistics.getUserStorageStats(userId, (error: BusinessError, storageStats: storageStatistics.StorageStats) => {  
  if (error) {  
    console.info("getUserStorageStats failed with error:" + JSON.stringify(error));  
  } else {  
    // do something  
    console.info("getUserStorageStats successfully:" + JSON.stringify(storageStats));  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let userId: number = 100;  
storageStatistics.getUserStorageStats(userId).then((storageStats: storageStatistics.StorageStats) => {  
  console.info("getUserStorageStats successfully:" + JSON.stringify(storageStats));  
}).catch((err: BusinessError) => {  
  console.info("getUserStorageStats failed with error:" + JSON.stringify(err));  
});  
    
```    
  
    
## getTotalSize<sup>(9+)</sup>    
获取内置存储的总空间大小（单位为Byte）。  
 **调用形式：**     
    
- getTotalSize(callback: AsyncCallback\<number>): void    
起始版本： 9    
- getTotalSize(): Promise\<number>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.SpatialStatistics  
 **需要权限：** ohos.permission.STORAGE_MANAGER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取内置存储的总空间大小之后的回调 |  
| Promise<number> | Promise对象，返回内置存储的总空间大小（单位为Byte） |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
| 13600001 | IPC error. |  
| 13900042 | Unknown error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
storageStatistics.getTotalSize((error: BusinessError, number: number) => {  
  if (error) {  
    console.info("getTotalSize failed with error:" + JSON.stringify(error));  
  } else {  
    // do something  
    console.info("getTotalSize successfully:" + number);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
storageStatistics.getTotalSize().then((number: number) => {  
  console.info("getTotalSize successfully:" + JSON.stringify(number));  
}).catch((err: BusinessError) => {  
  console.info("getTotalSize failed with error:"+ JSON.stringify(err));  
});  
    
```    
  
    
## getTotalSizeSync<sup>(10+)</sup>    
同步获取内置存储的总空间大小（单位为Byte）。  
 **调用形式：**     
- getTotalSizeSync(): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.SpatialStatistics  
 **需要权限：** ohos.permission.STORAGE_MANAGER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
| 13600001 | IPC error. |  
| 13900042 | Unknown error. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
try {  
  let number = storageStatistics.getTotalSizeSync();  
  console.info("getTotalSizeSync successfully:" + JSON.stringify(number));  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.info("getTotalSizeSync failed with error:" + JSON.stringify(error));  
}  
    
```    
  
    
## getFreeSize<sup>(9+)</sup>    
获取内置存储的可用空间大小（单位为Byte）。  
 **调用形式：**     
    
- getFreeSize(callback: AsyncCallback\<number>): void    
起始版本： 9    
- getFreeSize(): Promise\<number>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.SpatialStatistics  
 **需要权限：** ohos.permission.STORAGE_MANAGER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取内置存储的可用空间大小之后的回调 |  
| Promise<number> | Promise对象，返回内置存储的可用空间大小（单位为Byte） |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
| 13600001 | IPC error. |  
| 13900042 | Unknown error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
storageStatistics.getFreeSize((error: BusinessError, number: number) => {  
  if (error) {  
    console.info("getFreeSize failed with error:" + JSON.stringify(error));  
  } else {  
    // do something  
    console.info("getFreeSize successfully:" + number);  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
storageStatistics.getFreeSize().then((number: number) => {  
  console.info("getFreeSize successfully:" + JSON.stringify(number));  
}).catch((err: BusinessError) => {  
  console.info("getFreeSize failed with error:" + JSON.stringify(err));  
});  
    
```    
  
    
## getFreeSizeSync<sup>(10+)</sup>    
同步获取内置存储的可用空间大小（单位为Byte）。  
 **调用形式：**     
- getFreeSizeSync(): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.SpatialStatistics  
 **需要权限：** ohos.permission.STORAGE_MANAGER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
| 13600001 | IPC error. |  
| 13900042 | Unknown error. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
try {  
  let number = storageStatistics.getFreeSizeSync();  
  console.info("getFreeSizeSync successfully:" + JSON.stringify(number));  
} catch (err) {  
  let error: BusinessError = err as BusinessError;  
  console.info("getFreeSizeSync failed with error:" + JSON.stringify(error));  
}  
    
```    
  
