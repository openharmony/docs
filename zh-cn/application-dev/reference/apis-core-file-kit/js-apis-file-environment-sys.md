# @ohos.file.environment (目录环境能力)(系统接口)

该模块提供环境目录能力，获取内存存储根目录、公共文件根目录的JS接口。

> **说明：**
>
> - 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.file.environment (目录环境能力)](js-apis-file-environment-sys.md)。

## 导入模块

```ts
import { Environment } from '@kit.CoreFileKit';
```

## environment.getStorageDataDir

getStorageDataDir():Promise&lt;string&gt;

异步方法获取内存存储根目录，以promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.Environment

**系统接口**：此接口为系统接口。

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;string&gt; | 返回存储根目录 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。
| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 202 | The caller is not a system application |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  Environment.getStorageDataDir().then((path: string) => {
      console.info("getStorageDataDir successfully, Path: " + path);
  }).catch((err: BusinessError) => {
      console.error("getStorageDataDir failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## environment.getStorageDataDir

getStorageDataDir(callback:AsyncCallback&lt;string&gt;):void

异步方法获取内存存储根目录，以callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.Environment

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                        | 必填 | 说明                             |
| -------- | --------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback&lt;string&gt; | 是   | 异步获取内存存储根目录之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。
| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 202 | The caller is not a system application |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  Environment.getStorageDataDir((err: BusinessError, path: string) => {
    if (err) {
      console.error("getStorageDataDir failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("getStorageDataDir successfully, Path: " + path);
    }
  });
  ```

## environment.getUserDataDir

getUserDataDir():Promise&lt;string&gt;

异步方法获取公共文件根目录，以promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.Environment

**系统接口**：此接口为系统接口。

**返回值：**

| 类型                  | 说明               |
| --------------------- | ------------------ |
| Promise&lt;string&gt; | 返回公共文件根目录 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。
| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 202 | The caller is not a system application |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  Environment.getUserDataDir().then((path: string) => {
    console.info("getUserDataDir successfully, Path: " + path);
  }).catch((err: BusinessError) => {
    console.error("getUserDataDir failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## environment.getUserDataDir

getUserDataDir(callback:AsyncCallback&lt;string&gt;): void

异步方法获取公共文件根目录，以callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.Environment

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型                        | 必填 | 说明                             |
| -------- | --------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback&lt;string&gt; | 是   | 异步获取公共文件根目录之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。
| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 202 | The caller is not a system application |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  Environment.getUserDataDir((err: BusinessError, path: string) => {
    if (err) {
      console.error("getUserDataDir failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("getUserDataDir successfully, Path: " + path);
    }
  });
  ```

## environment.getExternalStorageDir<sup>11+</sup>

getExternalStorageDir(): string

获取外卡根目录的沙箱路径，该接口仅对具有该系统能力的设备开放。

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**系统能力**：SystemCapability.FileManagement.File.Environment.FolderObtain

**系统接口**：此接口为系统接口。

**返回值：**

| 类型                  | 说明            |
| --------------------- |---------------|
| string | 返回外卡根目录的沙箱路径。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息       |
| ---------------------------- | --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 801 | Capability not supported. |
| 13900042 | Unknown error |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
function getExternalStorageDirExample() {
  try {
    let path = Environment.getExternalStorageDir();
    console.log(`success to getExternalStorageDir: ${JSON.stringify(path)}`);
  } catch (error) {
    console.error(`failed to getExternalStorageDir because: ${JSON.stringify(error)}`);
  }
}
```

## environment.getUserHomeDir<sup>11+</sup>

getUserHomeDir(): string

获取当前用户下应用沙箱路径的内卡目录，该接口仅对具有该系统能力的设备开放。

**需要权限**：ohos.permission.FILE_ACCESS_MANAGER

**系统能力**：SystemCapability.FileManagement.File.Environment.FolderObtain

**系统接口**：此接口为系统接口。

**返回值：**

| 类型                  | 说明              |
| --------------------- |-----------------|
| string | 返回当前用户下应用沙箱路径的内卡目录。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息       |
| ---------------------------- | --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 801 | Capability not supported. |
| 13900042 | Unknown error |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
function getUserHomeDirExample() {
  try {
    let path = Environment.getUserHomeDir();
    console.log(`success to getUserHomeDir: ${JSON.stringify(path)}`);
  } catch (error) {
    console.error(`failed to getUserHomeDir because: ${JSON.stringify(error)}`);
  }
}
```
