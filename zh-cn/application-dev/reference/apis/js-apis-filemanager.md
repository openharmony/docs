# 公共文件访问与管理

## 导入模块

```
import filemanager from 'ohos.filemanager'
```

## 权限

应用需要拥有SystemCapability.FileManagement.FileManagerService权限

## filemanager.getRoot
getRoot(dev : DevInfo) : Promise&lt;FileInfo[]&gt;

以异步方法获取第一层相册，目录信息。使用promise形式返回结果。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | --- | -- |
  | dev | DevInfo | 是 | 设备名, 当前仅支持设备'local' |

- 返回值

  | 类型 | 说明 |
  | --- | -- |
  | Promise&lt;FileInfo[]&gt; | 第一层目录相册信息 |

- 示例

```js
let dev = {name: "local"};
filemanager.getRoot(dev)
.then((fileInfo) => {
    if(Array.isArray(fileInfo)) {
        for (var i = 0; i < fileInfo.length; i++) {
            console.log(JSON.Stringify(fileInfo))
        }
    }
})
.catch((err) => {
    console.log(err)
})
```

## filemanager.getRoot

getRoot(dev : DevInfo, callback : AsyncCallback&lt;FileInfo[]&gt;) : void

以异步方法获取第一层相册，目录信息。使用callback形式返回结果。

- 参数

  | 参数名   | 类型                      | 必填 | 说明                          |
  | -------- | ------------------------- | ---- | ----------------------------- |
  | dev      | DevInfo              | 是   | 设备名, 当前仅支持设备'local' |
  | callback | AsyncCallback&lt;FileInfo[]&gt; | 是   | 异步获取文件的信息之后的回调  |

- 示例

```js
let dev = {name: "local"};
filemanager.getRoot(dev, (err, fileInfo) => {
    if(Array.isArray(fileInfo)) {
        for (var i = 0; i < fileInfo.length; i++) {
            console.log(JSON.Stringify(fileInfo))
        }
    }
})
```

## filemanager.listFile

listFile(dev : DevInfo, type : string, path : string, option? : {offset? : number, count?: number}) : Promise&lt;FileInfo[]&gt;

以异步方法获取获取第二层相册，文件信息。使用promise形式返回结果。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | --- | -- |
  | dev | DevInfo | 是 | 设备名, 当前仅支持设备'local' |
  | type | string | 是 | 待查询文件类型, 支持以下类型 "file", "image", "audio", "video" |
  | path | string | 是 | 待查询目录uri |

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

```js
// 获取目录下所有文件
// 通过listFile、getRoot获取的文件uri
let media_path = file.uri
let dev = {name: "local"};
filemanager.listFile(dev, "file", media_path)
.then((fileInfo) => {
    if(Array.isArray(fileInfo)) {
        for (var i = 0; i < fileInfo.length; i++) {
            console.log(JSON.Stringify(fileInfo))
        }
    }
})
.catch((err) => {
    console.log(err)
})
```
## filemanager.listFile

listFile(dev : DevInfo, type : string, path : string, option? : {offset? : number, count?: number}, callback : AsyncCallback&lt;FileInfo[]&gt;) : void

以异步方法获取获取第二层相册，文件信息。使用callback形式返回结果。

- 参数

  | 参数名   | 类型                      | 必填 | 说明                                                         |
  | -------- | ------------------------- | ---- | ------------------------------------------------------------ |
  | dev      | DevInfo             | 是   | 设备名, 当前仅支持设备'local'                                |
  | type     | string                    | 是   | 待查询文件类型, 支持以下类型 "file", "image", "audio", "video" |
  | path     | string                    | 是   | 待查询目录uri                                                |
  | callback | AsyncCallback&lt;FileInfo[]&gt; | 是   | 异步获取文件的信息之后的回调                                 |
- 异常

  | 错误名称                  | 错误类型                  | 错误码 | 说明                      |
  | ------------------------- | ------------------------- | ------ | ------------------------- |
  | 对应的目录、相册不存在    | No such file or directory | 2      | uri对应的目录、相册不存在 |
  | 获取FMS服务失败           | No such process           | 3      | 获取FMS服务失败           |
  | path对应uri不是相册、目录 | Not a directory           | 20     | path对应uri不是相册、目录 |

```js
// 通过listFile、getRoot获取的文件uri
let media_path = file.uri
let dev = {name: "local"};
filemanager.listFile(dev, "file", media_path, (err, fileInfo) => {
    if(Array.isArray(fileInfo)) {
        for (var i = 0; i < fileInfo.length; i++) {
            console.log(JSON.Stringify(fileInfo))
        }
    }
})
```

## filemanager.createFile

filemanager.createFile(dev : DevInfo, filename: string, path : string)  :   promise&lt;string&gt;

以异步方法创建文件到指定路径，返回文件uri。使用promise形式返回结果。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | --- | --- | --- | -- |
  | dev | DevInfo | 是 | 设备名, 当前仅支持设备'local' |
  | filename | string | 是 | 待创建的文件名 |
  | path | string | 是 | 待保存目的相册uri |

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

```js
// 创建文件，返回文件uri
let media_path = file.uri // 通过listFile、getRoot获取的文件uri
let name = "xxx.jpg" // 待保存文件的后缀
let dev = {name: "local"};
filemanager.createFile(dev, name, media_path)
.then((uri) => {
// 返回uri给应用
})
.catch((err) => {
    console.log(err)
})
```

## filemanager.createFile

createFile(dev : DevInfo, filename: string, path : string, callback : AsyncCallback&lt;string&gt;) : void

以异步方法创建文件到指定路径，返回文件uri。使用callback形式返回结果。

- 参数

  | 参数名   | 类型                      | 必填 | 说明                          |
  | -------- | ------------------------- | ---- | ----------------------------- |
  | dev      | DevInfo              | 是   | 设备名, 当前仅支持设备'local' |
  | filename | string                    | 是   | 待创建的文件名                |
  | path     | string                    | 是   | 待保存目的相册uri             |
  | callback | AsyncCallback&lt;FileInfo[]&gt; | 是   | 异步获取文件的信息之后的回调  |

- 异常

  | 错误名称                  | 错误类型                  | 错误码 | 说明                      |
  | ------------------------- | ------------------------- | ------ | ------------------------- |
  | 创建文件不允许            | Operation not permitted   | 1      | 已有重名文件              |
  | 对应的目录、相册不存在    | No such file or directory | 2      | uri对应的目录、相册不存在 |
  | 获取FMS服务失败           | No such process           | 3      | 获取FMS服务失败           |
  | path对应uri不是相册、目录 | Not a directory           | 20     | path对应uri不是相册、目录 |

```js
// 创建文件，返回文件uri
// 通过listFile、getRoot获取的文件uri
let media_path = file.uri
// 待保存文件的后缀
let name = "xxx.jpg"
let dev = {name: "local"};
filemanager.createFile(dev, name, media_path, (err, uri) => {
// 返回uri给应用
})
```

## FileInfo
文件信息类型，通过getRoot, listFile等接口返回的类型。
### 属性

  | 参数名 | 类型 | 可读 | 可写 | 说明 |
  | --- | -- | -- | -- | -- |
  | name | string | 是 | 否 | 文件名称 |
  | path | string | 是 | 否 | 文件Uri |
  | type | string | 是 | 否 | 文件类型 |
  | size | number | 是 | 否 | 文件大小 |
  | added_time | number | 是 | 否 | 媒体插入时间 |
  | modified_time | number | 是 | 否 | 媒体修改时间 |

## DevInfo
设备类型，配置接口访问的设备类型。
### 属性
  | 参数名 | 类型 | 可读 | 可写 | 说明 |
  | --- | -- | -- | -- | -- |
  | name | string | 是 | 是 | 设备名称 |