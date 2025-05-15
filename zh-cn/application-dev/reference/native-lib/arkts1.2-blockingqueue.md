# BlockingQueue (阻塞队列)

阻塞队列（BlockingQueue）是一种线程安全的队列容器，其核心特点是在队列为空时阻塞消费者线程弹出元素，队列满时阻塞生产者线程插入元素。它通过内部的锁和条件变量保证多线程并发安全，常用于解决多线程环境下的数据共享与协同问题。

**推荐使用场景：** 可用于实现多线程阻塞式channel（管道，一种用于多线程之间数据传递和同步的通信机制）、​​线程池任务队列taskpool、流量控制等场景，允许生产者线程与消费者线程间安全传递数据。

> **说明：**
>
> ArkTS版本：该标准库接口仅适用于ArkTS1.2。

## BlockingQueue

BlockingQueue\<T> 是定义了阻塞队列及其方法的interface，有两个实现类：[LinkedBlockingQueue](#linkedblockingqueue)和[ArrayBlockingQueue](#arrayblockingqueue)。

### 属性

| 名称     | 类型 | 只读 | 可选 | 说明                   |
| :------- | :--- | :--- | :--- | :--------------------- |
| size     | int  | 是   | 否   | 阻塞队列中元素的个数。 |
| capacity | int  | 是   | 否   | 阻塞队列的容量。       |

### push

push(element: T): void

将元素插入队列尾部。如果队列已满，则阻塞，直到队列有空余容量后再插入元素。

该方法多线程并发执行安全。

**参数：**

| 参数名  | 类型 | 必填 | 说明               |
| :------ | :--- | :--- | :----------------- |
| element | T    | 是   | 要插入队列的数据。 |

**示例：**

```typescript
let queueInt: BlockingQueue<int> = new LinkedBlockingQueue<int>(10); //阻塞队列容量设置为10
for (let i = 0; i < 10; i++) {
  queueInt.push(i);
}
queueInt.push(10); //阻塞
```

### pop

pop(): T

弹出并返回队列的头部元素。如果队列为空，则阻塞，直到队列中有元素后再弹出元素。

该方法多线程并发执行安全。

**返回值：**

| 类型 | 说明                 |
| :--- | :------------------- |
| T    | 返回队列的头部元素。 |

**示例：**

```typescript
let queueInt: BlockingQueue<int> = new LinkedBlockingQueue<int>();
for (let i = 0; i < 10; i++) {
  queueInt.push(i);
}
for (let i = 0; i < 9; i++) {
  queueInt.pop();
}
let res_0 = queueInt.pop(); // 9
let res_1 = queueInt.pop(); // 阻塞
```

### add

add(element: T): boolean

尝试将元素插入队列。如果队列已满，则插入失败返回false，否则插入成功返回true。该方法不会阻塞。

该方法多线程并发执行安全。

**参数：**

| 参数名  | 类型 | 必填 | 说明               |
| :------ | :--- | :--- | :----------------- |
| element | T    | 是   | 待插入队列的数据。 |

**返回值：**

| 类型    | 说明                                                    |
| :------ | :------------------------------------------------------ |
| boolean | 如果队列已满，插入失败返回false，否则插入成功返回true。 |

**示例：**

```typescript
let queueInt: BlockingQueue<int> = new LinkedBlockingQueue<int>(10);
for (let i = 0; i < 10; i++) {
  let res = queueInt.add(i); // true
}
assertEQ(queueInt.size, 10); // 插入了10个元素，队列元素数量为10
let res = queueInt.add(11); // false
```

### poll

poll(): T \| undefined

尝试移除队列的头部元素。如果队列为空，则返回undefined，否则返回被移除的元素。该方法不会阻塞。

该方法多线程并发执行安全。

**返回值：**

| 类型           | 说明                                                  |
| :------------- | :---------------------------------------------------- |
| T \| undefined | 返回被移除的头部元素，如果队列为空，则返回undefined。 |

**示例：**

```typescript
let queueInt: BlockingQueue<int> = new LinkedBlockingQueue<int>();
for (let i = 0; i < 10; i++) {
  queueInt.push(i);
}
let res = queueInt.poll(); // 0
res = queueInt.poll(); // 1
```

### getFirst

getFirst(): T | undefined

获取队列的头部元素，如果队列为空，则返回undefined。

该方法多线程并发执行安全。

**返回值：**

| 类型           | 说明                                              |
| :------------- | :------------------------------------------------ |
| T \| undefined | 返回队列头部元素，如果队列为空，则返回undefined。 |

**示例：**

```typescript
let queueInt: BlockingQueue<int> = new LinkedBlockingQueue<int>();
for (let i: int = 0; i < 10; ++i) {
  queueInt.push(i);
}
let res = queueInt.getFirst(); // 0
res = queueInt.getFirst(); // 0
```

### isEmpty

isEmpty(): boolean

检查队列是否为空。

该方法多线程并发执行安全。

**返回值：**

| 类型    | 说明                                    |
| :------ | :-------------------------------------- |
| boolean | 队列为空返回true，队列不为空返回false。 |

**示例：**

```typescript
let queueInt: BlockingQueue<int> = new LinkedBlockingQueue<int>();
let res = queueInt.isEmpty(); // true
queueInt.push(1);
res = queueInt.isEmpty(); // false
```

### remainingCapacity

remainingCapacity(): int

当前队列在不阻塞的情况下还可以容纳的元素数量，即剩余容量，等于队列的容量减去当前的元素数量。

该方法多线程并发执行安全。

**返回值：**

| 类型 | 说明                     |
| :--- | :----------------------- |
| int  | 返回当前队列的剩余容量。 |

**示例：**

```typescript
let queueInt: BlockingQueue<int> = new ArrayBlockingQueue<int>(10);
for (let i = 0; i < 5; i++) {
  queueInt.push(i);
}
let remainingcapacity = queueInt.remainingCapacity(); // 5
queueInt.pop();
remainingcapacity = queueInt.remainingCapacity(); // 6
assertEQ(queueInt.remainingCapacity(), queueInt.capacity - queueInt.size);
```

## LinkedBlockingQueue

LinkedBlockingQueue\<T>，实现了[BlockingQueue](#blockingqueue)接口，是一个基于链表实现的阻塞队列，提供了阻塞队列的基本操作，如插入、删除、获取元素等，并在队列为空或满时支持线程阻塞等待，支持多线程环境下的并发操作。

### constructor

constructor()

LinkedBlockingQueue的构造函数，创建一个容量为Int.MAX_VALUE(2147483647)的LinkedBlockingQueue\<T>实例。

**示例：**

```typescript
let queueInt: BlockingQueue<int> = new LinkedBlockingQueue<int>();
let capacity = queueInt.capacity; // 2147483647
```

### constructor

constructor(capacity: int)

LinkedBlockingQueue的构造函数，创建一个容量为capacity的LinkedBlockingQueue\<T>实例。

**参数：**

| 参数名   | 类型 | 必填 | 说明                                                 |
| :------- | :--- | :--- | :--------------------------------------------------- |
| capacity | int  | 是   | 初始化队列的容量。 <br />取值范围：大于等于0。<br /> |

**示例：**

```typescript
let queueInt: BlockingQueue<int> = new LinkedBlockingQueue<int>(10);
let capacity = queueInt.capacity; // 10
```

### constructor

constructor(iterable: Iterable\<T>)

LinkedBlockingQueue的构造函数，传入一个实现了Iterable\<T>接口的可迭代对象。该构造函数创建一个容量为Int.MAX_VALUE(2147483647)的LinkedBlockingQueue\<T>实例，并将iterable中（非undefined）的元素添加到新创建的链表阻塞队列中。

**参数：**

| 参数名   | 类型         | 必填 | 说明                         |
| :------- | :----------- | :--- | :--------------------------- |
| iterable | Iterable\<T> | 是   | 一个迭代器，用于初始化队列。 |

**示例：**

```typescript
let arr = new Array<int>(10);
arr[0] = 0;
let queueInt: BlockingQueue<int> = new LinkedBlockingQueue<int>(arr);
let res = queueInt.capacity; // 2147483647
let size = queueInt.size; // 1
let first = queueInt.getFirst(); // 0
```

### constructor

constructor(capacity: int, iterable: Iterable\<T>)

LinkedBlockingQueue的构造函数，传入一个实现了Iterable\<T>接口的可迭代对象。该构造函数创建一个容量为capacity的LinkedBlockingQueue\<T>实例，并将iterable中（非undefined）的元素添加到新创建的链表阻塞队列中。

**参数：**

| 参数名   | 类型         | 必填 | 说明                                               |
| :------- | :----------- | :--- | :------------------------------------------------- |
| capacity | int          | 是   | 初始化队列容量。 <br />取值范围：大于等于0。<br /> |
| iterable | Iterable\<T> | 是   | 一个迭代器，用于初始化队列。                       |

**示例：**

```typescript
let arr = new Array<int>(10);
arr[0] = 0;
let iter = arr.values();
let queueInt: BlockingQueue<int> = new LinkedBlockingQueue<int>(10, iter);
let res = queueInt.capacity; // 10
let size = queueInt.size; // 1
let first = queueInt.getFirst(); // 0
```

### getEnd

getEnd(): T | undefined

获取队列的尾部元素，如果队列为空，则返回undefined。

该方法多线程并发执行安全。

**返回值：**

| 类型           | 说明                                                |
| :------------- | :-------------------------------------------------- |
| T \| undefined | 返回队列尾部元素，若队列没有元素，则返回undefined。 |

**示例：**

```typescript
let queueInt: LinkedBlockingQueue<int> = new LinkedBlockingQueue<int>(10);
for (let i: int = 0; i < 10; ++i) {
  queueInt.push(i);
}
let res = queueInt.getEnd(); // 9
```

## ArrayBlockingQueue

ArrayBlockingQueue\<T>，实现了[BlockingQueue](#blockingqueue)接口，是一个基于数组实现的阻塞队列，提供了阻塞队列的基本操作，如插入、删除、获取元素等，并在队列为空或满时支持线程阻塞等待，支持多线程环境下的并发操作。

### constructor

constructor(capacity: int)

ArrayBlockingQueue的构造函数，创建一个容量为capacity的ArrayBlockingQueue\<T>实例。

**参数：**

| 参数名   | 类型 | 必填 | 说明                                             |
| -------- | ---- | ---- | ------------------------------------------------ |
| capacity | int  | 是   | 初始化队列的容量。 <br />取值范围：大于0。<br /> |

**示例：**

```typescript
let queueInt: BlockingQueue<int> = new ArrayBlockingQueue<int>(10);
let res = queueInt.isEmpty(); // true
```

### constructor

constructor(capacity: int , iterable: Iterable\<T>)

ArrayBlockingQueue的构造函数。该构造函数创建一个容量为capacity的ArrayBlockingQueue\<T>实例，并将iterable中（非undefined）的元素添加到新创建的数组阻塞队列中。

**参数：**

| 参数名   | 类型         | 必填 | 说明                                             |
| -------- | ------------ | ---- | ------------------------------------------------ |
| capacity | int          | 是   | 初始化队列的容量。 <br />取值范围：大于0。<br /> |
| iterable | Iterable\<T> | 是   | 一个迭代器，用于初始化队列。                     |

**示例：**

```typescript
const arr: Number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
let set: Set<number> = new Set<number>(arr);
let queueInt: BlockingQueue<number> = new ArrayBlockingQueue<number>(200, set);
let capacity = queueInt.capacity; // 200
let size = queueInt.size; // 10
```

### getEnd

getEnd(): T \| undefined

获取队列的尾部元素，如果队列为空，则返回undefined。

该方法多线程并发执行安全。

**返回值：**

| 类型           | 说明                                                |
| -------------- | --------------------------------------------------- |
| T \| undefined | 返回队列尾部元素，若队列没有元素，则返回undefined。 |

**示例：**

```typescript
let queueInt: ArrayBlockingQueue<int> = new ArrayBlockingQueue<int>(10);
for (let i: int = 0; i < 10; ++i) {
  queueInt.push(i);
}
let res = queueInt.getEnd(); // 9
```
