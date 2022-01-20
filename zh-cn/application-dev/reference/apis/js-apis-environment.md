# 目录环境能力



## 支持设备

| 手机 | 平板 | 智慧屏 | 智能穿戴 |
| ---- | ---- | ------ | -------- |
| 支持 | 支持 | 支持   | 支持     |



## 导入模块

```
import environment from '@ohos.environment';
```



## 权限列表

无

## environment.getStorageDataDir

getStorageDataDir():Promise&lt;string&gt;

异步方法获取内存存储根目录，以Promise形式返回结果。

- 返回值：

  | 类型                  | 说明             |
  | --------------------- | ---------------- |
  | Promise&lt;string&gt; | 返回存存储根目录 |

- 示例：

  ```
  environment.getStorageDataDir().then(function(path){
  	// do something
  }).catch(function(error){
      
  });
  ```

## environment.getStorageDataDir

getStorageDataDir(callback:AsyncCallback&lt;string&gt;):void

异步方法获取内存存储根目录，以callback形式返回结果。

- 参数：

  | 参数名   | 类型                        | 必填 | 说明                             |
  | -------- | --------------------------- | ---- | -------------------------------- |
  | callback | AsyncCallback&lt;string&gt; | 是   | 异步获取内存存储根目录之后的回调 |

- 示例：

  ```
  environment.getStorageDataDir(function(error, path){
      // do something
  });
  ```

## getUserDataDir

getUserDataDir():Promise&lt;string&gt;

异步方法获取公共文件根目录，以Promise形式返回结果。

- 返回值：

  | 类型                  | 说明               |
  | --------------------- | ------------------ |
  | Promise&lt;string&gt; | 返回公共文件根目录 |

- 示例：

  ```
  environment.getUserDataDir().then(function(path){
  	// do something
  }).catch(function(error){
      
  });
  ```

## getUserDataDir

getUserDataDir(callback:AsyncCallback&lt;string&gt;): void

异步方法获取公共文件根目录，以callback形式返回结果。

- 参数：

  | 参数名   | 类型                        | 必填 | 说明                             |
  | -------- | --------------------------- | ---- | -------------------------------- |
  | callback | AsyncCallback&lt;string&gt; | 是   | 异步获取公共文件根目录之后的回调 |
  
- 示例：

  ```
  environment.getUserDataDir(function(error, path){
      // do something
  });
  ```

