# @ohos.app.ability.appMemoryOptimizer (Application Memory Optimizer)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=38a6a9e75eb8342b6ea8020426180dd0c5d97cb3 translatedAt=2026-08-13T13:17:19.678Z pushedAt=2026-08-14T08:39:14.803Z -->

appMemoryOptimizer provides application memory optimization capabilities, including releasing the file page cache of a specified file and releasing the file page cache of a specified module. For example, when an app enters the background or the device memory is tight, calling evictFilePages to release the file page cache of loaded files can reduce the app's own memory usage.

**Since**: 26.0.0

## Modules to Import

```ts
import { appMemoryOptimizer } from '@kit.AbilityKit';
```

## appMemoryOptimizer.evictFilePages

evictFilePages(fileNames: Array\<string\>): Promise\<void\>

Requests the system to release the file page cache of the specified files. The system determines whether to actually perform the release based on the current memory status, and the release is not guaranteed to succeed. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| fileNames | Array\<string\> | Yes | Array of file names whose file page cache is to be released. Each file name must end with `.so`, `.hap`, or `.hsp`. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise\<void\> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| -------- | -------- |
| 16000163 | File type error. File name does not end with .so, .hap, or .hsp. |

**Example**

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

Requests the system to release the file page cache of the specified modules. The system determines whether to actually perform the release based on the current memory status, and successful release is not guaranteed. The system reads the `memory_optimizer.json` configuration file in the corresponding module (path: `{module directory}/src/main/resources/rawfile/memory_optimizer.json`), obtains the `evictFilePages` array, and then releases the file page cache based on the file names configured in the array. The file names in the `evictFilePages` array must end with `.so`, `.hap`, or `.hsp`. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| moduleNames | Array\<string\> | Yes | Array of module names whose file page cache is to be released. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise\<void\> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| -------- | -------- |
| 16000163 | File type error. File names in the evictFilePages array of the configuration file do not end with .so, .hap, or .hsp. |
| 16000164 | Failed to parse configuration file. |

**Example**

Example of the configuration file `src/main/resources/rawfile/memory_optimizer.json` of the `entry` module:

```json
{
  "evictFilePages": [
    "libentry.so",
    "sharedLibrary.hsp"
  ]
}
```

Example

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