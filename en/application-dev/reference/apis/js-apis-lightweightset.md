# Nonlinear Container LightWeightSet 

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**LightWeightSet** stores a set of values, each of which must be unique.

**LightWeightSet** is based on generics and uses a lightweight structure. Its default initial capacity is 8, and it has the capacity doubled in each expansion.

The values in such a set are searched using hash values, which are stored in an array.

Compared with **[HashSet](js-apis-hashset.md)**, which can also store values, **LightWeightSet** occupies less memory.

**Recommended use case**: Use **LightWeightSet** when you need a set that has only unique elements or need to deduplicate a set.

This topic uses the following to identify the use of generics:
- T: Type

## Modules to Import

```ts
import LightWeightSet from '@ohos.util.LightWeightSet';  
```



## LightWeightSet

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a lightweight set (called container later).|


### constructor

constructor()

A constructor used to create a **LightWeightSet** instance.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let lightWeightSet = new LightWeightSet();
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
const lightWeightSet = new LightWeightSet();
let result = lightWeightSet.isEmpty();
```

### add

add(obj: T): boolean

Adds an element to this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| obj | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the element is added successfully; returns **false** otherwise.|

**Example**

```ts
let lightWeightSet = new LightWeightSet();
let result = lightWeightSet.add("squirrel");
```


### addAll

addAll(set: LightWeightSet&lt;T&gt;): boolean

Adds all elements in a **LightWeightSet** instance to this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| set | LightWeightSet&lt;T&gt; | Yes| **LightWeightSet** instance whose elements are to be added to the current container.|

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let set = new LightWeightSet();
set.add("gull");
let result = lightWeightSet.addAll(set);
```


### hasAll

hasAll(set: LightWeightSet&lt;T&gt;): boolean

Checks whether this container contains all elements of the specified **LightWeightSet** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| set | LightWeightSet&lt;T&gt; | Yes| **LightWeightSet** instance to be used for comparison.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if all the elements in the specified **LightWeightSet** instance are contained; returns **false** otherwise.|

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let set = new LightWeightSet();
set.add("sparrow");
let result = lightWeightSet.hasAll(set);
```


### has

has(key: T): boolean

Checks whether this container has the specified key.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key| T | Yes| Target key.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified key is contained; returns **false** otherwise.|

**Example**

```ts
let lightWeightSet = new LightWeightSet();
let result = lightWeightSet.has(123);
lightWeightSet.add(123);
result = lightWeightSet.has(123);
```


### equal

equal(obj: Object): boolean

Checks whether this container contains objects of the same type as the specified **obj**.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| obj | Object | Yes| Object to be used for comparison.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the container contains objects of the same type as the specified **obj**; returns **false** otherwise.|

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let obj = ["squirrel", "sparrow"];
let result = lightWeightSet.equal(obj);
```


### increaseCapacityTo

increaseCapacityTo(minimumCapacity: number): void

Increases the capacity of this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| minimumCapacity | number | Yes| Minimum number of elements to accommodate in the container.|

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.increaseCapacityTo(10);
```


### getIndexOf

getIndexOf(key: T): number

Obtains the position index of the element with the specified key in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key| T | Yes| Key of the target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Position index of the element.|

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.getIndexOf("sparrow");
```


### remove

remove(key: T): T

Removes an element of the specified key from this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key| T | Yes| Key of the target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value of the element removed.|

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.remove("sparrow");
```


### removeAt

removeAt(index: number): boolean

Removes the element at the specified position from this container.

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
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.removeAt(1);
```


### getValueAt

getValueAt(index: number): T

Obtains the value of the element at the specified position in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the element.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Value obtained.|

**Parameters**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.getValueAt(1);
```


### clear

clear(): void

Clears this container and sets its length to **0**.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
lightWeightSet.clear();
```


### toString

toString(): String

Obtains a string that contains all elements in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| String | String obtained.|

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.toString();
```


### toArray

toArray(): Array&lt;T&gt;

Obtains an array that contains all objects in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| Array&lt;T&gt; | Array obtained.|

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.toArray();
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
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let iter = lightWeightSet.values();
let index = 0;
while(index < lightWeightSet.length) {
  console.log(JSON.stringify(iter.next().value));
  index++;
}
```


### forEach

forEach(callbackfn: (value?: T, key?: T, set?: LightWeightSet&lt;T&gt;) => void, thisArg?: Object): void

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
| key| T | No| Key of the element that is currently traversed (same as **value**).|
| set | LightWeightSet&lt;T&gt; | No| Instance that invokes the **forEach** method.|

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("sparrow");
lightWeightSet.add("gull");
lightWeightSet.forEach((value, key) => {
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
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
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

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Example**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");

// Method 1:
for (let item of lightWeightSet) { 
  console.log("value:" + item);
}

// Method 2:
let iter = lightWeightSet[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
```
