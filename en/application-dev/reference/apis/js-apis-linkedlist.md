# Linear Container LinkedList

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**LinkedList** is implemented based on the doubly linked list. Each node of the doubly linked list has references pointing to the previous element and the next element. When querying an element, the system traverses the list from the beginning or end. **LinkedList** offers efficient insertion and removal operations but supports low query efficiency. **LinkedList** allows null elements.

Unlike **[List](js-apis-list.md)**, which is a singly linked list, **LinkedList** is a doubly linked list that supports insertion and removal at both ends.

**LinkedList** is less efficient in data access than **[ArrayList](js-apis-arraylist.md)**.

**Recommended use case**: Use **LinkedList** for frequent insertion and removal operations.

This topic uses the following to identify the use of generics:
- T: Type

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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200012 | The LinkedList's constructor cannot be directly invoked. |


**Example**

```ts
let linkedList = new LinkedList();
try {
  let linkedList2 = LinkedList();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

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
try {
  linkedList.add.bind({}, "b")(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

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
try {
  linkedList.addFirst.bind({}, "b")(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The insert method cannot be bound. |
| 10200001 | The value of parameters are out of range. |

**Example**

```ts
let linkedList = new LinkedList();
linkedList.insert(0, "A");
linkedList.insert(1, 0);
linkedList.insert(2, true);
try {
  linkedList.insert.bind({}, 3, "b")(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
try {
  linkedList.insert(6, "b");
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The has method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList();
let result1 = linkedList.has("squirrel");
linkedList.add("squirrel");
let result = linkedList.has("squirrel");
try {
  linkedList.has.bind({}, "squirrel")(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

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
try {
  linkedList.get.bind({}, 2)(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

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
try {
  linkedList.getLastIndexOf.bind({}, 2)(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

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
try {
  linkedList.getIndexOf.bind({}, 2)(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The removeByIndex method cannot be bound. |
| 10200001 | The value of parameters are out of range. |

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(2);
linkedList.add(4);
let result = linkedList.removeByIndex(2);
try {
  linkedList.removeByIndex.bind({}, 2)(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
try {
  linkedList.removeByIndex(8);
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The removeFirst method cannot be bound. |
| 10200010 | Container is empty. |

**Example**

```ts
let linkedList = new LinkedList();
try {
  linkedList.removeFirst();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(2);
linkedList.add(4);
let result = linkedList.removeFirst();
try {
  linkedList.removeFirst.bind({})(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The removeLast method cannot be bound. |
| 10200010 | Container is empty. |

**Example**

```ts
let linkedList = new LinkedList();
try {
  linkedList.removeLast();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(2);
linkedList.add(4);
let result = linkedList.removeLast();
try {
  linkedList.removeLast.bind({})(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

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
try {
  linkedList.remove.bind({}, 2)(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The removeFirstFound method cannot be bound. |
| 10200010 | Container is empty. |

**Example**

```ts
let linkedList = new LinkedList();
try {
  linkedList.removeFirstFound(4);
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.removeFirstFound(4);
try {
  linkedList.removeFirstFound.bind({}, 2)(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The removeLastFound method cannot be bound. |
| 10200010 | Container is empty. |

**Example**

```ts
let linkedList = new LinkedList();
try {
  linkedList.removeLastFound();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.removeLastFound(4);
try {
  linkedList.removeLastFound.bind({}, 4)(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

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
try {
  linkedList.clone.bind({})(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### forEach

forEach(callbackfn: (value: T, index?: number, LinkedList?: LinkedList&lt;T&gt;) => void,
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
| LinkedList | LinkedList&lt;T&gt; | No| Instance that invokes the **forEach** API.|

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

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
  console.log("value:" + value, index);
});
try {
  linkedList.forEach.bind({}, (value, index) => {
    console.log("value:" + value, index);
  })(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### clear

clear(): void

Clears this container and sets its length to **0**.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

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
try {
  linkedList.clear.bind({})(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The set method cannot be bound. |
| 10200001 | The value of parameters are out of range. |

**Example**

```ts
let linkedList = new LinkedList();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.set(2, "b");
try {
  linkedList.set.bind({}, 2, "b")(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
try {
  linkedList.set(8, "b");
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

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
try {
  linkedList.convertToArray.bind({})(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

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
try {
  linkedList.getFirst.bind({})(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
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

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

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
linkedList.getLast();
try {
  linkedList.getLast.bind({})(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
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

**Error codes**

For details about the error codes, see [containers Error Codes](../errorcodes/errorcode-containers.md).

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
try {
  linkedList[Symbol.iterator].bind({})(); // bind() creates a new bound function that, when called, has its this keyword set to the provided value. It is used to test exception capture.
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```
