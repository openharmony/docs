# @ohos.file.trash (最近删除)

该模块为最近删除（回收站）API，提供最近删除（回收站）里的文件/目录还原、彻底删除、查询等常用能力。

>**说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口，三方应用不支持调用，当前只支持文件管理器调用。

## 导入模块

```js
import trash from '@ohos.file.trash';
```

## trash.recover

recover(uri: string): void;

将uri对应文件/目录恢复到原路径。
该uri必须是位于最近删除（回收站）下的地址。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | 是   | 公共目录文件类URI |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  let uri = 'file://docs/storage/.Trash/Users/100/111111/storage/Users/currentUser/Documents/oh_trash_content111111/testdir";
  trash.recover(uri);
  ```

## trash.completelyDelete

completelyDelete(uri: string): void

将uri对应文件/目录从最近删除（回收站）列表中彻底删除。
该uri必须是位于最近删除（回收站）下的地址。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | 是   | 公共目录文件类URI |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  let uri = 'file://docs/storage/.Trash/Users/100/111111/storage/Users/currentUser/Documents/oh_trash_content111111/testdir";
  trash.completelyDelete(uri);
  ```

## trash.listFile

listFile(): Array\<FileInfo>

查询最近删除（回收站）列表中文件/目录信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**返回值：**

  | 类型 | 说明 |
  | --- | -- |
  | [Array\<FileInfo>](#fileinfo) | FileInfo数组 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

**示例：**

  ```js
  let fileinfos = trash.listFile();
  for(let i = 0; i < fileinfos.length; i++){
    console.info(fileinfos[i].uri);
    console.info(fileinfos[i].srcPath);
    console.info(fileinfos[i].fileName);
    console.info(fileinfos[i].mode);
    console.info(fileinfos[i].size);
    console.info(fileinfos[i].mtime);
    console.info(fileinfos[i].ctime);
  }
  ```

## FileInfo

最近删除（回收站）列表文件信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

### 属性

| 名称 | 类型   | 可读 | 可写 | 说明     |
| ------ | ------ | -------- | ------ | -------- |
| uri | string | 是 | 否 | 文件/目录uri |
| srcPath | string | 是 | 否 | 文件/目录删除前原路径 |
| fileName | string | 是 | 否 | 文件/目录文件名 |
| mode | number | 是 | 否 | 文件/目录权限信息 |
| size | number | 是 | 否 |  文件/目录的大小 |
| mtime | number | 是 | 否 |  文件/目录的修改时间 |
| ctime | string | 是 | 否 |  文件/目录的创建时间 |