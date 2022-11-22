# Nonlinear Container TreeSet 

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**TreeSet** is implemented based on **[TreeMap](js-apis-treemap.md)**. In **TreeSet**, only **value** objects are processed. **TreeSet** can be used to store values, each of which must be unique.

**[HashSet](js-apis-hashset.md)** stores data in a random order, whereas **TreeSet** stores data in sorted order. Both of them allows only unique elements. However, null values are allowed in **HashSet**, but not allowed in **TreeSet**.

Recommended use case: Use **TreeSet** when you need to store data in sorted order.

This topic uses the following to identify the use of generics:
- T: Type

## Modules to Import

```ts
import TreeSet from '@ohos.util.TreeSet';  
```

## TreeSet

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a tree set (called container later).|


### constructor

constructor(comparator?: (firstValue: T, secondValue: T) => boolean)

A constructor used to create a **TreeSet** instance.

**System capability**: SystemCapability.Utils.Lang

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

Checks whether this container is empty (contains no element).

**System capability**: SystemCapability.Utils.Lang

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

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Target value.|

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

Obtains the value of the first element in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value obtained.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let result = treeSet.getFirstValue();
```


### getLastValue

getLastValue(): T

Obtains the value of the last element in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value obtained.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let result = treeSet.getLastValue();
```


### add

add(value: T): boolean

Adds an element to this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the element is added successfully; returns **false** otherwise.|

**Example**

```ts
let treeSet = new TreeSet();
let result = treeSet.add("squirrel");
```


### remove

remove(value: T): boolean

Removes the element with the specified key from this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Key of the target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the element is removed successfully; returns **false** otherwise.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let result = treeSet.remove("sparrow");
```


### getLowerValue

getLowerValue(key: T): T

Obtains the value that is placed in front of the input key in this container.

**System capability**: SystemCapability.Utils.Lang

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
treeSet.add("squirrel");
treeSet.add("sparrow");
treeSet.add("gander");
let result = treeSet.getLowerValue("sparrow");
```


### getHigherValue

getHigherValue(key: T): T

Obtains the value that is placed next to the input key in this container.

**System capability**: SystemCapability.Utils.Lang

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
treeSet.add("squirrel");
treeSet.add("sparrow");
treeSet.add("gander");
let result = treeSet.getHigherValue("sparrow");
```


### popFirst

popFirst(): T

Removes the first element in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element removed.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let result = treeSet.popFirst();
```


### popLast

popLast(): T

Removes the last element in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element removed.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let result = treeSet.popLast();
```


### clear

clear(): void

Clears this container and sets its length to **0**.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
treeSet.clear();
```


### values

values(): IterableIterator&lt;T&gt;

Obtains an iterator that contains all the values in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let iter = treeSet.values();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
} 
```


### forEach

forEach(callbackfn: (value?: T, key?: T, set?: TreeSet&lt;T&gt;) => void, thisArg?: Object): void

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
| value | T | No| Value of the element that is currently traversed.|
| key | T | No| Key of the element that is currently traversed (same as **value**).|
| set | TreeSet&lt;T&gt; | No| Instance that invokes the **forEach** method.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("sparrow");
treeSet.add("gull");
treeSet.forEach((value, key) => {
  console.log("value:" + value, key)
});
```


### entries

entries(): IterableIterator<[T, T]>

Obtains an iterator that contains all the elements in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator<[T, T]> | Iterator obtained.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
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

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Example**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
  
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
