# @ohos.file.trash (回收站)(系统接口)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wang_zhangjun; @zhuangzhuang-->
<!--SE: @wang_zhangjun; @zhuangzhuang; @renguang1116-->
<!--TSE: @liuhonggang123; @yue-ye2; @juxiaopang-->

本模块接口提供接口，可以查询、还原或彻底删除最近删除（回收站）里的文件/文件夹。当前仅支持本地文件目录。

应用可通过FileAccess的删除操作将文件/文件夹移动到回收站，具体可参考[@ohos.file.fileAccess](js-apis-fileAccess-sys.md)。

>**说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块为系统接口。
> - 当前只支持文件管理器调用。

## 导入模块

```js
import trash from '@ohos.file.trash';
```

## trash.listFile

listFile(): Array\<FileInfo>

查询最近删除（回收站）列表中文件/目录信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**系统接口**：此接口为系统接口。

**返回值：**

  | 类型 | 说明 |
  | --- | -- |
  | Array [\<FileInfo>](#fileinfo) | FileInfo数组。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```js
  let fileinfos = trash.listFile();
  for(let i = 0; i < fileinfos.length; i++){
    console.info('uri: ' + fileinfos[i].uri);
    console.info('srcPath: ' + fileinfos[i].srcPath);
    console.info('fileName: ' + fileinfos[i].fileName);
    console.info('mode: ' + fileinfos[i].mode);
    console.info('size: ' + fileinfos[i].size);
    console.info('mtime: ' + fileinfos[i].mtime);
    console.info('ctime: ' + fileinfos[i].ctime);
  }
  ```

## trash.recover

recover(uri: string): void

将uri对应文件/目录恢复到原路径。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | 是   | 回收站文件/文件夹URI。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```js
  let fileinfos = trash.listFile();
  let uri = fileinfos[0].uri;
  trash.recover(uri);
  ```

## trash.completelyDelete

completelyDelete(uri: string): void

将uri对应文件/目录从最近删除（回收站）列表中彻底删除。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | 是   | 回收站文件/文件夹URI。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```js
  let fileinfos = trash.listFile();
  let uri = fileinfos[0].uri;
  trash.completelyDelete(uri);
  ```

## FileInfo

最近删除（回收站）内文件的FileInfo对象。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

| 名称 | 类型   | 只读 | 可选 | 说明     |
| ------ | ------ | -------- | ------ | -------- |
| uri | string | 是 | 否 | 文件/目录URI。 |
| srcPath | string | 是 | 否 | 文件/目录删除前原路径。 |
| fileName | string | 是 | 否 | 文件/目录文件名。 |
| mode | number | 是 | 否 | 文件/目录权限信息。 |
| size | number | 是 | 否 |  文件/目录的大小，单位为Byte。 |
| mtime | number | 是 | 否 |  文件/目录的修改时间。自1970年1月1日起至目标时间的毫秒数。|
| ctime | number | 是 | 否 |  文件/目录的创建时间。自1970年1月1日起至目标时间的秒数。|
