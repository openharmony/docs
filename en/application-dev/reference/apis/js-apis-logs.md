# Console

The **console** module provides a simple debugging console, which is similar to the JavaScript console provided by the browser.

> **NOTE**
>
> The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## console.debug

debug(message: string, ...arguments: any[]): void

Prints debugging information in formatted output mode.

Since API version 9, this API is supported in ArkTS widgets.

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

Since API version 9, this API is supported in ArkTS widgets.

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

Since API version 9, this API is supported in ArkTS widgets.

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

Since API version 9, this API is supported in ArkTS widgets.

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

Since API version 9, this API is supported in ArkTS widgets.

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
