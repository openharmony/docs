# @ohos.util.TreeMap (Nonlinear Container TreeMap)

**TreeMap** stores key-value (KV) pairs. Each key must be unique and have only one value.

**TreeMap** is implemented using a red-black tree, which is a binary search tree where keys are stored in sorted order for efficient insertion and removal.

**[HashMap](js-apis-hashmap.md)** is faster in accessing data than **TreeMap**, because the former accesses data based on the hash code of the key, whereas the latter stores and accesses the keys in sorted order.

Recommended use case: Use **TreeMap** when you need to store KV pairs in sorted order.

This topic uses the following to identify the use of generics:

- K: Key

- V: Value

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { TreeMap } from '@kit.ArkTS';
```

## TreeMap

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes | No | Number of elements in a tree map (called container later). |


### constructor

constructor(comparator?:(firstValue: K, secondValue: K) => boolean)

A constructor used to create a **TreeMap** instance. It supports sorting elements in ascending or descending order by using comparators.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| comparator | function | No | Custom comparator, which can be used to sort elements based on the comparison relationship. The default value is **hole** (a blank placeholder), indicating that no comparator is provided. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed. |
| 10200012 | The TreeMap's constructor cannot be directly invoked. |

**Example**

```ts
// Default constructor.
let treeMap : TreeMap<number, number> = new TreeMap();
```

```ts
// Use the comparator firstValue < secondValue if the elements are expected to be sorted in ascending order. Use firstValue > secondValue if the elements are expected to be sorted in descending order.
let treeMap : TreeMap<string,string> = new TreeMap<string,string>((firstValue: string, secondValue: string) : boolean => {return firstValue > secondValue});
treeMap.set("aa","3");
treeMap.set("dd","1");
treeMap.set("cc","2");
treeMap.set("bb","4");
let numbers = Array.from(treeMap.keys())
for (let item of numbers) {
  console.log("treeMap:" + item);
}
```

```ts
// When a custom type is inserted, a comparator must be provided.
 class TestEntry{
   public id: number = 0;
 }
 let ts1: TreeMap<TestEntry, string> = new TreeMap<TestEntry, string>((t1: TestEntry, t2: TestEntry): boolean => {return t1.id < t2.id;});
 let entry1: TestEntry = {
   id: 0
 };
 let entry2: TestEntry = {
   id: 1
 }
 ts1.set(entry1, "0");
 ts1.set(entry2, "1");
 console.log("treeMap: ", ts1.length);

```


### isEmpty

isEmpty(): boolean

Checks whether this container is empty (contains no element).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type | Description |
| -------- | -------- |
| boolean | Returns **true** if the container is empty; returns **false** otherwise. |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 10200011 | The isEmpty method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<number, number> = new TreeMap();
let result = treeMap.isEmpty();
```


### hasKey

hasKey(key: K): boolean

Checks whether this container has the specified key.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| key | K | Yes | Target key. |

**Return value**

| Type | Description |
| -------- | -------- |
| boolean | Returns **true** if the specified key is contained; returns **false** otherwise. |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 10200011 | The hasKey method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
let result = treeMap.hasKey("squirrel");
```


### hasValue

hasValue(value: V): boolean

Checks whether this container has the specified value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| value | V | Yes | Target value. |

**Return value**

| Type | Description |
| -------- | -------- |
| boolean | Returns **true** if the specified value is contained; returns **false** otherwise. |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 10200011 | The hasValue method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
let result = treeMap.hasValue(123);
```


### get

get(key: K): V

Obtains the value of the specified key in this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| key | K | Yes | Target key. |

**Return value**

| Type | Description |
| -------- | -------- |
| V | Value obtained. If nothing is obtained, **undefined** is returned. |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 10200011 | The get method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let result = treeMap.get("sparrow");
```


### getFirstKey

getFirstKey(): K

Obtains the first key in this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type | Description |
| -------- | -------- |
| K | Key obtained. If nothing is obtained, **undefined** is returned. |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 10200011 | The getFirstKey method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let result = treeMap.getFirstKey();
```


### getLastKey

getLastKey(): K

Obtains the last key in this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type | Description |
| -------- | -------- |
| K | Key obtained. If nothing is obtained, **undefined** is returned. |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 10200011 | The getLastKey method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let result = treeMap.getLastKey();
```


### setAll

setAll(map: TreeMap<K, V>): void

Adds all elements in a **TreeMap** instance to this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| map | TreeMap<K, V> | Yes | **TreeMap** object to be added to the container. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The setAll method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let map : TreeMap<string, number> = new TreeMap();
map.set("demo", 12);
map.setAll(treeMap); // Add all elements in the treeMap to the map.
map.forEach((value ?: number, key ?: string) : void => {
  console.log("value" + value, "key" + key); // Print result: 12 demo, 356 sparrow, and 123 squirrel
})
```


### set

set(key: K, value: V): Object

Adds or updates an element in this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| key | K | Yes | Key of the target element. |
| value | V | Yes | Value of the target element. |

**Return value**

| Type | Description |
| -------- | -------- |
| Object | Container that contains the new element. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The set method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
```


### remove

remove(key: K): V

Removes the element with the specified key from this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| key | K | Yes | Target key. |

**Return value**

| Type | Description |
| -------- | -------- |
| V | Value of the element removed. |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 10200011 | The remove method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let result = treeMap.remove("sparrow");
```


### getLowerKey

getLowerKey(key: K): K

Obtains the key that is equal to placed in front of the input key in this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| key | K | Yes | Input key. |

**Return value**

| Type | Description |
| -------- | -------- |
| K | Key obtained. If nothing is obtained, **undefined** is returned. |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 10200011 | The getLowerKey method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
treeMap.set("gander", 356);
let result = treeMap.getLowerKey("sparrow");
```


### getHigherKey

getHigherKey(key: K): K

Obtains the key that is equal to or placed next to the input key in this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| key | K | Yes | Input key. |

**Return value**

| Type | Description |
| -------- | -------- |
| K | Key obtained. If nothing is obtained, **undefined** is returned. |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 10200011 | The getHigherKey method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
treeMap.set("gander", 356);
let result = treeMap.getHigherKey("sparrow");
```

### replace

replace(key: K, newValue: V): boolean

Replaces an element in this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| key | K | Yes | Key of the target element. |
| newValue | V | Yes | New value of the element. |

**Return value**

| Type | Description |
| -------- | -------- |
| boolean | Returns **true** if the element is replaced successfully; returns **false** otherwise. |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 10200011 | The replace method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("sparrow", 123);
let result = treeMap.replace("sparrow", 357);
```


### clear

clear(): void

Clears this container and sets its length to **0**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 10200011 | The clear method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
treeMap.clear();
```


### keys

keys(): IterableIterator&lt;K&gt;

Obtains an iterator that contains all the keys in this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type | Description |
| -------- | -------- |
| IterableIterator&lt;K&gt; | Iterator obtained. |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 10200011 | The keys method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let it = treeMap.keys();
let t: IteratorResult<string> = it.next();
while(!t.done) {
  console.log("TreeMap " + t.value);
  t = it.next()
}
```


### values

values(): IterableIterator&lt;V&gt;

Obtains an iterator that contains all the values in this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type | Description |
| -------- | -------- |
| IterableIterator&lt;V&gt; | Iterator obtained. |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 10200011 | The values method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let it = treeMap.values();
let t: IteratorResult<number> = it.next();
while(!t.done) {
  console.log("TreeMap" + t.value);
  t = it.next()
}
```


### forEach

forEach(callbackFn: (value?: V, key?: K, map?: TreeMap<K, V>) => void, thisArg?: Object): void

Uses a callback to traverse the elements in this container and obtain their position indexes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callbackFn | function | Yes | Callback invoked to traverse the elements in the container. |
| thisArg | Object | No | Value of **this** to use when **callbackFn** is invoked. The default value is this instance. |

callbackFn
| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| value | V | No | Value of the element that is currently traversed. The default value is the value of the first key-value pair. |
| key | K | No | Key of the element that is currently traversed. The default value is the key of the first key-value pair. |
| map | TreeMap<K, V> | No | Instance that calls the **forEach** API. The default value is this instance. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The forEach method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("sparrow", 123);
treeMap.set("gull", 357);
treeMap.forEach((value ?: number, key ?: string) : void => {
  console.log("value:" + value, "key:" + key);
});
```
```ts
 // You are not advised to use the set or remove APIs in forEach because they may cause unpredictable risks such as infinite loops. You can use the for loop when inserting or deleting data.
 let treeMap : TreeMap<string, number> = new TreeMap();
 for(let i = 0; i < 10; i++) {
   treeMap.set("sparrow" + i, 123);
 }
 for(let i = 0;i < 10; i++) {
   treeMap.remove("sparrow" + i);
 }
```

### entries

entries(): IterableIterator<[K, V]>

Obtains an iterator that contains all the elements in this container.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type | Description |
| -------- | -------- |
| IterableIterator<[K, V]> | Iterator obtained. |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 10200011 | The entries method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let it = treeMap.entries();
let t: IteratorResult<Object[]> = it.next();
while(!t.done) {
  console.log("TreeMap" + t.value);
  t = it.next()
}
```
```ts
 // You are not advised to use the set or remove APIs in entries because they may cause unpredictable risks such as infinite loops. You can use the for loop when inserting or deleting data.
 let treeMap : TreeMap<string, number> = new TreeMap();
 for(let i = 0; i < 10; i++) {
   treeMap.set("sparrow" + i, 123);
 }
 for(let i = 0;i < 10; i++) {
   treeMap.remove("sparrow" + i);
 }
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
| Type | Description |
| -------- | -------- |
| IterableIterator<[K, V]> | Iterator obtained. |

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**Example**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);

// Method 1:
let it = treeMap.entries();
let t: IteratorResult<Object[]> = it.next();
while(!t.done) {
  console.log("TreeMap" + t.value);
  t = it.next()
}

// Method 2:
 let iter = treeMap[Symbol.iterator]();
 let temp: IteratorResult<Object[]> = iter.next();
 while(!temp.done) {
   console.log("key:" + temp.value[0]);
   console.log("value:" + temp.value[1]);
   temp = iter.next();
 }
```
```ts
 // You are not advised to use the set or remove APIs in Symbol.iterator because they may cause unpredictable risks such as infinite loops. You can use the for loop when inserting or deleting data.
 let treeMap : TreeMap<string, number> = new TreeMap();
 for(let i = 0; i < 10; i++) {
   treeMap.set("sparrow" + i, 123);
 }
 for(let i = 0;i < 10; i++) {
   treeMap.remove("sparrow" + i);
 }
```
