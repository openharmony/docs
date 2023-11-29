# @ohos.file.userDirectory (用户目录能力)

该模块提供用户目录能力，获取内存存储根目录、公共文件根目录的JS接口。

> **说明：**
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import userDirectory from '@ohos.file.userDirectory';
```

## userDirectory.getUserDownloadDir<sup>11+</sup>

getUserDownloadDir(): string;

以同步方法获取当前用户预授权下载目录的沙箱路径

**需要权限**：ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY

**系统能力**：SystemCapability.FileManagement.AppFileService

**返回值：**

| 类型                  | 说明                 |
| --------------------- |--------------------|
| string | 返回当前用户预授权下载目录的沙箱路径 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission denied. |
| 401      | The input parameter is invalid |
| 801      | Capability not supported |
| 13900002 | No such file or directory              |
| 13900012 | Permission denied                       |
| 13900042 | Unknown error |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
try {
    let path = userDirectory.getUserDownloadDir();
    console.log(`success to getUserDownloadDir: ${JSON.stringify(colors)}`);
} catch (error) {
    console.error(`failed to getUserDownloadDir because: ${JSON.stringify(error)}`);
}
  ```

## userDirectory.getUserDesktopDir<sup>11+</sup>

getUserDesktopDir(): string;

以同步方法获取当前用户预授权桌面目录的沙箱路径

**需要权限**：ohos.permission.READ_WRITE_DESKTOP_DIRECTORY

**系统能力**：SystemCapability.FileManagement.AppFileService

**返回值：**

| 类型                  | 说明                 |
| --------------------- |--------------------|
| string | 返回当前用户预授权桌面目录的沙箱路径 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission denied. |
| 401      | The input parameter is invalid |
| 801      | Capability not supported |
| 13900002 | No such file or directory              |
| 13900012 | Permission denied                       |
| 13900042 | Unknown error |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
try {
    let path = userDirectory.getUserDesktopDir();
    console.log(`success to getUserDesktopDir: ${JSON.stringify(colors)}`);
} catch (error) {
    console.error(`failed to getUserDesktopDir because: ${JSON.stringify(error)}`);
}
  ```

## userDirectory.getUserDocumentsDir<sup>11+</sup>

getUserDocumentsDir(): string;

以同步方法获取当前用户预授权文档目录的沙箱路径

**需要权限**：ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY

**系统能力**：SystemCapability.FileManagement.AppFileService

**返回值：**

| 类型                  | 说明                 |
| --------------------- |--------------------|
| string | 返回当前用户预授权文档目录的沙箱路径 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission denied. |
| 401      | The input parameter is invalid |
| 801      | Capability not supported |
| 13900002 | No such file or directory              |
| 13900012 | Permission denied                       |
| 13900042 | Unknown error |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
try {
    let path = userDirectory.getUserDocumentsDir();
    console.log(`success to getUserDocumentsDir: ${JSON.stringify(colors)}`);
} catch (error) {
    console.error(`failed to getUserDocumentsDir because: ${JSON.stringify(error)}`);
}
  ```

## userDirectory.getUserHomeDir<sup>11+</sup>

getUserHomeDir(): string;

以同步方法获取当前用户根目录的沙箱路径

**系统能力**：SystemCapability.FileManagement.AppFileService

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
| 13900002 | No such file or directory              |
| 13900012 | Permission denied                       |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  try {
    let path = userDirectory.getUserHomeDir();
    console.log(`success to getUserHomeDir: ${JSON.stringify(path)}`);
} catch (error) {
    console.error(`failed to getUserHomeDir because: ${JSON.stringify(error)}`);
}
  ```

## userDirectory.getExternalUsbDir<sup>11+</sup>

getExternalUsbDir(): string;

以同步方法获取外卡根目录的沙箱路径

**系统能力**：SystemCapability.FileManagement.AppFileService

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
| 13900002 | No such file or directory              |
| 13900012 | Permission denied                       |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  try {
    let path = userDirectory.getExternalUsbDir();
    console.log(`success to getExternalUsbDir: ${JSON.stringify(path)}`);
} catch (error) {
    console.error(`failed to getExternalUsbDir because: ${JSON.stringify(error)}`);
}
  ```

## userDirectory.getUserShareDir<sup>11+</sup>

getUserShareDir(): string;

以同步方法获取共享盘目录的沙箱路径

**系统能力**：SystemCapability.FileManagement.AppFileService

**系统接口**：此接口为系统接口。

**返回值：**

| 类型                  | 说明               |
| --------------------- |------------------|
| string | 返回共享盘目录的沙箱路径 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息       |
| ---------------------------- | --------- |
| 202 | The caller is not a system application |
| 801 | Capability not supported |
| 13900002 | No such file or directory              |
| 13900012 | Permission denied                       |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**示例：**

  ```ts
  import { BusinessError } from '@ohos.base';
  try {
    let path = userDirectory.getUserShareDir();
    console.log(`success to getUserShareDir: ${JSON.stringify(path)}`);
} catch (error) {
    console.error(`failed to getUserShareDir because: ${JSON.stringify(error)}`);
}
  ```