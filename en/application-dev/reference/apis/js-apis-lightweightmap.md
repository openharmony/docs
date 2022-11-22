# Nonlinear Container LightWeightMap 

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**LightWeightMap** stores key-value (KV) pairs. Each key must be unique and have only one value.

**LightWeightMap** is based on generics and uses a lightweight structure. Keys in the map are searched using hash values, which are stored in an array.

Compared with **[HashMap](js-apis-hashmap.md)**, which can also store KV pairs, **LightWeightMap** occupies less memory.

**Recommended use case**: Use LightWeightMap when you need to store and access **KV pairs**.

This topic uses the following to identify the use of generics:
- K: Key
- V: Value

## Modules to Import

```ts
import LightWeightMap from '@ohos.util.LightWeightMap';  
```



## LightWeightMap

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a lightweight map (called container later).|


### constructor

constructor()

A constructor used to create a **LightWeightMap** instance.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let lightWeightMap = new LightWeightMap();
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
const lightWeightMap = new LightWeightMap();
let result = lightWeightMap.isEmpty();
```


### hasAll

hasAll(map: LightWeightMap<K, V>): boolean

Checks whether this container contains all elements of the specified **LightWeightMap** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| map | LightWeightMap<K, V> | Yes| **LightWeightMap** instance to be used for comparison.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if all the elements in the specified **LightWeightMap** instance are contained; returns **false** otherwise.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let map = new LightWeightMap();
map.set("sparrow", 356);
let result = lightWeightMap.hasAll(map);
```


### hasKey

hasKey(key: K): boolean;

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

**Example**

```ts
let lightWeightMap = new LightWeightMap();
let result = lightWeightMap.hasKey;
lightWeightMap.hasKey("squirrel");
lightWeightMap.set("squirrel", 123);
let result1 = lightWeightMap.hasKey("squirrel");
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

**Example**

```ts
let lightWeightMap = new LightWeightMap();
let result = lightWeightMap.hasValue(123);
lightWeightMap.set("squirrel", 123);
let result1 = lightWeightMap.hasValue(123);
```


### increaseCapacityTo

increaseCapacityTo(minimumCapacity: number): void

Increases the capacity of this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| minimumCapacity | number | Yes| Minimum number of elements to accommodate in this container.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.increaseCapacityTo(10);
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
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let result = lightWeightMap.get("sparrow");
```


### getIndexOfKey

getIndexOfKey(key: K): number

Obtains the index of the first occurrence of an element with the specified key in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Key of the element.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns the position index if obtained; returns **-1** otherwise.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let result = lightWeightMap.getIndexOfKey("sparrow");
```


### getIndexOfValue

getIndexOfValue(value: V): number

Obtains the index of the first occurrence of an element with the specified value in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | V | Yes| Key of the element.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns the position index if obtained; returns **-1** otherwise.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let result = lightWeightMap.getIndexOfValue(123);
```


### getKeyAt

getKeyAt(index: number): K

Obtains the key of an element at the specified position in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the element.|

**Return value**

| Type| Description|
| -------- | -------- |
| K | Returns the key if obtained; returns **undefined** otherwise.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let result = lightWeightMap.getKeyAt(1);
```


### setAll

setAll(map: LightWeightMap<K, V>): void

Adds all elements in a **LightWeightMap** instance to this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| map | LightWeightMap<K, V> | Yes| **LightWeightMap** instance whose elements are to be added to the current container.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let map = new LightWeightMap();
lightWeightMap.setAll(map);
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
let lightWeightMap = new LightWeightMap();
let result = lightWeightMap.set("squirrel", 123);
```


### remove

remove(key: K): V

Removes an element with the specified key from this container.

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
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
lightWeightMap.remove("sparrow");
```


### removeAt

removeAt(index: number): boolean

Removes an element at the specified position from this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the element is removed successfully; returns **false** otherwise.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let result = lightWeightMap.removeAt(1);
```


### setValueAt

setValueAt(index: number, newValue: V): boolean

Sets a value for an element at the specified position in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the target element.|
| newValue | V | Yes| Value of the target element to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the value is set successfully; returns **false** otherwise.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
lightWeightMap.setValueAt(1, 3546);
```


### getValueAt

getValueAt(index: number): V

Obtains the value of an element at the specified position in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the element.|

**Return value**

| Type| Description|
| -------- | -------- |
| V | Value obtained.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let result = lightWeightMap.getValueAt(1);
```


### clear

clear(): void

Clears this container and sets its length to **0**.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
lightWeightMap.clear();
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
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let iter = lightWeightMap.keys();
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
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let iter = lightWeightMap.values();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
} 
```


### forEach

forEach(callbackfn: (value?: V, key?: K, map?: LightWeightMap<K, V>) => void, thisArg?: Object): void

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
| map | LightWeightMap<K, V> | No| Instance that invokes the **forEach** method.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("sparrow", 123);
lightWeightMap.set("gull", 357);
lightWeightMap.forEach((value, key) => {
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
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);
let iter = lightWeightMap.entries();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("key:" + temp[0]);
  console.log("value:" + temp[1]);
  temp = iter.next().value;
}
```

### toString

toString(): String

Concatenates the elements in this container into a string and returns the string.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| String | String obtained.|

**Example**

  ```ts
  let lightWeightMap = new LightWeightMap();
  lightWeightMap.set("squirrel", 123);
  lightWeightMap.set("sparrow", 356);
  let iter = lightWeightMap.toString();
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
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("squirrel", 123);
lightWeightMap.set("sparrow", 356);

// Method 1:
for (let item of lightWeightMap) { 
  console.log("key:" + item[0]);
  console.log("value:" + item[1]);
}

// Method 2:
let iter = lightWeightMap[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("key:" + temp[0]);
  console.log("value:" + temp[1]);
  temp = iter.next().value;
}
```
