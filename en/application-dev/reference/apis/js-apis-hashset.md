# Nonlinear Container HashSet

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import HashSet from '@ohos.util.HashSet';
```

## System Capabilities

SystemCapability.Utils.Lang

## HashSet


### Attributes

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of entries in a hash set (called container later).|


### constructor

constructor()

A constructor used to create a **HashSet** instance.

**Example**

```
let hashSet = new HashSet();
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
const hashSet = new HashSet();
hashSet.isEmpty();
```


### has

has(value: T): boolean

Checks whether this container contains the specified entry.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Entry to check.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified entry is contained; returns **false** otherwise.|

**Example**

```
let hashSet = new HashSet();
let result = hashSet.has("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
hashSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
let result1 = hashSet.has("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
```


### add

add(value: T): boolean

Adds an entry to this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Entry to add.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the entry is added successfully; returns **false** otherwise.|

**Example**

```
let hashSet = new HashSet();
let result = hashSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
```


### remove

remove(value: T): boolean

Removes an entry from this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Entry to remove.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the entry is removed successfully; returns **false** otherwise.|

**Example**

```
let hashSet = new HashSet();
hashSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
hashSet.add("sdfs");
let result = hashSet.remove("sdfs");
```


### clear

clear(): void

Clears this container and sets its length to **0**.

**Example**

```
let hashSet = new HashSet();
hashSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
hashSet.add("sdfs");
hashSet.clear();
```


### values

values(): IterableIterator&lt;T&gt;

Obtains an iterator that contains all the values in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Example**

```
let hashSet = new HashSet();
hashSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
hashSet.add("sdfs");
let iter = hashSet.values();
let temp = iter.next().value;
while(temp != undefined) {
  console.log(temp);
  temp = iter.next().value;
} 
```


### forEach

forEach(callbackfn: (value?: T, key?: T, set?: HashSet&lt;T&gt;) => void, thisArg?: Object): void

Uses a callback to traverse the entries in this container and obtain their position indexes.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackfn | function | Yes| Callback invoked to traverse the entries in the container.|
| thisArg | Object | No| Value to use when the callback is invoked.|

callbackfn
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | No| Value of the entry that is currently traversed.|
| key | T | No| Key of the entry that is currently traversed (same as **value**).|
| set | HashSet&lt;T&gt; | No| Instance that invokes the **forEach** method.|

**Example**

```
let hashSet = new HashSet();
hashSet.add("sdfs");
hashSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
hashSet.forEach((value, key) => {
  console.log(value, key);
});
```


### entries
entries(): IterableIterator<[T, T]>

Obtains an iterator that contains all the entries in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator<[T, T]> | Iterator obtained.|

**Example**

```
let hashSet = new HashSet();
hashSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
hashSet.add("sdfs");
let iter = hashSet.entries();
let temp = iter.next().value;
while(temp != undefined) {
  console.log(temp[0]);
  console.log(temp[1]);
  temp = iter.next().value;
}
```


### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

Obtains an iterator, each item of which is a JavaScript object.

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Example**

```
let hashSet = new HashSet();
hashSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
hashSet.add("sdfs");

// Method 1:
for (let item of hashSet) { 
  console.log("value: " + item);
}

// Method 2:
let iter = hashSet[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log(temp);
  temp = iter.next().value;
}
```
