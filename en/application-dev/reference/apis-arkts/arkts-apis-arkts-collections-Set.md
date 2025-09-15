# Class (Set)
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

A non-linear data structure.

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

| Name| Type  | Read Only| Optional| Description           |
| ---- | ------ | ---- | ---- | --------------- |
| size | number | Yes  | No  | Number of elements in a set.|

## constructor

constructor(values?: readonly T[] | null)

A constructor used to create an ArkTS set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description                                                     |
| ------ | ---- | ---- | --------------------------------------------------------- |
| values | readonly T[] \| null | No| Array or iterator object. The default value is **null**, indicating that an empty set is created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error.                                        |
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

## entries
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
| 10200201 | Concurrent modification error. |

**Example**

```ts
const mySet = new collections.Set<number>([0, 1, 2, 3]);

const iterator = mySet.entries();
// Expected output: [0, 0]
console.info(iterator.next().value);
// Expected output: [1, 1]
console.info(iterator.next().value);
```

## keys
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
| 10200201 | Concurrent modification error. |

**Example**

```ts
const mySet = new collections.Set<number>([0, 1, 2, 3]);

const iterator = mySet.keys();
// Expected output: 0
console.info(iterator.next().value);
// Expected output: 1
console.info(iterator.next().value);
```

## values
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
| 10200201 | Concurrent modification error. |

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

## clear
clear(): void

Removes all elements from this ArkTS set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                           |
| -------- | --------------------------------------------------- |
| 10200011 | The clear method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                  |

**Example**

```ts
const mySet = new collections.Set<number>([0, 1]);
// Expected output: 2
console.info("size:" + mySet.size);
mySet.clear();
// Expected output: 0
console.info("size:" + mySet.size);
```

## delete
delete(value: T): boolean

Deletes an element from this ArkTS set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description            |
| ------ | ---- | ---- | ---------------- |
| value    | T    | Yes  | Target value.|

**Return value**

| Type   | Description                             |
| ------- | --------------------------------- |
| boolean | Operation result. The value **true** is returned if the key is deleted; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 10200011 | The delete method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                   |


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

## forEach
forEach(callbackFn: (value: T, value2: T, set: Set\<T>) => void): void

Calls a callback function for each key-value pair in this ArkTS set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type                                        | Mandatory| Description      |
| ---------- | -------------------------------------------- | ---- | ---------- |
| callbackFn | (value: T, value2: T, set: Set\<T>) => void  | Yes  | Callback function to run for each key-value pair. |

callbackFn parameters
| Name| Type        | Mandatory| Description                        |
| ------ | ------------ | ---- | ---------------------------- |
| value  | T            | No  | Value of the element that is currently traversed.|
| value2 | T            | No  | Key of the element that is currently traversed.|
| set    | Set&lt;T&gt; | No  | Current set object.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                             |
| -------- | ----------------------------------------------------- |
| 401      | Parameter error.                                      |
| 10200011 | The forEach method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                    |

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
  // Throw exception `Concurrent modification error.`
  set.delete(value1);
});
```

## has
has(value: T): boolean

Checks whether a value exists in this ArkTS set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type| Mandatory| Description            |
| ------ | ---- | ---- | ---------------- |
| value  | T    | Yes  | Target key.|

**Return value**

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Check result. The value **true** is returned if the value exists; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                                  |
| 10200011 | The has method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                |

**Example**

```ts
const mySet = new collections.Set<string>(["hello", "world"]);
// Expected output: true
console.info("result:" + mySet.has("hello"));
// Expected output: true
console.info("result:" + mySet.has("world"));
```

## add
add(value: T): Set\<T>

Checks whether a value exists in this ArkTS set, and if not, adds the value to the set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type| Mandatory| Description            |
| ------ | ---- | ---- | ---------------- |
| value  | T    | Yes  | Target value. |

**Return value**

| Type        | Description     |
| ------------ | --------- |
| Set&lt;T&gt; | Set object.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200011 | The add method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                |

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

## [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

Returns an iterator, each item of which is a JavaScript object.

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

let val: Array<number> = Array.from(set.values());
for (let item of val) {
  console.info("value: " + item);
}
```
