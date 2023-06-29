# @ohos.util.HashMap (Nonlinear Container HashMap)

**HashMap** is a map implemented based on the array, linked list, and red-black tree. It provides efficient data query, insertion, and removal. The elements in a **HashMap** instance are mappings of key-value pairs. Each key must be unique and have only one value.

**HashMap** is faster in accessing data than **[TreeMap](js-apis-treemap.md)**, because the former accesses the keys based on the hash codes, whereas the latter stores and accesses the keys in sorted order.

**[HashSet](js-apis-hashset.md)** is implemented based on **HashMap**. The input parameter of **HashMap** consists of **key** and **value**. In **HashSet**, only the **value** object is processed.

**Recommended use case**: Use **HashMap** when you need to quickly access, remove, and insert key-value pairs.

This topic uses the following to identify the use of generics:
- K: Key
- V: Value

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import HashMap from '@ohos.util.HashMap'; 
```

## HashMap

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a hash map (called container later).|


### constructor

constructor()

A constructor used to create a **HashMap** instance.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200012 | The HashMap's constructor cannot be directly invoked. |

**Example**

```ts
let hashMap = new HashMap();
```


### isEmpty

isEmpty(): boolean

Checks whether this container is empty (contains no element).

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the container is empty; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The isEmpty method cannot be bound. |

**Example**

```ts
const hashMap = new HashMap();
let result = hashMap.isEmpty();
```


### hasKey

hasKey(key: K): boolean

Checks whether this container contains the specified key.

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

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The hasKey method cannot be bound. |

**Example**

```ts
let hashMap = new HashMap();
hashMap.set("squirrel", 123);
let result = hashMap.hasKey("squirrel");
```


### hasValue

hasValue(value: V): boolean

Checks whether this container contains the specified value.

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

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The hasValue method cannot be bound. |

**Example**

```ts
let hashMap = new HashMap();
hashMap.set("squirrel", 123);
let result = hashMap.hasValue(123);
```


### get

get(key: K): V

Obtains the value of the specified key in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Target key.|

**Return value**

| Type| Description|
| -------- | -------- |
| V | Value obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The get method cannot be bound. |

**Example**

```ts
let hashMap = new HashMap();
hashMap.set("squirrel", 123);
hashMap.set("sparrow", 356);
let result = hashMap.get("sparrow");
```


### setAll

setAll(map: HashMap<K, V>): void

Adds all elements in a **HashMap** instance to this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| map | HashMap<K, V> | Yes| **HashMap** instance whose elements are to be added to the current container.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The setAll method cannot be bound. |

**Example**

```ts
let hashMap = new HashMap();
hashMap.set("squirrel", 123);
hashMap.set("sparrow", 356);
let newHashMap = new HashMap();
newHashMap.set("newMap", 99);
hashMap.setAll(newHashMap);
```


### set

set(key: K, value: V): Object

Adds an element to this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Key of the target element.|
| value | V | Yes| Value of the target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| Object | Container that contains the new element.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The set method cannot be bound. |

**Example**

```ts
let hashMap = new HashMap();
let result = hashMap.set("squirrel", 123);
```


### remove

remove(key: K): V

Removes an element with the specified key from this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Key of the target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| V | Value of the element.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The remove method cannot be bound. |

**Example**

```ts
let hashMap = new HashMap();
hashMap.set("squirrel", 123);
hashMap.set("sparrow", 356);
let result = hashMap.remove("sparrow");
```


### clear

clear(): void

Clears this container and sets its length to **0**.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The clear method cannot be bound. |

**Example**

```ts
let hashMap = new HashMap();
hashMap.set("squirrel", 123);
hashMap.set("sparrow", 356);
hashMap.clear();
```


### keys

keys(): IterableIterator&lt;K&gt;

Obtains an iterator that contains all the elements in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;K&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The keys method cannot be bound. |

**Example**

```ts
let hashMap = new HashMap();
hashMap.set("squirrel", 123);
hashMap.set("sparrow", 356);
let iter = hashMap.keys();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
```


### values

values(): IterableIterator&lt;V&gt;

Obtains an iterator that contains all the values in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;V&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The values method cannot be bound. |

**Example**

```ts
let hashMap = new HashMap();
hashMap.set("squirrel", 123);
hashMap.set("sparrow", 356);
let iter = hashMap.values();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
```


### replace

replace(key: K, newValue: V): boolean

Replaces an element in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Key of the target element.|
| newValue | V | Yes| New value of the element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the element is replaced successfully; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The replace method cannot be bound. |

**Example**

```ts
let hashMap = new HashMap();
hashMap.set("sparrow", 123);
let result = hashMap.replace("sparrow", 357);
```


### forEach

forEach(callbackFn: (value?: V, key?: K, map?: HashMap<K, V>) => void, thisArg?: Object): void

Uses a callback to traverse the elements in this container and obtain their position indexes.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackFn | function | Yes| Callback invoked to traverse the elements in the container.|
| thisArg | Object | No| Value of **this** to use when **callbackFn** is invoked. The default value is this instance.|

callbackFn
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | V | No| Value of the element that is currently traversed. The default value is the value of the first key-value pair.|
| key | K | No| Key of the element that is currently traversed. The default value is the key of the first key-value pair.|
| map | HashMap<K, V> | No| Instance that calls the **forEach** API. The default value is this instance.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The forEach method cannot be bound. |

**Example**

```ts
let hashMap = new HashMap();
hashMap.set("sparrow", 123);
hashMap.set("gull", 357);
hashMap.forEach((value, key) => {
    console.log("value:" + value, "key:" + key);
});
```


### entries

entries(): IterableIterator&lt;[K, V]&gt;

Obtains an iterator that contains all the elements in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;[K, V]&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The entries method cannot be bound. |

**Example**

```ts
let hashMap = new HashMap();
hashMap.set("squirrel", 123);
hashMap.set("sparrow", 356);
let iter = hashMap.entries();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("key:" + temp[0]);
  console.log("value:" + temp[1]);
  temp = iter.next().value;
}
```


### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[K, V]&gt;

Obtains an iterator, each item of which is a JavaScript object.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;[K, V]&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**Example**
```ts
let hashMap = new HashMap();
hashMap.set("squirrel", 123);
hashMap.set("sparrow", 356);

// Method 1:
for (let item of hashMap) { 
  console.log("key:" + item[0]);
  console.log("value:" + item[1]);
}

// Method 2:
let iter = hashMap[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("key:" + temp[0]);
  console.log("value:" + temp[1]);
  temp = iter.next().value;
}
```
