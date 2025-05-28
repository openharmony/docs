# @ohos.util.Deque (线性容器Deque)

Deque（double ended queue）基于循环队列的数据结构实现，支持两端元素的插入和删除，同时具备先进先出以及先进后出的特点。Deque会根据实际需要动态调整容量，每次扩容两倍。

Deque和[Queue](js-apis-queue.md)相比，Deque允许在两端执行插入和删除操作，Queue只能在头部删除元素，尾部插入元素。

与[Vector](js-apis-vector.md)相比，它们都支持在两端插入和删除元素，但Deque不支持中间插入。Deque在头部插入删除元素的效率高于Vector，而Vector在访问元素的效率高于Deque。

**推荐使用场景：** 需要在集合两端频繁增删元素时，推荐使用Deque。

文档中使用了泛型，涉及以下泛型标记符：
- T：Type，类

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { Deque } from '@kit.ArkTS';
```

## Deque

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | Deque的元素个数。 |

### constructor

constructor()

Deque的构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200012 | The Deque's constructor cannot be directly invoked. |

**示例：**

```ts
let deque: Deque<string | number | boolean | Object> = new Deque();
```

### insertFront

insertFront(element: T): void

在deque头部插入元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 插入的元素。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The insertFront method cannot be bound. |

**示例：**

```ts
class C1 {
  name: string = ""
  age: string = ""
}
let deque: Deque<string | number | boolean | Array<number> | C1> = new Deque();
deque.insertFront("a");
deque.insertFront(1);
let b = [1, 2, 3];
deque.insertFront(b);
let c: C1 = {name : "Dylan", age : "13"};
deque.insertFront(c);
deque.insertFront(false);
```

### insertEnd

insertEnd(element: T): void

在deque尾部插入元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 插入的元素。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The insertEnd method cannot be bound. |

**示例：**

```ts
class C1 {
  name: string = ""
  age: string = ""
}

let deque: Deque<string | number | boolean | Array<number> | C1> = new Deque();
deque.insertEnd("a");
deque.insertEnd(1);
let b = [1, 2, 3];
deque.insertEnd(b);
let c: C1 = {name : "Dylan", age : "13"};
deque.insertEnd(c);
deque.insertEnd(false);
```

### has

has(element: T): boolean

判断此Deque中是否包含指定元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 指定的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果包含指定元素返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The has method cannot be bound. |

**示例：**

```ts
let deque: Deque<string> = new Deque();
deque.insertFront("squirrel");
let result = deque.has("squirrel");
```

### popFirst

popFirst(): T

删除并返回双端队列的首元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回被删除的首元素。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The popFirst method cannot be bound. |

**示例：**

```ts
let deque: Deque<number> = new Deque();
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

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回被删除的尾元素。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The popLast method cannot be bound. |

**示例：**

```ts
let deque: Deque<number> = new Deque();
deque.insertFront(2);
deque.insertEnd(4);
deque.insertFront(5);
deque.insertFront(2);
deque.insertFront(4);
let result = deque.popLast();
```

### forEach

forEach(callbackFn: (value: T, index?: number, deque?: Deque&lt;T&gt;) => void,
thisArg?: Object): void

使用回调函数遍历Deque实例对象的元素及其下标。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 回调函数。 |
| thisArg | Object | 否 | callbackFn被调用时用作this值，默认值为当前实例对象。 |

callbackFn的参数说明：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 当前遍历到的元素。 |
| index | number | 否 | 当前遍历到的下标值，默认值为0。 |
| deque | Deque&lt;T&gt; | 否 | 当前调用forEach方法的实例对象，默认值为当前实例对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The forEach method cannot be bound. |

**示例：**

```ts
let deque: Deque<number> = new Deque();
deque.insertFront(2);
deque.insertEnd(4);
deque.insertFront(5);
deque.insertEnd(4);
deque.forEach((value: number, index?: number | undefined, deque?: Deque<number> | undefined):void => {
  console.log("value:" + value, "index:" + index);
});
```

### getFirst

getFirst(): T

获取Deque实例的头元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回T类型的头元素。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getFirst method cannot be bound. |

**示例：**

```ts
let deque: Deque<number> = new Deque();
deque.insertEnd(2);
deque.insertEnd(4);
deque.insertFront(5);
deque.insertFront(4);
let result = deque.getFirst();
```

### getLast

getLast(): T

获取Deque实例的尾元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回T类型的尾元素。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getLast method cannot be bound. |

**示例：**

```ts
let deque: Deque<number> = new Deque();
deque.insertFront(2);
deque.insertFront(4);
deque.insertFront(5);
deque.insertFront(4);
let result = deque.getLast();
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

返回一个迭代器，迭代器的每一项都是一个JavaScript对象。

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
let deque: Deque<number> = new Deque();
deque.insertFront(2);
deque.insertFront(4);
deque.insertFront(5);
deque.insertFront(4);

// 使用方法一：
let nums: Array<number> = Array.from(deque);
for (let item of nums) {
  console.log("value:" + item);
}

// 使用方法二：
let iter = deque[Symbol.iterator]();
let temp:IteratorResult<number> = iter.next();
while(!temp.done) {
  console.log("value:" + temp.value);
  temp = iter.next();
}
```