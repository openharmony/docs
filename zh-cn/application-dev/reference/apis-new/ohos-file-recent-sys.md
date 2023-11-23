# @ohos.file.recent    
该模块提供最近访问列表插入、移除、查询等常用能力。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import recent from '@ohos.file.recent'    
```  
    
## FileInfo    
最近访问列表文件信息。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri | string | true | true | 文件uri |  
| srcPath | string | true | true | 文件路径 |  
| fileName | string | true | true | 文件名 |  
| mode | number | true | true | [文件权限信息](js-apis-file-fs.md#stat) |  
| size | number | true | true | 文件的大小（单位：字节） |  
| mtime | number | true | true | 文件的修改时间 |  
| ctime | number | true | true | 文件的创建时间 |  
    
## listFile    
查询最近访问列表中文件信息。  
 **调用形式：**     
- listFile(): Array\<FileInfo>  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<FileInfo> | FileInfo数组 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 | 没有这个文件或目录 |  
| 13900020 | 无效的参数 |  
| 13900042 | 未知错误 |  
    
 **示例代码：**   
```js    
let fileinfos = recent.listFile();  for(let i = 0; i < fileinfos.length; i++){    console.info('uri: ' + fileinfos[i].uri);    console.info('srcPath: ' + fileinfos[i].srcPath);    console.info('fileName: ' + fileinfos[i].fileName);    console.info('mode: ' + fileinfos[i].mode);    console.info('size: ' + fileinfos[i].size);    console.info('mtime: ' + fileinfos[i].mtime);    console.info('ctime: ' + fileinfos[i].ctime);  }    
```    
  
    
## add    
将uri对应的文件加入最近访问列表。  
 **调用形式：**     
- add(uri: string): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 公共目录文件类URI |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 | 没有这个文件或目录 |  
| 13900020 | 无效的参数 |  
| 13900042 | 未知错误 |  
    
 **示例代码：**   
```js    
let uri = 'file://docs/storage/Users/currentUser/\<publicPath>';  recent.add(uri);    
```    
  
    
## remove    
将uri对应的文件从最近访问列表中移除。  
 **调用形式：**     
- remove(uri: string): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 公共目录文件类URI。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 | 没有这个文件或目录 |  
| 13900020 | 无效的参数 |  
| 13900042 | 未知错误 |  
    
 **示例代码：**   
```js    
let uri = 'file://docs/storage/Users/currentUser/\<publicPath>';  recent.remove(uri);    
```    
  
