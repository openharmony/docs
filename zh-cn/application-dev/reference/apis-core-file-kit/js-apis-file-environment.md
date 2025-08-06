# @ohos.file.environment (目录环境能力)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25; @gsl_1234; @wuchengjun5-->
<!--SE: @gsl_1234; @wangke25-->
<!--TSE: @liuhonggang123; @yue-ye2; @juxiaopang-->

该模块提供环境目录能力，获取内存存储根目录、公共文件根目录的JS接口。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { Environment } from '@kit.CoreFileKit';
```

## Environment.getUserDownloadDir

getUserDownloadDir(): string

获取当前用户预授权下载目录的沙箱路径。当前仅支持2in1设备使用。

**系统能力**：SystemCapability.FileManagement.File.Environment.FolderObtain

**返回值：**

| 类型                  | 说明                  |
| --------------------- |---------------------|
| string | 返回当前用户预授权下载目录的沙箱路径。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 801      | Capability not supported. |
| 13900042 | Unknown error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
function getUserDownloadDirExample() {
  try {
    let path = Environment.getUserDownloadDir();
    console.info(`Succeeded in getUserDownloadDir, path is ${path}`);
  } catch (err) {
    console.error(`Failed to getUserDownloadDir. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## Environment.getUserDesktopDir

getUserDesktopDir(): string

获取当前用户预授权桌面目录的沙箱路径。当前仅支持2in1设备使用。

**系统能力**：SystemCapability.FileManagement.File.Environment.FolderObtain

**返回值：**

| 类型                  | 说明                  |
| --------------------- |---------------------|
| string | 返回当前用户预授权桌面目录的沙箱路径。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 801      | Capability not supported. |
| 13900042 | Unknown error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
function getUserDesktopDirExample() {
  try {
    let path = Environment.getUserDesktopDir();
    console.info(`Succeeded in getUserDesktopDir, path is ${path}`);
  } catch (err) {
    console.error(`Failed to getUserDesktopDir. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## Environment.getUserDocumentDir

getUserDocumentDir(): string

获取当前用户预授权文档目录的沙箱路径。当前仅支持2in1设备使用。

**系统能力**：SystemCapability.FileManagement.File.Environment.FolderObtain

**返回值：**

| 类型                  | 说明                  |
| --------------------- |---------------------|
| string | 返回当前用户预授权文档目录的沙箱路径。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID    | 错误信息       |
|----------| --------- |
| 801      | Capability not supported. |
| 13900042 | Unknown error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
function getUserDocumentDirExample() {
  try {
    let path = Environment.getUserDocumentDir();
    console.info(`Succeeded in getUserDocumentDir, path is ${path}`);
  } catch (err) {
    console.error(`Failed to getUserDocumentDir. Code: ${err.code}, message: ${err.message}`);
  }
}
```