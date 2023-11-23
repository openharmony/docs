# @ohos.multimedia.mediaLibrary    
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import mediaLibrary from '@ohos.multimedia.mediaLibrary'    
```  
    
## MediaLibrary<sup>(deprecated)</sup>    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
### deleteAsset<sup>(deprecated)</sup>    
删除媒体文件资源。  
 **调用形式：**     
- deleteAsset(uri: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | true | 需要删除的媒体文件资源的uri。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | callback返回空。 |  
    
### deleteAsset<sup>(deprecated)</sup>    
删除媒体文件资源。  
 **调用形式：**     
- deleteAsset(uri: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | true | 需要删除的媒体文件资源的uri。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象，返回删除的结果。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let fileType = mediaLibrary.MediaType.FILE;  
  let option: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [fileType.toString()],  
  };  
  const fetchFileResult = await media.getFileAssets(option);  
  let asset = await fetchFileResult.getFirstObject();  
  if (asset == undefined) {  
    console.error('asset not exist');  
    return;  
  }  
  media.deleteAsset(asset.uri).then(() => {  
    console.info('deleteAsset successfully');  
  }).catch((error: BusinessError) => {  
    console.error('deleteAsset failed with error: ' + error);  
  });  
  fetchFileResult.close();  
}  
    
```    
  
    
### getActivePeers<sup>(deprecated)</sup>    
获取在线对端设备的信息，使用Promise方式返回异步结果。  
 **调用形式：**     
- getActivePeers(callback: AsyncCallback\<Array\<PeerInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.DistributedCore  
 **需要权限：** ohos.permission.READ_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<PeerInfo>> | true | callback返回获取的所有在线对端设备的PeerInfo对象。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  media.getActivePeers((error, devicesInfo) => {  
    if (devicesInfo != undefined) {  
      console.info('get distributed info ' + JSON.stringify(devicesInfo));  
    } else {  
      console.error('get distributed failed with error: ' + error);  
    }  
  });  
}  
    
```    
  
    
### getActivePeers<sup>(deprecated)</sup>    
获取在线对端设备的信息，使用Promise方式返回异步结果。  
 **调用形式：**     
- getActivePeers(): Promise\<Array\<PeerInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.DistributedCore  
 **需要权限：** ohos.permission.READ_MEDIA    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<PeerInfo>> | Promise对象，返回获取的所有在线对端设备的PeerInfo。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  media.getActivePeers().then((devicesInfo) => {  
    if (devicesInfo != undefined) {  
      console.info('get distributed info ' + JSON.stringify(devicesInfo));  
    } else {  
      console.info('get distributed info is undefined!');  
    }  
  }).catch((error: BusinessError) => {  
    console.error('get distributed info failed with error: ' + error);  
  });  
}  
    
```    
  
    
### getAllPeers<sup>(deprecated)</sup>    
获取所有对端设备的信息，使用Promise方式返回异步结果。  
 **调用形式：**     
- getAllPeers(callback: AsyncCallback\<Array\<PeerInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.DistributedCore  
 **需要权限：** ohos.permission.READ_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<PeerInfo>> | true | callback返回获取的所有对端设备的PeerInfo对象。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  media.getAllPeers((error, devicesInfo) => {  
    if (devicesInfo != undefined) {  
      console.info('get distributed info ' + JSON.stringify(devicesInfo));  
    } else {  
      console.error('get distributed failed with error: ' + error);  
    }  
  });  
}  
    
```    
  
    
### getAllPeers<sup>(deprecated)</sup>    
获取所有对端设备的信息，使用Promise方式返回异步结果。  
 **调用形式：**     
- getAllPeers(): Promise\<Array\<PeerInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.DistributedCore  
 **需要权限：** ohos.permission.READ_MEDIA    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<PeerInfo>> | Promise对象，返回获取的所有对端设备的PeerInfo。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  media.getAllPeers().then((devicesInfo) => {  
    if (devicesInfo != undefined) {  
      console.info('get distributed info ' + JSON.stringify(devicesInfo));  
    } else {  
      console.info('get distributed info is undefined!');  
    }  
  }).catch((error: BusinessError) => {  
    console.error('get distributed info failed with error: ' + error);  
  });  
}  
    
```    
  
    
## PeerInfo<sup>(deprecated)</sup>    
注册设备的信息。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.DistributedCore    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.DistributedCore    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceName<sup>(deprecated)</sup> | string | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>注册设备的名称。 |  
| networkId<sup>(deprecated)</sup> | string | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>注册设备的网络ID。 |  
| deviceType<sup>(deprecated)</sup> | DeviceType | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>设备类型。 |  
| isOnline<sup>(deprecated)</sup> | boolean | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>是否在线。 |  
    
## DeviceType<sup>(deprecated)</sup>    
枚举，设备类型。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。    
    
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.DistributedCore    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_UNKNOWN<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>未识别设备。 |  
| TYPE_LAPTOP<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>笔记本电脑。 |  
| TYPE_PHONE<sup>(deprecated)</sup> | 2 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>手机。 |  
| TYPE_TABLET<sup>(deprecated)</sup> | 3 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>平板电脑。 |  
| TYPE_WATCH<sup>(deprecated)</sup> | 4 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>智能手表。 |  
| TYPE_CAR<sup>(deprecated)</sup> | 5 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>车载设备。 |  
| TYPE_TV<sup>(deprecated)</sup> | 6 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>电视设备。 |  
