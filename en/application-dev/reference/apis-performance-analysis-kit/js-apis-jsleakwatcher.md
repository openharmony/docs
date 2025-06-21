# @ohos.hiviewdfx.jsLeakWatcher (JS Leak Watcher)

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

Enables the detection for JS object leak. This function is disabled by default.

**System capability**: SystemCapability.HiviewDFX.HiChecker

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| isEnable | boolean | Yes| Whether to enable **jsLeakWatcher**.|

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
