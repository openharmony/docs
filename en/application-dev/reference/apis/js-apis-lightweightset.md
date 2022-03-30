# Nonlinear Container LightWeightSet 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import LightWeightSet from '@ohos.util.LightWeightSet'  
```

## System Capabilities

SystemCapability.Utils.Lang

## LightWeightSet


### Attributes

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of entries in a lightweight set (called container later).|


### constructor

constructor()

A constructor used to create a **LightWeightSet** instance.

**Example**

```
let lightWeightSet = new LightWeightSet();
```


### isEmpty

isEmpty(): boolean

Checks whether this container is empty.

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the container is empty; returns **false** otherwise.|

**Example**

```
const lightWeightSet = new LightWeightSet();
let result = lightWeightSet.isEmpty();
```

### add

add(obj: T): boolean

Adds an entry to this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| obj | T | Yes| Entry to add.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the entry is added successfully; returns **false** otherwise.|

**Example**

```
let lightWeightSet = new LightWeightSet();
let result = lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
```


### addAll

addAll(set: LightWeightSet&lt;T&gt;): boolean

Adds all entries in a **LightWeightSet** instance to this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| set | LightWeightSet&lt;T&gt; | Yes| **LightWeightSet** instance whose entries are to be added to the current container.|

**Example**

```
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
lightWeightSet.add("sdfs");
let set = new LightWeightSet();
set.add("sfage");
let result = lightWeightSet.addAll(set);
```


### hasAll

hasAll(set: LightWeightSet&lt;T&gt;): boolean

Checks whether this container contains all entries of the specified **LightWeightSet** instance.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| set | LightWeightSet&lt;T&gt; | Yes| **LightWeightSet** instance to be used for comparison.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if all the entries in the specified **LightWeightSet** instance are contained; returns **false** otherwise.|

**Example**

```
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
lightWeightSet.add("sdfs");
let set = new LightWeightSet();
set.add("sdfs");
let result = lightWeightSet.hasAll(set);
```


### has

has(key: T): boolean

Checks whether this container has the specified key.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key| T | Yes| Key to query.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified key is contained; returns **false** otherwise.|

**Example**

```
let lightWeightSet = new LightWeightSet();
let result = lightWeightSet.has(123);
lightWeightSet.add(123);
result = lightWeightSet.has(123);
```


### equal

equal(obj: Object): boolean

Checks whether this container contains objects of the same type as the specified **obj**.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| obj | Object | Yes| Object to be used for comparison.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the container contains objects of the same type as the specified **obj**; returns **false** otherwise.|

**Example**

```
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
lightWeightSet.add("sdfs");
let obj = ["Ahfbrgrbgnutfodgorrogorgrogofdfdf", "sdfs"];
let result = lightWeightSet.equal(obj);
```


### increaseCapacityTo

increaseCapacityTo(minimumCapacity: number): void

Increases the capacity of this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| minimumCapacity | number | Yes| Minimum number of entries to accommodate in the container.|

**Example**

```
let lightWeightSet = new LightWeightSet();
lightWeightSet.increaseCapacityTo(10);
```


### getIndexOf

getIndexOf(key: T): number

Obtains the position index of the entry with the specified key in this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key| T | Yes| Key of the entry to query.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Position index of the entry.|

**Example**

```
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
lightWeightSet.add("sdfs");
let result = lightWeightSet.getIndexOf("sdfs");
```


### remove

remove(key: T): T

Removes an entry of the specified key from this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key| T | Yes| Key of the entry to remove.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value of the entry removed.|

**Example**

```
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
lightWeightSet.add("sdfs");
let result = lightWeightSet.remove("sdfs");
```


### removeAt

removeAt(index: number): boolean

Removes the entry at the specified position from this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the entry to remove.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the entry is removed successfully; returns **false** otherwise.|

**Example**

```
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
lightWeightSet.add("sdfs");
let result = lightWeightSet.removeAt(1);
```


### getValueAt

getValueAt(index: number): T

Obtains the value of the entry at the specified position in this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the entry.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value obtained.|

**Parameters**

```
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
lightWeightSet.add("sdfs");
let result = lightWeightSet.getValueAt(1);
```


### clear

clear(): void

Clears this container and sets its length to **0**.

**Example**

```
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
lightWeightSet.add("sdfs");
lightWeightSet.clear();
```


### toString

toString(): String

Obtains a string that contains all entries in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| String | String obtained.|

**Example**

```
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
lightWeightSet.add("sdfs");
let result = lightWeightSet.toString();
```


### toArray

toArray(): Array&lt;T&gt;

Obtains an array that contains all objects in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| Array&lt;T&gt; | Array obtained.|

**Example**

```
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
lightWeightSet.add("sdfs");
let result = lightWeightSet.toArray();
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
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
lightWeightSet.add("sdfs");
let iter = lightWeightSet.values();
let index = 0;
while(index < lightWeightSet.length) {
  console.log(JSON.stringify(iter.next().value));
  index++;
}
```


### forEach

forEach(callbackfn: (value?: T, key?: T, set?: LightWeightSet&lt;T&gt;) => void, thisArg?: Object): void

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
| key| T | No| Key of the entry that is currently traversed (same as **value**).|
| set | LightWeightSet&lt;T&gt; | No| Instance that invokes the **forEach** method.|

**Example**

```
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("sdfs");
lightWeightSet.add("dfsghsf");
lightWeightSet.forEach((value, key) => {
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
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
lightWeightSet.add("sdfs");
let iter = lightWeightSet.entries();
let index = 0;
while(index < lightWeightSet.length) {
  console.log(JSON.stringify(iter.next().value));
  index++;
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
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
lightWeightSet.add("sdfs");

// Method 1:
for (let item of lightWeightSet) { 
  console.log("value: " + item);
}

// Method 2:
let iter = lightWeightSet[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log(temp);
  temp = iter.next().value;
}
```
