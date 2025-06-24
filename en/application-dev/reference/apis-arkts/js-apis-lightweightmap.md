# @ohos.util.LightWeightMap (Nonlinear Container LightWeightMap) 

LightWeightMap stores key-value (KV) pairs. Each key must be unique and have only one value.

LightWeightMap is based on generics and uses a lightweight structure. Its default initial capacity is 8, and it has the capacity doubled in each expansion.

The keys in such a set are searched using hash values, which are stored in an array.

Compared with [HashMap](js-apis-hashmap.md), which can also store KV pairs, LightWeightMap occupies less memory.

**Recommended use case**: Use LightWeightMap when you need to store and access KV pairs.

This topic uses the following to identify the use of generics:
- K: Key
- V: Value

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { LightWeightMap } from '@kit.ArkTS';
```

## LightWeightMap

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a LightWeightMap.|


### constructor

constructor()

A constructor used to create a **LightWeightMap** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang


**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200012 | The LightWeightMap's constructor cannot be directly invoked. |

**Example**

```ts
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
```


### isEmpty

isEmpty(): boolean

Checks whether this LightWeightMap is empty (contains no element).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** is returned if the LightWeightMap is empty; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The isEmpty method cannot be bound. |

**Example**

```ts
const lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
let result = lightWeightMap.isEmpty();
```


### hasAll

hasAll(map: LightWeightMap<K, V>): boolean

Checks whether this LightWeightMap contains all elements of the specified **LightWeightMap** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| map | LightWeightMap<K, V> | Yes| **LightWeightMap** instance to be used for comparison.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** is returned if all the elements in the specified LightWeightMap are contained; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The hasAll method cannot be bound. |

**Example**

```ts
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let map: LightWeightMap<string, number> = new LightWeightMap();
map.set("sparrow", 356);
let result = lightWeightMap.hasAll(map);
```


### hasKey

hasKey(key: K): boolean

Checks whether this LightWeightMap has the specified key.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Target key.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** is returned if the specified key is contained; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The hasKey method cannot be bound. |

**Example**

```ts
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
let result = lightWeightMap.hasKey("squirrel");
```


### hasValue

hasValue(value: V): boolean

Checks whether this LightWeightMap has the specified value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | V | Yes| Target value.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Operation result. The value **true** is returned if the specified value is contained; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The hasValue method cannot be bound. |

**Example**

```ts
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
let result = lightWeightMap.hasValue(123);
```

### increaseCapacityTo

increaseCapacityTo(minimumCapacity: number): void

Increases the capacity of this LightWeightMap.

If the passed-in capacity is greater than or equal to the number of elements in this LightWeightMap, the capacity is changed to the new capacity. If the passed-in capacity is less than the number of elements in this LightWeightMap, the capacity is not changed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| minimumCapacity | number | Yes| Minimum number of elements to accommodate in this LightWeightMap.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The increaseCapacityTo method cannot be bound. |

**Example**

```ts
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.increaseCapacityTo(10);
```

### get

get(key: K): V

Obtains the value of the specified key in this LightWeightMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Target key.|

**Return value**

| Type| Description|
| -------- | -------- |
| V | Value of the key.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The get method cannot be bound. |

**Example**

```ts
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let result = lightWeightMap.get("sparrow");
```


### getIndexOfKey

getIndexOfKey(key: K): number

Obtains the index of the first occurrence of an element with the specified key in this LightWeightMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Key of the element.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Index of the element. If no match is found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getIndexOfKey method cannot be bound. |

**Example**

```ts
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let result = lightWeightMap.getIndexOfKey("sparrow");
```


### getIndexOfValue

getIndexOfValue(value: V): number

Obtains the index of the first occurrence of an element with the specified value in this LightWeightMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | V | Yes| Key of the element.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Index of the element. If no match is found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getIndexOfValue method cannot be bound. |

**Example**

```ts
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let result = lightWeightMap.getIndexOfValue(123);
```


### getKeyAt

getKeyAt(index: number): K

Obtains the key of an element at the specified position in this LightWeightMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the element. The value must be less than or equal to int32_max, that is, 2147483647.|

**Return value**

| Type| Description|
| -------- | -------- |
| K | Key obtained. If the key is not found, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of index is out of range. |
| 10200011 | The getKeyAt method cannot be bound. |

**Example**

```ts
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let result = lightWeightMap.getKeyAt(1);
```


### setAll

setAll(map: LightWeightMap<K, V>): void

Adds all elements in a LightWeightMap to this LightWeightMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| map | LightWeightMap<K, V> | Yes| LightWeightMap whose elements are to be added to the current LightWeightMap.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The setAll method cannot be bound. |

**Example**

```ts
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let map: LightWeightMap<string, number> = new LightWeightMap();
map.setAll(lightWeightMap); // Add all elements in lightWeightMap to the map.
```


### set
set(key: K, value: V): Object

Adds or updates an element in this LightWeightMap.

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
| Object | LightWeightMap that contains the new element.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The set method cannot be bound. |

**Example**

```ts
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
let result = lightWeightMap.set("squirrel", 123);
```


### remove

remove(key: K): V

Removes an element with the specified key from this LightWeightMap.

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
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
lightWeightMap.remove("sparrow");
```


### removeAt

removeAt(index: number): boolean

Removes an element at the specified position from this LightWeightMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the element. The value must be less than or equal to int32_max, that is, 2147483647.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Operation result. The value **true** is returned if the element is removed; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The removeAt method cannot be bound. |

**Example**

```ts
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let result = lightWeightMap.removeAt(1);
```


### setValueAt

setValueAt(index: number, newValue: V): boolean

Sets a value for an element at the specified position in this LightWeightMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the element. The value must be less than or equal to int32_max, that is, 2147483647.|
| newValue | V | Yes| Value of the target element to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Operation result. The value **true** is returned if the value is set successfully; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of index is out of range. |
| 10200011 | The setValueAt method cannot be bound. |

**Example**

```ts
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
lightWeightMap.setValueAt(1, 3546);
```


### getValueAt

getValueAt(index: number): V

Obtains the value of an element at the specified position in this LightWeightMap.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the element. The value must be less than or equal to int32_max, that is, 2147483647.|

**Return value**

| Type| Description|
| -------- | -------- |
| V | Value obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of index is out of range. |
| 10200011 | The getValueAt method cannot be bound. |

**Example**

```ts
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let result = lightWeightMap.getValueAt(1);
```


### clear

clear(): void

Clears this LightWeightMap and sets its length to **0**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The clear method cannot be bound. |

**Example**

```ts
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
lightWeightMap.clear();
```


### keys

keys(): IterableIterator&lt;K&gt;

Returns an iterator that contains all the keys in this LightWeightMap.

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
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let iter = lightWeightMap.keys();
let temp: IteratorResult<string, number> = iter.next();
while(!temp.done) {
  console.log("value:" + temp.value);
  temp = iter.next();
}
```


### values

values(): IterableIterator&lt;V&gt;

Returns an iterator that contains all the values in this LightWeightMap.

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
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let iter = lightWeightMap.values();
let temp: IteratorResult<number> = iter.next();
while(!temp.done) {
  console.log("value:" + temp.value);
  temp = iter.next();
}
```


### forEach

forEach(callbackFn: (value?: V, key?: K, map?: LightWeightMap<K, V>) => void, thisArg?: Object): void

Uses a callback to traverse the elements in this LightWeightMap and obtain their indexes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackFn | function | Yes| Callback invoked to traverse the elements in the LightWeightMap.|
| thisArg | Object | No| Value of **this** to use when **callbackFn** is invoked. The default value is this instance.|

callbackFn parameters
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | V | No| Value of the element that is currently traversed. The default value is the value of the first key-value pair.|
| key | K | No| Key of the element that is currently traversed. The default value is the key of the first key-value pair.|
| map | LightWeightMap<K, V> | No| Instance that calls the **forEach** API. The default value is this instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The forEach method cannot be bound. |

**Example**

```ts
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("sparrow", 123);
lightWeightMap.set("gull", 357);
lightWeightMap.forEach((value?: number, key?: string) => {
  console.log("value:" + value, "key:" + key);
});
```
```ts
// You are not advised to use the set, setValueAt, remove, or removeAt APIs in forEach because they may cause unpredictable risks such as infinite loops. You can use the for loop when inserting or deleting data.
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
for(let i = 0; i < 10; i++) {
  lightWeightMap.set("sparrow" + i, 123);
}
for(let i = 0; i < 10; i++) {
  lightWeightMap.remove("sparrow" + i);
}
```

### entries

entries(): IterableIterator<[K, V]>

Returns an iterator that contains all the elements in this LightWeightMap.

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
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let iter = lightWeightMap.entries();
let temp: IteratorResult<Object[]> = iter.next();
while(!temp.done) {
  console.log("key:" + temp.value[0]);
  console.log("value:" + temp.value[1]);
  temp = iter.next();
}
```
```ts
// You are not advised to use the set, setValueAt, remove, or removeAt APIs in entries because they may cause unpredictable risks such as infinite loops. You can use the for loop when inserting or deleting data.
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
for(let i = 0; i < 10; i++) {
  lightWeightMap.set("sparrow" + i, 123);
}
for(let i = 0; i < 10; i++) {
  lightWeightMap.remove("sparrow" + i);
}
```

### toString

toString(): String

Concatenates the elements in this LightWeightMap into a string and returns the string.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| String | String obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The toString method cannot be bound. |

**Example**

```ts
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let result = lightWeightMap.toString();
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[K, V]&gt;

Returns an iterator. Each item of the iterator is a JavaScript object.

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
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);

// Method 1:
let nums = Array.from(lightWeightMap.values());
for (let item1 of nums) {
  console.log("value:" + item1);
}

let key = Array.from(lightWeightMap.keys());
for (let item2 of key) {
  console.log("key:" + item2);
}

// Method 2:
let iter = lightWeightMap[Symbol.iterator]();
let temp: IteratorResult<Object[]> = iter.next();
while(!temp.done) {
  console.log("key:" + temp.value[0]);
  console.log("value:" + temp.value[1]);
  temp = iter.next();
}
```
```ts
// You are not advised to use the set, setValueAt, remove, or removeAt APIs in Symbol.iterator because they may cause unpredictable risks such as infinite loops. You can use the for loop when inserting or deleting data.
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
for(let i = 0; i < 10; i++) {
  lightWeightMap.set("sparrow" + i, 123);
}
for(let i = 0; i < 10; i++) {
  lightWeightMap.remove("sparrow" + i);
}
```
