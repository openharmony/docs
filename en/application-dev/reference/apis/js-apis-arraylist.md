# Linear Container ArrayList

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**ArrayList** is a linear data structure that is implemented based on arrays. **ArrayList** can dynamically adjust the capacity based on project requirements. It increases the capacity by 50% each time.

Similar to **ArrayList**, **[Vector](js-apis-vector.md)** is also implemented based on arrays and can dynamically adjust the capacity. It increases the capability by 100% each time.

When compared with **[LinkedList](js-apis-linkedlist.md)**, **ArrayList** is more efficient in random access but less efficient in the addition or removal operation, because its addition or removal operation affects the position of other elements in the container.

**Recommended use case**: Use **ArrayList** when elements in a container need to be frequently read.

This topic uses the following to identify the use of generics:
- T: Type

## Modules to Import

```ts
import ArrayList from '@ohos.util.ArrayList';
```

## ArrayList

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in an array list (called container later).|


### constructor

constructor()

A constructor used to create an **ArrayList** instance.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let arrayList = new ArrayList();
```


### add

add(element: T): boolean

Adds an element at the end of this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the element is added successfully; returns **false** otherwise.|

**Example**

  ```ts
  let arrayList = new ArrayList();
  let result = arrayList.add("a");
  let result1 = arrayList.add(1);
  let b = [1, 2, 3];
  let result2 = arrayList.add(b);
  let c = {name: "Dylon", age: "13"};
  let result3 = arrayList.add(false);
  ```

### insert

insert(element: T, index: number): void

Inserts an element at the specified position in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|
| index | number | Yes| Index of the position where the element is to be inserted.|

**Example**

```ts
let arrayList = new ArrayList();
arrayList.insert("A", 0);
arrayList.insert(0, 1);
arrayList.insert(true, 2);
```

### has

has(element: T): boolean

Checks whether this container has the specified element.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified element is contained; returns **false** otherwise.|

**Example**

```ts
let arrayList = new ArrayList();
let result = arrayList.has("squirrel");
arrayList.add("squirrel");
let result1 = arrayList.has("squirrel");
```

### getIndexOf

getIndexOf(element: T): number

Obtains the index of the first occurrence of the specified element in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns the position index if obtained; returns **-1** if the specified element is not found.|

**Example**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(2);
arrayList.add(1);
arrayList.add(2);
arrayList.add(4);
let result = arrayList.getIndexOf(2);
```

### getLastIndexOf

getLastIndexOf(element: T): number

Obtains the index of the last occurrence of the specified element in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns the position index if obtained; returns **-1** if the specified element is not found.|

**Example**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(2);
arrayList.add(1);
arrayList.add(2);
arrayList.add(4);
let result = arrayList.getLastIndexOf(2);
```

### removeByIndex

removeByIndex(index: number): T

Removes an element with the specified position from this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element removed.|

**Example**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(2);
arrayList.add(4);
let result = arrayList.removeByIndex(2);
```

### remove

remove(element: T): boolean

Removes the first occurrence of the specified element from this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the element is removed successfully; returns **false** otherwise.|

**Example**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
let result = arrayList.remove(2);
```

### removeByRange

removeByRange(fromIndex: number, toIndex: number): void

Removes from this container all of the elements within a range, including the element at the start position but not that at the end position.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fromIndex | number | Yes| Index of the start position.|
| toIndex | number | Yes| Index of the end position.|

**Example**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
arrayList.removeByRange(2, 4);
arrayList.removeByRange(4, 3);
arrayList.removeByRange(2, 6);
```

### replaceAllElements

replaceAllElements(callbackfn: (value: T, index?: number, arrlist?: ArrayList&lt;T&gt;) => T,
thisArg?: Object): void

Replaces all elements in this container with new elements, and returns the new ones.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackfn | function | Yes| Callback invoked for the replacement.|
| thisArg | Object | No| Value to use when the callback is invoked.|

callbackfn

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value of the element that is currently traversed.|
| index | number | No| Position index of the element that is currently traversed.|
| arrlist | ArrayList&lt;T&gt; | No| Instance that invokes the **replaceAllElements** method.|

**Example**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
arrayList.replaceAllElements((value: number, index: number)=> {
  return value = 2 * value;
});
arrayList.replaceAllElements((value: number, index: number) => {
  return value = value - 2;
});
```

### forEach

forEach(callbackfn: (value: T, index?: number, arrlist?: ArrayList&lt;T&gt;) => void,
thisArg?: Object): void

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
| value | T | Yes| Value of the element that is currently traversed.|
| index | number | No| Position index of the element that is currently traversed.|
| arrlist | ArrayList&lt;T&gt; | No| Instance that invokes the **forEach** method.|

**Example**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
arrayList.forEach((value, index) => {
  console.log(`value:${value}`, index);
});
```

### sort

sort(comparator?: (firstValue: T, secondValue: T) => number): void

Sorts elements in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| comparator | function | No| Callback invoked for sorting.|

comparator

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| firstValue | T | Yes| Previous element.|
| secondValue | T | Yes| Next element.|

**Example**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
arrayList.sort((a: number, b: number) => a - b);
arrayList.sort((a: number, b: number) => b - a);
arrayList.sort();
```

### subArrayList

subArrayList(fromIndex: number, toIndex: number): ArrayList&lt;T&gt;

Obtains elements within a range in this container, including the element at the start position but not that at the end position, and returns these elements as a new **ArrayList** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fromIndex | number | Yes| Index of the start position.|
| toIndex | number | Yes| Index of the end position.|

**Return value**

| Type| Description|
| -------- | -------- |
| ArrayList&lt;T&gt; | New **ArrayList** instance obtained.|

**Example**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
let result1 = arrayList.subArrayList(2, 4);
let result2 = arrayList.subArrayList(4, 3);
let result3 = arrayList.subArrayList(2, 6);
```

### clear

clear(): void

Clears this container and sets its length to **0**.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
arrayList.clear();
```

### clone

clone(): ArrayList&lt;T&gt; 

Clones this container and returns a copy. The modification to the copy does not affect the original instance.

**System capability**: SystemCapability.Utils.Lang


**Return value**

| Type| Description|
| -------- | -------- |
| ArrayList&lt;T&gt; | New **ArrayList** instance obtained.|

**Example**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
let result = arrayList.clone();
```

### getCapacity

getCapacity(): number

Obtains the capacity of this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| number | Capacity obtained.|

**Example**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
let result = arrayList.getCapacity();
```

### convertToArray

convertToArray(): Array&lt;T&gt;

Converts this container into an array.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| Array&lt;T&gt; | Array obtained.|

**Example**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
let result = arrayList.convertToArray();
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
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
let result = arrayList.isEmpty();
```

### increaseCapacityTo

increaseCapacityTo(newCapacity: number): void

Increases the capacity of this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| newCapacity | number | Yes| New capacity.|

**Example**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
arrayList.increaseCapacityTo(2);
arrayList.increaseCapacityTo(8);
```

### trimToCurrentLength

trimToCurrentLength(): void

Trims the capacity of this container to its current length.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
arrayList.trimToCurrentLength();
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
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);

// Method 1:
for (let item of arrayList) { 
  console.log(`value:${item}`); 
} 

// Method 2:
let iter = arrayList[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log(`value:${temp}`);
  temp = iter.next().value;
}
```
