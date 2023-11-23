# @ohos.multimedia.mediaLibrary    
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import mediaLibrary from '@ohos.multimedia.mediaLibrary'    
```  
    
## getMediaLibrary<sup>(deprecated)</sup>    
获取媒体库的实例，用于访问和修改用户等个人媒体数据信息（如音频、视频、图片、文档等）。  
 **调用形式：**     
- getMediaLibrary(): MediaLibrary  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| MediaLibrary | 媒体库实例。 |  
    
 **示例代码：**   
```ts    
// 获取mediaLibrary实例，后续用到此实例均采用此处获取的实例。  
const context = getContext(this);  
let media: mediaLibrary.MediaLibrary = mediaLibrary.getMediaLibrary(context);    
```    
  
    
## getMediaLibrary<sup>(deprecated)</sup>    
获取媒体库的实例，用于访问和修改用户等个人媒体数据信息（如音频、视频、图片、文档等）。  
 **调用形式：**     
- getMediaLibrary(context: Context): MediaLibrary  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context<sup>(deprecated)</sup> | Context | true | 传入Ability实例的Context。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| MediaLibrary | 媒体库实例。 |  
    
 **示例代码：**   
```ts    
let media: mediaLibrary.MediaLibrary = mediaLibrary.getMediaLibrary();    
```    
  
    
## MediaType<sup>(deprecated)</sup>    
枚举，媒体类型。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。    
    
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FILE<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>文件。 |  
| IMAGE<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>图片。 |  
| VIDEO<sup>(deprecated)</sup> | 2 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>视频。 |  
| AUDIO<sup>(deprecated)</sup> | 3 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>音频。 |  
    
 **示例代码：**   
    
## MediaAssetOption<sup>(deprecated)</sup>    
媒体资源选项。    
从API version 6 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| src<sup>(deprecated)</sup> | string | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>本地文件应用沙箱路径。 |  
| mimeType<sup>(deprecated)</sup> | string | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>媒体MIME（MultipurposeInternetMailExtensions）类型。<br/>包括：'image/\*'、'video/\*'、'audio/\*'、 'file\*'。 |  
| relativePath<sup>(deprecated)</sup> | string | false | false | 从API version 6 开始支持，从API version 9 开始废弃。<br>自定义媒体资源保存位置，例：Pictures/ 不填则保存到默认路径。 <br/> image类型默认路径Pictures/ <br/> video类型默认路径Videos/ <br/> audio类型默认路径Audios/ <br/> file类型默认路径Documents/ 。 |  
    
## MediaSelectOption<sup>(deprecated)</sup>    
媒体资源类型选项。    
从API version 6 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | 'image' \| 'video' \| 'media' | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>媒体类型，包括：image, video, media，当前仅支持media类型。 |  
| count<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>可以选择媒体数量的最大值，count = 1表示单选，count大于1表示多选。 |  
    
## FileAsset<sup>(deprecated)</sup>    
提供封装文件属性的方法。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>文件资源编号。 |  
| uri<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>文件资源uri（如：file://media/image/2)。 |  
| mimeType<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>文件扩展属性。 |  
| mediaType<sup>(deprecated)</sup> | MediaType | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>媒体类型。 |  
| displayName<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>显示文件名，包含后缀名。 |  
| title<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>文件标题。 |  
| relativePath<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>相对公共目录路径。 |  
| parent<sup>(deprecated)</sup> | number | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>父目录id。由于API version 10的SDK上Asset可以存在多个相册，该属性不兼容。获取值始终为0。 |  
| size<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>文件大小（单位：字节）。 |  
| dateAdded<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>添加日期（添加文件时间到1970年1月1日的秒数值）。 |  
| dateModified<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>修改日期（修改文件时间到1970年1月1日的秒数值，修改文件名不会改变此值，当文件内容发生修改时才会更新）。 |  
| dateTaken<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>拍摄日期（文件拍照时间到1970年1月1日的秒数值）。 |  
| artist<sup>(deprecated)</sup> | string | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>作者。 |  
| audioAlbum<sup>(deprecated)</sup> | string | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>专辑。 |  
| width<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>图片宽度（单位：像素）。 |  
| height<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>图片高度（单位：像素）。 |  
| orientation<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>图片显示方向（顺时针旋转角度，如0，90，180  单位：度）。 |  
| duration<sup>(deprecated)</sup> | number | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>持续时间（单位：毫秒）。 |  
| albumId<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>文件所归属的相册编号。由于API version 10的SDK上Asset可以存在多个相册，该属性不兼容。获取值始终为0。 |  
| albumUri<sup>(deprecated)</sup> | string | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>文件所归属相册uri。由于API version 10的SDK上Asset可以存在多个相册，该属性不兼容。获取值始终为空字符串。 |  
| albumName<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>文件所归属相册名称。由于API version 10的SDK上Asset可以存在多个相册，该属性不兼容。获取值始终为空字符串。 |  
    
### isDirectory<sup>(deprecated)</sup>    
判断fileAsset是否为目录，使用callback方式返回异步结果。  
 **调用形式：**     
- isDirectory(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | callback返回boolean值，值为true则是目录，值为false则非目录。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  const fetchFileResult = await media.getFileAssets(getImageOp);  
  const asset = await fetchFileResult.getFirstObject();  
  asset.isDirectory((error, isDirectory) => {  
    if (error) {  
      console.error('isDirectory failed with error: ' + error);  
    } else {  
      console.info('isDirectory result:' + isDirectory);  
    }  
  });  
  fetchFileResult.close();  
}  
    
```    
  
    
### isDirectory<sup>(deprecated)</sup>    
判断fileAsset是否为目录，使用callback方式返回异步结果。  
 **调用形式：**     
- isDirectory(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象，返回boolean值，值为true则是目录，值为false则非目录。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  const fetchFileResult = await media.getFileAssets(getImageOp);  
  const asset = await fetchFileResult.getFirstObject();  
  asset.isDirectory().then((isDirectory) => {  
    console.info('isDirectory result:' + isDirectory);  
  }).catch((error: BusinessError) => {  
    console.error('isDirectory failed with error: ' + error);  
  });  
  fetchFileResult.close();  
}  
    
```    
  
    
### commitModify<sup>(deprecated)</sup>    
修改文件的元数据，使用callback方式返回异步结果。  
 **调用形式：**     
- commitModify(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | callback返回空。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  const fetchFileResult = await media.getFileAssets(getImageOp);  
  const asset = await fetchFileResult.getFirstObject();  
  asset.title = 'newtitle';  
  asset.commitModify(() => {  
    console.info('commitModify successfully');  
  });  
  fetchFileResult.close();  
}    
```    
  
    
### commitModify<sup>(deprecated)</sup>    
修改文件的元数据，使用callback方式返回异步结果。  
 **调用形式：**     
- commitModify(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象，返回空。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  const fetchFileResult = await media.getFileAssets(getImageOp);  
  const asset = await fetchFileResult.getFirstObject();  
  asset.title = 'newtitle';  
  await asset.commitModify();  
  fetchFileResult.close();  
}    
```    
  
    
### open<sup>(deprecated)</sup>    
打开当前文件，使用callback方式返回异步结果。  
 **调用形式：**     
- open(mode: string, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA or ohos.permission.WRITE_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode<sup>(deprecated)</sup> | string | true | 打开文件方式，如：'r'（只读）, 'w'（只写）, 'rw'（读写）。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | callback返回文件描述符。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  let mediaType = mediaLibrary.MediaType.IMAGE;  
  let DIR_IMAGE = mediaLibrary.DirectoryType.DIR_IMAGE;  
  const path = await media.getPublicDirectory(DIR_IMAGE);  
  const asset = await media.createAsset(mediaType, 'image00003.jpg', path);  
  asset.open('rw', (error, fd) => {  
    if (fd > 0) {  
      asset.close(fd);  
    } else {  
      console.error('File Open failed with error: ' + error);  
    }  
  });  
}  
    
```    
  
    
### open<sup>(deprecated)</sup>    
打开当前文件，使用callback方式返回异步结果。  
 **调用形式：**     
- open(mode: string): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA or ohos.permission.WRITE_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode<sup>(deprecated)</sup> | string | true | 打开文件方式，如：'r'（只读）, 'w'（只写）, 'rw'（读写）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象，返回文件描述符。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  let mediaType = mediaLibrary.MediaType.IMAGE;  
  let DIR_IMAGE = mediaLibrary.DirectoryType.DIR_IMAGE;  
  const path = await media.getPublicDirectory(DIR_IMAGE);  
  const asset = await media.createAsset(mediaType, 'image00003.jpg', path);  
  asset.open('rw').then((fd) => {  
    console.info('File open fd: ' + fd);  
  }).catch((error: BusinessError) => {  
    console.error('File open failed with error: ' + error);  
  });  
}  
    
```    
  
    
### close<sup>(deprecated)</sup>    
关闭当前文件，使用callback方式返回异步结果。  
 **调用形式：**     
- close(fd: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA or ohos.permission.WRITE_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 文件描述符。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | callback返回空。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  const fetchFileResult = await media.getFileAssets(getImageOp);  
  const asset = await fetchFileResult.getFirstObject();  
  asset.open('rw').then((fd) => {  
    console.info('File open fd: ' + fd);  
    asset.close(fd, (error) => {  
      if (error) {  
        console.error('asset.close failed with error: ' + error);  
      } else {  
        console.info('asset.close successfully');  
      }  
    });  
  }).catch((error: BusinessError) => {  
    console.error('File open failed with error: ' + error);  
  });  
  fetchFileResult.close();  
}  
    
```    
  
    
### close<sup>(deprecated)</sup>    
关闭当前文件，使用callback方式返回异步结果。  
 **调用形式：**     
- close(fd: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA or ohos.permission.WRITE_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 文件描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象，返回空。 |  
    
 **示例代码：**   
示例代码（promise）：  
```null    
<span style="font-size: 14px; letter-spacing: 0px;">import { BusinessError } from '@ohos.base';</span>  
  
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  const fetchFileResult = await media.getFileAssets(getImageOp);  
  const asset = await fetchFileResult.getFirstObject();  
  asset.open('rw').then((fd) => {  
    console.info('File fd!' + fd);  
    asset.close(fd).then(() => {  
      console.info('asset.close successfully');  
    }).catch((closeErr) => {  
      console.error('asset.close fail, closeErr: ' + closeErr);  
    });  
  }).catch((error: BusinessError) => {  
    console.error('open File failed with error: ' + error);  
  });  
  fetchFileResult.close();  
}    
```    
  
    
### getThumbnail<sup>(deprecated)</sup>    
获取文件的缩略图，使用callback方式返回异步结果。  
 **调用形式：**     
- getThumbnail(callback: AsyncCallback\<image.PixelMap>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<image.PixelMap> | true | callback返回缩略图的PixelMap。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  const fetchFileResult = await media.getFileAssets(getImageOp);  
  const asset = await fetchFileResult.getFirstObject();  
  asset.getThumbnail((error, pixelmap) => {  
    if (error) {  
      console.error('mediaLibrary getThumbnail failed with error: ' + error);  
    } else {  
      console.info('mediaLibrary getThumbnail Successful, pixelmap ' + JSON.stringify(pixelmap));  
    }  
  });  
  fetchFileResult.close();  
}  
    
```    
  
    
### getThumbnail<sup>(deprecated)</sup>    
获取文件的缩略图，使用callback方式返回异步结果。  
 **调用形式：**     
- getThumbnail(size: Size, callback: AsyncCallback\<image.PixelMap>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size<sup>(deprecated)</sup> | Size | true | 缩略图尺寸。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<image.PixelMap> | true | callback返回缩略图的PixelMap。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  let size: mediaLibrary.Size = { width: 720, height: 720 };  
  const fetchFileResult = await media.getFileAssets(getImageOp);  
  const asset = await fetchFileResult.getFirstObject();  
  asset.getThumbnail(size, (error, pixelmap) => {  
    if (error) {  
      console.error('mediaLibrary getThumbnail failed with error: ' + error);  
    } else {  
      console.info('mediaLibrary getThumbnail Successful, pixelmap ' + JSON.stringify(pixelmap));  
    }  
  });  
  fetchFileResult.close();  
}  
    
```    
  
    
### getThumbnail<sup>(deprecated)</sup>    
获取文件的缩略图，使用callback方式返回异步结果。  
 **调用形式：**     
- getThumbnail(size?: Size): Promise\<image.PixelMap>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size<sup>(deprecated)</sup> | Size | false | 缩略图尺寸。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<image.PixelMap> | Promise对象，返回缩略图的PixelMap。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  let size: mediaLibrary.Size = { width: 720, height: 720 };  
  const fetchFileResult = await media.getFileAssets(getImageOp);  
  const asset = await fetchFileResult.getFirstObject();  
  asset.getThumbnail(size).then((pixelmap) => {  
    console.info('mediaLibrary getThumbnail Successful, pixelmap ' + JSON.stringify(pixelmap));  
  }).catch((error: BusinessError) => {  
    console.error('mediaLibrary getThumbnail failed with error: ' + error);  
  });  
  fetchFileResult.close();  
}  
    
```    
  
    
### favorite<sup>(deprecated)</sup>    
将文件设置为收藏文件，使用callback方式返回异步结果。  
 **调用形式：**     
- favorite(isFavorite: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isFavorite<sup>(deprecated)</sup> | boolean | true | 是否设置为收藏文件， true：设置为收藏文件，false：取消收藏。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | callback返回空。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  const fetchFileResult = await media.getFileAssets(getImageOp);  
  const asset = await fetchFileResult.getFirstObject();  
  asset.favorite(true,(error) => {  
    if (error) {  
      console.error('mediaLibrary favorite failed with error: ' + error);  
    } else {  
      console.info('mediaLibrary favorite Successful');  
    }  
  });  
  fetchFileResult.close();  
}  
    
```    
  
    
### favorite<sup>(deprecated)</sup>    
将文件设置为收藏文件，使用callback方式返回异步结果。  
 **调用形式：**     
- favorite(isFavorite: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isFavorite<sup>(deprecated)</sup> | boolean | true | 是否设置为收藏文件， true：设置为收藏文件，false：取消收藏。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象，返回空。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  const fetchFileResult = await media.getFileAssets(getImageOp);  
  const asset = await fetchFileResult.getFirstObject();  
  asset.favorite(true).then(() => {  
    console.info('mediaLibrary favorite Successful');  
  }).catch((error: BusinessError) => {  
    console.error('mediaLibrary favorite failed with error: ' + error);  
  });  
  fetchFileResult.close();  
}  
    
```    
  
    
### isFavorite<sup>(deprecated)</sup>    
判断该文件是否为收藏文件，使用callback方式返回异步结果。  
 **调用形式：**     
- isFavorite(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | callback返回boolean值，值为true则为已收藏，值为false则为未收藏。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  const fetchFileResult = await media.getFileAssets(getImageOp);  
  const asset = await fetchFileResult.getFirstObject();  
  asset.isFavorite((error, isFavorite) => {  
    if (error) {  
      console.error('mediaLibrary favoriisFavoritete failed with error: ' + error);  
    } else {  
      console.info('mediaLibrary isFavorite Successful, isFavorite result: ' + isFavorite);  
    }  
  });  
  fetchFileResult.close();  
}  
    
```    
  
    
### isFavorite<sup>(deprecated)</sup>    
判断该文件是否为收藏文件，使用callback方式返回异步结果。  
 **调用形式：**     
- isFavorite(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象，返回boolean值，值为true则为已收藏，值为false则为未收藏。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  const fetchFileResult = await media.getFileAssets(getImageOp);  
  const asset = await fetchFileResult.getFirstObject();  
  asset.isFavorite().then((isFavorite) => {  
    console.info('mediaLibrary isFavorite Successful, isFavorite result: ' + isFavorite);  
  }).catch((error: BusinessError) => {  
    console.error('mediaLibrary favoriisFavoritete failed with error: ' + error);  
  });  
  fetchFileResult.close();  
}  
    
```    
  
    
### trash<sup>(deprecated)</sup>    
当文件被定位时，将文件放到垃圾文件夹，使用callback方式返回异步结果。  
 **调用形式：**     
- trash(isTrash: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isTrash<sup>(deprecated)</sup> | boolean | true | 是否设置为垃圾文件。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | callback返回空。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  const fetchFileResult = await media.getFileAssets(getImageOp);  
  const asset = await fetchFileResult.getFirstObject();  
  asset.trash(true, (error) => {  
    if (error) {  
      console.error('mediaLibrary trash failed with error: ' + error);  
    } else {  
      console.info('mediaLibrary trash Successful');  
    }  
  });  
  fetchFileResult.close();  
}  
    
```    
  
    
### trash<sup>(deprecated)</sup>    
当文件被定位时，将文件放到垃圾文件夹，使用callback方式返回异步结果。  
 **调用形式：**     
- trash(isTrash: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isTrash<sup>(deprecated)</sup> | boolean | true | 是否设置为垃圾文件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象，返回空 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  const fetchFileResult = await media.getFileAssets(getImageOp);  
  const asset = await fetchFileResult.getFirstObject();  
  asset.trash(true).then(() => {  
    console.info('trash successfully');  
  }).catch((error: BusinessError) => {  
    console.error('trash failed with error: ' + error);  
  });  
  fetchFileResult.close();  
}  
    
```    
  
    
### isTrash<sup>(deprecated)</sup>    
当文件被定位，判断文件是否为垃圾文件，使用callback方式返回异步结果。  
 **调用形式：**     
- isTrash(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | callback返回boolean值，值为true则为垃圾文件，值为false则为非垃圾文件。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  const fetchFileResult = await media.getFileAssets(getImageOp);  
  const asset = await fetchFileResult.getFirstObject();  
  asset.isTrash((error, isTrash) => {  
    if (error) {  
      console.error('Failed to get trash state failed with error: ' + error);  
      return;  
    }  
    console.info('Get trash state successfully, isTrash result: ' + isTrash);  
  });  
  fetchFileResult.close();  
}    
```    
  
    
### isTrash<sup>(deprecated)</sup>    
当文件被定位，判断文件是否为垃圾文件，使用callback方式返回异步结果。  
 **调用形式：**     
- isTrash(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象，返回boolean值，值为true则为垃圾文件，值为false则为非垃圾文件。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  const fetchFileResult = await media.getFileAssets(getImageOp);  
  const asset = await fetchFileResult.getFirstObject();  
  asset.isTrash().then((isTrash) => {  
    console.info('isTrash result: ' + isTrash);  
  }).catch((error: BusinessError) => {  
    console.error('isTrash failed with error: ' + error);  
  });  
  fetchFileResult.close();  
}  
    
```    
  
    
## FileKey<sup>(deprecated)</sup>    
枚举，文件关键信息。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。    
    
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ID<sup>(deprecated)</sup> | file_id | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>文件编号。 |  
| RELATIVE_PATH<sup>(deprecated)</sup> | relative_path | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>相对公共目录路径。 |  
| DISPLAY_NAME<sup>(deprecated)</sup> | display_name | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>显示名字。 |  
| PARENT<sup>(deprecated)</sup> | parent | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>父目录id。 |  
| MIME_TYPE<sup>(deprecated)</sup> | mime_type | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>文件扩展属性(如：image/*、video/*、file/*)。 |  
| MEDIA_TYPE<sup>(deprecated)</sup> | media_type | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>媒体类型。 |  
| SIZE<sup>(deprecated)</sup> | size | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>文件大小（单位：字节）。 |  
| DATE_ADDED<sup>(deprecated)</sup> | date_added | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>添加日期（添加文件时间到1970年1月1日的秒数值）。 |  
| DATE_MODIFIED<sup>(deprecated)</sup> | date_modified | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>修改日期（修改文件时间到1970年1月1日的秒数值，修改文件名不会改变此值，当文件内容发生修改时才会更新）。 |  
| DATE_TAKEN<sup>(deprecated)</sup> | date_taken | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>拍摄日期（文件拍照时间到1970年1月1日的秒数值）。 |  
| TITLE<sup>(deprecated)</sup> | title | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>文件标题。 |  
| ARTIST<sup>(deprecated)</sup> | artist | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>作者。 |  
| AUDIOALBUM<sup>(deprecated)</sup> | audio_album | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>专辑。 |  
| DURATION<sup>(deprecated)</sup> | duration | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>持续时间（单位：毫秒）。 |  
| WIDTH<sup>(deprecated)</sup> | width | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>图片宽度（单位：像素）。 |  
| HEIGHT<sup>(deprecated)</sup> | height | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>图片高度（单位：像素）。 |  
| ORIENTATION<sup>(deprecated)</sup> | orientation | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>图片显示方向，即顺时针旋转角度，如0，90，180。（单位：度）。 |  
| ALBUM_ID<sup>(deprecated)</sup> | bucket_id | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>文件所归属的相册编号。 |  
| ALBUM_NAME<sup>(deprecated)</sup> | bucket_display_name | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>文件所归属相册名称。 |  
    
## MediaFetchOptions<sup>(deprecated)</sup>    
检索条件。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| selections<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>检索条件，使用[FileKey](#filekey8)中的枚举值作为检索条件的列名。示例：<br/>selections: mediaLibrary.FileKey.MEDIA_TYPE + '= ? OR ' + mediaLibrary.FileKey.MEDIA_TYPE + '= ?', |  
| selectionArgs<sup>(deprecated)</sup> | Array<string> | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>检索条件的值，对应selections中检索条件列的值。<br/>示例：<br/>selectionArgs: [mediaLibrary.MediaType.IMAGE.toString(), mediaLibrary.MediaType.VIDEO.toString()], |  
| order<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>检索结果排序方式，使用[FileKey](#filekey8)中的枚举值作为检索结果排序的列，可以用升序或降序排列。示例：<br/>升序排列：order: mediaLibrary.FileKey.DATE_ADDED + ' ASC'<br/>降序排列：order: mediaLibrary.FileKey.DATE_ADDED + ' DESC' |  
| uri<sup>(deprecated)</sup> | string | false | false | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>文件URI。 |  
| networkId<sup>(deprecated)</sup> | string | false | false | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>注册设备网络ID。 |  
| extendArgs<sup>(deprecated)</sup> | string | false | false | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>扩展的检索参数，目前没有扩展检索参数。 |  
    
## FetchFileResult<sup>(deprecated)</sup>    
文件检索结果集。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
### getCount<sup>(deprecated)</sup>    
获取文件检索结果中的文件总数。  
 **调用形式：**     
- getCount(): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 检索到的文件总数。 |  
    
 **示例代码：**   
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let fileType = mediaLibrary.MediaType.FILE;  
  let getFileCountOneOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [fileType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  let fetchFileResult = await media.getFileAssets(getFileCountOneOp);  
  const fetchCount = fetchFileResult.getCount();  
  console.info('fetchCount result: ' + fetchCount);  
  fetchFileResult.close();  
}    
```    
  
    
### isAfterLast<sup>(deprecated)</sup>    
检查结果集是否指向最后一行。  
 **调用形式：**     
- isAfterLast(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 当读到最后一条记录后，后续没有记录返回true，否则返回false。 |  
    
 **示例代码：**   
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  let fetchFileResult = await media.getFileAssets(getImageOp);  
  const fetchCount = fetchFileResult.getCount();  
  console.info('mediaLibrary fetchFileResult.getCount, count:' + fetchCount);  
  let fileAsset = await fetchFileResult.getFirstObject();  
  for (let i = 1; i < fetchCount; i++) {  
    fileAsset = await fetchFileResult.getNextObject();  
    if(i == fetchCount - 1) {  
      let result = fetchFileResult.isAfterLast();  
      console.info('mediaLibrary fileAsset isAfterLast result: ' + result);  
      fetchFileResult.close();  
    }  
  }  
}    
```    
  
    
### close<sup>(deprecated)</sup>    
释放 FetchFileResult 实例并使其失效。无法调用其他方法。  
 **调用形式：**     
- close(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **示例代码：**   
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  let fetchFileResult = await media.getFileAssets(getImageOp);  
  fetchFileResult.close();  
}    
```    
  
    
### getFirstObject<sup>(deprecated)</sup>    
获取文件检索结果中的第一个文件资产。此方法使用回调返回FileAsset。  
 **调用形式：**     
- getFirstObject(callback: AsyncCallback\<FileAsset>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<FileAsset> | true | callback返回文件检索结果集中第一个FileAsset对象。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  let fetchFileResult = await media.getFileAssets(getImageOp);  
  fetchFileResult.getFirstObject((error, fileAsset) => {  
    if (error) {  
      console.error('fetchFileResult getFirstObject failed with error: ' + error);  
      return;  
    }  
    console.info('getFirstObject successfully, displayName : ' + fileAsset.displayName);  
    fetchFileResult.close();  
  })  
}    
```    
  
    
### getFirstObject<sup>(deprecated)</sup>    
获取文件检索结果中的第一个文件资产。此方法使用回调返回FileAsset。  
 **调用形式：**     
- getFirstObject(): Promise\<FileAsset>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<FileAsset> | Promise对象，返回文件检索结果集中第一个FileAsset。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  let fetchFileResult = await media.getFileAssets(getImageOp);  
  fetchFileResult.getFirstObject().then((fileAsset) => {  
    console.info('getFirstObject successfully, displayName: ' + fileAsset.displayName);  
    fetchFileResult.close();  
  }).catch((error: BusinessError) => {  
    console.error('getFirstObject failed with error: ' + error);  
  });  
}  
    
```    
  
    
### getNextObject<sup>(deprecated)</sup>    
获取文件检索结果中的下一个文件资产，此方法使用callback形式返回结果。  
 **调用形式：**     
- getNextObject(callback: AsyncCallback\<FileAsset>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<FileAsset> | true | callback返回文件检索结果集中下一个FileAsset对象。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  let fetchFileResult = await media.getFileAssets(getImageOp);  
  let fileAsset = await fetchFileResult.getFirstObject();  
  console.log('fetchFileResult getFirstObject successfully, displayName: ' + fileAsset.displayName);  
  if (!fetchFileResult.isAfterLast()) {  
    fetchFileResult.getNextObject((error, fileAsset) => {  
      if (error) {  
        console.error('fetchFileResult getNextObject failed with error: ' + error);  
        return;  
      }  
      console.log('fetchFileResult getNextObject successfully, displayName: ' + fileAsset.displayName);  
      fetchFileResult.close();  
    })  
  }  
}    
```    
  
    
### getNextObject<sup>(deprecated)</sup>    
获取文件检索结果中的下一个文件资产，此方法使用callback形式返回结果。  
 **调用形式：**     
- getNextObject(): Promise\<FileAsset>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<FileAsset> | Promise对象，返回文件检索结果集中下一个FileAsset。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  let fetchFileResult = await media.getFileAssets(getImageOp);  
  let fileAsset = await fetchFileResult.getFirstObject();  
  console.log('fetchFileResult getFirstObject successfully, displayName: ' + fileAsset.displayName);  
  if (!fetchFileResult.isAfterLast()) {  
    fetchFileResult.getNextObject().then((fileAsset) => {  
      console.info('fetchFileResult getNextObject successfully, displayName: ' + fileAsset.displayName);  
      fetchFileResult.close();  
    }).catch((error: BusinessError) => {  
      console.error('fetchFileResult getNextObject failed with error: ' + error);  
    })  
  }  
}  
    
```    
  
    
### getLastObject<sup>(deprecated)</sup>    
获取文件检索结果中的最后一个文件资产。此方法使用callback回调来返回FileAsset。  
 **调用形式：**     
- getLastObject(callback: AsyncCallback\<FileAsset>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<FileAsset> | true | callback返回文件检索结果集中最后一个FileAsset对象。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  let fetchFileResult = await media.getFileAssets(getImageOp);  
  fetchFileResult.getLastObject((error, fileAsset) => {  
    if (error) {  
      console.error('getLastObject failed with error: ' + error);  
      return;  
    }  
    console.info('getLastObject successfully, displayName: ' + fileAsset.displayName);  
    fetchFileResult.close();  
  })  
}    
```    
  
    
### getLastObject<sup>(deprecated)</sup>    
获取文件检索结果中的最后一个文件资产。此方法使用callback回调来返回FileAsset。  
 **调用形式：**     
- getLastObject(): Promise\<FileAsset>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<FileAsset> | Promise对象，返回文件检索结果集中下一个FileAsset。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  let fetchFileResult = await media.getFileAssets(getImageOp);  
  fetchFileResult.getLastObject().then((fileAsset) => {  
    console.info('getLastObject successfully, displayName: ' + fileAsset.displayName);  
    fetchFileResult.close();  
  }).catch((error: BusinessError) => {  
    console.error('getLastObject failed with error: ' + error);  
  });  
}  
    
```    
  
    
### getPositionObject<sup>(deprecated)</sup>    
获取文件检索结果中具有指定索引的文件资产。此方法使用回调来返回FileAsset。  
 **调用形式：**     
- getPositionObject(index: number, callback: AsyncCallback\<FileAsset>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index<sup>(deprecated)</sup> | number | true | 要获取的文件的索引，从0开始(注意该值要小于文件检索集的count值)。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<FileAsset> | true | callback返回文件检索结果集中指定索引处的FileAsset对象。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  let fetchFileResult = await media.getFileAssets(getImageOp);  
  fetchFileResult.getPositionObject(0, (error, fileAsset) => {  
    if (error) {  
      console.error('getPositionObject failed with error: ' + error);  
      return;  
    }  
    console.info('getPositionObject successfully, displayName: ' + fileAsset.displayName);  
    fetchFileResult.close();  
  })  
}    
```    
  
    
### getPositionObject<sup>(deprecated)</sup>    
获取文件检索结果中具有指定索引的文件资产。此方法使用回调来返回FileAsset。  
 **调用形式：**     
- getPositionObject(index: number): Promise\<FileAsset>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index<sup>(deprecated)</sup> | number | true | 要获取的文件的索引，从0开始(注意该值要小于文件检索集的count值)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<FileAsset> | Promise对象，返回文件检索结果集中指定索引处的FileAsset。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  let fetchFileResult = await media.getFileAssets(getImageOp);  
  fetchFileResult.getPositionObject(0).then((fileAsset) => {  
    console.info('getPositionObject successfully, displayName: ' + fileAsset.displayName);  
    fetchFileResult.close();  
  }).catch((error: BusinessError) => {  
    console.error('getPositionObject failed with error: ' + error);  
  });  
}  
    
```    
  
    
### getAllObject<sup>(deprecated)</sup>    
获取文件检索结果中的所有文件资产。此方法使用Callback回调来返回FileAsset结果集。  
 **调用形式：**     
- getAllObject(callback: AsyncCallback\<Array\<FileAsset>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<FileAsset>> | true | callback返回文件检索结果集中所有的FileAsset对象。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  let fetchFileResult = await media.getFileAssets(getImageOp);  
  fetchFileResult.getAllObject((error, fileAssetList) => {  
    if (error) {  
      console.error('getAllObject failed with error: ' + error);  
      return;  
    }  
    for (let i = 0; i < fetchFileResult.getCount(); i++) {  
      console.info('getAllObject fileAssetList ' + i + ' displayName: ' + fileAssetList[i].displayName);  
    }  
    fetchFileResult.close();  
  })  
}    
```    
  
    
### getAllObject<sup>(deprecated)</sup>    
获取文件检索结果中的所有文件资产。此方法使用Callback回调来返回FileAsset结果集。  
 **调用形式：**     
- getAllObject(): Promise\<Array\<FileAsset>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<FileAsset>> | Promise对象，返回文件检索结果集中所有的FileAsset。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  let getImageOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
    order: fileKeyObj.DATE_ADDED + ' DESC',  
  };  
  let fetchFileResult = await media.getFileAssets(getImageOp);  
  fetchFileResult.getAllObject().then((fileAssetList) => {  
    for (let i = 0; i < fetchFileResult.getCount(); i++) {  
      console.info('getAllObject fileAssetList ' + i + ' displayName: ' + fileAssetList[i].displayName);  
    }   
    fetchFileResult.close();  
  }).catch((error: BusinessError) => {  
    console.error('getAllObject failed with error: ' + error);  
  });  
}  
    
```    
  
    
## Album<sup>(deprecated)</sup>    
实体相册    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| albumId<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>相册编号。 |  
| albumName<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>相册名称。 |  
| albumUri<sup>(deprecated)</sup> | string | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>相册Uri。 |  
| dateModified<sup>(deprecated)</sup> | number | true | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>修改日期。 |  
| count<sup>(deprecated)</sup> | number | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>相册中文件数量。 |  
| relativePath<sup>(deprecated)</sup> | string | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>相对路径。 |  
| coverUri<sup>(deprecated)</sup> | string | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>封面文件Uri。 |  
    
### commitModify<sup>(deprecated)</sup>    
更新相册属性修改到数据库中。  
 **调用形式：**     
- commitModify(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | callback返回空。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  // 获取相册需要先预置相册和资源，示例代码为预置的新建相册1。  
  let albumFetchOp: mediaLibrary.MediaFetchOptions = {  
    selections: mediaLibrary.FileKey.ALBUM_NAME + '= ?',  
    selectionArgs: ['新建相册1'],  
  };  
  const albumList = await media.getAlbums(albumFetchOp);  
  const album = albumList[0];  
  album.albumName = 'hello';  
  album.commitModify((error) => {  
    if (error) {  
      console.error('commitModify failed with error: ' + error);  
      return;  
    }  
    console.info('commitModify successful.');  
  });  
}    
```    
  
    
### commitModify<sup>(deprecated)</sup>    
更新相册属性修改到数据库中。  
 **调用形式：**     
- commitModify(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象，返回空。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  // 获取相册需要先预置相册和资源，示例代码为预置的新建相册1。  
  let albumFetchOp: mediaLibrary.MediaFetchOptions = {  
    selections: mediaLibrary.FileKey.ALBUM_NAME + '= ?',  
    selectionArgs: ['新建相册1'],  
  };  
  const albumList = await media.getAlbums(albumFetchOp);  
  const album = albumList[0];  
  album.albumName = 'hello';  
  album.commitModify().then(() => {  
    console.info('commitModify successfully');  
  }).catch((error: BusinessError) => {  
    console.error('commitModify failed with error: ' + error);  
  });  
}  
    
```    
  
    
### getFileAssets<sup>(deprecated)</sup>    
按照检索条件获取相册中的文件。此方法使用Callback回调来返回文件结果集。  
 **调用形式：**     
- getFileAssets(callback: AsyncCallback\<FetchFileResult>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<FetchFileResult> | true | callback返回相册中的文件检索结果集。 |  
    
### getFileAssets<sup>(deprecated)</sup>    
按照检索条件获取相册中的文件。此方法使用Callback回调来返回文件结果集。  
 **调用形式：**     
- getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | MediaFetchOptions | true | 媒体检索选项。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<FetchFileResult> | true | callback返回相册中的文件检索结果集。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  // 获取相册需要先预置相册和资源，示例代码为预置的新建相册1。  
  let albumFetchOp: mediaLibrary.MediaFetchOptions = {  
    selections: mediaLibrary.FileKey.ALBUM_NAME + '= ?',  
    selectionArgs: ['新建相册1'],  
  };  
  // 获取符合检索要求的相册，返回相册列表。  
  const albumList = await media.getAlbums(albumFetchOp);  
  const album = albumList[0];  
  // 取到相册列表中的一个相册，获取此相册中所有符合媒体检索选项的媒体资源。  
  album.getFileAssets((error, fetchFileResult) => {  
    if (error) {  
      console.error('album getFileAssets failed with error: ' + error);  
      return;  
    }  
    let count = fetchFileResult.getCount();  
    console.info('album getFileAssets successfully, count: ' + count);  
    fetchFileResult.close();  
  });  
}    
```    
  
    
### getFileAssets<sup>(deprecated)</sup>    
按照检索条件获取相册中的文件。此方法使用异步Promise来返回文件结果集  
  
 **调用形式：**     
- getFileAssets(options?: MediaFetchOptions): Promise\<FetchFileResult>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | MediaFetchOptions | false | 媒体检索选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<FetchFileResult> | Promise对象，返回相册中的文件检索结果集。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  // 获取相册需要先预置相册和资源，示例代码为预置的新建相册1。  
  let albumFetchOp: mediaLibrary.MediaFetchOptions = {  
    selections: mediaLibrary.FileKey.ALBUM_NAME + '= ?',  
    selectionArgs: ['新建相册1'],  
  };  
  let fileNoArgsfetchOp: mediaLibrary.MediaFetchOptions = {  
    selections: '',  
    selectionArgs: [],  
  };  
  // 获取符合检索要求的相册，返回相册列表。  
  const albumList = await media.getAlbums(albumFetchOp);  
  const album = albumList[0];  
  // 取到相册列表中的一个相册，获取此相册中所有符合媒体检索选项的媒体资源。  
  album.getFileAssets(fileNoArgsfetchOp).then((fetchFileResult) => {  
    let count = fetchFileResult.getCount();  
    console.info('album getFileAssets successfully, count: ' + count);  
    fetchFileResult.close();  
  }).catch((error: BusinessError) => {  
    console.error('album getFileAssets failed with error: ' + error);  
  });  
}  
    
```    
  
    
## DirectoryType<sup>(deprecated)</sup>    
枚举，目录类型。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。    
    
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DIR_CAMERA<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>表示Camera文件路径。 |  
| DIR_VIDEO<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>表示视频路径。 |  
| DIR_IMAGE<sup>(deprecated)</sup> | 2 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>表示图片路径。 |  
| DIR_AUDIO<sup>(deprecated)</sup> | 3 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>表示音频路径。 |  
| DIR_DOCUMENTS<sup>(deprecated)</sup> | 4 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>表示文档路径。 |  
| DIR_DOWNLOAD<sup>(deprecated)</sup> | 5 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>表示下载路径。 |  
    
## MediaLibrary<sup>(deprecated)</sup>    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
### getPublicDirectory<sup>(deprecated)</sup>    
获取公共目录路径，使用callback方式返回结果。  
 **调用形式：**     
- getPublicDirectory(type: DirectoryType, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | DirectoryType | true | 公共目录类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | callback返回公共目录路径。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
let DIR_CAMERA = mediaLibrary.DirectoryType.DIR_CAMERA;  
media.getPublicDirectory(DIR_CAMERA, (error, dicResult) => {  
  if (dicResult == 'Camera/') {  
    console.info('getPublicDirectory DIR_CAMERA successfully');  
  } else {  
    console.error('getPublicDirectory DIR_CAMERA failed with error: ' + error);  
  }  
});  
    
```    
  
    
### getPublicDirectory<sup>(deprecated)</sup>    
获取公共目录路径，使用callback方式返回结果。  
 **调用形式：**     
- getPublicDirectory(type: DirectoryType): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | DirectoryType | true | 公共目录类型。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise对象，返回公共目录路径。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  let DIR_CAMERA = mediaLibrary.DirectoryType.DIR_CAMERA;  
  media.getPublicDirectory(DIR_CAMERA).then((dicResult) => {  
    if (dicResult == 'Camera/') {  
      console.info('getPublicDirectory DIR_CAMERA successfully');  
    } else {  
      console.error('getPublicDirectory DIR_CAMERA failed');  
    }  
  }).catch((error: BusinessError) => {  
    console.error('getPublicDirectory failed with error: ' + error);  
  });  
}  
    
```    
  
    
### getFileAssets<sup>(deprecated)</sup>    
按照检索条件获取相册中的文件。此方法使用Callback回调来返回文件结果集。  
 **调用形式：**     
- getFileAssets(options: MediaFetchOptions, callback: AsyncCallback\<FetchFileResult>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | MediaFetchOptions | true | 媒体检索选项。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<FetchFileResult> | true | callback返回相册中的文件检索结果集。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  // 创建文件获取选项，此处参数为获取image类型的文件资源。  
  let imagesFetchOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
  };  
  // 获取文件资源，使用callback方式返回异步结果。  
  media.getFileAssets(imagesFetchOp, async (error, fetchFileResult) => {  
    // 判断获取的文件资源的检索结果集是否为undefined，若为undefined则接口调用失败。  
    if (fetchFileResult == undefined) {  
      console.error('get fetchFileResult failed with error: ' + error);  
      return;  
    }  
    // 获取文件检索结果集中的总数。  
    const count = fetchFileResult.getCount();  
    // 判断结果集中的数量是否小于0，小于0时表示接口调用失败。  
    if (count < 0) {  
      console.error('get count from fetchFileResult failed, count: ' + count);  
      return;  
    }  
    // 判断结果集中的数量是否等于0，等于0时表示接口调用成功，但是检索结果集为空，请检查文件获取选项参数配置是否有误和设备中是否存在相应文件。  
    if (count == 0) {  
      console.info('The count of fetchFileResult is zero');  
      return;  
    }  
    console.info('Get fetchFileResult successfully, count: ' + count);  
    // 获取文件检索结果集中的第一个资源，使用callback方式返回异步结果，文件数量较多时请使用getAllObject接口。  
    fetchFileResult.getFirstObject(async (error, fileAsset) => {  
      // 检查获取的第一个资源是否为undefined，若为undefined则接口调用失败。  
      if (fileAsset == undefined) {  
        console.error('get first object failed with error: ' + error);  
        return;  
      }  
      console.info('fileAsset.displayName ' + '0 : ' + fileAsset.displayName);  
      // 调用 getNextObject 接口获取下一个资源，直到最后一个。  
      for (let i = 1; i < count; i++) {  
        let fileAsset = await fetchFileResult.getNextObject();  
        console.info('fileAsset.displayName ' + i + ': ' + fileAsset.displayName);  
      }  
      // 释放FetchFileResult实例并使其失效。无法调用其他方法。  
      fetchFileResult.close();  
    });  
  });  
}    
```    
  
    
### getFileAssets<sup>(deprecated)</sup>    
按照检索条件获取相册中的文件。此方法使用Callback回调来返回文件结果集。  
 **调用形式：**     
- getFileAssets(options: MediaFetchOptions): Promise\<FetchFileResult>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | MediaFetchOptions | true | 媒体检索选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<FetchFileResult> | Promise对象，返回相册中的文件检索结果集。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  let fileKeyObj = mediaLibrary.FileKey;  
  let imageType = mediaLibrary.MediaType.IMAGE;  
  // 创建文件获取选项，此处参数为获取image类型的文件资源。  
  let imagesFetchOp: mediaLibrary.MediaFetchOptions = {  
    selections: fileKeyObj.MEDIA_TYPE + '= ?',  
    selectionArgs: [imageType.toString()],  
  };  
  // 获取文件资源，使用Promise方式返回结果。  
  media.getFileAssets(imagesFetchOp).then(async (fetchFileResult) => {  
    // 获取文件检索结果集中的总数。  
    const count = fetchFileResult.getCount();  
    // 判断结果集中的数量是否小于0，小于0时表示接口调用失败。  
    if (count < 0) {  
      console.error('get count from fetchFileResult failed, count: ' + count);  
      return;  
    }  
    // 判断结果集中的数量是否等于0，等于0时表示接口调用成功，但是检索结果集为空，请检查文件获取选项参数配置是否有误和设备中是否存在相应文件。  
    if (count == 0) {  
      console.info('The count of fetchFileResult is zero');  
      return;  
    }  
    console.info('Get fetchFileResult successfully, count: ' + count);  
    // 获取文件检索结果集中的第一个资源，使用Promise方式返回异步结果，文件数量较多时请使用getAllObject接口。  
    fetchFileResult.getFirstObject().then(async (fileAsset) => {  
      console.info('fileAsset.displayName ' + '0 : ' + fileAsset.displayName);  
      // 调用 getNextObject 接口获取下一个资源，直到最后一个。  
      for (let i = 1; i < count; i++) {  
        let fileAsset = await fetchFileResult.getNextObject();  
        console.info('fileAsset.displayName ' + i + ': ' + fileAsset.displayName);  
      }  
      // 释放FetchFileResult实例并使其失效。无法调用其他方法。  
      fetchFileResult.close();  
    }).catch((error: BusinessError) => {  
      // 调用getFirstObject接口失败。  
      console.error('get first object failed with error: ' + error);  
    });  
  }).catch((error: BusinessError) => {  
    // 调用getFileAssets接口失败。  
    console.error('get file assets failed with error: ' + error);  
  });  
}  
    
```    
  
    
### on('deviceChange' | 'albumChange' | 'imageChange' | 'audioChange' | 'videoChange' | 'fileChange' | 'remoteFileChange')<sup>(deprecated)</sup>    
打开媒体库变更通知，使用callback方式返回异步结果。  
 **调用形式：**     
- on(type: 'deviceChange' | 'albumChange' | 'imageChange' | 'audioChange' | 'videoChange' | 'fileChange' | 'remoteFileChange', callback: Callback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 媒体类型 <br/>'deviceChange'：注册设备变更 <br/>'albumChange'：相册变更<br/>'imageChange'：图片文件变更<br/>'audioChange'： 音频文件变更<br/>'videoChange'：  视频文件变更<br/>'fileChange'：     文件变更<br/>'remoteFileChange'：注册设备上文件变更。 |  
| callback<sup>(deprecated)</sup> | Callback<void> | true | callbac返回空。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
media.on('imageChange', () => {  
  // image file had changed, do something.  
});    
```    
  
    
### off('deviceChange' | 'albumChange' | 'imageChange' | 'audioChange' | 'videoChange' | 'fileChange' | 'remoteFileChange')<sup>(deprecated)</sup>    
关闭媒体库变更通知，使用callback方式返回异步结果。  
 **调用形式：**     
- off(type: 'deviceChange' | 'albumChange' | 'imageChange' | 'audioChange' | 'videoChange' | 'fileChange' | 'remoteFileChange', callback?: Callback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 媒体类型 <br/>'deviceChange'：注册设备变更 <br/>'albumChange'：相册变更<br/>'imageChange'：图片文件变更<br/>'audioChange'： 音频文件变更<br/>'videoChange'： 视频文件变更<br/>'fileChange'： 文件变更<br/>'remoteFileChange'：注册设备上文件变更。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<void> | false | callback返回空。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
media.off('imageChange', () => {  
  // stop listening successfully.  
});    
```    
  
    
### createAsset<sup>(deprecated)</sup>    
创建媒体资源，使用callback方式返回结果。  
 **调用形式：**     
- createAsset(mediaType: MediaType, displayName: string, relativePath: string, callback: AsyncCallback\<FileAsset>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mediaType<sup>(deprecated)</sup> | MediaType | true | 媒体类型。 |  
| displayName<sup>(deprecated)</sup> | string | true | 展示文件名。 |  
| relativePath<sup>(deprecated)</sup> | string | true | 文件保存路径，可以通过[getPublicDirectory](#getpublicdirectory8)获取不同类型文件的保存路径。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<FileAsset> | true | callback返回创建的媒体资源FileAsset对象。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  // 使用Callback方式创建Image类型文件。  
  let mediaType = mediaLibrary.MediaType.IMAGE;  
  let DIR_IMAGE = mediaLibrary.DirectoryType.DIR_IMAGE;  
  const path = await media.getPublicDirectory(DIR_IMAGE);  
  media.createAsset(mediaType, 'imageCallBack.jpg', path + 'myPicture/', (error, fileAsset) => {  
    if (fileAsset != undefined) {  
      console.info('createAsset successfully, message');  
    } else {  
      console.error('createAsset failed with error: ' + error);  
    }  
  });  
}  
    
```    
  
    
### createAsset<sup>(deprecated)</sup>    
创建媒体资源，使用callback方式返回结果。  
 **调用形式：**     
- createAsset(mediaType: MediaType, displayName: string, relativePath: string): Promise\<FileAsset>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mediaType<sup>(deprecated)</sup> | MediaType | true | 媒体类型。 |  
| displayName<sup>(deprecated)</sup> | string | true | 展示文件名。 |  
| relativePath<sup>(deprecated)</sup> | string | true | 相对路径，可以通过getPublicDirectory获取不同类型媒体文件的一层目录的relative path。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<FileAsset> | Promise对象，返回创建媒体数据的FileAsset。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  // 使用Promise方式创建Image类型文件。  
  let mediaType = mediaLibrary.MediaType.IMAGE;  
  let DIR_IMAGE = mediaLibrary.DirectoryType.DIR_IMAGE;  
  const path = await media.getPublicDirectory(DIR_IMAGE);  
  media.createAsset(mediaType, 'imagePromise.jpg', path + 'myPicture/').then((fileAsset) => {  
    console.info('createAsset successfully, message = ' + JSON.stringify(fileAsset));  
  }).catch((error: BusinessError) => {  
    console.error('createAsset failed with error: ' + error);  
  });  
}  
    
```    
  
    
### getAlbums<sup>(deprecated)</sup>    
获取相册列表，使用callback 方式返回结果。  
 **调用形式：**     
- getAlbums(options: MediaFetchOptions, callback: AsyncCallback\<Array\<Album>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | MediaFetchOptions | true | 相册检索条件。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<Album>> | true | callback返回获取的Album结果集。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
async function example() {  
  let albumFetchOp: mediaLibrary.MediaFetchOptions = {  
    selections: mediaLibrary.FileKey.ALBUM_NAME + '= ?',  
    selectionArgs: ['Camera'],  
  };  
  media.getAlbums(albumFetchOp, (error, albumList) => {  
    if (albumList != undefined) {  
      console.info('getAlbums successfully: ' + JSON.stringify(albumList));  
    } else {  
      console.error('getAlbums failed with error: ' + error);  
    }  
  });  
}  
    
```    
  
    
### getAlbums<sup>(deprecated)</sup>    
获取相册列表，使用callback 方式返回结果。  
 **调用形式：**     
- getAlbums(options: MediaFetchOptions): Promise\<Array\<Album>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core  
 **需要权限：** ohos.permission.READ_MEDIA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | MediaFetchOptions | true | 相册检索条件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<Album>> | Promise对象，返回获取的Album结果集。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
async function example() {  
  let albumFetchOp: mediaLibrary.MediaFetchOptions = {  
    selections: mediaLibrary.FileKey.ALBUM_NAME + '= ?',  
    selectionArgs: ['Camera'],  
  };  
  media.getAlbums(albumFetchOp).then((albumList) => {  
    console.info('getAlbums successfully: ' + JSON.stringify(albumList));  
  }).catch((error: BusinessError) => {  
    console.error('getAlbums failed with error: ' + error);  
  });  
}  
    
```    
  
    
### storeMediaAsset<sup>(deprecated)</sup>    
保存媒体资源，以异步方法获取保存成功的URI，使用callback形式返回结果。  
 **调用形式：**     
- storeMediaAsset(option: MediaAssetOption, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| option<sup>(deprecated)</sup> | MediaAssetOption | true | 媒体资源选项。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | callback返回保存媒体资源成功后得到的URI。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
let option: mediaLibrary.MediaAssetOption = {  
  src : '/data/storage/el2/base/haps/entry/image.png',  
  mimeType : 'image/*',  
  relativePath : 'Pictures/'  
};  
mediaLibrary.getMediaLibrary().storeMediaAsset(option, (error, value) => {  
  if (error) {  
    console.error('storeMediaAsset failed with error: ' + error);  
    return;  
  }  
  console.info('Media resources stored. ');  
  // Obtain the URI that stores media resources.  
});    
```    
  
    
### storeMediaAsset<sup>(deprecated)</sup>    
保存媒体资源，以异步方法获取保存成功的URI，使用callback形式返回结果。  
 **调用形式：**     
- storeMediaAsset(option: MediaAssetOption): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| option<sup>(deprecated)</sup> | MediaAssetOption | true | 媒体资源选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise对象，返回保存媒体资源成功后得到的URI。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let option: mediaLibrary.MediaAssetOption = {  
  src : '/data/storage/el2/base/haps/entry/image.png',  
  mimeType : 'image/*',  
  relativePath : 'Pictures/'  
};  
mediaLibrary.getMediaLibrary().storeMediaAsset(option).then((value) => {  
  console.info('Media resources stored.');  
  // Obtain the URI that stores media resources.  
}).catch((error: BusinessError) => {  
  console.error('storeMediaAsset failed with error: ' + error);  
});  
    
```    
  
    
### startImagePreview<sup>(deprecated)</sup>    
启动图片预览界面并限定预览开始显示的图片。可以预览指定序号的单张本地图片（file://），也可以预览列表中的所有网络图片（https://）。使用callback方式进行异步回调。  
 **调用形式：**     
- startImagePreview(images: Array\<string>, index: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| images<sup>(deprecated)</sup> | Array<string> | true | 预览的图片URI（'https://'，'file://'）列表。 |  
| index<sup>(deprecated)</sup> | number | true | 开始显示的图片序号。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | callback返回空。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
<span style="font-family: monospace, monospace; font-size: 1em; letter-spacing: 0px;">let images = [</span>  
  'file://media/xxxx/2',  
  'file://media/xxxx/3'  
];  
/* 网络图片使用方式。  
let images = [  
  'https://media.xxxx.com/image1.jpg',  
  'https://media.xxxx.com/image2.jpg'  
];  
*/  
let index = 1;  
mediaLibrary.getMediaLibrary().startImagePreview(images, index, (error) => {  
  if (error) {  
    console.error('startImagePreview failed with error: ' + error);  
    return;  
  }  
  console.info('Succeeded in previewing the images.');  
});    
```    
  
    
### startImagePreview<sup>(deprecated)</sup>    
启动图片预览界面并限定预览开始显示的图片。可以预览指定序号的单张本地图片（file://），也可以预览列表中的所有网络图片（https://）。使用callback方式进行异步回调。  
 **调用形式：**     
- startImagePreview(images: Array\<string>, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| images<sup>(deprecated)</sup> | Array<string> | true | 预览的图片URI（'https://'，'file://'）列表。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | callback返回空。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
let images = [  
  'file://media/xxxx/2',  
  'file://media/xxxx/3'  
];  
/* 网络图片使用方式。  
let images = [  
  'https://media.xxxx.com/image1.jpg',  
  'https://media.xxxx.com/image2.jpg'  
];  
*/  
mediaLibrary.getMediaLibrary().startImagePreview(images, (error) => {  
  if (error) {  
    console.error('startImagePreview failed with error: ' + error);  
    return;  
  }  
  console.info('Succeeded in previewing the images.');  
});    
```    
  
    
### startImagePreview<sup>(deprecated)</sup>    
启动图片预览界面并限定预览开始显示的图片。可以预览指定序号的单张本地图片（file://），也可以预览列表中的所有网络图片（https://）。使用callback方式进行异步回调。  
 **调用形式：**     
- startImagePreview(images: Array\<string>, index?: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| images<sup>(deprecated)</sup> | Array<string> | true | 预览的图片URI（'https://'，'file://'）列表。<br/> |  
| index<sup>(deprecated)</sup> | number | false |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象，返回空。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let images = [  
  'file://media/xxxx/2',  
  'file://media/xxxx/3'  
];  
/* 网络图片使用方式。  
let images = [  
  'https://media.xxxx.com/image1.jpg',  
  'https://media.xxxx.com/image2.jpg'  
];  
*/  
let index = 1;  
mediaLibrary.getMediaLibrary().startImagePreview(images, index).then(() => {  
  console.info('Succeeded in previewing the images.');  
}).catch((error: BusinessError) => {  
  console.error('startImagePreview failed with error: ' + error);  
});  
    
```    
  
    
### startMediaSelect<sup>(deprecated)</sup>    
启动媒体选择界面，以异步方法获取选择的媒体URI列表，使用callback形式返回结果。  
 **调用形式：**     
- startMediaSelect(option: MediaSelectOption, callback: AsyncCallback\<Array\<string>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| option<sup>(deprecated)</sup> | MediaSelectOption | true | 媒体选择选项。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<string>> | true | callback返回选择的媒体URI列表。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
let option : mediaLibrary.MediaSelectOption = {  
  type : 'media',  
  count : 2  
};  
mediaLibrary.getMediaLibrary().startMediaSelect(option, (error, value) => {  
  if (error) {  
    console.error('startMediaSelect failed with error: ' + error);  
    return;  
  }  
  console.info('Media resources selected.');  
  // Obtain the media selection value.  
});    
```    
  
    
### startMediaSelect<sup>(deprecated)</sup>    
启动媒体选择界面，以异步方法获取选择的媒体URI列表，使用callback形式返回结果。  
 **调用形式：**     
- startMediaSelect(option: MediaSelectOption): Promise\<Array\<string>>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| option<sup>(deprecated)</sup> | MediaSelectOption | true | 媒体选择选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<string>> | Promise对象，返回选择的媒体URI列表。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let option : mediaLibrary.MediaSelectOption = {  
  type : 'media',  
  count : 2  
};  
mediaLibrary.getMediaLibrary().startMediaSelect(option).then((value) => {  
  console.info('Media resources selected.');  
  // Obtain the media selection value.  
}).catch((error: BusinessError) => {  
  console.error('startMediaSelect failed with error: ' + error);  
});  
    
```    
  
    
### release<sup>(deprecated)</sup>    
释放MediaLibrary实例。当后续不需要使用MediaLibrary实例中的方法时调用。  
 **调用形式：**     
- release(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | callback返回空。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
media.release(() => {  
  // do something.  
});    
```    
  
    
### release<sup>(deprecated)</sup>    
释放MediaLibrary实例。当后续不需要使用MediaLibrary实例中的方法时调用。  
 **调用形式：**     
- release(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.file.picker。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象，返回空。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
media.release();    
```    
  
    
## Size<sup>(deprecated)</sup>    
图片尺寸。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。  
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
### 属性    
 **系统能力:**  SystemCapability.Multimedia.MediaLibrary.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| width<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>宽（单位：像素）。 |  
| height<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.file.picker替代。<br>高（单位：像素）。 |  
