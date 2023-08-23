# Linear Containers


Linear containers implement a data structure that enables sequential access. The bottom layer of linear containers is implemented through arrays. OpenHarmony provides the following linear containers: **ArrayList**, **Vector**, **List**, **LinkedList**, **Deque**, **Queue**, and **Stack**.


Fully considering the data access speed, linear containers support Create, Read, Update, and Delete (CRUD) through a bytecode instruction at runtime.


## ArrayList

[ArrayList](../reference/apis/js-apis-arraylist.md) is a dynamic array that can be used to construct a global array object. You are advised to use **ArrayList** when elements in a container need to be frequently read.

**ArrayList** uses generics and must be stored in a contiguous memory space. Its initial capacity is 10, and it increases capacity 1.5-fold in each dynamic expansion.

**ArrayList** provides the following CRUD APIs.

| Operation| Description|
| --------- | ------- |
| Adding elements| Use **add(element: T)** to add an element at the end of this container.|
| Adding elements| Use **insert(element: T, index: number)** to insert an element at a given position (specified by **index**).|
| Accessing elements| Use **arr\[index]** to obtain the value at a given position (specified by **index**).|
| Accessing elements| Use **forEach(callbackFn: (value: T, index?: number, arrlist?: ArrayList&lt;T&gt;) =&gt; void, thisArg?: Object): void** to traverse the elements in this container.|
| Accessing elements| Use **\[Symbol.iterator]():IterableIterator&lt;T&gt;** for data access.|
| Modifying elements| Use **arr\[index] = xxx** to change the value at a given position (specified by **index**).|
| Deleting elements| Use **remove(element: T)** to remove the first occurrence of the specified element.|
| Deleting elements| Use **removeByRange(fromIndex: number, toIndex: number)** to remove all of the elements within a range.|


## Vector

[Vector](../reference/apis/js-apis-vector.md) is a continuous storage structure that can be used to construct a global array object. **Vector** uses generics and must be stored in a contiguous memory space. Its initial capacity is 10, and it has capacity doubled in each dynamic expansion.

Both **Vector** and [ArrayList](../reference/apis/js-apis-arraylist.md) are implemented based on arrays, but **Vector** provides more interfaces for operating the arrays. In addition to operator access, **Vector** provides the getter and setter to provide a more complete verification and error tolerance mechanism.

The APIs provided by **Vector** are deprecated since API version 9. You are advised to use [ArrayList](../reference/apis/js-apis-arraylist.md).

**Vector** provides the following CRUD APIs.

| Operation| Description|
| --------- | ------- |
| Adding elements| Use **add(element: T)** to add an element at the end of this container.|
| Adding elements| Use **insert(element: T, index: number)** to insert an element at a given position (specified by **index**).|
| Accessing elements| Use **vec\[index]** to obtain the value at a given position (specified by **index**).|
| Accessing elements| Use **get(index: number)** to obtain the element at a given position (specified by **index**).|
| Accessing elements| Use **getLastElement()** to obtain the last element in this container.|
| Accessing elements| Use **getIndexOf(element: T)** to obtain the index of the first occurrence of the specified element.|
| Accessing elements| Use **getLastIndexOf(element: T)** to obtain the index of the last occurrence of the specified element.|
| Accessing elements| Use **forEach(callbackFn: (value: T, index?: number, Vector?: Vector&lt;T&gt;) =&gt; void, thisArg?: Object)** to traverse the elements in this container.|
| Accessing elements| Use **\[Symbol.iterator]():IterableIterator&lt;T&gt;** for data access.|
| Modifying elements| Use **vec\[index]=xxx** to change the value at a given position (specified by **index**).|
| Modifying elements| Use **set(index: number, element: T)** to replace an element at a given position (specified by **index**) with a given element.|
| Modifying elements| Use **setLength(newSize: number)** to set the size of this container.|
| Deleting elements| Use **removeByIndex(index: number)** to remove the value at a given position (specified by **index**).|
| Deleting elements| Use **remove(element: T)** to remove the first occurrence of the specified element.|
| Deleting elements| Use **removeByRange(fromIndex: number, toIndex: number)** to remove all of the elements within a range.|


## List

[List](../reference/apis/js-apis-list.md) can be used to construct a singly linked list, which supports access only through the head node to the tail node. **List** uses generics and can be stored in a non-contiguous memory space.

Unlike [LinkedList](../reference/apis/js-apis-linkedlist.md), which is a doubly linked list, **List** is a singly linked list that does not support insertion or removal at both ends.

You are advised to use **List** for frequent insertion and removal operations.

**List** provides the following CRUD APIs.

| Operation| Description|
| --------- | ------ |
| Adding elements| Use **add(element: T)** to add an element at the end of this container.|
| Adding elements| Use **insert(element: T, index: number)** to insert an element at a given position (specified by **index**).|
| Accessing elements| Use **list\[index]** to obtain the value at a given position (specified by **index**).|
| Accessing elements| Use **get(index: number)** to obtain the element at a given position (specified by **index**).|
| Accessing elements| Use **getFirst()** to obtain the first element in this container.|
| Accessing elements| Use **getLast()** to obtain the last element in this container.|
| Accessing elements| Use **getIndexOf(element: T)** to obtain the index of the first occurrence of the specified element.|
| Accessing elements| Use **getLastIndexOf(element: T)** to obtain the index of the last occurrence of the specified element.|
| Accessing elements| Use **forEach(callbackfn: (value: T, index?: number, list?: List&lt;T&gt;)=&gt; void, thisArg?: Object)** to traverse the elements in this container.|
| Accessing elements| Use **\[Symbol.iterator]():IterableIterator&lt;T&gt;** for data access.|
| Modifying elements| Use **list\[index] = xxx** to change the value at a given position (specified by **index**).|
| Modifying elements| Use **set(index: number, element: T)** to replace an element at a given position (specified by **index**) with a given element.|
| Modifying elements| Use **replaceAllElements(callbackFn:(value: T,index?: number,list?: List&lt;T&gt;)=&gt;T,thisArg?: Object)** to replace all elements in this container with new elements.|
| Deleting elements| Use **removeByIndex(index: number)** to remove the value at a given position (specified by **index**).|
| Deleting elements| Use **remove(element: T)** to remove the first occurrence of the specified element.|


## LinkedList

[LinkedList](../reference/apis/js-apis-linkedlist.md) can be used to construct a doubly linked list, which can be traversed at both ends. **LinkedList** uses generics and can be stored in a non-contiguous memory space.

Unlike [List](../reference/apis/js-apis-list.md), which is a singly linked list, **LinkedList** is a doubly linked list that supports insertion and removal at both ends.

**LinkedList** is more efficient in data insertion than [ArrayList](../reference/apis/js-apis-arraylist.md), but less efficient in data access.

You are advised to use **LinkedList** for frequent insertion and removal operations.

**LinkedList** provides the following CRUD APIs.

| Operation| Description|
| ---------- | ------ |
| Adding elements| Use **add(element: T)** to add an element at the end of this container.|
| Adding elements| Use **insert(index: number, element: T)** to insert an element at a given position (specified by **index**).|
| Accessing elements| Use **list\[index]** to obtain the value at a given position (specified by **index**).|
| Accessing elements| Use **get(index: number)** to obtain the element at a given position (specified by **index**).|
| Accessing elements| Use **getFirst()** to obtain the first element in this container.|
| Accessing elements| Use **getLast()** to obtain the last element in this container.|
| Accessing elements| Use **getIndexOf(element: T)** to obtain the index of the first occurrence of the specified element.|
| Accessing elements| Use **getLastIndexOf(element: T)** to obtain the index of the last occurrence of the specified element.|
| Accessing elements| Use **forEach(callbackFn: (value: T, index?: number, list?: LinkedList&lt;T&gt;) =&gt; void, thisArg?: Object)** to traverse the elements in this container.|
| Accessing elements| Use **\[Symbol.iterator]():IterableIterator&lt;T&gt;** for data access.|
| Modifying elements| Use **list\[index]=xxx** to change the value at a given position (specified by **index**).|
| Modifying elements| Use **set(index: number, element: T)** to replace an element at a given position (specified by **index**) with a given element.|
| Deleting elements| Use **removeByIndex(index: number)** to remove the value at a given position (specified by **index**).|
| Deleting elements| Use **remove(element: T)** to remove the first occurrence of the specified element.|


## Deque

[Deque](../reference/apis/js-apis-deque.md) can be used to construct a double-ended queue (deque) that follows the principles of First In First Out (FIFO) and Last In First Out (LIFO). It allows insertion and removal of elements at both the ends.

**Deque** uses generics and must be stored in a contiguous memory space. Its initial capacity is 8, and it has capacity doubled in each dynamic expansion. The bottom layer of **Deque** is implemented by cyclic queues, delivering a high efficiency in enqueuing and dequeuing.

[Queue](../reference/apis/js-apis-queue.md) follows the principle of FIFO only and allows element removal at the front and insertion at the rear.

[Vector](../reference/apis/js-apis-vector.md) supports insertion and deletion of elements in between, as well as at both the ends. When compared with **Vector**, **Deque** is more efficient in inserting and removing header elements, but less efficient in accessing elements.

You are advised to use **Deque** when you need to frequently insert or remove elements at both the ends of a container.

**Deque** provides the following CRUD APIs.

| Operation| Description|
| ---------- | ------ |
| Adding elements| Use **insertFront(element: T)** to insert an element at the front of this container.|
| Adding elements| Use **insertEnd(element: T)** to insert an element at the end of this container.|
| Accessing elements| Use **getFirst()** to obtain the value of the first element in this container, without removing it from the container.|
| Accessing elements| Use **getLast()** to obtain the value of the last element in this container, without removing it from the container.|
| Accessing elements| Use **popFirst()** to obtain the value of the first element in this container and remove it from the container.|
| Accessing elements| Use **popLast()** to obtain the value of the last element in this container and remove it from the container.|
| Accessing elements| Use **forEach(callbackFn:(value: T, index?: number, deque?: Deque&lt;T&gt;) =&gt; void, thisArg?: Object)** to traverse the elements in this container.|
| Accessing elements| Use **\[Symbol.iterator]():IterableIterator&lt;T&gt;** for data access.|
| Modifying elements| Use **forEach(callbackFn:(value: T, index?: number, deque?: Deque&lt;T&gt;)=&gt; void, thisArg?: Object)** to modify an element in this container.|
| Deleting elements| Use **popFirst()** to remove the first element from this container.|
| Deleting elements| Use **popLast()** to remove the last element from this container.|


## Queue

[Queue](../reference/apis/js-apis-queue.md) can be used to construct a queue that follows the FIFO principle.

**Queue** uses generics and must be stored in a contiguous memory space. Its initial capacity is 8, and it has capacity doubled in each dynamic expansion.

The bottom layer of **Queue** is implemented by cyclic queues, delivering a high efficiency in enqueuing and dequeuing.

Unlike [Deque](../reference/apis/js-apis-deque.md), which supports insertion and removal at both the ends, **Queue** supports insertion at one end and removal at the other end.

You are advised to use **Queue** in FIFO scenarios.

**Queue** provides the following CRUD APIs.

| Operation| Description|
| ---------- | ------ |
| Adding elements| Use **add(element: T)** to add an element at the end of this container.|
| Accessing elements| Use **getFirst()** to obtain the value of the first element in this container, without removing it from the container.|
| Accessing elements| Use **pop()** to obtain the value of the first element in this container and remove it from the container.|
| Accessing elements| Use **forEach(callbackFn: (value: T, index?: number, queue?: Queue&lt;T&gt;) =&gt; void,thisArg?: Object)** to traverse the elements in this container.|
| Accessing elements| Use **\[Symbol.iterator]():IterableIterator&lt;T&gt;** for data access.|
| Modifying elements| Use **forEach(callbackFn:(value: T, index?: number, queue?: Queue&lt;T&gt;) =&gt; void,thisArg?: Object)** to modify an element in this container.|
| Deleting elements| Use **pop()** to remove the first element from this container.|


## Stack

[Stack](../reference/apis/js-apis-stack.md) can be used to construct a stack that follows the Last Out First In (LOFI) principle.

**Stack** uses generics and must be stored in a contiguous memory space. Its initial capacity is 8, and it increases capacity 1.5-fold in each dynamic expansion. The bottom layer of **Stack** is implemented based on arrays. It supports data insertion and removal at one end.

Unlike [Queue](../reference/apis/js-apis-queue.md), which is implemented based on the queue data structure and supports insertion at one end and removal at the other end, **Stack** supports insertion and removal at the same end.

You are advised to use **Stack** in LOFI scenarios.

**Stack** provides the following CRUD APIs.

| Operation| Description|
| ---------- | ------ |
| Adding elements| Use **push(item: T)** to add an element at the top of this container.|
| Accessing elements| Use **peek()** to obtain the value of the top element in this container, without removing it from the container.|
| Accessing elements| Use **pop()** to obtain the value of the top element in this container and remove it from the container.|
| Accessing elements| Use **forEach(callbackFn: (value: T, index?: number, stack?: Stack&lt;T&gt;) =&gt; void, thisArg?: Object)** to traverse the elements in this container.|
| Accessing elements| Use **\[Symbol.iterator]():IterableIterator&lt;T&gt;** for data access.|
| Accessing elements| Use **locate(element: T)** to obtain the index of the first occurrence of the specified element.|
| Modifying elements| Use **forEach(callbackFn:(value: T, index?: number, stack?: Stack&lt;T&gt;) =&gt; void, thisArg?: Object)** to modify an element in this container.|
| Deleting elements| Use **pop()** to remove the top element from this container.|


## Use of Linear Containers

Refer to the code snippet below to add, access, and modify elements in **ArrayList**, **Vector**, **Deque**, **Stack**, and **List**.  


```js
// ArrayList
import ArrayList from '@ohos.util.ArrayList'; // Import the ArrayList module.

let arrayList = new ArrayList();
arrayList.add('a');
arrayList.add(1); // Add an element.
console.info(`result: ${arrayList[0]}`); // Access an element.
arrayList[0] = 'one'; // Modify an element.
console.info(`result: ${arrayList[0]}`);

// Vector
import Vector from '@ohos.util.Vector'; // Import the Vector module.

let vector = new Vector();
vector.add('a');
let b1 = [1, 2, 3];
vector.add(b1);
vector.add(false); // Add an element.
console.info(`result: ${vector[0]}`); // Access an element.
console.info(`result: ${vector.getFirstElement()}`); // Access an element.

// Deque
import Deque from '@ohos.util.Deque'; // Import the Deque module.

let deque = new Deque;
deque.insertFront('a');
deque.insertFront(1); // Add an element.
console.info(`result: ${deque[0]}`); // Access an element.
deque[0] = 'one'; // Modify an element.
console.info(`result: ${deque[0]}`);

// Stack
import Stack from '@ohos.util.Stack'; // Import the Stack module.

let stack = new Stack();
stack.push('a');
stack.push(1); // Add an element.
console.info(`result: ${stack[0]}`); // Access an element.
stack.pop(); // Remove an element.
console.info(`result: ${stack.length}`);

// List
import List from '@ohos.util.List'; // Import the List module.

let list = new List;
list.add('a');
list.add(1);
let b2 = [1, 2, 3];
list.add(b2); // Add an element.
console.info(`result: ${list[0]}`); // Access an element.
console.info(`result: ${list.get(0)}`); // Access an element.
```
