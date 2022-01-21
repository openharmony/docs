# statfs



## 导入模块

```
import statfs from '@ohos.statfs'
```

## 使用说明

使用该功能模块对文件/目录进行操作前，需要先获取其绝对路径，获取方式及其接口用法请参考：[Context模块的接口getOrCreateLocalDir](js-apis-Context.md)。

“文件/目录绝对路径”=“应用目录路径”+“文件/目录名”

通过上述接口获取到应用目录路径dir，文件名为“xxx.txt”，文件所在绝对路径为：

```
let path = dir + "xxx.txt"
```

## 权限列表

无

## statfs.getFreeBytes

getFreeBytes(path:string):Promise&lt;number&gt;

异步方法获取指定文件系统空闲字节数，以Promise形式返回结果。

- 参数：

  | 参数名 | 类型   | 必填 | 说明                         |
  | ------ | ------ | ---- | ---------------------------- |
  | path   | string | 是   | 需要查询的文件系统的文件路径 |

- 返回值：

  | 类型                  | 说明           |
  | --------------------- | -------------- |
  | Promise&lt;number&gt; | 返回空闲字节数 |

- 示例：

  ```
  let num = await statfs.getFreeBytes(path);
  ```

## statfs.getFreeBytes

getFreeBytes(path:string, callback:AsyncCallback&lt;number&gt;): void

异步方法获取指定文件系统空闲字节数，使用callback形式返回结果。

- 参数：

  | 参数名   | 类型                        | 必填 | 说明                         |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | path     | string                      | 是   | 需要查询的文件系统的文件路径 |
  | callback | AsyncCallback&lt;number&gt; | 是   | 异步获取空闲字节数之后的回调 |

- 示例：

  ```
  statfs.getFreeBytes(path, function(err, number){
      //do something
  });
  ```

## statfs.getTotalBytes

getTotalBytes.(path:string):Promise&lt;number&gt;

异步方法获取指定文件系统总字节数，以Promise形式返回结果。

- 参数：

  | 参数 | 类型   | 必填 | 说明                         |
  | ---- | ------ | ---- | ---------------------------- |
  | path | string | 是   | 需要查询的文件系统的文件路径 |

- 返回值：

  | 类型                  | 说明         |
  | --------------------- | ------------ |
  | Promise&lt;number&gt; | 返回总字节数 |

- 示例：

  ```
  let num = await statfs.getTotalBytes(path);
  ```

## statfs.getTotalBytes

getTotalBytes(path:string, callback:AsyncCallback&lt;number&gt;): void

异步方法获取指定文件系统总字节数，使用callback形式返回结果。

- 参数：

  | 参数名   | 类型                        | 必填 | 说明                         |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | path     | string                      | 是   | 需要查询的文件系统的文件路径 |
  | callback | AsyncCallback&lt;number&gt; | 是   | 异步获取总字节数之后的回调   |

- 示例：

  ```
  statfs.getTotalBytes(path, function(err, number){
      //do something
  });
  ```

