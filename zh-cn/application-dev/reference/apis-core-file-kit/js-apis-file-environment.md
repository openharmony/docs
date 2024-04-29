# @ohos.file.environment (目录环境能力)

该模块提供环境目录能力，获取内存存储根目录、公共文件根目录的JS接口。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import environment from '@ohos.file.environment';
```

## environment.getUserDownloadDir<sup>11+</sup>

getUserDownloadDir(): string

获取当前用户预授权下载目录的沙箱路径，该接口仅对具有该系统能力的设备开放。

**需要权限**：ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY

**系统能力**：SystemCapability.FileManagement.File.Environment.FolderObtain

**返回值：**

| 类型                  | 说明                  |
| --------------------- |---------------------|
| string | 返回当前用户预授权下载目录的沙箱路径。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 801      | Capability not supported. |
| 13900042 | Unknown error |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
function getUserDownloadDirExample() {
  try {
    let path = environment.getUserDownloadDir();
    console.log(`success to getUserDownloadDir: ${JSON.stringify(path)}`);
  } catch (error) {
    console.error(`failed to getUserDownloadDir because: ${JSON.stringify(error)}`);
  }
}
```

## environment.getUserDesktopDir<sup>11+</sup>

getUserDesktopDir(): string

获取当前用户预授权桌面目录的沙箱路径，该接口仅对具有该系统能力的设备开放。

**需要权限**：ohos.permission.READ_WRITE_DESKTOP_DIRECTORY

**系统能力**：SystemCapability.FileManagement.File.Environment.FolderObtain

**返回值：**

| 类型                  | 说明                  |
| --------------------- |---------------------|
| string | 返回当前用户预授权桌面目录的沙箱路径。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 801      | Capability not supported. |
| 13900042 | Unknown error |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
function getUserDesktopDirExample() {
  try {
    let path = environment.getUserDesktopDir();
    console.log(`success to getUserDesktopDir: ${JSON.stringify(path)}`);
  } catch (error) {
    console.error(`failed to getUserDesktopDir because: ${JSON.stringify(error)}`);
  }
}
```

## environment.getUserDocumentDir<sup>11+</sup>

getUserDocumentDir(): string

获取当前用户预授权文档目录的沙箱路径，该接口仅对具有该系统能力的设备开放。

**需要权限**：ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY

**系统能力**：SystemCapability.FileManagement.File.Environment.FolderObtain

**返回值：**

| 类型                  | 说明                  |
| --------------------- |---------------------|
| string | 返回当前用户预授权文档目录的沙箱路径。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 801      | Capability not supported. |
| 13900042 | Unknown error |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
function getUserDocumentDirExample() {
  try {
    let path = environment.getUserDocumentDir();
    console.log(`success to getUserDocumentDir: ${JSON.stringify(path)}`);
  } catch (error) {
    console.error(`failed to getUserDocumentDir because: ${JSON.stringify(error)}`);
  }
}
```
