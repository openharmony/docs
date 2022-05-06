# Linear Container LinkedList

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import LinkedList from '@ohos.util.LinkedList'  
```

## System Capability

SystemCapability.Utils.Lang


## LinkedList


### Attributes

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of entries in a linked list (called container later).|


### constructor

constructor()

A constructor used to create a **LinkedList** instance.


**Example**

```ts
let linkedList = new LinkedList();
```


### add

add(element: T): boolean

Adds an entry at the end of this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to add.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the entry is added successfully; returns **false** otherwise.|

**Example**

```ts
let linkedList = new LinkedList();
let result = linkedList.add("a");
let result1 = linkedList.add(1);
let b = [1, 2, 3];
linkedList.add(b);
let c = {name : "lala", age : "13"};
let result3 = linkedList.add(false);
```

### addFirst

addFirst(element: T): void

Adds an entry at the top of this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to add.|

**Example**

```ts
let linkedList = new LinkedList();
linkedList.addFirst("a");
linkedList.addFirst(1);
let b = [1, 2, 3];
linkedList.addFirst(b);
let c = {name : "lala", age : "13"};
linkedList.addFirst(false);
```

### insert

insert(index: number, element: T): void

Inserts an entry at the specified position in this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to insert.|
| index | number | Yes| Index of the position where the entry is to be inserted.|

**Example**

```ts
let linkedList = new LinkedList();
linkedList.insert(0, "A");
linkedList.insert(1, 0);
linkedList.insert(2, true);
```

### has

has(element: T): boolean

Checks whether this container has the specified entry.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to check.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified entry is contained; returns **false** otherwise.|

**Example**

```ts
let linkedList = new LinkedList();
let result1 = linkedList.has("Ahfbrgrbgnutfodgorrogorg");
linkedList.add("Ahfbrgrbgnutfodgorrogorg");
let result = linkedList.has("Ahfbrgrbgnutfodgorrogorg");
```

### get

get(index: number): T

Obtains an entry at the specified position in this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the entry to query.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Entry obtained.|

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(2);
linkedList.add(1);
linkedList.add(2);
linkedList.add(4);
let result = linkedList.get(2);
```

### getLastIndexOf

getLastIndexOf(element: T): number

Obtains the index of the last occurrence of the specified entry in this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to check.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns the position index if obtained; returns **-1** if the specified entry is not found.|

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(2);
linkedList.add(1);
linkedList.add(2);
linkedList.add(4);
let result = linkedList.getLastIndexOf(2);
```

### getIndexOf

getIndexOf(element: T): number

Obtains the index of the first occurrence of the specified entry in this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to check.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Returns the position index if obtained; returns **-1** if the specified entry is not found.|

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(2);
linkedList.add(1);
linkedList.add(2);
linkedList.add(4);
let result = linkedList.getIndexOf(2);
```

### removeByIndex

removeByIndex(index: number): T

Removes an entry at the specified position from this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the entry to remove.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Entry removed.|

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(2);
linkedList.add(4);
let result = linkedList.removeByIndex(2);
```

### removeFirst

removeFirst(): T

Removes the first entry from this container.

**Return value**

| Type| Description|
| -------- | -------- |
| T | Entry removed.|

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(2);
linkedList.add(4);
let result = linkedList.removeFirst();
```

### removeLast

removeLast(): T

Removes the last entry from this container.

**Return value**

| Type| Description|
| -------- | -------- |
| T | Entry removed.|

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(2);
linkedList.add(4);
let result = linkedList.removeLast();
```

### remove

remove(element: T): boolean

Removes the first occurrence of the specified entry from this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to check.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the entry is removed successfully; returns **false** otherwise.|

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.remove(2);
```

### removeFirstFound

removeFirstFound(element: T): boolean

Removes the first occurrence of the specified entry from this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to check.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the entry is removed successfully; returns **false** otherwise.|

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.removeFirstFound(4);
```

### removeLastFound

removeLastFound(element: T): boolean

Removes the last occurrence of the specified entry from this container.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Entry to check.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the entry is removed successfully; returns **false** otherwise.|

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.removeLastFound(4);
```

### clone

clone(): LinkedList&lt;T&gt;

Clones this container and returns a copy. The modification to the copy does not affect the original instance.

**Return value**

| Type| Description|
| -------- | -------- |
| LinkedList&lt;T&gt; | New **LinkedList** instance obtained.|

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.clone();
```

### forEach

forEach(callbackfn: (value: T, index?: number, LinkedList?: LinkedList&lt;T&gt;) => void,
thisArg?: Object): void

Uses a callback to traverse the entries in this container and obtain their position indexes.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackfn | function | Yes| Callback invoked to traverse the entries in the container.|
| thisArg | Object | No| Value to use when the callback is invoked.|

callbackfn

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value of the entry that is currently traversed.|
| index | number | No| Position index of the entry that is currently traversed.|
| LinkedList | LinkedList&lt;T&gt; | No| Instance that invokes the **forEach** API.|

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
linkedList.forEach((value, index) => {
  console.log(value, index);
});
```

### clear

clear(): void

Clears this container and sets its length to **0**.

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
linkedList.clear();
```

### set

set(index: number, element: T): T

Replaces an entry at the specified position in this container with a given entry.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the entry to replace.|
| element | T | Yes| Entry to be used for replacement.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | New entry.|

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.set(2, "b");
```

### convertToArray

convertToArray(): Array&lt;T&gt;

Converts this container into an array.

**Return value**

| Type| Description|
| -------- | -------- |
| Array&lt;T&gt; | Array obtained.|

**Example**
```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.convertToArray();
```

### getFirst

getFirst(): T

Obtains the first entry in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| T | Returns the entry if obtained; returns **undefined** otherwise.|

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.getFirst();
```

### getLast

getLast(): T

Obtains the last entry in this container.

**Return value**

| Type| Description|
| -------- | -------- |
| T | Returns the entry if obtained; returns **undefined** otherwise.|

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
linkedList.getLast();
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
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);

// Method 1:
for (let item of linkedList) { 
  console.log(item); 
} 

// Method 2:
let iter = linkedList[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log(temp);
  temp = iter.next().value;
}
```
