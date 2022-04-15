# HiDebug

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

You can run the hidebug command to obtain the memory usage of an application, including the static heap memory (native heap) and proportional set size (PSS) occupied by the application process. You can also export VM memory slices and collect VM CPU profiling data.

## Modules to Import

```
import hidebug from '@ohos.hidebug';
```


## hidebug.getNativeHeapSize

getNativeHeapSize(): bigint

Obtains the total size of the native heap memory.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return Value**

| Type  | Description                       |
| ------ | --------------------------- |
| bigint | Total size of the native heap memory.|


**Example**
  ```
  let nativeHeapSize = hidebug.getNativeHeapSize();
  ```


## hidebug.getNativeHeapAllocatedSize

getNativeHeapAllocatedSize(): bigint

Obtains the size of the allocated native heap memory.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug


**Return Value**
| Type  | Description                             |
| ------ | --------------------------------- |
| bigint | Size of the allocated native heap memory.|


**Example**
  ```
  let nativeHeapAllocatedSize = hidebug.getNativeHeapAllocatedSize();
  ```


## hidebug.getNativeHeapFreeSize

getNativeHeapFreeSize(): bigint

Obtains the size of the free native heap memory.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug


**Return Value**
| Type  | Description                           |
| ------ | ------------------------------- |
| bigint | Size of the free native heap memory.|


**Example**
  ```
  let nativeHeapFreeSize = hidebug.getNativeHeapFreeSize();
  ```


## hidebug.getPss

getPss(): bigint

Obtains the PSS of this process.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug


**Return Value**
| Type  | Description                     |
| ------ | ------------------------- |
| bigint | PSS of the process.|


**Example**
  ```
  let pss = hidebug.getPss();
  ```


## hidebug.getSharedDirty

getSharedDirty(): bigint

Obtains the size of the shared dirty memory of this process.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug


**Return Value**
| Type  | Description                      |
| ------ | -------------------------- |
| bigint | Size of the shared dirty memory of the process.|


**Example**
  ```
  let sharedDirty = hidebug.getSharedDirty();
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
// Code block
// ...
// Code block
hidebug.stopProfiling();
```



## hidebug.stopProfiling

stopProfiling() : void

Stops the profiling method. `stopProfiling()` and `startProfiling()` are called in pairs. `stopProfiling()` always occurs after `startProfiling()`; that is, calling the functions in the following sequences is prohibited: `start->start->stop`, `start->stop->stop`, and `start->start->stop->stop`.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Example**

```js
hidebug.startProfiling("cpuprofiler-20220216");
// Code block
// ...
// Code block
hidebug.stopProfiling();
```

## hidebug.dumpHeapData

dumpHeapData(filename : string) : void

Exports the heap data.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filename | string | Yes  | User-defined heap file name. The `filename.heapsnapshot` file is generated in the `files` directory of the app based on the specified `filename`.|

**Example**

```js
hidebug.dumpHeapData("heap-20220216");
```
