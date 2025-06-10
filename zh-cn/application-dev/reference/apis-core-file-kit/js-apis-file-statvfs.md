# @ohos.file.statvfs (文件系统空间统计)

该模块提供文件系统相关存储信息的功能：向应用程序提供获取文件系统总字节数、空闲字节数的JS接口。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { statfs } from '@kit.CoreFileKit';
```

## statfs.getFreeSize

getFreeSize(path:string):Promise&lt;number&gt;

异步方法获取指定文件系统空闲字节数，以Promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名 | 类型   | 必填 | 说明                         |
  | ------ | ------ | ---- | ---------------------------- |
  | path   | string | 是   | 需要查询的文件系统的文件路径。 |

**返回值：**

  | 类型                  | 说明           |
  | --------------------- | -------------- |
  | Promise&lt;number&gt; | Promise对象，返回空闲字节数。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

<!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let path = context.filesDir;
  statfs.getFreeSize(path).then((number: number) => {
    console.info("getFreeSize succeed, Size: " + number);
  }).catch((err: BusinessError) => {
    console.error("getFreeSize failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## statfs.getFreeSize

getFreeSize(path:string, callback:AsyncCallback&lt;number&gt;): void

异步方法获取指定文件系统空闲字节数，使用callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名   | 类型                        | 必填 | 说明                         |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | path     | string                      | 是   | 需要查询的文件系统的文件路径。 |
  | callback | AsyncCallback&lt;number&gt; | 是   | 异步获取空闲字节数之后的回调。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

<!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let path = context.filesDir;
  statfs.getFreeSize(path, (err: BusinessError, number: number) => {
    if (err) {
      console.error("getFreeSize failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("getFreeSize succeed, Size: " + number);
    }
  });
  ```

## statfs.getFreeSizeSync<sup>10+</sup>

getFreeSizeSync(path:string): number

以同步方法获取指定文件系统空闲字节数。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名 | 类型   | 必填 | 说明                         |
  | ------ | ------ | ---- | ---------------------------- |
  | path   | string | 是   | 需要查询的文件系统的文件路径。 |

**返回值：**

  | 类型                  | 说明           |
  | --------------------- | -------------- |
  | number | 返回空闲字节数。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

<!--code_no_check-->
  ```ts
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let path = context.filesDir;
  let number = statfs.getFreeSizeSync(path);
  console.info("getFreeSizeSync succeed, Size: " + number);
  ```

## statfs.getTotalSize

getTotalSize(path: string): Promise&lt;number&gt;

异步方法获取指定文件系统总字节数，以Promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名 | 类型   | 必填 | 说明                         |
  | ---- | ------ | ---- | ---------------------------- |
  | path | string | 是   | 需要查询的文件系统的文件路径。 |

**返回值：**

  | 类型                  | 说明         |
  | --------------------- | ------------ |
  | Promise&lt;number&gt; | Promise对象，返回总字节数。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

<!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let path = context.filesDir;
  statfs.getTotalSize(path).then((number: number) => {
    console.info("getTotalSize succeed, Size: " + number);
  }).catch((err: BusinessError) => {
    console.error("getTotalSize failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

## statfs.getTotalSize

getTotalSize(path: string, callback: AsyncCallback&lt;number&gt;): void

异步方法获取指定文件系统总字节数，使用callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名   | 类型                        | 必填 | 说明                         |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | path     | string                      | 是   | 需要查询的文件系统的文件路径。 |
  | callback | AsyncCallback&lt;number&gt; | 是   | 异步获取总字节数之后的回调。   |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

<!--code_no_check-->
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let path = context.filesDir;
  statfs.getTotalSize(path, (err: BusinessError, number: number) => {
    if (err) {
      console.error("getTotalSize failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("getTotalSize succeed, Size: " + number);
    }
  });
  ```

## statfs.getTotalSizeSync<sup>10+</sup>

getTotalSizeSync(path: string): number

以同步方法获取指定文件系统总字节数。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名 | 类型   | 必填 | 说明                         |
  | ---- | ------ | ---- | ---------------------------- |
  | path | string | 是   | 需要查询的文件系统的文件路径。 |

**返回值：**

  | 类型                  | 说明         |
  | --------------------- | ------------ |
  | number | 返回总字节数。 |

**错误码：**

接口抛出错误码的详细介绍请参见[基础文件IO错误码](errorcode-filemanagement.md#基础文件io错误码)。

**示例：**

<!--code_no_check-->
  ```ts
  import { common } from '@kit.AbilityKit';

  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let path = context.filesDir;
  let number = statfs.getTotalSizeSync(path);
  console.info("getTotalSizeSync succeed, Size: " + number);
  ```
