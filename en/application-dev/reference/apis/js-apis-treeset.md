# Nonlinear Container TreeSet 

> **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import TreeSet from '@ohos.util.TreeSet';  
```

## System Capabilities

SystemCapability.Utils.Lang

## TreeSet


### Attributes

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of entries in a tree set (called container later).|


### constructor

constructor(comparator?:(firstValue: T, secondValue: T) => boolean)

A constructor used to create a **TreeSet** instance.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| comparator | function | No| Custom comparator.|

**Example**

```ts
let treeSet = new TreeSet();
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
const treeSet = new TreeSet();
let result = treeSet.isEmpty();
```


### has

has(value: T): boolean

Checks whether this container has the specified value.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value to query.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified value is contained; returns **false** otherwise.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.has(123);
treeSet.add(123);
let result1 = treeSet.has(123);
```


### getFirstValue

getFirstValue(): T

Obtains the value of the first entry in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value obtained.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
treeSet.add("sdfs");
let result = treeSet.getFirstValue();
```


### getLastValue

getLastValue(): T

Obtains the value of the last entry in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value obtained.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
treeSet.add("sdfs");
let result = treeSet.getLastValue();
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

```ts
let treeSet = new TreeSet();
let result = treeSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
```


### remove

remove(value: T): boolean

Removes the entry with the specified key from this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Key of the entry to remove.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the entry is removed successfully; returns **false** otherwise.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
treeSet.add("sdfs");
let result = treeSet.remove("sdfs");
```


### getLowerValue

getLowerValue(key: T): T

Obtains the value that is placed in front of the input key in this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | T | Yes| Input key.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value obtained.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
treeSet.add("sdfs");
treeSet.add("zdfgsd");
let result = treeSet.getLowerValue("sdfs");
```


### getHigherValue

getHigherValue(key: T): T

Obtains the value that is placed next to the input key in this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | T | Yes| Input key.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value obtained.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
treeSet.add("sdfs");
treeSet.add("zdfgsd");
let result = treeSet.getHigherValue("sdfs");
```


### popFirst

popFirst(): T

Removes the first entry in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| T | Entry removed.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
treeSet.add("sdfs");
let result = treeSet.popFirst();
```


### popLast

popLast(): T

Removes the last entry in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| T | Entry removed.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
treeSet.add("sdfs");
let result = treeSet.popLast();
```


### clear

clear(): void

Clears this container and sets its length to **0**.

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
treeSet.add("sdfs");
treeSet.clear();
```


### values

values(): IterableIterator&lt;T&gt;

Obtains an iterator that contains all the values in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
treeSet.add("sdfs");
let iter = treeSet.values();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
} 
```


### forEach

forEach(callbackfn: (value?: T, key?: T, set?: TreeSet&lt;T&gt;) => void, thisArg?: Object): void

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
| set | TreeSet&lt;T&gt; | No| Instance that invokes the **forEach** method.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("sdfs");
treeSet.add("dfsghsf");
treeSet.forEach((value, key) => {
  console.log("value:" + value, key)
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

```ts
let treeSet = new TreeSet();
treeSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
treeSet.add("sdfs");
let iter = treeSet.entries();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("key:" + temp[0]);
  console.log("value:" + temp[1]);
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

```ts
let treeSet = new TreeSet();
treeSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
treeSet.add("sdfs");
  
// Method 1:
for (let item of treeSet) { 
  console.log("value:" + item);
}

// Method 2:
let iter = treeSet[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
```
