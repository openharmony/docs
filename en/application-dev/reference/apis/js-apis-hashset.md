# Nonlinear Container HashSet

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**HashSet** is implemented based on [HashMap](js-apis-hashmap.md). In **HashSet**, only the **value** object is processed.

Unlike [TreeSet](js-apis-treeset.md), which stores and accesses data in sorted order, **HashSet** stores data in a random order. This means that **HashSet** may use a different order when storing and accessing elements. Both of them allows only unique elements. However, null values are allowed in **HashSet**, but not allowed in **TreeSet**.

**Recommended use case**: Use **HashSet** when you need a set that has only unique elements or need to deduplicate a set.

This topic uses the following to identify the use of generics:
- T: Type

## Modules to Import

```ts
import HashSet from '@ohos.util.HashSet';
```

## HashSet

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a hash set (called container later).|

**Example**

```ts
let hashSet = new HashSet();
hashSet.add(1);
hashSet.add(2);
hashSet.add(3);
hashSet.add(4);
hashSet.add(5);
let res = hashSet.length;
```

### constructor

constructor()

A constructor used to create a **HashSet** instance.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let hashSet = new HashSet();
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
const hashSet = new HashSet();
let result = hashSet.isEmpty();
```


### has

has(value: T): boolean

Checks whether this container contains the specified element.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified element is contained; returns **false** otherwise.|

**Example**

```ts
let hashSet = new HashSet();
let result = hashSet.has("squirrel");
hashSet.add("squirrel");
let result1 = hashSet.has("squirrel");
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
let hashSet = new HashSet();
let result = hashSet.add("squirrel");
```


### remove

remove(value: T): boolean

Removes an element from this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the element is removed successfully; returns **false** otherwise.|

**Example**

```ts
let hashSet = new HashSet();
hashSet.add("squirrel");
hashSet.add("sparrow");
let result = hashSet.remove("sparrow");
```


### clear

clear(): void

Clears this container and sets its length to **0**.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let hashSet = new HashSet();
hashSet.add("squirrel");
hashSet.add("sparrow");
hashSet.clear();
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
let hashSet = new HashSet();
hashSet.add("squirrel");
hashSet.add("sparrow");
let iter = hashSet.values();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
} 
```


### forEach

forEach(callbackfn: (value?: T, key?: T, set?: HashSet&lt;T&gt;) => void, thisArg?: Object): void

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
| set | HashSet&lt;T&gt; | No| Instance that invokes the **forEach** method.|

**Example**

```ts
let hashSet = new HashSet();
hashSet.add("sparrow");
hashSet.add("squirrel");
hashSet.forEach((value, key) => {
  console.log("value:" + value, key);
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
let hashSet = new HashSet();
hashSet.add("squirrel");
hashSet.add("sparrow");
let iter = hashSet.entries();
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
let hashSet = new HashSet();
hashSet.add("squirrel");
hashSet.add("sparrow");

// Method 1:
for (let item of hashSet) { 
  console.log("value: " + item);
}

// Method 2:
let iter = hashSet[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value: " + temp);
  temp = iter.next().value;
}
```
