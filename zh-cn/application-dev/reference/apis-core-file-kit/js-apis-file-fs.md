# @ohos.file.fs (文件管理)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25; @gsl_1234; @wuchengjun5-->
<!--Designer: @gsl_1234; @wangke25-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @jinqiuheng-->

该模块为基础文件操作API，提供基础文件操作能力，包括文件基本管理、文件目录管理、文件信息统计、文件流式读写等常用功能。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { fileIo } from '@kit.CoreFileKit';
```

## 使用说明

使用该功能模块对文件/目录进行操作前，需要先获取其应用沙箱路径，获取方式及其接口用法请参考：

  ```ts
  import { UIAbility } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';

  export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
      let context = this.context;
      let pathDir = context.filesDir;
    }
  }
  ```

获取沙箱路径的方式及其接口用法也可参考：[应用上下文Context-获取应用文件路径](../../application-models/application-context-stage.md#获取应用文件路径)。<br/>将指向资源的字符串称为URI。对于只支持沙箱路径作为入参的接口，可以使用构造fileUri对象并获取其沙箱路径的属性的方式将URI转换为沙箱路径，然后使用文件接口。URI定义及其转换方式请参考：[文件URI](../../../application-dev/reference/apis-core-file-kit/js-apis-file-fileuri.md)。

## fileIo.stat

stat(file: string | number): Promise&lt;Stat&gt;

获取文件或目录详细属性信息。使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| file | string \| number | 是 | 文件或目录的应用沙箱路径path、URI或已打开的文件描述符fd。<br>**说明**：从API version 22开始，支持传入URI。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;[Stat](#stat)&gt; | Promise对象，返回文件或目录的具体信息。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.stat(filePath).then((stat: fileIo.Stat) => {
    console.info(`Succeeded in getting file info, the size of file is ${stat.size}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get file info. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.stat

stat(file: string | number, callback: AsyncCallback&lt;Stat&gt;): void

获取文件或目录的详细属性信息。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| file | string \| number | 是 | 文件或目录的应用沙箱路径path、URI或已打开的文件描述符fd。<br>**说明**：从API version 22开始，支持传入URI。 |
| callback | AsyncCallback&lt;[Stat](#stat)&gt; | 是 | 异步获取文件或目录的信息之后的回调。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  fileIo.stat(pathDir, (err: BusinessError, stat: fileIo.Stat) => {
    if (err) {
      console.error(`Failed to get file info. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in getting file info, the size of file is ${stat.size}`);
    }
  });
  ```

## fileIo.statSync

statSync(file: string | number): Stat

以同步方法获取文件或目录详细属性信息。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| file | string \| number | 是 | 文件或目录的应用沙箱路径path、URI或已打开的文件描述符fd。<br>**说明**：从API version 22开始，支持传入URI。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [Stat](#stat) | 表示文件或目录的具体信息。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let stat = fileIo.statSync(pathDir);
  console.info(`Succeeded in getting file info, the size of file is ${stat.size}`);
  ```

## fileIo.access

access(path: string, mode?: AccessModeType): Promise&lt;boolean&gt;

检查文件或目录是否存在，或校验操作权限。使用Promise异步回调。<br>校验读、写或读写权限不通过会抛出13900012（Permission denied）错误码。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件或目录应用沙箱路径。 |
| mode<sup>12+</sup> | [AccessModeType](#accessmodetype12) | 否 | 文件或目录校验的权限。不填该参数则默认校验文件是否存在。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示文件或目录存在；返回false表示文件或目录不存在。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。


**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.access(filePath).then((res: boolean) => {
    if (res) {
      console.info(`Succeeded in checking file, file exists.`);
    } else {
      console.info(`Succeeded in checking file, file does not exist.`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to access. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.access<sup>12+</sup>

access(path: string, mode: AccessModeType, flag: AccessFlagType): Promise&lt;boolean&gt;

检查文件或目录是否在本地，或校验操作权限。使用Promise异步回调。<br>校验读、写或读写权限不通过会抛出13900012（Permission denied）错误码。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件或目录应用沙箱路径。 |
| mode | [AccessModeType](#accessmodetype12) | 是 | 文件或目录校验的权限。 |
| flag | [AccessFlagType](#accessflagtype12) | 是 | 文件或目录校验的位置。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示文件或目录在本地且校验权限存在；返回false表示文件或目录不存在或者文件或目录在云端或其他分布式设备上。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.access(filePath, fileIo.AccessModeType.EXIST, fileIo.AccessFlagType.LOCAL).then((res: boolean) => {
    if (res) {
      console.info(`Succeeded in checking file, file exists.`);
    } else {
      console.info(`Succeeded in checking file, file does not exist.`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to access. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.access

access(path: string, callback: AsyncCallback&lt;boolean&gt;): void

检查文件或目录是否存在。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件或目录应用沙箱路径。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 异步检查文件或目录是否存在的回调。如果存在，回调返回true；否则返回false。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。


**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.access(filePath, (err: BusinessError, res: boolean) => {
    if (err) {
      console.error(`Failed to access. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (res) {
        console.info(`Succeeded in checking file, file exists.`);
      } else {
        console.info(`Succeeded in checking file, file does not exist.`);
      }
    }
  });
  ```

## fileIo.accessSync

accessSync(path: string, mode?: AccessModeType): boolean

以同步方法检查文件或目录是否存在，或校验操作权限。<br>校验读、写或读写权限不通过会抛出13900012（Permission denied）错误码。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件或目录应用沙箱路径。 |
| mode<sup>12+</sup> | [AccessModeType](#accessmodetype12) | 否 | 文件或目录校验的权限。不填该参数则默认校验文件或目录是否存在。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| boolean | 返回true，表示文件或目录存在；返回false，表示文件或目录不存在。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  try {
    let res = fileIo.accessSync(filePath);
    if (res) {
      console.info(`Succeeded in checking file, file exists.`);
    } else {
      console.info(`Succeeded in checking file, file does not exist.`);
    }
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`Failed to accessSync. Code: ${err.code}, message: ${err.message}`);
  }
  ```

## fileIo.accessSync<sup>12+</sup>

accessSync(path: string, mode: AccessModeType, flag: AccessFlagType): boolean

以同步方法检查文件或目录是否在本地，或校验操作权限。<br>校验读、写或读写权限不通过会抛出13900012（Permission denied）错误码。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件应用沙箱路径。 |
| mode | [AccessModeType](#accessmodetype12) | 是 | 文件或目录校验的权限。 |
| flag | [AccessFlagType](#accessflagtype12) | 是 | 文件或目录校验的位置。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| boolean | 返回true，表示文件或目录在本地且校验权限存在；返回false，表示文件或目录不存在或者文件或目录在云端或其他分布式设备上。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  try {
    let res = fileIo.accessSync(filePath, fileIo.AccessModeType.EXIST, fileIo.AccessFlagType.LOCAL);
    if (res) {
      console.info(`Succeeded in checking file, file exists.`);
    } else {
      console.info(`Succeeded in checking file, file does not exist.`);
    }
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`Failed to accessSync. Code: ${err.code}, message: ${err.message}`);
  }
  ```

## fileIo.close

close(file: number | File): Promise&lt;void&gt;

关闭文件或目录。使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| file | number \| [File](#file) | 是 | 已打开的File对象或已打开的文件描述符fd。关闭后File对象或文件描述符fd不可再用于读写等操作，继续使用可能导致错误或操作失败。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.close(file).then(() => {
    console.info(`Succeeded in closing file.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to close file. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.close

close(file: number | File, callback: AsyncCallback&lt;void&gt;): void

关闭文件或目录。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| file | number \| [File](#file) | 是 | 已打开的File对象或已打开的文件描述符fd。关闭后File对象或文件描述符fd不可再用于读写等操作，继续使用可能导致错误或操作失败。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当异步关闭文件或目录成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.close(file, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to close file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in closing file.`);
    }
  });
  ```

## fileIo.closeSync

closeSync(file: number | File): void

以同步方法关闭文件或目录。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| file | number \| [File](#file) | 是 | 已打开的File对象或已打开的文件描述符fd。关闭后File对象或文件描述符fd不可再用于读写等操作，继续使用可能导致错误或操作失败。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.closeSync(file);
  ```

## fileIo.copy<sup>11+</sup>

copy(srcUri: string, destUri: string, options?: CopyOptions): Promise\<void>

拷贝文件或目录。使用Promise异步回调。

支持跨设备拷贝。强制覆盖拷贝。入参支持文件或目录URI。<br/>
跨端拷贝时，最多同时存在10个拷贝任务；单次拷贝的文件数量不得超过500个。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| srcUri | string | 是 | 待复制文件或目录的URI。 |
| destUri | string | 是 | 目标文件或目录的URI。 |
| options | [CopyOptions](#copyoptions11)| 否| options中提供拷贝进度回调。不填该参数则无拷贝进度回调。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileUri } from '@kit.CoreFileKit';

let srcDirPathLocal: string = pathDir + "/src";
let dstDirPathLocal: string = pathDir + "/dest";

let srcDirUriLocal: string = fileUri.getUriFromPath(srcDirPathLocal);
let dstDirUriLocal: string = fileUri.getUriFromPath(dstDirPathLocal);

let progressListener: fileIo.ProgressListener = (progress: fileIo.Progress) => {
  console.info(`progressSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
};
let copyOption: fileIo.CopyOptions = {
  "progressListener" : progressListener
}
try {
  fileIo.copy(srcDirUriLocal, dstDirUriLocal, copyOption).then(()=>{
    console.info("Succeeded in copying.");
  }).catch((err: BusinessError)=>{
    console.error(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
  })
} catch (err) {
  console.error(`Failed to copy.Code: ${err.code}, message: ${err.message}`);
}
```

## fileIo.copy<sup>11+</sup>

copy(srcUri: string, destUri: string, callback: AsyncCallback\<void>): void

拷贝文件或者目录。使用callback异步回调。

支持跨设备拷贝。强制覆盖拷贝。入参支持文件或目录URI。<br/>
跨端拷贝时，最多同时存在10个拷贝任务；单次拷贝的文件数量不得超过500个。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| srcUri | string | 是 | 待复制文件或目录的URI。 |
| destUri | string | 是 | 目标文件或目录的URI。 |
| callback | AsyncCallback\<void>| 是 | 回调函数。当拷贝成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileUri } from '@kit.CoreFileKit';

let srcDirPathLocal: string = pathDir + "/src";
let dstDirPathLocal: string = pathDir + "/dest";

let srcDirUriLocal: string = fileUri.getUriFromPath(srcDirPathLocal);
let dstDirUriLocal: string = fileUri.getUriFromPath(dstDirPathLocal);

try {
  fileIo.copy(srcDirUriLocal, dstDirUriLocal, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("Succeeded in copying.");
  })
} catch (err) {
  console.error(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
}
```

## fileIo.copy<sup>11+</sup>

copy(srcUri: string, destUri: string, options: CopyOptions, callback: AsyncCallback\<void>): void

拷贝文件或者目录。使用callback异步回调。

支持跨设备拷贝。强制覆盖拷贝。入参支持文件或目录URI。<br/>
跨端拷贝时，最多同时存在10个拷贝任务；单次拷贝的文件数量不得超过500个。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| srcUri | string | 是 | 待复制文件或目录的URI。 |
| destUri | string | 是 | 目标文件或目录的URI。 |
| options | [CopyOptions](#copyoptions11) |是 | 拷贝进度回调。 |
| callback | AsyncCallback\<void>| 是 | 回调函数。当拷贝成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileUri } from '@kit.CoreFileKit';

let srcDirPathLocal: string = pathDir + "/src";
let dstDirPathLocal: string = pathDir + "/dest";

let srcDirUriLocal: string = fileUri.getUriFromPath(srcDirPathLocal);
let dstDirUriLocal: string = fileUri.getUriFromPath(dstDirPathLocal);

try {
  let progressListener: fileIo.ProgressListener = (progress: fileIo.Progress) => {
    console.info(`progressSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
  };
  let copyOption: fileIo.CopyOptions = {
    "progressListener" : progressListener
  }
  fileIo.copy(srcDirUriLocal, dstDirUriLocal, copyOption, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("Succeeded in copying.");
  })
} catch (err) {
  console.error(`Failed to copy. Code: ${err.code}, message: ${err.message}`);
}
```

## fileIo.copyFile

copyFile(src: string | number, dest: string | number, mode?: number): Promise&lt;void&gt;

复制文件。使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string \| number | 是 | 待复制文件的路径或待复制文件的文件描述符。 |
| dest | string \| number | 是 | 目标文件路径或目标文件的文件描述符。 |
| mode | number | 否 | mode提供覆盖文件的选项，当前仅支持0，且默认为0。<br/>0：完全覆盖目标文件，未覆盖部分将被裁剪掉。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcPath = pathDir + "/srcDir/test.txt";
  let dstPath = pathDir + "/dstDir/test.txt";
  fileIo.copyFile(srcPath, dstPath, 0).then(() => {
    console.info(`Succeeded in copying file.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to copy file. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.copyFile

copyFile(src: string | number, dest: string | number, mode: number, callback: AsyncCallback&lt;void&gt;): void

复制文件，可设置覆盖文件的方式。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string \| number | 是 | 待复制文件的路径或待复制文件的文件描述符。 |
| dest | string \| number | 是 | 目标文件路径或目标文件的文件描述符。 |
| mode | number | 是 | mode提供覆盖文件的选项，当前仅支持0，且默认为0。<br/>0：完全覆盖目标文件，未覆盖部分将被裁剪掉。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当复制文件成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcPath = pathDir + "/srcDir/test.txt";
  let dstPath = pathDir + "/dstDir/test.txt";
  fileIo.copyFile(srcPath, dstPath, 0, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to copy file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in copying file.`);
    }
  });
  ```

## fileIo.copyFile

copyFile(src: string | number, dest: string | number, callback: AsyncCallback&lt;void&gt;): void

复制文件，覆盖方式为完全覆盖目标文件，未覆盖部分将被裁剪。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string \| number | 是 | 待复制文件的路径或待复制文件的文件描述符。 |
| dest | string \| number | 是 | 目标文件路径或目标文件的文件描述符。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当复制文件成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcPath = pathDir + "/srcDir/test.txt";
  let dstPath = pathDir + "/dstDir/test.txt";
  fileIo.copyFile(srcPath, dstPath, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to copy file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in copying file.`);
    }
  });
  ```


## fileIo.copyFileSync

copyFileSync(src: string | number, dest: string | number, mode?: number): void

以同步方法复制文件。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string \| number | 是 | 待复制文件的路径或待复制文件的文件描述符。 |
| dest | string \| number | 是 | 目标文件路径或目标文件的文件描述符。 |
| mode | number | 否 | mode提供覆盖文件的选项，当前仅支持0，且默认为0。<br/>0：完全覆盖目标文件，未覆盖部分将被裁剪掉。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let srcPath = pathDir + "/srcDir/test.txt";
  let dstPath = pathDir + "/dstDir/test.txt";
  fileIo.copyFileSync(srcPath, dstPath);
  ```

## fileIo.copyDir<sup>10+</sup>

copyDir(src: string, dest: string, mode?: number): Promise\<void>

复制源目录至目标路径下。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string | 是 | 源目录的应用沙箱路径。 |
| dest | string | 是 | 目标目录的应用沙箱路径。 |
| mode | number | 否 | 复制模式，默认值为0。<br/>-&nbsp; mode为0，文件级别抛异常。目标目录下存在与源目录名冲突的目录，若冲突目录下存在同名文件，则抛出异常。源目录下未冲突的文件全部拷贝至目标目录下，目标目录下未冲突文件将继续保留，且冲突文件信息将在抛出异常的data属性中以Array\<[ConflictFiles](#conflictfiles10)>形式提供。<br/>-&nbsp; mode为1，文件级别强制覆盖。目标目录下存在与源目录名冲突的目录，若冲突目录下存在同名文件，则强制覆盖冲突目录下所有同名文件，未冲突文件将继续保留。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // copy directory from srcPath to destPath
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fileIo.copyDir(srcPath, destPath, 0).then(() => {
    console.info(`Succeeded in copying directory.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to copy directory. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.copyDir<sup>10+</sup>

copyDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void

复制源目录至目标路径下，可设置复制模式。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string | 是 | 源目录的应用沙箱路径。 |
| dest | string | 是 | 目标目录的应用沙箱路径。 |
| mode | number | 是 | 复制模式。<br/>-&nbsp; mode为0，文件级别抛异常。目标目录下存在与源目录名冲突的目录，若冲突目录下存在同名文件，则抛出异常。源目录下未冲突的文件全部拷贝至目标目录下，目标目录下未冲突文件将继续保留。<br/>-&nbsp; mode为1，文件级别强制覆盖。目标目录下存在与源目录名冲突的目录，若冲突目录下存在同名文件，则强制覆盖冲突目录下所有同名文件，未冲突文件将继续保留。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当复制目录成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// copy directory from srcPath to destPath
let srcPath = pathDir + "/srcDir/";
let destPath = pathDir + "/destDir/";
fileIo.copyDir(srcPath, destPath, 0, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to copy directory. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in copying directory.`);
  }
});
```

## fileIo.copyDir<sup>10+</sup>

copyDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void

复制源目录至目标路径下，可设置复制模式。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string | 是 | 源目录的应用沙箱路径。 |
| dest | string | 是 | 目标目录的应用沙箱路径。 |
| mode | number | 是 | 复制模式。<br/>-&nbsp; mode为0，文件级别抛异常。目标目录下存在与源目录名冲突的目录，若冲突目录下存在同名文件，则抛出异常。源目录下未冲突的文件全部拷贝至目标目录下，目标目录下未冲突文件将继续保留，且冲突文件信息将在抛出异常的data属性中以Array\<[ConflictFiles](#conflictfiles10)>形式提供。<br/>-&nbsp; mode为1，文件级别强制覆盖。目标目录下存在与源目录名冲突的目录，若冲突目录下存在同名文件，则强制覆盖冲突目录下所有同名文件，未冲突文件将继续保留。 |
| callback | AsyncCallback&lt;void, Array&lt;[ConflictFiles](#conflictfiles10)&gt;&gt; | 是 | 回调函数。当复制目录成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { ConflictFiles } from '@kit.CoreFileKit';

  // copy directory from srcPath to destPath
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fileIo.copyDir(srcPath, destPath, 0, (err: BusinessError<Array<ConflictFiles>>) => {
    if (err && err.code == 13900015 && err.data?.length !== undefined) {
      for (let i = 0; i < err.data.length; i++) {
        console.error(`Failed to copy directory, with conflicting files: ${err.data[i].srcFile} ${err.data[i].destFile}`);
      }
    } else if (err) {
      console.error(`Failed to copy directory. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in copying directory.`);
    }
  });
  ```

## fileIo.copyDir<sup>10+</sup>

copyDir(src: string, dest: string, callback: AsyncCallback\<void>): void

复制源目录至目标路径下。使用callback异步回调。

如果目标目录下有与源目录名冲突的目录，且冲突目录下有同名文件，则抛出异常。源目录下未冲突的文件全部拷贝至目标目录下，目标目录下未冲突文件将继续保留。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string | 是 | 源目录的应用沙箱路径。 |
| dest | string | 是 | 目标目录的应用沙箱路径。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当复制目录成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// copy directory from srcPath to destPath
let srcPath = pathDir + "/srcDir/";
let destPath = pathDir + "/destDir/";
fileIo.copyDir(srcPath, destPath, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to copy directory. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in copying directory.`);
  }
});
```

## fileIo.copyDir<sup>10+</sup>

copyDir(src: string, dest: string, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void

复制源目录至目标路径下。使用callback异步回调。

如果目标目录下有与源目录名冲突的目录，且冲突目录下有同名文件，则抛出异常。源目录下未冲突的文件全部拷贝至目标目录下，目标目录下未冲突文件将继续保留，且冲突文件信息将在抛出异常的data属性中以Array\<[ConflictFiles](#conflictfiles10)>形式提供。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string | 是 | 源目录的应用沙箱路径。 |
| dest | string | 是 | 目标目录的应用沙箱路径。 |
| callback | AsyncCallback&lt;void, Array&lt;[ConflictFiles](#conflictfiles10)&gt;&gt; | 是 | 异步复制目录之后的回调。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { ConflictFiles } from '@kit.CoreFileKit';

  // copy directory from srcPath to destPath
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  fileIo.copyDir(srcPath, destPath, (err: BusinessError<Array<ConflictFiles>>) => {
    if (err && err.code == 13900015 && err.data?.length !== undefined) {
      for (let i = 0; i < err.data.length; i++) {
        console.error(`Failed to copy directory, with conflicting files: ${err.data[i].srcFile} ${err.data[i].destFile}`);
      }
    } else if (err) {
      console.error(`Failed to copy directory. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in copying directory.`);
    }
  });
  ```

## fileIo.copyDirSync<sup>10+</sup>

copyDirSync(src: string, dest: string, mode?: number): void

以同步方法复制源目录至目标路径下。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string | 是 | 源目录的应用沙箱路径。 |
| dest | string | 是 | 目标目录的应用沙箱路径。 |
| mode | number | 否 | 复制模式，默认值为0。<br/>-&nbsp; mode为0，文件级别抛异常。目标目录下存在与源目录名冲突的目录，若冲突目录下存在同名文件，则抛出异常。源目录下未冲突的文件全部拷贝至目标目录下，目标目录下未冲突文件将继续保留，且冲突文件信息将在抛出异常的data属性中以Array\<[ConflictFiles](#conflictfiles10)>形式提供。<br/>-&nbsp; mode为1，文件级别强制覆盖。目标目录下存在与源目录名冲突的目录，若冲突目录下存在同名文件，则强制覆盖冲突目录下所有同名文件，未冲突文件将继续保留。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // copy directory from srcPath to destPath
  let srcPath = pathDir + "/srcDir/";
  let destPath = pathDir + "/destDir/";
  try {
    fileIo.copyDirSync(srcPath, destPath, 0);
    console.info(`Succeeded in copying directory.`);
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`Failed to copy directory. Code: ${err.code}, message: ${err.message}`);
  }
  ```

## fileIo.dup<sup>10+</sup>

dup(fd: number): File

复制文件描述符，并返回对应的File对象。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 文件描述符。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [File](#file) | 打开的File对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file1 = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  let fd: number = file1.fd;
  let file2 = fileIo.dup(fd);
  console.info(`Succeeded in getting file name of the file2 is ${file2.name}`);
  fileIo.closeSync(file1);
  fileIo.closeSync(file2);
  ```

## fileIo.connectDfs<sup>12+</sup>

connectDfs(networkId: string, listeners: DfsListeners): Promise&lt;void&gt;

业务调用connectDfs接口，触发建链。如果对端设备出现异常，业务执行回调DfsListeners内[onStatus](#onstatus12)通知应用。可参考[跨设备文件共享和访问](../../file-management/file-access-across-devices.md)文档进行开发。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| networkId | string | 是 | 设备的网络Id。通过[distributedDeviceManager](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md)接口调用[DeviceBasicInfo](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#devicebasicinfo)获得。 |
| listeners | [DfsListeners](#fileiodfslisteners12) | 是 | 分布式文件系统状态监听器。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt;| Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';

  let dmInstance = distributedDeviceManager.createDeviceManager("com.example.filesync");
  let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
  if (deviceInfoList && deviceInfoList.length > 0) {
    console.info(`Succeeded in getting available device list.`);
    let networkId = deviceInfoList[0].networkId;
    let listeners: fileIo.DfsListeners = {
      onStatus(networkId, status) {
        console.info('onStatus');
      }
    };
    fileIo.connectDfs(networkId, listeners).then(() => {
      console.info("Succeeded in connecting dfs.");
    }).catch((err: BusinessError) => {
      console.error(`Failed to connectDfs. Code: ${err.code}, message: ${err.message}`);
    });
  }
  ```

## fileIo.disconnectDfs<sup>12+</sup>

disconnectDfs(networkId: string): Promise&lt;void&gt;

业务调用disconnectDfs接口，传入networkId参数，触发断链。可参考[跨设备文件共享和访问](../../file-management/file-access-across-devices.md)文档进行开发。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| networkId | string | 是 | 设备的网络Id。通过[distributedDeviceManager](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md)接口调用[DeviceBasicInfo](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#devicebasicinfo)获得。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt;| Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[空间统计错误码](errorcode-filemanagement.md#空间统计错误码)和[通用错误码](../errorcode-universal.md)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';

  let dmInstance = distributedDeviceManager.createDeviceManager("com.example.filesync");
  let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
  if (deviceInfoList && deviceInfoList.length > 0) {
    console.info(`Succeeded in getting available device list.`);
    let networkId = deviceInfoList[0].networkId;
    fileIo.disconnectDfs(networkId).then(() => {
      console.info("Succeeded in disconnecting dfs.");
    }).catch((err: BusinessError) => {
      console.error(`Failed to disconnect dfs. Code: ${err.code}, message: ${err.message}`);
    })
  }
  ```

## fileIo.setxattr<sup>12+</sup>

setxattr(path: string, key: string, value: string): Promise&lt;void&gt;

设置文件或目录的扩展属性。使用promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件或目录的应用沙箱路径。 |
| key | string | 是 | 扩展属性的key。仅支持前缀为“user.”的字符串，且长度需小于256字节。 |
| value | string | 是 | 扩展属性的value。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt;| Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let attrKey = "user.comment";
  let attrValue = "Test file.";

  fileIo.setxattr(filePath, attrKey, attrValue).then(() => {
    console.info(`Succeeded in setting extended attribute.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set extended attribute. Code: ${err.code}, message: ${err.message}`);
  });

  ```
## fileIo.setxattrSync<sup>12+</sup>

setxattrSync(path: string, key: string, value: string): void

设置文件或目录的扩展属性。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件或目录的应用沙箱路径。 |
| key | string | 是 | 扩展属性的key。仅支持前缀为“user.”的字符串，且长度需小于256字节。 |
| value | string | 是 | 扩展属性的value。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let attrKey = "user.comment";
  let attrValue = "Test file.";

  try {
    fileIo.setxattrSync(filePath, attrKey, attrValue);
    console.info(`Succeeded in setting extended attribute.`);
  } catch (err) {
    console.error(`Failed to set extended attribute. Code: ${err.code}, message: ${err.message}`);
  }

  ```

## fileIo.getxattr<sup>12+</sup>

getxattr(path: string, key: string): Promise&lt;string&gt;

获取文件或目录的扩展属性。使用promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件或目录的应用沙箱路径。 |
| key | string | 是 | 扩展属性的key。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;string&gt;| Promise对象，返回扩展属性的value。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let attrKey = "user.comment";

  fileIo.getxattr(filePath, attrKey).then((attrValue: string) => {
    console.info(`Succeeded in getting extended attribute, the value is: ${attrValue}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get extended attribute. Code: ${err.code}, message: ${err.message}`);
  });

  ```

## fileIo.getxattrSync<sup>12+</sup>

getxattrSync(path: string, key: string): string

使用同步接口获取文件或目录的扩展属性。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件或目录的应用沙箱路径。 |
| key | string | 是 | 扩展属性的key。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| string | 返回扩展属性的value。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let attrKey = "user.comment";

  try {
    let attrValue = fileIo.getxattrSync(filePath, attrKey);
    console.info(`Succeeded in getting extended attribute, the value is: ${attrValue}`);
  } catch (err) {
    console.error(`Failed to get extended attribute. Code: ${err.code}, message: ${err.message}`);
  }

  ```

## fileIo.mkdir

mkdir(path: string): Promise&lt;void&gt;

创建目录。使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 目录的应用沙箱路径。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let dirPath = pathDir + "/testDir";
  fileIo.mkdir(dirPath).then(() => {
    console.info(`Succeeded in making directory.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to make directory. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.mkdir<sup>11+</sup>

mkdir(path: string, recursion: boolean): Promise\<void>

创建目录。使用Promise异步回调。当recursion指定为true时，可递归创建目录。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 目录的应用沙箱路径。 |
| recursion | boolean | 是 | 是否递归创建目录。recursion指定为true时，可递归创建目录。recursion指定为false时，仅可创建单层目录。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let dirPath = pathDir + "/testDir1/testDir2/testDir3";
  fileIo.mkdir(dirPath, true).then(() => {
    console.info(`Succeeded in making directory.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to make directory. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.mkdir

mkdir(path: string, callback: AsyncCallback&lt;void&gt;): void

创建目录。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 目录的应用沙箱路径。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当创建目录成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let dirPath = pathDir + "/testDir";
  fileIo.mkdir(dirPath, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to make directory. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in making directory.`);
    }
  });
  ```

## fileIo.mkdir<sup>11+</sup>

mkdir(path: string, recursion: boolean, callback: AsyncCallback&lt;void&gt;): void

创建目录，当recursion指定为true，可递归创建目录。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 目录的应用沙箱路径。 |
| recursion | boolean | 是 | 是否递归创建目录。recursion指定为true时，可递归创建目录。recursion指定为false时，仅可创建单层目录。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当创建目录成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let dirPath = pathDir + "/testDir1/testDir2/testDir3";
  fileIo.mkdir(dirPath, true, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to make directory. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in making directory.`);
    }
  });
  ```

## fileIo.mkdirSync

mkdirSync(path: string): void

以同步方法创建目录。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 目录的应用沙箱路径。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let dirPath = pathDir + "/testDir";
  fileIo.mkdirSync(dirPath);
  ```

## fileIo.mkdirSync<sup>11+</sup>

mkdirSync(path: string, recursion: boolean): void

以同步方法创建目录。当recursion指定为true，可递归创建目录。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 目录的应用沙箱路径。 |
| recursion | boolean | 是 | 是否递归创建目录。recursion指定为true时，可递归创建目录。recursion指定为false时，仅可创建单层目录。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let dirPath = pathDir + "/testDir1/testDir2/testDir3";
  fileIo.mkdirSync(dirPath, true);
  ```

## fileIo.open

open(path: string, mode?: number): Promise&lt;File&gt;

打开文件或目录。使用Promise异步回调。支持使用URI打开文件。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件或目录的应用沙箱路径或文件URI。 |
| mode | number | 否 | 打开文件或目录的[OpenMode](#openmode)，必须指定如下选项中的一个，默认以只读方式打开：<br/>-&nbsp;OpenMode.READ_ONLY(0o0)：只读打开。<br/>-&nbsp;OpenMode.WRITE_ONLY(0o1)：只写打开。<br/>-&nbsp;OpenMode.READ_WRITE(0o2)：读写打开。<br/>可以追加以下功能选项，以按位或的方式组合，默认情况下不追加任何额外选项。<br/>-&nbsp;OpenMode.CREATE(0o100)：如果文件不存在，则创建文件。<br/>-&nbsp;OpenMode.TRUNC(0o1000)：如果文件存在且文件具有写权限，则将其长度裁剪为零。<br/>-&nbsp;OpenMode.APPEND(0o2000)：以追加方式打开，后续写将追加到文件末尾。<br/>-&nbsp;OpenMode.NONBLOCK(0o4000)：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续&nbsp;IO&nbsp;进行非阻塞操作。<br/>-&nbsp;OpenMode.DIR(0o200000)：如果path不指向目录，则出错。不允许附加写权限。<br/>-&nbsp;OpenMode.NOFOLLOW(0o400000)：如果path指向符号链接，则出错。<br/>-&nbsp;OpenMode.SYNC(0o4010000)：以同步IO方式打开文件。<br/>- OpenMode.UNCACHE(0o10000000000)：读写文件不进行页缓存，从API版本26.0.0开始支持此选项。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;[File](#file)&gt; | Promise对象，返回File对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.open(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE).then((file: fileIo.File) => {
    console.info(`Succeeded in getting file fd: ${file.fd}`);
    fileIo.closeSync(file);
  }).catch((err: BusinessError) => {
    console.error(`Failed to open file. Code: ${err.code}, message: ${err.message}`);
  });
  ```


## fileIo.open

open(path: string, mode: number, callback: AsyncCallback&lt;File&gt;): void

打开文件或目录，可设置打开文件的选项。使用callback异步回调。

支持使用URI打开文件。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件或目录的应用沙箱路径或URI。 |
| mode | number | 是 | 打开文件或目录的[OpenMode](#openmode)，必须指定如下选项中的一个，默认以只读方式打开：<br/>-&nbsp;OpenMode.READ_ONLY(0o0)：只读打开。<br/>-&nbsp;OpenMode.WRITE_ONLY(0o1)：只写打开。<br/>-&nbsp;OpenMode.READ_WRITE(0o2)：读写打开。<br/>给定如下功能选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-&nbsp;OpenMode.CREATE(0o100)：若文件不存在，则创建文件。<br/>-&nbsp;OpenMode.TRUNC(0o1000)：如果文件存在且文件具有写权限，则将其长度裁剪为零。<br/>-&nbsp;OpenMode.APPEND(0o2000)：以追加方式打开，后续写将追加到文件末尾。<br/>-&nbsp;OpenMode.NONBLOCK(0o4000)：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续&nbsp;IO&nbsp;进行非阻塞操作。<br/>-&nbsp;OpenMode.DIR(0o200000)：如果path不指向目录，则出错。不允许附加写权限。<br/>-&nbsp;OpenMode.NOFOLLOW(0o400000)：如果path指向符号链接，则出错。<br/>-&nbsp;OpenMode.SYNC(0o4010000)：以同步IO的方式打开文件。<br/>- OpenMode.UNCACHE(0o10000000000)：读写文件不进行页缓存，从API版本26.0.0开始支持此选项。 |
| callback | AsyncCallback&lt;[File](#file)&gt; | 是 | 回调函数，返回File对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.open(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE, (err: BusinessError, file: fileIo.File) => {
    if (err) {
      console.error(`Failed to open. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in getting file fd: ${file.fd}`);
      fileIo.closeSync(file);
    }
  });
  ```

## fileIo.open

open(path: string, callback: AsyncCallback&lt;File&gt;): void

打开文件或目录，支持使用URI打开文件。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件或目录的应用沙箱路径或URI。 |
| callback | AsyncCallback&lt;[File](#file)&gt; | 是 | 回调函数，返回File对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.open(filePath, (err: BusinessError, file: fileIo.File) => {
    if (err) {
      console.error(`Failed to open. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in getting file fd: ${file.fd}`);
      fileIo.closeSync(file);
    }
  });
  ```

## fileIo.openSync

openSync(path: string, mode?: number): File

以同步方法打开文件或目录。支持使用URI打开文件。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 打开文件或目录的应用沙箱路径或URI。 |
| mode | number | 否 | 打开文件或目录的[OpenMode](#openmode)，必须指定如下选项中的一个，默认以只读方式打开：<br/>-&nbsp;OpenMode.READ_ONLY(0o0)：只读打开。<br/>-&nbsp;OpenMode.WRITE_ONLY(0o1)：只写打开。<br/>-&nbsp;OpenMode.READ_WRITE(0o2)：读写打开。<br/>给定如下功能选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-&nbsp;OpenMode.CREATE(0o100)：若文件不存在，则创建文件。<br/>-&nbsp;OpenMode.TRUNC(0o1000)：如果文件存在且文件具有写权限，则将其长度裁剪为零。<br/>-&nbsp;OpenMode.APPEND(0o2000)：以追加方式打开，后续写将追加到文件末尾。<br/>-&nbsp;OpenMode.NONBLOCK(0o4000)：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续&nbsp;IO&nbsp;进行非阻塞操作。<br/>-&nbsp;OpenMode.DIR(0o200000)：如果path不指向目录，则出错。不允许附加写权限。<br/>-&nbsp;OpenMode.NOFOLLOW(0o400000)：如果path指向符号链接，则出错。<br/>-&nbsp;OpenMode.SYNC(0o4010000)：以同步IO的方式打开文件。<br/>- OpenMode.UNCACHE(0o10000000000)：读写文件不进行页缓存，从API版本26.0.0开始支持此选项。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [File](#file) | 打开的File对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  console.info(`Succeeded in getting file fd: ${file.fd}`);
  fileIo.closeSync(file);
  ```

## fileIo.read

read(fd: number, buffer: ArrayBuffer, options?: ReadOptions): Promise&lt;number&gt;

读取文件数据。使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 已打开的文件描述符。 |
| buffer | ArrayBuffer | 是 | 用于保存读取到的文件数据的缓冲区。 |
| options | [ReadOptions](#readoptions11) | 否 | 支持如下选项：<br/>-&nbsp;offset，number类型，表示期望读取文件的位置，单位为Byte。可选，默认从当前位置开始读。<br/>-&nbsp;length，number类型，表示期望读取数据的长度，单位为Byte。可选，默认缓冲区长度。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;number&gt; | Promise对象，返回实际读取的数据长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { buffer } from '@kit.ArkTS';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  let arrayBuffer = new ArrayBuffer(4096);
  fileIo.read(file.fd, arrayBuffer).then((readLen: number) => {
    let buf = buffer.from(arrayBuffer, 0, readLen);
    console.info(`Succeeded in reading file data. The content of file: ${buf.toString()}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to read file data. Code: ${err.code}, message: ${err.message}`);
  }).finally(() => {
    fileIo.closeSync(file);
  });
  ```

## fileIo.read

read(fd: number, buffer: ArrayBuffer, callback: AsyncCallback&lt;number&gt;): void

从文件读取数据。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 已打开的文件描述符。 |
| buffer | ArrayBuffer | 是 | 用于保存读取到的文件数据的缓冲区。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数。返回实际读取的数据长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { buffer } from '@kit.ArkTS';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  let arrayBuffer = new ArrayBuffer(4096);
  fileIo.read(file.fd, arrayBuffer, (err: BusinessError, readLen: number) => {
    if (err) {
      console.error(`Failed to read. Code: ${err.code}, message: ${err.message}`);
    } else {
      let buf = buffer.from(arrayBuffer, 0, readLen);
      console.info(`Succeeded in reading file data. The content of file: ${buf.toString()}`);
    }
    fileIo.closeSync(file);
  });
  ```

## fileIo.read

read(fd: number, buffer: ArrayBuffer, options: ReadOptions, callback: AsyncCallback&lt;number&gt;): void

从文件读取数据，支持配置读取选项。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 已打开的文件描述符。 |
| buffer | ArrayBuffer | 是 | 用于保存读取到的文件数据的缓冲区。 |
| options | [ReadOptions](#readoptions11) | 是 | 支持如下选项：<br/>-&nbsp;offset，number类型，表示期望读取文件的位置，单位为Byte。可选，默认从当前位置开始读。<br/>-&nbsp;length，number类型，表示期望读取数据的长度，单位为Byte。可选，默认缓冲区长度。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数，返回实际读取的数据长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { buffer } from '@kit.ArkTS';
  import { ReadOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  let arrayBuffer = new ArrayBuffer(4096);
  let readOption: ReadOptions = {
    offset: 1,
    length: 5
  };
  fileIo.read(file.fd, arrayBuffer, readOption, (err: BusinessError, readLen: number) => {
    if (err) {
      console.error(`Failed to read. Code: ${err.code}, message: ${err.message}`);
    } else {
      let buf = buffer.from(arrayBuffer, 0, readLen);
      console.info(`Succeeded in reading file data. The content of file: ${buf.toString()}`);
    }
    fileIo.closeSync(file);
  });
  ```

## fileIo.readSync

readSync(fd: number, buffer: ArrayBuffer, options?: ReadOptions): number

以同步方法从文件读取数据。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 已打开的文件描述符。 |
| buffer | ArrayBuffer | 是 | 用于保存读取到的文件数据的缓冲区。 |
| options | [ReadOptions](#readoptions11) | 否 | 支持如下选项：<br/>-&nbsp;offset，number类型，表示期望读取文件的位置，单位为Byte。可选，默认从当前位置开始读。<br/>-&nbsp;length，number类型，表示期望读取数据的长度，单位为Byte。可选，默认缓冲区长度。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| number | 返回实际读取的数据长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
  let buf = new ArrayBuffer(4096);
  fileIo.readSync(file.fd, buf);
  fileIo.closeSync(file);
  ```

## fileIo.rmdir

rmdir(path: string): Promise&lt;void&gt;

删除目录及其所有子目录和文件。使用Promise异步回调。

> **说明：**
>
> 该接口支持删除单个文件，但不推荐使用此方法删除单个文件，推荐使用unlink接口删除单个文件。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 目录的应用沙箱路径。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let dirPath = pathDir + "/testDir";
  fileIo.rmdir(dirPath).then(() => {
    console.info(`Succeeded in removing directory.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to remove directory. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.rmdir

rmdir(path: string, callback: AsyncCallback&lt;void&gt;): void

删除目录及其所有子目录和文件。使用callback异步回调。

> **说明：**
>
> 该接口支持删除单个文件，但不推荐使用此方法删除单个文件，推荐使用unlink接口删除单个文件。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 目录的应用沙箱路径。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当删除目录成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let dirPath = pathDir + "/testDir";
  fileIo.rmdir(dirPath, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to remove directory. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in removing directory.`);
    }
  });
  ```

## fileIo.rmdirSync

rmdirSync(path: string): void

以同步方法删除目录及其所有子目录和文件。

> **说明：**
>
> 该接口支持删除单个文件，但不推荐使用此方法删除单个文件，推荐使用unlinkSync接口删除单个文件。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 目录的应用沙箱路径。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let dirPath = pathDir + "/testDir";
  fileIo.rmdirSync(dirPath);
  ```

## fileIo.unlink

unlink(path: string): Promise&lt;void&gt;

删除单个文件。使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件的应用沙箱路径。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.unlink(filePath).then(() => {
    console.info(`Succeeded in removing file.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to remove file. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.unlink

unlink(path: string, callback: AsyncCallback&lt;void&gt;): void

删除文件。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件的应用沙箱路径。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当删除文件成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.unlink(filePath, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to remove file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in removing file.`);
    }
  });
  ```

## fileIo.unlinkSync

unlinkSync(path: string): void

以同步方法删除文件。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件的应用沙箱路径。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  fileIo.unlinkSync(filePath);
  ```


## fileIo.write

write(fd: number, buffer: ArrayBuffer | string, options?: WriteOptions): Promise&lt;number&gt;

将数据写入文件。使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 已打开的文件描述符。 |
| buffer | ArrayBuffer \| string | 是 | 待写入文件的数据，可来自缓冲区或字符串。 |
| options | [WriteOptions](#writeoptions11) | 否 | 支持如下选项：<br/>-&nbsp;offset，number类型，表示期望写入文件的位置，单位为Byte。可选，默认从当前位置开始写入。<br/>-&nbsp;length，number类型，表示期望写入数据的长度，单位为Byte。可选，默认缓冲区长度。<br/>-&nbsp;encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'。当前仅支持&nbsp;'utf-8'。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;number&gt; | Promise对象，返回实际写入的数据长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  let str: string = "hello, world";
  fileIo.write(file.fd, str).then((writeLen: number) => {
    console.info(`Succeeded in writing data to file, size is: ${writeLen}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to write data to file. Code: ${err.code}, message: ${err.message}`);
  }).finally(() => {
    fileIo.closeSync(file);
  });
  ```

## fileIo.write

write(fd: number, buffer: ArrayBuffer | string, callback: AsyncCallback&lt;number&gt;): void

将数据写入文件。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 已打开的文件描述符。 |
| buffer | ArrayBuffer \| string | 是 | 待写入文件的数据，可来自缓冲区或字符串。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数，返回实际写入的数据长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  let str: string = "hello, world";
  fileIo.write(file.fd, str, (err: BusinessError, writeLen: number) => {
    if (err) {
      console.error(`Failed to write data to file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in writing data to file, size is: ${writeLen}`);
    }
    fileIo.closeSync(file);
  });
  ```

## fileIo.write

write(fd: number, buffer: ArrayBuffer | string, options: WriteOptions, callback: AsyncCallback&lt;number&gt;): void

将数据写入文件，支持配置写入选项。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 已打开的文件描述符。 |
| buffer | ArrayBuffer \| string | 是 | 待写入文件的数据，可来自缓冲区或字符串。 |
| options | [WriteOptions](#writeoptions11) | 是 | 支持如下选项：<br/>-&nbsp;offset，number类型，表示期望写入文件的位置，单位为Byte。可选，默认从当前位置开始写。<br/>-&nbsp;length，number类型，表示期望写入数据的长度，单位为Byte。可选，默认缓冲区长度。<br/>-&nbsp;encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'。当前仅支持&nbsp;'utf-8'。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数，返回实际写入的数据长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { WriteOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  let str: string = "hello, world";
  let writeOptions: WriteOptions = {
    offset: 1,
    length: 5
  };
  fileIo.write(file.fd, str, writeOptions, (err: BusinessError, writeLen: number) => {
    if (err) {
      console.error(`Failed to write data to file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in writing data to file, size is: ${writeLen}`);
    }
    fileIo.closeSync(file);
  });
  ```

## fileIo.writeSync

writeSync(fd: number, buffer: ArrayBuffer | string, options?: WriteOptions): number

以同步方法将数据写入文件。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 已打开的文件描述符。 |
| buffer | ArrayBuffer \| string | 是 | 待写入文件的数据，可来自缓冲区或字符串。 |
| options | [WriteOptions](#writeoptions11) | 否 | 支持如下选项：<br/>-&nbsp;offset，number类型，表示期望写入文件的位置，单位为Byte。可选，默认从当前位置开始写。<br/>-&nbsp;length，number类型，表示期望写入数据的长度，单位为Byte。可选，默认缓冲区长度。<br/>-&nbsp;encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'。当前仅支持&nbsp;'utf-8'。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| number | 返回实际写入的数据长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  let str: string = "hello, world";
  let writeLen = fileIo.writeSync(file.fd, str);
  console.info(`Succeeded in writing data to file, size is: ${writeLen}`);
  fileIo.closeSync(file);
  ```

## fileIo.truncate

truncate(file: string | number, len?: number): Promise&lt;void&gt;

截断文件。使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| file | string \| number | 是 | 文件的应用沙箱路径或已打开的文件描述符fd。 |
| len | number | 否 | 文件截断后的长度，单位为Byte。默认为0。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let len: number = 5;
  fileIo.truncate(filePath, len).then(() => {
    console.info(`Succeeded in truncating file.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to truncate file. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.truncate

truncate(file: string | number, callback: AsyncCallback&lt;void&gt;): void

截断文件。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| file | string \| number | 是 | 文件的应用沙箱路径或已打开的文件描述符fd。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当截断文件成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.truncate(filePath, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to truncate. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in truncating.`);
    }
  });
  ```

## fileIo.truncate

truncate(file: string | number, len: number, callback: AsyncCallback&lt;void&gt;): void

截断文件，支持配置文件截断后的长度。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| file | string \| number | 是 | 文件的应用沙箱路径或已打开的文件描述符fd。 |
| len | number | 是 | 文件截断后的长度，单位为Byte。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当截断文件成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let len: number = 5;
  fileIo.truncate(filePath, len, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to truncate. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in truncating.`);
    }
  });
  ```

## fileIo.truncateSync

truncateSync(file: string | number, len?: number): void

以同步方法截断文件内容。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| file | string \| number | 是 | 文件的应用沙箱路径或已打开的文件描述符fd。 |
| len | number | 否 | 文件截断后的长度，单位为Byte。默认为0。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let len: number = 5;
  fileIo.truncateSync(filePath, len);
  ```

## fileIo.readLines<sup>11+</sup>

readLines(filePath: string, options?: Options): Promise&lt;ReaderIterator&gt;

逐行读取文件文本内容，只支持读取utf-8格式文件。使用promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| filePath | string | 是 | 文件的应用沙箱路径。 |
| options | [Options](#options11) | 否 | 可选项。支持以下选项：<br/>-&nbsp;encoding，string类型，当数据是&nbsp;string&nbsp;类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'，仅支持&nbsp;'utf-8'。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;[ReaderIterator](#readeriterator11)&gt; | Promise对象，返回文件读取迭代器。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { Options } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let options: Options = {
    encoding: 'utf-8'
  };
  fileIo.readLines(filePath, options).then((readerIterator: fileIo.ReaderIterator) => {
    for (let it = readerIterator.next(); !it.done; it = readerIterator.next()) {
      console.info(`Succeeded in reading lines, content: ${it.value}`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to read lines. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.readLines<sup>11+</sup>

readLines(filePath: string, callback: AsyncCallback&lt;ReaderIterator&gt;): void

逐行读取文件文本内容，只支持读取utf-8格式文件。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| filePath | string | 是 | 文件的应用沙箱路径。 |
| callback | AsyncCallback&lt;[ReaderIterator](#readeriterator11)&gt; | 是 | 回调函数，返回文件读取迭代器。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.readLines(filePath, (err: BusinessError, readerIterator: fileIo.ReaderIterator) => {
    if (err) {
      console.error(`Failed to read lines. Code: ${err.code}, message: ${err.message}`);
    } else {
      for (let it = readerIterator.next(); !it.done; it = readerIterator.next()) {
        console.info(`Succeeded in reading lines, content: ${it.value}`);
      }
    }
  });
  ```

## fileIo.readLines<sup>11+</sup>

readLines(filePath: string, options: Options, callback: AsyncCallback&lt;ReaderIterator&gt;): void

逐行读取文件文本内容，可配置读取选项，只支持读取utf-8格式文件。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| filePath | string | 是 | 文件的应用沙箱路径。 |
| options | [Options](#options11) | 是 | 读取选项。支持以下选项：<br/>-&nbsp;encoding，string类型，当数据是&nbsp;string&nbsp;类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'，仅支持&nbsp;'utf-8'。 |
| callback | AsyncCallback&lt;[ReaderIterator](#readeriterator11)&gt; | 是 | 回调函数，返回文件读取迭代器。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { Options } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let options: Options = {
    encoding: 'utf-8'
  };
  fileIo.readLines(filePath, options, (err: BusinessError, readerIterator: fileIo.ReaderIterator) => {
    if (err) {
      console.error(`Failed to read lines. Code: ${err.code}, message: ${err.message}`);
    } else {
      for (let it = readerIterator.next(); !it.done; it = readerIterator.next()) {
        console.info(`Succeeded in reading lines, content: ${it.value}`);
      }
    }
  });
  ```

## fileIo.readLinesSync<sup>11+</sup>

readLinesSync(filePath: string, options?: Options): ReaderIterator

以同步方式逐行读取文件的文本内容，只支持读取utf-8格式文件。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| filePath | string | 是 | 文件的应用沙箱路径。 |
| options | [Options](#options11) | 否 | 可选项。支持以下选项：<br/>-&nbsp;encoding，string类型，当数据是&nbsp;string&nbsp;类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'，仅支持&nbsp;'utf-8'。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [ReaderIterator](#readeriterator11) | 返回文件读取迭代器。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { Options } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let options: Options = {
    encoding: 'utf-8'
  };
  let readerIterator = fileIo.readLinesSync(filePath, options);
  for (let it = readerIterator.next(); !it.done; it = readerIterator.next()) {
    console.info(`Succeeded in reading lines, content: ${it.value}`);
  }
  ```

## ReaderIterator<sup>11+</sup>

文件读取迭代器。在调用ReaderIterator的方法前，需要先通过readLines方法（同步或异步）来构建一个ReaderIterator实例。

### next<sup>11+</sup>

next(): ReaderIteratorResult

获取迭代器下一项内容。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [ReaderIteratorResult](#readeriteratorresult11) | 文件读取迭代器返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

> **说明**：
>
> 如果ReaderIterator读取的当前行的编码方式不是'utf-8'，接口返回错误码13900037。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { Options } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let options: Options = {
    encoding: 'utf-8'
  };
  fileIo.readLines(filePath, options).then((readerIterator: fileIo.ReaderIterator) => {
    for (let it = readerIterator.next(); !it.done; it = readerIterator.next()) {
      console.info(`Succeeded in reading lines, content: ${it.value}`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to read lines. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## ReaderIteratorResult<sup>11+</sup>

文件读取迭代器返回结果，支持ReaderIterator接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 说明 |
| ---- | ---- | ---- |
| done | boolean | 迭代器是否已完成迭代。true：已完成迭代；false：未完成迭代。 |
| value | string | 逐行读取的文件文本内容。 |

## fileIo.readText

readText(filePath: string, options?: ReadTextOptions): Promise&lt;string&gt;

基于文本方式读取文件（即直接读取文件的文本内容）。使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| filePath | string | 是 | 文件的应用沙箱路径。 |
| options | [ReadTextOptions](#readtextoptions11) | 否 | 支持如下选项：<br/>-&nbsp;offset，number类型，表示期望读取文件的位置，单位为Byte。可选，默认从当前位置开始读取。<br/>-&nbsp;length，number类型，表示期望读取数据的长度，单位为Byte。可选，默认文件长度。<br/>-&nbsp;encoding，string类型，当数据是&nbsp;string&nbsp;类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'，仅支持&nbsp;'utf-8'。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;string&gt; | Promise对象，返回读取文件的内容。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.readText(filePath).then((str: string) => {
    console.info(`Succeeded in reading text, text is: ${str}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to read text. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.readText

readText(filePath: string, callback: AsyncCallback&lt;string&gt;): void

基于文本方式读取文件内容。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| filePath | string | 是 | 文件的应用沙箱路径。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数，返回读取文件的内容。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.readText(filePath, (err: BusinessError, str: string) => {
    if (err) {
      console.error(`Failed to read text. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in reading text, text is: ${str}`);
    }
  });
  ```

## fileIo.readText

readText(filePath: string, options: ReadTextOptions, callback: AsyncCallback&lt;string&gt;): void

基于文本方式读取文件内容，支持配置读取选项。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| filePath | string | 是 | 文件的应用沙箱路径。 |
| options | [ReadTextOptions](#readtextoptions11) | 是 | 支持如下选项：<br/>-&nbsp;offset，number类型，表示期望读取文件的位置，单位为Byte。可选，默认从当前位置开始读取。<br/>-&nbsp;length，number类型，表示期望读取数据的长度，单位为Byte。可选，默认文件长度。<br/>-&nbsp;encoding，string类型，表示数据的编码方式，默认&nbsp;'utf-8'，仅支持&nbsp;'utf-8'。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数，返回读取文件的内容。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { ReadTextOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let stat = fileIo.statSync(filePath);
  let readTextOption: ReadTextOptions = {
      offset: 1,
      length: stat.size,
      encoding: 'utf-8'
  };
  fileIo.readText(filePath, readTextOption, (err: BusinessError, str: string) => {
    if (err) {
      console.error(`Failed to read text. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in reading text, text is: ${str}`);
    }
  });
  ```

## fileIo.readTextSync

readTextSync(filePath: string, options?: ReadTextOptions): string

以同步方法基于文本方式读取文件（即直接读取文件的文本内容）。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| filePath | string | 是 | 文件的应用沙箱路径。 |
| options | [ReadTextOptions](#readtextoptions11) | 否 | 支持如下选项：<br/>-&nbsp;offset，number类型，表示期望读取文件的位置，单位为Byte。可选，默认从当前位置开始读取。<br/>-&nbsp;length，number类型，表示期望读取数据的长度，单位为Byte。可选，默认文件长度。<br/>-&nbsp;encoding，string类型，当数据是&nbsp;string&nbsp;类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'，仅支持&nbsp;'utf-8'。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| string | 返回读取文件的内容。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { ReadTextOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let readTextOptions: ReadTextOptions = {
    offset: 1,
    length: 0,
    encoding: 'utf-8'
  };
  let stat = fileIo.statSync(filePath);
  readTextOptions.length = stat.size;
  let str = fileIo.readTextSync(filePath, readTextOptions);
  console.info(`Succeeded in reading text, text is: ${str}`);
  ```

## fileIo.lstat

lstat(path: string): Promise&lt;Stat&gt;

获取符号链接文件信息。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件的应用沙箱路径或URI。<br>**说明**：从API version 22开始，支持传入URI。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;[Stat](#stat)&gt; | Promise对象，返回Stat对象，表示文件的具体信息，详情见Stat。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/linkToFile";
  fileIo.lstat(filePath).then((stat: fileIo.Stat) => {
    console.info(`Succeeded in getting symbolic link info, the size of file is ${stat.size}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get symbolic link info. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.lstat

lstat(path: string, callback: AsyncCallback&lt;Stat&gt;): void

获取符号链接文件信息。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件的应用沙箱路径或URI。<br>**说明**：从API version 22开始，支持传入URI。 |
| callback | AsyncCallback&lt;[Stat](#stat)&gt; | 是 | 回调函数，返回Stat对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/linkToFile";
  fileIo.lstat(filePath, (err: BusinessError, stat: fileIo.Stat) => {
    if (err) {
      console.error(`Failed to get symbolic link info. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in getting symbolic link info, the size of file is ${stat.size}`);
    }
  });
  ```

## fileIo.lstatSync

lstatSync(path: string): Stat

以同步方法获取符号链接文件信息。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件的应用沙箱路径或URI。<br>**说明**：从API version 22开始，支持传入URI。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [Stat](#stat) | 表示文件的具体信息。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/linkToFile";
  let fileStat = fileIo.lstatSync(filePath);
  console.info(`Succeeded in getting symbolic link info, the size of file is ${fileStat.size}`);
  ```

## fileIo.rename

rename(oldPath: string, newPath: string): Promise&lt;void&gt;

重命名文件或目录。使用Promise异步回调。

> **说明：**
> 
> 该接口不支持在分布式文件路径下操作。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| oldPath | string | 是 | 文件的应用沙箱原路径。 |
| newPath | string | 是 | 文件的应用沙箱新路径。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/new.txt";
  fileIo.rename(srcFile, dstFile).then(() => {
    console.info(`Succeeded in renaming.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to rename. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.rename

rename(oldPath: string, newPath: string, callback: AsyncCallback&lt;void&gt;): void

重命名文件或目录。使用callback异步回调。

> **说明：**
> 
> 该接口不支持在分布式文件路径下操作。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| oldPath | string | 是 | 文件的应用沙箱原路径。 |
| newPath | string | 是 | 文件的应用沙箱新路径。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当重命名文件成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/new.txt";
  fileIo.rename(srcFile, dstFile, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to rename. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in renaming.`);
    }
  });
  ```

## fileIo.renameSync

renameSync(oldPath: string, newPath: string): void

以同步方法重命名文件或目录。

> **说明：**
>
> 该接口不支持在分布式文件路径下操作。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| oldPath | string | 是 | 文件的应用沙箱原路径。 |
| newPath | string | 是 | 文件的应用沙箱新路径。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/new.txt";
  fileIo.renameSync(srcFile, dstFile);
  ```

## fileIo.fsync

fsync(fd: number): Promise&lt;void&gt;

将文件系统缓存数据写入磁盘。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 已打开的文件描述符。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.fsync(file.fd).then(() => {
    console.info(`Succeeded in syncing data.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to sync data. Code: ${err.code}, message: ${err.message}`);
  }).finally(() => {
    fileIo.closeSync(file);
  });
  ```

## fileIo.fsync

fsync(fd: number, callback: AsyncCallback&lt;void&gt;): void

将文件系统缓存数据写入磁盘。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 已打开的文件描述符。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当文件系统缓存数据写入磁盘成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.fsync(file.fd, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to sync. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in syncing.`);
    }
    fileIo.closeSync(file);
  });
  ```


## fileIo.fsyncSync

fsyncSync(fd: number): void

以同步方法将文件系统缓存数据写入磁盘。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 已打开的文件描述符。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.fsyncSync(file.fd);
  fileIo.closeSync(file);
  ```

## fileIo.fdatasync

fdatasync(fd: number): Promise&lt;void&gt;

实现文件内容数据同步。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 已打开的文件描述符。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.fdatasync(file.fd).then(() => {
    console.info(`Succeeded in syncing data.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to sync data. Code: ${err.code}, message: ${err.message}`);
  }).finally(() => {
    fileIo.closeSync(file);
  });
  ```

## fileIo.fdatasync

fdatasync(fd: number, callback: AsyncCallback&lt;void&gt;): void

实现文件内容数据同步。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 已打开的文件描述符。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当文件内容数据同步成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.fdatasync(file.fd, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to sync data. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in syncing data.`);
    }
    fileIo.closeSync(file);
  });
  ```

## fileIo.fdatasyncSync

fdatasyncSync(fd: number): void

以同步方法实现文件内容的数据同步。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 已打开的文件描述符。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.fdatasyncSync(file.fd);
  fileIo.closeSync(file);
  ```

## fileIo.symlink

symlink(target: string, srcPath: string): Promise&lt;void&gt;

基于文件路径创建符号链接。使用Promise异步回调。

> **说明：**
>
> 从API version 11开始，不支持三方应用使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| target | string | 是 | 要链接的目标文件的应用沙箱路径。 |
| srcPath | string | 是 | 符号链接文件的应用沙箱路径。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/test";
  fileIo.symlink(srcFile, dstFile).then(() => {
    console.info(`Succeeded in creating symbolic link.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create symbolic link. Code: ${err.code}, message: ${err.message}`);
  });
  ```


## fileIo.symlink
symlink(target: string, srcPath: string, callback: AsyncCallback&lt;void&gt;): void

基于文件路径创建符号链接。使用callback异步回调。

> **说明：**
>
> 从API version 11开始，不支持三方应用使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| target | string | 是 | 要链接的目标文件的应用沙箱路径。 |
| srcPath | string | 是 | 符号链接文件的应用沙箱路径。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当创建符号链接成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/test";
  fileIo.symlink(srcFile, dstFile, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to create symbolic link. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in creating symbolic link.`);
    }
  });
  ```

## fileIo.symlinkSync

symlinkSync(target: string, srcPath: string): void

以同步的方法基于文件路径创建符号链接。

> **说明：**
>
> 从API version 11开始，不支持三方应用使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| target | string | 是 | 要链接的目标文件的应用沙箱路径。 |
| srcPath | string | 是 | 符号链接文件的应用沙箱路径。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + "/test";
  fileIo.symlinkSync(srcFile, dstFile);
  ```

## fileIo.listFile
listFile(path: string, options?: ListFileOptions): Promise<string[]>

默认列出当前目录下所有文件名和目录名。支持过滤。使用promise异步回调。

可通过配置ListFileOptions中recursion参数实现递归列出所有文件的相对路径，相对路径以“/”开头。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 目录的应用沙箱路径。 |
| options | [ListFileOptions](#listfileoptions11) | 否 | 文件过滤选项。默认不进行过滤。 |


**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;string[]&gt; | Promise对象，返回文件名数组，默认以'utf-8'编码。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { Filter, ListFileOptions } from '@kit.CoreFileKit';

  let listFileOption: ListFileOptions = {
    recursion: false,
    listNum: 0,
    filter: {
      suffix: [".png", ".jpg", ".jpeg"],
      displayName: ["*abc", "efg*"],
      fileSizeOver: 1024
    }
  }
  fileIo.listFile(pathDir, listFileOption).then((filenames: Array<string>) => {
    console.info(`Succeeded in listing file.`);
    for (let i = 0; i < filenames.length; i++) {
      console.info(`Succeeded in listing file, file name: ${filenames[i]}`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to list file. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.listFile
listFile(path: string, callback: AsyncCallback<string[]>): void

默认列出当前目录下所有文件名和目录名。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 目录的应用沙箱路径。 |
| callback | AsyncCallback&lt;string[]&gt; | 是 | 回调函数，返回文件名数组，默认以'utf-8'编码。 |


**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  fileIo.listFile(pathDir, (err: BusinessError, filenames: Array<string>) => {
    if (err) {
      console.error(`Failed to list file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in listing file.`);
      for (let i = 0; i < filenames.length; i++) {
        console.info(`Succeeded in listing file, file name: ${filenames[i]}`);
      }
    }
  });
  ```

## fileIo.listFile
listFile(path: string, options: ListFileOptions, callback: AsyncCallback&lt;string[]&gt;): void

默认列出当前目录下所有文件名和目录名。支持过滤。使用callback异步回调。

可通过配置ListFileOptions中recursion参数实现递归列出所有文件的相对路径，相对路径以“/”开头。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 目录的应用沙箱路径。 |
| options | [ListFileOptions](#listfileoptions11) | 是 | 文件过滤选项。 |
| callback | AsyncCallback&lt;string[]&gt; | 是 | 回调函数，返回文件名数组，默认以'utf-8'编码。 |


**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { Filter, ListFileOptions } from '@kit.CoreFileKit';

  let listFileOption: ListFileOptions = {
    recursion: false,
    listNum: 0,
    filter: {
      suffix: [".png", ".jpg", ".jpeg"],
      displayName: ["*abc", "efg*"],
      fileSizeOver: 1024
    }
  };
  fileIo.listFile(pathDir, listFileOption, (err: BusinessError, filenames: Array<string>) => {
    if (err) {
      console.error(`Failed to list file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in listing file.`);
      for (let i = 0; i < filenames.length; i++) {
        console.info(`Succeeded in listing file, file name: ${filenames[i]}`);
      }
    }
  });
  ```

## fileIo.listFileSync

listFileSync(path: string, options?: ListFileOptions): string[]

默认以同步方式列出当前目录下所有文件名和目录名。支持过滤。

可通过配置ListFileOptions中recursion参数实现递归列出所有文件的相对路径，相对路径以“/”开头。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 目录的应用沙箱路径。 |
| options | [ListFileOptions](#listfileoptions11) | 否 | 文件过滤选项。默认不进行过滤。 |


**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| string[] | 返回文件名数组，默认以'utf-8'编码。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { Filter, ListFileOptions} from '@kit.CoreFileKit';

  let listFileOption: ListFileOptions = {
    recursion: false,
    listNum: 0,
    filter: {
      suffix: [".png", ".jpg", ".jpeg"],
      displayName: ["*abc", "efg*"],
      fileSizeOver: 1024
    }
  };
  let filenames = fileIo.listFileSync(pathDir, listFileOption);
  console.info(`Succeeded in listing file.`);
  for (let i = 0; i < filenames.length; i++) {
    console.info(`Succeeded in listing file, file name: ${filenames[i]}`);
  }
  ```

## fileIo.listFileExt

listFileExt(path: string, options?: ListFileExtOptions): Promise&lt;string[]&gt;

列出目录下所有文件名，支持递归列出和自定义文件名过滤。使用Promise异步回调。

可通过配置options中recursion参数实现递归列出所有文件的相对路径，相对路径以“/”开头。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 目录的应用沙箱路径。 |
| options | [ListFileExtOptions](#listfileextoptions) | 否 | 文件列出选项。默认为空，表示不递归、不限制列出数量、不进行过滤。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;string[]&gt; | Promise对象，返回文件名数组。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

| 错误码ID | 错误信息 |
| ---- | ---- |
| 13900002 | No such file or directory. |
| 13900011 | Out of memory. |
| 13900018 | Not a directory. |
| 13900020 | Invalid argument. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo, ListFileExtOptions, FileFilter } from '@kit.CoreFileKit';

let filter: FileFilter = {
  filter: (name: string): boolean => {
    return name.endsWith('.txt');
  }
};
let options: ListFileExtOptions = {
  recursion: false,
  listNum: 0,
  fileFilter: filter
};
fileIo.listFileExt(pathDir, options).then((filenames: Array<string>) => {
  console.info(`Succeeded in listing file.`);
  for (let i = 0; i < filenames.length; i++) {
    console.info(`Succeeded in listing file, file name: ${filenames[i]}`);
  }
}).catch((error: Error) => {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to list file. Code: ${err.code}, message: ${err.message}`);
});
```

## fileIo.listFileExtSync

listFileExtSync(path: string, options?: ListFileExtOptions): string[]

以同步方式列出目录下所有文件名，支持递归列出和自定义文件名过滤。

可通过配置options中recursion参数实现递归列出所有文件的相对路径，相对路径以“/”开头。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 目录的应用沙箱路径。 |
| options | [ListFileExtOptions](#listfileextoptions) | 否 | 文件列出选项。默认为空，表示不递归、不限制列出数量、不进行过滤。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| string[] | 返回文件名数组。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

| 错误码ID | 错误信息 |
| ---- | ---- |
| 13900002 | No such file or directory. |
| 13900011 | Out of memory. |
| 13900018 | Not a directory. |
| 13900020 | Invalid argument. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo, ListFileExtOptions, FileFilter } from '@kit.CoreFileKit';

let filter: FileFilter = {
  filter: (name: string): boolean => {
    return name.endsWith('.txt');
  }
};
let options: ListFileExtOptions = {
  recursion: false,
  listNum: 0,
  fileFilter: filter
};
try {
  let filenames = fileIo.listFileExtSync(pathDir, options);
  console.info(`Succeeded in listing file.`);
  for (let i = 0; i < filenames.length; i++) {
    console.info(`Succeeded in listing file, file name: ${filenames[i]}`);
  }
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to list file. Code: ${err.code}, message: ${err.message}`);
}
```

## fileIo.lseek<sup>11+</sup>

lseek(fd: number, offset: number, whence?: WhenceType): number

调整文件偏移指针位置。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 文件描述符。 |
| offset | number | 是 | 相对偏移位置，单位为Byte。 |
| whence | [WhenceType](#whencetype11) | 否 | 偏移指针相对位置类型。不指定则默认为文件起始位置处。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| number | 当前文件偏移指针位置（相对于文件头的偏移量，单位为Byte）。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  let offset = fileIo.lseek(file.fd, 5, fileIo.WhenceType.SEEK_SET);
  console.info(`Succeeded in seeking, the current offset is at ${offset}`);
  fileIo.closeSync(file);
  ```

## fileIo.moveDir<sup>10+</sup>

moveDir(src: string, dest: string, mode?: number): Promise\<void>

移动源目录至目标路径下。使用Promise异步回调。

> **说明：**
>
> 该接口不支持在分布式文件路径下操作。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string | 是 | 源目录的应用沙箱路径。 |
| dest | string | 是 | 目标目录的应用沙箱路径。 |
| mode | number | 否 | 移动模式，默认值为0。<br/>-&nbsp;mode为0，目录级别抛异常。若目标目录下存在与源目录名冲突的非空目录，则抛出异常。<br/>-&nbsp;mode为1，文件级别抛异常。目标目录下存在与源目录名冲突的目录，若冲突目录下存在同名文件，则抛出异常。源目录下未冲突的文件全部移动至目标目录下，目标目录下未冲突文件将继续保留，且冲突文件信息将在抛出异常的data属性中以Array\<[ConflictFiles](#conflictfiles10)>形式提供。<br/>-&nbsp; mode为2，文件级别强制覆盖。目标目录下存在与源目录名冲突的目录，若冲突目录下存在同名文件，则强制覆盖冲突目录下所有同名文件，未冲突文件将继续保留。<br/>-&nbsp; mode为3，目录级别强制覆盖。移动源目录至目标目录下，目标目录下移动的目录内容与源目录完全一致。若目标目录下存在与源目录名冲突的目录，该目录下的所有原始文件将被删除。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcPath = pathDir + "/srcDir";
  let destPath = pathDir + "/destDir";
  fileIo.moveDir(srcPath, destPath, 1).then(() => {
    console.info(`Succeeded in moving directory.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to move directory. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.moveDir<sup>10+</sup>

moveDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void

移动源目录至目标路径下，支持设置移动模式。使用callback异步回调。

> **说明：**
>
> 该接口不支持在分布式文件路径下操作。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string | 是 | 源目录的应用沙箱路径。 |
| dest | string | 是 | 目标目录的应用沙箱路径。 |
| mode | number | 是 | 移动模式。<br/>-&nbsp;mode为0，目录级别抛异常。若目标目录下存在与源目录名冲突的目录，则抛出异常。<br/>-&nbsp;mode为1，文件级别抛异常。目标目录下存在与源目录名冲突的目录，若冲突目录下存在同名文件，则抛出异常。源目录下未冲突的文件全部移动至目标目录下，目标目录下未冲突文件将继续保留。<br/>-&nbsp; mode为2，文件级别强制覆盖。目标目录下存在与源目录名冲突的目录，若冲突目录下存在同名文件，则强制覆盖冲突目录下所有同名文件，未冲突文件将继续保留。<br/>-&nbsp; mode为3，目录级别强制覆盖。移动源目录至目标目录下，目标目录下移动的目录内容与源目录完全一致。若目标目录下存在与源目录名冲突的目录，该目录下所有原始文件将被删除。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当移动目录成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let srcPath = pathDir + "/srcDir";
let destPath = pathDir + "/destDir";
fileIo.moveDir(srcPath, destPath, 1, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to move directory. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in moving directory.`);
  }
});
```

## fileIo.moveDir<sup>10+</sup>

moveDir(src: string, dest: string, mode: number, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void

移动源目录至目标路径下，支持设置移动模式。使用callback异步回调。

> **说明：**
>
> 该接口不支持在分布式文件路径下操作。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string | 是 | 源目录的应用沙箱路径。 |
| dest | string | 是 | 目标目录的应用沙箱路径。 |
| mode | number | 是 | 移动模式。<br/>-&nbsp;mode为0，目录级别抛异常。若目标目录下存在与源目录名冲突的目录，则抛出异常。<br/>-&nbsp;mode为1，文件级别抛异常。目标目录下存在与源目录名冲突的目录，若冲突目录下存在同名文件，则抛出异常。源目录下未冲突的文件全部移动至目标目录下，目标目录下未冲突文件将继续保留，且冲突文件信息将在抛出异常的data属性中以Array\<[ConflictFiles](#conflictfiles10)>形式提供。<br/>-&nbsp; mode为2，文件级别强制覆盖。目标目录下存在与源目录名冲突的目录，若冲突目录下存在同名文件，则强制覆盖冲突目录下所有同名文件，未冲突文件将继续保留。<br/>-&nbsp; mode为3，目录级别强制覆盖。移动源目录至目标目录下，目标目录下移动的目录内容与源目录完全一致。若目标目录下存在与源目录名冲突的目录，该目录下所有原始文件将被删除。 |
| callback | AsyncCallback&lt;void, Array&lt;[ConflictFiles](#conflictfiles10)&gt;&gt; | 是 | 回调函数。当移动目录成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { ConflictFiles } from '@kit.CoreFileKit';

  let srcPath = pathDir + "/srcDir";
  let destPath = pathDir + "/destDir";
  fileIo.moveDir(srcPath, destPath, 1, (err: BusinessError<Array<ConflictFiles>>) => {
    if (err && err.code == 13900015 && err.data?.length !== undefined) {
      for (let i = 0; i < err.data.length; i++) {
        console.error(`Failed to move directory, with conflicting files: ${err.data[i].srcFile} ${err.data[i].destFile}`);
      }
    } else if (err) {
      console.error(`Failed to move directory. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in moving directory.`);
    }
  });
  ```

## fileIo.moveDir<sup>10+</sup>

moveDir(src: string, dest: string, callback: AsyncCallback\<void>): void

移动源目录至目标路径下。使用callback异步回调。

移动模式为目录级别抛异常。当目标目录下存在与源目录名冲突的目录，则抛出异常。

> **说明：**
>
> 该接口不支持在分布式文件路径下操作。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string | 是 | 源目录的应用沙箱路径。 |
| dest | string | 是 | 目标目录的应用沙箱路径。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当移动目录成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let srcPath = pathDir + "/srcDir";
let destPath = pathDir + "/destDir";
fileIo.moveDir(srcPath, destPath, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to move directory. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Succeeded in moving directory.`);
  }
});
```

## fileIo.moveDir<sup>10+</sup>

moveDir(src: string, dest: string, callback: AsyncCallback\<void, Array\<ConflictFiles>>): void

移动源目录至目标路径下。使用callback异步回调。

移动模式为目录级别抛异常。当目标目录下存在与源目录名冲突的目录，则抛出异常。

> **说明：**
>
> 该接口不支持在分布式文件路径下操作。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string | 是 | 源目录的应用沙箱路径。 |
| dest | string | 是 | 目标目录的应用沙箱路径。 |
| callback | AsyncCallback&lt;void, Array&lt;[ConflictFiles](#conflictfiles10)&gt;&gt; | 是 | 回调函数。当移动目录成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { ConflictFiles } from '@kit.CoreFileKit';

  let srcPath = pathDir + "/srcDir";
  let destPath = pathDir + "/destDir";
  fileIo.moveDir(srcPath, destPath, (err: BusinessError<Array<ConflictFiles>>) => {
    if (err && err.code == 13900015 && err.data?.length !== undefined) {
      for (let i = 0; i < err.data.length; i++) {
        console.error(`Failed to move directory, with conflicting files: ${err.data[i].srcFile} ${err.data[i].destFile}`);
      }
    } else if (err) {
      console.error(`Failed to move directory. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in moving directory.`);
    }
  });
  ```

## fileIo.moveDirSync<sup>10+</sup>

moveDirSync(src: string, dest: string, mode?: number): void

以同步方法移动源目录至目标路径下。

> **说明：**
>
> 该接口不支持在分布式文件路径下操作。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string | 是 | 源目录的应用沙箱路径。 |
| dest | string | 是 | 目标目录的应用沙箱路径。 |
| mode | number | 否 | 移动模式，默认值为0。<br/>-&nbsp;mode为0，目录级别抛异常。若目标目录下存在与源目录名冲突的目录，则抛出异常。<br/>-&nbsp;mode为1，文件级别抛异常。目标目录下存在与源目录名冲突的目录，若冲突目录下存在同名文件，则抛出异常。源目录下未冲突的文件全部移动至目标目录下，目标目录下未冲突文件将继续保留，且冲突文件信息将在抛出异常的data属性中以Array\<[ConflictFiles](#conflictfiles10)>形式提供。<br/>-&nbsp; mode为2，文件级别强制覆盖。目标目录下存在与源目录名冲突的目录，若冲突目录下存在同名文件，则强制覆盖冲突目录下所有同名文件，未冲突文件将继续保留。<br/>-&nbsp; mode为3，目录级别强制覆盖。移动源目录至目标目录下，目标目录下移动的目录内容与源目录完全一致。若目标目录下存在与源目录名冲突的目录，该目录下所有原始文件将被删除。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { ConflictFiles } from '@kit.CoreFileKit';

let srcPath = pathDir + "/srcDir";
let destPath = pathDir + "/destDir";
try {
  fileIo.moveDirSync(srcPath, destPath, 1);
  console.info(`Succeeded in moving directory.`);
} catch (error) {
  let err: BusinessError<Array<ConflictFiles>> = error as BusinessError<Array<ConflictFiles>>;
  if (err.code == 13900015 && err.data?.length !== undefined) {
    for (let i = 0; i < err.data.length; i++) {
      console.error(`Failed to move directory, with conflicting files: ${err.data[i].srcFile} ${err.data[i].destFile}`);
    }
  } else {
    console.error(`Failed to move directory. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## fileIo.moveFile

moveFile(src: string, dest: string, mode?: number): Promise\<void>

移动文件。使用Promise异步回调。

> **说明：**
>
> 该接口不支持在分布式文件路径下操作。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string | 是 | 源文件的应用沙箱路径。 |
| dest | string | 是 | 目标文件的应用沙箱路径。 |
| mode | number | 否 | 移动模式。若mode为0，移动位置存在同名文件时，强制移动覆盖。若mode为1，移动位置存在同名文件时，抛出异常。默认为0。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcPath = pathDir + "/source.txt";
  let destPath = pathDir + "/dest.txt";
  fileIo.moveFile(srcPath, destPath, 0).then(() => {
    console.info(`Succeeded in moving file.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to move file. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.moveFile

moveFile(src: string, dest: string, mode: number, callback: AsyncCallback\<void>): void

移动文件，支持设置移动模式。使用callback异步回调。

> **说明：**
>
> 该接口不支持在分布式文件路径下操作。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string | 是 | 源文件的应用沙箱路径。 |
| dest | string | 是 | 目标文件的应用沙箱路径。 |
| mode | number | 是 | 移动模式。若mode为0，移动位置存在同名文件时，强制移动覆盖。若mode为1，移动位置存在同名文件时，抛出异常。默认为0。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当移动文件成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcPath = pathDir + "/source.txt";
  let destPath = pathDir + "/dest.txt";
  fileIo.moveFile(srcPath, destPath, 0, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to move file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in moving file.`);
    }
  });
  ```

## fileIo.moveFile

moveFile(src: string, dest: string, callback: AsyncCallback\<void>): void

移动文件。如果移动位置存在同名文件，将强制覆盖。使用callback异步回调。

> **说明：**
>
> 该接口不支持在分布式文件路径下操作。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string | 是 | 源文件的应用沙箱路径。 |
| dest | string | 是 | 目标文件的应用沙箱路径。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当移动文件成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let srcPath = pathDir + "/source.txt";
  let destPath = pathDir + "/dest.txt";
  fileIo.moveFile(srcPath, destPath, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to move file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in moving file.`);
    }
  });
  ```

## fileIo.moveFileSync

moveFileSync(src: string, dest: string, mode?: number): void

以同步方式移动文件。

> **说明：**
>
> 该接口不支持在分布式文件路径下操作。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| src | string | 是 | 源文件的应用沙箱路径。 |
| dest | string | 是 | 目标文件的应用沙箱路径。 |
| mode | number | 否 | 移动模式。若mode为0，移动位置存在同名文件时，强制移动覆盖。若mode为1，移动位置存在同名文件时，抛出异常。默认为0。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let srcPath = pathDir + "/source.txt";
  let destPath = pathDir + "/dest.txt";
  fileIo.moveFileSync(srcPath, destPath, 0);
  console.info(`Succeeded in moving file.`);
  ```

## fileIo.mkdtemp

mkdtemp(prefix: string): Promise&lt;string&gt;

创建临时目录。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| prefix | string | 是 | 指定目录路径，命名时需要以"XXXXXX"作为结尾。路径末尾的"XXXXXX"字符串将被替换为随机字符，以创建唯一的目录名。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;string&gt; | Promise对象，返回生成的唯一目录路径。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  fileIo.mkdtemp(pathDir + "/XXXXXX").then((dir: string) => {
    console.info(`Succeeded in making temporary directory.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to make temporary directory. Code: ${err.code}, message: ${err.message}`);
  });
  ```

## fileIo.mkdtemp

mkdtemp(prefix: string, callback: AsyncCallback&lt;string&gt;): void

创建临时目录。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| prefix | string | 是 | 指定目录路径，命名时需要以"XXXXXX"作为结尾。路径末尾的"XXXXXX"字符串将被替换为随机字符，以创建唯一的目录名。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数，返回临时目录路径。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  fileIo.mkdtemp(pathDir + "/XXXXXX", (err: BusinessError, res: string) => {
    if (err) {
      console.error(`Failed to make temporary directory. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in making temporary directory.`);
    }
  });
  ```

## fileIo.mkdtempSync

mkdtempSync(prefix: string): string

以同步的方法创建临时目录。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| prefix | string | 是 | 指定目录路径，命名时需要以"XXXXXX"作为结尾。路径末尾的"XXXXXX"字符串将被替换为随机字符，以创建唯一的目录名。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| string | 产生的唯一目录路径。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let res = fileIo.mkdtempSync(pathDir + "/XXXXXX");
  ```

## fileIo.mmap

mmap(file: number | File, mode: MappingMode, offset: number, size: number): Promise&lt;FileMapping&gt;

基于文件描述符或文件对象创建文件映射对象，实现文件的高效读写访问。使用Promise异步回调。

> **说明：**
>
> 1. 仅支持对常规文件（regular file）进行内存映射，不支持管道、socket、设备文件等非常规文件类型。可通过[statSync](#fileiostatsync)获取文件属性后调用[Stat.isFile()](#isfile)判断文件是否为常规文件。
> 2. 若映射范围超过原始文件大小且文件具有写权限，将自动扩展映射文件大小。
> 3. 对于外部存储或网络文件等，由于底层文件系统的差异，映射的建立及对映射内存的访问行为不做保证，可能导致应用异常终止。建议此类场景优先使用[read](#fileioread)、[write](#fileiowrite)或[Stream](#stream)等其他文件访问接口。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| file | number \| [File](#file) | 是 | 已打开的File对象或已打开的文件描述符fd。 |
| mode | [MappingMode](#mappingmode) | 是 | 创建文件内存映射对象的选项，必须指定如下选项中的一个：<br/>- MappingMode.READ_ONLY(0)：只读映射模式。文件映射区不可写，修改会抛出异常。<br/>- MappingMode.READ_WRITE(1)：读写映射模式。修改会写入文件映射区，后续由操作系统同步到文件（非实时）。<br/>- MappingMode.PRIVATE(2)：私有映射模式。是一种写时复制的映射机制，对映射区的修改仅对当前进程可见，不会影响原始文件。 |
| offset | number | 是 | 文件映射区的起始位置，单位为Byte。 |
| size | number | 是 | 文件映射区的大小，取值范围(0, INT32_MAX]，单位为Byte。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;[FileMapping](#filemapping)&gt; | Promise对象，返回文件映射对象。返回的对象初始状态：position为0，limit和capacity均等于size。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
fileIo.mmap(file, fileIo.MappingMode.READ_WRITE, 0, 1024).then((mapping: fileIo.FileMapping) => {
  console.info(`Succeeded in mmap`);
  mapping.unmapSync();
}).catch((err: BusinessError) => {
  console.error(`Failed to mmap. Code: ${err.code}, message: ${err.message}`);
}).finally(() => {
  fileIo.closeSync(file);
});
```

## fileIo.mmapSync

mmapSync(file: number | File, mode: MappingMode, offset: number, size: number): FileMapping

以同步方法基于文件描述符或文件对象创建文件映射对象，实现文件的高效读写访问。

> **说明：**
>
> 1. 仅支持对常规文件（regular file）进行内存映射，不支持管道、socket、设备文件等非常规文件类型。可通过[statSync](#fileiostatsync)获取文件属性后调用[Stat.isFile()](#isfile)判断文件是否为常规文件。
> 2. 若映射范围超过原始文件大小且文件具有写权限，将自动扩展映射文件大小。
> 3. 对于外部存储或网络文件等，由于底层文件系统的差异，映射的建立及对映射内存的访问行为不做保证，可能导致应用异常终止。建议此类场景优先使用[read](#fileioread)、[write](#fileiowrite)或[Stream](#stream)等其他文件访问接口。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| file | number \| [File](#file) | 是 | 已打开的File对象或已打开的文件描述符fd。 |
| mode | [MappingMode](#mappingmode) | 是 | 创建文件内存映射对象的选项，必须指定如下选项中的一个：<br/>- MappingMode.READ_ONLY(0)：只读映射模式。文件映射区不可写，修改会抛出异常。<br/>- MappingMode.READ_WRITE(1)：读写映射模式。修改会写入文件映射区，后续由操作系统同步到文件（非实时）。<br/>- MappingMode.PRIVATE(2)：私有映射模式。是一种写时复制的映射机制，对映射区的修改仅对当前进程可见，不会影响原始文件。 |
| offset | number | 是 | 文件映射区的起始位置，单位为Byte。 |
| size | number | 是 | 文件映射区的大小，取值范围(0, INT32_MAX]，单位为Byte。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [FileMapping](#filemapping) | 创建的文件映射对象。返回的对象初始状态：position为0，limit和capacity均等于size。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);
console.info("Succeeded in mmapSync.");
mapping.unmapSync();
fileIo.closeSync(file);
```

## fileIo.utimes<sup>11+</sup>

utimes(path: string, mtime: number): void

更改文件的上次修改时间。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件的应用沙箱路径。 |
| mtime | number | 是 | 待更新的时间戳。自1970年1月1日起至目标时间的毫秒数。仅支持更改上次修改该文件的时间属性。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  fileIo.writeSync(file.fd, 'test data');
  fileIo.closeSync(file);
  fileIo.utimes(filePath, new Date().getTime());
  ```

## fileIo.createRandomAccessFile<sup>10+</sup>

createRandomAccessFile(file: string | File, callback: AsyncCallback&lt;RandomAccessFile&gt;): void

基于文件路径或文件对象，以只读方式创建RandomAccessFile对象。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| file | string \| [File](#file) | 是 | 文件的应用沙箱路径或已打开的File对象。 |
| callback | AsyncCallback&lt;[RandomAccessFile](#randomaccessfile10)&gt; | 是 | 回调函数，返回RandomAccessFile对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  fileIo.createRandomAccessFile(file, (err: BusinessError, randomAccessFile: fileIo.RandomAccessFile) => {
    if (err) {
      console.error(`Failed to create randomaccessfile. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in creating randomaccessfile, fd: ${randomAccessFile.fd}`);
      randomAccessFile.close();
    }
    fileIo.closeSync(file);
  });
  ```

## fileIo.createRandomAccessFile<sup>10+</sup>

createRandomAccessFile(file: string | File, mode: number, callback: AsyncCallback&lt;RandomAccessFile&gt;): void

基于文件路径或文件对象创建RandomAccessFile对象。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| file | string \| [File](#file) | 是 | 文件的应用沙箱路径或已打开的File对象。 |
| mode | number | 是 | 创建文件RandomAccessFile对象的[OpenMode](#openmode)，仅当传入文件沙箱路径时生效，必须指定如下选项中的一个，默认以只读方式创建：<br/>-&nbsp;OpenMode.READ_ONLY(0o0)：只读创建。<br/>-&nbsp;OpenMode.WRITE_ONLY(0o1)：只写创建。<br/>-&nbsp;OpenMode.READ_WRITE(0o2)：读写创建。<br/>给定如下功能选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-&nbsp;OpenMode.CREATE(0o100)：若文件不存在，则创建文件。<br/>-&nbsp;OpenMode.TRUNC(0o1000)：如果RandomAccessFile对象存在且对应文件具有写权限，则将其长度裁剪为零。<br/>-&nbsp;OpenMode.APPEND(0o2000)：以追加方式打开，后续写将追加到RandomAccessFile对象末尾。<br/>-&nbsp;OpenMode.NONBLOCK(0o4000)：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续&nbsp;IO&nbsp;进行非阻塞操作。<br/>-&nbsp;OpenMode.DIR(0o200000)：如果path不指向目录，则出错。不允许附加写权限。<br/>-&nbsp;OpenMode.NOFOLLOW(0o400000)：如果path指向符号链接，则出错。<br/>-&nbsp;OpenMode.SYNC(0o4010000)：以同步IO的方式创建RandomAccessFile对象。 |
| callback | AsyncCallback&lt;[RandomAccessFile](#randomaccessfile10)&gt; | 是 | 回调函数，返回RandomAccessFile对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  fileIo.createRandomAccessFile(file, fileIo.OpenMode.READ_ONLY, (err: BusinessError, randomAccessFile: fileIo.RandomAccessFile) => {
    if (err) {
      console.error(`Failed to create randomaccessfile. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in creating randomaccessfile, fd: ${randomAccessFile.fd}`);
      randomAccessFile.close();
    }
    fileIo.closeSync(file);
  });
  ```

## fileIo.createRandomAccessFile<sup>10+</sup>

createRandomAccessFile(file: string | File, mode?: number, options?: RandomAccessFileOptions): Promise&lt;RandomAccessFile&gt;

基于文件路径或文件对象创建RandomAccessFile对象。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| file | string \| [File](#file) | 是 | 文件的应用沙箱路径或已打开的File对象。 |
| mode | number | 否 | 创建文件RandomAccessFile对象的[OpenMode](#openmode)，仅当传入文件沙箱路径时生效，必须指定如下选项中的一个，默认以只读方式创建：<br/>-&nbsp;OpenMode.READ_ONLY(0o0)：只读创建。<br/>-&nbsp;OpenMode.WRITE_ONLY(0o1)：只写创建。<br/>-&nbsp;OpenMode.READ_WRITE(0o2)：读写创建。<br/>给定如下功能选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-&nbsp;OpenMode.CREATE(0o100)：若文件不存在，则创建文件。<br/>-&nbsp;OpenMode.TRUNC(0o1000)：如果RandomAccessFile对象存在且对应文件具有写权限，则将其长度裁剪为零。<br/>-&nbsp;OpenMode.APPEND(0o2000)：以追加方式打开，后续写将追加到RandomAccessFile对象末尾。<br/>-&nbsp;OpenMode.NONBLOCK(0o4000)：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续&nbsp;IO&nbsp;进行非阻塞操作。<br/>-&nbsp;OpenMode.DIR(0o200000)：如果path不指向目录，则出错。不允许附加写权限。<br/>-&nbsp;OpenMode.NOFOLLOW(0o400000)：如果path指向符号链接，则出错。<br/>-&nbsp;OpenMode.SYNC(0o4010000)：以同步IO的方式创建RandomAccessFile对象。 |
|options<sup>12+</sup>|[RandomAccessFileOptions](#randomaccessfileoptions12)|否|支持如下选项：<br/>- start，number类型，表示文件的起始偏移位置，单位为Byte。可选，默认文件当前位置。<br/>- end，number类型，表示文件的结束偏移位置，单位为Byte。可选，默认文件末尾。<br/>此选项仅对[getreadstream](#getreadstream12)及[getwritestream](#getwritestream12)获取的文件流对象生效。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;[RandomAccessFile](#randomaccessfile10)&gt; | Promise对象，返回RandomAccessFile对象的结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
fileIo.createRandomAccessFile(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE, { start: 10, end: 100 })
  .then((randomAccessFile: fileIo.RandomAccessFile) => {
    console.info(`Succeeded in creating randomaccessfile, fd: ${randomAccessFile.fd}`);
    randomAccessFile.close();
  })
  .catch((err: BusinessError) => {
    console.error(`Failed to create randomaccessfile. Code: ${err.code}, message: ${err.message}`);
  });
```


## fileIo.createRandomAccessFileSync<sup>10+</sup>

createRandomAccessFileSync(file: string | File, mode?: number, options?: RandomAccessFileOptions): RandomAccessFile

基于文件路径或文件对象创建RandomAccessFile对象。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| file | string \| [File](#file) | 是 | 文件的应用沙箱路径或已打开的File对象。 |
| mode | number | 否 | 创建文件RandomAccessFile对象的[OpenMode](#openmode)，仅当传入文件沙箱路径时生效，必须指定如下选项中的一个，默认以只读方式创建：<br/>-&nbsp;OpenMode.READ_ONLY(0o0)：只读创建。<br/>-&nbsp;OpenMode.WRITE_ONLY(0o1)：只写创建。<br/>-&nbsp;OpenMode.READ_WRITE(0o2)：读写创建。<br/>给定如下功能选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-&nbsp;OpenMode.CREATE(0o100)：若文件不存在，则创建文件。<br/>-&nbsp;OpenMode.TRUNC(0o1000)：如果RandomAccessFile对象存在且对应文件具有写权限，则将其长度裁剪为零。<br/>-&nbsp;OpenMode.APPEND(0o2000)：以追加方式打开，后续写将追加到RandomAccessFile对象末尾。<br/>-&nbsp;OpenMode.NONBLOCK(0o4000)：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续&nbsp;IO&nbsp;进行非阻塞操作。<br/>-&nbsp;OpenMode.DIR(0o200000)：如果path不指向目录，则出错。不允许附加写权限。<br/>-&nbsp;OpenMode.NOFOLLOW(0o400000)：如果path指向符号链接，则出错。<br/>-&nbsp;OpenMode.SYNC(0o4010000)：以同步IO的方式创建RandomAccessFile对象。 |
|options<sup>12+</sup>|[RandomAccessFileOptions](#randomaccessfileoptions12)|否|支持如下选项：<br/>- start，number类型，表示文件的起始偏移位置，单位为Byte。可选，默认文件当前位置。<br/>- end，number类型，表示文件的结束偏移位置，单位为Byte。可选，默认文件末尾。<br/>此选项仅对[getreadstream](#getreadstream12)及[getwritestream](#getwritestream12)获取的文件流对象生效。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [RandomAccessFile](#randomaccessfile10) | 返回RandomAccessFile对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let randomAccessFile = fileIo.createRandomAccessFileSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE,
    { start: 10, end: 100 });
  randomAccessFile.close();
  ```

## fileIo.createStream

createStream(path: string, mode: string): Promise&lt;Stream&gt;

基于文件路径创建文件流。使用Promise异步回调。需要配合[Stream](#stream)中的close()函数关闭文件流。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件的应用沙箱路径。 |
| mode | string | 是 | -&nbsp;r：打开只读文件，该文件必须存在。<br/>-&nbsp;r+：打开可读写的文件，该文件必须存在。<br/>-&nbsp;w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-&nbsp;a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;[Stream](#stream)&gt; | Promise对象，返回文件流的结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.createStream(filePath, "a+").then((stream: fileIo.Stream) => {
    stream.closeSync();
    console.info(`Succeeded in creating stream.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create stream. Code: ${err.code}, message: ${err.message}`);
  });
  ```


## fileIo.createStream

createStream(path: string, mode: string, callback: AsyncCallback&lt;Stream&gt;): void

基于文件路径创建文件流，需要配合[Stream](#stream)中的close()函数关闭文件流。使用callback异步回调。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件的应用沙箱路径。 |
| mode | string | 是 | -&nbsp;r：打开只读文件，该文件必须存在。<br/>-&nbsp;r+：打开可读写的文件，该文件必须存在。<br/>-&nbsp;w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-&nbsp;a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |
| callback | AsyncCallback&lt;[Stream](#stream)&gt; | 是 | 回调函数，返回Stream对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  fileIo.createStream(filePath, "r+", (err: BusinessError, stream: fileIo.Stream) => {
    if (err) {
      console.error(`Failed to create stream. Code: ${err.code}, message: ${err.message}`);
    } else {
      stream.closeSync();
      console.info(`Succeeded in creating stream.`);
    }
  })
  ```

## fileIo.createStreamSync

createStreamSync(path: string, mode: string): Stream

以同步方法基于文件路径创建文件流。需要配合[Stream](#stream)中的close()函数关闭文件流。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件的应用沙箱路径。 |
| mode | string | 是 | -&nbsp;r：打开只读文件，该文件必须存在。<br/>-&nbsp;r+：打开可读写的文件，该文件必须存在。<br/>-&nbsp;w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-&nbsp;a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [Stream](#stream) | 返回文件流的结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  console.info(`Succeeded in creating stream.`);
  stream.closeSync();
  ```


## fileIo.fdopenStream

fdopenStream(fd: number, mode: string): Promise&lt;Stream&gt;

基于文件描述符打开文件流。使用Promise异步回调。需要配合[Stream](#stream)中的close()函数关闭文件流。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 已打开的文件描述符。 |
| mode | string | 是 | -&nbsp;r：打开只读文件，该文件必须存在。<br/>-&nbsp;r+：打开可读写的文件，该文件必须存在。<br/>-&nbsp;w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-&nbsp;a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;[Stream](#stream)&gt; | Promise对象，返回文件流的结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath);
  fileIo.fdopenStream(file.fd, "r+").then((stream: fileIo.Stream) => {
    console.info(`Succeeded in opening stream.`);
    stream.closeSync();
  }).catch((err: BusinessError) => {
    console.error(`Failed to open stream. Code: ${err.code}, message: ${err.message}`);
    // 文件流打开失败后，文件描述符需要手动关闭
    fileIo.closeSync(file);
  });
  ```

> **注意：**
>
> 使用文件描述符创建的文件流时，文件描述符的生命周期将由文件流对象管理。调用文件流的close()函数后，初始的文件描述符也会被关闭。

## fileIo.fdopenStream

fdopenStream(fd: number, mode: string, callback: AsyncCallback&lt;Stream&gt;): void

基于文件描述符打开文件流，需要配合[Stream](#stream)中的close()函数关闭文件流。使用callback异步回调。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 已打开的文件描述符。 |
| mode | string | 是 | -&nbsp;r：打开只读文件，该文件必须存在。<br/>-&nbsp;r+：打开可读写的文件，该文件必须存在。<br/>-&nbsp;w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-&nbsp;a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |
| callback | AsyncCallback&lt;[Stream](#stream)&gt; | 是 | 回调函数，返回Stream对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_ONLY);
  fileIo.fdopenStream(file.fd, "r+", (err: BusinessError, stream: fileIo.Stream) => {
    if (err) {
      console.error(`Failed to fdopen stream. Code: ${err.code}, message: ${err.message}`);
      // 文件流打开失败后，文件描述符需要手动关闭
      fileIo.closeSync(file);
    } else {
      console.info(`Succeeded in fdopening stream.`);
      stream.closeSync();
    }
  });
  ```

> **注意：**
>
> 使用文件描述符创建的文件流，文件描述符的生命周期也交由文件流对象，在调用文件流的close()函数后，初始的文件描述符也会被关闭。

## fileIo.fdopenStreamSync

fdopenStreamSync(fd: number, mode: string): Stream

以同步方法基于文件描述符打开文件流。需要配合[Stream](#stream)中的close()函数关闭文件流。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| fd | number | 是 | 已打开的文件描述符。 |
| mode | string | 是 | -&nbsp;r：打开只读文件，该文件必须存在。<br/>-&nbsp;r+：打开可读写的文件，该文件必须存在。<br/>-&nbsp;w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-&nbsp;a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [Stream](#stream) | 返回文件流的结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_ONLY | fileIo.OpenMode.CREATE);
  let stream = fileIo.fdopenStreamSync(file.fd, "r+");
  stream.closeSync();
  ```

> **注意：**
>
> 使用文件描述符创建的文件流，文件描述符的生命周期也交由文件流对象，在调用文件流的close()函数后，初始的文件描述符也会被关闭。

## fileIo.createReadStream<sup>12+</sup>

createReadStream(path: string, options?: ReadStreamOptions ): ReadStream

以同步方法打开文件可读流。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件路径。 |
| options | [ReadStreamOptions](#readstreamoptions12) | 否 | 支持如下选项：<br/>- start，number类型，表示期望读取文件的位置，单位为Byte。可选，默认从当前位置开始读。<br/>- end，number类型，表示期望读取结束的位置，单位为Byte。可选，默认文件末尾。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [ReadStream](#readstream12) | 文件可读流。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

**示例：**

  ```ts
  // 创建文件可读流
  const rs = fileIo.createReadStream(`${pathDir}/read.txt`);
  // 创建文件可写流
  const ws = fileIo.createWriteStream(`${pathDir}/write.txt`);
  // 暂停模式拷贝文件
  rs.on('readable', () => {
    const data = rs.read();
    if (!data) {
      return;
    }
    ws.write(data);
  });
  ```

## fileIo.createWriteStream<sup>12+</sup>

createWriteStream(path: string, options?: WriteStreamOptions): WriteStream

以同步方法打开文件可写流。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件路径。 |
| options | [WriteStreamOptions](#writestreamoptions12) | 否 | 支持如下选项：<br/>- start，number类型，表示期望写入文件的位置，单位为Byte。可选，默认从当前位置开始写。<br/>- mode，number 类型，创建文件可写流的[OpenMode](#openmode)，可选，默认以只写方式创建。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [WriteStream](#writestream12) | 文件可写流。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

**示例：**

  ```ts
  // 创建文件可读流
  const rs = fileIo.createReadStream(`${pathDir}/read.txt`);
  // 创建文件可写流
  const ws = fileIo.createWriteStream(`${pathDir}/write.txt`);
  // 暂停模式拷贝文件
  rs.on('readable', () => {
    const data = rs.read();
    if (!data) {
      return;
    }
    ws.write(data);
  });
  ```

## AtomicFile<sup>15+</sup>
AtomicFile是一个用于对文件进行原子读写操作的类。

在写操作时，通过写入临时文件，并在写入成功后将其重命名到原始文件位置来确保写入文件的完整性；而在写入失败时删除临时文件，不修改原始文件内容。

使用者可以自行调用finishWrite或failWrite来完成文件内容的写入或回滚。

**系统能力**：SystemCapability.FileManagement.File.FileIO

### constructor<sup>15+</sup>

constructor(path: string)

对于给定路径的文件创建一个AtomicFile类。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 文件的沙箱路径。 |

### getBaseFile<sup>15+</sup>

getBaseFile(): File

通过AtomicFile对象获取文件对象。

文件描述符fd需要由用户调用close方法关闭。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [File](#file) | 打开的File对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let atomicFile = new fileIo.AtomicFile(`${pathDir}/write.txt`);
  let writeStream = atomicFile.startWrite();
  writeStream.write("hello, world", "utf-8", ()=> {
    atomicFile.finishWrite();
    let file = atomicFile.getBaseFile();
    console.info(`Succeeded in getting base file. fd: ${file.fd}, path: ${file.path}, name:${file.name}`);
  })
} catch (err) {
  console.error(`Failed to get baseFile. Code: ${err.code}, message: ${err.message}`);
}
```

### openRead<sup>15+</sup>

openRead(): ReadStream

创建一个读文件流。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [ReadStream](#readstream12) | 文件可读流。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let file = new fileIo.AtomicFile(`${pathDir}/read.txt`);
  let writeStream = file.startWrite();
  writeStream.write("hello, world", "utf-8", ()=> {
    file.finishWrite();
    setTimeout(()=>{
      let readStream = file.openRead();
      readStream.on('readable', () => {
        const data = readStream.read();
        if (!data) {
          console.error(`Failed to read atomicfile, data is null.`);
          return;
        }
        console.info(`Succeeded in reading atomicfile, data is: ${data}`);
      });
    },1000);
  })
} catch (err) {
  console.error(`Failed to AtomicFile. Code: ${err.code}, message: ${err.message}`);
}
```

### readFully<sup>15+</sup>

readFully(): ArrayBuffer

读取文件全部内容。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| ArrayBuffer | 文件的全部内容。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { util, buffer } from '@kit.ArkTS';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let file = new fileIo.AtomicFile(`${pathDir}/read.txt`);
  let writeStream = file.startWrite();
  writeStream.write("hello, world", "utf-8", ()=> {
    file.finishWrite();
    setTimeout(()=>{
      let data = file.readFully();
      let decoder = util.TextDecoder.create('utf-8');
      let str = decoder.decodeToString(new Uint8Array(data));
      console.info(`Succeeded in reading atomicfile fully, str is: ${str}`);
    },1000);
  })
} catch (err) {
  console.error(`Failed to AtomicFile. Code: ${err.code}, message: ${err.message}`);
}
```

### startWrite<sup>15+</sup>

startWrite(): WriteStream

对文件开始新的写入操作。将返回一个WriteStream，用于在其中写入新的文件数据。

当文件不存在时新建文件。

在写入文件完成后，写入成功需要调用finishWrite()，写入失败需要调用failWrite()。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [WriteStream](#writestream12) | 文件可写流。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let file = new fileIo.AtomicFile(`${pathDir}/write.txt`);
  let writeStream = file.startWrite();
  writeStream.write("hello, world", "utf-8", ()=> {
    file.finishWrite();
    console.info(`Succeeded in writing atomicfile finished.`);
  })
} catch (err) {
  console.error(`Failed to AtomicFile. Code: ${err.code}, message: ${err.message}`);
}
```

### finishWrite<sup>15+</sup>

finishWrite(): void

在完成对startWrite返回流的写入操作时调用，表示文件写入成功。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let file = new fileIo.AtomicFile(`${pathDir}/write.txt`);
  let writeStream = file.startWrite();
  writeStream.write("hello, world", "utf-8", ()=> {
    file.finishWrite();
  })
} catch (err) {
  console.error(`Failed to AtomicFile. Code: ${err.code}, message: ${err.message}`);
}
```

### failWrite<sup>15+</sup>

failWrite(): void

文件写入失败后调用，将执行文件回滚操作。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

let file = new fileIo.AtomicFile(`${pathDir}/write.txt`);
try {
  let writeStream = file.startWrite();
  writeStream.write("hello, world", "utf-8", ()=> {
    console.info(`Succeeded in writing atomicFile.`);
  })
} catch (err) {
  file.failWrite();
  console.error(`Failed to AtomicFile. Code: ${err.code}, message: ${err.message}`);
}
```

### delete<sup>15+</sup>

delete(): void

删除AtomicFile类，会删除原始文件和临时文件。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';
import { util } from '@kit.ArkTS';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

try {
  let file = new fileIo.AtomicFile(`${pathDir}/read.txt`);
  let writeStream = file.startWrite();
  writeStream.write("hello, world", "utf-8", ()=> {
    file.finishWrite();
    setTimeout(()=>{
      let data = file.readFully();
      let decoder = util.TextDecoder.create('utf-8');
      let str = decoder.decodeToString(new Uint8Array(data));
      file.delete();
      console.info(`Succeeded in delete atomicfile.`);
    },1000);
  })
} catch (err) {
  console.error(`Failed to AtomicFile. Code: ${err.code}, message: ${err.message}`);
}
```

## fileIo.createWatcher<sup>10+</sup>

createWatcher(path: string, events: number, listener: WatchEventListener): Watcher

创建Watcher对象，监听文件或目录变动。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| path | string | 是 | 监听文件或目录的沙箱路径。 |
| events | number | 是 | 监听变动的事件集，多个事件通过或(\|)的方式进行集合。<br/>-&nbsp;0x1: IN_ACCESS， 文件被访问。<br/>-&nbsp;0x2: IN_MODIFY，文件内容被修改。<br/>-&nbsp;0x4: IN_ATTRIB，文件元数据被修改。<br/>-&nbsp;0x8: IN_CLOSE_WRITE，文件在打开时进行了写操作，然后被关闭。<br/>-&nbsp;0x10: IN_CLOSE_NOWRITE，文件或目录在打开时未进行写操作，然后被关闭。<br/>-&nbsp;0x20: IN_OPEN，文件或目录被打开。 <br/>-&nbsp;0x40: IN_MOVED_FROM，监听目录中文件被移动走。<br/>-&nbsp;0x80: IN_MOVED_TO，监听目录中文件被移动过来。<br/>-&nbsp;0x100: IN_CREATE，监听目录中文件或子目录被创建。<br/>-&nbsp;0x200: IN_DELETE，监听目录中文件或子目录被删除。<br/>-&nbsp;0x400: IN_DELETE_SELF，监听的目录被删除，删除后监听停止。<br/>-&nbsp;0x800: IN_MOVE_SELF，监听的文件或目录被移动，移动后监听继续。<br/>-&nbsp;0xfff: IN_ALL_EVENTS，监听以上所有事件。 |
| listener | [WatchEventListener](#watcheventlistener10) | 是 | 监听事件发生后的回调。监听事件每发生一次，回调一次。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [Watcher](#watcher10) | 返回Watcher对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

<!--code_no_check-->
  ```ts
  import { common } from '@kit.AbilityKit';
  import { WatchEvent } from '@kit.CoreFileKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let pathDir = context.filesDir;
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  let watcher = fileIo.createWatcher(filePath, 0x2 | 0x10, (watchEvent: WatchEvent) => {
    if (watchEvent.event == 0x2) {
      console.info(watchEvent.fileName + ' was modified');
    } else if (watchEvent.event == 0x10) {
      console.info(watchEvent.fileName + ' was closed');
    }
  });
  watcher.start();
  fileIo.writeSync(file.fd, 'test');
  fileIo.closeSync(file);
  watcher.stop();
  ```

## WatchEventListener<sup>10+</sup>

(event: WatchEvent): void

事件监听类。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| event | [WatchEvent](#watchevent10) | 是 | 回调的事件类。 |

## WatchEvent<sup>10+</sup>

事件类

### 属性

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| fileName | string | 是 | 否 | 发生监听事件对应文件的沙箱路径，该沙箱路径包含文件名称。 |
| event | number | 是 | 否 | 监听变动的事件集，多个事件通过或(\|)的方式进行集合。<br/>-&nbsp;0x1: IN_ACCESS， 文件被访问。<br/>-&nbsp;0x2: IN_MODIFY，文件内容被修改。<br/>-&nbsp;0x4: IN_ATTRIB，文件元数据被修改。<br/>-&nbsp;0x8: IN_CLOSE_WRITE，文件在打开时进行了写操作，然后被关闭。<br/>-&nbsp;0x10: IN_CLOSE_NOWRITE，文件或目录在打开时未进行写操作，然后被关闭。<br/>-&nbsp;0x20: IN_OPEN，文件或目录被打开。 <br/>-&nbsp;0x40: IN_MOVED_FROM，监听目录中文件被移动走。<br/>-&nbsp;0x80: IN_MOVED_TO，监听目录中文件被移动过来。<br/>-&nbsp;0x100: IN_CREATE，监听目录中文件或子目录被创建。<br/>-&nbsp;0x200: IN_DELETE，监听目录中文件或子目录被删除。<br/>-&nbsp;0x400: IN_DELETE_SELF，监听的目录被删除，删除后监听停止。<br/>-&nbsp;0x800: IN_MOVE_SELF，监听的文件或目录被移动，移动后监听继续。<br/>-&nbsp;0xfff: IN_ALL_EVENTS，监听以上所有事件。 |
| cookie | number | 是 | 否 | 绑定相关事件的cookie。当前仅支持事件IN_MOVED_FROM与IN_MOVED_TO，同一个文件的移动事件IN_MOVED_FROM和IN_MOVED_TO具有相同的cookie值。 |

## Progress<sup>11+</sup>

拷贝进度回调数据

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| processedSize | number | 是 | 否 | 已拷贝的数据大小，单位为Byte。 |
| totalSize | number | 是 | 否 | 待拷贝的数据总大小，单位为Byte。 |

## TaskSignal<sup>12+</sup>

拷贝中断信号。

**系统能力**：SystemCapability.FileManagement.File.FileIO

### cancel<sup>12+</sup>

cancel(): void

取消拷贝任务。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileUri } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let pathDir = context.filesDir;

let srcDirPathLocal: string = pathDir + "/src";
let dstDirPathLocal: string = pathDir + "/dest";
let srcDirUriLocal: string = fileUri.getUriFromPath(srcDirPathLocal);
let dstDirUriLocal: string = fileUri.getUriFromPath(dstDirPathLocal);
let copySignal = new fileIo.TaskSignal;
let progressListener: fileIo.ProgressListener = (progress: fileIo.Progress) => {
  console.info(`progressSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
  if (progress.processedSize / progress.totalSize > 0.5) {
    copySignal.cancel();
    console.info("copy cancel.");
  }
};
let options: fileIo.CopyOptions = {
  "progressListener" : progressListener,
  "copySignal" : copySignal,
}

try {
  fileIo.copy(srcDirUriLocal, dstDirUriLocal, options, (err: BusinessError) => {
    if (err) {
      console.error("copy fail, err: ", err.message);
      return;
    }
    console.info("copy success.");
  })
} catch (err) {
  console.error("copyFileWithCancel failed, err: ", err.message);
}

```

### onCancel<sup>(deprecated)</sup>

onCancel(): Promise&lt;string&gt;

> **说明：**
>
> 从API version 12开始支持，从API version 24开始废弃。

取消拷贝事件监听。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;string&gt; | Promise对象，返回最后一个拷贝的文件路径。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
import { TaskSignal } from '@kit.CoreFileKit';

let copySignal: fileIo.TaskSignal = new TaskSignal();
copySignal.onCancel();
```

## CopyOptions<sup>11+</sup>

拷贝进度回调监听

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| progressListener | [ProgressListener](#progresslistener11) | 否 | 是 | 拷贝进度监听。 |
| copySignal | [TaskSignal](#tasksignal12) | 否 | 是 | 取消拷贝信号。 |

## ProgressListener<sup>11+</sup>

拷贝进度监听。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 类型 | 说明 |
| ---- | ---- |
|(progress: [Progress](#progress11)) => void| 拷贝进度监听|

**示例：**

  ```ts
  import { TaskSignal } from '@kit.CoreFileKit';

  let copySignal: fileIo.TaskSignal = new TaskSignal();
  let progressListener: fileIo.ProgressListener = (progress: fileIo.Progress) => {
    console.info(`processedSize: ${progress.processedSize}, totalSize: ${progress.totalSize}`);
  };
  let copyOption: fileIo.CopyOptions = {
    "progressListener" : progressListener,
    "copySignal" : copySignal,
  }
  ```

## Stat

文件具体信息，在调用Stat的方法前，需要先通过[stat()](#fileiostat)方法（同步或异步）构建一个Stat实例。

### 属性

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| ino | bigint | 是 | 否 | 标识该文件。通常同设备上的不同文件的INO不同。 |
| mode | number | 是 | 否 | 表示文件权限，各特征位的含义如下：<br/>**说明**：以下值为八进制，取得的返回值为十进制，请换算后查看。<br/>-&nbsp;0o400：用户读。对于普通文件，所有者可读取文件；对于目录，所有者可读取目录项。<br/>-&nbsp;0o200：用户写。对于普通文件，所有者可写入文件；对于目录，所有者可创建/删除目录项。<br/>-&nbsp;0o100：用户执行。对于普通文件，所有者可执行文件；对于目录，所有者可在目录中搜索给定路径名。<br/>-&nbsp;0o040：用户组读。对于普通文件，所有用户组可读取文件；对于目录，所有用户组可读取目录项。<br/>-&nbsp;0o020：用户组写。对于普通文件，所有用户组可写入文件；对于目录，所有用户组可创建/删除目录项。<br/>-&nbsp;0o010：用户组执行。对于普通文件，所有用户组可执行文件；对于目录，所有用户组是否可在目录中搜索给定路径名。<br/>-&nbsp;0o004：其他读。对于普通文件，其余用户可读取文件；对于目录，其他用户组可读取目录项。<br/>-&nbsp;0o002：其他写。对于普通文件，其余用户可写入文件；对于目录，其他用户组可创建/删除目录项。<br/>-&nbsp;0o001：其他执行。对于普通文件，其余用户可执行文件；对于目录，其他用户组可在目录中搜索给定路径名。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| uid | number | 是 | 否 | 文件所有者的ID。 |
| gid | number | 是 | 否 | 文件所有组的ID。 |
| size | number | 是 | 否 | 文件的大小，单位为Byte。仅对普通文件有效。 <br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| atime | number | 是 | 否 | 上次访问该文件的时间，表示距1970年1月1日0时0分0秒的秒数。<br>**注意**：目前用户数据分区默认以“noatime”方式挂载，atime更新被禁用。  <br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| mtime | number | 是 | 否 | 上次修改该文件的时间，表示距1970年1月1日0时0分0秒的秒数。  <br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| ctime | number | 是 | 否 | 最近改变文件状态的时间，表示距1970年1月1日0时0分0秒的秒数。 |
| atimeNs<sup>15+</sup> | bigint | 是 | 是 | 上次访问该文件的时间，表示距1970年1月1日0时0分0秒的纳秒数。<br>**注意**：目前用户数据分区默认以“noatime”方式挂载，atime更新被禁用。 |
| mtimeNs<sup>15+</sup> | bigint | 是 | 是 | 上次修改该文件的时间，表示距1970年1月1日0时0分0秒的纳秒数。 |
| ctimeNs<sup>15+</sup> | bigint | 是 | 是 | 最近改变文件状态的时间，表示距1970年1月1日0时0分0秒的纳秒数。 |
| location<sup>11+</sup> | [LocationType](#locationtype11)| 是 |否| 文件的位置，表示该文件是本地文件或者云端文件。 |

> **说明：**
>
> Stat中部分属性仅支持普通文件获取，开发者可通过[isFile()](#isfile)接口判断文件是否为普通文件。

### isBlockDevice

isBlockDevice(): boolean

用于判断文件是否是块特殊文件。一个块特殊文件只能以块为粒度进行访问，且访问的时候带缓存。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| boolean | 表示文件是否是块特殊设备。true：是块特殊设备；false：不是块特殊设备。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isBLockDevice = fileIo.statSync(filePath).isBlockDevice();
  ```

### isCharacterDevice

isCharacterDevice(): boolean

判断文件是否为字符特殊文件。字符特殊设备支持随机访问，且访问时无缓存。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| boolean | 表示文件是否是字符特殊设备。true：是字符特殊设备；false：不是字符特殊设备。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isCharacterDevice = fileIo.statSync(filePath).isCharacterDevice();
  ```

### isDirectory

isDirectory(): boolean

判断文件是否为目录。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| boolean | 表示文件是否是目录。true：是目录；false：不是目录。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let dirPath = pathDir + "/test";
  let isDirectory = fileIo.statSync(dirPath).isDirectory();
  ```

### isFIFO

isFIFO(): boolean

用于判断文件是否是命名管道（有时也称为FIFO）。命名管道通常用于进程间通信。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| boolean | 表示文件是否是&nbsp;FIFO。true：是FIFO；false：不是FIFO。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isFIFO = fileIo.statSync(filePath).isFIFO();
  ```

### isFile

isFile(): boolean

用于判断文件是否是普通文件。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| boolean | 表示文件是否是普通文件。true：是普通文件；false：不是普通文件。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isFile = fileIo.statSync(filePath).isFile();
  ```

### isSocket

isSocket(): boolean

判断文件是否是套接字。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| boolean | 表示文件是否是套接字。true：是套接字；false：不是套接字。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isSocket = fileIo.statSync(filePath).isSocket();
  ```

### isSymbolicLink

isSymbolicLink(): boolean

判断文件是否为符号链接。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| boolean | 表示文件是否是符号链接。true：是符号链接；false：不是符号链接。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let isSymbolicLink = fileIo.statSync(filePath).isSymbolicLink();
  ```

## Stream

文件流，在调用Stream的方法前，需要先通过[fileIo.createStream](#fileiocreatestream)方法或者[fileIo.fdopenStream](#fileiofdopenstream)（同步或异步）来构建一个Stream实例。

### close

close(): Promise&lt;void&gt;

关闭文件流。使用Promise异步回调。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  stream.close().then(() => {
    console.info(`Succeeded in closing file stream.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to close file stream. Code: ${err.code}, message: ${err.message}`);
  });
  ```

### close

close(callback: AsyncCallback&lt;void&gt;): void

异步关闭文件流。使用callback异步回调。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当关闭文件流成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  stream.close((err: BusinessError) => {
    if (err) {
      console.error(`Failed to close stream. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in closing stream.`);
    }
  });
  ```

### closeSync

closeSync(): void

同步关闭文件流。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  stream.closeSync();
  ```

### flush

flush(): Promise&lt;void&gt;

刷新文件流。使用Promise异步回调。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  stream.flush().then(() => {
    console.info(`Succeeded in flushing.`);
    stream.close();
  }).catch((err: BusinessError) => {
    console.error(`Failed to flush. Code: ${err.code}, message: ${err.message}`);
  });
  ```

### flush

flush(callback: AsyncCallback&lt;void&gt;): void

异步刷新文件流。使用callback异步回调。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当刷新文件流成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  stream.flush((err: BusinessError) => {
    if (err) {
      console.error(`Failed to flush stream. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in flushing.`);
      stream.close();
    }
  });
  ```

### flushSync

flushSync(): void

同步刷新文件流。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  stream.flushSync();
  stream.close();
  ```

### write

write(buffer: ArrayBuffer | string, options?: WriteOptions): Promise&lt;number&gt;

将数据写入流文件。使用Promise异步回调。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer \| string | 是 | 待写入文件的数据，可来自缓冲区或字符串。 |
| options | [WriteOptions](#writeoptions11) | 否 | 支持如下选项：<br/>-&nbsp;length，number类型，表示期望写入数据的长度，单位为Byte。默认缓冲区长度。<br/>-&nbsp;offset，number类型，表示期望写入文件的位置，单位为Byte。可选，默认从当前位置开始写。<br/>-&nbsp;encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'。仅支持&nbsp;'utf-8'。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;number&gt; | Promise对象，返回实际写入的长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { WriteOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  let writeOption: WriteOptions = {
    offset: 5,
    length: 5,
    encoding: 'utf-8'
  };
  stream.write("hello, world", writeOption).then((number: number) => {
    console.info(`Succeeded in writing, size is: ${number}`);
    stream.close();
  }).catch((err: BusinessError) => {
    console.error(`Failed to write. Code: ${err.code}, message: ${err.message}`);
  });
  ```

### write

write(buffer: ArrayBuffer | string, callback: AsyncCallback&lt;number&gt;): void

将数据写入流文件。使用callback异步回调。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer \| string | 是 | 待写入文件的数据，可来自缓冲区或字符串。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数，返回实际写入的数据长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  stream.write("hello, world", (err: BusinessError, bytesWritten: number) => {
    if (err) {
      console.error(`Failed to write stream. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (bytesWritten) {
        console.info(`Succeeded in writing, size is: ${bytesWritten}`);
      }
    }
    stream.close();
  });
  ```

### write

write(buffer: ArrayBuffer | string, options: WriteOptions, callback: AsyncCallback&lt;number&gt;): void

将数据写入流文件，支持配置写入选项。使用callback异步回调。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer \| string | 是 | 待写入文件的数据，可来自缓冲区或字符串。 |
| options | [WriteOptions](#writeoptions11) | 是 | 支持如下选项：<br/>-&nbsp;length，number类型，表示期望写入数据的长度，单位为Byte。可选，默认缓冲区长度。<br/>-&nbsp;offset，number类型，表示期望写入文件的位置，单位为Byte。可选，默认从当前位置开始写。<br/>-&nbsp;encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'。仅支持&nbsp;'utf-8'。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数，返回实际写入的数据长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { WriteOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  let writeOption: WriteOptions = {
    offset: 5,
    length: 5,
    encoding: 'utf-8'
  };
  stream.write("hello, world", writeOption, (err: BusinessError, bytesWritten: number) => {
    if (err) {
      console.error(`Failed to write stream. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (bytesWritten) {
        console.info(`Succeeded in writing, size is: ${bytesWritten}`);
      }
    }
    stream.close();
  });
  ```

### writeSync

writeSync(buffer: ArrayBuffer | string, options?: WriteOptions): number

以同步方法将数据写入流文件。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer \| string | 是 | 待写入文件的数据，可来自缓冲区或字符串。 |
| options | [WriteOptions](#writeoptions11) | 否 | 支持如下选项：<br/>-&nbsp;length，number类型，表示期望写入数据的长度，单位为Byte。可选，默认缓冲区长度。<br/>-&nbsp;offset，number类型，表示期望写入文件的位置，单位为Byte。可选，默认从当前位置开始写。<br/>-&nbsp;encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'。仅支持&nbsp;'utf-8'。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| number | 实际写入的长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { WriteOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath,"r+");
  let writeOption: WriteOptions = {
    offset: 5,
    length: 5,
    encoding: 'utf-8'
  };
  let num = stream.writeSync("hello, world", writeOption);
  stream.close();
  ```

### read

read(buffer: ArrayBuffer, options?: ReadOptions): Promise&lt;number&gt;

从流文件读取数据。使用Promise异步回调。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | 是 | 用于读取文件的缓冲区。 |
| options | [ReadOptions](#readoptions11) | 否 | 支持如下选项：<br/>-&nbsp;length，number类型，表示期望读取数据的长度，单位为Byte。可选，默认缓冲区长度。<br/>-&nbsp;offset，number类型，表示期望读取文件的位置，单位为Byte。可选，默认从当前位置开始读。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;number&gt; | Promise对象，返回读取的结果，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { buffer } from '@kit.ArkTS';
  import { ReadOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  let arrayBuffer = new ArrayBuffer(4096);
  let readOption: ReadOptions = {
    offset: 5,
    length: 5
  };
  stream.read(arrayBuffer, readOption).then((readLen: number) => {
    let buf = buffer.from(arrayBuffer, 0, readLen);
    console.info(`Succeeded in reading data, the content of file is: ${buf.toString()}`);
    stream.close();
  }).catch((err: BusinessError) => {
    console.error(`Failed to read data. Code: ${err.code}, message: ${err.message}`);
  });
  ```

### read

read(buffer: ArrayBuffer, callback: AsyncCallback&lt;number&gt;): void

从流文件读取数据。使用callback异步回调。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | 是 | 用于读取文件的缓冲区。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数，返回读取的结果，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { buffer } from '@kit.ArkTS';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  let arrayBuffer = new ArrayBuffer(4096);
  stream.read(arrayBuffer, (err: BusinessError, readLen: number) => {
    if (err) {
      console.error(`Failed to read stream. Code: ${err.code}, message: ${err.message}`);
    } else {
      let buf = buffer.from(arrayBuffer, 0, readLen);
      console.info(`Succeeded in reading data, the content of file is: ${buf.toString()}`);
      stream.close();
    }
  });
  ```

### read

read(buffer: ArrayBuffer, options: ReadOptions, callback: AsyncCallback&lt;number&gt;): void

从流文件读取数据，支持配置读取选项。使用callback异步回调。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | 是 | 用于读取文件的缓冲区。 |
| options | [ReadOptions](#readoptions11) | 是 | 支持如下选项：<br/>-&nbsp;length，number类型，表示期望读取数据的长度，单位为Byte。可选，默认缓冲区长度。<br/>-&nbsp;offset，number类型，表示期望读取文件的位置，单位为Byte。可选，默认从当前位置开始读取。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数，返回读取的结果，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { buffer } from '@kit.ArkTS';
  import { ReadOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  let arrayBuffer = new ArrayBuffer(4096);
  let readOption: ReadOptions = {
    offset: 5,
    length: 5
  };
  stream.read(arrayBuffer, readOption, (err: BusinessError, readLen: number) => {
    if (err) {
      console.error(`Failed to read stream. Code: ${err.code}, message: ${err.message}`);
    } else {
      let buf = buffer.from(arrayBuffer, 0, readLen);
      console.info(`Succeeded in reading data, the content of file is: ${buf.toString()}`);
      stream.close();
    }
  });
  ```

### readSync

readSync(buffer: ArrayBuffer, options?: ReadOptions): number

以同步方法从流文件读取数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | 是 | 用于读取文件的缓冲区。 |
| options | [ReadOptions](#readoptions11) | 否 | 支持如下选项：<br/>-&nbsp;length，number类型，表示期望读取数据的长度，单位为Byte。可选，默认缓冲区长度。<br/>-&nbsp;offset，number类型，表示期望读取文件的位置，单位为Byte。可选，默认从当前位置开始读。<br/> |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| number | 实际读取的长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { ReadOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let stream = fileIo.createStreamSync(filePath, "r+");
  let readOption: ReadOptions = {
    offset: 5,
    length: 5
  };
  let buf = new ArrayBuffer(4096);
  let num = stream.readSync(buf, readOption);
  stream.close();
  ```

## File

由open接口打开的File对象。

### 属性

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| fd | number | 是 | 否 | 打开的文件描述符。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| path<sup>10+</sup> | string | 是 | 否 | 文件路径。 |
| name<sup>10+</sup> | string | 是 | 否 | 文件名。 |

### getParent<sup>11+</sup>

getParent(): string

获取File对象对应文件父目录。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| string | 返回父目录路径。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  console.info(`Succeeded in getting parent path, the parent path is: ${file.getParent()}`);
  fileIo.closeSync(file);
  ```

### lock

lock(exclusive?: boolean): Promise\<void>

对文件阻塞式施加共享锁或独占锁。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| exclusive | boolean | 否 | 是否施加独占锁，默认false。true：施加独占锁；false：不施加独占锁。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  file.lock(true).then(() => {
    console.info(`Succeeded in locking file.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to lock file. Code: ${err.code}, message: ${err.message}`);
  }).finally(() => {
    fileIo.closeSync(file);
  });
  ```

### lock

lock(callback: AsyncCallback\<void>): void

对文件阻塞式施加共享锁。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当文件上锁成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  file.lock((err: BusinessError) => {
    if (err) {
      console.error(`Failed to lock file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in locking file.`);
    }
    fileIo.closeSync(file);
  });
  ```

### lock

lock(exclusive: boolean, callback: AsyncCallback\<void>): void

对文件阻塞式施加共享锁或独占锁。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| exclusive | boolean | 是 | 是否施加独占锁。true：施加独占锁；false：不施加独占锁。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当文件上锁成功，err为undefined，否则为错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  file.lock(true, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to lock file. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`Succeeded in locking file.`);
    }
    fileIo.closeSync(file);
  });
  ```

### tryLock

tryLock(exclusive?: boolean): void

文件非阻塞式施加共享锁或独占锁。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| exclusive | boolean | 否 | 是否施加独占锁，默认false。true：施加独占锁；false：不施加独占锁。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  file.tryLock(true);
  console.info(`Succeeded in locking file.`);
  fileIo.closeSync(file);
  ```

### unlock

unlock(): void

以同步方式解锁文件。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  file.tryLock(true);
  file.unlock();
  console.info(`Succeeded in unlocking file.`);
  fileIo.closeSync(file);
  ```


## FileMapping

文件映射对象，在调用FileMapping的方法前，需要先通过[mmap()](#fileiommap)或方法[mmapSync()](#fileiommapsync)构建一个FileMapping实例。

**起始版本**：26.0.0

### setPosition

setPosition(position: number): void

设置文件映射区的当前位置。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| position | number | 是 | 期望设置的目标位置，单位为Byte。<br>必须为非负数且不大于当前可读写上界的limit，可通过[getLimit()](#getlimit)获得可读写上界的limit。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);
mapping.setPosition(100);
console.info("Succeeded in setPosition.");
mapping.unmapSync();
fileIo.closeSync(file);
```

### getPosition

getPosition(): number

获取文件映射区的当前位置。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| number | 文件映射区的当前位置，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);
let pos = mapping.getPosition();
console.info(`Succeeded in getting position, the position is: ${pos}`);
mapping.unmapSync();
fileIo.closeSync(file);
```

### capacity

capacity(): number

获取文件映射区的容量。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| number | 文件映射区的容量，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);
let cap = mapping.capacity();
console.info(`Succeeded in getting capacity, the capacity is: ${cap}`);
mapping.unmapSync();
fileIo.closeSync(file);
```

### setLimit

setLimit(limit: number): void

设置文件映射区可读写区域的上界。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| limit | number | 是 | 要设置的可读写区域上界值，单位为Byte。<br>取值需大于等于0，且小于等于当前[capacity](#capacity)。若所设值小于文件映射区的当前位置，则当前位置将自动调整至该值。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);
mapping.setLimit(512);
console.info("Succeeded in setLimit.");
mapping.unmapSync();
fileIo.closeSync(file);
```

### getLimit

getLimit(): number

获取文件映射区可读写区域的上界。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| number | 当前可读写区域上界值，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);
let lim = mapping.getLimit();
console.info(`Succeeded in getting limit, the limit is: ${lim}`);
mapping.unmapSync();
fileIo.closeSync(file);
```

### flip

flip(): void

翻转文件映射区，将写入准备状态切换为读取准备状态。调用后，limit被设置为当前position的值，position被重置为0。

推荐在一系列[write()](#write-2)操作完成后，调用此方法准备后续的[read()](#read-2)操作。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let writeData = new ArrayBuffer(50);
mapping.write(writeData);
mapping.flip(); // limit=50, position=0
console.info("Succeeded in flip.");

let readBuffer = new ArrayBuffer(50);
mapping.read(readBuffer);

mapping.unmapSync();
fileIo.closeSync(file);
```

### remaining

remaining(): number

获取从当前位置（position）到可读写区域的上界（limit）之间的剩余字节数。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| number | 剩余可读或可写的字节数，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

mapping.setPosition(100);
let remaining = mapping.remaining();
console.info(`Succeeded in getting remaining, the remaining is: ${remaining}`);

mapping.unmapSync();
fileIo.closeSync(file);
```

### read

read(buffer: ArrayBuffer, length?: number): number

从当前位置读取数据，并将位置后移实际读取的字节数。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | 是 | 用于保存读取到的文件数据的缓冲区。 |
| length | number | 否 | 期望读取数据的长度，单位为Byte。默认缓冲区长度。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| number | 返回实际读取的数据长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(100);
let bytesRead = mapping.read(buffer);
console.info(`Succeeded in reading data, size is: ${bytesRead}`);

mapping.unmapSync();
fileIo.closeSync(file);
```

### read

read(position: number, buffer: ArrayBuffer, length?: number): number

从指定位置读取数据，当前位置不会发生移动。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| position | number | 是 | 期望读取的起始位置，单位为Byte。 |
| buffer | ArrayBuffer | 是 | 用于保存读取到的文件数据的缓冲区。 |
| length | number | 否 | 期望读取数据的长度，单位为Byte。默认缓冲区长度。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| number | 返回实际读取的数据长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(100);
let bytesRead = mapping.read(50, buffer, 50);
console.info(`Succeeded in reading data, size is: ${bytesRead}`);

mapping.unmapSync();
fileIo.closeSync(file);
```

### write

write(data: ArrayBuffer, length?: number): number

从当前位置写入数据，并将位置后移实际写入的字节数。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| data | ArrayBuffer | 是 | 待写入文件的缓冲区数据。 |
| length | number | 否 | 期望写入数据的长度，单位为Byte。默认缓冲区长度。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| number | 返回实际写入的长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(11);
let bytesWritten = mapping.write(buffer);
console.info(`Succeeded in writing data to file, size is: ${bytesWritten}`);

mapping.msyncSync();
mapping.unmapSync();
fileIo.closeSync(file);
```

### write

write(position: number, data: ArrayBuffer, length?: number): number

从指定位置写入数据，当前位置不会发生移动。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| position | number | 是 | 期望写入的起始位置，单位为Byte。 |
| data | ArrayBuffer | 是 | 待写入文件的缓冲区数据。 |
| length | number | 否 | 期望写入数据的长度，单位为Byte。可选，默认缓冲区长度。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| number | 返回实际写入的长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(11);
let bytesWritten = mapping.write(50, buffer);
console.info(`Succeeded in writing data to file, size is: ${bytesWritten}`);

mapping.msyncSync();
mapping.unmapSync();
fileIo.closeSync(file);
```

### msync

msync(): Promise&lt;void&gt;

将整个文件映射区的数据同步到磁盘文件。使用Promise异步回调。

> **说明：**
>
> 如果文件不在本地设备上，调用此接口不保证所有更改都已持久化存储。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(11);
mapping.write(buffer);

mapping.msync().then(() => {
  console.info("Succeeded in msync.");
}).catch((err: BusinessError) => {
  console.error(`Failed to msync. Code: ${err.code}, message: ${err.message}`);
}).finally(() => {
  mapping.unmapSync();
  fileIo.closeSync(file);
});
```

### msync

msync(position: number, length: number): Promise&lt;void&gt;

将文件映射区指定范围内的数据同步到磁盘文件。使用Promise异步回调。

> **说明：**
>
> 如果文件不在本地设备上，调用此接口不保证所有更改都已持久化存储。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| position | number | 是 | 期望同步的起始位置，单位为Byte。 |
| length | number | 是 | 期望同步的数据长度，单位为Byte。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(11);
mapping.write(50, buffer);

mapping.msync(50, buffer.byteLength).then(() => {
  console.info("Succeeded in msync.");
}).catch((err: BusinessError) => {
  console.error(`Failed to msync. Code: ${err.code}, message: ${err.message}`);
}).finally(() => {
  mapping.unmapSync();
  fileIo.closeSync(file);
});
```

### msyncSync

msyncSync(): void

以同步方法将整个文件映射区的数据同步到磁盘文件。

> **说明：**
>
> 如果文件不在本地设备上，调用此接口不保证所有更改都已持久化存储。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(11);
mapping.write(buffer);

mapping.msyncSync();
console.info("Succeeded in msync.");

mapping.unmapSync();
fileIo.closeSync(file);
```

### msyncSync

msyncSync(position: number, length: number): void

以同步方法将文件映射区指定范围内的数据同步到磁盘文件。

> **说明：**
>
> 如果文件不在本地设备上，调用此接口不保证所有更改都已持久化存储。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| position | number | 是 | 期望同步的起始位置，单位为Byte。 |
| length | number | 是 | 期望同步的数据长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(11);
mapping.write(50, buffer);

mapping.msyncSync(50, buffer.byteLength);
console.info("Succeeded in msync.");

mapping.unmapSync();
fileIo.closeSync(file);
```

### unmap

unmap(): Promise&lt;void&gt;

释放文件映射区。使用Promise异步回调。调用后，position、limit和capacity均被重置为0，FileMapping对象不可再进行任何操作。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

let buffer = new ArrayBuffer(11);
mapping.write(buffer);
mapping.unmap().then(() => {
  console.info("Succeeded in unmap.");
}).catch((err: BusinessError) => {
  console.error(`Failed to unmap. Code: ${err.code}, message: ${err.message}`);
}).finally(() => {
  fileIo.closeSync(file);
});
```

### unmapSync

unmapSync(): void

以同步方法释放文件映射区。调用后，position、limit和capacity均被重置为0，FileMapping对象不可再进行任何操作。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let mapping = fileIo.mmapSync(file, fileIo.MappingMode.READ_WRITE, 0, 1024);

mapping.unmapSync();
console.info("Succeeded in unmap.");
fileIo.closeSync(file);
```

## fileIo.DfsListeners<sup>12+</sup>

事件监听类。创建DFSListener对象，用于监听分布式文件系统状态。

**系统能力**：SystemCapability.FileManagement.File.FileIO

### onStatus<sup>12+</sup>

onStatus(networkId: string, status: number): void;

事件回调类。参数由[connectDfs](#fileioconnectdfs12)传入。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| networkId | string | 是 | 设备的网络Id。 |
| status | number | 是 | 分布式文件系统的状态码（以connectDfs回调onStatus的特定错误码作为入参）。触发场景为connectDfs调用过程中出现对端设备异常，对应错误码为：<br/>-&nbsp;[13900046](errorcode-filemanagement.md#13900046-软件造成连接中断)：软件造成连接中断。 |

## RandomAccessFile<sup>10+</sup>

随机读写文件流。在调用RandomAccessFile的方法前，需要先通过createRandomAccessFile()方法（同步或异步）来构建一个RandomAccessFile实例。

### 属性

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| fd | number | 是 | 否 | 打开的文件描述符。 |
| filePointer | number | 是 | 否 | RandomAccessFile对象的偏移指针，单位为Byte。 |

### setFilePointer<sup>10+</sup>

setFilePointer(filePointer:number): void

设置文件偏移指针。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| filePointer | number | 是 | RandomAccessFile对象的偏移指针，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let randomAccessFile = fileIo.createRandomAccessFileSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  randomAccessFile.setFilePointer(1);
  randomAccessFile.close();
  ```


### close<sup>10+</sup>

close(): void

以同步方式关闭RandomAccessFile对象。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let randomAccessFile = fileIo.createRandomAccessFileSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  randomAccessFile.close();
  ```

### write<sup>10+</sup>

write(buffer: ArrayBuffer | string, options?: WriteOptions): Promise&lt;number&gt;

将数据写入文件。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer \| string | 是 | 待写入文件的数据，可来自缓冲区或字符串。 |
| options | [WriteOptions](#writeoptions11) | 否 | 支持如下选项：<br/>-&nbsp;length，number类型，表示期望写入数据的长度，单位为Byte。默认缓冲区长度。<br/>-&nbsp;offset，number类型，表示期望写入文件位置，单位为Byte（基于当前filePointer加上offset的位置）。可选，默认从偏移指针（filePointer）开始写。<br/>-&nbsp;encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'。仅支持&nbsp;'utf-8'。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;number&gt; | Promise对象，返回实际写入的长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { WriteOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  let randomAccessFile = fileIo.createRandomAccessFileSync(file);
  let bufferLength: number = 4096;
  let writeOption: WriteOptions = {
    offset: 1,
    length: 5,
    encoding: 'utf-8'
  };
  let arrayBuffer = new ArrayBuffer(bufferLength);
  randomAccessFile.write(arrayBuffer, writeOption).then((bytesWritten: number) => {
    console.info(`Succeeded in writing, bytes written: ${bytesWritten}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to write. Code: ${err.code}, message: ${err.message}`);
  }).finally(() => {
    randomAccessFile.close();
    fileIo.closeSync(file);
  });

  ```

### write<sup>10+</sup>

write(buffer: ArrayBuffer | string, callback: AsyncCallback&lt;number&gt;): void

将数据写入文件。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer \| string | 是 | 待写入文件的数据，可来自缓冲区或字符串。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数，返回实际写入数据长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filePath = pathDir + "/test.txt";
let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
let randomAccessFile = fileIo.createRandomAccessFileSync(file);
let bufferLength: number = 4096;
let arrayBuffer = new ArrayBuffer(bufferLength);
randomAccessFile.write(arrayBuffer, (err: BusinessError, bytesWritten: number) => {
  if (err) {
    console.error(`Failed to write. Code: ${err.code}, message: ${err.message}`);
  } else {
    if (bytesWritten) {
      console.info(`Succeeded in writing, size is: ${bytesWritten}`);
    }
  }
  randomAccessFile.close();
  fileIo.closeSync(file);
});
```

### write<sup>10+</sup>

write(buffer: ArrayBuffer | string, options: WriteOptions, callback: AsyncCallback&lt;number&gt;): void

将数据写入文件，支持配置写入选项。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer \| string | 是 | 待写入文件的数据，可来自缓冲区或字符串。 |
| options | [WriteOptions](#writeoptions11) | 否 | 支持如下选项：<br/>-&nbsp;length，number类型，表示期望写入数据的长度，单位为Byte。可选，默认为缓冲区长度。<br/>-&nbsp;offset，number类型，表示期望写入文件位置，单位为Byte（基于当前filePointer加上offset的位置）。可选，默认从偏移指针（filePointer）开始写。<br/>-&nbsp;encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'。仅支持&nbsp;'utf-8'。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数，返回实际写入数据长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { WriteOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  let randomAccessFile = fileIo.createRandomAccessFileSync(file);
  let bufferLength: number = 4096;
  let writeOption: WriteOptions = {
    offset: 1,
    length: bufferLength,
    encoding: 'utf-8'
  };
  let arrayBuffer = new ArrayBuffer(bufferLength);
  randomAccessFile.write(arrayBuffer, writeOption, (err: BusinessError, bytesWritten: number) => {
    if (err) {
      console.error(`Failed to write. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (bytesWritten) {
        console.info(`Succeeded in writing, size is: ${bytesWritten}`);
      }
    }
    randomAccessFile.close();
    fileIo.closeSync(file);
  });
  ```

### writeSync<sup>10+</sup>

writeSync(buffer: ArrayBuffer | string, options?: WriteOptions): number

以同步方法将数据写入文件。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer \| string | 是 | 待写入文件的数据，可来自缓冲区或字符串。 |
| options | [WriteOptions](#writeoptions11) | 否 | 支持如下选项：<br/>-&nbsp;length，number类型，表示期望写入数据的长度，单位为Byte。可选，默认缓冲区长度。<br/>-&nbsp;offset，number类型，表示期望写入文件位置，单位为Byte（基于当前filePointer加上offset的位置）。可选，默认从偏移指针（filePointer）开始写。<br/>-&nbsp;encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'。仅支持&nbsp;'utf-8'。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| number | 实际写入的长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { WriteOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let randomAccessFile = fileIo.createRandomAccessFileSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  let writeOption: WriteOptions = {
    offset: 5,
    length: 5,
    encoding: 'utf-8'
  };
  let bytesWritten = randomAccessFile.writeSync("hello, world", writeOption);
  randomAccessFile.close();
  ```

### read<sup>10+</sup>

read(buffer: ArrayBuffer, options?: ReadOptions): Promise&lt;number&gt;

从文件读取数据。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | 是 | 用于读取文件的缓冲区。 |
| options | [ReadOptions](#readoptions11) | 否 | 支持如下选项：<br/>-&nbsp;length，number类型，表示期望读取数据的长度，单位为Byte。可选，默认为缓冲区长度。<br/>-&nbsp;offset，number类型，表示期望读取文件位置，单位为Byte（基于当前filePointer加上offset的位置）。可选，默认从偏移指针（filePointer）开始读。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| Promise&lt;number&gt; | Promise对象，返回读取的结果，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { ReadOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  let randomAccessFile = fileIo.createRandomAccessFileSync(file);
  let bufferLength: number = 4096;
  let readOption: ReadOptions = {
    offset: 1,
    length: 5
  };
  let arrayBuffer = new ArrayBuffer(bufferLength);
  randomAccessFile.read(arrayBuffer, readOption).then((readLength: number) => {
    console.info(`Succeeded in reading, read length: ${readLength}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to read. Code: ${err.code}, message: ${err.message}`);
  }).finally(() => {
    randomAccessFile.close();
    fileIo.closeSync(file);
  });
  ```

### read<sup>10+</sup>

read(buffer: ArrayBuffer, callback: AsyncCallback&lt;number&gt;): void

从文件读取数据。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | 是 | 用于读取文件的缓冲区。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数，返回实际读取的数据长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  let randomAccessFile = fileIo.createRandomAccessFileSync(file);
  let length: number = 20;

  let arrayBuffer = new ArrayBuffer(length);
  randomAccessFile.read(arrayBuffer, (err: BusinessError, readLength: number) => {
    if (err) {
      console.error(`Failed to read. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (readLength) {
        console.info(`Succeeded in reading, size is: ${readLength}`);
      }
    }
    randomAccessFile.close();
    fileIo.closeSync(file);
  });
  ```

### read<sup>10+</sup>

read(buffer: ArrayBuffer, options: ReadOptions, callback: AsyncCallback&lt;number&gt;): void

从文件读取数据，支持配置读取选项。使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | 是 | 用于读取文件的缓冲区。 |
| options | [ReadOptions](#readoptions11) | 是 | 支持如下选项：<br/>-&nbsp;length，number类型，表示读取数据的长度，单位为Byte。可选，默认为缓冲区长度。<br/>-&nbsp;offset，number类型，表示读取文件位置，单位为Byte（基于当前filePointer加上offset的位置）。可选，默认从filePointer开始读。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数，返回实际读取的数据长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { ReadOptions } from '@kit.CoreFileKit';

  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  let randomAccessFile = fileIo.createRandomAccessFileSync(file);
  let length: number = 20;
  let readOption: ReadOptions = {
    offset: 1,
    length: 5
  };
  let arrayBuffer = new ArrayBuffer(length);
  randomAccessFile.read(arrayBuffer, readOption, (err: BusinessError, readLength: number) => {
    if (err) {
      console.error(`Failed to read. Code: ${err.code}, message: ${err.message}`);
    } else {
      if (readLength) {
        console.info(`Succeeded in reading, size is: ${readLength}`);
      }
    }
    randomAccessFile.close();
    fileIo.closeSync(file);
  });
  ```

### readSync<sup>10+</sup>

readSync(buffer: ArrayBuffer, options?: ReadOptions): number

以同步方法从文件读取数据。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| buffer | ArrayBuffer | 是 | 用于读取文件的缓冲区。 |
| options | [ReadOptions](#readoptions11) | 否 | 支持如下选项：<br/>-&nbsp;length，number类型，表示期望读取数据的长度，单位为Byte。可选，默认缓冲区长度。<br/>-&nbsp;offset，number类型，表示期望读取文件位置，单位为Byte（基于当前filePointer加上offset的位置）。可选，默认从偏移指针（filePointer）开始读。<br/> |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| number | 实际读取的长度，单位为Byte。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  let randomAccessFile = fileIo.createRandomAccessFileSync(file);
  let length: number = 4096;
  let arrayBuffer = new ArrayBuffer(length);
  let readLength = randomAccessFile.readSync(arrayBuffer);
  randomAccessFile.close();
  fileIo.closeSync(file);
  ```

### getReadStream<sup>12+</sup>

getReadStream(): ReadStream

获取当前 RandomAccessFile 的一个 ReadStream 实例。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [ReadStream](#readstream12) | 文件可读流。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

**示例：**

  ```ts
  const filePath = pathDir + "/test.txt";
  const randomAccessFile = fileIo.createRandomAccessFileSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  const rs = randomAccessFile.getReadStream();
  rs.close();
  randomAccessFile.close();
  ```

### getWriteStream<sup>12+</sup>

getWriteStream(): WriteStream

获取当前 RandomAccessFile 的一个 WriteStream 实例。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| [WriteStream](#writestream12) | 文件可写流。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

**示例：**

  ```ts
  const filePath = pathDir + "/test.txt";
  const randomAccessFile = fileIo.createRandomAccessFileSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  const ws = randomAccessFile.getWriteStream();
  ws.close();
  randomAccessFile.close();
  ```


## Watcher<sup>10+</sup>

文件目录变化监听对象。由createWatcher接口获得。

### start<sup>10+</sup>

start(): void

开启监听。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let watcher = fileIo.createWatcher(filePath, 0xfff, () => {});
  watcher.start();
  watcher.stop();
  ```

### stop<sup>10+</sup>

stop(): void

停止监听并移除Watcher对象。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  let filePath = pathDir + "/test.txt";
  let watcher = fileIo.createWatcher(filePath, 0xfff, () => {});
  watcher.start();
  watcher.stop();
  ```

## OpenMode

open接口flags参数常量。文件打开标签。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 值 | 说明 |
| ---- | ---- | ---- | ---- |
| READ_ONLY | number | 0o0 | 只读打开。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| WRITE_ONLY | number | 0o1 | 只写打开。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| READ_WRITE | number | 0o2 | 读写打开。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| CREATE | number | 0o100 | 若文件不存在，则创建文件。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| TRUNC | number | 0o1000 | 如果文件存在且以只写或读写的方式打开，则将其长度裁剪为零。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| APPEND | number | 0o2000 | 以追加方式打开，后续写将追加到文件末尾。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| NONBLOCK | number | 0o4000 | 如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续 IO 进行非阻塞操作。 |
| DIR | number | 0o200000 | 如果path不指向目录，则出错。 |
| NOFOLLOW | number | 0o400000 | 如果path指向符号链接，则出错。 |
| SYNC | number | 0o4010000 | 以同步IO的方式打开文件。 |
| UNCACHE | number | 0o10000000000 | 读写文件不进行页缓存。<br> **起始版本：** 26.0.0 <br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## FileFilter

文件名过滤器接口，可通过该接口自定义文件名过滤规则。

**起始版本**：26.0.0

### filter

filter(name: string): boolean

用于[listFileExt](#fileiolistfileext)或[listFileExtSync](#fileiolistfileextsync)接口的文件过滤，判断指定文件名是否应包含在返回的文件列表中。

> **说明**：
>
> 该函数调用频率较高，请避免执行耗时操作，如文件I/O、网络请求等。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| name | string | 是 | 待过滤的文件名或文件相对路径。递归模式下为文件的相对路径，相对路径以“/”开头。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| boolean | 表示是否包含在返回的文件列表中。true：包含该文件；false：不包含该文件。 |


## MappingMode

文件内存映射模式类型的枚举。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 值 | 说明 |
| ---- | ---- | ---- |
| READ_ONLY | 0 | 只读映射模式。文件映射区不可写，修改会抛出异常。 |
| READ_WRITE | 1 | 读写映射模式。修改会写入文件映射区，后续由操作系统同步到文件（非实时）。 |
| PRIVATE | 2 | 私有映射模式。是一种写时复制的映射机制，对映射区的修改仅对当前进程可见，不会影响原始文件。 |

## Filter<sup>10+</sup>

文件过滤配置项，支持listFile接口使用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| suffix | Array&lt;string&gt; | 否 | 是 | 文件后缀名完全匹配，各个关键词OR关系。 |
| displayName | Array&lt;string&gt; | 否 | 是 | 文件名模糊匹配，各个关键词OR关系。当前仅支持通配符*。 |
| mimeType | Array&lt;string&gt; | 否 | 是 | mime类型完全匹配，各个关键词OR关系。预留字段，暂不支持使用。 |
| fileSizeOver | number | 否 | 是 | 文件大小匹配，大于指定大小的文件，单位为Byte。 |
| lastModifiedAfter | number | 否 | 是 | 文件最近修改时间匹配，在指定时间点及之后的文件。 |
| excludeMedia | boolean | 否 | 是 | 是否排除Media中已有的文件。true：排除Media中已有的文件；false：不排除Media中已有的文件。预留字段，暂不支持使用。 |

## ConflictFiles<sup>10+</sup>

冲突文件信息，支持copyDir及moveDir接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 说明 |
| ---- | ---- | ---- |
| srcFile | string | 源冲突文件路径。 |
| destFile | string | 目标冲突文件路径。 |

## Options<sup>11+</sup>

可选项类型，支持readLines接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 说明 |
| ---- | ---- | ---- |
| encoding | string | 文件编码方式。可选项。 |

## WhenceType<sup>11+</sup>

枚举，文件偏移指针相对偏移位置类型，支持lseek接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 值 | 说明 |
| ---- | ---- | ---- |
| SEEK_SET | 0 | 文件起始位置处。 |
| SEEK_CUR | 1 | 当前文件偏移指针位置处。 |
| SEEK_END | 2 | 文件末尾位置处。 |

## LocationType<sup>11+</sup>

枚举，文件位置，表示该文件是否在本地或者云端存在。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 值 | 说明 |
| ---- | ---- | ---- |
| LOCAL | 1 | 文件在本地存在。 |
| CLOUD | 2 | 文件在云端存在。 |

## AccessModeType<sup>12+</sup>

枚举，表示需要校验的具体权限。若不填，默认校验文件是否存在。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 值 | 说明 |
| ---- | ---- | ---- |
| EXIST | 0 | 文件是否存在。 |
| WRITE | 2 | 文件是否具有写入权限。 |
| READ | 4 | 文件是否具有读取权限。 |
| READ_WRITE | 6 | 文件是否具有读写权限。 |

## AccessFlagType<sup>12+</sup>

枚举，表示需要校验的文件位置。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 值 | 说明 |
| ---- | ---- | ---- |
| LOCAL | 0 | 文件是否在本地。 |

## ReadOptions<sup>11+</sup>

可选项类型，支持read接口使用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| offset | number | 否 | 是 | 期望读取文件位置，单位为Byte（基于当前filePointer加上offset的位置）。可选，默认从偏移指针（filePointer）开始读。 |
| length | number | 否 | 是 | 期望读取数据的长度，单位为Byte。可选，默认缓冲区长度。 |

## ReadTextOptions<sup>11+</sup>

可选项类型，支持readText接口使用，ReadTextOptions继承自[ReadOptions](#readoptions11)。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| offset | number | 否 | 是 | 期望读取文件的位置，单位为Byte。可选，默认从当前位置开始读取。 |
| length | number | 否 | 是 | 期望读取数据的长度，单位为Byte。可选，默认文件长度。 |
| encoding | string | 否 | 是 | 当数据是 string 类型时有效，表示数据的编码方式，默认 'utf-8'，仅支持 'utf-8'。   <br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |

## WriteOptions<sup>11+</sup>

可选项类型，支持write接口使用，WriteOptions继承自[Options](#options11)。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| offset | number | 否 | 是 | 期望写入文件位置，单位为Byte（基于当前filePointer加上offset的位置）。可选，默认从偏移指针（filePointer）开始写。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| length | number | 否 | 是 | 期望写入数据的长度，单位为Byte。可选，默认缓冲区长度。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| encoding | string | 否 | 是 | 当数据是string类型时有效，表示数据的编码方式。默认 'utf-8'。仅支持 'utf-8'。 |

## ListFileExtOptions

可选项类型，支持listFileExt接口使用。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| recursion | boolean | 否 | 是 | 是否递归子目录下的文件名，默认为false。<br>false：返回当前目录下满足过滤要求的文件名及目录名。<br>true：返回该目录下所有符合过滤条件的文件的相对路径，相对路径以“/”开头。 |
| listNum | number | 否 | 是 | 列出文件名数量，默认为0，表示列出所有文件。 |
| fileFilter | [FileFilter](#filefilter) | 否 | 是 | 自定义文件名过滤的规则，默认为空，表示不进行过滤。 |

## ListFileOptions<sup>11+</sup>

可选项类型，支持listFile接口使用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| recursion | boolean | 否 | 是 | 是否递归子目录下文件名。可选，默认为false。当recursion为false时，返回当前目录下满足过滤要求的文件名及目录名。当recursion为true时，返回此目录下所有满足过滤要求的文件的相对路径（以“/”开头）。 |
| listNum | number | 否 | 是 | 列出文件名数量。可选，当设置0时，列出所有文件，默认为0。 |
| filter | [Filter](#filter10) | 否 | 是 | 文件过滤配置项。 可选，设置过滤条件。 |

## ReadStream<sup>12+</sup>

文件可读流，需要先通过[fileIo.createReadStream](#fileiocreatereadstream12)方法来构建一个ReadStream实例。ReadStream继承自数据流基类[stream.Readable](../apis-arkts/js-apis-stream.md#readable)。

**规格**：ReadStream读到的数据为解码后的字符串，其编码格式当前仅支持'utf-8'。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| bytesRead | number | 是 | 否 | 可读流已经读取的字节数。 |
| path | string | 是 | 否 | 当前可读流对应的文件路径。 |

### seek<sup>12+</sup>

seek(offset: number, whence?: WhenceType): number


调整可读流偏移指针位置。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| offset | number | 是 | 相对偏移位置，单位为Byte。 |
| whence | [WhenceType](#whencetype11) | 否 | 偏移指针相对位置类型。默认值：SEEK_SET，文件起始位置处。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| number | 当前可读流偏移指针位置（相对于文件头的偏移量，单位为Byte）。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

**示例：**

  ```ts
  const filePath = pathDir + "/test.txt";
  const rs = fileIo.createReadStream(filePath);
  const curOff = rs.seek(5, fileIo.WhenceType.SEEK_SET);
  console.info(`Succeeded in seeking, current offset is ${curOff}`);
  rs.close();
  ```

### close<sup>12+</sup>

close(): void

关闭可读流。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  const filePath = pathDir + "/test.txt";
  const rs = fileIo.createReadStream(filePath);
  rs.close();
  ```

## WriteStream<sup>12+</sup>

文件可写流，需要先通过[fileIo.createWriteStream](#fileiocreatewritestream12)方法来构建一个WriteStream实例。WriteStream继承自数据流基类[stream.Writable](../apis-arkts/js-apis-stream.md#writable)。

### 属性

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| bytesWritten | number | 是 | 否 | 可写流已经写入的字节数。 |
| path | string | 是 | 否 | 当前可写流对应的文件路径。 |

### seek<sup>12+</sup>

seek(offset: number, whence?: WhenceType): number;

调整可写流的偏移指针位置。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| offset | number | 是 | 相对偏移位置，单位为Byte。 |
| whence | [WhenceType](#whencetype11) | 否 | 偏移指针相对位置类型。默认值：SEEK_SET，文件起始位置处。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| number | 当前可写流偏移指针位置（相对于文件头的偏移量，单位为Byte）。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)和[通用错误码](../errorcode-universal.md)。

**示例：**

  ```ts
  const filePath = pathDir + "/test.txt";
  const ws = fileIo.createWriteStream(filePath);
  const curOff = ws.seek(5, fileIo.WhenceType.SEEK_SET);
  console.info(`Succeeded in seeking, current offset is ${curOff}`);
  ws.close();
  ```

### close<sup>12+</sup>

close(): void

关闭可写流。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

  ```ts
  const filePath = pathDir + "/test.txt";
  const ws = fileIo.createWriteStream(filePath);
  ws.close();
  ```

## RandomAccessFileOptions<sup>12+</sup>

可选项类型，支持 createRandomAccessFile 接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| start | number | 否 | 是 | 表示文件的起始偏移位置，单位为Byte。可选，默认从当前位置开始读。 |
| end | number | 否 | 是 | 表示文件的结束偏移位置，单位为Byte。可选，默认文件末尾。 |

## ReadStreamOptions<sup>12+</sup>

可选项类型，支持 createReadStream 接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| start | number | 否 | 是 | 表示期望读取文件的位置，单位为Byte。可选，默认从当前位置开始读。 |
| end | number | 否 | 是 | 表示期望读取结束的位置，单位为Byte。可选，默认文件末尾。 |

## WriteStreamOptions<sup>12+</sup>

可选项类型，支持 createWriteStream 接口使用。

**系统能力**：SystemCapability.FileManagement.File.FileIO

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| start | number | 否 | 是 | 表示期望写入文件的位置，单位为Byte。可选，默认从当前位置开始写。 |
| mode | number | 否 | 是 | 创建文件可写流的[OpenMode](#openmode)，必须指定如下选项中的一个，默认只写方式创建：<br/>-&nbsp;OpenMode.READ_ONLY(0o0)：只读。<br/>-&nbsp;OpenMode.WRITE_ONLY(0o1)：只写。<br/>-&nbsp;OpenMode.READ_WRITE(0o2)：读写。<br/>给定如下功能选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-&nbsp;OpenMode.CREATE(0o100)：若文件不存在，则创建文件。<br/>-&nbsp;OpenMode.TRUNC(0o1000)：如果文件存在且文件具有写权限，则将其长度裁剪为零。<br/>-&nbsp;OpenMode.APPEND(0o2000)：以追加方式打开，后续写将追加到文件末尾。<br/>-&nbsp;OpenMode.NONBLOCK(0o4000)：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续&nbsp;IO&nbsp;进行非阻塞操作。<br/>-&nbsp;OpenMode.DIR(0o200000)：如果path不指向目录，则出错。不允许附加写权限。<br/>-&nbsp;OpenMode.NOFOLLOW(0o400000)：如果path指向符号链接，则出错。<br/>-&nbsp;OpenMode.SYNC(0o4010000)：以同步IO的方式打开文件。 |