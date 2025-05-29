# Console

The **console** module provides a simple debugging console, which is similar to the JavaScript console provided by the browser.

> **NOTE**
>
> The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## console.debug

debug(message: string, ...arguments: any[]): void

Prints debugging information in formatted output mode.

This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| message | string | Yes   | Text to be printed.|
| arguments | any[] | No   | Arguments in the message or other information to be printed.|

**Example**

```js
const number = 5;
console.debug('count: %d', number);  // Print the debugging information with arguments in the message replaced.
// count: 5 
console.debug('count:', number);  // Print the message and other information.
// count: 5 
console.debug('count:'); // Print the message only.
// count: 
```

## console.log

log(message: string, ...arguments: any[]): void

Prints log information in formatted output mode.

This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| message | string | Yes   | Text to be printed.|
| arguments | any[] | No   |Arguments in the message or other information to be printed.|

**Example**

```js
const number = 5;
console.log('count: %d', number);  // Print the log information with arguments in the message replaced.
// count: 5 
console.log('count:', number);  // Print the message and other information.
// count: 5 
console.log('count:'); // Print the message only.
// count: 
```

## console.info

info(message: string, ...arguments: any[]): void

Prints log information in formatted output mode. This API is the alias of **console.log ()**.

This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| message | string | Yes   | Text to be printed.|
| arguments | any[] | No   | Arguments in the message or other information to be printed.|

**Example**

```js
const number = 5;
console.info('count: %d', number);  // Print the log information with arguments in the message replaced.
// count: 5 
console.info('count:', number);  // Print the message and other information.
// count: 5 
console.info('count:'); // Print the message only.
// count: 
```

## console.warn

warn(message: string, ...arguments: any[]): void

Prints warning information in formatted output mode.

This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| message | string | Yes   | Warning information to be printed.|
| arguments | any[] | No   | Arguments in the message or other information to be printed.|

**Example**

```js
const str = "name should be string";
console.warn('warn: %d', str); // Print the warning information with arguments in the message replaced.
// warn: name should be string
console.warn('warn:', str);  // Print the message and other information.
// warn: name should be string
console.warn('warn:'); // Print the message only.
// warn: 
```

## console.error

error(message: string, ...arguments: any[]): void

Prints error information in formatted output mode.

This API can be used in ArkTS widgets since API version 9.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| message | string | Yes   | Error information to be printed.|
| arguments | any[] | No   | Arguments in the message or other information to be printed.|


**Example**

```js
const str = "value is not defined";
console.error('error: %d', str);  // Print the error information with arguments in the message replaced.
// error: value is not defined
console.error('error:', str);  // Print the message and other information.
// error: value is not defined
console.error('error:'); // Print the message only.
// error: 
```

## console.assert<sup>10+</sup>

assert(value?: Object, ...arguments: Object[]): void

Prints assertion information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| value | Object | No   | Result value. If **value** is **false** or left blank, the output starting with "Assertion failed" is printed. If **value** is **true**, no information is printed.|
| arguments | Object | No   | Other information to be printed when **value** is **false**. If this parameter is left blank, other information is not printed.|

**Example**

```js
console.assert(true, 'does nothing');  // Do not print error information as value is true.
console.assert(2% 1 == 0,'does nothing');  // Do not print error information as value is true.

console.assert(false, 'console %s work', 'didn\'t');
// Assertion failed: console didn't work

console.assert();
// Assertion failed
```

## console.count<sup>10+</sup>

count(label?: string): void

Maintains an internal counter. When this counter is invoked, its label name and the corresponding call count are printed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| label | string | No   | Counter label name. The default value is **default**.|


**Example**

```js
console.count()
// default: 1
console.count('default')
// default: 2
console.count('abc')
// abc: 1
console.count('xyz')
// xyz: 1
console.count('abc')
// abc: 2
console.count()
// default: 3
```

## console.countReset<sup>10+</sup>

countReset(label?: string): void

Resets a counter based on the specified label name.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| label | string | No   | Counter label name. The default value is **default**.|

**Example**

```js
console.count('abc');
// abc: 1
console.countReset('abc');
console.count('abc');
// abc: 1
```

## console.dir<sup>10+</sup>

dir(dir?: Object): void

Prints content of the specified object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| dir | Object | No   | Object whose content needs to be printed. If this parameter is left blank, no information is printed.|


**Example**

```js
class bar {
  baz: boolean = true;
}
let b: bar = {baz: true}
class foo{
  bar: bar = b;
}
let c: foo = {bar: b}
class  c1{
  foo: foo = c;
}
let a: c1 = {foo: c}
console.dir(a);
// Object: {"foo":{"bar":{"baz":true}}}

console.dir(); // No information is printed.
```


## console.dirxml<sup>10+</sup>

dirxml(...arguments: Object[]): void 

Displays an interactive tree of the descendant elements of the specified XML element. This API is implemented by calling **console.log()** internally. It does not produce any XML elements. The usage method is the same as that of **console.log()**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| arguments | Object | Yes   | Information to be printed.|

**Example**

```js
const number = 5;
console.dirxml('count: %d', number);
// count: 5 
console.dirxml('count:', number);
// count: 5 
console.dirxml('count:');
// count: 
```

## console.group<sup>10+</sup>

group(...arguments: Object[]): void

Increases the indentation of subsequent lines by two spaces.
If the information to be printed is provided, the information is printed without extra indentation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| arguments | Object | No   | Information to be printed.|

**Example**

```js
console.log("outter");
// outter
console.group();
console.log("level 1");
//   level 1
console.group("in level1");
//   in level1
console.log("level 2");
//     level 2
```


## console.groupCollapsed<sup>10+</sup>

groupCollapsed(...arguments: Object[]): void

Creates a new inline group in collapsed mode. The usage and function of this API are the same as those of **console.group()**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| arguments | Object | No   | Information to be printed.|


**Example**

```js
console.groupCollapsed("outter");
// outter
console.groupCollapsed();
console.log("level 1");
//   level 1
console.groupCollapsed("in level1");
//   in level1
console.log("level 2");
//     level 2
```

## console.groupEnd<sup>10+</sup>

groupEnd(): void

Reduces the indentation of subsequent lines by two spaces.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang


**Example**

```js
console.log("outter");
// outter
console.group();
console.log("level 1");
//   level 1
console.groupEnd();
console.log("outter");
// outter
```


## console.table<sup>10+</sup>

table(tableData?: Object): void

Prints data in a table.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| tableData | Object | No   | Data to be printed in a table. If this parameter is left blank, no information is printed.|

**Example**

```js
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

Starts a timer to track the duration of an operation. You can use **console.timeEnd()** to close the timer and print the elapsed time (in ms).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| label | string | No   | Timer label. The default value is **default**.|

**Example**

```js
console.time('abc');
```

## console.timeEnd<sup>10+</sup>

timeEnd(label?: string): void

Stops the timer started by calling **console.time()** and prints the elapsed time (in ms).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| label | string | No   | Timer label. The default value is **default**.|

**Example**

```js
console.time('abc');
console.timeEnd('abc');
// abc: 225.438ms
```

## console.timeLog<sup>10+</sup>

timeLog(label?: string, ...arguments: Object[]): void

Prints the elapsed time and other data parameters for the timer started by **console.time()**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| label | string | No   | Timer label. The default value is **default**.|
| arguments | Object | No   | Logs to be printed.|

**Example**

```js
console.time('timer1');
console.timeLog('timer1', 17);
// timer1: 365.227ms 17
console.timeEnd('timer1');
// timer1: 513.22ms
```

## console.trace<sup>10+</sup>

static trace(...arguments: Object[]): void

Creates a stack trace.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type    | Mandatory  | Description         |
| ------- | ------ | ---- | ----------- |
| arguments | Object | No   | Logs to be printed. If this parameter is left blank, only stack information is printed.|

**Example**

```js
console.trace();
// Trace:
//     xxxxxxxxxx (current stack information)
console.trace("Show the trace");
// Trace: Show the trace
//     xxxxxxxxxx (current stack information)
```

## console.traceHybridStack<sup>12+</sup>

static traceHybridStack(): void

Prints information about the current hybrid stack of the calling thread in the main thread or worker thread.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
console.traceHybridStack();
// TraceHybridStack:
// xxxxxxxxxxxxx (information about the current hybrid stack of the calling thread)
```
