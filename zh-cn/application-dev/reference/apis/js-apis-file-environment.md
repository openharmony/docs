# @ohos.file.environment (目录环境能力)

该模块提供环境目录能力，获取内存存储根目录、公共文件根目录的JS接口。

> **说明：**
>
> - 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口，三方应用不支持调用。

## 导入模块

```ts
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

  ```ts
  import { BusinessError } from '@ohos.base';
  environment.getStorageDataDir().then((path: string) => {
      console.info("getStorageDataDir successfully, Path: " + path);
  }).catch((err: BusinessError) => {
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

  ```ts
  import { BusinessError } from '@ohos.base';
  environment.getStorageDataDir((err: BusinessError, path: string) => {
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

  ```ts
  import { BusinessError } from '@ohos.base';
  environment.getUserDataDir().then((path: string) => {
    console.info("getUserDataDir successfully, Path: " + path);
  }).catch((err: BusinessError) => {
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

  ```ts
  import { BusinessError } from '@ohos.base';
  environment.getUserDataDir((err: BusinessError, path: string) => {
    if (err) {
      console.info("getUserDataDir failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("getUserDataDir successfully, Path: " + path);
    }
  });
  ```

## environment.getUserDownloadDir<sup>11+</sup>

getUserDownloadDir(): string

获取当前用户预授权下载目录的沙箱路径，该接口仅对特定设备开放。

**需要权限**：ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY

**系统能力**：SystemCapability.FileManagement.File.Environment

**返回值：**

| 类型                  | 说明                 |
| --------------------- |--------------------|
| string | 返回当前用户预授权下载目录的沙箱路径 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission denied. |
| 801      | Capability not supported |
| 13900042 | Unknown error |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
try {
  let path = environment.getUserDownloadDir();
  console.log(`success to getUserDownloadDir: ${JSON.stringify(path)}`);
} catch (error) {
  console.error(`failed to getUserDownloadDir because: ${JSON.stringify(error)}`);
}
```

## environment.getUserDesktopDir<sup>11+</sup>

getUserDesktopDir(): string

获取当前用户预授权桌面目录的沙箱路径，该接口仅对特定设备开放。

**需要权限**：ohos.permission.READ_WRITE_DESKTOP_DIRECTORY

**系统能力**：SystemCapability.FileManagement.File.Environment

**返回值：**

| 类型                  | 说明                 |
| --------------------- |--------------------|
| string | 返回当前用户预授权桌面目录的沙箱路径 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission denied. |
| 801      | Capability not supported |
| 13900042 | Unknown error |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
try {
  let path = environment.getUserDesktopDir();
  console.log(`success to getUserDesktopDir: ${JSON.stringify(path)}`);
} catch (error) {
  console.error(`failed to getUserDesktopDir because: ${JSON.stringify(error)}`);
}
```

## environment.getUserDocumentDir<sup>11+</sup>

getUserDocumentDir(): string

获取当前用户预授权文档目录的沙箱路径，该接口仅对特定设备开放。

**需要权限**：ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY

**系统能力**：SystemCapability.FileManagement.File.Environment

**返回值：**

| 类型                  | 说明                 |
| --------------------- |--------------------|
| string | 返回当前用户预授权文档目录的沙箱路径 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission denied. |
| 801      | Capability not supported |
| 13900042 | Unknown error |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
try {
  let path = environment.getUserDocumentDir();
  console.log(`success to getUserDocumentDir: ${JSON.stringify(path)}`);
} catch (error) {
  console.error(`failed to getUserDocumentDir because: ${JSON.stringify(error)}`);
}
```

## environment.getExternalStorageDir<sup>11+</sup>

getExternalStorageDir(): string

获取外卡根目录的沙箱路径，该接口仅对特定设备开放。

**系统能力**：SystemCapability.FileManagement.File.Environment

**系统接口**：此接口为系统接口。

**返回值：**

| 类型                  | 说明               |
| --------------------- |------------------|
| string | 返回外卡根目录的沙箱路径 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息       |
| ---------------------------- | --------- |
| 202 | The caller is not a system application |
| 801 | Capability not supported |
| 13900042 | Unknown error |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
try {
  let path = environment.getExternalStorageDir();
  console.log(`success to getExternalStorageDir: ${JSON.stringify(path)}`);
} catch (error) {
  console.error(`failed to getExternalStorageDir because: ${JSON.stringify(error)}`);
}
```

## environment.getUserHomeDir<sup>11+</sup>

getUserHomeDir(): string

获取当前用户根目录的沙箱路径，该接口仅对特定设备开放。

**系统能力**：SystemCapability.FileManagement.File.Environment

**系统接口**：此接口为系统接口。

**返回值：**

| 类型                  | 说明               |
| --------------------- |------------------|
| string | 返回当前用户根目录的沙箱路径 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息       |
| ---------------------------- | --------- |
| 202 | The caller is not a system application |
| 801 | Capability not supported |
| 13900042 | Unknown error |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
try {
  let path = environment.getUserHomeDir();
  console.log(`success to getUserHomeDir: ${JSON.stringify(path)}`);
} catch (error) {
  console.error(`failed to getUserHomeDir because: ${JSON.stringify(error)}`);
}
```