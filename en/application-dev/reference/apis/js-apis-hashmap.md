# Nonlinear Container HashMap

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import HashMap from '@ohos.util.HashMap'  
```

## System Capabilities

SystemCapability.Utils.Lang

## HashMap


### Attributes

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of entries in a hash map (called container later).|


### constructor

constructor()

A constructor used to create a **HashMap** instance.

**Example**

```
let hashMap = new HashMap();
```


### isEmpty

isEmpty(): boolean

Checks whether this container is empty (contains no entry).

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the container is empty; returns **false** otherwise.|

**Example**

```
const hashMap = new HashMap();
let result = hashMap.isEmpty();
```


### hasKey

hasKey(key: K): boolean

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

```
let hashMap = new HashMap();
let result = hashMap.hasKey("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
hashMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
let result1 = hashMap.hasKey("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
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

```
let hashMap = new HashMap();
let result = hashMap.hasValue(123);
hashMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
let result1 = hashMap.hasValue(123);
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
| V | Value obtained.|

**Example**

```
let hashMap = new HashMap();
hashMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
hashMap.set("sdfs", 356);
let result = hashMap.get("sdfs");
```


### setAll

setAll(map: HashMap<K, V>): void

Adds all entries in a **HashMap** instance to this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| map | HashMap<K, V> | Yes| **HashMap** instance whose entries are to be added to the current container.|

**Example**

```
let hashMap = new HashMap();
hashMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
hashMap.set("sdfs", 356);
let newHashMap = new HashMap();
hashMap.setAll(newHashMap);
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

```
let hashMap = new HashMap();
let result = hashMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
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

```
let hashMap = new HashMap();
hashMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
hashMap.set("sdfs", 356);
let result = hashMap.remove("sdfs");
```


### clear

clear(): void

Clears this container and sets its length to **0**.

**Example**

```
let hashMap = new HashMap();
hashMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
hashMap.set("sdfs", 356);
hashMap.clear();
```


### keys

keys(): IterableIterator&lt;K&gt;

Obtains an iterator that contains all the entries in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;K&gt; | Iterator obtained.|

**Example**

```
let hashMap = new HashMap();
hashMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
hashMap.set("sdfs", 356);
let iter = hashMap.keys();
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

```
let hashMap = new HashMap();
hashMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
hashMap.set("sdfs", 356);
let iter = hashMap.values();
let temp = iter.next().value;
while(temp != undefined) {
  console.log(temp);
  temp = iter.next().value;
}
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

```
let hashMap = new HashMap();
hashMap.set("sdfs", 123);
let result = hashMap.replace("sdfs", 357);
```


### forEach

forEach(callbackfn: (value?: V, key?: K, map?: HashMap<K, V>) => void, thisArg?: Object): void

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
| map | HashMap<K, V> | No| Instance that invokes the **forEach** method.|

**Example**

```
let hashMap = new HashMap();
hashMap.set("sdfs", 123);
hashMap.set("dfsghsf", 357);
hashMap.forEach((value, key) => {
  console.log(value, key);
});
```


### entries

entries(): IterableIterator&lt;[K, V]&gt;

Obtains an iterator that contains all the entries in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;[K, V]&gt; | Iterator obtained.|

**Example**

```
let hashMap = new HashMap();
hashMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
hashMap.set("sdfs", 356);
let iter = hashMap.entries();
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
| IterableIterator&lt;[K, V]&gt; | Iterator obtained.|

**Example**
```
let hashMap = new HashMap();
hashMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
hashMap.set("sdfs", 356);

// Method 1:
for (let item of hashMap) { 
  console.log("key: " + item[0]);
  console.log("value: " + item[1]);
}

// Method 2:
let iter = hashMap[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log(temp[0]);
  console.log(temp[1]);
  temp = iter.next().value;
}
```
