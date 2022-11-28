# Debug调试

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

使用hidebug，可以获取应用内存的使用情况，包括应用进程的静态堆内存（native heap）信息、应用进程内存占用PSS（Proportional Set Size）信息等；可以完成虚拟机内存切片导出，虚拟机CPU Profiling采集等操作。

## 导入模块

```js
import hidebug from '@ohos.hidebug';
```


## hidebug.getNativeHeapSize

getNativeHeapSize(): bigint

获取本应用堆内存的总大小。

本接口在OpenHarmony 3.1 Release版本仅为接口定义，暂不支持使用。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                        |
| ------ | --------------------------- |
| bigint | 返回本应用堆内存总大小，单位为kB。 |


**示例：**
  ```js
  let nativeHeapSize = hidebug.getNativeHeapSize();
  ```


## hidebug.getNativeHeapAllocatedSize

getNativeHeapAllocatedSize(): bigint

获取本应用堆内存的已分配内存大小。

本接口在OpenHarmony 3.1 Release版本仅为接口定义，暂不支持使用。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                              |
| ------ | --------------------------------- |
| bigint | 返回本应用堆内存的已分配内存，单位为kB。 |


**示例：**
  ```js
  let nativeHeapAllocatedSize = hidebug.getNativeHeapAllocatedSize();
  ```


## hidebug.getNativeHeapFreeSize

getNativeHeapFreeSize(): bigint

获取本应用堆内存的空闲内存大小。

本接口在OpenHarmony 3.1 Release版本仅为接口定义，暂不支持使用。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                            |
| ------ | ------------------------------- |
| bigint | 返回本应用堆内存的空闲内存，单位为kB。 |

**示例：**
  ```js
  let nativeHeapFreeSize = hidebug.getNativeHeapFreeSize();
  ```


## hidebug.getPss

getPss(): bigint

获取应用进程实际使用的物理内存大小。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| bigint | 返回应用进程实际使用的物理内存大小，单位为kB。 |

**示例：**
  ```js
  let pss = hidebug.getPss();
  ```


## hidebug.getSharedDirty

getSharedDirty(): bigint

获取进程的共享脏内存大小。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| bigint | 返回进程的共享脏内存大小，单位为kB。 |


**示例：**
  ```js
  let sharedDirty = hidebug.getSharedDirty();
  ```

## hidebug.getPrivateDirty<sup>9+<sup>

getPrivateDirty(): bigint

获取进程的私有脏内存大小。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| bigint | 返回进程的私有脏内存大小，单位为kB。 |


**示例：**
  ```js
  let privateDirty = hidebug.getPrivateDirty();
  ```

## hidebug.getCpuUsage<sup>9+<sup>

getCpuUsage(): number

获取进程的CPU使用率。

如占用率为50%，则返回0.5。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| number | 获取进程的CPU使用率。 |


**示例：**
  ```js
  let cpuUsage = hidebug.getCpuUsage();
  ```

## hidebug.startProfiling<sup>(deprecated)</sup>

startProfiling(filename : string) : void

> **说明：** 从 API Version 9 开始废弃，建议使用[hidebug.startJsCpuProfiling](#hidebugstartjscpuprofiling9)替代。

启动虚拟机Profiling方法跟踪，`startProfiling()`方法的调用需要与`stopProfiling()`方法的调用一一对应，先开启后关闭，严禁使用`start->start->stop`，`start->stop->stop`，`start->start->stop->stop`等类似的顺序调用。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filename | string | 是   | 用户自定义的profiling文件名，根据传入的`filename`，将在应用的`files`目录生成`filename.json`文件。 |

**示例：**

```js
hidebug.startProfiling("cpuprofiler-20220216");
// code block
// ...
// code block
hidebug.stopProfiling();
```



## hidebug.stopProfiling<sup>(deprecated)</sup>

stopProfiling() : void

> **说明：** 从 API Version 9 开始废弃，建议使用[hidebug.stopJsCpuProfiling](#hidebugstopjscpuprofiling9)替代。

停止虚拟机Profiling方法跟踪，`stopProfiling()`方法的调用需要与`startProfiling()`方法的调用一一对应，先开启后关闭，严禁使用`start->start->stop`，`start->stop->stop`，`start->start->stop->stop`等类似的顺序调用。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**示例：**

```js
hidebug.startProfiling("cpuprofiler-20220216");
// code block
// ...
// code block
hidebug.stopProfiling();
```

## hidebug.dumpHeapData<sup>(deprecated)</sup>

dumpHeapData(filename : string) : void

> **说明：** 从 API Version 9 开始废弃，建议使用[hidebug.dumpJsHeapData](#hidebugdumpjsheapdata9)替代。

虚拟机堆导出。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filename | string | 是   | 用户自定义的虚拟机堆文件名，根据传入的`filename`，将在应用的`files`目录生成`filename.heapsnapshot`文件。 |

**示例：**

```js
hidebug.dumpHeapData("heap-20220216");
```

## hidebug.getServiceDump<sup>9+<sup>

getServiceDump(serviceid : number, fd : number, args : Array\<string>) : void

获取系统服务信息。

**需要权限**: ohos.permission.DUMP

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| serviceid | number | 是   | 基于该用户输入的service id获取系统服务信息。|
| fd | number | 是   | 文件描述符，该接口会往该fd中写入数据。|
| args | Array\<string> | 是   | 系统服务的Dump接口所对应的参数列表。|


**示例：**

```js
import fileio from '@ohos.fileio'
import hidebug from '@ohos.hidebug'
import featureAbility from '@ohos.ability.featureAbility'

let context = featureAbility.getContext();
context.getFilesDir().then((data) => {
  var path = data + "/serviceInfo.txt"
  console.info("output path: " + path)
  let fd = fileio.openSync(path, 0o102, 0o666)
  var serviceId = 10
  var args = new Array("allInfo")
  try {
    hidebug.getServiceDump(serviceId, fd, args)
  } catch (error) {
    console.info(error.code)
    console.info(error.message)
  }
  fileio.closeSync(fd);
})
```

## hidebug.startJsCpuProfiling<sup>9+</sup>

startJsCpuProfiling(filename : string) : void

启动虚拟机Profiling方法跟踪，`startJsCpuProfiling()`方法的调用需要与`stopJsCpuProfiling()`方法的调用一一对应，先开启后关闭，严禁使用`start->start->stop`，`start->stop->stop`，`start->start->stop->stop`等类似的顺序调用。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filename | string | 是   | 用户自定义的profiling文件名，根据传入的`filename`，将在应用的`files`目录生成`filename.json`文件。 |

**示例：**

```js
import hidebug from '@ohos.hidebug'

try {
  hidebug.startJsCpuProfiling("cpu_profiling");
  ...
  hidebug.stopJsCpuProfiling();
} catch (error) {
  console.info(error.code)
  console.info(error.message)
}
```

## hidebug.stopJsCpuProfiling<sup>9+</sup>

stopJsCpuProfiling() : void

停止虚拟机Profiling方法跟踪，`startJsCpuProfiling()`方法的调用需要与`stopJsCpuProfiling()`方法的调用一一对应，先开启后关闭，严禁使用`start->start->stop`，`start->stop->stop`，`start->start->stop->stop`等类似的顺序调用。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filename | string | 是   | 用户自定义的profiling文件名，根据传入的`filename`，将在应用的`files`目录生成`filename.json`文件。 |

**示例：**

```js
import hidebug from '@ohos.hidebug'

try {
  hidebug.startJsCpuProfiling("cpu_profiling");
  ...
  hidebug.stopJsCpuProfiling();
} catch (error) {
  console.info(error.code)
  console.info(error.message)
}
```

## hidebug.dumpJsHeapData<sup>9+</sup>

dumpJsHeapData(filename : string) : void

虚拟机堆导出。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filename | string | 是   | 用户自定义的虚拟机堆文件名，根据传入的`filename`，将在应用的`files`目录生成`filename.heapsnapshot`文件。 |

**示例：**

```js
import hidebug from '@ohos.hidebug'

try {
  hidebug.dumpJsHeapData("heapData");
} catch (error) {
  console.info(error.code)
  console.info(error.message)
}
```