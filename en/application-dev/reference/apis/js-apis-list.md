# Linear Container List

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import List from '@ohos.util.List'  
```

## System Capabilities

SystemCapability.Utils.Lang


## List


### Attributes

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of entries in a list (called container later).|


### constructor

constructor()

A constructor used to create a **List** instance.


**Example**

```ts
let list = new List();
```


### add

add(element: T): boolean

Adds an entry at the end of this container.

**Parameters**

| Name| Value Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Element to add.|

**Return value**

| Value Type | Description|
| -------- | -------- |
| boolean | Returns **true** if the entry is added successfully; returns **false** otherwise.|

**Example**

```ts
let list = new List();
let result = list.add("a");
let result1 = list.add(1);
let b = [1, 2, 3];
list.add(b);
let c = {name : "lala", age : "13"};
let result3 = list.add(false);
```

### insert

insert(element: T, index: number): void

Inserts an entry at the specified position in this container.

**Parameters**

| Name| Value Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Element to insert.|
| index | number | Yes| Index of the position where the entry is to be inserted.|

**Example**

```ts
let list = new List();
list.insert("A", 0);
list.insert(0, 1);
list.insert(true, 2);
```

### has

has(element: T): boolean

Checks whether this container has the specified entry.

**Parameters**

| Name| Value Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to check.|

**Return value**

| Value Type | Description|
| -------- | -------- |
| boolean | Returns **true** if the specified entry is contained; returns **false** otherwise.|

**Example**

```ts
let list = new List();
let result = list.has("Ahfbrgrbgnutfodgorrogorg");
list.add("Ahfbrgrbgnutfodgorrogorg");
let result1 = list.has("Ahfbrgrbgnutfodgorrogorg");
```

### get

get(index: number): T

Obtains the entry at the specified position in this container.

**Parameters**

| Name| Value Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the entry to obtain.|

**Return value**

| Value Type | Description|
| -------- | -------- |
| T | Entry obtained.|

**Example**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(2);
list.add(1);
list.add(2);
list.add(4);
let result = list.get(2);
```

### getLastIndexOf

getLastIndexOf(element: T): number

Obtains the index of the last occurrence of the specified entry in this container.

**Parameters**

| Name| Value Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to obtain.|

**Return value**

| Value Type | Description|
| -------- | -------- |
| number | Returns the position index if obtained; returns **-1** if the specified entry is not found.|

**Example**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(2);
list.add(1);
list.add(2);
list.add(4);
let result = list.getLastIndexOf(2);
```

### getIndexOf

getIndexOf(element: T): number

Obtains the index of the first occurrence of the specified entry in this container.

**Parameters**

| Name| Value Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to obtain.|

**Return value**

| Value Type | Description|
| -------- | -------- |
| number | Returns the position index if obtained; returns **-1** if the specified entry is not found.|

**Example**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(2);
list.add(1);
list.add(2);
list.add(4);
list.getIndexOf(2);
let result = list.getIndexOf(2);
```

### equal

equal(obj: Object): boolean

Compares whether a specified object is equal to this container.

**Parameters**

| Name| Value Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| obj | Object | Yes| Object used for comparison.|

**Return value**

| Value Type | Description|
| -------- | -------- |
| boolean | Returns **true** if the two are equal; returns **false** otherwise.|

**Example**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(2);
let obj1 = new List();
obj1.add(2);
obj1.add(4);
obj1.add(5);
list.equal(obj1);
let obj2 = {name : "lala", age : "13"};
let result = list.equal(obj2);
```

### removeByIndex

removeByIndex(index: number): T

Removes an entry at the specified position from this container.

**Parameters**

| Name| Value Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the entry to remove.|

**Return value**

| Value Type | Description|
| -------- | -------- |
| T | Entry removed.|

**Example**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(2);
list.add(4);
let result = list.removeByIndex(2);
```

### remove

remove(element: T): boolean

Removes the first occurrence of the specified entry from this container.

**Parameters**

| Name| Value Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to remove.|

**Return value**

| Value Type | Description|
| -------- | -------- |
| boolean | Returns **true** if the entry is removed successfully; returns **false** otherwise.|

**Example**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.remove(2);
```

### replaceAllElements

replaceAllElements(callbackfn: (value: T, index?: number, list?: List&lt;T&gt;) => T,
thisArg?: Object): void

Replaces all entries in this container with new entries, and returns the new ones.

**Parameters**

| Name| Value Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackfn | function | Yes| Callback invoked for the replacement.|
| thisArg | Object | No| Value to use when the callback is invoked.|

callbackfn

| Name| Value Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value of the entry that is currently traversed.|
| index | number | No| Position index of the entry that is currently traversed.|
| list | List&lt;T&gt; | No| Instance that invokes the **replaceAllElements** method.|

**Example**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
list.replaceAllElements((value, index) => {
  return value = 2 * value;
});
list.replaceAllElements((value, index) => {
  return value = value - 2;
});
```

### forEach

forEach(callbackfn: (value: T, index?: number, List?: List&lt;T&gt;) => void,
thisArg?: Object): void

Uses a callback to traverse the entries in this container and obtain their position indexes.

**Parameters**

| Name| Value Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackfn | function | Yes| Callback invoked to traverse the entries in the container.|
| thisArg | Object | No| Value to use when the callback is invoked.|

callbackfn

| Name| Value Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value of the entry that is currently traversed.|
| index | number | No| Position index of the entry that is currently traversed.|
| List | List&lt;T&gt; | No| Instance that invokes the **forEach** method.|

**Example**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
list.forEach((value, index) => {
  console.log(value, index);
});

```

### sort

sort(comparator: (firstValue: T, secondValue: T) => number): void

Sorts entries in this container.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| comparator | function | Yes | Callback invoked for sorting. |

comparator

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| firstValue | T | Yes | Previous entry. |
| secondValue | T | Yes | Next entry. |

**Example**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
list.sort(a, (b => a - b));
list.sort(a, (b => b - a));
```

### getSubList

getSubList(fromIndex: number, toIndex: number): List&lt;T&gt;

Obtains entries within a range in this container, including the entry at the start position but not that at the end position, and returns these entries as a new **List** instance.

**Parameters**

| Name| Value Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fromIndex | number | Yes| Index of the start position.|
| toIndex | number | Yes| Index of the end position.|

**Return value**

| Value Type | Description|
| -------- | -------- |
| List&lt;T&gt; | New **List** instance obtained.|

**Example**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.subList(2, 4);
let result1 = list.subList(4, 3);
let result2 = list.subList(2, 6);
```

### clear

clear(): void

Clears this container and sets its length to **0**.

**Example**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
list.clear();
```

### set

set(index: number, element: T): T

Replaces an entry at the specified position in this container with a given entry.

**Parameters**

| Name| Value Type | Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the entry to replace.|
| element | T | Yes| Entry to be used for replacement.|

**Return value**

| Value Type | Description|
| -------- | -------- |
| T | New entry.|

**Example**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
list.set(2, "b");

```

### convertToArray

convertToArray(): Array&lt;T&gt;

Converts this container into an array.

**Return value**

| Type | Description |
| -------- | -------- |
| Array&lt;T&gt; | Array obtained. |

**Example**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.convertToArray();
```

### isEmpty

isEmpty(): boolean

Checks whether this container is empty (contains no entry).

**Return value**

| Value Type | Description|
| -------- | -------- |
| boolean | Returns **true** if the container is empty; returns **false** otherwise.|

**Example**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.isEmpty();
```

### getFirst

getFirst(): T

Obtains the first entry in this container.

**Return value**

| Value Type | Description|
| -------- | -------- |
| T | The first entry obtained.|

**Example**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.getFirst();
```

### getLast

getLast(): T

Obtains the last entry in this container.

**Return value**

| Value Type | Description|
| -------- | -------- |
| T | The last entry obtained.|

**Example**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.getLast();
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;


Obtains an iterator, each item of which is a JavaScript object.

**Return value**

| Value Type | Description|
| -------- | -------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Example**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);

// Method 1:
for (let item of list) { 
  console.log(item); 
}

// Method 2:
let iter = list[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log(temp);
  temp = iter.next().value;
}
```
