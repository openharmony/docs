# Nonlinear Container TreeMap 

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**TreeMap** stores key-value (KV) pairs. Each key must be unique and have only one value.

**TreeMap** is implemented using a red-black tree, which is a binary search tree where keys are stored in sorted order for efficient insertion and removal.

**[HashMap](js-apis-treemap.md)** is faster in accessing data than **TreeMap**, because the former accesses data based on the hash code of the key, whereas the latter stores and accesses the keys in sorted order.

Recommended use case: Use **TreeMap** when you need to store KV pairs in sorted order.

This topic uses the following to identify the use of generics:
- K: Key
- V: Value

## Modules to Import

```ts
import TreeMap from '@ohos.util.TreeMap';  
```

## TreeMap

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a tree map (called container later).|


### constructor

constructor(comparator?:(firstValue: K, secondValue: K) => boolean)

A constructor used to create a **TreeMap** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| comparator | function | No| Custom comparator.|

**Example**

```ts
let treeMap = new TreeMap();
```


### isEmpty

isEmpty(): boolean

Checks whether this container is empty (contains no element).

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the container is empty; returns **false** otherwise.|

**Example**

```ts
const treeMap = new TreeMap();
let result = treeMap.isEmpty();
```


### hasKey

hasKey(key: K): boolean

Checks whether this container has the specified key.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Target key.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified key is contained; returns **false** otherwise.|

**Example**

```ts
let treeMap = new TreeMap();
let result = treeMap.hasKey("squirrel");
treeMap.set("squirrel", 123);
let result1 = treeMap.hasKey("squirrel");
```


### hasValue

hasValue(value: V): boolean

Checks whether this container has the specified value.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | V | Yes| Target value.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified value is contained; returns **false** otherwise.|

**Example**

```ts
let treeMap = new TreeMap();
let result = treeMap.hasValue(123);
treeMap.set("squirrel", 123);
let result1 = treeMap.hasValue(123);
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
| V | Value of the key.|

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let result = treeMap.get("sparrow");
```


### getFirstKey

getFirstKey(): K

Obtains the first key in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| K | Key obtained.|

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let result = treeMap.getFirstKey();
```


### getLastKey

getLastKey(): K

Obtains the last key in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| K | Key obtained.|

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let result = treeMap.getLastKey();
```


### setAll

setAll(map: TreeMap<K, V>): void

Adds all elements in a **TreeMap** instance to this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| map | TreeMap<K, V> | Yes| **TreeMap** instance whose elements are to be added to the current container.|

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let map = new TreeMap();
treeMap.setAll(map);
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

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("squirrel", 123);
```


### remove

remove(key: K): V

Removes the element with the specified key from this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Target key.|

**Return value**

| Type| Description|
| -------- | -------- |
| V | Value of the element removed.|

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
treeMap.remove("sparrow");
```


### getLowerKey

getLowerKey(key: K): K

Obtains the key that is placed in front of the input key in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Input key.|

**Return value**

| Type| Description|
| -------- | -------- |
| K | Key obtained.|

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
treeMap.set("gander", 356);
let result = treeMap.getLowerKey("sparrow");
```


### getHigherKey

getHigherKey(key: K): K

Obtains the key that is placed next to the input key in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Input key.|

**Return value**

| Type| Description|
| -------- | -------- |
| K | Key obtained.|

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
treeMap.set("gander", 356);
let result = treeMap.getHigherKey("sparrow");
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

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("sparrow", 123);
let result = treeMap.replace("sparrow", 357);
```


### clear

clear(): void

Clears this container and sets its length to **0**.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
treeMap.clear();
```


### keys

keys(): IterableIterator&lt;K&gt;

Obtains an iterator that contains all the keys in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;K&gt; | Iterator obtained.|

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let iter = treeMap.keys();
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

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let iter = treeMap.values();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
```


### forEach

forEach(callbackfn: (value?: V, key?: K, map?: TreeMap<K, V>) => void, thisArg?: Object): void

Uses a callback to traverse the elements in this container and obtain their position indexes.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackfn | function | Yes| Callback invoked to traverse the elements in the container.|
| thisArg | Object | No| Value to use when the callback is invoked.|

callbackfn
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | V | No| Value of the element that is currently traversed.|
| key | K | No| Key of the element that is currently traversed.|
| map | TreeMap<K, V> | No| Instance that invokes the **forEach** method.|

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("sparrow", 123);
treeMap.set("gull", 357);
treeMap.forEach((value, key) => {
  console.log("value:" + value, key);
});
```


### entries

entries(): IterableIterator<[K, V]>

Obtains an iterator that contains all the elements in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator<[K, V]> | Iterator obtained.|

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let iter = treeMap.entries();
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
| IterableIterator<[K, V]> | Iterator obtained.|

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);

// Method 1:
for (let item of treeMap) { 
  console.log("key:" + item[0]);
  console.log("value:" + item[1]);
}

// Method 2:
let iter = treeMap[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("key:" + temp[0]);
  console.log("value:" + temp[1]);
  temp = iter.next().value;
}
```
