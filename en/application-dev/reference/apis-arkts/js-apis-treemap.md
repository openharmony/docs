# @ohos.util.TreeMap (Nonlinear Container TreeMap)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @yuanyao14-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

TreeMap stores key-value (KV) pairs. Each key must be unique and have only one value.

TreeMap is implemented using a red-black tree, which is a binary search tree where keys are stored in sorted order for efficient insertion and removal.

[HashMap](js-apis-hashmap.md) is faster in accessing data than TreeMap, because the former accesses data based on the hash code of the key, whereas the latter stores and accesses the keys in sorted order.

Recommended use case: Use TreeMap when you need to store KV pairs in sorted order.

This topic uses the following to identify the use of generics:

- K: Key

- V: Value

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> Container classes, implemented in static languages, have restrictions on storage locations and properties, and do not support custom properties or methods.


## Modules to Import

```ts
import { TreeMap } from '@kit.ArkTS';
```

## TreeMap

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a TreeMap.|


### constructor

constructor(comparator?:(firstValue: K, secondValue: K) => boolean)

A constructor used to create a **TreeMap** instance. It supports sorting elements in customized order by using comparators.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| comparator | function | No| Custom comparator, which can be used to sort elements based on the comparison relationship. The default value is null, indicating that no comparator is provided.|

comparator parameters

| Name| Type| Mandatory| Description|
| ------| ---- | ----- | -- |
| firstValue | K | Yes| Previous element.|
| secondValue | K | Yes| Next element.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed. |
| 10200012 | The TreeMap's constructor cannot be directly invoked. |

**Example**

```ts
// Default constructor.
let treeMap = new TreeMap<number, number>();
```

```ts
// Use the comparator firstValue < secondValue if the elements are expected to be sorted in ascending order. Use firstValue > secondValue if the elements are expected to be sorted in descending order.
let treeMap: TreeMap<string,string> = new TreeMap<string,string>((firstValue: string, secondValue: string): boolean => {
  return firstValue > secondValue;
});
treeMap.set("aa","3");
treeMap.set("dd","1");
treeMap.set("cc","2");
treeMap.set("bb","4");
for (let item of treeMap) {
  console.info("key: " + item[0], "value: " + item[1]);
}
// Output:
// key: dd value: 1
// key: cc value: 2
// key: bb value: 4
// key: aa value: 3
```

```ts
// When a custom type is inserted, a comparator must be provided.
class TestEntry{
  public id: number = 0;
}

let ts1: TreeMap<TestEntry, string> = new TreeMap<TestEntry, string>((t1: TestEntry, t2: TestEntry): boolean => {
  return t1.id < t2.id;
});
let entry1: TestEntry = {
  id: 0
};
let entry2: TestEntry = {
  id: 1
}
ts1.set(entry1, "0");
ts1.set(entry2, "1");
console.info("length:", ts1.length); // length: 2
```


### isEmpty

isEmpty(): boolean

Checks whether this TreeMap is empty (contains no element).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the TreeMap is empty; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The isEmpty method cannot be bound. |

**Example**

```ts
let treeMap = new TreeMap<number, number>();
let result = treeMap.isEmpty();
console.info("result:", result);  // result: true
```


### hasKey

hasKey(key: K): boolean

Checks whether this TreeMap has the specified key.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Target key.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified key is contained; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The hasKey method cannot be bound. |

**Example**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set("squirrel", 123);
let result = treeMap.hasKey("squirrel");
console.info("result:", result);  // result: true
```


### hasValue

hasValue(value: V): boolean

Checks whether this TreeMap has the specified key.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | V | Yes| Target value.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified value is contained; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The hasValue method cannot be bound. |

**Example**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set("squirrel", 123);
let result = treeMap.hasValue(123);
console.info("result:", result);  // result: true
```


### get

get(key: K): V

Obtains the value of the specified key in this TreeMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Target key.|

**Return value**

| Type| Description|
| -------- | -------- |
| V | Value obtained. If nothing is obtained, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The get method cannot be bound. |

**Example**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let result = treeMap.get("sparrow");
console.info("result:", result); // result: 356
```


### getFirstKey

getFirstKey(): K

Obtains the first key in this TreeMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| K | Key obtained. If nothing is obtained, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getFirstKey method cannot be bound. |

**Example**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let result = treeMap.getFirstKey();
console.info("result:", result); // result: sparrow
```


### getLastKey

getLastKey(): K

Obtains the last key in this TreeMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| K | Key obtained. If nothing is obtained, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getLastKey method cannot be bound. |

**Example**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let result = treeMap.getLastKey();
console.info("result:", result); // result: squirrel
```


### setAll

setAll(map: TreeMap<K, V>): void

Adds all elements in a **TreeMap** instance to this TreeMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| map | TreeMap<K, V> | Yes| **TreeMap** object to be added to the TreeMap.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The setAll method cannot be bound. |

**Example**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let map : TreeMap<string, number> = new TreeMap();
map.set("demo", 12);
map.setAll(treeMap); // Add all elements in the treeMap to the map.
map.forEach((value ?: number, key ?: string) : void => {
  console.info("value: " + value, "key: " + key); 
})
// Output:
// value: 12 key: demo
// value: 356 key: sparrow
// value: 123 key: squirrel
```


### set

set(key: K, value: V): Object

Adds or updates an element in this TreeMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Key of the target element.|
| value | V | Yes| Value of the target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| Object | TreeMap that contains the new element.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The set method cannot be bound. |

**Example**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set("squirrel", 123);
console.info("squirrel:", treeMap.get("squirrel")); // squirrel: 123
```


### remove

remove(key: K): V

Removes the element with the specified key from this TreeMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Target key.|

**Return value**

| Type| Description|
| -------- | -------- |
| V | Value of the element removed.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The remove method cannot be bound. |

**Example**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let result = treeMap.remove("sparrow"); // Delete data.
console.info("result = " + result); // result = 356
```


### getLowerKey

getLowerKey(key: K): K

Obtains the largest key in this TreeMap that is less than the specified comparison key.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Input key.|

**Return value**

| Type| Description|
| -------- | -------- |
| K | Key obtained. If nothing is obtained, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getLowerKey method cannot be bound. |

**Example**

```ts
let treeMap = new TreeMap<number, string>();
treeMap.set(1, 'one');
treeMap.set(2, 'two');
treeMap.set(3, 'three');
treeMap.set(4, 'four');
let result = treeMap.getLowerKey(3);
console.info("result:", result); // result: 2
```


### getHigherKey

getHigherKey(key: K): K

Obtains the smallest key in this TreeMap that is greater than the specified comparison key.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Input key.|

**Return value**

| Type| Description|
| -------- | -------- |
| K | Key obtained. If nothing is obtained, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getHigherKey method cannot be bound. |

**Example**

```ts
let treeMap = new TreeMap<number, string>();
treeMap.set(1, 'one');
treeMap.set(2, 'two');
treeMap.set(3, 'three');
treeMap.set(4, 'four');
let result = treeMap.getHigherKey(3);
console.info("result:", result); // result: 4
```

### replace

replace(key: K, newValue: V): boolean

Replaces an element in this TreeMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Target key.|
| newValue | V | Yes| New value of the element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the element is replaced successfully; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The replace method cannot be bound. |

**Example**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set("sparrow", 123);
let result = treeMap.replace("sparrow", 357);
console.info("sparrow:", treeMap.get("sparrow")); // sparrow: 357
```


### clear

clear(): void

Clears this TreeMap and sets its length to **0**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The clear method cannot be bound. |

**Example**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
treeMap.clear();
let result = treeMap.isEmpty();
console.info("result:", result); // result: true
```


### keys

keys(): IterableIterator&lt;K&gt;

Returns an iterator that contains all the keys in this TreeMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;K&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The keys method cannot be bound. |

**Example**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let keys = treeMap.keys();
for (let key of keys) {
  console.info("key:", key);
}
// Output:
// key: sparrow
// key: squirrel
```


### values

values(): IterableIterator&lt;V&gt;

Returns an iterator that contains all the values in this TreeMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;V&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The values method cannot be bound. |

**Example**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let values = treeMap.values();
for (let value of values) {
  console.info("value:", value);
}
// value: 356
// value: 123
```


### forEach

forEach(callbackFn: (value?: V, key?: K, map?: TreeMap<K, V>) => void, thisArg?: Object): void

Uses a callback to traverse the elements in this TreeMap and obtain their indexes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackFn | function | Yes| Callback invoked to traverse the elements in the TreeMap.|
| thisArg | Object | No| Value of **this** to use when **callbackFn** is invoked. The default value is this instance.|

callbackFn
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | V | No| Value of the element that is currently traversed. The default value is the value of the first key-value pair.|
| key | K | No| Key of the element that is currently traversed. The default value is the key of the first key-value pair.|
| map | TreeMap<K, V> | No| Instance that calls the **forEach** API. The default value is this instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The forEach method cannot be bound. |

**Example**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set("sparrow", 123);
treeMap.set("gull", 357);
treeMap.forEach((value: number, key: string): void => {
  console.info("value: " + value, "key: " + key);
});
// Output:
// value: 357 key: gull
// value: 123 key: sparrow
```

```ts
 // You are not advised to use the set or remove APIs in forEach because they may cause unpredictable risks such as infinite loops. You can use the for loop when inserting or deleting data.
 let treeMap = new TreeMap<string, number>();
 for(let i = 0; i < 10; i++) {
   treeMap.set("sparrow" + i, 123);
 }
 for(let i = 0;i < 10; i++) {
   treeMap.remove("sparrow" + i);
 }
```

### entries

entries(): IterableIterator<[K, V]>

Returns an iterator that contains all the elements in this TreeMap.

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
| 10200011 | The entries method cannot be bound. |

**Example**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let it = treeMap.entries();
let t: IteratorResult<Object[]> = it.next();
while(!t.done) {
  console.info("TreeMap:", t.value);
  t = it.next()
}
// Output:
// TreeMap: sparrow,356
// TreeMap: squirrel,123
```

```ts
 // You are not advised to use the set or remove APIs in entries because they may cause unpredictable risks such as infinite loops. You can use the for loop when inserting or deleting data.
 let treeMap = new TreeMap<string, number>();
 for(let i = 0; i < 10; i++) {
   treeMap.set("sparrow" + i, 123);
 }
 for(let i = 0;i < 10; i++) {
   treeMap.remove("sparrow" + i);
 }
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[K, V]&gt;

Returns an iterator, each item of which is a JavaScript object.

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
let treeMap = new TreeMap<string, number>();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);

// Method 1:
for (let item of treeMap) {
  console.info("TreeMap:", item[0], item[1]);
}
// Output:
// TreeMap: sparrow,356
// TreeMap: squirrel,123

// Method 2:
let iter = treeMap[Symbol.iterator]();
let temp: IteratorResult<Object[]> = iter.next();
while(!temp.done) {
  console.info("key:", temp.value[0]);
  console.info("value:", temp.value[1]);
  temp = iter.next();
}
// Output:
// key: sparrow
// value: 356
// key: squirrel
// value: 123
```

```ts
 // You are not advised to use the set or remove APIs in Symbol.iterator because they may cause unpredictable risks such as infinite loops. You can use the for loop when inserting or deleting data.
 let treeMap = new TreeMap<string, number>();
 for(let i = 0; i < 10; i++) {
   treeMap.set("sparrow" + i, 123);
 }
 for(let i = 0;i < 10; i++) {
   treeMap.remove("sparrow" + i);
 }
```
