# @ohos.file.trash    
本模块接口提供接口，可以查询、还原或彻底删除最近删除（回收站）里的文件/文件夹。当前仅支持本地文件目录。  
  
应用可通过FileAccess的删除操作将文件/文件夹移动到回收站，具体可参考[s](js-apis-fileAccess.md)。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import trash from '@ohos.file.trash'    
```  
    
## FileInfo    
最近删除（回收站）内文件的FileInfo对象。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.UserFileService    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri | string | true | true | 文件/目录uri |  
| srcPath | string | true | true | 文件/目录删除前原路径 |  
| fileName | string | true | true | 文件/目录文件名 |  
| mode | number | true | true | 文件/目录权限信息 |  
| size | number | true | true | 文件/目录的大小 |  
| mtime | number | true | true | 文件/目录的修改时间 |  
| ctime | number | true | true | 文件/目录的创建时间 |  
    
## listFile    
查询最近删除（回收站）列表中文件/目录信息。  
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
| 13900002 | No such file or directory |  
| 13900020 | Invalid argument |  
| 13900042 | Unknown error |  
    
 **示例代码：**   
```js    
let fileinfos = trash.listFile();  for(let i = 0; i < fileinfos.length; i++){    console.info('uri: ' + fileinfos[i].uri);    console.info('srcPath: ' + fileinfos[i].srcPath);    console.info('fileName: ' + fileinfos[i].fileName);    console.info('mode: ' + fileinfos[i].mode);    console.info('size: ' + fileinfos[i].size);    console.info('mtime: ' + fileinfos[i].mtime);    console.info('ctime: ' + fileinfos[i].ctime);  }    
```    
  
    
## recover    
将uri对应文件/目录恢复到原路径。  
 **调用形式：**     
- recover(uri: string): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 回收站文件/文件夹URI |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 | No such file or directory |  
| 13900020 | Invalid argument |  
| 13900042 | Unknown error |  
    
 **示例代码：**   
```js    
let fileinfos = trash.listFile();  let uri = fileinfos[0].uri;  trash.recover(uri);    
```    
  
    
## completelyDelete    
将uri对应文件/目录从最近删除（回收站）列表中彻底删除。  
 **调用形式：**     
- completelyDelete(uri: string): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.UserFileService  
 **需要权限：** ohos.permission.FILE_ACCESS_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 回收站文件/文件夹URI |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13900002 | No such file or directory |  
| 13900020 | Invalid argument |  
| 13900042 | Unknown error |  
    
 **示例代码：**   
```js    
let fileinfos = trash.listFile();  let uri = fileinfos[0].uri;  trash.completelyDelete(uri);    
```    
  
