# @ohos.file.picker    
选择器(Picker)是一个封装PhotoViewPicker、DocumentViewPicker、AudioViewPicker等API模块，具有选择与保存的能力。应用可以自行选择使用哪种API实现文件选择和文件保存的功能。该类接口，需要应用在界面UIAbility中调用，否则无法拉起photoPicker应用或FilePicker应用。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import picker from '@ohos.file.picker'    
```  
    
## PhotoViewMIMETypes    
枚举，可选择的媒体文件类型。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| IMAGE_TYPE | image/* | 图片类型 |  
| VIDEO_TYPE | video/* | 视频类型 |  
| IMAGE_VIDEO_TYPE | */* | 图片和视频类型 |  
    
## PhotoSelectOptions    
图库选择选项。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| MIMEType | PhotoViewMIMETypes | false | false | 可选择的媒体文件类型，若无此参数，则默认为图片和视频类型 |  
| maxSelectNumber | number | false | false | 选择媒体文件数量的最大值(默认值为50，最大值为500) |  
    
## PhotoSelectResult    
返回图库选择后的结果集。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| photoUris | Array<string> | false | true | 返回图库选择后的媒体文件的uri数组，此uri数组只能通过临时授权的方式调用[photoAccessHelper.getAssets接口](js-apis-photoAccessHelper.md#getassets)去使用，具体使用方式参见用户文件uri介绍中的[媒体文件uri的使用方式](../../file-management/user-file-uri-intro.md#媒体文件uri的使用方式)。 |  
| isOriginalPhoto | boolean | false | true | 返回图库选择后的媒体文件是否为原图。 |  
    
## PhotoSaveOptions    
图片或视频的保存选项。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| newFileNames | Array<string> | false | false | 拉起photoPicker进行保存图片或视频资源的文件名，若无此参数，则默认需要用户自行输入 |  
    
## PhotoViewPicker    
图库选择器对象，用来支撑选择图片/视频和保存图片/视频等用户场景。选择文件推荐使用[PhotoAccessHelper的PhotoViewPicker](js-apis-photoAccessHelper.md)。在使用前，需要先创建PhotoViewPicker实例。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
### select    
通过选择模式拉起photoPicker界面，用户可以选择一个或多个图片/视频。传入可选参数PhotoSelectOptions对象，返回PhotoSelectResult对象。  
 **调用形式：**     
    
- select(option?: PhotoSelectOptions): Promise\<PhotoSelectResult>    
起始版本： 9    
- select(option: PhotoSelectOptions, callback: AsyncCallback\<PhotoSelectResult>): void    
起始版本： 9    
- select(callback: AsyncCallback\<PhotoSelectResult>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| option | PhotoSelectOptions | false | photoPicker选择选项，若无此参数，则默认选择媒体文件类型为图片和视频类型，选择媒体文件数量的默认最大值为50 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback 返回photoPicker选择后的结果集 |  
| Promise<PhotoSelectResult> | Promise对象。返回photoPicker选择后的结果集 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function example02() {  
  try {  
    let PhotoSelectOptions = new picker.PhotoSelectOptions();  
    PhotoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;  
    PhotoSelectOptions.maxSelectNumber = 5;  
    let photoPicker = new picker.PhotoViewPicker();  
    photoPicker.select(PhotoSelectOptions, (err: BusinessError, PhotoSelectResult: picker.PhotoSelectResult) => {  
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
    let PhotoSelectOptions = new picker.PhotoSelectOptions();  
    PhotoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;  
    PhotoSelectOptions.maxSelectNumber = 5;  
    let photoPicker = new picker.PhotoViewPicker();  
    photoPicker.select(PhotoSelectOptions).then((PhotoSelectResult: picker.PhotoSelectResult) => {  
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
  
    
### save    
通过保存模式拉起photoPicker界面，用户可以保存一个或多个图片/视频。传入可选参数PhotoSaveOptions对象，返回保存文件的uri数组。  
 **调用形式：**     
    
- save(option?: PhotoSaveOptions): Promise\<Array\<string>>    
起始版本： 9    
- save(option: PhotoSaveOptions, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 9    
- save(callback: AsyncCallback\<Array\<string>>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| option | PhotoSaveOptions | false | photoPicker保存图片或视频文件选项，若无此参数，则拉起photoPicker界面后需用户自行输入保存的文件名 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback 返回photoPicker保存图片或视频文件后的结果集 |  
| Promise<Array<string>> | Promise对象。返回photoPicker保存图片或视频文件后的结果集 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function example05() {  
  try {  
    let PhotoSaveOptions = new picker.PhotoSaveOptions();  
    PhotoSaveOptions.newFileNames = ['PhotoViewPicker02.jpg','PhotoViewPicker02.mp4'];  
    let photoPicker = new picker.PhotoViewPicker();  
    photoPicker.save(PhotoSaveOptions, (err: BusinessError, PhotoSaveResult: Array<string>) => {  
      if (err) {  
        console.error('PhotoViewPicker.save failed with err: ' + JSON.stringify(err));  
        return;  
      }  
      console.info('PhotoViewPicker.save successfully, PhotoSaveResult uri: ' + JSON.stringify(PhotoSaveResult));  
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
async function example04() {  
  try {  
    let PhotoSaveOptions = new picker.PhotoSaveOptions();  
    PhotoSaveOptions.newFileNames = ['PhotoViewPicker01.jpg', 'PhotoViewPicker01.mp4'];  
    let photoPicker = new picker.PhotoViewPicker();  
    photoPicker.save(PhotoSaveOptions).then((PhotoSaveResult: Array<string>) => {  
      console.info('PhotoViewPicker.save successfully, PhotoSaveResult uri: ' + JSON.stringify(PhotoSaveResult));  
    }).catch((err: BusinessError) => {  
      console.error('PhotoViewPicker.save failed with err: ' + JSON.stringify(err));  
    });  
  } catch (error) {  
    let err: BusinessError = error as BusinessError;  
      console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));  
  }  
}  
    
```    
  
    
## DocumentSelectOptions    
文档选择选项。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| defaultFilePathUri<sup>(10+)</sup> | string | false | false | 指定选择的文件或者目录路径 |  
| fileSuffixFilters<sup>(10+)</sup> | Array<string> | false | false | 选择文件的后缀类型，若选择项存在多个后缀名，则每一个后缀名之间用英文逗号进行分隔 |  
| maxSelectNumber<sup>(10+)</sup> | number | false | false | 选择文件/目录最大个数，上限500，有效值范围1-500 |  
    
## DocumentSaveOptions    
文档保存选项。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| newFileNames | Array<string> | false | false | 拉起documentPicker进行保存的文件名，若无此参数，则默认需要用户自行输入 |  
| defaultFilePathUri<sup>(10+)</sup> | string | false | false | 指定保存的文件或者目录路径 |  
| fileSuffixChoices<sup>(10+)</sup> | Array<string> | false | false | 保存文件的后缀类型 |  
    
## DocumentViewPicker    
文件选择器对象，用来支撑选择和保存各种格式文档。在使用前，需要先创建DocumentViewPicker实例。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
### select    
通过选择模式拉起documentPicker界面，用户可以选择一个或多个文件。传入可选参数DocumentSelectOptions对象，返回选择文件的uri数组。  
 **调用形式：**     
    
- select(option?: DocumentSelectOptions): Promise\<Array\<string>>    
起始版本： 9    
- select(option: DocumentSelectOptions, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 9    
- select(callback: AsyncCallback\<Array\<string>>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| option | DocumentSelectOptions | false | documentPicker选择选项，若无此参数，则默认拉起documentPicker主界面 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback 返回documentPicker选择后的结果集 |  
| Promise<Array<string>> | Promise对象。返回documentPicker选择后的结果集 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function example08() {  
  try {  
    let DocumentSelectOptions = new picker.DocumentSelectOptions();  
    let documentPicker = new picker.DocumentViewPicker();  
    documentPicker.select(DocumentSelectOptions, (err: BusinessError, DocumentSelectResult: Array<string>) => {  
      if (err) {  
        console.error('DocumentViewPicker.select failed with err: ' + JSON.stringify(err));  
        return;  
      }  
      console.info('DocumentViewPicker.select successfully, DocumentSelectResult uri: ' + JSON.stringify(DocumentSelectResult));  
    });  
  } catch (error) {  
    let err: BusinessError = error as BusinessError;  
    console.error('DocumentViewPicker failed with err: ' + JSON.stringify(err));  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function example07() {  
  try {  
    let DocumentSelectOptions = new picker.DocumentSelectOptions();  
    let documentPicker = new picker.DocumentViewPicker();  
    documentPicker.select(DocumentSelectOptions).then((DocumentSelectResult: Array<string>) => {  
      console.info('DocumentViewPicker.select successfully, DocumentSelectResult uri: ' + JSON.stringify(DocumentSelectResult));  
    }).catch((err: BusinessError) => {  
      console.error('DocumentViewPicker.select failed with err: ' + JSON.stringify(err));  
    });  
  } catch (error) {  
    let err: BusinessError = error as BusinessError;  
    console.error('DocumentViewPicker failed with err: ' + JSON.stringify(err));  
  }  
}  
    
```    
  
    
### save    
通过保存模式拉起documentPicker界面，用户可以保存一个或多个文件。传入可选参数DocumentSaveOptions对象，返回保存文件的uri数组。  
 **调用形式：**     
    
- save(option?: DocumentSaveOptions): Promise\<Array\<string>>    
起始版本： 9    
- save(option: DocumentSaveOptions, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 9    
- save(callback: AsyncCallback\<Array\<string>>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| option | DocumentSaveOptions | false | documentPicker保存选项，若无此参数，则拉起documentPicker界面后需用户自行输入保存的文件名 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback 返回documentPicker保存后的结果集 |  
| Promise<Array<string>> | Promise对象。返回documentPicker保存后的结果集 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function example11() {  
  try {  
    let DocumentSaveOptions = new picker.DocumentSaveOptions();  
    DocumentSaveOptions.newFileNames = ['DocumentViewPicker02.txt'];  
    let documentPicker = new picker.DocumentViewPicker();  
    documentPicker.save(DocumentSaveOptions, (err: BusinessError, DocumentSaveResult: Array<string>) => {  
      if (err) {  
        console.error('DocumentViewPicker.save failed with err: ' + JSON.stringify(err));  
        return;  
      }  
      console.info('DocumentViewPicker.save successfully, DocumentSaveResult uri: ' + JSON.stringify(DocumentSaveResult));  
    });  
  } catch (error) {  
    let err: BusinessError = error as BusinessError;  
    console.error('DocumentViewPicker failed with err: ' + JSON.stringify(err));  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function example10() {  
  try {  
    let DocumentSaveOptions = new picker.DocumentSaveOptions();  
    DocumentSaveOptions.newFileNames = ['DocumentViewPicker01.txt'];  
    let documentPicker = new picker.DocumentViewPicker();  
    documentPicker.save(DocumentSaveOptions).then((DocumentSaveResult: Array<string>) => {  
      console.info('DocumentViewPicker.save successfully, DocumentSaveResult uri: ' + JSON.stringify(DocumentSaveResult));  
    }).catch((err: BusinessError) => {  
      console.error('DocumentViewPicker.save failed with err: ' + JSON.stringify(err));  
    });  
  } catch (error) {  
    let err: BusinessError = error as BusinessError;  
    console.error('DocumentViewPicker failed with err: ' + JSON.stringify(err));  
  }  
}  
    
```    
  
    
## AudioSelectOptions    
音频选择选项，目前不支持参数配置。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
## AudioSaveOptions    
音频的保存选项。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| newFileNames | Array<string> | false | false | 拉起audioPicker进行保存音频资源的文件名，若无此参数，则默认需要用户自行输入 |  
    
## AudioViewPicker    
音频选择器对象，用来支撑选择和保存音频类文件等用户场景。在使用前，需要先创建AudioViewPicker实例。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
### select    
通过选择模式拉起audioPicker界面（目前拉起的是documentPicker，audioPicker在规划中），用户可以选择一个或多个音频文件。传入可选参数AudioSelectOptions对象，返回选择音频文件的uri数组。  
 **调用形式：**     
    
- select(option?: AudioSelectOptions): Promise\<Array\<string>>    
起始版本： 9    
- select(option: AudioSelectOptions, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 9    
- select(callback: AsyncCallback\<Array\<string>>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| option | AudioSelectOptions | false | audioPicker音频选择选项，若无此参数，则默认拉起audioPicker主界面 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback 返回audioPicker选择音频后的结果集 |  
| Promise<Array<string>> | Promise对象。返回audioPicker选择音频后的结果集 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function example14() {  
  try {  
    let AudioSelectOptions = new picker.AudioSelectOptions();  
    let audioPicker = new picker.AudioViewPicker();  
    audioPicker.select(AudioSelectOptions, (err: BusinessError, AudioSelectResult: Array<string>) => {  
      if (err) {  
        console.error('AudioViewPicker.select failed with err: ' + JSON.stringify(err));  
        return;  
      }  
      console.info('AudioViewPicker.select successfully, AudioSelectResult uri: ' + JSON.stringify(AudioSelectResult));  
    });  
  } catch (error) {  
    let err: BusinessError = error as BusinessError;  
    console.error('AudioViewPicker failed with err: ' + JSON.stringify(err));  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function example13() {  
  try {  
    let AudioSelectOptions = new picker.AudioSelectOptions();  
    let audioPicker = new picker.AudioViewPicker();  
    audioPicker.select(AudioSelectOptions).then((AudioSelectResult: Array<string>) => {  
      console.info('AudioViewPicker.select successfully, AudioSelectResult uri: ' + JSON.stringify(AudioSelectResult));  
    }).catch((err: BusinessError) => {  
      console.error('AudioViewPicker.select failed with err: ' + JSON.stringify(err));  
    });  
  } catch (error) {  
    let err: BusinessError = error as BusinessError;  
    console.error('AudioViewPicker failed with err: ' + JSON.stringify(err));  
  }  
}  
    
```    
  
    
### save    
通过保存模式拉起audioPicker界面（目前拉起的是documentPicker，audioPicker在规划中），用户可以保存一个或多个音频文件。传入可选参数AudioSaveOptions对象，返回保存音频文件的uri数组。  
 **调用形式：**     
    
- save(option?: AudioSaveOptions): Promise\<Array\<string>>    
起始版本： 9    
- save(option: AudioSaveOptions, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 9    
- save(callback: AsyncCallback\<Array\<string>>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| option | AudioSaveOptions | false | audioPicker保存音频文件选项，若无此参数，则拉起audioPicker界面后需用户自行输入保存的文件名 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback 返回audioPicker保存音频文件后的结果集 |  
| Promise<Array<string>> | Promise对象。返回audioPicker保存音频文件后的结果集 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function example17() {  
  try {  
    let AudioSaveOptions = new picker.AudioSaveOptions();  
    AudioSaveOptions.newFileNames = ['AudioViewPicker02.mp3'];  
    let audioPicker = new picker.AudioViewPicker();  
    audioPicker.save(AudioSaveOptions, (err: BusinessError, AudioSaveResult: Array<string>) => {  
      if (err) {  
        console.error('AudioViewPicker.save failed with err: ' + JSON.stringify(err));  
        return;  
      }  
      console.info('AudioViewPicker.save successfully, AudioSaveResult uri: ' + JSON.stringify(AudioSaveResult));  
    });  
  } catch (error) {  
    let err: BusinessError = error as BusinessError;  
    console.error('AudioViewPicker failed with err: ' + JSON.stringify(err));  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
async function example16() {  
  try {  
    let AudioSaveOptions = new picker.AudioSaveOptions();  
    AudioSaveOptions.newFileNames = ['AudioViewPicker01.mp3'];  
    let audioPicker = new picker.AudioViewPicker();  
    audioPicker.save(AudioSaveOptions).then((AudioSaveResult: Array<string>) => {  
      console.info('AudioViewPicker.save successfully, AudioSaveResult uri: ' + JSON.stringify(AudioSaveResult))  
    }).catch((err: BusinessError) => {  
      console.error('AudioViewPicker.save failed with err: ' + JSON.stringify(err));  
    });  
  } catch (error) {  
    let err: BusinessError = error as BusinessError;  
    console.error('AudioViewPicker failed with err: ' + JSON.stringify(err));  
  }  
}  
    
```    
  
