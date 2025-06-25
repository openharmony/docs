# @ohos.util.Queue (线性容器Queue)

Queue的特点是先进先出，在尾部增加元素，在头部删除元素。根据循环队列的数据结构实现。

Queue和[Deque](js-apis-deque.md)相比，Queue只能在一端删除一端增加，Deque可以两端增删。

**推荐使用场景：** 一般符合先进先出的场景可以使用Queue。

文档中使用了泛型，涉及以下泛型标记符：<br>
- T：Type，类

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { Queue } from '@kit.ArkTS';
```


## Queue

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | Queue的元素个数。 |


### constructor

constructor()

Queue的构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200012 | The Queue's constructor cannot be directly invoked. |

**示例：**

```ts
let queue : Queue<number | string | Object> = new Queue();
```


### add

add(element: T): boolean

在队列尾部插入元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 要插入的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 插入成功返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The add method cannot be bound. |

**示例：**

```ts
class C1 {
  name: string = ""
  age: string = ""
}
let queue : Queue<number | string | C1 | number[]> = new Queue();
let result = queue.add("a");
let result1 = queue.add(1);
let b = [1, 2, 3];
let result2 = queue.add(b);
let c : C1 = {name : "Dylan", age : "13"};
let result3 = queue.add(c);
```

### pop

pop(): T

删除头元素并返回该删除元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回删除的元素。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The pop method cannot be bound. |

**示例：**

```ts
let queue : Queue<number> = new Queue();
queue.add(2);
queue.add(4);
queue.add(5);
queue.add(2);
queue.add(4);
let result = queue.pop();
```

### getFirst

getFirst(): T

获取队列的头元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回获取的元素。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getFirst method cannot be bound. |

**示例：**

```ts
let queue : Queue<number> = new Queue();
queue.add(2);
queue.add(4);
queue.add(5);
queue.add(2);
let result = queue.getFirst();
```

### forEach

forEach(callbackFn: (value: T, index?: number, Queue?: Queue&lt;T&gt;) => void,
thisArg?: Object): void

通过回调函数遍历Queue实例对象的元素及其下标。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 回调函数。 |
| thisArg | Object | 否 | callbackfn被调用时用作this值，默认值为当前实例对象。 |

callbackfn的参数说明：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 当前遍历到的元素。 |
| index | number | 否 | 当前遍历到的下标值，默认值为0。 |
| Queue | Queue&lt;T&gt; | 否 | 当前调用forEach方法的实例对象，默认值为当前实例对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The forEach method cannot be bound. |

**示例：**

```ts
let queue : Queue<number> = new Queue();
queue.add(2);
queue.add(4);
queue.add(5);
queue.add(4);
queue.forEach((value : number, index ?: number) : void => {
  console.log("value:" + value, "index:" + index);
});
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

返回一个迭代器，每一项都是一个JavaScript对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;T&gt; | 返回一个迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**示例：**
```ts
let queue : Queue<number> = new Queue();
queue.add(2);
queue.add(4);
queue.add(5);
queue.add(4);

// 使用方法一：
while(queue.length) {
  let item = queue.pop();
  console.log("value:" + item);
}

// 使用方法二：
let iter = queue[Symbol.iterator]();
let temp: IteratorResult<number> = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
```