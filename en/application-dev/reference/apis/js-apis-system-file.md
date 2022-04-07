# File Storage



> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
> - The APIs of this module are no longer maintained since API version 6. It is recommended that you use [`@ohos.fileio`](js-apis-fileio.md) instead.
> 
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import file from '@system.file';
```


## file.move

move(Object): void

Moves a specified file to a given location.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| srcUri | string | Yes | URI&nbsp;of&nbsp;the&nbsp;file&nbsp;to&nbsp;move. |
| dstUri | string | Yes | URI&nbsp;of&nbsp;the&nbsp;location&nbsp;to&nbsp;which&nbsp;the&nbsp;file&nbsp;is&nbsp;to&nbsp;move. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;source&nbsp;file&nbsp;is&nbsp;moved&nbsp;to&nbsp;the&nbsp;specified&nbsp;location&nbsp;successfully.&nbsp;This&nbsp;function&nbsp;returns&nbsp;the&nbsp;URI&nbsp;of&nbsp;the&nbsp;destination&nbsp;location. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

One of the following error codes will be returned if the operation fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 202 | Invalid&nbsp;parameter. |
| 300 | I/O&nbsp;error. |
| 301 | File&nbsp;or&nbsp;directory&nbsp;not&nbsp;exist. |

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

Copies a file and saves the copy to a specified location. 

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| srcUri | string | Yes | URI&nbsp;of&nbsp;the&nbsp;file&nbsp;to&nbsp;copy. |
| dstUri | string | Yes | URI&nbsp;of&nbsp;the&nbsp;location&nbsp;to&nbsp;which&nbsp;the&nbsp;copy&nbsp;is&nbsp;to&nbsp;save.<br>The&nbsp;directory&nbsp;of&nbsp;application&nbsp;resources&nbsp;and&nbsp;URI&nbsp;of&nbsp;the&nbsp;**tmp**&nbsp;type&nbsp;are&nbsp;not&nbsp;supported. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;source&nbsp;file&nbsp;is&nbsp;copied&nbsp;and&nbsp;saved&nbsp;to&nbsp;the&nbsp;specified&nbsp;location&nbsp;successfully.&nbsp;This&nbsp;function&nbsp;returns&nbsp;the&nbsp;URI&nbsp;of&nbsp;the&nbsp;destination&nbsp;location. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

One of the following error codes will be returned if the operation fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 202 | Invalid&nbsp;parameter. |
| 300 | I/O&nbsp;error. |
| 301 | File&nbsp;or&nbsp;directory&nbsp;not&nbsp;exist. |

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

Obtains the list of all files in a specified directory. 

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| uri | string | Yes | URI&nbsp;of&nbsp;the&nbsp;directory. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

Return values of the **success** callback

| Name | Type | Description |
| -------- | -------- | -------- |
| fileList | Array&lt;FileInfo&gt; | File&nbsp;list.&nbsp;The&nbsp;format&nbsp;of&nbsp;each&nbsp;file&nbsp;is&nbsp;as&nbsp;follows:<br/>{<br/>uri:'file1',<br/>lastModifiedTime:1589965924479,<br/>length:10240,<br/>type:&nbsp;'file'<br/>} |

**Table1** FileInfo

| Name | Type | Description |
| -------- | -------- | -------- |
| uri | string | File&nbsp;URI. |
| lastModifiedTime | number | Timestamp&nbsp;when&nbsp;the&nbsp;file&nbsp;is&nbsp;stored&nbsp;the&nbsp;last&nbsp;time,&nbsp;which&nbsp;is&nbsp;the&nbsp;number&nbsp;of&nbsp;milliseconds&nbsp;elapsed&nbsp;since&nbsp;1970/01/01&nbsp;00:00:00&nbsp;GMT. |
| length | number | File&nbsp;size,&nbsp;in&nbsp;bytes. |
| type | string | File&nbsp;type.&nbsp;Available&nbsp;values&nbsp;are&nbsp;as&nbsp;follows:<br/>-&nbsp;**dir**:&nbsp;directory<br/>-&nbsp;**file**:&nbsp;file |

One of the following error codes will be returned if the operation fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 202 | Invalid&nbsp;parameter. |
| 300 | I/O&nbsp;error. |
| 301 | File&nbsp;or&nbsp;directory&nbsp;not&nbsp;exist. |

**Example**

```
export default {    
  list() {        
    file.list({            
      uri: 'internal://app/pic',            
      success: function(data) {                
        console.log(data.fileList);            
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

Obtains information about a specified local file. 

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| uri | string | Yes | File&nbsp;URI. |
| recursive | boolean | No | Whether&nbsp;to&nbsp;recursively&nbsp;obtain&nbsp;the&nbsp;file&nbsp;list&nbsp;under&nbsp;a&nbsp;subdirectory.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**false**. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

Return values of the **success** callback

| Name | Type | Description |
| -------- | -------- | -------- |
| uri | string | File&nbsp;URI. |
| length | number | File&nbsp;size,&nbsp;in&nbsp;bytes. |
| lastModifiedTime | number | Timestamp&nbsp;when&nbsp;the&nbsp;file&nbsp;is&nbsp;stored&nbsp;the&nbsp;last&nbsp;time,&nbsp;which&nbsp;is&nbsp;the&nbsp;number&nbsp;of&nbsp;milliseconds&nbsp;elapsed&nbsp;since&nbsp;1970/01/01&nbsp;00:00:00&nbsp;GMT. |
| type | string | File&nbsp;type.&nbsp;The&nbsp;values&nbsp;are&nbsp;as&nbsp;follows:<br/>-&nbsp;**dir**:&nbsp;directory<br/>-&nbsp;**file**:&nbsp;file |
| subFiles | Array | File&nbsp;list. |

One of the following error codes will be returned if the operation fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 202 | Invalid&nbsp;parameter. |
| 300 | I/O&nbsp;error. |
| 301 | File&nbsp;or&nbsp;directory&nbsp;not&nbsp;exist. |

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

Deletes local files. 

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| uri | string | Yes | URI&nbsp;of&nbsp;the&nbsp;file&nbsp;to&nbsp;delete,&nbsp;which&nbsp;cannot&nbsp;be&nbsp;an&nbsp;application&nbsp;resource&nbsp;path. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

One of the following error codes will be returned if the operation fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 202 | Incorrect&nbsp;parameter. |
| 300 | I/O&nbsp;error. |
| 301 | File&nbsp;or&nbsp;directory&nbsp;not&nbsp;exist. |

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

Writes text into a specified file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| uri | string | Yes | URI&nbsp;of&nbsp;a&nbsp;local&nbsp;file.&nbsp;If&nbsp;it&nbsp;does&nbsp;not&nbsp;exist,&nbsp;a&nbsp;file&nbsp;will&nbsp;be&nbsp;created. |
| text | string | Yes | Character&nbsp;string&nbsp;to&nbsp;write&nbsp;into&nbsp;the&nbsp;local&nbsp;file. |
| encoding | string | No | Encoding&nbsp;format.&nbsp;The&nbsp;default&nbsp;format&nbsp;is&nbsp;UTF-8. |
| append | boolean | No | Whether&nbsp;to&nbsp;enable&nbsp;the&nbsp;append&nbsp;mode.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**false**. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

One of the following error codes will be returned if the operation fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 202 | Incorrect&nbsp;parameter. |
| 300 | I/O&nbsp;error. |

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

Writes buffer data into a specified file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| uri | string | Yes | URI&nbsp;of&nbsp;a&nbsp;local&nbsp;file.&nbsp;If&nbsp;it&nbsp;does&nbsp;not&nbsp;exist,&nbsp;a&nbsp;file&nbsp;will&nbsp;be&nbsp;created. |
| buffer | Uint8Array | Yes | Buffer&nbsp;from&nbsp;which&nbsp;the&nbsp;data&nbsp;is&nbsp;derived. |
| position | number | No | Offset&nbsp;to&nbsp;the&nbsp;position&nbsp;where&nbsp;the&nbsp;writing&nbsp;starts.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**0**. |
| append | boolean | No | Whether&nbsp;to&nbsp;enable&nbsp;the&nbsp;append&nbsp;mode.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**false**.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;**true**,&nbsp;the&nbsp;**position**&nbsp;parameter&nbsp;will&nbsp;become&nbsp;invalid. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

One of the following error codes will be returned if the operation fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 202 | Invalid&nbsp;parameter. |
| 300 | I/O&nbsp;error. |

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

Reads text from a specified file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| uri | string | Yes | URI&nbsp;of&nbsp;a&nbsp;local&nbsp;file. |
| encoding | string | No | Encoding&nbsp;format.&nbsp;The&nbsp;default&nbsp;format&nbsp;is&nbsp;UTF-8. |
| position | number | No | Position&nbsp;where&nbsp;the&nbsp;reading&nbsp;starts.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;the&nbsp;start&nbsp;position&nbsp;of&nbsp;the&nbsp;file. |
| length | number | No | Length&nbsp;of&nbsp;the&nbsp;text&nbsp;to&nbsp;be&nbsp;read&nbsp;(in&nbsp;bytes).&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**4096**. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

Return values of the **success** callback

| Name | Type | Description |
| -------- | -------- | -------- |
| text | string | Text&nbsp;read&nbsp;from&nbsp;the&nbsp;specified&nbsp;file. |

One of the following error codes will be returned if the operation fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 202 | Invalid&nbsp;parameter. |
| 300 | I/O&nbsp;error. |
| 301 | The&nbsp;file&nbsp;or&nbsp;directory&nbsp;does&nbsp;not&nbsp;exist. |
| 302 | The&nbsp;size&nbsp;of&nbsp;text&nbsp;to&nbsp;read&nbsp;exceeds&nbsp;4096&nbsp;bytes. |

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

Reads buffer data from a specified file.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| uri | string | Yes | URI&nbsp;of&nbsp;a&nbsp;local&nbsp;file. |
| position | number | No | Position&nbsp;where&nbsp;the&nbsp;reading&nbsp;starts.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;the&nbsp;start&nbsp;position&nbsp;of&nbsp;the&nbsp;file. |
| length | number | No | Length&nbsp;of&nbsp;data&nbsp;to&nbsp;read.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;the&nbsp;reading&nbsp;proceeds&nbsp;until&nbsp;the&nbsp;end&nbsp;of&nbsp;the&nbsp;file. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

Return values of the **success** callback

| Name | Type | Description |
| -------- | -------- | -------- |
| buffer | Uint8Array | File&nbsp;content&nbsp;that&nbsp;is&nbsp;read |

One of the following error codes will be returned if the operation fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 202 | Invalid&nbsp;parameter. |
| 300 | I/O&nbsp;error. |
| 301 | File&nbsp;or&nbsp;directory&nbsp;not&nbsp;exist. |

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

Checks whether a specified file or directory exists.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| uri | string | Yes | URI&nbsp;of&nbsp;the&nbsp;directory&nbsp;or&nbsp;file. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

One of the following error codes will be returned if the operation fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 202 | Invalid&nbsp;parameter. |
| 300 | I/O&nbsp;error. |
| 301 | File&nbsp;or&nbsp;directory&nbsp;not&nbsp;exist. |

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

Creates a specified directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| uri | string | Yes | URI&nbsp;of&nbsp;the&nbsp;directory. |
| recursive | boolean | No | Whether&nbsp;to&nbsp;recursively&nbsp;create&nbsp;upper-level&nbsp;directories&nbsp;of&nbsp;the&nbsp;specified&nbsp;directory.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**false**. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

One of the following error codes will be returned if the operation fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 202 | Invalid&nbsp;parameter. |
| 300 | I/O&nbsp;error. |

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

Deletes a specified directory.

**System capability**: SystemCapability.FileManagement.File.FileIO

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| uri | string | Yes | URI&nbsp;of&nbsp;the&nbsp;directory. |
| recursive | boolean | No | Whether&nbsp;to&nbsp;recursively&nbsp;delete&nbsp;subfiles&nbsp;and&nbsp;subdirectories&nbsp;of&nbsp;the&nbsp;specified&nbsp;directory.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**false**. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

One of the following error codes will be returned if the operation fails.

| Error&nbsp;Code | Description |
| -------- | -------- |
| 202 | Invalid&nbsp;parameter. |
| 300 | I/O&nbsp;error. |
| 301 | File&nbsp;or&nbsp;directory&nbsp;not&nbsp;exist. |

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