# @arkts.collections (ArkTS Collections)

The collections module provides ArkTS containers for efficient data transfer in concurrency scenarios. The ArkTS containers provide similar functionalities as their JavaScript counterparts, except that their properties cannot be added or updated through \. or \[\].

By default, ArkTS containers are passed by reference between concurrent instances. This means that multiple concurrent instances can simultaneously operate the same container instance. Pass-by-copy is also supported. In this mode, each concurrent instance holds an ArkTS container instance.

ArkTS containers are not thread-safe. They adopt the fail-fast approach. An exception is thrown if multiple concurrent instances make structural changes to a container instance at the same time. Therefore, in update scenarios, you must use the ArkTS asynchronous lock to ensure secure access to the ArkTS containers.

Currently, the following ArkTS containers are provided: [Array](#collectionsarray), [Map](#collectionsmap), [Set](#collectionsset), [TypedArray](#collectionstypedarray), [ArrayBuffer](#collectionsarraybuffer), [BitVector](#collectionsbitvector), and [ConcatArray](#collectionsconcatarray).

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This module can be imported only to ArkTS files (with the file name extension .ets).

## Modules to Import

```ts
import { collections } from '@kit.ArkTS';
```

## ISendable

type ISendable = lang.ISendable

**ISendable** is the parent type of all sendable types except null and undefined. It does not have any necessary methods or properties.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Type| Description  |
| ------ | ------ |
| [lang.ISendable](js-apis-arkts-lang.md#langisendable)   | Parent type of all sendable types.|

## collections.ConcatArray
An array-like object that can be concatenated. This API extends **ISendable**.

This section uses the following to identify the use of generics:

- T: type, which can be any of the [sendable data types](../../arkts-utils/arkts-sendable.md#sendable-data-types).

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name  | Type  | Read Only| Optional| Description             |
| ------ | ------ | ---- | ---- | ----------------- |
| length | number | Yes  | No  | Number of elements in a ConcatArray.|

### [index: number]

readonly &#91;index: number&#93;: T

Returns the element at a given index in this ConcatArray.

**System capability**: SystemCapability.Utils.Lang

| Name   | Type  | Mandatory| Description                                                           |
| ----- | ------ | ---- | ------------------------------------------------------------------ |
| index | number | Yes  | Index of the element. The index starts from zero. If the passed-in index is less than 0 or greater than or equal to the value of **length**, an error is thrown.|

**Return value**

| Type  | Description                    |
| ----- | ------------------------ |
| T | Element in the ConcatArray.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                            |
| ------- | ------------------------------------ |
| 401 |  Parameter error. Illegal index.         |
| 10200001 | The value of index is out of range. |

**Example**

```ts
let concatArray : collections.ConcatArray<number> = new collections.Array<number>(1, 2, 4);
console.info("Element at index 1: ", concatArray[1]);
```

### join

join(separator?: string): string

Concatenates all elements in this array into a string, with a given separator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                                                |
| --------- | ------ | ---- | ---------------------------------------------------- |
| separator | string | No  | Separator to be used. If no value is passed in, a comma (,) is used as the separator.|

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| string | String obtained. If the array is empty, an empty string is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 |  Parameter error. Invalid separator. |

**Example**

```ts
let concatArray : collections.ConcatArray<string> = new collections.Array<string>('a', 'b', 'c');
let joinedString = concatArray.join('-'); // "a-b-c" is returned.
```

### slice

slice(start?: number, end?: number): ConcatArray\<T>

Selects a range of elements in this array to create an array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| start  | number | No  | Start index of the range. If a negative number is passed in, it refers to the index of **start + array.length**. The default value is **0**.  |
| end    | number | No  | End index of the range (exclusive). If a negative number is passed in, it refers to the index of **end + array.length**. The default value is the length of the ArkTS array.|

**Return value**

| Type     | Description                      |
| --------- | -------------------------- |
| ConcatArray\<T> | New array containing the selected elements.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 |  Parameter error. Invalid `start` or `end` parameters. |

**Example**

```ts
let concatArray : collections.ConcatArray<number> = new collections.Array<number>(1, 2, 3, 4, 5);
let slicedArray = concatArray.slice (1, 3); // [2, 3] is returned. The original array remains unchanged.
```

## ArrayFromMapFn<sup>18+</sup>
type ArrayFromMapFn<FromElementType, ToElementType> = (value: FromElementType, index: number) => ToElementType

Defines the ArkTS Array reduction function, which is used by the **from** API of the Array class.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 18.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| value | FromElementType | Yes| Element that is being processed.|
| index | number | Yes| Index of the element in the ArkTS array.|

**Return value**

| Type  | Description                         |
| ------ | --------------------------- |
| ToElementType | Result of the reduction function, which is used as a new element in the array.|

## ArrayPredicateFn</a><sup>18+</sup>
type ArrayPredicateFn<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => boolean

Defines the ArkTS Array reduction function, which is used by the **some** and **every** APIs of the Array class to determine whether array elements meet certain test conditions.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 18.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| value | ElementType | Yes| Element that is being processed.|
| index | number | Yes| Index of the element in the ArkTS array.|
| array | ArrayType | Yes| ArkTS array that is being traversed.|

**Return value**

| Type  | Description                         |
| ------ | --------------------------- |
| boolean | Result of the reduction function, indicating whether the current element meets the test condition. The value **true** means that the current element or a previous element meets the condition, and **false** means that no element meets the condition.|

## ArrayReduceCallback</a><sup>18+</sup>
type ArrayReduceCallback<AccType, ElementType, ArrayType> =
    (previousValue: AccType, currentValue: ElementType, currentIndex: number, array: ArrayType) => AccType

Defines the ArkTS Array reduction function, which is used by the **reduceRight** API of the Array class.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 18.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| previousValue | AccType | Yes| Accumulated value of the current traversal.|
| currentValue | ElementType | Yes| Element that is being traversed in the ArkTS array.|
| currentIndex | number | Yes| Index of the element in the ArkTS array.|
| array | ArrayType | Yes| ArkTS array that is being traversed.|

**Return value**

| Type  | Description                         |
| ------ | --------------------------- |
| AccType | Result of the reduction function, which is used as the **previousValue** parameter in the next call of **ArrayReduceCallback**.|

## collections.Array

A linear data structure that is implemented on arrays and can be passed between ArkTS concurrent instances.

Pass-by-reference is recommended for better transfer performance.

This section uses the following to identify the use of generics:

- T: type, which can be any of the [sendable data types](../../arkts-utils/arkts-sendable.md#sendable-data-types).

**Atomic service API**: This API can be used in atomic services since API version 12.

### Properties

**System capability**: SystemCapability.Utils.Lang

| Name  | Type  | Read Only| Optional| Description             |
| ------ | ------ | ---- | ---- | ----------------- |
| length | number | Yes  | No  | Number of elements in an ArkTS array.|


### constructor

 

constructor()

A constructor used to create an empty ArkTS array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                           |
| -------- | --------------------------------------------------- |
| 10200012 | The Array's constructor cannot be directly invoked. |

**Example**

```ts
let array = new collections.Array<number>();
```

### constructor

constructor(first: T, ...left: T[])

A constructor used to create an ArkTS array with the given elements.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description                           |
| ------ | ---- | ---- | ------------------------------- |
| first  | T    | Yes  | First element to be included in the ArkTS array.|
| left   | T[]  | No  | Remaining elements to be included in the ArkTS array.  |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                           |
| -------- | --------------------------------------------------- |
| 10200012 | The Array's constructor cannot be directly invoked. |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4);
```
### constructor

constructor(...items: T[])

A constructor used to create an ArkTS array with the given elements.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description                           |
| ------ | ---- | ---- | ------------------------------- |
| items  | T[]  | No  | Elements to be included in the ArkTS array.      |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                           |
| -------- | --------------------------------------------------- |
| 401      | Parameter error.                                    |
| 10200012 | The Array's constructor cannot be directly invoked. |

**Example**

```ts
let arrayPara  = [1,2,3];
let array = new collections.Array<number>(...arrayPara);
```

### create

static create\<T>(arrayLength: number, initialValue: T): Array\<T>

Creates an ArkTS array of a fixed length, with each element set to a given initial value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type         | Mandatory| Description                           |
| --------- | ------------- | ---- | ------------------------------- |
| arrayLength | number | Yes  | Length of the ArkTS array.|
| initialValue | T | Yes  | Initial value of each element in the ArkTS array.|

**Return value**

| Type     | Description                   |
| --------- | ----------------------- |
| Array\<T> | Newly created ArkTS array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 10200011 | The create method cannot be bound. |

**Example**

```ts
let array = collections.Array.create<number>(3, 10); // [10, 10, 10]
```

### from

static from\<T>(arrayLike: ArrayLike\<T>): Array\<T>

Creates an ArkTS array from an array-like object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type         | Mandatory| Description                           |
| --------- | ------------- | ---- | ------------------------------- |
| arrayLike | ArrayLike\<T> | Yes  | Array-like object.|

**Return value**

| Type     | Description                   |
| --------- | ----------------------- |
| Array\<T> | Newly created ArkTS array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 10200011 | The from method cannot be bound. |

**Example**

```ts
// Positive example:
let array: Array<string> = ['str1', 'str2', 'str3']; // Native Array<T>, where T is the sendable data type.
let sendableArray = collections.Array.from<string>(array); // Returns Sendable Array<T>.
```

<!--code_no_check-->
```ts
// Negative example:
let array: Array<Array<string>> = [['str1', 'str2', 'str3'], ['str4', 'str5', 'str6'], ['str7', 'str8', 'str9']]; // Native Array<T>, where T is a non-sendable data type.
let sendableArray = collections.Array.from<Array<string>>(array); // Prints the following exception information: Parameter error.Only accept sendable value
```

### from<sup>12+</sup>

static from\<T>(iterable: Iterable\<T>): Array\<T>

Creates an ArkTS array from an iterable object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type         | Mandatory| Description                           |
| --------- | ------------- | ---- | ------------------------------- |
| iterable | Iterable\<T> | Yes  | Array-like object.|

**Return value**

| Type     | Description                   |
| --------- | ----------------------- |
| Array\<T> | Newly created ArkTS array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The from method cannot be bound. |

**Example**

```ts
// Positive example:
const mapper = new Map([
  ['1', 'a'],
  ['2', 'b'],
]);
let newArray: collections.Array<string> = collections.Array.from(mapper.values());
console.info(newArray.toString());
// Expected output: a,b
```

### from<sup>18+</sup>

static from\<T>(arrayLike: ArrayLike\<T> | Iterable\<T>, mapFn: ArrayFromMapFn\<T, T>): Array\<T>

Creates an ArkTS array from an array-like object, and uses a custom function to process each array element.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type         | Mandatory| Description                           |
| --------- | ------------- | ---- | ------------------------------- |
| arrayLike | ArrayLike\<T> \| Iterable\<T> | Yes  | Array-like object.|
| mapFn | ArrayFromMapFn\<T,T> | Yes  | Functions used to process the array elements.|

**Return value**

| Type     | Description                   |
| --------- | ----------------------- |
| Array\<T> | Newly created ArkTS array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The from method cannot be bound. |

**Example**

```ts
let array : Array<number> = [1, 2, 3]; // Native Array<T>, where T is of the Sendable type.
let newarray = collections.Array.from<number, number>(array, (value, index) => value + index); // Return a new Array<T>.
console.info(newarray.toString());
// Expected output: 1, 3, 5
```

### from<sup>18+</sup>

static from\<U, T>(arrayLike: ArrayLike\<U> | Iterable\<U>, mapFn: ArrayFromMapFn\<U, T>): Array\<T>

Creates an ArkTS array from an array-like object, and uses a custom function to process each array element. The type of the elements in the array-like object can be different from that of the array elements.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type         | Mandatory| Description                           |
| --------- | ------------- | ---- | ------------------------------- |
| arrayLike | ArrayLike\<U> \| Iterable\<U> | Yes  | Array-like object.|
| mapFn | ArrayFromMapFn\<U, T> | Yes  | Functions used to process the array elements.|

**Return value**

| Type     | Description                   |
| --------- | ----------------------- |
| Array\<T> | Newly created ArkTS array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The from method cannot be bound. |

**Example**

```ts
let array : Array<number> = [1, 2, 3]; // Native Array<T>
let newarray = collections.Array.from<number, string>(array, (value, index) => value + "." + index); // Return a new Array<T>.
console.info(newarray.toString());
// Expected output: 1.0, 2.1, 3.2
```

### isArray<sup>18+</sup>

static isArray\<T>(value: Object | undefined | null): boolean

Check whether the input parameter is an ArkTS array.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type         | Mandatory| Description                           |
| --------- | ------------- | ---- | ------------------------------- |
| value | Object \| undefined \| null | Yes  | Value to check.|

**Return value**

| Type     | Description                   |
| --------- | ----------------------- |
| boolean | Check result. The value **true** means that the input parameter is an ArkTS array, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
let arr: collections.Array<string> = new collections.Array('a', 'b', 'c', 'd')
let result: boolean = collections.Array.isArray(arr);
console.info(result + '');
// Expected output: true
```

### of<sup>18+</sup>

static of\<T>(...items: T\[]): Array\<T>

Creates an ArkTS array with a variable number of parameters.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type         | Mandatory| Description                           |
| --------- | ------------- | ---- | ------------------------------- |
| items | T[] | No  | Array of elements used to create the array. The number of elements can be zero, one, or more.|

**Return value**

| Type     | Description                   |
| --------- | ----------------------- |
| Array\<T> | Newly created ArkTS array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
let arr: collections.Array<string> = collections.Array.of('a', 'b', 'c', 'd')
console.info(arr.toString());
// Expected output: a, b, c, d
```

### copyWithin<sup>18+</sup>
copyWithin(target: number, start: number, end?: number): Array\<T>

Copies elements within a given range from this ArkTS array to another position in sequence.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| target | number | Yes| Index to copy the elements to.|
| start | number | Yes| Start index of the range. If a negative number is passed in, it refers to the index of **start + array.length**.|
| end | number | No| End index of the range. If a negative number is passed in, it refers to the index of **end + array.length**. The default value is the length of the ArkTS array.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| Array\<T> | ArkTS array after being modified.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------ |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The copyWithin method cannot be bound.           |
| 10200201 | Concurrent modification exception.               |

**Example**

```ts
let array: collections.Array<number> = collections.Array.from([1, 2, 3, 4, 5, 6, 7, 8]);
let copied: collections.Array<number> = array.copyWithin(3, 1, 3);
console.info(copied.toString());
// Expected output: 1, 2, 3, 2, 3, 6, 7, 8
```

### lastIndexOf<sup>18+</sup>

lastIndexOf(searchElement: T, fromIndex?: number): number

Obtains the index of the last occurrence of the specified value in in this ArkTS array.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name          | Type    | Mandatory | Description                                                                               |
| ------------- | ------ | --- | --------------------------------------------------------------------------------- |
| searchElement | T | Yes  | Value to search for.                                                                           |
| fromIndex     | number | No  | Index from which the search starts. The default value is **0**. If the index is greater than or equal to the length of the ArkTS array, **-1** is returned. If a negative number is passed in, it refers to the index of **fromIndex + array.length**.|

**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| number | Index of the last occurrence of the value. If the value is not found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID   | Error Message                                   |
| -------- | --------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range. |
| 10200011 | The lastIndexOf method cannot be bound. |
| 10200201 | Concurrent modification exception.      |

**Example**

```ts
let array: collections.Array<number> = collections.Array.from([3, 5, 9]);
console.info(array.lastIndexOf(3) + '');
// Expected output: 0
console.info(array.lastIndexOf(7) + '');
// Expected output: -1
console.info(array.lastIndexOf(9, 2) + '');
// Expected output: 2
console.info(array.lastIndexOf(9, -2) + '');
// Expected output: -1
```

### some<sup>18+</sup>
some(predicate: ArrayPredicateFn\<T, Array\<T>>): boolean

Checks whether this ArkTS array contains an element that meets certain conditions.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                 |
| ------- | ------ | ---- | ---------------------------------------------------- |
| predicate | ArrayPredicateFn\<T, Array> | Yes| Assertion function used for the test.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| boolean | Check result. The value **true** means that an element meeting the given condition exists, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                           |
| -------- | ---------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 10200011 | The some method cannot be bound.   |
| 10200201 | Concurrent modification exception. |

**Example**

```ts
let newArray: collections.Array<number> = collections.Array.from([-10, 20, -30, 40, -50]);
console.info(newArray.some((element: number) => element < 0) + '');
// Expected output: true
```

### reduceRight<sup>18+</sup>

reduceRight(callbackFn: ArrayReduceCallback\<T, T, Array\<T>>): T

Goes through each element in this ArkTS array from right to left, uses a callback function to combine them into a single value, and returns that final value.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name       | Type                                                                              | Mandatory | Description                                        |
| ---------- | -------------------------------------------------------------------------------- | --- | ------------------------------------------ |
| callbackFn | ArrayReduceCallback\<T, T, Array\<T>> | Yes  | Function that takes four arguments. It performs an operation on each element and passes the result as an accumulated value to the next element.|

**Return value**

| Type | Description           |
| --- | ------------- |
| T   | Final result obtained from the last call of the callback function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID   | Error Message                                   |
| -------- | --------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 10200011 | The reduceRight method cannot be bound. |
| 10200201 | Concurrent modification error.          |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let reducedValue = array.reduceRight((accumulator, value) => accumulator + value); // Accumulated result of all elements.
console.info(reducedValue + '');
// Expected output: 15
```

### reduceRight<sup>18+</sup>

reduceRight\<U = T>(callbackFn: ArrayReduceCallback\<U, T, Array\<T>>, initialValue: U): U

This API is similar to the previous API, but it takes an initial value as the second parameter to initialize the accumulator before the array traversal starts from right to left.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name         | Type                                                                                          | Mandatory | Description                                        |
| ------------ | -------------------------------------------------------------------------------------------- | --- | ------------------------------------------ |
| callbackFn   | ArrayReduceCallback\<U, T, Array\<T>> | Yes  | Function that takes four arguments. It performs an operation on each element and passes the result as an accumulated value to the next element.|
| initialValue | U                                                                                            | Yes  | Initial value of the accumulator.                               |

**Return value**

| Type | Description           |
| --- | ------------- |
| U   | Final result obtained from the last call of the callback function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID   | Error Message                                   |
| -------- | --------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 10200011 | The reduceRight method cannot be bound. |
| 10200201 | Concurrent modification error.          |

**Example**

```ts
// An accumulator with the initial value 0 is used. The accumulator is used to calculate the sum of all elements in the array and return the sum.
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let reducedValue = array.reduceRight<number>((accumulator: number, value: number) => accumulator + value, 0); // Accumulated result of all elements. The initial value is 0.
console.info(reducedValue + '');
// Expected output: 15
```

### pop

pop(): T | undefined

Removes the last element from this ArkTS array and returns that element. If the array is empty, **undefined** is returned and the array does not change.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type          | Description                                               |
| -------------- | --------------------------------------------------- |
| T \| undefined | Element removed. If the array is empty, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                       |
| -------- | ------------------------------- |
| 10200011 | The pop method cannot be bound. |
| 10200201 | Concurrent modification error.  |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3);
let lastElement = array.pop(); // 3 is returned. The array changes to [1, 2].
```

### push

push(...items: T[]): number

Adds one or more elements to the end of this ArkTS array and returns the new length of the array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description                              |
| ------ | ---- | ---- | ---------------------------------- |
| items  | T[]  | Yes  | Elements to add.|

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | New length of the array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 10200011 | The push method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3);
let length = array.push (4, 5); // 5 is returned. The array changes to [1, 2, 3, 4, 5].
```

### join

join(separator?: string): string

Concatenates all elements in this ArkTS array into a string, with a given separator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                                                |
| --------- | ------ | ---- | ---------------------------------------------------- |
| separator | string | No  | Separator to be used. If no value is passed in, a comma (,) is used as the separator.|

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| string | String obtained. If the array is empty, an empty string is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 10200011 | The join method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**Example**

```ts
let array = new collections.Array<string>('a', 'b', 'c');
let joinedString = array.join('-'); // "a-b-c" is returned.
```

### shift

shift(): T | undefined

Removes the first element from this ArkTS array and returns that element. If the array is empty, **undefined** is returned and the array does not change.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type          | Description                                               |
| -------------- | --------------------------------------------------- |
| T \| undefined | Element removed. If the array is empty, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 10200011 | The shift method cannot be bound. |
| 10200201 | Concurrent modification error.    |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3);
let firstElement = array.shift(); // 1 is returned. The array changes to [2, 3].
```

### reverse<sup>18+</sup>

reverse(): Array\<T>

Reverses elements in this ArkTS array and returns a reference to the same array.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                |
| ----- | ------------------ |
| Array | Reversed ArkTS array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID   | Error Message                               |
| -------- | ----------------------------------- |
| 10200011 | The reverse method cannot be bound. |
| 10200201 | Concurrent modification exception.  |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let reversed = array.reverse();
console.info(array.toString());
// Expected output: 5, 4, 3, 2, 1
```

### unshift

unshift(...items: T[]): number

Adds one or more elements to the beginning of this ArkTS array and returns the new length of the array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description                    |
| ------ | ---- | ---- | ------------------------ |
| items  | T[]  | Yes  | Elements to add.|

**Return value**

| Type  | Description          |
| ------ | -------------- |
| number | New length of the array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 10200011 | The unshift method cannot be bound. |
| 10200201 | Concurrent modification error.      |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3);
let newLength = array.unshift(0); // 4 is returned. The array changes to [0, 1, 2, 3].
```

### toString<sup>18+</sup>

toString(): string

Converts an ArkTS array into a string.

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
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let stringArray = array.toString();
console.info(stringArray);
// Expected output: 1,2,3,4,5
```

### slice

slice(start?: number, end?: number): Array\<T>

Selects a range of elements in this ArkTS array to create an array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| start  | number | No  | Start index of the range. If a negative number is passed in, it refers to the index of **start + array.length**. The default value is **0**.  |
| end    | number | No  | End index of the range (exclusive). If a negative number is passed in, it refers to the index of **end + array.length**. The default value is the length of the ArkTS array.|

**Return value**

| Type     | Description                      |
| --------- | -------------------------- |
| Array\<T> | New array containing the selected elements.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 10200011 | The slice method cannot be bound. |
| 10200201 | Concurrent modification error.    |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let slicedArray = array.slice (1, 3); // [2, 3] is returned. The original array remains unchanged.
```

### sort

sort(compareFn?: (a: T, b: T) => number): Array\<T>

Sorts elements in this ArkTS array and returns a new array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type                  | Mandatory| Description                                      |
| --------- | ---------------------- | ---- | ------------------------------------------ |
| compareFn | (a: T, b: T) => number | No  | Function that determines the sort order. By default, elements are sorted in ascending order.|

**Return value**

| Type     | Description          |
| --------- | -------------- |
| Array\<T> | Array with the sorted elements.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 10200011 | The sort method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**Example**

```ts
let array = new collections.Array<number>(1, 3, 5, 4, 2);
array.sort((a: number, b: number) => a - b); // [1, 2, 3, 4, 5]
array.sort((a: number, b: number) => b - a); // [5, 4, 3, 2, 1]
```

### indexOf

indexOf(searchElement: T, fromIndex?: number): number

Returns the index of the first occurrence of a value in this ArkTS Array. If the value is not found, **-1** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name       | Type  | Mandatory| Description                       |
| ------------- | ------ | ---- | --------------------------- |
| searchElement | T      | Yes  | Value to search for.               |
| fromIndex     | number | No  | Index from which the search starts. The default value is **0**.|

**Return value**

| Type  | Description                                          |
| ------ | ---------------------------------------------- |
| number | Index of the first occurrence of the value. If the value is not found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 10200011 | The indexOf method cannot be bound. |
| 10200201 | Concurrent modification error.      |

**Example**

```ts
let array = new collections.Array<string>('a', 'b', 'c');
let index = array.indexOf('b'); // 1 is returned because 'b' is at index 1.
```

### forEach

forEach(callbackFn: (value: T, index: number, array: Array\<T>) => void): void

Calls a callback function for each element in this ArkTS Array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type                                               | Mandatory| Description                          |
| ---------- | --------------------------------------------------- | ---- | ------------------------------ |
| callbackFn | (value: T, index: number, array: Array\<T>) => void | Yes  | Callback function to run for each element.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 10200011 | The forEach method cannot be bound. |
| 10200201 | Concurrent modification error.      |

**Example**

```ts
let array = new collections.Array<string>('a', 'b', 'c');
array.forEach((value, index, array) => {
  console.info(`Element ${value} at index ${index}`);
});
```

### map

map\<U>(callbackFn: (value: T, index: number, array: Array\<T>) => U): Array\<U>

Calls a callback function for each element in this ArkTS Array and returns a new array that contains the result of the callback function.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| ---------- | ------------------------------------------------ | ---- | ------------------------------ |
| callbackFn | (value: T, index: number, array: Array\<T>) => U | Yes  | Callback function to run for each element.|

**Return value**

| Type     | Description                      |
| --------- | -------------------------- |
| Array\<U> | New array containing the result of the callback function.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                       |
| -------- | ------------------------------- |
| 10200011 | The map method cannot be bound. |
| 10200201 | Concurrent modification error.  |

**Example**

```ts
// Convert each string element in the original array to uppercase and return a new array containing the new strings.
let array = new collections.Array<string>('a', 'b', 'c');
let mappedArray = array.map((value, index, array) => {
  return value.toUpperCase(); // Convert each string element to uppercase.
});
console.info("" + mappedArray); // ['A', 'B', 'C'] is returned.
```

### filter

filter(predicate: (value: T, index: number, array: Array\<T>) => boolean): Array\<T>

Returns a new array containing all elements that pass a test provided by a callback function.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type                                                  | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| predicate | (value: T, index: number, array: Array\<T>) => boolean | Yes  | Function that takes three arguments. It is used to filter elements. The value **true** means that the current element passes the test and should be retained in the new array. The value **false** means that the current element fails the test and should be excluded from the new array.|

**Return value**

| Type     | Description                        |
| --------- | ---------------------------- |
| Array\<T> | New array containing elements that pass the test.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                          |
| -------- | ---------------------------------- |
| 10200011 | The filter method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let filteredArray = array.filter((value: number) => value % 2 === 0); // [2, 4] is returned. This new array contains only even numbers.
```

### reduce

reduce(callbackFn: (previousValue: T, currentValue: T, currentIndex: number, array: Array\<T>) => T): T

Calls a callback function for each element in this ArkTS array, uses the previous return value of the function as an accumulated value, and returns the final result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callbackFn | (previousValue: T, currentValue: T, currentIndex: number, array: Array\<T>) => T | Yes  | Function that takes four arguments. It performs an operation on each element and passes the result as an accumulated value to the next element.|

**Return value**

| Type| Description                      |
| ---- | -------------------------- |
| T    | Final result obtained from the last call of the callback function.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                          |
| -------- | ---------------------------------- |
| 10200011 | The reduce method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let reducedValue = array.reduce((accumulator, value) => accumulator + value); // 15, which is the final accumulated result of all elements, is returned.
```

### reduce

reduce\<U>(callbackFn: (previousValue: U, currentValue: T, currentIndex: number, array: Array\<T>) => U, initialValue: U): U

Similar to the previous API, this API takes an initial value as the second parameter to initialize the accumulator before the array traversal starts.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callbackFn   | callbackFn: (previousValue: U, currentValue: T, currentIndex: number, array: Array\<T>) => U | Yes  | Function that takes four arguments. It performs an operation on each element and passes the result as an accumulated value to the next element.|
| initialValue | U                                                            | Yes  | Initial value of the accumulator.                                      |

**Return value**

| Type| Description                      |
| ---- | -------------------------- |
| U    | Final result obtained from the last call of the callback function.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                          |
| -------- | ---------------------------------- |
| 10200011 | The reduce method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**Example**

```ts
// An accumulator with the initial value 0 is used. The accumulator is used to calculate the sum of all elements in the array and return the sum.
let array = new collections.Array(1, 2, 3, 4, 5);
let reducedValue = array.reduce<number>((accumulator: number, value: number) => accumulator + value, 0); // 15, which is the final accumulated result of all elements, is returned. The initial value is 0.
```

### at

at(index: number): T | undefined

Returns the element at a given index in this ArkTS array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| index  | number | Yes  | Index of the element. The index in an array always starts from 0 and is an integer. If a negative number is passed in, it refers to the index of **index + array.length**.|


**Return value**

| Type          | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| T \| undefined | Element at the given index. If the index is out of range or invalid, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 10200011 | The at method cannot be bound. |
| 10200201 | Concurrent modification error. |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let elementAtIndex = array.at(2); // 3 is returned. This is because the index starts from 0.
```

### entries

entries(): IterableIterator<[number, T]>

Returns an iterator object that contains the key-value pair of each element in this ArkTS array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                         | Description                                      |
| ----------------------------- | ------------------------------------------ |
| IterableIterator<[number, T]> | Iterator object that contains the key-value pair of each element in the array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 10200011 | The entries method cannot be bound. |
| 10200201 | Concurrent modification error.      |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let iterator = array.entries();
console.info(iterator.next().value); // [0, 1], key-value pair of the first element is returned.
```

### keys

keys(): IterableIterator\<number>

Returns an iterator object that contains the key of each element in this ArkTS array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                     | Description                                  |
| ------------------------- | -------------------------------------- |
| IterableIterator\<number> | Iterator object that contains the key of each element in the array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 10200011 | The keys method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let iterator = array.keys();
for (const key of iterator) {
  console.info("" + key); // 0, 1, 2, 3, and 4 are returned in sequence.
}
```

### values

values(): IterableIterator\<T>

Returns an iterator object that contains the value of each element in this ArkTS array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                | Description                                  |
| -------------------- | -------------------------------------- |
| IterableIterator\<T> | Iterator object that contains the value of each element in the array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                          |
| -------- | ---------------------------------- |
| 10200011 | The values method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let iterator = array.values();
for(const value of iterator) {
  console.info("" + value); // 1, 2, 3, 4, and 5 are returned in sequence.
}
```

### find

find(predicate: (value: T, index: number, obj: Array\<T>) => boolean): T | undefined

Returns the value of the first element that passes a test provided by a callback function. If none of the elements pass the test, **undefined** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type                                                | Mandatory| Description                                                  |
| --------- | ---------------------------------------------------- | ---- | ------------------------------------------------------ |
| predicate | (value: T, index: number, obj: Array\<T>) => boolean | Yes  | Function that takes three arguments. It is used to filter elements. The value **true** means that the current element meets the conditions, the traversal stops, and that element is returned. The value **false** means that the current element does not meet the condition, and the traversal continues until the element that meets the condition is found or the entire array is traversed.|

**Return value**

| Type          | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| T \| undefined | Value of the first element that passes the test. If none of the elements pass the test, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 10200011 | The find method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let foundValue = array.find((value: number) => value % 2 === 0); // 2, the first even element, is returned.
```

### includes

includes(searchElement: T, fromIndex?: number): boolean

Checks whether this ArkTS array contains an element and returns a Boolean value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name       | Type  | Mandatory| Description                       |
| ------------- | ------ | ---- | --------------------------- |
| searchElement | T      | Yes  | Element to search for.             |
| fromIndex     | number | No  | Index from which the search starts. The default value is **0**.|

**Return value**

| Type   | Description                                               |
| ------- | --------------------------------------------------- |
| boolean | Check result. The value **true** means that the element exists, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                            |
| -------- | ------------------------------------ |
| 10200011 | The includes method cannot be bound. |
| 10200201 | Concurrent modification error.       |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let includesResult = array.includes(3); // true is returned, because the array contains 3.
```

### findIndex

findIndex(predicate: (value: T, index: number, obj: Array\<T>) => boolean): number

Returns the index of the first element that passes a test provided by a callback function. If none of the elements pass the test, **-1** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type                                                | Mandatory| Description                                                  |
| --------- | ---------------------------------------------------- | ---- | ------------------------------------------------------ |
| predicate | (value: T, index: number, obj: Array\<T>) => boolean | Yes  | Function that takes three arguments. It is used to filter elements. The value **true** means that the current element meets the conditions, the traversal stops, and the index of that element is returned. The value **false** means that the current element does not meet the condition, and the traversal continues until the element that meets the condition is found or the entire array is traversed.|

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| number | Index of the first element that passes the test. If none of the elements pass the test, **-1** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 10200011 | The findIndex method cannot be bound. |
| 10200201 | Concurrent modification error.        |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let foundIndex = array.findIndex((value: number) => value % 2 === 0); // 1 is returned, because 2 is the first even element.
```

### fill

fill(value: T, start?: number, end?: number): Array\<T>

Fills elements in the specified range of this ArkTS array with a given value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                                                  |
| ------ | ------ | ---- | ------------------------------------------------------ |
| value  | T      | Yes  | Value to fill in.                                          |
| start  | number | No  | Start index of the range. The default value is **0**.                           |
| end    | number | No  | End index of the range (exclusive). If no value is passed in, it refers to the last element of the array.|

**Return value**

| Type     | Description          |
| --------- | -------------- |
| Array\<T> | Filled array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 10200011 | The fill method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**Example**

```ts
let array = new collections.Array(1, 2, 3, 4, 5);
array.fill(0, 1, 3); // [1, 0, 0, 4, 5] is returned, because elements in the index range from 1 to 3 are filled with 0.
```

### shrinkTo

shrinkTo(arrayLength: number): void

Shrinks this ArkTS array to a given length.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                                                  |
| ------ | ------ | ---- | ------------------------------------------------------ |
| arrayLength  | number  | Yes  | New length of the array. If a value greater than or equal to the current array length is passed in, the array does not change.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 10200011 | The shrinkTo method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**Example**

```ts
let array1 = new collections.Array(1, 2, 3, 4, 5);
array1.shrinkTo(1); // The array is changed to [1].

let array2 = new collections.Array(1, 2, 3, 4, 5);
array2.shrinkTo(10); // The array remains unchanged.
```

### extendTo

extendTo(arrayLength: number, initialValue: T): void

Extends this array to a given length by adding elements with the specified initial value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                                                  |
| ------ | ------ | ---- | ------------------------------------------------------ |
| arrayLength  | number  | Yes  | New length of the array. If a value less than or equal to the current array length is passed in, the array does not change.|
| initialValue  | T  | Yes  | Initial value of the elements to be added.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 10200011 | The extendTo method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**Example**

```ts
let array1 = new collections.Array(1, 2, 3);
array1.extendTo (5, 10); // The array is changed to [1, 2, 3, 10, 10].

let array2 = new collections.Array(1, 2, 3);
array2.extendTo (1, 10); // The array remains unchanged.
```

### concat

concat(...items: ConcatArray\<T>[]): Array\<T>

Concatenates this ArkTS array with one or more arrays.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description                              |
| ------ | ---- | ---- | ---------------------------------- |
| items  | ConcatArray\<T>[]  | Yes  | Arrays to concatenate.|

**Return value**

| Type| Description                              |
| ---- | ---------------------------------- |
| Array\<T>  | New array generated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| ------- | -------- |
| 401 |  Parameter error. Not a valid array. |
| 10200011 | The concat method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**Example**

```ts
let array = new collections.Array(1, 2, 3);
let array1 = new collections.Array(4, 5, 6);
let array2 = new collections.Array(7, 8, 9);

let concatArray = array.concat(array1, array2); // The concatenated array is [1, 2, 3, 4, 5, 6, 7, 8, 9].
```

### splice

splice(start: number): Array\<T>

Removes elements from a specified position in an array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type | Mandatory| Description                                                               |
| ----- | ------ | -- | ------------------------------------------------------------------- |
| start | number | Yes| Index from which the removal starts. If -array.length =< start < 0, the removal starts from **start + array.length**. If start < -array.length, the removal starts from 0.|

**Return value**

| Type     | Description                  |
| --------- | --------------------- |
| Array\<T> | **Array** object that contains the removed elements. If no element is removed, an empty **Array** object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                           |
| -------- | ---------------------------------- |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200011 | The splice method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let removeArray = array.splice(2); // The array is changed to [1, 2], and [3, 4, 5] is returned.
```

### every<sup>18+</sup>

every(predicate: ArrayPredicateFn\<T, Array\<T>>): boolean

Checks whether all elements in this ArkTS array meet a given condition.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name | Type  | Mandatory| Description                                                   |
| ------- | ------ | ---- | ----------------------------------------------------- |
| predicate | ArrayPredicateFn\<T, Array\<T>> | Yes| Assertion function used for the test.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| boolean | Check result. The value **true** means that all elements meet the given condition, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 10200011 | The every method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**Example**

```ts
let newArray: collections.Array<number> = collections.Array.from([-10, 20, -30, 40, -50]);
console.info(newArray.every((element: number) => element > 0) + '');
// Expected output: false
```

### toLocaleString<sup>18+</sup>

toLocaleString(): string

Generates a string that matches the cultural conversions of the current system locale. Each element converts itself to a string via its **toLocaleString** API, and these strings are then joined together in sequence with commas (,).

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
let array = new collections.Array<number | string>(1000, 'Test', 53621);
let stringArray = array.toLocaleString();
console.info(stringArray);
// Expected output: 1,000,Test,53,621
```

### splice

splice(start: number, deleteCount: number, ...items: T[]): Array\<T>

Removes elements from a specified position in an array, and inserts new elements from the same position.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name      | Type  | Mandatory| Description                                                               |
| ----------- | ------ | --  | ------------------------------------------------------------------- |
| start       | number | Yes | Index from which the removal starts. If -array.length =< start < 0, the removal starts from **start + array.length**. If start < -array.length, the removal starts from 0.|
| deleteCount | number | Yes | Number of elements to remove.                                                     |
| items       | T[]    | No | New elements to insert from the **start** position. If no value is passed in, only the elements in the array are removed.       |

**Return value**

| Type     | Description                                 |
| --------- | ------------------------------------ |
| Array\<T> | **Array** object that contains the removed elements. If no element is removed, an empty **Array** object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                           |
| -------- | ---------------------------------- |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200011 | The splice method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**Example**

```ts
// Example 1:
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let removeArray = array.splice(2, 2); // The array is changed to [1, 2, 5], and [3, 4] is returned.
```

```ts
// Example 2:
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let removeArray = array.splice(2, 2, 6, 7, 8); // The array is changed to [1, 2, 6, 7, 8, 5], and [3, 4] is returned.
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

Obtains an iterator, each item of which is a JavaScript object.

> **NOTE**
>
> This API cannot be used in .ets files.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                     | Description            |
| ------------------------- | ---------------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**Example**

```ts
let array= new collections.Array<number>(1, 2, 3, 4);

for (let item of array) {
  console.info(`value : ${item}`);
}
```

### [index: number]

&#91;index: number&#93;: T

Returns the element at a given index in this array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name   | Type  | Mandatory| Description                                                           |
| ----- | ------ | ---- | ------------------------------------------------------------------ |
| index | number | Yes  | Index of the element. The index starts from zero. If the passed-in index is less than 0 or greater than or equal to the value of **length**, an error is thrown.|

**Return value**

| Type  | Description                    |
| ----- | ------------------------ |
|   T   | Element in the array. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                            |
| ------- | ------------------------------------ |
| 401 |        Parameter error.                  |
| 10200001 | The value of index is out of range. |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 4);
console.info("Element at index 1: ", array[1]);
```

## collections.Map

A non-linear data structure.

This section uses the following to identify the use of generics:

- K: key.
- V: value.

The K and V types must be any of the [sendable data types](../../arkts-utils/arkts-sendable.md#sendable-data-types).

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type  | Read Only| Optional| Description           |
| ---- | ------ | ---- | ---- | --------------- |
| size | number | Yes  | No  | Number of elements in a map.|


### constructor
constructor(entries?: readonly (readonly [K, V])[] | null)

A constructor used to create an ArkTS map.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| entries | [K, V][] \| null | No  | Array containing key-value pairs, or iterator object. The default value is **null**, indicating that an empty map is created.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 10200012 | The ArkTS Map's constructor cannot be directly invoked. |

**Example**

```ts
// Positive example 1:
const myMap = new collections.Map<number, number>();
```

```ts
// Positive example 2:
const myMap = new collections.Map<number, string>([
  [1, "one"],
  [2, "two"],
  [3, "three"],
]);
```

<!--code_no_check-->
```ts
// Negative example:
@Sendable
class SharedClass {
  constructor() {
  }
}
let sObj = new SharedClass();
const myMap1: collections.Map<number, SharedClass> = new collections.Map<number, SharedClass>([[1, sObj]]);
// Type arguments of generic "Sendable" type must be a "Sendable" data type (arkts-sendable-generic-types)
let obj = new Object();
const myMap2: collections.Map<number, Object> = new collections.Map<number, Object>([[1, obj]]);
```

### entries
entries(): IterableIterator<[K, V]>

Returns a map iterator object that contains the key-value pair of each element in this ArkTS map.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                          | Description                   |
| ------------------------------ | ----------------------- |
| IterableIterator&lt;[K, V]&gt; | Map iterator object.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                             |
| -------- | ----------------------------------------------------- |
| 10200011 | The entries method cannot be bound with non-sendable. |

**Example**

```ts
// Example 1:
const myMap = new collections.Map<number, string>([
  [0, "foo"],
  [1, "bar"]
]);

const iterator = myMap.entries();
// Expected output: [0, "foo"]
console.info(iterator.next().value);
// Expected output: [1, "bar"]
console.info(iterator.next().value);
```

```ts
// Example 2:
const myMap: collections.Map<number, string> = new collections.Map<number, string>([
  [0, "one"],
  [1, "two"],
  [2, "three"],
  [3, "four"]
]);
const entriesIter: IterableIterator<[number, string]> = myMap.entries();
for (const entry of entriesIter) {
  if (entry[1].startsWith('t')) {
    myMap.delete(entry[0]);
  }
}
// Expected output: 2
console.info("size:" + myMap.size);
```

### keys
keys(): IterableIterator\<K>

Returns a map iterator object that contains the key of each element in this ArkTS map.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                     | Description                   |
| ------------------------- | ----------------------- |
| IterableIterator&lt;K&gt; | Map iterator object.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                          |
| -------- | -------------------------------------------------- |
| 10200011 | The keys method cannot be bound with non-sendable. |

**Example**

```ts
const myMap = new collections.Map<number, string>([
  [0, "foo"],
  [1, "bar"]
]);

const iterator = myMap.keys();
// Expected output: 0
console.info(iterator.next().value);
// Expected output: 1
console.info(iterator.next().value);
```

### values
values(): IterableIterator\<V>

Returns a map iterator object that contains the value of each element in this ArkTS map.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                     | Description                   |
| ------------------------- | ----------------------- |
| IterableIterator&lt;V&gt; | Map iterator object.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 10200011 | The values method cannot be bound with non-sendable. |

**Example**

```ts
const myMap = new collections.Map<number, string>([
  [0, "foo"],
  [1, "bar"]
]);

const iterator = myMap.values();
// Expected output: "foo"
console.info(iterator.next().value);
// Expected output: "bar"
console.info(iterator.next().value);
```

### clear
clear(): void

Removes all elements from this ArkTS map.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                           |
| -------- | --------------------------------------------------- |
| 10200011 | The clear method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                  |

**Example**

```ts
const myMap = new collections.Map<number, string>([
  [0, "foo"],
  [1, "bar"]
]);
// Expected output: 2
console.info("size:" + myMap.size);
myMap.clear();
// Expected output: 0
console.info("size:" + myMap.size);
```

### delete
delete(key: K): boolean

Deletes a specified key from this ArkTS map.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description            |
| ------ | ---- | ---- | ---------------- |
| key    | K    | Yes  | Key to delete.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Operation result. The value **true** means that the key exists and has been deleted, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 10200011 | The delete method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                   |


**Example**

```ts
const myMap = new collections.Map<string, string>([
  ["hello", "world"],
]);
// Expected result: true
console.info("result:" + myMap.delete("hello"));
// Expected result: false
console.info("result:" + myMap.has("hello"));
// Expected result: false
console.info("result:" + myMap.delete("hello"));
```

### forEach
forEach(callbackFn: (value: V, key: K, map: Map<K, V>) => void): void

Calls a callback function for each key-value pair in this ArkTS map.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type                                      | Mandatory| Description      |
| ---------- | ------------------------------------------ | ---- | ---------- |
| callbackFn | (value: V, key: K, map: Map<K, V>) => void | Yes  | Callback function to run for each key-value pair.|

callbackFn
| Name| Type           | Mandatory| Description                        |
| ------ | --------------- | ---- | ---------------------------- |
| value  | V               | No  | Value of the element that is currently traversed.|
| key    | K               | No  | Key of the element that is currently traversed.|
| map    | Map&lt;K, V&gt; | No  | Current map object.           |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                             |
| -------- | ----------------------------------------------------- |
| 10200011 | The forEach method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                    |

**Example**

```ts
// Positive example:
new collections.Map<string, number>([
  ['foo', 0],
  ['bar', 1],
  ['baz', 2],
]).forEach((value, key, map) => {
  console.info(`m[${key}] = ${value}`);
});
```

<!--code_no_check-->
```ts
// Negative example:
new collections.Map<string, number>([
  ['foo', 0],
  ['bar', 1],
  ['baz', 2],
]).forEach((value, key, map) => {
  // Throw exception `Concurrent modification exception.`
  map.delete(key);
});
```

### get
get(key: K): V | undefined

Obtains the value of the specified key in this ArkTS map.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description     |
| ------ | ---- | ---- | --------- |
| key    | K    | Yes  | Target key.|

**Return value**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| V    | Value obtained. If the key is not found, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The get method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                |

**Example**

```ts
const myMap = new collections.Map<string, string>([
  ["hello", "world"],
]);
// Expected output: "world"
console.info(myMap.get("hello"));
// Expected output: undefined
console.info(myMap.get("world"));
```

### has
has(key: K): boolean

Checks whether a key exists in this ArkTS map.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Check result. The value **true** means that the key exists, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The has method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                |

**Example**

```ts
const myMap = new collections.Map<string, string>([
  ["hello", "world"],
]);
// Expected output: true
console.info("result:" + myMap.has("hello"));
// Expected output: false
console.info("result:" + myMap.has("world"));
```

### set
set(key: K, value: V): Map<K, V>

Adds or updates a key-value pair to this ArkTS map.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type           | Description   |
| --------------- | ------- |
| Map&lt;K, V&gt; | New map obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The set method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                |

**Example**

```ts
// Positive example:
const myMap = new collections.Map<string, string>();
myMap.set("foo", "bar")
```

<!--code_no_check-->
```ts
// Negative example:
let obj = new Object();
const myMap: collections.Map<string, Object> = new collections.Map<string, Object>();
// Type arguments of generic "Sendable" type must be a "Sendable" data type (arkts-sendable-generic-types)
myMap.set("foo", obj);
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[K, V]&gt;

Obtains an iterator, each item of which is a JavaScript object.

> **NOTE**
>
> This API cannot be used in .ets files.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**
| Type| Description|
| -------- | -------- |
| IterableIterator<[K, V]> | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**Example**

```ts
let map = new collections.Map<number, string>([
    [0, "one"],
    [1, "two"],
    [2, "three"],
    [3, "four"]
]);

let keys = Array.from(map.keys());
for (let key of keys) {
  console.info("key:" + key);
  console.info("value:" + map.get(key));
}
```

## collections.Set

A non-linear data structure.

This section uses the following to identify the use of generics:

- T: type, which can be any of the [sendable data types](../../arkts-utils/arkts-sendable.md#sendable-data-types).

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type  | Read Only| Optional| Description           |
| ---- | ------ | ---- | ---- | --------------- |
| size | number | Yes  | No  | Number of elements in a set.|

### constructor

constructor(values?: readonly T[] | null)

A constructor used to create an ArkTS set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description                                                     |
| ------ | ---- | ---- | --------------------------------------------------------- |
| values | T[] \| null | No| Array or iterator object. The default value is **null**, indicating that an empty set is created.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 10200012 | The ArkTS Set's constructor cannot be directly invoked. |

**Example**

```ts
// Positive example 1:
const mySet = new collections.Set<number>();
```

```ts
// Positive example 2:
const mySet = new collections.Set<number>([1, 2, 3, 4, 5]);
```

<!--code_no_check-->
```ts
// Negative example:
@Sendable
class SharedClass {
  constructor() {
  }
}

let sObj = new SharedClass();
const mySet1: collections.Set<number|SharedClass> = new collections.Set<number|SharedClass>([1, sObj]);
// Type arguments of generic "Sendable" type must be a "Sendable" data type (arkts-sendable-generic-types)
let obj = new Object();
const mySet2: collections.Set<number|SharedClass> = new collections.Set<number|Object>([1, obj]);
```

### entries
entries(): IterableIterator<[T, T]>

Returns a set iterator object that contains the key-value pair of each element in this ArkTS set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                          | Description                   |
| ------------------------------ | ----------------------- |
| IterableIterator&lt;[T, T]&gt; | Set iterator object.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                             |
| -------- | ----------------------------------------------------- |
| 10200011 | The entries method cannot be bound with non-sendable. |

**Example**

```ts
const mySet = new collections.Set<number>([0, 1, 2, 3]);

const iterator = mySet.entries();
// Expected output: [0, 0]
console.info(iterator.next().value);
// Expected output: [1, 1]
console.info(iterator.next().value);
```

### keys
keys(): IterableIterator\<T>

Returns a set iterator object that contains the key of each element in this ArkTS set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                     | Description                   |
| ------------------------- | ----------------------- |
| IterableIterator&lt;T&gt; | Set iterator object.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                          |
| -------- | -------------------------------------------------- |
| 10200011 | The keys method cannot be bound with non-sendable. |

**Example**

```ts
const mySet = new collections.Set<number>([0, 1, 2, 3]);

const iterator = mySet.keys();
// Expected output: 0
console.info(iterator.next().value);
// Expected output: 1
console.info(iterator.next().value);
```

### values
values(): IterableIterator\<T>

Returns a set iterator object that contains the value of each element in this ArkTS set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                     | Description                   |
| ------------------------- | ----------------------- |
| IterableIterator&lt;T&gt; | Set iterator object.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 10200011 | The values method cannot be bound with non-sendable. |

**Example**

```ts
// Example 1:
const mySet = new collections.Set<number>([0, 1, 2, 3]);

const iterator = mySet.values();
// Expected output: 0
console.info(iterator.next().value);
// Expected output: 1
console.info(iterator.next().value);
```

```ts
// Example 2:
const mySet = new collections.Set<number>([0, 1, 2, 3]);

const valueIter = mySet.values();
for (let value of valueIter) {
    if (value % 2 == 0) {
        mySet.delete(value);
    }
}

// Expected output: 2
console.info("size:" + mySet.size);
```

### clear
clear(): void

Removes all elements from this ArkTS set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                           |
| -------- | --------------------------------------------------- |
| 10200011 | The clear method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                  |

**Example**

```ts
const mySet = new collections.Set<number>([0, 1]);
// Expected output: 2
console.info("size:" + mySet.size);
mySet.clear();
// Expected output: 0
console.info("size:" + mySet.size);
```

### delete
delete(value: T): boolean

Deletes an element from this ArkTS set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description            |
| ------ | ---- | ---- | ---------------- |
| key    | K    | Yes  | Key to delete.|

**Return value**

| Type   | Description                             |
| ------- | --------------------------------- |
| boolean | Operation result. The value **true** means that the key is deleted, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 10200011 | The delete method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                   |


**Example**

```ts
const mySet = new collections.Set<string>(["hello", "world"]);
// Expected result: true
console.info("result:" + mySet.delete("hello"));
// Expected result: false
console.info("result:" + mySet.has("hello"));
// Expected result: false
console.info("result:" + mySet.delete("hello"));
```

### forEach
forEach(callbackFn: (value1: T, value2: T, set: Set\<T>) => void): void

Calls a callback function for each key-value pair in this ArkTS set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type                                        | Mandatory| Description      |
| ---------- | -------------------------------------------- | ---- | ---------- |
| callbackFn | (value1: T, value2: T, set: Set\<T>) => void | Yes  | Callback function to run for each key-value pair.|

callbackFn
| Name| Type        | Mandatory| Description                        |
| ------ | ------------ | ---- | ---------------------------- |
| value1 | T            | No  | Value of the element that is currently traversed.|
| value2 | T            | No  | Key of the element that is currently traversed.|
| set    | Set&lt;T&gt; | No  | Current set object.           |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                             |
| -------- | ----------------------------------------------------- |
| 10200011 | The forEach method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                    |

**Example**

```ts
// Positive example:
new collections.Set<string>(['foo', 'bar', 'baz']).forEach((value1, value2, set) => {
  console.info(`s[${value1}] = ${value2}`);
});
```

<!--code_no_check-->
```ts
// Negative example:
new collections.Set<string>(['foo', 'bar', 'baz']).forEach((value1, value2, set) => {
  // Throw exception `Concurrent modification exception.`
  set.delete(value1);
});
```

### has
has(value: T): boolean

Checks whether a value exists in this ArkTS set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Check result. The value **true** means that the value exists, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The has method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                |

**Example**

```ts
const mySet = new collections.Set<string>(["hello", "world"]);
// Expected output: true
console.info("result:" + mySet.has("hello"));
// Expected output: true
console.info("result:" + mySet.has("world"));
```

### add
add(value: T): Set\<T>

Checks whether a value exists in this ArkTS set, and if not, adds the value to the set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type        | Description     |
| ------------ | --------- |
| Set&lt;T&gt; | Set object.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The add method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                |

**Example**

```ts
// Positive example:
const mySet: collections.Set<string> = new collections.Set<string>();
mySet.add("foo");
```

<!--code_no_check-->
```ts
// Negative example:
let obj = new Object();
const mySet: collections.Set<Object> = new collections.Set<Object>();
// Type arguments of generic "Sendable" type must be a "Sendable" data type (arkts-sendable-generic-types)
mySet.add(obj);
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

Obtains an iterator, each item of which is a JavaScript object.

> **NOTE**
>
> This API cannot be used in .ets files.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**Example**

```ts
let set = new collections.Set<number>([1, 2, 3, 4, 5]);

let val: Array<number> = Array.from(set.values())
for (let item of val) {
  console.info("value: " + item);
}
```

## collections.ArrayBuffer
Underlying data structure of the ArkTS typed array.

### Properties

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name  | Type  | Read Only| Optional| Description             |
| ------ | ------ | ---- | ---- | ----------------|
| byteLength | number | Yes  | No  | Number of bytes occupied by the buffer.|

### constructor
constructor(byteLength: number)

A constructor used to create an ArkTS ArrayBuffer of a given length.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------|
| byteLength  | number | Yes  | Number of bytes occupied by the buffer.    |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 10200012 | The ArrayBuffer's constructor cannot be directly invoked. |

**Example**

```ts
let arrayBuffer: collections.ArrayBuffer = new collections.ArrayBuffer(10);
console.info("byteLength: " + arrayBuffer.byteLength); // byteLength: 10
```

### slice
slice(begin: number, end?: number): ArrayBuffer

Selects a range of elements in this ArkTS ArrayBuffer to create an ArkTS ArrayBuffer.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type  | Mandatory| Description                                             |
| ------ | ------ | ---- | ------------------------------------------------ |
| begin  | number | Yes  | Start index of the range. If a negative number is passed in, it refers to the index of **begin + arraybuffer.byteLength**.|
| end    | number | No  | End index of the range. If a negative number is passed in, it refers to the index of **end + arraybuffer.byteLength**. The default value is the length of the ArkTS ArrayBuffer.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| ArrayBuffer | New ArrayBuffer generated.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID|                    Error Message                  |
| -------- | -------------------------------------------- |
| 10200011 | The slice method cannot be bound.            |
| 10200201 | Concurrent modification error.               |

**Example**

```ts
let arrayBuffer: collections.ArrayBuffer = new collections.ArrayBuffer(10);
let slicedBuffer: collections.ArrayBuffer = arrayBuffer.slice(0, 4);
console.info("byteLength: " + slicedBuffer.byteLength); // byteLength: 4
```

## TypedArrayFromMapFn
type TypedArrayFromMapFn\<FromElementType, ToElementType> = (value: FromElementType, index: number) => ToElementType

Describes the mapping function of the ArkTS typed array.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| value | FromElementType | Yes| Element that is currently traversed and used to construct an ArkTS typed array.|
| index | number | Yes| Index of the element.|

**Return value**

| Type  | Description                         |
| ------ | --------------------------- |
| ToElementType | Element value after the mapping.|

## TypedArrayPredicateFn
type TypedArrayPredicateFn\<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => boolean

Describes the assertion function of the ArkTS typed array.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| value | ElementType | Yes| Element that is being traversed in the ArkTS typed array.|
| index | number | Yes| Index of the element.|
| array | ArrayType | Yes| ArkTS typed array that is being traversed.|

**Return value**

| Type  | Description                         |
| ------ | --------------------------- |
| boolean | Operation result. The value **true** means that the value meets the condition, and **false** means the opposite.|

## TypedArrayForEachCallback
type TypedArrayForEachCallback\<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => void

Describes the traversal function of the ArkTS typed array.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| value | ElementType | Yes| Element that is being traversed in the ArkTS typed array.|
| index | number | Yes| Index of the element.|
| array | ArrayType | Yes| ArkTS typed array that is being traversed.|

## TypedArrayMapCallback
type TypedArrayMapCallback\<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => ElementType

Describes the conversion mapping function of the ArkTS typed array.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| value | ElementType | Yes| Element that is being mapped in the ArkTS typed array.|
| index | number | Yes| Index of the element.|
| array | ArrayType | Yes| ArkTS typed array that is being mapped.|

**Return value**

| Type  | Description                         |
| ------ | --------------------------- |
| ElementType | Element value after conversion.|

## TypedArrayReduceCallback
type TypedArrayReduceCallback\<AccType, ElementType, ArrayType> = (previousValue: AccType, currentValue: ElementType, currentIndex: number, array: ArrayType) => AccType

Describes the reduce function of the ArkTS typed array.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| previousValue | AccType | Yes| Accumulated value of the current traversal.|
| currentValue | ElementType | Yes| Element that is being traversed in the ArkTS typed array.|
| currentIndex | number | Yes| Index of the element.|
| array | ArrayType | Yes| ArkTS typed array that is being traversed.|

**Return value**

| Type  | Description                         |
| ------ | --------------------------- |
| AccType | Result of the reduce function. The result is passed in to the **previousValue** parameter when **TypedArrayReduceCallback** is called next time.|

## TypedArrayCompareFn
type TypedArrayCompareFn\<ElementType> = (first: ElementType, second: ElementType) => number

Describes the sort function of the ArkTS typed array.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| first | ElementType | Yes| First element to be compared.|
| second | ElementType | Yes| Second element to be compared.|

**Return value**

| Type  | Description                         |
| ------ | --------------------------- |
| number | Comparison result of the elements. If **first** is less than **second**, the return value is a negative number. If **first** is greater than **second**, the return value is a positive number. If **first** is equal to **second**, the return value is 0.|

## collections.TypedArray

A linear data structure that is implemented on [ArkTS ArrayBuffer](#collectionsarraybuffer). Currently, Int8Array, Uint8Array, Int16Array, Uint16Array, Int32Array, Uint32Array, Uint8ClampedArray, and Float32Array are supported.

This section uses the following to identify the use of generics:
- TypedArray: ArkTS typed array of the preceding eight types.

### Properties

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name  | Type  | Read Only| Optional| Description             |
| ------ | ------ | ---- | ---- | ----------------|
| buffer | ArrayBuffer | Yes  | No | Bottom-layer buffer used by an ArkTS typed array.|
| byteLength | number | Yes  | No  | Number of bytes occupied by the ArkTS typed array.|
| byteOffset | number | Yes  | No  | Offset between the ArkTS typed array and the start position of the ArrayBuffer.|
| length | number | Yes  | No | Number of elements in the ArkTS typed array.|
| BYTES_PER_ELEMENT | number | Yes  | No  | Number of bytes occupied by each element in the ArkTS typed array.|

### constructor
constructor()

A constructor used to create an empty ArkTS typed array.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 10200012 | The TypedArray's constructor cannot be directly invoked. |

**Example**

```ts
let int8Array: collections.Int8Array = new collections.Int8Array();
let uint8Array: collections.Uint8Array = new collections.Uint8Array();
let int16Array: collections.Int16Array = new collections.Int16Array();
let uint16Array: collections.Uint16Array = new collections.Uint16Array();
let int32Array: collections.Int32Array = new collections.Int32Array();
let uint32Array: collections.Uint32Array = new collections.Uint32Array();
let uint8ClampedArray: collections.Uint8ClampedArray = new collections.Uint8ClampedArray();
let float32Array: collections.Float32Array = new collections.Float32Array();
```

### constructor
constructor(length: number)

A constructor used to create an ArkTS typed array of a given length.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| length | number | Yes| Length of the ArkTS typed array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                 |
| -------- | -------------------------------------------------------  |
| 10200012 | The TypedArray's constructor cannot be directly invoked. |


**Example**

```ts
// Construct an object with the length parameter.
let int8Array: collections.Int8Array = new collections.Int8Array(12);
let uint8Array: collections.Uint8Array = new collections.Uint8Array(12);
let int16Array: collections.Int16Array = new collections.Int16Array(12);
let uint16Array: collections.Uint16Array = new collections.Uint16Array(12);
let int32Array: collections.Int32Array = new collections.Int32Array(12);
let uint32Array: collections.Uint32Array = new collections.Uint32Array(12);
let uint8ClampedArray: collections.Uint8ClampedArray = new collections.Uint8ClampedArray(12);
let float32Array: collections.Float32Array = new collections.Float32Array(12);
```

### constructor
constructor(array: ArrayLike\<number> | ArrayBuffer)

A constructor that creates an ArkTS typed array from an array-like object or ArkTS ArrayBuffer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| array |  ArrayLike\<number> \| ArrayBuffer | Yes| Object used to construct the ArkTS typed array. When the parameter type is ArrayBuffer, the number of bytes occupied by the buffer must be an integer multiple of 4.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 10200012 | The TypedArray's constructor cannot be directly invoked. |

**Example**

```ts
// Example 1: Construct an object from an array-like object.
let arrayLike = [1, 3, 5];
let array: collections.Uint32Array = new collections.Uint32Array(arrayLike);
```

```ts
// Example 2: Construct an object from an ArkTS typed array.
let arrayBuffer: collections.ArrayBuffer = new collections.ArrayBuffer(12);
let array: collections.Uint32Array = new collections.Uint32Array(arrayBuffer);
```

```ts
// Example 3: Construct an object from another ArkTS typed array.
let arrayLike = [1, 3, 5];
let uint8Array: collections.Uint8Array = new collections.Uint8Array(arrayLike);
// Uint8Array [1, 3, 5]
let uint32Array: collections.Uint32Array = new collections.Uint32Array(uint8Array);
// Uint32Array [1, 3, 5]
```

### constructor
constructor(buffer: ArrayBuffer, byteOffset?: number, length?: number)

A constructor that creates an ArkTS typed array from an ArrayBuffer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                        |
| ------- | ------ | ---- | ------------------------------------------ |
| buffer | ArrayBuffer | Yes| ArrayBuffer object used to construct the ArkTS typed array. The number of bytes occupied by the buffer must be an integer multiple of 4.|
| byteOffset | number | No| Byte offset of the specified buffer. The default value is **0**.|
| length | number | No| Length of the ArkTS typed array. The default value is **0**.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                  |
| -------- | -------------------------------------------------------   |
| 10200012 | The TypedArray's constructor cannot be directly invoked. |

**Example**

```ts
let int32Array: collections.Int32Array = collections.Int32Array.from([1, 2, 3, 4, 5, 6]);
console.info("byteLength: " + int32Array.buffer.byteLength) // byteLength: 24
// Start from the fourth byte of the buffer corresponding to int32Array. The length is 5.
let uint32Array: collections.Uint32Array = new collections.Uint32Array(int32Array.buffer, 4, 5);
console.info("[" + uint32Array + "]"); // [2, 3, 4, 5, 6]
```

### from
static from(arrayLike: ArrayLike\<number>): TypedArray

Creates an ArkTS typed array from an array-like or iterator object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                 |
| ------- | ------ | ---- | --------------------------------------------------- |
| arrayLike | ArrayLike\<number> | Yes| Array-like object used to construct the ArkTS typed array.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| TypedArray | New ArkTS typed array generated.|

**Example**
```ts
let arrayLike = [1, 3, 5];
let array: collections.Uint32Array = collections.Uint32Array.from(arrayLike);
// Uint32Array [1, 3, 5]
```

### from
static from\<T>(arrayLike: ArrayLike\<T>, mapFn: TypedArrayFromMapFn\<T, number>): TypedArray

Creates an ArkTS typed array from an array-like object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name | Type  | Mandatory| Description                                       |
| ------- | ------ | ---- | ------------------------------------------|
| arrayLike | ArrayLike\<T> | Yes| Array-like object used to construct the ArkTS typed array.             |
| mapFn | [TypedArrayFromMapFn](#typedarrayfrommapfn)\<T, number> | Yes| Mapping function.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| TypedArray | New ArkTS typed array generated.|

**Example**

```ts
// Example 1: Create an ArkTS typed array from an object.
let array: collections.Uint32Array = collections.Uint32Array.from<number>(
  { length: 5 }, (v: Object, k: number) => k);
// Uint32Array [0, 1, 2, 3, 4]
```

```ts
// Example 2: Create an ArkTS typed array from a string array.
let array: collections.Uint32Array = collections.Uint32Array.from<string>(
  ["1", "3", "5"], (v: string, k: number) => parseInt(v));
// Uint32Array [1, 3, 5]
```

```ts
// Example 3: Create an ArkTS typed array from a string.
let array: collections.Uint32Array = collections.Uint32Array.from<string>(
  "12345", (v: string, k: number) => parseInt(v));
// Uint32Array [1, 2, 3, 4, 5]
```

### from
static from(iterable: Iterable\<number>, mapFn?: TypedArrayFromMapFn\<number, number>): TypedArray

Creates an ArkTS typed array from an iterator object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name | Type  | Mandatory| Description                               |
| ------- | ------ | ---- | -----------------------------------|
| iterable | Iterable\<number> | Yes| Iterator object used to construct the ArkTS typed array.  |
| mapFn | [TypedArrayFromMapFn](#typedarrayfrommapfn)\<number, number> | No| Mapping function. If no value is passed in, no special processing is conducted on the elements.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| TypedArray | New ArkTS typed array generated.|

**Example**

```ts
// Example 1: No mapping function is specified.
let set: Set<number> = new Set<number>([1, 2, 3]);
let array: collections.Uint32Array = collections.Uint32Array.from(set);
// Uint32Array [1, 2, 3]
```

```ts
// Example 2: A mapping function is specified.
let set: Set<number> = new Set<number>([1, 2, 3]);
let array: collections.Uint32Array = collections.Uint32Array.from(
  set, (v: number, k: number) => v + k);
// Uint32Array [1, 3, 5]
```

### of<sup>18+</sup>

static of(...items: number[]): TypedArray

Creates an ArkTS typed array with a variable number of parameters.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type         | Mandatory| Description                           |
| --------- | ------------- | ---- | ------------------------------- |
| items | number[] | No  | Array of elements used to create the array. The number of elements can be zero, one, or more.|

**Return value**

| Type     | Description                   |
| --------- | ----------------------- |
| TypedArray | New ArkTS typed array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |

**Example**

```ts
let arr: collections.Uint32Array = collections.Uint32Array.of(1, 2, 3, 4)
console.info(arr.toString());
// Expected output: 1,2,3,4
```

### toString<sup>18+</sup>

toString(): string

Converts an ArkTS typed array into a string.

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
let array = new collections.Uint32Array([1, 2, 3, 4, 5]);
let stringArray = array.toString();
console.info(stringArray);
// Expected output: 1,2,3,4,5
```

### toLocaleString<sup>18+</sup>

toLocaleString(): string

Generates a string of digits that matches the cultural conventions of the current system locale. Each element converts its digits to a string via its **toLocaleString** API, and these strings are then joined together in sequence with commas (,).

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
let array = new collections.Uint32Array([1000, 2000, 3000]);
let stringArray = array.toLocaleString();
console.info(stringArray);
// Expected output: 1,000,2,000,3,000
```

### copyWithin
copyWithin(target: number, start: number, end?: number): TypedArray

Copies elements within a given range from this ArkTS typed array to another position in sequence.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| target | number | Yes| Index to copy the elements to.|
| start | number | Yes| Start index of the range. If a negative number is passed in, it refers to the index of **start + typedarray.length**.|
| end | number | No| End index of the range. If a negative number is passed in, it refers to the index of **end + typedarray.length**. The default value is the length of the ArkTS typed array.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| TypedArray | ArkTS typed array after being modified.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------ |
| 10200011 | The copyWithin method cannot be bound.           |
| 10200201 | Concurrent modification exception.               |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5, 6, 7, 8]);
let copied: collections.Uint32Array = array.copyWithin(3, 1, 3);
// Uint32Array [1, 2, 3, 2, 3, 6, 7, 8]
```

### some
some(predicate: TypedArrayPredicateFn\<number, TypedArray>): boolean

Checks whether any element in this ArkTS typed array meets a given condition.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                 |
| ------- | ------ | ---- | ---------------------------------------------------- |
| predicate | [TypedArrayPredicateFn](#typedarraypredicatefn)\<number, TypedArray> | Yes| Assertion function used for the test.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| boolean | Check result. The value **true** means that an element meeting the given condition exists, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                           |
| -------- | ---------------------------------- |
| 10200011 | The some method cannot be bound.   |
| 10200201 | Concurrent modification exception. |

**Example**

```ts
let arrayLike = [-10, 20, -30, 40, -50];
let uint32Array: collections.Uint32Array = new collections.Uint32Array(arrayLike);
uint32Array.some((element: number) => element < 0); // false

let int32Array: collections.Int32Array = new collections.Int32Array(arrayLike);
int32Array.some((element: number) => element < 0); // true
```

### every
every(predicate: TypedArrayPredicateFn\<number, TypedArray>): boolean

Checks whether all elements in this ArkTS typed array meet a given condition.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                   |
| ------- | ------ | ---- | ----------------------------------------------------- |
| predicate | [TypedArrayPredicateFn](#typedarraypredicatefn)\<number, TypedArray> | Yes| Assertion function used for the test.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| boolean | Check result. The value **true** means that all elements meet the given condition, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The every method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**Example**

```ts
let arrayLike = [-10, 20, -30, 40, -50];
let uint32Array: collections.Uint32Array = new collections.Uint32Array(arrayLike);
uint32Array.every((element: number) => element > 0); // true

let int32Array: collections.Int32Array = new collections.Int32Array(arrayLike);
int32Array.every((element: number) => element > 0);  // false
```

### fill
fill(value: number, start?: number, end?: number): TypedArray

Fills all elements in a given range in this ArkTS typed array with a value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                     |
| ------- | ------ | ---- | --------------------------------------------------------|
| value | number | Yes| Value to fill in.|
| start | number | No| Start index of the range. If a negative number is passed in, it refers to the index of **start + typedarray.length**. The default value is **0**.|
| end | number | No| End index of the range. If a negative number is passed in, it refers to the index of **end + typedarray.length**. The default value is the length of the ArkTS typed array.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| TypedArray | Filled ArkTS typed array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The fill method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**Example**

```ts
let arrayLike = [1, 2, 3];
new collections.Uint32Array(arrayLike).fill(4); // Uint32Array [4, 4, 4]
new collections.Uint32Array(arrayLike).fill(4, 1); // Uint32Array [1, 4, 4]
new collections.Uint32Array(arrayLike).fill(4, 1, 2); // Uint32Array [1, 4, 3]
```

### filter
filter(predicate: TypedArrayPredicateFn\<number, TypedArray>): TypedArray

Returns a new ArkTS typed array that contains all elements that meet the given condition.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                   |
| ------- | ------ | ---- | ------------------------------------------------------ |
| predicate | [TypedArrayPredicateFn](#typedarraypredicatefn)\<number, TypedArray> | Yes| Assertion function used for the test.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| TypedArray| Filtered ArkTS typed array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The filter method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([0, 1, 2, 3, 4]);
let filtered: collections.Uint32Array = array.filter((element: number) => element % 2 == 0);
// Uint32Array [0, 2, 4]
```

### find
find(predicate: TypedArrayPredicateFn\<number, TypedArray>): number | undefined

Returns the value of the first element that passes a test provided by a callback function. If none of the elements pass the test, **undefined** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| predicate | [TypedArrayPredicateFn](#typedarraypredicatefn)\<number, TypedArray> | Yes| Assertion function used for the test.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
|  number \| undefined | Value of the first element that passes the test. If none of the elements pass the test, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The find method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([0, 1, 2, 3, 4]);
array.find((element: number) => element > 2); // 3
array.find((element: number) => element > 4); // undefined
```

### findIndex
findIndex(predicate: TypedArrayPredicateFn\<number, TypedArray>): number

Returns the index of the first element that passes a test provided by a callback function. If none of the elements pass the test, **-1** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| predicate | [TypedArrayPredicateFn](#typedarraypredicatefn)\<number, TypedArray> | Yes| Assertion function used for the test.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| number | Index of the first element that passes the test. If none of the elements pass the test, **-1** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The findIndex method cannot be bound. |
| 10200201 | Concurrent modification exception.  |

**Example**

```ts
const array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let foundIndex: number = array.findIndex((element: number) => element % 2 === 0); // 1
```

### forEach
forEach(callbackFn: TypedArrayForEachCallback\<number, TypedArray>): void

Calls a callback function for each element in this ArkTS typed array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| callbackFn | [TypedArrayForEachCallback](#typedarrayforeachcallback)\<number, TypedArray> | Yes| Callback function to run for each element.|


**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The forEach method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**Example**

```ts
let uint32Array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3]);
uint32Array.forEach((value: number, index: number, array: collections.Uint32Array) => {
  console.info(`Element ${value} at index ${index}`);
});
```

### indexOf
indexOf(searchElement: number, fromIndex?: number): number

Returns the index of the first occurrence of a value in this ArkTS typed array. If the value is not found, **-1** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name       | Type  | Mandatory| Description                       |
| ------------- | ------ | ---- | ---------------------------|
| searchElement | number | Yes  | Value to search for.               |
| fromIndex     | number | No  | Index from which the search starts. The default value is **0**. If the index is greater than or equal to the length of the ArkTS typed array, **-1** is returned. If a negative number is passed in, the search starts from the end of the ArkTS typed array.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| number | Index of the first occurrence of the value. If the value is not found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The indexOf method cannot be bound. |
| 10200201 | Concurrent modification exception.                |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([3, 5, 9]);
array.indexOf(3); // 0
array.indexOf(7); // -1
array.indexOf(9, 2); // 2
array.indexOf(9, -2); // 2
```

### lastIndexOf<sup>18+</sup>

lastIndexOf(searchElement: number, fromIndex?: number): number

Obtains the index of the last occurrence of the specified value in in this ArkTS typed array.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name          | Type    | Mandatory | Description                                                                               |
| ------------- | ------ | --- | --------------------------------------------------------------------------------- |
| searchElement | number | Yes  | Value to search for.                                                                           |
| fromIndex     | number | No  | Index from which the search starts. The default value is **0**. If the index is greater than or equal to the length of the ArkTS typed array, **-1** is returned. If a negative number is passed in, the search starts from the end of the ArkTS typed array.|

**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| number | Index of the last occurrence of the value. If the value is not found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID   | Error Message                                   |
| -------- | --------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range. |
| 10200011 | The lastIndexOf method cannot be bound. |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([3, 5, 9]);
console.info(array.lastIndexOf(3) + '');
// Expected output: 0
console.info(array.lastIndexOf(7) + '');
// Expected output: -1
console.info(array.lastIndexOf(9, 2) + '');
// Expected output: 2
console.info(array.lastIndexOf(9, -2) + '');
// Expected output: -1
```

### join
join(separator?: string): string

Concatenates all elements in this ArkTS typed array into a string, with a given separator.

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

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The join method cannot be bound. |
| 10200201 | Concurrent modification exception.  |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let joined: string = array.join('-'); // "1-2-3-4-5"
```

### map
map(callbackFn: TypedArrayMapCallback\<number, TypedArray>): TypedArray

Applies a callback function to each element in this ArkTS typed array and uses the result to create an ArkTS typed array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name   | Type  | Mandatory| Description                                                |
| --------- | ------ | ---- | ---------------------------------------------------- |
| callbackFn | [TypedArrayMapCallback](#typedarraymapcallback)\<number, TypedArray> | Yes | Callback function to run for each element.|


**Return value**

| Type        | Description     |
| ------------ | --------- |
| TypedArray | New ArkTS typed array generated.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The map method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([25, 36, 49]);
const mapped: collections.Uint32Array = array.map(Math.sqrt); // Uint32Array [5, 6 ,7]
```

### reduce
reduce(callbackFn: TypedArrayReduceCallback\<number, number, TypedArray>): number

Applies a reduce function on each element in this ArkTS typed array and returns the final reduction result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name    | Type  | Mandatory|  Description    |
| ---------- | ---------------------- | ---- | ------------------------------------------------------------ |
| callbackFn | [TypedArrayReduceCallback](#typedarrayreducecallback)\<number, number, TypedArray> | Yes| Reduce function.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| number | Final result obtained from the last call of the reduce function.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID|                      Error Message                    |
| -------- | ------------------------------------------------ |
| 10200011 | The reduce method cannot be bound.               |
| 10200201 | Concurrent modification exception.               |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let reducedValue: number = array.reduce((accumulator: number, value: number) => accumulator + value);
// reducedValue == 15
```

### reduceRight<sup>18+</sup>

reduceRight(callbackFn: TypedArrayReduceCallback\<number, number, TypedArray>): number

Reversely traverses this ArkTS typed array, applies a reduce function on each element in the array, and returns the final reduction result.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name    | Type  | Mandatory|  Description    |
| ---------- | ---------------------- | ---- | ------------------------------------------------------------ |
| callbackFn | [TypedArrayReduceCallback](#typedarrayreducecallback)\<number, number, TypedArray> | Yes| Reduce function.|

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
| 10200201 | Concurrent modification exception.      |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let reducedValue: number = array.reduceRight((accumulator: number, value: number) => accumulator + value);
console.info(reducedValue + '');
// Expected output: 15
```

### reduce
reduce(callbackFn: TypedArrayReduceCallback\<number, number, TypedArray>, initialValue: number): number

Applies a reduce function for each element in this ArkTS typed array, receives an initial value as the parameter called by the reduce function for the first time, and returns the final reduction result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name   | Type  | Mandatory| Description                                                |
| --------- | ------ | ---- | --------------------------------------------------- |
| callbackFn | [TypedArrayReduceCallback](#typedarrayreducecallback)\<number, number, TypedArray> | Yes | Reduce function.|
| initialValue | number | Yes | Initial value.|


**Return value**

| Type        | Description     |
| ------------ | --------- |
| number | Final result obtained from the last call of the reduce function.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The reduce method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let reducedValue: number = array.reduce((accumulator: number, value: number) => accumulator + value, 1);
// reducedValue == 16
```

### reduceRight<sup>18+</sup>

reduceRight\<U = number>(callbackFn: TypedArrayReduceCallback\<U, number, TypedArray>, initialValue: U): U

Reversely traverses this ArkTS typed array, applies a reduce function for each element in the array, receives an initial value as the parameter called by the reduce function for the first time, and returns the final reduction result.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name   | Type  | Mandatory| Description                                                |
| --------- | ------ | ---- | --------------------------------------------------- |
| callbackFn | [TypedArrayReduceCallback](#typedarrayreducecallback)\<U, number, TypedArray> | Yes | Reduce function.|
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
| 10200201 | Concurrent modification exception.      |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let reducedValue: number = array.reduceRight((accumulator: number, value: number) => accumulator + value, 1);
console.info(reducedValue + '');
// Expected output: 16
```

### reduce
reduce\<U>(callbackFn: TypedArrayReduceCallback\<U, number, TypedArray>, initialValue: U): U

Applies a reduce function for each element in this ArkTS typed array, receives an initial value as the parameter called by the reduce function for the first time, and returns the final reduction result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                                                |
| --------- | ------ | ---- | ---------------------------------------------------- |
| callbackFn | [TypedArrayReduceCallback](#typedarrayreducecallback)\<U, number, TypedArray> | Yes | Reduce function.|
| initialValue | U | Yes | Initial value.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
|  U | Final result obtained from the last call of the reduce function.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The reduce method cannot be bound. |
| 10200201 | Concurrent modification exception.  |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let reducedValue: string = array.reduce<string>((accumulator: string, value: number) => accumulator + value, "initialValue");
// reducedValue == initialValue12345
```

### reverse
reverse(): TypedArray

Reverses this ArkTS typed array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type        | Description     |
| ------------ | --------- |
| TypedArray   | Reversed ArkTS typed array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The reverse method cannot be bound. |
| 10200201 | Concurrent modification exception.   |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let reversed: collections.Uint32Array = array.reverse(); // Uint32Array [5, 4, 3, 2, 1]
```

### set
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

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The set method cannot be bound. |
| 10200201 | Concurrent modification exception.  |

**Example**

```ts
let buffer: collections.ArrayBuffer = new collections.ArrayBuffer(8);
let array: collections.Uint8Array = new collections.Uint8Array(buffer);
array.set([1, 2, 3], 3); // Uint8Array [0, 0, 0, 1, 2, 3, 0, 0]
```

### slice
slice(start?: number, end?: number): TypedArray

Selects a range of elements in this ArkTS typed array to create an ArkTS typed array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                                                  |
| ------ | ------ | ---- | -----------------------------------------------------|
| start  | number | No  | Start index of the range. If a negative number is passed in, it refers to the index of **start + typedarray.length**. The default value is **0**.|
| end    | number | No  | End index of the range (exclusive). If a negative number is passed in, it refers to the index of **end + typedarray.length**. The default value is the length of the ArkTS typed array.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| TypedArray | New ArkTS typed array generated.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The slice method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
array.slice(); // Uint32Array [1, 2, 3, 4, 5]
array.slice(1, 3); // Uint32Array [2, 3]
array.slice(-2); // Uint32Array [4, 5]
```

### sort
sort(compareFn?: TypedArrayCompareFn\<number>): TypedArray

Sorts elements in this ArkTS typed array and returns the sorted ArkTS typed array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type                  | Mandatory| Description                                      |
| --------- | ---------------------- | ---- | ------------------------------------------ |
| compareFn | [TypedArrayCompareFn](#typedarraycomparefn)\<number> | No  | Function that determines the sort order. By default, elements are sorted in ascending order.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| TypedArray | Sorted ArkTS typed array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------ |
| 10200011 | The sort method cannot be bound. |
| 10200201 | Concurrent modification exception.         |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 3, 5, 4, 2]);
array.sort(); // Uint32Array [1, 2, 3, 4, 5]
array.sort((a: number, b: number) => a - b); // Uint32Array [1, 2, 3, 4, 5]
array.sort((a: number, b: number) => b - a); // Uint32Array [5, 4, 3, 2, 1]
```

### subarray
subarray(begin?: number, end?: number): TypedArray

Returns a new ArkTS typed array based on the same ArkTS ArrayBuffer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                                               |
| ------ | ------ | ---- | ------------------------------------------------- |
| begin  | number | No  | Start index of the range. If a negative number is passed in, it refers to the index of **begin + typedarray.length**. The default value is **0**.|
| end    | number | No  | End index of the range (exclusive). If a negative number is passed in, it refers to the index of **end + typedarray.length**. The default value is the length of the ArkTS typed array.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| TypedArray | New ArkTS typed array generated.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID|            Error Message                              |
| -------- | -------------------------------------------------|
| 10200011 | The subarray method cannot be bound.             |
| 10200201 | Concurrent modification exception.               |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let subArray: collections.Uint32Array = array.subarray(); // Uint32Array [1, 2, 3, 4, 5]
subArray.set([10, 20, 30]); // Uint32Array [10, 20, 30, 4, 5]
```

### at
at(index: number): number | undefined

Returns the element at the given index. If no element is found, **undefined** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| index  | number | Yes  | Index of the element. The index in an array always starts from 0 and is an integer. If a negative number is passed in, it refers to the index of **index + typedarray.length**.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| number \| undefined| Element obtained. If no element is found, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID|                       Error Message                   |
| -------- | ------------------------------------------------ |
| 10200011 | The at method cannot be bound.                   |
| 10200201 | Concurrent modification exception.               |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
console.info("element: " + array.at(2));  // element: 3
console.info("element: " + array.at(-1)); // element: 5
console.info("element: " + array.at(6));  // element: undefined
```

### includes
includes(searchElement: number, fromIndex?: number): boolean

Checks whether elements are contained in this ArkTS typed array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name| Type  | Mandatory| Description                                     |
| ------ | ------ | ---- | --------------------------------------- |
| searchElement  | number | Yes  | Element to search for.|
| fromIndex  | number | No | Index from which the search starts. If a negative number is passed in, it refers to the index of **fromIndex + typedarray.length**. The default value is **0**.|

**Return value**

| Type   | Description                                                       |
| ------- | ---------------------------------------------------------- |
| boolean | Check result. The value **true** means that the element exists, and **false** means the opposite.|


**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The includes method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3]);
console.info("includes: " + array.includes(2));    // includes: true
console.info("includes: " + array.includes(4));    // includes: false
console.info("includes: " + array.includes(3, 3)); // includes: false
```

### entries
entries(): IterableIterator\<[number, number]>

Returns an iterator object that contains the key-value pair of each element in this ArkTS typed array.

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
| 10200201 | Concurrent modification exception. |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([11, 22, 33]);
let iterator: IterableIterator<[number, number]> = array.entries();
console.info("value: " + iterator.next().value); // value: [0, 11]
console.info("value: " + iterator.next().value); // value: [1, 22]
console.info("value: " + iterator.next().value); // value: [2, 33]
```

### keys
keys(): IterableIterator\<number>

Returns an iterator object that contains the key (index) of each element in this ArkTS typed array.

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
| 10200201 | Concurrent modification exception. |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let iterator: IterableIterator<number> = array.keys();
for (const key of iterator) {
  console.info("" + key); // 0, 1, 2, 3, and 4 are returned in sequence.
}
```

### values
values(): IterableIterator\<number>

Returns an iterator object that contains the value of each element in this ArkTS typed array.

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
| 10200201 | Concurrent modification exception.  |

**Example**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let iterator: IterableIterator<number> = array.values();
for (const value of iterator) {
  console.info("" + value); // 1, 2, 3, 4, and 5 are returned in sequence.
}
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;number&gt;

Obtains an iterator, each item of which is a JavaScript object.

> **NOTE**
>
> This API cannot be used in .ets files.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                     | Description            |
| ------------------------- | ---------------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**Example**

```ts
let int32Array: collections.Int32Array = collections.Int32Array.from([1, 2, 3, 4, 5, 6]);

for (let item of int32Array) {
  console.info(`value : ${item}`);
}
```

### [index: number]

&#91;index: number&#93;: number

Returns the element at a given index in this TypedArray. This API is applicable to Int8Array, Int16Array, Int32Array, Uint8Array, Uint16Array, Uint32Array, Float32Array, and Float64Array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name   | Type  | Mandatory| Description                    |
| ----- | ------ | ---- | -------------------------- |
| index | number | Yes  | Index of the element. The index starts from zero.|

**Return value**

| Type  | Description                |
| ----- | ---------------------|
| number | Number data type.|

**Example**

```ts
let int8Array = collections.Int8Array.from([1, 2, 4]);
console.info("Element at index 1: ", int8Array[1]);
let int16Array = collections.Int16Array.from([1, 2, 4]);
console.info("Element at index 1: ", int16Array[1]);
let int32Array = collections.Int32Array.from([1, 2, 4]);
console.info("Element at index 1: ", int32Array[1]);
let uint8Array = collections.Uint8Array.from([1, 2, 4]);
console.info("Element at index 1: ", uint8Array[1]);
let uint16Array = collections.Uint16Array.from([1, 2, 4]);
console.info("Element at index 1: ", uint16Array[1]);
let uint32Array = collections.Uint32Array.from([1, 2, 4]);
console.info("Element at index 1: ", uint32Array[1]);
let float32Array = collections.Float32Array.from([1, 2, 4]);
console.info("Element at index 1: ", float32Array[1]);
let uint8Clamped = collections.Uint8ClampedArray.from([1, 2, 4]);
console.info("Element at index 1: ", uint8Clamped[1]);
```

## collections.BitVector

A linear data structure that is implemented on arrays. A bit vector stores bit values and provides bit-level storage and processing.

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name  | Type  | Read Only| Optional| Description                 |
| ------ | ------ | ---- | ---- | --------------------- |
| length | number | Yes  | No  | Number of elements in a bit vector.|


### constructor

constructor(length: number)

Constructor used to create a bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                   |
| ------ | ------ | ---- | ----------------------- |
| length | number | Yes  | Length of the bit vector.|

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
```


### push

push(element:number): boolean

Adds an element at the end of this bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                               |
| ------- | ------ | ---- | ----------------------------------- |
| element | number | Yes  | Element to add. The value **0** indicates bit value 0, and other values indicate bit value 1.|

**Return value**

| Type   | Description                             |
| ------- | --------------------------------- |
| boolean | Operation result. The value **true** means that the element is added, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200011 | The push method cannot be bound.                             |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
```

### pop

pop(): number

Removes the last element from this bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                                      |
| ------ | ------------------------------------------ |
| number | Element (bit value) removed.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                       |
| -------- | ------------------------------- |
| 10200011 | The pop method cannot be bound. |
| 10200201 | Concurrent modification error.  |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let res = bitVector.pop(); // bitVector: [0, 1, 0, 1]
console.info("bitVector pop:", res); // 0
```

### has

has(element: number, fromIndex: number, toIndex: number): boolean

Checks whether a bit value is included in a given range of this bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                                |
| --------- | ------ | ---- | ------------------------------------ |
| element   | number | Yes  | Bit value. The value **0** indicates bit value 0, and other values indicate bit value 1.|
| fromIndex | number | Yes  | Start index of the range (inclusive).        |
| toIndex   | number | Yes  | End index of the range (inclusive).      |

**Return value**

| Type   | Description                                  |
| ------- | -------------------------------------- |
| boolean | Check result. The value **true** means that the bit value exists, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The has method cannot be bound.                              |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let res0: boolean = bitVector.has(0, 1, 4);
console.info("bitVector has 0:", res0); // true
```

### setBitsByRange

setBitsByRange(element: number, fromIndex: number, toIndex: number): void

Sets elements in a given range in this bit vector to a bit value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                              |
| --------- | ------ | ---- | ---------------------------------- |
| element   | number | Yes  | Bit value to set. The value **0** indicates bit value 0, and other values indicate bit value 1.|
| fromIndex | number | Yes  | Start index of the range (inclusive).      |
| toIndex   | number | Yes  | End index of the range (exclusive).    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The setBitsByRange method cannot be bound.                   |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
bitVector.setBitsByRange(1, 1, 3); // bitVector: [0, 1, 1, 1, 0]
```

### setAllBits

setAllBits(element: number): void

Sets all elements in this bit vector to a bit value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                               |
| ------- | ------ | ---- | ----------------------------------- |
| element | number | Yes  | Bit value to set. The value **0** indicates bit value 0, and other values indicate bit value 1.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200011 | The setAllBits method cannot be bound.                       |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
bitVector.setAllBits(1); // bitVector: [1, 1, 1, 1, 1]
```

### getBitsByRange

getBitsByRange(fromIndex: number, toIndex: number): BitVector

Obtains bit values within a given range of this bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                          |
| --------- | ------ | ---- | ------------------------------ |
| fromIndex | number | Yes  | Start index of the range (inclusive).  |
| toIndex   | number | Yes  | End index of the range (exclusive).|

**Return value**

| Type     | Description                              |
| --------- | ---------------------------------- |
| BitVector | Bit vector containing the bit values obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The getBitsByRange method cannot be bound.                   |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let bitVector2 = bitVector.getBitsByRange(1, 3); // bitVector2: [1, 0]
console.info("bitVector2 length:", bitVector2.length); // 2
```

### resize

resize(size: number): void

Resizes this bit vector.

If **size** is greater than the length of the existing bit vector, the bit vector is extended, and elements of the extra part are set to 0.

If **size** is less than or equal to the length of the existing bit vector, the bit vector is shrunk according to the size.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| size   | number | Yes  | New length.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200011 | The resize method cannot be bound.                           |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
bitVector.resize(10); // bitVector: [0, 1, 0, 1, 0, 0, 0, 0, 0, 0]
console.info("bitVector get bit vector's length:", bitVector.length); // 10
bitVector.resize(3); // bitVector: [0, 1, 0]
console.info("bitVector get bit vector's length:", bitVector.length); // 3
```

### getBitCountByRange

getBitCountByRange(element: number, fromIndex: number, toIndex: number): number

Counts the number of bit values in a given range of this bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                                |
| --------- | ------ | ---- | ------------------------------------ |
| element   | number | Yes  | Bit value. The value **0** indicates bit value 0, and other values indicate bit value 1.|
| fromIndex | number | Yes  | Start index of the range (inclusive).        |
| toIndex   | number | Yes  | End index of the range (exclusive).      |

**Return value**

| Type  | Description                               |
| ------ | ----------------------------------- |
| number | Number of bit values.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The getBitCountByRange method cannot be bound.               |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let res: number = bitVector.getBitCountByRange(1, 1, 4);
console.info("bitVector getBitCountByRange:", res); // 2
```

### getIndexOf

getIndexOf(element: number, fromIndex: number, toIndex: number): number

Returns the index of the first occurrence of a bit value in this bit vector. If the bit value is not found, **-1** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                                |
| --------- | ------ | ---- | ------------------------------------ |
| element   | number | Yes  | Bit value. The value **0** indicates bit value 0, and other values indicate bit value 1.|
| fromIndex | number | Yes  | Start index of the range (inclusive).        |
| toIndex   | number | Yes  | End index of the range (exclusive).      |

**Return value**

| Type  | Description                                             |
| ------ | ------------------------------------------------- |
| number | Index of the first occurrence of the bit value. If the bit value is not found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The getIndexOf method cannot be bound.                       |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let res: number = bitVector.getIndexOf(0, 1, 4);
console.info("bitVector getIndexOf:", res); // 2
```

### getLastIndexOf

getLastIndexOf(element: number, fromIndex: number, toIndex: number): number

Returns the index of the last occurrence of a bit value in this bit vector. If the bit value is not found, **-1** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                                |
| --------- | ------ | ---- | ------------------------------------ |
| element   | number | Yes  | Bit value. The value **0** indicates bit value 0, and other values indicate bit value 1.|
| fromIndex | number | Yes  | Start index of the range (inclusive).        |
| toIndex   | number | Yes  | End index of the range (exclusive).      |

**Return value**

| Type  | Description                                                 |
| ------ | ----------------------------------------------------- |
| number | Index of the last occurrence of the bit value. If the bit value is not found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The getLastIndexOf method cannot be bound.                   |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let res: number = bitVector.getLastIndexOf(0, 1, 4);
console.info("bitVector getLastIndexOf:", res); // 2
```

### flipBitByIndex

flipBitByIndex(index: number): void

Flips the bit value (from 0 to 1 or from 1 to 0) at a given index in this bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| index  | number | Yes  | Index.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200001 | The value of index is out of range.                          |
| 10200011 | The flipBitByIndex method cannot be bound.                   |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
bitVector.flipBitByIndex(3); // bitVector: [0, 1, 0, 0, 0]
```

### flipBitsByRange

flipBitsByRange(fromIndex: number, toIndex: number): void

Flips the bit values (from 0 to 1 or from 1 to 0) in a given range in this bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                          |
| --------- | ------ | ---- | ------------------------------ |
| fromIndex | number | Yes  | Start index of the range (inclusive).  |
| toIndex   | number | Yes  | End index of the range (exclusive).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The flipBitsByRange method cannot be bound.                  |
| 10200201 | Concurrent modification error.                               |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
bitVector.flipBitsByRange(1, 4); // bitVector: [0, 0, 1, 0, 0]
```

### values

values(): IterableIterator\<number>

Returns an iterator object that contains the value of each element in this bit vector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                          | Description                         |
| ------------------------------ | ----------------------------- |
| IterableIterator&lt;number&gt; | Bit vector iterator object.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                          |
| -------- | ---------------------------------- |
| 10200011 | The values method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let iter: IterableIterator<number> = bitVector.values();
let temp: IteratorResult<number> = iter.next();
while (!temp.done) {
  console.info(JSON.stringify(temp.value));
  temp = iter.next();
} // 0, 1, 0, 1, and 0 are returned in sequence.
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;number&gt;

Obtains an iterator, each item of which is a JavaScript object.

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
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);

for (let item of bitVector) {
  console.info("value: " + item);
}
```

### [index: number]

&#91;index: number&#93;: number

Returns the element at a given index in this BitVector.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name   | Type  | Mandatory| Description                    |
| ----- | ------ | ---- | -------------------------- |
| index | number | Yes  | Index of the element. The index starts from zero.|

**Return value**

| Type  | Description                |
| ----- | ---------------------|
| number | Number data type.|

**Example**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
console.info("BitVector Element Index at 1: " + bitVector[1]);
```
