# @system.file    
> **说明**   
>本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import file from '@system.file';  
    
```  
    
## FileResponse<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| length<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| lastModifiedTime<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| type<sup>(deprecated)</sup> | 'dir' \| 'file' | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| subFiles<sup>(deprecated)</sup> | Array<FileResponse> | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
    
## FileMoveOption<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| srcUri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| dstUri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| success<sup>(deprecated)</sup> | (uri: string) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
    
## FileListResponse<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| fileList<sup>(deprecated)</sup> | Array<FileResponse> | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
    
## FileListOption<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| success<sup>(deprecated)</sup> | (data: FileListResponse) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
    
## FileCopyOption<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| srcUri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| dstUri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| success<sup>(deprecated)</sup> | (uri: string) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
    
## FileGetOption<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| recursive<sup>(deprecated)</sup> | boolean | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| success<sup>(deprecated)</sup> | (file: FileResponse) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
    
## FileDeleteOption<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| success<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
    
## FileWriteTextOption<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| text<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| encoding<sup>(deprecated)</sup> | string | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| append<sup>(deprecated)</sup> | boolean | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| success<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
    
## FileReadTextResponse<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| text<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
    
## FileReadTextOption<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| encoding<sup>(deprecated)</sup> | string | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| position<sup>(deprecated)</sup> | number | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| length<sup>(deprecated)</sup> | number | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| success<sup>(deprecated)</sup> | (data: FileReadTextResponse) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
    
## FileWriteArrayBufferOption<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| buffer<sup>(deprecated)</sup> | Uint8Array | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| position<sup>(deprecated)</sup> | number | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| append<sup>(deprecated)</sup> | boolean | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| success<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
    
## FileReadArrayBufferResponse<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| buffer<sup>(deprecated)</sup> | Uint8Array | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
    
## FileReadArrayBufferOption<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| position<sup>(deprecated)</sup> | number | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| length<sup>(deprecated)</sup> | number | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| success<sup>(deprecated)</sup> | (data: FileReadArrayBufferResponse) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
    
## FileAccessOption<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| success<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
    
## FileMkdirOption<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| recursive<sup>(deprecated)</sup> | boolean | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| success<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
    
## FileRmdirOption<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| recursive<sup>(deprecated)</sup> | boolean | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| success<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 10 开始废弃。 |  
    
## File<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
### move<sup>(deprecated)</sup>    
将指定文件移动到其他指定位置。  
 **调用形式：**     
- static move(options: FileMoveOption): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.file.fs.moveFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | FileMoveOption | true |  |  
    
 **示例代码：**   
```js    
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
  
    
### copy<sup>(deprecated)</sup>    
将指定文件拷贝并存储到指定位置。  
 **调用形式：**     
- static copy(options: FileCopyOption): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.file.fs.copyFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | FileCopyOption | true |  |  
    
 **示例代码：**   
```js    
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
  
    
### list<sup>(deprecated)</sup>    
  
获取指定路径下全部文件的列表。  
 **调用形式：**     
- static list(options: FileListOption): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.file.fs.listFile。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | FileListOption | true |  |  
    
 **示例代码：**   
```js    
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
  
    
### get<sup>(deprecated)</sup>    
获取指定本地文件的信息。  
 **调用形式：**     
- static get(options: FileGetOption): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.file.fs.stat。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | FileGetOption | true |  |  
    
 **示例代码：**   
```js    
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
  
    
### delete<sup>(deprecated)</sup>    
删除本地文件。  
 **调用形式：**     
- static delete(options: FileDeleteOption): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.file.fs.unlink。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | FileDeleteOption | true |  |  
    
 **示例代码：**   
```js    
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
  
    
### writeText<sup>(deprecated)</sup>    
写文本内容到指定文件。仅支持文本文档读写。  
 **调用形式：**     
- static writeText(options: FileWriteTextOption): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.file.fs.write。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | FileWriteTextOption | true |  |  
    
 **示例代码：**   
```js    
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
  
    
### readText<sup>(deprecated)</sup>    
从指定文件中读取文本内容。仅支持文本文档读写。  
 **调用形式：**     
- static readText(options: FileReadTextOption): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.file.fs.readText。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | FileReadTextOption | true |  |  
    
 **示例代码：**   
```js    
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
  
    
### writeArrayBuffer<sup>(deprecated)</sup>    
写Buffer内容到指定文件。仅支持文本文档读写。  
 **调用形式：**     
- static writeArrayBuffer(options: FileWriteArrayBufferOption): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.file.fs.write。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | FileWriteArrayBufferOption | true |  |  
    
 **示例代码：**   
```js    
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
  
    
### readArrayBuffer<sup>(deprecated)</sup>    
从指定文件中读取Buffer内容。仅支持文本文档读写。  
 **调用形式：**     
- static readArrayBuffer(options: FileReadArrayBufferOption): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.file.fs.read。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | FileReadArrayBufferOption | true |  |  
    
 **示例代码：**   
```js    
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
  
    
### access<sup>(deprecated)</sup>    
判断指定文件或目录是否存在。  
 **调用形式：**     
- static access(options: FileAccessOption): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.file.fs.access。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | FileAccessOption | true |  |  
    
 **示例代码：**   
```js    
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
  
    
### mkdir<sup>(deprecated)</sup>    
创建指定目录。  
 **调用形式：**     
- static mkdir(options: FileMkdirOption): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.file.fs.mkdir。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | FileMkdirOption | true |  |  
    
 **示例代码：**   
```js    
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
  
    
### rmdir<sup>(deprecated)</sup>    
删除指定目录。  
 **调用形式：**     
- static rmdir(options: FileRmdirOption): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.file.fs.rmdir。  
 **系统能力:**  SystemCapability.FileManagement.File.FileIO.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | FileRmdirOption | true |  |  
    
 **示例代码：**   
```js    
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
  
