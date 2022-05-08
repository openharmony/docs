# Nonlinear Container TreeMap 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import TreeMap from '@ohos.util.TreeMap'  
```

## System Capabilities

SystemCapability.Utils.Lang

## TreeMap


### Attributes

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of entries in a tree map (called container later).|


### constructor

constructor(comparator?:(firstValue: K, secondValue: K) => boolean)

A constructor used to create a **TreeMap** instance.

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

Checks whether this container is empty (contains no entry).

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
let treeMap = new TreeMap();
let result = treeMap.hasKey("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
let result1 = treeMap.hasKey("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
```


### hasValue

hasValue(value: V): boolean

Checks whether this container has the specified value.

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
let treeMap = new TreeMap();
let result = treeMap.hasValue(123);
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
let result1 = treeMap.hasValue(123);
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
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
let result = treeMap.get("sdfs");
```


### getFirstKey

getFirstKey(): K

Obtains the first key in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| K | Key obtained.|

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
let result = treeMap.getFirstKey();
```


### getLastKey

getLastKey(): K

Obtains the last key in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| K | Key obtained.|

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
let result = treeMap.getLastKey();
```


### setAll

setAll(map: TreeMap<K, V>): void

Adds all entries in a **TreeMap** instance to this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| map | TreeMap<K, V> | Yes| **TreeMap** instance whose entries are to be added to the current container.|

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
let map = new TreeMap();
treeMap.setAll(map);
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
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
```


### remove

remove(key: K): V

Removes the entry with the specified key from this container.

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
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
treeMap.remove("sdfs");
```


### getLowerKey

getLowerKey(key: K): K

Obtains the key that is placed in front of the input key in this container.

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
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
treeMap.set("zdfgsd", 356);
let result = treeMap.getLowerKey("sdfs");
```


### getHigherKey

getHigherKey(key: K): K

Obtains the key that is placed next to the input key in this container.

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
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
treeMap.set("zdfgsd", 356);
let result = treeMap.getHigherKey("sdfs");
```

### replace

replace(key: K, newValue: V): boolean

Replaces an entry in this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | K | Yes| Key of the entry to replace.|
| newValue | V | Yes| New value of the entry.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the entry is replaced successfully; returns **false** otherwise.|

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("sdfs", 123);
let result = treeMap.replace("sdfs", 357);
```


### clear

clear(): void

Clears this container and sets its length to **0**.

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
treeMap.clear();
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
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
let iter = treeMap.keys();
let temp = iter.next().value;
while(temp != undefined) {
  console.log(temp);
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
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
let iter = treeMap.values();
let temp = iter.next().value;
while(temp != undefined) {
  console.log(temp);
  temp = iter.next().value;
}
```


### forEach

forEach(callbackfn: (value?: V, key?: K, map?: TreeMap<K, V>) => void, thisArg?: Object): void

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
| map | TreeMap<K, V> | No| Instance that invokes the **forEach** method.|

**Example**

```ts
let treeMap = new TreeMap();
treeMap.set("sdfs", 123);
treeMap.set("dfsghsf", 357);
treeMap.forEach((value, key) => {
  console.log(value, key);
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
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
let iter = treeMap.entries();
let temp = iter.next().value;
while(temp != undefined) {
  console.log(temp[0]);
  console.log(temp[1]);
  temp = iter.next().value;
}
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
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);

// Method 1:
for (let item of treeMap) { 
  console.log("key: " + item[0]);
  console.log("value: " + item[1]);
}

// Method 2:
let iter = treeMap[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log(temp[0]);
  console.log(temp[1]);
  temp = iter.next().value;
}
```
