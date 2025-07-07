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

enable(isEnable: boolean): void

使能js对象泄露检测，默认关闭。

**系统能力**：SystemCapability.HiviewDFX.HiChecker

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| isEnable | boolean | 是 | 是否使能jsLeakWatcher。true：使能jsleakwatcher；false：不使能jsleakwatcher。 |

**示例：**

```js
jsLeakWatcher.enable(true);
```


## jsLeakWatcher.watch

watch(obj: object, msg: string): void

注册待检测泄露的对象。

**系统能力**：SystemCapability.HiviewDFX.HiChecker

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| obj | object | 是 | 需要检测的对象名。 |
| msg | string | 是 | 自定义对象信息。 |

**示例：**

```js
let obj:Object = new Object();
jsLeakWatcher.watch(obj, "Trace Object");
```


## jsLeakWatcher.check

check(): string

获取已通过jsLeakWatcher.watch注册且可能发生泄露的对象列表，触发GC后未被回收的对象会被标记为泄露。

**系统能力**：SystemCapability.HiviewDFX.HiChecker

**返回值：**

| 类型    | 说明                                                       |
| ------- | ---------------------------------------------------------- |
| string | JSON格式的疑似泄漏对象列表。 |

**示例：**
```js
let leakObjlist:string = jsLeakWatcher.check();
```


## jsLeakWatcher.dump

dump(filePath: string): Array&lt;string&gt;

导出泄漏列表和虚拟机内存快照。

**系统能力**：SystemCapability.HiviewDFX.HiChecker

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| filePath | string | 是 | 导出信息生成的文件存放的路径。 |

**返回值：**

| 类型    | 说明                                                       |
| ------- | ---------------------------------------------------------- |
| Array&lt;string&gt; | 导出结果的数组。索引0为泄露列表文件名，后缀为.jsleaklist；索引1为虚拟机内存快照文件名，后缀为.heapsnapshort。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 401 | Parameter error. The filepath is invalid.                      |

**示例：**

```js
let context = this.getUIContext().getHostContext();
let files: Array<string> = jsLeakWatcher.dump(context?.filesDir);
```


## jsLeakWatcher.enableLeakWatcher<sup>20+</sup>

enableLeakWatcher(isEnabled: boolean, config: Array&lt;string&gt;, callback: Callback&lt;Array&lt;string&gt;&gt;): void

使能js对象泄露检测，默认关闭。

这个接口通过一次调用即可检测JS对象的内存泄漏，比之前需要调用四个函数（enable、watch、check、dump）的方法更加简洁。

如果发生内存泄漏，泄漏文件将通过回调函数返回给开发者。


**系统能力**：SystemCapability.HiviewDFX.HiChecker

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| isEnabled | boolean | 是| 是否使能js对象内存泄漏检测功能。true：开启该功能；false：关闭该功能。|
| config | array&lt;string&gt; | 是| 配置项，数组中每个元素为监测具体对象的类型。<br>可配置项包括：XComponent，NodeContainer，Window，Custom Component，和Ability。 |
| callback | Callback&lt;Array&lt;string&gt;&gt; | 是| 回调函数，用于接收jsLeakWatcher.enableLeakWatcher接口的返回的内存泄漏的对象。<br>回调函数中传入一个数组对象，索引0为泄露列表文件名，后缀为.jsleaklist；索引1为虚拟机内存快照文件名，后缀为.heapsnapshort。|


**错误码：**

以下错误码的详细介绍请参见[JsLeakWatcher错误码](./errorcode-jsleakwatcher.md)。

| 错误码ID| 错误信息|
| ------- | ----------------------------------------------------------------- |
| 10801001 | The parameter isEnabled invalid.                      |
| 10801002 | The parameter config invalid.                        |
| 10801003 | The parameter callback invalid.                       |

**示例：**

```ts
let config: Array<string> = ['XComponent'];
// 监测js对象XComponent的内存泄漏
jsLeakWatcher.enableLeakWatcher(true, config, (filePath: Array<string>) => {
    console.info('JsLeakWatcher leaklistFileName:' + filePath[0]);
    console.info('JsLeakWatcher heapDumpFileName:' + filePath[1]);
});
```

