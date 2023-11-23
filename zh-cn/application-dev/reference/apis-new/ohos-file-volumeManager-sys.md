# @ohos.file.volumeManager    
该模块提供卷设备、磁盘设备查询和管理的相关功能：包括查询卷设备信息，对卷设备的挂载卸载、对磁盘设备分区以及卷设备的格式化等功能。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import volumeManager from '@ohos.file.volumeManager'    
```  
    
## Volume  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Volume    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.StorageService.Volume    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id | string | false | true | 卷设备ID的格式为vol-{主设备号}-{次设备号}，主设备号用来区分不同种类的设备，次设备号用来区分同一类型的多个设备，卷设备ID会随着插卡顺序不同而变化。 |  
| uuid | string | false | true | 卷设备uuid是卷设备的通用唯一识别码，不会随着插卡顺序变化而变化，但是卷设备的格式化会改变卷设备的uuid。 |  
| diskId | string | false | true | 卷设备所属的磁盘ID，一个磁盘可以有一个或者多个卷设备。磁盘设备ID的格式为disk-{主设备号}-{次设备号}，与卷设备ID相似。 |  
| description | string | false | true | 卷设备描述。 |  
| removable | boolean | false | true | 表示卷设备是否可移除，当前仅支持可移除存储设备。 |  
| state | number | false | true | 卷设备状态标识：<br>0：卸载状态 UNMOUNTED<br> 1：检查状态 CHECKING<br> 2：挂载状态 MOUNTED<br> 3：正在弹出状态 EJECTING |  
| path | string | false | true | 卷设备的挂载地址，一般为/mnt/data/external/{uuid}。 |  
    
## getAllVolumes    
异步获取当前外置存储中所有卷设备信息，以promise方式返回。  
 **调用形式：**     
    
- getAllVolumes(callback: AsyncCallback\<Array\<Volume>>): void    
起始版本： 9    
- getAllVolumes(): Promise\<Array\<Volume>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Volume  
 **需要权限：** ohos.permission.STORAGE_MANAGER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取当前所有可获得的卷设备信息之后的回调 |  
| Promise<Array<Volume>> | Promise对象，返回当前所有可获得的卷设备信息 |  
    
    
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
volumemanager.getAllVolumes((error: BusinessError, volumes: Array<volumemanager.Volume>) => {  
  // do something  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
volumemanager.getAllVolumes().then((volumes: Array<volumemanager.Volume>) => {  
  // do something with volumes, which is an array  
}).catch((error: BusinessError) => {  
  console.info("getAllVolumes failed");  
});  
    
```    
  
    
## mount    
异步挂载指定卷设备，以promise方式返回。当前仅支持vfat、exfat以及ntfs三种文件系统的卷设备挂载。  
 **调用形式：**     
    
- mount(volumeId: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- mount(volumeId: string): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Volume  
 **需要权限：** ohos.permission.MOUNT_UNMOUNT_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| volumeId | string | true | 卷设备id |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 挂载指定卷设备之后的回调 |  
| Promise<void> | 无返回结果的Promise对象 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
| 13600001 | IPC error. |  
| 13600002 | Not supported filesystem. |  
| 13600003 | Failed to mount. |  
| 13600005 | Incorrect volume state. |  
| 13600008 | No such object. |  
| 13900042 | Unknown error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let volumeId: string = "";  
volumemanager.mount(volumeId, (error: BusinessError) => {  
  // do something  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let volumeId: string = "";  
volumemanager.mount(volumeId).then(() => {  
  // do something  
}).catch((error: BusinessError) => {  
  console.info("mount failed");  
});  
    
```    
  
    
## unmount    
异步卸载指定卷设备。  
 **调用形式：**     
    
- unmount(volumeId: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- unmount(volumeId: string): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Volume  
 **需要权限：** ohos.permission.MOUNT_UNMOUNT_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| volumeId | string | true | 卷设备id |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 卸载指定卷设备之后的回调 |  
| Promise<void> | 无返回结果的Promise对象 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
| 13600001 | IPC error. |  
| 13600002 | Not supported filesystem. |  
| 13600004 |  |  
| 13600005 | Incorrect volume state. |  
| 13600008 | No such object. |  
| 13900042 | Unknown error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let volumeId: string = "";  
volumemanager.unmount(volumeId, (error: BusinessError) => {  
  // do something  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let volumeId: string = "";  
volumemanager.unmount(volumeId).then(() => {  
  // do something  
}).catch((error: BusinessError) => {  
  console.info("mount failed");  
});  
    
```    
  
    
## getVolumeByUuid    
异步通过卷设备uuid获得指定卷设备信息。  
 **调用形式：**     
    
- getVolumeByUuid(uuid: string, callback: AsyncCallback\<Volume>): void    
起始版本： 9    
- getVolumeByUuid(uuid: string): Promise\<Volume>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Volume  
 **需要权限：** ohos.permission.STORAGE_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uuid | string | true | 卷设备uuid |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取卷设备信息之后的回调 |  
| Promise<Volume> | Promise对象，返回当前所有可获得的卷设备信息 |  
    
    
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
let uuid: string = "";  
volumemanager.getVolumeByUuid(uuid, (error: BusinessError, volume: volumemanager.Volume) => {  
  // do something      
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let uuid: string = "";  
volumemanager.getVolumeByUuid(uuid).then((volume: volumemanager.Volume) => {  
  console.info("getVolumeByUuid successfully:" + JSON.stringify(volume));  
}).catch((error: BusinessError) => {  
  console.info("getVolumeByUuid failed with error:" + JSON.stringify(error));  
});  
    
```    
  
    
## getVolumeById    
异步通过卷设备id获得指定卷设备信息。  
 **调用形式：**     
    
- getVolumeById(volumeId: string, callback: AsyncCallback\<Volume>): void    
起始版本： 9    
- getVolumeById(volumeId: string): Promise\<Volume>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Volume  
 **需要权限：** ohos.permission.STORAGE_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| volumeId | string | true | 卷设备id |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取卷设备信息之后的回调 |  
| Promise<Volume> | Promise对象，返回当前所有可获得的卷设备信息 |  
    
    
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
let volumeId: string = "";  
volumemanager.getVolumeById(volumeId, (error: BusinessError, volume: volumemanager.Volume) => {  
  // do something      
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let volumeId: string = "";  
volumemanager.getVolumeById(volumeId).then((volume: volumemanager.Volume) => {  
  console.info("getVolumeById successfully:" + JSON.stringify(volume));  
}).catch((error: BusinessError) => {  
  console.info("getVolumeById failed with error:" + JSON.stringify(error));  
});  
    
```    
  
    
## setVolumeDescription    
异步修改指定卷设备描述。  
 **调用形式：**     
    
- setVolumeDescription(uuid: string, description: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setVolumeDescription(uuid: string, description: string): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Volume  
 **需要权限：** ohos.permission.MOUNT_UNMOUNT_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uuid | string | true | 卷设备uuid |  
| description | string | true | 卷设备描述 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 设置卷描述之后的回调 | |  
| Promise<void> | 无返回结果的Promise对象 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
| 13600001 | IPC error. |  
| 13600002 | Not supported filesystem. |  
| 13600005 | Incorrect volume state. |  
| 13600008 | No such object. |  
| 13900042 | Unknown error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let uuid: string = "";  
let description: string = "";  
volumemanager.setVolumeDescription(uuid, description, (error: BusinessError) => {  
  // do something      
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let uuid: string = "";  
let description: string = "";  
volumemanager.setVolumeDescription(uuid, description).then(() => {  
  console.info("setVolumeDescription successfully");  
}).catch((error: BusinessError) => {  
  console.info("setVolumeDescription failed with error:" + JSON.stringify(error));  
});  
    
```    
  
    
## format    
异步对指定卷设备进行格式化。当前仅支持vfat和exfat两种文件系统类型的格式化，只有处于卸载状态的卷设备可以进行格式化，格式化后卷设备的uuid、挂载路径和卷设备描述均会发生变化。  
 **调用形式：**     
    
- format(volumeId: string, fsType: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- format(volumeId: string, fsType: string): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Volume  
 **需要权限：** ohos.permission.MOUNT_FORMAT_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| volumeId | string | true | 卷设备id |  
| fsType | string | true | 文件系统类型（vfat或者exfat） |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 挂载指定卷设备之后的回调 |  
| Promise<void> | 无返回结果的Promise对象 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission verification failed. |  
| 202 | The caller is not a system application. |  
| 401 | The input parameter is invalid. |  
| 13600001 | IPC error. |  
| 13600002 | Not supported filesystem. |  
| 13600005 | Incorrect volume state. |  
| 13600008 | No such object. |  
| 13900042 | Unknown error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
let volumeId: string = "";  
let fsType: string = "";  
volumemanager.format(volumeId, fsType, (error: BusinessError) => {  
  // do something      
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let volumeId: string = "";  
let fsType: string = "";  
volumemanager.format(volumeId, fsType).then(() => {  
  console.info("format successfully");  
}).catch((error: BusinessError) => {  
  console.info("format failed with error:" + JSON.stringify(error));  
});  
    
```    
  
    
## partition    
异步对磁盘设备进行分区，以promise方式返回。当前仅支持将磁盘设备重新分区为一个分区，系统是支持读取多分区的磁盘设备。  
 **调用形式：**     
    
- partition(diskId: string, type: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- partition(diskId: string, type: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Volume  
 **需要权限：** ohos.permission.MOUNT_FORMAT_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| diskId | string | true | 卷设备所属的磁盘设备id |  
| type | number | true | 分区类型 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 对磁盘设备进行分区 |  
| Promise<void> | 无返回结果的Promise对象 |  
    
    
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
let diskId: string = "";  
let type: number = 0;  
volumemanager.partition(diskId, type, (error: BusinessError) => {  
  // do something      
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
let diskId: string = "";  
let type: number = 0;  
volumemanager.partition(diskId, type).then(() => {  
  console.info("partition successfully");  
}).catch((error: BusinessError) => {  
  console.info("partition failed with error:" + JSON.stringify(error));  
});  
    
```    
  
