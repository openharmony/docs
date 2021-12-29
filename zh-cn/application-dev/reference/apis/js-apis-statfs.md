# Statfs管理



## 导入模块

```js
import statfs from '@ohos.statfs'
```



## 权限列表

无

## statfs.getFreeBytes(path:string):Promise<number>

异步方法获取指定文件系统空闲字节数，以Promise形式返回结果。

- 参数：

  | 参数名 | 类型   | 必填 | 说明                         |
  | ------ | ------ | ---- | ---------------------------- |
  | path   | string | 是   | 需要查询的文件系统的文件路径 |

- 返回值：

  | 类型            | 说明           |
  | --------------- | -------------- |
  | Promise<number> | 返回空闲字节数 |

- 示例：

  ```js
  let num = await statfs.getFreeBytes(path);
  ```

## statfs.getFreeBytes(path:string, callback:AsyncCallback<number>): void

异步方法获取指定文件系统空闲字节数，使用callback形式返回结果。

- 参数：

  | 参数名   | 类型                | 必填 | 说明                         |
  | -------- | ------------------- | ---- | ---------------------------- |
  | path     | string              | 是   | 需要查询的文件系统的文件路径 |
  | callback | AsyncCallback<void> | 是   | 异步获取空闲字节数之后的回调 |

- 示例：

  ```js
  statfs.getFreeBytes(path,function(err,number){
      //do something
  });
  ```

## statfs.getTotalBytes(path:string):Promise<number>

异步方法获取指定文件系统总字节数，以Promise形式返回结果。

- 参数：

  | 参数 | 类型   | 必填 | 说明                         |
  | ---- | ------ | ---- | ---------------------------- |
  | path | string | 是   | 需要查询的文件系统的文件路径 |

- 返回值：

  | 类型            | 说明         |
  | --------------- | ------------ |
  | Promise<number> | 返回总字节数 |

- 示例：

  ```js
  let num = await statfs.getTotalBytes(path);
  ```

## statfs.getTotalBytes(path:string, callback:AsyncCallback<number>): void

异步方法获取指定文件系统总字节数，使用callback形式返回结果。

- 参数：

  | 参数名   | 类型                | 必填 | 说明                         |
  | -------- | ------------------- | ---- | ---------------------------- |
  | path     | string              | 是   | 需要查询的文件系统的文件路径 |
  | callback | AsyncCallback<void> | 是   | 异步获取总字节数之后的回调   |

- 示例：

  ```js
  statfs.getTotalBytes(path,function(err,number){
      //do something
  });
  ```

