# @ohos.file.recent (最近访问列表)(系统接口)

该模块提供最近访问列表插入、移除、查询等常用能力。

>**说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块为系统接口。
> - 当前只支持文件管理器调用。

## 导入模块

```js
import recent from '@ohos.file.recent';
```

## recent.add

add(uri: string): void

将uri对应的文件加入最近访问列表。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | 是   | 公共目录文件类URI。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```js
  let uri = 'file://docs/storage/Users/currentUser/<publicPath>';
  recent.add(uri);
  ```

## recent.remove

remove(uri: string): void

将uri对应的文件从最近访问列表中移除。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | 是   | 公共目录文件类URI。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```js
  let uri = 'file://docs/storage/Users/currentUser/<publicPath>';
  recent.remove(uri);
  ```

## recent.listFile

listFile(): Array\<FileInfo>

查询最近访问列表中文件信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**系统接口**：此接口为系统接口。

**返回值：**

  | 类型 | 说明 |
  | --- | -- |
  |  Array<[FileInfo](#fileinfo)> | FileInfo数组。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

**示例：**

  ```js
  let fileinfos = recent.listFile();
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

## FileInfo

最近访问列表文件信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

| 名称 | 类型   | 只读 | 可写 | 说明     |
| ------ | ------ | -------- | ------ | -------- |
| uri | string | 是 | 否 | 文件uri。 |
| srcPath | string | 是 | 否 | 文件路径。 |
| fileName | string | 是 | 否 | 文件名。 |
| mode | number | 是 | 否 | [文件权限信息](js-apis-file-fs.md#stat)。 |
| size | number | 是 | 否 |  文件的大小（单位：字节）。 |
| mtime | number | 是 | 否 |  文件的修改时间。 |
| ctime | number | 是 | 否 |  文件的创建时间。 |
