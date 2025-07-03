# @ohos.util.List (Linear Container List)

List is implemented based on the singly linked list. Each node has a reference pointing to the next element. Elements must be traversed from the beginning, making querying inefficient. However, insertion and deletion operations are highly efficient. List allows null elements.

Unlike [LinkedList](js-apis-linkedlist.md), which is a doubly linked list, List is a singly linked list that does not support insertion or removal at both ends.

> **NOTE**
>
> Accessing elements in a List using the \[index\] syntax may lead to undefined results. You are advised to use **get()** instead.

**Recommended use case**: Use List for frequent insertion and removal operations when a singly linked list is required.

This topic uses the following to identify the use of generics:
- T: Type

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { List } from '@kit.ArkTS';
```


## List

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a List.|


### constructor

constructor()

A constructor used to create a **List** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200012 | The List's constructor cannot be directly invoked. |

**Example**

```ts
let list: List<string | number | boolean | object> = new List();
```


### add

add(element: T): boolean

Adds an element at the end of this List.

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
let list: List<string | number | boolean | object> = new List();
let result1 = list.add("a");
let result2 = list.add(1);
let b = [1, 2, 3];
let result3 = list.add(b);
class C {
  name: string = ''
  age: string = ''
}
let c: C = {name : "Dylan", age : "13"};
let result4 = list.add(c);
let result5 = list.add(false);
```

### insert

insert(element: T, index: number): void

Inserts an element at the specified position in this List.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|
| index | number | Yes| Index of the position where the element is to be inserted. The value must be less than or equal to int32_max, that is, 2147483647.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of index is out of range. |
| 10200011 | The insert method cannot be bound. |

**Example**

```ts
let list: List<string | number | boolean> = new List();
list.insert("A", 0);
list.insert(0, 1);
list.insert(true, 2);
```

### has

has(element: T): boolean

Checks whether this List has the specified element.

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
let list: List<string> = new List();
list.add("squirrel");
let result = list.has("squirrel");
```

### get

get(index: number): T

Obtains the element at the specified position in this List.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Position index of the target element. The value must be less than or equal to int32_max, that is, 2147483647.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The get method cannot be bound. |

**Example**

```ts
let list: List<number> = new List();
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

Obtains the index of the last occurrence of the specified element in this List.

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
let list: List<number> = new List();
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

Obtains the index of the first occurrence of the specified element in this List.

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
let list: List<number> = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(2);
list.add(1);
list.add(2);
list.add(4);
let result = list.getIndexOf(2);
```

### equal

equal(obj: Object): boolean

Compares whether a specified object is equal to this List.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| obj | Object | Yes| Object used for comparison.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** is returned if the two are equal; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The equal method cannot be bound. |

**Example**

```ts
let list: List<number> = new List();
list.add(2);
list.add(4);
list.add(5);
let obj: List<number> = new List();
obj.add(2);
obj.add(4);
obj.add(5);
let result = list.equal(obj);
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
| T | Element removed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of index is out of range. |
| 10200011 | The removeByIndex method cannot be bound. |

**Example**

```ts
let list: List<number> = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(2);
list.add(4);
let result = list.removeByIndex(2);
```

### remove

remove(element: T): boolean

Removes the first occurrence of the specified element from this List.

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
let list: List<number> = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.remove(2);
```

### replaceAllElements

replaceAllElements(callbackFn: (value: T, index?: number, list?: List&lt;T&gt;) => T,
thisArg?: Object): void

Replaces all elements in this List with new elements, and returns the new ones.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackFn | function | Yes| Callback invoked for the replacement.|
| thisArg | Object | No| Value of **this** to use when **callbackFn** is invoked. The default value is this instance.|

callbackFn parameters

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value of the element that is currently traversed.|
| index | number | No| Position index of the element that is currently traversed. The default value is **0**.|
| list | List&lt;T&gt; | No| Instance that calls the **replaceAllElements** API. The default value is this instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The replaceAllElements method cannot be bound. |

**Example**

```ts
let list: List<number> = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
list.replaceAllElements((value: number) => {
  // Add the user operation logic based on the actual scenario.
  return value;
});
```

### forEach

forEach(callbackFn: (value: T, index?: number, List?: List&lt;T&gt;) => void,
thisArg?: Object): void

Uses a callback to traverse the elements in this List and obtain their indexes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackFn | function | Yes| Callback invoked for the replacement.|
| thisArg | Object | No| Value of **this** to use when **callbackFn** is invoked. The default value is this instance.|

callbackFn parameters

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Value of the element that is currently traversed.|
| index | number | No| Position index of the element that is currently traversed. The default value is **0**.|
| List | List&lt;T&gt; | No| Instance that calls the **forEach** API. The default value is this instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The forEach method cannot be bound. |

**Example**

```ts
let list: List<number> = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
list.forEach((value: number, index?: number) => {
  console.log("value:" + value, "index:" + index);
});
```

### sort

sort(comparator: (firstValue: T, secondValue: T) => number): void

Sorts elements in this List.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| comparator | function | Yes| Callback invoked for sorting.|

comparator

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| firstValue | T | Yes| Previous element.|
| secondValue | T | Yes| Next element.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The sort method cannot be bound. |

**Example**

```ts
let list: List<number> = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
list.sort((a: number, b: number) => a - b); // The elements are sorted in ascending order.
list.sort((a: number, b: number) => b - a); // The elements are sorted in descending order.
```

### getSubList

getSubList(fromIndex: number, toIndex: number): List&lt;T&gt;

Obtains elements within a range in this List, including the element at the start position but not that at the end position, and returns these elements as a new **List** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fromIndex | number | Yes| Index of the start position.|
| toIndex | number | Yes| Index of the end position.|

**Return value**

| Type| Description|
| -------- | -------- |
| List&lt;T&gt; | New **List** instance obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range. |
| 10200011 | The getSubList method cannot be bound. |

**Example**

```ts
let list: List<number> = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.getSubList(1, 3);
```

### clear

clear(): void

Clears this List and sets its length to **0**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The clear method cannot be bound. |

**Example**

```ts
let list: List<number> = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
list.clear();
```

### set

set(index: number, element: T): T

Replaces an element at the specified position in this List with a given element.

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
| T | New element.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of index is out of range. |
| 10200011 | The set method cannot be bound. |

**Example**

```ts
let list: List<number | string> = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.set(2, "b");
```

### convertToArray

convertToArray(): Array&lt;T&gt;

Converts this List into an array and returns the array.

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
let list: List<number> = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.convertToArray();
```

### isEmpty

isEmpty(): boolean

Checks whether this List is empty (contains no element).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Check result. The value **true** is returned if the List is empty; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The isEmpty method cannot be bound. |

**Example**

```ts
let list: List<number> = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.isEmpty();
```

### getFirst

getFirst(): T

Obtains the first element in this List.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | The first element obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getFirst method cannot be bound. |

**Example**

```ts
let list: List<number> = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.getFirst();
```

### getLast

getLast(): T

Obtains the last element in this List.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | The last element obtained.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200011 | The getLast method cannot be bound. |

**Example**

```ts
let list: List<number> = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.getLast();
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
let list: List<number> = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);

// Method 1:
let items = Array.from(list);
for (let item of items) {
  console.log("value: " + item);
}

// Method 2:
let iter = list[Symbol.iterator]();
let temp: IteratorResult<number> = iter.next();
while(!temp.done) {
  console.log("value: " + temp.value);
  temp = iter.next();
}
```
