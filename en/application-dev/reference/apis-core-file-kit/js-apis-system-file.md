# @system.file (File Storage)

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25; @gsl_1234; @wuchengjun5-->
<!--Designer: @gsl_1234; @wangke25-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=5556925570c80a64b2b1b74564a6b2974cdc4f30 translatedAt=2026-08-14T11:50:38.766Z pushedAt=2026-08-17T08:43:51.396Z -->

> **NOTE**
>
> - Module maintenance policy:
>   - For lite wearables, this module is constantly maintained and available.
>   - For other device types, this module is no longer maintained since API version 10, and you are advised to use [@ohos.file.fs](js-apis-file-fs.md) instead.
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.

In the following ArkTS example, URI is described as follows:

  1. The URI must be in the format of **internal://app/xxx**.

  2. **internal://app/** is a fixed prefix, indicating the app root directory. **xxx** indicates the directory or file name created by the developer.

## Modules to Import

```ts
import file from '@system.file';
```

## File

### move

static move(options: FileMoveOption): void

Moves a specified file to another specified position.

> **NOTE**
>
> This API is deprecated since API version 10 for all device types except lite wearables. Use [fileIo.moveFile](js-apis-file-fs.md#fileiomovefile) instead.

**System capability:** SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| options | [FileMoveOption](#filemoveoption) | Yes | Options for moving the files. |

**Example**

ArkTS example:

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

JS example:

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

Copies a specified file and stores it at a specified position.

> **NOTE**
>
> Except for Lite Wearable, this API is deprecated since API version 10. Use [fileIo.copyFile](js-apis-file-fs.md#fileiocopyfile) instead.

**System capability:** SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| options | [FileCopyOption](#filecopyoption) | Yes | Options for copying the files. |

**Example**

ArkTS example:

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

JS example:

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

Obtains the list of all files in the specified path.

> **NOTE**
>
> This API is deprecated since API version 10 for all device types except lite wearables. Use [fileIo.listFile](js-apis-file-fs.md#fileiolistfile) instead.

**System capability:** SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| options | [FileListOption](#filelistoption) | Yes | Options for obtaining all files in the specified directory. |

**Example**

ArkTS example:

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

JS example:

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

Obtains information about the specified local file.

> **NOTE**
>
> This API is deprecated since API version 10 for all device types except lite wearables. Use [fileIo.stat](js-apis-file-fs.md#fileiostat) instead.

**System capability:** SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| options | [FileGetOption](#filegetoption) | Yes | Options for obtaining information about a local file. |

**Example**

ArkTS example:

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

JS example:

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

Deletes a local file.

> **NOTE**
>
> This API is deprecated since API version 10 for all device types except lite wearables. Use [fileIo.unlink](js-apis-file-fs.md#fileiounlink) instead.

**System capability:** SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| options | [FileDeleteOption](#filedeleteoption) | Yes | Options for deleting a local file. |

**Example**

ArkTS example:

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

JS example:

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

Writes text content to a specified file. Only supports text file read and write.

> **NOTE**
>
> This API is deprecated since API version 10 for all device types except lite wearables. Use [fileIo.write](js-apis-file-fs.md#fileiowrite) instead.

**System capability:** SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| options | [FileWriteTextOption](#filewritetextoption) | Yes | Options for writing text into a file. |

**Example**

ArkTS example:

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

JS example:

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

Writes buffer content to the specified file. Only supports text document read and write.

> **NOTE**
>
> This API is deprecated since API version 10 for all device types except lite wearables. Use [fileIo.write](js-apis-file-fs.md#fileiowrite) instead.

**System capability:** SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| options | [FileWriteArrayBufferOption](#filewritearraybufferoption) | Yes | Options for writing buffer data into a file. |

**Example**

ArkTS example:

```ts
import file from '@system.file';

export default {    
  writeArrayBuffer() {       
    file.writeArrayBuffer({           
      uri: 'internal://app/test',           
      buffer: new Uint8Array(8),// buffer is of the Uint8Array type.
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

JS example:

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
      buffer: new Uint8Array(8),// buffer is of the Uint8Array type.
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

Reads text content from a specified file. Only supports text file read and write.

> **NOTE**
>
> This API is deprecated since API version 10 for all device types except lite wearables. Use [fileIo.readText](js-apis-file-fs.md#fileioreadtext) instead.

**System capability:** SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| options | [FileReadTextOption](#filereadtextoption) | Yes | Options for reading text from a file. |

**Example**

ArkTS example:

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

JS example:

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

Reads the buffer content from a specified file. Only text files are supported for read and write.

> **NOTE**
>
> This API is deprecated since API version 10 for all device types except lite wearables. Use [fileIo.read](js-apis-file-fs.md#fileioread) instead.

**System capability:** SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| options | [FileReadArrayBufferOption](#filereadarraybufferoption) | Yes | Options for reading buffer data from a file. |

**Example**

ArkTS example:

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

JS example:

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

Checks whether a specified file or directory exists.

> **NOTE**
>
> This API is deprecated since API version 10 for all device types except lite wearables. Use [fileIo.access](js-apis-file-fs.md#fileioaccess) instead.

**System capability:** SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| options | [FileAccessOption](#fileaccessoption) | Yes | Options for checking whether a file or directory exists. |

**Example**

ArkTS example:

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

JS example:

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

Creates a directory.

> **NOTE**
>
> This API is deprecated since API version 10 for all device types except lite wearables. Use [fileIo.mkdir](js-apis-file-fs.md#fileiomkdir) instead.

**System capability:** SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| options | [FileMkdirOption](#filemkdiroption) | Yes | Options for creating a directory. |

**Example**

ArkTS example:

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

JS example:

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

Deletes a specified directory.

> **NOTE**
>
> This API is deprecated since API version 10 for all device types except lite wearables. Use [fileIo.rmdir](js-apis-file-fs.md#fileiormdir) instead.

**System capability:** SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| options | [FileRmdirOption](#filermdiroption) | Yes | Options for deleting a directory. |

**Example**

ArkTS example:

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

JS example:

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

Returns a file, including the file information.

**System capability**: SystemCapability.FileManagement.File.FileIO.Lite

| Name | Type | Read-Only | Optional | Description |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | No | No | URI of the file. |
| length | number | No | No | File length, in bytes. |
| lastModifiedTime | number | No | No | Timestamp when the file is stored the last time, which is the number of milliseconds elapsed since 1970/01/01 00:00:00 GMT. |
| type | 'dir' \| 'file' | No | No | File type. Available values are as follows:<br/> -**dir**: directory;<br/> -**file**: file. |
| subFiles | Array&lt;[FileResponse](#fileresponse)&gt; | No | Yes | File list. |

## FileListResponse

Returns a file list, including the file list information.

**System capability**: SystemCapability.FileManagement.File.FileIO.Lite

| Name | Type | Read-Only | Optional | Description |
| ------ | ------ | ---- | ---- | ----- |
| fileList | Array&lt;[FileResponse](#fileresponse)&gt; | No | No | File list. The format of each file is as follows:<br/>{<br/>uri:'file1',<br/>lastModifiedTime:1589965924479,<br/>length:10240,<br/>type:&nbsp;'file'<br/>} |

## FileReadTextResponse

Returns the text read, including the text content.

**System capability**: SystemCapability.FileManagement.File.FileIO.Lite

| Name | Type | Read-Only | Optional | Description |
| ------ | ------ | ---- | ---- | ----- |
| text | string | No | No | Text read from the specified file. |

## FileReadArrayBufferResponse

Returns the file read, including the file content.

**System capability:** SystemCapability.FileManagement.File.FileIO.Lite

| Name | Type | Read-Only | Optional | Description |
| ------ | ------ | ---- | ---- | ----- |
| buffer | Uint8Array | No | No | Data read.|

## FileMoveOption

Defines the options used in **move()**.

**System capability**: SystemCapability.FileManagement.File.FileIO.Lite

| Name | Type | Read-Only | Optional | Description |
| ------ | ------ | ---- | ---- | ----- |
| srcUri | string | No | No | URI of the file to move. Restricted by the underlying file system of lite wearables, the value must meet the following requirements:<br/>1. The URI cannot contain the following special characters: "\*+,:;<=>?[]\|\x7F<br/>2. The value can contain a maximum of 128 characters. |
| dstUri | string | No | No | URI of the location to which the file is to move. Restricted by the underlying file system of lite wearables, the value must meet the following requirements:<br/>1. The URI cannot contain the following special characters: "\*+,:;<=>?[]\|\x7F<br/>2. The value can contain a maximum of 128 characters. |
| success | (uri: string) => void | No | Yes | Callback invoked when the API call is successful. This API returns the URI of the destination location. |
| fail | (data: string, code: number) => void | No | Yes | Callback invoked when the API call fails.<br/>**data** indicates the error message.<br/>**code** indicates an error code returned:<br/>**202**: parameter error.<br/>**300**: I/O error.<br/>**301**: file or directory not found. |
| complete | () => void | No | Yes | Callback invoked when the API call is complete. |

## FileCopyOption

Optional class that supports the copy API.

**System capability**: SystemCapability.FileManagement.File.FileIO.Lite

| Name | Type | Read-Only | Optional | Description |
| ------ | ------ | ---- | ---- | ----- |
| srcUri | string | No | No | URI of the file to copy. Restricted by the underlying file system of lite wearables, the value must meet the following requirements:<br/>1. The URI cannot contain the following special characters: "\*+,:;<=>?[]\|\x7F<br/>2. The value can contain a maximum of 128 characters. |
| dstUri | string | No | No | URI of the position to which the file is copied.<br/>The app resource path or a URI of the tmp type is not supported. Restricted by the underlying file system of lite wearables, the value must meet the following requirements:<br/>1. The URI cannot contain the following special characters: "\*+,:;<=>?[]\|\x7F<br/>2. The value can contain a maximum of 128 characters. |
| success | (uri: string) => void | No | Yes | Callback invoked when the API call is successful. **uri** indicates the URI of the position to which the file is copied. |
| fail | (data: string, code: number) => void | No | Yes | Callback invoked when the API call fails.<br/>**data** indicates the error message.<br/>**code** indicates an error code returned:<br/>**202**: parameter error.<br/>**300**: I/O error.<br/>**301**: file or directory not found. |
| complete | () => void | No | Yes | Callback invoked when the API call is complete. |

## FileListOption

Defines the options used in **list()**.

**System capability**: SystemCapability.FileManagement.File.FileIO.Lite

| Name | Type | Read-Only | Optional | Description |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | No | No | Directory URI. Restricted by the underlying file system of lite wearables, the value must meet the following requirements:<br/>1. The URI cannot contain the following special characters: "\*+,:;<=>?[]\|\x7F<br/>2. The value can contain a maximum of 128 characters. |
| success | (data: FileListResponse) => void | No | Yes | Callback invoked when the API call is successful. **data** is [FileListResponse](#filelistresponse). |
| fail | (data: string, code: number) => void | No | Yes | Callback invoked when the API call fails.<br/>**data** indicates the error message.<br/>**code** indicates an error code returned:<br/>**202**: parameter error.<br/>**300**: I/O error.<br/>**301**: file or directory not found. |
| complete | () => void | No | Yes | Callback invoked when the API call is complete. |

## FileGetOption

Defines the options used in **get()**.

**System capability**: SystemCapability.FileManagement.File.FileIO.Lite

| Name | Type | Read-Only | Optional | Description |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | No | No | URI of the file. Restricted by the underlying file system of lite wearables, the value must meet the following requirements:<br/>1. The URI cannot contain the following special characters: "\*+,:;<=>?[]\|\x7F<br/>2. The value can contain a maximum of 128 characters. |
| recursive | boolean | No | Yes | Whether to recursively obtain the subdirectory file list. The value **true** indicates recursive operation, and **false** indicates non-recursive operation. The default value is **false**. |
| success | (file: FileResponse) => void | No | Yes | Callback invoked when the API call is successful. **file** is [FileResponse](#fileresponse). |
| fail | (data: string, code: number) => void | No | Yes | Callback invoked when the API call fails.<br/>**data** indicates the error message.<br/>**code** indicates an error code returned:<br/>**202**: parameter error.<br/>**300**: I/O error.<br/>**301**: file or directory not found. |
| complete | () => void | No | Yes | Callback invoked when the API call is complete. |

## FileDeleteOption

Defines the options used in **delete()**.

**System capability**: SystemCapability.FileManagement.File.FileIO.Lite

| Name | Type | Read-Only | Optional | Description |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | No | No | URI of the file to delete. It cannot be an app resource path. Restricted by the underlying file system of lite wearables, the value must meet the following requirements:<br/>1. The URI cannot contain the following special characters: "\*+,:;<=>?[]\|\x7F<br/>2. The value can contain a maximum of 128 characters. |
| success | () => void | No | Yes | Callback invoked when the API call is successful. |
| fail | (data: string, code: number) => void | No | Yes | Callback invoked when the API call fails.<br/>**data** indicates the error message.<br/>**code** indicates an error code returned:<br/>**202**: parameter error.<br/>**300**: I/O error.<br/>**301**: file or directory not found. |
| complete | () => void | No | Yes | Callback invoked when the API call is complete. |

## FileWriteTextOption

Defines the options used in **writeText()**.

**System capability**: SystemCapability.FileManagement.File.FileIO.Lite

| Name | Type | Read-Only | Optional | Description |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | No | No | URI of a local file. If it does not exist, a file will be created. Restricted by the underlying file system of lite wearables, the value must meet the following requirements:<br/>1. The URI cannot contain the following special characters: "\*+,:;<=>?[]\|\x7F<br/>2. The value can contain a maximum of 128 characters. |
| text | string | No | No | String to write into the file. |
| encoding | string | No | Yes | Encoding format. The default value is **UTF-8**. |
| append | boolean | No | Yes | Whether to enable the append mode. The default value is **false**. The value **true** means to enable the append mode; the value **false** means the opposite. |
| success | () => void | No | Yes | Callback invoked when the API call is successful. |
| fail | (data: string, code: number) => void | No | Yes | Callback invoked when the API call fails.<br/>**data** indicates the error message.<br/>**code** indicates an error code returned:<br/>**202**: parameter error.<br/>**300**: I/O error. |
| complete | () => void | No | Yes | Callback invoked when the API call is complete. |

## FileWriteArrayBufferOption

Defines the options used in **writeArrayBuffer()**.

**System capability**: SystemCapability.FileManagement.File.FileIO.Lite

| Name | Type | Read-Only | Optional | Description |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | No | No | URI of the local file. If the file does not exist, it will be created. Restricted by the underlying file system of lite wearables, the value must meet the following requirements:<br/>1. The URI cannot contain the following special characters: "\*+,:;<=>?[]\|\x7F<br/>2. The value can contain a maximum of 128 characters. |
| buffer | Uint8Array | No | No | Buffer from which the data is derived. |
| position | number | No | Yes | Offset of the position in the file where writing starts, in bytes. The default value is **0**. |
| append | boolean | No | Yes | Whether to enable the append mode. The default value is **false**. If the value is **true**, the **position** parameter will become invalid. The value **true** means to enable the append mode; the value **false** means the opposite. |
| success | () => void | No | Yes | Callback invoked when the API call is successful. |
| fail | (data: string, code: number) => void | No | Yes | Callback invoked when the API call fails.<br/>**data** indicates the error message.<br/>**code** indicates an error code returned:<br/>**202**: parameter error.<br/>**300**: I/O error. |
| complete | () => void | No | Yes | Callback invoked when the API call is complete. |

## FileReadTextOption

Defines the options used in **readText()**.

**System capability**: SystemCapability.FileManagement.File.FileIO.Lite

| Name | Type | Read-Only | Optional | Description |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | No | No | URI of a local file. Restricted by the underlying file system of lite wearables, the value must meet the following requirements:<br/>1. The URI cannot contain the following special characters: "\*+,:;<=>?[]\|\x7F<br/>2. The value can contain a maximum of 128 characters. |
| encoding | string | No | Yes | Encoding format. The default value is **UTF-8**. |
| position | number | No | Yes | Position where the reading starts, in bytes. The default value is the start position of the file. |
| length | number | No | Yes | Length of the data to be read. The value range is [1, 4096], in bytes. If this parameter is left empty, the default value **4096** is used. |
| success | (data: FileReadTextResponse) => void | No | Yes | Callback invoked when the API call is successful. **data** is [FileReadTextResponse](#filereadtextresponse). |
| fail | (data: string, code: number) => void | No | Yes | Callback invoked when the API call fails.<br/>**data** indicates the error message.<br/>**code** indicates an error code returned:<br/>**202**: parameter error.<br/>**300**: I/O error.<br/>**301**: file or directory not found.<br/>**302**: the file content to read exceeds 4 KB. |
| complete | () => void | No | Yes | Callback invoked when the API call is complete. |

## FileReadArrayBufferOption

Defines the options used in **readArrayBuffer()**.

**System capability**: SystemCapability.FileManagement.File.FileIO.Lite

| Name | Type | Read-Only | Optional | Description |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | No | No | URI of a local file. Restricted by the underlying file system of lite wearables, the value must meet the following requirements:<br/>1. The URI cannot contain the following special characters: "\*+,:;<=>?[]\|\x7F<br/>2. The value can contain a maximum of 128 characters. |
| position | number | No | Yes | Position where the reading starts, in bytes. The default value is the start position of the file. |
| length | number | No | Yes | Length of data to read, in bytes. If this parameter is not set, the reading proceeds until the end of the file. |
| success | (data: FileReadArrayBufferResponse) => void | No | Yes | Callback invoked when the API call is successful. **data** is [FileReadArrayBufferResponse](#filereadarraybufferresponse). |
| fail | (data: string, code: number) => void | No | Yes | Callback invoked when the API call fails.<br/>**data** indicates the error message.<br/>**code** indicates an error code returned:<br/>**202**: parameter error.<br/>**300**: I/O error.<br/>**301**: file or directory not found. |
| complete | () => void | No | Yes | Callback invoked when the API call is complete. |

## FileAccessOption

Defines the options used in **access()**.

**System capability**: SystemCapability.FileManagement.File.FileIO.Lite

| Name | Type | Read-Only | Optional | Description |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | No | No | URI of the directory or file. Restricted by the underlying file system of lite wearables, the value must meet the following requirements:<br/>1. The URI cannot contain the following special characters: "\*+,:;<=>?[]\|\x7F<br/>2. The value can contain a maximum of 128 characters. |
| success | () => void | No | Yes | Callback invoked when the API call is successful. |
| fail | (data: string, code: number) => void | No | Yes | Callback invoked when the API call fails.<br/>**data** indicates the error message.<br/>**code** indicates an error code returned:<br/>**202**: parameter error.<br/>**300**: I/O error.<br/>**301**: file or directory not found. |
| complete | () => void | No | Yes | Callback invoked when the API call is complete. |

## FileMkdirOption

Defines the options used in **mkdir()**.

**System capability:** SystemCapability.FileManagement.File.FileIO.Lite

| Name | Type | Read-Only | Optional | Description |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | No | No | URI of the directory. Restricted by the underlying file system of lite wearables, the value must meet the following requirements:<br/>1. The URI cannot contain the following special characters: "\*+,:;<=>?[]\|\x7F<br/>2. The value can contain a maximum of 128 characters. |
| recursive | boolean | No | Yes | Whether to recursively create the upper-level directory of the specified directory. The default value is **false**. The value **true** means to create upper-level directory recursively; the value **false** means the opposite. |
| success | () => void | No | Yes | Callback invoked when the API call is successful. |
| fail | (data: string, code: number) => void | No | Yes | Callback invoked when the API call fails.<br/>**data** indicates the error message.<br/>**code** indicates an error code returned:<br/>**202**: parameter error.<br/>**300**: I/O error. |
| complete | () => void | No | Yes | Callback invoked when the API call is complete. |

## FileRmdirOption

Defines the options used in **rmdir()**.

**System capability**: SystemCapability.FileManagement.File.FileIO.Lite

| Name | Type | Read-Only | Optional | Description |
| ------ | ------ | ---- | ---- | ----- |
| uri | string | No | No | URI of the directory. Restricted by the underlying file system of lite wearables, the value must meet the following requirements:<br/>1. The URI cannot contain the following special characters: "\*+,:;<=>?[]\|\x7F<br/>2. The value can contain a maximum of 128 characters. |
| recursive | boolean | No | Yes | Whether to recursively delete files and subdirectories of the specified directory. The default value is **false**. The value **true** means to recursively delete files and subdirectories of the specified directory; the value **false** means the opposite. |
| success | () => void | No | Yes | Callback invoked when the API call is successful. |
| fail | (data: string, code: number) => void | No | Yes | Callback invoked when the API call fails.<br/>**data** indicates the error message.<br/>**code** indicates an error code returned:<br/>**202**: parameter error.<br/>**300**: I/O error.<br/>**301**: file or directory not found. |
| complete | () => void | No | Yes | Callback invoked when the API call is complete. |