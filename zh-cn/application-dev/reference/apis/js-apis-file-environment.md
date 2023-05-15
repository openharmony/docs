# @ohos.file.environment (目录环境能力)

该模块提供环境目录能力，获取内存存储根目录、公共文件根目录的JS接口。

> **说明：**
>
> - 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口，三方应用不支持调用。

## 导入模块

```js
import environment from '@ohos.file.environment';
```

## environment.getStorageDataDir

getStorageDataDir():Promise&lt;string&gt;

异步方法获取内存存储根目录，以promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.Environment

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;string&gt; | 返回存储根目录 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。
| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 202 | The caller is not a system application |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**示例：**

  ```js
  environment.getStorageDataDir().then((path) => {
      console.info("getStorageDataDir successfully, Path: " + path);
  }).catch((err) => {
      console.info("getStorageDataDir failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## environment.getStorageDataDir

getStorageDataDir(callback:AsyncCallback&lt;string&gt;):void

异步方法获取内存存储根目录，以callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.Environment

**参数：**

| 参数名   | 类型                        | 必填 | 说明                             |
| -------- | --------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback&lt;string&gt; | 是   | 异步获取内存存储根目录之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。
| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 202 | The caller is not a system application |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**示例：**

  ```js
  environment.getStorageDataDir((err, path) => {
    if (err) {
      console.info("getStorageDataDir failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("getStorageDataDir successfully, Path: " + path);
    }
  });
  ```

## environment.getUserDataDir

getUserDataDir():Promise&lt;string&gt;

异步方法获取公共文件根目录，以promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.Environment

**返回值：**

| 类型                  | 说明               |
| --------------------- | ------------------ |
| Promise&lt;string&gt; | 返回公共文件根目录 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。
| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 202 | The caller is not a system application |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**示例：**

  ```js
  environment.getUserDataDir().then((path) => {
    console.info("getUserDataDir successfully, Path: " + path);
  }).catch((err) => {
    console.info("getUserDataDir failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## environment.getUserDataDir

getUserDataDir(callback:AsyncCallback&lt;string&gt;): void

异步方法获取公共文件根目录，以callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.Environment

**参数：**

| 参数名   | 类型                        | 必填 | 说明                             |
| -------- | --------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback&lt;string&gt; | 是   | 异步获取公共文件根目录之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。
| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 202 | The caller is not a system application |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**示例：**

  ```js
  environment.getUserDataDir((err, path) => {
    if (err) {
      console.info("getUserDataDir failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("getUserDataDir successfully, Path: " + path);
    }
  });
  ```
