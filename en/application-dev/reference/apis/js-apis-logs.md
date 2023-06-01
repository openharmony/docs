# Console

The **console** module provides basic log printing capabilities and supports log printing by log level.

If you want to use more advanced log printing services, for example, filtering logs by the specified ID, you are advised to use [`@ohos.hilog`](js-apis-hilog.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## console.debug

debug(message: string): void

Prints debug-level logs.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| message | string | Yes   | Text to print.|


## console.log

log(message: string): void

Prints debug-level logs.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| message | string | Yes   | Text to print.|


## console.info

info(message: string): void

Prints info-level logs.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| message | string | Yes   | Text to print.|


## console.warn

warn(message: string): void

Prints warn-level logs.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| message | string | Yes   | Text to print.|


## console.error

error(message: string): void

Prints error-level logs.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| message | string | Yes   | Text to print.|


**Example**

```
export default {    
  clickConsole(){        
    var versionCode = 1;        
    console.info('Hello World. The current version code is ' + versionCode);        
    console.log(`versionCode: ${versionCode}`);        
    / / The following is supported since API version 6: console.log('versionCode:%d.', versionCode);   
  }
}
```

Switch to the HiLog window at the bottom of HUAWEI DevEco Studio. Specifically, select the current device and process, set the log level to Info, and enter Hello World in the search box. Logs that meet the search criteria are displayed, as shown in the following figure.

![Printing logs](figures/printing-logs.png)

## console.assert<sup>10+</sup>

assert(value?: Object, ...arguments: Object[]): void

If **value** is false, the subsequent content will be printed.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| value | Object | No   | Value|
| arguments | Object | No   | Prints error messages.|

**Example**
```
console.assert(true, 'does nothing');

console.assert(false, 'console %s work', 'didn\'t');
// Assertion console:ohos didn't work

console.assert();
// Assertion failed
```
## console.count<sup>10+</sup>

count(label?: string): void

Adds a counter by the specified label name to count the number of times **console.count()** is called. The default value is **default**.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| label | string | No   | Counter label name.|

**Example**
```
console.count()
// default: 1
console.count('default')
// default: 2
console.count('abc')
// abc: 1
console.count('xyz')
// xyz: 1
console.count('abc')
abc: 2
console.count()
// default: 3
```

## console.countReset<sup>10+</sup>

countReset(label?: string): void

Resets a counter by the specified label name. The default value is **default**.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| label | string | No   | Counter label name.|

**Example**
```
console.count('abc');
// abc: 1
console.countReset('abc');
console.count('abc');
// abc: 1
```

## console.dir<sup>10+</sup>

dir(dir?: Object): void

Prints content of the specified object.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| dir | Object | No   | Object whose content needs to be printed.|

## console.dirxml<sup>10+</sup>

dirxml(...arguments: Object[]): void 

Calls **console.log()** and passes the received parameters to it. This API does not produce any content of the XML format.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| arguments | Object | No   | Information to be printed.|

## console.group<sup>10+</sup>

group(...arguments: Object[]): void

Creates an inline group so that subsequent lines are indented by the value specified by **groupIndentation**.
If the information to be printed is provided, the information is printed without extra indentation.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| arguments | Object | No   | Information to be printed.|
## console.groupCollapsed<sup>10+</sup>

groupCollapsed(...arguments: Object[]): void

Creates a collapsed inline group.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| arguments | Object | No   | Information to be printed.|

## console.groupEnd<sup>10+</sup>

groupEnd(): void

Exits an inline group so that subsequent lines are not indented by the value specified by **groupIndentation** .

**System capability**: SystemCapability.Utils.Lang

## console.table<sup>10+</sup>

table(tableData?: Object): void

Prints data in a table.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| tableData | Object | No   | Data to be printed in a table.|

**Example**
```
console.table([1, 2, 3]);
// ┌─────────┬────────┐
// │ (index) │ Values │
// ├─────────┼────────┤
// │    0    │   1    │
// │    1    │   2    │
// │    2    │   3    │ 
// └─────────┴────────┘

console.table({ a: [1, 2, 3, 4, 5], b: 5, c: { e: 5 } });

// ┌─────────┬───┬───┬───┬───┬───┬───┬────────┐
// │ (index) │ 0 │ 1 │ 2 │ 3 │ 4 │ e │ Values │
// ├─────────┼───┼───┼───┼───┼───┼───┼────────┤
// │    a    │ 1 │ 2 │ 3 │ 4 │ 5 │   │        │
// │    b    │   │   │   │   │   │   │   5    │
// │    c    │   │   │   │   │   │ 5 │        │
// └─────────┴───┴───┴───┴───┴───┴───┴────────┘
```
## console.time<sup>10+</sup>

time(label?: string): void

Starts a timer to track the duration of an operation. The default value is **default**. You can use **console.timeEnd()** to disable the timer and print the result.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| label | string | No   | Timer label.|

## console.timeEnd<sup>10+</sup>

timeEnd(label?: string): void

Stops the timer started by **console.time()** and prints the result. The default value is **default**.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| label | string | No   | Timer label.|

**Example**
```
console.time('abc');
console.timeEnd('abc');
// abc: 225.438ms
```

## console.timeLog<sup>10+</sup>

timeLog(label?: string, ...arguments: Object[]): void

Prints the elapsed time and other logs for the timer started by **console.time()**.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| label | string | No   | Timer label.|
| arguments | Object | No   | Logs to be printed.|

**Example**
```
console.time('timer1');
const value = aaa (); // Return 17.
console.timeLog('timer1', value);
// timer1: 365.227ms 17
console.timeEnd('timer1');
// timer1: 513.22ms
```

## console.trace<sup>10+</sup>

trace(...arguments: Object[]): void

Creates a stack trace.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| arguments | Object | No   | Logs to be printed.|

**Example**
```
console.trace();
console.trace("Show the trace");
```
