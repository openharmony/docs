# @ohos.hiviewdfx.jsLeakWatcher (js泄露检测)

本模块提供了监控js对象是否发生泄露的能力。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { jsLeakWatcher } from '@kit.PerformanceAnalysisKit';
```


## jsLeakWatcher.enable

enable(isEnable: boolean): void;

使能js对象泄露检测，默认关闭。

**系统能力：** SystemCapability.HiviewDFX.HiChecker

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| isEnable | boolean | 是 | 是否使能jsLeakWatcher |

**示例：**

```js
jsLeakWatcher.enable(true);
```


## jsLeakWatcher.watch

watch(obj: object, msg: string): void;

注册待检测泄露的对象。

**系统能力：** SystemCapability.HiviewDFX.HiChecker

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| obj | object | 是 | 需要检测的对象名 |
| msg | string | 是 | 自定义对象信息 |

**示例：**

```js
let obj:Object = new Object();
jsLeakWatcher.watch(obj, "Trace Object");
```


## jsLeakWatcher.check

check(): string;

获取已通过jsLeakWatcher.watch注册且可能发生泄露的对象列表，触发GC后未被回收的对象会被标记为泄露。

**系统能力：** SystemCapability.HiviewDFX.HiChecker

**返回值：**

| 类型    | 说明                                                       |
| ------- | ---------------------------------------------------------- |
| string | JSON格式的疑似泄漏对象列表 |

**示例：**
```js
let leakObjlist:string = jsLeakWatcher.check();
```


## jsLeakWatcher.dump

dump(filePath: string): Array&lt;string&gt;;

导出泄漏列表和虚拟机内存快照。

**系统能力：** SystemCapability.HiviewDFX.HiChecker

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| filePath | string | 是 | 导出信息生成的文件存放的路径 |

**返回值：**

| 类型    | 说明                                                       |
| ------- | ---------------------------------------------------------- |
| Array&lt;string&gt; | 导出结果的数组，索引0为泄露列表文件名，后缀为.jsleaklist，索引1为虚拟机内存快照文件名，后缀为.heapsnapshort |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 401 | Parameter error. The filepath is invalid.                      |

**示例：**

```js
let context = getContext(this);
let files:Array<string> = jsLeakWatcher.dump(context.filesDir);
```