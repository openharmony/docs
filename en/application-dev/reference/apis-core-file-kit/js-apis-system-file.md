# @system.file (File Storage)

> **NOTE**
>
> - The APIs provided by this module are no longer maintained since API Version 10. You are advised to use [@ohos.file.fs](js-apis-file-fs.md).
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import file from '@system.file';
```


## file.move

move(Object): void

Moves a file to the given location.

> **NOTE**
>
> This API is deprecated since API version 10. Use [fs.moveFile](js-apis-file-fs.md#fsmovefile) instead.

**System Capability**: SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| srcUri | string | Yes| Uniform resource identifier (URI) of the file to move. <br/>The URI can contain a maximum of 128 characters, excluding the following characters: "\*+,:;&lt;=&gt;?[]\|\x7F |
| dstUri | string | Yes| URI of the location to which the file is to move. <br/>The URI can contain a maximum of 128 characters, excluding the following characters: "\*+,:;&lt;=&gt;?[]\|\x7F|
| success | Function | No| Called when the file is moved to the specified location. This API returns the URI of the destination location.|
| fail | Function | No| Called when the file fails to be moved.|
| complete | Function | No| Called when the execution is complete.|

**Error codes**

| Error Code| Description|
| -------- | -------- |
| 202 | Incorrect parameters are detected.|
| 300 | An I/O error occurs.|
| 301 | The file or directory does not exist.|

**Example**

```
export default {    
  move() {        
    file.move({            
      srcUri: 'internal://app/myfiles1',            
      dstUri: 'internal://app/myfiles2',            
      success: function(uri) {                
        console.log('call success callback success');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },        
    });    
  }
}
```

## file.copy

copy(Object): void

Copies a file to the given URI.

> **NOTE**
>
> This API is deprecated since API version 10. Use [fs.copyFile](js-apis-file-fs.md#fscopyfile) instead.

**System Capability**: SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| srcUri | string | Yes| URI of the file to copy.|
| dstUri | string | Yes| URI of the location to which the copy is to be saved.<br>The directory of application resources and URI of the **tmp** type are not supported.|
| success | Function | No| Called when the file is copied and saved to the specified location. This API returns the URI of the destination location.|
| fail | Function | No| Called when the file fails to be copied.|
| complete | Function | No| Called when the execution is complete.|

**Error codes**

| Error Code| Description|
| -------- | -------- |
| 202 | Incorrect parameters are detected.|
| 300 | An I/O error occurs.|
| 301 | The file or directory does not exist.|

**Example**

```
export default {    
  copy() {        
    file.copy({            
      srcUri: 'internal://app/file.txt',            
      dstUri: 'internal://app/file_copy.txt',            
      success: function(uri) {                
        console.log('call success callback success');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```


## file.list

list(Object): void

Obtains all files in the specified directory.

> **NOTE**
>
> This API is deprecated since API version 10. Use [fs.listFile](js-apis-file-fs.md#fslistfile) instead.

**System Capability**: SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the directory. <br/>The URI can contain a maximum of 128 characters, excluding the following characters: "\*+,:;&lt;=&gt;?[]\|\x7F |
| success | Function | No| Called when the file list is obtained.|
| fail | Function | No| Called when the file list fails to be obtained.|
| complete | Function | No| Called when the execution is complete.|

**Return value of success()**

| Name| Type| Description|
| -------- | -------- | -------- |
| fileList | Array&lt;FileInfo&gt; | File list. The format of each file is as follows:<br>{<br>uri:'file1',<br>lastModifiedTime:1589965924479,<br>length:10240,<br>type:&nbsp;'file'<br>} |

**Table 1** FileInfo

| Name| Type| Description|
| -------- | -------- | -------- |
| uri | string | URI of the file.|
| lastModifiedTime | number | Timestamp when the file is saved the last time, which is the number of milliseconds elapsed since 1970/01/01 00:00:00 GMT.|
| length | number | File size, in bytes.|
| type | string | File type. Available values are as follows:<br>- **dir**: directory<br>-&nbsp;**file**: file|

**Error codes**

| Error Code| Description|
| -------- | -------- |
| 202 | Incorrect parameters are detected.|
| 300 | An I/O error occurs.|
| 301 | The file or directory does not exist.|

**Example**

```
export default {    
  list() {        
    file.list({            
      uri: 'internal://app/pic',            
      success: function(data) {                
        console.log(JSON.stringify(data.fileList));            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },        
    });    
  }
}
```


## file.get

get(Object): void

Obtains information about a local file.

> **NOTE**
>
> This API is deprecated since API version 10. Use [fs.stat](js-apis-file-fs.md#fsstat) instead.

**System Capability**: SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the file.|
| recursive | boolean | No| Whether to obtain the subdirectory file list recursively. The value **true** means to obtain the subdirectory file list recursively; the value **false** means the opposite.|
| success | Function | No| Called when the file information is obtained.|
| fail | Function | No| Called when the file information fails to be obtained.|
| complete | Function | No| Called when the execution is complete.|

**Return value of success()**

| Name| Type| Description|
| -------- | -------- | -------- |
| uri | string | URI of the file.|
| length | number | File size, in bytes.|
| lastModifiedTime | number | Timestamp when the file is saved the last time, which is the number of milliseconds elapsed since 1970/01/01 00:00:00 GMT.|
| type | string | File type. Available values are as follows:<br>- &nbsp;**dir**: directory<br>-&nbsp;**file**: file|
| subFiles | Array | List of files.|

**Error codes**

| Error Code| Description|
| -------- | -------- |
| 202 | Incorrect parameters are detected.|
| 300 | An I/O error occurs.|
| 301 | The file or directory does not exist.|

**Example**

```
export default {    
  get() {        
    file.get({            
      uri: 'internal://app/file',            
      success: function(data) {                
        console.log(data.uri);            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```


## file.delete

delete(Object): void

Deletes a local file.

> **NOTE**
>
> This API is deprecated since API version 10. Use [fs.unlink](js-apis-file-fs.md#fsunlink) instead.

**System Capability**: SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the file to delete. It cannot be an application resource path.|
| success | Function | No| Called when the file is deleted.|
| fail | Function | No| Called when the file fails to be deleted.|
| complete | Function | No| Called when the execution is complete.|

**Error codes**

| Error Code| Description|
| -------- | -------- |
| 202 | Incorrect parameters are detected.|
| 300 | An I/O error occurs.|
| 301 | The file or directory does not exist.|

**Example**

```
export default {    
  delete() {        
    file.delete({            
      uri: 'internal://app/my_file',            
      success: function() {                
        console.log('call delete success.');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```


## file.writeText

writeText(Object): void

Writes text into a file. Only text files can be read and written.

> **NOTE**
>
> This API is deprecated since API version 10. Use [fs.write](js-apis-file-fs.md#fswrite) instead.

**System Capability**: SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of a local file. If it does not exist, a file will be created.|
| text | string | Yes| Text to write into the file. |
| encoding | string | No| Encoding format. The default format is **UTF-8**.|
| append | boolean | No| Whether to enable the append mode. The default value is **false**. The value **true** means to enable the append mode; the value **false** means the opposite.|
| success | Function | No| Called when the text is written into the specified file.|
| fail | Function | No| Called when the text fails to be written into the file.|
| complete | Function | No| Called when the execution is complete.|

**Error codes**

| Error Code| Description|
| -------- | -------- |
| 202 | Incorrect parameters are detected.|
| 300 | An I/O error occurs.|

**Example**

```
export default {    
  writeText() {        
    file.writeText({            
      uri: 'internal://app/test.txt',            
      text: 'Text that just for test.',            
      success: function() {                
        console.log('call writeText success.');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },        
    });    
  }
}
```


## file.writeArrayBuffer

writeArrayBuffer(Object): void

Writes buffer data into a file. Only text files can be read and written.

> **NOTE**
>
> This API is deprecated since API version 10. Use [fs.write](js-apis-file-fs.md#fswrite) instead.

**System Capability**: SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of a local file. If it does not exist, a file will be created.|
| buffer | Uint8Array | Yes| Buffer from which the data is derived.|
| position | number | No| Offset to the position where the writing starts. The default value is **0**.|
| append | boolean | No| Whether to enable the append mode. The default value is **false**. If the value is **true**, the **position** parameter will become invalid. The value **true** means to enable the append mode; the value **false** means the opposite.|
| success | Function | No| Called when buffer data is written into the file. |
| fail | Function | No| Called when buffer data fails to be written into the file.|
| complete | Function | No| Called when the execution is complete.|

**Error codes**

| Error Code| Description|
| -------- | -------- |
| 202 | Incorrect parameters are detected.|
| 300 | An I/O error occurs.|

**Example**

```
export default {    
  writeArrayBuffer() {       
    file.writeArrayBuffer({           
      uri: 'internal://app/test',           
      buffer: new Uint8Array(8), // The buffer is of the Uint8Array type.          
      success: function() {                
        console.log('call writeArrayBuffer success.');            
      },           
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```


## file.readText

readText(Object): void

Reads text from a file. Only text files can be read and written.

> **NOTE**
>
> This API is deprecated since API version 10. Use [fs.readText](js-apis-file-fs.md#fsreadtext) instead.

**System Capability**: SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of a local file.|
| encoding | string | No| Encoding format. The default format is **UTF-8**.|
| position | number | No| Position where the reading starts. The default value is the start position of the file.|
| length | number | No| Length of the text to read, in bytes. The default value is **4096**.|
| success | Function | No| Called when the text is read successfully.|
| fail | Function | No| Called when the text failed to be read.|
| complete | Function | No| Called when the execution is complete.|

**Return value of success()**

| Name| Type| Description|
| -------- | -------- | -------- |
| text | string | Text read from the specified file.|

**Error codes**

| Error Code| Description|
| -------- | -------- |
| 202 | Incorrect parameters are detected.|
| 300 | An I/O error occurs.|
| 301 | The file or directory does not exist.|
| 302 | The text to read exceeds 4 KB.|

**Example**

```
export default {    
  readText() {        
    file.readText({            
      uri: 'internal://app/text.txt',            
      success: function(data) {                
        console.log('call readText success: ' + data.text);            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },        
    });    
  }
}
```


## file.readArrayBuffer

readArrayBuffer(Object): void

Reads buffer data from a file. Only text files can be read and written.

> **NOTE**
>
> This API is deprecated since API version 10. Use [fs.read](js-apis-file-fs.md#fsread) instead.

**System Capability**: SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of a local file.|
| position | number | No| Position where the reading starts. The default value is the start position of the file.|
| length | number | No| Length of data to read. If this parameter is not set, the reading proceeds until the end of the file.|
| success | Function | No| Called when the buffer data is read successfully.|
| fail | Function | No| Called when the buffer data fails to be read.|
| complete | Function | No| Called when the execution is complete.|

**Return value of success()**

| Name| Type| Description|
| -------- | -------- | -------- |
| buffer | Uint8Array | Data read.|

**Error codes**

| Error Code| Description|
| -------- | -------- |
| 202 | Incorrect parameters are detected.|
| 300 | An I/O error occurs.|
| 301 | The file or directory does not exist.|

**Example**

```
export default {    
  readArrayBuffer() {        
    file.readArrayBuffer({            
      uri: 'internal://app/test',            
      position: 10,            
      length: 200,            
      success: function(data) {                
        console.log('call readArrayBuffer success: ' + data.buffer);            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```


## file.access

access(Object): void

Checks whether a file or directory exists.

> **NOTE**
>
> This API is deprecated since API version 10. Use [fs.access](js-apis-file-fs.md#fsaccess) instead.

**System Capability**: SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the directory or file to check.|
| success | Function | No| Called when the operation is successful.|
| fail | Function | No| Called when the operation fails.|
| complete | Function | No| Called when the execution is complete.|

**Error codes**

| Error Code| Description|
| -------- | -------- |
| 202 | Incorrect parameters are detected.|
| 300 | An I/O error occurs.|
| 301 | The file or directory does not exist.|

**Example**

```
export default {    
  access() {        
    file.access({            
      uri: 'internal://app/test',            
      success: function() {                
        console.log('call access success.');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },        
    });    
  }
}
```


## file.mkdir

mkdir(Object): void

Creates a directory.

> **NOTE**
>
> This API is deprecated since API version 10. Use [fs.mkdir](js-apis-file-fs.md#fsmkdir) instead.

**System Capability**: SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the directory to create.|
| recursive | boolean | No| Whether to recursively create upper-level directories of the specified directory. The default value is **false**.|
| success | Function | No| Called when the directory is created.|
| fail | Function | No| Called when the directory fails to be created.|
| complete | Function | No| Called when the execution is complete.|

**Error codes**

| Error Code| Description|
| -------- | -------- |
| 202 | Incorrect parameters are detected.|
| 300 | An I/O error occurs.|

**Example**

```
export default {    
  mkdir() {        
    file.mkdir({            
      uri: 'internal://app/test_directory',            
      success: function() {                
        console.log('call mkdir success.');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```


## file.rmdir

rmdir(Object): void

Deletes a directory.

> **NOTE**
>
> This API is deprecated since API version 10. Use [fs.rmdir](js-apis-file-fs.md#fsrmdir) instead.

**System Capability**: SystemCapability.FileManagement.File.FileIO.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the directory to delete.|
| recursive | boolean | No| Whether to recursively delete files and subdirectories of the specified directory. The default value is **false**. The value **true** means to recursively delete files and subdirectories of the specified directory; the value **false** means the opposite.|
| success | Function | No| Called when the directory is deleted.|
| fail | Function | No| Called when the directory fails to be deleted.|
| complete | Function | No| Called when the execution is complete.|

**Error codes**

| Error Code| Description|
| -------- | -------- |
| 202 | Incorrect parameters are detected.|
| 300 | An I/O error occurs.|
| 301 | The file or directory does not exist.|

**Example**

```
export default {    
  rmdir() {        
    file.rmdir({            
      uri: 'internal://app/test_directory',            
      success: function() {                
        console.log('call rmdir success.');            
      },            
      fail: function(data, code) {                
        console.error('call fail callback fail, code: ' + code + ', data: ' + data);            
      },
    });    
  }
}
```
