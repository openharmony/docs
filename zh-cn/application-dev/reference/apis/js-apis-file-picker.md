# @ohos.file.picker (选择器)

> **说明：**
>
> 该模块接口从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

选择器(Picker)是一个封装PhotoViewPicker、DocumentViewPicker、AudioViewPicker等系统应用选择与保存能力的模块。应用可以自行选择使用哪种picker实现文件选择和文件保存的功能。

## 导入模块

```js
import picker from '@ohos.file.picker';
```

## PhotoViewPicker

图库选择器对象，用来支撑选择图片/视频和保存图片/视频等用户场景。在使用前，需要先创建PhotoViewPicker实例。

**系统能力**：SystemCapability.FileManagement.UserFileService

**示例：**

```ts
let photoPicker = new picker.PhotoViewPicker();
```

### select

select(option?: PhotoSelectOptions) : Promise&lt;PhotoSelectResult&gt;

通过选择模式拉起photoPicker界面，用户可以选择一个或多个图片/视频。接口采用promise异步返回形式，传入可选参数PhotoSelectOptions对象，返回PhotoSelectResult对象。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](#photoselectoptions) | 否   | photoPicker选择选项，若无此参数，则默认选择媒体文件类型为图片和视频类型，选择媒体文件数量的最大值为50 |

**返回值：**

| 类型                            | 说明    |
| ----------------------------- | :---- |
| Promise&lt;[PhotoSelectResult](#photoselectresult)&gt; | Promise对象。返回photoPicker选择后的结果集 |

**示例：**

```ts
async function example() {
  try {  
    let PhotoSelectOptions = new picker.PhotoSelectOptions();
    PhotoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
    PhotoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.select(PhotoSelectOptions).then((PhotoSelectResult) => {
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));
    }).catch((err) => {
      console.error('PhotoViewPicker.select failed with err: ' + err);
    });
  } catch (err) {
    console.error('PhotoViewPicker failed with err: ' + err);
  }
}
```

### select

select(option: PhotoSelectOptions, callback: AsyncCallback&lt;PhotoSelectResult&gt;) : void

通过选择模式拉起photoPicker界面，用户可以选择一个或多个图片/视频。接口采用callback异步返回形式，传入参数PhotoSelectOptions对象，返回PhotoSelectResult对象。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](#photoselectoptions) | 是   | photoPicker选择选项 |
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresult)&gt;      | 是   | callback 返回photoPicker选择后的结果集 |

**示例：**

```ts
async function example() {
  try {   
    let PhotoSelectOptions = new picker.PhotoSelectOptions();
    PhotoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
    PhotoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.select(PhotoSelectOptions, (err, PhotoSelectResult) => {
      if (err) {
        console.error('PhotoViewPicker.select failed with err: ' + err);
        return;
      }
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));
    });
  } catch (err) {
    console.error('PhotoViewPicker failed with err: ' + err);
  }
}
```

### select

select(callback: AsyncCallback&lt;PhotoSelectResult&gt;) : void

通过选择模式拉起photoPicker界面，用户可以选择一个或多个图片/视频。接口采用callback异步返回形式，返回PhotoSelectResult对象。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresult)&gt;      | 是   | callback 返回photoPicker选择后的结果集 |

**示例：**

```ts
async function example() {
  try {   
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.select((err, PhotoSelectResult) => {
      if (err) {
        console.error('PhotoViewPicker.select failed with err: ' + err);
        return;
      }
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));
    });
  } catch (err) {
    console.error('PhotoViewPicker failed with err: ' + err);
  }
}
```

### save

save(option?: PhotoSaveOptions) : Promise&lt;Array&lt;string&gt;&gt;

通过保存模式拉起photoPicker界面，用户可以保存一个或多个图片/视频。接口采用promise异步返回形式，传入可选参数PhotoSaveOptions对象，返回保存文件的uri数组。

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
async function example() {
  try {   
    let PhotoSaveOptions = new picker.PhotoSaveOptions();
    PhotoSaveOptions.newFileNames = ['PhotoViewPicker01.jpg', 'PhotoViewPicker01.mp4'];
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.save(PhotoSaveOptions).then((PhotoSaveResult) => {
      console.info('PhotoViewPicker.save successfully, PhotoSaveResult uri: ' + JSON.stringify(PhotoSaveResult));
    }).catch((err) => {
      console.error('PhotoViewPicker.save failed with err: ' + err);
    });
  } catch (err) {
      console.error('PhotoViewPicker failed with err: ' + err);
  }
}
```

### save

save(option: PhotoSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

通过保存模式拉起photoPicker界面，用户可以保存一个或多个图片/视频。接口采用callback异步返回形式，传入参数PhotoSaveOptions对象，返回保存文件的uri数组。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSaveOptions](#photosaveoptions) | 是   | photoPicker保存图片或视频文件选项 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回photoPicker保存图片或视频文件后的结果集 |

**示例：**

```ts
async function example() {
  try {
    let PhotoSaveOptions = new picker.PhotoSaveOptions();
    PhotoSaveOptions.newFileNames = ['PhotoViewPicker02.jpg','PhotoViewPicker02.mp4'];
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.save(PhotoSaveOptions, (err, PhotoSaveResult) => {
      if (err) {
        console.error('PhotoViewPicker.save failed with err: ' + err);
        return;
      }
      console.info('PhotoViewPicker.save successfully, PhotoSaveResult uri: ' + JSON.stringify(PhotoSaveResult));
    });
  } catch (err) {
    console.error('PhotoViewPicker failed with err: ' + err);
  }
}
```

### save

save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

通过保存模式拉起photoPicker界面，用户可以保存一个或多个图片/视频。接口采用callback异步返回形式，返回保存文件的uri数组。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回photoPicker保存图片或视频文件后的结果集 |

**示例：**

```ts
async function example() {
  try {
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.save((err, PhotoSaveResult) => {
      if (err) {
        console.error('PhotoViewPicker.save failed with err: ' + err);
        return;
      }
      console.info('PhotoViewPicker.save successfully, PhotoSaveResult uri: ' + JSON.stringify(PhotoSaveResult));
    });
  } catch (err) {
    console.error('PhotoViewPicker failed with err: ' + err);
  }
}
```

## DocumentViewPicker

文件选择器对象，用来支撑选择和保存非媒体文件等用户场景，比如各种格式文档。在使用前，需要先创建DocumentViewPicker实例。

**系统能力**：SystemCapability.FileManagement.UserFileService

**示例：**

```ts
let documentPicker = new picker.DocumentViewPicker();
```

### select

select(option?: DocumentSelectOptions) : Promise&lt;Array&lt;string&gt;&gt;

通过选择模式拉起documentPicker界面，用户可以选择一个或多个文件。接口采用promise异步返回形式，传入可选参数DocumentSelectOptions对象，返回选择文件的uri数组。

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
async function example() {
  try {
    let DocumentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.select(DocumentSelectOptions).then((DocumentSelectResult) => {
      console.info('DocumentViewPicker.select successfully, DocumentSelectResult uri: ' + JSON.stringify(DocumentSelectResult));
    }).catch((err) => {
      console.error('DocumentViewPicker.select failed with err: ' + err);
    });
  } catch (err) {
    console.error('DocumentViewPicker failed with err: ' + err);
  }
}
```

### select

select(option: DocumentSelectOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

通过选择模式拉起documentPicker界面，用户可以选择一个或多个文件。接口采用callback异步返回形式，传入参数DocumentSelectOptions对象，返回选择文件的uri数组。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSelectOptions](#documentselectoptions) | 是   | documentPicker选择选项 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回documentPicker选择后的结果集 |

**示例：**

```ts
async function example() {
  try {
    let DocumentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.select(DocumentSelectOptions, (err, DocumentSelectResult) => {
      if (err) {
        console.error('DocumentViewPicker.select failed with err: ' + err);
        return;
      }
      console.info('DocumentViewPicker.select successfully, DocumentSelectResult uri: ' + JSON.stringify(DocumentSelectResult));
    });
  } catch (err) {
    console.error('DocumentViewPicker failed with err: ' + err);
  }
}
```

### select

select(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

通过选择模式拉起documentPicker界面，用户可以选择一个或多个文件。接口采用callback异步返回形式，返回选择文件的uri数组。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回documentPicker选择后的结果集 |

**示例：**

```ts
async function example() {
  try {
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.select((err, DocumentSelectResult) => {
      if (err) {
        console.error('DocumentViewPicker.select failed with err: ' + err);
        return;
      }
      console.info('DocumentViewPicker.select successfully, DocumentSelectResult uri: ' + JSON.stringify(DocumentSelectResult));
    });
  } catch (err) {
    console.error('DocumentViewPicker failed with err: ' + err);
  }
}
```


### save

save(option?: DocumentSaveOptions) : Promise&lt;Array&lt;string&gt;&gt;

通过保存模式拉起documentPicker界面，用户可以保存一个或多个文件。接口采用promise异步返回形式，传入可选参数DocumentSaveOptions对象，返回保存文件的uri数组。

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
async function example() {
  try {
    let DocumentSaveOptions = new picker.DocumentSaveOptions();
    DocumentSaveOptions.newFileNames = ['DocumentViewPicker01.txt'];
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.save(DocumentSaveOptions).then((DocumentSaveResult) => {
      console.info('DocumentViewPicker.save successfully, DocumentSaveResult uri: ' + JSON.stringify(DocumentSaveResult));
    }).catch((err) => {
      console.error('DocumentViewPicker.save failed with err: ' + err);
    });
  } catch (err) {
    console.error('DocumentViewPicker failed with err: ' + err);
  }
}
```

### save

save(option: DocumentSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

通过保存模式拉起documentPicker界面，用户可以保存一个或多个文件。接口采用callback异步返回形式，传入参数DocumentSaveOptions对象，返回保存文件的uri数组。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSaveOptions](#documentsaveoptions) | 是   | documentPicker保存选项 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回documentPicker保存后的结果集 |

**示例：**

```ts
async function example() {
  try {
    let DocumentSaveOptions = new picker.DocumentSaveOptions();
    DocumentSaveOptions.newFileNames = ['DocumentViewPicker02.txt'];
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.save(DocumentSaveOptions, (err, DocumentSaveResult) => {
      if (err) {
        console.error('DocumentViewPicker.save failed with err: ' + err);
        return;
      }
      console.info('DocumentViewPicker.save successfully, DocumentSaveResult uri: ' + JSON.stringify(DocumentSaveResult));
    });
  } catch (err) {
    console.error('DocumentViewPicker failed with err: ' + err);
  }
}
```

### save

save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

通过保存模式拉起documentPicker界面，用户可以保存一个或多个文件。接口采用callback异步返回形式，返回保存文件的uri数组。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回documentPicker保存后的结果集 |

**示例：**

```ts
async function example() {
  try {
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.save((err, DocumentSaveResult) => {
      if (err) {
        console.error('DocumentViewPicker.save failed with err: ' + err);
        return;
      }
      console.info('DocumentViewPicker.save successfully, DocumentSaveResult uri: ' + JSON.stringify(DocumentSaveResult));
    });
  } catch (err) {
    console.error('DocumentViewPicker failed with err: ' + err);
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

select(option?: AudioSelectOptions) : Promise&lt;Array&lt;string&gt;&gt;

通过选择模式拉起audioPicker界面（目前拉起的是documentPicker，audioPicker在规划中），用户可以选择一个或多个音频文件。接口采用promise异步返回形式，传入可选参数AudioSelectOptions对象，返回选择音频文件的uri数组。

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
async function example() {
  try {
    let AudioSelectOptions = new picker.AudioSelectOptions();
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.select(AudioSelectOptions).then((AudioSelectResult) => {
      console.info('AudioViewPicker.select successfully, AudioSelectResult uri: ' + JSON.stringify(AudioSelectResult));
    }).catch((err) => {
      console.error('AudioViewPicker.select failed with err: ' + err);
    });
  } catch (err) {
    console.error('AudioViewPicker failed with err: ' + err);
  }
}
```

### select

select(option: AudioSelectOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

通过选择模式拉起audioPicker界面（目前拉起的是documentPicker，audioPicker在规划中），用户可以选择一个或多个音频文件。接口采用callback异步返回形式，传入参数AudioSelectOptions对象，返回选择音频文件的uri数组。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSelectOptions](#audioselectoptions) | 是   | audioPicker音频选择选项 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回audioPicker选择音频后的结果集 |

**示例：**

```ts
async function example() {
  try {
    let AudioSelectOptions = new picker.AudioSelectOptions();
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.select(AudioSelectOptions, (err, AudioSelectResult) => {
      if (err) {
        console.error('AudioViewPicker.select failed with err: ' + err);
        return;
      }
      console.info('AudioViewPicker.select successfully, AudioSelectResult uri: ' + JSON.stringify(AudioSelectResult));
    });
  } catch (err) {
    console.error('AudioViewPicker failed with err: ' + err);
  }
}
```

### select

select(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

通过选择模式拉起audioPicker界面（目前拉起的是documentPicker，audioPicker在规划中），用户可以选择一个或多个音频文件。接口采用callback异步返回形式，返回选择音频文件的uri数组。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回audioPicker选择音频后的结果集 |

**示例：**

```ts
async function example() {
  try {
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.select((err, AudioSelectResult) => {
      if (err) {
        console.error('AudioViewPicker.select failed with err: ' + err);
        return;
      }
      console.info('AudioViewPicker.select successfully, AudioSelectResult uri: ' + JSON.stringify(AudioSelectResult));
    });
  } catch (err) {
    console.error('AudioViewPicker failed with err: ' + err);
  }
}
```

### save

save(option?: AudioSaveOptions) : Promise&lt;Array&lt;string&gt;&gt;

通过保存模式拉起audioPicker界面（目前拉起的是documentPicker，audioPicker在规划中），用户可以保存一个或多个音频文件。接口采用promise异步返回形式，传入可选参数AudioSaveOptions对象，返回保存音频文件的uri数组。

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
async function example() {
  try {
    let AudioSaveOptions = new picker.AudioSaveOptions();
    AudioSaveOptions.newFileNames = ['AudioViewPicker01.mp3'];
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.save(AudioSaveOptions).then((AudioSaveResult) => {
      console.info('AudioViewPicker.save successfully, AudioSaveResult uri: ' + JSON.stringify(AudioSaveResult))
    }).catch((err) => {
      console.error('AudioViewPicker.save failed with err: ' + err);
    });
  } catch (err) {
    console.error('AudioViewPicker failed with err: ' + err);
  }
}
```

### save

save(option: AudioSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

通过保存模式拉起audioPicker界面（目前拉起的是documentPicker，audioPicker在规划中），用户可以保存一个或多个音频文件。接口采用callback异步返回形式，传入参数AudioSaveOptions对象，返回保存音频文件的uri数组。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSaveOptions](#audiosaveoptions) | 是   | audioPicker保存音频文件选项 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回audioPicker保存音频文件后的结果集 |

**示例：**

```ts
async function example() {
  try {
    let AudioSaveOptions = new picker.AudioSaveOptions();
    AudioSaveOptions.newFileNames = ['AudioViewPicker02.mp3'];
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.save(AudioSaveOptions, (err, AudioSaveResult) => {
      if (err) {
        console.error('AudioViewPicker.save failed with err: ' + err);
        return;
      }
      console.info('AudioViewPicker.save successfully, AudioSaveResult uri: ' + JSON.stringify(AudioSaveResult));
    });
  } catch (err) {
    console.error('AudioViewPicker failed with err: ' + err);
  }
}
```

### save

save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

通过保存模式拉起audioPicker界面（目前拉起的是documentPicker，audioPicker在规划中），用户可以保存一个或多个音频文件。接口采用callback异步返回形式，返回保存音频文件的uri数组。

**系统能力**：SystemCapability.FileManagement.UserFileService

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | 是   | callback 返回audioPicker保存音频文件后的结果集 |

**示例：**

```ts
async function example() {
  try {
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.save((err, AudioSaveResult) => {
      if (err) {
        console.error('AudioViewPicker.save failed with err: ' + err);
        return;
      }
      console.info('AudioViewPicker.save successfully, AudioSaveResult uri: ' + JSON.stringify(AudioSaveResult));
    });
  } catch (err) {
    console.error('AudioViewPicker failed with err: ' + err);
  }
}
```

## PhotoViewMIMETypes

枚举，可选择的媒体文件类型。

**系统能力：** 以下各项对应的系统能力均为 SystemCapability.FileManagement.UserFileService

| 名称  |  值 |  说明 |
| ----- |  ---- | ---- |
| IMAGE_TYPE  |  'image/*' | 图片类型 |
| VIDEO_TYPE |  'video/*' | 视频类型 |
| IMAGE_VIDEO_TYPE |  '\*/*' | 图片和视频类型 |

## PhotoSelectOptions

图库选择选项。

**系统能力：** 以下各项对应的系统能力均为 SystemCapability.FileManagement.UserFileService

| 名称                    | 类型                | 必填 | 说明                          |
| ----------------------- | ------------------- | ---- | -------------------------------- |
| MIMEType?              | [PhotoViewMIMETypes](#photoviewmimetypes)   | 否   | 可选择的媒体文件类型，若无此参数，则默认为图片和视频类型 |
| maxSelectNumber?       | number | 否   | 选择媒体文件数量的最大值(默认值为50，最大值为500)      |

## PhotoSelectResult

返回图库选择后的结果集。

**系统能力：** 以下各项对应的系统能力均为 SystemCapability.FileManagement.UserFileService

| 名称                    | 类型                | 可读 | 可写 | 说明                           |
| ----------------------- | ------------------- | ---- | ---- | ------------------------------ |
| photoUris        | Array&lt;string&gt;    | 是   | 是   | 返回图库选择后的媒体文件的uri数组 |
| isOriginalPhoto        | boolean    | 是   | 是   | 返回图库选择后的媒体文件是否为原图 | 

## PhotoSaveOptions

图片或视频的保存选项。

**系统能力：** 以下各项对应的系统能力均为 SystemCapability.FileManagement.UserFileService

| 名称                    | 类型                | 必填 |  说明                           |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames?              | Array&lt;string&gt;    | 否  | 拉起photoPicker进行保存图片或视频资源的文件名，若无此参数，则默认需要用户自行输入 |

## DocumentSelectOptions

文档选择选项，目前不支持参数配置。

**系统能力：** SystemCapability.FileManagement.UserFileService

## DocumentSaveOptions

文档保存选项。

**系统能力：** 以下各项对应的系统能力均为 SystemCapability.FileManagement.UserFileService

| 名称                    | 类型                | 必填 |  说明                           |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames?            | Array&lt;string&gt;    | 否   | 拉起documentPicker进行保存的文件名，若无此参数，则默认需要用户自行输入 |

## AudioSelectOptions

音频选择选项，目前不支持参数配置。

**系统能力：** SystemCapability.FileManagement.UserFileService

## AudioSaveOptions

音频的保存选项。

**系统能力：** 以下各项对应的系统能力均为 SystemCapability.FileManagement.UserFileService

| 名称                    | 类型                | 必填 |  说明                           |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames?              | Array&lt;string&gt;    | 否  | 拉起audioPicker进行保存音频资源的文件名，若无此参数，则默认需要用户自行输入 |
