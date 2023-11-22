# @ohos.file.photoAccessHelper    
该模块提供相册管理模块能力，包括创建相册以及访问、修改相册中的媒体数据信息等。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import photoAccessHelper from '@ohos.file.photoAccessHelper'    
```  
    
## getPhotoAccessHelper    
获取相册管理模块模块的实例，用于访问和修改相册中的媒体文件。  
 **调用形式：**     
- getPhotoAccessHelper(context: Context): PhotoAccessHelper  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | Context | true | 传入Ability实例的Context。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PhotoAccessHelper | 相册管理模块模块的实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
    
 **示例代码：**   
```ts    
//此处获取的phAccessHelper实例为全局对象，后续使用到phAccessHelper的地方默认为使用此处获取的对象，如未添加此段代码报phAccessHelper未定义的错误请自行添加  
const context = getContext(this);  
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);    
```    
  
    
## PhotoType    
枚举，媒体文件类型。    
    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| IMAGE | 1 | 图片。 |  
| VIDEO | 2 | 视频。 |  
    
## MemberType    
成员类型。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| number | number类型。 |  
| string | string类型。 |  
| boolean | boolean类型。 |  
    
## PhotoAsset    
提供封装文件属性的方法。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri | string | true | true | 媒体文件资源uri（如：file://media/Photo/1/IMG_datetime_0001/displayName.jpg），详情参见用户文件uri介绍中的[媒体文件uri](../../file-management/user-file-uri-intro.md#媒体文件uri)。 |  
| photoType | PhotoType | true | true | 媒体文件类型 |  
| displayName | string | true | true | 显示文件名，包含后缀名。 |  
    
### get    
获取PhotoAsset成员参数。  
 **调用形式：**     
- get(member: string): MemberType  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| member | string | true | 成员参数名称，在get时，除了uri、photoType和displayName三个属性之外，其他的属性都需要在fetchColumns中填入需要get的[PhotoKeys](#photokeys)，例如：get title属性fetchColumns: ['title']。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| MemberType | 获取PhotoAsset成员参数的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900020 | Invalid argument. |  
| 14000014 | Member is not a valid PhotoKey. |  
    
 **示例代码：**   
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('photoAssetGetDemo');  
  try {  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: photoAccessHelper.FetchOptions = {  
      fetchColumns: ['title'],  
      predicates: predicates  
    };  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    let title: photoAccessHelper.PhotoKeys = photoAccessHelper.PhotoKeys.TITLE;  
    let photoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title.toString());  
    console.info('photoAsset Get photoAssetTitle = ', photoAssetTitle);  
  } catch (err) {  
    console.error('release failed. message = ', err);  
  }  
}  
    
```    
  
    
### set    
设置PhotoAsset成员参数。  
  
 **调用形式：**     
- set(member: string, value: string): void  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| member | string | true | 成员参数名称例如：[PhotoKeys](#photokeys).TITLE。 |  
| value | string | true | 设置成员参数名称，只能修改[PhotoKeys](#photokeys).TITLE的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900020 | Invalid argument. |  
| 14000014 | Member is not a valid PhotoKey. |  
    
 **示例代码：**   
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('photoAssetSetDemo');  
  try {  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: photoAccessHelper.FetchOptions = {  
      fetchColumns: ['title'],  
      predicates: predicates  
    };  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    let title: string = photoAccessHelper.PhotoKeys.TITLE.toString();  
    photoAsset.set(title, 'newTitle');  
  } catch (err) {  
    console.error('release failed. message = ', err);  
  }  
}  
    
```    
  
    
### commitModify    
修改文件的元数据。  
 **调用形式：**     
    
- commitModify(callback: AsyncCallback\<void>): void    
起始版本： 10    
- commitModify(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000001 | Invalid display name. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('commitModifyDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: ['title'],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
  let title: string = photoAccessHelper.PhotoKeys.TITLE.toString();  
  let photoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title);  
  console.info('photoAsset get photoAssetTitle = ', photoAssetTitle);  
  photoAsset.set(title, 'newTitle2');  
  photoAsset.commitModify((err) => {  
    if (err == undefined) {  
      let newPhotoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title);  
      console.info('photoAsset get newPhotoAssetTitle = ', newPhotoAssetTitle);  
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
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: ['title'],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
  let title: string = photoAccessHelper.PhotoKeys.TITLE.toString();  
  let photoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title);  
  console.info('photoAsset get photoAssetTitle = ', photoAssetTitle);  
  photoAsset.set(title, 'newTitle3');  
  try {  
    await photoAsset.commitModify();  
    let newPhotoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title);  
    console.info('photoAsset get newPhotoAssetTitle = ', newPhotoAssetTitle);  
  } catch (err) {  
    console.error('release failed. message = ', err);  
  }  
}  
    
```    
  
    
### getReadOnlyFd    
以只读方式打开当前文件。  
 **调用形式：**     
    
- getReadOnlyFd(callback: AsyncCallback\<number>): void    
起始版本： 10    
- getReadOnlyFd(): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回文件描述符。 |  
| Promise<number> | Promise对象，返回文件描述符。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
async function example() {  
  console.info('getReadOnlyFdDemo');  
   let testFileName: string = 'testFile' + Date.now() + '.jpg';  
  const photoAsset: photoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(testFileName);  
  photoAsset.getReadOnlyFd((err, fd) => {  
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
  console.info('getReadOnlyFdDemo');  
  try {  
    let testFileName: string = 'testFile' + Date.now() + '.jpg';  
    const photoAsset: photoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(testFileName);  
    let fd: number = await photoAsset.getReadOnlyFd();  
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
  
    
### close    
关闭当前文件。  
 **调用形式：**     
    
- close(fd: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- close(fd: number): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd | number | true | 文件描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('closeDemo');  
  try {  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: photoAccessHelper.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
    const photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    let fd: number = await photoAsset.open('rw');  
    console.info('file fd', fd);  
    photoAsset.close(fd, (err) => {  
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
    let fetchOption: photoAccessHelper.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
    const asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    let fd = await asset.open('rw');  
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
起始版本： 10    
- getThumbnail(size: image.Size, callback: AsyncCallback\<image.PixelMap>): void    
起始版本： 10    
- getThumbnail(size?: image.Size): Promise\<image.PixelMap>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size | image.Size | true | 缩略图尺寸。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回缩略图的PixelMap。 |  
| Promise<image.PixelMap> | Promise对象，返回缩略图的PixelMap。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import image from '@ohos.multimedia.image'  
  
async function example() {  
  console.info('getThumbnailDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let size: image.Size = { width: 720, height: 720 };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  const asset = await fetchResult.getFirstObject();  
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
import image from '@ohos.multimedia.image'  
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  console.info('getThumbnailDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let size: image.Size = { width: 720, height: 720 };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  const asset = await fetchResult.getFirstObject();  
  console.info('asset displayName = ', asset.displayName);  
  asset.getThumbnail(size).then((pixelMap) => {  
    console.info('getThumbnail successful ' + pixelMap);  
  }).catch((err: BusinessError) => {  
    console.error('getThumbnail fail' + err);  
  });  
}  
    
```    
  
    
## PhotoKeys    
枚举，图片和视频文件关键信息。    
    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| URI | uri | 文件uri。 |  
| PHOTO_TYPE | media_type | 媒体文件类型。 |  
| DISPLAY_NAME | display_name | 显示名字。 |  
| SIZE | size | 文件大小。 |  
| DATE_ADDED | date_added | 添加日期（添加文件时间距1970年1月1日的秒数值）。 |  
| DATE_MODIFIED | date_modified | 修改日期（修改文件时间距1970年1月1日的秒数值，修改文件名不会改变此值，当文件内容发生修改时才会更新）。 |  
| DURATION | duration | 持续时间（单位：毫秒）。 |  
| WIDTH | width | 图片宽度（单位：像素）。 |  
| HEIGHT | height | 图片高度（单位：像素）。 |  
| DATE_TAKEN | date_taken | 图片高度（单位：像素）。 |  
| ORIENTATION | orientation | 图片文件的方向。 |  
| FAVORITE | is_favorite | 收藏。 |  
| TITLE | title | 文件标题。 |  
    
## AlbumKeys    
枚举，相册关键信息。    
    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| URI | uri | 相册uri。 |  
| ALBUM_NAME | album_name | 相册名字。 |  
    
## FetchOptions    
检索条件。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| fetchColumns | Array<string> | false | true | 检索条件，指定列名查询，如果该参数为空时默认查询uri、name、photoType（具体字段名称以检索对象定义为准）且使用[get](#get)接口去获取当前对象的其他属性时将会报错。示例：<br />fetchColumns: ['uri', 'title']。 |  
| predicates | dataSharePredicates.DataSharePredicates | false | true | 谓词查询，显示过滤条件。 |  
    
## CreateOptions    
图片或视频的创建选项。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| title | string | false | false | 图片或者视频的标题。 |  
    
## FetchResult    
文件检索结果集。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
### getCount    
获取文件检索结果中的文件总数。  
 **调用形式：**     
- getCount(): number  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 检索到的文件总数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码：**   
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getCountDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  const fetchCount = fetchResult.getCount();  
  console.info('fetchCount = ', fetchCount);  
}    
```    
  
    
### isAfterLast    
检查结果集是否指向最后一行。  
 **调用形式：**     
- isAfterLast(): boolean  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 当读到最后一条记录后，后续没有记录返回true，否则返回false |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码：**   
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  const fetchCount = fetchResult.getCount();  
  console.info('count:' + fetchCount);  
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getLastObject();  
  if (fetchResult.isAfterLast()) {  
    console.info('photoAsset isAfterLast displayName = ', photoAsset.displayName);  
  } else {  
    console.info('photoAsset  not isAfterLast ');  
  }  
}  
    
```    
  
    
### getFirstObject    
获取文件检索结果中的第一个文件资产。  
 **调用形式：**     
    
- getFirstObject(callback: AsyncCallback\<T>): void    
起始版本： 10    
- getFirstObject(): Promise\<T>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步获取结果集中的第一个完成后的回调。 |  
| Promise<T> | Promise对象，返回结果集中第一个对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getFirstObjectDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  fetchResult.getFirstObject((err, photoAsset) => {  
    if (photoAsset != undefined) {  
      console.info('photoAsset displayName: ', photoAsset.displayName);  
    } else {  
      console.error('photoAsset failed with err:' + err);  
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
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
  console.info('photoAsset displayName: ', photoAsset.displayName);  
}    
```    
  
    
### getNextObject    
获取文件检索结果中的下一个文件资产。 在调用此方法之前，必须使用[isAfterLast()](#isafterlast)来检查当前位置是否为最后一行  
 **调用形式：**     
    
- getNextObject(callback: AsyncCallback\<T>): void    
起始版本： 10    
- getNextObject(): Promise\<T>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步返回结果集中下一个之后的回调。 |  
| Promise<T> | Promise对象，返回结果集中下一个对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getNextObjectDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  await fetchResult.getFirstObject();  
  if (!fetchResult.isAfterLast()) {  
    fetchResult.getNextObject((err, photoAsset) => {  
      if (photoAsset != undefined) {  
        console.info('photoAsset displayName: ', photoAsset.displayName);  
      } else {  
        console.error('photoAsset failed with err: ' + err);  
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
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  await fetchResult.getFirstObject();  
  if (!fetchResult.isAfterLast()) {  
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getNextObject();  
    console.info('photoAsset displayName: ', photoAsset.displayName);  
  }  
}    
```    
  
    
### getLastObject    
获取文件检索结果中的最后一个文件资产。  
 **调用形式：**     
    
- getLastObject(callback: AsyncCallback\<T>): void    
起始版本： 10    
- getLastObject(): Promise\<T>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步返回结果集中最后一个的回调。 |  
| Promise<T> | Promise对象，返回结果集中最后一个对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getLastObjectDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  fetchResult.getLastObject((err, photoAsset) => {  
    if (photoAsset != undefined) {  
      console.info('photoAsset displayName: ', photoAsset.displayName);  
    } else {  
      console.error('photoAsset failed with err: ' + err);  
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
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getLastObject();  
  console.info('photoAsset displayName: ', photoAsset.displayName);  
}    
```    
  
    
### getObjectByPosition    
获取文件检索结果中具有指定索引的文件资产。  
 **调用形式：**     
    
- getObjectByPosition(index: number, callback: AsyncCallback\<T>): void    
起始版本： 10    
- getObjectByPosition(index: number): Promise\<T>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
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
| 401 | if parameter is invalid. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getObjectByPositionDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  fetchResult.getObjectByPosition(0, (err, photoAsset) => {  
    if (photoAsset != undefined) {  
      console.info('photoAsset displayName: ', photoAsset.displayName);  
    } else {  
      console.error('photoAsset failed with err: ' + err);  
    }  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getObjectByPositionDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getObjectByPosition(0);  
  console.info('photoAsset displayName: ', photoAsset.displayName);  
}    
```    
  
    
### getAllObjects    
获取文件检索结果中的所有文件资产。  
 **调用形式：**     
    
- getAllObjects(callback: AsyncCallback\<Array\<T>>): void    
起始版本： 10    
- getAllObjects(): Promise\<Array\<T>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步获取结果集中的所有文件资产完成后的回调。 |  
| Promise<Array<T>> | Promise对象，返回结果集中所有文件资产数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getAllObjectDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  fetchResult.getAllObjects((err, photoAssetList) => {  
    if (photoAssetList != undefined) {  
      console.info('photoAssetList length: ', photoAssetList.length);  
    } else {  
      console.error('photoAssetList failed with err:' + err);  
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
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
  let photoAssetList: Array<photoAccessHelper.PhotoAsset> = await fetchResult.getAllObjects();  
  console.info('photoAssetList length: ', photoAssetList.length);  
}    
```    
  
    
### close    
释放FetchResult实例并使其失效。无法调用其他方法。  
 **调用形式：**     
- close(): void  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码：**   
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('fetchResultCloseDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOption: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  try {  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
    fetchResult.close();  
    console.info('close succeed.');  
  } catch (err) {  
    console.error('close fail. message = ' + err);  
  }  
}  
    
```    
  
    
## AlbumType    
枚举，相册类型，表示是用户相册还是系统预置相册。    
    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| USER | 0 | 用户相册。 |  
| SYSTEM | 1024 | 系统预置相册。 |  
    
## AlbumSubtype    
枚举，相册子类型，表示具体的相册类型。    
    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| USER_GENERIC | 1 | 用户相册。 |  
| FAVORITE | 1025 | 收藏夹。 |  
| VIDEO | 1026 | 视频相册。 |  
| ANY | 2147483647 | 任意相册。 |  
    
## AbsAlbum    
  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| albumType | AlbumType | true | true | <br/> |  
| albumSubtype | AlbumSubtype | true | true | <br/> |  
| albumName | string | false | true | <br/> |  
| albumUri | string | true | true | <br/> |  
| count | number | true | true | <br/> |  
| coverUri | string | true | true | <br/> |  
    
### getAssets  
 **调用形式：**     
    
- getAssets(options: FetchOptions, callback: AsyncCallback\<FetchResult\<PhotoAsset>>): void    
起始版本： 10    
- getAssets(options: FetchOptions): Promise\<FetchResult\<PhotoAsset>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | FetchOptions | true | <br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<FetchResult<PhotoAsset>> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 13900012 |  |  
| 13900020 |  |  
| 14000011 |  |  
    
## Album    
实体相册  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
### commitModify    
更新相册属性修改到数据库中。  
 **调用形式：**     
    
- commitModify(callback: AsyncCallback\<void>): void    
起始版本： 10    
- commitModify(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('albumCommitModifyDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let albumFetchOptions: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  const albumList: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);  
  const album: photoAccessHelper.Album = await albumList.getFirstObject();  
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
  let albumFetchOptions: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  const albumList: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);  
  const album: photoAccessHelper.Album = await albumList.getFirstObject();  
  album.albumName = 'hello';  
  album.commitModify().then(() => {  
    console.info('commitModify successfully');  
  }).catch((err: BusinessError) => {  
    console.error('commitModify failed with error: ' + err);  
  });  
}  
    
```    
  
    
### addAssets    
往相册中添加图片或者视频，需要先预置相册和文件资源。  
 **调用形式：**     
    
- addAssets(assets: Array\<PhotoAsset>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- addAssets(assets: Array\<PhotoAsset>): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| assets | Array<PhotoAsset> | true | 待添加到相册中的图片或视频数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
    console.info('addAssetsDemoCallback');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: photoAccessHelper.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);  
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    album.addAssets([asset], (err) => {  
      if (err === undefined) {  
        console.info('album addAssets successfully');  
      } else {  
        console.error('album addAssets failed with error: ' + err);  
      }  
    });  
  } catch (err) {  
    console.error('addAssetsDemoCallback failed with error: ' + err);  
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
    console.info('addAssetsDemoPromise');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: photoAccessHelper.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);  
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);  
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    album.addAssets([asset]).then(() => {  
      console.info('album addAssets successfully');  
    }).catch((err: BusinessError) => {  
      console.error('album addAssets failed with error: ' + err);  
    });  
  } catch (err) {  
    console.error('addAssetsDemoPromise failed with error: ' + err);  
  }  
}  
    
```    
  
    
### removeAssets    
从相册中移除图片或者视频，需要先预置相册和文件资源。  
 **调用形式：**     
    
- removeAssets(assets: Array\<PhotoAsset>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- removeAssets(assets: Array\<PhotoAsset>): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| assets | Array<PhotoAsset> | true | 相册中待移除的图片或视频数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
    console.info('removeAssetsDemoCallback');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: photoAccessHelper.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);  
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);  
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    album.removeAssets([asset], (err) => {  
      if (err === undefined) {  
        console.info('album removeAssets successfully');  
      } else {  
        console.error('album removeAssets failed with error: ' + err);  
      }  
    });  
  } catch (err) {  
    console.error('removeAssetsDemoCallback failed with error: ' + err);  
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
    console.info('removeAssetsDemoPromise');  
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
    let fetchOption: photoAccessHelper.FetchOptions = {  
      fetchColumns: [],  
      predicates: predicates  
    };  
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);  
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);  
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
    album.removeAssets([asset]).then(() => {  
      console.info('album removeAssets successfully');  
    }).catch((err: BusinessError) => {  
      console.error('album removeAssets failed with error: ' + err);  
    });  
  } catch (err) {  
    console.error('removeAssetsDemoPromise failed with error: ' + err);  
  }  
}  
    
```    
  
    
## PhotoAccessHelper  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
### getAssets    
获取图片和视频资源。  
 **调用形式：**     
    
- getAssets(options: FetchOptions, callback: AsyncCallback\<FetchResult\<PhotoAsset>>): void    
起始版本： 10    
- getAssets(options: FetchOptions): Promise\<FetchResult\<PhotoAsset>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | FetchOptions | true | 图片和视频检索选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回图片和视频检索结果集。 |  
| Promise<FetchResult<PhotoAsset>> | Promise对象，返回图片和视频数据结果集。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('getAssets');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOptions: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  
  phAccessHelper.getAssets(fetchOptions, async (err, fetchResult) => {  
    if (fetchResult != undefined) {  
      console.info('fetchResult success');  
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
      if (photoAsset != undefined) {  
        console.info('photoAsset.displayName : ' + photoAsset.displayName);  
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
  console.info('getAssets');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOptions: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  try {  
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);  
    if (fetchResult != undefined) {  
      console.info('fetchResult success');  
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
      if (photoAsset != undefined) {  
        console.info('photoAsset.displayName :' + photoAsset.displayName);  
      }  
    }  
  } catch (err) {  
    console.error('getAssets failed, message = ', err);  
  }  
}  
    
```    
  
    
### createAsset    
指定待创建的文件类型和后缀，创建图片或视频资源。  
 **调用形式：**     
    
- createAsset(photoType: PhotoType, extension: string, options: CreateOptions, callback: AsyncCallback\<string>): void    
起始版本： 10    
- createAsset(photoType: PhotoType, extension: string, callback: AsyncCallback\<string>): void    
起始版本： 10    
- createAsset(photoType: PhotoType, extension: string, options?: CreateOptions): Promise\<string>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| photoType | PhotoType | true | 创建的文件类型，IMAGE或者VIDEO类型。 |  
| extension | string | true | 文件名后缀参数，例如：'jpg'。 |  
| options | CreateOptions | true | 创建选项，例如{title: 'testPhoto'}。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回创建的图片和视频的uri。 |  
| Promise<string> | Promise对象，返回创建的图片和视频的uri。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
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
  
    
### getAlbums    
根据检索选项和相册类型获取相册。  获取相册前需先保证相册存在。  
 **调用形式：**     
    
- getAlbums(       type: AlbumType,       subtype: AlbumSubtype,       options: FetchOptions,       callback: AsyncCallback\<FetchResult\<Album>>     ): void    
起始版本： 10    
- getAlbums(type: AlbumType, subtype: AlbumSubtype, callback: AsyncCallback\<FetchResult\<Album>>): void    
起始版本： 10    
- getAlbums(type: AlbumType, subtype: AlbumSubtype, options?: FetchOptions): Promise\<FetchResult\<Album>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.READ_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | AlbumType | true | 相册类型。 |  
| subtype | AlbumSubtype | true | 相册子类型。 |  
| options | FetchOptions | true | 检索选项，不填时默认根据相册类型检索。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回获取相册的结果集。 |  
| Promise<FetchResult<Album>> | Promise对象，返回获取相册的结果集。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  // 示例代码中为获取相册名为newAlbumName的相册。  
  console.info('getAlbumsDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  predicates.equalTo('album_name', 'newAlbumName');  
  let fetchOptions: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions, async (err, fetchResult) => {  
    if (err) {  
      console.error('getAlbumsCallback failed with err: ' + err);  
      return;  
    }  
    if (fetchResult == undefined) {  
      console.error('getAlbumsCallback fetchResult is undefined');  
      return;  
    }  
    let album = await fetchResult.getFirstObject();  
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
  let fetchOptions: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions).then( async (fetchResult) => {  
    if (fetchResult == undefined) {  
      console.error('getAlbumsPromise fetchResult is undefined');  
      return;  
    }  
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();  
    console.info('getAlbumsPromise successfully, albumName: ' + album.albumName);  
    fetchResult.close();  
  }).catch((err: BusinessError) => {  
    console.error('getAlbumsPromise failed with err: ' + err);  
  });  
}  
    
```    
  
    
### registerChange    
注册对指定uri的监听。  
 **调用形式：**     
    
- registerChange(uri: string, forChildUris: boolean, callback: Callback\<ChangeData>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | PhotoAsset的uri, Album的uri或[DefaultChangeUri](#defaultchangeuri)的值。 |  
| forChildUris | boolean | true | 是否模糊监听，uri为相册uri时，forChildUris为true能监听到相册中文件的变化，如果是false只能监听相册本身变化。uri为photoAsset时，forChildUris为true、false没有区别，uri为DefaultChangeUri时，forChildUris必须为true，如果为false将找不到该uri，收不到任何消息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回要监听的[ChangeData](#changedata)。注：uri可以注册多个不同的callback监听，[unRegisterChange](#unregisterchange)可以关闭该uri所有监听，也可以关闭指定callback的监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('registerChangeDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOptions: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);  
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
  if (photoAsset != undefined) {  
    console.info('photoAsset.displayName : ' + photoAsset.displayName);  
  }  
  let onCallback1 = (changeData: photoAccessHelper.ChangeData) => {  
      console.info('onCallback1 success, changData: ' + JSON.stringify(changeData));  
    //file had changed, do something  
  }  
  let onCallback2 = (changeData: photoAccessHelper.ChangeData) => {  
      console.info('onCallback2 success, changData: ' + JSON.stringify(changeData));  
    //file had changed, do something  
  }  
  // 注册onCallback1监听  
  phAccessHelper.registerChange(photoAsset.uri, false, onCallback1);  
  // 注册onCallback2监听  
  phAccessHelper.registerChange(photoAsset.uri, false, onCallback2);  
  
  photoAsset.setFavorite(true, (err) => {  
    if (err == undefined) {  
      console.info('setFavorite successfully');  
    } else {  
      console.error('setFavorite failed with error:' + err);  
    }  
  });  
}  
    
```    
  
    
### unRegisterChange    
取消指定uri的监听，一个uri可以注册多个监听，存在多个callback监听时，可以取消指定注册的callback的监听；不指定callback时取消该uri的所有监听。  
 **调用形式：**     
    
- unRegisterChange(uri: string, callback?: Callback\<ChangeData>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | PhotoAsset的uri, Album的uri或[DefaultChangeUri](#defaultchangeuri)的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消[registerChange](#registerchange)注册时的callback的监听，不填时，取消该uri的所有监听。注：off指定注册的callback后不会进入此回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('offDemo');  
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();  
  let fetchOptions: photoAccessHelper.FetchOptions = {  
    fetchColumns: [],  
    predicates: predicates  
  };  
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);  
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();  
  if (photoAsset != undefined) {  
    console.info('photoAsset.displayName : ' + photoAsset.displayName);  
  }  
  let onCallback1 = (changeData: photoAccessHelper.ChangeData) => {  
    console.info('onCallback1 on');  
  }  
  let onCallback2 = (changeData: photoAccessHelper.ChangeData) => {  
    console.info('onCallback2 on');  
  }  
  // 注册onCallback1监听  
  phAccessHelper.registerChange(photoAsset.uri, false, onCallback1);  
  // 注册onCallback2监听  
  phAccessHelper.registerChange(photoAsset.uri, false, onCallback2);  
  // 关闭onCallback1监听，onCallback2 继续监听  
  phAccessHelper.unRegisterChange(photoAsset.uri, onCallback1);  
  photoAsset.setFavorite(true, (err) => {  
    if (err == undefined) {  
      console.info('setFavorite successfully');  
    } else {  
      console.error('setFavorite failed with error:' + err);  
    }  
  });  
}  
    
```    
  
    
### createDeleteRequest    
创建一个弹出框来删除照片，删除的文件进入到回收站。  
 **调用形式：**     
    
- createDeleteRequest(uriList: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- createDeleteRequest(uriList: Array\<string>): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core  
 **需要权限：** ohos.permission.WRITE_IMAGEVIDEO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uriList | Array<string> | true | 待删除的媒体文件uri数组，最大删除数量300。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback返回void。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900012 | Permission denied. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
async function example() {  
  console.info('createDeleteRequestDemo');  
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
    phAccessHelper.createDeleteRequest([asset.uri], (err) => {  
      if (err == undefined) {  
        console.info('createDeleteRequest successfully');  
      } else {  
        console.error('createDeleteRequest failed with error: ' + err);  
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
  console.info('createDeleteRequestDemo');  
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
    await phAccessHelper.createDeleteRequest([asset.uri]);  
    console.info('createDeleteRequest successfully');  
  } catch (err) {  
    console.error('createDeleteRequest failed with error: ' + err);  
  }  
}  
    
```    
  
    
### release    
释放PhotoAccessHelper实例。 当后续不需要使用PhotoAccessHelper 实例中的方法时调用。  
 **调用形式：**     
    
- release(callback: AsyncCallback\<void>): void    
起始版本： 10    
- release(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调表示成功还是失败。 |  
| Promise<void> | Promise对象，返回void。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900020 | Invalid argument. |  
| 14000011 | System inner fail. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
async function example() {  
  console.info('releaseDemo');  
  phAccessHelper.release((err) => {  
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
    await phAccessHelper.release();  
    console.info('release ok.');  
  } catch (err) {  
    console.error('release failed. message = ', err);  
  }  
}  
    
```    
  
    
## NotifyType    
枚举，通知事件的类型。    
    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NOTIFY_ADD | 0 | 添加文件集或相册通知的类型。 |  
| NOTIFY_UPDATE | 1 | 文件集或相册的更新通知类型。 |  
| NOTIFY_REMOVE | 2 | 删除文件集或相册的通知类型。 |  
| NOTIFY_ALBUM_ADD_ASSET | 3 | 在相册中添加的文件集的通知类型。 |  
| NOTIFY_ALBUM_REMOVE_ASSET | 4 | 在相册中删除的文件集的通知类型。 |  
    
## DefaultChangeUri    
枚举，DefaultChangeUri子类型。    
    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEFAULT_PHOTO_URI | file://media/Photo | 默认PhotoAsset的Uri，与forSubUri{true}一起使用，将接收所有PhotoAsset的更改通知。 |  
| DEFAULT_ALBUM_URI | file://media/PhotoAlbum | 默认相册的Uri，与forSubUri{true}一起使用，将接收所有相册的更改通知。 |  
    
## ChangeData    
监听器回调函数的值。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | NotifyType | false | true | ChangeData的通知类型。 |  
| uris | Array<string> | false | true | 相同[NotifyType](#notifytype)的所有uri，可以是PhotoAsset或Album。 |  
| extraUris | Array<string> | false | true | 相册中变动文件的uri数组。 |  
    
## PhotoViewMIMETypes    
枚举，可选择的媒体文件类型。    
    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| IMAGE_TYPE | image/* | 图片类型。 |  
| VIDEO_TYPE | video/* | 视频类型。 |  
| IMAGE_VIDEO_TYPE | */* | 图片和视频类型。 |  
    
## PhotoSelectOptions    
图库选择选项。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| MIMEType | PhotoViewMIMETypes | false | false | 可选择的媒体文件类型，若无此参数，则默认为图片和视频类型。 |  
| maxSelectNumber | number | false | false | 选择媒体文件数量的最大值(默认值为50，最大值为500)。 |  
    
## PhotoSelectResult    
返回图库选择后的结果集。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| photoUris | Array<string> | false | true | 返回图库选择后的媒体文件的uri数组，此uri数组只能通过临时授权的方式调用[photoAccessHelper.getAssets接口](#getassets)去使用，具体使用方式参见用户文件uri介绍中的[媒体文件uri的使用方式](../../file-management/user-file-uri-intro.md#媒体文件uri的使用方式)。 |  
| isOriginalPhoto | boolean | false | true | 返回图库选择后的媒体文件是否为原图。 |  
    
## PhotoViewPicker    
图库选择器对象，用来支撑选择图片/视频和等用户场景。在使用前，需要先创建PhotoViewPicker实例。  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
### select    
通过选择模式拉起photoPicker界面，用户可以选择一个或多个图片/视频。传入可选参数PhotoSelectOptions对象，返回PhotoSelectResult对象。  
 **调用形式：**     
    
- select(option?: PhotoSelectOptions): Promise\<PhotoSelectResult>    
起始版本： 10    
- select(option: PhotoSelectOptions, callback: AsyncCallback\<PhotoSelectResult>): void    
起始版本： 10    
- select(callback: AsyncCallback\<PhotoSelectResult>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.FileManagement.PhotoAccessHelper.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| option | PhotoSelectOptions | false | photoPicker选择选项，若无此参数，则默认选择媒体文件类型为图片和视频类型，选择媒体文件数量的最大值为50 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback 返回photoPicker选择后的结果集 |  
| Promise<PhotoSelectResult> | Promise对象。返回photoPicker选择后的结果集 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | if parameter is invalid. |  
| 13900042 | Unknown error. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function example02() {  
  try {  
    let PhotoSelectOptions = new photoAccessHelper.PhotoSelectOptions();  
    PhotoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_TYPE;  
    PhotoSelectOptions.maxSelectNumber = 5;  
    let photoPicker = new photoAccessHelper.PhotoViewPicker();  
    photoPicker.select(PhotoSelectOptions, (err: BusinessError, PhotoSelectResult: photoAccessHelper.PhotoSelectResult) => {  
      if (err) {  
        console.error('PhotoViewPicker.select failed with err: ' + JSON.stringify(err));  
        return;  
      }  
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));  
    });  
  } catch (error) {  
    let err: BusinessError = error as BusinessError;  
    console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function example01() {  
  try {    
    let PhotoSelectOptions = new photoAccessHelper.PhotoSelectOptions();  
    PhotoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_TYPE;  
    PhotoSelectOptions.maxSelectNumber = 5;  
    let photoPicker = new photoAccessHelper.PhotoViewPicker();  
    photoPicker.select(PhotoSelectOptions).then((PhotoSelectResult: photoAccessHelper.PhotoSelectResult) => {  
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));  
    }).catch((err: BusinessError) => {  
      console.error('PhotoViewPicker.select failed with err: ' + JSON.stringify(err));  
    });  
  } catch (error) {  
    let err: BusinessError = error as BusinessError;  
    console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));  
  }  
}  
    
```    
  
