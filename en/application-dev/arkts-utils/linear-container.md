# Linear Containers
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @yuanyao14-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->


Linear containers, underpinned by arrays, implement a data structure that enables sequential access. There are several types of linear containers: ArrayList, Vector, List, LinkedList, Deque, Queue, and Stack.


Linear containers optimize data access speed, enabling operations such as adding, removing, modifying, and accessing elements with a single bytecode instruction at runtime.

## Comparison of Linear Container Types

| Type| Characteristics and Recommended Use Cases|
| --------- | ------- |
| ArrayList | Dynamic array, which occupies a contiguous block of memory. This type is recommended for frequent element access.|
| List | Singly linked list, where memory can be non-contiguous. This type is recommended for frequent insertions and deletions when using a singly linked list.|
| LinkedList | Doubly linked list, where memory can be non-contiguous. This type is recommended for frequent insertions and deletions when using a doubly linked list.|
| Deque | Double-ended queue, which allows element operations at both ends and occupies a contiguous block of memory. This type is recommended for frequent access and manipulation of head and tail elements.
| Queue | Queue, which inserts elements at the tail and removes them from the head, and occupies a contiguous block of memory. This type is suitable for First In First Out (FIFO) scenarios.
| Stack | Stack, which allows insertions and deletions only at one end, and occupies a contiguous block of memory. It is applicable to first-in-last-out scenarios.|
| Vector | Dynamic array, which occupies a contiguous block of memory. This type is no longer maintained; use ArrayList instead.

## ArrayList

[ArrayList](../reference/apis-arkts/js-apis-arraylist.md) is a dynamic array used to construct a global array object. It is recommended for frequent element access.

Defined by generics, ArrayList requires a contiguous block of memory for storage, with an initial capacity of 10 and supports dynamic resizing, increasing its size by 1.5 times the original capacity each time.

Common APIs for adding, removing, modifying, and accessing elements in ArrayList are as follows:

| Operation| API| Description|
| --------- | ------- | ------- |
| Adding elements| add(element: T) | Adds an element to the end of the array.|
| Adding elements| insert(element: T, index: number) | Inserts an element at the specified index.|
| Accessing elements| arr[index: number] | Obtains the value at the specified index.|
| Accessing elements| forEach(callbackFn: (value: T, index?: number, arrlist?: ArrayList&lt;T&gt;) =&gt; void, thisArg?: Object) | Iterates over all elements in the ArrayList. `callbackFn` is a callback function used to process each element in the `forEach` method. It receives the current element, index, and original list as parameters.|
| Accessing elements| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Modifying elements| arr[index] = xxx | Modifies the value at the specified index.|
| Removing elements| remove(element: T) | Removes the first matching element.|
| Removing elements| removeByRange(fromIndex: number, toIndex:number) | Removes elements within the specified range.|

## List

[List](../reference/apis-arkts/js-apis-list.md) is used to construct a singly linked list. To search for a specific element within the List, traversal must start from the head node. Defined by generics, the storage locations of elements in the Link can be non-contiguous in memory.

Unlike [LinkedList](../reference/apis-arkts/js-apis-linkedlist.md), which is a doubly linked list and allows quick insertions and deletions at both ends, List is a singly linked list and does not support bidirectional operations.

If elements need to be frequently inserted and deleted and a singly linked list is required, you are advised to use List.

Common APIs for adding, removing, modifying, and accessing elements in List are as follows.

| Operation| API| Description|
| --------- | ------- | ------- |
| Adding elements| add(element: T) | Adds an element to the end of the array.|
| Adding elements| insert(element: T, index: number) | Adds an element at the specified index.|
| Accessing elements| get(index: number) | Obtains the element at the specified index.|
| Accessing elements| list[index: number] | Obtains the element at the specified index. If the index is out of range (index < 0 or index >= list.length) or the array is sparse (there are unassigned indexes), undefined is returned.|
| Accessing elements| getFirst() | Obtains the first element.|
| Accessing elements| getLast() | Obtains the last element.|
| Accessing elements| getIndexOf(element: T) | Obtains the index of the first matching element.|
| Accessing elements| getLastIndexOf(element: T) | Obtains the index of the last matching element.|
| Accessing elements| forEach(callbackfn: (value:T, index?: number, list?: List&lt;T&gt;)=&gt; void,thisArg?: Object) | Iterates over each element in the List and executes the specified callback function.|
| Accessing elements| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Modifying elements| set(index:number, element: T) | Modifies the element at the specified index.|
| Modifying elements| list[index] = element | Modifies the element at the specified index. This API does not make any actual changes to the nodes in the linked list. Instead, it simply adds a property to the object. This can cause the program's state to become inconsistent with the actual contents of the linked list, leading to undefined behavior.|
| Modifying elements| replaceAllElements(callbackFn:(value: T,index?: number,list?: List&lt;T&gt;)=&gt;T,thisArg?: Object) | Replaces all elements in the List.|
| Removing elements| remove(element: T) | Compares each element in the linked list using the === operator and removes the first node that matches. For object types, the element will only be removed if the provided object reference is identical to the node's reference in the linked list.|
| Removing elements| removeByIndex(index:number) | Removes the element at the specified index. If the index is out of range, an "out of range" error is reported|

## LinkedList

[LinkedList](../reference/apis-arkts/js-apis-linkedlist.md) is used to construct a doubly linked list, which can be traversed in both directions from any node. Defined by generics, the storage locations of elements in LinkedList can be non-contiguous in memory.

Unlike [List](../reference/apis-arkts/js-apis-list.md), which is a singly linked list and does not support bidirectional operations, LinkedList is a doubly linked list and allows quick insertions and deletions at both ends.

Compared with [ArrayList](../reference/apis-arkts/js-apis-arraylist.md), LinkedList is more efficient for inserting data, whereas ArrayList is more efficient for querying data.

This type is recommended for frequent insertions and deletions when using a doubly linked list.

You can use the **get**/**set** APIs to modify the stored elements. Common APIs for adding, removing, modifying, and accessing elements in LinkedList are as follows:

| Operation| API| Description|
| --------- | ------- | ------- |
| Adding elements| add(element: T) | Adds an element to the end of the array.|
| Adding elements| insert(element: T, index: number) | Inserts an element at the specified index.|
| Accessing elements| get(index: number) | Obtains the element at the specified index.|
| Accessing elements| list[index: number] | Obtains the element at the specified index. If the index is out of range (index < 0 or index >= list.length) or the array is sparse (there are unassigned indexes), undefined is returned.|
| Accessing elements| getFirst() | Obtains the first element.|
| Accessing elements| getLast() | Obtains the last element.|
| Accessing elements| getIndexOf(element: T) | Obtains the index of the first matching element.|
| Accessing elements| getLastIndexOf(element: T) | Obtains the index of the last matching element.|
| Accessing elements| forEach(callbackFn: (value: T, index?: number, list?: LinkedList&lt;T&gt;) =&gt; void, thisArg?: Object) | Iterates over each element in the LinkedList and executes the specified callback function.|
| Accessing elements| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Modifying elements| set(index:number, element: T) | Modifies the element at the specified index.|
| Modifying elements| list[index] = element | Modifies the element at the specified index. If the index is out of range (index < 0 or index >= list.length) or the array is sparse (there are unassigned indexes), undefined behavior may occur.|
| Removing elements| remove(element: T) | Removes the first matching element.|
| Removing elements| removeByIndex(index:number) | Deletes the element at the specified index.|

## Deque

[Deque](../reference/apis-arkts/js-apis-deque.md) is used to construct a double-ended queue (deque) that follows the principles of FIFO and LIFO. It allows insertion and removal of elements at both ends.

Defined by generics, Deque requires a contiguous block of memory for storage, with an initial capacity of 8 and supports dynamic resizing, increasing its size by 2 times the original capacity each time. Deque is implemented using a circular queue, ensuring efficient enqueue and dequeue operations.

Unlike [Queue](../reference/apis-arkts/js-apis-queue.md), which only allows element removal at the head and insertion at the tail, Deque allows operations at both ends.

Compared with [Vector](../reference/apis-arkts/js-apis-vector.md), both support element operations at both ends, but Deque does not allow insertions in the middle. Deque is more efficient than a Vector for inserting and deleting elements at the front, whereas a Vector excels in element access efficiency.

Deque is recommended for frequent insertions and deletions at both ends.

Common APIs for adding, deleting, modifying, and accessing elements in Deque are as follows.  

| Operation| API| Description|
| --------- | ------- | ------- |
| Adding elements| insertFront(element: T) | Adds an element to the front of the Deque.|
| Adding elements| insertEnd(element: T) | Adds an element to the end of the Deque.|
| Accessing elements| getFirst() | Obtains the first element without dequeuing.|
| Accessing elements| getLast() | Obtains the last element without dequeuing.|
| Accessing elements| forEach(callbackFn:(value: T, index?: number, deque?: Deque&lt;T&gt;) =&gt; void, thisArg?: Object) | Iterates over each element in the Deque and executes the specified callback function.|
| Accessing elements| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Removing elements| popFirst() | Removes the first element from the Queue and returns it. If the Queue is empty, undefined is returned.|
| Removing elements| popLast() | Removes the last element from the Queue and returns it. If the Queue is empty, undefined is returned.|

## Queue

[Queue](../reference/apis-arkts/js-apis-queue.md) is used to construct a queue that follows the FIFO principle.

Defined by generics, Queue requires a contiguous block of memory for storage, with an initial capacity of 8 and supports dynamic resizing, doubling its size each time.

Queue is implemented using a circular queue, ensuring efficient enqueue and dequeue operations.

Unlike [Deque](../reference/apis-arkts/js-apis-deque.md), which supports insertion and removal at both the ends, Queue supports insertion at the tail and removal at the head.

Queue is suitable for first-in-first-out scenarios.

Common APIs for adding, removing, modifying, and accessing elements in Queue are as follows:

| Operation| API| Description|
| --------- | ------- | ------- |
| Adding elements| add(element: T) | Adds an element to the end of the Queue.|
| Accessing elements| getFirst() | Obtains the first element without dequeuing.|
| Accessing elements| forEach(callbackFn: (value: T, index?: number, queue?: Queue&lt;T&gt;) =&gt; void,thisArg?: Object) | Iterates over each element in the Queue and executes the specified callback function.|
| Accessing elements| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Removing elements| pop() | Removes the first element from the Queue and returns it.|

## Stack

[Stack](../reference/apis-arkts/js-apis-stack.md) is used to construct a stack that follows the Last Out First In (LOFI) principle.

Defined by generics, Stack requires a contiguous block of memory for storage, with an initial capacity of 8 and supports dynamic resizing, increasing its size by 1.5 times the original capacity each time. Stack is implemented using an array, with all operations performed at one end.

Unlike [Queue](../reference/apis-arkts/js-apis-queue.md), which is implemented using a circular queue and allows removal only from the front and addition only at the rear, Stack supports insertion and removal at one end.

Stack is suitable for first-in-last-out scenarios.

Common APIs for adding, removing, modifying, and accessing elements in Stack are as follows:

| Operation| API| Description|
| --------- | ------- | ------- |
| Adding elements| push(item: T) | Adds an element to the top of the Stack.|
| Accessing elements| peek() | Obtains the top element of the Stack without dequeuing.|
| Accessing elements| locate(element: T) | Obtains the position of an element.|
| Accessing elements| forEach(callbackFn: (value: T, index?: number, stack?: Stack&lt;T&gt;) =&gt; void, thisArg?: Object) | Iterates over each element in the Stack and executes the specified callback function.|
| Accessing elements| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Removing elements| pop() | Removes the first element from the Stack and returns it.|

## Vector

> **NOTE**
>
> Since API version 9, this API is no longer maintained. Use [ArrayList](../reference/apis-arkts/js-apis-arraylist.md) instead.

[Vector](../reference/apis-arkts/js-apis-vector.md) is a continuous storage structure used to create a global array object. It is defined based on generics and requires that the storage space be contiguous. The initial capacity of Vector is 10, and it supports dynamic resizing, doubling its size each time.

Vector, like [ArrayList](../reference/apis-arkts/js-apis-arraylist.md), is based on arrays but provides more array manipulation APIs, supports operator access, and provides **get** and **set** APIs. In addition, Vector provides a more comprehensive verification and fault tolerance mechanism to meet requirements in different scenarios.

Common APIs for adding, removing, modifying, and accessing elements in Vector are as follows:

| Operation| API| Description|
| --------- | ------- | ------- |
| Adding elements| add(element: T) | Adds an element to the end of the array.|
| Adding elements| insert(element: T, index: number) | Inserts an element at the specified index.|
| Accessing elements| get(index: number) | Obtains the element at the specified index.|
| Accessing elements| vec[index: number] | Obtains the element at the specified index, ensuring fast access.|
| Accessing elements| getFirst() | Obtains the first element.|
| Accessing elements| getLastElement() | Obtains the last element.|
| Accessing elements| getIndexOf(element: T) | Obtains the index of the first matching element.|
| Accessing elements| getLastIndexOf(element: T) | Obtains the index of the last matching element.|
| Accessing elements| forEach(callbackFn: (value: T, index?: number, Vector?: Vector&lt;T&gt;) =&gt; void, thisArg?: Object) | Iterates over each element in the Stack and executes the specified callback function.|
| Accessing elements| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Modifying elements| set(index:number, element: T) | Modifies the element at the specified index.|
| Modifying elements| vec[index] = element | Modifies the element at the specified index.|
| Modifying elements| replaceAllElements(callbackFn: (value: T, index?: number, vector?: Vector&lt;T&gt;) => T, thisArg?: Object) | Replaces all elements in the Vector.|
| Modifying elements| setLength(newSize:number) | Sets the length of the Vector.|
| Removing elements| remove(element: T) | Removes the first matching element.|
| Removing elements| removeByIndex(index:number) | Removes the element at the specified index.|
| Removing elements| removeByRange(fromIndex:number,toIndex:number) | Removes elements within the specified range.|

## Use of Linear Containers

This section provides usage examples for common linear containers, including ArrayList, Deque, Stack, and List, covering importing modules, adding elements, accessing elements, and modifying elements. The example code is as follows:


```ts
// ArrayList
import { ArrayList } from '@kit.ArkTS'; // Import the ArrayList module.

let arrayList1: ArrayList<string> = new ArrayList();
arrayList1.add('a'); // Add an element with the value 'a'.
let arrayList2: ArrayList<number> = new ArrayList();
arrayList2.add(1); // Add an element with the value 1.
console.info(`result: ${arrayList2[0]}`); // Access the element at index 0. Output: result: 1
arrayList1[0] = 'one'; // Modify the element at index 0.
console.info(`result: ${arrayList1[0]}`); // Output: result: one

// Deque
import { Deque } from '@kit.ArkTS'; // Import the Deque module.

let deque1: Deque<string> = new Deque();
deque1.insertFront('a'); // Add an element with the value 'a' to the header.
let deque2: Deque<number> = new Deque();
deque2.insertFront(1); // Add an element with the value 1 to the header.
console.info(`result: ${deque2.getFirst()}`); // Access the first element. Output: result: 1
deque1.insertEnd('one'); // Add an element with the value 'one'.
console.info(`result: ${deque1.getLast()}`); // Access the last element. Output: result: one

// Stack
import { Stack } from '@kit.ArkTS'; // Import the Stack module.

let stack1: Stack<string> = new Stack();
stack1.push('a'); // Add an element with the value 'a' to the Stack.
let stack2: Stack<number> = new Stack();
stack2.push(1); // Add an element with the value 1 to the Stack.
console.info(`result: ${stack1.peek()}`); // Access the top element of the Stack. Output: result: a
console.info(`result: ${stack2.pop()}`); // Remove and return the top element. Output: result: 1
console.info(`result: ${stack2.length}`); // Output: result: 0

// List
import { List } from '@kit.ArkTS'; // Import the List module.

let list1: List<string> = new List();
list1.add('a'); // Add an element with the value 'a'.
let list2: List<number> = new List();
list2.insert(0, 0); // Insert an element with the value 0 at index 0.
let list3: List<Array<number>> = new List();
let b2 = [1, 2, 3];
list3.add(b2); // Add an element of the Array type.
console.info(`result: ${list1[0]}`); // Access the element at index 0. Output: result: a
console.info(`result: ${list3.get(0)}`); // Access the element at index 0. Output: result: 1,2,3
```
