# Class (Int16Array)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->
> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This module can be imported only to ArkTS files (with the file name extension .ets).

A linear data structure that is implemented on [ArkTS ArrayBuffer](arkts-apis-arkts-collections-ArrayBuffer.md).

**Decorator**: \@Sendable

## Modules to Import

```ts
import { collections } from '@kit.ArkTS';
```

## Properties

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name  | Type  | Read Only| Optional| Description             |
| ------ | ------ | ---- | ---- | ----------------|
| buffer | ArrayBuffer | Yes  | No | Bottom-layer buffer used by an ArkTS Int16Array.|
| byteLength | number | Yes  | No  | Number of bytes occupied by an ArkTS Int16Array.|
| byteOffset | number | Yes  | No  | Offset between the ArkTS Int16Array and the start position of the ArrayBuffer.|
| length | number | Yes  | No | Number of elements in an ArkTS Int16Array.|
| BYTES_PER_ELEMENT | number | Yes  | No  | Number of bytes occupied by each element in the ArkTS Int16Array.|

## constructor
constructor()

A constructor used to create an empty ArkTS Int16Array.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 10200012 | The Int16Array's constructor cannot be directly invoked. |

**Example**

```ts
let int16Array: collections.Int16Array = new collections.Int16Array();
```

## constructor
constructor(length: number)

A constructor used to create an ArkTS Int16Array of a given length.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| length | number | Yes| Length of the ArkTS Int16Array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                 |
| -------- | -------------------------------------------------------  |
| 401      | Parameter error.                                         |
| 10200012 | The Int16Array's constructor cannot be directly invoked. |


**Example**

```ts
// Construct an object with the length parameter.
let int16Array: collections.Int16Array = new collections.Int16Array(12);
```

## constructor
constructor(elements: Iterable\<number>)

A constructor that creates an ArkTS Int16Array from an iterable object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| elements |  Iterable\<number> | Yes| An iterable collection of numbers used to construct an ArkTS Int16Array object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error.                                         |
| 10200012 | The Int16Array's constructor cannot be directly invoked. |

**Example**

```ts
// Construct objects from an iterable object.
let set: Set<number> = new Set<number>([1, 2, 3]);
let array: collections.Int16Array = new collections.Int16Array(set);
// Int16Array [1, 2, 3]
```

## constructor
constructor(array: ArrayLike\<number> | ArrayBuffer)

A constructor that creates an ArkTS Int16Array from an array-like object or ArkTS ArrayBuffer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| array |  ArrayLike\<number> \| ArrayBuffer | Yes| Object used to construct the ArkTS Int16Array. When the parameter type is ArrayBuffer, the number of bytes occupied by the buffer must be an integer multiple of 4.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error.                                         |
| 10200012 | The Int16Array's constructor cannot be directly invoked. |

**Example**

```ts
// Example 1: Construct an object from an array-like object.
let arrayLike = [1, 3, 5];
let array: collections.Int16Array = new collections.Int16Array(arrayLike);
```

```ts
// Example 2: Construct an object from an ArrayBuffer.
let arrayBuffer: collections.ArrayBuffer = new collections.ArrayBuffer(12);
let array: collections.Int16Array = new collections.Int16Array(arrayBuffer);
```

```ts
// Example 3: Construct an object from another ArkTS Int16Array.
let arrayLike = [1, 3, 5];
// int16Array1 [1, 3, 5]
let int16Array1: collections.Int16Array = new collections.Int16Array(arrayLike);
// int16Array2 [1, 3, 5]
let int16Array2: collections.Int16Array = new collections.Int16Array(int16Array1);
```

## constructor
constructor(buffer: ArrayBuffer, byteOffset?: number, length?: number)

A constructor that creates an ArkTS Int16Array from an ArrayBuffer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                        |
| ------- | ------ | ---- | ------------------------------------------ |
| buffer | ArrayBuffer | Yes| ArrayBuffer object used to construct the ArkTS Int16Array. The number of bytes occupied by the buffer must be an integer multiple of 4.|
| byteOffset | number | No| Byte offset of the buffer, beginning at 0. The default value is **0**.|
| length | number | No| Length of the ArkTS Int16Array. The default value is **0**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                  |
| -------- | -------------------------------------------------------   |
| 401      | Parameter error.                                         |
| 10200012 | The Int16Array's constructor cannot be directly invoked. |

**Example**

```ts
let int16Array: collections.Int16Array = collections.Int16Array.from([1, 2, 3, 4, 5, 6]);
console.info("byteLength: " + int16Array.buffer.byteLength); // byteLength: 12
// Start from the second byte of the buffer corresponding to int16Array. The length is 5.
let int16Array1: collections.Int16Array = new collections.Int16Array(int16Array.buffer, 2, 5);
console.info("[" + int16Array1 + "]"); // [2, 3, 4, 5, 6]
```

## from
static from(arrayLike: ArrayLike\<number>): Int16Array

Creates an ArkTS Int16Array from an array-like or iterator object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                 |
| ------- | ------ | ---- | --------------------------------------------------- |
| arrayLike | ArrayLike\<number> | Yes| Array-like object used to construct the ArkTS Int16Array.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| Int16Array | New ArkTS Int16Array generated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                 |
| -------- | -------------------------------------------------------  |
| 401      | Parameter error.                                         |

**Example**
```ts
let arrayLike = [1, 3, 5];
let array: collections.Int16Array = collections.Int16Array.from(arrayLike); // array [1, 3, 5]
```

## from
static from\<T>(arrayLike: ArrayLike\<T>, mapFn: TypedArrayFromMapFn\<T, number>): Int16Array

Creates an ArkTS Int16Array from an array-like object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name | Type  | Mandatory| Description                                       |
| ------- | ------ | ---- | ------------------------------------------|
| arrayLike | ArrayLike\<T> | Yes| Array-like object used to construct the ArkTS Int16Array.             |
| mapFn | [TypedArrayFromMapFn](arkts-apis-arkts-collections-Types.md#typedarrayfrommapfn)\<T, number> | Yes| Mapping function.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| Int16Array | New ArkTS Int16Array generated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                 |
| -------- | -------------------------------------------------------  |
| 401      | Parameter error.                                         |

**Example**

```ts
// Example 1: Create an ArkTS Int16Array from an object.
let array: collections.Int16Array = collections.Int16Array.from<number>(
  { length: 5 }, (v: Object, k: number) => k);
// Int16Array [0, 1, 2, 3, 4]
```

```ts
// Example 2: Create an ArkTS Int16Array from a string array.
let array: collections.Int16Array = collections.Int16Array.from<string>(
  ["1", "3", "5"], (v: string, k: number) => parseInt(v));
// Int16Array [1, 3, 5]
```

```ts
// Example 3: Create an ArkTS Int16Array from a string.
let array: collections.Int16Array = collections.Int16Array.from<string>(
  "12345", (v: string, k: number) => parseInt(v));
// Int16Array [1, 2, 3, 4, 5]
```

## from
static from(arrayLike: Iterable\<number>, mapFn?: TypedArrayFromMapFn\<number, number>): Int16Array

Creates an ArkTS Int16Array from an iterator object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name | Type  | Mandatory| Description                               |
| ------- | ------ | ---- | -----------------------------------|
| arrayLike | Iterable\<number> | Yes| Iterator object used to construct the ArkTS Int16Array.  |
| mapFn | [TypedArrayFromMapFn](arkts-apis-arkts-collections-Types.md#typedarrayfrommapfn)\<number, number> | No| Mapping function. If no value is passed in, no special processing is conducted on the elements.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| Int16Array | New ArkTS Int16Array generated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                 |
| -------- | -------------------------------------------------------  |
| 401      | Parameter error.                                         |

**Example**

```ts
// Example 1: No mapping function is specified.
let set: Set<number> = new Set<number>([1, 2, 3]);
let array: collections.Int16Array = collections.Int16Array.from(set);
// Int16Array [1, 2, 3]
```

```ts
// Example 2: A mapping function is specified.
let set: Set<number> = new Set<number>([1, 2, 3]);
let array: collections.Int16Array = collections.Int16Array.from(
  set, (v: number, k: number) => v + k);
// Int16Array [1, 3, 5]
```

## of<sup>18+</sup>

static of(...items: number[]): Int16Array

Creates an ArkTS Int16Array with a variable number of parameters.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type         | Mandatory| Description                           |
| --------- | ------------- | ---- | ------------------------------- |
| items | number[] | No  | Array of elements used to create the array. The number of elements can be zero, one, or more.|

**Return value**

| Type     | Description                   |
| --------- | ----------------------- |
| Int16Array | New ArkTS Int16Array instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |

**Example**

```ts
let arr: collections.Int16Array = collections.Int16Array.of(1, 2, 3, 4);
console.info(arr.toString()); // Expected output: 1,2,3,4
```

## toString<sup>18+</sup>

toString(): string

Converts an ArkTS Int16Array to a string.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type        | Description           |
| ---------- | ------------- |
| string | A string that contains all elements of the array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID   | Error Message                                |
| -------- | ------------------------------------ |
| 10200011 | The toString method cannot be bound. |
| 10200201 | Concurrent modification error.       |

**Example**

```ts
let array = new collections.Int16Array([1, 2, 3, 4, 5]);
let stringArray = array.toString();
console.info(stringArray); // Expected output: 1,2,3,4,5
```

## toLocaleString<sup>18+</sup>

toLocaleString(): string

Generates a string of digits that matches the cultural conventions of the current system locale. Each element converts its digits to a string via its **toLocaleString** API, and these strings are then joined in sequence with commas (,).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type        | Description           |
| ---------- | ------------- |
| string | A string that contains all elements of the array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID   | Error Message                                      |
| -------- | ------------------------------------------ |
| 10200011 | The toLocaleString method cannot be bound. |
| 10200201 | Concurrent modification error.             |

**Example**

```ts
// The system where the application is running is set to the French locale.
let array = new collections.Int16Array([1000, 2000, 3000]);
let stringArray = array.toLocaleString();
console.info(stringArray); // Expected output: 1,000, 2,000, 3,000
```

## copyWithin
copyWithin(target: number, start: number, end?: number): Int16Array

Copies elements within a given range from this ArkTS Int16Array to another position in sequence.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| target | number | Yes| Start index of the range. If a negative number is passed in, it refers to the index of `target + array.length`.|
| start | number | Yes| Start index of the range. If a negative number is passed in, it refers to the index of `start + Int16Array.length`.|
| end | number | No| End index of the range (exclusive). If a negative number is passed in, it refers to the index of `end + Int16Array.length`. The default value is the length of the ArkTS Int16Array.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| Int16Array | ArkTS Int16Array after being modified.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------ |
| 401      | Parameter error.                                 |
| 10200011 | The copyWithin method cannot be bound.           |
| 10200201 | Concurrent modification error.               |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([1, 2, 3, 4, 5, 6, 7, 8]);
let copied: collections.Int16Array = array.copyWithin(3, 1, 3);
// Int16Array [1, 2, 3, 2, 3, 6, 7, 8]
```

## some
some(predicate: TypedArrayPredicateFn\<number, Int16Array>): boolean

Checks whether any element in this ArkTS Int16Array meets a given condition.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                 |
| ------- | ------ | ---- | ---------------------------------------------------- |
| predicate | [TypedArrayPredicateFn](arkts-apis-arkts-collections-Types.md#typedarraypredicatefn)\<number, Int16Array> | Yes| Assertion function used for the test.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| boolean | Check result. The value **true** is returned if an element meeting the given condition exists; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                           |
| -------- | ---------------------------------- |
| 401      | Parameter error.                   |
| 10200011 | The some method cannot be bound.   |
| 10200201 | Concurrent modification error. |

**Example**

```ts
let arrayLike = [-10, 20, -30, 40, -50];
let int16Array: collections.Int16Array = new collections.Int16Array(arrayLike);
int16Array.some((element: number) => element < 0); // true
```

## every
every(predicate: TypedArrayPredicateFn\<number, Int16Array>): boolean

Checks whether all elements in this ArkTS Int16Array meet a given condition.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                   |
| ------- | ------ | ---- | ----------------------------------------------------- |
| predicate | [TypedArrayPredicateFn](arkts-apis-arkts-collections-Types.md#typedarraypredicatefn)\<number, Int16Array> | Yes| Assertion function used for the test.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| boolean | Check result. The value **true** is returned if all elements meet the given condition; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                  |
| 10200011 | The every method cannot be bound. |
| 10200201 | Concurrent modification error. |

**Example**

```ts
let arrayLike = [-10, 20, -30, 40, -50];
let int16Array: collections.Int16Array = new collections.Int16Array(arrayLike);
int16Array.every((element: number) => element > 0);  // false
```

## fill
fill(value: number, start?: number, end?: number): Int16Array

Fills all elements in a given range in this ArkTS Int16Array with a value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                     |
| ------- | ------ | ---- | --------------------------------------------------------|
| value | number | Yes| Value to fill in.|
| start | number | No| Start index of the range. If a negative number is passed in, it refers to the index of `start + Int16Array.length`. The default value is **0**.|
| end | number | No| End index of the range (exclusive). If a negative number is passed in, it refers to the index of `end + Int16Array.length`. The default value is the length of the ArkTS Int16Array.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| Int16Array | Filled ArkTS Int16Array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                 |
| 10200011 | The fill method cannot be bound. |
| 10200201 | Concurrent modification error. |

**Example**

```ts
let arrayLike = [1, 2, 3];
new collections.Int16Array(arrayLike).fill(4); // Int16Array [4, 4, 4]
new collections.Int16Array(arrayLike).fill(4, 1); // Int16Array [1, 4, 4]
new collections.Int16Array(arrayLike).fill(4, 1, 2); // Int16Array [1, 4, 3]
```

## filter
filter(predicate: TypedArrayPredicateFn\<number, Int16Array>): Int16Array

Returns a new ArkTS Int16Array that contains all elements that meet the given condition.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                   |
| ------- | ------ | ---- | ------------------------------------------------------ |
| predicate | [TypedArrayPredicateFn](arkts-apis-arkts-collections-Types.md#typedarraypredicatefn)\<number, Int16Array> | Yes| Assertion function used for the test.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| Int16Array| Filtered ArkTS Int16Array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                   |
| 10200011 | The filter method cannot be bound. |
| 10200201 | Concurrent modification error. |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([0, 1, 2, 3, 4]);
let filtered: collections.Int16Array = array.filter((element: number) => element % 2 == 0);
// Int16Array [0, 2, 4]
```

## find
find(predicate: TypedArrayPredicateFn\<number, Int16Array>): number | undefined

Returns the value of the first element that passes a test provided by a callback function. If none of the elements pass the test, **undefined** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| predicate | [TypedArrayPredicateFn](arkts-apis-arkts-collections-Types.md#typedarraypredicatefn)\<number, Int16Array> | Yes| Assertion function used for the test.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
|  number \| undefined | Value of the first element that passes the test. If none of the elements pass the test, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                 |
| 10200011 | The find method cannot be bound. |
| 10200201 | Concurrent modification error. |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([0, 1, 2, 3, 4]);
array.find((element: number) => element > 2); // 3
array.find((element: number) => element > 4); // undefined
```

## findIndex
findIndex(predicate: TypedArrayPredicateFn\<number, Int16Array>): number

Returns the index of the first element that passes a test provided by a callback function. If none of the elements pass the test, **-1** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| predicate | [TypedArrayPredicateFn](arkts-apis-arkts-collections-Types.md#typedarraypredicatefn)\<number, Int16Array> | Yes| Assertion function used for the test.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| number | Index of the first element that passes the test. If none of the elements pass the test, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                      |
| 10200011 | The findIndex method cannot be bound. |
| 10200201 | Concurrent modification error.  |

**Example**

```ts
const array: collections.Int16Array = collections.Int16Array.from([1, 2, 3, 4, 5]);
let foundIndex: number = array.findIndex((element: number) => element % 2 === 0); // 1
```

## forEach
forEach(callbackFn: TypedArrayForEachCallback\<number, Int16Array>): void

Calls a callback function for each element in this ArkTS Int16Array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| callbackFn | [TypedArrayForEachCallback](arkts-apis-arkts-collections-Types.md#typedarrayforeachcallback)\<number, Int16Array> | Yes| Callback function to run for each element.|


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                    |
| 10200011 | The forEach method cannot be bound. |
| 10200201 | Concurrent modification error. |

**Example**

```ts
let int16Array: collections.Int16Array = collections.Int16Array.from([1, 2, 3]);
int16Array.forEach((value: number, index: number, array: collections.Int16Array) => {
  console.info(`Element ${value} at index ${index}`);
});
```

## indexOf
indexOf(searchElement: number, fromIndex?: number): number

Returns the index of the first occurrence of a value in this ArkTS Int16Array. If the value is not found, **-1** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name       | Type  | Mandatory| Description                       |
| ------------- | ------ | ---- | ---------------------------|
| searchElement | number | Yes  | Value to search for.               |
| fromIndex     | number | No  | Index from which the search starts. The default value is **0**. If the index is greater than or equal to the length of the ArkTS Int16Array, **-1** is returned. If a negative number is passed in, the search starts from the end of the ArkTS Int16Array.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| number | Index of the first occurrence of the value. If the value is not found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                    |
| 10200011 | The indexOf method cannot be bound. |
| 10200201 | Concurrent modification error.                |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([3, 5, 9]);
array.indexOf(3); // 0
array.indexOf(7); // -1
array.indexOf(9, 2); // 2
array.indexOf(9, -2); // 2
```

## lastIndexOf<sup>18+</sup>

lastIndexOf(searchElement: number, fromIndex?: number): number

Obtains the index of the last occurrence of the specified value in this ArkTS Int16Array.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name          | Type    | Mandatory | Description                                                                               |
| ------------- | ------ | --- | --------------------------------------------------------------------------------- |
| searchElement | number | Yes  | Value to search for.                                                                           |
| fromIndex     | number | No  | Index from which the search starts. The default value is **0**. If the index is greater than or equal to the length of the ArkTS Int16Array, **-1** is returned. If a negative number is passed in, the search starts from the end of the ArkTS Int16Array.|

**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| number | Index of the last occurrence of the value. If the value is not found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID   | Error Message                                   |
| -------- | --------------------------------------- |
| 10200011 | The lastIndexOf method cannot be bound. |
| 10200201 | Concurrent modification error. |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([3, 5, 9]);
console.info(array.lastIndexOf(3) + ''); // Expected output: 0
console.info(array.lastIndexOf(7) + ''); // Expected output: -1
console.info(array.lastIndexOf(9, 2) + ''); // Expected output: 2
console.info(array.lastIndexOf(9, -2) + ''); // Expected output: -1
```

## join
join(separator?: string): string

Concatenates all elements in this ArkTS Int16Array into a string, with a given separator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                                                |
| --------- | ------ | ---- | ---------------------------------------------------- |
| separator | string | No  | Separator to be used. If no value is passed in, a comma (,) is used as the separator.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| string | String obtained. If the array is empty, an empty string is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                 |
| 10200011 | The join method cannot be bound. |
| 10200201 | Concurrent modification error.  |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([1, 2, 3, 4, 5]);
let joined: string = array.join('-'); // "1-2-3-4-5"
```

## map
map(callbackFn: TypedArrayMapCallback\<number, Int16Array>): Int16Array

Applies a callback function to each element in this ArkTS Int16Array and uses the result to create an ArkTS Int16Array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name   | Type  | Mandatory| Description                                                |
| --------- | ------ | ---- | ---------------------------------------------------- |
| callbackFn | [TypedArrayMapCallback](arkts-apis-arkts-collections-Types.md#typedarraymapcallback)\<number, Int16Array> | Yes | Callback function to run for each element.|


**Return value**

| Type        | Description     |
| ------------ | --------- |
| Int16Array | New ArkTS Int16Array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                |
| 10200011 | The map method cannot be bound. |
| 10200201 | Concurrent modification error. |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([25, 36, 49]);
const mapped: collections.Int16Array = array.map(Math.sqrt); // Int16Array [5, 6 ,7]
```

## reduce
reduce(callbackFn: TypedArrayReduceCallback\<number, number, Int16Array>): number

Applies a reduce function on each element in this ArkTS Int16Array and returns the final reduction result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name    | Type  | Mandatory|  Description    |
| ---------- | ---------------------- | ---- | ------------------------------------------------------------ |
| callbackFn | [TypedArrayReduceCallback](arkts-apis-arkts-collections-Types.md#typedarrayreducecallback)\<number, number, Int16Array> | Yes| Reduce function.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| number | Final result obtained from the last call of the reduce function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID|                      Error Message                    |
| -------- | ------------------------------------------------ |
| 401      | Parameter error.                                 |
| 10200011 | The reduce method cannot be bound.               |
| 10200201 | Concurrent modification error.               |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([1, 2, 3, 4, 5]);
let reducedValue: number = array.reduce((accumulator: number, value: number) => accumulator + value);
// reducedValue == 15
```

## reduceRight<sup>18+</sup>

reduceRight(callbackFn: TypedArrayReduceCallback\<number, number, Int16Array>): number

Reversely traverses this ArkTS Int16Array, applies a reduce function on each element in the array, and returns the final reduction result.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name    | Type  | Mandatory|  Description    |
| ---------- | ---------------------- | ---- | ------------------------------------------------------------ |
| callbackFn | [TypedArrayReduceCallback](arkts-apis-arkts-collections-Types.md#typedarrayreducecallback)\<number, number, Int16Array> | Yes| Reduce function.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| number | Final result obtained from the last call of the reduce function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID   | Error Message                                   |
| -------- | --------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 10200011 | The reduceRight method cannot be bound. |
| 10200201 | Concurrent modification error.      |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([1, 2, 3, 4, 5]);
let reducedValue: number = array.reduceRight((accumulator: number, value: number) => accumulator + value);
console.info(reducedValue + ''); // Expected output: 15
```

## reduce
reduce(callbackFn: TypedArrayReduceCallback\<number, number, Int16Array>, initialValue: number): number

Applies a reduce function for each element in this ArkTS Int16Array, receives an initial value as the parameter called by the reduce function for the first time, and returns the final reduction result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name   | Type  | Mandatory| Description                                                |
| --------- | ------ | ---- | --------------------------------------------------- |
| callbackFn | [TypedArrayReduceCallback](arkts-apis-arkts-collections-Types.md#typedarrayreducecallback)\<number, number, Int16Array> | Yes | Reduce function.|
| initialValue | number | Yes | Initial value.|


**Return value**

| Type        | Description     |
| ------------ | --------- |
| number | Final result obtained from the last call of the reduce function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                   |
| 10200011 | The reduce method cannot be bound. |
| 10200201 | Concurrent modification error. |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([1, 2, 3, 4, 5]);
let reducedValue: number = array.reduce((accumulator: number, value: number) => accumulator + value, 1);
// reducedValue == 16
```

## reduceRight<sup>18+</sup>

reduceRight\<U = number>(callbackFn: TypedArrayReduceCallback\<U, number, Int16Array>, initialValue: U): U

Reversely traverses this ArkTS Int16Array, applies a reduce function for each element in the array, receives an initial value as the parameter called by the reduce function for the first time, and returns the final reduction result.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name   | Type  | Mandatory| Description                                                |
| --------- | ------ | ---- | --------------------------------------------------- |
| callbackFn | [TypedArrayReduceCallback](arkts-apis-arkts-collections-Types.md#typedarrayreducecallback)\<U, number, Int16Array> | Yes | Reduce function.|
| initialValue | U | Yes | Initial value.|

**Return value**

| Type    | Description         |
| ------ | ----------- |
| U | Final result obtained from the last call of the reduce function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID   | Error Message                                   |
| -------- | --------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 10200011 | The reduceRight method cannot be bound. |
| 10200201 | Concurrent modification error.      |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([1, 2, 3, 4, 5]);
let reducedValue: number = array.reduceRight((accumulator: number, value: number) => accumulator + value, 1);
console.info(reducedValue + ''); // Expected output: 16
```

## reduce
reduce\<U>(callbackFn: TypedArrayReduceCallback\<U, number, Int16Array>, initialValue: U): U

Applies a reduce function for each element in this ArkTS Int16Array, receives an initial value as the parameter called by the reduce function for the first time, and returns the final reduction result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                                                |
| --------- | ------ | ---- | ---------------------------------------------------- |
| callbackFn | [TypedArrayReduceCallback](arkts-apis-arkts-collections-Types.md#typedarrayreducecallback)\<U, number, Int16Array> | Yes | Reduce function.|
| initialValue | U | Yes | Initial value.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
|  U | Final result obtained from the last call of the reduce function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                   |
| 10200011 | The reduce method cannot be bound. |
| 10200201 | Concurrent modification error.  |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([1, 2, 3, 4, 5]);
let reducedValue: string = array.reduce<string>((accumulator: string, value: number) => accumulator + value, "initialValue");
// reducedValue == initialValue12345
```

## reverse
reverse(): Int16Array

Reverses this ArkTS Int16Array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type        | Description     |
| ------------ | --------- |
| Int16Array   | Reversed ArkTS Int16Array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The reverse method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([1, 2, 3, 4, 5]);
let reversed: collections.Int16Array = array.reverse(); // Int16Array [5, 4, 3, 2, 1]
```

## set
set(array: ArrayLike\<number>, offset?: number): void

Writes the elements in an array-like object to the given start position in sequence.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name   | Type  | Mandatory| Description                                                |
| --------- | ------ | ---- | ---------------------------------------------------- |
| array | ArrayLike\<number> | Yes | Array-like object whose elements will be written.|
| offset | number | No | Start position for writing data. The default value is **0**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                |
| 10200011 | The set method cannot be bound. |
| 10200201 | Concurrent modification error.  |

**Example**

```ts
let buffer: collections.ArrayBuffer = new collections.ArrayBuffer(16);
let array: collections.Int16Array = new collections.Int16Array(buffer);
array.set([1, 2, 3], 3); // Int16Array [0, 0, 0, 1, 2, 3, 0, 0]
```

## slice
slice(start?: number, end?: number): Int16Array

Selects a range of elements in this ArkTS Int16Array to create an ArkTS Int16Array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                                                  |
| ------ | ------ | ---- | -----------------------------------------------------|
| start  | number | No  | Start index of the range. If a negative number is passed in, it refers to the index of `start + Int16Array.length`. The default value is **0**.|
| end    | number | No  | End index of the range (exclusive). If a negative number is passed in, it refers to the index of `end + Int16Array.length`. The default value is the length of the ArkTS Int16Array.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| Int16Array | New ArkTS Int16Array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                  |
| 10200011 | The slice method cannot be bound. |
| 10200201 | Concurrent modification error. |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([1, 2, 3, 4, 5]);
array.slice(); // Int16Array [1, 2, 3, 4, 5]
array.slice(1, 3); // Int16Array [2, 3]
array.slice(-2); // Int16Array [4, 5]
```

## sort
sort(compareFn?: TypedArrayCompareFn\<number>): Int16Array

Sorts elements in this ArkTS Int16Array and returns the sorted ArkTS Int16Array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type                  | Mandatory| Description                                      |
| --------- | ---------------------- | ---- | ------------------------------------------ |
| compareFn | [TypedArrayCompareFn](arkts-apis-arkts-collections-Types.md#typedarraycomparefn)\<number> | No  | Function that determines the sort order. By default, elements are sorted in ascending order.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| Int16Array | Sorted ArkTS Int16Array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------ |
| 401      | Parameter error.                 |
| 10200011 | The sort method cannot be bound. |
| 10200201 | Concurrent modification error.         |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([1, 3, 5, 4, 2]);
array.sort(); // Int16Array [1, 2, 3, 4, 5]
array.sort((a: number, b: number) => a - b); // Int16Array [1, 2, 3, 4, 5]
array.sort((a: number, b: number) => b - a); // Int16Array [5, 4, 3, 2, 1]
```

## subarray
subarray(begin?: number, end?: number): Int16Array

Truncates an array from a specified position and returns a new ArkTS Int16Array based on the same ArkTS ArrayBuffer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                                               |
| ------ | ------ | ---- | ------------------------------------------------- |
| begin  | number | No  | Start index of the range. If a negative number is passed in, it refers to the index of `begin + Int16Array.length`. The default value is **0**.|
| end    | number | No  | End index of the range (exclusive). If a negative number is passed in, it refers to the index of `end + Int16Array.length`. The default value is the length of the ArkTS Int16Array.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| Int16Array | New ArkTS Int16Array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID|            Error Message                              |
| -------- | -------------------------------------------------|
| 401      | Parameter error.                                 |
| 10200011 | The subarray method cannot be bound.             |
| 10200201 | Concurrent modification error.               |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([1, 2, 3, 4, 5]);
let subArray: collections.Int16Array = array.subarray(); // Int16Array [1, 2, 3, 4, 5]
subArray.set([10, 20, 30]); // Int16Array [10, 20, 30, 4, 5]
```

## at
at(index: number): number | undefined

Returns the element at the given index. If no element is found, **undefined** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| index  | number | Yes  | Index of the element. The index in an array always starts from 0 and is an integer. If a negative number is passed in, it refers to the index of `index + Int16Array.length`.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| number \| undefined| Element obtained. If no element is found, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID|                       Error Message                   |
| -------- | ------------------------------------------------ |
| 401      | Parameter error.                                 |
| 10200011 | The at method cannot be bound.                   |
| 10200201 | Concurrent modification error.               |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([1, 2, 3, 4, 5]);
console.info("element: " + array.at(2));  // element: 3
console.info("element: " + array.at(-1)); // element: 5
console.info("element: " + array.at(6));  // element: undefined
```

## includes
includes(searchElement: number, fromIndex?: number): boolean

Checks whether elements are contained in this ArkTS Int16Array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name| Type  | Mandatory| Description                                     |
| ------ | ------ | ---- | --------------------------------------- |
| searchElement  | number | Yes  | Element to search for.|
| fromIndex  | number | No | Index from which the search starts. If a negative number is passed in, it refers to the index of `fromIndex + Int16Array.length`. The default value is **0**.|

**Return value**

| Type   | Description                                                       |
| ------- | ---------------------------------------------------------- |
| boolean | Check result. The value **true** is returned if the element exists; otherwise, **false** is returned.|


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                     |
| 10200011 | The includes method cannot be bound. |
| 10200201 | Concurrent modification error. |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([1, 2, 3]);
console.info("includes: " + array.includes(2));    // includes: true
console.info("includes: " + array.includes(4));    // includes: false
console.info("includes: " + array.includes(3, 3)); // includes: false
```

## entries
entries(): IterableIterator\<[number, number]>

Returns an iterator object that contains the key-value pair of each element in this ArkTS Int16Array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type        | Description     |
| ------------ | --------- |
| IterableIterator\<[number, number]>| Iterator object.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The entries method cannot be bound. |
| 10200201 | Concurrent modification error. |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([11, 22, 33]);
let iterator: IterableIterator<[number, number]> = array.entries();
console.info("value: " + iterator.next().value); // value: 0,11
console.info("value: " + iterator.next().value); // value: 1,22
console.info("value: " + iterator.next().value); // value: 2,33
```

## keys
keys(): IterableIterator\<number>

Returns an iterator object that contains the key (index) of each element in this ArkTS Int16Array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type        | Description     |
| ------------ | --------- |
| IterableIterator\<number> | Iterator object.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The keys method cannot be bound. |
| 10200201 | Concurrent modification error. |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([1, 2, 3, 4, 5]);
let iterator: IterableIterator<number> = array.keys();
for (const key of iterator) {
  console.info("" + key); // 0, 1, 2, 3, and 4 are returned in sequence.
}
```

## values
values(): IterableIterator\<number>

Returns an iterator object that contains the value of each element in this ArkTS Int16Array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type        | Description     |
| ------------ | --------- |
| IterableIterator\<number> | Iterator object.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The values method cannot be bound. |
| 10200201 | Concurrent modification error.  |

**Example**

```ts
let array: collections.Int16Array = collections.Int16Array.from([1, 2, 3, 4, 5]);
let iterator: IterableIterator<number> = array.values();
for (const value of iterator) {
  console.info("" + value); // 1, 2, 3, 4, and 5 are returned in sequence.
}
```

## [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;number&gt;

Returns an iterator, each item of which is a JavaScript object.

> **NOTE**
>
> This API cannot be used in .ets files.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                     | Description            |
| ------------------------- | ---------------- |
| IterableIterator&lt;number&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**Example**

```ts
let int16Array: collections.Int16Array = collections.Int16Array.from([1, 2, 3, 4, 5, 6]);

for (let item of int16Array) {
  console.info(`value : ${item}`);
}
```

## [index: number]

&#91;index: number&#93;: number

Returns the element at a given index in this Int16Array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                    |
| ----- | ------ | ---- | -------------------------- |
| index | number | Yes  | Index of the element. The index starts from zero.|

**Return value**

| Type  | Description                |
| ----- | ---------------------|
| number | Number data type.|

**Example**

```ts
let int16Array = collections.Int16Array.from([1, 2, 4]);
console.info("Element at index 1: ", int16Array[1]);
```
