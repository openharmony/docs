# Nonlinear Container LightWeightMap 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import LightWeightMap from '@ohos.util.LightWeightMap';  
```

## System Capabilities

SystemCapability.Utils.Lang

## LightWeightMap


### Attributes

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of entries in a lightweight map (called container later).|


### constructor

constructor()

A constructor used to create a **LightWeightMap** instance.

**Example**

```ts
let lightWeightMap = new LightWeightMap();
```


### isEmpty

isEmpty(): boolean

Checks whether this container is empty (contains no entry).

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

Checks whether this container contains all entries of the specified **LightWeightMap** instance.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| map | LightWeightMap<K, V> | Yes| **LightWeightMap** instance to be used for comparison.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if all the entries in the specified **LightWeightMap** instance are contained; returns **false** otherwise.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
lightWeightMap.set("sdfs", 356);
let map = new LightWeightMap();
map.set("sdfs", 356);
let result = lightWeightMap.hasAll(map);
```


### hasKey

hasKey(key: K): boolean;

Checks whether this container contains the specified key.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Key to check.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified key is contained; returns **false** otherwise.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
let result = lightWeightMap.hasKey;
lightWeightMap.hasKey("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
let result1 = lightWeightMap.hasKey("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
```


### hasValue

hasValue(value: V): boolean

Checks whether this container contains the specified value.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | V | Yes| Value to check.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified value is contained; returns **false** otherwise.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
let result = lightWeightMap.hasValue(123);
lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
let result1 = lightWeightMap.hasValue(123);
```


### increaseCapacityTo

increaseCapacityTo(minimumCapacity: number): void

Increases the capacity of this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| minimumCapacity | number | Yes| Minimum number of entries to accommodate in this container.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.increaseCapacityTo(10);
```


### get

get(key: K): V

Obtains the value of the specified key in this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Key to query.|

**Return value**

| Type| Description|
| -------- | -------- |
| V | Value of the key.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
lightWeightMap.set("sdfs", 356);
let result = lightWeightMap.get("sdfs");
```


### getIndexOfKey

getIndexOfKey(key: K): number

Obtains the index of the first occurrence of an entry with the specified key in this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Key of the entry.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns the position index if obtained; returns **-1** if the specified entry is not found.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
lightWeightMap.set("sdfs", 356);
let result = lightWeightMap.getIndexOfKey("sdfs");
```


### getIndexOfValue

getIndexOfValue(value: V): number

Obtains the index of the first occurrence of an entry with the specified value in this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | V | Yes| Value of the entry.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns the position index if obtained; returns **-1** if the specified entry is not found.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
lightWeightMap.set("sdfs", 356);
let result = lightWeightMap.getIndexOfValue(123);
```


### getKeyAt

getKeyAt(index: number): K

Obtains the key of an entry at the specified position in this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the entry.|

**Return value**

| Type| Description|
| -------- | -------- |
| K | Returns the key if obtained; returns **undefined** otherwise.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
lightWeightMap.set("sdfs", 356);
let result = lightWeightMap.getKeyAt(1);
```


### setAll

setAll(map: LightWeightMap<K, V>): void

Adds all entries in a **LightWeightMap** instance to this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| map | LightWeightMap<K, V> | Yes| **LightWeightMap** instance whose entries are to be added to the current container.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
lightWeightMap.set("sdfs", 356);
let map = new LightWeightMap();
lightWeightMap.setAll(map);
```


### set
set(key: K, value: V): Object

Adds an entry to this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Key of the entry to add.|
| value | V | Yes| Value of the entry to add.|

**Return value**

| Type| Description|
| -------- | -------- |
| Object | Container that contains the new entry.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
let result = lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
```


### remove

remove(key: K): V

Removes an entry with the specified key from this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Key of the entry to remove.|

**Return value**

| Type| Description|
| -------- | -------- |
| V | Value of the entry removed.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
lightWeightMap.set("sdfs", 356);
lightWeightMap.remove("sdfs");
```


### removeAt

removeAt(index: number): boolean

Removes an entry at the specified position from this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the entry.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the entry is removed successfully; returns **false** otherwise.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
lightWeightMap.set("sdfs", 356);
let result = lightWeightMap.removeAt(1);
```


### setValueAt

setValueAt(index: number, newValue: V): boolean

Sets a value for an entry at the specified position in this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the entry.|
| newValue | V | Yes| Value of the entry to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the value is set successfully; returns **false** otherwise.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
lightWeightMap.set("sdfs", 356);
lightWeightMap.setValueAt(1, 3546);
```


### getValueAt

getValueAt(index: number): V

Obtains the value of an entry at the specified position in this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the entry.|

**Return value**

| Type| Description|
| -------- | -------- |
| V | Value obtained.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
lightWeightMap.set("sdfs", 356);
let result = lightWeightMap.getValueAt(1);
```


### clear

clear(): void

Clears this container and sets its length to **0**.

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
lightWeightMap.set("sdfs", 356);
lightWeightMap.clear();
```


### keys

keys(): IterableIterator&lt;K&gt;

Obtains an iterator that contains all the keys in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;K&gt; | Iterator obtained.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
lightWeightMap.set("sdfs", 356);
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

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;V&gt; | Iterator obtained.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
lightWeightMap.set("sdfs", 356);
let iter = lightWeightMap.values();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
} 
```


### forEach

forEach(callbackfn: (value?: V, key?: K, map?: LightWeightMap<K, V>) => void, thisArg?: Object): void

Uses a callback to traverse the entries in this container and obtain their position indexes.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackfn | function | Yes| Callback invoked to traverse the entries in the container.|
| thisArg | Object | No| Value to use when the callback is invoked.|

callbackfn
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | V | No| Value of the entry that is currently traversed.|
| key | K | No| Key of the entry that is currently traversed.|
| map | LightWeightMap<K, V> | No| Instance that invokes the **forEach** method.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("sdfs", 123);
lightWeightMap.set("dfsghsf", 357);
lightWeightMap.forEach((value, key) => {
  console.log("value:" + value, key);
});
```


### entries

entries(): IterableIterator<[K, V]>

Obtains an iterator that contains all the entries in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator<[K, V]> | Iterator obtained.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
lightWeightMap.set("sdfs", 356);
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

Concatenates the entries in this container into a string and returns the string.

**Return value**

  | Type| Description|
  | -------- | -------- |
  | String | Returns a string.|

**Example**

  ```ts
  let lightWeightMap = new LightWeightMap();
  lightWeightMap.set("A", 123);
  lightWeightMap.set("sdfs", 356);
  let iter = lightWeightMap.toString();
  ```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[K, V]&gt;

Obtains an iterator, each item of which is a JavaScript object.

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator<[K, V]> | Iterator obtained.|

**Example**

```ts
let lightWeightMap = new LightWeightMap();
lightWeightMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
lightWeightMap.set("sdfs", 356);

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
