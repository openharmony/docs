# @system.file (文件存储)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25; @gsl_1234; @wuchengjun5-->
<!--Designer: @gsl_1234; @wangke25-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @jinqiuheng-->

> **说明：**
>
> - 模块维护策略：
>   - 对于Lite Wearable设备类型，该模块长期维护，正常使用。
>   - 对于支持该模块的其他设备类型，该模块从API Version 10开始不再维护，推荐使用新接口js-apis-file-fs.md。
> - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import file from '@system.file';
```

## File

### move

static move(options: FileMoveOption): void

将指定文件移动到其他指定位置。

> **说明**：
>
> 除Lite Wearable外，从API version 10开始废弃，请使用[fileIo.moveFile](js-apis-file-fs.md#fileiomovefile)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [FileMoveOption](#filemoveoption) | 是 | 文件移动选项。 |

**示例：**

ArkTS示例：

```ts
import file from '@system.file';

export default {    
  move() {        
    file.move({            
      srcUri: 'internal://app/myfiles1',            
      dstUri: 'internal://app/myfiles2',            
      success: function(uri) {                
        console.info('call success callback success');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },        
    });    
  }
}
```

JS示例：

```xml
<!-- xxx.hml -->
<div class="container">
  <text class="title" style="font-size: 30px;">test</text>
  <input type="button" value="move" class="button" onclick="move"></input>
</div>
```

```css
/* xxx.css */
.container {
  display: flex;
  justify-content: column;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}

.title {
  font-size: 100px;
  text-align: center;
  width: 200px;
  height: 100px;
}

.button {
  font-size: 30px;
  text-align: center;
  width: 250px;
  height: 60px;
  background-color: #0078D7;
  color: white;
  border-radius: 5px;
}
```

```js
// xxx.js
import file from '@system.file';

export default {
  move() {
    file.move({
      srcUri: 'internal://app/myfiles1',
      dstUri: 'internal://app/myfiles2',
      success: function(uri) {
        console.info('call success callback success');
      },
      fail: function(data, code) {
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);
      },
    });
  }
}
```
### copy

static copy(options: FileCopyOption): void

将指定文件拷贝并存储到指定位置。

> **说明**：
>
> 除Lite Wearable外，从API version 10开始废弃，请使用[fileIo.copyFile](js-apis-file-fs.md#fileiocopyfile)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [FileCopyOption](#filecopyoption) | 是 | 文件拷贝选项。 |

**示例：**

ArkTS示例：

```ts
import file from '@system.file';

export default {    
  copy() {        
    file.copy({            
      srcUri: 'internal://app/file.txt',            
      dstUri: 'internal://app/file_copy.txt',            
      success: function(uri) {                
        console.info('call success callback success');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```

JS示例：

```xml
<!-- xxx.hml -->
<div class="container">
  <text class="title" style="font-size: 30px;">test</text>
  <input type="button" value="copy" class="button" onclick="copy"></input>
</div>
```

```css
/* xxx.css */
.container {
  display: flex;
  justify-content: column;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}

.title {
  font-size: 100px;
  text-align: center;
  width: 200px;
  height: 100px;
}

.button {
  font-size: 30px;
  text-align: center;
  width: 250px;
  height: 60px;
  background-color: #0078D7;
  color: white;
  border-radius: 5px;
}
```

```js
// xxx.js
import file from '@system.file';

export default {    
  copy() {        
    file.copy({            
      srcUri: 'internal://app/file.txt',            
      dstUri: 'internal://app/file_copy.txt',            
      success: function(uri) {                
        console.info('call success callback success');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```

### list

static list(options: FileListOption): void

获取指定路径下全部文件的列表。

> **说明**：
>
> 除Lite Wearable外，从API version 10开始废弃，请使用[fileIo.listFile](js-apis-file-fs.md#fileiolistfile)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [FileListOption](#filelistoption) | 是 | 获取指定路径下全部文件的列表选项。 |

**示例：**

ArkTS示例：

```ts
import file from '@system.file';

export default {    
  list() {        
    file.list({            
      uri: 'internal://app/pic',            
      success: function(data) {                
        console.info(JSON.stringify(data.fileList));            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },        
    });    
  }
}
```

JS示例：

```xml
<!-- xxx.hml -->
<div class="container">
  <text class="title" style="font-size: 30px;">test</text>
  <input type="button" value="list" class="button" onclick="list"></input>
</div>
```

```css
/* xxx.css */
.container {
  display: flex;
  justify-content: column;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}

.title {
  font-size: 100px;
  text-align: center;
  width: 200px;
  height: 100px;
}

.button {
  font-size: 30px;
  text-align: center;
  width: 250px;
  height: 60px;
  background-color: #0078D7;
  color: white;
  border-radius: 5px;
}
```

```js
// xxx.js
import file from '@system.file';

export default {    
  list() {        
    file.list({            
      uri: 'internal://app/pic',            
      success: function(data) {                
        console.info(JSON.stringify(data.fileList));            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },        
    });    
  }
}
```

### get

static get(options: FileGetOption): void

获取指定本地文件的信息。

> **说明**：
>
> 除Lite Wearable外，从API version 10开始废弃，请使用[fileIo.stat](js-apis-file-fs.md#fileiostat)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [FileGetOption](#filegetoption) | 是 | 获取指定本地文件的信息选项。 |

**示例：**

ArkTS示例：

```ts
import file from '@system.file';

export default {    
  get() {        
    file.get({            
      uri: 'internal://app/file',            
      success: function(data) {                
        console.info(data.uri);            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```

JS示例：

```xml
<!-- xxx.hml -->
<div class="container">
  <text class="title" style="font-size: 30px;">test</text>
  <input type="button" value="get" class="button" onclick="get"></input>
</div>
```

```css
/* xxx.css */
.container {
  display: flex;
  justify-content: column;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}

.title {
  font-size: 100px;
  text-align: center;
  width: 200px;
  height: 100px;
}

.button {
  font-size: 30px;
  text-align: center;
  width: 250px;
  height: 60px;
  background-color: #0078D7;
  color: white;
  border-radius: 5px;
}
```

```js
// xxx.js
import file from '@system.file';

export default {    
  get() {        
    file.get({            
      uri: 'internal://app/file',            
      success: function(data) {                
        console.info(data.uri);            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```
### delete

static delete(options: FileDeleteOption): void

删除本地文件。

> **说明**：
>
> 除Lite Wearable外，从API version 10开始废弃，请使用[fileIo.unlink](js-apis-file-fs.md#fileiounlink)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [FileDeleteOption](#filedeleteoption) | 是 | 删除本地文件选项。 |

**示例：**

ArkTS示例：

```ts
import file from '@system.file';

export default {    
  delete() {        
    file.delete({            
      uri: 'internal://app/my_file',            
      success: function() {                
        console.info('call delete success.');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```

JS示例：

```xml
<!-- xxx.hml -->
<div class="container">
  <text class="title" style="font-size: 30px;">test</text>
  <input type="button" value="delete" class="button" onclick="delete"></input>
</div>
```

```css
/* xxx.css */
.container {
  display: flex;
  justify-content: column;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}

.title {
  font-size: 100px;
  text-align: center;
  width: 200px;
  height: 100px;
}

.button {
  font-size: 30px;
  text-align: center;
  width: 250px;
  height: 60px;
  background-color: #0078D7;
  color: white;
  border-radius: 5px;
}
```

```js
// xxx.js
import file from '@system.file';

export default {    
  delete() {        
    file.delete({            
      uri: 'internal://app/my_file',            
      success: function() {                
        console.info('call delete success.');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```


### writeText

static writeText(options: FileWriteTextOption): void

写文本内容到指定文件。仅支持文本文档读写。

> **说明**：
>
> 除Lite Wearable外，从API version 10开始废弃，请使用[fileIo.write](js-apis-file-fs.md#fileiowrite)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [FileWriteTextOption](#filewritetextoption) | 是 | 写文本内容到指定文件选项。 |

**示例：**

ArkTS示例：

```ts
import file from '@system.file';

export default {    
  writeText() {        
    file.writeText({            
      uri: 'internal://app/test.txt',            
      text: 'Text that just for test.',            
      success: function() {                
        console.info('call writeText success.');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },        
    });    
  }
}
```

JS示例：

```xml
<!-- xxx.hml -->
<div class="container">
  <text class="title" style="font-size: 30px;">test</text>
  <input type="button" value="writeText" class="button" onclick="writeText"></input>
</div>
```

```css
/* xxx.css */
.container {
  display: flex;
  justify-content: column;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}

.title {
  font-size: 100px;
  text-align: center;
  width: 200px;
  height: 100px;
}

.button {
  font-size: 30px;
  text-align: center;
  width: 250px;
  height: 60px;
  background-color: #0078D7;
  color: white;
  border-radius: 5px;
}
```

```js
// xxx.js
import file from '@system.file';

export default {    
  writeText() {        
    file.writeText({            
      uri: 'internal://app/test.txt',            
      text: 'Text that just for test.',            
      success: function() {                
        console.info('call writeText success.');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },        
    });    
  }
}
```

### writeArrayBuffer

static writeArrayBuffer(options: FileWriteArrayBufferOption): void

写Buffer内容到指定文件。仅支持文本文档读写。

> **说明**：
>
> 除Lite Wearable外，从API version 10开始废弃，请使用[fileIo.write](js-apis-file-fs.md#fileiowrite)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [FileWriteArrayBufferOption](#filewritearraybufferoption) | 是 | 写Buffer内容到指定文件选项。 |

**示例：**

ArkTS示例：

```ts
import file from '@system.file';

export default {    
  writeArrayBuffer() {       
    file.writeArrayBuffer({           
      uri: 'internal://app/test',           
      buffer: new Uint8Array(8),// buffer为Uint8Array类型
      success: function() {                
        console.info('call writeArrayBuffer success.');            
      },           
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```

JS示例：

```xml
<!-- xxx.hml -->
<div class="container">
  <text class="title" style="font-size: 30px;">test</text>
  <input type="button" value="writeArrayBuffer" class="button" onclick="writeArrayBuffer"></input>
</div>
```

```css
/* xxx.css */
.container {
  display: flex;
  justify-content: column;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}

.title {
  font-size: 100px;
  text-align: center;
  width: 200px;
  height: 100px;
}

.button {
  font-size: 30px;
  text-align: center;
  width: 250px;
  height: 60px;
  background-color: #0078D7;
  color: white;
  border-radius: 5px;
}
```

```js
// xxx.js
import file from '@system.file';

export default {    
  writeArrayBuffer() {       
    file.writeArrayBuffer({           
      uri: 'internal://app/test',           
      buffer: new Uint8Array(8),// buffer为Uint8Array类型
      success: function() {                
        console.info('call writeArrayBuffer success.');            
      },           
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```


### readText

static readText(options: FileReadTextOption): void

从指定文件中读取文本内容。仅支持文本文档读写。

> **说明**：
>
> 除Lite Wearable外，从API version 10开始废弃，请使用[fileIo.readText](js-apis-file-fs.md#fileioreadtext)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [FileReadTextOption](#filereadtextoption) | 是 | 从指定文件中读取文本内容选项。 |

**示例：**

ArkTS示例：

```ts
import file from '@system.file';

export default {    
  readText() {        
    file.readText({            
      uri: 'internal://app/text.txt',            
      success: function(data) {                
        console.info('call readText success: ' + data.text);            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },        
    });    
  }
}
```

JS示例：

```xml
<!-- xxx.hml -->
<div class="container">
  <text class="title" style="font-size: 30px;">test</text>
  <input type="button" value="readText" class="button" onclick="readText"></input>
</div>
```

```css
/* xxx.css */
.container {
  display: flex;
  justify-content: column;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}

.title {
  font-size: 100px;
  text-align: center;
  width: 200px;
  height: 100px;
}

.button {
  font-size: 30px;
  text-align: center;
  width: 250px;
  height: 60px;
  background-color: #0078D7;
  color: white;
  border-radius: 5px;
}
```

```js
// xxx.js
import file from '@system.file';

export default {    
  readText() {        
    file.readText({            
      uri: 'internal://app/text.txt',            
      success: function(data) {                
        console.info('call readText success: ' + data.text);            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },        
    });    
  }
}
```


### readArrayBuffer

static readArrayBuffer(options: FileReadArrayBufferOption): void

从指定文件中读取Buffer内容。仅支持文本文档读写。

> **说明**：
>
> 除Lite Wearable外，从API version 10开始废弃，请使用[fileIo.read](js-apis-file-fs.md#fileioread)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [FileReadArrayBufferOption](#filereadarraybufferoption) | 是 | 从指定文件中读取Buffer内容选项。 |

**示例：**

ArkTS示例：

```ts
import file from '@system.file';

export default {    
  readArrayBuffer() {        
    file.readArrayBuffer({            
      uri: 'internal://app/test',            
      position: 10,            
      length: 200,            
      success: function(data) {                
        console.info('call readArrayBuffer success: ' + data.buffer);            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```

JS示例：

```xml
<!-- xxx.hml -->
<div class="container">
  <text class="title" style="font-size: 30px;">test</text>
  <input type="button" value="readArrayBuffer" class="button" onclick="readArrayBuffer"></input>
</div>
```

```css
/* xxx.css */
.container {
  display: flex;
  justify-content: column;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}

.title {
  font-size: 100px;
  text-align: center;
  width: 200px;
  height: 100px;
}

.button {
  font-size: 30px;
  text-align: center;
  width: 250px;
  height: 60px;
  background-color: #0078D7;
  color: white;
  border-radius: 5px;
}
```

```js
// xxx.js
import file from '@system.file';

export default {    
  readArrayBuffer() {        
    file.readArrayBuffer({            
      uri: 'internal://app/test',            
      position: 10,            
      length: 200,            
      success: function(data) {                
        console.info('call readArrayBuffer success: ' + data.buffer);            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```


### access

static access(options: FileAccessOption): void

判断指定文件或目录是否存在。

> **说明**：
>
> 除Lite Wearable外，从API version 10开始废弃，请使用[fileIo.access](js-apis-file-fs.md#fileioaccess)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [FileAccessOption](#fileaccessoption) | 是 | 判断指定文件或目录是否存在选项。 |

**示例：**

ArkTS示例：

```ts
import file from '@system.file';

export default {    
  access() {        
    file.access({            
      uri: 'internal://app/test',            
      success: function() {                
        console.info('call access success.');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },        
    });    
  }
}
```

JS示例：

```xml
<!-- xxx.hml -->
<div class="container">
  <text class="title" style="font-size: 30px;">test</text>
  <input type="button" value="access" class="button" onclick="access"></input>
</div>
```

```css
/* xxx.css */
.container {
  display: flex;
  justify-content: column;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}

.title {
  font-size: 100px;
  text-align: center;
  width: 200px;
  height: 100px;
}

.button {
  font-size: 30px;
  text-align: center;
  width: 250px;
  height: 60px;
  background-color: #0078D7;
  color: white;
  border-radius: 5px;
}
```

```js
// xxx.js
import file from '@system.file';

export default {    
  access() {        
    file.access({            
      uri: 'internal://app/test',            
      success: function() {                
        console.info('call access success.');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },        
    });    
  }
}
```


### mkdir

static mkdir(options: FileMkdirOption): void

创建指定目录。

> **说明**：
>
> 除Lite Wearable外，从API version 10开始废弃，请使用[fileIo.mkdir](js-apis-file-fs.md#fileiomkdir)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [FileMkdirOption](#filemkdiroption) | 是 | 创建指定目录选项。 |

**示例：**

ArkTS示例：

```ts
import file from '@system.file';

export default {    
  mkdir() {        
    file.mkdir({            
      uri: 'internal://app/test_directory',            
      success: function() {                
        console.info('call mkdir success.');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```

JS示例：

```xml
<!-- xxx.hml -->
<div class="container">
  <text class="title" style="font-size: 30px;">test</text>
  <input type="button" value="mkdir" class="button" onclick="mkdir"></input>
</div>
```

```css
/* xxx.css */
.container {
  display: flex;
  justify-content: column;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}

.title {
  font-size: 100px;
  text-align: center;
  width: 200px;
  height: 100px;
}

.button {
  font-size: 30px;
  text-align: center;
  width: 250px;
  height: 60px;
  background-color: #0078D7;
  color: white;
  border-radius: 5px;
}
```

```js
// xxx.js
import file from '@system.file';

export default {    
  mkdir() {        
    file.mkdir({            
      uri: 'internal://app/test_directory',            
      success: function() {                
        console.info('call mkdir success.');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```

### rmdir

static rmdir(options: FileRmdirOption): void

删除指定目录。

> **说明**：
>
> 除Lite Wearable外，从API version 10开始废弃，请使用[fileIo.rmdir](js-apis-file-fs.md#fileiormdir)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [FileRmdirOption](#filermdiroption) | 是 | 删除指定目录选项。 |

**示例：**

ArkTS示例：

```ts
import file from '@system.file';

export default {    
  rmdir() {        
    file.rmdir({            
      uri: 'internal://app/test_directory',            
      success: function() {                
        console.info('call rmdir success.');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```

JS示例：

```xml
<!-- xxx.hml -->
<div class="container">
  <text class="title" style="font-size: 30px;">test</text>
  <input type="button" value="rmdir" class="button" onclick="rmdir"></input>
</div>
```

```css
/* xxx.css */
.container {
  display: flex;
  justify-content: column;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}

.title {
  font-size: 100px;
  text-align: center;
  width: 200px;
  height: 100px;
}

.button {
  font-size: 30px;
  text-align: center;
  width: 250px;
  height: 60px;
  background-color: #0078D7;
  color: white;
  border-radius: 5px;
}
```

```js
// xxx.js
import file from '@system.file';

export default {    
  rmdir() {        
    file.rmdir({            
      uri: 'internal://app/test_directory',            
      success: function() {                
        console.info('call rmdir success.');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```

## FileResponse

文件返回。包含文件的信息。

**系统能力**：SystemCapability.FileManagement.File.FileIO.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | 否 | 否 | 文件的URI。 |
| length | number | 否 | 否 | 文件长度，单位为Byte。|
| lastModifiedTime | number | 否 | 否 | 文件保存时的时间戳，从1970/01/01&nbsp;00:00:00到当前时间的毫秒数。 |
| type | 'dir' \| 'file' | 否 | 否 | 文件类型，可选值为：<br/> -dir：目录；<br/> -file：文件。 |
| subFiles | Array&lt;[FileResponse](#fileresponse)&gt; | 否 | 是 | 文件列表。 |

## FileListResponse

文件列表返回，包含文件列表信息。

**系统能力**：SystemCapability.FileManagement.File.FileIO.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ----- |
| fileList | Array&lt;[FileResponse](#fileresponse)&gt; | 否 | 否 | 获取的文件列表，其中每个文件的信息的格式为：<br/>{<br/>uri:'file1',<br/>lastModifiedTime:1589965924479,<br/>length:10240,<br/>type:&nbsp;'file'<br/>} |

## FileReadTextResponse

文本读取返回，包含读取到的文本内容。

**系统能力**：SystemCapability.FileManagement.File.FileIO.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ----- |
| text | string | 否 | 否 | 读取到的文本内容。 |

## FileReadArrayBufferResponse

文件读取返回，包含读取到的文件内容。

**系统能力**：SystemCapability.FileManagement.File.FileIO.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ----- |
| buffer | Uint8Array | 否 | 否 | 读取到的文件内容。 |

## FileMoveOption

可选项类型，支持move接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ----- |
| srcUri | string | 否 | 否 | 要移动的文件的URI。由于轻量级穿戴设备底层文件系统的限制，该值必须满足以下要求：<br/>1. URI 中不得包含以下特殊字符：\\"*+,:;<=>?[]\\|\x7F等。<br/>2. 最大允许字符长度为128个字符。 |
| dstUri | string | 否 | 否 | 文件要移动到的位置的URI。由于轻量级穿戴设备底层文件系统的限制，该值必须满足以下要求：<br/>1. URI 中不得包含以下特殊字符：\\"*+,:;<=>?[]\\|\x7F等。<br/>2. 最大允许字符长度为128个字符。 |
| success | (uri: string) => void | 否 | 是 | 接口调用成功的回调函数，uri为文件要移动到的位置的URI。 |
| fail | (data: string, code: number) => void | 否 | 是 | 接口调用失败的回调函数。<br/>data为错误信息。<br/>code为可能返回的错误码：<br/>202：出现参数错误。<br/>300：出现I/O错误。<br/>301：文件或目录不存在。 |
| complete | () => void | 否 | 是 | 接口调用结束的回调函数。 |

## FileCopyOption

可选项类型，支持copy接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ----- |
| srcUri | string | 否 | 否 | 要拷贝的文件的URI。由于轻量级穿戴设备底层文件系统的限制，该值必须满足以下要求：<br/>1. URI 中不得包含以下特殊字符：\\"*+,:;<=>?[]\\|\x7F等。<br/>2. 最大允许字符长度为128个字符。 |
| dstUri | string | 否 | 否 | 文件要拷贝到的位置的URI。<br/>不支持用应用资源路径或tmp类型的URI。由于轻量级穿戴设备底层文件系统的限制，该值必须满足以下要求：<br/>1. URI 中不得包含以下特殊字符：\\"*+,:;<=>?[]\\|\x7F等。<br/>2. 最大允许字符长度为128个字符。 |
| success | (uri: string) => void | 否 | 是 | 接口调用成功的回调函数，uri为文件要拷贝到的位置的URI。 |
| fail | (data: string, code: number) => void | 否 | 是 | 接口调用失败的回调函数。<br/>data为错误信息。<br/>code为可能返回的错误码：<br/>202：出现参数错误。<br/>300：出现I/O错误。<br/>301：文件或目录不存在。 |
| complete | () => void | 否 | 是 | 接口调用结束的回调函数。 |

## FileListOption

可选项类型，支持list接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | 否 | 否 | 目录URI。由于轻量级穿戴设备底层文件系统的限制，该值必须满足以下要求：<br/>1. URI 中不得包含以下特殊字符：\\"*+,:;<=>?[]\\|\x7F等。<br/>2. 最大允许字符长度为128个字符。 |
| success | (data: FileListResponse) => void | 否 | 是 | 接口调用成功的回调函数。data为[FileListResponse](#filelistresponse)。 |
| fail | (data: string, code: number) => void | 否 | 是 | 接口调用失败的回调函数。<br/>data为错误信息。<br/>code为可能返回的错误码：<br/>202：出现参数错误。<br/>300：出现I/O错误。<br/>301：文件或目录不存在。 |
| complete | () => void | 否 | 是 | 接口调用结束的回调函数。 |

## FileGetOption

可选项类型，支持get接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | 否 | 否 | 文件的URI。由于轻量级穿戴设备底层文件系统的限制，该值必须满足以下要求：<br/>1. URI 中不得包含以下特殊字符：\\"*+,:;<=>?[]\\|\x7F等。<br/>2. 最大允许字符长度为128个字符。 |
| recursive | boolean | 否 | 是 | 是否进行递归获取子目录文件列表。true表示进行递归操作，false表示不递归。参数缺省时，默认为false。 |
| success | (file: FileResponse) => void | 否 | 是 | 接口调用成功的回调函数。 file为[FileResponse](#fileresponse)。 |
| fail | (data: string, code: number) => void | 否 | 是 | 接口调用失败的回调函数。<br/>data为错误信息。<br/>code为可能返回的错误码：<br/>202：出现参数错误。<br/>300：出现I/O错误。<br/>301：文件或目录不存在。 |
| complete | () => void | 否 | 是 | 接口调用结束的回调函数。 |

## FileDeleteOption

可选项类型，支持delete接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | 否 | 否 | 删除文件的URI，不能是应用资源路径。由于轻量级穿戴设备底层文件系统的限制，该值必须满足以下要求：<br/>1. URI 中不得包含以下特殊字符：\\"*+,:;<=>?[]\\|\x7F等。<br/>2. 最大允许字符长度为128个字符。 |
| success | () => void | 否 | 是 | 接口调用成功的回调函数。 |
| fail | (data: string, code: number) => void | 否 | 是 | 接口调用失败的回调函数。<br/>data为错误信息。<br/>code为可能返回的错误码：<br/>202：出现参数错误。<br/>300：出现I/O错误。<br/>301：文件或目录不存在。 |
| complete | () => void | 否 | 是 | 接口调用结束的回调函数。 |

## FileWriteTextOption

可选项类型，支持writeText接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | 否 | 否 | 本地文件URI，如果文件不存在会创建文件。由于轻量级穿戴设备底层文件系统的限制，该值必须满足以下要求：<br/>1. URI 中不得包含以下特殊字符：\\"*+,:;<=>?[]\\|\x7F等。<br/>2. 最大允许字符长度为128个字符。 |
| text | string | 否  | 否 | 写入的字符串。 |
| encoding | string | 否  | 是 | 编码格式，默认为UTF-8。 |
| append | boolean | 否  | 是 | 是否追加模式，默认为false。true为追加，false为不追加。 |
| success | () => void | 否  | 是 | 接口调用成功的回调函数。 |
| fail | (data: string, code: number) => void | 否  | 是 | 接口调用失败的回调函数。<br/>data为错误信息。<br/>code为可能返回的错误码：<br/>202：出现参数错误。<br/>300：出现I/O错误。 |
| complete | () => void | 否  | 是 | 接口调用结束的回调函数。 |


## FileWriteArrayBufferOption

可选项类型，支持writeArrayBuffer接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | 否 | 否 | 本地文件URI，如果文件不存在会创建文件。由于轻量级穿戴设备底层文件系统的限制，该值必须满足以下要求：<br/>1. URI 中不得包含以下特殊字符：\\"*+,:;<=>?[]\\|\x7F等。<br/>2. 最大允许字符长度为128个字符。 |
| buffer | Uint8Array | 否 | 否 | 写入的Buffer。 |
| position | number | 否 | 是 | 文件写入的起始偏移位置，单位为Byte，默认为0。 |
| append | boolean | 否 | 是 | 是否追加模式，默认为false。当设置为true时，position参数无效。true为追加，false为不追加。 |
| success | () => void | 否 | 是 | 接口调用成功的回调函数。 |
| fail | (data: string, code: number) => void | 否 | 是 | 接口调用失败的回调函数。<br/>data为错误信息。<br/>code为可能返回的错误码：<br/>202：出现参数错误。<br/>300：出现I/O错误。 |
| complete | () => void | 否 | 是 | 接口调用结束的回调函数。 |

## FileReadTextOption

可选项类型，支持readText接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | 否 | 否 | 本地文件URI。由于轻量级穿戴设备底层文件系统的限制，该值必须满足以下要求：<br/>1. URI 中不得包含以下特殊字符：\\"*+,:;<=>?[]\\|\x7F等。<br/>2. 最大允许字符长度为128个字符。 |
| encoding | string | 否 | 是 | 编码格式，缺省为UTF-8。 |
| position | number | 否 | 是 | 读取的起始位置，单位为Byte，默认为文件的起始位置。 |
| length | number | 否 | 是 | 读取的长度，单位为Byte，如果不传长度参数，默认值为4096，传长度参数，最大值为4096。 |
| success | (data: FileReadTextResponse) => void | 否 | 是 | 接口调用成功的回调函数。data为[FileReadTextResponse](#filereadtextresponse)。 |
| fail | (data: string, code: number) => void | 否 | 是 | 接口调用失败的回调函数。<br/>data为错误信息。<br/>code为可能返回的错误码：<br/>202：出现参数错误。<br/>300：出现I/O错误。<br/>301：文件或目录不存在。<br/>302：要读取的文件内容超过4KB。 |
| complete | () => void | 否 | 是 | 接口调用结束的回调函数。 |

## FileReadArrayBufferOption

可选项类型，支持readArrayBuffer接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | 否 | 否 | 本地文件URI。由于轻量级穿戴设备底层文件系统的限制，该值必须满足以下要求：<br/>1. URI 中不得包含以下特殊字符：\\"*+,:;<=>?[]\\|\x7F等。<br/>2. 最大允许字符长度为128个字符。 |
| position | number | 否 | 是 | 读取的起始位置，单位为Byte，缺省为文件的起始位置。 |
| length | number | 否 | 是 | 需要读取的长度，单位为Byte，缺省则读取到文件结尾。 |
| success | (data: FileReadArrayBufferResponse) => void | 否 | 是 | 接口调用成功的回调函数。data为[FileReadArrayBufferResponse](#filereadarraybufferresponse)。 |
| fail | (data: string, code: number) => void | 否 | 是 | 接口调用失败的回调函数。<br/>data为错误信息。<br/>code为可能返回的错误码：<br/>202：出现参数错误。<br/>300：出现I/O错误。<br/>301：文件或目录不存在。 |
| complete | () => void | 否 | 是 | 接口调用结束的回调函数。 |

## FileAccessOption

可选项类型，支持access接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | 否 | 否 | 目录或文件URI。由于轻量级穿戴设备底层文件系统的限制，该值必须满足以下要求：<br/>1. URI 中不得包含以下特殊字符：\\"*+,:;<=>?[]\\|\x7F等。<br/>2. 最大允许字符长度为128个字符。 |
| success | () => void | 否 | 是 | 接口调用成功的回调函数。 |
| fail | (data: string, code: number) => void | 否 | 是 | 接口调用失败的回调函数。<br/>data为错误信息。<br/>code为可能返回的错误码：<br/>202：出现参数错误。<br/>300：出现I/O错误。<br/>301：文件或目录不存在。 |
| complete | () => void | 否 | 是 | 接口调用结束的回调函数。 |


## FileMkdirOption

可选项类型，支持mkdir接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | 否 | 否 | 目录URI。由于轻量级穿戴设备底层文件系统的限制，该值必须满足以下要求：<br/>1. URI 中不得包含以下特殊字符：\\"*+,:;<=>?[]\\|\x7F等。<br/>2. 最大允许字符长度为128个字符。 |
| recursive | boolean | 否 | 是 | 是否递归创建该目录的上级目录，缺省为false。true为递归创建，false是不递归创建。 |
| success | () => void | 否 | 是 | 接口调用成功的回调函数。 |
| fail | (data: string, code: number) => void | 否 | 是 | 接口调用失败的回调函数。<br/>data为错误信息。<br/>code为可能返回的错误码：<br/>202：出现参数错误。<br/>300：出现I/O错误。 |
| complete | () => void | 否 | 是 | 接口调用结束的回调函数。 |


## FileRmdirOption

可选项类型，支持rmdir接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO.Lite

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | 否 | 否 | 目录URI。由于轻量级穿戴设备底层文件系统的限制，该值必须满足以下要求：<br/>1. URI 中不得包含以下特殊字符：\\"*+,:;<=>?[]\\|\x7F等。<br/>2. 最大允许字符长度为128个字符。 |
| recursive | boolean | 否 | 是 | 是否递归删除子文件和子目录，缺省为false。true为递归删除，false为不递归删除。 |
| success | () => void | 否 | 是 | 接口调用成功的回调函数。 |
| fail | (data: string, code: number) => void | 否 | 是 | 接口调用失败的回调函数。<br/>data为错误信息。<br/>code为可能返回的错误码：<br/>202：出现参数错误。<br/>300：出现I/O错误。<br/>301：文件或目录不存在。 |
| complete | () => void | 否 | 是 | 接口调用结束的回调函数。 |