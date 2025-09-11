# Class (Map)
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

- K: key.
- V: value.

The K and V types must be any of the [sendable data types](../../arkts-utils/arkts-sendable.md#sendable-data-types).

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
| size | number | Yes  | No  | Number of elements in a map.|


## constructor
constructor(entries?: readonly (readonly [K, V])[] | null)

A constructor used to create an ArkTS map.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| entries | readonly (readonly [K, V])[] \| null | No  | Array containing key-value pairs, or iterator object. The default value is **null**, indicating that an empty map is created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error.                                        |
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

## entries
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
| 10200201 | Concurrent modification error. |

**Example**

```ts
// Example 1:
const myMap = new collections.Map<number, string>([
  [0, "foo"],
  [1, "bar"]
]);

const iterator = myMap.entries();
// Expected output: 0, foo
console.info(iterator.next().value);
// Expected output: 1, bar
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

## keys
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
| 10200201 | Concurrent modification error. |

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

## values
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
| 10200201 | Concurrent modification error. |

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

## clear
clear(): void

Removes all elements from this ArkTS map.

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

## delete
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
| boolean | Operation result. The value **true** is returned if the key exists and has been deleted; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                            |
| -------- | ---------------------------------------------------- |
| 401      | Parameter error.                                     |
| 10200011 | The delete method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                   |


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

## forEach
forEach(callbackFn: (value: V, key: K, map: Map<K, V>) => void): void

Calls a callback function for each key-value pair in this ArkTS map.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name    | Type                                      | Mandatory| Description      |
| ---------- | ------------------------------------------ | ---- | ---------- |
| callbackFn | (value: V, key: K, map: Map<K, V>) => void | Yes  | Callback function to run for each key-value pair.|

callbackFn parameters
| Name| Type           | Mandatory| Description                        |
| ------ | --------------- | ---- | ---------------------------- |
| value  | V               | No  | Value of the element that is currently traversed.|
| key    | K               | No  | Key of the element that is currently traversed.|
| map    | Map&lt;K, V&gt; | No  | Current map object.           |

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
  // Throw exception `Concurrent modification error.`
  map.delete(key);
});
```

## get
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
| V \| undefined    | Value obtained. If the key is not found, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                                  |
| 10200011 | The get method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                |

**Example**

```ts
const myMap = new collections.Map<string, string>([
  ["hello", "world"],
]);
// Expected output: "world"
console.info(myMap.get("hello"));
// Expected output: undefined
console.info(myMap.get("hel"));
```

## has
has(key: K): boolean

Checks whether a key exists in this ArkTS map.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description     |
| ------ | ---- | ---- | --------- |
| key    | K    | Yes  | Target key.|

**Return value**

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Check result. The value **true** is returned if the key exists; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                                  |
| 10200011 | The has method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                |

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

## set
set(key: K, value: V): Map<K, V>

Adds or updates a key-value pair to this ArkTS map.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description     |
| ------ | ---- | ---- | --------- |
| key    | K    | Yes  | Target key.|
| value    | V    | Yes  | Target value.|

**Return value**

| Type           | Description   |
| --------------- | ------- |
| Map&lt;K, V&gt; | New map obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 401      | Parameter error.                                  |
| 10200011 | The set method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                |

**Example**

```ts
// Positive example:
const myMap = new collections.Map<string, string>();
myMap.set("foo", "bar");
```

<!--code_no_check-->
```ts
// Negative example:
let obj = new Object();
const myMap: collections.Map<string, Object> = new collections.Map<string, Object>();
// Type arguments of generic "Sendable" type must be a "Sendable" data type (arkts-sendable-generic-types)
myMap.set("foo", obj);
```

## [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[K, V]&gt;

Returns an iterator, each item of which is a JavaScript object.

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
