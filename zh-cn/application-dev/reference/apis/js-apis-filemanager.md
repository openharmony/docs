# 公共文件访问与管理
>![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
>- 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>- 本模块接口为系统接口，三方应用不支持调用，当前只支持filepicker调用。

该模块提供公共文件访问和管理的服务接口，向下对接底层文件管理服务，如媒体库、外卡管理；向上对应用程序提供公共文件查询、创建的能力。

## 导入模块

```js
import filemanager from '@ohos.fileManager';
```

## filemanager.getRoot

getRoot(options? : {dev? : DevInfo}) : Promise&lt;FileInfo[]&gt;

以异步方法获取第一层相册，目录信息。使用promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.FileManagerService

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | --- | -- |
  | options | Object | 否 | 支持如下选项：<br/>-&nbsp;dev，[DevInfo](#devinfo)类型，不填默认dev = {name: "local"}, 当前仅支持设备'local' |

- 返回值

  | 类型 | 说明 |
  | --- | -- |
  | Promise&lt;[FileInfo](#fileinfo)[]&gt; | 第一层目录相册信息 |

- 示例

  ```js
  filemanager.getRoot().then((fileInfo) => {
      if(Array.isArray(fileInfo)) {
          for (var i = 0; i < fileInfo.length; i++) {
              console.log("file:"+JSON.stringify(fileInfo));
          }
      }
  }).catch((err) => {
      console.log(err)
  });
  ```

## filemanager.getRoot

getRoot(options? : {dev? : DevInfo}, callback : AsyncCallback&lt;FileInfo[]&gt;) : void

以异步方法获取第一层相册，目录信息。使用callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.FileManagerService

- 参数

  | 参数名   | 类型                      | 必填 | 说明                          |
  | -------- | ------------------------- | ---- | ----------------------------- |
  | options | Object | 否 | 支持如下选项：<br/>-&nbsp;dev，[DevInfo](#devinfo)类型，不填默认dev = {name: "local"}, 当前仅支持设备'local' |
  | callback | AsyncCallback&lt;[FileInfo](#fileinfo)[]&gt; | 是   | 异步获取文件的信息之后的回调  |

- 示例

  ```js
  let option = {
            "dev":{
            name:"",
            }
  };
  filemanager.getRoot(option,(err, fileInfo)=>{
      if(Array.isArray(fileInfo)) {
          for (var i = 0; i < fileInfo.length; i++) {
              console.log("file:"+JSON.stringify(fileInfo));
          }
      } 
  });
  
  ```

## filemanager.listFile

listFile(path : string, type : string, options? : {dev? : DevInfo, offset? : number, count? : number}) : Promise&lt;FileInfo[]&gt;

以异步方法获取第二层相册，文件信息。使用promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.FileManagerService

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | --- | -- |
  | path | string | 是 | 待查询目录uri |
  | type | string | 是 | 待查询文件类型, 支持以下类型 "file", "image", "audio", "video" |
  | options | Object | 否 | 支持如下选项：<br/>-&nbsp;dev，[DevInfo](#devinfo)类型，不填默认dev = {name: "local"}, 当前仅支持设备'local'。<br/>-&nbsp;offset，number类型，待查询文件偏移个数。<br/>-&nbsp;count，number类型，待查询文件个数。 |
  
- 返回值

  | 类型 | 说明 |
  | --- | -- |
  | Promise&lt;FileInfo[]&gt; | 文件信息 |

- 异常
  | 错误名称 | 错误类型 | 错误码 |说明 |
  | --- | -- | --- | -- |
  | 对应的目录、相册不存在 | No such file or directory | 2      | uri对应的目录、相册不存在 |
  | 获取FMS服务失败 | No such process | 3 | 获取FMS服务失败 |
  | path对应uri不是相册、目录 | Not a directory | 20 | path对应uri不是相册、目录 |

- 示例

  ```js
  // 获取目录下所有文件
  // 通过listFile、getRoot获取的文件uri
  let media_path = file.path
  filemanager.listFile(media_path, "file")
  .then((fileInfo) => {
      if(Array.isArray(fileInfo)) {
          for (var i = 0; i < fileInfo.length; i++) {
              console.log("file:"+JSON.stringify(fileInfo));
          }
      }
  }).catch((err) => {


    
      console.log(err)
  });
  ```

## filemanager.listFile

listFile(path : string, type : string, options? : {dev? : DevInfo, offset? : number, count? : number}, callback : AsyncCallback&lt;FileInfo[]&gt;) : void

以异步方法获取第二层相册，文件信息。使用callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.FileManagerService

- 参数

  | 参数名   | 类型                      | 必填 | 说明                                                         |
  | -------- | ------------------------- | ---- | ------------------------------------------------------------ |
  | path     | string                    | 是   | 待查询目录uri                                                |
  | type     | string                    | 是   | 待查询文件类型, 支持以下类型 "file", "image", "audio", "video" |
  | options | Object | 否 | 支持如下选项：<br/>-&nbsp;dev，[DevInfo](#devinfo)类型，不填默认dev = {name: "local"}, 当前仅支持设备'local'。<br/>-&nbsp;offset，number类型，待查询文件偏移个数。<br/>-&nbsp;count，number类型，待查询文件个数。 |
  | callback | AsyncCallback&lt;[FileInfo](#fileinfo)[]&gt; | 是   | 异步获取文件的信息之后的回调                                 |
- 异常

  | 错误名称                  | 错误类型                  | 错误码 | 说明                      |
  | ------------------------- | ------------------------- | ------ | ------------------------- |
  | 对应的目录、相册不存在    | No such file or directory | 2      | uri对应的目录、相册不存在 |
  | 获取FMS服务失败           | No such process           | 3      | 获取FMS服务失败           |
  | path对应uri不是相册、目录 | Not a directory           | 20     | path对应uri不是相册、目录 |

- 示例

  ```js
  // 通过listFile、getRoot获取的文件path
  let fileInfos = await filemanager.getRoot(); 
  let media_path  = "";
  for (let i = 0; i < fileInfos.length; i++) {
	if (fileInfos[i].name == "image_album") {
	  media_path = fileInfos[i].path;
	} else if (fileInfos[i].name == "audio_album") {
	  media_path = fileInfos[i].path;
	} else if (fileInfos[i].name == "video_album") {
	  media_path = fileInfos[i].path;
	} else if (fileInfos[i].name == "file_folder") {
	  media_path = fileInfos[i].path;
	}
  }

  filemanager.listFile(media_path, "file")
  .then((fileInfo) => {
    if(Array.isArray(fileInfo)) {
        for (var i = 0; i < fileInfo.length; i++) {
            console.log("file:"+JSON.stringify(fileInfo));
        }
    }
  }).catch((err) => {
    console.log(err)
  });
  ```

## filemanager.createFile

createFile(path : string, filename : string, options? : {dev? : DevInfo})  :   Promise&lt;string&gt;

以异步方法创建文件到指定路径，返回文件uri。使用promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.FileManagerService

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | --- | -- |
  | filename | string | 是 | 待创建的文件名 |
  | path | string | 是 | 待保存目的相册uri |
  | options | Object | 否 | 支持如下选项：<br/>-&nbsp;dev，[DevInfo](#devinfo)类型，不填默认dev = {name: "local"}, 当前仅支持设备'local' |

- 返回值

  | 类型 | 说明 |
  | --- | -- |
  | string | 文件uri |

- 异常
  | 错误名称 | 错误类型 | 错误码 |说明 |
  | --- | -- | --- | -- |
  | 创建文件不允许 | Operation not permitted | 1 | 已有重名文件 |
  | 对应的目录、相册不存在 | No such file or directory | 2 | uri对应的目录、相册不存在 |
  | 获取FMS服务失败 | No such process | 3 | 获取FMS服务失败 |
  | path对应uri不是相册、目录 | Not a directory | 20 | path对应uri不是相册、目录 |

- 示例

  ```js
  // 创建文件，返回文件uri
  let media_path = file.uri // 通过listFile、getRoot获取的文件uri
  let name = "xxx.jpg" // 待保存文件的后缀
  filemanager.createFile(media_path, name).then((uri) => {
      // 返回uri给应用
      console.log("file uri:"+uri);
  }).catch((err) => {
      console.log(err);
  });
  ```

## filemanager.createFile

createFile(path : string, filename: string, options? : {dev? : DevInfo}, callback : AsyncCallback&lt;string&gt;) : void

以异步方法创建文件到指定路径，返回文件uri。使用callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.FileManagerService

- 参数

  | 参数名   | 类型                      | 必填 | 说明                          |
  | -------- | ------------------------- | ---- | ----------------------------- |
  | filename | string                    | 是   | 待创建的文件名                |
  | path     | string                    | 是   | 待保存目的相册uri             |
  | options | Object | 否 | 支持如下选项：<br/>-&nbsp;dev，[DevInfo](#devinfo)类型，不填默认dev = {name: "local"}, 当前仅支持设备'local' |
  | callback | AsyncCallback&lt;[FileInfo](#fileinfo)[]&gt; | 是   | 异步获取文件的信息之后的回调  |

- 异常

  | 错误名称                  | 错误类型                  | 错误码 | 说明                      |
  | ------------------------- | ------------------------- | ------ | ------------------------- |
  | 创建文件不允许            | Operation not permitted   | 1      | 已有重名文件              |
  | 对应的目录、相册不存在    | No such file or directory | 2      | uri对应的目录、相册不存在 |
  | 获取FMS服务失败           | No such process           | 3      | 获取FMS服务失败           |
  | path对应uri不是相册、目录 | Not a directory           | 20     | path对应uri不是相册、目录 |

- 示例

  ```js
  // 创建文件，返回文件uri
  // 通过listFile、getRoot获取的文件uri
  let media_path = file.path
  // 待保存文件的后缀
  let name = "xxx.jpg"
  filemanager.createFile(media_path, name, (err, uri) => {
      // 返回uri给应用
      console.log("file uri:"+uri);
  });
  ```

## FileInfo
文件信息类型，通过getRoot, listFile等接口返回的类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.FileManagement.FileManagerService。

### 属性

| 参数名 | 类型 | 可读 | 可写 | 说明 |
| --- | -- | -- | -- | -- |
| name | string | 是 | 否 | 文件名称 |
| path | string | 是 | 否 | 文件Uri |
| type | string | 是 | 否 | 文件类型 |
| size | number | 是 | 否 | 文件大小 |
| addedTime | number | 是 | 否 | 媒体插入时间 |
| modifiedTime | number | 是 | 否 | 媒体修改时间 |

## DevInfo

设备类型，配置接口访问的设备类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.FileManagement.FileManagerService。

### 属性

| 参数名 | 类型   | 可读 | 可写 | 说明     |
| ------ | ------ | ---- | ---- | -------- |
| name   | string | 是   | 是   | 设备名称 |