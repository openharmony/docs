# @ohos.util.Vector (Linear Container Vector)

**Vector** is a linear data structure that is implemented based on arrays. When the memory of a vector is used up, a larger contiguous memory area is automatically allocated, all the elements are copied to the new memory area, and the current memory area is reclaimed. **Vector** can be used to efficiently access elements.

Both **Vector** and **[ArrayList](js-apis-arraylist.md)** are implemented based on arrays, but **Vector** provides more interfaces for operating the arrays. Both of them can dynamically adjust the capacity. **Vector** doubles the capacity each time, whereas **ArrayList** increases the capacity by 50%.

**Recommended use case**: Use **Vector** when the data volume is large.

This topic uses the following to identify the use of generics:
- T: Type

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are deprecated since API version 9. You are advised to use [@ohos.util.ArrayList](js-apis-arraylist.md).

## Modules to Import

```ts
import { Vector } from '@kit.ArkTS';
```


## Vector

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a vector (called container later).|


### constructor

constructor()

A constructor used to create a **Vector** instance.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let vector : Vector<string | number | Array<number>> = new Vector();
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
class C1 {
  name: string = ""
  age: string = ""
}
let vector : Vector<string | number | C1 | Array<number>> = new Vector();
let result = vector.add("a");
let result1 = vector.add(1);
let b = [1, 2, 3];
let result2 = vector.add(b);
let c: C1 = {name : "Jack", age : "13"};
let result3 = vector.add(c);
```

### insert

insert(element: T, index: number): void

Inserts an element within the length range and moves its subsequent elements rightwards.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|
| index | number | Yes| Index of the position where the element is to be inserted.|

**Example**

```ts
let vector : Vector<string | number | Object | Array<number>> = new Vector();
vector.insert("A", 0);
vector.insert(0, 1);
vector.insert(true, 2);
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
| boolean | Returns **true** if the container has the specified element; returns **false** otherwise.|

**Example**

```ts
let vector : Vector<string> = new Vector();
let result = vector.has("squirrel");
vector.add("squirrel");
let result1 = vector.has("squirrel");
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
| number | Returns the position index if obtained; returns **-1** otherwise.|

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(2);
vector.add(1);
vector.add(2);
vector.add(4);
let result = vector.getIndexOf(2);
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
| number | Returns the position index if obtained; returns **-1** otherwise.|

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(2);
vector.add(1);
vector.add(2);
vector.add(4);
let result = vector.getLastIndexOf(2);
```

### removeByIndex

removeByIndex(index: number): T

Searches for an element based on its index, removes the element after returning it, and moves its subsequent elements leftwards.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element removed. If the container is empty, **undefined** is returned. If the index is out of range, an exception is thrown.|

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(2);
vector.add(4);
let result = vector.removeByIndex(2);
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
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.remove(2);
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
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.removeByRange(2,4);
```

### replaceAllElements

replaceAllElements(callbackFn: (value: T, index?: number, vector?: Vector&lt;T&gt;) => T,
thisArg?: Object): void

Replaces all elements in this container with new elements, and returns the new ones.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackFn | function | Yes| Callback invoked for replacement.|
| thisArg | Object | No| Value of **this** to use when **callbackFn** is invoked. The default value is this instance.|

callbackFn

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value of the element that is currently traversed.|
| index | number | No| Position index of the element that is currently traversed. The default value is **0**.|
| vector | Vector&lt;T&gt; | No| Instance that calls the **replaceAllElements** API. The default value is this instance.|

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.replaceAllElements((value : number) : number => {
  // Add the user operation logic based on the actual scenario.
  return value;
});
```

### forEach

forEach(callbackFn: (value: T, index?: number, vector?: Vector&lt;T&gt;) => void,
thisArg?: Object): void

Uses a callback to traverse the elements in this container and obtain their position indexes.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackFn | function | Yes| Callback invoked for replacement.|
| thisArg | Object | No| Value of **this** to use when **callbackFn** is invoked. The default value is this instance.|

callbackFn

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value of the element that is currently traversed.|
| index | number | No| Position index of the element that is currently traversed. The default value is **0**.|
| vector | Vector&lt;T&gt; | No| Instance that calls the **forEach** API. The default value is this instance.|

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.forEach((value : number, index ?: number) : void => {
  console.log("value:" + value, "index:" + index);
});
```

### sort

sort(comparator?: (firstValue: T, secondValue: T) => number): void

Sorts elements in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| comparator | function | No| Callback invoked for sorting. The default value is this instance.|

comparator

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| firstValue | T | Yes| Previous element.|
| secondValue | T | Yes| Next element.|

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.sort((a: number, b: number) => a - b);
vector.sort((a: number, b: number) => b - a);
vector.sort();
```

### subVector

subVector(fromIndex: number, toIndex: number): Vector&lt;T&gt;

Obtains elements within a range in this container, including the element at the start position but not that at the end position, and returns these elements as a new **Vector** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fromIndex | number | Yes| Index of the start position.|
| toIndex | number | Yes| Index of the end position.|

**Return value**

| Type| Description|
| -------- | -------- |
| Vector&lt;T&gt; | New **Vector** instance obtained.|

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.add(6);
vector.add(8);
let result = vector.subVector(0,4);
let result1 = vector.subVector(2,4);

```

### clear

clear(): void

Clears all elements in this container and sets its length to **0**.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.clear();
```

### clone

clone(): Vector&lt;T&gt;

Clones this container and returns a copy. The modification to the copy does not affect the original instance.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| Vector&lt;T&gt; | New **Vector** instance obtained.|

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.clone();
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
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.getCapacity();
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
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.convertToArray();
```

### isEmpty

isEmpty(): boolean

Checks whether this container is empty (contains no elements).

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the container is empty; returns **false** otherwise.|

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.isEmpty();
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
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.increaseCapacityTo(2);
vector.increaseCapacityTo(12);
```

### trimToCurrentLength

trimToCurrentLength(): void

Trims the capacity of this container into its current length.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.trimToCurrentLength();
```

### toString

toString(): string

Uses commas (,) to concatenate elements in this container into a string.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| string | String obtained.|

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.toString();
```

### copyToArray

copyToArray(array: Array&lt;T&gt;): void

Copies elements in this container into an array to overwrite elements of the same position indexes.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| array | Array&lt;T&gt; | Yes| Array to which the elements in the container will be copied.|

### getFirstElement

getFirstElement(): T

Obtains the first element in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | The first element obtained.|

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.getFirstElement();
```

### getLastElement

getLastElement(): T

Obtains the last element in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | The last element obtained.|

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.getLastElement();
```

### getLastIndexFrom

getLastIndexFrom(element: T, index: number): number

Searches for an element backward from the specified position index and returns the position index of the element.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|
| index | number | Yes| Position index where the search starts.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns the position index if obtained; returns **-1** otherwise.|

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.getLastIndexFrom(4,3);
```

### getIndexFrom

getIndexFrom(element: T, index: number): number

Searches for an element forward from the specified position index and returns the position index of the element.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|
| index | number | Yes| Position index where the search starts.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns the position index if obtained; returns **-1** otherwise.|

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.getIndexFrom(4, 3);
```

### setLength

setLength(newSize: number): void

Sets a new length for this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| newSize | number | Yes| New length to set.|

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.setLength(8);
vector.setLength(2);
```

### get

get(index: number): T 

Obtains an element at the specified position in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | index | number | Yes| Position index of the target element.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | T | Element obtained.|

**Example**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.get(2);
```

### set

set(index: number, element: T): T

Replaces an element at the specified position in this container with a given element.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the target element.|
| element | T | Yes| Element to be used for replacement.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | T | New element.|

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
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
// Method 1:
let nums: Array<number> =  vector.convertToArray()
for (let item of nums) {
  console.log("value:" + item);
}

// Method 2:
let iter = vector[Symbol.iterator]();
let temp: IteratorResult<number> = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
```
