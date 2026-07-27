# @ohos.file.environment (目录环境能力)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25; @gsl_1234; @wuchengjun5-->
<!--Designer: @gsl_1234; @wangke25-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @jinqiuheng-->

该模块提供用户环境目录能力，用于获取用户的下载目录、桌面目录、文档目录的沙箱路径。上述三个方法分别适用于获取不同类型用户目录的场景，开发者可根据需要选择对应的目录类型。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { Environment } from '@kit.CoreFileKit';
```

## Environment.getUserDownloadDir

getUserDownloadDir(): string

获取当前用户的下载目录的沙箱路径。

**系统能力**：SystemCapability.FileManagement.File.Environment.FolderObtain

**设备行为差异**：
- 在API版本26.0.0及之后：该接口在PC/2in1和Tablet中可正常调用，在其他设备类型中返回801错误码。
- 在API版本26.0.0之前：该接口在PC/2in1可正常调用，在其他设备类型中返回801错误码。

**返回值：**

| 类型                  | 说明                  |
| --------------------- |---------------------|
| string | 返回当前用户的下载目录的沙箱路径。 |

**错误码：**

以下错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

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

获取当前用户的桌面目录的沙箱路径。

**系统能力**：SystemCapability.FileManagement.File.Environment.FolderObtain

**设备行为差异**：
- 在API版本26.0.0及之后：该接口在PC/2in1和Tablet中可正常调用，在其他设备类型中返回801错误码。
- 在API版本26.0.0之前：该接口在PC/2in1可正常调用，在其他设备类型中返回801错误码。

**返回值：**

| 类型                  | 说明                  |
| --------------------- |---------------------|
| string | 返回当前用户的桌面目录的沙箱路径。 |

**错误码：**

以下错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

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

获取当前用户的文档目录的沙箱路径。

**系统能力**：SystemCapability.FileManagement.File.Environment.FolderObtain

**设备行为差异**：
- 在API版本26.0.0及之后：该接口在PC/2in1和Tablet中可正常调用，在其他设备类型中返回801错误码。
- 在API版本26.0.0之前：该接口在PC/2in1可正常调用，在其他设备类型中返回801错误码。

**返回值：**

| 类型                  | 说明                  |
| --------------------- |---------------------|
| string | 返回当前用户的文档目录的沙箱路径。 |

**错误码：**

以下错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

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