# @ohos.file.photoAccessHelper    
该模块提供相册管理模块能力，包括创建相册以及访问、修改相册中的媒体数据信息等。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import photoAccessHelper from '@ohos.file.photoAccessHelper'    
```  
    
## PhotoSubtype    
枚举，媒体文件类型。    
    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEFAULT | 0 | 默认照片类型。 |  
| SCREENSHOT | 1 | 截屏录屏文件类型。 |  
    
## PositionType    
枚举，文件位置，表示文件在本地或云端。    
    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| LOCAL | 1 << 0 | 文件只存在于本端设备。 |  
| CLOUD | 1 << 1 | 文件只存在于云端。 |  
    
## PhotoAsset    
提供封装文件属性的方法。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
### open    
打开当前文件。  
 **调用形式：**     
    
- open(mode: string, callback: AsyncCallback\<number>): void    
起始版本： 10    
- open(mode: string): Promise\<number>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO or ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode | string | true | 打开文件方式，如：'r'（只读）, 'w'（只写）, 'rw'（读写）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回文件描述符。 |  
| Promise<number> | Promise对象，返回文件描述符。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Called by non-system application. |  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
async function example() {  
  console.info('openDemo');  
   let testFileName: string = 'testFile' + Date.now() + '.jpg';  
  const photoAsset: photoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(testFileName);  
  photoAsset.open('rw', (err, fd) => {  
    if (fd != undefined) {  
      console.info('File fd' + fd);  
      photoAsset.close(fd);  
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
    const photoAsset: photoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(testFileName);  
    let fd: number = await photoAsset.open('rw');  
    if (fd != undefined) {  
      console.info('File fd' + fd);  
      photoAsset.close(fd);  
    } else {  
      console.error(' open File fail');  
    }  
  } catch (err) {  
    console.error('open Demo err' + err);  
  }  
}  
    
```    
  
    
### setFavorite    
将文件设置为收藏文件。  
 **调用形式：**     
    
- setFavorite(favoriteState: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setFavorite(favoriteState: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| favoriteState | boolean | true | 是否设置为收藏文件， true：设置为收藏文件，false：取消收藏。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Called by non-system application. |  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('setFavoriteDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  const asset = await fetchResult.getFirstObject();  
  asset.setFavorite(true, (err) => {  
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
  console.info('setFavoriteDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  const asset = await fetchResult.getFirstObject();  
  asset.setFavorite(true).then(() => {  
    console.info('setFavorite successfully');  
  }).catch((err: BusinessError) => {  
    console.error('setFavorite failed with error:' + err);  
  });  
}  
    
```    
  
    
### setHidden    
将文件设置为隐私文件。  
 **调用形式：**     
    
- setHidden(hiddenState: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setHidden(hiddenState: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| hiddenState | boolean | true | 是否设置为隐藏文件，true:将文件资产放入隐藏相册;false:从隐藏相册中恢复。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Called by non-system application. |  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('setHiddenDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  const asset = await fetchResult.getFirstObject();  
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
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let albumList: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.HIDDEN);  
  const album = await albumList.getFirstObject();  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);  
  const asset = await fetchResult.getFirstObject();  
  asset.setHidden(false).then(() => {  
    console.info('setHidden successfully');  
  }).catch((err: BusinessError) => {  
    console.error('setHidden failed with error:' + err);  
  });  
}  
    
```    
  
    
### setUserComment    
修改图片或者视频的备注信息。  
 **调用形式：**     
    
- setUserComment(userComment: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setUserComment(userComment: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
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
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  try {  
    console.info('setUserCommentDemo')  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOptions: photoAccessHelper.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);  
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    let userComment = 'test_set_user_comment';  
    await photoAsset.setUserComment(userComment);  
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
    let fetchOptions: photoAccessHelper.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);  
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    let userComment = 'test_set_user_comment';  
    photoAsset.setUserComment(userComment, (err) => {  
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
  
    
### getExif    
返回jpg格式图片Exif标签组成的json格式的字符串。  
 **调用形式：**     
    
- getExif(callback: AsyncCallback\<string>): void    
起始版本： 10    
- getExif(): Promise\<string>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回Exif字段组成的json格式的字符串。 |  
| Promise<string> | 返回Exif标签组成的json格式的字符串。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Called by non-system application. |  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  try {  
    console.info('getExifDemo');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOptions: photoAccessHelper.FetchOptions = {  
      fetchColumns: [ 'all_exif',  photoAccessHelper.PhotoKeys.USER_COMMENT],  
      predicates: predicates  
    };  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);  
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    let exifMessage = await photoAsset.getExif();  
    let userCommentKey = 'UserComment';  
    let userComment = JSON.stringify(JSON.parse(exifMessage), [userCommentKey]);  
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
    let fetchOptions: photoAccessHelper.FetchOptions = {  
      fetchColumns: ['all_exif', photoAccessHelper.PhotoKeys.USER_COMMENT],  
      predicates: predicates  
    };  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);  
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    console.info('getExifDemo photoAsset displayName: ' + JSON.stringify(photoAsset.displayName));  
    let userCommentKey = 'UserComment';  
    photoAsset.getExif((err, exifMessage) => {  
      if (exifMessage != undefined) {  
        let userComment = JSON.stringify(JSON.parse(exifMessage), [userCommentKey]);  
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
  
    
## PhotoKeys    
枚举，图片和视频文件关键信息。    
    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| POSITION | position | 文件位置类型。 |  
| DATE_TRASHED | date_trashed | 删除日期（删除文件时间距1970年1月1日的秒数值）。 |  
| HIDDEN | hidden | 文件的隐藏状态。 |  
| USER_COMMENT | user_comment | 用户注释信息。 |  
| CAMERA_SHOT_KEY | camera_shot_key | 锁屏相机拍照或录像的标记字段（仅开放给系统相机,其key值由系统相机定义）。 |  
| DATE_YEAR<sup>(11+)</sup> | date_year | 创建文件的年份。 |  
| DATE_MONTH<sup>(11+)</sup> | date_month | 创建文件的月份。 |  
| DATE_DAY<sup>(11+)</sup> | date_day | 创建文件的日期。 |  
    
## PhotoCreateOptions    
图片或视频的创建选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| subtype | PhotoSubtype | false | false | 图片或者视频的子类型。 |  
| cameraShotKey | string | false | false | 锁屏相机拍照或录像的标记字段（仅开放给系统相机,其key值由系统相机定义）。 |  
    
## AlbumSubtype    
枚举，相册子类型，表示具体的相册类型。    
    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HIDDEN | 1027 | 隐藏相册。 |  
| TRASH | 1028 | 回收站。 |  
| SCREENSHOT | 1029 | 截屏和录屏相册。 |  
| CAMERA | 1030 | 相机拍摄的照片和视频相册。 |  
    
## Album    
实体相册  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
### recoverAssets    
从回收站中恢复图片或者视频，需要先在回收站中预置文件资源。  
 **调用形式：**     
    
- recoverAssets(assets: Array\<PhotoAsset>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- recoverAssets(assets: Array\<PhotoAsset>): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| assets | Array<PhotoAsset> | true | 回收站中待恢复图片或者视频数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Called by non-system application. |  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  try {  
    console.info('recoverAssetsDemoCallback');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: photoAccessHelper.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.TRASH);  
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);  
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    album.recoverAssets([asset], (err) => {  
      if (err === undefined) {  
        console.info('album recoverAssets successfully');  
      } else {  
        console.error('album recoverAssets failed with error: ' + err);  
      }  
    });  
  } catch (err) {  
    console.error('recoverAssetsDemoCallback failed with error: ' + err);  
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
    console.info('recoverAssetsDemoPromise');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: photoAccessHelper.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.TRASH);  
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);  
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    album.recoverAssets([asset]).then(() => {  
      console.info('album recoverAssets successfully');  
    }).catch((err: BusinessError) => {  
      console.error('album recoverAssets failed with error: ' + err);  
    });  
  } catch (err) {  
    console.error('recoverAssetsDemoPromise failed with error: ' + err);  
  }  
}  
    
```    
  
    
### deleteAssets    
从回收站中彻底删除图片或者视频，需要先在回收站中预置文件资源。  
 **调用形式：**     
    
- deleteAssets(assets: Array\<PhotoAsset>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- deleteAssets(assets: Array\<PhotoAsset>): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| assets | Array<PhotoAsset> | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Called by non-system application. |  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  try {  
    console.info('deleteAssetsDemoCallback');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: photoAccessHelper.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.TRASH);  
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);  
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    album.deleteAssets([asset], (err) => {  
      if (err === undefined) {  
        console.info('album deleteAssets successfully');  
      } else {  
        console.error('album deleteAssets failed with error: ' + err);  
      }  
    });  
  } catch (err) {  
    console.error('deleteAssetsDemoCallback failed with error: ' + err);  
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
    console.info('deleteAssetsDemoPromise');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: photoAccessHelper.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.TRASH);  
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);  
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    album.deleteAssets([asset]).then(() => {  
      console.info('album deleteAssets successfully');  
    }).catch((err: BusinessError) => {  
      console.error('album deleteAssets failed with error: ' + err);  
    });  
  } catch (err) {  
    console.error('deleteAssetsDemoPromise failed with error: ' + err);  
  }  
}  
    
```    
  
    
### setCoverUri    
设置相册封面。  
 **调用形式：**     
    
- setCoverUri(uri: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setCoverUri(uri: string): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 待设置为相册封面文件的uri。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Called by non-system application. |  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  try {  
    console.info('setCoverUriDemoCallback');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: photoAccessHelper.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);  
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);  
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    album.setCoverUri(asset.uri, (err) => {  
      if (err === undefined) {  
        console.info('album setCoverUri successfully');  
      } else {  
        console.error('album setCoverUri failed with error: ' + err);  
      }  
    });  
  } catch (err) {  
    console.error('setCoverUriDemoCallback failed with error: ' + err);  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  try {  
    console.info('setCoverUriDemoCallback');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: photoAccessHelper.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);  
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);  
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    album.setCoverUri(asset.uri, (err) => {  
      if (err === undefined) {  
        console.info('album setCoverUri successfully');  
      } else {  
        console.error('album setCoverUri failed with error: ' + err);  
      }  
    });  
  } catch (err) {  
    console.error('setCoverUriDemoCallback failed with error: ' + err);  
  }  
}  
    
```    
  
    
## PhotoAccessHelper  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
### createAsset    
指定待创建的文件类型和后缀，创建图片或视频资源。  
 **调用形式：**     
    
- createAsset(displayName: string, callback: AsyncCallback\<PhotoAsset>): void    
起始版本： 10    
- createAsset(displayName: string): Promise\<PhotoAsset>    
起始版本： 10    
- createAsset(displayName: string, options: PhotoCreateOptions): Promise\<PhotoAsset>    
起始版本： 10    
- createAsset(displayName: string, options: PhotoCreateOptions, callback: AsyncCallback\<PhotoAsset>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| displayName | string | true | 创建的图片或者视频文件名。 |  
| options | PhotoCreateOptions | true | 创建选项，例如{title: 'testPhoto'}。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回创建的图片和视频的uri。 |  
| Promise<PhotoAsset> | Promise对象，返回创建的图片和视频结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Called by non-system application. |  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000001 | Invalid display name. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
async function example() {  
  console.info('createAssetDemo');  
  let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;  
  let extension:string = 'jpg';  
  let options: photoAccessHelper.CreateOptions = {  
    title: 'testPhoto'  
  }  
  phAccessHelper.createAsset(photoType, extension, options, (err, uri) => {  
    if (uri != undefined) {  
      console.info('createAsset uri' + uri);  
      console.info('createAsset successfully');  
    } else {  
      console.error('createAsset failed, message = ', err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
async function example() {  
  console.info('createAssetDemo');  
  try {  
    let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;  
    let extension: string = 'jpg';  
    let options: photoAccessHelper.CreateOptions = {  
      title: 'testPhoto'  
    }  
    let uri: string = await phAccessHelper.createAsset(photoType, extension, options);  
    console.info('createAsset uri' + uri);  
    console.info('createAsset successfully');  
  } catch (err) {  
    console.error('createAsset failed, message = ', err);  
  }  
}  
    
```    
  
    
### createAlbum    
创建相册。  
 **调用形式：**     
    
- createAlbum(name: string, callback: AsyncCallback\<Album>): void    
起始版本： 10    
- createAlbum(name: string): Promise\<Album>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 待创建相册的相册名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回创建的相册实例。 |  
| Promise<Album> | Promise对象，返回创建的相册实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Called by non-system application. |  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900015 | File exists. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
async function example() {  
  console.info('createAlbumDemo');  
  let albumName: string = 'newAlbumName' + new Date().getTime();  
  phAccessHelper.createAlbum(albumName, (err, album) => {  
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
  let albumName: string = 'newAlbumName' + new Date().getTime();  
  phAccessHelper.createAlbum(albumName).then((album) => {  
    console.info('createAlbumPromise successfully, album: ' + album.albumName + ' album uri: ' + album.albumUri);  
  }).catch((err: BusinessError) => {  
    console.error('createAlbumPromise failed with err: ' + err);  
  });  
}  
    
```    
  
    
### deleteAlbums    
删除相册。  删除相册前需先确保相册存在，只能删除用户相册。  
 **调用形式：**     
    
- deleteAlbums(albums: Array\<Album>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- deleteAlbums(albums: Array\<Album>): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
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
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Called by non-system application. |  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  // 示例代码为删除相册名为newAlbumName的相册。  
  console.info('deleteAlbumsDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  predicates.equalTo('album_name', 'newAlbumName');  
  let fetchOptions: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions);  
  let album: photoAccessHelper.Album = await fetchResult.getFirstObject();  
  phAccessHelper.deleteAlbums([album], (err) => {  
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
  let fetchOptions: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions);  
  let album: photoAccessHelper.Album = await fetchResult.getFirstObject();  
  phAccessHelper.deleteAlbums([album]).then(() => {  
    console.info('deletePhotoAlbumsPromise successfully');  
    }).catch((err: BusinessError) => {  
      console.error('deletePhotoAlbumsPromise failed with err: ' + err);  
  });  
  fetchResult.close();  
}  
    
```    
  
    
### deleteAssets    
删除媒体文件，删除的文件进入到回收站。  
 **调用形式：**     
    
- deleteAssets(uriList: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- deleteAssets(uriList: Array\<string>): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uriList | Array<string> | true | 待删除的媒体文件uri数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Called by non-system application. |  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000002 | Invalid uri. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('deleteAssetDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOptions: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  try {  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);  
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    if (asset == undefined) {  
      console.error('asset not exist');  
      return;  
    }  
    phAccessHelper.deleteAssets([asset.uri], (err) => {  
      if (err == undefined) {  
        console.info('deleteAssets successfully');  
      } else {  
        console.error('deleteAssets failed with error: ' + err);  
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
  let fetchOptions: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  try {  
    const fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);  
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    if (asset == undefined) {  
      console.error('asset not exist');  
      return;  
    }  
    await phAccessHelper.deleteAssets([asset.uri]);  
    console.info('deleteAssets successfully');  
  } catch (err) {  
    console.error('deleteAssets failed with error: ' + err);  
  }  
}  
    
```    
  
    
### getPhotoIndex    
获取相册中图片或视频的位置。  
 **调用形式：**     
    
- getPhotoIndex(photoUri: string, albumUri: string, options: FetchOptions, callback: AsyncCallback\<number>): void    
起始版本： 10    
- getPhotoIndex(photoUri: string, albumUri: string, options: FetchOptions): Promise\<number>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
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
| 202 | Called by non-system application. |  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  try {  
    console.info('getPhotoIndexDemo');  
    let predicatesForGetAsset: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOp: photoAccessHelper.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicatesForGetAsset  
    };  
    // Obtain the uri of the album  
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.FAVORITE, fetchOp);  
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    predicates.orderByAsc(photoAccessHelper.PhotoKeys.DATE_MODIFIED);  
    let fetchOptions: photoAccessHelper.FetchOptions = {  
      fetchColumns: [photoAccessHelper.PhotoKeys.DATE_MODIFIED],  
      predicates: predicates  
    };  
    let photoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);  
    let expectIndex = 1;  
    // Obtain the uri of the second file  
    let photoAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getObjectByPosition(expectIndex);  
  
    phAccessHelper.getPhotoIndex(photoAsset.uri, album.albumUri, fetchOptions, (err, index) => {  
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
    let fetchOp: photoAccessHelper.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicatesForGetAsset  
    };  
    // Obtain the uri of the album  
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.FAVORITE, fetchOp);  
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    predicates.orderByAsc(photoAccessHelper.PhotoKeys.DATE_MODIFIED);  
    let fetchOptions: photoAccessHelper.FetchOptions = {  
      fetchColumns: [photoAccessHelper.PhotoKeys.DATE_MODIFIED],  
      predicates: predicates  
    };  
    let photoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);  
    let expectIndex = 1;  
    // Obtain the uri of the second file  
    let photoAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getObjectByPosition(expectIndex);  
    phAccessHelper.getPhotoIndex(photoAsset.uri, album.albumUri, fetchOptions).then((index) => {  
      console.info(`getPhotoIndex successfully and index is : ${index}`);  
    }).catch((err: BusinessError) => {  
      console.info(`getPhotoIndex failed; error: ${err}`);  
    });  
  } catch (error) {  
    console.info(`getPhotoIndex failed; error: ${error}`);  
  }  
}  
    
```    
  
