# Class (Array)
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

A linear data structure that is implemented on arrays and can be passed between ArkTS concurrent instances.

Pass-by-reference is recommended for better transfer performance.

This section uses the following to identify the use of generics:

- T: type, which can be any of the [sendable data types](../../arkts-utils/arkts-sendable.md#sendable-data-types).

**Decorator**: \@Sendable

## Modules to Import

```ts
import { collections } from '@kit.ArkTS';
```

## Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name  | Type  | Read Only| Optional| Description             |
| ------ | ------ | ---- | ---- | ----------------- |
| length | number | Yes  | No  | Number of elements in an ArkTS array.|


## constructor

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

## constructor

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                           |
| -------- | --------------------------------------------------- |
| 401      | Parameter error.                                    |
| 10200012 | The Array's constructor cannot be directly invoked. |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4);
```
## constructor

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

## create

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401      | Parameter error.                   |

**Example**

```ts
let array = collections.Array.create<number>(3, 10); // [10, 10, 10]
```

## from

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401      | Parameter error.                 |

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

## from

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

**Example**

```ts
// Positive example:
const mapper = new Map([
  ['1', 'a'],
  ['2', 'b'],
]);
let newArray: collections.Array<string> = collections.Array.from(mapper.values());
console.info(newArray.toString()); // Expected output: a,b
```

## from<sup>18+</sup>

static from\<T>(arrayLike: ArrayLike\<T> | Iterable\<T>, mapFn: ArrayFromMapFn\<T, T>): Array\<T>

Creates an ArkTS array from an array-like object, and uses a custom function to process each array element.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type         | Mandatory| Description                           |
| --------- | ------------- | ---- | ------------------------------- |
| arrayLike | ArrayLike\<T> \| Iterable\<T> | Yes  | Array-like object.|
| mapFn | [ArrayFromMapFn](arkts-apis-arkts-collections-Types.md#arrayfrommapfn18)\<T,T> | Yes  | Functions used to process the array elements.|

**Return value**

| Type     | Description                   |
| --------- | ----------------------- |
| Array\<T> | Newly created ArkTS array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
let array : Array<number> = [1, 2, 3]; // Native Array<T>, where T is of the Sendable type.
let newArray = collections.Array.from<number>(array, (value, index) => value + index); // Return a new Array<T>.
console.info(newArray.toString()); // Expected output: 1, 3, 5
```

## from<sup>18+</sup>

static from\<U, T>(arrayLike: ArrayLike\<U> | Iterable\<U>, mapFn: ArrayFromMapFn\<U, T>): Array\<T>

Creates an ArkTS array from an array-like object, and uses a custom function to process each array element. The type of the elements in the array-like object can be different from that of the array elements.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type         | Mandatory| Description                           |
| --------- | ------------- | ---- | ------------------------------- |
| arrayLike | ArrayLike\<U> \| Iterable\<U> | Yes  | Array-like object.|
| mapFn | [ArrayFromMapFn](arkts-apis-arkts-collections-Types.md#arrayfrommapfn18)\<U, T> | Yes  | Functions used to process the array elements.|

**Return value**

| Type     | Description                   |
| --------- | ----------------------- |
| Array\<T> | Newly created ArkTS array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
let array : Array<number> = [1, 2, 3]; // Native Array<T>
let newArray = collections.Array.from<number, string>(array, (value, index) => value + "." + index); // Return a new Array<T>.
console.info(newArray.toString()); // Expected output: 1.0, 2.1, 3.2
```

## isArray<sup>18+</sup>

static isArray(value: Object | undefined | null): boolean

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
| boolean | Check result. The value **true** is returned if the input parameter is an ArkTS array; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
let arr: collections.Array<string> = new collections.Array('a', 'b', 'c', 'd');
let result: boolean = collections.Array.isArray(arr);
console.info(result + ''); // Expected output: true
```

## of<sup>18+</sup>

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
let arr: collections.Array<string> = collections.Array.of('a', 'b', 'c', 'd');
console.info(arr.toString()); // Expected output: a, b, c, d
```

## copyWithin<sup>18+</sup>
copyWithin(target: number, start: number, end?: number): Array\<T>

Copies elements within a given range from this ArkTS array to another position in sequence.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| target | number | Yes| Start index of the range. If a negative number is passed in, it refers to the index of `target + array.length`.|
| start | number | Yes| Start index of the range. If a negative number is passed in, it refers to the index of **start + array.length**.|
| end | number | No| End index of the range. If a negative number is passed in, it refers to the index of `end + array.length`. The default value is the length of the ArkTS array.|

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
| 10200201 | Concurrent modification error.               |

**Example**

```ts
let array: collections.Array<number> = collections.Array.from([1, 2, 3, 4, 5, 6, 7, 8]);
let copied: collections.Array<number> = array.copyWithin(3, 1, 3);
console.info(copied.toString()); // Expected output: 1, 2, 3, 2, 3, 6, 7, 8
```

## lastIndexOf<sup>18+</sup>

lastIndexOf(searchElement: T, fromIndex?: number): number

Obtains the index of the last occurrence of the specified value in this ArkTS array.

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

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID   | Error Message                                   |
| -------- | --------------------------------------- |
| 10200011 | The lastIndexOf method cannot be bound. |
| 10200201 | Concurrent modification error.      |

**Example**

```ts
let array: collections.Array<number> = collections.Array.from([3, 5, 9]);
console.info(array.lastIndexOf(3) + ''); // Expected output: 0
console.info(array.lastIndexOf(7) + ''); // Expected output: -1
console.info(array.lastIndexOf(9, 2) + ''); // Expected output: 2
console.info(array.lastIndexOf(9, -2) + ''); // Expected output: -1
```

## some<sup>18+</sup>
some(predicate: ArrayPredicateFn\<T, Array\<T>>): boolean

Checks whether this ArkTS array contains an element that meets certain conditions.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                 |
| ------- | ------ | ---- | ---------------------------------------------------- |
| predicate | [ArrayPredicateFn](arkts-apis-arkts-collections-Types.md#arraypredicatefn18)\<T, Array\<T>> | Yes| Assertion function used for the test.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| boolean | Check result. The value **true** is returned if an element meeting the given condition exists; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                           |
| -------- | ---------------------------------- |
| 10200011 | The some method cannot be bound.   |
| 10200201 | Concurrent modification error. |

**Example**

```ts
let newArray: collections.Array<number> = collections.Array.from([-10, 20, -30, 40, -50]);
console.info(newArray.some((element: number) => element < 0) + ''); // Expected output: true
```

## reduceRight<sup>18+</sup>

reduceRight(callbackFn: ArrayReduceCallback\<T, T, Array\<T>>): T

Goes through each element in this ArkTS array from right to left, uses a callback function to combine them into a single value, and returns that final value.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name       | Type                                                                              | Mandatory | Description                                        |
| ---------- | -------------------------------------------------------------------------------- | --- | ------------------------------------------ |
| callbackFn | [ArrayReduceCallback](arkts-apis-arkts-collections-Types.md#arrayreducecallback18)\<T, T, Array\<T>> | Yes  | Function that takes four arguments. It performs an operation on each element and passes the result as an accumulated value to the next element.|

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
console.info(reducedValue + ''); // Expected output: 15
```

## reduceRight<sup>18+</sup>

reduceRight\<U = T>(callbackFn: ArrayReduceCallback\<U, T, Array\<T>>, initialValue: U): U

This API is similar to the [reduceRight](#reduceright18) API, but it takes an initial value as the second parameter to initialize the accumulator before the array traversal starts from right to left.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name         | Type                                                                                          | Mandatory | Description                                        |
| ------------ | -------------------------------------------------------------------------------------------- | --- | ------------------------------------------ |
| callbackFn   | [ArrayReduceCallback](arkts-apis-arkts-collections-Types.md#arrayreducecallback18)\<U, T, Array\<T>> | Yes  | Function that takes four arguments. It performs an operation on each element and passes the result as an accumulated value to the next element.|
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
console.info(reducedValue + ''); // Expected output: 15
```

## pop

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

## push

push(...items: T[]): number

Adds elements to the end of this ArkTS array and returns the new length of the array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description                              |
| ------ | ---- | ---- | ---------------------------------- |
| items  | T[]  | No  | Elements to add.|

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | New length of the array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401      | Parameter error.                 |
| 10200011 | The push method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3);
let length = array.push (4, 5); // 5 is returned. The array changes to [1, 2, 3, 4, 5].
```

## join

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401      | Parameter error.                 |
| 10200011 | The join method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**Example**

```ts
let array = new collections.Array<string>('a', 'b', 'c');
let joinedString = array.join('-'); // "a-b-c" is returned.
```

## shift

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

## reverse<sup>18+</sup>

reverse(): Array\<T>

Reverses elements in this ArkTS array and returns a reference to the same array.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                |
| ----- | ------------------ |
| Array\<T> | Reversed ArkTS array.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID   | Error Message                               |
| -------- | ----------------------------------- |
| 10200011 | The reverse method cannot be bound. |
| 10200201 | Concurrent modification error.  |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let reversed = array.reverse();
console.info(array.toString()); // Expected output: 5, 4, 3, 2, 1
```

## unshift

unshift(...items: T[]): number

Adds elements to the beginning of this ArkTS array and returns the new length of the array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description                    |
| ------ | ---- | ---- | ------------------------ |
| items  | T[]  | No  | Elements to add.|

**Return value**

| Type  | Description          |
| ------ | -------------- |
| number | New length of the array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401      | Parameter error.                    |
| 10200011 | The unshift method cannot be bound. |
| 10200201 | Concurrent modification error.      |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3);
let newLength = array.unshift(0); // 4 is returned. The array changes to [0, 1, 2, 3].
```

## toString<sup>18+</sup>

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
console.info(stringArray); // Expected output: 1,2,3,4,5
```

## slice

slice(start?: number, end?: number): Array\<T>

Selects a range of elements in this ArkTS array to create an array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| start  | number | No  | Start index of the range. If a negative number is passed in, it refers to the index of **start + array.length**. The default value is **0**.  |
| end    | number | No  | End index of the range (exclusive). If a negative number is passed in, it refers to the index of **end + array.length**. The default value is the length of the original ArkTS array.|

**Return value**

| Type     | Description                      |
| --------- | -------------------------- |
| Array\<T> | New array containing the selected elements.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 401      | Parameter error.                  |
| 10200011 | The slice method cannot be bound. |
| 10200201 | Concurrent modification error.    |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let slicedArray = array.slice (1, 3); // [2, 3] is returned. The original array remains unchanged.
```

## sort

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401      | Parameter error.                 |
| 10200011 | The sort method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**Example**

```ts
let array = new collections.Array<number>(1, 3, 5, 4, 2);
array.sort((a: number, b: number) => a - b); // [1, 2, 3, 4, 5]
array.sort((a: number, b: number) => b - a); // [5, 4, 3, 2, 1]
```

## indexOf

indexOf(searchElement: T, fromIndex?: number): number

Returns the index of the first occurrence of a value in this ArkTS Array. If the value is not found, **-1** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name       | Type  | Mandatory| Description                       |
| ------------- | ------ | ---- | --------------------------- |
| searchElement | T      | Yes  | Value to search for.               |
| fromIndex     | number | No  | Index from which the search starts. The value begins at 0. The default value is **0**.|

**Return value**

| Type  | Description                                          |
| ------ | ---------------------------------------------- |
| number | Index of the first occurrence of the value. If the value is not found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401      | Parameter error.                    |
| 10200011 | The indexOf method cannot be bound. |
| 10200201 | Concurrent modification error.      |

**Example**

```ts
let array = new collections.Array<string>('a', 'b', 'c');
let index = array.indexOf('b'); // 1 is returned because 'b' is at index 1.
```

## forEach

forEach(callbackFn: (value: T, index: number, array: Array\<T>) => void): void

Calls a callback function for each element in this ArkTS Array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type                                               | Mandatory| Description                          |
| ---------- | --------------------------------------------------- | ---- | ------------------------------ |
| callbackFn | (value: T, index: number, array: Array\<T>) => void | Yes  | Callback function to run for each element.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401      | Parameter error.                    |
| 10200011 | The forEach method cannot be bound. |
| 10200201 | Concurrent modification error.      |

**Example**

```ts
let array = new collections.Array<string>('a', 'b', 'c');
array.forEach((value, index, array) => {
  console.info(`Element ${value} at index ${index}`);
});
```

## map

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 10200011 | The map method cannot be bound. |
| 10200201 | Concurrent modification error.  |

**Example**

```ts
// Convert each string element in the original array to uppercase and return a new array containing the new strings.
let array = new collections.Array<string>('a', 'b', 'c');
let mappedArray = array.map((value, index, array) => {
  return value.toUpperCase(); // Convert each string element to uppercase.
});
console.info("" + mappedArray); // Output: A, B, C
```

## filter

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                          |
| -------- | ---------------------------------- |
| 401      | Parameter error.                   |
| 10200011 | The filter method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let filteredArray = array.filter((value : number) => value % 2 === 0); // [2, 4] is returned. This new array contains only even numbers.
```

## reduce

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                          |
| -------- | ---------------------------------- |
| 401      | Parameter error.                   |
| 10200011 | The reduce method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let reducedValue = array.reduce((accumulator, value) => accumulator + value); // 15, which is the final accumulated result of all elements, is returned.
```

## reduce

reduce\<U>(callbackFn: (previousValue: U, currentValue: T, currentIndex: number, array: Array\<T>) => U, initialValue: U): U

Similar to the previous API, this API takes an initial value as the second parameter to initialize the accumulator before the array traversal starts.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callbackFn   | (previousValue: U, currentValue: T, currentIndex: number, array: Array\<T>) => U | Yes  | Function that takes four arguments. It performs an operation on each element and passes the result as an accumulated value to the next element.|
| initialValue | U                                                            | Yes  | Initial value of the accumulator.                                      |

**Return value**

| Type| Description                      |
| ---- | -------------------------- |
| U    | Final result obtained from the last call of the callback function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                          |
| -------- | ---------------------------------- |
| 401      | Parameter error.                   |
| 10200011 | The reduce method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**Example**

```ts
// An accumulator with the initial value 0 is used. The accumulator is used to calculate the sum of all elements in the array and return the sum.
let array = new collections.Array(1, 2, 3, 4, 5);
let reducedValue = array.reduce<number>((accumulator: number, value: number) => accumulator + value, 0); // 15, which is the final accumulated result of all elements, is returned. The initial value is 0.
```

## at

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 401      | Parameter error.               |
| 10200011 | The at method cannot be bound. |
| 10200201 | Concurrent modification error. |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let elementAtIndex = array.at(2); // 3 is returned. This is because the index starts from 0.
```

## entries

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

## keys

keys(): IterableIterator\<number>

Returns an iterator object that contains the index of each element in this ArkTS array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                     | Description                                  |
| ------------------------- | -------------------------------------- |
| IterableIterator\<number> | Iterator object that contains the index of each element in the array.|

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

## values

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

## find

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401      | Parameter error.                 |
| 10200011 | The find method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let foundValue = array.find((value: number) => value % 2 === 0); // 2, the first even element, is returned.
```

## includes

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
| boolean | Check result. The value **true** is returned if the element exists; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                            |
| -------- | ------------------------------------ |
| 401      | Parameter error.                     |
| 10200011 | The includes method cannot be bound. |
| 10200201 | Concurrent modification error.       |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let includesResult = array.includes(3); // true is returned, because the array contains 3.
```

## findIndex

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 401      | Parameter error.                      |
| 10200011 | The findIndex method cannot be bound. |
| 10200201 | Concurrent modification error.        |

**Example**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let foundIndex = array.findIndex((value: number) => value % 2 === 0); // 1 is returned, because 2 is the first even element.
```

## fill

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401      | Parameter error.                 |
| 10200011 | The fill method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**Example**

```ts
let array = new collections.Array(1, 2, 3, 4, 5);
array.fill(0, 1, 3); // [1, 0, 0, 4, 5] is returned, because elements in the index range from 1 to 3 are filled with 0.
```

## shrinkTo

shrinkTo(arrayLength: number): void

Shrinks this ArkTS array to a given length.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                                                  |
| ------ | ------ | ---- | ------------------------------------------------------ |
| arrayLength  | number  | Yes  | New length of the array. If a value greater than or equal to the current array length is passed in, the array does not change.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401      | Parameter error.                 |
| 10200011 | The shrinkTo method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**Example**

```ts
let array1 = new collections.Array(1, 2, 3, 4, 5);
array1.shrinkTo(1); // The array is changed to [1].

let array2 = new collections.Array(1, 2, 3, 4, 5);
array2.shrinkTo(10); // The array remains unchanged.
```

## extendTo

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 401      | Parameter error.                 |
| 10200011 | The extendTo method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**Example**

```ts
let array1 = new collections.Array(1, 2, 3);
array1.extendTo (5, 10); // The array is changed to [1, 2, 3, 10, 10].

let array2 = new collections.Array(1, 2, 3);
array2.extendTo (1, 10); // The array remains unchanged.
```

## concat

concat(...items: ConcatArray\<T>[]): Array\<T>

Concatenates this ArkTS array with one or more arrays.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description                              |
| ------ | ---- | ---- | ---------------------------------- |
| items  | ConcatArray\<T>[]  | No  | Concatenates this ArkTS array with one or more arrays.|

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

## splice

splice(start: number): Array\<T>

Removes elements from a specified position in an array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type | Mandatory| Description                                                               |
| ----- | ------ | -- | ------------------------------------------------------------------- |
| start | number | Yes| Index from which the removal starts. If `-array.length =< start < 0`, the removal starts from `start + array.length`. If `start < -array.length`, the removal starts from **0**.|

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

## every<sup>18+</sup>

every(predicate: ArrayPredicateFn\<T, Array\<T>>): boolean

Checks whether all elements in this ArkTS array meet a given condition.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Utils.Lang

**Parameters**
| Name | Type  | Mandatory| Description                                                   |
| ------- | ------ | ---- | ----------------------------------------------------- |
| predicate | [ArrayPredicateFn](arkts-apis-arkts-collections-Types.md#arraypredicatefn18)\<T, Array\<T>> | Yes| Assertion function used for the test.|

**Return value**

| Type        | Description     |
| ------------ | --------- |
| boolean | Check result. The value **true** is returned if all elements meet the given condition; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The every method cannot be bound. |
| 10200201 | Concurrent modification error. |

**Example**

```ts
let newArray: collections.Array<number> = collections.Array.from([-10, 20, -30, 40, -50]);
console.info(newArray.every((element: number) => element > 0) + ''); // Expected output: false
```

## toLocaleString<sup>18+</sup>

toLocaleString(): string

Generates a string that matches the cultural conversions of the current system locale. Each element converts itself to a string via its **toLocaleString** API, and these strings are then joined in sequence with commas (,).

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
console.info(stringArray); // Expected output: 1,000,Test,53,621
```

## splice

splice(start: number, deleteCount: number, ...items: T[]): Array\<T>

Removes elements from a specified position in an array, and inserts new elements from the same position.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name      | Type  | Mandatory| Description                                                               |
| ----------- | ------ | --  | ------------------------------------------------------------------- |
| start       | number | Yes | Index from which the removal starts. If `-array.length =< start < 0`, the removal starts from `start + array.length`. If `start < -array.length`, the removal starts from **0**.|
| deleteCount | number | Yes | Number of elements to remove. If `deleteCount <= 0`, no element is removed.|
| items       | T[]    | No | New elements to insert from the `start` position. If no value is passed in, only the elements in the array are removed.       |

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

## [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

Returns an iterator, each item of which is a JavaScript object.

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

## [index: number]

&#91;index: number&#93;: T

Returns the element at a given index in this array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

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
