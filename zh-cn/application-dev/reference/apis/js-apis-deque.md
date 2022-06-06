# 线性容器Deque

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

Deque（double ended queue）根据循环队列的数据结构实现，符合先进先出以及先进后出的特点，支持两端的元素插入和移除。Deque会根据实际需要动态调整容量，每次进行两倍扩容。

Deque和[Queue](js-apis-queue.md)相比，Queue的特点是先进先出，只能在头部删除元素，尾部增加元素。

与[Vector](js-apis-vector.md)相比，它们都支持在两端增删元素，但Deque不能进行中间插入的操作。对头部元素的插入删除效率高于Vector，而Vector访问元素的效率高于Deque。

**推荐使用场景：** 需要频繁在集合两端进行增删元素的操作时，推荐使用Deque。

## 导入模块

```ts
import Deque from '@ohos.util.Deque'; 
```

## Deque

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | Deque的元素个数。 |

### constructor

constructor()

Deque的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
let deque = new Deque();
```

### insertFront

insertFront(element: T): void

在deque头部插入元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 插入的元素。 |

**示例：**

```ts
let deque = new Deque();
deque.insertFront("a");
deque.insertFront(1);
let b = [1, 2, 3];
deque.insertFront(b);
let c = {name : "lala", age : "13"};
deque.insertFront(false);
```

### insertEnd

insertEnd(element: T): void

在deque尾部插入元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 插入的元素。 |

**示例：**

```ts
let deque = new Deque();
deque.insertEnd("a");
deque.insertEnd(1);
let b = [1, 2, 3];
deque.insertEnd(b);
let c = {name : "lala", age : "13"};
deque.insertEnd(false);
```

### has

has(element: T): boolean

判断此Deque中是否含有该指定元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 指定的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果包含指定元素返回true，否则返回false。 |

**示例：**

```ts
let deque = new Deque();
let result = deque.has("Ahfbrgrbgnutfodgorrogorg");
deque.insertFront("Ahfbrgrbgnutfodgorrogorg");
let result1 = deque.has("Ahfbrgrbgnutfodgorrogorg");
```

### popFirst

popFirst(): T

删除并返回双端队列的首元素。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回被删除的元素。 |

**示例：**

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

删除并返回双端队列的尾元素。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回被删除的元素。 |

**示例：**

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

通过回调函数来遍历Deque实例对象上的元素以及元素对应的下标。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackfn | function | 是 | 回调函数。 |
| thisArg | Object | 否 | callbackfn被调用时用作this值。 |

callbackfn的参数说明：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 当前遍历到的元素。 |
| index | number | 否 | 当前遍历到的下标值。 |
| deque | Deque&lt;T&gt; | 否 | 当前调用forEach方法的实例对象。 |

**示例：**

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

获取Deque实例中的头元素。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回T型 |

**示例：**

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

获取Deque实例中的尾元素。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回T型 |

**示例：**

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

返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象,并返回该对象。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;T&gt; | 返回一个迭代器。 |

**示例：**
```ts
let deque = new Deque();
deque.insertFront(2);
deque.insertFront(4);
deque.insertFront(5);
deque.insertFront(4);

// 使用方法一：
for (let item of deque) { 
  console.log("value:" + item); 
}

// 使用方法二：
let iter = deque[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
```