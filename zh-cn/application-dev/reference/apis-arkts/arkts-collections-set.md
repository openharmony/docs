# @arkts.collections.Set (ArkTS Set)

ArkTS Set与JavaScript内建的Set类似，是一种非线性数据结构。两者最大的区别在于:
- ArkTS Set支持在多个线程间共享访问；
- ArkTS Set实例无法通过`.`或`[]`添加或更新属性。

默认情况下，ArkTS Set对象在线程间传输的行为是引用传递，同时也支持拷贝传递。如果通过引用传递，当多个线程同时访问时，可能会发生数据竞争。
为此，ArkTS提供了[异步锁](TODO)机制来保护多线程安全访问。

**推荐使用场景：** 多线程共享。

文档中存在泛型的使用，涉及以下泛型标记符：
- T：Type，类型

类型T需为[Sendable类型](TODO)。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { collections } from '@Kit.ArkTS';
```

## Set

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| size | number | 是 | 否 | Set的元素个数。|


### constructor
```ts
constructor(values?: readonly T[] | null);
```

Set的构造函数，创建Set对象。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| values | T[] | 否 | 数组或其它可迭代对象 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200012 | The ArkTS Set's constructor cannot be directly invoked. |

**示例：**

```ts
const mySet = new collections.Set<number>();
```

```ts
const mySet = new collections.Set<number>([1, 2, 3, 4, 5]);
```

```ts
@Sendable
class SharedClass {
  constructor() {
  }
}

let sObj = new SharedClass();
const mySet1 = new collections.Set<number|SharedClass>([1, sObj]);

// Throw exception `Parameter error. Only accept sendable value`
let obj = new Object();
const mySet2 = new collections.Set<number|Object>([1, obj]);
```

### entries
```ts
entries(): IterableIterator<[T, T]>;
```

返回一个set迭代器对象。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[T, T]&gt; | 返回一个set迭代器对象。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The entries method cannot be bound with non-sendable. |

**示例：**

```ts
const mySet = new collections.Set<number>([0, 1, 2, 3]);

const iterator = mySet.entries();
// Expected output: [0, 0]
console.log(iterator.next().value);
// Expected output: [1, 1]
console.log(iterator.next().value);
```

### keys
```ts
keys(): IterableIterator<T>;
```

返回一个set迭代器对象，该对象包含了此set中每个元素的值。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;T&gt; | 返回一个set迭代器对象。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The keys method cannot be bound with non-sendable. |

**示例：**

```ts
const mySet = new collections.Set<number>([0, 1, 2, 3]);

const iterator = mySet.keys();
// Expected output: 0
console.log(iterator.next().value);
// Expected output: 1
console.log(iterator.next().value);
```

### values
```ts
values(): IterableIterator<T>;
```

返回一个set迭代器对象，该对象包含了此set中每个元素的值。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;T&gt; | 返回一个set迭代器对象。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The values method cannot be bound with non-sendable. |

**示例：**

```ts
const mySet = new collections.Set<number>([0, 1, 2, 3]);

const iterator = mySet.values();
// Expected output: 0
console.log(iterator.next().value);
// Expected output: 1
console.log(iterator.next().value);
```

```ts
const mySet = new collections.Set<number>([0, 1, 2, 3]);

const valueIter = mySet.values();
for (let value of valueIter) {
    if (value % 2 == 0) {
        mySet.delete(value);
    }
}

// Expected output: 2
console.log("size:" + mySet.size);
```

### clear
```ts
clear(): void;
```

删除该集合中的所有元素。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The clear method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
const mySet = new collections.Set<number>([0, 1]);
// Expected output: 2
console.log("size:" + mySet.size);
mySet.clear();
// Expected output: 0
console.log("size:" + mySet.size);
```

### delete
```ts
delete(value: T): boolean;
```

删除该set中指定元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 待删除元素的键。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 成功删除返回true，否则返回false。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The delete method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception. |


**示例：**

```ts
const mySet = new collections.Set<string>(["hello", "world"]);
// Expected result: true
console.log("result:" + mySet.delete("hello"));
// Expected result: false
console.log("result:" + mySet.has("hello"));
// Expected result: false
console.log("result:" + mySet.delete("hello"));
```

### forEach
```ts
forEach(callbackFn: (value1: T, value2: T, set: Set<T>) => void): void;
```

按插入顺序对该set中的每个键/值对执行一次回调函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 回调函数。|

callbackFn的参数说明：
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value1 | T | 否 | 当前遍历到的元素键值对的值。|
| value2 | T | 否 | 当前遍历到的元素键值对的键。|
| set | Set&lt;T&gt; | 否 | 当前set实例对象。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The forEach method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
new collections.Set<string>(['foo', 'bar', 'baz']).forEach((value1, value2, set) => {
  console.log(`s[${value1}] = ${value2}`);
});
```

```ts
new collections.Set<string>(['foo', 'bar', 'baz']).forEach((value1, value2, set) => {
  // Throw exception `Concurrent modification exception.`
  set.delete(value1);
});
```

### has
```ts
has(value: T): boolean;
```

判断该Set中是否存在指定元素。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果存在指定元素，则返回true；否则返回false。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The has method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
const mySet = new collections.Set<string>(["hello", "world"]);
// Expected output: true
console.log("result:" + mySet.has("hello"));
// Expected output: true
console.log("result:" + mySet.has("world"));
```

### add
```ts
add(value: T): Set<T>;
```

如果没有相同元素，则在该集合中插入一个新元素。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Set&lt;T&gt; | Set对象 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The add method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
const mySet = new collections.Set<string>();
mySet.add("foo", "bar")
```

```ts
let obj = new Object();
const mySet = new collections.Set<Object>();
// Throw exception `Parameter error. Only accept sendable value`
mySet.add(obj)
```