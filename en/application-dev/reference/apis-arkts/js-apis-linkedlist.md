# @ohos.util.LinkedList (Linear Container LinkedList)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @yuanyao14-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

LinkedList is implemented based on the doubly linked list. Each node of the doubly linked list has references pointing to the previous element and the next element. When querying an element, the system traverses the list from the beginning or end. LinkedList offers efficient insertion and removal operations but supports low query efficiency. LinkedList allows null elements.

Unlike [List](js-apis-list.md), which is a singly linked list, LinkedList is a doubly linked list that supports insertion and removal at both ends.

LinkedList is more efficient in data insertion than [ArrayList](js-apis-arraylist.md), but less efficient in data access.

> **NOTE**
>
> Accessing elements in a LinkedList using the \[index\] syntax may lead to undefined results. You are advised to use **get()** instead.

**Recommended use case**: Use LinkedList for frequent insertion and removal operations when a doubly linked list is required.

This topic uses the following to identify the use of generics:
- T: Type

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> Container classes, implemented in static languages, have restrictions on storage locations and properties, and do not support custom properties or methods.


## Modules to Import

```ts
import { LinkedList } from '@kit.ArkTS';
```

## LinkedList

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a LinkedList.|


### constructor

constructor()

A constructor used to create a **LinkedList** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200012 | The LinkedList's constructor cannot be directly invoked. |


**Example**

```ts
let linkedList = new LinkedList<string | number | boolean | object>();
```


### add

add(element: T): boolean

Adds an element at the end of this LinkedList.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Operation result. The value **true** is returned if the element is added; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The add method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<string | number | boolean | object>();
let result = linkedList.add("a");
let result1 = linkedList.add(1);
let b = [1, 2, 3];
let result2 = linkedList.add(b);
class C {
  name: string = ''
  age: string = ''
}
let c: C = {name : "Dylan", age : "13"};
let result3 = linkedList.add(c);
let result4 = linkedList.add(false);
console.info("result = ", result4) // result =  true
```

### addFirst

addFirst(element: T): void

Adds an element at the top of this LinkedList.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The addFirst method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<string | number | boolean | object>();
linkedList.addFirst("a");
linkedList.addFirst(1);
let b = [1, 2, 3];
linkedList.addFirst(b);
class C {
  name: string = ''
  age: string = ''
}
let c: C = {name : "Dylan", age : "13"};
linkedList.addFirst(c);
linkedList.addFirst(false);
let result = linkedList.get(2);
console.info("result:", result);  // result: 1,2,3
```

### insert

insert(index: number, element: T): void

Inserts an element at the specified position in this LinkedList.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Index of the position where the element is to be inserted. The value must be less than or equal to int32_max, that is, 2147483647.|
| element | T | Yes| Target element.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of index is out of range. |
| 10200011 | The insert method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<string | number | boolean | object>();
linkedList.insert(0, "A");
linkedList.insert(1, 0);
linkedList.insert(2, true);
let result = linkedList.get(1);
console.info("result:", result);  // result: 0
```

### has

has(element: T): boolean

Checks whether this LinkedList has the specified element.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Operation result. The value **true** is returned if the specified element is contained; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The has method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<string>();
linkedList.add("squirrel");
let result = linkedList.has("squirrel");
console.info("result:", result);  // result: true
```

### get

get(index: number): T

Obtains an element at the specified position in this LinkedList.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the target element. The value must be less than or equal to int32_max, that is, 2147483647.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element obtained. If the element does not exist, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The get method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<number>();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(2);
linkedList.add(1);
linkedList.add(2);
linkedList.add(4);
let result = linkedList.get(2);
console.info("result:", result);  // result: 5
```

### getLastIndexOf

getLastIndexOf(element: T): number

Obtains the index of the last occurrence of the specified element in this LinkedList.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Index of the element. If no match is found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getLastIndexOf method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<number>();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(2);
linkedList.add(1);
linkedList.add(2);
linkedList.add(4);
let result = linkedList.getLastIndexOf(2);
console.info("result:", result);  // result: 5
```

### getIndexOf

getIndexOf(element: T): number

Obtains the index of the first occurrence of the specified element in this LinkedList.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Index of the element. If no match is found, **-1** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getIndexOf method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<number>();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(2);
linkedList.add(1);
linkedList.add(2);
linkedList.add(4);
let result = linkedList.getIndexOf(2);
console.info("result:", result);  // result: 0
```

### removeByIndex

removeByIndex(index: number): T

Searches for an element based on its index and then removes it.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the target element. The value must be less than or equal to int32_max, that is, 2147483647.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element removed. If the element does not exist, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of index is out of range. |
| 10200011 | The removeByIndex method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<number>();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(2);
linkedList.add(4);
let result = linkedList.removeByIndex(2);
console.info("result:", result);  // result: 5
```

### removeFirst

removeFirst(): T

Removes the first element from this LinkedList.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element removed.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200010 | Container is empty. |
| 10200011 | The removeFirst method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<number>();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(2);
linkedList.add(4);
let result = linkedList.removeFirst();
console.info("result:", result);  // result: 2
```

### removeLast

removeLast(): T

Removes the last element from this LinkedList.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element removed.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200010 | Container is empty. |
| 10200011 | The removeLast method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<number>();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(2);
linkedList.add(4);
let result = linkedList.removeLast();
console.info("result:", result);  // result: 4
```

### remove

remove(element: T): boolean

Removes the first occurrence of the specified element from this LinkedList.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Operation result. The value **true** is returned if the element is removed; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The remove method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<number>();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.remove(2);
console.info("result:", result);  // result: true
```

### removeFirstFound

removeFirstFound(element: T): boolean

Removes the first occurrence of the specified element from this LinkedList.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the element is removed; returns **false** if the element fails to be removed or does not exist.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200010 | Container is empty. |
| 10200011 | The removeFirstFound method cannot be bound. |
| 10200017 | The element does not exist in this container. |

**Example**

```ts
let linkedList = new LinkedList<number>();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.removeFirstFound(4);
console.info("result:", result);  // result: true
```

### removeLastFound

removeLastFound(element: T): boolean

Removes the last occurrence of the specified element from this LinkedList.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the element is removed; returns **false** if the element fails to be removed or does not exist.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200010 | Container is empty. |
| 10200011 | The removeLastFound method cannot be bound. |
| 10200017 | The element does not exist in this container. |

**Example**

```ts
let linkedList = new LinkedList<number>();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.removeLastFound(4);
console.info("result:", result);  // result: true
```

### clone

clone(): LinkedList&lt;T&gt;

Clones an instance identical to this **LinkedList** and returns it. The modification to the copy does not affect the original instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| LinkedList&lt;T&gt; | New **LinkedList** instance obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The clone method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<number>();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.clone();
console.info("result:", result.has(4));  // result: true
```

### forEach

forEach(callbackFn: (value: T, index?: number, LinkedList?: LinkedList&lt;T&gt;) => void,
thisArg?: Object): void

Uses a callback to traverse the elements in this LinkedList and obtain their indexes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackFn | function | Yes| Callback invoked to traverse the elements in the LinkedList.|
| thisArg | Object | No| Value of **this** to use when **callbackFn** is invoked. The default value is this instance.|

callbackFn parameters

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value of the element that is currently traversed.|
| index | number | No| Position index of the element that is currently traversed. The default value is **0**.|
| LinkedList | LinkedList&lt;T&gt; | No| Instance that calls the **forEach** API. The default value is this instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The forEach method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<number>();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
linkedList.forEach((value: number, index: number) => {
  console.info("value:" + value, "index:" + index);
});
// value:2 index:0
// value:4 index:1
// value:5 index:2
// value:4 index:3
```

### clear

clear(): void

Clears this LinkedList and sets its length to **0**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The clear method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<number>();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
linkedList.clear();
let result = linkedList.has(2);
console.info("result:", result);  // result: false
```

### set

set(index: number, element: T): T

Replaces an element at the specified position in this LinkedList with a given element.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the target element. The value must be less than or equal to int32_max, that is, 2147483647.|
| element | T | Yes| Element to be used for replacement.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | New element. If the element is empty, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of index is out of range. |
| 10200011 | The set method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<number | string>();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.set(2, "b");
console.info("result:", result);  // result: b
```

### convertToArray

convertToArray(): Array&lt;T&gt;

Converts this LinkedList into an array and returns the array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| Array&lt;T&gt; | Array obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The convertToArray method cannot be bound. |

**Example**
```ts
let linkedList = new LinkedList<number>();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.convertToArray();
console.info("result:", result);  // result: 2,4,5,4
```

### getFirst

getFirst(): T

Obtains the first element in this LinkedList.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element obtained. If the element is empty, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getFirst method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<number>();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.getFirst();
console.info("result:", result);  // result: 2
```

### getLast

getLast(): T

Obtains the last element in this LinkedList.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element obtained. If the element is empty, **undefined** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getLast method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<number>();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);
let result = linkedList.getLast();
console.info("result:", result);  // result: 4
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

Returns an iterator, each item of which is a JavaScript object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;T&gt; | Iterator obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**Example**

```ts
let linkedList = new LinkedList<number>();
linkedList.add(2);
linkedList.add(4);
linkedList.add(5);
linkedList.add(4);

// Method 1:
for (let item of linkedList) {
  console.info("value:", item);
}
// value: 2
// value: 4
// value: 5
// value: 4

// Method 2:
let iter = linkedList[Symbol.iterator]();
let temp: IteratorResult<number> = iter.next();
while(!temp.done) {
  console.info("value:", temp.value);
  temp = iter.next();
}
// value: 2
// value: 4
// value: 5
// value: 4
```
