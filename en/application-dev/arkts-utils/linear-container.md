# Linear Containers


Linear containers, underpinned by arrays, implement a data structure that enables sequential access. There are several types of linear containers: **ArrayList**, **Vector**, **List**, **LinkedList**, **Deque**, **Queue**, and **Stack**.


To accelerate data access, linear containers support Create, Read, Update, and Delete (CRUD) through a bytecode instruction at runtime.


## ArrayList

[ArrayList](../reference/apis-arkts/js-apis-arraylist.md) is a dynamic array that can be used to construct a global array object. You are advised to use **ArrayList** when elements in a container need to be frequently read.

**ArrayList** uses generics and must be stored in a contiguous memory space. Its initial capacity is 10, and it increases capacity 1.5-fold in each dynamic expansion.

**ArrayList** provides the following CRUD APIs.

| Operation| Description|
| --------- | ------- |
| Create| Use **add(element: T)** to add an element at the end of this container.|
| Create| Use **insert(element: T, index: number)** to insert an element at a given position (specified by **index**).|
| Read| Use **arr\[index]** to obtain the value at a given position (specified by **index**).|
| Read| Use **forEach(callbackFn: (value: T, index?: number, arrlist?: ArrayList&lt;T&gt;) =&gt; void, thisArg?: Object): void** to traverse the elements in this container.|
| Read| Use **\[Symbol.iterator]():IterableIterator&lt;T&gt;** for data access.|
| Update| Use **arr\[index] = xxx** to change the value at a given position (specified by **index**).|
| Delete| Use **remove(element: T)** to remove the first occurrence of the specified element.|
| Delete| Use **removeByRange(fromIndex: number, toIndex: number)** to remove all of the elements within a range.|


## Vector

> **NOTE**
>
> The APIs provided by **Vector** are deprecated since API version 9. You are advised to use [ArrayList](../reference/apis-arkts/js-apis-arraylist.md).

[Vector](../reference/apis-arkts/js-apis-vector.md) is a continuous storage structure that can be used to construct a global array object. **Vector** uses generics and must be stored in a contiguous memory space. Its initial capacity is 10, and it has capacity doubled in each dynamic expansion.

Both **Vector** and [ArrayList](../reference/apis-arkts/js-apis-arraylist.md) are implemented based on arrays, but **Vector** provides more interfaces for operating the arrays. In addition to operator access, **Vector** provides the getter and setter to provide a more complete verification and error tolerance mechanism.

**Vector** provides the following CRUD APIs.

| Operation| Description|
| --------- | ------- |
| Create| Use **add(element: T)** to add an element at the end of this container.|
| Create| Use **insert(element: T, index: number)** to insert an element at a given position (specified by **index**).|
| Read| Use **vec\[index]** to obtain the value at a given position (specified by **index**).|
| Read| Use **get(index: number)** to obtain the element at a given position (specified by **index**).|
| Read| Use **getLastElement()** to obtain the last element in this container.|
| Read| Use **getIndexOf(element: T)** to obtain the index of the first occurrence of the specified element.|
| Read| Use **getLastIndexOf(element: T)** to obtain the index of the last occurrence of the specified element.|
| Read| Use **forEach(callbackFn: (value: T, index?: number, Vector?: Vector&lt;T&gt;) =&gt; void, thisArg?: Object)** to traverse the elements in this container.|
| Read| Use **\[Symbol.iterator]():IterableIterator&lt;T&gt;** for data access.|
| Update| Use **vec\[index]=xxx** to change the value at a given position (specified by **index**).|
| Update| Use **set(index: number, element: T)** to replace an element at a given position (specified by **index**) with a given element.|
| Update| Use **setLength(newSize: number)** to set the size of this container.|
| Delete| Use **removeByIndex(index: number)** to remove the value at a given position (specified by **index**).|
| Delete| Use **remove(element: T)** to remove the first occurrence of the specified element.|
| Delete| Use **removeByRange(fromIndex: number, toIndex: number)** to remove all of the elements within a range.|


## List

[List](../reference/apis-arkts/js-apis-list.md) can be used to construct a singly linked list, which supports access only through the head node to the tail node. **List** uses generics and can be stored in a non-contiguous memory space.

Unlike [LinkedList](../reference/apis-arkts/js-apis-linkedlist.md), which is a doubly linked list, **List** does not support insertion or removal at both ends.

You are advised to use **List** for frequent insertion and removal operations.

**List** provides the following CRUD APIs.

| Operation| Description|
| --------- | ------ |
| Create| Use **add(element: T)** to add an element at the end of this container.|
| Create| Use **insert(element: T, index: number)** to insert an element at a given position (specified by **index**).|
| Read| Use **list\[index]** to obtain the value at a given position (specified by **index**).|
| Read| Use **get(index: number)** to obtain the element at a given position (specified by **index**).|
| Read| Use **getFirst()** to obtain the first element in this container.|
| Read| Use **getLast()** to obtain the last element in this container.|
| Read| Use **getIndexOf(element: T)** to obtain the index of the first occurrence of the specified element.|
| Read| Use **getLastIndexOf(element: T)** to obtain the index of the last occurrence of the specified element.|
| Read| Use **forEach(callbackfn: (value: T, index?: number, list?: List&lt;T&gt;)=&gt; void, thisArg?: Object)** to traverse the elements in this container.|
| Read| Use **\[Symbol.iterator]():IterableIterator&lt;T&gt;** for data access.|
| Update| Use **list\[index] = xxx** to change the value at a given position (specified by **index**).|
| Update| Use **set(index: number, element: T)** to replace an element at a given position (specified by **index**) with a given element.|
| Update| Use **replaceAllElements(callbackFn:(value: T,index?: number,list?: List&lt;T&gt;)=&gt;T,thisArg?: Object)** to replace all elements in this container with new elements.|
| Delete| Use **removeByIndex(index: number)** to remove the value at a given position (specified by **index**).|
| Delete| Use **remove(element: T)** to remove the first occurrence of the specified element.|


## LinkedList

[LinkedList](../reference/apis-arkts/js-apis-linkedlist.md) can be used to construct a doubly linked list, which can be traversed at both ends. **LinkedList** uses generics and can be stored in a non-contiguous memory space.

Unlike [List](../reference/apis-arkts/js-apis-list.md), which is a singly linked list, **LinkedList** supports insertion and removal at both ends.

**LinkedList** is more efficient in data insertion than [ArrayList](../reference/apis-arkts/js-apis-arraylist.md), but less efficient in data access.

You are advised to use **LinkedList** for frequent insertion and removal operations.

**LinkedList** provides the following CRUD APIs.

| Operation| Description|
| ---------- | ------ |
| Create| Use **add(element: T)** to add an element at the end of this container.|
| Create| Use **insert(index: number, element: T)** to insert an element at a given position (specified by **index**).|
| Read| Use **list\[index]** to obtain the value at a given position (specified by **index**).|
| Read| Use **get(index: number)** to obtain the element at a given position (specified by **index**).|
| Read| Use **getFirst()** to obtain the first element in this container.|
| Read| Use **getLast()** to obtain the last element in this container.|
| Read| Use **getIndexOf(element: T)** to obtain the index of the first occurrence of the specified element.|
| Read| Use **getLastIndexOf(element: T)** to obtain the index of the last occurrence of the specified element.|
| Read| Use **forEach(callbackFn: (value: T, index?: number, list?: LinkedList&lt;T&gt;) =&gt; void, thisArg?: Object)** to traverse the elements in this container.|
| Read| Use **\[Symbol.iterator]():IterableIterator&lt;T&gt;** for data access.|
| Update| Use **list\[index]=xxx** to change the value at a given position (specified by **index**).|
| Update| Use **set(index: number, element: T)** to replace an element at a given position (specified by **index**) with a given element.|
| Delete| Use **removeByIndex(index: number)** to remove the value at a given position (specified by **index**).|
| Delete| Use **remove(element: T)** to remove the first occurrence of the specified element.|


## Deque

[Deque](../reference/apis-arkts/js-apis-deque.md) can be used to construct a double-ended queue (deque) that follows the principles of First In First Out (FIFO) and Last In First Out (LIFO). It allows insertion and removal of elements at both ends.

**Deque** uses generics and must be stored in a contiguous memory space. Its initial capacity is 8, and it has capacity doubled in each dynamic expansion. The bottom layer of **Deque** is implemented by cyclic queues, delivering a high efficiency in enqueuing and dequeuing.

Different from **Deque**, [Queue](../reference/apis-arkts/js-apis-queue.md) follows the principle of FIFO only and allows element removal at the front and insertion at the rear.

Unlike [Vector](../reference/apis-arkts/js-apis-vector.md), **Deque** does not support insertion and deletion of elements in between. When compared with **Vector**, **Deque** is more efficient in inserting and removing header elements, but less efficient in accessing elements.

You are advised to use **Deque** when you need to frequently insert or remove elements at both the ends of a container.

**Deque** provides the following CRUD APIs.

| Operation| Description|
| ---------- | ------ |
| Create| Use **insertFront(element: T)** to insert an element at the front of this container.|
| Create| Use **insertEnd(element: T)** to insert an element at the end of this container.|
| Read| Use **getFirst()** to obtain the value of the first element in this container, without removing it from the container.|
| Read| Use **getLast()** to obtain the value of the last element in this container, without removing it from the container.|
| Read| Use **popFirst()** to obtain the value of the first element in this container and remove it from the container.|
| Read| Use **popLast()** to obtain the value of the last element in this container and remove it from the container.|
| Read| Use **forEach(callbackFn:(value: T, index?: number, deque?: Deque&lt;T&gt;) =&gt; void, thisArg?: Object)** to traverse the elements in this container.|
| Read| Use **\[Symbol.iterator]():IterableIterator&lt;T&gt;** for data access.|
| Update| Use **forEach(callbackFn:(value: T, index?: number, deque?: Deque&lt;T&gt;)=&gt; void, thisArg?: Object)** to modify an element in this container.|
| Delete| Use **popFirst()** to remove the first element from this container.|
| Delete| Use **popLast()** to remove the last element from this container.|


## Queue

[Queue](../reference/apis-arkts/js-apis-queue.md) can be used to construct a queue that follows the FIFO principle.

**Queue** uses generics and must be stored in a contiguous memory space. Its initial capacity is 8, and it has capacity doubled in each dynamic expansion.

The bottom layer of **Queue** is implemented by cyclic queues, delivering a high efficiency in enqueuing and dequeuing.

Unlike [Deque](../reference/apis-arkts/js-apis-deque.md), which supports insertion and removal at both the ends, **Queue** supports insertion at one end and removal at the other.

You are advised to use **Queue** in FIFO scenarios.

**Queue** provides the following CRUD APIs.

| Operation| Description|
| ---------- | ------ |
| Create| Use **add(element: T)** to add an element at the end of this container.|
| Read| Use **getFirst()** to obtain the value of the first element in this container, without removing it from the container.|
| Read| Use **pop()** to obtain the value of the first element in this container and remove it from the container.|
| Read| Use **forEach(callbackFn: (value: T, index?: number, queue?: Queue&lt;T&gt;) =&gt; void,thisArg?: Object)** to traverse the elements in this container.|
| Read| Use **\[Symbol.iterator]():IterableIterator&lt;T&gt;** for data access.|
| Update| Use **forEach(callbackFn:(value: T, index?: number, queue?: Queue&lt;T&gt;) =&gt; void,thisArg?: Object)** to modify an element in this container.|
| Delete| Use **pop()** to remove the first element from this container.|


## Stack

[Stack](../reference/apis-arkts/js-apis-stack.md) can be used to construct a stack that follows the Last Out First In (LOFI) principle.

**Stack** uses generics and must be stored in a contiguous memory space. Its initial capacity is 8, and it increases capacity 1.5-fold in each dynamic expansion. The bottom layer of **Stack** is implemented based on arrays. It supports data insertion and removal at one end.

Unlike [Queue](../reference/apis-arkts/js-apis-queue.md), which supports insertion at one end and removal at the other, **Stack** supports insertion and removal at the same end.

You are advised to use **Stack** in LOFI scenarios.

**Stack** provides the following CRUD APIs.

| Operation| Description|
| ---------- | ------ |
| Create| Use **push(item: T)** to add an element at the top of this container.|
| Read| Use **peek()** to obtain the value of the top element in this container, without removing it from the container.|
| Read| Use **pop()** to obtain the value of the top element in this container and remove it from the container.|
| Read| Use **forEach(callbackFn: (value: T, index?: number, stack?: Stack&lt;T&gt;) =&gt; void, thisArg?: Object)** to traverse the elements in this container.|
| Read| Use **\[Symbol.iterator]():IterableIterator&lt;T&gt;** for data access.|
| Read| Use **locate(element: T)** to obtain the index of the first occurrence of the specified element.|
| Update| Use **forEach(callbackFn:(value: T, index?: number, stack?: Stack&lt;T&gt;) =&gt; void, thisArg?: Object)** to modify an element in this container.|
| Delete| Use **pop()** to remove the top element from this container.|


## Use of Linear Containers

Refer to the code snippet below to add, access, and modify elements in **ArrayList**, **Deque**, **Stack**, and **List**.  


```ts
// ArrayList
import { ArrayList } from '@kit.ArkTS'; // Import the ArrayList module.

let arrayList1: ArrayList<string> = new ArrayList();
arrayList1.add('a');
let arrayList2: ArrayList<number> = new ArrayList();
arrayList2.add(1); // Add an element.
console.info(`result: ${arrayList2[0]}`); // Access an element.
arrayList1[0] = 'one'; // Modify an element.
console.info(`result: ${arrayList1[0]}`);

// Deque
import { Deque } from '@kit.ArkTS'; // Import the Deque module.

let deque1: Deque<string> = new Deque();
deque1.insertFront('a');
let deque2: Deque<number> = new Deque();
deque2.insertFront(1); // Add an element.
console.info(`result: ${deque1[0]}`); // Access an element.
deque1[0] = 'one'; // Modify an element.
console.info(`result: ${deque2[0]}`);

// Stack
import { Stack } from '@kit.ArkTS'; // Import the Stack module.

let stack1: Stack<string> = new Stack();
stack1.push('a');
let stack2: Stack<number> = new Stack();
stack2.push(1); // Add an element.
console.info(`result: ${stack1[0]}`); // Access an element.
stack2.pop(); // Remove the top element from this container.
console.info(`result: ${stack2.length}`);

// List
import { List } from '@kit.ArkTS'; // Import the List module.

let list1: List<string> = new List();
list1.add('a');
let list2: List<number> = new List();
list2.add(1);
let list3: List<Array<number>> = new List();
let b2 = [1, 2, 3];
list3.add(b2); // Add an element.
console.info(`result: ${list1[0]}`); // Access an element.
console.info(`result: ${list3.get(0)}`); // Access an element.
```
