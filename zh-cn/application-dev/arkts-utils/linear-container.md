# 线性容器


线性容器实现能按顺序访问的数据结构，其底层主要通过数组实现，包括ArrayList、Vector、List、LinkedList、Deque、Queue、Stack七种。


线性容器，充分考虑了数据访问的速度，运行时（Runtime）通过一条字节码指令就可以完成增、删、改、查等操作。

## 各线性容器类型特征对比

| 类名 | 特征及建议使用场景 |
| --------- | ------- |
| ArrayList | 动态数组，占用一片连续的内存空间。需要频繁读取元素时推荐使用。 |
| List | 单向链表，占用的空间可以不连续。需要频繁的插入删除元素且需要使用单向链表时时推荐使用。 |
| LinkedList | 双向链表，占用的空间可以不连续。需要频繁的插入删除元素且需要使用双向链表时时推荐使用。 |
| Deque | 双端队列，可以从容器头尾进行进出元素操作，占用一片连续的内存空间。需要频繁访问、操作头尾元素时推荐使用。 |
| Queue | 队列，从容器尾部插入元素，从容器头部弹出元素，占用一片连续的内存空间。一般符合先进先出的场景可以使用。 |
| Stack | 栈，只能从容器的一端进行插入删除操作，占用一片连续的内存空间。一般符合先进后出的场景可以使用。 |
| Vector | 动态数组，占用一片连续的内存空间。该类型已不再维护，推荐使用ArrayList。 |

## ArrayList

[ArrayList](../reference/apis-arkts/js-apis-arraylist.md)即动态数组，可用来构造全局的数组对象。 当需要频繁读取集合中的元素时，推荐使用ArrayList。

ArrayList依据泛型定义，要求存储位置是一片连续的内存空间，初始容量大小为10，并支持动态扩容，每次扩容大小为原始容量的1.5倍。

ArrayList进行增、删、改、查操作的常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | add(element: T) | 在数组尾部增加一个元素。 |
| 增加元素 | insert(element: T, index: number) | 在指定位置插入一个元素。 |
| 访问元素 | arr\[index: number] | 获取指定index对应的value值，通过指令获取保证访问速度。 |
| 访问元素 | forEach(callbackFn: (value: T, index?: number, arrlist?: ArrayList&lt;T&gt;) =&gt; void, thisArg?: Object) | 访问整个ArrayList容器的元素。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;T&gt; | 创建迭代器以进行数据访问。 |
| 修改元素 | arr\[index] = xxx | 修改指定index位置对应的value值。 |
| 删除元素 | remove(element: T) | 删除第一个匹配到的元素。 |
| 删除元素 | removeByRange(fromIndex: number, toIndex:number) | 删除指定范围内的元素。 |

## List

[List](../reference/apis-arkts/js-apis-list.md)可用来构造一个单向链表对象，即只能通过头结点开始访问到尾节点。List依据泛型定义，在内存中的存储位置可以是不连续的。

List和[LinkedList](../reference/apis-arkts/js-apis-linkedlist.md)相比，LinkedList是双向链表，可以快速地在头尾进行增删，而List是单向链表，无法双向操作。

当需要频繁的插入删除元素，并且需要使用单向链表时，推荐使用List高效操作。

可以通过get/set等接口对存储的元素进行修改，List进行增、删、改、查操作的常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | add(element: T) | 在数组尾部增加一个元素。 |
| 增加元素 | insert(element: T, index: number) | 在指定位置插入一个元素。 |
| 访问元素 | get(index: number) | 获取指定index位置对应的元素。 |
| 访问元素 | list\[index: number] | 获取指定index位置对应的元素，但会导致未定义结果。 |
| 访问元素 | getFirst() | 获取第一个元素。 |
| 访问元素 | getLast() | 获取最后一个元素。 |
| 访问元素 | getIndexOf(element: T) | 获取第一个匹配指定元素的位置。 |
| 访问元素 | getLastIndexOf(element: T) | 获取最后一个匹配指定元素的位置。 |
| 访问元素 | forEach(callbackfn: (value:T, index?: number, list?: List&lt;T&gt;)=&gt; void,thisArg?: Object) | 遍历访问整个List容器的元素。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;T&gt; | 创建迭代器以进行数据访问。 |
| 修改元素 | set(index:number, element: T) | 修改指定index位置的元素值为element。 |
| 修改元素 | list\[index] = element | 修改指定index位置的元素值为element，但会导致未定义结果。 |
| 修改元素 | replaceAllElements(callbackFn:(value: T,index?: number,list?: List&lt;T&gt;)=&gt;T,thisArg?: Object) | 对List内元素进行逐个替换。 |
| 删除元素 | remove(element: T) | 删除第一个匹配到的元素。 |
| 删除元素 | removeByIndex(index:number) | 删除index位置对应的元素。 |

## LinkedList

[LinkedList](../reference/apis-arkts/js-apis-linkedlist.md)可用来构造一个双向链表对象，可以在某一节点向前或者向后遍历List。LinkedList依据泛型定义，在内存中的存储位置可以是不连续的。

LinkedList和[List](../reference/apis-arkts/js-apis-list.md)相比，LinkedList是双向链表，可以快速地在头尾进行增删，而List是单向链表，无法双向操作。

LinkedList和[ArrayList](../reference/apis-arkts/js-apis-arraylist.md)相比，插入数据效率LinkedList优于ArrayList，而查询效率ArrayList优于LinkedList。

当需要频繁的插入删除元素，并且需要使用双向链表时，推荐使用LinkedList高效操作。

可以通过get/set等接口对存储的元素进行修改，LinkedList进行增、删、改、查操作的常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | add(element: T) | 在数组尾部增加一个元素。 |
| 增加元素 | insert(element: T, index: number) | 在指定位置插入一个元素。 |
| 访问元素 | get(index: number) | 获取指定index位置对应的元素。 |
| 访问元素 | list\[index: number] | 获取指定index位置对应的元素，但会导致未定义结果。 |
| 访问元素 | getFirst() | 获取第一个元素。 |
| 访问元素 | getLast() | 获取最后一个元素。 |
| 访问元素 | getIndexOf(element: T) | 获取第一个匹配指定元素的位置。 |
| 访问元素 | getLastIndexOf(element: T) | 获取最后一个匹配指定元素的位置。 |
| 访问元素 | forEach(callbackFn: (value: T, index?: number, list?: LinkedList&lt;T&gt;) =&gt; void, thisArg?: Object) | 遍历访问整个LinkedList容器的元素。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;T&gt; | 创建迭代器以进行数据访问。 |
| 修改元素 | set(index:number, element: T) | 修改指定index位置的元素值为element。 |
| 修改元素 | list\[index] = element | 修改指定index位置的元素值为element，但会导致未定义结果。 |
| 删除元素 | remove(element: T) | 删除第一个匹配到的元素。 |
| 删除元素 | removeByIndex(index:number) | 删除index位置对应的元素。 |

## Deque

[Deque](../reference/apis-arkts/js-apis-deque.md)可用来构造双端队列对象，存储元素遵循先进先出以及先进后出的规则，双端队列可以分别从队头或者队尾进行访问。

Deque依据泛型定义，要求存储位置是一片连续的内存空间，其初始容量大小为8，并支持动态扩容，每次扩容大小为原始容量的2倍。Deque底层采用循环队列实现，入队及出队操作效率都比较高。

Deque和[Queue](../reference/apis-arkts/js-apis-queue.md)相比，Queue的特点是先进先出，只能在头部删除元素，尾部增加元素。

Deque和[Vector](../reference/apis-arkts/js-apis-vector.md)相比，它们都支持在两端增删元素，但Deque不能进行中间插入的操作。对头部元素的插入删除效率高于Vector，而Vector访问元素的效率高于Deque。

需要频繁在集合两端进行增删元素的操作时，推荐使用Deque。

Deque进行增、删、改、查操作的常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | insertFront(element: T) | 在头部增加一个元素。 |
| 增加元素 | insertEnd(element: T) | 在尾部增加一个元素。 |
| 访问元素 | getFirst() | 获取第一个元素，不进行出队操作。 |
| 访问元素 | getLast() | 获取最后一个元素，不进行出队操作。 |
| 访问元素 | popFirst() | 获取第一个元素，并进行出队操作。 |
| 访问元素 | popLast() | 获取最后一个元素，并进行出队操作。 |
| 访问元素 | forEach(callbackFn:(value: T, index?: number, deque?: Deque&lt;T&gt;) =&gt; void, thisArg?: Object) | 遍历访问整个Deque容器的元素。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;T&gt; | 创建迭代器以进行数据访问。 |
| 修改元素 | forEach(callbackFn:(value: T, index?: number, deque?: Deque&lt;T&gt;)=&gt; void, thisArg?: Object) | 通过遍历修改整个Deque容器的元素。 |
| 删除元素 | popFirst() | 对队首元素进行出队操作并删除。 |
| 删除元素 | popLast() | 对队尾元素进行出队操作并删除。 |

## Queue

[Queue](../reference/apis-arkts/js-apis-queue.md)可用来构造队列对象，存储元素遵循先进先出的规则。

Queue依据泛型定义，要求存储位置是一片连续的内存空间，初始容量大小为8，并支持动态扩容，每次扩容大小为原始容量的2倍。

Queue底层采用循环队列实现，入队及出队操作效率都比较高。

Queue和[Deque](../reference/apis-arkts/js-apis-deque.md)相比，Queue只能在一端删除一端增加，Deque可以两端增删。

一般符合先进先出的场景可以使用Queue。

Queue进行增、删、改、查操作的常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | add(element: T) | 在尾部增加一个元素。 |
| 访问元素 | getFirst() | 获取队首元素，不进行出队操作。 |
| 访问元素 | pop() | 获取队首元素，并进行出队操作。 |
| 访问元素 | forEach(callbackFn: (value: T, index?: number, queue?: Queue&lt;T&gt;) =&gt; void,thisArg?: Object) | 遍历访问整个Queue容器的元素。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;T&gt; | 创建迭代器以进行数据访问。 |
| 修改元素 | forEach(callbackFn: (value: T, index?: number, queue?: Queue&lt;T&gt;) =&gt; void,thisArg?: Object) | 通过遍历修改整个Queue容器的元素。 |
| 删除元素 | pop() | 对队首元素进行出队操作并删除。 |

## Stack

[Stack](../reference/apis-arkts/js-apis-stack.md)可用来构造栈对象，存储元素遵循先进后出的规则。

Stack依据泛型定义，要求存储位置是一片连续的内存空间，初始容量大小为8，并支持动态扩容，每次扩容大小为原始容量的1.5倍。Stack底层基于数组实现，入栈出栈均从数组的一端操作。

Stack和[Queue](../reference/apis-arkts/js-apis-queue.md)相比，Queue基于循环队列实现，只能在一端删除，另一端插入，而Stack都在一端操作。

一般符合先进后出的场景可以使用Stack。

Stack进行增、删、改、查操作的常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | push(item: T) | 在栈顶增加一个元素。 |
| 访问元素 | peek() | 获取栈顶元素，不进行出队操作。 |
| 访问元素 | pop() | 获取栈顶元素，并进行出队操作。 |
| 访问元素 | locate(element: T) | 获取元素对应的位置。 |
| 访问元素 | forEach(callbackFn: (value: T, index?: number, stack?: Stack&lt;T&gt;) =&gt; void, thisArg?: Object) | 遍历访问整个Stack容器的元素。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;T&gt; | 创建迭代器以进行数据访问。 |
| 修改元素 | forEach(callbackFn: (value: T, index?: number, stack?: Stack&lt;T&gt;) =&gt; void, thisArg?: Object) | 通过遍历修改整个Stack容器的元素。 |
| 删除元素 | pop() | 对栈顶元素进行出队操作并删除。 |

## Vector

> **说明**：
>
> API version 9开始，该接口不再维护，推荐使用[ArrayList](../reference/apis-arkts/js-apis-arraylist.md)。

[Vector](../reference/apis-arkts/js-apis-vector.md)是指连续存储结构，可用来构造全局的数组对象。Vector依据泛型定义，要求存储位置是一片连续的内存空间，初始容量大小为10，并支持动态扩容，每次扩容大小为原始容量的2倍。

Vector和[ArrayList](../reference/apis-arkts/js-apis-arraylist.md)相似，都是基于数组实现，但Vector提供了更多操作数组的接口。Vector在支持操作符访问的基础上，还增加了get/set接口，提供更为完善的校验及容错机制，满足用户不同场景下的需求。

Vector进行增、删、改、查操作的常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | add(element: T) | 在数组尾部增加一个元素。 |
| 增加元素 | insert(element: T, index: number) | 在指定位置插入一个元素。 |
| 访问元素 | get(index: number) | 获取指定index位置对应的元素。 |
| 访问元素 | vec\[index: number] | 获取指定index位置对应的元素，通过指令获取保证访问速度。 |
| 访问元素 | getFirst() | 获取第一个元素。 |
| 访问元素 | getLastElement() | 获取最后一个元素。 |
| 访问元素 | getIndexOf(element: T) | 获取第一个匹配指定元素的位置。 |
| 访问元素 | getLastIndexOf(element: T) | 获取最后一个匹配指定元素的位置。 |
| 访问元素 | forEach(callbackFn: (value: T, index?: number, Vector?: Vector&lt;T&gt;) =&gt; void, thisArg?: Object) | 遍历访问整个Vector容器的元素。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;T&gt; | 创建迭代器以进行数据访问。 |
| 修改元素 | set(index:number, element: T) | 修改指定index位置的元素值为element。 |
| 修改元素 | vec\[index] = element | 修改指定index位置的元素值为element。 |
| 修改元素 | replaceAllElements(callbackFn:(value: T,index?: number,list?: List&lt;T&gt;)=&gt;T,thisArg?: Object) | 对Vector内元素进行逐个替换。 |
| 修改元素 | setLength(newSize:number) | 设置Vector的长度大小。 |
| 删除元素 | remove(element: T) | 删除第一个匹配到的元素。 |
| 删除元素 | removeByIndex(index:number) | 删除index位置对应的元素。 |
| 删除元素 | removeByRange(fromIndex:number,toIndex:number) | 删除指定范围内的元素。 |

## 线性容器的使用

此处列举常用的线性容器ArrayList、Deque、Stack、List的使用示例，包括导入模块、增加元素、访问元素及修改等操作。示例代码如下所示：


```ts
// ArrayList
import { ArrayList } from '@kit.ArkTS'; // 导入ArrayList模块

let arrayList1: ArrayList<string> = new ArrayList();
arrayList1.add('a');
let arrayList2: ArrayList<number> = new ArrayList();
arrayList2.add(1); // 增加元素
console.info(`result: ${arrayList2[0]}`); // 访问元素
arrayList1[0] = 'one'; // 修改元素
console.info(`result: ${arrayList1[0]}`);

// Deque
import { Deque } from '@kit.ArkTS'; // 导入Deque模块

let deque1: Deque<string> = new Deque();
deque1.insertFront('a');
let deque2: Deque<number> = new Deque();
deque2.insertFront(1); // 增加元素
console.info(`result: ${deque1[0]}`); // 访问元素
deque1[0] = 'one'; // 修改元素
console.info(`result: ${deque2[0]}`);

// Stack
import { Stack } from '@kit.ArkTS'; // 导入Stack模块

let stack1: Stack<string> = new Stack();
stack1.push('a');
let stack2: Stack<number> = new Stack();
stack2.push(1); // 增加元素
console.info(`result: ${stack1[0]}`); // 访问元素
stack2.pop(); // 删除栈顶元素并返回该删除元素
console.info(`result: ${stack2.length}`);

// List
import { List } from '@kit.ArkTS'; // 导入List模块

let list1: List<string> = new List();
list1.add('a');
let list2: List<number> = new List();
list2.add(1);
let list3: List<Array<number>> = new List();
let b2 = [1, 2, 3];
list3.add(b2); // 增加元素
console.info(`result: ${list1[0]}`); // 访问元素
console.info(`result: ${list3.get(0)}`); // 访问元素
```
