# @system.file (文件存储)

> **说明：**
>
> - 从API Version 10开始，该接口不再维护，推荐使用新接口[`@ohos.file.fs`](js-apis-file-fs.md)。
> - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import file from '@system.file';
```


## file.move

move(Object): void

将指定文件移动到其他指定位置。

> **说明**： 
>
> 从API version 10开始废弃，请使用[fs.moveFile](js-apis-file-fs.md#fsmovefile)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| srcUri | string | 是 | 要移动的文件的uri。字符串最大长度为128，且不能包含“"\*+,:;&lt;=&gt;?[]\|\x7F”等特殊符号。 |
| dstUri | string | 是 | 文件要移动到的位置的uri。字符串最大长度为128，且不能包含“"\*+,:;&lt;=&gt;?[]\|\x7F”等特殊符号。 |
| success | Function | 否 | 接口调用成功的回调函数，返回文件要移动到的位置的uri。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 202 | 出现参数错误。 |
| 300 | 出现I/O错误。 |
| 301 | 文件或目录不存在。 |

**示例：**

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

将指定文件拷贝并存储到指定位置。

> **说明**：
>
> 从API version 10开始废弃，请使用[fs.copyFile](js-apis-file-fs.md#fscopyfile)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| srcUri | string | 是 | 要拷贝的文件的uri。 |
| dstUri | string | 是 | 文件要拷贝到的位置的uri。<br/>不支持用应用资源路径或tmp类型的uri。 |
| success | Function | 否 | 接口调用成功的回调函数，返回文件要拷贝到的位置的uri。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 202 | 出现参数错误。 |
| 300 | 出现I/O错误。 |
| 301 | 文件或目录不存在。 |

**示例：**

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

获取指定路径下全部文件的列表。

> **说明**： 
>
> 从API version 10开始废弃，请使用[fs.listFile](js-apis-file-fs.md#fslistfile)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | 目录uri。字符串最大长度为128，且不能包含“"\*+,:;&lt;=&gt;?[]\|\x7F”等特殊符号。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

success返回值：

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| fileList | Array&lt;FileInfo&gt; | 获取的文件列表，其中每个文件的信息的格式为：<br/>{<br/>uri:'file1',<br/>lastModifiedTime:1589965924479,<br/>length:10240,<br/>type:&nbsp;'file'<br/>} |

**表1** FileInfo

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| uri | string | 文件的&nbsp;uri。 |
| lastModifiedTime | number | 文件上一次保存时的时间戳，显示从1970/01/01&nbsp;00:00:00&nbsp;GMT到当前时间的毫秒数。 |
| length | number | 文件的大小，单位为字节。 |
| type | string | 文件的类型，可选值为：<br/>-&nbsp;dir：目录；<br/>-&nbsp;file：文件。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 202 | 出现参数错误。 |
| 300 | 出现I/O错误。 |
| 301 | 文件或目录不存在。 |

**示例：**

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

获取指定本地文件的信息。

> **说明**： 
>
> 从API version 10开始废弃，请使用[fs.stat](js-apis-file-fs.md#fsstat)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | 文件的uri。 |
| recursive | boolean | 否 | 是否进行递归获取子目录文件列表，true为进行该操作，缺省为false。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

success返回值：

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| uri | string | 文件的uri。 |
| length | number | 文件字节长。 |
| lastModifiedTime | number | 文件保存时的时间戳，从1970/01/01&nbsp;00:00:00到当前时间的毫秒数。 |
| type | string | 文件类型，可选值为：<br/>-&nbsp;dir：目录；<br/>-&nbsp;file：文件。 |
| subFiles | Array | 文件列表。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 202 | 出现参数错误。 |
| 300 | 出现I/O错误。 |
| 301 | 文件或目录不存在。 |

**示例：**

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

删除本地文件。

> **说明**： 
>
> 从API version 10开始废弃，请使用[fs.unlink](js-apis-file-fs.md#fsunlink)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | 删除文件的uri，不能是应用资源路径。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 202 | 参数错误。 |
| 300 | I/O错误。 |
| 301 | 文件或目录不存在。 |

**示例：**

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

写文本内容到指定文件。仅支持文本文档读写。

> **说明**： 
>
> 从API version 10开始废弃，请使用[fs.write](js-apis-file-fs.md#fswrite)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | 本地文件uri，如果文件不存在会创建文件。 |
| text | string | 是 | 写入的字符串。 |
| encoding | string | 否 | 编码格式，默认为UTF-8。 |
| append | boolean | 否 | 是否追加模式，默认为false。true为追加，false为不追加。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 202 | 参数错误。 |
| 300 | I/O错误。 |

**示例：**

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

写Buffer内容到指定文件。仅支持文本文档读写。

> **说明**： 
>
> 从API version 10开始废弃，请使用[fs.write](js-apis-file-fs.md#fswrite)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | 本地文件uri，如果文件不存在会创建文件。 |
| buffer | Uint8Array | 是 | 写入的Buffer。 |
| position | number | 否 | 文件开始写入数据的位置的偏移量，默认为0。 |
| append | boolean | 否 | 是否追加模式，默认为false。当设置为true时，position参数无效。true为追加，false为不追加。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 202 | 出现参数错误。 |
| 300 | 出现I/O错误。 |

**示例：**

```
export default {    
  writeArrayBuffer() {       
    file.writeArrayBuffer({           
      uri: 'internal://app/test',           
      buffer: new Uint8Array(8), //buffer为Uint8Array类型           
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

从指定文件中读取文本内容。仅支持文本文档读写。

> **说明**： 
>
> 从API version 10开始废弃，请使用[fs.readText](js-apis-file-fs.md#fsreadtext)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | 本地文件uri。 |
| encoding | string | 否 | 编码格式，缺省为UTF-8。 |
| position | number | 否 | 读取的起始位置，默认值为文件的起始位置。 |
| length | number | 否 | 读取的长度，默认值为4096。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

success返回值：

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| text | string | 读取到的文本内容。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 202 | 出现参数错误。 |
| 300 | 出现I/O错误。 |
| 301 | 文件或目录不存在。 |
| 302 | 要读取的文件内容超过4KB。 |

**示例：**

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

从指定文件中读取Buffer内容。仅支持文本文档读写。

> **说明**： 
>
> 从API version 10开始废弃，请使用[fs.read](js-apis-file-fs.md#fsread)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | 本地文件uri。 |
| position | number | 否 | 读取的起始位置，缺省为文件的起始位置。 |
| length | number | 否 | 需要读取的长度，缺省则读取到文件结尾。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

success返回值：

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| buffer | Uint8Array | 读取到的文件内容。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 202 | 出现参数错误。 |
| 300 | 出现I/O错误。 |
| 301 | 文件或目录不存在。 |

**示例：**

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

判断指定文件或目录是否存在。

> **说明**： 
>
> 从API version 10开始废弃，请使用[fs.access](js-apis-file-fs.md#fsaccess)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | 目录或文件uri。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 202 | 出现参数错误。 |
| 300 | 出现I/O&nbsp;错误。 |
| 301 | 文件或目录不存在。 |

**示例：**

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

创建指定目录。

> **说明**： 
>
> 从API version 10开始废弃，请使用[fs.mkdir](js-apis-file-fs.md#fsmkdir)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | 目录的uri路径。 |
| recursive | boolean | 否 | 是否递归创建该目录的上级目录，缺省为false。true为递归创建，false是不递归创建。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 202 | 出现参数错误。 |
| 300 | 出现I/O&nbsp;错误。 |

**示例：**

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

删除指定目录。

> **说明**： 
>
> 从API version 10开始废弃，请使用[fs.rmdir](js-apis-file-fs.md#fsrmdir)替代。

**系统能力：** SystemCapability.FileManagement.File.FileIO.Lite

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | 目录的uri路径。 |
| recursive | boolean | 否 | 是否递归删除子文件和子目录，缺省为false。true为递归删除，false为不递归删除。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 202 | 出现参数错误。 |
| 300 | 出现I/O&nbsp;错误。 |
| 301 | 文件或目录不存在。 |

**示例：**

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