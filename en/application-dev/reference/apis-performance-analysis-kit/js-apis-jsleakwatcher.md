# @ohos.hiviewdfx.jsLeakWatcher (JS Leak Detection)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @lu-tao-->
<!--SE: @martin-duan-->
<!--TSE: @gcw_KuLfPSbe-->

This module provides the capability of monitoring whether JS objects are leaked.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { jsLeakWatcher } from '@kit.PerformanceAnalysisKit';
```


## jsLeakWatcher.enable

enable(isEnable: boolean): void

Enables the detection for JS object leaks. This function is disabled by default.

**System capability**: SystemCapability.HiviewDFX.HiChecker

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| isEnable | boolean | Yes| Whether to enable **jsLeakWatcher**. The value **true** means to enable jsleakwatcher, and **false** means the opposite.|

**Example**

```js
jsLeakWatcher.enable(true);
```


## jsLeakWatcher.watch

watch(obj: object, msg: string): void

Registers the object to be checked.

**System capability**: SystemCapability.HiviewDFX.HiChecker

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| obj | object | Yes| Name of the object to be checked.|
| msg | string | Yes| Custom object information.|

**Example**

```js
let obj:Object = new Object();
jsLeakWatcher.watch(obj, "Trace Object");
```


## jsLeakWatcher.check

check(): string

Obtains the list of objects that are registered using **jsLeakWatcher.watch()** and may leak. Objects that are not reclaimed after GC is triggered are marked as leaked.

**System capability**: SystemCapability.HiviewDFX.HiChecker

**Return value**

| Type   | Description                                                      |
| ------- | ---------------------------------------------------------- |
| string | List of objects that are suspected to leak, in JSON format.|

**Example**
```js
let leakObjlist:string = jsLeakWatcher.check();
```


## jsLeakWatcher.dump

dump(filePath: string): Array&lt;string&gt;

Exports the list of leaked objects and VM memory snapshot.

**System capability**: SystemCapability.HiviewDFX.HiChecker

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| filePath | string | Yes| The path for storing exported information files.|

**Return value**

| Type   | Description                                                      |
| ------- | ---------------------------------------------------------- |
| Array&lt;string&gt; | Array of exported results. Index **0** indicates the name of the leak list file, whose name extension is **.jsleaklist**. Index **1** indicates the name of the VM memory snapshot file, whose name extension is **.heapsnapshort**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 401 | Parameter error. The filepath is invalid.                      |

**Example**

```js
let context = this.getUIContext().getHostContext();
let files: Array<string> = jsLeakWatcher.dump(context?.filesDir);
```


## jsLeakWatcher.enableLeakWatcher<sup>20+</sup>

enableLeakWatcher(isEnabled: boolean, configs: Array&lt;string&gt;, callback: Callback&lt;Array&lt;string&gt;&gt;): void

Enables the detection for JS object leaks. This function is disabled by default.

This API can detect the JS object memory leak, which is simpler than the method that needs to call the **enable**, **watch**, **check**, and **dump** functions.

If a memory leak occurs, the leaked file is returned through the callback.


**System capability**: SystemCapability.HiviewDFX.HiChecker

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| isEnabled | boolean | Yes| Whether to enable the detection for JS object memory leaks. The value **true** means to enable the detection for JS object memory leaks, and **false** means the opposite.|
| configs | array&lt;string&gt; | Yes| Configuration item. Each element in the array indicates a specific monitored object type.<br>Configurable items: **XComponent**, **NodeContainer**, **Window**, Custom Component, and **Ability**.|
| callback | Callback&lt;Array&lt;string&gt;&gt; | Yes| Callback used to receive the memory-leaked object returned by the **jsLeakWatcher.enableLeakWatcher** API.<br>You need to input an array object in the callback. Index 0 is the name of the leak list file, whose suffix is **.jsleaklist**. Index 1 is the name of the VM memory snapshot file, whose suffix is **.heapsnapshort**.|


**Error codes**

For details, see [JsLeakWatcher Error Codes](./errorcode-jsleakwatcher.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 10801001 | The parameter isEnabled is invalid.                              |
| 10801002 | The parameter config is invalid.                                 |
| 10801003 | The parameter callback is invalid. Input parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |

**Example**

<!--code_no_check-->
```ts
let config: Array<string> = ['XComponent'];
// Monitor the memory leak of the JS object XComponent.
jsLeakWatcher.enableLeakWatcher(true, config, (filePath: Array<string>) => {
    console.info('JsLeakWatcher leaklistFileName:' + filePath[0]);
    console.info('JsLeakWatcher heapDumpFileName:' + filePath[1]);
});
```
