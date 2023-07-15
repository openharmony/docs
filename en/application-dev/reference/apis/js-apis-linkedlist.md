# @ohos.util.LinkedList (Linear Container LinkedList)

**LinkedList** is implemented based on the doubly linked list. Each node of the doubly linked list has references pointing to the previous element and the next element. When querying an element, the system traverses the list from the beginning or end. **LinkedList** offers efficient insertion and removal operations but supports low query efficiency. **LinkedList** allows null elements.

Unlike **[List](js-apis-list.md)**, which is a singly linked list, **LinkedList** is a doubly linked list that supports insertion and removal at both ends.

**LinkedList** is more efficient in data insertion than **[ArrayList](js-apis-arraylist.md)**, but less efficient in data access.

**Recommended use case**: Use **LinkedList** for frequent insertion and removal operations.

This topic uses the following to identify the use of generics:
- T: Type

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import LinkedList from '@ohos.util.LinkedList';  
```

## LinkedList

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a linked list (called container later).|


### constructor

constructor()

A constructor used to create a **LinkedList** instance.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200012 | The LinkedList's constructor cannot be directly invoked. |


**Example**

```ts
let linkedList = new LinkedList();
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

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The add method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList();
let result = linkedList.add("a");
let result1 = linkedList.add(1);
let b = [1, 2, 3];
let result2 = linkedList.add(b);
let c = {name : "Dylon", age : "13"};
let result3 = linkedList.add(c);
let result4 = linkedList.add(false);
```

### addFirst

addFirst(element: T): void

Adds an element at the top of this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The addFirst method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList();
linkedList.addFirst("a");
linkedList.addFirst(1);
let b = [1, 2, 3];
linkedList.addFirst(b);
let c = {name : "Dylon", age : "13"};
linkedList.addFirst(c);
linkedList.addFirst(false);
```

### insert

insert(index: number, element: T): void

Inserts an element at the specified position in this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|
| index | number | Yes| Index of the position where the element is to be inserted.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The insert method cannot be bound. |
| 10200001 | The value of index is out of range. |

**Example**

```ts
let linkedList = new LinkedList();
linkedList.insert(0, "A");
linkedList.insert(1, 0);
linkedList.insert(2, true);
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

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The has method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add("squirrel");
let result = linkedList.has("squirrel");
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

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The get method cannot be bound. |

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

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getLastIndexOf method cannot be bound. |

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

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getIndexOf method cannot be bound. |

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

Removes an element at the specified position from this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element removed.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The removeByIndex method cannot be bound. |
| 10200001 | The value of index is out of range. |

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

Removes the first element from this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element removed.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The removeFirst method cannot be bound. |
| 10200010 | Container is empty. |

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

Removes the last element from this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element removed.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The removeLast method cannot be bound. |
| 10200010 | Container is empty. |

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

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The remove method cannot be bound. |

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

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The removeFirstFound method cannot be bound. |
| 10200010 | Container is empty. |
| 10200017 | The element does not exist in this container. |

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

Removes the last occurrence of the specified element from this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the element is removed successfully; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The removeLastFound method cannot be bound. |
| 10200010 | Container is empty. |
| 10200017 | The element does not exist in this container. |

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

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| LinkedList&lt;T&gt; | New **LinkedList** instance obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The clone method cannot be bound. |

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

forEach(callbackFn: (value: T, index?: number, LinkedList?: LinkedList&lt;T&gt;) => void,
thisArg?: Object): void

Uses a callback to traverse the elements in this container and obtain their position indexes.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackFn | function | Yes| Callback invoked to traverse the elements in the container.|
| thisArg | Object | No| Value of **this** to use when **callbackFn** is invoked. The default value is this instance.|

callbackFn

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value of the element that is currently traversed.|
| index | number | No| Position index of the element that is currently traversed. The default value is **0**.|
| LinkedList | LinkedList&lt;T&gt; | No| Instance that calls the **forEach** API. The default value is this instance.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The forEach method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
linkedList.forEach((value, index) => {
    console.log("value:" + value, "index:" + index);
});
```

### clear

clear(): void

Clears this container and sets its length to **0**.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The clear method cannot be bound. |

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

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The set method cannot be bound. |
| 10200001 | The value of index is out of range. |

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

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| Array&lt;T&gt; | Array obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The convertToArray method cannot be bound. |

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

Obtains the first element in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | Returns the element if obtained; returns **undefined** otherwise.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getFirst method cannot be bound. |

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

Obtains the last element in this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | Returns the element if obtained; returns **undefined** otherwise.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getLast method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.getLast();
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

Obtains an iterator, each item of which is a JavaScript object.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);

// Method 1:
for (let item of linkedList) { 
  console.log("value:" + item); 
} 

// Method 2:
let iter = linkedList[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
```
