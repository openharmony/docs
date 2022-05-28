# Linear Container Vector

> **NOTE**<br>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import Vector from '@ohos.util.Vector'  
```

## System Capability

SystemCapability.Utils.Lang


## Vector


### Attributes

 | Name | Type | Readable | Writable | Description |
 | -------- | -------- | -------- | -------- | -------- |
 | length | number | Yes | No | Number of entries in a vector (called container later). |


### constructor

constructor()

A constructor used to create a **Vector** instance.

**Example**

```ts
let vector = new Vector();
```


### add

add(element: T): boolean

Adds an entry at the end of this container.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | element | T | Yes | Entry to add. |

**Return value**

 | Type | Description |
 | -------- | -------- |
 | boolean | Returns **true** if the entry is added successfully; returns **false** otherwise. |

**Example**

```ts
let vector = new Vector();
let result = vector.add("a");
let result1 = vector.add(1);
let b = [1, 2, 3];
vector.add(b);
let c = {name : "lala", age : "13"};
let result3 = vector.add(c);
```

### insert

insert(element: T, index: number): void

Inserts an entry at the specified position in this container.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | element | T | Yes | Entry to insert. |
 | index | number | Yes | Index of the position where the entry is to be inserted. |

**Example**

```ts
let vector = new Vector();
vector.insert("A", 0);
vector.insert(0, 1);
vector.insert(true, 2);
```

### has

has(element: T): boolean

Checks whether this container has the specified entry.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | element | T | Yes | Entry to check. |

**Return value**

 | Type | Description |
 | -------- | -------- |
 | boolean | Returns **true** if the entry is contained; returns **false** otherwise. |

**Example**

```ts
let vector = new Vector();
let result = vector.has("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
vector.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
let result1 = vector.has("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
``` 

### getIndexOf

getIndexOf(element: T): number

Obtains the index of the first occurrence of the specified entry in this container.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | element | T | Yes | Entry to obtain. |

**Return value**

 | Type | Description |
 | -------- | -------- |
 | number | Returns the position index if obtained; returns **-1** if the specified entry is not found. |

**Example**

```ts
let vector = new Vector();
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

Obtains the index of the last occurrence of the specified entry in this container.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | element | T | Yes | Entry to obtain. |

**Return value**

 | Type | Description |
 | -------- | -------- |
 | number | Returns the position index if obtained; returns **-1** if the specified entry is not found. |

**Example**

```ts
let vector = new Vector();
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

Removes an entry at the specified position from this container.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | index | number | Yes | Position index of the entry to remove. |

**Return value**

 | Type | Description |
 | -------- | -------- |
 | T | Entry removed. |

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(2);
vector.add(4);
let result = vector.removeByIndex(2);
```

### remove

remove(element: T): boolean

Removes the first occurrence of the specified entry from this container.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | element | T | Yes | Entry to remove. |

**Return value**

 | Type | Description |
 | -------- | -------- |
 | boolean | Returns **true** if the entry is removed successfully; returns **false** otherwise. |

**Return value**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.remove(2);
```

### removeByRange

removeByRange(fromIndex: number, toIndex: number): void

Removes from this container all of the entries within a range, including the entry at the start position but not that at the end position.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | fromIndex | number | Yes | Index of the start position. |
 | toIndex | number | Yes | Index of the end position. |

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.removeByRange(2,4);
vector.removeByRange(4,3);
vector.removeByRange(2,6);
```

### replaceAllElements

replaceAllElements(callbackfn: (value: T, index?: number, vector?: Vector&lt;T&gt;) => T,
thisArg?: Object): void

Replaces all entries in this container with new entries, and returns the new ones.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | callbackfn | function | Yes | Callback invoked for replacement. |
 | thisArg | Object | No | Value to use when the callback is invoked. |

callbackfn

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | value | T | Yes | Value of the entry that is currently traversed. |
 | index | number | No | Position index of the entry that is currently traversed. |
 | vector | Vector&lt;T&gt; | No | Instance that invokes the **replaceAllElements** API. |

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.replaceAllElements((value, index) => {
  return value = 2 * value;
});
vector.replaceAllElements((value, index) => {
  return value = value - 2;
});
```

### forEach

forEach(callbackfn: (value: T, index?: number, vector?: Vector&lt;T&gt;) => void,
thisArg?: Object): void

Uses a callback to traverse the entries in this container and obtain their position indexes.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | callbackfn | function | Yes | Callback invoked for replacement. |
 | thisArg | Object | No | Value to use when the callback is invoked. |

callbackfn

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | value | T | Yes | Value of the entry that is currently traversed. |
 | index | number | No | Position index of the entry that is currently traversed. |
 | vector | Vector&lt;T&gt; | No | Instance that invokes the **forEach** API. |

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.forEach((value, index) => {
  console.log(value, index)
});

```

### sort

sort(comparator?: (firstValue: T, secondValue: T) => number): void

Sorts entries in this container.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | comparator | function | No | Callback invoked for sorting. |

comparator

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | firstValue | T | Yes | Previous entry. |
 | secondValue | T | Yes | Next entry. |

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.sort(a, (b => a - b));
vector.sort(a, (b => b - a));
vector.sort();
```

### subVector

subVector(fromIndex: number, toIndex: number): Vector&lt;T&gt;

Obtains entries within a range in this container, including the entry at the start position but not that at the end position, and returns these entries as a new **Vector** instance.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | fromIndex | number | Yes | Index of the start position. |
 | toIndex | number | Yes | Index of the end position. |

**Return value**

 | Type | Description |
 | -------- | -------- |
 | Vector&lt;T&gt; | New **Vector** instance obtained. |

**Return value**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.subVector(2,4);
let result1 = vector.subVector(4,3);
let result2 = vector.subVector(2,6);

```

### clear

clear(): void

Clears all entries in this container and sets its length to **0**.

**Return value**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.clear();
```

### clone

clone(): Vector&lt;T&gt;

Clones this container and returns a copy. The modification to the copy does not affect the original instance.

**Return value**

 | Type | Description |
 | -------- | -------- |
 | Vector&lt;T&gt; | New **Vector** instance obtained. |

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.clone();
```

### getCapacity

getCapacity(): number

Obtains the capacity of this container.

**Return value**

 | Type | Description |
 | -------- | -------- |
 | number | Capacity obtained. |

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.getCapacity();
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
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.convertToArray();
```

### isEmpty

isEmpty(): boolean

Checks whether this container is empty (contains no entries).

**Return value**

 | Type | Description |
 | -------- | -------- |
 | boolean | Returns **true** if the container is empty; returns **false** otherwise. |

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.isEmpty();
```

### increaseCapacityTo

increaseCapacityTo(newCapacity: number): void

Increases the capacity of this container.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | newCapacity | number | Yes | New capacity. |

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.increaseCapacityTo(2);
vector.increaseCapacityTo(8);
```

### trimToCurrentLength

trimToCurrentLength(): void

Trims the capacity of this container into its current length.

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.trimToCurrentLength();
```

### toString

toString(): string

Uses commas (,) to concatenate entries in this container into a string.

**Return value**

 | Type | Description |
 | -------- | -------- |
 | string | String obtained. |

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.toSting();
```

### copyToArray

copyToArray(array: Array&lt;T&gt;): void

Copies entries in this container into an array to overwrite elements of the same position indexes.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | array | Array&lt;T&gt; | Yes | Array to which the entries in the container will be copied. |

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let array = ["a", "b", "c", "d", "e", "f"];
let result = vector.copyToArray(array);
```

### getFirstElement

getFirstElement(): T

Obtains the first entry in this container.

**Return value**

 | Type | Description |
 | -------- | -------- |
 | T | The first entry obtained. |

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.getFirstElement();
```

### getLastElement

getLastElement(): T

Obtains the last entry in this container.

**Return value**

 | Type | Description |
 | -------- | -------- |
 | T | The last entry obtained. |

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.getLastElement();
```

### getLastIndexFrom

getLastIndexFrom(element: T, index: number): number

Searches for an entry backward from the specified position index and returns the position index of the entry.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | element | T | Yes | Entry to query. |
 | index | number | Yes | Position index where the search starts. |

**Return value**

 | Type | Description |
 | -------- | -------- |
 | number | Returns the position index if obtained; returns **-1** if the entry is not found. |

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.add("a");
let result = vector.getLastIndexFrom(4,3);
```

### getIndexFrom

getIndexFrom(element: T, index: number): number

Searches for an entry forward from the specified position index and returns the position index of the entry.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | element | T | Yes | Entry to query. |
 | index | number | Yes | Position index where the search starts. |

**Return value**

 | Type | Description |
 | -------- | -------- |
 | number | Returns the position index if obtained; returns **-1** if the entry is not found. |

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.add("a");
let result = vector.getIndexFrom(4, 3);
```

### setLength

setLength(newSize: number): void

Sets a new length for this container.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | newSize | number | Yes | New length to set. |

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.setLength(8);
vector.setLength(2);
```

### get

get(index: number): T 

Obtains an entry at the specified position in this container.

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | index | number | Yes | Position index of the entry to obtain. |

**Return value**

  | Type | Description |
  | -------- | -------- |
  | T | Entry obtained. |

**Example**

  ```ts
  let vector = new Vector();
  vector.add(2);
  vector.add(4);
  vector.add(5);
  vector.add(4);
  let result = vector.get(2);
  ```
### set

set(index: number, element: T): T

Replaces an entry at the specified position in this container with a given entry.

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | index | number | Yes | Position index of the entry to replace. |
 | element | T | Yes | Entry to be used for replacement. |

**Return value**

  | Type | Description |
  | -------- | -------- |
  | T | New entry. |

**Example**

  ```ts
  let vector = new Vector();
  vector.add(2);
  vector.add(4);
  vector.add(5);
  vector.add(4);
  let result = vector.set(2, "A");
  ```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;


Obtains an iterator. Each item of the iterator is a JavaScript object.

**Return value**
 | Type | Description |
 | -------- | -------- |
 | IterableIterator&lt;T&gt; | Iterator obtained. |

**Example**

```ts
let vector = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);

// Method 1:
for (let item of vector) { 
  console.log(item); 
} 

// Method 2:
let iter = vector[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log(temp);
  temp = iter.next().value;
}
```
