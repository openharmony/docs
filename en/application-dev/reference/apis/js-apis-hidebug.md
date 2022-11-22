# HiDebug

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

You can run the hidebug command to obtain the memory usage of an application, including the static heap memory (native heap) and proportional set size (PSS) occupied by the application process. You can also export VM memory slices and collect VM CPU profiling data.

## Modules to Import

```js
import hidebug from '@ohos.hidebug';
```


## hidebug.getNativeHeapSize

getNativeHeapSize(): bigint

Obtains the total size of the heap memory of this application.

This API is defined but not implemented in OpenHarmony 3.1 Release.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                       |
| ------ | --------------------------- |
| bigint | Total size of the heap memory of this application, in kB.|


**Example**
  ```js
  let nativeHeapSize = hidebug.getNativeHeapSize();
  ```


## hidebug.getNativeHeapAllocatedSize

getNativeHeapAllocatedSize(): bigint

Obtains the size of the allocated heap memory of this application.

This API is defined but not implemented in OpenHarmony 3.1 Release.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug


**Return value**
| Type  | Description                             |
| ------ | --------------------------------- |
| bigint | Size of the allocated heap memory of this application, in kB.|


**Example**
  ```js
  let nativeHeapAllocatedSize = hidebug.getNativeHeapAllocatedSize();
  ```


## hidebug.getNativeHeapFreeSize

getNativeHeapFreeSize(): bigint

Obtains the size of the free heap memory of this application.

This API is defined but not implemented in OpenHarmony 3.1 Release.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug


**Return value**
| Type  | Description                           |
| ------ | ------------------------------- |
| bigint | Size of the free heap memory of this application, in kB.|


**Example**
  ```js
  let nativeHeapFreeSize = hidebug.getNativeHeapFreeSize();
  ```


## hidebug.getPss

getPss(): bigint

Obtains the size of the used physical memory of this process.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug


**Return value**
| Type  | Description                     |
| ------ | ------------------------- |
| bigint | Used physical memory of this process, in kB.|


**Example**
  ```js
  let pss = hidebug.getPss();
  ```


## hidebug.getSharedDirty

getSharedDirty(): bigint

Obtains the size of the shared dirty memory of this process.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug


**Return value**
| Type  | Description                      |
| ------ | -------------------------- |
| bigint | Size of the shared dirty memory of this process, in kB.|


**Example**
  ```js
  let sharedDirty = hidebug.getSharedDirty();
  ```

## hidebug.getPrivateDirty<sup>9+<sup>

getPrivateDirty(): bigint

Obtains the size of the private dirty memory of this process.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug


**Return value**
| Type  | Description                      |
| ------ | -------------------------- |
| bigint | Size of the private dirty memory of this process, in kB.|


**Example**
  ```js
  let privateDirty = hidebug.getPrivateDirty();
  ```

## hidebug.getCpuUsage<sup>9+<sup>

getCpuUsage(): number

Obtains the CPU usage of this process.

For example, if the CPU usage is **50%**, **0.5** is returned.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug


**Return value**
| Type  | Description                      |
| ------ | -------------------------- |
| number | CPU usage of this process.|


**Example**
  ```js
  let cpuUsage = hidebug.getCpuUsage();
  ```

## hidebug.startProfiling

startProfiling(filename : string) : void

Starts the profiling method. `startProfiling()` and `stopProfiling()` are called in pairs. `startProfiling()` always occurs before `stopProfiling()`; that is, calling the functions in the following sequences is prohibited: `start->start->stop`, `start->stop->stop`, and `start->start->stop->stop`.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filename | string | Yes  | User-defined profile name. The `filename.json` file is generated in the `files` directory of the application based on the specified `filename`.|

**Example**

```js
hidebug.startProfiling("cpuprofiler-20220216");
// code block
// ...
// code block
hidebug.stopProfiling();
```



## hidebug.stopProfiling

stopProfiling() : void

Stops the profiling method. `startProfiling()` and `stopProfiling()` are called in pairs. `startProfiling()` always occurs before `stopProfiling()`; that is, calling the functions in the following sequences is prohibited: `start->start->stop`, `start->stop->stop`, and `start->start->stop->stop`.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Example**

```js
hidebug.startProfiling("cpuprofiler-20220216");
// code block
// ...
// code block
hidebug.stopProfiling();
```

## hidebug.dumpHeapData

dumpHeapData(filename : string) : void

Exports data from the specified heap file.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory | Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filename | string | Yes  | User-defined heap file name. The `filename.heapsnapshot` file is generated in the `files` directory of the application based on the specified `filename`.|

**Example**

```js
hidebug.dumpHeapData("heap-20220216");
```

## hidebug.getServiceDump<sup>9+<sup>

getServiceDump(serviceid : number) : string

Obtains information on the specified system service.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| serviceid | number | Yes  | ID of the system service. |

**Return value**
| Type  | Description                      |
| ------ | -------------------------- |
| string | Absolute path of the file that contains the service information to dump. |

**Example**

```js
let serviceId = 10;
let pathName = hidebug.getServiceDump(serviceId);
```
