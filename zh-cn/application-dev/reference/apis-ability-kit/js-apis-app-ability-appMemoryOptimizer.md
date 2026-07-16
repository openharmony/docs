# @ohos.app.ability.appMemoryOptimizer (应用内存优化器)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

appMemoryOptimizer提供应用内存优化的能力，包括释放指定文件的文件页缓存、释放指定模块的文件页缓存等。例如，应用进入后台或设备内存紧张时，调用evictFilePages释放已加载文件的文件页缓存，可降低应用自身的内存占用。

**起始版本：** 26.0.0

## 导入模块

```ts
import { appMemoryOptimizer } from '@kit.AbilityKit';
```

## appMemoryOptimizer.evictFilePages

evictFilePages(fileNames: Array\<string\>): Promise\<void\>

向系统申请释放指定文件的文件页缓存，系统会根据当前内存状态决定是否真正执行，不保证一定释放成功。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| fileNames | Array\<string\> | 是 | 需要释放文件页缓存的文件名数组，文件名必须以`.so`、`.hap`或`.hsp`结尾。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void\> | Promise对象，无返回结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16000163 | File type error. File name does not end with .so, .hap, or .hsp. |

**示例：**

```ts
import { appMemoryOptimizer } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  appMemoryOptimizer.evictFilePages(['libentry.so', 'sharedLibrary.hsp'])
    .then(() => {
      console.info('EvictFilePages success.');
    })
    .catch((err: BusinessError) => {
      console.error(`EvictFilePages failed, error code: ${err.code}, error msg: ${err.message}.`);
    });
} catch (error) {
  console.error('EvictFilePages failed, error: ' + JSON.stringify(error));
}
```

## appMemoryOptimizer.evictModuleFilePages

evictModuleFilePages(moduleNames: Array\<string\>): Promise\<void\>

向系统申请释放指定模块的文件页缓存，系统会根据当前内存状态决定是否真正执行，不保证一定释放成功。系统会读取对应模块中的`memory_optimizer.json`配置文件（路径：`{模块目录}/src/main/resources/rawfile/memory_optimizer.json`），获取`evictFilePages`数组，然后按照数组中配置的文件名执行文件页缓存释放操作。`evictFilePages`数组里的文件名必须以`.so`、`.hap`或`.hsp`结尾。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| moduleNames | Array\<string\> | 是 | 需要释放文件页缓存的模块名数组。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void\> | Promise对象，无返回结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16000163 | File type error. File names in the evictFilePages array of the configuration file do not end with .so, .hap, or .hsp. |
| 16000164 | Failed to parse configuration file. |

**示例：**

模块`entry`的配置文件`src/main/resources/rawfile/memory_optimizer.json`示例：

```json
{
  "evictFilePages": [
    "libentry.so",
    "sharedLibrary.hsp"
  ]
}
```

接口调用示例：

```ts
import { appMemoryOptimizer } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  appMemoryOptimizer.evictModuleFilePages(['entry'])
    .then(() => {
      console.info('EvictModuleFilePages success.');
    })
    .catch((err: BusinessError) => {
      console.error(`EvictModuleFilePages failed, error code: ${err.code}, error msg: ${err.message}.`);
    });
} catch (error) {
  console.error('EvictFilePages failed, error: ' + JSON.stringify(error));
}
```
