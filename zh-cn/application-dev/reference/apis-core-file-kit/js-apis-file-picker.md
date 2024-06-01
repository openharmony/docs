# @ohos.file.picker (选择器)

> **说明：**
>
> 该模块接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

选择器(Picker)是一个封装PhotoViewPicker、DocumentViewPicker、AudioViewPicker等API模块，具有选择与保存的能力。应用可以自行选择使用哪种API实现文件选择和文件保存的功能。该类接口，需要应用在界面UIAbility中调用，否则无法拉起photoPicker应用或FilePicker应用。

## 导入模块

```ts
import picker from '@ohos.file.picker';
```

## PhotoViewPicker

图库选择器对象，用来支撑选择图片/视频和保存图片/视频等用户场景。选择文件推荐使用[PhotoAccessHelper的PhotoViewPicker](../apis-media-library-kit/js-apis-photoAccessHelper.md#photoviewpicker)。在使用前，需要先创建PhotoViewPicker实例。

**系统能力**：SystemCapability.FileManagement.UserFileService

**示例：**

```ts
let photoPicker = new picker.PhotoViewPicker();
```

### select

select(option?: PhotoSelectOptions): Promise&lt;PhotoSelectResult&gt;

通过选择模式拉起photoPicker界面，用户可以选择一个或多个图片/视频。接口采用Promise异步返回形式，传入可选参数PhotoSelectOptions对象，返回PhotoSelectResult对象。

**注意**：此接口返回的PhotoSelectResult对象中的photoUris只能通过临时授权的方式调用[photoAccessHelper.getAssets接口](../apis-media-library-kit/js-apis-photoAccessHelper.md#getassets)去使用，具体使用方式参见用户文件uri介绍中的[媒体文件uri的使用方式](../../file-management/user-file-uri-intro.md#媒体文件uri的使用方式)。

**元服务API:** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](#photoselectoptions) | 否   | photoPicker选择选项，若无此参数，则默认选择媒体文件类型为图片和视频类型，选择媒体文件数量的默认最大值为50 |

**返回值：**

| 类型                            | 说明    |
| ----------------------------- | :---- |
| Promise&lt;[PhotoSelectResult](#photoselectresult)&gt; | Promise对象。返回photoPicker选择后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example01() {
  try {  
    let photoSelectOptions = new picker.PhotoSelectOptions();
    photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
    photoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.select(photoSelectOptions).then((photoSelectResult: picker.PhotoSelectResult) => {
      console.info('PhotoViewPicker.select successfully, photoSelectResult uri: ' + JSON.stringify(photoSelectResult));
    }).catch((err: BusinessError) => {
      console.error('PhotoViewPicker.select failed with err: ' + JSON.stringify(err));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### select

select(option: PhotoSelectOptions, callback: AsyncCallback&lt;PhotoSelectResult&gt;): void

通过选择模式拉起photoPicker界面，用户可以选择一个或多个图片/视频。接口采用callback异步返回形式，传入参数PhotoSelectOptions对象，返回PhotoSelectResult对象。

**注意**：此接口返回的PhotoSelectResult对象中的photoUris只能通过临时授权的方式调用[photoAccessHelper.getAssets接口](../apis-media-library-kit/js-apis-photoAccessHelper.md#getassets)去使用，具体使用方式参见用户文件uri介绍中的[媒体文件uri的使用方式](../../file-management/user-file-uri-intro.md#媒体文件uri的使用方式)。

**元服务API:** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](#photoselectoptions) | 是   | photoPicker选择选项 |
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresult)&gt;      | 是   | callback 返回photoPicker选择后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example02() {
  try {
    let photoSelectOptions = new picker.PhotoSelectOptions();
    photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
    photoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.select(photoSelectOptions, (err: BusinessError, photoSelectResult: picker.PhotoSelectResult) => {
      if (err) {
        console.error('PhotoViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('PhotoViewPicker.select successfully, photoSelectResult uri: ' + JSON.stringify(photoSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### select

select(callback: AsyncCallback&lt;PhotoSelectResult&gt;): void

通过选择模式拉起photoPicker界面，用户可以选择一个或多个图片/视频。接口采用callback异步返回形式，返回PhotoSelectResult对象。

**注意**：此接口返回的PhotoSelectResult对象中的photoUris只能通过临时授权的方式调用[photoAccessHelper.getAssets接口](../apis-media-library-kit/js-apis-photoAccessHelper.md#getassets)去使用，具体使用方式参见用户文件uri介绍中的[媒体文件uri的使用方式](../../file-management/user-file-uri-intro.md#媒体文件uri的使用方式)。

**元服务API:** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresult)&gt;      | 是   | callback 返回photoPicker选择后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example03() {
  try {
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.select((err: BusinessError, photoSelectResult: picker.PhotoSelectResult) => {
      if (err) {
        console.error('PhotoViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('PhotoViewPicker.select successfully, photoSelectResult uri: ' + JSON.stringify(photoSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save

save(option?: PhotoSaveOptions): Promise&lt;Array&lt;string&gt;&gt;

通过保存模式拉起photoPicker界面，用户可以保存一个或多个图片/视频。接口采用Promise异步返回形式，传入可选参数PhotoSaveOptions对象，返回保存文件的uri数组。

**注意**：此接口会将文件保存在文件管理器，而不是图库。返回的uri数组的具体使用方式参见用户文件uri介绍中的[文档类uri的使用方式](../../file-management/user-file-uri-intro.md#文档类uri的使用方式)。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSaveOptions](#photosaveoptions) | 否   | photoPicker保存图片或视频文件选项，若无此参数，则拉起photoPicker界面后需用户自行输入保存的文件名 |

**返回值：**

| 类型                            | 说明    |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象。返回photoPicker保存图片或视频文件后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example04() {
  try {
    let photoSaveOptions = new picker.PhotoSaveOptions();
    photoSaveOptions.newFileNames = ['PhotoViewPicker01.jpg', 'PhotoViewPicker01.mp4'];
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.save(photoSaveOptions).then((photoSaveResult: Array<string>) => {
      console.info('PhotoViewPicker.save successfully, photoSaveResult uri: ' + JSON.stringify(photoSaveResult));
    }).catch((err: BusinessError) => {
      console.error('PhotoViewPicker.save failed with err: ' + JSON.stringify(err));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
      console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save

save(option: PhotoSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

通过保存模式拉起photoPicker界面，用户可以保存一个或多个图片/视频。接口采用callback异步返回形式，传入参数PhotoSaveOptions对象，返回保存文件的uri数组。

**注意**：此接口会将文件保存在文件管理器，而不是图库。返回的uri数组的具体使用方式参见用户文件uri介绍中的[文档类uri的使用方式](../../file-management/user-file-uri-intro.md#文档类uri的使用方式)。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSaveOptions](#photosaveoptions) | 是   | photoPicker保存图片或视频文件选项 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回photoPicker保存图片或视频文件后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example05() {
  try {
    let photoSaveOptions = new picker.PhotoSaveOptions();
    photoSaveOptions.newFileNames = ['PhotoViewPicker02.jpg','PhotoViewPicker02.mp4'];
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.save(photoSaveOptions, (err: BusinessError, photoSaveResult: Array<string>) => {
      if (err) {
        console.error('PhotoViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('PhotoViewPicker.save successfully, photoSaveResult uri: ' + JSON.stringify(photoSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save

save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

通过保存模式拉起photoPicker界面，用户可以保存一个或多个图片/视频。接口采用callback异步返回形式，返回保存文件的uri数组。

**注意**：此接口会将文件保存在文件管理器，而不是图库。返回的uri数组的具体使用方式参见用户文件uri介绍中的[文档类uri的使用方式](../../file-management/user-file-uri-intro.md#文档类uri的使用方式)。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回photoPicker保存图片或视频文件后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example06() {
  try {
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.save((err: BusinessError, photoSaveResult: Array<string>) => {
      if (err) {
        console.error('PhotoViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('PhotoViewPicker.save successfully, photoSaveResult uri: ' + JSON.stringify(photoSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

## DocumentViewPicker

文件选择器对象，用来支撑选择和保存各种格式文档。在使用前，需要先创建DocumentViewPicker实例。

**系统能力**：SystemCapability.FileManagement.UserFileService

**示例：**

```ts
let documentPicker = new picker.DocumentViewPicker();
```

### select

select(option?: DocumentSelectOptions): Promise&lt;Array&lt;string&gt;&gt;

通过选择模式拉起documentPicker界面，用户可以选择一个或多个文件。接口采用Promise异步返回形式，传入可选参数DocumentSelectOptions对象，返回选择文件的uri数组。

**注意**：此接口返回的uri数组的具体使用方式参见用户文件uri介绍中的[文档类uri的使用方式](../../file-management/user-file-uri-intro.md#文档类uri的使用方式)。

**元服务API:** 从API version 12开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSelectOptions](#documentselectoptions) | 否   | documentPicker选择选项，若无此参数，则默认拉起documentPicker主界面 |

**返回值：**

| 类型                            | 说明    |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象。返回documentPicker选择后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example07() {
  try {
    let documentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.select(documentSelectOptions).then((documentSelectResult: Array<string>) => {
      console.info('DocumentViewPicker.select successfully, documentSelectResult uri: ' + JSON.stringify(documentSelectResult));
    }).catch((err: BusinessError) => {
      console.error('DocumentViewPicker.select failed with err: ' + JSON.stringify(err));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('DocumentViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### select

select(option: DocumentSelectOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

通过选择模式拉起documentPicker界面，用户可以选择一个或多个文件。接口采用callback异步返回形式，传入参数DocumentSelectOptions对象，返回选择文件的uri数组。

**注意**：此接口返回的uri数组的具体使用方式参见用户文件uri介绍中的[文档类uri的使用方式](../../file-management/user-file-uri-intro.md#文档类uri的使用方式)。

**元服务API:** 从API version 12开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSelectOptions](#documentselectoptions) | 是   | documentPicker选择选项 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回documentPicker选择后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example08() {
  try {
    let documentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.select(documentSelectOptions, (err: BusinessError, documentSelectResult: Array<string>) => {
      if (err) {
        console.error('DocumentViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('DocumentViewPicker.select successfully, documentSelectResult uri: ' + JSON.stringify(documentSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('DocumentViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### select

select(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

通过选择模式拉起documentPicker界面，用户可以选择一个或多个文件。接口采用callback异步返回形式，返回选择文件的uri数组。

**注意**：此接口返回的uri数组的具体使用方式参见用户文件uri介绍中的[文档类uri的使用方式](../../file-management/user-file-uri-intro.md#文档类uri的使用方式)。

**元服务API:** 从API version 12开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回documentPicker选择后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example09() {
  try {
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.select((err: BusinessError, documentSelectResult: Array<string>) => {
      if (err) {
        console.error('DocumentViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('DocumentViewPicker.select successfully, documentSelectResult uri: ' + JSON.stringify(documentSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('DocumentViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save

save(option?: DocumentSaveOptions): Promise&lt;Array&lt;string&gt;&gt;

通过保存模式拉起documentPicker界面，用户可以保存一个或多个文件。接口采用Promise异步返回形式，传入可选参数DocumentSaveOptions对象，返回保存文件的uri数组。

**注意**：此接口返回的uri数组的具体使用方式参见用户文件uri介绍中的[文档类uri的使用方式](../../file-management/user-file-uri-intro.md#文档类uri的使用方式)。

**元服务API:** 从API version 12开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSaveOptions](#documentsaveoptions) | 否   | documentPicker保存选项，若无此参数，则拉起documentPicker界面后需用户自行输入保存的文件名 |

**返回值：**

| 类型                            | 说明    |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象。返回documentPicker保存后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example10() {
  try {
    let documentSaveOptions = new picker.DocumentSaveOptions();
    documentSaveOptions.newFileNames = ['DocumentViewPicker01.txt'];
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.save(documentSaveOptions).then((documentSaveResult: Array<string>) => {
      console.info('DocumentViewPicker.save successfully, documentSaveResult uri: ' + JSON.stringify(documentSaveResult));
    }).catch((err: BusinessError) => {
      console.error('DocumentViewPicker.save failed with err: ' + JSON.stringify(err));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('DocumentViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save

save(option: DocumentSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

通过保存模式拉起documentPicker界面，用户可以保存一个或多个文件。接口采用callback异步返回形式，传入参数DocumentSaveOptions对象，返回保存文件的uri数组。

**注意**：此接口返回的uri数组的具体使用方式参见用户文件uri介绍中的[文档类uri的使用方式](../../file-management/user-file-uri-intro.md#文档类uri的使用方式)。

**元服务API:** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSaveOptions](#documentsaveoptions) | 是   | documentPicker保存选项 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回documentPicker保存后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example11() {
  try {
    let documentSaveOptions = new picker.DocumentSaveOptions();
    documentSaveOptions.newFileNames = ['DocumentViewPicker02.txt'];
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.save(documentSaveOptions, (err: BusinessError, documentSaveResult: Array<string>) => {
      if (err) {
        console.error('DocumentViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('DocumentViewPicker.save successfully, documentSaveResult uri: ' + JSON.stringify(documentSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('DocumentViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save

save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

通过保存模式拉起documentPicker界面，用户可以保存一个或多个文件。接口采用callback异步返回形式，返回保存文件的uri数组。

**注意**：此接口返回的uri数组的具体使用方式参见用户文件uri介绍中的[文档类uri的使用方式](../../file-management/user-file-uri-intro.md#文档类uri的使用方式)。

**元服务API:** 从API version 12开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回documentPicker保存后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example12() {
  try {
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.save((err: BusinessError, documentSaveResult: Array<string>) => {
      if (err) {
        console.error('DocumentViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('DocumentViewPicker.save successfully, documentSaveResult uri: ' + JSON.stringify(documentSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('DocumentViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

## AudioViewPicker

音频选择器对象，用来支撑选择和保存音频类文件等用户场景。在使用前，需要先创建AudioViewPicker实例。

**系统能力**：SystemCapability.FileManagement.UserFileService

**示例：**

```ts
let audioPicker = new picker.AudioViewPicker();
```

### select

select(option?: AudioSelectOptions): Promise&lt;Array&lt;string&gt;&gt;

通过选择模式拉起audioPicker界面（目前拉起的是documentPicker，audioPicker在规划中），用户可以选择一个或多个音频文件。接口采用Promise异步返回形式，传入可选参数AudioSelectOptions对象，返回选择音频文件的uri数组。

**注意**：此接口返回的uri数组的具体使用方式参见用户文件uri介绍中的[文档类uri的使用方式](../../file-management/user-file-uri-intro.md#文档类uri的使用方式)。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSelectOptions](#audioselectoptions) | 否   | audioPicker音频选择选项，若无此参数，则默认拉起audioPicker主界面  |

**返回值：**

| 类型                            | 说明    |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象。返回audioPicker选择音频后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example13() {
  try {
    let audioSelectOptions = new picker.AudioSelectOptions();
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.select(audioSelectOptions).then((audioSelectResult: Array<string>) => {
      console.info('AudioViewPicker.select successfully, audioSelectResult uri: ' + JSON.stringify(audioSelectResult));
    }).catch((err: BusinessError) => {
      console.error('AudioViewPicker.select failed with err: ' + JSON.stringify(err));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('AudioViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### select

select(option: AudioSelectOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

通过选择模式拉起audioPicker界面（目前拉起的是documentPicker，audioPicker在规划中），用户可以选择一个或多个音频文件。接口采用callback异步返回形式，传入参数AudioSelectOptions对象，返回选择音频文件的uri数组。

**注意**：此接口返回的uri数组的具体使用方式参见用户文件uri介绍中的[文档类uri的使用方式](../../file-management/user-file-uri-intro.md#文档类uri的使用方式)。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSelectOptions](#audioselectoptions) | 是   | audioPicker音频选择选项 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回audioPicker选择音频后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example14() {
  try {
    let audioSelectOptions = new picker.AudioSelectOptions();
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.select(audioSelectOptions, (err: BusinessError, audioSelectResult: Array<string>) => {
      if (err) {
        console.error('AudioViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('AudioViewPicker.select successfully, audioSelectResult uri: ' + JSON.stringify(audioSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('AudioViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### select

select(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

通过选择模式拉起audioPicker界面（目前拉起的是documentPicker，audioPicker在规划中），用户可以选择一个或多个音频文件。接口采用callback异步返回形式，返回选择音频文件的uri数组。

**注意**：此接口返回的uri数组的具体使用方式参见用户文件uri介绍中的[文档类uri的使用方式](../../file-management/user-file-uri-intro.md#文档类uri的使用方式)。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回audioPicker选择音频后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example15() {
  try {
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.select((err: BusinessError, audioSelectResult: Array<string>) => {
      if (err) {
        console.error('AudioViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('AudioViewPicker.select successfully, audioSelectResult uri: ' + JSON.stringify(audioSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('AudioViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save

save(option?: AudioSaveOptions): Promise&lt;Array&lt;string&gt;&gt;

通过保存模式拉起audioPicker界面（目前拉起的是documentPicker，audioPicker在规划中），用户可以保存一个或多个音频文件。接口采用Promise异步返回形式，传入可选参数AudioSaveOptions对象，返回保存音频文件的uri数组。

**注意**：此接口返回的uri数组的具体使用方式参见用户文件uri介绍中的[文档类uri的使用方式](../../file-management/user-file-uri-intro.md#文档类uri的使用方式)。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSaveOptions](#audiosaveoptions) | 否   | audioPicker保存音频文件选项，若无此参数，则拉起audioPicker界面后需用户自行输入保存的文件名 |

**返回值：**

| 类型                            | 说明    |
| ----------------------------- | ---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象。返回audioPicker保存音频文件后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example16() {
  try {
    let audioSaveOptions = new picker.AudioSaveOptions();
    audioSaveOptions.newFileNames = ['AudioViewPicker01.mp3'];
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.save(audioSaveOptions).then((audioSaveResult: Array<string>) => {
      console.info('AudioViewPicker.save successfully, audioSaveResult uri: ' + JSON.stringify(audioSaveResult))
    }).catch((err: BusinessError) => {
      console.error('AudioViewPicker.save failed with err: ' + JSON.stringify(err));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('AudioViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save

save(option: AudioSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

通过保存模式拉起audioPicker界面（目前拉起的是documentPicker，audioPicker在规划中），用户可以保存一个或多个音频文件。接口采用callback异步返回形式，传入参数AudioSaveOptions对象，返回保存音频文件的uri数组。

**注意**：此接口返回的uri数组的具体使用方式参见用户文件uri介绍中的[文档类uri的使用方式](../../file-management/user-file-uri-intro.md#文档类uri的使用方式)。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSaveOptions](#audiosaveoptions) | 是   | audioPicker保存音频文件选项 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回audioPicker保存音频文件后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example17() {
  try {
    let audioSaveOptions = new picker.AudioSaveOptions();
    audioSaveOptions.newFileNames = ['AudioViewPicker02.mp3'];
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.save(audioSaveOptions, (err: BusinessError, audioSaveResult: Array<string>) => {
      if (err) {
        console.error('AudioViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('AudioViewPicker.save successfully, audioSaveResult uri: ' + JSON.stringify(audioSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('AudioViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save

save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

通过保存模式拉起audioPicker界面（目前拉起的是documentPicker，audioPicker在规划中），用户可以保存一个或多个音频文件。接口采用callback异步返回形式，返回保存音频文件的uri数组。

**注意**：此接口返回的uri数组的具体使用方式参见用户文件uri介绍中的[文档类uri的使用方式](../../file-management/user-file-uri-intro.md#文档类uri的使用方式)。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回audioPicker保存音频文件后的结果集 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example18() {
  try {
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.save((err: BusinessError, audioSaveResult: Array<string>) => {
      if (err) {
        console.error('AudioViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('AudioViewPicker.save successfully, audioSaveResult uri: ' + JSON.stringify(audioSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('AudioViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

## PhotoViewMIMETypes

枚举，可选择的媒体文件类型。

**系统能力：** SystemCapability.FileManagement.UserFileService

| 名称  |  值 |  说明 |
| ----- |  ---- | ---- |
| IMAGE_TYPE  |  'image/*' | 图片类型 <br>**元服务API:** 从API version 11开始，该接口支持在元服务中使用。 |
| VIDEO_TYPE |  'video/*' | 视频类型 <br>**元服务API:** 从API version 11开始，该接口支持在元服务中使用。 |
| IMAGE_VIDEO_TYPE |  '\*/*' | 图片和视频类型 <br>**元服务API:** 从API version 11开始，该接口支持在元服务中使用。 |

## PhotoSelectOptions

图库选择选项。

**系统能力：** SystemCapability.FileManagement.UserFileService

| 名称                    | 类型                | 必填 | 说明                          |
| ----------------------- | ------------------- | ---- | -------------------------------- |
| MIMEType              | [PhotoViewMIMETypes](#photoviewmimetypes)   | 否   | 可选择的媒体文件类型，若无此参数，则默认为图片和视频类型 <br>**元服务API:** 从API version 11开始，该接口支持在元服务中使用。 |
| maxSelectNumber       | number | 否   | 选择媒体文件数量的最大值(默认值为50，最大值为500)     <br>**元服务API:** 从API version 11开始，该接口支持在元服务中使用。 |

## PhotoSelectResult

返回图库选择后的结果集。

**系统能力：** SystemCapability.FileManagement.UserFileService

| 名称                    | 类型                | 只读 | 可写 | 说明                           |
| ----------------------- | ------------------- | ---- | ---- | ------------------------------ |
| photoUris        | Array&lt;string&gt;    | 是   | 是   | 返回图库选择后的媒体文件的uri数组，此uri数组只能通过临时授权的方式调用[photoAccessHelper.getAssets接口](../apis-media-library-kit/js-apis-photoAccessHelper.md#getassets)去使用，具体使用方式参见用户文件uri介绍中的[媒体文件uri的使用方式](../../file-management/user-file-uri-intro.md#媒体文件uri的使用方式)。 <br>**元服务API:** 从API version 11开始，该接口支持在元服务中使用。 |
| isOriginalPhoto        | boolean    | 是   | 是   | 返回图库选择后的媒体文件是否为原图。true为原图，false不是原图。 <br>**元服务API:** 从API version 11开始，该接口支持在元服务中使用。 |

## PhotoSaveOptions

图片或视频的保存选项。

**系统能力：** SystemCapability.FileManagement.UserFileService

| 名称                    | 类型                | 必填 |  说明                           |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames              | Array&lt;string&gt;    | 否  | 拉起photoPicker进行保存图片或视频资源的文件名，若无此参数，则默认需要用户自行输入 |

## DocumentSelectMode<sup>11+</sup>

枚举，picker选择的文档类型。

**系统能力：** SystemCapability.FileManagement.UserFileService.FolderSelection

| 名称  |  值 |  说明 |
| ----- |  ---- | ---- |
| FILE  | 0  | 文件类型 <br>**元服务API:** 从API version 12开始，该接口支持在元服务中使用。 |
| FOLDER | 1  | 文件夹类型 <br>**元服务API:** 从API version 12开始，该接口支持在元服务中使用。 |
| MIXED | 2  | 文件和文件夹混合类型 <br>**元服务API:** 从API version 12开始，该接口支持在元服务中使用。 |

## DocumentSelectOptions

文档选择选项。

**系统能力：** SystemCapability.FileManagement.UserFileService

| 名称                    | 类型                                          | 必填 | 说明                                       |
| :---------------------- |---------------------------------------------| ---- |------------------------------------------|
| maxSelectNumber<sup>10+</sup>       | number                                      | 否   | 选择文件最大个数，上限500，有效值范围1-500（选择目录仅对具有该系统能力的设备开放。且目录选择的最大个数为1）。默认值是1。**系统能力：** SystemCapability.FileManagement.UserFileService.FolderSelection <br>**元服务API:** 从API version 12开始，该接口支持在元服务中使用。 |
| defaultFilePathUri<sup>10+</sup>    | string                                      | 否   | 指定选择的文件或者目录路径                           <br>**元服务API:** 从API version 12开始，该接口支持在元服务中使用。 |
| fileSuffixFilters<sup>10+</sup>     | Array&lt;string&gt;                         | 否   | 选择文件的后缀类型，若选择项存在多个后缀名，则每一个后缀名之间用英文逗号进行分隔，后缀类型名添加不能超过100。仅对具有该系统能力的设备开放。**系统能力：** SystemCapability.FileManagement.UserFileService.FolderSelection  <br>**元服务API:** 从API version 12开始，该接口支持在元服务中使用。 |
| selectMode<sup>11+</sup>         | [DocumentSelectMode](#documentselectmode11) | 否   | 支持选择的资源类型，比如：文件、文件夹和二者混合，仅对具有该系统能力的设备开放，默认值是文件类型。**系统能力：** SystemCapability.FileManagement.UserFileService.FolderSelection <br>**元服务API:** 从API version 12开始，该接口支持在元服务中使用。 |
| authMode<sup>12+</sup>    | boolean                              | 否   | 拉起授权picker，默认为false（非授权模式）。当authMode为true时为授权模式，defaultFilePathUri必填，表明待授权uri。仅对具有该系统能力的设备开放，**系统能力：** SystemCapability.FileManagement.UserFileService.FolderSelection <br>**元服务API:** 从API version 12开始，该接口支持在元服务中使用。 |     

## DocumentPickerMode<sup>12+</sup>

枚举，picker选择的文档类型。

**系统能力：** SystemCapability.FileManagement.UserFileService.FolderSelection

| 名称  |  值 |  说明 |
| ----- |  ---- | ---- |
| DEFAULT  | 0  | 标准模式 |
| DOWNLOAD | 1  | 下载模式 |

## DocumentSaveOptions

文档保存选项。

**系统能力：** SystemCapability.FileManagement.UserFileService

| 名称                    | 类型                | 必填 |  说明                           |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames            | Array&lt;string&gt;    | 否   | 拉起documentPicker进行保存的文件名，若无此参数，则默认需要用户自行输入 <br>**元服务API:** 从API version 12开始，该接口支持在元服务中使用。 |
| defaultFilePathUri<sup>10+</sup>    | string  | 否   | 指定保存的文件或者目录路径 <br>**元服务API:** 从API version 12开始，该接口支持在元服务中使用。 |
| fileSuffixChoices<sup>10+</sup>     | Array&lt;string&gt; | 否   | 保存文件的后缀类型 <br>**元服务API:** 从API version 12开始，该接口支持在元服务中使用。 |
| pickerMode     |  [DocumentPickerMode](#documentPickerMode) | 否   | 拉起picker的类型, 默认为DEFAULT。当pickerMode设置为DOWNLOAD时，用户配置的参数newFileNames、defaultFilePathUri和fileSuffixChoices将不会生效 |

## AudioSelectOptions

音频选择选项。

**系统能力：** SystemCapability.FileManagement.UserFileService
| 名称                    | 类型                                          | 必填 | 说明                                       |
| :---------------------- |---------------------------------------------| ---- |------------------------------------------|
| maxSelectNumber       | number                                      | 否   | 选择文件最大个数，上限500，有效值范围1-500 |

## AudioSaveOptions

音频的保存选项。

**系统能力：** SystemCapability.FileManagement.UserFileService

| 名称                    | 类型                | 必填 |  说明                           |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames              | Array&lt;string&gt;    | 否  | 拉起audioPicker进行保存音频资源的文件名，若无此参数，则默认需要用户自行输入 |
