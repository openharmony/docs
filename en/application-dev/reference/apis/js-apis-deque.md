# Linear Container Deque

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

Double-ended queue (deque) is a sequence container implemented based on the queue data structure that follows the principles of First In First Out (FIFO) and Last In First Out (LIFO). It allows insertion and removal of elements at both the ends. **Deque** can dynamically adjust the capacity based on project requirements. It doubles the capacity each time. **Deque** differs from **[Queue](js-apis-queue.md)** and **[Vector](js-apis-vector.md)** mainly in the following aspects:

**Queue** follows the principle of FIFO only and allows element removal at the front and insertion at the rear.

**Vector** supports insertion and deletion of elements in between, as well as at both the ends. When compared with **Vector**, **Deque** is more efficient in inserting and removing header elements, but less efficient in accessing elements.

**Recommended use case**: Use **Deque** when you need to frequently insert or remove elements at both the ends of a container.

This topic uses the following to identify the use of generics:
- T: Type

## Modules to Import

```ts
import Deque from '@ohos.util.Deque'; 
```

## Deque

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| length | number | Yes| No| Number of elements in a deque (called container later).|

### constructor

constructor()

A constructor used to create a **Deque** instance.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let deque = new Deque();
```

### insertFront

insertFront(element: T): void

Inserts an element at the front of this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|

**Example**

```ts
let deque = new Deque();
deque.insertFront("a");
deque.insertFront(1);
let b = [1, 2, 3];
deque.insertFront(b);
let c = {name : "Dylon", age : "13"};
deque.insertFront(false);
```

### insertEnd

insertEnd(element: T): void

Inserts an element at the end of this container.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| element | T | Yes| Target element.|

**Example**

```ts
let deque = new Deque();
deque.insertEnd("a");
deque.insertEnd(1);
let b = [1, 2, 3];
deque.insertEnd(b);
let c = {name : "Dylon", age : "13"};
deque.insertEnd(false);
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
let deque = new Deque();
let result = deque.has("squirrel");
deque.insertFront("squirrel");
let result1 = deque.has("squirrel");
```

### popFirst

popFirst(): T

Removes the first element of this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element removed.|

**Example**

```ts
let deque = new Deque();
deque.insertFront(2);
deque.insertFront(4);
deque.insertEnd(5);
deque.insertFront(2);
deque.insertFront(4);
let result = deque.popFirst();
```

### popLast

popLast(): T

Removes the last element of this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element removed.|

**Example**

```ts
let deque = new Deque();
deque.insertFront(2);
deque.insertEnd(4);
deque.insertFront(5);
deque.insertFront(2);
deque.insertFront(4);
let result = deque.popLast();
```

### forEach

forEach(callbackfn: (value: T, index?: number, deque?: Deque&lt;T&gt;) => void,
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
| deque | Deque&lt;T&gt; | No| Instance that invokes the **forEach** method.|

**Example**

```ts
let deque = new Deque();
deque.insertFront(2);
deque.insertEnd(4);
deque.insertFront(5);
deque.insertEnd(4);
deque.forEach((value, index) => {
  console.log("value:" + value, index);
});
```

### getFirst

getFirst(): T

Obtains the first element of this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element obtained.|

**Example**

```ts
let deque = new Deque();
deque.insertEnd(2);
deque.insertEnd(4);
deque.insertFront(5);
deque.insertFront(4);
let result = deque.getFirst();
```

### getLast

getLast(): T

Obtains the last element of this container.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| T | Element obtained.|

**Example**

```ts
let deque = new Deque();
deque.insertFront(2);
deque.insertFront(4);
deque.insertFront(5);
deque.insertFront(4);
let result = deque.getLast();
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
let deque = new Deque();
deque.insertFront(2);
deque.insertFront(4);
deque.insertFront(5);
deque.insertFront(4);

// Method 1:
for (let item of deque) { 
  console.log("value:" + item); 
}

// Method 2:
let iter = deque[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
```
