# Linear Containers


Linear containers, underpinned by arrays, implement a data structure that enables sequential access. There are several types of linear containers: **ArrayList**, **Vector**, **List**, **LinkedList**, **Deque**, **Queue**, and **Stack**.


To accelerate data access, linear containers support Create, Read, Update, and Delete (CRUD) through a bytecode instruction at runtime.

## Comparison of linear container types

| Class| Characteristics and Recommended Application Scenarios|
| --------- | ------- |
| ArrayList | Dynamic array, which occupies a continuous memory space. This method is recommended when elements need to be frequently read.|
| List | Unidirectional linked list. The occupied space can be discontinuous. This mode is recommended when elements need to be frequently inserted and deleted and a unidirectional linked list is required.|
| LinkedList | A doubly linked list. The occupied space can be discontinuous. It is recommended when elements need to be frequently inserted and deleted and a doubly linked list is required.|
| Deque | Dual-ended queue. Elements can be entered and exited from the head and tail of a container, occupying a continuous memory space. It is recommended when the head and tail elements need to be frequently accessed and operated.|
| Queue | A queue is used to insert elements from the tail of a container and pop elements from the header of the container, occupying a continuous memory space. You are advised to use **Queue** in FIFO scenarios.|
| Stack | A stack can be inserted or deleted only from one end of a container, occupying a continuous memory space. You are advised to use **Stack** in LOFI scenarios.|
| Vector | Dynamic array, which occupies a continuous memory space. This type is no longer maintained. You are advised to use ArrayList.|

## ArrayList

[ArrayList](../reference/apis-arkts/js-apis-arraylist.md) is a dynamic array that can be used to construct a global array object. You are advised to use **ArrayList** when elements in a container need to be frequently read.

**ArrayList** uses generics and must be stored in a contiguous memory space. Its initial capacity is 10, and it increases capacity 1.5-fold in each dynamic expansion.

**ArrayList** provides the following CRUD APIs.

| Operation| API| Description|
| --------- | ------- | ------- |
| Create| add(element: T) | // Add an item to the end of the data.|
| Create| insert(element: T, index: number) |  * Inserts a value to a specified index.|
| Read| arr\[index: number] | Obtains the value corresponding to a specified index. The value is obtained by running commands to ensure the access speed.|
| Read| forEach(callbackFn: (value: T, index?: number, arrlist?: ArrayList&lt;T&gt;) =&gt; void, thisArg?: Object) | Accesses the elements of the entire ArrayList container.|
| Read| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Update| arr\[index] = xxx | Modifies the value corresponding to a specified index.|
| Delete| remove(element: T) | Deletes the first matched element.|
| Delete| removeByRange(fromIndex: number, toIndex:number) | Removes elements in a specified range from this container.|

## List

[List](../reference/apis-arkts/js-apis-list.md) can be used to construct a singly linked list, which supports access only through the head node to the tail node. **List** uses generics and can be stored in a non-contiguous memory space.

Unlike [LinkedList](../reference/apis-arkts/js-apis-linkedlist.md), which is a doubly linked list, **List** does not support insertion or removal at both ends.

If elements need to be frequently inserted and deleted and a unidirectional linked list is required, you are advised to use List to perform efficient operations.

**List** provides the following CRUD APIs.

| Operation| API| Description|
| --------- | ------- | ------- |
| Create| add(element: T) | // Add an item to the end of the data.|
| Create| insert(element: T, index: number) |  * Inserts a value to a specified index.|
| Read| get(index: number) | Obtains the element corresponding to the specified index.|
| Read| list\[index: number] | Obtains the element corresponding to the specified index position. However, this will result in undefined results.|
| Read| getFirst() | Obtains the first element.|
| Read| getLast() | Obtaining the last element|
| Read| getIndexOf(element: T) | Obtains the position of the first element that matches the specified element.|
| Read| getLastIndexOf(element: T) | Obtains the position of the last element that matches the specified element.|
| Read| forEach(callbackfn: (value:T, index?: number, list?: List&lt;T&gt;)=&gt; void,thisArg?: Object) | Traverses the elements of the entire list container.|
| Read| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Update| set(index:number, element: T) | Changes the value of an element with a specified index to element.|
| Update| list\[index] = element | Changes the value of an element at the specified index position to element. However, the result is not defined.|
| Update| replaceAllElements(callbackFn:(value: T,index?: number,list?: List&lt;T&gt;)=&gt;T,thisArg?: Object) | Replaces elements in a list one by one.|
| Delete| remove(element: T) | Deletes the first matched element.|
| Delete| removeByIndex(index:number) | Deletes the element corresponding to the index position.|

## LinkedList

[LinkedList](../reference/apis-arkts/js-apis-linkedlist.md) can be used to construct a doubly linked list, which can be traversed at both ends. **LinkedList** uses generics and can be stored in a non-contiguous memory space.

Unlike [List](../reference/apis-arkts/js-apis-list.md), which is a singly linked list, **LinkedList** supports insertion and removal at both ends.

**LinkedList** is more efficient in data insertion than [ArrayList](../reference/apis-arkts/js-apis-arraylist.md), but less efficient in data access.

If elements need to be frequently inserted and deleted and a doubly linked list is required, you are advised to use LinkedList to perform efficient operations.

**LinkedList** provides the following CRUD APIs.

| Operation| API| Description|
| --------- | ------- | ------- |
| Create| add(element: T) | // Add an item to the end of the data.|
| Create| insert(element: T, index: number) |  * Inserts a value to a specified index.|
| Read| get(index: number) | Obtains the element corresponding to the specified index.|
| Read| list\[index: number] | Obtains the element corresponding to the specified index position. However, this will result in undefined results.|
| Read| getFirst() | Obtains the first element.|
| Read| getLast() | Obtaining the last element|
| Read| getIndexOf(element: T) | Obtains the position of the first element that matches the specified element.|
| Read| getLastIndexOf(element: T) | Obtains the position of the last element that matches the specified element.|
| Read| forEach(callbackFn: (value: T, index?: number, list?: LinkedList&lt;T&gt;) =&gt; void, thisArg?: Object) | Traverses the elements of the entire LinkedList container.|
| Read| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Update| set(index:number, element: T) | Changes the value of an element with a specified index to element.|
| Update| list\[index] = element | Changes the value of an element at the specified index position to element. However, the result is not defined.|
| Delete| remove(element: T) | Deletes the first matched element.|
| Delete| removeByIndex(index:number) | Deletes the element corresponding to the index position.|

## Deque

[Deque](../reference/apis-arkts/js-apis-deque.md) can be used to construct a double-ended queue (deque) that follows the principles of First In First Out (FIFO) and Last In First Out (LIFO). It allows insertion and removal of elements at both ends.

**Deque** uses generics and must be stored in a contiguous memory space. Its initial capacity is 8, and it has capacity doubled in each dynamic expansion. The bottom layer of **Deque** is implemented by cyclic queues, delivering a high efficiency in enqueuing and dequeuing.

Compared with [Queue](../reference/apis-arkts/js-apis-queue.md), Deque allows you to add or delete elements at both ends. Queue allows you to delete elements only at the beginning and add elements at the end.

Unlike [Vector](../reference/apis-arkts/js-apis-vector.md), **Deque** does not support insertion and deletion of elements in between. When compared with **Vector**, **Deque** is more efficient in inserting and removing header elements, but less efficient in accessing elements.

You are advised to use **Deque** when you need to frequently insert or remove elements at both the ends of a container.

**Deque** provides the following CRUD APIs.

| Operation| API| Description|
| --------- | ------- | ------- |
| Create| insertFront(element: T) | Adds an element to the header.|
| Create| insertEnd(element: T) | Adds an element to the end.|
| Read| getFirst() | Obtains the first element and does not dequeue the element.|
| Read| getLast() | Obtains the last element and does not dequeue the element.|
| Read| popFirst() | Obtains the first element and dequeues it.|
| Read| popLast() | Obtains the last element and dequeues it.|
| Read| forEach(callbackFn:(value: T, index?: number, deque?: Deque&lt;T&gt;) =&gt; void, thisArg?: Object) | Traverses the elements of the entire Deque container.|
| Read| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Update| forEach(callbackFn:(value: T, index?: number, deque?: Deque&lt;T&gt;)=&gt; void, thisArg?: Object) | Modify the elements of the entire Deque container through traversal.|
| Delete| popFirst() | Dequeues and deletes the head element.|
| Delete| popLast() | Dequeues and deletes the tail element.|

## Queue

[Queue](../reference/apis-arkts/js-apis-queue.md) can be used to construct a queue that follows the FIFO principle.

**Queue** uses generics and must be stored in a contiguous memory space. Its initial capacity is 8, and it has capacity doubled in each dynamic expansion.

The bottom layer of **Queue** is implemented by cyclic queues, delivering a high efficiency in enqueuing and dequeuing.

Unlike [Deque](../reference/apis-arkts/js-apis-deque.md), which supports insertion and removal at both the ends, **Queue** supports insertion at one end and removal at the other.

You are advised to use **Queue** in FIFO scenarios.

**Queue** provides the following CRUD APIs.

| Operation| API| Description|
| --------- | ------- | ------- |
| Create| add(element: T) | Adds an element to the end.|
| Read| getFirst() | Obtains the head element of a queue and does not dequeue the element.|
| Read| pop() | Obtains the head element and dequeues it.|
| Read| forEach(callbackFn: (value: T, index?: number, queue?: Queue&lt;T&gt;) =&gt; void,thisArg?: Object) | Traverses and accesses the elements of the entire queue container.|
| Read| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Update| forEach(callbackFn: (value: T, index?: number, queue?: Queue&lt;T&gt;) =&gt; void,thisArg?: Object) | Modify the elements of the entire queue container through traversal.|
| Delete| pop() | Dequeues and deletes the head element.|

## Stack

[Stack](../reference/apis-arkts/js-apis-stack.md) can be used to construct a stack that follows the Last Out First In (LOFI) principle.

**Stack** uses generics and must be stored in a contiguous memory space. Its initial capacity is 8, and it increases capacity 1.5-fold in each dynamic expansion. The bottom layer of **Stack** is implemented based on arrays. It supports data insertion and removal at one end.

Unlike [Queue](../reference/apis-arkts/js-apis-queue.md), which supports insertion at one end and removal at the other, **Stack** supports insertion and removal at the same end.

You are advised to use **Stack** in LOFI scenarios.

**Stack** provides the following CRUD APIs.

| Operation| API| Description|
| --------- | ------- | ------- |
| Create| push(item: T) | Adds an element to the top of the stack.|
| Read| peek() | Obtains the top element of the stack and does not dequeue the element.|
| Read| pop() | Obtains the top element of the stack and dequeues it.|
| Read| locate(element: T) | Obtains the position of an element.|
| Read| forEach(callbackFn: (value: T, index?: number, stack?: Stack&lt;T&gt;) =&gt; void, thisArg?: Object) | Traverses and accesses the elements of the entire stack container.|
| Read| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Update| forEach(callbackFn: (value: T, index?: number, stack?: Stack&lt;T&gt;) =&gt; void, thisArg?: Object) | Modify the elements of the entire stack container through traversal.|
| Delete| pop() | Dequeues and deletes the top element from the stack.|

## Vector

> **NOTE**
>
> The APIs provided by **Vector** are deprecated since API version 9. You are advised to use [ArrayList](../reference/apis-arkts/js-apis-arraylist.md).

[Vector](../reference/apis-arkts/js-apis-vector.md) is a continuous storage structure that can be used to construct a global array object. **Vector** uses generics and must be stored in a contiguous memory space. Its initial capacity is 10, and it has capacity doubled in each dynamic expansion.

Both **Vector** and [ArrayList](../reference/apis-arkts/js-apis-arraylist.md) are implemented based on arrays, but **Vector** provides more interfaces for operating the arrays. In addition to operator access, **Vector** provides the getter and setter to provide a more complete verification and error tolerance mechanism.

**Vector** provides the following CRUD APIs.

| Operation| API| Description|
| --------- | ------- | ------- |
| Create| add(element: T) | // Add an item to the end of the data.|
| Create| insert(element: T, index: number) |  * Inserts a value to a specified index.|
| Read| get(index: number) | Obtains the element corresponding to the specified index.|
| Read| vec\[index: number] | Obtains the element corresponding to the specified index position. The access speed is ensured by obtaining the element by using instructions.|
| Read| getFirst() | Obtains the first element.|
| Read| getLastElement() | Obtaining the last element|
| Read| getIndexOf(element: T) | Obtains the position of the first element that matches the specified element.|
| Read| getLastIndexOf(element: T) | Obtains the position of the last element that matches the specified element.|
| Read| forEach(callbackFn: (value: T, index?: number, Vector?: Vector&lt;T&gt;) =&gt; void, thisArg?: Object) | Traverses the elements of the entire Vector container.|
| Read| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Update| set(index:number, element: T) | Changes the value of an element with a specified index to element.|
| Update| vec\[index] = element | Changes the value of an element with a specified index to element.|
| Update| replaceAllElements(callbackFn:(value: T,index?: number,list?: List&lt;T&gt;)=&gt;T,thisArg?: Object) | Replaces elements in a vector one by one.|
| Update| setLength(newSize:number) | Sets the vector length.|
| Delete| remove(element: T) | Deletes the first matched element.|
| Delete| removeByIndex(index:number) | Deletes the element corresponding to the index position.|
| Delete| removeByRange(fromIndex:number,toIndex:number) | Removes elements in a specified range from this container.|

## Use of Linear Containers

Refer to the code snippet below to add, access, and modify elements in **ArrayList**, **Deque**, **Stack**, and **List**.  


```ts
// ArrayList
import { ArrayList } from '@kit.ArkTS'; // Import the ArrayList module.

let arrayList1: ArrayList<string> = new ArrayList();
arrayList1.add ('a'); // Add an element whose value is'a'.
let arrayList2: ArrayList<number> = new ArrayList();
arrayList2.add (1); // Add an element whose value is 1.
console.info ('result: ${arrayList2[0]}'); // Access the element whose index is 0. Output: result: 1
arrayList1[0] = 'one'; // Modify the element whose index is 0.
console.info ('result: ${arrayList1[0]}'); // Output: result: one

// Deque
import { Deque } from '@kit.ArkTS'; // Import the Deque module.

let deque1: Deque<string> = new Deque();
deque1.insertFront ('a'); // Add an element whose value is'a' to the header.
let deque2: Deque<number> = new Deque();
deque2.insertFront (1); // Add an element whose value is 1 to the header.
console.info ('result: ${deque2.getFirst () }'); // Access the element in the queue header. Output: result: 1
deque1.insertEnd ('one'); // Add an element whose value is'one' to the end.
console.info ('result: ${deque1.getLast () }'); // Access the element at the end of the queue. Output: result: one

// Stack
import { Stack } from '@kit.ArkTS'; // Import the Stack module.

let stack1: Stack<string> = new Stack();
stack1.push ('a'); // Add an element whose value is'a' to the stack.
let stack2: Stack<number> = new Stack();
stack2.push (1); // Add an element whose value is 1 to the stack.
console.info ('result: ${stack1.peek () }'); // Access the top element of the stack. Output: result: a
console.info ('result: ${stack2.pop () }'); // Delete the top element of the stack and return the deleted element. Output: result: 1
console.info ('result: ${stack2.length}'); // Output: result: 0

// List
import { List } from '@kit.ArkTS'; // Import the List module.

let list1: List<string> = new List();
list1.add ('a'); // Add an element whose value is'a'.
let list2: List<number> = new List();
list2.insert (0, 0); // Insert (add) an element whose value is 0 at position 0.
let list3: List<Array<number>> = new List();
let b2 = [1, 2, 3];
list3.add (b2); // Add an element of the Array type.
console.info ('result: ${list1[0]}'); // Access the element whose index is 0. Output: result: a
console.info ('result: ${list3.get (0) }'); // Access the element whose index is 0. Output: result: 1,2,3
```
