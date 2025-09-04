# 线性容器
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @yuanyao14-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->


线性容器实现能按顺序访问的数据结构，其底层主要通过数组实现，包括ArrayList、Vector、List、LinkedList、Deque、Queue和Stack。


线性容器优化了数据访问速度，运行时（Runtime）通过一条字节码指令即可完成增、删、改、查等操作。

## 各线性容器类型特征对比

| 类名 | 特征及建议使用场景 |
| --------- | ------- |
| ArrayList | 动态数组，占用一片连续的内存空间。需要频繁读取元素时推荐使用。 |
| List | 单向链表，占用的空间可以不连续。推荐在需要频繁插入和删除元素，且需要使用单向链表时使用。 |
| LinkedList | 双向链表，占用的空间可以不连续。推荐在需要频繁插入和删除元素，且需要使用双向链表时使用。 |
| Deque | 双端队列，支持从头尾两端进行元素的插入和删除操作，占用连续的内存空间。推荐在需要频繁访问和操作头尾元素时使用。
| Queue | 队列，是一种从尾部插入元素、从头部移除元素的数据结构，占用连续的内存空间，适用于先进先出的场景。
| Stack | 栈，只能从一端进行插入和删除操作，占用连续的内存空间。适用于先进后出的场景。 |
| Vector | 动态数组，占用连续的内存空间。已不再维护，推荐使用 ArrayList。

## ArrayList

[ArrayList](../reference/apis-arkts/js-apis-arraylist.md)即动态数组，可用来构造全局的数组对象。需要频繁读取集合元素时，推荐使用ArrayList。

ArrayList依据泛型定义，存储位置为连续的内存空间，初始容量为10，支持动态扩容，每次扩容为原始容量的1.5倍。

ArrayList支持增、删、改、查操作，常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | add(element: T) | 在数组尾部增加一个元素。 |
| 增加元素 | insert(element: T, index: number) | 在指定位置插入一个元素。 |
| 访问元素 | arr[index: number] | 获取指定index对应的value值。 |
| 访问元素 | forEach(callbackFn: (value: T, index?: number, arrlist?: ArrayList&lt;T&gt;) =&gt; void, thisArg?: Object) | 访问整个ArrayList容器的元素，其中`callbackFn`是`forEach`方法中用于处理每个元素的回调函数，它接收当前元素、索引和原列表作为参数。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;T&gt; | 创建迭代器以进行数据访问。 |
| 修改元素 | arr[index] = xxx | 修改指定index位置对应的value值。 |
| 删除元素 | remove(element: T) | 删除第一个匹配到的元素。 |
| 删除元素 | removeByRange(fromIndex: number, toIndex:number) | 删除指定范围内的元素。 |

## List

[List](../reference/apis-arkts/js-apis-list.md)可用来构造一个单向链表对象，若需要查找List中某一个元素，只能从头结点开始遍历。List依据泛型定义，存储的元素在内存中的存储位置可以不连续。

List和[LinkedList](../reference/apis-arkts/js-apis-linkedlist.md)相比，LinkedList是双向链表，支持在头部和尾部快速增删操作。List则是单向链表，不支持双向操作。

当需要频繁插入和删除元素，并且使用单向链表时，推荐使用List进行高效操作。

可以通过get/set等接口修改存储的元素，List支持增、删、改、查操作，常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | add(element: T) | 在数组尾部增加一个元素。 |
| 增加元素 | insert(element: T, index: number) | 在指定位置增加一个元素。 |
| 访问元素 | get(index: number) | 获取指定index位置对应的元素。 |
| 访问元素 | list[index: number] | 获取指定索引位置的元素。若索引超出数组范围（index < 0 或 index >= list.length），或者数组是稀疏数组（存在未赋值的索引），则返回undefined。 |
| 访问元素 | getFirst() | 获取第一个元素。 |
| 访问元素 | getLast() | 获取最后一个元素。 |
| 访问元素 | getIndexOf(element: T) | 获取第一个匹配指定元素的位置。 |
| 访问元素 | getLastIndexOf(element: T) | 获取最后一个匹配指定元素的位置。 |
| 访问元素 | forEach(callbackfn: (value:T, index?: number, list?: List&lt;T&gt;)=&gt; void,thisArg?: Object) | 遍历访问整个List容器中的每个元素，并执行指定的回调函数。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;T&gt; | 创建迭代器以进行数据访问。 |
| 修改元素 | set(index:number, element: T) | 修改指定index位置的元素值为element。 |
| 修改元素 | list[index] = element | 修改指定index位置的元素值为element时，不会对链表中的实际节点进行任何更改，仅会在对象上添加一个属性，这将导致程序状态与链表实际内容不一致，从而产生未定义行为。 |
| 修改元素 | replaceAllElements(callbackFn:(value: T,index?: number,list?: List&lt;T&gt;)=&gt;T,thisArg?: Object) | 对List内元素进行逐个替换。 |
| 删除元素 | remove(element: T) | 通过 === 运算符逐个比对链表中的元素，删除第一个匹配成功的节点。对于对象类型，只有当传入的对象与链表中某节点的引用完全一致时才会被删除。 |
| 删除元素 | removeByIndex(index:number) | 删除index位置对应的元素，如果index超出范围，则会报out of range错误。 |

## LinkedList

[LinkedList](../reference/apis-arkts/js-apis-linkedlist.md)可用于构造双向链表对象，支持在任意节点向前或向后遍历LinkedList。LinkedList依据泛型定义，其元素在内存中的存储位置可以不连续。

LinkedList和[List](../reference/apis-arkts/js-apis-list.md)相比，LinkedList是双向链表，支持快速的头尾增删操作。List是单向链表，不支持双向操作。

LinkedList和[ArrayList](../reference/apis-arkts/js-apis-arraylist.md)相比，LinkedList插入数据的效率高于ArrayList，ArrayList查询效率高于LinkedList。

需要频繁插入删除元素且使用双向链表时，推荐使用LinkedList。

可以通过get/set等接口修改存储的元素。LinkedList支持增、删、改、查操作，常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | add(element: T) | 在数组尾部增加一个元素。 |
| 增加元素 | insert(element: T, index: number) | 在指定位置插入一个元素。 |
| 访问元素 | get(index: number) | 获取指定index位置对应的元素。 |
| 访问元素 | list[index: number] | 获取指定index位置对应的元素，若索引超出数组范围（index < 0 或 index >= list.length），或者数组是稀疏数组（存在未赋值的索引），则返回undefined。 |
| 访问元素 | getFirst() | 获取第一个元素。 |
| 访问元素 | getLast() | 获取最后一个元素。 |
| 访问元素 | getIndexOf(element: T) | 获取第一个匹配指定元素的位置。 |
| 访问元素 | getLastIndexOf(element: T) | 获取最后一个匹配指定元素的位置。 |
| 访问元素 | forEach(callbackFn: (value: T, index?: number, list?: LinkedList&lt;T&gt;) =&gt; void, thisArg?: Object) | 遍历访问整个LinkedList容器的每个元素，并执行指定的回调函数。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;T&gt; | 创建迭代器以进行数据访问。 |
| 修改元素 | set(index:number, element: T) | 修改指定index位置的元素值为element。 |
| 修改元素 | list[index] = element | 修改指定index位置的元素值为element，若索引超出数组范围（index < 0 或 index >= list.length），或者数组是稀疏数组（存在未赋值的索引），则可能导致未定义行为。 |
| 删除元素 | remove(element: T) | 删除第一个匹配到的元素。 |
| 删除元素 | removeByIndex(index:number) | 删除index位置对应的元素。 |

## Deque

[Deque](../reference/apis-arkts/js-apis-deque.md)可用来构造双端队列对象，存储元素遵循先进先出以及先进后出的规则，双端队列可以分别从队头或者队尾进行访问。

Deque依据泛型定义，要求存储位置为连续的内存空间，初始容量为8，支持动态扩容，每次扩容为原容量的2倍。Deque底层采用循环队列实现，入队和出队操作效率高。

Deque和[Queue](../reference/apis-arkts/js-apis-queue.md)相比，Deque支持在两端进行元素的增删操作，而Queue仅支持在头部删除元素，尾部增加元素。

Deque和[Vector](../reference/apis-arkts/js-apis-vector.md)相比，都支持在两端增删元素，但Deque不支持中间插入。Deque在头部插入和删除元素的效率高于Vector，而Vector访问元素的效率高于Deque。

需要频繁在两端增删元素时，推荐使用Deque。

Deque支持增、删、改、查操作。常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | insertFront(element: T) | 在头部增加一个元素。 |
| 增加元素 | insertEnd(element: T) | 在尾部增加一个元素。 |
| 访问元素 | getFirst() | 获取第一个元素，不进行出队操作。 |
| 访问元素 | getLast() | 获取最后一个元素，不进行出队操作。 |
| 访问元素 | forEach(callbackFn:(value: T, index?: number, deque?: Deque&lt;T&gt;) =&gt; void, thisArg?: Object) | 遍历访问整个Deque容器的每个元素，并执行指定的回调函数。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;T&gt; | 创建迭代器以进行数据访问。 |
| 删除元素 | popFirst() | 将队首元素作为返回值进行返回，并将其出队，如果队列为空，则返回undefined。 |
| 删除元素 | popLast() | 将队尾元素作为返回值进行返回，并将其出队，如果队列为空，则返回undefined。 |

## Queue

[Queue](../reference/apis-arkts/js-apis-queue.md)可用来构造队列对象，存储元素遵循先进先出的规则。

Queue基于泛型定义，存储位置为连续的内存空间，初始容量为8，支持动态扩容，每次扩容容量翻倍。

Queue底层采用循环队列实现，入队和出队操作效率高。

Queue和[Deque](../reference/apis-arkts/js-apis-deque.md)相比，Queue仅支持在头部删除元素，尾部增加元素，而Deque支持在两端进行元素的增删操作。

符合先进先出的场景可以使用Queue。

Queue支持增、删、改、查操作，常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | add(element: T) | 在尾部增加一个元素。 |
| 访问元素 | getFirst() | 获取队首元素，不进行出队操作。 |
| 访问元素 | forEach(callbackFn: (value: T, index?: number, queue?: Queue&lt;T&gt;) =&gt; void,thisArg?: Object) | 遍历访问整个Queue容器的每个元素，并执行指定的回调函数。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;T&gt; | 创建迭代器以进行数据访问。 |
| 删除元素 | pop() | 将队首元素作为返回值进行返回，并将其移除。|

## Stack

[Stack](../reference/apis-arkts/js-apis-stack.md)可用来构造栈对象，存储元素遵循先进后出的规则。

Stack基于泛型定义，要求使用连续的内存空间存储元素，初始容量为8，并支持动态扩容，每次扩容为原容量的1.5倍。Stack底层使用数组实现，入栈和出栈操作均在数组的一端进行。

Stack和[Queue](../reference/apis-arkts/js-apis-queue.md)相比，Queue基于循环队列实现，仅支持在头部删除元素，尾部增加元素，而Stack都在一端进行操作。

符合先进后出的场景可以使用Stack。

Stack支持增、删、改、查操作，常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | push(item: T) | 在栈顶增加一个元素。 |
| 访问元素 | peek() | 获取栈顶元素，不进行出队操作。 |
| 访问元素 | locate(element: T) | 获取元素对应的位置。 |
| 访问元素 | forEach(callbackFn: (value: T, index?: number, stack?: Stack&lt;T&gt;) =&gt; void, thisArg?: Object) | 遍历访问整个Stack容器的每个元素，并执行指定的回调函数。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;T&gt; | 创建迭代器以进行数据访问。 |
| 删除元素 | pop() | 将栈顶元素作为返回值进行返回，并将其移除。|

## Vector

> **说明**：
>
> API version 9开始，该接口不再维护，推荐使用[ArrayList](../reference/apis-arkts/js-apis-arraylist.md)。

[Vector](../reference/apis-arkts/js-apis-vector.md)是一种连续存储结构，用于创建全局数组对象。它基于泛型定义，要求存储在连续的内存空间中。Vector的初始容量为10，支持动态扩容，每次扩容时容量增加为原来的两倍。

Vector和[ArrayList](../reference/apis-arkts/js-apis-arraylist.md)相似，都基于数组实现，但Vector提供了更多操作数组的接口，支持操作符访问，增加get/set接口，提供更完善的校验和容错机制，满足不同的场景需求。

Vector支持增、删、改、查操作，常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | add(element: T) | 在数组尾部增加一个元素。 |
| 增加元素 | insert(element: T, index: number) | 在指定位置插入一个元素。 |
| 访问元素 | get(index: number) | 获取指定index位置对应的元素。 |
| 访问元素 | vec[index: number] | 获取指定index位置对应的元素，通过指令获取保证访问速度。 |
| 访问元素 | getFirst() | 获取第一个元素。 |
| 访问元素 | getLastElement() | 获取最后一个元素。 |
| 访问元素 | getIndexOf(element: T) | 获取第一个匹配指定元素的位置。 |
| 访问元素 | getLastIndexOf(element: T) | 获取最后一个匹配指定元素的位置。 |
| 访问元素 | forEach(callbackFn: (value: T, index?: number, Vector?: Vector&lt;T&gt;) =&gt; void, thisArg?: Object) | 遍历访问整个Vector容器的每个元素，并执行指定的回调函数。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;T&gt; | 创建迭代器以进行数据访问。 |
| 修改元素 | set(index:number, element: T) | 修改指定index位置的元素值为element。 |
| 修改元素 | vec[index] = element | 修改指定index位置的元素值为element。 |
| 修改元素 | replaceAllElements(callbackFn: (value: T, index?: number, vector?: Vector&lt;T&gt;) => T, thisArg?: Object) | 逐个替换Vector内的元素。|
| 修改元素 | setLength(newSize:number) | 设置Vector的长度大小。 |
| 删除元素 | remove(element: T) | 删除第一个匹配到的元素。 |
| 删除元素 | removeByIndex(index:number) | 删除index位置对应的元素。 |
| 删除元素 | removeByRange(fromIndex:number,toIndex:number) | 删除指定范围内的元素。 |

## 线性容器的使用

此处列举常用的线性容器ArrayList、Deque、Stack、List的使用示例，包括导入模块、添加元素、访问元素及修改等操作。示例代码如下所示：


```ts
// ArrayList
import { ArrayList } from '@kit.ArkTS'; // 导入ArrayList模块

let arrayList1: ArrayList<string> = new ArrayList();
arrayList1.add('a'); // 增加一个值为'a'的元素
let arrayList2: ArrayList<number> = new ArrayList();
arrayList2.add(1); // 增加一个值为1的元素
console.info(`result: ${arrayList2[0]}`); // 访问索引为0的元素。输出：result: 1
arrayList1[0] = 'one'; // 修改索引为0的元素
console.info(`result: ${arrayList1[0]}`); // 输出：result: one

// Deque
import { Deque } from '@kit.ArkTS'; // 导入Deque模块

let deque1: Deque<string> = new Deque();
deque1.insertFront('a'); // 头部增加一个值为'a'的元素
let deque2: Deque<number> = new Deque();
deque2.insertFront(1); // 头部增加一个值为1的元素
console.info(`result: ${deque2.getFirst()}`); // 访问队列首部的元素。输出：result: 1
deque1.insertEnd('one'); // 尾部增加一个值为'one'的元素
console.info(`result: ${deque1.getLast()}`); // 访问队列尾部的元素。输出：result: one

// Stack
import { Stack } from '@kit.ArkTS'; // 导入Stack模块

let stack1: Stack<string> = new Stack();
stack1.push('a'); // 向栈里增加一个值为'a'的元素
let stack2: Stack<number> = new Stack();
stack2.push(1); // 向栈里增加一个值为1的元素
console.info(`result: ${stack1.peek()}`); // 访问栈顶元素。输出：result: a
console.info(`result: ${stack2.pop()}`); // 删除栈顶元素并返回该删除元素。输出：result: 1
console.info(`result: ${stack2.length}`); // 输出：result: 0

// List
import { List } from '@kit.ArkTS'; // 导入List模块

let list1: List<string> = new List();
list1.add('a'); // 增加一个值为'a'的元素
let list2: List<number> = new List();
list2.insert(0, 0); // 在0号位置插入（增加）一个值为0的元素
let list3: List<Array<number>> = new List();
let b2 = [1, 2, 3];
list3.add(b2); // 增加一个Array类型的元素
console.info(`result: ${list1[0]}`); // 访问索引为0的元素。输出：result: a
console.info(`result: ${list3.get(0)}`); // 访问索引为0的元素。输出：result: 1,2,3
```
