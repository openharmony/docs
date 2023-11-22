# @ohos.filemanagement.userFileManager    
该模块提供用户数据管理能力，包括访问、修改用户等用户公共媒体数据信息等常用功能。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import userFileManager from '@ohos.filemanagement.userFileManager'    
```  
    
## getUserFileMgr    
获取用户数据管理模块的实例，用于访问和修改用户等用户公共媒体数据信息（如音频、视频、图片、文档等）。  
 **调用形式：**     
- getUserFileMgr(context: Context): UserFileManager  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 传入Ability实例的Context。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| UserFileManager | 媒体库实例。 |  
    
 **示例代码：**   
```ts    
//此处获取的userFileManager实例mgr为全局对象，后续使用到mgr的地方默认为使用此处获取的对象，如未添加此段代码报mgr未定义的错误请自行添加  
const context = getContext(this);  
let mgr = userFileManager.getUserFileMgr(context);    
```    
  
    
## FileType    
枚举，媒体文件类型。    
    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| IMAGE | 1 | 图片。 |  
| VIDEO | 2 | 视频。 |  
| AUDIO | 3 | 音频。 |  
    
## PhotoSubType<sup>(10+)</sup>    
枚举，不同[FileAsset](#fileasset)的类型。    
    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEFAULT | 0 | 默认照片类型。 |  
| SCREENSHOT | 1 | 截屏录屏文件类型。 |  
| CAMERA | 2 | 相机拍摄的照片和视频类型。 |  
    
## PositionType<sup>(10+)</sup>    
枚举，文件位置，表示文件在本地或云端。    
    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| LOCAL | 1 | 文件只存在于本端设备。 |  
| CLOUD | 2 | 文件只存在于云端。 |  
| BOTH | 3 | 文件在本地和云中都存在。 |  
    
## MemberType    
成员类型。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| number | number类型。 |  
| string | string类型。 |  
| boolean | boolean类型。 |  
    
## ChangeEvent    
变更监听的媒体文件类型。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| deviceChange | 设备。 |  
| albumChange | 相册。 |  
| imageChange | 图片。 |  
| audioChange | 音频。 |  
| videoChange | 视频。 |  
| remoteFileChange | 远程文件。 |  
    
## FileAsset    
提供封装文件属性的方法。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri | string | true | true | 媒体文件资源uri（如：file://media/Photo/1/IMG_datetime_0001/displayName.jpg），详情参见用户文件uri介绍中的[媒体文件uri](../../file-management/user-file-uri-intro.md#媒体文件uri)。 |  
| fileType | FileType | true | true | 媒体文件类型 |  
| displayName | string | false | true | 显示文件名，包含后缀名。 |  
    
### get    
获取FileAsset成员参数。  
 **调用形式：**     
- get(member: string): MemberType  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| member | string | true | 成员参数名称例如：ImageVideoKey.DISPLAY_NAME。在get时，除了uri、photoType和displayName三个属性之外，其他的属性都需要在fetchColumns中填入需要get的PhotoKeys，例如：get title属性fetchColumns: ['title']。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| MemberType |  |  
    
 **示例代码：**   
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('fileAssetGetDemo');  
  try {  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: userFileManager.FetchOptions = {  
      fetchColumns: ['title'],  
      predicates: predicates  
    };  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    let title: userFileManager.ImageVideoKey = userFileManager.ImageVideoKey.TITLE;  
    let fileAssetTitle: userFileManager.MemberType = fileAsset.get(title.toString());  
    console.info('fileAsset Get fileAssetTitle = ', fileAssetTitle);  
  } catch (err) {  
    console.error('release failed. message = ', err);  
  }  
}  
    
```    
  
    
### set    
设置FileAsset成员参数。  
 **调用形式：**     
- set(member: string, value: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| member | string | true | 成员参数名称例如：ImageVideoKey.DISPLAY_NAME。 |  
| value | string | true | 设置成员参数名称，只能修改DISPLAY_NAME和TITLE的值。 |  
    
 **示例代码：**   
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('fileAssetSetDemo');  
  try {  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: userFileManager.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    let displayName: string = userFileManager.ImageVideoKey.DISPLAY_NAME.toString();  
    fileAsset.set(displayName, 'newDisplayName1');  
  } catch (err) {  
    console.error('release failed. message = ', err);  
  }  
}  
    
```    
  
    
### commitModify    
修改文件的元数据。  
 **调用形式：**     
    
- commitModify(callback: AsyncCallback\<void>): void    
起始版本： 9    
- commitModify(): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.WRITE_AUDIO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('commitModifyDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
  let displayName: string = userFileManager.ImageVideoKey.DISPLAY_NAME.toString();  
  let fileAssetDisplayName: userFileManager.MemberType = fileAsset.get(displayName);  
  console.info('fileAsset get fileAssetDisplayName = ', fileAssetDisplayName);  
  let newFileAssetDisplayName = 'new' + fileAssetDisplayName;  
  console.info('fileAsset newFileAssetDisplayName = ', newFileAssetDisplayName);  
  fileAsset.set(displayName, newFileAssetDisplayName);  
  fileAsset.commitModify((err) => {  
    if (err == undefined) {  
      let commitModifyDisplayName = fileAsset.get(displayName);  
      console.info('fileAsset commitModify successfully, commitModifyDisplayName = ', commitModifyDisplayName);  
    } else {  
      console.error('commitModify failed, message =', err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('commitModifyDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
  let displayName = userFileManager.ImageVideoKey.DISPLAY_NAME.toString();  
  let fileAssetDisplayName: userFileManager.MemberType = fileAsset.get(displayName);  
  console.info('fileAsset get fileAssetDisplayName = ', fileAssetDisplayName);  
  let newFileAssetDisplayName = 'new' + fileAssetDisplayName;  
  console.info('fileAsset newFileAssetDisplayName = ', newFileAssetDisplayName);  
  fileAsset.set(displayName, newFileAssetDisplayName);  
  try {  
    await fileAsset.commitModify();  
    let commitModifyDisplayName = fileAsset.get(displayName);  
    console.info('fileAsset commitModify successfully, commitModifyDisplayName = ', commitModifyDisplayName);  
  } catch (err) {  
    console.error('commitModify failed. message = ', err);  
  }  
}  
    
```    
  
    
### open    
打开当前文件。  
 **调用形式：**     
    
- open(mode: string, callback: AsyncCallback\<number>): void    
起始版本： 9    
- open(mode: string): Promise\<number>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO or ohos.permission.READ_AUDIO or ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.WRITE_AUDIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode | string | true | 打开文件方式，如：'r'（只读）, 'w'（只写）, 'rw'（读写）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回文件描述符。 |  
| Promise<number> | Promise对象，返回文件描述符。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
async function example() {  
  console.info('openDemo');  
   let testFileName: string = 'testFile' + Date.now() + '.jpg';  
  const fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName);  
  fileAsset.open('rw', (err, fd) => {  
    if (fd != undefined) {  
      console.info('File fd' + fd);  
      fileAsset.close(fd);  
    } else {  
      console.error('File err' + err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
async function example() {  
  console.info('openDemo');  
  try {  
    let testFileName: string = 'testFile' + Date.now() + '.jpg';  
    const fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName);  
    let fd: number = await fileAsset.open('rw');  
    if (fd != undefined) {  
      console.info('File fd' + fd);  
      fileAsset.close(fd);  
    } else {  
      console.error(' open File fail');  
    }  
  } catch (err) {  
    console.error('open Demo err' + err);  
  }  
}  
    
```    
  
    
### close    
关闭当前文件。  
 **调用形式：**     
    
- close(fd: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- close(fd: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd | number | true | 文件描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('closeDemo');  
  try {  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: userFileManager.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
    const fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    let fd: number = await fileAsset.open('rw');  
    console.info('file fd', fd);  
    fileAsset.close(fd, (err) => {  
      if (err == undefined) {  
        console.info('asset close succeed.');  
      } else {  
        console.error('close failed, message = ' + err);  
      }  
    });  
  } catch (err) {  
    console.error('close failed, message = ' + err);  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('closeDemo');  
  try {  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: userFileManager.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
    const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    let fd: number = await asset.open('rw');  
    console.info('file fd', fd);  
    await asset.close(fd);  
    console.info('asset close succeed.');  
  } catch (err) {  
    console.error('close failed, message = ' + err);  
  }  
}  
    
```    
  
    
### getThumbnail    
获取文件的缩略图，传入缩略图尺寸。  
 **调用形式：**     
    
- getThumbnail(callback: AsyncCallback\<image.PixelMap>): void    
起始版本： 9    
- getThumbnail(size: image.Size, callback: AsyncCallback\<image.PixelMap>): void    
起始版本： 9    
- getThumbnail(size?: image.Size): Promise\<image.PixelMap>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO or ohos.permission.READ_AUDIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size | image.Size | true | 缩略图尺寸。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回缩略图的PixelMap。 |  
| Promise<image.PixelMap> | Promise对象，返回缩略图的PixelMap。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import image from '@ohos.multimedia.image';  
  
async function example() {  
  console.info('getThumbnailDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let size: image.Size = { width: 720, height: 720 };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
  console.info('asset displayName = ', asset.displayName);  
  asset.getThumbnail(size, (err, pixelMap) => {  
    if (err == undefined) {  
      console.info('getThumbnail successful ' + pixelMap);  
    } else {  
      console.error('getThumbnail fail', err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import image from '@ohos.multimedia.image';  
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  console.info('getThumbnailDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let size: image.Size = { width: 720, height: 720 };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
  console.info('asset displayName = ', asset.displayName);  
  asset.getThumbnail(size).then((pixelMap) => {  
    console.info('getThumbnail successful ' + pixelMap);  
  }).catch((err: BusinessError) => {  
    console.error('getThumbnail fail' + err);  
  });  
}  
    
```    
  
    
### favorite    
将文件设置为收藏文件。  
 **调用形式：**     
    
- favorite(isFavorite: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9    
- favorite(isFavorite: boolean): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.WRITE_AUDIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isFavorite | boolean | true | 是否设置为收藏文件， true：设置为收藏文件，false：取消收藏。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('favoriteDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
  asset.favorite(true, (err) => {  
    if (err == undefined) {  
      console.info('favorite successfully');  
    } else {  
      console.error('favorite failed with error:' + err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  console.info('favoriteDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
  asset.favorite(true).then(() => {  
    console.info('favorite successfully');  
  }).catch((err: BusinessError) => {  
    console.error('favorite failed with error:' + err);  
  });  
}  
    
```    
  
    
### setHidden<sup>(10+)</sup>    
将文件设置为隐私文件。  
 **调用形式：**     
    
- setHidden(hiddenState: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setHidden(hiddenState: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| hiddenState | boolean | true | 是否设置为隐藏文件，true:将文件资产放入隐藏相册;false:从隐藏相册中恢复。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Called by non-system application. |  
| 13900020 | if parameter is invalid. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
<i></i><span style="font-size: 14px; letter-spacing: 0px;"></span>import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('setHiddenDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
  asset.setHidden(true, (err) => {  
    if (err == undefined) {  
      console.info('setHidden successfully');  
    } else {  
      console.error('setHidden failed with error:' + err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  // 示例代码为将文件从隐藏相册中恢复，需要先在隐藏相册预置资源  
  console.info('setHiddenDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let albumList: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.HIDDEN);  
  const album: userFileManager.Album = await albumList.getFirstObject();  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);  
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
  asset.setHidden(false).then(() => {  
    console.info('setHidden successfully');  
  }).catch((err: BusinessError) => {  
    console.error('setHidden failed with error:' + err);  
  });  
}  
    
```    
  
    
### setUserComment<sup>(10+)</sup>    
修改图片或者视频的备注信息。  
 **调用形式：**     
    
- setUserComment(userComment: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setUserComment(userComment: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| userComment | string | true | 待修改的图片或视频的备注信息，备注信息最长为140字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Called by non-system application. |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  try {  
    console.info('setUserCommentDemo')  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOptions: userFileManager.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);  
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    let userComment: string = 'test_set_user_comment';  
    fileAsset.setUserComment(userComment, (err) => {  
      if (err === undefined) {  
        console.info('setUserComment successfully');  
      } else {  
        console.error('setUserComment failed with error: ' + err);  
      }  
    });  
  } catch (err) {  
    console.error('setUserCommentDemoCallback failed with error: ' + err);  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  try {  
    console.info('setUserCommentDemo')  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOptions: userFileManager.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);  
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    let userComment: string = 'test_set_user_comment';  
    await fileAsset.setUserComment(userComment);  
  } catch (err) {  
    console.error('setUserCommentDemoCallback failed with error: ' + err);  
  }  
}  
    
```    
  
    
### getExif<sup>(10+)</sup>    
返回jpg格式图片Exif标签组成的json格式的字符串。  
 **调用形式：**     
    
- getExif(callback: AsyncCallback\<string>): void    
起始版本： 10    
- getExif(): Promise\<string>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回exif标签组成的json格式的字符串。 |  
| Promise<string> | 返回exif标签组成的json格式的字符串。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Called by non-system application. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  try {  
    console.info('getExifDemo');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    predicates.isNotNull('all_exif')  
    let fetchOptions: userFileManager.FetchOptions = {  
      fetchColumns: ['all_exif', userFileManager.ImageVideoKey.USER_COMMENT.toString()],  
      predicates: predicates  
    };  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);  
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    console.info('getExifDemo fileAsset displayName: ' + JSON.stringify(fileAsset.displayName));  
    let userCommentKey: string = 'UserComment';  
    fileAsset.getExif((err, exifMessage) => {  
      if (exifMessage != undefined) {  
        let userComment: string = JSON.stringify(JSON.parse(exifMessage), [userCommentKey]);  
        console.info('getExifDemo userComment: ' + JSON.stringify(userComment));  
      } else {  
        console.error('getExif failed, message = ', err);  
      }  
    });  
    fetchResult.close();  
  } catch (err) {  
    console.error('getExifDemoCallback failed with error: ' + err);  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  try {  
    console.info('getExifDemo');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    predicates.isNotNull('all_exif')  
    let fetchOptions: userFileManager.FetchOptions = {  
      fetchColumns: ['all_exif', userFileManager.ImageVideoKey.USER_COMMENT.toString()],  
      predicates: predicates  
    };  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);  
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    console.info('getExifDemo fileAsset displayName: ' + JSON.stringify(fileAsset.displayName));  
    let exifMessage: string = await fileAsset.getExif();  
    let userCommentKey: string = 'UserComment';  
    let userComment: string = JSON.stringify(JSON.parse(exifMessage), [userCommentKey]);  
    console.info('getExifDemo userComment: ' + JSON.stringify(userComment));  
    fetchResult.close();  
  } catch (err) {  
    console.error('getExifDemoCallback failed with error: ' + err);  
  }  
}  
    
```    
  
    
## AudioKey    
枚举，音频文件关键信息。    
    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| URI | 0 | 文件uri。 |  
| DISPLAY_NAME | 1 | 显示名字。 |  
| DATE_ADDED | 2 | 添加日期（添加文件时间距1970年1月1日的秒数值）。 |  
| DATE_MODIFIED | 3 | 修改日期（修改文件时间距1970年1月1日的秒数值，修改文件名不会改变此值，当文件内容发生修改时才会更新）。 |  
| TITLE | 4 | 文件标题。 |  
| ARTIST | 5 | 作者。 |  
| AUDIOALBUM | 6 | 专辑。 |  
| DURATION | 7 | 持续时间（单位：毫秒）。 |  
| FAVORITE | 8 | 收藏。 |  
    
## ImageVideoKey    
枚举，图片和视频文件关键信息。    
    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| URI | 0 | 文件uri。 |  
| FILE_TYPE | 1 | 媒体文件类型。 |  
| DISPLAY_NAME | 2 | 显示名字。 |  
| DATE_ADDED | 3 | 添加日期（添加文件时间距1970年1月1日的秒数值）。 |  
| DATE_MODIFIED | 4 | 修改日期（修改文件时间距1970年1月1日的秒数值，修改文件名不会改变此值，当文件内容发生修改时才会更新）。 |  
| TITLE | 5 | 文件标题。 |  
| DURATION | 6 | 持续时间（单位：毫秒）。 |  
| WIDTH | 7 | 图片宽度（单位：像素）。 |  
| HEIGHT | 8 | 图片高度（单位：像素）。 |  
| DATE_TAKEN | 9 | 拍摄日期（文件拍照时间距1970年1月1日的秒数值）。 |  
| ORIENTATION | 10 | 图片文件的方向。 |  
| FAVORITE | 11 | 收藏。 |  
| POSITION<sup>(10+)</sup> | 12 | 文件位置类型。 |  
| DATE_TRASHED<sup>(10+)</sup> | 13 | 删除日期（删除文件时间距1970年1月1日的秒数值）。 |  
| HIDDEN<sup>(10+)</sup> | 14 | 文件的隐藏状态。 |  
| USER_COMMENT<sup>(10+)</sup> | 15 | 用户注释信息。 |  
| CAMERA_SHOT_KEY<sup>(10+)</sup> | 16 | 锁屏相机拍照或录像的标记字段（仅开放给系统相机,其key值由系统相机定义）。 |  
    
## AlbumKey    
枚举，相册关键信息。    
    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| URI | 0 | 相册uri。 |  
| FILE_TYPE | 1 | 媒体文件类型。 |  
| ALBUM_NAME | 2 | 相册名字。 |  
| DATE_ADDED | 3 | 添加日期（添加文件时间距1970年1月1日的秒数值）。 |  
| DATE_MODIFIED | 4 | 修改日期（修改文件时间距1970年1月1日的秒数值，修改文件名不会改变此值，当文件内容发生修改时才会更新）。 |  
    
## FetchOptions    
检索条件。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| fetchColumns | Array<string> | false | true | 检索条件，指定列名查询，如果该参数为空时默认查询uri、name、fileType（具体字段名称以检索对象定义为准）且使用[get](#get)接口去获取当前对象的其他属性时将会报错。示例：<br />fetchColumns: ['uri', 'title']。 |  
| predicates | dataSharePredicates.DataSharePredicates | false | true | 谓词查询，显示过滤条件。 |  
    
## AlbumFetchOptions    
相册检索条件。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| predicates | dataSharePredicates.DataSharePredicates | false | true | 谓词查询，显示过滤条件。 |  
    
## PhotoCreateOptions<sup>(10+)</sup>    
图片或视频的创建选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| subType<sup>(10+)</sup> | PhotoSubType | false | false | 图片或者视频的子类型。 |  
| cameraShotKey<sup>(10+)</sup> | string | false | false | 锁屏相机拍照或录像的标记字段（仅开放给系统相机,其key值由系统相机定义）。 |  
    
## FetchResult    
文件检索结果集。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
### getCount    
获取文件检索结果中的文件总数。  
 **调用形式：**     
- getCount(): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 检索到的文件总数。 |  
    
 **示例代码：**   
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getCountDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  const fetchCount: number = fetchResult.getCount();  
  console.info('fetchCount = ', fetchCount);  
}    
```    
  
    
### isAfterLast    
检查结果集是否指向最后一行。  
 **调用形式：**     
- isAfterLast(): boolean  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 当读到最后一条记录后，后续没有记录返回true，否则返回false。 |  
    
 **示例代码：**   
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  const fetchCount: number = fetchResult.getCount();  
  console.info('count:' + fetchCount);  
  let fileAsset: userFileManager.FileAsset = await fetchResult.getLastObject();  
  if (fetchResult.isAfterLast()) {  
    console.info('fileAsset isAfterLast displayName = ', fileAsset.displayName);  
  } else {  
    console.info('fileAsset  not isAfterLast ');  
  }  
}  
    
```    
  
    
### close    
释放 FetchFileResult 实例并使其失效。无法调用其他方法。  
 **调用形式：**     
- close(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **示例代码：**   
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('fetchResultCloseDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  try {  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
    fetchResult.close();  
    console.info('close succeed.');  
  } catch (err) {  
    console.error('close fail. message = ' + err);  
  }  
}  
    
```    
  
    
### getFirstObject    
获取文件检索结果中的第一个文件资产。  
 **调用形式：**     
    
- getFirstObject(callback: AsyncCallback\<T>): void    
起始版本： 9    
- getFirstObject(): Promise\<T>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步获取结果集中的第一个完成后的回调。 |  
| Promise<T> | Promise对象，返回结果集中第一个对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getFirstObjectDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  fetchResult.getFirstObject((err, fileAsset) => {  
    if (fileAsset != undefined) {  
      console.info('fileAsset displayName: ', fileAsset.displayName);  
    } else {  
      console.error('fileAsset failed with err:' + err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getFirstObjectDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
  console.info('fileAsset displayName: ', fileAsset.displayName);  
}    
```    
  
    
### getNextObject    
获取文件检索结果中的下一个文件资产。在调用此方法之前，必须使用[isAfterLast()](#isafterlast)来检查当前位置是否为最后一行。  
 **调用形式：**     
    
- getNextObject(callback: AsyncCallback\<T>): void    
起始版本： 9    
- getNextObject(): Promise\<T>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步返回结果集中下一个之后的回调。 |  
| Promise<T> | Promise对象，返回结果集中下一个对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getNextObjectDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  await fetchResult.getFirstObject();  
  if (!fetchResult.isAfterLast()) {  
    fetchResult.getNextObject((err, fileAsset) => {  
      if (fileAsset != undefined) {  
        console.info('fileAsset displayName: ', fileAsset.displayName);  
      } else {  
        console.error('fileAsset failed with err: ' + err);  
      }  
    });  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getNextObjectDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  await fetchResult.getFirstObject();  
  if (!fetchResult.isAfterLast()) {  
    let fileAsset: userFileManager.FileAsset = await fetchResult.getNextObject();  
    console.info('fileAsset displayName: ', fileAsset.displayName);  
  }  
}    
```    
  
    
### getLastObject    
获取文件检索结果中的最后一个文件资产。  
 **调用形式：**     
    
- getLastObject(callback: AsyncCallback\<T>): void    
起始版本： 9    
- getLastObject(): Promise\<T>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步返回结果集中最后一个的回调。 |  
| Promise<T> | Promise对象，返回结果集中最后一个对象。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getLastObjectDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  fetchResult.getLastObject((err, fileAsset) => {  
    if (fileAsset != undefined) {  
      console.info('fileAsset displayName: ', fileAsset.displayName);  
    } else {  
      console.error('fileAsset failed with err: ' + err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getLastObjectDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  let fileAsset: userFileManager.FileAsset = await fetchResult.getLastObject();  
  console.info('fileAsset displayName: ', fileAsset.displayName);  
}    
```    
  
    
### getPositionObject    
获取文件检索结果中具有指定索引的文件资产。  
 **调用形式：**     
    
- getPositionObject(index: number, callback: AsyncCallback\<T>): void    
起始版本： 9    
- getPositionObject(index: number): Promise\<T>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | 要获取的文件的索引，从0开始。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步返回指定索引的文件资产的回调。 |  
| Promise<T> | Promise对象，返回结果集中指定索引的一个对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900020 | if parameter is invalid. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getPositionObjectDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  fetchResult.getPositionObject(0, (err, fileAsset) => {  
    if (fileAsset != undefined) {  
      console.info('fileAsset displayName: ', fileAsset.displayName);  
    } else {  
      console.error('fileAsset failed with err: ' + err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getPositionObjectDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  let fileAsset: userFileManager.FileAsset = await fetchResult.getPositionObject(0);  
  console.info('fileAsset displayName: ', fileAsset.displayName);  
}    
```    
  
    
### getAllObject<sup>(10+)</sup>    
获取文件检索结果中的所有文件资产。  
 **调用形式：**     
    
- getAllObject(callback: AsyncCallback\<Array\<T>>): void    
起始版本： 10    
- getAllObject(): Promise\<Array\<T>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步获取结果集中的所有文件资产完成后的回调。 |  
| Promise<Array<T>> | Promise对象，返回结果集中所有文件资产数组。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getAllObjectDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  fetchResult.getAllObject((err, fileAssetList) => {  
    if (fileAssetList != undefined) {  
      console.info('fileAssetList length: ', fileAssetList.length);  
    } else {  
      console.error('fileAssetList failed with err:' + err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getAllObjectDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
  let fileAssetList: Array<userFileManager.FileAsset> = await fetchResult.getAllObject();  
  console.info('fileAssetList length: ', fileAssetList.length);  
}    
```    
  
    
## AlbumType<sup>(10+)</sup>    
枚举，相册类型，表示是用户相册还是系统预置相册。    
    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| USER | 0 | 用户相册。 |  
| SYSTEM | 1024 | 系统预置相册。 |  
    
## AlbumSubType<sup>(10+)</sup>    
枚举，相册子类型，表示具体的相册类型。    
    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| USER_GENERIC | 1 | 用户相册。 |  
| FAVORITE | 1025 | 收藏夹。 |  
| VIDEO | 1026 | 视频相册。 |  
| HIDDEN | 1027 | 隐藏相册。 |  
| TRASH | 1028 | 回收站。 |  
| SCREENSHOT | 1029 | 截屏和录屏相册。 |  
| CAMERA | 1030 | 相机拍摄的照片和视频相册。 |  
| ANY | 2147483647 | 任意相册。 |  
    
## AbsAlbum  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| albumType<sup>(10+)</sup> | AlbumType | true | true |  |  
| albumSubType<sup>(10+)</sup> | AlbumSubType | true | true |  |  
| albumName | string | false | true |  |  
| albumUri | string | true | true |  |  
| dateModified | number | true | true |  |  
| count | number | true | true |  |  
| coverUri | string | false | true |  |  
    
### getPhotoAssets  
 **调用形式：**     
    
- getPhotoAssets(options: FetchOptions, callback: AsyncCallback\<FetchResult\<FileAsset>>): void    
起始版本： 9    
- getPhotoAssets(options: FetchOptions): Promise\<FetchResult\<FileAsset>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | FetchOptions | true | <br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<FetchResult<FileAsset>> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900020 |  |  
    
## Album    
实体相册  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
### commitModify    
更新相册属性修改到数据库中。  
 **调用形式：**     
    
- commitModify(callback: AsyncCallback\<void>): void    
起始版本： 9    
- commitModify(): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('albumCommitModifyDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let albumFetchOptions: userFileManager.AlbumFetchOptions = {  
    predicates: predicates  
  };  
  const albumList: userFileManager.FetchResult<userFileManager.Album> = await mgr.getPhotoAlbums(albumFetchOptions);  
  const album: userFileManager.Album = await albumList.getFirstObject();  
  album.albumName = 'hello';  
  album.commitModify((err) => {  
    if (err != undefined) {  
      console.error('commitModify failed with error: ' + err);  
    } else {  
      console.info('commitModify successfully');  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  console.info('albumCommitModifyDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let albumFetchOptions: userFileManager.AlbumFetchOptions = {  
    predicates: predicates  
  };  
  try {  
    let albumList: userFileManager.FetchResult<userFileManager.Album> = await mgr.getPhotoAlbums(albumFetchOptions);  
    let album: userFileManager.Album = await albumList.getFirstObject();  
    album.albumName = 'hello';  
    album.commitModify().then(() => {  
      console.info('commitModify successfully');  
    }).catch((err: BusinessError) => {  
      console.error('commitModify failed with error: ' + err);  
    });  
  } catch (err) {  
    console.error('getPhotoAlbums failed. message = ', err);  
  }  
}  
    
```    
  
    
### addPhotoAssets<sup>(10+)</sup>    
往相册中添加图片或者视频，需要先预置相册和文件资源。  
 **调用形式：**     
    
- addPhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- addPhotoAssets(assets: Array\<FileAsset>): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| assets | Array<FileAsset> | true | 待添加到相册中的图片或视频数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900020 | if parameter is invalid. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  try {  
    console.info('addPhotoAssetsDemoCallback');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: userFileManager.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);  
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    album.addPhotoAssets([asset], (err) => {  
      if (err === undefined) {  
        console.info('album addPhotoAssets successfully');  
      } else {  
        console.error('album addPhotoAssets failed with error: ' + err);  
      }  
    });  
  } catch (err) {  
    console.error('addPhotoAssetsDemoCallback failed with error: ' + err);  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  try {  
    console.info('addPhotoAssetsDemoPromise');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: userFileManager.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);  
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);  
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    album.addPhotoAssets([asset]).then(() => {  
      console.info('album addPhotoAssets successfully');  
    }).catch((err: BusinessError) => {  
      console.error('album addPhotoAssets failed with error: ' + err);  
    });  
  } catch (err) {  
    console.error('addPhotoAssetsDemoPromise failed with error: ' + err);  
  }  
}  
    
```    
  
    
### removePhotoAssets<sup>(10+)</sup>    
从相册中移除图片或者视频，需要先预置相册和文件资源。  
 **调用形式：**     
    
- removePhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- removePhotoAssets(assets: Array\<FileAsset>): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| assets | Array<FileAsset> | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900020 | if parameter is invalid. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  try {  
    console.info('removePhotoAssetsDemoCallback');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: userFileManager.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);  
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);  
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    album.removePhotoAssets([asset], (err) => {  
      if (err === undefined) {  
        console.info('album removePhotoAssets successfully');  
      } else {  
        console.error('album removePhotoAssets failed with error: ' + err);  
      }  
    });  
  } catch (err) {  
    console.error('removePhotoAssetsDemoCallback failed with error: ' + err);  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  try {  
    console.info('removePhotoAssetsDemoPromise');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: userFileManager.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);  
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);  
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    album.removePhotoAssets([asset]).then(() => {  
      console.info('album removePhotoAssets successfully');  
    }).catch((err: BusinessError) => {  
      console.error('album removePhotoAssets failed with error: ' + err);  
    });  
  } catch (err) {  
    console.error('removePhotoAssetsDemoPromise failed with error: ' + err);  
  }  
}  
    
```    
  
    
### recoverPhotoAssets<sup>(10+)</sup>    
从回收站中恢复图片或者视频，需要先在回收站中预置文件资源。  
 **调用形式：**     
    
- recoverPhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- recoverPhotoAssets(assets: Array\<FileAsset>): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| assets | Array<FileAsset> | true | 回收站中待恢复图片或者视频数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900020 | if parameter is invalid. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  try {  
    console.info('recoverPhotoAssetsDemoCallback');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: userFileManager.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);  
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);  
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    album.recoverPhotoAssets([asset], (err) => {  
      if (err === undefined) {  
        console.info('album recoverPhotoAssets successfully');  
      } else {  
        console.error('album recoverPhotoAssets failed with error: ' + err);  
      }  
    });  
  } catch (err) {  
    console.error('recoverPhotoAssetsDemoCallback failed with error: ' + err);  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  try {  
    console.info('recoverPhotoAssetsDemoPromise');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: userFileManager.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);  
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);  
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    album.recoverPhotoAssets([asset]).then(() => {  
      console.info('album recoverPhotoAssets successfully');  
    }).catch((err: BusinessError) => {  
      console.error('album recoverPhotoAssets failed with error: ' + err);  
    });  
  } catch (err) {  
    console.error('recoverPhotoAssetsDemoPromise failed with error: ' + err);  
  }  
}  
    
```    
  
    
### deletePhotoAssets<sup>(10+)</sup>    
从回收站中彻底删除图片或者视频，需要先在回收站中预置文件资源。  
 **调用形式：**     
    
- deletePhotoAssets(assets: Array\<FileAsset>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- deletePhotoAssets(assets: Array\<FileAsset>): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| assets | Array<FileAsset> | true | 回收站中待彻底删除图片或者视频数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900020 | if parameter is invalid. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  try {  
    console.info('deletePhotoAssetsDemoCallback');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: userFileManager.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);  
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);  
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    album.deletePhotoAssets([asset], (err) => {  
      if (err === undefined) {  
        console.info('album deletePhotoAssets successfully');  
      } else {  
        console.error('album deletePhotoAssets failed with error: ' + err);  
      }  
    });  
  } catch (err) {  
    console.error('deletePhotoAssetsDemoCallback failed with error: ' + err);  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  try {  
    console.info('deletePhotoAssetsDemoPromise');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: userFileManager.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);  
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);  
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    album.deletePhotoAssets([asset]).then(() => {  
      console.info('album deletePhotoAssets successfully');  
    }).catch((err: BusinessError) => {  
      console.error('album deletePhotoAssets failed with error: ' + err);  
    });  
  } catch (err) {  
    console.error('deletePhotoAssetsDemoPromise failed with error: ' + err);  
  }  
}  
    
```    
  
    
## UserFileManager  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
### getPhotoAssets    
获取图片和视频资源。  
 **调用形式：**     
    
- getPhotoAssets(options: FetchOptions, callback: AsyncCallback\<FetchResult\<FileAsset>>): void    
起始版本： 9    
- getPhotoAssets(options: FetchOptions): Promise\<FetchResult\<FileAsset>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | FetchOptions | true | 图片和视频检索选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回图片和视频检索结果集。 |  
| Promise<FetchResult<FileAsset>> | Promise对象，返回图片和视频数据结果集。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900020 | if parameter is invalid. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getPhotoAssets');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOptions: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  
  mgr.getPhotoAssets(fetchOptions, async (err, fetchResult) => {  
    if (fetchResult != undefined) {  
      console.info('fetchResult success');  
      let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
      if (fileAsset != undefined) {  
        console.info('fileAsset.displayName : ' + fileAsset.displayName);  
      }  
    } else {  
      console.error('fetchResult fail' + err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getPhotoAssets');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOptions: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  try {  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);  
    if (fetchResult != undefined) {  
      console.info('fetchResult success');  
      let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
      if (fileAsset != undefined) {  
        console.info('fileAsset.displayName :' + fileAsset.displayName);  
      }  
    }  
  } catch (err) {  
    console.error('getPhotoAssets failed, message = ', err);  
  }  
}  
    
```    
  
    
### createPhotoAsset    
返回创建的图片和视频结果。  
 **调用形式：**     
    
- createPhotoAsset(displayName: string, albumUri: string, callback: AsyncCallback\<FileAsset>): void    
起始版本： 9    
- createPhotoAsset(displayName: string, callback: AsyncCallback\<FileAsset>): void    
起始版本： 9    
- createPhotoAsset(displayName: string, albumUri?: string): Promise\<FileAsset>    
起始版本： 9    
- createPhotoAsset(displayName: string, createOption: PhotoCreateOptions): Promise\<FileAsset>    
起始版本： 9    
- createPhotoAsset(displayName: string, createOption: PhotoCreateOptions, callback: AsyncCallback\<FileAsset>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| displayName | string | true | 创建的图片或者视频文件名。 |  
| albumUri | string | true | 创建的图片或者视频所在相册的uri。 |  
| createOption | PhotoCreateOptions | true | 图片或视频的创建选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回创建的图片和视频结果。 |  
| Promise<FileAsset> | Promise对象，返回创建的图片和视频结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900020 | if parameter is invalid. |  
| 14000001 | if type displayName invalid. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('createPhotoAssetDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOptions: userFileManager.AlbumFetchOptions = {  
    predicates: predicates  
  };  
  let albums: userFileManager.FetchResult<userFileManager.Album> = await mgr.getPhotoAlbums(fetchOptions);  
  let album: userFileManager.Album = await albums.getFirstObject();  
  let testFileName: string = 'testFile' + Date.now() + '.jpg';  
  mgr.createPhotoAsset(testFileName, album.albumUri, (err, fileAsset) => {  
    if (fileAsset != undefined) {  
      console.info('createPhotoAsset file displayName' + fileAsset.displayName);  
      console.info('createPhotoAsset successfully');  
    } else {  
      console.error('createPhotoAsset failed, message = ', err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：参数名为display、createOption。  
```ts    
async function example() {  
  console.info('createPhotoAssetDemo');  
  try {  
    let testFileName: string = 'testFile' + Date.now() + '.jpg';  
    let createOption: userFileManager.PhotoCreateOptions = {  
      subType: userFileManager.PhotoSubType.DEFAULT  
    }  
    let fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName, createOption);  
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);  
    console.info('createPhotoAsset successfully');  
  } catch (err) {  
    console.error('createPhotoAsset failed, message = ', err);  
  }  
}  
    
```    
  
    
 **示例代码3：**   
示例（Promise）：参数名为display、albumUri。  
```ts    
async function example() {  
  console.info('createPhotoAssetDemo');  
  try {  
    let testFileName: string = 'testFile' + Date.now() + '.jpg';  
    let fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName);  
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);  
    console.info('createPhotoAsset successfully');  
  } catch (err) {  
    console.error('createPhotoAsset failed, message = ', err);  
  }  
}  
    
```    
  
    
### createAudioAsset<sup>(10+)</sup>    
创建音频文件资源。  
 **调用形式：**     
    
- createAudioAsset(displayName: string, callback: AsyncCallback\<FileAsset>): void    
起始版本： 10    
- createAudioAsset(displayName: string): Promise\<FileAsset>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.WRITE_AUDIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| displayName | string | true | 创建的音频文件名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回创建的音频资源结果。 |  
| Promise<FileAsset> | Promise对象，返回创建的音频资源结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900020 | if parameter is invalid. |  
| 14000001 | if type displayName invalid. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
async function example() {  
  console.info('createAudioAssetDemo');  
  let testFileName: string = 'testFile' + Date.now() + '.mp3';  
  mgr.createAudioAsset(testFileName, (err, fileAsset) => {  
    if (fileAsset != undefined) {  
      console.info('createAudioAsset file displayName' + fileAsset.displayName);  
      console.info('createAudioAsset successfully');  
    } else {  
      console.error('createAudioAsset failed, message = ', err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
async function example() {  
  console.info('createAudioAssetDemo');  
  try {  
    let testFileName: string = 'testFile' + Date.now() + '.mp3';  
    let fileAsset: userFileManager.FileAsset = await mgr.createAudioAsset(testFileName);  
    console.info('createAudioAsset file displayName' + fileAsset.displayName);  
    console.info('createAudioAsset successfully');  
  } catch (err) {  
    console.error('createAudioAsset failed, message = ', err);  
  }  
}  
    
```    
  
    
### getPhotoAlbums    
获取相册。  
 **调用形式：**     
    
- getPhotoAlbums(options: AlbumFetchOptions, callback: AsyncCallback\<FetchResult\<Album>>): void    
起始版本： 9    
- getPhotoAlbums(options: AlbumFetchOptions): Promise\<FetchResult\<Album>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | AlbumFetchOptions | true | 相册检索选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回相册检索结果。 |  
| Promise<FetchResult<Album>> | Promise对象，返回相册检索结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900020 | if type options is not AlbumFetchOptions. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getPhotoAlbumsDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let albumFetchOptions: userFileManager.AlbumFetchOptions = {  
    predicates: predicates  
  };  
  
  mgr.getPhotoAlbums(albumFetchOptions, (err, fetchResult) => {  
    if (fetchResult != undefined) {  
      console.info('albums.count = ' + fetchResult.getCount());  
      fetchResult.getFirstObject((err, album) => {  
        if (album != undefined) {  
          console.info('first album.albumName = ' + album.albumName);  
        } else {  
          console.error('album is undefined, err = ', err);  
        }  
      });  
    } else {  
      console.error('getPhotoAlbums fail, message = ', err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getPhotoAlbumsDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let albumFetchOptions: userFileManager.AlbumFetchOptions = {  
    predicates: predicates  
  };  
  try {  
    let fetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getPhotoAlbums(albumFetchOptions);  
    console.info('album.count = ' + fetchResult.getCount());  
    const album: userFileManager.Album = await fetchResult.getFirstObject();  
    console.info('first album.albumName = ' + album.albumName);  
  } catch (err) {  
    console.error('getPhotoAlbums fail, message = ' + err);  
  }  
}  
    
```    
  
    
### createAlbum<sup>(10+)</sup>    
创建相册。  
 **调用形式：**     
    
- createAlbum(name: string, callback: AsyncCallback\<Album>): void    
起始版本： 10    
- createAlbum(name: string): Promise\<Album>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回创建的相册实例。 |  
| Promise<Album> | Promise对象，返回创建的相册实例。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
async function example() {  
  console.info('createAlbumDemo');  
  let albumName: string = 'newAlbumName' + new Date().getTime();  
  mgr.createAlbum(albumName, (err, album) => {  
    if (err) {  
      console.error('createAlbumCallback failed with err: ' + err);  
      return;  
    }  
    console.info('createAlbumCallback successfully, album: ' + album.albumName + ' album uri: ' + album.albumUri);  
  });  
}    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  console.info('createAlbumDemo');  
  let albumName: string  = 'newAlbumName' + new Date().getTime();  
  mgr.createAlbum(albumName).then((album) => {  
    console.info('createAlbumPromise successfully, album: ' + album.albumName + ' album uri: ' + album.albumUri);  
  }).catch((err: BusinessError) => {  
    console.error('createAlbumPromise failed with err: ' + err);  
  });  
}  
    
```    
  
    
### deleteAlbums<sup>(10+)</sup>    
删除相册。  
 **调用形式：**     
    
- deleteAlbums(albums: Array\<Album>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- deleteAlbums(albums: Array\<Album>): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| albums | Array<Album> | true | 待删除相册的数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  // 示例代码为删除相册名为newAlbumName的相册。  
  console.info('deleteAlbumsDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  predicates.equalTo('album_name', 'newAlbumName');  
  let fetchOptions: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions);  
  let album: userFileManager.Album = await fetchResult.getFirstObject();  
  mgr.deleteAlbums([album], (err) => {  
    if (err) {  
      console.error('deletePhotoAlbumsCallback failed with err: ' + err);  
      return;  
    }  
    console.info('deletePhotoAlbumsCallback successfully');  
  });  
  fetchResult.close();  
}    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  // 示例代码为删除相册名为newAlbumName的相册。  
  console.info('deleteAlbumsDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  predicates.equalTo('album_name', 'newAlbumName');  
  let fetchOptions: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions);  
  let album: userFileManager.Album = await fetchResult.getFirstObject();  
  mgr.deleteAlbums([album]).then(() => {  
    console.info('deletePhotoAlbumsPromise successfully');  
    }).catch((err: BusinessError) => {  
      console.error('deletePhotoAlbumsPromise failed with err: ' + err);  
  });  
  fetchResult.close();  
}  
    
```    
  
    
### getAlbums<sup>(10+)</sup>    
根据检索选项和相册类型获取相册。  
 **调用形式：**     
    
- getAlbums(       type: AlbumType,       subType: AlbumSubType,       options: FetchOptions,       callback: AsyncCallback\<FetchResult\<Album>>     ): void    
起始版本： 10    
- getAlbums(type: AlbumType, subType: AlbumSubType, callback: AsyncCallback\<FetchResult\<Album>>): void    
起始版本： 10    
- getAlbums(type: AlbumType, subType: AlbumSubType, options?: FetchOptions): Promise\<FetchResult\<Album>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | AlbumType | true | 相册类型。 |  
| subType | AlbumSubType | true | 相册子类型。 |  
| options | FetchOptions | true | 检索选项，不填时默认根据相册类型检索。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回获取相册的结果集。 |  
| Promise<FetchResult<Album>> | Promise对象，返回获取相册的结果集。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900020 | if type options is not FetchOption. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  // 示例代码中为获取相册名为newAlbumName的相册。  
  console.info('getAlbumsDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  predicates.equalTo('album_name', 'newAlbumName');  
  let fetchOptions: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions, async (err, fetchResult) => {  
    if (err) {  
      console.error('getAlbumsCallback failed with err: ' + err);  
      return;  
    }  
    if (fetchResult == undefined) {  
      console.error('getAlbumsCallback fetchResult is undefined');  
      return;  
    }  
    let album: userFileManager.Album = await fetchResult.getFirstObject();  
    console.info('getAlbumsCallback successfully, albumName: ' + album.albumName);  
    fetchResult.close();  
  });  
}    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  // 示例代码中为获取相册名为newAlbumName的相册。  
  console.info('getAlbumsDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  predicates.equalTo('album_name', 'newAlbumName');  
  let fetchOptions: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions).then( async (fetchResult) => {  
    if (fetchResult == undefined) {  
      console.error('getAlbumsPromise fetchResult is undefined');  
      return;  
    }  
    let album: userFileManager.Album = await fetchResult.getFirstObject();  
    console.info('getAlbumsPromise successfully, albumName: ' + album.albumName);  
    fetchResult.close();  
  }).catch((err: BusinessError) => {  
    console.error('getAlbumsPromise failed with err: ' + err);  
  });  
}  
    
```    
  
    
### getPrivateAlbum    
获取系统相册。  
 **调用形式：**     
    
- getPrivateAlbum(type: PrivateAlbumType, callback: AsyncCallback\<FetchResult\<PrivateAlbum>>): void    
起始版本： 9    
- getPrivateAlbum(type: PrivateAlbumType): Promise\<FetchResult\<PrivateAlbum>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | PrivateAlbumType | true | 系统相册类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回相册检索结果。 |  
| Promise<FetchResult<PrivateAlbum>> | Promise对象，返回相册检索结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900020 | if type type is not PrivateAlbumType. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
async function example() {  
  console.info('getPrivateAlbumDemo');  
  mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH, async (err, fetchResult) => {  
    if (fetchResult != undefined) {  
      let trashAlbum: userFileManager.PrivateAlbum = await fetchResult.getFirstObject();  
      console.info('first album.albumName = ' + trashAlbum.albumName);  
    } else {  
      console.error('getPrivateAlbum failed. message = ', err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
async function example() {  
  console.info('getPrivateAlbumDemo');  
  try {  
    let fetchResult: userFileManager.FetchResult<userFileManager.PrivateAlbum> = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);  
    let trashAlbum: userFileManager.PrivateAlbum = await fetchResult.getFirstObject();  
    console.info('first album.albumName = ' + trashAlbum.albumName);  
  } catch (err) {  
    console.error('getPrivateAlbum failed. message = ', err);  
  }  
}  
    
```    
  
    
### getAudioAssets    
获取音频文件。  
 **调用形式：**     
    
- getAudioAssets(options: FetchOptions, callback: AsyncCallback\<FetchResult\<FileAsset>>): void    
起始版本： 9    
- getAudioAssets(options: FetchOptions): Promise\<FetchResult\<FileAsset>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.READ_AUDIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | FetchOptions | true | 检索选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回音频检索结果。 |  
| Promise<FetchResult<FileAsset>> | Promise对象，返回音频检索结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900020 | if type options is not FetchOptions. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getAudioAssets');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOptions: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  
  mgr.getAudioAssets(fetchOptions, async (err, fetchResult) => {  
    if (fetchResult != undefined) {  
      console.info('fetchFileResult success');  
      let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
      if (fileAsset != undefined) {  
        console.info('fileAsset.displayName :' + fileAsset.displayName);  
      }  
    } else {  
      console.error('fetchFileResult fail' + err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getAudioAssets');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOptions: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  try {  
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getAudioAssets(fetchOptions);  
    if (fetchResult != undefined) {  
      console.info('fetchFileResult success');  
      let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
      if (fileAsset != undefined) {  
        console.info('fileAsset.displayName :' + fileAsset.displayName);  
      }  
    }  
  } catch (err) {  
    console.error('getAudioAssets failed, message = ', err);  
  }  
}  
    
```    
  
    
### delete    
删除媒体文件,删除的文件进入到回收站。  
 **调用形式：**     
    
- delete(uri: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- delete(uri: string): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.READ_AUDIO and ohos.permission.WRITE_AUDIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 媒体文件uri。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900020 | if type uri is not string. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('deleteAssetDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOptions: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  try {  
    const fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);  
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
  
  
    if (asset == undefined) {  
      console.error('asset not exist');  
      return;  
    }  
    mgr.delete(asset.uri, (err) => {  
      if (err == undefined) {  
        console.info('delete successfully');  
      } else {  
        console.error('delete failed with error: ' + err);  
      }  
    });  
  } catch (err) {  
    console.info('fetch failed, message =', err);  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('deleteDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOptions: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  try {  
    const fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);  
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    if (asset == undefined) {  
      console.error('asset not exist');  
      return;  
    }  
    await mgr.delete(asset.uri);  
    console.info('delete successfully');  
  } catch (err) {  
    console.error('delete failed with error: ' + err);  
  }  
}  
    
```    
  
    
### getPhotoIndex<sup>(10+)</sup>    
获取相册中图片或视频的位置。  
 **调用形式：**     
    
- getPhotoIndex(photoUri: string, albumUri: string, options: FetchOptions, callback: AsyncCallback\<number>): void    
起始版本： 10    
- getPhotoIndex(photoUri: string, albumUri: string, options: FetchOptions): Promise\<number>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| photoUri | string | true | 所查询的图库资源的uri。 |  
| albumUri | string | true | 相册uri，可以为空字符串，为空字符串时默认查询全部图库资源。 |  
| options | FetchOptions | true | 检索选项，predicates中必须设置一种检索排序方式，不设置或多设置均会导致接口调用异常。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回相册中资源的索引。 |  
| Promise<number> | 返回相册中资源的索引。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  try {  
    console.info('getPhotoIndexDemo');  
    let predicatesForGetAsset: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOp: userFileManager.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicatesForGetAsset  
    };  
    // Obtain the uri of the album  
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.FAVORITE, fetchOp);  
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    predicates.orderByAsc(userFileManager.ImageVideoKey.DATE_MODIFIED.toString());  
    let fetchOptions: userFileManager.FetchOptions = {  
      fetchColumns: [userFileManager.ImageVideoKey.DATE_MODIFIED.toString()],  
      predicates: predicates  
    };  
    let photoFetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOptions);  
    let expectIndex = 1;  
    // Obtain the uri of the second file  
    let photoAsset: userFileManager.FileAsset = await photoFetchResult.getPositionObject(expectIndex);  
    mgr.getPhotoIndex(photoAsset.uri, album.albumUri, fetchOptions, (err, index) => {  
      if (err == undefined) {  
        console.info(`getPhotoIndex successfully and index is : ${index}`);  
      } else {  
        console.info(`getPhotoIndex failed;`);  
      }  
    });  
  } catch (error) {  
    console.info(`getPhotoIndex failed; error: ${error}`);  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  try {  
    console.info('getPhotoIndexDemo');  
    let predicatesForGetAsset: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOp: userFileManager.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicatesForGetAsset  
    };  
    // Obtain the uri of the album  
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.FAVORITE, fetchOp);  
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    predicates.orderByAsc(userFileManager.ImageVideoKey.DATE_MODIFIED.toString());  
    let fetchOptions: userFileManager.FetchOptions = {  
      fetchColumns: [userFileManager.ImageVideoKey.DATE_MODIFIED.toString()],  
      predicates: predicates  
    };  
    let photoFetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOptions);  
    let expectIndex = 1;  
    // Obtain the uri of the second file  
    let photoAsset: userFileManager.FileAsset = await photoFetchResult.getPositionObject(expectIndex);  
    mgr.getPhotoIndex(photoAsset.uri, album.albumUri, fetchOptions).then((index) => {  
      console.info(`getPhotoIndex successfully and index is : ${index}`);  
    }).catch((err: BusinessError) => {  
      console.info(`getPhotoIndex failed; error: ${err}`);  
    });  
  } catch (error) {  
    console.info(`getPhotoIndex failed; error: ${error}`);  
  }  
}  
    
```    
  
    
### on    
打开文件管理库变更通知，使用callback方式返回异步结果。  
 **调用形式：**     
- on(type: ChangeEvent, callback: Callback\<void>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | ChangeEvent | true | 媒体类型 <br/>'deviceChange'：注册设备变更 <br/>'albumChange'：相册变更<br/>'imageChange'：图片文件变更<br/>'audioChange'： 音频文件变更<br/>'videoChange'：  视频文件变更<br/>'remoteFileChange'：注册设备上文件变更 |  
| callback | Callback<void> | true | callback返回void |  
    
 **示例代码：**   
示例（callback）：  
```ts    
async function example() {  
  console.info('onDemo');  
  let count = 0;  
  mgr.on('imageChange', () => {  
    count++;  
    // image file had changed, do something  
  });  
  try {  
    let testFileName: string = 'testFile' + Date.now() + '.jpg';  
    let fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName);  
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);  
    console.info('createPhotoAsset successfully');  
  } catch (err) {  
    console.error('createPhotoAsset failed, message = ' + err);  
  }  
  //sleep 1s  
  if (count > 0) {  
    console.info('onDemo success');  
  } else {  
    console.error('onDemo fail');  
  }  
  mgr.off('imageChange', () => {  
    // stop listening success  
  });  
}  
    
```    
  
    
### off    
关闭文件管理库变更通知，使用callback方式返回异步结果。  
 **调用形式：**     
- off(type: ChangeEvent, callback?: Callback\<void>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | ChangeEvent | true | 媒体类型 <br/>'deviceChange'：注册设备变更 <br/>'albumChange'：相册变更<br/>'imageChange'：图片文件变更<br/>'audioChange'： 音频文件变更<br/>'videoChange'：  视频文件变更<br/>'remoteFileChange'：注册设备上文件变更。 |  
| callback | Callback<void> | false | callback返回void。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
async function example() {  
  console.info('offDemo');  
  let count = 0;  
  mgr.on('imageChange', () => {  
    count++;  
    // image file had changed, do something  
  });  
  
  mgr.off('imageChange', () => {  
    // stop listening success  
  });  
  
  try {  
    let testFileName: string = 'testFile' + Date.now() + '.jpg';  
    let fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName);  
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);  
    console.info('createPhotoAsset successfully');  
  } catch (err) {  
    console.error('createPhotoAsset failed, message = ' + err);  
  }  
  //sleep 1s  
  if (count == 0) {  
    console.info('offDemo success');  
  } else {  
    console.error('offDemo fail');  
  }  
}  
    
```    
  
    
### on<sup>(10+)</sup>    
对指定uri注册监听，使用callback方式返回异步结果。  
 **调用形式：**     
    
- on(uri: string, forSubUri: boolean, callback: Callback\<ChangeData>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | FileAsset的uri, Album的uri或[DefaultChangeUri](#defaultchangeuri10)的值。 |  
| forSubUri | boolean | true | 是否模糊监听，uri为相册uri时，forSubUri 为true能监听到相册中文件的变化，如果是false只能监听相册本身变化。uri为fileAsset时，forSubUri 为true、false没有区别，uri为DefaultChangeUri时，forSubUri必须为true，如果为false将找不到该uri，收不到任何消息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回要监听的[ChangeData](#changedata10)。注：uri可以注册多个不同的callback监听，[off<sup>10+</sup>](#off10)可以关闭该uri所有监听，也可以关闭指定callback的监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900020 | if parameter is invalid. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('onDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOptions: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);  
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
  if (fileAsset != undefined) {  
    console.info('fileAsset.displayName : ' + fileAsset.displayName);  
  }  
  let onCallback1 = (changeData: userFileManager.ChangeData) => {  
      console.info('onCallback1 success, changData: ' + JSON.stringify(changeData));  
    //file had changed, do something  
  }  
  let onCallback2 = (changeData: userFileManager.ChangeData) => {  
      console.info('onCallback2 success, changData: ' + JSON.stringify(changeData));  
    //file had changed, do something  
  }  
  // 注册onCallback1监听  
  mgr.on(fileAsset.uri, false, onCallback1);  
  // 注册onCallback2监听  
  mgr.on(fileAsset.uri, false, onCallback2);  
  
  fileAsset.favorite(true, (err) => {  
    if (err == undefined) {  
      console.info('favorite successfully');  
    } else {  
      console.error('favorite failed with error:' + err);  
    }  
  });  
}  
    
```    
  
    
### off<sup>(10+)</sup>    
取消对指定uri的监听，一个uri可以注册多个监听，存在多个callback监听时，可以取消指定注册的callback的监听；不指定callback时解除该uri的所有监听。  
 **调用形式：**     
    
- off(uri: string, callback?: Callback\<ChangeData>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | FileAsset的uri, Album的uri或[DefaultChangeUri](#defaultchangeuri10)的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消[on<sup>10+</sup>](#on10)注册时的callback的监听，不填时，取消该uri的所有监听。注：off指定注册的callback后不会进入此回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900020 | if parameter is invalid. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('offDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOptions: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);  
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
  if (fileAsset != undefined) {  
    console.info('fileAsset.displayName : ' + fileAsset.displayName);  
  }  
  let onCallback1 = (changeData: userFileManager.ChangeData) => {  
    console.info('onCallback1 on');  
  }  
  let onCallback2 = (changeData: userFileManager.ChangeData) => {  
    console.info('onCallback2 on');  
  }  
  // 注册onCallback1监听  
  mgr.on(fileAsset.uri, false, onCallback1);  
  // 注册onCallback2监听  
  mgr.on(fileAsset.uri, false, onCallback2);  
  // 关闭onCallback1监听，onCallback2 继续监听  
  mgr.off(fileAsset.uri, onCallback1);  
  fileAsset.favorite(true, (err) => {  
    if (err == undefined) {  
      console.info('favorite successfully');  
    } else {  
      console.error('favorite failed with error:' + err);  
    }  
  });  
}  
    
```    
  
    
### getActivePeers    
获取在线对端设备的信息。  
 **调用形式：**     
    
- getActivePeers(callback: AsyncCallback\<Array\<PeerInfo>>): void    
起始版本： 9    
- getActivePeers(): Promise\<Array\<PeerInfo>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.DistributedCore    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回在线设备列表。 |  
| Promise<Array<PeerInfo>> | Promise对象，返回在线设备列表。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
async function example() {  
  console.info('getActivePeersDemo');  
  mgr.getActivePeers((err, devicesInfo) => {  
    if (devicesInfo != undefined) {  
      console.log('getActivePeers succeed.');  
      for (let i = 0; i < devicesInfo.length; i++) {  
        console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);  
      }  
    } else {  
      console.error('getActivePeers failed. message = ', err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
async function example() {  
  console.info('getActivePeersDemo');  
  try {  
    let devicesInfo: Array<userFileManager.PeerInfo> = await mgr.getActivePeers();  
    if (devicesInfo != undefined) {  
      console.log('getActivePeers succeed.');  
      for (let i = 0; i < devicesInfo.length; i++) {  
        console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);  
      }  
    } else {  
      console.error('get distributed fail');  
    }  
  } catch (err) {  
    console.error('getActivePeers failed. message = ', err);  
  }  
}  
    
```    
  
    
### getAllPeers    
获取所有对端设备的信息。  
 **调用形式：**     
    
- getAllPeers(callback: AsyncCallback\<Array\<PeerInfo>>): void    
起始版本： 9    
- getAllPeers(): Promise\<Array\<PeerInfo>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.DistributedCore    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回在线设备列表。 |  
| Promise<Array<PeerInfo>> | Promise对象，返回所有设备列表。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
async function example() {  
  console.info('getAllPeersDemo');  
  mgr.getAllPeers((err, devicesInfo) => {  
    if (devicesInfo != undefined) {  
      console.log('getAllPeers succeed.');  
      for (let i = 0; i < devicesInfo.length; i++) {  
        console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);  
      }  
    } else {  
      console.error('getAllPeers failed. message = ', err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
async function example() {  
  console.info('getActivePeersDemo');  
  try {  
    let devicesInfo: Array<userFileManager.PeerInfo> = await mgr.getActivePeers();  
    if (devicesInfo != undefined) {  
      console.log('getActivePeers succeed.');  
      for (let i = 0; i < devicesInfo.length; i++) {  
        console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);  
      }  
    } else {  
      console.error('get distributed fail');  
    }  
  } catch (err) {  
    console.error('getActivePeers failed. message = ', err);  
  }  
}  
    
```    
  
    
### release    
释放UserFileManager实例。 当后续不需要使用UserFileManager 实例中的方法时调用。  
 **调用形式：**     
    
- release(callback: AsyncCallback\<void>): void    
起始版本： 9    
- release(): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调表示成功还是失败。 |  
| Promise<void> | Promise对象，返回void。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
async function example() {  
  console.info('releaseDemo');  
  mgr.release((err) => {  
    if (err != undefined) {  
      console.error('release failed. message = ', err);  
    } else {  
      console.info('release ok.');  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
async function example() {  
  console.info('releaseDemo');  
  try {  
    await mgr.release();  
    console.info('release ok.');  
  } catch (err) {  
    console.error('release failed. message = ', err);  
  }  
}  
    
```    
  
    
## NotifyType<sup>(10+)</sup>    
枚举，通知事件的类型。    
    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NOTIFY_ADD | 0 | 添加文件集或相册通知的类型。 |  
| NOTIFY_UPDATE | 1 | 文件集或相册的更新通知类型。 |  
| NOTIFY_REMOVE | 2 | 删除文件集或相册的通知类型。 |  
| NOTIFY_ALBUM_ADD_ASSET | 3 | 在相册中添加的文件集的通知类型。 |  
| NOTIFY_ALBUM_REMOVE_ASSET | 4 | 在相册中删除的文件集的通知类型。 |  
    
## DefaultChangeUri<sup>(10+)</sup>    
枚举，DefaultChangeUri子类型。    
    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEFAULT_PHOTO_URI | 0 | 默认PhotoAsset的Uri，与forSubUri{true}一起使用，将接收所有PhotoAsset的更改通知。 |  
| DEFAULT_ALBUM_URI | 1 | 默认相册的Uri，与forSubUri{true}一起使用，将接收所有相册的更改通知。 |  
| DEFAULT_AUDIO_URI | 2 | 默认AudioAsset的Uri，与forSubUri{true}一起使用，将接收所有AudioAsset的更改通知。 |  
    
## ChangeData<sup>(10+)</sup>    
监听器回调函数的值。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type<sup>(10+)</sup> | NotifyType | false | true | ChangeData的通知类型。 |  
| uris<sup>(10+)</sup> | Array<string> | false | true | 相同[NotifyType](#notifytype10)的所有uri，可以是FileAsset或Album。 |  
| subUris<sup>(10+)</sup> | Array<string> | false | true | 相册中变动文件的uri数组。 |  
    
## PeerInfo    
注册设备的信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.DistributedCore    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.DistributedCore    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceName | string | true | true | 注册设备的名称。 |  
| networkId | string | true | true | 注册设备的网络ID。 |  
| isOnline | boolean | true | true | 是否在线。 |  
    
## PrivateAlbumType    
枚举，系统相册类型。    
    
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_FAVORITE | 0 | 收藏夹相册。 |  
| TYPE_TRASH | 1 | 回收站相册。 |  
    
## PrivateAlbum    
系统相册。  
  
此接口即将废弃，请使用[Album](#album)接口替代。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core    
### delete    
删除系统相册中的文件，仅支持删除回收站相册中文件。  
 **调用形式：**     
    
- delete(uri: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- delete(uri: string): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.READ_AUDIO and ohos.permission.WRITE_AUDIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 系统相册中文件的uri。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('deleteAssetDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOptions: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  try {  
    const fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);  
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
  
  
    if (asset == undefined) {  
      console.error('asset not exist');  
      return;  
    }  
    mgr.delete(asset.uri, (err) => {  
      if (err == undefined) {  
        console.info('delete successfully');  
      } else {  
        console.error('delete failed with error: ' + err);  
      }  
    });  
  } catch (err) {  
    console.info('fetch failed, message =', err);  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('deleteDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOptions: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  try {  
    const fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);  
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
    if (asset == undefined) {  
      console.error('asset not exist');  
      return;  
    }  
    await mgr.delete(asset.uri);  
    console.info('delete successfully');  
  } catch (err) {  
    console.error('delete failed with error: ' + err);  
  }  
}  
    
```    
  
    
### recover    
恢复系统相册中的文件，仅支持恢复回收站相册中文件。  此接口即将废弃，请使用[Album.recoverPhotoAssets](#recoverphotoassets10)接口替代。  
 **调用形式：**     
    
- recover(uri: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- recover(uri: string): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileManager.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.READ_AUDIO and ohos.permission.WRITE_AUDIO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 系统相册中文件的uri。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('privateAlbumRecoverDemoCallback');  
  let albumList: userFileManager.FetchResult<userFileManager.PrivateAlbum> = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let trashAlbum: userFileManager.PrivateAlbum = await albumList.getFirstObject();  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await trashAlbum.getPhotoAssets(fetchOption);  
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
  let recoverFileUri: string = fileAsset.uri;  
  trashAlbum.recover(recoverFileUri, (err) => {  
    if (err != undefined) {  
      console.error('trashAlbum.recover failed, message = ', err);  
    } else {  
      console.info('trashAlbum.recover successfully');  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  console.info('privateAlbumRecoverDemoPromise');  
  let albumList: userFileManager.FetchResult<userFileManager.PrivateAlbum> = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: userFileManager.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let trashAlbum: userFileManager.PrivateAlbum = await albumList.getFirstObject();  
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await trashAlbum.getPhotoAssets(fetchOption);  
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();  
  let recoverFileUri: string = fileAsset.uri;  
  trashAlbum.recover(recoverFileUri).then(() => {  
    console.info('trashAlbum.recover successfully');  
  }).catch((err: BusinessError) => {  
    console.error('trashAlbum.recover failed, message = ', err);  
  });  
}  
    
```    
  
